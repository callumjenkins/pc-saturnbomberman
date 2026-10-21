import os

from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

_ROOT = os.path.dirname(os.path.abspath(__file__))
while not os.path.exists(os.path.join(_ROOT, "build", "extract", "BOMSS", "0KRNL.BIN")):
    _ROOT = os.path.dirname(_ROOT)
with open(os.path.join(_ROOT, "build", "extract", "BOMSS", "0KRNL.BIN"), "rb") as _f:
    _IMG = _f.read()


def image(lo, hi):
    """The image's own words in [lo, hi), which a random trial overwrites."""
    return [plant(a, 4, [int.from_bytes(_IMG[a - 0x06006000:a - 0x06006000 + 4], "big")], 1.0) for a in range(lo & ~3, hi, 4)]

FIX = 0x060C0100
FALL = 0x060C2600
PATH = 0x060C4000
CUR = [plant(0x060D7768, 4, [bomber(0), bomber(1), bomber(2)], 1.0)]
MOV = [plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0)]
FALLP = [plant(0x060C1658, 4, [FALL], 1.0)]
# The tables the image keeps, which random trials overwrite.
TABLES = (image(0x060B90A0, 0x060B9140) + image(0x060B957C, 0x060B95BC) + image(0x060BA050, 0x060BA0A0)
          + image(0x060BA7D0, 0x060BA800) + image(0x060BB6A8, 0x060BB6E0) + image(0x060B11A4, 0x060B11D8)
          + image(0x060B1224, 0x060B1260) + image(0x060B12CC, 0x060B12D8) + image(0x060B12F8, 0x060B1320))


def cur(offset, size, values, chance=0.9):
    """A field of the bomber records CURRENT points at."""
    return [plant(bomber(k) + offset, size, values, chance) for k in (0, 1, 2)]


def mov(offset, size, values, chance=0.9):
    """A field of the objects MOVER points at."""
    return [plant(obj(k) + offset, size, values, chance) for k in (3, 4)]


# A bomber at a cell, to walk the flag tables from.
CELL = cur(20, 2, [0, 1, 0x20, 0x100, 0x2F0, 0x400, 0x5FF], 1.0)

case("f060354C0", [], True, [plant(0x060C164C, 4, [0x060C2000, 0x060C2100], 1.0)])
case("f060387EC", [span(1, 40), ptr(0x060C2000, 0x400, 2)], True)
case("f0603A45A", [], True, FALLP + [plant(FALL + 10, 2, [0, 1, 5, 30], 0.9)])
case("f0605B960", [], True, FALLP)
case("f0605BC9A", [], True, FALLP)

case("f06068B32", [pick(FIX)], False,
     [plant(FIX + 56, 4, [0x060C2000, 0x060C2100], 1.0), plant(FIX + 52, 4, [0x060C2200], 1.0),
      plant(0x060C2000, 2, [0xFFFF, 0, 5], 0.6), plant(0x060C2100, 2, [0xFFFF, 1, 0xFFFF], 0.6)])
case("f06068B62", [pick(FIX)], True,
     [plant(FIX + 56, 4, [0x060C2000], 1.0), plant(FIX + 60, 2, [0, 0x300, 0xFF00, 0x1200], 0.9)]
     + [plant(0x060C2000 + 4 * k, 2, [0xFFFF, 0, 7, 3, 0xFFFF], 0.5) for k in range(6)]
     + [plant(0x060C2002 + 4 * k, 2, [1, 5, 300, 0xFFFF, 0xFE], 0.5) for k in range(6)])

case("f0606B5DC", [], True, CUR + cur(52, 2, [0, 1, 2, 3, 4, 5]) + sum([[plant(bomber(k) + 4, 1, [0, 0, 0x40, 0x80, 0xC0]),
     plant(bomber(k) + 22, 2, [0, 3, 4, 100])] for k in range(6)], [])
     + [plant(obj(i), 4, [0, 0, 7], 0.5) for i in range(1, 8)])
