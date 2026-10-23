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


GREETING = b"Hi! Come come everybody. \x00"
SLOTBITS = [plant(0x060BBA9C + 4 * k, 4, [1 << k], 1.0) for k in range(32)]

# The offset tables SHC's shift routines jump through, which a random trial overwrites.
SHIFT_TABLES = image(0x060945C0, 0x06094800)

SP = 0x060FFFF0        # r15 on entry; the arguments a caller passed on the stack start here
BUF = 0x060C5000
CURRENT_PTR = 0x060D7768


def stack(k, values, chance=1.0):
    """The k-th word above the stack pointer the function is entered with."""
    return plant(SP + 4 * k, 4, values, chance)


# The VDP1 command list: the cursor, the record table and the pool all point at memory the check maps.
VDP1 = [plant(0x060FC004, 4, [BUF, BUF + 0x400], 1.0), plant(0x060FBF84, 4, [BUF + 0x800], 1.0),
        plant(0x060FBFD0, 4, [0, 0x1234], 0.8), plant(0x060FC008, 4, [0, 0x77], 0.8),
        plant(0x060FBF98, 4, [0, 0, 1], 1.0)]

# A sprite record the quad routines move; the draw call reads it again from the stack.
SPRITE = BUF + 0x1000
QUAD = [plant(0x060CBB5C, 4, [SPRITE], 1.0), plant(0x060C1B04, 4, [0, 5, 0x322, 0x323, 0x400], 1.0),
        plant(SPRITE + 42, 2, [0, 0x100, 0x120], 1.0), plant(SPRITE + 40, 2, [0, 8, 0x28, 0x38, 0xFFFF], 1.0)]
for _a in ("0606A4D4", "0606A6E8"):
    case("f" + _a, [], False, VDP1 + QUAD)

# A chain of the 84-byte objects: the link halfword at +8 ends at 1.
CHAIN = [plant(obj(k) + 8, 2, [1, k + 2], 1.0) for k in range(20)] + [plant(obj(k) + 8, 2, [1], 1.0) for k in range(20, 40)]
case("f0606AA58", [], False, CHAIN)
case("f0606AA90", [], False, CHAIN)
case("f0606AAC8", [pick(obj(3), obj(4)), span(0, 15)], False, [])
CUR = [plant(CURRENT_PTR, 4, [bomber(0), bomber(1)], 1.0), plant(bomber(0) + 64, 2, [0, 1, 2, 3], 1.0), plant(bomber(1) + 64, 2, [0, 1, 2, 3], 1.0)]
case("f0606C28A", [], True, CUR)
case("f0606C292", [span(0, 10)], True, CUR)
case("f0606C2B8", [span(0, 6), span(0, 5), span(0, 4)], True,
     [plant(CURRENT_PTR, 4, [bomber(0), bomber(1)], 1.0), plant(bomber(0) + 24, 2, [0, 8, 0x10, 0x100], 0.8),
      plant(bomber(0) + 28, 2, [0, 8, 0x10, 0x100], 0.8), plant(bomber(1) + 24, 2, [0, 8, 0x100], 0.8),
      plant(bomber(1) + 28, 2, [0, 8, 0x100], 0.8)])

# The 38-byte records at 060D849C: byte 7 links to the next, 0 ends the chain.
ACTORS = [plant(0x060D849C + 38 * k + 7, 1, [0, k + 1], 1.0) for k in range(8)] + [plant(0x060D849C + 38 * 8 + 7, 1, [0], 1.0)]
ACTORS += [plant(0x060D849C + 38 * k + 4, 2, [0, 0x40, 0x80, 0x100, 0xFFFF], 0.8) for k in range(9)]
case("f0606C6C2", [pick(0, 0x40, 0x7F, 0x80, 0x100, 0x1000, 0xFFFF)], True, ACTORS)
LINKS = [plant(0x060D776C + 8 * k + 2, 1, [0, k + 1], 1.0) for k in range(60)] + [plant(0x060D776C + 8 * 60 + 2, 1, [0], 1.0)]
case("f0606D8E6", [span(0, 20)], False, LINKS + [plant(CURRENT_PTR, 4, [bomber(0)], 1.0)])
case("f0606F330", [], False,
     [plant(CURRENT_PTR, 4, [bomber(0)], 1.0)])
