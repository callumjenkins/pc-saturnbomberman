#include "krnl.h"

void f06090266(void)
{
}

int f060906E4(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr flags;

    ST16(0x060C3242 + LDU16(cur + 66) * 2, 1);
    cur = LD32(CURRENT);
    flags = FLAGS_AT(LDU16(cur + 20));
    ST16(flags, LDU16(flags) & 0xFF77);
    ST16(LDU16(cur + 68) * 2 + 0x060C3248 + (signed char)(LD8(cur + 67) * 14), 0);
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

int f06090894(int n)
{
    return (GCALL1(0x0600A0EC, 17 - (n << 1)) << 4) + (n << 4) + 0x1A0;
}

int f060908C2(int n)
{
    return (GCALL1(0x0600A0EC, 11 - (n << 1)) << 4) + (n << 4) + 0x1C0;
}

int f06091228(void)
{
    int pick;

    if (LD16(0x060C3284))
        return 0;
    pick = GCALL0(0x0600A0B8) & 3;
    if (LD16(LD32(MOVER_PTR) + 66) && pick != 0) {
        if (pick == 1) {
            ST16(0x060C3280, 1);
            GCALL1(0x06014516, 0x06090FCA);
        } else {
            GCALL1(0x06014516, 0x0609137A);
        }
        return 1;
    }
    if (LD16(0x060C3282)) {
        ST16(0x060C3282, LD16(0x060C3282) - 1);
        return 0;
    }
    ST16(0x060C3282, 2);
    if (GCALL0(0x0606C5D6)) {
        ST16(0x060C3280, 0);
        GCALL1(0x06014516, 0x06090FCA);
        return 1;
    }
    if (GCALL0(0x0606BE44)) {
        GCALL1(0x06014516, 0x06091468);
        return 1;
    }
    GCALL0(0x0606E81C);
    if (GCALL0(0x0606BF8C) && !GCALL1(0x0606BCD8, LDU16(LD32(CURRENT) + 64))) {
        GCALL1(0x06014516, 0x060919B0);
        return 1;
    }
    if (!GCALL0(0x0606C4FA))
        return 0;
    if (LDU16(REC(LDU16(LD32(CURRENT) + 64)) + 28) < 0x230)
        return 0;
    ST16(0x060C3280, 1);
    GCALL1(0x06014516, 0x06090FCA);
    return 1;
}

void f06091848(void)
{
    short odd[13];
    short even[13];
    int limit = DIVS(LDU16(LD32(CURRENT) + 24) - 416, 16);
    int i, row, cell;

    i = 0;
    do {
        even[i] = (unsigned)i > (unsigned)limit ? 5 : ((unsigned)i >= (unsigned)limit ? 6 : 7);
        odd[i] = (i & 1) ? 0 : 6;
    } while (AGAIN(++i <= 12));
    even[0] = 6;
    even[12] = 6;
    cell = GCALL2(0x0600CAE4, 0x1A0, 0x1C0);
    row = 0;
    while (row <= 10) {
        POLL();
        if ((unsigned)row >= (unsigned)DIVS(LDU16(LD32(CURRENT) + 28) - 448, 16)) {
            gaddr p = 0x060EE8B0 + cell * 2;

            i = 0;
            do {
                ST16(p, LD16(p) | ((row & 1) ? odd[i] : even[i]));
                p += 2;
            } while (AGAIN(++i <= 12));
        }
        row++;
        cell += 64;
    }
}

void f06091968(void)
{
    int cell = GCALL2(0x0600CAE4, 0x1A0, 0x1C0);
    int row = 0;
    int col;

    do {
        gaddr p = 0x060EE8B0 + (cell + row * 64) * 2;

        col = 0;
        do {
            ST16(p, LDU16(p) & 0xFF00);
            p += 2;
        } while (AGAIN(++col <= 12));
    } while (AGAIN(++row <= 10));
}

void f0609360C(void)
{
    gaddr buf = 0x060C329A + (short)((short)LD16(LD32(CURRENT) + 66) * 76);
    unsigned int head = LDU16(buf);
    unsigned int i = 0;
    unsigned int id;
    gaddr obj;

    ST32(0x060C3418, buf);
    ST16(buf + 2 + head * 2, LD16(LD32(MOVER_PTR) + 16));
    ST16(LD32(0x060C3418) + 34 + head * 2, LD16(LD32(MOVER_PTR) + 18));
    ST16(LD32(0x060C3418), LD16(LD32(0x060C3418)) + 1);
    ST16(LD32(0x060C3418), LD16(LD32(0x060C3418)) & 15);
    do {
        id = LDU16(LD32(0x060C3418) + 66 + i);
        head = (head - 2) & 15;
        if (id) {
            obj = OBJ(id);
            ST16(obj + 16, LD16(LD32(0x060C3418) + 2 + head * 2));
            ST16(obj + 18, LD16(LD32(0x060C3418) + 34 + head * 2));
            ST16(obj + 4, LD16(LD32(MOVER_PTR) + 4));
        }
        i += 2;
    } while (AGAIN(i < 10));
}

void f060936AE(void)
{
    int i = 0;

    ST32(0x060C3418, (short)(LD16(LD32(CURRENT) + 66) * 76) + 0x060C329A);
    do {
        GCALL1(0x0606CC12, LD32(0x060C3418) + 66 + i * 2);
    } while (AGAIN(++i < 5));
}

int f060949D0(int x)
{
    return x < 0 ? -x : x;
}

gaddr f060949E0(gaddr dst, gaddr src, unsigned int n)
{
    unsigned int i = 0;

    if (dst == src || n == 0)
        return dst;
    if (dst < src)
        do {
            ST8(dst + i, LD8(src + i));
            i++;
        } while (AGAIN(i < n));
    else
        do {
            i++;
            ST8(dst + n - i, LD8(src + n - i));
        } while (AGAIN(i < n));
    return dst;
}

int f06094A44(gaddr a, gaddr b)
{
    return STRCMP(a, b);
}

gaddr f06094A58(gaddr dst, gaddr src)
{
    return STRCPY(dst, src);
}

/* Length of a zero-terminated string. */
int f06094A6C(gaddr s)
{
    int n;

    for (n = 0; LD8(s + n); n++)
        POLL();
    return n;
}

gaddr f06094CA8(gaddr dst, int value, unsigned int n)
{
    unsigned int i = 0;

    if (n != 0)
        do {
            ST8(dst + i, value);
            i++;
        } while (AGAIN(i < n));
    return dst;
}

int f06095158(gaddr a, gaddr b, unsigned int n)
{
    unsigned int i = 0;
    int c;

    if (n == 0)
        return 0;
    do {
        c = LD8(a++);
        if (c != LD8(b++) || c == 0)
            break;
    } while (AGAIN(++i < n));
    return (unsigned char)LD8(a - 1) - (unsigned char)LD8(b - 1);
}

gaddr f06095198(gaddr dst, gaddr src, unsigned int n)
{
    gaddr d = dst;
    unsigned int i = 0;

    while (i < n && LD8(src) != 0) {
        POLL();
        ST8(d, LD8(src));
        src++;
        d++;
        i++;
    }
    if (i < n)
        do {
            ST8(d, 0);
            d++;
            i++;
        } while (AGAIN(i < n));
    return dst;
}

void f0609546E(int a)
{
    GJUMP1(0x060A5020, a);
}

void f060957B0(gaddr src, gaddr dst)
{
    switch (LD32(src)) {
    case 1:
        ST8(dst, LD8(src + 5) | 128);
        ST8(dst + 1, LD8(src + 6));
        ST8(dst + 2, LD8(src + 7));
        break;
    case 2:
        ST8(dst, 0);
        ST8(dst + 1, LD8(src + 4));
        ST8(dst + 2, LD8(src + 5));
        break;
    case 3:
        ST8(dst, 255);
        ST8(dst + 1, 255);
        ST8(dst + 2, 255);
        break;
    default:
        ST8(dst, 0);
        ST8(dst + 1, 0);
        ST8(dst + 2, 0);
        break;
    }
}

int f060958E4(void)
{
    return 0x25818000;
}

void f0609591C(unsigned short bits)
{
    ST16(0x060FA8B8, LDU16(0x060FA8B8) | bits);
}

int f06096596(gaddr p)
{
    gaddr q = p + 12;

    if (LD32(q + 28) == 0) {
        if (GCALL1(0x060A6BA0, q) == 2)
            ST32(p + 8, 1);
    }
    return LD32(p + 8);
}

void f0609697E(gaddr dst)
{
    COPYW(0x0609445C, dst, LD32(0x060FA8BC) + 184, 12);
}

int f06096A7C(void)
{
    return 0;
}

void f06096A80(void)
{
    gaddr p = LD32(0x060FA8BC) + 4;

    ST32(p, 0x060A69A2);
    ST32(p + 4, 0x060A6B08);
    ST32(p + 8, 0x060A6BFE);
    ST32(p + 12, 0x060A6BF2);
}

void f06096AC0(int n)
{
    gaddr g;
    gaddr p;
    int i;

    ST32(LD32(0x060FA8BC), n);
    GCALL0(0x06096A80);
    g = LD32(0x060FA8BC);
    ST32(g + 148, 0);
    ST32(g + 180, 0);
    ST32(g + 168, 0);
    ST32(g + 176, 0);
    ST32(g + 172, 0);
    ST32(g + 184, 0);
    ST32(g + 196, 0);
    if (n > 0) {
        p = g + 0xC60;
        i = 0;
        do {
            ST32(p, 0);
            p += 168;
        } while (AGAIN(++i < n));
    }
    for (i = 0; i < 5; i++) {
        ST32(g + 0x438 + i * 4, 0);
        ST32(g + 0x44C + i * 4, 0);
    }
}

int f06096B3C(gaddr list)
{
    int i;

    for (i = 0; i < LD32(list + 4); i++) {
        POLL();
        if (LD32(list) ? GCALL2(0x060A56FA, i, LD32(list + 8)) & 1 : GCALL2(0x060A56E8, i, LD32(list + 8)) & 1)
            break;
    }
    return i > LD32(list + 4) ? 0 : i + 1;
}

gaddr f06096B9C(void)
{
    gaddr table = LD32(0x060FA8BC);
    gaddr slot = table + 0xC60;
    int i = 0;

    while (i < LD32(table)) {
        POLL();
        if (!LD32(slot))
            break;
        i++;
        slot += 168;
    }
    if (i != LD32(table)) {
        ST32(slot, 1);
        return slot;
    }
    return 0;
}

void f06096BCE(gaddr p)
{
    ST32(p, 0);
}

int f06096CB0(int key)
{
    gaddr list = LD32(0x060FA8BC) + 52;
    int i = 0;

    while (i < LD32(list + 96)) {
        POLL();
        if (key == LD32(list + i * 4))
            break;
        i++;
    }
    return i == LD32(list + 96) ? -1 : i;
}

void f06096CF4(int key)
{
    gaddr list;

    if (GCALL1(0x06096CB0, key) == -1) {
        list = LD32(0x060FA8BC) + 52;
        ST32(list + LD32(list + 96) * 4, key);
        ST32(list + 96, LD32(list + 96) + 1);
    }
}

void f06096D28(int key)
{
    gaddr list;
    int i, last;

    if (!key)
        return;
    i = GCALL1(0x06096CB0, key);
    if (i == -1)
        return;
    list = LD32(0x060FA8BC) + 52;
    last = LD32(list + 96) - 1;
    ST32(list + 96, last);
    if (i < last) {
        do {
            ST32(list + i * 4, LD32(list + (i + 1) * 4));
        } while (AGAIN(++i < last));
    }
    ST32(list + i * 4, 0);
}

void f06097184(gaddr src, gaddr out0, gaddr out4, gaddr out16)
{
    FRAME(sp, 0);
    gaddr out20 = LD32(sp);
    gaddr remaining = LD32(sp + 4);
    gaddr byte14 = LD32(sp + 8);
    gaddr byte15 = LD32(sp + 12);

    if (out0)
        ST32(out0, LD32(src));
    if (out4)
        ST32(out4, LD32(src + 4));
    if (out16)
        ST32(out16, LD32(src + 16));
    if (out20)
        ST32(out20, LD32(src + 20));
    if (remaining)
        ST32(remaining, LD32(src + 16) - LD32(src + 24));
    if (byte14)
        ST32(byte14, LDU8(src + 14));
    if (byte15)
        ST32(byte15, LDU8(src + 15));
}

int f0609720A(gaddr p)
{
    return LD32(p + 88);
}

void f0609741C(gaddr xs, gaddr ys, gaddr y2, int n)
{
    gaddr h = LD32(0x060FA8C8);
    gaddr u = LD32(0x060FA8CC);
    unsigned int i = 0;
    int w;

    ST32(y2, 0);
    ST32(y2 + (n - 1) * 4, 0);
    if ((unsigned int)(n - 1) > 0)
        do {
            SET_WORD(h, i, WORD(xs, i + 1) - WORD(xs, i));
            SET_WORD(u, i + 1, FDIV(WORD(ys, i + 1) - WORD(ys, i), WORD(h, i)));
            i++;
        } while (AGAIN(i < (unsigned int)(n - 1)));
    SET_WORD(y2, 1, WORD(u, 2) - WORD(u, 1) - FMUL(WORD(h, 0), WORD(y2, 0)));
    SET_WORD(u, 1, (WORD(xs, 2) - WORD(xs, 0)) << 1);
    i = 1;
    if ((unsigned int)(n - 2) > 1)
        do {
            w = FDIV(WORD(h, i), WORD(u, i));
            SET_WORD(y2, i + 1, WORD(u, i + 2) - WORD(u, i + 1) - FMUL(WORD(y2, i), w));
            SET_WORD(u, i + 1, ((WORD(xs, i + 2) - WORD(xs, i)) << 1) - FMUL(WORD(h, i), w));
            i++;
        } while (AGAIN(i < (unsigned int)(n - 2)));
    SET_WORD(y2, n - 2, WORD(y2, n - 2) - FMUL(WORD(h, n - 2), WORD(y2, n - 1)));
    i = n - 2;
    if (i > 0)
        do {
            SET_WORD(y2, i, FDIV(WORD(y2, i) - FMUL(WORD(h, i), WORD(y2, i + 1)), WORD(u, i)));
            i--;
        } while (AGAIN(i > 0));
}

int f060975F6(int x, gaddr xs, gaddr a, gaddr b)
{
    FRAME(sp, 0);
    unsigned int lo = 0;
    unsigned int hi = LD32(sp) - 1;
    unsigned int mid;
    int t, span, acc, r;

    if (hi > 0)
        do {
            mid = (lo + hi) >> 1;
            if (WORD(xs, mid) >= x)
                hi = mid;
            else
                lo = mid + 1;
        } while (AGAIN(lo < hi));
    if (lo > 0)
        lo--;
    t = x - WORD(xs, lo);
    span = WORD(xs, lo + 1) - WORD(xs, lo);
    acc = FMUL(FDIV(FMUL(WORD(b, lo + 1) - WORD(b, lo), t), span) + WORD(b, lo) * 3, t);
    acc += FDIV(WORD(a, lo + 1) - WORD(a, lo), span);
    r = FMUL(acc - FMUL((WORD(b, lo) << 1) + WORD(b, lo + 1), span), t);
    return r + WORD(a, lo);
}

int f06097B7C(unsigned int a, unsigned int b)
{
    if (a < 3)
        return 0;
    return b >= 2 ? b : 0;
}

int f06097B92(gaddr src, unsigned int limit)
{
    int i;

    if ((unsigned int)LD32(src) < limit)
        return 0;
    for (i = 0; i < 9; i++)
        ST32(0x060FA8C8 + i * 4, LD32(src + 4 + i * 4));
    return 1;
}

int f060980C8(int num, int den)
{
    ST32(0xFFFFFF00, den);
    ST32(0xFFFFFF10, (short)((unsigned int)num >> 16));
    ST32(0xFFFFFF14, num << 16);
    return LD32(0xFFFFFF14);
}

int f060980DC(short v)
{
    return v << 16;
}

int f060980E4(int x)
{
    return (short)(x >> 16);
}

int f0609812C(int angle)
{
    int neg = 0;

    if (angle < 0) {
        neg = 1;
        angle = -angle;
    }
    if (angle >= 0x00B40000)
        angle = 0;
    else if (angle > 0x005A0000)
        angle = 0x00B40000 - angle;
    angle = GCALL1(0x060981B6, angle);
    return neg ? -angle : angle;
}

int f0609816C(int angle)
{
    int neg = 1;

    if (angle < 0)
        angle = -angle;
    if (angle >= 0x00B40000)
        angle = 0;
    else if (angle > 0x005A0000)
        angle = 0x00B40000 - angle;
    else
        neg = 0;
    angle = GCALL1(0x060981B0, angle);
    return neg ? -angle : angle;
}

void f06098700(gaddr dst, short tag, gaddr p)
{
    ST16(dst, tag);
    ST32(dst + 8, p);
    ST32(dst + 4, p);
    GJUMP1(0x0609870C, dst);
}

void f0609870C(gaddr obj)
{
    gaddr src = 0x060B11A4;
    gaddr dst = LD32(obj + 4);
    int i = 0;

    do {
        ST32(dst, LD32(src));
        src += 4;
        dst += 4;
    } while (AGAIN(++i < 12));
}

int f06098EA4(gaddr first, gaddr second)
{
    int mode = LD8(0x060FA907) & 255;
    int count;

    if (mode != 1 && mode != 2) {
        ST32(first, 0);
        return 1;
    }
    if ((LD8(0x20100061) & 16) == 16) {
        count = LD32(0x060FA960) + 1;
        ST32(0x060FA960, count);
        if (count >= 3) {
            ST8(0x060FA8EC, 1);
            ST32(0x060FA960, LD32(0x060FA960) - 1);
        }
    } else {
        ST8(0x060FA8EC, 0);
        ST32(0x060FA960, 0);
    }
    if (LD32(0x060FA918) < (LD8(0x060FA908) & 255)) {
        ST32(0x060FA918, LD32(0x060FA918) + 1);
        return 0;
    }
    ST32(0x060FA918, 0);
    if (LD32(0x060FA914) == 0 || (LD8(0x060FA970) & 255) == 2 || (LD8(0x060FA970) & 255) == 3) {
        ST8(0x060FA970, (LD8(0x060FA970) & 255) == 4 ? 0 : 4);
        if (!(LD8(0x060FA970) & 255))
            ST8(0x060FA901, LD8(0x060FA901) + 1);
        if ((LD8(0x060FA901) & 255) >= 3) {
            if ((LD8(0x060FA981) & 255) == 1)
                GCALL1(0x06099A2E, 15);
            if (LD32(0x060FA974) > 0)
                ST32(0x060FA968, LD32(0x060FA968) + 1);
            GCALL0(0x0609998C);
            while (LD32(0x060FA968) < 2) {
                POLL();
                ST8(LD32(0x060FA958) + LD32(0x060FA968) * 2, 240);
                ST8(LD32(0x060FA958) + LD32(0x060FA968) * 2 + 1, 0);
                ST32(0x060FA968, LD32(0x060FA968) + 1);
            }
            ST8(0x060FA901, LD8(0x060FA901) - 1);
        } else {
            GCALL0(0x06099A5C);
        }
    } else {
        if ((LD8(0x060FA970) & 255) != 4)
            ST8(0x060FA901, 0);
        ST8(0x060FA970, 0);
    }
    if ((LD8(0x060FA938) & 255) == 1) {
        ST8(0x060FA902, 1);
        ST32(0x060FA924, LD32(0x060FA948));
        ST32(0x060FA948, LD32(0x060FA8F0));
        ST32(0x060FA8F0, LD32(0x060FA924));
    } else {
        ST8(0x060FA902, 0);
    }
    ST32(0x060FA95C, LD32(0x060FA958));
    ST32(0x060FA958, LD32(0x060FA954));
    ST32(0x060FA954, LD32(0x060FA95C));
    ST32(0x060FA924, LD32(0x060FA920));
    ST32(0x060FA920, LD32(0x060FA91C));
    ST32(0x060FA91C, LD32(0x060FA924));
    ST32(first, LD32(0x060FA924));
    ST32(second, LD32(0x060FA954));
    GCALL0(0x060998A0);
    if ((LD8(0x060FA970) & 255) == 4)
        return 1;
    ST8(0x060FA970, 3);
    if ((LD8(0x20100063) & 1) == 1)
        return 1;
    ST8(0x20100063, 1);
    ST8(0x20100001, LD8(0x060FA903));
    ST8(0x20100003, LD8(0x060FA904));
    ST8(0x20100005, LD8(0x060FA905));
    ST8(0x2010001F, 16);
    ST8(0x060FA970, 2);
    return 0;
}

/* 20100061 is SMPC's status register. */
void f060997BC(void)
{
    if ((unsigned int)LD32(0x060FA964) >= 0x20100061 && (LD8(0x20100061) & 0x20))
        ST8(0x060FA970, 2);
}

void f06099828(void)
{
    unsigned int i;

    for (i = 0; i < (unsigned char)LD8(0x060FA97C); i++) {
        POLL();
        ST8(LD32(0x060FA920) + ((unsigned char)LD8(0x060FA90C) + 2) * LD32(0x060FA914) + i + 2,
            LD8(LD32(0x060FA930) + (unsigned char)LD8(0x060FA92C) * i));
    }
}

void f060998A0(void)
{
    gaddr buf;

    ST8(0x060FA980, 1);
    ST8(0x060FA981, 0);
    ST8(0x060FA982, 0);
    ST8(0x060FA983, 0);
    ST8(0x060FA984, 0);
    ST8(0x060FA985, 0);
    ST8(0x060FA938, 0);
    ST32(0x060FA914, 0);
    ST32(0x060FA968, 0);
    ST32(0x060FA96C, 0);
    ST32(0x060FA974, 0);
    ST8(0x060FA906, 0);
    buf = LD32(0x060FA958);
    ST8(buf, 240);
    ST8(buf + 1, 0);
    ST8(buf + 2, 240);
    ST8(buf + 3, 0);
}

void f06099A2E(unsigned char value)
{
    ST8(LD32(0x060FA920) + ((LD8(0x060FA90C) & 255) + 2) * LD32(0x060FA914) + 1, value);
}

void f06099CDC(int addr, unsigned short mode, int src)
{
    if (mode != 1 && mode != LDU16(0x060BB900))
        return;
    addr &= 0x0007FFFF;
    ST32(0x060FAA4C, addr);
    GCALL3(0x0609B734, addr | 0x25E00000, src, mode << 1);
    ST32(0x060FAA4C, (unsigned int)LD32(0x060FAA4C) >> 1);
    if (mode != 1)
        ST32(0x060FAA10 + 60, LD32(0x060FAA10 + 60) | 0x80000000);
    if (!LDU16(0x060BB8FC))
        ST16(0x060BB8FC, 1);
}

void f06099F0C(gaddr p)
{
    int i;

    ST32(p, 0);
    ST32(p + 4, 0);
    for (i = 8; i < 15; i++)
        ST8(p + i, 0);
}

void f06099F30(gaddr cfg)
{
    int mode;
    int ones = 0;
    int sel = 0;

    ST32(0x060FB85C, 0);
    ST32(0x060FB860, 0);
    ST32(0x060FB864, LD32(cfg));
    ST32(0x060FB868, LD32(cfg + 4));
    ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0x7FFF);
    if ((LD8(cfg + 8) & 255) == 1)
        ST16(0x060FA9AE, LDU16(0x060FA9AE) | 0x100);
    else
        ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFEFF);
    if ((LD8(cfg + 9) & 255) == 1)
        ST16(0x060FA9AE, LDU16(0x060FA9AE) | 0x200);
    else
        ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFDFF);

    mode = LD8(cfg + 10) & 255;
    if (mode < 4) {
        ST16(0x060FA9AE, (LDU16(0x060FA9AE) & 0xFFFC) | mode);
        if (mode == 1) {
            if (LD32(0x060FB864) == 0)
                sel = 1;
            else
                ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFFFC);
            ST16(0x060FAA56, LDU16(0x060FAA56) & 0xFF00);
            ST32(0x060FB85C, LD32(0x060FB864) + 0x25E00000);
            ones = 1;
        }
    } else if (mode == 4) {
        ST16(0x060FAA56, LDU16(0x060FAA56) & 255);
        ST32(0x060FB860, LD32(0x060FB868) + 0x25E00000);
    }

    mode = LD8(cfg + 11) & 255;
    if (mode < 4) {
        ST16(0x060FA9AE, (LDU16(0x060FA9AE) & 0xFFF3) | (mode << 2));
        if (mode == 1) {
            if (ones) {
                if (LD32(0x060FB868))
                    ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFFF3);
                ST16(0x060FAA56, LDU16(0x060FAA56) & 255);
                ST16(0x060FAA56, LDU16(0x060FAA56) | 0x100);
                ST32(0x060FB860, LD32(0x060FB868) + 0x25E20000);
                ones++;
            } else {
                if (LD32(0x060FB864) == 0)
                    sel = 2;
                else
                    ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFFF3);
                ST16(0x060FAA56, LDU16(0x060FAA56) & 0xFF00);
                ST16(0x060FAA56, LDU16(0x060FAA56) | 1);
                ST32(0x060FB85C, LD32(0x060FB864) + 0x25E20000);
                ones = 1;
            }
        }
    } else if (mode == 4) {
        ST16(0x060FAA56, LDU16(0x060FAA56) & 255);
        ST16(0x060FAA56, LDU16(0x060FAA56) | 0x100);
        ST32(0x060FB860, LD32(0x060FB868) + 0x25E20000);
    }

    mode = LD8(cfg + 12) & 255;
    if (mode < 4) {
        ST16(0x060FA9AE, (LDU16(0x060FA9AE) & 0xFFCF) | (mode << 4));
        if (mode == 1) {
            if (ones) {
                if (LD32(0x060FB868))
                    ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFFCF);
                ST16(0x060FAA56, LDU16(0x060FAA56) & 255);
                ST16(0x060FAA56, LDU16(0x060FAA56) | 0x200);
                ones++;
                ST32(0x060FB860, LD32(0x060FB868) + 0x25E40000);
            } else {
                if (LD32(0x060FB864) == 0)
                    sel = 3;
                else
                    ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFFCF);
                ST16(0x060FAA56, LDU16(0x060FAA56) & 0xFF00);
                ST16(0x060FAA56, LDU16(0x060FAA56) | 2);
                ST32(0x060FB85C, LD32(0x060FB864) + 0x25E40000);
                ones = 1;
            }
        }
    } else if (mode == 4 && LD32(0x060FB868)) {
        ST16(0x060FAA56, LDU16(0x060FAA56) & 255);
        ST16(0x060FAA56, LDU16(0x060FAA56) | 0x200);
        ST32(0x060FB860, LD32(0x060FB868) + 0x25E40000);
    }

    mode = LD8(cfg + 13) & 255;
    if (mode < 4) {
        ST16(0x060FA9AE, (LDU16(0x060FA9AE) & 0xFF3F) | (mode << 6));
        if (mode == 1) {
            if (ones) {
                if (LD32(0x060FB868))
                    ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFF3F);
                ST16(0x060FAA56, LDU16(0x060FAA56) & 255);
                ST16(0x060FAA56, LDU16(0x060FAA56) | 0x300);
                ST32(0x060FB860, LD32(0x060FB868) + 0x25E60000);
            } else {
                if (LD32(0x060FB864) == 0)
                    sel = 4;
                else
                    ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFF3F);
                ST16(0x060FAA56, LDU16(0x060FAA56) & 0xFF00);
                ST16(0x060FAA56, LDU16(0x060FAA56) | 3);
                ST32(0x060FB85C, LD32(0x060FB864) + 0x25E60000);
            }
        }
    } else if (mode == 4 && LD32(0x060FB868)) {
        ST16(0x060FAA56, LDU16(0x060FAA56) & 255);
        ST16(0x060FAA56, LDU16(0x060FAA56) | 0x300);
        ST32(0x060FB860, LD32(0x060FB868) + 0x25E60000);
    }

    if (LD32(0x060FB860))
        return;
    if ((LD8(cfg + 14) & 255) == 1 && LD32(0x060FB85C) == 0 && GCALL0(0x0609C062) == 1) {
        ST16(0x060FA9AE, LDU16(0x060FA9AE) | 0x8000);
        ST32(0x060FB85C, 0x25F00800);
        return;
    }
    if (LD32(0x060FB85C)) {
        if (LD8(0x060FB871)) {
            if (LD32(0x060FB868) == 0)
                ST32(0x060FB868, LD32(0x060FB864) + 0x400);
            if (LD32(0x060FB864) == 0)
                ST32(0x060FB864, -1);
            ST32(0x060FB860, LD32(0x060FB868) + LD32(0x060FB85C));
            ST16(0x060FAA56, (LDU16(0x060FAA56) & 255) | (LDU16(0x060FAA56) << 8));
            if (sel == 1) {
                POLL();
                ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFFFC);
            } else if (sel == 2) {
                POLL();
                ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFFF3);
            } else if (sel == 3) {
                POLL();
                ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFFCF);
            } else if (sel == 4) {
                POLL();
                ST16(0x060FA9AE, LDU16(0x060FA9AE) & 0xFF3F);
            }
        }
        return;
    }
    if (LD32(0x060FB864) && LD8(0x060FB870)) {
        ST16(0x060FAA56, LDU16(0x060FAA56) & 0xFF00);
        ST16(0x060FAA56, LDU16(0x060FAA56) | (DIVS(LD32(0x060FB864), 0x00020000) & 0xFFFF));
        ST32(0x060FB85C, LD32(0x060FB864) + 0x25E00000);
    }
    if (LD32(0x060FB868) && LD8(0x060FB871)) {
        ST16(0x060FAA56, LDU16(0x060FAA56) & 255);
        ST16(0x060FAA56, LDU16(0x060FAA56) | ((DIVS(LD32(0x060FB868), 0x00020000) & 0xFFFF) << 8));
        ST32(0x060FB860, LD32(0x060FB868) + 0x25E00000);
    }
}

