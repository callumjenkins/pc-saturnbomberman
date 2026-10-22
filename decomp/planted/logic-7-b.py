import os

from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

_ROOT = os.path.dirname(os.path.abspath(__file__))
while not os.path.exists(os.path.join(_ROOT, "build", "extract", "BOMSS", "0KRNL.BIN")):
    _ROOT = os.path.dirname(_ROOT)
with open(os.path.join(_ROOT, "build", "extract", "BOMSS", "0KRNL.BIN"), "rb") as _f:
    _IMG = _f.read()


def image(lo, hi):
    """The image's own halfwords in [lo, hi), which a random trial overwrites."""
    return [plant(a, 2, [int.from_bytes(_IMG[a - 0x06006000:a - 0x06006000 + 2], "big")], 1.0) for a in range(lo & ~1, hi, 2)]


def image_words(lo, hi):
    return [plant(a, 4, [int.from_bytes(_IMG[a - 0x06006000:a - 0x06006000 + 4], "big")], 1.0) for a in range(lo & ~3, hi, 4)]


SP = 0x060FFFF0                 # r15 on entry; the first stack argument is here
FIX = 0x060C0100                # a pointer argument the plants can name
TASK = 0x060C2100               # a task record
CUR = [plant(0x060D7768, 4, [bomber(0)], 1.0)]
# the user callbacks the two error recorders (060AAE08, 060AD62C) jump to when set
ERR = [plant(0x060BB994, 4, [0], 1.0), plant(0x060FC228, 4, [0], 1.0)]


def bombers(offset, size, values, count=2, chance=0.9):
    return [plant(bomber(i) + offset, size, values, chance) for i in range(count)]


# the task record 060D7E60 points at, and the object 060D7E64 points at
TASKP = [plant(0x060D7E60, 4, [TASK], 1.0), plant(0x060D7E64, 4, [obj(3)], 1.0)]

case("f06062562", [], True, TASKP + [plant(TASK + 8, 2, [3, 4], 1.0), plant(TASK + 10, 2, [1, 2, 5, 9, 12], 1.0),
                                    plant(0x060D7BB0, 2, [3, 4], 1.0), plant(obj(3) + 38, 2, [10, 60, 70], 0.9),
                                    plant(obj(4) + 38, 2, [10, 60, 70], 0.9)])
case("f06062D3C", [span(0, 40)], True, [plant(slot(k) + 8, 2, [0, 1, 5], 0.7) for k in range(40)])
case("f060638E0", [span(0, 4)], True, [plant(0x060C063D, 1, [0, 2, 3], 1.0)] + bombers(4, 1, [0, 0, 0x40, 0x80], 6, 0.9)
     + bombers(46, 2, [0, 0, 0x100], 6, 0.9) + bombers(20, 2, [0, 1, 2, 3, 4], 6, 0.9))
case("f06063916", [span(0, 4)], True, bombers(4, 1, [0, 0, 0x80]) + bombers(20, 2, [0, 1, 2, 3, 4]))
case("f0606397C", [span(0, 40), span(0, 40)], True,
     bombers(4, 1, [0, 0, 0x80]) + bombers(22, 2, [3, 4], 2, 1.0)
     + [plant(obj(i) + o, 2, [0, 10, 20, 33], 0.9) for i in (3, 4) for o in (16, 18)])
case("f06063A06", [span(-50, 50)], False, TASKP + [plant(TASK + 20, 2, [0, 1, 2, 3], 1.0)] + bombers(22, 2, [3, 4], 2, 1.0))
case("f06063D92", [], True, CUR + [plant(0x060C029C, 1, [3, 3, 0], 1.0), plant(0x060D7B46, 2, [1], 1.0)]
     + [plant(slot(k) + 8, 2, [0, 1, 5], 0.7) for k in (4, 5)]
     + [plant(bomber(0) + 24, 2, [0, 300], 1.0), plant(bomber(0) + 28, 2, [0, 50], 1.0)]
     + [plant(obj(i) + o, 2, [0], 0.9) for i in range(8) for o in (16, 18)] + [plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0)])
case("f0606453C", [], True, TASKP + [plant(TASK + 16, 2, [0, 1, 2], 0.9), plant(TASK + 14, 2, [0, 1, 2, 3], 1.0),
                                    plant(TASK + 18, 2, [0, 1, 2, 3, 40], 1.0)]
     + [plant(0x060EC8B0 + 2 * c, 2, [0, 0, 7, 0x1F], 0.9) for c in range(0, 64)]
     + [plant(slot(k) + 16, 2, [0, 5], 0.9) for k in range(0, 4)])
case("f0606A9A2", [span(0, 20)], True, [plant(obj(i) + 10, 2, [0, 5], 0.7) for i in range(21)])
case("f0606BDDC", [], True, CUR + [plant(bomber(0) + 64, 2, [0, 1, 2, 3], 1.0), plant(0x060C1F30, 2, [0, 1], 0.3)]
     + bombers(4, 1, [0, 0, 0x80], 6, 0.9))

BUF = 0x060C5000                # work RAM the trials do not use for anything else


def stack(k, values, chance=1.0):
    """The k-th word above the stack pointer the function is entered with."""
    return plant(SP + 4 * k, 4, values, chance)


def words(base, values, chance=1.0):
    return [plant(base + 4 * k, 4, [v], chance) for k, v in enumerate(values)]


# the sound command ring: 060FBF48 is its start, 060FBF64 the slot in use, and a slot whose first byte is 0 is free
RING = BUF + 0x1000
RING2 = BUF + 0x1800
SND = [plant(0x060FBF40, 4, [0, 0, 0, 1], 1.0), plant(0x060FBF48, 4, [RING, RING, RING, RING2], 1.0),
       plant(0x060FBF64, 4, [RING, RING, RING2], 1.0)]
