"""A first draft of a function's C, from its SH-2 instructions.

    python decomp/lift.py ADDRESS [--module KRNL] [--append]

The draft is straight from the instructions: registers become locals (r4 to r7 are the parameters,
stack slots become v locals), loads and stores go through LD and ST, calls go through GCALL, and the
control flow is rebuilt as if, while, break and continue. It is meant to be read and rewritten; run.py's
cosim decides whether it is right. Raises Unsupported for what it cannot read: a jump table, a control-register access, or code that reads a register it never set.
"""
import argparse
import os
import re
import sys
from dataclasses import dataclass, field
from typing import NamedTuple

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import modules  # noqa: E402
import registers  # noqa: E402
import status  # noqa: E402
import structure  # noqa: E402
from returns import left_for_callers  # noqa: E402
from saturnrecomp import sh2  # noqa: E402
from state import (LOCAL_TYPES, MAC, NO_FLAG, VAR, Copies, State, Stmt, Unsupported, const, copy_move, fold_frame, framed,  # noqa: E402
                   is_run_time_frame, loads_r15, number, restored, sp_change, step, steps_r15, strip, track)

_CALLS = ("bsr", "jsr")
TABLE_LOAD = re.compile(r"mov\.([wb]) @\(r0,r\d+\),r(\d+)$")     # the load of an entry of a jump table of words or bytes
SAVED = 2000                            # variables from here hold a register of the caller while a call into the middle of a function borrows it
MERGED = 1000                           # flag variables from here are made for a block entered with T in different variables
MAX_ROUNDS = 60                         # times read_blocks reads every block again before it gives up


class Walked(NamedTuple):
    """What `walk` finds: `offsets`, r15's offset at each leader; `lowest` offset r15 has at any instruction; the
    offsets at the `tails`, the jumps out of the function; the `copies`, registers that hold r15 at one offset
    throughout; `adjusts`, how far each of those has moved at each leader; and `run_time`, the leaders where r15 is
    below a frame whose size the function works out as it runs, with its offset before the frame."""
    offsets: dict[int, int]
    lowest: int
    tails: set[int]
    copies: dict[int, int]
    adjusts: dict[int, dict[int, int]]
    run_time: dict[int, int]


class Stops(dict):
    """r15's offset at each leader, and what `walk` found about the copies of it and the run-time frames."""

    def __init__(self, walked: Walked) -> None:
        super().__init__(walked.offsets)
        self.copies = walked.copies
        self.adjusts = walked.adjusts
        self.run_time = walked.run_time


@dataclass
class Read:
    """One block as read from the instructions, and the variables it uses and overwrites."""
    block: structure.Block
    stmts: list[Stmt]
    term: str                               # the branch condition or the returned expression
    tail: bool = False                      # it ends by jumping to another function
    fresh: set[int] = field(default_factory=set)         # State.fresh where the block ends
    clobbered: set[int] = field(default_factory=set)     # State.clobbered where the block ends
    r0_defined: bool = False                             # State.r0_defined where the block ends
    ctx_reads: set[int] = field(default_factory=set)     # State.ctx_reads
    loaded: set[int] = field(default_factory=set)        # State.loaded
    passes: set[int] = field(default_factory=set)        # State.entry_clobbered where the block ends
    lacks: str = ""                         # State.lacks: the block reads a T bit nothing before it set
    flag: str | None = None                 # State.flag where the block ends: what T holds on the way to its fall-through
    taken: str | None = None                # what T holds on the way to the target of its branch


