from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

case("f060065FC", [ptr(0x060C0100, 0x100, 2), span(0, 0xFFFF), span(-4, 64)], False)

case("f06014344", [], False,
     [plant(0x060D7E7C, 2, [0, 2, 4, 1], 1.0), plant(0x060D7E7E, 2, [0, 3, 10, 5], 1.0),
      plant(0x060D7E80, 2, [0, 3, 5, 1], 1.0), plant(0x060D7E82, 2, [0, 1, 3, 5], 1.0),
      plant(0x060C029C, 1, [17, 0, 3], 0.7)])
case("f0602AB54", [ptr(0x060C2000, 0x100, 4), span(-0x40000, 0x40000)], True)
case("f06038E1E", [ptr(0x060C0100, 0x100, 1), ptr(0x060C0200, 0x100, 1)], False,
     [plant(0x060C0100 + k, 1, [0, 65, 66], 0.2) for k in range(0, 0x200, 3)])
case("f0604D4D4", [span(0, 20), span(-3, 20)], True)
case("f06053934", [ptr(0x060C0100, 0x40, 2), pick(255, 4, 3, 2, 0, 1, 5, 7), span(-2, 12), pick(0, 1)], False)
case("f0605EAF6", [ptr(0x060C0100, 0x40, 2), span(-2, 9)], False)
case("f0606646A", [span(-100, 100), span(-100, 100), span(-100, 100), span(-100, 100)], True)

ACT = 0x060C2100            # a record for the pointer at 060D8C08
FALL = 0x060C2600           # the record at 060C1658 points at


def act(offset, size, values, chance=0.8):
    return plant(ACT + offset, size, values, chance)


def tsk(offset, size, values, chance=0.8):
    """A field of the slots the kernel runs."""
    return [plant(slot(k) + offset, size, values, chance) for k in (3, 4)]


def tob(offset, size, values, chance=0.8):
    """A field of the objects the slots own."""
    return [plant(obj(k) + offset, size, values, chance) for k in (3, 4)]


def cur(offset, size, values, chance=0.8):
    """A field of the bomber records CURRENT points at."""
    return [plant(bomber(k) + offset, size, values, chance) for k in (0, 1, 2)]


def mov(offset, size, values, chance=0.8):
    return [plant(obj(k) + offset, size, values, chance) for k in (3, 4)]


ACTOR = [plant(0x060D8C08, 4, [ACT], 1.0)]
TASK = [plant(0x060D7E60, 4, [slot(3), slot(4)], 1.0), plant(0x060D7E64, 4, [obj(3), obj(4)], 1.0)]
CURRENT = [plant(0x060D7768, 4, [bomber(0), bomber(1), bomber(2)], 1.0)]
MOVER = [plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0)]
OTHER = [plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0)]
HALVES = [0, 1, 2, 3, 5, 8, 0x10, 0x80, 0x100, 0x7FFF, 0x8000, 0xFFFF]

case("f0600A76E", [pick(1, 2, 4, 8, 16, 32, 0, 3, 64), span(0, 0xFFFF)], True,
     [plant(0x060FA9C8 + 2 * k, 2, [0, 0x8000, 0xC000, 0x8010, 0xC010, 0xFFFF, 0x0010, 0x4000, 0x0001, 0x1000], 0.8) for k in range(12)])
STATE = ([plant(0x060C04C5, 1, [0, 1, 2, 3, 3], 0.6), plant(0x060C04D8, 2, [0, 1, 2, 3], 0.5), plant(0x060C04DC, 2, [0, 0, 0, 1], 0.5),
          plant(0x060C04CA, 2, [0, 1, 3, 9], 0.6), plant(0x060C04CC, 2, [0], 0.6), plant(0x060C04DA, 2, [0, 0, 2], 0.6),
          plant(0x060B3978, 2, [0, 1, 4], 0.6)]
         + [plant(0x060EC8B0 + 2 * k, 2, [0, 0, 0, 1, 2], 0.5) for k in range(4)]
         + [plant(0x060EE8B0 + 2 * k, 2, [0, 0x100, 0x200, 0x500, 0xF00], 0.6) for k in range(4)]
         + [plant(0x060C04A0 + 6 * k, 2, [0, 100, 128, 255, 0xFFFF], 0.6) for k in range(4)])