FREE_SLOTS = SND + [plant(RING + 16 * k, 1, [0, 0, 5], 0.6) for k in range(7)] + [plant(RING2 + 16 * k, 1, [5], 1.0) for k in range(7)]
BUSY_SLOTS = [plant(0x060FBF40, 4, [0, 0, 1], 1.0), plant(0x060FBF48, 4, [RING], 1.0), plant(0x060FBF64, 4, [RING], 1.0)] \
    + [plant(RING + 16 * k, 1, [5], 1.0) for k in range(7)]
case("f0609E434", [span(-3, 3)], False, BUSY_SLOTS)
case("f0609E5EC", [span(-3, 3), span(0, 7), span(-3, 3)], True, FREE_SLOTS)
case("f0609E674", [pick(BUF + 0x1100), span(-3, 3)], True, BUSY_SLOTS)
case("f0609E972", [span(-3, 3), pick(0, 5, 0x123, -0x234, 0x7FFF, -0x8000)], True, FREE_SLOTS)
case("f0609E9E4", [span(0, 7), span(0, 7), span(0, 7), span(0, 7)], True, FREE_SLOTS + [stack(0, [0x12345678, 5]), stack(1, [0x7F, 0x80])])
case("f0609EA86", [span(-3, 3), span(-3, 3), span(-3, 3)], True, FREE_SLOTS)
case("f0609EAF8", [pick(BUF + 0x1200), pick(BUF + 0x1300)], True, FREE_SLOTS)
case("f0609EC08", [span(-3, 3)], True, FREE_SLOTS)
case("f0609EC5E", [pick(BUF + 0x1200)], True, FREE_SLOTS)
case("f0609ED2C", [], True, FREE_SLOTS)
case("f0609ED78", [], True, FREE_SLOTS)
case("f0609F090", [span(-3, 3), span(-3, 3)], True, FREE_SLOTS)
case("f0609F0F4", [span(-3, 3), span(-3, 3), span(-3, 3)], True, FREE_SLOTS)
case("f0609F15A", [], True, FREE_SLOTS)
LIST = [plant(0x060FBFFC, 4, [BUF + 0x1400], 1.0)] + [plant(BUF + 0x1400 + 0x20 * k, 4, [BUF + 0x1400 + 0x20 * (k + 1)], 1.0) for k in range(4)] \
    + [plant(BUF + 0x1400 + 0x80, 4, [0], 1.0)] \
    + [plant(BUF + 0x1400 + 0x20 * k + 4, 2, [0, 5, 0x100, 0xFFFF], 0.9) for k in range(5)]
case("f0609F938", [pick(BUF + 0x1300)], True, LIST)

# a handle: a pointer to a word that points to the stream's record, with the state the API wrappers read in it
HANDLE = BUF + 0x2000
STREAM = BUF + 0x2100
H = ERR + [plant(HANDLE, 4, [STREAM], 1.0), plant(STREAM + 0x144, 4, [0, 5], 0.6), plant(STREAM + 0x18C, 4, [0, 5], 0.6),
     plant(STREAM + 52, 4, [-1, 0, 1, 2, 5, 7], 1.0), plant(STREAM + 56, 4, [0, 3, 5], 1.0), plant(STREAM + 284, 4, [-5, 0, 100, 0x7FFFFFFF], 1.0)]
case("f060A05C4", [pick(-16, -15, -14, -13, -12, -11, -10, -2, 0, 5)], True)
NODES = [plant(BUF + 0x2200 + 0x40 * k + 8, 4, [BUF + 0x2200 + 0x40 * (k + 1), 0], 0.7) for k in range(3)] \
    + [plant(BUF + 0x2200 + 0x40 * 3 + 8, 4, [0], 1.0)] \
    + [plant(BUF + 0x2200 + 0x40 * k + 20, 4, [BUF + 0x2400], 1.0) for k in range(4)] + [plant(BUF + 0x2400 + 28, 4, [0, 7], 0.7)]
case("f060A129C", [pick(BUF + 0x2200)], True, NODES + [plant(BUF + 0x2208, 4, [0, 0, BUF + 0x2240], 1.0), plant(BUF + 0x2200, 4, [BUF + 0x2240, 0], 1.0)])
case("f060A1644", [pick(BUF + 0x2200)], False, NODES + [plant(BUF + 0x2200 + 20, 4, [0, 3, 100], 1.0), plant(BUF + 0x2200, 4, [BUF + 0x2240, 0], 1.0)]
     + [plant(BUF + 0x2200 + 0x40 * k + 16, 4, [BUF + 0x2500], 1.0) for k in range(4)])
