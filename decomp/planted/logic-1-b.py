from cases import bomber, case, ent, obj, objs, pick, plant, ptr, slot, span  # noqa: F401

ACT = 0x060C2100            # a record for the pointer at 060D8C08
TSK = 0x060C2200            # a record for the pointer at 060D7E60
TOB = 0x060C2300            # an object for the pointer at 060D7E64
CUR = 0x060C2400            # a record for CURRENT
MOV = 0x060C2500            # a record for the pointer at 060D7B3C


def act(offset, size, values, chance=0.8):
    return plant(ACT + offset, size, values, chance)


def tsk(offset, size, values, chance=0.8):
    return plant(TSK + offset, size, values, chance)


def tob(offset, size, values, chance=0.8):
    return plant(TOB + offset, size, values, chance)


def cur(offset, size, values, chance=0.8):
    return plant(CUR + offset, size, values, chance)


# The offsets 060276D0's jump table holds; the check would otherwise randomise them.
JUMPS = [plant(0x06027710 + 2 * i, 2, [v], 1.0) for i, v in enumerate(
    [0x36, 0x3E, 0x56, 0x6C, 0x82, 0x98, 0x116, 0xAE, 0xB6, 0xBE, 0xC6, 0xD4, 0xEA, 0xF2, 0x108, 0xCC, 0x116, 0x116, 0x10E])]
ACTOR = [plant(0x060D8C08, 4, [ACT], 1.0)]
TASK = [plant(0x060D7E60, 4, [TSK], 1.0), plant(0x060D7E64, 4, [TOB], 1.0)]
CURRENT = [plant(0x060D7768, 4, [CUR], 1.0)]

case("f0601E766", [], False, ACTOR + [act(16, 1, [0, 1, 5, 255]), act(0, 2, [0, 7, 300]), act(2, 2, [0, 9, 300]),
                                      act(13, 1, [0, 0, 1]), act(15, 1, [0, 3, 9, 10, 200]), act(8, 2, [0, 64, 0x41]),
                                      act(35, 1, [0, 64, 0xFF]), act(4, 2, [0, 0xFFFF, 12])] + JUMPS)
case("f0601ED54", [pick(0, 1, 2, 3)], False, ACTOR + [plant(0x060C029C, 1, [8], 0.9), plant(0x060C063D, 1, [0, 2, 10]),
                                                      act(15, 1, [0, 1, 5]), act(35, 1, [0, 16, 4, 8, 28, 0xFF])]
     + [plant(0x060EE8B0 + 2 * k, 2, [0, 0x4000, 0x4001], 0.8) for k in range(4)] + JUMPS)
case("f0601F38C", [], True, ACTOR + [act(16, 1, [0, 1, 2, 255]), act(4, 2, [0, 5, 0xFFF, 0x1000, 0xFFFF]), act(0, 2, [0, 1, 5])])
case("f0601F3DA", [], True, ACTOR + [act(16, 1, [0, 1, 5, 255])])
case("f0601F500", [], True, ACTOR)
case("f0601F58E", [], True, ACTOR + [act(0, 2, [0, 3]), act(2, 2, [0, 5])])
case("f0601F668", [], False, ACTOR + [act(15, 1, [0, 3])])
case("f0601F6CC", [], True, ACTOR + [act(15, 1, [0, 1]), act(0, 2, [3, 4]), plant(bomber(0) + 16, 2, [3, 4, 5]), plant(bomber(1) + 16, 2, [3, 4, 5])]
     + [plant(obj(i) + o, 2, [0, 1, 5, 100], 0.9) for i in (3, 4, 5) for o in (16, 18)])
case("f0601F7AE", [], False, ACTOR + [act(10, 2, [0, 1, 3]), act(24, 1, [0, 2, 3])])
case("f06021102", [], False, ACTOR + [act(8, 2, [0, 1]), act(10, 2, [0, 1, 3]), act(24, 1, [0, 4, 2]), act(16, 1, [0, 50, 111, 112, 200, 255])])
case("f060212E6", [pick(0x060C2600), pick(0x060C2610), pick(0, 0x100, 0x200, 0xF00, 0x1000, 0xF01)], False,
     ACTOR + [plant(0x060C029C, 1, [8], 0.9), plant(0x060C2610, 2, [0, 0x4000, 0x4100, 0x4F00, 0x0300]),
              plant(0x060C2600, 2, [0, 80, 16, 0x40]), act(35, 1, [0, 1, 2, 32, 64, 33, 0xFF]), act(15, 1, [0, 1, 5]),
              plant(0x060C063D, 1, [0, 3, 10])] + JUMPS)
