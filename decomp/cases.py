"""The arguments and data each decompiled function is checked with, where check.py's defaults do not
reach all of its branches.

A case is (arguments, whether it returns a value, plants). Each argument is drawn from one of the
forms below, and each plant writes one of its values over the memory at an address, in a share of the
trials, so that the branches random bytes almost never take run as well. Cases written by a batch of
workers go in a file of their own under planted/, which load() runs, so each keeps its own helpers.
"""
import functools
import glob
import os
import runpy

PLANTED = os.path.join(os.path.dirname(os.path.abspath(__file__)), "planted")

# A pointer argument whose target the plants can name.
FIX = 0x060C0100

SPEC: dict[str, tuple[list[tuple], bool, list[tuple]]] = {}


def bomber(i: int) -> int:
    return 0x060D5F30 + 124 * i


def cell(k: int) -> int:
    return 0x060C1F42 + 12 * k


def ent(k: int) -> int:
    return 0x060EC478 + 24 * k


@functools.cache
def load() -> None:
    for path in sorted(glob.glob(os.path.join(PLANTED, "*.py"))):
        runpy.run_path(path)


def obj(i: int) -> int:
    return 0x060C381C + 84 * i


def slot(k: int) -> int:
    return 0x060D7B48 + 24 * k


def case(name: str, args: list[tuple], returns: bool, plants: list[tuple] = ()) -> None:
    if name in SPEC:
        raise ValueError("%s has two cases" % name)
    SPEC[name] = (args, returns, list(plants))


def objs(offset: int, values: list[int], ids: tuple[int, ...] = (3, 4), chance: float = 0.9) -> list[tuple]:
    """The halfword at offset in each of the 84-byte objects ids."""
    return [plant(obj(i) + offset, 2, values, chance) for i in ids]


def pick(*values: int) -> tuple:
    return ("pick", list(values))


def plant(address: int, size: int, values: list[int], chance: float = 0.6) -> tuple:
    return (address, size, values, chance)


def ptr(lo: int, span: int, align: int = 4) -> tuple:
    return ("ptr", lo, span, align)


def span(lo: int, hi: int) -> tuple:
    return ("int", lo, hi)


case("f0600665C", [], False)
case("f06006B38", [span(0, 200)], False)
case("f0600940A", [span(0, 200)], False)
case("f0600942E", [], False)
case("f0600A3E0", [ptr(0x060C0000, 0x100), ptr(0x060C1000, 0x100, 1), span(-40000, 40000)], False)
case("f0600A4B0", [span(0, 0xFFFF)], True)
case("f0600B934", [span(0, 1000), span(0, 1000)], True)
case("f0600A25E", [span(-(1 << 31), (1 << 31) - 1)], False)
case("f0600A2D8", [span(-(1 << 31), (1 << 31) - 1)], False)
case("f060A5EEC", [ptr(0x060C0000, 0x400)], True)
case("f060075D4", [pick(FIX), pick(*[ord(c) for c in "lh-0123456789/:"], 0x80, 0xFF, 0x180 + ord("h"))], True,
    [plant(FIX + 20, 4, [0, 0, 5, 12345]), plant(FIX + 25, 2, [0, 0xFFFF])])
case("f0600794E", [pick(FIX), span(0, 300)], True, [plant(FIX + 24, 1, [0, 0x81, 0x40])])
case("f06006DC8", [span(-2, 20)], True, [plant(0x060BC190 + 88 * k + 80, 1, [1, 1, 2, 0]) for k in range(18)])
case("f0600B8F0", [], True, [plant(0x060BF5EA, 2, [0, 1, 7]), plant(0x060C02AA, 2, [100]), plant(0x060C1000, 4, [100, 90, 2000]),
                            plant(0x060060AE, 2, [0, 0xE00, 0x200, 0x1000]), plant(0x060D7E68, 2, [0, 0x40, 0x440, 0x3F])])
case("f06013C24", [span(-1, 24)], True, [plant(0x060C051C, 4, [0, 0, 1]), plant(0x060D7E68, 2, [0, 0, 0x40]),
                                       plant(0x060C0510, 4, [0x060C2000]), plant(0x060C050C, 4, [5, 0x060C2100])]
    + [plant(0x060B41FC + 4 * k, 4, [k, 3, -1, 8], 0.8) for k in range(20)])
