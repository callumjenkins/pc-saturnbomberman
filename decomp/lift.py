"""A first draft of a function's C, from its SH-2 instructions.

    python decomp/lift.py ADDRESS [--module KRNL] [--append]

The draft is straight from the instructions: registers become locals (r4 to r7 are the parameters,
stack slots become v locals), loads and stores go through LD and ST, calls go through GCALL, and the
control flow is rebuilt as if, while, break and continue. It is meant to be read and rewritten; run.py's
cosim decides whether it is right. Raises Unsupported for what it cannot read: a jump table, a pointer
to a local, a stack argument, a control-register access, or code that reads a register it never set.
"""
import argparse
import os
import re
import sys
from dataclasses import dataclass, field

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import status  # noqa: E402
import structure  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

IMAGES = {"KRNL": ("build/extract/BOMSS/0KRNL.BIN", 0x06006000)}
_REG = re.compile(r"\br(\d+)\b")
_SIZES = {"b": 1, "w": 2, "l": 4}
_LOAD = {1: "LD8", 2: "LD16", 4: "LD32"}
_STORE = {1: "ST8", 2: "ST16", 4: "ST32"}
_CALLS = ("bsr", "jsr")
_BRANCHES = ("bt", "bf", "bt/s", "bf/s", "bra", "rts", "bsr", "jsr")


class Unsupported(Exception):
    pass


_NUMBER = re.compile(r"^-?(?:0x[0-9A-Fa-f]+|\d+)$")
_VAR = re.compile(r"\b[rcv]\d+\b")
_LOCAL_TYPES = {1: "signed char", 2: "short", 4: "int"}


@dataclass
class Stmt:
    """One statement of a block. `var` is the variable it assigns, if it is an assignment."""
    var: str | None
    expr: str
    pure: bool = True                       # an assignment that can be dropped when unused, or inlined
    kills: set[str] = field(default_factory=set)     # variables it overwrites besides `var`

    @property
    def uses(self) -> set[str]:
        return set(_VAR.findall(self.expr))

    @property
    def defs(self) -> set[str]:
        return ({self.var} if self.var else set()) | self.kills

    def text(self) -> str:
        return "%s = %s;" % (self.var, strip(self.expr)) if self.var else self.expr


@dataclass
class State:
    """Registers while one block is read: the statements so far and which registers hold a known number."""
    stmts: list[Stmt] = field(default_factory=list)
    known: dict[int, int] = field(default_factory=dict)
    clobbered: set[int] = field(default_factory=set)
    fresh: set[int] = field(default_factory=set)         # written since the last call, on every path here
    flag: str | None = None
    macl: str | None = None
    flags: int = 0                          # how many flag variables have been made so far
    sp: int = 0                             # r15 relative to its value on entry
    slots: dict[int, int] = field(default_factory=dict)     # the function's stack locals: offset to size

    def get(self, reg: int) -> str:
        if reg in self.clobbered:
            raise Unsupported("r%d is read after a call overwrote it" % reg)
        return const(self.known[reg]) if reg in self.known else "r%d" % reg

    def put(self, reg: int, expr: str, pure: bool = True) -> None:
        self.clobbered.discard(reg)
        self.fresh.add(reg)
        if _NUMBER.match(expr):
            self.known[reg] = int(expr, 0)
        else:
            self.known.pop(reg, None)
        self.stmts.append(Stmt("r%d" % reg, expr, pure))

    def temp(self, expr: str) -> str:
        name = "c%d" % self.flags
        self.flags += 1
        self.stmts.append(Stmt(name, expr))
        return name

    def set_flag(self, expr: str) -> None:
        self.flag = self.temp(expr)

    def put_local(self, name: str, expr: str) -> None:
        self.stmts.append(Stmt(name, expr))

    def effect(self, text: str) -> None:
        self.stmts.append(Stmt(None, text, False))


