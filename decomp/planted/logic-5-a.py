from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

FIX = 0x060C0100
SP = 0x060FFFF0                 # where a function called by the check finds its first stack argument

# 06006AA0: 18 records of 88 bytes; a free one has 0 at 80, and a busy one whose word at 20 equals the buffer traps
# 0609DA34 hands a word to the display and waits for it to be taken back, unless 060BB924 holds 0
IDLE = [plant(0x060BB924, 4, [0], 1.0)]
FREE = [plant(0x060BC190 + 88 * k + 80, 1, [0, 0, 1], 0.7) for k in range(18)] + [plant(0x060BC190 + 88 * k + 20, 4, [0], 1.0) for k in range(18)]
case("f0600663C", [ptr(0x060C0100, 0x40, 4), pick(1, 5, 0x12345678), span(-3, 40)], False)
case("f060069B2", [pick(1, 2), pick(FIX), pick(8, 0x100), pick(0, 3)], True, FREE)
case("f060069C2", [pick(1, 2), pick(FIX), pick(8, 0x100), pick(0, 3)], True, FREE)
case("f06006AA0", [pick(1, 2), pick(FIX), pick(8, 0x100), pick(0, 3)], True, FREE + [plant(SP, 4, [0, 1, 5])])
case("f06006FBA", [span(-2, 20)], False)
BLEND = [plant(SP, 4, [0, 0x8000, 0x8003, 0x1F, 0xFFFF]), plant(SP + 4, 4, [0, 1])]
case("f06008F50", [pick(0, 5, 16, 100), pick(0, 5, 16, 20, 130), pick(0, 0x8000, 0x8010, 0x10, 0x7FFF), pick(0, 0x8000, 0x8010, 0x7FFF, 0xFF)], False, BLEND)
case("f06009078", [pick(0, 5, 16), pick(0, 5, 20), pick(0, 0x8000, 0x8010, 0x10)], False)
case("f060090A8", [pick(0, 5, 16), pick(0, 5, 20), pick(0, 0x8000, 0x8010, 0x10)], False)
case("f060090C2", [pick(0, 5, 16), pick(0, 5, 20), pick(0, 0x8000, 0x10), pick(0, 0x8000, 0x10)], False, [plant(SP, 4, [0, 0x8000, 7])])
ENTS = 0x060CE060
case("f060092D4", [pick(1, 2, 3)], True, [plant(ENTS + 16 * k + 11, 1, [0, 1, 1, 5], 0.8) for k in range(16)] + [plant(0x060BF4A4, 4, [-1, 5])] + FREE)
case("f06009380", [pick(1, 2, 3), pick(0, 0x10, 0x8000, 0xFFF0)], True, [plant(ENTS + 16 * k + 11, 1, [0, 1, 1, 5], 0.8) for k in range(16)] + [plant(0x060BF4A4, 4, [-1, 5])] + FREE)
case("f060097E0", [], True, FREE)
case("f0600A1FC", [pick(FIX), pick(0, 1, 2, 3, 0x10003), span(0, 4)], True,
     [plant(FIX + 6, 2, [0, 1, 0x0102, 0x7F7F]), plant(FIX + 8, 2, [0, 1, 5, 9]), plant(FIX, 2, [0, 1, 4, 6]), plant(FIX + 2, 2, [0, 3, 5, 9]), plant(FIX + 4, 2, [0, 1, 2, 7])])
case("f0600A49C", [ptr(0x060C0100, 0x40, 2), pick(0, 0x1234, 0xFFFF), span(-3, 40)], False)
case("f0600CE6C", [], True, [plant(0x060C029C, 1, [8, 17, 3])] + FREE + IDLE)
case("f0600D4BE", [pick(0, 1, 5, 0x10003), span(-2, 5), pick(0, 1, 0xFFFF, 0x12345)], False)
case("f0600D4DA", [pick(0, 1, 5, 0x10003), span(-2, 5), pick(0, 1, 0xFFFF, 0x12345)], False)
# the cell 060C04D8 names: its flags, and the kind a byte of 060F08B0 selects from the table at 060DFB9B
CELLS = [plant(0x060C04D8, 2, [0, 1, 2, 3], 1.0)] + [plant(0x060EC8B0 + 2 * c, 2, [0x40, 0x40, 0, 0x7F], 0.9) for c in range(4)] \
    + [plant(0x060F08B0 + 2 * c, 2, [0, 1, 2, 3, 4], 0.95) for c in range(4)] \
    + [plant(0x060DFB9B + 8 * b, 1, [10, 16, 21, 26, 3], 0.9) for b in range(5)]
CUR = [plant(0x060D7768, 4, [bomber(0)], 1.0), plant(bomber(0) + 46, 2, [0, 0x800, 0x800]), plant(bomber(0) + 36, 2, [0, 1, 2]), plant(bomber(0) + 20, 2, [0, 1, 2, 3], 0.6)] \
    + [plant(0x060D5F30 + 124 * k + 52, 2, [0, 1, 2, 3], 0.7) for k in range(4)]
case("f06010E88", [], False, CELLS + CUR + [plant(0x060C04CC, 2, [0, 1, 2, 3])])
case("f06010F7C", [pick(FIX), pick(0, 1, 2, 3)], False,
     CELLS + [plant(FIX + 20, 2, [0, 1, 2, 3], 0.6), plant(FIX + 16, 2, [0, 1, 2, 3], 0.6), plant(0x060C04CC, 2, [0, 1, 2, 3])])
case("f06011A6C", [pick(FIX)], True,
     [plant(FIX + 24, 1, [0, 1, 2, 3, 4], 0.9), plant(0x060C062C, 2, [0, 1, 2], 0.8)] + CUR
     + [plant(0x060D5F30 + 124 * k + 20, 2, [0, 1, 2, 3], 0.6) for k in range(5)]
     + [plant(0x060B3BB8 + 4 * k, 4, [1, 2, 3, 0x20, 0x40], 0.8) for k in range(4)]
     + [plant(0x060EC8B0 + 2 * c, 2, [0, 0x10, 0x40, 0x42F0, 0x7], 0.6) for c in range(40)])
case("f06013D5C", [], True, [plant(0x060D7E68, 2, [0, 0x40, 0x10]), plant(0x060C029C, 1, [0, 1, 5, 9, 12]), plant(0x060C063D, 1, [0, 1, 2, 3]),
                              plant(0x060BF5EA, 2, [0, 1, 7]), plant(0x060C02AA, 2, [100]), plant(0x060C1000, 4, [100, 90, 2000]),
                              plant(0x060060AE, 2, [0, 0xE00, 0x200, 0x1000])])
# a ring of links at 060D776C: entry 0 the head, entry k followed by k + 1, the last pointing back to 1
RING = []
for _k in range(7):
    RING += [plant(0x060D776C + 8 * _k, 1, [0, 1, 2, 3, 255], 0.8), plant(0x060D776C + 8 * _k + 4, 4, [0x1234, 0x060C2000], 0.9),
             plant(0x060D776C + 8 * _k + 2, 1, [_k + 1 if _k < 6 else 0], 1.0)]
    if _k >= 2:
        RING.append(plant(0x060D776C + 8 * _k + 1, 1, [_k - 1], 1.0))
RING += [plant(0x060D776C + 9, 1, [6, 6, 3, 2, 1], 1.0), plant(0x060C062C, 2, [0, 1, 2, 3], 0.95), plant(0x060D7768, 4, [0x060C2100])]
# the same entries as a plain chain, each one's previous being the entry before it
CHAIN = [plant(0x060D776C + 8 * _k, 1, [0, 1, 2, 3, 255], 0.8) for _k in range(7)] \
    + [plant(0x060D776C + 8 * _k + 1, 1, [max(_k - 1, 0)], 1.0) for _k in range(7)] \
    + [plant(0x060D776C + 8 * _k + 2, 1, [_k + 1 if _k < 6 else 0], 1.0) for _k in range(7)] \
    + [plant(0x060C062C, 2, [0, 1, 2, 3], 0.95), plant(0x060D7768, 4, [0x060C2100])]
