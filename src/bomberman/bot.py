"""A bot that clears a Normal Game stage with the bomber made invincible: it bombs every enemy, breaking
soft blocks to reach them, then walks to the exit. It plays through saturnrecomp.agent, so the presses
it makes replay the same run as a route."""
import collections

from . import routes, state

DIRS = {"UP": (0, -1), "DOWN": (0, 1), "LEFT": (-1, 0), "RIGHT": (1, 0)}


def paths(stage, start):
    """For each cell the bomber can walk to, the presses that get there."""
    prev = {start: None}
    q = collections.deque([start])
    while q:
        c = q.popleft()
        for d, (dx, dy) in DIRS.items():
            n = (c[0] + dx, c[1] + dy)
            if n not in prev and stage.passable(n):
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


def plan(stage, fire):
    """Where to go next and whether to bomb there: a cell whose blast reaches a target, else one that
    breaks the soft block nearest a target, else the exit once none is left. The targets are the Core
    Mechanisms, which alone keep the exit shut, or every enemy in a stage without them, such as a
    boss's."""
    reachable, path = paths(stage, stage.me.cell)
    foes = stage.cores or stage.enemies
    if not stage.cores and stage.exit in reachable and stage.exit != stage.me.cell:
        return path(stage.exit), False
    if not foes:
        if stage.exit in reachable:
            return path(stage.exit), False
        targets = {stage.exit}
    else:
        targets = {e.cell for e in foes}
    best = None
    for c in reachable:
        hit, soft = blast(stage, c, fire)
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
    if best is None and foes:
        # nothing in reach, as against a boss: blast from the nearest cell, where each new bomb lands in
        # the last one's fire and goes off at once
        near = min(reachable, key=lambda c: (min(abs(c[0] - t[0]) + abs(c[1] - t[1]) for t in targets), len(path(c))))
        return path(near), True
    return (path(best[1]), True) if best else ([], False)


def walk(r, d, pad=1):
    """Hold d until the bomber stands on the next cell in that direction, aligned to it. False if it
    did not get there. A bomb dropped on fire goes off at once, so it drops one on every burning cell
    it crosses: with invincibility that keeps a blast going wherever it walks."""
    me = state.me(r, pad)
    if me is None:
        return True
    dx, dy = DIRS[d]
    goal = (me.cell[0] + dx, me.cell[1] + dy)
    r.pad(d, pad)
    arrived = False
    for _ in range(30):
        r.step(2)
        me = state.me(r, pad)
        if me is None:                            # gone: the exit took it
            arrived = True
            break
        under = state.cell(r, me.cell)
        if under & state.FIRE and not under & state.BOMB:
            r.pad(d + "+C", pad)
            r.step(2)
            r.pad(d, pad)
        if me.cell == goal and abs(me.x - goal[0] * 16) < 2 and abs(me.y - goal[1] * 16) < 3:
            arrived = True
            break
    r.pad("", pad)
    return arrived


def stage_number(r):
    """World and stage, or in Master Game its world and floor."""
    from .run import GAME
    master = r.read(GAME.symbols["stage_2"], 2)
    return master if master[0] == state.MASTER_WORLD else r.read(GAME.symbols["stage"], 2)


# Master Game enemies that dodge every blast: once none has died for this long, the bot hits them by hand.
PATIENCE = 1800


def strike(r, enemies):
    """Sets the hit flag on each enemy, the way a blast does, and records each write in the run's presses as
    VBLANK:@ADDR=HEX, which routes.clear replays as a write."""
    from .run import GAME
    for e in enemies:
        at = GAME.symbols["objects"] + e.slot * state.SLOT + 0x34
        flags = bytes([r.read(at, 1)[0] | 0x40])
        r.write(at, flags)
        r.presses.append(f"{r.vblank}:@{at:08X}={flags.hex()}")


def play(r, limit, log=print, fire=2):
    """Play the stage the run is in until it changes or `limit` VBlanks pass; whether it was cleared."""
    start, end = stage_number(r), r.vblank + limit
    final = start in (bytes([len(routes.STAGES) - 1, routes.STAGES[len(routes.STAGES)] - 1]),
                      bytes([state.MASTER_WORLD, routes.FLOORS - 1]))
    master = start[0] == state.MASTER_WORLD
    stuck, gone_since = 0, None
    count, changed = None, r.vblank
    while r.vblank < end:
        if stage_number(r) != start:
            return True
        stage = state.read(r)
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
        if state.cannon(stage.at(stage.me.cell)):
            r.pad("A")                           # in a cannon: fire out of it
            r.step(10)
            r.pad("")
            r.step(60)
            continue
        moves, bomb = plan(stage, fire)
        if not moves and not bomb:
            r.pad("B")                           # sets off a remote-control bomb, which waits for it
            r.step(4)
            r.pad("")
            r.step(16)
            continue
        for d in moves[:8]:
            if not walk(r, d):
                stuck += 1
                # a bomber that cannot move is often in a scene with dialogue, which A and C move on
                r.pad("A" if stuck % 2 else "C")
                r.step(4)
                r.pad("")
                r.step(10)
                break
        else:
            stuck = 0
            if bomb and len(moves) <= 8:
                r.pad("C")
                r.step(4)
                r.pad("B")                       # sets off a remote-control bomb at once; nothing without one
                r.step(4)
                r.pad("")
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
