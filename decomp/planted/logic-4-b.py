from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

SP = 0x060FFFF0        # r15 on entry; the arguments a caller passed on the stack start here
BUF = 0x060C5000


def stack(k, values, chance=1.0):
    """The k-th word above the stack pointer the function is entered with."""
    return plant(SP + 4 * k, 4, values, chance)


# The VDP1 command list: the cursor, the record table and the pool all point at memory the check maps.
VDP1 = [plant(0x060FC004, 4, [BUF, BUF + 0x400], 1.0), plant(0x060FBF84, 4, [BUF + 0x800], 1.0),
        plant(0x060FBFD0, 4, [0, 0x1234], 0.8), plant(0x060FC008, 4, [0, 0x77], 0.8),
        plant(0x060FBF98, 4, [0, 0, 1], 1.0)]
CMD_FLAGS = pick(0, 8, 0x28, 0x38, 0x10, 0x1008, 0xF00, 0x300)

for _a in ("0609FCE8", "0609FD9E", "0609FE50"):
    case("f" + _a, [span(0, 3), CMD_FLAGS, span(0, 0x300), ptr(BUF + 0xC00, 0x100, 2)], False,
         VDP1 + [stack(0, [0xFFFF, 0, 0x1234, 0xFFFF0003])])
for _a in ("0609FF14", "060A0018", "060A0158"):
    case("f" + _a, [span(0, 3), pick(0, 0x100, 0x1004, 8), pick(0, 8, 0x28, 0x38, 0xFFFF), pick(0xFFFF, 0, 5, 0x1234)], False,
         VDP1 + [stack(0, [0, 1, 3, 12], 1.0), stack(1, [BUF + 0xC00, BUF + 0xC40], 1.0), stack(2, [0xFFFF, 0, 5, 0x1234]),
                 plant(BUF + 0x800, 2, [0, 5, 0x1234, 0xFFFF], 0.5)])

case("f06097184", [ptr(BUF, 0x80, 4), pick(0, BUF + 0x100), pick(0, BUF + 0x180), pick(0, BUF + 0x200)], False,
     [stack(k, [0, BUF + 0x300 + 8 * k]) for k in range(4)])
case("f0609F00A", [], True,
     [plant(0x060FBF48, 4, [BUF], 1.0), plant(0x060FBF64, 4, [BUF + 16 * k for k in range(9)], 1.0)]
     + [plant(BUF + 16 * k, 1, [0, 1, 7], 0.6) for k in range(8)])
case("f0609F708", [span(0, 30), pick(0, 5, 8, 9, 39, 40, 41, 100), span(0, 0xFFFF), span(0, 40)], False,
     [plant(0x060FBF84, 4, [BUF + 0x800], 1.0), plant(0x060FBFB4, 4, [BUF + 0x1000], 1.0),
      plant(BUF + 0x800, 2, [0, 5], 0.4)]
     + [plant(BUF + 0x800 + 10 * k + 8, 2, [0, 1, 40, 0x300], 0.7) for k in range(30)]
     + [stack(0, [1, 2, 7, 20, 3]), stack(1, [0, BUF + 0x2000, BUF + 0x2000])])

ARENA = 0x00200000
N0, N1, N2 = ARENA + 0x100, ARENA + 0x2000, ARENA + 0x4000
case("f060A0338", [pick(0x10, 0x20, 0x3C, 0x3FC, 0x3FC, 0x3FC, 0x3FC, 0x400, 0x40, 0x40, 0x40, 0x40, 0x44, 0x3F8, 0x410, 0x414, 0x7F0, 0x800, 0x808, 0xFFF, 0x1000, 0x0, 0x7000),
                   pick(1, 1, 1, 2, 3, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x100, 0x100)], False,
     [plant(0x060FBFB4, 4, [ARENA], 1.0), plant(0x060FBFFC, 4, [N0], 1.0),
      plant(N0, 4, [N1, 0], 1.0), plant(N1, 4, [N2, 0], 1.0), plant(N2, 4, [0], 1.0),
      plant(N0 + 4, 2, [8, 8, 8, 4, 1], 1.0), plant(N1 + 4, 2, [4, 2, 8], 1.0), plant(N2 + 4, 2, [2, 1, 4], 1.0)])

