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
import subprocess
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
        **{name: routes.ROUTES[name] for name in ["master", "master-boss", "master-result", "master-ending", "cannon", *routes.BOSS_ROUTES, "mad-bomber",
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
    log = run.run(route, out, more=["--coverage", f"{out}/coverage.txt"], learn_seeds=False)
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


def controllers_match():
    """Problems with the 10-player battle played on ten SDL virtual gamepads instead of a script: its
    frames must be the scripted run's, and its recording the script. It runs in a window, offscreen,
    paced to real time."""
    route = RUNS["battle"]()
    out = f"{BUILD}/test/controllers"
    os.makedirs(out, exist_ok=True)
    args = run.saturn_args(route)
    args.remove("--headless")
    args[args.index("--input")] = "--virtual-input"
    args += ["--settings", "-"]                 # the default bindings, whatever the player's file says
    env = {**os.environ, "SDL_VIDEO_DRIVER": "offscreen", "SDL_AUDIO_DRIVER": "dummy"}
    with open(f"{out}/log.txt", "w") as log:
        subprocess.run([run.GAME.saturn, "--out", out, "--record-input", f"{out}/input.txt", *args],
                       stdout=log, stderr=subprocess.STDOUT, env=env, timeout=600)
    problems = [f"frame {v} differs" for v in route.shots.split(",")
                if not os.path.exists(f"{out}/shot-{v}.png") or
                Image.open(f"{out}/shot-{v}.png").tobytes() != Image.open(f"{BUILD}/test/battle/shot-{v}.png").tobytes()]

    def steps(presses):
        return sorted((int(at), held if "." in held else "1." + held)
                      for at, held in (p.split(":") for p in presses if p))
    recorded = open(f"{out}/input.txt").read().split(",") if os.path.exists(f"{out}/input.txt") else []
    if steps(recorded) != steps(route.presses):
        problems.append("the recording is not the script")
    return problems


# Runs started again from a dump of the machine taken at this VBlank (saturn-recomp's state.cpp).
DUMPS = {"battle": 7000, "clear-1-7": 8000, "master-boss": 13000, "save": 9000}


def dump_matches(name):
    """Problems with the run loaded from a dump taken partway: its frames after the dump must be the
    scripted run's, so a part of the machine the dump leaves out shows up here."""
    route, at = RUNS[name](), DUMPS[name]
    out = f"{BUILD}/test/dump-{name}"
    os.makedirs(out, exist_ok=True)
    dump = f"{out}/state.bin"
    with open(f"{out}/log-dump.txt", "w") as log:
        subprocess.run([run.GAME.saturn, "--out", out, *run.saturn_args(route, vblanks=at + 60, shots=str(at)),
                        "--state-out", dump, "--state-at", str(at)], stdout=log, stderr=subprocess.STDOUT, timeout=600)
    if not os.path.exists(dump):
        return ["no dump was written"]
    with open(f"{out}/log.txt", "w") as log:
        subprocess.run([run.GAME.saturn, "--out", out, *run.saturn_args(route), "--state-in", dump],
                       stdout=log, stderr=subprocess.STDOUT, timeout=600)
    problems = [line.strip() for line in open(f"{out}/log.txt") if "FATAL" in line]
    return problems + [f"frame {v} differs" for v in route.shots.split(",") if int(v) > at and (
        not os.path.exists(f"{out}/shot-{v}.png") or
        Image.open(f"{out}/shot-{v}.png").tobytes() != Image.open(f"{BUILD}/test/{name}/shot-{v}.png").tobytes())]


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
    controllers = "battle" in names and not args.update and not results["battle"][1]
    dumped = [n for n in DUMPS if n in names and not args.update and not results[n][1]]
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as ex:
        dumps = dict(zip(dumped, ex.map(dump_matches, dumped)))

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
    if controllers:
        problems = controllers_match()
        failed += bool(problems)
        print(f"{'FAIL' if problems else 'ok':8} controllers: the battle on ten virtual gamepads"
              + (f": {'; '.join(problems)}" if problems else ""))
    for name, problems in dumps.items():
        failed += bool(problems)
        print(f"{'FAIL' if problems else 'ok':8} dump: {name} from a dump at VBlank {DUMPS[name]}"
              + (f": {'; '.join(problems)}" if problems else ""))
    if args.update:
        json.dump(expected, open(EXPECTED, "w"), indent=1, sort_keys=True)
        open(EXPECTED, "a").write("\n")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
