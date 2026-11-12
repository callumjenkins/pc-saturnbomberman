from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

OUT = 0x060C0100            # where a function is given room to write a result


def KEYED(n):
    return 0x060C104C + 16 * n



SND = 0x25A00000            # sound RAM, through the cache-through mirror

# 096FA: a table of 8-byte entries in sound RAM; the word at 408 is its offset
HEADS = [(k << 28) | (i << 24) | 0x1234 for k in (0, 1, 2, 7) for i in (0, 1, 2, 15)] + [0x80000000, 0xF0000000]
case("f060096FA", [pick(OUT), pick(OUT + 8), pick(0, 1, 2, 7), pick(0, 1, 2, 15)], False,
     [plant(SND + 0x408, 4, [0x500, 0x600])]
     + [plant(SND + 0x500 + 8 * k, 4, HEADS, 0.9) for k in range(10)]
     + [plant(SND + 0x600 + 8 * k, 4, HEADS, 0.9) for k in range(10)])

# 09762: four lists of 15 pointers to records whose first halfword is the kind; kind 6 looks the record's
# two other halfwords up in the sound RAM table, which 096FA leaves unset when there is no match
LISTS = [0x060C3000 + 0x80 * k for k in range(4)]
RECS = [0x060C3800 + 0x20 * j for j in range(15)]
KEYS = [(k << 28) | (i << 24) | 0x1234 for k in (0, 1, 2, 7) for i in (0, 1, 2, 15)]
case("f06009762", [pick(4, 9, 0x10000), pick(0, 1, 2, 3)], False,
     [plant(0x060BD8E4 + 4 * k, 4, [LISTS[k]], 1.0) for k in range(4)]
     + [plant(LISTS[k] + 4 * j, 4, [RECS[j]], 1.0) for k in range(4) for j in range(15)]
     + [plant(LISTS[k] + 4 * j, 4, [-1], 0.06) for k in range(4) for j in range(15)]
     + [plant(RECS[j], 2, [0, 3, 4, 5, 6, 6, 9], 1.0) for j in range(15)]
     + [plant(RECS[j], 2, [1, 2], 0.03) for j in range(15)]
     + [plant(RECS[j] + 2, 2, [0, 1, 2, 7], 1.0) for j in range(15)]
     + [plant(RECS[j] + 4, 2, [0, 1, 2, 15], 1.0) for j in range(15)]
     + [plant(RECS[j] + o, 2, [0, 1, 2, 5, 0x100], 0.8) for j in range(15) for o in (6, 8)]
     + [plant(SND + 0x408, 4, [0x500])]
     + [plant(SND + 0x500 + 8 * k, 4, [KEYS[k]], 1.0) for k in range(16)]
     + [plant(SND + 0x500 + 8 * 16, 4, [0x80000000], 1.0)])

# the table of device states: port k's halfword at 060FBF50's target holds a state in its high byte
PORT_TABLE = [plant(0x060FBF50, 4, [0x060C3000], 1.0)] + [plant(0x060C3000 + 2 * k, 2, [0x0100, 0x0101, 0x0300, 0x0305, 0, 0x0200], 0.9) for k in range(8)]
case("f06009940", [], False, PORT_TABLE + [plant(0x060B2E84, 1, [0, 1, 1]), plant(0x060B2E85, 1, [0, 1])])
case("f06009A08", [span(-1, 7)], True, PORT_TABLE)
case("f06009A3A", [pick(0, 1, 2, 3)], True, PORT_TABLE)
case("f06009A6C", [], False, PORT_TABLE)
case("f06009AC0", [], True, PORT_TABLE)

# 0FE8A: a table of ten 16-byte entries ordered by (u16 at 14, u16 at 12, word 0, word 4, word 8)
TOP = [plant(0x060C0A4C + 4 * _i, 4, [1, 2], 0.15) for _i in range(19)] + [plant(0x060C0690, 4, [0, 1], 0.5), plant(0x060C06C0, 4, [0, 0, 5]),
                                                                          plant(0x060C029D, 1, [0, 1, 2])]
for _k in range(10):
    _e = 0x060C0910 + 16 * _k
    TOP += [plant(_e + 14, 2, [0, 0, 0, 0x11], 0.9), plant(_e + 12, 2, [1, 2, 3, 3, 1], 0.95), plant(_e, 4, [0, 0, 1], 0.9),
            plant(_e + 4, 4, [0, 0, 0, 1, 2, 3], 0.9), plant(_e + 8, 4, [0, 3, 5, 9], 0.9)]
TOP += [plant(0x060C0910 + 16 * 9 + 12, 2, [0, 3], 0.5)]
case("f0600FE8A", [], True, TOP)


def cells(base, values, chance=0.5, lo=100, hi=540):
    """The halfword of each map cell from lo to hi in one of the 4096-cell tables."""
    return [plant(base + 2 * c, 2, values, chance) for c in range(lo, hi)]


