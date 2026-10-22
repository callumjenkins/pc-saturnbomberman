#include "krnl.h"

void f06070024(void)
{
    GJUMP0(0x0607005C);
}

void f0607123A(int n)
{
    GJUMP1(0x0601628E, n);
}

void f0607193C(void)
{
    FRAME(sp, 20);
    gaddr table = sp - 20;
    gaddr obj, rec;

    COPYB(table, 0x060B298C, 10);
    obj = LD32(CURRENT);
    ST16(obj + 48, LD16(table + (LDU8(obj + 6) << 1)));
    rec = REC(LDU16(LD32(CURRENT) + 68));
    ST16(rec + 66, 0);
    while (LD16(rec + 68) != 0) {
        POLL();
        rec = REC(LDU16(rec + 68));
    }
    if (LDU16(rec + 40) != 1)
        ST16(rec + 72, 1);
    GCALL1(0x060144F4, 0x0606D2C8);
}

void f06071AEE(void)
{
    FRAME(sp, 24);
    gaddr cur;

    COPYW(0x06094450, sp - 24, 0x060B2998, 16);
    cur = LD32(CURRENT);
    ST16(cur + 62, LD32(sp - 24 + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

void f060723D8(void)
{
    FRAME(sp, 24);
    gaddr cur;

    COPYW(0x06094450, sp - 24, 0x060B29BC, 16);
    cur = LD32(CURRENT);
    ST16(cur + 62, LD32(sp - 24 + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

int f060733DE(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr p = 0x060B90A2;

    if (!(LDU16(cur + 42) & 0x2000))
        return 0;
    do {
        if (!(LDU16(FLAGS_AT(LDU16(cur + 20) + LD16(p))) & (LDU16(cur + 18) | 16)))
            return 1;
        p += 2;
    } while (AGAIN(p < 0x060B90AA));
    return 0;
}

void f06073432(void)
{
    gaddr cur;

    GCALL1(0x060144F4, 0x0607399A);
    cur = LD32(CURRENT);
    ST16(cur + 42, LDU16(cur + 42) & 0xDFFF);
    cur = LD32(CURRENT);
    ST16(cur + 70, 4);
    cur = LD32(CURRENT);
    ST16(cur + 68, LD16(cur + 70) + 0x100);
}

void f06073968(void)
{
    gaddr cur;

    GCALL1(0x060144F4, 0x0607399A);
    cur = LD32(CURRENT);
    ST16(cur + 42, LDU16(cur + 42) & 0xDFFF);
    cur = LD32(CURRENT);
    ST16(cur + 70, 4);
    cur = LD32(CURRENT);
    ST16(cur + 68, LD16(cur + 70) + 0x100);
}

void f06073AC0(void)
{
    gaddr cur;

    GCALL2(0x0606AAC8, LD32(MOVER_PTR), 0);
    ST16(LD32(CURRENT) + 80, 80);
    ST16(LD32(CURRENT) + 50, 6);
    ST16(LD32(CURRENT) + 48, 6);
    GJUMP1(0x060144F4, 0x0606D2C8);
}

int f06073B32(void)
{
    if (LD16(LD32(CURRENT) + 66)) {
        GCALL1(0x06014820, LD16(0x060C062C));
        GCALL1(0x060144F4, 0x06073B72);
        ST32(0x060E2154 + (short)(LD16(0x060C062C) * 20), 0x0606B1EC);
        ST16(LD32(CURRENT) + 18, 0);
    }
    return 0;
}

void f06073F74(void)
{
    FRAME(sp, 24);
    gaddr cur;

    COPYW(0x06094450, sp - 24, 0x060B29D4, 16);
    cur = LD32(CURRENT);
    ST16(cur + 62, LD32(sp - 24 + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

void f060743A6(void)
{
    POLL();
    GJUMP0(0x06073968);
}

void f060743AA(void)
{
    FRAME(sp, 24);
    gaddr cur;

    COPYW(0x06094450, sp - 24, 0x060B2A94, 16);
    cur = LD32(CURRENT);
    ST16(cur + 62, LD32(sp - 24 + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

void f06074754(void)
{
    int i = 0;

    do {
        ST16(0x060C1F78 + i * 220, 0);
    } while (AGAIN(++i < 8));
}

int f06074770(void)
{
    int i = 0;

    while (i < 8) {
        gaddr rec = 0x060C1F78 + i * 220;

        POLL();
        if (LD16(rec) == 0) {
            ST16(rec, 1);
            ST16(rec + 212, 0);
            return i;
        }
        i++;
    }
    return 8;
}

void f060747A6(unsigned int n)
{
    if (n < 8)
        ST16(0x060C1F78 + n * 220, 0);
}

void f060749D8(void)
{
    unsigned int total = 0;
    unsigned int i;

    if (LD32(LD32(PATH_PTR) + 76)) {
        for (i = 1; i < (unsigned int)LD32(LD32(PATH_PTR) + 76); i++) {
            POLL();
            total += GCALL1(0x06074A22, i);
        }
        total = DIVU(total, LD32(LD32(PATH_PTR) + 76));
    }
    ST32(LD32(PATH_PTR) + 216, total);
}

int f06074A22(int i)
{
    int dx = GCALL1(0x060949D0, LD32(LD32(PATH_PTR) + 80 + i * 8) - LD32(LD32(PATH_PTR) + 80 + (i - 1) * 8));
    int dy = GCALL1(0x060949D0, LD32(LD32(PATH_PTR) + 80 + i * 8 + 4) - LD32(LD32(PATH_PTR) + 80 + (i - 1) * 8 + 4));

    return GJUMP2(0x0609732A, dx, dy);
}

void f06074A7C(void)
{
    unsigned int i = 1;
    unsigned int j;

    while (i < (unsigned int)LD32(LD32(PATH_PTR) + 8)) {
        POLL();
        if (LD32(PATH_ENTRY(i - 1)) == LD32(PATH_ENTRY(i)) && LD32(PATH_ENTRY(i - 1) + 4) == LD32(PATH_ENTRY(i) + 4)) {
            j = i;
            while (j < (unsigned int)LD32(LD32(PATH_PTR) + 8)) {
                POLL();
                ST32(PATH_ENTRY(j - 1), LD32(PATH_ENTRY(j)));
                ST32(PATH_ENTRY(j - 1) + 4, LD32(PATH_ENTRY(j) + 4));
                j++;
            }
            i--;
            ST32(LD32(PATH_PTR) + 8, LD32(LD32(PATH_PTR) + 8) - 1);
        }
        i++;
    }
}

void f06074AFA(int x, int y)
{
    gaddr cur = LD32(0x060D7768);

    GJUMP2(0x06074B2C, x - LDU16(cur + 24), y - LDU16(cur + 28));
}

void f06074B2C(int x, int y)
{
    int speed;

    GCALL2(0x06074BB6, x, y);
    speed = (LDU16(LD32(0x060D7768) + 12) << 16) + LDU16(LD32(0x060D7768) + 10);
    ST16(LD32(0x060D7768) + 82,
         HELPER(GCALL2(0x060980B4, speed, GCALL1(0x0606CEB0, LDU16(LD32(0x060D7768) + 86))) >> 8));
    ST16(LD32(0x060D7768) + 84,
         HELPER(GCALL2(0x060980B4, speed, GCALL1(0x0606CE8C, LDU16(LD32(0x060D7768) + 86))) >> 8));
}

void f06074B48(short dir, short speed)
{
    gaddr cur = LD32(CURRENT);
    int v, s;

    ST16(cur + 54, speed);
    ST16(cur + 86, dir);
    v = (LDU16(cur + 12) << 16) + LDU16(cur + 10);
    s = GCALL2(0x060980B4, v, GCALL1(0x0606CEB0, LDU16(cur + 86)));
    ST16(cur + 82, HELPER(s >> 8));
    s = GCALL2(0x060980B4, v, GCALL1(0x0606CE8C, LDU16(cur + 86)));
    ST16(cur + 84, HELPER(s >> 8));
}

void f06074BB6(int x, int y)
{
    int ax = GCALL1(0x060949D0, x);
    int ay = GCALL1(0x060949D0, y);
    int big = (unsigned int)ax >= (unsigned int)ay ? ax : ay;
    int nx, ny;

    ST16(LD32(CURRENT) + 54, big);
    nx = -DIVS(GCALL1(0x060980DC, x), big);
    ny = DIVS(GCALL1(0x060980DC, y), big);
    ST16(LD32(CURRENT) + 86, GCALL2(0x0606CED4, -ny, nx));
}

int f06074C34(int dir, int scale)
{
    int s = ((dir + 32) & 64) ? GCALL1(0x0606CE8C, dir) : GCALL1(0x0606CEB0, dir);

    return GCALL1(0x060949D0, GCALL1(0x060980E4, 0x8000 + GCALL2(0x060980B4, GCALL1(0x060980DC, scale), s)));
}

void f06074E14(void)
{
    ST16(LD32(CURRENT) + 62, 0x4B0);
}

void f06075710(void)
{
    GJUMP0(0x0607571E);
}

void f06075C58(void)
{
    int p = 0x060C277E;

    do {
        ST16(p, 0);
    } while (AGAIN((p += 32) < 0x060C27BE));
}

int f06075C6E(void)
{
    int i = 0;

    while (i < 2) {
        gaddr rec = 0x060C277E + i * 32;

        POLL();
        if (LD16(rec) == 0) {
            int k = 0;

            ST16(rec, 1);
            do {
                ST16(rec + 8 + k, 0);
                ST16(rec + 14 + k, 0);
                ST16(rec + 20 + k, GCALL0(0x0600A0B8) & 7);
                k += 2;
            } while (AGAIN(k < 6));
            return i;
        }
        i++;
    }
    return 2;
}

int f0607612C(void)
{
    int fresh = 0, any = 0;
    int i = 0;

    do {
        int bit = 1 << i;
        gaddr p = 0x060BA7AA + (signed char)(i * 6);
        int j = 0;

        do {
            if (LDU16(FLAGS_AT(LD16(p) + LDU16(LD32(CURRENT) + 20))) & 7) {
                any = i + 1;
                if (!(LDU16(LD32(CURRENT) + 66) & bit))
                    fresh = i + 1;
                ST16(LD32(CURRENT) + 66, LD16(LD32(CURRENT) + 66) | bit);
                break;
            }
            p += 2;
        } while (AGAIN(++j < 3));
    } while (AGAIN(++i < 4));
    return fresh != 0 ? fresh : any;
}

void f06076658(void)
{
    int i = 0;

    do {
        if (LDU16(0x060EC8B0 + (LDU16(LD32(CURRENT) + 20) + i - 1) * 2) & 7) {
            gaddr p = LD32(0x060C27C0) + 26 + i * 2;
            gaddr cur;

            ST16(p, LDU16(p) | 1);
            cur = LD32(CURRENT);
            ST16(cur + 66, LDU16(cur + 66) | (1 << i));
        }
    } while (AGAIN(++i < 3));
}

unsigned char f06076854(int a, int b)
{
    return LD8(0x060BA7D2 + ((LDU16(LD32(CURRENT) + 72) * 3 + a) << 3) + b);
}

int f06076AD4(void)
{
    gaddr cur = LD32(CURRENT);

    if (LDU16(cur + 72)) {
        GCALL1(0x060692DC, LDU16(cur + 72));
        ST16(LD32(CURRENT) + 72, 0);
    }
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

int f06076BBC(void)
{
    int s = GCALL1(0x0606CE8C, LD32(0x26006034) & 255);

    ST16(LD32(MOVER_PTR) + 38, HELPER((s - 4) >> 14));
    return 0;
}

void f06077024(void)
{
    GCALL1(0x06009A3A, 190);
    GCALL1(0x0606CC12, LD32(CURRENT) + 68);
    GCALL1(0x0606CC12, LD32(CURRENT) + 70);
    GJUMP1(0x060144F4, 0x0606D2C8);
}

int f060770A4(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    return GJUMP1(0x0609D730, 28);
}

void f0607745C(void)
{
    gaddr zone = 0x060C1F38;

    GCALL0(0x0606DA88);
    if (LD16(0x060C27CE) != 4)
        return;
    if (LDU16(LD32(CURRENT) + 24) <= 208)
        ST16(zone + 6, 1);
    if (LDU16(LD32(CURRENT) + 24) >= 0x170)
        ST16(zone + 2, 1);
    if (LDU16(LD32(CURRENT) + 28) >= 0x200)
        ST16(zone + 4, 1);
}

int f0607766C(void)
{
    gaddr p;
    int count = 0;

    if (LDU16(0x060C27EE)) {
        ST16(0x060C27EE, LDU16(0x060C27EE) - 1);
        return 0;
    }
    ST16(0x060C27CC, 0xFFF);
    p = 0x060BA8B0;
    do {
        gaddr cur = LD32(CURRENT);
        unsigned short cell = LDU16(cur + 20);

        ST16(cur + 20, cell + LDU16(0x060B90AA + LDU16(p) * 2));
        ST16(cur + 20, LDU16(cur + 20) + LD16(0x060B90A8));
        if (GCALL0(0x0606C5D6)) {
            int y, target;

            ST16(LD32(CURRENT) + 20, cell);
            GCALL1(0x0600C9AA, LD16(0x060C1F34));
            y = LDU16(0x060D7EB6);
            if (y >= 27) {
                count++;
                target = y - ((LDU16(LD32(CURRENT) + 28) + 48) >> 4);
                if (GCALL1(0x060949D0, LD16(0x060C27CC)) > GCALL1(0x060949D0, target))
                    ST16(0x060C27CC, target);
            }
        } else {
            ST16(LD32(CURRENT) + 20, cell);
        }
        p += 2;
    } while (AGAIN(p < 0x060BA8B4));
    return count;
}

void f06077870(void)
{
    ST16(0x060C27D2, LD16(0x060C27D0));
    GCALL1(0x060144F4, 0x060778FC);
    GCALL1(0x06014516, 0x0606D88C);
    GJUMP0(0x060778A0);
}

int f06077A8C(void)
{
    return GCALL0(0x060780A4) ? 0 : GCALL0(0x0606C5D6);
}

int f06077BFA(void)
{
    return GCALL0(0x0606BF8C);
}

int f06077C08(void)
{
    if ((unsigned char)LD8(LD32(CURRENT) + 7) < 2)
        return 0;
    return GCALL0(0x0606BE44) != 0;
}

void f06077F9A(void)
{
    int i = 0;

    do {
        ST16(0x060C27DC + i * 2, 0);
    } while (AGAIN(++i < 6));
}

int f060780A4(void)
{
    int bits = 0;
    int p = 0x060C27DC;

    do {
        bits |= LDU16(p);
    } while (AGAIN((p += 2) < 0x060C27E8));
    return bits;
}

int f06078244(void)
{
    ST16(0x060C27DC + LDU16(LD32(CURRENT) + 66) * 2, 0);
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

void f0607884E(void)
{
    gaddr mover = LD32(MOVER_PTR);
    unsigned int dist = LDU16(mover + 50) - LDU16(LD32(CURRENT) + 80);
    int col = LDU16(mover + 10) - LDU16(0x060C27E8);

    if (dist >= 9 && dist < 20) {
        gaddr p = 0x060BA9BC + col * 2;

        ST16(0x060C27EA, LD8(p) & 255);
        ST16(0x060C27EC, LD8(p + 1) & 255);
    } else {
        ST16(0x060C27EC, 0);
        ST16(0x060C27EA, 0);
    }
}

int f06078D38(void)
{
    gaddr mover = LD32(MOVER_PTR);
    gaddr cur = LD32(CURRENT);
    int s = GCALL1(0x0606CE8C, LDU16(cur + 68) & 255);
    gaddr obj;

    ST16(mover + 38, -GCALL1(0x060949D0, HELPER(s >> 11)));
    cur = LD32(CURRENT);
    ST16(cur + 68, LDU16(cur + 68) + 1);
    obj = OBJ(LDU16(LD32(CURRENT) + 70));
    ST16(obj + 16, LDU16(LD32(MOVER_PTR) + 16));
    obj = OBJ(LDU16(LD32(CURRENT) + 70));
    ST16(obj + 18, LDU16(LD32(MOVER_PTR) + 18));
    return 0;
}

void f06078DB0(void)
{
    ST16(0x060C1E48, 17);
}

void f06078DEC(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f060796CE(void)
{
    return LD16(0x060C27FA) <= 4 && GCALL1(0x0606C390, 3) != 0;
}

int f0607992E(void)
{
    return LD16(0x060C27FE) == 0 && GCALL1(0x0606C114, 7) != 0;
}

int f06079A8A(void)
{
    if (LDU16(0x060C2810)) {
        ST16(0x060C2810, LDU16(0x060C2810) - 1);
        return 0;
    }
    return !GCALL1(0x0606C114, 4);
}

int f06079D30(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr p;
    int count = 0;

    if (LD16(cur + 60) != 0 || (LD8(cur + 7) & 255) < 2)
        return 0;
    if (IN_BOX(LDU16(cur + 24), LDU16(cur + 28))) {
        for (p = 0x060D5F30; p < 0x060D6028; p += 124) {
            if (!(LD8(p + 4) & 192) && IN_BOX(LDU16(p + 24), LDU16(p + 28)))
                count++;
            POLL();
        }
    }
    return count;
}

void f0607A420(void)
{
    GJUMP0(0x0607A42A);
}

int f0607A438(void)
{
    return LD16(0x060C27FC) == 0 && GCALL2(0x0606C006, 80, 80) != 0;
}

void f0607A5EA(void)
{
    ST16(0x060C27FC, LD16(0x060C27FC) + 4);
    GJUMP0(0x0607A5F8);
}

void f0607A60A(void)
{
    int p = 0x060C2820;

    do {
        ST32(p + 16, 0);
    } while (AGAIN((p += 20) < 0x060C285C));
}

void f0607A620(void)
{
    gaddr p = 0x060C2820;

    do {
        if (LD32(p + 16)) {
            GCALL1(0x060692DC, LD32(p + 16));
            ST32(p + 16, 0);
        }
        p += 20;
    } while (AGAIN(p < 0x060C285C));
}

void f0607A990(void)
{
    FRAME(sp, 88);
    gaddr table = sp - 88;
    gaddr entry;
    int scale;
    int dx, dy;

    COPYW(0x060944F4, table, 0x060B2B3C, 80);
    scale = LD16(0x060C2808);
    entry = table + (LDU8(LD32(CURRENT) + 6) << 4);
    dx = LD32(entry) * scale;
    dy = LD32(entry + 4) * scale;
    ST32(0x060C2834, LD32(0x060C2834) + dx);
    ST32(0x060C2838, LD32(0x060C2838) + dy);
    ST32(0x060C2848, LD32(0x060C2848) + dx * 2);
    ST32(0x060C284C, LD32(0x060C284C) + dy * 2);
}

void f0607ADAE(void)
{
    int n = LDU16(0x060C27F0);

    ST16(LD32(CURRENT) + 24, LDU16(REC(n) + 24));
    ST16(LD32(CURRENT) + 28, LDU16(REC(n) + 28));
}

int f0607B134(void)
{
    gaddr mover = LD32(MOVER_PTR);

    if (LDU16(mover + 68) < 0x100) {
        ST16(mover + 68, LD16(mover + 68) + 1);
        mover = LD32(MOVER_PTR);
        ST16(mover + 70, LD16(mover + 70) + 1);
    }
    return 0;
}

void f0607B3A0(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 28);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFF3);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFCF);
    ST16(0x060DF982, 153);
    ST16(0x060DF984, 151);
    ST16(0x060C1E44, 0);
}

void f0607B3E8(void)
{
    ST16(LD32(CURRENT) + 24, LDU16(0x060BAE48 + (LDU16(0x060C2870) << 2) + (LDU16(0x060C2872) << 1)));
    ST16(LD32(CURRENT) + 28, LDU16(0x060BAE60 + (LDU16(0x060C2872) << 1)));
}

void f0607B414(int n)
{
    gaddr obj;
    int v;

    GCALL1(0x0606948A, n);
    obj = OBJ(n);
    v = LD16(obj + 4) - 48;
    ST16(obj + 4, v > 20 ? v : 20);
}

void f0607B44C(void)
{
    int v = GCALL1(0x0605C9BC, (LDU16(LD32(CURRENT) + 28) + 8) >> 4);
    gaddr cur = LD32(CURRENT);

    v = (LDU16(cur + 24) << 16) + LDU16(cur + 26) - v;
    ST16(LD32(CURRENT) + 24, (unsigned int)v >> 16);
    ST16(LD32(CURRENT) + 26, v);
}

void f0607B88C(void)
{
    gaddr p = LD32(CURRENT) + 60;

    ST16(p, (GCALL0(0x0600A0B8) & 1) ? 0x258 : 0x708);
}

void f0607B9D8(void)
{
    int row = LDU16(0x060C2872) << 1;
    int x = LDU16(0x060BAE60 + row);
    int y = LDU16(0x060BAE48 + (LDU16(0x060C2870) << 2) + row);

    GCALL2(0x06074AFA, y, x);
    GJUMP1(0x06014516, 0x06074CB4);
}

void f0607BC86(void)
{
    GJUMP0(0x0607BC8E);
}

void f0607BCB6(void)
{
    GJUMP0(0x0607BCBE);
}

void f0607BD28(void)
{
    gaddr p = 0x060BAEBA;

    do {
        int cell = GCALL2(0x0600CAE4, LDU16(p), LDU16(p + 2));

        ST16(FLAGS_AT(cell), LDU16(FLAGS_AT(cell)) & 0xFF7F);
        p += 4;
    } while (AGAIN(p < 0x060BAECE));
}

void f0607C1A0(void)
{
    int id = LDU16(0x060C2888);

    if (id) {
        GCALL1(0x060692DC, id);
        ST16(0x060C2888, 0);
    }
}

int f0607CCBC(gaddr list)
{
    gaddr rec = REC(LDU16(0x060C2860));
    int key = LDU16(OBJ(LDU16(rec + 22)) + 50) - LDU16(rec + 80);

    while (LD16(list) != -1) {
        POLL();
        if (LD16(list) == key)
            return 1;
        list += 2;
    }
    return 0;
}

void f0607D2A4(void)
{
    int d = GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 28) - LDU16(LD32(CURRENT) + 68));

    ST16(LD32(MOVER_PTR) + 68, 0x100 + d);
    ST16(LD32(MOVER_PTR) + 70, d + 64);
}

int f0607DA5A(void)
{
    ST16(0x060C2878, 0);
    ST16(0x060C287A, 0);
    return 0;
}

int f0607DD98(void)
{
    gaddr cur = LD32(CURRENT);
    int d = GCALL1(0x060949D0, LDU16(cur + 28) - LDU16(LD32(CURRENT) + 70));
    int s = 0x100 - d * 3;
    gaddr mover = LD32(MOVER_PTR);
    int v;

    ST16(mover + 70, s);
    ST16(mover + 68, s);
    v = DIVS(LDU16(LD32(CURRENT) + 28) << 7, LDU16(LD32(CURRENT) + 70) - 64);
    v = GCALL1(0x0606CE8C, v);
    ST16(LD32(MOVER_PTR) + 38, HELPER(v >> 11));
    if (LD16(LD32(CURRENT) + 66)) {
        gaddr obj = OBJ(LDU16(LD32(CURRENT) + 66));

        ST16(obj + 70, s);
        ST16(obj + 68, s);
        ST16(obj + 16, LD16(LD32(MOVER_PTR) + 16));
        ST16(obj + 18, LD16(LD32(MOVER_PTR) + 18));
        ST16(obj + 38, GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 28) - 64));
    }
    if (!LD16(LD32(CURRENT) + 72))
        return 0;
    if (!GCALL0(0x0607DFB2))
        return 0;
    ST16(LD32(CURRENT) + 72, 0);
    GCALL1(0x060144F4, 0x0606D23C);
    return 1;
}

int f0607DF5A(void)
{
    gaddr cur = LD32(CURRENT);
    int v = LDU16(cur + 42);

    if (v & 128)
        return v;
    v = LDU16(cur + 28);
    if (v >= 112)
        return v;
    GCALL1(0x0607B414, LDU16(0x060C1AA8));
    cur = LD32(CURRENT);
    v = LD16(cur + 66);
    if (v) {
        gaddr mover = LD32(MOVER_PTR);

        v = LD16(mover + 4) + LD16(OBJ(LDU16(cur + 66)) + 38);
        ST16(mover + 4, v);
    }
    return v;
}

int f0607DFB2(void)
{
    int n = LDU16(0x060C2860);
    gaddr rec, mine, theirs, mover;
    int half, dx, dy;

    if (!n)
        return 0;
    rec = REC(n);
    if ((LD8(rec + 4) & 192) || LD16(0x060C288E))
        return 0;
    mine = OBJ(LDU16(rec + 22));
    theirs = OBJ(LDU16(LD32(CURRENT) + 66));
    half = (LDU16(rec + 28) - 64 + 4) >> 3;
    mover = LD32(MOVER_PTR);
    dx = LD16(theirs + 16) - LD16(mine + 16);
    dy = LD16(mover + 4) - LD16(mine + 4);
    if (dx < -8 - half || dx > 7 + half || dy < -4 || dy > 3)
        return 0;
    ST16(0x060C2890, LD16(0x060C2890) + 1);
    ST16(0x060C2892, LD16(LD32(CURRENT) + 74));
    return 1;
}

void f0607E28C(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f0607EA10(void)
{
    if (!GCALL0(0x0606BF22))
        return 0;
    GCALL0(0x0606E81C);
    return GCALL0(0x0606BE44) == 0;
}

int f0607EBB4(void)
{
    GCALL1(0x060144F4, 0x0607EBD4);
    GCALL2(0x06074AFA, LDU16(LD32(CURRENT) + 24), 64);
    return GJUMP1(0x06014516, 0x06074CB4);
}

void f0607F3FC(void)
{
    int tries = 64;
    int dx, dy;

    ST16(0x060C28A0, LD16(LD32(CURRENT) + 24));
    ST16(0x060C28A2, LD16(LD32(CURRENT) + 28));
    if (LD16(LD32(CURRENT) + 66)) {
        while (tries-- != 0) {
            POLL();
            dx = GCALL1(0x0600A0EC, 5);
            dy = GCALL1(0x0600A0EC, 5);
            if (dx == 2 && dy == 2)
                continue;
            ST16(0x060C28A0, LD16(LD32(CURRENT) + 24) + (dx - 2) * 16);
            ST16(0x060C28A2, LD16(LD32(CURRENT) + 28) + (dy - 2) * 16);
            if (GCALL2(0x0607F5A8, LDU16(0x060C28A0), LDU16(0x060C28A2)))
                break;
        }
    }
    GJUMP1(0x0607F50A, 64);
}

int f0607F50A(int divisor)
{
    int dx, dy, angle;

    ST16(LD32(CURRENT) + 70, -(int)((unsigned)(divisor << 4) >> 1));
    ST16(LD32(CURRENT) + 74, 0);
    ST16(LD32(MOVER_PTR) + 38, 0);
    dx = GCALL1(0x060980DC, GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 24) - LDU16(0x060C28A0)));
    dy = GCALL1(0x060980DC, GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 28) - LDU16(0x060C28A2)));
    angle = DIVS(GCALL2(0x0609732A, dx, dy), divisor);
    ST16(LD32(CURRENT) + 12, (unsigned)angle >> 16);
    ST16(LD32(CURRENT) + 10, (((unsigned)angle >> 8) & 255) << 8);
    return GJUMP2(0x06074AFA, LDU16(0x060C28A0), LDU16(0x060C28A2));
}

int f0607F5A8(int x, unsigned int y)
{
    int cell;

    if (y > 176)
        return 0;
    cell = GCALL2(0x0600CAE4, x, y);
    return !(LDU16(FLAGS_AT(LD16(0x060B90A8) + cell)) & LDU16(FLAGS_AT(cell)) & (LDU16(LD32(CURRENT) + 18) & ~32));
}

int f0607F83C(void)
{
    gaddr mover = LD32(MOVER_PTR);
    gaddr cur = LD32(CURRENT);

    if (LD16(mover + 38) > 0) {
        ST16(cur + 74, 0);
    } else {
        int v = (LD16(mover + 38) << 16) + LDU16(cur + 74) + (LD16(cur + 70) << 8);

        ST16(LD32(MOVER_PTR) + 38, (unsigned int)v >> 16);
        ST16(LD32(CURRENT) + 74, v);
        cur = LD32(CURRENT);
        ST16(cur + 70, LD16(cur + 70) + 16);
    }
    ST8(LD32(MOVER_PTR) + 78, LDU16(LD32(CURRENT) + 70) >> 1);
    if (LD16(LD32(CURRENT) + 82) < 0) {
        mover = LD32(MOVER_PTR);
        ST8(mover + 78, -LD8(mover + 78));
    }
    return 0;
}

int f0607F9EA(void)
{
    gaddr cur = LD32(CURRENT);

    if (LDU16(cur + 36) == 74) {
        gaddr flags = FLAGS_AT(LDU16(cur + 20));

        ST16(flags, LDU16(flags) & 0xFF77);
    }
    ST16(0x060C289E, LD16(0x060C289E) - 1);
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

void f0607FED8(void)
{
    gaddr mover = LD32(MOVER_PTR);
    gaddr obj;

    if (!(GCALL1(0x060691DA, LD16(mover + 18)) & 0xFFFF))
        return;
    obj = OBJ(LDU16(0x060C1AAA));
    ST16(obj + 42, LDU16(obj + 42) | 16);
    mover = LD32(MOVER_PTR);
    ST16(obj + 44, LD16(mover + 44));
    ST16(obj + 46, LD16(mover + 46));
    GCALL1(0x0606AB72, obj);
    mover = LD32(MOVER_PTR);
    ST16(obj + 10, LD16(mover + 10));
    ST16(obj + 16, LD16(mover + 16));
    ST16(obj + 18, LD16(mover + 18) + LD16(mover + 38));
    ST16(obj + 38, -16 - ((LD32(0x26006034) & 1) << 4));
}
