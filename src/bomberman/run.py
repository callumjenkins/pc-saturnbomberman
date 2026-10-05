"""One run of a route on the recompiled game, headless. A run starts with no saves and keeps none."""
import os

from saturnrecomp import agent, build, config, learn

from .paths import BUILD, ROOT, cue

GAME = config.load(f"{ROOT}/game.toml")


def invincible_hooks():
    """Hooks that keep every bomber from being hit, though enemies still die."""
    s = GAME.symbols
    return ["--hook", f"{s['bomber_hit_flag']:08X}:r2=0", "--hook", f"{s['bomber_fire_under']:08X}:r0=0",
            "--hook", f"{s['bomber_touched']:08X}:r3=8"]


def saturn_args(route, vblanks=None, shots=None, extra=(), more=()):
    presses = ",".join((*route.presses, *extra))
    return ["--cue", cue(), "--headless", "--save", "-", "--vblanks", str(vblanks or route.vblanks), "--shot", shots or route.shots,
            "--input", presses, *route.args, *(invincible_hooks() if route.invincible else []),
            *(["--write", ",".join(route.writes)] if route.writes else []), *more]


def run(route, out, vblanks=None, shots=None, extra=(), more=(), learn_seeds=True, recompile=False, log=print):
    """The run into `out`, and its log. With `learn_seeds`, it builds first if it has to, and while
    the game stops at code discovery missed, adds the seed, recompiles and runs again."""
    args = saturn_args(route, vblanks, shots, extra, more)
    if not learn_seeds:
        return learn.run(GAME, args, out)
    build.ensure(GAME, recompile, log=lambda s: None)
    return learn.learn(GAME, args, out, log=log)


def play(out, route=None, until=0, invincible=False, window=False, more=()):
    """A run for a program to play (saturnrecomp.agent), on the current build. With a route, its
    presses before VBlank `until` are played first, and its saturn arguments apply."""
    args = ["--cue", cue(), "--save", "-", *([] if window else ["--headless"]), *(route.args if route else ()),
            *(invincible_hooks() if invincible or (route and route.invincible) else []), *more]
    r = agent.start(GAME.saturn, args, out)
    if route and until:
        advance(r, route, until)
    return r


def advance(r, route, to):
    """Play the route's presses and writes from the run's VBlank to just before `to`, and run on to
    VBlank `to`. One at `to` is left for the next call."""
    events = [(int(p.split(":", 1)[0]), "press", p.split(":", 1)[1]) for p in route.presses]
    events += [(int(w.split(":", 1)[0]), "write", w.split(":", 1)[1]) for w in route.writes]
    for at, kind, what in sorted(events, key=lambda e: e[0]):
        if at < r.vblank:
            continue
        if at >= to:
            break
        if at > r.vblank:
            r.step(at - r.vblank)
        if kind == "press":
            pad, _, buttons = what.rpartition(".")
            r.pad(buttons, int(pad) if pad else 1)
        else:
            addr, data = what.split("=")
            r.write(int(addr, 16), bytes.fromhex(data))
    if to > r.vblank:
        r.step(to - r.vblank)


def out_dir(name):
    return os.path.join(BUILD, "run", name)
