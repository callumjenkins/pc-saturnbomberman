"""The stage as a grid from a --dump: each 16-dot cell's top-left character on NBG0 to NBG3.
    uv run -m bomberman.research.stage_map DUMP [XOFF YOFF]
XOFF YOFF are the screen dot of cell (0,0), 8 0 by default."""
import sys
from collections import Counter

from .dump import Dump

NAMES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"


def main():
    d = Dump(sys.argv[1])
    xo, yo = (int(sys.argv[2]), int(sys.argv[3])) if len(sys.argv) > 3 else (8, 0)
    cols, rows = range((320 - xo) // 16), range(1, (224 - yo) // 16)
    for n in range(4):
        grid = {(c, r): d.cell(n, xo + 16 * c, yo + 16 * r) for c in cols for r in rows}
        common = Counter(grid.values()).most_common(1)[0][0]
        names = {}
        print(f"NBG{n} (. = {common:04X})")
        for r in rows:
            line = "".join("." if grid[(c, r)] == common else names.setdefault(grid[(c, r)], NAMES[len(names) % len(NAMES)])
                           for c in cols)
            print(f"  {r:2} {line}")
        print("  " + " ".join(f"{k}={v:04X}" for v, k in list(names.items())[:30]))


if __name__ == "__main__":
    main()
