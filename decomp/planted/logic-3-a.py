from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

CUR = [plant(0x060D7768, 4, [bomber(0), bomber(1), bomber(2)], 1.0)]
OTHER = [plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0)]
MOVER = [plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0)]
BRAIN = 0x060C2200
S = 0x060C2400          # a decoder stream

# 066D8: the table pointer, with room for the zero fill
case("f060066D8", [], False, [plant(0x060B2D24, 4, [0x060C0000, 0x060D8000, 0x060C1000, 0x060D0010])])
case("f060079B6", [pick(S), pick(0, 65, 255, -1)], True, [plant(S, 4, [0x060C3000, 0x060C3100])])
case("f06008ABA", [span(0, 5), span(0, 3)], True, [plant(0x060BD8E4 + 4 * k, 4, [0x060C3000, 0x060C3400], 1.0) for k in range(4)])
PAL = ([plant(0x060BD8E8, 4, [0x060C3000], 1.0), plant(0x060BD8D4, 4, [0x060C4000], 1.0), plant(0x060BD8D8, 4, [0x060C4000], 1.0), plant(0x060C4004, 4, [0x060C3000], 1.0)]
       + [plant(0x060C3000 + 4 * k, 4, [0x060C3400, 0x060C3600], 1.0) for k in range(40)]
       + [plant(a + 2 * k, 2, [0, 2, 5, 33, 0x7FF0, 0x4000], 0.5) for a in (0x060C3400, 0x060C3600) for k in range(2)]
       + [plant(0x26006168, 4, [0, 0, 0x060090D8]), plant(0x060BF4A8, 2, [0, 3, 40], 1.0)])
case("f06008ECA", [span(0, 5), pick(0, 5, 0x20, 0x7FFF, 0x8000, 0xFFFF, 0x1F3)], True, PAL)
case("f06008ECE", [span(0, 5)], True, PAL)
case("f0600A8F4", [pick(1, 2, 4, 8, 16, 32), span(0, 0xFFFFFF)], True,
     [plant(0x060FA9C8 + 2 * k, 2, [0, 0x8000, 0xC000, 0x8010, 0xC010, 0x0010, 0x4000, 0x0001, 0x1000, 0x0100], 0.8) for k in range(24)]
     + [plant(0x060FA9DE, 2, [0, 1, 2]), plant(0x060FA9DA, 2, [0, 0x100, 0x1000, 0x30, 0x00C0, 0x3000])])
TILES = [plant(0x060D7E98, 4, [0x06000000], 1.0), plant(0x060D7EA0, 4, [0x060C6000], 1.0),
         plant(0x060DF988, 4, [0x06000000], 1.0), plant(0x060DF98C, 4, [0x060C6000], 1.0),
         plant(0x060D7E9C, 4, [0x06000000], 1.0), plant(0x060D7EA4, 4, [0x060C6000], 1.0)]
case("f0600C796", [span(0, 300), span(0, 63), span(0, 63)], False, TILES)
case("f0600C7BE", [span(0, 300), span(0, 4000)], False, TILES)
# the tile numbers stay below 0xFF00 so that the tiles read never reach the stack, which the check leaves out
MAP = [plant(0x060F28B0 + 2 * k, 2, [0, 5, 100, 0x1000, 0x6954, 0x8000, 0xFEFF], 1.0) for k in range(4096)]
MAPS = MAP + [plant(m + 2 * k, 2, [0, 5, 100, 0x1000, 0x6954, 0x8000, 0xFEFF], 1.0) for m in (0x060F48B0, 0x060F68B0, 0x060F88B0) for k in range(4096)]
GRID = TILES + MAP + [plant(0x060D7E6C, 2, [0], 1.0), plant(0x060D7E6C, 2, [1], 0.35)]
GRIDS = TILES + MAPS + [plant(0x060D7E6C + k, 2, [0], 1.0) for k in (0, 2, 4, 6)] + [plant(0x060D7E6C + k, 2, [1], 0.07) for k in (0, 2, 4, 6)] + [plant(a, 4, [0x060C6000], 1.0) for a in (0x060D7EA8, 0x060D7EAC, 0x060D7EB0)]
case("f0600C876", [], False, GRID)
case("f0600C8FA", [], False, GRIDS)

