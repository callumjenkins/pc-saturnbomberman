#include "krnl.h"

/* The first six halfwords of VDP1 VRAM, the first command table entry: skip to the next command
 * with a zero link, then the halfword the game keeps at 060BC12E. */
void f0600665C(void)
{
    H16PTR p = (H16PTR)0x25D00000;

    PUT16(p, 0);
    PUT16(p, 0);
    PUT16(p, 2);
    PUT16(p, 0);
    PUT16(p, 0);
    STORE16(p, LD16(0x060BC12E));
}

/* Records of 88 bytes: sets the first word when the byte at 80 is nonzero. */
void f06006B38(short n)
{
    short off = n * 88;
    REF(Rec88) r = BYTEOFF(Rec88, RECS, off);

    if (GET(Rec88, r, flag))
        SET(Rec88, r, active, 1);
}

void f060086E2(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060086EA(void)
{
}

/* Entries of 16 bytes, numbered from 1: clears the byte at 11 and counts it down. */
void f0600940A(int n)
{
    REF(Ent16) e;

    if (n) {
        e = ELEM(Ent16, ENTS, n - 1);
        if (GET(Ent16, e, f)) {
            SET(Ent16, e, f, 0);
            ST8(CNT, LD8(CNT) - 1);
        }
    }
}

void f0600942E(void)
{
    unsigned int i = 1;

    do {
        POLL();                 /* the game's bsr */
        f0600940A(i);
    } while (AGAIN(++i <= 16));
}

void f06009ECE(unsigned int n)
{
    POLL();
    if ((unsigned char)LD8(0x060B2E84) == 2) {
        ST8(0x060BF4DC, n > 30 ? 30 : n);
        ST8(0x060BF4DD, LD8(0x060BF4DC) * 7);
    }
}

/* Zeroes the bytes at 6 and 7, then runs f0600A186 on the same record. */
void f0600A1F4(gaddr p)
{
    ST8(p + 7, 0);
    ST8(p + 6, 0);
    GJUMP1(0x0600A186, p);
}

/* Objects of 84 bytes: adds d to the 32-bit value held as two halfwords at 12 (low) and 16 (high). */
void f0600A25E(int d)
{
    REF(Obj84) o = BYTEOFF(Obj84, OBJS, (unsigned short)(LDU16(OBJIDX) * 84));
    unsigned int v = ((unsigned int)GET(Obj84, o, w16) << 16) + (unsigned short)GET(Obj84, o, w12) + d;

    SET(Obj84, o, w16, v >> 16);
    SET(Obj84, o, w12, v);
}

/* The same at 14 (low) and 18 (high). */
void f0600A2D8(int d)
{
    REF(Obj84) o = BYTEOFF(Obj84, OBJS, (unsigned short)(LDU16(OBJIDX) * 84));
    unsigned int v = ((unsigned int)GET(Obj84, o, w18) << 16) + (unsigned short)GET(Obj84, o, w14) + d;

    SET(Obj84, o, w18, v >> 16);
    SET(Obj84, o, w14, v);
}

/* Adds the sign-extended halfword, times 256, to the object's 32-bit value at 14 and 18. */
void f0600A306(short d)
{
    GJUMP1(0x0600A2D8, d * 256);
}

/* Adds the low byte, signed, times 0x1000 to the 32-bit value at 14 (low) and 18 (high). */
void f0600A32A(signed char d)
{
    REF(Obj84) o = BYTEOFF(Obj84, OBJS, (unsigned short)(LDU16(OBJIDX) * 84));
    unsigned int v = ((unsigned int)GET(Obj84, o, w18) << 16) + (unsigned short)GET(Obj84, o, w14) + d * 0x1000;

    SET(Obj84, o, w18, v >> 16);
    SET(Obj84, o, w14, v);
}

void f0600A3E0(REF(Pos) p, gaddr b, int c)
{
    SET(Pos, p, w20, GET(Pos, p, w16) - c);
    SET(Pos, p, w24, GET(Pos, p, w16) + GETB(b, 0) - GETB(b, 2) + c);
}

/* The highest of four pad bits: 0x4000 is 3, 0x2000 is 2, 0x8000 is 1, 0x1000 is 4. */
int f0600A4B0(unsigned int x)
{
    if (x & 0x4000)
        return 3;
    if (x & 0x2000)
        return 2;
    if (x & 0x8000)
        return 1;
    if (x & 0x1000)
        return 4;
    return 0;
}

void f0600AC1E(int buttons)
{
    int i;

    for (i = 0; i < 4; i++)
        if (buttons & (4 << i))
            ST16(0x060FA9C0, LD16(0x060FA9C0) | 1 << i);
    if (buttons)
        ST16(0x060FA9A0, LD16(0x060FA9A0) | 0x8000);
    ST16(0x060BB8FC, 1);
}

int f0600B934(int n, int m)
{
    return (10 * n + m) * 152 + 0x00207F74;
}

int f0600B950(int n, int m)
{
    return (10 * n + m) * 16 + 0x060B30C4;
}

int f0600BD3C(void)
{
    unsigned char kind = LD8(0x060C029C);

    if (kind == 17)
        return 196;
    if (kind >= 9)
        return LD16(0x060B356E + (unsigned char)LD8(0x060C029D) * 2);
    if (kind == 8)
        return 0x404;
    return 0;
}

void f0600C364(void)
{
    int i;

    i = 0;
    do {
        ST16(0x060F08B0 + i * 2, 0);
        ST16(0x060EE8B0 + i * 2, 0);
        ST16(0x060EC8B0 + i * 2, 0);
    } while (AGAIN(++i < 0x1000));
    ST16(0x060D7E6A, 0);
    i = 0;
    do {
        ST16(0x060D7E6C + i * 2, 0);
        ST32(0x060D7EA4 + i * 4, 0);
        ST16(0x060D7E74 + i * 2, 0);
    } while (AGAIN(++i < 4));
}

void f0600C4B0(void)
{
    ST32(0x060D7E98, LD32(0x060D7E9C));
    ST32(0x060D7E94, 0x060F68B0);
    ST32(0x060D7EA0, LD32(0x060D7EAC));
}

int f0600C962(unsigned short x, unsigned short y)
{
    return ((y >> 5) << 15) + ((x >> 5) << 14) + ((y & 31) << 9) + ((x & 31) << 3);
}

void f0600D900(void)
{
    ST16(0x060D82CA, 0);
}