def call(ins: "sh2.Insn", slot: "sh2.Insn", st: State, params: set[int], image: "sh2.Image",
         functions: dict[int, set[int]] | None = None) -> bool:
    """Writes the call as a statement. With `functions`, the arguments are the registers the callee reads, except
    those at the end that an earlier call overwrote: the callee finds there what that call left, as it does in the
    game's code. A call to a callee nobody can read passes as well the r4 to r7 the function never writes, which the
    callee finds as its caller left them. Without `functions`, a call passes those set since the last call, and a tail call hands on r4 to r7 as
    they stand, except those an earlier call overwrote: those at the end are left out, and one before a
    register that does go in passes what that call left, which the context holds."""
    tail = ins.op in ("jmp", "bra")
    where = const(ins.target) if ins.op in ("bsr", "bra") else st.get(ins.n)
    through_register = ins.op == "jmp" and number(where) is None and functions is not None
    if through_register and status.jump_kinds().get(ins.pc) == "switch":
        raise Unsupported("a jump table at %08X" % ins.pc)
    step(slot, st, image)
    if ins.op == "jmp" and functions is not None and ins.pc in status.polling_jumps():
        st.effect("POLL();")
    if st.parked and not tail:
        spill(ins, st, image, functions)
    known = functions is not None and number(where) is not None
    needs = sorted(registers.saved(image, number(where), functions)) if known else []
    restore: list[str] = []
    if needs:
        if tail and not (st.parked or st.sp == 0):
            raise Unsupported("goes to %s, the middle of a function that reads r%d from its caller" % (where, needs[0]))
        for reg in needs:
            if reg in st.touched:
                if not tail:                    # the context holds the caller's value, which this function gives back
                    kept = "c%d" % (SAVED + reg)
                    st.stmts.append(Stmt(kept, "R(%d)" % reg, False))
                    restore.append("SETR(%d, %s);" % (reg, kept))
                st.effect("SETR(%d, %s);" % (reg, strip(st.get(reg))))
        if st.sp and tail:
            st.effect("SETSP(%s);" % st.get(15))
    if st.run_time is not None:
        if tail:
            raise Unsupported("goes to %s below a frame of a run-time size" % where)
        st.effect("SETSP(r15);")
    helper = registers.routine(image, number(where), functions) if known and not tail else None
    if helper:
        text, changes, result = helper
        st.put(result, text.format(**{"r%d" % r: st.get(r) for r in range(8) if "{r%d}" % r in text}), False)
        for r in changes:
            st.clobbered.add(r)
            st.known.pop(r, None)
        return False
    reads = registers.reads(image, number(where), functions) if known else None
    args: list[str] = []
    if reads is not None:
        for r in sorted(reads & {0, 1, 2, 3}):          # a callee that takes an argument in a register the calling convention does not pass
            st.effect("SETIN(%d, %s);" % (r, strip(st.get(r))))
        top = max((r for r in reads if r not in st.clobbered), default=3)
        args = [st.get(r) if r in reads else "0" for r in range(4, top + 1)]
    else:
        top = 7 if tail else max((r for r in range(4, 8) if r in st.fresh or r in params or r in st.kept), default=3)
        for r in range(4, top + 1):
            args.append("" if r in st.clobbered else st.get(r))
        while args and not args[-1]:
            args.pop()
        args = [a or st.get(4 + i) for i, a in enumerate(args)]     # what an earlier call left, which the context holds
    extra = stack_arguments(st) if not tail and not st.parked and st.run_time is None else []   # a parked function's are in its frame already
    if extra:
        for r in sorted(reads or ()):
            if r > 3 + len(args):
                st.get(r)                       # overwritten by a call: it cannot be left out before a stack argument
        args += [st.get(r) for r in range(4 + len(args), 8)] if reads is None else ["0"] * (4 - len(args))
        args += extra
    if reads is None:                           # a callee nobody can read may leave a register it does not write as it found it
        for r in sorted(st.ctx_wanted - st.clobbered - set(range(4, 4 + len(args)))):
            if r or st.r0_defined:
                st.effect("SETIN(%d, %s);" % (r, strip(st._get(r))))
    text = "%s%d(%s%s)" % ("GJUMP" if tail else "GCALL", len(args), where, "".join(", " + a for a in args))
    if tail and st.framed and not st.sp:
        st.effect("UNFRAME(sp);")
    written = registers.writes(image, number(where), functions) - {0} if known else registers.EVERY - {0}
    leaves_r0 = known and not tail and 0 not in registers.writes(image, number(where), functions)    # a callee that never writes r0 gives back the caller's
    if leaves_r0:
        st.stmts.append(Stmt(None, text + ";", False, {"r%d" % r for r in written}))
    else:
        st.stmts.append(Stmt("r0", text, False, {"r%d" % r for r in written}))
    for line in restore:
        st.effect(line)
    st.clobbered |= written
    st.r0_defined = True
    st.pr_intact = False
    st.entry_clobbered -= written
    st.callee = where
    st.clobbered.discard(0)
    st.fresh &= set(range(1, 8)) - written
    for r in range(8):
        if r not in written:
            continue
        st.known.pop(r, None)
    if not leaves_r0:
        st.known.pop(0, None)
    return tail


