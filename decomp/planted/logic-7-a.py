from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

POINTS = 0x060EC478
SP = 0x060FFFF0                 # r15 on entry; the first stack argument is here
FREE = 0x060C0100
TASKP = [plant(0x060D7E60, 4, [0x060C2100], 1.0), plant(0x060D7E64, 4, [obj(3)], 1.0)]
CURB = [plant(0x060D7768, 4, [bomber(0), bomber(1), bomber(2)], 1.0)]
COUNT = [plant(0x060C063D, 1, [0, 1, 2, 3, 4, 5], 1.0), plant(0x060C062C, 2, [0, 1, 2, 3, 6], 1.0)]
MOVER = [plant(0x060D7B3C, 4, [obj(3), obj(4)], 1.0)]
# the 38-byte actor records at 060D849C: byte 7 of each names the next, and 0 ends the chain
A0 = 0x060D849C
ACT = [plant(A0 + 38 * k + 7, 1, [k + 1, k + 1, k + 1, 0], 1.0) for k in range(5)]
ACT += [plant(A0 + 38 * k + 7, 1, [0], 1.0) for k in range(5, 12)]


def actor(offset, values, size=1, chance=0.8):
    return [plant(A0 + 38 * k + offset, size, values, chance) for k in range(6)]


def recs(offset, values, size=2, chance=0.8, n=6):
    return [plant(bomber(i) + offset, size, values, chance) for i in range(n)]


BRAINS = [0x060C0360 + 32 * k for k in range(10)]
BRAIN = pick(*BRAINS)

# 06008A6A reads its source through the four pointers at 060BD8D4, which point into work RAM-L, and 06008A96 copies twelve words of it
PALTAB = [plant(0x060BD8D4 + 4 * k, 4, [0x00200000, 0x00254000], 1.0) for k in range(4)]
PALTAB += [plant(base + 4 * k, 4, [0x060C4000], 1.0) for base in (0x00200000, 0x00254000) for k in range(12)]
# 06008ABA takes a word from the table that 060BD904 names, and 06068BDC walks the records that word names until a halfword of -1
BANK = [plant(0x060BD904, 4, [0x060C4000], 1.0), plant(0x060C4000, 4, [0x060C4100], 1.0), plant(0x060C4004, 4, [0x060C4100], 1.0)]
BANK += [plant(0x060C4100 + 4 * k, 4, [0x060C4200], 1.0) for k in range(100)]
BANK += [plant(0x060C4200, 4, [0xFFFF0000, 0x00000000], 1.0), plant(0x060C4204, 4, [0xFFFF0000], 1.0)]
BOXES = [plant(0x060FBFFC, 4, [0], 1.0)]


def data(address, halfwords):
    """The halfwords of a table in the image, which the check randomises with the variables around it."""
    return [plant(address + 2 * i, 2, [w], 1.0) for i, w in enumerate(halfwords)]


def data8(address, values):
    return [plant(address + i, 1, [v], 1.0) for i, v in enumerate(values)]

# 06068CC4 looks its argument up in a table that 060BD904 leads to, and walks the list the entry names until a halfword of -1
SPRITES = [plant(0x060BD904, 4, [0x060C4000], 1.0), plant(0x060C4000, 4, [0x060C4100], 1.0), plant(0x060C4004, 4, [0x060C5000], 1.0)]
SPRITES += [plant(0x060C5000 + 4 * k, 4, [0x060C7000], 1.0) for k in range(700)] + [plant(0x060C7000, 4, [0xFFFF0000], 1.0)]

# 0600C4E0 loads the tile table at 060D7E98 from 060D7E9C and the buffer at 060D7EA0 from one of 060D7EA4 to 060D7EB0
TILES = [plant(0x060D7E98, 4, [0x06000000], 1.0), plant(0x060D7EA0, 4, [0x060C6000], 1.0),
         plant(0x060DF988, 4, [0x06000000], 1.0), plant(0x060DF98C, 4, [0x060C6000], 1.0),
         plant(0x060D7E9C, 4, [0x06000000], 1.0), plant(0x060D7EA4, 4, [0x060C6000], 1.0)]

# the table of ten-byte entries at 060C0DF0, sorted by the key halfword at 0, and how many are in use
KEYS = [plant(0x060C0F80, 2, [0, 1, 2, 3, 4, 5, 6], 1.0)] + [plant(0x060C0DF0 + 10 * k, 2, [0xFFFF, 5, 3, 1, 9, 5, 0x7FFF, 0x8000], 0.95) for k in range(8)]
KEYS += [plant(0x060C0DF0 + 10 * k + o, 2, [0, 1, 7, 0xFFFF], 0.8) for k in range(8) for o in (2, 4, 6, 8)]
case("f06008EE8", [span(0, 50), span(50, 100)], False)
case("f06008F08", [span(0, 50), span(50, 100)], False)
case("f060093B0", [span(0, 5)], True,
     [plant(0x060CE060 + 16 * k, 4, [0x060C4000], 1.0) for k in range(5)]
     + [plant(0x060CE064 + 16 * k, 4, [0x060C4000, 0x060C4008, 0x060C4040], 0.9) for k in range(5)]
     + [plant(0x060CE06B + 16 * k, 1, [0, 1, 2], 1.0) for k in range(5)]
     + [plant(0x060C4000 + 2 * k, 2, [0, 1, 5], 0.6) for k in range(32)])
for _a in ("0600AA2A", "0600AAE4", "0600AB46"):
    case("f" + _a, [pick(0, 1, 2, 4, 8, 16, 32, 64)], True)
case("f0600E1BC", [], True, TASKP + [plant(0x060C035E, 2, [0, 1, 2, 3], 1.0), plant(0x060C2100 + 10, 2, [0, 5, 8, 9, 10, 12, 0xFFFF], 1.0)])
case("f0600E318", [], True, TASKP + [plant(obj(3) + 16, 2, [100, 159, 160, 200, 0x11F, 0x120, 0x130, 0xFFF0], 1.0)])
case("f0600E38C", [], True, TASKP + [plant(0x060C035E, 2, [0, 3, 5], 1.0), plant(0x060C2100 + 10, 2, [0, 3, 5, 6], 1.0),
                                    plant(0x060C2100 + 12, 2, [0, 15, 16, 20], 1.0)])