def const(value: int) -> str:
    value &= 0xFFFFFFFF
    if value >= 0x80000000:
        return str(value - (1 << 32)) if value >= 0xFFFF0000 else "(int)0x%08X" % value
    return str(value) if value < 256 else "0x%08X" % value if value >= 0x10000 else "0x%X" % value


def number(text: str) -> int | None:
    if text.startswith("(int)"):
        text = text[5:]
    return int(text, 0) if _NUMBER.match(text) else None


_FOLD = {"+": lambda a, b: a + b, "-": lambda a, b: a - b, "&": lambda a, b: a & b, "|": lambda a, b: a | b,
         "^": lambda a, b: a ^ b, "<<": lambda a, b: a << b, "*": lambda a, b: a * b}


def op2(left: str, symbol: str, right: str) -> str:
    a, b = number(left), number(right)
    if a is not None and b is not None and symbol in _FOLD:
        return const(_FOLD[symbol](a, b))
    return "(%s %s %s)" % (left, symbol, right)


def unsigned(expr: str) -> str:
    return "(unsigned)%s" % expr


def signed(expr: str) -> str:
    """An unsigned result as the int a register holds, so a later compare is signed as the SH-2's is."""
    return "(int)%s" % expr


def address(base: str, offset: int | str) -> str:
    return base if offset == 0 else op2(base, "+", str(offset))


def sp_change(ins: "sh2.Insn") -> int:
    """How far an instruction moves r15."""
    if ins.op in ("sts.l", "mov.l") and ins.n == 15 and "@-Rn" in ins.fmt:
        return -4
    if ins.op in ("lds.l", "mov.l") and ins.m == 15 and "@Rm+" in ins.fmt:
        return 4
    if ins.op == "add" and ins.n == 15 and ins.imm is not None:
        return ins.imm
    return 0


def local(st: State, offset: int, size: int, ins: "sh2.Insn") -> str:
    if offset >= 0:
        raise Unsupported("reads an argument passed on the stack at %08X" % ins.pc)
    if st.slots.setdefault(offset, size) != size:
        raise Unsupported("a stack slot used at two sizes at %08X" % ins.pc)
    return "v%d" % -offset


def frame(ins: "sh2.Insn", st: State) -> bool:
    """Handles an instruction that uses r15 as the frame: saves and restores, and the function's locals."""
    op, fmt, n, m = ins.op, ins.fmt, ins.n, ins.m
    if op == "add" and n == 15 and ins.imm is not None:
        st.sp += ins.imm
        return True
    if op in ("sts.l", "lds.l"):
        st.sp += sp_change(ins)
        return True
    if op == "mov.l" and fmt == "mov.l Rm,@-Rn" and n == 15:
        st.sp -= 4
        if not 8 <= m <= 14:
            st.put_local(local(st, st.sp, 4, ins), st.get(m))
        return True
    if op == "mov.l" and fmt == "mov.l @Rm+,Rn" and m == 15:
        if not 8 <= n <= 14:
            st.put(n, local(st, st.sp, 4, ins))
        st.sp += 4
        return True
    if op.startswith("mov.") and "@" in fmt:
        size = _SIZES[op[-1]]
        source, dest = operands(fmt)
        offset = ins.disp or 0
        if dest.startswith("@") and (n == 15 and dest in ("@Rn", "@(disp,Rn)")):
            value = st.get(0 if source == "r0" else m)
            if size < 4:
                value = "(%s)%s" % (_LOCAL_TYPES[size], value)
            st.put_local(local(st, st.sp + offset, size, ins), value)
            return True
        if source in ("@Rm", "@(disp,Rm)") and m == 15:
            st.put(0 if dest == "r0" else n, local(st, st.sp + offset, size, ins), pure=True)
            return True
    return False