case("f060215A2", [pick(0, 1, 0x7F, 0xFF, -1)], True, ACTOR + [plant(0x060DFB95, 1, [0, 5, 126, 127, 255], 0.9)])

# The random number table at 060BF4F8, with values a mask of 31 clears.
RANDOM = [plant(0x060BF4F4, 4, [1, 5, 20], 0.9)] + [plant(0x060BF4F8 + 4 * k, 4, [0, 32, 64, 5, 0], 0.7) for k in range(1, 56)]

# The limits and the position the movement routines work on.
LIMITS = [plant(0x060C0904, 2, [100], 1.0), plant(0x060C0906, 2, [200], 1.0), plant(0x060C0908, 2, [20], 1.0),
          plant(0x060C090A, 2, [10], 1.0)]
MOVER = [plant(0x060D7B3C, 4, [MOV], 1.0), plant(MOV + 16, 2, [5, 10, 15, 20, 21, 60, 99, 100, 101, 200, 0x8000], 0.95),
         plant(MOV + 18, 2, [5, 10, 11, 100, 199, 200, 201, 300, 0x8000], 0.95)]

case("f06021E1A", [], False, CURRENT + [plant(0x060DFDFE, 2, [0, 0, 1]), cur(4, 1, [0, 0x40, 0x80, 0xC0]), cur(46, 2, [0, 0x0800, 0xFFFF])])
case("f060225D2", [pick(0x060C2700)], False, [plant(0x060C2705, 1, [21, 0, 5]), plant(0x060C2706, 1, [0, 1, 2, 29, 30, 31, 200]),
                                              plant(0x060C2707, 1, [0, 255, 5]), plant(0x060C2700, 2, [3, 4])])
case("f0602336E", [], False, TASK + [plant(0x060C02AE, 2, [0, 1, 2, 128]), plant(0x060D7E68, 2, [0, 64]), tsk(10, 2, [0, 0xFF, 0x100])])
case("f06023390", [pick(0, 1, 5, 0x100, -1)], True, TASK + [plant(0x060D7E68, 2, [0, 64]), tsk(10, 2, [0, 0xFF, 0x100, 0x200])])
case("f060238F0", [], True, TASK + [plant(0x060C067C, 2, [0, 1, 5, 100]), plant(0x060C063D, 1, [0, 2, 10]), tsk(10, 2, [0, 1, 5, 0x8000]),
                                    tob(62, 2, [0, 0x100, 0x101, 0x200])])
case("f06023B04", [], True, TASK + [plant(0x060D7B44, 2, [0, 1, 5])])
case("f06023D8E", [], True, TASK + [tob(18, 2, [0, 100, 127, 128, 129, 200, 256, 257, 300, -5])])
case("f06023E2C", [], False, TASK + [tob(18, 2, [-100, -32, -31, 0, 0x200, 0x201, 0x7FFF])])
case("f06023E72", [], True, TASK + [tob(18, 2, [0, 15, 16, 100, 240, 241, 300])])
case("f060256EC", [], True, TASK + [tsk(12, 2, [0, 1, 2, 3])] + [plant(0x060EC8B0 + 2 * k, 2, [0, 32, 1]) for k in range(4)]
     + [plant(0x060EE8B0 + 2 * k, 2, [0, 0x1000, 0x3000, 0x2000]) for k in range(4)])
case("f06025E3E", [], True, TASK + [tsk(10, 2, [0, 0x257, 0x258, 5]), plant(0x060D7E68, 2, [0, 64])])
PADS = pick(0, 0x8000, 0x4000, 0x2000, 0x1000, 0xF000, 0xC000, 0x3000, 0xA000, 0x5000, 0x9000, 0x6000)
case("f06026C08", [PADS], True, CURRENT + LIMITS + MOVER + [cur(44, 2, [1, 2, 3, 50]), plant(0x060C0684, 2, [0, 1, 0xFFFF]),
                                                              plant(0x060BF5E0, 2, [0, 1, 0xFFFF])])
case("f06026D90", [], False, CURRENT + LIMITS + MOVER + [cur(58, 2, [0, 0, 1]), plant(0x060C0684, 2, [0, 0x1000, 0x8000, 0xF000, 0x4000]),
                                                           cur(50, 2, [0, 1, 2, 3, 4]), cur(18, 2, [0, 0x1000, 0x8000, 0xFFFF]),
                                                           cur(44, 2, [1, 2, 3])])
