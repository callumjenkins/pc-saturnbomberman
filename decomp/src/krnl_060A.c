#include "krnl.h"

unsigned short f060A029A(unsigned short size)
{
    gaddr p = LD32(0x060FBFFC);
    gaddr prev = 0, best = 0, best_prev = 0;
    unsigned int best_size = 0xFFFF;
    unsigned int result = 0;
    unsigned int left;

    while (p) {
        POLL();
        if (size <= LDU16(p + 4) && best_size > LDU16(p + 4)) {
            best_size = LDU16(p + 4);
            best = p;
            best_prev = prev;
        }
        prev = p;
        p = LD32(p);
    }
    if (best) {
        ST16(best + 4, LD16(best + 4) - size);
        left = LDU16(best + 4);
        result = ((left << 5) + best - LD32(0x060FBFB4)) >> 3;
        if (left == 0 && best_prev)
            ST32(best_prev, LD32(best));
    }
    return result;
}

void f060A046C(int count, int extra, gaddr buf)
{
    ST32(0x060FC00C, buf);
    GCALL3(0x06094CA8, LD32(0x060FC00C), 0, count * 60 + extra * 48 + 48);
    buf = LD32(0x060FC00C);
    ST32(buf, buf + 48);
    ST32(buf + 4, count);
    ST32(buf + 8, LD32(buf) + count * 60);
    ST32(buf + 12, extra);
    ST32(buf + 20, -1);
    ST32(buf + 24, -1);
    ST32(buf + 44, 0);
    ST32(0x060FC010, 0);
    ST32(0x060FC014, 0);
    ST32(buf + 28, 0);
    ST32(buf + 32, 0x300);
    ST32(buf + 36, 0);
    ST32(buf + 40, 0);
}

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

int f060A0732(gaddr src, int unused, gaddr dst)
{
    ST8(dst, LD8(src + 1));
    ST8(dst + 1, LD8(src + 3));
    ST8(dst + 2, LD8(src + 5));
    ST8(dst + 3, LD8(src + 7));
    ST8(dst + 4, LD8(src + 9));
    ST8(dst + 5, LD8(src + 11));
    return GCALL1(0x060A0706, src);
}

void f060A08BA(gaddr p)
{
    ST32(p, 0);
    ST32(p + 4, 0);
    ST8(p + 58, 0);
}

int f060A0A0A(int a, int b, gaddr buf)
{
    if (!buf)
        return 0;
    GCALL3(0x060A046C, a, b, buf);
    return 1;
}

int f060A0CB2(void)
{
    return 0;
}

void f060A11E2(int value)
{
    ST32(LD32(0x060FC00C) + 32, value);
}

