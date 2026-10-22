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

int f06050F02(int mask)
{
    return SHL(mask & 7, LDU16(0x060B7BE8 + (LDU16(0x060FB89C) & 15) * 4));
}

int f06050F28(int mask)
{
    return SHL(mask & 7, LDU16(0x060B7BA8 + (LDU16(0x060FB89C) & 15) * 4));
}

int f06050F4E(void)
{
    int a = GCALL1(0x06050F28, 6);

    return GCALL1(0x06050F02, 3) | a;
}

void f0605112C(void)
{
    FRAME(sp, 56);
    gaddr pos = sp - 56;
    int shift = 0;
    int i = 0;
    gaddr obj;

    GCALL1(0x060512C0, pos);
    if ((LD32(0x060C1048) & 48) == 32 || LD8(0x060C1008) != 0)
        shift = SHL(8, LDU8(0x060C1008));
    do {
        if (LDU8(0x060C0640 + i) & 3) {
            obj = OBJ(LDU16(0x060DFE56 + i * 2));
            ST16(obj + 16, SHL(LD16(pos + i * 2) * 8 + 8, LDU8(0x060C1008)));
            ST16(obj + 18, SHL(20, LDU8(0x060C1008)));
            ST16(obj + 36, shift);
            ST16(obj + 38, 0);
            ST16(obj + 46, 96 + i * 16);
            if (LD8(0x060C1008) == 0)
                GCALL2(0x0606950C, obj, 6);
        }
        i++;
    } while (AGAIN(i < 10));
}