case("f060A39F2", [pick(0, HANDLE), span(-2, 2), span(0, 3), span(0, 3)], True, H + [plant(0x060BB98C, 4, [0] * 30 + [0xFFFFFFFF], 1.0)])
case("f060A3B08", [pick(0, HANDLE), span(-2, 2), span(0, 3), span(0, 3)], True, H)
case("f060A3B7E", [pick(0, HANDLE), span(-2, 10), span(0, 3), span(0, 3)], True, H)
case("f060A3BB6", [pick(0, HANDLE), span(-2, 10), span(0, 3), span(0, 3)], True, H)
case("f060A3D7C", [pick(0, HANDLE), span(-2, 2), span(0, 3), span(0, 3)], True, H)
case("f060A3F06", [pick(0, HANDLE), span(-2, 10), span(0, 3), span(0, 3)], True, H)
case("f060A46C0", [pick(0, HANDLE), span(-2, 2), span(0, 3), span(0, 3)], True, H)
case("f060A4860", [pick(0, HANDLE), span(-2, 2), span(0, 3), span(0, 3)], True, H + [plant(STREAM + 48 + 4, 4, [-1, 0, 2, 7], 1.0)])
case("f060A4908", [pick(0, HANDLE), span(-2, 10), span(0, 3), span(0, 3)], True, H)
case("f060A4940", [pick(0, HANDLE), span(-2, 10), span(0, 3), span(0, 3)], True, H)
case("f060A4B24", [pick(0, HANDLE), span(-2, 10), span(0, 3), span(0, 3)], True, H)
case("f060A4C0C", [pick(0, HANDLE, *[0x060FC190 + 4 * k for k in range(8)]), span(-2, 10), span(0, 3), span(0, 3)], True,
     H + [plant(0x060FC210, 4, [0, -1, -1], 1.0)] + [plant(0x060B12F8 + 4 * k, 4, [1 << k], 1.0) for k in range(32)]
     + [plant(0x060FC190 + 4 * k, 4, [STREAM], 1.0) for k in range(32)])

# the sprite 060CBB5C points at, and the records its bank lists (20 bytes each, ended by a halfword of 0x8000 or more)
QUAD = BUF + 0x2600
BANK_P = BUF + 0x2800
BANK_T = BUF + 0x2900
RECS = BUF + 0x2A00
BANK = [plant(0x060BD904, 4, [BANK_P], 1.0), plant(BANK_P, 4, [BANK_T], 1.0), plant(BANK_P + 4, 4, [BANK_T], 1.0)] \
    + [plant(BANK_T + 4 * k, 4, [RECS], 1.0) for k in range(8)]
RECORDS = [plant(RECS + 20 * k, 2, [1, 2, 0x10, 0x8000], 0.9 if k == 0 else 0.6) for k in range(3)] \
    + [plant(RECS + 60, 2, [0x8000], 1.0)] \
    + [plant(RECS + 20 * k + 2, 2, [0, 1, 4], 1.0) for k in range(3)] + [plant(RECS + 20 * k + 6, 2, [0, 8], 1.0) for k in range(3)] \
    + [plant(RECS + 20 * k + 8, 2, [0x0123, 0x4567, 0x0820], 1.0) for k in range(3)] \
    + [plant(RECS + 20 * k + o, 2, [0, 10, 100, 0xFFF0], 1.0) for k in range(3) for o in (10, 12)]
QUADSET = [plant(0x060CBB5C, 4, [QUAD], 1.0), plant(QUAD + 68, 2, [0, 64, 200, 300], 0.95), plant(QUAD + 70, 2, [0, 64, 200], 0.95),
           plant(QUAD + 72, 2, [0, 0xFFCE, 100], 1.0), plant(QUAD + 74, 2, [0, 30], 1.0), plant(QUAD + 76, 1, [0, 0, 1, 2, 3], 1.0),
           plant(QUAD + 77, 1, [0, 0, 1, 2], 1.0), plant(QUAD + 78, 1, [0, 0, 1], 1.0), plant(QUAD + 80, 2, [0, 3, 0xFFFB], 1.0),
           plant(QUAD + 82, 2, [0, 2], 1.0), plant(QUAD + 10, 2, [1, 2], 1.0)]
case("f06069FF0", [], False, QUADSET + BANK + RECORDS + [plant(0x060C1B04, 4, [0, 0, 0x320, 0x322], 1.0),
                                                      plant(0x060B7BA4, 2, [0, 1], 1.0), plant(0x060B7BA6, 2, [0, 1], 1.0),
                                                      plant(0x060C1B10, 4, [0, 1], 1.0)])

# the spline routines: sorted knots, two value tables, the scratch pair 060FA8C8/060FA8CC and the stack arguments
SPL = BUF + 0x4000
XS, YA, YB, YC, Y2A, Y2B, Y2C = (SPL + 0x100 * k for k in range(1, 8))
DIST, OUTA, OUTB, OUTC, UNIT = (SPL + 0x100 * k for k in range(8, 13))
KNOTS = [plant(XS + 4 * k, 4, [k * 0x20000], 1.0) for k in range(10)]
SCRATCH = [plant(0x060FA8C8, 4, [SPL], 1.0), plant(0x060FA8CC, 4, [SPL + 0x80], 1.0)]
XVALS = [span(-0x20000, 0xE0000)]
case("f060976D8", XVALS + [pick(XS), pick(YA), pick(YB)], True, KNOTS + [stack(0, [1, 2, 3, 5, 8]), stack(1, [OUTA])])
case("f060978BC", [pick(DIST), pick(XS), pick(YA), pick(YB)], False,
     KNOTS + SCRATCH + [stack(0, [Y2A]), stack(1, [Y2B]), stack(2, [Y2C]), stack(3, [2, 3, 5, 8])])
# 06097B92 copies nine pointers from the structure its first argument names to 060FA8C8
SPLINE_SRC = SPL + 0x1000
SRC9 = [plant(SPLINE_SRC, 4, [8, 16, 1], 1.0)] + [plant(SPLINE_SRC + 4 + 4 * k, 4, [p], 1.0) for k, p in
                                               enumerate([SPL, SPL + 0x80, YA, YB, YC, XS, Y2A, Y2B, Y2C])]
TAB = SPL + 0x1100
case("f06097E20", [pick(0, SPLINE_SRC), pick(TAB), span(2, 6), span(1, 4)], True,
     KNOTS + SRC9 + [stack(0, [OUTA])])
case("f06097F5C", [pick(0, SPLINE_SRC), pick(TAB), span(2, 6), span(1, 4)], True,
     KNOTS + SRC9 + [stack(0, [OUTA]), stack(1, [UNIT])])