case("f060142E2", [span(0, 3), span(0, 3), span(0, 5), span(0, 4)], False,
     [plant(0x060EC8B0 + 2 * c, 2, [0, 0x80, 0x85, 1, 0xFF7F], 0.5) for c in range(0, 800)])
case("f0601446E", [], False, FREE)
case("f060145A8", [], False, RING)
case("f06014776", [span(-1, 4)], False, CHAIN + [plant(bomber(i) + 22, 2, [0, 5, 0xFFFF], 0.6) for i in range(5)] + [plant(0x060C0632, 2, [0, 3])])
case("f060147BC", [], False, CHAIN + [plant(bomber(i) + 22, 2, [0, 5, 0xFFFF], 0.6) for i in range(5)])
case("f06014820", [pick(0, 1, 2, 3, 0x10001)], False, CHAIN)
case("f06015D16", [], False,
     [plant(0x060D7B3C, 4, [0x060C2400], 1.0), plant(0x060C1AA8, 2, [3, 4], 1.0)] +
     [plant(0x060D7768, 4, [0x060C2000], 1.0), plant(0x060C2000 + 4, 1, [0, 0x40, 0x80, 0xC0]), plant(0x060C2000 + 20, 2, [0, 1, 2, 3]),
      plant(0x060C2000 + 90, 2, [0, 0x12, 0x1234, 0x7F]), plant(0x060C062C, 2, [0, 1, 5]), plant(0x060C063D, 1, [0, 1, 5])]
     + [plant(0x060EE8B0 + 2 * c, 2, [0, 0x12, 0x1200, 0x7F, 0xFFFF], 0.7) for c in range(4)])
# 0601640E, which 06016394 branches to, wants the mover (060D7B3C) or the object named by the bomber, with halfwords 60 and 62
MOVE = [plant(0x060D7B3C, 4, [0x060C2000], 1.0), plant(0x060C2000 + 60, 2, [0, 1, 5, 9]), plant(0x060C2000 + 62, 2, [0, 1, 5, 9]),
        plant(0x060D7768, 4, [0x060C2100], 1.0), plant(0x060C2100 + 70, 2, [0, 1, 3]), plant(0x060C2100 + 4, 1, [0, 0x80]),
        plant(0x060C2100 + 46, 2, [0, 0x1000, 0x800, 0x1800, 0x27D, 0x8000], 0.9), plant(0x060C2100 + 36, 2, [0, 1, 2]),
        plant(0x060C029C, 1, [0, 3, 9, 12]), plant(0x060C0684, 2, [0, 0x1000, 0xF000, 0x8000]),
        plant(0x060D5F46 + 124 * 1, 2, [3], 0.9), plant(0x060D5F46, 2, [3], 0.9), plant(0x060D5F46 + 124 * 2, 2, [4], 0.9)]
case("f06016394", [], False, MOVE)
case("f0601689A", [pick(0, 0x8000, 0x10), pick(0, 0x8000, 0x7FFF), pick(0, 0x10, 0x8003)], False,
     [plant(0x060D7B3C, 4, [0x060C2400], 1.0), plant(0x060C2400 + 46, 2, [0, 0x10, 0x1F0, 0x7F0], 0.9), plant(0x060D7768, 4, [0x060C2000], 1.0),
      plant(0x060C2000 + 36, 2, [0, 1, 2, 3])])
FINDLATER = [plant(0x060D849C + 7, 1, [1], 1.0), plant(0x060D849C + 38 + 7, 1, [2, 2, 0], 1.0), plant(0x060D849C + 76 + 7, 1, [0], 1.0),
             plant(0x060D849C + 38 + 16, 1, [0, 1, 2, 5, 255, 5], 0.9), plant(0x060D849C + 38 + 4, 2, [0, 1, 2, 3, 3], 0.9),
             plant(0x060D849C + 38 + 10, 2, [0, 0, 0x1FA, 0x2], 0.9)]
# the object 060C1AA8 names, whose position 0600C90C turns into a cell number
POS = [plant(0x060D82BA, 2, [0, 5, 16], 0.95), plant(0x060D82BC, 2, [0, 5, 16], 0.95),
       plant(0x060C1AA8, 2, [3], 1.0), plant(obj(3) + 16, 2, [0, 100, 200, 300, 0x1F0], 1.0), plant(obj(3) + 18, 2, [0, 100, 200, 300, 0x1F0], 1.0)]
# the actors, 38 bytes each from 060D849C, are chained by the byte at 7: 0, then 1, then 2, whose zero ends the chain
ACT = 0x060D849C
ACTORS = [plant(ACT + 7, 1, [1, 1, 0], 1.0), plant(ACT + 38 + 7, 1, [2], 1.0), plant(ACT + 76 + 7, 1, [0], 1.0),
          plant(ACT + 38 + 16, 1, [0, 1, 1], 0.9), plant(ACT + 38 + 15, 1, [0, 1, 1, 2], 0.9), plant(0x060C062C, 2, [0, 1, 2], 0.9),
          plant(ACT + 38 + 10, 2, [0, 0x20, 0x20, 0x7], 0.9), plant(ACT + 38 + 20, 2, [30, 40, 50, 0xFFF0], 0.9), plant(ACT + 38 + 6, 1, [0, 1, 2], 0.9)]
case("f06020276", [], True, ACTORS)
case("f060173CE", [], False, [plant(0x060D7768, 4, [0x060C2000], 1.0)] + ACTORS)
case("f0601768E", [span(0, 6), pick(0, 5, 0x10), pick(0, 5, 0x10)], False,
     [plant(0x060C063D, 1, [0, 1, 3, 5]), plant(bomber(0) + 22, 2, [3, 4], 0.9), plant(bomber(1) + 22, 2, [3, 4], 0.9), plant(bomber(2) + 22, 2, [3, 4], 0.9)]
     + [plant(bomber(i) + 20, 2, [0, 1, 2, 3], 0.8) for i in range(6)] + [plant(0x060EE8B0 + 2 * c, 2, [0, 0xFFFF, 0x1000, 0x2000], 0.8) for c in range(4)])
case("f06019ED2", [], False, [plant(0x060D7768, 4, [0x060C2000], 1.0), plant(0x060D7B3C, 4, [0x060C2400], 1.0), plant(0x060C2000 + 36, 2, [0, 1, 2])] + ACTORS + CHAIN)
LEVEL = [plant(bomber(i) + 36, 2, [0, 1, 2, 3], 0.9) for i in range(4)] + [plant(bomber(i) + 64, 2, [0, 1, 2, 3, 0xFFFF], 0.9) for i in range(4)] \
    + [plant(0x060D82DC + 20 * i + 4 * s, 4, [0, 1, 5, 100, 0x7FFFFFFF, 0xFFFFFFFF], 0.7) for i in range(4) for s in range(-1, 4)] \
    + [plant(0x060B46B8 + 12 * s + 4 * k, 4, [0, 1, 5, 50, 100, 0xFFFFFFFF], 0.7) for s in range(-2, 4) for k in range(3)]
case("f0601B12C", [span(0, 3)], True, LEVEL)
OTHER = [plant(0x060D8310, 4, [0x060C2200], 1.0), plant(0x060D8314, 4, [0x060C2300], 1.0)]
MOVER4 = [plant(0x060D7B3C, 4, [0x060C2400], 1.0)] + [plant(0x060C2400 + o, 2, [5, 7], 0.7) for o in (16, 18)] \
    + [plant(0x060C2300 + o, 2, [5, 7], 0.7) for o in (16, 18)] + [plant(0x060C2300 + o, 2, [0, 0, 1], 0.7) for o in (12, 14)]
