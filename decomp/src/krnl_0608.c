#include "krnl.h"

int f060801DC(void)
{
    gaddr cur = LD32(CURRENT);
    int kind;

    if (LD16(cur + 62))
        return 0;
    kind = LD8(cur + 6) & 255;
    if (kind != 1 && kind != 3) {
        gaddr p = LD32(CURRENT) + 6;

        ST8(p, (GCALL0(0x0600A0B8) & 1) ? 1 : 3);
    }
    ST16(LD32(CURRENT) + 66, 0);
    GCALL1(0x06014516, 0x06080230);
    return 1;
}

void f06080396(void)
{
    FRAME(sp, 24);
    gaddr table = sp - 24;
    gaddr obj;

    COPYW(0x06094450, table, 0x060B2BF8, 16);
    obj = LD32(CURRENT);
    ST16(obj + 62, LD32(table + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

int f0608065A(void)
{
    ST16(0x060C1E4A, 1);
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

int f06080840(void)
{
    gaddr mover = LD32(MOVER_PTR);

    ST16(mover + 68, LD16(mover + 68) + 3);
    ST16(mover + 70, LD16(mover + 70) + 3);
    ST8(mover + 78, LD8(mover + 78) + 16);
    return 0;
}

void f06080B08(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 28);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFF3);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFCF);
}

int f06080B3E(int n)
{
    return 16 * (GCALL1(0x0600A0EC, 17 - n * 2) + n) + 48;
}

int f06080B6A(int n)
{
    return 16 * (GCALL1(0x0600A0EC, 11 - n * 2) + n) + 48;
}

int f06081724(void)
{
    return GCALL0(0x0601FEC6) != 0;
}

void f0608173E(int value)
{
    ST16(0x060C28B4, value);
    ST16(LD32(CURRENT) + 62, 0x1E0);
    GCALL1(0x06014516, 0x06081760);
    ST16(0x060C28B8, 0);
}

void f060819B8(void)
{
    int a, b;

    if (LDU16(0x060C28B4) == 0) {
        ST16(LD32(CURRENT) + 12, 2);
        ST16(LD32(CURRENT) + 10, 0x8000);
        a = LDU16(0x060C28B6) == 1 ? 0x130 : 48;
        if (LDU16(0x060C28B8) != 0) {
            b = LDU16(LD32(CURRENT) + 28) + (LDU16(0x060C28B8) == 2 ? 32 : -32);
        } else {
            b = LDU16(LD32(CURRENT) + 28);
            ST16(0x060C28B8, b >= 128 ? 4 : 2);
        }
        if ((LDU16(0x060C28B8) == 4 && (unsigned int)b <= 64) || (LDU16(0x060C28B8) == 2 && (unsigned int)b >= 0xC0))
            ST16(0x060C28B8, LDU16(0x060B90B4 + (LDU16(0x060C28B8) << 1)));
    } else {
        unsigned int ahead;
        unsigned int row;
        int y;

        ST16(LD32(CURRENT) + 12, 2);
        ST16(LD32(CURRENT) + 10, 0x8000);
        row = LDU16(LD32(CURRENT) + 86);
        ahead = row - 64;
        do {
            y = LDU16(LD32(CURRENT) + 28);
            if (y > 48 && y < 0xD0) {
                a = GCALL1(0x06080B3E, 3);
                b = row > 128 ? 48 : 0xD0;
            } else {
                a = ahead >= 128 ? 0x130 : 48;
                b = GCALL1(0x06080B6A, 3);
            }
        } while (AGAIN(LDU16(FLAGS_AT(GCALL2(0x0600CAE4, a, b))) & 0x380));
    }
    GCALL2(0x06074AFA, a, b);
    GCALL1(0x06014516, 0x06074CB4);
    ST16(0x060C28B6, LD16(0x060B90B4 + (LDU16(0x060C28B6) << 1)));
}

void f06081BEC(void)
{
    unsigned short task = LDU16(0x060C28AC);

    if (task) {
        GCALL1(0x060692DC, task);
        ST16(0x060C28AC, 0);
    }
}

int f06081C4C(void)
{
    return GJUMP1(0x06014516, 0x06081C54);
}

void f06081FA4(void)
{
    ST16(0x060C28B0, 2);
    ST16(0x060C28B2, GCALL0(0x0600A0B8) & 128);
    GJUMP1(0x06014516, 0x06081FBE);
}

int f0608255E(void)
{
    if (LDU16(LD32(MOVER_PTR) + 70) < 0x100)
        ST16(LD32(MOVER_PTR) + 70, LD16(LD32(MOVER_PTR) + 70) + 4);
    GCALL1(0x0606CB86, LD32(MOVER_PTR));
    ST16(LD32(MOVER_PTR) + 4, LD16(OBJ(LDU16(REC(LDU16(0x060C28A8)) + 22)) + 4) - 2);
    GCALL3(0x06082A42, LDU16(LD32(CURRENT) + 68), 10, -2);
    GCALL3(0x06082A42, LDU16(LD32(CURRENT) + 70), 20, -4);
    return 0;
}

int f060827EC(void)
{
    GCALL1(0x06082B20, LDU16(LD32(CURRENT) + 68));
    return 0;
}

void f060829F8(void)
{
    if (LD16(LD32(CURRENT) + 68)) {
        GCALL1(0x060692DC, LDU16(LD32(CURRENT) + 68));
        ST16(LD32(CURRENT) + 68, 0);
    }
    if (LD16(LD32(CURRENT) + 70)) {
        GCALL1(0x060692DC, LDU16(LD32(CURRENT) + 70));
        ST16(LD32(CURRENT) + 70, 0);
    }
}

void f06082B20(int n)
{
    gaddr o, m;

    if (n == 0)
        return;
    o = OBJ(n);
    GCALL2(0x06069462, n, 10);
    GCALL2(0x0606AAC8, o, 3);
    GCALL1(0x0606AB92, o);
    ST16(o + 10, LD16(LD32(MOVER_PTR) + 10));
    ST16(o + 16, LD16(LD32(MOVER_PTR) + 16));
    ST16(o + 18, LD16(LD32(MOVER_PTR) + 18));
    m = LD32(MOVER_PTR);
    ST16(o + 70, LD16(m + 38) + 0x100);
    ST16(o + 68, LD16(m + 38) + 0x100);
}

int f06082D32(int a, int b)
{
    int s = GCALL1(0x0606CE8C, LD32(0x26006034) * 3 + a + b);

    return HELPER(s >> 14);
}

void f06082D5E(void)
{
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, (LDU16(0x060FB8A8) & 0xFEFF) | 0x100);
    GCALL1(0x0609E27E, 0x100);
    GCALL1(0x0609E27E, 4);
    GCALL1(0x0609E27E, 8);
    GCALL1(0x0609E27E, 16);
    GCALL2(0x0609C0B4, 0x100, 8);
    GJUMP2(0x0609C0B4, 24, 10);
}