case("f0606BC16", [], False, [plant(0x060C1F5C, 4, [0x060C2000, 0x060C2100], 1.0), plant(0x060C2000, 2, [0, 0x8000, 5], 0.8),
                                plant(0x060C2100, 2, [0, 0x8000, 5], 0.8)])
case("f0606BC2E", [], False, [plant(0x060C1F5C, 4, [0x060C2000, 0x060C2100], 1.0), plant(0x060C2002, 2, [0, 0x8000, 5], 0.8),
                                plant(0x060C2102, 2, [0, 0x8000, 5], 0.8)])

# The CD driver's work area: FIX holds a pointer to D, D+0x140 one to V.
D = 0x060C5000
V = 0x060C6000
CTX = [plant(FIX, 4, [D], 1.0), plant(D + 0x140, 4, [V], 1.0), plant(0x060BB994, 4, [0], 1.0), plant(0x060FC228, 4, [0], 1.0)]


def sf(offset, values, chance=0.9, base=52):
    """A word of the work area, at offset from D + base."""
    return plant(D + base + offset, 4, values, chance)


def vf(offset, values, chance=0.9):
    return plant(V + offset, 4, values, chance)


RING = [sf(72, [0, 10, 100, 1000]), sf(76, [0, 50, 500]), sf(80, [0, 90, 400, 1000]), sf(84, [0, 20, 700]),
        sf(92, [100, 500, 1000]), sf(100, [10, 100, 300]), sf(4, [0, 1, 2, 3, 4, 5])]
RING48 = [sf(60, [0, 10, 100], 0.9, 48), sf(64, [0, 50, 500], 0.9, 48), sf(68, [100, 500, 1000], 0.9, 48),
          sf(72, [0, 90, 400, 1000], 0.9, 48), sf(76, [0, 20, 700], 0.9, 48), sf(4, [0, 1, 2, 3, 4, 5], 0.9, 48),
          sf(40, [0, 4, 9, 16], 0.9, 48), sf(92, [100, 500, 1000], 0.9, 48), sf(96, [0, 50, 800], 0.9, 48),
          sf(104, [0, 50, 500], 0.9, 48), sf(108, [0, 50, 500], 0.9, 48)]

case("f060A029A", [pick(0, 3, 7, 9, 50, 120)], True,
     [plant(0x060FBFFC, 4, [0x060C7000], 1.0), plant(0x060C7000, 4, [0x060C7100, 0], 1.0),
      plant(0x060C7004, 2, [0, 3, 7, 50, 120], 1.0), plant(0x060C7100, 4, [0], 1.0), plant(0x060C7104, 2, [1, 4, 9, 60], 1.0)])
case("f060A046C", [span(0, 5), span(0, 5), pick(0x060C8000)], False)
case("f060A0732", [ptr(0x060C2000, 0x100, 1), span(0, 3), ptr(0x060C3000, 0x40, 1)], True)
case("f060A0A0A", [span(0, 4), span(0, 4), pick(0, 0x060C8000)], True)
case("f060A1300", [pick(FIX)], True,
     [plant(FIX + 36, 4, [0, 0, 0, 0, 1, 5], 1.0), plant(FIX + 28, 4, [0, 0x060C2000], 1.0), plant(0x060C2014, 4, [0, 1, 20], 0.9),
      plant(FIX + 32, 4, [0, 1, 50, 100], 0.9), plant(FIX + 56, 2, [0, 1], 0.9)])
case("f060A15BC", [pick(FIX)], True, [plant(FIX + 16, 4, [0x060C2000], 1.0), plant(0x060C2078, 4, [0, 1, 5], 0.9)])
case("f060A1B68", [pick(FIX), span(-3, 5), span(-3, 50), pick(0, 1, 2)], True,
     [plant(FIX + 20, 4, [0, 5, 40], 0.9), plant(FIX + 56, 2, [0, 2], 0.9), plant(FIX, 4, [0], 1.0),
      plant(FIX + 12, 4, [0x060C2000], 1.0), plant(0x060C2014, 4, [0, 10, 100], 1.0)])