int f060A1300(gaddr ctx)
{
    int len;

    ST16(ctx + 56, LD16(ctx + 56) | 4);
    if (!LD32(ctx + 36))
        return 0;
    if (!LD32(ctx + 28)) {
        len = GCALL0(0x060AAD72);
        if (len >= LD32(ctx + 32))
            return len;
    } else {
        len = GCALL1(0x060AAD4E, LD32(LD32(ctx + 28) + 20));
        if (len < LD32(ctx + 32))
            return len;
    }
    ST16(ctx + 56, LD16(ctx + 56) | 8);
    return 56;
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

int f060A15BC(gaddr ctx)
{
    return LD32(LD32(ctx + 16) + 120) != 0;
}

int f060A1B68(gaddr ctx, int n, int limit, int mode)
{
    int result = 0;

    if (n >= 0) {
        result = GCALL2(0x060AAB92, ctx, n);
        ST32(ctx + 20, n);
    } else if (LD32(ctx + 20) <= limit && mode == 1 && !(LDU16(ctx + 56) & 2)) {
        GCALL4(0x060A1806, ctx, 0, limit, mode);
        result = GCALL1(0x060AAA6C, ctx);
        if (!result)
            ST16(ctx + 56, LD16(ctx + 56) | 2);
    }
    return result;
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

void f060A3250(gaddr ctx)
{
    int r;

    if (LD32(LD32(ctx) + 0x154) == 1) {
        if (LD32(LD32(ctx) + 0x168) == 0x060A32C8) {
            do {
                r = GCALL1(0x060A3464, ctx);
            } while (AGAIN(r == 2));
        } else if (LD32(LD32(ctx) + 0x168) == 0x060A34A6) {
            do {
                r = GCALL1(0x060A3658, ctx);
            } while (AGAIN(r == 2));
        }
        ST32(LD32(ctx) + 0x154, 0);
    }
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

void f060A3C1A(gaddr ctx, int value)
{
    if (!ctx) {
        GJUMP1(0x060AAE08, 0x504);
        return;
    }
    GJUMP2(0x060ABB48, ctx, value);
}

int f060A3C38(int value)
{
    return GJUMP1(0x060ABCAA, value);
}

void f060A3D00(gaddr ctx, int a, int b)
{
    gaddr rec;

    if (!ctx) {
        GJUMP1(0x060AAE08, 0x504);
        return;
    }
    if (b <= 0) {
        GJUMP1(0x060AAE08, 0x503);
        return;
    }
    rec = GCALL1(0x060AB316, ctx);
    ST32(rec + 12, a);
    ST32(rec + 16, b);
}

int f060A3DBE(gaddr ctx)
{
    if (!ctx) {
        GCALL1(0x060AAE08, 0x504);
        return -1;
    }
    return LD32(GCALL1(0x060AB31C, ctx) + 4);
}

int f060A3DF0(gaddr ctx)
{
    if (!ctx) {
        GCALL1(0x060AAE08, 0x504);
        return 0;
    }
    return GJUMP1(0x060AB324, ctx);
}

void f060A3E6C(gaddr ctx)
{
    int i = 0;
    gaddr rec;

    if (ctx) {
        ST32(GCALL1(0x060AB31C, ctx) + 8, 0);
        return;
    }
    do {
        rec = GCALL1(0x060ABD4E, i);
        if (rec)
            ST32(GCALL1(0x060AB31C, rec) + 8, 0);
    } while (AGAIN(++i < 32));
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

void f060A4014(gaddr ctx, int value)
{
    if (!ctx) {
        GJUMP1(0x060AAE08, 0x504);
        return;
    }
    GJUMP2(0x060ABB16, ctx, value);
}

void f060A40C0(void)
{
}

void f060A41E2(gaddr ctx)
{
    if (!ctx) {
        GJUMP1(0x060AD62C, 0x504);
        return;
    }
    if (LD32(LD32(ctx) + 0x18C) != 1)
        GCALL1(0x060AD62C, 0x202);
    GJUMP1(0x060ADAAA, ctx);
}

void f060A45E4(void)
{
    ST32(0x060FC03C, 0);
    GCALL0(0x060AD718);
}

void f060A47FE(gaddr ctx)
{
    if (!ctx) {
        GJUMP1(0x060AD62C, 0x504);
        return;
    }
    GJUMP1(0x060ADC8C, ctx);
}

void f060A48A8(gaddr ctx, int value)
{
    if (!ctx) {
        GJUMP1(0x060AD62C, 0x504);
        return;
    }
    GJUMP2(0x060AD672, ctx, value);
}

void f060A49F0(int a, int b)
{
    GJUMP2(0x060AD6D6, a, b);
}

int f060A4AF4(gaddr ctx)
{
    if (!ctx) {
        GCALL1(0x060AD62C, 0x504);
        return -1;
    }
    return LD32(GCALL1(0x060ADC7C, ctx) + 4);
}

void f060A4BDE(void)
{
}

void f060A4C08(void)
{
}

void f060A5058(gaddr src, gaddr dst)
{
    ST8(dst, LD8(src));
    ST8(dst + 4, LD8(src + 1));
    ST8(dst + 5, LD8(src + 2));
    ST8(dst + 6, LD8(src + 3));
    ST8(dst + 7, LD8(src + 4));
    ST32(dst + 8, LD32(src + 4) & 0xFFFFFF);
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

void f060A51F4(gaddr desc, int ch)
{
    unsigned int mask = LD32(desc + 36);
    gaddr regs = (ch << 4) - 128;
    unsigned int chcr;

    if ((mask & 1) == 1)
        ST32(regs, LD32(desc));
    if ((mask & 2) == 2)
        ST32(regs + 4, LD32(desc + 4));
    if ((mask & 4) == 4)
        ST32(regs + 8, LD32(desc + 8));
    chcr = LD32(regs + 12);
    if ((mask & 8) == 8)
        chcr = (chcr & 0xFFFF3FFF) | HELPER(LD32(desc + 12) << 14);
    if ((mask & 16) == 16)
        chcr = (chcr & 0xFFFFCFFF) | (LD32(desc + 16) << 12);
    if ((mask & 32) == 32)
        chcr = (chcr & 0xFFFFF3FF) | LD32(desc + 20);
    if ((mask & 64) == 64)
        chcr = (chcr & 0xFFFFFDFF) | LD32(desc + 24);
    chcr &= ~0x18;
    if ((mask & 128) == 128)
        chcr = (chcr & ~4) | LD32(desc + 28);
    if ((mask & 0x200) == 0x200)
        chcr &= ~2;
    ST32(regs + 12, chcr);
    if ((mask & 0x100) == 0x100)
        ST8(ch - 399, LD32(desc + 32));
}

void f060A52E8(int ch)
{
    ST32((ch << 4) - 116, LD32((ch << 4) - 116) | 1);
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

int f060A532A(int ch)
{
    return LD32((ch << 4) - 116) & 2;
}

void f060A5338(gaddr desc, int ch)
{
    gaddr regs = 0x25FE0000 + (ch << 5);

    if ((LD32(desc + 36) & 1) == 1)
        ST32(regs, LD32(desc));
    if ((LD32(desc + 36) & 2) == 2)
        ST32(regs + 4, LD32(desc + 4));
    ST32(regs + 8, LD32(desc + 8));
    ST32(regs + 12, LD32(desc + 12) | LD32(desc + 16));
    ST32(regs + 20, (LD32(desc + 24) << 16) | LD32(desc + 20) | (LD32(desc + 28) << 8) | LD32(desc + 32));
}

int f060A56CA(int n, int base)
{
    return n * 12 + base;
}

int f060A56D8(int a, int b)
{
    return a * 24 + b;
}

unsigned char f060A56FA(int a, int b)
{
    return LD8(a * 24 + b + 11);
}

void f060A589C(gaddr dst, gaddr src)
{
    ST32(dst, src);
    ST32(dst + 4, LD32(0x060FA8BC) + 0x460);
    ST32(dst + 8, -1);
    ST32(dst + 16, LD32(src + 32));
    ST32(dst + 12, 0);
}

void f060A5E26(gaddr dst, gaddr src)
{
    ST32(dst, LD32(src));
    ST32(dst + 4, LD32(src + 4));
    ST8(dst + 10, LD8(src + 25));
    ST8(dst + 11, LD8(src + 9));
    ST8(dst + 8, LD8(src + 10));
    ST8(dst + 9, LD8(src + 11));
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

void f060A61E2(gaddr ctx, int unused, int c, int d)
{
    gaddr s = ctx + 108;
    int n = LD32(s + 24) - LD32(s + 28);
    int per;

    if (LD32(s + 20) <= n)
        n = LD32(s + 20);
    if (LD32(s + 44) > 1) {
        if (LD32(s + 12))
            n = DIVS(LD32(LD32(s + 12) + 8) - LD32(s + 32), LD32(s + 44));
        per = DIVS(GCALL1(0x060A66F2, s), LD32(s + 44));
        if (n >= per)
            n = per;
    }
    if (!LD32(s + 12)) {
        ST32(s + 12, GCALL4(0x060A5E7C, ctx, n, c, d));
        if (LD32(s + 12))
            ST32(s + 32, 0);
    }
}

void f060A625E(gaddr rec)
{
    int n;
    int rest;

    if (LD32(rec + 44) > 1) {
        n = LD32(LD32(rec + 12) + 8);
    } else {
        rest = LD32(LD32(rec + 12) + 8) - LD32(rec + 32);
        if (rest >= GCALL1(0x060A66F2, rec))
            n = GCALL1(0x060A66F2, rec);
        else
            n = rest;
    }
    ST32(rec + 16, GCALL2(0x060A6724, rec, n));
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

gaddr f060A6724(gaddr src, int n)
{
    gaddr slot = LD32(0x060FA8BC) + 0x44C;

    if (LD32(slot + 16))
        return 0;
    ST32(slot, LD32(src) + LD32(src + 8));
    ST32(slot + 4, 1);
    ST32(slot + 8, n);
    ST32(slot + 16, 1);
    return slot;
}

void f060A674C(gaddr dst, gaddr src)
{
    if (LD32(dst + 56) != 4)
        ST32(dst + 8, LD32(dst + 8) + LD32(src + 8));
    ST32(src + 16, 0);
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

int f060A750A(gaddr ctx)
{
    return GJUMP1(0x060A7902, LD32(ctx + 28));
}

void f060A7516(gaddr ctx)
{
    GJUMP1(0x060A78E0, LD32(ctx + 28));
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

int f060AA976(gaddr ctx)
{
    return GCALL1(0x060A66F2, LD32(ctx + 16) + 108) == 0;
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

void f060AB1B0(gaddr ctx, gaddr out_pos, gaddr out_len, gaddr out_avail)
{
    gaddr s = LD32(ctx) + 52;
    int avail;

    if ((unsigned int)LD32(s + 80) >= (unsigned int)LD32(s + 92) && LD32(s + 4) >= 3)
        ST32(s + 80, LD32(s + 80) - LD32(s + 100));
    avail = LD32(s + 100) + LD32(s + 76) - LD32(s + 72);
    ST32(out_avail, avail);
    if (avail <= 0) {
        ST32(out_len, 0);
        ST32(out_pos, 0);
        return;
    }
    if ((unsigned int)LD32(s + 80) >= (unsigned int)LD32(s + 84))
        ST32(out_len, LD32(s + 92) - LD32(s + 80));
    else
        ST32(out_len, LD32(out_avail));
    ST32(out_pos, LD32(s + 80));
}

void f060AB228(gaddr ctx, int n)
{
    gaddr s = LD32(ctx) + 52;

    ST32(s + 72, LD32(s + 72) + n);
    ST32(s + 80, LD32(s + 80) + n);
    if ((unsigned int)LD32(s + 80) >= (unsigned int)LD32(s + 92) && LD32(s + 4) >= 3)
        ST32(s + 80, LD32(s + 80) - LD32(s + 100));
}

void f060AB268(gaddr ctx, unsigned int off, unsigned int len)
{
    gaddr s = LD32(ctx) + 52;

    if (off + len > (unsigned int)LD32(s + 92))
        GJUMP3(0x060B00BC, LD32(s + 92), LD32(s + 88), (len + off - LD32(s + 92) + 3) >> 2);
}

void f060AB2BC(gaddr ctx, int n)
{
    gaddr s = LD32(ctx) + 52;

    ST32(s + 76, LD32(s + 76) + n);
    ST32(s + 84, LD32(s + 84) + n);
    if ((unsigned int)LD32(s + 84) >= (unsigned int)LD32(s + 92))
        ST32(s + 84, LD32(s + 84) - LD32(s + 100));
}

void f060AB2F2(gaddr ctx, int n)
{
    gaddr s = LD32(ctx) + 52;

    if (!LD32(s + 160)) {
        GJUMP2(0x060AB2BC, ctx, n);
        return;
    }
    ST32(s + 168, LD32(s + 168) + n);
}

int f060AB316(gaddr p)
{
    return LD32(p);
}

int f060AB31C(gaddr p)
{
    return LD32(p) + 52;
}

int f060AB324(gaddr ctx)
{
    return LD32(LD32(ctx) + 0x140);
}

void f060AB32C(gaddr ctx)
{
    ST32(LD32(ctx) + 52 + 4, 2);
}

void f060AB338(gaddr ctx)
{
    gaddr data = LD32(ctx);
    gaddr dev = LD32(data + 0x140);
    gaddr s = data + 52;
    int mode;
    gaddr src, dst, e;

    if (!LD32(s + 156))
        return;
    if (!LD32(s + 160))
        return;
    mode = GCALL0(0x060AEAC4);
    if (mode == 2) {
        POLL();
        return;
    }
    if (mode == 1) {
        POLL();
        GCALL1(0x060AAE08, 0x802);
    }
    src = LD32(s + 176 + (signed char)((signed char)LD32(s + 172) * 12));
    dst = LD32(s + 112) + src;
    if (src == LD32(data + 32) || src == LD32(s + 116)) {
        if ((unsigned char)LD8(dev + 38) == 16)
            ST16(dst - 2, LD16(src));
        else
            ST8(dst - 1, LD8(src));
    }
    if (!LD32(s + 172)) {
        GCALL2(0x060B0030, ctx, LD32(s + 164));
        GCALL2(0x060AB2BC, ctx, LD32(s + 168));
        ST32(s + 164, 0);
        ST32(s + 168, 0);
        ST32(s + 160, 0);
        ST32(0x060FC16C, 0);
        return;
    }
    ST32(s + 172, LD32(s + 172) - 1);
    e = s + 176 + (signed char)((signed char)LD32(s + 172) * 12);
    GJUMP3(0x060AEA3C, LD32(e), LD32(e + 4), LD32(e + 8));
}

void f060AB49C(gaddr ctx, int b, int c, int d)
{
    gaddr s = LD32(ctx) + 52;

    GCALL4(0x060AB456, ctx, b, c, d);
    if (LD32(s + 4) == 4)
        GCALL4(0x060AFDF0, ctx, b, c, d);
    ST32(s + 4, 5);
}

int f060AB804(gaddr ctx)
{
    gaddr data = LD32(ctx);
    gaddr dev = LD32(data + 0x140);
    gaddr s = data + 52;
    unsigned int i;
    int longest = 0;
    int v;

    if ((unsigned int)LD32(s + 72) < 8)
        return -1;
    if (GCALL3(0x06095158, LD32(data), 0x060B12CC, 4)) {
        GCALL1(0x060AAE08, 0x303);
        return -1;
    }
    ST32(s + 20, LD32(dev + 4));
    if ((unsigned int)LD32(dev + 4) > (unsigned int)LD32(s + 100)) {
        GCALL1(0x060AAE08, 0x302);
        return -1;
    }
    if ((unsigned int)LD32(s + 72) < (unsigned int)LD32(s + 20))
        return -1;
    ST32(s + 96, (LD32(s + 20) + 0x7FF) & -2048);
    ST32(s + 108, (unsigned char)LD8(dev + 37) ? LD32(data + 20) : 0);
    ST32(s + 44, 1);
    ST32(s + 48, 1);
    for (i = 0; i < (unsigned int)LD32(dev + 60); i++) {
        POLL();
        if (LD32(dev + 64 + i * 16 + 8) == -1 && LD32(s + 108))
            ST32(s + 48, 0);
        if (LD32(dev + 64 + i * 16 + 8) != -1)
            ST32(s + 44, 0);
    }
    for (i = 1; i < (unsigned int)LD32(dev + 60); i++) {
        POLL();
        v = LD32(dev + 64 + i * 16 + 4);
        if (longest < v)
            longest = v;
    }
    if ((unsigned int)LD32(s + 104) < (unsigned int)longest) {
        GCALL1(0x060AAE08, 0x301);
        return -1;
    }
    ST32(s + 104, LD32(s + 104) - ((LD32(s + 104) - longest) & -2048));
    if ((unsigned int)LD32(data + 4)
        < LD32(s + 104) + LD32(s + 96) + (LD32(dev + 68) > longest ? LD32(dev + 68) : longest)) {
        GCALL1(0x060AAE08, 0x302);
        return -1;
    }
    ST32(s + 100, LD32(data + 4) - LD32(s + 104) - LD32(s + 96));
    ST32(s + 88, LD32(data) + LD32(s + 96));
    ST32(s + 92, LD32(s + 88) + LD32(s + 100));
    if (!LD32(s + 52)) {
        ST32(s + 52, (unsigned char)LD8(dev + 36));
        GCALL2(0x060AB726, ctx, LD32(s + 52));
    }
    ST32(s + 124, (unsigned int)LD32(dev + 40) >> 16);
    if ((unsigned char)LD8(dev + 38) == 8)
        ST32(s + 112, LD32(data + 36));
    else
        ST32(s + 112, LD32(data + 36) << 1);
    ST32(s + 116, ((unsigned int)LD32(s + 112) >> 1 << 1) + LD32(data + 32));
    ST32(s + 76, LD32(s + 76) + LD32(s + 20));
    ST32(s + 84, LD32(s + 84) + LD32(s + 20));
    ST32(s + 4, 3);
    return 0;
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

int f060AC62E(gaddr ctx)
{
    gaddr data = LD32(ctx);
    gaddr dev = LD32(data + 0x140);
    gaddr s = data + 52;
    unsigned int next;
    gaddr e;

    if (LD32(s + 64))
        return 0;
    next = LD32(s + 12) + 1;
    if (next >= (unsigned int)LD32(dev + 60))
        return 0;
    e = dev + 64 + next * 16;
    if (LD32(e + 8) < 0)
        return 0;
    return (unsigned int)(LD32(s + 20) + LD32(e) + LD32(e + 4)) <= (unsigned int)LD32(s + 72);
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

int f060ACC02(gaddr ctx)
{
    gaddr s = LD32(ctx) + 52;
    int mode = LD32(s + 4);
    int pos;
    int d, a, r;

    POLL();
    if (mode == -1 || mode == 0)
        return -1;
    if (mode >= 2 && mode <= 5)
        pos = GCALL1(0x060ACBB8, ctx);
    else
        pos = 0;
    d = LD32(s + 152);
    a = LD32(s + 124);
    r = (LD32(s + 128) << 12) + DIVS(pos, d) * a + DIVU(a, d) * MODS(pos, d) + DIVU(MODU(a, d) * MODS(pos, d), d);
    return r & -4;
}

void f060ACCB2(gaddr ctx, gaddr scaled, gaddr raw)
{
    gaddr s = LD32(ctx) + 52;
    gaddr dev = LD32(LD32(ctx) + 0x140);
    int mode = LD32(s + 4);
    unsigned int tv;
    int n, m, a, d, r;

    if (mode < -1 || mode > 5)
        return;
    POLL();
    if (mode <= 0) {
        ST32(raw, -1);
        ST32(scaled, -1);
        return;
    }
    if (mode == 2 || mode == 3) {
        ST32(raw, 0);
        ST32(scaled, 0);
        return;
    }
    if (LD32(s + 48)) {
        n = (mode == 1 ? LD32(s + 0xE4) : LD32(0x060FC0E4)) - LD32(s + 0xE0);
        ST32(raw, n);
        m = n << 1;
        tv = LDU16(VIDEO_MODE);
        d = VIDEO_DIV(tv);
        a = LD32(dev + 56) << 5;
        ST32(scaled, DIVS(m, d) * a + DIVU(a, d) * MODS(m, d) + DIVU(MODU(a, d) * MODS(m, d), d));
        return;
    }
    if (mode == 1)
        n = LD32(s + 0x90) - LD32(s + 0x8C);
    else
        n = GCALL1(0x060ACC02, ctx) + LD32(s + 0x90) - LD32(s + 0x8C);
    ST32(raw, n);
    d = LD32(s + 124);
    a = LD32(dev + 56);
    r = MODU(n, d);
    ST32(scaled, DIVU(n, d) * a + DIVU(a, d) * r + DIVU(MODU(a, d) * r, d));
}

void f060AD39C(void)
{
    ST8(0xFFFFFE16, (LD8(0xFFFFFE16) & ~3) | 2);
    ST32(0x060FC17C, 0);
    ST16(0x060FC180, 0);
}

int f060AD4B8(gaddr ctx)
{
    gaddr s = LD32(ctx) + 48;
    int mode = LD32(s + 4);
    int pos, d, a, r;

    POLL();
    if (mode == -1 || mode == 0)
        return -1;
    if (mode >= 2 && mode <= 5)
        pos = GCALL1(0x060AD46C, ctx);
    else
        pos = 0;
    d = LD32(s + 124);
    a = LD32(s + 44);
    r = MODS(pos, d);
    return ((LD32(s + 100) << 12) + DIVS(pos, d) * a + DIVS(a, d) * r + DIVS(MODS(a, d) * r, d)) & -4;
}

void f060AD5C8(gaddr ctx, gaddr out)
{
    gaddr s = LD32(ctx) + 48;
    int mode = LD32(s + 4);

    if (mode < -1 || mode > 5)
        return;
    POLL();
    if (mode <= 0)
        ST32(out, -1);
    else if (mode == 1)
        ST32(out, LD32(s + 116));
    else
        ST32(out, GCALL1(0x060AD4B8, ctx) + LD32(s + 116));
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

void f060AD672(gaddr ctx, int value)
{
    gaddr s = LD32(ctx) + 48;

    ST32(s + 144, value);
    if (LD32(s + 40) > 8)
        ST32(s + 148, LD32(s + 144) << 1);
    else
        ST32(s + 148, LD32(s + 144));
    ST32(s + 152, DIVS(LD32(s + 144) + 223, 224));
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

void f060AD88C(gaddr ctx)
{
    gaddr base = LD32(ctx);
    gaddr s = base + 48;

    ST32(base, 0x574F524B);
    ST32(s, 0x53544154);
    ST32(s + 20, 0x494E464F);
    ST32(s + 56, 0x52494E47);
    ST32(s + 84, 0x50434D20);
    ST32(s + 156, 0x53445256);
    ST32(s + 208, 0x434F5059);
    ST32(s + 0x128, 0x56424C20);
    ST32(s + 0x13C, 0x45525220);
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

void f060ADBA8(gaddr ctx, gaddr out_pos, gaddr out_len, gaddr out_avail)
{
    gaddr data = LD32(ctx);
    gaddr s = data + 48;
    int avail = LD32(data + 8) + LD32(s + 64) - LD32(s + 60);

    ST32(out_avail, avail);
    if (avail <= 0) {
        ST32(out_len, 0);
        ST32(out_pos, 0);
        return;
    }
    if ((unsigned int)LD32(s + 72) >= (unsigned int)LD32(s + 76))
        ST32(out_len, LD32(s + 68) - LD32(s + 72));
    else
        ST32(out_len, LD32(out_avail));
    ST32(out_pos, LD32(s + 72));
}

void f060ADBF6(gaddr ctx, int n)
{
    gaddr data = LD32(ctx);
    gaddr s = data + 48;

    if (n <= 0)
        return;
    ST32(s + 60, LD32(s + 60) + n);
    ST32(s + 72, LD32(s + 72) + n);
    if ((unsigned int)LD32(s + 72) >= (unsigned int)LD32(s + 68))
        ST32(s + 72, LD32(s + 72) - LD32(data + 8));
}

void f060ADC2A(gaddr ctx, int n)
{
    gaddr data = LD32(ctx);
    gaddr s = data + 48;

    ST32(s + 64, LD32(s + 64) + n);
    ST32(s + 76, LD32(s + 76) + n);
    if ((unsigned int)LD32(s + 76) >= (unsigned int)LD32(s + 68))
        ST32(s + 76, LD32(s + 76) - LD32(data + 8));
}

int f060ADC76(gaddr p)
{
    return LD32(p) + 4;
}

int f060ADC7C(gaddr p)
{
    return LD32(p) + 48;
}

void f060ADC82(gaddr ctx)
{
    ST32(LD32(ctx) + 48 + 4, 2);
}

void f060ADC8C(gaddr ctx)
{
    gaddr s = LD32(ctx) + 48;

    if (LD32(s + 4) == 4)
        GCALL1(0x060B070E, ctx);
    ST32(s + 4, 5);
    ST32(s + 16, 0);
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

int f060AE2FC(gaddr ctx)
{
    gaddr s = LD32(ctx) + 48;

    if (LD32(s + 60) == LD32(s + 64))
        return 1;
    if (LD32(s + 48) == -1)
        return 0;
    return LD32(s + 48) <= LD32(s + 104);
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