case("f0600CFC6", [span(-50, 4000), span(-50, 4000)], False, [plant(0x060C029C, 1, [17, 0, 3])])
case("f0600D3D4", [span(0, 63), pick(0, 1, 5, 0x8000, 0xFFFF, 0x12345)], False, [plant(0x06006160, 4, [0x0600CE24, 0, 1])])
case("f06011F1A", [pick(FIX)], True, [plant(FIX + 18, 2, [0, 0, 5, 0xFFF0]), plant(0x060D7768, 4, [0x060C2000])])
case("f060161B0", [span(0, 3)], True,
    [plant(0x060C063D, 1, [0, 1, 2, 3, 5]), plant(0x060C062C, 2, [0, 1, 2, 3, 4])]
    + sum([[plant(bomber(i) + 4, 1, [0, 0, 0x40, 0x80, 0xC0]), plant(bomber(i) + 46, 2, [0x100, 0x100, 0, 0x300]),
            plant(bomber(i) + 74, 2, [0, 1, 2, 3, 4]), plant(bomber(i) + 62, 2, [3, 0x7FFF]), plant(bomber(i) + 52, 2, [9, 0x8000])]
           for i in range(6)], [])
    + [plant(0x060D7768, 4, [bomber(0), bomber(2), 0x060C2000])])
case("f060174EC", [pick(FIX)], True,
    [plant(0x060C063D, 1, [0, 1, 2, 3, 5, 9]), plant(0x060C062C, 2, [0, 1, 2, 3, 4])]
    + sum([[plant(bomber(i) + 4, 1, [0, 0, 0x40, 0x80]), plant(bomber(i) + 46, 2, [0, 0, 0x33D, 0x100, 0x2])] for i in range(10)], []))
case("f0601079E", [span(-1, 8), pick(0, 1, 5, 9, 10, 11, 20)], True,
    [plant(0x060C063D, 1, [0, 1, 2, 4, 7, 9]), plant(0x060C064A, 10, [0x0809080B0A0B0809080B], 0.3)]
    + [plant(0x060C064A + i, 1, [8, 9, 11, 0, 3], 0.7) for i in range(10)]
    + [plant(bomber(i) + 4, 1, [0, 0, 0x80, 0x7F]) for i in range(10)])
case("f06024752", [span(0, 4000)], True, [plant(0x060EE8B0 + 2 * c, 2, [13, 0x10D, 0x0E], 0.3) for c in range(4000)]
    + [plant(0x060D7E7E, 2, [0, 3, 10, 30, 60]), plant(0x060D7E82, 2, [0, 1, 2, 40, 50, 70])])
case("f060273F4", [span(-3, 9)], True, [plant(0x060D7E8C, 2, [0xFFFF, 0, 1, 2, 3, 9]), plant(0x060C062C, 2, [0, 1, 2, 3, 9])]
    + [plant(0x060C0640 + i, 1, [0, 4, 8, 12, 28, 0x1C, 0xFF], 0.9) for i in range(10)])
case("f06028E94", [], False,
    [plant(0x060C02A0, 1, [0, 1, 2, 3, 3, 4]), plant(0x060C02A2, 1, [0, 0, 1, 2]), plant(0x060D7CB8, 2, [7], 1.0),
     plant(obj(7) + 16, 2, [0, 100, 150, 300, 0xFFE0]), plant(obj(7) + 18, 2, [0, 40, 60, 90, 0xFFF0])]
    + [plant(0x060B5010 + 2 * i, 2, [0, 40, 80, 100, 150, 200, 320, 0xFFF0], 0.9) for i in range(24)])
case("f0602B976", [span(-2, 12)], True, [plant(0x060C0640 + i, 1, [0, 1, 4, 8, 2], 0.9) for i in range(12)])
case("f0602B9EC", [], True, [plant(0x06006134 + i, 1, [0, 0, 1], 0.9) for i in range(10)])
case("f0602E88E", [], True, [plant(0x06006134 + i, 1, [0, 0, 0, 1], 0.9) for i in range(10)]
    + [plant(0x06006096 + 2 * i, 2, [0x70, 0x71, 0xFFFF, 0x30, 0], 0.7) for i in range(10)])
case("f0602E656", [pick(0, 1, 9999, 10000, 10001, 29999, 30000, 30001, 49999, 50000, 70000, 123456, 1000000)], True)
case("f0602ED18", [span(-5, 5000)], False, [plant(0x060C1004, 1, [1, 0, 3, 1])])
case("f0603110C", [pick(FIX), pick(0, 1, 2, 3, 4, 0x10001)], False,
    [plant(FIX + i, 1, [15, 0, 14, 1, 255], 0.5) for i in range(260)])
case("f06031AE2", [pick(0, 0x1111, 0x2222, 0x3333, 0x4444)], True,
    [plant(0x060C1244, 1, [0, 1, 2, 3, 5, 8])]
    + sum([[plant(0x060C104C + 16 * k + 1, 1, [0, 1, 2, 3, 4, 5, 6, 7]), plant(0x060C104C + 16 * k + 4, 4, [0x1111, 0x2222, 0x3333, 7])]
            for k in range(8)], []))
