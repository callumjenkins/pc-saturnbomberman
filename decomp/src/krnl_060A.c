#include "krnl.h"

int f060A0706(gaddr p)
{
    int mask = 64;

    if (LD16(p) != -1)
        mask |= 1;
    if (LD16(p + 2) != -1)
        mask |= 2;
    if (LD16(p + 4) != -1)
        mask |= 4;
    if (LD16(p + 8) != -1)
        mask |= 8;
    return mask;
}

void f060A08BA(gaddr p)
{
    ST32(p, 0);
    ST32(p + 4, 0);
    ST8(p + 58, 0);
}

int f060A0CB2(void)
{
    return 0;
}

void f060A11E2(int value)
{
    ST32(LD32(0x060FC00C) + 32, value);
}

void f060A1356(int code)
{
    int err = 0;

    if (code == 3) {
        err = -23;
    } else if (code == 4) {
        gaddr p = LD32(LD32(0x060FC00C) + 16);

        if (!p || !GCALL1(0x060A129C, p))
            err = -2;
    } else if (code == 6) {
        err = -25;
    } else if (code == 5) {
        err = -1;
    }
    if (err)
        GJUMP1(0x060A11EA, err);
}

void f060A2EE0(int a, int b)
{
    ST32(LD32(0x060FC00C) + 28, 0);
    ST32(LD32(0x060FC00C) + 36, a);
    ST32(LD32(0x060FC00C) + 40, b);
}

void f060A2F10(void)
{
    ST32(0x060FC018, 0);
    ST32(0x060FC01C, 0);
    ST32(0x060FC020, 0);
}

int f060A32A6(int a, int b, int c)
{
    return 0;
}

void f060A3900(void)
{
    ST32(0x060FC038, 0);
    GCALL0(0x060AAE84);
}

int f060A3C38(int value)
{
    return GJUMP1(0x060ABCAA, value);
}

int f060A3EB4(void)
{
    return GJUMP0(0x060AAE30);
}

void f060A3EBC(int a, int b)
{
    GJUMP2(0x060AAE44, a, b);
}

int f060A3F84(void)
{
    return 0;
}

void f060A3F90(int a, int b)
{
}

void f060A40C0(void)
{
}

void f060A45E4(void)
{
    ST32(0x060FC03C, 0);
    GCALL0(0x060AD718);
}

void f060A49F0(int a, int b)
{
    GJUMP2(0x060AD6D6, a, b);
}

void f060A4BDE(void)
{
}

void f060A4C08(void)
{
}

void f060A51AC(gaddr p)
{
    int reg = LD32(0xFFFFFFB0);
    int flags = LD32(p + 8);

    if ((flags & 1) == 1)
        reg = (reg & ~8) | LD32(p);
    if ((flags & 8) == 8)
        reg = (reg & ~1) | LD32(p + 4);
    if ((flags & 2) == 2)
        reg &= ~4;
    if ((flags & 4) == 4)
        reg &= ~2;
    ST32(0xFFFFFFB0, reg);
}

void f060A52FA(int n)
{
    int reg = (n << 4) - 116;

    ST32(reg, LD32(reg) & ~1);
}

void f060A5318(gaddr p)
{
    int reg = LD32(0xFFFFFFB0);

    ST32(p, reg & 4);
    ST32(p + 4, reg & 2);
}

int f060A56CA(int n, int base)
{
    return n * 12 + base;
}

int f060A56D8(int a, int b)
{
    return a * 24 + b;
}

/* Sets a 60-byte record up: zero except a 1 at 20, then the two setters, which the game keeps as
 * functions of their own. Returns the record. */
REF(Thing) f060A5EEC(REF(Thing) t)
{
    SET(Thing, t, f0, 0);
    SET(Thing, t, f4, 0);
    SET(Thing, t, f8, 0);
    SET(Thing, t, f12, 0);
    SET(Thing, t, f16, 0);
    SET(Thing, t, f20, 1);
    SET(Thing, t, f24, 0);
    SET(Thing, t, f28, 0);
    SET(Thing, t, f32, 0);
    GCALL2(0x060A5F2E, t, 1);
    SET(Thing, t, f52, 0);
    GCALL2(0x060A5F22, t, 3);
    return t;
}

