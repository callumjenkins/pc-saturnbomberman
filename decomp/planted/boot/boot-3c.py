from cases import case, plant  # noqa: F401

RET1 = 0x060290A8            # the BIOS stub that returns 1
BIOS = [plant(0x06000330, 4, [RET1], 1.0), plant(0x06000334, 4, [RET1], 1.0), plant(0x06000344, 4, [RET1], 1.0)]

# Both wait until a word an interrupt advances changes, which no plant does, so the word reads back one more at each load.
case("f06051BB4", [], False, ticks=(0x0608B980,))
case("f06032FD4", [("any",)], False, BIOS, ticks=(0x06089CB8,))