case("f06032F6E", [span(-3, 12)], True, [plant(0x060C063C, 1, [0, 1, 5]), plant(0x060C063F, 1, [0, 1, 4, 9, 2, 3, 2, 3, 2, 3]),
                                       plant(0x060C1048, 4, [0x400, 0x400, 0x400, 0, 0x800, 0xC00])]
    + [plant(0x060C0640 + i, 1, [0, 1, 2, 3, 4, 5, 6, 7, 0x84, 0x85, 0x87], 0.9) for i in range(10)])
case("f06033BD6", [pick(0, 1, 0x100, 0x1FF)], False,
    [plant(0x060C122C, 1, [0, 1, 2, 3])] + [plant(0x060EC47A + 24 * k, 2, [1, 0, 2], 0.7) for k in range(4)])
case("f06033380", [], True, [plant(0x060C1048, 4, [0x1000, 0, 0x3000, 0x2000, 0xFFFFFFFF]), plant(0x060C1234, 4, [0, 0x55555, 0xFFFFF, 0x0F0F0, 0xAAAAA])]
    + [plant(0x060C0640 + i, 1, [0, 1, 2, 3, 0xFC, 0xFD], 0.8) for i in range(10)])
case("f060342F8", [pick(FIX)], True, [plant(FIX + 44, 4, [0, 0, 1, 7, 6]), plant(FIX, 4, [0x060C2000]), plant(FIX + 32, 4, [0, 0xFFFFFF81, 0x55])])
case("f06035E18", [pick(0, 5, 29, 30, 40, 0x10000), pick(0, 0x00100000, 0x00200000, 0x01000000, 0x02000000, 7, 0x03000000)], False,
    [plant(ent(k) + 12, 4, [-1, 0x12345678, 0, 0x03000000], 0.7) for k in (0, 5, 29)])
case("f06036AD2", [pick(0, 3, 5, 29)], True,
    [plant(ent(k) + 12, 4, [-1, 0, 0x40, 0x02000000, 0x02000040, 0x80000000, 0x800, 0x01000000, 0x03000000, 0x840], 0.9) for k in range(30)]
    + [plant(ent(k), 2, [1, 2], 0.9) for k in range(30)] + [plant(ent(k) + 4, 2, [1, 2], 0.9) for k in (0, 3, 5, 29)])
case("f0603796C", [pick(0, 1, 2, 0x10001)], False,
    [plant(ent(k) + 12, 4, [-1, 0x20000000, 0, 0xFFFFFFF0], 0.8) for k in range(30)] + [plant(ent(k), 2, [1, 2], 0.7) for k in range(30)])
case("f0603BBD6", [], True, [plant(0x060D7E30, 4, [0x0603DDA6, 0, 0x0603DDA6])])
case("f0601DDEA", [], True, [plant(0x060D84E8 + 38 * k + 16, 1, [1] * 20 + [0], 1.0) for k in range(50)]
    + [plant(0x060D7E8C, 2, [0, 1, 2, 0xFFF0])] + [plant(0x060EC8B0 + 2 * i, 2, [0, 0x42F0, 1, 0x8000], 0.7) for i in range(3)])
case("f06021562", [], True, [plant(0x060DFA14, 1, [0, 126, 127, 255, 128, 5])])
case("f0601123A", [span(-3, 6)], True, [plant(0x060D7EB4, 2, [3, 7, 0xFFFF]), plant(0x060D7E88, 2, [3, 7, 0xFFFF]),
                                       plant(0x060C04DC, 2, [0, 0xFFFF, 1])] + [plant(0x060EC8B0 + 2 * i, 2, [0, 1, 0xFFFF], 0.7) for i in range(12)])
case("f0601486E", [span(-3, 8), span(0, 3)], False,
    [plant(bomber(i) + 6, 1, [4, 0, 4, 2]) for i in range(4)] + [plant(bomber(i) + 22, 2, [0, 1, 5, 2]) for i in range(4)])
case("f0601628E", [pick(0, 1, 2, 7)], False, [plant(bomber(i) + 46, 2, [0, 0x800, 0x400, 0x1, 0x7F0, 0xFFFF], 0.9) for i in range(3)])
case("f0602D7C0", [pick(0, 1, 2, 300)], False,
    [plant(0x060E20EB + k * 14, 1, [0, 1, 0xFF, 2, 0xFE, 5, 0xFB, 0x7F, 0x80], 0.9) for k in range(4)]
    + [plant(0x060C0FBE, 2, [0, 1, 0xFFFF, 3, 0x80, 0xFFFD, 255, 256, 0x7FFF])])