void f06082DD4(void)
{
    GCALL8(0x0609DC4C, 0, 0, 0, 0, 1, 0, 1, 0);
    GCALL1(0x0609E282, 0x100);
    GCALL1(0x0609E282, 4);
    GCALL1(0x0609E282, 8);
    GCALL1(0x0609E282, 16);
    GJUMP2(0x0609C0B4, 0x118, 0);
}

int f0608304C(void)
{
    return 0;
}

int f06083192(void)
{
    gaddr obj = OBJ(LDU16(0x060C28AE));
    gaddr mover = LD32(MOVER_PTR);
    int s, v;

    ST16(obj + 16, LD16(mover + 16));
    ST16(obj + 18, LD16(mover + 18));
    ST16(obj + 4, LD16(mover + 4));
    ST16(obj + 10, LD16(mover + 10));
    s = GCALL1(0x0606CE8C, LD32(0x26006034) << 1);
    v = GCALL1(0x060949D0, s);
    ST16(0x060C28D0, HELPER(v >> 11) + LD16(0x060C28BE));
    return GJUMP3(0x0609B8C0, 0x0004EC00, 1, 0x060C28D0);
}

void f06083258(void)
{
    GCALL1(0x0606CC12, 0x060C28AE);
    GCALL3(0x0609DF54, 0, 0, 0);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB89C, LDU16(0x060FB89C) & 0xFFEF);
    GCALL1(0x0609E282, 0x100);
    GCALL1(0x0609E282, 8);
    GCALL1(0x0609E282, 16);
    GJUMP2(0x0609C0B4, 0x118, 0);
}

int f06083830(void)
{
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) + 2);
    GCALL0(0x06083900);
    return 0;
}

void f06083900(void)
{
    gaddr cur = LD32(CURRENT);
    int ang = LDU16(cur + 68);
    int radius = LDU16(cur + 70);
    gaddr p = 0x060C28C8;

    do {
        gaddr obj = OBJ(LDU16(p));
        int x = LD16(LD32(MOVER_PTR) + 16);
        int s = GCALL1(0x0606CEB0, ang);
        int y;

        ST16(obj + 16, (short)((unsigned int)(s * radius) >> 16) + x - 8);
        y = LD16(LD32(MOVER_PTR) + 18);
        s = GCALL1(0x0606CE8C, ang);
        p += 2;
        ST16(obj + 18, (short)((unsigned int)(s * radius) >> 16) + y + LD16(LD32(MOVER_PTR) + 38) - 8);
        ang += 64;
    } while (AGAIN(p < 0x060C28D0));
}

void f06083BC6(void)
{
    ST32(0x060E2160 + (short)(LD16(0x060C062C) * 20), 0x06083C0A);
    GJUMP1(0x0606D8E6, LDU16(LD32(CURRENT) + 40));
}