def bom(off, size, values, chance=0.9, ids=(0, 1)):
    return [plant(bomber(k) + off, size, values, chance) for k in ids]


# the walking bomber's cell is 320; the grid is 64 cells wide and the brain functions look up to six cells away
CUR = [plant(0x060D7768, 4, [bomber(0)], 1.0), plant(bomber(0) + 20, 2, [320], 1.0)]
GRID = (cells(0x060EC8B0, [0], 0.7) + cells(0x060EC8B0, [1, 7, 0x20, 0x40, 0xB7, 0x40D0, 0x42B0, 0x290, 0x10, 0x8000], 0.12)
        + cells(0x060EE8B0, [0], 0.6) + cells(0x060EE8B0, [0x100, 0x200, 0x300, 0x1000, 0xC00, 0xF00, 0x400, 0xB00, 0xA00, 0xD00, 0x900, 0x800, 0x700, 0x600, 0x600, 0x700], 0.2)
        + cells(0x060F08B0, [0, 0, 1, 0xFF, 0x100], 0.5))
NAV = CUR + GRID
BRAIN = 0x060C2200


def brain(off, size, values, chance=0.8):
    return plant(BRAIN + off, size, values, chance)


# 113FC: a depth-first walk with its path of 6-byte steps at 060C04A0
WALK = (CUR + [plant(0x060C04C5, 1, [0, 1, 2, 3]), plant(0x060C04C4, 1, [1, 2, 3, 4, 5]), plant(0x060C04D0, 2, [0xFFFF, 0, 5], 0.4),
               plant(0x060C04D8, 2, [64, 320, 321, 7], 0.9)]
        + [plant(0x060C04A0 + 6 * k + 2, 1, [0, 1, 2, 3, 4], 0.9) for k in range(8)])
case("f060113FC", [], True, WALK + GRID)
case("f06011570", [pick(BRAIN)], True,
     WALK + GRID + [plant(0x060C04CA, 2, [0, 1, 2]), plant(0x060C04CC, 2, [0, 1, 2]), plant(0x060C04DA, 2, [0, 1, 3]),
                    plant(0x060C04DC, 2, [1, 0x40, 0xFFFF, 0x20])]
     + [plant(0x060B39A8 + 2 * k, 2, [1, 2, 5, 9], 1.0) for k in range(4)] + [plant(0x060B3978 + 2 * k, 2, [0, 1, 3, 9, 0xFFFF], 1.0) for k in range(4)])
case("f06011FE4", [span(0, 5)], True, NAV + [plant(0x060C04CA, 2, [0, 0, 1])] + [plant(0x060B3C68 + 4 * k, 4, [0, 1, 64, -1, -64], 1.0) for k in range(5)])
case("f060120B4", [span(0, 5)], True,
     NAV + [plant(0x060EC8B0 + 640, 2, [0, 0, 0, 1, 7]), plant(0x060C04CA, 2, [0, 0, 1, 9]), plant(0x060C04CC, 2, [0, 1, 2]), plant(0x060C04DA, 2, [0, 1, 3])]
     + [plant(0x060B3990 + 2 * k, 2, [1, 2, 5, 9], 1.0) for k in range(4)] + [plant(0x060B3C68 + 4 * k, 4, [0, 1, 64, -1, -64], 1.0) for k in range(5)]
     + [plant(bomber(0) + 52, 2, [0, 0, 1, 2, 3, 4, 5, 6, 4, 5], 0.95)]
     + [plant(0x060EE8B0 + 2 * (320 + s * k), 2, [0], 0.9) for s in (1, 64, -1, -64) for k in (1, 2, 3)]
     + [plant(0x060EE8B0 + 2 * (320 + s * 4), 2, [0x1000], 0.8) for s in (1, 64, -1, -64)])
case("f06012376", [span(0, 5)], True,
     NAV + [plant(0x060C04CA, 2, [0, 0, 1]), plant(0x060C04CC, 2, [0, 1, 2]), plant(0x060C04DA, 2, [0, 1, 3])]
     + [plant(0x060B3990 + 2 * k, 2, [1, 2, 5, 9], 1.0) for k in range(4)] + [plant(0x060B3C68 + 4 * k, 4, [0, 1, 64, -1, -64], 1.0) for k in range(5)]
     + [plant(bomber(0) + 52, 2, [0, 0, 1, 2, 3, 5], 0.95)])

