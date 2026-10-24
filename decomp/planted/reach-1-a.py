from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

SP = 0x060FFFF0                 # r15 on entry; the first stack argument is here
SENT = 0xFFFFFFF0               # the address the interpreter's call returns to
FIX = 0x060C0100
# a code tail that pops the registers and pr of the function that branched to it: every word of the frame is the return address
FRAME_WORDS = [plant(SP + 4 * k, 4, [SENT], 1.0) for k in range(12)]

# 0606D410 ends a state by jumping through the word at +4 of the record 060E2150 points at; let it return to 0600660C, an rts
NEXT = [plant(0x060E2150, 4, [0x060C8000], 1.0), plant(0x060C8004, 4, [0x0600660C], 1.0)]
ROUND = [plant(0x060D7768, 4, [bomber(0), bomber(1)], 1.0), plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0)]

for _a in ("f0603CD76", "f06057D56", "f060A2312"):
    case(_a, [], False, FRAME_WORDS)
for _a in ("f0607799E", "f06086DD0"):
    case(_a, [], False, FRAME_WORDS + ROUND + NEXT)

# the 18 sound records at 060BC190, 88 bytes each
FREE = [plant(0x060BC190 + 88 * k + 80, 1, [0, 0, 1], 0.7) for k in range(18)] + [plant(0x060BC190 + 88 * k + 20, 4, [0], 1.0) for k in range(18)]
# 0609DA34 sets 060BB92C and waits for it to clear, unless 060BB924 holds 0
IDLE = [plant(0x060BB924, 4, [0], 1.0)]
# the text layout's list of boxes, headed by 060FBFFC and normally in VDP1 VRAM, which holds random bytes here
BOXES = [plant(0x060FBFFC, 4, [0], 1.0)]
CUR = [plant(0x060D7768, 4, [bomber(0)], 1.0), plant(bomber(0) + 6, 1, [0, 1, 2, 3, 4], 1.0)]
TASKP = [plant(0x060D7E60, 4, [0x060C2100], 1.0), plant(0x060D7E64, 4, [obj(3)], 1.0)]
ENV = CUR + TASKP + [plant(0x060D8C08, 4, [0x060C2100], 1.0), plant(0x060D7B3C, 4, [obj(3)], 1.0), plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0),
                     plant(0x060D8314, 4, [obj(3)], 1.0)] + [plant(bomber(i) + o, 2, [0, 1, 2, 3], 1.0) for i in range(4) for o in (22, 36, 62)]
# 06008ADC takes a word from the table that the table 060BD904 names points to; the animation setup then walks the records that word names
BANK0 = [plant(0x060BD904, 4, [0x060C4000], 1.0), plant(0x060C4000, 4, [0x060C4100], 1.0), plant(0x060C4004, 4, [0x060C4100], 1.0)]
BANK0 += [plant(0x060C4100 + 4 * k, 4, [0x060C4200], 1.0) for k in range(100)] + [plant(0x060C4200, 4, [0, 0, 0x00010000], 1.0)]
STK = [plant(SP, 4, [SENT], 1.0), plant(SP + 4, 4, [SENT], 1.0)]
# the animation records of the objects: pointers into the list that BANK0 leads to
ANIM = ([plant(obj(k) + o, 4, [0x060C2800], 1.0) for k in range(8) for o in (52, 56)] + BANK0
        + [plant(obj(k) + 50, 2, [0, 1, 2, 3], 1.0) for k in range(8)])

# 060086EA returns at once, and 06068FF0 returns 0: what a pointer the code jumps through can name
EMPTY, ZERO = 0x060086EA, 0x06068FF0

case("f06006EE6", [pick(0, 1, 0x12345678, -1), pick(0, 5, 0x80000000)], False,
     [plant(0x06006020, 4, [FIX], 1.0), plant(0x06006024, 4, [FIX + 0x40], 1.0)])
case("f0600B7CA", [pick(0, 1, 5, -1), pick(0, 2, 3), pick(0, 7), pick(0, 9)], True, [plant(0x0600026C, 4, [ZERO], 1.0)])
case("f06058DBE", [pick(0, 1, 5, -1), pick(0, 2, 3), pick(0, 7), pick(0, 9)], True, [plant(0x06002F3C, 4, [ZERO], 1.0)])
case("f060A4CE4", [pick(0, 1), pick(0, 2, 3), pick(0, 7), pick(0, 9)], True, [plant(0x06000320, 4, [ZERO], 1.0)])
case("f060144F4", [pick(0, 1, 0x0606D398, -1)], False, [plant(0x060C062C, 2, [0, 1, 2, 3, 0xFFFF], 0.9)])