case("f06010468", [], True, [plant(0x060C029C, 1, [0, 5, 8, 9, 12], 1.0), plant(0x060C029D, 1, [0, 4, 200], 0.8),
                             plant(0x060C0680, 1, [0, 1, 2, 3, 9], 1.0)])
case("f060114D8", [], True, [plant(0x060C029C, 1, [17, 5], 1.0), plant(0x060D7EB6, 2, [0, 7, 12, 19, 25], 1.0),
                             plant(0x060D7E7E, 2, [0, 5, 8], 1.0), plant(0x060D7E82, 2, [10, 21, 30], 1.0)])
case("f06011818", [], True, CURB + COUNT + recs(4, [0, 0, 0x80]) + recs(24, [0, 10, 20, 5000]) + recs(28, [0, 10, 40, 5000]))
case("f060118A6", [BRAIN], False, CURB + [plant(0x060C04A3, 1, [0, 1, 2, 3], 1.0), plant(0x060C04D6, 2, [0, 5], 1.0)])
case("f0601198C", [], True, [plant(0x060C04D8, 2, [0, 1, 2, 5], 1.0), plant(0x060C04DC, 2, [0, 0x42B0, 1], 0.6),
                             plant(0x060C04CC, 2, [0, 1, 2], 1.0), plant(0x060C04DA, 2, [0, 3, 40], 1.0)])
case("f06011D86", [pick(0, 1, 2, 20, 0x1D, 0x1E), pick(0, 0x1000, 0x1001, 0x2000, 0x11FFF)], True,
     COUNT + recs(20, [0, 1, 2, 20, 0x1D, 0x1E]) + recs(4, [0, 0x80]))
case("f06011E2C", [pick(0, 1, 20), ptr(0x060C0000, 0x100, 2)], True, COUNT + recs(20, [0, 1, 20]))
case("f060122F0", [span(0, 3)], True, CURB + [plant(0x060B3C68 + 4 * k, 4, [1, 2, -1, -2, 3], 0.5) for k in range(4)]
     + [plant(bomber(i) + 20, 2, [0x20, 0x21, 0x22, 0x23], 1.0) for i in range(3)])
# the bomber a brain acts for, where the other bomber stands, and the search state the brain code reads
BW = (CURB + COUNT + MOVER + recs(36, [0, 1, 2, 0]) + recs(24, [0x100, 0x164, 0x19C, 0xA0], chance=1.0) + recs(28, [0x100, 0x100, 0x120], chance=1.0)
      + recs(40, [0, 0, 1, 2]) + recs(62, [0, 1, 2, 3, 8]) + recs(64, [0, 0x400, 0x100, 0x300, 0x200]) + recs(42, [0, 0x20]) + recs(66, [0, 1])
      + recs(46, [0, 0x20, 0x300, 0x10, 0x33D, 0x27D, 0x800, 0x1000]) + recs(20, [0x20, 0x21, 0x22, 0x40], chance=1.0)
      + recs(6, [0, 1, 2, 3, 4, 5], size=1) + recs(4, [0, 0x40, 0x80], size=1) + recs(52, [0, 0, 1, 2])
      + [plant(0x060EC8B0 + 2 * c, 2, [0, 0, 0x42B0, 0x1000, 0x80, 0x10], 0.7) for c in range(0x1E, 0x44)]
      + [plant(0x060EE8B0 + 2 * c, 2, [0, 0x1000, 0x500, 0xA00, 0xF00], 0.7) for c in range(0x1E, 0x44)]
      + [plant(0x060C04CA, 2, [0, 3, 50], 1.0), plant(0x060C04CC, 2, [0, 1], 1.0), plant(0x060C04DA, 2, [0, 2], 1.0),
         plant(0x060C04D8, 2, [0x20, 0x21, 0x40], 1.0), plant(0x060C04DC, 2, [0, 0x42B0], 0.5),
         plant(0x060BF5E4, 2, [0, 1], 1.0), plant(0x060BF5DC, 2, [0, 1], 1.0)]
      + [plant(b + 24, 1, [0, 1, 2, 3], 1.0) for b in BRAINS] + [plant(b + 28, 1, [0, 1, 2, 3, 4], 1.0) for b in BRAINS]
      + [plant(b + 12, 2, [0, 0x1000, 0x1003], 0.8) for b in BRAINS])
for _a in ("0601292C", "060129A6", "06012A02", "06012A88", "06012C88", "06012DCC", "06012E02", "06012E54", "06012F6C",
           "0601302E", "06013134", "060131E0", "060136E0"):
    case("f" + _a, [BRAIN], True, BW)
case("f0601640E", [], True, BW + MOVER + [plant(0x060C029C, 1, [0, 5, 9], 1.0), plant(0x060C0684, 2, [0, 0xF000, 0x1000], 1.0)]
     + [plant(obj(3) + 60, 2, [0, 1, 5, 10], 1.0), plant(obj(3) + 62, 2, [0, 3, 5], 1.0), plant(obj(4) + 60, 2, [0, 5, 10], 1.0),
        plant(obj(4) + 62, 2, [0, 3, 5], 1.0)]
     + recs(22, [3, 4], chance=1.0) + recs(36, [0, 1, 2], chance=1.0)
     + [plant(0x060D5F46 + 124 * i, 2, [3, 4], 1.0) for i in range(6)])
case("f0601741C", [], True, BW + MOVER + recs(22, [3, 4], chance=1.0)
     + [plant(0x060C381C + 84 * i + 16, 2, [0, 40], 0.6) for i in range(8)])
case("f060175F2", [], True, BW + [plant(0x060D7768 + 0, 4, [bomber(0), bomber(1)], 1.0)] + recs(66, [0, 0, 1]) + recs(42, [0, 64, 64]))
case("f06017648", [], True, BW)
case("f06017A2A", [], True, BW + MOVER + recs(108, [0x060175F2, 0, 5], size=4) + recs(22, [3, 4], chance=1.0) + recs(60, [3, 4], chance=1.0)
     + recs(66, [0, 5, 20]) + recs(54, [0, 5, 20]))