# With a callback pointer that matches, the loop waits on a DMA channel's status bit, which is random
# in the cosim and often never set: the host build would spin for ever. So the pointer never matches.
case("f060A3250", [pick(FIX)], False, CTX + [plant(D + 0x154, 4, [0, 1, 1], 1.0), plant(D + 0x168, 4, [0, 5], 1.0)])
case("f060A3C1A", [pick(0, FIX), span(0, 5)], False, CTX + [sf(4, [0, 1, 4, 2], 1.0)])
case("f060A3D00", [pick(0, FIX), span(0, 10), span(-2, 10)], False, CTX)
case("f060A3DBE", [pick(0, FIX)], True, CTX)
case("f060A3DF0", [pick(0, FIX)], True, CTX)
case("f060A3E6C", [pick(0, FIX)], False, CTX)
case("f060A4014", [pick(0, FIX), span(0, 5)], False, CTX)
case("f060A41E2", [pick(0, FIX)], False, CTX + [plant(D + 0x18C, 4, [0, 1, 1], 1.0)])
case("f060A47FE", [pick(0, FIX)], False, CTX + [sf(4, [4, 0, 1], 1.0, 48)])
case("f060A48A8", [pick(0, FIX), span(0, 500)], False, CTX + [sf(40, [0, 4, 9, 16], 1.0, 48)])
case("f060A4AF4", [pick(0, FIX)], True, CTX)
case("f060A5058", [ptr(0x060C2000, 0x100, 1), ptr(0x060C3000, 0x100, 1)], False)
MASK = [plant(FIX + 36, 4, [0x3FF, 0xFF, 0x101, 0x200, 0, 0x2FF, 0x8, 0x1F0, 0x80, 0x7F, 0x300], 1.0)]
case("f060A51F4", [pick(FIX), span(0, 3)], False, MASK)
case("f060A52E8", [span(0, 3)], False)
case("f060A532A", [span(0, 3)], True)
case("f060A5338", [pick(FIX), span(0, 3)], False, MASK)
case("f060A56FA", [span(0, 30), ptr(0x060C2000, 0x100, 1)], True)
case("f060A589C", [ptr(0x060C2000, 0x40, 4), ptr(0x060C3000, 0x80, 4)], False, [plant(0x060FA8BC, 4, [0x060C7000], 1.0)])
case("f060A5E26", [ptr(0x060C2000, 0x40, 4), ptr(0x060C3000, 0x80, 4)], False)
case("f060A61E2", [pick(FIX), pick(0), span(0, 5), span(0, 5)], False,
     [plant(FIX + 108 + 44, 4, [0, 1, 2, 3, 10], 1.0), plant(FIX + 108 + 20, 4, [1, 5, 100], 0.9),
      plant(FIX + 108 + 24, 4, [10, 200], 0.9), plant(FIX + 108 + 28, 4, [0, 5], 0.9), plant(FIX + 108 + 32, 4, [0, 7, 50], 0.9),
      plant(0x060C2008, 4, [20, 300, 1000], 0.9), plant(FIX + 40, 4, [3, 4, 5, 3, 4], 1.0), plant(FIX + 108 + 12, 4, [0, 0, 0, 0x060C2000], 1.0)] + TABLES)
case("f060A625E", [pick(FIX)], False,
     [plant(FIX + 44, 4, [0, 1, 2, 5], 1.0), plant(FIX + 12, 4, [0x060C2000], 1.0), plant(0x060C2008, 4, [20, 300, 1000], 0.9),
      plant(FIX + 32, 4, [0, 7, 50], 0.9), plant(0x060FA8BC, 4, [0x060C7000], 1.0)])
case("f060A6724", [pick(FIX), span(0, 50)], True,
     [plant(0x060FA8BC, 4, [0x060C7000], 1.0), plant(0x060C7000 + 0x44C + 16, 4, [0, 1, 0], 1.0)])
case("f060A674C", [pick(FIX), pick(FIX + 0x200)], False, [plant(FIX + 56, 4, [0, 4, 4, 2], 1.0)])
case("f060A750A", [pick(FIX)], True, [plant(FIX + 28, 4, [0, 5, 77], 1.0), plant(0x060FC084, 4, [0x060C7000], 1.0),
                                         plant(0x060C7000 + 48, 4, [0, 1], 1.0), plant(0x060C7000 + 56, 4, [0, 5, 77], 1.0)])
