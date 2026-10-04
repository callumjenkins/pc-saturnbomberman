"""Build the game if needed, then run it headless, learning seeds while it stops at code discovery
missed (saturnrecomp.learn).
    uv run tools/iterate.py VBLANKS SHOTS [LIMIT]

SATURN_ARGS adds the saturn executable's own arguments. INVINCIBLE=1 stops any bomber being hit,
though enemies still die. RECOMPILE=1 recompiles first. RUN_OUT sends the run to another directory.
RUN_ONCE runs the current build once, adding no seeds."""
import os
import sys

from paths import ROOT, RUN, cue
from saturnrecomp import build, config, learn

GAME = config.load(f"{ROOT}/game.toml")


def invincible():
    s = GAME.symbols
    return ["--hook", f"{s['bomber_hit_flag']:08X}:r2=0", "--hook", f"{s['bomber_fire_under']:08X}:r0=0"]


def main():
    vblanks = sys.argv[1] if len(sys.argv) > 1 else "1800"
    shots = sys.argv[2] if len(sys.argv) > 2 else "120,300,600,900,1200,1800"
    limit = int(sys.argv[3]) if len(sys.argv) > 3 else 40
    args = ["--cue", cue(), "--headless", "--vblanks", vblanks, "--shot", shots,
            *(invincible() if os.environ.get("INVINCIBLE") else []), *os.environ.get("SATURN_ARGS", "").split()]
    out = os.environ.get("RUN_OUT", RUN)
    if os.environ.get("RUN_ONCE"):
        print(learn.run(GAME, args, out))
        return
    build.ensure(GAME, bool(os.environ.get("RECOMPILE")), log=lambda s: None)
    print(learn.learn(GAME, args, out, limit, log=lambda s: print(s, flush=True)))


if __name__ == "__main__":
    main()
