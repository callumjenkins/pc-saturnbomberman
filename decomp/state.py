"""What one SH-2 instruction does to the registers, flags and stack slots of a block being lifted."""
import re
from dataclasses import dataclass, field
from typing import TYPE_CHECKING

import registers

if TYPE_CHECKING:
    from saturnrecomp import sh2

LOCAL_TYPES = {1: "signed char", 2: "short", 4: "int"}
VAR = re.compile(r"\b[rcmv]\d+\b")
_FOLD = {"+": lambda a, b: a + b, "-": lambda a, b: a - b, "&": lambda a, b: a & b, "|": lambda a, b: a | b,
         "^": lambda a, b: a ^ b, "<<": lambda a, b: a << b, "*": lambda a, b: a * b}
_LOAD = {1: "LD8", 2: "LD16", 4: "LD32"}
_NUMBER = re.compile(r"^-?(?:0x[0-9A-Fa-f]+|\d+)$")
_SIZES = {"b": 1, "w": 2, "l": 4}
_STORE = {1: "ST8", 2: "ST16", 4: "ST32"}
_CONTROL = {"sr": "SR", "gbr": "GBR", "vbr": "VBR"}
_SAVED = {"mach": "MACH", "macl": "MACL", "pr": "PR"}      # what a parked function pushes with sts.l
NO_FLAG = "cT"                           # stands for a T bit no block has set, in a block read before the lift refuses it
MAC = "m0"                                  # MACH:MACL as one 64-bit variable
_FRAMED = re.compile(r"sp|\(sp ([-+]) (\d+)\)")
_SP_SUM = re.compile(r"(\w?)\(\(sp ([-+]) (\d+)\) ([-+]) (\d+)\)")


@dataclass
class Stmt:
    """One statement of a block. `var` is the variable it assigns, if it is an assignment."""
    var: str | None
    expr: str
    pure: bool = True                       # an assignment that can be dropped when unused, or inlined
    kills: set[str] = field(default_factory=set)     # variables it overwrites besides `var`

    @property
    def uses(self) -> set[str]:
        return set(VAR.findall(self.expr))

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
    callee: str = ""                        # the call that last overwrote them
    fresh: set[int] = field(default_factory=set)         # written since the last call, on every path here
    flag: str | None = None
    lacks: str = ""                         # why the block needs a T bit that no block before it has set, if it does
    macl: str | None = None                 # the product of the last mul.l, muls.w or mulu.w, which sets MACL alone
    mac64: bool = False                     # the block has set MACH:MACL as a whole (m0)
    flags: int = 0                          # how many flag variables have been made so far
    sp: int = 0                             # r15 relative to its value on entry
    copies: dict[int, int] = field(default_factory=dict)   # registers that hold r15 at one offset throughout the function
    adjust: dict[int, int] = field(default_factory=dict)   # how far the block has moved each of them since
    slots: dict[int, int] = field(default_factory=dict)     # the function's stack locals: offset to size
    framed: bool = False                    # locals live in guest memory below `sp`, r15 on entry
    parked: bool = False                    # a task can park in the function: its pushes and pops are real stores and loads
    touched: frozenset[int] = frozenset(range(8, 15))   # r8 to r14 the function writes, which a jump out of it has to set
    stored: set[int] = field(default_factory=set)   # offsets from r15 on entry stored to anywhere in the function
    saved: set[int] = field(default_factory=set)    # r8 to r14 the function's prologue has pushed
    sp_set: str = ""                        # the SETSP the block last wrote, which a call after it need not repeat
    entry_clobbered: set[int] = field(default_factory=set)  # r1 to r7 a call on some path in overwrote, and the block has not set since
    ctx_reads: set[int] = field(default_factory=set)        # every register the block reads from the context after a call
    ctx_wanted: frozenset[int] = frozenset()                # those the function reads from the context anywhere, which a call it cannot read has to find in the context too
    loaded: set[int] = field(default_factory=set)           # those the block reads from the context, which the other paths into it must set
    pr_intact: bool = False                 # no call has run yet in the function, so pr still holds its return address
    r0_defined: bool = False                # r0 holds a value on every path here, which a callee that leaves it alone gives back
    kept: frozenset[int] = frozenset()      # r4 to r7 the function never writes
    run_time: int | None = None             # r15 is the variable `r15`, below a frame of a run-time size: its offset before it

    def get(self, reg: int) -> str:
        if reg == 15 and self.framed and self.run_time is None:
            return framed(self.sp)
        return self._get(reg)

    def _get(self, reg: int) -> str:
        if reg in self.clobbered and 1 <= reg <= 7:
            self.ctx_reads.add(reg)
            if reg in self.entry_clobbered:
                self.loaded.add(reg)
            self.put(reg, "R(%d)" % reg, False)         # what the callee left in the context, which the game's code reads
        if reg in self.clobbered:
            raise Unsupported("r%d is read after a call%s overwrote it" % (reg, " to " + self.callee if self.callee else ""))
        return const(self.known[reg]) if reg in self.known else "r%d" % reg

    def put(self, reg: int, expr: str, pure: bool = True) -> None:
        self.clobbered.discard(reg)
        if reg == 0:
            self.r0_defined = True
        self.entry_clobbered.discard(reg)
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