void f0609A464(gaddr p)
{
    int i = 0;

    ST8(p, 0);
    ST8(p + 1, 0);
    ST8(p + 2, 0);
    ST8(p + 3, 0);
    ST8(p + 4, 0);
    ST8(p + 5, 0);
    ST8(p + 6, 0);
    ST8(p + 8, 0);
    ST8(p + 7, 0);
    ST16(p + 10, 0);
    do {
        ST32(p + 12 + i * 4, 0);
    } while (AGAIN(++i < 16));
}

void f0609AFCC(gaddr src)
{
    int i = 0;

    do {
        ST16(0x060FA9B0 + i * 2, LD16(src + i * 2));
    } while (AGAIN(++i < 8));
}

void f0609AFF4(void)
{
    int i;

    GCALL0(0x0609DA54);
    ST32(0x060FB878, 0);
    ST32(0x060FB87C, 0);
    ST32(0x060FB880, 0);
    ST32(0x060FB884, 0);
    ST32(0x060FB890, 0);
    ST32(0x060FB894, 0);
    ST16(0x060FB858, 0);
    ST16(0x060FB85A, 0);
    ST16(0x060FB86C, 0);
    ST16(0x060FB86E, 0);
    ST32(0x060FB85C, 0);
    ST32(0x060FB860, 0);
    ST32(0x060FB864, 0);
    ST32(0x060FB868, 0);
    GCALL0(0x0609C010);
    ST32(0x060FA99C, 0x25F80000);
    ST16(0x060FA9A0, 0x8000);
    ST16(0x060FA9A2, 0);
    ST16(0x060FA9A6, 0);
    ST16(0x060FA9AC, 0);
    ST16(0x060FA9AE, 0x8000 >> 2);
    i = 0;
    do {
        ST16(0x060FA9B0 + i * 2, 0xFFFF);
    } while (AGAIN(++i < 8));
    for (i = 0; i < 4; i++)
        ST16(0x060FA9C0 + i * 2, 0);
    for (i = 0; i < 12; i++)
        ST16(0x060FA9C8 + i * 2, 0);
    i = 0;
    do {
        ST16(0x060FA9E0 + i * 2, 0);
    } while (AGAIN(++i < 8));
    i = 0;
    do {
        ST16(0x060FA9F0 + i * 2, 0);
    } while (AGAIN(++i < 16));
    ST32(0x060FAA10, 0);
    ST32(0x060FAA14, 0);
    ST32(0x060FAA18, 0x00010000);
    ST32(0x060FAA1C, 0x00010000);
    ST32(0x060FAA20, 0);
    ST32(0x060FAA24, 0);
    ST32(0x060FAA28, 0x00010000);
    ST32(0x060FAA2C, 0x00010000);
    for (i = 0; i < 6; i++)
        ST16(0x060FAA30 + i * 2, 0);
    ST32(0x060FAA3C, 0);
    ST32(0x060FAA40, 0);
    ST32(0x060FAA44, 0);
    ST32(0x060FAA48, 0);
    ST32(0x060FAA4C, 0);
    for (i = 0; i < 6; i++)
        ST16(0x060FAA50 + i * 2, 0);
    ST32(0x060FAA5C, 0);
    for (i = 0; i < 12; i++)
        ST16(0x060FAA60 + i * 2, 0);
    ST32(0x060FAA78, 0);
    ST32(0x060FAA7C, 0);
    if (!LDU16(0x060BB8FC))
        ST16(0x060BB8FC, 1);
}