case("f060A7516", [pick(FIX)], False, [plant(FIX + 28, 4, [0, 5, 77], 1.0), plant(0x060FC084, 4, [0x060C7000], 1.0),
                                          plant(0x060C7000 + 48, 4, [0, 1], 1.0), plant(0x060C7000 + 56, 4, [0, 5, 77], 1.0)])
case("f060AA976", [pick(FIX)], True, [plant(FIX + 16, 4, [0x060C2000], 1.0)])
case("f060AB1B0", [pick(FIX), ptr(0x060C2000, 16, 4), ptr(0x060C2100, 16, 4), ptr(0x060C2200, 16, 4)], False, CTX + RING)
case("f060AB228", [pick(FIX), span(-20, 300)], False, CTX + RING)
case("f060AB268", [pick(FIX), pick(0x060C8F00, 0x100), span(0, 0x300)], False,
     CTX + [sf(92, [0x060C9000, 0x060C8000, 100], 0.9), sf(88, [0x060CA000], 1.0)])
case("f060AB2BC", [pick(FIX), span(-20, 300)], False, CTX + RING)
case("f060AB2F2", [pick(FIX), span(-20, 300)], False, CTX + RING + [sf(160, [0, 1, 0], 1.0)])
case("f060AB324", [pick(FIX)], True, CTX)
case("f060AB32C", [pick(FIX)], False, CTX)
case("f060AB338", [pick(FIX)], False, CTX + RING + [sf(156, [0, 1, 1], 1.0), sf(160, [0, 1, 1], 1.0), sf(172, [0, 1, 2, 3], 1.0),
                                                      sf(112, [0, 10, 20], 1.0), sf(116, [0, 0x060C2000, 0x060C2100], 0.8),
                                                      plant(D + 32, 4, [0x060C2000, 0x060C2100, 0], 0.8),
                                                      plant(V + 38, 1, [8, 16, 0], 1.0)]
     + [sf(176 + 12 * k + o, [0x060C2000, 0x060C2100, 5, 0x060C2300], 0.7) for k in range(4) for o in (0, 4, 8)])
# 060AB456 calls f060AB338 until word 160 clears, which never happens when that returns early.
case("f060AB49C", [pick(FIX), span(0, 5), span(0, 5), span(0, 5)], False, CTX + [sf(4, [4, 5, 1, 0], 1.0), sf(160, [0], 1.0)])
case("f060AB804", [pick(FIX)], True, CTX + RING
     + [plant(D, 4, [0x060C9000], 1.0), plant(0x060C9000, 4, [0x46494C4D], 1.0), plant(V + 4, 4, [10, 100, 400], 1.0), sf(100, [500, 100, 50], 1.0), sf(72, [0, 4, 8, 100, 600, 8, 100], 1.0),
        sf(20, [0, 1], 0.8), plant(D + 20, 4, [1, 5, 0], 1.0), sf(52, [0, 0, 3], 1.0), sf(104, [0, 50, 600], 1.0), plant(D + 4, 4, [500, 3000, 100], 1.0), vf(60, [0, 1, 2, 3], 1.0),
        vf(68, [0, 5, 100], 1.0), plant(V + 37, 1, [0, 1], 1.0), plant(V + 36, 1, [0, 5], 1.0), plant(V + 38, 1, [8, 16], 1.0)]
     + [plant(V + 64 + 16 * k + o, 4, [-1, 0, 5, 100, 0x12345], 0.6) for k in range(4) for o in (4, 8)])
case("f060AC62E", [pick(FIX)], True, CTX + [sf(64, [0, 0, 1], 1.0), sf(12, [0, 1, 2], 1.0), vf(60, [0, 1, 2, 3], 1.0), sf(20, [0, 10], 1.0),
                                              sf(72, [0, 50, 500], 1.0)]
     + [plant(V + 64 + 16 * k + o, 4, [-1, 0, 5, 100], 0.7) for k in range(4) for o in (0, 4, 8)])
