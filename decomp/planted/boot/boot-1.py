from cases import case, pick, plant, ptr, span

A = 0x060C0100
SF = 0x20100063
HIRQ, CR1 = 0x25890008, 0x25890018
# The BIOS vector table is not in the image: each pointer is made to reach a routine that returns 1, and the
# frame counter that an interrupt would advance is put where a wait for it is already over.
RET1 = 0x060290A8
BIOS = [plant(0x06000330, 4, [RET1], 1.0), plant(0x06000334, 4, [RET1], 1.0), plant(0x06000344, 4, [RET1], 1.0)]
FRAMES = [plant(0x06089CB0, 4, [0x7FFFFFFE], 1.0)]
CD = [plant(HIRQ, 2, [0xFFFF] * 40 + [0x0243, 0x00C3, 0x0083, 0x0003, 0x0241, 0x0001], 1.0),
      plant(CR1, 2, [0x0000, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0800, 0x0A00, 0x0600, 0x0700, 0x0F00, 0xFF00, 0x8100], 1.0)]
POINT = ptr(A, 4, 4)            # one fixed address, so that plants can name the fields

# The count is a loop bound; the pointer goes into plantable work RAM.
case("f06010B20", [span(0, 1000)], False)
case("f06012C8C", [ptr(A, 0x100)], True,
     [plant(0x060767CC, 4, [0x060C0600], 1.0), plant(0x0608AB68, 4, [0x060C0300, 0], 0.9), plant(0x060C0314, 4, [0x060C0400], 1.0)])
case("f06014E74", [ptr(A, 0x100), ("any",), ("any",), span(0, 16)], True)
# the list head is plantable, and each node's link ends the chain
case("f0601CC34", [POINT, ("any",), ("any",), ("any",)], True,
     BIOS + [plant(0x060875C8, 4, [0, 0x060C0200, 0x060C0100], 1.0), plant(A + 52, 4, [0, 0, 0x060C0200], 1.0),
             plant(0x060C0234, 4, [0, 0x060C0300], 1.0), plant(0x060C0334, 4, [0], 1.0)], False)
case("f0601DAB0", [ptr(A, 0x100), ptr(0x060C0400, 0x400, 2), span(0, 600), span(0, 600)], True)
case("f0601DCE8", [("any",), ("any",), span(0, 20), span(0, 20)], True, [plant(0x060FFFF0, 4, [0, 3, 8, 30], 1.0)])
# a width of zero or less never ends in the game's code either
case("f0601EFE8", [ptr(A, 0x400, 2), span(1, 64), span(0, 64)], False)
B = 0x060C0800
case("f0601F834", [POINT, ptr(B, 4, 4), span(0, 7), ("any",)], True,
     [plant(A + 48, 2, [4, 8, 16, 64], 1.0), plant(B + 44, 4, [0, 3, 9, 30], 1.0), plant(B + 48, 4, [0, 1, 5], 1.0)]
     + [plant(B + 52 + 2 * i, 2, [0, 1, 3, 9], 1.0) for i in range(8)])
case("f06025A0C", [("any",)], True, BIOS)
case("f0602777C", [("any",)] * 4, True,
     BIOS + [plant(0x060769B0, 4, [0x060C0100, 0x060C0100, 0], 1.0), plant(A, 4, [0, 0x060C0200], 1.0),
             plant(A + 0x18, 4, [0, 0, 1], 1.0), plant(0x060C0200, 4, [0], 1.0), plant(0x060C0218, 4, [0, 1], 1.0)], False)
case("f060286A8", [("any",), span(0, 8), ("any",), ("any",)], True, BIOS)
C = 0x060C0200
case("f0602E26C", [], True,
     [plant(0x060769D4, 4, [A], 1.0), plant(A + 20, 4, [C], 1.0)]
     + [plant(C + 24 * i, 4, [10, 10, 5, 0] if i < 7 else [0], 1.0) for i in range(8)])
case("f0602BF00", [ptr(A, 0x40, 2), span(0, 32), ("any",), pick(0, 1)], True)
case("f06033050", [], True, [plant(SF, 1, [0], 1.0)])
case("f06036C60", [POINT, POINT, ("any",), ("any",)], True, FRAMES)
case("f06038CE8", [POINT], True,
     [plant(A + 0x1CC + 4 * k, 4, v, 1.0) for k, v in enumerate([[1], [1, 2], [2, 3, 0], [3, 4, 0], [4, 5, 0], [5, 0], [0]])])