void f0609B5B4(void)
{
    if (LDU16(0x060FB858) && LD32(0x060FB85C)) {
        GCALL3(0x0609B734, LD32(0x060FB85C), 0x060FAB80, LD32(0x060FB850) << 1);
        ST16(0x060FB858, 0);
    }
    if (LDU16(0x060FB85A) && LD32(0x060FB860)) {
        GCALL3(0x0609B734, LD32(0x060FB860), 0x060FB1E8, LD32(0x060FB854) << 1);
        ST16(0x060FB85A, 0);
    }
    if (LDU16(0x060BB902) == 1) {
        POLL();
        GCALL3(0x0609B734, LD32(0x060FB874), 0x060FAA80, 128);
    } else if (LDU16(0x060BB902) == 2) {
        POLL();
        GCALL3(0x0609B734, LD32(0x060FB874), 0x060FAA80, 0x100);
    }
    GCALL3(0x0609B734, LD32(0x060FA99C), 0x060FA9A0, 40);
    GCALL3(0x0609B734, LD32(0x060FA99C) + 40, 0x060FA9C8, 72);
    GCALL3(0x0609B734, LD32(0x060FA99C) + 112, 0x060FAA10, 64);
    GCALL3(0x0609B734, LD32(0x060FA99C) + 176, 0x060FAA50, 16);
    GCALL3(0x0609B734, LD32(0x060FA99C) + 192, 0x060FAA60, 32);
}

