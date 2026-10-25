#include "krnl.h"

void f0601002A(void)
{
    GCALL0(0x060100F6);
    ST32(0x060DFE08, 71);
    ST16(0x060DFE16, 9);
    ST16(0x060DFE90, 1);
    ST16(0x060DFE14, 48);
    ST16(0x060D7EB4, 8);
    ST16(0x060D7EB6, 0);
}

int f06010058(unsigned int seconds)
{
    unsigned int hours = DIVU(seconds, 0xE10);

    return hours > 99 ? 99 : hours;
}

int f06010072(unsigned int seconds)
{
    return DIVU(seconds - DIVU(seconds, 0xE10) * 0xE10, 60);
}

int f060100D4(unsigned int frames)
{
    return DIVU(MODU(frames, 60) * 100, 60);
}

/* Clears 2000 records of 14 bytes from 060D8C0C, stepping the pointer kept at CURSOR. */
void f060100F6(void)
{
    int i;
    REF(Rec14) p;

    ST32(CURSOR, 0x060D8C0C);
    i = 0;
    do {
        p = LD32(CURSOR);
        SET(Rec14, p, h0, 0);
        SET(Rec14, p, h2, 0);
        SET(Rec14, p, h4, 0);
        SET(Rec14, p, b6, 0);
        SET(Rec14, p, b7, 0);
        SET(Rec14, p, b8, 0);
        SET(Rec14, p, b9, 0);
        ST32(CURSOR, p + 14);
    } while (AGAIN(++i < 2000));
    ST16(0x060DF980, 0);
}

void f06010132(int a, int b)
{
    ST32(CURSOR, 0x060D8C0C + LDU16(0x060DF980) * 14);
    SET(Node14, NODE, h0, a);
    SET(Node14, NODE, b6, b);
    SET(Node14, NODE, b9, LD8(0x060DFE91));
    ST16(0x060DF980, LD16(0x060DF980) + 1);
}

void f060101E4(void)
{
    int i = 0;
    int node;

    ST32(CURSOR, 0x060D8C0C);
    while (i < LDU16(0x060DF980)) {
        POLL();
        node = LD32(CURSOR);
        if (LD16(node))
            GCALL1(0x060692DC, LDU16(node));
        i++;
        ST32(CURSOR, LD32(CURSOR) + 14);
    }
    POLL();
    ST32(CURSOR, 0x060D8C0C);
    i = 0;
    do {
        SET(Node14, NODE, h0, 0);
        SET(Node14, NODE, h2, 0);
        SET(Node14, NODE, h4, 0);
        SET(Node14, NODE, b6, 0);
        SET(Node14, NODE, b7, 0);
        SET(Node14, NODE, b8, 0);
        SET(Node14, NODE, b9, 0);
        ST32(CURSOR, LD32(CURSOR) + 14);
    } while (AGAIN(++i < 2000));
    ST16(0x060DF980, 0);
}

int f060102E4(int r4, int r5, int r6, int r7)
{
    int r0, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST32(sp - 28, r4);
    ST32(sp - 20, r5);
    ST32(sp - 24, r6);
    ST32(sp - 16, r7);
    SETSP((sp - 28));
    r0 = GCALL1(0x060691DA, r7);
    r14 = r0 & 0xFFFF;
    if (!((r14 & r14) == 0)) {
        r5 = LD32(sp - 28);
        SETSP((sp - 28));
        r0 = GCALL2(0x06010132, r14, r5);
        r0 = LD16(sp - 18);
        r4 = (((r14 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(r4 + 16, r0);
        r0 = LD16(sp - 22);
        ST16(r4 + 18, r0);
        r2 = LD16(0x060DFE14);
        ST16(46 + r4, r2);
        r5 = LD32(sp - 28);
        SETR(14, r14);
        SETSP((sp - 28));
        SETPR(0x0601032A);
        r0 = GCALL2(0x06068A8E, r14, r5);
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r14;
}

int f060103F2(int r4, int r5, int r6, int r7)
{
    int r0, r1, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r6 = LD32(0x060DFE10);
    r14 = LD32(0x060B3914 + (r4 << 2));
    r5 = LD32(0x060DFE0C);
    r1 = LD32(0x060DFE08);
    SETR(14, r14);
    SETSP((sp - 8));
    SETPR(0x06010418);
    r0 = GCALL4(0x060102E4, ((255 & ((int)((unsigned)r14 >> 8))) + r1), r5, r6, 10);
    r0 = LD32(0x060DFE08);
    if (!(r0 == 105)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        ST16(0x060DFE14, 96);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP4(0x060102E4, (148 + ((int)((unsigned)r14 >> 16))), 220, 34, 10);
        return r0;
    }
}

int f06010468(void)
{
    int i = 0;
    int result;

    do {
        REF(Brain) brain = 0x060C0360 + i * 32;

        BR_SET(brain, b25, 0);
        if (LDU8(0x060C029C) < 9) {
            int kind;

            GCALL2(0x06008A6A, 4, 0);
            if (LDU8(0x060C029C) != 8)
                kind = LDU8(0x060C029C) + 1;
            else
                kind = (LDU8(0x060C029D) >> 2) + 6;
            ST32(brain + 8, GCALL2(0x06008ABA, kind, 4) + i * 4);
        }
        BR_SET(brain, next, 0x06010C0C);
        BR_SET(brain, fn, 0x06010C0C);
        result = GCALL1(0x06011762, brain);
        ST16(0x060C04DA, (2 - (LDU8(0x060C0680) > 2 ? 2 : LDU8(0x060C0680))) * 2);
    } while (AGAIN(++i < 10));
    return result;
}

void f06010508(void)
{
    GCALL2(0x06022F1C, 31, 0x0601051E);
    ST16(LD32(TASK_PTR) + 10, 0);
}

int f0601051E(void)
{
    gaddr t;
    int i, n;

    for (i = 0; i < (unsigned char)LD8(BOMBER_COUNT); i++) {
        if ((LD8(REC(i) + 4) & 3) == 2) {
            if ((LD8(REC((unsigned char)LD8(0x060C0360 + i * 32 + 24)) + 4) & 128) || !LD16(LD32(TASK_PTR) + 10))
                GCALL2(0x060105EC, i, 1);
        }
        POLL();
    }
    t = LD32(TASK_PTR);
    n = LD16(t + 10) ? LD16(t + 10) - 1 : 120;
    ST16(t + 10, n);
    return n;
}

/* Mode 0 gives 1; below 10 it returns who's kind if that is 8, 9 or 11; otherwise it counts the other bombers of those kinds. */
int f0601079E(int who, unsigned int mode)
{
    unsigned char kind;
    int count = 0;
    int i;

    if (!mode)
        return 1;
    if (mode < 10) {
        kind = LD8(0x060C064A + who);
        return kind == 8 || kind == 9 || kind == 11 ? kind : 0;
    }
    for (i = 0; i < (unsigned char)LD8(BOMBER_COUNT); i++) {
        if (!(LD8((OBJECTS + 0x30) + i * 124 + 4) & 128)) {
            kind = LD8(0x060C064A + i);
            if ((kind == 8 || kind == 9 || kind == 11) && i != who)
                count++;
        }
        POLL();
    }
    return count;
}

/* Records of 124 bytes: counts those other than `self` with bit 7 of byte 4 clear and its low two bits not `kind`. */
int f06010832(int self, int kind)
{
    unsigned int i;
    int count = 0;
    gaddr p = 0x060D5F30;

    for (i = 0; i < (unsigned char)LD8(0x060C063D); i++, p += 124) {
        unsigned char flags = LD8(p + 4);

        POLL();
        if (!(flags & 0x80) && (flags & 3) != kind && i != self)
            count++;
    }
    return count;
}

int f06010C0C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    r14 = r4;
    SETR(14, r14);
    SETSP((sp - 20));
    SETPR(0x06010C1C);
    r0 = GCALL4(0x06012748, r4, 0, 0, r7);
    if ((r0 & r0) == 0) {
        r13 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 20);
        r3 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
        r2 = LD16(0x060C04DC);
        if (((r3 & 0xFFFF) & (r2 & 0xFFFF)) == 0) {
            SETSP((sp - 20));
            r0 = GCALL1(0x060110AC, r14);
            r12 = r0;
            ST8(0x060C04E5, 1);
            ST8(0x060C04C4, 5);
            SETSP((sp - 20));
            r0 = GCALL1(0x06011320, r14);
            do {
                SETSP((sp - 20));
                r0 = GCALL2(0x06010D08, r14, r12);
                SETSP((sp - 20));
                r0 = GCALL0(0x0601136A);
                SETSP((sp - 20));
                r0 = GCALL0(0x060113FC);
            } while (AGAIN(!((r0 & r0) == 0)));
            r0 = LD8(0x060C04E5);
            if (!((r0 & r0) == 0)) {
                r0 = LD8(0x060C0680);
                if ((r0 & r0) == 0) {
                    SETSP((sp - 20));
                    r0 = GCALL0(0x0600A0B8);
                    ST8(0x060C04A3, ((r0 & 3) + 1));
                    ST32(r14, 0x06011BF0);
                } else {
                    ST32(r14, 0x06012410);
                }
            }
            r0 = LD8(0x060C04A3);
            r0 = LD16(((r0 & 255) << 1) + 0x060B4800);
            ST16(r14 + 12, r0);
            r0 = LD32(r13);
            r0 = LD16(r0 + 20);
            ST16(r14 + 18, r0);
            r0 = LD16(r14 + 12);
            if (!((r0 & r0) == 0)) {
                r0 = LD32(r13);
                r0 = LD16(r0 + 20);
                ST16(r14 + 20, r0);
                r0 = 3;
                r3 = LD8(0x060C0680);
                if (!((r3 & 255) >= 3)) {
                    r0 = 22;
                    ST8(22 + r14, 64);
                }
            }
        } else {
            r0 = 0;
            ST16(r14 + 12, 0);
            ST32(r14, 0x06011C50);
        }
    }
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06010D08(int a, int b)
{
    int dev = LDU16(0x060C04D8) << 1;
    unsigned int level, mark, bonus, v;
    unsigned short limit;
    int total, c;

    ST32(0x060C04E8, 128);
    ST16(0x060C04D2, 0);
    level = HELPER((LDU16(0x060EE8B0 + dev) & 0xF00) >> 8);
    ST16(0x060C04C8, level);
    limit = LDU16(0x060B3978 + (LDU16(0x060C04CC) << 1)) + LDU16(0x060C04DA);
    if (LD8(0x060C04C5) != 0) {
        mark = LDU16(0x060C04CA);
        if (LDU16(0x060EC8B0 + dev) & LDU16(0x060C04DC)) {
            ST16(0x060C04D0, 0xFFFF);
            return;
        }
        if (level >= mark && level - mark >= limit) {
            ST16(0x060C04D0, 0xFFFF);
            return;
        }
    }
    GCALL0(0x06010E5C);
    GCALL0(0x06010E88);
    GCALL0(0x06010EEE);
    GCALL2(0x06010F7C, a, b);
    GCALL0(0x06010FDE);
    c = LD8(0x060C04C5);
    bonus = 0;
    if (c >= 2) {
        v = LDU16(0x060C04A0 + (signed char)(6 * (c - 1)));
        if (v >= 128)
            bonus = v - 127;
    }
    total = LD32(0x060C04E8) + bonus + LDU16(0x060C04D2);
    if ((unsigned int)total > 0xFFFF)
        total = 0xFFFF;
    ST32(0x060C04E8, total);
    ST16(0x060C04A0 + (signed char)(6 * c), total);
    ST16(0x060C04D0, (LDU16(0x060C04D2) << 4) + total);
}

void f06010E5C(void)
{
    unsigned short code = LDU16(0x060EE8B0 + LDU16(0x060C04D8) * 2);
    int add;

    if ((code & 255) >= 22)
        return;
    add = LDU16(0x060B3BD8 + (code & 255) * 2);
    if ((unsigned int)(LD32(0x060C04E8) + add) > 0x7530)
        ST32(0x060C04E8, 0x7530);
    else
        ST32(0x060C04E8, LD32(0x060C04E8) + add);
}

void f06010E88(void)
{
    int flags = LDU16(FLAGS_AT(LDU16(0x060C04D8)));
    int kind;

    if (!(flags & 64))
        return;
    kind = GCALL1(0x06021F82, LDU16(0x060C04D8));
    if (kind == 10 || kind == 16 || kind == 26 || (kind == 21 && GCALL0(0x06011046) == 0))
        GJUMP1(0x06011014, LDU16(0x060B39D8 + LDU16(0x060C04CC) * 2));
    else
        GJUMP1(0x0601102E, LDU16(0x060B39C0 + LDU16(0x060C04CC) * 2));
}

void f06010EEE(void)
{
    int idx = LDU16(0x060C04CC) << 4;
    int col = LDU16(0x060C04C8);
    int limit;
    unsigned short inc;

    if (col) {
        if (LD8(0x060C04C5)) {
            limit = LDU16(0x060C04CA);
            idx += col > limit ? col - limit : 1;
        } else {
            idx += col;
        }
    }
    inc = LD16(0x060B3A20 + idx * 2);
    if (inc)
        ST16(0x060C04D2, LD16(0x060C04D2) + inc);
    else
        ST8(0x060C04E5, 0);
}

void f06010F7C(gaddr rec, int cell)
{
    if (LD16(0x060C04D8) == LD16(rec + 20))
        GCALL1(0x06011014, LDU8(rec + 22));
    if (LD16(0x060C04D8) == LD16(rec + 16))
        GCALL1(0x0601102E, LDU16(0x060B39F0 + LDU16(0x060C04CC) * 2));
    if (LDU16(0x060C04D8) == cell)
        GJUMP1(0x0601102E, LDU16(0x060B3A08 + LDU16(0x060C04CC) * 2));
}

void f06010FDE(void)
{
    gaddr cell = 0x060EC8B0 + LDU16(0x060C04D8) * 2;
    unsigned int n = 0;
    int i = 0;

    do {
        if (!(LDU16(cell + LD32(0x060B3BB8 + i * 4) * 2) & LDU16(0x060C04DC)))
            n++;
    } while (AGAIN(++i < 4));
    if ((unsigned int)LD32(0x060C04E8) >= n)
        ST32(0x060C04E8, LD32(0x060C04E8) - n);
    else
        ST32(0x060C04E8, 0);
}

void f06011014(int n)
{
    if ((unsigned int)(LD32(0x060C04E8) + n) > 0x7530)
        ST32(0x060C04E8, 0x7530);
    else
        ST32(0x060C04E8, LD32(0x060C04E8) + n);
}

void f0601102E(unsigned int n)
{
    if ((unsigned int)LD32(0x060C04E8) >= n)
        ST32(0x060C04E8, LD32(0x060C04E8) - n);
    else
        ST32(0x060C04E8, 0);
}

int f06011046(void)
{
    gaddr t = LD32(CURRENT);

    if (!(LDU16(t + 46) & 0x800))
        return 1;
    return LDU16(REC(LDU16(t + 36)) + 52) < 2;
}
int f060110AC(REF(Brain) brain)
{
    gaddr cur;
    gaddr other;
    int cell;
    int ok = 1;
    int i;
    int odd;
    int mask;

    if (BR(brain, b24) != LDU16(0x060C062C)) {
        other = REC(BR(brain, b24));
        GCALL1(0x0600C9AA, LDU16(other + 20));
        ST16(0x060D7E88, LD16(0x060D7EB4));
        ST16(0x060D7E8A, LD16(0x060D7EB6));
        if (LD16(other + 42)) {
            ST16(0x060D7E88, -LD16(0x060D7E88));
            ST16(0x060D7E8A, -LD16(0x060D7E8A));
        }
    } else if (!GCALL0(0x060112A2)) {
        ok = 0;
    }
    if (ok) {
        cell = LDU16(LD32(CURRENT) + 20);
        GCALL1(0x0600C9AA, cell);
        odd = GCALL0(0x0600A0B8) & 1;
        i = 0;
        do {
            if (!odd) {
                cell = GCALL1(0x0601126E, cell);
                cell = GCALL1(0x0601123A, cell);
            } else {
                cell = GCALL1(0x0601123A, cell);
                cell = GCALL1(0x0601126E, cell);
            }
        } while (AGAIN(++i < 2));
        if (cell == LDU16(LD32(CURRENT) + 20))
            cell = 0;
    } else {
        cell = 0;
    }
    if (LDU16(LD32(CURRENT) + 46) & 0x800) {
        if (LDU16(REC(LDU16(LD32(CURRENT) + 36)) + 64) == 3) {
            cur = LD32(CURRENT);
            mask = (LDU8(cur + 6) & 1) ? 63 : 0xFFC0;
            if ((LDU16(cur + 20) & mask) == (cell & mask))
                GCALL1(0x06011642, LDU16(0x060BF5E6));
        }
    }
    if (!cell) {
        cur = LD32(CURRENT);
        cell = LD32(0x060B3C08 + ((BR(brain, b25) + LDU16(0x060C062C)) & 7) * 4) + LDU16(cur + 20);
        if (LDU16(FLAGS_AT(cell)) & LDU16(0x060C04DC))
            BR_SET(brain, b25, (GCALL0(0x0600A0B8) & 3) + 1);
    }
    return cell;
}

int f0601123A(int i)
{
    int target = LDU16(0x060D7EB4);
    int pos = LD16(0x060D7E88);
    int next;

    if (target != pos) {
        next = pos >= target ? i + 1 : i - 1;
        if (!(LDU16(0x060EC8B0 + next * 2) & LDU16(0x060C04DC)))
            i = next;
    }
    return i;
}

int f0601126E(int pos)
{
    int cur = LDU16(0x060D7EB6);
    int dest = LD16(0x060D7E8A);
    int next;

    if (cur != dest) {
        next = dest >= cur ? pos + 64 : pos - 64;
        if ((LDU16(0x060EC8B0 + next * 2) & LDU16(0x060C04DC)) == 0)
            pos = next;
    }
    return pos;
}

int f060112A2(void)
{
    gaddr rec = 0x060DFB9E;
    int x = 0, y = 0;
    int i = 1;

    do {
        if (LD8(rec + 5) != 0 && LD8(rec + 4) != 0 && LDU8(rec + 4) < 3) {
            int cell = GCALL1(0x0600CA6A, LDU16(rec));

            if (LDU16(FLAGS_AT(cell)) & 0x40) {
                x = LD16(0x060D7E88);
                y = LD16(0x060D7E8A);
                break;
            }
        }
        rec += 8;
    } while (AGAIN(++i <= 75));
    return (x | y) != 0;
}

void f06011320(REF(Brain) brain)
{
    int i;

    ST16(0x060C04A0, 0);
    i = 0;
    do {
        ST8(0x060C04A0 + i * 6 + 3, 0);
        ST8(0x060C04A0 + i * 6 + 2, 0);
        ST8(0x060C04A0 + i * 6 + 4, 0);
    } while (AGAIN(++i < 6));
    i = 0;
    do {
        ST8(0x060C04E0 + i, 0);
    } while (AGAIN(++i < 5));
    ST16(0x060C04CE, 0xFFFF);
    ST8(0x060C04C5, 0);
    if (BR(brain, w16) == LDU16(LD32(CURRENT) + 20))
        BR_SET(brain, w16, 0);
}

void f0601136A(void)
{
    int i;

    if (LDU16(0x060C04CE) <= LDU16(0x060C04D0))
        return;
    ST16(0x060C04CE, LD16(0x060C04D0));
    ST16(0x060C04D6, LD16(0x060C04D8));
    for (i = 0; i < (unsigned char)LD8(0x060C04C4); i++) {
        ST8(0x060C04A3 + i * 6, LD8(0x060C04A2 + i * 6));
        POLL();
    }
}

int f060113FC(void)
{
    gaddr step = 0x060C04A0 + (signed char)(LD8(0x060C04C5) * 6);
    int retreat = LD8(0x060C04C5) != 0 && LDU16(0x060C04D0) == 0xFFFF;

    for (;;) {
        if (!retreat) {
            if (LD8(0x060C04C5) >= LDU8(0x060C04C4)) {
                int slot = 0x060C04E0 + LDU8(0x060C04A2);

                ST8(slot, LD8(slot) + 1);
            } else {
                ST8(step + 2, LD8(step + 2) + 1);
                if (LDU8(step + 2) < 5) {
                    if (LD8(0x060C04C5) != 0 && ((LDU8(step + 2) - 1) ^ 2) + 1 == LDU8(step - 4)) {
                        POLL();
                        continue;
                    }
                    ST16(0x060C04D8, GCALL1(0x0600C9C0, LD16(0x060C04D8) + LD32(0x060B3C68 + LDU8(step + 2) * 4)));
                    ST8(0x060C04C5, LD8(0x060C04C5) + 1);
                    step += 6;
                    ST8(0x060C04C6, LD8(step - 4));
                    ST8(step + 2, 0);
                    ST16(step, 0);
                    return 1;
                }
            }
        }
        retreat = 0;
        ST8(0x060C04C5, LD8(0x060C04C5) - 1);
        if (LD8(0x060C04C5) < 0)
            return 0;
        step -= 6;
        ST16(0x060C04D8, GCALL1(0x0600C9C0, LD16(0x060C04D8) - LD32(0x060B3C68 + LDU8(step + 2) * 4)));
        POLL();
    }
}

int f060114D8(void)
{
    int y;
    int low;

    GCALL1(0x0600C9AA, LD16(0x060C04D8));
    y = LDU16(0x060D7EB6);
    low = LDU16(0x060D7E7E);
    if (LDU8(0x060C029C) == 17)
        return y <= low + 4 || y >= LDU16(0x060D7E82) - 2;
    return y <= low || y >= LDU16(0x060D7E82) - 1;
}

int f06011570(int arg)
{
    short limit;

    if (LDU16(0x060C04CA) >= LDU16(0x060B39A8 + LDU16(0x060C04CC) * 2) + LDU16(0x060C04DA))
        return 0;
    ST8(0x060C04C4, 3);
    GCALL1(0x06011320, arg);
    limit = LD16(0x060B3978 + LDU16(0x060C04CC) * 2) + LD16(0x060C04DA);
    for (;;) {
        int pos, level;

        ST16(0x060C04D0, 0xFFFF);
        pos = LDU16(0x060C04D8);
        if (!(LDU16(FLAGS_AT(pos)) & LDU16(0x060C04DC))) {
            level = HELPER((int)(LDU16(0x060EE8B0 + pos * 2) & 0xF00) >> 8);
            if ((unsigned short)level <= (unsigned short)limit) {
                ST16(0x060C04D0, 0);
                if ((unsigned short)level == 0) {
                    int diff = (pos ^ LD16(LD32(CURRENT) + 20)) & 0xFFFF;

                    if ((diff & 63) && (diff & 0xFFC0))
                        return 1;
                }
            }
        }
        if (GCALL0(0x060113FC) == 0)
            return 0;
        POLL();
    }
}

void f06011642(short bits)
{
    int i = LDU16(0x060C062C) * 2;

    ST16(0x260060B0 + i, LD16(0x260060B0 + i) | bits);
    ST16(0x26006096 + i, LD16(0x26006096 + i) | bits);
    ST16(0x260060CA + i, LD16(0x260060CA + i) | bits);
}

/* Which of four boxes (numbered from 1) the other bomber's position falls in, 0 if none. */
int f060116C0(REF(Brain) brain, int set)
{
    gaddr cur, other, box;
    int cx, cy, ox, oy;
    int i;

    if (BR(brain, b24) == LDU16(0x060C062C))
        return 0;
    cur = LD32(CURRENT);
    cx = LD16(cur + 24);
    cy = LD16(cur + 28);
    other = REC(BR(brain, b24));
    ox = LD16(other + 24);
    oy = LD16(other + 28);
    box = 0x060B3C88 + set * 32;
    i = 0;
    do {
        if (LD16(box) + cx < ox && LD16(box + 2) + cx >= ox && LD16(box + 4) + cy < oy && LD16(box + 6) + cy >= oy)
            return i + 1;
        box += 8;
    } while (AGAIN(++i < 4));
    return 0;
}

void f06011762(gaddr p)
{
    ST16(p + 12, 0);
    ST16(p + 16, 0);
    ST16(p + 18, 0);
    ST16(p + 20, 0);
    ST8(p + 22, 0);
    ST8(p + 27, 0);
}

void f06011778(REF(Brain) brain, int n)
{
    GCALL1(0x06011762, brain);
    BR_SET(brain, w12, LD16(0x060B4800 + n * 2));
}

void f0601179A(REF(Brain) brain)
{
    BR_SET(brain, w12, LD16(0x060B4800 + LDU8(LD32(CURRENT) + 6) * 2));
}

int f060117AC(gaddr task)
{
    if (LDU16(0x060C04CA) >= LDU16(0x060B3990 + LDU16(0x060C04CC) * 2) + LDU16(0x060C04DA)) {
        GCALL1(0x06011762, task);
        ST32(task, 0x06010C0C);
        return 0;
    }
    return 1;
}

int f06011818(void)
{
    int best = 10000;
    int nearest = 0;
    int i;

    for (i = 0; i < LDU8(BOMBER_COUNT); i++) {
        gaddr rec = REC(i);
        gaddr cur;
        int dist;

        POLL();
        if (i == LDU16(0x060C062C) || (LDU8(rec + 4) & 128))
            continue;
        cur = LD32(CURRENT);
        dist = ABS_DIFF(LDU16(rec + 24), LDU16(cur + 24)) + ABS_DIFF(LDU16(rec + 28), LDU16(cur + 28));
        if (best > dist) {
            best = dist;
            nearest = i + 1;
        }
    }
    return nearest;
}

void f060118A6(REF(Brain) brain)
{
    int dir;

    ST8(0x060C04C4, 3);
    GCALL1(0x06011320, brain);
    do {
        if (GCALL0(0x0601198C))
            GCALL1(0x060118D2, brain);
    } while (AGAIN(GCALL0(0x060113FC) == 0));
    dir = LDU8(0x060C04A3);
    BR_SET(brain, w12, LD16(0x060B4800 + dir * 2));
    BR_SET(brain, b23, dir);
    BR_SET(brain, w18, LD16(LD32(CURRENT) + 20));
    BR_SET(brain, w16, LD16(0x060C04D6));
}

void f060118D2(gaddr p)
{
    unsigned int a = LDU16(0x060C04D8);
    unsigned int b = LDU16((OBJECTS + 0x30) + (unsigned char)LD8(p + 26) * 124 + 20);
    int dx = (a & 63) - (b & 63);
    int dy = (a >> 6) - (b >> 6);

    ST16(0x060C04D0, (dx < 0 ? -dx : dx) + (dy < 0 ? -dy : dy));
    if (LDU16(0x060C04D0) < LDU16(0x060C04CE)) {
        ST16(0x060C04CE, LD16(0x060C04D0));
        ST16(0x060C04D6, LD16(0x060C04D8));
        ST8(0x060C04A3, LD8(0x060C04A2));
    }
}

int f0601198C(void)
{
    int cell = LDU16(0x060C04D8) * 2;

    ST16(0x060C04D0, 0xFFFF);
    if (LDU16(0x060EC8B0 + cell) & LDU16(0x060C04DC))
        return 0;
    if (HELPER((LDU16(0x060EE8B0 + cell) & 0xF00) >> 8) >= LDU16(0x060B3978 + LDU16(0x060C04CC) * 2) + LDU16(0x060C04DA))
        return 0;
    ST16(0x060C04D0, 255);
    return 1;
}

int f060119E8(void)
{
    gaddr t = LD32(CURRENT);

    if ((LDU16(t + 42) & 32) || (LDU16(t + 46) & 0x32D))
        return 0;
    if (LDU16(t + 40) >= LDU16(t + 62))
        return 0;
    return !(LDU16(0x060EC8B0 + LDU16(t + 20) * 2) & 0x42F0);
}

int f06011A6C(gaddr rec)
{
    int who = LDU8(rec + 24);
    int sum = 0;
    int k;
    int cell;

    if (who != LDU16(0x060C062C) && LD16(LD32(CURRENT) + 20) == LD16(0x060D5F44 + who * 124))
        return 0;
    ST32(0x060C04E8, 0);
    cell = LDU16(LD32(CURRENT) + 20) * 2;
    for (k = 0; k < 4 && sum == 0; k++) {
        POLL();
        sum += GCALL4(0x06011B00, LD32(0x060B3BB8 + k * 4), 0x060EC8B0 + cell, 0x060EE8B0 + cell, 0x060F08B0 + cell);
    }
    return sum;
}

/* Walks `stride` halfwords at a time down three tables while the cells they describe are open. */
int f06011B00(int stride, gaddr flags, gaddr bits, gaddr kinds)
{
    int count = 0;
    int i = 0;
    int kind;

    stride *= 2;
    while (i < LDU16(LD32(CURRENT) + 52) && !count) {
        POLL();
        flags += stride;
        kinds += stride;
        bits += stride;
        if (LDU16(flags) & 16) {
            if (LDU16(flags) & 7)
                break;
            if (LDU16(bits) & 0xF00)
                break;
            count++;
        } else if (LDU16(flags) & 64) {
            kind = LDU8(0x060DFB9B + (LDU16(kinds) & 255) * 8);
            if (kind == 16 || kind == 10 || kind == 26)
                count++;
            else if (kind == 21 && !GCALL0(0x06011046))
                count++;
        } else if (LDU16(bits) & 0x1000) {
            count++;
        }
        if (LDU16(flags) & 160)
            break;
        i++;
    }
    return count;
}

void f06011BF0(REF(Brain) brain)
{
    if (!(BR(brain, w12) & 0xF000)) {
        BR_SET(brain, fn, BR(brain, next));
    } else {
        BR_SET(brain, w18, LD16(LD32(CURRENT) + 20));
        BR_SET(brain, b29, 4);
        BR_SET(brain, fn, 0x06011C16);
    }
}

void f06011C16(gaddr task)
{
    if (LDU8(task + 29) == 0 || LD16(LD32(CURRENT) + 20) != LD16(task + 18)) {
        int next = LD32(task + 4);

        ST32(task, next);
        POLL();
        GJUMP1(next, task);
        return;
    }
    ST8(task + 29, LDU8(task + 29) - 1);
}

/* Puts the brain back on the course it was last given and starts it on its next step. */
static void retarget(REF(Brain) brain)
{
    GCALL1(0x060126E4, brain);
    GJUMP1(0x06011BF0, brain);
}

void f06011C50(REF(Brain) brain)
{
    ST8(0x060C04C4, 3);
    GCALL1(0x06011320, brain);
    do {
        GCALL1(0x06011CBA, brain);
        GCALL0(0x0601136A);
    } while (AGAIN(GCALL0(0x060113FC)));
    if (LDU16(0x060C04CE) >= 16) {
        BR_SET(brain, fn, 0x06012410);
    } else {
        BR_SET(brain, b27, 255);
        BR_SET(brain, next, 0x06010C0C);
        retarget(brain);
    }
}

/* 0609497E shifts r0 right by 8, and a GCALL cannot pass r0. The call stays for the time it advances, and the shift is done here. */
void f06011CBA(gaddr task)
{
    int pos = LDU16(0x060C04D8);
    unsigned char kind = GCALL1(0x06021F82, pos);
    gaddr cell = 0x060EE8B0 + pos * 2;
    int dist;

    ST16(0x060C04D0, 0xFFFF);
    if (LDU16(0x060EC8B0 + pos * 2) & LDU16(0x060C04DC))
        return;
    if (kind == 16 || kind == 10 || kind == 26) {
        ST16(0x060C04D0, LD16(0x060C04D0) | 32);
        return;
    }
    if (GCALL1(0x060121D4, cell) & 0x1000)
        return;
    dist = HELPER(LDU16(cell) >> 8) & 15;
    if (dist < LDU16(0x060C04CA) || dist - LDU16(0x060C04CA) < LDU16(0x060B39A8 + LDU16(0x060C04CC) * 2) + LDU16(0x060C04DA)) {
        if (dist) {
            ST16(0x060C04D0, dist + 32);
        } else {
            ST16(0x060C04D0, LD8(0x060C04C5) << 1);
            if (LD8(0x060C04A2) != LD8(task + 25))
                ST16(0x060C04D0, LD16(0x060C04D0) | 1);
        }
    }
}

int f06011D86(int cell, int flags)
{
    int i;

    if (!(flags & 0x1000))
        return flags;
    flags &= 0xEFFF;
    for (i = 0; i < LDU8(BOMBER_COUNT); i++) {
        gaddr rec = REC(i);

        POLL();
        if (LDU16(rec + 20) == cell && !(LDU8(rec + 4) & 128) && i != LDU16(0x060C062C)) {
            flags |= 0x1000;
            break;
        }
    }
    return flags;
}

int f06011E2C(int cell, gaddr table)
{
    int k = 0;
    int result;

    do {
        result = GCALL2(0x06011D86, cell, LD16(table + LD32(0x060B3C68 + k * 4) * 2));
    } while (AGAIN(++k < 5));
    return result;
}

void f06011E62(REF(Brain) brain)
{
    if (LDU16(LD32(CURRENT) + 64) & 1) {
        if (!LD16(0x060C04CA) && !LD16(0x260060B0 + LDU16(0x060C062C) * 2))
            GCALL1(0x06011642, LDU16(0x060BF5E0));
    }
    if (GCALL0(0x060119E8) && GCALL1(0x06011570, brain) && GCALL1(0x06011A6C, brain))
        GCALL1(0x06011EBE, brain);
    BR_SET(brain, fn, BR(brain, next));
}

void f06011EBE(gaddr task)
{
    GCALL1(0x06011642, LDU16(0x060BF5DC));
    ST16(task + 12, 0);
    ST32(task + 4, 0x06011C50);
    ST32(task, 0x06011C50);
}

void f06011EDC(gaddr task)
{
    if (!(LDU16(0x060EC8B0 + LDU16(0x060D7E8C) * 2) & 32))
        GCALL1(0x06011642, LDU16(0x060BF5DC));
    ST16(task + 14, LD16(task + 12));
    ST16(task + 12, GCALL1(0x06016C84, LD16(task + 12)));
    ST16(task + 18, LD16(0x060D7E8C));
    ST32(task, 0x06011F1A);
}

int f06011F1A(gaddr p)
{
    int wait = LD16(p + 18);

    if (wait) {
        ST32(p, 0x06011F26);
        return wait;
    }
    ST16(p + 12, LD16(p + 14));
    wait = LD16(LD32(CURRENT) + 20);
    ST16(p + 18, wait);
    ST32(p, 0x06011F38);
    return wait;
}

void f06011F26(REF(Brain) brain)
{
    BR_SET(brain, w12, BR(brain, w14));
    BR_SET(brain, w18, LD16(LD32(CURRENT) + 20));
    BR_SET(brain, fn, 0x06011F38);
}

int f06011F38(gaddr task)
{
    int n = LD16(task + 18);
    gaddr next;

    if (n) {
        ST32(task, 0x06011F44);
        return n;
    }
    GCALL1(0x06011762, task);
    next = LD32(task + 4);
    ST32(task, next);
    POLL();
    return GJUMP1(next, task);
}

void f06011F44(gaddr task)
{
    int next;

    GCALL1(0x06011762, task);
    next = LD32(task + 4);
    ST32(task, next);
    POLL();
    GJUMP1(next, task);
}

int f06011F98(gaddr task, unsigned int need)
{
    gaddr t = LD32(CURRENT);

    if (!(LDU16(t + 64) & 0x100))
        return 0;
    if ((unsigned int)(LDU16(t + 62) - LDU16(t + 40)) < need)
        return 0;
    return GCALL0(0x060119E8) && GCALL1(0x060120B4, task);
}

int f06011FE4(int dir)
{
    gaddr flags = FLAGS_AT(LDU16(LD32(CURRENT) + 20));
    gaddr height;
    int step, i, level;

    if (GCALL1(0x06012184, flags) & 183)
        return 0;
    if (LD16(0x060C04CA) != 0)
        return 0;
    step = LD32(0x060B3C68 + (dir << 2));
    height = 0x060EE8B0 + LDU16(LD32(CURRENT) + 20) * 2 + step * 6;
    flags += step * 6;
    i = 0;
    level = 12;
    for (;;) {
        int h;

        flags += step * 2;
        height += step * 2;
        if (LDU16(flags) & 0x40D0 || LDU16(height) & 0x1000)
            return 0;
        h = HELPER((int)(LDU16(height) & 0xF00) >> 8);
        if (h >= level && h < level + 3)
            return 1;
        level--;
        if (++i >= 6)
            return 0;
        POLL();
    }
}

int f060120B4(int dir)
{
    gaddr flags = FLAGS_AT(LDU16(LD32(CURRENT) + 20));
    gaddr height;
    int delta, i, budget;

    if (GCALL1(0x06012184, flags) & 183)
        return 0;
    if (LDU16(0x060C04CA) >= LDU16(0x060B3990 + LDU16(0x060C04CC) * 2) + LDU16(0x060C04DA))
        return 0;
    budget = 3;
    height = 0x060EE8B0 + LDU16(LD32(CURRENT) + 20) * 2;
    delta = LD32(0x060B3C68 + (dir << 2)) * 2;
    i = 0;
    while (i < LDU16(LD32(CURRENT) + 52)) {
        POLL();
        height += delta;
        if (LDU16(flags) & 0x42B0 || LDU16(height) & 0x1000)
            return budget == 0;
        if (LDU16(flags) & 7 || (LDU16(height) & 0xF00) >= 0x300)
            return 0;
        if (budget != 0)
            budget--;
        i++;
    }
    return 1;
}

int f06012184(gaddr base)
{
    int bits = 0;
    int i = 0;

    do {
        bits |= LDU16(base + LD32(0x060B3BB8 + i * 4) * 2);
    } while (AGAIN(++i < 4));
    return bits;
}

int f060121D4(gaddr p)
{
    int v = LD16(p);

    return GCALL1(0x06012184, p) | v;
}

void f060121EC(gaddr task)
{
    if (LDU16(0x060EC8B0 + LDU16(0x060D7E8C) * 2) & 32) {
        GCALL1(0x06011642, LDU16(0x060BF5E2));
        ST8(task + 29, 9);
        ST32(task, 0x0601224A);
    } else {
        GCALL1(0x06011642, LDU16(0x060BF5DC));
        ST32(task, 0x06012226);
    }
}

int f06012226(gaddr task)
{
    GCALL1(0x06011642, LDU16(0x060BF5E2));
    ST8(task + 29, 9);
    ST32(task, 0x0601224A);
    return 29;
}

void f0601224A(REF(Brain) brain)
{
    BR_SET(brain, b29, BR(brain, b29) - 1);
    if (!BR(brain, b29) || (LDU16(LD32(CURRENT) + 46) & 2)) {
        GCALL1(0x06011642, LDU16(0x060BF5E2));
        BR_SET(brain, fn, BR(brain, next));
    }
}

int f0601227E(gaddr task, unsigned int need)
{
    gaddr t = LD32(CURRENT);

    if (!(LDU16(t + 64) & 0x200) || LD16(t + 46))
        return 0;
    if ((unsigned int)(LDU16(t + 62) - LDU16(t + 40)) < need)
        return 0;
    return GCALL0(0x060119E8) && GCALL1(0x06012376, task);
}

int f060122F0(int dir)
{
    int step = LD32(0x060B3C68 + dir * 4);
    int cell = LDU16(LD32(CURRENT) + 20) * 2;
    gaddr flags = 0x060EC8B0 + cell + step * 6;
    gaddr bits = 0x060EE8B0 + cell + step * 6;
    int i = 0;
    int level;

    do {
        if (!(LDU16(flags) & 0x42B0) && !(LDU16(bits) & 0x1000)) {
            level = HELPER((LDU16(bits) & 0xF00) >> 8);
            return level >= 6 && level < 10;
        }
        flags += step * 2;
        bits += step * 2;
    } while (AGAIN(++i < 4));
    return 0;
}

int f06012376(int dir)
{
    gaddr flags;
    int delta, i;

    if (LDU16(0x060C04CA) >= LDU16(0x060B3990 + LDU16(0x060C04CC) * 2) + LDU16(0x060C04DA))
        return 0;
    if (LDU16(LD32(CURRENT) + 52) < 3)
        return 1;
    delta = LD32(0x060B3C68 + (dir << 2)) * 2;
    flags = FLAGS_AT(LDU16(LD32(CURRENT) + 20));
    i = 0;
    do {
        flags += delta;
        if (LDU16(flags) & 0x40D0)
            return 1;
    } while (AGAIN(++i < 3));
    return 0;
}

void f06012410(REF(Brain) brain)
{
    int i, best = 0, step = 0;

    GCALL1(0x060124B8, brain);
    if (!(LDU16(0x060EE8B0 + LDU16(0x060C04D6) * 2) & 0xF00)) {
        BR_SET(brain, next, 0x06010C0C);
        retarget(brain);
        return;
    }
    BR_SET(brain, next, 0x06012638);
    if (LD8(0x060C04E0 + LDU8(0x060C04A3))) {
        retarget(brain);
        return;
    }
    i = 4;
    while (i) {
        POLL();
        if (LDU8(0x060C04E0 + i) > best) {
            best = LDU8(0x060C04E0 + i);
            step = i;
        }
        i--;
    }
    if (!best) {
        if (!(LDU16(LD32(CURRENT) + 64) & 0x100))
            BR_SET(brain, fn, 0x06012410);
        else
            retarget(brain);
        return;
    }
    BR_SET(brain, w12, LD16(0x060B4800 + step * 2));
    BR_SET(brain, b23, step);
    GJUMP1(0x06011BF0, brain);
}

void f060124B8(REF(Brain) brain)
{
    ST8(0x060C04C4, 5);
    GCALL1(0x06011320, brain);
    do {
        GCALL0(0x0601251C);
        GCALL0(0x0601136A);
    } while (AGAIN(GCALL0(0x060113FC)));
}

void f0601251C(void)
{
    int dev = LDU16(0x060C04D8);
    int step;
    int c;
    gaddr p;
    unsigned short total;
    unsigned int level;

    if (LDU16(0x060EC8B0 + dev * 2) & LDU16(0x060C04DC)) {
        ST16(0x060C04D0, 0xFFFF);
        return;
    }
    step = GCALL1(0x06021F82, dev);
    if (step == 16 || step == 10 || step == 26) {
        step = 3;
    } else {
        level = HELPER((LDU16(0x060EE8B0 + dev * 2) & 0xF00) >> 8);
        ST16(0x060C04C8, level);
        if (level == 0)
            step = 0;
        else if (level >= LDU16(0x060C04CA))
            step = level;
        else
            step = level << 1;
    }
    c = LD8(0x060C04C5);
    p = 0x060C04A0 + (signed char)(6 * c);
    total = c == 0 ? 0 : LD16(p - 2) + step;
    ST16(p, total);
    ST16(0x060C04D0, (step << 4) + total);
}

void f06012638(REF(Brain) brain)
{
    gaddr cur;
    int mask;

    GCALL1(0x060124B8, brain);
    if (!HELPER((LDU16(0x060EE8B0 + LDU16(0x060C04D6) * 2) & 0xF00) >> 8)) {
        BR_SET(brain, next, 0x06010C0C);
        retarget(brain);
        return;
    }
    if (BR(brain, w18) == LDU16(LD32(CURRENT) + 20))
        BR_SET(brain, b23, (BR(brain, b23) & 3) + 1);
    mask = LDU16(LD32(CURRENT) + 18);
    if (LDU16(LD32(CURRENT) + 64) & 0x100)
        mask &= -33;
    cur = LD32(CURRENT);
    if (!(LDU16(FLAGS_AT(LDU16(cur + 20) + LD16(0x060B47F0 + BR(brain, b23) * 2))) & mask)) {
        BR_SET(brain, w12, LD16(0x060B4800 + BR(brain, b23) * 2));
        BR_SET(brain, next, 0x06012638);
        GJUMP1(0x06011BF0, brain);
    } else {
        BR_SET(brain, b23, 0);
    }
}

void f060126E4(REF(Brain) brain)
{
    int dir = LDU8(0x060C04A3);

    BR_SET(brain, w12, LD16(0x060B4800 + dir * 2));
    BR_SET(brain, b23, dir);
    BR_SET(brain, w18, LD16(LD32(CURRENT) + 20));
    BR_SET(brain, w16, LD16(0x060C04D6));
}

int f06012748(int r4)
{
    int r0, r2, r3, r5, r6, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r6 = 0x060C04CC;
    r14 = r4;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r3 = LD8(27 + r14);
    ST8(27 + r14, (r3 + 1));
    r4 = LD16(0x060C04CC);
    r5 = LD8(27 + r14);
    r4 = (r4 & 0xFFFF) << 1;
    r5 = r5 & 255;
    r3 = LD16(0x060B3960 + r4);
    if (((r3 & 0xFFFF) & r5) == 0) {
        r3 = LD16(0x060C04CA);
        r2 = LD16(0x060B3990 + r4);
        if ((r3 & 0xFFFF) >= (r2 & 0xFFFF)) {
            r0 = 0;
        } else {
            ST32(r14, 0x06011E62);
            ST32(r14 + 4, 0x06010C0C);
            r13 = LD16(r6);
            r12 = 0x060B3D08;
            r13 = ((r13 & 0xFFFF) << 2) << 2;
            while (1) {
                r3 = LD32((r13 << 2) + r12);
                if (!((r3 & r3) == 0)) {
                    POLL();
                    r3 = LD32((r13 << 2) + r12);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 16));
                    SETPR(0x060127AA);
                    r0 = GCALL1(r3, r14);
                    if (!((r0 & r0) == 0)) {
                        r13 = r13 + 1;
                        continue;
                    } else {
                        r0 = 1;
                        break;
                    }
                } else {
                    r0 = 0;
                    break;
                }
            }
        }
    } else {
        r0 = LD16(r14 + 12);
        if (!((r0 & r0) == 0)) {
            r0 = 0;
        } else {
            if (!((1 & r5) == 0)) {
                r0 = 0;
            } else {
                r3 = LD16(0x060C04CA);
                r2 = LD16(0x060B3990 + r4);
                if ((r3 & 0xFFFF) >= (r2 & 0xFFFF)) {
                    r0 = 0;
                } else {
                    ST32(r14, 0x06011E62);
                    ST32(r14 + 4, 0x06010C0C);
                    r13 = LD16(r6);
                    r12 = 0x060B3D08;
                    r13 = ((r13 & 0xFFFF) << 2) << 2;
                    while (1) {
                        r3 = LD32((r13 << 2) + r12);
                        if (!((r3 & r3) == 0)) {
                            POLL();
                            r3 = LD32((r13 << 2) + r12);
                            SETR(12, r12);
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 16));
                            SETPR(0x060127AA);
                            r0 = GCALL1(r3, r14);
                            if (!((r0 & r0) == 0)) {
                                r13 = r13 + 1;
                                continue;
                            } else {
                                r0 = 1;
                                break;
                            }
                        } else {
                            r0 = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060127CA(gaddr task)
{
    gaddr t = LD32(CURRENT);

    if (!(LDU16(t + 46) & 0x800) || LD16(t + 42) || (LDU16(t + 46) & 0xF7FF))
        return 1;
    switch (LDU16(REC(LDU16(t + 36)) + 64)) {
    case 1:
        if (LDU16(0x060C04CA) < 14)
            return 1;
        break;
    case 2:
        if ((GCALL0(0x0600A0B8) & 7) || LDU16(0x060C04CA) >= 6)
            return 1;
        t = LD32(CURRENT);
        if (!(LDU16(0x060EC8B0 + (LD16(0x060B47F0 + (unsigned char)LD8(t + 6) * 2) + LDU16(t + 20)) * 2) & 32))
            return 1;
        break;
    case 4:
        if ((GCALL0(0x0600A0B8) & 7) || LD16(0x060C04CA))
            return 1;
        if (GCALL2(0x060116C0, task, 2) != (unsigned char)LD8(LD32(CURRENT) + 6))
            return 1;
        break;
    default:
        return 1;
    }
    GCALL1(0x06011642, LDU16(0x060BF5E6));
    return 0;
}

int f060128FA(REF(Brain) brain)
{
    if (LD16(LD32(CURRENT) + 42) == 0)
        return 1;
    GCALL1(0x06011762, brain);
    BR_SET(brain, fn, 0x0601292C);
    return 0;
}

int f0601292C(REF(Brain) brain)
{
    int target;

    if (GCALL1(0x060117AC, brain) == 0) {
        BR_SET(brain, fn, 0x06010C0C);
        return 0;
    }
    target = GCALL0(0x06011818);
    if (target == 0) {
        BR_SET(brain, fn, 0x06010C0C);
        return 0;
    }
    ST8(brain + 26, target - 1);
    GCALL1(0x060118A6, brain);
    if (BR(brain, w12) == 0) {
        BR_SET(brain, fn, 0x06010C0C);
        return 0;
    }
    BR_SET(brain, next, 0x0601292C);
    return GJUMP1(0x06011BF0, brain);
}

int f060129A6(REF(Brain) brain)
{
    int box = GCALL2(0x060116C0, brain, 1);

    if (box == 0 || GCALL2(0x06011F98, box, 1) == 0)
        return 1;
    GCALL2(0x06011778, brain, box);
    BR_SET(brain, fn, 0x060129E0);
    return 0;
}

int f060129E0(gaddr task)
{
    ST32(task + 4, 0x06012A02);
    GCALL1(0x0601179A, task);
    GCALL1(0x06011EDC, task);
    ST8(task + 28, 0);
    return 28;
}

int f06012A02(REF(Brain) brain)
{
    int count;

    if (!(BR(brain, b28) & 1))
        GCALL1(0x06011642, LDU16(0x060BF5E4));
    count = LDU16(0x060C04CA);
    if (count == 0 || count >= 8) {
        BR_SET(brain, fn, 0x06012410);
    } else {
        GCALL1(0x0601179A, brain);
        BR_SET(brain, w18, LD16(LD32(CURRENT) + 20));
    }
    BR_SET(brain, b28, BR(brain, b28) + 1);
    return 28;
}

int f06012A50(gaddr task)
{
    if (!GCALL2(0x06011F98, LDU8(LD32(CURRENT) + 6), 3))
        return 1;
    GCALL1(0x06011762, task);
    ST32(task, 0x06012A88);
    return 0;
}

int f06012A88(REF(Brain) brain)
{
    GCALL1(0x0601179A, brain);
    if (GCALL0(0x060119E8) == 0 || GCALL1(0x060120B4, LDU8(LD32(CURRENT) + 6)) == 0) {
        BR_SET(brain, fn, 0x06010C0C);
        return 0;
    }
    BR_SET(brain, next, 0x06012AC4);
    return GJUMP1(0x06011EDC, brain);
}

int f06012AC4(gaddr task)
{
    gaddr cur;

    GCALL1(0x06011762, task);
    if (!GCALL1(0x060117AC, task))
        return 0;
    cur = LD32(CURRENT);
    ST8(cur + 6, (LDU8(cur + 6) & 3) + 1);
    return GJUMP1(0x06012A88, task);
}

int f06012AF4(gaddr task)
{
    int target;

    if (LD16(0x060C04CA))
        return 1;
    target = GCALL2(0x060116C0, task, 0);
    if (!target || !GCALL2(0x06011F98, target, 2))
        return 1;
    GCALL2(0x06011778, task, target);
    ST32(task, 0x06012B3E);
    ST8(task + 28, 0);
    return 0;
}

int f06012B3E(REF(Brain) brain)
{
    BR_SET(brain, next, 0x06012B58);
    GCALL1(0x0601179A, brain);
    return GJUMP1(0x06011EDC, brain);
}

int f06012B58(REF(Brain) brain)
{
    BR_SET(brain, next, 0x06012B72);
    GCALL1(0x0601179A, brain);
    return GJUMP1(0x06011EDC, brain);
}

void f06012B72(REF(Brain) brain)
{
    if (!GCALL0(0x060119E8)) {
        GCALL1(0x06012410, brain);
    } else if (LDU16(0x060C04CA) >= 8) {
        GCALL1(0x06012410, brain);
    } else {
        GCALL1(0x0601179A, brain);
        BR_SET(brain, next, 0x06012410);
        GCALL1(0x06011EDC, brain);
    }
    BR_SET(brain, b28, BR(brain, b28) + 1);
}

int f06012C0C(REF(Brain) brain)
{
    int idx;

    if (GCALL1(0x060121D4, 0x060EE8B0 + LDU16(LD32(CURRENT) + 20) * 2) & 0xF00)
        return 1;
    idx = GCALL2(0x060116C0, brain, 0);
    if (!idx)
        return 1;
    if (!GCALL2(0x06011F98, idx, 2))
        return 1;
    GCALL2(0x06011778, brain, idx);
    BR_SET(brain, fn, 0x06012C62);
    return 0;
}

int f06012C62(REF(Brain) brain)
{
    BR_SET(brain, next, 0x06012C7C);
    GCALL1(0x0601179A, brain);
    return GJUMP1(0x06011EDC, brain);
}

void f06012C7C(gaddr p)
{
    ST8(p + 28, 3);
    ST32(p, 0x06012C88);
}

int f06012C88(REF(Brain) brain)
{
    int result;

    BR_SET(brain, b28, BR(brain, b28) - 1);
    if (BR(brain, b28) == 0) {
        BR_SET(brain, fn, 0x06012CD8);
        return 0;
    }
    if (LDU16(0x060C04CA) >= 6)
        return GJUMP1(0x06012410, brain);
    if (BR(brain, b28) >= 2)
        return BR(brain, b28);
    result = GCALL1(0x060120B4, LDU8(LD32(CURRENT) + 6));
    if (result)
        return result;
    return GJUMP1(0x06012410, brain);
}

int f06012CD8(gaddr task)
{
    ST32(task + 4, 0x06012410);
    GCALL1(0x0601179A, task);
    return GJUMP1(0x06011EDC, task);
}

int f06012D30(REF(Brain) brain)
{
    int dir = 1;

    if (LD16(0x060C04CA) != 0)
        return 1;
    do {
        if (GCALL2(0x06011F98, dir, 1) != 0 && GCALL1(0x06011FE4, dir) != 0) {
            GCALL2(0x06011778, brain, dir);
            BR_SET(brain, next, 0x06010C0C);
            GCALL1(0x06011EDC, brain);
            return 0;
        }
    } while (AGAIN(++dir < 5));
    return 1;
}

int f06012D94(gaddr task)
{
    if (!GCALL2(0x0601227E, LDU8(LD32(CURRENT) + 6), 3))
        return 1;
    GCALL1(0x06011762, task);
    ST32(task, 0x06012DCC);
    return 0;
}

int f06012DCC(REF(Brain) brain)
{
    if (GCALL0(0x060119E8) == 0 || GCALL1(0x06012376, LDU8(LD32(CURRENT) + 6)) == 0) {
        BR_SET(brain, fn, 0x06010C0C);
        return 0;
    }
    BR_SET(brain, next, 0x06012E02);
    return GJUMP1(0x060121EC, brain);
}

int f06012E02(REF(Brain) brain)
{
    GCALL1(0x06011762, brain);
    BR_SET(brain, next, 0x06012E54);
    return GJUMP1(0x06012E54, brain);
}

int f06012E54(REF(Brain) brain)
{
    int result = GCALL1(0x060117AC, brain);
    gaddr cur;

    if (result) {
        result = 46;
        cur = LD32(CURRENT);
        if (!(LDU16(cur + 46) & 0x33D)) {
            result = LD16(0x060B4800 + ((LDU8(cur + 6) & 3) + 1) * 2);
            BR_SET(brain, w12, result);
            BR_SET(brain, fn, 0x06012DCC);
        }
    }
    return result;
}

int f06012E8C(REF(Brain) brain)
{
    int dir = 1;

    do {
        if (GCALL2(0x0601227E, dir, 3) != 0) {
            GCALL2(0x06011778, brain, dir);
            BR_SET(brain, b28, 0);
            BR_SET(brain, fn, 0x06012EDA);
            return 0;
        }
    } while (AGAIN(++dir < 5));
    return 1;
}

void f06012EDA(REF(Brain) brain)
{
    if (!GCALL0(0x060119E8) || !GCALL1(0x06012376, LDU8(LD32(CURRENT) + 6)) || BR(brain, b28) >= 3) {
        BR_SET(brain, fn, 0x06010C0C);
    } else {
        BR_SET(brain, next, 0x06012F24);
        GCALL1(0x060121EC, brain);
    }
    BR_SET(brain, b28, BR(brain, b28) + 1);
}

int f06012F24(gaddr task)
{
    int flags = LD16(LD32(0x060D7768) + 46);

    if (flags == 0)
        ST32(task, 0x06012EDA);
    return flags;
}

int f06012F6C(REF(Brain) brain)
{
    int box;

    if (LD16(LD32(CURRENT) + 40) != 0)
        return 1;
    box = GCALL2(0x060116C0, brain, 2);
    if (box == 0 || GCALL2(0x0601227E, box, 1) == 0)
        return 1;
    GCALL2(0x06011778, brain, box);
    BR_SET(brain, fn, 0x060121EC);
    BR_SET(brain, next, 0x06010C0C);
    return 0;
}

int f06012FB8(REF(Brain) brain)
{
    int idx = GCALL0(0x06013094);

    if (!idx)
        return 1;
    if (!GCALL2(0x0601227E, idx, 2))
        return 1;
    GCALL2(0x06011778, brain, (2 ^ (idx - 1)) + 1);
    GCALL1(0x06011642, LDU16(0x060BF5DC));
    BR_SET(brain, next, 0x06013006);
    GCALL1(0x06011BF0, brain);
    return 0;
}

int f06013006(gaddr task)
{
    int result = GCALL2(0x06011778, task, (2 ^ (LDU8(LD32(CURRENT) + 6) - 1)) + 1);

    ST32(task, 0x0601302E);
    return result;
}

int f0601302E(REF(Brain) brain)
{
    int ok = GCALL0(0x060119E8);

    if (ok == 0 || LDU16(0x060C04CA) >= 6) {
        BR_SET(brain, fn, 0x06010C0C);
        return ok;
    }
    BR_SET(brain, next, 0x06010C0C);
    return GJUMP1(0x060121EC, brain);
}

int f06013094(void)
{
    gaddr flags = FLAGS_AT(LDU16(LD32(CURRENT) + 20));
    gaddr height;
    int i;

    if (GCALL1(0x06012184, flags) & LDU16(0x060C04DC))
        return 0;
    height = 0x060EE8B0 + LDU16(LD32(CURRENT) + 20) * 2;
    i = 1;
    do {
        int ahead = LD32(0x060B3BB8 + (i - 1) * 4);
        int side = LD32(0x060B3BC8 + (i - 1) * 4);
        int far = side * 2;

        if ((LDU16(height + ahead * 2) & 0x1000) && !(LDU16(height + side * 2) & 0xF00)
            && !(LDU16(flags + far * 2) & LDU16(0x060C04DC)) && !(LDU16(height + far * 2) & 0xF00))
            return i;
    } while (AGAIN(++i < 5));
    return 0;
}

int f06013134(REF(Brain) brain)
{
    gaddr cur = LD32(CURRENT);
    int box;

    if (LD16(cur + 40) != 0)
        return 1;
    box = GCALL2(0x060116C0, brain, 1);
    if (box == 0)
        return 1;
    cur = LD32(CURRENT);
    if (!(LDU16(0x060EC8B0 + (LD16(0x060B47F0 + box * 2) * 3 + LDU16(cur + 20)) * 2) & 0x42B0))
        return 1;
    if (GCALL2(0x0601227E, box, 1) == 0)
        return 1;
    GCALL2(0x06011778, brain, box);
    BR_SET(brain, next, 0x06010C0C);
    BR_SET(brain, fn, 0x060121EC);
    return 0;
}

int f060131E0(REF(Brain) brain)
{
    int box;

    if (LDU16(LD32(CURRENT) + 40) >= 2)
        return 1;
    box = GCALL2(0x060116C0, brain, 3);
    if (box == 0 || GCALL2(0x0601227E, box, 1) == 0)
        return 1;
    GCALL2(0x06011778, brain, (2 ^ (box - 1)) + 1);
    BR_SET(brain, next, 0x06010C0C);
    BR_SET(brain, fn, 0x060121EC);
    return 0;
}

int f06013238(REF(Brain) brain)
{
    int dir = 1;

    if (LD16(LD32(CURRENT) + 40) != 0)
        return 1;
    do {
        if (GCALL2(0x0601227E, dir, 1) != 0 && GCALL1(0x060122F0, dir) != 0) {
            GCALL2(0x06011778, brain, dir);
            BR_SET(brain, next, 0x06010C0C);
            BR_SET(brain, fn, 0x060121EC);
            return 0;
        }
    } while (AGAIN(++dir < 5));
    return 1;
}

int f0601329E(gaddr task)
{
    if (GCALL0(0x0600A0B8) & LDU16(0x060B3BA0 + LDU16(0x060C04CC) * 2))
        return 1;
    if (LD16(LD32(CURRENT) + 46))
        return 1;
    GCALL1(0x06011762, task);
    ST32(task, 0x06013318);
    ST8(task + 28, 32);
    return 0;
}

void f06013318(REF(Brain) brain)
{
    if (!GCALL1(0x060117AC, brain) || !BR(brain, b28)) {
        BR_SET(brain, fn, 0x06010C0C);
    } else {
        ST16(LD32(CURRENT) + 54, 0x12C);
        BR_SET(brain, b28, BR(brain, b28) - 1);
    }
}

int f0601334C(REF(Brain) brain)
{
    int off = LDU16(LD32(CURRENT) + 20) * 2;
    int i = 0;

    do {
        int d = LD32(0x060B3C08 + i * 4);

        if ((LDU16(0x060F08B0 + off + d * 2) & 255) && (LDU16(0x060EE8B0 + off + d * 2) & 0xF00) > 0x100
            && (LDU16(0x060EC8B0 + off + d * 2) & 16)) {
            BR_SET(brain, fn, 0x06013400);
            BR_SET(brain, b28, 0);
            return 0;
        }
    } while (AGAIN(++i < 24));
    return 1;
}

int f06013400(gaddr task)
{
    ST8(task + 28, LD8(task + 28) + 1);
    if (!GCALL1(0x060117AC, task)) {
        ST32(task, 0x06010C0C);
        return 0;
    }
    if ((unsigned char)LD8(task + 28) >= 128) {
        ST32(task, 0x06010C0C);
        return 28;
    }
    ST8(0x060C04C4, 4);
    GCALL1(0x06011320, task);
    do {
        GCALL0(0x06013470);
        GCALL0(0x0601136A);
    } while (AGAIN(GCALL1(0x060113FC, task)));
    if (LDU16(0x060C04CE) >= 0x100) {
        ST32(task, 0x06010C0C);
        return 0;
    }
    return GJUMP1(0x060126E4, task);
}

/* 0609497E shifts r0 right by 8, and a GCALL cannot pass r0. The call stays for the time it advances, and the shift is done here. */
void f06013470(void)
{
    int pos = LDU16(0x060C04D8);
    gaddr cell = 0x060EC8B0 + pos * 2;
    gaddr dist = 0x060EE8B0 + pos * 2;
    int step = LD8(0x060C04C5);
    unsigned int flags = LDU16(cell);

    if ((flags & 16) && ((flags & 7) || (LDU16(dist) & 0xF00))) {
        ST16(0x060C04D0, (LDU16(0x060C04CA) << 8) + step);
        return;
    }
    if (LDU16(cell) & LDU16(0x060C04DC)) {
        ST16(0x060C04D0, 0xFFFF);
        return;
    }
    if (HELPER((LDU16(dist) & 0xF00) >> 8) >= LDU16(0x060B3978 + LDU16(0x060C04CC) * 2) + LDU16(0x060C04DA))
        ST16(0x060C04D0, 0xFFFF);
    else
        ST16(0x060C04D0, step + 0x100);
}

int f06013554(gaddr task)
{
    int y;

    if ((unsigned char)LD8(0x060C029C) != 17)
        return 1;
    GCALL0(0x0600CA84);
    y = LDU16(0x060D7EB6);
    if (y > LDU16(0x060D7E7E) + 4 && y < LDU16(0x060D7E82) - 2)
        return 1;
    GCALL1(0x06011762, task);
    GCALL1(0x06011642, LDU16(0x060BF5DC));
    ST32(task, 0x06010C0C);
    return 0;
}

int f060135B2(REF(Brain) brain)
{
    unsigned short target = LD16(0x060D5F44 + BR(brain, b24) * 124);
    unsigned int limit = LDU16(0x060B3990 + LDU16(0x060C04CC) * 2) + LDU16(0x060C04DA);
    gaddr p = 0x060B4008;

    while (LD16(p) != 0) {
        gaddr cur;
        int near, ahead;

        POLL();
        cur = LD32(CURRENT);
        if (((LD16(cur + 20) + LD16(p)) & 0xFFFF) == target) {
            near = LD16(cur + 20) + LD16(p + 4);
            if (LDU16(FLAGS_AT(near & 0xFFFF)) & 183) {
                ahead = LD16(cur + 20) + LD16(p + 2);
                if (!(LDU16(FLAGS_AT(ahead & 0xFFFF)) & 0x42B0)
                    && (unsigned)HELPER((int)(LDU16(0x060EE8B0 + (ahead & 0xFFFF) * 2) & 0xF00) >> 8) < limit) {
                    ST16(brain + 12, LD16(p + 6));
                    GCALL1(0x06011762, brain);
                    BR_SET(brain, next, 0x06011EBE);
                    GCALL1(0x06011BF0, brain);
                    return 0;
                }
            }
        }
        p += 8;
    }
    return 1;
}

int f060136E0(REF(Brain) brain)
{
    gaddr cur = LD32(CURRENT);
    gaddr flags;
    int i;

    if (LD16(cur + 40) != 0 || !(LDU16(cur + 64) & 0x400) || LDU16(cur + 62) < 2)
        return 1;
    if (GCALL0(0x0600A0B8) & 3)
        return 1;
    flags = 0x060EC8B0 + LDU16(LD32(CURRENT) + 20) * 2;
    for (i = 0; i < LDU16(LD32(CURRENT) + 62); i++) {
        POLL();
        if (LDU16(flags) & 0xF00)
            return 1;
        if (LDU16(flags) & 0x42B0)
            break;
    }
    if (i < 2)
        return 1;
    GCALL1(0x06011762, brain);
    GCALL1(0x06011642, LDU16(0x060BF5DC));
    BR_SET(brain, fn, 0x06013788);
    return 0;
}

int f06013788(gaddr task)
{
    int result = GCALL1(0x06011642, LDU16(0x060BF5DC));

    ST32(task, 0x06010C0C);
    return result;
}

int f060137CC(REF(Brain) brain)
{
    gaddr cur = LD32(CURRENT);
    int off = LDU16(cur + 20) * 2;
    gaddr list = 0x060B404C;
    int index = 0;

    if (LDU16(cur + 62) - LDU16(cur + 40) < 3)
        return 1;
    while (LD32(list) != 0) {
        int count = 0;
        gaddr flags, height;

        POLL();
        if (!(GCALL1(0x060121D4, 0x060EE8B0 + off + LD32(list) * 2) & 0x1000)
            && (GCALL0(0x0600A0B8) & LDU16(0x060B41E2 + LDU16(0x060C04CC) * 2))) {
            list += 32;
            index += 8;
            continue;
        }
        flags = 0x060EC8B0 + off;
        height = 0x060EE8B0 + off;
        while (LD32(list) != 0) {
            POLL();
            flags += LD32(list) * 2;
            height += LD32(list) * 2;
            if (!(LDU16(flags) & 183) && !(LDU16(height) & 0xF00))
                count++;
            list += 4;
        }
        list += 4;
        if (count != 0) {
            GCALL1(0x06011762, brain);
            BR_SET(brain, b30, index + 1);
            BR_SET(brain, b28, 0);
            BR_SET(brain, fn, 0x060138D8);
            return 0;
        }
        index += 8;
    }
    return 1;
}

int f060138D8(gaddr task)
{
    if ((unsigned char)LD8(task + 28) >= 3) {
        ST32(task, 0x06012410);
    } else if (!GCALL1(0x0601393A, task)) {
        ST32(task, 0x06012410);
    } else {
        GCALL1(0x06011642, LDU16(0x060BF5DC));
        GCALL2(0x0601391E, task, 0x06013918);
    }
    ST8(task + 28, LD8(task + 28) + 1);
    return 28;
}

int f06013918(gaddr obj)
{
    ST32(obj + 4, 0x060138D8);
    ST16(obj + 12, LD16((LD8(obj + 30) & 255) * 2 + 0x060B4150));
    ST8(obj + 30, LD8(obj + 30) + 1);
    return GJUMP1(0x06011BF0, obj);
}

void f0601391E(REF(Brain) brain, int state)
{
    BR_SET(brain, next, state);
    BR_SET(brain, w12, LD16(0x060B4150 + BR(brain, b30) * 2));
    BR_SET(brain, b30, BR(brain, b30) + 1);
    GJUMP1(0x06011BF0, brain);
}

int f0601393A(gaddr task)
{
    gaddr entry, cell, dist;
    int off;

    if (LDU16(0x060C04CA) >= 6)
        return 0;
    entry = 0x060B404C + ((unsigned char)LD8(task + 30) << 2);
    off = (LD32(entry) + LDU16(LD32(CURRENT) + 20)) * 2;
    cell = 0x060EC8B0 + off;
    dist = 0x060EE8B0 + off;
    if (!GCALL2(0x060139AC, cell, dist))
        return 0;
    off = LD32(entry + 4) * 2;
    dist += off;
    if (!GCALL2(0x060139AC, cell + off, dist))
        return 0;
    return !(GCALL1(0x060121D4, dist) & 0x1000);
}

int f060139AC(gaddr a, gaddr b)
{
    if (LDU16(a) & 183)
        return 0;
    return (LDU16(b) & 0xF00) < 0x300;
}

int f06013B90(void)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r0 = LD32(0x060C0AA8);
    if (!((r0 & r0) == 0)) {
        ST32(0x060BD8CC, -1);
        SETSP((sp - 8));
        SETPR(0x06013BAC);
        r0 = GCALL3(0x0600AE58, 23, 2, 1);
        SETSP((sp - 8));
        r0 = GCALL4(0x060096FA, 0x060C050C, (sp - 8), 0, 4);
        r0 = 0;
        r3 = LD32(0x060BD8DC);
        ST32(0x060C0510, r3);
        ST32(0x060C051C, 0);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06013C24(unsigned int n)
{
    int idx;
    int base;

    if (LD32(0x060C051C))
        return 0;
    if (LDU16(0x060D7E68) & 64)
        return 0;
    if (n >= 20)
        return 0;
    idx = LD32(0x060B41FC + n * 4);
    if (idx < 0)
        return 0;
    base = LD32(0x060C0510);
    ST32(0x060C0520, (unsigned int)(LD32(base + (idx + 1) * 4) - LD32(base + idx * 4)) >> 1);
    ST32(0x060C0514, LD32(base + idx * 4));
    ST32(0x060C0518, LD32(0x060C050C));
    ST32(0x060C051C, 1);
    return 1;
}

void f06013C88(void)
{
    unsigned int n;
    gaddr src, dst;

    if (!LD32(0x060C0AA8) || !LD32(0x060C051C))
        return;
    switch (LD32(0x060C051C)) {
    case 1:
        n = LD32(0x060C0520);
        if (n > 0x400)
            n = 0x400;
        else
            ST32(0x060C051C, 2);
        ST32(0x060C0520, LD32(0x060C0520) - n);
        src = LD32(0x060C0514);
        dst = LD32(0x060C0518);
        while (n) {
            ST16(dst, LD16(src));
            src += 2;
            dst += 2;
            ST32(0x060C0514, src);
            ST32(0x060C0518, dst);
            n--;
            POLL();
        }
        break;
    case 2:
        GCALL1(0x0600996A, 0x140);
        ST32(0x060C051C, 3);
        ST32(0x060C0520, 0);
        break;
    case 3:
        ST32(0x060C0520, LD32(0x060C0520) + 1);
        if ((unsigned int)LD32(0x060C0520) > 150) {
            GCALL1(0x06009A3A, 0x140);
            ST32(0x060C051C, 4);
        }
        break;
    case 4:
        ST32(0x060C051C, 0);
        break;
    }
}

int f06013D5C(void)
{
    int result = GCALL0(0x06018C72);
    int lo = result & 255;
    int hi = (unsigned)result >> 16;

    if (lo < 2 || hi != 0) {
        if (!(LDU16(0x060D7E68) & 64)) {
            ST16(0x060D7E68, LDU16(0x060D7E68) | 64);
            GCALL1(0x0600996A, 238);
        }
        if (lo == 0)
            ST16(0x060D7E68, LDU16(0x060D7E68) | 16);
    }
    POLL();
    return GJUMP0(0x0600B8F0);
}

int f06013DA4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    UNFRAME(sp);
    r0 = GJUMP4(0x06009B62, 13, 100, r6, r7);
    return r0;
}

int f06013DD0(int r4)
{
    int r0, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r14 = 0x060C0628;
    r3 = LD16(0x060C0628);
    ST16(0x060C0628, (r3 + 1));
    r2 = LD16(0x060C0628);
    r11 = r4;
    if ((r2 & 0xFFFF) >= 40) {
        ST16(r14, 0);
    }
    SETSP((sp - 24));
    r0 = GCALL2(0x06008A6A, 8, 0);
    SETSP((sp - 24));
    r0 = GCALL1(0x060691DA, 0x1E6);
    if (((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
        r0 = 0;
    } else {
        r13 = 0x060C1AAA;
        r12 = LD16(r14);
        r3 = LD16(0x060C1AAA);
        ST16(0x060C0574 + ((r12 & 0xFFFF) << 1), r3);
        r12 = (((r3 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 24));
        r0 = GCALL2(0x0600D148, r4, r11);
        ST16(r12 + 18, 0);
        ST16(46 + r12, 0x6310);
        r4 = LD16(0x060C1AAA);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, 0x060C1AAA);
        SETR(14, r14);
        SETSP((sp - 24));
        SETPR(0x06013E40);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 35);
        SETSP((sp - 24));
        r0 = GCALL2(0x0606AAC8, r12, 3);
        SETSP((sp - 24));
        r0 = GCALL1(0x060691DA, 10);
        if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
            r12 = LD16(r14);
            r3 = LD16(r13);
            ST16(0x060C05C4 + ((r12 & 0xFFFF) << 1), r3);
            r12 = (((r3 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            r4 = LD16(r13);
            SETSP((sp - 24));
            r0 = GCALL2(0x0600D148, r4, r11);
            ST16(46 + r12, 0x310);
            r4 = LD16(r13);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 24));
            SETPR(0x06013E84);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 33);
            SETSP((sp - 24));
            r0 = GCALL2(0x0606AAC8, r12, 3);
        }
        r3 = LD16(r14);
        ST16(0x060C0524 + ((r3 & 0xFFFF) << 1), r11);
        r0 = LD16(r13);
        r0 = r0 & 0xFFFF;
    }
    SETMACL(LD32((sp - 24)));
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06013EE0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c28;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    SETSP((sp - 48));
    r0 = GCALL0(0x0600BD3C);
    r11 = r0;
    r7 = 0x060C1004;
    r14 = 0;
    r10 = 0x060C0622;
    r8 = 0x060C05C4;
    r9 = 0x060C029C;
    r12 = 0x060C0618;
    r13 = 0x060C0614;
    r4 = LD8(0x060C1004);
    r0 = r4 & 255;
    r4 = r0;
    if (!(r0 == 2)) {
        r0 = r4;
        if (r0 == 3) {
            r0 = LD16(0x060D7E68);
            if (((r0 & 0xFFFF) & 97) == 0) {
                r2 = LD32(r13);
                r1 = LD16(r2);
                r2 = LD16(0x060C0624);
                if (!(r1 == (r2 & 0xFFFF))) {
                    r0 = LD32(r13);
                    r0 = LD16(r0);
                    if (r0 == 1) {
                        r1 = LD32(r13);
                        r1 = r1 + 2;
                        ST32(r13, r1);
                        r1 = LD16(r1);
                        ST16(0x060C0620, (r1 + r11));
                    }
                    r3 = 0x060C061C;
                    r0 = LD16(0x060C061C);
                    if (!((r0 & r0) == 0)) {
                        r2 = LD16(r3);
                        ST16(r3, (r2 - 1));
                    } else {
                        r4 = LD16(0x060C0620);
                        SETR(8, r8);
                        SETR(9, r9);
                        SETR(10, r10);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 48));
                        SETPR(0x0601400C);
                        r0 = GCALL1(0x06013DD0, r4);
                        if (!((r0 & r0) == 0)) {
                            r3 = LD16(0x060C0626);
                            ST16(0x060C061C, r3);
                            r0 = LD32(r13);
                            r0 = LD16(r0 + 2);
                            r2 = LD16(0x060C0620);
                            r2 = r2 + r0;
                            ST16(0x060C0620, r2);
                            r3 = LD32(r13);
                            r0 = LD16(r3 + 4);
                            if (((short)r2) == (r0 + r11)) {
                                r2 = LD32(r13);
                                r2 = r2 + 6;
                                ST32(r13, r2);
                                r2 = LD16(r2);
                                ST16(0x060C0620, (r2 + r11));
                                r0 = LD32(r13);
                                r0 = LD16(r0);
                                if (r0 == 1) {
                                    SETSP((sp - 48));
                                    r0 = GCALL0(0x06014344);
                                }
                            }
                        }
                    }
                }
                r3 = LD32(r12);
                r2 = LD16(r3);
                r3 = LD16(0x060C0624);
                if (!(r2 == (r3 & 0xFFFF))) {
                    r0 = LD32(r12);
                    r0 = LD16(r0);
                    if (r0 == 1) {
                        r2 = LD32(r12);
                        r2 = r2 + 2;
                        ST32(r12, r2);
                        r2 = LD16(r2);
                        ST16(r10, (r2 + r11));
                    }
                    r3 = 0x060C061E;
                    r0 = LD16(0x060C061E);
                    if (!((r0 & r0) == 0)) {
                        r2 = LD16(r3);
                        ST16(r3, (r2 - 1));
                    } else {
                        r4 = LD16(r10);
                        SETR(8, r8);
                        SETR(9, r9);
                        SETR(10, r10);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(14, r14);
                        SETSP((sp - 48));
                        SETPR(0x06014086);
                        r0 = GCALL1(0x06013DD0, r4);
                        if (!((r0 & r0) == 0)) {
                            r3 = LD16(0x060C0626);
                            ST16(0x060C061E, r3);
                            r0 = LD32(r12);
                            r3 = LD16((r0 + 2));
                            r0 = LD16(r10);
                            ST16(r10, (r0 + r3));
                            r3 = LD16(r10);
                            r0 = LD32(r12);
                            r0 = LD16(r0 + 4);
                            if (r3 == (r0 + r11)) {
                                r0 = LD32(r12);
                                r0 = r0 + 6;
                                ST32(r12, r0);
                                r0 = LD16(r0);
                                ST16(r10, (r11 + r0));
                            }
                        }
                    }
                }
            }
            r12 = 0x060C0574;
            r13 = 0x060C0524;
            r0 = LD16(0x060D7E68);
            r0 = r0 & 0xFFFF;
            if ((r0 & 33) == 0) {
                r10 = r14;
                r11 = 0xE00;
                ST32(sp - 44, 0x060B47FA);
                ST32(sp - 40, (0x060B47F0 + r14));
                while (1) {
                    r1 = LD16(r12);
                    if (!((r1 & r1) == 0)) {
                        r2 = LD16(r12);
                        ST32(sp - 48, ((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
                        r4 = LD16(r13);
                        SETSP((sp - 48));
                        r0 = GCALL1(0x0600C9AA, r4);
                        r4 = LD16(r12);
                        SETSP((sp - 48));
                        r0 = GCALL1(0x0600C90C, (r4 & 0xFFFF));
                        r4 = LD32(sp - 40);
                        do {
                            r5 = LD16(r4);
                            r3 = LD16(r13);
                            r5 = ((r5 + (r3 & 0xFFFF)) << 1) + 0x060EE8B0;
                            r3 = LD16(r5);
                            r4 = r4 + 2;
                            if (!(((r3 & 0xFFFF) & 0xF00) >= r11)) {
                                r0 = LD16(r5);
                                ST16(r5, ((r0 & 0xF0FF) | r11));
                            }
                            r3 = LD32(sp - 44);
                        } while (AGAIN(!((unsigned)r4 >= (unsigned)r3)));
                        r1 = LD16(0x060D7E8A);
                        r3 = LD16(0x060D7EB6);
                        if (!(r1 >= (((r3 & 0xFFFF) << 2) << 2))) {
                            r3 = LD32(sp - 48);
                            r0 = LD8(r9);
                            c28 = (r0 & 255) == 17;
                            r0 = LD16(r3 + 18);
                            if (!(c28)) {
                                r1 = 4;
                            } else {
                                r1 = 8;
                            }
                            r0 = r0 + r1;
                            ST16(r3 + 18, r0);
                        } else {
                            r0 = LD16(r13);
                            r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060F08B0);
                            if (!(((r0 & 0xFFFF) & 255) == 0)) {
                                r4 = LD16(r13);
                                SETSP((sp - 48));
                                r0 = GCALL1(0x06022044, (r4 & 0xFFFF));
                            }
                            r4 = LD16(r13);
                            SETSP((sp - 48));
                            r0 = GCALL1(0x06020DB4, (r4 & 0xFFFF));
                            r4 = LD16(r13);
                            r4 = ((r4 & 0xFFFF) << 1) + 0x060EC8B0;
                            r1 = LD16(r4);
                            ST16(r4, (r1 & 0xFFF8));
                            r0 = LD16(r4);
                            ST16(r4, (r0 | 133));
                            r4 = LD16(r13);
                            SETSP((sp - 48));
                            r0 = GCALL1(0x06022B0A, r4);
                            r3 = LD32(0x060DF988);
                            ST32(0x060D7E98, r3);
                            r0 = LD32(0x060DF98C);
                            ST32(0x060D7EA0, r0);
                            r5 = LD16(r13);
                            SETSP((sp - 48));
                            r0 = GCALL2(0x0600C7BE, 224, r5);
                            r4 = LD16(r12);
                            SETSP((sp - 48));
                            r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
                            ST16(r12, r14);
                            r4 = (r10 << 1) + r8;
                            ST32(sp - 48, r4);
                            r4 = LD16(r4);
                            SETSP((sp - 48));
                            r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
                            r2 = LD32(sp - 48);
                            ST16(r2, r14);
                            r0 = LD8(r9);
                            r0 = r0 & 255;
                            if (!(r0 == 17)) {
                                r4 = 0x108;
                                SETSP((sp - 48));
                                r0 = GCALL1(0x0600996A, r4);
                            } else {
                                if ((3 & r10) == 0) {
                                    r4 = 0x108;
                                    SETSP((sp - 48));
                                    r0 = GCALL1(0x0600996A, r4);
                                }
                            }
                        }
                    }
                    r10 = r10 + 1;
                    r12 = r12 + 2;
                    r13 = r13 + 2;
                    if ((unsigned)r10 >= (unsigned)40) {
                        break;
                    }
                    POLL();
                }
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
    } else {
        r6 = 80;
        r4 = r14;
        do {
            r5 = r4;
            ST16(0x060C0574 + r4, r14);
            ST16(r8 + r5, r14);
            r4 = r4 + 2;
            ST16(0x060C0524 + r5, r14);
        } while (AGAIN(!((unsigned)r4 >= (unsigned)r6)));
        r4 = 0x060C0681;
        r0 = LD8(r9);
        if (!((r0 & 255) == 17)) {
            ST32(r13, 0x060B424C);
            ST32(r12, 0x060B42A4);
            r0 = LD8(r4);
            if (!((r0 & 255) == 1)) {
                ST16(0x060C0626, 37);
            } else {
                r2 = 24;
                ST16(0x060C0626, r2);
            }
        } else {
            ST32(r13, 0x060B42F6);
            ST32(r12, 0x060B43A8);
            r0 = LD8(r4);
            if (!((r0 & 255) == 1)) {
                ST16(0x060C0626, 8);
            } else {
                r2 = 5;
                ST16(0x060C0626, r2);
            }
        }
        ST16(0x060C061E, r14);
        ST16(0x060C061C, r14);
        r1 = LD32(r13);
        r0 = LD16(r1);
        ST16(0x060C0620, (r0 + r11));
        r3 = LD32(r12);
        r2 = LD16(r3);
        ST16(r10, (r11 + r2));
        r0 = LD8(0x060C0682);
        if (((r0 & 255) & 2) == 0) {
            r3 = 1;
        } else {
            r3 = 0;
        }
        ST16(0x060C0624, r3);
        ST16(0x060C0628, r14);
        ST8(r7, 3);
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
        r0 = GJUMP1(0x0600996A, 0x105);
        return r0;
    }
}

void f060142E2(int left, unsigned int top, unsigned int right, unsigned int bottom)
{
    unsigned int row;

    for (row = top; row <= bottom; row++) {
        gaddr cell = FLAGS_AT(GCALL2(0x0600C950, left, row));
        unsigned int col = left;

        POLL();
        if (col <= right) {
            do {
                if (!(LDU16(cell) & 0x80))
                    ST16(cell, LDU16(cell) | 0x85);
                col++;
                cell += 2;
            } while (AGAIN(col <= right));
        }
    }
}

void f06014344(void)
{
    unsigned int left = LDU16(0x060D7E7C);
    unsigned int y0 = LDU16(0x060D7E7E);
    unsigned int right = LDU16(0x060D7E80);
    unsigned int top, bottom, y, x, d;
    gaddr p;

    if (LD8(0x060C029C) != 17) {
        GCALL4(0x060142E2, left, y0 - 4, right, y0);
        d = LDU16(0x060D7E82);
        top = d - 1;
        bottom = d + 3;
    } else {
        GCALL4(0x060142E2, left, y0 - 3, right, y0 + 4);
        d = LDU16(0x060D7E82);
        top = d - 2;
        bottom = d + 4;
    }
    right = LDU16(0x060D7E80);
    left = LDU16(0x060D7E7C);
    POLL();
    y = top;
    while (y <= bottom) {
        p = 0x060EC8B0 + GCALL2(0x0600C950, left, y) * 2;
        x = left;
        if (x <= right) {
            do {
                if (!(LDU16(p) & 128))
                    ST16(p, LD16(p) | 133);
                p += 2;
                x++;
            } while (AGAIN(x <= right));
        }
        y++;
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060143D8(void)
{
}

void f060143E0(int n)
{
    int off;

    for (off = 36; off <= 96; off += 2)
        ST16((OBJECTS + 0x30) + n * 124 + off, 0);
}

void f0601446E(void)
{
    int i = 0;
    gaddr p = 0x060D5F30;

    ST16(0x060C0632, 0);
    do {
        i++;
        ST8(p + 4, 128);
        ST16(p + 22, 0);
        ST8(p + 8, 255);
        ST16(p + 14, 0);
        ST8(p + 9, 0);
        ST32(p, 0x060143D8);
        p += 124;
    } while (AGAIN(i < 50));
    i = 0;
    p = LINKS;
    ST8(0x060C0636, 0);
    do {
        ST8(p, 255);
        i++;
        ST8(p + 2, 0);
        ST8(p + 1, 0);
        ST8(p + 3, 0);
        ST32(p + 4, 0x060143D8);
        p += 8;
    } while (AGAIN(i < 120));
    ST16(0x060C0630, 0);
    ST8(LINKS + 1, 1);
    ST8(LINKS + 2, 1);
    ST32(0x060C0638, GCALL4(0x060069B2, 0x06014616, 0x060D5730, 0x800, 1));
}

void f060144E4(int n, int v)
{
    ST32((OBJECTS + 0x30) + n * 124, v);
}

void f060144F4(int fn)
{
    POLL();
    ST32(REC(LDU16(0x060C062C)), fn);
}

void f06014504(int b, int v)
{
    ST8(LD32(CURRENT) + 9, b);
    GJUMP1(0x060144F4, v);
}

/* Takes the first 8-byte slot from 2 to 119 whose first byte is 255 and chains it in after the slot that slot 1 names as previous. */
int f06014516(int value)
{
    REF(Link) head = ELEM(Link, LINKS, 1);
    REF(Link) e, last;
    int i;

    for (i = 2; i < 120; i++) {
        if (GET(Link, ELEM(Link, LINKS, i), tag) == 255)
            break;
        POLL();
    }
    if (i == 120)
        return -1;
    e = ELEM(Link, LINKS, i);
    SET(Link, e, tag, LD8(0x060C062D));
    SET(Link, e, next, 1);
    SET(Link, e, prev, GET(Link, head, prev));
    last = ELEM(Link, LINKS, GET(Link, e, prev));
    SET(Link, last, next, i);
    SET(Link, head, prev, i);
    SET(Link, e, saved, LD32(LD32(0x060D7768)));
    ST32(LD32(0x060D7768), value);
    return i;
}

void f060145A8(void)
{
    REF(Link) e = ELEM(Link, LINKS, GET(Link, ELEM(Link, LINKS, 1), prev));

    while (GET(Link, e, prev) != 1) {
        POLL();
        if (GET(Link, e, tag) == LDU16(0x060C062C)) {
            SET(Link, e, tag, 255);
            SET(Link, ELEM(Link, LINKS, GET(Link, e, next)), prev, GET(Link, e, prev));
            SET(Link, ELEM(Link, LINKS, GET(Link, e, prev)), next, GET(Link, e, next));
            ST32(LD32(CURRENT), GET(Link, e, saved));
            return;
        }
        e = ELEM(Link, LINKS, GET(Link, e, prev));
    }
}

void f0601471C(unsigned short idx, int handler)
{
    gaddr rec;

    ST16(0x060C062E, idx);
    rec = REC(idx);
    if (LD16(rec + 22))
        return;
    if (!(GCALL1(0x060691DA, 100) & 0xFFFF))
        return;
    ST16(rec + 22, LD16(0x060C1AAA));
    ST32(rec, handler);
    ST8(rec + 4, 0);
    ST8(rec + 9, 0);
    ST16(0x060C0632, LD16(0x060C0632) + 1);
}

void f06014776(int i)
{
    gaddr bomber = REC(i);

    if (LD16(bomber + 22) != 0) {
        GCALL1(0x060692DC, LDU16(bomber + 22));
        ST16(bomber + 22, 0);
    }
    ST8(bomber + 4, LD8(bomber + 4) | 128);
    GCALL1(0x06014820, i);
    ST16(0x060C0632, LD16(0x060C0632) - 1);
}

void f060147BC(void)
{
    GJUMP1(0x06014776, LDU16(0x060C062C));
}

void f060147C4(unsigned int first, unsigned int last)
{
    if (first > last)
        return;
    do {
        GCALL1(0x06014776, first);
        first++;
    } while (AGAIN(first <= last));
}

void f06014820(unsigned short id)
{
    REF(Link) e = ELEM(Link, LINKS, 0);

    while (GET(Link, e, next) != 0) {
        POLL();
        if (GET(Link, e, tag) == id) {
            SET(Link, e, tag, 255);
            SET(Link, ELEM(Link, LINKS, GET(Link, e, prev)), next, GET(Link, e, next));
            SET(Link, ELEM(Link, LINKS, GET(Link, e, next)), prev, GET(Link, e, prev));
        }
        e = ELEM(Link, LINKS, GET(Link, e, next));
    }
}

void f0601486E(int a, int who)
{
    int rec = (OBJECTS + 0x30) + who * 124;
    int step = LD8(rec + 6) == 4 ? -1 : 1;

    GJUMP2(0x06069462, a, LD16(OBJS + 4 + (unsigned short)(LDU16(rec + 22) * 84)) + step);
}

void f060148AE(int obj, int n)
{
    gaddr p = 0x060D5F30 + n * 124;
    int step = (unsigned char)LD8(p + 6) == 4 ? 1 : -1;
    short v = LD16(OBJS + 4 + (unsigned short)(LD16(p + 22) * 84));

    GJUMP2(0x06069462, obj, v + step);
}

void f060149E0(int n)
{
    gaddr rec = REC(n);
    unsigned short obj = LDU16(rec + 22);
    unsigned short cell = LDU16(rec + 20);

    GJUMP2(0x0606950C, OBJ(obj), (LDU16(0x060EC8B0 + cell * 2) & 0x1000) ? 3 : 0);
}

void f060149FC(int cell, unsigned short obj)
{
    GJUMP2(0x0606950C, OBJ(obj), (LDU16(0x060EC8B0 + cell * 2) & 0x1000) ? 3 : 0);
}

void f06014A48(void)
{
    int i;
    int bits;

    ST8(0x060C063C, 0);
    for (i = 0; i < (unsigned char)LD8(0x060C063D); i++) {
        bits = LD8(0x060C0640 + i) & 3;
        ST8(0x060C0654 + i, bits);
        if (bits)
            ST8(0x060C063C, LD8(0x060C063C) + 1);
        POLL();
    }
}

void f06014A90(void)
{
    int i;

    ST16(0x060C067C, (unsigned char)LD8(0x060C063D));
    ST16(0x060C067E, 0);
    for (i = 0; i < (unsigned char)LD8(0x060C063D); i++) {
        ST8(0x060E1A98 + i, 0xFF);
        POLL();
    }
}

void f06014ABA(void)
{
    gaddr t = LD32(CURRENT);

    ST8(t + 4, LD8(t + 4) & 223);
    ST16(t + 38, 0);
    ST16(t + 54, 0);
    ST16(t + 42, 0);
    ST16(t + 44, 0);
    ST16(t + 68, 0);
    ST16(t + 82, 0);
    ST16(t + 46, LD16(t + 46) & 0xFEFF);
    ST16(t + 72, 0);
    ST16(t + 70, 0);
    ST16(t + 84, 0);
}

void f06014B0A(void)
{
    if (LD16(LD32(CURRENT) + 68))
        GCALL1(0x06009A3A, 18);
    GJUMP0(0x06014ABA);
}

void f06014B54(void)
{
    gaddr t = LD32(CURRENT);

    ST8(t + 32, 2);
    ST8(t + 33, 2);
    ST8(t + 34, 2);
    ST8(t + 35, 2);
    ST16(t + 16, 0xC000);
    ST16(t + 46, LD16(t + 46) & 0x800);
    if (!LD16(t + 46))
        ST16(t + 36, 0);
    ST16(t + 48, 0);
    ST16(t + 50, 0);
    ST16(t + 56, 0);
    ST16(t + 74, 0);
    ST16(t + 40, 0);
    ST16(t + 66, 0);
    ST16(t + 60, 0);
    ST16(t + 86, 0);
    ST16(t + 90, 0);
    GCALL0(0x06014ABA);
    t = LD32(CURRENT);
    ST32(t + 108, 0x060143D8);
    ST32(t + 104, 0x060143D8);
    ST32(t + 100, 0x060143D8);
}

void f06014BD2(void)
{
    gaddr t = LD32(CURRENT);

    ST16(t + 10, 0);
    ST16(t + 12, 1);
    if ((unsigned char)LD8(0x060C029C) < 7)
        GCALL0(0x06015F1C);
    t = LD32(CURRENT);
    ST16(t + 18, 0x4B0);
    ST8(t + 7, 0);
    ST16(t + 46, 0);
    ST16(t + 78, 2);
    ST16(t + 52, 2);
    ST16(t + 76, 1);
    ST16(t + 62, 1);
    ST16(t + 80, 0);
    ST16(t + 64, 0);
    ST16(t + 88, 0);
    GJUMP0(0x06014B54);
}

int f06014C42(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    SETSP((sp - 28));
    r0 = GCALL0(0x06014A48);
    r9 = 0x060C06C0;
    r14 = 0;
    r13 = 0;
    r10 = 0x060C063D;
    r11 = 0x060143E0;
    r12 = 0x060D7768;
    ST32(0x060D7768, 0x060D5F30);
    while (1) {
        r2 = LD8(r10);
        if (!((unsigned)r13 >= (unsigned)(r2 & 255))) {
            POLL();
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 28));
            SETPR(0x06014C90);
            r0 = GCALL1(r11, r13);
            SETSP((sp - 28));
            r0 = GCALL0(0x06014BD2);
            ST32((r13 << 2) + r9, r14);
            r13 = r13 + 1;
            r3 = LD32(r12);
            ST32(r12, (r3 + 124));
            continue;
        } else {
            break;
        }
    }
    SETSP((sp - 28));
    r0 = GCALL0(0x06014A90);
    SETSP((sp - 28));
    r0 = GCALL1(0x0600A4EC, 16);
    if (!((r0 & r0) == 0)) {
        ST8(0x060C063E, 6);
    } else {
        ST8(0x060C063E, 3);
    }
    r11 = r14;
    r9 = 2;
    r10 = 5;
    r12 = 0x060D82D4 + r14;
    r13 = 0x060D8304 + r14;
    r7 = 0x060D82DC + r14;
    ST8(0x060C063F, r14);
    ST16(0x060C068C, r14);
    ST16(0x060C068A, r14);
    r1 = 0x060C0690;
    do {
        r0 = r11 << 2;
        r6 = r14;
        ST32(r0 + r1, r14);
        r5 = r13 + r14;
        r4 = r14 + r7;
        do {
            r6 = r6 + 1;
            ST32(r4, r14);
            ST8(r5, r14);
            r5 = r5 + 1;
            r4 = r4 + 4;
        } while (AGAIN(!((unsigned)r6 >= (unsigned)r10)));
        ST8(r12, r14);
        r11 = r11 + 1;
        r12 = r12 + 1;
        r7 = r7 + 20;
        r13 = r13 + 5;
    } while (AGAIN(!((unsigned)r11 >= (unsigned)r9)));
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06014D22(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    r0 = GCALL0(0x06014A48);
    r12 = 0x060C063D;
    r13 = 0x060D7768;
    r2 = 0x060D5F30;
    r14 = 0;
    while (1) {
        ST32(r13, r2);
        r3 = LD8(r12);
        if (!((unsigned)r14 >= (unsigned)(r3 & 255))) {
            POLL();
            SETSP((sp - 16));
            r0 = GCALL0(0x06014BD2);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x06014D40);
            r0 = GCALL1(0x06014FEA, r14);
            r2 = LD32(r13);
            r14 = r14 + 1;
            r2 = r2 + 124;
            continue;
        } else {
            break;
        }
    }
    SETSP((sp - 16));
    r0 = GCALL0(0x06014A90);
    SETSP((sp - 16));
    SETPR(0x06014D5A);
    r0 = GCALL0(0x0601ACFE);
    SETSP((sp - 16));
    SETPR(0x06014D60);
    r0 = GCALL0(0x06026734);
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x06010468);
    return r0;
}

int f06014D6C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = 0;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r12 = 0x060C063D;
    r13 = 0x060D7768;
    ST32(0x060D7768, 0x060D5F30);
    while (1) {
        r3 = LD8(r12);
        if (!((unsigned)r14 >= (unsigned)(r3 & 255))) {
            POLL();
            SETSP((sp - 16));
            r0 = GCALL0(0x06014B54);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x06014D88);
            r0 = GCALL1(0x06014FEA, r14);
            r2 = LD32(r13);
            r14 = r14 + 1;
            ST32(r13, (r2 + 124));
            continue;
        } else {
            break;
        }
    }
    ST32(0x060C069C, 0);
    ST32(0x060C0698, 0);
    SETSP((sp - 16));
    r0 = GCALL0(0x06014A90);
    SETSP((sp - 16));
    SETPR(0x06014DA8);
    r0 = GCALL0(0x0601ACFE);
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x06010468);
    return r0;
}

int f06014DB4(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    r0 = GCALL0(0x06014A48);
    r12 = 0x060C063D;
    r14 = 0x060D7768;
    r3 = 0x060D5F30;
    r13 = 0;
    while (1) {
        ST32(r14, r3);
        r2 = LD8(r12);
        if (!((unsigned)r13 >= (unsigned)(r2 & 255))) {
            POLL();
            SETSP((sp - 16));
            r0 = GCALL0(0x06014B54);
            r13 = r13 + 1;
            r3 = LD32(r14);
            r3 = r3 + 124;
            continue;
        } else {
            break;
        }
    }
    ST32(0x060C069C, 0);
    ST32(0x060C0698, 0);
    SETSP((sp - 16));
    r0 = GCALL0(0x06014A90);
    SETSP((sp - 16));
    SETPR(0x06014DEC);
    r0 = GCALL1(0x06014F0A, 0);
    SETSP((sp - 16));
    r0 = GCALL2(0x06014F68, 0, 96);
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x06010468);
    return r0;
}

int f06014DFE(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), MACL());
    r0 = LD8(0x060C0682);
    r0 = r0 & 255;
    if (!((r0 & 8) == 0)) {
        r4 = 0x060D7768;
        r2 = LD16(0x060C068C);
        r2 = ((r2 & 0xFFFF) * 124) + 0x060D5F30;
        ST32(0x060D7768, r2);
        r5 = r2;
        r0 = LD16(0x060C068A);
        r0 = r0 & 0xFFFF;
        if (r0 == 1) {
            r0 = LD8(r5 + 7);
            r0 = r0 + 1;
            ST8(r5 + 7, r0);
            SETMACL(LD32((sp - 4)));
            return r0;
        } else {
            if (r0 == 2) {
                r3 = LD16(64 + r5);
                ST16(64 + r5, (r3 | 0x200));
                r0 = LD32(r4);
                r3 = LD16((64 + r0));
                r2 = 80 + r0;
                ST16(r2, r3);
                SETMACL(LD32((sp - 4)));
                return r0;
            } else {
                if (r0 == 3) {
                    r1 = LD16(62 + r5);
                    ST16(62 + r5, (r1 + 1));
                    r0 = LD32(r4);
                    r1 = LD16((62 + r0));
                    ST16((76 + r0), r1);
                    SETMACL(LD32((sp - 4)));
                    return r0;
                } else {
                    if (r0 == 4) {
                        SETMACL(LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP0(0x06015ECA);
                        return r0;
                    } else {
                        if (r0 == 5) {
                            r3 = LD16(64 + r5);
                            ST16(64 + r5, (r3 | 0x100));
                            r0 = LD32(r4);
                            r3 = LD16((64 + r0));
                            r2 = 80 + r0;
                            ST16(r2, r3);
                            SETMACL(LD32((sp - 4)));
                            return r0;
                        } else {
                            if (r0 == 6) {
                                SETMACL(LD32((sp - 4)));
                                UNFRAME(sp);
                                r0 = GJUMP0(0x06015F1C);
                                return r0;
                            } else {
                                if (r0 == 7) {
                                    r0 = LD8(0x060C029C);
                                    r0 = r0 & 255;
                                    if (!(r0 == 17)) {
                                        SETMACL(LD32((sp - 4)));
                                        return r0;
                                    } else {
                                        SETMACL(LD32((sp - 4)));
                                        UNFRAME(sp);
                                        r0 = GJUMP0(0x060241AC);
                                        return r0;
                                    }
                                } else {
                                    SETMACL(LD32((sp - 4)));
                                    return r0;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        SETMACL(LD32((sp - 4)));
        return r0;
    }
}

int f06014F0A(int r4)
{
    int r0, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r0 = LD8(0x060C029C);
    r13 = r4;
    if (!((r0 & 255) == 8)) {
        SETSP((sp - 20));
        r0 = GCALL2(0x06008A6A, 8, 0);
        r4 = 231;
        r13 = (((r13 << 2) << 2) + r13) << 1;
    } else {
        SETSP((sp - 20));
        r0 = GCALL2(0x06008A6A, 8, 1);
        r4 = 154;
        r13 = 0;
    }
    r14 = r4;
    r11 = 0x06068BDC;
    r12 = r4 + 34;
    r13 = r13 + r14;
    if (!((unsigned)r14 >= (unsigned)r12)) {
        do {
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x06014F54);
            r0 = GCALL1(r11, r13);
            r14 = r14 + 1;
            r13 = r13 + 1;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r12)));
    }
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06014F68(int n, unsigned short first)
{
    if (LDU8(0x060C029C) != 8) {
        GCALL2(0x06008A6A, 1, 0);
        n += 4;
    } else {
        GCALL2(0x06008A6A, 1, 1);
        n = 1;
    }
    return GJUMP2(0x06008ECA, n, first);
}

int f06014FC4(void)
{
    int r0, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = 0;
    ST32((sp - 8), R(13));
    r13 = 12;
    ST32((sp - 12), PR());
    do {
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06014FD2);
        r0 = GCALL1(0x06014F0A, r14);
        SETSP((sp - 12));
        r0 = GCALL2(0x06014F68, r14, ((r14 << 2) << 2));
        r14 = r14 + 1;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r13)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06014FEA(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32(sp - 12, r4);
    r4 = 0x060C064A + r4;
    ST32(sp - 8, r4);
    r4 = LD8(r4);
    SETSP((sp - 12));
    SETPR(0x06014FFE);
    r0 = GCALL1(0x06014F0A, (r4 & 255));
    r5 = LD32(sp - 12);
    r4 = LD32(sp - 8);
    r4 = LD8(r4);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06014F68, (r4 & 255), (((r5 << 2) << 2) + 96));
    return r0;
}

void f06015012(unsigned short a, unsigned short b, unsigned short c, unsigned int d)
{
    int i;
    int rec;

    ST32(CURRENT, (OBJECTS + 0x30));
    for (i = 0; i < (unsigned char)LD8(BOMBER_COUNT); i++) {
        rec = LD32(CURRENT);
        if (!(LD8(rec + 4) & 192)) {
            ST16(rec + 62, a);
            ST16(rec + 76, a);
            ST16(rec + 52, b);
            ST16(rec + 78, b);
            ST16(rec + 64, c);
            ST16(rec + 80, c);
            ST16(rec + 12, d >> 16);
            ST16(rec + 10, d);
        }
        ST32(CURRENT, LD32(CURRENT) + 124);
        POLL();
    }
}

void f06015080(void)
{
    int i, p, kind;

    for (i = 0;; i++) {
        p = (OBJECTS + 0x30) + i * 124;
        ST32(0x060D7768, p);
        if (i >= (unsigned char)LD8(0x060C063D))
            break;
        if (!(LD8(p + 4) & 192)) {
            kind = (unsigned char)LD8(0x060C064A + i);
            if (kind == 10) {
                ST16(p + 80, LD16(p + 80) | 0x200);
                ST16(p + 64, LD16(p + 64) | 0x200);
            }
            if (kind == 11 && LDU16(p + 12) < 3)
                ST16(p + 12, LD16(p + 12) + 1);
        }
        POLL();
    }
}

int f0601510C(void)
{
    int k = 0;

    do {
        ST16(0x060C06EC + k, 2);
        ST16(0x060C06E8 + k, 1);
        ST16(0x060C06F0 + k, 0);
        ST16(0x060C08FC + k, 0);
        ST16(0x060C06F4 + k, 0x100);
        ST16(0x060C06F8 + k, 0x4B0);
        k += 2;
    } while (AGAIN(k < 4));
    return 0x060C06F8;
}

void f06015156(void)
{
    gaddr t = LD32(CURRENT);

    ST32(t + 100, 0x060154A4);
    ST32(t + 104, 0x06015808);
    ST32(t + 108, 0x06015B8C);
}

void f06015172(void)
{
    gaddr t = LD32(CURRENT);

    ST32(t + 108, 0x060143D8);
    ST32(t + 104, 0x060143D8);
    ST32(t + 100, 0x060143D8);
}

int f06015190(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = r4;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(8));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    ST32(sp - 44, r5);
    ST32(sp - 36, r6);
    ST32(sp - 40, r7);
    r0 = LD8(0x060C029C);
    if (!((r0 & 255) == 8)) {
        r4 = 0;
    } else {
        r4 = 1;
    }
    SETSP((sp - 44));
    r0 = GCALL1(0x06008A96, r4);
    SETSP((sp - 44));
    r0 = GCALL2(0x0601471C, r13, 0x06015358);
    r11 = 0x060C062C;
    r2 = LD16(0x060C062C);
    r14 = 0x060D7768;
    r12 = 0x060D7B3C;
    ST32(sp - 32, (r2 & 0xFFFF));
    ST16(0x060C062C, r13);
    r3 = (r13 * 124) + 0x060D5F30;
    ST32(0x060D7768, r3);
    r0 = LD8(0x060C0654 + r13);
    ST8(r3 + 4, r0);
    r3 = LD32(0x060D7768);
    r1 = LD32(sp - 40);
    ST16(58 + r3, r1);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 22);
    ST16(0x060C1AA8, r0);
    ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
    r6 = LD32(sp - 36);
    r5 = LD32(sp - 44);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 44));
    r0 = GCALL3(0x0600D0E4, r4, r5, r6);
    SETSP((sp - 44));
    r0 = GCALL0(0x06015D16);
    r3 = LD32(0x060D7768);
    ST8(r3 + 6, 2);
    SETSP((sp - 44));
    r0 = GCALL0(0x06015156);
    r2 = LD32(0x060D7B3C);
    ST16(46 + r2, (((r13 << 2) << 2) + 96));
    r0 = LD8(0x060C029C);
    if (!((r0 & 255) == 8)) {
        r3 = LD32(r12);
        r1 = LD8(0x060C064A + r13);
        ST16(48 + r3, ((((((r1 & 255) << 2) << 2) + (r1 & 255)) << 1) + 230));
    } else {
        r1 = LD32(r12);
        ST16(48 + r1, 153);
    }
    r3 = LD32(r14);
    r2 = LD16(46 + r3);
    if (((r2 & 0xFFFF) & 0x800) == 0) {
        SETR(11, r11);
        SETSP((sp - 44));
        SETPR(0x060152F0);
        r0 = GCALL1(0x060165B8, 6);
    } else {
        r8 = LD32(r14);
        r8 = r8 + 36;
        r5 = LD16(r11);
        r5 = LD8(0x060D82D4 + (r5 & 0xFFFF));
        r4 = LD32(r14);
        r0 = LD16(r4 + 20);
        SETR(8, r8);
        SETR(11, r11);
        SETR(12, r12);
        SETR(14, r14);
        SETSP((sp - 44));
        SETPR(0x060152B8);
        r0 = GCALL2(0x0601AF3E, (r0 & 0xFFFF), (r5 & 255));
        ST16(r8, r0);
        r1 = LD16(r11);
        r3 = LD32(r14);
        r2 = LD16(36 + r3);
        ST16(0x060D5F54 + ((r2 & 0xFFFF) * 124), r1);
        SETR(11, r11);
        SETR(12, r12);
        SETR(14, r14);
        SETSP((sp - 44));
        SETPR(0x060152D4);
        r0 = GCALL1(0x060165B8, 28);
        r4 = LD32(r14);
        r0 = LD8(r4 + 6);
        SETSP((sp - 44));
        r0 = GCALL1(0x06016776, (r0 & 255));
        r8 = LD32(r12);
        SETSP((sp - 44));
        r0 = GCALL0(0x060167DE);
        ST16((r8 + 38), r0);
    }
    r3 = LD32(sp - 32);
    ST16(r11, r3);
    SETMACL(LD32((sp - 28)));
    SETPR(LD32((sp - 24)));
    SETR(8, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06015358(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r0 = LD16(0x060D7E68);
    if (!(((r0 & 0xFFFF) & 1) == 0)) {
        SETSP((sp - 8));
        r0 = GCALL0(0x060153BC);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06015CD2);
        return r0;
    } else {
        r14 = 0x060D7768;
        r0 = LD32(0x060D7768);
        r0 = LD8(r0 + 4);
        if (((r0 & 255) & 3) == 2) {
            r4 = LD16(0x060C062C);
            SETSP((sp - 8));
            r0 = GCALL1(0x06015408, (r4 & 0xFFFF));
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06015382);
            r0 = GCALL0(0x06010930);
        }
        SETSP((sp - 8));
        r0 = GCALL0(0x060153BC);
        r2 = LD32(r14);
        r3 = LD32(100 + r2);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06015390);
        r0 = GCALL0(r3);
        r1 = LD32(r14);
        r3 = LD32(104 + r1);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x0601539A);
        r0 = GCALL0(r3);
        r2 = LD32(r14);
        r3 = LD32(108 + r2);
        SETSP((sp - 8));
        SETPR(0x060153A4);
        r0 = GCALL0(r3);
        SETSP((sp - 8));
        r0 = GCALL0(0x06016908);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06016394);
        return r0;
    }
}

void f060153BC(void)
{
    gaddr t = LD32(CURRENT);
    gaddr tbl;
    int pad;

    if ((LDU16(t + 46) & 0x2000) || (LDU16(0x060D7E68) & 1)) {
        ST16(0x060C0688, 0);
        ST16(0x060C0686, 0);
        ST16(0x060C0684, 0);
    } else {
        pad = LDU16(0x060C062C) * 2;
        ST16(0x060C0684, LD16(0x26006096 + pad));
        ST16(0x060C0686, LD16(0x260060B0 + pad));
        ST16(0x060C0688, LD16(0x260060CA + pad));
    }
    tbl = LD16(0x060BF5EA) ? 0x060B2EB0 : 0x060BF5EC + LDU16(0x060C062C) * 16;
    ST16(0x060BF5DC, LD16(tbl + 2));
    ST16(0x060BF5DE, LD16(tbl + 4));
    ST16(0x060BF5E4, LD16(tbl + 10));
    ST16(0x060BF5E0, LD16(tbl + 6));
    ST16(0x060BF5E2, LD16(tbl + 8));
    ST16(0x060BF5E6, LD16(tbl + 12));
    ST16(0x060BF5E8, LD16(tbl + 14));
}

void f06015408(int n)
{
    int src = LD16(0x060BF5EA) ? 0x060B2EB0 : 0x060BF5EC + n * 16;

    ST16(0x060BF5DC, LD16(src + 2));
    ST16(0x060BF5DE, LD16(src + 4));
    ST16(0x060BF5E4, LD16(src + 10));
    ST16(0x060BF5E0, LD16(src + 6));
    ST16(0x060BF5E2, LD16(src + 8));
    ST16(0x060BF5E6, LD16(src + 12));
    ST16(0x060BF5E8, LD16(src + 14));
}

void f060157E4(void)
{
    GCALL0(0x060153BC);
    if (LDU16(0x060C0686) & LDU16(0x060BF5E0))
        GJUMP1(0x0601FF30, 0);
}

int f06015B48(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 20);
    r3 = (r0 & 0xFFFF) << 1;
    r0 = LD16(0x060EE8B0 + r3);
    ST16((0x060EE8B0 + r3), (r0 & 0xEFFF));
    SETSP((sp - 4));
    SETPR(0x06015B66);
    r0 = GCALL0(0x06016EB6);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x06015D16);
    return r0;
}

int f06015B8C(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r5 = 7;
    ST32((sp - 8), R(13));
    r14 = 0x060D7768;
    ST32((sp - 12), PR());
    r4 = LD32(0x060D7768);
    r3 = LD16(86 + r4);
    if (((r3 & 0xFFFF) & 7) == 0) {
        r0 = LD16(r4 + 20);
        r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EE8B0);
        r6 = r0 & 255;
        r7 = r6 & 0xFFFF;
        if (r7 >= 5) {
            if (!(r7 >= 9)) {
                r2 = LD8(0x060C02C0);
                ST16(86 + r4, (((r6 + 0xFFFB) ^ (r2 & 255)) + 1));
            }
        }
    }
    r13 = 0x060C08F8;
    r3 = LD32(r14);
    r2 = LD16(86 + r3);
    if (!(((r2 & 0xFFFF) & r5) == 0)) {
        r3 = LD32(r14);
        r4 = 0xFF00;
        r2 = LD16(86 + r3);
        r3 = LD16(0x060B4800 + (((r2 & 0xFFFF) & r5) << 1));
        ST16(0x060C0684, r3);
        r3 = LD32(r14);
        r2 = LD16(86 + r3);
        r5 = 1;
        if (((r2 & 0xFFFF) & 0xFF00) == 0) {
            r3 = LD16(0x060C0630);
            ST32(r13, (((r3 & 0xFFFF) & r5) << 16));
        } else {
            r3 = LD32(r14);
            r2 = LD16(86 + r3);
            ST32(r13, (((r2 & 0xFFFF) & r4) << 8));
        }
        ST16(0x060C08F6, r5);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06015C24);
        r0 = GCALL0(0x06015B48);
    }
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 12));
    SETPR(0x06015C2A);
    r0 = GCALL0(0x06016CB0);
    ST16(0x060C08F6, 0);
    r1 = LD16(0x060C0684);
    if (((r1 & 0xFFFF) & 0xF000) == 0) {
        r4 = LD32(r14);
        r0 = LD16(r4 + 22);
        SETSP((sp - 12));
        r0 = GCALL1(0x0606948A, r0);
    } else {
        r2 = LD32(0x060D7768);
        r3 = LD16(46 + r2);
        if (!(((r3 & 0xFFFF) & 0x32D) == 0)) {
            r4 = LD32(r14);
            r0 = LD16(r4 + 22);
            SETSP((sp - 12));
            r0 = GCALL1(0x0606948A, r0);
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x06015D8A);
            ST32(r13, r0);
            SETSP((sp - 12));
            r0 = GCALL1(0x06015E8C, r0);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06015C5A);
            r0 = GCALL0(0x06015B48);
        }
    }
    r0 = LD32(r14);
    r0 = LD16(r0 + 46);
    if (!(((r0 & 0xFFFF) & 32) == 0)) {
        r3 = LD32(r14);
        r0 = LD16(66 + r3);
        if ((r0 & r0) == 0) {
            r3 = LD32(r14);
            r1 = LD16(46 + r3);
            ST16(46 + r3, (r1 & 0xFFDF));
        }
    }
    SETR(14, r14);
    SETSP((sp - 12));
    SETPR(0x06015CC0);
    r0 = GCALL0(0x060165FE);
    r0 = LD32(r14);
    ST16((86 + r0), 0);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06015CD2(void)
{
    gaddr t = LD32(CURRENT);

    ST16(t + 20, GCALL0(0x0600CA7C));
    ST16(LD32(CURRENT) + 24, LD16(0x060D7E88));
    ST16(LD32(CURRENT) + 26, LD16(LD32(MOVER_PTR) + 12));
    ST16(LD32(CURRENT) + 28, LD16(0x060D7E8A));
    ST16(LD32(CURRENT) + 30, LD16(LD32(MOVER_PTR) + 14));
    GJUMP1(0x0606948A, LD16(LD32(CURRENT) + 22));
}

/* When neither branch runs, the game compares with r6, which 06015CD2 leaves holding the halfword at 060D7E88. */
void f06015D16(void)
{
    gaddr cur;
    gaddr cell;
    int bits;

    GCALL0(0x06015CD2);
    bits = LDU16(0x060D7E88);
    cur = LD32(CURRENT);
    if (LDU16(0x060C062C) >= LDU8(0x060C063D)) {
        cell = 0x060EE8B0 + LDU16(cur + 20) * 2;
        ST16(cell, LDU16(cell) | 0x2000);
        bits = LDU16(cell) & 255;
    } else if (!(LDU8(cur + 4) & 192)) {
        cell = 0x060EE8B0 + LDU16(cur + 20) * 2;
        ST16(cell, LDU16(cell) | 0x1000);
        bits = LDU16(cell) & 255;
    }
    cur = LD32(CURRENT);
    if ((LDU16(cur + 90) & 255) != bits)
        ST16(cur + 90, (LDU16(cur + 90) << 8) | bits);
}

unsigned int f06015D8A(void)
{
    gaddr t = LD32(CURRENT);
    unsigned int v;
    gaddr other;
    int limit;

    if ((LDU16(t + 42) & 1) || (LDU16(t + 46) & 0x400))
        return 0xA000 + LDU16(t + 14);
    if (LDU16(t + 42) & 2)
        return 0x00040000;
    if (!(LDU16(t + 46) & 16)) {
        v = (LDU16(t + 12) << 16) + LDU16(t + 14) + LDU16(t + 10) + LD32(0x060B45C8 + (LDU16(0x060C067E) & 3) * 4);
        if (v > 0x00040000)
            v = 0x00040000;
        if (v < 0xC000)
            v = 0xC000;
        return v;
    }
    other = REC(LDU16(t + 36));
    v = (LDU16(other + 52) << 16) + 0x00020000;
    if (LD16(t + 56)) {
        limit = LD32(0x060B4454 + (short)(LD16(other + 52) * 124) + LDU16(t + 56) * 4);
        if ((unsigned int)limit >= v) {
            ST16(t + 56, 1);
            v = 0;
        } else {
            v -= limit;
        }
    }
    return v;
}

void f06015E8C(int v)
{
    ST16(LD32(CURRENT) + 14, v);
}

int f06015E96(int n)
{
    gaddr p = 0x060D5F30 + n * 124;
    unsigned int x = (((unsigned int)LDU16(p + 12) << 16) + LDU16(p + 10) - 0xC000) >> 13;

    return x > 9 ? 9 : x;
}

void f06015ECA(void)
{
    gaddr t = LD32(CURRENT);
    unsigned int v = (LDU16(t + 12) << 16) + LDU16(t + 10) + 0x2000;

    if (v > 0x00040000)
        v = 0x00040000;
    ST16(t + 10, v);
    ST16(LD32(CURRENT) + 12, v >> 16);
}

void f06015F1C(void)
{
    gaddr t = LD32(CURRENT);
    unsigned int v = (LDU16(t + 12) << 16) + LDU16(t + 10) - 0x2000;

    if (v < 0xC000)
        v = 0xC000;
    ST16(t + 12, v >> 16);
    ST16(LD32(CURRENT) + 10, v);
}

int f06015F48(gaddr p)
{
    if (LD16(p + 42))
        return 42;
    ST16(p + 42, LD16(LD32(0x060D7768) + 42));
    ST16(p + 44, LD16(LD32(0x060D7768) + 44));
    return GJUMP1(0x0600996A, 0x101);
}

void f06015F6E(void)
{
    gaddr t = LD32(CURRENT);

    ST16(t + 62, LD16(t + 76));
    ST16(t + 52, LD16(t + 78));
    if (LD16(t + 72))
        GCALL1(0x060161B0, 2);
    t = LD32(CURRENT);
    if (LDU16(t + 52) >= 16)
        ST16(t + 52, 16);
    if (LDU16(t + 62) >= 10)
        ST16(t + 62, 10);
}

int f06015FC8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r13 = 0x060D7768;
    r14 = LD32(0x060D7768);
    r14 = LD16(74 + r14);
    r14 = ((r14 & 0xFFFF) * 124) + 0x060D5F30;
    r1 = LD16(72 + r14);
    if ((r1 & r1) == 0) {
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x06015FF0);
        r0 = GCALL0(0x06016044);
        SETSP((sp - 16));
        r0 = GCALL0(0x06015156);
    }
    r3 = LD32(r13);
    r0 = LD16(r3 + 20);
    r3 = (r0 & 0xFFFF) << 1;
    r1 = LD16(0x060EE8B0 + r3);
    ST16(0x060EE8B0 + r3, (r1 & 0xEFFF));
    r5 = LD32(r13);
    r0 = LD16(r5 + 22);
    r5 = r0 & 0xFFFF;
    r0 = LD16(r14 + 22);
    SETSP((sp - 16));
    r0 = GCALL2(0x0600A3D8, (r0 & 0xFFFF), r5);
    SETSP((sp - 16));
    r0 = GCALL0(0x06015D16);
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x060165FE);
    return r0;
}

int f06016044(void)
{
    int r0, r1, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x06014B0A);
    r4 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r1 = LD16(46 + r3);
    ST16(46 + r3, (r1 & 0xFEFF));
    r3 = LD32(0x060D7768);
    r0 = LD8(r3 + 4);
    ST8(r3 + 4, (r0 & 175));
    r0 = LD32(0x060D7768);
    r0 = LD16(r0 + 20);
    r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
    r14 = 0;
    if (!(((r0 & 0xFFFF) & 7) == 0)) {
        r3 = LD32(r4);
        r0 = LD16(74 + r3);
        r3 = LD16(0x060C062C);
        if (r0 == r3) {
            r14 = 1;
        } else {
            r3 = LD32(r4);
            r0 = LD8(r3 + 4);
            ST8(r3 + 4, (r0 | 32));
            r3 = LD32(r4);
            ST16((38 + r3), 60);
        }
    }
    SETSP((sp - 8));
    r0 = GCALL0(0x06015F6E);
    SETR(14, r14);
    SETSP((sp - 8));
    SETPR(0x060160A6);
    r0 = GCALL1(0x06016574, 0x2710);
    SETSP((sp - 8));
    r0 = GCALL0(0x06016812);
    SETSP((sp - 8));
    r0 = GCALL0(0x0601BC7E);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r14;
}

int f060160D4(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r0 = 46;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    r14 = 0x060D7768;
    r11 = LD32(0x060D7768);
    r12 = 0x060D7B3C;
    r9 = LD32(0x060D7B3C);
    r13 = 0x060C062C;
    r6 = LD16(0x060C062C);
    r3 = LD16(46 + r4);
    r10 = r6 & 0xFFFF;
    if (((r3 & 0xFFFF) & 0x33D) == 0) {
        r0 = 72;
        r1 = LD16(72 + r4);
        if ((r1 & r1) == 0) {
            ST16(74 + r4, r6);
            ST32(r14, r4);
            r0 = LD16(r4 + 22);
            ST32(r12, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
            ST16(r13, r5);
            r2 = LD32(r14);
            r0 = LD16(68 + r2);
            if (!((r0 & r0) == 0)) {
                r3 = LD32(r14);
                ST16(68 + r3, 0);
                SETSP((sp - 32));
                r0 = GCALL1(0x06009A3A, 18);
                SETR(9, r9);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 32));
                SETPR(0x06016142);
                r0 = GCALL1(0x06020B96, 0x186);
                SETSP((sp - 32));
                r0 = GCALL0(0x06016812);
            }
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 32));
            SETPR(0x0601614C);
            r0 = GCALL0(0x06018D60);
            r3 = LD32(r14);
            r1 = LD16(46 + r3);
            ST16(46 + r3, (r1 | 0x100));
            r3 = LD32(r14);
            ST32(100 + r3, 0x06015FC8);
            r3 = LD32(r14);
            ST32(108 + r3, 0x060143D8);
            ST32(104 + r3, 0x060143D8);
            ST32(r14, r11);
            ST32(r12, r9);
            ST16(r13, r10);
            r3 = LD32(r14);
            r2 = LD16(70 + r3);
            if (!((r2 & 0xFFFF) >= 8)) {
                r1 = LD32(r14);
                r2 = LD16(70 + r1);
                ST16(70 + r1, (r2 + 2));
            }
            SETSP((sp - 32));
            r0 = GCALL0(0x06015F6E);
            SETSP((sp - 32));
            r0 = GCALL1(0x0600996A, 0x100);
        }
    }
    ST32(r14, r11);
    ST32(r12, r9);
    ST16(r13, r10);
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

int f060161B0(int mode)
{
    int matched = 0;
    int rest = 0;
    int i;
    int rec;
    unsigned int me;

    for (i = 0; i < (unsigned char)LD8(BOMBER_COUNT); i++) {
        rec = (OBJECTS + 0x30) + i * 124;
        if (!(LD8(rec + 4) & 192)) {
            me = LDU16(0x060C062C);
            if (i != me) {
                if (LDU16(rec + 46) & 0x100) {
                    if (LDU16(rec + 74) == me) {
                        matched++;
                        if (mode == 2) {
                            ST16(LD32(CURRENT) + 62, LD16(LD32(CURRENT) + 62) + LD16(rec + 62));
                            ST16(LD32(CURRENT) + 52, LD16(LD32(CURRENT) + 52) + LD16(rec + 52));
                        }
                    }
                } else {
                    rest++;
                }
            }
        }
        POLL();
    }
    return mode ? matched : rest;
}

void f0601628E(unsigned int n)
{
    int rec;

    if (n >= 2)
        return;
    rec = (OBJECTS + 0x30) + n * 124;
    if (LDU16(rec + 46) & 0xF7FF)
        return;
    ST16(rec + 46, LD16(rec + 46) | 0x400);
    ST16(rec + 70, 0xFFFC);
    ST16(rec + 84, 0x384);
    GJUMP1(0x0600996A, 12);
}

int f060162D0(void)
{
    gaddr t = LD32(CURRENT);
    unsigned short cell = GCALL1(0x0600C9C0, LD16(t + 20) + 1);

    if (!(LDU16(0x060EC8B0 + cell * 2) & LDU16(LD32(CURRENT) + 18)))
        return 0;
    t = LD32(CURRENT);
    cell = GCALL1(0x0600C9C0, LD16(t + 20) + 64);
    if (!(LDU16(0x060EC8B0 + cell * 2) & LDU16(LD32(CURRENT) + 18)))
        return 0;
    t = LD32(CURRENT);
    cell = GCALL1(0x0600C9C0, LD16(t + 20) - 1);
    if (!(LDU16(0x060EC8B0 + cell * 2) & LDU16(LD32(CURRENT) + 18)))
        return 0;
    t = LD32(CURRENT);
    cell = GCALL1(0x0600C9C0, LD16(t + 20) - 64);
    return (LDU16(0x060EC8B0 + cell * 2) & LDU16(LD32(CURRENT) + 18)) != 0;
}

void f06016394(void)
{
    gaddr cur;
    int v;

    if (LD16(LD32(CURRENT) + 70) != 0) {
        GCALL2(0x0606AAC8, LD32(MOVER_PTR), 3);
        v = LD16(LD32(CURRENT) + 70) * 16 + 0x100;
    } else {
        GCALL2(0x0606AAC8, LD32(MOVER_PTR), 0);
        v = 0x100;
    }
    ST16(LD32(MOVER_PTR) + 70, v);
    ST16(LD32(MOVER_PTR) + 68, v);
    cur = LD32(CURRENT);
    if (!(LDU8(cur + 4) & 128) && !(LDU16(cur + 46) & 0x1000))
        GCALL1(0x060149E0, LDU16(0x060C062C));
    GJUMP0(0x0601640E);
}

int f0601640E(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr target;
    int result;

    if (LDU16(cur + 46) & 0x27D)
        return 46;
    if (LDU8(0x060C029C) >= 9)
        return 46;
    if (!(LDU16(cur + 46) & 0x800)) {
        result = MOVER_PTR;
        target = LD32(MOVER_PTR);
    } else {
        result = 0x060D5F46;
        target = OBJ(LDU16(0x060D5F46 + LDU16(cur + 36) * 124));
    }
    if (!(LDU16(0x060C0684) & 0xF000))
        return result;
    if (!(LDU16(cur + 46) & 0x1000))
        return 46;
    if (LD16(target + 62) == 0)
        return 0;
    if ((unsigned int)LD16(target + 60) > (unsigned int)LD16(target + 62))
        return 62;
    result = GCALL1(0x06068B4E, target);
    if (result & 1)
        return result;
    return GJUMP1(0x0600996A, 24);
}

int f060164CC(int r4)
{
    int r0, r1, r3, r5, r14;
    ENTRY_SP(sp);

    r0 = 46;
    r3 = LD32(0x060D7768);
    r1 = LD16(46 + r3);
    if (((r1 & 0xFFFF) & 0x800) == 0) {
        ST32((sp - 4), R(14));
        r3 = r4;
        ST32((sp - 8), PR());
        r14 = 0x060D7B3C;
        ST32(sp - 12, r4);
        r5 = LD32(0x060D7B3C);
        r5 = LD16(48 + r5);
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 22);
        SETR(14, 0x060D7B3C);
        SETSP((sp - 12));
        SETPR(0x06016502);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), ((r5 & 0xFFFF) + r3));
        if (!((r0 & r0) == 0)) {
            r3 = LD32(r14);
            ST16(60 + r3, 0);
        }
        r3 = LD32(r14);
        ST16(62 + r3, 0x100);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 62;
    } else {
        return r0;
    }
}

int f0601651E(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    r4 = LD32(0x060D7768);
    r5 = LD16(48 + r4);
    r0 = r5 & 0xFFFF;
    r5 = r0;
    if (r0 == 28) {
        return r0;
    } else {
        r0 = r5;
        if (r0 == 6) {
            return r0;
        } else {
            r3 = LD16(46 + r4);
            if (((r3 & 0xFFFF) & 0x800) == 0) {
                r4 = 6;
            } else {
                r4 = 28;
            }
            UNFRAME(sp);
            r0 = GJUMP1(0x06016574, r4);
            return r0;
        }
    }
}

int f06016574(int r4)
{
    int r0, r1, r2, r3, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    if (!((unsigned)r4 >= (unsigned)0x2710)) {
        r1 = LD32(r14);
        ST16(48 + r1, r4);
    }
    r2 = LD32(r14);
    r1 = LD16(48 + r2);
    r5 = LD32(0x060D7B3C);
    r5 = LD16(48 + r5);
    r0 = LD8(r2 + 6);
    r5 = ((r5 & 0xFFFF) + (r1 & 0xFFFF)) + (r0 & 255);
    r0 = LD16(r2 + 22);
    SETSP((sp - 8));
    SETPR(0x060165A8);
    r0 = GCALL2(0x06068ACC, (r0 & 0xFFFF), r5);
    r3 = LD32(0x060D7B3C);
    ST16(62 + r3, 0x100);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 62;
}

int f060165B8(int r4)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060165BE);
    r0 = GCALL1(0x06016574, r4);
    r2 = LD32(0x060D7B3C);
    ST16(62 + r2, 0);
    SETPR(LD32((sp - 4)));
    r2 = LD32(0x060D7768);
    ST16(54 + r2, 1);
    return 54;
}

int f060165D6(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r2 = LD32(0x060D7768);
    r3 = LD16(46 + r2);
    if (((r3 & 0xFFFF) & 0x800) == 0) {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x060165B8, 6);
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x060165EC);
        r0 = GCALL1(0x060165B8, 28);
        r4 = LD32(0x060D7768);
        r0 = LD8(r4 + 6);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x06016776, (r0 & 255));
        return r0;
    }
}

void f06016776(int n)
{
    gaddr cur = LD32(0x060D7768);
    gaddr mover = LD32(MOVER_PTR);

    if (LDU16(cur + 46) & 0x800)
        ST16(mover + 36, LD16(0x060B45D8 + (signed char)(LD8(REC(LDU16(cur + 36)) + 53) * 10) + n * 2));
    else
        ST16(mover + 36, 0);
}

int f060167DE(void)
{
    gaddr t = LD32(CURRENT);

    if (!LD16(t + 36))
        return 0;
    return LD16(0x060B45F6 + LDU16(REC(LDU16(t + 36)) + 52) * 2);
}

int f06016812(void)
{
    int a = LDU16(0x060C062C);
    int b = LD16(LD32(0x060D7B3C) + 46);

    GCALL2(0x06014F68, LDU8(0x060C064A + a), b & 255);
    return GJUMP0(0x0601BC7E);
}

void f06016836(void)
{
    gaddr rec = REC(0);
    int i = 0;

    ST32(CURRENT, rec);
    while (i < (unsigned char)LD8(BOMBER_COUNT)) {
        rec = LD32(CURRENT);
        if (!(LD8(rec + 4) & 128)) {
            ST32(MOVER_PTR, OBJ(LDU16(rec + 22)));
            ST16(0x060C062C, i);
            GCALL0(0x06016812);
        }
        i++;
        rec = LD32(CURRENT) + 124;
        POLL();
        ST32(CURRENT, rec);
    }
}

void f0601689A(int a, int b, int c)
{
    int first = LDU16(LD32(MOVER_PTR) + 46) & 255;

    GCALL5(0x060090C2, first, first + 15, a, b, c);
    GJUMP3(0x0601BC9E, a, b, c);
}

/* Flashes on the ticks where bit `period` of the countdown is clear, and restores on the others. */
static void flash(int ticks, int limit, int a, int b, int c)
{
    int period = ticks >= limit ? 4 : 8;

    if (!(ticks & (period - 1))) {
        if (!(ticks & period))
            GCALL3(0x0601689A, a, b, c);
        else
            GCALL0(0x06016812);
    }
}

void f06016908(void)
{
    gaddr t = LD32(CURRENT);
    int busy = 0;
    int n;

    if (LD16(t + 68)) {
        n = LDU16(t + 68);
        if (n >= 90) {
            if (n < 0x186)
                GCALL3(0x0601689A, 0x81C0, 0x81C0, 64);
            else
                GCALL0(0x06016812);
        } else {
            flash(n, 30, 0x81C0, 0x81C0, 64);
        }
        busy = 1;
    }
    t = LD32(CURRENT);
    if (LD16(t + 84)) {
        if (!busy)
            flash(LDU16(t + 84), 120, 0x81C0, 64, 64);
        t = LD32(CURRENT);
        ST16(t + 84, LD16(t + 84) - 1);
        if (!LD16(t + 84)) {
            ST16(t + 70, 0);
            ST16(t + 46, LD16(t + 46) & 0xFBFF);
            GCALL0(0x06016812);
        }
        busy |= 2;
    }
    t = LD32(CURRENT);
    if (LD16(t + 72)) {
        if (!busy)
            flash(LDU16(t + 72), 120, 0x81C0, 64, 64);
        t = LD32(CURRENT);
        if (!(LDU16(t + 46) & 0x32D) || LDU16(t + 72) != 1)
            ST16(t + 72, LD16(t + 72) - 1);
        t = LD32(CURRENT);
        if (!LD16(t + 72)) {
            ST16(t + 70, 0);
            GCALL0(0x06016812);
        }
        busy |= 4;
    }
    t = LD32(CURRENT);
    if (LD16(t + 38)) {
        if (!busy)
            flash(LDU16(t + 38), 120, 0x81C0, 0x81C0, 0x81C0);
        t = LD32(CURRENT);
        ST16(t + 38, LD16(t + 38) - 1);
        if (!LD16(t + 38)) {
            ST8(t + 4, LD8(t + 4) & 223);
            GCALL0(0x06016812);
        }
        t = LD32(CURRENT);
        busy |= 8;
        ST8(t + 4, LD8(t + 4) & 175);
    }
    t = LD32(CURRENT);
    if (LD16(t + 44)) {
        if (!busy)
            flash(LDU16(t + 44), 120, 0x8040, 0x8040, 0x8040);
        t = LD32(CURRENT);
        ST16(t + 44, LD16(t + 44) - 1);
        if (!LD16(t + 44)) {
            ST16(t + 42, 0);
            ST16(t + 44, 0);
            GCALL0(0x06016812);
        }
    }
}

void f06016BA0(int pad)
{
    int cursor = LD32(0x060D7B3C);

    if (pad & 0x8000) {
        ST16(cursor + 16, LD16(cursor + 16) + 1);
        ST16(LD32(0x060D7768) + 50, 1);
        ST16(LD32(0x060D7768) + 16, 0x3000);
    } else if (pad & 0x2000) {
        ST16(cursor + 18, LD16(cursor + 18) + 1);
        ST16(LD32(0x060D7768) + 50, 2);
        ST16(LD32(0x060D7768) + 16, 0xC000);
    } else if (pad & 0x4000) {
        ST16(cursor + 16, LD16(cursor + 16) - 1);
        ST16(LD32(0x060D7768) + 50, 3);
        ST16(LD32(0x060D7768) + 16, 0x3000);
    } else if (pad & 0x1000) {
        ST16(cursor + 18, LD16(cursor + 18) - 1);
        ST16(LD32(0x060D7768) + 50, 4);
        ST16(LD32(0x060D7768) + 16, 0xC000);
    }
    if (LD16(0x060D82CA) == 0 && !(LD8(LD32(0x060D7768) + 4) & 128))
        GJUMP0(0x0600D1A6);
}

void f06016C50(int pad)
{
    int rec = LD32(CURRENT);

    if (pad & 0x8000)
        ST8(rec + 6, 1);
    else if (pad & 0x2000)
        ST8(rec + 6, 2);
    else if (pad & 0x4000)
        ST8(rec + 6, 3);
    else if (pad & 0x1000)
        ST8(rec + 6, 4);
}

int f06016C84(unsigned short pad)
{
    return ((pad & 0x5000) << 1) | ((pad & 0xA000) >> 1) | (pad & 0xFFF);
}

void f06016C9C(unsigned short value)
{
    ST16(0x060C0684, (LDU16(0x060C0684) & 0x0FFF) | (value & 0xF000));
}

int f06016CB0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    r13 = 0x060C0684;
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r2 = LD16(46 + r3);
    if (((r2 & 0xFFFF) & 0x2000) == 0) {
        r12 = LD16(0x060C062C);
        r12 = LD16(0x26006096 + ((r12 & 0xFFFF) << 1));
    } else {
        r12 = 0;
    }
    ST16(r13, r12);
    r0 = LD32(r14);
    r0 = LD16(r0 + 42);
    if (!(((r0 & 0xFFFF) & 128) == 0)) {
        r0 = LD32(r14);
        r0 = LD8(r0 + 4);
        if (((r0 & 255) & 2) == 0) {
            r4 = LD16(r13);
            SETSP((sp - 20));
            r0 = GCALL1(0x06016C84, r4);
            SETSP((sp - 20));
            r0 = GCALL1(0x06016C9C, (r0 & 0xFFFF));
        }
    }
    r3 = LD32(r14);
    r2 = LD16(42 + r3);
    if (!(((r2 & 0xFFFF) & 0x100) == 0)) {
        r2 = LD16(r13);
        if (((r2 & 0xFFFF) & 0xF000) == 0) {
            r4 = LD32(r14);
            r4 = LD16(50 + r4);
            r4 = LD16(0x060B4800 + ((r4 & 0xFFFF) << 1));
            SETSP((sp - 20));
            r0 = GCALL1(0x06016C9C, (r4 & 0xFFFF));
        }
    }
    r0 = LD32(r14);
    r0 = LD16(r0 + 46);
    r0 = r0 & 0xFFFF;
    if ((r0 & 16) == 0) {
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD32(r14);
        r0 = LD16(r0 + 56);
        if ((r0 & 0xFFFF) == 1) {
            SETMACL(LD32((sp - 20)));
            SETPR(LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x06016E28);
            return r0;
        } else {
            r4 = LD32(r14);
            r0 = LD8(r4 + 6);
            r4 = LD16(0x060B4800 + ((r0 & 255) << 1));
            SETSP((sp - 20));
            r0 = GCALL1(0x06016C9C, (r4 & 0xFFFF));
            r4 = 124;
            r2 = LD32(r14);
            r5 = 0x060D5F30;
            r3 = LD16(36 + r2);
            r1 = LD16(52 + (((r3 & 0xFFFF) * 124) + 0x060D5F30));
            if (!((r1 & r1) == 0)) {
                r2 = LD32(r14);
                r1 = LD16(56 + r2);
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r14);
                    r3 = LD16(56 + r1);
                    ST16(56 + r1, (r3 - 1));
                } else {
                    r2 = LD32(r14);
                    r0 = LD8(r2 + 6);
                    r2 = LD16(((r0 & 255) << 1) + 0x060B480A);
                    if (!(((r12 & 0xFFFF) & (r2 & 0xFFFF)) == 0)) {
                        r2 = LD32(r14);
                        ST16(56 + r2, 30);
                    }
                }
            }
            r0 = LD32(r14);
            r0 = LD16(r0 + 36);
            r0 = LD16((((r0 & 0xFFFF) * r4) + r5) + 52);
            r0 = r0 & 0xFFFF;
            if (r0 == 2) {
                r0 = LD32(r14);
                r3 = LD16(r0 + 56);
                if ((r3 & r3) == 0) {
                    r2 = LD16(r13);
                    ST16(r13, (r2 | r12));
                }
            }
            SETMACL(LD32((sp - 20)));
            SETPR(LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        }
    }
}

int f06016E28(void)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r2 = LD16(46 + r3);
    if (((r2 & 0xFFFF) & 0x810) == 0x810) {
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06016E44);
        r0 = GCALL0(0x0601CEEA);
    }
    r3 = LD32(r14);
    r1 = LD16(46 + r3);
    ST16(46 + r3, (r1 & 0xFFEF));
    r3 = LD32(r14);
    ST16(56 + r3, 0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 56;
}

int f06016E5E(int pad)
{
    if (pad) {
        GCALL1(0x06016BA0, pad);
        if (!LD16(0x060C08F6))
            GCALL1(0x06016C50, pad);
    }
    return pad;
}

int f06016E80(int mask, int other)
{
    int hit = LDU16(0x060C08F4) & mask;

    if (hit) {
        GCALL1(0x06016BA0, other);
        GCALL1(0x06016BA0, hit);
        if (!LD16(0x060C08F6))
            GCALL1(0x06016C50, other);
    }
    return hit;
}

int f06017336(void)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x0601FFDA);
    if (!((r0 & r0) == 0)) {
        r3 = LD32(0x060D7768);
        r1 = LD16(46 + r3);
        ST16(46 + r3, (r1 | 1));
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x06017356);
        r0 = GCALL1(0x06016574, 15);
        r2 = LD32(0x060D7768);
        ST32(104 + r2, 0x06017398);
        r0 = 108;
        r2 = LD32(0x060D7768);
        ST32(108 + r2, 0x060143D8);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06017398(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r0 = 60;
    r2 = LD32(0x060D7B3C);
    r3 = LD16(60 + r2);
    if (!((r3 & 0xFFFF) == 0xFF00)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r1 = LD32(0x060D7768);
        r0 = LD16(r1 + 46);
        ST16((46 + r1), ((r0 & 0xFFF8) | 2));
        SETSP((sp - 4));
        SETPR(0x060173C2);
        r0 = GCALL1(0x060165B8, 19);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06015156);
        return r0;
    }
}

void f060173CE(void)
{
    gaddr cur;

    GCALL0(0x06020276);
    cur = LD32(CURRENT);
    ST16(cur + 46, (LD16(cur + 46) & 0xFFF8) | 4);
    ST32(LD32(CURRENT) + 104, 0x060143D8);
    ST32(LD32(CURRENT) + 108, 0x06017402);
    GJUMP1(0x0600996A, 0x30);
}

int f0601741C(void)
{
    FRAME(sp, 64);
    gaddr cur = LD32(CURRENT);
    int who;

    if ((LDU8(cur + 4) & 192) || (LDU16(cur + 46) & 0x33D))
        who = 0;
    else
        who = GCALL1(0x060174EC, sp - 64);
    if (who) {
        who = LD32(sp - 64 + GCALL1(0x0600A0EC, who) * 4);
        if (who) {
            gaddr rec = REC(who - 1);
            gaddr obj = OBJ(LDU16(rec + 22));

            GCALL3(0x0601768E, LDU16(0x060C062C), LD16(obj + 16), LD16(obj + 18));
            GCALL3(0x0601768E, who - 1, LD16(LD32(MOVER_PTR) + 16), LD16(LD32(MOVER_PTR) + 18));
            ST16(rec + 42, 64);
            ST16(rec + 44, 0x258);
        }
    }
    return who;
}

int f060174EC(gaddr list)
{
    int n = 0;
    int i;
    int rec;

    for (i = 0; i < (unsigned char)LD8(BOMBER_COUNT); i++) {
        ST32(list + i * 4, 0);
        POLL();
    }
    for (i = 0; i < (unsigned char)LD8(BOMBER_COUNT); i++) {
        rec = (OBJECTS + 0x30) + i * 124;
        if (i != LDU16(0x060C062C) && !(LD8(rec + 4) & 192) && !(LDU16(rec + 46) & 0x33D)) {
            ST32(list + n * 4, i + 1);
            n++;
        }
        POLL();
    }
    return n;
}

void f0601755E(unsigned int amount)
{
    gaddr t = LD32(CURRENT);
    unsigned int have;
    int taken;

    if (!LD16(t + 66) || !amount)
        return;
    t = LD32(CURRENT);
    have = LDU16(t + 66);
    taken = GCALL3(0x0600A1FC, (LD8(0x060C062D) * 10 & 255) + 0x060C06FC, LDU16(LD32(CURRENT) + 22), have > amount ? amount : have);
    ST16(t + 66, LD16(t + 66) - taken);
    GJUMP0(0x06015CD2);
}

int f060175F2(void)
{
    gaddr cur = LD32(CURRENT);
    int flags;

    if (LD16(cur + 66) != 0) {
        GCALL1(0x0601755E, 4);
    } else if (!(LDU16(cur + 42) & 64)) {
        ST32(cur + 108, 0x06017648);
    } else {
        ST16(cur + 46, LD16(cur + 46) & 0xFFDF);
        ST16(LD32(CURRENT) + 44, 1);
        GCALL0(0x06015156);
        GCALL0(0x06015D16);
    }
    cur = LD32(CURRENT);
    flags = LD8(cur + 4) & 175;
    ST8(cur + 4, flags);
    return flags;
}

int f06017648(void)
{
    gaddr cur = LD32(CURRENT);

    ST16(cur + 46, LD16(cur + 46) & 0xFFDF);
    ST16(cur + 90, LD16(cur + 90) << 8);
    ST16(cur + 90, LD16(cur + 90) | (LD16(0x060EE8B0 + LDU16(cur + 20) * 2) & 255));
    ST16(cur + 66, 0);
    GCALL0(0x06015D16);
    return GJUMP0(0x06015156);
}

void f0601768E(int bomber, int b, int c)
{
    gaddr rec = REC(bomber);
    gaddr o = OBJ(LDU16(rec + 22));
    gaddr cell;

    ST16(rec + 66, GCALL5(0x0600A138, 0x060C06FC + ((bomber * 10) & 255), LD16(o + 16), LD16(o + 18), b, c));
    cell = 0x060EE8B0 + LDU16(rec + 20) * 2;
    if ((unsigned int)bomber < LDU8(BOMBER_COUNT)) {
        ST16(cell, LD16(cell) & 0xEFFF);
        ST16(rec + 46, LD16(rec + 46) | 32);
        ST32(rec + 100, 0x060143D8);
        ST32(rec + 104, 0x060143D8);
        ST32(rec + 108, 0x060175F2);
    } else {
        ST16(cell, LD16(cell) & 0xDFFF);
    }
    ST8(rec + 4, LD8(rec + 4) & 175);
}

int f06017784(int r4, int r5)
{
    int r0, r2, r3, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32(sp - 16, r4);
    ST32(sp - 12, r5);
    SETSP((sp - 16));
    r0 = GCALL0(0x060262BC);
    if ((r0 & r0) == 0) {
        SETSP((sp - 16));
        r0 = GCALL0(0x06017648);
        r4 = LD32(sp - 12);
        SETSP((sp - 16));
        r0 = GCALL1(0x060144F4, r4);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    } else {
        r6 = LD16(0x060D7E8A);
        r5 = LD16(0x060D7E88);
        r4 = LD16(0x060C062C);
        SETSP((sp - 16));
        r0 = GCALL3(0x0601768E, (r4 & 0xFFFF), r5, r6);
        r2 = LD32(0x060D7768);
        ST8(r2 + 6, 2);
        SETSP((sp - 16));
        SETPR(0x060177B8);
        r0 = GCALL1(0x060165B8, 0x2710);
        r4 = LD32(0x060D7768);
        r0 = LD8(r4 + 6);
        SETSP((sp - 16));
        r0 = GCALL1(0x06016776, (r0 & 255));
        SETSP((sp - 16));
        r0 = GCALL0(0x06016812);
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606AAC8, r4, 3);
        r3 = LD32(0x060D7B3C);
        ST16(70 + r3, 0x100);
        ST16(68 + r3, 0x100);
        r4 = LD32(sp - 16);
        SETSP((sp - 16));
        r0 = GCALL1(0x060144F4, r4);
        SETSP((sp - 16));
        SETPR(0x060177EE);
        r0 = GCALL0(0x0601D72A);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 1;
    }
}

int f06017890(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    SETSP((sp - 20));
    SETPR(0x060178A2);
    r0 = GCALL2(0x06017784, 0x0601793E, 0x0601780E);
    if ((r0 & r0) == 0) {
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r1 = LD16(66 + r3);
        ST16(54 + r3, ((int)((unsigned)(r1 & 0xFFFF) >> 1)));
        r8 = LD32(0x060D7768);
        SETSP((sp - 20));
        r0 = GCALL1(0x060691DA, 6);
        ST16((r8 + 60), r0);
        if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
            r14 = LD32(r13);
            r2 = LD16(60 + r14);
            r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(44 + r14, 1);
            r4 = LD32(r13);
            r5 = LD32(r13);
            r5 = LD16(60 + r5);
            r0 = LD16(r4 + 22);
            SETSP((sp - 20));
            r0 = GCALL2(0x0600A3D8, (r0 & 0xFFFF), (r5 & 0xFFFF));
            r4 = LD32(r13);
            r4 = LD16(60 + r4);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x06017902);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 90);
            ST16(46 + r14, 0x3B0);
            SETSP((sp - 20));
            r0 = GCALL2(0x0606AAC8, r14, 3);
            SETSP((sp - 20));
            r0 = GCALL2(0x0606950C, r14, 3);
            ST16(70 + r14, 0);
            ST16(68 + r14, 0);
        }
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x0600996A, 253);
        return r0;
    }
}

int f0601793E(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r13 = 0x060D7768;
    r14 = 0x060D7B3C;
    r4 = LD32(0x060D7B3C);
    r0 = LD16(70 + r4);
    if ((r0 & r0) == 0) {
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x060179D2);
        r0 = GCALL1(0x060164E0, 2);
        r2 = LD32(r14);
        ST16(70 + r2, 0x100);
        ST16(68 + r2, 0x100);
        r3 = LD32(r14);
        ST16(36 + r3, 0);
        r3 = LD32(r14);
        ST16(38 + r3, 6);
        r4 = LD32(r14);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606950C, r4, 3);
        r4 = LD32(r13);
        r0 = LD16(r4 + 22);
        SETSP((sp - 16));
        r0 = GCALL2(0x06069462, r0, 4);
        r4 = LD32(r13);
        r4 = LD16(58 + r4);
        SETSP((sp - 16));
        r0 = GCALL1(0x060265B4, ((int)((unsigned)(r4 & 0xFFFF) >> 8)));
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x060144F4, 0x06017A2A);
        return r0;
    } else {
        r3 = LD16(70 + r4);
        ST16(70 + r4, (r3 - 16));
        r4 = LD32(r13);
        r0 = LD16(60 + r4);
        if (!((r0 & r0) == 0)) {
            r2 = LD16(60 + r4);
            r3 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            r2 = LD16(68 + r3);
            ST16(68 + r3, (r2 + 16));
            r3 = LD32(r13);
            r3 = LD16(60 + r3);
            r0 = 70;
            r5 = 0x060C381C + (((r3 & 0xFFFF) * 84) & 0xFFFF);
            r3 = LD16(70 + r5);
            ST16(70 + r5, (r3 + 16));
        }
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f06017A2A(void)
{
    gaddr cur = LD32(CURRENT);
    int step;

    if (LD32(cur + 108) != 0x060175F2) {
        GCALL1(0x0602658A, LDU16(cur + 58) & 255);
        GCALL2(0x0606950C, LD32(MOVER_PTR), 0);
        ST16(LD32(MOVER_PTR) + 68, 0x100);
        ST16(LD32(MOVER_PTR) + 70, 0);
        return GJUMP1(0x060144F4, 0x06017B30);
    }
    GCALL0(0x060175F2);
    GCALL2(0x0600A3D8, LDU16(LD32(CURRENT) + 22), LDU16(LD32(CURRENT) + 60));
    GCALL2(0x06069462, LD16(LD32(CURRENT) + 22), 4);
    cur = LD32(CURRENT);
    step = (unsigned int)LD16(cur + 66) < (unsigned int)LD16(cur + 54) ? 8 : -8;
    ST16(LD32(MOVER_PTR) + 68, LD16(LD32(MOVER_PTR) + 68) + step);
    ST16(OBJ(LDU16(LD32(CURRENT) + 60)) + 68, LD16(LD32(MOVER_PTR) + 68));
    ST16(LD32(MOVER_PTR) + 70, LD16(LD32(MOVER_PTR) + 70) + step);
    ST16(OBJ(LDU16(LD32(CURRENT) + 60)) + 70, LD16(LD32(MOVER_PTR) + 70));
    return 70;
}

int f06017BC0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06017BCA);
    r0 = GCALL2(0x06017784, 0x06017BD2, 0x0601780E);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 253);
    return r0;
}

int f06017BD2(void)
{
    gaddr mover = LD32(MOVER_PTR);

    if (LDU16(mover + 68) == 0) {
        GCALL1(0x060265B4, LDU16(LD32(CURRENT) + 58) >> 8);
        return GJUMP1(0x060144F4, 0x06017C16);
    }
    ST16(mover + 68, LD16(mover + 68) - 32);
    ST16(LD32(MOVER_PTR) + 70, LD16(LD32(MOVER_PTR) + 70) + 32);
    return 70;
}

int f06017C16(void)
{
    gaddr cur = LD32(CURRENT);

    if (LD32(cur + 108) == 0x060175F2)
        return GJUMP0(0x060175F2);
    GCALL1(0x0602658A, 255 & LDU16(cur + 58));
    return GJUMP1(0x060144F4, 0x06017C84);
}

int f06017CD8(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06017CE2);
    r0 = GCALL2(0x06017784, 0x06017C16, 0x0601780E);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 253);
    return r0;
}

int f06017D08(void)
{
    int r0, r1, r4, r8, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 16));
    r0 = GCALL0(0x06017E46);
    r8 = LD32(0x060D7768);
    r4 = LD16(0x060DF984);
    SETSP((sp - 16));
    r0 = GCALL1(0x060691DA, r4);
    ST16((r8 + 60), r0);
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r14 = LD32(0x060D7768);
        r1 = LD16(60 + r14);
        r14 = (((r1 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(44 + r14, 0);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606AAC8, r14, 3);
        ST16(72 + r14, 0);
        ST16(74 + r14, 4);
        r4 = LD16(0x060C1AAA);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x06017D64);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 33);
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 46);
        r0 = r0 & 255;
        ST16((46 + r14), r0);
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06017DC0(void)
{
    gaddr t = LD32(CURRENT);
    gaddr o;
    int own;
    short v;

    if (!LD16(t + 60))
        return;
    GCALL2(0x0600A3D8, LDU16(t + 22), LDU16(t + 60));
    o = OBJ(LDU16(LD32(CURRENT) + 60));
    own = LD16(LD32(MOVER_PTR) + 38);
    v = own - (LDU16(0x060C062C) >= (unsigned char)LD8(0x060C063D) ? 0 : (short)GCALL0(0x060167DE));
    if (v <= -128)
        v = -128;
    if (v >= 0)
        v = 0;
    ST16(o + 70, v + 0x100);
    ST16(o + 68, v + 0x100);
}

void f06017E46(void)
{
    gaddr t = LD32(CURRENT);

    if (LD16(t + 60)) {
        GCALL1(0x060692DC, LDU16(t + 60));
        ST16(LD32(CURRENT) + 60, 0);
    }
}

int f06017E70(int step, int dir, int edge)
{
    int obj = LDU16(LD32(CURRENT) + 22);
    unsigned int x, y, next, bound;

    GCALL1(0x0600CA6A, obj);
    x = LDU16(0x060D7EB4);
    y = LDU16(0x060D7EB6);
    switch (dir) {
    case 1:
        bound = LDU16(0x060D7E80);
        next = x + step;
        if (next < bound - 2 || edge == 2 || (edge && next < bound + 1))
            ST16(0x060D7EB4, LD16(0x060D7EB4) + step);
        else if (!edge)
            obj = 0;
        else
            ST16(0x060D7EB4, bound + 1);
        break;
    case 2:
        bound = LDU16(0x060D7E82);
        next = y + step;
        if (next < bound - 1 || edge == 2 || (edge && next < bound + 2))
            ST16(0x060D7EB6, LD16(0x060D7EB6) + step);
        else if (!edge)
            obj = 0;
        else
            ST16(0x060D7EB6, bound + 2);
        break;
    case 3:
        bound = LDU16(0x060D7E7C);
        next = x - step;
        if (next >= bound + 2 || edge == 2 || (edge && next >= bound))
            ST16(0x060D7EB4, LD16(0x060D7EB4) - step);
        else if (!edge)
            obj = 0;
        else
            ST16(0x060D7EB4, bound - 1);
        break;
    case 4:
        bound = LDU16(0x060D7E7E);
        next = y - step;
        if (next >= bound + 1 || edge == 2 || (edge && next >= bound - 1))
            ST16(0x060D7EB6, LD16(0x060D7EB6) - step);
        else if (!edge)
            obj = 0;
        else
            ST16(0x060D7EB6, bound - 2);
        break;
    }
    GCALL2(0x0600CA32, LDU16(0x060D7EB4), LDU16(0x060D7EB6));
    GCALL2(0x0600C950, LDU16(0x060D7EB4), LDU16(0x060D7EB6));
    return obj;
}

int f06017FF6(void)
{
    gaddr slide = 0x060C07B0 + (short)(LD16(0x060C062C) * 18);
    gaddr mover = LD32(MOVER_PTR);
    gaddr cur;

    if (GET(Slide, slide, count) > 0) {
        SET(Slide, slide, pos, GET(Slide, slide, pos) + GET(Slide, slide, rate));
        ST16(mover + 38, DIVS(GET(Slide, slide, pos), 100));
        SET(Slide, slide, rate, GET(Slide, slide, rate) + GET(Slide, slide, accel));
        if (GET(Slide, slide, rate) >= 0 && LD16(mover + 38) > GET(Slide, slide, limit)) {
            SET(Slide, slide, count, 0);
            ST16(mover + 38, GET(Slide, slide, limit));
        }
        SET(Slide, slide, count, GET(Slide, slide, count) - 1);
    }
    if (GET(Slide, slide, count) <= 0) {
        SET(Slide, slide, count, 0);
        ST16(mover + 38, GET(Slide, slide, limit));
    }
    cur = LD32(0x060D7768);
    ST8(cur + 4, LD8(cur + 4) & 175);
    GCALL0(0x060153BC);
    GCALL0(0x060157E4);
    return GET(Slide, slide, count);
}

int f06018090(void)
{
    int r0, r1, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = LD16(0x060C062C);
    r14 = ((short)((((r14 << 2) << 1) + r14) << 1)) + 0x060C07B0;
    r0 = LD16(r14 + 12);
    r1 = r0;
    r0 = LD16(r14 + 10);
    ST16(r14 + 10, (r0 + r1));
    r0 = LD16(r14 + 10);
    ST16(r14 + 10, (r0 & 255));
    SETSP((sp - 8));
    r0 = GCALL1(0x0601755E, ((int)((unsigned)(r0 & 0xFFFF) >> 8)));
    r0 = LD8(r14 + 15);
    if (!((r0 & 255) == 2)) {
        SETSP((sp - 8));
        r0 = GCALL0(0x0600D1A6);
    }
    SETSP((sp - 8));
    r0 = GCALL0(0x06017FF6);
    if (!((r0 & r0) == 0)) {
        SETSP((sp - 8));
        r0 = GCALL0(0x06017DC0);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 1;
    } else {
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        SETSP((sp - 8));
        r0 = GCALL1(0x0601755E, (r4 & 0xFFFF));
        SETSP((sp - 8));
        SETPR(0x060180E4);
        r0 = GCALL0(0x060181EA);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

void f06018138(int x)
{
    int h = LD16(0x060C062C);
    gaddr rec = 0x060C07B0 + (short)(h * 18);
    unsigned int n = DIVS(x + 8, 16);
    int w;

    if (n > 8)
        n = 8;
    w = LDU16(0x060B45FC + n * 2);
    ST16(rec + 2, -(w / 2));
    ST8(rec + 14, 8);
    ST16(rec, DIVS(w, 8) + 1);
    ST16(rec + 12, DIVS(LDU16(LD32(CURRENT) + 66) << 8, LD16(rec)) + 1);
    ST16(rec + 10, 0);
    ST16(rec + 4, LD16(LD32(MOVER_PTR) + 38));
    ST16(rec + 6, 100 * LD16(LD32(MOVER_PTR) + 38));
    if (LDU16(0x060C062C) < LDU8(BOMBER_COUNT))
        ST16(LD32(CURRENT) + 46, LD16(LD32(CURRENT) + 46) | 8);
}

int f060181EA(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = LD16(0x060C062C);
    r2 = LD32(0x060D7768);
    r1 = LD16(46 + r2);
    r14 = ((short)((((r14 << 2) << 1) + r14) << 1)) + 0x060C07B0;
    ST16(46 + r2, (r1 & 0xBFD7));
    SETSP((sp - 8));
    r0 = GCALL0(0x06017E46);
    SETSP((sp - 8));
    r0 = GCALL0(0x06015D16);
    SETSP((sp - 8));
    r0 = GCALL0(0x06015156);
    r0 = LD16(r14 + 8);
    if (!((r0 & r0) == 0)) {
        r0 = LD16(r14 + 8);
        SETSP((sp - 8));
        SETPR(0x0601822E);
        r0 = GCALL1(0x060165B8, (r0 & 0xFFFF));
    }
    r0 = 0x060C063D;
    r2 = LD16(0x060C062C);
    r1 = LD8(0x060C063D);
    if ((r2 & 0xFFFF) >= (r1 & 255)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 8)));
        r4 = LD32(0x060D7768);
        r0 = LD8(r4 + 6);
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x06016776, (r0 & 255));
        return r0;
    }
}

int f06018254(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32(sp - 20, r4);
    ST32(sp - 24, r5);
    ST32(sp - 28, r6);
    ST32(sp - 16, r7);
    r14 = LD16(0x060C062C);
    r0 = LD32(sp - 24);
    r14 = ((short)((((r14 << 2) << 1) + r14) << 1)) + 0x060C07B0;
    if (!((r0 & r0) == 0)) {
        r4 = LD32(sp - 24);
        SETSP((sp - 28));
        r0 = GCALL1(0x06018138, r4);
    } else {
        r13 = LD32(0x060D7768);
        r0 = LD16(66 + r13);
        if ((r0 & r0) == 0) {
            r4 = 48;
        } else {
            r4 = LD16(66 + r13);
            r4 = r4 & 0xFFFF;
        }
        SETSP((sp - 28));
        r0 = GCALL1(0x06018138, r4);
    }
    r2 = LD32(sp - 28);
    if (!((r2 & r2) == 0)) {
        r4 = LD32(sp - 28);
        SETR(14, r14);
        SETSP((sp - 28));
        SETPR(0x060182B0);
        r0 = GCALL1(0x06016574, r4);
    }
    r0 = LD16(sp - 14);
    ST16(r14 + 8, r0);
    r0 = LD32(sp);
    ST8(r14 + 15, r0);
    r3 = LD32(sp - 20);
    ST8(16 + r14, r3);
    SETSP((sp - 28));
    r0 = GCALL0(0x06015172);
    SETSP((sp - 28));
    SETPR(0x060182C6);
    r0 = GCALL0(0x06017D08);
    SETSP((sp - 28));
    r0 = GCALL0(0x06017DC0);
    r1 = LD32(0x060D7768);
    ST32(100 + r1, 0x06018090);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 100;
}

int f060182DE(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060D7768;
    ST32(sp - 20, r6);
    ST32(sp - 16, r7);
    r14 = r5;
    if ((r4 & r4) == 0) {
        r3 = LD32(r13);
        r0 = LD16(r3 + 20);
        r3 = (r0 & 0xFFFF) << 1;
        r1 = LD16(0x060EE8B0 + r3);
        ST16(0x060EE8B0 + r3, (r1 & 0xEFFF));
        r3 = LD32(r13);
        ST16(66 + r3, 0);
    } else {
        r6 = LD32(sp + 4);
        SETSP((sp - 20));
        r0 = GCALL3(0x06017E70, r4, r14, r6);
        r6 = LD16(0x060D7E8A);
        r5 = LD16(0x060D7E88);
        r4 = LD16(0x060C062C);
        SETSP((sp - 20));
        r0 = GCALL3(0x0601768E, (r4 & 0xFFFF), r5, r6);
    }
    r3 = LD32(r13);
    ST8(r3 + 6, r14);
    r3 = LD32(sp + 4);
    ST32((sp - 24), r3);
    r7 = LD32(sp);
    r6 = LD32(sp - 16);
    r5 = LD32(sp - 20);
    SETSP((sp - 24));
    SETPR(0x0601833A);
    r0 = GCALL4(0x06018254, r14, r5, r6, r7);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06018344(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 16, r4);
    ST32(sp - 28, r5);
    ST32(sp - 24, r6);
    ST32(sp - 20, r7);
    r6 = LD32(sp - 16);
    r6 = (((r6 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    ST32(sp - 12, r6);
    r0 = LD16(r6 + 18);
    r6 = r0;
    r5 = LD32(sp - 12);
    r0 = LD16(r5 + 16);
    r4 = LD16(0x060C062C);
    SETSP((sp - 28));
    r0 = GCALL3(0x0601768E, (r4 & 0xFFFF), r0, r6);
    r3 = LD32(sp);
    ST32((sp - 32), r3);
    r7 = LD32(sp - 20);
    r6 = LD32(sp - 24);
    r5 = LD32(sp - 28);
    r4 = LD16(0x060C062C);
    r4 = LD8(0x060D5F36 + ((r4 & 0xFFFF) * 124));
    SETSP((sp - 32));
    SETPR(0x06018392);
    r0 = GCALL4(0x06018254, (r4 & 255), r5, r6, r7);
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f060183F0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST32(sp - 24, r4);
    ST32(sp - 28, r5);
    ST32(sp - 20, r6);
    ST32(sp - 16, r7);
    r4 = LD16(0x060C062C);
    r1 = LD8(0x060C063D);
    if ((r4 & 0xFFFF) >= (r1 & 255)) {
        r0 = 0;
    } else {
        r14 = 0x060D7768;
        r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
        ST32(0x060D7768, r4);
        r0 = LD16(r4 + 22);
        ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
        SETR(14, 0x060D7768);
        SETSP((sp - 28));
        SETPR(0x06018436);
        r0 = GCALL0(0x06018D60);
        if ((r0 & r0) == 0) {
            r0 = 0;
        } else {
            r2 = LD32(sp - 28);
            if (!((r2 & r2) == 0)) {
                r3 = LD32(sp - 28);
            } else {
                r3 = LD32(0x060D7768);
                r0 = LD8(r3 + 6);
                r3 = r0 & 255;
            }
            ST32(sp - 28, r3);
            r2 = LD32(r14);
            r3 = LD16(46 + r2);
            if (!(((r3 & 0xFFFF) & 0x800) == 0)) {
                ST32(sp - 16, 0);
                ST32(sp - 20, 0);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x06018468);
                r0 = GCALL0(0x0601C83E);
            }
            r2 = LD32(sp);
            ST32((sp - 32), r2);
            r3 = LD32(sp - 16);
            ST32((sp - 36), r3);
            r7 = LD32(sp - 20);
            r5 = LD32(sp - 28);
            r4 = LD32(sp - 24);
            SETR(14, r14);
            SETSP((sp - 36));
            SETPR(0x0601847A);
            r0 = GCALL4(0x060182DE, r4, r5, 0, r7);
            r2 = LD32(r14);
            ST32(100 + r2, 0x0601857C);
            r0 = 1;
        }
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06018494(int r4, int r5, int r6)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32(sp - 8, r6);
    ST32((sp - 12), r6);
    SETSP((sp - 12));
    SETPR(0x060184A4);
    r0 = GCALL4(0x060183F0, r4, r5, 24, 6);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06018508(int r4, int r5, int r6)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32(sp - 12, r5);
    ST32(sp - 8, r6);
    SETSP((sp - 12));
    r0 = GCALL1(0x06018E1A, r4);
    r2 = LD8(0x060C063D);
    r5 = r0;
    if ((unsigned)r0 >= (unsigned)(r2 & 255)) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        ST16(0x060C062C, r5);
        r5 = LD32(sp - 8);
        r4 = LD32(sp - 12);
        SETSP((sp - 12));
        SETPR(0x0601852C);
        r0 = GCALL3(0x06018494, r4, r5, 1);
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 4)));
            return 0;
        } else {
            SETPR(LD32((sp - 4)));
            return 1;
        }
    }
}

int f06018542(int r4, int r5, int r6)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32(sp - 12, r5);
    ST32(sp - 8, r6);
    SETSP((sp - 12));
    r0 = GCALL1(0x06018EBC, r4);
    r2 = LD8(0x060C063D);
    r5 = r0;
    if ((unsigned)r0 >= (unsigned)(r2 & 255)) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        ST16(0x060C062C, r5);
        r5 = LD32(sp - 8);
        r4 = LD32(sp - 12);
        SETSP((sp - 12));
        SETPR(0x06018566);
        r0 = GCALL3(0x06018494, r4, r5, 1);
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 4)));
            return 0;
        } else {
            SETPR(LD32((sp - 4)));
            return 1;
        }
    }
}

int f0601857C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06018584);
    r0 = GCALL0(0x06018090);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD16(0x060C062C);
        r4 = LD32(0x060D7768);
        r14 = ((short)((((r14 << 2) << 1) + r14) << 1)) + 0x060C07B0;
        r3 = LD8(16 + r14);
        ST8(r4 + 6, r3);
        SETSP((sp - 8));
        r0 = GCALL1(0x0601BF94, (r3 & 255));
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x060185B8);
        r0 = GCALL1(0x060165B8, 0x2710);
        r4 = 0x060EC8B0;
        r3 = 0x060D7768;
        r0 = LD32(0x060D7768);
        r0 = LD16(r0 + 20);
        r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
        r0 = r0 & 0xFFFF;
        if (!((r0 & 7) == 0)) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r0 = LD8(r14 + 15);
            r0 = r0 & 255;
            if (!(r0 == 1)) {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                r0 = LD32(r3);
                r0 = LD16(r0 + 20);
                r1 = LD32(r3);
                r2 = LD16(((r0 & 0xFFFF) << 1) + r4);
                r0 = LD16(r1 + 18);
                r0 = r0 & 0xFFFF;
                if (((r2 & 0xFFFF) & r0) == 0) {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    ST32((sp - 12), 1);
                    r5 = LD8(16 + r14);
                    SETSP((sp - 12));
                    SETPR(0x060185FC);
                    r0 = GCALL4(0x060183F0, 1, (r5 & 255), 28, 6);
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP1(0x0600996A, 26);
                    return r0;
                }
            }
        }
    }
}

int f060186AC(void)
{
    int r0, r1, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060186B4);
    r0 = GCALL0(0x06018090);
    if ((r0 & r0) == 0) {
        r3 = LD32(0x060D7768);
        r1 = LD16(46 + r3);
        ST16(46 + r3, (r1 | 0x800));
        r4 = LD32(0x060D7768);
        r0 = LD8(r4 + 6);
        SETSP((sp - 8));
        r0 = GCALL1(0x06016776, (r0 & 255));
        r3 = LD32(0x060D7768);
        r0 = 46;
        r1 = LD16(46 + r3);
        ST16(46 + r3, (r1 | 0x8000));
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0601879C(void)
{
    int r0, r1, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), 0);
    ST32((sp - 12), 6);
    r5 = LD32(0x060D7768);
    r0 = LD8(r5 + 6);
    SETSP((sp - 12));
    SETPR(0x060187B6);
    r0 = GCALL4(0x060182DE, 0, (r0 & 255), 40, 24);
    SETPR(LD32((sp - 4)));
    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r4 = LD16(0x060C062C);
    r4 = ((short)((((r4 << 2) << 1) + r4) << 1)) + 0x060C07B0;
    ST16(r4 + 4, 0);
    ST16(r4, 100);
    r0 = LD32(0x060D7768);
    ST16((36 + r0), 0);
    SETSP((sp - 8));
    r0 = GCALL0(0x06015172);
    r3 = LD32(0x060D7768);
    ST32(100 + r3, 0x06018090);
    r3 = LD32(0x060D7768);
    r1 = LD16(46 + r3);
    ST16(46 + r3, (r1 & 0xF7FF));
    r4 = LD32(0x060D7768);
    r0 = LD8(r4 + 6);
    SETSP((sp - 8));
    r0 = GCALL1(0x06016776, (r0 & 255));
    r3 = LD32(0x060D7768);
    r1 = LD16(46 + r3);
    ST16(46 + r3, (r1 | 0x4000));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 46;
}

int f0601881E(int r4)
{
    int r0, r1, r2, r3, r5, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    SETSP((sp - 20));
    r0 = GCALL1(0x06018DD6, r4);
    r2 = LD8(0x060C063D);
    r5 = r0;
    if ((unsigned)r0 >= (unsigned)(r2 & 255)) {
        r0 = 0;
    } else {
        r14 = 0x060D7768;
        ST16(0x060C062C, r5);
        r5 = ((r5 & 0xFFFF) * 124) + 0x060D5F30;
        ST32(0x060D7768, r5);
        r0 = LD16(r5 + 22);
        ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
        SETR(14, 0x060D7768);
        SETSP((sp - 20));
        SETPR(0x06018862);
        r0 = GCALL0(0x06018D60);
        if ((r0 & r0) == 0) {
            r0 = 0;
        } else {
            r13 = 24;
            r3 = LD32(r14);
            r2 = LD16(46 + r3);
            r12 = 28;
            if (!(((r2 & 0xFFFF) & 0x800) == 0)) {
                r12 = 0;
                r13 = 0;
                SETR(12, 0);
                SETR(13, 0);
                SETR(14, r14);
                SETSP((sp - 20));
                SETPR(0x06018880);
                r0 = GCALL0(0x0601C83E);
            }
            ST32((sp - 24), 0);
            r4 = LD32(0x060D7E60);
            r0 = LD16(r4 + 8);
            SETR(14, r14);
            SETSP((sp - 24));
            SETPR(0x06018894);
            r0 = GCALL4(0x06018344, (r0 & 0xFFFF), 0, r13, r12);
            r3 = LD32(r14);
            r1 = LD16(46 + r3);
            ST16(46 + r3, (r1 | 0x200));
            r3 = LD32(r14);
            ST32(100 + r3, 0x060188FC);
            r0 = 1;
        }
    }
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060188FC(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06018902);
    r0 = GCALL0(0x06018090);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x0605F4A8);
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 22);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600D16A, (r0 & 0xFFFF));
        r3 = LD32(0x060D7768);
        ST16(58 + r3, 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0601893E);
        SETSP((sp - 4));
        SETPR(0x06018930);
        r0 = GCALL0(0x0601D72A);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x0600996A, 109);
        return r0;
    }
}

int f06018C72(void)
{
    int team = (unsigned char)LD8(0x060C029C) >= 9 ? 100 : 0;
    int found = 0;
    int i, p, mine;

    for (i = 0; i < (unsigned char)LD8(0x060C063D); i++) {
        p = (OBJECTS + 0x30) + i * 124;
        if (!(LD8(p + 4) & 128)) {
            ST8(0x060C063F, i);
            found++;
            if ((unsigned char)LD8(0x060C029C) < 9 || !(LD8(0x060C0682) & 1)) {
                team = 0;
            } else if (team) {
                mine = ((LD8(0x060C0640 + i) & 28) >> 2) + 1;
                if ((unsigned int)team > 6)
                    team = mine;
                else if (team != mine)
                    team = 0;
            }
        }
        POLL();
    }
    return (team << 16) + found;
}

void f06018D0C(void)
{
    if ((unsigned char)LD8(0x060C063E) < 9)
        ST8(0x060C063E, LD8(0x060C063E) + 1);
}

int f06018D60(void)
{
    int r0, r2, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060D7768);
    r0 = LD8(r4 + 4);
    if (!(((r0 & 255) & 144) == 0)) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        r2 = LD16(46 + r4);
        if (!(((r2 & 0xFFFF) & 0x33D) == 0)) {
            SETPR(LD32((sp - 4)));
            return 0;
        } else {
            r0 = LD16(46 + r4);
            if (!(((r0 & 0xFFFF) & 2) == 0)) {
                r2 = LD16(46 + r4);
                ST16(46 + r4, (r2 & 0xFFFD));
                SETSP((sp - 4));
                r0 = GCALL0(0x06020276);
                SETSP((sp - 4));
                SETPR(0x06018D9A);
                r0 = GCALL0(0x06017402);
            }
            SETPR(LD32((sp - 4)));
            return 1;
        }
    }
}

int f06018DD6(int pos)
{
    int i;

    for (i = 0; i < LDU8(BOMBER_COUNT); i++) {
        POLL();
        if (!(LDU8(REC(i) + 4) & 192) && !(LDU16(REC(i) + 46) & 0x33D) && LDU16(REC(i) + 20) == pos)
            return i;
    }
    return LDU8(BOMBER_COUNT);
}

int f06018E1A(int pos)
{
    int i;

    for (i = 0; i < LDU8(BOMBER_COUNT); i++) {
        POLL();
        if (!(LDU8(REC(i) + 4) & 192) && !(LDU16(REC(i) + 46) & 0x33D) && LDU16(REC(i) + 20) == pos) {
            int x = LDU16(REC(i) + 24) & 15;
            int y = LDU16(REC(i) + 28) & 15;

            if ((x >= 12 || x <= 4) && (y >= 12 || y <= 4))
                return i;
        }
    }
    return LDU8(BOMBER_COUNT);
}

int f06018EBC(int arg)
{
    int i;

    GCALL1(0x0600C90C, arg);
    for (i = 0; i < LDU8(BOMBER_COUNT); i++) {
        gaddr rec = REC(i);
        int x, y, px, py;

        POLL();
        if ((LDU8(rec + 4) & 192) || (LDU16(rec + 46) & 0x33D))
            continue;
        x = LDU16(rec + 24);
        px = LD16(0x060D7E88);
        if (x + 6 < px || x - 6 > px)
            continue;
        y = LDU16(rec + 28);
        py = LD16(0x060D7E8A);
        if (y + 6 >= py && y - 6 <= py)
            return i;
    }
    return LDU8(BOMBER_COUNT);
}

int f06018F54(int n)
{
    gaddr rec = REC((n + 1) & 1);

    if (LDU16(rec + 46) & 0x33D)
        return 0;
    GCALL1(0x0600CA6A, LDU16(rec + 22));
    ST16(0x060D7E88, LD16(OBJ(LDU16(rec + 22)) + 16));
    ST16(0x060D7E8A, LD16(OBJ(LDU16(rec + 22)) + 18));
    return 1;
}

int f06018FB2(int r4)
{
    int r0, r1, r3, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r5 = LD32(0x060D7768);
    r3 = LD16(46 + r5);
    if (!(((r3 & 0xFFFF) & 0x33F) == 0)) {
        r0 = LD8(r5 + 4);
        ST8(r5 + 4, (r0 & 239));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    } else {
        r0 = LD8(r5 + 4);
        if (!(((r0 & 255) & 32) == 0)) {
            r0 = LD8(r5 + 4);
            ST8(r5 + 4, (r0 & 239));
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        } else {
            r3 = LD16(46 + r5);
            if (((r3 & 0xFFFF) & 0x200) == 0) {
                ST32(100 + r5, 0x060154A4);
                r3 = LD32(r14);
                ST32(104 + r3, 0x060143D8);
                r3 = LD32(r14);
                ST32(108 + r3, 0x06019164);
                r3 = LD32(r14);
                ST16(82 + r3, r4);
                r3 = LD8(0x060C029C);
                if (!((r3 & 255) >= 9)) {
                    r0 = LD32(r14);
                    r0 = LD8(r0 + 4);
                    if (!(((r0 & 255) & 16) == 0)) {
                        SETSP((sp - 8));
                        r0 = GCALL1(0x0600996A, 42);
                    }
                } else {
                    SETR(14, r14);
                    SETSP((sp - 8));
                    SETPR(0x06019010);
                    r0 = GCALL1(0x0601A0E4, 1);
                }
            } else {
                r1 = LD16(82 + r5);
                if ((r1 & r1) == 0) {
                    ST32(100 + r5, 0x060154A4);
                    r3 = LD32(r14);
                    ST32(104 + r3, 0x060143D8);
                    r3 = LD32(r14);
                    ST32(108 + r3, 0x06019164);
                    r3 = LD32(r14);
                    ST16(82 + r3, r4);
                    r3 = LD8(0x060C029C);
                    if (!((r3 & 255) >= 9)) {
                        r0 = LD32(r14);
                        r0 = LD8(r0 + 4);
                        if (!(((r0 & 255) & 16) == 0)) {
                            SETSP((sp - 8));
                            r0 = GCALL1(0x0600996A, 42);
                        }
                    } else {
                        SETR(14, r14);
                        SETSP((sp - 8));
                        SETPR(0x06019010);
                        r0 = GCALL1(0x0601A0E4, 1);
                    }
                }
            }
            r3 = LD32(r14);
            r1 = LD16(46 + r3);
            ST16(46 + r3, (r1 & 0xFDFF));
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 1;
        }
    }
}

int f06019088(int r4)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    ST32(sp - 12, r4);
    SETR(14, 0x060D7768);
    SETSP((sp - 12));
    SETPR(0x06019096);
    r0 = GCALL0(0x06018D60);
    if ((r0 & r0) == 0) {
        r3 = LD32(r14);
        r0 = LD8(r3 + 4);
        ST8(r3 + 4, (r0 & 239));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    } else {
        r4 = 0x200;
        r3 = LD32(r14);
        r2 = LD16(46 + r3);
        if (((r2 & 0xFFFF) & 0x200) == 0) {
            r2 = LD32(r14);
            ST32(100 + r2, 0x060154A4);
            r2 = LD32(r14);
            ST32(104 + r2, 0x060143D8);
            r2 = LD32(r14);
            ST32(108 + r2, 0x06019358);
            r2 = LD32(r14);
            r3 = LD32(sp - 12);
            ST16(82 + r2, r3);
        } else {
            r3 = LD32(r14);
            r1 = LD16(82 + r3);
            if ((r1 & r1) == 0) {
                r2 = LD32(r14);
                ST32(100 + r2, 0x060154A4);
                r2 = LD32(r14);
                ST32(104 + r2, 0x060143D8);
                r2 = LD32(r14);
                ST32(108 + r2, 0x06019358);
                r2 = LD32(r14);
                r3 = LD32(sp - 12);
                ST16(82 + r2, r3);
            }
        }
        r3 = LD32(r14);
        r2 = LD16(46 + r3);
        ST16(46 + r3, (r2 | r4));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 1;
    }
}

int f06019164(void)
{
    int r0, r1, r2, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD32(0x060D7768);
    r1 = LD16(46 + r3);
    if (!(((r1 & 0xFFFF) & 0x800) == 0)) {
        SETSP((sp - 4));
        SETPR(0x06019186);
        r0 = GCALL1(0x0601BEA8, 33);
    } else {
        SETSP((sp - 4));
        SETPR(0x0601917C);
        r0 = GCALL1(0x060164E0, 24);
    }
    SETPR(LD32((sp - 4)));
    POLL();
    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x06015CD2);
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(82 + r4);
    if (!((r0 & r0) == 0)) {
        r2 = LD16(82 + r4);
        ST16(82 + r4, (r2 - 1));
    } else {
        SETSP((sp - 8));
        r0 = GCALL0(0x06015156);
        r2 = LD32(r14);
        r3 = LD16(46 + r2);
        if (!(((r3 & 0xFFFF) & 0x800) == 0)) {
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06019136);
            r0 = GCALL1(0x0601BEA8, 0x2710);
        } else {
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0601912A);
            r0 = GCALL1(0x060165B8, 0x2710);
        }
        r3 = LD32(r14);
        r1 = LD16(46 + r3);
        ST16(46 + r3, (r1 & 0xFDFF));
        r3 = LD32(r14);
        ST16(82 + r3, 0);
    }
    r3 = LD32(r14);
    r0 = LD8(r3 + 4);
    r0 = r0 & 239;
    ST8(r3 + 4, r0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0601917C(void)
{
    return GJUMP0(0x06019186);
}

int f060191B8(int r4, int r5)
{
    int r0, r2, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    SETPR(0x060191C0);
    r0 = GCALL2(0x06019290, r4, r5);
    r2 = LD8(0x060C063D);
    r6 = r0;
    if (!((unsigned)r0 >= (unsigned)(r2 & 255))) {
        ST32(0x060D5F9C + (r6 * 124), 0x06019164);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r6;
}

int f06019290(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r12 = 0x060C062C;
    ST32(sp - 40, r5);
    r9 = LD16(0x060C062C);
    r9 = r9 & 0xFFFF;
    r14 = 0x060D7768;
    r10 = LD32(0x060D7768);
    r13 = 0x060D7B3C;
    r8 = LD32(0x060D7B3C);
    SETSP((sp - 40));
    r0 = GCALL1(0x06018DD6, r4);
    r2 = LD8(0x060C063D);
    r11 = r0;
    if ((unsigned)r0 >= (unsigned)(r2 & 255)) {
        ST32(r13, r8);
        ST32(r14, r10);
        ST16(r12, r9);
        r0 = LD8(0x060C063D);
        r0 = r0 & 255;
    } else {
        ST16(r12, r11);
        r1 = ((r11 & 0xFFFF) * 124) + 0x060D5F30;
        ST32(r14, r1);
        r0 = LD16(r1 + 22);
        ST32(r13, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x060192E6);
        r0 = GCALL0(0x06018D60);
        if ((r0 & r0) == 0) {
            ST32(r13, r8);
            ST32(r14, r10);
            ST16(r12, r9);
            r0 = LD8(0x060C063D);
            r0 = r0 & 255;
        } else {
            r4 = 0x200;
            r3 = LD32(r14);
            r2 = LD16(46 + r3);
            if (((r2 & 0xFFFF) & 0x200) == 0) {
                r2 = LD32(r14);
                ST32(100 + r2, 0x060154A4);
                r2 = LD32(r14);
                ST32(104 + r2, 0x060143D8);
                r2 = LD32(r14);
                ST32(108 + r2, 0x06019358);
                r2 = LD32(r14);
                r3 = LD32(sp - 40);
                ST16(82 + r2, r3);
            } else {
                r3 = LD32(r14);
                r1 = LD16(82 + r3);
                if ((r1 & r1) == 0) {
                    r2 = LD32(r14);
                    ST32(100 + r2, 0x060154A4);
                    r2 = LD32(r14);
                    ST32(104 + r2, 0x060143D8);
                    r2 = LD32(r14);
                    ST32(108 + r2, 0x06019358);
                    r2 = LD32(r14);
                    r3 = LD32(sp - 40);
                    ST16(82 + r2, r3);
                }
            }
            r3 = LD32(r14);
            r2 = LD16(46 + r3);
            ST16(46 + r3, (r2 | r4));
            ST32(r13, r8);
            ST32(r14, r10);
            ST16(r12, r9);
            r0 = r11;
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

int f06019358(void)
{
    int r0, r1, r2, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r2 = LD32(0x060D7768);
    r3 = LD16(46 + r2);
    if (!(((r3 & 0xFFFF) & 0x800) == 0)) {
        SETSP((sp - 4));
        SETPR(0x0601937A);
        r0 = GCALL1(0x0601BEA8, 33);
    } else {
        SETSP((sp - 4));
        SETPR(0x06019370);
        r0 = GCALL1(0x060164E0, 14);
    }
    SETPR(LD32((sp - 4)));
    POLL();
    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x06015CD2);
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(82 + r4);
    if (!((r0 & r0) == 0)) {
        r2 = LD16(82 + r4);
        ST16(82 + r4, (r2 - 1));
    } else {
        SETSP((sp - 8));
        r0 = GCALL0(0x06015156);
        r2 = LD32(r14);
        r3 = LD16(46 + r2);
        if (!(((r3 & 0xFFFF) & 0x800) == 0)) {
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06019136);
            r0 = GCALL1(0x0601BEA8, 0x2710);
        } else {
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0601912A);
            r0 = GCALL1(0x060165B8, 0x2710);
        }
        r3 = LD32(r14);
        r1 = LD16(46 + r3);
        ST16(46 + r3, (r1 & 0xFDFF));
        r3 = LD32(r14);
        ST16(82 + r3, 0);
    }
    r3 = LD32(r14);
    r0 = LD8(r3 + 4);
    r0 = r0 & 239;
    ST8(r3 + 4, r0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06019370(void)
{
    return GJUMP0(0x0601937A);
}

int f060193B0(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r14 = 0x060D7768;
    ST32(sp - 40, r5);
    r11 = LD32(0x060D7768);
    r12 = 0x060D7B3C;
    r13 = 0x060C062C;
    r10 = LD32(0x060D7B3C);
    r9 = LD16(0x060C062C);
    r9 = r9 & 0xFFFF;
    SETSP((sp - 40));
    r0 = GCALL1(0x06018DD6, r4);
    r2 = LD8(0x060C063D);
    r8 = r0;
    if ((unsigned)r0 >= (unsigned)(r2 & 255)) {
        ST32(r14, r11);
        ST32(r12, r10);
        ST16(r13, r9);
        r0 = LD8(0x060C063D);
        r0 = r0 & 255;
    } else {
        ST16(r13, r8);
        r1 = ((r8 & 0xFFFF) * 124) + 0x060D5F30;
        ST32(r14, r1);
        r0 = LD16(r1 + 22);
        ST32(r12, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x06019406);
        r0 = GCALL0(0x06018D60);
        if ((r0 & r0) == 0) {
            ST32(r14, r11);
            ST32(r12, r10);
            ST16(r13, r9);
            r0 = LD8(0x060C063D);
            r0 = r0 & 255;
        } else {
            r3 = LD32(0x060D7768);
            r0 = LD16(82 + r3);
            if (!((r0 & r0) == 0)) {
                ST32(r14, r11);
                ST32(r12, r10);
                ST16(r13, r9);
                r0 = LD8(0x060C063D);
                r0 = r0 & 255;
            } else {
                SETSP((sp - 40));
                r0 = GCALL1(0x06014516, 0x06019470);
                r2 = LD32(r14);
                r3 = LD32(sp - 40);
                ST16(82 + r2, r3);
                r3 = LD32(r14);
                r1 = LD16(46 + r3);
                ST16(46 + r3, (r1 | 0x200));
                SETR(8, r8);
                SETR(9, r9);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 40));
                SETPR(0x06019438);
                r0 = GCALL0(0x06017D08);
                SETSP((sp - 40));
                r0 = GCALL0(0x06017DC0);
                SETR(8, r8);
                SETR(9, r9);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 40));
                SETPR(0x06019444);
                r0 = GCALL0(0x0601D7E4);
                ST32(r14, r11);
                ST32(r12, r10);
                ST16(r13, r9);
                r0 = r8;
            }
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

int f06019470(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(8));
    ST32((sp - 8), PR());
    r3 = LD32(0x060D7768);
    r0 = LD8(r3 + 4);
    ST8(r3 + 4, (r0 & 175));
    r3 = LD32(0x060D7768);
    r2 = LD16(46 + r3);
    if (((r2 & 0xFFFF) & 0x800) == 0) {
        SETSP((sp - 8));
        SETPR(0x06019492);
        r0 = GCALL1(0x060165B8, 24);
    }
    r3 = LD32(0x060D7B3C);
    r8 = LD16(38 + r3);
    SETSP((sp - 8));
    r0 = GCALL0(0x060167DE);
    if (!(r8 > (((short)r0) - 32))) {
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x06019514);
    } else {
        r0 = LD32(0x26006034);
        if (!((r0 & 1) == 0)) {
            r3 = LD32(0x060D7B3C);
            r2 = LD16(38 + r3);
            ST16(38 + r3, (r2 - 1));
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(8, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x06017DC0);
    return r0;
}

int f06019590(int r4)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r14 = 0x060D7768;
    ST16(0x060C062C, r4);
    r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
    ST32(0x060D7768, r4);
    r0 = LD16(r4 + 22);
    ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
    SETR(14, 0x060D7768);
    SETSP((sp - 16));
    SETPR(0x060195C2);
    r0 = GCALL0(0x06018D60);
    ST32(sp - 16, r0);
    if (!((r0 & r0) == 0)) {
        r3 = LD32(r14);
        r1 = LD16(46 + r3);
        ST16(46 + r3, (r1 | 0x200));
        r3 = LD32(r14);
        r0 = LD16(r3 + 20);
        r3 = (r0 & 0xFFFF) << 1;
        r0 = LD16(0x060EE8B0 + r3);
        ST16((0x060EE8B0 + r3), (r0 & 0xEFFF));
        r4 = LD32(r14);
        r0 = LD16(r4 + 22);
        SETSP((sp - 16));
        SETPR(0x060195F6);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
        SETSP((sp - 16));
        SETPR(0x060195FC);
        r0 = GCALL0(0x0601D730);
        SETSP((sp - 16));
        r0 = GCALL1(0x06014516, 0x06015CD2);
    }
    r0 = LD32(sp - 16);
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06019664(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r6 = 0x060C062C;
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r14 = 0x060D7768;
    ST32(sp - 16, r5);
    ST16(0x060C062C, r4);
    r3 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
    ST32(0x060D7768, r3);
    r5 = r3;
    r0 = LD8(r5 + 4);
    r0 = r0 & 255;
    if (!((r0 & 128) == 0)) {
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r0 = 46;
        r3 = LD16(46 + r5);
        if (((r3 & 0xFFFF) & 0x200) == 0) {
            SETMACL(LD32((sp - 12)));
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r1 = LD16(46 + r5);
            ST16(46 + r5, (r1 & 0xFDFF));
            ST16(r6, r4);
            r0 = LD32(r14);
            r0 = LD16(r0 + 22);
            ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
            r5 = LD32(sp - 16);
            r4 = LD32(r14);
            r0 = LD16(r4 + 22);
            SETSP((sp - 16));
            r0 = GCALL2(0x0600D148, r0, r5);
            SETSP((sp - 16));
            SETPR(0x060196CC);
            r0 = GCALL1(0x060165B8, 0x2710);
            SETSP((sp - 16));
            r0 = GCALL0(0x06015D16);
            SETSP((sp - 16));
            SETPR(0x060196D8);
            r0 = GCALL0(0x0601D7A8);
            SETMACL(LD32((sp - 12)));
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x060145A8);
            return r0;
        }
    }
}

int f060196EE(int r4, int r5)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    ST32(sp - 24, r5);
    SETSP((sp - 24));
    r0 = GCALL1(0x06018DD6, r4);
    r2 = LD8(0x060C063D);
    r14 = r0;
    if ((unsigned)r0 >= (unsigned)(r2 & 255)) {
        r0 = LD8(0x060C063D);
        r0 = r0 & 255;
    } else {
        r13 = 0x060D7768;
        ST16(0x060C062C, r14);
        r2 = ((r14 & 0xFFFF) * 124) + 0x060D5F30;
        ST32(0x060D7768, r2);
        r0 = LD16(r2 + 22);
        ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
        SETR(13, 0x060D7768);
        SETR(14, r14);
        SETSP((sp - 24));
        SETPR(0x06019734);
        r0 = GCALL0(0x06018D60);
        if ((r0 & r0) == 0) {
            r0 = LD8(0x060C063D);
            r0 = r0 & 255;
        } else {
            r2 = LD32(0x060D7768);
            r3 = LD16(46 + r2);
            if (!(((r3 & 0xFFFF) & 0x800) == 0)) {
                r0 = LD8(0x060C063D);
                r0 = r0 & 255;
            } else {
                r0 = LD16(0x060C062C);
                ST32(sp - 20, (((short)((((r0 << 2) << 1) + r0) << 1)) + 0x060C07B0));
                ST32((sp - 28), 0);
                r4 = LD32(sp - 24);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x0601976E);
                r0 = GCALL4(0x06018344, r4, 50, 24, 24);
                r3 = LD32(sp - 20);
                ST16(r3 + 4, -24);
                SETSP((sp - 24));
                r0 = GCALL0(0x06015172);
                r2 = LD32(r13);
                ST32(108 + r2, 0x060197E2);
                r0 = r14;
            }
        }
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060197E2(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060197EA);
    r0 = GCALL0(0x06018090);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r1 = LD16(46 + r3);
        ST16(46 + r3, (r1 | 0x200));
        r3 = LD32(0x060D7768);
        ST16(54 + r3, 0);
        r3 = LD32(0x060D7768);
        ST32(100 + r3, 0x060143D8);
        r3 = LD32(0x060D7768);
        ST32(104 + r3, 0x060143D8);
        r3 = LD32(0x060D7768);
        ST32(108 + r3, 0x06019878);
        r4 = LD16(0x060C062C);
        SETPR(LD32((sp - 4)));
        if (!((r4 & r4) == 0)) {
            r4 = 60;
        } else {
            r4 = 79;
        }
        UNFRAME(sp);
        r0 = GJUMP1(0x060165B8, r4);
        return r0;
    }
}

int f06019836(int dir)
{
    return GCALL3(0x06017E70, 1, dir, 0) && !(LDU16(0x060EC8B0 + LDU16(0x060D7E8C) * 2) & LDU16(LD32(CURRENT) + 18));
}

int f06019878(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c1;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r12 = 0x060D7768;
    r0 = LD16(0x060D7E68);
    if (((r0 & 0xFFFF) & 18) == 0) {
        r11 = 0x060C062C;
        r4 = LD16(0x060C062C);
        SETSP((sp - 32));
        r0 = GCALL1(0x0605F136, (r4 & 0xFFFF));
        if (!((r0 & r0) == 0)) {
            r4 = LD16(0x060C0684);
            SETSP((sp - 32));
            r0 = GCALL1(0x06016C50, (r4 & 0xFFFF));
        }
        SETR(11, r11);
        SETR(12, r12);
        SETSP((sp - 32));
        SETPR(0x0601990E);
        r0 = GCALL0(0x060165FE);
        r2 = LD16(0x060C0686);
        r1 = LD16(0x060BF5DC);
        if (!(((r2 & 0xFFFF) & (r1 & 0xFFFF)) == 0)) {
            r4 = LD16(r11);
            SETSP((sp - 32));
            r0 = GCALL1(0x0605F16E, (r4 & 0xFFFF));
        }
        r3 = LD16(0x060BF5E2);
        r1 = LD16(0x060BF5E0);
        r3 = (r3 & 0xFFFF) | (r1 & 0xFFFF);
        r1 = LD16(0x060BF5E8);
        r3 = r3 | (r1 & 0xFFFF);
        r1 = LD16(0x060C0684);
        if (!((r3 & (r1 & 0xFFFF)) == 0)) {
            r0 = LD32(r12);
            r8 = 0;
            r0 = LD8(r0 + 6);
            r14 = (2 ^ ((r0 & 255) - 1)) + 1;
            SETSP((sp - 32));
            r0 = GCALL1(0x06019836, r14);
            if ((r0 & r0) == 0) {
                r13 = r8;
                r9 = 3;
                r10 = 4;
                while (1) {
                    r14 = (r14 & r9) + 1;
                    SETSP((sp - 32));
                    r0 = GCALL1(0x06019836, r14);
                    if (!((r0 & r0) == 0)) {
                        break;
                    } else {
                        r13 = r13 + 1;
                        if (!((unsigned)r13 >= (unsigned)r10)) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
                if ((unsigned)r13 >= (unsigned)r10) {
                    r14 = r8;
                }
            }
            if (!((r14 & r14) == 0)) {
                r4 = LD16(r11);
                SETSP((sp - 32));
                r0 = GCALL1(0x0605F204, (r4 & 0xFFFF));
                if (!((r0 & r0) == 0)) {
                    ST32((sp - 36), r8);
                    ST32((sp - 40), 6);
                    SETR(8, r8);
                    SETR(11, r11);
                    SETR(12, r12);
                    SETSP((sp - 40));
                    SETPR(0x060199A2);
                    r0 = GCALL4(0x060182DE, 1, r14, 40, 24);
                    r4 = LD16(r11);
                    r4 = ((short)((((r4 << 2) << 1) + r4) << 1)) + 0x060C07B0;
                    ST16(r4 + 4, r8);
                    ST16(r4, 100);
                    SETSP((sp - 32));
                    r0 = GCALL0(0x06015172);
                    r2 = LD32(r12);
                    ST32(100 + r2, 0x06018090);
                    r3 = LD32(r12);
                    r1 = LD16(46 + r3);
                    ST16(46 + r3, (r1 & 0xFDFF));
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
        UNFRAME(sp);
        r0 = GJUMP0(0x06015CD2);
        return r0;
    } else {
        SETSP((sp - 32));
        r0 = GCALL0(0x06015172);
        r0 = LD16(0x060D7E68);
        c1 = ((r0 & 0xFFFF) & 2) == 0;
        r0 = 100;
        if (c1) {
            r2 = LD32(r12);
            r1 = 0x06019C6C;
        } else {
            r1 = 0x06019A5C;
            r2 = LD32(r12);
        }
        ST32(r0 + r2, r1);
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
}

int f06019A5C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(8));
    ST32((sp - 24), PR());
    r13 = 0x060C029C;
    r14 = 0x060D7768;
    r3 = LD8(0x060C029C);
    if (!((r3 & 255) > 0)) {
        r0 = LD32(r14);
        r0 = LD16(r0 + 46);
        if (!(((r0 & 0xFFFF) & 2) == 0)) {
            SETSP((sp - 24));
            r0 = GCALL0(0x06020276);
        }
    }
    r11 = 0x060C062C;
    r0 = LD8(0x060C062D);
    ST8(0x060C063F, r0);
    SETSP((sp - 24));
    r0 = GCALL0(0x06014B0A);
    SETSP((sp - 24));
    r0 = GCALL0(0x06016812);
    r3 = LD32(r14);
    r1 = LD16(46 + r3);
    ST16(46 + r3, (r1 & 0x800));
    r3 = LD16(0x060C062C);
    ST8(0x060C0FC4 + (r3 & 0xFFFF), 4);
    SETR(11, 0x060C062C);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 24));
    SETPR(0x06019AB4);
    r0 = GCALL0(0x0601651E);
    SETR(11, 0x060C062C);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 24));
    SETPR(0x06019ABA);
    r0 = GCALL1(0x060164CC, 12);
    SETSP((sp - 24));
    r0 = GCALL0(0x06015172);
    r2 = LD32(r14);
    r12 = 0x0600996A;
    ST8(r2 + 6, 2);
    r0 = LD8(r13);
    if (!((r0 & 255) == 8)) {
        r2 = LD8(r13);
        if ((r2 & 255) >= 9) {
            SETSP((sp - 24));
            r0 = GCALL1(r12, 255);
        }
        SETPR(LD32((sp - 24)));
        SETR(8, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x060144F4, 0x06019BB4);
        return r0;
    } else {
        r2 = LD16(r11);
        r2 = (r2 & 0xFFFF) << 2;
        r3 = LD16(0x060C02AA);
        r1 = LD32(0x060C1000);
        r3 = (r3 & 0xFFFF) - r1;
        r1 = LD32(0x060C06C0 + r2);
        ST32(0x060C06C0 + r2, (r1 + r3));
        SETSP((sp - 24));
        r0 = GCALL2(0x06014504, 150, 0x06019C32);
        r1 = LD8(0x060C029D);
        SETSP((sp - 24));
        r0 = MODS((r1 & 255), 4);
        if (!((r0 & r0) == 0)) {
            r4 = 0x11B;
        } else {
            r4 = 0x11C;
        }
        SETSP((sp - 24));
        r0 = GCALL1(r12, r4);
        r2 = LD32(r14);
        ST16(64 + r2, 0);
        r0 = 80;
        ST16(80 + r2, 0);
        SETPR(LD32((sp - 24)));
        SETR(8, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

void f06019BB4(void)
{
    gaddr cur, rec, row;
    int n;

    GCALL0(0x06015CD2);
    cur = LD32(CURRENT);
    if (LD16(cur + 36)) {
        rec = REC(LDU16(cur + 36));
        n = GCALL1(0x06068B4E, OBJ(LDU16(rec + 22)));
        row = 0x060B463E + (signed char)(LDU8(rec + 53) * 40) + (n - 1) * 4;
        ST16(LD32(0x060D7B3C) + 36, LD16(row));
        cur = LD32(0x060D7B3C);
        n = GCALL0(0x060167DE);
        ST16(cur + 38, LD16(row + 2) + n);
    }
}

void f06019C32(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD8(0x060C029D);
    if ((r3 & 255) >= 20) {
        SETPR(LD32((sp - 4)));
        return;
    } else {
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 22);
        SETSP((sp - 4));
        SETPR(0x06019C4E);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 5);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600A32A, 248);
        r2 = LD32(0x060D7B3C);
        r0 = LD16(r2 + 18);
        if (r0 >= 0) {
            SETPR(LD32((sp - 4)));
            return;
        } else {
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x060147BC);
            return;
        }
    }
}

int f06019C6C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x06019D48);
    SETSP((sp - 4));
    r0 = GCALL0(0x06019EDE);
    SETSP((sp - 4));
    SETPR(0x06019C7C);
    r0 = GCALL0(0x0601651E);
    SETSP((sp - 4));
    SETPR(0x06019C82);
    r0 = GCALL1(0x060164CC, 13);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x060143D8);
    return r0;
}

int f06019CCC(int r4, int r5, int r6, int r7)
{
    int r0, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x06019D48);
    r14 = 0x060D7768;
    r0 = LD32(0x060D7768);
    r0 = LD16(r0 + 64);
    if (!(((r0 & 0xFFFF) & 1) == 0)) {
        SETSP((sp - 8));
        r0 = GCALL1(0x0601FF30, 1);
    }
    SETR(14, r14);
    SETSP((sp - 8));
    SETPR(0x06019CEE);
    r0 = GCALL1(0x060164E0, 11);
    r0 = LD32(r14);
    r0 = LD16(r0 + 20);
    r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
    if (((r0 & 0xFFFF) & 7) == 0) {
        SETSP((sp - 8));
        r0 = GCALL0(0x06016812);
    } else {
        r3 = LD16(0x060C062C);
        r3 = LD8(0x060C064A + (r3 & 0xFFFF));
        if ((r3 & 255) >= 2) {
            SETSP((sp - 8));
            r0 = GCALL0(0x06016812);
        } else {
            SETSP((sp - 8));
            r0 = GCALL3(0x0601689A, 0x8200, 0x8040, 0x8040);
        }
    }
    r3 = LD32(r14);
    ST32(104 + r3, 0x060143D8);
    r3 = LD16(0x060C062C);
    ST16(0x060C067C, r3);
    SETSP((sp - 8));
    r0 = GCALL2(0x06014504, 2, 0x06015358);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 13);
    return r0;
}

void f06019D48(void)
{
    gaddr entry;
    int id;

    GCALL0(0x06014B0A);
    ST8(LD32(0x060D7768) + 7, 0);
    id = GCALL1(0x06020FE8, LDU16(LD32(0x060D7768) + 20));
    if (id < 0)
        id = 10;
    entry = 0x060E1A98 + LDU16(0x060C062C);
    if (LD8(entry) == -1)
        ST8(entry, id);
    entry = 0x060C06C0 + (LDU16(0x060C062C) << 2);
    ST32(entry, LD32(entry) + LDU16(0x060C02AA) - LD32(0x060C1000));
    if (LDU16(LD32(0x060D7768) + 46) & 2)
        GCALL0(0x06020276);
    entry = 0x060EE8B0 + (LDU16(LD32(0x060D7768) + 20) << 1);
    ST16(entry, LD16(entry) & 0xEFFF);
}

int f06019E30(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r0 = 60;
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r3 = LD32(0x060D7B3C);
    r1 = LD16(60 + r3);
    if (!((r1 & 0xFFFF) == 0xFF00)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = 0x060C067C;
        r14 = 0x060C062C;
        r1 = LD16(0x060C067C);
        r2 = LD16(0x060C062C);
        if (r1 == r2) {
            r2 = LD8(0x060C063D);
            ST16(r4, (r2 & 255));
        }
        r3 = LD16(r14);
        ST8(0x060C0FC4 + (r3 & 0xFFFF), 3);
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 22);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06019E72);
        r0 = GCALL2(0x06068ACC, (r0 & 0xFFFF), 0);
        SETSP((sp - 12));
        r0 = GCALL0(0x06015172);
        r13 = 0x060144F4;
        r2 = LD8(0x060C063C);
        ST8(0x060C063C, (r2 - 1));
        r3 = LD8(0x060C029C);
        if (!((r3 & 255) >= 9)) {
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06019EBC);
            r0 = GCALL1(r13, 0x06019ED2);
        } else {
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06019E94);
            r0 = GCALL1(0x0601A0E4, 255);
            r0 = LD8(0x060C0682);
            if (((r0 & 255) & 4) == 0) {
                r4 = 0x06019ED2;
            } else {
                r2 = LD8(0x060C1004);
                if (!((r2 & r2) == 0)) {
                    r4 = 0x06019ED2;
                } else {
                    r4 = 0x060267A8;
                }
            }
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06019EB2);
            r0 = GCALL1(r13, r4);
        }
        r4 = LD16(r14);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x0602105A, (r4 & 0xFFFF));
        return r0;
    }
}

void f06019ED2(void)
{
    GCALL0(0x06019EDE);
    GJUMP0(0x060147BC);
}

int f06019EDE(void)
{
    ST16(LD32(CURRENT) + 64, 0);
    ST16(LD32(CURRENT) + 80, 0);
    ST16(LD32(CURRENT) + 18, 0x4B0);
    ST16(LD32(CURRENT) + 46, 0);
    GCALL0(0x06014B54);
    ST8(0x060C0654 + LDU16(0x060C062C), 0);
    return GJUMP0(0x06016812);
}

int f0601A05A(int r4, int r5, int r6)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060D7768;
    ST32(sp - 20, r4);
    ST32(sp - 16, r5);
    r3 = LD32(0x060D7768);
    r2 = LD16(80 + r3);
    r3 = LD32(sp - 20);
    r14 = r6;
    if (((r2 & 0xFFFF) & r3) == 0) {
        r0 = 1;
    } else {
        r4 = LD32(sp - 16);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 20));
        SETPR(0x0601A07E);
        r0 = GCALL1(0x06019F16, r4);
        if (!((r0 & r0) == 0)) {
            r3 = LD32(r13);
            r4 = LD32(sp - 20);
            r4 = ~r4;
            r2 = LD16(80 + r3);
            ST16(80 + r3, (r2 & r4));
            r3 = LD32(r13);
            r2 = LD16(64 + r3);
            ST16(64 + r3, (r2 & r4));
            r3 = LD32(r14);
            r3 = r3 - 1;
            ST32(r14, r3);
            if (!((r3 & r3) == 0)) {
                r0 = 1;
            } else {
                r0 = 0;
            }
        } else {
            r0 = 0;
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0601A0E4(int r4)
{
    int r0, r1, r2, r3, r6, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    r14 = 0x060D7768;
    ST32(sp - 28, r4);
    r4 = LD32(0x060D7768);
    r13 = LD16(76 + r4);
    r13 = r13 & 0xFFFF;
    r12 = LD16(78 + r4);
    r0 = LD8(r4 + 4);
    r12 = r12 & 0xFFFF;
    if (!(((r0 & 255) & 128) == 0)) {
        r0 = LD8(0x060C029C);
        if (!((r0 & 255) == 17)) {
            r4 = 5;
            r1 = LD32(sp - 28);
            if ((unsigned)r1 > (unsigned)5) {
                ST32(sp - 28, r4);
            }
            r4 = 3;
            if ((unsigned)r13 > (unsigned)3) {
                r13 = r4;
            }
            r4 = 4;
            if ((unsigned)r12 > (unsigned)4) {
                r12 = r4;
            }
        }
    } else {
        SETSP((sp - 28));
        r0 = GCALL1(0x0600996A, 42);
    }
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 28));
    SETPR(0x0601A144);
    r0 = GCALL3(0x0601A05A, 0x800, 15, (sp - 28));
    if (!((r0 & r0) == 0)) {
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 28));
        SETPR(0x0601A154);
        r0 = GCALL3(0x0601A05A, 8, 20, (sp - 28));
        if (!((r0 & r0) == 0)) {
            r4 = LD32(r14);
            r4 = LD16(40 + r4);
            r11 = 2;
            r4 = r4 & 0xFFFF;
            if (!(r4 > 2)) {
                r10 = r11;
            } else {
                r10 = r4;
            }
            if (!((unsigned)r13 >= (unsigned)r10)) {
                if (!((unsigned)r12 > (unsigned)r11)) {
                    SETR(14, r14);
                    SETSP((sp - 28));
                    SETPR(0x0601A1EE);
                    r0 = GCALL3(0x0601A05A, 0x400, 25, (sp - 28));
                    if (!((r0 & r0) == 0)) {
                        r13 = LD32(r14);
                        r4 = 0x00014000;
                        r0 = LD16(r13 + 12);
                        r3 = (r0 & 0xFFFF) << 16;
                        r0 = LD16(r13 + 10);
                        r13 = r3 + (r0 & 0xFFFF);
                        if ((unsigned)r13 > (unsigned)0x00014000) {
                            r13 = r4;
                        }
                        r11 = 0x2000;
                        r12 = 0x00010000;
                        if (!((unsigned)r13 > (unsigned)0x00010000)) {
                            SETR(14, r14);
                            SETSP((sp - 28));
                            SETPR(0x0601A23A);
                            r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                            if (!((r0 & r0) == 0)) {
                                SETR(14, r14);
                                SETSP((sp - 28));
                                SETPR(0x0601A246);
                                r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                if (!((r0 & r0) == 0)) {
                                    r3 = LD32(r14);
                                    r0 = LD16(68 + r3);
                                    if (!((r0 & r0) == 0)) {
                                        SETSP((sp - 28));
                                        SETPR(0x0601A268);
                                        r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                        if (!((r0 & r0) == 0)) {
                                            r6 = sp - 28;
                                            SETSP((sp - 28));
                                            SETPR(0x0601A28E);
                                            r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                            if (!((r0 & r0) == 0)) {
                                                SETSP((sp - 28));
                                                SETPR(0x0601A29A);
                                                r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                            }
                                        }
                                    } else {
                                        SETSP((sp - 28));
                                        SETPR(0x0601A25C);
                                        r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                        if (!((r0 & r0) == 0)) {
                                            SETSP((sp - 28));
                                            SETPR(0x0601A268);
                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                            if (!((r0 & r0) == 0)) {
                                                r6 = sp - 28;
                                                SETSP((sp - 28));
                                                SETPR(0x0601A28E);
                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                if (!((r0 & r0) == 0)) {
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A29A);
                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            while (1) {
                                SETR(11, r11);
                                SETR(12, r12);
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 28));
                                SETPR(0x0601A218);
                                r0 = GCALL1(0x06019F16, 3);
                                if ((r0 & r0) == 0) {
                                    break;
                                } else {
                                    SETSP((sp - 28));
                                    r0 = GCALL0(0x06015F1C);
                                    r2 = LD32(sp - 28);
                                    r2 = r2 - 1;
                                    ST32(sp - 28, r2);
                                    if ((r2 & r2) == 0) {
                                        break;
                                    } else {
                                        r13 = r13 - r11;
                                        if ((unsigned)r13 > (unsigned)r12) {
                                            POLL();
                                            continue;
                                        } else {
                                            SETR(14, r14);
                                            SETSP((sp - 28));
                                            SETPR(0x0601A23A);
                                            r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                            if ((r0 & r0) == 0) {
                                                break;
                                            } else {
                                                SETR(14, r14);
                                                SETSP((sp - 28));
                                                SETPR(0x0601A246);
                                                r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                if ((r0 & r0) == 0) {
                                                    break;
                                                } else {
                                                    r3 = LD32(r14);
                                                    r0 = LD16(68 + r3);
                                                    if (!((r0 & r0) == 0)) {
                                                        SETSP((sp - 28));
                                                        SETPR(0x0601A268);
                                                        r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                        if ((r0 & r0) == 0) {
                                                            break;
                                                        } else {
                                                            r6 = sp - 28;
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A28E);
                                                            r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A29A);
                                                                r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                break;
                                                            }
                                                        }
                                                    } else {
                                                        SETSP((sp - 28));
                                                        SETPR(0x0601A25C);
                                                        r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                        if ((r0 & r0) == 0) {
                                                            break;
                                                        } else {
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A268);
                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                r6 = sp - 28;
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A28E);
                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A29A);
                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                POLL();
                            }
                        }
                    }
                } else {
                    while (1) {
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(14, r14);
                        SETSP((sp - 28));
                        SETPR(0x0601A1BE);
                        r0 = GCALL1(0x06019F16, 1);
                        if ((r0 & r0) == 0) {
                            break;
                        } else {
                            r3 = LD32(r14);
                            r2 = LD16(78 + r3);
                            ST16(78 + r3, (r2 - 1));
                            r3 = LD32(r14);
                            r0 = 52;
                            r2 = LD16(52 + r3);
                            ST16(52 + r3, (r2 - 1));
                            r3 = LD32(sp - 28);
                            r3 = r3 - 1;
                            ST32(sp - 28, r3);
                            r12 = r12 - 1;
                            if ((r3 & r3) == 0) {
                                break;
                            } else {
                                if ((unsigned)r12 > (unsigned)r11) {
                                    POLL();
                                    continue;
                                } else {
                                    SETR(14, r14);
                                    SETSP((sp - 28));
                                    SETPR(0x0601A1EE);
                                    r0 = GCALL3(0x0601A05A, 0x400, 25, (sp - 28));
                                    if ((r0 & r0) == 0) {
                                        break;
                                    } else {
                                        r13 = LD32(r14);
                                        r4 = 0x00014000;
                                        r0 = LD16(r13 + 12);
                                        r3 = (r0 & 0xFFFF) << 16;
                                        r0 = LD16(r13 + 10);
                                        r13 = r3 + (r0 & 0xFFFF);
                                        if (!((unsigned)r13 > (unsigned)0x00014000)) {
                                            r11 = 0x2000;
                                            r12 = 0x00010000;
                                            if (!((unsigned)r13 > (unsigned)0x00010000)) {
                                                SETR(14, r14);
                                                SETSP((sp - 28));
                                                SETPR(0x0601A23A);
                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                if ((r0 & r0) == 0) {
                                                    break;
                                                } else {
                                                    SETR(14, r14);
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A246);
                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                    if ((r0 & r0) == 0) {
                                                        break;
                                                    } else {
                                                        r3 = LD32(r14);
                                                        r0 = LD16(68 + r3);
                                                        if (!((r0 & r0) == 0)) {
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A268);
                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                r6 = sp - 28;
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A28E);
                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A29A);
                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                    break;
                                                                }
                                                            }
                                                        } else {
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A25C);
                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A268);
                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    r6 = sp - 28;
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A28E);
                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        SETSP((sp - 28));
                                                                        SETPR(0x0601A29A);
                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                while (1) {
                                                    SETR(11, r11);
                                                    SETR(12, r12);
                                                    SETR(13, r13);
                                                    SETR(14, r14);
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A218);
                                                    r0 = GCALL1(0x06019F16, 3);
                                                    if ((r0 & r0) == 0) {
                                                        break;
                                                    } else {
                                                        SETSP((sp - 28));
                                                        r0 = GCALL0(0x06015F1C);
                                                        r2 = LD32(sp - 28);
                                                        r2 = r2 - 1;
                                                        ST32(sp - 28, r2);
                                                        if ((r2 & r2) == 0) {
                                                            break;
                                                        } else {
                                                            r13 = r13 - r11;
                                                            if ((unsigned)r13 > (unsigned)r12) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                SETR(14, r14);
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A23A);
                                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETR(14, r14);
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A246);
                                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r3 = LD32(r14);
                                                                        r0 = LD16(68 + r3);
                                                                        if (!((r0 & r0) == 0)) {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A268);
                                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                r6 = sp - 28;
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A28E);
                                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A29A);
                                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                    break;
                                                                                }
                                                                            }
                                                                        } else {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A25C);
                                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A268);
                                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    r6 = sp - 28;
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A28E);
                                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                    if ((r0 & r0) == 0) {
                                                                                        break;
                                                                                    } else {
                                                                                        SETSP((sp - 28));
                                                                                        SETPR(0x0601A29A);
                                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    POLL();
                                                }
                                                break;
                                            }
                                        } else {
                                            r13 = r4;
                                            r11 = 0x2000;
                                            r12 = 0x00010000;
                                            if (!((unsigned)r13 > (unsigned)0x00010000)) {
                                                SETR(14, r14);
                                                SETSP((sp - 28));
                                                SETPR(0x0601A23A);
                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                if ((r0 & r0) == 0) {
                                                    break;
                                                } else {
                                                    SETR(14, r14);
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A246);
                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                    if ((r0 & r0) == 0) {
                                                        break;
                                                    } else {
                                                        r3 = LD32(r14);
                                                        r0 = LD16(68 + r3);
                                                        if (!((r0 & r0) == 0)) {
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A268);
                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                r6 = sp - 28;
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A28E);
                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A29A);
                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                    break;
                                                                }
                                                            }
                                                        } else {
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A25C);
                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A268);
                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    r6 = sp - 28;
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A28E);
                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        SETSP((sp - 28));
                                                                        SETPR(0x0601A29A);
                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                while (1) {
                                                    SETR(11, r11);
                                                    SETR(12, r12);
                                                    SETR(13, r13);
                                                    SETR(14, r14);
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A218);
                                                    r0 = GCALL1(0x06019F16, 3);
                                                    if ((r0 & r0) == 0) {
                                                        break;
                                                    } else {
                                                        SETSP((sp - 28));
                                                        r0 = GCALL0(0x06015F1C);
                                                        r2 = LD32(sp - 28);
                                                        r2 = r2 - 1;
                                                        ST32(sp - 28, r2);
                                                        if ((r2 & r2) == 0) {
                                                            break;
                                                        } else {
                                                            r13 = r13 - r11;
                                                            if ((unsigned)r13 > (unsigned)r12) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                SETR(14, r14);
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A23A);
                                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETR(14, r14);
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A246);
                                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r3 = LD32(r14);
                                                                        r0 = LD16(68 + r3);
                                                                        if (!((r0 & r0) == 0)) {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A268);
                                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                r6 = sp - 28;
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A28E);
                                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A29A);
                                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                    break;
                                                                                }
                                                                            }
                                                                        } else {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A25C);
                                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A268);
                                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    r6 = sp - 28;
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A28E);
                                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                    if ((r0 & r0) == 0) {
                                                                                        break;
                                                                                    } else {
                                                                                        SETSP((sp - 28));
                                                                                        SETPR(0x0601A29A);
                                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    POLL();
                                                }
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        POLL();
                    }
                }
            } else {
                while (1) {
                    SETR(10, r10);
                    SETR(11, r11);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 28));
                    SETPR(0x0601A18A);
                    r0 = GCALL1(0x06019F16, 2);
                    if (!((r0 & r0) == 0)) {
                        r3 = LD32(r14);
                        r2 = LD16(76 + r3);
                        ST16(76 + r3, (r2 - 1));
                        r3 = LD32(r14);
                        r0 = 62;
                        r2 = LD16(62 + r3);
                        ST16(62 + r3, (r2 - 1));
                        r3 = LD32(sp - 28);
                        r3 = r3 - 1;
                        ST32(sp - 28, r3);
                        r13 = r13 - 1;
                        if ((r3 & r3) == 0) {
                            break;
                        } else {
                            if ((unsigned)r13 >= (unsigned)r10) {
                                POLL();
                                continue;
                            } else {
                                if (!((unsigned)r12 > (unsigned)r11)) {
                                    SETR(14, r14);
                                    SETSP((sp - 28));
                                    SETPR(0x0601A1EE);
                                    r0 = GCALL3(0x0601A05A, 0x400, 25, (sp - 28));
                                    if ((r0 & r0) == 0) {
                                        break;
                                    } else {
                                        r13 = LD32(r14);
                                        r4 = 0x00014000;
                                        r0 = LD16(r13 + 12);
                                        r3 = (r0 & 0xFFFF) << 16;
                                        r0 = LD16(r13 + 10);
                                        r13 = r3 + (r0 & 0xFFFF);
                                        if (!((unsigned)r13 > (unsigned)0x00014000)) {
                                            r11 = 0x2000;
                                            r12 = 0x00010000;
                                            if (!((unsigned)r13 > (unsigned)0x00010000)) {
                                                SETR(14, r14);
                                                SETSP((sp - 28));
                                                SETPR(0x0601A23A);
                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                if ((r0 & r0) == 0) {
                                                    break;
                                                } else {
                                                    SETR(14, r14);
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A246);
                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                    if ((r0 & r0) == 0) {
                                                        break;
                                                    } else {
                                                        r3 = LD32(r14);
                                                        r0 = LD16(68 + r3);
                                                        if (!((r0 & r0) == 0)) {
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A268);
                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                r6 = sp - 28;
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A28E);
                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A29A);
                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                    break;
                                                                }
                                                            }
                                                        } else {
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A25C);
                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A268);
                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    r6 = sp - 28;
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A28E);
                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        SETSP((sp - 28));
                                                                        SETPR(0x0601A29A);
                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                while (1) {
                                                    SETR(11, r11);
                                                    SETR(12, r12);
                                                    SETR(13, r13);
                                                    SETR(14, r14);
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A218);
                                                    r0 = GCALL1(0x06019F16, 3);
                                                    if ((r0 & r0) == 0) {
                                                        break;
                                                    } else {
                                                        SETSP((sp - 28));
                                                        r0 = GCALL0(0x06015F1C);
                                                        r2 = LD32(sp - 28);
                                                        r2 = r2 - 1;
                                                        ST32(sp - 28, r2);
                                                        if ((r2 & r2) == 0) {
                                                            break;
                                                        } else {
                                                            r13 = r13 - r11;
                                                            if ((unsigned)r13 > (unsigned)r12) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                SETR(14, r14);
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A23A);
                                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETR(14, r14);
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A246);
                                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r3 = LD32(r14);
                                                                        r0 = LD16(68 + r3);
                                                                        if (!((r0 & r0) == 0)) {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A268);
                                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                r6 = sp - 28;
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A28E);
                                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A29A);
                                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                    break;
                                                                                }
                                                                            }
                                                                        } else {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A25C);
                                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A268);
                                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    r6 = sp - 28;
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A28E);
                                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                    if ((r0 & r0) == 0) {
                                                                                        break;
                                                                                    } else {
                                                                                        SETSP((sp - 28));
                                                                                        SETPR(0x0601A29A);
                                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    POLL();
                                                }
                                                break;
                                            }
                                        } else {
                                            r13 = r4;
                                            r11 = 0x2000;
                                            r12 = 0x00010000;
                                            if (!((unsigned)r13 > (unsigned)0x00010000)) {
                                                SETR(14, r14);
                                                SETSP((sp - 28));
                                                SETPR(0x0601A23A);
                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                if ((r0 & r0) == 0) {
                                                    break;
                                                } else {
                                                    SETR(14, r14);
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A246);
                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                    if ((r0 & r0) == 0) {
                                                        break;
                                                    } else {
                                                        r3 = LD32(r14);
                                                        r0 = LD16(68 + r3);
                                                        if (!((r0 & r0) == 0)) {
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A268);
                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                r6 = sp - 28;
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A28E);
                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A29A);
                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                    break;
                                                                }
                                                            }
                                                        } else {
                                                            SETSP((sp - 28));
                                                            SETPR(0x0601A25C);
                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                            if ((r0 & r0) == 0) {
                                                                break;
                                                            } else {
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A268);
                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    r6 = sp - 28;
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A28E);
                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        SETSP((sp - 28));
                                                                        SETPR(0x0601A29A);
                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                while (1) {
                                                    SETR(11, r11);
                                                    SETR(12, r12);
                                                    SETR(13, r13);
                                                    SETR(14, r14);
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A218);
                                                    r0 = GCALL1(0x06019F16, 3);
                                                    if ((r0 & r0) == 0) {
                                                        break;
                                                    } else {
                                                        SETSP((sp - 28));
                                                        r0 = GCALL0(0x06015F1C);
                                                        r2 = LD32(sp - 28);
                                                        r2 = r2 - 1;
                                                        ST32(sp - 28, r2);
                                                        if ((r2 & r2) == 0) {
                                                            break;
                                                        } else {
                                                            r13 = r13 - r11;
                                                            if ((unsigned)r13 > (unsigned)r12) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                SETR(14, r14);
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A23A);
                                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETR(14, r14);
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A246);
                                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r3 = LD32(r14);
                                                                        r0 = LD16(68 + r3);
                                                                        if (!((r0 & r0) == 0)) {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A268);
                                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                r6 = sp - 28;
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A28E);
                                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A29A);
                                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                    break;
                                                                                }
                                                                            }
                                                                        } else {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A25C);
                                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A268);
                                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    r6 = sp - 28;
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A28E);
                                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                    if ((r0 & r0) == 0) {
                                                                                        break;
                                                                                    } else {
                                                                                        SETSP((sp - 28));
                                                                                        SETPR(0x0601A29A);
                                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    POLL();
                                                }
                                                break;
                                            }
                                        }
                                    }
                                } else {
                                    while (1) {
                                        SETR(11, r11);
                                        SETR(12, r12);
                                        SETR(14, r14);
                                        SETSP((sp - 28));
                                        SETPR(0x0601A1BE);
                                        r0 = GCALL1(0x06019F16, 1);
                                        if ((r0 & r0) == 0) {
                                            break;
                                        } else {
                                            r3 = LD32(r14);
                                            r2 = LD16(78 + r3);
                                            ST16(78 + r3, (r2 - 1));
                                            r3 = LD32(r14);
                                            r0 = 52;
                                            r2 = LD16(52 + r3);
                                            ST16(52 + r3, (r2 - 1));
                                            r3 = LD32(sp - 28);
                                            r3 = r3 - 1;
                                            ST32(sp - 28, r3);
                                            r12 = r12 - 1;
                                            if ((r3 & r3) == 0) {
                                                break;
                                            } else {
                                                if ((unsigned)r12 > (unsigned)r11) {
                                                    POLL();
                                                    continue;
                                                } else {
                                                    SETR(14, r14);
                                                    SETSP((sp - 28));
                                                    SETPR(0x0601A1EE);
                                                    r0 = GCALL3(0x0601A05A, 0x400, 25, (sp - 28));
                                                    if ((r0 & r0) == 0) {
                                                        break;
                                                    } else {
                                                        r13 = LD32(r14);
                                                        r4 = 0x00014000;
                                                        r0 = LD16(r13 + 12);
                                                        r3 = (r0 & 0xFFFF) << 16;
                                                        r0 = LD16(r13 + 10);
                                                        r13 = r3 + (r0 & 0xFFFF);
                                                        if (!((unsigned)r13 > (unsigned)0x00014000)) {
                                                            r11 = 0x2000;
                                                            r12 = 0x00010000;
                                                            if (!((unsigned)r13 > (unsigned)0x00010000)) {
                                                                SETR(14, r14);
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A23A);
                                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETR(14, r14);
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A246);
                                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r3 = LD32(r14);
                                                                        r0 = LD16(68 + r3);
                                                                        if (!((r0 & r0) == 0)) {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A268);
                                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                r6 = sp - 28;
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A28E);
                                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A29A);
                                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                    break;
                                                                                }
                                                                            }
                                                                        } else {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A25C);
                                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A268);
                                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    r6 = sp - 28;
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A28E);
                                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                    if ((r0 & r0) == 0) {
                                                                                        break;
                                                                                    } else {
                                                                                        SETSP((sp - 28));
                                                                                        SETPR(0x0601A29A);
                                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                while (1) {
                                                                    SETR(11, r11);
                                                                    SETR(12, r12);
                                                                    SETR(13, r13);
                                                                    SETR(14, r14);
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A218);
                                                                    r0 = GCALL1(0x06019F16, 3);
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        SETSP((sp - 28));
                                                                        r0 = GCALL0(0x06015F1C);
                                                                        r2 = LD32(sp - 28);
                                                                        r2 = r2 - 1;
                                                                        ST32(sp - 28, r2);
                                                                        if ((r2 & r2) == 0) {
                                                                            break;
                                                                        } else {
                                                                            r13 = r13 - r11;
                                                                            if ((unsigned)r13 > (unsigned)r12) {
                                                                                POLL();
                                                                                continue;
                                                                            } else {
                                                                                SETR(14, r14);
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A23A);
                                                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    SETR(14, r14);
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A246);
                                                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                                                    if ((r0 & r0) == 0) {
                                                                                        break;
                                                                                    } else {
                                                                                        r3 = LD32(r14);
                                                                                        r0 = LD16(68 + r3);
                                                                                        if (!((r0 & r0) == 0)) {
                                                                                            SETSP((sp - 28));
                                                                                            SETPR(0x0601A268);
                                                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                            if ((r0 & r0) == 0) {
                                                                                                break;
                                                                                            } else {
                                                                                                r6 = sp - 28;
                                                                                                SETSP((sp - 28));
                                                                                                SETPR(0x0601A28E);
                                                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                                if ((r0 & r0) == 0) {
                                                                                                    break;
                                                                                                } else {
                                                                                                    SETSP((sp - 28));
                                                                                                    SETPR(0x0601A29A);
                                                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                                    break;
                                                                                                }
                                                                                            }
                                                                                        } else {
                                                                                            SETSP((sp - 28));
                                                                                            SETPR(0x0601A25C);
                                                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                                                            if ((r0 & r0) == 0) {
                                                                                                break;
                                                                                            } else {
                                                                                                SETSP((sp - 28));
                                                                                                SETPR(0x0601A268);
                                                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                                if ((r0 & r0) == 0) {
                                                                                                    break;
                                                                                                } else {
                                                                                                    r6 = sp - 28;
                                                                                                    SETSP((sp - 28));
                                                                                                    SETPR(0x0601A28E);
                                                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                                    if ((r0 & r0) == 0) {
                                                                                                        break;
                                                                                                    } else {
                                                                                                        SETSP((sp - 28));
                                                                                                        SETPR(0x0601A29A);
                                                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                                        break;
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    POLL();
                                                                }
                                                                break;
                                                            }
                                                        } else {
                                                            r13 = r4;
                                                            r11 = 0x2000;
                                                            r12 = 0x00010000;
                                                            if (!((unsigned)r13 > (unsigned)0x00010000)) {
                                                                SETR(14, r14);
                                                                SETSP((sp - 28));
                                                                SETPR(0x0601A23A);
                                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                                if ((r0 & r0) == 0) {
                                                                    break;
                                                                } else {
                                                                    SETR(14, r14);
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A246);
                                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r3 = LD32(r14);
                                                                        r0 = LD16(68 + r3);
                                                                        if (!((r0 & r0) == 0)) {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A268);
                                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                r6 = sp - 28;
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A28E);
                                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A29A);
                                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                    break;
                                                                                }
                                                                            }
                                                                        } else {
                                                                            SETSP((sp - 28));
                                                                            SETPR(0x0601A25C);
                                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                                            if ((r0 & r0) == 0) {
                                                                                break;
                                                                            } else {
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A268);
                                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    r6 = sp - 28;
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A28E);
                                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                    if ((r0 & r0) == 0) {
                                                                                        break;
                                                                                    } else {
                                                                                        SETSP((sp - 28));
                                                                                        SETPR(0x0601A29A);
                                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                while (1) {
                                                                    SETR(11, r11);
                                                                    SETR(12, r12);
                                                                    SETR(13, r13);
                                                                    SETR(14, r14);
                                                                    SETSP((sp - 28));
                                                                    SETPR(0x0601A218);
                                                                    r0 = GCALL1(0x06019F16, 3);
                                                                    if ((r0 & r0) == 0) {
                                                                        break;
                                                                    } else {
                                                                        SETSP((sp - 28));
                                                                        r0 = GCALL0(0x06015F1C);
                                                                        r2 = LD32(sp - 28);
                                                                        r2 = r2 - 1;
                                                                        ST32(sp - 28, r2);
                                                                        if ((r2 & r2) == 0) {
                                                                            break;
                                                                        } else {
                                                                            r13 = r13 - r11;
                                                                            if ((unsigned)r13 > (unsigned)r12) {
                                                                                POLL();
                                                                                continue;
                                                                            } else {
                                                                                SETR(14, r14);
                                                                                SETSP((sp - 28));
                                                                                SETPR(0x0601A23A);
                                                                                r0 = GCALL3(0x0601A05A, 0x100, 11, (sp - 28));
                                                                                if ((r0 & r0) == 0) {
                                                                                    break;
                                                                                } else {
                                                                                    SETR(14, r14);
                                                                                    SETSP((sp - 28));
                                                                                    SETPR(0x0601A246);
                                                                                    r0 = GCALL3(0x0601A05A, 0x200, 12, (sp - 28));
                                                                                    if ((r0 & r0) == 0) {
                                                                                        break;
                                                                                    } else {
                                                                                        r3 = LD32(r14);
                                                                                        r0 = LD16(68 + r3);
                                                                                        if (!((r0 & r0) == 0)) {
                                                                                            SETSP((sp - 28));
                                                                                            SETPR(0x0601A268);
                                                                                            r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                            if ((r0 & r0) == 0) {
                                                                                                break;
                                                                                            } else {
                                                                                                r6 = sp - 28;
                                                                                                SETSP((sp - 28));
                                                                                                SETPR(0x0601A28E);
                                                                                                r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                                if ((r0 & r0) == 0) {
                                                                                                    break;
                                                                                                } else {
                                                                                                    SETSP((sp - 28));
                                                                                                    SETPR(0x0601A29A);
                                                                                                    r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                                    break;
                                                                                                }
                                                                                            }
                                                                                        } else {
                                                                                            SETSP((sp - 28));
                                                                                            SETPR(0x0601A25C);
                                                                                            r0 = GCALL3(0x0601A05A, 32, 24, (sp - 28));
                                                                                            if ((r0 & r0) == 0) {
                                                                                                break;
                                                                                            } else {
                                                                                                SETSP((sp - 28));
                                                                                                SETPR(0x0601A268);
                                                                                                r0 = GCALL3(0x0601A05A, 64, 27, (sp - 28));
                                                                                                if ((r0 & r0) == 0) {
                                                                                                    break;
                                                                                                } else {
                                                                                                    r6 = sp - 28;
                                                                                                    SETSP((sp - 28));
                                                                                                    SETPR(0x0601A28E);
                                                                                                    r0 = GCALL3(0x0601A05A, 16, 23, r6);
                                                                                                    if ((r0 & r0) == 0) {
                                                                                                        break;
                                                                                                    } else {
                                                                                                        SETSP((sp - 28));
                                                                                                        SETPR(0x0601A29A);
                                                                                                        r0 = GCALL3(0x0601A05A, 4, 14, (sp - 28));
                                                                                                        break;
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    POLL();
                                                                }
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        POLL();
                                    }
                                    break;
                                }
                            }
                        }
                    } else {
                        break;
                    }
                    POLL();
                }
            }
        }
    }
    SETPR(LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0601A2AC(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(8));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r11 = 0x060C062C;
    ST32(sp - 44, r5);
    r3 = LD16(0x060C062C);
    ST32(sp - 32, (r3 & 0xFFFF));
    r14 = 0x060D7768;
    r13 = 0x060D7B3C;
    r2 = LD32(0x060D7768);
    ST32(sp - 40, r2);
    r2 = LD32(0x060D7B3C);
    ST32(sp - 36, r2);
    ST16(0x060C062C, r4);
    r3 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
    ST32(0x060D7768, r3);
    r0 = LD16(r3 + 22);
    ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
    SETSP((sp - 44));
    r0 = GCALL1(0x06023602, r4);
    r0 = r0 & 255;
    if (!((r0 & r0) == 0)) {
        r3 = LD32(r14);
        r12 = 0;
        r2 = LD32(sp - 44);
        ST32(120 + r3, r2);
        r3 = LD32(r14);
        ST32(112 + r3, 0);
        r3 = LD32(r14);
        ST16(58 + r3, 0);
        r3 = LD32(r14);
        ST16(56 + r3, 0);
        r3 = LD32(r14);
        ST16(82 + r3, 0);
        r3 = LD32(r14);
        r2 = LD16(46 + r3);
        if (!(((r2 & 0xFFFF) & 0x1000) == 0)) {
            SETSP((sp - 44));
            r0 = GCALL1(0x060144F4, 0x0601A3A4);
        } else {
            SETSP((sp - 44));
            r0 = GCALL1(0x06014516, 0x0601A3A4);
            r3 = LD32(r14);
            r1 = LD16(46 + r3);
            ST16(46 + r3, (r1 | 0x1000));
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 44));
            SETPR(0x0601A348);
            r0 = GCALL0(0x0601D84A);
        }
        r3 = LD32(r13);
        ST16(36 + r3, r12);
        r8 = LD32(r13);
        SETSP((sp - 44));
        r0 = GCALL0(0x060167DE);
        ST16((r8 + 38), r0);
        r3 = LD32(r14);
        r0 = LD16(r3 + 20);
        r3 = r0 & 0xFFFF;
        r0 = 0x060EE8B0;
        r3 = r3 << 1;
        r1 = LD16(0x060EE8B0 + r3);
        ST16(0x060EE8B0 + r3, (r1 & 0xEFFF));
    }
    r3 = LD32(sp - 32);
    ST16(r11, r3);
    r2 = LD32(sp - 40);
    ST32(r14, r2);
    r3 = LD32(sp - 36);
    ST32(r13, r3);
    SETMACL(LD32((sp - 28)));
    SETPR(LD32((sp - 24)));
    SETR(8, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0601A394(int i, int v)
{
    ST32(0x060D5FA0 + i * 124, v);
}

int f0601A942(void)
{
    if (!(LD8((OBJECTS + 0x30) + 4) & 128) && (LDU16((OBJECTS + 0x30) + 46) & 0x1000))
        return 1;
    if (LD8((OBJECTS + 0x30) + 128) & 128)
        return 0;
    return (LDU16((OBJECTS + 0x30) + 170) & 0x1000) != 0;
}

void f0601A97C(int a, int b)
{
    if (a && LD8(0x060C0654)) {
        gaddr cell = 0x060EE8B0 + (LDU16(REC(0) + 20) + a * 64) * 2;

        ST16(cell, LD16(cell) & 0xEFFF);
    }
    if (b && LD8(0x060C0655)) {
        gaddr cell = 0x060EE8B0 + (LDU16(REC(1) + 20) + b * 64) * 2;

        ST16(cell, LD16(cell) & 0xEFFF);
    }
}

int f0601ACFE(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    r12 = 0;
    r11 = 8;
    ST32((sp - 20), R(10));
    r14 = 0;
    ST32((sp - 24), R(9));
    r9 = 124;
    r10 = 255;
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r8 = 0x060143E0;
    r13 = LD8(0x060C063D);
    r13 = r13 & 255;
    do {
        SETSP((sp - 36));
        r0 = GCALL1(r8, r13);
        ST16(0x060D5F54 + (r13 * r9), r10);
        ST8(0x060D82CC + r14, r12);
        r14 = r14 + 1;
        r13 = r13 + 1;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r11)));
    ST16(0x060D82D6, r12);
    r0 = LD8(0x060C029C);
    r0 = r0 & 255;
    if (r0 == 17) {
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
    } else {
        SETMACL(LD32((sp - 36)));
        SETPR(LD32((sp - 32)));
        SETR(8, LD32((sp - 28)));
        SETR(9, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        POLL();
        ST32((sp - 4), PR());
        SETSP((sp - 4));
        r0 = GCALL1(0x06008A96, 0);
        SETSP((sp - 4));
        SETPR(0x0601ACF4);
        r0 = GCALL2(0x06068BA4, 117, 230);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06008ECA, 16, 0);
        return r0;
    }
}

void f0601AD70(void)
{
    ST32(0x060D8310, LD32(0x060D7768));
    ST32(0x060D8314, LD32(0x060D7B3C));
}

void f0601AD82(void)
{
    ST32(CURRENT, LD32(0x060D8310));
    ST32(0x060D7B3C, LD32(0x060D8314));
}

int f0601AD94(void)
{
    int result = GCALL0(0x0601AD82);

    ST16(0x060C062C, LD16(0x060D82D8));
    return result;
}

void f0601ADA6(void)
{
    gaddr rec;

    GCALL0(0x0601AD70);
    rec = REC(LDU16(LD32(0x060D8310) + 36));
    ST32(CURRENT, rec);
    ST32(MOVER_PTR, OBJ(LDU16(rec + 22)));
    ST32(0x060D8318, 0x060D831C + (short)(LD16(LD32(CURRENT) + 62) * 48));
}

void f0601AE4C(void)
{
    GCALL0(0x0601ADA6);
    ST16(0x060D82D8, LD16(0x060C062C));
    ST16(0x060C062C, LD16(LD32(0x060D8310) + 36));
}

void f0601AE68(void)
{
    int bomber = LD32(CURRENT);
    int other = LD32(0x060D7B3C);

    ST32(CURRENT, LD32(0x060D8310));
    ST32(0x060D7B3C, LD32(0x060D8314));
    ST32(0x060D8310, bomber);
    ST32(0x060D8314, other);
}

void f0601AEC2(int n)
{
    ST16(LD32(0x060D8318) + n * 2, 0);
    ST8(LD32(0x060D8318) + 24 + n, 0);
    ST8(n + LD32(0x060D8318) + 36, 0);
}

void f0601AEE2(void)
{
    int i = 0;

    do {
        GCALL1(0x0601AEC2, i);
    } while (AGAIN(++i < 12));
}

void f0601AF3E(int r4, int r5)
{
    int r0, r2, r3, r6, r11, r12, r14;
    ENTRY_SP(sp);

    ST32(sp - 4, r5);
    r6 = LD16(0x060C062C);
    r6 = LD8(((((((r6 & 0xFFFF) << 2) + (r6 & 0xFFFF)) + 0x060D8304) + r5) - 1));
    r6 = r6 & 255;
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r11 = 0x060D82D6;
    ST32(sp - 36, r4);
    r4 = 8;
    ST32(sp - 32, r5);
    r5 = 0;
    ST32(sp - 28, r6);
    r3 = LD16(0x060D82D6);
    r12 = 0;
    if (!((r3 & 0xFFFF) >= 8)) {
        r14 = r5;
        while (!((unsigned)r14 >= (unsigned)r4)) {
            r3 = LD8(0x060D82CC + r14);
            if (!(((r3 & 255) & (r3 & 255)) == 0)) {
                POLL();
                r14 = r14 + 1;
                POLL();
                continue;
            } else {
                break;
            }
            POLL();
        }
        if (!((unsigned)r14 >= (unsigned)r4)) {
            r12 = LD8(0x060C063D);
            r12 = (r12 & 255) + r14;
            SETSP((sp - 36));
            r0 = GCALL0(0x0601AD70);
            SETSP((sp - 36));
            r0 = GCALL2(0x06008A6A, 8, 0);
            SETSP((sp - 36));
            r0 = GCALL2(0x0601471C, r12, 0x0601B5CC);
            r3 = (r12 * 124) + 0x060D5F30;
            ST32(0x060D7768, r3);
            r0 = LD16(r3 + 22);
            ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
            ST32(0x060D8318, (((short)((((r14 << 1) + r14) << 2) << 2)) + 0x060D831C));
            r3 = LD32(0x060D7768);
            ST8(r3 + 6, 2);
            r3 = LD32(0x060D7768);
            ST16(62 + r3, r14);
            r3 = LD32(0x060D7768);
            r2 = LD32(sp - 32);
            ST16(64 + r3, r2);
            r3 = LD32(0x060D7768);
            r2 = LD32(sp - 28);
            ST16(52 + r3, r2);
            SETSP((sp - 36));
            r0 = GCALL0(0x0601B34A);
            SETSP((sp - 36));
            r0 = GCALL0(0x0601AEE2);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, 0x060D7768);
            SETR(14, r14);
            SETSP((sp - 36));
            SETPR(0x0601B016);
            r0 = GCALL0(0x0601AE84);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, 0x060D7768);
            SETR(14, r14);
            SETSP((sp - 36));
            SETPR(0x0601B01A);
            r0 = GCALL0(0x0601B390);
            r3 = LD32(0x060D7B3C);
            ST16(46 + r3, (((r12 << 2) << 2) + 96));
            SETSP((sp - 36));
            r0 = GCALL0(0x0601BC58);
            r5 = LD32(sp - 36);
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 22);
            SETSP((sp - 36));
            r0 = GCALL2(0x0600D148, r0, r5);
            r4 = LD32(0x060D7768);
            r0 = LD8(r4 + 6);
            SETSP((sp - 36));
            r0 = GCALL1(0x0601BF0C, (r0 & 255));
            SETSP((sp - 36));
            r0 = GCALL0(0x0601C0C8);
            SETSP((sp - 36));
            r0 = GCALL0(0x0601AD82);
            ST8(0x060D82CC + r14, r12);
            r2 = LD16(r11);
            ST16(r11, (r2 + 1));
        }
    }
    SETMACL(LD32((sp - 24)));
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
}

int f0601B068(int player, int kind)
{
    unsigned int score;
    gaddr limits;

    if ((unsigned char)LD8(0x060C029C) >= 9)
        return LDU16(LD32(CURRENT) + 52);
    kind--;
    score = LD32(0x060D82DC + player * 20 + kind * 4);
    limits = 0x060B46B8 + (signed char)(kind * 12);
    if (score < (unsigned int)LD32(limits))
        return 0;
    return score >= (unsigned int)LD32(limits + 4) ? 2 : 1;
}

int f0601B12C(int bomber)
{
    gaddr rec = REC(bomber);
    int step = LDU16(REC(LDU16(rec + 36)) + 64) - 1;
    unsigned int threshold = LD32(0x060D82DC + bomber * 20 + step * 4);
    gaddr table = 0x060B46B8 + (signed char)(step * 12);
    int level = 0;

    while (level < 2 && threshold >= LD32(table)) {
        level++;
        table += 4;
        POLL();
    }
    return level;
}

int f0601B194(int n)
{
    gaddr owner = REC(LDU16(REC(n) + 36));
    int k = LDU16(owner + 64) - 1;
    gaddr range = 0x060B46B8 + (signed char)(k * 12);
    unsigned int value = LD32(0x060D82DC + n * 20 + k * 4);
    unsigned int percent;

    switch (LDU16(owner + 52)) {
    case 0:
        percent = DIVU(value * 100, LD32(range));
        break;
    case 1:
        value = value >= LD32(range) ? value - LD32(range) : 0;
        percent = DIVU(value * 100, LD32(range + 4) - LD32(range));
        break;
    default:
        percent = 100;
    }
    return percent > 100 ? 100 : percent;
}

int f0601B240(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r0 = 46;
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r2 = LD16(46 + r3);
    if (((r2 & 0xFFFF) & 0x800) == 0) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL0(0x0601ADA6);
        r1 = LD32(r14);
        r3 = LD16(52 + r1);
        if (!((r3 & 0xFFFF) >= 2)) {
            r1 = LD32(r14);
            r3 = LD16(52 + r1);
            ST16(52 + r1, (r3 + 1));
        }
        SETSP((sp - 8));
        r0 = GCALL0(0x0601B34A);
        SETSP((sp - 8));
        SETPR(0x0601B27C);
        r0 = GCALL1(0x06016574, 0x2710);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0601AD82);
        return r0;
    }
}

void f0601B288(void)
{
    int i = 0;
    gaddr rec = REC(0);
    gaddr other;
    int kind;

    do {
        if (LD16(rec + 36)) {
            other = REC(LDU16(rec + 36));
            if (LDU16(other + 52) == 2) {
                kind = LDU16(other + 64) - 1;
                ST32(0x060D82DC + i * 20 + kind * 4, LD32(0x060B46B8 + (signed char)(kind * 12) + (LDU16(other + 52) - 1) * 4));
            }
        }
        i++;
        rec += 124;
    } while (AGAIN(i < 2));
}

int f0601B308(int n)
{
    gaddr rec = REC(n);

    if (!(LDU16(rec + 46) & 0x800))
        return 0;
    return LDU16(OBJ(LDU16(REC(LDU16(rec + 36)) + 22)) + 46) & 0x7FF;
}

void f0601B34A(void)
{
    ST16(LD32(MOVER_PTR) + 48, LD16(LD32(0x060D7768) + 52) * 34 + 128);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601B390(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    r3 = LD32(0x060D7768);
    ST16(r3 + 18, 176);
    r3 = LD32(0x060D7768);
    ST16(36 + r3, 255);
    r3 = LD32(0x060D7768);
    ST32(100 + r3, 0x0601B6AE);
    UNFRAME(sp);
    r0 = GJUMP1(0x060165B8, 0);
    return r0;
}

int f0601B3AE(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0601ADA6);
    SETSP((sp - 4));
    SETPR(0x0601B3B8);
    r0 = GCALL0(0x0601B390);
    r4 = LD16(0x060C062C);
    if (!((r4 & 0xFFFF) >= 2)) {
        ST8(0x060D82D4 + (r4 & 0xFFFF), 0);
    }
    SETSP((sp - 4));
    r0 = GCALL0(0x0601BC58);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 4));
    r0 = GCALL2(0x0606AAC8, r4, 0);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x0601AD82);
    return r0;
}

int f0601B3DE(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    r0 = GCALL0(0x0601ADA6);
    r14 = 0x060D7768;
    r5 = LD32(0x060D7768);
    r3 = LD16(36 + r5);
    if ((r3 & 0xFFFF) == 255) {
        r4 = 0x060C062C;
        r3 = LD16(0x060C062C);
        ST16(36 + r5, r3);
        r1 = LD16(0x060C062C);
        if (!((r1 & 0xFFFF) >= 2)) {
            r6 = 0x060D8304;
            r1 = LD16(r4);
            r2 = LD32(r14);
            r2 = LD8((65 + r2));
            ST8(0x060D82D4 + (r1 & 0xFFFF), r2);
            r5 = LD32(r14);
            r5 = LD16(64 + r5);
            r0 = LD16(r4);
            r5 = (r5 & 0xFFFF) - 1;
            r3 = LD32(r14);
            r2 = LD8(((((r0 & 0xFFFF) << 2) + (r0 & 0xFFFF)) + 0x060D8304) + r5);
            r1 = LD16(52 + r3);
            if (!((r2 & 255) >= (r1 & 0xFFFF))) {
                r2 = LD16(r4);
                r1 = LD32(r14);
                r3 = LD8(53 + r1);
                ST8((((((r2 & 0xFFFF) << 2) + (r2 & 0xFFFF)) + r6) + r5), r3);
                r2 = LD32(r14);
                r1 = LD16(52 + r2);
                if (!((r1 & r1) == 0)) {
                    r7 = LD32(r14);
                    r6 = LD16(r4);
                    r7 = LD16((52 + r7));
                    r13 = r5 << 2;
                    r7 = LD32(((((r7 & 0xFFFF) - 1) << 2) + (0x060B46B8 + ((signed char)(((r5 << 1) + r5) << 2)))));
                    r6 = ((((r6 & 0xFFFF) << 2) + (r6 & 0xFFFF)) << 2) + 0x060D82DC;
                    r3 = LD32(r13 + r6);
                    if (!((unsigned)r3 >= (unsigned)r7)) {
                        ST32((r6 + r13), r7);
                    }
                }
            }
        }
        SETSP((sp - 12));
        r0 = GCALL0(0x0601BB8E);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x0601B4D2);
        r0 = GCALL1(0x060165B8, 0);
        r4 = LD32(r14);
        r0 = LD8(r4 + 6);
        SETSP((sp - 12));
        r0 = GCALL1(0x0601BF0C, (r0 & 255));
        r4 = LD32(r14);
        r0 = LD16(r4 + 22);
        SETSP((sp - 12));
        r0 = GCALL1(0x0606948A, r0);
        SETSP((sp - 12));
        r0 = GCALL0(0x0601BBC2);
        r14 = 1;
    } else {
        r14 = 0;
    }
    SETSP((sp - 12));
    r0 = GCALL0(0x0601AD82);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r14;
}

void f0601B4F8(void)
{
    GCALL0(0x0601ADA6);
    GCALL1(0x0600996A, LDU16(LD32(CURRENT) + 52) + 38);
    GJUMP0(0x0601AD82);
}

int f0601B514(int id, int i)
{
    int p = (OBJECTS + 0x30) + i * 124;

    if (LD8(p + 4) & 192)
        return 0;
    if (LDU16(p + 20) != id)
        return 0;
    if (LD32(p) != 0x0601B5CC)
        return 0;
    if (LDU16(p + 36) != 255)
        return 0;
    return i;
}

int f0601B582(int a, int b)
{
    gaddr p = 0x060D82CC;

    do {
        int v = LDU8(p);

        if (v != 0 && v != b && GCALL2(0x0601B514, a, v) != 0)
            return v;
    } while (AGAIN(++p < 0x060D82D4));
    return 0;
}

int f0601B5CC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r5 = 0x060C063D;
    r14 = 0x060D7768;
    r0 = LD16(0x060D7E68);
    r4 = LD32(0x060D7768);
    if (!(((r0 & 0xFFFF) & 1) == 0)) {
        r2 = LD8(r5);
        r0 = 36;
        r1 = LD16(36 + r4);
        if ((r1 & 0xFFFF) >= (r2 & 255)) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            SETSP((sp - 8));
            r0 = GCALL0(0x0601B662);
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0601BFC6);
            return r0;
        }
    } else {
        r2 = LD16(62 + r4);
        ST32(0x060D8318, (((short)((((r2 << 1) + r2) << 2) << 2)) + 0x060D831C));
        r1 = LD32(r14);
        r2 = LD8(r5);
        r3 = LD16(36 + r1);
        if ((r3 & 0xFFFF) >= (r2 & 255)) {
            ST16(0x060C0686, 0);
            ST16(0x060C0684, 0);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0601B630);
            r0 = GCALL0(0x0601BD4C);
            r4 = LD32(r14);
            r0 = LD16(r4 + 22);
            SETSP((sp - 8));
            r0 = GCALL1(0x0606948A, r0);
            SETSP((sp - 8));
            r0 = GCALL0(0x0601C0C8);
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 20);
            r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
            if (!(((r0 & 0xFFFF) & 7) == 0)) {
                POLL();
                ST32((sp - 4), PR());
                SETSP((sp - 4));
                SETPR(0x0601B990);
                r0 = GCALL1(0x060164E0, 26);
                SETSP((sp - 4));
                r0 = GCALL0(0x0601C534);
                r3 = LD32(0x060D7768);
                r0 = LD16(r3 + 20);
                r3 = (r0 & 0xFFFF) << 1;
                r0 = LD16(0x060EE8B0 + r3);
                ST16((0x060EE8B0 + r3), (r0 & 0xDFFF));
                SETPR(LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP1(0x060144F4, 0x0601B798);
                return r0;
            } else {
                r0 = LD8(r4 + 4);
                r0 = r0 & 255;
                if ((r0 & 64) == 0) {
                    return r0;
                } else {
                    POLL();
                    ST32((sp - 4), PR());
                    SETSP((sp - 4));
                    SETPR(0x0601B990);
                    r0 = GCALL1(0x060164E0, 26);
                    SETSP((sp - 4));
                    r0 = GCALL0(0x0601C534);
                    r3 = LD32(0x060D7768);
                    r0 = LD16(r3 + 20);
                    r3 = (r0 & 0xFFFF) << 1;
                    r0 = LD16(0x060EE8B0 + r3);
                    ST16((0x060EE8B0 + r3), (r0 & 0xDFFF));
                    SETPR(LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP1(0x060144F4, 0x0601B798);
                    return r0;
                }
            }
        } else {
            SETSP((sp - 8));
            r0 = GCALL0(0x0601B662);
            SETSP((sp - 8));
            r0 = GCALL0(0x0601B710);
            SETSP((sp - 8));
            r0 = GCALL0(0x0601BB8E);
            r3 = LD32(r14);
            r2 = LD32(100 + r3);
            SETSP((sp - 8));
            SETPR(0x0601B61E);
            r0 = GCALL4(r2, 0, 0, r6, r7);
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0601BFC6);
            return r0;
        }
    }
}

void f0601B662(void)
{
    gaddr rec = REC(LDU16(LD32(CURRENT) + 36));

    ST32(0x060D8310, rec);
    ST32(0x060D8314, OBJ(LDU16(rec + 22)));
    ST32(0x060D8318, 0x060D831C + (short)(LD16(LD32(CURRENT) + 62) * 48));
}

int f0601B6AE(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r2 = LD32(0x060D8314);
    r1 = LD16(50 + r2);
    if (!((r1 & r1) == 0)) {
        SETSP((sp - 4));
        SETPR(0x0601B6D2);
        r0 = GCALL0(0x0601BD4C);
    } else {
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 22);
        SETSP((sp - 4));
        SETPR(0x0601B6CA);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
    }
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x0601BBC2);
    return r0;
}

int f0601B6CA(void)
{
    return GJUMP0(0x0601B6D2);
}

void f0601B710(void)
{
    int i = LDU16(LD32(CURRENT) + 36);

    ST16(0x060C0684, LD16(0x26006096 + i * 2));
    i = LDU16(LD32(CURRENT) + 36);
    ST16(0x060C0686, LD16(0x260060B0 + i * 2));
    if (GCALL0(0x0601C150) == 0 && LD8(LD32(0x060D8310) + 6) == LD8(LD32(CURRENT) + 6)) {
        ST16(0x060C0684, LD16(0x060C0684) & 0xFFF);
        ST16(0x060C0686, LD16(0x060C0686) & 0xFFF);
    }
    POLL();
    GJUMP1(0x06015408, LDU16(LD32(CURRENT) + 36));
}

int f0601B798(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, c4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r13 = 0x060D8318;
    r3 = LD32(0x060D7768);
    r14 = 0x060D7B3C;
    r3 = LD16(62 + r3);
    ST32(0x060D8318, (((short)((((r3 << 1) + r3) << 2) << 2)) + 0x060D831C));
    r3 = LD32(0x060D7B3C);
    r2 = LD16(60 + r3);
    if ((r2 & 0xFFFF) == 0xFF00) {
        r8 = 0x060C381C;
        r9 = 12;
        r3 = LD32(r13);
        r2 = LD16(r3);
        r12 = 3;
        if ((r2 & r2) == 0) {
            SETSP((sp - 52));
            r0 = GCALL2(0x06008A6A, 8, 0);
            r11 = 0;
            do {
                SETSP((sp - 52));
                r0 = DIVS(r11, r12);
                ST8(sp - 48, r0);
                SETSP((sp - 52));
                r0 = MODS(r11, r12);
                ST32(sp - 40, r0);
                ST8(sp - 44, r0);
                r3 = LD32(r13);
                ST32((sp - 56), ((r11 << 1) + r3));
                r4 = LD32(r14);
                r0 = LD16(r4 + 4);
                SETSP((sp - 56));
                r0 = GCALL1(0x060691DA, r0);
                r0 = r0 & 0xFFFF;
                ST32(sp - 52, r0);
                r3 = LD32((sp - 56));
                ST16(r3, r0);
                r10 = LD32(sp - 52);
                r5 = LD32(sp - 40);
                r4 = LD32(sp - 52);
                r10 = (((r10 & 0xFFFF) * 84) & 0xFFFF) + r8;
                SETR(8, r8);
                SETR(9, r9);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 52));
                SETPR(0x0601B848);
                r0 = GCALL2(0x06068A8E, r4, (r5 + 122));
                r3 = LD32(r14);
                r1 = LD16(46 + r3);
                ST16(46 + r10, (r1 & 0x7FF));
                r0 = LD32(r14);
                r3 = LD16(r0 + 16);
                r0 = LD8(sp - 48);
                ST16(r10 + 16, ((((r0 & 255) << 2) + r3) - 6));
                r0 = LD8(sp - 48);
                SETSP((sp - 52));
                r0 = MODS((r0 & 255), 2);
                c4 = (r0 & r0) == 0;
                r0 = LD32(r14);
                if (c4) {
                    r2 = -6;
                } else {
                    r2 = 6;
                }
                r11 = r11 + 1;
                r3 = LD16(r0 + 18);
                r0 = LD8(sp - 44);
                ST16(r10 + 18, ((((((r0 & 255) << 2) << 1) + r3) + r2) - 16));
                r2 = LD32(r14);
                r3 = LD16(42 + r2);
                ST16(42 + r10, r3);
            } while (AGAIN(!(r11 >= r9)));
        }
        r0 = LD32(r13);
        r0 = LD8((r0 + 36));
        r0 = r0 & 255;
        if ((r0 & 64) == 0) {
            r7 = LD32(r13);
            r4 = 0;
            r3 = LD32(r14);
            r0 = LD16(r3 + 18);
            r7 = LD8((r7 + 36));
            r7 = (int)((unsigned)(r7 & 255) >> 2);
            ST16(r3 + 18, (r0 - r7));
            do {
                SETSP((sp - 52));
                r0 = MODS(r4, r12);
                r6 = r0 + 1;
                r0 = LD32(r13);
                r2 = LD16(r0 + (r4 << 1));
                r5 = r7 - (r6 & 255);
                r2 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r8;
                if (r5 >= 0) {
                    r3 = r5;
                } else {
                    r3 = 0;
                }
                r4 = r4 + 1;
                r0 = LD16(r2 + 18);
                r0 = r0 - r3;
                ST16(r2 + 18, r0);
            } while (AGAIN(!(r4 >= r9)));
            r3 = LD32(r13);
            r3 = r3 + 36;
            r2 = LD8(r3);
            ST8(r3, (r2 + 1));
        } else {
            r2 = LD32(r13);
            ST8((r2 + 24), 255);
        }
        r2 = LD32(r13);
        r3 = LD8((r2 + 24));
        if ((r3 & 255) == 255) {
            r1 = LD32(0x060D7768);
            r0 = LD16(62 + r1);
            ST8((0x060D82CC + (r0 & 0xFFFF)), 0);
            SETSP((sp - 52));
            r0 = GCALL0(0x0601C534);
            SETSP((sp - 52));
            r0 = GCALL0(0x060147BC);
            r2 = LD16(0x060D82D6);
            ST16(0x060D82D6, (r2 - 1));
        }
    } else {
        SETSP((sp - 52));
        r0 = GCALL0(0x0601C2A8);
        r0 = r0 & 0xFFFF;
        if (r0 >= 3) {
            r8 = 0x060C381C;
            r9 = 12;
            r3 = LD32(r13);
            r2 = LD16(r3);
            r12 = 3;
            if ((r2 & r2) == 0) {
                SETSP((sp - 52));
                r0 = GCALL2(0x06008A6A, 8, 0);
                r11 = 0;
                do {
                    SETSP((sp - 52));
                    r0 = DIVS(r11, r12);
                    ST8(sp - 48, r0);
                    SETSP((sp - 52));
                    r0 = MODS(r11, r12);
                    ST32(sp - 40, r0);
                    ST8(sp - 44, r0);
                    r3 = LD32(r13);
                    ST32((sp - 56), ((r11 << 1) + r3));
                    r4 = LD32(r14);
                    r0 = LD16(r4 + 4);
                    SETSP((sp - 56));
                    r0 = GCALL1(0x060691DA, r0);
                    r0 = r0 & 0xFFFF;
                    ST32(sp - 52, r0);
                    r3 = LD32((sp - 56));
                    ST16(r3, r0);
                    r10 = LD32(sp - 52);
                    r5 = LD32(sp - 40);
                    r4 = LD32(sp - 52);
                    r10 = (((r10 & 0xFFFF) * 84) & 0xFFFF) + r8;
                    SETR(8, r8);
                    SETR(9, r9);
                    SETR(10, r10);
                    SETR(11, r11);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 52));
                    SETPR(0x0601B848);
                    r0 = GCALL2(0x06068A8E, r4, (r5 + 122));
                    r3 = LD32(r14);
                    r1 = LD16(46 + r3);
                    ST16(46 + r10, (r1 & 0x7FF));
                    r0 = LD32(r14);
                    r3 = LD16(r0 + 16);
                    r0 = LD8(sp - 48);
                    ST16(r10 + 16, ((((r0 & 255) << 2) + r3) - 6));
                    r0 = LD8(sp - 48);
                    SETSP((sp - 52));
                    r0 = MODS((r0 & 255), 2);
                    c4 = (r0 & r0) == 0;
                    r0 = LD32(r14);
                    if (c4) {
                        r2 = -6;
                    } else {
                        r2 = 6;
                    }
                    r11 = r11 + 1;
                    r3 = LD16(r0 + 18);
                    r0 = LD8(sp - 44);
                    ST16(r10 + 18, ((((((r0 & 255) << 2) << 1) + r3) + r2) - 16));
                    r2 = LD32(r14);
                    r3 = LD16(42 + r2);
                    ST16(42 + r10, r3);
                } while (AGAIN(!(r11 >= r9)));
            }
            r0 = LD32(r13);
            r0 = LD8((r0 + 36));
            r0 = r0 & 255;
            if ((r0 & 64) == 0) {
                r7 = LD32(r13);
                r4 = 0;
                r3 = LD32(r14);
                r0 = LD16(r3 + 18);
                r7 = LD8((r7 + 36));
                r7 = (int)((unsigned)(r7 & 255) >> 2);
                ST16(r3 + 18, (r0 - r7));
                do {
                    SETSP((sp - 52));
                    r0 = MODS(r4, r12);
                    r6 = r0 + 1;
                    r0 = LD32(r13);
                    r2 = LD16(r0 + (r4 << 1));
                    r5 = r7 - (r6 & 255);
                    r2 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r8;
                    if (r5 >= 0) {
                        r3 = r5;
                    } else {
                        r3 = 0;
                    }
                    r4 = r4 + 1;
                    r0 = LD16(r2 + 18);
                    r0 = r0 - r3;
                    ST16(r2 + 18, r0);
                } while (AGAIN(!(r4 >= r9)));
                r3 = LD32(r13);
                r3 = r3 + 36;
                r2 = LD8(r3);
                ST8(r3, (r2 + 1));
            } else {
                r2 = LD32(r13);
                ST8((r2 + 24), 255);
            }
            r2 = LD32(r13);
            r3 = LD8((r2 + 24));
            if ((r3 & 255) == 255) {
                r1 = LD32(0x060D7768);
                r0 = LD16(62 + r1);
                ST8((0x060D82CC + (r0 & 0xFFFF)), 0);
                SETSP((sp - 52));
                r0 = GCALL0(0x0601C534);
                SETSP((sp - 52));
                r0 = GCALL0(0x060147BC);
                r2 = LD16(0x060D82D6);
                ST16(0x060D82D6, (r2 - 1));
            }
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

int f0601BA08(void)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r0 = 36;
    ST32((sp - 8), PR());
    r14 = 0x060C062C;
    r3 = LD16(0x060C062C);
    ST32(sp - 12, (r3 & 0xFFFF));
    r2 = LD32(0x060D7768);
    r3 = LD16(36 + r2);
    ST16(0x060C062C, r3);
    if (!(((r3 & 0xFFFF) & (r3 & 0xFFFF)) == 0)) {
        SETSP((sp - 12));
        r0 = GCALL0(0x0601ADA6);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x0601BA2E);
        r0 = GCALL0(0x0601B988);
        r0 = LD32(0x060D8310);
        r0 = LD16(r0 + 46);
        if (!(((r0 & 0xFFFF) & 16) == 0)) {
            SETSP((sp - 12));
            r0 = GCALL1(0x06009A3A, 30);
        }
        SETSP((sp - 12));
        r0 = GCALL0(0x0601AD82);
    }
    r3 = LD32(sp - 12);
    ST16(r14, r3);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0601BA54(void)
{
    int i = 0;
    int p;
    int slot;

    do {
        slot = (unsigned char)LD8(0x060D82CC + i);
        if (slot) {
            p = (OBJECTS + 0x30) + slot * 124;
            if (!(LD8(p + 4) & 192) && LDU16(p + 36) == 255)
                ST8(p + 4, LD8(p + 4) | 64);
        }
    } while (AGAIN(++i < 8));
}

void f0601BAA0(void)
{
    if (LD16(LD32(CURRENT) + 36) == 0)
        return;
    GCALL0(0x0601ADA6);
    GCALL0(0x0601C534);
    ST8(LD32(CURRENT) + 6, 2);
    ST16(LD32(CURRENT) + 88, 0);
    GCALL0(0x0601AD82);
    POLL();
    GJUMP2(0x060144E4, LDU16(LD32(CURRENT) + 36), 0x0601BB08);
}

int f0601BB08(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r14 = LD32(0x060D7768);
    r2 = LD16(36 + r14);
    r1 = LD8(0x060C063D);
    if (!((r2 & 0xFFFF) >= (r1 & 255))) {
        r0 = LD16(r14 + 22);
        r4 = LD16(36 + r14);
        r4 = LD16(0x060D5F46 + ((r4 & 0xFFFF) * 124));
        SETSP((sp - 12));
        r0 = GCALL2(0x0600A3D8, (r4 & 0xFFFF), (r0 & 0xFFFF));
    }
    r0 = LD16(0x060D7E68);
    if (((r0 & 0xFFFF) & 16) == 0) {
        SETSP((sp - 12));
        SETPR(0x0601BB56);
        r0 = GCALL1(0x060164E0, 25);
        r4 = 33;
    } else {
        SETSP((sp - 12));
        SETPR(0x0601BB4C);
        r0 = GCALL1(0x060165B8, 0);
        r4 = 34;
    }
    SETSP((sp - 12));
    SETPR(0x0601BB5C);
    r0 = GCALL1(0x0601BCE6, r4);
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x0601BB68);
    return r0;
}

int f0601BB68(void)
{
    if (LDU16(LD32(CURRENT) + 36) >= (unsigned char)LD8(0x060C063D))
        return 36;
    GCALL0(0x0601B662);
    return GJUMP1(0x0601BF0C, 2);
}

void f0601BB8E(void)
{
    ST8(LD32(CURRENT) + 6, LD8(LD32(0x060D8310) + 6));
    ST16(LD32(CURRENT) + 18, LD16(LD32(0x060D8310) + 18));
}

void f0601BBA4(void)
{
    gaddr t = LD32(CURRENT);

    ST16(t + 76, 0);
    ST16(t + 78, 0);
    ST16(t + 80, 0);
}

void f0601BBC2(void)
{
    gaddr t = LD32(CURRENT);

    if (!(LDU16(0x060C0684) & LDU16(0x060BF5E6))) {
        if (!LD16(t + 80)) {
            ST16(t + 78, 0);
        } else {
            ST16(t + 80, 0);
            ST16(LD32(CURRENT) + 78, LD16(0x060BF5E6));
        }
    } else if (!LD16(t + 80)) {
        ST16(t + 76, 1);
        ST16(LD32(CURRENT) + 80, LD16(0x060BF5E6));
    } else if (LDU16(t + 76) < 120) {
        ST16(t + 76, LD16(t + 76) + 1);
    }
}

int f0601BC58(void)
{
    int a, b;

    GCALL2(0x06008A6A, 1, 0);
    a = LD16(LD32(0x060D7B3C) + 46);
    b = LD16(LD32(CURRENT) + 64);
    return GJUMP2(0x06008ECA, b + 15, a & 0x7FF);
}

void f0601BC7E(void)
{
    if (LD16(LD32(CURRENT) + 36) == 0)
        return;
    GCALL0(0x0601ADA6);
    GCALL0(0x0601BC58);
    GJUMP0(0x0601AD82);
}

int f0601BC9E(int a, int b, int c)
{
    int bits;

    if (LD16(LD32(CURRENT) + 36) == 0)
        return 0;
    GCALL0(0x0601ADA6);
    bits = LDU16(LD32(MOVER_PTR) + 46) & 0x7FF;
    GCALL5(0x060090C2, bits, bits + 15, a, b, c);
    return GJUMP0(0x0601AD82);
}

int f0601BCE6(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    r0 = 36;
    ST32((sp - 4), PR());
    ST32(sp - 8, r4);
    r4 = LD32(0x060D7768);
    r2 = LD16(36 + r4);
    r1 = LD8(0x060C063D);
    if ((r2 & 0xFFFF) >= (r1 & 255)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        ST8(r4 + 6, 2);
        SETSP((sp - 8));
        r0 = GCALL0(0x0601B662);
        SETSP((sp - 8));
        r0 = GCALL1(0x0601BF0C, 2);
        SETSP((sp - 8));
        r0 = GCALL0(0x0601AE68);
        r4 = LD32(sp - 8);
        SETSP((sp - 8));
        SETPR(0x0601BD16);
        r0 = GCALL1(0x060164E0, r4);
        SETSP((sp - 8));
        r0 = GCALL1(0x06016776, 2);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0601AE68);
        return r0;
    }
}

int f0601BD4C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r11 = 0x060D8310;
    r13 = 0x060D7B3C;
    r14 = 0x060D7768;
    r3 = LD16(0x060C0684);
    r12 = 0;
    if (!(((r3 & 0xFFFF) & 0xF000) == 0)) {
        r3 = LD32(r14);
        r0 = LD16(54 + r3);
        if (!((r0 & r0) == 0)) {
            r2 = LD32(r14);
            ST16(54 + r2, r12);
            r3 = LD32(r11);
            r2 = LD16(46 + r3);
            if (((r2 & 0xFFFF) & 0x4000) == 0) {
                r2 = LD32(r13);
                ST16(60 + r2, r12);
            }
        }
        r3 = LD32(r13);
        r2 = LD32(0x060D8314);
        r0 = LD16(62 + r2);
        ST16((62 + r3), r0);
        r5 = LD32(r13);
        r3 = LD32(r14);
        r5 = LD16(48 + r5);
        r2 = LD16(48 + r3);
        r4 = LD32(r14);
        r3 = LD32(r11);
        SETPR(LD32((sp - 20)));
        r0 = LD8(r3 + 6);
        SETR(11, LD32((sp - 16)));
        r5 = ((r5 & 0xFFFF) + (r2 & 0xFFFF)) + (r0 & 255);
        SETR(12, LD32((sp - 12)));
        r0 = LD16(r4 + 22);
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), r5);
        return r0;
    } else {
        SETSP((sp - 20));
        r0 = GCALL0(0x060162D0);
        if ((r0 & r0) == 0) {
            r2 = LD32(r14);
            r0 = LD16(54 + r2);
            if (!((r0 & r0) == 0)) {
                r3 = LD32(r14);
                r2 = LD16(54 + r3);
                if (!((r2 & 0xFFFF) >= 0x12C)) {
                    r1 = LD32(r14);
                    r2 = LD16(36 + r1);
                    if ((r2 & 0xFFFF) == 255) {
                        r2 = LD32(r14);
                        r3 = LD16(54 + r2);
                        ST16(54 + r2, (r3 + 1));
                    }
                    SETR(12, r12);
                    SETR(13, r13);
                    SETSP((sp - 20));
                    SETPR(0x0601BE04);
                    r0 = GCALL1(0x06016574, 0x2710);
                    r3 = LD32(r13);
                    r0 = 62;
                    ST16(62 + r3, r12);
                    SETPR(LD32((sp - 20)));
                    SETR(11, LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    SETSP((sp - 20));
                    SETPR(0x0601BDD6);
                    r0 = GCALL1(0x060164E0, 34);
                    SETPR(LD32((sp - 20)));
                    SETR(11, LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP1(0x0601BCE6, 30);
                    return r0;
                }
            } else {
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP1(0x060165B8, 0x2710);
                return r0;
            }
        } else {
            r0 = LD32(0x060D8310);
            r0 = LD8(r0 + 4);
            if (!(((r0 & 255) & 32) == 0)) {
                r2 = LD32(r14);
                r0 = LD16(54 + r2);
                if (!((r0 & r0) == 0)) {
                    r3 = LD32(r14);
                    r2 = LD16(54 + r3);
                    if (!((r2 & 0xFFFF) >= 0x12C)) {
                        r1 = LD32(r14);
                        r2 = LD16(36 + r1);
                        if ((r2 & 0xFFFF) == 255) {
                            r2 = LD32(r14);
                            r3 = LD16(54 + r2);
                            ST16(54 + r2, (r3 + 1));
                        }
                        SETR(12, r12);
                        SETR(13, r13);
                        SETSP((sp - 20));
                        SETPR(0x0601BE04);
                        r0 = GCALL1(0x06016574, 0x2710);
                        r3 = LD32(r13);
                        r0 = 62;
                        ST16(62 + r3, r12);
                        SETPR(LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        SETSP((sp - 20));
                        SETPR(0x0601BDD6);
                        r0 = GCALL1(0x060164E0, 34);
                        SETPR(LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP1(0x0601BCE6, 30);
                        return r0;
                    }
                } else {
                    SETPR(LD32((sp - 20)));
                    SETR(11, LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP1(0x060165B8, 0x2710);
                    return r0;
                }
            } else {
                r3 = LD32(0x060D7768);
                r0 = LD16(36 + r3);
                r2 = LD16(((r0 & 0xFFFF) << 1) + 0x26006096);
                if (!((r2 & r2) == 0)) {
                    r2 = LD32(r14);
                    r0 = LD16(54 + r2);
                    if (!((r0 & r0) == 0)) {
                        r3 = LD32(r14);
                        r2 = LD16(54 + r3);
                        if (!((r2 & 0xFFFF) >= 0x12C)) {
                            r1 = LD32(r14);
                            r2 = LD16(36 + r1);
                            if ((r2 & 0xFFFF) == 255) {
                                r2 = LD32(r14);
                                r3 = LD16(54 + r2);
                                ST16(54 + r2, (r3 + 1));
                            }
                            SETR(12, r12);
                            SETR(13, r13);
                            SETSP((sp - 20));
                            SETPR(0x0601BE04);
                            r0 = GCALL1(0x06016574, 0x2710);
                            r3 = LD32(r13);
                            r0 = 62;
                            ST16(62 + r3, r12);
                            SETPR(LD32((sp - 20)));
                            SETR(11, LD32((sp - 16)));
                            SETR(12, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        } else {
                            SETSP((sp - 20));
                            SETPR(0x0601BDD6);
                            r0 = GCALL1(0x060164E0, 34);
                            SETPR(LD32((sp - 20)));
                            SETR(11, LD32((sp - 16)));
                            SETR(12, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            UNFRAME(sp);
                            r0 = GJUMP1(0x0601BCE6, 30);
                            return r0;
                        }
                    } else {
                        SETPR(LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP1(0x060165B8, 0x2710);
                        return r0;
                    }
                } else {
                    SETR(11, r11);
                    SETSP((sp - 20));
                    SETPR(0x0601BD9A);
                    r0 = GCALL1(0x060164E0, 33);
                    SETR(11, r11);
                    SETSP((sp - 20));
                    SETPR(0x0601BD9E);
                    r0 = GCALL1(0x0601BCE6, 30);
                    r0 = 2;
                    r3 = LD32(r11);
                    ST8(r3 + 6, 2);
                    SETPR(LD32((sp - 20)));
                    SETR(11, LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                }
            }
        }
    }
}

int f0601BEA8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32(sp - 8, r4);
    r3 = LD32(0x060D7768);
    r0 = LD16(36 + r3);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r1 = 0x2710;
        r0 = LD32(sp - 8);
        if (!(r0 == 0x2710)) {
            SETSP((sp - 8));
            r0 = GCALL0(0x0601ADA6);
            r2 = LD32(0x060D7768);
            ST32(100 + r2, 0x060143D8);
            r4 = LD32(sp - 8);
            SETSP((sp - 8));
            SETPR(0x0601BEF0);
            r0 = GCALL1(0x060164E0, r4);
            r2 = LD32(0x060D8310);
            ST8(r2 + 6, 2);
            SETSP((sp - 8));
            SETPR(0x0601BEFC);
            r0 = GCALL1(0x0601BCE6, 30);
        } else {
            SETSP((sp - 8));
            SETPR(0x0601BEC8);
            r0 = GCALL1(0x060165B8, r1);
            SETSP((sp - 8));
            r0 = GCALL0(0x0601ADA6);
            SETSP((sp - 8));
            SETPR(0x0601BED4);
            r0 = GCALL0(0x0601AE84);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0601AD82);
        return r0;
    }
}

int f0601BEC8(void)
{
    GCALL0(0x0601ADA6);
    GCALL0(0x0601AE84);
    return GJUMP0(0x0601BEFC);
}

int f0601BED4(void)
{
    return GJUMP0(0x0601BEFC);
}

void f0601BF0C(int dir)
{
    GCALL2(0x06069462, LD16(LD32(CURRENT) + 22), LD16(LD32(0x060D8314) + 4));
    if (LD16(LD32(CURRENT) + 88))
        return;
    GJUMP3(0x060693DC, LDU16(LD32(CURRENT) + 22), LDU16(LD32(0x060D8310) + 22), LD8(0x060B4700 + dir - 1));
}

void f0601BF94(int arg)
{
    if (!(LDU16(LD32(CURRENT) + 46) & 0x800))
        return;
    GCALL0(0x0601ADA6);
    GCALL1(0x0601BF0C, arg);
    GJUMP0(0x0601AD82);
}

void f0601BFC6(void)
{
    gaddr cell;
    gaddr mover;

    ST16(LD32(CURRENT) + 54, LD16(LD32(0x060D8310) + 54));
    cell = 0x060EE8B0 + LDU16(LD32(CURRENT) + 20) * 2;
    ST16(cell, LD16(cell) & 0xDFFF);
    if (LDU16(LD32(0x060D8310) + 46) & 0x800) {
        GCALL1(0x0601BF0C, LDU8(LD32(CURRENT) + 6));
        GCALL2(0x0600A3D8, LDU16(LD32(0x060D8310) + 22), LDU16(LD32(CURRENT) + 22));
    }
    GCALL0(0x0601C0C8);
    mover = LD32(MOVER_PTR);
    if (LDU16(LD32(CURRENT) + 36) < LDU8(BOMBER_COUNT)
        && (LDU16(LD32(0x060D8314) + 68) != 0x100 || LDU16(LD32(0x060D8314) + 70) != 0x100)) {
        GCALL2(0x0606AAC8, mover, 3);
        ST16(LD32(MOVER_PTR) + 68, LD16(LD32(0x060D8314) + 68));
        ST16(LD32(MOVER_PTR) + 70, LD16(LD32(0x060D8314) + 70));
    } else {
        GCALL2(0x0606AAC8, mover, 0);
        ST16(LD32(MOVER_PTR) + 70, 0x100);
        ST16(LD32(MOVER_PTR) + 68, 0x100);
    }
    GJUMP1(0x060149E0, LDU16(0x060C062C));
}

void f0601C0C8(void)
{
    gaddr cur = LD32(0x060D7768);
    gaddr flags;

    ST16(cur + 20, GCALL0(0x0600CA7C));
    cur = LD32(0x060D7768);
    flags = 0x060EE8B0 + (LDU16(cur + 20) << 1);
    ST16(flags, LD16(flags) | 0x2000);
    if (LDU16(cur + 36) < (LD8(0x060C063D) & 255) && (LDU16(LD32(0x060D8310) + 46) & 0x128)) {
        ST16(flags, LD16(flags) & 0xDFFF);
        ST8(cur + 4, LD8(cur + 4) & 191);
    }
    ST16(cur + 24, LD16(0x060D7E88));
    ST16(cur + 26, LD16(LD32(MOVER_PTR) + 12));
    ST16(cur + 28, LD16(0x060D7E8A));
    ST16(cur + 30, LD16(LD32(MOVER_PTR) + 14));
}

int f0601C150(void)
{
    gaddr mover = LD32(0x060D7B3C);
    gaddr other = LD32(0x060D8314);

    if (LD16(mover + 16) != LD16(other + 16))
        return 1;
    if (LD16(other + 12))
        return 1;
    if (LD16(mover + 18) != LD16(other + 18))
        return 1;
    return LD16(other + 14) != 0;
}

int f0601C182(int n)
{
    gaddr list = LD32(0x060D8318);

    if (LD16(list + n * 2) == 0)
        return 0;
    GCALL2(0x0600A3D8, LDU16(LD32(CURRENT) + 22), LDU16(list + n * 2));
    return GJUMP1(0x0606948A, LD16(LD32(0x060D8318) + n * 2));
}

int f0601C1C6(void)
{
    unsigned int i = 0;
    int result;

    do {
        result = GCALL1(0x0601C182, i);
        i++;
    } while (AGAIN(i < 12));
    return result;
}

int f0601C21C(void)
{
    GCALL1(0x0600A2B0, LD32(0x060B4704 + (LD8(LD32(0x060D8310) + 6) & 255) * 4));
    return GJUMP1(0x0600A32A, LD32(0x060B4718 + (LD8(LD32(0x060D8310) + 6) & 255) * 4));
}

void f0601C244(int forward)
{
    gaddr obj = OBJ(LDU16(0x060C1AAA));

    if (forward) {
        ST16(obj + 16, LD16(obj + 16) + LD16(0x060B4740 + LDU8(LD32(0x060D8310) + 6) * 2));
        ST16(obj + 18, LD16(obj + 18) + LD16(0x060B474A + LDU8(LD32(0x060D8310) + 6) * 2));
    } else {
        ST16(obj + 16, LD16(obj + 16) + LD16(0x060B472C + LDU8(LD32(0x060D8310) + 6) * 2));
        ST16(obj + 18, LD16(obj + 18) + LD16(0x060B4736 + LDU8(LD32(0x060D8310) + 6) * 2));
    }
}

int f0601C2A8(void)
{
    gaddr mover = LD32(MOVER_PTR);
    int d = LD32(mover + 56) - LD32(mover + 52);

    return (d / 2 >> 1) + 0xFFFF;
}

void f0601C2C2(int id)
{
    int dir = LDU8(LD32(0x060D8310) + 6);
    gaddr other = LD32(0x060D8314);
    int target;

    if (dir == 1 || dir == 3)
        target = LD16(other + 4) + 8;
    else if (dir == 4)
        target = LD16(other + 4) - 1;
    else
        target = 228;
    if (id)
        GJUMP2(0x06069462, id, target);
}

int f0601C34C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    r3 = LD32(0x060D7768);
    ST32(100 + r3, 0x060154A4);
    r3 = LD32(0x060D7768);
    ST32(104 + r3, 0x060143D8);
    r3 = LD32(0x060D7768);
    ST32(108 + r3, 0x06015CD2);
    r3 = LD32(0x060D7768);
    r1 = LD16(46 + r3);
    ST16(46 + r3, (r1 | 0x200));
    r3 = LD32(0x060D7768);
    ST16(54 + r3, 0);
    UNFRAME(sp);
    r0 = GJUMP1(0x06016574, 0x2710);
    return r0;
}

int f0601C3BE(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = r4;
    SETSP((sp - 8));
    r0 = GCALL0(0x0601AE68);
    r4 = LD32(0x060D7768);
    r4 = LD16(48 + r4);
    SETR(14, r14);
    SETSP((sp - 8));
    SETPR(0x0601C3D8);
    r0 = GCALL1(0x060164E0, ((r4 & 0xFFFF) + r14));
    SETSP((sp - 8));
    r0 = GCALL1(0x06016776, r14);
    SETSP((sp - 8));
    r0 = GCALL0(0x0601AE68);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0601BF0C, r14);
    return r0;
}

void f0601C440(void)
{
    int step = (unsigned short)GCALL0(0x0601C2A8) ? 0 : 2;
    gaddr mover;

    POLL();
    GCALL0(0x0601AE68);
    GCALL1(0x06016776, LDU8(LD32(CURRENT) + 6));
    mover = LD32(MOVER_PTR);
    if (LDU8(LD32(CURRENT) + 6) == 1)
        ST16(mover + 36, LD16(mover + 36) - step);
    else if (LDU8(LD32(CURRENT) + 6) == 3)
        ST16(mover + 36, LD16(mover + 36) + step);
    GJUMP0(0x0601AE68);
}

void f0601C510(int i)
{
    int w = LDU16(LD32(0x060D8318) + i * 2);

    if (w != 0)
        GCALL1(0x060692DC, w);
    POLL();
    GJUMP1(0x0601AEC2, i);
}

void f0601C534(void)
{
    int i = 0;

    do {
        GCALL1(0x0601C510, i);
    } while (AGAIN(++i < 12));
}

int f0601C550(void)
{
    int r0, r4, r5, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = 0;
    ST32((sp - 8), R(13));
    r13 = 24;
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    r9 = 0x06068A8E;
    r10 = 0x060D7768;
    r11 = 0x060C381C;
    r12 = 0x060D8318;
    do {
        r0 = LD32(r12);
        r4 = LD16(r0 + r14);
        r4 = r4 & 0xFFFF;
        if (!((r4 & r4) == 0)) {
            r5 = LD32(r10);
            r0 = LD16(r5 + 22);
            r5 = LD16(50 + ((((r0 & 0xFFFF) * 84) & 0xFFFF) + r11));
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 32));
            SETPR(0x0601C58C);
            r0 = GCALL2(r9, r4, (r5 & 0xFFFF));
        }
        r14 = r14 + 2;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r13)));
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

void f0601C620(gaddr out_a, gaddr out_b)
{
    gaddr rec = REC(LDU16(LD32(CURRENT) + 36));
    unsigned int v;

    ST32(0x060D8310, rec);
    ST32(out_a, (LDU16(rec + 52) << 1) + 2);
    v = (LDU16(LD32(0x060D8310) + 76) >> 2) + 2;
    ST32(out_b, v);
    if (v > 6)
        ST32(out_b, 6);
}

int f0601C83E(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0601ADA6);
    SETSP((sp - 4));
    SETPR(0x0601C84C);
    r0 = GCALL1(0x06016574, 4);
    r3 = LD32(0x060D7768);
    ST32(100 + r3, 0x0601C8A0);
    r3 = LD32(0x060D7768);
    r2 = LD32(0x060D8314);
    r2 = LD16(38 + r2);
    ST16(58 + r3, r2);
    r3 = LD32(0x060D7768);
    ST16(88 + r3, 1);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x0601AD82);
    return r0;
}

int f0601C8A0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD32(0x060D7B3C);
    r2 = LD32(0x060D8314);
    r1 = LD32(0x060D7768);
    r1 = LD16(58 + r1);
    r2 = LD16(38 + r2);
    ST16(38 + r3, (r2 - r1));
    SETSP((sp - 4));
    r0 = GCALL0(0x0601BBA4);
    r0 = LD32(0x060D8310);
    r0 = LD16(r0 + 46);
    r0 = r0 & 0xFFFF;
    if (!((r0 & 8) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0601AE84);
        return r0;
    }
}

int f0601C8D8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r14 = 0x060D7768;
    ST32(sp - 20, r6);
    ST32(sp - 16, r7);
    r3 = LD16(0x060C062C);
    r3 = ((r3 & 0xFFFF) * 124) + 0x060D5F30;
    ST32(0x060D7768, r3);
    r0 = LD16(r3 + 22);
    ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
    if ((r5 & r5) == 0) {
        r3 = LD32(r14);
        r0 = LD8(r3 + 6);
        r5 = r0 & 255;
    }
    r2 = LD32(sp);
    ST32((sp - 24), r2);
    r3 = LD32(sp - 16);
    ST32((sp - 28), r3);
    r7 = LD32(sp - 20);
    SETR(14, r14);
    SETSP((sp - 28));
    SETPR(0x0601C926);
    r0 = GCALL4(0x060182DE, r4, r5, 0, r7);
    r3 = LD32(r14);
    r2 = 0x0601C9CC;
    r0 = LD8(r3 + 4);
    ST8(r3 + 4, (r0 & 191));
    r3 = LD32(r14);
    r1 = LD32(r3);
    if (r1 == 0x0601C9CC) {
        r0 = 0;
    } else {
        SETSP((sp - 20));
        r0 = GCALL1(0x06014516, r2);
        r0 = 1;
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0601C950(int r4, int r5)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), 1);
    SETSP((sp - 8));
    SETPR(0x0601C95C);
    r0 = GCALL4(0x0601C8D8, r4, r5, 4, 0);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0601C964(int r4, int r5, int r6)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32(sp - 12, r5);
    ST32(sp - 8, r6);
    SETSP((sp - 12));
    r0 = GCALL2(0x0601B582, r4, 0);
    r5 = r0;
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        ST16(0x060C062C, r5);
        r5 = LD32(sp - 8);
        r4 = LD32(sp - 12);
        SETSP((sp - 12));
        SETPR(0x0601C984);
        r0 = GCALL2(0x0601C950, r4, r5);
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 4)));
            return 0;
        } else {
            SETPR(LD32((sp - 4)));
            return 1;
        }
    }
}

int f0601CB04(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    r3 = LD16(0x060C0686);
    if (!(((r3 & 0xFFFF) & 0xF000) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0601C382);
        return r0;
    } else {
        r0 = LD32(0x060D7B3C);
        r0 = LD32(r0 + 56);
        r0 = LD16(r0);
        if (!(r0 == -1)) {
            r3 = LD32(0x060D7768);
            r2 = LD16(52 + r3);
            r0 = LD8(r3 + 6);
            r8 = (((r2 & 0xFFFF) << 2) << 2) + (((r0 & 255) - 1) << 2);
            SETSP((sp - 16));
            r0 = GCALL0(0x0601C2A8);
            r3 = LD16(0x060B4754 + ((r8 + (r0 & 0xFFFF)) << 1));
            ST16(sp - 16, r3);
            r2 = LD32(0x060D7768);
            ST16(88 + r2, 0);
            r0 = LD32(0x060D7768);
            r0 = LD8(r0 + 6);
            r3 = LD16(sp - 16);
            SETR(14, 0x060D7768);
            SETSP((sp - 16));
            SETPR(0x0601CB74);
            r0 = GCALL1(0x0601C3BE, ((3 & (((r0 & 255) + (r3 & 0xFFFF)) - 1)) + 1));
            r2 = LD32(0x060D7768);
            ST16(88 + r2, 1);
            SETPR(LD32((sp - 12)));
            SETR(8, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 88;
        } else {
            SETPR(LD32((sp - 12)));
            SETR(8, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0601C382);
            return r0;
        }
    }
}

int f0601CCA4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    r14 = 0x060D8310;
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r4 = LD32(0x060D8310);
    r5 = LD16(46 + r4);
    r5 = r5 & 0xFFFF;
    if (!((16 & r5) == 0)) {
        if (!((0x4000 & r5) == 0)) {
            r13 = 0x060D7768;
            r1 = LD16(56 + r4);
            if ((r1 & r1) == 0) {
                r0 = LD32(r13);
                r0 = LD16(r0 + 52);
                r0 = r0 & 0xFFFF;
                if (r0 == 2) {
                    r12 = LD32(0x060D8318);
                    r4 = LD32(r13);
                    r12 = LD16(r12);
                    r0 = LD16(r4 + 22);
                    r12 = r12 & 0xFFFF;
                    SETSP((sp - 32));
                    r0 = GCALL2(0x0600A3D8, (r0 & 0xFFFF), r12);
                    r5 = LD16(0x060C062C);
                    SETSP((sp - 32));
                    r0 = GCALL2(0x060148AE, r12, (r5 & 0xFFFF));
                    r11 = LD32(r14);
                    r0 = LD16(0x060C0630);
                    r10 = LD32(r14);
                    r4 = 3 & (r0 & 0xFFFF);
                    r0 = LD16(r11 + 24);
                    r4 = ((r4 + 1) << 2) << 1;
                    r5 = (((r12 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
                    r11 = r0 & 0xFFFF;
                    r0 = LD16(r10 + 28);
                    r10 = r0 & 0xFFFF;
                    r0 = LD32(r14);
                    r0 = LD8(r0 + 6);
                    r0 = r0 & 255;
                    r6 = r4 + 8;
                    if (r0 == 1) {
                        r0 = LD16(r5 + 16);
                        ST16(r5 + 16, (r0 - r4));
                        r11 = r11 - r6;
                    } else {
                        if (r0 == 2) {
                            r0 = LD16(r5 + 18);
                            ST16(r5 + 18, (r0 - r4));
                            r10 = r10 - r6;
                        } else {
                            if (r0 == 3) {
                                r0 = LD16(r5 + 16);
                                ST16(r5 + 16, (r0 + r4));
                                r11 = r11 + r6;
                            } else {
                                if (r0 == 4) {
                                    r0 = LD16(r5 + 18);
                                    r10 = r10 + r6;
                                    ST16(r5 + 18, (r0 + r4));
                                }
                            }
                        }
                    }
                    r0 = LD32(r14);
                    r0 = LD8(r0 + 6);
                    ST32(sp - 32, ((((r0 & 255) - 1) ^ 2) + 1));
                    SETSP((sp - 32));
                    r0 = GCALL2(0x0600CAE4, r11, r10);
                    r1 = 0x060EC8B0;
                    r0 = LD16((r0 << 1) + 0x060EC8B0);
                    if (!(((r0 & 0xFFFF) & 184) == 0)) {
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 32));
                        SETPR(0x0601CE22);
                        r0 = GCALL2(0x06068A8E, r12, 0);
                    } else {
                        r2 = LD32(sp - 32);
                        r0 = LD32(0x060D8310);
                        r0 = LD16(r0 + 20);
                        r3 = r0 & 0xFFFF;
                        r0 = LD16(0x060B47F0 + (r2 << 1));
                        r0 = LD16(((r0 + r3) << 1) + r1);
                        if (((r0 & 0xFFFF) & 184) == 0) {
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 32));
                            SETPR(0x0601CE2A);
                            r0 = GCALL0(0x0601C550);
                        } else {
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 32));
                            SETPR(0x0601CE22);
                            r0 = GCALL2(0x06068A8E, r12, 0);
                        }
                    }
                    r2 = LD32(r13);
                    r3 = LD16(58 + r2);
                    r2 = LD32(r14);
                    r0 = LD8(r2 + 6);
                    r0 = r0 & 255;
                    if ((r3 & 0xFFFF) == r0) {
                        SETMACL(LD32((sp - 28)));
                        SETPR(LD32((sp - 24)));
                        SETR(10, LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 32));
                        SETPR(0x0601CE42);
                        r0 = GCALL1(0x06016574, 16);
                        r3 = LD32(r13);
                        r2 = LD32(r14);
                        r0 = LD8(r2 + 6);
                        ST16((58 + r3), (r0 & 255));
                        r4 = LD32(r13);
                        r4 = LD16(52 + r4);
                        SETMACL(LD32((sp - 28)));
                        SETPR(LD32((sp - 24)));
                        SETR(10, LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP1(0x0600996A, ((r4 & 0xFFFF) + 27));
                        return r0;
                    }
                } else {
                    SETMACL(LD32((sp - 28)));
                    SETPR(LD32((sp - 24)));
                    SETR(10, LD32((sp - 20)));
                    SETR(11, LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                }
            } else {
                SETSP((sp - 32));
                r0 = GCALL0(0x0601C534);
                SETR(13, r13);
                SETSP((sp - 32));
                SETPR(0x0601CCEE);
                r0 = GCALL1(0x06016574, 20);
                r3 = LD32(r13);
                ST32(100 + r3, 0x0601CE94);
                SETMACL(LD32((sp - 28)));
                SETPR(LD32((sp - 24)));
                SETR(10, LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP1(0x0600996A, 31);
                return r0;
            }
        } else {
            r3 = LD16(42 + r4);
            if ((r3 & r3) == 0) {
                r13 = 0x060D7768;
                r1 = LD16(56 + r4);
                if ((r1 & r1) == 0) {
                    r0 = LD32(r13);
                    r0 = LD16(r0 + 52);
                    r0 = r0 & 0xFFFF;
                    if (r0 == 2) {
                        r12 = LD32(0x060D8318);
                        r4 = LD32(r13);
                        r12 = LD16(r12);
                        r0 = LD16(r4 + 22);
                        r12 = r12 & 0xFFFF;
                        SETSP((sp - 32));
                        r0 = GCALL2(0x0600A3D8, (r0 & 0xFFFF), r12);
                        r5 = LD16(0x060C062C);
                        SETSP((sp - 32));
                        r0 = GCALL2(0x060148AE, r12, (r5 & 0xFFFF));
                        r11 = LD32(r14);
                        r0 = LD16(0x060C0630);
                        r10 = LD32(r14);
                        r4 = 3 & (r0 & 0xFFFF);
                        r0 = LD16(r11 + 24);
                        r4 = ((r4 + 1) << 2) << 1;
                        r5 = (((r12 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
                        r11 = r0 & 0xFFFF;
                        r0 = LD16(r10 + 28);
                        r10 = r0 & 0xFFFF;
                        r0 = LD32(r14);
                        r0 = LD8(r0 + 6);
                        r0 = r0 & 255;
                        r6 = r4 + 8;
                        if (r0 == 1) {
                            r0 = LD16(r5 + 16);
                            ST16(r5 + 16, (r0 - r4));
                            r11 = r11 - r6;
                        } else {
                            if (r0 == 2) {
                                r0 = LD16(r5 + 18);
                                ST16(r5 + 18, (r0 - r4));
                                r10 = r10 - r6;
                            } else {
                                if (r0 == 3) {
                                    r0 = LD16(r5 + 16);
                                    ST16(r5 + 16, (r0 + r4));
                                    r11 = r11 + r6;
                                } else {
                                    if (r0 == 4) {
                                        r0 = LD16(r5 + 18);
                                        r10 = r10 + r6;
                                        ST16(r5 + 18, (r0 + r4));
                                    }
                                }
                            }
                        }
                        r0 = LD32(r14);
                        r0 = LD8(r0 + 6);
                        ST32(sp - 32, ((((r0 & 255) - 1) ^ 2) + 1));
                        SETSP((sp - 32));
                        r0 = GCALL2(0x0600CAE4, r11, r10);
                        r1 = 0x060EC8B0;
                        r0 = LD16((r0 << 1) + 0x060EC8B0);
                        if (!(((r0 & 0xFFFF) & 184) == 0)) {
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 32));
                            SETPR(0x0601CE22);
                            r0 = GCALL2(0x06068A8E, r12, 0);
                        } else {
                            r2 = LD32(sp - 32);
                            r0 = LD32(0x060D8310);
                            r0 = LD16(r0 + 20);
                            r3 = r0 & 0xFFFF;
                            r0 = LD16(0x060B47F0 + (r2 << 1));
                            r0 = LD16(((r0 + r3) << 1) + r1);
                            if (((r0 & 0xFFFF) & 184) == 0) {
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 32));
                                SETPR(0x0601CE2A);
                                r0 = GCALL0(0x0601C550);
                            } else {
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 32));
                                SETPR(0x0601CE22);
                                r0 = GCALL2(0x06068A8E, r12, 0);
                            }
                        }
                        r2 = LD32(r13);
                        r3 = LD16(58 + r2);
                        r2 = LD32(r14);
                        r0 = LD8(r2 + 6);
                        r0 = r0 & 255;
                        if ((r3 & 0xFFFF) == r0) {
                            SETMACL(LD32((sp - 28)));
                            SETPR(LD32((sp - 24)));
                            SETR(10, LD32((sp - 20)));
                            SETR(11, LD32((sp - 16)));
                            SETR(12, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        } else {
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 32));
                            SETPR(0x0601CE42);
                            r0 = GCALL1(0x06016574, 16);
                            r3 = LD32(r13);
                            r2 = LD32(r14);
                            r0 = LD8(r2 + 6);
                            ST16((58 + r3), (r0 & 255));
                            r4 = LD32(r13);
                            r4 = LD16(52 + r4);
                            SETMACL(LD32((sp - 28)));
                            SETPR(LD32((sp - 24)));
                            SETR(10, LD32((sp - 20)));
                            SETR(11, LD32((sp - 16)));
                            SETR(12, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            UNFRAME(sp);
                            r0 = GJUMP1(0x0600996A, ((r4 & 0xFFFF) + 27));
                            return r0;
                        }
                    } else {
                        SETMACL(LD32((sp - 28)));
                        SETPR(LD32((sp - 24)));
                        SETR(10, LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    }
                } else {
                    SETSP((sp - 32));
                    r0 = GCALL0(0x0601C534);
                    SETR(13, r13);
                    SETSP((sp - 32));
                    SETPR(0x0601CCEE);
                    r0 = GCALL1(0x06016574, 20);
                    r3 = LD32(r13);
                    ST32(100 + r3, 0x0601CE94);
                    SETMACL(LD32((sp - 28)));
                    SETPR(LD32((sp - 24)));
                    SETR(10, LD32((sp - 20)));
                    SETR(11, LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP1(0x0600996A, 31);
                    return r0;
                }
            } else {
                SETMACL(LD32((sp - 28)));
                SETPR(LD32((sp - 24)));
                SETR(10, LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0601C382);
                return r0;
            }
        }
    } else {
        SETMACL(LD32((sp - 28)));
        SETPR(LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0601C382);
        return r0;
    }
}

int f0601CEEA(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0601ADA6);
    r2 = LD32(0x060D7768);
    r0 = LD16(52 + r2);
    if ((r0 & r0) == 0) {
        SETSP((sp - 4));
        r0 = GCALL0(0x0601AE68);
        SETSP((sp - 4));
        SETPR(0x0601CF08);
        r0 = GCALL0(0x0601C34C);
        SETSP((sp - 4));
        r0 = GCALL0(0x0601AE68);
        SETSP((sp - 4));
        SETPR(0x0601CF14);
        r0 = GCALL1(0x06016574, 20);
        r2 = LD32(0x060D7768);
        ST32(100 + r2, 0x0601CF2A);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 30);
    }
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x0601AD82);
    return r0;
}

int f0601CF2A(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    r0 = 60;
    ST32((sp - 4), PR());
    r3 = LD32(0x060D7B3C);
    r1 = LD16(60 + r3);
    if (!((r1 & 0xFFFF) == 0xFF00)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x0601CF40);
        r0 = GCALL0(0x0601C382);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x06009A3A, 30);
        return r0;
    }
}

void f0601CF8C(void)
{
    gaddr rec = LD32(0x060D8318);
    int id = LDU16(rec);
    int n = LDU8(rec + 24);
    gaddr box;
    int a, b;

    if (!(LDU8(LD32(0x060D8310) + 6) & 1)) {
        box = 0x060B47B8 + LDU16(LD32(CURRENT) + 52) * 8;
        a = n - LD8(box);
        if ((short)a >= 0)
            a = 0;
        b = n * 2 - LD8(box + 1);
        GCALL4(0x0600A3FA, id, box, b, a);
    } else {
        box = 0x060B47B8 + LDU16(LD32(CURRENT) + 52) * 8 + 4;
        a = n * 2 - LD8(box);
        b = n - LD8(box + 1);
        if ((short)b >= 0)
            b = 0;
        GCALL4(0x0600A3FA, id, box, b, a);
    }
    GCALL1(0x0601C2C2, id);
}

int f0601D070(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x0601C440);
    r0 = 60;
    r2 = LD32(0x060D7B3C);
    r1 = LD16(60 + r2);
    if (!((r1 & 0xFFFF) == 0xFF00)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r1 = LD32(0x060D7768);
        ST32(100 + r1, 0x0601D0F6);
        r6 = LD32(0x060D7768);
        r5 = LD32(0x060D7B3C);
        r6 = LD16(52 + r6);
        r0 = LD32(0x060D8310);
        r0 = LD8(r0 + 6);
        r6 = ((((((r6 & 0xFFFF) << 2) << 2) + (r6 & 0xFFFF)) << 1) + (((r0 & 255) - 1) & 1)) + 159;
        r0 = LD16(r5 + 4);
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x0601D0C6);
        r0 = GCALL4(0x0601C48C, 0, (r0 - 1), r6, 1);
        SETSP((sp - 8));
        r0 = GCALL1(0x0601C244, 0);
        SETSP((sp - 8));
        r0 = GCALL0(0x0601CF8C);
        r4 = LD32(0x060D8318);
        r4 = LD16(r4);
        SETSP((sp - 8));
        r0 = GCALL2(0x06069546, (r4 & 0xFFFF), 1);
        r4 = LD32(0x060D7768);
        r4 = LD16(52 + r4);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x0600996A, ((r4 & 0xFFFF) + 32));
        return r0;
    }
}

int f0601D0F6(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r13 = 0x060D8318;
    r14 = 0x060C1AA8;
    r3 = LD32(0x060D8318);
    r2 = LD16(r3);
    ST16(0x060C1AA8, r2);
    r0 = LD32(0x060D8310);
    r0 = LD8(r0 + 6);
    r12 = LD32(0x060D7768);
    r12 = LD16((52 + r12));
    r12 = LD8((((signed char)((r0 << 1) + r0)) + 0x060B47D0) + (r12 & 0xFFFF));
    r0 = LD32(0x060D8318);
    r3 = LD8((r0 + 24));
    if (!((r3 & 255) >= r12)) {
        SETSP((sp - 16));
        r0 = GCALL0(0x0601C21C);
        SETSP((sp - 16));
        r0 = GCALL0(0x0601CF8C);
    }
    r4 = LD16(r14);
    SETSP((sp - 16));
    r0 = GCALL1(0x0601C2C2, (r4 & 0xFFFF));
    r3 = LD32(r13);
    r3 = r3 + 24;
    r2 = LD8(r3);
    ST8(r3, (r2 + 1));
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 22);
    ST16(r14, r0);
    r0 = LD16(0x060C0630);
    r4 = LD32(0x060D7B3C);
    r5 = 1 & (r0 & 0xFFFF);
    r0 = LD32(0x060D8310);
    r0 = LD8(r0 + 6);
    r0 = r0 & 255;
    r6 = -r5;
    if (r0 == 1) {
        r0 = 36;
        ST16(r0 + r4, r5);
    } else {
        if (r0 == 2) {
            r0 = 38;
            ST16(r0 + r4, r5);
        } else {
            if (r0 == 3) {
                r0 = 36;
                ST16(r0 + r4, r6);
            } else {
                if (r0 == 4) {
                    r0 = 38;
                    ST16(r0 + r4, r6);
                }
            }
        }
    }
    SETR(12, r12);
    SETR(13, r13);
    SETSP((sp - 16));
    SETPR(0x0601D1CA);
    r0 = GCALL0(0x0601D1F8);
    r2 = LD32(r13);
    r3 = LD8((r2 + 24));
    if ((r3 & 255) >= (r12 + 40)) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0601C382);
        return r0;
    } else {
        r3 = LD32(0x060D8310);
        r0 = LD16(42 + r3);
        if ((r0 & r0) == 0) {
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
            r0 = GJUMP0(0x0601C382);
            return r0;
        }
    }
}

int f0601D1F8(void)
{
    int r0, r1, r2, r3, r4, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r14 = 0x060D7768;
    r12 = LD32(0x060D8318);
    r9 = LD32(0x060D7768);
    r12 = LD8((r12 + 24));
    r0 = LD32(0x060D8310);
    r0 = LD8(r0 + 6);
    r12 = r12 & 255;
    r4 = LD16((52 + r9));
    r0 = (signed char)((r0 << 1) + r0);
    r4 = LD8(((r4 & 0xFFFF) + (0x060B47D0 + r0)));
    if ((unsigned)r12 >= (unsigned)r4) {
        r12 = r4;
    }
    r11 = 0x060D7B3C;
    r10 = 0x060C062C;
    r3 = LD32(0x060D7B3C);
    r8 = 0x060C063D;
    ST32(sp - 44, r3);
    r3 = LD16(0x060C062C);
    ST32(sp - 48, (r3 & 0xFFFF));
    r12 = (int)((unsigned)r12 >> 2);
    while (!((r12 & r12) == 0)) {
        POLL();
        r3 = LD32(sp - 44);
        ST32(r11, r3);
        ST32(r14, r9);
        r3 = LD32(sp - 48);
        ST16(r10, r3);
        r0 = LD8(r9 + 6);
        SETSP((sp - 48));
        r0 = GCALL3(0x06017E70, r12, (r0 & 255), 0);
        if (!((r0 & r0) == 0)) {
            r0 = 0x060EE8B0;
            r3 = LD16(0x060D7E8C);
            r3 = r3 & 0xFFFF;
            ST32(sp - 40, r3);
            r1 = LD16(0x060EE8B0 + (r3 << 1));
            if (!(((r1 & 0xFFFF) & 0x7000) == 0)) {
                r13 = 0;
                ST32(r14, 0x060D5F30);
                do {
                    r3 = LD32(sp - 48);
                    if (!(r13 == r3)) {
                        r0 = 36;
                        r1 = LD16(36 + r9);
                        if (!(r13 == (r1 & 0xFFFF))) {
                            r0 = LD32(r14);
                            r0 = LD8(r0 + 4);
                            r0 = r0 & 255;
                            if ((r0 & 192) == 0) {
                                r3 = LD32(r14);
                                r0 = LD16(r3 + 20);
                                r3 = LD32(sp - 40);
                                r0 = r0 & 0xFFFF;
                                if (r0 == r3) {
                                    r0 = LD32(r14);
                                    r0 = LD16(r0 + 22);
                                    r0 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
                                    ST32(r11, r0);
                                    ST16(r10, r13);
                                    r3 = LD8(r8);
                                    if (!((unsigned)r13 >= (unsigned)(r3 & 255))) {
                                        r0 = LD32(r14);
                                        r0 = LD8(r0 + 4);
                                        r0 = r0 & 255;
                                        if ((r0 & 32) == 0) {
                                            r3 = LD32(r14);
                                            r0 = LD16(82 + r3);
                                            if (!((r0 & r0) == 0)) {
                                                r3 = LD32(r14);
                                                r0 = 82;
                                                ST16(82 + r3, 30);
                                            } else {
                                                SETR(8, r8);
                                                SETR(9, r9);
                                                SETR(10, r10);
                                                SETR(11, r11);
                                                SETR(12, r12);
                                                SETR(13, r13);
                                                SETR(14, r14);
                                                SETSP((sp - 48));
                                                SETPR(0x0601D302);
                                                r0 = GCALL0(0x06018D60);
                                                if (!((r0 & r0) == 0)) {
                                                    SETR(8, r8);
                                                    SETR(9, r9);
                                                    SETR(10, r10);
                                                    SETR(11, r11);
                                                    SETR(12, r12);
                                                    SETR(13, r13);
                                                    SETR(14, r14);
                                                    SETSP((sp - 48));
                                                    SETPR(0x0601D30C);
                                                    r0 = GCALL1(0x06018FB2, 30);
                                                }
                                            }
                                        }
                                    }
                                    r3 = LD8(r8);
                                    if ((unsigned)r13 >= (unsigned)((r3 & 255) + 8)) {
                                        SETSP((sp - 48));
                                        r0 = GCALL2(0x0606B29C, r13, 30);
                                    }
                                }
                            }
                        }
                    }
                    r13 = r13 + 1;
                    r2 = LD32(r14);
                    ST32(r14, (r2 + 124));
                } while (AGAIN(!((unsigned)r13 >= (unsigned)50)));
            }
        }
        r12 = r12 - 1;
    }
    r3 = LD32(sp - 44);
    ST32(r11, r3);
    ST32(r14, r9);
    r3 = LD32(sp - 48);
    ST16(r10, r3);
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

int f0601D3C0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

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
    r0 = GCALL0(0x0601C440);
    r0 = 60;
    r10 = 0x060D7B3C;
    r2 = LD32(0x060D7B3C);
    r3 = LD16(60 + r2);
    if (!((r3 & 0xFFFF) == 0xFF00)) {
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
    } else {
        r8 = 0x060C381C;
        r9 = 3;
        r11 = 0x060D8318;
        r13 = 0;
        r12 = 0x060D7768;
        r14 = 0;
        r1 = LD32(0x060D7768);
        ST32(100 + r1, 0x0601D48C);
        do {
            r6 = LD32(r12);
            r0 = LD8(r6 + 6);
            r5 = LD32(r10);
            r6 = r0 & 255;
            r0 = LD16(r5 + 4);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 36));
            SETPR(0x0601D40E);
            r0 = GCALL4(0x0601C48C, r14, r0, (r6 + 124), 3);
            SETSP((sp - 36));
            r0 = GCALL1(0x0601C244, 1);
            r2 = LD16(0x060C1AAA);
            r4 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r8;
            ST16(74 + r4, r13);
            ST16(72 + r4, r13);
            ST16(70 + r4, r13);
            ST16(68 + r4, r13);
            r2 = LD32(r11);
            r1 = LD32(r12);
            r0 = LD16(52 + r1);
            ST8(((r2 + 24) + r14), (((((r0 & 0xFFFF) + 1) << 2) << 1) + 6));
            r0 = LD32(r11);
            ST8(((r0 + 36) + r14), ((r14 << 2) << 1));
            r14 = r14 + 1;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r9)));
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
        r0 = GJUMP1(0x0600996A, 37);
        return r0;
    }
}

int f0601D48C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 0;
    r13 = 0x060D8318;
    r14 = 0;
    r10 = 0x060C1AA8;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    r8 = 3;
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r9 = 0;
    if (!((unsigned)0 >= (unsigned)3)) {
        do {
            r3 = LD32(r13);
            r0 = LD8(((r3 + 36) + r14));
            if ((r0 & r0) == 0) {
                r0 = LD32(r13);
                r12 = LD16(r0 + (r14 << 1));
                ST16(r10, r12);
                r12 = (((r12 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
                SETSP((sp - 40));
                r0 = GCALL0(0x0600CA7C);
                ST32(sp - 40, r0);
                r0 = LD16((r0 << 1) + 0x060EE8B0);
                r3 = LD32(r13);
                r4 = 255 & (r0 & 0xFFFF);
                r0 = LD8(((r3 + 24) + r14));
                if ((r0 & r0) == 0) {
                    r3 = LD32(r13);
                    ST8(((r3 + 24) + r14), r11);
                    ST16(70 + r12, r11);
                    ST16(68 + r12, r11);
                } else {
                    if (r4 == 13) {
                        r3 = LD32(r13);
                        ST8(((r3 + 24) + r14), r11);
                        ST16(70 + r12, r11);
                        ST16(68 + r12, r11);
                    } else {
                        if (r4 == 14) {
                            r3 = LD32(r13);
                            ST8(((r3 + 24) + r14), r11);
                            ST16(70 + r12, r11);
                            ST16(68 + r12, r11);
                        } else {
                            r3 = LD32(r13);
                            r3 = (r3 + 24) + r14;
                            r2 = LD8(r3);
                            ST8(r3, (r2 - 1));
                            SETSP((sp - 40));
                            r0 = GCALL0(0x0601C21C);
                            r4 = LD16(r10);
                            SETSP((sp - 40));
                            r0 = GCALL1(0x0601C2C2, (r4 & 0xFFFF));
                            r3 = LD16(68 + r12);
                            ST16(68 + r12, (r3 + 16));
                            r2 = LD16(68 + r12);
                            ST16(70 + r12, r2);
                            r5 = LD32(sp - 40);
                            SETSP((sp - 40));
                            r0 = GCALL3(0x0601D5EC, 0, r5, r12);
                            r9 = r9 + 1;
                        }
                    }
                }
            } else {
                r0 = LD32(r13);
                r3 = (r0 + 36) + r14;
                r2 = LD8(r3);
                ST8(r3, (r2 - 1));
                r9 = r9 + 1;
            }
            r14 = r14 + 1;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r8)));
    }
    r2 = LD32(0x060D7768);
    r0 = LD16(r2 + 22);
    ST16(r10, r0);
    if ((r9 & r9) == 0) {
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
        r0 = GJUMP0(0x0601C382);
        return r0;
    } else {
        r2 = LD32(0x060D8310);
        r0 = LD16(42 + r2);
        if ((r0 & r0) == 0) {
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
        } else {
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
            r0 = GJUMP0(0x0601C382);
            return r0;
        }
    }
}

void f0601D5EC(int unused, int dx, gaddr obj)
{
    gaddr step;

    GCALL1(0x0601D668, dx);
    step = ((LDU8(LD32(CURRENT) + 6) - 1) << 2) + 0x060B47E0;
    if (LDU16(obj + 68) < 0x140)
        return;
    GCALL1(0x0601D668, LD16(step) + dx);
    GJUMP1(0x0601D668, LD16(step + 2) + dx);
}

void f0601D668(int cell)
{
    int offset = (unsigned short)cell * 2;
    int flags = LDU16(0x060EC8B0 + offset);

    if (LDU16(LD32(0x060D8310) + 20) == (unsigned short)cell)
        return;
    if (flags & 32)
        GCALL2(0x0601F232, (unsigned short)cell, 17);
    if ((flags & 255) == 16 && (LDU16(0x060F08B0 + offset) & 255) != 0) {
        GCALL0(0x0600C4C8);
        GJUMP2(0x0600C7BE, 2, cell);
    }
}

int f0601D72A(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    r4 = 0x2710;
    POLL();
    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    ST32(sp - 12, r4);
    r3 = LD32(0x060D7768);
    r0 = LD16(36 + r3);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 12));
        r0 = GCALL0(0x0601ADA6);
        SETSP((sp - 12));
        r0 = GCALL0(0x0601BB8E);
        r0 = LD32(sp - 12);
        if (!((r0 & r0) == 0)) {
            r4 = LD32(sp - 12);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x0601D710);
            r0 = GCALL1(0x060165B8, r4);
        } else {
            r4 = LD32(r14);
            r0 = LD16(r4 + 22);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x0601D704);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
        }
        r2 = LD32(r14);
        ST32(100 + r2, 0x060143D8);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0601AD82);
        return r0;
    }
}

int f0601D730(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    r4 = 0;
    POLL();
    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    ST32(sp - 12, r4);
    r3 = LD32(0x060D7768);
    r0 = LD16(36 + r3);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 12));
        r0 = GCALL0(0x0601ADA6);
        SETSP((sp - 12));
        r0 = GCALL0(0x0601BB8E);
        r0 = LD32(sp - 12);
        if (!((r0 & r0) == 0)) {
            r4 = LD32(sp - 12);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x0601D710);
            r0 = GCALL1(0x060165B8, r4);
        } else {
            r4 = LD32(r14);
            r0 = LD16(r4 + 22);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x0601D704);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
        }
        r2 = LD32(r14);
        ST32(100 + r2, 0x060143D8);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0601AD82);
        return r0;
    }
}

int f0601D812(void)
{
    short value;

    GCALL0(0x0601ADA6);
    value = LD16(LD32(MOVER_PTR) + 38) - GCALL0(0x060167DE);
    GCALL0(0x0601AD82);
    ST16(LD32(MOVER_PTR) + 38, value);
    return 38;
}

int f0601D846(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    UNFRAME(sp);
    r0 = GJUMP0(0x0601DA3A);
    return r0;
}

int f0601D89A(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 20));
    r0 = GCALL0(0x0601B662);
    SETSP((sp - 20));
    r0 = GCALL0(0x0601AE68);
    SETSP((sp - 20));
    r0 = GCALL0(0x060167DE);
    ST32(sp - 20, ((short)r0));
    SETSP((sp - 20));
    r0 = GCALL0(0x0601AE68);
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r5 = LD32(0x060D8310);
    r0 = LD8(r4 + 6);
    r3 = r0;
    r0 = LD8(r5 + 6);
    if (!(r3 == r0)) {
        r0 = LD8(r5 + 6);
        ST8(r4 + 6, r0);
        SETR(14, r14);
        SETSP((sp - 20));
        SETPR(0x0601D8DC);
        r0 = GCALL1(0x060165B8, 0);
        r4 = LD32(r14);
        r0 = LD8(r4 + 6);
        SETSP((sp - 20));
        r0 = GCALL1(0x0601BF0C, (r0 & 255));
    }
    r12 = 0x060D8314;
    r13 = 0x060D7B3C;
    SETSP((sp - 20));
    r0 = GCALL0(0x0601C150);
    if ((r0 & r0) == 0) {
        r3 = LD32(r13);
        ST16(62 + r3, 0);
    } else {
        r3 = LD32(r13);
        r2 = LD32(r12);
        r1 = LD16(62 + r2);
        ST16(62 + r3, r1);
        r5 = LD32(r14);
        r0 = LD16(r5 + 22);
        r5 = r0 & 0xFFFF;
        r4 = LD32(0x060D8310);
        r0 = LD16(r4 + 22);
        SETSP((sp - 20));
        r0 = GCALL2(0x0600A3D8, (r0 & 0xFFFF), r5);
        r4 = LD32(r14);
        r0 = LD8(r4 + 6);
        SETSP((sp - 20));
        r0 = GCALL1(0x0601BF0C, (r0 & 255));
    }
    r3 = LD32(r13);
    r2 = LD32(r12);
    r1 = LD32(sp - 20);
    r2 = LD16(38 + r2);
    ST16(38 + r3, (r2 - r1));
    r3 = LD32(r13);
    r0 = LD16(r3 + 4);
    r3 = LD32(r12);
    r2 = r0;
    r0 = LD16(r3 + 4);
    if (r2 == r0) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(r14);
        r0 = LD8(r4 + 6);
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x0601BF0C, (r0 & 255));
        return r0;
    }
}

int f0601D962(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0601D968);
    r0 = GCALL0(0x0601D89A);
    r0 = LD32(0x060D8310);
    r0 = LD16(r0 + 46);
    r0 = r0 & 0xFFFF;
    if ((r0 & 8) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x0601D97C);
        r0 = GCALL1(0x06016574, 4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x060144F4, 0x0601D9F0);
        return r0;
    }
}

int f0601D9F0(void)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0601D9F6);
    r0 = GCALL0(0x0601D89A);
    r2 = LD32(0x060D7B3C);
    ST16(62 + r2, 0x100);
    r0 = LD32(0x060D8310);
    r0 = LD16(r0 + 46);
    r0 = r0 & 0xFFFF;
    if ((r0 & 8) == 0) {
        SETSP((sp - 4));
        SETPR(0x0601DA14);
        r0 = GCALL1(0x060165B8, 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0601D962);
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 20);
        r3 = (r0 & 0xFFFF) << 1;
        r0 = LD16(0x060EE8B0 + r3);
        r0 = r0 & 0xDFFF;
        ST16((0x060EE8B0 + r3), r0);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0601DAD0(void)
{
    gaddr t = LD32(0x060D8C08);
    int i = 0;

    ST16(t + 2, 0);
    ST16(t, 0);
    ST8(t + 16, 0);
    ST16(t + 20, 0);
    ST8(t + 24, 0);
    ST8(t + 19, 255);
    ST16(t + 4, 0xFFFF);
    ST8(t + 15, 255);
    ST8(t + 34, 255);
    ST8(t + 35, 0);
    ST8(t + 36, 0);
    do {
        ST8(LD32(0x060D8C08) + 30 + i, 0);
    } while (AGAIN(++i < 4));
}

void f0601DB2E(void)
{
    REF(Node14) n = NODE;

    SET(Node14, n, b6, 0);
    SET(Node14, n, b7, 0);
    SET(Node14, n, b8, 0);
    SET(Node14, n, b9, 0);
    SET(Node14, n, b11, 0);
    SET(Node14, n, b10, 0);
}

int f0601DC78(int r4)
{
    int r0, r2, r3, r5, r6, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r12 = 0x060D8C08;
    r13 = LD32(0x060D8C08);
    r0 = LD16(r13 + 10);
    r11 = r4;
    if (!(((r0 & 0xFFFF) & 0x102) == 0)) {
        r11 = 0;
        r14 = 0;
    } else {
        r0 = LD8(r13 + 12);
        if (((r0 & 255) & 1) == 0) {
            r0 = LD8(r13 + 12);
            if (((r0 & 255) & 2) == 0) {
                r0 = LD8(r13 + 12);
                if (((r0 & 255) & 4) == 0) {
                    r0 = LD8(r13 + 12);
                    if (((r0 & 255) & 8) == 0) {
                        r0 = LD8(r13 + 12);
                        if (((r0 & 255) & 16) == 0) {
                            r0 = LD8(r13 + 12);
                            if (((r0 & 255) & 64) == 0) {
                                r14 = 38;
                            } else {
                                r14 = 44;
                            }
                        } else {
                            r14 = 43;
                        }
                    } else {
                        r14 = 42;
                    }
                } else {
                    r14 = 41;
                }
            } else {
                r14 = 40;
            }
        } else {
            r14 = 39;
        }
    }
    r10 = 0x06068A8E;
    r5 = r11 + r14;
    ST32(sp - 32, r5);
    r4 = LD16(r13);
    SETR(10, 0x06068A8E);
    SETR(11, r11);
    SETR(12, r12);
    SETR(14, r14);
    SETSP((sp - 32));
    SETPR(0x0601DD2E);
    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), r5);
    if (!((r11 & r11) == 0)) {
        r3 = LD32(r12);
        r3 = LD16(r3);
        ST16(0x060C385A + (((r3 & 0xFFFF) * 84) & 0xFFFF), 0x100);
    }
    r2 = LD32(r12);
    r0 = LD16(r2 + 2);
    if (!((r0 & r0) == 0)) {
        r0 = LD32(r12);
        r0 = LD16(r0 + 10);
        if (((r0 & 0xFFFF) & 1) == 0) {
            r4 = LD32(r12);
            if ((r14 & r14) == 0) {
                r5 = 0;
            } else {
                r5 = 33;
            }
            r0 = LD16(r4 + 2);
            SETSP((sp - 32));
            SETPR(0x0601DDD8);
            r0 = GCALL2(r10, (r0 & 0xFFFF), r5);
        } else {
            r0 = LD32(r12);
            r0 = LD8(r0 + 24);
            if (!((r0 & 255) == 4)) {
                r4 = LD32(r12);
                if ((r14 & r14) == 0) {
                    r5 = 0;
                } else {
                    r5 = 33;
                }
                r0 = LD16(r4 + 2);
                SETSP((sp - 32));
                SETPR(0x0601DDD8);
                r0 = GCALL2(r10, (r0 & 0xFFFF), r5);
            } else {
                r5 = LD32(sp - 32);
                r4 = LD32(r12);
                r0 = LD16(r4 + 2);
                SETR(12, r12);
                SETSP((sp - 32));
                SETPR(0x0601DD6C);
                r0 = GCALL2(r10, (r0 & 0xFFFF), r5);
                r4 = LD32(r12);
                r0 = LD16(0x060C0630);
                r5 = 3 & (r0 & 0xFFFF);
                r0 = LD16(r4 + 2);
                r5 = ((r5 + 1) << 2) << 1;
                r4 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
                ST16(38 + r4, 0);
                ST16(36 + r4, 0);
                r0 = LD32(r12);
                r0 = LD8(r0 + 14);
                r0 = r0 & 255;
                r6 = -r5;
                if (r0 == 1) {
                    r0 = 36;
                    ST16(r0 + r4, r6);
                } else {
                    if (r0 == 2) {
                        r0 = 38;
                        ST16(r0 + r4, r6);
                    } else {
                        if (r0 == 3) {
                            r0 = 36;
                            ST16(r0 + r4, r5);
                        } else {
                            if (r0 == 4) {
                                r0 = 38;
                                ST16(r0 + r4, r5);
                            }
                        }
                    }
                }
            }
        }
    }
    SETMACL(LD32((sp - 28)));
    SETPR(LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0601DDEA(void)
{
    int entry = 0x060D84E8;
    int i;

    for (i = 2;; i++) {
        ST32(0x060D8C08, entry);
        if (i >= 50 || !LD8(entry + 16))
            break;
        entry += 38;
        POLL();
    }
    if (i >= 50)
        return 0;
    return (LDU16(0x060EC8B0 + LDU16(0x060D7E8C) * 2) & 0x42F0) ? 0 : i;
}

void f0601DE4E(int value)
{
    gaddr t = LD32(0x060D8C08);
    gaddr slot;
    gaddr cell;

    ST8(t + 6, LD8(0x060D84C8));
    slot = 0x060D849C + (unsigned char)LD8(t + 6) * 38;
    ST8(t + 7, LD8(slot + 7));
    ST8(0x060D84C8, value);
    ST8(slot + 7, value);
    ST8(t + 17, LD8(0x060DF971));
    ST8(t + 16, LD8(0x060DF973));
    ST8(t + 34, LD8(0x060C062D));
    ST8(t + 15, LD8(0x060C062D));
    ST16(t + 4, LD16(0x060D7E8C));
    ST8(t + 24, 0);
    ST16(t + 8, LD16(0x060DF974));
    ST8(t + 12, LD16(0x060DF974));
    if (LDU16(0x060EC8B0 + LDU16(0x060D7E8C) * 2) & 7) {
        ST16(t + 8, LD16(t + 8) & 0xFFFA);
        ST16(0x060DF972, 1);
        ST8(t + 16, 1);
    }
    ST16(t + 10, 0);
    cell = 0x060EC8B0 + LDU16(0x060D7E8C) * 2;
    ST16(cell, LD16(cell) | 32);
    ST8(t + 13, 0);
}

int f0601DFEA(int r4)
{
    int r0, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    ST32(sp - 24, r4);
    ST16(0x060DF970, 2);
    ST16(0x060DF972, 150);
    ST16(0x060DF974, 0);
    r14 = LD16(0x060D7E8C);
    r14 = ((r14 & 0xFFFF) << 1) + 0x060EC8B0;
    r0 = LD16(r14);
    ST16(sp - 20, r0);
    ST16(r14, 0);
    SETR(14, r14);
    SETSP((sp - 24));
    SETPR(0x0601E01C);
    r0 = GCALL0(0x0601DF3C);
    r13 = r0;
    if (!(((r13 & 0xFFFF) & (r13 & 0xFFFF)) == 0)) {
        ST32(0x060D8C08, (((r13 & 0xFFFF) * 38) + 0x060D849C));
        r4 = LD32(sp - 24);
        SETSP((sp - 24));
        r0 = GCALL1(0x060201A0, r4);
    }
    r0 = LD16(sp - 20);
    ST16(r14, r0);
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r13 & 0xFFFF;
}

int f0601E098(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r12, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    ST32(sp - 28, r6);
    ST16(0x060DF970, r5);
    ST16(0x060DF972, 150);
    ST16(0x060DF974, 0);
    r3 = LD32(sp - 28);
    r3 = r3 << 1;
    ST32(sp - 32, r3);
    r1 = LD16(0x060D7E8C);
    r2 = LD16(0x060B4814 + r3);
    ST16(0x060D7E8C, (r1 + r2));
    r13 = LD16(0x060D7E8C);
    r13 = ((r13 & 0xFFFF) << 1) + 0x060EC8B0;
    r2 = LD16(r13);
    ST32(sp - 24, (r2 & 0xFFFF));
    ST16(r13, 0);
    SETR(13, r13);
    SETSP((sp - 32));
    SETPR(0x0601E0DC);
    r0 = GCALL0(0x0601DF3C);
    r12 = r0;
    if (!((r0 & r0) == 0)) {
        ST32(0x060D8C08, ((r12 * 38) + 0x060D849C));
        r6 = LD32(sp - 28);
        SETSP((sp - 32));
        r0 = GCALL3(0x06020174, 2, 0, r6);
        r2 = LD32(0x060D8C08);
        r0 = LD32(sp - 32);
        r0 = LD16(r0 + 0x060B4828);
        ST16(r2 + 22, r0);
        r2 = LD32(0x060D8C08);
        ST8(25 + r2, 8);
        r2 = LD32(0x060D8C08);
        r0 = LD32(0x060C0900);
        r1 = LD32(sp - 32);
        r1 = LD16((r1 + 0x060B481E));
        ST16((38 + r0), r1);
        ST16(r2 + 28, ((short)r1 * (short)100));
    }
    r3 = LD32(sp - 24);
    ST16(r13, r3);
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r12;
}

void f0601E13C(char kind, short id, int mode)
{
    REF(Node14) head = ELEM(Node14, 0x060D8C0C, 1);
    int next;
    int q;

    if (LDU16(0x060DF97E) < 2)
        ST16(0x060DF97E, 2);
    ST32(CURSOR, ELEM(Node14, 0x060D8C0C, LDU16(0x060DF97E)));
    while (LDU16(0x060DF97E) < 2000 && GET(Node14, NODE, b6)) {
        ST32(CURSOR, LD32(CURSOR) + 14);
        ST16(0x060DF97E, LD16(0x060DF97E) + 1);
        POLL();
    }
    if (LDU16(0x060DF97E) >= 2000) {
        ST16(0x060DF97E, 0);
        return;
    }
    SET(Node14, NODE, h2, GET(Node14, head, h2));
    SET(Node14, NODE, h4, GET(Node14, ELEM(Node14, 0x060D8C0C, GET(Node14, NODE, h2) & 0xFFFF), h4));
    next = GET(Node14, NODE, h2) & 0xFFFF;
    SET(Node14, head, h2, LD16(0x060DF97E));
    SET(Node14, ELEM(Node14, 0x060D8C0C, next), h4, LD16(0x060DF97E));
    SET(Node14, NODE, b11, LD8(0x060C1AAB));
    SET(Node14, NODE, h0, id);
    SET(Node14, NODE, b9, mode);
    SET(Node14, NODE, b6, kind);
    q = LD32(0x060D8C08);
    SET(Node14, NODE, b7, mode == 1 ? LD8(q + 18) : 0);
    if (mode == 2) {
        SET(Node14, NODE, b8, LD8(0x060DF977));
        SET(Node14, NODE, b12, (LD8(q + 17) - LD16(q + 20)) << 1);
    } else {
        SET(Node14, NODE, b8, LD8(q + 19));
        SET(Node14, NODE, b12, 0);
    }
    if (LD8(q + 35) & 16)
        SET(Node14, NODE, b10, 16);
}

int f0601E2A4(unsigned short set, unsigned short n, int tag)
{
    gaddr p = 0x060F08B0 + n * 2;
    unsigned int v = LDU16(p);
    int current = HELPER((v & 0xFF00) >> 8);

    if (current != 0) {
        if (!set && current == tag)
            ST16(p, v & 255);
    } else if (set) {
        ST16(p, (tag << 8) + (v & 255));
    }
    return current;
}

void f0601E300(short x, short y, int tag)
{
    ST32(0x060D7E98, LD32(0x060DF988));
    ST32(0x060D7EA0, LD32(0x060DF98C));
    GCALL2(0x0600C7BE, x, y);
    GCALL3(0x0601E2A4, x, y, tag);
}

void f0601E336(unsigned short set, unsigned short n, unsigned short flags)
{
    int a, c;

    if (set) {
        if (!(flags & 16)) {
            if (LDU8(ACTB(18)) == 255) {
                a = set;
                c = 0;
            } else {
                a = flags;
                c = 1;
            }
        } else {
            a = flags & 16;
            c = 2;
            set = 1;
        }
        GCALL3(0x0601E13C, a & 0xFFFF, n, c);
    }
    GCALL3(0x0601E300, set, n, LDU8(ACTB(19)));
    ST16(FLAGS_AT(n), (LD16(FLAGS_AT(n)) & 0xFFF8) | flags);
}

void f0601E3B2(void)
{
    REF(Node14) n;

    GCALL0(0x0601DB2E);
    n = NODE;
    SET(Node14, ELEM(Node14, 0x060D8C0C, (unsigned short)GET(Node14, n, h2)), h4, GET(Node14, n, h4));
    n = NODE;
    SET(Node14, ELEM(Node14, 0x060D8C0C, (unsigned short)GET(Node14, n, h4)), h2, GET(Node14, n, h2));
}

void f0601E766(void)
{
    int i;

    if (!AGET(b16))
        return;
    ST8(0x060D849C + AGET(b6) * 38 + 7, AGET(b7));
    ST8(0x060D849C + AGET(b7) * 38 + 6, AGET(b6));
    if (AGET(w0))
        GCALL1(0x060692DC, AGET(w0));
    if (AGET(w2))
        GCALL1(0x060692DC, AGET(w2));
    if (!AGET(b13)) {
        if (AGET(b15) < 10) {
            gaddr bomber = 0x060D5F30 + AGET(b15) * 124;

            if (AGET(w8) & 64)
                ST16(bomber + 88, 0);
            else
                ST16(bomber + 40, LD16(bomber + 40) - 1);
            ST32(0x060DF990, LD32(0x060DF990) + 1);
            if (AGET(b35) & 64)
                GCALL2(0x060276D0, 18, 1);
        }
        ASET(b13, 0);
    }
    if (AGET(b16) != 255 && AGET(w4) != 0xFFFF)
        GCALL0(0x060210E8);
    POLL();
    ASET(w2, 0);
    ASET(w0, 0);
    ASET(b16, 0);
    ASET(w20, 0);
    ASET(b24, 0);
    ASET(b19, 255);
    ASET(w4, 0xFFFF);
    ASET(b15, 255);
    ASET(b34, 255);
    ASET(b35, 0);
    ASET(b36, 0);
    i = 0;
    do {
        ST8(LD32(0x060D8C08) + 30 + i, 0);
        i++;
    } while (AGAIN(i < 4));
}

void f0601E96E(int owner, int side)
{
    gaddr a = 0x060D849C + LDU8(0x060D849C + 7) * 38;
    int slot = 2 ^ ((side & 255) - 1);

    while (LD8(a + 7) != 0) {
        POLL();
        if (LDU16(a + 4) == owner && LDU8(a + 19) != 255) {
            ST8(a + 19, GCALL1(0x06021588, LDU8(LD32(ACTOR_PTR) + 19)));
            ST8(a + 30 + slot, 255);
            ST8(a + 35, LD8(a + 35) | 16);
        }
        a = 0x060D849C + LDU8(a + 7) * 38;
    }
}

void f0601ED54(int cell)
{
    gaddr flags;

    if ((unsigned char)LD8(0x060C029C) != 8)
        return;
    if ((unsigned)(signed char)AGET(b15) >= (unsigned)LD8(BOMBER_COUNT))
        return;
    flags = 0x060F08B0 + (0x800 + cell) * 2;
    ST16(flags, LD16(flags) | 1);
    if (AGET(b35) & 16)
        ST16(flags, LD16(flags) | 16);
    if (!(LDU16(0x060EE8B0 + cell * 2) & 0x4000))
        return;
    if (AGET(b35) & 4)
        GCALL2(0x060276D0, 4, 1);
    if (AGET(b35) & 8)
        GJUMP2(0x060276D0, 5, 1);
}

int f0601F090(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    r14 = 0x060D8C08;
    r3 = LD32(0x060D8C08);
    ST8(16 + r3, 255);
    SETR(14, 0x060D8C08);
    SETSP((sp - 20));
    SETPR(0x0601F0AA);
    r0 = GCALL1(0x0601DC78, 8);
    r4 = LD32(0x060D8C08);
    r0 = LD16(r4 + 2);
    SETR(14, 0x060D8C08);
    SETSP((sp - 20));
    SETPR(0x0601F0B6);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
    r13 = LD32(0x060D8C08);
    r0 = LD16(r13 + 4);
    r13 = ((r0 & 0xFFFF) << 1) + 0x060EC8B0;
    r1 = LD16(r13);
    ST16(r13, (r1 & 0xFFDF));
    r0 = LD16(r13);
    if (!(((r0 & 0xFFFF) & 7) == 0)) {
        r1 = LD32(0x060D8C08);
        r3 = LD8(19 + r1);
        if ((r3 & 255) == 255) {
            r4 = LD32(r14);
            r0 = LD16(r4 + 4);
            SETSP((sp - 20));
            r0 = GCALL1(0x06020F50, (r0 & 0xFFFF));
            ST16(sp - 20, r0);
            if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
                r8 = LD32(r14);
                r4 = LD16(sp - 20);
                SETSP((sp - 20));
                r0 = GCALL1(0x06021588, (r4 & 0xFFFF));
                ST8((r8 + 19), r0);
                r3 = LD32(r14);
                r1 = LD8(35 + r3);
                ST8(35 + r3, (r1 | 16));
            }
        }
    }
    r3 = LD32(r14);
    r2 = LD8(19 + r3);
    if ((r2 & 255) == 255) {
        r8 = LD32(r14);
        r6 = LD16(0x060DF976);
        ST32((sp - 24), (r6 & 0xFFFF));
        r3 = LD32(r14);
        r0 = LD8(r3 + 15);
        ST32((sp - 28), (r0 & 255));
        SETSP((sp - 28));
        r0 = GCALL0(0x06021562);
        r5 = LD32((sp - 28));
        r6 = LD32((sp - 24));
        SETSP((sp - 20));
        r0 = GCALL1(0x060215A2, r0);
        ST8((r8 + 19), r0);
    }
    r3 = LD16(r13);
    r4 = 1;
    if (!(((r3 & 0xFFFF) & 0x2000) == 0)) {
        r1 = LD32(r14);
        ST8(17 + r1, 16);
        r3 = LD32(r14);
        r0 = LD16(r3 + 8);
        ST16(r3 + 8, (r0 | 16));
    }
    r3 = LD16(0x060DF97C);
    if (!(((r3 & 0xFFFF) & r4) == 0)) {
        r1 = LD32(r14);
        ST8(17 + r1, r4);
    }
    SETSP((sp - 20));
    r0 = GCALL0(0x0601F7AE);
    r2 = LD32(r14);
    r7 = 4;
    r5 = 0;
    ST16(r2 + 10, 0);
    r6 = 0;
    r3 = LD32(r14);
    ST8(18 + r3, 0);
    r3 = LD32(r14);
    ST16(r3 + 20, 0);
    r3 = LD32(r14);
    r1 = LD8(35 + r3);
    ST8(35 + r3, (r1 | 96));
    r4 = LD32(r14);
    r4 = r4 + 30;
    do {
        r0 = LD8(r4);
        r6 = r6 + 1;
        if ((r0 & r0) == 0) {
            r2 = LD32(r14);
            r3 = LD8(17 + r2);
            ST8(r4, r3);
        } else {
            ST8(r4, r5);
        }
        r4 = r4 + 1;
    } while (AGAIN(!((r6 & 0xFFFF) >= r7)));
    SETSP((sp - 20));
    r0 = GCALL0(0x0601F73A);
    r3 = LD32(r14);
    r0 = LD16(r3 + 4);
    r3 = (r0 & 0xFFFF) << 1;
    r0 = LD16(0x060EC8B0 + r3);
    ST16((0x060EC8B0 + r3), (r0 | 7));
    r4 = LD32(r14);
    r2 = LD32(r14);
    r0 = LD16(r4 + 4);
    r4 = ((r0 & 0xFFFF) << 1) + 0x060F08B0;
    r1 = LD8(19 + r2);
    r0 = LD16(r4);
    ST16(r4, (((r1 & 255) << 8) + (r0 & 255)));
    r2 = LD16(0x060DF97A);
    ST16(0x060DF97A, (r2 + 1));
    SETPR(LD32((sp - 16)));
    SETR(8, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 15);
    return r0;
}

int f0601F232(int id, unsigned int slot)
{
    int next = LDU8(0x060D849C + 7);
    gaddr a;

    for (;;) {
        a = 0x060D849C + next * 38;
        ST32(ACTOR_PTR, a);
        if (LD8(a + 7) == 0)
            return 0;
        POLL();
        if (LDU8(a + 16) > 1 && LDU8(a + 16) != 255 && LDU16(a + 4) == id && !(LDU16(a + 10) & 0x1FA)) {
            GCALL0(0x0601F38C);
            if (slot <= 16)
                ST8(LD32(ACTOR_PTR) + 17, slot);
            return LDU8(0x060D849C + LDU8(LD32(ACTOR_PTR) + 6) * 38 + 7);
        }
        next = LDU8(LD32(ACTOR_PTR) + 7);
    }
}

int f0601F2C0(int id, unsigned int slot)
{
    int next = LDU8(0x060D849C + 7);
    gaddr a;

    for (;;) {
        a = 0x060D849C + next * 38;
        ST32(ACTOR_PTR, a);
        if (LD8(a + 7) == 0)
            return 0;
        POLL();
        if (LDU8(a + 16) > 1 && LDU8(a + 16) != 255 && LDU16(a + 4) == id && GCALL1(0x0600D066, LDU16(LD32(ACTOR_PTR))) != 0
            && !(LDU16(LD32(ACTOR_PTR) + 10) & 0x1FA)) {
            GCALL0(0x0601F38C);
            if (slot <= 16)
                ST8(LD32(ACTOR_PTR) + 17, slot);
            return LDU8(0x060D849C + LDU8(LD32(ACTOR_PTR) + 6) * 38 + 7);
        }
        next = LDU8(LD32(ACTOR_PTR) + 7);
    }
}

int f0601F38C(void)
{
    gaddr p;
    int flags;

    if (AGET(b16) > 1)
        ASET(b16, 1);
    ASET(w8, AGET(w8) & 0xFFFA);
    ASET(w10, AGET(w10) & 0xFE85);
    if (AGET(w4) < 0x1000) {
        p = 0x060EC8B0 + AGET(w4) * 2;
        ST16(p, LD16(p) & 0xFFDF);
    }
    if (!AGET(w0))
        return 0;
    GCALL0(0x0601F73A);
    p = 0x060EC8B0 + AGET(w4) * 2;
    flags = LD16(p) | 32;
    ST16(p, flags);
    return flags;
}

int f0601F3DA(void)
{
    unsigned char b = AGET(b16);

    if (b == 255 || b == 0)
        return 0;
    GCALL0(0x0601F38C);
    return 1;
}

void f0601F4B6(unsigned char dir)
{
    GCALL1(0x0600C90C, LDU16(0x060C1AA8));
    GCALL2(0x0600CAE4, LD16(0x060B4832 + dir * 2) + LD16(0x060D7E88), LD16(0x060B483C + dir * 2) + LD16(0x060D7E8A));
    ST16(0x060D7E8C, GCALL1(0x0600C9C0, LD16(0x060D7E8C)));
}

int f0601F500(void)
{
    int cell;

    GCALL1(0x0601F4B6, LD8(LD32(0x060D8C08) + 14));
    cell = LDU16(0x060D7E8C) * 2;
    if (LDU16(0x060EC8B0 + cell) & 0x42B0)
        return 1;
    return (LDU16(0x060EE8B0 + cell) & 0x7000) != 0;
}

int f0601F578(void)
{
    int flags;
    int cell;

    ST8(ACTB(14), ((LD8(ACTB(14)) + 255) ^ 2) + 1);
    POLL();
    GCALL1(0x0601F4B6, LD8(ACTB(14)));
    cell = LDU16(0x060D7E8C);
    flags = LDU16(FLAGS_AT(cell));
    if (flags & 0x42B0)
        return 1;
    return (LDU16(0x060EE8B0 + cell * 2) & 0x7000) != 0;
}

int f0601F58E(void)
{
    if (!AGET(w2))
        return 0;
    POLL();
    return GJUMP2(0x0600A3D8, AGET(w0), AGET(w2));
}

int f0601F5DE(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r5 = 0x060D8C08;
    r0 = LD32(0x060D8C08);
    r0 = LD8(r0 + 14);
    r0 = r0 & 255;
    r4 = LD32(0x060C0900);
    if (r0 == 1) {
        r0 = LD16(r4 + 16);
        r0 = r0 + 1;
        ST16(r4 + 16, r0);
    } else {
        if (r0 == 2) {
            r0 = LD16(r4 + 18);
            r0 = r0 + 1;
            ST16(r4 + 18, r0);
        } else {
            if (r0 == 3) {
                r0 = LD16(r4 + 16);
                r0 = r0 - 1;
                ST16(r4 + 16, r0);
            } else {
                if (r0 == 4) {
                    r0 = LD16(r4 + 18);
                    r0 = r0 - 1;
                    ST16(r4 + 18, r0);
                }
            }
        }
    }
    r3 = LD32(r5);
    r2 = LD16(r3);
    ST16(0x060C1AA8, r2);
    SETSP((sp - 8));
    r0 = GCALL0(0x0600D1A6);
    ST32(sp - 8, r0);
    SETSP((sp - 8));
    r0 = GCALL0(0x0600CA7C);
    SETSP((sp - 8));
    r0 = GCALL0(0x0601F58E);
    SETSP((sp - 8));
    SETPR(0x0601F63A);
    r0 = GCALL1(0x0601DC78, 0);
    r0 = LD32(sp - 8);
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0601F668(void)
{
    gaddr bomber = 0x060D5F30 + AGET(b15) * 124;
    REF(Actor) a;

    GCALL2(0x0600A3D8, LDU16(bomber + 22), AGET(w0));
    GCALL0(0x0601F58E);
    GCALL1(0x0606948A, AGET(w0));
    GCALL3(0x060693DC, AGET(w0), LDU16(bomber + 22), LD8(0x060B4846 + (unsigned char)LD8(bomber + 6) - 1));
    a = ACTOR;
    SET(Actor, a, w4, GCALL0(0x0600CA7C));
}

int f0601F6CC(void)
{
    gaddr src = OBJ(LDU16(0x060D5F46 + AGET(b15) * 124));
    gaddr dst = OBJ(AGET(w0));

    if (LD16(src + 16) > LD16(dst + 16))
        ST16(dst + 16, LD16(dst + 16) + 1);
    if (LD16(src + 16) < LD16(dst + 16))
        ST16(dst + 16, LD16(dst + 16) - 1);
    if (LD16(src + 18) > LD16(dst + 18))
        ST16(dst + 18, LD16(dst + 18) + 1);
    if (LD16(src + 18) < LD16(dst + 18))
        ST16(dst + 18, LD16(dst + 18) - 1);
    return GJUMP0(0x0601F58E);
}

void f0601F73A(void)
{
    REF(Actor) actor;
    gaddr obj;

    GCALL1(0x0600D16A, AGET(w0));
    obj = OBJ(AGET(w0));
    ST16(obj + 38, 0);
    ST16(obj + 36, 0);
    actor = ACTOR;
    SET(Actor, actor, w4, GCALL1(0x0600CA6A, AGET(w0)));
    POLL();
    GCALL0(0x0601F58E);
    if (AGET(w2) != 0) {
        obj = OBJ(AGET(w2));
        ST16(obj + 38, 0);
        ST16(obj + 36, 0);
    }
}

void f0601F782(void)
{
    if (AGET(w0) != 0) {
        int cell;

        GCALL0(0x0601F73A);
        cell = AGET(w4);
        ST16(FLAGS_AT(cell), LDU16(FLAGS_AT(cell)) | 32);
    }
}

void f0601F7AE(void)
{
    if ((AGET(w10) & 1) && AGET(b24) == 2)
        GCALL1(0x0602109C, 5);
    ASET(w10, AGET(w10) & 0xFFFE);
    ASET(w20, 0);
    ASET(b24, 0);
    ASET(b34, AGET(b15));
}

int f0601FB04(short pos, unsigned short dir, short owner)
{
    gaddr saved_actor = LD32(ACTOR_PTR);
    int saved_limit = LD32(0x060C0900);
    int result = 0;
    int cell;

    ST16(0x060DF97C, LD16(0x060DF97C) & 0xFFFB);
    pos = GCALL1(0x0600C9C0, LD16(0x060B47F0 + dir * 2) + pos);
    if (LDU16(FLAGS_AT((unsigned short)pos)) & 32) {
        cell = (unsigned short)GCALL1(0x0600C9C0, LD16(0x060B47F0 + dir * 2) + pos);
        if (!(LDU16(FLAGS_AT(cell)) & 0x290) && !(LDU16(0x060EE8B0 + cell * 2) & 0x7000)) {
            ST32(ACTOR_PTR, 0x060D849C + LDU8(0x060D84A3) * 38);
            while (AGET(b7) != 0) {
                POLL();
                if (AGET(b16) > 1 && AGET(b16) != 255 && AGET(w4) == (unsigned short)pos
                    && !(AGET(w10) & 0x1FA) && !(AGET(w8) & 64)) {
                    if (!(AGET(w10) & 1) || AGET(b14) != dir)
                        ST16(0x060DF97C, LD16(0x060DF97C) | 4);
                    ASET(w10, AGET(w10) | 1);
                    if ((AGET(b14) & 1) != (dir & 1))
                        GCALL0(0x0601F73A);
                    ASET(b14, dir);
                    ASET(b34, owner);
                    if (AGET(b24) < 2)
                        ASET(b24, 2);
                    result = LDU8(0x060D849C + AGET(b6) * 38 + 7);
                    break;
                }
                ST32(ACTOR_PTR, 0x060D849C + AGET(b7) * 38);
            }
        }
    }
    ST32(ACTOR_PTR, saved_actor);
    ST32(0x060C0900, saved_limit);
    return result;
}

int f0601FCBE(void)
{
    int cell = GCALL1(0x0600C9C0, LD16(0x060B47F0 + LDU8(LD32(CURRENT) + 6) * 2) + LD16(LD32(CURRENT) + 20));

    if (!(LDU16(FLAGS_AT((unsigned short)cell)) & 32))
        return 0;
    cell = (unsigned short)GCALL1(0x0600C9C0, LD16(0x060B47F0 + LDU8(LD32(CURRENT) + 6) * 2) + cell);
    if (LDU16(FLAGS_AT(cell)) & 0x42B0 || LDU16(0x060EE8B0 + cell * 2) & 0x7000)
        return 0;
    POLL();
    return GJUMP3(0x0601FB04, LD16(LD32(CURRENT) + 20), LDU8(LD32(CURRENT) + 6), LD16(0x060C062C));
}

void f0601FD42(int arg)
{
    int next = LDU8(0x060D84A3);

    for (;;) {
        ST32(ACTOR_PTR, 0x060D849C + next * 38);
        if (AGET(b7) == 0)
            return;
        POLL();
        if (AGET(b16) > 1 && AGET(b16) != 255 && AGET(b34) == LDU16(0x060C062C) && (AGET(w10) & 1) && !(AGET(w10) & 0x1FA)
            && AGET(b24) == 2) {
            GCALL0(0x0601F7AE);
            GCALL0(0x0601F782);
            if (arg == 0)
                return;
        }
        next = AGET(b7);
    }
}

int f0601FEC6(void)
{
    int count = 0;
    gaddr a = 0x060D849C + LDU8(0x060D849C + 7) * 38;

    ST32(ACTOR_PTR, a);
    while (LD8(a + 7) != 0) {
        POLL();
        a = LD32(ACTOR_PTR);
        if (LDU8(a + 16) > 1 && LDU8(a + 16) != 255 && (LDU16(a + 10) & 0x400))
            count++;
        a = 0x060D849C + LDU8(LD32(ACTOR_PTR) + 7) * 38;
        ST32(ACTOR_PTR, a);
    }
    return count;
}

int f0601FF30(int none)
{
    int next = LDU8(0x060D849C + 7);
    gaddr a;

    for (;;) {
        a = 0x060D849C + next * 38;
        ST32(ACTOR_PTR, a);
        if (LD8(a + 7) == 0)
            return 0;
        POLL();
        if (LDU8(a + 16) > 1 && LDU8(a + 16) != 255 && (LDU16(a + 8) & 1) && LDU8(a + 15) == LDU16(0x060C062C)
            && !(LDU16(a + 10) & 0x5FA) && (GCALL0(0x0601F3DA) & (none == 0)))
            return LDU8(0x060D849C + LDU8(LD32(ACTOR_PTR) + 6) * 38 + 7);
        next = LDU8(LD32(ACTOR_PTR) + 7);
    }
}

int f0601FFDA(void)
{
    int next;
    gaddr a;

    if (!(LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20))) & 32))
        return 0;
    next = LDU8(0x060D849C + 7);
    for (;;) {
        a = 0x060D849C + next * 38;
        ST32(ACTOR_PTR, a);
        if (LD8(a + 7) == 0)
            return 0;
        POLL();
        if (LDU8(a + 16) > 1 && LDU8(a + 16) != 255 && LDU16(a + 4) == LDU16(LD32(CURRENT) + 20)
            && LDU8(a + 15) == LDU16(0x060C062C) && !(LDU16(a + 10) & 0x1FA) && !(LDU16(a + 8) & 64)
            && (!(LDU16(a + 10) & 1) || LD8(a + 24) == 0)) {
            GCALL0(0x0601F7AE);
            a = LD32(ACTOR_PTR);
            ST16(a + 10, LD16(a + 10) | 16);
            ST16(LD32(ACTOR_PTR) + 20, 16);
            ST8(LD32(ACTOR_PTR) + 24, 0);
            GCALL2(0x0601486E, LDU16(LD32(ACTOR_PTR)), LDU8(LD32(ACTOR_PTR) + 15));
            return 1;
        }
        next = LDU8(LD32(ACTOR_PTR) + 7);
    }
}