case("f060ACC02", [pick(FIX)], True, CTX + [sf(4, [-1, 0, 1, 2, 3, 4, 5, 9], 1.0), sf(152, [1, 2, 7, 100], 1.0), sf(124, [1, 5, 33], 1.0),
                                              sf(128, [0, 4], 1.0)])
case("f060ACCB2", [pick(FIX), ptr(0x060C2000, 16, 4), ptr(0x060C2100, 16, 4)], False,
     CTX + [sf(4, [-1, 0, 1, 2, 3, 4, 5, 9], 1.0), sf(48, [0, 1], 1.0), sf(0xE4, [100, 5000], 0.9), sf(0xE0, [0, 20], 0.9),
            sf(0x90, [100, 5000], 0.9), sf(0x8C, [0, 20], 0.9), sf(124, [1, 5, 33], 1.0), vf(56, [1, 7, 100, 2000], 1.0),
            plant(0x060FC0E4, 4, [100, 5000], 0.9)])
case("f060AD4B8", [pick(FIX)], True, CTX + [sf(4, [-1, 0, 1, 2, 3, 4, 5, 9], 1.0, 48), sf(124, [1, 5, 33], 1.0, 48), sf(44, [1, 7, 100], 1.0, 48),
                                              sf(100, [0, 4], 1.0, 48)])
case("f060AD5C8", [pick(FIX), ptr(0x060C2000, 16, 4)], False, CTX + [sf(4, [-1, 0, 1, 2, 3, 4, 5, 9], 1.0, 48), sf(116, [0, 7, 100], 1.0, 48)])
case("f060AD672", [pick(FIX), span(0, 2000)], False, CTX + [sf(40, [0, 4, 9, 16], 1.0, 48)])
case("f060AD88C", [pick(FIX)], False, CTX)
case("f060ADBA8", [pick(FIX), ptr(0x060C2000, 16, 4), ptr(0x060C2100, 16, 4), ptr(0x060C2200, 16, 4)], False,
     CTX + RING48 + [plant(D + 8, 4, [10, 100, 500], 1.0)])
case("f060ADBF6", [pick(FIX), span(-5, 300)], False, CTX + RING48 + [plant(D + 8, 4, [10, 100, 500], 1.0)])
case("f060ADC2A", [pick(FIX), span(-5, 300)], False, CTX + RING48 + [plant(D + 8, 4, [10, 100, 500], 1.0)])
case("f060ADC82", [pick(FIX)], False, CTX)
case("f060ADC8C", [pick(FIX)], False, CTX + [sf(4, [4, 5, 3, 4], 1.0, 48)])
case("f060AE2FC", [pick(FIX)], True, CTX + [sf(60, [0, 5, 5, 9], 1.0, 48), sf(64, [0, 5, 7], 1.0, 48), sf(48, [-1, 5, 500, 9], 1.0, 48),
                                              sf(104, [0, 50, 700], 1.0, 48)])
case("f060B0030", [pick(FIX), span(0, 300)], False, CTX + [sf(120, [0, 50, 100, 600], 1.0), sf(116, [100, 500], 1.0), sf(112, [0, 100, 400], 1.0),
                                                              plant(V + 38, 1, [8, 16], 1.0)])
case("f060B086C", [pick(FIX), span(0, 2000)], False, CTX)
case("f060B0C30", [pick(FIX), span(-10, 300)], False, CTX + [sf(40, [0, 4, 9, 16], 1.0, 48), sf(96, [0, 50, 100], 1.0, 48), sf(92, [100, 500], 1.0, 48)])

TSK = [plant(0x060D7E60, 4, [slot(3), slot(4)], 1.0), plant(0x060D7E64, 4, [obj(3), obj(4)], 1.0)]
DIRS = CUR + CELL + TABLES + cur(18, 2, [0, 0x20, 0xFFFF, 0x30, 1]) + [plant(0x060C1F32, 2, [1, 2, 3, 4], 0.9)]
STEP = CUR + CELL + TABLES + cur(65, 1, [0, 1, 2, 3, 4, 0xFF, 0xFE]) + cur(44, 2, [0, 1]) + cur(18, 2, [0, 0x20, 0xFFFF, 0x30, 1]) \
    + [plant(0x060C1F24, 2, [0, 1, 2, 3, 4], 0.9), plant(0x060C1F5C, 4, [0x060C2000], 0.3)]

