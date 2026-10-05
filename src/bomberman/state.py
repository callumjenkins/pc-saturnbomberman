"""A stage as the game holds it in RAM: the map, the objects, the exit. The addresses and layouts are
game.toml's symbols."""
from dataclasses import dataclass

from .run import GAME

SLOT = 0x7C
SLOTS = 50
ENEMY_SLOTS = range(10, SLOTS)

SOLID, SOFT, BOMB, FIRE = 0x80, 0x10, 0x20, 0x07


@dataclass(frozen=True)
class Thing:
    slot: int
    cell: tuple[int, int]
    x: float                                     # pixels
    y: float


@dataclass(frozen=True)
class Stage:
    cells: tuple[int, ...]                       # 64*64 words, (x, y) at y*64+x
    me: Thing | None                             # pad 1's bomber, None when it is gone (as on the exit)
    enemies: tuple[Thing, ...]
    exit: tuple[int, int]

    def at(self, c):
        x, y = c
        return self.cells[y * 64 + x] if 0 <= x < 64 and 0 <= y < 64 else SOLID

    def passable(self, c):
        return not self.at(c) & (SOLID | SOFT | BOMB)


def _things(raw, slots):
    idle = GAME.symbols["idle_object"]
    out = []
    for k in slots:
        s = raw[k * SLOT:(k + 1) * SLOT]
        if int.from_bytes(s[0x30:0x34], "big") == idle or s[0x34] & 0x80:
            continue
        cell = int.from_bytes(s[0x44:0x46], "big")
        out.append(Thing(k, (cell % 64, cell // 64),
                         int.from_bytes(s[0x48:0x4C], "big") / 65536, int.from_bytes(s[0x4C:0x50], "big") / 65536))
    return out


def me(r):
    """Pad 1's bomber alone: one read of its slot, for following it as it walks."""
    found = _things(r.read(GAME.symbols["objects"], SLOT), [0])
    return found[0] if found else None


def read(r):
    sym = GAME.symbols
    raw = r.read(sym["cells"], 64 * 64 * 2)
    cells = tuple(int.from_bytes(raw[2 * i:2 * i + 2], "big") for i in range(64 * 64))
    objs = r.read(sym["objects"], SLOT * SLOTS)
    bomber = _things(objs, [0])
    exit_cell = int.from_bytes(r.read(sym["exit_cell"], 2), "big")
    return Stage(cells, bomber[0] if bomber else None, tuple(_things(objs, ENEMY_SLOTS)),
                 (exit_cell % 64, exit_cell // 64))
