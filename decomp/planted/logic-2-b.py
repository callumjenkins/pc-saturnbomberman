from cases import bomber, case, cell, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

CURRENT = 0x060D7768
CUR_OBJ = 0x060D7B3C
SLOT_NOW = 0x060D7E60
SLOT_OBJ = 0x060D7E64
FLAGS = 0x060EC8B0


def current(extra=()):
    """The four pointers the kernel keeps at the record being run, so that a trial gets past the first dereference."""
    return [plant(CURRENT, 4, [bomber(0), bomber(1), bomber(2)], 1.0), plant(CUR_OBJ, 4, [obj(3), obj(4)], 1.0),
            plant(SLOT_NOW, 4, [slot(3), slot(4)], 1.0), plant(SLOT_OBJ, 4, [obj(3), obj(4)], 1.0)] + list(extra)


def field(offset, size, values, chance=0.8, records=(0, 1, 2)):
    """The value at offset of the first bomber records."""
    return [plant(bomber(i) + offset, size, values, chance) for i in records]


def objf(offset, size, values, chance=0.8, which=(3, 4)):
    return [plant(obj(k) + offset, size, values, chance) for k in which]


def cells(values, which=range(0, 12), chance=0.7):
    """Halfwords of the cell flags table."""
    return [plant(FLAGS + 2 * c, 2, values, chance) for c in which]


def bits(address, size, chance=0.8):
    return plant(address, size, [0, 1, 2, 3, 4, 7, 0x80], chance)


# What 0606C114 reads: the first two bomber records' flag byte and the cells' halfwords at 8 and 10.
def near(limit_values=(0, 3, 6, 8, 10)):
    return (field(4, 1, [0, 0, 0x80, 0x01], 0.8, (0, 1)) + [plant(cell(k) + 8, 2, list(limit_values), 0.8) for k in range(2)]
            + [plant(cell(k) + 10, 2, list(limit_values), 0.8) for k in range(2)])


case("f06076658", [], False, current([plant(0x060C27C0, 4, [0x060C2000])] + field(20, 2, [2, 3, 6, 0xFFFF]) + cells([0, 1, 2, 8, 0x10, 0xFFFF])))
case("f0607745C", [], False, current([plant(0x060C27CE, 2, [4, 4, 0])] + field(24, 2, [100, 208, 209, 0x170, 0x16F, 0x300]) + field(28, 2, [0x1FF, 0x200, 0x300])))
case("f0607766C", [], True, current([plant(0x060C27EE, 2, [0, 0, 0, 1]), plant(0x060D7EB6, 2, [20, 27, 100, 0x2000, 0xC000]),
                                     plant(0x060C27CC, 2, [0, 5, 0xFFF])] + field(28, 2, [0, 0x40, 0x100, 0x1000]) + field(20, 2, [0, 1, 5])
                                    + cells([0, 1, 2, 8, 0x10, 0xFFFF])))
case("f0607884E", [], False, current(objf(50, 2, [20, 25, 30]) + field(80, 2, [10, 16, 20, 0]) + objf(10, 2, [0, 1, 5, 8])
                                     + [plant(0x060C27E8, 2, [0, 1, 4])]))
case("f0607992E", [], True, current(near() + [plant(0x060C27FE, 2, [0, 0, 0, 1])]))
case("f0607A438", [], True, current([plant(0x060C27FC, 2, [0, 0, 0, 1])] + field(4, 1, [0, 0, 0x80, 0x01], 0.8, (0, 1))))
case("f06079D30", [], True, current(field(60, 2, [0, 0, 1]) + field(7, 1, [0, 1, 2, 3, 3]) + field(24, 2, [0x1BF, 0x1C0, 0x200, 0x220, 0x221])
                                    + field(28, 2, [0x1BF, 0x1C0, 0x1F0, 0x200, 0x201]) + field(4, 1, [0, 0, 0x40, 0x80, 0xC0], 0.7, (0, 1))))
