from cases import case, pick, plant, ptr, span

SP = 0x060FFFF0        # r15 on entry; the arguments a caller passed on the stack start here
BUF = 0x060C5000
CMDBUF = BUF + 0x3000
OUT = BUF + 0xB000
DEVREC = BUF + 0x8000
RETURN = 0xFFFFFFF0    # the interpreter's return address


def stack(k, values):
    """The k-th word above the stack pointer the function is entered with."""
    return plant(SP + 4 * k, 4, values, 1.0)


HIRQ, CR1, CR2 = 0x25890008, 0x25890018, 0x2589001C
SHADOW = 0x060FA8B8
# The block's answers are plants: nothing changes these registers during a trial.
CD = [plant(HIRQ, 2, [0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0243, 0x00C3, 0x0083, 0x0003, 0x0241, 0x0001], 0.99),
      plant(SHADOW, 2, [0, 0xFFFF, 1, 0x0800], 0.9),
      plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00, 0x0600, 0x0700, 0x0F00, 0xFF00, 0x8100], 1.0)]
CD_FULL = [plant(HIRQ, 2, [0xFFFF, 0x00C3, 0x0243, 0x0083, 0x0003], 1.0),
           plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00, 0x0600, 0x0700, 0x0F00], 1.0)]
# HIRQ with the bits the waits want, so they end without a block to raise them.
HIRQ_OK = plant(HIRQ, 2, [0x0043, 0x00C3, 0x0243, 0x0143, 0x0047, 0x0053, 0x00C7], 1.0)
CR_OK = plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00], 1.0)
CR_FAIL = plant(CR1, 2, [0xFF00, 0x8100, 0x8000], 1.0)
CR2_OK = plant(CR2, 2, [0, 1, 2, 3, 5], 1.0)
# A status word with bit 5 set, which 06095474 wants of the block's reply.
CR1_REPLY = plant(CR1, 2, [0x2000 + 0x100 * k for k in range(16)] + [0x0900, 0x0000], 1.0)
DEVP = [plant(0x060FC084, 4, [DEVREC], 1.0)]

# SF reads back 0 once written, but a trial's first read is whatever was planted.
case("f06054FB8", [], False, [plant(0x20100063, 1, [0, 0, 0, 2], 1.0), plant(0x060FA900, 1, [0, 1, 1], 0.8)])
case("f06095868", [ptr(OUT, 0x40, 4)], False, [HIRQ_OK, CR_OK, CR2_OK])
case("f060955E0", [span(0, 255), ptr(CMDBUF, 0x40, 4)], False, CD)
case("f06095716", [ptr(CMDBUF, 0x40, 4)], True, CD)
case("f0609580A", [ptr(CMDBUF, 0x40, 4)], False, CD)
case("f060958EA", [], True, CD)
case("f06095904", [span(0, 0xFFFF)], False, CD)
case("f0609593A", [pick(-2, -1, 0, 0, 0, 1, 2, 3, 4, 5), ptr(CMDBUF, 0x40, 2)], True,
     CD_FULL + [plant(CR2, 2, [0, 1, 2, 3, 4, 5], 0.9), plant(CR1, 2, [0xFF00, 0x8100], 0.2)])
case("f06095A84", [pick(1, 2, 3, 0x82, 0xFFFF), ptr(CMDBUF, 0x10, 4)], True,
     [plant(HIRQ, 2, [0xFFFF, 0x0003, 0x00C3, 0x0083], 1.0)])
case("f06095ACE", [ptr(CMDBUF, 0x20, 2)], False, CD)

