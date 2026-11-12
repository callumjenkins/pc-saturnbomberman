"""The per-function status table, decomp/status.tsv.

    python decomp/status.py            # rewrite the table from the build, the coverage files and src/
    python decomp/status.py --summary  # counts by module and state

One row per function the recompile found. Everything but `state` and `name` is read from the build, so
rerunning keeps the table current. A state set by hand in the old table (`dead`) and every name carry
over.
"""
import argparse
import collections
import glob
import json
import os
import re
import sys
from dataclasses import dataclass

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "saturn-recomp", "src"))
import modules  # noqa: E402
from saturnrecomp import build as recomp_build, config, sh2  # noqa: E402
from saturnrecomp.analysis import resume  # noqa: E402
from saturnrecomp.recomp import __main__ as recomp_main, discover, emit  # noqa: E402

COLUMNS = ("module", "address", "insns", "calls", "leaf", "executed", "yields", "hooked", "piece", "state", "name")
COVERAGE = ("build/test/*/coverage.txt", "build/run/*/coverage.txt", "build/play/*/replay/coverage.txt")
HERE = os.path.dirname(os.path.abspath(__file__))
KRNL = ("KRNL", "build/extract/BOMSS/0KRNL.BIN", 0x06006000)
ROOT = os.path.dirname(HERE)
SRC = os.path.join(HERE, "src")
STATES = ("todo", "drafted", "swapped", "dead")
TABLE = os.path.join(HERE, "status.tsv")
_BRANCHES = ("bt", "bf", "bt/s", "bf/s", "bra")
_CALL = re.compile(r"\b(?:bsr|jsr|bsrf)\b")
_DEFINED = re.compile(r"^[^\s#/*].*?\bf([0-9A-F]{8})\(", re.MULTILINE)
_ENDS = ("bra", "braf", "jmp", "rts", "rte")
_REPLACE = re.compile(r'\[\[replace\]\]\s*\nmodule = "(\w+)"\s*\nat = (0x[0-9A-Fa-f]+)')


@dataclass
class Row:
    module: str
    address: int
    insns: int
    calls: int
    executed: bool
    state: str = "todo"
    name: str = ""
    yields: bool = False                    # a task can park inside it, so host code cannot stand in for it
    hooked: bool = False                    # its code holds an address game.toml hooks, which C never runs
    piece: bool = False                     # it starts inside another function: a resume point, which that function's C covers

    @property
    def leaf(self) -> bool:
        return self.calls == 0

    def fields(self) -> list[str]:
        return [self.module, "%08X" % self.address, str(self.insns), str(self.calls), "yes" if self.leaf else "no",
                "yes" if self.executed else "no", "yes" if self.yields else "no",
                "yes" if self.hooked else "no", "yes" if self.piece else "no", self.state, self.name]


def body(image: sh2.Image, address: int) -> list[sh2.Insn]:
    """The instructions reachable from an entry, following every branch, a tail branch into another
    function included, in address order. A literal pool between two returns is never reached, and a jump
    through a register is not followed."""
    found: dict[int, sh2.Insn] = {}
    pending = [address]
    while pending:
        at = pending.pop()
        if at in found or not image.contains(at):
            continue
        ins = found[at] = image.insn(at)
        if ins.delay:
            found.setdefault(at + 2, image.insn(at + 2))
        if ins.op in _BRANCHES:
            pending.append(ins.target)
        if ins.op not in _ENDS:
            pending.append(at + 4 if ins.delay else at + 2)
    return [found[at] for at in sorted(found)]


def build_table(root: str = ROOT) -> list[Row]:
    ran = executed(root)
    swapped = replaced(os.path.join(root, "game.toml"))     # only to start a table; gen.py writes them after
    written = {name: drafted(sources(modules.load(name).src)) for name in modules.SCOPE}
    old = previous(os.path.join(HERE, "status.tsv"))
    rows = functions(root)
    found = {(row.module, row.address) for row in rows}
    for key in sorted((set(old) or swapped) - found):       # the map leaves out a replaced function
        was = old.get(key)
        insns, calls = (was.insns, was.calls) if was else walk(root, key[1], key[0])
        rows.append(Row(key[0], key[1], insns, calls, False))
    rows.sort(key=lambda row: (row.module, row.address))
    parked = yielding(root)
    inside = {name: pieces(root, name) for name in modules.SCOPE}
    caught = {name: hooked(root, name) for name in modules.SCOPE}
    for row in rows:
        key = (row.module, row.address)
        row.executed = key in ran
        row.yields = row.module == KRNL[0] and row.address in parked
        row.hooked = row.address in caught.get(row.module, ())
        row.piece = row.address in inside.get(row.module, ())
        was = old.get(key)
        row.name = was.name if was else ""
        if was and was.state in ("dead", "swapped"):
            row.state = was.state
        elif not old and key in swapped:
            row.state = "swapped"
        elif row.address in written.get(row.module, ()):
            row.state = "drafted"
    return rows


def drafted(paths: list[str] | None = None) -> set[int]:
    """The addresses the decompiled C defines a function for."""
    found: set[int] = set()
    for path in sources() if paths is None else paths:
        with open(path, encoding="utf-8") as f:
            found |= {int(m.group(1), 16) for m in _DEFINED.finditer(f.read())}
    return found