case("f06010D08", [ptr(0x060C0100, 0x100, 4), ptr(0x060C0300, 0x100, 4)], False, STATE)
case("f0601251C", [], False, STATE + [plant(0x060F08B0 + 2 * k, 2, [0, 1, 2], 0.9) for k in range(4)]
     + [plant(0x060DFB9B + 8 * k, 1, [16, 10, 26, 3, 0, 5], 0.8) for k in range(4)])


def bomb(offset, size, values, chance=0.9, which=range(5)):
    """The value at offset of the first bomber records."""
    return [plant(bomber(i) + offset, size, values, chance) for i in which]


def objs(offset, size, values, chance=0.9, which=range(3, 6)):
    return [plant(obj(i) + offset, size, values, chance) for i in which]


# The random number table at 060BF4F8, with values a mask clears.
RANDOM = [plant(0x060BF4F4, 4, [1, 5, 20], 0.9)] + [plant(0x060BF4F8 + 4 * k, 4, [0, 32, 64, 5, 0], 0.7) for k in range(1, 56)]

case("f0600C8AC", [], False, [plant(0x060D7E6E, 2, [0, 1, 5], 1.0), plant(0x060D7E94, 4, [0x060D0000], 1.0)])
case("f06016776", [span(0, 5)], False,
     CURRENT + MOVER + cur(46, 2, [0, 0x800, 0x800]) + cur(36, 2, [0, 1, 2]) + bomb(53, 1, [0, 1, 2, 3], 0.9, range(3)))
case("f06017FF6", [], True,
     CURRENT + MOVER + cur(46, 2, [0x2000], 1.0) + [plant(0x060C062C, 2, [0, 1, 2], 1.0)]
     + [plant(0x060C07B0 + 18 * i + o, 2, v, 0.95) for i in range(3) for o, v in
        ((0, [0, 1, 2, 5]), (2, [0, 5, 100, 3000, 0xFFFF, 0xFF00]), (4, [0, 50, 100]), (6, [0, 1000, 5000, 0x7FFF]))]
     + [plant(0x060C07B0 + 18 * i + 14, 1, [0xFD, 0, 5], 0.9) for i in range(3)])
case("f06019D48", [], False,
     CURRENT + cur(20, 2, [0, 1, 2]) + cur(46, 2, [0, 2, 3]) + [plant(0x060C062C, 2, [0, 1, 2], 1.0), plant(0x060D849C + 7, 1, [0], 1.0)]
     + [plant(0x060E1A98 + k, 1, [0xFF, 0, 3], 0.8) for k in range(3)]
     + [plant(0x060EC8B0 + 2 * k, 2, [5, 0, 0, 1], 0.8) for k in range(3)]
     + [plant(0x060F08B0 + 2 * k, 2, [0, 0x100, 0x300], 0.8) for k in range(3)])
case("f0601B308", [span(0, 4)], True,
     bomb(46, 2, [0, 0x800, 0x800]) + bomb(36, 2, [0, 1, 2, 3]) + bomb(22, 2, [3, 4, 5]))
case("f0601B34A", [], False, CURRENT + MOVER + cur(52, 2, [0, 1, 2, 0xFFFD]))
case("f0601C0C8", [], False,
     CURRENT + MOVER + OTHER + cur(36, 2, [0, 1, 2, 3]) + [plant(0x060C063D, 1, [0, 2, 10]), plant(0x060C1AA8, 2, [3, 4], 1.0), plant(0x060D82BA, 2, [0, 16], 0.9),
                        plant(0x060D82BC, 2, [0, 16], 0.9),
                        plant(bomber(0) + 46, 2, [0, 0x128, 0x100, 0x20, 0x8], 0.9), plant(bomber(1) + 46, 2, [0, 0x128, 0x100, 0x20, 0x8], 0.9)]
     + mov(16, 2, [0, 100, 200], 1.0) + mov(18, 2, [100, 200], 1.0))
