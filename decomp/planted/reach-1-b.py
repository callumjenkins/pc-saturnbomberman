from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

FIX = 0x060C0100
NOTHING = 0x0606B1EC            # a function that returns 0
SENTINEL = 0xFFFFFFF0           # the return address check.py gives a function
STACK_TOP = 0x060FFFF0          # r15 on entry
VTABLE = 0x060C0300


def parked(pr_at: int) -> list[tuple]:
    """The stack word a fragment pops into pr, so that its rts returns to the caller."""
    return [plant(STACK_TOP + pr_at, 4, [SENTINEL], 1.0)]


# a plain chain of links at 060D776C, each one's previous being the entry before it, which 06014820 walks
CHAIN = ([plant(0x060D776C + 8 * k, 1, [0, 1, 2, 3, 255], 0.8) for k in range(7)]
         + [plant(0x060D776C + 8 * k + 1, 1, [max(k - 1, 0)], 1.0) for k in range(7)]
         + [plant(0x060D776C + 8 * k + 2, 1, [k + 1 if k < 6 else 0], 1.0) for k in range(7)])

case("f060069D2", [pick(0x06006954, 0x060C0400), ptr(0x060C0000, 0x400), pick(0, 1, 2, 5, 0x10003, -1), pick(0, 1, 0x1FF)], True,
    [plant(STACK_TOP, 4, [0, 1, 2, 5, 0x10003, 0x1234], 0.9), plant(0x06006018, 4, [-1, 0, 1, 3]), plant(0x0600601C, 4, [-1, 0, 1, 3])]
    + [plant(0x060BC190 + 88 * k + 80, 1, [0, 0, 1], 0.9) for k in (0, 1, 2, 5)])
case("f06006EFC", [ptr(0x060C0000, 0x400)], True, [plant(0x06006020, 4, [0x060C0600], 1.0), plant(0x06006024, 4, [0x060C0700], 1.0)])
case("f0600B41A", [span(-2, 20), pick(0, 1, 5, 0x10003, 0xFFFF)], False)
case("f0600B7C2", [pick(0, 5), pick(0, 5), pick(0, 5), pick(0, 5)], True, [plant(0x0600026C, 4, [NOTHING], 1.0)])
case("f0600DBFC", [], False, parked(8))
case("f060128FA", [pick(FIX)], True, [plant(0x060D7768, 4, [0x060C2000]), plant(0x060C2000 + 42, 2, [0, 0, 1, 0xFFFF])])
case("f06021604", [pick(0, 1, 100, 9999999, 0x7FFFFFFF, -1, 0x80000000), span(0, 5)], False,
    [plant(bomber(k) + 4, 1, [0, 0, 0x80], 0.8) for k in range(6)]
    + [plant(bomber(k) + 46, 2, [0, 0x800, 0x800, 0xFFFF], 0.8) for k in range(6)]
    + [plant(bomber(k) + 36, 2, [0, 1, 2, 5], 0.9) for k in range(6)]
    + [plant(bomber(k) + 64, 2, [0, 1, 2, 3, 0xFFFF], 0.9) for k in range(6)]
    + [plant(0x060C0690 + 4 * k, 4, [0, 9000000, 9999990, 0x7FFFFFFF], 0.8) for k in range(8)]
    + [plant(0x060D82DC + 4 * k, 4, [0, 9999990, 9999999], 0.8) for k in range(30)])
case("f0602D752", [], False, parked(12))
case("f06058DA6", [pick(0, 5), pick(0, 5), pick(0, 5), pick(0, 5)], True, [plant(0x060C0AA8, 4, [1, 1, 0, 2]), plant(0x06002F68, 4, [NOTHING], 1.0)])
case("f0606D1CE", [], False, parked(4))
case("f0606FCAE", [], True, [plant(0x060D7B3C, 4, [0x060C2000]), plant(0x060C2000 + 60, 2, [0xFF00, 0xFFFF, 0xFEFF, 0x0000]),
                             plant(0x060D7768, 4, [0x060C2400], 1.0), plant(0x060C062C, 2, [0, 1, 3]),
                             plant(0x060C2400 + 46, 2, [0, 1, 2, 3], 1.0)] + CHAIN)
case("f06092840", [], False, parked(4))
case("f06095992", [ptr(0x060C0000, 0x400), pick(0, 1, 5, 0xFF), pick(0, 1, 5, 0xFF)], True)
case("f0609879E", [pick(FIX), pick(0, 0x2000, 0x4000, 0x8000, 0x10000, 0xFFFFE000, 0x100, 0x1F00)], True,
    [plant(FIX + 4, 4, [0x060C0400], 1.0)])
