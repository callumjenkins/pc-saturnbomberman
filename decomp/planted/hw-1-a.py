from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

BUF = 0x060C5000
CMDBUF = BUF + 0x3000
SF = 0x20100063
HIRQ = 0x25890008
CR1, CR2, CR3, CR4 = 0x25890018, 0x2589001C, 0x25890020, 0x25890024
SHADOW = 0x060FA8B8

CD = [plant(HIRQ, 2, [0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0243, 0x00C3, 0x0083, 0x0003, 0x0241, 0x0001], 0.99),
      plant(SHADOW, 2, [0, 0xFFFF, 1, 0x0800], 0.9),
      plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00, 0x0600, 0x0700, 0x0F00, 0xFF00, 0x8100], 1.0)]
CD_FULL = [plant(HIRQ, 2, [0xFFFF, 0x00C3, 0x0243, 0x0083, 0x0003], 1.0),
           plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00, 0x0600, 0x0700, 0x0F00], 1.0)]
SMALL = [plant(CR2, 2, [0, 1, 2, 3, 4, 5], 0.9)]

case("f06055060", [], False, [plant(0x060FA900, 1, [0, 1, 1]), plant(SF, 1, [0], 1.0)])
case("f06095622", [pick(0, 1, 0x81, 0x80, 0x41, 0xFF), span(0, 0xFFFF), span(0, 255), span(0, 255)], True,
     CD + [plant(HIRQ, 2, [0x0001, 0x0003], 0.3), plant(SHADOW, 2, [0], 0.5)])
case("f060956CC", [pick(0, 1, 2)], True, CD_FULL)
case("f0609576C", [ptr(CMDBUF, 0x40, 4)], True, CD)
case("f06095836", [span(0, 255)], True, CD)
case("f060958F2", [span(0, 0xFFFF)], False, CD)
case("f0609590A", [], False, CD)
case("f060959CA", [pick(1, 2, 3, 0x20, 0xFFFF, 0x801), ptr(CMDBUF, 0x10, 2), ptr(CMDBUF + 0x40, 0x10, 2)], True,
     CD + [plant(HIRQ, 2, [0x0002, 0x0020, 0x0022], 0.3), plant(SHADOW, 2, [0], 0.5)])
case("f06095AB4", [ptr(CMDBUF, 0x20, 2)], False, CD)
case("f060A4D20", [pick(1, 2, 0x200, 0x40, 0xFFFF, 0)], True, CD)
case("f060A4D8E", [], True, CD)
case("f060A4E50", [span(0, 255), span(0, 0xFFFFFF)], True, CD)
case("f060A4EA0", [pick(BUF + 0x7E00), pick(BUF + 0x7E04), pick(BUF + 0x7E08)], True, CD)
case("f060A4F40", [span(0, 255), span(0, 0xFFFFFF), span(0, 0xFFFFFF)], True, CD)
case("f060A4FA8", [pick(0, 0x40, 0x200, 0x80), ptr(CMDBUF + 0x300, 0x10, 1), ptr(CMDBUF + 0x320, 0x10, 1)], True, CD)
case("f060A5180", [ptr(0x060C5000, 0x100, 1), span(0, 0x100)], False)
case("f060A8B72", [pick(1, 2, 0x200, 0x40, 0xFFFF, 0)], True, CD)
case("f060AE3D4", [span(0, 255)], True, CD)
case("f060AE434", [pick(BUF + 0x7E00)], True, CD)
case("f060AE4A2", [span(0, 255), pick(BUF + 0x7E00), pick(BUF + 0x7E04)], True, CD)
case("f060AE530", [span(0, 255), ptr(CMDBUF + 0x400, 0x10, 1)], True, CD)
case("f060AE5B0", [span(0, 255), pick(BUF + 0x7E00)], True, CD)
case("f060AE628", [span(0, 255), pick(BUF + 0x7E00), pick(BUF + 0x7E04)], True, CD)
case("f060AE6AC", [pick(BUF + 0x7E00), pick(BUF + 0x7E04), pick(BUF + 0x7E08)], True, CD)
case("f060AE73E", [span(0, 255), span(0, 0xFFFF), span(0, 0xFFFF)], True, CD)
case("f060AE7A0", [ptr(CMDBUF + 0x300, 0x10, 1), ptr(CMDBUF + 0x320, 0x10, 1)], True, CD)
case("f060AE82A", [span(0, 255), span(0, 0xFFFF), span(0, 0xFFFFFF)], True, CD)
case("f060AE8B0", [span(0, 255), span(0, 255)], True, CD)
case("f060AE908", [span(0, 255), span(0, 0xFFFF), span(0, 0xFFFF)], True, CD)
case("f060AE964", [span(0, 255), span(0, 0xFFFF)], True, CD)
case("f060AE9C2", [span(0, 255), span(0, 0xFFFF), span(0, 0xFFFF), span(0, 255)], True, CD)
case("f060A79CC", [span(0, 255), pick(BUF + 0x7E00), pick(BUF + 0x7E40)], True, CD_FULL + [plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0xFF00, 0x8100])])
case("f060A8CA6", [], True, CD_FULL + [plant(0x060FC080, 4, [-13, 5, 1], 1.0), plant(0x060FC084, 4, [BUF + 0x8000], 1.0)])
case("f060AAD4E", [pick(BUF + 0x7300)], True, CD_FULL + [plant(BUF + 0x7300 + 32, 4, [0, 1, 5])])

