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
    GCALL1(0x0600C9AA, LD16(LD32(CURRENT) + 20));
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

void f06020B40(void)
{
    int x = LD16(0x060D7E88) & 15;
    int y = LD16(0x060D7E8A) & 15;
    int dir = AGET(b14);

    if ((dir == 1 && x >= 8) || (dir == 2 && y >= 8) || (dir == 3 && x < 8) || (dir == 4 && y < 8))
        ASET(b14, ((dir + 255) ^ 2) + 1);
}

int f06020D1C(void)
{
    if (!(LDU16(FLAGS_AT(AGET(w4))) & 0x42B0))
        return 0;
    return (AGET(w10) & 0x100) != 0;
}

int f06020D68(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);
    SETSP(sp - 8);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x06020D1C);
    if ((r0 & r0) == 0) {
        r3 = LD32(0x060D8C08);
        r0 = LD16(r3 + 8);
        ST16(r3 + 8, (r0 & 0xFFDF));
        r3 = LD32(0x060D8C08);
        r0 = LD16(r3 + 10);
        ST16(r3 + 10, (r0 & 0xFEFF));
        SETR(14, 0x060D8C08);
        SETSP((sp - 8));
        SETPR(0x06020D98);
        r0 = GCALL1(0x0601DC78, 0);
        r5 = LD16(0x060DF982);
        r4 = LD32(0x060D8C08);
        r4 = LD16(r4);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        SETSP(sp);
        r0 = GJUMP2(0x06069462, r4, r5);
        return r0;
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        SETSP(sp);
        r0 = GJUMP0(0x0601E766);
        return r0;
    }
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

int f06020E40(int type)
{
    int result = 0;
    int next = LDU8(0x060D84A3);

    for (;;) {
        ST32(ACTOR_PTR, 0x060D849C + next * 38);
        if (AGET(b7) == 0)
            return result;
        POLL();
        if (AGET(b16) != 0 && AGET(b16) != 255 && AGET(b15) == type) {
            GCALL0(0x0601E766);
            result = LDU8(0x060D849C + AGET(b6) * 38 + 7);
        }
        next = AGET(b7);
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

int f06021014(int cell)
{
    int next = LDU8(0x060D84A3);

    for (;;) {
        ST32(ACTOR_PTR, 0x060D849C + next * 38);
        if (AGET(b7) == 0)
            return -1;
        POLL();
        if (AGET(b16) != 0 && AGET(w4) == cell)
            return AGET(b15);
        next = AGET(b7);
    }
}

int f0602105A(int type)
{
    int count = 0;
    int next = LDU8(0x060D84A3);

    for (;;) {
        ST32(ACTOR_PTR, 0x060D849C + next * 38);
        if (AGET(b7) == 0)
            return count;
        POLL();
        if (AGET(b15) == type) {
            count++;
            ASET(b13, 1);
        }
        next = AGET(b7);
    }
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

void f06021486(void)
{
    int level;

    for (level = 15; level != 0; level--) {
        int next = LDU8(0x060D84A3);

        POLL();
        for (;;) {
            ST32(ACTOR_PTR, 0x060D849C + next * 38);
            if (AGET(b7) == 0)
                break;
            POLL();
            if (AGET(b36) == level) {
                int speed = (LDU16(FLAGS_AT(AGET(w4))) & 0x2000) ? 16 : LDU8(LD32(ACTOR_PTR) + 17);

                GCALL5(0x06021190, 0, speed, AGET(w4), 0, 0x060D849C);
                ASET(b36, 0);
                ASET(b35, AGET(b35) & 252);
            }
            next = AGET(b7);
        }
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

void f06021604(int amount, int who)
{
    gaddr rec = REC(who);
    gaddr total = 0x060C0690 + who * 4;
    gaddr best = 0x060C0698 + who * 4;
    gaddr cell;

    if (LDU8(rec + 4) & 128)
        return;
    if (amount == 0)
        return;
    ST32(total, LD32(total) + amount);
    ST32(best, LD32(best) + amount);
    if ((unsigned)LD32(total) >= 9999999)
        ST32(total, 9999999);
    if ((unsigned)LD32(best) >= 9999999)
        ST32(best, 9999999);
    if (!(LDU16(rec + 46) & 0x800))
        return;
    cell = 0x060D82DC + who * 20 + ((LDU16(REC(LDU16(rec + 36)) + 64) - 1) << 2);
    ST32(cell, LD32(cell) + amount);
    if ((unsigned)LD32(cell) >= 9999999)
        ST32(cell, 9999999);
}

int f0602168C(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r14;
    int v8;
    int v12;

    v12 = r4;
    v8 = r5;
    if (!((r5 & 1) == 0)) {
        r0 = GCALL6(0x06021604, v12, 0, 0, 0, v12, v8);
    }
    r0 = v8;
    if ((r0 & 2) == 0) {
        return r0;
    } else {
        r5 = 1;
        r4 = v12;
        POLL();
        r14 = (r5 * 124) + 0x060D5F30;
        r0 = LD8(r14 + 4);
        r0 = r0 & 255;
        if ((r0 & 128) == 0) {
            if (!((r4 & r4) == 0)) {
                r6 = r5 << 2;
                r0 = 0x060C0690 + r6;
                r3 = LD32(r0);
                r7 = 0x060C0698 + r6;
                r6 = 0x0098967F;
                ST32(r0, (r3 + r4));
                r2 = LD32(r7);
                ST32(r7, (r2 + r4));
                r3 = LD32(r0);
                if ((unsigned)r3 >= (unsigned)0x0098967F) {
                    ST32(r0, r6);
                }
                r3 = LD32(r7);
                r0 = 46;
                if ((unsigned)r3 >= (unsigned)r6) {
                    ST32(r7, r6);
                }
                r3 = LD16(r0 + r14);
                if (!(((r3 & 0xFFFF) & 0x800) == 0)) {
                    r1 = LD16(36 + r14);
                    r0 = 0x060D5F70;
                    r2 = LD16(0x060D5F70 + ((r1 & 0xFFFF) * 124));
                    r5 = ((((r5 << 2) + r5) << 2) + 0x060D82DC) + (((r2 & 0xFFFF) - 1) << 2);
                    r3 = LD32(r5);
                    r3 = r3 + r4;
                    ST32(r5, r3);
                    if ((unsigned)r3 >= (unsigned)r6) {
                        ST32(r5, r6);
                    }
                }
            }
        }
        return r0;
    }
}

void f060216D4(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 44);

    ST32((sp - 4), R(14));
    r14 = r4;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    ST32(sp - 36, r5);
    ST32(sp - 40, r6);
    r12 = r7;
    if (!((r14 & r14) == 0)) {
        r3 = LD8(0x060C063D);
        if (!((r3 & 255) > 2)) {
            if (!((r12 & r12) == 0)) {
                if (!((unsigned)r12 >= (unsigned)0x1000)) {
                    r9 = 1;
                    if (!((unsigned)r12 >= (unsigned)4)) {
                        SETSP((sp - 40));
                        r0 = GCALL2(0x0602168C, r14, r12);
                        r13 = r9;
                    } else {
                        SETSP((sp - 40));
                        r0 = GCALL1(0x06020F7C, r12);
                        r10 = r0;
                        SETSP((sp - 40));
                        r0 = GCALL1(0x06020F50, r12);
                        r4 = r0;
                        r13 = LD8(0x060DF994 + r10);
                        r13 = r13 & 255;
                        if (!((unsigned)r14 >= (unsigned)0x1388)) {
                            if ((unsigned)(r13 + 1) > (unsigned)20) {
                                r13 = 19;
                            }
                        } else {
                            r13 = r9;
                        }
                        r11 = LD8(0x060DFA95 + r4);
                        r11 = r11 & 255;
                        r3 = LD8(0x060C063D);
                        if ((unsigned)r11 >= (unsigned)(r3 & 255)) {
                            r0 = LD8(0x060C029C);
                            r4 = 0;
                            if (!((r0 & 255) == 8)) {
                                r14 = r4;
                            } else {
                                r11 = r4;
                            }
                        }
                        if (!((r14 & r14) == 0)) {
                            SETSP((sp - 40));
                            r0 = GCALL2(0x060276D0, 1, r12);
                            SETSP((sp - 40));
                            r0 = GCALL2(0x060276D0, 11, r13);
                            r3 = LD8(0x060DF994 + r10);
                            ST8(0x060DF994 + r10, (r3 + 1));
                            SETSP((sp - 40));
                            r0 = GCALL2(0x06021604, (r14 * r13), r11);
                        }
                    }
                    if (!((r14 & r14) == 0)) {
                        r2 = LD16(0x060C0630);
                        if (((r2 & 0xFFFF) & r9) == 0) {
                            r3 = 16;
                        } else {
                            r3 = 0;
                        }
                        ST32((sp - 44), r3);
                        r6 = LD32(sp - 40);
                        r5 = LD32(sp - 36);
                        SETSP((sp - 44));
                        SETPR(0x060217AC);
                        r0 = GCALL4(0x06035752, r14, r5, r6, r13);
                    }
                }
            }
        }
    }
    SETMACL(LD32((sp - 32)));
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
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

void f06021822(void)
{
    unsigned int i = 0;

    do {
        GCALL1(0x06021F9A, i);
        i++;
    } while (AGAIN(i <= 75));
}

int f0602183E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x06008A96, 0);
    SETSP((sp - 4));
    SETPR(0x0602184E);
    r0 = GCALL2(0x06068BA4, 1, 37);
    r4 = LD8(0x060C029C);
    r0 = r4 & 255;
    r4 = r0;
    if (!(r0 == 17)) {
        if (!(r4 >= 9)) {
            SETPR(LD32((sp - 4)));
            return r0;
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x06008A96, 1);
            SETSP((sp - 4));
            SETPR(0x06021878);
            r0 = GCALL2(0x06068BA4, 1, 4);
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            SETSP(sp);
            r0 = GJUMP2(0x06008ECA, 1, 0x1E0);
            return r0;
        }
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        SETSP(sp);
        r0 = GJUMP2(0x06008ECA, 3, 0);
        return r0;
    }
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

int f06021E6A(void)
{
    int r0, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 36);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    r11 = 3;
    r12 = 0x4B0;
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    r10 = 7;
    r14 = 0x060D5F30;
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r8 = 0x060C063D;
    r9 = 0x060B48F8;
    r13 = 0;
    while (1) {
        r3 = LD8(r8);
        if (!((unsigned)r13 >= (unsigned)(r3 & 255))) {
            POLL();
            r0 = LD8(r14 + 4);
            r4 = r0 & 255;
            if (!((r4 & r11) == 0)) {
                if ((192 & r4) == 0) {
                    SETSP((sp - 36));
                    r0 = GCALL0(0x0600A0B8);
                    r2 = LD16(((r0 & r10) << 1) + r9);
                    ST16(42 + r14, r2);
                    ST16(44 + r14, r12);
                }
            }
            r13 = r13 + 1;
            r14 = r14 + 124;
            continue;
        } else {
            break;
        }
    }
    SETSP((sp - 36));
    r0 = GCALL1(0x06008A96, 1);
    r13 = 0x060DFDF6;
    r0 = LD16(0x060DFDF6);
    if ((r0 & r0) == 0) {
        SETSP((sp - 36));
        r0 = GCALL1(0x060691DA, 0x1E6);
        ST16(r13, r0);
    }
    r2 = LD16(0x060C062C);
    ST16(0x060DFDF8, r2);
    r5 = LD16(r13);
    r4 = LD16(0x060DFDF8);
    r4 = LD16(0x060D5F46 + ((r4 & 0xFFFF) * 124));
    SETSP((sp - 36));
    r0 = GCALL2(0x0600A3D8, (r4 & 0xFFFF), (r5 & 0xFFFF));
    r2 = LD16(r13);
    r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    SETSP((sp - 36));
    r0 = GCALL2(0x0606AAC8, r14, 1);
    ST16(r14 + 20, 152);
    ST16(r14 + 24, 167);
    ST16(r14 + 22, 0);
    ST16(r14 + 26, 15);
    ST16(46 + r14, 0x61E0);
    r4 = LD16(r13);
    SETSP((sp - 36));
    SETPR(0x06021F5E);
    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 1);
    ST16(0x060DFDFC, 0);
    ST16(0x060DFDFA, 0);
    ST16(0x060DFDFE, 1);
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0x060DFDFE;
}

unsigned char f06021F82(int i)
{
    return LD8(0x060DFB9B + (unsigned char)LDU16(0x060F08B0 + i * 2) * 8);
}

int f06021F9A(int r4)
{
    int r0, r1, r3, r14;
    int v12;

    v12 = r4;
    r14 = ((r4 << 2) << 1) + 0x060DFB96;
    r0 = LD16(r14);
    if (!((r0 & r0) == 0)) {
        r4 = LD16(r14);
        r0 = GCALL5(0x0600CA6A, (r4 & 0xFFFF), 0, 0, 0, v12);
        r3 = r0 << 1;
        r1 = LD16(0x060EC8B0 + r3);
        ST16(0x060EC8B0 + r3, (r1 & 0xFFBF));
        r4 = LD16(r14);
        r0 = GCALL5(0x060692DC, (r4 & 0xFFFF), 0, 0, 0, v12);
    }
    r0 = LD16(r14 + 2);
    if (!((r0 & r0) == 0)) {
        r0 = LD16(r14 + 2);
        r0 = GCALL5(0x060692DC, (r0 & 0xFFFF), 0, 0, 0, v12);
    }
    r4 = v12;
    POLL();
    r4 = ((r4 << 2) << 1) + 0x060DFB96;
    ST16(r4 + 2, 0);
    ST16(r4, 0);
    ST8(r4 + 7, 0);
    ST8(r4 + 6, 0);
    ST8(r4 + 5, 0);
    ST8(r4 + 4, 0);
    return 0;
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

int f06022088(int r4, int r5)
{
    int r0, r1, r2, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 32);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = r4 << 1;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    r0 = LD16(0x060EC8B0 + r13);
    r0 = r0 & 0xFFFF;
    r10 = r5;
    if (!((r0 & 64) == 0)) {
        r0 = LD16(0x060F08B0 + r13);
        r0 = r0 & 0xFFFF;
        r11 = 255 & r0;
        r14 = ((r11 << 2) << 1) + 0x060DFB96;
        if (!((r11 & r11) == 0)) {
            r0 = LD8(r14 + 4);
            if (!((r0 & r0) == 0)) {
                r0 = LD8(r14 + 4);
                r0 = r0 & 255;
                if (!(r0 == 3)) {
                    r0 = LD16(r14);
                    if (!((r0 & r0) == 0)) {
                        r12 = 0x06068A8E;
                        r9 = ((r10 << 1) << 2) + 0x060B4908;
                        r0 = LD8(r9 + 3);
                        ST8(r14 + 4, r0);
                        r0 = LD8(r14 + 5);
                        if ((r0 & 255) == 21) {
                            r4 = LD16(r14);
                            SETR(10, r10);
                            SETR(11, r11);
                            SETR(12, r12);
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 32));
                            SETPR(0x060221A8);
                            r0 = GCALL2(r12, (r4 & 0xFFFF), 0);
                            r0 = r10;
                            if (r0 == 0) {
                                r5 = 119;
                                r0 = LD16(r14 + 2);
                                r4 = r0 & 0xFFFF;
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 32));
                                SETPR(0x060221DA);
                                r0 = GCALL2(r12, r4, r5);
                            } else {
                                if (r0 == 2) {
                                    r5 = LD32(0x060D7B3C);
                                    r0 = LD16(r5 + 4);
                                    r5 = r0;
                                    r0 = LD16(r14 + 2);
                                    SETSP((sp - 32));
                                    r0 = GCALL2(0x06069462, r0, (r5 + 1));
                                    r0 = LD16(r14 + 2);
                                    r5 = 118;
                                    r4 = r0 & 0xFFFF;
                                    SETR(13, r13);
                                    SETR(14, r14);
                                    SETSP((sp - 32));
                                    SETPR(0x060221DA);
                                    r0 = GCALL2(r12, r4, r5);
                                } else {
                                    SETSP((sp - 32));
                                    r0 = GCALL1(0x06021F9A, r11);
                                }
                            }
                        } else {
                            r4 = LD16(r14);
                            SETSP((sp - 32));
                            r0 = GCALL4(0x0600A44A, (r4 & 0xFFFF), 0x060B486C, 0, 0);
                            r4 = LD16(r14);
                            SETSP((sp - 32));
                            r0 = GCALL2(0x0606AB08, (r4 & 0xFFFF), 1);
                            r5 = LD32(r9 + 4);
                            r0 = LD16(r14 + 2);
                            SETR(10, r10);
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 32));
                            SETPR(0x06022120);
                            r0 = GCALL2(r12, (r0 & 0xFFFF), r5);
                            r0 = LD16(r14 + 2);
                            SETSP((sp - 32));
                            r0 = GCALL2(0x0606AB08, (r0 & 0xFFFF), 0);
                            r2 = LD16(r14);
                            r5 = LD16(0x060C3820 + (((r2 & 0xFFFF) * 84) & 0xFFFF));
                            r0 = LD16(r14 + 2);
                            SETSP((sp - 32));
                            r0 = GCALL2(0x06069462, r0, (r5 + 1));
                            r0 = LD16(r14 + 2);
                            ST16((0x060C385A + (((r0 & 0xFFFF) * 84) & 0xFFFF)), 128);
                            if (r10 == 1) {
                                r1 = LD16(0x060EC8B0 + r13);
                                ST16(0x060EC8B0 + r13, (r1 & 0xFFBF));
                            }
                        }
                        ST8(r14 + 7, 0);
                        ST8(r14 + 6, 0);
                        r0 = 0x060F08B0;
                        r2 = LD16(0x060F08B0 + r13);
                        ST16(0x060F08B0 + r13, (r2 & 0xFF00));
                    }
                }
            }
        }
    }
    SETMACL(LD32((sp - 32)));
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06022204(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 24);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = r4;
    r12 = (r13 & 0xFFFF) << 1;
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r0 = LD16(0x060F08B0 + r12);
    r0 = r0 & 0xFFFF;
    r4 = 255 & r0;
    if ((r4 & r4) == 0) {
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = ((r4 << 2) << 1) + 0x060DFB96;
        r0 = LD8(r14 + 5);
        if (!((r0 & r0) == 0)) {
            r1 = LD16(r14);
            if (!((r1 & r1) == 0)) {
                r1 = LD16(r14);
                r0 = LD16(0x060C3826 + (((r1 & 0xFFFF) * 84) & 0xFFFF));
                if ((r0 & r0) == 0) {
                    r11 = 0x06068A8E;
                    r0 = LD8(r14 + 5);
                    if (!((r0 & 255) == 21)) {
                        r0 = LD8(r14 + 5);
                        r4 = LD16(r14);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 24));
                        SETPR(0x0602226C);
                        r0 = GCALL4(r11, (r4 & 0xFFFF), (r0 & 255), r6, r7);
                        r0 = 1;
                    } else {
                        r4 = LD16(r14);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 24));
                        SETPR(0x0602225E);
                        r0 = GCALL4(r11, (r4 & 0xFFFF), 117, r6, r7);
                        r0 = 2;
                    }
                    ST8(r14 + 4, r0);
                    r0 = LD16(r14 + 2);
                    if (!((r0 & r0) == 0)) {
                        r0 = LD16(r14 + 2);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETSP((sp - 24));
                        SETPR(0x0602227E);
                        r0 = GCALL2(r11, (r0 & 0xFFFF), 33);
                    }
                }
            }
        }
        r0 = LD16(0x060EC8B0 + r12);
        if (((r0 & 0xFFFF) & 64) == 0) {
            SETMACL(LD32((sp - 24)));
            r4 = r13 & 0xFFFF;
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            POLL();
            ST32((sp - 4), PR());
            ST32(sp - 8, r4);
            SETSP((sp - 12));
            r0 = GCALL1(0x06022B0A, r4);
            r3 = LD32(sp - 8);
            r3 = r3 << 1;
            ST32(sp - 12, r3);
            r1 = LD16(0x060EC8B0 + r3);
            ST16(0x060EC8B0 + r3, (r1 & 0xFFBF));
            r0 = LD32(sp - 12);
            r0 = LD16(r0 + 0x060F08B0);
            r4 = 255 & (r0 & 0xFFFF);
            if (!((r4 & r4) == 0)) {
                SETSP((sp - 12));
                r0 = GCALL1(0x06021F9A, r4);
            }
            r3 = LD32(sp - 12);
            r3 = r3 + 0x060F08B0;
            r1 = LD16(r3);
            ST16(r3, (r1 & 0xFF00));
            SETPR(LD32((sp - 4)));
            return 0x060F08B0;
        } else {
            SETMACL(LD32((sp - 24)));
            r4 = r13;
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            ST32((sp - 4), PR());
            ST16(sp - 8, r4);
            SETSP((sp - 8));
            r0 = GCALL0(0x0600C434);
            r5 = LD16(sp - 8);
            r4 = LD16(sp - 8);
            r3 = LD32(0x060D7E94);
            r4 = LD16((((r4 & 0xFFFF) << 1) + r3));
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            SETSP(sp);
            r0 = GJUMP2(0x0600C7BE, r4, r5);
            return r0;
        }
    }
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

int f06022486(int r4, int r5, int r6, int r7)
{
    int r0, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 20);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    r13 = 1;
    r14 = 0x060DFB9E;
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    r12 = 75;
    ST32((sp - 20), PR());
    r11 = 0x0606948A;
    do {
        r0 = LD16(r14);
        if (!((r0 & r0) == 0)) {
            r4 = LD16(r14);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x060224A2);
            r0 = GCALL4(r11, r4, r5, r6, r7);
        }
        r0 = LD8(r14 + 4);
        if (!((r0 & r0) == 0)) {
            r0 = LD8(r14 + 4);
            r0 = r0 & 255;
            if (r0 == 1) {
                SETSP((sp - 20));
                r0 = GCALL1(0x0602251C, r14);
            } else {
                if (r0 == 2) {
                    SETSP((sp - 20));
                    r0 = GCALL1(0x060225D2, r14);
                } else {
                    if (r0 == 3) {
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 20));
                        SETPR(0x060224DA);
                        r5 = r13;
                        r0 = GCALL2(0x06022688, r14, r13);
                    } else {
                        if (!(r0 == 4)) {
                            if (r0 == 5) {
                                SETR(11, r11);
                                SETR(12, r12);
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 20));
                                SETPR(0x06022506);
                                r5 = r13;
                                r0 = GCALL2(0x06022706, r14, r13);
                            }
                        }
                    }
                }
            }
        }
        r13 = r13 + 1;
        r14 = r14 + 8;
    } while (AGAIN(!((unsigned)r13 > (unsigned)r12)));
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP4(0x060357A4, 0, r5, r6, r7);
    return r0;
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

int f06022688(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 20);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    r14 = r4;
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    ST32(sp - 20, r5);
    r0 = LD8(r14 + 6);
    if (!((r0 & 255) >= 21)) {
        r0 = LD8(r14 + 7);
        if ((r0 & r0) == 0) {
            ST8(r14 + 7, 5);
            r0 = LD8(r14 + 6);
            r13 = 0x060B49A0 + (r0 & 255);
            r0 = LD8(r14 + 6);
            ST8(r14 + 6, (r0 + 3));
            r2 = LD8(r13);
            r1 = LD32(0x060B2E88 + (r2 << 2));
            r0 = LD8(r13 + 2);
            r7 = r0;
            r0 = LD8(r13 + 1);
            r4 = LD16(r14);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x060226D6);
            r0 = GCALL4(r1, r4, 0x060B486C, r0, r7);
        } else {
            r0 = LD8(r14 + 7);
            ST8(r14 + 7, (r0 - 1));
        }
    }
    r0 = LD16(r14 + 2);
    r2 = LD16((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C3858);
    r0 = 0xFF00;
    if (!((r2 & 0xFFFF) == 0xFF00)) {
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(sp - 20);
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        SETSP(sp);
        r0 = GJUMP1(0x06021F9A, r4);
        return r0;
    }
}

int f06022706(int r4, int r5)
{
    int r0, r1, r2, r7, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 16);

    ST32((sp - 4), R(14));
    r14 = r4;
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32(sp - 16, r5);
    r0 = LD8(r14 + 6);
    if ((r0 & 255) >= 30) {
        r4 = LD32(sp - 16);
        SETSP((sp - 16));
        r0 = GCALL1(0x06021F9A, r4);
    } else {
        r0 = LD8(r14 + 6);
        r13 = 0x060B49A0 + (r0 & 255);
        r2 = LD8(r13);
        r1 = LD32(0x060B2E88 + (r2 << 2));
        r0 = LD8(r13 + 2);
        r7 = r0;
        r0 = LD8(r13 + 1);
        r4 = LD16(r14);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x0602273A);
        r0 = GCALL4(r1, r4, 0x060B486C, r0, r7);
    }
    r0 = LD8(r14 + 6);
    r0 = r0 + 3;
    ST8(r14 + 6, r0);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0602277C(void)
{
    gaddr obj;
    gaddr who;
    int px;
    int py;
    int angle;

    if (LDU16(0x060D7E68) & 16)
        return;
    if (LDU16(0x060DFDF6) == 0)
        return;
    obj = OBJ(LDU16(0x060DFDF6));
    who = REC(LDU16(0x060DFDF8));
    if (LD16(who + 42) == 0 || (LDU8(who + 4) & 128) || LD16(0x060DFDFE) == 0) {
        ST16(0x060DFDFE, 0);
        if (LD16(0x060DFDFA) == 0) {
            if (LDU16(0x060DFDFC) >= 5) {
                ST16(obj + 42, LD16(obj + 42) | 32);
                ST16(obj + 22, LD16(obj + 22) - 6);
                ST16(obj + 26, LD16(obj + 26) - 6);
                if (LD16(obj + 26) >= 10)
                    return;
                GCALL1(0x060692DC, LDU16(0x060DFDF6));
                GCALL1(0x060092AA, 0);
                ST16(0x060DFDF6, 0);
            } else {
                ST16(0x060DFDFC, LD16(0x060DFDFC) + 1);
                ST16(obj + 20, LD16(obj + 20) + 1);
                ST16(obj + 24, LD16(obj + 24) - 1);
                ST16(obj + 22, LD16(obj + 22) + 1);
                ST16(obj + 26, LD16(obj + 26) - 1);
            }
        } else {
            ST16(0x060DFDFC, 0);
            ST16(0x060DFDFA, 0);
            GCALL2(0x0606AAC8, obj, 1);
            ST16(obj + 20, LD16(obj + 36) + LD16(obj + 16));
            ST16(obj + 24, LD16(obj + 36) + LD16(obj + 16) + 23);
            ST16(obj + 22, LD16(obj + 38) + LD16(obj + 18));
            ST16(obj + 26, LD16(obj + 38) + LD16(obj + 18) + 23);
        }
        return;
    }
    if (LD16(0x060DFDFA) == 0) {
        if (LD16(0x060DFDFC) == 0)
            GCALL6(0x06009288, 0, 0x200, 0x2FF, 0x8080, 0x8080, 0x8080);
        if (LDU16(0x060DFDFC) < 100) {
            ST16(0x060D7E68, LD16(0x060D7E68) | 1);
            GCALL0(0x0606AA58);
            ST16(obj + 42, LD16(obj + 42) & 0xFFDF);
            ST16(0x060DFDFC, LD16(0x060DFDFC) + 1);
            angle = (MODS(LDU16(0x060DFDFC) * 14, 0x168) - 180) << 16;
            px = (short)((unsigned int)FMUL(GCALL1(0x0609812C, angle), (110 - LDU16(0x060DFDFC)) << 16) >> 16);
            py = (short)((unsigned int)FMUL(GCALL1(0x0609816C, angle), (110 - LDU16(0x060DFDFC)) << 16) >> 16);
            px += 160;
            py += 112;
            ST16(obj + 20, px - LD16(0x060DFDFC));
            ST16(obj + 24, LD16(0x060DFDFC) + px + 23);
            ST16(obj + 22, py - LD16(0x060DFDFC));
            ST16(obj + 26, LD16(0x060DFDFC) + py + 23);
        } else if (LDU16(0x060DFDFC) >= 200) {
            ST16(0x060DFDFA, 1);
            GCALL2(0x0606AAC8, obj, 0);
            ST16(0x060D7E68, LD16(0x060D7E68) & 0xFFFE);
            GCALL0(0x0606AA90);
            ST16(obj + 38, -15);
            ST16(obj + 36, -4);
        } else {
            if (LD16(obj + 20) == LD16(obj + 16) && LD16(obj + 24) == LD16(obj + 16) + 23
                && LD16(obj + 22) == LD16(obj + 18) - 15 && LD16(obj + 26) == LD16(obj + 18) + 8)
                ST16(0x060DFDFC, 200);
            ease(obj + 20, LD16(obj + 16) - LD16(obj + 20));
            ease(obj + 24, LD16(obj + 16) - LD16(obj + 24) + 23);
            ease(obj + 22, LD16(obj + 18) - LD16(obj + 22) - 15);
            ease(obj + 26, LD16(obj + 18) - LD16(obj + 26) + 8);
        }
    }
    if (LD16(0x060DFDFA) == 0)
        return;
    GCALL2(0x0600A3D8, LDU16(who + 22), LDU16(0x060DFDF6));
    POLL();
    GJUMP2(0x0601486E, LDU16(0x060DFDF6), LDU16(0x060DFDF8));
}

