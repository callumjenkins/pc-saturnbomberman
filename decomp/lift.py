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
import registers  # noqa: E402
import status  # noqa: E402
import structure  # noqa: E402
from saturnrecomp import sh2  # noqa: E402
from state import LOCAL_TYPES, VAR, State, Stmt, Unsupported, const, fold_frame, framed, number, sp_change, step, strip  # noqa: E402

IMAGES = {"KRNL": ("build/extract/BOMSS/0KRNL.BIN", 0x06006000)}
_CALLS = ("bsr", "jsr")


@dataclass
class Read:
    """One block as read from the instructions, and the variables it uses and overwrites."""
    block: structure.Block
    stmts: list[Stmt]
    term: str                               # the branch condition or the returned expression
    tail: bool = False                      # it ends by jumping to another function
    fresh: set[int] = field(default_factory=set)         # State.fresh where the block ends


def call(ins: "sh2.Insn", slot: "sh2.Insn", st: State, params: set[int], image: "sh2.Image",
         functions: dict[int, set[int]] | None = None) -> bool:
    """Writes the call as a statement. With `functions`, the arguments are the registers the callee
    reads. Without, a call passes those set since the last call, and a tail call hands on r4 to r7 as
    they stand, except those an earlier call overwrote: those at the end are left out, and one before a
    register that does go in passes 0."""
    tail = ins.op in ("jmp", "bra")
    where = const(ins.target) if ins.op in ("bsr", "bra") else st.get(ins.n)
    if ins.op == "jmp" and number(where) is None:
        raise Unsupported("a tail call through a register at %08X" % ins.pc)
    step(slot, st, image)
    known = functions is not None and number(where) is not None
    needs = sorted(registers.saved(image, number(where), functions)) if known else []
    if needs:
        raise Unsupported("goes to %s, the middle of a function that reads r%d from its caller" % (where, needs[0]))
    helper = registers.routine(image, number(where), functions) if known and not tail else None
    if helper:
        text, changes = helper
        st.put(0, text.format(**{"r%d" % r: st.get(r) for r in range(3) if "{r%d}" % r in text}), False)
        for r in changes:
            st.clobbered.add(r)
            st.known.pop(r, None)
        return False
    reads = registers.reads(image, number(where), functions) if known else None
    args: list[str] = []
    if reads is not None:
        helper = sorted(reads & {0, 1, 2, 3})
        if helper:
            raise Unsupported("calls %s, which takes r%d, as a runtime routine does: write its operator in HELPER()"
                              % (where, helper[0]))
        args = [st.get(r) for r in range(4, max(reads, default=3) + 1)]
    else:
        for r in range(4, 8):
            if r not in st.fresh and r not in params and not tail:
                break
            args.append("" if r in st.clobbered else st.get(r))
        while args and not args[-1]:
            args.pop()
        args = [a or "0" for a in args]
    extra = stack_arguments(st) if not tail else []
    if extra:
        args += ["0"] * (4 - len(args)) + extra         # r4 to r7 first, then the stack words
    text = "%s%d(%s%s)" % ("GJUMP" if tail else "GCALL", len(args), where, "".join(", " + a for a in args))
    if tail and st.framed:
        st.effect("UNFRAME(sp);")
    st.stmts.append(Stmt("r0", text, False, {"r%d" % r for r in range(1, 8)}))
    st.clobbered |= set(range(1, 8))
    st.clobbered.discard(0)
    st.fresh.clear()
    for r in range(8):
        st.known.pop(r, None)
    return tail


def leaders(image: "sh2.Image", entry: int, code: set[int] | None = None) -> dict[int, int]:
    """Entry plus every branch target and instruction that follows a branch, with r15's offset at each."""
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


def lift(image: "sh2.Image", entry: int, code: set[int] | None = None, functions: dict[int, set[int]] | None = None) -> str:
    """A draft of the function at entry. With its `code`, the recompiler's boundary, a `bra` outside
    that code is a tail call and a conditional branch outside it is refused; without, the draft follows
    every branch. With `functions`, every function's code, a call passes the registers its callee reads."""
    stops = leaders(image, entry, code)
    params: set[int] = set()
    try:
        read_blocks(image, entry, stops, params, code, functions)
        framed = False
    except Unsupported as e:
        if "address of a local" not in str(e) and "argument passed on the stack" not in str(e):
            raise
        framed = True
    for attempt in range(2):
        reads, slots = read_blocks(image, entry, stops, params, code, functions, framed)
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
    lines = [fold_frame(line) for line in structure.Structurer(blocks, entry).run()]
    if lines and lines[-1] == "return;":
        lines.pop()
    body = "\n".join(lines)
    names = sorted({v for v in VAR.findall(body)} - {"r%d" % p for p in params}, key=lambda v: (v[0] != "r", int(v[1:])))
    head = "%s f%08X(%s)" % ("int" if returns else "void", entry, ", ".join("int r%d" % p for p in sorted(params)) or "void")
    decl = ["    int %s;" % ", ".join(n for n in names if n[0] != "v")] if any(n[0] != "v" for n in names) else []
    decl += ["    %s v%d;" % (LOCAL_TYPES[size], -offset) for offset, size in sorted(slots.items(), reverse=True)]
    decl += ["    FRAME(sp, %d);" % frame_size(image, stops)] if framed else []
    decl += [""] if decl else []
    return "\n".join([head, "{"] + decl + ["    " + line for line in lines] + ["}"]) + "\n"