def executed(root: str = ROOT) -> set[tuple[str, int]]:
    """The (module, address) pairs a coverage file reports as run."""
    seen: set[tuple[str, int]] = set()
    for pattern in COVERAGE:
        for path in glob.glob(os.path.join(root, pattern)):
            with open(path, encoding="utf-8") as f:
                for line in f:
                    parts = line.split()
                    if len(parts) == 4 and parts[3] == "1":
                        seen.add((parts[0], int(parts[1], 16)))
    return seen


def function_code(root: str = ROOT, module: str | None = None) -> dict[int, set[int]]:
    """{entry: its instruction addresses} for a module (the one DECOMP_MODULE names), as the recompiler finds
    them from the build's seeds."""
    return {int(k): set(v) for k, v in _discovery(root, module or modules.current().name)["code"].items()}


def functions(root: str = ROOT) -> list[Row]:
    """A row per function from the recompile's map, with the calls its generated code makes."""
    recomp = os.path.join(root, "build", "recomp")
    rows: list[Row] = []
    for path in sorted(glob.glob(os.path.join(recomp, "map", "*.tsv"))):
        module = os.path.basename(path)[:-4]
        sources: dict[str, list[str]] = {}
        insns: dict[int, int] = collections.Counter()
        calls: dict[int, int] = collections.Counter()
        with open(path, encoding="utf-8") as f:
            for line in f:
                if line.startswith("#"):
                    continue
                _, func, _, name, number = line.split()
                if name not in sources:
                    with open(os.path.join(recomp, name), encoding="utf-8") as src:
                        sources[name] = src.read().splitlines()
                entry = int(func, 16)
                insns[entry] += 1
                calls[entry] += bool(_CALL.search(sources[name][int(number) - 1]))
        rows.extend(Row(module, entry, count, calls[entry], False) for entry, count in sorted(insns.items()))
    return rows


def holding(code: dict[int, set[int]], addresses: set[int]) -> set[int]:
    return {entry for entry, insns in code.items() if insns & addresses}


def hooked(root: str = ROOT, module: str | None = None) -> set[int]:
    """The functions of a module whose code holds an address game.toml hooks."""
    name = module or modules.current().name
    hooks = set(config.load(os.path.join(root, "game.toml")).hooks.get(name, []))
    return holding(function_code(root, name), hooks)


def image(root: str = ROOT, module: str | None = None) -> sh2.Image:
    found = modules.load(module or modules.current().name, root)
    with open(found.path, "rb") as f:
        return sh2.Image(f.read(), found.base)


def own(image: sh2.Image, address: int, code: set[int] | None) -> list[sh2.Insn]:
    """The function's own instructions with their delay slots: its code by the recompiler's boundaries,
    or, without them, everything reachable."""
    if code is None:
        return body(image, address)
    found = {at: image.insn(at) for at in code}
    for at, ins in list(found.items()):
        if ins.delay:
            found.setdefault(at + 2, image.insn(at + 2))
    return [found[at] for at in sorted(found)]


def jump_kinds(root: str = ROOT) -> dict[int, str]:
    """How the recompiler resolves each jmp and braf of the module: `literal` (a tail call to a known address),
    `pointer` or `unresolved` (a tail call through a register), or `switch` (a jump table)."""
    return {int(a): kind for a, kind in _discovery(root, modules.current().name)["jumps"].items()}


def jump_targets(root: str = ROOT) -> dict[int, list[int]]:
    """The target of each entry of each `switch` jump of the module, in table order."""
    return {int(a): targets for a, targets in _discovery(root, modules.current().name)["switches"].items()}


def polling_jumps(root: str = ROOT) -> set[int]:
    """The jmp and braf instructions of the module whose generated code advances time before it jumps, wherever the
    jump then goes: one that may go back within its function."""
    return set(_discovery(root, modules.current().name)["polling"])


def pieces(root: str = ROOT, module: str | None = None) -> set[int]:
    """The entries inside another function's code: the resume points the recompile seeds in the middle of
    a function, whose code that function holds too."""
    code = function_code(root, module)
    inside = {at for entry, instructions in code.items() for at in instructions if at != entry}
    return {entry for entry in code if entry in inside}


def previous(path: str = TABLE) -> dict[tuple[str, int], Row]:
    """The rows of an existing table, keyed by module and address."""
    if not os.path.exists(path):
        return {}
    old = {}
    with open(path, encoding="utf-8") as f:
        header = next(f).rstrip("\n").split("\t")
        for line in f:
            fields = dict(zip(header, line.rstrip("\n").split("\t")))
            address = int(fields["address"], 16)
            old[(fields["module"], address)] = Row(
                fields["module"], address, int(fields["insns"]), int(fields["calls"]), fields["executed"] == "yes",
                fields["state"], fields["name"], fields.get("yields") == "yes", fields.get("hooked") == "yes",
                fields.get("piece") == "yes")
    return old