void f06022B0A(short cell)
{
    GCALL0(0x0600C434);
    GJUMP2(0x0600C7BE, LD16(LD32(0x060D7E94) + (unsigned short)cell * 2), cell);
}

int f06022B60(int r4, int r5)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 24);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = r4;
    ST32((sp - 16), PR());
    r4 = (r13 & 0xFFFF) << 1;
    ST32((sp - 20), MACL());
    ST16(sp - 24, r5);
    r0 = LD16(0x060F08B0 + r4);
    if (!(((r0 & 0xFFFF) & 255) == 0)) {
        r0 = LD16(0x060EC8B0 + r4);
        if (((r0 & 0xFFFF) & 64) == 0) {
            SETSP((sp - 24));
            r0 = GCALL1(0x06021F82, (r13 & 0xFFFF));
            SETSP((sp - 24));
            r0 = GCALL2(0x060222D8, r0, r13);
        }
    }
    SETSP((sp - 24));
    r0 = GCALL1(0x060691DA, 0x1E4);
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r2 = LD16(0x060C1AAA);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(44 + r14, 1);
        ST16(46 + r14, 48);
        r1 = LD16(42 + r14);
        ST16(42 + r14, (r1 | 0x400));
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 24));
        r0 = GCALL2(0x0600D148, r4, r13);
        r4 = LD16(0x060C1AAA);
        r5 = LD16(0x060DFE02);
        SETR(14, r14);
        SETSP((sp - 24));
        SETPR(0x06022BDC);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 & 0xFFFF));
        r3 = LD16(sp - 24);
        r0 = 62;
        ST16(62 + r14, r3);
        if (!(((r3 & 0xFFFF) & (r3 & 0xFFFF)) == 0)) {
            r0 = 42;
            r2 = LD16(42 + r14);
            ST16(42 + r14, (r2 | 64));
        }
        r3 = LD16(0x060DFE00);
        ST16(0x060DFE00, (r3 - 1));
    }
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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
    GJUMP1(0x06022EDA, LDU16(0x060D7B44));
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

int f06022FFC(int n)
{
    gaddr slot;
    gaddr cur;
    int px;
    int py;

    if (LD16(0x060D7B46) == 0)
        return 0;
    slot = SLOT(n);
    if (LD16(slot + 8) == 0)
        return 0;
    GCALL1(0x0600CA6A, LDU16(slot + 8));
    cur = LD32(CURRENT);
    px = LD16(0x060D7E88);
    if (LDU16(cur + 24) > px + 8 || LDU16(cur + 24) < px - 8)
        return 0;
    py = LD16(0x060D7E8A);
    cur = LD32(CURRENT);
    return LDU16(cur + 28) <= py + 8 && LDU16(cur + 28) >= py - 8;
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

int f060230B8(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    r3 = LD8(0x060C02A5);
    ST8(0x060C02A5, (r3 - 1));
    r0 = LD8(0x060C02A5);
    if (!((r0 & r0) == 0)) {
        UNFRAME(sp);
        SETSP(sp);
        r0 = GJUMP1(0x0600996A, 46);
        return r0;
    } else {
        r0 = LD16(0x060BF5EA);
        if ((r0 & r0) == 0) {
            ST32((sp - 4), PR());
            r0 = LD16(0x060C02AE);
            if ((r0 & r0) == 0) {
                r0 = LD16(0x060C02B0);
                if (!((r0 & r0) == 0)) {
                    r0 = LD16(0x060C02B2);
                    if (!((r0 & r0) == 0)) {
                        SETSP((sp - 4));
                        r0 = GCALL2(0x06008A6A, 8, 0);
                        SETSP((sp - 4));
                        r0 = GCALL1(0x0600996A, 23);
                        SETSP((sp - 4));
                        r0 = GCALL2(0x06022F1C, 30, 0x060231FA);
                        SETSP((sp - 4));
                        SETPR(0x0602310C);
                        r0 = GCALL1(0x0602318C, 36);
                        r4 = LD32(0x060D7E64);
                        SETSP((sp - 4));
                        r0 = GCALL2(0x0606950C, r4, 1);
                        SETSP((sp - 4));
                        r0 = GCALL2(0x06022F1C, 31, 0x0602336E);
                        SETSP((sp - 4));
                        SETPR(0x06023122);
                        r0 = GCALL1(0x0602318C, 37);
                        r4 = LD32(0x060D7E60);
                        r0 = LD16(r4 + 8);
                        SETSP((sp - 4));
                        r0 = GCALL2(0x06069462, r0, 10);
                        ST16(0x060C02AE, 1);
                    }
                }
            }
            SETPR(LD32((sp - 4)));
            return r0;
        } else {
            UNFRAME(sp);
            SETSP(sp);
            r0 = GJUMP1(0x0600996A, 46);
            return r0;
        }
    }
}

int f0602318C(int r4)
{
    int r0, r2, r3, r5, r6;
    ENTRY_SP(sp);
    SETSP(sp - 16);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32(sp - 16, r4);
    r6 = LD16(0x060C02B2);
    r5 = LD16(0x060C02B0);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 16));
    r0 = GCALL3(0x0600D0E4, r0, r5, r6);
    r5 = LD32(sp - 16);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(14, 0x060D7E60);
    SETSP((sp - 16));
    SETPR(0x060231B6);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    r2 = LD32(0x060D7E64);
    ST16(46 + r2, 0x310);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 16));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    r2 = LD32(0x060D7E64);
    ST16(72 + r2, 0);
    r3 = LD32(0x060D7E64);
    ST16(82 + r3, 8);
    r3 = LD32(0x060D7E64);
    ST16(68 + r3, 0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 10, 0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 12, 0x200);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 6, 0);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
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

int f060234DE(int r4, int r5)
{
    int r0, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 36);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    r11 = r4;
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32(sp - 36, r5);
    ST16(0x060C02B0, r11);
    r2 = LD32(sp - 36);
    ST16(0x060C02B2, r2);
    SETSP((sp - 36));
    r0 = GCALL0(0x0602308C);
    if (!((r0 & r0) == 0)) {
        SETR(11, r11);
        SETSP((sp - 36));
        SETPR(0x06023508);
        r0 = GCALL0(0x060230D6);
    }
    r8 = 128;
    r9 = 1;
    r14 = 0x060C02A8;
    r7 = 15;
    r4 = 0x060D5F30;
    r10 = 2;
    r13 = 0;
    r6 = 8;
    r12 = 0;
    r5 = 0;
    while (!((unsigned)r5 >= (unsigned)r10)) {
        POLL();
        ST8(r5 + r14, r13);
        r0 = LD8(r4 + 4);
        if (((r0 & 255) & r8) == 0) {
            r0 = LD16(r4 + 24);
            if (((((((r0 & 0xFFFF) + 8) >> 1) >> 1) >> 1) >> 1) == r11) {
                r0 = LD16(r4 + 28);
                r3 = LD32(sp - 36);
                if (((((((r0 & 0xFFFF) + 8) >> 1) >> 1) >> 1) >> 1) == r3) {
                    r0 = LD16(r4 + 24);
                    if (!((((r0 & 0xFFFF) + 4) & r7) >= r6)) {
                        r0 = LD16(r4 + 28);
                        if (!((((r0 & 0xFFFF) + 4) & r7) >= r6)) {
                            r3 = LD16(46 + r4);
                            if (((r3 & 0xFFFF) & 0x32D) == 0) {
                                r12 = r12 + 1;
                                ST8(0x060C02A7, r5);
                                ST8(r5 + r14, r9);
                            }
                        }
                    }
                }
            }
        }
        r5 = r5 + 1;
        r4 = r4 + 124;
    }
    r5 = LD32(sp - 36);
    SETSP((sp - 36));
    r0 = GCALL2(0x0600C950, r11, r5);
    r2 = LD16((r0 << 1) + 0x060EC8B0);
    if (!(((r2 & 0xFFFF) & 0x490) == 0)) {
        r12 = r13;
    }
    if ((r12 & r12) == 0) {
        r0 = 0;
    } else {
        r0 = LD8(0x060C02A5);
        if (!((r0 & r0) == 0)) {
            r0 = 0;
        } else {
            r2 = LD16(0x060C02AE);
            if (!((r2 & 0xFFFF) >= 128)) {
                r0 = 0;
            } else {
                r0 = 1;
            }
        }
    }
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

void f0602370A(int a, int b, int c, int d)
{
    GCALL1(0x0600C4E0, d);
    POLL();
    GJUMP3(0x0600C796, a, b, c);
}

void f06023774(void)
{
    GJUMP4(0x06015012, 5, 6, 0x100, 0x00010000);
}

void f06023780(void)
{
    GJUMP4(0x06015012, 1, 2, 0, 0x00040000);
}

int f0602378C(void)
{
    int r0, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 36);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    SETSP((sp - 36));
    r0 = GCALL1(0x06008A96, 1);
    SETSP((sp - 36));
    SETPR(0x060237AC);
    r0 = GCALL1(0x060689F8, 0x060B4A30);
    SETSP((sp - 36));
    r0 = GCALL2(0x06008ECA, 21, 0x3B0);
    r13 = 0x060D7E60;
    r9 = 10;
    r14 = 0x060D7E64;
    r8 = 0;
    r12 = 0;
    r10 = 0;
    r11 = 0;
    do {
        r5 = LD32(0x060B4A80 + (r12 << 2));
        SETSP((sp - 36));
        r0 = GCALL2(0x06022F1C, r9, r5);
        r2 = LD32(r14);
        r0 = LD16((r11 << 1) + 0x060B4A4E);
        ST16(r2 + 16, r0);
        r3 = LD32(r14);
        r0 = LD16(((r11 + 1) << 1) + 0x060B4A4E);
        ST16(r3 + 18, r0);
        r3 = LD32(r14);
        ST16(44 + r3, 1);
        r5 = LD32(r14);
        ST32(sp - 36, r10);
        r3 = LD16(0x060B4A30 + r10);
        ST16(48 + r5, r3);
        r4 = LD32(r13);
        r0 = LD16(r4 + 8);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x0602380A);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r3 & 0xFFFF));
        r2 = LD32(r14);
        ST16(46 + r2, 0x3B0);
        r4 = LD32(r13);
        r0 = LD16(r4 + 8);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606AB08, (r0 & 0xFFFF), 0);
        r4 = LD32(r14);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606950C, r4, 3);
        r5 = LD32(sp - 36);
        r5 = LD16((r5 + 0x060B4A6E));
        r4 = LD32(r13);
        r0 = LD16(r4 + 8);
        SETSP((sp - 36));
        r0 = GCALL2(0x06069462, r0, (r5 & 0xFFFF));
        r0 = r8;
        r3 = LD32(r13);
        r12 = r12 + 1;
        ST16(r3 + 10, r0);
        r10 = r10 + 2;
        r11 = r11 + 2;
        r9 = r9 + 1;
    } while (AGAIN(!((unsigned)r12 >= (unsigned)8)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06023862(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06023868);
    r0 = GCALL0(0x0602378C);
    SETSP((sp - 4));
    SETPR(0x06023870);
    r0 = GCALL2(0x06024FEE, 6, 5);
    SETSP((sp - 4));
    SETPR(0x06023878);
    r0 = GCALL2(0x06024FEE, 12, 5);
    SETSP((sp - 4));
    SETPR(0x06023880);
    r0 = GCALL2(0x06024FEE, 8, 7);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP2(0x06024FEE, 14, 7);
    return r0;
}

int f0602388A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06023890);
    r0 = GCALL0(0x0602378C);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP4(0x06025564, 10, 6, 2, 0);
    return r0;
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

int f06023A54(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 32);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    SETSP((sp - 32));
    r0 = GCALL1(0x06008A96, 1);
    r9 = 0x3B0;
    SETSP((sp - 32));
    r0 = GCALL2(0x06008ECA, 22, 0x3B0);
    r8 = 4;
    r12 = 0x060D7E64;
    r14 = 0;
    r11 = LD8(0x060C029D);
    r13 = 0x060D7E60;
    r11 = (((r11 & 255) << 2) << 2) + 0x060B4AA0;
    do {
        SETSP((sp - 32));
        r0 = GCALL2(0x06022F1C, r14, 0x06023B04);
        SETSP((sp - 32));
        r0 = GCALL0(0x0600BD74);
        r3 = LD16(0x060D7EB6);
        r0 = LD16(r11 + 2);
        r6 = r0 + r3;
        r5 = LD16(r11);
        r1 = LD16(0x060D7EB4);
        r4 = LD32(r13);
        r0 = LD16(r4 + 8);
        SETSP((sp - 32));
        r0 = GCALL3(0x0600D0E4, r0, (r5 + r1), r6);
        r10 = r14 + 81;
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 32));
        SETPR(0x06023ABE);
        r0 = GCALL1(0x06068BDC, r10);
        r4 = LD32(r13);
        r0 = LD16(r4 + 8);
        SETR(8, r8);
        SETR(9, r9);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 32));
        SETPR(0x06023ACA);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r10);
        r2 = LD32(r12);
        ST16(46 + r2, r9);
        r4 = LD32(r12);
        SETSP((sp - 32));
        r0 = GCALL2(0x0606950C, r4, 1);
        r5 = LD32(r12);
        r0 = LD16(r5 + 18);
        r4 = LD32(r13);
        r5 = r0 + 30;
        r0 = LD16(r4 + 8);
        SETSP((sp - 32));
        r0 = GCALL2(0x06069462, r0, r5);
        r14 = r14 + 1;
        r11 = r11 + 4;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r8)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06023B04(void)
{
    if (!LD16(0x060D7B44))
        GCALL1(0x0600996A, 245);
    TSET(h4, 240);
    return 240;
}

int f06023B30(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06023B36);
    r0 = GCALL0(0x06023A54);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    POLL();
    SETSP(sp);
    r0 = GJUMP4(0x06015012, 4, 3, 0x100, 0x00012000);
    return r0;
}

int f06023BC2(void)
{
    return GJUMP4(0x06025564, 10, 5, 3, 0);
}

void f06023BD4(void)
{
    int r0, r2, r3;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    r3 = LD16(0x060DFE00);
    if (!((r3 & 0xFFFF) >= 50)) {
        SETSP((sp - 4));
        SETPR(0x06023BEA);
        r0 = GCALL2(0x06024C76, 10, 6);
        r2 = LD8(0x060C029D);
        if ((r2 & 255) >= 3) {
            SETSP((sp - 4));
            SETPR(0x06023BFE);
            r0 = GCALL2(0x06024C76, 10, 6);
            SETSP((sp - 4));
            SETPR(0x06023C06);
            r0 = GCALL2(0x06024C76, 10, 6);
        }
        ST32(0x060C02B8, 0x060143D8);
    }
    SETPR(LD32((sp - 4)));
}

int f06023C12(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);
    SETSP(sp - 20);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32(sp - 20, r6);
    ST32(sp - 16, r7);
    SETSP((sp - 20));
    r0 = GCALL2(0x06022F1C, r4, r5);
    r6 = LD32(sp - 16);
    r5 = LD32(sp - 20);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 20));
    r0 = GCALL3(0x0600D0E4, r0, r5, r6);
    r2 = LD32(0x060D7E64);
    ST16(44 + r2, 1);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 20));
    r0 = GCALL2(0x0606AB08, (r0 & 0xFFFF), 3);
    r5 = LD32(sp);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    ST16(0x060C1AA8, r0);
    SETR(13, 0x060D7E64);
    SETR(14, 0x060D7E60);
    SETSP((sp - 20));
    SETPR(0x06023C5A);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    r3 = LD32(0x060D7E64);
    ST16(46 + r3, 0x380);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 20));
    r0 = GCALL2(0x0606950C, r4, 3);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 20));
    r0 = GCALL2(0x06069462, r0, 4);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 6, 0);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
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
    GJUMP1(0x0600A32A, LDU8(0x060B4AF0 + n * 4 + (LDU16(0x060C067E) & 3)));
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

int f06023EBC(int r4)
{
    int r0, r2, r3, r7;
    ENTRY_SP(sp);
    SETSP(sp - 16);

    ST32((sp - 4), PR());
    ST32(sp - 8, r4);
    SETSP((sp - 8));
    r0 = GCALL0(0x0600BD74);
    ST32((sp - 12), 89);
    r3 = LD16(0x060D7EB6);
    ST32((sp - 16), ((r3 & 0xFFFF) - 1));
    SETSP((sp - 16));
    r0 = GCALL0(0x0600A0B8);
    r2 = LD16(0x060D7EB4);
    r4 = LD32(sp - 8);
    r7 = LD32((sp - 16));
    SETSP((sp - 12));
    SETPR(0x06023EF0);
    r0 = GCALL4(0x06023C12, r4, 0x06023EF8, (((r0 & 15) + (r2 & 0xFFFF)) - 4), r7);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06023EF8(void)
{
    gaddr obj = LD32(TASK_OBJ);
    int y;

    if (LD16(obj + 16) > 0x150)
        GCALL0(0x06022F14);
    else if (LD16(obj + 18) > 0x100)
        GCALL0(0x06022F14);
    obj = LD32(TASK_OBJ);
    ST16(obj + 16, LD16(obj + 16) + 1);
    obj = LD32(TASK_OBJ);
    y = LD16(obj + 18) + 1;
    ST16(obj + 18, y);
    return y;
}

int f06023F60(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06023F66);
    r0 = GCALL0(0x06023CC8);
    SETSP((sp - 4));
    r0 = GCALL3(0x06025F40, 1, 8, 6);
    SETSP((sp - 4));
    r0 = GCALL3(0x06025F40, 0, 10, 6);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP3(0x06025F40, 3, 12, 6);
    return r0;
}

int f06023F86(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06023F8C);
    r0 = GCALL0(0x06023CC8);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP0(0x060265D2);
    return r0;
}

int f06023F96(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06023F9C);
    r0 = GCALL0(0x06023F60);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP0(0x060265D2);
    return r0;
}

int f06023FA2(void)
{
    int r0, r1, r2, r3, r6, r8, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 28);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(8));
    ST32((sp - 28), PR());
    r0 = LD16(0x060C067E);
    r6 = LD32(0x060B4AFC + ((3 & (r0 & 0xFFFF)) << 2));
    SETSP((sp - 28));
    r0 = GCALL3(0x0600D026, 1, 0, r6);
    r3 = LD16(0x060C0630);
    if (((r3 & 0xFFFF) & 0x3FF) == 0) {
        SETSP((sp - 28));
        SETPR(0x06023FD8);
        r0 = GCALL1(0x06023EBC, 10);
    }
    r2 = LD16(0x060C067C);
    r0 = 0x060C063D;
    r1 = LD8(0x060C063D);
    if (!((r2 & 0xFFFF) >= (r1 & 255))) {
        r10 = 0x060D7E60;
        r12 = 20;
        r13 = 0x060D7C50;
        r14 = 11;
        r11 = 0x0600A0B8;
        do {
            r0 = LD16(r13 + 8);
            if ((r0 & r0) == 0) {
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x06023FFC);
                r0 = GCALL1(0x06023EBC, r14);
                r8 = LD32(r10);
                SETSP((sp - 28));
                r0 = GCALL0(r11);
                r0 = r0 & 127;
                ST16((r8 + 4), r0);
            }
            r14 = r14 + 1;
            r13 = r13 + 24;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r12)));
        r2 = LD8(0x060C063D);
        ST16(0x060C067C, (r2 & 255));
    }
    SETPR(LD32((sp - 28)));
    SETR(8, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f060240E0(void)
{
    GCALL4(0x06068E10, 2, VDP2_VRAM_A1, 102, 1);
    GCALL4(0x06068E10, 3, VDP2_VRAM_A1, 2, 1);
    GCALL1(0x060092D4, 9);
    GJUMP1(0x060092D4, 10);
}

void f06024108(void)
{
    POLL();
    f060240E0();
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

int f06024154(void)
{
    GCALL4(0x06025564, 20, 15, 11, 0);
    return GJUMP0(0x060266E6);
}

void f06024168(void)
{
    GJUMP4(0x06015012, 4, 2, 0x900, 0x00014000);
}

int f0602428A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32(sp - 4, r4);
    r0 = LD32(sp - 4);
    r4 = LD32(0x060D7B3C);
    if (!((r0 & r0) == 0)) {
        ST16(70 + r4, 0x200);
        ST16(68 + r4, 0x200);
        r5 = LD32(sp - 4);
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 22);
        UNFRAME(sp);
        SETSP(sp);
        r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), r5);
        return r0;
    } else {
        ST16(70 + r4, 0);
        r0 = 68;
        ST16(68 + r4, 0);
        return r0;
    }
}

int f060242C2(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    r2 = LD32(0x060D7768);
    r4 = LD32(0x060D7B3C);
    r4 = LD16(48 + r4);
    r0 = LD8(r2 + 6);
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP1(0x0602428A, ((r4 & 0xFFFF) + (r0 & 255)));
    return r0;
}

int f0602439C(gaddr obj, int index)
{
    ST8(obj + 4, LD8(obj + 4) | 64);
    ST8(0x060E1A98 + index, 10);
    return 0x060E1A98;
}

int f06024752(unsigned int cell)
{
    unsigned int col = cell >> 6;

    if ((LDU16(0x060EE8B0 + cell * 2) & 255) == 13)
        return 1;
    return col <= LDU16(0x060D7E7E) + 4u || col >= LDU16(0x060D7E82) - 2u;
}

void f060247D8(void)
{
    gaddr obj;
    gaddr row;
    gaddr mover;
    int target;

    GCALL2(0x06008A6A, 8, 1);
    GCALL2(0x06022F1C, 0, 0x060248E0);
    TSET(h10, LD16(LD32(CURRENT) + 20));
    TSET(h12, LDU8(LD32(CURRENT) + 6) - 1);
    TSET(h14, 0);
    GCALL2(0x0606AAC8, LD32(TASK_OBJ), 6);
    mover = LD32(MOVER_PTR);
    target = TGET(h12) == 3 ? LD16(mover + 4) - 1 : LD16(mover + 4) + 1;
    GCALL2(0x06069462, (short)TGET(h8), target);
    obj = LD32(TASK_OBJ);
    ST16(obj + 46, 10);
    row = 0x060B4D38 + TGET(h12) * 16;
    ST16(obj + 20, LD16(mover + 16) + LD16(row));
    ST16(obj + 24, LD16(row + 2) + LD16(mover + 16));
    ST16(obj + 22, LD16(row + 4) + LD16(mover + 18));
    ST16(obj + 26, LD16(row + 6) + LD16(mover + 18));
    ST16(obj + 28, LD16(row + 8) + LD16(mover + 16));
    ST16(obj + 32, LD16(row + 10) + LD16(mover + 16));
    ST16(obj + 30, LD16(row + 12) + LD16(mover + 18));
    ST16(obj + 34, LD16(row + 14) + LD16(mover + 18));
    GJUMP1(0x0600996A, 243);
}

int f060248E0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);
    SETSP(sp - 12);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 14);
    if (!((r0 & 0xFFFF) >= 24)) {
        r0 = LD16(r4 + 12);
        r4 = 0x060D7E64;
        r3 = LD32(0x060D7E64);
        r5 = ((r0 & 0xFFFF) << 1) << 1;
        r0 = LD16(r3 + 28);
        r5 = r5 + 0x060B4D78;
        r1 = LD16(r5);
        ST16(r3 + 28, (r0 + r1));
        r1 = LD16(r5);
        r3 = LD32(0x060D7E64);
        r2 = LD16(32 + r3);
        ST16(32 + r3, (r2 + r1));
        r3 = LD32(0x060D7E64);
        r2 = r5 + 2;
        ST32(sp - 12, r2);
        r1 = LD16(r2);
        r0 = LD16(r3 + 30);
        ST16(r3 + 30, (r0 + r1));
        r2 = LD32(sp - 12);
        r3 = LD32(0x060D7E64);
        r2 = LD16(r2);
        r1 = LD16(34 + r3);
        ST16(34 + r3, (r1 + r2));
        r6 = LD32(r14);
        r0 = LD16(r6 + 14);
        r6 = r0;
        if (!(((r6 & 0xFFFF) & (r6 & 0xFFFF)) == 0)) {
            if (((r6 & 0xFFFF) & 3) == 0) {
                r3 = LD32(r4);
                r2 = LD16(r5);
                r0 = LD16(r3 + 20);
                ST16(r3 + 20, (r0 + r2));
                r3 = LD32(r4);
                r2 = LD16(r5);
                r0 = LD16(r3 + 24);
                ST16(r3 + 24, (r0 + r2));
                r3 = LD32(r4);
                r2 = LD32(sp - 12);
                r2 = LD16(r2);
                r0 = LD16(r3 + 22);
                ST16(r3 + 22, (r0 + r2));
                r3 = LD32(r4);
                r2 = LD32(sp - 12);
                r2 = LD16(r2);
                r0 = LD16(r3 + 26);
                ST16(r3 + 26, (r0 + r2));
            }
        }
        r0 = LD32(r14);
        r0 = LD16(r0 + 14);
        if ((r0 & 0xFFFF) == 2) {
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x060249FC);
            r0 = GCALL0(0x06024A0C);
        }
        r3 = LD32(r14);
        r0 = LD16(r3 + 14);
        r0 = r0 + 1;
        ST16(r3 + 14, r0);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        SETSP(sp);
        r0 = GJUMP0(0x06022F14);
        return r0;
    }
}

int f06024A0C(void)
{
    int r0, r2, r3, r4, r5, r12;
    ENTRY_SP(sp);
    SETSP(sp - 20);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r12 = LD32(0x060D7E60);
    r3 = LD32(0x060D7E64);
    ST32(sp - 20, r3);
    SETSP((sp - 20));
    r0 = GCALL2(0x06008A6A, 8, 1);
    SETSP((sp - 20));
    r0 = GCALL2(0x06022F1C, 1, 0x06024AE4);
    r3 = LD32(0x060D7E60);
    r0 = LD16(r12 + 12);
    ST16(r3 + 12, r0);
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 12);
    r2 = LD16(((r0 & 0xFFFF) << 1) + 0x060B4D88);
    r0 = LD16(r12 + 10);
    ST16(r3 + 10, (r0 + r2));
    r3 = LD32(0x060D7E60);
    ST16(r3 + 14, 0);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 20));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    r5 = LD32(0x060D7E60);
    r0 = LD16(r5 + 10);
    r4 = LD32(0x060D7E60);
    r5 = r0;
    r0 = LD16(r4 + 8);
    SETSP((sp - 20));
    r0 = GCALL2(0x0600D148, r0, r5);
    r2 = LD32(0x060D7E64);
    ST16(68 + r2, 0x200);
    r3 = LD32(0x060D7E64);
    ST16(70 + r3, 0x200);
    r3 = LD32(0x060D7E64);
    ST16(46 + r3, 0);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 20));
    r0 = GCALL2(0x06069462, r0, 11);
    r5 = LD32(0x060D7E60);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r5 + 12);
    r5 = LD16(0x060B4D10 + ((r0 & 0xFFFF) << 1));
    r0 = LD16(r4 + 8);
    SETR(12, r12);
    SETR(13, 0x060D7E64);
    SETR(14, 0x060D7E60);
    SETSP((sp - 20));
    SETPR(0x06024AA0);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    ST32(0x060D7E60, r12);
    r2 = LD32(sp - 20);
    ST32(0x060D7E64, r2);
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06024C76(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);
    SETSP(sp - 20);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32(sp - 16, r4);
    ST32(sp - 20, r5);
    SETSP((sp - 20));
    r0 = GCALL2(0x06022F9C, 0, 3);
    ST32(sp - 12, r0);
    if ((unsigned)r0 > (unsigned)3) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 20));
        r0 = GCALL1(0x06008A96, 1);
        SETSP((sp - 20));
        SETPR(0x06024C9C);
        r0 = GCALL1(0x06068BDC, 85);
        SETSP((sp - 20));
        r0 = GCALL2(0x06008ECA, 23, 0x380);
        r4 = LD32(sp - 12);
        SETSP((sp - 20));
        r0 = GCALL2(0x06022F1C, r4, 0x06024DF8);
        SETSP((sp - 20));
        r0 = GCALL0(0x0600BD74);
        r6 = LD32(sp - 20);
        r3 = LD16(0x060D7EB6);
        r5 = LD32(sp - 16);
        r1 = LD16(0x060D7EB4);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 20));
        r0 = GCALL3(0x0600D0E4, r0, (r5 + r1), (r6 + r3));
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 20));
        r0 = GCALL2(0x0606AB08, (r0 & 0xFFFF), 3);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        ST16(0x060C1AA8, r0);
        SETR(14, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x06024CEC);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 85);
        r3 = LD32(0x060D7E64);
        ST16(46 + r3, 0x380);
        r3 = LD32(0x060D7E64);
        ST16(68 + r3, 0);
        SETSP((sp - 20));
        r0 = GCALL0(0x06024D78);
        r1 = LD32(0x060D7E60);
        ST16((16 + r1), 0);
        ST16(r1 + 14, 0);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        SETSP(sp);
        r0 = GJUMP1(0x0600996A, 247);
        return r0;
    }
}

