from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

A = 0x060C0100
SF = 0x20100063
# The BIOS vector table is not in the image: each pointer is made to reach a routine that returns 1, and the
# frame counter that an interrupt would advance is put where a wait for it is already over.
RET1 = 0x060290A8
BIOS = [plant(0x06000330, 4, [RET1], 1.0), plant(0x06000334, 4, [RET1], 1.0), plant(0x06000344, 4, [RET1], 1.0)]
FRAMES = [plant(0x06089CB0, 4, [0x7FFFFFFE], 1.0)]
# The allocator at 060279E0 stores its caller's return address in a block it hands out, which the host's call does not set,
# so a trial where it succeeds differs in that word. A limit of zero makes every request fail.
NOHEAP = [plant(0x0608AC98, 4, [0], 1.0), plant(0x0608AC9C, 4, [0], 1.0)]
# The allocator's error report keeps a short log of messages, in a table of pointers.
HEAPLOG = [plant(0x0608ACB0, 4, [0, 1, 3], 1.0), plant(0x0608ACB8, 4, [0x060C0F00], 1.0), plant(0x060C0F00, 4, [0x060C0F40], 1.0)]

# The callee clears the status byte at the argument and queues the argument at 0608AB84. Nothing else the loop calls
# sets that byte, so the argument is the queue's own link word, and the queueing stores its address there, making
# the byte 6 and ending the wait.
case("f06020DE4", [pick(0x0608AB84)], True, BIOS + [plant(0x0608AB84, 4, [0], 1.0), plant(0x060767D0, 4, [0, 5, 9], 0.5)])

# The argument vector: a count of up to three strings, each a pointer to some bytes that end in a zero. The block for them
# is never granted, so the run ends at the failure return.
VEC = 0x060C0400
STR = 0x060C0600
case("f06043B20", [], True,
     BIOS + [plant(0x0608BD04, 4, [0, 1, 2, 3], 1.0), plant(0x0608BD08, 4, [VEC], 1.0)]
     + [plant(VEC + 4 * k, 4, [STR + 0x40 * k], 1.0) for k in range(3)]
     + [plant(STR + 0x40 * k + n, 1, [0x41, 0x42, 0], 1.0) for k in range(3) for n in range(8)]
     + NOHEAP)

# Every vector the reset routine calls goes to a routine that returns, and the SMPC command flag reads clear.
VECTORS = [plant(a, 4, [RET1], 1.0) for a in (0x06000300, 0x06000310)]
case("f060466D0", [], True, BIOS + VECTORS + [plant(SF, 1, [0], 1.0), plant(0x06075994, 4, [0], 1.0), plant(0x0608D854, 4, [0], 1.0)])

# A reader whose heap (+112) holds up to three chunks; each chunk names its first byte, its length, and its data.
H, ARR, KEYS, H2 = 0x060C0200, 0x060C0240, 0x060C0280, 0x060C0B00
CHUNK, DATA = 0x060C0400, 0x060C0600
case("f06059768", [pick(A), pick(0, 0x060C0900), span(0, 12)], True,
     [plant(0x0608D390, 4, [RET1], 1.0), plant(A + 112, 4, [H], 1.0), plant(A + 108, 4, [0, 4, 9, 20], 1.0), plant(A + 116, 4, [0, 4, 9, 20], 1.0),
      plant(A + 120, 4, [H2], 1.0), plant(H, 4, [8], 1.0), plant(H2, 4, [8, 2], 1.0), plant(H2 + 4, 4, [0, 1], 1.0),
      plant(H2 + 12, 4, [0x060C0A00], 1.0), plant(H2 + 16, 4, [0x060C0A40], 1.0), plant(H + 4, 4, [1, 2, 3], 1.0), plant(H + 12, 4, [KEYS], 1.0),
      plant(H + 16, 4, [ARR], 1.0)]
     + [plant(ARR + 4 * k, 4, [CHUNK + 0x40 * k], 1.0) for k in range(4)]
     + [plant(KEYS + 4 * k, 4, [0, 1, 2, 5], 1.0) for k in range(4)]
     + [plant(CHUNK + 0x40 * k + 4, 4, [0, 1, 3, 5], 1.0) for k in range(4)]
     + [plant(CHUNK + 0x40 * k + 8, 4, [0, 1, 2, 4], 1.0) for k in range(4)]
     + [plant(CHUNK + 0x40 * k + 12, 4, [DATA + 0x40 * k], 1.0) for k in range(4)])