case("f0607A990", [], False, [plant(CURRENT_PTR, 4, [bomber(0)], 1.0), plant(0x060C2808, 2, [0, 1, 2, 5, -3], 0.9), plant(bomber(0) + 6, 1, [0, 1, 2, 3, 4], 1.0)])
LIST = BUF + 0x2000
case("f0607CCBC", [ptr(LIST, 0x20, 2)], True,
     [plant(LIST + 2 * k, 2, [-1, 0, 1, 2, 3], 1.0) for k in range(16)] + [plant(LIST + 40, 2, [-1], 1.0)]
     + [plant(0x060C2860, 2, [0, 1, 2], 1.0), plant(0x060D5F30 + 22, 2, [3, 4], 1.0), plant(0x060D5F30 + 124 + 22, 2, [3, 4], 1.0),
        plant(0x060D5F30 + 124 * 2 + 22, 2, [3, 4], 1.0)]
     + [plant(0x060D5F30 + 124 * k + 80, 2, [0], 0.8) for k in range(3)]
     + [plant(obj(k) + 50, 2, [0, 1, 2], 1.0) for k in (3, 4)])
case("f06080396", [], False, [plant(CURRENT_PTR, 4, [bomber(0), bomber(1)], 1.0)])

MEM = BUF + 0x3000
case("f060949E0", [ptr(MEM, 0x40, 1), ptr(MEM + 0x10, 0x40, 1), span(0, 48)], True, [])
case("f06094CA8", [ptr(MEM, 0x40, 1), span(0, 255), span(0, 48)], True, [])
case("f06095198", [ptr(MEM, 0x40, 1), ptr(MEM + 0x80, 0x40, 1), span(0, 48)], True,
     [plant(MEM + 0x80 + k, 1, [0, 0x41, 0x42], 0.9) for k in range(48)])
case("f06094A58", [ptr(MEM, 0x40, 1), ptr(MEM + 0x80, 0x40, 1)], True,
     [plant(MEM + 0x80 + k, 1, [0, 0x41, 0x42], 0.9) for k in range(48)])
case("f06082B20", [pick(0, 3, 4, 5)], False, [plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0)])
case("f0608AAEE", [ptr(MEM + 0x200, 0x40, 2)], True,
     [plant(MEM + 0x200 + 2 * k, 2, [1, 5, 0x30], 0.97) for k in range(120)]
     + [plant(MEM + 0x200 + 2 * k, 2, [0, -1], 0.04) for k in range(120)]
     + [plant(CURRENT_PTR, 4, [bomber(0)], 1.0)] + [plant(0x060C2F04 + 88 * k, 1, [1], 0.93) for k in range(8)]
     + [plant(0x060C2F04 + 88 * k, 1, [0], 0.04) for k in range(8)])
case("f0608AD82", [], False, [plant(0x060C31CA, 2, [3, 4], 1.0), plant(obj(3) + 66, 2, [0, 1], 0.5), plant(obj(4) + 66, 2, [0, 1], 0.5),
                              plant(0x060C31DE, 2, [0, 3, 4], 0.7)])
case("f06088DA4", [span(0, 50)], False, [plant(CURRENT_PTR, 4, [bomber(0)], 1.0), plant(bomber(0) + 18, 2, [0, 0x180, 1, 0x10], 0.9)]
     + [plant(0x060EC8B0 + 2 * k, 2, [0, 0x180, 0x100, 1], 0.8) for k in range(50)])
case("f06088E20", [], False, [plant(CURRENT_PTR, 4, [bomber(0)], 1.0), plant(bomber(0) + 20, 2, [0, 2, 4], 1.0),
                              plant(0x060C2ED4, 2, [6, 8], 1.0), plant(0x060C2ED6, 2, [0, 1, 2, 3], 1.0)]
     + [plant(0x060B90A0 + 2 * k, 2, [1, 2], 1.0) for k in range(4)]
     + [plant(0x060EC8B0 + 2 * k, 2, [0, 0x180, 0x100], 0.7) for k in range(0, 40)])