XS, VA, VB, VC, VD = BUF + 0xC000, BUF + 0xC100, BUF + 0xC200, BUF + 0xC300, BUF + 0xC400
UNITS = [BUF + 0xC500 + 4 * k for k in range(3)]
SPLINE = ([plant(XS + 4 * k, 4, [10 * k, 10 * k + 5, 25 * k], 0.9) for k in range(10)]
          + [plant(a + 4 * k, 4, [0, 1, 100, 0x10000, -300, 0x7FFF], 1.0) for a in (VA, VB, VC, VD) for k in range(10)]
          + [plant(u, 4, [0, 1, 0x10000, -0x10000, 0x20000], 1.0) for u in UNITS])
case("f060979DC", [span(-20, 300), pick(BUF + 0xC600), pick(BUF + 0xC604), pick(XS)], False,
     SPLINE + [stack(0, [VA]), stack(1, [VB]), stack(2, [VC]), stack(3, [VD]), stack(4, [2, 3, 5, 8, 10]),
               stack(5, [UNITS[0]]), stack(6, [UNITS[1]])])
case("f06097AB0", [span(-20, 300), pick(BUF + 0xC600), pick(BUF + 0xC604), pick(BUF + 0xC608)], True,
     SPLINE + [stack(0, [XS])] + [stack(k, [VA, VB, VC, VD]) for k in range(1, 7)] + [stack(7, [2, 3, 5, 8, 10])]
     + [stack(8 + k, [UNITS[k]]) for k in range(3)])

# The epilogues these two jump to pop pr from the stack; the sentinel ends the call.
case("f060A115E", [], False, [plant(SP + 12, 4, [RETURN], 1.0)])
case("f060A2378", [], False, [plant(SP + 16, 4, [RETURN], 1.0)])

# 4CEC's second step waits for a bit that stays clear, so only the failing first step ends.
case("f060A4CEC", [], True, [HIRQ_OK, CR_FAIL, CR2_OK])
case("f060A4D60", [pick(0x1, 0x2, 0x40, 0x41, 0x3)], True, [HIRQ_OK])
case("f060A4DD6", [], False, CD)
case("f060A4E78", [span(0, 255), span(0, 0xFFFFFF)], True, CD)
case("f060A4EF0", [span(0, 1000), ptr(OUT, 0x40, 2)], True,
     [HIRQ_OK, CR_OK, CR2_OK, plant(HIRQ, 2, [0x0002, 0x0000], 0.2)])
case("f060A4F6A", [], True, CD)
case("f060A4FAC", [pick(0, 0x40, 0x200, 0x80), ptr(CMDBUF + 0x300, 0x10, 1)], True, CD)
case("f060A6790", [span(0, 9)], True,
     [plant(HIRQ, 2, [0x07FF, 0x07C3, 0x07C7, 0x05FF], 1.0), CR_OK, CR2_OK, plant(0x060FA8BC, 4, [BUF + 0x8800], 1.0)])
case("f060A6CE6", [pick(0, BUF + 0x7F00), pick(0, BUF + 0x7F04)], True,
     CD + [CR1_REPLY, plant(0x060FC080, 4, [0, 0, 0, -13, -14, -16, 5]), plant(0x060FC088, 4, [0, 1, 1]), plant(0x060FC084, 4, [DEVREC], 1.0)])
case("f060A788A", [], True, CD)
case("f060A7C3E", [ptr(CMDBUF + 0x100, 0x10, 1)], True,
     CD_FULL + [CR1_REPLY, plant(0x060FC088, 4, [0, 1, 1]), plant(CMDBUF + 0x100, 1, [0, 6, 7, 10, 3, 0x1A, 0x19]),
                plant(0x060FC084, 4, [DEVREC], 1.0)])
case("f060A802C", [], True, DEVP + CD)
case("f060A89F4", [pick(BUF + 0x7D00)], True,
     DEVP + [plant(DEVREC + 0x1DC, 4, [0, 1, 2, 5, 24], 1.0), plant(DEVREC + 0x1E0, 4, [0, 1])]
     + sum([[plant(DEVREC + 0x1E4 + 12 * k + o, 4, [-2, -2, 0, 1, 7], 1.0) for o in (0, 4, 8)] for k in range(6)], [])
     + CD_FULL + [plant(CR1, 2, [0xFF00, 0x8100], 0.6), plant(HIRQ, 2, [0xFFFF, 0x00C3, 0x0243], 0.6)])
