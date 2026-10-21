"""Runs each decompiled kernel function (src/) against the game's own code.

    python decomp/check.py [--trials N] [--seed S] [FUNCTION ...]

The original is 0KRNL.BIN, run by the SH-2 interpreter in saturn-recomp. The decompiled C is built
for the host with DECOMP_HOST and run on a copy of the same memory. Each trial gives both the same
random arguments and the same random data, then compares the return value, if the function has one,
and every byte of work RAM and VDP1 VRAM afterwards.
"""
import argparse
import ctypes
import json
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
import status  # noqa: E402
from saturnrecomp import sh2emu  # noqa: E402

KRNL = os.path.join(ROOT, "build", "extract", "BOMSS", "0KRNL.BIN")
BASE = 0x06006000
WRAM, WRAML, VDP1 = 0x06000000, 0x00200000, 0x05D00000
# The game's functions spill registers onto the stack, which the host build has no counterpart for.
STACK = 0x06100000 - 0x1000
# Random data covers the tables the functions read, up to the stack. Half the trials also randomise the
# variables inside the image, around the code.
DATA = (0x060B0000, STACK)
VDP1_DATA = 0x100


# How a parameter or result of each type crosses into the host build: at its own width, so a narrow
# parameter drops the upper bits of the register as the swap's wrapper does.
C_TYPES = {"int": ctypes.c_int32, "unsigned int": ctypes.c_uint32, "uint32_t": ctypes.c_uint32,
           "short": ctypes.c_int16, "unsigned short": ctypes.c_uint16, "char": ctypes.c_int8,
           "signed char": ctypes.c_int8, "unsigned char": ctypes.c_uint8}
CALL_HOOK = ctypes.CFUNCTYPE(ctypes.c_uint32, ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32), ctypes.c_int)


# Values where a comparison, a width or a sign changes, which random numbers rarely land on.
EDGES = [0, 1, 2, 0x7F, 0x80, 0xFF, 0x100, 0x7FFF, 0x8000, 0xFFFF, 0x10000, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF,
         0xFFFFFFFE, 0xFFFFFF80, 0xFFFF8000]


class Counting(sh2emu.CPU):
    """The interpreter, also counting the places the recompiled game advances time: a call, a branch back
    within the function that is running, and an ldc to sr. A branch out of the function is a tail call
    and counts nothing. Those are the generator's rules for SH2_POLL, over its own function boundaries."""
    _image = None
    _bodies: dict = {}
    _code: dict | None = None

    def call(self, entry, max_steps=10_000_000, **regs):
        self.code, self.outer = self._body(entry), []
        return super().call(entry, max_steps, **regs)

    def step(self):
        pc = self.pc
        ins = self.fetch(pc)
        super().step()
        op = ins.op
        if op in ("bsr", "jsr", "bsrf"):
            self.polls += 1
            self.outer.append(self.code)
            self.code = self._body(self.pc)
        elif op in ("rts", "rte"):
            self.code = self.outer.pop() if self.outer else self.code
        elif op in ("ldc", "ldc.l") and ins.fmt.endswith("sr"):
            self.polls += 1
        elif op in ("bt", "bf", "bt/s", "bf/s", "bra", "braf", "jmp") and self.pc != pc + (4 if ins.delay else 2):
            if self.pc not in self.code:
                self.code = self._body(self.pc)
            elif self.pc <= pc:
                self.polls += 1

    @classmethod
    def _body(cls, entry):
        if cls._code is None:
            cls._code = status.function_code()
        if entry in cls._code:
            return cls._code[entry]
        if entry not in cls._bodies:
            if cls._image is None:
                cls._image = status.krnl_image()
            cls._bodies[entry] = {ins.pc for ins in status.body(cls._image, entry)}
        return cls._bodies[entry]




def counting(cpu):
    cpu.__class__ = Counting
    cpu.polls = 0
    return cpu


def ptr(lo, span, align=4):
    return ("ptr", lo, span, align)


def rng_int(lo, hi):
    return ("int", lo, hi)


# Arguments a function needs narrower than its type allows: name: (arguments, returns a value).
# Any other function is given random arguments of the types it declares.
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
    """Random arguments for each parameter of a definition: a pointer for a reference, and for a number
    anything a register can hold, whatever the declared width, since a caller may leave the upper bits set."""
    unknown = [t for t in sig.params + [sig.returns] if t not in C_TYPES and t != "void"]
    if unknown:
        raise SystemExit("%s: no default argument for %s; add it to SPEC" % (sig.name, ", ".join(unknown)))
    return [ptr(0x060C0000, 0x400) if t == "uint32_t" else ("any",) for t in sig.params], sig.returns != "void"


def code_runs():
    """The (start, end) offsets into 0KRNL.BIN of every function's instructions and the literals they load,
    which randomising the image must leave alone. Cached beside the extracted disc, as walking every
    function takes a few seconds."""
    cache = os.path.join(ROOT, "build", "decomp", "code-runs.json")
    stamp = [os.path.getmtime(KRNL), os.path.getmtime(status.TABLE)]
    try:
        with open(cache, encoding="utf-8") as f:
            saved = json.load(f)
        if saved["stamp"] == stamp:
            return saved["runs"]
    except (OSError, ValueError, KeyError):
        pass
    image = status.krnl_image()
    used = set()
    for row in status.previous().values():
        if row.module != "KRNL":
            continue
        for ins in status.body(image, row.address):
            used.update((ins.pc, ins.pc + 1))
            if ins.target is not None and ins.op in ("mov.w", "mov.l", "mova"):
                used.update(range(ins.target, ins.target + (2 if ins.op == "mov.w" else 4)))
    runs = []
    for at in sorted(a - BASE for a in used if a >= BASE):
        if runs and runs[-1][1] == at:
            runs[-1][1] = at + 1
        else:
            runs.append([at, at + 1])
    os.makedirs(os.path.dirname(cache), exist_ok=True)
    with open(cache, "w", encoding="utf-8") as f:
        json.dump({"stamp": stamp, "runs": runs}, f)
    return runs


