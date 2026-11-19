from cases import case, pick, plant, ptr, span

OBJ = 0x060C2000
NODE = 0x060C4000
ANY4 = [("any",)] * 4

# Assumes the flag word is already zero, so neither wait loop runs; the loop calls a void function that leaves r0 undefined.
case("f06012D40", [], True, [plant(0x0607599C, 4, [0], 1.0), plant(0x060766A0, 4, [0], 1.0)])
# Assumes the list walked from +80 holds at most one node.
case("f06010B38", [pick(OBJ), ("any",), ("any",), ("any",)], True,
     [plant(OBJ + 80, 4, [0, NODE], 1.0), plant(NODE + 12, 4, [0], 1.0)])
# Assumes the list from 060875C8 has at most two nodes.
case("f0601CEEC", [], True,
     [plant(0x060875C8, 4, [0, NODE], 1.0), plant(NODE + 52, 4, [0, NODE + 0x100], 1.0),
      plant(NODE + 0x100 + 52, 4, [0], 1.0)] +
     [plant(a + o, 4, [0, 0, 1, NODE + 0x200], 0.9) for a in (NODE, NODE + 0x100) for o in (48, 56, 12, 16)])

# Assumes a countdown of at most 40 passes between the two bounds.
case("f0601DBAC", [("any",), ("any",), span(0, 16), span(0, 40)], True)
# Assumes the object's pointers into the work area are valid ones.
case("f06059434", [span(0, 4)], True,
     [plant(0x0608D890, 4, [OBJ], 1.0)] + [plant(OBJ + 220 * i + 128, 4, [0, 0, 0, 5], 1.0) for i in range(5)])
# Assumes a count of at most 64 bytes.
case("f060754D0", [ptr(0x060C0000, 0x100, 1), span(0, 255), span(0, 64)], True)
# Assumes the index table and the entries it points to lie in the work area.
case("f0606CDAC", [span(0, 40)], True,
     [plant(0x0608F008, 4, [8, 30, 100], 1.0), plant(0x0608EFEC, 4, [OBJ], 1.0), plant(0x0608EFD8, 4, [NODE], 1.0)])
# Assumes a target word that sits in the work area or in one of the two address ranges the code tests.
case("f0606F3F0", [pick(OBJ)], True,
     [plant(OBJ + 56, 4, [0, 1, 2, 3, 4], 1.0), plant(OBJ + 16, 4, [NODE], 1.0),
      plant(NODE, 4, [0x06000000, 0x00250000, 0x02100000, 0x00300000], 1.0)]
     + [plant(0x0608F030 + 4 * k, 4, [0, 0x060290A8], 1.0) for k in range(-100, 100)]    # the handlers dispatch through this table
     + [plant(0x0606EAFC + 12 * k, 4, [handler], 1.0) for k, handler in enumerate((0x0606F040, 0x0606F1E4, 0x0606F238, 0x0606F29C))])
case("f06071924", [pick(0, 1, 2)], True)
# Assumes at most 8 entries to clear and a work-area pointer for the two tables.
case("f060682E8", [], False,
     [plant(0x0608EFFC, 4, [0, 1, 4, 20], 1.0), plant(0x0608F014, 4, [OBJ], 1.0),
      plant(0x060896E8, 4, [NODE], 1.0), plant(0x060896EC, 2, [0, 3, 9], 0.8)])
# Assumes at most 8 entries in the table.
case("f0606BA48", [pick(OBJ)], True, [plant(OBJ + 4, 4, [0, 1, 3, 8], 1.0)])
# Assumes the caller gives a small tick limit.
case("f0605D8A0", [span(0, 16)], True)

# Assumes at most 3 table entries whose ids are among a few consecutive ones, so the id search ends within a few passes.
case("f060619A4", [], True,
     [plant(0x0608D88C, 4, [0, 1, 3], 1.0), plant(0x0608D890, 4, [OBJ], 1.0),
      plant(0x06079FB0, 2, [0x0400, 0x0401, 0x7FFE, 0x7FFF, 0xFFFE, 0xFFFF], 1.0)] +
     [plant(OBJ + 220 * i + 28, 2, [0x0400, 0x0401, 0x0402], 1.0) for i in range(3)] +
     [plant(OBJ + 220 * i, 2, [0, 1], 0.8) for i in range(3)])

N1, N2 = NODE + 0x400, NODE + 0x500
ARR = 0x060CA000
# Assumes a radius of at most 12 and the clip bounds hold only small values.
case("f06014FE4", [pick(OBJ), ("any",), span(-20, 20), span(0, 12)], True,
     [plant(OBJ + 136, 4, [0, 0, 1], 1.0), plant(OBJ + 16, 4, [0, 5, 50], 1.0),
      plant(OBJ + 28, 4, [0, 10, 100], 1.0), plant(OBJ + 24, 4, [0, 10, 100], 1.0),
      plant(OBJ + 0x10C8, 4, [0, 0, 1], 1.0), plant(OBJ + 0x10CC, 4, [0, 1, 2, 3, 4], 1.0)])