TRACK = [plant(CURRENT_PTR, 4, [bomber(0), bomber(1)], 1.0), plant(bomber(0) + 68, 2, [0, 1, 2], 1.0), plant(bomber(1) + 68, 2, [0, 2], 1.0),
         plant(REC1 := 0x060D5F30 + 124 * 2 + 68, 2, [0], 1.0), plant(bomber(0) + 6, 1, [0, 1, 4], 1.0), plant(bomber(1) + 6, 1, [0, 2, 4], 1.0)]
case("f0607193C", [], False, TRACK + [plant(0x060D5F30 + 124 * k + 40, 2, [0, 1, 2], 0.8) for k in range(3)])
ACTORS = [plant(0x060D849C + 38 * k + 7, 1, [0, k + 1], 1.0) for k in range(8)] + [plant(0x060D849C + 38 * 8 + 7, 1, [0], 1.0)]
case("f06081724", [], True, ACTORS + [plant(0x060D8C08, 4, [0x060D849C], 0.5)]
     + [plant(0x060D849C + 38 * k + 16, 1, [0, 1, 2, 3, 0xFF], 0.9) for k in range(9)]
     + [plant(0x060D849C + 38 * k + 10, 2, [0, 0x80, 0x180, 0xFFFF], 0.9) for k in range(9)])

# Buffers the copy routines and their callers read and write.
def ptrs(*addrs, base=BUF + 0x6000, step=0x200):
    return [plant(a, 4, [base + step * k, base + step * k + 0x100, base + step * k, 0], 1.0) for k, a in enumerate(addrs)]


SMALL = lambda *addrs: [plant(a, 4, [0, 2, 8, 12], 1.0) for a in addrs]
case("f06096B3C", [pick(MEM + 0x400)], True,
     [plant(MEM + 0x400, 4, [0, 1], 1.0), plant(MEM + 0x404, 4, [-1, 0, 1, 3, 5, 8], 1.0), plant(MEM + 0x408, 4, [MEM + 0x500], 1.0)]
     + [plant(MEM + 0x500 + 24 * k + 11, 1, [0, 1, 3], 0.4) for k in range(10)])
HW, UW = BUF + 0x4000, BUF + 0x4100
case("f0609741C", [ptr(BUF + 0x4200, 0x20, 4), ptr(BUF + 0x4300, 0x20, 4), ptr(BUF + 0x4400, 0x20, 4), span(2, 6)], False,
     [plant(0x060FA8C8, 4, [HW], 1.0), plant(0x060FA8CC, 4, [UW], 1.0)])
case("f060975F6", [span(-5, 40), ptr(BUF + 0x4200, 0x20, 4), ptr(BUF + 0x4300, 0x20, 4), ptr(BUF + 0x4400, 0x20, 4)], True,
     [stack(0, [1, 2, 3, 4, 5, 6])] + [plant(BUF + 0x4200 + 4 * k, 4, [k * 8, k * 8 + 3, 100], 0.7) for k in range(8)])
FB = ptrs(0x060FB85C, 0x060FB860, 0x060FB874, 0x060FA99C, 0x060FA988, 0x060FA98C, 0x060FA990, 0x060FA994,
          0x060BB904, 0x060BB908, 0x060BB90C, 0x060BB910, 0x060BB914, 0x060BB918)
FB += SMALL(0x060FB850, 0x060FB854) + [plant(0x060FB858, 2, [0, 1], 1.0), plant(0x060FB85A, 2, [0, 1], 1.0), plant(0x060BB902, 2, [0, 1, 2], 1.0),
                                      plant(0x060BB8F0, 2, [0, 2, 8], 1.0), plant(0x060BB8F2, 2, [0, 2, 8], 1.0), plant(0x060BB8FC, 2, [0, 1, 2, 3, 4, 5, 6, 7], 1.0)]