void f0609B69A(void)
{
    if (LDU16(0x060BB8FC) == 1) {
        POLL();
        GCALL0(0x0609B5B4);
        ST16(0x060BB8FC, 0);
    } else if (LDU16(0x060BB8FC) == 2) {
        POLL();
        GCALL3(0x0609B734, LD32(0x060FA988), LD32(0x060FA98C), LDU16(0x060BB8F0) << 2);
        GCALL3(0x0609B734, LD32(0x060FA990), LD32(0x060FA994), LDU16(0x060BB8F2) << 2);
        GCALL0(0x0609B5B4);
        ST16(0x060BB8FC, 0);
    }
    GCALL0(0x0609C634);
    if (LD8(0x060FB8DC) & 128) {
        GCALL3(0x0609B734, LD32(0x060BB904), 0x060FB89C, 16);
        BITSET(0x060FB8DC, 0, 1);
    }
    if (LD8(0x060FB8DC) & 64) {
        GCALL3(0x0609B734, LD32(0x060BB908), 0x060FB8AC, 8);
        BITSET(0x060FB8DC, 0, 0x101);
    }
    if (LD8(0x060FB8DC) & 32) {
        GCALL3(0x0609B734, LD32(0x060BB90C), 0x060FB8B4, 6);
        BITSET(0x060FB8DC, 0, 0x201);
    }
    if (LD8(0x060FB8DC) & 16) {
        GCALL3(0x0609B734, LD32(0x060BB910), 0x060FB8BA, 8);
        BITSET(0x060FB8DC, 0, 0x301);
    }
    if (LD8(0x060FB8DC) & 8) {
        GCALL3(0x0609B734, LD32(0x060BB914), 0x060FB8C2, 8);
        BITSET(0x060FB8DC, 0, 0x401);
    }
    if (LD8(0x060FB8DC) & 4) {
        GCALL3(0x0609B734, LD32(0x060BB918), 0x060FB8CA, 16);
        BITSET(0x060FB8DC, 0, 0x501);
    }
}

void f0609B734(gaddr dst, gaddr src, unsigned int n)
{
    unsigned int words = n >> 1;
    unsigned int i = 0;

    if (words != 0)
        do {
            i++;
            ST16(dst, LD16(src));
            dst += 2;
            src += 2;
        } while (AGAIN(i < words));
}

void f0609B750(int mode)
{
    if ((unsigned int)mode <= 2) {
        POLL();
        ST16(0x060FA9AE, (LDU16(0x060FA9AE) & 0xFFF) | mode << 12);
    }
    if (!LDU16(0x060BB8FC))
        ST16(0x060BB8FC, 1);
}

/* Copies count halfwords, each plus a bias, to VDP2 VRAM at addr; does nothing unless count is 1 or the halfword at 060BB900. */
void f0609B8C0(unsigned int addr, unsigned short count, gaddr src)
{
    unsigned short bias = LD32(0x060FB8E0) << 8;
    gaddr dst;
    int i;

    if (count != 1 && count != LDU16(0x060BB900))
        return;
    addr &= 0x7FFFF;
    ST32(0x060FAA48, addr);
    dst = addr | 0x25E00000;
    if (count > 0) {
        i = 0;
        do {
            ST16(dst + i * 2, LD16(src + i * 2) + bias);
        } while (AGAIN(++i < count));
    }
    ST32(0x060FAA48, LD32(0x060FAA48) >> 1);
    if (count != 1)
        ST32(0x060FAA48, LD32(0x060FAA48) | 0x80000000);
    if (!LDU16(0x060BB8FC))
        ST16(0x060BB8FC, 1);
}

void f0609B960(int a, int b, int c)
{
    BITSET(0x060FB8DC, 1, 1);
    ST16(0x060FB89C, (LDU16(0x060FB89C) & 0xFFF0) | (a & 255));
    BITSET(0x060FB8DC, 1, 1);
    ST16(0x060FB89C, (LDU16(0x060FB89C) & 0xFFDF) | ((b & 255) << 5));
    BITSET(0x060FB8DC, 1, 1);
    ST16(0x060FB89C, (LDU16(0x060FB89C) & 0xFFEF) | ((c & 255) << 4));
}

