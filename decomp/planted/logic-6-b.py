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


SP = 0x060FFFF0                 # r15 on entry
SENT = 0xFFFFFFF0               # the address the interpreter's call returns to
CURRENT_PTR = 0x060D7768
MOVER_PTR = 0x060D7B3C
BUF = 0x060C5000
RET = 0x0600660C                # an rts


def stack(k, values, chance=1.0):
    """The k-th word above the stack pointer the function is entered with."""
    return plant(SP + 4 * k, 4, values, chance)


# A code tail that pops its caller's saved registers and pr: every word of the frame returns.
FRAME_WORDS = [stack(k, [SENT]) for k in range(4)]
CUR = [plant(CURRENT_PTR, 4, [bomber(0), bomber(1)], 1.0)]
MOV = [plant(MOVER_PTR, 4, [obj(3), obj(4)], 1.0)]
# 0606D410 ends a state by jumping through the word at +4 of the record 060E2150 points at; let it return.
NEXT = [plant(0x060E2150, 4, [BUF + 0x3000], 1.0), plant(BUF + 0x3004, 4, [RET], 1.0)]

for _a in ("0606E38C", "0606E3C2", "06070024", "06075710", "06077870", "0607A420", "0607A5EA", "0607BC86",
           "0607BCB6", "060846D2", "06085EC6", "06087C68", "06087C98", "0608905E", "06089080", "06089752",
           "0608BE1C"):
    case("f" + _a, [], False, FRAME_WORDS + CUR + MOV + NEXT)

# The 84-byte object whose state the call changes, and the state asked for.
STATE = ([plant(0x060C1AA8, 2, [3, 4], 1.0)] + [plant(bomber(i) + 80, 2, [0, 1, 2, 3, 4, 9], 1.0) for i in (0, 1)]
         + [plant(obj(k) + 50, 2, [0, 1, 2, 3, 6, 8, 9, 15], 1.0) for k in (3, 4)])
case("f06087C82", [], False, FRAME_WORDS + CUR + MOV + NEXT + STATE)

# The 8-byte link records: the byte at 2 names the next, and 0 ends the chain.
CHAIN = [plant(0x060D776C + 8 * k + 2, 1, [0, k + 1], 1.0) for k in range(60)] + [plant(0x060D776C + 8 * 60 + 2, 1, [0], 1.0)]
CHAIN += [plant(0x060D776C + 8 * k + 1, 1, [k - 1], 1.0) for k in range(2, 61)] + [plant(0x060D776C + 9, 1, [2, 5, 30], 1.0)]
# The handlers 0606B6BC picks by the halfword at +46 of the current object.
HANDLERS = (image(0x060B90EC, 0x060B90EC + 32) + [plant(bomber(i) + 46, 2, [0, 1, 2, 3], 1.0) for i in (0, 1)]
            + [plant(obj(k) + 48, 2, [0, 1, 2, 4, 6], 0.9) for k in (3, 4)] + [plant(bomber(i) + 80, 2, [0, 1, 2, 4], 0.9) for i in (0, 1)]
            + [plant(0x060C1AA8, 2, [3, 4], 1.0)] + [plant(obj(k) + 50, 2, [0, 1, 2, 3, 6, 8, 9, 15], 1.0) for k in (3, 4)])
PLAYER = [plant(0x060C062C, 2, [0, 1, 2, 3], 1.0)]
ENV = FRAME_WORDS + CUR + MOV + NEXT + CHAIN + PLAYER
# The first two bombers' flag byte at +4 and the cells they stand on, for the checks 0606BF22 and 0606BE44 make.
BOMBERS = ([plant(bomber(k) + 4, 1, [0, 0, 0x80], 0.9) for k in (0, 1)] + [plant(bomber(k) + 64, 2, [0, 1], 0.95) for k in (0, 1)]
           + [plant(0x060C1F42 + 12 * k + 2, 2, [0, 16, 100], 0.7) for k in range(4)]
           + [plant(0x060C1F42 + 12 * k + 8, 2, [0, 1, 2], 0.9) for k in range(4)])
for _a, _r in (("0606F458", False), ("06071AEE", False),
               ("060723D8", False), ("06073432", False), ("06073968", False), ("06073AC0", False), ("06073B32", True),
               ("06073F74", False), ("060743A6", False), ("060743AA", False), ("06074E14", False), ("06077024", False),
               ("0607B134", True), ("0607C1A0", False), ("060845BC", True), ("06084794", False),
               ("0608479C", False), ("060847A4", True), ("06086D52", False), ("06087374", True), ("060873DE", False),
               ("06087406", False), ("06087662", True)):
    case("f" + _a, [], _r, ENV)
ANY = ("any",)
case("f0607EA10", [], True, ENV + BOMBERS)
for _a in ("0606EE32", "0606EE98", "0606F1C4"):
    case("f" + _a, [ANY, ANY, ANY, ANY], False, ENV + HANDLERS)
case("f06083BC6", [], False, ENV + [plant(CURRENT_PTR, 4, [bomber(0), bomber(1)], 1.0)]
     + [plant(bomber(i) + 40, 2, [0, 1, 5, 20], 1.0) for i in (0, 1)])