case("f0609893C", [pick(FIX), pick(0, 0x2000, 0x4000, 0x8000, 0x10000, 0xFFFFE000, 0x100, 0x1F00)], True,
    [plant(FIX + 4, 4, [0x060C0400], 1.0)])
case("f0609E27E", [pick(1, 2, 4, 8, 16, 32, 128, 0x100, 0, 3, 64)], False)
case("f0609F1A8", [ptr(0x060C0000, 0x400)], False)
case("f060A3D3E", [pick(0, FIX), pick(-1, 0, 1, 5), pick(0, 7), pick(0, 7)], True,
    [plant(FIX, 4, [VTABLE], 1.0), plant(VTABLE + 0x178, 4, [NOTHING], 1.0), plant(0x060BB994, 4, [0, 0, NOTHING])])
case("f060A4088", [pick(0, FIX), pick(0, 1), pick(0, 7), pick(0, 7)], True,
    [plant(FIX, 4, [VTABLE], 1.0), plant(VTABLE + 0x17C, 4, [NOTHING], 1.0), plant(0x060BB994, 4, [0, 0, NOTHING])])
case("f060A4B86", [pick(0, FIX), pick(-1, 0, 1, 5), pick(0, 7), pick(0, 7)], True,
    [plant(FIX, 4, [VTABLE], 1.0), plant(VTABLE + 0x1C4, 4, [NOTHING], 1.0), plant(0x060FC228, 4, [0, 0, NOTHING])])

case("f060A5468", [ptr(0x060C0000, 0x400), span(0, 100)], False)
case("f060AAE08", [pick(0x503, 5, -1), pick(0, 1), pick(0, 7), pick(0, 7)], True, [plant(0x060BB994, 4, [0, 0, NOTHING])])
case("f060ABA0E", [pick(FIX), pick(0, 1), pick(0, 7), pick(0, 7)], False,
    [plant(FIX, 4, [0x060C0400], 1.0), plant(0x060C0400 + 8, 4, [0, 0, 0x1000]), plant(0x060C0400 + 52 + 72, 4, [0, 0x1000, 0xFFFFFFFF]),
     plant(0x05F80004, 2, [0, 1]), plant(0x06000324, 4, [0, 1])])
case("f060ACBB8", [pick(FIX)], True, [plant(FIX, 4, [0x060C0400], 1.0)])
case("f060AD428", [pick(FIX)], False, [plant(FIX, 4, [0x060C0400], 1.0)])
case("f060AD62C", [pick(0x503, 5, -1), pick(0, 1), pick(0, 7), pick(0, 7)], True, [plant(0x060FC228, 4, [0, 0, NOTHING])])
case("f060AFB0E", [pick(FIX), pick(-1, 0, 3, 7, 9), pick(0, 5, 31, 33), pick(0, 7)], False,
    [plant(FIX, 4, [0x060C0400], 1.0), plant(0x060C0400 + 52 + 108, 4, [0, 1, 1]), plant(0x060C0400 + 24, 4, [0], 1.0),
     plant(0x25A00404, 4, [0], 1.0), plant(0x25A00000, 1, [0], 1.0), plant(0x060C0400 + 52 + 124, 4, [100, 1000, 44100, 22050, 0, 0xFFFFFFFF])])
case("f060AFDF0", [pick(FIX), pick(0, 1), pick(0, 5), pick(0, 7)], False,
    [plant(FIX, 4, [0x060C0400], 1.0), plant(0x060C0400 + 52 + 108, 4, [0, 1, 1]), plant(0x060C0400 + 24, 4, [0], 1.0),
     plant(0x25A00404, 4, [0], 1.0), plant(0x25A00000, 1, [0], 1.0)])
case("f060B05B8", [pick(FIX)], False,
    [plant(FIX, 4, [0x060C0400], 1.0), plant(0x060C0400 + 4 + 16, 4, [0], 1.0),
     plant(0x25A00404, 4, [0], 1.0), plant(0x25A00000, 1, [0], 1.0), plant(0x060C0400 + 48 + 44, 4, [100, 1000, 44100, 22050, 0, 0xFFFFFFFF]),
     plant(0x060C0400 + 48 + 36, 4, [0, 1, 1]), plant(0x060C0400 + 48 + 40, 4, [0, 8, 9, 16, 17, 40])])
case("f060B087E", [pick(0, 5), pick(0, 5), pick(0, 5), pick(0, 5)], True, [plant(0x060FC228, 4, [0, 0, NOTHING])])

case("f060A28BA", [], False, parked(16))

# The CD block's answers are plants: nothing changes these registers during a trial.
HIRQ, CR1, CR2 = 0x25890008, 0x25890018, 0x2589001C
CD = [plant(HIRQ, 2, [0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0243, 0x00C3, 0x0083, 0x0003, 0x0241, 0x0001], 0.99),
      plant(0x060FA8B8, 2, [0, 0xFFFF, 1, 0x0800], 0.9),
      plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00, 0x0600, 0x0700, 0x0F00, 0xFF00, 0x8100], 1.0)]
