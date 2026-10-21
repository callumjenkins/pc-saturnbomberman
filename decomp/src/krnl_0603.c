#include "krnl.h"

void f06031854(short a, short b)
{
    ST16(0x060C1246, a);
    ST16(0x060C1248, b);
}

void f0603185E(unsigned char a, unsigned char b, unsigned char c)
{
    ST8(0x060C123D, a);
    ST8(0x060C123E, b);
    ST8(0x060C123C, c);
}

short f06032FF2(short x)
{
    if (LD8(0x060C063C) && (LD32(0x060C1048) & 0xC00) == 0x800
        && (short)(x * 4) == ((unsigned char)LD8(0x060C0640 + (unsigned char)LD8(0x060C063F)) & -4))
        return -1;
    return 0;
}

void f0603302C(void)
{
    int i;

    ST8(0x060C063C, 0);
    i = 0;
    do {
        if (LD8(0x060C0640 + i) & 3) {
            ST8(0x060C0FC4 + i, 1);
            ST8(0x060C063C, LD8(0x060C063C) + 1);
        } else {
            ST8(0x060C0FC4 + i, 0);
        }
        ST8(0x060E1A98 + i, 0xFF);
    } while (AGAIN(++i < 10));
}

void f06033198(void)
{
    int i, j;

    i = 0;
    do {
        ST8(0x060E1A98 + i, 0);
        j = 0;
        do {
            ST16(0x060E1B6A + (i * 10 + j) * 2, 0);
            ST16(0x060E1AA2 + (i * 10 + j) * 2, 0);
        } while (AGAIN(++j < 10));
    } while (AGAIN(++i < 10));
    i = 0;
    do {
        ST8(0x060E1C4E + i, 0);
        ST8(0x060E1C46 + i, 0);
        j = 0;
        do {
            ST16(0x060E1C56 + (i * 10 + j) * 2, 0);
        } while (AGAIN(++j < 10));
    } while (AGAIN(++i < 8));
    ST8(0x060C0683, 0);
}

void f06033A60(void)
{
    int mode = LD32(0x060C1048) & 48;
    int i;

    if (mode == 16) {
        ST32(0x060C1048, LD32(0x060C1048) & ~0x02000000);
        ST8(0x060C0683, 3);
    } else if (mode == 32) {
        ST32(0x060C1048, LD32(0x060C1048) & ~0x01000000);
        i = 0;
        do {
            ST8(0x060C18FC + i, 0);
            ST8(0x060E1C46 + i, 0);
        } while (AGAIN(++i < 9));
        ST8(0x060C0683, 0);
    }
}

void f060343F8(void)
{
    int n = LD8(0x060C146E);

    if (n < 2)
        ST32(0x060C162C, 1);
    else if (n < 4)
        ST32(0x060C162C, 2);
    else
        ST32(0x060C162C, 4);
}

/* The first of 30 slots of 24 bytes whose word at 12 is not -1 and whose first three halfwords match, or 255. */
int f0603666E(unsigned short x, unsigned short y, unsigned short z)
{
    REF(Point24) s;
    int i;

    for (i = 0; i < 30; i++) {
        POLL();
        s = ELEM(Point24, 0x060EC478, i);
        if (GET(Point24, s, link) != -1 && GET(Point24, s, x) == x && GET(Point24, s, y) == y
            && GET(Point24, s, z) == z)
            break;
    }
    return i < 30 ? i : 255;
}

void f06036E26(short v)
{
    ST16(0x060C1656, v);
}

/* Entries of 24 bytes: the index of the first whose halfword at 4 equals entry n's halfword at 0, or 0xFFFF. */
int f06036FD0(unsigned short n)
{
    unsigned short key;
    int i;

    if (n >= 30)
        return 0xFFFF;
    key = LDU16(0x060EC478 + n * 24);
    i = 0;
    do {
        if (LDU16(0x060EC478 + i * 24 + 4) == key)
            return i;
    } while (AGAIN(++i < 30));
    return 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06038174(void)
{
}

void f060382B6(gaddr ids)
{
    for (; LD16(ids) > 0; ids += 2) {
        POLL();
        ST16(OBJS + (unsigned short)(LDU16(ids) * 84) + 36, -LD16(0x060C1654));
    }
}

void f06039DD8(void)
{
    ST8(0x060C1725, 0);
}

unsigned char f06039FBC(void)
{
    return LD8(0x060C02A2);
}

int f0603A00E(int n)
{
    if (LD8(0x060D5F34 + n * 124) & 192)
        return 0;
    return -1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603AF08(void)
{
}

void f0603B252(unsigned char value)
{
    ST8(0x060C1734, value);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603C7EE(void)
{
}

void f0603C9E4(void)
{
    ST16(0x060C173A, 0);
    ST16(0x060C173C, 1);
    ST16(0x060C173E, 1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603DDA6(void)
{
}

int f0603E212(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 4);
    gaddr o = OBJS + (unsigned short)(GET(Slot24, s, obj) * 84);

    if (!LD16(o + 10) || LDU16(o + 60) >= 0xFF00)
        return -1;
    return 0;
}

void f0603ED78(int n)
{
    GJUMP1(0x06022EDA, n);
}