case("f0601B710", [], False, CUR + OTHER + MOVER4 + [plant(0x060C2200 + 6, 1, [0, 1, 2]), plant(0x060D7768 + 0, 4, [bomber(0)], 1.0), plant(bomber(0) + 6, 1, [0, 1, 2])]
     + [plant(bomber(0) + 36, 2, [0, 1, 2], 1.0), plant(0x060BF5EA, 2, [0, 1])])
case("f0601BAA0", [], False, CUR + [plant(bomber(0) + 36, 2, [0, 1, 2], 1.0)])
case("f0601BC7E", [], False, CUR + [plant(bomber(0) + 36, 2, [0, 1, 2], 1.0)])
case("f0601BFC6", [], False, CUR + OTHER + [plant(0x060C2200 + 46, 2, [0, 0x800], 0.8), plant(0x060C2300 + 68, 2, [0x100, 0x100, 0, 5]), plant(0x060C2300 + 70, 2, [0x100, 0, 5]),
     plant(0x060D7B3C, 4, [0x060C2400], 1.0), plant(bomber(0) + 36, 2, [0, 1, 2, 3, 9], 1.0), plant(0x060C063D, 1, [0, 1, 2, 5]),
     plant(bomber(0) + 20, 2, [0, 1, 2, 3], 1.0)] + POS)
case("f0601C440", [], False, CUR + OTHER + [plant(0x060D7B3C, 4, [0x060C2400], 1.0), plant(bomber(0) + 6, 1, [0, 1, 3, 2], 1.0), plant(0x060C2200 + 6, 1, [0, 1, 3, 2], 1.0), plant(0x060C2400 + 52, 4, [0, 5, 100, 0xFFFFFFF0], 0.7), plant(0x060C2400 + 56, 4, [0, 5, 100, 0xFFFFFFF0], 0.7)])
case("f0601C510", [span(-1, 4)], False, [plant(0x060D8318, 4, [0x060C2500], 1.0)] + [plant(0x060C2500 + 2 * k, 2, [0, 0, 7], 0.8) for k in range(-1, 5)])
case("f0601D668", [pick(0, 1, 2, 3, 0x10001)], False, OTHER + [plant(0x060C2200 + 20, 2, [0, 1, 2, 3], 0.7)]
     + [plant(0x060EC8B0 + 2 * c, 2, [0, 0x20, 0x10, 0x30, 0x7F10], 0.8) for c in range(4)] + [plant(0x060F08B0 + 2 * c, 2, [0, 1, 0x100, 0xFF], 0.8) for c in range(4)] + FINDLATER)
case("f0601E96E", [pick(0, 1, 5, 0x10001), pick(0, 1, 2, 0x101)], False, ACTORS + [plant(ACT + 38 + 4, 2, [0, 1, 5], 0.7), plant(ACT + 38 + 19, 1, [0, 255, 7], 0.7),
     plant(0x060D8C08, 4, [ACT + 38], 1.0)])
# an actor in the chain that 0601F232 and 0601F2C0 look for: a byte at 16 above 1 and not 255, the id at 4, no bit of 0x1FA at 10
FIND = [plant(ACT + 7, 1, [1], 1.0), plant(ACT + 38 + 7, 1, [2, 2, 0], 1.0), plant(ACT + 76 + 7, 1, [0], 1.0),
        plant(ACT + 38 + 16, 1, [0, 1, 2, 5, 255, 5], 0.9), plant(ACT + 38 + 4, 2, [0, 1, 2, 3, 3], 0.9),
        plant(ACT + 38 + 10, 2, [0, 0, 0x1FA, 0x2], 0.9), plant(ACT + 38 + 6, 1, [0, 1, 2], 0.9),
        plant(ACT + 76 + 16, 1, [0, 1, 2, 5, 255, 5], 0.9), plant(ACT + 76 + 4, 2, [0, 1, 2, 3, 3], 0.9),
        plant(ACT + 76 + 10, 2, [0, 0, 0x1FA, 0x2], 0.9), plant(ACT + 76 + 6, 1, [0, 1, 2], 0.9),
        plant(ACT + 38, 2, [3, 3, 4], 1.0), plant(ACT + 76, 2, [3, 4], 1.0), plant(0x060C029C, 1, [17, 0, 3]),
        plant(0x060D82BA, 2, [0, 0, 16], 0.9), plant(0x060D82BC, 2, [0, 0, 16], 0.9)] + POS \
    + [plant(obj(3) + 16, 2, [0, 16, 5, 0], 1.0), plant(obj(3) + 18, 2, [24, 8, 40, 5], 1.0), plant(obj(4) + 16, 2, [0, 5], 1.0), plant(obj(4) + 18, 2, [24, 8], 1.0)]
case("f0601F232", [pick(0, 1, 2, 3, 0x10001), pick(0, 5, 16, 17, 100)], True, FIND)
case("f0601F2C0", [pick(0, 1, 2, 3, 0x10001), pick(0, 5, 16, 17, 100)], True, FIND)
# the same chain for the functions that count or pick actors by their flags
def actor(k, byte16, flags10, flags8, id4, owner, byte15=None, byte14=None):
    return [plant(ACT + 38 * k + 16, 1, byte16, 0.95), plant(ACT + 38 * k + 10, 2, flags10, 0.95), plant(ACT + 38 * k + 8, 2, flags8, 0.9),
            plant(ACT + 38 * k + 4, 2, id4, 0.9), plant(ACT + 38 * k + 15, 1, byte15 or [0, 1, 2], 0.9),
            plant(ACT + 38 * k + 14, 1, byte14 or [0, 0, 3, 5], 0.9)]
# the actors' links: next at 7 and previous at 6, so that releasing one leaves a chain
CHAIN3 = [plant(ACT + 7, 1, [1], 1.0), plant(ACT + 38 + 7, 1, [2], 1.0), plant(ACT + 76 + 7, 1, [3], 1.0), plant(ACT + 114 + 7, 1, [0], 1.0),
          plant(ACT + 38 + 6, 1, [0], 1.0), plant(ACT + 76 + 6, 1, [1], 1.0), plant(ACT + 114 + 6, 1, [2], 1.0)]
ACTS = CHAIN3 + actor(1, [0, 1, 2, 5, 255], [0, 0, 0x400, 0x80, 0x1FA, 0x1FB, 1, 0x401], [0, 1, 0x40, 1, 0x41], [0, 1, 2, 3, 3], [0, 1, 2]) \
    + actor(2, [0, 1, 2, 5, 255], [0, 0, 0x400, 0x80, 0x1FA, 0x1FB, 1, 0x401], [0, 1, 0x40, 1], [0, 1, 2, 3, 3], [0, 1, 2]) \
    + [plant(ACT + 38 * k + 24, 1, [0, 0, 5], 0.9) for k in (1, 2)] + [plant(ACT + 38 * k + 8, 2, [0x40, 0, 1], 0.5) for k in (1, 2)] \
    + [plant(0x060C062C, 2, [0, 1, 2], 0.9), plant(0x060D8C08, 4, [ACT + 38], 0.9), plant(0x060D7768, 4, [bomber(0)], 1.0), plant(bomber(0) + 20, 2, [0, 1, 2, 3], 1.0),
       plant(bomber(0) + 6, 1, [0, 1, 2, 3], 1.0), plant(0x060EC8B0 + 2 * 1, 2, [0x20, 0, 0x20], 0.9), plant(0x060EC8B0 + 2 * 2, 2, [0x20, 0, 0x20], 0.9),
       plant(0x060EC8B0, 2, [0x20, 0, 0x20], 0.9), plant(0x060EC8B0 + 2 * 3, 2, [0x20, 0, 0x20], 0.9)] + POS