LIST = BUF + 0x1400
NODES = [BUF + 0x1500 + 0x40 * k for k in range(4)]
OBJS = [BUF + 0x2000 + 0x80 * k for k in range(4)]
CHAIN = ([plant(LIST, 4, [NODES[0]], 1.0)]
         + [plant(NODES[k] + 8, 4, [NODES[k + 1], NODES[k + 1], 0], 1.0) for k in range(3)] + [plant(NODES[3] + 8, 4, [0], 1.0)]
         + [plant(NODES[k] + 20, 4, [OBJS[k]], 1.0) for k in range(4)]
         + [plant(NODES[k] + 16, 4, [BUF + 0x2400 + 0x20 * k], 1.0) for k in range(4)]
         + [plant(NODES[k] + 44, 1, [0, 1, 2, 3, 6, 8, 10, 12], 1.0) for k in range(4)])
case("f060A12CC", [pick(LIST)], True,
     CHAIN + [plant(LIST + 8, 4, [0, 0, 5]), plant(LIST + 4, 4, [0, 0, 3])]
     + [plant(NODES[k] + 44, 1, [2, 3, 6, 2, 0], 1.0) for k in range(4)])
case("f060A1806", [pick(LIST)], False, CHAIN + [plant(LIST + 20, 4, [0, 5, 100, -1])])
case("f060A191E", [pick(LIST), span(-5, 200)], True, CHAIN + [plant(LIST + 20, 4, [0, 5, 100, -1])])
TASK, FIRST, OBJ, REC = BUF + 0x1800, BUF + 0x1900, BUF + 0x1A00, BUF + 0x1B00
case("f060A1D3E", [pick(TASK), span(-5, 50), span(-5, 50), pick(0, 1, 5)], True,
     [plant(TASK, 4, [FIRST], 1.0), plant(FIRST + 20, 4, [0, 10, 40, -3], 1.0), plant(TASK + 20, 4, [OBJ], 1.0),
      plant(OBJ + 28, 4, [0, 5], 0.6), plant(TASK + 16, 4, [REC], 1.0), plant(REC + 156, 4, [0, 1], 0.6),
      plant(TASK + 40, 4, [0x7FFFFFFF, 30, 60, 5], 1.0), plant(TASK + 44, 1, [0, 1, 4, 5, 8, 9, 12, 13], 1.0),
      plant(REC + 152, 4, [0, 2], 0.6), plant(REC + 116, 4, [0, 5], 0.6), plant(REC + 112, 4, [0, 3], 0.6)])

SLOT_BASE = 0x060FC0E8
case("f060A3E10", [pick(0, 0, 0, SLOT_BASE, SLOT_BASE + 4, SLOT_BASE + 8)], True,
     [plant(0x060BB98C, 4, [0xFFFFFFFF, 0xFF, 0x100, 0], 1.0)]
     + [plant(0x060BBA9C + 4 * k, 4, [0, 1, 0xFF, 0x300, 0xFFFFFFFF], 1.0) for k in range(32)]
     + [plant(SLOT_BASE + 4 * k, 4, [BUF + 0x2800 + 0x80 * k], 1.0) for k in range(32)]
     + [plant(BUF + 0x2800 + 0x80 * k + 60, 4, [0, 1, 1, 2], 1.0) for k in range(32)])

# The CD block is not modelled by check.py, so these only run where its registers are mapped as plain memory.
# CD_BLOCK=1 adds the plants that need that.
import os

CD = []
if os.environ.get("CD_BLOCK"):
    CD = [plant(0x25890008, 2, [0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0243, 0x00C3, 0x0083, 0x0003, 0x0241, 0x0001], 0.99),
          plant(0x060FA8B8, 2, [0, 0xFFFF, 1, 0x0800], 0.9),
          plant(0x25890018, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00, 0x0600, 0x0700, 0x0F00, 0xFF00, 0x8100], 1.0)]
