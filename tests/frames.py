"""Replay the scripted runs on the current build and compare their frames with the recorded ones.
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

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, f"{ROOT}/tools")
from paths import BUILD, SAT  # noqa: E402

EXPECTED = f"{ROOT}/tests/frames.json"

# name: (script and its arguments, VBlanks, shots, extra environment)
RUNS = {
    "normal": (["run-normal.sh"], 9000, "4500,6300,8100,9000", {}),
    "single": (["run-single.sh"], 8400, "6500,8400", {}),
    "battle": (["run-battle.sh"], 8880, "7700,8880", {}),
    "hige": (["run-world.sh", "L+R+A+UP+LEFT"], 6000, "4800,6000", {}),
    "mage": (["run-world.sh", "L+R+B+UP+LEFT"], 6000, "4800,6000", {}),
    "gunman": (["run-world.sh", "L+R+C+UP+RIGHT"], 6000, "4800,6000", {}),
    "tyranno": (["run-world.sh", "L+R+X+UP+RIGHT"], 6000, "4800,6000", {}),
    "mujoe": (["run-world.sh", "L+R+Y+UP"], 6000, "4800,6000", {}),
    "slot": (["run-slot.sh"], 7200, "6700,7090,7106,7200", {}),
}


def replay(name):
    """The run's frames as {VBlank: md5}, and its fatal errors."""
    script, vblanks, shots, env = RUNS[name]
    out = f"{BUILD}/test/{name}"
    subprocess.run([f"{ROOT}/scripts/{script[0]}", *script[1:], str(vblanks), shots],
                   env=dict(os.environ, **env, RUN_OUT=out, RUN_ONCE="1"), capture_output=True, check=True)
    frames = {}
    for v in shots.split(","):
        path = f"{out}/shot-{v}.png"
        frames[v] = hashlib.md5(open(path, "rb").read()).hexdigest() if os.path.exists(path) else None
    fatal = [line for line in open(f"{out}/log.txt") if "FATAL" in line]
    return frames, fatal


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--update", action="store_true")
    ap.add_argument("names", nargs="*")
    args = ap.parse_args()
    names = args.names or list(RUNS)
    unknown = [n for n in names if n not in RUNS]
    if unknown:
        raise SystemExit(f"no run named {', '.join(unknown)}; the runs are {', '.join(RUNS)}")
    if not os.path.exists(SAT):
        raise SystemExit("no build yet: run any script in scripts/ once")
    subprocess.run(["ninja", "-C", "recomp-build"], cwd=BUILD, check=True, capture_output=True)

    expected = json.load(open(EXPECTED)) if os.path.exists(EXPECTED) else {}
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as ex:
        results = dict(zip(names, ex.map(replay, names)))

    failed = 0
    for name in names:
        frames, fatal = results[name]
        if args.update:
            expected[name] = frames
        diffs = [v for v in frames if frames[v] != expected.get(name, {}).get(v)]
        bad = fatal or (diffs and not args.update)
        failed += bool(bad)
        status = "FAIL" if bad else "recorded" if args.update else "ok"
        detail = "; ".join([*(f"frame {v} differs" for v in diffs if not args.update), *(f.strip() for f in fatal)])
        print(f"{status:8} {name}" + (f": {detail}" if detail and bad else ""))
    if args.update:
        json.dump(expected, open(EXPECTED, "w"), indent=1, sort_keys=True)
        open(EXPECTED, "a").write("\n")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