case("f06017BD2", [], True, BW + MOVER + [plant(obj(3) + 68, 2, [0, 1, 40, 0x100], 1.0), plant(obj(4) + 68, 2, [0, 1, 40], 1.0)])
# 0600C90C puts 060D7E88 and 060D7E8A at the object's position, the second 24 higher (less the scroll at 060D82BA and 060D82BC)
case("f06018EBC", [pick(3, 4)], True, BW + [plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0)]
     + [plant(obj(k) + 16, 2, [0x100], 1.0) for k in (3, 4)] + [plant(obj(k) + 18, 2, [0x100], 1.0) for k in (3, 4)]
     + recs(24, [0x100, 0x102, 0x10A, 0xF8], chance=1.0) + recs(28, [0xE8, 0xEA, 0xF2, 0xE0], chance=1.0)
     + recs(4, [0, 0, 0x40], size=1, chance=1.0) + recs(46, [0, 0, 0x20], chance=1.0))
case("f0601BC9E", [pick(0, 1, 7), pick(0, 1, 7), pick(0, 1, 7)], True, BW + MOVER + recs(36, [0, 0, 1]))
case("f0601C182", [span(0, 5)], True, BW + [plant(0x060D8318, 4, [0x060C2200], 1.0)]
     + [plant(0x060C2200 + 2 * k, 2, [0, 0, 5, 7], 0.8) for k in range(6)])
case("f0601FD42", [pick(0, 1)], False, BW + ACT + actor(16, [2, 2, 5, 255, 0], chance=1.0) + actor(34, [0, 1, 2, 3], chance=1.0)
     + actor(10, [1, 1, 1, 0, 3], size=2, chance=1.0) + actor(24, [2, 2, 2, 0], chance=1.0) + actor(6, [0, 1, 2, 3], chance=0.9))
ACTP = [plant(0x060D8C08, 4, [0x060C2100], 1.0)]
ACTF = [plant(0x060C2100 + 14, 1, [0, 1, 2, 3, 4, 5], 1.0), plant(0x060D7E88, 2, [0, 4, 8, 12, 0x13], 1.0),
        plant(0x060D7E8A, 2, [0, 4, 8, 12, 0x13], 1.0)]
case("f06020B40", [], False, ACTP + ACTF)
case("f06020D1C", [], True, ACTP + [plant(0x060C2100 + 4, 2, [0, 1, 2, 3], 1.0), plant(0x060C2100 + 10, 2, [0, 0x100], 1.0)]
     + [plant(0x060EC8B0 + 2 * k, 2, [0, 0x42B0, 0x10], 0.7) for k in range(4)])
case("f06020E40", [pick(0, 1, 2, 3)], True, ACT + actor(16, [0, 1, 255, 3], chance=0.9) + actor(15, [0, 1, 2, 3], chance=0.9)
     + [plant(A0 + 38 * k + 6, 1, [k - 1], 1.0) for k in range(1, 6)] + actor(0, [0], size=2, chance=1.0) + actor(2, [0], size=2, chance=1.0)
     + actor(13, [0, 1], chance=0.5) + actor(35, [0], chance=1.0))
case("f06021014", [pick(0, 1, 2, 3)], True, ACT + actor(16, [0, 1, 2], chance=0.9) + actor(4, [0, 1, 2, 3], size=2, chance=0.9)
     + actor(15, [0, 1, 2, 3], chance=0.9))
case("f0602105A", [pick(0, 1, 2, 3)], True, ACT + actor(15, [0, 1, 2, 3], chance=0.9))
case("f06021486", [], False, ACT + actor(36, list(range(0, 16)), chance=0.9) + actor(4, [0, 1, 2, 3], size=2, chance=0.9)
     + actor(17, [0, 5], chance=0.9) + actor(35, [0xFF, 3], chance=0.9)
     + [plant(0x060EC8B0 + 2 * k, 2, [0, 0x2000], 0.6) for k in range(4)])
# 0600CA6A puts 060D7E88 and 060D7E8A at the object of the slot's halfword at +8, the second 24 higher
case("f06022FFC", [span(0, 3)], True, CURB + [plant(0x060D7B46, 2, [0, 5], 0.9), plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0)]
     + [plant(0x060D7B48 + 24 * k + 8, 2, [0, 3, 4], 0.9) for k in range(4)] + recs(24, [0x100, 0x108, 0x10A, 0xF8], chance=1.0)
     + recs(28, [0x100, 0x108, 0x10A, 0xF8, 0x80], chance=1.0) + [plant(obj(k) + 16, 2, [0x100], 1.0) for k in (3, 4)]
     + [plant(obj(k) + 18, 2, [0x118], 1.0) for k in (3, 4)])
case("f06023EF8", [], True, TASKP + [plant(obj(3) + 16, 2, [0, 0x150, 0x151, 0x200], 1.0), plant(obj(3) + 18, 2, [0, 0x100, 0x101], 1.0)])
case("f060247D8", [], False, TASKP + CURB + MOVER + recs(6, [0, 1, 2, 3, 4, 5], size=1, chance=1.0))
case("f06024D78", [], False, TASKP + [plant(0x060D7E8C, 2, [0x20, 0x21, 0x40], 1.0)]
     + [plant(0x060EC8B0 + 2 * c, 2, [0, 128], 0.5) for c in range(0x10, 0x80)])
case("f06024DF8", [], True, TASKP + [plant(obj(3) + 68, 2, [0x50, 0xFF, 0x100, 0x120], 1.0)])
case("f06025A54", [], True, TASKP + [plant(0x060C2100 + 18, 2, [0, 1, 2, 3], 1.0), plant(0x060C2100 + 14, 2, [0, 1, 2, 3], 1.0)]
     + recs(28, [0, 8, 3, 15, 0x100]) + recs(24, [0, 8, 3, 15, 0x100]) + recs(20, [0x41, 0x42, 0x50, 0x1, 0x2], chance=1.0)
     + recs(18, [0, 1, 0x42B0, 0xFFFF]) + [plant(0x060EC8B0 + 2 * c, 2, [0, 0xFFFF, 0x10], 0.6) for c in range(0, 0x60)])