void f06024D78(void)
{
    int tries = 0;

    TSET(h10, GCALL0(0x0600A0B8) & 3);
    TSET(h12, 32);
    GCALL0(0x0600CA7C);
    do {
        int cell = LDU16(0x060D7E8C) + LD16(0x060B47F0 + (TGET(h10) + 1) * 2);

        if (!(LDU16(FLAGS_AT(cell)) & 128)) {
            TSET(h10, LD16(LD32(TASK_PTR) + 10) + 1);
            return;
        }
        TSET(h10, (LD16(LD32(TASK_PTR) + 10) + 1) & 3);
    } while (AGAIN(++tries < 4));
    TSET(h12, 0);
    TSET(h10, 0);
}

int f06024DF8(void)
{
    gaddr obj = LD32(TASK_OBJ);

    if (LDU16(obj + 68) >= 0x100) {
        ST16(obj + 68, 0x100);
        TSET(h4, 30);
        TSET(fn, 0x06024E88);
        return 30;
    }
    ST16(obj + 68, LD16(obj + 68) + 4);
    return 68;
}

int f06024E88(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 16);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r12 = 0x100;
    r13 = 0x060D7E64;
    r0 = LD8(0x060C1004);
    if ((r0 & r0) == 0) {
        SETSP((sp - 16));
        r0 = GCALL0(0x0600CA7C);
        r0 = LD16((r0 << 1) + 0x060EC8B0);
        if (((r0 & 0xFFFF) & 128) == 0) {
            r0 = LD16(0x060D7E68);
            if (!(((r0 & 0xFFFF) & 64) == 0)) {
                r2 = LD32(r13);
                r3 = LD16(70 + r2);
                if (!((r3 & 0xFFFF) > r12)) {
                    r0 = 70;
                    r2 = LD32(r13);
                    r3 = LD16(70 + r2);
                    ST16(70 + r2, (r3 - 8));
                    r2 = LD32(r13);
                    r3 = LD16(70 + r2);
                    if ((r3 & 0xFFFF) >= 16) {
                        SETPR(LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        SETPR(LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        SETSP(sp);
                        r0 = GJUMP0(0x06022F14);
                        return r0;
                    }
                } else {
                    r0 = 70;
                    r2 = LD32(r13);
                    ST16(70 + r2, r12);
                    SETPR(LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                }
            } else {
                SETR(12, r12);
                SETR(13, r13);
                SETSP((sp - 16));
                SETPR(0x06024EC4);
                r0 = GCALL0(0x06024E28);
                r14 = 0x060D7E60;
                r4 = LD32(0x060D7E60);
                r0 = LD16(r4 + 16);
                if ((r0 & r0) == 0) {
                    r0 = LD16(r4 + 12);
                    if ((r0 & r0) == 0) {
                        SETSP((sp - 16));
                        r0 = GCALL0(0x06024D78);
                    }
                    r0 = LD32(r14);
                    r0 = LD16(r0 + 10);
                    r0 = r0 & 0xFFFF;
                    if (r0 == 1) {
                        r4 = 8;
                        SETSP((sp - 16));
                        r0 = GCALL1(0x0600A2B0, r4);
                    } else {
                        if (r0 == 2) {
                            r4 = 8;
                            SETSP((sp - 16));
                            r0 = GCALL1(0x0600A32A, r4);
                        } else {
                            if (r0 == 3) {
                                r4 = 248;
                                SETSP((sp - 16));
                                r0 = GCALL1(0x0600A2B0, r4);
                            } else {
                                if (r0 == 4) {
                                    r4 = 248;
                                    SETSP((sp - 16));
                                    r0 = GCALL1(0x0600A32A, r4);
                                }
                            }
                        }
                    }
                    SETSP((sp - 16));
                    r0 = GCALL0(0x0600D1A6);
                    SETSP((sp - 16));
                    r0 = GCALL0(0x060694B8);
                    SETSP((sp - 16));
                    r0 = GCALL0(0x0600D290);
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 12);
                    ST16(r2 + 12, (r0 - 1));
                }
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 16));
                SETPR(0x06024F2C);
                r0 = GCALL0(0x06024E28);
                r2 = LD32(r14);
                r0 = LD16(r2 + 14);
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 14);
                    if (!((r0 & r0) == 0)) {
                        r3 = LD32(r14);
                        r0 = LD16(r3 + 14);
                        ST16(r3 + 14, (r0 - 1));
                    }
                    r3 = LD32(r14);
                    r0 = LD16(r3 + 16);
                    if ((r0 & 0xFFFF) >= r12) {
                        r2 = LD32(r14);
                        r0 = LD16(r2 + 14);
                        if ((r0 & r0) == 0) {
                            r3 = LD32(r14);
                            ST16(r3 + 16, 0);
                        }
                    } else {
                        r2 = LD32(r14);
                        r0 = LD16(r2 + 16);
                        ST16(r2 + 16, (r0 + 8));
                    }
                } else {
                    r3 = LD32(r14);
                    r0 = LD16(r3 + 16);
                    if (!((r0 & r0) == 0)) {
                        r2 = LD32(r14);
                        r0 = LD16(r2 + 14);
                        if (!((r0 & r0) == 0)) {
                            r3 = LD32(r14);
                            r0 = LD16(r3 + 14);
                            ST16(r3 + 14, (r0 - 1));
                        }
                        r3 = LD32(r14);
                        r0 = LD16(r3 + 16);
                        if ((r0 & 0xFFFF) >= r12) {
                            r2 = LD32(r14);
                            r0 = LD16(r2 + 14);
                            if ((r0 & r0) == 0) {
                                r3 = LD32(r14);
                                ST16(r3 + 16, 0);
                            }
                        } else {
                            r2 = LD32(r14);
                            r0 = LD16(r2 + 16);
                            ST16(r2 + 16, (r0 + 8));
                        }
                    }
                }
                r3 = LD32(r13);
                r2 = LD32(r14);
                r0 = LD16(r2 + 16);
                r0 = r0 + r12;
                ST16((70 + r3), r0);
                SETPR(LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            }
        } else {
            r2 = LD32(r13);
            r3 = LD16(70 + r2);
            if (!((r3 & 0xFFFF) > r12)) {
                r0 = 70;
                r2 = LD32(r13);
                r3 = LD16(70 + r2);
                ST16(70 + r2, (r3 - 8));
                r2 = LD32(r13);
                r3 = LD16(70 + r2);
                if ((r3 & 0xFFFF) >= 16) {
                    SETPR(LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    SETPR(LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    SETSP(sp);
                    r0 = GJUMP0(0x06022F14);
                    return r0;
                }
            } else {
                r0 = 70;
                r2 = LD32(r13);
                ST16(70 + r2, r12);
                SETPR(LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            }
        }
    } else {
        r2 = LD32(r13);
        r3 = LD16(70 + r2);
        if (!((r3 & 0xFFFF) > r12)) {
            r0 = 70;
            r2 = LD32(r13);
            r3 = LD16(70 + r2);
            ST16(70 + r2, (r3 - 8));
            r2 = LD32(r13);
            r3 = LD16(70 + r2);
            if ((r3 & 0xFFFF) >= 16) {
                SETPR(LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                SETPR(LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                SETSP(sp);
                r0 = GJUMP0(0x06022F14);
                return r0;
            }
        } else {
            r0 = 70;
            r2 = LD32(r13);
            ST16(70 + r2, r12);
            SETPR(LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        }
    }
}

int f06024FEE(int r4, int r5)
{
    int r0, r1, r3, r6, r8;
    ENTRY_SP(sp);
    SETSP(sp - 24);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    ST32(sp - 20, r4);
    ST32(sp - 24, r5);
    SETSP((sp - 24));
    r0 = GCALL2(0x06022F9C, 2, 9);
    ST32(sp - 16, r0);
    if (!((unsigned)r0 > (unsigned)9)) {
        SETSP((sp - 24));
        r0 = GCALL1(0x06008A96, 0);
        SETSP((sp - 24));
        SETPR(0x06025016);
        r0 = GCALL1(0x06068BDC, 57);
        SETSP((sp - 24));
        r0 = GCALL2(0x06008ECA, 23, 0x390);
        r4 = LD32(sp - 16);
        SETSP((sp - 24));
        r0 = GCALL2(0x06022F1C, r4, 0x0602512E);
        SETSP((sp - 24));
        r0 = GCALL0(0x0600BD74);
        r6 = LD32(sp - 24);
        r5 = LD32(sp - 20);
        r3 = LD16(0x060D7EB6);
        r4 = LD32(0x060D7E60);
        r1 = LD16(0x060D7EB4);
        r0 = LD16(r4 + 8);
        SETSP((sp - 24));
        r0 = GCALL3(0x0600D0E4, r0, (r5 + r1), (r6 + r3));
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 24));
        r0 = GCALL2(0x06069462, r0, 12);
        SETR(14, 0x060D7E60);
        SETSP((sp - 24));
        SETPR(0x0602505A);
        r0 = GCALL0(0x0602511A);
        r3 = LD32(0x060D7E64);
        ST16(46 + r3, 0x390);
        r8 = LD32(0x060D7E60);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 24));
        r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
        r3 = (r0 & 0xFFFF) << 1;
        ST16((r8 + 10), r0);
        r1 = LD16(0x060EC8B0 + r3);
        ST16(0x060EC8B0 + r3, (r1 | 0xA00));
        r3 = LD16(0x060D7E8C);
        r0 = 0x060EE8B0;
        r3 = (r3 & 0xFFFF) << 1;
        r1 = LD16(0x060EE8B0 + r3);
        ST16(0x060EE8B0 + r3, (r1 | 18));
    }
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0602510C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP2(0x06068ACC, (r0 & 0xFFFF), 57);
    return r0;
}

int f0602511A(void)
{
    int r0, r2;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06025120);
    r0 = GCALL0(0x0602510C);
    SETPR(LD32((sp - 4)));
    r2 = LD32(0x060D7E64);
    ST16(62 + r2, 0);
    return 62;
}

int f06025208(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8;
    ENTRY_SP(sp);
    SETSP(sp - 28);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    ST32(sp - 20, r4);
    ST32(sp - 28, r5);
    ST32(sp - 24, r6);
    SETSP((sp - 28));
    r0 = GCALL2(0x06022F9C, 10, 15);
    ST32(sp - 16, r0);
    if (!((unsigned)r0 > (unsigned)15)) {
        SETSP((sp - 28));
        r0 = GCALL1(0x06008A96, 0);
        SETSP((sp - 28));
        SETPR(0x06025234);
        r0 = GCALL1(0x060689F8, 0x060B4DA0);
        SETSP((sp - 28));
        r0 = GCALL2(0x06008ECA, 23, 0x390);
        r4 = LD32(sp - 16);
        SETSP((sp - 28));
        r0 = GCALL2(0x06022F1C, r4, 0x06025374);
        SETSP((sp - 28));
        r0 = GCALL0(0x0600BD74);
        r6 = LD32(sp - 28);
        r3 = LD16(0x060D7EB6);
        r5 = LD32(sp - 20);
        r1 = LD16(0x060D7EB4);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL3(0x0600D0E4, r0, (r5 + r1), (r6 + r3));
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL2(0x06069462, r0, 9);
        r2 = LD32(0x060D7E64);
        ST16(46 + r2, 0x390);
        r8 = LD32(0x060D7E60);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
        ST16((r8 + 10), r0);
        r3 = LD32(0x060D7E60);
        r0 = LD16(sp - 22);
        ST16(r3 + 12, (r0 + 0xFFFF));
        SETR(14, 0x060D7E60);
        SETSP((sp - 28));
        SETPR(0x0602529C);
        r0 = GCALL0(0x06025498);
        SETSP((sp - 28));
        r0 = GCALL0(0x060254C0);
        r5 = LD32(0x060D7E60);
        r0 = LD16(r5 + 10);
        r5 = (r0 & 0xFFFF) << 1;
        r7 = LD32(0x060D7E60);
        r4 = 0x060EC8B0 + r5;
        r6 = 0x060EE8B0 + r5;
        r0 = LD16(r7 + 12);
        r7 = LD16(0x060B4D98 + ((r0 & 0xFFFF) << 1));
        r0 = r4;
        r5 = r7 << 1;
        r2 = LD16(r0 + r5);
        ST16(r0 + r5, (r2 | 0x800));
        r0 = LD16(r4);
        r2 = r4 - r5;
        ST16(r4, (r0 | 128));
        r1 = LD16(r2);
        r0 = r6;
        ST16(r2, (r1 | 0x800));
        r1 = LD16(r0 + r5);
        ST16(r0 + r5, (r1 | 17));
        r0 = LD16(r6);
        r1 = r6 - r5;
        ST16(r6, (r0 | 17));
        r0 = LD16(r1);
        r0 = r0 | 17;
        ST16(r1, r0);
    }
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06025374(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 12);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 10);
    r7 = r0 & 0xFFFF;
    r0 = LD16(r4 + 12);
    r5 = r0 & 0xFFFF;
    r0 = 0x060B4D98;
    r5 = LD16(0x060B4D98 + (r5 << 1));
    r6 = ((r7 + r5) << 1) + 0x060EC8B0;
    r7 = r7 - r5;
    r5 = 128;
    r4 = 0x060EC8B0 + (r7 << 1);
    r2 = LD16(r4);
    if (!(((r2 & 0xFFFF) & 128) == 0)) {
        r1 = LD16(r4);
        if (((r1 & 0xFFFF) & r5) == 0) {
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r3 = LD16(r6);
            if (((r3 & 0xFFFF) & r5) == 0) {
                SETPR(LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                SETPR(LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                SETSP(sp);
                r0 = GJUMP0(0x06022F14);
                return r0;
            }
        }
    } else {
        r3 = LD16(r6);
        if (!(((r3 & 0xFFFF) & r5) == 0)) {
            r1 = LD16(r4);
            if (((r1 & 0xFFFF) & r5) == 0) {
                SETPR(LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                r3 = LD16(r6);
                if (((r3 & 0xFFFF) & r5) == 0) {
                    SETPR(LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    SETPR(LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    SETSP(sp);
                    r0 = GJUMP0(0x06022F14);
                    return r0;
                }
            }
        } else {
            r0 = LD16(0x060D7E68);
            r0 = r0 & 0xFFFF;
            if (!((r0 & 64) == 0)) {
                r1 = LD16(r4);
                if (((r1 & 0xFFFF) & r5) == 0) {
                    SETPR(LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    r3 = LD16(r6);
                    if (((r3 & 0xFFFF) & r5) == 0) {
                        SETPR(LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        SETPR(LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        SETSP(sp);
                        r0 = GJUMP0(0x06022F14);
                        return r0;
                    }
                }
            } else {
                r14 = 0x060D7E64;
                r0 = LD16(r4);
                if (!(((r0 & 0xFFFF) & 32) == 0)) {
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 12));
                    SETPR(0x060253D6);
                    r0 = GCALL0(0x06025498);
                    r1 = LD32(r14);
                    ST16(60 + r1, 0);
                    r2 = LD32(r14);
                    ST16(62 + r2, 0x100);
                    r3 = LD32(r13);
                    r0 = LD16(r3 + 12);
                    ST16(r3 + 12, (r0 ^ 2));
                    r3 = LD32(r13);
                    ST32(r3, 0x0602543E);
                    SETSP((sp - 12));
                    r0 = GCALL1(0x0600996A, 254);
                } else {
                    r3 = LD16(0x060EE8B0 + (r7 << 1));
                    if (!(((r3 & 0xFFFF) & 0x3000) == 0)) {
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 12));
                        SETPR(0x060253D6);
                        r0 = GCALL0(0x06025498);
                        r1 = LD32(r14);
                        ST16(60 + r1, 0);
                        r2 = LD32(r14);
                        ST16(62 + r2, 0x100);
                        r3 = LD32(r13);
                        r0 = LD16(r3 + 12);
                        ST16(r3 + 12, (r0 ^ 2));
                        r3 = LD32(r13);
                        ST32(r3, 0x0602543E);
                        SETSP((sp - 12));
                        r0 = GCALL1(0x0600996A, 254);
                    }
                }
                r2 = LD32(r14);
                r0 = LD16(62 + r2);
                if ((r0 & r0) == 0) {
                    SETPR(LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    r0 = 60;
                    r3 = LD32(r14);
                    r2 = LD16(60 + r3);
                    if (!((r2 & 0xFFFF) == 0xFF00)) {
                        SETPR(LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        SETPR(LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        SETSP(sp);
                        r0 = GJUMP0(0x06025498);
                        return r0;
                    }
                }
            }
        }
    }
}

int f0602543E(void)
{
    int r0, r2;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x060254C0);
    SETSP((sp - 4));
    r0 = GCALL2(0x0600CDC4, r0, 0x4000);
    SETSP((sp - 4));
    SETPR(0x06025450);
    r0 = GCALL0(0x06025504);
    r2 = LD32(0x060D7E60);
    SETPR(LD32((sp - 4)));
    ST32(r2, 0x06025374);
    return r0;
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
    GCALL2(0x0600C7BE, (short)TGET(h14) + shift, (short)TGET(h12));
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

int f060257A0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8;
    ENTRY_SP(sp);
    SETSP(sp - 28);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    ST32(sp - 20, r4);
    ST32(sp - 24, r5);
    ST32(sp - 28, r6);
    SETSP((sp - 28));
    r0 = GCALL2(0x06022F9C, 10, 30);
    ST32(sp - 16, r0);
    if (!((unsigned)r0 > (unsigned)30)) {
        SETSP((sp - 28));
        r0 = GCALL1(0x06008A96, 1);
        SETSP((sp - 28));
        SETPR(0x060257CC);
        r0 = GCALL1(0x060689F8, 0x060B4DAA);
        SETSP((sp - 28));
        r0 = GCALL2(0x06008ECA, 26, 0x3C0);
        r4 = LD32(sp - 16);
        SETSP((sp - 28));
        r0 = GCALL2(0x06022F1C, r4, 0x06025B46);
        SETSP((sp - 28));
        r0 = GCALL0(0x0600BD74);
        r6 = LD32(sp - 24);
        r3 = LD16(0x060D7EB6);
        r5 = LD32(sp - 20);
        r1 = LD16(0x060D7EB4);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL3(0x0600D0E4, r0, (r5 + r1), (r6 + r3));
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL2(0x06069462, r0, 12);
        r2 = LD32(0x060D7E64);
        ST16(46 + r2, 0x3C0);
        r8 = LD32(0x060D7E60);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
        ST16((r8 + 10), r0);
        r3 = LD32(0x060D7E60);
        r0 = LD16(sp - 26);
        ST16(r3 + 14, r0);
        r3 = LD32(0x060D7E60);
        ST16(r3 + 18, 255);
        r3 = LD32(0x060D7E60);
        ST16(r3 + 20, 0);
        SETR(14, 0x060D7E60);
        SETSP((sp - 28));
        SETPR(0x0602583C);
        r0 = GCALL1(0x060258DC, 0);
        r3 = LD32(0x060D7E60);
        r0 = LD16(r3 + 10);
        r3 = (r0 & 0xFFFF) << 1;
        r1 = LD16(0x060EC8B0 + r3);
        ST16(0x060EC8B0 + r3, (r1 | 0x800));
        r3 = LD32(0x060D7E60);
        r0 = LD16(r3 + 10);
        r3 = (r0 & 0xFFFF) << 1;
        r0 = LD16(0x060EE8B0 + r3);
        r0 = r0 | 19;
        ST16((0x060EE8B0 + r3), r0);
    }
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060258DC(int r4)
{
    int r0, r2, r3, r5, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 16);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    r13 = r4;
    r14 = 0x060D7E60;
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r3 = LD32(0x060D7E60);
    ST16(r3 + 16, r4);
    r12 = LD32(0x060D7E60);
    r0 = LD16(r12 + 14);
    r12 = LD16(0x060B4DC4 + (((r0 & 0xFFFF) - 1) << 1));
    if (!((r13 & r13) == 0)) {
        r0 = LD32(r14);
        r12 = r12 + 1;
        r0 = LD16(r0 + 14);
        r13 = (((r13 - 1) << 2) + (((r0 & 0xFFFF) - 1) ^ 2)) + 93;
    }
    r4 = LD32(r14);
    r0 = LD16(r4 + 8);
    SETR(12, r12);
    SETR(14, r14);
    SETSP((sp - 16));
    SETPR(0x06025924);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r13);
    SETSP((sp - 16));
    r0 = GCALL0(0x0600C434);
    r5 = LD32(r14);
    r0 = LD16(r5 + 10);
    SETSP((sp - 16));
    r0 = GCALL2(0x0600C7BE, r12, r0);
    r2 = LD32(r14);
    ST16(r2 + 12, 0);
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
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

int f06025A54(void)
{
    gaddr rec = REC(TGET(h18));
    int along;

    ST32(CURRENT, rec);
    if (!(TGET(h14) & 1)) {
        along = LDU16(rec + 28) & 15;
        if (along)
            return along >= 8 ? 2 : 4;
        return LDU16(FLAGS_AT(LDU16(rec + 20) - 64)) & LDU16(rec + 18) ? 4 : 2;
    }
    along = LDU16(rec + 24) & 15;
    if (along)
        return along >= 8 ? 1 : 3;
    return LDU16(FLAGS_AT(LDU16(rec + 20) - 1)) & LDU16(rec + 18) ? 3 : 1;
}

int f06025B46(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 36);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(8));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 10);
    r10 = r0 & 0xFFFF;
    r12 = (r10 << 1) + 0x060EC8B0;
    r0 = LD16(r12);
    if (!(((r0 & 0xFFFF) & 128) == 0)) {
        SETMACL(LD32((sp - 32)));
        SETPR(LD32((sp - 28)));
        SETR(8, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        SETSP(sp);
        r0 = GJUMP0(0x06022F14);
        return r0;
    } else {
        r0 = LD16(0x060D7E68);
        if (((r0 & 0xFFFF) & 64) == 0) {
            r11 = 191;
            r13 = 0x060D7768;
            r0 = LD16(r4 + 16);
            r0 = r0 & 0xFFFF;
            if (r0 == 0) {
                r3 = LD16(r12);
                if (!(((r3 & 0xFFFF) & r11) == 0)) {
                    r2 = LD32(r14);
                    ST16(r2 + 12, 0);
                    r3 = LD32(r14);
                    r0 = 255;
                    ST16(r3 + 18, 255);
                    SETMACL(LD32((sp - 32)));
                    SETPR(LD32((sp - 28)));
                    SETR(8, LD32((sp - 24)));
                    SETR(10, LD32((sp - 20)));
                    SETR(11, LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    SETSP((sp - 36));
                    r0 = GCALL0(0x06025946);
                    ST32(sp - 36, r0);
                    if ((r0 & r0) == 0) {
                        r2 = LD32(r14);
                        ST16(r2 + 12, 0);
                        r3 = LD32(r14);
                        r0 = 255;
                        ST16(r3 + 18, 255);
                        SETMACL(LD32((sp - 32)));
                        SETPR(LD32((sp - 28)));
                        SETR(8, LD32((sp - 24)));
                        SETR(10, LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        r3 = LD32(r14);
                        r0 = LD16(sp - 34);
                        ST16(r3 + 18, (r0 + 0xFFFF));
                        r3 = LD32(r14);
                        r0 = LD16(r3 + 12);
                        if (!((r0 & 0xFFFF) >= 45)) {
                            r1 = LD32(r14);
                            r0 = LD16(r1 + 12);
                            r0 = r0 + 1;
                            ST16(r1 + 12, r0);
                            SETMACL(LD32((sp - 32)));
                            SETPR(LD32((sp - 28)));
                            SETR(8, LD32((sp - 24)));
                            SETR(10, LD32((sp - 20)));
                            SETR(11, LD32((sp - 16)));
                            SETR(12, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        } else {
                            r8 = LD32(r14);
                            SETSP((sp - 36));
                            r0 = GCALL0(0x06025A54);
                            ST16((r8 + 14), r0);
                            r0 = LD32(r14);
                            r0 = LD16(r0 + 14);
                            r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060B47F0);
                            r0 = r0 << 1;
                            r3 = LD16((r12 - r0));
                            if (((r3 & 0xFFFF) & r11) == 0) {
                                SETR(10, r10);
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 36));
                                SETPR(0x06025C24);
                                r0 = GCALL1(0x060258DC, 1);
                                SETSP((sp - 36));
                                r0 = GCALL2(0x0600CDC4, r10, 0x608);
                                r3 = LD32(r14);
                                r0 = LD16(r3 + 18);
                                r0 = ((r0 & 0xFFFF) * 124) + 0x060D5F30;
                                ST32(r13, r0);
                                r0 = LD16(r0 + 22);
                                ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
                                r3 = LD32(r13);
                                r1 = LD16(46 + r3);
                                ST16(46 + r3, (r1 | 0x2000));
                                r3 = LD32(r13);
                                r0 = LD32(r14);
                                r0 = LD8(r0 + 15);
                                ST8(r3 + 6, r0);
                                SETR(13, r13);
                                SETSP((sp - 36));
                                SETPR(0x06025C6E);
                                r0 = GCALL1(0x060165B8, 0x2710);
                                r4 = LD32(r13);
                                r0 = LD8(r4 + 6);
                                SETSP((sp - 36));
                                r0 = GCALL1(0x06016776, (r0 & 255));
                                SETMACL(LD32((sp - 32)));
                                SETPR(LD32((sp - 28)));
                                SETR(8, LD32((sp - 24)));
                                SETR(10, LD32((sp - 20)));
                                SETR(11, LD32((sp - 16)));
                                SETR(12, LD32((sp - 12)));
                                SETR(13, LD32((sp - 8)));
                                SETR(14, LD32((sp - 4)));
                                UNFRAME(sp);
                                SETSP(sp);
                                r0 = GJUMP1(0x0600996A, 252);
                                return r0;
                            } else {
                                SETMACL(LD32((sp - 32)));
                                SETPR(LD32((sp - 28)));
                                SETR(8, LD32((sp - 24)));
                                SETR(10, LD32((sp - 20)));
                                SETR(11, LD32((sp - 16)));
                                SETR(12, LD32((sp - 12)));
                                SETR(13, LD32((sp - 8)));
                                SETR(14, LD32((sp - 4)));
                                return r0;
                            }
                        }
                    }
                }
            } else {
                if (!(r0 == 1)) {
                    if (!(r0 == 3)) {
                        SETMACL(LD32((sp - 32)));
                        SETPR(LD32((sp - 28)));
                        SETR(8, LD32((sp - 24)));
                        SETR(10, LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        r0 = 60;
                        r2 = LD32(0x060D7E64);
                        r1 = LD16(60 + r2);
                        if (!((r1 & 0xFFFF) == 0xFF00)) {
                            SETMACL(LD32((sp - 32)));
                            SETPR(LD32((sp - 28)));
                            SETR(8, LD32((sp - 24)));
                            SETR(10, LD32((sp - 20)));
                            SETR(11, LD32((sp - 16)));
                            SETR(12, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        } else {
                            r4 = r12;
                            SETMACL(LD32((sp - 32)));
                            SETPR(LD32((sp - 28)));
                            SETR(8, LD32((sp - 24)));
                            SETR(10, LD32((sp - 20)));
                            SETR(11, LD32((sp - 16)));
                            SETR(12, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            POLL();
                            ST32((sp - 4), PR());
                            ST32((sp - 8), MACL());
                            r5 = LD32(0x060D7E60);
                            r0 = LD16(r5 + 18);
                            if (!((r0 & 0xFFFF) == 255)) {
                                r0 = LD16(r5 + 18);
                                r1 = (r0 & 0xFFFF) * 124;
                                r2 = LD16(0x060D5F5E + r1);
                                ST16(0x060D5F5E + r1, (r2 & 0xDFFF));
                                r1 = LD16(r4);
                                ST16(r4, (r1 & 0xF9F7));
                            }
                            SETSP((sp - 8));
                            SETPR(0x06025B36);
                            r0 = GCALL1(0x060258DC, 0);
                            r2 = LD32(0x060D7E60);
                            ST16(r2 + 18, 255);
                            SETMACL(LD32((sp - 8)));
                            SETPR(LD32((sp - 4)));
                            return 255;
                        }
                    }
                } else {
                    r0 = LD16(r4 + 14);
                    r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060B47F0);
                    r2 = LD16((r12 - (r0 << 1)));
                    if (!(((r2 & 0xFFFF) & r11) == 0)) {
                        r4 = r12;
                        SETMACL(LD32((sp - 32)));
                        SETPR(LD32((sp - 28)));
                        SETR(8, LD32((sp - 24)));
                        SETR(10, LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        POLL();
                        ST32((sp - 4), PR());
                        ST32((sp - 8), MACL());
                        r5 = LD32(0x060D7E60);
                        r0 = LD16(r5 + 18);
                        if (!((r0 & 0xFFFF) == 255)) {
                            r0 = LD16(r5 + 18);
                            r1 = (r0 & 0xFFFF) * 124;
                            r2 = LD16(0x060D5F5E + r1);
                            ST16(0x060D5F5E + r1, (r2 & 0xDFFF));
                            r1 = LD16(r4);
                            ST16(r4, (r1 & 0xF9F7));
                        }
                        SETSP((sp - 8));
                        SETPR(0x06025B36);
                        r0 = GCALL1(0x060258DC, 0);
                        r2 = LD32(0x060D7E60);
                        ST16(r2 + 18, 255);
                        SETMACL(LD32((sp - 8)));
                        SETPR(LD32((sp - 4)));
                        return 255;
                    } else {
                        r0 = LD16(r4 + 18);
                        ST32(r13, (((r0 & 0xFFFF) * 124) + 0x060D5F30));
                        r3 = LD32(r14);
                        r0 = LD16(r3 + 12);
                        if ((r0 & 0xFFFF) >= 12) {
                            r1 = LD32(r14);
                            r0 = LD16(r1 + 18);
                            r0 = (r0 & 0xFFFF) << 1;
                            r1 = LD16(r0 + 0x26006096);
                            if ((r1 & r1) == 0) {
                                SETMACL(LD32((sp - 32)));
                                SETPR(LD32((sp - 28)));
                                SETR(8, LD32((sp - 24)));
                                SETR(10, LD32((sp - 20)));
                                SETR(11, LD32((sp - 16)));
                                SETR(12, LD32((sp - 12)));
                                SETR(13, LD32((sp - 8)));
                                SETR(14, LD32((sp - 4)));
                                return r0;
                            } else {
                                r2 = LD32(r13);
                                r3 = LD16(46 + r2);
                                ST16(46 + r2, (r3 & 0xDFFF));
                                SETMACL(LD32((sp - 32)));
                                SETPR(LD32((sp - 28)));
                                SETR(8, LD32((sp - 24)));
                                SETR(10, LD32((sp - 20)));
                                SETR(11, LD32((sp - 16)));
                                SETR(12, LD32((sp - 12)));
                                SETR(13, LD32((sp - 8)));
                                SETR(14, LD32((sp - 4)));
                                UNFRAME(sp);
                                SETSP(sp);
                                r0 = GJUMP1(0x060258DC, 3);
                                return r0;
                            }
                        } else {
                            r3 = LD32(r13);
                            r0 = LD32(r14);
                            r0 = LD16(r0 + 14);
                            ST16((r3 + 86), ((((r0 + 0xFFFF) ^ 2) + 1) | 0x100));
                            r3 = LD32(r14);
                            r0 = LD16(r3 + 12);
                            r0 = r0 + 1;
                            ST16(r3 + 12, r0);
                            SETMACL(LD32((sp - 32)));
                            SETPR(LD32((sp - 28)));
                            SETR(8, LD32((sp - 24)));
                            SETR(10, LD32((sp - 20)));
                            SETR(11, LD32((sp - 16)));
                            SETR(12, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        }
                    }
                }
            }
        } else {
            SETMACL(LD32((sp - 32)));
            SETPR(LD32((sp - 28)));
            SETR(8, LD32((sp - 24)));
            SETR(10, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            SETSP(sp);
            r0 = GJUMP0(0x06022F14);
            return r0;
        }
    }
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

int f06025E7E(void)
{
    TSET(h10, TGET(h10) + 1);
    ST16(0x060DF97C, 1);
    GCALL1(0x0600AC1E, 32);
    if (TGET(h10) >= 0x258) {
        TSET(h10, 0);
        TSET(fn, 0x06025E3E);
        GCALL1(0x06009A3A, 246);
    }
    if (!(LDU16(0x060D7E68) & 64))
        return LDU16(0x060D7E68);
    ST16(0x060DF97C, 0);
    GCALL1(0x0600AC90, 32);
    GCALL2(0x0600A8F4, 32, 0x2000);
    return GJUMP0(0x06022F14);
}

void f06025FC0(int shift)
{
    GCALL0(0x0600C434);
    GJUMP2(0x0600C7BE, LD16(0x060B4DCC + TGET(h12) * 2) + shift, (short)TGET(h14));
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

int f0602620C(void)
{
    gaddr cur;
    int x;
    int y;
    gaddr cell;
    int i = 0;

    GCALL0(0x0600BD74);
    cur = LD32(CURRENT);
    x = (LDU16(cur + 24) >> 4) - LDU16(0x060D7EB4);
    y = (LDU16(LD32(CURRENT) + 28) >> 4) - LDU16(0x060D7EB6);
    for (cell = LD32(0x060C02CC); LD16(cell) != 0; cell += 4) {
        POLL();
        if (LDU16(cell) == x && LDU16(cell + 2) == y)
            return i + 1;
        i++;
    }
    return 0;
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

int f060262BC(void)
{
    int spot = GCALL0(0x0602620C);
    int entry;
    gaddr cell;

    if (spot == 0)
        return 0;
    entry = GCALL1(0x06026270, LD32(0x060C02D0) + (spot - 1) * 20) & 0xFFFF;
    if (entry == 0)
        return 0;
    cell = LD32(0x060C02CC) + (entry - 1) * 4;
    GCALL0(0x0600BD74);
    GCALL2(0x0600CA32, LDU16(cell) + LDU16(0x060D7EB4), LDU16(0x060D7EB6) + LDU16(cell + 2));
    return entry;
}

void f06026542(int n)
{
    int rec = 0x060D7B48 + (short)(n * 24);

    ST32(0x060D7E60, rec);
    ST32(0x060D7E64, OBJ(LDU16(rec + 8)));
}

void f06026570(void)
{
    TSET(h12, 1);
    ST16(LD32(TASK_OBJ) + 20, 0);
    ST16(LD32(TASK_OBJ) + 28, 0);
    ST16(LD32(TASK_OBJ) + 24, 0);
}

void f0602658A(int a)
{
    GCALL1(0x06026542, a);
    GJUMP0(0x06026570);
}

int f060265B4(int arg)
{
    gaddr obj;
    int y;

    GCALL1(0x06026542, arg);
    POLL();
    TSET(h12, 1);
    ST16(LD32(TASK_OBJ) + 20, 1);
    ST16(LD32(TASK_OBJ) + 28, 0);
    obj = LD32(TASK_OBJ);
    y = LD16(obj + 26) - 1;
    ST16(obj + 24, y);
    return y;
}

int f060265BE(void)
{
    int r0, r2, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 12);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060265C6);
    r0 = GCALL2(0x06026358, 0, 0x06017890);
    if (!((r0 & r0) == 0)) {
        SETSP((sp - 4));
        r0 = GCALL0(0x06026570);
    }
    SETPR(LD32((sp - 4)));
    POLL();
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060D7E60;
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 12);
    if (!((r0 & r0) == 0)) {
        r14 = 0x060D7E64;
        r4 = LD32(0x060D7E64);
        r0 = LD16(r4 + 28);
        if (!((r0 & r0) == 0)) {
            r0 = LD16(r4 + 28);
            r0 = r0 - 1;
            ST16(r4 + 28, r0);
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x0600C434);
            r4 = LD32(r13);
            r0 = LD16(r4 + 8);
            SETSP((sp - 12));
            r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
            r5 = r0;
            r4 = LD32(r14);
            r0 = LD16(r4 + 24);
            r3 = r0;
            r0 = LD16(r4 + 22);
            SETSP((sp - 12));
            r0 = GCALL2(0x0600C7BE, (r0 + r3), r5);
            r2 = LD32(r14);
            r0 = LD16(r2 + 20);
            r4 = 0;
            if (!((r0 & r0) == 0)) {
                r2 = LD32(r14);
                r0 = LD16(r2 + 24);
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 24);
                    ST16(r2 + 24, (r0 - 1));
                } else {
                    r3 = LD32(r13);
                    ST16(r3 + 12, r4);
                }
            } else {
                r3 = LD32(r14);
                r0 = LD16(r3 + 24);
                r2 = r0;
                r0 = LD16(r3 + 26);
                if (!(r2 >= (r0 - 1))) {
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 24);
                    ST16(r2 + 24, (r0 + 1));
                } else {
                    r2 = LD32(r13);
                    ST16(r2 + 12, r4);
                }
            }
            r3 = LD32(r14);
            r0 = LD16(r3 + 30);
            ST16(r3 + 28, r0);
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060265D2(void)
{
    int kind = LDU8(0x060C029D);

    if (kind == 1)
        ST32(0x060C02CC, 0x060B4DE4);
    else if (kind == 3)
        ST32(0x060C02CC, 0x060B4DF6);
    ST32(0x060C02D0, 0x060B4E08);
    return GCALL5(0x060260F8, 23, 88, 5, 4, 0x060265BE);
}

int f06026670(void)
{
    int r0, r2, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 12);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06026678);
    r0 = GCALL2(0x06026358, 0, 0x06017BC0);
    if (!((r0 & r0) == 0)) {
        SETSP((sp - 4));
        r0 = GCALL0(0x06026570);
    }
    SETPR(LD32((sp - 4)));
    POLL();
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060D7E60;
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 12);
    if (!((r0 & r0) == 0)) {
        r14 = 0x060D7E64;
        r4 = LD32(0x060D7E64);
        r0 = LD16(r4 + 28);
        if (!((r0 & r0) == 0)) {
            r0 = LD16(r4 + 28);
            r0 = r0 - 1;
            ST16(r4 + 28, r0);
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x0600C434);
            r4 = LD32(r13);
            r0 = LD16(r4 + 8);
            SETSP((sp - 12));
            r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
            r5 = r0;
            r4 = LD32(r14);
            r0 = LD16(r4 + 24);
            r3 = r0;
            r0 = LD16(r4 + 22);
            SETSP((sp - 12));
            r0 = GCALL2(0x0600C7BE, (r0 + r3), r5);
            r2 = LD32(r14);
            r0 = LD16(r2 + 20);
            r4 = 0;
            if (!((r0 & r0) == 0)) {
                r2 = LD32(r14);
                r0 = LD16(r2 + 24);
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 24);
                    ST16(r2 + 24, (r0 - 1));
                } else {
                    r3 = LD32(r13);
                    ST16(r3 + 12, r4);
                }
            } else {
                r3 = LD32(r14);
                r0 = LD16(r3 + 24);
                r2 = r0;
                r0 = LD16(r3 + 26);
                if (!(r2 >= (r0 - 1))) {
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 24);
                    ST16(r2 + 24, (r0 + 1));
                } else {
                    r2 = LD32(r13);
                    ST16(r2 + 12, r4);
                }
            }
            r3 = LD32(r14);
            r0 = LD16(r3 + 30);
            ST16(r3 + 28, r0);
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06026684(void)
{
    ST32(0x060C02CC, 0x060B4DF6);
    ST32(0x060C02D0, 0x060B4E08);
    return GCALL5(0x060260F8, 2, 24, 2, 4, 0x06026670);
}

int f060266A8(void)
{
    int r0, r2, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 12);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060266B0);
    r0 = GCALL2(0x06026358, 0, 0x06017BC0);
    if (!((r0 & r0) == 0)) {
        SETSP((sp - 4));
        r0 = GCALL0(0x06026570);
    }
    SETPR(LD32((sp - 4)));
    POLL();
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060D7E60;
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 12);
    if (!((r0 & r0) == 0)) {
        r14 = 0x060D7E64;
        r4 = LD32(0x060D7E64);
        r0 = LD16(r4 + 28);
        if (!((r0 & r0) == 0)) {
            r0 = LD16(r4 + 28);
            r0 = r0 - 1;
            ST16(r4 + 28, r0);
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x0600C434);
            r4 = LD32(r13);
            r0 = LD16(r4 + 8);
            SETSP((sp - 12));
            r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
            r5 = r0;
            r4 = LD32(r14);
            r0 = LD16(r4 + 24);
            r3 = r0;
            r0 = LD16(r4 + 22);
            SETSP((sp - 12));
            r0 = GCALL2(0x0600C7BE, (r0 + r3), r5);
            r2 = LD32(r14);
            r0 = LD16(r2 + 20);
            r4 = 0;
            if (!((r0 & r0) == 0)) {
                r2 = LD32(r14);
                r0 = LD16(r2 + 24);
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 24);
                    ST16(r2 + 24, (r0 - 1));
                } else {
                    r3 = LD32(r13);
                    ST16(r3 + 12, r4);
                }
            } else {
                r3 = LD32(r14);
                r0 = LD16(r3 + 24);
                r2 = r0;
                r0 = LD16(r3 + 26);
                if (!(r2 >= (r0 - 1))) {
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 24);
                    ST16(r2 + 24, (r0 + 1));
                } else {
                    r2 = LD32(r13);
                    ST16(r2 + 12, r4);
                }
            }
            r3 = LD32(r14);
            r0 = LD16(r3 + 30);
            ST16(r3 + 28, r0);
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060266BC(void)
{
    ST32(0x060C02CC, 0x060B4DF6);
    ST32(0x060C02D0, 0x060B4E08);
    return GCALL5(0x060260F8, 2, 162, 3, 4, 0x060266A8);
}