void f06083BE8(void)
{
    ST32(0x060E2160 + (short)(LD16(0x060C062C) * 20), 0x06083C18);
    GJUMP1(0x0606D8E6, LDU16(LD32(CURRENT) + 40));
}

int f06083D48(void)
{
    if (LD16(LD32(CURRENT) + 66) != 0) {
        return 0;
    }
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) - 1);
    if (LD16(LD32(CURRENT) + 68) != 0) {
        return 0;
    }
    if (GCALL0(0x060845BC) == 0) {
        ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 70));
        return 0;
    }
    GCALL1(0x06014516, 0x060845E8);
    ST16(LD32(CURRENT) + 66, 1);
    return 1;
}

int f06083DC2(void)
{
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) - 1);
    if (LD16(LD32(CURRENT) + 68) != 0) {
        return 0;
    }
    if (LD16(LD32(CURRENT) + 66) != 0) {
        ST16(LD32(CURRENT) + 40, 17);
        GCALL1(0x0606D8E6, 17);
        ST16(LD32(CURRENT) + 68, 2);
        ST16(LD32(CURRENT) + 66, 0);
        return 1;
    }
    GCALL0(0x0606E81C);
    if (GCALL3(0x0606BCDE, LDU16(LD32(CURRENT) + 64), 5, 5) == 0) {
        ST16(LD32(CURRENT) + 68, 2);
        return 0;
    }
    ST16(LD32(CURRENT) + 40, 1);
    GCALL1(0x0606D8E6, 1);
    ST16(LD32(CURRENT) + 68, 10);
    ST16(LD32(CURRENT) + 66, 1);
    return 1;
}

int f06083F1A(void)
{
    if (LD16(LD32(CURRENT) + 66) != 0) {
        return 0;
    }
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) - 1);
    if (LD16(LD32(CURRENT) + 68) != 0) {
        return 0;
    }
    if (GCALL0(0x060847A4) == 0) {
        ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 70));
        return 0;
    }
    GCALL1(0x06014516, 0x060847C4);
    ST16(LD32(CURRENT) + 66, 1);
    return 1;
}

void f060840C0(int delta)
{
    gaddr cur = LD32(CURRENT);
    unsigned int angle = (LDU16(cur + 66) << 16) + LDU16(LD32(CURRENT) + 68) + delta;

    ST16(LD32(CURRENT) + 12, angle >> 16);
    ST16(LD32(CURRENT) + 10, angle);
}

void f060844B4(void)
{
    unsigned int level = LDU8(0x060C029D) + 1;
    int i = 0;
    gaddr row;

    while (level >= LDU16(0x060BB1FC + (i + 1) * 8)) {
        POLL();
        i++;
    }
    row = 0x060BB1FC + i * 8;
    ST16(LD32(CURRENT) + 66, LD16(row + 2));
    ST16(LD32(CURRENT) + 68, LD16(row + 4));
    ST16(LD32(CURRENT) + 72, LD16(row + 6));
}

int f060845BC(void)
{
    GCALL0(0x0606E81C);
    return GCALL3(0x0606BCDE, LDU16(LD32(CURRENT) + 64), 7, 7) != 0;
}

void f060846D2(void)
{
    GJUMP0(0x060846FE);
}

void f06084794(void)
{
    POLL();
    GJUMP1(0x0606CABE, 0x4000);
}

void f0608479C(void)
{
    GJUMP1(0x0606CABE, -16384);
}

int f060847A4(void)
{
    GCALL0(0x0606E81C);
    return GCALL1(0x0606C390, 3) != 0;
}

void f060848D4(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f06084BD0(void)
{
    int dir = GCALL0(0x0606C5EA);

    if (dir && LDU16(0x060C1F36) > 3) {
        ST8(LD32(CURRENT) + 6, dir);
        return 1;
    }
    return 0;
}

int f06084D48(void)
{
    return (GCALL0(0x0600A0B8) & 1) && GCALL0(0x0606BF22) != 0;
}

int f06084E7E(void)
{
    return (LD8(LD32(CURRENT) + 7) & 255) >= 2 && GCALL0(0x0606BF8C) != 0;
}

void f060854F4(void)
{
    GCALL1(0x06009A3A, 0x130);
    GJUMP1(0x06009A3A, 0x12E);
}

void f0608589C(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f06085B60(void)
{
    return GCALL0(0x0606BF8C) != 0 || GCALL0(0x0606BE44) != 0;
}

int f06085C5E(void)
{
    return GCALL0(0x0606BF22) != 0;
}

int f06085CAE(void)
{
    return (LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20) + LD16(0x060B90A4))) & 32) != 0;
}

int f06085D9C(void)
{
    return GCALL2(0x0606C3F4, 3, 3) != 0;
}

void f06085EC6(void)
{
    GJUMP0(0x06085ECE);
}

