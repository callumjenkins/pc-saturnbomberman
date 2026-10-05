"""The scripted runs, as pad presses from power-on.

A press is one of the saturn executable's --input steps, "VBLANK:BUTTONS", and an empty BUTTONS
lets go. Menus are stepped by time, so a route only holds while the game takes the same time to
get there, which a deterministic run does."""
import os
from dataclasses import dataclass

from .paths import ROOT

# The title's held codes for each world (Sega Retro's hidden content).
WORLDS = {
    "hige": "L+R+A+UP+LEFT",
    "mage": "L+R+B+UP+LEFT",
    "gunman": "L+R+C+UP+RIGHT",
    "tyranno": "L+R+X+UP+RIGHT",
    "mujoe": "L+R+Y+UP",
}


@dataclass(frozen=True)
class Route:
    about: str
    presses: tuple[str, ...]
    vblanks: int
    shots: str
    args: tuple[str, ...] = ()                   # more of saturn's arguments, such as --multitap
    invincible: bool = False
    writes: tuple[str, ...] = ()                 # memory set on the way, as saturn's --write: "VBLANK:ADDR=HEX"


def tap(at, buttons, held):
    return (f"{at}:{buttons}", f"{at + held}:")


def taps(times, buttons, held):
    return tuple(p for at in times for p in tap(at, buttons, held))


def presses_file(name):
    return tuple(open(os.path.join(ROOT, "inputs", name)).read().strip().split(","))


# START through the title, the intro and the mode select, to Normal mode's story
TO_NORMAL = taps((1900, 2500, 3000, 3400), "START", 10)
# ... and from the mode select down to Battle
TO_BATTLE = TO_NORMAL + tap(3700, "DOWN", 8) + tap(3760, "START", 10)


def normal():
    return Route("the title, the story intro and stage 1",
                 TO_NORMAL + taps(range(4200, 8701, 300), "START", 10), 9000, "4500,6300,8100,9000")


def single():
    """A battle on one pad: A through players, rules, character select and stage (READY at about
    6300, GO at 6400)."""
    return Route("a single battle on one pad, through to the match",
                 TO_BATTLE + taps(range(4400, 6301, 90), "A", 8), 8400, "6500,8400")


def battle():
    """Ten players on two multitaps: pads 2 to 10 each press A to join."""
    presses = TO_BATTLE + taps((4250, 4600), "A", 8) + tap(4850, "RIGHT", 8) + tap(4900, "A", 8)
    presses += taps(range(5050, 5691, 80), "A", 8)
    at = 6450
    for pad in range(2, 11):
        presses += (f"{at}:{pad}.A", f"{at + 8}:{pad}.")
        at += 70
    presses += taps(range(at, at + 1201, 90), "A", 8)
    return Route("the 10-player battle on two multitaps", presses, 8880, "7700,8880", args=("--multitap", "2"))


def yuna(start=4200, end=4260):
    """L+R held on Battle's "Which Mode?" screen (up from about 4100 to 5900) from `start` to `end`,
    then A through to character select. A hold of 60 VBlanks or more adds Yuna and Manto."""
    hold = (f"{start}:L+R", f"{end}:") if end else ()
    return Route("Yuna and Manto unlocked, at character select",
                 TO_BATTLE + hold + taps(range(5900, 7001, 90), "A", 8), 6900, "6900")


# Normal Game's stages a world. A higher number loads, but reads the stage tables past their end.
STAGES = {1: 7, 2: 10, 3: 10, 4: 10, 5: 10}


def stage(world, number):
    """Stage WORLD-NUMBER as the game shows it (from 1), through Normal Game's start with the world and
    stage written over the ones it chose. START skips the opening movie, and play starts at about
    VBlank 5620."""
    from .run import GAME
    if not 1 <= number <= STAGES.get(world, 0):
        raise ValueError(f"no stage {world}-{number}: " + ", ".join(f"{w}-1 to {w}-{n}" for w, n in STAGES.items()))
    value = f"{world - 1:02X}{number - 1:02X}"
    names = ("stage", "stage_2", "stage_3", "stage_saved")
    return Route(f"stage {world}-{number}, from Normal Game with the stage select",
                 TO_NORMAL + tap(4200, "START", 10) + tap(4500, "START", 10), 5700, "5700",
                 writes=tuple(f"4250:{GAME.symbols[n]:08X}={value}" for n in names))


def clear(world, number):
    """Stage WORLD-NUMBER cleared by the bot (bomberman bot), replayed from the presses it saved in
    inputs/clears/; the run ends a few seconds after its last press, on the next stage's start."""
    base = stage(world, number)
    presses = presses_file(f"clears/{world}-{number}.txt")
    end = int(presses[-1].split(":")[0]) + 300
    return Route(f"stage {world}-{number} cleared by the bot", base.presses + presses, end, str(end),
                 invincible=True, writes=base.writes)


def attempt(world, number):
    """The bot's last run at stage WORLD-NUMBER, cleared or not, replayed from the presses it left in
    build/run/bot-WORLD-NUMBER/; the run ends a few seconds after its last press."""
    from .run import out_dir
    base = stage(world, number)
    presses = tuple(open(f"{out_dir(f'bot-{world}-{number}')}/presses.txt").read().strip().split(","))
    end = int(presses[-1].split(":")[0]) + 300
    return Route(f"the bot's last run at stage {world}-{number}", base.presses + presses, end, str(end),
                 invincible=True, writes=base.writes)


def world(name):
    """The world's code held while "Press Start" shows, through START, then on to its first stage."""
    held = WORLDS[name]
    presses = tap(1900, "START", 10) + (f"2850:{held}", f"3000:{held}+START", f"3010:{held}", "3060:")
    return Route(f"{name.capitalize()} world's first stage, from the title's held code",
                 presses + taps((3500, 3900), "START", 10), 6000, "4800,6000")


def code(keys, hold="", at=2800):
    """A title-screen code, then Normal mode. `keys` are pressed in turn, 6 VBlanks each, with
    `hold` held under all of them."""
    presses = tap(1900, "START", 10)
    for key in keys.split(","):
        presses += (f"{at}:{hold + '+' if hold else ''}{key}", f"{at + 6}:{hold}")
        at += 15
    presses += (f"{at + 10}:",)
    presses += taps((3000, 3500, 3900), "START", 10) + taps(range(4700, 9201, 300), "START", 10)
    return Route(f"the title code {keys}, then Normal mode", presses, 9000, "4500,6300,8100,9000")


def cactus():
    """Gunman world 3-1, bombing the sleeping cactus on all four sides; it is a slot machine from
    about VBlank 6200."""
    return Route("Gunman world 3-1 with the cactus turned into the slot machine",
                 world("gunman").presses + presses_file("cactus-presses.txt"), 6300, "6200,6300",
                 invincible=True)


def slot():
    """The cactus route, then the slot machine played to a win: a remote bomb under each reel's
    button (the lobe below it, bombed from row 12), set off when that reel will stop on fire. Three
    fires at about VBlank 6600, then a Fire Up parachutes down to (9,12) and pad 1 picks it up at
    7106."""
    return Route("the slot machine won: three fires and the Fire Up picked up",
                 world("gunman").presses + presses_file("slot-win-presses.txt"), 7200, "6700,7090,7106,7200",
                 invincible=True)


ROUTES = {"normal": normal, "single": single, "battle": battle,
          **{name: (lambda name=name: world(name)) for name in WORLDS},
          "cactus": cactus, "slot": slot, "yuna": yuna}
