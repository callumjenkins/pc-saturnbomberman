#include "krnl.h"

void f0602116A(int i)
{
    ST16(0x060EE8B0 + i * 2, LD16(0x060EE8B0 + i * 2) | 0xF00);
}

void f060213C8(void)
{
    int mode = (unsigned char)LD8(0x060C029C);
    int y, x, cell;

    for (y = LDU16(0x060D7E7E); y <= LDU16(0x060D7E82); y++) {
        for (x = LDU16(0x060D7E7C); x <= LDU16(0x060D7E80); x++) {
            cell = (y * 64 + x) * 2;
            ST16(0x060EE8B0 + cell, LD16(0x060EE8B0 + cell) & 0xF0FF);
            if (mode == 8)
                ST16(0x060F18B0 + cell, LD16(0x060F18B0 + cell) & 0xFFEF);
            POLL();
        }
        POLL();
    }
}

int f06021562(void)
{
    unsigned char id = (LD8(0x060DFA14) + 1) & 127;

    if (!id)
        id = 1;
    ST8(0x060DFA14, id);
    ST8(0x060DF994 + id, 1);
    return id;
}

void f06021604(int points, int who)
{
    int rec = (OBJECTS + 0x30) + who * 124;
    int total = 0x060C0690 + who * 4;
    int round = 0x060C0698 + who * 4;
    int team;

    if ((LD8(rec + 4) & 128) || points == 0)
        return;
    ST32(total, LD32(total) + points);
    ST32(round, LD32(round) + points);
    if ((unsigned int)LD32(total) >= 9999999)
        ST32(total, 9999999);
    if ((unsigned int)LD32(round) >= 9999999)
        ST32(round, 9999999);
    if (LDU16(rec + 46) & 0x800) {
        team = 0x060D82DC + who * 20 + (LDU16(0x060D5F70 + LDU16(rec + 36) * 124) - 1) * 4;
        ST32(team, LD32(team) + points);
        if ((unsigned int)LD32(team) >= 9999999)
            ST32(team, 9999999);
    }
}

void f060217E4(int n)
{
    int q = 0x060DFB96 + n * 8;

    ST16(q + 2, 0);
    ST16(q, 0);
    ST8(q + 7, 0);
    ST8(q + 6, 0);
    ST8(q + 5, 0);
    ST8(q + 4, 0);
}

unsigned char f06021F82(int i)
{
    return LD8(0x060DFB9B + (unsigned char)LDU16(0x060F08B0 + i * 2) * 8);
}

void f06022F14(void)
{
    REF(Slot24) s = BYTEOFF(Slot24, SLOTS, (short)(LDU16(0x060D7B44) * 24));

    ST32(0x060D7E60, s);
    if (GET(Slot24, s, obj)) {
        GCALL2(0x060692DC, (unsigned short)GET(Slot24, s, obj), 0x060D7E60);
        GCALL0(0x06022DC8);
        ST16(0x060D7B40, LD16(0x060D7B40) - 1);
    }
}

int f06022F9C(unsigned int first, unsigned int last)
{
    unsigned int i = first;
    REF(Slot24) s = BYTEOFF(Slot24, SLOTS, (short)(first * 24));

    if (first > last)
        return first;
    while (GET(Slot24, s, obj)) {
        i++;
        s = BYTEOFF(Slot24, s, 24);
        if (i > last)
            break;
        POLL();
    }
    return i;
}

int f0602308C(void)
{
    return (unsigned int)LD8(0x060C029C) < (unsigned int)LD8(0x060C029E)
        || (unsigned int)LD8(0x060C029D) < (unsigned int)LD8(0x060C029F);
}

void f060230AE(void)
{
    ST8(0x060C02A5, LD8(0x060C02A5) + 1);
}

int f06023602(int i)
{
    if (LD8((OBJECTS + 0x30) + 4 + i * 124) & 128)
        return 0;
    if (LDU16(0x060D7E68) & 64)
        return LD8(0x060C02A8 + i);
    return 1;
}

void f06023632(void)
{
    ST8(0x060C02A8, 1);
    ST8(0x060C02A9, 1);
}

/* Keeps the greater pair of (a, b) in 029E and 029F, and the latest in 029C and 029D. */
void f060236DE(unsigned int a, unsigned int b)
{
    unsigned char best = LD8(0x060C029E);

    if (best >= a) {
        if (best == a && (unsigned char)LD8(0x060C029F) < b)
            ST8(0x060C029F, b);
    } else {
        ST8(0x060C029E, a);
        ST8(0x060C029F, b);
    }
    ST8(0x060C029C, a);
    ST8(0x060C029D, b);
}

int f06023774(void)
{
    return GJUMP4(0x06015012, 5, 6, 0x100, 0x00010000);
}

int f06023780(void)
{
    return GJUMP4(0x06015012, 1, 2, 0, 0x00040000);
}