# the decoder's handlers all take a stream whose cursors and ring the plants make valid
STREAM = ([plant(S, 4, [0x060C3000], 1.0), plant(S + 4, 4, [0x060C3200], 1.0), plant(S + 8, 4, [0x060C3400], 1.0),
           plant(S + 16, 4, [0xFF, 0x3F, 0xF, 0x1FF], 1.0), plant(S + 24, 4, [0, 1, 2, 7, 100, 0x3FF, 0x1234, 0xFFFFFFFF], 0.9)])
_STREAM_VOID = {"06033DFE", "06033E0C", "06033F88", "06033FA4", "0603415A", "06034194"}
_STREAMERS = (
    "06033DF0", "06033DFE", "06033E0C", "06033E26", "06033E36", "06033E48", "06033E5A", "06033E6C",
    "06033E7E", "06033E90", "06033EA2", "06033EB4", "06033EC6", "06033ED8", "06033EEA", "06033EFC",
    "06033F0E", "06033F1E", "06033F2E", "06033F3E", "06033F4E", "06033F5E", "06033F6E", "06033F88",
    "06033FA4", "06033FC0", "06033FD2", "06033FE6", "06033FFA", "0603400E", "06034036", "0603404A",
    "0603405E", "06034086", "060340C2", "060340D4", "060340E6", "060340F8", "0603410A", "0603411C",
    "0603412E", "0603415A", "06034194", "060341B0", "060341C0", "060341D2", "060341E4", "060341F6",
    "06034208", "0603422C", "0603423E", "06034250", "06034262", "06034298", "060342A8", "060342B8",
    "060342C8", "060342D8", "060342E8",
)
for _a in _STREAMERS:
    case("f" + _a, [pick(S)], _a not in _STREAM_VOID, STREAM)

SPIN = 0x060C3800
SPINS = [plant(0x060C164C, 4, [SPIN], 1.0), plant(SPIN, 1, [0x10, 0x25, 0xF0, 0x01]), plant(SPIN + 1, 1, [0, 0x12, 0x31, 0xA5, 0xFF, 0x21]),
         plant(SPIN + 2, 2, [0, 5, 14, 15, 16, 29, 30, 31, 40, 0xFFFF], 0.9), plant(SPIN + 4, 2, [3, 4]),
         plant(SPIN + 6, 1, [1, 2, 5, 9, 0]), plant(SPIN + 7, 1, [1, 2, 5, 9, 0, 3]), plant(SPIN + 8, 2, [0, 8, 40, 4, 100])]
for _a in ("06034FC4", "06034FF6", "060350AC", "060350CA", "060351A4", "060353A2", "060353C0"):
    case("f" + _a, [], False, SPINS)
# DIVS and its kin store 0x44E at 060FA8B4 when the divisor is 0 (the routine at 060941AA), which divide.c does not
# do, so the divisor 3541C takes from the byte at +7 stays between 1 and 35.
case("f0603541C", [], False, SPINS[:-3] + [plant(SPIN + 7, 1, [1, 2, 5, 9, 3, 35, 20], 1.0), plant(SPIN + 8, 2, [0, 8, 40, 4, 100])])

def brain(off, size, values, chance=0.8):
    return plant(BRAIN + off, size, values, chance)


def bom(off, size, values, chance=0.8):
    return [plant(bomber(k) + off, size, values, chance) for k in (0, 1, 2)]


