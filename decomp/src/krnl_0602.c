#include "krnl.h"

/* The pose an actor takes once its distance (+20) is set. */
static void settle(void)
{
    int step = DIVS(LD16(ACTB(20)) + 8, 16);

    if ((unsigned int)step >= 8)
        step = 8;
    ST8(ACTB(27), 0);
    ST8(ACTB(24), 0);
    ST8(ACTB(25), LD16(0x060B4856 + step * 2));
    ST8(ACTB(26), 4);
    ST16(ACTB(22), -((short)(LD16(ACTB(20)) >> 1) * (short)LD8(ACTB(25))));
    ST16(ACTB(28), 0);
    ST16(ACTB(10), (LD16(ACTB(10)) & 0xFFDF) | 64);
}

void f06020174(int distance, int unused, char dir)
{
    ST32(0x060C0900, OBJ(LDU16(ACTB(0))));
    ST8(ACTB(14), dir);
    ST16(ACTB(20), distance << 4);
    POLL();
    settle();
}

void f060201A0(unsigned short scale)
{
    int dir;

    ST32(0x060C0900, OBJ(LDU16(ACTB(0))));
    ST8(ACTB(14), LD8(LD32(CURRENT) + 6));
    GCALL1(0x0600C9AA, LDU16(LD32(CURRENT) + 20));
    dir = LDU8(ACTB(14));
    ST16(0x060D7EB4, (LDU16(0x060D7EB4) << 4) + LDU16(0x060B484C + dir * 2) * scale);
    dir = LDU8(ACTB(14));
    ST16(0x060D7EB6, (LDU16(0x060D7EB6) << 4) + LDU16(0x060B484A + dir * 2) * scale);
    dir = LDU8(ACTB(14));
    if (dir == 1)
        ST16(ACTB(20), LD16(0x060D7EB4) - LD16(LD32(CURRENT) + 24));
    else if (dir == 2)
        ST16(ACTB(20), LD16(0x060D7EB6) - LD16(LD32(CURRENT) + 28));
    else if (dir == 3)
        ST16(ACTB(20), LD16(LD32(CURRENT) + 24) - LD16(0x060D7EB4));
    else
        ST16(ACTB(20), LD16(LD32(CURRENT) + 28) - LD16(0x060D7EB6));
    POLL();
    settle();
}

int f06020276(void)
{
    int next = LDU8(0x060D84A3);
    gaddr a;

    for (;;) {
        a = 0x060D849C + next * 38;
        ST32(ACTOR_PTR, a);
        if (LD8(a + 7) == 0)
            return 0;
        POLL();
        if (LD8(a + 16) != 0 && LDU8(a + 15) == LDU16(0x060C062C) && (LDU16(a + 10) & 32)) {
            GCALL1(0x060201A0, 3);
            a = LD32(ACTOR_PTR);
            ST16(a + 22, -155 - 5 * (LD16(a + 20) - 40));
            return LDU8(0x060D849C + LDU8(LD32(ACTOR_PTR) + 6) * 38 + 7);
        }
        next = LDU8(LD32(ACTOR_PTR) + 7);
    }
}

int f06020330(int arg)
{
    gaddr cur = LD32(CURRENT);
    unsigned short target = GCALL1(0x0600C9C0, LD16(cur + 20) + LD16(0x060B47F0 + LDU8(cur + 6) * 2));
    int next = LDU8(0x060D849C + 7);
    gaddr a;

    for (;;) {
        a = 0x060D849C + next * 38;
        ST32(ACTOR_PTR, a);
        if (LD8(a + 7) == 0)
            return 0;
        POLL();
        if (LDU8(a + 16) > 1 && LDU8(a + 16) != 255 && LDU16(a + 4) == target && !(LDU16(a + 10) & 0x1FB)) {
            GCALL1(0x060201A0, arg);
            GCALL0(0x060210E8);
            return LDU8(0x060D849C + LDU8(LD32(ACTOR_PTR) + 6) * 38 + 7);
        }
        next = LDU8(LD32(ACTOR_PTR) + 7);
    }
}

int f060203EC(int arg, int count, int id)
{
    int next = LDU8(0x060D849C + 7);
    gaddr a;

    for (;;) {
        a = 0x060D849C + next * 38;
        ST32(ACTOR_PTR, a);
        if (LD8(a + 7) == 0)
            return 0;
        POLL();
        if (LDU8(a + 16) > 1 && LDU8(a + 16) != 255 && LDU16(a + 4) == id && !(LDU16(a + 10) & 0x1FB)) {
            if (count == 0) {
                if (LD8(a + 14) == 0)
                    count = (GCALL0(0x0600A0B8) & 3) + 1;
                else
                    count = LDU8(LD32(ACTOR_PTR) + 14);
            }
            GCALL3(0x06020174, arg, 8, count);
            GCALL0(0x060210E8);
            return LDU8(0x060D849C + LDU8(LD32(ACTOR_PTR) + 6) * 38 + 7);
        }
        next = LDU8(LD32(ACTOR_PTR) + 7);
    }
}

int f060204A2(int tag)
{
    int i = 0;

    do {
        if (LD16(REC(i) + 22) != 0 && LD8(REC(i) + 9) == 0 && LDU16(REC(i) + 20) == AGET(w4)
            && !(LDU8(REC(i) + 4) & 128)) {
            if (tag == 0) {
                ST8(REC(i) + 4, LDU8(REC(i) + 4) | 16);
            } else if (LDU16(0x060EE8B0 + GCALL1(0x0600CA6A, AGET(w0)) * 2) & 0x1000) {
                if ((AGET(w10) & 4) || i == AGET(b15))
                    return AGET(b15);
            }
        }
    } while (AGAIN(++i < 50));
    return 50;
}

int f06020DB4(int id)
{
    int result = 0;
    int next = LDU8(0x060D849C + 7);
    gaddr a;

    for (;;) {
        a = 0x060D849C + next * 38;
        ST32(ACTOR_PTR, a);
        if (LD8(a + 7) == 0)
            return result;
        POLL();
        if (LDU8(a + 16) != 0 && LDU8(a + 16) != 255 && !(LDU16(a + 10) & 0x1FA) && LDU16(a + 4) == id) {
            GCALL0(0x0601E766);
            result = LDU8(0x060D849C + LDU8(LD32(ACTOR_PTR) + 6) * 38 + 7);
        }
        next = LDU8(LD32(ACTOR_PTR) + 7);
    }
}

int f06020EE4(int id)
{
    int next = LDU8(0x060D849C + 7);
    gaddr a;

    for (;;) {
        a = 0x060D849C + next * 38;
        ST32(ACTOR_PTR, a);
        if (LD8(a + 7) == 0)
            return 0;
        POLL();
        if (LDU8(a + 16) != 0 && LDU8(a + 16) != 255 && (LDU16(a + 10) & 0x80) && LDU16(a + 4) == id)
            return LDU8(0x060D849C + LDU8(LD32(ACTOR_PTR) + 6) * 38 + 7);
        next = LDU8(LD32(ACTOR_PTR) + 7);
    }
}

int f06020F50(int n)
{
    if ((LDU16(0x060EC8B0 + n * 2) & 7) == 5)
        return 0;
    return HELPER((LDU16(0x060F08B0 + n * 2) & 0xFF00) >> 8);
}

unsigned char f06020F7C(int cell)
{
    return LD8(0x060DFA15 + GCALL1(0x06020F50, cell));
}

int f06020F8C(int cell)
{
    int v = GCALL1(0x06020F50, cell);

    if (v)
        v = (unsigned char)LD8(0x060DFB15 + v);
    return v;
}

int f06020FCC(int cell)
{
    int v = GCALL1(0x06020F50, cell);

    if (!v)
        return -1;
    return (unsigned char)LD8(0x060DFA95 + v);
}

int f06020FE8(int cell)
{
    int v = GCALL1(0x06020FCC, cell);

    if (v >= 0 && (LD8(0x060D5F34 + v * 124) & 8))
        v |= 128;
    return v;
}

void f0602109C(int bits)
{
    if (AGET(b15) < LDU8(0x060C063D))
        ASET(b35, AGET(b35) | bits);
}

void f060210B6(void)
{
    int cell = AGET(w4);

    ST16(FLAGS_AT(cell), LD16(FLAGS_AT(cell)) | 32);
}

void f060210E8(void)
{
    int cell = AGET(w4);

    ST16(FLAGS_AT(cell), LD16(FLAGS_AT(cell)) & 0xFFDF);
}

void f06021102(void)
{
    if ((AGET(w8) & 1) || ((AGET(w10) & 1) && AGET(b24) == 4))
        ASET(b36, 14);
    else if (AGET(b16) <= 111)
        ASET(b36, ((111 - AGET(b16)) >> 3) + 1);
    else if (AGET(b16) != 255)
        ASET(b36, 1);
    else
        ASET(b36, 15);
}

void f0602116A(int i)
{
    ST16(0x060EE8B0 + i * 2, LD16(0x060EE8B0 + i * 2) | 0xF00);
}