void f06023E50(int n)
{
    GJUMP1(0x0600A32A, LD8(0x060B4AF0 + n * 4 + (LDU16(0x060C067E) & 3)));
}

int f06024168(void)
{
    return GJUMP4(0x06015012, 4, 2, 0x900, 0x00014000);
}

int f06024752(unsigned int cell)
{
    unsigned int col = cell >> 6;

    if ((LDU16(0x060EE8B0 + cell * 2) & 255) == 13)
        return 1;
    return col <= LDU16(0x060D7E7E) + 4u || col >= LDU16(0x060D7E82) - 2u;
}

int f0602561E(short a, short b, short c, short d)
{
    ST16(0x060C02C2, a);
    ST16(0x060C02C4, b);
    ST16(0x060C02C6, c);
    ST16(0x060C02C8, d);
    return 0x060C02C8;
}

int f06026270(gaddr table)
{
    int who = LDU16(0x060C062C);
    unsigned int pad = LDU16(0x26006096 + who * 2);

    if (!(pad & 0xF000))
        pad = LDU16(0x060B4800 + (unsigned char)LD8((OBJECTS + 0x30) + who * 124 + 6) * 2);
    while (LD16(table)) {
        POLL();
        if ((LDU16(table) & pad) == LDU16(table))
            break;
        table += 4;
    }
    return LD16(table + 2) + 1;
}

void f06026542(int n)
{
    int rec = 0x060D7B48 + (short)(n * 24);

    ST32(0x060D7E60, rec);
    ST32(0x060D7E64, OBJ(LDU16(rec + 8)));
}

int f060273F4(int v)
{
    unsigned int other = LDU16(0x060D7E8C);

    if (other == 0xFFFF)
        return v;
    if ((LD8(0x060C0640 + LDU16(0x060C062C)) & 28) == (LD8(0x060C0640 + other) & 28))
        return 0;
    return v;
}

/* Not in krnl.c: the cosim counts 35 polls for the game's code, the recompile does 36 (see notes.md). */
void f06027684(void)
{
    int i = 0;

    do {
        ST32(0x060C0A4C + i * 4, 0);
    } while (AGAIN(++i < 19));
    i = 0;
    do {
        ST32(0x060C0A00 + i * 4, 0);
    } while (AGAIN(++i < 19));
    ST32(0x060C0A18, (unsigned char)LD8(0x060D5F37));
    ST32(0x060C0A98, 0);
}

void f0602769A(void)
{
    int i = 0;

    do {
        ST32(0x060C0A00 + i * 4, 0);
    } while (AGAIN(++i < 19));
    ST32(0x060C0A18, (unsigned char)LD8(0x060D5F37));
    ST32(0x060C0A98, 0);
}

void f06027994(void)
{
    int i = 0;
    int q;

    do {
        if (i != 6 && i != 15 && i != 16)
            ST32(0x060C0A4C + i * 4, LD32(0x060C0A4C + i * 4) + LD32(0x060C0A00 + i * 4));
    } while (AGAIN(++i < 19));
    q = 0x060C09B0 + ((unsigned char)LD8(0x060C029D) - 1) * 4;
    if ((unsigned int)LD32(0x060C0698) > (unsigned int)LD32(q))
        ST32(q, LD32(0x060C0698));
}

int f060279E2(void)
{
    int sum = 0;
    int i = 0;

    do {
        if (i != 15 && i != 16)
            sum += LD32(0x060C0A4C + i * 4);
    } while (AGAIN(++i < 19));
    return sum < 0 ? 0 : sum;
}

void f06028E94(void)
{
    int obj;
    int row = 0;
    int col = 0;
    int rowDist = 0x100;
    int colDist = 0x140;
    int dist;
    int i;

    if ((unsigned char)LD8(0x060C02A0) >= 4)
        return;
    if ((unsigned char)LD8(0x060C02A2) == 1)
        return;
    obj = OBJ(LDU16(0x060D7CB8));
    i = 0;
    do {
        dist = LD16(0x060B5012 + i * 16) - LD16(obj + 18) - 40;
        if (dist < 0)
            dist = LD16(obj + 18) - LD16(0x060B5012 + i * 16) + 40;
        if (rowDist > dist) {
            rowDist = dist;
            row = i;
        }
    } while (AGAIN(++i < 3));
    i = 0;
    do {
        dist = LD16(0x060B5010 + row * 16 + i * 4) - LD16(obj + 16);
        if (dist < 0)
            dist = -dist;
        if (colDist > dist) {
            colDist = dist;
            col = i;
        }
    } while (AGAIN(++i < 4));
    if (colDist >= rowDist)
        rowDist = colDist;
    if (rowDist <= 32 || LD8(0x060C02A2))
        ST8(0x060C02A1, row * 4 + col);
    else
        ST8(0x060C02A1, 100);
    if (!LD8(0x060C02A2) && (unsigned char)LD8(0x060C02A0) == 2)
        ST8(0x060C02A2, (unsigned char)LD8(0x060C02A1) == 100 ? 1 : 2);
}