class Unsupported(Exception):
    pass


def address(base: str, offset: int | str) -> str:
    at = _FRAMED.fullmatch(base)
    if at and isinstance(offset, int):
        return framed(int(at.group(2) or 0) * (-1 if at.group(1) == "-" else 1) + offset)
    return base if offset == 0 else op2(base, "+", str(offset))


def fold_frame(text: str) -> str:
    """text with each `(sp - a) + b` or `(sp + a) - b` folded to one offset from sp. A sum that is a call's
    argument list keeps its parentheses."""
    def fold(m: re.Match[str]) -> str:
        where = framed(int(m.group(3)) * (-1 if m.group(2) == "-" else 1) + int(m.group(5)) * (-1 if m.group(4) == "-" else 1))
        return m.group(1) + ("(sp)" if m.group(1) and where == "sp" else where)

    while True:
        new = _SP_SUM.sub(fold, text)
        if new == text:
            return text
        text = new


def framed(offset: int) -> str:
    """The address `offset` bytes from sp."""
    return "sp" if not offset else "(sp %s %d)" % ("-" if offset < 0 else "+", abs(offset))


def set_mac(st: State, expr: str, pure: bool = True) -> None:
    """Assigns MACH:MACL as a whole, which also replaces a MACL the block set alone."""
    st.stmts.append(Stmt(MAC, expr, pure))
    st.macl = None
    st.mac64 = True


def carried(ins: "sh2.Insn", st: State) -> str:
    """The T bit going into an instruction that adds or rotates it in."""
    if st.flag is None:
        st.lacks = st.lacks or "the T bit is read before this block sets it at %08X" % ins.pc
        return NO_FLAG
    return st.flag


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


def const(value: int) -> str:
    value &= 0xFFFFFFFF
    if value >= 0x80000000:
        return str(value - (1 << 32)) if value >= 0xFFFF0000 else "(int)0x%08X" % value
    return str(value) if value < 256 else "0x%08X" % value if value >= 0x10000 else "0x%X" % value