case("f06026E04", [pick(0, 1, 1, 1)], False, CURRENT + LIMITS + MOVER)
ROUND = ([plant(0x060C063D, 1, [2, 3, 4, 5]), plant(0x060C062C, 2, [0, 1, 2, 3]), cur(6, 1, [1, 2, 3, 4]),
          plant(0x060C090C, 2, [0, 10, 100]), plant(0x060C090E, 2, [0, 10, 100])]
         + [plant(bomber(k) + 4, 1, [0, 0x80, 2], 0.8) for k in range(6)] + [plant(0x060C0640 + k, 1, [0, 4, 8, 28, 12], 0.8) for k in range(6)]
         + [plant(bomber(k) + 22, 2, [3, 4, 5, 6], 0.9) for k in range(6)] + objs(16, [0, 5, 10, 50, 100, 200], (3, 4, 5, 6))
         + objs(18, [0, 5, 10, 50, 100, 200], (3, 4, 5, 6)) + [plant(0x060D7E88, 2, [-20, 0, 20, 0x1000])])
case("f06027270", [], False, CURRENT + ROUND)
case("f06027426", [], False, CURRENT + LIMITS + MOVER + RANDOM + [plant(0x060C0680, 1, [0, 1, 1, 2]), plant(0x060C063D, 1, [0, 0, 3]), cur(70, 2, [0, 1, 5]), cur(18, 2, [0, 0x1000, 0x8000, 0xFFFF]),
                                                          cur(50, 2, [0, 1, 2, 3]), cur(6, 1, [0, 1, 2]), plant(0x060D7E8C, 2, [0xFFFF, 0, 5], 0.6),
                                                          plant(0x060D7E88, 2, [-20, -8, -7, 0, 7, 8, 20]), plant(0x060D7E8A, 2, [-20, -8, -7, 0, 7, 8, 20]),
                                                          plant(0x060C0630, 2, [0, 1, 2, 3])])
case("f06027910", [], False, [plant(0x060C029D, 1, [0, 1, 5, 20, 20], 0.95), plant(0x060C0A64, 4, [0, 1, 5], 0.8), plant(0x060C0A30, 4, [0, 5, 11, 12]), ] + JUMPS)
case("f060285EA", [], True, TASK + [tsk(10, 2, [3, 4, 5])] + objs(68, [0, 0x5E0, 0x5F0, 0x600, 0x100], (3, 4, 5)) + objs(70, [0, 0x5F0], (3, 4, 5)))
case("f060287C4", [], True, TASK + [tsk(16, 2, [0, 1, 2, 3, 4, 5, 6, 7])] + [tob(16, 2, [-100, -1, 0, 5, 100, 200, 0x7FFF]), tob(18, 2, [-100, 0, 40, 100, 200, 0x7FFF])])
# A round in which another bomber's lane differs from this one's, so 06027206 and 0602719C may pick it.
LANES = ([plant(0x060C063D, 1, [3], 1.0), plant(0x060C062C, 2, [0], 1.0), plant(0x060C0640, 1, [0], 1.0), plant(0x060C0641, 1, [4], 1.0),
          plant(0x060C0642, 1, [8], 1.0), plant(bomber(1) + 4, 1, [0], 1.0), plant(bomber(2) + 4, 1, [0], 1.0),
          plant(bomber(1) + 22, 2, [3, 4], 1.0), plant(bomber(2) + 22, 2, [3, 4], 1.0), plant(bomber(0) + 22, 2, [5], 1.0),
          cur(6, 1, [1, 2, 3, 4], 1.0), plant(0x060C090C, 2, [10, 50, 100]), plant(0x060C090E, 2, [10, 50, 100]),
          plant(0x060D7E88, 2, [0x1000]), plant(0x060D7E8A, 2, [0x1000]), cur(28, 2, [10, 50, 200]), cur(24, 2, [10, 50, 200]),
          plant(bomber(1) + 28, 2, [10, 50, 200]), plant(bomber(2) + 28, 2, [10, 50, 200]),
          plant(bomber(1) + 24, 2, [10, 50, 200]), plant(bomber(2) + 24, 2, [10, 50, 200])]
         + objs(16, [0, 5, 10, 50, 100, 200], (3, 4, 5)) + objs(18, [0, 5, 10, 50, 100, 200], (3, 4, 5)))