def table_entry(image: "sh2.Image", table: tuple[int | None, int, int], k: int) -> int:
    """Entry k of a jump table of words or of bytes, which `mov.w` and `mov.b` load signed."""
    base, _, size = table
    if size == 2:
        word = image.u16(base + 2 * k)
        return word - 0x10000 if word >= 0x8000 else word
    word = image.u16((base + k) & ~1)
    byte = (word >> 8 if (base + k) % 2 == 0 else word) & 0xFF
    return byte - 256 if byte >= 128 else byte


def spill(ins: "sh2.Insn", st: State, image: "sh2.Image", functions: dict[int, set[int]] | None) -> None:
    """Before a call in a function a task can park in, sets r15 where the game's code has it, so the callee's frame
    sits below this one's words. If the call can switch tasks, its return address is a resume point, which the
    recompile seeds, and a task resumed there has only the registers and stack the code after it reads, so those
    are set too. pr is that address, as the call's bsr or jsr leaves it: the runtime tells a task that comes back
    where it parked from one resumed elsewhere by the address the callee returns to."""
    after = ins.pc + 4
    resumes = functions is None or after in functions
    if resumes and functions is not None:
        for reg in sorted(registers.saved(image, after, functions)):
            st.effect("SETR(%d, %s);" % (reg, strip(st.get(reg))))
    set_sp = "SETSP(%s);" % st.get(15)
    if st.sp_set != set_sp:
        st.effect(set_sp)
    if resumes:
        st.effect("SETPR(0x%08X);" % after)


def leaders(image: "sh2.Image", entry: int, code: set[int] | None = None, parked: bool = False) -> Stops:
    """Entry plus every branch target and instruction that follows a branch, with r15's offset at each. A parked
    function may leave with its frame still down, by a jump to code that pops it."""
    return Stops(walk(image, entry, code, parked))


def frame_depth(image: "sh2.Image", entry: int, code: set[int] | None = None) -> int:
    """How many bytes below its entry the function's own pushes and stack adjustments take r15 at the lowest."""
    return -walk(image, entry, code, True).lowest


def tail_offsets(image: "sh2.Image", entry: int, code: set[int] | None = None) -> set[int]:
    """r15's offset from its entry value at each jump the function makes to code outside it."""
    return walk(image, entry, code, True).tails


def takes_r15_back_first(image: "sh2.Image", at: int, copies: Copies) -> bool:
    """Whether the instructions from `at` set r15 from a copy or from memory before any of them reads or writes it, or
    branches, so a path that arrives below a frame of a run-time size and one that does not end up the same."""
    while image.contains(at):
        ins = image.insn(at)
        if restored(ins, copies.kept(), copies.adjust) is not None or loads_r15(ins):
            return True
        if 15 in registers.defs(ins) | registers.uses(ins) or ins.target is not None or ins.op in ("rts", "jmp", "jsr", "bsr"):
            return False
        at += 2
    return False