case("f0601FEC6", [], True, ACTS)
case("f0601FF30", [pick(0, 0, 1)], True, ACTS)
case("f0601FFDA", [], True, ACTS + [plant(ACT + 38 * k + 10, 2, [0, 1, 0, 0x401, 0x80], 0.95) for k in (1, 2)] + [plant(ACT + 38 * k + 8, 2, [1, 1, 0x40], 0.95) for k in (1, 2)]
     + [plant(ACT + 38 * k + 16, 1, [2, 5, 0, 255], 0.95) for k in (1, 2)] + [plant(ACT + 38 * k + 4, 2, [1, 2, 3], 0.95) for k in (1, 2)]
     + [plant(bomber(0) + 20, 2, [1, 2], 1.0)] + [plant(ACT + 38 * k + 15, 1, [0, 1], 0.95) for k in (1, 2)] + [plant(0x060C062C, 2, [0, 1], 1.0)])
case("f06020330", [pick(0, 5)], True, ACTS + [plant(0x060B47F0 + 2 * k, 2, [0, 0, 1, 2, 0xFFFF], 0.8) for k in range(4)]
     + [plant(0x060D7E7E, 2, [1], 1.0), plant(0x060D7E82, 2, [63], 1.0), plant(0x060D7E7C, 2, [1], 1.0), plant(0x060D7E80, 2, [63], 1.0)])
case("f060203EC", [pick(0, 5), pick(0, 0, 2), pick(0, 1, 2, 3)], True, ACTS)
case("f06020DB4", [pick(0, 1, 2, 3)], True, ACTS)
case("f06020EE4", [pick(0, 1, 2, 3)], True, ACTS)
# the table of tables 06008ABA reads: bank 3 holds records the entries of 060CE060 are made from
BANK = [plant(0x060BD8E4 + 4 * b, 4, [0x060C3000 + 0x40 * b], 1.0) for b in range(8)] \
    + [plant(0x060C3000 + 0x40 * b + 4 * k, 4, [0x060C3800 + 0x40 * (b * 16 + k)], 1.0) for b in range(8) for k in range(16)]
# 06008A6A fills bank slot i from the pointer table n of 060BD8D4
BANK += [plant(0x060BD8D4 + 4 * n, 4, [0x060C3A00 + 0x80 * n], 1.0) for n in range(4)] \
    + [plant(0x060C3A00 + 0x80 * n + 4 * i, 4, [0x060C3000 + 0x40 * (i % 8)], 1.0) for n in range(4) for i in range(16)]
# each record starts a stream of 8-byte steps: a pointer, then a halfword that is 0 at the end
BANK += [plant(0x060C3800 + 0x40 * j + 4, 4, [0x060C6000 + 0x100 * (j % 16)], 1.0) for j in range(128)] \
    + [plant(0x060C3800 + 0x40 * j + 8, 2, [1, 2, 5], 1.0) for j in range(128)]
# the pointer leads to tiles: a width and a height in halfwords at 4 and 6, then 32 bytes a tile
BANK += [plant(0x060C6000 + 0x100 * m + o, 2, [0, 1, 2], 1.0) for m in range(16) for o in (4, 6)]
# the task record 060D7E60 points at: a position in halfwords at 12 and 14
BANK += [plant(0x060D7E60, 4, [0x060C2600], 1.0), plant(0x060C2600 + 12, 2, [0, 1, 2, 3], 1.0), plant(0x060C2600 + 14, 2, [0, 1, 2, 3], 1.0)]
BANK += [plant(0x060D7E98, 4, [0x060C4000], 1.0), plant(0x060D7EA0, 4, [0x060C4400], 1.0), plant(0x060D7E9C, 4, [0x060C4000], 1.0), plant(0x060D7EA4, 4, [0x060C4400], 1.0)]
# 060092D4 takes a free entry of the table at 060CE060 and a free sound record, or loops
case("f060240E0", [], False, FREE + BANK + [plant(ENTS + 16 * k + 11, 1, [0, 1], 0.5) for k in range(16)] + [plant(0x060BF4A4, 4, [-1, 5])])
case("f06024108", [], False, FREE + BANK + [plant(ENTS + 16 * k + 11, 1, [0, 1], 0.5) for k in range(16)] + [plant(0x060BF4A4, 4, [-1, 5])])
case("f0602410C", [], False, FREE + BANK + [plant(ENTS + 16 * k + 11, 1, [0, 1], 0.5) for k in range(16)] + [plant(0x060BF4A4, 4, [-1, 5])])
case("f06024130", [], False, FREE + BANK + [plant(ENTS + 16 * k + 11, 1, [0, 1], 0.5) for k in range(16)] + [plant(0x060BF4A4, 4, [-1, 5])])
case("f0602413C", [], False, FREE + BANK + [plant(ENTS + 16 * k + 11, 1, [0, 1], 0.5) for k in range(16)] + [plant(0x060BF4A4, 4, [-1, 5])])

TASKP = [plant(0x060D7E60, 4, [0x060C2600], 1.0), plant(0x060C2600 + 10, 2, [0, 1, 2], 1.0)]
case("f06025716", [], False, TASKP + BANK + FREE + [plant(0x060C02C0, 1, [0, 1, 2, 3])] + POS + CUR)
case("f06029E66", [pick(0, 1, 2, 3), pick(0, 1, 2, 3)], False, FREE + BANK + TASKP)
# the table of ten-byte entries at 060C0DF0, sorted by the key halfword at 0, and how many are in use
KEYS = [plant(0x060C0F80, 2, [0, 1, 2, 3, 4, 5, 6], 1.0)] + [plant(0x060C0DF0 + 10 * k, 2, [0xFFFF, 5, 3, 1, 9, 5, 0x7FFF, 0x8000], 0.95) for k in range(8)] \
    + [plant(0x060C0DF0 + 10 * k + o, 2, [0, 1, 7, 0xFFFF], 0.8) for k in range(8) for o in (2, 4, 6, 8)]
# a full table (no free entry, none with the key) takes some luck: forty entries, most holding 0x1234
case("f0602A6FA", [pick(-2, -1, 0, 1, 3, 5, 9, 0x10003), pick(0, 0x100, 0x200), pick(0, 5), pick(0, 7)], False,
     [plant(0x060C0F80, 2, [0, 1, 2, 3, 4, 5, 6], 1.0)] + [plant(0x060C0DF0 + 10 * k, 2, [0x1234], 0.99) for k in range(8, 40)]
     + [plant(0x060C0DF0 + 10 * k, 2, [0x1234] * 12 + [0xFFFF, 5, 3, 1, 9], 0.97) for k in range(8)]
     + [plant(0x060C0DF0 + 10 * k + o, 2, [0, 1, 7, 0xFFFF], 0.8) for k in range(8) for o in (2, 4, 6, 8)]
     + [plant(0x060FFFF0, 4, [0, 0x12345678, 0xFFFF], 1.0)])
case("f0602A7F6", [], False, KEYS)
case("f0602ACAE", [pick(-2, 0, 1, 3, 5, 9, 0x7FFF, 0x10003)], True, KEYS)
case("f0602ACE4", [pick(-2, 0, 1, 3, 5, 9, 0x7FFF, 0x10003)], True, KEYS)
case("f0602C540", [pick(-1, 0, 1, 2, 4, 5, 0x10003)], True,
     [plant(0x060C0640 + i, 1, [0, 1, 4, 5, 8, 9, 12, 13, 16, 17, 3, 19, 2], 1.0) for i in range(10)] + [plant(0x060C1044, 1, [0, 3, 10, 0x80, 0xFF, 5], 1.0)])