int f06029166(int n)
{
    return n == 3 || n == 4;
}

void f0602917C(void)
{
    int i = 0;

    do {
        ST8(0x26006088 + i, LD8(0x26006062 + i));
        ST16(0x26006070 + i * 2, LD16(0x2600604A + i * 2));
    } while (AGAIN(++i < 12));
    ST8(0x26006094, LD8(0x2600606E));
}

void f0602977C(int pad)
{
    int v = LD16(0x060FB8CA);

    v = (v & ~0x01) | (pad & 4 ? 0x01 : 0);
    v = (v & ~0x02) | (pad & 8 ? 0x02 : 0);
    v = (v & ~0x04) | (pad & 16 ? 0x04 : 0);
    v = (v & ~0x08) | (pad & 32 ? 0x08 : 0);
    v = (v & ~0x10) | (pad & 1 ? 0x10 : 0);
    v = (v & ~0x01) | (pad & 2 ? 0x01 : 0);
    v = (v & ~0x40) | (pad & 0x100 ? 0x40 : 0);
    v = (v & ~0x20) | (pad & 0x80000 ? 0x20 : 0);
    v = (v & ~0x02) | (pad & 128 ? 0x02 : 0);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 4);
    ST16(0x060FB8CA, v);
}

void f060298F4(int pad)
{
    unsigned int v = LDU16(0x060FB8CC);

    ST8(0x060FB8DC, LD8(0x060FB8DC) | 4);
    v = pad & 4 ? v & ~1u : v | 1;
    v = pad & 8 ? v & ~2u : v | 2;
    v = pad & 16 ? v & ~4u : v | 4;
    v = pad & 32 ? v & ~8u : v | 8;
    v = pad & 1 ? v & ~16u : v | 16;
    v = pad & 2 ? v & ~1u : v | 1;
    v = pad & 0x100 ? v & ~64u : v | 64;
    v = pad & 0x00080000 ? v & ~32u : v | 32;
    v = pad & 128 ? v & ~2u : v | 2;
    ST16(0x060FB8CC, v);
}

void f06029FB8(void)
{
    ST16(0x060EC450, 0);
    ST16(0x060FAA3A, 0);
    ST32(0x060FAA40, 0x00023000);
    ST32(0x060FAA44, 0x00024000);
    ST16(0x060EC452, 0);
}

void f0602A750(void)
{
    int i = 0;
    int rec;

    do {
        rec = 0x060C0DF0 + i * 10;
        ST16(rec, -1);
        ST16(rec + 2, 0);
        ST16(rec + 4, 0x100);
        ST16(rec + 6, 0);
        ST16(rec + 8, 0x100);
    } while (AGAIN(++i < 40));
    ST16(0x060C0F80, 0);
}

void f0602B042(unsigned short on)
{
    if (on)
        ST32(0x060C1048, LD32(0x060C1048) | 0x00040000);
    else
        ST32(0x060C1048, LD32(0x060C1048) & ~0x00040000);
}

void f0602B328(unsigned short i, gaddr flags)
{
    ST8(flags + i, LD8(flags + i) | 128);
}

void f0602B334(unsigned short i, gaddr table)
{
    ST8(table + i, LD8(table + i) & 127);
}

int f0602B930(int i)
{
    i++;
    if ((short)i < 10) {
        do {
            if (LD8(0x060C0640 + (short)i) & 3)
                break;
            i++;
        } while (AGAIN((short)i < 10));
    }
    return i;
}

int f0602B976(int n)
{
    int i = n - 1;

    if ((short)i >= 0) {
        do {
            if (LD8(0x060C0640 + (short)i) & 3)
                break;
        } while (AGAIN((short)--i >= 0));
    }
    return i;
}

int f0602B9EC(void)
{
    int bits = 0;
    int i = 0;

    do {
        if (!LD8(0x26006134 + i))
            bits |= LDU16(0x260060B0 + i * 2);
    } while (AGAIN(++i < 10));
    return bits;
}

int f0602BA34(void)
{
    int i = 0;
    int bits = 0;

    do {
        if (LD8(0x26006134 + i) == 0)
            bits |= LDU16(0x26006096 + i * 2);
    } while (AGAIN(++i < 10));
    return bits;
}

void f0602BFA8(unsigned short on)
{
    if (on)
        ST32(0x060C1048, LD32(0x060C1048) | 0x00080000);
    else
        ST32(0x060C1048, LD32(0x060C1048) & ~0x00080000);
}

