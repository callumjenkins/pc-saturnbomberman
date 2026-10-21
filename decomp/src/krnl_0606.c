#include "krnl.h"

int f06060440(void)
{
    GCALL0(0x06039F54);
    return GJUMP0(0x06063370);
}

void f06061412(void)
{
    int x = LD16(0x060C034C);
    int y = LD16(0x060C034E);

    ST16(0x060D7CBE, x);
    ST16(0x060D7CC0, y);
    ST16(OBJ(LDU16(0x060D7CB8)) + 16, 168 - x);
    ST16(OBJ(LDU16(0x060D7CB8)) + 18, 24 - y);
}

int f060614A4(void)
{
    int y;

    ST16(LD32(TASK_OBJ) + 4, LD16(OBJ(LDU16(REC(LDU16(0x060C2898)) + 22)) + 4) - 1);
    ST16(LD32(TASK_OBJ) + 36, (short)TGET(h14) - LD16(0x060FAA34));
    y = (short)TGET(h16) - LD16(0x060FAA36);
    ST16(LD32(TASK_OBJ) + 38, y);
    return y;
}

void f060614F8(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 15);

    ST16(OBJS + 4 + (unsigned short)(GET(Slot24, s, obj) * 84), 1);
    SET(Slot24, s, fn, 0x0603DDA6);
}

void f06061BD4(short a, short b)
{
    ST16(0x060D7B86, a);
    ST16(0x060D7B88, b);
}

int f06062168(void)
{
    if (LDU16(0x060D7C94) == 255)
        return -1;
    return 0;
}

int f060622A4(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 3);

    ST32(0x060D7E60, s);
    if (LDU16(OBJ(GET(Slot24, s, obj)) + 60) >= 0xFF00)
        return -1;
    return 0;
}

void f0606261C(int n)
{
    ST16(0x060D7BBA, LD16(0x060B7474 + n * 4));
    ST16(0x060D7BBC, LD16(0x060B7474 + n * 4 + 2));
    ST16(0x060D7BB8, 0);
}

void f0606267E(void)
{
    ST16(0x060D7BBA, 0);
    ST16(0x060D7BBC, 72);
}

int f0606268A(void)
{
    int obj = OBJ(LDU16(0x060D7BB0));

    return LD16(0x060D7BBA) == LD16(obj + 36) && LD16(0x060D7BBC) == LD16(obj + 38) ? -1 : 0;
}

int f0606281E(void)
{
    int y;

    ST16(LD32(TASK_OBJ) + 36, (short)TGET(h10) - LD16(0x060FAA34));
    y = (short)TGET(h12) - LD16(0x060FAA36);
    ST16(LD32(TASK_OBJ) + 38, y);
    return y;
}

int f06062914(short v)
{
    ST16(0x060D7CCC, v);
    ST32(0x060D7CC8, 0x06062958);
    ST16(0x060D7CD4, 1);
    return 1;
}

int f06062BAC(void)
{
    int n = TGET(h10);

    if (n < 0x8000) {
        n++;
        TSET(h10, n);
    }
    return n;
}

void f06063370(void)
{
    GCALL1(0x06008A96, 1);
    GJUMP2(0x06008ECA, 19, 0x380);
}

void f060633F2(short n)
{
    SET(Slot24, BYTEOFF(Slot24, SLOTS, (short)(n * 24)), fn, 0x06063406);
}

void f060635B4(void)
{
    gaddr obj = LD32(TASK_OBJ);
    unsigned int pos, rnd;

    TSET(h6, 0);
    pos = (LD16(obj + 16) << 16) + LDU16(obj + 12) - (TGET(h10) << 8);
    ST16(obj + 16, pos >> 16);
    ST16(obj + 12, pos);
    pos = (LD16(obj + 18) << 16) + LDU16(obj + 14) + (TGET(h12) << 8);
    ST16(obj + 18, pos >> 16);
    ST16(obj + 14, pos);
    if (LD16(obj + 16) < -32)
        ST16(obj + 16, 0x150);
    if (LD16(obj + 18) > 240) {
        ST16(obj + 18, LD16(obj + 18) - 232);
        ST16(obj + 16, GCALL1(0x0600A0EC, 0x130) + 8);
        rnd = GCALL0(0x0600A0B8);
        ST8(obj + 77, rnd);
        ST16(obj + 70, (rnd >> 1) + 192);
        ST16(obj + 68, (rnd >> 1) + 192);
        TSET(h10, DIVU(rnd, 5) + 16);
        TSET(h12, DIVU(rnd, 3) + 128);
    }
    ST8(obj + 77, LD8(obj + 77) + 1);
    ST8(obj + 78, LD8(obj + 78) + 1);
}

void f06063864(void)
{
    int x = (short)TGET(h10);
    gaddr flags = 0x060EC8B0 + (TGET(h10) << 1);
    int dir = 0;

    if ((short)GCALL2(0x060647BA, 1, x - 1) == 0) {
        if ((short)GCALL2(0x060647BA, 3, x + 1) != 0)
            dir = -1;
    } else {
        dir = 1;
    }
    if (dir != 0) {
        TSET(h12, dir);
        TSET(h14, 0);
        ST16(flags, LD16(flags) & 0xFF7F);
        TSET(fn, 0x06063A90);
        GCALL1(0x0600996A, 155);
        ST16(0x060C191C, LD16(0x060C191C) + 1);
    }
}