int f060266E0(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 56);

    r5 = 0x06017CD8;
    POLL();
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r10 = 0x060D7E60;
    ST32(sp - 52, r5);
    ST32(sp - 56, 0);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 56));
    r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
    ST32(sp - 48, r0);
    r3 = LD16((r0 << 1) + 0x060EE8B0);
    if (!(((r3 & 0xFFFF) & 0x1000) == 0)) {
        r0 = LD8(0x060C1004);
        if ((r0 & r0) == 0) {
            r12 = 15;
            r14 = 0x060D7768;
            r11 = 0;
            r13 = 8;
            r8 = 255;
            r9 = 0xFFFF;
            ST32(0x060D7768, 0x060D5F30);
            while (1) {
                r2 = LD8(0x060C063D);
                if (!((unsigned)r11 >= (unsigned)(r2 & 255))) {
                    POLL();
                    ST16(0x060C062C, r11);
                    r3 = LD32(r14);
                    r0 = LD16(r3 + 22);
                    ST16(0x060C1AA8, r0);
                    ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 20);
                    r3 = LD32(sp - 48);
                    if ((r0 & 0xFFFF) == r3) {
                        r3 = LD32(r14);
                        r0 = LD16(r3 + 24);
                        if (!((((r0 & 0xFFFF) + 4) & r12) >= r13)) {
                            r2 = LD32(r14);
                            r0 = LD16(r2 + 28);
                            if (!((((r0 & 0xFFFF) + 4) & r12) >= r13)) {
                                r4 = LD32(r14);
                                r4 = LD16(90 + r4);
                                r4 = r4 & 0xFFFF;
                                SETSP((sp - 56));
                                r0 = HELPER((int)r4 >> 8);
                                if (!(r0 == (r4 & r8))) {
                                    SETR(8, r8);
                                    SETR(9, r9);
                                    SETR(10, r10);
                                    SETR(11, r11);
                                    SETR(12, r12);
                                    SETR(13, r13);
                                    SETR(14, r14);
                                    SETSP((sp - 56));
                                    SETPR(0x0602642C);
                                    r0 = GCALL0(0x06018D60);
                                    if (!((r0 & r0) == 0)) {
                                        SETSP((sp - 56));
                                        r0 = GCALL0(0x0602620C);
                                        ST32(sp - 44, r0);
                                        if (!((r0 & r0) == 0)) {
                                            SETSP((sp - 56));
                                            r0 = GCALL0(0x060262BC);
                                            ST32(sp - 40, r0);
                                            r4 = LD32(r14);
                                            r0 = LD16(r4 + 22);
                                            SETSP((sp - 56));
                                            r0 = GCALL1(0x0600D16A, (r0 & 0xFFFF));
                                            SETSP((sp - 56));
                                            r0 = GCALL0(0x06015D16);
                                            r3 = LD32(r14);
                                            r4 = LD32(r10);
                                            r2 = LD32(sp - 44);
                                            r0 = LD16(r4 + 10);
                                            r1 = LD32(sp - 40);
                                            ST16(58 + r3, ((((((r2 + (r0 & 0xFFFF)) - 1) << 8) + (r0 & 0xFFFF)) + r1) + r9));
                                            r4 = LD32(sp - 52);
                                            SETSP((sp - 56));
                                            r0 = GCALL1(0x06014516, r4);
                                            r2 = LD32(sp - 56);
                                            ST32(sp - 56, (r2 + 1));
                                        }
                                    }
                                }
                            }
                        }
                    }
                    r11 = r11 + 1;
                    r3 = LD32(r14);
                    ST32(r14, (r3 + 124));
                    continue;
                } else {
                    break;
                }
            }
        }
    }
    r0 = LD32(sp - 56);
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060266E6(void)
{
    ST32(0x060C02CC, 0x060B4E58);
    ST32(0x060C02D0, 0x060B4E08);
    return GCALL5(0x060260F8, 2, 80, 0, 4, 0x060266E0);
}

int f06026734(void)
{
    int r0, r2, r4, r5, r6, r7;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0602673A);
    r0 = GCALL0(0x06026786);
    r7 = 0x060C090A;
    r6 = 0x060C0908;
    r5 = 0x060C0906;
    r4 = 0x060C0904;
    r0 = LD8(0x060C029C);
    if (!((r0 & 255) == 17)) {
        ST16(r4, 0x130);
        ST16(r5, 216);
        ST16(r6, 16);
        r0 = 0x060C090C;
        ST16(r7, 24);
        r2 = 120;
        ST16(0x060C090C, 160);
    } else {
        ST16(r4, 0x270);
        r0 = 0x060C090C;
        ST16(r5, 0x1A8);
        ST16(r6, 16);
        ST16(r7, 72);
        ST16(0x060C090C, 0x140);
        r2 = 192;
    }
    SETPR(LD32((sp - 4)));
    ST16(0x060C090E, r2);
    return r0;
}

int f060267A8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 24);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    r4 = LD16(0x060C062C);
    SETSP((sp - 20));
    r0 = GCALL1(0x060143E0, (r4 & 0xFFFF));
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r5 = 2;
    r4 = 0;
    ST16(r3 + 16, 0);
    r6 = 1;
    r3 = LD32(0x060D7768);
    ST16(50 + r3, 4);
    r3 = LD32(0x060D7768);
    ST16(52 + r3, 2);
    r3 = LD32(0x060D7768);
    ST16(62 + r3, 1);
    r3 = LD32(0x060D7768);
    ST16(58 + r3, 0);
    r3 = LD32(0x060D7768);
    ST16(60 + r3, 2);
    r3 = LD32(0x060D7768);
    ST16(70 + r3, 0);
    r0 = LD8(0x060C029C);
    if (!((r0 & 255) == 17)) {
        r2 = LD32(r14);
        ST16(44 + r2, r6);
        r2 = LD32(r14);
        ST16(56 + r2, 32);
    } else {
        r1 = LD32(r14);
        ST16(44 + r1, r5);
        r2 = LD32(r14);
        ST16(56 + r2, 64);
    }
    r13 = 0x060D7B3C;
    r3 = LD32(r14);
    ST16(68 + r3, r4);
    r3 = LD32(r14);
    ST8(r3 + 6, 3);
    r3 = LD32(0x060D7B3C);
    r0 = LD16(r3 + 16);
    r3 = LD16(0x060C090C);
    if (r0 >= (r3 & 0xFFFF)) {
        r1 = LD32(r14);
        ST8(r1 + 6, r6);
    }
    r8 = LD32(r14);
    r2 = LD16(0x060C0906);
    r3 = LD16(0x060C090A);
    ST32((sp - 24), ((((r2 & 0xFFFF) - (r3 & 0xFFFF)) >> 1) + 8));
    r0 = LD32(r14);
    r0 = LD8(r0 + 6);
    r8 = r8 + 66;
    if (!((r0 & 255) == 3)) {
        r7 = LD16(0x060C0908);
    } else {
        r7 = LD16(0x060C0904);
    }
    r6 = LD32(r13);
    r0 = LD16(r6 + 18);
    r5 = LD32(r13);
    r6 = r0;
    r0 = LD16(r5 + 16);
    r4 = LD16(0x060C062C);
    SETSP((sp - 24));
    r0 = GCALL4(0x0600A138, (((((r4 & 0xFFFF) << 2) + (r4 & 0xFFFF)) << 1) + 0x060C06FC), r0, r6, (r7 & 0xFFFF));
    ST16(r8, r0);
    SETSP((sp - 20));
    r0 = GCALL1(0x06008A96, 0);
    r4 = LD32(r13);
    SETSP((sp - 20));
    r0 = GCALL2(0x0606950C, r4, 1);
    SETSP((sp - 20));
    r0 = GCALL0(0x06016812);
    SETSP((sp - 20));
    r0 = GCALL1(0x06008A96, 1);
    r8 = LD32(r14);
    SETSP((sp - 20));
    r0 = GCALL1(0x060691DA, 0x1EA);
    ST16((r8 + 36), r0);
    if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
        SETSP((sp - 20));
        r0 = GCALL0(0x06026AD4);
        r5 = LD32(r14);
        r0 = LD16(r5 + 22);
        r4 = LD32(r14);
        r4 = LD16(36 + r4);
        SETSP((sp - 20));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r0 & 0xFFFF), -1);
        SETR(14, r14);
        SETSP((sp - 20));
        SETPR(0x0602691E);
        r0 = GCALL1(0x06026F8E, 0);
        r3 = LD32(r14);
        r3 = LD16(36 + r3);
        ST16(0x060C384A + (((r3 & 0xFFFF) * 84) & 0xFFFF), 64);
        r4 = LD32(r14);
        r4 = LD16(36 + r4);
        SETSP((sp - 20));
        r0 = GCALL2(0x06069546, (r4 & 0xFFFF), 1);
    }
    r2 = LD32(r14);
    ST16(r2 + 18, 0x3000);
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(8, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP1(0x060144F4, 0x060269A4);
    return r0;
}

void f060269A4(void)
{
    GCALL1(0x0601755E, LDU16(LD32(CURRENT) + 44) << 2);
    GCALL0(0x06026AD4);
    if (LD16(LD32(CURRENT) + 66))
        return;
    GJUMP1(0x060144F4, 0x060269D4);
}

void f06026AD4(void)
{
    gaddr obj = OBJ(LD16(LD32(CURRENT) + 36));
    gaddr mover, entry;
    int y;
    unsigned int k;

    GCALL2(0x0600A3D8, LDU16(LD32(CURRENT) + 22), LDU16(LD32(CURRENT) + 36));
    y = LD16(LD32(MOVER_PTR) + 18);
    GCALL2(0x06069462, LD16(LD32(CURRENT) + 22), y > LIM_UP ? y + 30 : 490);
    GCALL2(0x06069462, LD16(LD32(CURRENT) + 36), LD16(LD32(MOVER_PTR) + 4));
    entry = 0x060B4E70 + (LDU8(LD32(CURRENT) + 6) - 1) * 4;
    mover = LD32(MOVER_PTR);
    ST16(obj + 36, LD16(entry));
    ST16(mover + 36, LD16(entry));
    ST16(obj + 38, LD16(entry + 2));
    ST16(mover + 38, LD16(entry + 2));
    ST16(mover + 38, LD16(mover + 38) + (LDU16(LD32(CURRENT) + 42) == 5 ? -3 : -2));
    if (LD16(LD32(CURRENT) + 58)) {
        k = GCALL1(0x06068B4E, obj);
        if (k >= 3 && k < 5) {
            entry = 0x060B4E80 + (LDU8(LD32(CURRENT) + 6) - 1) * 8 + (k - 3) * 4;
            mover = LD32(MOVER_PTR);
            ST16(mover + 36, LD16(mover + 36) + LD16(entry));
            mover = LD32(MOVER_PTR);
            ST16(mover + 38, LD16(mover + 38) + LD16(entry + 2));
        }
    }
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

int f06027064(void)
{
    int r0, r2, r3, r4, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 12);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = 0x060D7768;
    r13 = LD32(0x060D7768);
    r0 = LD16(46 + r13);
    if (!((r0 & r0) == 0)) {
        r4 = LD16(46 + r13);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06027086);
        r0 = GCALL1(0x0601DFEA, (((int)((unsigned)((int)((unsigned)(r4 & 0xFFFF) >> 2)) >> 1)) + 3));
        if (!((r0 & r0) == 0)) {
            r3 = LD32(r14);
            r2 = LD16(40 + r3);
            ST16(40 + r3, (r2 + 1));
            r3 = LD32(0x060D8C08);
            r2 = LD32(r14);
            r0 = LD8(61 + r2);
            ST8((26 + r3), (r0 + 1));
            r3 = LD32(r14);
            r0 = LD8(r3 + 4);
            ST8(r3 + 4, (r0 | 8));
            r3 = LD32(r14);
            ST16(58 + r3, 1);
            r3 = LD32(r14);
            ST16(68 + r3, 150);
        }
        r3 = LD32(r14);
        r0 = 46;
        ST16(46 + r3, 0);
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060270CE(void)
{
    int r0, r1, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);
    SETSP(sp - 8);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r0 = LD16(0x060D7E68);
    r0 = r0 & 0xFFFF;
    if ((r0 & 64) == 0) {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 20);
        r2 = r0 & 0xFFFF;
        r0 = LD8(r4 + 6);
        r5 = LD16(0x060B47F0 + ((r0 & 255) << 1));
        r5 = LD16(0x060EC8B0 + ((r5 + r2) << 1));
        r2 = LD16(40 + r4);
        r1 = LD16(62 + r4);
        r5 = r5 & 0xFFFF;
        if ((unsigned)r2 >= (unsigned)r1) {
            ST16(42 + r4, 0);
            r0 = 68;
            r3 = LD32(r14);
            r1 = LD16(68 + r3);
            if (!((r1 & r1) == 0)) {
                r2 = LD32(r14);
                r3 = LD16(40 + r2);
                r0 = 62;
                r1 = LD16(62 + r2);
                if (!((unsigned)r3 >= (unsigned)r1)) {
                    r0 = 68;
                    r2 = LD32(r14);
                    r3 = LD16(68 + r2);
                    ST16(68 + r2, (r3 - 1));
                }
            }
        } else {
            r1 = LD16(68 + r4);
            if (!((r1 & r1) == 0)) {
                ST16(42 + r4, 0);
                r0 = 68;
                r3 = LD32(r14);
                r1 = LD16(68 + r3);
                if (!((r1 & r1) == 0)) {
                    r2 = LD32(r14);
                    r3 = LD16(40 + r2);
                    r0 = 62;
                    r1 = LD16(62 + r2);
                    if (!((unsigned)r3 >= (unsigned)r1)) {
                        r0 = 68;
                        r2 = LD32(r14);
                        r3 = LD16(68 + r2);
                        ST16(68 + r2, (r3 - 1));
                    }
                }
            } else {
                if (!((r5 & 128) == 0)) {
                    ST16(42 + r4, 0);
                    r0 = 68;
                    r3 = LD32(r14);
                    r1 = LD16(68 + r3);
                    if (!((r1 & r1) == 0)) {
                        r2 = LD32(r14);
                        r3 = LD16(40 + r2);
                        r0 = 62;
                        r1 = LD16(62 + r2);
                        if (!((unsigned)r3 >= (unsigned)r1)) {
                            r0 = 68;
                            r2 = LD32(r14);
                            r3 = LD16(68 + r2);
                            ST16(68 + r2, (r3 - 1));
                        }
                    }
                } else {
                    r3 = LD16(0x060C0684);
                    r2 = LD16(0x060BF5DC);
                    if (((r3 & 0xFFFF) & (r2 & 0xFFFF)) == 0) {
                        SETR(14, r14);
                        SETSP((sp - 8));
                        SETPR(0x0602713C);
                        r0 = GCALL0(0x06027064);
                    } else {
                        r3 = LD16(46 + r4);
                        r2 = LD16(56 + r4);
                        if ((unsigned)r3 >= (unsigned)r2) {
                            SETR(14, r14);
                            SETSP((sp - 8));
                            SETPR(0x0602713C);
                            r0 = GCALL0(0x06027064);
                        } else {
                            r2 = LD16(46 + r4);
                            ST16(46 + r4, (r2 + 1));
                        }
                    }
                    r3 = LD32(r14);
                    r0 = 42;
                    ST16(42 + r3, 5);
                }
            }
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0602719C(int n)
{
    gaddr cur = LD32(CURRENT);
    gaddr rec = REC(n);
    int dx = LDU16(cur + 24) - LDU16(rec + 24);
    int reach = LD16(0x060D7E88);
    int result = ABS(reach);

    if (ABS(dx) < result) {
        ST16(0x060D7E88, LD16(cur + 24) - LD16(rec + 24));
        result = LD16(LD32(CURRENT) + 28) - LD16(rec + 28);
        ST16(0x060D7E8A, result);
        ST16(0x060D7E8C, n);
    }
    return result;
}

int f06027206(int n)
{
    gaddr cur = LD32(CURRENT);
    gaddr rec = REC(n);
    int dy = LDU16(cur + 28) - LDU16(rec + 28);
    int reach = LD16(0x060D7E8A);
    int result = ABS(reach);

    if (ABS(dy) < result) {
        ST16(0x060D7E8A, LD16(cur + 28) - LD16(rec + 28));
        result = LD16(LD32(CURRENT) + 24) - LD16(rec + 24);
        ST16(0x060D7E88, result);
        ST16(0x060D7E8C, n);
    }
    return result;
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

int f06027378(void)
{
    int count = 0;
    int i;

    for (i = 0; i < LDU8(BOMBER_COUNT) && i != LDU16(0x060C062C); i++) {
        POLL();
        if (LD16(REC(i) + 20) == LD16(LD32(CURRENT) + 20))
            count++;
    }
    return count != 0;
}

int f060273B6(unsigned int n)
{
    int result;

    if (n > 48) {
        gaddr cur = LD32(CURRENT);

        if (n < LDU16(cur + 56) * 2 + 48)
            ST16(0x060D7E90, (n - 48) >> 1);
        else
            ST16(0x060D7E90, LD16(cur + 56));
    } else {
        ST16(0x060D7E90, 1);
    }
    result = GCALL1(0x060273F4, LDU16(0x060D7E90));
    ST16(0x060D7E90, result);
    return result;
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
    GJUMP0(0x0602769A);
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

int f06027A48(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 56);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    SETSP((sp - 32));
    r0 = GCALL1(0x0603176E, 50);
    r10 = 0x060311BA;
    SETSP((sp - 32));
    r0 = GCALL3(0x060311BA, 32, 1, 1);
    r12 = 0x06031594;
    ST32((sp - 36), 0x060B1AFC);
    SETR(10, 0x060311BA);
    SETR(12, 0x06031594);
    SETSP((sp - 36));
    SETPR(0x06027A70);
    r0 = GCALL4(0x06031594, 0, 0, 0, r7);
    r11 = 1;
    r13 = 0;
    r8 = 22;
    r14 = 3;
    do {
        SETSP((sp - 32));
        r0 = GCALL4(r10, 32, 1, r14, r7);
        r3 = LD32(0x060C0A4C + r13);
        ST32((sp - 36), r3);
        r2 = LD32(0x060C0A00 + r13);
        ST32((sp - 40), r2);
        ST32((sp - 44), r11);
        ST32((sp - 48), 0x060B1B14);
        SETR(8, r8);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 48));
        SETPR(0x06027A98);
        r0 = GCALL0(r12);
        r11 = r11 + 1;
        r14 = r14 + 1;
        r13 = r13 + 4;
    } while (AGAIN(!(r14 >= r8)));
    SETSP((sp - 32));
    r0 = GCALL4(r10, 32, 24, 10, r7);
    r2 = LD32(0x060C0698);
    ST32((sp - 36), r2);
    ST32((sp - 40), 0x060B1B28);
    SETR(10, r10);
    SETR(12, r12);
    SETSP((sp - 40));
    SETPR(0x06027AB8);
    r0 = GCALL0(r12);
    SETSP((sp - 40));
    r0 = GCALL3(r10, 32, 24, 12);
    r3 = LD32(0x060C0358);
    ST32((sp - 44), r3);
    ST32((sp - 48), 0x060B1B34);
    SETR(10, r10);
    SETR(12, r12);
    SETSP((sp - 48));
    SETPR(0x06027ACC);
    r0 = GCALL0(r12);
    SETSP((sp - 48));
    r0 = GCALL3(r10, 32, 24, 14);
    r3 = LD32(0x060C0A98);
    ST32((sp - 52), r3);
    ST32((sp - 56), 0x060B1B40);
    SETSP((sp - 56));
    SETPR(0x06027AE0);
    r0 = GCALL0(r12);
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06027EEE(void)
{
    int r0, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 16);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 16));
    r0 = GCALL1(0x060691DA, 10);
    r13 = r0 & 0xFFFF;
    if (!((r13 & r13) == 0)) {
        r14 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(44 + r14, 1);
        ST16(r14 + 18, 128);
        ST16(r14 + 16, 128);
        SETSP((sp - 16));
        r0 = GCALL0(0x0600A0B8);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x06027F2A);
        r0 = GCALL2(0x06068A8E, r13, (0x24D + (r0 & 3)));
        ST16(46 + r14, 0);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606950C, r14, 2);
        SETSP((sp - 16));
        r0 = GCALL1(0x060691DA, 11);
        r13 = r0 & 0xFFFF;
        if (!((r13 & r13) == 0)) {
            r14 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(44 + r14, 1);
            SETSP((sp - 16));
            r0 = GCALL2(0x0606AAC8, r14, 3);
            ST16(r14 + 18, 128);
            ST16(r14 + 16, 128);
            ST16(70 + r14, 0x200);
            ST16(68 + r14, 0x200);
            ST16(72 + r14, 160);
            ST16(74 + r14, 48);
            SETSP((sp - 16));
            r0 = GCALL0(0x0600A0B8);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x06027F8A);
            r0 = GCALL2(0x06068A8E, r13, (0x257 + (r0 & 3)));
            ST16(46 + r14, 0);
            SETSP((sp - 16));
            r0 = GCALL2(0x0606950C, r14, 2);
        }
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r13;
}