def step(ins: "sh2.Insn", st: State, image: "sh2.Image") -> None:
    op, fmt, n, m = ins.op, ins.fmt, ins.n, ins.m
    if n == 15 or m == 15 or "r15" in fmt:
        if frame(ins, st):
            return
        raise Unsupported("takes the address of a local or moves r15 at %08X" % ins.pc)
    if op == "nop":
        return
    if op == "mov" and fmt == "mov Rm,Rn":
        st.put(n, st.get(m))
    elif op == "mov" and fmt == "mov #imm,Rn":
        st.put(n, const(ins.imm))
    elif op in ("mov.w", "mov.l") and "@T" in fmt:
        value = image.literal(ins)
        if value is None:
            raise Unsupported("a literal outside the image at %08X" % ins.pc)
        st.put(n, const(value))
    elif op == "mova":
        st.put(0, "0x%08X" % ins.target)
    elif op.startswith("mov.") and "@" in fmt:
        memory(ins, st)
    elif op == "add" and fmt == "add Rm,Rn":
        st.put(n, op2(st.get(n), "+", st.get(m)))
    elif op == "add":
        st.put(n, op2(st.get(n), "+" if ins.imm >= 0 else "-", str(abs(ins.imm))))
    elif op in ("sub", "and", "or", "xor") and ins.m is not None:
        st.put(n, op2(st.get(n), {"sub": "-", "and": "&", "or": "|", "xor": "^"}[op], st.get(m)))
    elif op in ("and", "or", "xor") and ins.imm is not None:
        st.put(0, op2(st.get(0), {"and": "&", "or": "|", "xor": "^"}[op], const(ins.imm)))
    elif op == "not":
        st.put(n, "(~%s)" % st.get(m))
    elif op == "neg":
        st.put(n, "(-%s)" % st.get(m))
    elif op in ("shll", "shal"):
        st.put(n, op2(st.get(n), "<<", "1"))
        st.flag = None
    elif op == "shar":
        st.put(n, op2(st.get(n), ">>", "1"))
        st.flag = None
    elif op == "shlr":
        st.put(n, signed(op2(unsigned(st.get(n)), ">>", "1")))
        st.flag = None
    elif op in ("shll2", "shll8", "shll16"):
        st.put(n, op2(st.get(n), "<<", op[4:]))
    elif op in ("shlr2", "shlr8", "shlr16"):
        st.put(n, signed(op2(unsigned(st.get(n)), ">>", op[4:])))
    elif op == "extu.b":
        st.put(n, op2(st.get(m), "&", "255"))
    elif op == "extu.w":
        st.put(n, op2(st.get(m), "&", "0xFFFF"))
    elif op == "exts.b":
        st.put(n, "(signed char)%s" % st.get(m))
    elif op == "exts.w":
        st.put(n, "(short)%s" % st.get(m))
    elif op == "swap.w":
        st.put(n, op2(op2(st.get(m), "<<", "16"), "|", signed(op2(unsigned(st.get(m)), ">>", "16"))))
    elif op == "xtrct":
        st.put(n, op2(op2(st.get(m), "<<", "16"), "|", signed(op2(unsigned(st.get(n)), ">>", "16"))))
    elif op.startswith("cmp/"):
        compare(ins, st)
    elif op == "tst":
        left = st.get(0) if ins.m is None else st.get(n)
        right = const(ins.imm) if ins.m is None else st.get(m)
        st.set_flag(op2(op2(left, "&", right), "==", "0"))
    elif op == "dt":
        st.put(n, op2(st.get(n), "-", "1"))
        st.set_flag(op2(st.get(n), "==", "0"))
    elif op in ("sett", "clrt"):
        st.set_flag("1" if op == "sett" else "0")
    elif op == "movt":
        if st.flag is None:
            raise Unsupported("the T bit is read before this block sets it at %08X" % ins.pc)
        st.put(n, st.flag)
    elif op in ("mul.l", "muls.w", "mulu.w"):
        a, b = st.get(n), st.get(m)
        st.macl = st.temp({"mul.l": op2(a, "*", b), "muls.w": op2("(short)" + a, "*", "(short)" + b),
                           "mulu.w": op2(op2(a, "&", "0xFFFF"), "*", op2(b, "&", "0xFFFF"))}[op])
    elif op == "sts" and fmt.startswith("sts macl"):
        if st.macl is None:
            raise Unsupported("macl is read before this block sets it at %08X" % ins.pc)
        st.put(n, st.macl)
    else:
        raise Unsupported("%s at %08X" % (ins.text, ins.pc))