int f060A5F22(gaddr p, int value)
{
    int old = LD32(p + 56);

    ST32(p + 56, value);
    ST32(p + 36, 0);
    ST32(p + 40, 0);
    return old;
}

void f060A5F2E(gaddr p, int value)
{
    ST32(p + 44, value);
}

void f060A5F32(gaddr p, int value)
{
    int kind, n;

    ST32(p + 24, value);
    ST32(p + 28, 0);
    if (LD32(p + 52) != 6)
        return;
    ST32(p + 52, 0);
    kind = LD32(p + 56);
    if (kind == 1 || kind == 2 || kind == 3) {
        n = LD32(p + 8) + 3;
        ST32(p + 8, n);
        ST32(p + 8, DIVU(n, 4) * 4);
    }
}

int f060A5F74(gaddr p)
{
    return LD32(p + 24);
}

int f060A5F7C(gaddr p, int v)
{
    int old = LD32(p + 20);

    ST32(p + 20, v);
    return old;
}

void f060A5F82(gaddr p)
{
    ST32(p + 48, 1);
}

void f060A5F88(gaddr p)
{
    ST32(p + 48, 0);
}

int f060A629C(void)
{
    return 1;
}

int f060A6496(void)
{
    POLL();
    return 1;
}

int f060A64C4(void)
{
    POLL();
    return 1;
}

int f060A64F2(void)
{
    return 1;
}

int f060A6534(void)
{
    return 0;
}

int f060A66EE(gaddr p)
{
    return LD32(p + 8);
}

int f060A66F2(gaddr p)
{
    return LD32(p + 4) * LD32(p + 44) - LD32(p + 8);
}

void f060A6770(REF(Thing) p, int a, int b, int c)
{
    SET(Thing, p, f0, a);
    SET(Thing, p, f4, b);
    SET(Thing, p, f44, c);
    SET(Thing, p, f8, 0);
}

void f060A677C(gaddr p, int a, int b)
{
    ST32(p + 144, b);
    ST32(p + 148, a);
    ST32(p + 164, 4);
}

int f060A6BF2(gaddr p)
{
    return GJUMP1(0x060A71E4, p + 28);
}

int f060A6C8E(gaddr p, int n)
{
    int size = LD8(p + 12) & 255;
    int q, step, rem;

    if (!size)
        return n;
    q = DIVS(n, size);
    step = (LD8(p + 13) & 255) + size;
    rem = MODS(n, size);
    return rem + q * step;
}

int f060A6DA6(int flags)
{
    if (flags & 64)
        return 0x930;
    if (!(flags & 16))
        return 0x800;
    if (!(flags & 8))
        return 0x914;
    return 0;
}

int f060A71E4(gaddr p)
{
    return LD32(p + 32) + LD32(p + 36);
}

int f060A74E2(gaddr p)
{
    int v = GCALL0(0x060A78B0);

    if (v < 0)
        return 0;
    ST32(p + 28, v);
    return 1;
}

void f060A7540(int flag)
{
    gaddr g = LD32(DEV);

    ST8(g + 23, flag ? 1 : 0);
    ST8(LD32(DEV) + 24 + 23, flag ? 1 : 0);
}

int f060A77B0(int i)
{
    gaddr p;

    if (i < 0 || i >= 24)
        return -6;
    p = LD32(0x060FC084) + 24;
    if (LD8(p + i) != 1)
        return -7;
    ST8(p + i, 0);
    return 0;
}

int f060A78B0(void)
{
    gaddr g = LD32(DEV);

    if (LD32(g + 48) == 1)
        return -5;
    ST32(g + 48, 1);
    ST32(g + 56, LD32(g + 56) + 1);
    if (LD32(g + 56) < 0)
        ST32(g + 56, 0);
    return LD32(g + 56);
}

int f060A78E0(int key)
{
    gaddr g = LD32(DEV);

    if (!LD32(g + 48))
        return -7;
    if (LD32(g + 56) != key)
        return -9;
    ST32(g + 48, 0);
    return 0;
}

