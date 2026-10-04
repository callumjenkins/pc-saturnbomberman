"""Gunman world from its code, the presses so far, then the stage at VBlank END as a map: # rock,
o soft block, f fire, % building or edge, P pad 1's bomber, s other sprites (enemies, bombs, fire).
    uv run -m bomberman.research.step END "VBLANK:BUTTONS,..." """
import sys

from .. import routes, run
from .dump import Dump

FLOOR = {0x100A, 0x100C, 0x100E, 0x102A, 0x102C, 0x102E}


def main():
    end, presses = int(sys.argv[1]), sys.argv[2] if len(sys.argv) > 2 else ""
    out = run.out_dir("step")
    log = run.run(routes.world("gunman"), out, vblanks=end, shots=str(end), extra=presses.split(",") if presses else (),
                  more=("--dump", str(end)), log=print)
    for line in log.splitlines():
        if "FATAL" in line:
            print(line)
    d = Dump(f"{out}/dump-{end}.bin")
    g = {}
    for row in range(1, 14):
        for col in range(19):
            x, y = 8 + 16 * col, 16 * row
            f, soft = d.cell(2, x, y), d.cell(0, x, y)
            g[(col, row)] = ("o" if soft == 0x1002 else "f" if soft != 0x1000 and soft & 0x7000 != 0x1000
                             else "#" if f == 0x1006 else "." if f in FLOOR or (f >> 4) in (0x104, 0x100, 0x102) else "%")
    me = None
    sprites = [(c, x, y, w, h) for c, x, y, w, h in d.sprites() if y >= 24 and h <= 40]
    for colr, x, y, sw, sh in sprites:
        col, row = (x + sw // 2 - 8) // 16, (y + sh - 1) // 16
        if colr & 0xFFF == 0x060:
            me = (col, row, x, y)
            g[(col, row)] = "P"
        elif (col, row) in g and g[(col, row)] in ".o":
            g[(col, row)] = "s"
    print("    " + "".join(str(c % 10) for c in range(19)))
    for row in range(1, 14):
        print(f"{row:3} " + "".join(g[(c, row)] for c in range(19)))
    others = sorted({(f"{c:04X}", (x + sw // 2 - 8) // 16, (y + sh - 1) // 16)
                     for c, x, y, sw, sh in sprites if c & 0xFFF != 0x60})
    print("pad 1:", me, "| other sprites:", others)


if __name__ == "__main__":
    main()
