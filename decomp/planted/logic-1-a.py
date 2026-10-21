from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

CURRENT = 0x060D7768
CUR_OBJ = 0x060D7B3C
SLOT_NOW = 0x060D7E60
SLOT_OBJ = 0x060D7E64
FLAGS = 0x060EC8B0
DISTS = 0x060EE8B0


def current(extra=()):
    """The four pointers the kernel keeps at the record being run, so that a trial gets past the first dereference."""
    return [plant(CURRENT, 4, [bomber(0), bomber(1), bomber(2)], 1.0), plant(CUR_OBJ, 4, [obj(3), obj(4)], 1.0),
            plant(SLOT_NOW, 4, [slot(3), slot(4)], 1.0), plant(SLOT_OBJ, 4, [obj(3), obj(4)], 1.0)] + list(extra)


def field(offset, size, values, chance=0.8, records=(0, 1, 2)):
    """The value at offset of the first bomber records."""
    return [plant(bomber(i) + offset, size, values, chance) for i in records]


def cells(values, which=range(0, 12), chance=0.7):
    """Halfwords of the cell flags table."""
    return [plant(FLAGS + 2 * c, 2, values, chance) for c in which]


case("f06006626", [ptr(0x060C0100, 0x100, 2), span(0, 0xFFFF), pick(-2, -1, 0, 1, 2, 3, 8, 0x1FE, 0x40, 0x7F)], True)
case("f0600687A", [span(-2, 19)], False,
     [plant(0x060BC190 + 88 * k + 82, 1, [255, 255, 0, 1, 2, 3], 0.7) for k in range(18)]
     + [plant(0x060BC190 + 88 * k + 80, 1, [0, 1, 2], 0.7) for k in range(18)]
     + [plant(0x060BC190 + 88 * k + 81, 1, [4, 4, 0], 0.6) for k in range(18)]
     + [plant(0x060BC190 + 88 * k + 83, 1, [0, 1, 1, 2], 0.7) for k in range(18)])
case("f0600996A", [pick(0, 1, 2, 3, 5, 0x100)], True, [plant(0x060BF4D8, 4, [0, 1, 2, 3, 5, 0x100], 0.6)])
case("f06009BFE", [], False, [plant(0x060BF4D4, 1, [0, 1])])
case("f06009E48", [], False, [plant(0x060B2E84, 1, [2, 2, 2, 0, 1]), plant(0x060B2E85, 1, [0, 1]), plant(0x060BF4E4, 4, [0, 0x060C0100])])
case("f06009E7E", [], False, [plant(0x060B2E84, 1, [2, 2, 2, 0, 1]), plant(0x060B2E85, 1, [0, 1, 1]), plant(0x060BF4E4, 4, [0, 0x060C0100])])
case("f06009EDA", [], True, [plant(0x060BF4E4, 4, [0x060C0100, 0, 0x060C0100]), plant(0x060C0100, 4, [0x060C0200]),
                             plant(0x060C0234, 4, [5, 5, 7, -1])])
case("f0600A570", [pick(1, 2, 4, 8, 16, 32, 0, 3, 64, -1)], True,
     [plant(0x060FA9C8 + 2 * k, 2, [0, 1, 0x8000, 0x8001, 0x100, 0x10, 0xFFFF], 0.8) for k in range(12)])
case("f0600A63E", [pick(1, 2, 4, 8, 16, 32, 0, 3, 64, -1)], True,
     [plant(0x060FA9C8 + 2 * k, 2, [0, 1, 0x100, 0x200, 0x300, 0x1000, 0x2000, 0x3000, 0x40, 0xFFFF], 0.8) for k in range(24)])
case("f0600ABA4", [pick(1, 2, 4, 8, 16, 32, 0), span(0, 0x3FF), span(0, 0x3FF)], True,
     [plant(0x060FA9C8 + 2 * k, 2, [0, 1, 0x100, 0x200, 0x300, 0x1000, 0x2000, 0x3000, 0x40, 0xFFFF], 0.8) for k in range(24)])