BRAINS = ([brain(24, 1, [0, 1, 2, 3]), brain(25, 1, [0, 1, 2, 3, 4, 7]), brain(23, 1, [0, 1, 2, 3, 4]), brain(27, 1, [0, 255, 3]),
           brain(28, 1, [0, 1, 2, 3, 5]), brain(29, 1, [0, 1, 2]), brain(30, 1, [0, 1, 2, 3]),
           brain(12, 2, [0, 0x1000, 0x2000, 5, 0xF000]), brain(14, 2, [0, 0x40, 5]), brain(16, 2, [0, 0x10, 0x11, 0x12]), brain(18, 2, [0, 0x10, 0x11, 0x12]),
           plant(0x060C062C, 2, [0, 1, 2, 3]), plant(0x060C04CA, 2, [0, 1, 3, 7, 8, 9]), plant(0x060C04D6, 2, [0, 1, 2, 3]),
           plant(0x060C04A3, 1, [0, 1, 2, 3, 4]), plant(0x060C04CE, 2, [0, 5, 16, 20, 0xFFFF]), plant(0x060C04DC, 2, [0, 1, 0xFFFF]),
           plant(0x060C04E0, 5, [0, 0x0000000000, 0x0100020003, 0x0200000000, 0x0001000000], 0.8)]
          + [plant(0x060C04E0 + k, 1, [0, 0, 1, 2, 5], 0.6) for k in range(5)]
          + [plant(0x060EE8B0 + 2 * k, 2, [0, 0x100, 0x200, 0xF00, 0x800], 0.5) for k in range(0x10, 0x30)]
          + [plant(0x060EC8B0 + 2 * k, 2, [0, 1, 2, 0x20, 0x30, 0xFFFF], 0.5) for k in range(0x10, 0x30)]
          + CUR + OTHER
          + bom(20, 2, [0x10, 0x11, 0x12, 0x20, 0], 0.9) + bom(42, 2, [0, 1]) + bom(46, 2, [0, 2, 0x800, 0x802], 0.9) + bom(36, 2, [0, 1, 2])
          + bom(64, 2, [0, 1, 3, 0x100, 0x101, 5]) + bom(6, 1, [0, 1, 2, 3, 4, 5]) + bom(18, 2, [0xFFFF, 0, 0x40, 0x20])
          + bom(52, 2, [0, 1, 2, 5]) + bom(24, 2, [0, 0, 0, 40, 100, 0xFFF0]) + bom(28, 2, [0, 0, 0, 40, 100, 0xFFF0])
          + bom(62, 2, [0, 10, 20, 0x7FFF], 0.9) + bom(40, 2, [0, 0, 5], 0.9)
          + [plant(0x060B3C88 + 8 * k, 2, [0xFF9C, 0xFFF0], 0.9) for k in range(16)] + [plant(0x060B3C88 + 8 * k + 2, 2, [100, 5, 0x1000], 0.9) for k in range(16)]
          + [plant(0x060B3C88 + 8 * k + 4, 2, [0xFF9C, 0xFFF0], 0.9) for k in range(16)] + [plant(0x060B3C88 + 8 * k + 6, 2, [100, 5, 0x1000], 0.9) for k in range(16)])
for _a in ("060110AC", "06011320", "0601179A", "06011BF0", "06011C50", "06011E62", "06011F26", "0601224A", "06012410", "060124B8",
           "06012638", "060126E4", "06012B3E", "06012B58", "06012B72", "06012C62", "06012EDA", "06013318"):
    case("f" + _a, [pick(BRAIN)], _a in ("060110AC", "06012B3E", "06012B58", "06012C62"), BRAINS)
case("f060116C0", [pick(BRAIN), span(0, 3)], True, BRAINS + [plant(0x060B3C88 + k * 2, 2, [0, 0xFFF0, 20, 0x30, 0xFFD0, 5, 0x100, 0xFF80], 0.9) for k in range(32)])
case("f06012184", [ptr(0x060C2000, 0x100, 2)], True, [plant(0x060B3BB8 + 4 * k, 4, [0, 1, 5, 20], 1.0) for k in range(4)])
case("f0601391E", [pick(BRAIN), pick(0x06012410, 0x06011C16, 0)], False, BRAINS)
case("f06011778", [pick(BRAIN), span(0, 6)], False, BRAINS)
case("f06011B00", [span(0, 3), ptr(0x060C2000, 0x100, 2), ptr(0x060C2100, 0x100, 2), ptr(0x060C2300, 0x100, 2)], True,
     CUR + bom(52, 2, [0, 1, 2, 4, 5], 1.0) + bom(46, 2, [0x800, 0], 1.0) + bom(36, 2, [0, 1, 2], 1.0) + [plant(0x060C2000 + k, 2, [0, 16, 64, 0x20, 0xA0, 7, 0x10, 0x50], 0.5) for k in range(0, 0x100, 2)]
     + [plant(0x060C2100 + k, 2, [0, 0xF00, 0x1000, 0x10], 0.5) for k in range(0, 0x100, 2)]
     + [plant(0x060C2300 + k, 2, [0, 5, 0xAB], 0.5) for k in range(0, 0x100, 2)]
     + [plant(0x060DFB9B + 8 * k, 1, [16, 10, 26, 21, 0, 3], 0.8) for k in range(256)] + [plant(0x060C2300 + k, 2, [0, 1, 2, 3, 0xAB], 0.3) for k in range(0, 0x100, 2)])