case("f0601C21C", [], True, OTHER + [plant(bomber(0) + 6, 1, [0, 1, 2, 3]), plant(bomber(1) + 6, 1, [0, 1, 2, 3])])
case("f0601F73A", [], False, ACTOR + [act(0, 2, [3, 4, 5]), act(2, 2, [0, 3, 4])])
case("f06021F9A", [span(0, 11)], False,
     [plant(0x060DFB96 + 8 * k + o, 2, [0, 3, 100], 0.7) for k in range(12) for o in (0, 2)])
case("f06025FEE", [], True,
     TASK + tsk(10, 2, [0, 1, 2, 3]) + tsk(12, 2, [0, 1, 2]) + tsk(14, 2, [0, 1, 2]) + [plant(0x060C02A1, 1, [0, 1, 2, 3], 0.9)]
     + [plant(0x060EC8B0 + 2 * k, 2, [0, 32, 0x20, 1], 0.8) for k in range(3)]
     + [plant(0x060EE8B0 + 2 * k, 2, [0, 0x1000, 0x2000, 0], 0.8) for k in range(3)])
case("f06028D98", [], False, RANDOM + [plant(0x060C02A4, 1, [0, 0, 3]), plant(0x060C029C, 1, [17, 0, 3], 0.7)]
     + [plant(0x060DFB9B + 8 * k, 1, [0, 1, 5], 0.6) for k in range(12)])
case("f0602B954", [span(-3, 12)], True, [plant(0x060C0640 + k, 1, [0, 1, 2, 3, 4], 0.7) for k in range(10)])
case("f0602B998", [span(-3, 12)], True, [plant(0x060C0640 + k, 1, [0, 1, 2, 3, 4], 0.7) for k in range(10)])
case("f0603A64C", [], True,
     [plant(0x060C1658, 4, [FALL], 1.0), plant(FALL + 14, 2, [0, 1, 2, 5], 0.9), plant(FALL + 10, 2, [3, 4, 5], 0.95),
      plant(FALL + 12, 2, [3, 4, 5], 0.95), plant(FALL + 16, 2, [0, 256, 0x7FFF, 0xFF00], 0.9), plant(FALL + 18, 2, [0, 5, 100], 0.9)])

# The block that the allocator's tables lead 06008ECA to, which copies it to VDP2. 06008A96 rebuilds
# the table at 060BD8E4 from the one at 060BD8D8, so the plants go there.
BLOCK = [plant(0x060BD8D8, 4, [0x060C2700], 1.0), plant(0x060C2704, 4, [0x060C2780], 1.0), plant(0x060C27DC, 4, [0x060C2800], 1.0),
         plant(0x060C27C8, 4, [0x060C2800], 1.0), plant(0x060C2802, 2, [0, 1, 2, 5], 1.0), plant(0x060BF4A8, 2, [64, 128, 5], 1.0)]
FALLP = [plant(0x060C1658, 4, [FALL], 1.0)]
CELLS = [plant(0x060EC8B0 + 2 * k, 2, [0, 1, 0x20, 0x380, 0x8000, 0xFFFF], 0.6) for k in range(0, 40)]

case("f0605BBEC", [], False, FALLP + [plant(FALL, 1, [0, 3, 5], 0.9), plant(FALL + 1, 1, [0, 3, 5], 0.9)])
case("f0605CBE2", [], False, BLOCK)
case("f06063370", [], False, BLOCK)
case("f0606AB08", [span(0, 100), span(0, 15)], True)
case("f0606C724", [span(0, 400), span(0, 400)], True, CURRENT + cur(18, 2, [0, 1, 0x380, 0x7F]) + CELLS)
case("f0606CBCC", [span(-20, 100), span(-20, 100)], True, MOVER + mov(16, 2, [0, 100, 0x140, 0x1FF, 0xFFE0], 0.9) + mov(18, 2, [0, 100, 0xF0, 0xFF, 0xFFE0], 0.9))
case("f0606E81C", [], False, CURRENT)
case("f0606EA3A", [span(0, 20), span(0, 20), span(0, 20), span(0, 20)], False, CURRENT + MOVER + OTHER + cur(46, 2, [0, 1, 2, 3], 1.0)
     + [plant(0x060C1AA8, 2, [3, 4], 1.0)] + objs(52, 4, [0x060C2800], 1.0, (3, 4)))