case("f060997F0", [pick(BUF + 0x3000, BUF + 0x3040, BUF + 0x3041)], False,
     [plant(0x060FA928, 4, [BUF + 0x3100], 1.0), plant(0x060FA964, 4, [BUF + 0x3000], 1.0)])
case("f0609998C", [], False, [plant(0x060FA974, 4, [0, 2, 5], 1.0), plant(0x060FA914, 4, [0, 1, 3], 1.0),
                              plant(0x060FA90A, 2, [2, 4, 9], 1.0), plant(0x060FA920, 4, [BUF + 0x3200], 1.0),
                              plant(0x060FA90C, 1, [0, 3], 1.0)])
CELLS = BUF + 0x3300
case("f06099A5C", [], True, [plant(0x060FA920, 4, [BUF + 0x3400], 1.0), plant(0x060FA91C, 4, [BUF + 0x3500], 1.0),
                             plant(0x060FA958, 4, [BUF + 0x3600], 1.0), plant(0x060FA954, 4, [BUF + 0x3700], 1.0),
                             plant(0x060FA914, 4, [0, 1], 1.0), plant(0x060FA96C, 4, [0, 5], 1.0),
                             plant(0x060FA90A, 2, [3, 8], 1.0), plant(0x060FA90C, 1, [0, 2], 1.0)])
# the state record 06099AA6 steps: destination, source, two run pointers, a skip count and a repeat count
RUN = BUF + 0x3800
case("f06099AA6", [pick(RUN)], True,
     [plant(RUN, 4, [BUF + 0x3900], 1.0), plant(RUN + 4, 4, [BUF + 0x3A00], 1.0), plant(RUN + 8, 4, [BUF + 0x3B00], 1.0),
      plant(RUN + 12, 4, [BUF + 0x3B10], 1.0), plant(RUN + 16, 4, [0, 2, 5, 40], 1.0), plant(RUN + 20, 4, [0, 1], 1.0),
      plant(BUF + 0x3B01, 1, [0, 1, 3, 6, 9], 1.0), plant(BUF + 0x3B11, 1, [0, 1, 3, 6, 9], 1.0),
      plant(0x060FA90C, 1, [0, 3], 1.0), plant(0x060FA914, 4, [0, 1000], 1.0), plant(0x060FA90A, 2, [2, 6, 1000], 1.0)])

case("f060A8FCC", [pick(0, 0x005A0000, 0x00B40000, 0x010E0000, -0x005A0000, 0x01680000 + 0x005A0000, 0x00100000, 0x00A00000, 0x00C00000,
                       0x01000000, 0x01500000, -0x00200000, 0x7FFFFFFF)], True)
case("f060A9068", [pick(0, 0x005A0000, 0x00B40000, 0x010E0000, -0x005A0000, 0x01680000, 0x00100000, 0x00A00000, 0x00C00000,
                       0x01000000, 0x01500000, -0x00200000, 0x7FFFFFFF)], True)
OBJ2 = BUF + 0x4800
OBJ2_S = BUF + 0x4900
OBJ2_P = BUF + 0x4A00
O2 = [plant(OBJ2 + 20, 4, [OBJ2_S], 1.0), plant(OBJ2 + 16, 4, [OBJ2_P], 1.0), plant(OBJ2_S + 16, 4, [0, 5], 1.0),
      plant(OBJ2_S + 8, 4, [0, 100, 0x801], 1.0), plant(OBJ2_P + 108, 4, [0, 3, 5], 1.0), plant(OBJ2 + 52, 4, [BUF + 0x4B00], 1.0)]
case("f060AA7B4", [pick(OBJ2), span(0, 3), span(0, 3), pick(0, 1, 2, 3)], False, O2)
case("f060AA87E", [pick(OBJ2)], False, O2)
case("f060AAB50", [pick(OBJ2)], True, O2)
case("f060AAB92", [pick(OBJ2), span(0, 5)], True, O2 + [plant(0x060FC00C, 4, [BUF + 0x4C00], 1.0)])
case("f060AABEA", [pick(OBJ2), span(0, 5)], True, O2 + [plant(0x060FC00C, 4, [BUF + 0x4C00], 1.0)])


# a plain chain of links at 060D776C, each one's previous being the entry before it, which 06014820 walks
CHAIN = [plant(0x060D776C + 8 * k, 1, [0, 1, 2, 3, 255], 0.8) for k in range(7)] \
    + [plant(0x060D776C + 8 * k + 1, 1, [max(k - 1, 0)], 1.0) for k in range(7)] \
    + [plant(0x060D776C + 8 * k + 2, 1, [k + 1 if k < 6 else 0], 1.0) for k in range(7)] \
    + [plant(0x060C062C, 2, [0, 1, 2, 3], 0.95)]

# the bomber at 060D7768, the cell flag tables, and the direction tables in the image
MOVER = [plant(0x060D7B3C, 4, [obj(3)], 1.0), plant(obj(3) + 48, 2, [0, 9, 13], 0.9)]
CELLS_ENV = CUR + MOVER + image(0x060B90A0, 0x060B90C0) \
    + [plant(0x060EC8B0 + 2 * c, 2, [0, 0x20, 0x90, 0x10, 0x7, 0x1000, 0xA0], 0.8) for c in range(0, 300)] \
    + [plant(0x060EE8B0 + 2 * c, 2, [0, 0x100, 0xF00, 0x300], 0.8) for c in range(0, 300)] \
    + [plant(bomber(0) + 20, 2, [0, 1, 2, 3, 64, 65, 66, 130], 1.0), plant(bomber(0) + 6, 1, [0, 1, 2, 3, 4], 1.0),
       plant(bomber(0) + 66, 2, [0, 0, 1], 0.9)]
