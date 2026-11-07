"""Swapped C functions whose callers read a register the C does not give them.

    python decomp/returns.py

A function declared void leaves the context's r0 as the last callee left it, or as the caller had it. The
original leaves whatever its own last write to r0 was, and a caller that tests r0 after the call sees that.
So a void function that writes r0 on a path to its `rts` has to return it. One that only tail-calls passes
its callee's r0 through the context and needs nothing.

The same goes for r1 to r7 in any function: the C leaves them as the caller had them, so a function that writes
one of them and a caller whose own instructions read it before writing it, as a runtime helper's caller does,
cannot be swapped as C that returns one value.
"""
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(os.path.dirname(HERE), "saturn-recomp", "src"))
import gen  # noqa: E402
import modules  # noqa: E402
import registers  # noqa: E402
import status  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

LOOKAHEAD = 14      # instructions between loading a function's address and the jsr through that register
SCAN_MAX = 400      # instructions a caller is followed for after a call, at most
_BRANCHES = ("bt", "bf", "bt/s", "bf/s")
_ENDS = ("jsr", "bsr", "bsrf", "rts", "jmp", "rte", "braf")


def readers(image: sh2.Image, code: dict[int, set[int]], voids: set[int]) -> dict[int, list[int]]:
    """For each void function that writes r0 before an rts, the return addresses whose code reads r0 first."""
    own = {a for a in voids if a in code and _has_rts(image, code[a]) and 0 in registers.writes(image, a, code)}
    sites = _call_sites(image, set().union(*code.values()), own)
    found = {}
    for callee, afters in sites.items():
        reading = sorted(a for a in afters if 0 in registers.reads(image, a, code))
        if reading:
            found[callee] = reading
    return found


def outputs(image: sh2.Image, code: dict[int, set[int]], swapped: set[int]) -> dict[int, list[tuple[int, list[int]]]]:
    """For each swapped function with code that writes r1 to r7, the return addresses after which an instruction of the
    caller's reads one of them before writing it, with those registers."""
    written = {}
    for a in swapped & code.keys():
        regs = {r for pc in code[a] for r in registers.defs(image.insn(pc)) if 1 <= r <= 7}
        if regs:
            written[a] = frozenset(regs)
    pcs = set().union(*code.values())
    found: dict[int, list[tuple[int, list[int]]]] = {}
    for callee, afters in _call_sites(image, pcs, set(written)).items():
        for after in sorted(afters):
            reading = _read_first(image, pcs, after, written[callee])
            if reading:
                found.setdefault(callee, []).append((after, sorted(reading)))
    return found


def swapped(kind: str | None = None) -> set[int]:
    """The addresses of the module's swapped functions, only those returning `kind` if it is given."""
    rows = {r.address: r for r in status.build_table() if r.module == modules.current().name}
    return {a for a, sig in gen.signatures().items() if a in rows and rows[a].state == "swapped" and kind in (None, sig.returns)}


def swapped_void() -> set[int]:
    return swapped("void")


def _call_sites(image: sh2.Image, pcs: set[int], callees: set[int]) -> dict[int, set[int]]:
    """The return address of each call in the code at `pcs` to one of `callees`, by callee. A call is a bsr, or a
    jsr through a register that a pc-relative load set from the function's address and nothing has rewritten."""
    sites: dict[int, set[int]] = {}
    for pc in sorted(pcs):
        ins = image.insn(pc)
        if ins.op == "bsr" and ins.target in callees:
            sites.setdefault(ins.target, set()).add(pc + 4)
        elif ins.op == "mov.l" and image.literal(ins) in callees:
            for at in range(pc + 2, pc + 2 + 2 * LOOKAHEAD, 2):
                if at not in pcs:
                    break
                later = image.insn(at)
                if later.op == "jsr" and later.n == ins.n:
                    sites.setdefault(image.literal(ins), set()).add(at + 4)
                    break
                if ins.n in registers.defs(later):
                    break
    return sites


def _read_first(image: sh2.Image, pcs: set[int], start: int, wanted: frozenset[int]) -> set[int]:
    """The registers of `wanted` that an instruction from `start` on reads before any instruction writes them,
    along every path to a call or a return. What a callee would read does not count."""
    found: set[int] = set()
    seen: set[tuple[int, frozenset[int]]] = set()
    work = [(start, frozenset())]
    for _ in range(SCAN_MAX):
        if not work:
            break
        at, written = work.pop()
        while at in pcs and (at, written) not in seen:
            seen.add((at, written))
            ins = image.insn(at)
            slot = image.insn(at + 2) if ins.delay else None
            for each in (ins, slot) if slot else (ins,):
                found |= (registers.uses(each) & wanted) - written
                written |= registers.defs(each)
            if ins.op in _ENDS:
                break
            if ins.op in _BRANCHES:
                work.append((ins.target, written))
            at = ins.target if ins.op == "bra" else at + (4 if slot else 2)
    return found


def _has_rts(image: sh2.Image, code: set[int]) -> bool:
    """Whether the function has an rts, so r0 at its end is its own."""
    return any(image.insn(pc).op == "rts" for pc in code)


def main() -> None:
    image, code = status.image(), status.function_code()
    found = readers(image, code, swapped_void())
    for callee, afters in sorted(found.items()):
        print("%08X is void, and the code after the calls at %s reads r0" % (callee, " ".join("%08X" % a for a in afters[:4])))
    changed = outputs(image, code, swapped())
    for callee, sites in sorted(changed.items()):
        after, regs = sites[0]
        print("%08X writes r%s, which the code after %d of its calls reads first, as at %08X"
              % (callee, ", r".join(map(str, regs)), len(sites), after))
    sys.exit(1 if found or changed else 0)


if __name__ == "__main__":
    main()