case("f0603A0B4", [POINT], True,
     [plant(A + 0x1DE8, 4, [0, 1, 1, 1, 1], 1.0), plant(A + 120, 4, [0xD0, 0xD3, 0xD7], 1.0)] + BIOS + FRAMES)
case("f0603AAB8", [POINT], True,
     [plant(A + 0x1DE4, 4, [0x060C2400], 1.0), plant(0x060C2418, 4, [0, 1, 2, 3], 1.0), plant(0x060C2428, 4, [0x060C3000], 1.0)])
case("f060426AC", [POINT], True,
     [plant(A + 24, 4, [0, 1, 2], 1.0), plant(A + 4, 4, [0x060C0400], 1.0),
      plant(0x060C0400, 4, [0x060C0500, 0], 1.0), plant(0x060C0404, 4, [0x060C0600, 0], 1.0),
      plant(0x060C0408, 4, [0x060C0700, 0], 1.0), plant(A + 28, 4, [0, 3, 9], 1.0)])
case("f06051BC8", [POINT], True, BIOS + [plant(A + 60, 4, [0x00F00000, 0x00100000, 0x00800000], 1.0)])
case("f06051E30", [pick(0x05F00000, 0x060C0100), span(0, 16), ("any",)], True)
case("f060593B8", [], True, [plant(0x0608D88C, 4, [0, 1, 2, 5, 8], 1.0)])
case("f0605A6B8", [ptr(A, 0x100), ("any",)], True, BIOS + CD + FRAMES)
case("f0605B208", [span(0, 3), ("any",), ("any",), ("any",)], True,
     [plant(0x0608D9EC, 4, [0x060C1000], 1.0), plant(0x0608D9F0, 4, [0x060C2000], 1.0)]
     + [plant(0x060C1000 + 32 * i + 24, 4, [0, 1, 2, 5], 1.0) for i in range(4)])
case("f0605CEFC", [POINT, ("any",), ("any",), ("any",)], False,
     [plant(A + 2, 1, [0], 1.0), plant(A + 3, 1, [4, 5, 6, 8, 12], 1.0)] + CD)
case("f0605E53C", [], True, [plant(0x0608D9E8, 4, [0, 1, 2, 5, 8], 1.0)])
case("f060669F8", [POINT], True,
     [plant(SF, 1, [0], 1.0), plant(0x25A00400, 4, [0x1000], 1.0), plant(0x25A01008, 4, [0x2000], 1.0),
      plant(A, 4, [0x060C0400], 1.0), plant(A + 8, 4, [0x060C0500], 1.0), plant(A + 4, 2, [0, 2, 8], 1.0),
      plant(A + 12, 2, [0, 1, 4], 1.0)])
# the fifth to seventh arguments are on the stack, at the entry r15 of 0x060FFFF0
case("f06068E64", [("any",)] * 4, True,
     [plant(0x0608F014, 4, [0x060C1000], 1.0), plant(0x060896BC, 4, [0x060C2000], 1.0),
      plant(0x060FFFF0, 4, [0, 1, 2, 3], 1.0), plant(0x060FFFF4, 4, [0x060C0600], 1.0),
      plant(0x060FFFF8, 4, [0, 0xFFFF, 5], 1.0)])
case("f0606AD50", [POINT, ("any",), ("any",), ("any",)], True,
     [plant(0x0608F444, 4, [0x060C1000], 1.0), plant(A + 40, 4, [0, 1, 2, 3], 1.0)])
case("f0606C3AC", [span(0, 32), ptr(A, 0x100, 2)], True, CD + BIOS)
case("f0606CFCC", [ptr(A, 0x40, 4), span(0, 7)], True)
case("f0606F318", [POINT, ("any",), ("any",), ("any",)], True,
     [plant(A + 120, 4, [0x060C0400], 1.0), plant(A + 124, 4, [0x060C0500], 1.0),
      plant(A + 164, 4, [0, 1, 4, 2, 3], 1.0)])
case("f060704C8", [span(0, 7), span(0, 7), ("any",), ("any",)], True,
     [plant(0x0608F458, 4, [0x060C1000], 1.0), plant(0x060C1348, 4, [0, 1], 1.0)]
     + [plant(0x060C1018 + i, 1, [0, 1], 1.0) for i in range(8)])
