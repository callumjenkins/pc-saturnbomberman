"""Which of r0 to r7 a function reads before writing them: its arguments, by what its code does. And
the runtime routines SHC calls for an operator, which take r0 and r1.

A backward liveness over the function's own instructions, the recompiler's code for it. A call or a
tail branch reads what its callee reads, found the same way, and a call leaves r0 to r7 written. A push
of r0 to r3 is a routine saving a scratch register, and a push of r8 to r14 a function saving its
caller's: neither is a read.
"""
import re

from saturnrecomp import sh2

ARGUMENTS = frozenset({4, 5, 6, 7})          # what a callee nobody can read is taken to read
# KRNL's division routines, r1 by r0: each leaves the result in r0 and changes r1.
DIVISIONS = {0x0609410C: "DIVS", 0x060941C0: "DIVU", 0x06094268: "MODS", 0x06094330: "MODU"}
# SHC's other runtime routines in KRNL, which loop, so the C calls them through guest.h's macros: the C
# for a call, with {rN} for what the register holds, and the registers the routine changes.
LIBRARY = {
    0x0609460C: ("SHL({r0}, {r1})", {1}),
    0x060947E4: ("SHR({r0}, {r1})", {1}),
    0x060946CC: ("SAR({r0}, {r1})", {1}),
    0x06094B70: ("DIVS16({r1}, {r0})", {1}),
    0x060945B4: ("COPYB({r1}, {r2}, {r0})", {1}),
    0x06094450: ("COPYW(0x06094450, {r1}, {r2}, {r0})", {1}),
    0x0609445C: ("COPYW(0x0609445C, {r1}, {r2}, {r0})", {1}),
    0x060944F4: ("COPYW(0x060944F4, {r1}, {r2}, {r0})", {1}),
    0x06094C24: ("STRCPY({r0}, {r1})", {1}),
    0x06094BC0: ("STRCMP({r0}, {r1})", {1}),
    0x06094B08: ("BITSET({r2}, {r0}, {r1})", set()),
}
# Ops whose last operand, a register, is only written.
_MOVES = frozenset({"mov", "mov.b", "mov.w", "mov.l", "mova", "movt", "sts", "stc", "exts.b", "exts.w",
                    "extu.b", "extu.w", "neg", "negc", "not", "swap.b", "swap.w"})
# Ops that read their last operand, a register, and leave it as it was.
_KEEPS = frozenset({"cmp/eq", "cmp/ge", "cmp/gt", "cmp/hi", "cmp/hs", "cmp/pl", "cmp/pz", "cmp/str", "tst",
                    "div0s", "mul.l", "muls.w", "mulu.w", "dmuls.l", "dmulu.l", "jmp", "jsr", "braf", "bsrf",
                    "ldc", "lds"})
_CACHES: dict[int, dict[int, frozenset[int] | None]] = {}     # per map of functions: address to what it reads, None while being read
_REG = re.compile(r"\br(\d+)\b")
_CALLS = ("bsr", "jsr", "bsrf")
_TAILS = ("bra", "jmp", "braf")
_SHIFTS = {"shar": (">>", 1), "shll": ("<<", 1), "shll2": ("<<", 2), "shll8": ("<<", 8), "shll16": ("<<", 16),
           "shlr": (">>", 1), "shlr2": (">>", 2), "shlr8": (">>", 8), "shlr16": (">>", 16)}


def reads(image: sh2.Image, address: int, functions: dict[int, set[int]]) -> frozenset[int]:
    """r0 to r7 the function at address reads before writing them. A function without code in
    `functions`, or one reached again while it is being read, is taken to read ARGUMENTS."""
    return frozenset(r for r in _live(image, address, functions) if r < 8)


def saved(image: sh2.Image, address: int, functions: dict[int, set[int]]) -> frozenset[int]:
    """r8 to r14 the code at address reads before writing them, which a function's entry never does:
    code there is the middle of a larger function, and needs its caller's registers."""
    return frozenset(r for r in _live(image, address, functions) if 8 <= r <= 14)


def _live(image: sh2.Image, address: int, functions: dict[int, set[int]]) -> frozenset[int]:
    cache = _CACHES.setdefault(id(functions), {})
    if address in cache:
        return cache[address] if cache[address] is not None else ARGUMENTS
    code = functions.get(address)
    if code is None:
        return ARGUMENTS
    cache[address] = None
    nodes = {}
    islands = [pc for pc in sorted(code) if pc - 2 not in code and pc != address]
    for pc in sorted(code):
        ins = image.insn(pc)
        if pc - 2 in code and image.insn(pc - 2).delay:
            continue                                    # a delay slot, part of its branch's node
        nodes[pc] = _node(image, ins, code, functions, islands)
    live: dict[int, frozenset[int]] = {pc: frozenset() for pc in nodes}
    changed = True
    while changed:
        changed = False
        for pc in sorted(nodes, reverse=True):
            uses, defs, after = nodes[pc]
            out = frozenset().union(*(live[n] for n in after if n in live))
            new = uses | (out - defs)
            if new != live[pc]:
                live[pc] = new
                changed = True
    cache[address] = frozenset(r for r in live.get(address, frozenset()) if r < 15)
    return cache[address]