void f06021190(int from, unsigned int limit, int pos, unsigned int depth)
{
    gaddr actor = LD32(0x060D8C08);
    unsigned int level = LDU8(actor + 36) << 8;
    gaddr cell;
    gaddr owner;
    unsigned int found;
    int dir;
    int off;
    int cur;
    unsigned int n;
    int flags;

    if (depth == 0) {
        cell = 0x060EC8B0 + pos * 2;
        owner = 0x060EE8B0 + pos * 2;
        if (LDU16(cell) & 0x4290)
            return;
        found = LDU16(owner) & 0xF00;
        if (found >= level) {
            level = found;
            ST8(actor + 36, found >> 8);
        }
        GCALL4(0x060212E6, cell, owner, level, actor);
        depth = 1;
    }
    dir = 1;
    do {
        if (dir != from && dir != LDU8(0x060B47FA + from)) {
            off = LD16(0x060B47F0 + dir * 2);
            cur = pos;
            n = depth;
            if (n <= limit) {
                for (;;) {
                    found = (unsigned short)GCALL1(0x0600C9C0, off + cur) * 2;
                    cell = 0x060EC8B0 + found;
                    owner = 0x060EE8B0 + found;
                    flags = LDU16(cell);
                    if (!(flags & 0x4080) || ((flags & 0x80) && (flags & 8))) {
                        GCALL4(0x060212E6, cell, owner, level, actor);
                        flags = LDU16(cell);
                        if ((LDU16(0x060DF978) & flags) || (flags & 32))
                            break;
                        cur = GCALL1(0x0600C9C0, off + cur) & 0xFFFF;
                        n++;
                        if (n > limit)
                            break;
                        POLL();
                    } else {
                        if ((LDU16(LD32(0x060D8C08) + 8) & 16) || (LDU16(cell) & 0x2000)) {
                            if (n > depth)
                                GCALL4(0x06021190, dir, limit, cur, n);
                        }
                        break;
                    }
                }
            }
        }
        dir++;
    } while (AGAIN(dir < 5));
}