int f06027FF0(void)
{
    int r0, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 36);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 0;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r8 = 48;
    r10 = 0x200;
    ST32((sp - 36), MACL());
    r9 = 0x060C063D;
    r0 = LD8(0x060C063D);
    r12 = ((signed char)((((r0 & 1) << 2) + (r0 & 1)) << 2)) + 0x060B4FE8;
    r14 = 0;
    while (1) {
        r3 = LD8(r9);
        if (!((unsigned)r14 >= (unsigned)(r3 & 255))) {
            POLL();
            r3 = LD8(0x060C063F);
            if (!(r14 == (r3 & 255))) {
                r0 = LD8(0x060C0640 + r14);
                if (!(((r0 & 255) & 3) == 0)) {
                    SETSP((sp - 36));
                    r0 = GCALL1(0x060691DA, 9);
                    r4 = r0 & 0xFFFF;
                    if (!((r4 & r4) == 0)) {
                        r0 = LD16(r12);
                        r13 = (((r4 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
                        ST16(r13 + 16, r0);
                        ST16(r13 + 18, r8);
                        r5 = LD8(0x060C064A + r14);
                        SETR(8, r8);
                        SETR(9, r9);
                        SETR(10, r10);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 36));
                        SETPR(0x06028062);
                        r0 = GCALL2(0x06068A8E, r4, ((r5 & 255) + 0x1E3));
                        ST16(46 + r13, (((r14 << 2) << 2) + r10));
                        r12 = r12 + 2;
                        r11 = r11 + 1;
                    }
                }
            }
            r14 = r14 + 1;
            continue;
        } else {
            break;
        }
    }
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r11;
}

int f06028092(void)
{
    int r0, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 16);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 16));
    r0 = GCALL1(0x060691DA, 0x1EA);
    r13 = r0 & 0xFFFF;
    if (!((r13 & r13) == 0)) {
        r14 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(44 + r14, 1);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606AAC8, r14, 64);
        ST16(r14 + 18, 128);
        ST16(r14 + 16, 128);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x060280D0);
        r0 = GCALL2(0x06068A8E, r13, 0x225);
        ST16(46 + r14, 0);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606950C, r14, 2);
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r13;
}

int f0602811C(void)
{
    int r0, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 72);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 0;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    ST8(0x060C02A4, 0);
    SETSP((sp - 68));
    r0 = GCALL0(0x06028D98);
    r8 = 0x0606950C;
    r12 = 1;
    r13 = 0x060D7E64;
    r14 = 0x060D7E60;
    ST16(sp - 68, 0);
    ST32(sp - 64, 0x060B5010);
    while (1) {
        r4 = LD16(sp - 68);
        SETSP((sp - 68));
        r0 = GCALL2(0x06022F1C, (r4 & 0xFFFF), 0x060283EC);
        r9 = LD16(sp - 68);
        r3 = LD32(r13);
        r9 = (int)((unsigned)(r9 & 0xFFFF) >> 2);
        ST16(44 + r3, r12);
        r3 = LD32(r13);
        r0 = LD32(sp - 64);
        r0 = LD16(r0);
        ST16(r3 + 16, r0);
        r3 = LD32(r13);
        r0 = LD32(sp - 64);
        r0 = LD16(r0 + 2);
        ST16(r3 + 18, r0);
        r3 = LD32(r13);
        ST16(48 + r3, (0x218 + r9));
        r5 = LD32(r13);
        r4 = LD32(r14);
        r5 = LD16(48 + r5);
        r0 = LD16(r4 + 8);
        SETR(8, r8);
        SETR(9, r9);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 68));
        SETPR(0x06028186);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r5 & 0xFFFF));
        r2 = LD32(r13);
        ST32((sp - 72), (46 + r2));
        SETSP((sp - 72));
        r0 = GCALL1(0x0600A0EC, 6);
        r3 = LD32((sp - 72));
        ST16(r3, ((r0 << 2) << 2));
        r5 = LD32(r13);
        r0 = LD16(r5 + 18);
        r4 = LD32(r14);
        r5 = r0;
        r0 = LD16(r4 + 8);
        SETSP((sp - 68));
        r0 = GCALL2(0x06069462, r0, r5);
        r4 = LD32(r13);
        SETSP((sp - 68));
        r0 = GCALL2(r8, r4, 2);
        r2 = LD32(r14);
        ST32((sp - 72), (12 + r2));
        r4 = LD32(r13);
        r0 = LD16(r4 + 4);
        SETSP((sp - 72));
        r0 = GCALL1(0x060691DA, r0);
        r3 = LD32((sp - 72));
        ST16(r3, r0);
        if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
            r10 = LD32(r14);
            r0 = LD16(r10 + 12);
            r10 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(44 + r10, r12);
            SETSP((sp - 68));
            r0 = GCALL2(0x0606AAC8, r10, 3);
            r5 = LD32(r14);
            r4 = LD32(r14);
            r0 = LD16(r5 + 12);
            r5 = r0 & 0xFFFF;
            r0 = LD16(r4 + 8);
            SETSP((sp - 68));
            r0 = GCALL2(0x0600A3D8, (r0 & 0xFFFF), r5);
            ST16(74 + r10, 16);
            r4 = LD32(r14);
            r0 = LD16(r4 + 12);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x0602820E);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (0x215 + r9));
            r2 = LD32(r13);
            r3 = LD16(46 + r2);
            ST16(46 + r10, r3);
            SETSP((sp - 68));
            r0 = GCALL2(r8, r10, 2);
            SETSP((sp - 68));
            r0 = GCALL2(0x060695B0, r10, 1);
            r5 = LD32(r14);
            r4 = LD32(r14);
            r0 = LD16(r5 + 8);
            r5 = r0 & 0xFFFF;
            r0 = LD16(r4 + 12);
            SETSP((sp - 68));
            r0 = GCALL3(0x060693DC, (r0 & 0xFFFF), r5, -1);
        }
        r2 = LD32(r14);
        ST32((sp - 72), (10 + r2));
        r4 = LD32(r13);
        r0 = LD16(r4 + 4);
        SETSP((sp - 72));
        r0 = GCALL1(0x060691DA, r0);
        r3 = LD32((sp - 72));
        ST16(r3, r0);
        if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
            r10 = LD32(r14);
            r0 = LD16(r10 + 10);
            r10 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(44 + r10, r12);
            SETSP((sp - 68));
            r0 = GCALL2(0x0606AAC8, r10, 3);
            r5 = LD32(r14);
            r4 = LD32(r14);
            r0 = LD16(r5 + 10);
            r5 = r0 & 0xFFFF;
            r0 = LD16(r4 + 8);
            SETSP((sp - 68));
            r0 = GCALL2(0x0600A3D8, (r0 & 0xFFFF), r5);
            r3 = r9;
            ST16(74 + r10, 8);
            r2 = r9;
            ST16(48 + r10, ((((r3 << 2) << 1) - r2) + 0x232));
            r4 = LD32(r14);
            r0 = LD16(r4 + 10);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x060282EC);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (0x249 + r9));
            ST16(46 + r10, r11);
            SETSP((sp - 68));
            r0 = GCALL2(r8, r10, 6);
            r5 = LD32(r14);
            r0 = LD16(r5 + 8);
            r4 = LD32(r14);
            r5 = r0 & 0xFFFF;
            r0 = LD16(r4 + 10);
            SETSP((sp - 68));
            r0 = GCALL3(0x060693DC, (r0 & 0xFFFF), r5, 1);
        }
        r2 = LD32(r14);
        ST32((sp - 72), (14 + r2));
        r4 = LD32(r13);
        r0 = LD16(r4 + 4);
        SETSP((sp - 72));
        r0 = GCALL1(0x060691DA, r0);
        r3 = LD32((sp - 72));
        ST16(r3, r0);
        if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
            r10 = LD32(r14);
            r0 = LD16(r10 + 14);
            r10 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(44 + r10, r12);
            r5 = LD32(r14);
            r4 = LD32(r14);
            r0 = LD16(r5 + 14);
            r5 = r0 & 0xFFFF;
            r0 = LD16(r4 + 8);
            SETSP((sp - 68));
            r0 = GCALL2(0x0600A3D8, (r0 & 0xFFFF), r5);
            ST16(38 + r10, -16);
            ST16(48 + r10, (0x222 + r9));
            r4 = LD32(r14);
            r0 = LD16(r4 + 14);
            SETR(8, r8);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x06028362);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
            ST16(46 + r10, r11);
            SETSP((sp - 68));
            r0 = GCALL2(r8, r10, 2);
            r5 = LD32(r14);
            r4 = LD32(r14);
            r0 = LD16(r5 + 8);
            r5 = r0 & 0xFFFF;
            r0 = LD16(r4 + 14);
            SETSP((sp - 68));
            r0 = GCALL3(0x060693DC, (r0 & 0xFFFF), r5, 1);
        }
        r2 = LD32(r14);
        ST16(r2 + 6, r11);
        r3 = LD32(r14);
        ST16(r3 + 16, 0xFF00);
        r3 = LD32(r14);
        ST32((sp - 72), (18 + r3));
        SETSP((sp - 72));
        r0 = GCALL0(0x0600A0B8);
        r0 = r0 & 31;
        r2 = LD32((sp - 72));
        ST16(r2, r0);
        r3 = LD16(sp - 68);
        r3 = r3 + 1;
        ST16(sp - 68, r3);
        r2 = LD32(sp - 64);
        ST32(sp - 64, (r2 + 4));
        if ((r3 & 0xFFFF) >= 12) {
            break;
        }
        POLL();
    }
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060283EC(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14, c14;
    ENTRY_SP(sp);
    SETSP(sp - 40);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r11 = 0x060C381C;
    r0 = LD16(0x060D7CB8);
    r9 = 0x060C02A0;
    r14 = 0x060D7E60;
    ST32(sp - 40, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
    r13 = LD32(0x060D7E60);
    r0 = LD16(r13 + 18);
    if (!((r0 & r0) == 0)) {
        r0 = LD16(r13 + 18);
        ST16(r13 + 18, (r0 - 1));
    } else {
        r3 = LD8(r9);
        if (!((r3 & 255) >= 7)) {
            r0 = LD16(r13 + 16);
            SETSP((sp - 40));
            r0 = GCALL1(0x0600A306, (r0 & 0xFFFF));
            r2 = LD32(r14);
            r0 = LD16(r2 + 16);
            ST16(r2 + 16, (r0 + 16));
            r3 = LD32(r14);
            r0 = LD16(r3 + 16);
            if ((r0 & 0xFFFF) == 0x110) {
                r1 = LD32(r14);
                ST16(r1 + 16, 0xFF00);
            }
        } else {
            r0 = LD8(0x060C02A1);
            r2 = LD16(0x060D7B44);
            if (!((r0 & 255) == (r2 & 0xFFFF))) {
                r0 = LD16(r13 + 16);
                SETSP((sp - 40));
                r0 = GCALL1(0x0600A306, (r0 & 0xFFFF));
                r2 = LD32(r14);
                r0 = LD16(r2 + 16);
                ST16(r2 + 16, (r0 + 16));
                r3 = LD32(r14);
                r0 = LD16(r3 + 16);
                if ((r0 & 0xFFFF) == 0x110) {
                    r1 = LD32(r14);
                    ST16(r1 + 16, 0xFF00);
                }
            }
        }
    }
    r10 = 0x060D7B44;
    r12 = 0x060D7E64;
    r13 = 0x06068A8E;
    r3 = LD8(0x060C02A1);
    r1 = LD16(0x060D7B44);
    if (!((r3 & 255) == (r1 & 0xFFFF))) {
        r4 = LD32(r14);
        r0 = LD16(r4 + 14);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x06028542);
        r0 = GCALL2(r13, (r0 & 0xFFFF), 0);
    } else {
        r0 = LD8(r9);
        r0 = r0 & 255;
        r8 = LD32(r12);
        if (r0 == 6) {
            r0 = LD32(sp - 40);
            r0 = LD16(r0 + 16);
            ST16(r8 + 16, r0);
        } else {
            if (r0 == 7) {
                r4 = LD32(r14);
                r5 = LD16(48 + r8);
                r0 = LD16(r4 + 8);
                SETR(9, r9);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 40));
                SETPR(0x060284A4);
                r0 = GCALL2(r13, (r0 & 0xFFFF), ((r5 & 0xFFFF) + 3));
                r3 = LD32(r12);
                r0 = LD32(sp - 40);
                r0 = LD16(r0 + 18);
                ST16(r3 + 18, r0);
            } else {
                if (r0 == 8) {
                    r4 = LD32(r14);
                    r0 = LD16(r4 + 10);
                    SETSP((sp - 40));
                    r0 = GCALL2(0x06069462, r0, 0x1F0);
                    r2 = LD32(r14);
                    ST16(r2 + 4, 60);
                    r3 = LD32(r14);
                    ST32(r3, 0x060285EA);
                    ST8(r9, 9);
                }
            }
        }
        r1 = LD8(r9);
        if ((r1 & 255) >= 5) {
            r4 = LD32(r14);
            r5 = 0;
            r0 = LD16(r4 + 14);
            r4 = r0 & 0xFFFF;
        } else {
            r5 = LD32(r14);
            r0 = LD16(r5 + 14);
            ST16(sp - 40, r0);
            r4 = LD16(sp - 40);
            r5 = LD16(48 + ((((r0 & 0xFFFF) * 84) & 0xFFFF) + r11));
            r5 = r5 & 0xFFFF;
            r4 = r4 & 0xFFFF;
        }
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x06028534);
        r0 = GCALL2(r13, r4, r5);
    }
    r9 = 0x060C02A3;
    r1 = LD8(0x060C02A3);
    if ((r1 & r1) == 0) {
        r5 = LD32(r14);
        r0 = LD16(r5 + 10);
        ST16(sp - 40, r0);
        r3 = LD16(r10);
        r4 = LD16(sp - 40);
        r5 = LD16(48 + ((((r0 & 0xFFFF) * 84) & 0xFFFF) + r11));
        r2 = LD8(0x060DFB9B + (((r3 & 0xFFFF) << 2) << 1));
        SETR(11, r11);
        SETR(12, r12);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x06028596);
        r0 = GCALL2(r13, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r2 & 255)));
    } else {
        r5 = LD16(r10);
        r4 = LD32(r14);
        r0 = LD16(r4 + 10);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x0602855C);
        r0 = GCALL2(r13, (r0 & 0xFFFF), (((int)((unsigned)(r5 & 0xFFFF) >> 2)) + 0x249));
        r1 = LD16(r10);
        if ((r1 & r1) == 0) {
            r3 = LD8(r9);
            ST8(r9, (r3 - 1));
        }
    }
    r5 = LD32(r14);
    r4 = LD32(r14);
    r0 = LD16(r5 + 10);
    r5 = r0 & 0xFFFF;
    r0 = LD16(r4 + 8);
    SETSP((sp - 40));
    r0 = GCALL2(0x0600A3D8, (r0 & 0xFFFF), r5);
    r4 = LD32(r14);
    r0 = LD16(r4 + 12);
    c14 = (r0 & 0xFFFF) * 84;
    r0 = LD32(r12);
    r0 = LD16(r0 + 16);
    r4 = (c14 & 0xFFFF) + r11;
    ST16(r4 + 16, r0);
    r0 = LD16(r4 + 18);
    r3 = LD32(r12);
    r2 = r0;
    r0 = LD16(r3 + 18);
    r2 = (-((r2 - r0) << 1)) + 0x100;
    ST16(70 + r4, r2);
    ST16(68 + r4, r2);
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 68;
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

int f06028644(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 36);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(9));
    ST32((sp - 24), R(8));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    SETSP((sp - 36));
    r0 = GCALL2(0x06022F1C, 15, 0x06028814);
    r12 = 0x060D7E64;
    ST32(sp - 36, 0x060B5012);
    r3 = LD32(0x060D7E64);
    ST16(44 + r3, 1);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 36));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    r2 = LD32(0x060D7E64);
    r14 = 0x060D7E60;
    ST16(r2 + 16, -48);
    r3 = LD32(0x060D7E64);
    r0 = LD32(sp - 36);
    r0 = LD16(r0);
    ST16(r3 + 18, (r0 - 40));
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(12, 0x060D7E64);
    SETR(14, 0x060D7E60);
    SETSP((sp - 36));
    SETPR(0x06028692);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0x21E);
    r11 = 0;
    r2 = LD32(0x060D7E64);
    ST16(46 + r2, 0);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 36));
    r0 = GCALL2(0x0606950C, r4, 2);
    r8 = LD32(0x060D7E60);
    SETSP((sp - 36));
    r0 = GCALL1(0x060691DA, 102);
    ST16((r8 + 10), r0);
    if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
        r13 = LD32(r14);
        r0 = LD16(r13 + 10);
        r13 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(44 + r13, 1);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606AAC8, r13, 3);
        SETSP((sp - 36));
        r0 = GCALL1(0x0606AB92, r13);
        r0 = LD32(r12);
        r0 = LD16(r0 + 16);
        ST16(r13 + 16, r0);
        r0 = LD32(r12);
        r0 = LD16(r0 + 18);
        ST16(r13 + 18, (r0 + 40));
        ST16(38 + r13, 16);
        ST16(72 + r13, r11);
        ST16(74 + r13, -8);
        r4 = LD32(r14);
        r0 = LD16(r4 + 10);
        SETR(11, r11);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x06028702);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0x247);
        ST16(46 + r13, r11);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606950C, r13, 2);
        r5 = LD32(r14);
        r0 = LD16(r5 + 8);
        r4 = LD32(r14);
        r5 = r0 & 0xFFFF;
        r0 = LD16(r4 + 10);
        SETSP((sp - 36));
        r0 = GCALL3(0x060693DC, (r0 & 0xFFFF), r5, -1);
    }
    r2 = LD32(r14);
    r0 = r11;
    ST16(r2 + 12, r0);
    r3 = LD32(r14);
    ST16(r3 + 14, r0);
    r3 = LD32(r14);
    ST16(r3 + 16, r0);
    r3 = LD32(r14);
    ST16(r3 + 6, r0);
    r4 = LD8(0x060C063F);
    r1 = LD8(0x060C063D);
    if (!((r4 & 255) >= (r1 & 255))) {
        r0 = LD8((r4 & 255) + 0x060C0640);
        if (((r0 & 255) & 3) == 2) {
            r9 = LD32(r14);
            SETSP((sp - 36));
            r0 = GCALL0(0x0600A0B8);
            r8 = r0 & 7;
            SETSP((sp - 36));
            r0 = GCALL0(0x0600A0B8);
            ST16((r9 + 16), ((r8 + (r0 & 3)) + 1));
        }
    }
    SETMACL(LD32((sp - 32)));
    SETPR(LD32((sp - 28)));
    SETR(8, LD32((sp - 24)));
    SETR(9, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return sp - 36;
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

int f06028814(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, c25;
    ENTRY_SP(sp);
    SETSP(sp - 48);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r14 = 0x060D7E60;
    r5 = 0x26006096;
    r4 = LD8(0x060C063F);
    r1 = LD8(0x060C063D);
    if ((r4 & 255) >= (r1 & 255)) {
        r6 = LD16(r5);
    } else {
        r1 = LD32(r14);
        r0 = LD16(r1 + 16);
        if ((r0 & r0) == 0) {
            r6 = LD16(((r4 & 255) << 1) + r5);
        } else {
            SETSP((sp - 48));
            r0 = GCALL0(0x060287C4);
            r6 = r0;
        }
    }
    r9 = 60;
    r10 = 0x06068A8E;
    r0 = r6 & 0xFFFF;
    r8 = 0x060C02A1;
    r11 = 0x0600996A;
    r12 = 0x060D7E64;
    r13 = 0x060C02A0;
    r5 = LD32(0x060D7E64);
    ST32(sp - 40, r0);
    r4 = 0x10E;
    ST32(sp - 48, (r0 & 0x100));
    ST32(sp - 44, 0x10F);
    r7 = LD32(sp - 40);
    r0 = LD8(0x060C02A0);
    r0 = r0 & 255;
    r7 = r7 & 0x200;
    if (r0 == 0) {
        r0 = LD16(r5 + 16);
        if (r0 >= 32) {
            r1 = LD32(sp - 48);
            if (!((r1 & r1) == 0)) {
                SETSP((sp - 48));
                r0 = GCALL4(r11, r4, r5, r6, r7);
                ST8(r13, 1);
            }
        } else {
            r0 = LD16(r5 + 16);
            ST16(r5 + 16, (r0 + 1));
        }
    } else {
        if (r0 == 1) {
            r0 = LD32(sp - 48);
            if ((r0 & r0) == 0) {
                r4 = LD32(sp - 44);
                SETSP((sp - 48));
                r0 = GCALL4(r11, r4, r5, r6, r7);
                ST8(r13, 2);
            } else {
                r0 = LD16(r5 + 16);
                if (r0 >= 0x120) {
                    r4 = LD32(sp - 44);
                    SETSP((sp - 48));
                    r0 = GCALL4(r11, r4, r5, r6, r7);
                    ST8(r13, 2);
                } else {
                    r0 = LD16(r5 + 16);
                    ST16(r5 + 16, (r0 + 1));
                    SETSP((sp - 48));
                    r0 = GCALL0(0x06028D98);
                }
            }
        } else {
            if (r0 == 2) {
                if (!((r7 & r7) == 0)) {
                    SETSP((sp - 48));
                    r0 = GCALL4(r11, r4, r5, r6, r7);
                    r3 = LD32(r14);
                    r0 = LD32(r12);
                    r0 = LD16(r0 + 16);
                    ST16(r3 + 14, ((-r0) + 160));
                    ST8(r13, 3);
                }
            } else {
                if (r0 == 3) {
                    if ((r7 & r7) == 0) {
                        r4 = LD32(sp - 44);
                        SETSP((sp - 48));
                        r0 = GCALL4(r11, r4, r5, r6, r7);
                        ST8(r13, 4);
                    } else {
                        r2 = LD16(68 + r5);
                        if (!((r2 & 0xFFFF) > 152)) {
                            r4 = LD32(sp - 44);
                            SETSP((sp - 48));
                            r0 = GCALL4(r11, r4, r5, r6, r7);
                            ST8(r13, 4);
                        } else {
                            r4 = LD32(r14);
                            r0 = LD16(r4 + 14);
                            SETSP((sp - 48));
                            r0 = GCALL1(0x0600A28C, (r0 & 0xFFFF));
                            SETSP((sp - 48));
                            r0 = GCALL1(0x0600A32A, 248);
                            r3 = LD32(r12);
                            r2 = LD16(68 + r3);
                            ST16(68 + r3, (r2 - 1));
                            r3 = LD32(r12);
                            r2 = LD16(70 + r3);
                            ST16(70 + r3, (r2 - 1));
                            SETSP((sp - 48));
                            r0 = GCALL0(0x06028D98);
                        }
                    }
                } else {
                    if (r0 == 4) {
                        r4 = LD32(r14);
                        r0 = LD16(r4 + 8);
                        SETR(9, r9);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 48));
                        SETPR(0x060289B0);
                        r0 = GCALL4(r10, (r0 & 0xFFFF), 0x21F, r6, r7);
                        r3 = LD32(r14);
                        ST16(r3 + 4, r9);
                        r3 = 5;
                        ST8(r13, r3);
                    } else {
                        if (!(r0 == 5)) {
                            if (!(r0 == 6)) {
                                if (!(r0 == 7)) {
                                    if (r0 == 8) {
                                        r0 = LD8(r8);
                                        if ((r0 & 255) == 100) {
                                            ST8(r13, 10);
                                        }
                                    }
                                } else {
                                    SETSP((sp - 48));
                                    r0 = GCALL1(0x0600A32A, 248);
                                    r2 = LD32(r14);
                                    r0 = LD16(r2 + 12);
                                    ST16(r2 + 12, (r0 - 1));
                                    r3 = LD32(r14);
                                    r0 = LD16(r3 + 12);
                                    if ((r0 & r0) == 0) {
                                        r0 = LD8(r8);
                                        if ((r0 & 255) == 100) {
                                            r4 = LD32(r14);
                                            r0 = LD16(r4 + 8);
                                            SETR(9, r9);
                                            SETR(11, r11);
                                            SETR(12, r12);
                                            SETR(13, r13);
                                            SETR(14, r14);
                                            SETSP((sp - 48));
                                            SETPR(0x06028A44);
                                            r0 = GCALL2(r10, (r0 & 0xFFFF), 0x221);
                                            SETSP((sp - 48));
                                            r0 = GCALL1(r11, 0x111);
                                            r3 = LD32(r14);
                                            ST16(r3 + 4, r9);
                                        } else {
                                            r2 = LD8(r8);
                                            r3 = LD8(0x060DFB9B + (((r2 & 255) << 2) << 1));
                                            if (!((r3 & 255) >= 5)) {
                                                SETSP((sp - 48));
                                                r0 = GCALL1(0x0600940A, 1);
                                                SETSP((sp - 48));
                                                r0 = GCALL1(0x0600940A, 2);
                                                SETSP((sp - 48));
                                                r0 = GCALL1(0x060092D4, 23);
                                                SETSP((sp - 48));
                                                r0 = GCALL1(0x060092D4, 26);
                                                r4 = LD32(r14);
                                                r0 = LD16(r4 + 8);
                                                SETR(11, r11);
                                                SETR(12, r12);
                                                SETR(13, r13);
                                                SETR(14, r14);
                                                SETSP((sp - 48));
                                                SETPR(0x06028A96);
                                                r0 = GCALL2(r10, (r0 & 0xFFFF), 0x220);
                                                SETSP((sp - 48));
                                                r0 = GCALL1(r11, 244);
                                            } else {
                                                r4 = LD32(r14);
                                                r0 = LD16(r4 + 8);
                                                SETR(9, r9);
                                                SETR(11, r11);
                                                SETR(12, r12);
                                                SETR(13, r13);
                                                SETR(14, r14);
                                                SETSP((sp - 48));
                                                SETPR(0x06028A44);
                                                r0 = GCALL2(r10, (r0 & 0xFFFF), 0x221);
                                                SETSP((sp - 48));
                                                r0 = GCALL1(r11, 0x111);
                                                r3 = LD32(r14);
                                                ST16(r3 + 4, r9);
                                            }
                                        }
                                        ST8(r13, 8);
                                    }
                                }
                            } else {
                                r4 = LD32(r14);
                                r0 = LD16(r4 + 8);
                                SETR(9, r9);
                                SETR(12, r12);
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 48));
                                SETPR(0x060289FA);
                                r0 = GCALL4(r10, (r0 & 0xFFFF), 0x21E, r6, r7);
                                r3 = LD32(r14);
                                ST16(r3 + 4, r9);
                                r3 = 7;
                                ST8(r13, r3);
                            }
                        } else {
                            SETSP((sp - 48));
                            r0 = GCALL1(0x0600A32A, 8);
                            r2 = LD32(r14);
                            r0 = LD16(r2 + 12);
                            ST16(r2 + 12, (r0 + 1));
                            r3 = LD32(r14);
                            r0 = LD16(r3 + 12);
                            if ((r0 & 0xFFFF) > 1) {
                                r2 = LD32(r14);
                                r0 = LD16(r2 + 12);
                                if ((r0 & 0xFFFF) >= 80) {
                                    ST8(r13, 6);
                                }
                            } else {
                                SETSP((sp - 48));
                                r0 = GCALL1(r11, 0x110);
                            }
                        }
                    }
                }
            }
        }
    }
    r0 = LD32(r12);
    r0 = LD16(r0 + 70);
    ST16(sp - 48, ((((-(r0 & 0xFFFF)) + 0x100) & 240) >> 1));
    r5 = LD16(0x060B5012);
    r3 = LD16(sp - 48);
    r4 = LD32(r14);
    r0 = LD16(r4 + 8);
    SETSP((sp - 48));
    r0 = GCALL2(0x06069462, r0, (((r5 & 0xFFFF) - (r3 & 0xFFFF)) + 1));
    r5 = LD32(r12);
    r4 = LD32(r14);
    r0 = LD16(r5 + 4);
    r5 = r0;
    r0 = LD16(r4 + 10);
    SETSP((sp - 48));
    r0 = GCALL2(0x06069462, r0, r5);
    r2 = LD32(r14);
    r0 = LD16(r2 + 10);
    if (!((r0 & r0) == 0)) {
        r4 = LD32(r14);
        r0 = LD16(r4 + 10);
        c25 = (r0 & 0xFFFF) * 84;
        r0 = LD32(r12);
        r0 = LD16(r0 + 16);
        r4 = (c25 & 0xFFFF) + 0x060C381C;
        ST16(r4 + 16, r0);
        r2 = LD8(r13);
        if (!((r2 & 255) > 4)) {
            r0 = LD32(r12);
            r0 = LD16(r0 + 18);
            ST16(r4 + 18, (r0 + 40));
        }
        r3 = LD32(r12);
        r0 = LD16(r3 + 18);
        r3 = r0;
        r0 = LD16(r4 + 18);
        r0 = r0 - r3;
        r3 = LD32(r12);
        r5 = r0 << 1;
        r2 = LD16(68 + r3);
        ST16(68 + r4, (r2 - r5));
        r0 = 70;
        r3 = LD32(r12);
        r2 = LD16(70 + r3);
        ST16(70 + r4, (r2 - r5));
    }
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06028B70(void)
{
    int r0, r1, r2, r3, r4, r8, r9, r10, r11, r12, r13, r14, c1, c3;
    ENTRY_SP(sp);
    SETSP(sp - 40);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    SETSP((sp - 36));
    r0 = GCALL2(0x06008A6A, 8, 1);
    SETSP((sp - 36));
    r0 = GCALL2(0x06022F1C, 16, 0x06028CF8);
    r12 = 0;
    r14 = 0x060D7E60;
    r8 = 0x06068A8E;
    r9 = 0x060C381C;
    r10 = 0x060691DA;
    r11 = 128;
    r3 = LD32(0x060D7E60);
    ST32((sp - 40), (12 + r3));
    SETSP((sp - 40));
    r0 = GCALL1(0x060691DA, 0x1EA);
    r1 = LD32((sp - 40));
    ST16(r1, r0);
    if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
        r13 = LD32(r14);
        r0 = LD16(r13 + 12);
        c1 = (r0 & 0xFFFF) * 84;
        r0 = r11;
        r13 = (c1 & 0xFFFF) + r9;
        ST16(r13 + 18, r0);
        ST16(r13 + 16, r0);
        r4 = LD32(r14);
        r0 = LD16(r4 + 12);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x06028BD2);
        r0 = GCALL2(r8, (r0 & 0xFFFF), 0x226);
        ST16(46 + r13, r12);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606950C, r13, 3);
    }
    r2 = LD32(r14);
    ST32((sp - 40), (10 + r2));
    SETSP((sp - 40));
    r0 = GCALL1(r10, 0x1EA);
    r1 = LD32((sp - 40));
    ST16(r1, r0);
    if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
        r13 = LD32(r14);
        r0 = LD16(r13 + 10);
        c3 = (r0 & 0xFFFF) * 84;
        r0 = r11;
        r13 = (c3 & 0xFFFF) + r9;
        ST16(r13 + 18, r0);
        ST16(r13 + 16, r0);
        r4 = LD32(r14);
        r0 = LD16(r4 + 10);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x06028C12);
        r0 = GCALL2(r8, (r0 & 0xFFFF), 0x229);
        ST16(46 + r13, r12);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606950C, r13, 3);
    }
    r2 = LD32(r14);
    ST32((sp - 40), (16 + r2));
    SETSP((sp - 40));
    r0 = GCALL1(r10, 0x1EA);
    r1 = LD32((sp - 40));
    ST16(r1, r0);
    if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
        r13 = LD32(r14);
        r0 = LD16(r13 + 16);
        r13 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + r9;
        SETSP((sp - 36));
        r0 = GCALL2(0x0606AAC8, r13, 3);
        r0 = r11;
        ST16(r13 + 18, r0);
        ST16(r13 + 16, r0);
        r4 = LD32(r14);
        r0 = LD16(r4 + 16);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x06028C5A);
        r0 = GCALL2(r8, (r0 & 0xFFFF), 0);
        ST16(46 + r13, r12);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606950C, r13, 2);
    }
    r2 = LD32(r14);
    ST32((sp - 40), (14 + r2));
    SETSP((sp - 40));
    r0 = GCALL1(r10, 0x1EA);
    r1 = LD32((sp - 40));
    ST16(r1, r0);
    if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
        r13 = LD32(r14);
        r0 = LD16(r13 + 14);
        r13 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + r9;
        SETSP((sp - 36));
        r0 = GCALL2(0x0606AAC8, r13, 3);
        r0 = r11;
        ST16(r13 + 18, r0);
        ST16(r13 + 16, r0);
        r4 = LD32(r14);
        r0 = LD16(r4 + 14);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x06028CA2);
        r0 = GCALL2(r8, (r0 & 0xFFFF), 0);
        ST16(46 + r13, r12);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606950C, r13, 2);
    }
    r2 = LD32(r14);
    ST16(r2 + 6, r12);
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return sp - 36;
}