case("f0603A614", [pick(0, 5, 0x1234), pick(0, 1, 2, 3, 4, 5, -1), pick(0, 1, -1, 300, 32767, -32768)], False)
case("f0603AAD2", [pick(1, 2), pick(3, 4), pick(5, 6)], False, [plant(0x060C1728 + 2 * i, 2, [0, 1, 0xFFFF, 0], 0.8) for i in range(2)])
case("f0603D16C", [pick(3), span(-2, 8), pick(0, 0, 1)], True,
    [plant(obj(3) + 16, 2, [0, 5, 100]), plant(obj(3) + 18, 2, [0, 0, 0, 5, 60, 0xFFF0]), plant(obj(3) + 26, 2, [7, 23, 39, 55, 12, 3, 0, 5, 40, 61, 100])])
case("f0603D314", [], False, [plant(0x060D7E14, 2, [0, 255, 3, 0xFFFF])])
case("f0602A750", [], False)
case("f0603EE1E", [span(0, 5)], True, [plant(slot(k) + 8, 2, [3, 4]) for k in range(6)] + objs(10, [0, 1, 5]) + objs(60, [0xFF00, 0xFFFF, 0xFEFF, 0, 5]))
case("f0603F380", [span(0, 5)], True, [plant(slot(k) + 8, 2, [3, 4]) for k in range(6)])
case("f0604B4CC", [span(-2, 6), pick(FIX)], True,
    [plant(FIX + 20 + 2 * k, 2, [3, 4], 1.0) for k in range(-2, 7)] + objs(16, [0, 100, 160, 161, 0x153, 0x154, 0x155, 0xFFEB, 0xFFEC, 0xFFED, 0xFF00]))
case("f0604D47C", [pick(0, 1, 2, 3, -1, 5), pick(0, 1, 2, 3, 9)], True,
    [plant(0x060B69CC + 4 * k, 4, [0x00010002, 0x00030004, 0x00020003, 0xFFFF0000, 0x00000000, 0x00010003], 0.85) for k in range(8)])
case("f0604D590", [], True, [plant(0x060BF5EA, 2, [0, 0, 5]), plant(0x060C179C, 1, [0, 1, 2, 3]), plant(0x060C179D, 1, [0, 1, 2, 3]),
                            plant(0x060C029C, 1, [0, 1, 2, 3]), plant(0x060C029D, 1, [0, 1, 2, 3])])
case("f0604D898", [], True, [plant(0x060C179A, 1, [0, 0, 1]), plant(0x060C179B, 1, [0, 0, 2])])
case("f0604D922", [pick(-1, 0, 1, 2, 3, 5, 0x10002)], True, [plant(0x060C179A, 1, [0, 1, 2, 3])])
case("f0604EA00", [pick(FIX), pick(0, 7), span(-1, 5), span(-1, 5)], False,
    [plant(FIX + 20 + 2 * k, 2, [3 + k], 1.0) for k in range(5)]
    + [plant(obj(3 + k) + 68, 2, [0x10, 0x40, 0xE0, 0x100, 0x101, 0x1E0, 0x1FF, 0x200, 0x201, 0x7FFF, 0xFFFF], 0.95) for k in range(5)])
case("f06050C8C", [], True, [plant(0x060C17B6, 1, [255, 0, 1])])
case("f06050CB0", [], True, [plant(0x060C1844 + k, 1, [5, 5, 0, 1]) for k in range(3)])
case("f06051D88", [pick(0, 16, 32, 64, 48, 0x10040, 0x20, 0x8010, 80), span(0, 5), span(0, 3)], True, [plant(0x060D7E68, 2, [0, 0, 0x20, 0x1, 0x21, 0x40])])
case("f06051E1C", [pick(0, 16, 32, 64, 0x10000, 0x10010, 0x20, 80), span(-3, 6), span(-3, 6)], True)
case("f06051E4C", [span(-2, 4), span(0, 3)], False, [plant(0x060C18CC, 1, [2, 2, 0, 1])])
case("f0605650C", [pick(0, 1, -1, 0x100, 0x80, 0x7F)], False,
    [plant(0x060C122C, 1, [0, 1, 5, 29])] + [plant(ent(k) + 2, 2, [1, 2, 3, 4, 5, 6, 7, 0, 9], 0.9) for k in range(30)])