case("f0606CA64", [], True, CUR + [plant(bomber(0) + 20, 2, [0, 1], 1.0), plant(0x060C062C, 2, [10, 20, 0], 0.6)]
     + [plant(bomber(i) + 22, 2, [0, 3], 0.6) for i in range(10, 50)] + [plant(bomber(i) + 4, 1, [0, 0, 0x40], 0.8) for i in range(10, 50)]
     + [plant(bomber(i) + 20, 2, [0, 1], 0.5) for i in range(10, 50)])
case("f0606EB5C", [], True, CELLS_ENV)
case("f0606EC68", [], True, CELLS_ENV)
case("f0606FE7C", [span(0, 5)], True, CELLS_ENV)
case("f06072AC8", [], True, CELLS_ENV + image(0x060B90A2, 0x060B90AA))
case("f060757DE", [span(0, 20)], True, CUR + [plant(bomber(0) + 66, 2, [0, 0, 1], 0.9)]
     + [plant(0x060C1F42 + 12 * k + o, 2, [0, 1, 3, 5], 0.8) for k in range(21) for o in (4, 6)])
case("f06077A20", [], False, CELLS_ENV + image(0x060BA8B0, 0x060BA8B8) + image(0x060B90A4, 0x060B90B0))
case("f06087390", [], False, CELLS_ENV + [plant(bomber(0) + o, 2, [0, 40, 100, 300], 0.9) for o in (24, 28)])
case("f06083D48", [], True, CUR + [plant(bomber(0) + 66, 2, [0, 0, 1], 0.9), plant(bomber(0) + 68, 2, [0, 1, 2, 5], 0.9),
                                   plant(bomber(0) + 70, 2, [0, 4], 0.9)])
case("f06083F1A", [], True, CUR + [plant(bomber(0) + 66, 2, [0, 0, 1], 0.9), plant(bomber(0) + 68, 2, [0, 1, 2, 5], 0.9),
                                   plant(bomber(0) + 70, 2, [0, 4], 0.9)])
case("f06083DC2", [], True, CUR + CHAIN + [plant(bomber(0) + 66, 2, [0, 1], 0.9), plant(bomber(0) + 68, 2, [0, 1, 2, 5], 0.9),
                                          plant(bomber(0) + 64, 2, [0, 1], 0.9)])
LEVEL = [plant(0x060C029D, 1, [0, 1, 5, 20, 200], 1.0)] + [plant(0x060BB1FC + 8 * k, 2, [k * 8], 1.0) for k in range(40)]
case("f060844B4", [], False, CUR + LEVEL)
case("f06085FB4", [], True, CUR + [plant(0x060C1F24, 2, [0, 1, 2, 3, 4, 5], 1.0)]
     + [plant(0x060C2E8E + 2 * k, 2, [0, 0, 1], 0.7) for k in range(6)])
case("f06087418", [], True, [plant(0x060C2EA8 + 2 * k, 2, [0, 1, 5], 0.5) for k in range(4)])
case("f060876E0", [], False, CELLS_ENV + image(0x060BB354, 0x060BB394)
     + [plant(bomber(0) + o, 2, [0, 40, 100, 300], 0.9) for o in (24, 28)])
case("f06087758", [], False, [plant(0x060C2EA8 + 2 * k, 2, [0, 1, 5, 7], 0.5) for k in range(4)] + [plant(0x060C062C, 2, [0, 1, 5, 7], 1.0)])
case("f060884C6", [], True, [plant(0x060D7B3C, 4, [obj(3)], 1.0), plant(obj(3) + 4, 2, [0, 0x100, 0x1D0, 0x1E0, 0x1F0, 0xFFF0], 1.0)])

STR = BUF + 0x5000
DELIM = BUF + 0x5100
CHARS = [plant(STR + k, 1, [0x61, 0x62, 0x2C, 0x20, 0], 0.8) for k in range(10)] + [plant(STR + 10, 1, [0], 1.0)] \
    + [plant(STR + 0x40 + k, 1, [0x61, 0x62, 0x2C, 0x20, 0], 0.8) for k in range(10)] + [plant(STR + 0x4A, 1, [0], 1.0)] \
    + [plant(DELIM + k, 1, [0x2C, 0x20, 0x62, 0], 0.5) for k in range(3)] + [plant(DELIM + 3, 1, [0], 1.0)]
case("f06094A24", [pick(STR), pick(0x61, 0x62, 0x2C, 0, -1, 0x20)], True, CHARS)
case("f06094A7C", [pick(0, STR, STR + 0x40), pick(DELIM)], False, [plant(0x060FA8B0, 4, [0, STR, STR + 3, STR + 0x41], 1.0)] + CHARS)
case("f06094C74", [pick(STR, STR + 0x40), pick(STR, STR + 0x40, STR + 0x41), span(0, 12)], True, CHARS)
case("f06094CC0", [pick(STR, STR + 0x40), pick(DELIM)], True, CHARS)

