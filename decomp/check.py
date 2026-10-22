"""Runs each decompiled kernel function (src/) against the game's own code.

    python decomp/check.py [--trials N] [--seed S] [FUNCTION ...]

The original is 0KRNL.BIN, run by the SH-2 interpreter in saturn-recomp. The decompiled C is built
for the host with DECOMP_HOST and run on a copy of the same memory. Each trial gives both the same
random arguments and the same memory, random or dumped from a route, with the values cases.py plants.
It then compares the return value, if the function has one, and every byte of memory afterwards.
"""
import argparse
import ctypes
import json
import os
import random
import runpy
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
sys.path.insert(0, HERE)
import cases  # noqa: E402
import gen  # noqa: E402
import machine  # noqa: E402
import status  # noqa: E402
from saturnrecomp import sh2emu  # noqa: E402

BASE = 0x06006000
CALL_HOOK = ctypes.CFUNCTYPE(ctypes.c_uint32, ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32), ctypes.c_int)
# The game's code a function calls, in order. Memory alone cannot tell two calls apart when their
# stores do not overlap.
CALLS = {
    "f060A5EEC": [0x060A5F2E, 0x060A5F22],
}
CONDITIONAL = ("bt", "bf", "bt/s", "bf/s")
# How a parameter or result of each type crosses into the host build: at its own width, so a narrow
# parameter drops the upper bits of the register as the swap's wrapper does.
C_TYPES = {"int": ctypes.c_int32, "unsigned int": ctypes.c_uint32, "uint32_t": ctypes.c_uint32,
           "short": ctypes.c_int16, "unsigned short": ctypes.c_uint16, "char": ctypes.c_int8,
           "signed char": ctypes.c_int8, "unsigned char": ctypes.c_uint8}
# Values where a comparison, a width or a sign changes, which random numbers rarely land on.
EDGES = (0, 1, 2, 0x7F, 0x80, 0xFF, 0x100, 0x7FFF, 0x8000, 0xFFFF, 0x10000, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF,
         0xFFFFFFFE, 0xFFFFFF80, 0xFFFF8000)
KRNL = os.path.join(ROOT, "build", "extract", "BOMSS", "0KRNL.BIN")
TABLE_MAX = 0x100                # bytes of a jump table code_runs keeps, at most


class Counting(sh2emu.CPU):
    """The interpreter, also counting the SH2_POLLs the generated code would make, over the recompiler's
    own function boundaries."""
    _image = None
    _bodies: dict[int, set[int]] = {}
    _code: dict[int, set[int]] | None = None
    _jumps: set[int] | None = None
    seen: set[tuple[int, bool]] | None = None     # (pc, taken) for each conditional branch of the called function's own code

    def call(self, entry: int, max_steps: int = 10_000_000, **regs: int) -> int:
        self.code, self.outer = self._body(entry), []
        self.own = self.code
        return super().call(entry, max_steps, **regs)

    def step(self) -> None:
        pc = self.pc
        ins = self.fetch(pc)
        super().step()
        op = ins.op
        if self.seen is not None and op in CONDITIONAL and pc in self.own and self.code is self.own:
            self.seen.add((pc, self.pc != pc + (4 if ins.delay else 2)))
        if op in ("bsr", "jsr", "bsrf"):
            self.polls += 1
            self.outer.append(self.code)
            self.code = self._body(self.pc)
        elif op in ("rts", "rte"):
            self.code = self.outer.pop() if self.outer else self.code
        elif op in ("ldc", "ldc.l") and ins.fmt.endswith("sr"):
            self.polls += 1
        elif op in ("braf", "jmp"):
            self.polls += pc in self._polling()
            if self.pc not in self.code:
                self.code = self._body(self.pc)
        elif op == "bra" or op in CONDITIONAL and self.pc != pc + (4 if ins.delay else 2):
            if self.pc not in self.code:
                self.code = self._body(self.pc)
            elif self.pc <= pc:
                self.polls += 1

    @classmethod
    def _body(cls, entry: int) -> set[int]:
        if cls._code is None:
            cls._code = status.function_code()
        if entry in cls._code:
            return cls._code[entry]
        if entry not in cls._bodies:
            if cls._image is None:
                cls._image = status.krnl_image()
            cls._bodies[entry] = {ins.pc for ins in status.body(cls._image, entry)}
        return cls._bodies[entry]

    @classmethod
    def _polling(cls) -> set[int]:
        if cls._jumps is None:
            cls._jumps = status.polling_jumps()
        return cls._jumps


