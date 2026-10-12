"""Two copies of the game play each other over a NetLink line on this machine: a call, a match, the
reboot back to the XBAND client, then a rematch and its reboot. Nine minutes: it runs in real time.
    uv run tests/netlink.py

Both copies run at real-time pace, as two consoles do. Unpaced, one can get far enough ahead to hang up
and redial before the other has chosen Wait, which no two players could do. The checks are what each
side's log holds and what its screen shows once it is back."""
import concurrent.futures
import os
import re
import socket
import sys

from PIL import Image, ImageStat
from saturnrecomp import build, learn
from bomberman import run
from bomberman.paths import BUILD, cue

# Into the XBAND client's QuickLink menu, past its title screen.
TO_MENU = ["1500:UP", "1530:", "1550:A", "1556:", "2300:A", "2306:"]
WAIT = ["2500:RIGHT", "2506:", "2530:A", "2536:"]
# Dial, type "1" on the keyboard, dial it.
DIAL = ["2500:A", "2506:", *(p for k in range(12) for p in (f"{2700 + 14 * k}:LEFT", f"{2706 + 14 * k}:")),
        "2868:A", "2874:", *(p for k in range(12) for p in (f"{2882 + 14 * k}:RIGHT", f"{2888 + 14 * k}:")),
        *(p for k in range(3) for p in (f"{3050 + 14 * k}:DOWN", f"{3056 + 14 * k}:")), "3112:A", "3118:"]
# Both sides are back on the XBAND title by then; A opens the menu again, and the first call's presses
# make the second.
AGAIN = 14200
END = 31000
BACK = [16400, 30900]


def later(presses, by):
    return [f"{int(v) + by}:{b}" for v, b in (p.split(":") for p in presses)]


def side(name, modem, presses):
    out = f"{BUILD}/test/netlink-{name}"
    # In a window, offscreen, as frames.py's controllers check runs: only a window is paced.
    args = ["--cue", cue(), "--settings", "-", "--save", "-", "--vblanks", str(END), "--modem", modem,
            "--shot", ",".join(map(str, BACK)), "--input", ",".join(presses)]
    return out, learn.run(run.GAME, args, out, timeout=3000)


def problems(name, out, log):
    found = [line for line in log.splitlines() if "FATAL" in line]
    if len(re.findall(r"CONNECT 28800", log)) < 2:
        found.append("fewer than two calls connected")
    starts = re.findall(r"program start \d+: (\w+)", log)
    if starts.count("KRNL") < 2:
        found.append(f"KRNL started {starts.count('KRNL')} times, not twice")
    if starts[-4:] != ["KRNL", "BOOT", "TRAMP", "XS"]:
        found.append(f"the last program starts are {starts[-4:]}, not KRNL's reboot to XS")
    for v in BACK:
        shot = f"{out}/shot-{v}.png"
        # The XBAND title is dark grey marble; VDP2 left as a match had it shows it pink and yellow.
        if not os.path.exists(shot) or sum(ImageStat.Stat(Image.open(shot).convert("L")).mean) > 90:
            found.append(f"VBlank {v} is not the XBAND title")
    return [f"{name}: {p}" for p in found]


def main():
    build.ensure(run.GAME, False, log=lambda s: None)
    os.environ.update(SDL_VIDEO_DRIVER="offscreen", SDL_AUDIO_DRIVER="dummy")
    with socket.socket() as probe:
        probe.bind(("127.0.0.1", 0))
        port = probe.getsockname()[1]
    waiter = TO_MENU + WAIT + ["16500:A", "16506:"] + later(WAIT, AGAIN)
    dialer = TO_MENU + DIAL + ["16500:A", "16506:"] + later(DIAL, AGAIN)
    with concurrent.futures.ThreadPoolExecutor(2) as ex:
        w = ex.submit(side, "waiter", f"listen={port}", waiter)
        d = ex.submit(side, "dialer", f"dial=127.0.0.1:{port}", dialer)
        found = problems("waiter", *w.result()) + problems("dialer", *d.result())
    for p in found:
        print("FAIL    ", p)
    if not found:
        print("ok       two matches over a NetLink line, each back to the XBAND title")
    sys.exit(1 if found else 0)


if __name__ == "__main__":
    main()