def walk(image: "sh2.Image", entry: int, code: set[int] | None, parked: bool,
         spoiled: frozenset[int] = frozenset(), joins: tuple[tuple[int, int], ...] = ()) -> Walked:
    """The leaders of the function and what else its r15 does. A `mov Rm,r15` of a copy sets r15 back to the offset
    the copy was made at, plus that move, and ends a frame of a run-time size. A register moved by different
    amounts on two paths to a leader is no copy, and the walk starts again without it, so that nothing it read
    earlier used it. A leader that one path reaches below a frame of a run-time size and another reaches with r15 at
    that frame's base is a join of the two: the walk starts again with r15 below the frame there, and the other path
    sets r15 to the base."""
    found = {entry: 0}
    run_time: dict[int, int] = {}
    moved: dict[int, dict[int, int]] = {entry: {}}
    tables = status.jump_targets()
    copies = Copies(spoiled)
    lowest = 0
    tails: set[int] = set()
    forced = dict(joins)                        # the leaders that are joins, and the base of the frame below them
    found_joins: dict[int, int] = {}
    # r15, how far the copies have moved, and the base of a run-time frame, at each instruction a path has reached
    states: dict[int, tuple[int, dict[int, int], int | None]] = {}
    work = [(entry, 0, {}, None)]

    def reach(target: int, sp: int, base: int | None) -> None:
        found.setdefault(target, sp)
        moved.setdefault(target, dict(copies.adjust))
        if base is not None:
            run_time.setdefault(target, base)
        work.append((target, sp, dict(copies.adjust), base))

    def meet(at: int, sp: int, base: int | None) -> None:
        """A second path to an instruction has to find r15 where the first did, and below a run-time frame or not, unless
        the instruction takes r15 from a copy or from memory. A copy of r15 moved by another amount on it is no copy."""
        was_sp, was_moves, was_base = states[at]
        restores = takes_r15_back_first(image, at, copies)
        if was_sp != sp and not restores:
            raise Unsupported("the stack is %d bytes down on one path to %08X and %d on another" % (-was_sp, at, -sp))
        if was_base != base:
            below = was_base if was_base is not None else base
            at_base = (sp if base is None else was_sp) == below
            if restores:
                run_time[at] = below                                    # the restore is the same on both paths
            elif at_base and at not in forced:
                found_joins[at] = below
            else:
                raise Unsupported("r15 is below a frame of a run-time size on one path to %08X and not on another" % at)
        copies.spoiled |= {r for r in was_moves.keys() | copies.adjust.keys() if was_moves.get(r, 0) != copies.adjust.get(r, 0)}

    while work:
        at, sp, copies.adjust, base = work.pop()
        known: dict[int, int] = {}
        while image.contains(at):
            if at in forced:
                base = forced[at]
                run_time[at] = base
            if at in states:
                meet(at, sp, base)
                break
            states[at] = (sp, dict(copies.adjust), base)
            ins = image.insn(at)
            slot = image.insn(at + 2) if ins.delay else None
            nxt = at + (4 if slot else 2)
            if ins.op in ("braf", "bsrf", "rte", "trapa", "sleep") or ins.op == ".word":
                raise Unsupported("%s at %08X" % (ins.text, at))
            for each in (ins, slot) if slot else (ins,):
                copies.note(each, sp, known, base is not None)
                restore = restored(each, copies.kept(), copies.adjust)
                if restore is not None:
                    sp, base = restore, None
                elif base is not None and loads_r15(each):
                    sp, base = base, None
                elif is_run_time_frame(each, known):
                    base = sp if base is None else base
                elif base is not None and 15 in registers.defs(each):
                    if not steps_r15(each):
                        raise Unsupported("moves r15 below a frame of a run-time size at %08X" % at)
                else:
                    sp += sp_change(each, known)
            track(ins, known, image)
            lowest = min(lowest, sp)
            leaves = code is not None and ins.target is not None and ins.target not in code
            if leaves and ins.op != "bra" and ins.op in ("bt", "bf", "bt/s", "bf/s"):
                raise Unsupported("a conditional branch out of the function at %08X" % at)
            if ins.op in ("bt", "bf", "bt/s", "bf/s", "bra") and not leaves:
                for target in ([ins.target] if ins.op == "bra" else [ins.target, nxt]):
                    reach(target, sp, base)
                break
            if ins.op == "jmp" and at in tables:
                if code is not None and (not set(tables[at]) <= code or set(tables[at]) & set(status.function_code())):
                    raise Unsupported("a jump table at %08X to code the game's build enters as functions" % at)
                for target in dict.fromkeys(tables[at]):
                    reach(target, sp, base)
                break
            if ins.op in ("rts", "jmp") or leaves and ins.op == "bra":
                if base is not None:
                    raise Unsupported("leaves below a frame of a run-time size at %08X" % at)
                if sp and not (parked and ins.op != "rts"):
                    raise Unsupported("returns with the stack %d bytes off at %08X: a piece of a larger function"
                                      % (sp, at))
                if ins.op != "rts" and (leaves or ins.op == "jmp"):
                    tails.add(sp)
                break
            if ins.op in ("jsr", "bsr") and code is not None and nxt not in code:
                break                           # the callee never returns: what follows the call is data
            at = nxt
    if copies.spoiled != spoiled or found_joins:
        return walk(image, entry, code, parked, frozenset(copies.spoiled), tuple(sorted((forced | found_joins).items())))
    return Walked(found, lowest, tails, copies.kept(), moved, run_time)