case("f0602C5BC", [pick(-2, -1, 0, 1, 2, 3, 4, 5, 0x10002)], True,
     [plant(0x060C0640 + i, 1, [0] * 8 + [1, 4, 5, 8, 9, 12, 13, 16, 17, 3, 19, 2], 1.0) for i in range(10)] + [plant(0x060C1044, 1, [0, 3, 10, 0x80, 0xFF, 5], 1.0)])
case("f0602D8A0", [pick(0, 112, 100, 0x12345, 300, -50, 224), pick(0, 1, 7, 8, 0x10002)], False,
     [plant(0x060C0FBE, 2, [0, 5, 0x7FFF], 0.8), plant(0x060C0FB8, 2, [3, 4], 1.0), plant(0x060C0FBA, 2, [3, 4], 1.0)])
# 0606AA90 walks the objects chained by the halfword at 8 until it reaches 1
case("f0602EA24", [], False, FREE + [plant(0x060C381C + 8, 2, [1, 1, 3], 1.0), plant(obj(3) + 8, 2, [1], 1.0)])
case("f0602F322", [], True, FREE)
case("f0602F368", [], True, FREE)
# eight entries of 16 bytes at 060C104C, linked in a ring by the bytes at 0 (next) and 1 (previous); the last one always qualifies
KEYED16 = [plant(0x060C104C + 16 * k, 1, [(k + 1) % 8], 1.0) for k in range(8)] + [plant(0x060C104C + 16 * k + 1, 1, [(k - 1) % 8], 1.0) for k in range(8)] \
    + [plant(0x060C104C + 16 * k + 4, 4, [0, 5, 0x1234], 0.7) for k in range(7)] + [plant(0x060C104C + 16 * k + 14, 2, [0, 0x10, 0x30, 0x20, 1], 0.7) for k in range(7)] \
    + [plant(0x060C104C + 16 * 7 + 4, 4, [5], 1.0), plant(0x060C104C + 16 * 7 + 14, 2, [0, 1], 1.0)]
case("f06031B28", [pick(0, 1, 2, 3, 0x10001)], True, KEYED16)
case("f06031B58", [pick(0, 1, 2, 3, 0x10001)], True, KEYED16)
case("f0603214E", [pick(0, 1, 2, 3), pick(0, 1, 5, 0x80, 0xFF)], False,
     KEYED16 + [plant(0x060C104C + 16 * k + o, 1, [0, 1, 2, 3], 1.0) for k in range(4) for o in (2, 3, 12, 13)])
# 0603666E finds the slot of 060EC478 holding (101, 1, 255) and the one holding (101, 2, 255)
SLOTS2 = [plant(ent(0), 2, [101, 101, 5], 0.95), plant(ent(0) + 2, 2, [1], 0.95), plant(ent(0) + 4, 2, [255], 0.95), plant(ent(0) + 12, 4, [0, 5], 0.95), plant(ent(0) + 18, 2, [3, 4], 0.95),
          plant(ent(1), 2, [101, 101, 5], 0.95), plant(ent(1) + 2, 2, [2], 0.95), plant(ent(1) + 4, 2, [255], 0.95), plant(ent(1) + 12, 4, [0, 5], 0.95), plant(ent(1) + 18, 2, [3, 4], 0.95)]
case("f06033D22", [], False, SLOTS2 + [plant(0x060C122C, 1, [0, 1, 2, 5], 1.0), plant(ent(2), 2, [101, 5], 0.8)]
     + [plant(obj(3) + 70, 2, [0, 5, 255, 256, 300, 0xFFFF], 0.9), plant(obj(4) + 70, 2, [0, 5, 255, 256, 300], 0.9)])
case("f060335B8", [], False, [plant(0x060C1048, 4, [0, 0x20, 0x30, 0x10, 0x32], 1.0)] + [plant(ent(k) + 12, 4, [-1, 0, 5], 0.6) for k in range(30)])
case("f0603461C", [ptr(0x060C0100, 0x40, 1)], False, [plant(0x060C0100 + k, 1, [0, 1, 2, 3, 4, 5, 6, 7, 0xFF, 0x80], 0.9) for k in range(0x40)])
case("f06034C3A", [ptr(0x060C0200, 0x40, 1)], False,
     [plant(0x060C1048, 4, [0x400, 0x400, 0, 0x800, 0xC00], 1.0)] + [plant(0x060C0640 + i, 1, [0, 1, 2, 3, 4, 5, 8, 9, 12, 13, 16, 17, 19], 1.0) for i in range(10)])
case("f06035D64", [pick(FIX)], False,
     [plant(FIX, 2, [0, 1, 0xFFFF], 1.0), plant(FIX + 16, 2, [0, 0xFFFF, 0xFFFF], 1.0), plant(FIX + 32, 2, [0xFFFF], 1.0)]
     + [plant(FIX + 16 * k + o, 2, [0, 1, 2, 101, 255], 0.8) for k in range(3) for o in (2, 4)] + [plant(FIX + 16 * k + 6, 2, [0, 0x0101, 0x1], 0.8) for k in range(3)])
# slots of 060EC478 for the lookups by id, with the flag word at 12 that the search and the release of 36F40 test
PT = [plant(ent(k) + 12, 4, [-1, 0, 0x01000000, 0x02000000, 0x03000000, 0x80000000, 0x40, 0x11000000], 0.9) for k in range(30)] \
    + [plant(ent(k), 2, [0, 1, 2, 3, 5], 0.8) for k in range(30)] + [plant(ent(k) + 2, 2, [0, 1, 2, 255, 5], 0.8) for k in range(30)] + [plant(ent(k) + 4, 2, [255, 255, 5], 0.8) for k in range(30)]
case("f06036F40", [pick(0, 1, 2, 3, 5, 255, 0x100FF)], False, PT)
# 06036FD0 links slot i to the first slot whose halfword at 4 equals the halfword at 0 of slot i: here 7, 9 and 11 form a chain
CHAINPT = [plant(ent(k), 2, [0, 1, 2, 3, 255], 1.0) for k in range(30)] + [plant(ent(k) + 4, 2, [0x7777], 1.0) for k in range(30)] \
    + [plant(ent(7) + 4, 2, [1], 1.0), plant(ent(9) + 4, 2, [2], 1.0), plant(ent(11) + 4, 2, [3], 1.0),
       plant(ent(7), 2, [2], 1.0), plant(ent(9), 2, [3], 1.0), plant(ent(11), 2, [0], 1.0)]
case("f0603703C", [pick(FIX), pick(-1, 0, 1, 2, 3, 7, 9, 11, 29, 30, 0x10002)], True,
     CHAINPT + [plant(FIX, 2, [0, 1, 2, 3, 7, 9, 11], 1.0), plant(FIX + 2, 2, [0, 1, 255, 5], 1.0), plant(FIX + 4, 2, [0x7777, 5], 1.0)]
     + [plant(ent(k) + 12, 4, [0, 5], 1.0) for k in range(30)] + [plant(ent(k) + 2, 2, [0, 1, 255], 1.0) for k in range(30)])