case("f06072748", [span(0, 2000)], False)
case("f06033A1C", [("any",), pick(0, 1)], True,
     [plant(0x06088028, 4, [A], 1.0), plant(A + 4, 4, [0x060C0200], 1.0), plant(A + 8, 4, [0x060C0200], 1.0),
      plant(0x060C0200, 4, [1, 2, 0], 1.0), plant(0x060C0204, 4, [0x060C0300, 0], 1.0), plant(0x060C0208, 4, [0x060C0300, 0], 1.0),
      plant(0x060C0300, 4, [2, 0], 1.0), plant(0x060C0304, 4, [0], 1.0), plant(0x060C0308, 4, [0], 1.0)])
D = 0x060C2000
case("f0603B41C", [POINT], True,
     BIOS + [plant(A + 56, 4, [0, 1, 3, 6], 1.0), plant(A + 60, 4, [0, 2, 4, 6], 1.0), plant(A + 0x1DE0, 4, [D], 1.0),
             plant(D, 4, [0, 1, 2, 3], 1.0), plant(D + 68, 4, [1, 2, 4], 1.0), plant(A + 41, 1, [0, 1, 2], 1.0)]
     + [plant(D + 140 + 4 * i, 4, [0, 1, 2, 3], 1.0) for i in range(4)]
     + [plant(A + 0x9DC + 4 * i, 4, [0, 1, 2, 3], 1.0) for i in range(4)]
     + [plant(A + 0xDDC + 4 * i, 4, [0, 1, 2, 3], 1.0) for i in range(4)])
case("f0604AD10", [POINT, ("any",), ("any",), ("any",)], True,
     [plant(A + 24, 4, [0x060C0400, 0], 1.0), plant(0x060C0400, 1, [0x41, 0x20, 0], 1.0),
      plant(0x060C0401, 1, [0x20, 0x42, 0], 1.0), plant(0x060C0402, 1, [0, 0x41], 1.0)]
     + [plant(0x060C0403 + i, 1, [0], 1.0) for i in range(4)])
case("f060541A8", [POINT, span(0, 20)], True,
     [plant(A + 80, 4, [0x060C0400], 1.0), plant(0x060C0400, 4, [0, 0x060C0500], 1.0), plant(0x060C0500, 4, [0], 1.0)]
     + [plant(n + 12, 4, [0x060C3000], 1.0) for n in (0x060C0400, 0x060C0500)]
     + [plant(n + 16, 4, [0, 3, 9, 30], 1.0) for n in (0x060C0400, 0x060C0500)]
     + [plant(n + 20, 4, [0, 1, 3], 1.0) for n in (0x060C0400, 0x060C0500)])
T = 0x060C0600
case("f06061064", [POINT, ptr(0x060C1000, 4, 4)], True,
     [plant(A + 1, 1, [5], 1.0), plant(A + 2, 1, [0], 1.0), plant(A + 3, 1, [4, 6, 8, 12], 1.0),
      plant(0x060C1006, 1, [5, 5, 5, 6], 1.0), plant(0x060C1010, 2, [0, 2, 8, 20], 1.0),
      plant(0x060C1024, 4, [0x060C0800], 1.0), plant(0x060C1014, 4, [T], 1.0), plant(T + 1, 1, [0, 0x80], 1.0),
      plant(T + 9, 1, [0x80, 0], 1.0), plant(T + 17, 1, [0x80], 1.0)]
     + [plant(T + 25 + 8 * i, 1, [0x80], 1.0) for i in range(6)]
     + [plant(A + 5 + k, 1, [2, 3, 4], 1.0) for k in range(13)])
case("f0602FBE4", [POINT, ("any",)], True,
     [plant(A + 44, 4, [0, 1, 2, 3], 1.0), plant(A + 40, 4, [0, 1, 2, 3], 1.0)]
     + [plant(A + 68 + 4 * k, 4, [0x1000, 0x2000, 0x3000], 1.0) for k in range(6)]
     + [plant(A + 20, 2, [1, 2, 4], 1.0), plant(A + 16, 2, [1, 2, 4], 1.0), plant(A + 60, 2, [0, 3, 8, 16], 1.0),
        plant(A + 24, 4, [0x060C2000], 1.0), plant(A + 48, 4, [0, 4, 20], 1.0), plant(A + 52, 4, [0, 4, 20], 1.0),
        plant(A + 28, 4, [0, 50, 200], 1.0), plant(A + 88, 4, [0, 1], 1.0), plant(A + 8, 2, [0, 1, 2], 1.0)])