DIRS = [plant(0x060B3C68 + 4 * k, 4, [0, 1, 64, -1, -64], 1.0) for k in range(5)]
OPEN = [plant(0x060C04CA, 2, [0, 0, 1, 3]), plant(0x060C04CC, 2, [0, 1, 2]), plant(0x060C04DA, 2, [0, 1, 3]), plant(0x060C04DC, 2, [1, 0x40, 0xFFFF, 0x20])]
READY = (bom(64, 2, [0x100, 0x300, 0x100, 0], 0.95, (0,)) + bom(62, 2, [5, 10, 3, 0, 2], 0.95, (0,)) + bom(40, 2, [0, 1, 2, 5], 0.95, (0,))
         + bom(42, 2, [0, 0, 0x20, 0x2000], 0.95, (0,)) + bom(46, 2, [0, 0, 0x800, 0x2, 0x4], 0.95, (0,))
         + [plant(0x060EC8B0 + 640, 2, [0, 0, 0x1000, 0x8000, 7], 0.95)])
case("f06012D30", [pick(BRAIN)], True, NAV + DIRS + OPEN + READY)
case("f06012E8C", [pick(BRAIN)], True, NAV + DIRS + OPEN + READY)
case("f06013238", [pick(BRAIN)], True, NAV + DIRS + OPEN + READY + [plant(bomber(0) + 40, 2, [0, 0, 1])])

DIR_LISTS = [127, 1, 1, 64, 64, 1, 1, 0, 129, -1, -1, 64, 64, -1, -1, 0, -66, 64, 64, -1, -1, 64, 64, 0, 62, -64, -64, -1, -1, -64, -64, 0,
             -127, -1, -1, -64, -64, -1, -1, 0, -129, 1, 1, -64, -64, 1, 1, 0, 66, -64, -64, 1, 1, -64, -64, 0, -62, 64, 64, 1, 1, 64, 64, 0, 0]
case("f060137CC", [pick(BRAIN)], True,
     NAV + DIRS + [plant(0x060B404C + 4 * i, 4, [v], 1.0) for i, v in enumerate(DIR_LISTS)]
     + [plant(0x060B41E2 + 2 * k, 2, [63, 31, 15, 127, 0, 1], 0.9) for k in range(4)] + [plant(0x060C04CC, 2, [0, 1, 2, 3])]
     + [plant(0x060B404C + 4 * (i * 8), 4, [0], 0.03) for i in range(1, 8)]
     + bom(62, 2, [10, 12, 3, 40, 9], 0.95, (0,)) + bom(40, 2, [0, 1, 2, 5, 7], 0.95, (0,)))

SIDES = [plant(0x060B3BB8 + 4 * k, 4, [v], 1.0) for k, v in enumerate([1, 64, -1, -64])] + [plant(0x060B3BC8 + 4 * k, 4, [v], 1.0) for k, v in enumerate([-1, -64, 1, 64])]
case("f06013094", [], True, NAV + SIDES + OPEN + [plant(0x060EE8B0 + 2 * c, 2, [0x1000, 0x1100, 0, 0x1F00], 0.4) for c in range(250, 400)])

RING = [-65, -64, -63, -1, 1, 63, 64, 65, -130, -129, -128, -127, -126, -66, -62, -2, 2, 62, 66, 126, 127, 128, 129, 130]
case("f0601334C", [pick(BRAIN)], True,
     NAV + [plant(0x060B3C08 + 4 * k, 4, [v], 1.0) for k, v in enumerate(RING)]
     + [plant(0x060EC8B0 + 2 * (320 + d), 2, [0x10, 0, 0x10], 0.6) for d in RING]
     + [plant(0x060EE8B0 + 2 * (320 + d), 2, [0x200, 0x100, 0, 0x300], 0.6) for d in RING]
     + [plant(0x060F08B0 + 2 * (320 + d), 2, [1, 0, 0x100, 0xFF], 0.6) for d in RING])

STEPS = [-63, -64, -62, 4096, -63, 1, -127, -32768, 65, 64, 66, 8192, 65, 1, 129, -32768, 63, 64, 62, 8192, 63, -1, 127, 16384,
         -65, -64, -66, 4096, -65, -1, -129, 16384, 0]
case("f060135B2", [pick(BRAIN)], True,
     NAV + OPEN + [plant(BRAIN + 24, 1, [1], 1.0)] + bom(20, 2, [257, 385, 383, 255, 5], 0.95, (1,))
     + [plant(0x060B4008 + 2 * i, 2, [v], 1.0) for i, v in enumerate(STEPS)] + [plant(0x060B4008 + 8 * k, 2, [0], 0.05) for k in range(1, 8)]
     + [plant(0x060B3990 + 2 * k, 2, [2, 3, 6, 9], 1.0) for k in range(4)]
     + [plant(0x060EC8B0 + 2 * (320 + d), 2, [0xB7, 1, 0x20, 0, 0xB7], 0.9) for d in (-62, -127, 66, 129, 62, 127, -66, -129)]
     + [plant(0x060EC8B0 + 2 * (320 + d), 2, [0, 0, 0x42B0, 0x10], 0.8) for d in (-64, 1, 64, -1, -63, 65, 63, -65)]
     + [plant(0x060EE8B0 + 2 * (320 + d), 2, [0x100, 0x500, 0x400, 0, 0x900], 0.8) for d in (-64, 1, 64, -1, -63, 65, 63, -65)])