def lift(image: "sh2.Image", entry: int, code: set[int] | None = None, functions: dict[int, set[int]] | None = None,
         parked: bool = False) -> str:
    """A draft of the function at entry. With its `code`, the recompiler's boundary, a `bra` outside
    that code is a tail call and a conditional branch outside it is refused; without, the draft follows
    every branch. With `functions`, every function's code, a call passes the registers its callee reads.
    With `parked`, the function is one a task can park in, and the draft keeps in the guest's registers and
    stack what the code after each call that can switch tasks reads."""
    stops = leaders(image, entry, code, parked)
    params: set[int] = set()
    gives = tuple(sorted(left_for_callers(image, functions).get(entry, ()))) if functions else ()
    framed = parked
    if not parked:
        try:
            read_blocks(image, entry, stops, params, code, functions, gives=gives)
        except Unsupported as e:
            if not any(why in str(e) for why in ("address of a local", "argument passed on the stack", "two sizes")):
                raise
            framed = True
    attempts = 2
    attempt = -1
    while attempt + 1 < attempts:
        attempt += 1
        reads, slots = read_blocks(image, entry, stops, params, code, functions, framed, parked, gives)
        returns = any(s.var == "r0" for r in reads.values() for s in r.stmts)
        live_in, live_out = liveness(reads, returns)
        if returns and "r0" in live_in[entry]:
            returns = False
            live_in, live_out = liveness(reads, returns)
        stray = sorted(v for v in live_in[entry] if not (v[0] == "r" and 4 <= int(v[1:]) <= 7))
        if not framed and not parked and any(v[0] == "v" for v in stray):
            framed = True                       # a local read before it is written holds what the frame had, which only guest memory keeps
            attempts += 1
            continue
        inherited = [v for v in stray if v == MAC or v[0] == "r" and (int(v[1:]) <= 3 or 8 <= int(v[1:]) <= 14)]     # its caller's, which the context holds
        stray = [v for v in stray if v not in inherited]
        if stray and attempt == attempts - 1:
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
        if block.kind == "switch":
            block.value = strip(read.term)
        elif block.kind == "branch":
            block.value = strip(read.term) if not read.term.startswith("!") else "!(%s)" % strip(read.term[1:])
        elif block.kind == "return":
            block.value = strip(read.term) or ("r0" if returns else "")
        blocks[at] = block
    lines = [("%s = ((long long)MACH() << 32) | (unsigned)MACL();" % MAC) if v == MAC else "%s = R(%s);" % (v, v[1:])
             for v in inherited]
    try:
        written = structure.Structurer(blocks, entry).run()
    except structure.Unstructured:
        written = structure.flat(blocks, entry)
    lines += [fold_frame(line) for line in written]
    if inherited[:1] == [MAC] and not any(MAC in line for line in lines[len(inherited):]):
        lines.pop(0)                            # the function only saves and restores MACH:MACL, which the context keeps
    if lines and lines[-1] == "return;":
        lines.pop()
    body = "\n".join(lines)
    names = sorted({v for v in VAR.findall(body)} - {"r%d" % p for p in params}, key=lambda v: (v[0] != "r", int(v[1:])))
    head = "%s f%08X(%s)" % ("int" if returns else "void", entry, ", ".join("int r%d" % p for p in sorted(params)) or "void")
    decl = ["    int %s;" % ", ".join(n for n in names if n[0] in "rc")] if any(n[0] in "rc" for n in names) else []
    decl += ["    long long %s;" % MAC] if MAC in names else []
    decl += ["    %s v%d;" % (LOCAL_TYPES[size], -offset) for offset, size in sorted(slots.items(), reverse=True)]
    decl += ["    ENTRY_SP(sp);"] if parked else ["    FRAME(sp, %d);" % frame_size(image, stops)] if framed else []
    decl += [""] if decl else []
    return "\n".join([head, "{"] + decl + ["    " + line for line in lines] + ["}"]) + "\n"


