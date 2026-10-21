#include "krnl.h"

void f060614F8(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 15);

    ST16(OBJS + 4 + (unsigned short)(GET(Slot24, s, obj) * 84), 1);
    SET(Slot24, s, fn, 0x0603DDA6);
}

void f060633F2(short n)
{
    SET(Slot24, BYTEOFF(Slot24, SLOTS, (short)(n * 24)), fn, 0x06063406);
}

int f06065460(void)
{
    return (unsigned char)LD8(0x060C02A1);
}

void f06066B5E(void)
{
    ST16(0x060D7BB6, 1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06068FF0(void)
{
    return 0;
}

/* The halfwords at 6 and 8 name the neighbours: each is made to point at the other. */
void f06069392(unsigned short i)
{
    REF(ObjLink) o = (REF(ObjLink))OBJ(i);

    SET(ObjLink, (REF(ObjLink))OBJ(GET(ObjLink, o, prev)), next, GET(ObjLink, o, next));
    SET(ObjLink, (REF(ObjLink))OBJ(GET(ObjLink, o, next)), prev, GET(ObjLink, o, prev));
}

void f0606948A(unsigned short n)
{
    short v = GET(Obj84, BYTEOFF(Obj84, OBJS, (unsigned short)(n * 84)), w18);

    if (v < 0)
        v = 0;
    else if (v > 0x1CB)
        v = 0x1CB;
    GJUMP2(0x06069462, n, v + 20);
}

unsigned short f06069606(gaddr p)
{
    int k = (LDU16(0x060FB89C) & 15) * 4;

    return LDU16(p + 46) & LDU16(0x060B7BAA + k) & LDU16(0x060B7BEA + k);
}

void f0606AA06(void)
{
    ST16(0x060B7BA4, 0);
    ST16(0x060B7BA6, 0);
}

void f0606AB4A(gaddr p)
{
    ST16(p + 42, LD16(p + 42) | 0x80);
}

void f0606B34A(void)
{
}

int f0606BCD2(int n)
{
    REF(Pair12) p = BYTEOFF(Pair12, 0x060C1F42, (signed char)(n * 12));

    return GET(Pair12, p, a) <= 2 && GET(Pair12, p, b) <= 2;
}

int f0606BFE8(int n)
{
    return LD16(0x060C1F44 + (signed char)(n * 12)) < 0;
}

int f0606C168(int n, unsigned int limit)
{
    signed char off = n * 12;
    gaddr p = 0x060C1F42 + off;

    return (unsigned int)(LDU16(p + 8) + LDU16(p + 10)) > limit;
}

/* Returns the table's address, which the caller reached through 0606AF68 reads. */
int f0606CF28(int n)
{
    gaddr flags = 0x060D5F34 + n * 124;

    ST8(flags, LD8(flags) | 0x40);
    return 0x060D5F34;
}

int f0606F2CC(int cur, int target, int step, int limit)
{
    int diff = target - cur;

    if (diff > 0xFFFF) {
        cur += step;
        if (target - cur > limit)
            cur += step * 2;
    } else if (diff < -0xFFFF) {
        cur -= step;
        if (cur - target > limit)
            cur -= step * 2;
    }
    return cur;
}