case("f06076BBC", [], True, current())
case("f06078D38", [], True, current(field(70, 2, [3, 4, 5])))
case("f0607ADAE", [], False, current([plant(0x060C27F0, 2, [0, 1, 2])]))


def flagbytes(chance=0.8):
    """The flag byte at 4 of the first two bomber records, which the 0606BF.. and 0606C1.. predicates test against 0x80."""
    return field(4, 1, [0, 0, 0x80, 0x01], chance, (0, 1))


def freeobjs():
    """Free object slots (first word 0) for the allocator at 060691DA."""
    return [plant(0x060C1AAC, 2, [0, 5, 100]), plant(obj(2), 4, [0, 0x1234], 0.5)]


case("f0607B3E8", [], False, current([plant(0x060C2870, 2, [0, 1, 2]), plant(0x060C2872, 2, [0, 1, 2, 3])]))
case("f0607B44C", [], False, current())
case("f0607B88C", [], False, current())
case("f0607B9D8", [], False, current([plant(0x060C2870, 2, [0, 1, 2]), plant(0x060C2872, 2, [0, 1, 2, 3])]))
case("f0607DD98", [], True, current(field(28, 2, [0x50, 0x80, 0x100, 0x300]) + field(70, 2, [0, 0x20, 0x80, 0x100]) + field(66, 2, [0, 3, 4])
                                    + field(72, 2, [0, 1, 5]) + [plant(0x060C2860, 2, [0, 1, 2]), plant(0x060C288E, 2, [0, 0, 1])]
                                    + field(4, 1, [0, 0x40, 0x80]) + field(22, 2, [3, 4]) + objf(16, 2, [100, 104, 110, 200]) + objf(4, 2, [50, 52, 60, 100])))
case("f0607DF5A", [], True, current(field(42, 2, [0, 0, 0x80]) + field(28, 2, [50, 111, 112, 200]) + field(66, 2, [0, 3, 4])
                                    + [plant(0x060C1AA8, 2, [3, 4, 5])] + objf(4, 2, [10, 20, 0xFFF0]) + objf(38, 2, [0, 5, 0xFFFB])))
case("f0607DFB2", [], True, current([plant(0x060C2860, 2, [0, 1, 2, 2]), plant(0x060C288E, 2, [0, 0, 0, 1])]
                                    + field(4, 1, [0, 0, 0x40], 0.7, (1, 2)) + field(22, 2, [3, 4], 0.9, (1, 2)) + field(28, 2, [0x40, 0x48, 0x60, 0x80, 0x100], 0.9, (1, 2))
                                    + field(66, 2, [3, 4]) + objf(16, 2, [100, 104, 110, 200]) + objf(4, 2, [50, 52, 60, 100]) + field(74, 2, [0, 5])))
case("f0607F83C", [], True, current(objf(38, 2, [0xFFFB, 0, 5, 0xFFF0]) + field(70, 2, [0, 5, 0x100, 0x7FF0]) + field(74, 2, [0, 0x8000, 0x1234])
                                    + field(82, 2, [0, 5, 0xFFF0]) + objf(78, 1, [0, 5, 0x80])))
case("f0607F9EA", [], True, current(field(36, 2, [74, 74, 0, 5]) + field(20, 2, [0, 1, 2, 5]) + cells([0, 0xFFFF, 0x88, 0x77])))
case("f0607FED8", [], False, current(objf(18, 2, [0, 5, 100, 0x200]) + freeobjs() + [plant(0x060C1AAA, 2, [2, 3, 4, 5])]))
case("f060801DC", [], True, current(field(62, 2, [0, 0, 0, 5]) + field(6, 1, [0, 1, 2, 3, 4]) + field(66, 2, [0, 5])))
case("f06080840", [], True, current(objf(78, 1, [0, 5, 0x80])))
case("f060827EC", [], True, current(field(68, 2, [0, 1, 5])))
case("f06083192", [], True, current([plant(0x060C28AE, 2, [2, 3, 5])]))
case("f06083900", [], False, current(field(68, 2, [0, 0x40, 0x100]) + field(70, 2, [0, 0x10, 0x200]) + [plant(0x060C28C8 + 2 * k, 2, [2, 3, 5, 6], 0.9) for k in range(4)]))
case("f06084E7E", [], True, current(field(7, 1, [0, 1, 2, 3, 3]) + flagbytes() + [plant(cell(k) + 8, 2, [0, 3, 6, 8], 0.8) for k in range(2)]
                                    + [plant(cell(k) + 10, 2, [0, 3, 6, 8], 0.8) for k in range(2)]))