void f060A7B76(int a)
{
    int r;

    if (LD32(LD32(DEV) + 52) == -1)
        return;
    r = GCALL1(0x06095716, a);
    ST32(LD32(DEV) + 52, -1);
    if (!r)
        GCALL0(0x060A8C10);
}

int f060A7C20(int value)
{
    gaddr g = LD32(DEV);

    return LD32(g + 0x338) == 0 || LD32(g + 0x33C) != value;
}

int f060A8128(int kind)
{
    int off;

    switch (kind) {
    case 0:
        off = 88;
        break;
    case 1:
        off = 0x304;
        break;
    case 2:
        off = 0x30C;
        break;
    case 3:
        off = 0x328;
        break;
    case 4:
        off = 0x338;
        break;
    case 5:
        off = 0x348;
        break;
    case 6:
        off = 0x1E0;
        break;
    case 7:
        off = 0x360;
        break;
    default:
        return 0;
    }
    return LD32(LD32(0x060FC084) + off) == 0;
}

void f060A81FE(int value)
{
    ST32(LD32(DEV) + 60, value);
}

void f060A83A0(gaddr counter)
{
    if (LD32(LD32(DEV) + 0x304) == 1) {
        int r = GCALL1(0x060AE3D4, LD32(LD32(DEV) + 0x308));

        ST32(counter, LD32(counter) + 1);
        if (!r)
            ST32(LD32(DEV) + 0x304, 2);
        GCALL0(0x060A8C10);
    }
    if (LD32(LD32(DEV) + 0x304) == 2) {
        if (GCALL1(0x060A8B72, 64))
            ST32(LD32(DEV) + 0x304, 0);
    }
}

void f060A8556(gaddr counter)
{
    gaddr g = LD32(DEV);

    if (LD32(g + 0x328) == 1) {
        if (GCALL3(0x060AE8DA, LD32(g + 0x32C), LD32(g + 0x330), LD32(g + 0x334)))
            return;
        GCALL0(0x060A8C10);
        ST32(counter, LD32(counter) + 1);
        ST32(LD32(DEV) + 0x328, 2);
    }
    if (LD32(LD32(DEV) + 0x328) != 2)
        return;
    if (GCALL1(0x060956CC, 0))
        return;
    ST32(LD32(DEV) + 0x328, 0);
}

void f060A85E4(gaddr counter)
{
    int ok = 1;
    gaddr g = LD32(DEV);

    if (LD32(g + 0x338) == 1) {
        if (LD32(g + 0x340) != 0 || LD32(g + 0x344) != -1) {
            if (LD32(g + 0x344))
                ST32(g + 0x338, 2);
            else
                ok = 0;
        } else {
            if (GCALL2(0x060AE676, 0, LD32(g + 0x33C)))
                return;
            GCALL0(0x060A8C10);
            ST32(counter, LD32(counter) + 1);
            ST32(LD32(DEV) + 0x338, 4);
        }
    }
    if (LD32(LD32(DEV) + 0x338) == 2) {
        int r = GCALL3(0x060AE908, LD32(LD32(DEV) + 0x33C), LD32(LD32(DEV) + 0x340), LD32(LD32(DEV) + 0x344));

        ST32(counter, LD32(counter) + 1);
        if (!r) {
            ST32(LD32(DEV) + 0x338, 3);
            GCALL0(0x060A8C10);
        }
    }
    if (LD32(LD32(DEV) + 0x338) == 3) {
        if (GCALL1(0x060A8B72, 128))
            ok = 0;
    }
    if (LD32(LD32(DEV) + 0x338) == 4) {
        if (GCALL1(0x060A8B72, 64))
            ok = 0;
    }
    if (ok != 1) {
        GCALL1(0x060958F2, -9);
        ST32(LD32(DEV) + 0x338, 0);
    }
}

void f060A8B98(void)
{
    gaddr g = LD32(DEV);
    int i = 0;

    do {
        ST8(g + i, 0);
        ST8(g + 24 + i, 0);
    } while (AGAIN(++i < 23));
    ST32(g + 48, 0);
    ST32(g + 52, -1);
    ST32(g + 56, -1);
    ST32(g + 60, 0);
    ST32(g + 76, 0);
    ST32(g + 80, 0);
    ST32(g + 84, 0);
    ST32(g + 88, 0);
    ST32(g + 0x304, 0);
    ST32(g + 0x30C, 0);
    ST32(g + 0x328, 0);
    ST32(g + 0x338, 0);
    ST32(g + 0x348, 0);
    ST32(g + 0x360, 0);
    ST32(g + 0x1DC, 0);
    ST32(g + 0x1E0, 0);
}

