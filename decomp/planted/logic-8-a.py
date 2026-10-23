from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

REC = 0x060C2100
STUBS = [0x06006368, 0x0600620C, 0x06006218, 0x0600A2D8]
# functions that return 0 in r0 whatever r0 held, for a tail call whose result the check compares
ZERO = [0x0602F666, 0x06068FF0, 0x0606B1EC, 0x0608304C, 0x06096A7C]
CURB = [plant(0x060D7768, 4, [bomber(0), bomber(1), bomber(2)], 1.0)]
MOVER = [plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0)]
TASKP = [plant(0x060D7E60, 4, [REC], 1.0)]

# 060C1038 holds the code address 0602F640 jumps to
case("f0602F640", [span(0, 5), span(0, 5), span(0, 5), span(0, 5)], False, [plant(0x060C1038, 4, STUBS, 1.0)])
case("f0601C2A8", [], True, MOVER)
# 06011C16 and 06011F44 follow the word at 4 of the task, and the byte at 29 is a countdown
case("f06011C16", [pick(REC)], False,
     CURB + [plant(REC + 4, 4, STUBS, 1.0), plant(REC + 29, 1, [0, 1, 2], 1.0), plant(REC + 18, 2, [0, 5], 1.0),
             plant(bomber(0) + 20, 2, [0, 5], 1.0), plant(bomber(1) + 20, 2, [0, 5], 1.0), plant(bomber(2) + 20, 2, [0, 5], 1.0)])
case("f06011F44", [pick(REC)], False, [plant(REC + 4, 4, STUBS, 1.0)])
# 060352C4 steps the record at 060C164C: count at 2, an object number at 4, a byte pair at 1, and rates at 6 to 8
SPIN = 0x060C2200
case("f060352C4", [], True,
     [plant(0x060C164C, 4, [SPIN], 1.0), plant(SPIN + 1, 1, [0, 0x11, 0x32, 0xA5, 0xFF], 0.8), plant(SPIN + 2, 2, [0, 3, 10, 11, 0xFFF0], 1.0),
      plant(SPIN + 4, 2, [3, 4, 5], 1.0), plant(SPIN + 6, 1, [0, 3, 7], 0.8), plant(SPIN + 7, 1, [0, 3, 7], 0.8),
      plant(SPIN + 8, 2, [0, 1, 0x40, 0x100], 0.8)])
# 0603C83A moves the task's two offsets (10 and 12) within the step; the halfword at 14 picks the pattern
case("f0603C83A", [], True,
     TASKP + [plant(REC + 20, 2, [0, 0, 4, 9], 1.0), plant(REC + 18, 2, [0, 3, 8], 1.0), plant(REC + 14, 2, list(range(0, 16)) + [0x7FFF, 0xFFFF], 1.0),
              plant(REC + 10, 2, [0, 1, 4, 0xFFFC, 0xFFF0], 0.9), plant(REC + 12, 2, [0, 1, 4, 0xFFFC, 0xFFF0], 0.9)])

# 0606B6BC jumps to the word at 060B90EC plus eight times the halfword at 46 of the current record
JUMPS = [plant(0x060B90EC + 8 * k, 4, STUBS, 1.0) for k in range(3)] + [plant(bomber(i) + 46, 2, [0, 1, 2], 1.0) for i in range(3)]
case("f0606B6BC", [span(0, 5), span(0, 5), span(0, 5), span(0, 5)], False, CURB + JUMPS)
case("f0606D97A", [], False, CURB + JUMPS)
# 0606D23C picks a record of the table at 060E2154 by the halfword at 060C062C and jumps to its word at 12
WORD = [plant(0x060C062C, 2, [0, 1, 2, 3], 1.0)]
case("f0606D23C", [], False, CURB + MOVER + WORD + [plant(0x060E2160 + 20 * k, 4, STUBS, 1.0) for k in range(4)])
case("f0607F3BE", [], False, CURB + MOVER + WORD)
case("f0606FC60", [], True, CURB + MOVER + WORD + [plant(bomber(i) + 62, 2, [0, 0, 1], 1.0) for i in range(3)])
case("f060738A2", [], False, CURB + MOVER + [plant(bomber(i) + 68, 2, [0, 1, 0x80, 0x100, 0x7FFF, 0xFFFF], 1.0) for i in range(3)]
     + [plant(obj(k) + 70, 2, [0, 0x40, 0x100, 0x200, 0xFFFF], 1.0) for k in (3, 4)])
