from cases import case, pick, plant, ptr, span

BUF = 0x060C5000
N1, N2 = BUF + 0x100, BUF + 0x200

case("f0601254C", [("address",), ("any",), ("any",), ("any",)], True)
case("f06013EC8", [span(-4, 4)], False)
case("f0601DC10", [("address",), ("address",), span(0, 300), span(0, 600)], True)
case("f0601E7C0", [("address",), ("address",), span(0, 16), span(0, 16)], True)
case("f06038C8C", [pick(BUF)], True,
     [plant(BUF + 0x1DEC, 4, [BUF + 0x2000], 1.0)] + [plant(BUF + 0x2000 + 4 * i, 4, [0, 1, 2, 3], 1.0) for i in range(1, 17)])

# One list node of f0601B098: the +12 link ends in zero, the first longword is the 0x7FFFFFFF the search wants.
case("f0601B098", [pick(BUF)], True,
     [plant(BUF + 80, 4, [0, N1], 0.9), plant(N1, 4, [0x7FFFFFFF, 5], 0.8), plant(N1 + 12, 4, [0, N2], 0.5),
      plant(N2, 4, [0x7FFFFFFF, 3], 0.7), plant(N2 + 12, 4, [0], 1.0)])
# The list head the first callee leaves at 060875C8 ends in zero after two nodes.
case("f0601CF60", [("any",)] * 4, True,
     [plant(0x060875C8, 4, [0, N1], 0.9), plant(N1 + 52, 4, [0, N2], 0.7), plant(N2 + 52, 4, [0], 1.0)])
case("f0601F4F8", [pick(BUF), pick(N1), span(0, 7), ("any",)], True,
     [plant(BUF + 48, 2, [1, 2, 3, 7, 100], 1.0), plant(N1 + 44, 4, [0, 5, 100, 1000], 1.0)]
     + [plant(N1 + 52 + 2 * k, 2, [0, 1, 5, 40], 0.8) for k in range(8)])
# The status byte at the argument is what the wait is for: 0 and 1 keep it waiting.
case("f06025984", [pick(BUF)], True, [plant(BUF, 1, [2, 3, 0x80, 0xFF], 1.0)])
case("f0602767C", [("any",)] * 4, True,
     [plant(0x060769B0, 4, [0, N1, N1], 0.9), plant(N1, 4, [0, N2], 0.7), plant(N2, 4, [0], 1.0),
      plant(0x20000118 + N1, 4, [0, 1], 1.0), plant(0x20000118 + N2, 4, [0, 1], 1.0)])
case("f0602BA00", [("address",)], False,
     [plant(0x0608ACB0, 4, [0, 1, 2, 5, 8], 1.0), plant(0x0608ACB8, 4, [0, BUF], 0.9)])
# The two 24-byte record tables end in a zero first word; the text at 06089B18 is a few words ending in a zero byte.
case("f0602CC0C", [("address",)], True,
     [plant(0x06077F7C, 4, [N1], 1.0), plant(0x06077F94, 4, [N1], 1.0),
      plant(N1, 4, [13, 5, 0], 0.9), plant(N1 + 24, 4, [0, 13], 0.8), plant(N1 + 48, 4, [0], 1.0),
      plant(0x06089B18, 4, [0, N2, N2], 0.9), plant(N2, 4, [0x41424320, 0x41420000, 0x20414200], 1.0),
      plant(N2 + 4, 4, [0x43442045, 0x46470000, 0], 1.0), plant(N2 + 8, 4, [0], 1.0),
      plant(0x0608AF56, 1, [0, 1], 1.0), plant(0x06089B1C, 1, [0, 1], 1.0), plant(0x06089B10, 4, [0, 5], 1.0)])
case("f0602EDBC", [pick(0, BUF, N1)], False,
     [plant(0x06078028, 4, [0, BUF, N1], 0.9), plant(BUF + 40, 4, [0, N1], 0.6), plant(N1 + 40, 4, [0, N2], 0.6),
      plant(N2 + 40, 4, [0], 1.0)])
case("f060335FC", [pick(BUF, 0), pick(N1)], True,
     [plant(BUF + 0x10C8, 4, [0, 1], 1.0), plant(BUF + 0x10CC, 4, [0, 3, 4], 1.0),
      plant(BUF + 64, 4, [0, 5, 10], 1.0), plant(BUF + 68, 4, [0, 20, 100], 1.0), plant(N1 + 44, 2, [0, 3, 8, 20], 1.0)])
case("f06034990", [("address",), ("address",), ("any",)], True)
case("f06039C1C", [pick(BUF), span(0, 40)], True, [plant(BUF + 124, 4, [-1, 0, 3, 10, 22], 1.0)])
case("f0603A1C0", [("any",)] * 4, True)
# The context at the argument names a small slot number, and the slot table holds the transfer kind 1, 2 or other.
case("f0603AE98", [pick(BUF), ("any",), ("any",), ("any",)], True,
     [plant(BUF + 0x1DE0, 4, [N1], 1.0), plant(N1 + 140, 4, [0, 1, 2], 1.0)]
     + [plant(BUF + 0x9DC + 4 * i, 4, [0, 1, 2, 3], 1.0) for i in range(3)])
case("f0603B390", [pick(BUF)], False,
     [plant(BUF + 60, 4, [0, 3, 10], 1.0), plant(BUF + 56, 4, [0, 3, 10, 20], 1.0),
      plant(BUF + 0x1DE0, 4, [N1], 1.0), plant(N1, 4, [0, 1, 2, 3, 5], 1.0)])
case("f06042468", [pick(BUF)], True, [plant(BUF + 20, 4, [0, 1, 2, 5], 1.0)])
case("f060440E4", [("address",), ("any",), ("any",), ("any",)], True)
case("f0604A920", [("address",)], True)
case("f06051D10", [pick(BUF, 0x00200100), span(0, 7)], True)
case("f06052510", [("address",), ("address",), pick(0, 1)], True)
case("f06057C88", [span(0, 8), ("any",)], True)
case("f06059EBC", [span(0, 3)], True, [plant(0x0608D394, 4, [0, 1, 2], 1.0)])
case("f0605AF90", [span(0, 8), ("address",), span(0, 64), ("any",)], True)
case("f0605BFA4", [("address",)], True)
case("f0605DA18", [span(0, 3)], True)
case("f0605F634", [span(-2, 4), ("any",)], True, [plant(0x0608D394, 4, [0, 1, 2], 1.0)])
case("f06062280", [], False, [plant(0x06079FBC, 4, [0, 0, 1], 1.0)])
case("f06068538", [span(0, 0xFFFF)], False)
case("f0606A6D0", [], False, [plant(0x25D00010, 2, [2, 3, 0xFFFF], 1.0)])
case("f0606BC08", [("any",)], True,
     [plant(0x0608F444, 4, [BUF], 1.0), plant(BUF + 148, 4, [0, 1, 4, 8], 1.0)]
     + [plant(BUF + 52 + 4 * i, 4, [1, 2, 3], 0.5) for i in range(8)])
case("f0606CDF8", [("address",)] * 4, True)
case("f0606F2A8", [("address",)], True)
case("f06070070", [span(0, 23), ("any",), ("address",), ("any",)], True)
case("f06071A30", [("address",), span(0, 8)], True)
