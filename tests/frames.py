"""Replay the routes on the current build and compare their frames with the recorded ones.
    uv run tests/frames.py [NAME ...]             # all runs, or the ones named
    uv run tests/frames.py --update [NAME ...]    # record the frames as they are now

Runs are deterministic, so a frame that changes means the game ran differently. A change can be
right, such as a VDP2 feature that now draws, so look at the frames in build/test/NAME before
recording them with --update."""
import argparse
import concurrent.futures
import hashlib
import json
import os
import sys

from PIL import Image
from saturnrecomp import build

from bomberman import routes, run
from bomberman.paths import BUILD, ROOT

EXPECTED = f"{ROOT}/tests/frames.json"
RUNS = {**{name: routes.ROUTES[name] for name in ["normal", "single", "battle", "items", *routes.WORLDS, "slot", "yuna"]},
        "stage-5-3": lambda: routes.stage(5, 3), "clear-1-1": lambda: routes.clear(1, 1),
        "clear-1-7": lambda: routes.clear(1, 7),
        **{name: routes.ROUTES[name] for name in ["die", "continue", "save", "pause", "battle-round"]},
        **{name: routes.ROUTES[name] for name in routes.ROUTES if name.startswith("arena-")},
        "clear-M-1": lambda: routes.clear(routes.MASTER, 1),
        **{name: routes.ROUTES[name] for name in ["master", "master-boss", "master-result", "master-ending", "mad-bomber",
                                                     "team", "five-minutes", "bonus-game",
                                                     "kick-goal", "dino-hatch", *routes.DINO_ROUTES,
                                                     *(f"item-{k}" for k in routes.ITEM_KINDS), "egg-burn", "egg-second", "dino-evolve",
                                                     "open-arena", *routes.MECHANICS, "com-level-1", "com-level-3"]}}
# Lines a run's log must hold, for what a frame does not show.
LOG_LINES = {"save": ["BUP: wrote BOMBERSS_01 (12 bytes)"], "master-result": ["BUP: wrote BOMBERSS_02 (240 bytes)"]}


def replay(name):
    """The run's frames as {VBlank: md5}, and its problems: fatal errors and missing log lines."""
    route = RUNS[name]()
    out = f"{BUILD}/test/{name}"
    log = run.run(route, out, learn_seeds=False)
    frames = {}
    for v in route.shots.split(","):
        path = f"{out}/shot-{v}.png"
        frames[v] = hashlib.md5(open(path, "rb").read()).hexdigest() if os.path.exists(path) else None
    problems = [line for line in log.splitlines() if "FATAL" in line]
    problems += [f"no log line {want!r}" for want in LOG_LINES.get(name, []) if want not in log]
    return frames, problems


def agent_matches():
    """Whether stage 5-3 played through the agent, its write included, and a VBlank at a time for the
    last 100, gives the frame the scripted run did."""
    route = RUNS["stage-5-3"]()
    end = int(route.shots)
    with run.play(f"{BUILD}/test/agent", route, until=end - 100) as r:
        while r.vblank < end:
            run.advance(r, route, r.vblank + 1)
        frame = r.frame()
    shot = Image.open(f"{BUILD}/test/stage-5-3/shot-{end}.png").convert("RGB")
    return shot.size == (frame.width, frame.height) and shot.tobytes() == frame.rgb


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--update", action="store_true")
    ap.add_argument("names", nargs="*")
    args = ap.parse_args()
    names = args.names or list(RUNS)
    unknown = [n for n in names if n not in RUNS]
    if unknown:
        raise SystemExit(f"no run named {', '.join(unknown)}; the runs are {', '.join(RUNS)}")
    build.ensure(run.GAME)

    expected = json.load(open(EXPECTED)) if os.path.exists(EXPECTED) else {}
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as ex:
        results = dict(zip(names, ex.map(replay, names)))

    failed = 0
    for name in names:
        frames, problems = results[name]
        problems = problems + [f"no frame {v}" for v in frames if frames[v] is None]
        # a run with a problem is never recorded as the expected one
        if args.update and not problems:
            expected[name] = frames
        diffs = [v for v in frames if frames[v] != expected.get(name, {}).get(v)]
        bad = problems or (diffs and not args.update)
        failed += bool(bad)
        status = "FAIL" if bad else "recorded" if args.update else "ok"
        detail = "; ".join([*(f"frame {v} differs" for v in diffs if not args.update), *(p.strip() for p in problems)])
        print(f"{status:8} {name}" + (f": {detail}" if detail and bad else ""))
    if "stage-5-3" in names and not args.update:
        ok = agent_matches()
        failed += not ok
        print(f"{'ok' if ok else 'FAIL':8} agent: stage 5-3 played through the agent"
              + ("" if ok else " gives a different frame"))
    if args.update:
        json.dump(expected, open(EXPECTED, "w"), indent=1, sort_keys=True)
        open(EXPECTED, "a").write("\n")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
