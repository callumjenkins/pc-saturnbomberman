"""A --dump file: VDP1's VRAM, draw framebuffer and registers, then VDP2's VRAM, colour RAM and registers."""
import struct


class Dump:
    def __init__(self, path):
        d = open(path, "rb").read()
        self.vdp1_vram = d[:0x80000]
        self.vdp2_vram = d[0xC0020:0x140020]
        self.vdp2_regs = d[0x141020:0x141220]

    def reg(self, off):
        return struct.unpack(">H", self.vdp2_regs[off:off + 2])[0]

    def vdp1_word(self, a):
        return struct.unpack(">H", self.vdp1_vram[a:a + 2])[0]

    def vdp2_word(self, a):
        a &= 0x7FFFE
        return struct.unpack(">H", self.vdp2_vram[a:a + 2])[0]

    def cell(self, n, x, y):
        """The character number at screen dot (x, y) on NBGn, for the 2-word, 1x1-cell, 64x64-cell-page
        maps the stages use."""
        mp = self.reg(0x40 + n * 4) & 0x3F | (self.reg(0x3C) >> (n * 4) & 7) << 6
        base = ((mp & 0x1F) & ~3) * 0x4000
        if n < 2:
            b = 0x70 + n * 0x10
            sx, sy = self.reg(b), self.reg(b + 4)
        else:
            b = 0x90 + (n - 2) * 4
            sx, sy = self.reg(b), self.reg(b + 2)
        X, Y = (x + (sx & 0x7FF)) & 0x3FF, (y + (sy & 0x7FF)) & 0x3FF
        a = base + ((Y // 512) * 2 + X // 512) * 0x4000 + (((Y % 512) // 8) * 64 + (X % 512) // 8) * 4
        return self.vdp2_word(a + 2) & 0x7FFF

    def sprites(self):
        """VDP1's normal sprites in command order, as (colour, x, y, width, height)."""
        s = lambda a: ((self.vdp1_word(a) & 0x7FF) ^ 0x400) - 0x400
        out = []
        a, seen = 0, set()
        while a not in seen:
            seen.add(a)
            c = self.vdp1_word(a)
            if c & 0x8000:
                break
            jp = c >> 12 & 7
            if not c & 0x4000 and (c & 0xF) == 0:
                size = self.vdp1_word(a + 10)
                out.append((self.vdp1_word(a + 6), s(a + 12), s(a + 14), (size >> 8 & 0x3F) * 8, size & 0xFF))
            a = self.vdp1_word(a + 2) * 8 if jp in (1, 5) else a + 32
        return out