case("f0606C4FA", [], True, DIRS)
case("f0606C5D6", [], True, DIRS)
case("f0606C5EA", [], True, DIRS + cur(6, 1, [0, 1, 2, 3, 4]))
case("f0606C982", [], True, CUR + CELL + TABLES)
case("f06085CAE", [], True, CUR + CELL + TABLES)
case("f0606D920", [], True, STEP)
case("f0606D93E", [], True, STEP)
case("f0606BBDA", [], False, STEP + [plant(0x060C1F5C, 4, [0x060C2000, 0x060C2100], 1.0), plant(0x060C2000, 2, [0, 0x8000, 5], 0.8),
                                       plant(0x060C2100, 2, [0, 0x8000, 5], 0.8)])
case("f0606BBF8", [], True, STEP + [plant(0x060C1F5C, 4, [0x060C2000, 0x060C2100], 1.0), plant(0x060C2000, 2, [0, 0x8000, 5], 0.8),
                                      plant(0x060C2100, 2, [0, 0x8000, 5], 0.8), plant(0x060C2002, 2, [0, 0x8000, 5], 0.8)])
case("f0606E9C8", [span(0, 4), span(0, 4), span(0, 4), span(0, 4)], True,
     CUR + MOV + TABLES + cur(46, 2, [0, 1, 2, 0, 1, 2, 3], 1.0) + [plant(0x060C062C, 2, [0, 1, 2, 3], 0.9)] + mov(52, 4, [0x060C2000, 0x060C2100], 1.0) + mov(56, 4, [0x060C2000, 0x060C2100], 1.0) \
     + [plant(0x060C2000 + 2 * k, 2, [0xFFFF, 0, 1, 5, 0x100], 0.5) for k in range(0x80)] + [plant(0x060C2100 + 2 * k, 2, [0xFFFF, 0, 1, 5, 0x100], 0.5) for k in range(0x80)] + cur(6, 1, [0, 1, 2], 1.0) + [plant(0x060C1F2E, 2, [0, 1, 2], 1.0)] + cur(80, 2, [0, 1, 2], 1.0) + mov(50, 2, [0, 1, 2, 3, 4, 5, 8, 9], 1.0))
case("f0606F770", [pick(0), span(0, 4), span(0, 4), span(0, 4)], True,
     CUR + MOV + TABLES + cur(46, 2, [0, 1, 2, 0, 1, 2, 3], 1.0) + cur(60, 2, [0, 1, 5]) + mov(48, 2, [0, 4, 8, 3])
     + [plant(0x060C062C, 2, [0, 1, 2, 3], 0.9)] + mov(52, 4, [0x060C2000, 0x060C2100], 1.0) + mov(56, 4, [0x060C2000, 0x060C2100], 1.0) \
     + [plant(0x060C2000 + 2 * k, 2, [0xFFFF, 0, 1, 5, 0x100], 0.5) for k in range(0x80)] + [plant(0x060C2100 + 2 * k, 2, [0xFFFF, 0, 1, 5, 0x100], 0.5) for k in range(0x80)] + cur(6, 1, [0, 1, 2], 1.0) + [plant(0x060C1F2E, 2, [0, 1, 2], 1.0)] + cur(80, 2, [0, 1, 2], 1.0) + mov(50, 2, [0, 1, 2, 3, 4, 5, 8, 9], 1.0))
case("f0606F38C", [], True,
     CUR + MOV + TABLES + TSK + cur(74, 2, [0, 3, 4, 5], 1.0) + cur(52, 2, [0, 1, 2, 3, 4, 5], 1.0)
     + [plant(bomber(k) + 22, 2, [3, 4, 5, 6], 1.0) for k in range(6)] + [plant(bomber(k) + 6, 1, [0, 1, 2, 3, 4, 5, 6, 7], 1.0) for k in range(6)])
