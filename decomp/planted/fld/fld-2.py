from cases import case, pick, plant, ptr, span

BUF = 0x060C5000
HIRQ, CR1 = 0x25890008, 0x25890018
# The block's answers are plants: nothing changes these registers during a trial.
# A wait that never ends is 2.9 million passes, so only an odd trial gets a HIRQ the wait does not want.
CD = [plant(HIRQ, 2, [0xFFFF] * 40 + [0x0243, 0x00C3, 0x0083, 0x0003, 0x0241, 0x0001], 1.0),
      plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00, 0x0600, 0x0700, 0x0F00, 0xFF00, 0x8100], 1.0)]

case("f002001BE", [("any",)] * 4, True, CD)
case("f00200208", [span(0, 3), ("any",)], True, CD)
case("f002002F2", [], True, CD)
case("f0020033E", [("any",)] * 2, True, CD)
case("f00200410", [("any",), span(0, 64), ("any",)], True, CD)
case("f002005B4", [pick(0x0001, 0x0002, 0x0040, 0x0200, 0xFFFF)], True, CD)
case("f0020060A", [ptr(BUF, 0x40, 4)], True, CD)
case("f002009BC", [pick(0, 1)], True, CD)
case("f00201096", [span(0, 8), ptr(BUF, 0x40, 2)], True, CD)