int f06085FB4(void)
{
    int tries = 0;

    GCALL0(0x0606DA9E);
    ST16(LD32(CURRENT) + 44, 1);
    do {
        if (LD16(0x060C2E8E + LDU16(0x060C1F24) * 2) == 0 && GCALL0(0x0606B648)) {
            return LDU16(0x060C1F24);
        }
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
        tries++;
    } while (AGAIN(tries < 4));
    tries = 0;
    do {
        if (GCALL0(0x0606B648)) {
            return LDU16(0x060C1F24);
        }
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
        tries++;
    } while (AGAIN(tries < 4));
    return 0;
}

void f0608661C(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f06086964(void)
{
    GCALL0(0x0606E81C);
    return !GCALL3(0x0606BCDE, LDU16(LD32(CURRENT) + 64), 5, 5);
}

int f06086BBE(void)
{
    return GCALL1(0x0606C390, 0) != 0;
}

int f06086CEC(void)
{
    gaddr cur = LD32(CURRENT);
    unsigned int dir = LDU16(0x060B90B4 + (unsigned char)LD8(cur + 6) * 2);
    unsigned int pos = LDU16(cur + 20);

    if (!(LDU16(0x060EE8B0 + ((LD16(0x060B90A0 + dir * 2) + pos) << 1)) & 0xF00))
        return 0;
    if (!(LDU16(0x060EE8B0 + ((pos + LD16(0x060B90AA + dir * 2)) << 1)) & 0xF00))
        return 0;
    if (GCALL1(0x0606C390, 0))
        return 0;
    ST8(LD32(CURRENT) + 6, dir);
    return 1;
}

void f06086D52(void)
{
    ST16(0x060C2E9C, 3);
    ST16(0x060C2E9E, 0);
    GJUMP1(0x060144F4, 0x06086D64);
}

int f06087374(void)
{
    gaddr flags = FLAGS_AT(LDU16(LD32(CURRENT) + 20));

    ST16(flags, LDU16(flags) & 0xFFF7);
    return 0;
}

void f06087390(void)
{
    gaddr cell = LD32(CURRENT) + 20;

    ST16(cell, GCALL0(0x0600CA84));
    if (!(LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20))) & 15)) {
        GJUMP2(0x0606C82C, LDU16(LD32(CURRENT) + 20), 8);
    }
}

void f060873DE(void)
{
    if (LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20))) & 7)
        return;
    GCALL0(0x06087374);
    GJUMP1(0x060144F4, 0x06087406);
}

void f06087406(void)
{
    GCALL1(0x060144F4, 0x0606D398);
    GJUMP1(0x06014516, 0x0606D37A);
}

int f06087418(void)
{
    gaddr p = 0x060C2EA8;
    int n = 1;

    do {
        if (LD16(p) == 0) {
            return n;
        }
        p += 2;
        n++;
    } while (AGAIN(p < 0x060C2EB0));
    return 0;
}

int f06087662(void)
{
    if (!LD16(0x060C2EA6))
        return 0;
    GCALL1(0x060144F4, 0x0606D23C);
    ST16(LD32(CURRENT) + 48, 41);
    return 1;
}

void f060876E0(void)
{
    int dir = GCALL0(0x0600A0B8) & 15;
    int x, y, flags;

    do {
        x = LDU16(LD32(CURRENT) + 24) + LD16(0x060BB354 + dir * 4) * 16;
        y = LDU16(LD32(CURRENT) + 28) + LD16(0x060BB354 + dir * 4 + 2) * 16;
        flags = LDU16(FLAGS_AT(GCALL2(0x0600CAE4, x, y)));
        if (flags & 128) {
            dir = (dir + 3) & 15;
        }
    } while (AGAIN(flags & 128));
    GJUMP2(0x06074AFA, x, y);
}

void f06087758(void)
{
    gaddr p = 0x060C2EA8;

    do {
        if (LD16(p) == LD16(0x060C062C)) {
            ST16(p, 0);
            break;
        }
        p += 2;
    } while (AGAIN(p < 0x060C2EB0));
    GJUMP1(0x060144F4, 0x0606D2C8);
}

