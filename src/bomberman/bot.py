"""A bot that clears a Normal Game stage with the bomber made invincible: it bombs every enemy, breaking
soft blocks to reach them, then walks to the exit. It plays through saturnrecomp.agent, so the presses
it makes replay the same run as a route."""
import collections

from . import state

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
    """Where to go next and whether to bomb there: a cell whose blast reaches an enemy, else one that
    breaks the soft block nearest an enemy, else the exit once no enemy is left."""
    reachable, path = paths(stage, stage.me.cell)
    if not stage.enemies:
        if stage.exit in reachable:
            return path(stage.exit), False
        targets = {stage.exit}
    else:
        targets = {e.cell for e in stage.enemies}
    best = None
    for c in reachable:
        hit, soft = blast(stage, c, fire)
        steps = len(path(c))
        if hit & targets and stage.enemies:
            score = (0, steps)
        elif soft:
            near = min(abs(s[0] - t[0]) + abs(s[1] - t[1]) for s in soft for t in targets)
            score = (1, near * 4 + steps)
        else:
            continue
        if best is None or score < best[0]:
            best = (score, c)
    return (path(best[1]), True) if best else ([], False)


def walk(r, d):
    """Hold d until the bomber stands on the next cell in that direction, aligned to it. False if it
    did not get there. A bomb dropped on fire goes off at once, so it drops one on every burning cell
    it crosses: with invincibility that keeps a blast going wherever it walks."""
    me = state.me(r)
    if me is None:
        return True
    dx, dy = DIRS[d]
    goal = (me.cell[0] + dx, me.cell[1] + dy)
    r.pad(d)
    arrived = False
    for _ in range(30):
        r.step(2)
        me = state.me(r)
        if me is None:                            # gone: the exit took it
            arrived = True
            break
        under = state.cell(r, me.cell)
        if under & state.FIRE and not under & state.BOMB:
            r.pad(d + "+C")
            r.step(2)
            r.pad(d)
        if me.cell == goal and abs(me.x - goal[0] * 16) < 2 and abs(me.y - goal[1] * 16) < 3:
            arrived = True
            break
    r.pad("")
    return arrived


def stage_number(r):
    from .run import GAME
    return r.read(GAME.symbols["stage"], 2)


def play(r, limit, log=print, fire=2):
    """Play the stage the run is in until it changes or `limit` VBlanks pass; whether it was cleared."""
    start, end = stage_number(r), r.vblank + limit
    stuck = 0
    while r.vblank < end:
        if stage_number(r) != start:
            return True
        stage = state.read(r)
        if stage.me is None:                     # a cutscene or a change of scene: C and START move them on
            r.pad("C" if (r.vblank // 10) % 2 else "START")
            r.step(4)
            r.pad("")
            r.step(6)
            continue
        moves, bomb = plan(stage, fire)
        if not moves and (not bomb or stage.at(stage.me.cell) & state.BOMB):
            r.pad("B")                           # sets off a remote-control bomb, which waits for it
            r.step(4)
            r.pad("")
            r.step(16)
            continue
        for d in moves[:8]:
            if not walk(r, d):
                stuck += 1
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
        if stuck > 20:
            log(f"{r.vblank}: stuck at {stage.me.cell}")
            return False
    return False