case("f0609B5B4", [], False, FB)
case("f0609B69A", [], False, FB + [plant(0x060FB8DC, 1, [0, 0xFC, 0x80, 0x40, 0x20, 0x10, 8, 4], 0.9)])
case("f0609B734", [ptr(MEM, 0x40, 2), ptr(MEM + 0x100, 0x40, 2), span(0, 64)], False, [])
case("f0609B9E0", [span(0, 5), span(0, 20), pick(0, 1, 2, 3, 8), ptr(MEM, 0x40, 4)], False, [])
case("f0609BE8C", [span(0, 4), pick(0, 1, 5), pick(0, 1, 2, 5, 100), ptr(MEM, 0x10, 2)], False,
     [stack(0, [MEM + 0x100, MEM + 0x110]), plant(0x060FB930, 1, [0, 0, 3], 1.0)]
     + [plant(MEM + 2 * k, 2, [0, 1, 5, -3, 200, 0x7FFF, 0x8000], 0.8) for k in range(16)]
     + [plant(MEM + 0x100 + 2 * k, 2, [0, 1, 5, -3, 200, 0x7FFF, 0x8000], 0.8) for k in range(16)])
case("f0609C0B4", [pick(0, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000, 1, 2, 4, 8, 16, 32, 128, 0x3F, 0xFFFF, 0x1FF), pick(0, 5, 31, 32, 200, 255, 0x1FF)], False, [])

case("f06083BE8", [], False, LINKS + [plant(CURRENT_PTR, 4, [bomber(0)], 1.0), plant(0x060C062C, 2, [0, 1, 2, 5], 1.0)])
case("f06085D9C", [], True, [plant(CURRENT_PTR, 4, [bomber(0), bomber(1)], 1.0), plant(bomber(0) + 24, 2, [0x10, 0x28, 0x58, 0x100], 1.0),
                              plant(bomber(0) + 28, 2, [0x10, 0x28, 0x58, 0x100], 1.0), plant(bomber(1) + 24, 2, [0x10, 0x28, 0x58, 0x100], 1.0),
                              plant(bomber(1) + 28, 2, [0x10, 0x28, 0x58, 0x100], 1.0)]
     + [plant(0x060C1F42 + 12 * k + 4, 4, [0, 1, 0xFFFF, 0x10000], 0.7) for k in range(10)])
case("f0608AE8C", [pick(0, 1, 5, -3)], False, [plant(0x060C31DE, 2, [0, 3, 4], 0.7), plant(0x060C31DC, 2, [0, 3, 4], 0.7)])

case("f0609D730", [pick(0, 1, 2, 4, 8, 16, 32, 128, 0x80000, 0xFF, 0x80000 | 0x3F, 0x80)], False, [])
case("f0609DA34", [], True, [plant(0x060BB924, 4, [0], 1.0)])
SND = [plant(0x060BB8FE, 2, [0, 0x100, 0x160, 0x161, 0x300], 1.0), plant(0x060BB8FC, 2, [0, 1, 2], 1.0),
       plant(0x060FB898, 2, [0, 5, 0x1234], 0.8)]
case("f0609DC4C", [pick(0, 0, 1, 1, 2, 255, 256), pick(0, 0, 5, -1), pick(0, 0, 1, 0x10000, 0x10001, -1), pick(0, 0, 3, -1)], False,
     SND + [stack(k, [0, 1, 0x20, 0x7FFF, 0xFFFF, 0x1234]) for k in range(4)])
case("f0609DD9C", [pick(0, 0, 1, 1, 2, 255, 256), pick(0, 0, 5, -1), pick(0, 0, 1, 0x10000, 0x10001, -1), pick(0, 0, 3, -1)], False,
     SND + [stack(0, [BUF + 0x7000, BUF + 0x7400]), stack(1, [0, 1, 0x20, 3]), stack(2, [0, 1, 2, 5, 9]), stack(3, [BUF + 0x7800, BUF + 0x7900])]
     + [plant(BUF + 0x7800 + 2 * k, 2, [0, 1, 0x7FFF, 0xFFFF, 0x1234], 0.7) for k in range(40)])
case("f0609CBF8", [pick(0, 1), span(-300, 300), span(-300, 300), span(-300, 300)], False, [])

