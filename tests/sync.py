"""Players on several machines in one game: copies of the game in a room on the playtest Worker, run on this machine
under wrangler dev, each with --sync, so every VBlank's pads are the same on all of them.
    uv run tests/sync.py
- two copies play battle-round, a pad each, and show the same frames as one copy given both pads' presses DELAY
  frames later, which is when a press in a synced game applies;
- of three copies, one is killed during the battle, and the other two play on together;
- a copy whose work RAM is written to is reported out of step, by both;
- a copy that joins once the game has started is told so;
- a copy whose network goes mid-battle comes back, and the two still show the reference's frames;
- a room's maker in a window starts the game with Start once another player is in;
- a copy that joins plays with the maker's saves, and both keep them beside the run for a replay.
The copies run headless, so unpaced, but for the maker pressing Start: only the lockstep keeps them together."""
import os
import re
import shutil
import struct
import subprocess
import sys
import time

import netlink
from saturnrecomp import build, learn
from saturnrecomp.config import later
from saturnrecomp.playtest.local_worker import LocalWorker, local_worker
from bomberman import routes, run
from bomberman.paths import BUILD

DELAY = 3
ROUTE = routes.battle_round()
SHOTS = "6500,8400,13600,16400"
# The second player's presses through the battle: C to drop a bomb, then RIGHT, over and over.
SECOND = [p for v in range(6500, 9000, 120) for p in (f"{v}:C", f"{v + 8}:", f"{v + 60}:RIGHT", f"{v + 80}:")]
# A byte of work RAM written on one copy every VBlank, which the other's never holds.
STRAY = "KRNL:002FFFF0=A5"


def alone() -> str:
    """The reference: one copy with both pads' presses, DELAY frames late, as the synced copies apply them."""
    out = f"{BUILD}/test/sync-alone"
    presses = later(list(ROUTE.presses), DELAY) + later([p.replace(":", ":2.", 1) for p in SECOND], DELAY)
    args = run.saturn_args(ROUTE, shots=SHOTS)
    args[args.index("--input") + 1] = ",".join(presses)
    learn.run(run.GAME, args, out, timeout=1200)
    return out


def finished(game: tuple[str, subprocess.Popen]) -> tuple[str, str]:
    """`game`'s output folder and its log once it has stopped."""
    out, process = game
    return out, netlink.finished(out, process, timeout=1200)


def problems(name: str, out: str, log: str, starts: bool = True) -> list[str]:
    found = [line for line in log.splitlines() if "FATAL" in line or learn.EXITED in line]
    if starts and "sync: the game starts" not in log:
        found.append("the game never started")
    if "stopped (VBlank limit)" not in log:
        found.append("it did not play to its last VBlank")
    return [f"{name}: {p}" for p in found]


def same_shots(names: list[str], outs: list[str], shots: str = SHOTS) -> list[str]:
    found = []
    for v in shots.split(","):
        pictures = [f"{o}/shot-{v}.png" for o in outs]
        if not all(map(os.path.exists, pictures)):
            found.append(f"VBlank {v}: a picture is missing")
        elif len({open(p, "rb").read() for p in pictures}) != 1:
            found.append(f"VBlank {v} differs between {' and '.join(names)}")
    return found


def start(name: str, session: str, token: str, presses: list[str], more: tuple[str, ...] = (),
          vblanks: int = ROUTE.vblanks, window: bool = False) -> tuple[str, subprocess.Popen]:
    """A synced copy of the game in the room at `session`, as tester `token`, pressing its own pad 1 as `presses`.
    In a `window`, offscreen, its controllers and the room's card are the player's, and --input is left out."""
    out = f"{BUILD}/test/sync-{name}"
    shutil.rmtree(out, ignore_errors=True)
    os.makedirs(out)
    args = run.saturn_args(ROUTE, vblanks=vblanks, shots=SHOTS)
    args[args.index("--input") + 1] = ",".join(presses) or "0:"
    env = {**os.environ, "SATURN_PLAYTEST_TOKEN": token}
    if window:
        at = args.index("--input")
        args = [a for i, a in enumerate(args) if a != "--headless" and i not in (at, at + 1)] + ["--settings", "-"]
        env.update(SDL_VIDEO_DRIVER="offscreen", SDL_AUDIO_DRIVER="dummy")
    command = [run.GAME.saturn, "--out", out, *args, "--session", session, "--sync-delay", str(DELAY), *more]
    with open(f"{out}/log.txt", "w") as log:
        process = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT, env=env)
    return out, process


