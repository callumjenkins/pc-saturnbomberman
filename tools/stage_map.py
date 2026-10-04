"""The stage as a grid from a --dump: each 16-dot cell's top-left character on NBG0 and NBG1, and the
sprites. Args: DUMP [XOFF YOFF] (screen dot of cell (0,0); default 8,0)."""
import struct, sys
from collections import Counter
d = open(sys.argv[1], "rb").read()
xo, yo = (int(sys.argv[2]), int(sys.argv[3])) if len(sys.argv) > 3 else (8, 0)
V, R = d[0xC0020:0x140020], d[0x141020:0x141220]
r = lambda o: struct.unpack(">H", R[o:o + 2])[0]
vw = lambda a: struct.unpack(">H", V[a & 0x7FFFE:(a & 0x7FFFE) + 2])[0]
def cell(n, x, y):
    mp = r(0x40 + n * 4) & 0x3F | (r(0x3C) >> (n * 4) & 7) << 6
    base = ((mp & 0x1F) & ~3) * 0x4000
    b = 0x70 + n * 0x10 if n < 2 else 0x90 + (n - 2) * 4
    sx, sy = (r(b) & 0x7FF, r(b + 4 if n < 2 else b + 2) & 0x7FF)
    X, Y = (x + sx) & 0x3FF, (y + sy) & 0x3FF
    a = base + ((Y // 512) * 2 + X // 512) * 0x4000 + (((Y % 512) // 8) * 64 + (X % 512) // 8) * 4
    return vw(a + 2) & 0x7FFF
cols, rows = range((320 - xo) // 16), range(1, (224 - yo) // 16)
for n in (0, 1, 2, 3):
    grid = {(c, rr): cell(n, xo + 16 * c, yo + 16 * rr) for c in cols for rr in rows}
    common = Counter(grid.values()).most_common(1)[0][0]
    names = {}
    print(f"NBG{n} (. = {common:04X})")
    for rr in rows:
        line = ""
        for c in cols:
            v = grid[(c, rr)]
            line += "." if v == common else names.setdefault(v, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"[len(names) % 62])
        print(f"  {rr:2} {line}")
    print("  " + " ".join(f"{k}={v:04X}" for v, k in list(names.items())[:30]))