OBJ2 = 0x060C381C + 84 * 2
# the object table at 060C381C: 84 bytes each, chained by the halfwords at 6 and 8; one is free when its first word is 0
OBJFREE = [plant(0x060C381C + 84 * k, 4, [0, 0, 5, 0x1000], 0.5) for k in range(2, 12)] + [plant(0x060C1AAC, 2, [0, 5, 399, 400], 0.9)] \
    + [plant(0x060C381C + 84 * k + 8, 2, [1], 1.0) for k in range(1, 40)] + [plant(0x060C381C + 8, 2, [1, 2, 3, 4], 0.9), plant(OBJ2 + 8, 2, [3], 1.0), plant(OBJ2 + 84 + 8, 2, [4], 1.0), plant(OBJ2 + 168 + 8, 2, [1], 1.0)] \
    + [plant(0x060C381C + 84 * k, 4, [5, 0x2000, 0x1000, 0], 0.7) for k in (1, 2, 3, 4)] + [plant(0x060B7BA2, 2, [0, 2, 400], 0.7)]
case("f060691DA", [pick(0, 1, 100, 0x1000, 0x2000)], True, OBJFREE)
case("f06069194", [], False, [])
case("f060690AA", [], False, [plant(0x060B7BA4, 2, [0, 1], 0.5)] + [plant(0x060BC190 + 88 * k + 80, 1, [0], 1.0) for k in range(18)])
# 06008ADC reaches a bank's list through 060BD904; 06008ACC a record by its id; the list ends with -1, a record with a key of 0x8000 or more
LISTS = [plant(0x060BD904, 4, [0x060C2800], 1.0), plant(0x060C2800 + 4, 4, [0x060C2900], 1.0), plant(0x060C2800, 4, [0x060C2C00], 1.0)] \
    + [plant(0x060C2900 + 4 * (b - 1), 4, [0x060C2A00 + 0x40 * b], 1.0) for b in range(-1, 5)] \
    + [plant(0x060C2A00 + 0x40 * b + 4 * j, 2, [1, 2, 3, 0, 2], 0.8) for b in range(-1, 5) for j in range(4)] \
    + [plant(0x060C2A00 + 0x40 * b + 16, 2, [0xFFFF], 1.0) for b in range(-1, 5)] \
    + [plant(0x060C2C00 + 4 * (i - 1), 4, [0x060C2D00 + 0x80 * i], 1.0) for i in range(0, 5)] \
    + [plant(0x060C2D00 + 0x80 * i + 20 * k, 2, [0, 1, 5], 1.0) for i in range(0, 5) for k in range(2)] \
    + [plant(0x060C2D00 + 0x80 * i + 40, 2, [0x8000], 1.0) for i in range(0, 5)] \
    + [plant(0x060C2D00 + 0x80 * i + 20 * k + 2, 2, [0, 1, 2], 0.8) for i in range(0, 5) for k in range(3)]
case("f06068F14", [pick(FIX)], False, [plant(FIX + 16, 4, [0x060C2C00], 1.0), plant(FIX + 12, 4, [0x060C2C20], 1.0), plant(FIX + 8, 4, [0x060C6000], 1.0),
     plant(0x060C2C00 + 4, 2, [0, 0, 1], 0.7), plant(0x060C2C20 + 4, 2, [1, 2], 1.0), plant(0x060C2C00, 4, [0x060C3000], 1.0), plant(0x060C2C20, 4, [0x060C3000], 1.0),
     plant(0x060C3000 + 4, 2, [1, 2], 1.0), plant(0x060C3000 + 6, 2, [1, 2], 1.0), plant(FIX + 4, 2, [0, 5, 0xF0], 0.9)])
case("f06068F5A", [pick(0x060C3000), pick(0x060C6000), pick(0, 5, 16, 0xFF0, 0x1F0, 0xF0F0)], False,
     [plant(0x060C3000 + 4, 2, [0, 1, 2, 17], 1.0), plant(0x060C3000 + 6, 2, [0, 1, 2], 1.0)])
case("f060073B8", [], False, FREE)
case("f06038178", [pick(0, 1, 2, 3, 0x10002), ptr(0x060C0300, 0x20, 2)], False, OBJFREE)
case("f060381EA", [pick(0, 1, 2, 3, 0x10002), ptr(0x060C0300, 0x20, 2)], False, OBJFREE)
case("f0603BC98", [pick(0, 1, 5), pick(0, 5, 0x1234)], True, TASKP + [plant(0x060D7E64, 4, [0x060C2700], 1.0)] + BANK + FREE + POS)
case("f06040DEE", [pick(0, 1, 2, 3)], True, ACTS + [plant(0x060EC8B0 + 2 * c, 2, [0, 1, 7, 8], 0.8) for c in range(4)] + [plant(0x060F08B0 + 2 * c, 2, [0, 1], 0.9) for c in range(4)]
     + [plant(ACT + 38 * k + 15, 1, [0, 1, 5, 49, 50, 0x80, 0xFF], 0.9) for k in range(4)] + [plant(0x060C063D, 1, [0, 3, 10, 0x80], 0.9)])
# the bytes of the jump tables of SHC's shift routines (0609460C and 060947E4), which the check randomises with the data around them
SHTAB = [plant(0x060945EC + k, 1, [v], 1.0) for k, v in enumerate([14, 12, 10, 8, 6, 4, 2, 0, 32, 30, 28, 26, 24, 22, 20, 18, 52, 50, 48, 46, 44, 42, 40, 38, 64, 62, 60, 58, 72, 86, 98, 108])] + [plant(0x060947C4 + k, 1, [v], 1.0) for k, v in enumerate([14, 12, 10, 8, 6, 4, 2, 0, 32, 30, 28, 26, 24, 22, 20, 18, 52, 50, 48, 46, 44, 42, 40, 38, 64, 62, 60, 58, 72, 86, 98, 108])]
TBL = SHTAB + [plant(0x060FB89C, 2, list(range(16)), 1.0)] + [plant(0x060B7BA8 + 4 * k, 2, [0, 1, 2, 3, 5], 1.0) for k in range(16)] \
    + [plant(0x060B7BA8 + 4 * k + 2, 2, [0, 1, 2, 0xFFFF, 0xF0F0], 0.9) for k in range(16)] \
    + [plant(0x060B7BE8 + 4 * k, 2, [0, 1, 2, 3, 5], 1.0) for k in range(16)] + [plant(0x060B7BE8 + 4 * k + 2, 2, [0, 1, 2, 0xFFFF, 0xF0F0], 0.9) for k in range(16)]
case("f06045208", [pick(0, 1, 0x10002)], False, FREE + BANK + [plant(0x060B65B8 + 2 * k, 2, [0, 1, 2], 1.0) for k in range(8)] + [plant(0x060CBC60 + 2 * k, 2, [0, 0x1F, 0xFFFF], 0.8) for k in range(64)])
case("f06050F02", [pick(0, 1, 7, 8, 0xF)], True, TBL)
case("f06050F28", [pick(0, 1, 7, 8, 0xF)], True, TBL)
case("f06054350", [], True, FREE + BANK + [plant(ENTS + 16 * k + 11, 1, [0, 1], 0.5) for k in range(16)] + [plant(0x060BF4A4, 4, [-1, 5])])
case("f0605C9B4", [pick(0, 1, 5)], False, KEYS + [plant(0x060C1918, 2, [0, 1, 5, 300], 0.9)] + POS)
case("f0606950C", [pick(FIX), pick(0, 1, 7, 8, 0xF)], False, TBL)
case("f06069546", [pick(0, 1, 2, 3), pick(0, 1, 7, 8)], False, TBL)
case("f06069562", [pick(FIX)], True, TBL + [plant(FIX + 46, 2, [0, 0xFFFF, 0x1234], 0.9)])
case("f060695B0", [pick(FIX), pick(0, 1, 7, 8, 0xF)], False, TBL)
case("f06046A5C", [pick(0, 1, 2, 3)], True, SHTAB + [plant(0x060B672A + 2 * k, 2, [0, 1, 2, 3, 4, 5], 1.0) for k in range(12)]
     + [plant(0x060EE8B0 + 2 * c, 2, [0, 13, 14, 0x1D, 5], 0.8) for c in range(0, 16)])
