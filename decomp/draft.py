"""Lifts the functions at the addresses in a file, then places the drafts in the module's folder of C.

    python decomp/draft.py ADDRESSES.txt                 # the drafts on stdout, one block per address
    farm map --items ADDRESSES.txt --out OUT -- env DECOMP_MODULE=BOOT python3 decomp/draft.py
    python decomp/draft.py --place OUT/chunks            # put what the chunks hold into the C, list the refusals
    python decomp/draft.py --drop ADDRESSES.txt          # take the functions at these addresses out of the C

Without an argument it reads the chunk `farm map` hands it, FARM_ITEMS. A block starts with `#### ADDRESS ok`
followed by the draft, or is the single line `#### ADDRESS refused: WHY`. The module is the one DECOMP_MODULE
names, KRNL by default. A function the C already defines keeps its definition.
"""
import argparse
import glob
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import lift  # noqa: E402
import modules  # noqa: E402
import status  # noqa: E402
import structure  # noqa: E402

INCLUDE = '#include "krnl.h"\n'
MARK = "#### "
NOTE = "/* Lifted by decomp/lift.py, not yet rewritten by hand. */\n"


def lift_all(addresses: list[int]) -> str:
    image, code = status.image(), status.function_code()
    blocks = []
    for address in addresses:
        try:
            blocks.append("%s%08X ok\n%s" % (MARK, address, lift.lift(image, address, code.get(address), code, False)))
        except (lift.Unsupported, structure.Unstructured) as error:
            blocks.append("%s%08X refused: %s\n" % (MARK, address, str(error).replace("\n", " ")))
    return "".join(blocks)


def place(folder: str) -> dict[int, str]:
    """Adds the drafts the chunks of `folder` hold to the files of C, and returns the refusals by address."""
    drafts: dict[int, str] = {}
    refused: dict[int, str] = {}
    for path in sorted(glob.glob(os.path.join(folder, "*.out"))):
        with open(path, encoding="utf-8") as f:
            for block in re.split(r"^%s" % MARK, f.read(), flags=re.MULTILINE)[1:]:
                head, _, text = block.partition("\n")
                address, verdict = head.split(" ", 1)
                if verdict == "ok":
                    drafts[int(address, 16)] = text
                else:
                    refused[int(address, 16)] = verdict.removeprefix("refused: ")
    defined = status.drafted()
    by_file: dict[str, list[int]] = {}
    for address in sorted(set(drafts) - defined):
        by_file.setdefault(status.source_for(address), []).append(address)
    os.makedirs(modules.current().src, exist_ok=True)
    for path, addresses in by_file.items():
        start = "" if os.path.exists(path) else INCLUDE
        with open(path, "a", encoding="utf-8") as f:
            f.write(start + "".join("\n" + NOTE + drafts[a].rstrip("\n") + "\n" for a in addresses))
    print("%d placed, %d already defined, %d refused" % (sum(map(len, by_file.values())), len(set(drafts) & defined), len(refused)))
    return refused


def drop(addresses: set[int]) -> int:
    """Removes the functions at `addresses`, with the note above a lifted one, from the files of C. Returns how many went."""
    gone = 0
    for path in status.sources():
        with open(path, encoding="utf-8") as f:
            text = f.read()
        for address in addresses:
            found = re.search(r"(?:\n%s\n)?^[^\n]* f%08X\([^\n]*\n\{\n.*?\n\}\n" % (re.escape(NOTE.rstrip("\n")), address),
                              text, re.MULTILINE | re.DOTALL)
            if found:
                text = text[:found.start()] + text[found.end():]
                gone += 1
        with open(path, "w", encoding="utf-8") as f:
            f.write(text)
    return gone


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("addresses", nargs="?", help="a file of hex addresses; FARM_ITEMS if left out")
    parser.add_argument("--place", metavar="CHUNKS", help="place the drafts of the chunk files in this folder")
    parser.add_argument("--drop", metavar="ADDRESSES", help="remove the functions at the addresses in this file")
    args = parser.parse_args()
    if args.drop:
        with open(args.drop, encoding="utf-8") as f:
            print("%d removed" % drop({int(word, 16) for word in f.read().split()}))
        return
    if args.place:
        for address, why in sorted(place(args.place).items()):
            print("%08X\t%s" % (address, why))
        return
    with open(args.addresses or os.environ["FARM_ITEMS"], encoding="utf-8") as f:
        sys.stdout.write(lift_all([int(word, 16) for word in f.read().split()]))


if __name__ == "__main__":
    main()