case("f06025E7E", [], True, TASKP + [plant(0x060D7E68, 2, [0, 64, 1], 1.0), plant(0x060C2100 + 10, 2, [0, 0x256, 0x257, 0x258], 1.0)])
_list = 0x060C2300
case("f0602620C", [], True, CURB + [plant(0x060C02CC, 4, [_list], 1.0), plant(0x060D7EB4, 2, [0, 1], 1.0), plant(0x060D7EB6, 2, [0, 1], 1.0)]
     + [plant(_list + 4 * k, 2, [0, 1, 2, 3, 0xFFFF], 0.9) for k in range(8)] + [plant(_list + 4 * k + 2, 2, [0, 1, 2, 3], 0.9) for k in range(8)]
     + recs(24, [0, 0x10, 0x20, 0x30], chance=1.0) + recs(28, [0, 0x10, 0x20, 0x30], chance=1.0))
case("f060262BC", [], True, CURB + [plant(0x060C02CC, 4, [_list], 1.0), plant(0x060C02D0, 4, [0x060C2400], 1.0),
                                    plant(0x060D7EB4, 2, [0, 1], 1.0), plant(0x060D7EB6, 2, [0, 1], 1.0)]
     + [plant(_list + 4 * k, 2, [0, 1, 2, 3, 0xFFFF], 0.9) for k in range(8)] + [plant(_list + 4 * k + 2, 2, [0, 1, 2, 3], 0.9) for k in range(8)]
     + recs(24, [0, 0x10, 0x20, 0x30], chance=1.0) + recs(28, [0, 0x10, 0x20, 0x30], chance=1.0)
     + [plant(0x060C2400 + 20 * k, 4, [0, 1, 2, 3, 0x0000FFFF], 0.8) for k in range(8)])
case("f060265B4", [pick(0, 1, 2)], True, TASKP + [plant(obj(3) + 26, 2, [0, 5, 100], 1.0)])
case("f060265D2", [], True, TASKP + [plant(0x060C029D, 1, [0, 1, 2, 3], 1.0), plant(0x060C02CC, 4, [0x060C2300], 1.0), plant(0x060C2300, 2, [0], 1.0)])
_near = recs(24, [0x100, 0x104, 0x120, 0x200], chance=1.0) + recs(28, [0x100, 0x104, 0x120, 0x200], chance=1.0)
case("f0602719C", [span(0, 5)], True, CURB + _near + [plant(0x060D7E88, 2, [0, 3, 0x20, 0xFFF0, 0x1000], 1.0)])
case("f06027206", [span(0, 5)], True, CURB + _near + [plant(0x060D7E8A, 2, [0, 3, 0x20, 0xFFF0, 0x1000], 1.0)])
case("f06027378", [], True, CURB + COUNT + recs(20, [0x20, 0x21, 0x22], chance=1.0))
case("f060273B6", [span(0, 80)], True, CURB + recs(56, [0, 3, 10, 24]) + TASKP)
_c = [plant(0x26006088 + k, 1, [0, 0x10, 240, 0x70], 0.7) for k in range(12)] + [plant(0x26006070 + 2 * k, 2, [0, 0xF000, 0x1234, 0xF123], 0.7) for k in range(12)]
case("f060291A8", [], False, _c + [plant(0x26006094, 1, [0, 5, 12], 1.0), plant(0x060C0AA4, 4, [0, 1], 1.0)]
     + [plant(0x060C0AB4 + 4 * k, 4, [0, 3, 7, 13, 2], 1.0) for k in range(3)] + [plant(0x060C0ABC + 2 * k, 2, [0, 1, 2], 0.5) for k in range(8)])
case("f060292E8", [], False, [plant(0x060C0AB4, 4, [0, 3, 5, 12], 1.0), plant(0x060C0AB8, 4, [0, 2, 20], 1.0)])
case("f06029FD2", [pick(4, 8, 0, 5), pick(-224, -222, -220, -215, 300), span(-300, 300), span(-300, 300)], True,
     [plant(SP, 4, [0, 5], 1.0), plant(SP + 4, 4, [0, 1, 0x12345], 1.0), plant(0x060EC450, 2, [1, 3], 1.0)])
case("f0602A2A8", [ptr(0x060C3000, 0x400, 4), ptr(0x060C3800, 0x400, 4), pick(-224, -222, -220, -218, -216, -215, -300, -1000, -448, -440),
                   pick(0, 0x10000, 0x20000)], False,
     [plant(0x060FA9A0, 2, [0, 192], 1.0), plant(0x060EC452, 2, [0, 1, 0x20], 1.0)])
case("f0602A618", [ptr(0x060C3000, 0x400, 4), span(0, 5), ptr(0x060C3800, 0x400, 4)], False, [plant(0x060FA9A0, 2, [0, 192], 1.0)])
case("f0602B86E", [span(-3, 15)], True, [plant(0x060C1040, 4, [0, 4], 1.0), plant(0x060C1044, 1, [0, 3, 10, 12, 0xF0], 1.0)]
     + [plant(0x060C0640 + k, 1, [0, 1, 2, 3, 4], 0.8) for k in range(12)] + [plant(0x060C064A + k, 1, [0, 1, 5, 9, 11, 12, 30], 0.8) for k in range(12)])
_bytes = [plant(0x060C0640 + k, 1, [0, 1, 2, 3, 4, 5, 7, 8], 0.8) for k in range(14)]
case("f0602C482", [span(0, 12)], True, _bytes)
case("f0602C4D8", [span(0, 12)], True, _bytes)
case("f0602C50C", [span(0, 6)], True, [])
case("f0602C5EE", [span(-2, 5)], True, [])
case("f0602D36E", [span(0, 20), span(-5, 400), span(-5, 400), span(-300, 300)], True,
     [plant(SP, 4, [0, 3, 0x10004], 1.0)] + [plant(0x060E20DE + 14 * k + 2 + 2 * j, 2, [0, 3, 4, 5], 0.7) for k in range(20) for j in range(5)]
     + [plant(0x060B522A + j, 1, [0, 3], 1.0) for j in range(5)])
case("f0602E2EA", [], True, [plant(0x060E1C4E + k, 1, [0, 0, 0, 0, 0, 1], 0.97) for k in range(8)])
case("f0602E836", [ptr(0x060C3000, 0x40, 4)], True, COUNT + [plant(0x26006134 + k, 1, [0, 1], 0.6) for k in range(6)] + recs(22, [0, 1], chance=0.7)
     + [plant(0x260060B0 + 2 * k, 2, [0, 0x800], 0.6) for k in range(6)])
