#include "krnl.h"

void f060A0018(int unit, unsigned short flags, unsigned short mask, unsigned short pos)
{
    FRAME(sp, 0);
    int id = LDU16(sp + 2);
    gaddr coords = LD32(sp + 4);
    int ext = LDU16(sp + 10);
    gaddr rec = LD32(0x060FBF84) + id * 10;
    gaddr cmd;
    int attr;

    if (LD32(0x060FBF98))
        GCALL1(0x060AA50C, unit);
    cmd = LD32(0x060FC004);
    ST32(0x060FC004, cmd + 32);
    ST32(0x060FBF90, LD32(0x060FBF90) + 1);
    ST16(cmd, 1 | flags);
    ST16(cmd + 8, LD16(rec));
    ST16(cmd + 10, LD16(rec + 2));
    attr = (mask & ~56) | LDU16(rec + 4);
    ST16(cmd + 4, attr);
    if (pos == 0xFFFF)
        pos = LD16(rec + 6);
    if ((attr & 56) == 8)
        ST16(cmd + 6, LDU16(0x060FBFD0) + (pos << 2));
    else
        ST16(cmd + 6, pos);
    ST16(cmd + 12, LD16(coords));
    ST16(cmd + 14, LD16(coords + 2));
    if ((flags & 0xF00) == 0) {
        ST16(cmd + 20, LD16(coords + 4));
        ST16(cmd + 22, LD16(coords + 6));
    } else {
        ST16(cmd + 16, LD16(coords + 4));
        ST16(cmd + 18, LD16(coords + 6));
    }
    ST16(cmd + 28, ext == 0xFFFF ? 0 : LDU16(0x060FC008) + ext);
}

void f060A0158(int unit, unsigned short flags, unsigned short mask, unsigned short pos)
{
    FRAME(sp, 0);
    int id = LDU16(sp + 2);
    gaddr coords = LD32(sp + 4);
    int ext = LDU16(sp + 10);
    gaddr rec = LD32(0x060FBF84) + id * 10;
    gaddr cmd;
    int attr;

    if (LD32(0x060FBF98))
        GCALL1(0x060AA50C, unit);
    cmd = LD32(0x060FC004);
    ST32(0x060FC004, cmd + 32);
    ST32(0x060FBF90, LD32(0x060FBF90) + 1);
    ST16(cmd, flags | 2);
    ST16(cmd + 8, LD16(rec));
    ST16(cmd + 10, LD16(rec + 2));
    attr = (mask & ~56) | LDU16(rec + 4);
    ST16(cmd + 4, attr);
    if (pos == 0xFFFF)
        pos = LD16(rec + 6);
    if ((attr & 56) == 8)
        ST16(cmd + 6, LDU16(0x060FBFD0) + (pos << 2));
    else
        ST16(cmd + 6, pos);
    GCALL3(0x060949E0, cmd + 12, coords, 16);
    ST16(cmd + 28, ext == 0xFFFF ? 0 : LDU16(0x060FC008) + ext);
}

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