def frame(ins: "sh2.Insn", st: State) -> bool:
    """Handles an instruction that uses r15 as the frame: saves and restores, and the function's locals."""
    op, fmt, n, m = ins.op, ins.fmt, ins.n, ins.m
    ends_run_time_frame = restored(ins, st.copies, st.adjust) is not None or loads_r15(ins)
    if st.run_time is not None and 15 in registers.defs(ins) and not (ends_run_time_frame or is_run_time_frame(ins, st.known)):
        if not steps_r15(ins):
            raise Unsupported("moves r15 below a frame of a run-time size at %08X" % ins.pc)
        below_run_time_frame(ins, st)
        return True
    if st.run_time is not None and loads_r15(ins):
        st.sp, st.run_time = st.run_time, None
        st.effect("SETSP(%s);" % framed(st.sp))
        return True
    if op == "add" and n == 15 and ins.imm is not None:
        st.sp += ins.imm
        moved(st)
        return True
    if op == "add" and fmt == "add Rm,Rn" and n == 15 and m in st.known:
        st.sp += st.known[m]
        moved(st)
        return True
    if op == "sub" and fmt == "sub Rm,Rn" and n == 15 and m in st.known:
        st.sp -= st.known[m]
        moved(st)
        return True
    if is_run_time_frame(ins, st.known):
        if st.parked:
            raise Unsupported("a frame of a run-time size in a function a task can park in at %08X" % ins.pc)
        if not st.framed:
            raise Unsupported("takes the address of a local or moves r15 at %08X" % ins.pc)
        st.put(15, "ALLOCA(%s, %s)" % (strip(st.get(15)), strip(st.get(m))), False)
        if st.run_time is None:
            st.run_time = st.sp
        return True
    restore = restored(ins, st.copies, st.adjust)
    if restore is not None:
        st.sp = restore
        if st.run_time is not None:
            st.run_time = None
            st.effect("SETSP(%s);" % framed(restore))
        moved(st)
        return True
    if st.parked and parked_frame(ins, st):
        return True
    if op in ("sts.l", "lds.l"):
        st.sp += sp_change(ins)
        return True
    if op in ("stc.l", "ldc.l"):
        reg = fmt.split(" ")[1].split(",")[0] if op == "stc.l" else fmt.rsplit(",", 1)[1]
        if reg not in _CONTROL:
            raise Unsupported("%s at %08X" % (ins.text, ins.pc))
        if op == "stc.l":
            st.sp -= 4
            st.stored.add(st.sp)
            value = control(reg, st)
            if st.framed:
                st.effect("ST32(%s, %s);" % (st.get(15), strip(value)))
            else:
                st.put_local(local(st, st.sp, 4, ins), value)
        else:
            set_control(reg, "LD32(%s)" % st.get(15) if st.framed else local(st, st.sp, 4, ins), st)
            st.sp += 4
        return True
    if op == "mov.l" and fmt == "mov.l Rm,@-Rn" and n == 15:
        st.sp -= 4
        if 8 <= m <= 14 and m not in st.saved:          # the first push of r8 to r14 saves the caller's
            st.saved.add(m)
            return True
        st.stored.add(st.sp)
        if st.framed:
            st.effect("ST32(%s, %s);" % (st.get(15), strip(st.get(m))))
        else:
            st.put_local(local(st, st.sp, 4, ins), st.get(m))
        return True
    if op == "mov.l" and fmt == "mov.l @Rm+,Rn" and m == 15:
        if st.framed and not 8 <= n <= 14:
            st.put(n, "LD32(%s)" % st.get(15), pure=False)
        elif not 8 <= n <= 14:
            st.put(n, local(st, st.sp, 4, ins))
        st.sp += 4
        return True
    if op.startswith("mov.") and "@" in fmt:
        source, dest = operands(fmt)
        if dest.startswith("@") and n == 15 and dest in ("@Rn", "@(disp,Rn)") and st.run_time is None:
            st.stored.add(st.sp + (ins.disp or 0))
    if op.startswith("mov.") and "@" in fmt and not st.framed:
        size = _SIZES[op[-1]]
        source, dest = operands(fmt)
        offset = ins.disp or 0
        if dest.startswith("@") and (n == 15 and dest in ("@Rn", "@(disp,Rn)")):
            value = st.get(0 if source == "r0" else m)
            if size < 4:
                value = "(%s)%s" % (LOCAL_TYPES[size], value)
            st.put_local(local(st, st.sp + offset, size, ins), value)
            return True
        if source in ("@Rm", "@(disp,Rm)") and m == 15:
            st.put(0 if dest == "r0" else n, local(st, st.sp + offset, size, ins), pure=True)
            return True
    return False


def control(reg: str, st: State) -> str:
    """The value of sr, gbr or vbr. The T bit of sr is the lifter's flag when this block has set it."""
    read = "%s()" % _CONTROL[reg]
    return read if reg != "sr" or st.flag is None else op2(op2(read, "&", "~1"), "|", st.flag)


def load_operand(ins: "sh2.Insn", st: State) -> str:
    """The value an ldc or ldc.l brings in: the register, or the word it points at, which it steps past."""
    if not ins.op.endswith(".l"):
        return st.get(ins.m)
    value = st.temp("LD32(%s)" % strip(st.get(ins.m)))
    st.put(ins.m, op2(st.get(ins.m), "+", "4"))
    return value


def set_control(reg: str, value: str, st: State) -> None:
    """Writes sr, gbr or vbr. A write to sr changes T and may unmask an interrupt, so time advances."""
    st.effect("SET%s(%s);" % (_CONTROL[reg], strip(value)))
    if reg == "sr":
        st.flag = None