case("f06014F68", [span(0, 5), span(0, 3)], True, PAL + [plant(0x060C029C, 1, [8, 0, 1])])
case("f06016812", [], True, PAL + MOVER + CUR + bom(36, 2, [0, 1, 2], 1.0) + bom(22, 2, [3, 4], 1.0) + bom(64, 2, [0, 1, 5, 16], 1.0) + [plant(0x060D7768 + 0x100, 1, [0])] + [plant(0x060C062C, 2, [0, 1, 2, 3], 1.0), plant(0x060C029C, 1, [8, 0, 1])] + [plant(0x060C064A + k, 1, [0, 1, 2, 3], 1.0) for k in range(8)] + [plant(obj(3) + 46, 2, [0, 1, 2], 0.5), plant(obj(4) + 46, 2, [0, 1, 2], 0.5)])

ACT = 0x060C2100            # a record for the pointer at 060D8C08
ACTOR = [plant(0x060D8C08, 4, [ACT], 1.0)]
TASK = [plant(0x060D7E60, 4, [slot(3), slot(4)], 1.0), plant(0x060D7E64, 4, [obj(3), obj(4)], 1.0)]
THIRD = [plant(0x060D8314, 4, [obj(3), obj(4), 0x060C5100, bomber(1)], 1.0), plant(0x060D8318, 4, [0x060C5000], 1.0)]


def act(off, size, values, chance=0.8):
    return plant(ACT + off, size, values, chance)


ACTS = ACTOR + [act(0, 2, [3, 4]), act(4, 2, [0x10, 0x11, 0x20, 0x30]), act(14, 1, [0, 1, 2, 3]), act(15, 1, [0, 1, 5, 9, 0xFF]),
                act(18, 1, [255, 0, 3]), act(19, 1, [0, 1, 2]), act(20, 2, [0, 7, 0x80, 0x100, 0xFF00, 0xFF80]), act(10, 2, [0, 0x20, 0x40, 0x60]),
                act(35, 1, [0, 1, 2, 4])]
CELLS = ([plant(0x060EC8B0 + 2 * k, 2, [0, 1, 0x20, 0x40, 0x42B0, 0x10, 0x30, 0xFFFF], 0.5) for k in range(0x10, 0x40)]
         + [plant(0x060EE8B0 + 2 * k, 2, [0, 0x1000, 0x7000, 0x8000], 0.5) for k in range(0x10, 0x40)]
         + [plant(0x060F08B0 + 2 * k, 2, [0, 0x1, 0x10, 0x1100, 0xFFFF], 0.5) for k in range(0x10, 0x40)])
POS = bom(36, 2, [0, 1, 2]) + bom(22, 2, [3, 4]) + bom(20, 2, [0x10, 0x11, 0x20, 0x30, 0x12]) + bom(52, 2, [0, 1, 2, 4]) + bom(53, 1, [0, 1, 2])

case("f06019BB4", [], False, CUR + MOVER + POS)
case("f06019EDE", [], True, CUR + MOVER + POS + [plant(0x060C062C, 2, [0, 1, 2, 3])])
case("f0601AEC2", [span(0, 11)], False, [plant(0x060D8318, 4, [0x060C5000], 1.0)])
case("f0601AEE2", [], False, [plant(0x060D8318, 4, [0x060C5000], 1.0)])
case("f0601BB8E", [], False, CUR + OTHER)
case("f0601BC58", [], True, CUR + MOVER + PAL + bom(64, 2, [0, 1, 5, 16], 1.0) + [plant(obj(3) + 46, 2, [0, 5, 0x7FF, 0x800]), plant(obj(4) + 46, 2, [0, 5, 0x7FF, 0x800])])
case("f0601BF0C", [span(0, 6)], False, CUR + OTHER + THIRD + bom(22, 2, [3, 4]) + bom(88, 2, [0, 1], 0.5) + bom(4, 2, [3, 4]))
case("f0601C150", [], True, MOVER + THIRD + [plant(obj(3) + 16, 2, [0, 5], 0.7), plant(obj(4) + 16, 2, [0, 5], 0.7), plant(obj(3) + 18, 2, [0, 5], 0.7), plant(obj(4) + 18, 2, [0, 5], 0.7),
                                           plant(obj(3) + 12, 2, [0, 0, 1], 0.7), plant(obj(3) + 14, 2, [0, 0, 1], 0.7), plant(obj(4) + 12, 2, [0, 0, 1], 0.7), plant(obj(4) + 14, 2, [0, 0, 1], 0.7)])
