"""The scripted runs, as pad presses from power-on.

A press is one of the saturn executable's --input steps, "VBLANK:BUTTONS", and an empty BUTTONS
lets go. Menus are stepped by time, so a route only holds while the game takes the same time to
get there, which a deterministic run does."""
import dataclasses
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
# ... or two down to Master Game, whose temple intro leads to its first floor at about VBlank 6600
TO_MASTER = TO_NORMAL + taps((3700, 3760), "DOWN", 8) + tap(3820, "START", 10)


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


# The rules screen's rows, top to bottom, each stepped on by RIGHT: wins to take the match (3, from
# 1 to 5), minutes a round (3, from 1 to 5), then on or off: positions shuffled each round, sudden
# death until one is left, Devil items, Mad Bomber (the fallen bomb from the sidelines), and a
# bonus game between rounds.
RULES = ("battles", "time", "shuffle", "no_draw", "devil", "mad_bomber", "bonus_game")
RULES_UP, RULES_DONE = 5000, 5030             # in a single battle: rows take presses from, and A accepts them at


def with_rules(route, **steps):
    """A single-battle route with the rules screen changed: for each rule named, DOWN to its row and
    RIGHT that many times, 30 VBlanks a press. Everything from the rules' A on comes that much later."""
    buttons, row = [], 0
    for name, n in sorted(steps.items(), key=lambda kv: RULES.index(kv[0])):
        buttons += ["DOWN"] * (RULES.index(name) - row) + ["RIGHT"] * n
        row = RULES.index(name)
    delay = 30 * len(buttons)

    def later(at):
        return at + delay if at >= RULES_DONE else at

    presses = tuple(f"{later(int(at))}:{b}" for at, b in (p.split(":") for p in route.presses))
    presses += tuple(p for k, b in enumerate(buttons) for p in tap(RULES_UP + 30 * k, b, 8))
    return dataclasses.replace(route, presses=presses, vblanks=later(route.vblanks),
                               shots=",".join(str(later(int(v))) for v in route.shots.split(",")),
                               about=route.about + ", with " + ", ".join(f"{k} +{v}" for k, v in steps.items()))


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


# Master Game's floors, named as stage M-1 to M-20: a boss on every fourth.
MASTER = "M"
FLOORS = 20


def floor(number):
    """Master Game's floor NUMBER, from 1. The game sets stage_2 to world 8 and floor 0 at about
    VBlank 6536, then loads the floor, so the floor written just after is the one that loads. Play
    starts at about 6600."""
    from .run import GAME
    if not 1 <= number <= FLOORS:
        raise ValueError(f"no floor {number}: Master Game has M-1 to M-{FLOORS}")
    writes = (f"6537:{GAME.symbols['stage_2']:08X}=08{number - 1:02X}",) if number > 1 else ()
    return Route(f"Master Game's floor {number}", TO_MASTER, 6700, "6700", writes=writes)


def stage_start(world):
    """The VBlank play starts at in a stage route without items."""
    return 6600 if world == MASTER else 5700


def stage(world, number, items=False):
    """Stage WORLD-NUMBER as the game shows it (from 1), through Normal Game's start with the world and
    stage written over the ones it chose; START skips the opening movie. Play starts at about VBlank
    5620, or 5000 with every item (the title's held code), whose start comes sooner. World M is Master
    Game's floors."""
    from .run import GAME
    if world == MASTER and not items:
        return floor(number)
    if not 1 <= number <= STAGES.get(world, 0):
        raise ValueError(f"no stage {world}-{number}: " + ", ".join(f"{w}-1 to {w}-{n}" for w, n in STAGES.items())
                         + f", or Master Game's {MASTER}-1 to {MASTER}-{FLOORS} without items")
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
    """The single battle played to its end, pad 1 dropping one bomb at the start. Sudden death
    starts with a minute left (VBlank 13600): pressure blocks drop in a spiral from the edge, one
    in mid-fall at 14410. Then the 3 WIN MATCH results with the round's winner, and C on to round
    two, whose HUD counts that win."""
    return Route("a single battle's round played out through sudden death, its results, then round two",
                 single().presses + tap(6500, "C", 4) + tap(16100, "C", 8), 16400, "13600,14410,16090,16400")


def master():
    return Route("Master Game: the temple intro and its first floor", TO_MASTER, 6700, "5500,6700")


def master_boss():
    """Floor 4's boss, the first Bomber Instructor, beaten by the bot, the ladder taken and floor 5."""
    base = clear(MASTER, 4)
    return Route("Master Game's first boss beaten, on to floor 5", base.presses, 14900, f"{base.shots},14900",
                 invincible=True, writes=base.writes)