# The same, always: a command that fails early leaves the response unwritten, and 06095434 then copies the
# stack garbage in it, which differs between the two sides.
CD_FULL = [plant(0x25890008, 2, [0xFFFF, 0x00C3, 0x0243, 0x0083, 0x0003], 1.0),
           plant(0x25890018, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00, 0x0600, 0x0700, 0x0F00], 1.0)] if CD else []
CMDBUF = BUF + 0x3000
# A mask that never matches loops 0x240000 times, past the 10 million steps the game's side may take.

POOL = BUF + 0x5000
POOLS = ([plant(0x060FC00C, 4, [POOL], 1.0), plant(POOL, 4, [BUF + 0x5100], 1.0), plant(POOL + 4, 4, [0, 1, 2, 4, 6]),
          plant(POOL + 8, 4, [BUF + 0x5800], 1.0), plant(POOL + 12, 4, [0, 1, 2, 4, 6])]
         + [plant(BUF + 0x5100 + 60 * k + 58, 1, [0, 1], 0.7) for k in range(8)]
         + [plant(BUF + 0x5800 + 48 * k + 45, 1, [0, 1], 0.7) for k in range(8)])
case("f060A04EE", [], True, POOLS)
case("f060A0558", [], True, POOLS)
case("f0609FA48", [], False,
     [plant(0x060FC002, 2, [0xFFFF, 0, 5], 0.7), plant(0x060FBFAC, 4, [BUF + 0x6000], 1.0), plant(0x060FBF90, 4, [0, 1, 3], 1.0),
      plant(0x060FBFBC, 4, [BUF + 0x6800], 1.0), plant(0x060FBF68, 4, [1, 320, 352], 1.0), plant(0x060FBF6C, 4, [1, 224, 240], 1.0)])

OWNER = BUF + 0x5C00
LNODES = [BUF + 0x5E00 + 0x40 * k for k in range(4)]
LOBJS = [BUF + 0x6200 + 0x80 * k for k in range(4)]
LCHAIN = ([plant(OWNER + 4, 4, [LNODES[0], LNODES[0], 0], 1.0), plant(OWNER + 12, 4, [LNODES[1], 0])]
          + [plant(LNODES[k] + 12, 4, [LNODES[k + 1], LNODES[k + 1], 0], 1.0) for k in range(3)]
          + [plant(LNODES[k] + 20, 4, [LOBJS[k]], 1.0) for k in range(4)]
          + [plant(LOBJS[k] + 28, 4, [0, 0, 5], 1.0) for k in range(4)])
case("f060A057E", [pick(OWNER)], True, LCHAIN)
case("f060A09BC", [pick(OWNER)], False, LCHAIN)

case("f060A64F6", [pick(0, BUF + 0x7000, BUF + 0x7000), span(0, 3), ptr(BUF + 0x7100, 0x40, 4), span(0, 3)], False,
     [stack(0, [0, 1, 2, 3, 4, 5, 7, 8, 12, 13])])
case("f060A6938", [ptr(BUF + 0x7200, 0x40, 4), pick(0, BUF + 0x7300), pick(0, BUF + 0x7304), pick(0, BUF + 0x7308)], False,
     [stack(k, [0, BUF + 0x7310 + 8 * k]) for k in range(4)] + [plant(BUF + 0x7200 + 15, 1, [0, 8, 16, 24, 7], 0.9)])
case("f060A6336", [], True, [plant(0x060FC068, 1, [1, 0, 2])])

# The CD driver's record, 060FC084 points at it: busy flags at +0 and +24, the queue at +0x1DC.
DEVREC = BUF + 0x8000
DEVP = [plant(0x060FC084, 4, [DEVREC], 1.0)]
FLAGS = [plant(DEVREC + k, 1, [0, 1, 1], 0.8) for k in range(48)]
case("f060A777E", [pick(BUF + 0x7500)], True, DEVP + [plant(DEVREC + 24 + k, 1, [1], 0.93) for k in range(24)])
case("f060A77E0", [pick(BUF + 0x7500)], True, DEVP + [plant(DEVREC + k, 1, [1], 0.93) for k in range(24)])