# 0602B7CA clears the byte of a 12-byte frame that the byte at 060C064A + n names, for each n below the count at 060C1044 whose flag at 060C0640 + n has bit 0 or 1 set
case("f0602B8FC", [pick(-1, 0, 1, 2, 3, 4, 11, 12, 0x10000)], True,
     [plant(0x060C0640 + n, 1, [0, 1, 2, 3, 0], 0.9) for n in range(12)]
     + [plant(0x060C064A + n, 1, list(range(12)), 1.0) for n in range(12)]
     + [plant(0x060C1040, 4, [0, 4, 5, 1], 1.0), plant(0x060C1044, 1, [0, 1, 3, 9, 10, 12], 1.0)])
# the jump table of 0606B6BC, indexed by the halfword at +46 of the bomber CURRENT names
STATES = [plant(0x060B90E8 + 8 * i + j, 4, [v], 1.0)
          for i, (a, b) in enumerate([(0x0606B6E8, 0x0606B734), (0x0606B778, 0x0606B78E),
                                      (0x0606B758, 0x0606B758), (0x0606B78E, 0x0606B78E)])
          for j, v in ((0, a), (4, b))]
case("f0606EA3A", [span(0, 20), span(0, 20), span(0, 20), span(0, 20)], False,
     CUR + ENV + STATES + [plant(0x060C062C, 2, [0, 1, 2, 3], 1.0), plant(bomber(0) + 46, 2, [0, 1, 2, 3], 1.0),
                           plant(0x060C1AA8, 2, [3, 4], 1.0), plant(obj(3) + 44, 2, [9], 1.0)]
     + [plant(obj(k) + o, 4, [0x060C2800], 1.0) for k in (3, 4) for o in (52, 56)] + BANK0
     + [plant(obj(k) + 48, 2, [0, 1, 2], 1.0) for k in (3, 4)] + [plant(obj(k) + 50, 2, [0, 1, 2, 3], 1.0) for k in (3, 4)]
     + [plant(bomber(k) + 80, 2, [0, 1], 1.0) for k in (0, 1)])

# 44100 / (rate + 1) indexes a table of shift counts. SHIFTS stay outside 0 to 23, because the check
# does not keep the jump table that SAR (060946CC) reads for those counts
QS = (0, 1, 2, 3, 4, 5, 8)
RATES = [44099, 22049, 14699, 11024, 8819, 5511, 44100, 0xFFFFFFFF, 100000]
SHIFTS = [0xF1, 0xF5, 0x20, 0x21, 0x7F]
PL, OTHER = 0x060C3000, 0x060C3400


def slots(base_values=(0, 0x100, 0x400)):
    """The sound RAM slot bytes a player's slot index can name, all idle, and the table base that places them."""
    return ([plant(0x25A00404, 4, list(base_values), 1.0)]
            + [plant(0x25A00000 + b + 16 * i, 1, [0], 1.0) for b in base_values for i in range(8)])


def player(index_at, extra=()):
    """A player record behind the object at FIX, whose slot index is the word at index_at."""
    return ([plant(FIX, 4, [PL], 1.0), plant(PL + index_at, 4, [0, 1, 2, 3, 5], 1.0)] + slots() + list(extra))


case("f0609886C", [pick(FIX), pick(0, 0x00B40000, 0x005A0000, 0x00100000, -0x00200000, 0x00700000, 0x7FFFFFFF)], False,
     [plant(FIX + 4, 4, [FIX + 0x80], 1.0)])
case("f0609E282", [pick(1, 2, 4, 8, 16, 32, 128, 256, 0, 3, 64)], False)
case("f060A3F32", [pick(0, FIX), pick(-1, 0, 1, 5), pick(0, 3), pick(0, 4)], True,
     [plant(FIX, 4, [FIX + 0x400], 1.0), plant(FIX + 0x400 + 0x174, 4, [ZERO], 1.0), plant(0x060BB994, 4, [0, ZERO], 1.0)])