# Assumes the list from +80 holds at most one node.
case("f0601E268", [pick(OBJ), ("any",), ("any",), ("any",)], True,
     [plant(OBJ + 80, 4, [0, NODE], 1.0), plant(NODE + 12, 4, [0], 1.0)])
# Assumes at most 16 slots, a list of at most two nodes, and each node's row count at most 3.
case("f0601F088", [pick(OBJ)], False,
     [plant(OBJ + 4, 4, [ARR], 1.0), plant(OBJ + 40, 2, [0, 1, 4, 16], 1.0), plant(OBJ + 38, 2, [1, 4], 1.0),
      plant(OBJ, 4, [0, N1], 1.0), plant(N1 + 8, 4, [0, 1, 3], 1.0), plant(N1, 4, [0, N2], 1.0),
      plant(N1 + 4, 4, [0x060CC000], 1.0), plant(N2 + 8, 4, [0, 1, 3], 1.0), plant(N2, 4, [0], 1.0),
      plant(N2 + 4, 4, [0x060CD000], 1.0)])

BYTE = 0x060CC000
# Assumes the list from 060875C8 has at most two nodes.
case("f06021990", [("any",)] * 4, True,
     [plant(0x060875C8, 4, [NODE], 1.0), plant(NODE + 52, 4, [0, N2], 1.0), plant(N2 + 52, 4, [0], 1.0),
      plant(NODE + 56, 4, [0, BYTE], 1.0), plant(N2 + 56, 4, [0, BYTE], 1.0), plant(BYTE, 1, [0, 1, 2, 5], 1.0),
      plant(0x060765BC, 4, [0, BYTE], 1.0)])

# Assumes the lock byte is free, so the wait for it never runs; nothing here frees it during a trial.
case("f06025AE0", [pick(OBJ)], True, [plant(OBJ + 0xB8, 1, [0], 1.0)])

# Assumes at most 7 objects are allocated.
case("f0602B968", [span(0, 7)], True)
# Assumes the string table holds at most 3 entries and the caller asks for at most 5.
case("f0602E380", [ptr(0x060C0000, 0x400, 1), span(0, 8), span(0, 5)], True,
     [plant(0x0608BCFC, 4, [0, 1, 3], 1.0), plant(0x0608B97C, 4, [OBJ], 1.0), plant(OBJ + 20, 4, [NODE], 1.0)])
# Assumes a surface of at most 6 rows and 4 columns, with the pixel tables and the lookup table in the work area.
case("f0602FDD4", [pick(OBJ), ("any",), ptr(0x060C6000, 0x100, 1)], True,
     [plant(OBJ + 60, 2, [0, 1, 3, 6], 1.0), plant(OBJ + 16, 2, [1, 2, 4], 1.0), plant(OBJ + 20, 2, [1, 2, 4], 1.0),
      plant(OBJ + 8, 2, [0, 1], 1.0), plant(OBJ + 28, 4, [0, 100, 1000], 1.0), plant(OBJ + 52, 4, [0, 5, 50], 1.0),
      plant(OBJ + 24, 4, [0x060CE000], 1.0), plant(OBJ + 88, 4, [0, 1], 1.0), plant(OBJ + 40, 4, [0, 1, 2], 1.0),
      plant(OBJ + 44, 4, [0, 1, 2], 1.0)] + [plant(OBJ + 68 + 4 * k, 4, [0x1000, 0x2000], 1.0) for k in range(8)])
case("f06033168", [pick(OBJ), pick(NODE)], True,
     [plant(NODE + 32, 4, [4, 8, 3, 0], 1.0), plant(OBJ + 0x10C8, 4, [0, 1], 1.0), plant(OBJ + 0x10CC, 4, [3, 2, 1], 1.0),
      plant(OBJ + 64, 4, [0, 10], 1.0), plant(OBJ + 68, 4, [10, 100], 1.0), plant(NODE + 48, 4, [3, 20, 100], 1.0)])
# Assumes the parser stops within a few records.
case("f0603486C", [pick(OBJ), pick(NODE), span(0, 32)], True)
case("f06036CB0", [pick(OBJ), ("any",), pick(NODE), ("any",)], True)
# Assumes the two tables the code walks are in the work area and every entry count is at most 3.
case("f06038D40", [pick(OBJ)], True,
     [plant(OBJ + 0x1DF0, 4, [0x060C8000], 1.0), plant(OBJ + 0x1DEC, 4, [0x060CA000], 1.0)] +
     [plant(0x060CA000 + 4 * k, 4, [0, 1, 2, 3], 1.0) for k in range(17)])