def compare(ins: "sh2.Insn", st: State) -> None:
    kind = ins.op[4:]
    if ins.m is None and ins.imm is not None:
        left, right = st.get(0), const(ins.imm)
    elif ins.m is None:
        left, right = st.get(ins.n), "0"
    else:
        left, right = st.get(ins.n), st.get(ins.m)
    symbols = {"eq": "==", "hs": ">=", "hi": ">", "ge": ">=", "gt": ">", "pz": ">=", "pl": ">"}
    if kind not in symbols:
        raise Unsupported("%s at %08X" % (ins.text, ins.pc))
    if kind in ("hs", "hi"):
        left, right = unsigned(left), unsigned(right)
    st.set_flag(op2(left, symbols[kind], right))


def operands(fmt: str) -> tuple[str, str]:
    """The source and destination of a mov, split at the comma outside any brackets."""
    text = fmt.split(" ", 1)[1]
    depth = 0
    for i, ch in enumerate(text):
        depth += ch == "("
        depth -= ch == ")"
        if ch == "," and depth == 0:
            return text[:i], text[i + 1:]
    raise Unsupported("cannot read the operands of " + fmt)


def memory(ins: "sh2.Insn", st: State) -> None:
    size = _SIZES[ins.op[-1]]
    source, dest = operands(ins.fmt)
    n, m = ins.n, ins.m
    if "gbr" in ins.fmt:
        raise Unsupported("gbr-relative access at %08X" % ins.pc)
    if dest.startswith("@"):
        value = st.get(0 if source == "r0" else m)
        if dest == "@Rn":
            where = st.get(n)
        elif dest == "@-Rn":
            st.put(n, op2(st.get(n), "-", str(size)))
            where = st.get(n)
        elif dest == "@(disp,Rn)":
            where = address(st.get(n), ins.disp)
        elif dest == "@(r0,Rn)":
            where = op2(st.get(0), "+", st.get(n))
        else:
            raise Unsupported("%s at %08X" % (ins.text, ins.pc))
        st.effect("%s(%s, %s);" % (_STORE[size], strip(where), strip(value)))
        return
    if source in ("@Rm", "@Rm+"):
        where = st.get(m)
    elif source == "@(disp,Rm)":
        where = address(st.get(m), ins.disp)
    elif source == "@(r0,Rm)":
        where = op2(st.get(0), "+", st.get(m))
    else:
        raise Unsupported("%s at %08X" % (ins.text, ins.pc))
    target = 0 if dest == "r0" else n
    after = op2(st.get(m), "+", str(size)) if source == "@Rm+" else None
    st.put(target, "%s(%s)" % (_LOAD[size], strip(where)), pure=False)
    if after and m != target:
        st.put(m, after)


@dataclass
class Read:
    """One block as read from the instructions, and the variables it uses and overwrites."""
    block: structure.Block
    stmts: list[Stmt]
    term: str                               # the branch condition or the returned expression
    tail: bool = False                      # it ends by jumping to another function
    fresh: set[int] = field(default_factory=set)         # State.fresh where the block ends


def strip(expr: str) -> str:
    """The expression without a pair of parentheses around all of it."""
    while expr.startswith("(") and expr.endswith(")"):
        depth = 0
        for i, ch in enumerate(expr):
            depth += ch == "("
            depth -= ch == ")"
            if depth == 0 and i < len(expr) - 1:
                return expr
        expr = expr[1:-1]
    return expr