int f06028CF8(void)
{
    int r0, r1, r3, r4, r5, r6, r13, c0, c1;
    ENTRY_SP(sp);
    SETSP(sp - 20);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    r13 = LD8(0x060C02A0);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 10);
    r13 = (((r13 & 255) << 2) << 1) + 0x060B5040;
    r5 = LD16(r13);
    SETR(12, 0x06068A8E);
    SETR(13, r13);
    SETR(14, 0x060D7E60);
    SETSP((sp - 20));
    SETPR(0x06028D20);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r5 & 0xFFFF));
    r0 = LD16(r13 + 2);
    r5 = r0 & 0xFFFF;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 12);
    SETR(12, 0x06068A8E);
    SETR(13, r13);
    SETR(14, 0x060D7E60);
    SETSP((sp - 20));
    SETPR(0x06028D2C);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    r0 = LD16(r13 + 4);
    r5 = r0 & 0xFFFF;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 14);
    SETR(12, 0x06068A8E);
    SETR(13, r13);
    SETR(14, 0x060D7E60);
    SETSP((sp - 20));
    SETPR(0x06028D38);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    r0 = LD16(r13 + 6);
    r5 = r0 & 0xFFFF;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 16);
    SETR(14, 0x060D7E60);
    SETSP((sp - 20));
    SETPR(0x06028D44);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 16);
    r5 = LD32(0x060D7E60);
    c0 = (r0 & 0xFFFF) * 84;
    r0 = LD16(r5 + 14);
    r4 = (c0 & 0xFFFF) + 0x060C381C;
    c1 = (r0 & 0xFFFF) * 84;
    r0 = LD16(0x060D7CB8);
    r5 = (c1 & 0xFFFF) + 0x060C381C;
    r6 = 0x060C381C + (((r0 & 0xFFFF) * 84) & 0xFFFF);
    r0 = LD16(r6 + 16);
    ST16(r5 + 16, r0);
    ST16(r4 + 16, r0);
    r1 = LD16(68 + r6);
    ST16(68 + r5, r1);
    ST16(68 + r4, r1);
    r0 = LD16(r6 + 18);
    ST16(r5 + 18, r0);
    ST16(r4 + 18, r0);
    r3 = LD16(70 + r6);
    ST16(70 + r5, r3);
    ST16(70 + r4, r3);
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 70;
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

void f060291A8(void)
{
    int i;
    unsigned int j;
    int k = 0;
    unsigned int count;
    gaddr out = 0x060C0ABC;

    for (i = 0; i < 12; i++) {
        POLL();
        if (i >= LDU8(0x26006094) || (LDU8(0x26006088 + i) & 240) || (LDU16(0x26006070 + i * 2) & 0xF000) == 0xF000) {
            ST8(0x26006088 + i, 240);
            ST16(0x26006070 + i * 2, 0);
        }
    }
    count = LD32(0x060C0AB4 + LD32(0x060C0AA4) * 4);
    for (j = 0; j < count; j++) {
        POLL();
        ST16(out, 2);
        if (k < 10) {
            do {
                if (!(LDU8(0x26006088 + k) & 240) && (LDU16(0x26006070 + k * 2) & 0xF000) != 0xF000)
                    ST16(out, LD16(0x26006070 + k * 2) & 0xFFF8);
                k++;
            } while (AGAIN((LDU16(out) & 7) == 2 && k < 10));
        }
        out += 2;
    }
    if (j < 5) {
        do {
            j++;
            ST16(out, 2);
            out += 2;
        } while (AGAIN(j < 5));
    }
}

void f060292AE(gaddr flag, gaddr value, unsigned short bits)
{
    if (bits & 7) {
        ST8(flag, 240);
        ST16(value, 0);
    } else {
        ST8(flag, 0);
        ST16(value, bits & 0xFFF8);
    }
}

void f060292E8(void)
{
    gaddr tag = 0x26006088;
    gaddr val = 0x26006070;
    gaddr src = 0x060C0AC6;
    unsigned int n = LD32(0x060C0AB4);
    unsigned int i = 0;

    if (i < n) {
        do {
            GCALL3(0x060292AE, tag, val, LD16(src));
            tag++;
            val += 2;
            i++;
            src += 2;
        } while (AGAIN(i < n));
    }
    src = 0x060C0AD0;
    n += LD32(0x060C0AB8);
    if (i < n) {
        do {
            GCALL3(0x060292AE, tag, val, LD16(src));
            tag++;
            val += 2;
            i++;
            src += 2;
        } while (AGAIN(i < n));
    }
    if (i < 12) {
        do {
            GCALL3(0x060292AE, tag, val, 2);
            tag++;
            i++;
            val += 2;
        } while (AGAIN(i < 12));
    }
    ST8(0x26006094, 12);
}

int f06029430(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 16);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r12 = 16;
    r13 = SMPC_SF;
    ST32((sp - 16), PR());
    r0 = LD32(0x060C0AA8);
    r14 = 1;
    if (r0 == 1) {
        r0 = LD32(0x06002F6C);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x0602944E);
        r0 = GCALL0(r0);
        if (r0 == 1) {
            r2 = LD32(0x06002F78);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x0602945A);
            r0 = GCALL0(r2);
        }
        r1 = LD8(SMPC_SR);
        if (((r1 & 255) & r12) == r12) {
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x0602946C);
            r0 = GCALL0(0x06039016);
            r3 = LD32(0x06002F3C);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x06029474);
            r0 = GCALL0(r3);
            r1 = LD32(0x06002F74);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x0602947C);
            r0 = GCALL0(r1);
            do {
                r2 = LD8(r13);
            } while (AGAIN(((r2 & 255) & r14) == r14));
            ST8(r13, r14);
            ST8(SMPC_COMREG, 24);
            do {
                r0 = LD8(r13);
            } while (AGAIN(!(((r0 & 255) & r14) == 0)));
        }
    }
    r0 = LD32(0x060C0AA8);
    if (r0 == 2) {
        r1 = LD8(SMPC_SR);
        if (((r1 & 255) & r12) == r12) {
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x060294AE);
            r0 = GCALL4(0x060294F4, 4, 0, 0, r7);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x060294B4);
            r0 = GCALL0(0x06039016);
            r2 = LD32(0x06002F3C);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x060294BC);
            r0 = GCALL0(r2);
            r1 = LD32(0x06002F74);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x060294C4);
            r0 = GCALL0(r1);
            r3 = LD32(0x06002F48);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x060294D0);
            r0 = GCALL2(r3, 0x060B50E8, -608);
            do {
                r2 = LD8(r13);
            } while (AGAIN(((r2 & 255) & r14) == r14));
            ST8(r13, r14);
            ST8(SMPC_COMREG, 24);
            do {
                r0 = LD8(r13);
                r0 = r0 & 255;
            } while (AGAIN(!((r0 & r14) == 0)));
        }
    }
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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
    ST16(VDP2_CLOFEN, out);
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

void f06029A78(void)
{
    gaddr reg = VDP2_COAR;
    int i = 0;

    GCALL1(0x06029718, 0x13C);
    do {
        ST16(reg, 0x1A0);
        i++;
        reg += 2;
    } while (AGAIN(i < 3));
}

void f06029A9A(void)
{
    gaddr reg = VDP2_COAR;
    int i = 0;

    GCALL1(0x06029718, 0x13C);
    do {
        i++;
        ST16(reg, 0xA0);
        reg += 2;
    } while (AGAIN(i < 3));
}

void f06029ABC(int x, int y, int z)
{
    GCALL1(0x06029718, 0x13C);
    ST16(VDP2_COAR, x & 0x1FF);
    ST16(VDP2_COAG, y & 0x1FF);
    ST16(VDP2_COAB, z & 0x1FF);
}

void f06029AEE(void)
{
    POLL();
    ST16(0x060FB8CA, 0);
    ST16(VDP2_CLOFEN, 0);
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

int f06029EB8(int a, int b)
{
    FRAME(sp, 32);
    int k;

    GCALL1(0x0602977C, a);
    GCALL1(0x060298F4, a);
    for (k = 0; k < 3; k++) {
        int v = LD16(0x060FB8CE + k * 2) & 0x1FF;

        if (v & 128)
            v |= -256;
        ST16(sp - 12 + k * 2, v);
    }
    ST16(sp - 16, 0);
    ST16(sp - 18, 0);
    ST16(sp - 20, 0);
    return GCALL5(0x0609BE8C, 0, 1, b, sp - 12, sp - 20);
}

void f06029FB8(void)
{
    ST16(0x060EC450, 0);
    ST16(0x060FAA3A, 0);
    ST32(0x060FAA40, 0x00023000);
    ST32(0x060FAA44, 0x00024000);
    ST16(0x060EC452, 0);
}

int f06029FD2(short mode, int level, short y, short x)
{
    FRAME(sp, 0);
    int result;

    ST32(0x26006160, 0);
    if (LD16(0x060EC450) == 0)
        GCALL4(0x060069B2, 0x0602A12E, 0x060DFE98, 0x100, 1);
    if ((short)level > 224)
        level = 224;
    if (mode == 4) {
        ST16(0x060EC454, level);
        ST32(0x060EC458, LD32(sp));
        ST32(0x060EC468, x << 16);
        ST32(0x060EC470, y << 16);
        ST32(0x060EC460, 0);
        ST16(0x060EC452, LD32(sp + 4));
        ST16(0x060FAA3A, (LD16(0x060FAA3A) & 0xFF00) | 14);
        GCALL4(0x0602A2A8, 0x25E46000, 0x25E4A000, level, LD32(0x060EC470));
        GCALL4(0x0602A470, 0x060DFF98, level, LD32(0x060EC470), LD32(0x060EC468));
        result = LD16(0x060EC450) | 15;
        ST16(0x060EC450, result);
    } else if (mode == 8) {
        ST16(0x060EC456, level);
        ST32(0x060EC45C, LD32(sp));
        ST32(0x060EC46C, x << 16);
        ST32(0x060EC474, y << 16);
        ST32(0x060EC464, 0);
        ST16(0x060EC452, LD32(sp + 4));
        ST16(0x060FAA3A, (LD16(0x060FAA3A) & 255) | 0xE00);
        GCALL4(0x0602A2A8, 0x25E48000, 0x25E4C000, level, LD32(0x060EC474));
        result = GCALL4(0x0602A470, 0x060E0A18, level, LD32(0x060EC474), LD32(0x060EC46C));
        ST16(0x060EC450, LD16(0x060EC450) | 0xF00);
    } else {
        result = mode;
    }
    return result;
}

void f0602A2A8(gaddr dst_a, gaddr dst_b, int rows, int scale)
{
    int step = DIVS(0x01680000, (short)rows);
    int angle = 0;
    int shape = (LDU16(0x060EC452) << 16) & 0x07FF0000;
    int n = ((LDU16(0x060FA9A0) & 192) == 192 ? 0x1C0 : 224) + rows;
    int u;
    int v;

    if (scale != 0) {
        if (shape != 0) {
            if ((short)n > 0) {
                do {
                    angle = MODS(angle + 0x021C0000, 0x01680000) - 0x00B40000;
                    u = GCALL1(0x0609812C, angle);
                    u = FMUL(u - 65536, scale);
                    u = FDIV(u + shape, shape) & 0x0003FF00;
                    v = (shape - FMUL(shape, u)) & 0x07FFFF00;
                    ST32(dst_b, v);
                    ST32(dst_a, v);
                    ST32(dst_b + 8, u);
                    ST32(dst_a + 8, u);
                    dst_b += 12;
                    dst_a += 12;
                    n = (short)(n - 1);
                    angle += step;
                } while (AGAIN((short)n > 0));
            }
        } else if ((short)n > 0) {
            do {
                angle = MODS(angle + 0x021C0000, 0x01680000) - 0x00B40000;
                u = FMUL(GCALL1(0x0609812C, angle), scale) & 0x07FFFF00;
                ST32(dst_b, u);
                ST32(dst_a, u);
                ST32(dst_b + 8, 0x00010000);
                ST32(dst_a + 8, 0x00010000);
                dst_b += 12;
                dst_a += 12;
                n--;
                angle += step;
            } while (AGAIN((short)n > 0));
        }
    } else if ((short)n > 0) {
        do {
            ST32(dst_b, 0);
            n--;
            ST32(dst_a, 0);
            ST32(dst_b + 8, 0x00010000);
            ST32(dst_a + 8, 0x00010000);
            dst_a += 12;
            dst_b += 12;
        } while (AGAIN((short)n > 0));
    }
}

void f0602A618(gaddr dst, short row, gaddr src)
{
    int n = (LDU16(0x060FA9A0) & 192) == 192 ? 0x1C0 : 224;
    int acc = 0;

    dst += row * 12 + 4;
    src += row * 4;
    if ((short)n > 0) {
        do {
            ST32(dst, (LD32(src) + acc) & 0x07FFFF00);
            n--;
            acc += 0x10000;
            dst += 12;
            src += 4;
        } while (AGAIN((short)n > 0));
    }
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

int f0602B072(int r4)
{
    int r0, r2, r3, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 48);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r0 = LD32(0x060C1040);
    r9 = r4;
    if ((r0 & 4) == 0) {
        r8 = 0x060B514C;
        ST32(sp - 48, 10);
    } else {
        r8 = 0x060B5174;
        ST32(sp - 48, 12);
    }
    r12 = 0;
    ST32(sp - 44, 0x060B5140);
    r10 = 0x100;
    r3 = LD32(sp - 48);
    r11 = 0;
    if (!(0 >= r3)) {
        do {
            r4 = LD16(r9);
            r5 = r9 + 2;
            ST32(sp - 40, r5);
            r5 = LD16(r5);
            r14 = (((r4 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(44 + r14, r12);
            r13 = (((r5 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(44 + r13, 1);
            r0 = LD16(r8);
            ST16(r13 + 16, r0);
            ST16(r14 + 16, r0);
            r0 = LD16(r8 + 2);
            r4 = r0 << 1;
            r5 = 0x060B5148 + r4;
            r0 = LD16(r5);
            ST16(r14 + 4, r0);
            r0 = LD16(r5);
            ST16(r13 + 4, (r0 - 1));
            r0 = LD16(0x060B5144 + r4);
            ST16(r13 + 18, r0);
            ST16(r14 + 18, r0);
            r0 = LD16(r14 + 18);
            ST16(r14 + 18, (r0 + 3));
            ST16(46 + r14, (((r11 << 2) << 2) + 0x200));
            SETSP((sp - 48));
            r0 = GCALL2(0x0606950C, r14, 1);
            ST16(46 + r13, r10);
            SETSP((sp - 48));
            r0 = GCALL2(0x0606950C, r13, 1);
            r5 = LD32(sp - 44);
            r4 = LD32(sp - 40);
            r5 = LD16(r5);
            r4 = LD16(r4);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(14, r14);
            SETSP((sp - 48));
            SETPR(0x0602B14A);
            r0 = GCALL2(0x06068A8E, r4, r5);
            ST16(62 + r14, r12);
            SETSP((sp - 48));
            r0 = GCALL2(0x0606AAC8, r14, 3);
            ST16(70 + r14, r10);
            ST16(68 + r14, r10);
            r4 = LD16(r9);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETSP((sp - 48));
            SETPR(0x0602B176);
            r0 = GCALL2(0x06068A8E, r4, ((short)(((((r11 << 2) << 2) + r11) << 1) + 238)));
            r11 = r11 + 1;
            r2 = LD32(sp - 48);
            r9 = r9 + 4;
            r8 = r8 + 4;
        } while (AGAIN(!(r11 >= r2)));
    }
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0602B198(int r4, int r5)
{
    int r0, r2, r3, r6, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 28);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = r5;
    ST32((sp - 24), PR());
    ST32(sp - 28, r4);
    r4 = r5;
    r5 = 0;
    r6 = r4 + 12;
    do {
        ST8(r4, r5);
        r4 = r4 + 1;
    } while (AGAIN(!((unsigned)r4 >= (unsigned)r6)));
    r2 = LD32(0x060C1048);
    if ((r2 & 0x00040000) == 0) {
        SETSP((sp - 28));
        r0 = GCALL1(0x0602B930, -1);
        ST8(0x060C1044, r0);
        SETSP((sp - 28));
        r0 = GCALL0(0x0602B8F0);
        ST8(0x060C122C, r0);
    } else {
        r13 = 0x060C064A;
        r12 = 3;
        r14 = 0x060C0640;
        r10 = 0x060C064A;
        while (!((unsigned)r14 >= (unsigned)r10)) {
            POLL();
            r3 = LD8(r14);
            if (!(((r3 & 255) & r12) == 0)) {
                r5 = LD32(sp - 28);
                r4 = LD8(r13);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x0602B21A);
                r0 = GCALL3(0x0602B24E, (r4 & 255), r5, r11);
            }
            r13 = r13 + 1;
            r14 = r14 + 1;
        }
        ST8(0x060C1044, 10);
        SETSP((sp - 28));
        r0 = GCALL0(0x0602B8F0);
        ST8(0x060C122C, r0);
    }
    SETPR(LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0602B24E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 12);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), MACL());
    r13 = r4;
    r14 = r5 + (((r13 & 0xFFFF) << 1) << 1);
    r2 = LD16(r14);
    ST16(38 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C), -60);
    r0 = LD16(r14 + 2);
    ST16((38 + ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C)), -60);
    r0 = r13 & 0xFFFF;
    r1 = LD8(r0 + r6);
    ST8(r0 + r6, (r1 | 128));
    r0 = LD16(r14);
    ST16(62 + ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C), 0x100);
    r4 = LD16(r14);
    SETMACL(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP2(0x06068ACC, r4, ((((((r13 & 0xFFFF) << 2) << 2) + (r13 & 0xFFFF)) << 1) + 245));
    return r0;
}

int f0602B2BC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 12);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), MACL());
    r13 = r4;
    r14 = r5 + (((r13 & 0xFFFF) << 1) << 1);
    r2 = LD16(r14);
    ST16(38 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C), 0);
    r0 = LD16(r14 + 2);
    r2 = 38 + ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C);
    r0 = r13 & 0xFFFF;
    ST16(r2, 0);
    r1 = LD8(r0 + r6);
    ST8(r0 + r6, (r1 & 127));
    r0 = LD16(r14);
    ST16(62 + ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C), 0);
    r4 = LD16(r14);
    SETMACL(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP2(0x06068ACC, r4, ((((((r13 & 0xFFFF) << 2) << 2) + (r13 & 0xFFFF)) << 1) + 238));
    return r0;
}

void f0602B328(unsigned short i, gaddr flags)
{
    ST8(flags + i, LD8(flags + i) | 128);
}

void f0602B334(unsigned short i, gaddr table)
{
    ST8(table + i, LD8(table + i) & 127);
}