ID = [0x77, 0x78, 0x99]
DEVID = [plant(DEVREC + 56, 4, ID, 1.0)]
HANDLES = [plant(DEVREC + k, 1, [0, 1, 1], 0.9) for k in range(6)] + [plant(DEVREC + 24 + k, 1, [0, 1, 1], 0.9) for k in range(6)]
case("f060A7A12", [pick(255, 255, 0, 1, 5, 23), pick(*ID)], True, DEVP + DEVID + HANDLES)
case("f060A7A5E", [ptr(CMDBUF, 0x40, 2), pick(*ID)], True, DEVP + DEVID + CD + [plant(0x060FC080, 4, [0, 0, -13, 5])])
case("f060A7CC6", [ptr(CMDBUF, 0x40, 2), pick(*ID)], True, DEVP + DEVID + CD + [plant(0x060FC080, 4, [0, 0, -13, 5])])
case("f060A7ACA", [span(0, 9), span(0, 9), span(0, 9), span(0, 9)], True,
     DEVP + [plant(DEVREC + 0x30C, 4, [0, 0, 1]), stack(0, [BUF + 0x7A00]), plant(DEVREC + 0x1DC, 4, [0, 3]),
             plant(DEVREC + 52, 4, [-1, 5])] + CD)
case("f060A7B24", [span(0, 9), span(0, 9), span(0, 9)], True,
     DEVP + [plant(DEVREC + 0x328, 4, [0, 0, 1]), plant(DEVREC + 52, 4, [-1, -1, 5])] + CD)
case("f060A7BB0", [pick(3, 4), span(0, 9), span(0, 9)], True,
     DEVP + [plant(DEVREC + 0x338, 4, [0, 0, 1]), plant(DEVREC + 52, 4, [3, 4, -1])] + CD)
case("f060A7DE6", [pick(-1, -1, 0, 1, 5), pick(0, 1, 2, 3, 23, 30), span(0, 100)], True,
     DEVP + [plant(DEVREC + 0x360, 4, [0, 0, 0, 1])] + [plant(DEVREC + k, 1, [1], 0.9) for k in range(6)]
     + [plant(DEVREC + 24 + k, 1, [1], 0.9) for k in range(6)] + CD)
case("f060A7E66", [pick(255, -2, 0, 1, 5, 23, 24, -1), pick(0, 1, 2, 23, 24, -1), pick(255, -2, -3, 0, 1, 3, 23, 24)], True,
     DEVP + [plant(DEVREC + 0x1DC, 4, [0, 1, 5, 23, 24]), plant(DEVREC + 0x1E0, 4, [0, 1])]
     + [plant(DEVREC + k, 1, [1], 0.93) for k in range(8)] + [plant(DEVREC + 24 + k, 1, [1], 0.93) for k in range(8)] + CD)
case("f060A8402", [pick(BUF + 0x7B00)], True,
     DEVP + [plant(DEVREC + 0x30C, 4, [0, 1, 1, 2, 2, 3, 3, 4]), plant(DEVREC + 52, 4, [-1, -1, 3]),
             plant(DEVREC + 0x310, 4, [1, 5]), plant(DEVREC + 0x314, 4, [0, 3, 40]), plant(DEVREC + 0x318, 4, [1, 10, 100, 0]),
             plant(DEVREC + 0x320, 4, [BUF + 0x7B40]), plant(BUF + 0x7B40, 4, [BUF + 0x7B60]),
             plant(DEVREC + 0x324, 4, [0, BUF + 0x7B80, BUF + 0x7B80])] + CD)
case("f060A881C", [pick(BUF + 0x7C00)], True,
     DEVP + [plant(DEVREC + 0x360, 4, [0, 1, 1, 2, 2, 3, 3, 4, 4]), plant(DEVREC + 0x364, 2, [0, 1, 5, 40, 0xFFFD, 7]),
             plant(DEVREC + 0x366, 2, [0, 1, 5]), plant(DEVREC + 0x368, 4, [BUF + 0x7C40, BUF + 0x7C40]),
             plant(0x060FC080, 4, [0, 0, 0, -13, 5])] + CD
     + ([plant(0x25890020, 2, [0, 0, 0xFFFF]), plant(0x25890024, 2, [0, 3, 6, 100, 1]), plant(0x2589001C, 2, [0, 1, 5, 40, 100])]
        if CD else []))