def leaders(image: "sh2.Image", entry: int, code: set[int] | None = None) -> dict[int, int]:
    """Entry plus every branch target and instruction that follows a branch, with r15's offset at each.
    With the function's `code`, a branch outside it leaves the function."""
    found = {entry: 0}
    seen: set[int] = set()
    work = [(entry, 0)]

    def reach(target: int, sp: int) -> None:
        if found.setdefault(target, sp) != sp:
            raise Unsupported("the stack is %d bytes down on one path to %08X and %d on another"
                              % (-found[target], target, -sp))
        work.append((target, sp))

    while work:
        at, sp = work.pop()
        while at not in seen and image.contains(at):
            seen.add(at)
            ins = image.insn(at)
            slot = image.insn(at + 2) if ins.delay else None
            nxt = at + (4 if slot else 2)
            if ins.op in ("braf", "bsrf", "rte", "trapa", "sleep") or ins.op == ".word":
                raise Unsupported("%s at %08X" % (ins.text, at))
            sp += sp_change(ins) + (sp_change(slot) if slot else 0)
            leaves = code is not None and ins.target is not None and ins.target not in code
            if leaves and ins.op != "bra" and ins.op in ("bt", "bf", "bt/s", "bf/s"):
                raise Unsupported("a conditional branch out of the function at %08X" % at)
            if ins.op in ("bt", "bf", "bt/s", "bf/s", "bra") and not leaves:
                for target in ([ins.target] if ins.op == "bra" else [ins.target, nxt]):
                    reach(target, sp)
                break
            if ins.op in ("rts", "jmp") or leaves and ins.op == "bra":
                if sp:
                    raise Unsupported("returns with the stack %d bytes off at %08X: a piece of a larger function"
                                      % (sp, at))
                break
            at = nxt
    return found


def call(ins: "sh2.Insn", slot: "sh2.Insn", st: State, params: set[int], image: "sh2.Image") -> bool:
    """Writes the call as a statement. A tail call hands on r4 to r7 as they stand, so they all go in."""
    tail = ins.op in ("jmp", "bra")
    where = const(ins.target) if ins.op in ("bsr", "bra") else st.get(ins.n)
    if ins.op == "jmp" and number(where) is None:
        raise Unsupported("a tail call through a register at %08X" % ins.pc)
    step(slot, st, image)
    args: list[str] = []
    for r in range(4, 8):
        if r not in st.fresh and r not in params and not tail:
            break
        args.append(st.get(r))
    text = "%s%d(%s%s)" % ("GJUMP" if tail else "GCALL", len(args), where, "".join(", " + a for a in args))
    st.stmts.append(Stmt("r0", text, False, {"r%d" % r for r in range(1, 8)}))
    st.clobbered |= set(range(1, 8))
    st.clobbered.discard(0)
    st.fresh.clear()
    for r in range(8):
        st.known.pop(r, None)
    return tail


def read_block(image: "sh2.Image", start: int, stops: dict[int, int], params: set[int], flags: int,
               slots: dict[int, int], fresh: set[int], code: set[int] | None) -> tuple[Read, int]:
    st = State(flags=flags, sp=stops[start], slots=slots, fresh=set(fresh))
    block = structure.Block(start)
    term = ""
    tail = False
    at = start
    while True:
        ins = image.insn(at)
        slot = image.insn(at + 2) if ins.delay else None
        nxt = at + (4 if slot else 2)
        if ins.op in ("bt", "bf", "bt/s", "bf/s"):
            if st.flag is None:
                raise Unsupported("a branch on a T bit set in another block at %08X" % at)
            test = st.flag
            if slot:
                step(slot, st, image)
            term = test if ins.op.startswith("bt") else "!" + test
            block.kind, block.targets = "branch", [ins.target, nxt]
            break
        if ins.op == "bra" and code is not None and ins.target not in code:
            tail = call(ins, slot, st, params, image)
            block.kind = "return"
            break
        if ins.op == "bra":
            step(slot, st, image)
            block.kind, block.targets = "goto", [ins.target]
            break
        if ins.op == "rts":
            step(slot, st, image)
            block.kind = "return"
            break
        if ins.op == "jmp":
            if ins.n not in st.known:
                raise Unsupported("a jump through a register that is not a known address, a switch, at %08X" % at)
            tail = call(ins, slot, st, params, image)
            block.kind = "return"
            break
        if ins.op in _CALLS:
            call(ins, slot, st, params, image)
        else:
            step(ins, st, image)
            if slot:
                step(slot, st, image)
        at = nxt
        if at in stops:
            block.kind, block.targets = "goto", [at]
            break
    return Read(block, st.stmts, term, tail, st.fresh), st.flags


