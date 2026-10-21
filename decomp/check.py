"""Runs each decompiled kernel function (krnl.c) against the game's own code.

    python decomp/check.py [--trials N] [--seed S] [FUNCTION ...]

The original is 0KRNL.BIN, run by the SH-2 interpreter in saturn-recomp. The decompiled C is built
for the host with DECOMP_HOST and run on a copy of the same memory. Each trial gives both the same
random arguments and the same random data, then compares the return value, if the function has one,
and every byte of work RAM and VDP1 VRAM afterwards.
"""
import argparse
import ctypes
import os
import random
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
sys.path.insert(0, HERE)
import gen  # noqa: E402
from saturnrecomp import sh2emu  # noqa: E402

KRNL = os.path.join(ROOT, "build", "extract", "BOMSS", "0KRNL.BIN")
BASE = 0x06006000
WRAM, VDP1 = 0x06000000, 0x05D00000
# Random data covers the tables the functions read. Code and the literal pools below stay as they are.
DATA = (0x060B0000, 0x060F0000)
VDP1_DATA = 0x100
# The game's functions spill registers onto the stack, which the host build has no counterpart for.
STACK = 0x06100000 - 0x1000


CALL_HOOK = ctypes.CFUNCTYPE(ctypes.c_uint32, ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32), ctypes.c_int)


# Values where a comparison, a width or a sign changes, which random numbers rarely land on.
EDGES = [0, 1, 2, 0x7F, 0x80, 0xFF, 0x100, 0x7FFF, 0x8000, 0xFFFF, 0x10000, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF,
         0xFFFFFFFE, 0xFFFFFF80, 0xFFFF8000]


def ptr(lo, span, align=4):
    return ("ptr", lo, span, align)


def rng_int(lo, hi):
    return ("int", lo, hi)


# Arguments a function needs narrower than its type allows: name: (arguments, returns a value).
# Any other function in krnl.c is given random arguments of the types it declares.
SPEC = {
    "f0600665C": ([], False),
    "f06006B38": ([rng_int(0, 200)], False),
    "f0600940A": ([rng_int(0, 200)], False),
    "f0600942E": ([], False),
    "f0600A3E0": ([ptr(0x060C0000, 0x100), ptr(0x060C1000, 0x100, 1), rng_int(-40000, 40000)], False),
    "f0600A4B0": ([("int", 0, 0xFFFF)], True),
    "f0600B934": ([rng_int(0, 1000), rng_int(0, 1000)], True),
    "f0600A25E": ([rng_int(-(1 << 31), (1 << 31) - 1)], False),
    "f0600A2D8": ([rng_int(-(1 << 31), (1 << 31) - 1)], False),
    "f060A5EEC": ([ptr(0x060C0000, 0x400)], True),
}


# The game's code a function calls, in order. Memory alone cannot tell two calls apart when their
# stores do not overlap.
CALLS = {
    "f060A5EEC": [0x060A5F2E, 0x060A5F22],
}


def default_spec(sig):
    """Random arguments for each parameter of a definition in krnl.c, from its type."""
    kinds = {"uint32_t": ptr(0x060C0000, 0x400), "short": rng_int(-(1 << 15), (1 << 15) - 1),
             "int": ("any",), "unsigned int": rng_int(0, (1 << 32) - 1)}
    unknown = [t for t in sig.params if t not in kinds]
    if unknown:
        raise SystemExit("%s: no default argument for %s; add it to SPEC" % (sig.name, ", ".join(unknown)))
    return [kinds[t] for t in sig.params], sig.returns != "void"


def build(source=os.path.join(HERE, "krnl.c")):
    out = os.path.join(tempfile.mkdtemp(prefix="decomp-"), "libdecomp.so")
    subprocess.check_call(["clang", "-std=gnu11", "-O1", "-Wall", "-shared", "-fPIC", "-fwrapv", "-DDECOMP_HOST",
                           "-I", HERE, "-o", out, source, os.path.join(HERE, "host_mem.c")])
    return ctypes.CDLL(out)