void f0609B9E0(int row, int col, int count, gaddr src)
{
    if (GCALL0(0x0609C062) != 2) {
        gaddr dst = 0x25F00000 + (GCALL1(0x060A8D0C, row) << 9) + (col << 1);

        if (count == 1) {
            ST16(dst, LD16(src));
        } else {
            POLL();
            GJUMP3(0x0609B734, dst, src, count << 1);
        }
    } else {
        gaddr dst = 0x25F00000 + (GCALL1(0x060A8D0C, row) << 10) + (col << 2);

        if (count == 1) {
            ST32(dst, LD32(src));
        } else {
            POLL();
            GJUMP3(0x0609B734, dst, src, count << 2);
        }
    }
}

void f0609BA80(int mask)
{
    int i = 0;

    do {
        ST32(0x060FB8E4 + i * 4, LD32(0x060FB8E4 + i * 4) & ~mask);
    } while (AGAIN(++i < 8));
    ST32(0x060FB904, LD32(0x060FB904) & ~mask);
}

void f0609BE40(unsigned char hi, unsigned char top)
{
    ST8(0x060FB8DC, (LD8(0x060FB8DC) & 127) | 128);
    ST16(0x060FB89C, (LDU16(0x060FB89C) & 0xFFF) | top << 12);
    ST16(0x060FB89C, (LD16(0x060FB89C) & 0xF0FF) | hi << 8);
}

void f0609BE8C(int mode, int target, unsigned int steps, gaddr from)
{
    FRAME(sp, 24);
    gaddr to = LD32(sp);
    gaddr slot;
    int v;

    if (LDU8(0x060FB930) != 0)
        return;
    if (target == 0 && steps == 0)
        return;
    ST8(0x060FB930, 3);
    ST32(0x060FB908, mode);
    ST32(0x060FB90C, target);
    ST16(0x060FB91C, LD16(to) - LD16(from));
    ST16(0x060FB91E, LD16(to + 2) - LD16(from + 2));
    ST16(0x060FB920, LD16(to + 4) - LD16(from + 4));
    ST16(0x060FB922, LD16(0x060FB91C));
    ST16(0x060FB924, LD16(0x060FB91E));
    ST16(0x060FB926, LD16(0x060FB920));
    ST16(0x060FB928, LD16(to));
    ST16(0x060FB92A, LD16(to + 2));
    ST16(0x060FB92C, LD16(to + 4));
    for (slot = 0x060FB91C; slot <= 0x060FB920; slot += 2) {
        v = LD16(slot);
        if (steps == 0 || (unsigned int)(v >= 0 ? v : -v) <= steps)
            ST16(slot, v > 0 ? 1 : -1);
        else
            ST16(slot, DIVS16(v, (short)steps));
    }
    if (steps != 0)
        ST32(0x060FB90C, 0);
    ST32(0x060FB910, LD32(0x060FB90C));
}

void f0609C010(void)
{
    int i;

    GCALL0(0x0609CCDC);
    GCALL0(0x0609D24C);
    GCALL0(0x0609D328);
    GCALL0(0x0609D3B8);
    GCALL0(0x0609D494);
    GCALL0(0x0609D550);
    i = 0;
    do {
        ST32(0x060FB8E4 + i * 4, 0);
    } while (AGAIN(++i < 8));
    ST32(0x060FB904, 0);
    ST8(0x060FB930, 0);
}

int f0609C062(void)
{
    return (LDU16(0x060FA9AE) & 0x3000) >> 12;
}

void f0609C0B4(int mask, unsigned char level)
{
    int k;

    BITSET(0x060FB8DC, 1, 1);
    ST16(0x060FB8A8, LDU16(0x060FB8A8) & 0xFDFF);
    BITSET(0x060FB8DC, 1, 1);
    ST16(0x060FB8A8, LDU16(0x060FB8A8) & 0xFEFF);
    for (k = 0; k < 8; k++)
        if (mask & (0x100 << k))
            SET_LEVEL(0x40, 0x301, 0x060FB8BA + (k >> 1) * 2, k & 1);
    if (mask & 6)
        SET_LEVEL(1, 0x401, 0x060FB8C2, 0);
    if (mask & 0x88)
        SET_LEVEL(2, 0x401, 0x060FB8C2, 1);
    if (mask & 16)
        SET_LEVEL(4, 0x401, 0x060FB8C4, 0);
    if (mask & 32)
        SET_LEVEL(8, 0x401, 0x060FB8C4, 1);
    if (mask & 1) {
        BITSET(0x060FB8DC, 1, 1);
        if (level >= 32) {
            ST16(0x060FB8A8, LDU16(0x060FB8A8) & 0xFFEF);
        } else {
            ST16(0x060FB8A8, (LDU16(0x060FB8A8) & 0xFFEF) | 16);
            BITSET(0x060FB8DC, 1, 0x401);
            ST16(0x060FB8C6, level);
        }
    }
}

void f0609CBF8(int second, short a, short b, short c)
{
    gaddr lane = second ? 0x060FB8D4 : 0x060FB8CE;

    LATCH(0x501);
    ST16(lane, (LDU16(lane) & 0x1FF) + a);
    LATCH(0x501);
    ST16(lane + 2, (LDU16(lane + 2) & 0x1FF) + b);
    LATCH(0x501);
    ST16(lane + 4, (LDU16(lane + 4) & 0x1FF) + c);
}

void f0609CCDC(void)
{
    int bit;
    int pass;

    SET_FIELD(1, 0x060FB89C, 0xFFF, 0x3000);
    MASK(1, 0x060FB8A8, 0xFFBF);
    SET_FIELD(1, 0x060FB89C, 0xFFDF, 32);
    MASK(1, 0x060FB89C, 0xFFEF);
    SET_FIELD(1, 0x060FB89C, 0xFFF0, 7);
    for (pass = 0; pass < 2; pass++) {
        MASK(1, 0x060FB8A0, 0xFFF0);
        MASK(1, 0x060FB8A0, 0xFF0F);
        MASK(1, 0x060FB8A0, 0xF0FF);
        MASK(1, 0x060FB8A0, 0x0FFF);
        MASK(1, 0x060FB8A2, 0xFFF0);
        MASK(1, 0x060FB8A2, 0xFF0F);
    }
    for (bit = 1; bit <= 0x20; bit <<= 1)
        MASK(1, 0x060FB8A4, ~bit);
    MASK_FIELDS(0x060FB8A6);
    MASK(1, 0x060FB8A8, 0x7FFF);
    MASK(1, 0x060FB8A8, 0x8FFF);
    MASK(1, 0x060FB8A8, 0xFBFF);
    MASK(1, 0x060FB8A8, 0xFDFF);
    SET_FIELD(1, 0x060FB8A8, 0xFEFF, 0x100);
    MASK(1, 0x060FB8A8, 0xFFBF);
    for (bit = 0x20; bit >= 1; bit >>= 1)
        MASK(1, 0x060FB8A8, ~bit);
    MASK_FIELDS(0x060FB8AA);
    for (bit = 1; bit <= 0x20; bit <<= 1)
        MASK(1, 0x060FB89E, ~bit);
    MASK(1, 0x060FB89E, 0xFEFF);
    LATCH(1);
}

void f0609D24C(void)
{
    gaddr reg;

    for (reg = 0x060FB8AC; reg <= 0x060FB8B2; reg += 2) {
        MASK(0x101, reg, 0xFFF0);
        MASK(0x101, reg, 0xF0FF);
    }
    LATCH(0x101);
}

void f0609D328(void)
{
    SET_FIELD(0x201, 0x060FB8B4, 0xFF00, 3);
    SET_FIELD(0x201, 0x060FB8B4, 255, 0x200);
    SET_FIELD(0x201, 0x060FB8B6, 0xFF00, 1);
    MASK(0x201, 0x060FB8B6, 255);
    LATCH(0x201);
    ST16(0x060FB8B8, 4);
    LATCH(0x201);
}

void f0609D3B8(void)
{
    gaddr reg;

    for (reg = 0x060FB8BA; reg <= 0x060FB8BE; reg += 2) {
        MASK(0x301, reg, 0xFF00);
        MASK(0x301, reg, 255);
    }
    MASK(0x301, 0x060FB8C0, 0xFF00);
    MASK(0x301, 0x060FB8BE, 255);
    LATCH(0x301);
}

void f0609D494(void)
{
    MASK(0x401, 0x060FB8C2, 0xFF00);
    MASK(0x401, 0x060FB8C2, 255);
    MASK(0x401, 0x060FB8C4, 0xFF00);
    MASK(0x401, 0x060FB8C4, 255);
    LATCH(0x401);
    ST16(0x060FB8C6, 0);
    MASK(0x401, 0x060FB8C8, 0xFF00);
    MASK(0x401, 0x060FB8C8, 255);
    LATCH(0x401);
}

void f0609D550(void)
{
    gaddr reg;
    int bit;

    for (bit = 1; bit <= 0x40; bit <<= 1)
        MASK(0x501, 0x060FB8CA, ~bit);
    for (bit = 1; bit <= 0x40; bit <<= 1)
        MASK(0x501, 0x060FB8CC, ~bit);
    for (reg = 0x060FB8CE; reg <= 0x060FB8D8; reg += 2) {
        LATCH(0x501);
        ST16(reg, 0);
    }
    LATCH(0x501);
}

void f0609D730(int mask)
{
    int bit;

    MASK(1, 0x060FB89E, 0xFEFF);
    for (bit = 1; bit <= 0x20; bit <<= 1)
        MASK(1, 0x060FB89E, ~bit);
    if (mask == 0)
        return;
    SET_FIELD(1, 0x060FB89E, 0xFEFF, 0x100);
    if (mask & 4)
        SET_FIELD(1, 0x060FB89E, 0xFFFE, 1);
    if (mask & 2)
        SET_FIELD(1, 0x060FB89E, 0xFFFE, 1);
    if (mask & 8)
        SET_FIELD(1, 0x060FB89E, 0xFFFD, 2);
    if (mask & 128)
        SET_FIELD(1, 0x060FB89E, 0xFFFD, 2);
    if (mask & 16)
        SET_FIELD(1, 0x060FB89E, 0xFFFB, 4);
    if (mask & 32)
        SET_FIELD(1, 0x060FB89E, 0xFFF7, 8);
    if (mask & 1)
        SET_FIELD(1, 0x060FB89E, 0xFFEF, 16);
    if (mask & 0x00080000)
        SET_FIELD(1, 0x060FB89E, 0xFFDF, 32);
}