case("f0600C8C6", [], False, [plant(0x060D7E70, 2, [0, 0, 1]), plant(0x060D7E94, 4, [0x060D0000], 0.6)]
     + [plant(FLAGS + 0x80 * k, 2, [0, 16, 0x10, 0xFFFF], 0.5) for k in range(64)])
case("f0600C8E0", [], False, [plant(0x060D7E72, 2, [0, 0, 1]), plant(0x060D7E94, 4, [0x060D0000], 0.6)]
     + [plant(FLAGS + 0x80 * k, 2, [0, 16, 0x10, 0xFFFF], 0.5) for k in range(64)])
case("f0600CAA4", [], False, current())
case("f06011046", [], True, current(field(46, 2, [0, 0x800, 0x800]) + field(36, 2, [0, 1, 2, 3])
                                    + [plant(bomber(i) + 52, 2, [0, 1, 2, 5], 0.9) for i in range(5)]))
case("f060149E0", [span(0, 6)], False, current(field(22, 2, [3, 4, 5]) + field(20, 2, [0, 1, 2, 5]) + cells([0, 0x1000], range(6))))
case("f06014B0A", [], False, current(field(68, 2, [0, 1, 5])))
case("f06014BD2", [], False, current([plant(0x060C029C, 1, [0, 5, 6, 7, 8], 0.9)]))
case("f06015CD2", [], False, current())
case("f0601ADA6", [], False, current([plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0)] + field(36, 2, [0, 1, 2, 3]) + field(62, 2, [0, 1, 2, 3])))
case("f0601AE4C", [], False, current([plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0)] + field(36, 2, [0, 1, 2, 3]) + field(62, 2, [0, 1, 2, 3])))
case("f0601B068", [span(0, 3), span(0, 4)], True,
     current([plant(0x060C029C, 1, [0, 1, 8, 9, 12], 0.6)] + field(52, 2, [0, 1, 2, 3])
             + [plant(0x060D82DC + 4 * k, 4, [0, 1, 100, 3000, 100000, 0x7FFFFFFF, 0xFFFFFFFF], 0.9) for k in range(20)]))
case("f0601B4F8", [], False, current([plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0)] + field(36, 2, [0, 1, 2, 3]) + field(62, 2, [0, 1, 2, 3])))
case("f0601B662", [], False, current(field(36, 2, [0, 1, 2, 3]) + field(62, 2, [0, 1, 2, 3])))
case("f0601BF94", [pick(0, 1, 2, 5)], False, current([plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0)] + field(46, 2, [0, 0x800, 0x800])
                                                     + field(36, 2, [0, 1, 2, 3]) + field(88, 2, [0, 1])))
case("f0601DAD0", [], False, [plant(0x060D8C08, 4, [0x060D849C + 38 * k for k in range(5)], 1.0)])
case("f0601DB2E", [], False, [plant(0x060DF96C, 4, [0x060D8C0C + 14 * k for k in range(5)], 1.0)])
case("f0601E3B2", [], False, [plant(0x060DF96C, 4, [0x060D8C0C + 14 * k for k in range(5)], 1.0)]
     + [plant(0x060D8C0C + 14 * k + o, 2, [0, 1, 2, 3, 4], 0.9) for k in range(5) for o in (2, 4)])


def slots(offset, size, values, chance=0.9, which=(3, 4)):
    """The value at offset of the slots the kernel runs."""
    return [plant(slot(k) + offset, size, values, chance) for k in which]


def objects(offset, size, values, chance=0.9, which=(3, 4)):
    return [plant(obj(k) + offset, size, values, chance) for k in which]


case("f0600D600", [span(0, 20), pick(0, 5, 100, 0x200, 0xFFF0, 7, 0x1F0), pick(0, 5, 100, 0x200, 0xFFF0, 7, 0x1F0)], True,
     [plant(0x060D82BA, 2, [0, 5, 100, 0x200, 0xFFF0, 7], 0.9), plant(0x060D82BC, 2, [0, 5, 100, 0x200, 0xFFF0, 7], 0.9)])