void f06063F58(void)
{
    REF(Task) task = TASK;

    SET(Task, task, h14, ((GCALL0(0x0600A0B8) & 3) + 1) << 7);
}

int f060647BA(short want, short i)
{
    int v = LDU16(0x060EC8B0 + i * 2) & 7;

    if (v == 7)
        return -1;
    if (v && (v == want || !want))
        return -1;
    return 0;
}

void f06064D12(void)
{
    if (LDU16(0x060D7BE6) == 128) {
        ST16(SLOTS + 144 + 4, 30);
        ST16(SLOTS + 144 + 14, 0);
        ST32(SLOTS + 144, 0x06064C36);
    }
}

void f060651D0(void)
{
    ST32(0x060D7C08, 0x060651D8);
}

int f06065460(void)
{
    return (unsigned char)LD8(0x060C02A1);
}

void f06065468(void)
{
    ST8(0x060C02A1, 1);
}

void f06065470(void)
{
    ST8(0x060C02A1, 0);
}

void f06065924(void)
{
    GJUMP2(0x06022F1C, 2, 0x06065890);
}

void f06065EF2(void)
{
    gaddr obj = LD32(TASK_OBJ);

    if (LD16(obj + 38) > 120)
        TSET(fn, 0x0603DDA6);
    else
        ST16(obj + 38, LD16(obj + 38) + 1);
}

int f06065F18(void)
{
    if (GET(Slot24, ELEM(Slot24, SLOTS, 2), fn) == 0x0603DDA6)
        return -1;
    return 0;
}

void f06065F2C(void)
{
    GCALL1(0x060692DC, LDU16(0x060D7B82));
    GJUMP1(0x06022EDA, 2);
}

short f0606646A(short x1, short y1, short x2, short y2)
{
    int dx = (x1 - x2) << 16;
    int dy = ((y1 - y2) << 16) + 0x8000;
    int angle = GCALL2(0x0609732A, dx, dy);
    int sx = GCALL2(0x060980C8, dx, angle);
    int sy = GCALL2(0x060980C8, dy, angle);

    return (unsigned int)GCALL2(0x06098348, sx, sy) >> 16;
}

void f06066AC0(void)
{
    ST8(0x060C1925, 1);
}

void f06066B5E(void)
{
    ST16(0x060D7BB6, 1);
}

static void descend(void)
{
    ST16(LD32(TASK_OBJ) + 18, LD16(LD32(TASK_OBJ) + 18) - (short)TGET(h14));
    TSET(h16, TGET(h16) + 1);
}

void f06066BB0(void)
{
    gaddr obj = LD32(TASK_OBJ);
    unsigned int tick;
    unsigned int age;

    ST16(obj + 36, (short)TGET(h10) - (short)(LD32(0x060FAA20) >> 16));
    ST16(obj + 38, (short)TGET(h12) - (short)(LD32(0x060FAA24) >> 16));
    if (TGET(h14) == 0)
        return;
    tick = LD32(TICK);
    age = TGET(h16);
    if (age >= 48) {
        if (age >= 64) {
            if (age >= 0x200) {
                if (!(tick & 3))
                    ST16(obj + 16, LD16(obj + 16) - 1);
                if (!(tick & 7))
                    ST16(obj + 70, LD16(obj + 70) - 1);
            } else {
                if (!(tick & 15))
                    descend();
                if (!(tick & 7))
                    ST16(obj + 16, LD16(obj + 16) - 1);
                if (!(tick & 15))
                    ST16(obj + 70, LD16(obj + 70) - 1);
            }
        } else {
            if (!(tick & 7))
                descend();
            if (!(tick & 15))
                ST16(obj + 16, LD16(obj + 16) - 1);
        }
    } else if (!(tick & 1)) {
        descend();
    }
    ST16(obj + 68, LD16(obj + 70));
}

void f06066DDE(void)
{
    ST16(0x060C1AA8, TGET(h8));
    GCALL1(0x0600A306, TGET(h10));
    if (LD16(LD32(TASK_OBJ) + 18) >= 0x118)
        GJUMP0(0x06066E5C);
}

void f06066E5C(void)
{
    gaddr obj = LD32(TASK_OBJ);
    int base = (short)TGET(h16);

    ST16(obj + 16, GCALL1(0x0600A0EC, 32) + base - 16);
    obj = LD32(TASK_OBJ);
    ST16(obj + 18, -GCALL1(0x0600A0EC, 60) - 50);
}

void f06066E96(void)
{
    int slot = 5;

    do {
        ST32(SLOTS + slot * 24, 0x06066EAE);
    } while (AGAIN(++slot < 11));
}

void f06066EAE(void)
{
    ST16(0x060C1AA8, TGET(h8));
    GCALL1(0x0600A306, TGET(h10));
    if (LD16(LD32(TASK_OBJ) + 18) >= 0x118)
        TSET(fn, 0x0603DDA6);
}

