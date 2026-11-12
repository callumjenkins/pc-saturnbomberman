from cases import case, plant, ptr, span

# The copy and fill routines take a count that a random word makes four billion passes long.
HALFWORDS = ptr(0x060C0100, 0x100, 2)
BYTES = ptr(0x060C0300, 0x100, 1)

case("f06002404", [HALFWORDS, ptr(0x060C0200, 0x100, 2), span(1, 8)], False)
case("f06002430", [BYTES, ptr(0x060C0400, 0x100, 1), span(1, 8)], False)
case("f0600245C", [HALFWORDS, span(1, 8), span(0, 0xFFFF)], True)
# the work area at 06002D7C holds a pointer to the VDP2 register copy
case("f060024D8", [span(0, 0xFFFF)], True, [plant(0x06002D7C, 4, [0x060C0100], 1.0)])
