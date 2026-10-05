"""One run of a route on the recompiled game, headless."""
import os

from saturnrecomp import agent, build, config, learn

from .paths import BUILD, ROOT, cue

GAME = config.load(f"{ROOT}/game.toml")


def invincible_hooks():
    """Hooks that keep every bomber from being hit, though enemies still die."""
    s = GAME.symbols
    return ["--hook", f"{s['bomber_hit_flag']:08X}:r2=0", "--hook", f"{s['bomber_fire_under']:08X}:r0=0"]


def saturn_args(route, vblanks=None, shots=None, extra=(), more=()):
    presses = ",".join((*route.presses, *extra))
    return ["--cue", cue(), "--headless", "--vblanks", str(vblanks or route.vblanks), "--shot", shots or route.shots,
            "--input", presses, *route.args, *(invincible_hooks() if route.invincible else []), *more]


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
    presses up to VBlank `until` are played first, and its saturn arguments apply."""
    args = ["--cue", cue(), *([] if window else ["--headless"]), *(route.args if route else ()),
            *(invincible_hooks() if invincible or (route and route.invincible) else []), *more]
    r = agent.start(GAME.saturn, args, out)
    presses = sorted(route.presses if route else (), key=lambda p: int(p.split(":", 1)[0]))
    for press in presses:
        at, buttons = press.split(":", 1)
        if int(at) > until:
            break
        if int(at) > r.vblank:
            r.step(int(at) - r.vblank)
        pad, _, buttons = buttons.rpartition(".")
        r.pad(buttons, int(pad) if pad else 1)
    return r


def out_dir(name):
    return os.path.join(BUILD, "run", name)