void f06066EDE(void)
{
    GCALL2(0x06022F1C, 13, 0x06066EF4);
    TSET(h6, 0);
}

int f06066EF4(void)
{
    int tick = LD32(TICK);

    if (!(tick & 7))
        ST16(0x060C034A, LD16(0x060C034A) - 1);
    return tick;
}

void f06066F08(void)
{
    GCALL2(0x06022F1C, 14, 0x0603DDA6);
    TSET(h6, 0);
    TSET(h10, LD32(0x060C032C) >> 16);
    ST16(0x060C1926, LD32(0x060C0328) >> 16);
    ST16(0x060C1928, LD32(0x060C032C) >> 16);
}

void f06066F38(void)
{
    ST32(0x060D7C98, 0x06066F40);
}

void f06066F40(void)
{
    ST16(0x060C1928, LD16(0x060C1928) - 1);
}

void f06066F4A(void)
{
    ST32(0x060C032C, LDU16(0x060D7CA2) << 16);
    GJUMP1(0x06022EDA, 14);
}

void f0606707C(short v)
{
    ST16(0x060D7CC0, v);
}

void f06067148(short v)
{
    ST16(0x060C192A, v);
}

void f0606828C(int n)
{
    gaddr obj = OBJ(LDU16(0x060DFE40 + (n + 11) * 2));

    GCALL2(0x0606AAC8, obj, 0);
    ST16(obj + 46, LD16(obj + 46) & 0xFC00);
    ST16(obj + 46, LD16(obj + 46) | (n * 16 + 96));
    ST16(obj + 16, n != 0 ? 235 : 83);
    ST16(obj + 18, 18);
}

int f060686E4(void)
{
    if (GCALL1(0x0603A00E, 0) == 0 && GCALL1(0x0603A00E, 1) == 0)
        return 0;
    return (LDU16(0x060D7E68) & 115) == 0;
}

void f060689EC(void)
{
    ST16(0x060C1980, 0);
    ST16(0x060C1982, 0);
}

void f06068DE0(void)
{
    int p = 0x060C19E4;

    do {
        ST16(p, 0);
    } while (AGAIN((p += 24) < 0x060C1AA4));
}

