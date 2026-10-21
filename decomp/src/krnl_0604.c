#include "krnl.h"

/* 0 and 1 pick a table; any other value is taken as the table's address. */
int f06040890(int table, short i)
{
    switch ((short)table) {
    case 0:
        table = 0x060B5F1C;
        break;
    case 1:
        table = 0x060B5FF8;
        break;
    }
    return table + i * 8;
}

int f060408F4(short n)
{
    REF(Slot24) s = BYTEOFF(Slot24, SLOTS, (short)(n * 24));

    return GET(Slot24, s, w18) != 0xFF;
}

void f060429A8(void)
{
    SET(Slot24, ELEM(Slot24, SLOTS, 1), fn, 0x06042864);
}

int f060465AC(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 4);

    if (!GET(Slot24, s, w12))
        return 0;
    return LDU16(OBJS + 60 + (unsigned short)(GET(Slot24, s, obj) * 84)) >= 0xFF00;
}

int f060496E4(void)
{
    unsigned char i = LD8(0x060C063F);

    if ((LD32(0x060C1048) & 0xC00) == 0x400)
        return LD32(0x060B68C0 + (unsigned char)LD8(0x060C064A + i) * 4);
    return LD32(0x060B68F0 + ((unsigned char)LD8(0x060C0640 + i) >> 2) * 4);
}

void f0604D568(void)
{
    ST8(0x060C179A, 0);
    ST8(0x060C179B, 0);
    ST8(0x060C029E, 0);
    ST8(0x060C029F, 0);
    ST8(0x060C179C, 0);
    ST8(0x060C179D, 0);
}

/* The same greater-pair rule as f060236DE, on 179A and 179B. */
void f0604D780(unsigned int a, unsigned int b)
{
    unsigned char best = LD8(0x060C179A);

    if (best >= a) {
        if (best == a && (unsigned char)LD8(0x060C179B) < b)
            ST8(0x060C179B, b);
    } else {
        ST8(0x060C179A, a);
        ST8(0x060C179B, b);
    }
}

void f0604D8B2(void)
{
    POLL();
    ST8(0x060C17A0, LD8(0x060C179A));
    ST8(0x060C17A1, LD8(0x060C179B));
    ST8(0x060C179F, 1);
}

void f0604DFFE(gaddr p)
{
    int obj = OBJ(LDU16(p + 10));
    int v = (LD16(0x2600603A) & 31) - 16;
    int d = v * v;

    ST16(obj + 70, 0x180 - (d > 192 ? 192 : d));
    ST16(obj + 68, 0x100 + (d > 96 ? d - 96 : 0));
}

void f0604EB80(void)
{
}

void f0604F07C(void)
{
    ST16(0x060DFE18, LD16(0x060FB8C2));
    ST16(0x060DFE1A, LD16(0x060FB8C4));
    ST16(0x060DFE1C, LD16(0x060FB8BA));
    ST16(0x060DFE1E, LD16(0x060FB8BC));
    ST16(0x060DFE20, LD16(0x060FB8AA));
    ST16(0x060DFE22, LD16(0x060FB8A8));
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
}

unsigned short f0604F1EE(void)
{
    return (unsigned char)LD8(0x060C02A0) != 255;
}

/* Folds the six bytes at 060C17A4 into four: their sum, OR, AND NOT and XOR. */
void f0604FC44(gaddr out)
{
    int i;

    ST8(out + 2, 0);
    ST8(out + 1, 0);
    ST8(out, 0);
    ST8(out + 3, 0xFF);
    i = 0;
    do {
        ST8(out, LD8(out) + LD8(0x060C17A4 + i));
        ST8(out + 1, LD8(out + 1) | LD8(0x060C17A4 + i));
        ST8(out + 2, LD8(out + 2) & ~LD8(0x060C17A4 + i));
        ST8(out + 3, LD8(out + 3) ^ LD8(0x060C17A4 + i));
    } while (AGAIN(++i < 6));
}
