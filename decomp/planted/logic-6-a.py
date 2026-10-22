from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

SP = 0x060FFFF0                 # r15 on entry; the first stack argument is here
FIX = 0x060C0100                # a pointer argument the plants can name
# 06006AA0 takes one of the 18 sound records at 060BC190: a free one has 0 at +80, and a busy one whose word at +20 equals the buffer traps
FREE = [plant(0x060BC190 + 88 * k + 80, 1, [0, 0, 1], 0.7) for k in range(18)] + [plant(0x060BC190 + 88 * k + 20, 4, [0], 1.0) for k in range(18)]
# 0609DA34 hands a word to the display and waits for it to be taken back, unless 060BB924 holds 0
IDLE = [plant(0x060BB924, 4, [0], 1.0)]
# the text layout's list of boxes, headed by 060FBFFC and normally in VDP1 VRAM, which holds random bytes here
BOXES = [plant(0x060FBFFC, 4, [0], 1.0)]
# 06008A6A reads its source through the four pointers at 060BD8D4, which point into work RAM-L
PALTAB = [plant(0x060BD8D4 + 4 * k, 4, [0x00200000, 0x00254000], 1.0) for k in range(4)]
# 06008A96 copies twelve words of that source to the bank table at 060BD8E4
PALTAB += [plant(base + 4 * k, 4, [0x060C4000], 1.0) for base in (0x00200000, 0x00254000) for k in range(12)]
# 06008ADC takes a word from the table that the table that 060BD904 names points to, and 06068BDC treats it as a record
BANK = [plant(0x060BD904, 4, [0x060C4000], 1.0), plant(0x060C4000, 4, [0x060C4100], 1.0), plant(0x060C4004, 4, [0x060C4100], 1.0)] + [plant(0x060C4100 + 4 * k, 4, [0x060C4200], 1.0) for k in range(100)]
# 06068BDC walks the records that word names until a halfword of -1
BANK += [plant(0x060C4200, 4, [0xFFFF0000, 0x00000000], 1.0), plant(0x060C4204, 4, [0xFFFF0000], 1.0)]


def data(address, words):
    """The halfwords of a table in the image, which the check randomises with the variables around it."""
    return [plant(address + 2 * i, 2, [w], 1.0) for i, w in enumerate(words)]


# the lists of glyph numbers the text routines copy to the stack, each ended by 0xFFFF
STRINGS = (data(0x060B1FC8, [0x16, 0xFFFF]) + data(0x060B1FDE, [0xA, 8, 0xE, 0xC, 0xB, 9, 0xF, 0xD, 0xFFFF]) + data(0x060B1FF4, [0x1E, 0xFFFF])
           + data(0x060B1FF8, [0x1E, 0xFFFF]) + data(0x060B2002, [0x1A, 0x1B, 0xFFFF]) + data(0x060B20CE, [0, 0x27, 0xFFFF])
           + data(0x060B20DA, [0x2E, 0x28, 0xFFFF]) + data(0x060B20E8, [0x2A, 0x2B, 0x29, 0xFFFF]) + data(0x060B20F8, [0x2C, 0x2D, 0x29, 0xFFFF])
           + data(0x060B26EE, [8, 9, 0xA, 0xB, 0xFFFF]) + data(0x060B5E4A, [70, 71, 72, 73, 82, 83, 84, 85, 74, 75, 76, 77, 78, 79, 80, 81, 65535]))
TEXT = BOXES + PALTAB + BANK + STRINGS
BLEND = [plant(SP, 4, [0, 0x8000, 0x8003, 0x1F, 0xFFFF]), plant(SP + 4, 4, [0, 1])]
case("f060088E2", [], True, FREE + IDLE + [plant(0x060BD4AC, 2, [0, 1, 5])])
case("f06009092", [pick(0, 5, 16, 100), pick(0, 5, 16, 20, 130), pick(0, 0x8000, 0x8010, 0x10, 0x7FFF), pick(0, 0x8000, 0x8010, 0x7FFF, 0xFF)], False, BLEND)
case("f060092AA", [span(-12, 12)], False, [plant(0x060BF4AA + 10 * k, 2, [0, 3, 16, 7], 1.0) for k in range(-12, 13)]
     + [plant(0x060BF4AA + 10 * k + 2, 2, [0, 3, 16, 20], 1.0) for k in range(-12, 13)] + BLEND[:1])
# a plain chain of links at 060D776C, each one's previous being the entry before it, which 06014820 walks
CHAIN = [plant(0x060D776C + 8 * _k, 1, [0, 1, 2, 3, 255], 0.8) for _k in range(7)] \
    + [plant(0x060D776C + 8 * _k + 1, 1, [max(_k - 1, 0)], 1.0) for _k in range(7)] \
    + [plant(0x060D776C + 8 * _k + 2, 1, [_k + 1 if _k < 6 else 0], 1.0) for _k in range(7)] \
    + [plant(0x060C062C, 2, [0, 1, 2, 3], 0.95), plant(0x060D7768, 4, [0x060C2100])]