void f06068EC8(void)
{
    gaddr p;

    if (LDU16(0x060D7E68) & 32)
        return;
    for (p = 0x060C19E4; p < 0x060C1AA4; p += 24) {
        ST32(0x060C1AA4, p);
        if (LD16(p) != 0) {
            ST16(p + 20, LD16(p + 20) - 1);
            if (LDU16(p + 20) == 0)
                GCALL1(0x06068F14, p);
        }
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06068FF0(void)
{
    return 0;
}

void f06068FF4(unsigned short n)
{
    gaddr o = OBJ(n);

    ST32(0x060CBB5C, o);
    ST16(o + 42, 128);
    ST16(o + 10, 0);
    ST16(o + 12, 0);
    ST16(o + 14, 0);
    ST16(o + 16, 160);
    ST16(o + 18, 112);
    ST16(o + 38, 0);
    ST16(o + 36, 0);
    ST16(o + 40, 128);
    ST16(o + 46, 0);
    ST16(o + 64, 0xFFFF);
    ST16(o + 44, LD16(0x060BD924));
    ST16(o + 50, 0);
    ST16(o + 48, 0);
    ST16(o + 62, 0x100);
    ST16(o + 66, 0);
    ST16(o + 68, 0x100);
    ST16(o + 70, 0x100);
    ST16(o + 82, 0);
    ST16(o + 80, 0);
    ST16(o + 72, 0);
    ST8(o + 78, 0);
    ST8(o + 77, 0);
    ST8(o + 76, 0);
    ST16(o + 74, 8);
}

void f060692DC(unsigned int n)
{
    gaddr obj = OBJ(n);

    if (n < 2 || n >= 0x190 || LD32(obj) == 0)
        return;
    if (LDU16(obj + 42) & 0x200) {
        GCALL2(0x06008A6A, 8, LDU16(obj + 44));
        GCALL1(0x06068CC4, LDU16(obj + 50));
    }
    ST32(obj, 0);
    GCALL1(0x06069392, n);
    ST16(0x060C1AAC, LD16(0x060C1AAC) - 1);
    GCALL1(0x06068FF4, n);
}

void f0606935A(unsigned short a, unsigned short b)
{
    REF(ObjLink) x = (REF(ObjLink))OBJ(a);
    REF(ObjLink) y = (REF(ObjLink))OBJ(b);

    SET(ObjLink, x, prev, GET(ObjLink, y, prev));
    SET(ObjLink, (REF(ObjLink))OBJ(GET(ObjLink, y, prev)), next, a);
    SET(ObjLink, x, next, b);
    SET(ObjLink, y, prev, a);
}

/* The halfwords at 6 and 8 name the neighbours: each is made to point at the other. */
void f06069392(unsigned short i)
{
    REF(ObjLink) o = (REF(ObjLink))OBJ(i);

    SET(ObjLink, (REF(ObjLink))OBJ(GET(ObjLink, o, prev)), next, GET(ObjLink, o, next));
    SET(ObjLink, (REF(ObjLink))OBJ(GET(ObjLink, o, next)), prev, GET(ObjLink, o, prev));
}

int f060693DC(unsigned int from, unsigned int to, int mode)
{
    if (from < 2 || from >= 0x190 || LD32(OBJ(from)) == 0)
        return 0;
    if (to < 2 || to >= 0x190 || LD32(OBJ(to)) == 0)
        return 0;
    GCALL1(0x06069392, from);
    GCALL2(0x0606935A, from, mode >= 0 ? LDU16(OBJ(to) + 8) : to);
    return from;
}

void f06069462(unsigned short n, int v)
{
    if (v > 0x1F3)
        v = 0x1F3;
    ST16(OBJ(n) + 4, v);
}

void f0606947C(int v)
{
    GJUMP2(0x06069462, LD16(OBJIDX), v);
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

/* The game's code branches back twice, into a setter that clamps to 0x1F3, which this value never reaches. */
int f060694B8(void)
{
    int id = LDU16(OBJIDX);
    int y;

    POLL();
    y = LD16(OBJ(id) + 18);
    POLL();
    ST16(OBJ(id) + 4, y < 0 ? 20 : y >= 0x1CC ? 0x1DF : y + 20);
    return 0x060C3820;
}

int f060695EA(unsigned short obj, int bits)
{
    return GJUMP2(0x060695B0, OBJ(obj), bits);
}

unsigned short f06069606(gaddr p)
{
    int k = (LDU16(0x060FB89C) & 15) * 4;

    return LDU16(p + 46) & LDU16(0x060B7BAA + k) & LDU16(0x060B7BEA + k);
}

void f0606A8FC(void)
{
    gaddr q = LD32(0x060CBB5C);
    int a = LD16(q + 20) + LD32(0x060C1B08);
    int b = LD16(q + 22) + LD32(0x060C1B0C);
    int c = LD16(q + 24) + LD32(0x060C1B08);
    int d = LD16(q + 26) + LD32(0x060C1B0C);

    ST16(q + 20, a);
    ST16(0x060C1AE0, a + LD16(q + 36));
    ST16(q + 22, b);
    ST16(0x060C1AE2, LD16(q + 38) + b);
    ST16(q + 24, c);
    ST16(0x060C1AE4, c + LD16(q + 36));
    ST16(q + 26, d);
    ST16(0x060C1AE6, LD16(q + 38) + d);
    if ((unsigned int)LD32(0x060C1B04) < 0x323) {
        GCALL2(0x0609FCA4, LD16(LD32(0x060CBB5C) + 4), 0x060C1AE0);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f0606A996(int value)
{
    ST32(0x060C1B24, value);
}

void f0606A9E4(void)
{
    int v;

    ST16(0x060B7BA4, 0x100);
    ST16(0x060B7BA6, 0x100);
    v = GCALL1(0x060980DC, 0x100);
    ST32(0x060C1B20, v);
    ST32(0x060C1B1C, v);
}

void f0606AA06(void)
{
    ST16(0x060B7BA4, 0);
    ST16(0x060B7BA6, 0);
}

int f0606AB08(int n, int index)
{
    return GJUMP2(0x0606AAC8, OBJ(n), index);
}

int f0606AB24(gaddr obj)
{
    ST16(obj + 42, LDU16(obj + 42) & 0xFF7F);
    return LD16(obj + 42);
}

int f0606AB32(unsigned short n)
{
    return GJUMP1(0x0606AB24, OBJ(n));
}

void f0606AB4A(gaddr p)
{
    ST16(p + 42, LD16(p + 42) | 0x80);
}

void f0606AB5A(unsigned short obj)
{
    GJUMP1(0x0606AB4A, OBJ(obj));
}

void f0606AB72(gaddr p)
{
    ST16(p + 50, 0);
}

void f0606AB92(gaddr o)
{
    ST16(o + 40, (LD16(o + 40) & 0xFFFC) | 0x8000);
    if (LDU16(0x060FB89C) & 16) {
        ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
        ST16(0x060FB89C, LD16(0x060FB89C) & 0xFFEF);
    }
}

void f0606ABCC(unsigned short n)
{
    POLL();
    f0606AB92(OBJ(n));
}

void f0606AC10(void)
{
    GCALL0(0x0606B346);
    GCALL0(0x0606B36C);
    GCALL0(0x06074754);
    GCALL0(0x0608AAD8);
    ST16(0x060C1E3C, 0);
    ST16(0x060C1E42, 0);
    ST16(0x060C1E44, 1);
    ST16(0x060C1E3A, 0);
    ST16(0x060C1E3E, GCALL0(0x0602308C));
    ST16(0x060C1E40, 0);
    ST16(0x060C1E46, 0);
    ST16(0x060C1E48, 0);
    ST16(0x060C1E4A, 0);
    ST16(0x060C2E74, -1);
    ST16(0x060C1E5C, 1);
    GCALL0(0x06075C58);
    ST16(0x060C1E4E, 0);
    ST16(0x060C1E4C, 0);
    ST16(0x060C1E5A, 0);
    ST16(0x060C1E52, 0x100);
    ST16(0x060C1E50, 0x100);
    ST16(0x060C1E58, 0);
    ST16(0x060C1E56, 0);
    ST16(0x060C1E54, 0);
}

int f0606B060(int k)
{
    return !(k == 50 || k == 51 || k == 147);
}

int f0606B1EC(void)
{
    return 0;
}

void f0606B29C(int index, int value)
{
    int saved_index = LDU16(0x060C062C);
    int saved = LD32(0x060D7768);

    ST16(0x060C062C, index);
    ST32(0x060D7768, REC(LDU16(0x060C062C)));
    if (!(LD8(LD32(0x060D7768) + 4) & 192)) {
        if (LD16(LD32(0x060D7768) + 76) == 0)
            GCALL1(0x06014516, 0x0606D47C);
        ST16(LD32(0x060D7768) + 76, value);
    }
    ST32(0x060D7768, saved);
    ST16(0x060C062C, saved_index);
}

/* Sets bit 6 of byte 4 in bomber records 10 to 49 that have a nonzero halfword at 22 and bit 9 of the halfword at 42 clear. */
void f0606B300(void)
{
    gaddr p;

    for (p = (OBJECTS + 0x30) + 124 * 10; p < (OBJECTS + 0x30) + 124 * 50; p += 124) {
        if (LDU16(p + 22) && !(LDU16(p + 42) & 0x200))
            ST8(p + 4, LD8(p + 4) | 64);
        POLL();
    }
    ST16(0x060C1E40, 1);
}

void f0606B346(void)
{
}

void f0606B34A(void)
{
}

void f0606B36C(void)
{
    int i = 0;

    do {
        ST16(0x060C1EE4 + i, 0);
        ST16(0x060C1EA4 + i, 0);
        ST16(0x060C1E64 + i, 0);
        i += 2;
    } while (AGAIN(i < 64));
    GCALL1(0x06008A96, 0);
    GCALL2(0x06008ECA, 24, 0x100);
    ST16(0x060C1AB2, 0x100);
    ST16(0x060C1E84, 24);
    ST16(0x060C1EC4, 0);
    ST16(0x060C1F04, LD16(0x060C1F04) + 1);
}

void f0606B620(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 24, (LD16(cur + 24) + 8) & 0xFFF0);
    ST16(cur + 28, (LD16(cur + 28) + 8) & 0xFFF0);
    ST16(cur + 26, 0);
    ST16(cur + 30, 0);
}

int f0606B648(void)
{
    gaddr cur = LD32(0x060D7768);
    int dir = LDU16(0x060C1F24) << 1;
    int cell;

    if (LD16(cur + 44) == 0) {
        cell = LD16(0x060B90A0 + dir) + LDU16(cur + 20);
    } else {
        if ((unsigned int)((LDU16(0x060B90DC + dir) & LDU16(cur + 20)) + LD16(0x060B90AA + dir)) > LDU16(0x060B90D2 + dir))
            return 0;
        cell = LD16(0x060B90AA + dir) + LDU16(cur + 20);
    }
    if ((unsigned int)cell >= 0x1000)
        return 1;
    return (LDU16(0x060EC8B0 + cell * 2) & LDU16(cur + 18)) == 0;
}

void f0606B8CA(int n);

void f0606B8BE(void)
{
    GCALL1(0x0606B8CA, 0);
    f0606B8CA(1);
}

void f0606B8CA(int n)
{
    gaddr rec = REC(n);
    gaddr cell = CELL(n);
    int far;

    if (!(LD8(rec + 4) & 128)) {
        ST16(cell, LD16(rec + 24) - LD16(LD32(0x060D7768) + 24));
        ST16(cell + 4, GCALL1(0x060949D0, LD16(cell)));
        ST16(cell + 8, LDU16(cell + 4) >> 4);
        ST16(cell + 2, LD16(rec + 28) - LD16(LD32(0x060D7768) + 28));
        ST16(cell + 6, GCALL1(0x060949D0, LD16(cell + 2)));
        far = LDU16(cell + 6) >> 4;
    } else {
        ST16(cell, 0x7FFF);
        ST16(cell + 2, 0x7FFF);
        far = 0xFFFF;
        ST16(cell + 4, 0xFFFF);
        ST16(cell + 6, 0xFFFF);
        ST16(cell + 8, 0xFFFF);
    }
    ST16(cell + 10, far);
}

int f0606B9DE(int n)
{
    int cell;

    if ((unsigned char)LD8(REC(n) + 4) & 224)
        return 0;
    cell = CELL(n);
    return LDU16(cell + 4) < 8 && LDU16(cell + 6) < 8;
}

int f0606BAF6(void)
{
    if ((unsigned char)LD8(0x060C029C) == 8)
        return 0;
    if (LD8(REC(1) + 4) & 128)
        return 0;
    if (LD8(REC(0) + 4) & 128)
        return 1;
    return LDU16(0x060C1F4A) + LDU16(0x060C1F4C) > LDU16(0x060C1F56) + LDU16(0x060C1F58);
}

void f0606BBB0(void)
{
    gaddr cell = CELL(LD8(LD32(0x060D7768) + 65));

    ST32(0x060C1F5C, cell);
    if ((unsigned int)LD16(cell + 4) >= (unsigned int)LD16(cell + 6))
        ST16(0x060C1F24, LD16(LD32(0x060C1F5C)) >= 0 ? 1 : 3);
    else
        GJUMP0(0x0606BC2E);
}

int f0606BCD2(int n)
{
    REF(Pair12) p = BYTEOFF(Pair12, 0x060C1F42, (signed char)(n * 12));

    return GET(Pair12, p, a) <= 2 && GET(Pair12, p, b) <= 2;
}

int f0606BCD8(int n)
{
    REF(Pair12) p = BYTEOFF(Pair12, 0x060C1F42, (signed char)(n * 12));

    return GET(Pair12, p, a) <= 3 && GET(Pair12, p, b) <= 3;
}

int f0606BCDE(int n, unsigned int x, unsigned int y)
{
    return LDU16(CELL(n) + 8) <= x && LDU16(CELL(n) + 10) <= y;
}

int f0606BD32(int n)
{
    return !LD16(CELL(n) + 10) && LDU16(CELL(n) + 8) <= 2;
}

int f0606BEBC(int n)
{
    if (GCALL1(0x0606BEE2, n) != 0)
        return 1;
    return LD16(CELL(n) + 8) == 0;
}

int f0606BEE2(int n)
{
    return !LD16(CELL(n) + 10);
}

int f0606BF00(int n)
{
    REF(Pair12) p = BYTEOFF(Pair12, 0x060C1F42, (signed char)(n * 12));

    return GET(Pair12, p, a) == 0;
}

int f0606BF6C(int n)
{
    return LD16(0x060C1F44 + (signed char)(n * 12)) > 15;
}

int f0606BFE8(int n)
{
    return LD16(0x060C1F44 + (signed char)(n * 12)) < 0;
}

int f0606C05C(int n, unsigned int a, unsigned int b)
{
    gaddr cell = CELL(n);
    int v;

    switch (LD8(LD32(0x060D7768) + 6) & 255) {
    case 1:
        if (b >> 1 < LDU16(cell + 6))
            return 0;
        v = LD16(cell);
        return v >= 0 && a >= (unsigned int)v;
    case 2:
        if (a >> 1 < LDU16(cell + 4))
            return 0;
        v = LD16(cell + 2);
        return v >= 0 && b >= (unsigned int)v;
    case 3:
        if (b >> 1 < LDU16(cell + 6))
            return 0;
        v = LD16(cell);
        return v <= 0 && -a <= (unsigned int)v;
    case 4:
        if (a >> 1 < LDU16(cell + 4))
            return 0;
        v = LD16(cell + 2);
        return v <= 0 && -b <= (unsigned int)v;
    }
    return 0;
}

int f0606C168(int n, unsigned int limit)
{
    signed char off = n * 12;
    gaddr p = 0x060C1F42 + off;

    return (unsigned int)(LDU16(p + 8) + LDU16(p + 10)) > limit;
}

int f0606C268(int n)
{
    int v = (unsigned char)LD8(REC(n) + 6);

    return v >= 1 && v <= 4 ? v : 2;
}

int f0606C724(int a, int b)
{
    int cell = GCALL2(0x0600CAE4, a, b) << 1;

    if (LDU16(0x060EC8B0 + cell) & (LDU16(LD32(0x060D7768) + 18) | 0x380))
        return 1;
    if (LDU16(0x060EE8B0 + cell) & 0xF00)
        return 2;
    return 0;
}

void f0606C776(void)
{
    gaddr cur = LD32(0x060D7768);

    ST8(cur + 4, LD8(cur + 4) | 32);
    cur = LD32(0x060D7768);
    ST16(cur + 42, LD16(cur + 42) | 1);
}

void f0606C78E(void)
{
    gaddr cur = LD32(0x060D7768);

    ST8(cur + 4, LD8(cur + 4) | 32);
}

void f0606C79A(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 42, LD16(cur + 42) | 1);
}

void f0606C7AA(void)
{
    gaddr cur = LD32(0x060D7768);

    ST8(cur + 4, LD8(cur + 4) & 223);
    cur = LD32(0x060D7768);
    ST16(cur + 42, LD16(cur + 42) & 0xFFFE);
}

void f0606C7C2(void)
{
    gaddr cur = LD32(0x060D7768);

    ST8(cur + 4, LD8(cur + 4) & 223);
}

void f0606C7CE(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 42, LD16(cur + 42) & 0xFFFE);
}

void f0606C7DE(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 46, LD16(cur + 46) | 1);
}

void f0606C7EE(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 46, LD16(cur + 46) & 0xFFFE);
}