void f0609D96C(unsigned short mode)
{
    int state, flag, index;

    if (mode == 0xFFFF) {
        state = 2;
        flag = 0;
        index = mode;
    } else if (mode == 0xFFFE) {
        state = 3;
        flag = 0;
        index = mode;
    } else {
        flag = !(mode & 0x8000);
        index = mode & 0x7FFF;
        state = index > 1;
    }
    ST16(0x060BB91C, state);
    ST32(0x060BB920, flag);
    ST32(0x060BB924, index);
    ST16(0x25D00002, state ? LDU16(0x060FBF72) | 3 : LDU16(0x060FBF72));
}

int f0609DA34(void)
{
    if (LD32(0x060BB924) != 0) {
        ST32(0x060BB92C, 1);
        do {
        } while (AGAIN(LD32(0x060BB92C) != 0));
        do {
        } while (AGAIN(LD32(0x060BB930) != 0));
    }
    return 0;
}

void f0609DA54(void)
{
    int p;

    ST16(0x060BB91C, 0);
    ST32(0x060BB920, 1);
    for (p = 0x060BB924; p <= 0x060BB934; p += 4)
        ST32(p, 0);
    ST32(0x060FBF34, 0);
}

void f0609DA9C(void)
{
    unsigned short state = LDU16(0x060BB91C);

    if (state == 2) {
        if (LD32(0x060BB92C)) {
            GCALL1(0x0609B69A, 0x060BB91C);
            ST32(0x060FBF34, 2);
        }
    } else if (state == 3) {
        if (LD32(0x060BB92C)) {
            ST16(0x25D00000, LDU16(0x060FBF70) | 8);
            ST16(0x25D00002, LDU16(0x060FBF72) | 3);
            GCALL3(0x0609B69A, 0x060BB91C, 0x25D00002, 0x060FBF72);
            ST32(0x060FBF34, 3);
        }
    } else if (state != 0) {
        ST32(0x060BB928, LD32(0x060BB928) + 1);
        if (LD32(0x060BB920) == 1 && LD32(0x060BB924) - 1 <= LD32(0x060BB928))
            ST16(0x25D00002, LDU16(0x060FBF72) | 2);
        if (LD32(0x060BB924) <= LD32(0x060BB928)) {
            if (LD32(0x060BB92C)) {
                GCALL3(0x0609B69A, 0x060BB91C, 0x25D00002, 0x060FBF72);
                ST32(0x060FBF34, 1);
            }
            ST32(0x060BB928, 0);
        }
    } else {
        GCALL3(0x0609B69A, 0x060BB91C, 0x25D00002, 0x060FBF72);
        ST32(0x060BB92C, 0);
    }
}

void f0609DB80(void)
{
    int mode;

    if (LDU16(0x060FBF74)) {
        ST16(0x25D00002, LDU16(0x060FBF72) | ((LD16(0x25F80004) & 2) ? 12 : 8));
        ST32(0x060FBF34, 0);
        ST32(0x060BB92C, 0);
        return;
    }
    mode = LD32(0x060FBF34);
    if (!mode)
        return;
    if (mode == 2 && LD32(0x060BB938) && !(LDU16(0x25D00010) & 2)) {
        ST32(0x060BB930, 1);
    } else {
        if (LD32(0x060FBF34) != 3)
            ST16(0x25D00002, LDU16(0x060FBF72) | 3);
        else
            ST16(0x25D00000, LD16(0x060FBF70));
        ST32(0x060FBF34, 0);
        ST32(0x060BB930, 0);
    }
    ST32(0x060BB92C, 0);
}

void f0609DC4C(unsigned char sel, int a, int flags, int b)
{
    FRAME(sp, 0);
    gaddr first, second;

    POLL();
    if (sel == 0) {
        ST32(0x060FAA78, 0);
        first = 0x060FAA60;
        second = 0x060FAA64;
    } else if (sel == 1) {
        ST32(0x060FAA7C, 0);
        first = 0x060FAA68;
        second = 0x060FAA6C;
    } else {
        return;
    }
    if (LDU16(0x060BB8FE) > 0x160) {
        ST16(first, LD16(sp + 2));
        ST16(second, LD16(sp + 10));
    } else {
        ST16(first, LDU16(sp + 2) << 1);
        ST16(second, LDU16(sp + 10) << 1);
    }
    ST16(first + 2, LD16(sp + 6));
    ST16(second + 2, LD16(sp + 14));
    if (sel == 0) {
        SEND_BLOCKS(a, b, flags, 1, 254, 2, 253);
    } else {
        SEND_BLOCKS(a, b, flags, 4, 251, 8, 247);
    }
}

void f0609DD9C(unsigned char sel, int a, int flags, int b)
{
    FRAME(sp, 0);
    int vram = LD32(sp);
    int start = LD32(sp + 4);
    unsigned int count = LD32(sp + 8);
    gaddr src = LD32(sp + 12);
    gaddr first, second, dst;
    unsigned int i = 0;

    POLL();
    if (sel == 0) {
        ST32(0x060FAA78, (((0xDA200000 + vram) >> 1) & 0x0007FFFE) | 0x80000000);
        first = 0x060FAA60;
        second = 0x060FAA64;
    } else if (sel == 1) {
        ST32(0x060FAA7C, (((0xDA200000 + vram) >> 1) & 0x0007FFFE) | 0x80000000);
        first = 0x060FAA68;
        second = 0x060FAA6C;
    } else {
        return;
    }
    ST16(first + 2, start);
    ST16(second + 2, start + count - 1);
    if (count != 0) {
        dst = (start << 2) + vram;
        if (LDU16(0x060BB8FE) > 0x160)
            do {
                i++;
                ST16(dst, LD16(src));
                ST16(dst + 2, LD16(src + 2));
                dst += 4;
                src += 4;
            } while (AGAIN((unsigned short)i < count));
        else
            do {
                i++;
                ST16(dst, LDU16(src) << 1);
                ST16(dst + 2, LDU16(src + 2) << 1);
                dst += 4;
                src += 4;
            } while (AGAIN((unsigned short)i < count));
    }
    if (sel == 0) {
        SEND_BLOCKS(a, b, flags, 1, 254, 2, 253);
    } else {
        SEND_BLOCKS(a, b, flags, 4, 251, 8, 247);
    }
}

void f0609DF54(int a, int flags, int b)
{
    if ((a | flags) != 0)
        GCALL5(0x060AA39C, a, flags, 0x060FAA70, 128, 127);
    if ((b | flags) != 0)
        GCALL5(0x060AA39C, b, flags, 0x060FAA70, 16, 0xEF);
    GCALL5(0x060AA39C, flags, 0xFFFEFFFF, 0x060FAA70, 32, 0xDF);
    if (flags == 0)
        SET_FIELD(1, 0x060FB89C, 0xFFEF, 0);
    else
        SET_FIELD(1, 0x060FB89C, 0xFFEF, 16);
    if (LDU16(0x060BB8FC) == 0)
        ST16(0x060BB8FC, 1);
}

void f0609E020(int sel)
{
    int field;

    MASK(1, 0x060FB8A8, 0xFBFF);
    SET_FIELD(1, 0x060FB8A8, 0x7FFF, 0x8000);
    if (sel == 1)
        field = 0x1000;
    else if (sel == 2)
        field = 0x2000;
    else if (sel == 4)
        field = 0x2000;
    else if (sel == 8)
        field = 0x4000;
    else if (sel == 16)
        field = 0x5000;
    else if (sel == 32)
        field = 0x6000;
    else if (sel == 128)
        field = 0x4000;
    else if (sel == 0x100)
        field = 0;
    else
        return;
    POLL();
    SET_FIELD(1, 0x060FB8A8, 0x8FFF, field);
}

void f0609E27E(int sel)
{
    POLL();
    GJUMP2(0x0609E178, sel, 1);
}

void f0609E282(int sel)
{
    POLL();
    GJUMP2(0x0609E178, sel, 0);
}

void f0609E3FA(int a, int b, int c, int d)
{
    FRAME(sp, 20);
    gaddr dst = sp - 16;
    gaddr header = sp - 20;

    GCALL4(0x0609EF5C, dst, header, c, d);
    GCALL3(0x0609F004, LD32(dst), a, b);
    ST32(LD32(header), LD32(LD32(header)) | 0x80000000);
}

void f0609E4E4(signed char arg)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255) {
        ST8(LD32(0x060FBF64) + 2, arg);
        ST16(LD32(0x060FBF64), 0x8200);
    }
    ST32(0x060FBF40, 0);
}

void f0609E53C(signed char arg)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255) {
        ST8(LD32(0x060FBF64) + 2, arg);
        ST16(LD32(0x060FBF64), 0x8300);
    }
    ST32(0x060FBF40, 0);
}

void f0609E586(signed char a, signed char b)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255) {
        ST8(LD32(0x060FBF64) + 2, a);
        ST8(LD32(0x060FBF64) + 3, b);
        ST16(LD32(0x060FBF64), 0x8700);
    }
    ST32(0x060FBF40, 0);
}

void f0609E708(void)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255)
        ST16(LD32(0x060FBF64), 0xC00);
    ST32(0x060FBF40, 0);
}

void f0609E750(void)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255)
        ST16(LD32(0x060FBF64), 0xD00);
    ST32(0x060FBF40, 0);
}