def branches(entry: int) -> list[int]:
    """The conditional branches of the function's own code."""
    image = status.krnl_image()
    return [at for at in Counting._body(entry) if image.contains(at) and image.insn(at).op in CONDITIONAL]


def build(sources: list[str] | None = None) -> ctypes.CDLL:
    with tempfile.TemporaryDirectory(prefix="decomp-") as where:
        out = os.path.join(where, "libdecomp.so")
        subprocess.check_call(["clang", "-std=gnu11", "-O1", "-Wall", "-shared", "-fPIC", "-fwrapv", "-DDECOMP_HOST",
                               "-I", HERE, "-o", out, *(sources or status.sources()), os.path.join(HERE, "host_mem.c"),
                               os.path.join(HERE, "divide.c")])
        return ctypes.CDLL(out)


def code_runs() -> list[list[int]]:
    """The (start, end) offsets into 0KRNL.BIN of every function's instructions and the literals they load,
    which randomising the image must leave alone. Cached in build/decomp, as walking every function is slow."""
    cache = os.path.join(ROOT, "build", "decomp", "code-runs.json")
    stamp = [os.path.getmtime(KRNL), os.path.getmtime(status.TABLE), TABLE_MAX]
    try:
        with open(cache, encoding="utf-8") as f:
            saved = json.load(f)
        if saved["stamp"] == stamp:
            return saved["runs"]
    except (OSError, ValueError, KeyError):
        pass
    image = status.krnl_image()
    used = set()
    tables = set()
    for row in status.previous().values():
        if row.module != "KRNL":
            continue
        for ins in status.body(image, row.address):
            used.update((ins.pc, ins.pc + 1))
            if ins.target is not None and ins.op in ("mov.w", "mov.l", "mova"):
                used.update(range(ins.target, ins.target + (2 if ins.op == "mov.w" else 4)))
            if ins.op == "mova":
                tables.add(ins.target)
    for start in tables:            # a jump table runs on to the next instruction, as SHC places it
        end = start + 4
        while end - start < TABLE_MAX and end not in used:
            end += 1
        used.update(range(start, end))
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


def counting(cpu: sh2emu.CPU) -> Counting:
    cpu.__class__ = Counting
    cpu.polls = 0
    return cpu


def default_spec(sig: gen.Signature) -> tuple[list[tuple], bool, list[tuple]]:
    """Random arguments for each parameter of a definition: a pointer for a reference (uint32_t on the host),
    and for a number anything a register can hold, whatever the declared width, since a caller may leave the upper bits set."""
    unknown = [t for t in sig.params + [sig.returns] if t not in C_TYPES and t != "void"]
    if unknown:
        raise SystemExit("%s: no host type for %s; add it to C_TYPES" % (sig.name, ", ".join(unknown)))
    return [cases.ptr(0x060C0000, 0x400) if t == "uint32_t" else ("any",) for t in sig.params], sig.returns != "void", []


def hook_for(cpu, state, junk: list[int], lib: ctypes.CDLL):
    """What the host build's g_call runs: the game's function on the interpreter that holds the host
    build's memory. Registers r8 to r15 and pr come back unchanged, as the runtime's swap does. r0 to r7
    that the call does not pass hold junk, so a callee that reads one the C did not pass disagrees with
    the game, whose registers hold something else."""
    @CALL_HOOK
    def hook(addr, args, n):
        keep = (cpu.r[8:], cpu.pr)
        sp = ctypes.c_uint32.in_dll(lib, "g_sp").value
        try:
            if n > 4:
                sp -= 4 * (n - 4)
                for i in range(4, n):
                    cpu.mem.write(sp + 4 * (i - 4), 4, args[i])
            cpu.r[15] = sp
            cpu.r[:8] = junk
            if n < 0:                               # one of SHC's routines, given r0 up
                return cpu.call(addr, **{"r%d" % i: args[i] for i in range(-n)})
            return cpu.call(addr, **{"r%d" % (4 + i): args[i] for i in range(min(n, 4))})
        except Exception as e:                      # an access outside the mapped memory, or no return
            state["error"] = str(e)
            return 0
        finally:
            cpu.r[8:], cpu.pr = keep
            state["calls"].append(addr)
    return hook