BOMBERS = [plant(bomber(i) + 22, 2, [0, 5, 0xFFFF], 0.6) for i in range(5)] + [plant(0x060C0632, 2, [0, 3])]
case("f060147C4", [span(0, 3), span(0, 4)], False, CHAIN + BOMBERS)
CUR = [plant(0x060D7768, 4, [bomber(0)], 1.0), plant(bomber(0) + 6, 1, [0, 1, 2, 3, 4], 1.0)]
TASKP = [plant(0x060D7E60, 4, [0x060C2100], 1.0), plant(0x060D7E64, 4, [obj(3)], 1.0)]
# the pointers the kernel keeps at the record being run, and the one 0601AD82 puts back
ENV = CUR + TASKP + [plant(0x060D8C08, 4, [0x060C2100], 1.0), plant(0x060D7B3C, 4, [obj(3)], 1.0), plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0),
                     plant(0x060D8314, 4, [obj(3)], 1.0)] + [plant(bomber(i) + o, 2, [0, 1, 2, 3], 1.0) for i in range(4) for o in (22, 36, 62)]
# a stub that pops pr (at the stack top, or one word up) and returns: the check's return address in both words
SENT = 0xFFFFFFF0
STK = [plant(SP, 4, [SENT], 1.0), plant(SP + 4, 4, [SENT], 1.0)]
for _a in ("0601917C", "06019370", "0601B6CA", "0601BEC8", "0601BED4", "0602E40E", "0602E420", "0602E43C",
           "0602EA9E", "0602EAB0", "0602EACC", "06033148", "0603D862", "0603D868", "0603D86E", "0605BEA2", "0605BEA8", "0605BEAC", "0605BEB0", "06060E78", "06060E80"):
    case("f" + _a, [], True, STK + FREE + IDLE + BOXES + ENV)
case("f0602E408", [pick(0, 1, 5)], True, STK + FREE + IDLE + BOXES + ENV)
case("f0602EA98", [pick(0, 1, 5)], True, STK + FREE + IDLE + BOXES + ENV)
for _a in ("0606DCA8", "0606DD00", "0606DE16", "0606DE9A", "0606DED0", "0606E098", "0606E19E", "0606E228"):
    case("f" + _a, [], False, STK)
for _a in ("0602E53E", "0602E5BE", "0602E5C8", "0602E5D2"):
    case("f" + _a, [], False, STK)
for _a in ("060129E0", "06012CD8", "06013788", "06013006"):
    case("f" + _a, [pick(FIX)], True, CUR)
# 06011F98 and 0601227E test the bomber's flags at 64, its range 62 against 40, and 0601227E also the word at 46
CURF = CUR + [plant(bomber(0) + 64, 2, [0x100, 0x300, 0, 0x200], 0.9), plant(bomber(0) + 62, 2, [100, 200, 0], 0.9),
              plant(bomber(0) + 40, 2, [0, 5], 1.0), plant(bomber(0) + 46, 2, [0, 0, 1], 1.0)]
# 060119E8 and 060120B4 then read the bomber's cell at 20, its flags at 42 and 46, and the cell's flags and height
CURF += [plant(bomber(0) + 20, 2, [0, 1, 2, 3], 1.0), plant(bomber(0) + 42, 2, [0, 0, 32], 1.0), plant(bomber(0) + 52, 2, [0, 1, 3, 4], 1.0),
         plant(0x060C04CA, 2, [0, 1, 0, 500], 1.0), plant(0x060C04DA, 2, [5, 0], 1.0), plant(0x060C04CC, 2, [0, 1], 1.0)] \
    + [plant(0x060EC8B0 + 2 * c, 2, [0, 0, 0x40, 7, 0x42F0], 0.9) for c in range(0, 40)] + [plant(0x060EE8B0 + 2 * c, 2, [0, 0, 0x100, 0x1000, 0x300], 0.9) for c in range(0, 40)]
for _a in ("06012A50", "06012AC4", "06012D94"):
    case("f" + _a, [pick(FIX)], True, CURF)
case("f06017C16", [], True, CUR + [plant(bomber(0) + 108, 4, [0x060175F2, 0, 5], 0.5), plant(bomber(0) + 58, 2, [0, 1, 0x100])])
case("f0602C622", [pick(-2, -1, 0, 1, 2, 3, 4, 5, 0x10002)], True,
     [plant(0x060C0640 + i, 1, [0] * 8 + [1, 4, 5, 8, 9, 12, 13, 16, 17, 3, 19, 2], 1.0) for i in range(10)] + [plant(0x060C1044, 1, [0, 3, 10, 0x80, 0xFF, 5], 1.0)])
case("f0602C644", [pick(-2, -1, 0, 1, 2, 3, 4, 5, 6, 0x10002)], True,
     [plant(0x060C0640 + i, 1, [0] * 8 + [1, 4, 5, 8, 9, 12, 13, 16, 17, 3, 19, 2], 1.0) for i in range(10)] + [plant(0x060C1044, 1, [0, 3, 10, 0x80, 0xFF, 5], 1.0)])