case("f06059E62", [pick(0, 1, 2, 255, 257)], True, [plant(0x060C0AA8, 4, [2, 0, 1])])
case("f0605B094", [span(0, 9)], True,
    [plant(0x060C1905 + k, 1, [0, 0, 1, 2, 5, 20, 100, 255], 0.8) for k in range(8)] + [plant(0x060060CA, 2, [0x8000, 0x4000, 0xC000, 0, 0x8001])])
case("f0605B0F8", [], True, [plant(0x060C190D, 1, [0, 1, 98, 99, 100, 101, 200, 255]), plant(0x060060CA, 2, [0x8000, 0x4000, 0xC000, 0, 0x8001])])
case("f0606268A", [], True, [plant(0x060D7BB0, 2, [3], 1.0), plant(0x060D7BBA, 2, [0x1234, 7]), plant(obj(3) + 36, 2, [0x1234, 7, 0], 0.9),
                            plant(0x060D7BBC, 2, [0x55, 8]), plant(obj(3) + 38, 2, [0x55, 8, 9], 0.9)])
case("f060647BA", [span(-1, 8), span(0, 3)], True, [plant(0x060EC8B0 + 2 * k, 2, [0, 1, 2, 3, 7, 15, 0x1F8], 0.95) for k in range(4)])
case("f06064D12", [], False, [plant(0x060D7BE6, 2, [128, 128, 0, 5])])
case("f06066EF4", [], True, [plant(0x06006038, 4, [0, 8, 16, 1, 7])])
case("f060694B8", [], True, [plant(0x060C1AA8, 2, [3, 4], 1.0)] + objs(18, [0xFFF0, 0, 0x1CB, 0x1CC, 0x1CD, 5, 0x1E0]))
case("f0606B9DE", [span(0, 5)], True,
    [plant(bomber(k) + 4, 1, [0, 0, 0x20, 0x80, 0xE0, 0x1F], 0.9) for k in range(6)] + [plant(cell(k) + o, 2, [0, 3, 7, 8, 9], 0.9) for k in range(6) for o in (4, 6)])
case("f0606BAF6", [], True, [plant(0x060C029C, 1, [8, 0, 1]), plant(bomber(1) + 4, 1, [0, 0x80]), plant(bomber(0) + 4, 1, [0, 0x80])]
    + [plant(a, 2, [0, 1, 5, 9, 0xFFFF]) for a in (0x060C1F4A, 0x060C1F4C, 0x060C1F56, 0x060C1F58)])
case("f0606BCDE", [span(0, 5), pick(0, 3, 5, 8, 0x10000, -1), pick(0, 3, 5, 8, 0x10000, -1)], True, [plant(cell(k) + o, 2, [0, 3, 5, 8], 0.9) for k in range(6) for o in (8, 10)])
case("f0606BD32", [span(0, 5)], True, [plant(cell(k) + 10, 2, [0, 0, 1], 0.9) for k in range(6)] + [plant(cell(k) + 8, 2, [0, 1, 2, 3, 4], 0.9) for k in range(6)])
case("f0606BEE2", [span(0, 5)], True, [plant(cell(k) + 10, 2, [0, 1], 0.9) for k in range(6)])
case("f0606C268", [span(0, 5)], True, [plant(bomber(k) + 6, 1, [0, 1, 2, 3, 4, 5, 255], 0.95) for k in range(6)])
case("f0608A9D4", [pick(0, 0x1234, 0x11234, 5), pick(0, 1, 2, 3)], True, [plant(0x060C2EFE, 2, [0x1234, 0, 5])])
case("f06097B92", [pick(FIX), pick(0, 1, 5, 0xFFFFFFFF, 0x80000000, 100)], True, [plant(FIX, 4, [0, 5, 6, 0xFFFFFFFF, 0x80000000])])
case("f0609B750", [pick(0, 1, 2, 3, -1, 0x100000000)], False, [plant(0x060BB8FC, 2, [0, 1, 5])])
case("f0609D96C", [pick(0xFFFF, 0xFFFE, 0, 1, 2, 0x8000, 0x8001, 0x7FFF, 0x8002, 5)], False, [plant(0x060FBF72, 2, [0, 1, 0x10])])
case("f060A0706", [pick(FIX)], True, [plant(FIX + 2 * k, 2, [0xFFFF, 0, 5], 0.8) for k in range(5)])
case("f060A8D0C", [pick(1, 2, 4, 8, 16, 32, 128, 256, 0x40000, 0, 3, 64, -1)], True)
case("f060ABD4E", [span(0, 5)], True, [plant(0x060BB98C, 4, [0xFFFFFFFF, 0, 1, 2])] + [plant(0x060BBA9C + 4 * k, 4, [0, 1, 2, 3, 0xF0]) for k in range(6)])
case("f060AD6D6", [pick(0, 1, 2, 3, 4, 5, 0x100, 0x101), pick(0, 3, 4, 5, 8, 0x100)], True)
case("f060B0090", [ptr(0x060C0100, 0x40, 2), pick(0, 1, 0xFFFF, 0x12345), span(-2, 12)], False)
case("f060B00BC", [ptr(0x060C0100, 0x40, 4), ptr(0x060C0100, 0x40, 4), span(-2, 12)], False)
case("f060B00D6", [ptr(0x060C0100, 0x40, 1), ptr(0x060C0100, 0x40, 1), span(-2, 12)], False)
case("f060B010A", [ptr(0x060C0100, 0x40, 4), ptr(0x060C0100, 0x40, 4), span(-2, 12)], False)
case("f06029E0C", [pick(0, 5, 0x1F), pick(-5, 0, 1, 255, 256, 511, 0x1FF, 0x200, 0x300, 0x7FFFFFFF, -0x80000000)], False)
case("f0603DEEC", [], True, [plant(0x060D7E68, 2, [0, 1, 2, 3], 1.0), plant(0x060D7E60, 4, [0x060C2000], 0.9)])
case("f0603E888", [span(30, 42), span(17, 27)], True)
case("f0603E9B6", [], True, [plant(0x060DF97A, 2, [0, 1, 0x8000, 0x100])])
case("f06043BFC", [pick(0, 1, 2, 3, 0x10000, 0x10001, 0x2AAB)], True,
    [plant(0x060D7B5C + 24 * k, 2, [0, 0, 5, 0xFFFF], 0.7) for k in range(4)] + [plant(0x060D7B5C + 24 * 0x2AAB % 65536, 2, [0])])