def parked_frame(ins: "sh2.Insn", st: State) -> bool:
    """The saves and restores of pr and of r8 to r14 in a function a task can park in. A task resumed
    inside it, on a stack the game built or on another fiber, pops them from the guest stack, so each is a
    store or a load there, and r8 to r14 are the context's registers."""
    op, fmt, n, m = ins.op, ins.fmt, ins.n, ins.m
    if op in ("sts.l", "lds.l"):
        reg = fmt.split(" ")[1].split(",")[0] if op == "sts.l" else fmt.rsplit(",", 1)[1]
        if reg not in _SAVED:
            raise Unsupported("%s in a function a task can park in" % ins.text)
        if op == "sts.l":
            push(st, "%s()" % _SAVED[reg])
        else:
            pop(st, "SET%s(LD32(%%s));" % _SAVED[reg])
        return True
    if op == "mov.l" and fmt == "mov.l Rm,@-Rn" and n == 15 and 8 <= m <= 14 and m not in st.saved:
        st.saved.add(m)
        push(st, "R(%d)" % m)
        return True
    if op == "mov.l" and fmt == "mov.l @Rm+,Rn" and m == 15 and 8 <= n <= 14:
        pop(st, "SETR(%d, LD32(%%s));" % n)
        return True
    return False


def moved(st: State) -> None:
    """r15 has a new value. In a function a task can park in the context's r15 follows it, so that what the function
    keeps below the entry value is below r15 whenever time advances: an interrupt pushes at r15."""
    if st.parked:
        st.sp_set = "SETSP(%s);" % st.get(15)
        st.effect(st.sp_set)


def pop(st: State, template: str) -> None:
    st.effect(template % st.get(15))
    st.sp += 4
    moved(st)


def push(st: State, value: str) -> None:
    st.sp -= 4
    st.stored.add(st.sp)
    st.effect("ST32(%s, %s);" % (st.get(15), value))
    moved(st)


def local(st: State, offset: int, size: int, ins: "sh2.Insn") -> str:
    if offset >= 0:
        raise Unsupported("reads an argument passed on the stack at %08X" % ins.pc)
    if st.slots.setdefault(offset, size) != size:
        raise Unsupported("a stack slot used at two sizes at %08X" % ins.pc)
    return "v%d" % -offset


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


def number(text: str) -> int | None:
    if text.startswith("(int)"):
        text = text[5:]
    return int(text, 0) if _NUMBER.match(text) else None


def op2(left: str, symbol: str, right: str) -> str:
    a, b = number(left), number(right)
    if a is not None and b is not None and symbol in _FOLD:
        return const(_FOLD[symbol](a, b))
    return "(%s %s %s)" % (left, symbol, right)


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


def signed(expr: str) -> str:
    """An unsigned result as the int a register holds, so a later compare is signed as the SH-2's is."""
    return "(int)%s" % expr


def sp_change(ins: "sh2.Insn", known: dict[int, int] | None = None) -> int:
    """How far an instruction moves r15. `known` holds the registers a straight run of instructions has set to a
    number, for an `add Rm,r15` of a frame too large for an immediate."""
    if ins.op in ("sts.l", "stc.l", "mov.l") and ins.n == 15 and "@-Rn" in ins.fmt:
        return -4
    if ins.op in ("lds.l", "ldc.l", "mov.l") and ins.m == 15 and "@Rm+" in ins.fmt:
        return 4
    if ins.op == "add" and ins.n == 15 and ins.imm is not None:
        return ins.imm
    if ins.op == "add" and ins.n == 15 and known and ins.m in known:
        return known[ins.m]
    if ins.op == "sub" and ins.n == 15 and known and ins.m in known:
        return -known[ins.m]
    return 0


def steps_r15(ins: "sh2.Insn") -> bool:
    """A push, a pop, an `add #imm` or a `mov Rm,r15` of r15, which a function does below a frame of a run-time size to
    pass an argument and take its stack back."""
    pushes = ins.op == "mov.l" and ins.n == 15 and "@-Rn" in ins.fmt
    pops = ins.op == "mov.l" and ins.m == 15 and "@Rm+" in ins.fmt
    assigned = ins.op == "mov" and ins.fmt == "mov Rm,Rn" and ins.n == 15
    return pushes or pops or assigned or ins.op == "add" and ins.n == 15 and ins.imm is not None


def below_run_time_frame(ins: "sh2.Insn", st: State) -> None:
    """A push, pop or add on r15 where it is the variable `r15`."""
    if ins.op == "add":
        st.put(15, op2(st.get(15), "+", str(ins.imm)))
    elif ins.op == "mov":
        st.put(15, st.get(ins.m))
    elif ins.n == 15:
        value = st.get(ins.m)
        st.put(15, op2(st.get(15), "-", "4"))
        st.effect("ST32(r15, %s);" % strip(value))
    else:
        st.put(ins.n, "LD32(%s)" % st.get(15), pure=False)
        st.put(15, op2(st.get(15), "+", "4"))


