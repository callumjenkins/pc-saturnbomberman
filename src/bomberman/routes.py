"""The scripted runs, as pad presses from power-on.

A press is one of the saturn executable's --input steps, "VBLANK:BUTTONS", and an empty BUTTONS
lets go. Menus are stepped by time, so a route only holds while the game takes the same time to
get there, which a deterministic run does."""
import os
from dataclasses import dataclass

from .paths import ROOT

# The title's held codes for each world (Sega Retro's hidden content), and the one for every item.
ITEMS = "L+R+A+UP+LEFT"
WORLDS = {
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


# The arenas of a normal-size battle, as the stage wheel names them; RIGHT turns it to the next.
# A wide battle, the 10-player size, has one arena, Field of Glory.
ARENAS = ("Path to Glory", "Soccer Stadium", "Jungle Trap", "Desert Twister", "Space Colony",
          "Bouncing Bomber", "Ninja House", "Factory Floor")
# The wheel's skies in the order UP steps through them with X+Y+Z held. Each sky after the first
# is a variant of every arena, with its own gimmicks.
SKIES = ("day", "night", "orange", "white")


def arena(n, sky="day"):
    """The single battle in arena N (from 1) under SKY, turned to on the stage wheel (up from about
    VBlank 6140) and picked with A. The wheel takes no UP before about 6400, and the match starts
    about 380 VBlanks after the pick."""
    turned = 6200 + 80 * (n - 1)
    presses = TO_BATTLE + taps(range(4400, 6111, 90), "A", 8) + taps(range(6200, turned, 80), "RIGHT", 8)
    k = SKIES.index(sky)
    pick = turned
    if k:
        ups = range(turned + 200, turned + 200 * (k + 1), 200)
        presses += (f"{turned + 40}:X+Y+Z",) + tuple(p for at in ups for p in (f"{at}:X+Y+Z+UP", f"{at + 8}:X+Y+Z"))
        pick = ups[-1] + 100
        presses += (f"{pick - 40}:",)
    return Route(f"a single battle in arena {n}, {ARENAS[n - 1]}{'' if not k else f', under the {sky} sky'}",
                 presses + taps((pick, pick + 90), "A", 8), pick + 600, f"{pick - 20},{pick + 600}")


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


# Normal Game's stages a world, its boss's included: clearing the last leads to the next world's first.
# A higher number loads, but reads the stage tables past their end.
STAGES = {1: 7, 2: 9, 3: 9, 4: 10, 5: 10}


def stage(world, number, items=False):
    """Stage WORLD-NUMBER as the game shows it (from 1), through Normal Game's start with the world and
    stage written over the ones it chose; START skips the opening movie. Play starts at about VBlank
    5620, or 5000 with every item (the title's held code), whose start comes sooner."""
    from .run import GAME
    if not 1 <= number <= STAGES.get(world, 0):
        raise ValueError(f"no stage {world}-{number}: " + ", ".join(f"{w}-1 to {w}-{n}" for w, n in STAGES.items()))
    value = f"{world - 1:02X}{number - 1:02X}"
    names = ("stage", "stage_2", "stage_3", "stage_saved")
    if items:
        presses, at = world_presses(ITEMS) + tap(4200, "START", 10), 3950
    else:
        presses, at = TO_NORMAL + tap(4200, "START", 10) + tap(4500, "START", 10), 4250
    return Route(f"stage {world}-{number}{' with every item' if items else ''}, from Normal Game with the stage select",
                 presses, 5700, "5700", writes=tuple(f"{at}:{GAME.symbols[n]:08X}={value}" for n in names))


def clear(world, number, items=False):
    """Stage WORLD-NUMBER cleared by the bot (bomberman bot), replayed from the presses it saved in
    inputs/clears/; the run ends a few seconds after its last press, on the next stage's start."""
    base = stage(world, number, items)
    presses = presses_file(f"clears/{world}-{number}{'-items' if items else ''}.txt")
    end = int(presses[-1].split(":")[0]) + 300
    return Route(f"stage {world}-{number} cleared by the bot", base.presses + presses, end, str(end),
                 invincible=True, writes=base.writes)


def attempt(world, number, items=False):
    """The bot's last run at stage WORLD-NUMBER, cleared or not, replayed from the presses it left in
    build/run/bot-WORLD-NUMBER/; the run ends a few seconds after its last press."""
    from .run import out_dir
    base = stage(world, number, items)
    presses = tuple(open(f"{out_dir(f'bot-{world}-{number}{tag(items)}')}/presses.txt").read().strip().split(","))
    end = int(presses[-1].split(":")[0]) + 300
    return Route(f"the bot's last run at stage {world}-{number}", base.presses + presses, end, str(end),
                 invincible=True, writes=base.writes)


def world_presses(held):
    return tap(1900, "START", 10) + (f"2850:{held}", f"3000:{held}+START", f"3010:{held}", "3060:") + \
        taps((3500, 3900), "START", 10)


def world(name):
    """The world's code held while "Press Start" shows, through START, then on to its first stage."""
    held = ITEMS if name == "items" else WORLDS[name]
    presses = tap(1900, "START", 10) + (f"2850:{held}", f"3000:{held}+START", f"3010:{held}", "3060:")
    about = "Normal Game with every item, from the title's held code" if name == "items" else \
        f"{name.capitalize()} world's first stage, from the title's held code"
    return Route(about,
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


# Stage 1-1 without invincibility: the bomber drops a bomb where it starts and stands in the blast,
# losing a life each time. Three lives, so the fourth ends the game, with its menu up from about 9640.
DEATHS = (5700, 6580, 7460, 8340)
GAME_OVER_MENU = 9644


def deaths(n):
    base = stage(1, 1)
    return base, base.presses + taps(DEATHS[:n], "C", 4)


def die():
    base, presses = deaths(1)
    return Route("stage 1-1, a life lost to the bomber's own bomb, and the stage restarted",
                 presses, 6500, "5860,6500", writes=base.writes)


def game_over():
    base, presses = deaths(4)
    return Route("stage 1-1's lives all lost, to the GAME OVER menu", presses, GAME_OVER_MENU + 60,
                 str(GAME_OVER_MENU + 60), writes=base.writes)


def continued():
    """CONTINUE, the menu's first choice, then START on the stage card."""
    base, presses = deaths(4)
    presses += tap(GAME_OVER_MENU, "C", 8) + taps((10000, 10150), "START", 8)
    return Route("GAME OVER, then CONTINUE: stage 1-1 again with three lives", presses, 10500, "9900,10500",
                 writes=base.writes)


def save():
    """SAVE GAME into slot 1 (the game writes BOMBERSS_01), QUIT to the title, then Normal Game's
    LOAD GAME, whose list shows slot 1 as STAGE 1-1, and slot 1 loaded and played. The run's saves
    last for the run alone, so it starts with every slot empty."""
    base, presses = deaths(4)
    m = GAME_OVER_MENU
    presses += tap(m, "DOWN", 8) + tap(m + 38, "C", 8) + taps((m + 136, m + 174, m + 212), "UP", 8)
    presses += tap(m + 250, "C", 8) + taps((10132, 10170), "DOWN", 8) + tap(10208, "C", 8)
    presses += taps((11446, 11604, 11762), "START", 8) + tap(11860, "DOWN", 8) + tap(11908, "START", 8)
    presses += tap(12016, "DOWN", 8) + tap(12064, "C", 8) + taps((12172, 12320), "START", 8)
    return Route("GAME OVER, SAVE GAME in slot 1, QUIT, then LOAD GAME from the title and slot 1 played",
                 presses, 12700, "9900,12010,12700", writes=base.writes)


def paused():
    """START pauses stage 1-1 at 5:47, with PAUSE over the field and the clock held, and START again
    goes on."""
    base = stage(1, 1)
    return Route("stage 1-1 paused and resumed", base.presses + taps((5900, 6148), "START", 8), 6400,
                 "6028,6140,6400", writes=base.writes)


def battle_round():
    """The single battle played to its end, pad 1 dropping one bomb at the start: sudden death,
    then the 3 WIN MATCH results with the round's winner, and C on to round two, whose HUD counts
    that win."""
    return Route("a single battle's round played out, its results, then round two",
                 single().presses + tap(6500, "C", 4) + tap(16100, "C", 8), 16400, "16090,16400")


def tag(items):
    return "-items" if items else ""


ROUTES = {"normal": normal, "single": single, "battle": battle,
          "items": lambda: world("items"),
          **{name: (lambda name=name: world(name)) for name in WORLDS},
          "cactus": cactus, "slot": slot, "yuna": yuna,
          "die": die, "game-over": game_over, "continue": continued, "save": save,
          "pause": paused, "battle-round": battle_round,
          **{f"arena-{n}": (lambda n=n: arena(n)) for n in range(2, len(ARENAS) + 1)},
          **{f"arena-{n}-{sky}": (lambda n=n, sky=sky: arena(n, sky)) for n in range(1, len(ARENAS) + 1) for sky in SKIES[1:]}}