case("f060840C0", [pick(0, 1, 4, 0x4000, 0xFFFF, 0x10000, 0x80000000, 0xFFFFC000)], False, ENV)

# A handle: a word that names a record of about 0x100 bytes, the record's state words at +52 and +56.
H = BUF + 0x4000
REC = BUF + 0x4100
HANDLE = [plant(H, 4, [REC], 1.0), plant(0x060FC00C, 4, [REC], 1.0)]
STATES = [plant(REC + 56, 4, [0, 1, 2, 3, 4, 5], 1.0), plant(REC + 52, 4, [0, 1, 2, 3, 4, 5], 1.0)]
# The sound driver's mailbox: the word at 25A00404 offsets 16-byte slots, whose first byte is clear when the slot is free.
SOUND = ([plant(0x25A00404, 4, [0x1000], 1.0)] + [plant(0x25A01000 + 16 * k, 1, [0], 1.0) for k in range(8)]
         + [plant(REC + 20, 4, [0, 1, 2, 3], 1.0), plant(REC + 24, 4, [0, 1, 2, 3], 1.0), plant(REC + 160, 4, [0, 5], 0.8)])
PTRS = [plant(0x06000324, 4, [0, 1], 1.0), plant(REC + 84, 4, [0, 1], 1.0), plant(REC + 144, 4, [0, 1, 8, 0x1000, 0xFFFFF000, 0xFFFFFFF0], 0.95),
        plant(REC + 88, 4, [0, 4, 20], 0.9), plant(0x060FC21C, 4, [0, BUF + 0x8000], 0.9), plant(0x060FC220, 4, [0, BUF + 0x8100], 0.9)]
for _a, _args, _r in (("060ABB28", [pick(H), ANY], False), ("060ABB6C", [pick(H), ANY], False),
                      ("060AD6C4", [pick(H), ANY], False), ("060AD6CA", [pick(H), ANY], False), ("060AD6D0", [pick(H), ANY], False),
                      ("060ADBA0", [pick(H)], True), ("060AE0E0", [pick(H), ANY], False), ("060AE0E8", [pick(H), ANY], False),
                      ("060AE0F0", [pick(H)], False), ("060AE1E6", [pick(H), ANY], False), ("060AAE52", [pick(H), ANY, ANY, ANY], False)):
    case("f" + _a, _args, _r, HANDLE + STATES + SOUND)

for _a in ("060A5076", "060AF9A8", "060B02F0"):
    case("f" + _a, [span(-5, 40)], False, [])
MEM = BUF + 0x6000
case("f060B0142", [ptr(MEM, 0x40, 1), ptr(MEM + 0x40, 0x40, 1), span(8, 24), span(0, 8)], False, [])
case("f060B0180", [ptr(MEM, 0x40, 4), ptr(MEM + 0x80, 0x80, 4), span(8, 24), span(0, 8)], False, [])

# The error callbacks of the two handle layers: none, or one that returns at once.
CALLBACKS = [plant(0x060BB994, 4, [0, RET], 1.0), plant(0x060FC228, 4, [0, RET], 1.0)]
HPLANTS = HANDLE + CALLBACKS + STATES + [plant(REC + 212, 4, [0], 1.0)]
for _a, _r in (("060A3AE0", False), ("060A3AF4", False), ("060A3BFC", False), ("060A3ED4", True), ("060A4060", False),
               ("060A4074", False), ("060A4838", True), ("060A4984", False)):
    case("f" + _a, [pick(0, H), ANY, ANY, ANY], _r, HPLANTS)
case("f060A4810", [pick(0, H), pick(0, 0, 1, 2), ANY, ANY], False, HPLANTS + SOUND + PTRS + [plant(REC + 52, 4, [1, 4, 4, 5], 1.0)])
case("f060A49B4", [pick(0, H), ANY, ANY, ANY], False, HPLANTS + SOUND)
case("f060A11EA", [ANY], True, HANDLE + [plant(REC + 28, 4, [0, 5], 1.0)])
case("f060AE234", [pick(0, H)], False, HANDLE + CALLBACKS + STATES + [plant(0x060FC214, 4, [H], 1.0), plant(REC + 52, 4, [0, 1, 2, 3, 5], 1.0),
                                                                    plant(REC + 48 + 4, 4, [0, 1, 2, 3, 5], 1.0)])
case("f060ABD34", [pick(0, H), ANY, ANY, ANY], False, HPLANTS + SOUND + [plant(0x060FC168, 4, [H], 1.0)])

# A request object, its node at +8, and the record the node names at +20.
OBJ = BUF + 0x7000
NODE = BUF + 0x7100
INFO = BUF + 0x7200
case("f060A197E", [pick(OBJ)], True, [plant(OBJ + 8, 4, [NODE], 1.0), plant(NODE + 20, 4, [INFO], 1.0)])

# 060A4CB4 pops its return address and jumps to the code address kept at 0600026C.
case("f060A4CA2", [ANY, ANY, ANY, ANY], True, FRAME_WORDS + [plant(0x0600026C, 4, [0x0600A4B6], 1.0)])