FIND = ([plant(0x060C063D, 1, [0, 1, 3, 6, 6])] + bom(4, 1, [0, 0, 0x40, 0x80, 0xC0], 0.9, range(7)) + bom(46, 2, [0, 0, 0x100, 0x33D, 0x1], 0.9, range(7))
        + bom(20, 2, [5, 7, 320, 0], 0.9, range(7)) + bom(24, 2, [0, 3, 4, 5, 12, 15, 0x1F0, 0x2C], 0.9, range(7)) + bom(28, 2, [0, 3, 4, 5, 12, 15, 0x1F0, 0x2C], 0.9, range(7)))
case("f06018DD6", [pick(5, 7, 320, 0)], True, FIND)
case("f06018E1A", [pick(5, 7, 320, 0)], True, FIND)

# 1B194: a bomber's progress through the range of the thing it holds
case("f0601B194", [span(0, 4)], True,
     bom(36, 2, [0, 1, 2, 3], 1.0, range(5)) + bom(64, 2, [1, 2, 3, 4, 5], 1.0, range(5)) + bom(52, 2, [0, 1, 2], 1.0, range(5))
     + [plant(0x060B46B8 + 4 * j, 4, [0, 100, 200, 400, 50], 0.9) for j in range(18)]
     + [plant(0x060D82DC + 4 * j, 4, [0, 50, 150, 250, 1000, 100], 0.9) for j in range(30)])
# 1B514 accepts bomber v when its cell is a and its code word and halfword at 36 hold the markers planted here
case("f0601B582", [pick(0, 1, 2, 3, 7), pick(0, 1, 2, 3)], True, [plant(0x060D82CC + k, 1, [0, 1, 2, 3, 3], 0.7) for k in range(8)]
     + [plant(0x060D82CC + k, 1, [0], 0.3) for k in range(8)]
     + bom(4, 1, [0, 0, 0x40], 0.9, range(1, 4)) + bom(20, 2, [0, 1, 2, 3, 7], 0.9, range(1, 4))
     + [plant(bomber(k), 4, [0x0601B5CC], 0.9) for k in range(1, 4)] + bom(36, 2, [0xFF, 0xFF, 0], 0.9, range(1, 4)))

# FB04: a walk of 38-byte records linked through byte 7, looking for one on a cell next to a given one.
# C9C0 wraps a cell into the stage, columns 4 to 24 and rows 15 to 29 of the 64-wide grid, whose limits sit at 060D7E7C
STAGE = [plant(0x060D7E7C, 2, [4], 1.0), plant(0x060D7E7E, 2, [16], 1.0), plant(0x060D7E80, 2, [25], 1.0), plant(0x060D7E82, 2, [29], 1.0)]
MID = 20 * 64 + 10
REG = (STAGE + cells(0x060EC8B0, [0x20, 0x20, 0, 0x290, 0x42B0], 0.5, MID - 140, MID + 140) + cells(0x060EE8B0, [0, 0, 0, 0x7000], 0.4, MID - 140, MID + 140)
       + [plant(0x060B47F0 + 2 * k, 2, [v], 1.0) for k, v in enumerate([0, 1, 64, -1, -64])])
REG += ([plant(0x060EC8B0 + 2 * (MID + d), 2, [0x20, 0x20, 0x20, 0x0], 0.85) for d in (1, 64, -1, -64)]
        + [plant(0x060EC8B0 + 2 * (MID + 2 * d), 2, [0, 0, 0, 0x290], 0.85) for d in (1, 64, -1, -64)]
        + [plant(0x060EE8B0 + 2 * (MID + 2 * d), 2, [0, 0, 0, 0x7000], 0.9) for d in (1, 64, -1, -64)])
LINKS = ([plant(0x060D84A3, 1, [0, 1, 2, 3])] + [plant(0x060DF97C, 2, [0, 4, 0xFFFF, 0x10])]
         + [plant(0x060D849C + 38 * i + 7, 1, [0, i + 1, i + 1, i + 2], 1.0) for i in range(12)]
         + [plant(0x060D849C + 38 * i + 7, 1, [0], 1.0) for i in range(12, 256)]
         + [plant(0x060D849C + 38 * i + 4, 2, [MID + 1, MID + 1, MID + 1, MID + 64, MID - 1, MID - 64, MID, 0], 0.97) for i in range(8)]
         + [plant(0x060D849C + 38 * i + 16, 1, [2, 5, 3, 4, 3, 0, 1, 255], 0.95) for i in range(8)]
         + [plant(0x060D849C + 38 * i + 10, 2, [0, 1, 4, 5, 1, 0, 0x1FA, 2], 0.95) for i in range(8)]
         + [plant(0x060D849C + 38 * i + 8, 2, [0, 64, 64, 1, 0], 0.95) for i in range(8)]
         + [plant(0x060D849C + 38 * i + 14, 1, [1, 1, 2, 3, 0], 0.95) for i in range(8)]
         + [plant(0x060D849C + 38 * i + 24, 1, [0, 1, 2, 3], 0.9) for i in range(8)]
         + [plant(0x060D849C + 38 * i + 6, 1, [0, 1, 2, 3, 4, 5, 6], 0.9) for i in range(8)])