case("f0601C244", [pick(0, 1, 5)], False, OTHER + [plant(0x060C1AAA, 2, [3, 4], 1.0)] + bom(6, 1, [0, 1, 2, 3, 4, 5]))
case("f0601C2C2", [pick(0, 1, 7)], False, OTHER + THIRD + bom(6, 1, [0, 1, 2, 3, 4, 5]) + [plant(obj(3) + 4, 2, [0, 5, 100]), plant(bomber(1) + 4, 2, [0, 5, 100])])
case("f0601C534", [], False, THIRD + CUR + OTHER)
case("f0601C620", [ptr(0x060C5200, 0x100, 4), ptr(0x060C5300, 0x100, 4)], False, CUR + bom(36, 2, [0, 1, 2]) + bom(52, 2, [0, 1, 2, 4]) + bom(76, 2, [0, 4, 12, 40, 0xFFFF]))
case("f0601CF8C", [], False, CUR + OTHER + THIRD + bom(6, 1, [0, 1, 2, 3, 4, 5]) + bom(52, 2, [0, 1, 2, 4]) + [plant(0x060C5000, 2, [0, 5, 0x30]), plant(0x060C5000 + 24, 1, [0, 1, 3, 6, 0x90, 0x7F])]
     + [plant(0x060B47B8 + k, 1, [0, 1, 3, 6, 0xF0, 0x7F, 0x80], 0.7) for k in range(0, 48)])
case("f0601D5EC", [span(0, 0), pick(0x40, 0x41, 0x50, 0x80, 0xC0, 0x60, 0x90, 0xA0), pick(0x060C5200)], False,
     CUR + OTHER + bom(6, 1, [1, 2, 3, 4]) + [plant(0x060C5200 + 68, 2, [0x13F, 0x140, 0x200, 0])]
     + [plant(0x060EC8B0 + 2 * k, 2, [0, 0x20, 0x10, 0x30, 0x1], 0.6) for k in range(0x20, 0x200)]
     + [plant(0x060F08B0 + 2 * k, 2, [0, 0x1, 0x10, 0xFF], 0.6) for k in range(0x20, 0x200)] + bom(20, 2, [0x40, 0x41, 0x50, 0x80, 0xC0]) + [plant(0x060D849C + 7, 1, [0], 1.0)])
case("f0601E300", [span(0, 1), span(0, 100), pick(0, 1, 5, 6)], False, [plant(0x060DF988, 4, [0x060C5000]), plant(0x060DF98C, 4, [0x060C6000])] + TILES + CELLS)
case("f0601E336", [pick(0, 1, 5), span(0, 100), pick(0, 1, 2, 16, 17, 0x8, 3)], False,
     ACTS + [plant(0x060DF988, 4, [0x060C5000]), plant(0x060DF98C, 4, [0x060C6000])] + TILES + CELLS + [plant(0x060F08B0 + 2 * k, 2, [0, 0x100, 0x200, 0x1234], 0.6) for k in range(0, 100)])