PATH_PLANTS = ([plant(0x060C2658, 4, [PATH], 1.0)]
               + [plant(PATH + 12 + 8 * k + o, 4, [0, 1, 2], 0.7) for k in range(8) for o in (0, 4)]
               + [plant(PATH + 80 + 8 * k + o, 4, [0, 100, 1000, -100, 5], 0.8) for k in range(8) for o in (0, 4)]
               + [plant(PATH + 8, 4, [0, 1, 2, 3, 4, 6], 1.0), plant(PATH + 76, 4, [0, 1, 2, 3, 5], 1.0)])
case("f060749D8", [], False, PATH_PLANTS)
case("f06074A22", [span(1, 6)], True, PATH_PLANTS)
case("f06074A7C", [], False, PATH_PLANTS)
case("f06076854", [span(0, 10), span(0, 10)], True, CUR + TABLES + cur(72, 2, [0, 1, 2, 3], 1.0))
case("f06077C08", [], True, STEP + cur(7, 1, [0, 1, 2, 3, 5], 1.0) + CELL + TABLES)
case("f0607D2A4", [], False, CUR + MOV)
case("f0607F3FC", [], False, CUR + MOV + TSK + CELL + TABLES + cur(66, 2, [0, 1], 1.0) + cur(24, 2, [0, 100, 300], 0.9) + cur(28, 2, [0, 100, 300], 0.9))
case("f0608255E", [], True, CUR + MOV + TSK + [plant(0x060C28A8, 2, [0, 1, 2, 3], 1.0)] + mov(70, 2, [0, 0x80, 0x100, 0x200], 0.9)
     + [plant(bomber(k) + 22, 2, [3, 4, 5, 6], 1.0) for k in range(6)])
case("f06083830", [], True, CUR + MOV + TSK + cur(68, 2, [0, 5, 100], 0.9))
case("f06084BD0", [], True, DIRS + cur(6, 1, [0, 1, 2, 3, 4])
     + [plant(0x060EC8B0 + 2 * c, 2, [0, 0, 0, 0x20], 0.5) for c in range(0x600)])
case("f06086BBE", [], True, CUR + CELL + TABLES + cur(18, 2, [0, 0x20, 0xFFFF, 0x30, 1]))
case("f060894F2", [], True, CUR + CELL + TABLES + cur(18, 2, [0, 0x20, 0xFFFF, 0x30, 1]))
case("f06086CEC", [], True, CUR + CELL + TABLES + cur(6, 1, [0, 1, 2, 3, 4]) + cur(18, 2, [0, 0x20, 0xFFFF, 0x30, 1])
     + [plant(0x060EE8B0 + 2 * c, 2, [0, 0xF00, 0x100, 0xE00], 0.5) for c in range(0, 0x600, 1)])
case("f0608A718", [], True, MOV + [plant(0x060C1AA8, 2, [0, 3, 4, 5], 1.0)])
case("f0608A944", [], False, [plant(0x060C2F00, 4, [0x060C8000, 0x060C9000], 1.0)])
case("f0608AF42", [span(0, 5)], False,
     [plant(0x060C31CC + 2 * k, 2, [0, 1, 2, 3, 4, 5], 1.0) for k in range(8)])
case("f0608F23E", [], False, CUR + MOV + TSK + cur(66, 2, [0, 1, 2, 3], 1.0))
case("f0608F83C", [], True, CUR + MOV + TSK + cur(66, 2, [0, 1, 2, 3, 4, 5, 6, 7], 1.0) + mov(16, 2, [-64, 0, 100, 0x180, 0x181, -65, 200], 0.9)
     + mov(18, 2, [0, 50, 0x100, 0x120], 0.9) + mov(38, 2, [0, 1, 0x20, 0x40], 0.9) + TABLES)