def scene(n, **f):
    """Record n of the 38-byte list, set field by field for one way through FB04's match."""
    base = 0x060D849C + 38 * n
    out = [plant(base + 7, 1, [26], 1.0), plant(base + 6, 1, [3], 1.0), plant(base + 4, 2, [MID + 1], 1.0), plant(base + 16, 1, [3], 1.0),
           plant(base + 10, 2, [0], 1.0), plant(base + 8, 2, [0], 1.0), plant(base + 14, 1, [1], 1.0), plant(base + 24, 1, [0], 1.0)]
    off = {"w4": (4, 2), "b16": (16, 1), "w10": (10, 2), "w8": (8, 2), "b14": (14, 1), "b24": (24, 1)}
    for name, v in f.items():
        out.append(plant(base + off[name][0], off[name][1], [v], 1.0))
    return out


SCENES = (scene(20) + scene(21, w10=1, b24=2) + scene(22, w10=1, b14=2) + scene(23, w8=64) + scene(24, b16=255) + scene(25, w10=0x1FA)
          + scene(27, b14=2, b24=1) + [plant(0x060D849C + 38 * 26 + 7, 1, [0], 1.0)]
          + [plant(0x060D84A3, 1, [20, 21, 22, 23, 24, 25, 27, 0, 1], 0.9)])
case("f0601FB04", [pick(MID, MID, MID, 5, 0x20000 + MID), pick(1, 1, 1, 2, 3, 0x10001, 0), pick(0, 1, 5, 0x1234)], True, REG + LINKS + SCENES)
case("f0601FCBE", [], True, REG + LINKS + SCENES + [plant(0x060D7768, 4, [bomber(0)], 1.0), plant(bomber(0) + 20, 2, [MID, MID, 5], 1.0)]
     + bom(6, 1, [1, 1, 1, 1, 1, 1, 2, 3, 4, 0], 0.97, (0,)) + [plant(0x060C062C, 2, [0, 1, 5])])
ACT = 0x060C2100            # a record for the pointer at 060D8C08
ACTOR = [plant(0x060D8C08, 4, [ACT], 1.0)]


def act(off, size, values, chance=0.9):
    return plant(ACT + off, size, values, chance)


# 204A2: the bomber whose cell is the actor's
case("f060204A2", [pick(0, 1, 2)], True,
     ACTOR + [act(4, 2, [320, 5, 1290]), act(0, 2, [5, 320, 1290, 0x1F]), act(10, 2, [0, 4, 5, 1]), act(15, 1, [0, 1, 2, 3, 7])]
     + bom(20, 2, [320, 5, 1290], 0.9, range(50)) + bom(22, 2, [0, 1, 1, 1], 0.9, range(50)) + bom(9, 1, [0, 0, 0, 1], 0.9, range(50))
     + bom(4, 1, [0, 0, 0x80, 0x10], 0.9, range(50))
     + [plant(0x060EE8B0 + 2 * c, 2, [0x1000, 0, 0x1000], 0.6) for c in range(0, 4096)])

TREC = 0x060C2400           # a task record for the pointer at 060D7E60
TASKP = [plant(0x060D7E60, 4, [TREC], 1.0)]


def trec(off, size, values, chance=0.9):
    return plant(TREC + off, size, values, chance)


# 25946: the one bomber standing where the task says; when the task names none, the owners of the others decide
case("f06025946", [], True,
     TASKP + [trec(10, 2, [320, 5]), trec(18, 2, [255, 255, 0, 1, 2, 5]), plant(0x060C063D, 1, [1, 2, 3, 4, 6])]
     + bom(20, 2, [320, 5, 0], 0.9, range(16)) + bom(46, 2, [0, 0, 0, 1], 0.9, range(16)) + bom(4, 1, [0, 0, 0, 0x80], 0.9, range(16))
     + bom(36, 2, [0, 0, 1, 255, 2, 3], 0.9, range(16)))

# 260F8: spawns a task per entry of a list of (x, y) halfword pairs that ends in a zero x
case("f060260F8", [span(0, 20), pick(0, 5, -3), pick(0, 7), pick(1, 2)], False,
     TASKP + [plant(0x060D7E64, 4, [obj(3), obj(4)], 1.0), plant(0x060C02CC, 4, [0x060C3C00], 1.0)]
     + [plant(0x060C3C00 + 4 * k, 2, [20, 40, 0], 0.85) for k in range(4)] + [plant(0x060C3C00 + 4 * k + 2, 2, [10, 0, 30], 0.9) for k in range(4)]
     + [plant(0x060C3C00 + 4 * 4, 2, [0], 1.0)])