case("f0601F578", [], True, ACTS + [plant(0x060D7E8C, 2, [0x10, 0x11, 0x20, 0x30])] + CELLS)
case("f0602109C", [pick(0, 1, 4, 0x80)], False, ACTS + [plant(0x060C063D, 1, [0, 3, 5, 9, 0xFF])])
case("f060210B6", [], False, ACTS)
case("f060210E8", [], False, ACTS)
case("f06021588", [span(0, 255)], True, ACTS)
case("f06021980", [pick(0, 5, 0x7F, 0x80, 0xFF), span(0, 63), span(0, 63), span(0, 31)], True, [])
case("f06022044", [span(0, 0x3F)], False, CELLS + TILES + MAP[:64])
case("f06022B0A", [span(0, 0x3F)], False, TILES + MAP[:64])
case("f0602566C", [pick(0, 1, 2, 5)], False, TASK + TILES + [plant(0x060C02C2, 2, [0, 0x10, 0x11, 0x20]), plant(0x060C02C0, 1, [0, 2, 4, 8])]
     + [plant(0x060C02C2 + 2 * k, 2, [0x10, 0x11, 0x20, 0x30]) for k in range(4)])
case("f06025FC0", [pick(0, 1, 2, 5)], False, TASK + TILES)
case("f060269A4", [], False, CUR + MOVER + bom(44, 2, [0, 1, 2, 3]) + bom(66, 2, [0, 0, 1]) + bom(36, 2, [3, 4], 1.0) + bom(22, 2, [3, 4], 1.0) + bom(4, 1, [0, 1, 2]) + bom(6, 1, [1, 2, 3, 4]))
case("f0602781C", [pick(0x060C5000), pick(0x060C5100), span(-2, 300)], False,
     [plant(0x060C5000, 4, [0, 1, 50, 200, 7]), plant(0x060C5100, 4, [10, 50, 100, 1000], 0.7), plant(0x060C5108, 4, [30, 150, 1000, 5000], 0.7), plant(0x060C5110, 4, [100, 5000, 100000], 0.9),
      plant(0x060C5118, 4, [0x7FFFFFFF], 1.0)])

# 06008ACC and 06008ADC reach a list through the pointers at 060BD8D8; every list the ids 238 to 623 name is empty or one entry
LISTS = ([plant(0x060C4020, 4, [0x060C2700], 1.0), plant(0x060C2704, 4, [0x060C2780], 1.0)]
         + [plant(0x060C2780 + 4 * (n - 1), 4, [0x060C3F00, 0x060C3F10], 1.0) for n in range(1, 700)] + [plant(0x060BD8D4, 4, [0x060C4000], 1.0)]
         + [plant(0x060FBFFC, 4, [0x060C5000], 1.0), plant(0x060C5000, 4, [0, 0x060C5010], 1.0), plant(0x060C5010, 4, [0], 1.0), plant(0x060FBF84, 4, [0x060C5800], 1.0), plant(0x060C3F00, 2, [0xFFFF], 1.0), plant(0x060C3F10, 2, [0xFFFF], 1.0)])
case("f060329A0", [], True, LISTS)

# a bomber that stands still on an open cell, with the other one inside the first of the four boxes
WALK = (CUR + bom(20, 2, [0x10], 1.0) + bom(64, 2, [0x300, 0x100, 0x200], 1.0) + bom(62, 2, [10], 1.0) + bom(40, 2, [0], 1.0)
        + bom(42, 2, [0], 1.0) + bom(46, 2, [0], 1.0) + bom(24, 2, [0], 1.0) + bom(28, 2, [0], 1.0)
        + [plant(0x060B3C88 + 2 * k, 2, [0xFF9C if k % 2 == 0 else 100], 0.8) for k in range(16)]
        + [plant(0x060EE8B0 + 2 * k, 2, [0], 1.0) for k in range(0x80)]
        + [plant(0x060EC8B0 + 2 * k, 2, [0], 0.8) for k in range(0x80)]
        + [brain(24, 1, [1], 0.9), plant(0x060C062C, 2, [0], 0.9), plant(0x060C04DC, 2, [1], 0.5)])
case("f06012C0C", [pick(BRAIN)], True, BRAINS + WALK)
case("f06012FB8", [pick(BRAIN)], True, BRAINS + WALK)
case("f06020174", [span(-3, 40), pick(0), pick(0, 1, 2, 3, 0x1FF)], False, ACTS)
case("f060201A0", [span(0, 40)], False, ACTS + CUR + bom(6, 1, [0, 1, 2, 3, 4]) + bom(20, 2, [0x10, 0x20]) + bom(24, 2, [0, 100, 0x200, 0xFF00]) + bom(28, 2, [0, 100, 0x200, 0xFF00]))