def replaced(path: str = os.path.join(ROOT, "game.toml")) -> set[tuple[str, int]]:
    """The (module, address) pairs game.toml replaces."""
    with open(path, encoding="utf-8") as f:
        return {(m.group(1), int(m.group(2), 16)) for m in _REPLACE.finditer(f.read())}


def source_for(address: int, folder: str | None = None) -> str:
    """The file a function at this address belongs in, in the module's folder of C: one per 0x10000 of address,
    so workers given different ranges edit different files."""
    current = modules.current()
    return os.path.join(folder or current.src, "%s_%04X.c" % (current.name.lower(), address >> 16))


def sources(folder: str | None = None) -> list[str]:
    """The decompiled C of the module (DECOMP_MODULE), every file of its folder."""
    return sorted(glob.glob(os.path.join(folder or modules.current().src, "*.c")))


def summary(rows: list[Row]) -> str:
    counts: dict[str, collections.Counter] = collections.defaultdict(collections.Counter)
    for row in rows:
        counts[row.module][row.state] += 1
        counts[row.module]["functions"] += 1
        counts[row.module]["leaves"] += row.leaf
        counts[row.module]["executed"] += row.executed
        counts[row.module]["yields"] += row.yields
    header = "%-6s %9s %7s %8s %7s" % ("", "functions", "leaves", "executed", "yields") + "".join("%9s" % s for s in STATES)
    lines = [header]
    for module in sorted(counts):
        c = counts[module]
        lines.append("%-6s %9d %7d %8d %7d" % (module, c["functions"], c["leaves"], c["executed"], c["yields"])
                     + "".join("%9d" % c[s] for s in STATES))
    return "\n".join(lines)


def walk(root: str, address: int, module: str) -> tuple[int, int]:
    """Instructions and calls of a function. A replaced function has no rows in the map, so this
    counts one that was never in the table."""
    insns = own(image(root, module), address, function_code(root, module).get(address))
    return len(insns), sum(ins.op in ("bsr", "jsr", "bsrf") for ins in insns)


def write_table(rows: list[Row], path: str = TABLE) -> None:
    with open(path, "w", encoding="utf-8") as f:
        f.write("\t".join(COLUMNS) + "\n")
        for row in rows:
            f.write("\t".join(row.fields()) + "\n")


def yielding(root: str = ROOT) -> set[int]:
    """The KRNL functions a task can park inside, by saturn-recomp's analysis of the game's [tasks]."""
    return resume.yielding_functions(config.load(os.path.join(root, "game.toml")))


def _discovery(root: str, module: str) -> dict:
    """The recompiler's view of a module, cached against build/recomp/inputs.json, which the last recompile
    wrote from everything it read."""
    cache = os.path.join(root, "build", "decomp", "function-code%s.json" % ("" if module == KRNL[0] else "-" + module))
    with open(os.path.join(root, "build", "recomp", "inputs.json"), encoding="utf-8") as f:
        stamp = f.read()
    try:
        with open(cache, encoding="utf-8") as f:
            saved = json.load(f)
        if saved["stamp"] == stamp and "polling" in saved and "jumps" in saved and "switches" in saved:
            return saved
    except (OSError, ValueError, KeyError):
        pass
    game = config.load(os.path.join(root, "game.toml"))
    _, path, base, seeds = next(s for s in recomp_build.specs(game) if s[0] == module)
    with open(path, "rb") as f:
        program = discover.Program(sh2.Image(f.read(), base), [base, *seeds])
    polling, jumps, switches = _polling_jumps(program)
    saved = {"stamp": stamp, "code": {e: sorted(fn.code) for e, fn in program.funcs.items()},
             "polling": polling, "jumps": jumps, "switches": switches}
    os.makedirs(os.path.dirname(cache), exist_ok=True)
    with open(cache, "w", encoding="utf-8") as f:
        json.dump(saved, f)
    return json.loads(json.dumps(saved))


def _polling_jumps(program: discover.Program) -> tuple[list[int], dict[int, str], dict[int, list[int]]]:
    """The generator's own rule: a jump table advances time when any target it may take is in its function
    at or before the jump, and an unresolved one may take any instruction of its function. Also how each
    jump was resolved, and the targets of each jump table."""
    entries, volatile = set(program.funcs), recomp_main.volatile_literals(program)
    polling = []
    kinds = {}
    switches = {}
    for fn in program.funcs.values():
        jumps = [a for a in fn.code if program.img.insn(a).op in ("jmp", "braf")]
        if not jumps:
            continue
        body = emit.Body(program, fn, entries, volatile, comments=False)
        anywhere = [a for a in fn.code if a not in body.slots]
        for a in jumps:
            candidates, how = body._targets[a]
            kinds[a] = how
            if how == "switch":
                switches[a] = list(program.switches[a])
            reach = anywhere if how == "unresolved" else candidates
            if any(v in fn.code and v <= a for v in reach):
                polling.append(a)
    return sorted(polling), kinds, switches


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--summary", action="store_true", help="print counts instead of rewriting the table")
    args = parser.parse_args()
    rows = build_table()
    if args.summary:
        print(summary(rows))
        return
    write_table(rows)
    print(summary(rows))


if __name__ == "__main__":
    main()
