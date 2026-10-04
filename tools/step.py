"""Gunman world from its code, the presses so far, then the stage at VBlank END as a map.
    uv run tools/step.py END "VBLANK:BUTTONS,..."
# rock, o soft block, f fire, % building/edge (NBG2 not floor), P pad 1's bomber, s other sprites (enemies, bombs, fire)."""
import os, struct, subprocess, sys
from paths import ROOT, RUN
end, presses = int(sys.argv[1]), sys.argv[2] if len(sys.argv) > 2 else ""
env = dict(os.environ, EXTRA=presses, DUMP=f"--dump {end}")
p = subprocess.run([f"{ROOT}/scripts/run-world.sh", "L+R+C+UP+RIGHT", str(end), str(end)], env=env, capture_output=True, text=True)
for l in p.stdout.splitlines():
    if "FATAL" in l or "seed" in l: print(l)
d = open(f"{RUN}/dump-{end}.bin", "rb").read()
v, V, R = d[:0x80000], d[0xC0020:0x140020], d[0x141020:0x141220]
r = lambda o: struct.unpack(">H", R[o:o + 2])[0]
w = lambda a: struct.unpack(">H", v[a:a + 2])[0]
s = lambda a: ((w(a) & 0x7FF) ^ 0x400) - 0x400
vw = lambda a: struct.unpack(">H", V[a & 0x7FFFE:(a & 0x7FFFE) + 2])[0]
def cell(n, x, y):
    mp = r(0x40 + n * 4) & 0x3F | (r(0x3C) >> (n * 4) & 7) << 6
    base = ((mp & 0x1F) & ~3) * 0x4000
    b = 0x70 + n * 0x10
    X, Y = (x + (r(b) & 0x7FF)) & 0x3FF, (y + (r(b + 4) & 0x7FF)) & 0x3FF
    if n >= 2:
        b = 0x90 + (n - 2) * 4
        X, Y = (x + (r(b) & 0x7FF)) & 0x3FF, (y + (r(b + 2) & 0x7FF)) & 0x3FF
    return vw(base + ((Y // 512) * 2 + X // 512) * 0x4000 + (((Y % 512) // 8) * 64 + (X % 512) // 8) * 4 + 2) & 0x7FFF
FLOOR = {0x100A, 0x100C, 0x100E, 0x102A, 0x102C, 0x102E}
g = {}
for row in range(1, 14):
    for col in range(19):
        x, y = 8 + 16 * col, 16 * row
        f, soft = cell(2, x, y), cell(0, x, y)
        g[(col, row)] = "o" if soft == 0x1002 else "f" if soft != 0x1000 and soft & 0x7000 != 0x1000 else "#" if f == 0x1006 else "." if f in FLOOR or (f >> 4) in (0x104, 0x100, 0x102) else "%"
sprites = []
a, seen, ret = 0, set(), None
while a not in seen:
    seen.add(a); c = w(a)
    if c & 0x8000: break
    jp = c >> 12 & 7
    if not c & 0x4000 and (c & 0xF) == 0:
        sprites.append((w(a + 6), s(a + 12), s(a + 14), (w(a + 10) >> 8 & 0x3F) * 8, w(a + 10) & 0xFF))
    a = a + 32 if jp in (0, 4) else w(a + 2) * 8 if jp in (1, 5) else a + 32
me = None
for colr, x, y, sw, sh in sprites:
    if y < 24 or sh > 40: continue
    col, row = (x + sw // 2 - 8) // 16, (y + sh - 1) // 16
    if colr & 0xFFF == 0x060: me = (col, row, x, y); g[(col, row)] = "P"
    elif (col, row) in g and g[(col, row)] in ".o": g[(col, row)] = "s"
print("    " + "".join(str(c % 10) for c in range(19)))
for row in range(1, 14): print(f"{row:3} " + "".join(g[(c, row)] for c in range(19)))
print("pad 1:", me, "| other sprites:", sorted({(f"{c:04X}", (x + sw // 2 - 8) // 16, (y + sh - 1) // 16) for c, x, y, sw, sh in sprites if 24 <= y and sh <= 40 and c & 0xFFF != 0x60}))