def uses_of(read: Read, returns: bool) -> set[str]:
    out = set(_VAR.findall(read.term))
    if read.block.kind == "return" and returns:
        out.add("r0")
    return out


def liveness(reads: dict[int, Read], returns: bool) -> tuple[dict[int, set[str]], dict[int, set[str]]]:
    live_in = {at: set() for at in reads}
    live_out = {at: set() for at in reads}
    changed = True
    while changed:
        changed = False
        for at, read in reads.items():
            out = set().union(*(live_in[n] for n in structure.successors(read.block)), set())
            need = uses_of(read, returns) | out
            for stmt in reversed(read.stmts):
                need = (need - stmt.defs) | stmt.uses
            if need != live_in[at] or out != live_out[at]:
                live_in[at], live_out[at] = need, out
                changed = True
    return live_in, live_out


def substitute(text: str, var: str, expr: str) -> str:
    wrapped = expr if re.match(r"^[\w.]+$", expr) or expr.startswith("(") and strip(expr) != expr else "(%s)" % expr
    return re.sub(r"\b%s\b" % var, lambda _: wrapped, text)


def simplify(read: Read, live_out: set[str], returns: bool) -> None:
    """Drops assignments nobody reads and folds one that is read once, or that is a number, into its user."""
    stmts = read.stmts
    changed = True
    while changed:
        changed = False
        for i, stmt in enumerate(stmts):
            if not stmt.var or not stmt.pure:
                continue
            users: list[int] = []
            redefined = False
            for j in range(i + 1, len(stmts)):
                if stmt.var in stmts[j].uses:
                    users.append(j)
                if stmt.var in stmts[j].defs:
                    redefined = True
                    break
            in_term = not redefined and (stmt.var in _VAR.findall(read.term) or
                                         (stmt.var == "r0" and read.block.kind == "return" and returns))
            if not redefined and stmt.var in live_out:
                continue
            count = len(users) + in_term
            if count == 0:
                del stmts[i]
                changed = True
                break
            numeric = number(stmt.expr) is not None
            last = len(stmts) if in_term else users[-1]
            between = {v for k in range(i + 1, last) for v in stmts[k].defs}
            if (count == 1 or numeric) and not (stmt.uses & between):
                for j in users:
                    stmts[j].expr = substitute(stmts[j].expr, stmt.var, stmt.expr)
                if in_term:
                    if stmt.var == "r0" and not read.term:
                        read.term = strip(stmt.expr)
                    else:
                        read.term = substitute(read.term, stmt.var, stmt.expr)
                del stmts[i]
                changed = True
                break


def read_blocks(image: "sh2.Image", entry: int, stops: dict[int, int], params: set[int],
                code: set[int] | None) -> tuple[dict[int, Read], dict[int, int]]:
    """Every block, read until the registers a call may pass settle: those written since the last call
    on every path into a block, so an argument set before a branch reaches the call after it."""
    fresh = {at: set() if at == entry else set(range(16)) for at in stops}
    while True:
        flags = 0
        reads: dict[int, Read] = {}
        slots: dict[int, int] = {}
        for at in sorted(stops):
            reads[at], flags = read_block(image, at, stops, params, flags, slots, fresh[at], code)
        into: dict[int, list[set[int]]] = {at: [] for at in stops}
        for read in reads.values():
            for target in read.block.targets:
                into[target].append(read.fresh)
        settled = {at: set() if at == entry or not into[at] else set.intersection(*into[at]) for at in stops}
        if settled == fresh:
            return reads, slots
        fresh = settled