case("f0600E096", [], True,
     current([plant(0x060D5F44, 2, [0x44E, 0x44E, 0, 5]), plant(0x060D5F48, 2, [0, 4, 8, 12, 0xFFFC, 0xFFF4, 3, 11]),
              plant(0x060D5F4C, 2, [0, 4, 8, 12, 0xFFFC, 0xFFF4, 3, 11]), plant(0x060D7E68, 2, [0, 0x40, 0x41, 0])]
             + objects(60, 2, [0xFF00, 0xFF00, 0, 5]) + [plant(0x060D5F46, 2, [3, 4, 5])]))
case("f0600E94C", [], True, current(slots(12, 2, [0, 1, 2, 5]) + slots(14, 2, [0, 1, 5, 9]) + slots(10, 2, [0, 1, 3, 5, 9]) + slots(16, 2, [0, 0, 1, 5])))
case("f0600E960", [], True, current(slots(12, 2, [0, 1, 2, 5]) + slots(14, 2, [0, 1, 5, 9]) + slots(10, 2, [0, 1, 3, 5, 9]) + slots(16, 2, [0, 0, 1, 5])))
case("f0600E974", [], True, current(slots(18, 2, [0, 1, 5]) + slots(12, 2, [0, 1, 2, 5]) + slots(14, 2, [0, 1, 5, 9]) + slots(10, 2, [0, 1, 3, 5, 9])
                                    + slots(16, 2, [0, 0, 1, 5]) + [plant(0x26006034, 4, [0, 4, 8, 12, 1]), plant(0x060C029D, 1, [0, 1, 2, 5])]))
case("f0600F104", [], True, current([plant(0x060C02A1, 1, [0, 1, 2, 2, 3])] + objects(46, 2, [0, 0xF, 0xFF, 0x10, 0x1000, 0xFFFF, 0x7, 0x8])
                                    + objects(16, 2, [0, 100, 0x170, 0x171, 0x200, 0xFFD0])))
case("f0600F272", [], True, current([plant(0x060C02A1, 1, [0, 1, 2]), plant(0x060FAA20, 4, [0, 0x00400000, 0x7FFFFFFF, 0x00300000, 0xFFFFFFFF])]
                                    + objects(18, 2, [0, 100, 104, 105, 200, 0xFF00])))
case("f0600F1C6", [], True, current([plant(0x060C02A1, 1, [0, 1, 2, 3])]))

FIX = 0x060C0100
GOOD = (field(42, 2, [0, 0, 0, 32]) + field(46, 2, [0, 0, 0, 0x32D, 0x800, 1]) + field(40, 2, [0, 1, 5, 100]) + field(62, 2, [0, 5, 100, 200])
        + field(20, 2, [0, 1, 2, 3]) + cells([0, 0, 0x42F0, 1, 0x8000]))

case("f0601051E", [], True,
     current(slots(10, 2, [0, 0, 1, 5]) + [plant(bomber(i) + 4, 1, [2, 2, 0x82, 0x80, 0, 1, 3, 0xA2]) for i in range(8)]
             + [plant(0x060C0360 + 32 * i + 24, 1, [0, 1, 2, 3, 4, 5, 6, 7]) for i in range(8)] + [plant(0x060C063D, 1, [0, 1, 2, 3, 5, 8, 9])]))
case("f06010EEE", [], False,
     [plant(0x060C04CC, 2, [0, 1, 2, 5]), plant(0x060C04C8, 2, [0, 0, 1, 3, 9]), plant(0x060C04C5, 1, [0, 0, 1, 5]),
      plant(0x060C04CA, 2, [0, 1, 2, 5, 9]), plant(0x060C04D2, 2, [0, 5])])
case("f060119E8", [], True, current(GOOD))
case("f06011F98", [pick(FIX), span(0, 5)], True,
     current(GOOD + field(64, 2, [0x100, 0x300, 0x100, 0x200, 0]) + field(62, 2, [0, 5, 100, 200]) + field(40, 2, [0, 1, 5, 100])))