def master_result():
    """Floor 1 cleared by the bot, then floor 2's clock run out: RESULT, START to the TOP 10
    CHALLENGERS table, which the game saves as BOMBERSS_02, START to its TRY AGAIN or QUIT, and
    TRY AGAIN back to floor 1."""
    presses = clear(MASTER, 1).presses + taps((20600, 21000, 21400), "START", 8)
    return Route("Master Game run out of time: its result, the TOP 10 table saved, and TRY AGAIN",
                 presses, 21700, "20500,20800,21250,21700", invincible=True)


def mad_bomber():
    """A single battle with Mad Bomber on. Pad 1 walks into its own bomb's blast (dead at about
    VBlank 7020), flies off and rides a hovercraft round the edge, moved by UP and DOWN. C throws a
    bomb in from the edge (7400), and its blast takes the CPU by the right wall (7448), who joins it on
    the edge. A Mad Bomber scores kills but never comes back into the arena."""
    presses = single().presses + tap(6650, "C", 6) + tap(6700, "A", 6) + tap(6760, "B", 6) + tap(6800, "DOWN", 20)
    presses += tuple(p for k in range(3) for p in tap(7150 + 100 * k, ("UP", "DOWN")[k // 4 % 2], 30) + tap(7190 + 100 * k, "C", 6))
    return with_rules(Route("a single battle with Mad Bomber: pad 1 dies, throws from the edge and takes a CPU",
                            presses, 7420, "6880,7220,7268,7420"), mad_bomber=1)


def team():
    """Mode turned to Team on the battle screen (RIGHT at 4610). After character select, the Team
    Battle screen places each player on White, Red, Blue, Yellow or Green: A alone puts four on White
    and one on Red (6620), and the match's HUD counts wins by team (7520)."""
    presses = TO_BATTLE + taps(range(4400, 4581, 90), "A", 8) + tap(4610, "RIGHT", 8) + taps(range(4680, 5900, 90), "A", 8)
    return Route("a team battle: the Team Battle screen, then the match with a team HUD",
                 presses + taps(range(6100, 7400, 90), "A", 8), 7520, "6620,7520")


def five_minutes():
    return with_rules(Route("a single battle with five-minute rounds", single().presses, 6500, "6500"), time=2)


def bonus_game():
    """The battle-round with Bonus Game on and the match won at one win: the winner's VICTORY!, then
    BOMBER CATCHER, a crane over prizes, steered with C (the claw down at about 17050), and the
    battle screen for the next match."""
    presses = battle_round().presses[:-2] + taps(range(15900, 17000, 300), "C", 8)
    return with_rules(Route("a one-win match, its VICTORY! and the BOMBER CATCHER bonus game",
                            presses, 17050, "16150,16600,16750,16900,17050"), battles=3, bonus_game=1)


def kick_goal():
    """Soccer Stadium with kick written into pad 1 (its +0x70) and pad 1 invincible, played through the
    agent: it bombs its way down to row 21, sets a bomb by the left goal and kicks it in. The bomb goes off
    in the goal at once (7671), about 110 VBlanks before its fuse would have run out."""
    from .run import GAME
    base = arena(2)
    return Route("Soccer Stadium: a bomb kicked into the left goal goes off there at once",
                 base.presses + presses_file("kick-goal-presses.txt"), 7680, "7651,7671",
                 invincible=True, writes=(f"6700:{GAME.symbols['objects'] + 0x70:08X}=01",))


# Pad 1 is created riding a dino when its +0x5E has 0x0800 and dino_colours names a colour. A single battle
# clears both at about VBlank 6336 and creates pad 1 at 6354.
DINOS = {"pink": 1, "blue": 2, "green": 3, "yellow": 4, "purple": 5}


def dino(colour, presses, shots, about):
    from .run import GAME
    writes = (f"6345:{GAME.symbols['objects'] + 0x5E:08X}=0800", f"6345:{GAME.symbols['dino_colours']:08X}={DINOS[colour]:02X}")
    end = max(int(v) for v in shots.split(","))
    return Route(f"a single battle with pad 1 on the {colour} dino: {about}", single().presses + presses, end, shots,
                 writes=writes)


RIDE = tap(6720, "RIGHT", 30) + tap(6760, "A", 20)
DINO_ROUTES = {
    "dino-pink": lambda: dino("pink", RIDE, "6700,6790", "A jumps it into the air"),
    "dino-green": lambda: dino("green", RIDE, "6700,6790", "A dashes it along the row"),
    "dino-yellow": lambda: dino("yellow", RIDE, "6700,6810", "A roars"),
    "dino-purple": lambda: dino("purple", RIDE, "6700,6810,6880", "A sends out sound waves"),
    "dino-blue": lambda: dino("blue", tap(6710, "C", 6) + tap(6730, "RIGHT", 24) + tap(6770, "LEFT+A", 30),
                              "6760,6780,6800", "LEFT and A kick its bomb into the air"),
    "dino-burn": lambda: dino("green", tap(6710, "C", 6), "6875,6900,6925",
                              "its own bomb knocks the dino out and the bomber is left standing"),
}


def dino_hatch():
    """A CPU's blast uncovers an egg at (14,26) (VBlank 6840), a CPU walks onto it and rides the green
    dino that hatches (6935)."""
    return Route("a single battle where a CPU uncovers an egg and hatches a green dino", single().presses,
                 6935, "6840,6890,6935")


# Item kinds, from each one given to pad 1 (item-N): what changed in the bomber, or what the icon shows
# where nothing in it did.
ITEM_KINDS = {1: "fire up", 2: "bomb up", 3: "skate", 4: "a bomb kind", 5: "?", 6: "?", 7: "a timed state",
              8: "clock", 9: "1UP", 10: "speed down", 11: "kick", 12: "glove", 13: "a bomb kind",
              14: "a bomb kind", 15: "an ability", 16: "skull", 17: "heart", 18: "apple", 19: "ice cream",
              20: "a bomb kind", 21: "egg", 22: "a timed state", 23: "a bomb kind", 24: "a bomb kind"}
ITEM_CELL, ITEM_SLOT = (8, 17), 60             # the soft block beside pad 1's start; a slot no battle uses


def hide(kind, cell=ITEM_CELL, slot=ITEM_SLOT, at=6600):
    """Writes that hide an item of `kind` in the soft block at `cell`."""
    from .run import GAME
    x, y = cell
    return (f"{at}:{GAME.symbols['hidden_items'] + (y * 64 + x) * 2:08X}={slot:04X}",
            f"{at}:{GAME.symbols['item_slots'] + slot * 8:08X}=0000000000{kind:02X}0000")


def item(kind):
    """A single battle where pad 1 bombs the block beside it, with item `kind` hidden in it, and picks the
    item up: revealed at 6890, taken by 6966."""
    return Route(f"a single battle where pad 1 uncovers and takes item {kind} ({ITEM_KINDS[kind]})",
                 single().presses + presses_file("item-presses.txt"), 6966, "6890,6966", writes=hide(kind))


def egg_burn():
    """An egg uncovered beside pad 1 (6890), then pad 1's next bomb beside it (7072) goes off: the egg is
    fried (7097) and gone by 7122."""
    return Route("a single battle where pad 1 uncovers an egg and its next bomb fries it",
                 single().presses + presses_file("egg-burn-presses.txt"), 7122, "6890,7072,7097,7122",
                 writes=hide(21))


def egg_second():
    """Pad 1 hatches one egg and rides (7032), then uncovers a second and walks onto it (7458): the dino's
    count of eggs eaten (+0x64) goes to 1, and nothing in the picture changes."""
    return Route("a single battle where pad 1 rides a hatched dino onto a second egg",
                 single().presses + presses_file("egg-second-presses.txt"), 7458, "7032,7458",
                 writes=hide(21) + hide(21, (9, 17), ITEM_SLOT + 1))


def dino_evolve():
    """Pad 1 rides a hatched dino (7092), then eats a second egg (7608) and a third (8268): each raises the
    dino's count of eggs eaten (+0x64), to its cap of 2, and with the third the dino grows bigger, with
    spines on its back."""
    return Route("a single battle where pad 1's dino eats two more eggs and grows",
                 single().presses + presses_file("dino-evolve-presses.txt"), 8388, "7092,7608,8268,8388",
                 writes=sum((hide(21, (x, 17), ITEM_SLOT + i) for i, x in enumerate((8, 9, 10))), ()))


def tag(items):
    return "-items" if items else ""


ROUTES = {"normal": normal, "single": single, "battle": battle,
          "items": lambda: world("items"),
          **{name: (lambda name=name: world(name)) for name in WORLDS},
          "cactus": cactus, "slot": slot, "yuna": yuna,
          "die": die, "game-over": game_over, "continue": continued, "save": save,
          "pause": paused, "battle-round": battle_round,
          **{f"item-{k}": (lambda k=k: item(k)) for k in ITEM_KINDS}, "egg-burn": egg_burn, "egg-second": egg_second,
          "dino-evolve": dino_evolve,
          "mad-bomber": mad_bomber, "kick-goal": kick_goal, "dino-hatch": dino_hatch, **DINO_ROUTES, "team": team, "five-minutes": five_minutes, "bonus-game": bonus_game,
          "master": master, "master-boss": master_boss, "master-result": master_result,
          **{f"arena-{n}": (lambda n=n: arena(n)) for n in range(2, len(ARENAS) + 1)},
          **{f"arena-{n}-{sky}": (lambda n=n, sky=sky: arena(n, sky)) for n in range(1, len(ARENAS) + 1) for sky in SKIES[1:]}}
