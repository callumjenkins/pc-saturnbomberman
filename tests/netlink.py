"""Two copies of the game play each other over a NetLink line on this machine: a call, a match, the
reboot back to the XBAND client, then a rematch and its reboot. Beside them, a second pair whose dialler
stops mid-match: the waiter holds the match while it waits for a call back, then returns to the XBAND
client. Nine minutes: it runs in real time.
    uv run tests/netlink.py [--room [--saved]]

With --room, one pair calls and rematches through a room on the playtest Worker, run on this machine
under wrangler dev: the waiter makes the room, and the dialler joins it by its code. Each steers to its
call with --steer, as a player's launcher has it do, and takes the offer of a rematch with a virtual
gamepad's Start. Each side is then replayed from its presses and what its line heard, and has to show the
same pictures and start the same programs at the same moments. With --saved, both start from a save the XBAND
client has already made, as a returning player's is, so after each match the client opens its chat on the call.

Both copies run at real-time pace, as two consoles do. Unpaced, one can get far enough ahead to hang up
and redial before the other has chosen Wait, which no two players could do. The checks are what each
side's log holds and what its screen shows once it is back."""
import argparse
import concurrent.futures
import os
import re
import shutil
import socket
import subprocess
import sys
import time

from PIL import Image, ImageStat
from saturnrecomp import build, learn
from saturnrecomp.config import later
from saturnrecomp.playtest.local_worker import local_worker
from bomberman import run
from bomberman.paths import BUILD, cue

CLASSIC = run.GAME.classic
# Both sides are back on the XBAND title by then, and the client's presses make the second call.
AGAIN = 14200
END = 31000
BACK = [16400, 30900]
# Through a room: when each side takes the offer of a rematch.
TAKE_REMATCH = 15000
ROOM_BACK = [TAKE_REMATCH - 100, 30900]
# With the client's save, the rematch waits for its chat to end, so the second match ends later.
SAVED_END = 34000
SAVED_BACK = [TAKE_REMATCH - 100, SAVED_END - 100]
# The dropped call: the dialler stops in the match, and the waiter's H2H waits 4500 ticks for it to call back.
DROP = 9000
DROP_END = 16000


def args(out, modem, presses, end=END, shots=BACK):
    # In a window, offscreen, as frames.py's controllers check runs: only a window is paced.
    found = ["--cue", cue(), "--settings", "-", "--save", "-", "--vblanks", str(end), "--modem", modem,
             "--input", ",".join(presses), "--coverage", f"{out}/coverage.txt"]
    if shots:
        found += ["--shot", ",".join(map(str, shots))]
    return found


def finished(out, game, timeout=3000):
    """`game`'s log once it exits, ending in learn.run's EXITED line if it failed."""
    try:
        game.wait(timeout)
    except subprocess.TimeoutExpired:
        game.kill()
        game.wait()
    with open(f"{out}/log.txt") as f:
        log = f.read()
    return log + (f"{learn.EXITED} {game.returncode}\n" if game.returncode else "")


def room_code(out, game, timeout=60):
    """The code of the room `game` made, from its log."""
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline and game.poll() is None:
        with open(f"{out}/log.txt") as f:
            if m := re.search(r"session: in room ([A-Z]{4})", f.read()):
                return m.group(1)
        time.sleep(0.25)
    return None


def client_save():
    """A save the XBAND client has made, from a run to just after the client first starts. The NetLink loader that
    offers the client appears only with a modem fitted."""
    out = f"{BUILD}/test/netlink-save"
    learn.run(run.GAME, ["--cue", cue(), "--headless", "--settings", "-", "--save", f"{out}/backup.bin",
                         "--modem", "line", "--vblanks", str(CLASSIC.starts + 350), "--input", ",".join(CLASSIC.boot)],
              out, timeout=600)
    return f"{out}/backup.bin"


def save_copy(save, to):
    """saturn's --save: a copy of `save` at `to`, which the run may change, or none."""
    if not save:
        return "-"
    return shutil.copy(save, to)


def room_pair(save):
    """The waiter and dialer through a room on a local Worker, each `(out, log)`, starting from `save` if given."""
    with local_worker(f"{BUILD}/test/netlink-worker", f"{BUILD}/test/netlink-worker.log") as worker:
        tokens = [worker.invite("waiter"), worker.invite("dialer")]
        w = room_side("room-waiter", worker.room(), tokens[0], "wait", save)
        code = room_code(*w)
        if not code:
            w[1].kill()
            return (w[0], finished(*w)), (w[0], "FATAL: the waiter made no room\n")
        d = room_side("room-dialer", worker.room(code), tokens[1], "dial", save)
        return (w[0], finished(*w)), (d[0], finished(*d))


def room_side(name, session, token, role, save):
    """A copy of the game in the room at `session` as tester `token`, steered to its call as `role`, "wait" or
    "dial", and to the rematch's: `(out, process)`."""
    out = f"{BUILD}/test/netlink-{name}"
    shutil.rmtree(out, ignore_errors=True)
    os.makedirs(out)
    end, back = (SAVED_END, SAVED_BACK) if save else (END, ROOM_BACK)
    command = [run.GAME.saturn, "--out", out, "--cue", cue(), "--settings", "-", "--save", save_copy(save, f"{out}/backup.bin"),
               "--vblanks", str(end), "--modem", "session", "--session", session, *CLASSIC.steer(role),
               "--virtual-input", f"{TAKE_REMATCH}:START,{TAKE_REMATCH + 6}:",
               "--shot", ",".join(map(str, back)), "--coverage", f"{out}/coverage.txt",
               "--record-input", f"{out}/input.txt"]
    with open(f"{out}/log.txt", "w") as log:
        game = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT,
                                env={**os.environ, "SATURN_PLAYTEST_TOKEN": token})
    return out, game