/* The fifth to seventh arguments are on the stack, each a halfword in the low half of its word. */
void f060516B0(short kind, unsigned short first, unsigned short second, short x)
{
    FRAME(sp, 0);
    gaddr a = OBJ(first);
    gaddr b = OBJ(second);
    int v;

    GCALL2(0x0606AAC8, a, 6);
    GCALL2(0x0606AAC8, b, 5);
    ST16(a + 42, LD16(a + 42) | 0x100);
    ST16(b + 42, LD16(b + 42) | 0x100);
    ST16(b + 10, 1);
    ST16(a + 10, 1);
    v = SHL(x * 8, LDU8(0x060C1008));
    ST16(b + 20, v);
    ST16(a + 20, v);
    v = SHL(LD16(sp + 6) * 8 + 8, LDU8(0x060C1008)) - 1;
    ST16(b + 24, v);
    ST16(a + 24, v);
    v = SHL(LD16(sp + 2) * 8 + 2, LDU8(0x060C1008));
    ST16(b + 22, v);
    ST16(a + 22, v);
    v = SHL(LD16(sp + 10) * 8 + 5, LDU8(0x060C1008)) - 1;
    ST16(b + 26, v);
    ST16(a + 26, v);
    if (LD8(0x060C1008) != 0) {
        ST16(a + 46, LDU8(0x060B6B64 + kind));
        ST16(b + 46, LDU8(0x060B6B69 + kind));
        ST16(a + 38, -2);
        ST16(b + 38, -2);
    } else {
        ST16(a + 46, LDU8(0x060B6B64 + kind) + 0x310);
        ST16(b + 46, LDU8(0x060B6B69 + kind) + 0x310);
        GCALL2(0x0606950C, a, 6);
        UNFRAME(sp);
        GJUMP2(0x0606950C, b, 6);
    }
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

void f06052A00(int hold)
{
    gaddr e;
    gaddr row;
    int index = hold;

    if (hold != 0) {
        ST16(0x060BF5EA, 0);
    } else {
        e = 0x060B6BC0 + LDU8(0x060C17DA);
        index = LDU8(e);
        ST16(0x060BF5EA, index);
        if (LDU16(0x060BF5EA) == 2) {
            ST8(0x060C029C, 8);
            ST8(0x060C029D, LD8(e + 1));
        } else {
            ST8(0x060C029C, LD8(e + 1));
            ST8(0x060C029D, 0);
        }
        ST8(0x060C17DA, LD8(0x060C17DA) + 2);
        ST8(0x060C17DA, MODS(LDU8(0x060C17DA), 48));
    }
    row = 0x060B6B98 + index * 8;
    ST32(0x060C1048, LDU16(row + 6));
    POLL();
    GJUMP2(0x0600AD62, LD32(row), LD16(row + 4));
}

int f06052BB6(unsigned char which)
{
    gaddr slot = 0x060EC748;
    gaddr key = 0x060C104C + which * 16;
    int result = 0;
    int i = 0;

    ST8(0x060C17F0, LD8(0x060C17F0) + 1);
    ST8(0x060C17F0, MODS(LD8(0x060C17F0) & 255, 41));
    if (LDU16(0x260060B0) & 0x3000)
        ST8(0x060C17F0, 0);
    do {
        result = GCALL2(0x06052DBA, slot, LD16(slot + 4) == LD32(key + 4));
        i++;
        slot += 24;
    } while (AGAIN(i < 15));
    return result;
}

void f06052DBA(gaddr obj, unsigned short flag)
{
    short ids[5];
    int level = LD16(obj + 6);
    int k;

    for (k = 0; k < 5; k++)
        ids[k] = LD16(obj + 10 + k * 2);
    if (flag != 0) {
        int stage = LDU8(0x060C17F0);

        if (stage < 9) {
            level += 16;
            if (stage >= 3 && stage < 6)
                level += 16;
        }
    }
    k = 0;
    do {
        if (ids[k] != 0)
            ST16(OBJ(ids[k]) + 46, level);
    } while (AGAIN(++k < 5));
}

void f06052F3C(void)
{
    unsigned int key = LDU16(0x26006096);
    gaddr p = 0x060B6BFC;
    int i = 0;
    int found = 255;

    while (LD32(p) != 0) {
        POLL();
        if (key == LD32(p)) {
            found = i;
            break;
        }
        i++;
        p += 4;
    }
    if (found != 255 && found != ((LD32(0x060C1040) >> 4) & 7)) {
        GCALL1(0x0600996A, found == 0 ? 6 : 5);
        ST32(0x060C1040, (LD32(0x060C1040) & 0xFF0F) | (found << 4));
    }
}

void f060535A2(void)
{
    int i = 0;

    do {
        ST8(0x060C0640 + i, 0);
        ST8(0x060C064A + i, i);
        i++;
    } while (AGAIN(i < 10));
    if (LDU8(0x060C17DB) == 2) {
        ST8(0x060C0640, 1);
        ST8(0x060C0641, 1);
        ST8(0x060C063C, 2);
    } else {
        ST8(0x060C17DB, 1);
        ST8(0x060C0640, 1);
        ST8(0x060C063C, 1);
    }
    ST8(0x060C063D, 2);
    POLL();
    GJUMP0(0x0604D7F4);
}

void f06053934(gaddr dst, int a, int b, int c)
{
    int i = 0;
    gaddr p = dst;
    int r;

    do {
        ST16(p, 0);
        i++;
        p += 2;
    } while (AGAIN(i < 4));
    if ((short)a == 255) {
        if ((short)b == 0)
            ST16(dst, (short)c == 0 ? 0x206 : 0x205);
        else
            ST16(dst, (short)b == 4 ? 0x203 : 0x204);
        return;
    }
    r = GCALL2(0x0604D47C, a, b);
    if (r & 0xFFFF) {
        ST16(dst, 0x201);
        ST16(dst + 2, r + 0x1F4);
    } else if ((short)a != 4 || (short)b < 4 || (short)b > 7) {
        r = GCALL2(0x0604D4D4, a, b);
        ST16(dst, 0x200);
        ST16(dst + 2, (short)(a + 1) + 0x1F4);
        ST16(dst + 4, 0x1FF);
        ST16(dst + 6, r + 0x1F4);
    } else {
        ST16(dst, 0x20D);
    }
}

void f06053C58(void)
{
    GJUMP1(0x06038268, 0x060C17F2);
}

void f06053EB2(void)
{
    GCALL1(0x060692DC, LDU16(0x060D7B52));
    GJUMP1(0x06022EDA, 0);
}

void f06053EC6(void)
{
    ST16(0x060D7B54, 16);
}

int f06053ECE(void)
{
    gaddr obj;

    if (TGET(h12) == 0)
        return 0;
    obj = LD32(TASK_OBJ);
    ST16(obj + 38, LD16(obj + 38) + 4);
    obj = LD32(TASK_OBJ);
    if (LD16(obj + 38) > 128) {
        ST16(LD32(TASK_OBJ) + 38, 128);
        TSET(fn, 0x06053F5C);
        TSET(h14, 16);
        GCALL1(0x0605417A, 30);
    }
    return GJUMP2(0x0600A3DC, TGET(h8), TGET(h10));
}

int f06053F5C(void)
{
    int n;

    if (TGET(h14) != 0) {
        n = (short)TGET(h14) - 1;
        TSET(h14, n);
        return n;
    }
    TSET(fn, 0x06053F92);
    TSET(h12, 64);
    TSET(h14, 0);
    n = LD16(LD32(TASK_OBJ) + 38) << 8;
    TSET(h18, n);
    return n;
}

int f0605401C(void)
{
    if (LDU16(OBJ(TGET(h10)) + 60) < 0xFF00)
        return 0xFF00;
    TSET(h16, 1);
    TSET(fn, 0x0603DDA6);
    return 1;
}

int f06054046(void)
{
    return LD16(0x060D7B58);
}

int f0605404C(void)
{
    GCALL2(0x06022F1C, 1, 0x0603DDA6);
    TSET(h6, 0);
    TSET(h18, 0);
    TSET(h14, 0);
    TSET(h12, 0);
    TSET(h10, 0);
    return 0;
}

void f0605417A(short v)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 1);

    SET(Slot24, s, fn, 0x06054086);
    SET(Slot24, s, w18, v);
}

