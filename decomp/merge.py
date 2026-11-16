"""Merges a batch of workers' C and cases into src/ and planted/.

    python decomp/merge.py WORKER_DIR NAME [--verdicts ok few]

WORKER_DIR holds krnl.c, cases.py and report.tsv, as a worker leaves them. Each function whose verdict is
listed goes into the file of src/ for its address, replacing a definition already there, and cases.py is
copied to planted/NAME.py. Whatever krnl.c holds besides function definitions (typedefs, #defines) is
printed, for krnl.h. The addresses merged are printed last, for run.py.
"""
import argparse
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import gen  # noqa: E402
import status  # noqa: E402

INCLUDE = '#include "krnl.h"\n'


def definition_start(text: str, at: int) -> int:
    """Where a definition begins, counting the comment lines directly above its first line."""
    start = text.rfind("\n", 0, at) + 1
    while start > 0:
        before = text.rfind("\n", 0, start - 1) + 1
        if not text[before:start - 1].lstrip().startswith(("/*", "//", "*")):
            break
        start = before
    return start


def functions(text: str) -> tuple[str, dict[int, str]]:
    """The definitions of a worker's krnl.c by address, and everything else in it."""
    _, segments, _ = split(text)
    rest = text
    for _, body in segments.values():
        rest = rest.replace(body, "")
    return re.sub(r"\n{3,}", "\n\n", rest.replace(INCLUDE, "")).strip(), {a: body for a, (_, body) in segments.items()}


def merge(existing: str, additions: dict[int, str]) -> str:
    """The text of a src file with the definitions in `additions` (by address) put in: over the one it has, or in
    address order."""
    head, segments, tail = split(existing)
    for address, text in additions.items():
        segments[address] = (segments[address][0] if address in segments else "\n", text.rstrip("\n") + "\n")
    return head + "".join(lead + body for _, (lead, body) in sorted(segments.items())) + tail


def split(text: str) -> tuple[str, dict[int, tuple[str, str]], str]:
    """The text before the first definition, each definition by address with the text between it and the one
    before, and the text after the last."""
    found = list(gen._DEFINITION.finditer(text))
    if not found:
        return text.rstrip("\n") + "\n", {}, ""
    head = text[:definition_start(text, found[0].start())]
    segments: dict[int, tuple[str, str]] = {}
    previous = len(head)
    for m in found:
        start = definition_start(text, m.start())
        end = text.index("\n}\n", m.end()) + 3
        segments[int(m.group("address"), 16)] = (text[previous:start], text[start:end])
        previous = end
    return head, segments, text[previous:]


def verdicts(path: str) -> dict[int, str]:
    found = {}
    with open(path, encoding="utf-8") as f:
        for line in f:
            fields = line.rstrip("\n").split("\t")
            if len(fields) >= 2 and re.fullmatch(r"[0-9A-Fa-f]{8}", fields[0]):
                found[int(fields[0], 16)] = fields[1]
    return found


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("worker", help="the worker's directory")
    parser.add_argument("name", help="the name of its file in planted/, such as reach-1-a")
    parser.add_argument("--verdicts", nargs="+", default=["ok", "few"], help="the verdicts to merge")
    args = parser.parse_args()
    with open(os.path.join(args.worker, "krnl.c"), encoding="utf-8") as f:
        other, defined = functions(f.read())
    wanted = {a for a, v in verdicts(os.path.join(args.worker, "report.tsv")).items() if v in args.verdicts}
    by_file: dict[str, dict[int, str]] = {}
    for address, text in defined.items():
        if address in wanted:
            by_file.setdefault(status.source_for(address), {})[address] = text
    for path, additions in by_file.items():
        existing = open(path, encoding="utf-8").read() if os.path.exists(path) else INCLUDE + "\n"
        with open(path, "w", encoding="utf-8") as f:
            f.write(merge(existing, additions))
    shutil.copy(os.path.join(args.worker, "cases.py"), os.path.join(HERE, "planted", args.name + ".py"))
    if other:
        print("not a function, for krnl.h:\n" + other)
    print("merged:", " ".join("%08X" % a for a in sorted(wanted & set(defined))))


if __name__ == "__main__":
    main()
