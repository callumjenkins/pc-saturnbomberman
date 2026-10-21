#include "krnl.h"

void f06090266(void)
{
}

int f060949D0(int x)
{
    return x < 0 ? -x : x;
}

/* Length of a zero-terminated string. */
int f06094A6C(gaddr s)
{
    int n;

    for (n = 0; LD8(s + n); n++)
        POLL();
    return n;
}

int f060958E4(void)
{
    return 0x25818000;
}

void f0609591C(unsigned short bits)
{
    ST16(0x060FA8B8, LDU16(0x060FA8B8) | bits);
}

int f06096A7C(void)
{
    return 0;
}

void f06096BCE(gaddr p)
{
    ST32(p, 0);
}

int f0609720A(gaddr p)
{
    return LD32(p + 88);
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

int f060980DC(short v)
{
    return v << 16;
}

int f060980E4(int x)
{
    return (short)(x >> 16);
}

/* 20100061 is SMPC's status register. */
void f060997BC(void)
{
    if ((unsigned int)LD32(0x060FA964) >= 0x20100061 && (LD8(0x20100061) & 0x20))
        ST8(0x060FA970, 2);
}

void f06099F0C(gaddr p)
{
    int i;

    ST32(p, 0);
    ST32(p + 4, 0);
    for (i = 8; i < 15; i++)
        ST8(p + i, 0);
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

int f0609C062(void)
{
    return (LDU16(0x060FA9AE) & 0x3000) >> 12;
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

void f0609DA54(void)
{
    int p;

    ST16(0x060BB91C, 0);
    ST32(0x060BB920, 1);
    for (p = 0x060BB924; p <= 0x060BB934; p += 4)
        ST32(p, 0);
    ST32(0x060FBF34, 0);
}

int f0609EFD4(signed char x)
{
    return x >= 0 ? x : 16 - x;
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

void f0609F448(int flag)
{
    ST16(0x060FBF72, flag ? 16 : 0);
}

void f0609F61E(int a, int b, int c)
{
    POLL();
    GJUMP3(0x0609F274, a, b, c);
}

int f0609F624(unsigned short mode)
{
    ST16(0x060FC002, mode);
    POLL();
    return GJUMP1(0x0609D96C, mode);
}