case("f06085184", [], True, CURB + MOVER + [plant(bomber(i) + 54, 2, [0, 5, 12, 20, 0xFFF0], 1.0) for i in range(3)])
case("f06065AF2", [], False, TASKP)

# 060512C0: ten flag bytes at 060C0FC4, and ten bytes at 060C0640 that shifted right by two pick one of five groups
case("f060512C0", [ptr(0x060C0100, 0x40, 2)], False,
     [plant(0x060C0FC4 + i, 1, [0, 1, 1], 1.0) for i in range(10)] + [plant(0x060C0640 + i, 1, [0, 4, 8, 12, 16, 19], 1.0) for i in range(10)]
     + [plant(0x060C1048, 4, [0x400, 0, 0x800, 0xC00, 0x400], 1.0), plant(0x060C063C, 1, [0, 1, 2, 3, 4, 5, 6, 7, 9, 32], 1.0)])

# the dispatchers read the object at the first argument and jump through tables of code addresses
VT = 0x060C2300
case("f060A47E2", [pick(0, REC)], False, [plant(REC, 4, [VT], 1.0), plant(VT + 0x1BC, 4, STUBS, 1.0)])
case("f060A5E62", [pick(REC), span(0, 5), span(0, 5), span(0, 5)], True,
     [plant(REC + 40, 4, [0, 1, 2], 1.0)] + [plant(0x060B1220 + 16 * k, 4, ZERO, 1.0) for k in range(3)])
case("f060A5E9A", [span(0, 5), pick(REC), span(0, 5), span(0, 5)], True,
     [plant(REC + 28, 4, [0, 1, 2], 1.0)] + [plant(0x060B1228 + 16 * k, 4, ZERO, 1.0) for k in range(3)])
WORDP = 0x060C2400
case("f060A6554", [pick(REC), span(0, 5), span(0, 5), span(0, 5)], True,
     [plant(REC + 56, 4, [0, 0, 0, 4, 1, 3, 2], 1.0), plant(REC + 16, 4, [WORDP], 1.0),
      plant(WORDP, 4, [0, 0x00200000, 0x002FFFFF, 0x00300000, 0x02000000, 0x058FFFFF, 0x05900000, 0xF0200000, 0x0FFFFFFF], 1.0)]
     + [plant(0x060B1250 + 12 * k, 4, ZERO, 1.0) for k in range(4)])

# 0609A4AC packs the descriptor at DESC (bytes 0 to 8, a halfword at 10, then pairs of words from 12) into the table at 060FA9A0
DESC = 0x060C2500
case("f0609A4AC", [pick(1, 2, 2, 2, 4, 8, 16, 32, 1, 2, 0, 3), pick(DESC)], False,
     [plant(DESC + k, 1, [0, 1, 2, 3, 0xFF, 0x55, 0, 1], 1.0) for k in range(9)] + [plant(DESC + 10, 2, [0, 0x8000, 0x4000, 0xFFFF, 0x1234], 1.0)]
     + [plant(DESC + 12 + 4 * k, 4, [0x26000000, 0x25F00000 + 0x1000 * k, 0x26020000, 0x25DFFFFF, 0], 0.9) for k in range(18)]
     + [plant(0x060FB870, 1, [0, 1, 1, 1], 1.0), plant(0x060FB871, 1, [0, 1, 2, 2], 1.0)])

# 0602E5E4 compares two words per index, and 0602E656 turns each into a count that is one per 20000 above 10000
SCORES = [0, 5000, 10000, 29999, 30000, 50000, 90000, 200000]
case("f0602E5E4", [span(0, 3)], False,
     [plant(0x060C0690 + 4 * k, 4, SCORES, 1.0) for k in range(4)] + [plant(0x060C0FDC + 4 * k, 4, SCORES, 1.0) for k in range(4)]
     + [plant(0x060C063E, 1, [0, 5, 9, 12], 1.0)])