int f060542CE(void)
{
    int scale = DIVS((128 - LD16(OBJ(LDU16(0x060D7B50)) + 38)) << 8, 128);

    ST16(LD32(TASK_OBJ) + 70, scale);
    return scale;
}

void f06054306(void)
{
    GJUMP1(0x06022EDA, 2);
}

int f06054350(void)
{
    GCALL1(0x06008A96, 1);
    return GJUMP1(0x060092D4, 17);
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

void f06056944(gaddr list)
{
    gaddr obj;
    unsigned int a, b, c;
    int i = 0;

    do {
        obj = OBJ(LDU16(list + i * 2));
        ST16(obj + 4, i >= 2 ? 99 : 80);
        GCALL2(0x0606AAC8, obj, 6);
        i++;
        ST16(obj + 42, LD16(obj + 42) | 0x100);
        ST16(obj + 46, 0);
    } while (AGAIN(i < 3));
    a = LDU16(list);
    b = LDU16(list + 2);
    c = LDU16(list + 4);
    ST16(OBJ(b) + 20, 80);
    ST16(OBJ(a) + 20, 80);
    ST16(OBJ(b) + 24, 0x12F);
    ST16(OBJ(a) + 24, 0x12F);
    ST16(OBJ(a) + 22, 16);
    ST16(OBJ(c) + 22, 16);
    ST16(OBJ(a) + 26, 40);
    ST16(OBJ(b) + 22, 189);
    ST16(OBJ(b) + 26, 207);
    ST16(OBJ(c) + 26, 207);
    ST16(OBJ(c) + 20, 16);
    ST16(OBJ(c) + 24, 79);
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

int f06057012(unsigned short n)
{
    int r = MODS(n, 5);

    return r * 3 + 7;
}

int f0605702C(int n)
{
    return GCALL1(0x06056FA4, n) + 1;
}

int f06057038(int n)
{
    return GCALL1(0x06057012, n) + 2;
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

static void accelerate(gaddr speed, int target, int current)
{
    int before = ABS(LD16(speed));
    int sign;

    if (target > current)
        ST16(speed, LD16(speed) + 64);
    else if (target < current)
        ST16(speed, LD16(speed) - 64);
    sign = LD16(speed) >= 0 ? 1 : -1;
    ST16(speed, ABS(LD16(speed)));
    if (LD16(speed) > 0x1000)
        ST16(speed, 0x1000);
    if ((unsigned int)before > (unsigned int)LD16(speed) && LD16(speed) > 64)
        ST16(speed, LD16(speed) - 48);
    ST16(speed, (short)LD16(speed) * (short)sign);
}

static void jump(gaddr speed, int target, int current)
{
    int distance = ABS(target - current);

    if (distance >= 0x100000)
        ST16(speed, 0x1000);
    else
        ST16(speed, HELPER(distance >> 8));
    if (target < current)
        ST16(speed, -LD16(speed));
}

int f06057930(short px, short py, short ease)
{
    int tx = (40 - px) << 16;
    int ty = (40 - py) << 16;
    int cx = LD32(0x060FAA20) & -65536;
    int cy = LD32(0x060FAA24) & -65536;

    if (ABS(tx - cx) >= 0x20000 || ABS(ty - cy) >= 0x20000) {
        if (ease == 0) {
            accelerate(0x060C184C, tx, cx);
            accelerate(0x060C184E, ty, cy);
        } else {
            jump(0x060C184C, tx, cx);
            jump(0x060C184E, ty, cy);
        }
        cx += LD16(0x060C184C) << 8;
        cy += LD16(0x060C184E) << 8;
        ST32(0x060FAA20, cx);
        ST32(0x060FAA24, cy);
    } else {
        cx = tx;
        cy = ty;
        ST32(0x060FAA20, cx);
        ST32(0x060FAA24, cy);
    }
    ST16(0x060BB8FC, 1);
    return tx == cx && ty == cy;
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

void f06058598(gaddr list)
{
    FRAME(sp, 48);
    gaddr pair = sp - 44;
    gaddr obj;
    int i = 0;

    COPYB(pair, 0x060B25E6, 16);
    GCALL2(0x06008A6A, 8, 1);
    do {
        obj = OBJ(LDU16(list));
        ST16(obj + 4, 0x190);
        ST16(obj + 44, 1);
        ST16(obj + 16, LD16(pair) << 3);
        ST16(obj + 18, LD16(pair + 2) << 3);
        ST16(obj + 38, 0);
        ST16(obj + 36, 0);
        i++;
        list += 2;
        pair += 4;
    } while (AGAIN(i < 4));
}

int f06059040(void)
{
    if (!LD8(0x26006135))
        return 2;
    if (LD32(0x060C0AA8) != 2)
        return 1;
    return LD8(0x26006137) ? 1 : 2;
}

void f06059AE8(void)
{
    int mode = LD32(0x060C0AA8);

    if (mode == 1) {
        GJUMP1(0x06038268, 0x060C18CE);
    } else if (mode == 2) {
        GCALL1(0x06038268, 0x060C18CE);
        POLL();
        GJUMP1(0x06038268, 0x060C18EC);
    }
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

void f0605A5E8(unsigned char on)
{
    gaddr mode = 0x060C1048;
    int kind, used, i;

    if (!on)
        return;
    ST32(mode, LD32(mode) | 0x00100000);
    GCALL2(0x06035DC4, GCALL3(0x0603666E, 10, 2, 12), 0x00200000);
    kind = LD8(0x060EC47B + (short)((LD8(0x060C122C) & 255) * 24)) & 255;
    if (kind == 1) {
        ST32(mode, (LD32(mode) & -12289) | 0x1000);
    } else if (kind == 2) {
        ST32(mode, (LD32(mode) & -12289) | 0x2000);
        ST8(0x060C0682, LD8(0x060C0682) & 239);
        ST8(0x060C18FA, LD8(0x060C18FA) & 239);
    }
    if ((LD32(mode) & 0x30) == 0x20) {
        if ((LD32(mode) & 0x3000) != 0x1000) {
            used = LD8(0x060C1904) & 255;
        } else {
            used = 0;
            i = 0;
            do {
                used += LD8(0x060C18FC + i) & 255;
                i++;
            } while (AGAIN(i < 8));
        }
        if (used & 0xFFFF)
            ST32(mode, LD32(mode) | 0x01000000);
        else
            ST32(mode, LD32(mode) & 0xFEFFFFFF);
        if (LD32(mode) & 0x01000000) {
            i = 0;
            if ((LD32(mode) & 0x3000) != 0x1000) {
                do {
                    ST8(0x060E1C4E + i, 0);
                    i++;
                } while (AGAIN(i < 8));
            } else {
                do {
                    ST8(0x060E1C4E + i, LD8(0x060C18FC + i));
                    i++;
                } while (AGAIN(i < 8));
            }
            ST8(0x060C18FB, used);
            ST8(0x060C0683, used);
        }
    }
    GCALL0(0x0605A4E4);
    if (GCALL0(0x06033380) != 0) {
        GCALL2(0x06035E18, GCALL3(0x0603666E, 10, 2, 12), 0);
        GCALL2(0x060359B0, 12, 0);
        ST32(mode, LD32(mode) & 0xFFFBFFFF);
        ST32(mode, LD32(mode) & 0xFFF7FFFF);
        ST32(mode, LD32(mode) & 0xFFDFFFFF & 0xFFFEFFFF);
    }
}

void f0605A798(unsigned char on)
{
    if (!on) {
        ST32(0x060C1234, LD32(0x060C1238));
        return;
    }
    ST32(0x060C1048, LD32(0x060C1048) | 0x00200000);
    GCALL2(0x06035DC4, GCALL3(0x0603666E, 1, 3, 40), 0x00200000);
    if (GCALL0(0x06033380) != 0) {
        GCALL2(0x06035DC4, GCALL3(0x0603666E, 1, 3, 40), 0);
        GCALL2(0x06035E18, GCALL3(0x0603666E, 1, 4, 50), 0);
        ST32(0x060C1048, LD32(0x060C1048) & 0xFFF7FFFF);
        ST32(0x060C1048, LD32(0x060C1048) & 0xFFFBFFFF);
    }
    ST32(0x060C1238, LD32(0x060C1234));
}

void f0605A85C(unsigned char on)
{
    int kind = LDU16(POINTS + 2 + (short)(LDU8(0x060C122C) * 24)) & 255;
    int flags;
    int slot;
    int mode;

    if (on == 0)
        return;
    ST32(0x060C1048, LD32(0x060C1048) | 0x00400000);
    if (kind == 1) {
        ST32(0x060C1048, LD32(0x060C1048) & 0xFFFFF3FF);
        ST32(0x060C1048, LD32(0x060C1048) | 0x400);
        GCALL2(0x06035DC4, GCALL3(0x0603666E, 1, 4, 50), 0x00100000);
    } else if (kind == 2) {
        flags = (LD32(0x060C1048) & 0xFFFFF3FF) | 0x800;
        ST32(0x060C1048, flags);
        slot = GCALL3(0x0603666E, 1, 4, 50);
        mode = (flags & 0x00040000) ? 0x00200000 : 0x00100000;
        GCALL2(0x06035DC4, slot, mode);
    }
}

void f0605A8F4(void)
{
    int kind = 255;
    int arg = 255;
    int slot;
    int packed;
    int bits;
    int count = 0;
    int shift;
    int field;
    int free_;
    int next;

    if (LDU8(0x060C122C) < 30) {
        kind = LD16(POINTS + (short)(LDU8(0x060C122C) * 24));
        arg = LD16(POINTS + (short)(LDU8(0x060C122C) * 24) + 2);
    }
    if ((kind & 255) != 12)
        return;
    slot = (arg & 255) - 1;
    packed = LD32(0x060C1234);
    bits = packed & ((LD32(0x060C1048) & 0x3000) == 0x1000 ? 0xFFFF : 0x000FFFFF);
    while (bits != 0) {
        POLL();
        if (bits & 3)
            count++;
        bits = (unsigned int)bits >> 2;
    }
    shift = slot << 1;
    field = SHR(packed, shift) & 3;
    free_ = LD8(0x26006134 + slot) == 0;
    next = field;
    if (field == 0) {
        if (!(LDU16(0x260060B0) & 0x4000)) {
            if (LDU16(0x260060B0) & 0x8000)
                next = free_ ? 1 : 2;
        } else {
            next = 2;
        }
    } else if (field == 1) {
        if (!(LDU16(0x260060B0) & 0x4000)) {
            if (LDU16(0x260060B0) & 0x8000)
                next = 2;
        } else {
            next = (unsigned int)count > 2 ? 0 : 2;
        }
    } else if (field == 2) {
        if (!(LDU16(0x260060B0) & 0x4000)) {
            if (LDU16(0x260060B0) & 0x8000) {
                if ((unsigned int)count > 2)
                    next = 0;
                else if (free_)
                    next = 1;
            }
        } else if (!free_) {
            if ((unsigned int)count > 2)
                next = 0;
        } else {
            next = 1;
        }
    }
    next = SHL(next, shift);
    packed = (packed & ~SHL(3, shift)) | next;
    ST32(0x060C1234, packed);
    ST8(0x060C1243, count >= 2 ? 0 : 3);
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

void f0605B326(void)
{
    int link = 3;
    int row = 2;
    gaddr p;

    GCALL1(0x06035D64, 0x060B704C);
    if ((LD32(0x060C1048) & 48) == 16) {
        p = POINTS + (short)((unsigned short)GCALL6(0x06035CDA, 31, 1, 255, 20, 3, 0x0605B570) * 24);
        ST32(p + 12, LD32(p + 12) | 0x80000);
        link = 5;
    }
    do {
        p = POINTS + (short)((unsigned short)GCALL6(0x06035CDA, 31, row, 255, 20, link, 0x0605B570) * 24);
        ST32(p + 12, LD32(p + 12) | 0x80000);
        row++;
        link += 2;
    } while (AGAIN(row < 8));
    GCALL0(0x0605B7A6);
    if ((LD32(0x060C1048) & 48) == 16) {
        if (!(LD32(0x060C1048) & 0x02000000)) {
            ST8(0x060C0683, 3);
            ST8(0x060C18FB, 3);
        } else {
            ST8(0x060C18FB, LD8(0x060C0683));
        }
    }
    ST8(0x060C18FA, LD8(0x060C0682));
    ST8(0x060C18F9, LD8(0x060C0681));
    ST8(0x060C18F8, LD8(0x060C0680));
    ST32(0x060C1650, 0x0605B614);
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

static void cycle(gaddr p, int hi, int mid, int mid_step, int size)
{
    ST8(p, LD8(p) - 1);
    if (hi)
        ST8(p, LD8(p) + 1);
    if (mid)
        ST8(p, LD8(p) + mid_step);
    ST8(p, MODS(LD8(p) & 255, size));
    ST8(p, LD8(p) + 1);
}

int f0605B614(void)
{
    int a = 255;
    int b = 255;
    int sel, hi, mid, max;
    unsigned int pad;
    gaddr rec;

    if ((LD8(0x060C122C) & 255) < 30) {
        rec = 0x060EC478 + (short)((LD8(0x060C122C) & 255) * 24);
        a = LD16(rec);
        b = LD16(rec + 2);
    }
    sel = a & 255;
    pad = LDU16(0x260060B0);
    hi = pad & 0x8000;
    mid = pad & 0x4000;
    if (sel == 31) {
        switch (b & 255) {
        case 1:
            cycle(0x060C18FB, hi, mid, 4, 5);
            break;
        case 2:
            cycle(0x060C18F9, hi, mid, 8, 9);
            break;
        case 3:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 128);
            break;
        case 4:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 2);
            break;
        case 5:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 16);
            break;
        case 6:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 4);
            break;
        case 7:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 8);
            break;
        }
    }
    if (sel == 32) {
        if (hi) {
            ST8(0x060C18F8, LD8(0x060C18F8) + 1);
            max = LD32(0x060C1040) & 8 ? 3 : 2;
            if ((LD8(0x060C18F8) & 255) > max)
                ST8(0x060C18F8, 0);
        }
        if (mid) {
            ST8(0x060C18F8, LD8(0x060C18F8) - 1);
            max = LD32(0x060C1040) & 8 ? 3 : 2;
            if ((LD8(0x060C18F8) & 255) > max)
                ST8(0x060C18F8, max);
        }
    }
    return sel;
}

void f0605B7A6(void)
{
    int i;

    if ((LD32(0x060C1048) & 48) == 16) {
        if ((short)GCALL5(0x06037D02, -1, 0x0605B8C6, 31, 1, 255) >= 0) {
            ST8(LD32(0x060C1658), LD8(LD32(0x060C165C) + 20));
            ST8(LD32(0x060C1658) + 1, LD8(LD32(0x060C165C) + 21));
            ST16(LD32(0x060C1658) + 4, 455);
        }
    } else {
        if ((short)GCALL5(0x06037D02, -1, 0x0605B8C6, 31, 2, 255) >= 0) {
            ST8(LD32(0x060C1658), LD8(LD32(0x060C165C) + 20));
            ST8(LD32(0x060C1658) + 1, LD8(LD32(0x060C165C) + 21));
            ST16(LD32(0x060C1658) + 4, 456);
        }
    }
    i = 1;
    do {
        if ((short)GCALL5(0x06037D02, -1, LD32(0x060B70BC + (i - 1) * 4), 31, i, 255) >= 0) {
            ST8(LD32(0x060C1658), LD8(LD32(0x060C165C) + 20) + 12);
            ST8(LD32(0x060C1658) + 1, LD8(LD32(0x060C165C) + 21));
            ST16(LD32(0x060C1658) + 4, LD16(0x060B70DC + (i - 1) * 2));
        }
        i++;
    } while (AGAIN(i < 8));
    if ((short)GCALL5(0x06037D02, -1, 0x0605BC9A, 32, 1, 255) >= 0) {
        ST8(LD32(0x060C1658), LD8(LD32(0x060C165C) + 20));
        ST8(LD32(0x060C1658) + 1, LD8(LD32(0x060C165C) + 21));
    }
}

int f0605B960(void)
{
    REF(Fall) fall = FALL_PTR;
    short index = GCALL1(0x060691DA, 0x1EB);
    gaddr obj = OBJ(index);

    SET(Fall, fall, id, index);
    ST16(obj + 44, 1);
    ST16(obj + 16, GET(Fall, FALL_PTR, col) << 3);
    ST16(obj + 18, GET(Fall, FALL_PTR, row) << 3);
    GCALL2(0x0606950C, obj, 2);
    ST16(obj + 40, LD16(obj + 40) | 0x400);
    SET(Fall, FALL_PTR, fn, 0x0605B9BC);
    return 40;
}

void f0605BBEC(void)
{
    gaddr obj;
    unsigned short id;
    REF(Fall) fall = FALL_PTR;

    id = GCALL1(0x060691DA, 0x1EB);
    SET(Fall, fall, id, id);
    obj = OBJ(id);
    ST16(obj + 44, 1);
    ST16(obj + 16, GET(Fall, FALL_PTR, col) * 8);
    ST16(obj + 18, GET(Fall, FALL_PTR, row) * 8);
    GCALL2(0x0606950C, obj, 2);
    ST16(obj + 40, LD16(obj + 40) | 0x400);
    SET(Fall, FALL_PTR, fn, 0x0605BC48);
}

int f0605BC9A(void)
{
    REF(Fall) fall = FALL_PTR;
    short index = GCALL1(0x060691DA, 0x1EB);
    gaddr obj = OBJ(index);

    SET(Fall, fall, id, index);
    ST16(obj + 44, 1);
    ST16(obj + 16, GET(Fall, FALL_PTR, col) << 3);
    ST16(obj + 18, GET(Fall, FALL_PTR, row) << 3);
    GCALL2(0x0606950C, obj, 2);
    ST16(obj + 40, LD16(obj + 40) | 0x400);
    SET(Fall, FALL_PTR, fn, 0x0605BCF6);
    return 40;
}

void f0605C9B4(int a)
{
    POLL();
    GJUMP2(0x0602AD3C, a, LD16(0x060C1918));
}

void f0605C9BC(unsigned short a)
{
    GCALL2(0x0600CA32, 0, a);
    POLL();
    GJUMP2(0x0602AD3C, LD16(0x060D7E8A), LD16(0x060C1918));
}

void f0605CA10(void)
{
    if (GCALL2(0x06022F1C, 1, 0x0605CAEC) < 0)
        return;
    TSET(h6, 0);
    GCALL1(0x0602A6D2, 8);
    GCALL5(0x0602A6FA, 0, 64, 256, 0, 256);
    GCALL5(0x0602A6FA, 47, 64, 256, 0, 256);
    GCALL5(0x0602A6FA, 48, 512, 384, 0, 256);
    GCALL5(0x0602A6FA, 64, 512, 640, 0, 256);
    GCALL5(0x0602A6FA, 80, 512, 768, 0, 256);
    GCALL5(0x0602A6FA, 96, 512, 896, 0, 256);
    GCALL5(0x0602A6FA, 112, 512, 960, 0, 256);
    GCALL5(0x0602A6FA, 160, 512, 1024, 0, 256);
    GCALL5(0x0602A6FA, 191, 512, 1024, 0, 256);
    GCALL5(0x0602A6FA, 192, 2048, 256, 0, 256);
    GCALL5(0x0602A6FA, 255, 2048, 256, 0, 256);
    TSET(h10, 0);
    TSET(h16, 0);
    TSET(h12, 0);
    TSET(h14, 0);
    TSET(h18, 1);
}

void f0605CAEC(void)
{
    int dir;
    int step;

    ST32(0x060C0338, LD32(0x060C0338) + LD32(0x060C1914));
    step = LD32(0x060C033C);
    ST16(0x060C1918, DIVS(step, 0x10000));
    GCALL1(0x0602A876, step);
    switch ((LD32(0x060C0338) >> 16) & 31) {
    case 5:
    case 16:
        dir = -1;
        break;
    case 8:
    case 19:
        dir = 1;
        break;
    default:
        TSET(h16, 0);
        dir = 0;
    }
    TSET(h10, TGET(h10) + 1);
    if (dir == 0) {
        TSET(h16, 0);
    } else if (TGET(h16) == 0) {
        TSET(h14, TGET(h14) + dir);
        TSET(h16, 1);
        GJUMP2(0x0600D5EA, 0, dir);
    }
}

void f0605CBCC(void)
{
    GCALL2(0x0600D5EA, 0, -LD16(0x060D7B6E));
    GJUMP1(0x06022EDA, 1);
}

void f0605CBE2(void)
{
    GCALL1(0x06008A96, 1);
    GJUMP2(0x06008ECA, 24, 0x380);
}

int f0605CCE0(void)
{
    gaddr obj = OBJ(TGET(h8));
    int pos;

    ST16(obj + 18, (short)TGET(h10) - (short)(LD32(0x060C033C) >> 16));
    GCALL1(0x0607B414, TGET(h8));
    pos = (LD16(obj + 16) << 16) | LDU16(obj + 12);
    pos -= GCALL1(0x0605C9B4, LD16(obj + 18)) & -256;
    if (pos < (int)0xFF000000)
        pos = 0x02000000;
    ST16(obj + 16, (unsigned int)pos >> 16);
    ST16(obj + 12, pos);
    return pos;
}

void f0605D724(void)
{
    ST32(0x060D7C50, 0x0605D72C);
}

void f0605DBAE(void)
{
    ST32(0x060D7C80, 0x0605DBB6);
}

void f0605DDB6(void)
{
    GCALL1(0x0606948A, (short)TGET(h8));
    if (GCALL1(0x0600CA6A, LDU16(0x060D7B50 + (short)((short)TGET(h10) * 24))) == TGET(h12))
        TSET(fn, 0x0605DE34);
}

int f0605DE8C(short which)
{
    FRAME(sp, 24);
    gaddr table = sp - 20;

    COPYB(table, 0x060B2686, 6);
    GCALL2(0x06022F1C, which + 17, 0x0603DDA6);
    ST16(LD32(TASK_PTR) + 6, 0);
    ST16(LD32(TASK_OBJ) + 44, 1);
    ST16(LD32(TASK_OBJ) + 36, LD16(LD32(TASK_OBJ) + 36) - 16);
    ST16(LD32(TASK_OBJ) + 38, LD16(LD32(TASK_OBJ) + 38) - 20);
    ST16(LD32(TASK_OBJ) + 46, 0x200);
    GCALL2(0x0606AAC8, LD32(TASK_OBJ), 7);
    ST16(LD32(TASK_PTR) + 10, LD16(table + which * 2));
    ST16(LD32(TASK_PTR) + 14, 0);
    return 0;
}

void f0605E592(unsigned short i)
{
    if (i < 0x1000 && (LDU16(0x060EE8B0 + i * 2) & 15) != 13)
        ST16(0x060EC8B0 + i * 2, LD16(0x060EC8B0 + i * 2) & 0xF8FF);
}

void f0605EAF6(gaddr list, int count)
{
    gaddr task;
    int v;
    int i = 0;

    if ((short)count > 0) {
        do {
            task = LD32(TASK_PTR);
            if ((short)i == 0) {
                v = LD16(task + 8);
                ST16(list, v);
                ST16(0x060C1AA8, v);
            } else if ((short)i >= 1 && (short)i <= 6) {
                v = GCALL2(0x060691DA, 1, count);
                ST16(task + 8 + (short)i * 2, v);
                ST16(list + (short)i * 2, v);
                ST16(0x060C1AA8, v);
            }
            GCALL1(0x06068FF4, LDU16(0x060C1AA8));
            i++;
        } while (AGAIN((short)i < (short)count));
    }
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

int f0605F0A6(int n)
{
    int i = 1;

    ST32(TASK_PTR, 0x060D7B60);
    do {
        if (LD16(TASK + 8) != 0) {
            int cell = GCALL1(0x0600CA6A, LDU16(TASK + 8));
            int tag;

            ST32(TASK_OBJ, OBJ(LDU16(TASK + 8)));
            if (LDU16(REC(n) + 20) == cell) {
                tag = LDU16(LD32(TASK_OBJ) + 50);
                if (tag >= 88 && tag <= 95)
                    return i;
            }
        }
        ST32(TASK_PTR, LD32(TASK_PTR) + 24);
    } while (AGAIN(++i < 5));
    return 0;
}

int f0605F136(int a)
{
    int r = GCALL1(0x0605F0A6, a);

    if (r == 0)
        return 0;
    if (TGET(h12) != a || TGET(h18) != 0)
        return 0;
    return r + 1;
}

int f0605F204(int a)
{
    int r = GCALL1(0x0605F0A6, a);

    if (r == 0)
        return 0;
    if (TGET(h12) != a || TGET(h18) != 0)
        return 0;
    TSET(h12, 255);
    return r;
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