SP = 0x060FFFF0
TABLES = [BUF + 0x7600, BUF + 0x7700, BUF + 0x7800, BUF + 0x7900]
case("f0609799C", [span(-300, 300), ptr(BUF + 0x7B00, 0x40, 4), ptr(BUF + 0x7B80, 0x40, 4), pick(BUF + 0x7A00)], False,
     [plant(SP + 4 * k, 4, TABLES, 1.0) for k in range(4)] + [plant(SP + 16, 4, [0, 1, 2, 3, 5, 9], 1.0)])
case("f06097A4C", [span(-300, 300), ptr(BUF + 0x7B00, 0x40, 4), ptr(BUF + 0x7B80, 0x40, 4), ptr(BUF + 0x7BC0, 0x40, 4)], False,
     [plant(SP, 4, [BUF + 0x7A00], 1.0)] + [plant(SP + 4 * k, 4, TABLES, 1.0) for k in range(1, 7)]
     + [plant(SP + 28, 4, [0, 1, 2, 3, 5, 9], 1.0)])

SRC = BUF + 0x8000
case("f0609E28C", [pick(BUF + 0x7400)], False,
     [plant(SF, 1, [0], 1.0), plant(BUF + 0x7400, 4, [SRC], 1.0), plant(BUF + 0x7404, 2, [0x1100], 1.0), plant(BUF + 0x7408, 4, [BUF + 0x9000], 1.0),
      plant(BUF + 0x740C, 2, [0x20, 0x41, 0x2], 1.0), plant(SRC + 0x400, 4, [0x1000], 1.0), plant(SRC + 0x404, 4, [0x2000, 0x2010], 1.0),
      plant(SRC + 0x408, 4, [0x3000], 1.0), plant(SRC + 0x412, 2, [0, 1], 1.0), plant(SRC + 0x414, 2, [0x500, 0], 1.0),
      plant(SRC + 0x1008, 4, [0x4000], 1.0)])

HIRQ_FULL = [plant(HIRQ, 2, [0xFFFF, 0x00C3, 0x0243, 0x0083, 0x0003], 1.0)]
case("f06095474", [ptr(CMDBUF, 0x40, 2)], True, HIRQ_FULL + [plant(CR1, 2, [0xFF00, 0x2000, 0x2100, 0x0100, 0x0000, 0x0500], 1.0)])
case("f0609559C", [ptr(CMDBUF, 0x40, 2)], True, HIRQ_FULL + SMALL + [plant(CR1, 2, [0x0000, 0x0100, 0xFF00, 0x8100], 1.0)])
case("f0609587E", [ptr(CMDBUF, 0x40, 2), ptr(CMDBUF + 0x80, 0x10, 4), span(0, 255)], True,
     HIRQ_FULL + SMALL + [plant(CR1, 2, [0x0000, 0x0100, 0xFF00, 0x8100], 1.0)])
case("f060A8226", [pick(BUF + 0x7200)], True,
     HIRQ_FULL + [plant(CR1, 2, [0x0000, 0x0100, 0x0000, 0xFF00], 1.0), plant(0x060FC084, 4, [BUF + 0x8000], 1.0),
                  plant(BUF + 0x8000 + 84, 4, [0, 1, 2, 3, 5], 1.0), plant(BUF + 0x8000 + 88, 4, [0, 1, 2, 3], 1.0)]
     + [plant(BUF + 0x8000 + 92 + 16 * k + 12, 4, [0, 5], 1.0) for k in range(6)])

DEVREC = BUF + 0x8000
case("f060A6C04", [pick(BUF + 0x7000), span(0, 300)], True,
     HIRQ_FULL + [plant(CR1, 2, [0x0100, 0x0200, 0x0100, 0x0300, 0x0400, 0x0600], 1.0), plant(0x060FC084, 4, [DEVREC], 1.0),
                  plant(0x060FC088, 4, [0, 1, 1], 1.0), plant(0x060FC080, 4, [0, 0, -13, 5], 1.0)]
     + [plant(DEVREC + k, 1, [0, 1, 0], 0.8) for k in range(48)] + [plant(DEVREC + 48, 4, [0, 0, 1], 1.0), plant(DEVREC + 56, 4, [0, 5, -1, 0x7FFFFFFF], 1.0)])
