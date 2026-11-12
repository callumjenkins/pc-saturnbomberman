from cases import case, pick, plant

# Each byte of the player table, shifted right two, indexes a five-halfword total on the stack.
PLAYER_KINDS = [plant(0x060C0640 + i, 1, [0] * 8 + [1, 4, 5, 8, 9, 12, 13, 16, 17, 3, 19, 2], 1.0) for i in range(10)]

case("f06034C02", [], True, PLAYER_KINDS)

# The first argument points at a block whose second word points at a block holding the third pointer at +16, and the
# task block the callee writes through is at 060FC00C.
BLOCK, INNER, TARGET, TASK = 0x060C0200, 0x060C0300, 0x060C0400, 0x060C0500
case("f060A2C18", [pick(BLOCK, BLOCK, BLOCK, 0), pick(0x300, 0x301, 5), ("any",), ("any",)], True,
     [plant(BLOCK + 4, 4, [INNER], 1.0), plant(INNER + 16, 4, [TARGET], 1.0), plant(0x060FC00C, 4, [TASK], 1.0)])

# Each of 32 slots of a table holds an object whose first word points at a table of methods, and the methods at
# +0x170 and +0x1C0 return zero. A slot is live when its bit is set in the table's mask.
OBJECT, METHODS, RETURNS = 0x060C0300, 0x060C0400, 0x0600A4E6
METHOD_TABLE = [plant(OBJECT, 4, [METHODS], 1.0), plant(METHODS + 0x170, 4, [RETURNS], 1.0), plant(METHODS + 0x1C0, 4, [RETURNS], 1.0)]
SLOTS = [plant(slot + 4 * n, 4, [OBJECT], 1.0) for slot in (0x060FC0E8, 0x060FC190) for n in range(32)]
LIVE = [plant(0x060BB98C, 4, [0xFFFFFFFF], 1.0), plant(0x060FC210, 4, [0xFFFFFFFF], 1.0)] \
    + [plant(table + 4 * n, 4, [0, 0xFFFFFFFF, 1 << n], 0.5) for table in (0x060BBA9C, 0x060B12F8) for n in range(32)]
for name in ("f060A3A54", "f060A476C"):
    case(name, [pick(OBJECT, 0, 0), ("any",), ("any",), ("any",)], True, METHOD_TABLE + SLOTS + LIVE)