void f060877B0(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f06087ACC(void)
{
    return GCALL1(0x0606C390, 0) != 0;
}

int f06087AE6(void)
{
    unsigned short want;
    gaddr cur, cell;

    GCALL0(0x0606E81C);
    GCALL0(0x0606BBB0);
    want = LDU16(0x060C1F24);
    cur = LD32(CURRENT);
    if (want != LDU16(0x060B90B4 + (LD8(cur + 6) & 255) * 2))
        return 0;
    cell = 0x060C1F42 + LDU16(cur + 64) * 12;
    if (LD16(cell + 8) && LD16(cell + 10))
        return 0;
    ST8(cur + 6, want);
    return 1;
}

int f06087C34(void)
{
    return GCALL0(0x0606BF22) != 0;
}

void f06087C68(void)
{
    GJUMP0(0x06087CAC);
}

void f06087C82(void)
{
    GCALL2(0x06068A8E, LDU16(OBJIDX), LDU16(LD32(CURRENT) + 80) + 6);
    GCALL1(0x06014516, 0x0606D88C);
    GJUMP0(0x06087CAC);
}

void f06087C98(void)
{
    GCALL1(0x06014516, 0x0606D88C);
    GJUMP0(0x06087CAC);
}

int f06087FAE(void)
{
    GCALL0(0x0606E81C);
    return !GCALL3(0x0606BCDE, LDU16(LD32(CURRENT) + 64), 5, 5);
}

int f060884C6(void)
{
    int pos;

    ST16(LD32(MOVER_PTR) + 4, LD16(LD32(MOVER_PTR) + 4) + 32);
    pos = LD16(LD32(MOVER_PTR) + 4);
    if (pos >= 0x1E0) {
        pos = 0x1E0;
        ST16(LD32(MOVER_PTR) + 4, pos);
    }
    return pos;
}

int f06088928(void)
{
    gaddr mover = LD32(MOVER_PTR);
    int a, b, c, d, mode;

    ST16(mover + 70, 0x100);
    ST16(mover + 68, 0x100);
    a = LD32(0x060C2EC0);
    c = LD32(0x060C2EC8);
    b = LD32(0x060C2EC4);
    mode = LDU16(0x060C2ED6);
    d = LD32(0x060C2ECC);
    if (mode == 1) {
        mover = LD32(MOVER_PTR);
        ST16(mover + 68, LD16(mover + 68) + (DIVU(a - c, 40) >> 8));
    } else if (mode == 2) {
        mover = LD32(MOVER_PTR);
        ST16(mover + 70, LD16(mover + 70) + ((unsigned int)(b - d) >> 13));
    } else if (mode == 3) {
        mover = LD32(MOVER_PTR);
        ST16(mover + 68, LD16(mover + 68) + (DIVU(c - a, 40) >> 8));
    } else if (mode == 4) {
        mover = LD32(MOVER_PTR);
        ST16(mover + 70, LD16(mover + 70) + ((unsigned int)(d - b) >> 13));
    }
    return 0;
}

void f06088A6C(void)
{
    int y = (unsigned int)LD32(0x060C2EC4) >> 16;

    ST16(0x060C2ED0, (unsigned int)LD32(0x060C2EC0) >> 16);
    ST16(0x060C2ED2, y);
    ST16(0x060C2ED4, GCALL2(0x0600CAE4, LD16(0x060C2ED0), y));
}

int f06088C7E(void)
{
    unsigned int a = LD32(0x060C2EC0);
    unsigned int b = LD32(0x060C2EC8);
    unsigned int c = LD32(0x060C2EC4);
    unsigned int d = LD32(0x060C2ECC);

    switch (LDU16(0x060C2ED6)) {
    case 1:
        return a <= b;
    case 2:
        return c <= d;
    case 3:
        return a >= b;
    case 4:
        return c >= d;
    }
    return 0;
}

void f06088DA4(int cell)
{
    if (LDU16(FLAGS_AT(cell)) & LDU16(LD32(CURRENT) + 18))
        return;
    GJUMP2(0x0606C82C, cell, 0x180);
}

void f06088DC6(int n)
{
    int flags = 0x060EC8B0 + n * 2;

    if ((LDU16(flags) & 0x180) == 0x180)
        ST16(flags, LDU16(flags) & 0xFE7F);
}

void f06088E20(void)
{
    int step = LD16(0x060B90A0 + (LDU16(0x060C2ED6) << 1));
    int pos = LDU16(LD32(CURRENT) + 20) + step;

    while (pos != LDU16(0x060C2ED4)) {
        POLL();
        GCALL1(0x06088DC6, pos);
        pos += step;
    }
    POLL();
    GJUMP1(0x06088DC6, LDU16(0x060C2ED4));
}

void f06088E80(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 28);
    GJUMP0(0x0603C7BC);
}

void f0608905E(void)
{
    GJUMP0(0x0608909C);
}

void f06089080(void)
{
    GJUMP0(0x0608909C);
}

int f060894F2(void)
{
    return GCALL1(0x0606C390, 0) != 0;
}

void f06089752(void)
{
    GJUMP0(0x0608975A);
}

int f06089766(void)
{
    return LDU16(LD32(CURRENT) + 40) == 5 && GCALL0(0x0606C192) != 0;
}

int f06089B90(void)
{
    if (LD16(LD32(MOVER_PTR) + 66))
        return 1;
    if (!GCALL0(0x0606C584))
        return 0;
    return !GCALL1(0x0600A0EC, 3);
}

int f06089FDA(void)
{
    int s = GCALL1(0x0606CEB0, (LDU16(0x060C2EF2) + 128) & 255);
    int one = GCALL1(0x060980DC, 1);
    gaddr mover = LD32(MOVER_PTR);
    int v = DIVS((s + one) * 240, 0x00020000) + 0x100;

    ST16(mover + 70, v);
    ST16(mover + 68, v);
    if (LDU16(0x060C2EF2) < 128) {
        ST16(0x060C2EF2, LD16(0x060C2EF2) + 1);
    } else {
        ST16(0x060C2EE6, 1);
        mover = LD32(MOVER_PTR);
        ST16(mover + 70, 0x1F0);
        ST16(mover + 68, 0x1F0);
    }
    return 0;
}