case("f0602E932", [], True, COUNT)
case("f0602E970", [], True, COUNT)
# the Fall record 060C1658 points at (column, row, position, ids, count, step) and the 0603A614 helper's tables
FALLP = [plant(0x060C1658, 4, [0x060C2500], 1.0)]
FALLF = [plant(0x060C2500, 1, [0, 3, 9], 1.0), plant(0x060C2501, 1, [0, 2], 1.0), plant(0x060C2502, 2, [0, 5], 1.0), plant(0x060C2504, 2, [0, 2, 5], 1.0),
         plant(0x060C250A, 2, [0, 3, 5], 1.0), plant(0x060C250C, 2, [0, 4, 6], 1.0), plant(0x060C250E, 2, [0, 1, 3], 1.0),
         plant(0x060C2510, 2, [0, 0x100, 0xFF00], 1.0), plant(0x060C2512, 2, [0, 2, 0x20], 1.0)]
case("f0603840E", [ptr(0x060C3A00, 0x40, 2), span(0, 15)], False,
     [plant(0x060C3A00 + 2 * k, 2, [3, 5, 0, 0xFFFF, 9], 0.8) for k in range(16)])
case("f06038004", [span(0, 20)], True, FALLP + FALLF)
case("f06038BF0", [span(0, 150), span(0, 150), span(0, 150), span(0, 150)], False,
     [plant(SP, 4, [0, 0x1234], 1.0)] + [plant(0x060B1DF8 + 4 * k, 4, [0, 0xFF, 0xFFFFFFFF], 0.5) for k in range(9)])
case("f0603A466", [], True, FALLP + FALLF)
case("f0603A7A6", [], True, FALLP + FALLF)
case("f0603AA2C", [], True, FALLP + FALLF)
case("f0603B56C", [], True, TASKP + [plant(obj(3) + 68, 2, [0, 1, 5, 100], 1.0)])
_dirs = 0x060C3A80
# 0600CA6A turns an object's position into a cell (sixteen units each), and 0603E888 looks the cell up in a 9 by 7 table of walkable flags
_walk = [plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0)] + [plant(obj(k) + 16, 2, [0x200, 0x220, 0x240, 0x1F0], 1.0) for k in (3, 4)]
_walk += [plant(obj(k) + 18, 2, [0x130, 0x140, 0x150, 0x120], 1.0) for k in (3, 4)] + [plant(0x060B5E0A + k, 1, [0, 1, 1, 5], 1.0) for k in range(63)]
case("f0603E7AC", [ptr(_dirs, 4, 1), pick(3, 4)], True, _walk + [plant(_dirs + k, 1, [0, 1], 0.5) for k in range(8)])
case("f0603E930", [pick(0, 1, 2, 3)], True, ACT + actor(16, [0, 1, 255, 3], chance=0.9) + actor(4, [0, 1, 2, 3], size=2, chance=0.9)
     + actor(6, [0, 1, 2, 3], chance=0.9))
case("f0603E604", [], False, _walk + TASKP + [plant(0x060C2100 + 8, 2, [3, 4], 1.0), plant(0x060C2100 + 12, 2, [0, 1, 2, 3, 255], 1.0),
                                      plant(0x060C2100 + 14, 2, [0, 5, 64], 1.0), plant(0x060C2100 + 16, 2, [0, 5, 64, 128], 1.0),
                                      plant(0x060C2100 + 18, 2, [0, 1], 1.0)])
case("f0603FB16", [span(0, 5)], True, [])
case("f0603A3A0", [], True, [])
_cur = CURB + recs(22, [3, 4], chance=1.0) + recs(36, [0, 1, 2], chance=1.0) + recs(52, [0, 1, 2, 3], chance=1.0) + [plant(0x060C3820 + 84 * k - 4, 2, [0], 0.0) for k in range(1)]
_height = recs(56, [0, 30, 60, 100, 130, 144, 4, 70], chance=1.0)
case("f06042CFE", [], True, _cur + _height + recs(82, [6, 4, 0], chance=1.0))
case("f06042DC8", [], True, _cur + _height + recs(82, [6, 4, 0], chance=1.0))
case("f06044868", [], True, PALTAB + BANK + TILES + TASKP + [plant(0x060C2100 + 14, 2, [0, 1, 2], 1.0), plant(0x060C2100 + 16, 2, [0, 1], 1.0), plant(0x060C2100 + 10, 2, [0, 1], 1.0)]
     + [plant(0x060EC8B0 + 2 * c, 2, [0, 7, 8], 0.6) for c in range(3)])
case("f060448BC", [], True, TILES + TASKP + [plant(0x060C2100 + 16, 2, [0, 1], 1.0), plant(0x060C2100 + 18, 2, [0, 1, 2, 3], 1.0),
                                     plant(0x060C2100 + 10, 2, [0, 1, 2], 1.0), plant(0x060C2100 + 14, 2, [0, 1], 1.0)])
case("f06044A7E", [pick(5, 6, 7, 8)], True, COUNT + recs(20, [5, 6, 7], chance=1.0) + recs(4, [0, 0, 0x40], size=1, chance=1.0) + recs(46, [0, 0, 0x20], chance=1.0))
case("f06045974", [], True, TASKP + [plant(obj(3) + 60, 2, [0, 0xFEFF, 0xFF00, 0xFFFF], 1.0), plant(0x060C1754, 1, [0, 1, 2], 1.0)])
# 0600CA32 sets 060D7E88 and 060D7E8A to sixteen times the task's two halfwords, less the scroll at 060D82BA and 060D82BC
case("f06045B98", [span(1, 4)], True, TASKP + [plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0),
                                               plant(0x060C2100 + 16, 2, [0x0F, 0x10, 0x11], 1.0), plant(0x060C2100 + 14, 2, [0x0F, 0x10, 0x11], 1.0),
                                               plant(obj(3) + 16, 2, [0xF0, 0x100, 0x110], 1.0), plant(obj(3) + 18, 2, [0xF8, 0x108, 0x118, 0x100], 1.0)])