int f0602C430(short team)
{
    int count = 0;
    int i;
    unsigned char b;

    for (i = 0; i < 10; i++) {
        b = LD8(0x060C0640 + i);
        if ((b & 3) && (b & -4) == team * 4)
            count++;
        POLL();
    }
    return count;
}

int f0602C61E(void)
{
    return GJUMP1(0x0602C5BC, -1);
}

void f0602D7C0(unsigned char n)
{
    int delta = (signed char)(LD8(0x060E20EB + (signed char)(n * 14)) + LD16(0x060C0FBE));
    int step = 0;
    int v = LD16(0x060C0FBE);

    if (delta)
        step = (delta < 0 ? -delta : delta) >= 2 ? 2 : 1;
    if (delta > 0)
        v -= step;
    else if (delta < 0)
        v += step;
    ST16(0x060C0FBE, v & 255);
}

int f0602D866(short n)
{
    return (((unsigned char)LD8(0x060E20EB + (signed char)(n * 14)) + LDU16(0x060C0FBE)) & 255) == 0 ? -1 : 0;
}

void f0602E084(void)
{
    if (LD32(0x060C1040) & 1)
        return;
    if (LDU16(0x26006096) == 112)
        ST8(0x060C0FC0, LD8(0x060C0FC0) + 1);
    else
        ST8(0x060C0FC0, 0);
    if ((unsigned char)LD8(0x060C0FC0) > 60) {
        ST32(0x060C1040, LD32(0x060C1040) | 3);
        GJUMP1(0x0600996A, 5);
    }
}

void f0602E2B0(void)
{
    int i = 0;

    do {
        ST8(0x060E1C4E + i, 1);
    } while (AGAIN(++i < 8));
}

void f0602E2C6(void)
{
    int set = 0;
    int i = 0;

    do {
        if (LD8(0x060E1C4E + i))
            set++;
    } while (AGAIN(++i < 8));
    if (set == 0) {
        i = 0;
        do {
            ST8(0x060E1C4E + i, 1);
        } while (AGAIN(++i < 8));
    }
}

void f0602E346(unsigned short i)
{
    ST8(0x060E1C4E + i, 0);
}

void f0602E384(void)
{
    ST8(0x060C0FCF, 0);
}

void f0602E38C(void)
{
    ST8(0x060C0FCF, 2);
}

void f0602E394(void)
{
    ST8(0x060C0FCF, 1);
}

void f0602E39C(void)
{
    ST8(0x060C0FCF, 3);
}

int f0602E656(unsigned int n)
{
    int count = 0;

    if (n >= 10000) {
        n -= 10000;
        count = 1;
        if (n >= 20000) {
            do {
                n -= 20000;
                count++;
            } while (AGAIN(n >= 20000));
        }
    }
    return count;
}

void f0602E674(void)
{
    ST32(0x060C0FE0, 0);
    ST32(0x060C0FDC, 0);
}

int f0602E88E(void)
{
    unsigned int i;

    for (i = 0; i < 10; i++) {
        POLL();
        if (!LD8(0x26006134 + i) && (LDU16(0x26006096 + i * 2) & 0x70) == 0x70)
            break;
    }
    return i == 10 ? 0 : -1;
}

int f0602E9AE(int i)
{
    return LDU16(0x060D5F46 + i * 124) && !LD8(0x26006134 + i);
}

void f0602ED18(int n)
{
    ST32(0x060C1000, n * 0xE10);
    if (LD8(0x060C1004) != 1)
        ST8(0x060C1004, 0);
    ST8(0x060C101B, 1);
}

void f0602ED56(void)
{
    int minutes;

    if (LD16(0x060BF5EA) == 0) {
        minutes = (unsigned char)LD8(0x060C0681);
        ST32(0x060C1000, minutes > 9 ? -1 : minutes * 0xE10);
    } else {
        ST32(0x060C1000, 0x2A30);
    }
    if ((unsigned char)LD8(0x060C1004) != 1)
        ST8(0x060C1004, 0);
    ST8(0x060C101B, 1);
}

void f0602EDFA(void)
{
    ST16(0x060C100A, 128);
}

void f0602EE02(void)
{
    ST16(0x060C100A, LD16(0x060C100A) | 2);
}

void f0602EE0C(void)
{
    ST16(0x060C100A, LD16(0x060C100A) & ~2);
}

void f0602EE18(void)
{
    ST16(0x060C100A, LD16(0x060C100A) | 1);
}

void f0602EE22(void)
{
    ST16(0x060C100A, LD16(0x060C100A) & 0xFFFE);
}

int f0602F648(void)
{
    if (LD8(0x060C101A) == 0)
        return 0;
    ST8(0x060C101A, LD8(0x060C101A) - 1);
    return LD8(0x060C101A) == 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602F666(void)
{
    return 0;
}

void f0602FF0A(void)
{
    ST8(0x060C103C, 0);
}