# the stream records 060AB4C6 and its neighbours read: a handle, the record, and the parameter block at +0x140
PAR = BUF + 0x2300
STREAM3 = BUF + 0x2500
HANDLE3 = BUF + 0x2010
PAR3 = BUF + 0x2600 + 0x200
HS = ERR + [plant(STREAM + 0x16C, 4, [0x060AB32C], 1.0), plant(STREAM + 0x170, 4, [0x060AC900], 1.0), plant(STREAM + 0x174, 4, [0x060A3F84], 1.0),
      plant(STREAM + 0x178, 4, [0x060A3F90], 1.0), plant(STREAM + 0x17C, 4, [0x060A40C0], 1.0), plant(STREAM + 0x1BC, 4, [0x060ADC82], 1.0),
      plant(STREAM + 0x1C0, 4, [0x060A4720], 1.0), plant(STREAM + 0x1C4, 4, [0x060A4BDA], 1.0), plant(STREAM + 0x1C8, 4, [0x060A4BDE], 1.0),
      plant(STREAM + 0x1CC, 4, [0x060A4C08], 1.0), plant(HANDLE, 4, [STREAM], 1.0), plant(STREAM + 0x140, 4, [PAR], 1.0), plant(HANDLE3, 4, [STREAM3], 1.0),
      plant(STREAM3 + 0x140, 4, [PAR3], 1.0), plant(PAR + 37, 1, [0, 1], 1.0), plant(PAR + 38, 1, [8, 16, 1], 1.0),
      plant(PAR3 + 37, 1, [0, 1], 1.0), plant(PAR3 + 38, 1, [8, 16, 1], 1.0)]
PCM = HS + [plant(STREAM + 56, 4, [-1, 0, 1, 2, 3, 4, 5, 9], 1.0), plant(STREAM + 100, 4, [0, 1], 1.0),
            plant(STREAM + 176, 4, [1, 4, 16, 60], 1.0), plant(STREAM + 196, 4, [0, 100, 5000], 1.0),
            plant(PAR + 56, 4, [0, 10, 1000], 1.0), plant(PAR + 4, 4, [0, 10, 50, 5000], 1.0), plant(PAR + 68, 4, [0, 20, 100], 1.0),
            plant(STREAM + 124, 4, [0, 7, 8, 20, 100], 1.0), plant(STREAM + 152, 4, [0, 40, 200], 1.0),
            plant(STREAM + 160, 4, [0, 5], 1.0), plant(STREAM + 184, 4, [0, 1], 1.0), plant(STREAM + 32, 4, [0, 100, 1000], 1.0)]
case("f060ABCCC", [], True, PCM + [plant(0x060FC168, 4, [0, HANDLE], 1.0)])
case("f060AC500", [pick(HANDLE)], False, PCM)
case("f060AD27A", [pick(HANDLE), pick(BUF + 0x5200), pick(BUF + 0x5300)], False, PCM)
case("f060AD564", [pick(HANDLE), pick(BUF + 0x5200)], False, PCM + [plant(STREAM + 52, 4, [-1, 0, 1, 2, 3, 4, 5, 9], 1.0),
                                                                    plant(STREAM + 160, 4, [0, 5], 1.0), plant(STREAM + 164, 4, [0, 100], 1.0)])
case("f060AD848", [pick(HANDLE)], True, PCM)
case("f060AE206", [], True, PCM + [plant(0x060FC214, 4, [0, HANDLE], 1.0), plant(STREAM + 108, 4, [-1, 0, 4, 8, 100], 1.0),
                                   plant(STREAM + 36, 4, [0, 5, 50], 1.0)])
case("f060ABB80", [pick(HANDLE), pick(HANDLE3)], True, PCM + [plant(STREAM3, 4, [BUF + 0x5200], 1.0)] + [plant(BUF + 0x5200 + k, 1, [c], 0.9) for k, c in enumerate(b"FILM\0")] + [plant(PAR3 + 4, 4, [10], 1.0), plant(STREAM3 + 152, 4, [100], 1.0), plant(STREAM3 + 52 + 72, 4, [8, 20, 100], 1.0),plant(STREAM3 + 56, 4, [0, 0, 1], 1.0), plant(STREAM3 + 52 + 4, 4, [0, 0, 1], 1.0),
                                                              plant(STREAM3 + 52 + 108, 4, [0, 5], 1.0)]
     + [plant(STREAM + o, 4, [5], 1.0) for o in (28, 32, 36)] + [plant(STREAM3 + o, 4, [5, 5, 6], 0.9) for o in (28, 32, 36)]
     + [plant(PAR + 56, 4, [10], 1.0), plant(PAR3 + 56, 4, [10, 10, 11], 0.9), plant(STREAM + 52 + 124, 4, [9], 1.0),
        plant(STREAM3 + 52 + 124, 4, [9, 9, 8], 0.9), plant(PAR3 + 37, 1, [0, 1], 1.0)])

RB = BUF + 0x6000
case("f060AFEA8", [pick(RB), pick(RB + 0x40), pick(RB + 0x80), pick(RB + 0x100, RB + 0x200)], True,
     [plant(RB + 112, 4, [0, 4, 16], 1.0), plant(RB + 116, 4, [RB + 0x200, RB + 0x300], 1.0), plant(RB + 0x40 + 32, 4, [RB + 0x100, RB + 0x300], 1.0),
      plant(RB + 0x80 + 38, 1, [16, 8, 0], 1.0), stack(0, [RB + 0x400]), stack(1, [0, 4, 8, 16, 40])])
case("f060AFF04", [pick(RB + 0x500, RB + 0x501, RB + 0x502), span(8, 80), pick(RB + 0x600), span(0, 40)], False,
     [stack(0, [0, 8, 10, 33, 64])])
case("f060B0B08", [pick(RB + 0x500, RB + 0x501, RB + 0x502), span(8, 80), pick(RB + 0x600), span(0, 40)], False,
     [stack(0, [0, 8, 10, 33, 64])])