def replayed(name, out, save):
    """Problems with `out`'s replay from its presses and line: whatever differs from the match itself."""
    again = f"{out}-replay"
    end, back = (SAVED_END, SAVED_BACK) if save else (END, ROOM_BACK)
    log = learn.run(run.GAME, ["--cue", cue(), "--headless", "--save", save_copy(save, f"{out}/replay-backup.bin"), "--vblanks", str(end),
                               "--modem", "session", "--line-in", f"{out}/line.txt", "--input", f"@{out}/input.txt",
                               "--shot", ",".join(map(str, back))], again, timeout=3000)
    found = [line for line in log.splitlines() if "FATAL" in line]
    starts = re.compile(r"^\[\s*([\d.]+) M\] program start .*$", re.M)
    with open(f"{out}/log.txt") as f:
        if starts.findall(f.read()) != starts.findall(log):
            found.append("its program starts differ from the match's")
    for v in back:
        shots = [f"{d}/shot-{v}.png" for d in (out, again)]
        if not all(map(os.path.exists, shots)) or len({open(p, "rb").read() for p in shots}) != 1:
            found.append(f"VBlank {v} differs from the match's")
    return [f"{name} replay: {p}" for p in found]


def side(name, modem, presses, end=END, shots=BACK):
    out = f"{BUILD}/test/netlink-{name}"
    return out, learn.run(run.GAME, args(out, modem, presses, end, shots), out, timeout=3000)


def problems(name, out, log, calls=2, back=BACK):
    found = [line for line in log.splitlines() if "FATAL" in line]
    if len(re.findall(r"CONNECT 28800", log)) < calls:
        found.append(f"fewer than {calls} calls connected")
    starts = re.findall(r"program start \d+: (\w+)", log)
    if starts.count("KRNL") < calls:
        found.append(f"KRNL started {starts.count('KRNL')} times, not {calls}")
    if back and starts[-4:] != ["KRNL", "BOOT", "TRAMP", "XS"]:
        found.append(f"the last program starts are {starts[-4:]}, not KRNL's reboot to XS")
    for v in back:
        shot = f"{out}/shot-{v}.png"
        # The XBAND title is dark grey marble; VDP2 left as a match had it shows it pink and yellow.
        if not os.path.exists(shot) or sum(ImageStat.Stat(Image.open(shot).convert("L")).mean) > 90:
            found.append(f"VBlank {v} is not back in the XBAND client")
    return [f"{name}: {p}" for p in found]


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--room", action="store_true", help="call through a room on a local playtest Worker")
    parser.add_argument("--saved", action="store_true", help="with --room: both sides start from the XBAND client's save")
    options = parser.parse_args()
    room = options.room
    build.ensure(run.GAME, False, log=lambda s: None)
    os.environ.update(SDL_VIDEO_DRIVER="offscreen", SDL_AUDIO_DRIVER="dummy")
    if room:
        save = client_save() if options.saved else None
        back = SAVED_BACK if save else ROOM_BACK
        w, d = room_pair(save)
        found = problems("room-waiter", *w, back=back) + problems("room-dialer", *d, back=back)
        found += replayed("room-waiter", w[0], save) + replayed("room-dialer", d[0], save)
        for p in found:
            print("FAIL    ", p)
        if not found:
            print("ok       two matches through a room, each back to the XBAND client, and each side's replay the same")
        sys.exit(1 if found else 0)
    rematch = AGAIN + CLASSIC.starts
    waiter = CLASSIC.first("wait") + later(CLASSIC.wait, rematch)
    dialer = CLASSIC.first("dial") + later(CLASSIC.dial, rematch)
    ports = []
    for _ in range(2):
        with socket.socket() as probe:
            probe.bind(("127.0.0.1", 0))
            ports.append(probe.getsockname()[1])
    with concurrent.futures.ThreadPoolExecutor(4) as ex:
        w = ex.submit(side, "waiter", f"listen={ports[0]}", waiter)
        d = ex.submit(side, "dialer", f"dial=127.0.0.1:{ports[0]}", dialer)
        dw = ex.submit(side, "drop-waiter", f"listen={ports[1]}", CLASSIC.first("wait"), DROP_END, [DROP_END - 100])
        dd = ex.submit(side, "drop-dialer", f"dial=127.0.0.1:{ports[1]}", CLASSIC.first("dial"), DROP, [])
        rematch = problems("waiter", *w.result()) + problems("dialer", *d.result())
        drop = problems("drop-waiter", *dw.result(), calls=1, back=[DROP_END - 100])
        drop += problems("drop-dialer", *dd.result(), calls=1, back=[])
    for p in rematch + drop:
        print("FAIL    ", p)
    if not rematch:
        print("ok       two matches over a NetLink line, each back to the XBAND title")
    if not drop:
        print("ok       a call dropped mid-match: the other side waits for it, then goes back to the XBAND title")
    sys.exit(1 if rematch or drop else 0)


if __name__ == "__main__":
    main()