case("f06074AFA", [span(0, 400), span(0, 400)], False, CURRENT)
case("f0606D37A", [], True, MOVER + mov(60, 2, [0xFF00, 0, 0xFFFF], 1.0) + [plant(0x060D776C + 9, 1, [1], 1.0)])

BYTES = [plant(0x060C029C, 1, [0, 1, 2, 3, 17], 0.9), plant(0x060C029D, 1, [0, 1, 2, 5], 0.9), plant(0x060C179A, 1, [0, 1, 2, 3], 0.9),
         plant(0x060C179B, 1, [0, 1, 2, 3], 0.9), plant(0x060C179C, 1, [0, 1, 2, 3], 0.9), plant(0x060C179D, 1, [0, 1, 2, 3], 0.9),
         plant(0x060C029E, 1, [0, 1, 2, 3], 0.9), plant(0x060C029F, 1, [0, 1, 2, 3], 0.9), plant(0x060BF5EA, 2, [0, 0, 1], 0.9)]
LEVELS = [plant(0x060B6A00 + 2 * k, 2, [0, 1, 2, 9], 0.8) for k in range(8)]
# An object whose cell index is 326, the cell index of a bomber the slots are looking for.
FOUND = ([plant(0x060C029C, 1, [0], 1.0), plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0)]
         + objs(16, 2, [100], 1.0, (3, 4)) + objs(18, 2, [100], 1.0, (3, 4)) + objs(50, 2, [90, 90, 50, 100], 0.9, (3, 4))
         + bomb(20, 2, [326, 326, 0], 1.0, range(4)) + [plant(slot(k) + 8, 2, [3, 4, 0], 0.8) for k in range(5)])

case("f0603B660", [], False,
     TASK + tsk(18, 2, [3, 4]) + tsk(20, 2, [0, 5, 100, 0xFFF0]) + tob(16, 2, [0, 5, 100, 0xFFF0, 200]) + tob(18, 2, [0, 5, 100, 0xFFF0, 200])
     + tob(38, 2, [0, 5, 100, 200, 0xFFF0]) + [plant(0x060D7E88, 2, [0, 5, 100, 0xFFF0, 200]), plant(0x060D7E8A, 2, [0, 5, 100, 0xFFF0, 200]),
                                               plant(0x060C1734, 1, [0, 1, 5, 16, 200]), plant(0x26006038, 4, [0, 1, 2, 3])]
     + tob(16, 2, [100], 0.9) + tob(18, 2, [100], 0.9) + tob(38, 2, [100], 0.9) + tsk(20, 2, [100], 0.9)
     + [plant(0x060D7E88, 2, [100], 0.9), plant(0x060D7E8A, 2, [100], 0.9)])
case("f0604142A", [span(-5, 5)], True,
     TASK + RANDOM + tsk(8, 2, [3, 4], 1.0) + tsk(12, 2, [0, 1, 2]) + mov(16, 2, [416, 410, 423, 288, 100], 1.0) + mov(18, 2, [100, 200], 1.0)
     + [plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0, 16], 1.0), plant(0x060C029C, 1, [0, 17], 0.9)])