def run(lib: ctypes.CDLL, name: str, spec: tuple[list[tuple], bool, list[tuple]], trials: int, seed: int,
        sig: gen.Signature | None = None, seen: set[tuple[int, bool]] | None = None) -> tuple[list, int]:
    """The trials that differ, as (arguments, problems), and how many ran to the end, for one function.
    Without its signature, every parameter and the result pass as an int. `seen` becomes Counting.seen
    in every trial."""
    args, returns, plants = spec
    r = random.Random("%s:%d" % (name, seed))
    fails = []
    ran = 0
    for _ in range(trials):
        vals, problems, skipped = trial(lib, name, args, returns, r, sig, seen, plants)
        ran += not skipped
        if problems:
            fails.append((vals, problems))
    return fails, ran


def spec_for(sig: gen.Signature) -> tuple[list[tuple], bool, list[tuple]]:
    cases.load()
    return cases.SPEC.get(sig.name) or default_spec(sig)


def trial(lib: ctypes.CDLL, name: str, args: list[tuple], returns: bool, r: random.Random,
          sig: gen.Signature | None = None, seen: set[tuple[int, bool]] | None = None,
          plants: list[tuple] = ()) -> tuple[list[int], list[str], bool]:
    cpu = counting(sh2emu.load(KRNL, BASE))     # the game's own function
    cpu.seen = seen
    host = counting(sh2emu.load(KRNL, BASE))    # the memory the host build runs on, and its callees
    machine.fill(cpu, r, BASE, code_runs(), plants)
    machine.copy(cpu, host)
    vals = [value(a, r) for a in args]

    state = {"calls": []}
    keep = machine.point(lib, host)
    hook = hook_for(host, state, [value(("any",), r) & 0xFFFFFFFF for _ in range(8)], lib)
    ctypes.c_uint32.in_dll(lib, "g_sp").value = host.r[15]
    ctypes.c_void_p.in_dll(lib, "g_call_hook").value = ctypes.cast(hook, ctypes.c_void_p).value
    ctypes.c_int.in_dll(lib, "g_fault").value = 0
    ctypes.c_int.in_dll(lib, "g_polls").value = 0
    fn = getattr(lib, name)
    fn.restype = C_TYPES.get(sig.returns if sig else "int", ctypes.c_int32)
    fn.argtypes = [C_TYPES[t] for t in sig.params] if sig else [ctypes.c_int32] * len(vals)
    got = fn(*[t(v).value for t, v in zip(fn.argtypes, vals)])
    polls = ctypes.c_int.in_dll(lib, "g_polls").value + host.polls
    fault = ctypes.c_int.in_dll(lib, "g_fault").value or "error" in state

    regs = {"r%d" % i: value(("any",), r) for i in range(8)} | {"r%d" % (4 + i): v for i, v in enumerate(vals)}
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
    problems += machine.differences(host, cpu)
    return vals, problems, False


def value(kind, r):
    if kind[0] == "any":
        # whatever a parameter might hold: a small count, a negative, a pointer into the data, anything
        return value(r.choice([("int", 0, 40), ("int", -40, 0), cases.ptr(0x060C0000, 0x400), cases.ptr(0x060B0000, 0x40000),
                               ("int", -(1 << 31), (1 << 31) - 1), ("pick", EDGES)]), r)
    if kind[0] == "pick":
        return r.choice(kind[1])
    if kind[0] == "int":
        return r.randint(kind[1], kind[2])
    lo, span, align = kind[1:]
    return lo + r.randrange(0, span // align) * align


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--trials", type=int, default=300)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--source", nargs="+", help="C files to check in place of src/")
    ap.add_argument("--cases", nargs="+", default=[], help="files of case() calls to use as well as cases.py's")
    ap.add_argument("names", nargs="*")
    a = ap.parse_args()
    for path in a.cases:
        runpy.run_path(path)
    lib = build(a.source)
    sigs = gen.signatures(a.source)
    bad = 0
    for name in [n for n in (a.names or ["f%08X" % x for x in sorted(sigs)])]:
        spec = spec_for(sigs[int(name[1:], 16)])
        seen = set()
        fails, ran = run(lib, name, spec, a.trials, a.seed, sigs[int(name[1:], 16)], seen)
        status = ("ok" if ran == a.trials else "ok, %d of %d trials ran" % (ran, a.trials)) if not fails \
            else "%d of %d trials differ" % (len(fails), a.trials)
        outcomes = 2 * len(branches(int(name[1:], 16)))
        missed = "; %d of %d branch outcomes never reached" % (outcomes - len(seen), outcomes) if len(seen) < outcomes else ""
        print("%s  %s%s" % (name, status, missed))
        for vals, problems in fails[:2]:
            print("   args %s: %s" % ([hex(v) for v in vals], "; ".join(problems)))
        bad += bool(fails)
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
