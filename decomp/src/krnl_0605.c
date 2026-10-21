#include "krnl.h"

void f060501F4(unsigned short n)
{
    int off = (signed char)(n * 10);
    int i = 0;

    do {
        ST8(0x060C17FC + off + i, LD8(0x060F48B0 + 18 + i));
        ST8(0x060C181A + off + i, LD8(0x060F48B0 + 8 + i));
    } while (AGAIN(++i < 10));
    ST8(0x060C183E + n, LD8(0x060F48B4));
    ST8(0x060C1841 + n, LD8(0x060F48B4) - LD8(0x060F48B0 + 55));
    ST8(0x060C1838 + n, LD8(0x060F48B6));
    ST8(0x060C183B + n, LD8(0x060F48B7));
}

void f06050474(unsigned short n)
{
    int off = (signed char)(n * 10);
    int i = 0;

    do {
        ST8(0x060C181A + off + i, 0);
        ST8(0x060C17FC + off + i, 0);
    } while (AGAIN(++i < 10));
    ST8(0x060C183E + n, 0);
    ST8(0x060C1841 + n, 0);
    ST8(0x060C1838 + n, 0);
    ST8(0x060C183B + n, 0);
}

int f060504B8(void)
{
    int n = 0;
    int i = 0;

    do {
        if (LD8(0x060C1844 + i) == 6)
            n++;
    } while (AGAIN(++i < 3));
    return n;
}

int f060504E2(void)
{
    int n = 0;
    int i = 0;

    do {
        int b = LD8(0x060C1844 + i);

        if (b == 6 || b == 5)
            n++;
    } while (AGAIN(++i < 3));
    return n;
}

int f06050594(void)
{
    return LD8(0x060C17B6) != -1;
}

int f060506B4(unsigned short k)
{
    if (k == 0)
        return 1;
    if (k == 1)
        return 5;
    return 11;
}

int f06050C8C(void)
{
    return (unsigned char)LD8(0x060C17B6) != 255;
}

int f06050CB0(void)
{
    int n = 0;
    int i = 0;

    do {
        if ((unsigned char)LD8(0x060C1844 + i) == 5)
            n++;
    } while (AGAIN(++i < 3));
    return n;
}

int f06051D88(unsigned short flags, int row, int col)
{
    int cell;

    if (LDU16(0x060D7E68) & 33)
        return 0;
    if ((unsigned short)row > 3 || (unsigned short)col > 1)
        return 0;
    if (flags & 32)
        return row * 2 + 0x29B;
    cell = col * 2 + row * 4;
    if (flags & 16)
        return 0x2A4 + cell;
    if (flags & 64)
        return 0x28B + cell;
    return 0;
}

int f06051E1C(unsigned short flags, int row, int col)
{
    if (flags & 32)
        return row + 8;
    if (flags & 16)
        return row * 2 + col + 12;
    if (flags & 64)
        return row * 2 + col;
    return 0;
}

void f06051E4C(short stage, short n)
{
    int kind = (unsigned char)LD8(0x060C18CC);
    int obj = OBJ(LDU16(0x060C17B8 + n * 2));
    int step = kind != 2 ? LD16(0x060B6B6E + n * 2) : LD16(0x060B6B76 + n * 4);

    ST16(obj + 16, step * 8 + (kind != 2 ? 20 : 16));
    ST16(obj + 18, 0);
    if (stage > 1)
        ST16(obj + 16, LD16(obj + 16) - 16);
}

void f0605232C(void)
{
    ST8(0x060C1722, 0);
    ST8(0x060C17D9, 0);
}

void f06052338(void)
{
    ST8(0x060C0681, 3);
    ST8(0x060C0683, 3);
    ST8(0x060C0682, 0);
    ST8(0x060C0680, 0);
    ST8(0x060C029C, 0);
    ST8(0x060C029D, 0);
    ST32(0x060C0694, 0);
    ST32(0x060C0690, 0);
    ST32(0x060C1040, 0);
    ST8(0x060C17DD, 0);
}

void f06053C58(void)
{
    GJUMP1(0x06038268, 0x060C17F2);
}

void f06053EC6(void)
{
    ST16(0x060D7B54, 16);
}

int f06054046(void)
{
    return LD16(0x060D7B58);
}

void f0605417A(short v)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 1);

    SET(Slot24, s, fn, 0x06054086);
    SET(Slot24, s, w18, v);
}

void f06054306(void)
{
    GJUMP1(0x06022EDA, 2);
}

/* Counts the entries below the byte count at 2600606E that are neither 240 nor zero. */
int f06054ED4(void)
{
    int count = 0;
    int i;

    for (i = 0; i < (unsigned char)LD8(0x2600606E); i++) {
        POLL();
        if ((unsigned char)LD8(0x26006088 + i) != 240 && LD8(0x26006088 + i))
            count++;
    }
    return count;
}