case("f060275E4", [], False, CURRENT + LIMITS + MOVER + RANDOM + [plant(0x060D7E92, 2, [0, 1]), plant(0x060C0680, 1, [0, 1, 1, 2]), cur(42, 2, [5, 0, 3]),
                                                                  cur(70, 2, [0, 1, 5]), plant(0x060D7E8E, 2, [0, 1, 2, 3, 4])] + LANES)

# Ten pad halfwords at 060060B0 and the bytes at 06006134 that switch each one off.
PAD_WORDS = ([plant(0x060060B0 + 2 * k, 2, [0, 0x100, 0x8000, 0x4000, 0xC000, 0xE00, 0x200, 0x400, 0x2000, 0x1000], 0.6) for k in range(10)]
             + [plant(0x06006134 + k, 1, [0, 0, 1], 0.8) for k in range(10)]
             + [plant(0x060C0640 + k, 1, [0, 1, 1, 2, 3], 0.8) for k in range(10)]
             + [plant(0x060C1044, 1, [0, 1, 3, 9, 10, 12, -1], 0.9), plant(0x060C122C, 1, [0, 1, 2, 3, 4], 1.0)])
K = 0x060C2800
case("f0602A876", [pick(0, 0x060C3000, 0x060C3000)], True, [plant(0x060C0F82, 1, [0, 1, 128, 129, 5], 0.95)])
case("f0602A940", [], False, [plant(0x060C0FA8, 2, [0, 1, 1, 1]), plant(0x060C0F88 + 28, 4, [K], 1.0), plant(K, 2, [0, 0, 3])])
case("f0602BA62", [pick(0, 1, 0x1234, -1)], True, PAD_WORDS)
case("f060306F0", [], True, [plant(0x060C101A, 1, [0, 1, 1, 2])] + [plant(0x06006096 + 2 * k, 2, [0, 0x70, 0xF0, 0x1F0], 0.6) for k in range(10)]
     + [plant(0x06006134 + k, 1, [0, 0, 1], 0.8) for k in range(10)] + [plant(0x060C0FF4 + 2 * k, 2, [3, 4, 5]) for k in range(3)])
case("f0602B8FC", [pick(0, 1, 2, 3, 4)], True, PAD_WORDS)
case("f0602C65E", [], True, PAD_WORDS + [plant(0x060C0640 + k, 1, [0, 0, 0, 4, 1], 0.95) for k in range(10)])

