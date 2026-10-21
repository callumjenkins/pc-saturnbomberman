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
    unsigned int i;

    for (i = 1; i <= 16; i++)
        f0600940A(i);
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

int f0600B934(int n, int m)
{
    return (10 * n + m) * 152 + 0x00207F74;
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

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060086EA(void)
{
}