void f060212E6(gaddr src, gaddr dst, int level)
{
    if ((LDU16(dst) & 0xF00) < (unsigned)level)
        ST16(dst, (LDU16(dst) & 0xF0FF) | level);
    if ((unsigned char)LD8(0x060C029C) == 8) {
        if (LDU16(dst) & 0x4000) {
            if (AGET(b35) & 1)
                GCALL2(0x060276D0, 2, 1);
            if (AGET(b35) & 2)
                GCALL2(0x060276D0, 3, 1);
            if ((AGET(b35) & 32) && level == 0xF00 && (unsigned)(signed char)AGET(b15) < (unsigned)LD8(BOMBER_COUNT))
                GCALL2(0x060276D0, 13, 1);
        }
        if ((AGET(b35) & 64) && level == 0xF00) {
            if ((LDU16(src) & 80) || (LDU16(dst) & 0x4000))
                ASET(b35, AGET(b35) & ~64);
        }
    }
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

int f06021588(int i)
{
    return GJUMP1(0x060215A2, LDU8(0x060DFA15 + i));
}

unsigned char f060215A2(int code)
{
    unsigned char n = (LD8(0x060DFB95) + 1) & 127;

    if (!n)
        n = 1;
    ST8(0x060DFB95, n);
    ST8(0x060DFA15 + n, code);
    ST8(0x060DFA95 + n, AGET(b15));
    ST8(0x060DFB15 + n, LD8(0x060DF977));
    return n;
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

void f0602168C(int points, int flags)
{
    if (flags & 1)
        GCALL2(0x06021604, points, 0);
    if (flags & 2)
        GCALL2(0x06021604, points, 1);
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

void f060217FC(void)
{
    int i = 0;

    do {
        GCALL1(0x060217E4, i);
        i++;
    } while (AGAIN(i <= 75));
    ST16(0x060DFDFE, 0);
    ST16(0x060DFDF6, 0);
}

void f06021888(gaddr ids)
{
    int i = 1;
    gaddr rec;
    gaddr flags;
    gaddr owner;
    int x;
    int y;
    int cell;

    while (LD8(ids) != 0) {
        POLL();
        if (LDU8(ids) != 26 || (LDU8(0x060C0682) & 16)) {
            rec = 0x060DFB96 + i * 8;
            while (LD8(rec + 5) == 0) {
                POLL();
                x = LDU16(0x060D7E7C) + GCALL1(0x0600A0EC, LDU16(0x060D7E80) - LDU16(0x060D7E7C));
                y = LDU16(0x060D7E7E);
                y = GCALL1(0x0600A0EC, LDU16(0x060D7E82) - y) + LDU16(0x060D7E7E);
                cell = (unsigned short)GCALL2(0x0600C950, x, y) * 2;
                flags = 0x060EC8B0 + cell;
                owner = 0x060F08B0 + cell;
                while (LD8(rec + 5) == 0 && (unsigned int)x < LDU16(0x060D7E80)) {
                    POLL();
                    if ((LDU16(flags) & 16) && (LDU16(owner) & 255) == 0) {
                        ST16(owner, LD16(owner) | i);
                        ST8(rec + 5, LD8(ids));
                    }
                    x++;
                    flags += 2;
                    owner += 2;
                }
            }
        }
        ids++;
        i++;
    }
}

int f06021980(signed char kind, int x, int y, int bits)
{
    int cell = GCALL2(0x0600C950, x, y) * 2;

    ST16(0x060EC8B0 + cell, LD16(0x060EC8B0 + cell) | 16);
    ST16(0x060F08B0 + cell, LD16(0x060F08B0 + cell) | bits);
    ST8(0x060DFB9B + bits * 8, kind);
    return kind;
}

void f060219C6(gaddr p)
{
    int n = 0;
    int cell;
    unsigned char kind;

    GCALL0(0x0602769A);
    while (LD8(p)) {
        cell = GCALL2(0x0600C950, (unsigned char)LD8(p + 1), (unsigned char)LD8(p + 2));
        if (LDU16(0x060EC8B0 + cell * 2) & 16) {
            ST16(0x060F08B0 + cell * 2, LD16(0x060F08B0 + cell * 2) | (n + 1));
            kind = LD8(p);
            ST8(0x060DFB9E + n * 8 + 5, kind);
            if (kind == 1)
                GCALL2(0x060276D0, 8, 1);
            else if (kind == 2)
                GCALL2(0x060276D0, 7, 1);
            else if (kind == 3)
                GCALL2(0x060276D0, 9, 1);
            n++;
        }
        p += 3;
        POLL();
    }
}

void f06021A56(int bits)
{
    ST16(LD32(CURRENT) + 64, (LDU16(LD32(CURRENT) + 64) & 0xFFE0) | bits);
    ST16(LD32(CURRENT) + 80, LD16(LD32(CURRENT) + 80) | bits);
}

void f06021A76(int bits)
{
    ST16(LD32(CURRENT) + 64, LD16(LD32(CURRENT) + 64) | bits);
    ST16(LD32(CURRENT) + 80, LD16(LD32(CURRENT) + 80) | bits);
}

void f06021E1A(void)
{
    gaddr cur;

    if (LD16(0x060DFDFE))
        return;
    cur = LD32(CURRENT);
    ST16(cur + 42, LD16(0x060B48E4 + GCALL1(0x0600A0EC, 10) * 2));
    ST16(LD32(CURRENT) + 44, 0x258);
    if (LDU16(LD32(CURRENT) + 42) & 64) {
        if (!GCALL0(0x0601741C))
            ST16(LD32(CURRENT) + 42, 2);
    }
}

unsigned char f06021F82(int i)
{
    return LD8(0x060DFB9B + (unsigned char)LDU16(0x060F08B0 + i * 2) * 8);
}

void f06021F9A(int n)
{
    gaddr q = 0x060DFB96 + n * 8;
    gaddr flags;

    if (LD16(q) != 0) {
        flags = 0x060EC8B0 + GCALL1(0x0600CA6A, LDU16(q)) * 2;
        ST16(flags, LD16(flags) & 0xFFBF);
        GCALL1(0x060692DC, LDU16(q));
    }
    if (LD16(q + 2) != 0)
        GCALL1(0x060692DC, LDU16(q + 2));
    GCALL1(0x060217E4, n);
}

void f06022044(int cell)
{
    int tag;

    GCALL1(0x06022B0A, cell);
    ST16(0x060EC8B0 + cell * 2, LD16(0x060EC8B0 + cell * 2) & 0xFFBF);
    tag = LDU16(0x060F08B0 + cell * 2) & 255;
    if (tag)
        GCALL1(0x06021F9A, tag);
    ST16(0x060F08B0 + cell * 2, LD16(0x060F08B0 + cell * 2) & 0xFF00);
}

int f060222D8(int kind, int cell)
{
    int slot = LDU16(0x060F08B0 + (cell & 0xFFFF) * 2) & 255;
    gaddr rec;
    gaddr flags;
    int made;

    if (slot == 0) {
        slot = 1;
        while ((unsigned int)slot <= 75 && LD8(0x060DFB9B + slot * 8) != 0) {
            POLL();
            slot++;
        }
        if ((unsigned int)slot > 75)
            slot = 0;
    }
    if (slot == 0 || (kind & 0xFFFF) == 0)
        return slot;
    rec = 0x060DFB96 + slot * 8;
    ST32(0x060D7EA0, LD32(0x060D7EA4));
    ST32(0x060D7E98, LD32(0x060DF988));
    GCALL2(0x0600C7BE, 191 + kind, cell);
    flags = 0x060EC8B0 + (cell & 0xFFFF) * 2;
    ST16(flags, LD16(flags) | 64);
    GCALL2(0x06008A6A, 8, 0);
    made = GCALL1(0x060691DA, 100);
    ST16(rec, made);
    if ((made & 0xFFFF) == 0)
        return slot;
    if ((kind & 0xFFFF) == 21)
        ST16(OBJ(LDU16(rec)) + 46, 0);
    else
        ST16(OBJ(LDU16(rec)) + 46, LDU8(0x060C029C) != 17 ? 0x310 : 0);
    GCALL2(0x060149FC, cell & 0xFFFF, LDU16(rec));
    GCALL2(0x0600D148, LD16(rec), cell);
    GCALL1(0x0606948A, LD16(rec));
    ST8(rec + 5, kind);
    made = GCALL1(0x060691DA, LDU16(0x060DF984));
    ST16(rec + 2, made);
    if ((made & 0xFFFF) != 0) {
        ST16(OBJ(LDU16(rec + 2)) + 46, LD16(OBJ(LDU16(rec)) + 46));
        GCALL2(0x0600D148, LD16(rec + 2), cell);
    }
    return slot;
}

void f0602251C(gaddr p)
{
    gaddr a = OBJ(LDU16(p));
    gaddr b = OBJ(LDU16(p + 2));
    int k;
    int dx;

    GCALL2(0x0606AAC8, a, 1);
    k = (unsigned char)LD8(p + 7) * 3;
    dx = LD8(0x060B4920 + k);
    ST16(a + 20, LD16(a + 16) + dx);
    ST16(a + 24, LD16(a + 16) - dx + 15);
    ST16(a + 22, LD16(a + 18) + LD8(0x060B4920 + k + 1));
    ST16(a + 26, LD16(a + 18) + LD8(0x060B4920 + k + 2));
    ST16(b + 20, LD16(b + 16) + dx);
    ST16(b + 24, LD16(b + 16) - dx + 15);
    ST16(b + 22, LD16(b + 18));
    ST16(b + 26, LD16(b + 18) + 7);
    ST8(p + 7, LD8(p + 7) + 1);
    if ((unsigned char)LD8(p + 7) == 32) {
        ST8(p + 6, 0);
        ST8(p + 7, 0);
        ST8(p + 4, 2);
        GJUMP2(0x0606AAC8, a, 0);
    }
}

void f060225D2(gaddr p)
{
    gaddr a;
    gaddr step;

    if ((unsigned char)LD8(p + 5) == 21)
        return;
    a = OBJ(LDU16(p));
    if (LD8(p + 6)) {
        int dx, dy;

        step = 0x060B4980 + (unsigned char)LD8(p + 6);
        ST8(p + 6, LD8(p + 6) + 2);
        GCALL2(0x0606AAC8, a, 2);
        dx = LD8(step);
        dy = LD8(step + 1);
        ST16(a + 20, LD16(a + 16) + dx);
        ST16(a + 22, LD16(a + 18) + dy);
        ST16(a + 24, LD16(a + 16) - dx + 15);
        ST16(a + 26, LD16(a + 18) - dy);
        ST16(a + 28, LD16(a + 16) - dx + 15);
        ST16(a + 30, LD16(a + 18) - dy + 15);
        ST16(a + 32, LD16(a + 16) + dx);
        ST16(a + 34, LD16(a + 18) + dy + 15);
        if ((unsigned char)LD8(p + 6) > 30) {
            ST8(p + 6, 0);
            GCALL2(0x0606AAC8, a, 0);
        }
    }
    ST8(p + 7, LD8(p + 7) + 1);
    if (!LD8(p + 7))
        ST8(p + 6, 2);
}

void f06022B0A(short cell)
{
    GCALL0(0x0600C434);
    GJUMP2(0x0600C7BE, LD16(LD32(0x060D7E94) + (unsigned short)cell * 2), cell);
}

void f06022C9C(int count)
{
    gaddr rec = 0x060D5F30;
    gaddr cell;
    gaddr p;
    int i = 0;
    int j;
    int radius = 4;
    unsigned int x;
    unsigned int y;

    do {
        if (LD16(rec + 22) != 0) {
            cell = 0x060EC8B0 + LDU16(rec + 20) * 2;
            ST16(cell, LD16(cell) | 0x800);
            if (LDU16(0x060EE8B0 + LDU16(rec + 20) * 2) & 0x1000) {
                p = 0x060B49BE + LDU16(rec + 58) * 16;
                j = 0;
                do {
                    j++;
                    ST16(cell + LD16(p) * 2, LD16(cell + LD16(p) * 2) | 0x800);
                    p += 2;
                } while (AGAIN(j < 8));
            }
        }
        i++;
        rec += 124;
    } while (AGAIN(i < 50));
    ST16(0x060DFE00, 0);
    while (count != 0) {
        if (radius >= 16)
            break;
        POLL();
        y = LDU16(0x060D7E7E);
        while (y < LDU16(0x060D7E82)) {
            POLL();
            cell = 0x060EC8B0 + (unsigned short)GCALL2(0x0600C950, LDU16(0x060D7E7C), y) * 2;
            x = LDU16(0x060D7E7C);
            while (x < LDU16(0x060D7E80)) {
                POLL();
                if (count != 0 && (GCALL0(0x0600A0B8) & 15) < radius && !(LDU16(cell) & 0x4C90)) {
                    ST16(cell, LD16(cell) | 16);
                    count--;
                    ST16(0x060DFE00, LD16(0x060DFE00) + 1);
                }
                x++;
                cell += 2;
            }
            y++;
        }
        radius++;
    }
}

void f06022DC8(void)
{
    TSET(fn, 0);
    TSET(h6, 1);
    TSET(h4, 0);
    TSET(h8, 0);
    TSET(h10, 0);
    TSET(h12, 0);
    TSET(h14, 0);
    TSET(h16, 0);
    TSET(h18, 0);
    TSET(h20, 0);
}

void f06022DFA(void)
{
    int i = 0;

    ST32(TASK_PTR, SLOTS);
    do {
        GCALL0(0x06022DC8);
        ST32(TASK_PTR, LD32(TASK_PTR) + 24);
        i++;
    } while (AGAIN(i < 33));
    ST16(0x060D7B46, 0);
    ST16(0x060D7B42, 0);
    ST16(0x060D7B40, 0);
}

void f06022EDA(int n)
{
    ST32(TASK_PTR, SLOT(n));
    if (TGET(h8)) {
        GCALL1(0x060692DC, TGET(h8));
        GCALL0(0x06022DC8);
        ST16(0x060D7B40, LD16(0x060D7B40) - 1);
    }
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

int f06022F1C(int n, int fn)
{
    REF(Task) t;

    ST32(TASK_PTR, SLOT(n));
    if (TGET(h8))
        GCALL1(0x06022EDA, n);
    t = TASK;
    SET(Task, t, h8, GCALL1(0x060691DA, 20));
    if (!GET(Task, t, h8))
        return -1;
    ST32(TASK_OBJ, OBJ(TGET(h8)));
    TSET(fn, fn);
    TSET(h6, 1);
    ST16(0x060D7B40, LD16(0x060D7B40) + 1);
    return n;
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

void f060231FA(void)
{
    GCALL1(0x0606948A, (short)TGET(h8));
    if (GCALL1(0x06023390, 4) == 0)
        return;
    if (LDU16(0x060C02AE) < 2) {
        ST16(0x060C02AE, 2);
        GJUMP2(0x0606AAC8, LD32(TASK_OBJ), 7);
        return;
    }
    switch (TGET(h14)) {
    case 0:
    case 2:
        TSET(h12, TGET(h12) - 1);
        if (TGET(h12) == 0)
            TSET(h14, TGET(h14) + 1);
        break;
    case 1:
        TSET(h12, TGET(h12) + 1);
        ST8(LD32(TASK_OBJ) + 78, HELPER(GCALL1(0x0609812C, LD32(0x060B9108 + (TGET(h12) & 255) * 4)) >> 11));
        if (TGET(h12) > 64)
            TSET(h14, TGET(h14) + 1);
        break;
    case 3:
        TSET(h16, 0x100);
        TSET(h14, TGET(h14) + 1);
        TSET(h12, 64);
        break;
    case 4:
        TSET(h12, TGET(h12) + 10);
        TSET(h16, TGET(h16) - 1);
        ST8(LD32(TASK_OBJ) + 78,
            HELPER((signed char)HELPER(GCALL1(0x0609812C, LD32(0x060B9108 + (TGET(h12) & 255) * 4)) >> 11) * TGET(h16) >> 8));
        if (TGET(h16) == 0)
            TSET(h14, TGET(h14) + 1);
        break;
    case 5:
        TSET(h14, 0);
        TSET(h12, 0x200);
        ST8(LD32(TASK_OBJ) + 78, 0);
        break;
    }
}

void f0602336E(void)
{
    if (LDU16(0x060C02AE) >= 2 && GCALL1(0x06023390, 16))
        ST16(0x060C02AE, 128);
}

int f06023390(int amount)
{
    if (LDU16(0x060D7E68) & 64) {
        GCALL0(0x06022F14);
        return 1;
    }
    if (TGET(h10) >= 0x100)
        return 1;
    TSET(h10, TGET(h10) + amount);
    ST16(LD32(TASK_OBJ) + 68, TGET(h10));
    return 0;
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

void f0602363C(void)
{
    gaddr cur = LD32(CURRENT);

    if (LD8(cur + 4) & 128)
        return;
    GJUMP1(0x0600D16A, LDU16(cur + 22));
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

void f06023774(void)
{
    GJUMP4(0x06015012, 5, 6, 0x100, 0x00010000);
}

void f06023780(void)
{
    GJUMP4(0x06015012, 1, 2, 0, 0x00040000);
}

int f060238F0(void)
{
    if (LDU16(0x060C067C) < (unsigned char)LD8(BOMBER_COUNT)) {
        TSET(h10, 120);
        ST16(LD32(TASK_OBJ) + 62, 0x400);
    }
    if (TGET(h10)) {
        int left = (short)TGET(h10) - 1;

        TSET(h10, left);
        return left;
    }
    if (LDU16(LD32(TASK_OBJ) + 62) > 0x100)
        ST16(LD32(TASK_OBJ) + 62, 0x100);
    return 62;
}

int f06023B04(void)
{
    if (!LD16(0x060D7B44))
        GCALL1(0x0600996A, 245);
    TSET(h4, 240);
    return 240;
}

int f06023BC2(void)
{
    return GJUMP4(0x06025564, 10, 5, 3, 0);
}

int f06023D8E(void)
{
    gaddr obj = LD32(TASK_OBJ);
    int pos = LD16(obj + 18);
    int dist;

    if (pos > 0x100)
        pos = 0x100;
    dist = pos <= 128 ? 128 - pos : pos - 128;
    ST16(obj + 70, dist * 4 + 64);
    ST16(obj + 68, dist * 4 + 64);
    return 68;
}

void f06023E2C(void)
{
    if (LD16(LD32(TASK_OBJ) + 18) < -32)
        ST16(LD32(TASK_OBJ) + 18, 0x200);
    if (LD16(LD32(TASK_OBJ) + 18) > 0x200)
        ST16(LD32(TASK_OBJ) + 18, -32);
}

void f06023E50(int n)
{
    GJUMP1(0x0600A32A, LD8(0x060B4AF0 + n * 4 + (LDU16(0x060C067E) & 3)));
}

int f06023E72(void)
{
    gaddr obj = LD32(TASK_OBJ);

    if (LD16(obj + 18) < 16)
        ST16(obj + 18, LD16(obj + 18) + 224);
    obj = LD32(TASK_OBJ);
    if (LD16(obj + 18) > 240)
        ST16(obj + 18, LD16(obj + 18) - 224);
    GCALL1(0x06023E50, 0);
    return GJUMP0(0x06023D8E);
}

int f06023EA4(void)
{
    GCALL0(0x06023E2C);
    POLL();
    return GJUMP1(0x0600A32A, LD8(0x060B4AF4 + (LDU16(0x060C067E) & 3)) & 255);
}

int f06023EB0(void)
{
    GCALL0(0x06023E2C);
    POLL();
    return GJUMP1(0x0600A32A, LD8(0x060B4AF8 + (LDU16(0x060C067E) & 3)) & 255);
}

void f060240E0(void)
{
    GCALL4(0x06068E10, 2, 0x25E20000, 102, 1);
    GCALL4(0x06068E10, 3, 0x25E20000, 2, 1);
    GCALL1(0x060092D4, 9);
    GJUMP1(0x060092D4, 10);
}

void f06024108(void)
{
    POLL();
    GJUMP0(0x060240E0);
}

void f0602410C(void)
{
    GCALL0(0x060240E0);
    GCALL4(0x06025564, 10, 6, 8, 176);
    GJUMP4(0x0602561E, 0x4E8, 0x4F4, 0x674, 0x668);
}

void f06024130(void)
{
    GCALL0(0x060240E0);
    GJUMP0(0x060266BC);
}

void f0602413C(void)
{
    GCALL0(0x060240E0);
    GCALL4(0x06025564, 10, 6, 8, 176);
    GJUMP0(0x060266BC);
}

void f06024168(void)
{
    GJUMP4(0x06015012, 4, 2, 0x900, 0x00014000);
}

int f06024752(unsigned int cell)
{
    unsigned int col = cell >> 6;

    if ((LDU16(0x060EE8B0 + cell * 2) & 255) == 13)
        return 1;
    return col <= LDU16(0x060D7E7E) + 4u || col >= LDU16(0x060D7E82) - 2u;
}

int f060254C0(void)
{
    gaddr step = 0x060B4D98 + TGET(h12) * 2;
    gaddr cell;

    cell = 0x060EC8B0 + ((TGET(h10) - LD16(step)) << 1);
    ST16(cell, LD16(cell) | 0x4000);
    cell = 0x060EC8B0 + ((TGET(h10) + LD16(step)) << 1);
    ST16(cell, LD16(cell) & 0xBFFF);
    return TGET(h10) - LD16(step);
}

int f0602561E(short a, short b, short c, short d)
{
    ST16(0x060C02C2, a);
    ST16(0x060C02C4, b);
    ST16(0x060C02C6, c);
    ST16(0x060C02C8, d);
    return 0x060C02C8;
}

void f0602566C(int shift)
{
    int i;
    gaddr cell;

    GCALL0(0x0600C434);
    GCALL2(0x0600C7BE, TGET(h14) + shift, TGET(h12));
    if (!shift)
        return;
    if (LD16(0x060C02C2)) {
        i = 0;
        do {
            cell = 0x060EE8B0 + LDU16(0x060C02C2 + i * 2) * 2;
            ST16(cell, ((i - (LDU8(0x060C02C0) >> 1)) & 3) + 5 | (LD16(cell) & 0xFF00));
        } while (AGAIN(++i < 4));
    }
    GJUMP1(0x0600996A, 250);
}

int f060256EC(void)
{
    int cell = TGET(h12) * 2;

    if (LDU16(0x060EC8B0 + cell) & 32)
        return 1;
    return (LDU16(0x060EE8B0 + cell) & 0x3000) != 0;
}

void f06025716(void)
{
    if (GCALL0(0x060256EC) == 0)
        return;
    ST8(0x060C02C0, LD8(0x060C02C0) ^ 2);
    GCALL1(0x0602566C, 1);
    GCALL2(0x060093E6, TGET(h10), LDU8(0x060C02C0) >> 1);
    TSET(fn, 0x0602574E);
}

int f0602574E(void)
{
    int blocked = GCALL0(0x060256EC);

    if (!blocked) {
        blocked = GCALL1(0x0602566C, 0);
        ST32(LD32(TASK_PTR), 0x06025716);
    }
    return blocked;
}

int f06025946(void)
{
    int found = 0, count = 0;
    int i;

    ST32(CURRENT, REC(0));
    for (i = 0; i < LDU8(BOMBER_COUNT); i++) {
        POLL();
        if (LDU16(LD32(CURRENT) + 20) == TGET(h10) && LD16(LD32(CURRENT) + 46) == 0 && !(LDU8(LD32(CURRENT) + 4) & 128)) {
            found = i;
            count++;
        }
        ST32(CURRENT, LD32(CURRENT) + 124);
    }
    if (count != 1)
        return 0;
    if (TGET(h18) != 255 && TGET(h18) != found)
        return 0;
    if (LD16(REC(found) + 36) == 0)
        return found + 1;
    i = LDU8(BOMBER_COUNT);
    ST32(CURRENT, REC(i));
    while (i < LDU8(BOMBER_COUNT) + 8) {
        POLL();
        if (LDU16(LD32(CURRENT) + 20) == TGET(h10) && !(LDU8(LD32(CURRENT) + 4) & 128)) {
            int owner = LDU16(LD32(CURRENT) + 36);

            if (owner == 255 || owner != found)
                return 0;
        }
        i++;
        ST32(CURRENT, LD32(CURRENT) + 124);
    }
    return found + 1;
}

int f06025E3E(void)
{
    int flags;

    TSET(h10, TGET(h10) + 1);
    ST16(0x060DF97C, 0);
    GCALL1(0x0600AC90, 32);
    if (TGET(h10) >= 0x258) {
        TSET(h10, 0);
        TSET(fn, 0x06025E7E);
        GCALL1(0x0600996A, 246);
    }
    flags = LDU16(0x060D7E68);
    if (!(flags & 64))
        return flags;
    ST16(0x060DF97C, 0);
    GCALL1(0x0600AC90, 32);
    GCALL2(0x0600A8F4, 32, 0x2000);
    return GJUMP0(0x06022F14);
}

void f06025FC0(int shift)
{
    GCALL0(0x0600C434);
    GJUMP2(0x0600C7BE, LD16(0x060B4DCC + TGET(h12) * 2) + shift, TGET(h14));
}

int f06025FEE(void)
{
    unsigned int step = LD8(0x060C02A1) & 255;
    int n = TGET(h14) * 2;
    unsigned int flags;

    if (step != 0) {
        if (step != TGET(h10)) {
            POLL();
            GCALL0(0x0600C434);
            return GJUMP2(0x0600C7BE, LD16(0x060B4DCC + TGET(h12) * 2), (short)TGET(h14));
        }
        flags = LDU16(0x060EC8B0 + n);
        if (flags & 32)
            return flags;
        if (LDU16(0x060EE8B0 + n) & 0x3000)
            return 0x060EE8B0;
        ST8(0x060C02A1, 0);
        return 0;
    }
    flags = LDU16(0x060EC8B0 + n);
    if (!(flags & 32) && !(LDU16(0x060EE8B0 + n) & 0x3000))
        return 0x060EE8B0;
    ST16(0x060C067E, TGET(h12) | (LDU16(0x060C067E) & 0xFFFC));
    if ((LDU16(0x060C067E) & 3) == 3)
        ST16(0x060C067E, LD16(0x060C067E) | 4);
    else
        ST16(0x060C067E, LD16(0x060C067E) & 0xFFFB);
    ST8(0x060C02A1, TGET(h10));
    GCALL1(0x06025FC0, 1);
    return GJUMP1(0x0600996A, LD32(0x060B4DD4 + TGET(h12) * 4));
}

void f060260F8(int base, short a, short b, short c)
{
    FRAME(sp, 52);
    int arg5 = LD32(sp);
    gaddr list = LD32(0x060C02CC);
    int i = 0;

    while (LD16(list) != 0) {
        gaddr obj, flags;
        gaddr p;

        POLL();
        GCALL2(0x06022F1C, base + i, arg5);
        TSET(h10, base);
        TSET(h12, 0);
        GCALL0(0x0600BD74);
        GCALL3(0x0600D0E4, LD16(TASK + 8), LD16(list) + LD16(0x060D7EB4), LD16(list + 2) + LD16(0x060D7EB6));
        obj = LD32(TASK_OBJ);
        ST16(obj + 22, a);
        ST16(obj + 26, b);
        ST16(obj + 30, c);
        flags = 0x060EC8B0 + GCALL1(0x0600CA6A, TGET(h8)) * 2;
        p = 0x060B47F0;
        do {
            int off = LD16(p) * 2;

            p += 2;
            ST16(flags + off, LD16(flags + off) | 0x800);
        } while (AGAIN(p < 0x060B47FA));
        i++;
        list += 4;
        ST16(0x060EE8B0 + LDU16(0x060D7E8C) * 2, LD16(0x060EE8B0 + LDU16(0x060D7E8C) * 2) | 16);
    }
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

void f060269A4(void)
{
    GCALL1(0x0601755E, LDU16(LD32(CURRENT) + 44) << 2);
    GCALL0(0x06026AD4);
    if (LD16(LD32(CURRENT) + 66))
        return;
    GJUMP1(0x060144F4, 0x060269D4);
}

int f06026C08(int pad)
{
    int dir = 0;
    int step = LDU16(LD32(CURRENT) + 44);

    if (LDU16(0x060C0684) & LDU16(0x060BF5E0))
        step <<= 1;
    if (pad & 0x8000) {
        if ((MY == LIM_UP || MY == LIM_DOWN) && MX < LIM_RIGHT) {
            SET(Mover, MOVER, x, MX + step);
            dir = 1;
            if (MX >= LIM_RIGHT)
                SET(Mover, MOVER, x, LIM_RIGHT);
        }
    }
    if ((pad & 0x4000) && !dir) {
        if ((MY == LIM_UP || MY == LIM_DOWN) && MX > LIM_LEFT) {
            SET(Mover, MOVER, x, MX - step);
            dir = 3;
            if (!(MX > LIM_LEFT))
                SET(Mover, MOVER, x, LIM_LEFT);
        }
    }
    if ((pad & 0x2000) && !dir) {
        if ((MX == LIM_RIGHT || MX == LIM_LEFT) && MY < LIM_DOWN) {
            SET(Mover, MOVER, y, MY + step);
            dir = 2;
            if (MY >= LIM_DOWN)
                SET(Mover, MOVER, y, LIM_DOWN);
        }
    }
    if ((pad & 0x1000) && !dir) {
        if ((MX == LIM_RIGHT || MX == LIM_LEFT) && MY > LIM_UP) {
            SET(Mover, MOVER, y, MY - step);
            dir = 4;
            if (!(MY > LIM_UP))
                SET(Mover, MOVER, y, LIM_UP);
        }
    }
    return dir;
}

void f06026D90(void)
{
    int dir;

    if (LD16(LD32(CURRENT) + 58))
        return;
    dir = GCALL1(0x06026C08, LDU16(0x060C0684));
    if (!dir && (LDU16(0x060C0684) & 0xF000)) {
        dir = GCALL1(0x06026C08, LDU16(0x060B4800 + LDU16(LD32(CURRENT) + 50) * 2));
        if (!dir)
            dir = GCALL1(0x06026C08, LDU16(0x060B4EA0 + LDU16(LD32(CURRENT) + 50) * 2) & LDU16(LD32(CURRENT) + 18));
    }
    if (dir)
        ST16(LD32(CURRENT) + 50, dir);
    ST16(LD32(CURRENT) + 16, dir);
}

void f06026E04(int enable)
{
    gaddr cur;

    if (!enable)
        return;
    cur = LD32(CURRENT);
    if (MY > LIM_UP) {
        if (MY < LIM_DOWN)
            ST8(cur + 6, MX < LIM_RIGHT ? 1 : 3);
        else
            ST8(cur + 6, 4);
    } else {
        ST8(cur + 6, 2);
    }
    if (!(MY > LIM_UP)) {
        if (MX > LIM_LEFT)
            ST16(LD32(CURRENT) + 18, MX < LIM_RIGHT ? 0xC000 : 0x6000);
        else
            ST16(LD32(CURRENT) + 18, 0xA000);
    }
    if (MY >= LIM_DOWN) {
        if (MX > LIM_LEFT)
            ST16(LD32(CURRENT) + 18, MX < LIM_RIGHT ? 0xC000 : 0x5000);
        else
            ST16(LD32(CURRENT) + 18, 0x9000);
    }
    if (MX >= LIM_RIGHT) {
        if (MY > LIM_UP)
            ST16(LD32(CURRENT) + 18, MY < LIM_DOWN ? 0x3000 : 0x5000);
        else
            ST16(LD32(CURRENT) + 18, 0x6000);
    }
    if (!(MX > LIM_LEFT)) {
        if (MY > LIM_UP)
            ST16(LD32(CURRENT) + 18, MY < LIM_DOWN ? 0x3000 : 0x9000);
        else
            ST16(LD32(CURRENT) + 18, 0xA000);
    }
}

void f06027270(void)
{
    int i;

    ST16(0x060D7E8A, 0x1000);
    ST16(0x060D7E88, 0x1000);
    ST16(0x060D7E8C, 0xFFFF);
    for (i = 0; (unsigned)i < (unsigned char)LD8(BOMBER_COUNT); i++) {
        gaddr bomber = 0x060D5F30 + i * 124;
        int me = LDU16(0x060C062C);
        gaddr obj;
        int x, y;

        if (i != me && !(LD8(bomber + 4) & 128)
            && (LD8(0x060C0640 + i) & 28) != (LD8(0x060C0640 + me) & 28)) {
            obj = OBJ(LDU16(bomber + 22));
            x = LDU16(0x060C090C);
            y = LDU16(0x060C090E);
            switch ((unsigned char)LD8(LD32(CURRENT) + 6)) {
            case 1:
                if (!(LD16(obj + 16) >= x))
                    GCALL1(0x06027206, i);
                break;
            case 2:
                if (!(LD16(obj + 18) >= y))
                    GCALL1(0x0602719C, i);
                break;
            case 3:
                if (LD16(obj + 16) >= x)
                    GCALL1(0x06027206, i);
                break;
            case 4:
                if (LD16(obj + 18) >= y)
                    GCALL1(0x0602719C, i);
                break;
            }
        }
        POLL();
    }
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

void f06027426(void)
{
    unsigned char mode;

    ST16(0x060D7E8E, 0);
    ST16(0x060D7E92, 1);
    if (!LD16(LD32(CURRENT) + 70)) {
        mode = LD8(0x060C0680);
        if (mode == 0 || (mode == 1 && !(GCALL0(0x0600A0B8) & 31))) {
            ST16(LD32(CURRENT) + 70, 1);
        } else {
            gaddr slot = LD32(CURRENT) + 70;

            ST16(slot, GCALL0(0x06027378));
        }
    }
    if (LDU16(0x060D7E8C) == 0xFFFF || LD16(LD32(CURRENT) + 70)) {
        int dir;

        if (!(LDU16(LD32(CURRENT) + 18) & LDU16(0x060B4800 + LDU16(LD32(CURRENT) + 50) * 2))) {
            ST16(LD32(CURRENT) + 70, 0);
            if (!LD16(LD32(CURRENT) + 50))
                dir = (LD16(0x060C0630) & 3) + 1;
            else
                dir = GCALL1(0x0600A4B0, LDU16(0x060B4EC0 + LDU16(LD32(CURRENT) + 50) * 2) & LDU16(LD32(CURRENT) + 18));
            ST16(0x060D7E8E, dir);
        } else {
            ST16(0x060D7E8E, LD16(LD32(CURRENT) + 50));
        }
        ST16(0x060D7E90, GCALL1(0x060273F4, ((GCALL0(0x0600A0B8) & 3) << 3) + 4));
    } else if (LD8(LD32(CURRENT) + 6) & 1) {
        int dy = LD16(0x060D7E8A);
        int dx = LD16(0x060D7E88);

        if (dy >= 8)
            ST16(0x060D7E8E, 4);
        else if (!(dy > -8))
            ST16(0x060D7E8E, 2);
        GCALL1(0x060273B6, ABS(dx));
        dy = LD16(0x060D7E8A);
        if (!(ABS(dy) >= 3))
            ST16(0x060D7E92, 0);
    } else {
        int dx = LD16(0x060D7E88);
        int dy = LD16(0x060D7E8A);

        if (dx >= 8)
            ST16(0x060D7E8E, 3);
        else if (!(dx > -8))
            ST16(0x060D7E8E, 1);
        GCALL1(0x060273B6, ABS(dy));
        dx = LD16(0x060D7E88);
        if (!(ABS(dx) >= 3))
            ST16(0x060D7E92, 0);
    }
}

void f060275E4(void)
{
    gaddr cur;

    GCALL0(0x06027270);
    GCALL0(0x06027426);
    ST16(0x060C0684, LD16(0x060B4800 + LDU16(0x060D7E8E) * 2));
    if (LD16(0x060D7E92) && LD8(0x060C0680))
        ST16(0x060C0684, LD16(0x060C0684) | LD16(0x060BF5E0));
    ST16(0x060C0688, LD16(0x060C0684));
    ST16(0x060C0686, LD16(0x060C0684));
    cur = LD32(CURRENT);
    ST16(cur + 46, LDU16(cur + 42) == 5 ? LD16(0x060D7E90) : 0);
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

/* Takes the share of `total` that *slot is, as a percentage, and replaces it with the second word of the
 * first pair in the table whose first word is above it. */
void f0602781C(gaddr slot, gaddr table, int total)
{
    int percent;

    if (!total)
        total = 1;
    if (!LD32(slot)) {
        ST32(slot, 0);
        return;
    }
    percent = DIVS(LD32(slot) * 100, total);
    while (percent >= LD32(table)) {
        POLL();
        table += 8;
    }
    ST32(slot, LD32(table + 4));
}

void f06027874(void)
{
    gaddr total = 0x060C0A98;
    gaddr src = 0x060C0A00;
    int i = 0;

    ST32(0x060C0A64, LD32(0x060C0A64) + LD32(0x060C0A18));
    ST32(0x060C0A40, LD32(0x060DF990));
    GCALL3(0x0602781C, 0x060C0A34, 0x060B4F78, LD32(0x060C0A40));
    GCALL3(0x0602781C, 0x060C0A48, 0x060B4FB8, 100);
    ST32(0x060C0A88, LD32(0x060C0A88) + LD32(0x060C0A3C));
    ST32(total, 0);
    do {
        switch (i) {
        case 6:
        case 12:
        case 14:
        case 15:
        case 16:
        case 17:
            break;
        default:
            ST32(total, LD32(total) + LD32(src));
        }
        i++;
        src += 4;
    } while (AGAIN(i < 19));
}

void f06027910(void)
{
    if ((unsigned char)LD8(0x060C029D)) {
        if (LD32(0x060C0A64))
            GCALL3(0x0602781C, 0x060C0A64, 0x060B4F30, (unsigned char)LD8(0x060C029D));
        else
            ST32(0x060C0A64, LD32(0x060B4F34));
        ST32(0x060C0A64, LD32(0x060C0A64) * (unsigned char)LD8(0x060C029D));
    } else {
        ST32(0x060C0A64, 0);
    }
    if ((unsigned char)LD8(0x060C029D) != 20) {
        ST32(0x060C0A7C, 0);
        return;
    }
    if (LD32(0x060C0A30) >= 11)
        ST32(0x060C0A30, 11);
    ST32(0x060C0A7C, LD32(0x060B4F00 + LD32(0x060C0A30) * 4));
    GJUMP2(0x060276D0, 14, 1);
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

int f060285EA(void)
{
    gaddr obj = OBJ(TGET(h10));

    ST16(obj + 68, LD16(obj + 68) + 16);
    ST16(obj + 70, LD16(obj + 70) + 16);
    if (LDU16(obj + 68) >= 0x600)
        ST8(0x060C02A0, 10);
    return 68;
}

int f060287C4(void)
{
    unsigned lane = TGET(h16);
    int left = LDU16(0x060B5010 + (lane & 3) * 4);
    gaddr row = 0x060B5010 + (lane >> 2) * 16 + 2;
    gaddr obj = LD32(TASK_OBJ);

    if (LD16(obj + 16) < left)
        return 0x100;
    return LD16(obj + 18) + 40 >= (int)LDU16(row) ? 0x200 : 0;
}

void f06028D98(void)
{
    int i, j;
    int a;

    if (LD8(0x060C02A4) != 0) {
        ST8(0x060C02A4, LD8(0x060C02A4) - 1);
        return;
    }
    i = 0;
    do {
        ST8(0x060DFB96 + (11 - i) * 8 + 5, MODU(i, 6));
        i++;
    } while (AGAIN(i < 12));
    if (LD8(0x060C029C) == 17)
        ST8(0x060DFB96 + 5, 6);
    for (i = 0; i < 12; i++) {
        j = GCALL1(0x0600A0EC, 12);
        if (i != 0 ? (j != 0 || LD8(0x060DFB9B + i * 8) != 0) : LD8(0x060DFB9B + j * 8) != 0) {
            a = LD8(0x060DFB96 + i * 8 + 5) & 255;
            ST8(0x060DFB96 + i * 8 + 5, LD8(0x060DFB96 + j * 8 + 5));
            ST8(0x060DFB96 + j * 8 + 5, a);
        }
        POLL();
    }
    ST8(0x060C02A4, (GCALL0(0x0600A0B8) & 127) + 1);
    ST8(0x060C02A3, 30);
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

void f06029718(int pad)
{
    int out = 0;

    if (pad & 4)
        out = 1;
    if (pad & 8)
        out |= 2;
    if (pad & 16)
        out |= 4;
    if (pad & 32)
        out |= 8;
    if (pad & 1)
        out |= 16;
    if (pad & 2)
        out |= 1;
    if (pad & 0x100)
        out |= 64;
    if (pad & 0x00080000)
        out |= 32;
    if (pad & 128)
        out |= 2;
    ST16(0x060FB8CA, out);
    ST16(0x25F80110, out);
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

void f06029ABC(int x, int y, int z)
{
    GCALL1(0x06029718, 0x13C);
    ST16(0x25F80114, x & 0x1FF);
    ST16(0x25F80116, y & 0x1FF);
    ST16(0x25F80118, z & 0x1FF);
}

void f06029AEE(void)
{
    POLL();
    ST16(0x060FB8CA, 0);
    ST16(0x25F80110, 0);
}

/* Clamps pos to 0..0x1FF, subtracts 256 and wraps to 9 bits. */
void f06029E0C(int flags, int pos)
{
    if (pos < 0)
        pos = 0;
    else if (pos > 0x1FF)
        pos = 0x1FF;
    pos = (pos - 256) & 0x1FF;
    GJUMP4(0x06029E2E, flags, pos, pos, pos);
}

void f06029E66(int a, int b)
{
    FRAME(sp, 28);
    gaddr ones = sp - 20;
    gaddr zeros = sp - 12;

    GCALL1(0x0602977C, a);
    GCALL1(0x060298F4, a);
    ST16(zeros + 4, 0);
    ST16(zeros + 2, 0);
    ST16(zeros, 0);
    ST16(ones + 4, -255);
    ST16(ones + 2, -255);
    ST16(ones, -255);
    GCALL5(0x0609BE8C, 0, 1, b, zeros, ones);
}

void f06029FB8(void)
{
    ST16(0x060EC450, 0);
    ST16(0x060FAA3A, 0);
    ST32(0x060FAA40, 0x00023000);
    ST32(0x060FAA44, 0x00024000);
    ST16(0x060EC452, 0);
}

void f0602A6D2(int mode)
{
    GCALL0(0x0602A750);
    ST8(0x060C0F82, mode == 4 ? 0 : 128);
    ST32(0x060C0F84, 0);
}

/* The fifth argument is on the stack. */
void f0602A6FA(short key, int a, int b, int c)
{
    FRAME(sp, 0);
    gaddr e = 0x060C0DF0;
    int i = 0;

    if (key < 0)
        return;
    do {
        if (LD16(e) == key || LD16(e) < 0)
            break;
        i++;
        e += 10;
    } while (AGAIN(i < 40));
    if (i < 40) {
        if (LD16(e) < 0)
            ST16(0x060C0F80, LD16(0x060C0F80) + 1);
        ST16(e, key);
        ST16(e + 2, a - 256);
        ST16(e + 4, b);
        ST16(e + 6, c);
        ST16(e + 8, LD16(sp + 2));
    }
    GJUMP0(0x0602A7F6);
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

void f0602A7F6(void)
{
    int n = LD16(0x060C0F80) - 1;
    gaddr last = 0x060C0DF0 + (short)(n * 10);
    gaddr low = 0x060C0DF0;
    short i = n;
    short j;
    gaddr high;
    int k;
    int t;

    while (i > 0) {
        POLL();
        j = i;
        high = last;
        if (j > 0) {
            do {
                if (LD16(low) > LD16(high)) {
                    for (k = 0; k < 10; k += 2) {
                        t = LD16(high + k);
                        ST16(high + k, LD16(low + k));
                        ST16(low + k, t);
                    }
                }
                j--;
                high -= 10;
            } while (AGAIN(j > 0));
        }
        i--;
        low += 10;
    }
}

int f0602A876(int dst)
{
    int arg = dst;
    int flip;
    unsigned char mode = LD8(0x060C0F82);

    if (mode == 0)
        dst = 0x25E46000;
    else if (mode == 1)
        dst = 0x25E4A000;
    else if (mode == 128)
        dst = 0x25E48000;
    else if (mode == 129)
        dst = 0x25E4C000;
    if (!arg)
        GCALL1(0x0602AA60, dst);
    else
        GCALL2(0x0602AB54, dst, arg);
    mode = LD8(0x060C0F82);
    if (mode == 0) {
        ST32(0x060FAA40, 0x00023000);
        ST32(0x060FAA10 + 52, 0);
        ST16(0x060FAA10 + 42, 14);
    } else if (mode == 1) {
        ST32(0x060FAA40, 0x00025000);
        ST32(0x060FAA10 + 52, 0);
        ST16(0x060FAA10 + 42, 14);
    } else if (mode == 128) {
        ST32(0x060FAA40, 0);
        ST32(0x060FAA10 + 52, 0x00024000);
        ST16(0x060FAA10 + 42, 0xE00);
    } else if (mode == 129) {
        ST32(0x060FAA40, 0);
        ST32(0x060FAA10 + 52, 0x00026000);
        ST16(0x060FAA10 + 42, 0xE00);
    }
    flip = LD8(0x060C0F82) ^ 1;
    ST8(0x060C0F82, flip);
    ST16(0x060BB8FC, 1);
    return flip;
}

void f0602A940(void)
{
    REF(Ramp) r = RAMP;
    REF(RampKey) k;

    if (!LD16(0x060C0FA8) || LD16(GET(Ramp, r, key))) {
        SET(Ramp, r, until, -1);
        SET(Ramp, r, x, 0x00010000);
        SET(Ramp, r, y, GET(Ramp, r, start));
        SET(Ramp, r, z, 0x00010000);
    } else {
        k = GET(Ramp, r, key);
        SET(Ramp, r, x, GET(RampKey, k, x) << 8);
        SET(Ramp, r, y, GCALL2(0x060980B4, GET(Ramp, r, start), GET(RampKey, k, ya) << 8) + (GET(RampKey, k, yb) << 16));
        SET(Ramp, r, z, GET(RampKey, k, z) << 8);
        SET(Ramp, r, left, GET(Ramp, r, left) - 1);
    }
}

void f0602A9D4(int now)
{
    gaddr key;
    short span;

    if (GET(Ramp, RAMP, left) == 0) {
        SET(Ramp, RAMP, until, 0x7FFF);
        SET(Ramp, RAMP, dx, 0);
        SET(Ramp, RAMP, dy, 0);
        SET(Ramp, RAMP, dz, 0);
        return;
    }
    key = GET(Ramp, RAMP, key) + 10;
    SET(Ramp, RAMP, key, key);
    SET(Ramp, RAMP, until, GET(RampKey, key, until));
    span = GET(RampKey, key, until) - now;
    SET(Ramp, RAMP, dx, DIVS((GET(RampKey, key, x) << 8) - GET(Ramp, RAMP, x), span));
    SET(Ramp, RAMP, dy,
        DIVS((GCALL2(0x060980B4, GET(Ramp, RAMP, start), GET(RampKey, key, ya) << 8)
              + (GET(RampKey, key, yb) << 16)) - GET(Ramp, RAMP, y), span));
    SET(Ramp, RAMP, dz, DIVS((GET(RampKey, key, z) << 8) - GET(Ramp, RAMP, z), span));
    SET(Ramp, RAMP, left, GET(Ramp, RAMP, left) - 1);
}

void f0602AA60(gaddr out)
{
    REF(Ramp) r = RAMP;
    int i = 0;
    int total = 0;
    int row;

    if (!(LD8(0x060C0F82) & 128))
        SET(Ramp, r, start, LD32(0x060FAA10));
    else
        SET(Ramp, r, start, LD32(0x060FAA10 + 16));
    SET(Ramp, r, left, LD16(0x060C0F80));
    SET(Ramp, r, key, 0x060C0DF0);
    GCALL0(0x0602A940);
    GCALL1(0x0602A9D4, 0);
    do {
        if (i == GET(Ramp, r, until))
            GCALL1(0x0602A9D4, i);
        row = GCALL2(0x060980C8, 0x00010000, GET(Ramp, r, x)) & 0x0007FF00;
        ST32(out, (GET(Ramp, r, y) & 0x07FFFF00) - row * 160 + 0x00A00000);
        out += 4;
        ST32(out, total & 0x07FFFF00);
        out += 4;
        ST32(out, row);
        out += 4;
        i++;
        total += GCALL2(0x060980C8, 0x00010000, GET(Ramp, r, z));
        SET(Ramp, r, x, GET(Ramp, r, x) + GET(Ramp, r, dx));
        SET(Ramp, r, y, GET(Ramp, r, y) + GET(Ramp, r, dy));
        SET(Ramp, r, z, GET(Ramp, r, z) + GET(Ramp, r, dz));
    } while (AGAIN(i < 0x100));
}

int f0602AB54(gaddr dst, int start)
{
    int rows = 0;
    int acc = 0;
    int skip, phase, row, step = 0;

    SET(Ramp, RAMP, start, LD32(0x060FAA10 + (LD8(0x060C0F82) & 128 ? 16 : 0)));
    SET(Ramp, RAMP, left, LD16(0x060C0F80));
    SET(Ramp, RAMP, key, 0x060C0DF0);
    GCALL0(0x0602A940);
    GCALL1(0x0602A9D4, 0);
    if (start >= 0) {
        skip = DIVS(start, -65536);
        phase = 0;
    } else {
        skip = 0;
        phase = DIVS(start, 0x10000);
    }
    do {
        if (phase >= 0 && phase == GET(Ramp, RAMP, until))
            GCALL1(0x0602A9D4, phase);
        if (skip >= 0) {
            row = GCALL2(0x060980C8, 0x10000, GET(Ramp, RAMP, x)) & 0x0007FF00;
            ST32(dst, ((GET(Ramp, RAMP, y) & 0x07FFFF00) - row * 160) + 0x00A00000);
            ST32(dst + 4, acc & 0x07FFFF00);
            ST32(dst + 8, row);
            dst += 12;
            rows++;
            step = GCALL2(0x060980C8, 0x10000, GET(Ramp, RAMP, z));
            acc += step;
        }
        if (phase >= 0) {
            SET(Ramp, RAMP, x, GET(Ramp, RAMP, x) + GET(Ramp, RAMP, dx));
            SET(Ramp, RAMP, y, GET(Ramp, RAMP, y) + GET(Ramp, RAMP, dy));
            SET(Ramp, RAMP, z, GET(Ramp, RAMP, z) + GET(Ramp, RAMP, dz));
        }
        phase++;
        skip++;
    } while (AGAIN(rows < 0x100));
    return step;
}

int f0602AC54(int key)
{
    int i;

    for (i = 0; i < LDU16(0x060C0F80); i++) {
        POLL();
        if (GET(RampKey, 0x060C0DF0 + i * 10, until) == (short)key)
            return i;
    }
    return -1;
}

int f0602ACAE(short key)
{
    int found = -1;
    int i = 0;
    gaddr e = 0x060C0DF0;

    GCALL0(0x0602A7F6);
    while ((short)i < LDU16(0x060C0F80)) {
        POLL();
        if (LD16(e) > key)
            break;
        found = i;
        i++;
        e += 10;
    }
    return found;
}

int f0602ACE4(short key)
{
    int found = -1;
    int i = 0;
    gaddr e = 0x060C0DF0;

    GCALL0(0x0602A7F6);
    while ((short)i < LDU16(0x060C0F80)) {
        POLL();
        if (LD16(e) >= key) {
            found = i;
            break;
        }
        i++;
        e += 10;
    }
    return found;
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

int f0602B4A4(gaddr ids, gaddr flags)
{
    int n = (short)((LD32(0x060C1040) & 4) ? 12 : 10);
    int i = 0;

    if (n > 0) {
        do {
            int y = LD16(OBJ(LDU16(ids)) + 38);

            if (LD8(flags) & 128) {
                if (y > -60)
                    break;
            } else if (y < 0) {
                break;
            }
            i++;
            flags++;
            ids += 4;
        } while (AGAIN(i < n));
    }
    return i >= n ? -1 : 0;
}

int f0602B7CA(short cur)
{
    FRAME(sp, 28);
    gaddr free_at = sp - 28;
    int limit = (LD32(0x060C1040) & 4) ? 12 : 10;
    int i, n;

    i = 0;
    do {
        ST8(free_at + i, 1);
    } while (AGAIN(++i < 12));
    i = 0;
    while (i < LD8(0x060C1044)) {
        POLL();
        if (LDU8(0x060C0640 + i) & 3)
            ST8(free_at + LDU8(0x060C064A + i), 0);
        i++;
    }
    n = cur + 1;
    if (n < limit) {
        do {
            if (LDU8(free_at + n) != 0)
                break;
            n++;
        } while (AGAIN(n < limit));
    }
    return n >= limit ? -1 : n;
}

int f0602B8F0(void)
{
    return GCALL1(0x0602B7CA, -1);
}

int f0602B8FC(int dir)
{
    int v = GCALL1(0x0602B7CA, dir);

    if ((short)v < 0)
        v = GCALL1(0x0602B7CA, -1);
    return v;
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

int f0602B954(int n)
{
    int i = GCALL1(0x0602B930, n);

    if ((short)i < 10)
        return i;
    POLL();
    i = 0;
    while (!(LD8(0x060C0640 + i) & 3)) {
        i++;
        if (i >= 10)
            break;
        POLL();
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

int f0602B998(int n)
{
    int i = GCALL1(0x0602B976, n);

    if ((short)i >= 0)
        return i;
    POLL();
    i = 9;
    while (!(LD8(0x060C0640 + i) & 3)) {
        i--;
        if (i < 0)
            break;
        POLL();
    }
    return i;
}

int f0602B9B2(void)
{
    int i = LD8(0x060C1044);

    if (i >= 10 || (LD8(0x060C0640 + i) & 3) != 1)
        return GCALL1(0x0602B9EC, i);
    return LDU16(0x260060B0 + i * 2);
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

int f0602BA62(int arg)
{
    int done = 0;
    int info = GCALL0(0x0602B9EC);
    int pad = GCALL0(0x0602B9B2);

    if (!(info & 0x100)) {
        if (!(pad & 0xE00)) {
            if (pad & 0x8000)
                ST8(0x060C122C, GCALL1(0x0602B8FC, LD8(0x060C122C) & 255));
            if (pad & 0x4000)
                ST8(0x060C122C, GCALL1(0x0602B916, LD8(0x060C122C) & 255));
            if (pad & 0xC000)
                GCALL1(0x0600996A, 4);
        } else {
            GCALL1(0x0600996A, 5);
            if (LD8(0x060C1044) >= 10) {
                done = 1;
            } else {
                GCALL2(0x0602B328, LD8(0x060C122C) & 255, arg);
                ST8(0x060C064A + LD8(0x060C1044), LD8(0x060C122C));
                ST8(0x060C1044, GCALL1(0x0602B930, LD8(0x060C1044)));
                ST8(0x060C122C, GCALL1(0x0602B8FC, LD8(0x060C122C) & 255));
            }
        }
    } else {
        GCALL1(0x0600996A, 6);
        ST8(0x060C1044, GCALL1(0x0602B976, LD8(0x060C1044)));
        if (LD8(0x060C1044) < 0) {
            done = 1;
        } else {
            ST8(0x060C122C, LD8(0x060C064A + LD8(0x060C1044)));
            GCALL2(0x0602B334, LD8(0x060C122C) & 255, arg);
        }
    }
    return done;
}

void f0602BF7E(void)
{
    if (!(LD32(0x060C1048) & 0x00080000))
        ST8(0x060C1044, GCALL1(0x0602B930, -1));
    else
        ST8(0x060C1044, 10);
    ST8(0x060C122C, GCALL0(0x0602C61E));
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

int f0602C540(short which)
{
    FRAME(sp, 28);
    gaddr count = sp - 28;
    int total = 0;
    int i = 0;
    int kind;

    do {
        ST16(count + i * 2, 0);
        i++;
    } while (AGAIN(i < 5));
    for (i = 0; i < 10; i++) {
        POLL();
        kind = LDU8(0x060C0640 + i);
        if (kind & 3) {
            total++;
            if (i < LD8(0x060C1044))
                ST16(count + (kind >> 2) * 2, LD16(count + (kind >> 2) * 2) + 1);
        }
    }
    return LD16(count + which * 2) + 1 >= total ? 0 : -1;
}

int f0602C5BC(short level)
{
    int i = level + 1;

    if (i < 5) {
        do {
            if ((short)GCALL1(0x0602C540, i) != 0)
                break;
            i++;
        } while (AGAIN(i < 5));
    }
    return i < 5 ? i : -1;
}

int f0602C61E(void)
{
    return GJUMP1(0x0602C5BC, -1);
}

int f0602C65E(void)
{
    int done = 0;
    int info = GCALL0(0x0602B9EC);
    int pad = GCALL0(0x0602B9B2);

    if (!(info & 0x100)) {
        if (!(pad & 0xE00)) {
            if (LD8(0x060C1044) < 10) {
                if (pad & 0x8000)
                    ST8(0x060C122C, GCALL1(0x0602C622, LD8(0x060C122C) & 255));
                if (pad & 0x4000)
                    ST8(0x060C122C, GCALL1(0x0602C644, LD8(0x060C122C) & 255));
                if (pad & 0xC000)
                    GCALL1(0x0600996A, 4);
            }
        } else {
            GCALL1(0x0600996A, 5);
            if (LD8(0x060C1044) >= 10) {
                done = 1;
            } else {
                ST8(0x060C0640 + LD8(0x060C1044), LD8(0x060C0640 + LD8(0x060C1044)) & 3);
                ST8(0x060C0640 + LD8(0x060C1044), LD8(0x060C0640 + LD8(0x060C1044)) | ((LD8(0x060C122C) & 255) << 2));
                ST8(0x060C1044, GCALL1(0x0602B930, LD8(0x060C1044)));
                if (!(short)GCALL1(0x0602C540, LD8(0x060C122C) & 255))
                    ST8(0x060C122C, GCALL0(0x0602C61E));
            }
        }
    } else {
        GCALL1(0x0600996A, 6);
        ST8(0x060C1044, GCALL1(0x0602B976, LD8(0x060C1044)));
        if (LD8(0x060C1044) < 0)
            done = 1;
        else
            ST8(0x060C122C, (unsigned char)LD8(0x060C0640 + LD8(0x060C1044)) >> 2);
    }
    return done;
}

void f0602C9B6(gaddr rec, short col, short row)
{
    int q = DIVS(col, 3);
    int r = MODS(col, 3);

    ST16(rec + 36, (q << 4) - (DIVS(row - 1, 3) << 3));
    ST16(rec + 38, -40 - (r << 4));
    ST16(rec + 4, 0x12B - r);
}

void f0602D45C(short n, short x, short y, short scale)
{
    FRAME(sp, 52);
    short ids[5];
    gaddr rec = 0x060E20DE + (signed char)(n * 14);
    int k;
    gaddr box;
    int wide, tall, lower;

    for (k = 0; k < 5; k++)
        ids[k] = LD16(rec + 2 + k * 2);
    k = 0;
    do {
        if (ids[k] != 0) {
            gaddr obj = OBJ(ids[k]);

            ST16(obj + 68, scale);
            ST16(obj + 70, scale);
            ST16(obj + 16, x);
            ST16(obj + 18, y);
            ST16(obj + 4, LDU8(0x060B522A + k) + LD16(sp + 2));
        }
    } while (AGAIN(++k < 5));
    box = OBJ(ids[1]);
    wide = HELPER((int)(scale << 5) >> 8);
    tall = HELPER((int)(scale * 56) >> 8);
    lower = HELPER((int)(scale * 48) >> 8);
    ST16(box + 20, x - wide - 1);
    ST16(box + 24, x + wide);
    ST16(box + 28, x + tall);
    ST16(box + 32, x - tall - 1);
    ST16(box + 22, y - lower);
    ST16(box + 26, y - lower);
    ST16(box + 30, y - 1);
    ST16(box + 34, y - 1);
}

void f0602D570(short n, short turn, short x, short y)
{
    FRAME(sp, 44);
    int size = LD16(sp + 2);
    int angle = (LDU8(0x060E20DE + (signed char)(n * 14) + 13) + turn) & 255;
    int dx, dy, scale, back, denom;

    dx = -GCALL2(0x060980B4, GCALL1(0x0609812C, LD32(0x060B9108 + angle * 4)), size);
    denom = 0x200 - GCALL2(0x060980B4, GCALL1(0x0609816C, LD32(0x060B9108 + angle * 4)), size);
    scale = DIVS(0x10000, denom);
    dx = HELPER((int)(dx * scale) >> 8) + x;
    dy = HELPER((int)(y * scale) >> 8);
    back = (ABS(128 - angle) >> 2) - 16;
    GCALL5(0x0602D45C, n, dx, dy, scale, back + 90);
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

void f0602D8A0(int x, unsigned short row)
{
    short half = (unsigned int)(x - 112) >> 1;
    short edge = x + 256;
    int i = 0;
    int near_;
    int first;
    int last;

    do {
        if (row == i) {
            near_ = half;
            if (near_ < 0) {
                near_ = 0;
                last = 256 - x * 2;
            } else {
                last = 256 - 112 * 2;
            }
            first = near_ + 112;
        } else {
            first = 112 - x;
            last = edge;
        }
        GCALL5(0x0602D570, i, LD16(0x060C0FBE), 160, first, last);
        i++;
    } while (AGAIN(i < 8));
    ST16(OBJ(LDU16(0x060C0FB8)) + 38, -x);
    ST16(OBJ(LDU16(0x060C0FBA)) + 38, -x);
}

void f0602D954(unsigned int n, unsigned short mode)
{
    gaddr obj = OBJ(LDU16(0x060C0FBC));
    unsigned int scale;

    if (mode >= 8) {
        scale = DIVU(0x00060000, 0x600 - n * 5);
        ST16(obj + 68, scale);
        ST16(obj + 70, scale);
    } else {
        ST16(obj + 38, -(n >> 2));
    }
    ST32(0x060FAA14, n << 13);
    ST16(0x060BB8FC, 1);
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
        POLL();
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

int f0602E752(gaddr out)
{
    int i = 0;

    ST32(out, 0);
    while (i < 10) {
        POLL();
        if (LD8(0x26006134 + i) == 0 && (LDU8(0x060C0640 + i) & 3) && (LDU16(0x260060B0 + i * 2) & 0x800)) {
            ST32(out, 0x800);
            break;
        }
        i++;
    }
    return i;
}

int f0602E7A0(gaddr out)
{
    int i = 0;

    ST32(out, 0);
    while (i < LDU8(BOMBER_COUNT)) {
        POLL();
        if (LD8(0x26006134 + i) == 0 && GCALL1(0x06039FF0, i) != 0 && (LDU16(0x260060B0 + i * 2) & 0x800)) {
            ST32(out, 0x800);
            break;
        }
        i++;
    }
    return i;
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

void f0602EA24(void)
{
    GCALL0(0x0606AA90);
    GCALL0(0x0600994E);
    POLL();
    GJUMP0(0x06009452);
}

void f0602ECCE(void)
{
    gaddr p = 0x060C101C;

    do {
        GCALL1(0x060692DC, LDU16(p));
        p += 2;
    } while (AGAIN(p < 0x060C1026));
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

int f0602F322(void)
{
    return GJUMP4(0x060069B2, 0x0602F3A8, 0x060E1898, 0x200, 1);
}

int f0602F368(void)
{
    return GJUMP4(0x060069B2, 0x0602F51E, 0x060E1898, 0x200, 1);
}

void f0602F374(void)
{
    gaddr p = 0x060C0FF4;
    int i = 0;

    do {
        ST16(p, GCALL1(0x060691DA, 0x1F3));
        i++;
        p += 2;
    } while (AGAIN(i < 4));
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