int f0608A718(void)
{
    return GJUMP2(0x06069462, LD16(OBJIDX), LD16(LD32(MOVER_PTR) + 4) + 28);
}

int f0608A72A(void)
{
    int open[8];
    int i, k, tries, x, y, left, top, angle;

    i = 0;
    while (i < 8) {
        POLL();
        open[i] = 1;
        i++;
    }
    x = LD16(LD32(MOVER_PTR) + 16);
    if (x >= 160) {
        open[7] = 0;
        open[0] = 0;
        open[1] = 0;
    } else {
        open[3] = 0;
        open[4] = 0;
        open[5] = 0;
    }
    x = LD16(LD32(MOVER_PTR) + 16);
    if (x < 16 || x >= 0x130) {
        open[2] = 0;
        open[6] = 0;
    }
    y = LD16(LD32(MOVER_PTR) + 18);
    if (y >= 112) {
        open[1] = 0;
        open[2] = 0;
        open[3] = 0;
    } else {
        open[5] = 0;
        open[6] = 0;
        open[7] = 0;
    }
    y = LD16(LD32(MOVER_PTR) + 18);
    if (y < 32 || y >= 208) {
        open[0] = 0;
        open[4] = 0;
    }
    k = GCALL0(0x0600A0B8) & 7;
    tries = 0;
    do {
        if (open[k] != 0)
            break;
        k = (k + 1) & 7;
    } while (AGAIN(++tries < 8));
    angle = k * 32;
    ST16(LD32(CURRENT) + 86, angle);
    angle &= 0xFFFF;
    if (((angle + 64) & 128) == 0)
        left = 0x160 - LD16(LD32(MOVER_PTR) + 16);
    else
        left = LD16(LD32(MOVER_PTR) + 16) + 32;
    if (left < 0)
        left = 0;
    if ((angle & 128) == 0)
        top = 0x110 - LD16(LD32(MOVER_PTR) + 18);
    else
        top = LD16(LD32(MOVER_PTR) + 18) + 32;
    if (top < 0)
        top = 0;
    if (LDU16(LD32(CURRENT) + 86) & 32)
        return left < top ? left : top;
    return (LDU16(LD32(CURRENT) + 86) & 64) ? top : left;
}

int f0608A8B2(void)
{
    if (LDU16(0x060C1E3C) <= 2)
        GCALL1(0x06009A3A, 0x135);
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

void f0608A944(void)
{
    int index = GCALL2(0x0600C950, 5, 16);
    int row, col;
    gaddr walls, floor, dst;
    unsigned int cell;

    for (row = 13; row != 0; row--, index += 64) {
        POLL();
        walls = 0x060EC8B0 + index * 2;
        floor = 0x060EE8B0 + index * 2;
        dst = LD32(0x060C2F00) + index * 2;
        for (col = 19; col != 0; col--) {
            POLL();
            cell = LDU16(walls) & 0xB0;
            if ((LDU16(walls) & 7) == 7)
                cell |= 32;
            walls += 2;
            if (!cell)
                cell = (LDU16(floor) & 0xF00) >= 0xE00 ? 0x2000 : 0x8000;
            floor += 2;
            ST16(dst, cell);
            dst += 2;
        }
    }
}

int f0608A9D4(unsigned int id, int b)
{
    if (id == LDU16(0x060C2EFE))
        return 0;
    return GJUMP2(0x0608AA18, id, b);
}

int f0608AA18(unsigned int id, int dir, int unused, int arg)
{
    gaddr p;
    int state, skip, k;

    if (id >= 0x1000)
        return 0;
    p = LD32(0x060C2F00) + id * 2;
    state = LD16(p);
    if (state & 0x50B0)
        return 0;
    if (state & 0x8000)
        return 1;
    skip = LDU16(0x060B90B4 + dir * 2);
    for (k = 1; k < 5; k++) {
        POLL();
        if (k == skip)
            continue;
        ST16(p, LD16(p) | 0x1000);
        if (GCALL4(0x0608A9D4, LD16(0x060B90A0 + k * 2) + id, k, state, arg) != 0) {
            ST16(p, LD16(p) & 0xEFFF);
            ST16(p, LD16(p) | 0x8000);
            return 1;
        }
        ST16(p, LD16(p) & 0xEFFF);
    }
    ST16(p, LD16(p) | 0x4000);
    return 0;
}

void f0608AAD8(void)
{
    int i;

    i = 0;
    do {
        ST8(0x060C2F04 + i * 88, 0);
    } while (AGAIN(++i < 8));
}

int f0608AAEE(gaddr data)
{
    unsigned int i, n;
    gaddr rec;

    for (i = 0; i < 8; i++) {
        POLL();
        rec = 0x060C2F04 + (short)(i * 88);
        if (LD8(rec) != 0)
            continue;
        ST16(LD32(CURRENT) + 88, i);
        ST32(0x060C31C4, rec);
        ST8(rec, 1);
        n = 0;
        while (LD16(data) > 0 && n < 16) {
            POLL();
            ST8(rec + 3 + n, LD16(data));
            ST16(rec + 20 + n * 2, LD16(data + 2));
            ST16(rec + 52 + n * 2, LD16(data + 4));
            data += 6;
            n++;
        }
        ST8(rec + 1, n);
        ST8(rec + 2, 0);
        ST8(rec + 19, 0);
        return n;
    }
    return 8;
}

void f0608AB88(unsigned int n)
{
    if (n < 8)
        ST8(0x060C2F04 + n * 88, 0);
}

void f0608AD00(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 28);
    ST16(0x060DF982, 153);
    ST16(0x060DF984, 151);
    ST16(0x060C1E44, 0);
    GCALL2(0x0609BBC0, 0x400, 1);
    ST8(0x060C1910, 2);
}

