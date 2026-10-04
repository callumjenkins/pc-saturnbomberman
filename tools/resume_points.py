"""Where the kernel's tasks can resume: the return address of every call to a
function that yields. A task parks inside a call to the kernel's yield (or to
setjmp) and comes back at that call's return address, which is inside a
function rather than at an entry, so the build needs it as a seed. A function
yields if it calls one that does, so the set grows from the kernel's own.

    python tools/resume_points.py [--check]    # prints the KRNL addresses; --check compares with seeds.json
"""
import json
import os
import sys

from paths import EXTRACT, ROOT, TOOLS

sys.path.insert(0, ROOT)
from saturnkit import sh2
from saturnkit.recomp import discover

BASE = 0x06006000
YIELDS = {0x060061C4, 0x06006D36}          # setjmp, the scheduler's yield


def held(p, f, reg):
    """The value `reg` holds all through `f`, when every write to it there is a literal load of that value."""
    values = set()
    for a in f.code:
        ins = p.img.insn(a)
        if reg in discover._writes(ins):
            if ins.op in ("jsr", "jmp", "bsrf", "braf"):     # listed as writes of the register they read
                continue
            if ins.fmt == "mov.l @Rm+,Rn" and ins.m == 15:   # the epilogue's restore
                continue
            if not (ins.op == "mov.l" and ins.size == 4 and ins.target is not None):
                return None
            values.add(p.img.literal(ins))
    return values.pop() if len(values) == 1 else None


def call_sites(p):
    """(function entry, call address, target or None) for every bsr and jsr reached."""
    for f in p.funcs.values():
        for a in sorted(f.code):
            ins = p.img.insn(a)
            if ins.op == "bsr":
                yield f.entry, a, ins.target
            elif ins.op == "jsr":
                lit = p._literal_for(a, ins.n)
                yield f.entry, a, lit[1] if lit and lit[0] == "lit" else held(p, f, ins.n)


def main():
    img = sh2.Image(open(f"{EXTRACT}/BOMSS/0KRNL.BIN", "rb").read(), BASE)
    seeds = [int(x, 16) for x in json.load(open(f"{TOOLS}/seeds.json")).get("KRNL", [])]
    p = discover.Program(img, [BASE] + seeds)
    sites = list(call_sites(p))
    yields = set(YIELDS)
    may = "--unknown-yields" in sys.argv                   # a call to an unknown target may yield too
    while True:
        more = {e for e, _, t in sites if t in yields or (may and t is None)} - yields
        if not more:
            break
        yields |= more
    points = sorted({a + 4 for _, a, t in sites if t in yields or (may and t is None)})
    unknown = sum(1 for _, _, t in sites if t is None)
    print(f"{len(yields)} yielding functions, {len(points)} resume points, {unknown} calls with no known target",
          file=sys.stderr)
    if "--check" in sys.argv:
        hit = [s for s in seeds if s in set(points)]
        print(f"{len(hit)} of {len(seeds)} existing seeds predicted", file=sys.stderr)
        for s in seeds:
            if s not in set(points):
                print(f"  not predicted: {s:08X}", file=sys.stderr)
    else:
        print(",".join(f"{a:08X}" for a in points))


if __name__ == "__main__":
    main()