# 2B7CA: the next free one of twelve slots after cur, with the taken ones named by the entries from 060C0640
case("f0602B7CA", [span(-2, 12)], True,
     [plant(0x060C1044, 1, [0, 3, 10, 12, 12]), plant(0x060C1040, 4, [0, 4])]
     + [plant(0x060C0640 + i, 1, [3, 3, 0, 1], 0.9) for i in range(12)] + [plant(0x060C064A + i, 1, [i, i, i, 5, 11], 0.95) for i in range(12)])

# 319AC: a circular list of 16-byte nodes kept in order of the key word at 4, node 0 being the head; the count is at 060C1244
case("f060319AC", [pick(0, 5, 100, 0x2222, 7), pick(1, 2), pick(3, 4), pick(0x12, 0x34)], True,
     [plant(0x060C1244, 1, [0, 1, 2, 3, 3, 5])]
     + [plant(KEYED(k) + 4, 4, [0, 3, 5, 100, 0x2222, 0x3333, 7], 0.5) for k in range(1, 30)]
     + [plant(KEYED(k) + 1, 1, [0, k + 1, k + 1, 2], 0.9) for k in range(30)]
     + [plant(KEYED(k), 1, [0, max(k - 1, 0), 3], 0.9) for k in range(30)])

# 35C38: the next free-looking entry of the 30 at 060EC478 that shares its halfword at 0 with entry id
case("f06035C38", [span(-2, 31)], True,
     [plant(ent(k) + 12, 4, [0, -1, 0x7FFFFFFF, 0x80000000, 5, 0], 0.85) for k in range(30)] + [plant(ent(k), 2, [1, 2, 1, 1], 0.95) for k in range(30)])

SP = 0x060FFFF0            # the stack pointer at entry; arguments after the fourth sit above it


# 37D02: claims a free slot of the 15 records at 060EC748 for the entry the other three arguments name
case("f06037D02", [span(-2, 17), pick(0x1234, 0), pick(5, 6), pick(7, 8)], True,
     [plant(SP + 2, 2, [1, 2, 1])] + [plant(ent(k) + 12, 4, [0, 0, -1], 0.9) for k in range(30)] + [plant(ent(k), 2, [5, 6], 0.9) for k in range(30)]
     + [plant(ent(k) + 2, 2, [7, 8], 0.9) for k in range(30)] + [plant(ent(k) + 4, 2, [1, 2], 0.9) for k in range(30)]
     + [plant(0x060EC748 + 24 * k + 20, 4, [0, 7, 7, 7, 7, 7, 7, 7, 7, 7], 1.0) for k in range(15)])

# 39C28: fills a table of 224 pairs at the pointer in its seventh argument, from the sixth (a row count) and the fifth
case("f06039C28", [pick(0, 50, 100, 300), pick(1, 20, -5, 0, 60, 300), pick(0, 40, 200), pick(-3, 0, 1, 5, 30, 100, 224, 300)], False,
     [plant(SP + 2, 2, [0, 3, 100]), plant(SP + 6, 2, [-2, 0, 5, 40, 100, 224, 225, 300]), plant(SP + 8, 4, [0x060C4000], 1.0)])

case("f0603B4B2", [], False, TASKP + [plant(0x060D7E64, 4, [obj(3)], 1.0), plant(obj(3) + 68, 2, [0, 5, 0xFFFD, 3])])

# 4271C: five objects named by the task's halfwords 8 to 16 slide left, and are reset once they pass -464
case("f0604271C", [], False,
     TASKP + [trec(8 + 2 * k, 2, [3 + k, 3 + k, 8], 1.0) for k in range(5)] + [trec(18, 2, [0, 1, 5, 6, 2]), trec(20, 2, [0, 100, 0xFF00, 5000]), plant(0x060C02DC, 4, [0, 50, 0xFFFFFF00])]
     + [plant(obj(i) + 36, 2, [0, 0xFE00, 0xFE30, 0xFE2F, 5, 0xFFFF, 0xF000], 0.9) for i in range(3, 9)])

case("f0604ABAC", [pick(3, 4), pick(100, -100, 0x4000), pick(50, -3, 0), pick(0, 128, 5, 64, 0x1FF)], False, [plant(SP + 2, 2, [0, 128, 0x40, 5, 0x80, 0xFF])])
# 4FC96: compares four bytes at 060C17AA with a checksum of the six at 060C17A4, which is 0, 0, 0, FF when they are all zero
case("f0604FC96", [], True, [plant(0x060C17A4 + k, 1, [0], 0.9) for k in range(6)] + [plant(0x060C17AA + k, 1, [0, 0, 1], 0.85) for k in range(3)]
     + [plant(0x060C17AD, 1, [0xFF, 0xFF, 0], 0.85)])