def lift(image: "sh2.Image", entry: int, code: set[int] | None = None) -> str:
    """A draft of the function at entry. With its `code`, the recompiler's boundary, a branch outside
    that code is a tail call; without, the draft follows every branch."""
    stops = leaders(image, entry, code)
    params: set[int] = set()
    for attempt in range(2):
        reads, slots = read_blocks(image, entry, stops, params, code)
        returns = any(s.var == "r0" for r in reads.values() for s in r.stmts)
        live_in, live_out = liveness(reads, returns)
        if returns and "r0" in live_in[entry]:
            returns = False
            live_in, live_out = liveness(reads, returns)
        stray = sorted(v for v in live_in[entry] if not (v[0] == "r" and 4 <= int(v[1:]) <= 7))
        if stray and attempt == 1:
            raise Unsupported("reads %s before writing it: a piece of a larger function, or a task entry" % ", ".join(stray))
        params = {int(v[1:]) for v in live_in[entry] if v[0] == "r" and 4 <= int(v[1:]) <= 7}
        if any(r.tail for r in reads.values()):
            params = {4, 5, 6, 7}
    params = set(range(4, max(params, default=3) + 1))
    blocks: dict[int, structure.Block] = {}
    for at, read in reads.items():
        simplify(read, live_out[at], returns)
        block = read.block
        block.stmts = [s.text() for s in read.stmts]
        if block.kind == "branch":
            block.value = strip(read.term) if not read.term.startswith("!") else "!(%s)" % strip(read.term[1:])
        elif block.kind == "return":
            block.value = strip(read.term) or ("r0" if returns else "")
        blocks[at] = block
    lines = structure.Structurer(blocks, entry).run()
    if lines and lines[-1] == "return;":
        lines.pop()
    body = "\n".join(lines)
    names = sorted({v for v in _VAR.findall(body)} - {"r%d" % p for p in params}, key=lambda v: (v[0] != "r", int(v[1:])))
    head = "%s f%08X(%s)" % ("int" if returns else "void", entry, ", ".join("int r%d" % p for p in sorted(params)) or "void")
    decl = ["    int %s;" % ", ".join(n for n in names if n[0] != "v")] if any(n[0] != "v" for n in names) else []
    decl += ["    %s v%d;" % (_LOCAL_TYPES[size], -offset) for offset, size in sorted(slots.items(), reverse=True)]
    decl += [""] if decl else []
    return "\n".join([head, "{"] + decl + ["    " + line for line in lines] + ["}"]) + "\n"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("address", help="hex entry address")
    parser.add_argument("--module", default="KRNL", choices=sorted(IMAGES))
    parser.add_argument("--append", action="store_true", help="add the draft to its file in src/ instead of printing it")
    args = parser.parse_args()
    path, base = IMAGES[args.module]
    with open(os.path.join(ROOT, path), "rb") as f:
        image = sh2.Image(f.read(), base)
    try:
        draft = lift(image, int(args.address, 16), status.function_code().get(int(args.address, 16)) if args.module == "KRNL" else None)
    except (Unsupported, structure.Unstructured) as error:
        sys.exit("%s: %s" % (args.address, error))
    if not args.append:
        sys.stdout.write(draft)
        return
    target = status.source_for(int(args.address, 16))
    start = "" if os.path.exists(target) else '#include "krnl.h"\n'
    with open(target, "a", encoding="utf-8") as f:
        f.write(start + "\n/* Lifted by decomp/lift.py, not yet rewritten by hand. */\n" + draft)


if __name__ == "__main__":
    main()