def _node(image: sh2.Image, ins: sh2.Insn, code: set[int], functions: dict[int, set[int]],
          islands: list[int]) -> tuple[frozenset[int], frozenset[int], list[int]]:
    """(registers read, registers written, the instructions that can come next) for one instruction,
    with its delay slot, which runs before the branch takes effect. A jmp through a table goes to any of
    the islands, the function's code that follows data, where the recompiler found the table's targets."""
    uses, defs = _operands(ins)
    after = [ins.pc + 2]
    if ins.delay:
        slot_uses, slot_defs = _operands(image.insn(ins.pc + 2))
        uses, defs = uses | (slot_uses - defs), defs | slot_defs
        after = [ins.pc + 4]
    if ins.op in ("rts", "rte"):
        return uses, defs, []
    target = ins.target if ins.op in ("bsr", "bra") else _loaded(image, ins, code) if ins.op in ("jsr", "jmp") else None
    if ins.op == "jmp" and target is None and islands:
        return uses, defs, islands
    leaves = ins.op in _TAILS and (target is None or target not in code)
    if ins.op in _CALLS or leaves:
        callee = _live(image, target, functions) if target is not None else ARGUMENTS
        uses = uses | (callee - defs)
        if leaves:
            return uses, defs, []
        helper = routine(image, target, functions) if target is not None else None
        written = {0} | helper[1] if helper else set(range(8))      # SHC's routines keep r4 to r7
        return uses, defs | frozenset(written), after
    if ins.op in _TAILS:
        return uses, defs, [target]
    if ins.op in ("bt", "bf", "bt/s", "bf/s"):
        return uses, defs, after + [ins.target]
    return uses, defs, after


def routine(image: sh2.Image, address: int, functions: dict[int, set[int]]) -> tuple[str, set[int]] | None:
    """The C for a call to a runtime routine, with {r0} to {r2} for what they hold, and the registers other
    than r0 it changes: a division, one of LIBRARY, or a run of shifts of r0 to its rts. None for any other
    function."""
    if address in DIVISIONS:
        return "%s({r1}, {r0})" % DIVISIONS[address], {1}
    if address in LIBRARY:
        return LIBRARY[address]
    code = functions.get(address)
    kinds, count = set(), 0
    for pc in sorted(code or ()):
        ins = image.insn(pc)
        if ins.op == "rts":
            continue
        if ins.op not in _SHIFTS or ins.n != 0:
            return None
        kinds.add("shar" if ins.op == "shar" else ins.op[:4])
        count += _SHIFTS[ins.op][1]
    if len(kinds) != 1:
        return None
    kind = kinds.pop()
    value = {"shar": "(int){r0}", "shlr": "(unsigned int){r0}", "shll": "{r0}"}[kind]
    return "HELPER(%s %s %d)" % (value, _SHIFTS[kind][0], count), set()


def _loaded(image: sh2.Image, ins: sh2.Insn, code: set[int]) -> int | None:
    """The address a jsr or jmp goes to, where one of the 32 instructions before it loads the register from a
    literal and nothing between writes it again."""
    for pc in range(ins.pc - 2, ins.pc - 66, -2):
        if pc not in code:
            return None
        prior = image.insn(pc)
        if prior.op == "mov.l" and prior.target is not None and prior.n == ins.n:
            return image.u32(prior.target)
        if ins.n in _operands(prior)[1] or prior.delay:
            return None
    return None


def _operands(ins: sh2.Insn) -> tuple[frozenset[int], frozenset[int]]:
    text = ins.text
    parts = text.split(None, 1)
    operands = re.split(r",(?![^(]*\))", parts[1]) if len(parts) > 1 else []
    uses: set[int] = set()
    defs: set[int] = set()
    for i, operand in enumerate(operands):
        regs = {int(r) for r in _REG.findall(operand)}
        bare = re.fullmatch(r"r\d+", operand.strip()) is not None
        last = i == len(operands) - 1
        if last and bare and ins.op in _MOVES:
            defs |= regs
            continue
        uses |= regs
        if (last and bare and ins.op not in _KEEPS) or "+" in operand or "@-" in operand:
            defs |= regs
    if ins.op == "mov.l" and len(operands) == 2 and operands[1].strip() == "@-r15":
        uses -= {r for r in map(int, _REG.findall(operands[0])) if r < 4 or 8 <= r <= 14}
    return frozenset(uses), frozenset(defs)