def cellf(offset, values, which=(0, 1, 2, 3), chance=0.8):
    """A halfword of the 12-byte cell records at 060C1F42."""
    return [plant(cell(k) + offset, 2, list(values), chance) for k in which]


def predicate_inputs():
    """What the 0606BF.., 0606C1.. and 0606C3.. predicates read of the bombers, the current record and the cells."""
    return (flagbytes() + field(6, 1, [1, 2, 3, 4]) + cellf(0, [0, 5, 0xFFFB]) + cellf(2, [0, 5, 0xFFFB]) + cellf(8, [0, 0, 6])
            + cellf(10, [0, 0, 6]) + cellf(4, [0, 5, 20]) + cellf(6, [0, 5, 20]) + field(20, 2, [0, 1, 2, 3]) + field(18, 2, [0, 1, 0xFFFF]))


KIND = [0, 3, 4, 1, 2]
case("f06087ACC", [], True, current(predicate_inputs()))
case("f06085B60", [], True, current(predicate_inputs()))
case("f06086964", [], True, current(predicate_inputs() + field(64, 2, [0, 1, 2, 3])))
case("f06087FAE", [], True, current(predicate_inputs() + field(64, 2, [0, 1, 2, 3])))
case("f06087AE6", [], True, current(predicate_inputs() + field(64, 2, [0, 1, 2, 3]) + field(6, 1, [0, 1, 2, 3, 4], 0.95)
                                    + [plant(0x060C1F24, 2, KIND, 0.9)] + cellf(8, [0, 0, 6], range(0, 24), 0.9) + cellf(10, [0, 0, 6], range(0, 24), 0.9)))
case("f06088928", [], True, current([plant(0x060C2ED6, 2, [1, 2, 3, 4, 0]), plant(0x060C2EC0, 4, [0x1000, 0x50000, 0x100000, 0]),
                                     plant(0x060C2EC4, 4, [0x1000, 0x50000, 0x100000, 0]), plant(0x060C2EC8, 4, [0x1000, 0x50000, 0]),
                                     plant(0x060C2ECC, 4, [0x1000, 0x50000, 0])]))
case("f06089766", [], True, current(predicate_inputs() + field(40, 2, [5, 5, 0, 1])))
case("f06089B90", [], True, current(predicate_inputs() + objf(66, 2, [0, 0, 1, 5]) + field(4, 1, [0, 0x80, 0x40])))
case("f06089FDA", [], True, current([plant(0x060C2EF2, 2, [0, 5, 127, 128, 200])]))
case("f0608EA2E", [], True, current([plant(0x060C31CA, 2, [2, 3, 4]), plant(0x060C31D0, 2, [0, 1, 2])]))
case("f060906E4", [], True, current(field(66, 2, [0, 1, 2]) + field(20, 2, [0, 1, 2]) + field(68, 2, [0, 1, 2]) + field(67, 1, [0, 1, 2, 3])))
case("f060A52FA", [span(-4, 12)], False)
case("f06096AC0", [span(-2, 8)], False, [plant(0x060FA8BC, 4, [0x060C2000])])
case("f06096CB0", [pick(0, 1, 5, 7, 9)], True, [plant(0x060FA8BC, 4, [0x060C2000]), plant(0x060C2000 + 52 + 96, 4, [0, 1, 3, 5, 8], 1.0),
                                               plant(0x060C2000 + 52, 4, [1, 5, 7, 9], 0.8), plant(0x060C2000 + 56, 4, [1, 5, 7, 9], 0.8),
                                               plant(0x060C2000 + 60, 4, [1, 5, 7, 9], 0.8), plant(0x060C2000 + 64, 4, [1, 5, 7, 9], 0.8)])