case("f0609DF54", [pick(0, 0, 5, -1), pick(0, 0, 1, 0x10000, -1), pick(0, 0, 3, -1)], False, SND)
case("f0609E020", [pick(0, 1, 2, 4, 8, 16, 32, 128, 0x100, 3, 64)], False, [])
LISTP = BUF + 0x7C00
SOUNDLIST = ([plant(0x060FBF4C, 4, [LISTP], 1.0), plant(0x060FBF64, 4, [BUF + 0x7D00], 1.0)]
             + [plant(LISTP + 8 * k, 4, [0x00000010, 0x11000020, 0x22000030, 0x33000040, 0x01000050, 0x10000060, 0x80000000, 0x12000070], 1.0) for k in range(10)]
             + [plant(LISTP + 8 * 10, 4, [0x80000000], 1.0)])
case("f0609EF5C", [ptr(BUF + 0x7E00, 0x10, 4), ptr(BUF + 0x7E10, 0x10, 4), span(0, 4), span(0, 4)], False, SOUNDLIST)
case("f0609E3FA", [pick(BUF + 0x7F00), span(0, 12), pick(0), pick(0)], False,
     [plant(0x060FBF4C, 4, [LISTP], 1.0), plant(0x060FBF64, 4, [BUF + 0x7D00], 1.0), plant(LISTP, 4, [0x00000010, 0x00000011, 0x10000012, 0x01000013], 1.0),
      plant(LISTP + 8, 4, [0x00000020], 1.0)])
case("f0609F66C", [span(-5, 5)], True, [plant(0x060FBF68, 4, [0, 1, 2, 320], 1.0), plant(0x060FBF6C, 4, [0, 1, 2, 224], 1.0)])

DEVP = [plant(0x060FC084, 4, [BUF + 0x8000], 1.0)]
DEVREC = BUF + 0x8000
case("f060A7902", [span(0, 5)], True, DEVP + [plant(DEVREC + 48, 4, [0, 1, 2], 1.0), plant(DEVREC + 56, 4, [0, 1, 2, 3, 4, 5], 1.0)])
case("f060A7920", [span(0, 5), span(0, 5), ptr(BUF + 0x8400, 0x10, 1), span(0, 100)], True,
     DEVP + [plant(DEVREC + 24 + k, 1, [0, 1, 1, 1], 1.0) for k in range(6)] + [plant(DEVREC + 84, 4, [0, 5, 23, 24, 30], 1.0),
     plant(DEVREC + 88, 4, [0, 5, 7], 1.0), stack(0, [0, 7, 0x1234])])
case("f060A8DCC", [pick(0, 0x100, 4, 2, 8, 128, 16, 32, 1, 0x40000, 0xFFFFF, 6, 0x88), span(0, 20), pick(0, 1, 2, 255, 256)], False, [])
case("f060AA57C", [], True, [plant(0x060FBF98, 4, [0, 1, 1, 1], 1.0), plant(0x060FBFA0, 4, [BUF + 0x8800], 1.0), plant(0x060FBFAC, 4, [BUF + 0x9000], 1.0),
     plant(0x060FBFA4, 4, [BUF + 0x8C00], 1.0), plant(0x060FBF94, 4, [0, 1, 2, 3], 1.0), plant(0x060FBF8C, 4, [0, 1, 2, 3, 5], 1.0),
     plant(0x060FBF90, 4, [0, 1, 2, 7], 1.0)]
     + [plant(BUF + 0x8C00 + 4 * k, 2, [-1, 0, 1, 2, 3], 1.0) for k in range(8)]
     + [plant(BUF + 0x8800 + 4 * k, 2, [-1, k + 1], 1.0) for k in range(8)] + [plant(BUF + 0x8800 + 4 * 8, 2, [-1], 1.0)]
     + [plant(BUF + 0x8800 + 4 * k + 2, 2, [0, 1, 2, 3, 4], 1.0) for k in range(8)])
case("f060A33D8", [span(0, 5), span(0, 5), span(0, 5)], False, [])
case("f060A30EA", [span(0, 5), pick(BUF + 0xB000), span(0, 5), span(0, 5)], True,
     [stack(0, [0xC000, 0xB900, 0x100]), stack(1, [3]), stack(2, [4, 0]), plant(0x060BB994, 4, [0], 1.0)] + [plant(0x060BB96C + k, 1, [b], 0.995) for k, b in enumerate(GREETING)]
     + SLOTBITS + [plant(0x060BB98C, 4, [0, 0, 1, 0xFF], 1.0)])