case("f06052DBA", [pick(obj(3), obj(4)), pick(0, 1, 0x10000, 5)], False,
     [plant(obj(3) + o, 2, [3, 4, 5, 0, 7], 0.9) for o in (10, 12, 14, 16, 18)] + [plant(obj(4) + o, 2, [3, 4, 5, 0, 7], 0.9) for o in (10, 12, 14, 16, 18)]
     + [plant(0x060C17F0, 1, [0, 2, 3, 5, 6, 8, 9, 20])])
case("f06052F3C", [], False,
     [plant(0x26006096, 2, [1, 2, 5, 9, 0, 3]), plant(0x060C1040, 4, [0, 0x10, 0x20, 0x30, 0x40, 0x50, 0x70, 0x1234])]
     + [plant(0x060B6BFC + 4 * k, 4, [1, 2, 5, 9, 0, 3], 0.8) for k in range(8)])

# CA6A turns an object's position into a cell: with the offsets at 060D82BA planted as 0 and the stage limits, obj(3) at (160, 240) is cell
# 38A, obj(4) at (176, 320) is 4CB and obj(5) at (200, 100) is 14D
CELLOF = (STAGE + [plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0)]
          + [plant(obj(3) + 16, 2, [160], 1.0), plant(obj(3) + 18, 2, [240], 1.0), plant(obj(4) + 16, 2, [176], 1.0), plant(obj(4) + 18, 2, [320], 1.0),
             plant(obj(5) + 16, 2, [200], 1.0), plant(obj(5) + 18, 2, [100], 1.0)])
# 5F0A6: the first of five task slots (24 bytes from 060D7B60) whose object stands on bomber n's cell with its halfword at 50 in 88 to 95
case("f0605F0A6", [span(0, 3)], True,
     CELLOF + [plant(0x060D7B60 + 24 * k + 8, 2, [0, 3, 4, 5, 3, 4], 0.9) for k in range(5)]
     + [plant(obj(i) + 50, 2, [88, 90, 95, 96, 87, 50], 0.9) for i in (3, 4, 5)] + bom(20, 2, [0x38A, 0x4CB, 0x14D, 0], 0.95, range(4)))

case("f06062AF0", [], False, TASKP + [trec(10, 2, [0, 100, 253, 254, 255, 300])])

# 6BD74 and 6BE44 try 0606BEBC / 0606BF00 on the current bomber's twin, and 6BF22 and the rest try each of the first two bombers
HANDS = (CUR + bom(64, 2, [0, 1], 0.95, (0,)) + bom(4, 1, [0, 0, 0x80], 0.9, (0, 1)) + [plant(0x060C1F42 + 12 * k + 10, 2, [0, 0, 1], 0.9) for k in range(4)]
         + [plant(0x060C1F42 + 12 * k + 8, 2, [0, 1, 2, 3, 4], 0.9) for k in range(4)] + [plant(0x060C1F42 + 12 * k + o, 2, [0, 1, 0xFFFF, 3], 0.7) for k in range(4) for o in (0, 2, 4, 6)])
# 6BB4C and its kin: four steps round the direction word at 060C1F24, each trying 0606B648
case("f0606BB4C", [], True, CUR + bom(65, 1, [0, 1, 2], 0.9, (0,)) + [plant(0x060C1F42 + 12 * k + o, 2, [0, 3, 5, 8], 0.8) for k in range(4) for o in (4, 6)]
     + [plant(0x060C1F24, 2, [0, 1, 2, 3, 4])])
case("f0606BC4A", [], True, HANDS + [plant(0x060C1F24, 2, [0, 1, 2, 3, 4])])
case("f0606BC7E", [], True, HANDS + [plant(0x060C1F24, 2, [0, 1, 2, 3, 4])] + [plant(0x060C1F38 + 2 * k, 2, [0, 1, 2, 0xFFFF], 0.8) for k in range(8)])

case("f0606BD74", [], True, HANDS)
case("f0606BE44", [], True, HANDS)
case("f0606C006", [pick(0, 1, 5), pick(0, 1, 5)], True, HANDS)

STEP4 = [plant(0x060B90A0 + 2 * k, 2, [v], 1.0) for k, v in enumerate([0, 1, 64, -1, -64, 0])]
# 6C192: the first two bombers' cells, read by the sign of one halfword when the other is 0, by the current bomber's byte 6
case("f0606C192", [], True,
     CUR + bom(6, 1, [1, 2, 3, 4, 0], 0.97, (0,)) + bom(4, 1, [0, 0, 0xC0], 0.9, (0, 1))
     + [plant(0x060C1F42 + 12 * k + o, 2, [0, 0, 1], 0.9) for k in range(2) for o in (8, 10)]
     + [plant(0x060C1F42 + 12 * k + o, 2, [5, 0xFFFB, 0, 7], 0.9) for k in range(2) for o in (0, 2)])