case("f060A8C58", [], True, CD)
case("f060A8C7C", [], False, [plant(HIRQ, 2, [0x0400, 0x0401, 0, 0x0001], 0.95)])
case("f060AA9FC", [], True, [HIRQ_OK, CR_OK, CR2_OK])
case("f060AAD72", [], True, [HIRQ_OK, CR_OK, CR2_OK])

# 060AFDF0 polls a byte of sound RAM, and the delay it calls loops until it reads 0.
HND, RING, PAR = BUF + 0xD000, BUF + 0xD100, BUF + 0xD400
RING_RAM = BUF + 0xD800
ST_AT = RING + 52
case("f060AB4C6", [pick(HND)], False,
     [plant(HND, 4, [RING], 1.0), plant(RING + 0x140, 4, [PAR], 1.0), plant(PAR + 37, 1, [0, 1, 2], 1.0),
      plant(PAR + 38, 1, [0, 8, 4], 1.0), plant(ST_AT + 0xA0, 4, [0], 1.0), plant(ST_AT + 108, 4, [0, 1, 1, 5], 1.0),
      plant(ST_AT + 112, 4, [0x40, 0x100, 0x200], 1.0), plant(ST_AT + 116, 4, [RING_RAM, RING_RAM + 0x100], 1.0),
      plant(ST_AT + 120, 4, [0, 4, 8, 16, 0x40, 0x100, 0x200], 1.0), plant(ST_AT + 136, 4, [0x20, 0x40, 0x100], 1.0),
      plant(ST_AT + 144, 4, [0, 4, 0x10], 1.0), plant(ST_AT + 104, 4, [0x44, 0x100, 0x1002, 0x7FC], 1.0),
      plant(ST_AT + 92, 4, [RING_RAM + 0x300], 1.0), plant(RING + 32, 4, [RING_RAM, RING_RAM + 0x80], 1.0),
      plant(RING + 24, 4, [0, 1, 2], 1.0), plant(0x25A00404, 4, [0], 1.0)]
     + [plant(0x25A00000 + 16 * k, 1, [0], 1.0) for k in range(3)])

case("f060AE3FA", [ptr(OUT, 0x40, 4)], True, CD)
case("f060AE478", [span(0, 255), span(0, 0xFFFFFF), span(0, 0xFFFFFF)], True, CD)
case("f060AE4F2", [span(0, 255), ptr(CMDBUF + 0x400, 0x10, 1)], True, CD)
case("f060AE586", [span(0, 255), span(0, 255)], True, CD)
case("f060AE5F4", [span(0, 255), span(0, 255), span(0, 255), span(0, 255)], True, CD)
case("f060AE676", [span(0, 255), span(0, 255)], True, CD)
case("f060AE6FA", [span(0, 255), pick(BUF + 0x7810)], True, CD)
case("f060AE76C", [pick(BUF + 0x7814)], True, CD)
case("f060AE7D0", [span(0, 255), span(0, 0xFFFF), ptr(OUT, 0x40, 1)], True, CD)
case("f060AE856", [ptr(OUT, 0x10, 4), ptr(OUT + 0x20, 0x10, 4), ptr(OUT + 0x40, 0x10, 4)], True, CD)
case("f060AE8DA", [span(0, 255), span(0, 0xFFFF), span(0, 0xFFFF)], True, CD)
case("f060AE936", [span(0, 255), span(0, 0xFFFF), span(0, 0xFFFF)], True, CD)
case("f060AE98E", [span(0, 255), span(0, 0xFFFF), span(0, 0xFFFF), span(0, 255)], True, CD)
case("f060AE9F6", [ptr(OUT, 0x40, 4)], True, CD)
