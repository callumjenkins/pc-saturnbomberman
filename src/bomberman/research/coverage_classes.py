"""Writes coverage-classes.tsv, the code the coverage report sets aside as no lead.

    uv run python -m bomberman.research.coverage_classes JP_0KRNL.BIN US_JP.tsv

US_JP.tsv is `python -m saturnrecomp.recomp.versions --game game.toml --module KRNL JP_0KRNL.BIN@0600A000
--tsv US_JP.tsv`, from the Japanese disc (the version-diff skill). Every function of a classed group is
listed, so the class holds when a route reaches part of the group and the rest regroups.

- online: behind a test of link_mode at the call, so only a NetLink connection reaches it.
- dead: an orphan here whose Japanese counterpart nothing calls or points at either.
- cut: an orphan here that the Japanese release calls, from code the US release changed or dropped.
"""
import collections
import os
import sys

from saturnrecomp import config, sh2
from saturnrecomp.playtest import coverage
from saturnrecomp.recomp.discover import Program

JP_BASE = 0x0600A000

# Each root, and where its caller tests link_mode before calling it.
ONLINE = {
    0x06059648: "link_mode != 0 at 0603313E",
    0x06051B0C: "link_mode != 0 at 0602E5B4",
    0x06059A72: "link_mode == 2 at 06059A44",
    0x0605A124: "link_mode == 1 at 06059A40",
    0x060518D0: "link_mode != 0 at 0602E416",
    0x06051A78: "link_mode != 0 at 0602E416",
    0x06059798: "link_mode == 2 at 06032C98",
    0x06007326: "link_mode == 2 at 0602F82E",
    0x06059B70: "link_mode == 2 at 06059B22",
    0x06059BF2: "link_mode == 2 at 06059B22",
    0x06059C0A: "link_mode == 2 at 06059B22",
    0x060599C8: "link_mode == 2 at 06059B22",
}


def jp_status(jp_file, tsv):
    """{US entry: "dead" or "cut"} for the US functions paired with a JP one, by whether the JP one has a
    caller or a stored pointer."""
    data = open(jp_file, "rb").read()
    img = sh2.Image(data, JP_BASE)
    pairs = {}
    for line in open(tsv):
        kind, a, b, *_ = line.split("\t")
        if int(b, 16):
            pairs[int(a, 16)] = int(b, 16)
    p = Program(img, [JP_BASE, *sorted(set(pairs.values()))])
    called = {c for e, f in p.funcs.items() for c in (f.calls | f.tails) - {e}}
    words = {int.from_bytes(data[i:i + 4], "big") for i in range(0, len(data) - 3, 2)}
    return {a: "cut" if b in called or b in words else "dead" for a, b in pairs.items()}


def main(argv=None):
    jp_file, tsv = (argv or sys.argv[1:])[:2]
    game = config.load("game.toml")
    found = coverage.coverage_map(game, os.path.join(game.build, "playtest"))
    insns, calls = coverage.generated(os.path.join(game.build, "recomp"), ["KRNL"])
    reached = set(found["runs"])

    def below(k):
        seen, todo = {k}, [k]
        while todo:
            for c in calls[todo.pop()]:
                if c not in reached and c not in seen:
                    seen.add(c)
                    todo.append(c)
        return seen

    owner = {}                                   # each function in the group the report puts it in
    for kind in coverage.KINDS:
        for _, k, root, _ in found["roots"]:
            if k == kind:
                for f in below(root):
                    owner.setdefault(f, root)
    status = jp_status(jp_file, tsv)
    rows, tally = [], collections.Counter()
    for n, kind, root, _ in found["roots"]:
        if root[0] != "KRNL":
            continue
        if kind == "behind" and root[1] in ONLINE:
            cls, why = "online", ONLINE[root[1]]
        elif kind == "orphan" and root[1] in status:
            cls = status[root[1]]
            why = "no caller or pointer in the JP release either" if cls == "dead" else "called in the JP release"
        else:
            continue
        tally[cls] += n
        for k in sorted(f for f in below(root) if owner.get(f) == root):
            rows.append(f"KRNL {k[1]:08X} {cls}  " + (why if k == root else f"under {root[1]:08X}"))
    with open("coverage-classes.tsv", "w") as f:
        f.write("# Code the coverage report sets aside: MODULE ADDRESS CLASS, then a note.\n"
                "# Written by src/bomberman/research/coverage_classes.py; its docstring says how.\n")
        f.write("\n".join(rows) + "\n")
    print(", ".join(f"{c} {n} bytes" for c, n in sorted(tally.items())))


if __name__ == "__main__":
    main()