# The allocator's two pools: a base and a size each, a free list and a list of tagged blocks, and the log the error report keeps.
# Free blocks at +0x40 and +0x200 and tagged blocks at +0x80 and +0x100 in each pool, linked head to tail or cut short.
POOLS = [0x060C1000, 0x060C2000]
case("f06028254", [("any",)] * 4, True,
     BIOS + [plant(0x0608ACB0, 4, [0, 1, 3, 5], 1.0), plant(0x0608ACB8, 4, [0x060C0F00], 1.0), plant(0x060C0F00, 4, [0x060C0F40], 1.0)]
     + [plant(0x0608AC30 + 4 * v, 4, [POOLS[v]], 1.0) for v in range(2)] + [plant(0x0608AC98 + 4 * v, 4, [0x400, 0x300], 1.0) for v in range(2)]
     + [plant(0x0608ACA0 + 4 * v, 4, [0, POOLS[v] + 0x40, POOLS[v] + 0x40], 1.0) for v in range(2)]
     + [plant(0x0608AC40 + 4 * v, 4, [0, POOLS[v] + 0x80, POOLS[v] + 0x80], 1.0) for v in range(2)]
     + [plant(p + 0x40, 4, [0, p + 0x200], 1.0) for p in POOLS] + [plant(p + 0x44, 4, [0x20, 0x40, 0x10], 1.0) for p in POOLS]
     + [plant(p + 0x200, 4, [0], 1.0) for p in POOLS] + [plant(p + 0x204, 4, [0x20, 0x40], 1.0) for p in POOLS]
     + [plant(p + o, 4, [0xBABE0000, 0xBABE0001], 1.0) for p in POOLS for o in (0x80, 0x100)]
     + [plant(p + 0x84, 4, [0, p + 0x100, p + 0x100], 1.0) for p in POOLS]
     + [plant(p + 0x104, 4, [0], 1.0) for p in POOLS])

# A path string of letters, slashes, dots, hash marks and quotes ending in a zero, which the caller's record names.
PATH, OUT = 0x060C0A00, 0x060C0C00
case("f0603C0BC", [pick(A), pick(OUT), pick(OUT + 0x80), pick(OUT + 0x90)], True,
     BIOS + NOHEAP + [plant(A, 4, [PATH], 1.0)]
     + [plant(PATH + k, 1, [0x41, 0x42, 0x2F, 0x2E, 0x23, 0x22, 0x30, 0x2F, 0x41, 0], 1.0) for k in range(24)])

# A packet whose header is 20 bytes at +16, then a body of two halfwords (type and subtype, and the complement that makes the
# ones'-complement sum 0xFFFF, which is what a sound packet sums to); the records it is matched against are 220 and 24 bytes.
# Type 8 is left out: its handler uses what the vector returns as a pointer, and the vector returns 1.
NET, RECS, SLOTS = 0x060C0D00, 0x060C1400, 0x060C1A00
SOUND = [(word << 16) | (0xFFFF - word) for word in ((t << 8) | s for t in range(0, 22) if t != 8 for s in (0, 1, 5, 12, 13))]
case("f06061CB4", [("any",), pick(A), ("any",), ("any",)], True,
     [plant(0x0608D390, 4, [RET1], 1.0), plant(0x0608D3A8, 4, [RET1], 1.0), plant(A + 4, 2, [0x10], 1.0), plant(A + 0x10, 1, [0x45], 1.0), plant(A + 0x12, 2, [24], 1.0),
      plant(A + 0x24, 4, SOUND, 1.0), plant(A + 0x35, 1, [6, 17, 0, 6], 1.0),
      plant(A + 0x38, 2, [0x1111, 0x2222], 0.8), plant(A + 0x3A, 2, [0x1111, 0x2222], 0.8), plant(A + 0x3C, 2, [0x1111, 0x2222], 0.8),
      plant(A + 0x3E, 2, [0x1111, 0x2222], 0.8), plant(A + 0x44, 2, [0x1111, 0x2222], 0.8), plant(A + 0x42, 2, [0x1111, 0x2222], 0.8),
      plant(0x0608D88C, 4, [0, 1, 2, 3], 1.0), plant(0x0608D890, 4, [RECS], 1.0), plant(0x0608D9E8, 4, [0, 1, 2, 3], 1.0),
      plant(0x0608D9F0, 4, [SLOTS], 1.0)]
     + [plant(RECS + 220 * k, 2, [0, 1], 0.8) for k in range(4)] + [plant(RECS + 220 * k + 18, 2, [0x1111, 0x2222], 0.8) for k in range(4)]
     + [plant(RECS + 220 * k + 28, 2, [0x1111, 0x2222], 0.8) for k in range(4)] + [plant(RECS + 220 * k + 20, 4, [0x11112222, 0x22221111], 0.8) for k in range(4)]
     + [plant(RECS + 220 * k + 24, 4, [0x11112222, 0x22221111], 0.8) for k in range(4)]
     + [plant(SLOTS + 24 * k, 1, [0, 1], 0.8) for k in range(4)] + [plant(SLOTS + 24 * k + 4, 2, [0x1111, 0x2222], 0.8) for k in range(4)])

# A jar of cookies at 0608BD10 (44 bytes each, the copy of the text at +40), a text of up to a few attributes, and a count that is below 100.
JAR, TXT2 = 0x0608BD10, 0x060C0E00
case("f06045FE0", [pick(A), pick(TXT2)], True,
     BIOS + NOHEAP + [plant(0x060791BC, 4, [0, 1, 5, 99], 1.0)]
     + [plant(JAR + 44 * k + 40, 4, [0, 0, 0x060C0F80], 0.7) for k in range(100)]
     + [plant(TXT2 + k, 1, [0x61, 0x3D, 0x3B, 0x20, 0], 1.0) for k in range(24)])