case("f0609360C", [], False, CUR + MOV + cur(66, 2, [0, 1, 2, 3], 1.0)
     + [plant(0x060C329A + 76 * k + 66 + o, 2, [0, 3, 4, 5, 6], 0.7) for k in range(6) for o in range(0, 10, 2)])
case("f06095158", [pick(FIX), pick(FIX, FIX + 1, FIX + 0x10), span(0, 12)], True, [plant(FIX + k, 1, [0, 0x61, 0x62, 0x61], 0.8) for k in range(0x30)])
case("f060957B0", [pick(FIX), pick(FIX + 0x100)], False, [plant(FIX, 4, [0, 1, 2, 3, 4], 1.0)])
case("f06096B9C", [], True, [plant(0x060FA8BC, 4, [0x060C7000], 1.0), plant(0x060C7000, 4, [0, 1, 3, 4, 18], 1.0)]
     + [plant(0x060C7000 + 0xC60 + 168 * k, 4, [0, 0, 1, 5], 0.6) for k in range(20)])
case("f06098700", [pick(FIX), span(-3, 3), pick(0x060C8000)], False)
case("f0609870C", [pick(FIX)], False, [plant(FIX + 4, 4, [0x060C8000], 1.0)] + TABLES)
case("f06099828", [], False,
     [plant(0x060FA97C, 1, [0, 1, 3, 6], 1.0), plant(0x060FA920, 4, [0x060C8000], 1.0), plant(0x060FA930, 4, [0x060C9000], 1.0),
      plant(0x060FA914, 4, [0, 1, 2, 5], 1.0), plant(0x060FA90C, 1, [0, 1, 2], 1.0), plant(0x060FA92C, 1, [0, 1, 2, 4], 1.0)])
case("f0609EEA8", [ptr(0x060C2000, 0x40, 2), span(0, 255)], False, [plant(0x060FBF50, 4, [0x060C8000], 1.0)])
case("f0609EF42", [ptr(0x060C8000, 0x400, 1), span(0, 64)], False)
case("f0609F004", [ptr(0x060C8000, 0x400, 1), ptr(0x060C9000, 0x400, 1), span(0, 64)], True)
case("f0609F464", [pick(FIX)], False,
     [plant(FIX + 6, 2, [0, 1, 3, 8], 1.0), plant(FIX + 12, 4, [0x060C8000], 1.0), plant(FIX + 2, 2, [0, 1, 5, 16], 1.0),
      plant(FIX, 2, [0, 1, 5, 16], 1.0), plant(FIX + 4, 2, [0, 2, 9], 1.0), plant(FIX + 8, 2, [0, 1, 3], 1.0),
      plant(FIX + 16, 4, [0x060C8800], 1.0), plant(FIX + 20, 4, [0x060CC000], 1.0), plant(0x060FBFB4, 4, [0x060CA000], 0.5)])
case("f0609F838", [span(0, 8)], False,
     [plant(0x060FBF84, 4, [0x060C8000], 1.0)] + [plant(0x060C8000 + 10 * k, 2, [0, 1, 7], 0.6) for k in range(9)])
case("f0609F88E", [], False,
     [plant(0x060FBF88, 4, [0, 1, 3, 8], 1.0), plant(0x060FBF84, 4, [0x060C8000], 1.0), plant(0x060FBFC0 + 24, 2, [0, 9], 1.0),
      plant(0x060FBFC0 + 20, 4, [0x060CA000], 1.0)])
for name in ("f0609FC04", "f0609FC50", "f0609FCA4"):
    case(name, [span(0, 5), ptr(0x060C2000, 0x40, 2)], False,
         [plant(0x060FC004, 4, [0x060CA000], 1.0), plant(0x060FBF98, 4, [0, 0, 0, 1], 1.0)])
case("f0606B07E", [ptr(0x060C2000, 0x80, 2), span(0, 20)], False)
case("f0603B368", [span(0, 30), span(0, 30), span(0, 100)], False,
     TSK + [plant(0x060D7E38, 2, [3, 4, 5], 1.0)]
     + [plant(slot(k) + o, 2, [3, 4, 5, 6, 7], 1.0) for k in (3, 4) for o in (8, 10, 12, 14, 16)])