case("f0604D602", [], False, BYTES + LEVELS)
case("f0604D6AC", [], True, BYTES + LEVELS)
case("f0604D758", [], False, BYTES + LEVELS)
case("f0604D9D0", [pick(0, 1, 2, 3), pick(0, 1, 2, 3, 4, 5), span(0, 8), ptr(0x060C0200, 0x40, 2)], True)
case("f06053ECE", [], True, TASK + tsk(12, 2, [0, 1, 2]) + tob(38, 2, [0, 100, 123, 125, 127, 0xFFFF], 0.9) + tsk(8, 2, [3, 4]) + tsk(10, 2, [3, 4]))
case("f06053F5C", [], True, TASK + tsk(14, 2, [0, 1, 5]) + tob(38, 2, [0, 5, 100]))
case("f0605401C", [], True, TASK + tsk(10, 2, [3, 4]) + objs(60, 2, [0xFF00, 0, 0xFFFF], 0.9, (3, 4)))
case("f06057930", [pick(0, 10, 20, 40, 100, -50, 3), pick(0, 10, 20, 40, 100, -50, 3), pick(0, 1)], True,
     [plant(0x060FAA20, 4, [0, 0x00280000, 0x001E0000, 0x00140000, 0x00500000, 0x7FFF0000, 0xFFFF0000, 0x00100000], 0.9),
      plant(0x060FAA24, 4, [0, 0x00280000, 0x001E0000, 0x00140000, 0x00500000, 0x7FFF0000, 0xFFFF0000, 0x00100000], 0.9),
      plant(0x060C184C, 2, [0, 100, 0xFF9C, 0x1000, 0x1100, 64, 65, 0x7FFF, 0x8000, 200, 0x2000, 0x1800], 0.9),
      plant(0x060C184E, 2, [0, 100, 0xFF9C, 0x1000, 0x1100, 64, 65, 0x7FFF, 0x8000, 200, 0x2000, 0x1800], 0.9)])
case("f06059AE8", [], False, [plant(0x060C0AA8, 4, [0, 1, 2, 3], 1.0)])
case("f0605A5E8", [pick(0, 1, 2, 255, 256)], False,
     [plant(0x060C1048, 4, [0x20, 0x1020, 0x2020, 0x3020, 0, 0x30, 0x1030, 0x2030], 0.95), plant(0x060C122C, 1, [0, 1, 2], 0.95)]
     + [plant(0x060EC47B + 24 * k, 1, [1, 2, 0], 0.9) for k in range(3)] + [plant(0x060C18FC + k, 1, [0, 1, 5], 0.6) for k in range(10)]
     + [plant(0x060C0682, 1, [0xFF, 0x10]), plant(0x060C18FA, 1, [0xFF, 0x10]), plant(0x060C18FB, 1, [0, 1, 5])])
case("f0605B614", [], True,
     [plant(0x060C122C, 1, [0, 1, 2, 3, 40], 0.95), plant(0x260060B0, 2, [0, 0x8000, 0x4000, 0xC000, 0x4000, 0x8000], 0.95),
      plant(0x060C1040, 4, [0, 8], 0.9)]
     + [plant(0x060EC478 + 24 * k, 2, [31, 32, 255, 31, 32], 0.95) for k in range(4)]
     + [plant(0x060EC478 + 24 * k + 2, 2, [1, 2, 3, 4, 5, 6, 7, 8], 0.95) for k in range(4)]
     + [plant(0x060C18F8 + k, 1, [0, 1, 2, 3, 4, 255], 0.8) for k in range(5)])
case("f0605CAEC", [], False,
     TASK + [plant(0x060C0338, 4, [0, 5 << 16, 8 << 16, 16 << 16, 19 << 16, 1 << 16], 0.95), plant(0x060C1914, 4, [0], 0.9)]
     + tsk(16, 2, [0, 1, 5]) + tsk(10, 2, [0, 1, 5]) + tsk(14, 2, [0, 1, 5]))
case("f0605DDB6", [], False,
     TASK + tsk(8, 2, [3, 4]) + tsk(10, 2, [0, 1]) + tsk(12, 2, [326, 0, 326, 9, 2]) + [plant(0x060D7B50, 2, [3, 4], 1.0)]
     + [plant(0x060C029C, 1, [0], 1.0), plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0)]
     + objs(16, 2, [100], 1.0, (3, 4)) + objs(18, 2, [100], 1.0, (3, 4)))