case("f06096CF4", [pick(0, 1, 5, 7, 9)], False, [plant(0x060FA8BC, 4, [0x060C2000]), plant(0x060C2000 + 52 + 96, 4, [0, 1, 3, 5, 8], 1.0),
                                                plant(0x060C2000 + 52, 4, [1, 5, 7, 9], 0.8), plant(0x060C2000 + 56, 4, [1, 5, 7, 9], 0.8),
                                                plant(0x060C2000 + 60, 4, [1, 5, 7, 9], 0.8)])
case("f06096D28", [pick(0, 1, 5, 7, 9)], False, [plant(0x060FA8BC, 4, [0x060C2000]), plant(0x060C2000 + 52 + 96, 4, [0, 1, 3, 5, 8], 1.0),
                                                plant(0x060C2000 + 52, 4, [1, 5, 7, 9], 0.8), plant(0x060C2000 + 56, 4, [1, 5, 7, 9], 0.8),
                                                plant(0x060C2000 + 60, 4, [1, 5, 7, 9], 0.8), plant(0x060C2000 + 64, 4, [1, 5, 7, 9], 0.8)])
case("f0609812C", [pick(0, 1, 0x100000, 0x5A0001, 0x5A0000, 0xB40000, 0xB40001, -1, -0x100000, -0x5B0000, -0xB40000, 0x7FFFFFFF)], True)
case("f0609816C", [pick(0, 1, 0x100000, 0x5A0001, 0x5A0000, 0xB40000, 0xB40001, -1, -0x100000, -0x5B0000, -0xB40000, 0x7FFFFFFF)], True)

DEVICE = 0x060C2000     # a record for the pointer at 060FC084 to name
DEV_FIELDS = [plant(0x060FC084, 4, [DEVICE], 1.0)]


def dev(offset, values, chance=0.9):
    return plant(DEVICE + offset, 4, list(values), chance)


case("f06091228", [], True, current(predicate_inputs() + field(64, 2, [0, 1, 2, 3]) + field(28, 2, [0x100, 0x230, 0x240, 0x500])
                                    + [plant(0x060C3284, 2, [0, 0, 0, 1]), plant(0x060C3282, 2, [0, 0, 0, 1])] + objf(66, 2, [0, 0, 0, 5])
                                    + [plant(0x060C27EE, 2, [0, 1])]))
case("f06099CDC", [pick(0, 0x1000, 0x7FFFF, 0x80000, -1), pick(0, 1, 2, 3, 0xFFFF, 0x10001, 0x10003), ptr(0x060C0100, 0x100, 2)],
     False, [plant(0x060BB900, 2, [0, 1, 2, 3], 0.9), plant(0x060BB8FC, 2, [0, 0, 1])])
case("f0609DA9C", [], False, [plant(0x060BB91C, 2, [0, 1, 2, 3, 4]), plant(0x060BB92C, 4, [0, 1]), plant(0x060BB928, 4, [0, 1, 4, 5]),
                              plant(0x060BB920, 4, [0, 1, 2]), plant(0x060BB924, 4, [0, 1, 2, 5, 6]), plant(0x060FBF70, 2, [0, 0x10]),
                              plant(0x060FBF72, 2, [0, 0x10])])
case("f0609DB80", [], False, [plant(0x060FBF74, 2, [0, 0, 0, 1]), plant(0x060FBF34, 4, [0, 1, 2, 3, 4]), plant(0x060BB938, 4, [0, 1]),
                              plant(0x25D00010, 2, [0, 2, 3, 1]), plant(0x25F80004, 2, [0, 2, 3, 1]), plant(0x060FBF70, 2, [0, 5]),
                              plant(0x060FBF72, 2, [0, 5])])
