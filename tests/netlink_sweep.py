"""Classic online scenarios that reach the kernel's online code a plain match in tests/netlink.py leaves unrun, each
on a NetLink line on this machine, and the checks that they still reach it:
    taunt           both sides press L, R, X, Y and Z in turn through the battle
    next-battle     both sides take VICTORY's "Next Battle?" and play a second match on the same call
    traditional     the waiter takes the NetLink page's Traditional link, and H2H lets a QuickLink call ring
    practice        the waiter practises while it waits, and H2H answers a call that comes during the practice battle
    practice-alone  the waiter practises with no call and loses, which runs the kernel's code for link_mode 1
Six minutes for all of them at once: like tests/netlink.py, every copy runs in real time.
    uv run tests/netlink_sweep.py [--video] [SCENARIO...]"""
import argparse
import concurrent.futures
import itertools
import os
import re
import socket
import sys
import time
from dataclasses import dataclass, field

import netlink
from saturnrecomp import build, learn
from bomberman import run
from bomberman.paths import BUILD

CLASSIC = run.GAME.classic
# On QuickLink's Wait: LEFT to Yes at the prompt to practise while waiting, then A.
PRACTICE = ["2950:LEFT", "2956:", "2980:A", "2986:"]
# The practice dialler starts this many seconds after the waiter, so its call comes during the practice battle.
PRACTICE_CALL = 60


@dataclass(frozen=True)
class Side:
    """One copy of the game in a scenario, and what its run has to show."""

    role: str
    presses: list[str]
    end: int
    # "MODULE ADDRESS" for each function the run has to reach, as coverage.txt names it.
    ran: tuple[str, ...] = ()
    unran: tuple[str, ...] = ()
    # Patterns the log has to match one after another, and ones it must not match anywhere.
    heard: tuple[str, ...] = ()
    unheard: tuple[str, ...] = ()
    # Seconds after the scenario starts.
    delay: float = 0
    shots: list[int] = field(default_factory=list)


def coverage(out: str) -> set[str]:
    """The functions `out`'s run reached, as "MODULE ADDRESS"."""
    with open(f"{out}/coverage.txt", encoding="utf-8") as f:
        return {f"{module} {address}" for module, address, _, reached in map(str.split, f) if reached == "1"}


def free_port() -> int:
    with socket.socket() as probe:
        probe.bind(("127.0.0.1", 0))
        return probe.getsockname()[1]


def lose(start: int, end: int) -> list[str]:
    """C, which drops a bomb the bomber then stands on, every 300 VBlanks, so the side loses each round."""
    return taps(start, "C", 300, end)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--video", action="store_true", help="write each side's video.mp4 beside its coverage")
    parser.add_argument("scenarios", nargs="*", metavar="SCENARIO", help=", ".join(SCENARIOS))
    options = parser.parse_args()
    names = options.scenarios or list(SCENARIOS)
    if unknown := [n for n in names if n not in SCENARIOS]:
        parser.error(f"no scenario {', '.join(unknown)}; there are {', '.join(SCENARIOS)}")
    build.ensure(run.GAME, False, log=lambda s: None)
    os.environ.update(SDL_VIDEO_DRIVER="offscreen", SDL_AUDIO_DRIVER="dummy")
    with concurrent.futures.ThreadPoolExecutor(len(names)) as ex:
        results = dict(zip(names, ex.map(lambda n: scenario(n, options.video), names)))
    for name, found in results.items():
        for p in found:
            print("FAIL    ", p)
        if not found:
            print("ok      ", name)
    sys.exit(1 if any(results.values()) else 0)


def merged(*lists: list[str]) -> list[str]:
    """Press lists as one, in VBlank order. A press sets the whole pad, so a release in one list releases every button."""
    return sorted((p for presses in lists for p in presses), key=lambda p: int(p.split(":")[0]))


def next_battle() -> list[Side]:
    end = 22000
    # Each cursor starts on No, so UP then A takes Yes.
    yes = ["11780:UP", "11786:", "11800:A", "11806:", "11900:UP", "11906:", "11920:A", "11926:"]
    second = ("KRNL 06059776", "KRNL 06068E10")
    return [Side("waiter", CLASSIC.first("wait") + press_on(6150, 11400) + yes + press_on(12750, end), end, ran=second),
            Side("dialer", CLASSIC.first("dial") + lose(6000, 11400) + yes + lose(12600, end), end, ran=second)]


