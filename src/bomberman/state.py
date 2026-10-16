"""A stage as the game holds it in RAM: the map, the objects, the exit. The addresses and layouts are
game.toml's symbols."""
from dataclasses import dataclass

from .run import GAME

SLOT = 0x7C
SLOTS = 50
ENEMY_SLOTS = range(10, SLOTS)

SOLID, ITEM, SOFT, BOMB, FIRE = 0x80, 0x40, 0x10, 0x20, 0x07
# Both bits: a cannon (0x0B08 on 3-7), which holds a bomber until A, B or L climbs it back out, or
# railway track (0x0F00 on 3-2 and 3-3), whose trains run a bomber down.
CANNON = 0x0300
CART = 0x5B00                                     # 3-6's mine cart where it waits; 4-2's floor 0x4A00 shares bits with it
BRIDGE = 0x4000                                   # 4-4's stone bridges over the lava, 0x5300 once lowered: floor, not a cannon
WEAK_FIRE = 0x0010                                # the skull's illness (+0x5A) that leaves a bomber one cell of fire
# The sleeping cactus, a slot machine mini-game once bombed on all four sides (routes.cactus): an object that
# never dies, at a fixed cell of two Gunman stages, by (world, stage) as the game shows them.
CACTI = {(3, 1): (11, 25), (3, 3): (35, 40)}
MASTER_WORLD = 8                                  # stage_2's world in Master Game, with the floor after it
LADDER = (14, 17)                                 # where Master Game's ladder drops, once no enemy is left


@dataclass(frozen=True)
class Thing:
    slot: int
    update: int                                  # the object's update function: its kind
    cell: tuple[int, int]
    x: float                                     # pixels
    y: float


def cart(v):
    """3-6's mine cart, waiting at one end of its track: a bomber who steps on rides it to the other."""
    return v & 0xFF80 == CART


def cannon(v):
    return v & CANNON == CANNON and not v & BRIDGE


@dataclass(frozen=True)
class Stage:
    cells: tuple[int, ...]                       # 64*64 words, (x, y) at y*64+x
    me: Thing | None                             # pad 1's bomber, None when it is gone (as on the exit)
    enemies: tuple[Thing, ...]
    exit: tuple[int, int]
    fire: int = 2                                # how far the bomber's blasts reach, in cells
    weak: tuple[int, int] | None = None          # the one cell a boss takes hits on, for the bosses that have one

    @property
    def cores(self):
        """The Core Mechanisms left, which keep the exit shut."""
        return tuple(e for e in self.enemies if e.update == GAME.symbols["core_mechanism"])

    def at(self, c):
        x, y = c
        return self.cells[y * 64 + x] if 0 <= x < 64 and 0 <= y < 64 else SOLID

    def passable(self, c):
        v = self.at(c)
        return not v & (SOLID | SOFT | BOMB) and not cannon(v)


def _things(raw, slots):
    idle = GAME.symbols["idle_object"]
    out = []
    for k in slots:
        s = raw[k * SLOT:(k + 1) * SLOT]
        update = int.from_bytes(s[0x30:0x34], "big")
        # an update function outside the game's code means the array holds something else, as in the ending
        if update == idle or s[0x34] & 0x80 or not 0x06000000 <= update < 0x06100000:
            continue
        cell = int.from_bytes(s[0x44:0x46], "big")
        out.append(Thing(k, int.from_bytes(s[0x30:0x34], "big"), (cell % 64, cell // 64),
                         int.from_bytes(s[0x48:0x4C], "big") / 65536, int.from_bytes(s[0x4C:0x50], "big") / 65536))
    return out


MEANIE = (5, 9)                                   # the stage of Mr. Meanie's mech, whose body is slot 10


def meanie_weak(objs, r):
    """The cell Mr. Meanie's mech takes hits on, worked out as the game does; None when no fire can hurt it."""
    sym = GAME.symbols
    body = objs[10 * SLOT:11 * SLOT]
    word = lambda a: int.from_bytes(r.read(a, 2), "big")
    lost = word(sym["meanie_parts_lost"])
    out = (word(sym["meanie_parts_out"]) - lost) & 0xFFFF
    x = int.from_bytes(body[0x48:0x4A], "big")
    y = (int.from_bytes(body[0x4C:0x4E], "big") - 32 + 16 * lost + 16 * out) & 0xFFFF
    at = ((y >> 4) + (y >> 3 & 1)) * 64 + (x >> 4) + (x >> 3 & 1)   # each to the nearest cell
    if out:
        phase = word(sym["meanie_phase"])
        if phase >= 3:
            return None
        at += int.from_bytes(r.read(sym["meanie_offsets"] + 2 * phase, 2), "big", signed=True)
    return at % 64, at // 64


def cell(r, c):
    """One cell of the map: a 2-byte read, for checking under the bomber as it walks."""
    x, y = c
    return int.from_bytes(r.read(GAME.symbols["cells"] + 2 * (y * 64 + x), 2), "big")


def me(r, pad=1):
    """A pad's bomber alone: one read of its slot, for following it as it walks."""
    found = _things(r.read(GAME.symbols["objects"] + (pad - 1) * SLOT, SLOT), [0])
    return found[0] if found else None


def read(r, pad=1):
    """The map, the pad's bomber as `me`, the enemies and the exit."""
    sym = GAME.symbols
    raw = r.read(sym["cells"], 64 * 64 * 2)
    cells = tuple(int.from_bytes(raw[2 * i:2 * i + 2], "big") for i in range(64 * 64))
    objs = r.read(sym["objects"], SLOT * SLOTS)
    bomber = _things(objs, [pad - 1])
    exit_cell = int.from_bytes(r.read(sym["exit_cell"], 2), "big")
    # a bomb is an object in the enemies' slots too, on a cell the map marks as holding one
    # (a slot can also hold a cell off the map, in a stage that keeps other things there)
    enemies = tuple(t for t in _things(objs, ENEMY_SLOTS) if t.cell[1] < 64 and not cells[t.cell[1] * 64 + t.cell[0]] & BOMB)
    exit = (exit_cell % 64, exit_cell // 64)
    weak = None
    if r.read(sym["stage_2"], 1)[0] == MASTER_WORLD:
        exit = LADDER if not enemies else (-1, -1)
    else:
        world, number = r.read(sym["stage"], 2)
        cactus = CACTI.get((world + 1, number + 1))
        enemies = tuple(e for e in enemies if e.cell != cactus)
        weak = meanie_weak(objs, r) if (world + 1, number + 1) == MEANIE and enemies else None
    me_slot = objs[(pad - 1) * SLOT:pad * SLOT]
    fire = 1 if int.from_bytes(me_slot[0x5A:0x5C], "big") & WEAK_FIRE else int.from_bytes(me_slot[0x64:0x66], "big")
    return Stage(cells, bomber[0] if bomber else None, enemies, exit, max(fire, 1), weak)