case("f060A317A", [ptr(BUF + 0xA000, 0x20, 4)], False, [plant(BUF + 0xA000 + 4 * k, 4, [BUF + 0xA100], 1.0) for k in range(8)])
case("f060AAA1C", [pick(BUF + 0xA400), ptr(BUF + 0xA300, 0x10, 4), ptr(BUF + 0xA340, 0x10, 4)], True,
     [plant(BUF + 0xA400 + 15, 1, [0, 2, 4, 6, 1, 8, 24], 1.0)] + [plant(BUF + 0xA400 + 4 * k, 4, [0, 5, 100], 1.0) for k in range(8)]
     + [plant(BUF + 0xA300 + 4 * k, 4, [0, 5, 100], 1.0) for k in range(4)])

case("f060AAF8A", [ptr(BUF + 0xB000, 0x300, 4), span(0, 5), ptr(BUF + 0xB800, 0x40, 4)], True,
     [plant(0x060BB96C + k, 1, [b], 0.995) for k, b in enumerate(GREETING)] + SLOTBITS
     + [plant(0x060BB98C, 4, [0, 0, 1, 0xFF, 0x7FFFFFFF, 0xFFFFFFFF], 1.0)]
     + [plant(BUF + 0xB800 + 4, 4, [0x100, 0xB900, 0xC000, 0x10000, 0xB801], 1.0), plant(0x060BB994, 4, [0], 1.0)])
case("f060AAE84", [], True, [])
OBJP = [plant(BUF + 0xC000, 4, [BUF + 0xC100], 1.0)]
case("f060AB456", [pick(BUF + 0xC000)], False, OBJP + [plant(BUF + 0xC100 + 52 + 160, 4, [0], 1.0)])
case("f060AB726", [pick(BUF + 0xC000), pick(24, 16, 0, 25, 24)], False, OBJP + SHIFT_TABLES)
case("f060ABB16", [pick(BUF + 0xC000), pick(24, 16, 0, 25, 24)], False, OBJP + SHIFT_TABLES)
case("f060ABB48", [pick(BUF + 0xC000), span(-3, 9)], True,
     OBJP + [plant(BUF + 0xC100 + 52 + 4, 4, [4, 4, 4, 5, 0], 1.0), plant(BUF + 0xC100 + 52 + 108, 4, [0, 1, 1, 1], 1.0),
             plant(BUF + 0xC100 + 24, 4, [0, 1, 2], 1.0), plant(0x25A00404, 4, [0x1000], 1.0), plant(BUF + 0xC100 + 52 + 124, 4, [0, 1, 5, 9], 1.0)]
     + [plant(0x25A01000 + 16 * k, 1, [0], 1.0) for k in range(4)])
case("f060AD718", [], False, [])
IDX = [plant(0x060B12F8 + 4 * k, 4, [1 << k], 1.0) for k in range(32)]
case("f060AD8F0", [ptr(BUF + 0xB000, 0x300, 4), ptr(BUF + 0xB800, 0x40, 4), span(0, 5), span(0, 5)], True,
     IDX + [plant(0x060FC18C, 4, [0x12345678, 0x12345678, 0x12345678, 0], 1.0), plant(0x060FC210, 4, [0, 0, 1, 0xFFFF, 0xFFFFFFFF], 1.0)]
     + [plant(BUF + 0xB800 + 12, 4, [0x2000, 0x3000, 0x10000, 0x11000, 0x1000, 0x1001, 0x4000, 0x0000], 1.0), plant(0x060FC228, 4, [0], 1.0)])
case("f060AEA3C", [span(0, 5), span(0, 5), span(0, 5)], False, [])
MEM2 = BUF + 0xD000
case("f060AFAC4", [ptr(MEM2, 0x40, 1), ptr(MEM2 + 0x80, 0x40, 1), span(0, 14)], False, [])
case("f060B0426", [ptr(MEM2, 0x40, 1), ptr(MEM2 + 0x80, 0x40, 1), span(0, 14)], False, [])
case("f060B07B4", [pick(BUF + 0xC000), ptr(BUF + 0xD400, 0x20, 2)], False,
     OBJP + [plant(BUF + 0xC100 + 48 + 8, 4, [0, 1, 2], 1.0), plant(BUF + 0xD400 + 16, 2, [0x400E, 0x400A, 0x4000, 0x4010, 0x400F, 0], 1.0)] + SHIFT_TABLES)