# Table 060B69CC pairs two bytes with a kind, counted from 1; the plants make the first match fall at different places.
KINDS = ([plant(0x060C029C, 1, [1, 2, 3, 4, 9], 1.0), plant(0x060C029D, 1, [1, 2, 9], 1.0)]
         + [plant(0x060B69CC + 4 * j, 2, [j % 4 + 1], 1.0) for j in range(8)] + [plant(0x060B69CC + 4 * j + 2, 2, [j // 4 + 1], 1.0) for j in range(8)])
# The 30 entries of the table at 060EC478.
POINTS = ([plant(ent(k), 2, [1, 2, 3, 0x100], 0.7) for k in range(30)] + [plant(ent(k) + 12, 4, [-1, 0, 5], 0.7) for k in range(30)]
          + [plant(ent(k) + 18, 2, [0, 5], 0.7) for k in range(30)] + [plant(ent(k) + 22, 1, [0, 1], 0.7) for k in range(30)]
          + [plant(ent(k) + 4, 2, [255, 5], 0.7) for k in range(30)])
case("f06039F54", [], False, KINDS + [plant(0x060BF5EA, 2, [0, 1]), plant(0x060C179C, 1, [0, 3, 9]), plant(0x060C179D, 1, [0, 3, 9])])
case("f0603C0B0", [], False, KINDS)
case("f0603C0FA", [], False, KINDS)
case("f0603C7F2", [], False, KINDS)
case("f060368DE", [pick(1, 2, 3, 0x100)], False, POINTS)
case("f06036C10", [pick(1, 2, 3, 0x100)], False, POINTS)
case("f06037094", [pick(0x060C2900)], True, POINTS + [plant(0x060C2900 + 23, 1, [0, 0x80]),
                                                     plant(0x060C2900 + 12, 4, [0, 0x80000000, 0x01000000, 0x02000000, 0x03000000, 0x80]),
                                                     plant(0x060C2900, 2, [1, 2, 3]), plant(0x060C122C, 1, [0, 1, 2, 3, 4])])
case("f0603645A", [pick(1, 2, 3, 4, 0x100), pick(0, 0x00040000)], True,
     POINTS + [plant(0x060060CA, 2, [0, 0x2000, 0x1000, 0x8000, 0x4000, 0xF000], 0.9)] + [plant(0x060C122C, 1, [0, 1, 2], 0.5)])

# With these four zero, 0600CA6A gives x / 16 + 64 * (y / 16 - 1) for an object's position (x, y).
OFFSETS = [plant(a, 2, [0], 1.0) for a in (0x060D7E88, 0x060D7E8A, 0x060D82BA, 0x060D82BC)]
CELLS = [65472, 0, 64, 65473, 1, 65, 65474, 2, 66]
case("f0603DF02", [], True, TASK + [tsk(8, 2, [3, 4]), tsk(14, 2, [0, 0xFF, 0x1FF, 0x100, 5]), tsk(12, 2, [0, 1, 0x258, 0x259, 5]),
                                    plant(0x060D7E68, 2, [0, 0x1052, 2, 0x1002]), plant(0x060C029D, 1, [0, 1, 5])]
     + objs(16, [0x154, 0x155, 0x150, 0x100, 0x254], (3, 4)) + objs(18, [0, 10, 0x100], (3, 4)))
case("f06040E4A", [], True, TASK + OFFSETS + [tsk(8, 2, [3], 1.0), plant(0x060C1742, 2, CELLS, 0.8), plant(0x060C1744, 2, CELLS, 0.8)]
     + objs(16, [0, 16, 32], (3,), 1.0) + objs(18, [0, 16, 32], (3,), 1.0))
case("f060413E2", [], True, TASK + OFFSETS + RANDOM + [tsk(8, 2, [3], 1.0), tsk(12, 2, [0, 1, 5])]
     + objs(16, [0, 16, 288, 416, 500], (3,), 1.0) + objs(18, [0, 16, 32], (3,), 1.0))
case("f0604144E", [], False, TASK + [tsk(14, 2, [0, 1, 2, 2, 3, 3, 5]), tsk(12, 2, [0, 1]), tsk(20, 2, [0, 5, 0x100]),
                                     tob(16, 2, [0, 5, 0x7FFF, -5]), tob(12, 2, [0, 5, 0xFFFF, 0x8000])])
case("f06042C8C", [], True, TASK + [tsk(12, 2, [0, 3, -3]), tsk(14, 2, [0, 3, -3]), tsk(10, 2, [0, 5, 0x7FFE]),
                                    tob(18, 2, [0, 100, 200, 240, 241, 300]), tob(38, 2, [0, 10, 100, 241])])
case("f06046712", [], True, TASK + RANDOM + [tsk(20, 2, [0, 0, 1, 5]), tsk(10, 2, [0, 5]), tsk(8, 2, [3, 4]),
                                             tob(68, 2, [0, 5, 0x100, 0x101, 0xFFF0, 0x20, 0x10]), plant(0x060D7EB4, 2, [0, 5]), plant(0x060D7EB6, 2, [0, 5])])
case("f06047884", [pick(4, 8, 5, 0), pick(0, 0x12345678, -1), pick(0, 0x07654321, 0x00010000), pick(0x060C2A00)], True,
     [plant(0x060C2A00, 2, [0, 5, -5]), plant(0x060C2A02, 2, [0, 5, -5])])
# For cell 3 and no offsets the game's 0600C9AA and 0600CA32 leave the target at (48, 24).
case("f060469A4", [], True, TASK + [plant(a, 2, [0], 1.0) for a in (0x060D82BA, 0x060D82BC)] + [tsk(14, 2, [3], 1.0),
                                    tob(16, 2, [0, 47, 48, 48, 49, 200], 1.0), tob(18, 2, [0, 23, 24, 24, 25, 300], 1.0)])
case("f06021A56", [pick(0, 1, 0x10, 0xFFFF, -1, 0x8000)], False, CURRENT)
case("f06021A76", [pick(0, 1, 0x10, 0xFFFF, -1, 0x8000)], False, CURRENT)
case("f06022DC8", [], False, TASK)
case("f0602363C", [], False, CURRENT + [cur(4, 1, [0, 0x80, 5]), cur(22, 2, [3, 4])])