case("f06065A12", [], False, [plant(0x060B2758 + 2 * k, 2, [0, 1, 2, 5, 0xFFFF], 0.9) for k in range(4)])
case("f0605DE8C", [pick(0, 1, 2, -1)], True, TASKP + [plant(0x060D7E64, 4, [0x060C2700], 1.0)] + BANK + FREE + POS + [plant(0x060B2686 + 2 * k, 2, [0, 5, 0x1234], 0.9) for k in range(3)])
case("f06052A00", [pick(0, 0, 1, 5)], False,
     [plant(0x060C17DA, 1, [0, 2, 4, 46, 47], 1.0)] + [plant(0x060B6BC0 + k, 1, [0, 1, 2, 3, 5], 0.9) for k in range(50)]
     + [plant(0x060B6B98 + 8 * k + o, 2, [0, 1, 0xFFFF], 0.8) for k in range(8) for o in (0, 2, 4, 6)] + SHTAB)
case("f06058598", [pick(0x060C0300)], False, BANK + [plant(0x060C0300 + 2 * k, 2, [3, 4, 5, 6], 1.0) for k in range(4)] + [plant(0x060B25E6 + 2 * k, 2, [0, 1, 20], 0.9) for k in range(8)])
case("f0605A85C", [pick(0, 1, 0x100, 0x101)], False,
     SLOTS2 + [plant(0x060C122C, 1, [0, 1, 2], 1.0), plant(ent(0) + 2, 2, [1, 2, 3, 0x101], 1.0), plant(ent(1) + 2, 2, [1, 2, 3], 1.0), plant(ent(2) + 2, 2, [1, 2, 3], 1.0),
               plant(0x060C1048, 4, [0, 0x40000, 0xC00, 0xFFFFFFFF], 0.8)])
case("f0606A400", [], False, [plant(0x060CBB5C, 4, [0x060C2700], 1.0), plant(0x060C1B04, 4, [0, 5, 802, 803, 1000], 1.0)]
     + [plant(0x060C1B08, 4, [0, 5, 0xFFFFFFF0], 0.9), plant(0x060C1B0C, 4, [0, 7, 0xFFFFFFF0], 0.9)] + [plant(0x060C2700 + o, 2, [0, 1, 0x1F, 0xFFF0], 0.8) for o in (4, 20, 22, 24, 26, 36, 38, 40, 46, 64)])
case("f0605112C", [], False, TBL + SHTAB + [plant(0x060C063C, 1, [0, 1, 2, 3, 4, 5, 6, 7, 8], 1.0), plant(0x060C1008, 1, [0, 0, 1, 2], 1.0), plant(0x060C1048, 4, [0, 0x20, 0x30, 0x10], 1.0)]
     + [plant(0x060C0640 + i, 1, [0, 1, 2, 3, 4, 5, 8, 9, 12, 13, 16, 17, 19], 1.0) for i in range(10)] + [plant(0x060DFE56 + 2 * i, 2, [3, 4, 5], 1.0) for i in range(10)])
case("f060535A2", [], False, [plant(0x060C17DB, 1, [0, 1, 2], 1.0)])
case("f0606725C", [], True, TASKP + [plant(0x060C2600 + o, 2, [0, 1, 7, 8, 100, 199, 200, 255, 256, 0xFFF0], 0.7) for o in (10, 12, 14, 16)] + BANK + FREE)
case("f0605CA10", [], False, TASKP + BANK + FREE + POS + [plant(0x060C0F80, 2, [0, 1, 2, 3], 1.0)] + [plant(0x060C0DF0 + 10 * k, 2, [0xFFFF, 0x1234], 0.7) for k in range(40)])
FALL = [plant(0x060C1658, 4, [0x060C2800], 1.0), plant(0x060C165C, 4, [0x060C2900], 1.0), plant(0x060C1048, 4, [0, 0x10, 0x20, 0x02000010, 0x30], 1.0)] \
    + [plant(ent(k) + 12, 4, [-1, 0, 5], 0.7) for k in range(30)] + [plant(0x060B70BC + 4 * k, 4, [0x0605B8C6], 0.9) for k in range(8)]
case("f0605B7A6", [], False, FALL + PT)
case("f0605B326", [], False, FALL + PT + [plant(0x060C0680 + k, 1, [0, 5], 0.8) for k in range(4)])
case("f06062C34", [pick(0, 1), pick(0, 5, 0x10003)], False, TASKP + BANK + FREE + OBJFREE + SHTAB + [plant(0x060C2600 + o, 2, [3, 4, 5, 0], 0.9) for o in (8, 10, 12)])
case("f060516B0", [pick(0, 1, 2, 4, -1), pick(3, 4), pick(5, 6), pick(0, 1, 100, -3)], False,
     SHTAB + TBL + [plant(0x060FFFF0 + 4 * k, 4, [0, 1, 5, 0x12345678, 0xFFFF], 1.0) for k in range(3)] + [plant(0x060C1008, 1, [0, 1, 2], 1.0)]
     + [plant(0x060B6B64 + k, 1, [0, 1, 0x7F, 0xFF], 0.9) for k in range(-1, 12)])
case("f06069906", [], False, BANK + LISTS + [plant(0x060CBB5C, 4, [0x060C2700], 1.0), plant(0x060C2700 + 10, 2, [1, 2, 3], 1.0), plant(0x060C1B04, 4, [0, 5, 0x322, 0x323], 0.9),
     plant(0x060C1B10, 4, [0, 1], 0.7)] + [plant(0x060C2700 + o, 2, [0, 5, 0x1234], 0.8) for o in (4, 16, 18, 36, 38, 40, 44, 46)])
# 0604 69A4 steps the object at 060D7E64 one unit a call towards the cell the task stands on (16 a column, with the scroll at 0)
WALK = [plant(0x060D82BA, 2, [0], 1.0), plant(0x060D82BC, 2, [0], 1.0), plant(0x060C029C, 1, [0, 17], 1.0), plant(0x060C2700 + 16, 2, [0, 16, 32, 15, 17, 31, 33, 1], 0.95),
        plant(0x060C2700 + 18, 2, [24, 8, 23, 25, 7, 9, 0], 0.95)]
case("f06046834", [], False, WALK + TASKP + [plant(0x060D7E64, 4, [0x060C2700], 1.0), plant(0x060C2600 + 12, 2, [0, 1, 2, 3, 4, 5, 6, 7], 1.0), plant(0x060C2600 + 14, 2, [0, 1, 2], 1.0),
     plant(0x060C2600 + 16, 2, [0, 0, 1, 5], 1.0)] + SHTAB + POS + [plant(0x060EE8B0 + 2 * c, 2, [0, 0, 0, 0, 0, 13, 14, 0x1D], 0.95) for c in range(0, 8)]
     + [plant(0x060B672A + 2 * k, 2, [0, 1, 2, 3, 4, 5], 1.0) for k in range(12)] + [plant(0x060B671A + 2 * k, 2, [0, 1, 2, 0xFFFF], 0.9) for k in range(10)])
case("f0604A8B4", [pick(0, 128, -128, 300), pick(0, 136, 200, -50), pick(FIX), pick(64, 0, 5, 0x10040)], False,
     [plant(0x060C1760, 1, [0, 1, 3, 5, 10], 1.0)] + [plant(FIX + 20 + 2 * k, 2, [3, 4, 5, 6, 7], 1.0) for k in range(10)]
     + [plant(0x060B22BE + 2 * k, 2, [0, 1, 2, 3, 0xFFFF], 0.5) for k in range(10)])