void f0606C7FE(void)
{
    GCALL0(0x0606C776);
    ST16(LD32(0x060D7768) + 18, 0);
}

void f0606C82C(unsigned int i, int bits)
{
    if (i >= 0x1000)
        return;
    if (LD16(0x060C1E42))
        POLL();
    ST16(0x060EC8B0 + i * 2, LD16(0x060EC8B0 + i * 2) | bits);
}

void f0606C850(void)
{
    gaddr cur = LD32(0x060D7768);
    unsigned int n;
    gaddr flags;

    if (LDU16(cur + 18) & 32) {
        ST16(cur + 20, GCALL0(0x0600CA84));
        n = LDU16(LD32(0x060D7768) + 20);
        if (n < 0x1000) {
            flags = 0x060EE8B0 + n * 2;
            ST16(flags, LD16(flags) | 0x4000);
        }
    }
}

void f0606C894(void)
{
    unsigned int n = GCALL0(0x0600CA84) & 0xFFFF;
    gaddr flags;

    if (n < 0x1000) {
        flags = 0x060EE8B0 + n * 2;
        ST16(flags, LD16(flags) & 0xBFFF);
    }
}

int f0606CBCC(int a, int b)
{
    gaddr mover = LD32(MOVER_PTR);
    int x = LD16(mover + 16);

    return x < -a || x > 0x140 + a || LD16(mover + 18) < -b || LD16(mover + 18) > 240 + b;
}