void f060550D8(unsigned short value)
{
    ST32(0x060C0AB4, value);
    ST32(0x060C0AB8, value);
}

void f06055616(signed char flag)
{
    unsigned char who;
    REF(Point24) p;

    if (flag) {
        who = LD8(0x060C122C);
        p = ELEM(Point24, POINTS, who);
        SET(Point24, p, link, GET(Point24, p, link) | 64);
        ST16(0x060C185C, who);
    }
}

void f0605650C(signed char enable)
{
    REF(Point24) pt;

    if (!enable)
        return;
    pt = ELEM(Point24, POINTS, (unsigned char)LD8(0x060C122C));
    SET(Point24, pt, link, GET(Point24, pt, link) | 64);
    switch (GET(Point24, pt, y)) {
    case 1:
        ST32(0x060C125C, 0x060488C0);
        break;
    case 2:
        ST32(0x060C125C, 0x06048524);
        break;
    case 3:
        ST32(0x060C125C, 0x06048808);
        break;
    case 4:
        ST32(0x060C125C, 0x06055330);
        break;
    case 5:
    case 7:
        ST32(0x060C125C, 0x0602E052);
        break;
    case 6:
        ST32(0x060C125C, 0x0602DF2E);
        break;
    }
    ST16(0x060C185C, (unsigned char)LD8(0x060C122C));
}

int f06056FA4(unsigned short level)
{
    int n = 0;
    int i = 0;

    do {
        if (LD8(0x060C0640 + i) & 3)
            n++;
    } while (AGAIN(++i < 10));
    if (n < 6)
        return 18;
    return level >= 5 ? 25 : 11;
}

int f06057044(void)
{
    return 12;
}

void f0605788A(void)
{
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 32);
    ST16(0x060FB8B4, (LDU16(0x060FB8B4) & 0xFF) | 0x700);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, (LDU16(0x060FB8A8) & 0xFEFF) | 0x100);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, (LDU16(0x060FB8A8) & 0xFFFD) | 2);
}

void f06057B40(void)
{
    ST32(0x060FAA20, 0);
    ST32(0x060FAA24, 0);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 32);
    ST16(0x060FB8B4, LDU16(0x060FB8B4) & 0xFF);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, LDU16(0x060FB8A8) & 0xFEFF);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, LDU16(0x060FB8A8) & 0xFFFD);
    ST16(0x060BB8FC, 1);
}

void f06058274(void)
{
    int row = 0;
    int col;
    int i = 0;

    do {
        col = 0;
        do {
            ST8(0x060C185E + row * 10 + col, 255);
        } while (AGAIN(++col < 10));
    } while (AGAIN(++row < 11));
    do {
        int v = LD8(0x060E1A98 + i) & 255;

        if (v != 255)
            ST8(0x060C185E + (signed char)((v & 127) * 10) + i, (v & 128) != 0);
    } while (AGAIN(++i < 10));
}

int f06059040(void)
{
    if (!LD8(0x26006135))
        return 2;
    if (LD32(0x060C0AA8) != 2)
        return 1;
    return LD8(0x26006137) ? 1 : 2;
}

void f06059BF2(void)
{
    ST8(0x060C18E3, 1);
    ST8(0x060C18E2, 1);
    ST16(0x060C18EA, 0x4AF);
    ST16(0x060C18E4, 0xFFFF);
}

unsigned short f06059E62(unsigned char n)
{
    if (LD32(0x060C0AA8) == 2 || n == 0)
        return LDU16(0x260060B0 + n * 4);
    return 0x1E00;
}

int f06059EAC(void)
{
    unsigned char a = LD8(0x060C18E2);
    unsigned char b = LD8(0x060C18E3);

    return a == 129 || b == 129 || (a == 128 && b == 128);
}

int f06059EDE(unsigned char a, unsigned char b)
{
    int obj = OBJ(LDU16(0x060C18CE + (a * 2 + (b & 15) + 1) * 2));

    ST16(obj + 70, 0x100);
    ST16(obj + 68, 0x100);
    return 68;
}

int f06059F0E(void)
{
    return (LD8(0x060C18E2) & 255) == 128 && (LD8(0x060C18E3) & 255) == 128;
}

void f0605A556(short flag)
{
    unsigned int bits = LD32(0x060C1238);
    int i = 0;

    ST32(0x060C1234, bits);
    bits &= (LD32(0x060C1048) & 0x3000) == 0x2000 ? 0xFFFFF : 0xFFFF;
    do {
        ST8(0x060C0640 + i, (LD8(0x060C0640 + i) & 0xFC) | (bits & 3));
        bits >>= 2;
    } while (AGAIN(++i < 10));
    if (flag)
        ST32(0x060C1048, LD32(0x060C1048) | 0x10000);
}

void f0605AEE8(short flag)
{
    ST32(0x060C1650, 0);
    if (flag)
        ST32(0x060C1048, LD32(0x060C1048) | 0x01000000);
}