case("f0605F136", [span(0, 3)], True, TASK + FOUND + tsk(12, 2, [0, 1, 2, 3]) + tsk(18, 2, [0, 0, 1]))
case("f0605F204", [span(0, 3)], True, TASK + FOUND + tsk(12, 2, [0, 1, 2, 3]) + tsk(18, 2, [0, 0, 1]))
case("f06062BAC", [], True, TASK + tsk(10, 2, [0, 5, 0x7FFF, 0x8000, 0xFFFF]))
case("f060635B4", [], False,
     TASK + tob(16, 2, [0, 100, 0xFFE0, 0xFFC0, 0xFFFF]) + tob(18, 2, [0, 100, 241, 250, 0xFFFF]) + tsk(10, 2, [0, 5, 100]) + tsk(12, 2, [0, 5, 100]))
case("f06065EF2", [], False, TASK + tob(38, 2, [0, 100, 120, 121, 125]))
case("f06066BB0", [], False,
     TASK + tsk(14, 2, [0, 1, 5]) + tsk(16, 2, [0, 10, 47, 48, 63, 64, 0x1FF, 0x200, 0x300]) + [plant(0x26006038, 4, [0, 1, 2, 3, 7, 8, 15, 16, 0x10], 0.95)]
     + tsk(10, 2, [0, 5, 100]) + tsk(12, 2, [0, 5, 100]) + tob(18, 2, [0, 5, 100]) + tob(16, 2, [0, 5, 100]) + tob(70, 2, [0, 5, 100]))
case("f06066DDE", [], False, TASK + tob(18, 2, [0, 0x117, 0x118, 0x200]))
case("f06066EAE", [], False, TASK + tob(18, 2, [0, 0x117, 0x118, 0x200]))
case("f06068EC8", [], False,
     [plant(0x060D7E68, 2, [0, 0x20, 0], 0.9)] + [plant(0x060C19E4 + 24 * k, 2, [0, 1], 0.7) for k in range(8)]
     + [plant(0x060C19E4 + 24 * k + 20, 2, [0, 1, 2, 5], 0.8) for k in range(8)])
case("f060693DC", [span(0, 450), span(0, 450), span(-2, 2)], True, [plant(obj(i), 4, [0, 1], 0.8) for i in range(2, 8)])

CELL = [plant(0x060C1F42 + 12 * k + o, 2, [0, 1, 5, 50, 100, 0xFFFB, 0xFF00, 0x8000], 0.8) for k in range(4) for o in (0, 2, 4, 6, 8)]
SPEEDS = [plant(0x060C1F24, 2, [0, 1, 2, 3], 0.95)]

case("f0606B648", [], True,
     CURRENT + SPEEDS + CELLS + cur(44, 2, [0, 0, 1]) + cur(20, 2, [0, 1, 2, 3]) + cur(18, 2, [0, 1, 0x380])
     + [plant(0x060B90A0 + 2 * k, 2, [0, 1, 2, 0xFFFF], 0.8) for k in range(4)] + [plant(0x060B90AA + 2 * k, 2, [0, 1, 2, 0xFFFF], 0.8) for k in range(4)]
     + [plant(0x060B90D2 + 2 * k, 2, [0, 1, 5, 0xFFFF], 0.8) for k in range(4)] + [plant(0x060B90DC + 2 * k, 2, [0, 1, 0xFF, 0xFFFF], 0.8) for k in range(4)])
case("f0606BBB0", [], False, CURRENT + cur(65, 1, [0, 1, 2]) + CELL + [plant(0x060C1F5C, 4, [0])])
case("f0606BEBC", [span(0, 3)], True, CELL + CELLS)
case("f0606C05C", [span(0, 3), span(0, 100), span(0, 100)], True, CURRENT + cur(6, 1, [1, 2, 3, 4, 0], 0.95) + CELL)
case("f0606C850", [], False, CURRENT + cur(18, 2, [0x20, 0, 0x20]) + cur(28, 2, [0, 100, 1100, 0x8000]) + cur(24, 2, [0, 100, 200]))
case("f0606C894", [], False, CURRENT + cur(28, 2, [0, 100, 1100, 0x8000]) + cur(24, 2, [0, 100, 200]))
case("f0606CD0C", [span(0, 50), span(0, 50), span(0, 50), span(0, 50)], False,
     CURRENT + cur(24, 2, [0, 100, 200]) + cur(28, 2, [0, 100, 200])
     + [plant(0x060C1E4C, 2, [0, 1], 0.9), plant(0x060C1AAC, 2, [0, 5, 100], 1.0), plant(0x060C1AAA, 2, [3, 4], 0.9)]
     + [plant(obj(i), 4, [0, 0, 1], 0.6) for i in range(2, 12)])
