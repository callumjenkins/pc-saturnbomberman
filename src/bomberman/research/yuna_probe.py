"""Hold L+R on Battle's "Which Mode?" screen from START to END, then A through to character select,
and print that frame's md5. END 0 holds nothing. Yuna and Manto unlock with the hold at 60 VBlanks.
    uv run -m bomberman.research.yuna_probe END [START] [-- SATURN_ARGS...]"""
import hashlib
import sys

from .. import routes, run


def main():
    argv = sys.argv[1:]
    more = argv[argv.index("--") + 1:] if "--" in argv else []
    argv = argv[:argv.index("--")] if "--" in argv else argv
    end, start = int(argv[0]), int(argv[1]) if len(argv) > 1 else 3780
    hold = (f"{start}:L+R", f"{end}:") if end else ()
    route = routes.Route("", routes.TO_BATTLE + hold + routes.taps(range(5900, 7001, 90), "A", 8), 6900, "4100,6900")
    out = run.out_dir("yuna")
    log = run.run(route, out, more=more, log=lambda s: None)
    md5 = hashlib.md5(open(f"{out}/shot-6900.png", "rb").read()).hexdigest()[:8]
    print(f"hold {start}-{end} {' '.join(more)}: {md5} {log.count('FATAL')} fatal")


if __name__ == "__main__":
    main()