case("f060B0212", [pick(RB + 0x700, RB + 0x710, RB + 0x720), pick(RB + 0x700, RB + 0x708, RB + 0x718), span(-1, 20)], False)
case("f060B027E", [pick(RB + 0x700, RB + 0x744, RB + 0x780), pick(RB + 0x740), span(0, 40), span(0, 20)], False)
case("f060B02B4", [pick(RB + 0x700, RB + 0x744, RB + 0x7C0), pick(RB + 0x740), span(0, 20), span(0, 10)], False)
case("f060B0810", [pick(HANDLE), pick(RB + 0x800)], False, [plant(HANDLE, 4, [STREAM], 1.0), plant(STREAM + 56, 4, [0, 1], 1.0)])
RING_H = [plant(HANDLE, 4, [STREAM], 1.0), plant(STREAM + 4, 4, [RB + 0x900], 1.0), plant(STREAM + 8, 4, [0x60, 0x20, 0], 1.0),
          plant(STREAM + 116, 4, [RB + 0x980], 1.0), plant(RB + 0xA00, 4, [RB + 0xB00], 1.0), plant(RB + 0xA04, 4, [RB + 0xC00], 1.0),
          plant(RB + 0xA08, 4, [RB + 0x900, RB + 0x940, RB + 0x970, RB + 0x97C], 1.0), plant(RB + 0xA0C, 4, [0, 4, 8, 32, 64, 200], 1.0)]
case("f060B0E22", [pick(HANDLE), pick(RB + 0xA00)], True, RING_H)
case("f060B0EF6", [pick(HANDLE), pick(RB + 0xA00)], True, RING_H)
case("f060B0F5E", [pick(HANDLE), pick(RB + 0xA00)], True, RING_H)

# bank lists: 060BD904 names a table of tables, and each list of entries ends with a halfword of -1
BANKP = BUF + 0x7000
BANKT = BUF + 0x7100
BANKL = BUF + 0x7200
BANKS = [plant(0x060BD904, 4, [BANKP], 1.0), plant(BANKP, 4, [BANKT], 1.0), plant(BANKP + 4, 4, [BANKT], 1.0),
         plant(0x060FBFFC, 4, [0], 1.0)] + [plant(BANKT + 4 * k, 4, [BANKL], 1.0) for k in range(8)] \
    + [plant(BANKL, 4, [0x00020000, 0x00000000, 0xFFFF0000], 1.0), plant(BANKL + 4, 4, [0xFFFF0000, 0x00010000], 1.0),
       plant(BANKL + 8, 4, [0xFFFF0000], 1.0), plant(BANKL + 20, 2, [0x8000, 0xFFFF], 1.0), plant(BANKL + 2, 2, [0, 3], 1.0),
       plant(BANKL + 22, 2, [0, 1], 1.0)]
case("f06068CC4", [span(0, 5)], False, BANKS + [plant(0x060FBFFC, 4, [0, BUF + 0x1400], 1.0)] + LIST[1:])
LISTP = BUF + 0x7400
case("f06068A5E", [pick(LISTP)], True, BANKS + [plant(0x060FBFFC, 4, [0, BUF + 0x1400], 1.0)] + LIST[1:] + [plant(LISTP + 2 * k, 2, [1, 2, 3, 0, 0xFFFF, 0xFFFF, 0xFFFF], 0.6) for k in range(6)] + [plant(LISTP + 12, 2, [0xFFFF], 1.0)])

OBJX = BUF + 0x2C00
case("f060A609A", [pick(OBJX), span(0, 3), span(0, 3), span(0, 3)], False,
     [plant(OBJX + 108 + 24, 4, [0, 5, 100], 1.0), plant(OBJX + 108 + 48, 4, [0, 1], 1.0), plant(OBJX + 108 + 52, 4, [0, 0, 5, 6, 3], 1.0),
      plant(OBJX + 108 + 12, 4, [0, BUF + 0x2D00], 1.0), plant(OBJX + 108 + 28, 4, [0, 10, 200], 1.0), plant(BUF + 0x2D00 + 12, 4, [0, 5, 50], 1.0)])
case("f060A6364", [pick(0, 1), pick(BUF + 0x3000), span(-3, 3), pick(BUF + 0x3100)], False, [stack(0, [-5, 0, 5]), stack(1, [0, 0, 0, 0, 4, 12, 64])])
case("f060A66C8", [span(-2, 6), pick(BUF + 0x3300), pick(BUF + 0x3400)], False)

DEVP = BUF + 0x7800
DEVC = [plant(0x060FC084, 4, [DEVP], 1.0)]
case("f060A7D2E", [span(0, 8), span(0, 8), span(0, 3), span(0, 3)], False,
     DEVC + [plant(DEVP + 24 + k, 1, [0, 1, 1], 0.8) for k in range(10)] + [plant(DEVP + 0x348, 4, [0, 0, 1, 2], 1.0)])
case("f060A7DA6", [span(-3, 28), span(0, 3), span(0, 3)], False, DEVC + [plant(DEVP + k, 1, [0, 1, 1], 0.8) for k in range(26)])
case("f060A86F8", [pick(BUF + 0x7900)], False, DEVC + [plant(DEVP + 0x348, 4, [0] * 6 + [7, 7, 1, 2, 3, 4, 5], 1.0)])

# the block decoders: a byte stream, two books of 256 pointers to 16-byte blocks, and a destination of rows
VQ_SRC = BUF + 0x8000
VQ_A = BUF + 0x8400
VQ_B = BUF + 0x8800
VQ_BLOCKS = BUF + 0x8C00
VQ_DST = BUF + 0x9000
VQ = [plant(VQ_SRC + k, 1, list(range(256)), 1.0) for k in range(160)] \
    + [plant(book + 4 * k, 4, [VQ_BLOCKS + 16 * (k & 7)], 1.0) for book in (VQ_A + 0x200, VQ_B + 0x200) for k in range(-128, 128)] \
    + [plant(VQ_BLOCKS + 4 * k, 4, [0x11223344, 0x55667788, 0x99AABBCC, 0xDDEEFF00], 1.0) for k in range(32)]