case("f06045E00", [], True, TASKP + [plant(0x060C1755, 1, [0, 1, 2], 1.0), plant(0x060D7E68, 2, [0, 0x1052, 1], 1.0)])
case("f06046174", [], False, TASKP + [plant(obj(3) + 16, 2, [0, 100], 1.0), plant(obj(3) + 18, 2, [0, 100], 1.0)])
# 06008A6A fills the bank table at 060BD8E4 from PALTAB's sources, so bank 9 is the table at 060C4000 and holds images: a header whose bytes 14 and 15 are the size, byte 17 the number of ranges, then (first, last) halfwords and the data
_img = 0x060C5200
case("f06030F0C", [span(0, 25), span(0, 3)], True, PALTAB + [plant(0x060C4000 + 4 * k, 4, [_img], 1.0) for k in range(4)]
     + [plant(_img + 14, 1, [8, 16, 20], 1.0), plant(_img + 15, 1, [4, 8], 1.0), plant(_img + 17, 1, [0, 1, 2, 3], 1.0)]
     + [plant(_img + 18 + 4 * k, 1, [0, 3, 6, 10], 1.0) for k in range(4)] + [plant(_img + 19 + 4 * k, 1, [0], 1.0) for k in range(4)]
     + [plant(_img + 20 + 4 * k, 1, [2, 5, 9, 14, 24], 1.0) for k in range(4)] + [plant(_img + 21 + 4 * k, 1, [0], 1.0) for k in range(4)])
case("f060436E8", [], True, PALTAB + BANK + BOXES + data(0x060B210A, [5, 6, 7, 15, 0xFFFF]) + [plant(0x060D7C70, 2, [0, 1], 1.0)])
case("f06043B78", [span(0, 5)], True, PALTAB + BANK + BOXES + [plant(slot(k) + 10, 2, [0, 3], 0.8) for k in range(6)])
case("f06043F48", [span(0, 5)], True, PALTAB + BANK + BOXES + [plant(slot(k) + 8, 2, [0, 3], 0.8) for k in range(6)])
case("f060442A0", [span(0, 5)], False, PALTAB + BANK + BOXES + [plant(slot(k) + 8, 2, [0, 3], 0.8) for k in range(6)])
case("f060483CC", [ptr(0x060C3A00, 8, 2)], False, PALTAB + BANK + data8(0x060B2278, [1, 29, 1, 28, 255, 255]) + data8(0x060B227E, [1, 32, 0, 16, 1, 32, 0, 184])
     + [plant(0x060C3A00 + 2 * k, 2, [3, 4, 5], 1.0) for k in range(4)])
case("f06049310", [ptr(0x060C3A00, 8, 2)], True, PALTAB + BANK + data8(0x060B2298, [0, 26, 0, 24, 0, 30, 0, 24])
     + [plant(0x060C3A00 + 160 + 2 * k, 2, [3, 4, 5], 1.0) for k in range(4)])
case("f06048C40", [ptr(0x060C3C00, 0x40, 1)], False, [plant(0x060C1048, 4, [0x800, 0x800, 0x800, 0x800, 0x800, 0x800, 0x800, 0x800, 0x800, 0x400], 1.0)]
     + [plant(0x060C0640 + k, 1, [0, 1, 2, 3, 4, 5, 6, 7, 8], 1.0) for k in range(10)])
case("f0605635C", [], False, PALTAB + SPRITES + BOXES)
case("f06057048", [span(0, 8)], True, [plant(0x060C0640 + k, 1, [0, 1, 2, 3, 4, 5, 7, 8], 0.8) for k in range(14)])
case("f06055644", [pick(0, 0x1000, 0x2000), span(0, 3), pick(0, 1, 2)], True, [plant(0x060C1844 + k, 1, [0, 5, 6], 0.7) for k in range(3)])
case("f0605548C", [pick(0, 1, 5)], False, PALTAB + BANK + [plant(0x060C17B6, 1, [255, 0], 0.6)])
case("f060495B6", [span(0, 5)], False, PALTAB + BANK + [plant(0x060C1048, 4, [0x400, 0, 0xC00], 1.0)]
     + [plant(0x060C0640 + k, 1, [0, 1, 2, 3], 0.8) for k in range(10)])
case("f0604D7F4", [], False, [plant(0x060C1040, 4, [0, 0x10, 0x20, 0x70], 1.0)])
_o = obj(3)
case("f0602277C", [], False,
     [plant(0x060D7E68, 2, [0, 0, 0, 16], 1.0), plant(0x060DFDF6, 2, [0, 3, 3, 3], 1.0), plant(0x060DFDF8, 2, [0, 1, 2], 1.0)]
     + recs(42, [0, 5, 5, 5], chance=1.0) + recs(4, [0, 0x80, 0, 0], size=1, chance=1.0) + recs(6, [4, 0, 1], size=1, chance=1.0)
     + [plant(0x060DFDFE, 2, [0, 1, 1, 1], 1.0), plant(0x060DFDFA, 2, [0, 0, 1], 1.0),
        plant(0x060DFDFC, 2, [0, 3, 5, 50, 99, 100, 150, 199, 200, 250], 1.0)]
     + [plant(_o + 16, 2, [0x100], 1.0), plant(_o + 18, 2, [0x100], 1.0), plant(_o + 20, 2, [0x100, 0x100, 0x100, 0x180], 1.0),
        plant(_o + 24, 2, [0x117, 0x117, 0x117, 0x190], 1.0), plant(_o + 22, 2, [0xF1, 0xF1, 0xF1, 0x180], 1.0), plant(_o + 26, 2, [0x108, 0x108, 0x108, 0x190, 12], 1.0),
        plant(_o + 36, 2, [0, 4, 0xFFFC], 0.8), plant(_o + 38, 2, [0, 4, 0xFFF1], 0.8), plant(_o + 42, 2, [0, 32, 0xFFDF], 0.8)]
     # 0606AA58 and 0606AA90 walk the objects linked through the halfword at +8 until one numbered 1
     + [plant(0x060C381C + 8, 2, [1, 3, 4], 1.0)] + [plant(obj(k) + 8, 2, [1, k + 1 if k < 7 else 1, 1], 1.0) for k in range(2, 8)])
# a bank's script: a list of record pointers ended by -1, and each record's first halfword says what it does
_list = 0x060C4400
_recs = 0x060C4500
case("f060095E0", [span(0, 3)], True,
     [plant(0x060BD8E4 + 4 * k, 4, [_list], 1.0) for k in range(4)]
     + [plant(_list + 4 * k, 4, [_recs + 32 * k, _recs + 32 * k, _recs + 32 * k, 0xFFFFFFFF], 0.9) for k in range(16)]
     + [plant(_recs + 32 * k, 2, [0, 3, 4, 5, 7, 0, 3, 4, 5, 1, 2, 6], 1.0) for k in range(16)]
     + [plant(_recs + 32 * k + 2, 2, [0, 1, 2, 5], 1.0) for k in range(16)])