case("f060A1356", [pick(3, 4, 5, 6, 7, 0, 1)], False, [plant(0x060FC00C, 4, [DEVICE], 1.0), dev(16, [0, 0x060C2100, 0x060C2200], 0.8)])
case("f060A5F32", [ptr(0x060C2000, 0x40, 4), pick(0, 5, 100)], False,
     [plant(0x060C2000 + 52, 4, [6, 6, 0, 5], 0.9), plant(0x060C2000 + 56, 4, [0, 1, 2, 3, 4], 0.9), plant(0x060C2000 + 8, 4, [0, 1, 5, 100, 0xFFFFFF])])
case("f060A78B0", [], True, DEV_FIELDS + [dev(48, [0, 1, 1, 5]), dev(56, [0, 5, -1, 0x7FFFFFFF, -2])])
case("f060A78E0", [pick(0, 5, 7, -1)], True, DEV_FIELDS + [dev(48, [0, 1, 1, 5]), dev(56, [0, 5, 7, -1])])
case("f060A7B76", [pick(0, 1, 5)], False, DEV_FIELDS + [dev(52, [-1, -1, -1, 0, 5], 1.0)])
case("f060A7C20", [pick(0, 5, 7, -1)], True, DEV_FIELDS + [dev(0x338, [0, 1, 2]), dev(0x33C, [0, 5, 7, -1])])
case("f060A83A0", [ptr(0x060C2400, 0x20, 4)], False, DEV_FIELDS + [dev(0x304, [0, 1, 2, 2]), dev(0x308, [0, 5, 7]), plant(0x060C2400, 4, [0, 5])])
case("f060A8556", [ptr(0x060C2400, 0x20, 4)], False, DEV_FIELDS + [dev(0x328, [0, 0, 3, 3, 2, 1], 1.0), dev(0x32C, [0, 5, 7]), dev(0x330, [0, 5, 7]), dev(0x334, [0, 5, 7])])
case("f060A85E4", [ptr(0x060C2400, 0x20, 4)], False,
     DEV_FIELDS + [dev(0x338, [0, 0, 0, 0, 0, 3, 4, 1, 2], 1.0), dev(0x33C, [0, 5, 7]), dev(0x340, [0, 0, 5, 7]), dev(0x344, [0, -1, -1, 5, 7])])
case("f060ADAAA", [pick(0x060FC190, 0x060FC190, 0x060FC194)], True,
     [plant(0x060FC18C, 4, [0x12345678, 0x12345678, 0]), plant(0x060FC210, 4, [0, 0xFFFFFFFF, 1, 1, 3, 2, 0x10], 0.95)])

FIX = 0x060C0100
case("f06098EA4", [ptr(0x060C0100, 0x20, 4), ptr(0x060C0200, 0x20, 4)], True,
     [plant(0x060FA907, 1, [1, 2, 1, 2, 0, 3]), plant(0x060FA960, 4, [0, 1, 2, 5]),
      plant(0x060FA918, 4, [0, 1, 5, 9]), plant(0x060FA908, 1, [0, 1, 2, 3]), plant(0x060FA914, 4, [0, 0, 1]),
      plant(0x060FA970, 1, [0, 1, 2, 3, 4]), plant(0x060FA901, 1, [0, 1, 2, 3, 4]), plant(0x060FA981, 1, [0, 1]),
      plant(0x060FA974, 4, [0, 1, 1]), plant(0x060FA968, 4, [0, 1, 2]), plant(0x060FA958, 4, [0x060C0300]),
      plant(0x060FA938, 1, [0, 1]), plant(0x060FA920, 4, [0x060C0400]),
      plant(0x060FA90C, 1, [0, 1, 2])])
case("f06099F30", [pick(FIX)], False,
     [plant(FIX, 4, [0, 0x1000, 0x20000, 0x40000]), plant(FIX + 4, 4, [0, 0x1000, 0x20000, 0x40000])]
     + [plant(FIX + 8 + k, 1, [0, 1, 1, 2, 3, 4, 5], 0.9) for k in range(7)]
     + [plant(0x060FB870, 1, [0, 1, 1]), plant(0x060FB871, 1, [0, 1, 1]), plant(0x060FA9AE, 2, [0, 0x8000, 0x1000, 0x1000, 0x1005, 0x3000])])