case("f0601227E", [pick(FIX), span(0, 5)], True,
     current(GOOD + field(64, 2, [0x200, 0x300, 0x200, 0x100, 0]) + field(62, 2, [0, 5, 100, 200]) + field(40, 2, [0, 1, 5, 100])
             + field(46, 2, [0, 0, 0, 0x32D, 1])))
case("f06011CBA", [pick(FIX)], False,
     [plant(0x060C04D8, 2, [0, 1, 2, 3]), plant(0x060C04D0, 2, [0, 5]), plant(0x060C04DC, 2, [0, 0, 1, 0x80]), plant(0x060C04CA, 2, [0, 1, 5, 15]),
      plant(0x060C04CC, 2, [0, 1, 2]), plant(0x060C04DA, 2, [0, 1, 5, 20]), plant(0x060C04C5, 1, [0, 1, 5]), plant(0x060C04A2, 1, [0, 1, 5]),
      plant(FIX + 25, 1, [0, 1, 5])]
     + [plant(0x060F08B0 + 2 * i, 2, [0, 1, 2, 3, 4], 0.9) for i in range(4)] + [plant(0x060DFB9B + 8 * k, 1, [16, 10, 26, 0, 5, 7], 0.8) for k in range(5)]
     + [plant(DISTS + 2 * i, 2, [0, 0x100, 0x200, 0xF00, 0x0F00, 0x500, 0x1000], 0.9) for i in range(4)]
     + cells([0, 0, 0x1000, 1, 0x80], range(4)))
case("f060127CA", [pick(FIX)], True,
     current(field(46, 2, [0x800, 0x800, 0x800, 0, 0x801]) + field(42, 2, [0, 0, 0, 1]) + field(36, 2, [0, 1, 2, 3])
             + [plant(bomber(i) + 64, 2, [1, 2, 3, 4, 5, 0], 0.9) for i in range(5)]
             + [plant(0x060C04CA, 2, [0, 1, 5, 6, 13, 14, 20]), plant(FIX + 25, 1, [0, 1, 5])] + field(6, 1, [0, 1, 2, 3])
             + field(20, 2, [0, 1, 2, 3]) + cells([0, 0x20, 0x20, 1], range(16))
             + [plant(0x060C04A2 + k, 1, [0, 1, 2, 3, 5]) for k in range(3)]))
case("f06012AF4", [pick(FIX)], True,
     current(GOOD + [plant(0x060C04CA, 2, [0, 0, 0, 1])] + field(64, 2, [0x100, 0x300, 0x100, 0]) + field(62, 2, [0, 5, 100, 200])
             + [plant(0x060C04A2 + k, 1, [0, 1, 2, 3, 5]) for k in range(3)]))
case("f0601329E", [pick(FIX)], True,
     current(field(46, 2, [0, 0, 0, 1, 0x800]) + [plant(0x060C04CC, 2, [0, 1, 2, 5, 9], 0.9)]))
case("f06013470", [], False,
     [plant(0x060C04D8, 2, [0, 1, 2, 3, 4, 5]), plant(0x060C04C5, 1, [0, 1, 5, 0xFF]), plant(0x060C04CA, 2, [0, 1, 5]),
      plant(0x060C04D0, 2, [0, 1]), plant(0x060C04DC, 2, [0, 0, 1, 0x80]), plant(0x060C04CC, 2, [0, 1, 2]), plant(0x060C04DA, 2, [0, 1, 5, 20])]
     + [plant(FLAGS + 2 * i, 2, [0, 0x10, 0x10, 0x12, 0x17, 0x1000, 1, 0x80], 0.9) for i in range(6)]
     + [plant(DISTS + 2 * i, 2, [0, 0x100, 0x200, 0xF00, 0x0100, 0x500], 0.9) for i in range(6)])
case("f06013554", [pick(FIX)], True,
     current([plant(0x060C029C, 1, [17, 17, 17, 0, 5]), plant(0x060D7EB6, 2, [0, 1, 5, 20, 100, 200, 0xFFFF]),
              plant(0x060D7E7E, 2, [0, 1, 5, 20]), plant(0x060D7E82, 2, [10, 50, 100, 190, 300])]))