int f0602B340(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 48);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    ST32(sp - 44, r5);
    r0 = LD32(0x060C1040);
    r13 = r4;
    if ((r0 & 4) == 0) {
        r4 = 10;
    } else {
        r4 = 12;
    }
    r11 = 0;
    r9 = 245;
    r4 = (short)r4;
    r10 = 0x06068A8E;
    r12 = 0;
    r14 = 0x060C381C;
    ST32(sp - 40, r4);
    r8 = -60;
    if (!(0 >= r4)) {
        do {
            r0 = LD32(sp - 44);
            r0 = LD8(r0);
            if ((r0 & 128) == 0) {
                r2 = LD16(r13);
                r0 = 38;
                r2 = LD16(38 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + r14));
                if (!(r2 >= 0)) {
                    ST16(sp - 48, (((((r12 << 2) << 2) + r12) << 1) + 238));
                    r5 = LD16(sp - 48);
                    r4 = LD16(r13);
                    SETR(8, r8);
                    SETR(9, r9);
                    SETR(10, r10);
                    SETR(11, r11);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 48));
                    SETPR(0x0602B446);
                    r0 = GCALL2(r10, r4, r5);
                    r2 = LD16(r13);
                    ST16(62 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + r14), r11);
                    r2 = LD16(r13);
                    r3 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r14;
                    r2 = LD16(38 + r3);
                    ST16(38 + r3, (r2 + 1));
                    r0 = LD16(r13 + 2);
                    r0 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + r14;
                    r1 = LD16(r0 + 38);
                    ST16(r0 + 38, (r1 + 1));
                }
            } else {
                r2 = LD16(r13);
                r0 = 38;
                r2 = LD16(38 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + r14));
                if (r2 > r8) {
                    r2 = LD16(r13);
                    r3 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r14;
                    r2 = LD16(38 + r3);
                    ST16(38 + r3, (r2 - 1));
                    r0 = LD16(r13 + 2);
                    r0 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + r14;
                    r1 = LD16(r0 + 38);
                    ST16(r0 + 38, (r1 - 1));
                    r0 = LD16(r13);
                    r0 = LD16(((((r0 & 0xFFFF) * 84) & 0xFFFF) + r14) + 38);
                    if (r0 == -60) {
                        ST16(sp - 48, (((((r12 << 2) << 2) + r12) << 1) + r9));
                        r5 = LD16(sp - 48);
                        r4 = LD16(r13);
                        SETR(8, r8);
                        SETR(9, r9);
                        SETR(10, r10);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 48));
                        SETPR(0x0602B404);
                        r0 = GCALL2(r10, r4, r5);
                        r2 = LD16(r13);
                        r0 = 62;
                        ST16(62 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + r14), 0x100);
                    }
                }
            }
            r12 = r12 + 1;
            r3 = LD32(sp - 44);
            ST32(sp - 44, (r3 + 1));
            r2 = LD32(sp - 40);
            r13 = r13 + 4;
        } while (AGAIN(!(r12 >= r2)));
    }
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0602B666(int r4)
{
    int r0, r1, r2, r3, r5, r7, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 56);

    r7 = 0x060C1654;
    r5 = r4 + 64;
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    r11 = 0x060C381C;
    ST32(sp - 56, r4);
    r12 = (sp - 56) + 8;
    r4 = r12;
    ST32(sp - 52, r4);
    r14 = r4 + 16;
    while (!((unsigned)r4 >= (unsigned)r14)) {
        POLL();
        r2 = LD16(r5);
        ST32(r4, r2);
        r5 = r5 + 2;
        r1 = LD16(r7);
        r3 = LD32(r4);
        r4 = r4 + 4;
        ST16(36 + ((((r3 & 0xFFFF) * 84) & 0xFFFF) + r11), (-r1));
    }
    r13 = 0x06068A8E;
    r4 = LD32(sp - 52);
    r4 = LD32(r4);
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, 0x06068A8E);
    SETSP((sp - 56));
    SETPR(0x0602B6BC);
    r0 = GCALL2(0x06068A8E, r4, 148);
    r10 = 0x060C1044;
    r14 = LD8(0x060C1044);
    r9 = r12 + 4;
    if (r14 >= 10) {
        r4 = LD32(r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETSP((sp - 56));
        SETPR(0x0602B712);
        r0 = GCALL2(r13, r4, 0);
        r5 = 0;
    } else {
        if (!(r14 >= 0)) {
            r4 = LD32(r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETSP((sp - 56));
            SETPR(0x0602B712);
            r0 = GCALL2(r13, r4, 0);
            r5 = 0;
        } else {
            r4 = LD32(r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETSP((sp - 56));
            SETPR(0x0602B6D6);
            r0 = GCALL2(r13, r4, (0x11E + r14));
            r5 = LD8(0x060C122C);
            r5 = LD16(0x060B51AC + ((r5 & 255) << 1));
        }
    }
    r4 = LD32(r12 + 8);
    SETR(10, r10);
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, r13);
    SETSP((sp - 56));
    SETPR(0x0602B718);
    r0 = GCALL2(r13, r4, r5);
    r2 = LD8(r10);
    r9 = r12 + 12;
    if (!(r2 >= 0)) {
        r4 = LD32(r9);
        SETSP((sp - 56));
        SETPR(0x0602B7B6);
        r0 = GCALL2(r13, r4, 0);
    } else {
        r2 = LD8(r10);
        r14 = LD32(r9);
        r14 = (((r14 & 0xFFFF) * 84) & 0xFFFF) + r11;
        if (r2 >= 10) {
            r4 = LD32(r9);
            SETR(14, r14);
            SETSP((sp - 56));
            SETPR(0x0602B786);
            r0 = GCALL2(r13, r4, 0x119);
            r0 = LD8(0x060B51AA);
            ST16(r14 + 16, (((r0 & 255) << 2) << 1));
            r0 = LD8(0x060B51AB);
            ST16(r14 + 18, (((r0 & 255) << 2) << 1));
            r0 = 46;
            r2 = LD16(46 + r14);
            ST16(46 + r14, (r2 & 0xFC00));
            r1 = LD16(46 + r14);
            ST16(46 + r14, (r1 | 0x360));
        } else {
            r4 = LD8(0x060C122C);
            r3 = LD32(sp - 56);
            r0 = LD16(((((r4 & 255) << 1) << 1) + r3));
            r4 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + r11;
            r0 = LD16(r4 + 16);
            ST16(r14 + 16, (r0 - 8));
            r3 = LD16(38 + r4);
            r0 = LD16(r4 + 18);
            ST16(r14 + 18, ((r0 + r3) - 30));
            r5 = LD8(r10);
            r4 = LD32(r12 + 12);
            SETR(14, r14);
            SETSP((sp - 56));
            SETPR(0x0602B76A);
            r0 = GCALL2(r13, r4, (r5 + 120));
            r0 = 46;
            r2 = LD16(46 + r14);
            ST16(46 + r14, (r2 & 0xFC00));
            r1 = LD16(46 + r14);
            ST16(46 + r14, (r1 | 0x370));
        }
    }
    SETMACL(LD32((sp - 32)));
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0602B916(int index)
{
    int result = GCALL1(0x0602B86E, index);

    if ((short)result < 0)
        result = GCALL1(0x0602B86E, 12);
    return result;
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

int f0602BFC6(int r4, int r5, int r6)
{
    int r0, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 32);

    ST32((sp - 4), PR());
    ST32(sp - 8, r5);
    ST32(sp - 12, r6);
    SETSP((sp - 12));
    SETPR(0x0602BFD2);
    r0 = GCALL1(0x0602BFE0, r4);
    r4 = LD32(sp - 8);
    SETSP((sp - 12));
    SETPR(0x0602BFD8);
    r0 = GCALL1(0x0602C0F8, r4);
    r4 = LD32(sp - 12);
    SETPR(LD32((sp - 4)));
    ST32((sp - 4), R(14));
    r7 = 1;
    ST32((sp - 8), R(13));
    r14 = 4;
    ST32((sp - 12), R(12));
    r6 = 0;
    r13 = 0x360;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), MACL());
    SETSP(sp - 32);
    r9 = 0x060C381C;
    r10 = 0x060B51C8;
    r11 = 0x1EA;
    r12 = 0xFC00;
    do {
        r5 = LD16((r6 << 1) + r4);
        r5 = (((r5 & 0xFFFF) * 84) & 0xFFFF) + r9;
        r8 = r6 << 1;
        r0 = LD8(r10 + r8);
        ST16(r5 + 16, (((r0 & 255) << 2) << 1));
        r0 = LD8((r8 + 1) + r10);
        ST16(r5 + 18, (((r0 & 255) << 2) << 1));
        r2 = LD16(46 + r5);
        ST16(46 + r5, (r2 & r12));
        if (r6 >= 3) {
            r2 = LD16(46 + r5);
            ST16(46 + r5, (r2 | r13));
        } else {
            r3 = LD16(46 + r5);
            ST16(46 + r5, (r3 | 0x370));
        }
        ST16(r5 + 4, r11);
        r6 = r6 + 1;
        ST16(44 + r5, r7);
    } while (AGAIN(!(r6 >= r14)));
    r8 = 128;
    r10 = 2;
    r6 = 0;
    do {
        r5 = LD16(((r6 + 4) << 1) + r4);
        r5 = (((r5 & 0xFFFF) * 84) & 0xFFFF) + r9;
        if ((r6 & r10) == 0) {
            r2 = -24;
        } else {
            r2 = 8;
        }
        ST16(36 + r5, r2);
        r0 = 38;
        if ((r6 & r7) == 0) {
            r3 = -44;
        } else {
            r3 = -28;
        }
        r6 = r6 + 1;
        ST16(r0 + r5, r3);
        ST16(r5 + 18, r8);
        r3 = LD16(46 + r5);
        ST16(46 + r5, (r3 & r12));
        r2 = LD16(46 + r5);
        ST16(46 + r5, (r2 | r13));
        ST16(r5 + 4, r11);
        r0 = 44;
        ST16(44 + r5, r7);
    } while (AGAIN(!(r6 >= r14)));
    SETMACL(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0602BFE0(int r4)
{
    int r0, r1, r2, r3, r6, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 40);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r12 = 0;
    ST32((sp - 16), R(11));
    r11 = 0;
    ST32((sp - 20), R(10));
    r10 = r4;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r8 = 0x060C381C;
    r9 = 0;
    while (!(r11 >= 10)) {
        POLL();
        r0 = LD8(0x060C0640 + r11);
        if (!(((r0 & 255) & 3) == 0)) {
            r2 = LD8(0x060C064A + r11);
            ST32(sp - 40, (r2 & 255));
            r1 = LD16(r10);
            r0 = LD16(r10 + 2);
            r13 = (((r1 & 0xFFFF) * 84) & 0xFFFF) + r8;
            r14 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + r8;
            ST16(44 + r13, r12);
            ST16(44 + r14, 1);
            r0 = LD16(((r9 + 1) << 1) + 0x060B514C);
            r6 = (1 ^ r0) << 1;
            r0 = LD16(0x060B5148 + r6);
            ST16(r13 + 4, r0);
            ST16(r14 + 4, 0x1EA);
            r0 = LD16((r9 << 1) + 0x060B514C);
            ST16(r14 + 16, r0);
            ST16(r13 + 16, r0);
            r0 = LD16(0x060B5144 + r6);
            ST16(r14 + 18, r0);
            ST16(r13 + 18, r0);
            ST16(36 + r14, -8);
            r2 = LD16(38 + r13);
            ST16(38 + r14, (r2 - 30));
            r3 = LD32(sp - 40);
            ST16(46 + r13, (((r3 << 2) << 2) + 0x200));
            SETSP((sp - 40));
            r0 = GCALL2(0x0606950C, r13, 1);
            ST16(46 + r14, 0x370);
            SETSP((sp - 40));
            r0 = GCALL2(0x0606950C, r14, 1);
            r14 = LD32(sp - 40);
            r4 = LD16(r10);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETSP((sp - 40));
            SETPR(0x0602C0D2);
            r0 = GCALL2(0x06068ACC, r4, (((((r14 << 2) << 2) + r14) << 1) + 238));
            ST16(62 + r13, r12);
            r9 = r9 + 2;
        }
        r11 = r11 + 1;
        r10 = r10 + 4;
    }
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
}

int f0602C0F8(int r4)
{
    int r0, r2, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 36);

    ST32((sp - 4), R(14));
    r14 = 0;
    ST32((sp - 8), R(13));
    r13 = r4;
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 1;
    ST32((sp - 24), R(9));
    r10 = 0x12C;
    r9 = 5;
    ST32((sp - 28), R(8));
    r12 = 128;
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r8 = 0x1DE;
    do {
        r2 = LD16(r13);
        r4 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(44 + r4, r11);
        ST16(r4 + 16, (((((r14 << 2) + r14) + 14) << 2) << 1));
        ST16(r4 + 18, r12);
        ST16(r4 + 4, r10);
        ST16(46 + r4, 0x2C0);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606950C, r4, 1);
        r4 = LD16(r13);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x0602C15A);
        r0 = GCALL2(0x06068A8E, r4, (r14 + r8));
        r14 = r14 + 1;
        r13 = r13 + 2;
    } while (AGAIN(!(r14 >= r9)));
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0602C2A8(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 68);

    ST32((sp - 4), R(14));
    r7 = 8;
    ST32((sp - 8), R(13));
    r6 = 4;
    ST32((sp - 12), R(12));
    r5 = 0;
    r13 = 0x060C1654;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r12 = 0x060C381C;
    r14 = sp - 68;
    do {
        r2 = LD16((r5 << 1) + r4);
        ST32(((r5 << 2) + r14), r2);
        if (!(r5 >= r6)) {
            r1 = LD16(r13);
            r3 = LD32((r5 << 2) + r14);
            ST16(36 + ((((r3 & 0xFFFF) * 84) & 0xFFFF) + r12), (-r1));
        }
        r5 = r5 + 1;
    } while (AGAIN(!(r5 >= r7)));
    r13 = 0x06068A8E;
    r4 = LD32(r14);
    SETR(12, r12);
    SETR(13, 0x06068A8E);
    SETR(14, r14);
    SETSP((sp - 68));
    SETPR(0x0602C300);
    r0 = GCALL2(0x06068A8E, r4, 149);
    r11 = 0x060C1044;
    r10 = LD8(0x060C1044);
    r9 = r14 + 4;
    if (r10 >= 10) {
        r4 = LD32(r9);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 68));
        SETPR(0x0602C336);
        r0 = GCALL2(r13, r4, 0);
        r4 = LD32(r14 + 8);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 68));
        SETPR(0x0602C33C);
        r0 = GCALL2(r13, r4, 0);
        r5 = 0x119;
    } else {
        if (!(r10 >= 0)) {
            r4 = LD32(r9);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x0602C336);
            r0 = GCALL2(r13, r4, 0);
            r4 = LD32(r14 + 8);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x0602C33C);
            r0 = GCALL2(r13, r4, 0);
            r5 = 0x119;
        } else {
            r4 = LD32(r9);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x0602C31A);
            r0 = GCALL2(r13, r4, (0x11E + r10));
            r5 = LD8(r11);
            r5 = LD8(0x060C064A + r5);
            r5 = LD16(0x060B51AC + ((r5 & 255) << 1));
            r4 = LD32(r14 + 8);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x0602C32C);
            r0 = GCALL2(r13, r4, r5);
            r5 = 0;
        }
    }
    r4 = LD32(r14 + 12);
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 68));
    SETPR(0x0602C342);
    r0 = GCALL2(r13, r4, r5);
    r5 = LD8(r11);
    r4 = r14 + 16;
    r10 = r14 + 32;
    if (!(r5 >= 0)) {
        r14 = r4;
        do {
            r4 = LD32(r14);
            SETR(10, r10);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x0602C396);
            r0 = GCALL2(r13, r4, 0);
            r14 = r14 + 4;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r10)));
    } else {
        if (r5 >= 10) {
            r14 = r4;
            do {
                r4 = LD32(r14);
                SETR(10, r10);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 68));
                SETPR(0x0602C396);
                r0 = GCALL2(r13, r4, 0);
                r14 = r14 + 4;
            } while (AGAIN(!((unsigned)r14 >= (unsigned)r10)));
        } else {
            r14 = r4;
            r8 = 0x060C122C;
            r11 = 0x114;
            do {
                r3 = LD32(r14);
                r0 = LD8(r8);
                ST16(((((r3 & 0xFFFF) * 84) & 0xFFFF) + r12) + 16, ((((((r0 & 255) << 2) + (r0 & 255)) + 14) << 2) << 1));
                r4 = LD32(r14);
                SETR(8, r8);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 68));
                SETPR(0x0602C382);
                r0 = GCALL2(r13, r4, r11);
                r14 = r14 + 4;
                r11 = r11 + 1;
            } while (AGAIN(!((unsigned)r14 >= (unsigned)r10)));
        }
    }
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0602C482(unsigned short n)
{
    int key = LDU8(0x060C0640 + n) & -4;
    int count = 0;
    int i;

    for (i = 0; (short)i < n; i++) {
        POLL();
        if ((LDU8(0x060C0640 + i) & 3) && (LDU8(0x060C0640 + i) & -4) == key)
            count++;
    }
    return count;
}

int f0602C4D8(unsigned short n)
{
    int count = 0;
    int i = 0;

    if (0 < n) {
        do {
            if (LDU8(0x060C0640 + i) & 3)
                count++;
            i++;
        } while (AGAIN((short)i < n));
    }
    return count;
}

int f0602C50C(unsigned short n)
{
    int count = 0;
    int i = 0;

    if (0 < n) {
        do {
            int hit = GCALL1(0x0602C430, i);

            i++;
            if ((short)hit)
                count++;
        } while (AGAIN((short)i < n));
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

int f0602C5EE(short n)
{
    int i = n - 1;

    if (i >= 0) {
        while ((short)GCALL1(0x0602C540, i) == 0) {
            i--;
            if (i < 0)
                break;
            POLL();
        }
    }
    return i >= 0 ? i : -1;
}

int f0602C61E(void)
{
    return GJUMP1(0x0602C5BC, -1);
}

int f0602C622(int level)
{
    int result = GCALL1(0x0602C5BC, level);

    if ((short)result < 0)
        result = GCALL1(0x0602C5BC, -1);
    return result;
}

int f0602C644(int level)
{
    int result = GCALL1(0x0602C5EE, level);

    if ((short)result < 0)
        result = GCALL1(0x0602C5EE, 5);
    return result;
}

void f0602C9B6(gaddr rec, short col, short row)
{
    int q = DIVS(col, 3);
    int r = MODS(col, 3);

    ST16(rec + 36, (q << 4) - (DIVS(row - 1, 3) << 3));
    ST16(rec + 38, -40 - (r << 4));
    ST16(rec + 4, 0x12B - r);
}

int f0602CE18(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14, c5;
    ENTRY_SP(sp);
    SETSP(sp - 68);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    SETSP((sp - 68));
    r0 = GCALL0(0x0606A9E4);
    SETSP((sp - 68));
    r0 = GCALL1(0x06008A96, 1);
    SETSP((sp - 68));
    r0 = GCALL2(0x06008ECA, 54, 0x200);
    SETSP((sp - 68));
    SETPR(0x0602CE48);
    r0 = GCALL1(0x06068BDC, 0x1EF);
    ST32(sp - 60, 0x210);
    r10 = 0x060B5220;
    r13 = 0x060E20DE;
    SETR(10, 0x060B5220);
    SETR(13, 0x060E20DE);
    SETSP((sp - 68));
    SETPR(0x0602CE58);
    r0 = GCALL1(0x06068BDC, 0x162);
    r0 = LD16(0x060B5228);
    ST16(0x060E20DE, r0);
    SETR(10, 0x060B5220);
    SETR(13, 0x060E20DE);
    SETSP((sp - 68));
    SETPR(0x0602CE62);
    r0 = GCALL1(0x06068BDC, ((short)r0));
    r0 = LD16(0x060B5224);
    SETSP((sp - 68));
    r0 = GCALL2(0x06008ECA, r0, 0x210);
    r9 = 0x060C381C;
    r12 = 0;
    ST8(0x060E20EA, 1);
    r8 = 5;
    ST32(sp - 68, 0);
    r11 = (sp - 68) + 12;
    do {
        r14 = LD32(sp - 68);
        SETSP((sp - 68));
        r0 = GCALL1(0x060691DA, 1);
        ST16(((r14 << 1) + r11), r0);
        r14 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + r9;
        ST16(44 + r14, 1);
        r2 = LD16(40 + r14);
        ST16(40 + r14, (r2 & 0xFBFF));
        r0 = LD32(sp - 68);
        if (!(r0 == 1)) {
            SETSP((sp - 68));
            r0 = GCALL2(0x0606AAC8, r14, 3);
            ST16(82 + r14, r12);
            ST16(80 + r14, r12);
            ST16(74 + r14, r12);
            ST16(72 + r14, r12);
            ST16(38 + r14, r12);
            ST16(36 + r14, r12);
        } else {
            SETSP((sp - 68));
            r0 = GCALL2(0x0606AAC8, r14, 2);
            ST16(36 + r14, 56);
            ST16(38 + r14, 112);
        }
        SETSP((sp - 68));
        r0 = GCALL1(0x0606AB24, r14);
        SETSP((sp - 68));
        r0 = GCALL2(0x0606950C, r14, 1);
        r3 = LD32(sp - 68);
        r3 = r3 + 1;
        ST32(sp - 68, r3);
    } while (AGAIN(!(r3 >= r8)));
    r4 = r11;
    ST32(sp - 64, r4);
    r4 = LD16(r4);
    SETR(8, r8);
    SETR(9, r9);
    SETR(10, r10);
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, r13);
    SETSP((sp - 68));
    SETPR(0x0602CF04);
    r0 = GCALL2(0x06068A8E, r4, 0x1EF);
    r2 = LD32(sp - 64);
    r2 = LD16(r2);
    ST16(46 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + r9), 0x200);
    r14 = r12;
    while (1) {
        r0 = LD8(r10 + 2);
        if (!(r14 >= (r0 & 255))) {
            POLL();
            r4 = LD16(r10);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x0602CF60);
            r0 = GCALL1(0x06068BDC, (r4 + r14));
            r5 = LD16(r10);
            r4 = ((r14 + 1) << 1) + r11;
            ST32(sp - 68, r4);
            r4 = LD16(r4);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x0602CF74);
            r0 = GCALL2(0x06068A8E, r4, (r5 + r14));
            r3 = LD32(sp - 68);
            r2 = LD16(r3);
            r14 = r14 + 1;
            r3 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r9;
            r1 = LD16(46 + r3);
            ST16(46 + r3, (r1 & 0xFC00));
            r3 = LD32(sp - 68);
            r1 = LD16(r3);
            c5 = (r1 & 0xFFFF) * 84;
            r1 = LD32(sp - 60);
            r3 = (c5 & 0xFFFF) + r9;
            r2 = LD16(46 + r3);
            ST16(46 + r3, (r2 | r1));
            continue;
        } else {
            break;
        }
    }
    if (!(r14 >= r8)) {
        do {
            r14 = r14 + 1;
        } while (AGAIN(!(r14 >= r8)));
    }
    r4 = 1;
    ST8(r13 + 13, r12);
    r5 = 8;
    r0 = LD32(sp - 64);
    r0 = LD16(r0);
    ST16(r13 + 2, r0);
    r0 = LD16(r11 + 2);
    ST16(r13 + 4, r0);
    r0 = LD16(r11 + 4);
    ST16(r13 + 6, r0);
    r0 = LD16(r11 + 6);
    ST16(r13 + 8, r0);
    r0 = LD16(r11 + 8);
    ST16(r13 + 10, r0);
    r13 = r13 + 14;
    do {
        r0 = r12;
        r4 = r4 + 1;
        ST16(r13 + 10, r0);
        ST16(r13 + 8, r0);
        ST16(r13 + 6, r0);
        ST16(r13 + 4, r0);
        ST16(r13 + 2, r0);
        r13 = r13 + 14;
    } while (AGAIN(!(r4 >= r5)));
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0602D180(void)
{
    int r0, r1, r2, r3, r4, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 56);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    SETSP((sp - 52));
    r0 = GCALL1(0x06008A96, 1);
    SETSP((sp - 52));
    r0 = GCALL2(0x06008ECA, 66, 0x180);
    SETSP((sp - 52));
    r0 = GCALL2(0x06008ECA, 57, 0x1C0);
    SETSP((sp - 52));
    SETPR(0x0602D1B2);
    r0 = GCALL1(0x06068BDC, 0x128);
    r14 = (sp - 52) + 8;
    r9 = r14;
    SETSP((sp - 52));
    r0 = GCALL1(0x060691DA, 0x15E);
    r2 = r9 + 2;
    ST16(0x060C0FB8, r0);
    ST16(r9, r0);
    ST32(sp - 48, r2);
    ST32((sp - 56), r2);
    SETR(9, r9);
    SETR(13, 0x060691DA);
    SETR(14, r14);
    SETSP((sp - 56));
    SETPR(0x0602D1D0);
    r0 = GCALL1(0x060691DA, 0x15E);
    r14 = r14 + 4;
    ST16(0x060C0FBA, r0);
    r1 = LD32((sp - 56));
    ST16(r1, r0);
    ST32(sp - 52, r14);
    SETR(9, r9);
    SETR(14, r14);
    SETSP((sp - 52));
    SETPR(0x0602D1E0);
    r0 = GCALL1(0x060691DA, 90);
    ST16(0x060C0FBC, r0);
    ST16(r14, r0);
    r4 = LD32(sp - 52);
    r4 = LD16(r4);
    SETSP((sp - 52));
    r0 = GCALL2(0x0606AB08, r4, 3);
    r12 = 0x060C381C;
    r13 = 0;
    r10 = 0;
    r11 = r9;
    r8 = 1;
    do {
        r2 = LD16(r11);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r12;
        ST16(44 + r14, r8);
        ST16(46 + r14, r13);
        SETSP((sp - 52));
        r0 = GCALL2(0x0606950C, r14, 1);
        SETSP((sp - 52));
        r0 = GCALL1(0x0606AB24, r14);
        r10 = r10 + 1;
        ST16(38 + r14, r13);
        ST16(36 + r14, r13);
        ST16(74 + r14, r13);
        ST16(72 + r14, r13);
        r11 = r11 + 2;
    } while (AGAIN(!(((short)r10) >= 3)));
    r2 = LD16(r9);
    ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + r12) + 16, 112);
    r2 = LD16(r9);
    ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + r12) + 18, 32);
    r3 = LD32(sp - 48);
    r3 = LD16(r3);
    ST16(((((r3 & 0xFFFF) * 84) & 0xFFFF) + r12) + 16, 96);
    r3 = LD32(sp - 48);
    r3 = LD16(r3);
    ST16(((((r3 & 0xFFFF) * 84) & 0xFFFF) + r12) + 18, 120);
    r14 = LD32(sp - 52);
    r2 = LD16(r14);
    r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r12;
    ST16(r14 + 16, 128);
    ST16(r14 + 18, 128);
    r2 = LD16(r9);
    r3 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r12;
    r1 = LD16(46 + r3);
    ST16(46 + r3, (r1 | 0x180));
    r3 = LD32(sp - 48);
    r2 = LD16(r3);
    r3 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r12;
    r1 = LD16(46 + r3);
    ST16(46 + r3, (r1 | 0x1C0));
    r4 = LD32(sp - 52);
    r4 = LD16(r4);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 52));
    SETPR(0x0602D2C8);
    r0 = GCALL2(0x06068A8E, r4, 0x128);
    ST16(72 + r14, 32);
    ST16(74 + r14, r13);
    ST16(70 + r14, r13);
    ST16(68 + r14, r13);
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 68;
}