case("f060482A6", [pick(0, 4, 5, 6, 0x10005, 0xFFFF0004), pick(0, 5, 6, 7, 0x10006, 0xFFFF0005)], True)
case("f06049694", [pick(0, 1, 0x100, 0x80, 0xFF)], False, [plant(0x060C122C, 1, [0, 1, 2, 3, 29, 200, 255])])
case("f0604D5D4", [pick(5, 0x10005), pick(3, 0xFFFF, 0x10003), pick(5, 6, 0x10005), pick(4, 3, 0x10004, 0)], True,
    [plant(0x060BF5EA, 2, [0, 0, 1]), plant(0x060C179C, 1, [4, 5, 6, 0]), plant(0x060C179D, 1, [0, 3, 4, 5, 8, 9, 15, 0xF0])])
case("f0604D644", [pick(0x10, 0x10010, 0, 255, 0x1FF), pick(3, 4, 0x10000, 0xFFFF)], True,
    [plant(0x060C029E, 1, [0x0F, 0x10, 0x11, 0, 255]), plant(0x060C029F, 1, [2, 3, 4, 5, 0, 255])])
case("f060504B8", [], True, [plant(0x060C1844 + i, 1, [5, 6, 6, 0, 255], 0.9) for i in range(3)])
case("f060504E2", [], True, [plant(0x060C1844 + i, 1, [5, 6, 6, 0, 255, 7], 0.9) for i in range(3)])
case("f06050594", [], True, [plant(0x060C17B6, 1, [255, 0, 254])])
case("f060506B4", [pick(0, 1, 2, 0x10000, 0x10001, 0xFFFF)], True)
case("f06056FA4", [pick(0, 4, 5, 6, 0x10005, 0xFFFF0004)], True, [plant(0x060C0640 + i, 1, [0, 1, 4, 8, 0xFC, 3], 0.7) for i in range(10)])
case("f06058274", [], False, [plant(0x060E1A98 + i, 1, [255, 0x80, 0x7F, 0x81, 0xFF, 0x05, 0xEF], 0.8) for i in range(10)])
case("f06059040", [], True, [plant(0x06006135, 1, [0, 1, 5]), plant(0x060C0AA8, 4, [2, 2, 3, 0]), plant(0x06006137, 1, [0, 1])])
case("f06059EAC", [], True, [plant(0x060C18E2, 1, [128, 129, 0, 130], 0.9), plant(0x060C18E3, 1, [128, 129, 0, 130], 0.9)])
case("f06059F0E", [], True, [plant(0x060C18E2, 1, [128, 129, 0, 130], 0.9), plant(0x060C18E3, 1, [128, 129, 0, 130], 0.9)])
case("f0605A556", [pick(0, 1, 0x10000, 0xFFFF, 0x8000)], False,
    [plant(0x060C1048, 4, [0x2000, 0x1000, 0x3000, 0, 0x12000])])