case("f06013C88", [], False,
     [plant(0x060C0AA8, 4, [0, 1, 5], 0.9), plant(0x060C051C, 4, [0, 1, 1, 2, 3, 4, 5], 0.9),
      plant(0x060C0520, 4, [0, 1, 5, 0x3FF, 0x400, 0x401, 0x800, 149, 150, 151], 0.9), plant(0x060C0514, 4, [0x060C1000, 0x060C1400]),
      plant(0x060C0518, 4, [0x060C2000, 0x060C2400])])
case("f060153BC", [], False,
     current(field(46, 2, [0, 0x2000, 0x2000]) + [plant(0x060D7E68, 2, [0, 1, 0, 3]), plant(0x060BF5EA, 2, [0, 1, 0, 7]), plant(0x060C062C, 2, [0, 1, 2, 3])]))
case("f06015D8A", [], True,
     current(field(42, 2, [0, 1, 2, 3, 0]) + field(46, 2, [0, 0x400, 0x10, 0, 0x410]) + field(36, 2, [0, 1, 2]) + field(56, 2, [0, 1, 2, 5])
             + field(10, 2, [0, 0x2000, 0xFFFF, 0x8000]) + field(12, 2, [0, 1, 2, 3, 4, 5, 0xFFFF]) + field(14, 2, [0, 0x1000, 0xFFFF, 0x8000])
             + [plant(bomber(k) + 52, 2, [0, 1, 2, 3], 0.9) for k in range(4)] + [plant(0x060C067E, 2, [0, 1, 2, 3])]))
case("f060162D0", [], True,
     current(field(18, 2, [0x1000, 0x2000, 0x8000, 0xFFFF, 1, 0xF]) + field(20, 2, [0, 1, 2, 5, 70, 100]) + cells([0xFFFF, 0, 0x1000, 0x2000, 0x8000, 0xF], range(0, 200, 1), 0.5)))
case("f06016908", [], False,
     current(field(68, 2, [0, 0, 10, 29, 30, 31, 89, 90, 100, 0x185, 0x186, 500]) + field(84, 2, [0, 0, 1, 2, 29, 30, 119, 120, 121, 200])
             + field(72, 2, [0, 0, 1, 2, 8, 29, 30, 119, 120, 121]) + field(38, 2, [0, 0, 1, 2, 8, 29, 30, 119, 120, 121])
             + field(44, 2, [0, 0, 1, 2, 8, 29, 30, 119, 120, 121]) + field(46, 2, [0, 0x32D, 0x400, 1]) + field(4, 1, [0, 0x20, 0xFF, 0x50])))
case("f0601393A", [pick(FIX)], True,
     current([plant(FIX + 30, 1, [0, 1, 2, 3]), plant(0x060C04CA, 2, [0, 1, 5, 6])] + field(20, 2, [0, 1, 2, 3, 64, 65])
             + [plant(FLAGS + 2 * i, 2, [0, 0xFFFF, 0x1000, 1], 0.5) for i in range(0, 200)]
             + [plant(DISTS + 2 * i, 2, [0, 0xFFFF, 0x1000, 1, 0x100], 0.5) for i in range(0, 200)]))
case("f06017E70", [span(-2, 8), pick(1, 2, 3, 4, 0, 5), pick(0, 1, 2, 3)], True,
     current(field(22, 2, [3, 4, 5])
             + [plant(0x060D7EB4, 2, [0, 3, 8, 9, 10, 11, 98, 99, 100, 101, 102, 0xFFF8], 0.9), plant(0x060D7EB6, 2, [0, 3, 8, 9, 10, 11, 98, 99, 100, 101, 102, 0xFFF8], 0.9),
                plant(0x060D7E80, 2, [0, 5, 10, 100], 0.9), plant(0x060D7E82, 2, [0, 5, 10, 100], 0.9), plant(0x060D7E7C, 2, [0, 1, 2, 3, 5, 10, 0xFFFF], 0.9),
                plant(0x060D7E7E, 2, [0, 1, 2, 3, 5, 10, 0xFFFF], 0.9)]))