def play(name: str, side: Side, modem: str, video: bool) -> list[str]:
    """Problems with `side`'s run as `name`."""
    time.sleep(side.delay)
    out = f"{BUILD}/test/netlink-sweep-{name}"
    found = netlink.args(out, modem, side.presses, side.end, side.shots)
    if video:
        found += ["--video", os.path.abspath(f"{out}/video.mp4")]
    log = learn.run(run.GAME, found, out, timeout=3000)
    return [f"{name}: {p}" for p in problems(side, log, out)]


def practice() -> list[Side]:
    # H2H answers in capitals, where the XBAND client sends "ata".
    answered = (r"modem: -> ATA$", r"CONNECT 28800", r"program start \d+: BOOT")
    return [Side("waiter", CLASSIC.first("wait") + PRACTICE, 16000, ran=("H2H 06004DFC",), heard=answered),
            Side("dialer", CLASSIC.first("dial") + lose(6000, 11000), 11000, delay=PRACTICE_CALL)]


def practice_alone() -> list[Side]:
    end = 14000
    presses = CLASSIC.first("wait") + PRACTICE + merged(taps(3500, "C", 300, end), press_on(3650, end))
    return [Side("waiter", presses, end, ran=("KRNL 0605A124",))]


def press_on(start: int, end: int) -> list[str]:
    """A every 300 VBlanks, which takes the winner through the screens between rounds."""
    return taps(start, "A", 300, end)


def problems(side: Side, log: str, out: str) -> list[str]:
    found = [line for line in log.splitlines() if "FATAL" in line or learn.EXITED in line]
    reached = coverage(out) if os.path.exists(f"{out}/coverage.txt") else set()
    found += [f"{f} did not run" for f in side.ran if f not in reached]
    found += [f"{f} ran" for f in side.unran if f in reached]
    at = 0
    for pattern in side.heard:
        m = re.compile(pattern, re.M).search(log, at)
        if not m:
            found.append(f"no {pattern!r} in the log after what came before it")
            break
        at = m.end()
    found += [f"the log has {pattern!r}" for pattern in side.unheard if re.search(pattern, log, re.M)]
    return found


def scenario(name: str, video: bool) -> list[str]:
    """Problems with the scenario `name`, whose waiter listens on a free port and whose dialler calls it."""
    port = free_port()
    modems = {"waiter": f"listen={port}", "dialer": f"dial=127.0.0.1:{port}"}
    sides = SCENARIOS[name]()
    with concurrent.futures.ThreadPoolExecutor(len(sides)) as ex:
        runs = [ex.submit(play, f"{name}-{s.role}", s, modems[s.role], video) for s in sides]
        return [p for r in runs for p in r.result()]


def taps(start: int, button: str, every: int, end: int, hold: int = 6) -> list[str]:
    return [p for v in range(start, end - 10, every) for p in (f"{v}:{button}", f"{v + hold}:")]


def taunt() -> list[Side]:
    end = 14000
    buttons = [p for v, b in zip(range(6080, 11400, 60), itertools.cycle("LRXYZ")) for p in (f"{v}:{b}", f"{v + 6}:")]
    effect = ("KRNL 06013C24", "KRNL 06051EBE")
    return [Side("waiter", CLASSIC.first("wait") + merged(press_on(6150, 11400), buttons), end, ran=effect),
            Side("dialer", CLASSIC.first("dial") + merged(lose(6000, 11400), buttons), end, ran=effect)]


def traditional() -> list[Side]:
    end = 16000
    # UP held 45 VBlanks, then A, takes the Traditional link. Then Start through the intro, and Battle Game.
    waiter = ["1500:UP", "1545:", "1565:A", "1571:", "5000:START", "5006:", "5700:START", "5706:", "6000:A", "6006:",
              "6300:DOWN", "6306:", "6420:A", "6426:"] + press_on(7000, end)
    return [Side("waiter", waiter, end, unran=("H2H 06003404",), heard=(r"<- RING",), unheard=(r"-> ATA", r"CONNECT")),
            Side("dialer", CLASSIC.first("dial") + lose(6000, end), end)]


SCENARIOS = {"taunt": taunt, "next-battle": next_battle, "traditional": traditional, "practice": practice,
             "practice-alone": practice_alone}

if __name__ == "__main__":
    main()