case("f060A4ABA", [pick(0, FIX), pick(-1, 0, 1, 5), pick(0, 3), pick(0, 4)], True,
     [plant(FIX, 4, [FIX + 0x400], 1.0), plant(FIX + 0x400 + 0x1C8, 4, [ZERO], 1.0), plant(0x060FC228, 4, [0, ZERO], 1.0)])
case("f060A5E44", [pick(FIX - 12), pick(0, 1, 2), pick(0, 3), pick(0, 4)], True,
     [plant(FIX + 28, 4, [0, 3, 4, 5, 1, 2], 1.0)] + [plant(0x060B1220 + 16 * k, 4, [ZERO], 1.0) for k in range(8)])

case("f060954B8", [pick(0x25890016, 0x2589001A, 0x2589001E, 0x25890012, 0x060C0200)], True)
# the player record: the sound slot index at +24 (for 060AFC74), the state record at +48 and the object at +320
case("f060AFC74", [pick(FIX), pick(0, 1, 2, 5), pick(0, FIX), pick(0, 7)], False,
     player(24) + [plant(PL + 52 + 108, 4, [0, 5, 0x20000], 0.15), plant(PL + 52 + 124, 4, RATES, 1.0),
                   plant(PL + 0x140, 4, [OTHER], 1.0), plant(OTHER + 37, 1, [1, 0, 3], 1.0), plant(OTHER + 38, 1, [16, 0, 3], 1.0),
                   ]
     + [plant(0x060BB99C + q, 1, SHIFTS, 1.0) for q in QS])
case("f060ACB74", [pick(FIX)], False, player(24))
case("f060AD46C", [pick(FIX)], True, player(24))

# 060B047E and 060B070E index the slot by the word at +20 of the player, and 060B047E reads the rate at +92
case("f060B047E", [pick(FIX), pick(-1, 0, 5, 0x1F, 0x23), pick(0, 3, 31, 40)], False,
     player(20) + [plant(PL + 92, 4, RATES, 1.0), plant(PL + 24, 4, [0, 7, 0x1F, 0x23], 0.9),
                   plant(PL + 28, 4, [0, 3, 7, 9], 0.9), plant(PL + 4 + 20, 4, [0, 7, 9], 0.9)]
     + [plant(0x060B1380 + q, 1, SHIFTS, 1.0) for q in QS])
case("f060B070E", [pick(FIX)], False, player(20))

case("f060ADFAA", [pick(FIX)], False,
     [plant(FIX, 4, [PL], 1.0), plant(PL + 36, 4, [0, 5, 0x7FFFFFFF], 0.9), plant(PL + 40, 4, [0, 5, 0x7FFFFFFF], 0.9),
      plant(PL + 48 + 60, 4, [0, 5, 100], 0.9), plant(PL + 48 + 108, 4, [0, 5, 100], 0.9), plant(0x060FC184, 4, [0, 5]), plant(0x06000324, 4, [0, 1, 5], 1.0)]
     + slots())

# 060AB6BE: in state 1 (the word at +56) command 2 starts the sound, and in state 4 commands 0 and 1 act
case("f060AB6BE", [pick(FIX), pick(0, 1, 2, 3, -1), pick(0, 7), pick(0, 9)], False,
     player(24) + [plant(PL + 52 + 4, 4, [1, 1, 1, 4, 4, 0, 7], 1.0), plant(PL + 52 + 108, 4, [1], 1.0),
                   plant(PL + 52 + 124, 4, RATES, 1.0), plant(PL + 0x140, 4, [OTHER], 1.0), plant(0x06000324, 4, [0, 1, 5], 1.0),
                   plant(OTHER + 37, 1, [1, 0, 3], 1.0), plant(OTHER + 38, 1, [16, 0, 3], 1.0)]
     + [plant(0x060BB99C + q, 1, SHIFTS, 1.0) for q in QS])

# 060A5468 reads a byte at 060FC068; 060A5180 clears the range at 060FC02C
case("f060A3658", [], True,
     [plant(0x060FC034, 1, [1, 1, 0, 2], 1.0), plant(0x060FC068, 1, [0, 1, 2], 1.0),
      plant(0x060FC02C, 4, [0x060C6000], 1.0), plant(0x060FC030, 4, [0, 0x40], 1.0)])
