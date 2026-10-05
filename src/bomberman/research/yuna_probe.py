"""Hold L+R on Battle's "Which Mode?" screen from START to END, then A through to character select,
and print that frame's md5. END 0 holds nothing.
    uv run -m bomberman.research.yuna_probe END [START] [-- SATURN_ARGS...]"""
import hashlib
import sys

from .. import routes, run


def main():
    argv = sys.argv[1:]
    more = argv[argv.index("--") + 1:] if "--" in argv else []
    argv = argv[:argv.index("--")] if "--" in argv else argv
    end, start = int(argv[0]), int(argv[1]) if len(argv) > 1 else 4200
    out = run.out_dir("yuna")
    log = run.run(routes.yuna(start, end), out, more=more, log=lambda s: None)
    md5 = hashlib.md5(open(f"{out}/shot-6900.png", "rb").read()).hexdigest()[:8]
    print(f"hold {start}-{end} {' '.join(more)}: {md5} {log.count('FATAL')} fatal")


if __name__ == "__main__":
    main()