case("f06019836", [pick(0, 1, 2, 3, 4)], True,
     current(field(18, 2, [0, 1, 0x1000, 0xFFFF]) + [plant(0x060D7E8C, 2, [0, 1, 2, 3])] + cells([0, 1, 0x1000, 0xFFFF], range(8))
             + [plant(0x060D7EB4, 2, [0, 3, 8, 9, 10, 98, 99, 100, 101, 102], 0.9), plant(0x060D7EB6, 2, [0, 3, 8, 9, 10, 98, 99, 100, 101, 102], 0.9),
                plant(0x060D7E80, 2, [0, 5, 10, 100], 0.9), plant(0x060D7E82, 2, [0, 5, 10, 100], 0.9), plant(0x060D7E7C, 2, [0, 1, 2, 3, 5, 10], 0.9),
                plant(0x060D7E7E, 2, [0, 1, 2, 3, 5, 10], 0.9)] + field(22, 2, [3, 4, 5])))
case("f06017DC0", [], False,
     current(field(60, 2, [0, 3, 4, 5]) + field(22, 2, [3, 4, 5]) + [plant(0x060C062C, 2, [0, 1, 2, 5, 6, 9]), plant(0x060C063D, 1, [0, 1, 2, 5, 6])]
             + objects(38, 2, [0, 5, 100, 200, 0xFF00, 0xFFF0, 0x7F, 0x80]) + field(52, 2, [0, 1, 2, 3])
             + field(36, 2, [0, 1, 2])))
case("f0601BB68", [], True, current(field(36, 2, [0, 1, 2, 3, 40, 0xFFFF]) + [plant(0x060C063D, 1, [0, 1, 2, 3, 5, 8])]
                                    + [plant(0x060D8310, 4, [bomber(0), bomber(1)], 1.0)] + field(62, 2, [0, 1, 2]) + field(22, 2, [3, 4])
                                    + [plant(0x060D8314, 4, [obj(3)]), plant(0x060D8310 + 8, 4, [obj(3)])]))
case("f0601BBC2", [], False, current(field(80, 2, [0, 1, 5]) + field(76, 2, [0, 1, 5, 119, 120, 121]) + field(78, 2, [0, 1])
                                     + [plant(0x060C0684, 2, [0, 0xFF, 1, 0x8000]), plant(0x060BF5E6, 2, [0, 0xFF, 1, 0x8000])]))
case("f0601B288", [], False, [plant(bomber(i) + 36, 2, [0, 1, 2, 3], 0.9) for i in range(2)]
     + [plant(bomber(k) + 52, 2, [0, 1, 2, 2, 3], 0.9) for k in range(5)] + [plant(bomber(k) + 64, 2, [0, 1, 2, 3], 0.9) for k in range(5)])
case("f0601DE4E", [pick(0, 1, 5, 255)], False,
     [plant(0x060D8C08, 4, [0x060D849C + 38 * k for k in range(5)], 1.0), plant(0x060D84C8, 1, [0, 1, 2, 3]),
      plant(0x060D7E8C, 2, [0, 1, 2, 3, 40])] + [plant(FLAGS + 2 * c, 2, [0, 1, 4, 7, 8, 0], 0.7) for c in range(0, 64)])
case("f06015ECA", [], False, current(field(12, 2, [0, 1, 3, 4, 5, 6]) + field(10, 2, [0, 0x1000, 0xF000, 0xFFFF, 0xE000])))
case("f06015F1C", [], False, current(field(12, 2, [0, 1, 3, 0xB, 0xC, 5]) + field(10, 2, [0, 0x1000, 0x2000, 0xF000, 0xFFFF, 0x2001])))
case("f060167DE", [], True, current(field(36, 2, [0, 1, 2, 3]) + [plant(bomber(i) + 52, 2, [0, 1, 2, 5, 9], 0.9) for i in range(4)]))
case("f0601755E", [pick(0, 1, 5, 100, 0x10000)], False,
     current(field(66, 2, [0, 1, 5, 100, 0xFFFF]) + field(22, 2, [3, 4]) + [plant(0x060C062D, 1, [0, 1, 2, 5])]))