def loads_r15(ins: "sh2.Insn") -> bool:
    """`mov.l @...,r15`: a function that kept r15 in its frame before it lowered it by a run-time size takes it back."""
    return ins.op == "mov.l" and ins.n == 15 and ins.fmt.split(",")[0].split(" ")[1].startswith("@")


def is_run_time_frame(ins: "sh2.Insn", known: dict[int, int]) -> bool:
    """`sub Rm,r15` of a size the function works out as it runs, which makes r15 a value the lifter cannot count."""
    return ins.op == "sub" and ins.fmt == "sub Rm,Rn" and ins.n == 15 and ins.m not in known


class Copies:
    """The registers a function sets to r15 with `mov r15,Rn`, and the offset from its entry value that r15 had.
    A register whose copy any other instruction overwrites, or that copies r15 at two offsets, is not kept.
    A pop is no overwrite: it gives the register back to the caller. An `add #imm,Rn` moves the copy, which `adjust`
    holds for the path being walked, and `mov Rn,r15` sets r15 to where the copy was made plus that move.
    """

    def __init__(self, spoiled: frozenset[int] = frozenset()) -> None:
        self.at: dict[int, int] = {}
        self.spoiled = set(spoiled)
        self.adjust: dict[int, int] = {}

    def note(self, ins: "sh2.Insn", sp: int, known: dict[int, int], dynamic: bool) -> None:
        move = copy_move(ins, known)
        if ins.op == "mov" and ins.fmt == "mov Rm,Rn" and ins.m == 15 and ins.n != 15:
            if dynamic or self.at.setdefault(ins.n, sp) != sp:
                self.spoiled.add(ins.n)
        elif move and move[0] in self.at:
            self.adjust[move[0]] = self.adjust.get(move[0], 0) + move[1]
            self.spoiled |= registers.defs(ins) - {move[0]}
        elif not (ins.op == "mov.l" and ins.m == 15 and "@Rm+" in ins.fmt):
            self.spoiled |= registers.defs(ins)

    def kept(self) -> dict[int, int]:
        return {reg: sp for reg, sp in self.at.items() if reg not in self.spoiled}


def copy_move(ins: "sh2.Insn", known: dict[int, int]) -> tuple[int, int] | None:
    """The register an instruction moves by a number it knows, and by how much: an `add`, or a load or store that
    steps the pointer it goes through. `known` holds the registers a straight run has set to a number."""
    if ins.op == "add" and ins.imm is not None:
        return ins.n, ins.imm
    if ins.op == "add" and ins.fmt == "add Rm,Rn" and ins.m in known:
        return ins.n, known[ins.m]
    size = _SIZES.get(ins.op[-1]) if ins.op.startswith("mov.") else None
    if size and "@Rm+" in ins.fmt and ins.n != ins.m:
        return ins.m, size
    if size and "@-Rn" in ins.fmt:
        return ins.n, -size
    return None


def restored(ins: "sh2.Insn", copies: dict[int, int], adjust: dict[int, int]) -> int | None:
    """r15's offset after `mov Rm,r15` of a register that holds a copy of it, moved by `adjust` since the copy was
    made, or None for any other instruction."""
    if ins.op == "mov" and ins.fmt == "mov Rm,Rn" and ins.n == 15 and ins.m in copies:
        return copies[ins.m] + adjust.get(ins.m, 0)
    return None


def track(ins: "sh2.Insn", known: dict[int, int], image: "sh2.Image") -> None:
    """Updates `known`, the registers set to a number so far in a straight run, with what the instruction does."""
    if ins.op == "mov" and ins.fmt == "mov #imm,Rn":
        known[ins.n] = ins.imm
        return
    if ins.op in ("mov.w", "mov.l") and "@T" in ins.fmt:
        value = image.literal(ins)
        if value is None:
            known.pop(ins.n, None)
        else:
            known[ins.n] = value - (1 << 32) if value >= 1 << 31 else value
        return
    if ins.n is not None:
        known.pop(ins.n, None)
    known.pop(0, None)