void f060A8C32(int a, int b)
{
    ST32(LD32(DEV) + 76, a);
    ST32(LD32(DEV) + 80, b);
}

int f060A8D0C(int which)
{
    int value;

    switch (which) {
    case 1:
        value = LDU16(0x060FB8A2) & 7;
        break;
    case 2:
    case 4:
        value = LDU16(0x060FB8A0) & 7;
        break;
    case 8:
    case 128:
        value = (LDU16(0x060FB8A0) & 0x70) >> 4;
        break;
    case 16:
        value = (LDU16(0x060FB8A0) & 0x700) >> 8;
        break;
    case 32:
        value = (LDU16(0x060FB8A0) & 0x7000) >> 12;
        break;
    case 256:
        value = (LDU16(0x060FB8A2) & 0x70) >> 4;
        break;
    case 0x00040000:
        value = LD32(0x060FB8E0);
        break;
    default:
        return which;
    }
    POLL();
    return value;
}

void f060AA50C(int index)
{
    int limit = LD32(0x060FBF8C);
    gaddr entry, slot;
    int n;

    if (index >= limit)
        index = limit - 1;
    entry = LD32(0x060FBFA8);
    ST32(0x060FBFA8, entry + 4);
    ST16(entry + 2, LD32(0x060FBF90));
    ST16(entry, -1);
    slot = LD32(0x060FBFA4) + index * 4;
    n = LD32(0x060FBF9C);
    if (LD16(slot) != -1)
        ST16(LD32(0x060FBFA0) + LDU16(slot + 2) * 4, n);
    else
        ST16(slot, n);
    ST16(slot + 2, n);
    ST32(0x060FBF9C, n + 1);
}

void f060AADF8(void)
{
    ST32(0x060BB990, 0);
    ST32(0x060BB994, 0);
    ST32(0x060BB998, 0);
}

int f060AAE30(void)
{
    return LD32(0x060BB990);
}

void f060AAE44(int a, int b)
{
    ST32(0x060BB994, a);
    ST32(0x060BB998, b);
}

void f060AAE4E(void)
{
}

int f060AB316(gaddr p)
{
    return LD32(p);
}

int f060AB31C(gaddr p)
{
    return LD32(p) + 52;
}

void f060ABCAA(int value)
{
    ST32(0x060FC168, value);
}

int f060ABCB0(void)
{
    return LD32(0x060FC168);
}

int f060ABD4E(int n)
{
    return LD32(0x060BBA9C + n * 4) & LD32(0x060BB98C) ? 0x060FC0E8 + n * 4 : 0;
}

void f060ABD84(gaddr p, int t)
{
    unsigned int rel = t - LD32(p + 36);

    if ((unsigned int)LD32(p + 0x104) < rel) {
        ST32(p + 0x104, rel);
        ST32(p + 0x108, LD32(p + 16) - 1);
    }
    ST32(p + 232, LD32(p + 36) + LD32(p + 40));
    ST32(p + 24, LD32(p + 28));
    ST32(p + 8, 1);
    ST32(p + 32, 0);
}

void f060ACB0C(void)
{
    ST8(0xFFFFFE16, (LD8(0xFFFFFE16) & ~3) | 2);
    ST32(0x060FC174, 0);
    ST16(0x060FC178, 0);
}

int f060ACB2C(void)
{
    int v = ((LD8(0xFFFFFE12) & 255) << 8) | (LD8(0xFFFFFE13) & 255);

    if (v < LDU16(0x060FC178))
        ST32(0x060FC174, LD32(0x060FC174) + 0x100);
    ST16(0x060FC178, v);
    return (v >> 8) + LD32(0x060FC174);
}

void f060AD39C(void)
{
    ST8(0xFFFFFE16, (LD8(0xFFFFFE16) & ~3) | 2);
    ST32(0x060FC17C, 0);
    ST16(0x060FC180, 0);
}

