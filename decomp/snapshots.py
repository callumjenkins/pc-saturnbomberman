"""Dumps the game's work RAM at points along the routes, for check.py to start trials from.

    python decomp/snapshots.py [--jobs J]

Each dump is the runtime's --state-out at one VBlank, cut down to work RAM-H then work RAM-L, and
goes to build/decomp/ram/ROUTE-VBLANK.bin. The routes rebuild the game first if it is out of date.
"""
import argparse
import concurrent.futures
import os
import struct
import subprocess
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
OUT = os.path.join(ROOT, "build", "decomp", "ram")
POINTS = {
    "normal": (3000, 6000, 8500),
    "battle-round": (5000, 10000, 15000),
    "mad-bomber-com": (4000, 8000),
    "bonus-game": (6000, 12000, 17000),
    "die": (3000, 5500),
    "items": (3000, 5500),
}
RAM = 0x100000


def paths() -> list[str]:
    try:
        return sorted(os.path.join(OUT, name) for name in os.listdir(OUT) if name.endswith(".bin"))
    except FileNotFoundError:
        return []


def work_ram(state: bytes) -> bytes:
    """Work RAM-H then work RAM-L, from a dump: "SATSTATE", a version, then each part as a length-prefixed
    name, a little-endian 64-bit size and its bytes. The core part starts with RAM-L then RAM-H."""
    at = 12
    while at < len(state):
        n = state[at]
        name = state[at + 1:at + 1 + n].decode()
        size, = struct.unpack_from("<Q", state, at + 1 + n)
        at += 9 + n
        if name == "core":
            return state[at + RAM:at + 2 * RAM] + state[at:at + RAM]
        at += size
    raise ValueError("no core part in the dump")


def _dump(route: str, vblank: int) -> str:
    with tempfile.TemporaryDirectory() as scratch:
        state = os.path.join(scratch, "game.state")
        subprocess.run(["uv", "run", "bomberman", "run", route, "--", "--state-out", state, "--state-at", str(vblank)],
                       cwd=ROOT, check=True, capture_output=True, timeout=1800)
        with open(state, "rb") as f:
            ram = work_ram(f.read())
    path = os.path.join(OUT, "%s-%d.bin" % (route, vblank))
    with open(path, "wb") as f:
        f.write(ram)
    return path


def _dump_route(route: str) -> list[str]:
    """One route's points in turn, since two runs of a route share its directory under build/run."""
    return [_dump(route, vblank) for vblank in POINTS[route] if not os.path.exists(os.path.join(OUT, "%s-%d.bin" % (route, vblank)))]


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--jobs", type=int, default=4)
    args = parser.parse_args()
    os.makedirs(OUT, exist_ok=True)
    routes = list(POINTS)
    print(_dump(routes[0], POINTS[routes[0]][0]))      # builds the game, if it has to, before the runs share it
    with concurrent.futures.ThreadPoolExecutor(args.jobs) as pool:
        for done in pool.map(_dump_route, routes):
            print("\n".join(done))


if __name__ == "__main__":
    main()
