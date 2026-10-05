"""Saturn Bomberman on saturn-recomp.
    bomberman prepare                     extract the disc into build/
    bomberman routes                      list the scripted runs
    bomberman run ROUTE [options] [-- SATURN_ARGS...]
    bomberman run code KEYS [--hold BUTTONS] [options]
    bomberman run stage WORLD-STAGE [options]    such as 3-2, as the game shows it
    bomberman run clear WORLD-STAGE [options]    a stage the bot cleared, replayed
    bomberman bot WORLD-STAGE [--limit N]        clear a stage, invincible, and save its presses
A run builds the game first if it has to, plays the route headless into build/run/ROUTE (log.txt and
shot-N.png) and learns seeds while the game stops at code discovery missed."""
import argparse
import dataclasses
import sys

import os

from . import bot, prepare, routes, run
from .paths import ROOT


def stage_arg(ap, text):
    try:
        world, number = map(int, (text or "").split("-"))
    except ValueError:
        ap.error("a stage is WORLD-STAGE, such as 3-2")
    return world, number


def clear_stage(world, number, limit, window):
    route = routes.stage(world, number)
    start = 5700
    with run.play(run.out_dir(f"bot-{world}-{number}"), route, until=start, invincible=True, window=window) as r:
        cleared = bot.play(r, limit)
        presses = [p for p in r.presses if int(p.split(":")[0]) >= start]
        r.frame().save_png(os.path.join(r.out, f"end-{r.vblank}.png"))
        print(f"{world}-{number}: {'cleared' if cleared else 'not cleared'} at VBlank {r.vblank}, {len(presses)} presses")
    if cleared:
        path = os.path.join(ROOT, "inputs", "clears", f"{world}-{number}.txt")
        os.makedirs(os.path.dirname(path), exist_ok=True)
        open(path, "w").write(",".join(presses) + "\n")
        print(f"saved {os.path.relpath(path, ROOT)}: uv run bomberman run clear {world}-{number}")


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
    b = sub.add_parser("bot")
    b.add_argument("stage", help="such as 3-2")
    b.add_argument("--limit", type=int, default=12000, help="VBlanks to try for, 60 a second")
    b.add_argument("--window", action="store_true", help="play it in a window")
    r = sub.add_parser("run")
    r.add_argument("route", choices=[*routes.ROUTES, "code", "stage", "clear"])
    r.add_argument("which", nargs="?", help="code: its presses in turn, such as L,R,Y,UP; stage: such as 3-2")
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
    elif args.command == "bot":
        world, number = stage_arg(ap, args.stage)
        clear_stage(world, number, args.limit, args.window)
    elif args.command == "routes":
        for name, make in routes.ROUTES.items():
            print(f"{name:10} {make().about}")
        print(f"{'code':10} {routes.code.__doc__.split('.')[0]}")
        print(f"{'stage':10} any stage, such as stage 3-2, through Normal Game with the stage select")
    else:
        if args.route == "code":
            if not args.which:
                ap.error("run code needs KEYS")
            route = routes.code(args.which, args.hold)
        elif args.route in ("stage", "clear"):
            world, number = stage_arg(ap, args.which)
            try:
                route = routes.stage(world, number) if args.route == "stage" else routes.clear(world, number)
            except (ValueError, FileNotFoundError) as e:
                ap.error(str(e))
        else:
            route = routes.ROUTES[args.route]()
        if args.invincible:
            route = dataclasses.replace(route, invincible=True)
        extra = args.extra.split(",") if args.extra else ()
        name = f"{args.route}-{args.which}" if args.route in ("stage", "clear") else args.route
        print(run.run(route, args.out or run.out_dir(name), args.vblanks, args.shots, extra, more,
                      learn_seeds=not args.once, recompile=args.recompile,
                      log=lambda s: print(s, flush=True)))


if __name__ == "__main__":
    main()
