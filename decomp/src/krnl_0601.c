#include "krnl.h"

/* Clears 2000 records of 14 bytes from 060D8C0C, stepping the pointer kept at CURSOR. */
void f060100F6(void)
{
    int i;
    REF(Rec14) p;

    ST32(CURSOR, 0x060D8C0C);
    i = 0;
    do {
        p = LD32(CURSOR);
        SET(Rec14, p, h0, 0);
        SET(Rec14, p, h2, 0);
        SET(Rec14, p, h4, 0);
        SET(Rec14, p, b6, 0);
        SET(Rec14, p, b7, 0);
        SET(Rec14, p, b8, 0);
        SET(Rec14, p, b9, 0);
        ST32(CURSOR, p + 14);
    } while (AGAIN(++i < 2000));
    ST16(0x060DF980, 0);
}

/* Records of 124 bytes: counts those other than `self` with bit 7 of byte 4 clear and its low two bits not `kind`. */
int f06010832(int self, int kind)
{
    unsigned int i;
    int count = 0;
    gaddr p = 0x060D5F30;

    for (i = 0; i < (unsigned char)LD8(0x060C063D); i++, p += 124) {
        unsigned char flags = LD8(p + 4);

        POLL();
        if (!(flags & 0x80) && (flags & 3) != kind && i != self)
            count++;
    }
    return count;
}

void f06012C7C(gaddr p)
{
    ST8(p + 28, 3);
    ST32(p, 0x06012C88);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060143D8(void)
{
}

/* Takes the first 8-byte slot from 2 to 119 whose first byte is 255 and chains it in after the slot that slot 1 names as previous. */
int f06014516(int value)
{
    REF(Link) head = ELEM(Link, LINKS, 1);
    REF(Link) e, last;
    int i;

    for (i = 2; i < 120; i++) {
        if (GET(Link, ELEM(Link, LINKS, i), tag) == 255)
            break;
        POLL();
    }
    if (i == 120)
        return -1;
    e = ELEM(Link, LINKS, i);
    SET(Link, e, tag, LD8(0x060C062D));
    SET(Link, e, next, 1);
    SET(Link, e, prev, GET(Link, head, prev));
    last = ELEM(Link, LINKS, GET(Link, e, prev));
    SET(Link, last, next, i);
    SET(Link, head, prev, i);
    SET(Link, e, saved, LD32(LD32(0x060D7768)));
    ST32(LD32(0x060D7768), value);
    return i;
}

void f060148AE(int obj, int n)
{
    gaddr p = 0x060D5F30 + n * 124;
    int step = (unsigned char)LD8(p + 6) == 4 ? 1 : -1;
    short v = LD16(OBJS + 4 + (unsigned short)(LD16(p + 22) * 84));

    GJUMP2(0x06069462, obj, v + step);
}

int f06015E96(int n)
{
    gaddr p = 0x060D5F30 + n * 124;
    unsigned int x = (((unsigned int)LDU16(p + 12) << 16) + LDU16(p + 10) - 0xC000) >> 13;

    return x > 9 ? 9 : x;
}

void f06016C9C(unsigned short value)
{
    ST16(0x060C0684, (LDU16(0x060C0684) & 0x0FFF) | (value & 0xF000));
}

void f0601AD70(void)
{
    ST32(0x060D8310, LD32(0x060D7768));
    ST32(0x060D8314, LD32(0x060D7B3C));
}
