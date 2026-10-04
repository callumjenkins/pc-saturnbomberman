"""Saturn Bomberman on saturn-recomp.
    bomberman prepare                     extract the disc into build/
    bomberman routes                      list the scripted runs
    bomberman run ROUTE [options] [-- SATURN_ARGS...]
    bomberman run code KEYS [--hold BUTTONS] [options]
A run builds the game first if it has to, plays the route headless into build/run/ROUTE (log.txt and
shot-N.png) and learns seeds while the game stops at code discovery missed."""
import argparse
import dataclasses
import sys

from . import prepare, routes, run


def main(argv=None):
    argv = sys.argv[1:] if argv is None else argv
    more = []
    if "--" in argv:
        at = argv.index("--")
        argv, more = argv[:at], argv[at + 1:]
    ap = argparse.ArgumentParser(prog="bomberman", description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="command", required=True)
    sub.add_parser("prepare")
    sub.add_parser("routes")
    r = sub.add_parser("run")
    r.add_argument("route", choices=[*routes.ROUTES, "code"])
    r.add_argument("keys", nargs="?", help="code's presses in turn, comma-separated, such as L,R,Y,UP")
    r.add_argument("--hold", default="", help="code: buttons held under every press, such as L+R")
    r.add_argument("--vblanks", type=int, help="how long to run, at 60 VBlanks a second")
    r.add_argument("--shots", help="the VBlanks to save pictures at, comma-separated")
    r.add_argument("--extra", default="", help="more presses, as VBLANK:BUTTONS,...")
    r.add_argument("--invincible", action="store_true", help="no bomber is ever hit")
    r.add_argument("--recompile", action="store_true", help="recompile first, about 45 s")
    r.add_argument("--once", action="store_true", help="run the current build once and learn no seeds")
    r.add_argument("--out", help="the run's directory (default build/run/ROUTE)")
    args = ap.parse_args(argv)

    if args.command == "prepare":
        prepare.prepare()
    elif args.command == "routes":
        for name, make in routes.ROUTES.items():
            print(f"{name:10} {make().about}")
        print(f"{'code':10} {routes.code.__doc__.split('.')[0]}")
    else:
        if args.route == "code":
            if not args.keys:
                ap.error("run code needs KEYS")
            route = routes.code(args.keys, args.hold)
        else:
            route = routes.ROUTES[args.route]()
        if args.invincible:
            route = dataclasses.replace(route, invincible=True)
        extra = args.extra.split(",") if args.extra else ()
        print(run.run(route, args.out or run.out_dir(args.route), args.vblanks, args.shots, extra, more,
                      learn_seeds=not args.once, recompile=args.recompile,
                      log=lambda s: print(s, flush=True)))


if __name__ == "__main__":
    main()