int f0602D36E(short row, short x, short y, short speed)
{
    FRAME(sp, 0);
    gaddr src = 0x060E20DE + (signed char)(row * 14);
    int ids[5];
    int k;
    int result;

    for (k = 0; k < 5; k++)
        ids[k] = LD16(src + 2 + k * 2);
    k = 0;
    do {
        if (ids[k] != 0) {
            gaddr obj = OBJ(ids[k] & 0xFFFF);

            ST16(obj + 68, speed);
            ST16(obj + 70, speed);
            ST16(obj + 16, x);
            ST16(obj + 18, y);
            ST16(obj + 4, LDU8(0x060B522A + k) + LD16(sp + 2));
        }
        k++;
    } while (AGAIN(k < 5));
    result = HELPER(speed * 544 >> 8);
    ST16(OBJ(ids[1] & 0xFFFF) + 70, result);
    return result;
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

void f0602D752(void)
{
    GJUMP0(0x0602D784);
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

int f0602E2EA(void)
{
    int list[8];
    int n = 0;
    int k = 0;

    do {
        if (LD8(0x060E1C4E + k))
            list[n++] = k;
        k++;
    } while (AGAIN(k < 8));
    if (n != 0)
        return list[MODU(GCALL0(0x0600A0E0), n)];
    GCALL0(0x0602E2B0);
    return GCALL0(0x0602E2EA);
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

int f0602E408(int a)
{
    ENTRY_SP(sp);
    SETSP(sp);
    SETPR(0x0602E40E);
    GCALL1(0x0602FD74, a);
    UNFRAME(sp);
    SETSP(sp);
    return GJUMP0(0x0602E44C);
}

int f0602E40E(void)
{
    return GJUMP0(0x0602E44C);
}

int f0602E420(void)
{
    ENTRY_SP(sp);
    SETSP(sp);
    SETPR(0x0602E426);
    GCALL0(0x06051A78);
    SETPR(0x0602E43C);
    GCALL0(0x0602F66A);
    UNFRAME(sp);
    SETSP(sp);
    return GJUMP0(0x0602E44C);
}

int f0602E43C(void)
{
    return GJUMP0(0x0602E44C);
}

int f0602E4E8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r14;
    ENTRY_SP(sp);
    SETSP(sp - 8);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0602E4F0);
    r0 = GCALL4(0x0602E686, 0, r5, r6, r7);
    r0 = LD32(0x060C1048);
    if ((r0 & 15) == 1) {
        SETSP((sp - 8));
        r0 = GCALL1(0x0602E5E4, 0);
        SETSP((sp - 8));
        r0 = GCALL1(0x0602E5E4, 1);
    }
    r14 = 0x0602F1C0;
    r0 = LD32(0x060C1048);
    r0 = r0 & 15;
    if (r0 == 1) {
        r5 = 1;
        r4 = 21;
        SETSP((sp - 8));
        SETPR(0x0602E550);
        r0 = GCALL4(r14, r4, r5, r6, r7);
    } else {
        if (r0 == 2) {
            r1 = LD32(0x060C0AA8);
            if ((r1 & r1) == 0) {
                r0 = LD8(0x060C1008);
                if (!((r0 & r0) == 0)) {
                    r5 = 2;
                    r4 = 2;
                } else {
                    r5 = 1;
                    r4 = 2;
                }
                SETSP((sp - 8));
                SETPR(0x0602E53E);
                r0 = GCALL4(r14, r4, r5, r6, r7);
            } else {
                r5 = 1;
                r4 = 1;
                SETSP((sp - 8));
                SETPR(0x0602E550);
                r0 = GCALL4(r14, r4, r5, r6, r7);
            }
        } else {
            if (r0 == 3) {
                r5 = 1;
                r4 = 2;
                SETSP((sp - 8));
                SETPR(0x0602E550);
                r0 = GCALL4(r14, r4, r5, r6, r7);
            }
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0602E53E(void)
{
    GJUMP0(0x0602E550);
}

void f0602E5BE(void)
{
    GJUMP0(0x0602E5DC);
}

void f0602E5C8(void)
{
    GJUMP0(0x0602E5DC);
}

void f0602E5D2(void)
{
    GJUMP0(0x0602E5DC);
}

void f0602E5E4(unsigned char n)
{
    unsigned int current = LD32(0x060C0690 + n * 4);
    unsigned int lowest = LD32(0x060C0FDC + n * 4);
    unsigned short stop;
    unsigned short i;

    if (current < lowest) {
        lowest = current;
    }
    ST32(0x060C0FDC + n * 4, current);
    stop = GCALL1(0x0602E656, current);
    i = GCALL1(0x0602E656, lowest);
    if (stop > i) {
        if (LDU8(0x060C063E) < 9) {
            GCALL1(0x0600996A, 21);
        }
        do {
            GCALL0(0x06018D0C);
            i++;
        } while (AGAIN(stop > i));
    }
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

int f0602E686(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);
    SETSP(sp - 12);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r0 = LD32(0x060C1048);
    if (!((r0 & 15) == 2)) {
        SETSP((sp - 12));
        r0 = GCALL4(0x0602E7A0, (sp - 12), r5, r6, r7);
    } else {
        SETSP((sp - 12));
        r0 = GCALL1(0x0602E752, (sp - 12));
    }
    r2 = LD16(0x060BF5EA);
    r4 = r0;
    if ((r2 & r2) == 0) {
        r14 = 0x060D7E68;
        r0 = LD32(sp - 12);
        if (!((r0 & r0) == 0)) {
            r5 = 0x060C0FE4;
            r0 = LD16(r14);
            if (!(((r0 & 0xFFFF) & 32) == 0)) {
                r3 = LD8(r5);
                if ((r3 & 255) == r4) {
                    SETR(14, r14);
                    SETSP((sp - 12));
                    SETPR(0x0602E726);
                    r0 = GCALL4(0x0602F624, r4, r5, r6, r7);
                    SETSP((sp - 12));
                    r0 = GCALL0(0x0602EA24);
                    r2 = LD16(r14);
                    ST16(r14, (r2 & 0xFFDF));
                }
            } else {
                r2 = LD32(0x060C0AA8);
                if (!((r2 & r2) == 0)) {
                    r3 = LD8(r5);
                    if ((r3 & 255) == r4) {
                        SETR(14, r14);
                        SETSP((sp - 12));
                        SETPR(0x0602E726);
                        r0 = GCALL4(0x0602F624, r4, r5, r6, r7);
                        SETSP((sp - 12));
                        r0 = GCALL0(0x0602EA24);
                        r2 = LD16(r14);
                        ST16(r14, (r2 & 0xFFDF));
                    }
                } else {
                    r0 = LD16(r14);
                    if (((r0 & 0xFFFF) & 83) == 0) {
                        ST8(r5, r4);
                        r0 = LD16(r14);
                        ST16(r14, (r0 | 32));
                        SETR(14, r14);
                        SETSP((sp - 12));
                        SETPR(0x0602E714);
                        r0 = GCALL0(0x0602EA04);
                    }
                }
            }
        }
        r0 = LD16(r14);
        if (((r0 & 0xFFFF) & 32) == 0) {
            SETSP((sp - 12));
            r0 = GCALL4(0x0602F640, r4, r5, r6, r7);
        } else {
            SETSP((sp - 12));
            r0 = GCALL4(0x0602F638, r4, r5, r6, r7);
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0602E836(gaddr out)
{
    int i;

    ST32(out, 0);
    for (i = 0; i < LDU8(BOMBER_COUNT); i++) {
        POLL();
        if (!LD8(0x26006134 + i) && LD16(REC(i) + 22) != 0 && (LDU16(0x260060B0 + i * 2) & 0x800)) {
            ST32(out, 0x800);
            break;
        }
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

int f0602E932(void)
{
    int mask = 0;
    int i;

    for (i = 0; i < LDU8(BOMBER_COUNT); i++) {
        POLL();
        if (GCALL1(0x0602E9AE, i))
            mask |= LDU16(0x26006096 + i * 2);
    }
    return mask;
}

int f0602E970(void)
{
    int mask = 0;
    int i;

    for (i = 0; i < LDU8(BOMBER_COUNT); i++) {
        POLL();
        if (GCALL1(0x0602E9AE, i))
            mask |= LDU16(0x260060B0 + i * 2);
    }
    return mask;
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

int f0602EA98(int a)
{
    ENTRY_SP(sp);
    SETSP(sp);
    SETPR(0x0602EA9E);
    GCALL1(0x06030C80, a);
    UNFRAME(sp);
    SETSP(sp);
    return GJUMP0(0x0602EB44);
}

int f0602EA9E(void)
{
    return GJUMP0(0x0602EB44);
}

int f0602EAB0(void)
{
    ENTRY_SP(sp);
    SETSP(sp);
    SETPR(0x0602EAB6);
    GCALL0(0x06051A78);
    SETPR(0x0602EACC);
    GCALL0(0x0602F66A);
    UNFRAME(sp);
    SETSP(sp);
    return GJUMP0(0x0602EB44);
}

int f0602EACC(void)
{
    return GJUMP0(0x0602EB44);
}

void f0602ECCE(void)
{
    gaddr p = 0x060C101C;

    do {
        GCALL1(0x060692DC, LDU16(p));
        p += 2;
    } while (AGAIN(p < 0x060C1026));
}

int f0602ECF6(gaddr text)
{
    int mode;

    ST32(0x060C1000, GCALL1(0x0602EE3A, text));
    mode = LDU8(0x060C1004);
    if (mode != 1)
        ST8(0x060C1004, 0);
    ST8(0x060C101B, 1);
    return mode;
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

int f0602EDC8(gaddr text)
{
    int result = GCALL1(0x0602EE3A, text);

    ST16(0x060C0FFC, result);
    ST8(0x060C101B, 1);
    return result;
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

int f0602EE3A(gaddr str)
{
    int total = 0;
    int n = 0;

    while (LD8(str) != 58) {
        POLL();
        if (LD8(str) == 0)
            return 0;
        n = n * 10 + (LD8(str) - 48);
        str++;
    }
    str++;
    total += n * 0xE10;
    n = 0;
    while (LD8(str) != 46) {
        POLL();
        if (LD8(str) == 0)
            return 0;
        n = n * 10 + (LD8(str) - 48);
        str++;
    }
    str++;
    total += n * 60;
    n = 0;
    while (LD8(str) != 0) {
        POLL();
        n = n * 10 + (LD8(str) - 48);
        str++;
    }
    return total + DIVU(n * 5, 3);
}

int f0602EFC2(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 44);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = 0x06068A8E;
    r14 = 0x060C101C;
    r12 = ((r6 & 255) << 2) << 1;
    ST32((sp - 16), R(11));
    r11 = r4 & 255;
    ST32((sp - 20), R(10));
    r10 = 10;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r8 = ((r7 & 255) << 2) << 1;
    ST8(sp - 44, r5);
    r9 = 0x060C101C;
    if (!(r11 > 9)) {
        r5 = 0;
    } else {
        SETSP((sp - 44));
        r0 = DIVS(r11, r10);
        r5 = r0 + 59;
    }
    r4 = LD16(r9);
    SETR(8, r8);
    SETR(10, r10);
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x0602F02C);
    r0 = GCALL4(r13, (r4 & 0xFFFF), r5, r6, r7);
    SETSP((sp - 44));
    r0 = MODS(r11, r10);
    r5 = r0 + 59;
    r0 = LD16(r14 + 2);
    SETR(8, r8);
    SETR(10, r10);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x0602F03E);
    r0 = GCALL2(r13, (r0 & 0xFFFF), r5);
    r0 = LD16(r14 + 4);
    SETR(8, r8);
    SETR(10, r10);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x0602F046);
    r0 = GCALL2(r13, (r0 & 0xFFFF), 69);
    r1 = LD8(sp - 44);
    r1 = r1 & 255;
    ST32(sp - 40, r1);
    SETSP((sp - 44));
    r0 = DIVS(r1, r10);
    r5 = r0;
    r0 = LD16(r14 + 6);
    SETR(8, r8);
    SETR(10, r10);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x0602F05C);
    r0 = GCALL2(r13, (r0 & 0xFFFF), (r5 + 59));
    r1 = LD32(sp - 40);
    SETSP((sp - 44));
    r0 = MODS(r1, r10);
    r5 = r0 + 59;
    r0 = LD16(r14 + 8);
    SETR(8, r8);
    SETR(12, r12);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x0602F06E);
    r0 = GCALL2(r13, (r0 & 0xFFFF), r5);
    r13 = 5;
    r7 = 0xFC00;
    r5 = 0;
    r10 = 0x060C1006;
    r11 = 0x060C381C;
    r6 = 0x060C1008;
    do {
        r1 = LD8(r6);
        r4 = LD16(((r5 & 255) << 1) + r14);
        r4 = (((r4 & 0xFFFF) * 84) & 0xFFFF) + r11;
        SETSP((sp - 44));
        r0 = SHL((r12 & 0xFFFF), (r1 & 255));
        ST16(r4 + 16, r0);
        r1 = LD8(r6);
        SETSP((sp - 44));
        r0 = SHL((r8 & 0xFFFF), (r1 & 255));
        ST16(r4 + 18, r0);
        r5 = r5 + 1;
        r0 = 46;
        r1 = LD16(46 + r4);
        ST16(46 + r4, (r1 & r7));
        r2 = LD16(r10);
        r1 = LD16(46 + r4);
        ST16(46 + r4, (r1 | r2));
        r12 = r12 + 8;
    } while (AGAIN(!((r5 & 255) >= r13)));
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0602F1C0(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 40);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r8 = 0x060C100A;
    ST8(sp - 36, r4);
    ST8(sp - 40, r5);
    r1 = LD16(0x060C100A);
    if (!((r1 & r1) == 0)) {
        r14 = 0x060C1000;
        r0 = LD32(0x060C1000);
        if ((r0 & r0) == 0) {
            SETSP((sp - 40));
            r0 = GCALL0(0x0602EE02);
        }
        r13 = 0x060D7E68;
        r0 = LD16(0x060D7E68);
        if (!(((r0 & 0xFFFF) & 82) == 0)) {
            SETSP((sp - 40));
            r0 = GCALL0(0x0602EE02);
        }
        r0 = LD16(r13);
        if (((r0 & 0xFFFF) & 33) == 0) {
            SETSP((sp - 40));
            r0 = GCALL0(0x0602EE22);
        } else {
            SETSP((sp - 40));
            r0 = GCALL0(0x0602EE18);
        }
        r10 = 0x200;
        r9 = 1;
        r11 = 128;
        r12 = 0x060069B2;
        r2 = LD16(r13);
        if (((r2 & 0xFFFF) & 1) == 0) {
            r4 = 0x060C0FFC;
            r13 = LD16(r8);
            r1 = LD16(0x060C0FFC);
            r13 = r13 & 0xFFFF;
            if ((r1 & r1) == 0) {
                if (!((r13 & r11) == 0)) {
                    if ((3 & r13) == 0) {
                        r1 = LD32(0x060C1000);
                        if (!((unsigned)r1 >= (unsigned)((int)0x80000000))) {
                            r3 = LD32(r14);
                            r3 = r3 - 1;
                            ST32(r14, r3);
                            if ((r3 & r3) == 0) {
                                SETSP((sp - 40));
                                r0 = GCALL4(r12, 0x0602F4C0, 0x060E1698, r10, 1);
                            }
                        }
                    }
                }
            } else {
                if (!((r13 & r11) == 0)) {
                    if ((3 & r13) == 0) {
                        r3 = LD16(r4);
                        ST16(r4, (r3 - 1));
                    }
                }
            }
        }
        r0 = LD8(sp - 40);
        r5 = r0 & 63;
        r0 = LD8((sp - 36));
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x0602F2BE);
        r0 = GCALL2(0x0602EF00, (r0 & 63), r5);
        r4 = LD16(r8);
        r4 = r4 & 0xFFFF;
        if (!((r11 & r4) == 0)) {
            if ((3 & r4) == 0) {
                r2 = LD8(0x060C1004);
                if ((r2 & r2) == 0) {
                    r4 = 0x060E1498;
                    r0 = LD32(0x060C1048);
                    r0 = r0 & 15;
                    if (!(r0 == 2)) {
                        r2 = LD32(r14);
                        if (!((unsigned)r2 > (unsigned)0x708)) {
                            SETSP((sp - 40));
                            r0 = GCALL4(r12, 0x0602F412, r4, r10, 1);
                            ST8(0x060C1004, r9);
                        }
                    } else {
                        r2 = LD32(r14);
                        if (!((unsigned)r2 > (unsigned)0xEC4)) {
                            SETSP((sp - 40));
                            r0 = GCALL4(r12, 0x0602F412, r4, r10, 1);
                            ST8(0x060C1004, r9);
                        }
                    }
                }
            }
        }
    } else {
        r0 = LD8(0x060C101B);
        if (!((r0 & r0) == 0)) {
            r14 = 0x060C1000;
            r0 = LD32(0x060C1000);
            if ((r0 & r0) == 0) {
                SETSP((sp - 40));
                r0 = GCALL0(0x0602EE02);
            }
            r13 = 0x060D7E68;
            r0 = LD16(0x060D7E68);
            if (!(((r0 & 0xFFFF) & 82) == 0)) {
                SETSP((sp - 40));
                r0 = GCALL0(0x0602EE02);
            }
            r0 = LD16(r13);
            if (((r0 & 0xFFFF) & 33) == 0) {
                SETSP((sp - 40));
                r0 = GCALL0(0x0602EE22);
            } else {
                SETSP((sp - 40));
                r0 = GCALL0(0x0602EE18);
            }
            r10 = 0x200;
            r9 = 1;
            r11 = 128;
            r12 = 0x060069B2;
            r2 = LD16(r13);
            if (((r2 & 0xFFFF) & 1) == 0) {
                r4 = 0x060C0FFC;
                r13 = LD16(r8);
                r1 = LD16(0x060C0FFC);
                r13 = r13 & 0xFFFF;
                if ((r1 & r1) == 0) {
                    if (!((r13 & r11) == 0)) {
                        if ((3 & r13) == 0) {
                            r1 = LD32(0x060C1000);
                            if (!((unsigned)r1 >= (unsigned)((int)0x80000000))) {
                                r3 = LD32(r14);
                                r3 = r3 - 1;
                                ST32(r14, r3);
                                if ((r3 & r3) == 0) {
                                    SETSP((sp - 40));
                                    r0 = GCALL4(r12, 0x0602F4C0, 0x060E1698, r10, 1);
                                }
                            }
                        }
                    }
                } else {
                    if (!((r13 & r11) == 0)) {
                        if ((3 & r13) == 0) {
                            r3 = LD16(r4);
                            ST16(r4, (r3 - 1));
                        }
                    }
                }
            }
            r0 = LD8(sp - 40);
            r5 = r0 & 63;
            r0 = LD8((sp - 36));
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(14, r14);
            SETSP((sp - 40));
            SETPR(0x0602F2BE);
            r0 = GCALL2(0x0602EF00, (r0 & 63), r5);
            r4 = LD16(r8);
            r4 = r4 & 0xFFFF;
            if (!((r11 & r4) == 0)) {
                if ((3 & r4) == 0) {
                    r2 = LD8(0x060C1004);
                    if ((r2 & r2) == 0) {
                        r4 = 0x060E1498;
                        r0 = LD32(0x060C1048);
                        r0 = r0 & 15;
                        if (!(r0 == 2)) {
                            r2 = LD32(r14);
                            if (!((unsigned)r2 > (unsigned)0x708)) {
                                SETSP((sp - 40));
                                r0 = GCALL4(r12, 0x0602F412, r4, r10, 1);
                                ST8(0x060C1004, r9);
                            }
                        } else {
                            r2 = LD32(r14);
                            if (!((unsigned)r2 > (unsigned)0xEC4)) {
                                SETSP((sp - 40));
                                r0 = GCALL4(r12, 0x0602F412, r4, r10, 1);
                                ST8(0x060C1004, r9);
                            }
                        }
                    }
                }
            }
        }
    }
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0602F57C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 36);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = 0;
    r14 = 0x060C0FF4;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r10 = 4;
    r11 = 0xFFDF;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r8 = 0x06068A8E;
    r9 = 0x060C381C;
    do {
        r3 = LD16(r14);
        r3 = (((r3 & 0xFFFF) * 84) & 0xFFFF) + r9;
        r2 = LD16(42 + r3);
        ST16(42 + r3, (r2 & r11));
        r4 = LD16(r14);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x0602F5B8);
        r0 = GCALL2(r8, (r4 & 0xFFFF), 0);
        r13 = r13 + 1;
        r14 = r14 + 2;
    } while (AGAIN(!((r13 & 0xFFFF) >= r10)));
    ST8(0x060C101A, 8);
    r1 = LD32(0x060C102C);
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    SETSP(sp);
    r0 = GJUMP0(r1);
    return r0;
}

int f0602F624(void)
{
    int r0, r3;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    r3 = LD32(0x060C1030);
    SETSP((sp - 4));
    SETPR(0x0602F62E);
    r0 = GCALL0(r3);
    SETPR(LD32((sp - 4)));
    ST8(0x060C101A, 0);
    return 0x060C101A;
}

void f0602F638(void)
{
    GJUMP0(LD32(0x060C1034));
}

void f0602F640(int a, int b, int c, int d)
{
    GJUMP4(LD32(0x060C1038), a, b, c, d);
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

int f0602F66A(void)
{
    int r0, r4, r5, r6, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 24);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 24));
    r0 = COPYB((sp - 24), 0x060B1B58, 10);
    r6 = 0x060C0FF0;
    r5 = 0x060C0FEC;
    r4 = 0x060C0FE8;
    r0 = LD16(0x060BF5EA);
    r13 = 0;
    if ((r0 & r0) == 0) {
        ST32(r4, 0x0602F75C);
        ST32(r5, 0x0602F8FE);
        ST32(r6, 0x0602FAF8);
    } else {
        ST32(r4, 0x060309FC);
        ST32(r5, r13);
        ST32(r6, r13);
    }
    SETSP((sp - 24));
    r0 = GCALL0(0x0602F374);
    ST32(0x060C102C, 0x0602FBD4);
    ST32(0x060C1030, 0x0602FCC6);
    ST32(0x060C1034, 0x0602FCCE);
    ST32(0x060C1038, 0x0602FD10);
    SETSP((sp - 24));
    r0 = GCALL1(0x06008A96, 1);
    r14 = 0x06008ECA;
    r0 = LD8(0x060C1008);
    if (!((r0 & r0) == 0)) {
        SETSP((sp - 24));
        r0 = GCALL2(r14, 79, 80);
        r5 = 32;
    } else {
        SETSP((sp - 24));
        r0 = GCALL2(r14, 79, 0x350);
        r5 = 0x340;
    }
    SETSP((sp - 24));
    r0 = GCALL2(r14, 78, r5);
    SETR(13, r13);
    SETSP((sp - 24));
    SETPR(0x0602F6EE);
    r0 = GCALL1(0x060689F8, (sp - 24));
    ST8(0x060C101A, r13);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0602FBD4(void)
{
    int r0, r1, r2, r4, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 20);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    ST32(sp - 20, 0x060C0FF4);
    r2 = LD16(0x060C0FF4);
    r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    ST16(44 + r14, 1);
    r4 = LD32(sp - 20);
    r4 = LD16(r4);
    SETR(14, r14);
    SETSP((sp - 20));
    SETPR(0x0602FC02);
    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 0x25E);
    r13 = 0x060C1008;
    r0 = LD8(0x060C1008);
    if (!((r0 & r0) == 0)) {
        ST16(46 + r14, 80);
    } else {
        ST16(46 + r14, 0x350);
    }
    r2 = LD8(r13);
    if ((r2 & r2) == 0) {
        SETSP((sp - 20));
        r0 = GCALL2(0x0606950C, r14, 6);
    }
    SETSP((sp - 20));
    r0 = GCALL1(0x0606AB24, r14);
    SETSP((sp - 20));
    r0 = GCALL2(0x0606AAC8, r14, 3);
    r1 = LD8(r13);
    SETSP((sp - 20));
    r0 = SHL(160, (r1 & 255));
    ST16(r14 + 16, r0);
    r1 = LD8(r13);
    SETSP((sp - 20));
    r0 = SHL(112, (r1 & 255));
    ST16(r14 + 18, r0);
    r1 = LD8(r13);
    if (!((r1 & r1) == 0)) {
        ST16(70 + r14, 0x200);
        r0 = 68;
        ST16(68 + r14, 0x200);
    } else {
        ST16(70 + r14, 0x100);
        r0 = 68;
        ST16(68 + r14, 0x100);
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0602FCC6(void)
{
    return GJUMP1(0x06009A3A, 7);
}

int f0602FCCE(void)
{
    if (GCALL0(0x0602E88E)) {
        gaddr obj = OBJ(LDU16(0x060C0FF4));

        ST16(obj + 70, 0);
        ST16(obj + 68, 0);
    }
    if (GCALL0(0x0602F648) == 0)
        return 0;
    return GJUMP1(0x0600996A, 7);
}

int f0602FD10(void)
{
    int r0, r4, r11, r12, r13, r14;
    ENTRY_SP(sp);
    SETSP(sp - 20);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = 0;
    r14 = 0x060C0FF4;
    r12 = 4;
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r11 = 0x06068A8E;
    do {
        r4 = LD16(r14);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 20));
        SETPR(0x0602FD2A);
        r0 = GCALL2(r11, (r4 & 0xFFFF), 0);
        r13 = r13 + 1;
        r14 = r14 + 2;
    } while (AGAIN(!((r13 & 0xFFFF) >= r12)));
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

void f0602FF0A(void)
{
    ST8(0x060C103C, 0);
}




/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B7CA(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    SETSP((sp - 4));
    ST32((sp - 8), R(13));
    SETSP((sp - 8));
    ST32((sp - 12), R(12));
    SETSP((sp - 12));
    ST32((sp - 16), R(11));
    SETSP((sp - 16));
    SETSP((sp - 28));
    r0 = LD32(0x060C1040);
    if ((r0 & 4) == 0) {
        r11 = 10;
    } else {
        r11 = 12;
    }
    r7 = sp - 28;
    r6 = r7;
    r12 = 1;
    r13 = 12;
    r14 = 0;
    r5 = 0;
    do {
        r5 = r5 + 1;
        ST8(r6, r12);
        r6 = r6 + 1;
    } while (AGAIN(!(r5 >= r13)));
    r6 = 0x060C064A;
    r13 = r14;
    r1 = 0x060C1044;
    r5 = 0x060C0640;
    r12 = 3;
    while (1) {
        r3 = LD8(r1);
        if (!(r13 >= r3)) {
            POLL();
            r2 = LD8(r5);
            r13 = r13 + 1;
            if (!(((r2 & 255) & r12) == 0)) {
                r0 = LD8(r6);
                ST8((r0 & 255) + r7, r14);
            }
            r6 = r6 + 1;
            r5 = r5 + 1;
            continue;
        } else {
            break;
        }
    }
    r4 = ((short)r4) + 1;
    if (!(r4 >= r11)) {
        while (1) {
            r2 = LD8(r7 + r4);
            if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                break;
            } else {
                r4 = r4 + 1;
                if (!(r4 >= r11)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    if (r4 >= r11) {
        r4 = -1;
    }
    SETSP((sp - 16));
    SETR(11, LD32((sp - 16)));
    SETSP((sp - 12));
    SETR(12, LD32((sp - 12)));
    SETSP((sp - 8));
    SETR(13, LD32((sp - 8)));
    SETSP((sp - 4));
    SETR(14, LD32((sp - 4)));
    SETSP(sp);
    return r4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B86E(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    SETSP((sp - 4));
    ST32((sp - 8), R(13));
    SETSP((sp - 8));
    ST32((sp - 12), R(12));
    SETSP((sp - 12));
    ST32((sp - 16), R(11));
    SETSP((sp - 16));
    SETSP((sp - 28));
    r0 = LD32(0x060C1040);
    if ((r0 & 4) == 0) {
        r11 = 10;
    } else {
        r11 = 12;
    }
    r14 = sp - 28;
    r6 = r14;
    r12 = 1;
    r13 = 12;
    r7 = 0;
    r5 = 0;
    do {
        r5 = r5 + 1;
        ST8(r6, r12);
        r6 = r6 + 1;
    } while (AGAIN(!(r5 >= r13)));
    r6 = 0x060C064A;
    r13 = r7;
    r1 = 0x060C1044;
    r5 = 0x060C0640;
    r12 = 3;
    while (1) {
        r3 = LD8(r1);
        if (!(r13 >= r3)) {
            POLL();
            r2 = LD8(r5);
            r13 = r13 + 1;
            if (!(((r2 & 255) & r12) == 0)) {
                r0 = LD8(r6);
                ST8((r0 & 255) + r14, r7);
            }
            r6 = r6 + 1;
            r5 = r5 + 1;
            continue;
        } else {
            break;
        }
    }
    if (((short)r4) > r11) {
        r4 = r11;
    }
    r4 = ((short)r4) - 1;
    if (r4 >= 0) {
        while (1) {
            r2 = LD8(r14 + r4);
            if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                break;
            } else {
                r4 = r4 - 1;
                if (r4 >= 0) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    SETSP((sp - 16));
    SETR(11, LD32((sp - 16)));
    SETSP((sp - 12));
    SETR(12, LD32((sp - 12)));
    SETSP((sp - 8));
    SETR(13, LD32((sp - 8)));
    SETSP((sp - 4));
    SETR(14, LD32((sp - 4)));
    SETSP(sp);
    return r4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602C65E(void)
{
    int r0, r1, r2, r3, r4, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    SETSP((sp - 4));
    ST32((sp - 8), R(13));
    SETSP((sp - 8));
    ST32((sp - 12), R(12));
    SETSP((sp - 12));
    ST32((sp - 16), R(11));
    SETSP((sp - 16));
    ST32((sp - 20), R(10));
    SETSP((sp - 20));
    ST32((sp - 24), R(9));
    SETSP((sp - 24));
    ST32((sp - 28), PR());
    SETSP((sp - 28));
    SETSP((sp - 32));
    r0 = GCALL0(0x0602B9EC);
    ST32(sp - 32, r0);
    r0 = GCALL0(0x0602B9B2);
    r9 = 0x060C0640;
    r12 = r0;
    r10 = 0x0600996A;
    r13 = 0x060C122C;
    r14 = 0x060C1044;
    r2 = LD32(sp - 32);
    r11 = 0;
    if ((r2 & 0x100) == 0) {
        if ((0xE00 & r12) == 0) {
            r2 = LD8(r14);
            if (!(r2 >= 10)) {
                if (!((0x8000 & r12) == 0)) {
                    r4 = LD8(r13);
                    SETSP((sp - 32));
                    r0 = GCALL1(0x0602C622, (r4 & 255));
                    ST8(r13, r0);
                }
                if (!((0x4000 & r12) == 0)) {
                    r4 = LD8(r13);
                    SETSP((sp - 32));
                    r0 = GCALL1(0x0602C644, (r4 & 255));
                    ST8(r13, r0);
                }
                if (!((r12 & 0xC000) == 0)) {
                    SETSP((sp - 32));
                    r0 = GCALL1(r10, 4);
                }
            }
        } else {
            SETSP((sp - 32));
            r0 = GCALL1(r10, 5);
            r3 = LD8(r14);
            if (r3 >= 10) {
                r11 = 1;
            } else {
                r0 = LD8(r14);
                r1 = LD8(r0 + r9);
                ST8(r0 + r9, (r1 & 3));
                r0 = LD8(r14);
                r1 = LD8(r13);
                r2 = LD8(r0 + r9);
                ST8(r0 + r9, (r2 | ((r1 & 255) << 2)));
                r4 = LD8(r14);
                SETSP((sp - 32));
                r0 = GCALL1(0x0602B930, r4);
                ST8(r14, r0);
                r4 = LD8(r13);
                SETSP((sp - 32));
                r0 = GCALL1(0x0602C540, (r4 & 255));
                if ((((short)r0) & ((short)r0)) == 0) {
                    SETSP((sp - 32));
                    r0 = GCALL0(0x0602C61E);
                    ST8(r13, r0);
                }
            }
        }
    } else {
        SETSP((sp - 32));
        r0 = GCALL1(r10, 6);
        r4 = LD8(r14);
        SETSP((sp - 32));
        r0 = GCALL1(0x0602B976, r4);
        ST8(r14, r0);
        r2 = LD8(r14);
        if (!(r2 >= 0)) {
            r11 = 1;
        } else {
            r0 = LD8(r14);
            r3 = LD8(r0 + r9);
            ST8(r13, ((int)((unsigned)(r3 & 255) >> 2)));
        }
    }
    SETSP((sp - 28));
    SETPR(LD32((sp - 28)));
    SETSP((sp - 24));
    SETR(9, LD32((sp - 24)));
    SETSP((sp - 20));
    SETR(10, LD32((sp - 20)));
    SETSP((sp - 16));
    SETR(11, LD32((sp - 16)));
    SETSP((sp - 12));
    SETR(12, LD32((sp - 12)));
    SETSP((sp - 8));
    SETR(13, LD32((sp - 8)));
    SETSP((sp - 4));
    SETR(14, LD32((sp - 4)));
    SETSP(sp);
    return r11;
}