# the name of each 24-byte entry at 060BF198 is at +12 ("A.BIN"), and the filters are lists of extensions like ".BIN.TXT"; strtok runs on a copy of eight bytes, so every string ends early
_names = [plant(0x060BF198 + 24 * k + 12, 4, [0x412E4249, 0x422E5458, 0x43000000, 0x442E4441, 0, 0x412E4249], 0.9) for k in range(32)]
_names += [plant(0x060BF198 + 24 * k + 16, 4, [0x4E000000, 0x54000000, 0], 0.9) for k in range(32)]
_names += [plant(0x060BF198 + 24 * k + 20, 4, [0], 1.0) for k in range(32)]
_filters = [(0x060C3A00, [0x2E42494E, 0]), (0x060C3A10, [0x2E545854, 0]), (0x060C3A20, [0x2E42494E, 0x2E545854, 0]), (0x060C3A30, [0x2E444154, 0])]
_fplants = [plant(a + 4 * i, 4, [w], 1.0) for a, ws in _filters for i, w in enumerate(ws)]
case("f06008C7A", [ptr(0x060C3400, 0x40, 4), pick(*[a for a, _ in _filters])], True,
     _names + _fplants + [plant(0x060B1AC4, 4, [0x2E00FFFF], 1.0)])
_t = 0x060C2100
# 060092D4 takes a free entry of the table at 060CE060 and reads its record through bank 3
ALLOC = [plant(0x060BF4A4, 4, [0, 1], 1.0), plant(0x060BD8F0, 4, [0x060C4300], 1.0)] + [plant(0x060C4300 + 4 * k, 4, [0x060C4400], 1.0) for k in range(8)]
ALLOC += [plant(0x060C4400, 4, [0, 0x01000000, 0x00030000], 1.0), plant(0x060C4404, 4, [0], 1.0)]
ALLOC += [plant(0x060CE060 + 16 * k + 11, 1, [0, 1], 0.5) for k in range(16)]
case("f0605DA58", [pick(0, 1)], True, TASKP + PALTAB + BANK + ALLOC + [plant(_t + 18, 2, [255, 255, 255, 3, 20], 1.0), plant(_t + 20, 2, [0, 1, 2], 1.0)])
case("f0605D980", [], True, TASKP + PALTAB + BANK + ALLOC + [plant(0x060C191A, 1, [0, 1, 2], 1.0), plant(_t + 20, 2, [0, 1, 2], 1.0), plant(_t + 18, 2, [255, 255, 1, 3], 1.0)])
case("f0605F92C", [], True, KEYS + TASKP + [plant(0x26006096, 2, [0, 0x200, 0x400, 0x1400, 0x2400, 0x8400, 0x4400, 0x40, 0x1040, 0x2040, 0x8040, 0x4040], 1.0),
                                       plant(0x060C1914, 4, [0, 0x10000], 1.0), plant(0x060C033C, 4, [0, 0, 0x20000], 1.0), plant(0x060C0F82, 1, [0, 1, 128, 129], 1.0), plant(0x060C3000, 4, [0], 1.0)]
     + [plant(_t + o, 2, [0, 5, 16, 0xFFF0], 1.0) for o in (10, 12, 14, 16)])
case("f0605AE92", [], False, [plant(0x060C1048, 4, [0, 0x01000000, 0x01000000], 1.0)] + PALTAB + BANK)
case("f0605DF9C", [], True, TASKP + [plant(0x060C2100 + 12, 2, [0, 1, 2, 3], 1.0), plant(0x060C2100 + 14, 2, [0, 1], 1.0), plant(0x060C2100 + 10, 2, [0, 1, 5, 0x7FFF], 1.0),
                                       plant(obj(3) + 38, 2, [0, 5, 0xFFF0, 0x7FFF], 1.0), plant(obj(3) + 14, 2, [0, 0x1234, 0xFFFF], 1.0)])
case("f06037E38", [], True, PALTAB + BANK + FALLP + FALLF + [plant(0x060C2514, 4, [0, 1, 5], 1.0), plant(0x060C1668, 1, [0, 3], 1.0)])
case("f060616B8", [], True, TASKP + recs(36, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 255], chance=1.0) + recs(46, [0x808, 0, 0x800], chance=1.0)
     + [plant(_t + 8 + 2 * k, 2, [3, 4, 5, 6, 7], 1.0) for k in range(6)])
case("f06034D20", [ptr(0x060C3A00, 0x20, 1)], False, [plant(0x060C0640 + k, 1, [0, 1, 2, 3, 4, 5, 7, 8], 1.0) for k in range(14)]
     + [plant(0x060C0672 + 2 * k, 2, [0, 1, 5], 0.8) for k in range(6)])
case("f06061B64", [span(0, 8)], False, PALTAB + BANK)
# the sorted list of keyed nodes at 060C104C: byte 0 is the previous node, byte 1 the next, the word at 4 the key; 060C1244 counts them
_node = 0x060C104C
case("f06031C3C", [pick(0, 1, 2, 3, 4, 7), pick(0, 1, 2, 3, 4, 5, 10)], True,
     [plant(0x060C1244, 1, [0, 1, 2, 3, 4, 5], 1.0)]
     + [plant(_node + 16 * k, 1, [max(k - 1, 0)], 1.0) for k in range(8)] + [plant(_node + 16 * k + 1, 1, [(k + 1) % 5], 1.0) for k in range(8)]
     + [plant(_node + 16 * k + 4, 4, [k, k, k + 2], 0.9) for k in range(8)])

_lo = 0x060C3B00
case("f060618E0", [pick(bomber(0), bomber(1), bomber(2)), ptr(0x060C3A00, 0x20, 2), pick(_lo), pick(_lo + 16)], False,
     [plant(bomber(i) + 20, 2, [2752, 2760, 100, 2815], 1.0) for i in range(3)] + recs(22, [3, 4], chance=1.0)
     + [plant(obj(3) + 16, 2, [5, 10, 50], 1.0), plant(obj(4) + 16, 2, [5, 10, 50], 1.0)]
     + [plant(_lo + 2 * k, 2, [0, 5, 100, 0xFFFB], 1.0) for k in range(6)] + [plant(_lo + 16 + 2 * k, 2, [10, 20, 200], 1.0) for k in range(6)])
