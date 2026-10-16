"""A bot that clears a Normal Game stage with the bomber made invincible: it bombs every enemy, breaking
soft blocks to reach them, then walks to the exit. It plays through saturnrecomp.agent, so the presses
it makes replay the same run as a route."""
import collections

from . import routes, state

DIRS = {"UP": (0, -1), "DOWN": (0, 1), "LEFT": (-1, 0), "RIGHT": (1, 0)}


def paths(stage, start, carts=False):
    """For each cell the bomber can walk to, the presses that get there; with `carts`, onto a mine cart too."""
    prev = {start: None}
    q = collections.deque([start])
    while q:
        c = q.popleft()
        for d, (dx, dy) in DIRS.items():
            n = (c[0] + dx, c[1] + dy)
            if n not in prev and stage.passable(n) and (carts or not state.cart(stage.at(n))):
                prev[n] = (c, d)
                q.append(n)

    def path(goal):
        out = []
        while prev[goal]:
            goal, d = prev[goal]
            out.append(d)
        return out[::-1]

    return prev.keys(), path


def blast(stage, c, fire):
    """The cells a bomb at c reaches, and the soft blocks it breaks."""
    hit, soft = {c}, set()
    for dx, dy in DIRS.values():
        for k in range(1, fire + 1):
            n = (c[0] + dx * k, c[1] + dy * k)
            v = stage.at(n)
            if v & state.SOFT:
                soft.add(n)
                break
            if v & state.SOLID:
                hit.add(n)                       # a standing enemy is solid, and the bomb still reaches it
                break
            hit.add(n)
    return hit, soft


def plan(stage, fire, ignore=frozenset()):
    """Where to go next and whether to bomb there: a cell whose blast reaches a target, else one that
    breaks the soft block nearest a target, else the exit once none is left. The targets are the Core
    Mechanisms, which alone keep the exit shut, or a boss's weak cell where it has one, or every enemy.
    Soft blocks in `ignore` are left alone. A mine cart is ridden only when nothing is in reach
    without it."""
    reachable, path = paths(stage, stage.me.cell)
    foes = stage.cores or stage.enemies
    if not stage.cores and stage.exit in reachable and stage.exit != stage.me.cell:
        return path(stage.exit), False
    if not foes:
        if stage.exit in reachable:
            return path(stage.exit), False
        targets = {stage.exit}
    else:
        targets = {stage.weak} if stage.weak else {e.cell for e in foes}
    best = None
    for c in reachable:
        hit, soft = blast(stage, c, fire)
        soft -= ignore
        steps = len(path(c))
        if hit & targets and foes:
            score = (0, steps)
        elif soft:
            near = min(abs(s[0] - t[0]) + abs(s[1] - t[1]) for s in soft for t in targets)
            score = (1, near * 4 + steps)
        else:
            continue
        if best is None or score < best[0]:
            best = (score, c)
    if best is None:
        # nothing in reach on foot: ride a mine cart if there is one, which takes the bomber elsewhere
        by_cart, cart_path = paths(stage, stage.me.cell, carts=True)
        carts = [c for c in by_cart if state.cart(stage.at(c))]
        if carts:
            return cart_path(min(carts, key=lambda c: len(cart_path(c)))), False
    if best is None and foes:
        # nothing in reach. Against a boss: blast from the nearest cell, where each new bomb lands in the
        # last one's fire and goes off at once. Else wait there: fire keeps 4-4's bridges raised.
        near = min(reachable, key=lambda c: (min(abs(c[0] - t[0]) + abs(c[1] - t[1]) for t in targets), len(path(c))))
        return path(near), not stage.cores
    return (path(best[1]), True) if best else ([], False)


def walk(r, d, pad=1, flame=True):
    """Hold d until the bomber stands on the next cell in that direction, at or just past its centre. False
    if it did not get there. A bomb dropped on fire goes off at once, so with `flame` it drops one on every
    burning cell it crosses: with invincibility that keeps a blast going wherever it walks."""
    me = state.me(r, pad)
    if me is None:
        return True
    dx, dy = DIRS[d]
    goal = (me.cell[0] + dx, me.cell[1] + dy)
    r.pad(d, pad)
    arrived = False
    for _ in range(60):
        r.step(1)
        me = state.me(r, pad)
        if me is None:                            # gone: the exit took it
            arrived = True
            break
        under = state.cell(r, me.cell)
        if flame and under & state.FIRE and not under & state.BOMB:
            r.pad(d + "+C", pad)
            r.step(2)
            r.pad(d, pad)
        # checked every VBlank: with every speed-up a bomber moves more than a pixel a VBlank
        off_x, off_y = me.x - goal[0] * 16, me.y - goal[1] * 16
        if me.cell == goal and (dx * off_x >= -1 if dx else abs(off_x) < 2) and (dy * off_y >= -2 if dy else abs(off_y) < 3):
            arrived = True
            break
    r.pad("", pad)
    return arrived


