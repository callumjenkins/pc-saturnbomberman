"""A stage as the game holds it in RAM: the map, the objects, the exit. The addresses and layouts are
game.toml's symbols."""
from dataclasses import dataclass

from .run import GAME

SLOT = 0x7C
SLOTS = 50
ENEMY_SLOTS = range(10, SLOTS)

SOLID, SOFT, BOMB, FIRE = 0x80, 0x10, 0x20, 0x07
# Both bits: a cannon (0x0B08 on 3-7), which holds a bomber until A, B or L climbs it back out, or
# railway track (0x0F00 on 3-2 and 3-3), whose trains run a bomber down.
CANNON = 0x0300
BRIDGE = 0x4000                                   # 4-4's stone bridges over the lava, 0x5300 once lowered: floor, not a cannon
MASTER_WORLD = 8                                  # stage_2's world in Master Game, with the floor after it
LADDER = (14, 17)                                 # where Master Game's ladder drops, once no enemy is left


@dataclass(frozen=True)
class Thing:
    slot: int
    update: int                                  # the object's update function: its kind
    cell: tuple[int, int]
    x: float                                     # pixels
    y: float


def cannon(v):
    return v & CANNON == CANNON and not v & BRIDGE


@dataclass(frozen=True)
class Stage:
    cells: tuple[int, ...]                       # 64*64 words, (x, y) at y*64+x
    me: Thing | None                             # pad 1's bomber, None when it is gone (as on the exit)
    enemies: tuple[Thing, ...]
    exit: tuple[int, int]

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
    if r.read(sym["stage_2"], 1)[0] == MASTER_WORLD:
        exit = LADDER if not enemies else (-1, -1)
    return Stage(cells, bomber[0] if bomber else None, enemies, exit)