int f0608AD36(void)
{
    int base = LDU16(0x060BB4A4 + (LDU16(0x060C31F0) << 3));

    return 16 * GCALL1(0x0600A0EC, 13) + base;
}

int f0608AD5C(void)
{
    int base = LDU16(0x060BB4A6 + (LDU16(0x060C31F0) << 3));

    return 16 * GCALL1(0x0600A0EC, 5) + base;
}

void f0608AD82(void)
{
    GCALL1(0x0608ADDE, LDU16(0x060C31C8));
    if (LD16(OBJ(LDU16(0x060C31CA)) + 66)) {
        GCALL1(0x0608ADDE, LDU16(0x060C31CC));
        GCALL1(0x0608ADDE, LDU16(0x060C31CE));
    }
    GCALL1(0x0608ADDE, LDU16(0x060C31D0));
    GCALL1(0x0608ADDE, LDU16(0x060C31D2));
    GCALL1(0x0608ADDE, LDU16(0x060C31D4));
    GCALL1(0x0608AE64, LDU16(0x060C31DC));
    GJUMP1(0x0608AE64, LDU16(0x060C31DE));
}

void f0608ADDE(int n)
{
    if (n)
        GJUMP1(0x0608AE64, LDU16((OBJECTS + 0x30) + n * 124 + 22));
}

void f0608AE64(int id)
{
    if (id)
        ST16(OBJ(id) + 66, LD16(OBJ(LDU16(0x060C31CA)) + 66));
}

void f0608AE8C(int delta)
{
    GCALL2(0x0608AEE6, LDU16(0x060C31C8), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31CC), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31CE), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31D0), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31D2), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31D4), delta);
    GCALL2(0x0608AF28, LDU16(0x060C31DC), delta);
    GJUMP2(0x0608AF28, LDU16(0x060C31DE), delta);
}

void f0608AEE6(int n, int delta)
{
    gaddr rec, obj;

    if (!n)
        return;
    rec = REC(n);
    ST16(rec + 28, LD16(rec + 28) + delta);
    obj = OBJ(LDU16(rec + 22));
    ST16(obj + 18, LD16(obj + 18) + delta);
    ST16(rec + 20, GCALL2(0x0600CAE4, LD16(rec + 24), LD16(rec + 28)));
}

void f0608AF28(int n, int d)
{
    REF(Obj84) o;

    if (n) {
        o = (REF(Obj84))OBJ(n);
        SET(Obj84, o, w18, GET(Obj84, o, w18) + d);
    }
}

void f0608AF42(int who)
{
    gaddr rec;

    GCALL2(0x0608AEE6, LDU16(0x060C31D0), 16);
    GCALL2(0x0608AEE6, LDU16(0x060C31D2), 16);
    GCALL2(0x0608AEE6, LDU16(0x060C31D4), 16);
    GCALL2(0x0608AF28, LDU16(0x060C31DC), 16);
    GCALL2(0x0608AF28, LDU16(0x060C31DE), 16);
    rec = REC(LDU16(0x060C31CC + (who << 1)));
    ST8(rec + 4, LD8(rec + 4) | 64);
}

void f0608B552(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr row = 0x060BB5E0 + (LDU16(0x060C31EE) << 3);

    ST16(cur + 60, LDU16(row + ((GCALL0(0x0600A0B8) & 3) << 1)));
}

int f0608B80C(void)
{
    ST16(0x060C31E2, 1);
    ST16(0x060C31E4, 0);
    GCALL0(0x0602EE02);
    return GJUMP1(0x060144F4, 0x0608B858);
}

void f0608B904(void)
{
}

void f0608BE1C(void)
{
    GJUMP0(0x0608BE24);
}

void f0608CE94(int n)
{
    gaddr rec = 0x060C320C + (signed char)(n * 20);

    ST16(rec + 16, LDU16(LD32(CURRENT) + 80) + 9 + n);
    ST16(rec + 18, LDU16(LD32(CURRENT) + 80) + 11 + n);
}