def stage_number(r):
    """World and stage, or in Master Game its world and floor."""
    from .run import GAME
    master = r.read(GAME.symbols["stage_2"], 2)
    return master if master[0] == state.MASTER_WORLD else r.read(GAME.symbols["stage"], 2)


# How long the bot bombs the same soft blocks, from its first bomb at them, before it leaves them.
UNBROKEN = 900

# Master Game enemies that dodge every blast: once none has died for this long, the bot hits them by hand.
PATIENCE = 1800


def poke(r, addr, data):
    """A write, recorded in the run's presses as VBLANK:@ADDR=HEX, which routes.clear replays as a write."""
    r.write(addr, data)
    r.presses.append(f"{r.vblank}:@{addr:08X}={bytes(data).hex()}")


CLOCK = next(k for k, name in routes.ITEM_KINDS.items() if name == "clock")


def take_clock(r, stage, pad=1):
    """Hides a clock in a soft block written onto a free cell beside the bomber, bombs it and walks onto
    the clock. The game's pickup then stops the stage's timer and every enemy, bosses too, for about 950
    VBlanks. Whether it took one."""
    from .run import GAME
    sym = GAME.symbols
    me = stage.me.cell
    side = next(((d, (me[0] + dx, me[1] + dy)) for d, (dx, dy) in DIRS.items()
                 if stage.passable((me[0] + dx, me[1] + dy)) and not stage.at((me[0] + dx, me[1] + dy)) & state.FIRE), None)
    free = next((k for k in range(75, 0, -1) if not any(r.read(sym["item_slots"] + k * 8, 8))), None)
    if side is None or free is None:
        return False
    d, (x, y) = side
    r.pad("C", pad)
    r.step(4)
    r.pad("", pad)
    if not state.cell(r, me) & state.BOMB:      # no bomb yet, as while a stage's opening plays
        return False
    poke(r, sym["item_slots"] + free * 8, bytes([0, 0, 0, 0, 0, CLOCK, 0, 0]))
    poke(r, sym["hidden_items"] + (y * 64 + x) * 2, free.to_bytes(2, "big"))
    poke(r, sym["cells"] + (y * 64 + x) * 2, (stage.at((x, y)) | state.SOFT).to_bytes(2, "big"))
    r.pad("B", pad)                              # sets off a remote-control bomb at once; nothing without one
    r.step(4)
    r.pad("", pad)
    for _ in range(80):                          # a plain bomb's fuse is about 140 VBlanks; a remote one goes at once
        r.step(4)
        v = state.cell(r, (x, y))
        if v & state.ITEM and not v & (state.FIRE | state.SOFT):
            break
    walk(r, d, pad, flame=False)
    return int.from_bytes(r.read(sym["clock_freeze"], 2), "big") > 0


def strike(r, enemies):
    """Sets the hit flag on each enemy, the way a blast does, and records each write in the run's presses as
    VBLANK:@ADDR=HEX, which routes.clear replays as a write."""
    from .run import GAME
    for e in enemies:
        at = GAME.symbols["objects"] + e.slot * state.SLOT + 0x34
        poke(r, at, bytes([r.read(at, 1)[0] | 0x40]))