case("f0606D648", [span(0, 10), span(0, 10)], True,
     CURRENT + cur(54, 2, [0, 1, 5, 9, 16, 17, 25, 32, 0x30, 0x31]) + cur(56, 2, [0, 16, 32, 0x30, 0x20]) + cur(42, 2, [0, 2]) + cur(44, 2, [0, 1])
     + cur(6, 1, [1, 2, 3, 4, 0]) + cur(10, 2, [0, 1, 4, 8, 16, 0x20]) + cur(12, 2, [0, 1]) + cur(24, 2, [0, 100, 0x30]) + cur(28, 2, [0, 100, 0x30])
     + cur(26, 2, [0, 0x8000]) + cur(30, 2, [0, 0x8000]) + SPEEDS + CELLS
     + [plant(0x060B90B5 + 2 * k, 1, [1, 2, 3, 4], 0.8) for k in range(5)])
case("f0606D7A6", [span(0, 10), span(0, 10)], True,
     CURRENT + cur(6, 1, [1, 2, 3, 4, 0], 0.95) + cur(10, 2, [0, 1, 0x8000, 0xFFFF]) + cur(12, 2, [0, 1, 0x8000]) + cur(24, 2, [0, 100]) + cur(26, 2, [0, 0x8000])
     + cur(28, 2, [0, 100]) + cur(30, 2, [0, 0x8000]))
case("f0606E00E", [], False,
     CURRENT + cur(24, 2, [0, 7, 8, 50, 88, 89, 100, 200]) + cur(82, 2, [0, 50, 100, 200]) + cur(28, 2, [0, 7, 8, 50, 88, 89, 100, 200]) + cur(84, 2, [0, 50, 100, 200]))

case("f060231FA", [], False,
     TASK + [plant(0x060D7E68, 2, [0x40, 0, 0x40], 0.9), plant(0x060C02AE, 2, [0, 1, 2, 3], 0.9)] + tsk(10, 2, [0, 0x100, 0xFF, 5], 0.9)
     + tsk(14, 2, [0, 1, 1, 2, 3, 4, 5, 6], 0.95) + tsk(12, 2, [0, 1, 2, 64, 64, 64, 65, 0xFFFF], 0.9) + tsk(16, 2, [0, 1, 2, 0x100], 0.9) + tsk(8, 2, [3, 4], 0.9))

case("f0602168C", [pick(0, 5, -3, 1000000), pick(0, 1, 2, 3)], False,
     bomb(46, 2, [0x800], 0.9, (0, 1)) + bomb(4, 1, [0, 0, 0x80]) + bomb(36, 2, [0, 1, 2], 0.9, (0, 1))
     + [plant(0x060D5F70 + 124 * k, 2, [1, 2, 3], 0.9) for k in range(3)]
     + [plant(0x060D82DC + 4 * k, 4, [0, 5, 0x0098967C, 0x0098967F, 0x7FFFFFFF], 0.9) for k in range(25)]
     + [plant(0x060C0690 + 4 * k, 4, [0, 5, 0x0098967C, 0x7FFFFFFF], 0.8) for k in range(2)])
case("f0601E2A4", [pick(0, 1), span(0, 6), span(0, 4)], True,
     [plant(0x060F08B0 + 2 * k, 2, [0x0100, 0x0200, 0x0300, 0, 0x0001, 0x0102, 0x0201], 0.9) for k in range(7)])