# A widget record at the argument: +0 names a kind, +20 a list of 24-byte records that ends in a zero first longword.
OBJ, RECS2 = 0x060C1000, 0x060C1100
case("f0602E554", [pick(A), span(0, 400), span(0, 300), ("any",)], True,
     BIOS + NOHEAP + [plant(0x060FFFF0, 4, [0x060C1200], 1.0), plant(0x060C1200, 4, [0, 1, 1], 1.0), plant(A, 4, [OBJ], 1.0), plant(OBJ, 4, [3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27], 1.0),
                      plant(OBJ + 16, 4, [0, 1], 1.0), plant(OBJ + 20, 4, [RECS2], 1.0)]
     + [plant(0x060769D4, 4, [A], 1.0), plant(A + 20, 4, [0x060C0200], 1.0)]
     + [plant(0x0608BCF4, 4, [0, 1, 3], 1.0), plant(0x0608BD04, 4, [0, 1, 3], 1.0), plant(0x0608BCF8, 4, [0x060C1400], 1.0),
        plant(0x0608BD08, 4, [0x060C1400], 1.0), plant(0x060767CC, 4, [0x060C1300], 1.0)]
     + [plant(0x060C1300 + k, 1, [0x41, 0x2F, 0], 1.0) for k in range(16)]
     + [plant(0x060C1400 + k, 1, [0x41, 0x42, 0], 1.0) for k in range(16)]
     + [plant(0x060C0200 + 24 * i, 4, [10, 10, 5, 0] if i < 7 else [0], 1.0) for i in range(8)]
     + [plant(RECS2 + 24 * k, 4, [1, 2, 3, 4, 5, 10] if k < 3 else [0], 1.0) for k in range(4)]
     + [plant(RECS2 + 24 * k + o, 2, [0, 10, 100, 200, 300, 400], 0.8) for k in range(3) for o in (4, 6, 8, 10)])

# A line from (x0, y0) to (x1, y1) of at most 70 cells on a 64 by 64 canvas at 060C3000, with the colour in the sixth argument.
COORDS = [-5, 0, 1, 7, 20, 31, 32, 63, 64, 70]
case("f06014C4C", [pick(A), pick(*COORDS), pick(*COORDS), pick(*COORDS)], True,
     BIOS + NOHEAP + [plant(0x060FFFF0, 4, COORDS, 1.0), plant(0x060FFFF4, 4, [0, 1, 0x80, 0xFF], 1.0), plant(A + 16, 4, [0, 1], 1.0), plant(A + 24, 4, [64], 1.0),
      plant(A + 28, 4, [0], 1.0), plant(A + 40, 4, [0x060C3000], 1.0), plant(A + 44, 4, [64], 1.0), plant(A + 136, 4, [0], 1.0),
      plant(A + 0x10C8, 4, [0, 1], 1.0), plant(A + 0x10CC, 4, [0, 3, 5], 1.0),
      plant(A + 148, 4, [0, 0x060C1900], 1.0), plant(A + 144, 4, [0x060C1800], 1.0), plant(A + 152, 4, [0x060C1800], 1.0), plant(A + 156, 4, [0], 1.0), plant(A + 160, 4, [0x400, 0x800], 1.0), plant(0x060C1900, 4, [0], 1.0), plant(A + 164, 4, [0, 1, 7], 1.0)])

# A text context with a short line at +0x1B0, and the font lookup that the glyph code asks for: a cached node and a list of
# 64-byte nodes (the longword at +0 the font id, the byte at +4 the flag, the longword at +8 the width table).
TEXTCTX, FNT, FDATA, FLIST = 0x060C6000, 0x060C8000, 0x060C9800, 0x060C9000
GLYPHS = [0x80, 0x41, 0x20, 0x81, 0x42, 0x40]
FONT = ([plant(TEXTCTX + 0x10B4, 4, [0x1200], 1.0), plant(0x06076568, 4, [FNT], 1.0), plant(FNT, 4, [0x1200], 1.0), plant(FNT + 4, 1, [0x80], 1.0),
         plant(FNT + 8, 4, [FDATA], 1.0), plant(0x060875C8, 4, [FLIST], 1.0)]
        + sum([[plant(FLIST + 64 * k, 4, [0x1200], 1.0), plant(FLIST + 64 * k + 4, 1, [g], 1.0), plant(FLIST + 64 * k + 8, 4, [FDATA], 1.0),
                plant(FLIST + 64 * k + 52, 4, [FLIST + 64 * (k + 1) if k < len(GLYPHS) - 1 else 0], 1.0)] for k, g in enumerate(GLYPHS)], []))
case("f0601D4D8", [pick(TEXTCTX), ("any",), ("any",), ("any",)], False,
     BIOS + NOHEAP + HEAPLOG + FONT + [plant(TEXTCTX + 0x10D4, 4, [0], 1.0), plant(TEXTCTX + 56, 4, [0, 1, 2, 3], 1.0)]
     + [plant(TEXTCTX + 0x1B0 + k, 1, [0x41, 0x20, 0x2E, 0, 0x31] if k < 2 else [0], 1.0) for k in range(4)])