void f0606CC12(gaddr slot)
{
    if (LD16(slot) != 0) {
        GCALL1(0x060692DC, LDU16(slot));
        ST16(slot, 0);
    }
}

int f0606CC30(gaddr rec, int target, int step)
{
    int diff = target - LDU16(rec + 68);
    int s;

    if (diff == 0)
        return 1;
    s = GCALL1(0x060949D0, diff);
    if (s < step)
        step = s;
    if (diff < 0)
        step = -step;
    ST16(rec + 68, LD16(rec + 68) + step);
    return 0;
}

int f0606CCE8(unsigned int n)
{
    if (n >= 128)
        return 1;
    return MODU(n, (n >> 4) + 1);
}

void f0606CD0C(int a, int b, int c, int d)
{
    gaddr rec;
    int x0, y0, y;

    if (LD16(0x060C1E4C) == 0)
        return;
    if ((GCALL1(0x060691DA, 0x1F3) & 0xFFFF) == 0)
        return;
    GCALL2(0x0606AB08, LDU16(0x060C1AAA), 6);
    rec = OBJ(LDU16(0x060C1AAA));
    ST16(rec + 46, (LDU16(0x26006036) & 15) + 0x100);
    ST16(rec + 42, LD16(rec + 42) | 16);
    ST16(rec + 40, LD16(rec + 40) | 0x100);
    x0 = LDU16(LD32(0x060D7768) + 24) - LDU16(0x060D82BA);
    y0 = LDU16(LD32(0x060D7768) + 28) - LDU16(0x060D82BC);
    y = y0 + GCALL0(0x0600D0D0);
    rec = OBJ(LDU16(0x060C1AAA));
    ST16(rec + 20, b + x0);
    ST16(rec + 22, c + y);
    ST16(rec + 24, b + x0);
    ST16(rec + 26, d + y);
    ST16(rec + 28, a + x0);
    ST16(rec + 30, d + y);
    ST16(rec + 32, a + x0);
    ST16(rec + 34, c + y);
}

