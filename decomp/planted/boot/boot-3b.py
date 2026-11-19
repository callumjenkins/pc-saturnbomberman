from cases import bomber, case, ent, obj, pick, plant, ptr, slot, span  # noqa: F401

# The BIOS vector table is not in the image: each pointer is made to reach a routine that returns 1.
RET1 = 0x060290A8
BIOS = [plant(0x06000330, 4, [RET1], 1.0), plant(0x06000334, 4, [RET1], 1.0), plant(0x06000344, 4, [RET1], 1.0)]
RET = 0x060727A6        # a function that only shifts r4 and returns, for a callback the code is given
# Assumes the busy flag at 060759D0 is clear, so the wait for it never runs, and the callback returns at once.
case("f06016610", [ptr(0x060C0000, 0x100, 4), pick(RET), ("any",), ("any",)], True, [plant(0x060759D0, 4, [0], 1.0)])

TXT = 0x060C5400
CTX = 0x060C6000
FNT = 0x060C8000
FDATA = 0x060C9800
LIST = 0x060C9000
GLYPHS = [0x80, 0x41, 0x20, 0x81, 0x42, 0x40]       # the flag bytes the font lookup is asked for
# Assumes a one-character text, a font lookup that hits the cached node for the first call and a list of nodes from
# 060875C8 for the others (a node is the 64-byte record whose first longword is the font id, the byte at +4 the flag,
# the longword at +8 the width table), and a small index at +56 of the context.
case("f0601DD98", [pick(CTX), pick(TXT), pick(0, 1), ("any",)], True,
     [plant(TXT, 2, [0x8000, 0x8000, 0], 1.0), plant(TXT + 2, 2, [0], 1.0)]
     + [plant(TXT + 8 + 2 * i, 2, [0], 1.0) for i in range(8)]
     + [plant(CTX + 0x10B4, 4, [0x1200], 1.0), plant(0x06076568, 4, [FNT], 1.0), plant(FNT, 4, [0x1200], 1.0), plant(FNT + 4, 1, [0x80], 1.0),
        plant(FNT + 8, 4, [FDATA], 1.0), plant(0x060875C8, 4, [LIST], 1.0)]
     + sum([[plant(LIST + 64 * k, 4, [0x1200], 1.0), plant(LIST + 64 * k + 4, 1, [g], 1.0), plant(LIST + 64 * k + 8, 4, [FDATA], 1.0),
             plant(LIST + 64 * k + 52, 4, [LIST + 64 * (k + 1) if k < len(GLYPHS) - 1 else 0], 1.0)] for k, g in enumerate(GLYPHS)], [])
     + [plant(CTX + 56, 4, [0, 1, 2, 3], 1.0)] + BIOS)

# The allocator at 060279E0 gives up on a request above the limits at 0608AC98 and 0608AC9C, and stores its caller's
# return address in the block it hands out, which the host's call does not set, so every request is above the limit.
HEAPS = [plant(0x0608AC98, 4, [0x100000], 1.0), plant(0x0608AC9C, 4, [0x100000], 1.0),
         plant(0x0608ACA0, 4, [0x060D0000], 1.0), plant(0x0608ACA4, 4, [0x060E0000], 1.0),
         plant(0x060D0000, 4, [0], 1.0), plant(0x060D0004, 4, [0x6000], 1.0),
         plant(0x060E0000, 4, [0], 1.0), plant(0x060E0004, 4, [0x6000], 1.0)]
NOHEAP = [plant(0x0608AC98, 4, [0], 1.0), plant(0x0608AC9C, 4, [0], 1.0)]
OS = 0x060CA000
# The kernel object at 0608F444 has no error callback (the longword at +0xB8), and no tasks in its table, so a lookup of the
# current task fails with an error code that is stored and returned.
KERNEL = [plant(0x0608F444, 4, [OS], 1.0), plant(OS + 0xB8, 4, [0], 1.0), plant(0x0608F454, 4, [1, 2, 5], 1.0),
          plant(OS + 0x9C, 4, [0], 1.0)]
case("f06020EB8", [], True, BIOS + NOHEAP + KERNEL)

# Assumes the first allocation fails (limit above), so the node is not filled in.
case("f0602ECE0", [("any",)] * 4, True, BIOS + NOHEAP)

TBL, STRS = 0x060C7000, 0x060C7100
# Assumes at most 3 argument strings of fewer than 8 bytes; the allocation of the block that holds them fails (see NOHEAP).
case("f06043C08", [], True,
     [plant(0x0608BCF4, 4, [0, 1, 2, 3], 1.0), plant(0x0608BCF8, 4, [TBL], 1.0)]
     + [plant(TBL + 4 * k, 4, [STRS + 16 * k], 1.0) for k in range(3)]
     + [plant(STRS + 16 * k + 7, 1, [0], 1.0) for k in range(3)] + NOHEAP)