def value(kind, r):
    if kind[0] == "any":
        # whatever a parameter might hold: a small count, a negative, a pointer into the data, anything
        return value(r.choice([("int", 0, 40), ("int", -40, 0), ptr(0x060C0000, 0x400), ptr(0x060B0000, 0x40000),
                               ("int", -(1 << 31), (1 << 31) - 1), ("pick", EDGES)]), r)
    if kind[0] == "pick":
        return r.choice(kind[1])
    if kind[0] == "int":
        return r.randint(kind[1], kind[2])
    lo, span, align = kind[1:]
    return lo + r.randrange(0, span // align) * align


def hook_for(cpu, state):
    """What the host build's g_call runs: the game's function on the interpreter that holds the host
    build's memory. Registers r8 to r15 and pr come back unchanged, as the runtime's swap does."""
    @CALL_HOOK
    def hook(addr, args, n):
        keep = (cpu.r[8:], cpu.pr)
        sp = cpu.r[15]
        try:
            if n > 4:
                sp -= 4 * (n - 4)
                for i in range(4, n):
                    cpu.mem.write(sp + 4 * (i - 4), 4, args[i])
                cpu.r[15] = sp
            return cpu.call(addr, **{"r%d" % (4 + i): args[i] for i in range(min(n, 4))})
        except Exception as e:                      # an access outside the mapped memory, or no return
            state["error"] = str(e)
            return 0
        finally:
            cpu.r[8:], cpu.pr = keep
            state["calls"].append(addr)
    return hook


def trial(lib, name, args, returns, r):
    cpu = sh2emu.load(KRNL, BASE)               # the game's own function
    host = sh2emu.load(KRNL, BASE)              # the memory the host build runs on, and its callees
    wram = cpu.mem.regions[0][2]
    vdp1 = cpu.mem.add(VDP1, 0x80000)
    hwram = host.mem.regions[0][2]
    hvdp1 = host.mem.add(VDP1, 0x80000)
    lo, hi = DATA[0] - WRAM, DATA[1] - WRAM
    wram[lo:hi] = r.randbytes(hi - lo)
    vdp1[:VDP1_DATA] = r.randbytes(VDP1_DATA)
    hwram[:] = wram
    hvdp1[:] = vdp1
    vals = [value(a, r) for a in args]

    state = {"calls": []}
    keep = (ctypes.c_char * len(hwram)).from_buffer(hwram), (ctypes.c_char * len(hvdp1)).from_buffer(hvdp1)
    ctypes.c_void_p.in_dll(lib, "g_wram").value = ctypes.addressof(keep[0])
    ctypes.c_void_p.in_dll(lib, "g_vdp1").value = ctypes.addressof(keep[1])
    hook = hook_for(host, state)
    ctypes.c_void_p.in_dll(lib, "g_call_hook").value = ctypes.cast(hook, ctypes.c_void_p).value
    ctypes.c_int.in_dll(lib, "g_fault").value = 0
    fn = getattr(lib, name)
    fn.restype = ctypes.c_int32
    fn.argtypes = [ctypes.c_int32] * len(vals)
    signed = [v - (1 << 32) if v >= 1 << 31 else v for v in vals]
    got = fn(*signed)
    fault = ctypes.c_int.in_dll(lib, "g_fault").value or "error" in state

    regs = {"r%d" % (4 + i): v for i, v in enumerate(vals)}
    original_fault = False
    want = 0
    try:
        want = cpu.call(int(name[1:], 16), **regs)
    except (sh2emu.MemoryError_, RuntimeError):         # touched memory this check does not model, or ran on
        original_fault = True
    del keep

    if fault and original_fault:
        return vals, [], True
    problems = []
    if fault != original_fault:
        problems.append("%s touched memory the check does not model; %s did not"
                        % (("the host build", "the game's code") if fault else ("the game's code", "the host build")))
    if name in CALLS and state["calls"] != CALLS[name]:
        problems.append("called %s, expected %s" % ([hex(a) for a in state["calls"]],
                                                  [hex(a) for a in CALLS.get(name, [])]))
    if returns and (got & 0xFFFFFFFF) != want:
        problems.append("returned %08X, the game's code %08X" % (got & 0xFFFFFFFF, want))
    keep_to = STACK - WRAM
    for label, mine, theirs, base in (("work RAM", bytes(hwram[:keep_to]), bytes(wram[:keep_to]), WRAM),
                                      ("VDP1", bytes(hvdp1), bytes(vdp1), VDP1)):
        if mine != theirs:
            i = next(i for i in range(len(mine)) if mine[i] != theirs[i])
            problems.append("%s differs first at %08X: host %02X, game %02X" % (label, base + i, mine[i], theirs[i]))
    return vals, problems, False


def run(lib, name, spec, trials, seed):
    """The trials that differ, as (arguments, problems), and how many ran to the end, for one function."""
    args, returns = spec
    r = random.Random("%s:%d" % (name, seed))
    fails = []
    ran = 0
    for _ in range(trials):
        vals, problems, skipped = trial(lib, name, args, returns, r)
        ran += not skipped
        if problems:
            fails.append((vals, problems))
    return fails, ran


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--trials", type=int, default=300)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--source", default=os.path.join(HERE, "krnl.c"), help="a C file to check in place of krnl.c")
    ap.add_argument("names", nargs="*")
    a = ap.parse_args()
    lib = build(a.source)
    sigs = gen.signatures(a.source)
    bad = 0
    for name in [n for n in (a.names or ["f%08X" % x for x in sorted(sigs)])]:
        spec = SPEC.get(name) or default_spec(sigs[int(name[1:], 16)])
        fails, ran = run(lib, name, spec, a.trials, a.seed)
        status = ("ok" if ran == a.trials else "ok, %d of %d trials ran" % (ran, a.trials)) if not fails \
            else "%d of %d trials differ" % (len(fails), a.trials)
        print("%s  %s" % (name, status))
        for vals, problems in fails[:2]:
            print("   args %s: %s" % ([hex(v) for v in vals], "; ".join(problems)))
        bad += bool(fails)
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