case("f0603A178", [pick(OBJ), ("any",), ("any",), ("any",)], True)
# Assumes at most two list entries, each with at most 3 pointers.
case("f0603AD94", [pick(OBJ)], True,
     [plant(OBJ + 0x1DE0, 4, [0, N1], 1.0), plant(N1, 4, [0, 1, 2], 1.0),
      plant(N1 + 76, 4, [0, N2, N2 + 0x100], 1.0), plant(N1 + 80, 4, [0, N2, N2 + 0x100], 1.0)] +
     [plant(a + 4, 4, [0, 1, 2, 3], 1.0) for a in (N2, N2 + 0x100)] +
     [plant(a + 40, 4, [ARR], 1.0) for a in (N2, N2 + 0x100)] +
     [plant(ARR + 4 * k, 4, [0, NODE], 1.0) for k in range(4)] + [plant(NODE + 20, 4, [0, 0x060CE000], 1.0)])

# Assumes a size of at most 3 either way.
case("f060419E0", [ptr(0x060C0000, 0x100, 4), span(-3, 3), ("any",), ("any",)], True)
# Assumes at most 5 entries in the work table and a few words to copy.
case("f06057B38", [span(0, 4), pick(0, 1, 2, 3), ("any",), ("any",)], True,
     [plant(0x0608D890, 4, [OBJ], 1.0)] +
     [plant(OBJ + 220 * i + o, 4, [0, 1, 4, 16], 1.0) for i in range(5) for o in (40, 44, 52, 64)])
case("f06044030", [ptr(0x060C0000, 0x100, 1), ("any",), ("any",), ("any",)], True)
case("f0604A400", [pick(OBJ), ("any",), ("any",), ("any",)], True)
case("f06051988", [], True)
case("f06051C84", [pick(OBJ), ("any",), ("any",), ("any",)], True)
case("f06052364", [pick(OBJ)], True)
# Assumes at most 3 table entries.
case("f0605AE6C", [("any",), span(0, 20)], True,
     [plant(0x0608D9E8, 4, [0, 1, 3], 1.0), plant(0x0608D9EC, 4, [OBJ], 1.0), plant(0x0608D9F0, 4, [NODE], 1.0),
      plant(0x0608D9F0 + 0, 4, [NODE], 1.0)] + [plant(NODE + 24 * i, 1, [0, 1], 1.0) for i in range(4)])
case("f0605B398", [ptr(0x060C0000, 0x100, 1), ptr(0x060C1000, 0x400, 1)], True)
# Assumes at most 3 table entries.
case("f0605EE94", [pick(OBJ), ("any",), pick(0, 1, 5)], True,
     [plant(0x0608D88C, 4, [0, 1, 3], 1.0), plant(0x0608D890, 4, [OBJ, NODE], 1.0), plant(0x0608D388, 4, [NODE], 1.0)])
# Assumes the index is under 40 and its table, which f0606CDAC reads, lies in the work area.
case("f060690BC", [span(0, 40), ("any",), ("any",), ("any",)], True,
     [plant(0x060896BC, 4, [NODE], 1.0), plant(0x0608F01C, 4, [0, 5], 1.0), plant(0x0608F008, 4, [8, 30, 100], 1.0),
      plant(0x0608EFEC, 4, [OBJ], 1.0), plant(0x0608EFD8, 4, [N2], 1.0)])
# Assumes the state word is not 6 or 7, so the wait loop that nothing ends during a trial does not run.
case("f0606EBF8", [pick(OBJ), ("any",)], True,
     [plant(OBJ + 108 + 52, 4, [0, 3, 8, 9], 1.0), plant(0x0608F444, 4, [NODE], 1.0),
      plant(OBJ + 108 + 12, 4, [0], 1.0), plant(OBJ + 108 + 16, 4, [0], 1.0)])
# Assumes an image of at most 12 columns and 6 rows.
case("f0603B1DC", [pick(OBJ), span(0, 12), span(0, 6), ptr(0x060C6000, 0x400, 1)], True,
     [plant(OBJ + 0x1DE0, 4, [0x060C7000], 1.0), plant(0x060C7000 + 76, 4, [0x060C7100], 1.0),
      plant(0x060C7000 + 80, 4, [0x060C7200], 1.0), plant(0x060C7000 + 84, 4, [0x060C7300], 1.0),
      plant(0x060C7100 + 44, 4, [0x060C8000], 1.0), plant(0x060C7200 + 44, 4, [0x060C8400], 1.0),
      plant(0x060C7300 + 44, 4, [0x060C8800], 1.0)])