int f0605AF02(unsigned char mode)
{
    int i = 0;

    if (!mode) {
        do {
            ST8(0x060C1905 + i, LD8(0x060C18FC + i));
        } while (AGAIN(++i < 8));
        return 0x060C18FC;
    }
    ST8(0x060C0683, 0);
    do {
        int v = LD8(0x060C1905 + i);

        ST8(0x060C18FC + i, v);
        ST8(0x060E1C4E + i, v);
        ST8(0x060C0683, LD8(0x060C0683) + v);
    } while (AGAIN(++i < 8));
    return 0x060C1905;
}

void f0605AF60(unsigned char mode)
{
    int i;

    if (!mode) {
        ST8(0x060C190D, LD8(0x060C1904));
        return;
    }
    i = 0;
    do {
        ST8(0x060E1C4E + i, 0);
    } while (AGAIN(++i < 8));
    ST8(0x060C1904, LD8(0x060C190D));
    ST8(0x060C0683, LD8(0x060C190D));
}

/* Without a pad bit the game's step is the loop's end pointer, which fails both range checks as 0 would. */
int f0605B094(unsigned char slot)
{
    unsigned short pad = LDU16(PAD_SHADOW);
    int left = 100;
    int step = 0;
    int i = 0;

    do {
        left -= (unsigned char)LD8(0x060C1905 + i);
    } while (AGAIN(++i < 8));
    if (pad & 0x8000)
        step = 1;
    if (pad & 0x4000)
        step = -1;
    if (step > 0 && left - step >= 0)
        ST8(0x060C1905 + slot, LD8(0x060C1905 + slot) + step);
    if (step < 0 && (unsigned char)LD8(0x060C1905 + slot) + step >= 0)
        ST8(0x060C1905 + slot, LD8(0x060C1905 + slot) + step);
    return 100 - left;
}

unsigned char f0605B0F8(void)
{
    unsigned short pad = LDU16(PAD_SHADOW);
    int value = (unsigned char)LD8(0x060C190D);
    int step = 0;

    if (pad & 0x8000)
        step = 1;
    if (pad & 0x4000)
        step = -1;
    if (step > 0 && 100 - step - value >= 0)
        value += step;
    if (step < 0 && step + value >= 0)
        value += step;
    ST8(0x060C190D, value);
    return value;
}

void f0605B50C(short flag)
{
    ST32(0x060C1650, 0);
    if (flag)
        ST32(0x060C1048, LD32(0x060C1048) | 0x00020000);
}

int f0605B570(unsigned char restore)
{
    if (!restore) {
        if ((LD32(0x060C1048) & 0x30) == 0x10)
            ST8(0x060C18FB, LD8(0x060C0683));
        ST8(0x060C18FA, LD8(0x060C0682));
        ST8(0x060C18F9, LD8(0x060C0681));
        return 0x060C0682;
    }
    ST32(0x060C1048, LD32(0x060C1048) | 0x02000000);
    if ((LD32(0x060C1048) & 0x30) == 0x10)
        ST8(0x060C0683, LD8(0x060C18FB));
    ST8(0x060C0682, LD8(0x060C18FA));
    ST8(0x060C0681, LD8(0x060C18F9));
    return 0x060C18FA;
}

void f0605B5C6(unsigned char restore)
{
    if (!restore) {
        ST8(0x060C18F8, LD8(0x060C0680));
    } else {
        ST32(0x060C1048, LD32(0x060C1048) | 0x04000000);
        ST8(0x060C0680, LD8(0x060C18F8));
    }
}

void f0605D724(void)
{
    ST32(0x060D7C50, 0x0605D72C);
}

void f0605DBAE(void)
{
    ST32(0x060D7C80, 0x0605DBB6);
}

void f0605E592(unsigned short i)
{
    if (i < 0x1000 && (LDU16(0x060EE8B0 + i * 2) & 15) != 13)
        ST16(0x060EC8B0 + i * 2, LD16(0x060EC8B0 + i * 2) & 0xF8FF);
}

/* Copies the first n of seven halfwords, from offset 8 of the structure at 060D7E60. */
void f0605EC1E(gaddr dst, short n)
{
    int i = 0;

    if (n <= 0)
        return;
    do {
        if (i <= 6)
            ST16(dst + i * 2, LD16(LD32(0x060D7E60) + 8 + i * 2));
    } while (AGAIN(++i < n));
}

void f0605F86A(void)
{
    (void)LD8(0x060C02A6);
}

void f0605F88A(void)
{
}

int f0605FBF0(unsigned short i, int n)
{
    int kind = LD16(0x060EE8B0 + i * 2) & 255;

    if ((unsigned short)n == 0)
        return 0;
    if (kind == 1 || kind == 2)
        return n;
    if (kind == 3)
        return (3 ^ (n - 1)) + 1;
    if (kind == 4)
        return (1 ^ (n - 1)) + 1;
    return 0;
}