case("f0605AEE8", [pick(0, 1, 0x10000, 0xFFFF, 0x8000)], False)
case("f0605B570", [pick(0, 1, 0x100, 0x1FF, 2)], True, [plant(0x060C1048, 4, [0x10, 0, 0x30, 0x11, 0x20, 0x1F])])
case("f0605B5C6", [pick(0, 1, 0x100, 0x1FF, 2)], False, [plant(0x060C1048, 4, [0x10, 0, 0x30])])
case("f0605E592", [span(-2, 0x1010)], False, [plant(0x060EE8B0 + 2 * i, 2, [13, 0x1D, 0x0D0D, 12, 14], 0.5) for i in range(0, 0x1001)])
case("f0605EC1E", [pick(FIX, 0x060C0200), span(-2, 10)], False, [plant(0x060D7E60, 4, [0x060C2000], 1.0)])
case("f0605FBF0", [span(0, 20), pick(0, 1, 2, 3, 4, 5, 0x10000, 0x10001, 0x20003, -1, 0x7FFFFFFF)], True,
    [plant(0x060EE8B0 + 2 * i, 2, [0, 1, 2, 3, 4, 5, 0x101, 0x201, 0x300, 0x1004], 0.9) for i in range(21)])
case("f06062168", [], True, [plant(0x060D7C94, 2, [255, 0, 0x100, 0xFF])])
case("f060622A4", [], True, [plant(0x060D7B98, 2, [3, 0, 7, 0x1003]), plant(obj(3) + 60, 2, [0xFF00, 0xFFFF, 0, 0xFEFF, 0xFF01]),
                            plant(obj(7) + 60, 2, [0xFF00, 0xFEFF]), plant(obj(0) + 60, 2, [0xFF00, 0xFEFF]), plant(obj(0x1003) + 60, 2, [0xFF00, 0])])
case("f06065F18", [], True, [plant(0x060D7B78, 4, [0x0603DDA6, 0, 0x0603DDA7])])
case("f0606B060", [pick(49, 50, 51, 52, 146, 147, 148, 0, -50, 0x132)], True)
case("f0606B300", [], False, [plant(bomber(k) + 22, 2, [0, 1, 0xFFFF], 0.8) for k in range(10, 50)]
    + [plant(bomber(k) + 42, 2, [0, 0x200, 0x201, 0x1FF], 0.8) for k in range(10, 50)])
case("f0606BCD8", [pick(0, 1, 2, 3, 0x7F, -1)], True,
    [plant(0x060C1F42 + 12 * k + o, 2, [0, 1, 2, 3, 4, 0xFFFF], 0.8) for k in (0, 1, 2, 3) for o in (8, 10)])
case("f0606BF00", [pick(0, 1, 2, 3, 0x7F, -1)], True, [plant(0x060C1F42 + 12 * k + 8, 2, [0, 0, 1, 0x8000], 0.8) for k in (0, 1, 2, 3)])
case("f0606BF6C", [pick(0, 1, 2, 3, 0x7F, -1)], True, [plant(0x060C1F44 + 12 * k, 2, [0, 15, 16, 17, 0xFFFF, 0x8000], 0.8) for k in (0, 1, 2, 3)])
case("f0606C82C", [span(-1, 0x1010), pick(0, 1, 0x8000, 0xF0F0, 0x12345)], False,
    [plant(0x060C1E42, 2, [0, 1, 0x8000])])
case("f0606D208", [], False, [plant(0x060C1E3A, 2, [0, 0, 1]), plant(0x060D7768, 4, [0x060C2000]),
                              plant(0x060C2000 + 60, 2, [0, 1, 5, 0xFFFF]), plant(0x060C2000 + 62, 2, [0, 1, 5, 0xFFFF])])
case("f0607123A", [pick(0, 1, 2, 7)], True, [plant(bomber(0) + 46 - 48 + 48 + 124 * 0, 2, [0, 0x800], 0.5)])
case("f06088C7E", [], True, [plant(0x060C2ED6, 2, [1, 2, 3, 4, 0, 9], 1.0)]
    + [plant(0x060C2EC0 + o, 4, [5, 6, 0xFFFFFFFF, 0x80000000, 0], 0.9) for o in (0, 4, 8, 12)])