def frame_size(image: "sh2.Image", stops: dict[int, int]) -> int:
    """How far below its entry value r15 goes."""
    low = 0
    for at, sp in stops.items():
        while True:
            ins = image.insn(at)
            slot = image.insn(at + 2) if ins.delay else None
            sp += sp_change(ins) + (sp_change(slot) if slot else 0)
            low = min(low, sp)
            at += 4 if slot else 2
            if slot or ins.op in ("bt", "bf", "rts") or at in stops:
                break
    return -low


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


def stack_arguments(st: State) -> list[str]:
    """The words stored at the bottom of the frame, which a callee may read as its fifth and later arguments.
    The function's stores are not told apart by path, so a local that sits there is passed too, harmlessly."""
    words = []
    while st.sp + 4 * len(words) in st.stored and len(words) < 4:
        words.append(st.sp + 4 * len(words))
    return [("LD32(%s)" % framed(off)) if st.framed else "v%d" % -off for off in words]


def read_block(image: "sh2.Image", start: int, stops: dict[int, int], params: set[int], flags: int,
               slots: dict[int, int], fresh: set[int], code: set[int] | None,
               functions: dict[int, set[int]] | None = None, framed: bool = False,
               stored: set[int] | None = None, saved: set[int] | None = None) -> tuple[Read, int]:
    st = State(flags=flags, sp=stops[start], slots=slots, fresh=set(fresh), framed=framed,
               stored=stored if stored is not None else set(), saved=saved if saved is not None else set())
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
            block.polls = [ins.target] if ins.target <= at else []
            break
        if ins.op == "bra" and code is not None and ins.target not in code:
            tail = call(ins, slot, st, params, image, functions)
            block.kind = "return"
            break
        if ins.op == "bra":
            step(slot, st, image)
            block.kind, block.targets = "goto", [ins.target]
            block.polls = [ins.target] if ins.target <= at else []
            break
        if ins.op == "rts":
            step(slot, st, image)
            block.kind = "return"
            break
        if ins.op == "jmp":
            if ins.n not in st.known:
                raise Unsupported("a jump through a register that is not a known address, a switch, at %08X" % at)
            tail = call(ins, slot, st, params, image, functions)
            block.kind = "return"
            break
        if ins.op in _CALLS:
            call(ins, slot, st, params, image, functions)
        else:
            step(ins, st, image)
            if slot:
                step(slot, st, image)
        at = nxt
        if at in stops:
            block.kind, block.targets = "goto", [at]
            break
    return Read(block, st.stmts, term, tail, st.fresh), st.flags


def read_blocks(image: "sh2.Image", entry: int, stops: dict[int, int], params: set[int], code: set[int] | None,
                functions: dict[int, set[int]] | None = None, framed: bool = False) -> tuple[dict[int, Read], dict[int, int]]:
    """Every block, read until the registers a call may pass settle: those written since the last call
    on every path into a block, so an argument set before a branch reaches the call after it."""
    fresh = {at: set() if at == entry else set(range(16)) for at in stops}
    while True:
        flags = 0
        reads: dict[int, Read] = {}
        slots: dict[int, int] = {}
        stored: set[int] = set()
        saved: set[int] = set()
        for at in sorted(stops):
            reads[at], flags = read_block(image, at, stops, params, flags, slots, fresh[at], code, functions, framed,
                                          stored, saved)
        into: dict[int, list[set[int]]] = {at: [] for at in stops}
        for read in reads.values():
            for target in read.block.targets:
                into[target].append(read.fresh)
        settled = {at: set() if at == entry or not into[at] else set.intersection(*into[at]) for at in stops}
        if settled == fresh:
            return reads, slots
        fresh = settled


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
            in_term = not redefined and (stmt.var in VAR.findall(read.term) or
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


def substitute(text: str, var: str, expr: str) -> str:
    wrapped = expr if re.match(r"^[\w.]+$", expr) or expr.startswith("(") and strip(expr) != expr else "(%s)" % expr
    return re.sub(r"\b%s\b" % var, lambda _: wrapped, text)


def uses_of(read: Read, returns: bool) -> set[str]:
    out = set(VAR.findall(read.term))
    if read.block.kind == "return" and returns:
        out.add("r0")
    return out


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("address", help="hex entry address")
    parser.add_argument("--module", default="KRNL", choices=sorted(IMAGES))
    parser.add_argument("--append", action="store_true", help="add the draft to its file in src/ instead of printing it")
    args = parser.parse_args()
    path, base = IMAGES[args.module]
    with open(os.path.join(ROOT, path), "rb") as f:
        image = sh2.Image(f.read(), base)
    functions = status.function_code() if args.module == "KRNL" else {}
    try:
        draft = lift(image, int(args.address, 16), functions.get(int(args.address, 16)), functions or None)
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