HIRQ_OK = plant(HIRQ, 2, [0x0043, 0x00C3, 0x0243, 0x0143, 0x0047, 0x0053, 0x00C7], 1.0)
CR_OK = plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00], 1.0)
CR2_OK = plant(CR2, 2, [0, 1, 2, 3, 5], 1.0)

case("f06052024", [], True, [HIRQ_OK, CR_OK, CR2_OK])

OREGS = 0x20100021
# 060990AA parses the SMPC's peripheral report. Each peripheral starts with a byte whose high nibble is its type and low nibble its data length.
case("f060990AA", [], False,
    [plant(0x060FA970, 1, [2, 2, 2, 0, 1, 3, 4, 5], 1.0), plant(0x060FA907, 1, [0, 1, 1, 2, 2, 5], 1.0),
     plant(0x060FA938, 1, [0, 1], 0.8), plant(0x20100061, 1, [0xE0, 0xE0, 0xC0, 0xA0, 0xA0, 0x80, 0x00, 0xF0], 1.0),
     plant(0x060FA96C, 4, [0, 0, 1], 0.8), plant(0x060FA968, 4, [0, 0, 1, 2], 0.8), plant(0x060FA974, 4, [0, 0, 1, 2, 5, 40], 0.7),
     plant(0x060FA978, 4, [0, 1, 2], 0.5), plant(0x060FA980, 1, [0, 1, 1], 0.8), plant(0x060FA981, 1, [0, 1], 0.5),
     plant(0x060FA982, 1, [0, 1], 0.6), plant(0x060FA983, 1, [0, 1], 0.5), plant(0x060FA984, 1, [0, 1], 0.5), plant(0x060FA985, 1, [0, 1], 0.5),
     plant(0x060FA97D, 1, [0, 1, 2, 3, 6, 15, 16, 20, 40], 0.8), plant(0x060FA97E, 1, [0, 1, 5, 20, 33, 40], 0.7),
     plant(0x060FA97F, 1, [0, 1, 3, 20], 0.6),
     plant(0x060FA90C, 1, [0, 1, 2, 6, 15, 40], 0.8), plant(0x060FA90A, 2, [1, 1, 2, 40], 0.8), plant(0x060FA914, 4, [0, 0, 1, 2], 0.8),
     plant(0x060FA920, 4, [0x060C3000], 1.0), plant(0x060FA958, 4, [0x060C3400], 1.0), plant(0x060FA948, 4, [0x060C3600], 1.0),
     plant(0x060FA928, 4, [0x060C3800], 1.0), plant(0x060FA934, 4, [0x060C3A00], 1.0), plant(0x060FA930, 4, [0x060C3C00], 1.0),
     plant(0x060FA92C, 1, [1, 2], 0.7)]
    + [plant(OREGS + 2 * k, 1, [0x00, 0x01, 0x12, 0x23, 0x30, 0xF0, 0xF1, 0xF2, 0xE3, 0xE0, 0xE1, 0x80, 0x03, 0x04, 0x15, 0x2F, 0x2F, 0x3F, 0x1F, 0xEF, 0xFF, 0xF8], 0.9) for k in range(32)])

case("f06084714", [], False, [plant(0x060D7768, 4, [0x060C2000], 1.0), plant(0x060C2000, 4, [NOTHING], 1.0),
                              plant(0x060C2000 + 66, 2, [2, 0, 1], 1.0), plant(0x060C062C, 2, [0, 1, 3], 1.0),
                              plant(0x060D776C + 9, 1, [3, 2, 1], 1.0), plant(0x060D776C + 25, 1, [2], 1.0), plant(0x060D776C + 17, 1, [1], 1.0),
                              plant(0x060D776C + 24, 1, [3, 0, 255], 1.0), plant(0x060D776C + 16, 1, [3, 0, 255], 1.0),
                              plant(0x060D776C + 26, 1, [0, 1, 2], 1.0), plant(0x060D776C + 18, 1, [0, 1, 2, 3], 1.0)])

case("f060A4FBE", [pick(0x1, 0x40, 0x200, 0x3, 0x80), ptr(0x060C0300, 0x40, 4), ptr(0x060C0400, 0x100, 1), pick(0, 1, 5)], True,
    [plant(HIRQ, 2, [0x0043, 0x00C3, 0x0243, 0x0083, 0x0003, 0x0143], 1.0), plant(CR1, 2, [0x0100, 0x0200, 0x0900, 0xFF00, 0x8100], 1.0),
     plant(CR2, 2, [0, 1, 2, 3, 5], 1.0)])