case("f0605A8F4", [], False, SHTAB + [plant(0x060C122C, 1, [0, 1, 2, 30], 1.0), plant(ent(0), 2, [12, 12, 5], 1.0), plant(ent(1), 2, [12, 5], 1.0), plant(ent(2), 2, [12], 1.0)]
     + [plant(ent(k) + 2, 2, [1, 2, 3, 4, 5, 0x101], 0.95) for k in range(3)] + [plant(0x060C1048, 4, [0x1000, 0x3000, 0, 0x2000], 1.0)]
     + [plant(0x060C1234, 4, [0, 0x55555, 0x55555, 0x15, 0x45, 0x155, 0x1555, 0x2, 0x6, 0x1A, 0x1A9, 0xFFFFF, 0xAAAAA], 0.97)] + [plant(0x06006134 + k, 1, [0, 1], 0.8) for k in range(8)]
     + [plant(0x060060B0, 2, [0, 0x4000, 0x8000, 0xC000], 1.0)])
case("f0603890C", [pick(0, 5, 16, 100), pick(0, 1, 3, 20), pick(FIX), pick(0, 1, 3, 100, -2)], False,
     [plant(0x060C1696, 2, [0, 1, 3, 50, 100], 1.0), plant(0x26006168, 4, [0, 1], 1.0)] + [plant(FIX + 2 * k, 2, [0, 1, 0x100, 0x1F00, 0xFFFF], 0.8) for k in range(60)]
     + [plant(0x060CBB60 + 2 * k, 2, [0, 1], 0.5) for k in range(10)] + [plant(0x06006048 + 0x20000000 - 0x20000000, 2, [0, 1], 1.0), plant(0x060BF4A8, 2, [0, 1, 3], 1.0)])
case("f060157E4", [], False, [plant(0x060C0686, 2, [0, 1, 3]), plant(0x060BF5E0, 2, [0, 1, 2])] + CUR + ACTS + [plant(0x060D7E68, 2, [0, 1], 0.5)])
case("f06021888", [pick(FIX)], False,
     [plant(FIX + k, 1, [0, 1, 2, 26, 5], 0.8) for k in range(4)] + [plant(FIX + 4, 1, [0], 1.0), plant(0x060C0682, 1, [0, 16], 0.8)]
     + [plant(0x060DFB96 + 8 * i + 5, 1, [0, 0, 7], 0.7) for i in range(1, 6)]
     + [plant(0x060D7E7C, 2, [1], 1.0), plant(0x060D7E80, 2, [5, 6], 1.0), plant(0x060D7E7E, 2, [1], 1.0), plant(0x060D7E82, 2, [3, 4], 1.0)]
     + [plant(0x060EC8B0 + 2 * c, 2, [0x10], 1.0) for c in range(0, 600)] + [plant(0x060F08B0 + 2 * c, 2, [0, 0, 0x100], 0.95) for c in range(0, 600)])
case("f060222D8", [pick(0, 21, 5, 0x10000, 0x10015), pick(0, 1, 2, 3, 0x10001)], True,
     OBJFREE + BANK + FREE + SHTAB + [plant(0x060F08B0 + 2 * c, 2, [0, 0, 3, 0x102], 0.8) for c in range(4)] + [plant(0x060DFB9B + 8 * k, 1, [0, 1], 0.6) for k in range(0, 80)]
     + [plant(0x060C029C, 1, [0, 17], 1.0), plant(0x060DF984, 2, [100, 101], 1.0)] + POS)
case("f06022C9C", [pick(0, 1, 3, 20, 100)], False, [plant(0x060B49BE + 2 * k, 2, [1, 0xFFFF, 64, 0xFFC0, 63], 1.0) for k in range(24)] +
     [plant(0x060D7E7C, 2, [1, 2], 1.0), plant(0x060D7E80, 2, [4, 6], 1.0), plant(0x060D7E7E, 2, [1], 1.0), plant(0x060D7E82, 2, [3, 5], 1.0)]
     + [plant(0x060D5F30 + 124 * k + 22, 2, [0, 1], 0.5) for k in range(50)] + [plant(0x060D5F30 + 124 * k + 20, 2, [0, 5, 70], 1.0) for k in range(50)]
     + [plant(0x060D5F30 + 124 * k + 58, 2, [0, 1], 1.0) for k in range(50)]
     + [plant(0x060EC8B0 + 2 * c, 2, [0, 0, 0x4C90, 0x10], 0.7) for c in range(0, 400)] + [plant(0x060EE8B0 + 2 * c, 2, [0, 0x1000], 0.6) for c in range(0, 100)])
case("f06021190", [pick(0, 1, 2, 3, 4), pick(0, 1, 2, 3), pick(65, 66, 100, 130), pick(0, 0, 1, 2)], False,
     [plant(0x060D8C08, 4, [0x060C2900], 1.0), plant(0x060C2900 + 36, 1, [0, 1, 5], 1.0), plant(0x060C2900 + 8, 2, [0, 16, 1], 0.8)]
     + [plant(0x060B47F0 + 2 * k, 2, [0, 1, 0xFFFF, 64, 0xFFC0], 1.0) for k in range(5)] + [plant(0x060B47FA + k, 1, [0, 1, 2, 3, 4], 1.0) for k in range(5)]
     + [plant(0x060D7E7E, 2, [0], 1.0), plant(0x060D7E7C, 2, [0], 1.0), plant(0x060D7E80, 2, [63], 1.0), plant(0x060D7E82, 2, [63], 1.0), plant(0x060DF978, 2, [0, 1, 0x40], 0.8)]
     + [plant(0x060EC8B0 + 2 * c, 2, [0, 0x4000, 0x80, 0x88, 0x4080, 0x2000, 0x20, 0x4290, 0x2080, 0], 0.9) for c in range(0, 300)]
     + [plant(0x060EE8B0 + 2 * c, 2, [0, 0x100, 0xF00, 0x200], 0.9) for c in range(0, 300)])
case("f06069A3E", [], False, BANK + LISTS + [plant(0x060CBB5C, 4, [0x060C2700], 1.0), plant(0x060C2700 + 10, 2, [1, 2, 3], 1.0), plant(0x060C1B04, 4, [0, 5, 0x322, 0x323], 0.9),
     plant(0x060C1B10, 4, [0, 1], 0.7), plant(0x060C1B08, 4, [0, 3], 0.8), plant(0x060C1B0C, 4, [0, 3], 0.8)] + [plant(0x060C2700 + o, 2, [0, 5, 0x1234], 0.8) for o in (4, 16, 18, 20, 22, 24, 26, 36, 38, 40, 44, 46, 64)])
case("f06069BD2", [], False, BANK + LISTS + [plant(0x060CBB5C, 4, [0x060C2700], 1.0), plant(0x060C2700 + 10, 2, [1, 2, 3], 1.0), plant(0x060C1B04, 4, [0, 5, 0x322, 0x323], 0.9),
     plant(0x060C1B10, 4, [0, 1], 0.7)] + [plant(0x060C2700 + o, 2, [0, 5, 0x1234, 0x100, 0x80], 0.8) for o in (4, 16, 18, 20, 22, 24, 26, 36, 38, 40, 44, 46, 64, 68, 70, 72, 74)])
case("f06069DBC", [], False, BANK + LISTS + [plant(0x060CBB5C, 4, [0x060C2700], 1.0), plant(0x060C2700 + 10, 2, [1, 2, 3], 1.0), plant(0x060C1B04, 4, [0, 5, 0x322, 0x323], 0.9),
     plant(0x060C1B10, 4, [0, 1], 0.7), plant(0x060C1B08, 4, [0, 3], 0.8), plant(0x060C1B0C, 4, [0, 3], 0.8)] + [plant(0x060C2700 + o, 2, [0, 5, 0x1234], 0.8) for o in (4, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 44, 46, 64)])
