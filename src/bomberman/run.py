"""One run of a route on the recompiled game, headless."""
import os

from saturnrecomp import build, config, learn

from .paths import BUILD, ROOT, cue

GAME = config.load(f"{ROOT}/game.toml")


def invincible():
    """Hooks that keep every bomber from being hit, though enemies still die."""
    s = GAME.symbols
    return ["--hook", f"{s['bomber_hit_flag']:08X}:r2=0", "--hook", f"{s['bomber_fire_under']:08X}:r0=0"]


def saturn_args(route, vblanks=None, shots=None, extra=(), more=()):
    presses = ",".join((*route.presses, *extra))
    return ["--cue", cue(), "--headless", "--vblanks", str(vblanks or route.vblanks), "--shot", shots or route.shots,
            "--input", presses, *route.args, *(invincible() if route.invincible else []), *more]


def run(route, out, vblanks=None, shots=None, extra=(), more=(), learn_seeds=True, recompile=False, log=print):
    """The run into `out`, and its log. With `learn_seeds`, it builds first if it has to, and while
    the game stops at code discovery missed, adds the seed, recompiles and runs again."""
    args = saturn_args(route, vblanks, shots, extra, more)
    if not learn_seeds:
        return learn.run(GAME, args, out)
    build.ensure(GAME, recompile, log=lambda s: None)
    return learn.learn(GAME, args, out, log=log)


def out_dir(name):
    return os.path.join(BUILD, "run", name)
