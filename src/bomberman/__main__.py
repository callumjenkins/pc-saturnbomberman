"""Saturn Bomberman on saturn-recomp.
    bomberman prepare                     check the disc and extract it into build/
    bomberman play [-- SATURN_ARGS...]    play in a window, saves kept in the user's data directory; the
                                          session (pad, clock, log) is kept in build/play/SESSION
    bomberman replay [SESSION] [--video]  a session played again headless (the latest by default)
    bomberman routes                      list the scripted runs
    bomberman run ROUTE [options] [-- SATURN_ARGS...]
    bomberman run code KEYS [--hold BUTTONS] [options]
    bomberman run stage WORLD-STAGE [options]    such as 3-2, as the game shows it, or M-5 for Master Game's fifth floor
    bomberman run clear WORLD-STAGE [options]    a stage the bot cleared, replayed
    bomberman run attempt WORLD-STAGE [options]  the bot's last run at a stage, cleared or not
    bomberman bot WORLD-STAGE [--limit N]        clear a stage, invincible, and save its presses
    bomberman compare ROUTE | --arenas    against Mednafen's Saturn: a route, or every arena under every sky
--video on run or bot also records the run as video.mp4 in its directory; a clear's is also kept
in $BOMBERMAN_RUNS (bomberman videos).
A run builds the game first if it has to, plays the route headless into build/run/ROUTE (log.txt and
shot-N.png) and learns seeds while the game stops at code discovery missed."""
import argparse
import dataclasses
import sys

import os

from . import bot, compare, lab, prepare, routes, run, session, videos
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
    rp = sub.add_parser("replay")
    rp.add_argument("session", nargs="?", default="latest")
    rp.add_argument("--video", action="store_true", help="record it as replay/video.mp4 in the session")
    rp.add_argument("--window", action="store_true", help="play it in a window")
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
    v = sub.add_parser("videos", help="videos of the saved clears, kept in $BOMBERMAN_RUNS")
    v.add_argument("stages", nargs="*", help="such as 3-2 or M-4 (default: every saved clear)")
    v.add_argument("--jobs", type=int, default=6)
    v.add_argument("--route", action="append", default=[], help="a route's video instead, kept as mechanics/ROUTE.mp4")
    lab_parser = sub.add_parser("lab", help="research tools, each printing a short summary (bomberman.lab)")
    labs = lab_parser.add_subparsers(dest="tool", required=True)
    v = labs.add_parser("verify", help="a route on ours and on Beetle Saturn, by the game's tick")
    v.add_argument("route", choices=list(routes.ROUTES))
    v.add_argument("--from", dest="start", type=int, help="first VBlank compared (default: 400 before the end)")
    v.add_argument("--every", type=int, default=4)
    v = labs.add_parser("sheet", help="a route's frame-test shots on one image")
    v.add_argument("route")
    v.add_argument("--crop", help="X0,Y0,X1,Y1")
    v.add_argument("--columns", type=int, default=4)
    v = labs.add_parser("watch", help="stores to LO:HI during a route, by the function that made them")
    v.add_argument("route", choices=list(routes.ROUTES))
    v.add_argument("range", help="LO:HI in hex")
    v.add_argument("--from", dest="start", type=int, default=0)
    v.add_argument("--to", type=int)
    v = labs.add_parser("disasm", help="instructions from ADDR")
    v.add_argument("addr")
    v.add_argument("count", nargs="?", type=int, default=40)
    v.add_argument("--module")
    v = labs.add_parser("coverage", help="which recompiled code the recorded runs have run, by module")
    v.add_argument("--clears", action="store_true", help="first replay every saved clear with coverage on")
    v = labs.add_parser("ramdiff", help="bytes in LO:HI that differ between VBlanks A and B of a route")
    v.add_argument("route", choices=list(routes.ROUTES))
    v.add_argument("a", type=int)
    v.add_argument("b", type=int)
    v.add_argument("range", help="LO:HI in hex")
    c = sub.add_parser("compare", help="a route on our build against Mednafen's Saturn, by the game's tick")
    c.add_argument("route", nargs="?", choices=list(routes.ROUTES))
    c.add_argument("--arenas", action="store_true", help="every arena under every sky, from the pick into play")
    c.add_argument("--core", default=os.environ.get("SATURN_REFERENCE_CORE"),
                   help="Beetle Saturn's libretro core (default $SATURN_REFERENCE_CORE)")
    c.add_argument("--bios", default=os.environ.get("SATURN_BIOS"),
                   help="the folder holding mpr-17933.bin (default $SATURN_BIOS)")
    c.add_argument("--every", type=int, help="a shot every N VBlanks as well as the route's own")
    args = ap.parse_args(argv)

    if args.command == "prepare":
        prepare.prepare()
    elif args.command == "play":
        prepare.check_prepared()
        run.build.ensure(run.GAME)
        raise SystemExit(session.play(more))
    elif args.command == "replay":
        prepare.check_prepared()
        run.build.ensure(run.GAME)
        raise SystemExit(session.replay(args.session, args.video, args.window, more))
    elif args.command == "videos":
        if args.route:
            for name in args.route:
                print(videos.record_route(name))
        else:
            videos.record_all(set(args.stages), args.jobs)
    elif args.command == "lab":
        span = lambda text: tuple(int(x, 16) for x in text.split(":"))
        if args.tool == "verify":
            route = routes.ROUTES[args.route]()
            lab.verify(route, args.start or max(0, route.vblanks - 400), args.every)
        elif args.tool == "sheet":
            print(lab.sheet(args.route, tuple(map(int, args.crop.split(","))) if args.crop else None, args.columns))
        elif args.tool == "watch":
            print("\n".join(lab.watch(routes.ROUTES[args.route](), *span(args.range), args.start, args.to)))
        elif args.tool == "disasm":
            print("\n".join(lab.disasm(int(args.addr, 16), args.count, args.module)))
        elif args.tool == "coverage":
            if args.clears:
                lab.run_clears_with_coverage()
            never = f"{lab.BUILD}/lab/never-ran.txt"
            os.makedirs(os.path.dirname(never), exist_ok=True)
            print("\n".join(lab.coverage(never)) + f"\nfunctions that never ran: {never}")
        else:
            print("\n".join(lab.ramdiff(routes.ROUTES[args.route](), args.a, args.b, *span(args.range))) or "no difference")
    elif args.command == "compare":
        if not args.core or not args.bios:
            ap.error("compare needs --core and --bios, or SATURN_REFERENCE_CORE and SATURN_BIOS")
        if args.arenas:
            compare.arenas(os.path.expanduser(args.core), os.path.expanduser(args.bios))
            return
        if not args.route:
            ap.error("compare needs a route, or --arenas")
        route = routes.ROUTES[args.route]()
        shots = {int(s) for s in route.shots.split(",") if s}
        if args.every:
            shots |= set(range(args.every, max(shots) + 1, args.every))
        for line in compare.compare(route, args.route, args.core, args.bios, shots):
            print(line)
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
        if args.video and args.route == "clear":
            print("kept", videos.keep(os.path.join(os.path.abspath(out), "video.mp4"), world, number, args.items))


if __name__ == "__main__":
    main()