case("f0608ADDE", [span(-1, 20)], False, [plant(bomber(n) + 22, 2, [0, 1, 7, 0xFFFF], 0.9) for n in range(0, 21)])
case("f0608AF28", [pick(0, 1, 2, 0x10000, 0x10001, 300), pick(0, 1, -1, 0x7FFF, 0x8000, 12345)], False)
case("f060949D0", [pick(0, 1, -1, 5, -5, 0x7FFFFFFF, -0x80000000, -0x7FFFFFFF)], True)
case("f06097B7C", [pick(0, 1, 2, 3, 4, 0x80000000, -1), pick(0, 1, 2, 3, 0x80000000, -1)], True)
case("f060980E4", [pick(0, 0x7FFF0000, 0x80000000, 0xFFFF0000, 0x12345678, -1)], True)
case("f0609EFD4", [pick(0, 1, 127, 128, 255, 0x180, -1, -128, 0x7F)], True)
case("f0609F274", [pick(0, 1, 2, 3, 7, 8, 0x10001, 0x10003), pick(0, 1, 7, 8, 9, 0x10000, 0x10003), pick(0, 1, 2, 0x10000, 0x10001)], False)
case("f0609F448", [pick(0, 1, 0x10000, -1, 0x80000000)], False)
case("f060A6DA6", [pick(0, 8, 16, 24, 64, 72, 80, 88, 0x7F, 0xFFFFFFFF)], True)
case("f060A8128", [span(-1, 9)], True, [plant(0x060FC084, 4, [0x060C2000], 1.0)]
    + [plant(0x060C2000 + o, 4, [0, 0, 1, 0xFFFFFFFF], 0.8) for o in (88, 0x304, 0x30C, 0x328, 0x338, 0x348, 0x1E0, 0x360)])
case("f060ABD84", [pick(FIX), pick(0, 5, 100, 0x7FFFFFFF, -1, 0x80000000)], False,
    [plant(FIX + 36, 4, [0, 5, 100, 0xFFFFFFFF]), plant(FIX + 0x104, 4, [0, 3, 99, 0xFFFFFFFF])])
case("f060ADA80", [pick(*[0x060FC190 + 4 * k for k in (-1, 0, 1, 5, 31, 32, 33)], 0, 0x060FC190 + 2)], True,
    [plant(0x060FC210, 4, [0xFFFFFFFF, 0, 0x20, 1], 0.9)] + [plant(0x060B12F8 + 4 * k, 4, [0, 1, 0xFFFFFFFF, 0x20, 0x80000000], 0.7) for k in range(32)])
case("f060AF17C", [pick(0, 0x00FFFFFF, 0x00102030, 0x12345678, 0x00FF00FF), span(-3, 800), pick(0x060C0200)], False)
case("f060AF22C", [pick(0, 0x00FFFFFF, 0x00102030, 0x12345678, 0x00FF00FF), span(-3, 100), pick(0x060C0200)], False)
case("f06055616", [pick(0, 1, 0x80, 0x100, -1)], False, [plant(0x060C122C, 1, [0, 1, 5, 29, 255]), plant(0x060EC484 + 24 * 255, 4, [0, -1])])
case("f06069462", [pick(0, 1, 7, 0x10000, 0x10001), pick(0, 499, 500, 501, -1, 0x7FFFFFFF, 0x80000000)], False)
case("f0606935A", [pick(0, 1, 2, 7), pick(0, 1, 2, 7)], False,
    [plant(obj(k) + 6, 2, [0, 1, 2, 7, 0x1003], 0.9) for k in (0, 1, 2, 7)])
case("f0606AB92", [pick(FIX)], False, [plant(0x060FB89C, 2, [0, 0x10, 0xFFEF, 0xFFFF, 0x20]), plant(FIX + 40, 2, [0, 0xFFFF, 3, 0x8000])])
case("f0606ABCC", [pick(0, 1, 2, 7, 0x10000)], False, [plant(0x060FB89C, 2, [0, 0x10, 0xFFEF, 0xFFFF, 0x20])])
case("f06094A6C", [pick(FIX)], True, [plant(FIX + i, 1, [0, 1, 2, 0xFF], 0.15) for i in range(40)])
case("f0609BE40", [pick(0, 1, 0x0F, 0xFF, 0x1F3, 0x12345), pick(0, 1, 0x0F, 0xFF, 0x1F3, 0x12345)], False)
case("f060A49F0", [pick(0, 1, 5, 0x1234, 0xFFFFFFFF), pick(0, 1, 5, 0xFFFFFFFF, 0x1235)], False, [plant(0x060AD658, 4, [0, 1]), plant(0x060AD65C, 4, [0, 0x060C2000, 0x0603DDA6])])
case("f0609B8C0", [pick(0, 1, 0x80000, 0x12345, 0x7FFFF), pick(0, 1, 2, 3, 0x10001), pick(0x060C0200)], False,
    [plant(0x060BB900, 2, [0, 2, 3]), plant(0x060BB8FC, 2, [0, 1]), plant(0x060FB8E0, 4, [0, 0x12, 0xFF, 0x1FF])])