int f0606CE8C(unsigned char n)
{
    return -4 & (GCALL1(0x0609812C, LD32(0x060B9108 + n * 4)) + 1);
}

int f0606CEB0(unsigned char n)
{
    return -4 & (GCALL1(0x0609816C, LD32(0x060B9108 + n * 4)) + 1);
}

int f0606CED4(int a, int b)
{
    int angle = DIVS(GCALL2(0x06098348, a, b) + 0x00B40000, 0x168);

    return HELPER((128 + angle) >> 8) & 255;
}

/* Returns the table's address, which the caller reached through 0606AF68 reads. */
int f0606CF28(int n)
{
    gaddr flags = 0x060D5F34 + n * 124;

    ST8(flags, LD8(flags) | 0x40);
    return 0x060D5F34;
}

void f0606D208(void)
{
    gaddr p;

    if (LD16(0x060C1E3A))
        return;
    p = LD32(CURRENT);
    if (LD16(p + 60))
        ST16(p + 60, LD16(p + 60) - 1);
    if (LD16(p + 62))
        ST16(p + 62, LD16(p + 62) - 1);
}

int f0606D37A(void)
{
    if (LDU16(LD32(MOVER_PTR) + 60) >= 0xFF00)
        GCALL0(0x060145A8);
    return 1;
}