RING = BUF + 0xD800
case("f060B0E8E", [pick(BUF + 0xC000), pick(BUF + 0xDC00)], True,
     OBJP + [plant(BUF + 0xC100 + 4, 4, [RING, RING + 8], 1.0), plant(BUF + 0xC100 + 48 + 68, 4, [RING + 0x10, RING + 0x30, RING], 1.0),
             plant(BUF + 0xDC00, 4, [BUF + 0xDD00], 1.0), plant(BUF + 0xDC00 + 4, 4, [BUF + 0xDD80], 1.0),
             plant(BUF + 0xDC00 + 8, 4, [RING, RING + 4, RING + 0x20, RING - 8], 1.0), plant(BUF + 0xDC00 + 12, 4, [0, 1, 2, 5, 12, -1], 1.0)])
ITEMS = BUF + 0xC100 + 48 + 232
case("f060B0FB6", [pick(BUF + 0xC000)], False,
     OBJP + [plant(BUF + 0xC100 + 48 + 228, 4, [-1, 0, 1, 2], 1.0), plant(BUF + 0xC100 + 48 + 36, 4, [0, 1], 1.0),
             plant(BUF + 0xC100 + 48 + 40, 4, [0, 8, 9, 20], 1.0), plant(BUF + 0xC100 + 4, 4, [RING], 1.0),
             plant(BUF + 0xC100 + 48 + 68, 4, [RING + 0x40], 1.0)]
     + [plant(ITEMS + 16 * k, 4, [BUF + 0xDD00 + 0x40 * k], 1.0) for k in range(3)]
     + [plant(ITEMS + 16 * k + 4, 4, [BUF + 0xDE00 + 0x40 * k], 1.0) for k in range(3)]
     + [plant(ITEMS + 16 * k + 8, 4, [RING, RING + 8, RING + 0x10], 1.0) for k in range(3)]
     + [plant(ITEMS + 16 * k + 12, 4, [0, 1, 2, 4], 1.0) for k in range(3)])

case("f060A499C", [pick(0, 0, BUF + 0xE000), span(0, 5), span(0, 5), span(0, 5)], False,
     [plant(BUF + 0xE000, 4, [BUF + 0xE100], 1.0), plant(0x060FC228, 4, [0], 1.0)])

TURN = [plant(CURRENT_PTR, 4, [bomber(0), bomber(1)], 1.0), plant(bomber(0) + 28, 2, [0, 30, 48, 49, 100, 128, 200, 0xCF, 0xD0, 0x300, 0xFFFF], 1.0),
        plant(bomber(1) + 28, 2, [0, 30, 48, 49, 100, 128, 200, 0xCF, 0xD0, 0x300, 0xFFFF], 1.0),
        plant(bomber(0) + 86, 2, [0, 30, 64, 100, 192, 193, 300, 0xFFFF], 1.0), plant(bomber(1) + 86, 2, [0, 30, 64, 100, 192, 193, 300, 0xFFFF], 1.0),
        plant(0x060C28B4, 2, [0, 0, 1], 1.0), plant(0x060C28B6, 2, [0, 1, 2, 3], 1.0), plant(0x060C28B8, 2, [0, 0, 2, 4, 6], 1.0)]
RNG = [plant(0x060BF4F4, 4, [0, 1, 5, 30, 54], 1.0)] + [plant(0x060BF4F8 + 4 * k, 4, [0, 17, 99, 255, 4000, 12345, 0x7FFF], 1.0) for k in range(60)]
case("f060819B8", [], False, TURN + RNG + [plant(0x060EC8B0 + 2 * k, 2, [0], 0.85) for k in range(0, 0x400)] + [plant(0x060EC8B0 + 2 * k, 2, [0x380, 0x100, 0x80], 0.15) for k in range(0, 0x400)])