TQ = 0x060C7400
# The callback at 0608D39C is a routine that returns 1; the frame counts it is compared with are small. The ten 16-byte
# timer entries at 0608D380 hold a state byte, a small delay and an empty queue.
case("f0605E050", [("any",)] * 4, True,
     [plant(0x0608D39C, 4, [RET1], 1.0), plant(0x06079F6C, 4, [0, 1, 2, 5], 1.0), plant(0x0608D394, 4, [1, 2, 8, 100], 1.0),
      plant(0x0608D380, 4, [TQ], 1.0)]
     + [plant(TQ + 16 * k, 1, [0, 1, 2, 3, 3], 1.0) for k in range(10)] + [plant(TQ + 16 * k + 4, 4, [0, 1, 3, 100], 1.0) for k in range(10)]
     + [plant(TQ + 16 * k + 12, 4, [0], 1.0) for k in range(10)])

NET, OPT, BUFP = 0x060C7800, 0x060C7900, 0x060C7A00
GETTER = 0x0605215C      # returns the longword at 060766B4, so the allocation callback hands out the buffer planted there
# Assumes the option list at +20 holds at most two 8-byte entries, ended by a negative byte, and the allocation callback returns a buffer.
case("f06060E64", [pick(NET), ("any",), ("any",), ("any",)], True,
     [plant(NET + 12, 2, [0xC021, 0xC025, 0x8021, 0xC023, 0x0021], 1.0), plant(NET + 20, 4, [OPT], 1.0), plant(NET + 36, 4, [0, BUFP], 1.0),
      plant(OPT + 1, 1, [0x80, 2, 3], 1.0), plant(OPT + 9, 1, [0x80], 1.0),
      plant(0x0608D3A0, 4, [GETTER], 1.0), plant(0x060766B4, 4, [BUFP], 1.0), plant(0x0608D390, 4, [RET1], 1.0), plant(0x0608D39C, 4, [RET1], 1.0),
      plant(0x0608D9C8, 4, [BUFP + 0x100], 1.0)])

WTAB, REC, STR = 0x060C7C00, 0x060C7D00, 0x060C7E00
# Assumes the 24-byte table at 06077CF8 holds the id 13 at its first entry, whose record gives a width limit of 5 to 100,
# the string is at most 7 bytes, each character is at most 3 wide, and the allocation fails (see NOHEAP).
case("f06042C0C", [pick(STR)], False,
     [plant(0x0608BCD0, 4, [0, 1, 1], 1.0), plant(0x06077CF8, 4, [13], 1.0), plant(0x06077CF8 + 20, 4, [REC], 1.0),
      plant(REC + 8, 2, [5, 20, 100], 1.0), plant(REC + 4, 2, [0, 1], 1.0), plant(0x0608AB70, 4, [WTAB], 1.0),
      plant(0x060773D4, 4, [0, 0x060791A8], 1.0), plant(0x060773E0, 4, [0], 1.0), plant(STR + 7, 1, [0], 1.0)]
     + [plant(WTAB + i, 1, [0, 4, 8, 12], 1.0) for i in range(128)] + BIOS + NOHEAP)

SLOT = 0x0608BD10
# Assumes every one of the 100 44-byte slots at 0608BD10 is free, so none has a block to give back.
case("f060462F8", [span(-2, 5), ("any",)], True, BIOS + [plant(SLOT + 44 * k + 40, 4, [0], 1.0) for k in range(100)])

# The width and the row count are loop bounds, so they are small; the stride at the stack argument is a few bytes.
POINT = ptr(0x060C0100, 4, 4)
D = 0x060C2000
case("f0603B100", [POINT, span(0, 8), span(0, 8), ptr(0x060C5400, 0x100, 1)], True,
     [plant(0x060C0100 + 0x1DE0, 4, [D], 1.0), plant(D + 76, 4, [0x060C3000], 1.0), plant(D + 80, 4, [0x060C3100], 1.0),
      plant(D + 84, 4, [0x060C3200], 1.0), plant(0x060C302C, 4, [0x060C4000], 1.0),
      plant(0x060C312C, 4, [0x060C4400], 1.0), plant(0x060C322C, 4, [0x060C4800], 1.0),
      plant(0x060FFFF0, 4, [0, 4, 16], 1.0)])

T1, T2, A5, A6, OUT = 0x060C6000, 0x060C6400, 0x060C6800, 0x060C6900, 0x060C6A00
# The two tables hold 32-byte entries whose halfword at +2 links to the next index. Pair i of each array starts at
# index 4i or 4i + 1 (or is empty, -1) and ends at 4i + 2, so no chain meets one an earlier pair already rewrote.
case("f0606CDF8", [span(0, 4), pick(A5), pick(A6), pick(OUT)], True,
     [plant(0x0608EFD8, 4, [T1], 1.0), plant(0x0608F020, 4, [0, T2, T2], 1.0)]
     + [plant(t + 32 * k + 2, 2, [k + 1], 1.0) for t in (T1, T2) for k in range(16)]
     + [plant(a + 4 * i, 2, [0xFFFF, 4 * i, 4 * i + 1], 1.0) for a in (A5, A6) for i in range(4)]
     + [plant(a + 4 * i + 2, 2, [4 * i + 2], 1.0) for a in (A5, A6) for i in range(4)])