int f0609E78C(signed char a, signed char b, signed char c, signed char d)
{
    if (LD32(0x060FBF40))
        return 1;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255) {
        ST8(LD32(0x060FBF64) + 2, a);
        ST8(LD32(0x060FBF64) + 3, b);
        ST8(LD32(0x060FBF64) + 4, c);
        ST8(LD32(0x060FBF64) + 5, d);
        ST16(LD32(0x060FBF64), 0x100);
        ST32(0x060FBF40, 0);
        return 0;
    }
    ST32(0x060FBF40, 0);
    return 1;
}

void f0609E80C(signed char arg)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255) {
        ST8(LD32(0x060FBF64) + 2, arg);
        ST16(LD32(0x060FBF64), 0x200);
    }
    ST32(0x060FBF40, 0);
}

void f0609E862(signed char arg)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255) {
        ST8(LD32(0x060FBF64) + 2, arg);
        ST16(LD32(0x060FBF64), 0x300);
    }
    ST32(0x060FBF40, 0);
}

void f0609E8B8(signed char arg)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255) {
        ST8(LD32(0x060FBF64) + 2, arg);
        ST16(LD32(0x060FBF64), 0x400);
    }
    ST32(0x060FBF40, 0);
}

void f0609E902(signed char a, signed char b, signed char c)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255) {
        ST8(LD32(0x060FBF64) + 2, a);
        ST8(LD32(0x060FBF64) + 3, b);
        ST8(LD32(0x060FBF64) + 4, c);
        ST16(LD32(0x060FBF64), 0x500);
    }
    ST32(0x060FBF40, 0);
}

void f0609EDB4(signed char a, signed char b)
{
    if (LD32(0x060FBF40))
        return;
    ST32(0x060FBF40, 1);
    if (GCALL0(0x0609F00A) & 255) {
        ST8(LD32(0x060FBF64) + 2, (a & 255) << 5);
        ST8(LD32(0x060FBF64) + 3, (b & 255) << 5);
        ST16(LD32(0x060FBF64), 0x8000);
    }
    ST32(0x060FBF40, 0);
}

int f0609EE2A(signed char a, signed char b)
{
    gaddr p;

    if (LD32(0x060FBF40))
        return 1;
    ST32(0x060FBF40, 1);
    if (!(unsigned char)GCALL0(0x0609F00A)) {
        ST32(0x060FBF40, 0);
        return 1;
    }
    p = LD32(0x060FBF64) + 2;
    ST8(p, GCALL1(0x0609EFD4, a));
    p = LD32(0x060FBF64) + 3;
    ST8(p, GCALL1(0x0609EFD4, b));
    ST16(LD32(0x060FBF64), 0x8100);
    ST32(0x060FBF40, 0);
    return 0;
}

void f0609EEA8(gaddr dst, unsigned char index)
{
    int off = index * 2;

    ST16(dst, LDU16(LD32(0x060FBF50) + off) & 0xFF00);
    ST8(dst + 2, LD16(LD32(0x060FBF50) + off));
}

void f0609EF42(gaddr dst, int n)
{
    GJUMP3(0x06094CA8, dst, 0, n);
}

void f0609EF5C(gaddr out_pos, gaddr out_entry, unsigned short kind, unsigned short id)
{
    unsigned int entry = LD32(LD32(0x060FBF4C));
    int i = 1;

    while (!(entry & 0x80000000)) {
        POLL();
        if (HELPER((entry & 0x70000000) >> 28) == kind && ((entry & 0x0F000000) >> 24) == id) {
            ST32(out_pos, (entry & 0x000FFFFF) + 0x25A00000);
            ST32(out_entry, LD32(0x060FBF4C) + (i - 1) * 8 + 4);
            break;
        }
        entry = LD32(LD32(0x060FBF4C) + i * 8);
        i++;
    }
}

int f0609EFD4(signed char x)
{
    return x >= 0 ? x : 16 - x;
}

int f0609F004(gaddr dst, gaddr src, int n)
{
    return GJUMP3(0x060949E0, dst, src, n);
}

int f0609F00A(void)
{
    gaddr cursor = 0x060FBF64;
    gaddr first = 0x060FBF48;

    if (LDU8(LD32(cursor)) == 0) {
        ST32(cursor, LD32(first));
    } else {
        if (LD32(cursor) >= LD32(first) + 112)
            return 0;
        ST32(cursor, LD32(cursor) + 16);
    }
    while (LD32(cursor) < LD32(first) + 112) {
        POLL();
        if (LDU8(LD32(cursor)) == 0)
            return 1;
        ST32(cursor, LD32(cursor) + 16);
    }
    return 0;
}

void f0609F274(unsigned short mode, unsigned short idx, unsigned short wide)
{
    int a, b;

    if (idx > 7)
        idx = 0;
    ST16(0x060FBF70, mode & 7);
    ST16(0x25D00000, mode & 7);
    a = LD16(0x060BB94C + idx * 4);
    b = LD16(0x060BB94C + idx * 4 + 2);
    ST32(0x060FBF68, a);
    if (wide == 1)
        b <<= 1;
    ST32(0x060FBF6C, b);
    ST16(0x060BB94A, mode == 1 || mode == 3);
    ST16(0x060FBF74, wide ? 8 : 0);
    ST16(0x060FBF76, 0);
}

void f0609F354(int color, unsigned short x1, unsigned short y1, int x2)
{
    FRAME(sp, 0);
    int y2 = LDU16(sp + 2);
    int mode = LDU16(0x060BB94A);
    int half = LDU16(0x060FBF74);

    ST16(0x060BB940, color);
    ST16(0x060BB942, x1);
    ST16(0x060BB944, y1);
    ST16(0x060BB946, x2);
    ST16(0x060BB948, y2);
    ST16(0x25D00006, color);
    if (mode == 0)
        x1 >>= 3;
    else
        x1 >>= 4;
    if (half)
        y1 >>= 1;
    ST16(0x060BB93C, (x1 << 9) + y1);
    ST16(0x25D00008, LD16(0x060BB93C));
    if (mode == 0)
        x2 = (unsigned short)(x2 + 1) >> 3;
    else
        x2 = (unsigned short)(x2 + 1) >> 4;
    if (half)
        y2 >>= 1;
    ST16(0x060BB93E, (x2 << 9) + y2);
    ST16(0x25D0000A, LD16(0x060BB93E));
}

void f0609F448(int flag)
{
    ST16(0x060FBF72, flag ? 16 : 0);
}

void f0609F464(gaddr desc)
{
    unsigned int rounded = (LDU16(desc + 2) + 3) & 0xFFFC;

    ST32(0x060FBF88, LDU16(desc + 6));
    ST32(0x060FBF84, LD32(desc + 12));
    GCALL1(0x0609F1A8, 0x060FBFB4);
    ST16(LAYOUT, LDU16(desc) + 4);
    ST16(LAYOUT + 2, LDU16(desc) + 4);
    ST16(LAYOUT + 4, rounded);
    ST16(LAYOUT + 6, rounded >> 2);
    ST16(LAYOUT + 8, LD16(desc + 4));
    ST16(LAYOUT + 10, LD16(desc + 4));
    ST16(LAYOUT + 24, 0x4000 - (((LDU16(LAYOUT + 2) + LDU16(LAYOUT + 6)) * 2 + LDU16(LAYOUT + 10) + 1) & 0xFFFF));
    ST32(LAYOUT_A, LD32(0x060FBFB4) + 32);
    ST32(LAYOUT_A + 8, (LDU16(LAYOUT + 2) << 5) + LD32(LAYOUT_A));
    ST32(LAYOUT_B, (LDU16(LAYOUT + 6) << 5) + LD32(LAYOUT_A + 8));
    ST32(LAYOUT_B + 8, (LDU16(LAYOUT + 2) << 5) + LD32(LAYOUT_B));
    ST32(LAYOUT + 12, (LDU16(LAYOUT + 6) << 5) + LD32(LAYOUT_B + 8));
    ST32(LAYOUT + 20, (LDU16(LAYOUT + 10) << 5) + LD32(LAYOUT + 12));
    ST16(LAYOUT_A + 4, 4);
    ST16(LAYOUT_A + 12, LDU16(LAYOUT_A + 4) + (LDU16(LAYOUT + 2) << 2));
    ST16(LAYOUT_B + 4, LDU16(LAYOUT_A + 12) + (LDU16(LAYOUT + 6) << 2));
    ST16(LAYOUT_B + 12, LDU16(LAYOUT_B + 4) + (LDU16(LAYOUT + 2) << 2));
    ST16(LAYOUT + 16, LDU16(LAYOUT_B + 12) + (LDU16(LAYOUT + 6) << 2));
    GCALL0(0x0609F88E);
    ST32(0x060FBFBC, LD32(0x060FBFB4));
    ST16(LD32(0x060FBFB4), 0x8000);
    ST32(0x060FBFA0, LD32(desc + 16));
    ST32(0x060FBFA4, LD32(desc + 20));
    ST32(0x060FBF8C, LDU16(desc + 8));
    ST32(0x060FBF98, 0);
    GCALL3(0x06094CA8, LD32(0x060FBFA4), 255, LDU16(desc + 8) << 2);
    ST32(0x060FBFB8, 0);
    ST32(0x060FBF90, 4);
    GCALL1(0x0609F66C, 0x8000);
    ST32(0x060FBF7C, 0);
    ST32(0x060FBF78, LD32(0x060FBF7C));
}

void f0609F61E(int a, int b, int c)
{
    POLL();
    GJUMP3(0x0609F274, a, b, c);
}

void f0609F624(unsigned short mode)
{
    ST16(0x060FC002, mode);
    POLL();
    GJUMP1(0x0609D96C, mode);
}

int f0609F66C(short x)
{
    GCALL5(0x0609F354, x, 0, 0, (LD32(0x060FBF68) - 1) & 0xFFFF, (LD32(0x060FBF6C) - 1) & 0xFFFF);
    ST16(0x060FC000, x);
    return x;
}

