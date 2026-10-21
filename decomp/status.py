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
from saturnrecomp import sh2  # noqa: E402

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)

COLUMNS = ("module", "address", "insns", "calls", "leaf", "executed", "yields", "hooked", "state", "name")
COVERAGE = ("build/test/*/coverage.txt", "build/run/*/coverage.txt", "build/play/*/replay/coverage.txt")
KRNL = ("KRNL", "build/extract/BOMSS/0KRNL.BIN", 0x06006000)
SRC = os.path.join(HERE, "src")
STATES = ("todo", "drafted", "swapped", "dead")
TABLE = os.path.join(HERE, "status.tsv")

_BRANCHES = ("bt", "bf", "bt/s", "bf/s", "bra")
_CALL = re.compile(r"\b(?:bsr|jsr|bsrf)\b")
_ENDS = ("bra", "braf", "jmp", "rts", "rte")
_DEFINED = re.compile(r"^[^\s#/*].*?\bf([0-9A-F]{8})\(", re.MULTILINE)
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
    hooked: bool = False                    # a [[hook]] is on one of its instructions, which C never runs

    @property
    def leaf(self) -> bool:
        return self.calls == 0

    def fields(self) -> list[str]:
        return [self.module, "%08X" % self.address, str(self.insns), str(self.calls), "yes" if self.leaf else "no",
                "yes" if self.executed else "no", "yes" if self.yields else "no",
                "yes" if self.hooked else "no", self.state, self.name]


def drafted(paths: list[str] | None = None) -> set[int]:
    """The addresses the decompiled C defines a function for."""
    found: set[int] = set()
    for path in paths or sources():
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


def replaced(path: str = os.path.join(ROOT, "game.toml")) -> set[tuple[str, int]]:
    """The (module, address) pairs game.toml replaces."""
    with open(path, encoding="utf-8") as f:
        return {(m.group(1), int(m.group(2), 16)) for m in _REPLACE.finditer(f.read())}


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
                fields["state"], fields["name"], fields.get("yields") == "yes", fields.get("hooked") == "yes")
    return old


def source_for(address: int, folder: str = SRC) -> str:
    """The file of src/ a function at this address belongs in."""
    return os.path.join(folder, "krnl_%04X.c" % (address >> 16))


def sources(folder: str = SRC) -> list[str]:
    """The decompiled C, one file per 64 KiB of the module, so two people never edit the same file."""
    return sorted(glob.glob(os.path.join(folder, "*.c")))


def yielding(root: str = ROOT) -> set[int]:
    """The KRNL functions a task can park inside, by saturn-recomp's analysis of the game's [tasks]."""
    from saturnrecomp import config
    from saturnrecomp.analysis import resume
    return resume.yielding_functions(config.load(os.path.join(root, "game.toml")))


def body(image: sh2.Image, address: int) -> list[sh2.Insn]:
    """The instructions reachable from an entry without leaving the function, in address order. A literal
    pool between two returns is never reached, and a jump through a register is not followed."""
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


def function_code(root: str = ROOT) -> dict[int, set[int]]:
    """{entry: its instruction addresses} for KRNL, as the recompiler finds them from the build's seeds.
    Cached against build/recomp/inputs.json, which changes whenever those could."""
    from saturnrecomp import build as recomp_build, config
    from saturnrecomp.recomp import discover
    cache = os.path.join(root, "build", "decomp", "function-code.json")
    with open(os.path.join(root, "build", "recomp", "inputs.json"), encoding="utf-8") as f:
        stamp = f.read()
    try:
        with open(cache, encoding="utf-8") as f:
            saved = json.load(f)
        if saved["stamp"] == stamp:
            return {int(k): set(v) for k, v in saved["code"].items()}
    except (OSError, ValueError, KeyError):
        pass
    game = config.load(os.path.join(root, "game.toml"))
    _, path, base, seeds = next(s for s in recomp_build.specs(game) if s[0] == "KRNL")
    with open(path, "rb") as f:
        program = discover.Program(sh2.Image(f.read(), base), [base, *seeds])
    code = {e: sorted(fn.code) for e, fn in program.funcs.items()}
    os.makedirs(os.path.dirname(cache), exist_ok=True)
    with open(cache, "w", encoding="utf-8") as f:
        json.dump({"stamp": stamp, "code": code}, f)
    return {e: set(v) for e, v in code.items()}


def hooked(root: str = ROOT) -> set[int]:
    """The KRNL functions whose code holds an address game.toml hooks."""
    from saturnrecomp import config
    hooks = set(config.load(os.path.join(root, "game.toml")).hooks.get(KRNL[0], []))
    return {entry for entry, code in function_code(root).items() if code & hooks}


def krnl_image(root: str = ROOT) -> sh2.Image:
    _, rel, base = KRNL
    with open(os.path.join(root, rel), "rb") as f:
        return sh2.Image(f.read(), base)


def walk(root: str, address: int) -> tuple[int, int]:
    """Instructions and calls of a KRNL function. A replaced function has no rows in the map, so this
    counts one that was never in the table."""
    insns = body(krnl_image(root), address)
    return len(insns), sum(ins.op in ("bsr", "jsr", "bsrf") for ins in insns)


def build_table(root: str = ROOT) -> list[Row]:
    ran = executed(root)
    swapped = replaced(os.path.join(root, "game.toml"))     # only to start a table; gen.py writes them after
    written = drafted()
    old = previous(os.path.join(HERE, "status.tsv"))
    rows = functions(root)
    found = {(row.module, row.address) for row in rows}
    for key in sorted((set(old) or swapped) - found):       # the map leaves out a replaced function
        was = old.get(key)
        insns, calls = (was.insns, was.calls) if was else walk(root, key[1])
        rows.append(Row(key[0], key[1], insns, calls, False))
    rows.sort(key=lambda row: (row.module, row.address))
    parked = yielding(root)
    caught = hooked(root)
    for row in rows:
        key = (row.module, row.address)
        row.executed = key in ran
        row.yields = row.module == KRNL[0] and row.address in parked
        row.hooked = row.module == KRNL[0] and row.address in caught
        was = old.get(key)
        row.name = was.name if was else ""
        if was and was.state in ("dead", "swapped"):
            row.state = was.state
        elif not old and key in swapped:
            row.state = "swapped"
        elif row.module == KRNL[0] and row.address in written:
            row.state = "drafted"
    return rows


def write_table(rows: list[Row], path: str = TABLE) -> None:
    with open(path, "w", encoding="utf-8") as f:
        f.write("\t".join(COLUMNS) + "\n")
        for row in rows:
            f.write("\t".join(row.fields()) + "\n")


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