void f060A0338(unsigned short block, unsigned short count)
{
    gaddr base = LD32(0x060FBFB4);
    gaddr end = base + 0x80000;
    gaddr node = base + (block << 3);
    gaddr node_end = node + (count << 5);
    gaddr prev = base;
    gaddr next = LD32(0x060FBFFC);
    gaddr prev_end;

    for (;;) {
        if (prev > node || node >= next) {
            if (next == end)
                return;
            prev = next;
            next = LD32(next);
            if (next == 0)
                next = end;
            POLL();
            continue;
        }
        if (prev == base) {
            if (node_end == next) {
                ST32(node, LD32(next));
                ST16(node + 4, LDU16(next + 4) + count);
            } else {
                ST32(node, LD32(0x060FBFFC));
                ST16(node + 4, count);
            }
            ST32(0x060FBFFC, node);
            return;
        }
        prev_end = prev + (LDU16(prev + 4) << 5);
        if (next == end) {
            if (prev_end == node) {
                ST16(prev + 4, LD16(prev + 4) + count);
            } else {
                ST32(prev, node);
                ST32(node, 0);
                ST16(node + 4, count);
            }
        } else if (prev_end == node && node_end < next) {
            ST16(prev + 4, LD16(prev + 4) + count);
        } else if (prev_end < node && node_end == next) {
            ST32(node, LD32(next));
            ST16(node + 4, LDU16(next + 4) + count);
            ST32(prev, node);
        } else if (prev_end < node && node_end < next) {
            ST32(node, next);
            ST16(node + 4, count);
            ST32(prev, node);
        } else {
            ST32(prev, LD32(next));
            ST16(prev + 4, LD16(prev + 4) + count);
            ST16(prev + 4, LD16(next + 4) + LD16(prev + 4));
        }
        return;
    }
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

gaddr f060A04EE(void)
{
    gaddr pool = LD32(0x060FC00C);
    gaddr node = LD32(pool);
    int i;

    for (i = 0; i < LD32(pool + 4); i++, node += 60) {
        POLL();
        if (LD8(node + 58) == 0) {
            ST32(node, 0);
            ST32(node + 4, 0);
            ST32(node + 8, 0);
            ST32(node + 12, 0);
            ST32(node + 16, 0);
            ST32(node + 20, 150);
            ST32(node + 24, 0x101);
            ST32(node + 28, 0);
            ST32(node + 32, 0);
            ST32(node + 36, 0);
            ST32(node + 40, 0);
            ST32(node + 44, 0x7FFFFFFF);
            ST32(node + 48, 0);
            ST32(node + 52, -1);
            ST16(node + 56, 0);
            ST8(node + 58, 1);
            return node;
        }
    }
    return 0;
}

gaddr f060A0558(void)
{
    gaddr pool = LD32(0x060FC00C);
    gaddr node = LD32(pool + 8);
    int i;

    for (i = 0; i < LD32(pool + 12); i++, node += 48) {
        POLL();
        if (LD8(node + 45) == 0)
            return node;
    }
    return 0;
}

int f060A057E(gaddr owner)
{
    FRAME(sp, 16);
    gaddr node = LD32(owner + 12);

    if (node == 0)
        return 150;
    GCALL3(0x060AAA1C, LD32(node + 20), sp - 12, sp - 16);
    return LD32(sp - 16);
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

void f060A09BC(gaddr owner)
{
    FRAME(sp, 32);
    gaddr best = 0;
    int best_value = 150;
    gaddr node;

    for (node = LD32(owner + 4); node; node = LD32(node + 12)) {
        POLL();
        if (LD32(LD32(node + 20) + 28) == 0) {
            GCALL3(0x060AAA1C, LD32(node + 20), sp - 28, sp - 32);
            if (best_value < LD32(sp - 32)) {
                best = node;
                best_value = LD32(sp - 32);
            }
        }
    }
    ST32(owner + 12, best);
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

int f060A11EA(int value)
{
    gaddr rec = LD32(0x060FC00C);

    if (LD32(rec + 28))
        return 0;
    ST32(rec + 28, value);
    return 1;
}

int f060A12CC(gaddr list)
{
    gaddr node;

    if (LD32(list + 8) != 0 || LD32(list + 4) != 0)
        return 0;
    for (node = LD32(list); node; node = LD32(node + 8)) {
        POLL();
        if (!(LD8(node + 44) & 2))
            return 0;
    }
    return 1;
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

void f060A1806(gaddr list)
{
    FRAME(sp, 24);
    int limit = LD32(list + 20);
    gaddr node;
    int flags;

    for (node = LD32(list); node; node = LD32(node + 8)) {
        POLL();
        GCALL3(0x060AAA1C, LD32(node + 20), sp - 24, sp - 20);
        flags = LDU8(node + 44);
        if ((flags & 2) || (LD32(sp - 24) >= limit && !(flags & 8))) {
            ST8(node + 44, LD8(node + 44) | 1);
            ST32(LD32(node + 16) + 8, 1);
        }
    }
}

int f060A191E(gaddr list, int limit)
{
    FRAME(sp, 28);
    gaddr node;
    int start;

    if (limit < LD32(list + 20))
        limit = LD32(list + 20);
    for (node = LD32(list); node; node = LD32(node + 8)) {
        POLL();
        if (LD8(node + 44) & 8)
            continue;
        GCALL3(0x060AAA1C, LD32(node + 20), sp - 28, sp - 24);
        start = LD32(sp - 28);
        if (start > limit)
            return start;
        if (LD32(sp - 24) >= limit)
            return -1;
    }
    return -1;
}

int f060A197E(gaddr p)
{
    FRAME(sp, 16);

    GCALL3(0x060AAA1C, LD32(LD32(p + 8) + 20), sp - 16, sp - 12);
    return LD32(sp - 16);
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

int f060A1D3E(gaddr task, int lo, int limit, int wait)
{
    FRAME(sp, 24);
    int key = LD32(LD32(task) + 20);
    int flags = LDU8(task + 44);
    int deadline;

    if ((flags & 8) && wait == 0)
        return 0x100;
    if (key <= limit && LD32(LD32(task + 20) + 28) == 0) {
        if (!(flags & 1) && (flags & 4))
            return 32;
        GCALL1(0x060A1356, GCALL2(0x060A6CE6, 0, sp - 24));
        if (!(LD32(sp - 24) & 8))
            return 0x102;
        if (wait == 0)
            return 0x103;
    } else if ((flags & 1) && wait == 0) {
        return 0x100;
    }
    deadline = LD32(task + 40);
    if (deadline == 0x7FFFFFFF)
        deadline = GCALL1(0x060A057E, LD32(task));
    if (LD32(LD32(task + 16) + 156) == 0)
        return 0x103;
    if (key < lo || key >= deadline)
        return GCALL1(0x060AA976, task) == 1 ? 0x103 : 0x102;
    return 0x103;
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

int f060A30EA(int a, int b, int c, int d)
{
    FRAME(sp, 72);
    gaddr req = sp - 68;

    ST32(req, d);
    ST32(req + 4, LD32(sp));
    ST32(req + 8, 0);
    ST32(req + 12, 0);
    ST32(req + 16, 0);
    ST32(req + 20, 1);
    ST32(req + 24, 0);
    ST32(req + 28, 0);
    ST32(req + 32, LD32(sp + 4));
    ST32(req + 36, LD32(sp + 8));
    ST32(req + 40, 0);
    ST32(req + 44, 7);
    return GCALL3(0x060AAF8A, b, c, req);
}

void f060A317A(gaddr obj)
{
    GJUMP1(0x060AB32C, obj);
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

void f060A33D8(int a, int b, int c)
{
    FRAME(sp, 72);
    gaddr req = sp - 72;
    gaddr mode = sp - 32;

    GCALL1(0x060A52FA, 1);
    ST32(mode, 0);
    ST32(mode + 4, 1);
    ST32(mode + 8, 15);
    GCALL1(0x060A51AC, mode);
    ST32(req, b);
    ST32(req + 4, a);
    ST32(req + 8, c);
    ST32(req + 12, 1);
    ST32(req + 16, 0);
    ST32(req + 20, 0x800);
    ST32(req + 24, 0x200);
    ST32(req + 28, 0);
    ST32(req + 36, 0x2FF);
    GCALL2(0x060A51F4, req, 1);
    GCALL1(0x060A52E8, 1);
    ST32(0x060FC024, a);
    ST32(0x060FC028, c << 2);
}

int f060A3464(void)
{
    FRAME(sp, 12);

    GCALL1(0x060A5318, sp - 12);
    if (LD32(sp - 12) == 4)
        return 1;
    if (GCALL1(0x060A532A, 1) == 0)
        return 2;
    GCALL2(0x060A5180, LD32(0x060FC024), LD32(0x060FC028));
    return 0;
}

void f060A3900(void)
{
    ST32(0x060FC038, 0);
    GCALL0(0x060AAE84);
}

void f060A3914(int a, int b, int c, int d)
{
    GJUMP4(0x060AAEC2, a, b, c, d);
}

void f060A3AE0(int a, int b, int c, int d)
{
    if (a)
        GJUMP4(0x060AB49C, a, b, c, d);
    else
        GJUMP4(0x060AAE08, 0x504, b, c, d);
}

void f060A3AF4(int a, int b, int c, int d)
{
    if (a)
        GJUMP4(0x060AB6BE, a, b, c, d);
    else
        GJUMP4(0x060AAE08, 0x504, b, c, d);
}

void f060A3BFC(int a, int b, int c, int d)
{
    if (a)
        GJUMP2(0x060ABB28, a, b);
    else
        GJUMP4(0x060AAE08, 0x504, b, c, d);
}

void f060A3C1A(gaddr ctx, int value)
{
    if (!ctx) {
        GJUMP1(0x060AAE08, 0x504);
        return;
    }
    GJUMP2(0x060ABB48, ctx, value);
}

void f060A3C38(int value)
{
    GJUMP1(0x060ABCAA, value);
}

int f060A3CDE(void)
{
    return GJUMP0(0x060ABCCC);
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

int f060A3E10(int index)
{
    int i = 0;
    int entry;

    if (index)
        return LD32(GCALL1(0x060AB31C, index) + 8);
    do {
        entry = GCALL1(0x060ABD4E, i);
        if (entry && LD32(GCALL1(0x060AB31C, entry) + 8) == 1)
            return 1;
        i++;
    } while (AGAIN(i < 32));
    return 0;
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

int f060A3ED4(int a, int b, int c, int d)
{
    FRAME(sp, 16);

    if (a) {
        GCALL4(0x060AB1B0, a, sp - 16, b, c);
        return LD32(sp - 16);
    }
    GCALL4(0x060AAE08, 0x504, b, c, d);
    return 0;
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

void f060A4060(int a, int b, int c, int d)
{
    if (a)
        GJUMP2(0x060ABB6C, a, b);
    else
        GJUMP4(0x060AAE08, 0x504, b, c, d);
}

void f060A4074(int a, int b, int c, int d)
{
    if (a)
        GJUMP4(0x060AAE52, a, b, c, d);
    else
        GJUMP4(0x060AAE08, 0x504, b, c, d);
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

int f060A4280(int unused, int a, int b, int c)
{
    FRAME(sp, 52);
    gaddr req = sp - 48;

    ST32(req, b);
    ST32(req + 4, c);
    ST32(req + 8, LD32(sp));
    ST32(req + 12, LD32(sp + 4));
    ST32(req + 16, 1);
    ST32(req + 20, 1);
    ST32(req + 24, 0);
    ST32(req + 28, 7);
    ST32(req + 32, 0);
    ST32(req + 36, 0x1000);
    ST32(req + 40, 0x800);
    return GCALL4(0x060AD8F0, a, req, b, c);
}

void f060A45E4(void)
{
    ST32(0x060FC03C, 0);
    GCALL0(0x060AD718);
}

void f060A45F8(int a, int b, int c, int d)
{
    GJUMP4(0x060AD790, a, b, c, d);
}

void f060A47FE(gaddr ctx)
{
    if (!ctx) {
        GJUMP1(0x060AD62C, 0x504);
        return;
    }
    GJUMP1(0x060ADC8C, ctx);
}

void f060A4810(int a, int b, int c, int d)
{
    if (a)
        GJUMP4(0x060ADE9E, a, b, c, d);
    else
        GJUMP4(0x060AD62C, 0x504, b, c, d);
}

int f060A4838(int a, int b, int c, int d)
{
    FRAME(sp, 8);

    if (a) {
        GCALL2(0x060AD564, a, sp - 8);
        return LD32(sp - 8);
    }
    GCALL4(0x060AD62C, 0x504, b, c, d);
    return 0;
}

void f060A48A8(gaddr ctx, int value)
{
    if (!ctx) {
        GJUMP1(0x060AD62C, 0x504);
        return;
    }
    GJUMP2(0x060AD672, ctx, value);
}

void f060A4984(int a, int b, int c, int d)
{
    if (a)
        GJUMP2(0x060AE0E0, a, b);
    else
        GJUMP4(0x060AD62C, 0x504, b, c, d);
}

void f060A499C(gaddr obj, int b, int c, int d)
{
    if (obj != 0)
        GJUMP2(0x060AE0E8, obj, b);
    else
        GJUMP4(0x060AD62C, 0x504, b, c, d);
}

void f060A49B4(int a, int b, int c, int d)
{
    if (a)
        GJUMP1(0x060AE0F0, a);
    else
        GJUMP4(0x060AD62C, 0x504, b, c, d);
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

int f060A4CA2(int a, int b, int c, int d)
{
    return GJUMP4(0x060A4CB4, a, b, c, d);
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

void f060A5076(int n)
{
    while (n > 0) {
        POLL();
        n--;
    }
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

int f060A5676(gaddr table, gaddr key, int count)
{
    int i = 0;

    if (count <= 0)
        return -1;
    do {
        if (GCALL3(0x06095158, key, table + 12, 12) == 0)
            return i;
        if (LD8(table + 11) & 1)
            return -1;
        i++;
        table += 24;
    } while (AGAIN(i < count));
    return -1;
}

int f060A56CA(int n, int base)
{
    return n * 12 + base;
}

int f060A56D8(int a, int b)
{
    return a * 24 + b;
}

unsigned char f060A56E8(int i, gaddr base)
{
    return LDU8(base + i * 12 + 11);
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

int f060A6336(void)
{
    FRAME(sp, 8);

    GCALL2(0x060A5468, sp - 8, 0);
    if (LD32(sp - 8) == 1)
        return 1;
    ST32(0x060FA8C4, 0);
    return 0;
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

void f060A64F6(gaddr dst, int dst_step, gaddr src, int src_step)
{
    FRAME(sp, 8);
    int size = LD32(sp);
    int words = (unsigned int)size >> 2;
    int tail = size & 3;
    int i;

    if (dst == 0)
        return;
    dst_step <<= 2;
    src_step <<= 2;
    if (words > 0) {
        i = 0;
        do {
            ST32(dst, LD32(src));
            i++;
            dst += dst_step;
            src += src_step;
        } while (AGAIN(i < words));
    }
    if (tail > 0) {
        ST32(sp - 4, LD32(src));
        i = 0;
        do {
            ST8(dst, LD8(sp - 4 + i));
            i++;
            dst++;
        } while (AGAIN(i < tail));
    }
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

void f060A6762(gaddr src, gaddr a, gaddr b, gaddr c)
{
    ST32(a, LD32(src));
    ST32(b, LD32(src + 4));
    ST32(c, LD32(src + 44));
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

void f060A6938(gaddr src, gaddr out0, gaddr out4, gaddr out16)
{
    FRAME(sp, 0);
    gaddr out20 = LD32(sp);
    gaddr out_left = LD32(sp + 4);
    gaddr byte14 = LD32(sp + 8);
    gaddr byte15 = LD32(sp + 12);
    int flags;

    if (out0)
        ST32(out0, LD32(src));
    if (out4)
        ST32(out4, LD32(src + 4));
    if (byte14)
        ST32(byte14, LDU8(src + 14));
    if (out16)
        ST32(out16, LD32(src + 16));
    if (out20)
        ST32(out20, LD32(src + 20));
    if (byte15)
        ST32(byte15, LDU8(src + 15));
    if (out_left) {
        flags = LDU8(src + 15);
        if (!(flags & 8) || !(flags & 16))
            ST32(out_left, LD32(src + 16) - LD32(src + 24));
        else
            ST32(out_left, 0);
    }
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

int f060A7494(gaddr p, int v)
{
    return GJUMP2(0x060A7CC6, v, LD32(p + 28));
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

int f060A777E(gaddr out)
{
    int i = 0;

    do {
        if (LD8(LD32(DEV) + 24 + i) == 0) {
            ST8(LD32(DEV) + 24 + i, 1);
            ST32(out, i);
            return 0;
        }
        i++;
    } while (AGAIN(i < 24));
    ST32(out, -1);
    return -3;
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

int f060A77E0(gaddr out)
{
    int i = 0;

    do {
        if (LD8(LD32(DEV) + i) == 0) {
            ST8(LD32(DEV) + i, 1);
            ST32(out, i);
            return 0;
        }
        i++;
    } while (AGAIN(i < 24));
    ST32(out, -1);
    return -4;
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

int f060A7902(int id)
{
    gaddr dev = LD32(DEV);

    return LD32(dev + 48) != 0 && LD32(dev + 56) == id;
}

int f060A7920(int a, int b, gaddr c, int d)
{
    FRAME(sp, 20);
    gaddr dev = LD32(DEV);
    int count = LD32(dev + 84);
    gaddr slot;

    if (LD8(dev + 24 + a) != 1)
        return -7;
    if (count >= 24)
        return -8;
    if (LD32(dev + 88) == 0)
        ST32(dev + 88, 1);
    slot = dev + 92 + count * 16;
    ST8(slot, a);
    ST8(slot + 1, b);
    COPYB(slot + 2, c, 6);
    ST32(slot + 8, d);
    ST32(slot + 12, LD32(sp));
    ST32(dev + 84, LD32(dev + 84) + 1);
    GCALL1(0x060A8226, sp - 20);
    return 0;
}

int f060A7A12(int handle, int id)
{
    FRAME(sp, 8);
    gaddr dev;

    if (handle != 255 && LD8(LD32(DEV) + 24 + handle) != 1)
        return -7;
    dev = LD32(DEV);
    if (LD32(dev + 56) != id)
        return -9;
    ST32(dev + 0x304, 1);
    ST32(dev + 0x308, handle);
    GCALL1(0x060A83A0, sp - 8);
    return 0;
}

int f060A7A5E(int arg, int id)
{
    FRAME(sp, 20);
    int error;

    if (LD32(LD32(DEV) + 56) != id)
        return -9;
    GCALL1(0x060A7C3E, sp - 16);
    error = LD32(0x060FC080);
    if (error != 0)
        return error;
    GCALL1(0x060958F2, -21);
    GCALL1(0x0609576C, arg);
    ST32(0x060FC088, 1);
    return 0;
}

int f060A7ACA(int a, int b, int c, int d)
{
    FRAME(sp, 12);
    gaddr dev = LD32(DEV);

    if (LD32(dev + 0x30C) != 0)
        return -1;
    ST32(dev + 0x30C, 1);
    ST32(dev + 0x310, a);
    ST32(dev + 0x314, b);
    ST32(dev + 0x318, c);
    ST32(dev + 0x31C, 0);
    ST32(dev + 0x320, d);
    ST32(dev + 0x324, LD32(sp));
    GCALL1(0x060A8402, sp - 12);
    return 0;
}

int f060A7B24(int a, int b, int c)
{
    FRAME(sp, 8);
    gaddr dev = LD32(DEV);

    if (LD32(dev + 0x328) != 0)
        return -1;
    if (LD32(dev + 52) != -1)
        return -5;
    ST32(dev + 52, a);
    ST32(dev + 0x328, 1);
    ST32(dev + 0x32C, a);
    ST32(dev + 0x330, b);
    ST32(dev + 0x334, c);
    GCALL1(0x060A8556, sp - 8);
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

int f060A7BB0(int a, int b, int c)
{
    FRAME(sp, 8);
    gaddr dev = LD32(DEV);

    if (LD32(dev + 0x338) != 0)
        return -1;
    if (LD32(dev + 52) == a)
        return -5;
    ST32(dev + 0x338, 1);
    ST32(dev + 0x33C, a);
    ST32(dev + 0x340, b);
    ST32(dev + 0x344, c);
    GCALL1(0x060A85E4, sp - 8);
    return 0;
}

int f060A7C20(int value)
{
    gaddr g = LD32(DEV);

    return LD32(g + 0x338) == 0 || LD32(g + 0x33C) != value;
}

int f060A7CC6(int arg, int id)
{
    FRAME(sp, 20);
    int error;

    if (LD32(LD32(DEV) + 56) != id)
        return -9;
    GCALL1(0x060A7C3E, sp - 16);
    error = LD32(0x060FC080);
    if (error != 0)
        return error;
    GCALL1(0x0609580A, arg);
    return 0;
}

int f060A7DE6(int mode, int handle, int arg)
{
    FRAME(sp, 12);
    gaddr dev = LD32(DEV);

    if (LD8(dev + 24 + handle) != 1)
        return -5;
    if (LD8(dev + handle) != 1)
        return -5;
    if (LD32(dev + 0x360) != 0)
        return -1;
    ST32(dev + 0x360, mode == -1 ? 3 : 1);
    ST16(dev + 0x364, mode);
    ST16(dev + 0x366, handle);
    ST32(dev + 0x368, arg);
    GCALL1(0x060A881C, sp - 12);
    return 0;
}

int f060A7E66(int a, int b, int c)
{
    FRAME(sp, 20);
    gaddr dev = LD32(DEV);
    int count = LD32(dev + 0x1DC);
    gaddr entry;

    if (a != 255 && a != -2 && (a < 0 || a >= 24))
        return -6;
    if (b < 0 || b >= 24)
        return -6;
    if (c != 255 && c != -2 && (c < 0 || c >= 24))
        return -6;
    if (a != 255 && a != -2 && LD8(dev + 24 + a) != 1)
        return -7;
    if (c != 255 && c != -2 && LD8(dev + 24 + c) != 1)
        return -7;
    if (LD8(dev + b) != 1)
        return -7;
    if (count >= 24)
        return -8;
    if (LD32(dev + 0x1E0) == 0)
        ST32(dev + 0x1E0, 1);
    entry = dev + 0x1E4 + (short)(count * 12);
    ST32(entry, a);
    ST32(entry + 4, b);
    ST32(entry + 8, c);
    ST32(dev + 0x1DC, LD32(dev + 0x1DC) + 1);
    GCALL1(0x060A89F4, sp - 20);
    return 0;
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

int f060A8402(gaddr counter)
{
    FRAME(sp, 28);
    gaddr dev = LD32(DEV);
    int left;
    int limit;

    if (LD32(dev + 0x30C) == 1) {
        GCALL2(0x060AE6FA, LD32(dev + 0x310), sp - 28);
        GCALL0(0x060A8C10);
        ST32(counter, LD32(counter) + 1);
        left = LD32(sp - 28) - LD32(dev + 0x314);
        limit = LD32(dev + 0x318);
        if (left >= limit)
            left = limit;
        ST32(LD32(dev + 0x320), left);
        if (LD32(dev + 0x324) == 0) {
            ST32(dev + 0x30C, 0);
            return 0;
        }
        if (left <= 0) {
            ST32(dev + 0x30C, 0);
            ST32(LD32(dev + 0x324), 0);
            return 0;
        }
        ST32(dev + 0x30C, 2);
    }
    if (LD32(dev + 0x30C) == 2) {
        if (LD32(dev + 52) != -1)
            return 2;
        ST32(dev + 52, LD32(dev + 0x310));
        if (GCALL3(0x060AE73E, LD32(dev + 0x310), LD32(dev + 0x314), LD32(LD32(dev + 0x320))) != 0)
            return 2;
        GCALL0(0x060A8C10);
        ST32(counter, LD32(counter) + 1);
        ST32(dev + 0x30C, 3);
    }
    if (LD32(dev + 0x30C) == 3) {
        if (GCALL1(0x060AE76C, sp - 24) != 0)
            return 1;
        GCALL0(0x060A8C10);
        ST32(counter, LD32(counter) + 1);
        ST32(dev + 0x30C, 0);
        ST32(LD32(dev + 0x324), LD32(sp - 24) << 1);
        ST32(dev + 52, -1);
        return 0;
    }
    return 1;
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

int f060A881C(gaddr counter)
{
    FRAME(sp, 48);
    gaddr first = sp - 48;
    gaddr span = sp - 44;
    gaddr info = sp - 36;
    gaddr dev = LD32(DEV);
    int mode;
    int error;

    if (LD32(dev + 0x360) == 1) {
        if (GCALL3(0x060A4EA0, first, span, sp - 40) != 0) {
            ST32(dev + 0x360, 0);
            ST32(LD32(dev + 0x368), -1);
            return -11;
        }
        ST32(counter, LD32(counter) + 1);
        mode = LD16(dev + 0x364);
        if (mode == 0 || mode == 1 || (LD32(first) <= mode && mode < LD32(first) + LD32(span))) {
            ST32(dev + 0x360, 3);
        } else {
            if (GCALL2(0x060A4E78, 23, LD16(dev + 0x364)) != 0) {
                ST32(dev + 0x360, 0);
                ST32(LD32(dev + 0x368), -1);
                return -11;
            }
            ST32(counter, LD32(counter) + 1);
            ST32(dev + 0x360, 2);
        }
    }
    if (LD32(dev + 0x360) == 2 && GCALL1(0x060A8B72, 0x200)) {
        if (GCALL3(0x060A4EA0, first, span, sp - 40) != 0
            || (LD16(dev + 0x364) < LD32(first) && LD32(first) + LD32(span) <= LD16(dev + 0x364))) {
            ST32(dev + 0x360, 0);
            ST32(LD32(dev + 0x368), -1);
            return -11;
        }
        ST32(dev + 0x360, 3);
    }
    if (LD32(dev + 0x360) == 3) {
        GCALL1(0x060A7C3E, info);
        error = LD32(0x060FC080);
        if (error != 0)
            return error;
        if (GCALL2(0x060A4E50, LD16(dev + 0x366), LD16(dev + 0x364)) != 0)
            return 1;
        GCALL0(0x060A8C10);
        ST32(counter, LD32(counter) + 1);
        ST32(dev + 0x360, 4);
    }
    if (LD32(dev + 0x360) == 4 && GCALL1(0x060A8B72, 0x200)) {
        ST32(dev + 0x360, 0);
        if (GCALL3(0x060A4EA0, first, span, sp - 40) != 0) {
            ST32(dev + 0x360, 0);
            ST32(LD32(dev + 0x368), -1);
            return -11;
        }
        ST32(LD32(dev + 0x368), LD32(span));
    }
    return LD32(dev + 0x360);
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

void f060A8C10(void)
{
    FRAME(sp, 12);

    GCALL1(0x0609546E, sp - 12);
    ST8(LD32(DEV) + 64, LD8(sp - 12));
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

void f060A8DCC(int mask, int value, int on)
{
    if (mask & 0x100)
        SET_FIELD(1, 0x060FB8A2, 0xFF0F, value << 4);
    if (mask & 4) {
        SET_FIELD(1, 0x060FB8A0, 0xFFF0, value);
        TONE_FLAG(0x100);
    } else if (mask & 2) {
        SET_FIELD(1, 0x060FB8A0, 0xFFF0, value);
        TONE_FLAG(0x100);
    }
    if (mask & 8) {
        SET_FIELD(1, 0x060FB8A0, 0xFF0F, value << 4);
        TONE_FLAG(0x200);
    } else if (mask & 128) {
        SET_FIELD(1, 0x060FB8A0, 0xFF0F, value << 4);
        TONE_FLAG(0x200);
    }
    if (mask & 16) {
        SET_FIELD(1, 0x060FB8A0, 0xF0FF, value << 8);
        TONE_FLAG(0x400);
    }
    if (mask & 32) {
        SET_FIELD(1, 0x060FB8A0, 0x0FFF, value << 12);
        TONE_FLAG(0x800);
    }
    if (mask & 1) {
        SET_FIELD(1, 0x060FB8A2, 0xFFF0, value);
        TONE_FLAG(0x1000);
    }
    if (mask & 0x00040000)
        ST32(0x060FB8E0, value);
}

void f060AA39C(int now, int changed, gaddr dst, unsigned char set)
{
    FRAME(sp, 0);
    unsigned char clear = LDU8(sp + 3);

    if (changed & 6) {
        if (now & 6)
            ST8(dst + 1, LD8(dst + 1) | set);
        else
            ST8(dst + 1, LD8(dst + 1) & clear);
    }
    if (changed & 0x88) {
        if (now & 0x88)
            ST8(dst, LD8(dst) | set);
        else
            ST8(dst, LD8(dst) & clear);
    }
    if (changed & 0x10) {
        if (now & 0x10)
            ST8(dst + 3, LD8(dst + 3) | set);
        else
            ST8(dst + 3, LD8(dst + 3) & clear);
    }
    if (changed & 0x20) {
        if (now & 0x20)
            ST8(dst + 2, LD8(dst + 2) | set);
        else
            ST8(dst + 2, LD8(dst + 2) & clear);
    }
    if (changed & 0x1) {
        if (now & 0x1)
            ST8(dst + 5, LD8(dst + 5) | set);
        else
            ST8(dst + 5, LD8(dst + 5) & clear);
    }
    if (changed & 0x100) {
        if (now & 0x100)
            ST8(dst + 4, LD8(dst + 4) | set);
        else
            ST8(dst + 4, LD8(dst + 4) & clear);
    }
    if (changed & 0x10000) {
        if (now & 0x10000)
            ST8(dst + 7, LD8(dst + 7) | set);
        else
            ST8(dst + 7, LD8(dst + 7) & clear);
    }
    if (changed & 0x20000) {
        if (now & 0x20000)
            ST8(dst + 6, LD8(dst + 6) | set);
        else
            ST8(dst + 6, LD8(dst + 6) & clear);
    }
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

int f060AA57C(void)
{
    gaddr table = LD32(0x060FBFA0);
    gaddr recs = LD32(0x060FBFAC);
    int next = LD32(0x060FBF90);
    gaddr rec;

    if (LD32(0x060FBF98) == 1) {
        gaddr head = LD32(0x060FBFA4);
        int cur = LD32(0x060FBF94);
        int groups = LD32(0x060FBF8C);
        int base = LDU16(0x060FBFB0);
        int link;

        for (;;) {
            if (groups-- == 0)
                break;
            link = LD16(head);
            ST16(head, -1);
            head += 4;
            while (link != -1) {
                rec = recs + cur * 32;
                ST16(rec, LDU16(rec) | 0x1000);
                cur = LD16(table + link * 4 + 2);
                link = LD16(table + link * 4);
                ST16(rec + 2, base + cur * 4);
                POLL();
            }
            POLL();
        }
        rec = recs + cur * 32;
        ST16(rec, LDU16(rec) | 0x1000);
        ST16(rec + 2, base + next * 4);
    }
    ST32(0x060FBF9C, 0);
    ST32(0x060FBFA8, table);
    ST32(0x060FBF94, next);
    ST32(0x060FBF90, next + 1);
    ST16(recs + next * 32, 0x4000);
    return 0x4000;
}

int f060AA976(gaddr ctx)
{
    return GCALL1(0x060A66F2, LD32(ctx + 16) + 108) == 0;
}

int f060AAA1C(int a, gaddr b, gaddr c)
{
    FRAME(sp, 24);
    gaddr first = sp - 24;
    gaddr flags = sp - 20;

    GCALL8(0x060A6938, a, 0, b, 0, first, 0, 0, flags);
    if (LD32(flags) & 6) {
        ST32(b, 0x7FFFFFFF);
        ST32(c, 0x7FFFFFFF);
    } else {
        ST32(c, LD32(b) + LD32(first) - 1);
    }
    return LD32(flags);
}

int f060AAA6C(gaddr obj)
{
    FRAME(sp, 44);
    gaddr request = sp - 36;
    int first = LD32(obj + 20);
    int result = 0;

    GCALL3(0x060AAA1C, LD32(LD32(obj + 12) + 20), sp - 40, sp - 44);
    if (LD32(sp - 44) >= first) {
        ST32(request, 1);
        ST32(request + 4, first);
        ST32(request + 8, 1);
        ST32(request + 12, LD32(sp - 44) - first + 1);
        ST8(request + 16, 0);
        result = GCALL2(0x060A7A5E, request, LD32(obj + 52));
        if (result == -13) {
            result = -23;
        } else if (result == 0) {
            ST32(LD32(0x060FC00C) + 20, first);
            ST32(LD32(0x060FC00C) + 24, LD32(sp - 44));
        } else {
            result = -1;
        }
    }
    return result;
}

int f060AAAEE(gaddr obj)
{
    FRAME(sp, 16);
    int result;

    ST32(sp - 12, 3);
    result = GCALL2(0x060A7CC6, sp - 12, LD32(obj + 52));
    if (result == -13)
        return -23;
    if (result != 0)
        return -1;
    ST32(LD32(0x060FC00C) + 20, -1);
    ST32(LD32(0x060FC00C) + 24, -1);
    return result;
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

void f060AAE52(gaddr p, int mode, int c, int d)
{
    gaddr rec = LD32(p) + 52;

    if (mode == 2)
        GCALL4(0x060AAE08, 0x801, mode, c, d);
    ST32(rec + 156, mode);
}

gaddr f060AAE84(void)
{
    ST32(0x060BB98C, 0);
    ST32(0x060FC0E4, 0);
    ST32(0x060FC168, 0);
    ST32(0x060FC16C, 0);
    ST32(0x060FC170, 0);
    GCALL0(0x060ACB0C);
    GCALL0(0x060AEB1C);
    GCALL0(0x060AAE4E);
    GCALL0(0x060AADF8);
    return STRCPY(0x060BB96C, 0x060B1280);
}

gaddr f060AAF8A(gaddr obj, int unused, gaddr req)
{
    gaddr p = obj + 52;
    unsigned int idx = 0;
    gaddr slot;

    if (STRCMP(0x060BB96C, 0x060B1280) != 0) {
        GCALL1(0x060AAE08, 0x103);
        return 0;
    }
    while (LD32(SLOT_BITS + idx * 4) & LD32(SLOT_USED)) {
        idx++;
        if (idx >= 32)
            break;
        POLL();
    }
    if (idx == 32) {
        GCALL1(0x060AAE08, 0x101);
        return 0;
    }
    COPYW(0x060944F4, obj, req, 52);
    ST32(obj + 0x140, LD32(req));
    ST32(p, LD32(0x060B12BC));
    ST32(p + 236, LD32(0x060B12C4));
    ST32(p + 4, 0);
    ST32(p + 72, 0);
    ST32(p + 76, 0);
    ST32(p + 80, LD32(req));
    ST32(p + 84, LD32(req));
    ST32(p + 104, (LD32(req + 4) & 0x7FF) + 0xB000);
    if ((unsigned int)LD32(req + 4) <= (unsigned int)(LD32(p + 104) + 0x800)) {
        GCALL1(0x060AAE08, 0x102);
        return 0;
    }
    ST32(p + 100, LD32(req + 4) - LD32(p + 104));
    ST32(p + 88, LD32(req));
    ST32(p + 92, LD32(p + 88) + LD32(p + 100));
    ST32(p + 8, 0);
    ST32(p + 12, 0);
    ST32(p + 16, 0);
    ST32(p + 240, 0);
    ST32(p + 244, 0);
    ST32(p + 248, 0);
    ST32(p + 252, 0);
    ST32(p + 0x100, 0);
    ST32(p + 0x104, 0);
    ST32(p + 0x108, 0);
    ST32(p + 24, 0);
    ST32(p + 28, 0);
    ST32(p + 32, 0);
    ST32(p + 52, 0);
    ST32(p + 56, 0);
    ST32(p + 60, 0);
    ST32(p + 232, 0);
    ST32(p + 156, 1);
    ST32(p + 160, 0);
    ST32(p + 68, 21);
    ST32(p + 120, LD32(req + 32));
    ST32(p + 128, 0);
    ST32(p + 132, 0);
    ST32(p + 136, 0);
    ST32(p + 140, 0);
    ST32(p + 144, 0);
    ST32(p + 64, 0);
    ST32(SLOT_USED, LD32(SLOT_USED) | LD32(SLOT_BITS + idx * 4));
    slot = SLOT_TABLE + idx * 4;
    ST32(slot, obj);
    return slot;
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

void f060AB456(gaddr obj)
{
    gaddr rec = LD32(obj) + 52;

    while (LD32(rec + 160) != 0) {
        POLL();
        GCALL1(0x060AB338, obj);
    }
}

void f060AB49C(gaddr ctx, int b, int c, int d)
{
    gaddr s = LD32(ctx) + 52;

    GCALL4(0x060AB456, ctx, b, c, d);
    if (LD32(s + 4) == 4)
        GCALL4(0x060AFDF0, ctx, b, c, d);
    ST32(s + 4, 5);
}

void f060AB726(gaddr obj, int mode)
{
    gaddr o = LD32(obj);
    int shift = mode == 24 ? 2 : 1;
    unsigned int i = 0;
    int off;

    ST32(o + 0x180, o + 0x190 + 0x200);
    ST32(o + 0x184, o + 0x590 + 0x200);
    ST32(o + 0x188, o + 0x990 + 0x200);
    ST32(o + 0x18C, o + 0xD90 + 0x200);
    do {
        off = (signed char)i << 2;
        ST32(LD32(o + 0x180) + off, (SHL(i, shift) << 2) + (o + 0x1190));
        ST32(LD32(o + 0x184) + off, (SHL(i + 0x100, shift) << 2) + (o + 0x1190));
        ST32(LD32(o + 0x188) + off, (SHL(i + 0x200, shift) << 2) + (o + 0x1190));
        ST32(LD32(o + 0x18C) + off, (SHL(i + 0x300, shift) << 2) + (o + 0x1190));
        i++;
    } while (AGAIN(i < 0x100));
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

void f060ABB16(gaddr obj, int mode)
{
    ST32(LD32(obj) + 52 + 52, mode);
    GJUMP2(0x060AB726, obj, mode);
}

void f060ABB28(gaddr p, int v)
{
    gaddr rec = LD32(p);

    ST32(rec + 40, v);
    if (LD32(rec + 52 + 4) == 4)
        GJUMP4(0x060AFB0E, p, -1, -1, rec);
}

int f060ABB48(gaddr obj, int value)
{
    gaddr o = LD32(obj);
    int kind;

    ST32(o + 44, value);
    kind = LD32(o + 52 + 4);
    if (kind != 4)
        return kind;
    return GJUMP4(0x060AFB0E, obj, -1, -1, o);
}

void f060ABB6C(gaddr p, int v)
{
    ST32(LD32(p) + 52 + 68, v);
}

void f060ABCAA(int value)
{
    ST32(0x060FC168, value);
}

int f060ABCB0(void)
{
    return LD32(0x060FC168);
}

void f060ABD34(int a, int b, int c, int d)
{
    if (a)
        GCALL4(0x060AB49C, a, b, c, d);
    GCALL1(0x060AB32C, LD32(0x060FC168));
    ST32(0x060FC168, 0);
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

void f060AD6C4(gaddr p, int v)
{
    ST32(LD32(p) + 36, v);
}

void f060AD6CA(gaddr p, int v)
{
    ST32(LD32(p) + 40, v);
}

void f060AD6D0(gaddr p, int v)
{
    ST32(LD32(p) + 44, v);
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

void f060AD718(void)
{
    ST32(0x060FC210, 0);
    ST32(0x060FC184, 0);
    ST32(0x060FC214, 0);
    ST32(0x060FC218, 0);
    ST32(0x060FC21C, 0);
    ST32(0x060FC220, 0);
    GCALL0(0x060AD39C);
    GCALL0(0x060AD66E);
    GCALL0(0x060AD61C);
    ST32(0x060FC18C, 0x12345678);
    ST32(0x060FCF08, 0x060B087E);
    ST32(0x060FC188, 0x060ADB2C);
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

gaddr f060AD8F0(gaddr obj, gaddr req, int c, int d)
{
    gaddr rec = obj + 48;
    unsigned int idx = 0;
    unsigned int count;
    gaddr ent;

    if (LD32(0x060FC18C) != 0x12345678) {
        GCALL4(0x060AD62C, 0x103, 0, c, d);
        return 0;
    }
    while (LD32(0x060B12F8 + idx * 4) & LD32(0x060FC210)) {
        idx++;
        if (idx >= 32)
            break;
        POLL();
    }
    if (idx == 32) {
        GCALL4(0x060AD62C, 0x101, 0, c, d);
        return 0;
    }
    if (LD32(req + 12) & 0xFFF) {
        GCALL4(0x060AD62C, 0x305, 0, c, d);
        return 0;
    }
    count = HELPER(LD32(req + 12) >> 12);
    if (count < 2) {
        GCALL4(0x060AD62C, 0x304, 0, c, d);
        return 0;
    }
    if (count > 16) {
        GCALL4(0x060AD62C, 0x305, 0, c, d);
        return 0;
    }
    ST32(0x060FC210, LD32(0x060FC210) | LD32(0x060B12F8 + idx * 4));
    ent = 0x060FC190 + idx * 4;
    ST32(ent, obj);
    GCALL3(0x06094CA8, obj, 0, 0x1D0);
    COPYW(0x060944F4, obj + 4, req, 44);
    GCALL1(0x060AD88C, ent);
    ST32(rec + 4, 0);
    ST32(rec + 8, 0);
    ST32(rec + 12, 0);
    ST32(rec + 16, 1);
    ST32(rec + 24, 2);
    ST32(rec + 28, 1);
    ST32(rec + 60, 0);
    ST32(rec + 64, 0);
    ST32(rec + 72, LD32(req));
    ST32(rec + 76, LD32(req));
    ST32(rec + 68, LD32(req) + LD32(req + 4));
    ST32(rec + 96, 0);
    ST32(rec + 100, 0);
    ST32(rec + 128, 0);
    ST32(rec + 0x158, 0);
    ST32(rec + 104, 0);
    ST32(rec + 108, 0);
    ST32(rec + 112, 0);
    ST32(rec + 116, 0);
    ST32(rec + 140, 0);
    ST32(rec + 0x140, 0);
    ST32(rec + 0x144, 0);
    ST32(rec + 0x148, 0);
    ST32(rec + 0x14C, 0);
    ST32(rec + 0x150, 0);
    ST32(rec + 0x138, 0x060B1154);
    GCALL2(0x060AD672, ent, 0x400);
    return ent;
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

void f060ADB2C(int unused1, int unused2, int c, int d)
{
    GJUMP4(0x060AD62C, 0x308, 0, c, d);
}

int f060ADBA0(gaddr p)
{
    return LD32(LD32(p) + 4 + 4);
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

void f060AE0E0(gaddr p, int v)
{
    ST32(LD32(p) + 4 + 24, v);
}

void f060AE0E8(gaddr p, int v)
{
    ST32(LD32(p) + 4 + 28, v);
}

void f060AE0F0(gaddr p)
{
    if (LD32(LD32(p) + 48 + 4) == 4)
        GJUMP3(0x060B047E, p, -1, -1);
}

void f060AE1E6(gaddr p, int v)
{
    ST32(LD32(p) + 48 + 16, v);
}

void f060AE1EE(int v)
{
    ST32(0x060FC214, v);
}

int f060AE200(void)
{
    return LD32(0x060FC214);
}

void f060AE234(gaddr p)
{
    if (p) {
        GCALL1(0x060ADC8C, p);
        GCALL2(0x060AE1E6, p, 0);
    }
    GCALL1(0x060ADC82, LD32(0x060FC214));
    ST32(0x060FC214, 0);
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

void f060AEA3C(int a, int b, int c)
{
    FRAME(sp, 72);
    gaddr mode = sp - 20;
    gaddr req = sp - 60;

    GCALL1(0x060A52FA, 0);
    ST32(mode, 0);
    ST32(mode + 4, 1);
    ST32(mode + 8, 15);
    GCALL1(0x060A51AC, mode);
    ST32(req, b);
    ST32(req + 4, a);
    ST32(req + 8, c);
    ST32(req + 12, 1);
    ST32(req + 16, 1);
    ST32(req + 20, 0x800);
    ST32(req + 24, 0x800 >> 2);
    ST32(req + 28, 0);
    ST32(req + 36, 0x2FF);
    GCALL2(0x060A51F4, req, 0);
    GCALL1(0x060A52E8, 0);
    ST32(0x060FC230, a);
    ST32(0x060FC234, c << 2);
}

int f060AEAC4(void)
{
    FRAME(sp, 12);

    GCALL1(0x060A5318, sp - 12);
    if (LD32(sp - 12) == 4)
        return 1;
    if (GCALL1(0x060A532A, 0) == 0)
        return 2;
    GCALL2(0x060A5180, LD32(0x060FC230), LD32(0x060FC234));
    return 0;
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

void f060AF9A8(int n)
{
    do {
        n--;
    } while (AGAIN(n > 0));
}

int f060AFA28(int channel)
{
    int value = LD8(0x25A000A0 + (channel << 1) + LD32(0x25A00404));

    ST8(0x060FCEF8 + channel, value);
    return value;
}

void f060AFAC4(gaddr dst, gaddr src, int n)
{
    gaddr d = dst + 2;
    gaddr s = src + 2;
    int left = n - 2;

    while (--left >= 0) {
        POLL();
        for (;;) {
            ST8(d, LD8(s));
            if (LDU8(d) == LDU8(s))
                break;
            POLL();
            GCALL3(0x060AF9A8, 0x100, src, n);
        }
        d++;
        s++;
    }
}

void f060AFF98(gaddr stream, gaddr out_a, gaddr out_b, gaddr out_c)
{
    FRAME(sp, 0);
    gaddr out_free = LD32(sp);
    gaddr base = LD32(stream) + 52;
    gaddr second = LD32(LD32(stream) + 0x140);
    int offset = (LD32(base + 128) << 12) + LD32(base + 144);
    int used;
    int free;
    int span;

    if (LDU8(second + 38) != 8)
        used = (LD32(base + 136) - offset) << 1;
    else
        used = LD32(base + 136) - offset;
    free = LD32(base + 112) - used;
    ST32(out_free, free);
    if (free != 0) {
        if ((unsigned int)(LD32(base + 120) + free) > (unsigned int)LD32(base + 116))
            span = LD32(base + 116) - LD32(base + 120);
        else
            span = free;
        ST32(out_c, span);
        ST32(out_a, LD32(base + 120));
        ST32(out_b, (((unsigned int)LD32(base + 112) >> 1) << 1) + LD32(base + 120));
    } else {
        ST32(out_c, 0);
        ST32(out_a, 0);
        ST32(out_b, 0);
    }
}