# 0602E88E finds an empty slot whose halfword at 06006096 has all of 0x70 set; 0602F648 counts the byte at 060C101A down
_blink = [plant(0x06006134 + i, 1, [0, 0, 1], 0.9) for i in range(10)] + [plant(0x06006096 + 2 * i, 2, [0x70, 0x7F, 0], 0.7) for i in range(10)]
_blink += [plant(0x060C101A, 1, [0, 1, 2], 1.0), plant(0x060C0FF4, 2, [3, 4, 5], 1.0)] + [plant(0x060C0FF4 + 2 * k, 2, [3, 4, 5], 1.0) for k in range(4)]
case("f0602FCCE", [], True, _blink)
case("f06030928", [], True, _blink)
_menu = [plant(0x060C122C, 1, [0, 1, 2, 31, 40], 1.0)] + [plant(POINTS + 24 * k, 2, [21, 22, 5, 0x1215], 1.0) for k in range(4)] \
    + [plant(POINTS + 24 * k + 2, 2, [0, 1, 2], 1.0) for k in range(4)]
case("f0605AFD8", [], True, _menu)
case("f0605B032", [], True, _menu)
# 06059E62 reads the pad at 260060B0 (260060B4 for the second pad, which counts only when 060C0AA8 is 2)
case("f06059D9C", [], False, PALTAB + BANK + [plant(0x260060B0, 2, [0, 0x1000, 0x2000, 0x1E00, 0x0200, 0x3000], 1.0), plant(0x260060B4, 2, [0, 0x1000, 0x2000, 0x1E00, 0x0200, 0x3000], 1.0),
                                               plant(0x060C0AA8, 4, [2, 2, 0], 1.0), plant(0x060C18E2, 1, [0, 0x80, 0x10, 0x81, 0x40], 1.0),
                                               plant(0x060C18E3, 1, [0, 0x80, 0x10, 0x81, 0x40], 1.0)])
# 0605F0A6 looks for a slot (from 060D7B60, 24 bytes each) whose object stands in the bomber's cell, with a tag from 88 to 95
_cell = [plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0)] + [plant(obj(k) + 16, 2, [0x210], 1.0) for k in (3, 4)] \
    + [plant(obj(k) + 18, 2, [0x140], 1.0) for k in (3, 4)] + [plant(obj(k) + 50, 2, [88, 95, 0, 96], 1.0) for k in (3, 4)]
case("f0605F16E", [span(0, 2)], False, TASKP + _cell + recs(20, [1249, 1248, 1249, 1313], chance=1.0)
     + [plant(0x060D7B60 + 24 * k + 8, 2, [3, 4, 0], 1.0) for k in range(4)] + [plant(0x060D7B60 + 24 * k + 12, 2, [0, 1, 2], 1.0) for k in range(4)]
     + [plant(0x060D7B60 + 24 * k + 14, 2, [0, 0, 1], 1.0) for k in range(4)])

# 0600CA32 puts 060D7E88 at sixteen times the first halfword and 060D7E8A at sixteen times the second, plus 24
case("f06061CE0", [], True, [plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0), plant(0x060D7B80, 2, [3, 4], 1.0),
                             plant(0x060D7B86, 2, [0x10, 0x11], 1.0), plant(0x060D7B88, 2, [0x10, 0x11], 1.0)]
     + [plant(obj(k) + 16, 2, [0x100, 0x110], 1.0) for k in (3, 4)] + [plant(obj(k) + 18, 2, [0x118, 0x128, 0x100], 1.0) for k in (3, 4)]
     + [plant(0x060D7B78 + 20, 2, [0, 1], 1.0)])
# the 24-byte point records at 060EC478: tag at 0, a link to another record at 4, a word at 12 (-1 for a free one), a flag byte at 22
case("f06036778", [span(0, 6)], False, PALTAB + BANK + [plant(POINTS + 24 * k, 2, [0, 1, 2, 3, 4], 1.0) for k in range(30)]
     + [plant(POINTS + 24 * k + 4, 2, [255, 255, 255, 5, 6], 1.0) for k in range(30)] + [plant(POINTS + 24 * k + 12, 4, [0xFFFFFFFF, 0, 0, 5], 0.8) for k in range(30)]
     + [plant(POINTS + 24 * k + 18, 2, [0, 0, 5], 1.0) for k in range(30)] + [plant(POINTS + 24 * k + 22, 1, [0, 1, 1], 1.0) for k in range(30)])
# 06037D02 finds the point record that 0603666E names (tag, kind, 255) and a fall record whose callback word at 20 is 0
_alloc = [plant(POINTS + 24 * k, 2, [20, 21, 22, 21], 1.0) for k in range(30)] + [plant(POINTS + 24 * k + 2, 2, [2, 1, 3, 5, 8], 1.0) for k in range(30)]
_alloc += [plant(POINTS + 24 * k + 4, 2, [255], 1.0) for k in range(30)] + [plant(POINTS + 24 * k + 12, 4, [0, 5, 0xFFFFFFFF], 1.0) for k in range(30)]
_alloc += [plant(0x060EC748 + 24 * k + 20, 4, [0, 0, 5], 1.0) for k in range(15)] + [plant(0x060C165C, 4, [0x060C2600], 1.0), plant(0x060C2600 + 20, 2, [0, 5], 1.0)]
case("f0605B14C", [], False, _alloc + PALTAB + BANK)
case("f0605B1FA", [], True, _alloc + PALTAB + BANK)
case("f06060038", [span(0, 3)], False, recs(4, [0, 0, 0x80], size=1, chance=1.0, n=10) + recs(20, [0, 1, 2, 3], chance=1.0, n=10) + recs(36, [255, 255, 0, 1], chance=1.0, n=10))

case("f06058EA0", [], False, PALTAB + BANK + [plant(0x26006134 + k, 1, [0, 1], 0.9) for k in range(6)] + [plant(0x060C0AA8, 4, [2, 0], 1.0)])