def started(game: tuple[str, subprocess.Popen], timeout: float = 120) -> bool:
    out, process = game
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline and process.poll() is None:
        with open(f"{out}/log.txt") as f:
            if "sync: the game starts" in f.read():
                return True
        time.sleep(0.25)
    return False


def two(worker: LocalWorker, reference: str) -> list[str]:
    """Two copies, a pad each, and a third that joins too late."""
    tokens = [worker.invite(n) for n in ("ann", "bob", "cat")]
    a = start("two-ann", worker.room(), tokens[0], list(ROUTE.presses), ("--sync", "2"))
    code = netlink.room_code(*a)
    if not code:
        a[1].kill()
        return ["two: the first copy made no room"]
    b = start("two-bob", worker.room(code), tokens[1], SECOND, ("--sync", "0"))
    late = None
    if started(a):
        late = start("two-late", worker.room(code), tokens[2], [], ("--sync", "0"), vblanks=600)
    found = problems("ann", *finished(a)) + problems("bob", *finished(b))
    found += same_shots(["ann", "bob", "one copy alone"], [a[0], b[0], reference])
    if late:
        out, log = finished(late)
        if "sync: the game had already started" not in log:
            found.append("late: it was not told the game had started")
    else:
        found.append("two: the game never started")
    return found


def three_one_killed(worker: LocalWorker) -> list[str]:
    tokens = [worker.invite(n) for n in ("dan", "eve", "fay")]
    a = start("three-dan", worker.room(), tokens[0], list(ROUTE.presses), ("--sync", "3"))
    code = netlink.room_code(*a)
    if not code:
        a[1].kill()
        return ["three: the first copy made no room"]
    b = start("three-eve", worker.room(code), tokens[1], SECOND, ("--sync", "0"))
    c = start("three-fay", worker.room(code), tokens[2], [], ("--sync", "0"))
    if started(c):
        time.sleep(10)
    c[1].kill()
    found = problems("dan", *(dan := finished(a))) + problems("eve", *(eve := finished(b)))
    found += same_shots(["dan", "eve"], [a[0], b[0]], "13600,16400")
    if not all(re.search(r"^.*sync: \w+ (left the room|its connection failed|sent no pads)", log, re.M) for _, log in (dan, eve)):
        found.append("three: a copy did not note that fay left")
    return found


def stray_write(worker: LocalWorker) -> list[str]:
    tokens = [worker.invite(n) for n in ("gus", "hal")]
    a = start("stray-gus", worker.room(), tokens[0], list(ROUTE.presses), ("--sync", "2"), vblanks=4000)
    code = netlink.room_code(*a)
    if not code:
        a[1].kill()
        return ["stray: the first copy made no room"]
    b = start("stray-hal", worker.room(code), tokens[1], [], ("--sync", "0", "--cheat", STRAY), vblanks=4000)
    found = []
    for name, game in (("gus", a), ("hal", b)):
        out, log = finished(game)
        if "fell out of step" not in log:
            found.append(f"stray {name}: no report that the machines fell out of step")
    return found