case("f0603E4D8", [pick(0, 1, 2, 3, 0x10002, -0x10000)], True)
# 0600C4E0 loads the tile table at 060D7E98 from 060D7E9C and the buffer at 060D7EA0 from one of 060D7EA4 to 060D7EB0; 0600C796 copies a tile between them
case("f0602370A", [span(0, 300), span(0, 63), span(0, 63), pick(0, 1, 2, 3, 4)], False,
     [plant(0x060D7E9C, 4, [0x06000000], 1.0)] + [plant(0x060D7EA4 + 4 * k, 4, [0x060C6000], 1.0) for k in range(4)])
# 0601ADA6 points CURRENT and 060D7B3C at the record 060D8310 names, which 0601AD82 puts back from 060D8310 and 060D8314
case("f0601D812", [], True, CUR + [plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0), plant(0x060D8314, 4, [obj(3)], 1.0), plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0)]
     + [plant(bomber(i) + 36, 2, [0, 1, 2, 3], 1.0) for i in range(4)] + [plant(bomber(i) + 62, 2, [0, 1, 2, 3], 1.0) for i in range(4)]
     + [plant(bomber(i) + 52, 2, [0, 1, 2, 5, 9], 1.0) for i in range(4)] + [plant(bomber(i) + 22, 2, [0, 1, 2, 3], 1.0) for i in range(4)])
ACT = 0x060C2100            # a record for the pointer at 060D8C08
ACTOR = [plant(0x060D8C08, 4, [ACT], 1.0)]
case("f0601F782", [], False, ACTOR + [plant(ACT, 2, [0, 3, 4, 5], 1.0), plant(ACT + 2, 2, [0, 3, 4], 1.0), plant(ACT + 4, 2, [0, 1, 2, 3], 1.0)])
case("f0601C1C6", [], True, CUR + [plant(0x060D8318, 4, [0x060D831C], 1.0), plant(bomber(0) + 22, 2, [0, 1, 5], 1.0)]
     + [plant(0x060D831C + 2 * k, 2, [0, 1, 5, 7], 0.7) for k in range(12)])
case("f06021822", [], False, [plant(0x060DFB96 + 8 * k + o, 2, [0, 3, 100, 0], 1.0) for k in range(76) for o in (0, 2)])
case("f0602ECF6", [pick(FIX)], True, [plant(0x060C1004, 1, [0, 1, 2])])
case("f0603A0A8", [], False, [plant(0x060C029C, 1, [17, 0, 3], 0.7)])
# 06022FFC wants the word at 060D7B46 set, the first slot busy, and the bomber's position within 8 of the one 0600C90C makes from the slot's object
case("f0605F4B4", [], True, CUR + [plant(0x060C029C, 1, [2], 0.9), plant(0x060D7B46, 2, [0, 1, 1], 1.0), plant(0x060D7B50, 2, [0, 3, 3], 1.0),
                                  plant(obj(3) + 16, 2, [100], 1.0), plant(obj(3) + 18, 2, [124, 124, 300], 1.0), plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0),
                                  plant(bomber(0) + 24, 2, [100], 1.0), plant(bomber(0) + 28, 2, [100], 1.0)])
case("f0602EDC8", [pick(FIX)], True)
# the decoder's stream: its cursors and its ring, which the plants make valid
STREAM_AT = 0x060C2400
STREAM = [plant(STREAM_AT, 4, [0x060C3000], 1.0), plant(STREAM_AT + 4, 4, [0x060C3200], 1.0), plant(STREAM_AT + 8, 4, [0x060C3400], 1.0),
          plant(STREAM_AT + 16, 4, [0xFF, 0x3F, 0xF, 0x1FF], 1.0), plant(STREAM_AT + 24, 4, [0, 1, 2, 7, 100, 0x3FF, 0x1234, 0xFFFFFFFF], 0.9)]
for _a in ("06034022", "06034072", "0603409A", "060340AE", "0603421A", "06034274", "06034286"):
    case("f" + _a, [pick(STREAM_AT)], True, STREAM)
FALLP = 0x060C2600           # the record 060C1658 points at
case("f0605B240", [], True, [plant(0x060C1658, 4, [FALLP], 1.0), plant(FALLP + 6, 2, [0, 1, 2, 5], 0.9)])
case("f0606CABE", [pick(0, 1, 0x7FFF, 0x8000, 0xFFFF, 0x10000, -1, 0x12345678)], False, CUR + [plant(bomber(0) + 10, 2, [0, 5, 0xFFFF, 0x8000], 0.9), plant(bomber(0) + 12, 2, [0, 5, 0xFFFF], 0.9)])
case("f0606DAB2", [], True, CUR)
for _a, _r in (("0603DE58", True), ("0603E33C", False), ("0603E366", True), ("0603E436", True), ("0603E5A8", True), ("06042F96", True), ("06043194", True),
               ("0604327A", True), ("06043454", True), ("06061ABC", True)):
    case("f" + _a, [], _r, ENV + TEXT + FREE + IDLE)