def frame_size(image: "sh2.Image", stops: Stops) -> int:
    """How far below its entry value r15 goes."""
    low = 0
    for at, sp in stops.items():
        known: dict[int, int] = {}
        adjust = dict(stops.adjusts[at])
        while True:
            ins = image.insn(at)
            slot = image.insn(at + 2) if ins.delay else None
            for each in (ins, slot) if slot else (ins,):
                restore = restored(each, stops.copies, adjust)
                sp = sp + sp_change(each, known) if restore is None else restore
                move = copy_move(each, known)
                if move and move[0] in stops.copies:
                    adjust[move[0]] = adjust.get(move[0], 0) + move[1]
            track(ins, known, image)
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
    """The words stored at the bottom of the frame, which a callee may read as its fifth and later arguments."""
    words = []
    while st.sp + 4 * len(words) in st.stored and len(words) < 4:
        words.append(st.sp + 4 * len(words))
    return [("LD32(%s)" % framed(off)) if st.framed else "v%d" % -off for off in words]


def read_block(image: "sh2.Image", entry: int, start: int, stops: Stops, params: set[int], flags: int,
               slots: dict[int, int], fresh: set[int], code: set[int] | None,
               functions: dict[int, set[int]] | None = None, framed: bool = False,
               stored: set[int] | None = None, saved: set[int] | None = None, parked: bool = False,
               clobbered: set[int] = frozenset(), flag: str | None = None,
               merged: dict[int, str] | None = None, gives: tuple[int, ...] = (),
               sync: set[int] = frozenset(), wanted: frozenset[int] = frozenset(), r0_defined: bool = False) -> tuple[Read, int]:
    st = State(flags=flags, sp=stops[start], copies=stops.copies, adjust=dict(stops.adjusts[start]), run_time=stops.run_time.get(start), slots=slots, fresh=set(fresh), framed=framed, parked=parked,
               clobbered=set(clobbered), entry_clobbered=set(clobbered), flag=flag,
               touched=registers.written(image, code) if code is not None else frozenset(range(8, 15)),
               kept=registers.kept(image, code) if code is not None and functions is not None else frozenset(),
               pr_intact=start == entry, ctx_wanted=wanted, r0_defined=r0_defined,
               stored=stored if stored is not None else set(), saved=saved if saved is not None else set())
    block = structure.Block(start)
    term = ""
    tail = False
    table: tuple[int | None, int, int] | None = None   # the table address, the register and the size of the last entry loaded from it
    taken_flag = after_slot = None
    at = start
    while True:
        ins = image.insn(at)
        slot = image.insn(at + 2) if ins.delay else None
        nxt = at + (4 if slot else 2)
        if ins.op in ("bt", "bf", "bt/s", "bf/s"):
            if st.flag is None:
                st.lacks = st.lacks or "a branch on a T bit set in another block at %08X" % at
            test = st.flag or NO_FLAG
            before = st.flag
            if slot:
                step(slot, st, image)
            after_slot = st.flag
            if st.flag == before:           # the slot left T alone, so on each way out it holds what the test settled
                taken_flag, st.flag = ("1", "0") if ins.op.startswith("bt") else ("0", "1")
            else:
                taken_flag = st.flag
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
            for reg in gives:                   # what callers read of r1 to r7 after the call, which the context carries back
                st.effect("SETR(%d, %s);" % (reg, strip(st.get(reg))))
            for reg in sorted(st.touched - st.saved if code is not None else ()):   # r8 to r14 written and not pushed: the function hands them on
                st.effect("SETR(%d, %s);" % (reg, strip(st.get(reg))))
            block.kind = "return"
            break
        if ins.op == "jmp" and ins.pc in status.jump_targets():
            targets = status.jump_targets()[ins.pc]
            if table is None or table[0] is None or image.insn(ins.pc - 2).text != "add r%d,r0" % table[1] or any(
                    table[0] + table_entry(image, table, k) != target for k, target in enumerate(targets)):
                raise Unsupported("a jump table at %08X that is not words or bytes added to its address" % ins.pc)
            step(slot, st, image)
            if ins.pc in status.polling_jumps():
                st.effect("POLL();")
            term = st.get(table[1])
            block.kind, block.targets = "switch", list(dict.fromkeys(targets))
            block.cases = [(table_entry(image, table, k), target) for k, target in enumerate(targets)]
            break
        if ins.op == "jmp":
            tail = call(ins, slot, st, params, image, functions)
            block.kind = "return"
            break
        if ins.op in _CALLS:
            call(ins, slot, st, params, image, functions)
            st.flag = None
            if ins.op in ("jsr", "bsr") and code is not None and nxt not in code:
                block.kind = "return"           # the callee never returns: what follows the call is data
                break
        else:
            loads = TABLE_LOAD.match(ins.text)
            if loads:
                table = (number(st.get(0)), int(loads[2]), 2 if loads[1] == "w" else 1)
            step(ins, st, image)
            if slot:
                step(slot, st, image)
        at = nxt
        if at in stops:
            block.kind, block.targets = "goto", [at]
            break
    if st.run_time is None and st.framed and any(stops.run_time.get(target) is not None for target in block.targets):
        st.put(15, st.get(15))                  # the block after has r15 as a variable, which the way in that made no frame sets here
    for reg in sorted(sync - st.clobbered):         # the block after reads it from the context, where a path that made no call left nothing
        st.effect("SETIN(%d, %s);" % (reg, st.get(reg)))
    if merged and block.kind in ("goto", "branch"):
        # the variable T is in once the block ends is what T holds on every way out, a branch's own two ways included
        holds = after_slot if block.kind == "branch" else st.flag
        for target in dict.fromkeys(block.targets):
            if target in merged and holds is not None:
                st.stmts.append(Stmt(merged[target], holds))
    return Read(block, st.stmts, term, tail, st.fresh, st.clobbered, st.r0_defined, st.ctx_reads, st.loaded, st.entry_clobbered, st.lacks, st.flag, taken_flag), st.flags