case("f060A8C10", [], False, DEVP + CD)
OB = BUF + 0x9000
OBJ_PL = ([plant(OB + 12, 4, [BUF + 0x9100], 1.0), plant(BUF + 0x9100 + 20, 4, [BUF + 0x9200], 1.0), plant(OB + 20, 4, [0, 5, 100, 1000]),
           plant(OB + 52, 4, ID, 1.0), plant(0x060FC00C, 4, [POOL], 1.0), plant(0x060FC084, 4, [DEVREC], 1.0), plant(DEVREC + 56, 4, ID, 1.0),
           plant(0x060FC080, 4, [0, 0, -13, 5])] + CD)
case("f060AAA6C", [pick(OB)], True, OBJ_PL)
case("f060AAAEE", [pick(OB)], True, OBJ_PL)
case("f060AA39C", [span(0, 0x3FFFF), span(0, 0x3FFFF), ptr(BUF + 0x7F80, 0x10, 1), span(0, 255)], False, [stack(0, [0, 0x7F, 0xFF, 0x0F, 0xAA])])
case("f060AFA28", [span(0, 31)], True, [plant(0x25A00404, 4, [0, 0x100, 0x1000], 1.0)])
case("f060B0392", [span(0, 31)], True, [plant(0x25A00404, 4, [0, 0x100, 0x1000], 1.0)])

STR = BUF + 0xA000
ST = BUF + 0xA100
SEC = BUF + 0xA600
VALS = [0, 1, 8, 16, 100, 1000, 4096, 0x1000, 3000]


def stream_field(off, values, chance=1.0):
    """A word of the stream record, off bytes past the record's own +48."""
    return plant(ST + 48 + off, 4, values, chance)


STREAM_BASE = [plant(STR, 4, [ST], 1.0), plant(ST + 0x140, 4, [SEC], 1.0), plant(SEC + 38, 1, [8, 0, 4], 1.0),
               plant(ST + 12, 4, [0, BUF + 0xA800], 1.0)]
STREAM_FIELDS = [stream_field(o, VALS, 0.9) for o in (4, 8, 12, 16, 32, 40, 44, 52, 56, 60, 64, 68, 76, 88, 92, 96, 100, 108, 116, 128)]
OUTS = [stack(0, [BUF + 0xAA00 + 4 * k for k in range(1)])]
case("f060AFF98", [pick(STR), pick(BUF + 0xAB00), pick(BUF + 0xAB04), pick(BUF + 0xAB08)], False,
     STREAM_BASE + OUTS + [plant(ST + 52 + o, 4, VALS, 0.9) for o in (112, 116, 120, 128, 136, 144)]
     + [plant(ST + 52 + o, 4, [0], 0.7) for o in (112, 128, 136, 144)])
case("f060B0B9C", [pick(STR), pick(BUF + 0xAB00), pick(BUF + 0xAB04), pick(BUF + 0xAB08)], True,
     STREAM_BASE + OUTS + [stream_field(o, VALS, 0.9) for o in (40, 88, 92, 96, 100, 108, 116)]
     + [stream_field(o, [0], 0.7) for o in (92, 100, 108, 116)])
case("f060B0C78", [pick(STR), span(0, 200)], True,
     STREAM_BASE + [stream_field(o, VALS, 0.9) for o in (40, 88, 92, 96, 100, 108, 116, 76)]
     + [stream_field(28, [0, 1, 1, 2], 1.0), stream_field(36, [0, 1, 1, 2], 1.0)])
case("f060B1154", [pick(STR)], True,
     STREAM_BASE + [stream_field(o, VALS, 0.9) for o in (40, 88, 92, 96, 100, 108, 116, 76, 32, 48, 60, 64, 104, 0x94)]
     + [stream_field(28, [1, 2, 3, 4, 1, 2], 1.0), stream_field(36, [0, 1, 1, 2], 1.0)])

# 0609799C reads a fifth stack argument 16 bytes above the stack pointer, past the end of work RAM, and
# 0609E28C waits on the SMPC's SF flag, which stays set in plain memory; both need the harness's extra memory.
KEYS = BUF + 0x1100
SND = 0x060E0000
SRC = 0x060E1000