def play(r, limit, log=print, pad=1, flame=True, clock=None):
    """Play the stage the run is in with the pad's bomber until it changes or `limit` VBlanks pass; whether
    it was cleared. Pad 1 moves the cutscenes on. With `clock`, by default in Master Game, it keeps every
    enemy frozen with a clock it hides beside itself (take_clock)."""
    from .run import GAME
    start, end = stage_number(r), r.vblank + limit
    final = start in (bytes([len(routes.STAGES) - 1, routes.STAGES[len(routes.STAGES)] - 1]),
                      bytes([state.MASTER_WORLD, routes.FLOORS - 1]))
    master = start[0] == state.MASTER_WORLD
    # bosses come out slower frozen, and a freeze can keep one from changing form (5-10)
    clock = (master if clock is None else clock) and ((routes.MASTER if master else start[0] + 1), start[1] + 1) not in routes.BOSSES
    stuck, gone_since = 0, None
    count, changed = None, r.vblank
    ignore, aiming = set(), {}                   # soft blocks given up on; when each set was first aimed at
    held = (0, r.vblank)                         # the clock's VBlanks left, and since when
    while r.vblank < end:
        if stage_number(r) != start:
            return True
        stage = state.read(r, pad)
        if len(stage.enemies) != count:
            count, changed = len(stage.enemies), r.vblank
        if master and stage.enemies and not stage.cores and r.vblank - changed > PATIENCE:
            log(f"{r.vblank}: no enemy has died for {PATIENCE} VBlanks; hitting the {count} left")
            strike(r, stage.enemies)
            changed = r.vblank
        gone_since = (gone_since or r.vblank) if stage.me is None else None
        if final and gone_since and r.vblank - gone_since > 1800:
            return True                          # the last boss leads to the ending, not to another stage
        if stage.me is None:                     # a cutscene or a change of scene: C and START move them on
            r.pad("C" if (r.vblank // 10) % 2 else "START")
            r.step(4)
            r.pad("")
            r.step(6)
            continue
        left = int.from_bytes(r.read(GAME.symbols["clock_freeze"], 2), "big") if clock else 0
        if left and left == held[0] and r.vblank - held[1] > 120:
            # the game counts the freeze down only in some phases, and freezing those again keeps them from
            # ending: 5-10's boss never took his final form
            log(f"{r.vblank}: the clock has stopped at {left}; ending it, and no more clocks here")
            poke(r, GAME.symbols["clock_freeze"], bytes(2))
            left, clock = 0, False
        if left != held[0]:
            held = (left, r.vblank)
        # not while Core Mechanisms stand: 1-1 never cleared with clocks taken then
        if clock and not stage.cores and stage.enemies and not left:
            if take_clock(r, stage, pad):
                log(f"{r.vblank}: took a clock")
                continue
        if state.cannon(stage.at(stage.me.cell)):
            r.pad("A", pad)                      # in a cannon: climb back out
            r.step(10)
            r.pad("", pad)
            r.step(60)
            continue
        fire = stage.fire
        moves, bomb = plan(stage, fire, frozenset(ignore))
        if not moves and not bomb:
            r.pad("B", pad)                      # sets off a remote-control bomb, which waits for it
            r.step(4)
            r.pad("", pad)
            r.step(16)
            continue
        for d in moves[:8]:
            if not walk(r, d, pad, flame and bomb):
                stuck += 1
                # a bomber that cannot move is often in a scene with dialogue, which A and C move on
                r.pad("A" if stuck % 2 else "C", pad)
                r.step(4)
                r.pad("", pad)
                r.step(10)
                break
        else:
            stuck = 0
            if bomb and len(moves) <= 8:
                at = stage.me.cell
                for d in moves:
                    at = (at[0] + DIRS[d][0], at[1] + DIRS[d][1])
                aimed = frozenset(blast(stage, at, fire)[1] - ignore)
                if aimed and r.vblank - aiming.setdefault(aimed, r.vblank) > UNBROKEN:
                    log(f"{r.vblank}: the soft blocks at {sorted(aimed)} have not broken; leaving them")
                    ignore |= aimed
                r.pad("C", pad)
                r.step(4)
                r.pad("B", pad)                  # sets off a remote-control bomb at once; nothing without one
                r.step(4)
                r.pad("", pad)
                r.step(2)
        if stuck > 200:
            log(f"{r.vblank}: stuck at {stage.me.cell}")
            return False
    return False


def route_through_blocks(stage, start, goal):
    """The presses from start to goal, walking through soft blocks as though broken; None if walls block it."""
    prev = {start: None}
    q = collections.deque([start])
    while q:
        c = q.popleft()
        if c == goal:
            break
        for d, (dx, dy) in DIRS.items():
            n = (c[0] + dx, c[1] + dy)
            v = stage.at(n)
            if n not in prev and (stage.passable(n) or v & state.SOFT and not v & state.SOLID or n == goal):
                prev[n] = (c, d)
                q.append(n)
    if goal not in prev:
        return None
    out, c = [], goal
    while prev[c]:
        c, d = prev[c]
        out.append(d)
    return out[::-1]


def go(r, goal, pad=1, wait=200):
    """Walks the pad's bomber to `goal`, bombing each soft block on the way and waiting out its blast; for
    invincible runs. Whether it got there."""
    for _ in range(20):
        me = state.me(r, pad)
        if me is None:
            return False
        if me.cell == goal:
            return True
        stage = state.read(r)
        moves = route_through_blocks(stage, me.cell, goal)
        if moves is None:
            return False
        c = me.cell
        for d in moves:
            n = (c[0] + DIRS[d][0], c[1] + DIRS[d][1])
            if stage.at(n) & state.SOFT:
                r.pad("C", pad)
                r.step(4)
                r.pad("B", pad)                  # sets off a remote-control bomb at once; nothing without one
                r.step(4)
                r.pad("", pad)
                r.step(wait)
                break
            if not walk(r, d, pad):
                return state.me(r, pad) is not None and state.me(r, pad).cell == goal
            c = n
        else:
            return state.me(r, pad) is not None and state.me(r, pad).cell == goal
    return False