void f0608D17C(void)
{
    int who;

    GCALL0(0x0608D1CA);
    who = LDU16(0x060C31F8);
    if (who) {
        gaddr src = OBJ(LDU16(0x060D5F46 + LDU16(0x060C31D0) * 124));

        ST16(OBJ(who) + 18, LD16(src + 18) - (LD16(0x060C3202) << 4));
    }
}

void f0608D1CA(void)
{
    ST16(0x060C3202, LD16(0x060C31F0) == LD16(0x060C31EE));
}

void f0608D74C(int n)
{
    int back = LDU16(LD32(CURRENT) + 66) != 0;
    int dir = back ? -1 : 1;
    gaddr p = 0x060BB636 + (signed char)(n * 3);
    gaddr rec = 0x060C320C + (signed char)(LDU16(LD32(CURRENT) + 66) * 20);

    ST16(LD32(CURRENT) + 72, 0x100);
    ST16(LD32(CURRENT) + 70, (LD8(p) & 255) * dir);
    ST16(rec + 8, (LD8(p + 1) & 255) * dir);
    ST16(rec + 10, (LD8(p + 2) & 255) * dir);
}

int f0608E408(void)
{
    gaddr cur;

    GCALL1(0x0600996A, 211);
    cur = LD32(CURRENT);
    if (LD16(cur + 68)) {
        GCALL1(0x060692DC, LDU16(cur + 68));
        ST16(LD32(CURRENT) + 68, 0);
    }
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

int f0608EA2E(void)
{
    ST16(LD32(MOVER_PTR) + 66, LD16(OBJ(LDU16(0x060C31CA)) + 66));
    ST16(LD32(CURRENT) + 28, LD16(REC(LDU16(0x060C31D0)) + 28) - 48);
    return 0;
}

int f0608F054(void)
{
    gaddr cur, cell;

    if (LD16(0x060C31E6)) {
        GCALL0(0x0608F23E);
        return 1;
    }
    GCALL0(0x0606E81C);
    cur = LD32(CURRENT);
    cell = 0x060C1F42 + LDU16(cur + 64) * 12;
    if (LD16(cur + 62) && LDU16(cell + 4) + LDU16(cell + 6) > 15)
        return 0;
    GCALL1(0x06014516, LD16(cur + 68) ? 0x0608F126 : 0x0608F0C4);
    return 1;
}

int f0608F1A6(void)
{
    gaddr cur;

    if (LD16(0x060C31E6) || !LD16(LD32(CURRENT) + 70)) {
        GCALL0(0x0608F23E);
        return 1;
    }
    cur = LD32(CURRENT);
    if (!(LDU16(cur + 70) & 1)) {
        ST16(cur + 70, LD16(cur + 70) - 1);
        return 0;
    }
    GCALL1(0x06014516, 0x0608F30C);
    cur = LD32(CURRENT);
    ST16(cur + 70, LD16(cur + 70) - 1);
    return 1;
}

int f0608F200(void)
{
    gaddr cur;

    if (LD16(0x060C31E6)) {
        GCALL0(0x0608F23E);
        return 1;
    }
    cur = LD32(CURRENT);
    if (LD16(cur + 70)) {
        ST16(cur + 70, LD16(cur + 70) - 1);
        return 0;
    }
    GCALL1(0x06014516, 0x0608F126);
    return 1;
}

void f0608F23E(void)
{
    ST8(LD32(CURRENT) + 4, LD8(LD32(CURRENT) + 4) | 64);
    ST16(REC(LDU16(LD32(CURRENT) + 66)) + 72, 1);
    GJUMP1(0x06009A3A, 207);
}

int f0608F83C(void)
{
    gaddr mover = LD32(MOVER_PTR);
    int x = LD16(mover + 16);
    int v;
    int h;

    if (x < -64 || x > 0x180 || LD16(mover + 18) + LD16(mover + 38) > 0x120) {
        GCALL1(0x060144F4, 0x0606D23C);
        return 1;
    }
    v = GCALL1(0x0606CE8C, LDU16(LD32(CURRENT) + 68));
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) + LD16(0x060BB6AC + LDU16(LD32(CURRENT) + 66) * 8));
    v = GCALL1(0x060949D0, v);
    ST16(LD32(MOVER_PTR) + 38, -(short)((unsigned int)(v * LD16(0x060BB6AA + LDU16(LD32(CURRENT) + 66) * 8)) >> 16));
    h = 0x100 - (LD16(LD32(MOVER_PTR) + 38) << 2);
    ST16(LD32(MOVER_PTR) + 70, h);
    ST16(LD32(MOVER_PTR) + 68, h);
    ST8(LD32(MOVER_PTR) + 78, -(LD8(LD32(CURRENT) + 69) << 2));
    return 0;
}

void f0608F924(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 12);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFF3);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFCF);
}
