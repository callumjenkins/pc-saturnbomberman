#include "krnl.h"

void f06061412(void)
{
    int x = LD16(0x060C034C);
    int y = LD16(0x060C034E);

    ST16(0x060D7CBE, x);
    ST16(0x060D7CC0, y);
    ST16(OBJ(LDU16(0x060D7CB8)) + 16, 168 - x);
    ST16(OBJ(LDU16(0x060D7CB8)) + 18, 24 - y);
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

int f06062914(short v)
{
    ST16(0x060D7CCC, v);
    ST32(0x060D7CC8, 0x06062958);
    ST16(0x060D7CD4, 1);
    return 1;
}

void f060633F2(short n)
{
    SET(Slot24, BYTEOFF(Slot24, SLOTS, (short)(n * 24)), fn, 0x06063406);
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

int f06065F18(void)
{
    if (GET(Slot24, ELEM(Slot24, SLOTS, 2), fn) == 0x0603DDA6)
        return -1;
    return 0;
}

void f06066AC0(void)
{
    ST8(0x060C1925, 1);
}

void f06066B5E(void)
{
    ST16(0x060D7BB6, 1);
}

void f06066E96(void)
{
    int slot = 5;

    do {
        ST32(SLOTS + slot * 24, 0x06066EAE);
    } while (AGAIN(++slot < 11));
}

int f06066EF4(void)
{
    int tick = LD32(TICK);

    if (!(tick & 7))
        ST16(0x060C034A, LD16(0x060C034A) - 1);
    return tick;
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

void f0606A996(int value)
{
    ST32(0x060C1B24, value);
}

void f0606AA06(void)
{
    ST16(0x060B7BA4, 0);
    ST16(0x060B7BA6, 0);
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

int f0606B060(int k)
{
    return !(k == 50 || k == 51 || k == 147);
}

int f0606B1EC(void)
{
    return 0;
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

void f0606C82C(unsigned int i, int bits)
{
    if (i >= 0x1000)
        return;
    if (LD16(0x060C1E42))
        POLL();
    ST16(0x060EC8B0 + i * 2, LD16(0x060EC8B0 + i * 2) | bits);
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

void f0606DA88(void)
{
    int i = 0;

    do {
        ST16(0x060C1F38 + i * 2, 0);
    } while (AGAIN(++i < 5));
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
