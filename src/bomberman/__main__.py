"""Saturn Bomberman on saturn-recomp.
    bomberman prepare                     check the disc and extract it into build/
    bomberman play [-- SATURN_ARGS...]    play in a window, saves kept in the user's data directory
    bomberman routes                      list the scripted runs
    bomberman run ROUTE [options] [-- SATURN_ARGS...]
    bomberman run code KEYS [--hold BUTTONS] [options]
    bomberman run stage WORLD-STAGE [options]    such as 3-2, as the game shows it, or M-5 for Master Game's fifth floor
    bomberman run clear WORLD-STAGE [options]    a stage the bot cleared, replayed
    bomberman run attempt WORLD-STAGE [options]  the bot's last run at a stage, cleared or not
    bomberman bot WORLD-STAGE [--limit N]        clear a stage, invincible, and save its presses
--video on run or bot also records the run as video.mp4 in its directory.
A run builds the game first if it has to, plays the route headless into build/run/ROUTE (log.txt and
shot-N.png) and learns seeds while the game stops at code discovery missed."""
import argparse
import dataclasses
import subprocess
import sys

import os

from . import bot, prepare, routes, run
from .paths import ROOT


def stage_arg(ap, text):
    try:
        world, number = (text or "").split("-")
        return (world if world == routes.MASTER else int(world)), int(number)
    except ValueError:
        ap.error(f"a stage is WORLD-STAGE, such as 3-2, or {routes.MASTER}-FLOOR for Master Game")


def clear_stage(world, number, limit, window, video=False, items=False):
    route = routes.stage(world, number, items)
    start = routes.stage_start(world)
    out = run.out_dir(f"bot-{world}-{number}{routes.tag(items)}")
    more = ["--video", os.path.join(out, "video.mp4")] if video else []
    with run.play(out, route, until=start, invincible=True, window=window, more=more) as r:
        cleared = bot.play(r, limit)
        presses = [p for p in r.presses if int(p.split(":")[0]) >= start]
        r.frame().save_png(os.path.join(r.out, f"end-{r.vblank}.png"))
        open(os.path.join(r.out, "presses.txt"), "w").write(",".join(presses) + "\n")
        print(f"{world}-{number}: {'cleared' if cleared else 'not cleared'} at VBlank {r.vblank}, {len(presses)} presses")
    if cleared:
        path = os.path.join(ROOT, "inputs", "clears", f"{world}-{number}{routes.tag(items)}.txt")
        os.makedirs(os.path.dirname(path), exist_ok=True)
        open(path, "w").write(",".join(presses) + "\n")
        print(f"saved {os.path.relpath(path, ROOT)}: uv run bomberman run clear {world}-{number}{' --items' if items else ''}")


def main(argv=None):
    argv = sys.argv[1:] if argv is None else argv
    more = []
    if "--" in argv:
        at = argv.index("--")
        argv, more = argv[:at], argv[at + 1:]
    ap = argparse.ArgumentParser(prog="bomberman", description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="command", required=True)
    sub.add_parser("prepare")
    sub.add_parser("play")
    sub.add_parser("routes")
    b = sub.add_parser("bot")
    b.add_argument("stage", help="such as 3-2")
    b.add_argument("--limit", type=int, default=22000, help="VBlanks to try for, 60 a second; a stage gives 6:00, about 21600")
    b.add_argument("--window", action="store_true", help="play it in a window")
    b.add_argument("--video", action="store_true", help="record it as video.mp4 beside its log")
    b.add_argument("--items", action="store_true", help="start with every item (the title's held code)")
    r = sub.add_parser("run")
    r.add_argument("route", choices=[*routes.ROUTES, "code", "stage", "clear", "attempt"])
    r.add_argument("which", nargs="?", help="code: its presses in turn, such as L,R,Y,UP; stage: such as 3-2")
    r.add_argument("--hold", default="", help="code: buttons held under every press, such as L+R")
    r.add_argument("--vblanks", type=int, help="how long to run, at 60 VBlanks a second")
    r.add_argument("--shots", help="the VBlanks to save pictures at, comma-separated")
    r.add_argument("--extra", default="", help="more presses, as VBLANK:BUTTONS,...")
    r.add_argument("--invincible", action="store_true", help="no bomber is ever hit")
    r.add_argument("--recompile", action="store_true", help="recompile first, about 45 s")
    r.add_argument("--once", action="store_true", help="run the current build once and learn no seeds")
    r.add_argument("--out", help="the run's directory (default build/run/ROUTE)")
    r.add_argument("--video", action="store_true", help="record it as video.mp4 beside its log")
    r.add_argument("--items", action="store_true", help="stage, clear, attempt: with every item")
    args = ap.parse_args(argv)

    if args.command == "prepare":
        prepare.prepare()
    elif args.command == "play":
        prepare.check_prepared()
        run.build.ensure(run.GAME)
        out = f"{run.BUILD}/play"
        os.makedirs(out, exist_ok=True)
        raise SystemExit(subprocess.run([run.GAME.saturn, "--cue", run.cue(), "--out", out, *more]).returncode)
    elif args.command == "bot":
        world, number = stage_arg(ap, args.stage)
        clear_stage(world, number, args.limit, args.window, args.video, args.items)
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
        elif args.route in ("stage", "clear", "attempt"):
            world, number = stage_arg(ap, args.which)
            make = {"stage": routes.stage, "clear": routes.clear, "attempt": routes.attempt}[args.route]
            try:
                route = make(world, number, args.items)
            except (ValueError, FileNotFoundError) as e:
                ap.error(str(e))
        else:
            route = routes.ROUTES[args.route]()
        if args.invincible:
            route = dataclasses.replace(route, invincible=True)
        extra = args.extra.split(",") if args.extra else ()
        name = f"{args.route}-{args.which}{routes.tag(args.items)}" if args.route in ("stage", "clear", "attempt") else args.route
        out = args.out or run.out_dir(name)
        if args.video:
            more = [*more, "--video", os.path.join(os.path.abspath(out), "video.mp4")]
        print(run.run(route, out, args.vblanks, args.shots, extra, more,
                      learn_seeds=not args.once, recompile=args.recompile,
                      log=lambda s: print(s, flush=True)))


if __name__ == "__main__":
    main()