# 6C390 and the walks beside it: step along a direction from the current cell until a flag word has bit 5 or a bit of cur+18
WALK2 = NAV + STEP4 + bom(6, 1, [1, 2, 3, 4, 1, 2], 0.97, (0,)) + bom(18, 2, [0, 0x80, 0x10, 0x4000, 0], 0.9, (0,))
case("f0606C390", [pick(0, 1, 2, 3, 10, 0x100)], True, WALK2)
case("f0606C4C0", [], True, WALK2)
case("f0606C584", [], True, WALK2 + [plant(0x060C1F32, 2, [0, 2, 4])])
case("f0606C640", [], True, WALK2 + [plant(0x060C1F32, 2, [0, 1, 2, 3, 4]), plant(0x060C1F34, 2, [320, 321, 5])])
# 6C9BE: a bomber from 10 up whose position lies within a window about the current bomber's
case("f0606C9BE", [pick(-30, 0, -5), pick(30, 5, 0), pick(-30, 0, -5), pick(30, 5, 0)], True,
     CUR + bom(22, 2, [0, 1, 1], 0.9, range(10, 50)) + bom(4, 1, [0, 0, 0xC0], 0.9, range(10, 50)) + bom(24, 2, [100, 90, 110, 120, 70], 0.9, range(0, 50))
     + bom(28, 2, [100, 90, 110, 120, 70], 0.9, range(0, 50)) + [plant(0x060C062C, 2, [0, 10, 11, 20])])
case("f060733DE", [], True,
     NAV + bom(42, 2, [0x2000, 0x2000, 0], 0.9, (0,)) + bom(18, 2, [0, 0x80, 0x10, 0x4000], 0.9, (0,))
     + [plant(0x060B90A2 + 2 * k, 2, [v], 1.0) for k, v in enumerate([1, 64, -1, -64])])
case("f0607612C", [], True,
     NAV + bom(66, 2, [0, 1, 2, 4, 8, 15], 0.9, (0,)) + [plant(0x060BA7AA + 2 * k, 2, [v], 1.0) for k, v in enumerate([-126, -62, 2, 63, 64, 65, -130, -66, -2, -193, -192, -191])])

case("f0607F50A", [pick(1, 2, 5, -3, 0x100, 16)], True,
     CUR + [plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0), plant(0x060C28A0, 2, [100, 0, 0xFF00]), plant(0x060C28A2, 2, [100, 0, 50])]
     + bom(24, 2, [100, 0, 200, 0xFF00], 0.9, (0,)) + bom(28, 2, [100, 0, 200, 50], 0.9, (0,)))
# 8A72A: picks one of eight directions open from the mover's position (x at 16, y at 18) and gives the distance to the edge
case("f0608A72A", [], True,
     CUR + [plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0)]
     + [plant(obj(i) + 16, 2, [5, 20, 100, 159, 160, 200, 0x12F, 0x130, 0x200, 0x300, 0x1A0, 0xFF00, 0x7000], 0.95) for i in (3, 4)]
     + [plant(obj(i) + 18, 2, [5, 20, 31, 32, 100, 111, 112, 207, 208, 300, 0x200, 0x120, 0xFF00, 0x7000], 0.95) for i in (3, 4)] + [plant(0x060D7768, 4, [bomber(0)], 1.0)])
# 8AA18: tries the four neighbours of a cell in the table at 060C2F00 and marks it 4000 when none works
ARR2 = 0x060C4400
case("f0608AA18", [span(0, 8), span(0, 5), pick(0), pick(0, 1, 5)], True,
     [plant(0x060C2F00, 4, [ARR2], 1.0)] + [plant(ARR2 + 2 * c, 2, [0, 0, 0x50B0, 0x8000, 0x10, 0x4000, 0x1000], 0.8) for c in range(-70, 80)]
     + [plant(0x060C2EFE, 2, [0x1234, 0, 5])]
     + [plant(0x060B90A0 + 2 * k, 2, [v], 1.0) for k, v in enumerate([0, 1, 64, -1, -64, 0])]
     + [plant(0x060B90B4 + 2 * k, 2, [v], 1.0) for k, v in enumerate([0, 3, 4, 1, 2, 0])])
case("f06091848", [], False,
     CUR + bom(24, 2, [400, 416, 432, 480, 600, 700], 0.95, (0,)) + bom(28, 2, [440, 448, 460, 500, 560, 700, 0], 0.95, (0,)))

# 34D90 ranks up to 255 entries; the three arrays here are small and sometimes overlap, which the order of its swaps must survive
case("f06034D90", [span(0, 16), pick(0x060C0100), pick(0x060C0200, 0x060C0230, 0x060C0210), pick(0x060C0220, 0x060C0240, 0x060C0200, 0x060C0222)], False)