int f0609F6CC(unsigned short i, gaddr p)
{
    return GJUMP3(0x060949E0, LD32(0x060FBFCC) + i * 32, p, 32);
}

void f0609F708(unsigned short id, unsigned short kind, int pos, unsigned short w)
{
    FRAME(sp, 0);
    int h = LDU16(sp + 2);
    gaddr src = LD32(sp + 4);
    unsigned int size = w * h;
    unsigned int blocks;
    gaddr rec;

    if (kind >= 40)
        size <<= 1;
    else if (kind <= 8)
        size >>= 1;
    blocks = (size + 31) >> 5;
    rec = LD32(0x060FBF84) + id * 10;
    if (LDU16(rec) == 0) {
        ST16(rec, GCALL1(0x060A029A, (unsigned short)blocks));
        ST16(rec + 8, blocks);
    }
    if (blocks <= LDU16(rec + 8)) {
        if (src)
            GCALL3(0x060949E0, LD32(0x060FBFB4) + (LDU16(rec) << 3), src, (blocks << 4) << 1);
        ST16(rec + 4, kind);
        ST16(rec + 6, pos);
        ST16(rec + 2, (w << 5) + h);
    }
}

void f0609F838(unsigned short index)
{
    unsigned int off = index * 10;
    gaddr entry;

    if (LDU16(LD32(0x060FBF84) + off)) {
        entry = LD32(0x060FBF84) + off;
        GCALL2(0x060A0338, LD16(entry), LD16(entry + 8));
        ST16(LD32(0x060FBF84) + off, 0);
    }
}

void f0609F88E(void)
{
    int i;

    for (i = 0; i < LD32(0x060FBF88); i++) {
        POLL();
        ST16(LD32(0x060FBF84) + i * 10, 0);
    }
    if (LDU16(0x060FBFC0 + 24)) {
        gaddr block = LD32(0x060FBFC0 + 20);

        ST32(0x060FBFFC, block);
        ST32(block, 0);
        ST16(LD32(0x060FBFFC) + 4, LD16(0x060FBFC0 + 24));
    } else {
        ST32(0x060FBFFC, 0);
    }
}

void f0609F9A4(unsigned short value)
{
    gaddr entry, p;

    ST32(0x060FBF80, 1);
    ST32(0x060FBFB8, LD32(0x060FBFB8) ^ 1);
    ST32(0x060FBF90, 4);
    ST32(0x060FBF98, value);
    ST32(0x060FBF9C, 0);
    ST32(0x060FBFA8, LD32(0x060FBFA0));
    ST32(0x060FBF94, LD32(0x060FBF90));
    entry = (LD32(0x060FBFB8) << 4) + 0x060FBFDC;
    ST32(0x060FBFAC, LD32(entry));
    ST16(0x060FBFB0, LD16(entry + 4));
    ST16(0x060FC008, LD16(entry + 12));
    p = LD32(0x060FBFAC) + 128;
    ST32(0x060FC004, p);
    ST16(p, 0x4000);
    ST32(0x060FC004, LD32(0x060FC004) + 32);
    ST32(0x060FBF90, LD32(0x060FBF90) + 1);
}

/* Starts the VDP1 command list; the system clip and local coordinate commands only when 060FC002 is 0xFFFF. */
void f0609FA48(void)
{
    FRAME(sp, 44);
    gaddr box = sp - 44;
    gaddr table;
    gaddr cmd;

    GCALL0(0x0609FBC0);
    table = LD32(0x060FBFAC);
    ST16(table + (LD32(0x060FBF90) << 5), 0x8000);
    ST16(LD32(0x060FBFBC), 0x5000);
    if (LDU16(0x060FC002) != 0xFFFF) {
        ST16(LD32(0x060FBFBC) + 2, LDU16(0x060FBFB0) + 16);
        return;
    }
    ST32(0x060FBF90, 0);
    ST16(box, 0);
    ST16(box + 2, 0);
    ST16(box + 4, LD32(0x060FBF68) - 1);
    ST16(box + 6, 0);
    ST16(box + 8, LD32(0x060FBF68) - 1);
    ST16(box + 10, LD32(0x060FBF6C) - 1);
    ST16(box + 12, 0);
    ST16(box + 14, LD32(0x060FBF6C) - 1);
    ST32(0x060FBF90, 1);
    ST16(table, 10);
    ST16(table + 12, 0);
    ST16(table + 14, 0);
    ST32(0x060FBF90, 2);
    cmd = table + 32;
    ST16(cmd, 4);
    ST16(cmd + 4, 232);
    ST16(cmd + 6, LD16(0x060FC000));
    GCALL3(0x060949E0, cmd + 12, box, 16);
    ST16(cmd + 28, 0);
    ST32(0x060FBF90, 3);
    cmd = table + 64;
    ST16(cmd, 10);
    ST16(cmd + 12, LD32(0x060FBF78));
    ST16(cmd + 14, LD32(0x060FBF7C));
    cmd = table + 96;
    ST16(cmd, 0x5000);
    ST16(cmd + 2, LDU16(0x060FBFB0) + 16);
    ST16(LD32(0x060FBFBC) + 2, LD16(0x060FBFB0));
}

void f0609FBC0(void)
{
    if (LD32(0x060FBF9C)) {
        GCALL0(0x060AA57C);
        ST32(0x060FC004, (LD32(0x060FBF90) << 5) + LD32(0x060FBFAC));
    }
}

void f0609FC04(int arg, gaddr src)
{
    gaddr rec;

    if (LD32(0x060FBF98))
        GCALL1(0x060AA50C, arg);
    rec = LD32(0x060FC004);
    ST32(0x060FC004, rec + 32);
    ST32(0x060FBF90, LD32(0x060FBF90) + 1);
    ST16(rec, 10);
    ST16(rec + 12, LD16(src));
    ST32(0x060FBF78, LD16(rec + 12));
    ST16(rec + 14, LD16(src + 2));
    ST32(0x060FBF7C, LD16(rec + 14));
}

void f0609FC50(int arg, gaddr src)
{
    gaddr rec;

    if (LD32(0x060FBF98))
        GCALL1(0x060AA50C, arg);
    rec = LD32(0x060FC004);
    ST32(0x060FC004, rec + 32);
    ST32(0x060FBF90, LD32(0x060FBF90) + 1);
    ST16(rec, 9);
    ST16(rec + 20, LD16(src));
    ST16(rec + 22, LD16(src + 2));
}

void f0609FCA4(int arg, gaddr src)
{
    gaddr rec;

    if (LD32(0x060FBF98))
        GCALL1(0x060AA50C, arg);
    rec = LD32(0x060FC004);
    ST32(0x060FC004, rec + 32);
    ST32(0x060FBF90, LD32(0x060FBF90) + 1);
    ST16(rec, 8);
    ST16(rec + 12, LD16(src));
    ST16(rec + 14, LD16(src + 2));
    ST16(rec + 20, LD16(src + 4));
    ST16(rec + 22, LD16(src + 6));
}

void f0609FCE8(int unit, unsigned short flags, unsigned short pos, gaddr coords)
{
    FRAME(sp, 0);
    int ext = LDU16(sp + 2);
    gaddr cmd;

    if (LD32(0x060FBF98))
        GCALL1(0x060AA50C, unit);
    cmd = LD32(0x060FC004);
    ST32(0x060FC004, cmd + 32);
    ST32(0x060FBF90, LD32(0x060FBF90) + 1);
    ST16(cmd, 6);
    ST16(cmd + 4, flags);
    if ((flags & 56) == 8)
        ST16(cmd + 6, LDU16(0x060FBFD0) + (pos << 2));
    else
        ST16(cmd + 6, pos);
    ST16(cmd + 12, LD16(coords));
    ST16(cmd + 14, LD16(coords + 2));
    ST16(cmd + 16, LD16(coords + 4));
    ST16(cmd + 18, LD16(coords + 6));
    ST16(cmd + 28, ext == 0xFFFF ? 0 : LDU16(0x060FC008) + ext);
}

void f0609FD9E(int unit, unsigned short flags, unsigned short pos, gaddr coords)
{
    FRAME(sp, 0);
    int ext = LDU16(sp + 2);
    gaddr cmd;

    if (LD32(0x060FBF98))
        GCALL1(0x060AA50C, unit);
    cmd = LD32(0x060FC004);
    ST32(0x060FC004, cmd + 32);
    ST32(0x060FBF90, LD32(0x060FBF90) + 1);
    ST16(cmd, 5);
    ST16(cmd + 4, flags);
    if ((flags & 56) == 8)
        ST16(cmd + 6, LDU16(0x060FBFD0) + (pos << 2));
    else
        ST16(cmd + 6, pos);
    GCALL3(0x060949E0, cmd + 12, coords, 16);
    ST16(cmd + 28, ext == 0xFFFF ? 0 : LDU16(0x060FC008) + ext);
}

void f0609FE50(int unit, unsigned short flags, unsigned short pos, gaddr coords)
{
    FRAME(sp, 0);
    int ext = LDU16(sp + 2);
    gaddr cmd;

    if (LD32(0x060FBF98))
        GCALL1(0x060AA50C, unit);
    cmd = LD32(0x060FC004);
    ST32(0x060FC004, cmd + 32);
    ST32(0x060FBF90, LD32(0x060FBF90) + 1);
    ST16(cmd, 4);
    ST16(cmd + 4, flags);
    if ((flags & 56) == 8)
        ST16(cmd + 6, LDU16(0x060FBFD0) + (pos << 2));
    else
        ST16(cmd + 6, pos);
    GCALL3(0x060949E0, cmd + 12, coords, 16);
    ST16(cmd + 28, ext == 0xFFFF ? 0 : LDU16(0x060FC008) + ext);
}

void f0609FF14(int unit, unsigned short flags, unsigned short mask, unsigned short pos)
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
    ST16(cmd, flags);
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
    ST16(cmd + 28, ext == 0xFFFF ? 0 : LDU16(0x060FC008) + ext);
}
