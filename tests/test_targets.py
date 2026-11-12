import csv
import glob
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def entries() -> set[int]:
    with open(os.path.join(ROOT, "decomp", "status.tsv"), encoding="utf-8", newline="") as f:
        return {int(row["address"], 16) for row in csv.DictReader(f, delimiter="\t")}


def test_every_call_and_jump_in_the_decompiled_c_goes_to_a_function_the_recompile_has():
    found = entries()
    missing = []
    for path in sorted(glob.glob(os.path.join(ROOT, "decomp", "src", "*.c"))):
        with open(path, encoding="utf-8") as f:
            for number, line in enumerate(f, 1):
                for target in re.findall(r"G(?:CALL|JUMP)\d\(\s*(0x[0-9A-Fa-f]+)", line):
                    if int(target, 16) not in found:
                        missing.append("%s:%d %s" % (os.path.basename(path), number, target))
    assert missing == []