VQ_ARGS = [pick(VQ_DST), pick(64, 128), pick(16, 32, 4, 3), pick(8, 16, 4)]
case("f060AF2EA", VQ_ARGS, False, VQ + [stack(0, [VQ_SRC]), stack(1, [VQ_A + 0x200]), stack(2, [VQ_B + 0x200]), stack(3, [0, 1])])
case("f060AF4BE", VQ_ARGS, False, VQ + [stack(0, [VQ_SRC]), stack(1, [VQ_A + 0x200]), stack(2, [VQ_B + 0x200])])

case("f060A3C58", [span(0, 3), span(0, 3), span(0, 3), span(0, 3)], False,
     PCM + [plant(0x060BB98C, 4, [0] * 30 + [0xFFFFFFFF], 1.0), plant(0x060FC168, 4, [0, HANDLE], 1.0),
            plant(0x060FC0E4, 4, [0, 0x060FC0E8 + 12, 0x060FC0E8], 1.0)]
     + [plant(0x060BBA9C + 4 * k, 4, [1 << k], 1.0) for k in range(32)] + [plant(0x060FC0E8 + 4 * k, 4, [STREAM], 1.0) for k in range(32)])
case("f060A4A02", [span(0, 3), span(0, 3), span(0, 3), span(0, 3)], False,
     PCM + [plant(0x060FC210, 4, [0] * 30 + [0xFFFFFFFF], 1.0), plant(0x060FC214, 4, [0, HANDLE], 1.0),
            plant(0x060FC18C, 4, [0, 0x060FC190 + 12, 0x060FC190], 1.0)]
     + [plant(0x060B12F8 + 4 * k, 4, [1 << k], 1.0) for k in range(32)] + [plant(0x060FC190 + 4 * k, 4, [STREAM], 1.0) for k in range(32)])
case("f060AB12E", [pick(*[0x060FC0E8 + 4 * k for k in range(33)]), span(0, 3), span(0, 3), span(0, 3)], True, PCM
     + [plant(0x060BB98C, 4, [0] * 30 + [0xFFFFFFFF], 1.0)] + [plant(0x060BBA9C + 4 * k, 4, [1 << k], 1.0) for k in range(32)]
     + [plant(0x060FC0E8 + 4 * k, 4, [STREAM], 1.0) for k in range(32)])

# a creation request: a record whose name at +52 must match the library's string, and the sizes and buffers it asks for
DESC = BUF + 0xA000
NAMEREC = BUF + 0xA100
HELLO = b"Hi! Come come everybody.\0"
CREATE = ERR + [plant(DESC, 4, [NAMEREC, 0, NAMEREC], 0.9), plant(DESC + 4, 4, [0, 8, 100, 0x4000], 0.9),
                plant(DESC + 8, 4, [0, BUF + 0xA400], 0.9), plant(DESC + 12, 4, [0, 8, 100, 0x4000], 0.9),
                plant(DESC + 16, 4, [0, BUF + 0xA800], 0.9), plant(DESC + 20, 4, [0, 8, 100, 0x4000], 0.9),
                plant(0x060BB98C, 4, [0, 0, 1], 1.0)] \
    + [plant(NAMEREC + 52 + k, 1, [c], 0.9) for k, c in enumerate(HELLO)] \
    + [plant(0x060BBA9C + 4 * k, 4, [1 << k], 1.0) for k in range(32)]
case("f060A391C", [pick(0, DESC), span(0, 3), span(0, 3), span(0, 3)], True, CREATE)
CREATE_CD = ERR + [plant(DESC, 4, [NAMEREC, 0, NAMEREC], 0.9), plant(DESC + 4, 4, [0, BUF + 0xA400, BUF + 0xA400], 0.9),
                   plant(DESC + 8, 4, [-5, 0, 8, 100, 0x4000], 0.9), plant(DESC + 12, 4, [0, BUF + 0xA800], 0.9),
                   plant(DESC + 16, 4, [-5, 0, 8, 100, 0x4000], 0.9), plant(0x060FC210, 4, [0, 0, 1], 1.0)] \
    + [plant(0x060B12F8 + 4 * k, 4, [1 << k], 1.0) for k in range(32)] \
    + [plant(NAMEREC + 52 + k, 1, [c], 0.9) for k, c in enumerate(HELLO)]
case("f060A45FE", [pick(0, DESC), span(0, 3), span(0, 3), span(0, 3)], True, CREATE_CD)
# 0600996A takes one of the 18 sound records at 060BC190: a free one has 0 at +80, and a busy one whose word at +20 equals the buffer traps
# 06008A6A reads its source through the four pointers at 060BD8D4, which point into work RAM-L
PALTAB = [plant(0x060BD8D4 + 4 * k, 4, [0x00200000, 0x00254000], 1.0) for k in range(4)] \
    + [plant(base + 4 * k, 4, [0x060C4000], 1.0) for base in (0x00200000, 0x00254000) for k in range(12)]
FREE = [plant(0x060BC190 + 88 * k + 80, 1, [0, 0, 1], 0.7) for k in range(18)] + [plant(0x060BC190 + 88 * k + 20, 4, [0], 1.0) for k in range(18)]
case("f0606F482", [], True, CUR + MOVER + [plant(bomber(0) + 42, 2, [0, 5, 128], 1.0), plant(0x060C062C, 2, [0, 1, 2, 3], 1.0)])
case("f06072E5E", [], True, CUR + MOVER + [plant(bomber(0) + o, 2, [0, 100, 300, 0xFFF0], 0.9) for o in (24, 28, 68, 70)])
