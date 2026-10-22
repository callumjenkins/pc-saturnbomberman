"""What one SH-2 instruction does to the registers, flags and stack slots of a block being lifted."""
import re
from dataclasses import dataclass, field
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from saturnrecomp import sh2

LOCAL_TYPES = {1: "signed char", 2: "short", 4: "int"}
VAR = re.compile(r"\b[rcv]\d+\b")
_FOLD = {"+": lambda a, b: a + b, "-": lambda a, b: a - b, "&": lambda a, b: a & b, "|": lambda a, b: a | b,
         "^": lambda a, b: a ^ b, "<<": lambda a, b: a << b, "*": lambda a, b: a * b}
_LOAD = {1: "LD8", 2: "LD16", 4: "LD32"}
_NUMBER = re.compile(r"^-?(?:0x[0-9A-Fa-f]+|\d+)$")
_SIZES = {"b": 1, "w": 2, "l": 4}
_STORE = {1: "ST8", 2: "ST16", 4: "ST32"}
_FRAMED = re.compile(r"sp|\(sp ([-+]) (\d+)\)")
_SP_SUM = re.compile(r"\(\(sp ([-+]) (\d+)\) ([-+]) (\d+)\)")


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
    fresh: set[int] = field(default_factory=set)         # written since the last call, on every path here
    flag: str | None = None
    macl: str | None = None
    flags: int = 0                          # how many flag variables have been made so far
    sp: int = 0                             # r15 relative to its value on entry
    slots: dict[int, int] = field(default_factory=dict)     # the function's stack locals: offset to size
    framed: bool = False                    # locals live in guest memory below `sp`, r15 on entry
    stored: set[int] = field(default_factory=set)   # offsets from r15 on entry stored to anywhere in the function
    saved: set[int] = field(default_factory=set)    # r8 to r14 the function's prologue has pushed

    def get(self, reg: int) -> str:
        if reg == 15 and self.framed:
            return framed(self.sp)
        return self._get(reg)

    def _get(self, reg: int) -> str:
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


class Unsupported(Exception):
    pass


def address(base: str, offset: int | str) -> str:
    at = _FRAMED.fullmatch(base)
    if at and isinstance(offset, int):
        return framed(int(at.group(2) or 0) * (-1 if at.group(1) == "-" else 1) + offset)
    return base if offset == 0 else op2(base, "+", str(offset))


def fold_frame(text: str) -> str:
    """text with each `(sp - a) + b` an address next to sp could have been, as one offset from sp."""
    while True:
        new = _SP_SUM.sub(lambda m: framed(int(m.group(2)) * (-1 if m.group(1) == "-" else 1)
                                           + int(m.group(4)) * (-1 if m.group(3) == "-" else 1)), text)
        if new == text:
            return text
        text = new


def framed(offset: int) -> str:
    """The address `offset` bytes from sp."""
    return "sp" if not offset else "(sp %s %d)" % ("-" if offset < 0 else "+", abs(offset))


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
    if op == "add" and n == 15 and ins.imm is not None:
        st.sp += ins.imm
        return True
    if op in ("sts.l", "lds.l"):
        st.sp += sp_change(ins)
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
        if dest.startswith("@") and n == 15 and dest in ("@Rn", "@(disp,Rn)"):
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


def sp_change(ins: "sh2.Insn") -> int:
    """How far an instruction moves r15."""
    if ins.op in ("sts.l", "mov.l") and ins.n == 15 and "@-Rn" in ins.fmt:
        return -4
    if ins.op in ("lds.l", "mov.l") and ins.m == 15 and "@Rm+" in ins.fmt:
        return 4
    if ins.op == "add" and ins.n == 15 and ins.imm is not None:
        return ins.imm
    return 0


def step(ins: "sh2.Insn", st: State, image: "sh2.Image") -> None:
    op, fmt, n, m = ins.op, ins.fmt, ins.n, ins.m
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