void f060AD61C(void)
{
    ST32(0x060FC224, 0);
    ST32(0x060FC228, 0);
    ST32(0x060FC22C, 0);
}

int f060AD650(void)
{
    return LD32(0x060FC224);
}

void f060AD664(int a, int b)
{
    ST32(0x060FC228, a);
    ST32(0x060FC22C, b);
}

void f060AD66E(void)
{
}

int f060AD6D6(int start, int size)
{
    int aligned = (start + 3) & -4;

    ST32(0x060FC21C, aligned);
    size = aligned == start ? size & -4 : (size - 4) & -4;
    ST32(0x060FC220, size);
    if (aligned && size)
        return size;
    return GJUMP1(0x060AD62C, 0x704);
}

int f060ADA80(int a)
{
    int i = (a - 0x060FC190) >> 2;

    if ((unsigned int)i >= 32)
        return 0;
    return (LD32(0x060B12F8 + i * 4) & LD32(0x060FC210)) != 0;
}

int f060ADAAA(int rec)
{
    int n = (rec - 0x060FC190) >> 2;
    int mask;

    if (LD32(0x060FC18C) != 0x12345678)
        return GJUMP1(0x060AD62C, 0x103);
    if (!(LD32(0x060B12F8 + n * 4) & LD32(0x060FC210)))
        return GJUMP1(0x060AD62C, 0x201);
    GCALL1(0x060ADC8C, rec);
    mask = LD32(0x060FC210) & ~LD32(0x060B12F8 + n * 4);
    ST32(0x060FC210, mask);
    if (!mask)
        ST32(0x060FC184, 0);
    return mask;
}

int f060ADC76(gaddr p)
{
    return LD32(p) + 4;
}

int f060ADC7C(gaddr p)
{
    return LD32(p) + 48;
}

void f060AE1EE(int v)
{
    ST32(0x060FC214, v);
}

int f060AE200(void)
{
    return LD32(0x060FC214);
}

int f060AE25A(int n)
{
    if (!(LD32(0x060B12F8 + n * 4) & LD32(0x060FC210)))
        return 0;
    return 0x060FC190 + n * 4;
}

void f060AEB1C(void)
{
    int i = 0;

    do {
        ST16(0x060FC238 + i * 2, 0);
        ST16(0x060FC238 + (i + 32) * 2, i);
        ST16(0x060FC238 + (i + 64) * 2, 31);
    } while (AGAIN(++i < 32));
    i = 0;
    do {
        ST32(0x060FC2F8 + i * 4, 0);
        ST32(0x060FC2F8 + (i + 256) * 4, i);
        ST32(0x060FC2F8 + (i + 512) * 4, 255);
    } while (AGAIN(++i < 256));
}

/* Clears bit 31 of each of 1024 words whose 8-bit-per-channel colour is within tolerance of color. */
void f060AF17C(unsigned int color, int tolerance, gaddr table)
{
    int r = (color >> 16) & 255;
    int g = (color >> 8) & 255;
    int b = color & 255;
    int i = 0;

    do {
        int e = LD32(table + i * 4);
        int er = (e >> 16) & 255;
        int eg = (e >> 8) & 255;
        int eb = e & 255;

        if (ABS_DIFF(r, er) + ABS_DIFF(g, eg) + ABS_DIFF(b, eb) <= tolerance)
            ST32(table + i * 4, e & 0x7FFFFFFF);
    } while (AGAIN(++i < 1024));
}

/* Zeroes each of 1024 halfwords whose 5-bit-per-channel colour is within tolerance of the top five bits of each byte of color. */
void f060AF22C(unsigned int color, int tolerance, gaddr table)
{
    int r = (color >> 19) & 31;
    int g = (color >> 11) & 31;
    int b = (color >> 3) & 31;
    int i = 0;

    do {
        int e = LD16(table + i * 2);
        int er = (e >> 10) & 31;
        int eg = (e >> 5) & 31;
        int eb = e & 31;

        if (ABS_DIFF(r, er) + ABS_DIFF(g, eg) + ABS_DIFF(b, eb) <= tolerance)
            ST16(table + i * 2, 0);
    } while (AGAIN(++i < 1024));
}