def step(ins: "sh2.Insn", st: State, image: "sh2.Image") -> None:
    op, fmt, n, m = ins.op, ins.fmt, ins.n, ins.m
    move = copy_move(ins, st.known)
    if move and move[0] in st.copies:
        st.adjust[move[0]] = st.adjust.get(move[0], 0) + move[1]
    if n == 15 or m == 15 or "r15" in fmt:
        if frame(ins, st):
            return
        if not st.framed:
            raise Unsupported("takes the address of a local or moves r15 at %08X" % ins.pc)
        writes = n == 15 and (not operands(fmt)[1].startswith("@") or "@-" in fmt) and not op.startswith(("cmp/", "tst"))
        if writes or (m == 15 and "@Rm+" in fmt):
            raise Unsupported("moves r15 at %08X" % ins.pc)
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
    elif op in ("and", "or") and fmt in ("and Rm,Rn", "or Rm,Rn") and m == n:
        pass                                    # SHC's filler for a delay slot: it reads and writes nothing
    elif op in ("sub", "and", "or", "xor") and ins.m is not None:
        st.put(n, op2(st.get(n), {"sub": "-", "and": "&", "or": "|", "xor": "^"}[op], st.get(m)))
    elif op in ("and", "or", "xor") and ins.imm is not None:
        st.put(0, op2(st.get(0), {"and": "&", "or": "|", "xor": "^"}[op], const(ins.imm)))
    elif op == "not":
        st.put(n, "(~%s)" % st.get(m))
    elif op == "neg":
        value = st.get(m)
        st.put(n, const(-number(value)) if number(value) is not None else "(-%s)" % value)
    elif op in ("shll", "shal"):
        value = st.get(n)
        st.set_flag(op2(unsigned(value), ">>", "31"))
        st.put(n, op2(value, "<<", "1"))
    elif op == "shar":
        value = st.get(n)
        st.set_flag(op2(value, "&", "1"))
        st.put(n, op2(value, ">>", "1"))
    elif op == "shlr":
        value = st.get(n)
        st.set_flag(op2(value, "&", "1"))
        st.put(n, signed(op2(unsigned(value), ">>", "1")))
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
    elif op.startswith("cmp/") and op != "cmp/str":
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
    elif op in ("rotl", "rotr"):
        value = st.get(n)
        if op == "rotl":
            st.set_flag(signed(op2(unsigned(value), ">>", "31")))
            st.put(n, op2(op2(value, "<<", "1"), "|", signed(op2(unsigned(value), ">>", "31"))))
        else:
            st.set_flag(op2(value, "&", "1"))
            st.put(n, signed(op2(op2(unsigned(value), ">>", "1"), "|", op2(value, "<<", "31"))))
    elif op in ("rotcl", "rotcr"):
        value, carry = st.get(n), carried(ins, st)
        if op == "rotcl":
            st.set_flag(signed(op2(unsigned(value), ">>", "31")))
            st.put(n, op2(op2(value, "<<", "1"), "|", carry))
        else:
            st.set_flag(op2(value, "&", "1"))
            st.put(n, signed(op2(op2(unsigned(value), ">>", "1"), "|", op2(carry, "<<", "31"))))
    elif op in ("addc", "subc"):
        carry, left, right = carried(ins, st), st.temp(st.get(n)), st.get(m)
        first = st.temp(op2(left, "+" if op == "addc" else "-", right))
        st.put(n, op2(first, "+" if op == "addc" else "-", carry))
        wrapped = (lambda a, b: op2(unsigned(a), "<", unsigned(b)))
        if op == "addc":
            st.set_flag(op2(wrapped(first, left), "|", wrapped(st.get(n), first)))
        else:
            st.set_flag(op2(wrapped(left, first), "|", wrapped(first, st.get(n))))
    elif op == "negc":
        carry, value = carried(ins, st), st.temp(op2("0", "-", st.get(m)))
        st.put(n, op2(value, "-", carry))
        st.set_flag(op2(op2(unsigned(value), "!=", "0"), "|", op2(unsigned(value), "<", unsigned(st.get(n)))))
    elif op == "tas.b":
        pointer = strip(st.get(n))
        byte = st.temp("LD8(%s)" % pointer)
        st.set_flag(op2(byte, "==", "0"))
        st.effect("ST8(%s, %s);" % (pointer, op2(byte, "|", "0x80")))
    elif op == "tst.b":
        st.set_flag(op2(op2("LD8(%s)" % strip(op2(control("gbr", st), "+", st.get(0))), "&", str(ins.imm)), "==", "0"))
    elif op == "lds.l" and fmt.endswith(("mach", "macl")):
        value = st.temp("LD32(%s)" % strip(st.get(m)))
        st.put(m, op2(st.get(m), "+", "4"))
        high = fmt.endswith("mach")
        keep = "(%s & 0xFFFFFFFFLL)" % MAC if high else "(%s & ~0xFFFFFFFFLL)" % MAC
        set_mac(st, "(%s | %s)" % (keep, "((long long)%s << 32)" % value if high else "(unsigned)%s" % value))
    elif op == "swap.b":
        value = st.get(m)
        st.put(n, op2(op2(value, "&", "0xFFFF0000"), "|",
                      op2(op2(op2(value, "&", "255"), "<<", "8"), "|", op2(op2(unsigned(value), ">>", "8"), "&", "255"))))
    elif op == "cmp/str":
        difference = st.temp(op2(st.get(n), "^", st.get(m)))
        st.set_flag(" || ".join(op2(difference, "&", mask) + " == 0" for mask in ("255", "0xFF00", "0xFF0000", "0xFF000000")))
    elif op == "movt":
        st.put(n, carried(ins, st))
    elif op in ("mul.l", "muls.w", "mulu.w"):
        a, b = st.get(n), st.get(m)
        product = {"mul.l": op2(a, "*", b), "muls.w": op2("(short)" + a, "*", "(short)" + b),
                   "mulu.w": op2(op2(a, "&", "0xFFFF"), "*", op2(b, "&", "0xFFFF"))}[op]
        if st.mac64:                        # MACH stays, MACL becomes the product
            st.stmts.append(Stmt(MAC, "(%s & ~0xFFFFFFFFLL) | (unsigned)%s" % (MAC, st.temp(product))))
            st.macl = None
        else:
            st.macl = st.temp(product)
            st.stmts.append(Stmt(MAC, "(unsigned)%s" % st.macl))      # for a `sts macl` in a later block
    elif op in ("stc", "sts") and fmt.split(" ")[1].split(",")[0] in _CONTROL:
        st.put(n, control(fmt.split(" ")[1].split(",")[0], st), pure=False)
    elif op == "sts" and fmt.startswith("sts pr,") and st.pr_intact:
        st.put(n, "PR()", pure=False)
    elif op == "sts" and fmt.startswith("sts macl") and st.macl is not None:
        st.put(n, st.macl)
    elif op == "sts" and fmt.startswith(("sts mach", "sts macl")):
        st.put(n, "(int)(%s >> 32)" % MAC if fmt.startswith("sts mach") else "(int)%s" % MAC)
    elif op in ("ldc", "ldc.l") and fmt.rsplit(",", 1)[1] in _CONTROL:
        set_control(fmt.rsplit(",", 1)[1], load_operand(ins, st), st)
    elif op == "lds" and fmt.endswith(",pr"):
        st.effect("SETPR(%s);" % strip(st.get(m)))
        st.pr_intact = False
    elif op == "lds" and fmt.endswith(("mach", "macl")):
        high = fmt.endswith("mach")
        keep = "(%s & 0xFFFFFFFFLL)" % MAC if high else "(%s & ~0xFFFFFFFFLL)" % MAC
        part = "((long long)%s << 32)" % st.get(m) if high else "(unsigned)%s" % st.get(m)
        set_mac(st, "(%s | %s)" % (keep, part))
    elif op == "clrmac":
        set_mac(st, "0")
    elif op in ("dmuls.l", "dmulu.l"):
        a, b = st.get(n), st.get(m)
        set_mac(st, "(long long)%s * %s" % (a, b) if op == "dmuls.l"
                else "(long long)((unsigned long long)(unsigned)%s * (unsigned)%s)" % (a, b))
    elif op in ("mac.l", "mac.w"):
        size = 4 if op == "mac.l" else 2
        first = st.temp("%s(%s)" % (_LOAD[size], strip(st.get(n))))
        st.put(n, op2(st.get(n), "+", str(size)))
        second = st.temp("%s(%s)" % (_LOAD[size], strip(st.get(m))))
        st.put(m, op2(st.get(m), "+", str(size)))
        set_mac(st, "MAC_%s(%s, %s, %s)" % (op[-1].upper(), MAC, first, second), False)
    else:
        raise Unsupported("%s at %08X" % (ins.text, ins.pc))


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


def unsigned(expr: str) -> str:
    return "(unsigned)%s" % expr