def severed(worker: LocalWorker, reference: str) -> list[str]:
    """Two copies, the second losing its network in the battle, as a phone that changes networks does."""
    tokens = [worker.invite(n) for n in ("kay", "lou")]
    a = start("severed-kay", worker.room(), tokens[0], list(ROUTE.presses), ("--sync", "2"))
    code = netlink.room_code(*a)
    if not code:
        a[1].kill()
        return ["severed: the first copy made no room"]
    b = start("severed-lou", worker.room(code), tokens[1], SECOND, ("--sync", "0", "--session-sever-at", "7000"))
    kay, lou = finished(a), finished(b)
    found = problems("kay", *kay) + problems("lou", *lou)
    found += same_shots(["kay", "lou", "one copy alone"], [a[0], b[0], reference])
    if "session: the network goes" not in lou[1] or lou[1].count("session: connected to") < 2:
        found.append("severed: lou's network did not go and come back")
    for name, (_, log) in (("kay", kay), ("lou", lou)):
        # The first to reach its last VBlank leaves the room, which the other notes as it finishes.
        if re.search(r"sync: \w+ (its connection failed|sent no pads)", log):
            found.append(f"severed {name}: the other copy was lost")
    return found


def started_by_start(worker: LocalWorker) -> list[str]:
    """The maker's Start, held from the first VBlank, which the room's card takes once a second player is in."""
    tokens = [worker.invite(n) for n in ("ida", "jo")]
    a = start("start-ida", worker.room(), tokens[0], [], ("--sync", "0", "--virtual-input", "1:START,10:"), 600, True)
    code = netlink.room_code(*a)
    if not code:
        a[1].kill()
        return ["start: the maker made no room"]
    time.sleep(3)
    b = start("start-jo", worker.room(code), tokens[1], [], ("--sync", "0"), 600)
    found = []
    for name, game in (("ida", a), ("jo", b)):
        out, log = finished(game)
        if not re.search(r"sync: the game starts at VBlank \d+ with 2 players", log):
            found.append(f"start {name}: the game did not start with two players")
    return found


def makers_saves(worker: LocalWorker) -> list[str]:
    tokens = [worker.invite(n) for n in ("max", "ned")]
    saves = f"{BUILD}/test/sync-makers-saves.bin"
    data = bytes(range(64))
    with open(saves, "wb") as f:
        f.write(b"SYNC_TEST".ljust(12, b"\0") + b"A TEST".ljust(11, b"\0") + b"\0" + struct.pack("<II", 0, len(data)) + data)
    a = start("saves-max", worker.room(), tokens[0], [], ("--sync", "2", "--save", saves), 600)
    code = netlink.room_code(*a)
    if not code:
        a[1].kill()
        return ["saves: the maker made no room"]
    b = start("saves-ned", worker.room(code), tokens[1], [], ("--sync", "0"), 600)
    found = []
    for name, game in (("max", a), ("ned", b)):
        out, log = finished(game)
        found += problems(f"saves {name}", out, log)
        kept = f"{out}/backup-at-start.bin"
        if not os.path.exists(kept) or open(kept, "rb").read() != open(saves, "rb").read():
            found.append(f"saves {name}: backup-at-start.bin is not the maker's saves")
        if name == "ned" and "backup memory: 1 save from the room's creator" not in log:
            found.append("saves ned: it did not play with the maker's saves")
    return found


def main() -> None:
    build.ensure(run.GAME, False, log=lambda s: None)
    reference = alone()
    found = []
    with local_worker(f"{BUILD}/test/sync-worker", f"{BUILD}/test/sync-worker.log") as worker:
        for check in (lambda: two(worker, reference), lambda: three_one_killed(worker), lambda: stray_write(worker),
                      lambda: severed(worker, reference), lambda: started_by_start(worker),
                      lambda: makers_saves(worker)):
            found += check()
    for p in found:
        print("FAIL    ", p)
    if not found:
        print("ok       two, three and a stray write: the same frames on every synced copy, a lost copy left behind, "
              "and a copy out of step reported; a copy whose network went came back; a game started with the "
              "maker's Start; and the maker's saves played by both")
    sys.exit(1 if found else 0)


if __name__ == "__main__":
    main()