def read_blocks(image: "sh2.Image", entry: int, stops: Stops, params: set[int], code: set[int] | None,
                functions: dict[int, set[int]] | None = None, framed: bool = False,
                parked: bool = False, gives: tuple[int, ...] = ()) -> tuple[dict[int, Read], dict[int, int]]:
    """Every block, read until the registers a call may pass settle: those written since the last call
    on every path into a block, so an argument set before a branch reaches the call after it, and those a call
    overwrote on some path into it, which the block may not read."""
    fresh = {at: set() if at == entry else set(range(16)) for at in stops}
    clobbered: dict[int, set[int]] = {at: set() for at in stops}
    carried: dict[int, str | None] = {at: None for at in stops}
    merged: dict[int, str] = {}                 # blocks entered with T in different variables, to the one the ways in copy it to
    wanted: frozenset[int] = frozenset()        # the registers some block reads from the context
    defined = {at: at != entry for at in stops}  # r0 holds a value on every path into the block
    syncs: dict[int, set[int]] = {at: set() for at in stops}    # per block, the registers it sets in the context for what follows to read
    for _ in range(MAX_ROUNDS):
        flags = 0
        reads: dict[int, Read] = {}
        slots: dict[int, int] = {}
        stored: set[int] = set()
        saved: set[int] = set()
        for at in sorted(stops):
            reads[at], flags = read_block(image, entry, at, stops, params, flags, slots, fresh[at], code, functions, framed,
                                          stored, saved, parked, clobbered[at], carried[at], merged, gives, syncs[at], wanted, defined[at])
        into: dict[int, list[set[int]]] = {at: [] for at in stops}
        after: dict[int, list[set[int]]] = {at: [] for at in stops}
        holding: dict[int, list[str | None]] = {at: [] for at in stops}
        ways: dict[int, list[str]] = {at: [] for at in stops}
        for read in reads.values():
            for i, target in enumerate(read.block.targets):
                ways[target].append(read.block.kind)
                into[target].append(read.fresh)
                after[target].append(read.clobbered)
                holding[target].append(read.taken if read.block.kind == "branch" and i == 0 else read.flag)
        settled = {at: set() if at == entry or not into[at] else set.intersection(*into[at]) for at in stops}
        spoiled = {at: set().union(*after[at]) for at in stops}
        # T is carried into a block only when every way into it leaves it in the same variable
        leaving = {at: None if at == entry or len(set(holding[at])) != 1 else holding[at][0] for at in stops}
        merges = {}
        for number, at in enumerate(sorted(stops)):
            if at != entry and len(set(holding[at])) > 1 and None not in holding[at] and set(ways[at]) <= {"goto", "branch"}:
                merges[at] = leaving[at] = "c%d" % (MERGED + number)
        # a block's registers read from the context, and those it passes on to the blocks after it
        reading = {at: set(read.loaded) for at, read in reads.items()}
        for _ in range(len(reads)):
            for at, read in reads.items():
                reading[at] |= {r for target in read.block.targets for r in reading[target] if r in read.passes}
        needs = {at: set().union(*(reading[t] for t in read.block.targets)) if read.block.targets else set()
                 for at, read in reads.items()}
        reading_now = frozenset().union(*(read.ctx_reads for read in reads.values()))
        if any(s.var == "r0" and s.pure for read in reads.values() for s in read.stmts):
            reading_now |= {0}                  # a callee that leaves r0 alone gives it back, so r0 reaches it in the context
        coming: dict[int, list[bool]] = {at: [] for at in stops}
        for read in reads.values():
            for target in read.block.targets:
                coming[target].append(read.r0_defined)
        defined_now = {at: at != entry and bool(coming[at]) and all(coming[at]) for at in stops}
        if (settled == fresh and spoiled == clobbered and leaving == carried and merges == merged and needs == syncs
                and reading_now == wanted and defined_now == defined):
            for read in reads.values():
                if read.lacks:
                    raise Unsupported(read.lacks)
            return reads, slots
        fresh, clobbered, carried, merged, syncs, wanted, defined = settled, spoiled, leaving, merges, needs, reading_now, defined_now
    raise Unsupported("what the blocks leave in registers and T does not settle")


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
    parser.add_argument("--module", default=modules.DEFAULT, choices=modules.SCOPE)
    parser.add_argument("--append", action="store_true", help="add the draft to its file in src/ instead of printing it")
    parser.add_argument("--parked", action="store_true", help="the function is one a task can park in")
    args = parser.parse_args()
    os.environ["DECOMP_MODULE"] = args.module
    image = status.image()
    functions = status.function_code()
    try:
        draft = lift(image, int(args.address, 16), functions.get(int(args.address, 16)), functions or None, args.parked)
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