def build(sources=None):
    out = os.path.join(tempfile.mkdtemp(prefix="decomp-"), "libdecomp.so")
    subprocess.check_call(["clang", "-std=gnu11", "-O1", "-Wall", "-shared", "-fPIC", "-fwrapv", "-DDECOMP_HOST",
                           "-I", HERE, "-o", out, *(sources or status.sources()), os.path.join(HERE, "host_mem.c")])
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


def trial(lib, name, args, returns, r, sig=None):
    cpu = counting(sh2emu.load(KRNL, BASE))     # the game's own function
    host = counting(sh2emu.load(KRNL, BASE))    # the memory the host build runs on, and its callees
    wram, wraml = cpu.mem.regions[0][2], cpu.mem.regions[1][2]
    vdp1 = cpu.mem.add(VDP1, 0x80000)
    hwram, hwraml = host.mem.regions[0][2], host.mem.regions[1][2]
    hvdp1 = host.mem.add(VDP1, 0x80000)
    lo, hi = DATA[0] - WRAM, DATA[1] - WRAM
    if r.random() < 0.5:
        lo = BASE - WRAM
    image = bytes(wram[BASE - WRAM:BASE - WRAM + os.path.getsize(KRNL)])
    wram[lo:hi] = r.randbytes(hi - lo)
    for start, end in code_runs():
        wram[BASE - WRAM + start:BASE - WRAM + end] = image[start:end]
    vdp1[:VDP1_DATA] = r.randbytes(VDP1_DATA)
    hwram[:] = wram
    hvdp1[:] = vdp1
    vals = [value(a, r) for a in args]

    state = {"calls": []}
    keep = [(ctypes.c_char * len(b)).from_buffer(b) for b in (hwram, hwraml, hvdp1)]
    for symbol, buf in zip(("g_wram", "g_wraml", "g_vdp1"), keep):
        ctypes.c_void_p.in_dll(lib, symbol).value = ctypes.addressof(buf)
    hook = hook_for(host, state)
    ctypes.c_void_p.in_dll(lib, "g_call_hook").value = ctypes.cast(hook, ctypes.c_void_p).value
    ctypes.c_int.in_dll(lib, "g_fault").value = 0
    ctypes.c_int.in_dll(lib, "g_polls").value = 0
    fn = getattr(lib, name)
    fn.restype = C_TYPES.get(sig.returns if sig else "int", ctypes.c_int32)
    fn.argtypes = [C_TYPES[t] for t in sig.params] if sig else [ctypes.c_int32] * len(vals)
    got = fn(*[t(v).value for t, v in zip(fn.argtypes, vals)])
    polls = ctypes.c_int.in_dll(lib, "g_polls").value + host.polls
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
    if polls != cpu.polls:
        problems.append("advanced time %d times, the game's code %d" % (polls, cpu.polls))
    if name in CALLS and state["calls"] != CALLS[name]:
        problems.append("called %s, expected %s" % ([hex(a) for a in state["calls"]],
                                                  [hex(a) for a in CALLS.get(name, [])]))
    if returns and (got & 0xFFFFFFFF) != want:
        problems.append("returned %08X, the game's code %08X" % (got & 0xFFFFFFFF, want))
    keep_to = STACK - WRAM
    for label, mine, theirs, base in (("work RAM", bytes(hwram[:keep_to]), bytes(wram[:keep_to]), WRAM),
                                      ("work RAM-L", bytes(hwraml), bytes(wraml), WRAML),
                                      ("VDP1", bytes(hvdp1), bytes(vdp1), VDP1)):
        if mine != theirs:
            i = next(i for i in range(len(mine)) if mine[i] != theirs[i])
            problems.append("%s differs first at %08X: host %02X, game %02X" % (label, base + i, mine[i], theirs[i]))
    return vals, problems, False


def run(lib, name, spec, trials, seed, sig=None):
    """The trials that differ, as (arguments, problems), and how many ran to the end, for one function.
    Without its signature, every parameter and the result pass as an int."""
    args, returns = spec
    r = random.Random("%s:%d" % (name, seed))
    fails = []
    ran = 0
    for _ in range(trials):
        vals, problems, skipped = trial(lib, name, args, returns, r, sig)
        ran += not skipped
        if problems:
            fails.append((vals, problems))
    return fails, ran


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--trials", type=int, default=300)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--source", nargs="+", help="C files to check in place of src/")
    ap.add_argument("names", nargs="*")
    a = ap.parse_args()
    lib = build(a.source)
    sigs = gen.signatures(a.source)
    bad = 0
    for name in [n for n in (a.names or ["f%08X" % x for x in sorted(sigs)])]:
        spec = SPEC.get(name) or default_spec(sigs[int(name[1:], 16)])
        fails, ran = run(lib, name, spec, a.trials, a.seed, sigs[int(name[1:], 16)])
        status = ("ok" if ran == a.trials else "ok, %d of %d trials ran" % (ran, a.trials)) if not fails \
            else "%d of %d trials differ" % (len(fails), a.trials)
        print("%s  %s" % (name, status))
        for vals, problems in fails[:2]:
            print("   args %s: %s" % ([hex(v) for v in vals], "; ".join(problems)))
        bad += bool(fails)
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
