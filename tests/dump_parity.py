"""Dump the machine near the end of each run and compare the dump part by part with another build's.
    uv run tests/dump_parity.py --saturn EXE --expected FILE --update [NAME ...]   # record this build's dumps
    uv run tests/dump_parity.py --saturn EXE --expected FILE [NAME ...]            # compare this build's with them

A dump holds the memory, the processors and every device, so two builds whose dumps are equal also agree
on state the frames have not shown yet. docs/PLATFORMS.md says how this checks a build for another platform."""
import argparse
import concurrent.futures
import hashlib
import json
import os
import re
import struct
import subprocess
import sys

from frames import SOUNDS

from bomberman import routes, run
from bomberman.paths import BUILD
from bomberman.prepare import check_prepared

DUMP_BEFORE_END = 100
MAGIC = b"SATSTATE"


def dump(name: str) -> dict:
    """The run's dump as {"vblank": the VBlank it was taken at, "parts": its parts' hashes}, or {"error": why there is none}."""
    route = routes.ROUTES[name]()
    out = f"{BUILD}/test/dump-parity-{name}"
    os.makedirs(out, exist_ok=True)
    state = f"{out}/state.bin"
    with open(f"{out}/log.txt", "w", encoding="utf-8") as log:
        p = subprocess.run([run.GAME.saturn, "--out", out, *run.saturn_args(route),
                            "--state-out", state, "--state-at", str(route.vblanks - DUMP_BEFORE_END)],
                           stdout=log, stderr=subprocess.STDOUT, timeout=1800)
    with open(f"{out}/log.txt", encoding="utf-8", errors="replace") as log:
        written = re.search(r"state: VBlank (\d+) to", log.read())
    if p.returncode or not written:
        return {"error": f"exit status {p.returncode}, {'a' if written else 'no'} dump written; see {out}/log.txt"}
    with open(state, "rb") as f:
        return {"vblank": int(written.group(1)), "parts": parts(f.read())}


def parts(data: bytes) -> dict[str, str]:
    """The SHA-256 of each part of a dump in saturn-recomp's state.cpp format, by the part's name."""
    if data[:len(MAGIC)] != MAGIC:
        raise ValueError("not a dump")
    at, found = len(MAGIC) + 4, {}
    while at < len(data):
        n = data[at]
        body = at + 1 + n + 8
        if body > len(data):
            raise ValueError("cut short in a part's name or size")
        name = data[at + 1:at + 1 + n].decode()
        (size,) = struct.unpack_from("<Q", data, at + 1 + n)
        if body + size > len(data):
            raise ValueError(f"the part {name} is cut short")
        found[name] = hashlib.sha256(data[body:body + size]).hexdigest()
        at = body + size
    return found


def problems(got: dict, want: dict) -> list[str]:
    """How a dump differs from the recorded one: the VBlank it was taken at, and the parts that differ."""
    if "error" in got:
        return [got["error"]]
    if not want:
        return ["nothing recorded"]
    found = [] if got["vblank"] == want["vblank"] else [f"taken at VBlank {got['vblank']}, recorded at {want['vblank']}"]
    differ = [p for p in [*want["parts"], *(p for p in got["parts"] if p not in want["parts"])]
              if got["parts"].get(p) != want["parts"].get(p)]
    return found + ([f"{len(differ)} of {len(want['parts'])} parts differ: {', '.join(differ)}"] if differ else [])


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--saturn", required=True, help="run this executable, as it is")
    ap.add_argument("--expected", required=True, help="the recording to compare with or --update")
    ap.add_argument("--update", action="store_true")
    ap.add_argument("names", nargs="*")
    args = ap.parse_args()
    if not os.path.isfile(args.saturn):
        raise SystemExit(f"--saturn {args.saturn}: no such executable")
    names = args.names or sorted(SOUNDS)
    unknown = [n for n in names if n not in routes.ROUTES]
    if unknown:
        raise SystemExit(f"no route named {', '.join(unknown)}")
    check_prepared()
    run.GAME.executable = os.path.abspath(args.saturn)

    with concurrent.futures.ThreadPoolExecutor(len(names)) as ex:
        got = dict(zip(names, ex.map(dump, names)))
    expected = {}
    if os.path.exists(args.expected):
        with open(args.expected, encoding="utf-8") as f:
            expected = json.load(f)
    failed = 0
    for name in names:
        if args.update:
            found = [got[name]["error"]] if "error" in got[name] else []
            if not found:
                expected[name] = got[name]
        else:
            found = problems(got[name], expected.get(name, {}))
        failed += bool(found)
        detail = "; ".join(found) or f"{len(got[name]['parts'])} parts at VBlank {got[name]['vblank']}"
        print(f"{'FAIL' if found else 'ok':8} {name}: {detail}")
    if args.update:
        with open(args.expected, "w", encoding="utf-8") as f:
            json.dump(expected, f, indent=1, sort_keys=True)
            f.write("\n")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