int f0606D648(int unused, int fallback)
{
    gaddr cur = LD32(0x060D7768);
    int phase;
    int step, left;
    int stop, edge;

    ST16(0x060C1F70, 0);
    if (LD16(cur + 54) != 0) {
        phase = LDU16(cur + 54) & 15;
        step = GCALL2(0x0606D7A6, cur, fallback);
        cur = LD32(0x060D7768);
        left = LD16(cur + 54) - step;
        ST16(cur + 54, left);
        if ((short)left > 0) {
            if (step == 0) {
                stop = 0;
                edge = 0;
            } else {
                stop = !(left & 15) && (phase & 15) != 0;
                edge = (240 & (short)left) != LDU16(LD32(0x060D7768) + 56);
            }
            if (!stop && !edge) {
                if (LDU16(LD32(0x060D7768) + 42) & 2)
                    return 0;
                if ((LDU16(LD32(0x060D7768) + 54) & 15) < 9)
                    return 0;
                if (GCALL0(0x0606D786) != 0)
                    return 0;
                cur = LD32(0x060D7768);
                ST16(cur + 54, 16 - (LD16(cur + 54) & 15));
                ST8(cur + 6, LD8(0x060B90B5 + (LD8(cur + 6) & 255) * 2));
                GCALL1(0x0606B6D2, step);
                return 0;
            }
            cur = LD32(0x060D7768);
            ST16(cur + 56, (LD16(cur + 54) - step) & 240);
            ST16(0x060C1F70, 1);
            ST16(cur + 20, GCALL0(0x0600CA84));
            if (GCALL0(0x0606D786) != 0)
                return 0;
        }
    }
    cur = LD32(0x060D7768);
    ST16(cur + 56, 0);
    ST16(cur + 54, 0);
    GCALL0(0x0606B620);
    ST16(0x060C1F70, 2);
    return 1;
}

int f0606D786(void)
{
    gaddr cur = LD32(0x060D7768);

    if (LD16(cur + 44) != 0)
        return 1;
    ST16(0x060C1F24, LD8(cur + 6) & 255);
    return GJUMP0(0x0606B648);
}

int f0606D7A6(int unused, int fallback)
{
    gaddr cur = LD32(0x060D7768);
    unsigned int speed = (LDU16(cur + 12) << 16) + LDU16(cur + 10);
    int mode = LD8(cur + 6) & 255;
    unsigned int whole, pos;
    int axis = mode == 1 || mode == 3 ? 24 : 28;

    if (mode < 1 || mode > 4)
        return fallback;
    whole = LDU16(cur + axis);
    pos = (whole << 16) + LDU16(cur + axis + 2);
    pos = mode <= 2 ? pos + speed : pos - speed;
    ST16(cur + axis, pos >> 16);
    ST16(cur + axis + 2, pos);
    if (mode <= 2)
        return LDU16(cur + axis) - whole;
    return whole - LDU16(cur + axis);
}

int f0606D95C(void)
{
    if (GCALL0(0x0606BC7E) == 0)
        return 0;
    GCALL0(0x0606D986);
    return 1;
}

void f0606D9EC(void)
{
    unsigned int n;

    GCALL0(0x0606DA88);
    n = LDU16(0x060C1F2E);
    ST16(0x060C1F38 + n * 2, 1);
    ST16(0x060C1F38 + LDU16(0x060B90B4 + LDU16(0x060C1F2E) * 2) * 2, 1);
}

void f0606DA14(void)
{
    unsigned int n;

    GCALL0(0x0606DA88);
    n = LDU16(0x060C1F2E);
    ST16(0x060C1F38 + n * 2, 2);
    ST16(0x060C1F38 + LDU16(0x060B90B4 + LDU16(0x060C1F2E) * 2) * 2, 2);
}

void f0606DA3C(void)
{
    GCALL0(0x0606DA88);
    ST16(0x060C1F38 + LDU16(0x060B90B4 + LDU16(0x060C1F2E) * 2) * 2, 1);
}

void f0606DA5C(void)
{
    int n;

    GCALL0(0x0606DA88);
    n = ((LDU16(0x060C1F2E) & 3) + 1) * 2;
    ST16(0x060C1F38 + n, 2);
    ST16(0x060C1F38 + LDU16(0x060B90B4 + n) * 2, 2);
}

void f0606DA88(void)
{
    int i = 0;

    do {
        ST16(0x060C1F38 + i * 2, 0);
    } while (AGAIN(++i < 5));
}

void f0606DA9E(void)
{
    ST16(0x060C1F24, (GCALL0(0x0600A0B8) & 3) + 1);
}

void f0606E00E(void)
{
    gaddr cur = LD32(0x060D7768);
    unsigned int dx = LDU16(cur + 24) - LDU16(cur + 82);
    unsigned int dy;

    if (dx < 8)
        ST16(0x060C1F38 + 6, 2);
    if (dx > 88)
        ST16(0x060C1F38 + 2, 2);
    cur = LD32(0x060D7768);
    dy = LDU16(cur + 28) - LDU16(cur + 84);
    if (dy < 8)
        ST16(0x060C1F38 + 8, 2);
    if (dy > 88)
        ST16(0x060C1F38 + 4, 2);
}

void f0606E81C(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 64, GCALL0(0x0606BAF6));
}

int f0606E8D0(int a, int b, int c, int d)
{
    if ((unsigned int)LD32(0x060C1000) < 0xE10) {
        ST16(LD32(MOVER_PTR) + 48, 16);
        GCALL4(0x0606B6BC, a, b, c, d);
        ST32(0x060E215C + (short)(LD16(0x060C062C) * 20), 0x0606E906);
    }
    return 0;
}

void f0606EA3A(int a, int b, int c, int d)
{
    GCALL4(0x0606B6BC, a, b, c, d);
    GCALL1(0x060144F4, 0x0606D398);
    GCALL1(0x06014516, 0x0606E7F4);
    ST32(0x060E2154 + (short)(LD16(0x060C062C) * 20), 0x0606EA6A);
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
