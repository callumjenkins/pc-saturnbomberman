#include "krnl.h"

void f06060038(short n)
{
    int i;

    for (i = 0; i < 10; i++) {
        gaddr rec = REC(i);

        POLL();
        if (GCALL1(0x06039FF0, i)) {
            if (i < 2) {
                if (LD16(rec + 20) == n)
                    GCALL1(0x0605E504, rec);
            } else if (LDU16(rec + 36) == 255) {
                if (LD16(rec + 20) == n)
                    GCALL1(0x0605E504, rec);
            }
        }
    }
}

void f060600C4(void)
{
    FRAME(sp, 32);
    gaddr buf = sp - 32;
    int mask;
    int k;

    COPYB(buf, 0x060B26C8, 6);
    if (!(LDU16(LD32(TASK_PTR) + 18) & 0x100)) {
        mask = 0x200;
        k = 0;
        do {
            if (LDU16(LD32(TASK_PTR) + 18) & (mask & 0xFFFF)) {
                int hit = (short)GCALL1(0x060603CA, LD16(LD32(TASK_PTR) + 20) + LD16(buf + k * 2));

                if (hit != 0)
                    TSET(h18, LD16(LD32(TASK_PTR) + 18) | ((mask & 0xFFFF) >> 4));
            }
            mask <<= 1;
            k++;
        } while (AGAIN((mask & 0xFFFF) <= 0x800));
    } else if ((short)GCALL1(0x060603CA, LD16(LD32(TASK_PTR) + 20)) != 0) {
        TSET(h18, LD16(LD32(TASK_PTR) + 18) | 16);
    }
}

int f060603CA(short pos)
{
    FRAME(sp, 32);
    gaddr offsets = sp - 28;
    int i = 4;

    COPYB(offsets, 0x060B26CE, 10);
    for (;;) {
        if ((short)GCALL2(0x060647BA, i, LD16(offsets + i * 2) + pos) != 0)
            break;
        i--;
        if (i == 0)
            break;
        POLL();
    }
    return i;
}

int f06060414(void)
{
    return GJUMP1(0x0606948A, LD16(LD32(TASK_PTR) + 8));
}

int f06060440(void)
{
    GCALL0(0x06039F54);
    return GJUMP0(0x06063370);
}

int f06060E78(void)
{
    GCALL2(0x06063E90, 0, 10);
    return GJUMP0(0x06060E8C);
}

int f06060E80(void)
{
    return GJUMP0(0x06060E8C);
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

int f060616B8(void)
{
    FRAME(sp, 92);
    gaddr taken = sp - 92;
    gaddr b72 = sp - 72;
    gaddr b60 = sp - 60;
    gaddr b48 = sp - 48;
    gaddr p;
    int i;

    for (p = b48; p < b48 + 12; p += 2) {
        POLL();
        ST16(p, 0);
    }
    GCALL2(0x06061810, b60, b72);
    for (p = taken + 4; p < taken + 20; p += 2) {
        POLL();
        ST16(p, 255);
    }
    for (i = 0; i < 10; i++) {
        gaddr rec = REC(i);

        POLL();
        if (i >= 2) {
            if (LD16(taken + i * 2) != 0)
                GCALL4(0x060618E0, rec, b48, b60, b72);
        } else {
            if ((LDU16(rec + 46) & 0x808) == 0x808)
                ST16(taken + LDU16(rec + 36) * 2, 0);
            GCALL4(0x060618E0, rec, b48, b60, b72);
        }
    }
    GCALL1(0x06061968, b48);
    ST16(OBJ(TGET(h8)) + 38, LD16(b48));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 10)) + 38, LD16(b48 + 2));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 12)) + 38, LD16(b48 + 4));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 14)) + 38, LD16(b48 + 6));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 16)) + 38, LD16(b48 + 8));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 18)) + 38, LD16(b48 + 10));
    return LD16(b48 + 10);
}

void f06061810(gaddr lo, gaddr hi)
{
    int k;

    for (k = 0; k < 6; k++) {
        ST16(lo + k * 2, LD16(OBJ(LDU16(LD32(TASK_PTR) + 8 + k * 2)) + 16) - 10);
        ST16(hi + k * 2, LD16(lo + k * 2) + 22);
    }
}

void f060618E0(gaddr rec, gaddr out, gaddr lo, gaddr hi)
{
    int k = 0;
    int y;

    if (LDU16(rec + 46) & 0x628)
        return;
    y = (short)LD16(OBJ(LDU16(rec + 22)) + 16);
    GCALL1(0x0600C9AA, LDU16(rec + 20));
    if (LDU16(0x060D7EB6) == 43) {
        do {
            if (LD16(lo + k) < y && LD16(hi + k) > y)
                ST16(out + k, 2);
            k += 2;
        } while (AGAIN(k < 12));
    }
}

void f06061968(gaddr row)
{
    int first = 0;
    int last = 5;
    int k;

    for (;;) {
        if (LD16(row + first * 2) != 0)
            break;
        first++;
        if (first >= 6)
            break;
        POLL();
    }
    for (;;) {
        if (LD16(row + last * 2) != 0)
            break;
        last--;
        if (last < 0)
            break;
        POLL();
    }
    k = first;
    if (!(k > last)) {
        do {
            ST16(row + k * 2, 2);
            k++;
        } while (AGAIN(!(k > last)));
    }
    if (!(first > last)) {
        int i = 0;
        int n = 2;

        if (0 < first) {
            do {
                ST16(row + i * 2, DIVS(n, first + 1));
                i++;
                n += 2;
            } while (AGAIN(i < first));
        }
        n = 5;
        i = 2;
        {
            gaddr end = row + 10;

            if (5 > last) {
                do {
                    ST16(end, DIVS(i, 6 - last));
                    n--;
                    i += 2;
                    end -= 2;
                } while (AGAIN(n > last));
            }
        }
    }
}

int f06061ABC(void)
{
    FRAME(sp, 16);

    COPYB(sp - 16, 0x060B26EE, 10);
    GCALL1(0x06022EDA, 2);
    GCALL1(0x06008A96, 1);
    GCALL1(0x06068A5E, sp - 16);
    return GCALL1(0x06009A3A, 145);
}

int f06061AEE(void)
{
    gaddr slot = SLOT(2);

    if (LDU16(slot + 18) >= 7)
        return -1;
    GCALL1(0x06061B64, LD16(slot + 18) + 1);
    return 0;
}

void f06061B64(short n)
{
    GCALL1(0x0600996A, 145);
    switch ((unsigned short)n) {
    case 1:
        GCALL2(0x06061BD4, 31, 60);
        break;
    case 2:
        GCALL2(0x06061BD4, 18, 60);
        break;
    case 3:
        GCALL2(0x06061BD4, 41, 60);
        break;
    case 4:
        GCALL2(0x06061BD4, 41, 50);
        break;
    case 5:
        GCALL2(0x06061BD4, 38, 50);
        break;
    case 6:
        GCALL2(0x06061BD4, 41, 50);
        break;
    case 7:
        GCALL2(0x06061BD4, 41, 59);
        break;
    }
    ST16(0x060D7B78 + 18, n);
}

void f06061BD4(short a, short b)
{
    ST16(0x060D7B86, a);
    ST16(0x060D7B88, b);
}

int f06061CE0(void)
{
    gaddr obj = OBJ(LDU16(0x060D7B80));

    GCALL2(0x0600CA32, LDU16(0x060D7B86), LDU16(0x060D7B88));
    if (LD16(0x060D7E88) != LD16(obj + 16) || LD16(0x060D7E8A) != LD16(obj + 18))
        ST16(0x060D7B78 + 20, 0);
    return LD16(0x060D7B78 + 20) == 0 ? 0 : -1;
}

int f06062168(void)
{
    if (LDU16(0x060D7C94) == 255)
        return -1;
    return 0;
}

int f060621B0(int base)
{
    int result = GCALL2(0x06022F1C, base + 3, 0x0603DDA6);
    gaddr obj;

    if (result >= 0) {
        TSET(h6, 0);
        obj = OBJ(TGET(h8));
        ST16(obj + 44, 1);
        GCALL1(0x0606AB4A, obj);
        GCALL2(0x0606AAC8, obj, 0);
        ST16(obj + 4, base + 10);
        ST16(obj + 46, 0x380);
        GCALL2(0x0606950C, obj, 1);
        GCALL3(0x0600D0E4, LD16(LD32(TASK_PTR) + 8), 32, 20);
        ST16(obj + 18, LD16(obj + 18) + 8);
        result = base;
        TSET(h10, base);
    }
    return result;
}

int f060622A4(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 3);

    ST32(0x060D7E60, s);
    if (LDU16(OBJ(GET(Slot24, s, obj)) + 60) >= 0xFF00)
        return -1;
    return 0;
}

int f060622D0(void)
{
    int i = 3;
    int result;

    do {
        result = GCALL1(0x06022EDA, i);
        i++;
    } while (AGAIN(i < 13));
    return result;
}

int f06062562(void)
{
    int base = LD8(0x060B7830 + TGET(h10) - 2);
    gaddr src = OBJ(LDU16(0x060D7BB0));
    gaddr dst = OBJ(TGET(h8));
    int y;

    if (LD16(src + 38) > 56) {
        base = DIVS(base * (72 - LD16(src + 38)), 16);
    }
    ST16(dst + 36, DIVS(LD16(src + 36) * (TGET(h10) - 1), 9));
    y = DIVS(LD16(src + 38) * (TGET(h10) - 1), 9) + base;
    ST16(dst + 38, y);
    return y;
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

void f060626C0(void)
{
    GCALL0(0x0606267E);
    ST32(0x060D7B90, 0x060626D0);
}

int f060626D0(void)
{
    if (!GCALL0(0x0606268A))
        return 0;
    TSET(fn, 0x060626FA);
    TSET(h4, 65);
    return 65;
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

void f06062AF0(void)
{
    int a, b, c, t;

    TSET(h10, TGET(h10) + 1);
    t = TGET(h10);
    a = LD16(0x060B783E);
    a = (a + HELPER((int)((LD16(0x060B7844) - a) * t) >> 8)) & 0x1FF;
    b = LD16(0x060B7840);
    b = (b + HELPER((int)((LD16(0x060B7846) - b) * t) >> 8)) & 0x1FF;
    c = LD16(0x060B7842);
    c = (c + HELPER((int)((LD16(0x060B7848) - c) * t) >> 8)) & 0x1FF;
    GCALL4(0x06029E2E, -1, a, b, c);
    if (TGET(h10) >= 255) {
        TSET(h12, 3);
        TSET(h10, 0);
        TSET(fn, 0x06062BAC);
    }
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

void f06062C34(int a, short b)
{
    FRAME(sp, 72);
    unsigned short ids[3];
    unsigned short at[3];
    gaddr slot;
    gaddr obj;
    int i;

    COPYB(sp - 60, 0x060B2728, 8);
    if (GCALL2(0x06022F1C, a, 0x06062DC0) < 0)
        return;
    TSET(h6, 0);
    TSET(h4, b);
    ids[0] = TGET(h8);
    slot = LD32(TASK_PTR) + 10;
    ids[1] = GCALL1(0x060691DA, 0x1CC);
    ST16(slot, ids[1]);
    slot = LD32(TASK_PTR) + 12;
    ids[2] = GCALL1(0x060691DA, 0x1CC);
    ST16(slot, ids[2]);
    i = 0;
    do {
        obj = OBJ(ids[i]);
        ST16(obj + 44, 1);
        ST16(obj + 4, 0x1CC);
        at[i] = GCALL1(0x0600A10E, 500) + 60;
        GCALL1(0x0606AB24, obj);
        GCALL2(0x0606AAC8, obj, 0);
        ST16(obj + 46, 0x380);
        GCALL2(0x0606950C, obj, 1);
        ST16(obj + 16, GCALL1(0x0600A10E, 320));
        ST16(obj + 18, 0);
        i++;
    } while (AGAIN(i < 3));
    TSET(h14, 0);
    TSET(h16, at[1]);
    TSET(h18, at[2]);
}

int f06062D3C(int n)
{
    gaddr s = SLOT(n);

    if (LD16(s + 8) == 0) {
        return 0;
    }
    GCALL5(0x060692DC, LDU16(s + 10), 0, 0, 0, n);
    GCALL5(0x060692DC, LDU16(s + 12), 0, 0, 0, n);
    return GJUMP1(0x06022EDA, n);
}

void f06062FF0(short id, short a, short b, short state)
{
    if (GCALL2(0x06022F1C, id, 0x060632A6) < 0) {
        return;
    }
    ST16(LD32(TASK_OBJ) + 44, 1);
    GCALL1(0x0606AB4A, LD32(TASK_OBJ));
    GCALL2(0x0606AAC8, LD32(TASK_OBJ), 3);
    ST16(LD32(TASK_OBJ) + 4, 5);
    ST16(LD32(TASK_OBJ) + 46, 0x3D0);
    GCALL2(0x0606950C, LD32(TASK_OBJ), 0);
    ST16(LD32(TASK_OBJ) + 36, 0);
    ST16(LD32(TASK_OBJ) + 38, 4);
    TSET(h10, 0);
    ST16(LD32(TASK_OBJ) + 74, 16);
    GCALL3(0x0600D0E4, (short)TGET(h8), a, b);
    {
        REF(Task) task = LD32(TASK_PTR);

        SET(Task, task, h12, GCALL1(0x0600CA6A, TGET(h8)));
    }
    TSET(h4, state);
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

int f060638E0(int x)
{
    unsigned short who = GCALL1(0x06018DD6, x);
    int result = who;

    ST16(0x060C062C, who);
    if (who < LDU8(BOMBER_COUNT)) {
        result = REC(0) + 4;
        ST8(result + who * 124, LD8(result + who * 124) | 64);
    }
    return result;
}

int f06063916(int cell)
{
    int mask = 0;
    int i = 0;

    do {
        if (GCALL1(0x06039FF0, i) && LDU16(REC(i) + 20) == cell) {
            mask |= SHL(1, i);
        }
        i++;
    } while (AGAIN(i < 2));
    return mask;
}

int f0606397C(int x, int y)
{
    int mask = 0;
    int i = 0;

    do {
        if (GCALL1(0x06039FF0, i)) {
            gaddr o = OBJ(LDU16(REC(i) + 22));

            if ((unsigned)(LD16(o + 16) + 7 - x) < 16 && (unsigned)(LD16(o + 18) + 7 - y) < 16) {
                mask |= SHL(1, i);
            }
        }
        i++;
    } while (AGAIN(i < 2));
    return mask;
}

void f06063A06(int amount)
{
    if (TGET(h20) & 1) {
        gaddr o = OBJ(LDU16(REC(0) + 22));

        ST16(o + 16, LD16(o + 16) + amount);
    }
    if (TGET(h20) & 2) {
        gaddr o = OBJ(LDU16(REC(1) + 22));

        ST16(o + 16, LD16(o + 16) + amount);
    }
}

int f06063CEE(short src, short dst)
{
    gaddr from = OBJ((unsigned short)src);
    gaddr to = OBJ((unsigned short)dst);

    GCALL2(0x0600A3DC, src, dst);
    ST16(to + 4, LD16(from + 4) + 1);
    ST8(to + 78, LD8(from + 78));
    ST16(to + 74, -4);
    ST16(to + 82, -4);
    return 82;
}

int f06063D78(void)
{
    if (LDU16(LD32(TASK_OBJ) + 60) != 0xFF00)
        return 60;
    return GJUMP0(0x06022F14);
}

int f06063D92(void)
{
    int i = 4;

    if (LDU8(0x060C029C) != 3) {
        return 0;
    }
    do {
        if (GCALL1(0x06022FFC, i)) {
            GCALL1(0x0600996A, 143);
            return 1;
        }
        i++;
    } while (AGAIN(i <= 5));
    return 0;
}

void f06063F58(void)
{
    REF(Task) task = TASK;

    SET(Task, task, h14, ((GCALL0(0x0600A0B8) & 3) + 1) << 7);
}

int f06063FA2(void)
{
    int flags = LDU16(FLAGS_AT(TGET(h10)));

    if ((flags & 7) == 0)
        TSET(fn, 0x06064056);
    return flags;
}

int f0606453C(void)
{
    int left;

    if (TGET(h16) == 0) {
        gaddr s = SLOT(TGET(h14));

        GCALL1(0x06022F14, 0);
        left = LD16(s + 16) - 1;
        ST16(s + 16, left);
        return left;
    }
    TSET(h16, TGET(h16) - 1);
    left = LDU16(FLAGS_AT(TGET(h18)));
    if (left & 7) {
        left = 0;
        TSET(h16, 0);
    }
    return left;
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

int f06064874(short n)
{
    return DIVS(n * 60, 60);
}

int f06064AAC(short n)
{
    gaddr slot = SLOT(n);

    GCALL1(0x060692DC, LDU16(slot + 10));
    ST16(slot + 10, 0);
    return GJUMP1(0x06022EDA, n);
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

void f0606523A(void)
{
    ST32(0x060D7C08, 0x06065258);
    ST16(0x060D7C16, 5);
    ST16(0x060D7C14, GCALL1(0x06064874, 0x139));
    ST16(0x060D7C18, 0);
}

void f06065386(void)
{
    gaddr task;

    GCALL2(0x06022F1C, 10, 0x060653E0);
    ST8(0x060C1920, 0);
    TSET(h6, 0);
    task = LD32(TASK_PTR);
    ST16(task + 4, GCALL1(0x06064874, 0x5DC));
}

int f060653E0(void)
{
    gaddr task;
    int result;

    GCALL0(0x06064D12);
    TSET(fn, 0x06065400);
    task = LD32(TASK_PTR);
    result = GCALL1(0x06064874, 180);
    ST16(task + 4, result);
    return result;
}

int f06065428(void)
{
    GCALL0(0x06064D12);
    TSET(fn, 0x0603DDA6);
    ST8(0x060C1920, 255);
    return 0x060C1920;
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

void f06065A12(void)
{
    FRAME(sp, 40);
    gaddr list = sp - 40;
    gaddr cell;
    int i = 0;

    COPYB(list, 0x060B2758, 8);
    do {
        cell = 0x060EC8B0 + GCALL2(0x0600C950, LD16(list + i * 2), 10) * 2;
        ST16(cell, LD16(cell) & 0xFF7F);
        ST16(cell, LD16(cell) | 0xF00);
        i++;
    } while (AGAIN(i < 4));
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

int f0606714E(void)
{
    FRAME(sp, 40);

    GCALL2(0x06022F1C, 24, 0x0606725C);
    TSET(h4, 60);
    TSET(h6, 0);
    GCALL0(0x06039DD8);
    ST16(0x060FAA70, 0);
    ST16(0x060FAA72, 0);
    ST16(0x060FAA74, 0);
    ST16(0x060FAA76, 0x300);
    ST16(0x060BB8FC, 1);
    GCALL1(0x0609E27E, 8);
    GCALL1(0x0609E27E, 16);
    GCALL1(0x0609E27E, 0x100);
    ST16(0x25F007FE, 0x83FF);
    ST16(sp - 40, 0x3FF);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LD16(0x060FB8AA) & 0xFFF3);
    GCALL2(0x0609C0B4, 0x318, 0);
    GCALL3(0x0609B8C0, 0x0004EC00, 1, sp - 40);
    TSET(h10, 0);
    TSET(h12, 0);
    TSET(h14, 16);
    TSET(h16, 1);
    return 1;
}

int f0606725C(void)
{
    int pos = (short)TGET(h12);
    int cells;

    GCALL5(0x06039DE0, 0, 160, 112, pos, pos);
    pos = (unsigned short)pos;
    cells = pos >> 4;
    if (TGET(h10) == 0)
        GCALL1(0x0606707C, 0);
    if (cells >= 31)
        cells = 31;
    if (TGET(h16) != 0) {
        if (pos >= 200) {
            GCALL1(0x0600996A, 88);
            TSET(h16, 0);
        } else if (!(TGET(h10) & 7)) {
            GCALL1(0x0600996A, 91);
        }
    }
    GCALL2(0x0609C0B4, 0x318, cells);
    TSET(h12, TGET(h12) + (TGET(h14) >> 4));
    TSET(h14, TGET(h14) + 2);
    if (TGET(h10) > 255)
        TSET(fn, 0x0603DDA6);
    pos = (short)TGET(h10) + 1;
    TSET(h10, pos);
    return pos;
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

int f06068A5E(gaddr p)
{
    ST16(0x060B7B9C, 0);
    while (LD16(p) != -1) {
        POLL();
        GCALL1(0x06068CC4, LD16(p));
        p += 2;
    }
    return p;
}

void f06068B32(gaddr obj)
{
    gaddr p = LD32(obj + 56);

    if (LD16(p) == -1)
        p = LD32(obj + 52);
    ST16(obj + 10, LD16(p));
    ST32(obj + 56, p + 4);
    ST16(obj + 60, LD16(p + 2) << 8);
}

int f06068B62(gaddr obj)
{
    int total = LDU16(obj + 60) >> 8;
    gaddr p = LD32(obj + 56);
    int step;

    while (LD16(p) != -1) {
        POLL();
        step = LD16(p + 2);
        p += 4;
        if ((unsigned int)step >= 255)
            break;
        total += step;
    }
    return total;
}

void f06068CC4(int bank)
{
    gaddr entry;

    if (bank == 0) {
        return;
    }
    entry = GCALL1(0x06008ADC, bank);
    while (LD16(entry) != -1) {
        POLL();
        if (LD16(entry) != 0) {
            gaddr p = GCALL1(0x06008ACC, LD16(entry));

            while (LDU16(p) < 0x8000) {
                POLL();
                GCALL1(0x06068DBC, LDU16(p + 2));
                GCALL1(0x0609F838, LD16(p + 2));
                p += 20;
            }
        }
        entry += 4;
    }
    GJUMP1(0x0609F938, 0x060C1970);
}

int f06068D60(int id)
{
    int count = LDU16(0x060C1980);
    gaddr p = 0x060C1984;
    int n = count;

    while (n != 0) {
        POLL();
        if (LDU16(p) == id)
            return 1;
        n--;
        p += 2;
    }
    if (count >= 48) {
        ST16(0x060C1984 + LDU16(0x060C1982) * 2, id);
        ST16(0x060C1982, LD16(0x060C1982) + 1);
        if (LDU16(0x060C1982) >= 48)
            ST16(0x060C1982, 0);
    } else {
        ST16(0x060C1984 + count * 2, id);
        ST16(0x060C1980, LD16(0x060C1980) + 1);
    }
    return 0;
}

void f06068DBC(int id)
{
    gaddr p = 0x060C1984;
    int n = LDU16(0x060C1980);

    while (n != 0) {
        POLL();
        if (LDU16(p) == id) {
            ST16(p, 0);
            break;
        }
        n--;
        p += 2;
    }
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

void f06068F14(gaddr p)
{
    gaddr tiles = LD32(p + 16);

    for (;;) {
        ST16(p + 20, LD16(tiles + 4));
        if (LDU16(tiles + 4) != 0)
            break;
        tiles = LD32(p + 12);
        POLL();
    }
    GCALL3(0x06068F5A, LD32(tiles), LD32(p + 8), LDU16(p + 4));
    ST32(p + 16, tiles + 8);
}

void f06068F5A(gaddr src, gaddr dst, unsigned int row)
{
    unsigned int width;
    unsigned int height;
    unsigned int y;
    unsigned int i;
    unsigned int j;
    unsigned int n;
    gaddr d;

    src += 4;
    width = LDU16(src);
    src += 2;
    height = LDU16(src);
    src += 2;
    dst += row << 5;
    for (j = 0; j < height; j++) {
        POLL();
        d = dst;
        y = row;
        for (i = 0; i < width; i++) {
            POLL();
            n = 32;
            do {
                ST8(d, LD8(src));
                src++;
                d++;
            } while (AGAIN(--n != 0));
            y++;
            if ((y & 15) == 0) {
                y += 240;
                d += 7680;
            }
        }
        row += 16;
        dst += 512;
        if ((row & 255) == 0) {
            dst += 8192;
            row += 256;
        }
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

void f060690AA(void)
{
    int i = 0;

    do {
        ST32(OBJ(i), 0);
        GCALL2(0x06069462, i, 0);
        GCALL1(0x06068FF4, i);
        i++;
    } while (AGAIN(i < 400));
    ST16(OBJS + 6, 1);
    ST16(OBJS + 8, 1);
    ST32(OBJS, 1);
    ST16(OBJS + 84 + 6, 0);
    ST16(OBJS + 84 + 8, 1);
    ST32(OBJS + 84, 255);
    ST16(0x060C1AAC, 2);
    ST16(0x060C1AB0, 0);
    ST16(0x060C1AAE, 0);
    GCALL1(0x0606A996, 0x06068FF0);
    ST32(0x060C1ABC, GCALL4(0x060069C2, 0x06069646, 0x060C341C, 0x400, 1));
    ST32(0x2600603C, 0);
    GCALL0(0x06068DE0);
    GCALL3(0x06098700, 0x060C1E28, 16, 0x060C1B28);
    GJUMP0(0x0606AA06);
}

void f06069194(void)
{
    ST16(0x060C1AB4 + 2, 0);
    ST16(0x060C1AB4, 0);
    ST16(0x060C1AB8, 319);
    ST16(0x060C1AB8 + 2, 223);
    ST16(0x060C1AC0, 0);
    ST16(0x060C1AC0 + 2, 0);
    ST16(0x060C1AC0 + 4, LD16(0x060C1AB8));
    ST16(0x060C1AC0 + 6, LD16(0x060C1AB8 + 2));
    GCALL1(0x0609F1A8, 0x060C1E34);
    GCALL1(0x0609F464, 0x060BB8D8);
    GCALL1(0x0609F624, 1);
    POLL();
    GJUMP0(0x060689EC);
}

int f060691DA(unsigned int key)
{
    int i = 2;
    int after;

    if (LDU16(0x060C1AAC) >= 400)
        return 0;
    ST16(0x060C1AAA, i);
    ST32(0x060CBB5C, OBJ(i));
    while (i < 400 && LD32(LD32(0x060CBB5C)) != 0) {
        POLL();
        ST32(0x060CBB5C, LD32(0x060CBB5C) + 84);
        i++;
        ST16(0x060C1AAA, i);
    }
    if (i >= 400)
        return 0;
    GCALL1(0x06068FF4, i);
    after = LDU16(OBJS + 8);
    while (after != 1) {
        POLL();
        if ((unsigned int)LD32(OBJ(after)) >= key)
            break;
        after = LDU16(OBJ(after) + 8);
    }
    GCALL2(0x0606935A, i, after);
    ST32(LD32(0x060CBB5C), key);
    GCALL2(0x06069462, i, key);
    ST16(0x060C1AAC, LD16(0x060C1AAC) + 1);
    if (LDU16(0x060C1AAC) > LDU16(0x060B7BA2))
        ST16(0x060B7BA2, LD16(0x060C1AAC));
    return i;
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

void f0606950C(gaddr obj, int mask)
{
    gaddr t = 0x060B7BA8 + (LDU16(0x060FB89C) & 15) * 4;

    ST16(obj + 46, LD16(obj + 46) & LD16(t + 2));
    ST16(obj + 46, LD16(obj + 46) | SHL(mask & 7, LDU16(t)));
}

void f06069546(unsigned short i, int mask)
{
    POLL();
    GJUMP2(0x0606950C, OBJ(i), mask);
}

int f06069562(gaddr obj)
{
    gaddr t = 0x060B7BA8 + (LDU16(0x060FB89C) & 15) * 4;

    return SHR(LDU16(obj + 46) & ~LDU16(t + 2), LDU16(t));
}

void f060695B0(gaddr obj, int mask)
{
    gaddr t = 0x060B7BE8 + (LDU16(0x060FB89C) & 15) * 4;

    ST16(obj + 46, LD16(obj + 46) & LD16(t + 2));
    ST16(obj + 46, LD16(obj + 46) | SHL(mask & 7, LDU16(t)));
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

void f06069906(void)
{
    ST16(0x060C1AF4, LD16(LD32(0x060CBB5C) + 16) + LD16(LD32(0x060CBB5C) + 36));
    ST16(0x060C1AF6, LD16(LD32(0x060CBB5C) + 18) + LD16(LD32(0x060CBB5C) + 38));
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        ST16(0x060C1AE0, LD16(LD32(0x060C1AF0) + 10) + LD16(0x060C1AF4));
        ST16(0x060C1AE2, LD16(0x060C1AF6) + LD16(LD32(0x060C1AF0) + 12));
        GCALL7(0x0609FF14, LD16(LD32(0x060CBB5C) + 4), LDU16(LD32(0x060C1AF0)) & 48, LD16(LD32(0x060CBB5C) + 40),
               LD32(0x060C1B10) == 0 ? LDU16(LD32(0x060CBB5C) + 46) + LDU16(LD32(0x060C1AF0) + 6) : LD32(0x060C1B18),
               LD16(LD32(0x060C1AF0) + 2), 0x060C1AE0, LD16(LD32(0x060CBB5C) + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f06069A3E(void)
{
    int v;

    v = LD16(LD32(0x060CBB5C) + 20) + LD32(0x060C1B08);
    ST16(LD32(0x060CBB5C) + 20, v);
    ST16(0x060C1AF4, v + LD16(LD32(0x060CBB5C) + 36));
    v = LD16(LD32(0x060CBB5C) + 22) + LD32(0x060C1B0C);
    ST16(LD32(0x060CBB5C) + 22, v);
    ST16(0x060C1AF6, v + LD16(LD32(0x060CBB5C) + 38));
    v = LD16(LD32(0x060CBB5C) + 24) + LD32(0x060C1B08);
    ST16(LD32(0x060CBB5C) + 24, v);
    ST16(0x060C1AF8, v + LD16(LD32(0x060CBB5C) + 36));
    v = LD16(LD32(0x060CBB5C) + 26) + LD32(0x060C1B0C);
    ST16(LD32(0x060CBB5C) + 26, v);
    ST16(0x060C1AFA, v + LD16(LD32(0x060CBB5C) + 38));
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        ST16(0x060C1AE0, LD16(LD32(0x060C1AF0) + 10) + LD16(0x060C1AF4));
        ST16(0x060C1AE2, LD16(0x060C1AF6) + LD16(LD32(0x060C1AF0) + 12));
        ST16(0x060C1AE4, LD16(LD32(0x060C1AF0) + 10) + LD16(0x060C1AF8));
        ST16(0x060C1AE6, LD16(0x060C1AFA) + LD16(LD32(0x060C1AF0) + 12));
        GCALL7(0x060A0018, LD16(LD32(0x060CBB5C) + 4), LD16(LD32(0x060C1AF0)) & 0xF30, LD16(LD32(0x060CBB5C) + 40),
               LD32(0x060C1B10) == 0 ? LDU16(LD32(0x060CBB5C) + 46) + LDU16(LD32(0x060C1AF0) + 6) : LD32(0x060C1B18),
               LD16(LD32(0x060C1AF0) + 2), 0x060C1AE0, LD16(LD32(0x060CBB5C) + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f06069BD2(void)
{
    unsigned int scale_x = LDU16(LD32(0x060CBB5C) + 68);
    unsigned int scale_y = LDU16(LD32(0x060CBB5C) + 70);
    int left = LD16(LD32(0x060CBB5C) + 72);
    int top = LD16(LD32(0x060CBB5C) + 74);
    gaddr q;
    int w;

    if (scale_x == 0 || scale_y == 0)
        return;
    ST16(0x060C1AF4, LD16(LD32(0x060CBB5C) + 16) + LD16(LD32(0x060CBB5C) + 36));
    ST16(0x060C1AF6, LD16(LD32(0x060CBB5C) + 18) + LD16(LD32(0x060CBB5C) + 38));
    ST16(0x060C1AF4, LD16(0x060C1AF4) + left);
    ST16(0x060C1AF6, LD16(0x060C1AF6) + top);
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        q = LD32(0x060C1AF0);
        w = LDU16(q + 8);
        ST16(0x060C1AE0, ((unsigned int)((LD16(LD32(0x060C1AF0) + 10) - left) * scale_x + 128) >> 8) + LD16(0x060C1AF4));
        ST16(0x060C1AE2, ((unsigned int)((LD16(LD32(0x060C1AF0) + 12) - top) * scale_y + 128) >> 8) + LD16(0x060C1AF6));
        ST16(0x060C1AE4, ((unsigned int)((LD16(LD32(0x060C1AF0) + 10) - left + ((w >> 5) & 0x1F8)) * scale_x + 128) >> 8) + LD16(0x060C1AF4) - 1);
        ST16(0x060C1AE6, ((unsigned int)((LD16(LD32(0x060C1AF0) + 12) - top + (w & 255)) * scale_y + 128) >> 8) + LD16(0x060C1AF6) - 1);
        GCALL7(0x060A0018, LD16(LD32(0x060CBB5C) + 4), LDU16(LD32(0x060C1AF0)) & 48, LD16(LD32(0x060CBB5C) + 40),
               LD32(0x060C1B10) == 0 ? LDU16(LD32(0x060CBB5C) + 46) + LDU16(LD32(0x060C1AF0) + 6) : LD32(0x060C1B18),
               LD16(LD32(0x060C1AF0) + 2), 0x060C1AE0, LD16(LD32(0x060CBB5C) + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f06069DBC(void)
{
    int corner;
    int v;

    for (corner = 0; corner < 4; corner++) {
        v = LD16(LD32(0x060CBB5C) + 20 + corner * 4 + 0) + LD32(0x060C1B08);
        ST16(LD32(0x060CBB5C) + 20 + corner * 4, v);
        ST16(0x060C1AF4 + corner * 4, v + LD16(LD32(0x060CBB5C) + 36));
        v = LD16(LD32(0x060CBB5C) + 22 + corner * 4) + LD32(0x060C1B0C);
        ST16(LD32(0x060CBB5C) + 22 + corner * 4, v);
        ST16(0x060C1AF6 + corner * 4, v + LD16(LD32(0x060CBB5C) + 38));
    }
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        for (corner = 0; corner < 4; corner++) {
            ST16(0x060C1AE0 + corner * 4, LD16(LD32(0x060C1AF0) + 10) + LD16(0x060C1AF4 + corner * 4));
            ST16(0x060C1AE2 + corner * 4, LD16(0x060C1AF6 + corner * 4) + LD16(LD32(0x060C1AF0) + 12));
        }
        GCALL7(0x060A0158, LD16(LD32(0x060CBB5C) + 4), LDU16(LD32(0x060C1AF0)) & 48, LD16(LD32(0x060CBB5C) + 40),
               LD32(0x060C1B10) == 0 ? LDU16(LD32(0x060CBB5C) + 46) + LDU16(LD32(0x060C1AF0) + 6) : LD32(0x060C1B18),
               LD16(LD32(0x060C1AF0) + 2), 0x060C1AE0, LD16(LD32(0x060CBB5C) + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f06069FF0(void)
{
    FRAME(sp, 120);
    gaddr eye = sp - 24;
    gaddr shifted = sp - 12;
    gaddr q = LD32(0x060CBB5C);
    int width = LDU16(q + 68);
    int height = LDU16(q + 70);
    int x0 = LD16(q + 72);
    int y0 = LD16(q + 74);
    int shade_a, shade_b, shade_c, ox, oy;
    gaddr table_a, table_b, table_c;
    gaddr rec, out, id_q;
    unsigned int cell;
    int step_x, step_y, x_off, y_off, x_adj, y_adj, k, i, j, px, py, flag;
    int len;

    if (width == 0 || height == 0) {
        return;
    }
    shade_a = LDU8(q + 76);
    shade_b = LDU8(q + 77);
    shade_c = LDU8(q + 78);
    ox = LD16(q + 80);
    oy = LD16(q + 82);
    ST16(0x060C1AF4, LD16(q + 36) + LD16(q + 16));
    ST16(0x060C1AF6, LD16(LD32(0x060CBB5C) + 38) + LD16(LD32(0x060CBB5C) + 18));
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    table_a = 0x060B9108 + shade_a * 4;
    table_b = 0x060B9108 + shade_b * 4;
    table_c = 0x060B9108 + shade_c * 4;
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        rec = LD32(0x060C1AF0);
        cell = LDU16(rec + 8);
        step_x = (cell >> 5) & 0x1F8;
        step_y = cell & 255;
        k = 0;
        y_off = 0;
        y_adj = 0;
        for (j = 0; j < 2; j++) {
            POLL();
            x_off = 0;
            x_adj = 0;
            i = 0;
            do {
                rec = LD32(0x060C1AF0);
                px = ((unsigned int)((LD16(rec + 10) - x0 + x_off) * width + 128) >> 8) + x0;
                py = ((unsigned int)((LD16(rec + 12) - y0 + y_off) * height + 128) >> 8) + y0;
                out = LD32(0x060B7C68 + k * 4) * 4 + 0x060C1AE0;
                k++;
                if ((shade_a | shade_b | shade_c) != 0) {
                    GCALL1(0x0609870C, 0x060C1E28);
                    flag = LD16(0x060B7BA4);
                    if (flag != 0) {
                        GCALL4(0x06098744, 0x060C1E28, 0, 0, GCALL1(0x060980DC, (unsigned short)flag));
                    }
                    if (shade_a != 0) {
                        GCALL2(0x0609879E, 0x060C1E28, LD32(table_a));
                    }
                    if (shade_b != 0) {
                        GCALL2(0x0609886C, 0x060C1E28, LD32(table_b));
                    }
                    if (shade_c != 0) {
                        GCALL2(0x0609893C, 0x060C1E28, LD32(table_c));
                    }
                    ST32(shifted, GCALL1(0x060980DC, px - ox));
                    ST32(shifted + 4, GCALL1(0x060980DC, py - oy));
                    ST32(shifted + 8, GCALL1(0x060980DC, 1));
                    GCALL3(0x06098B5C, LD32(0x060C1E2C), shifted, eye);
                    if (LD16(0x060B7BA6) != 0) {
                        GCALL3(0x06098BEC, eye, 0x060C1B1C, out);
                        ST16(out, LD16(out) + ox + LD16(0x060C1AF4));
                        ST16(out + 2, LD16(out + 2) + oy + LD16(0x060C1AF6));
                    } else {
                        ST16(out, GCALL1(0x060980E4, LD32(eye)) + LD16(0x060C1AF4) + ox);
                        ST16(out + 2, GCALL1(0x060980E4, LD32(eye + 4)) + LD16(0x060C1AF6) + (short)oy);
                    }
                } else {
                    ST16(out, px + LD16(0x060C1AF4));
                    ST16(out + 2, (short)py + LD16(0x060C1AF6));
                }
                ST16(out, LD16(out) + x_adj);
                ST16(out + 2, LD16(out + 2) + y_adj);
                x_off = step_x;
                x_adj = -1;
                i++;
            } while (AGAIN(i < 2));
            y_off = step_y;
            y_adj = -1;
        }
        id_q = LD32(0x060CBB5C);
        rec = LD32(0x060C1AF0);
        if (LD32(0x060C1B10) == 0) {
            len = LDU16(LD32(0x060CBB5C) + 46) + LDU16(rec + 6);
        } else {
            len = LD32(0x060C1B18);
        }
        GCALL7(0x060A0158, LD16(LD32(0x060CBB5C) + 4), LD16(rec) & 48, LD16(LD32(0x060CBB5C) + 40), len, LD16(rec + 2),
               0x060C1AE0, LD16(id_q + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f0606A400(void)
{
    gaddr obj = LD32(0x060CBB5C);
    gaddr quad = 0x060C1AE0;
    int x = LD16(obj + 20) + LD32(0x060C1B08);
    int y;

    ST16(obj + 20, x);
    ST16(quad, x + LD16(LD32(0x060CBB5C) + 36));
    y = LD16(LD32(0x060CBB5C) + 22) + LD32(0x060C1B0C);
    ST16(LD32(0x060CBB5C) + 22, y);
    ST16(quad + 2, LD16(LD32(0x060CBB5C) + 38) + y);
    quad += 4;
    x = LD16(LD32(0x060CBB5C) + 24) + LD32(0x060C1B08);
    ST16(LD32(0x060CBB5C) + 24, x);
    ST16(quad, x + LD16(LD32(0x060CBB5C) + 36));
    y = LD16(LD32(0x060CBB5C) + 26) + LD32(0x060C1B0C);
    ST16(LD32(0x060CBB5C) + 26, y);
    ST16(quad + 2, LD16(LD32(0x060CBB5C) + 38) + y);
    if ((unsigned int)LD32(0x060C1B04) < 803) {
        obj = LD32(0x060CBB5C);
        GCALL5(0x0609FCE8, LD16(obj + 4), (LD16(obj + 40) | 192) & 0xEFC7, LD16(obj + 46), 0x060C1AE0, LD16(obj + 64));
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f0606A4D4(void)
{
    QUAD_SPRITE(0x0609FD9E);
}

void f0606A6E8(void)
{
    QUAD_SPRITE(0x0609FE50);
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

int f0606A9A2(unsigned short n)
{
    gaddr o = OBJ(n);

    ST32(0x060CBB5C, o);
    if (LD16(o + 10) == 0) {
        return 0;
    }
    GCALL2(0x06008A6A, 8, LDU16(o + 44));
    return GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10));
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

void f0606AA58(void)
{
    unsigned short id = LDU16(OBJS + 8);

    if (id != 1)
        do {
            gaddr p = OBJ(id);

            ST32(QUAD_PTR, p);
            ST16(p + 42, LDU16(p + 42) | 32);
            id = LDU16(LD32(QUAD_PTR) + 8);
        } while (AGAIN(id != 1));
}

void f0606AA90(void)
{
    unsigned short id = LDU16(OBJS + 8);

    if (id != 1)
        do {
            gaddr p = OBJ(id);

            ST32(QUAD_PTR, p);
            ST16(p + 42, LDU16(p + 42) & 0xFFDF);
            id = LDU16(LD32(QUAD_PTR) + 8);
        } while (AGAIN(id != 1));
}

void f0606AAC8(gaddr obj, int state)
{
    FRAME(sp, 72);
    gaddr table = sp - 72;

    COPYW(0x06094450, table, 0x060B27D4, 64);
    ST16(obj + 42, (LDU16(obj + 42) & ~15) | state);
    if (LD32(table + (state << 2))) {
        ST16(obj + 10, 1);
        GCALL1(0x0606AB72, obj);
    }
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

void f0606B07E(gaddr obj, int index)
{
    gaddr entry = 0x060B957C + (index << 4);

    ST16(obj + 12, LDU16(entry + 4) >> 8);
    ST16(obj + 10, (LDU16(entry + 4) & 255) << 8);
    ST16(obj + 18, LD16(entry + 2) | 0x3A0);
    ST16(obj + 40, LD16(entry));
    ST16(obj + 52, 0);
    ST16(obj + 44, 0);
    ST8(obj + 6, 0);
    ST16(obj + 56, 0);
    ST16(obj + 54, 0);
    ST16(obj + 58, 0);
    ST16(obj + 60, 0);
    ST16(obj + 62, 0);
    ST16(obj + 76, 0);
    ST16(obj + 38, 0);
    ST16(obj + 90, 8);
    ST16(obj + 88, 8);
}

int f0606B1EC(void)
{
    return 0;
}

int f0606B1F0(int n)
{
    if ((unsigned int)n >= 50)
        return 0;
    do {
        if (LD16(REC(n) + 22) == 0)
            return n;
    } while (AGAIN((unsigned int)++n < 50));
    return 0;
}

void f0606B21C(int arg)
{
    unsigned short saved = LDU16(0x060C062C);

    ST16(0x060C062C, 10);
    while (LDU16(0x060C062C) < 50) {
        POLL();
        if (LD16(REC(LDU16(0x060C062C)) + 22))
            GCALL2(0x0606B29C, LDU16(0x060C062C), arg);
        ST16(0x060C062C, LD16(0x060C062C) + 1);
    }
    ST16(0x060C062C, saved);
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

int f0606B5DC(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr rec;

    if (!LD16(cur + 52))
        return 0;
    rec = REC(LDU16(cur + 52));
    if (LD8(rec + 4) & 192)
        return 1;
    return LD32(OBJ(LDU16(rec + 22))) == 0;
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

int f0606BB4C(void)
{
    gaddr cell = CELL(LD8(LD32(CURRENT) + 65));
    int i;

    ST32(0x060C1F5C, cell);
    if (LDU16(cell + 4) < LDU16(cell + 6) ? GCALL0(0x0606BBF8) : GCALL0(0x0606BBDA))
        return 1;
    i = 0;
    do {
        if (GCALL0(0x0606B648) != 0)
            return 1;
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
    } while (AGAIN(++i < 4));
    return 0;
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

void f0606BBDA(void)
{
    GCALL0(0x0606BC16);
    if (GCALL0(0x0606B648))
        return;
    GJUMP0(0x0606BC2E);
}

int f0606BBF8(void)
{
    GCALL0(0x0606BC2E);
    if (GCALL0(0x0606B648))
        return 1;
    return GJUMP0(0x0606BC16);
}

void f0606BC16(void)
{
    ST16(0x060C1F24, LD16(LD32(0x060C1F5C)) >= 0 ? 1 : 3);
}

void f0606BC2E(void)
{
    ST16(0x060C1F24, LD16(LD32(0x060C1F5C) + 2) >= 0 ? 2 : 4);
}

int f0606BC4A(void)
{
    int i = 0;

    do {
        if (GCALL0(0x0606B648) != 0)
            return 1;
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
    } while (AGAIN(++i < 4));
    return 0;
}

int f0606BC7E(void)
{
    int i = 0;

    do {
        gaddr slot = 0x060C1F38 + LDU16(0x060C1F24) * 2;
        int left = LD16(slot);

        ST16(slot, left - 1);
        if ((left & 0xFFFF) == 0 && GCALL0(0x0606B648) != 0)
            return 1;
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
    } while (AGAIN(++i < 8));
    return 0;
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

int f0606BD74(void)
{
    int i = 0;

    ST16(0x060C1F30, LD16(LD32(CURRENT) + 64));
    do {
        if (!(LDU8(REC(LDU16(0x060C1F30)) + 4) & 128) && GCALL1(0x0606BEBC, LDU16(0x060C1F30)) != 0)
            return 1;
        ST16(0x060C1F30, LD16(0x060C1F30) ^ 1);
    } while (AGAIN(++i < 2));
    return 0;
}

int f0606BDDC(void)
{
    int n = 0;

    ST16(0x060C1F30, LD16(LD32(CURRENT) + 64));
    do {
        if (!(LDU8(REC(LDU16(0x060C1F30)) + 4) & 128) && GCALL1(0x0606BEE2, LDU16(0x060C1F30))) {
            return 1;
        }
        ST16(0x060C1F30, LD16(0x060C1F30) ^ 1);
        n++;
    } while (AGAIN(n < 2));
    return 0;
}

int f0606BE44(void)
{
    int i = 0;

    ST16(0x060C1F30, LD16(LD32(CURRENT) + 64));
    do {
        if (!(LDU8(REC(LDU16(0x060C1F30)) + 4) & 128) && GCALL1(0x0606BF00, LDU16(0x060C1F30)) != 0)
            return 1;
        ST16(0x060C1F30, LD16(0x060C1F30) ^ 1);
    } while (AGAIN(++i < 2));
    return 0;
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

int f0606BF22(void)
{
    int i = 0;

    do {
        if (!(LDU8(REC(i) + 4) & 128) && GCALL1(0x0606BF6C, i) == 0)
            return 0;
    } while (AGAIN(++i < 2));
    return 1;
}

int f0606BF6C(int n)
{
    return LD16(0x060C1F44 + (signed char)(n * 12)) > 15;
}

int f0606BF8C(void)
{
    int i = 0;

    do {
        if (!(LDU8(REC(i) + 4) & 128) && GCALL1(0x0606BFE8, i) != 0)
            return 1;
    } while (AGAIN(++i < 2));
    return 0;
}

int f0606BFE8(int n)
{
    return LD16(0x060C1F44 + (signed char)(n * 12)) < 0;
}

int f0606C006(int a, int b)
{
    int i = 0;

    do {
        if (!(LDU8(REC(i) + 4) & 128) && GCALL3(0x0606C05C, i, a, b) != 0)
            return 1;
    } while (AGAIN(++i < 2));
    return 0;
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

int f0606C114(int a)
{
    int i = 0;

    do {
        if (!(LDU8(REC(i) + 4) & 128) && GCALL2(0x0606C168, i, a) != 0)
            return 1;
    } while (AGAIN(++i < 2));
    return 0;
}

int f0606C168(int n, unsigned int limit)
{
    signed char off = n * 12;
    gaddr p = 0x060C1F42 + off;

    return (unsigned int)(LDU16(p + 8) + LDU16(p + 10)) > limit;
}

int f0606C192(void)
{
    int i = 0;

    while (i < 2) {
        POLL();
        if (!(LDU8(REC(i) + 4) & 192)) {
            switch (LDU8(LD32(CURRENT) + 6)) {
            case 1:
                if (LD16(CELL(i) + 10) == 0 && LD16(CELL(i)) > 0)
                    return 1;
                break;
            case 2:
                if (LD16(CELL(i) + 8) == 0 && LD16(CELL(i) + 2) > 0)
                    return 1;
                break;
            case 3:
                if (LD16(CELL(i) + 10) == 0 && LD16(CELL(i)) < 0)
                    return 1;
                break;
            case 4:
                if (LD16(CELL(i) + 8) == 0 && LD16(CELL(i) + 2) < 0)
                    return 1;
                break;
            }
        }
        i++;
    }
    return 0;
}

int f0606C268(int n)
{
    int v = (unsigned char)LD8(REC(n) + 6);

    return v >= 1 && v <= 4 ? v : 2;
}

int f0606C28A(void)
{
    return GJUMP1(0x0606C292, 2);
}

int f0606C292(int arg)
{
    unsigned short n = LDU16(LD32(CURRENT) + 64);
    int r = GCALL1(0x0606C268, n);

    return GCALL3(0x0606C2B8, arg, n, r);
}

int f0606C2B8(unsigned int count, int cell, int step)
{
    FRAME(sp, 44);
    gaddr table = sp - 40;
    gaddr c = CELL(cell);
    gaddr obj = LD32(CURRENT);
    int x = (LDU16(obj + 24) + 8) & 0xFFF0;
    int y = (LDU16(obj + 28) + 8) & 0xFFF0;
    unsigned int i = 0;

    COPYB(table, 0x060B2844, 20);
    if (count != 0)
        do {
            if (x != 0) {
                int dx = LD16(table + step * 4);

                x += dx;
                ST16(c, LD16(c) + dx);
            }
            i++;
            if (y != 0) {
                int dy = LD16(table + step * 4 + 2);

                y += dy;
                ST16(c + 2, LD16(c + 2) + dy);
            }
        } while (AGAIN(i < count));
    ST16(c + 4, GCALL1(0x060949D0, LD16(c)));
    ST16(c + 8, LDU16(c + 4) >> 4);
    ST16(c + 6, GCALL1(0x060949D0, LD16(c + 2)));
    ST16(c + 10, LDU16(c + 6) >> 4);
    return GCALL0(0x0606BB4C);
}

int f0606C390(unsigned int range)
{
    gaddr cur = LD32(CURRENT);
    gaddr flags = FLAGS_AT(LDU16(cur + 20));
    int step = LD16(0x060B90A0 + LDU8(cur + 6) * 2) * 2;
    unsigned int i = 0;

    if (range == 0)
        range = 0x100;
    do {
        int v;

        flags += step;
        v = LDU16(flags);
        if (v & 32)
            return i + 1;
        if (v & LDU16(cur + 18))
            return 0;
    } while (AGAIN(++i < range));
    return 0;
}

int f0606C4C0(void)
{
    int i = 1;

    do {
        if (LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20) + LD16(0x060B90A0 + i * 2))) & 32)
            return i;
    } while (AGAIN(++i < 5));
    return 0;
}

unsigned short f0606C4FA(void)
{
    int found = 0;

    ST16(0x060C1F32, 1);
    while (LDU16(0x060C1F32) < 5) {
        POLL();
        if (GCALL0(0x0606C640)) {
            ST16(0x060C1F60 + LDU16(0x060C1F32) * 2, LD16(0x060C1F36));
            found++;
        } else {
            ST16(0x060C1F60 + LDU16(0x060C1F32) * 2, 0xFFF);
        }
        ST16(0x060C1F32, LD16(0x060C1F32) + 2);
    }
    if (!found) {
        ST16(0x060C1F32, 0);
        ST16(0x060C1F36, 0);
        return 0;
    }
    ST16(0x060C1F32, (unsigned int)LD16(0x060C1F62) > (unsigned int)LD16(0x060C1F66) ? 3 : 1);
    ST16(0x060C1F36, LD16(0x060C1F60 + LDU16(0x060C1F32) * 2));
    return LDU16(0x060C1F32);
}

int f0606C584(void)
{
    int v = 2;

    for (;;) {
        ST16(0x060C1F32, v);
        if (LDU16(0x060C1F32) >= 5) {
            ST16(0x060C1F32, 0);
            return 0;
        }
        POLL();
        if (GCALL0(0x0606C640) != 0)
            return LDU16(0x060C1F32);
        v = LD16(0x060C1F32) + 2;
    }
}

unsigned short f0606C5D6(void)
{
    int result;

    ST16(0x060C1F32, 2);
    result = GCALL0(0x0606C640);
    ST16(0x060C1F32, result);
    return result;
}

unsigned short f0606C5EA(void)
{
    int tries = 4;
    unsigned int best = 0xFFF;
    unsigned int dir = 0;

    ST16(0x060C1F32, (unsigned char)LD8(LD32(CURRENT) + 6));
    do {
        if (GCALL0(0x0606C640)) {
            if (LDU16(0x060C1F36) < best) {
                best = LDU16(0x060C1F36);
                dir = LDU16(0x060C1F32);
            }
        }
        ST16(0x060C1F32, (LD16(0x060C1F32) & 3) + 1);
    } while (AGAIN(--tries));
    ST16(0x060C1F36, best);
    ST16(0x060C1F32, dir);
    return dir;
}

int f0606C640(void)
{
    int step;

    ST16(0x060C1F36, 0);
    step = LD16(0x060B90A0 + LDU16(0x060C1F32) * 2);
    ST16(0x060C1F34, LD16(LD32(CURRENT) + 20) + step);
    while (LD16(0x060C1F34) != LD16(LD32(CURRENT) + 20)) {
        int flags;

        POLL();
        ST16(0x060C1F36, LD16(0x060C1F36) + 1);
        flags = LDU16(FLAGS_AT(LDU16(0x060C1F34)));
        if (flags & 32)
            return LDU16(0x060C1F32);
        if (flags & (LDU16(LD32(CURRENT) + 18) | 128))
            return 0;
        ST16(0x060C1F34, LD16(0x060C1F34) + step);
    }
    return 0;
}

int f0606C6C2(unsigned int limit)
{
    int link = LD8(0x060D84A3);
    gaddr a;

    limit = (limit & -64) + 64;
    for (;;) {
        a = 0x060D849C + (link & 255) * 38;
        ST32(0x060D8C08, a);
        link = LD8(a + 7);
        if (link == 0)
            return 0;
        POLL();
        if (LDU16(a + 4) >= limit)
            return 1;
    }
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

int f0606C982(void)
{
    gaddr p = 0x060B90A2;
    unsigned int flags = 0;

    do {
        flags |= LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20) + LD16(p)));
        p += 2;
    } while (AGAIN(p < 0x060B90AA));
    return (flags & 32) != 0;
}

int f0606C9BE(int west, int east, int north, int south)
{
    int i;

    for (i = 10; i < 50; i++) {
        gaddr rec = REC(i);
        int dx, dy;

        POLL();
        if (LD16(rec + 22) == 0 || i == LDU16(0x060C062C) || (LDU8(rec + 4) & 192))
            continue;
        dx = LDU16(rec + 24) - LDU16(LD32(CURRENT) + 24);
        dy = LDU16(rec + 28) - LDU16(LD32(CURRENT) + 28);
        if (dx >= west && dx <= east && dy >= north && dy <= south)
            return i;
    }
    return 0;
}

int f0606CA64(void)
{
    int i;

    for (i = 10; i < 50; i++) {
        POLL();
        if (LD16(REC(i) + 22) != 0 && i != LDU16(0x060C062C) && !(LDU8(REC(i) + 4) & 192)
            && LD16(LD32(CURRENT) + 20) == LD16(REC(i) + 20)) {
            return i;
        }
    }
    return 0;
}

void f0606CABE(int delta)
{
    gaddr cur = LD32(CURRENT);
    unsigned int pos = (LDU16(cur + 12) << 16) + LDU16(cur + 10) + delta;

    ST16(LD32(CURRENT) + 12, pos >> 16);
    ST16(LD32(CURRENT) + 10, pos);
}

int f0606CB6C(gaddr obj)
{
    int inv = DIVU(0x10000, LDU16(obj + 68));

    ST16(obj + 70, inv);
    return inv & 0xFFFF;
}

int f0606CB86(gaddr obj)
{
    int inv = DIVU(0x10000, LDU16(obj + 70));

    ST16(obj + 68, inv);
    return inv & 0xFFFF;
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

void f0606CC7A(gaddr obj, int target, int max)
{
    int diff = target - LDU16(obj + 70);
    int step;
    int dist;

    if (!diff)
        return;
    step = max;
    dist = GCALL1(0x060949D0, diff);
    if (dist < step)
        step = dist;
    if (diff < 0)
        step = -step;
    ST16(obj + 70, LD16(obj + 70) + step);
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

void f0606D8E6(int index)
{
    gaddr obj = LD32(CURRENT);

    ST16(obj + 60, 0);
    obj = LD32(CURRENT);
    ST16(obj + 64, 0);
    obj = LD32(CURRENT);
    ST16(obj + 82, 0);
    obj = LD32(CURRENT);
    ST16(obj + 84, 0);
    GCALL1(0x06014820, LD16(0x060C062C));
    GJUMP1(0x060144F4, LD32(0x060B9508 + (index << 2)));
}

int f0606D920(void)
{
    if (!GCALL0(0x0606BB4C))
        return 0;
    GCALL0(0x0606D986);
    return 1;
}

int f0606D93E(void)
{
    if (!GCALL0(0x0606BC4A))
        return 0;
    GCALL0(0x0606D986);
    return 1;
}

int f0606D95C(void)
{
    if (GCALL0(0x0606BC7E) == 0)
        return 0;
    GCALL0(0x0606D986);
    return 1;
}

void f0606D992(void)
{
    ST8(LD32(CURRENT) + 6, LD8(0x060C1F25));
    POLL();
    GJUMP0(0x0606B620);
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

int f0606DAB2(void)
{
    FRAME(sp, 84);
    int variant;

    COPYW(0x060944F4, sp - 84, 0x060B2858, 80);
    variant = GCALL0(0x0600A0B8) & 3;
    ST16(0x060C1F24, LD32(sp - 84 + LDU8(LD32(CURRENT) + 6) * 16 + variant * 4));
    return 0x060C1F24;
}

void f0606DCA8(void)
{
    GJUMP0(0x0606DCBE);
}

void f0606DD00(void)
{
    GJUMP0(0x0606DD44);
}

void f0606DE16(void)
{
    GJUMP0(0x0606DE26);
}

void f0606DE9A(void)
{
    GJUMP0(0x0606DEB0);
}

void f0606DED0(void)
{
    GJUMP0(0x0606DEE6);
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

void f0606E098(void)
{
    GJUMP0(0x0606E0D8);
}

void f0606E19E(void)
{
    GJUMP0(0x0606E1B8);
}

void f0606E228(void)
{
    GJUMP0(0x0606E238);
}

void f0606E38C(void)
{
    GJUMP0(0x0606E39C);
}

void f0606E3C2(void)
{
    GJUMP0(0x0606E3D2);
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

int f0606E9C8(int a, int b, int c, int d)
{
    ST16(LD32(MOVER_PTR) + 48, 8);
    GCALL4(0x0606B6BC, a, b, c, d);
    ST32(0x060E215C + (short)(LD16(0x060C062C) * 20), 0x0606B1EC);
    return 0;
}

void f0606EA3A(int a, int b, int c, int d)
{
    GCALL4(0x0606B6BC, a, b, c, d);
    GCALL1(0x060144F4, 0x0606D398);
    GCALL1(0x06014516, 0x0606E7F4);
    ST32(0x060E2154 + (short)(LD16(0x060C062C) * 20), 0x0606EA6A);
}

int f0606EB5C(void)
{
    int dir;

    if (LD16(LD32(MOVER_PTR) + 48) != 0) {
        return 0;
    }
    dir = GCALL0(0x0606C5EA);
    if (dir == 0) {
        return 0;
    }
    ST8(LD32(CURRENT) + 6, dir);
    ST16(LD32(CURRENT) + 12, 0);
    ST16(LD32(CURRENT) + 10, 0xC000);
    ST16(LD32(MOVER_PTR) + 48, 9);
    GCALL1(0x0606B6BC, dir);
    GCALL1(0x06014516, 0x0606EBCC);
    ST16(LD32(CURRENT) + 58, 10);
    GCALL1(0x06014516, 0x0606E864);
    return 1;
}

int f0606EC68(void)
{
    gaddr cur = LD32(CURRENT);
    int cell = LDU16(cur + 20) + LD16(0x060B90A0 + LDU8(cur + 6) * 2);

    if (!(LDU16(FLAGS_AT(cell)) & 32)) {
        return 0;
    }
    ST16(LD32(MOVER_PTR) + 48, 13);
    GCALL1(0x0606B6BC, cur);
    return 1;
}

void f0606EE32(int unused1, int unused2, int c, int d)
{
    GCALL4(0x0606EE98, 0, 0, c, d);
    GJUMP0(0x060145A8);
}

void f0606EE98(int unused1, int unused2, int c, int d)
{
    ST16(LD32(CURRENT) + 12, 0);
    ST16(LD32(CURRENT) + 10, 0x6000);
    ST16(LD32(MOVER_PTR) + 48, 0);
    GCALL4(0x0606B6BC, 0, CURRENT, c, d);
    GJUMP0(0x0606C7C2);
}

int f0606EF42(void)
{
    if (LD16(LD32(CURRENT) + 66) != 0) {
        return 0;
    }
    GCALL0(0x0606E81C);
    if (!GCALL1(0x0606BEBC, LDU16(LD32(CURRENT) + 64))) {
        return 0;
    }
    GCALL0(0x0606BBB0);
    ST16(LD32(CURRENT) + 66, LD16(0x060C1F24));
    ST16(LD32(CURRENT) + 62, 0x12C);
    GCALL1(0x06014516, 0x0606EFEC);
    return 1;
}

void f0606F1C4(int unused, int b, int c, int d)
{
    gaddr mover = LD32(MOVER_PTR);

    ST16(mover + 48, LD16(mover + 48) + 1);
    if (LDU16(LD32(MOVER_PTR) + 48) >= 8)
        ST16(LD32(MOVER_PTR) + 48, 0);
    GJUMP4(0x0606B6BC, MOVER_PTR, b, c, d);
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

void f0606F330(void)
{
    gaddr slot = LD32(CURRENT) + 74;
    int found = GCALL1(0x060691DA, 100);
    gaddr o;

    ST16(slot, found);
    if ((found & 0xFFFF) == 0)
        return;
    o = OBJ(LDU16(LD32(CURRENT) + 74));
    ST16(o + 44, LD16(LD32(MOVER_PTR) + 44));
    ST16(o + 46, LD16(LD32(MOVER_PTR) + 46) + 2);
    GCALL2(0x0606AAC8, o, 4);
    GJUMP0(0x0606F38C);
}

int f0606F38C(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr dst, rec, src, row;
    int kind, y;

    if (!LD16(cur + 74))
        return 0;
    dst = OBJ(LDU16(cur + 74));
    ST16(dst + 20, GET(Mover, MOVER, x) + LD16(MOVER + 36) - 1);
    ST16(dst + 22, GET(Mover, MOVER, y) + LD16(MOVER + 38) - 24);
    rec = REC(LDU16(LD32(CURRENT) + 52));
    src = OBJ(LDU16(rec + 22));
    kind = (unsigned char)LD8(rec + 6);
    GCALL3(0x060693DC, LDU16(LD32(CURRENT) + 74), LDU16(rec + 22), LD32(0x060BA078 + kind * 4));
    GCALL2(0x06069462, LD16(LD32(CURRENT) + 74), LD16(src + 4));
    row = 0x060BA050 + kind * 8;
    ST16(dst + 24, LD16(src + 16) + LD16(row + 2) - 7);
    y = LD16(src + 18) + LD16(row + 6) - 24;
    ST16(dst + 26, y);
    return y;
}

void f0606F458(void)
{
    gaddr cur = LD32(CURRENT);

    if (LD16(cur + 74)) {
        GCALL1(0x060692DC, LDU16(cur + 74));
        ST16(LD32(CURRENT) + 74, 0);
    }
}

int f0606F482(void)
{
    gaddr cur;

    GCALL0(0x0606F458);
    cur = LD32(CURRENT);
    ST16(cur + 66, 0);
    ST16(cur + 68, 0);
    ST16(cur + 70, 0);
    ST16(cur + 72, 0);
    GCALL2(0x0606AAC8, LD32(MOVER_PTR), 3);
    cur = LD32(CURRENT);
    ST16(cur + 42, LD16(cur + 42) | 128);
    GCALL2(0x0606950C, LD32(MOVER_PTR), 3);
    GCALL1(0x060144F4, 0x0606F520);
    GCALL1(0x0600996A, 59);
    return 1;
}

int f0606F770(int unused, int b, int c, int d)
{
    gaddr mover = LD32(MOVER_PTR);
    int dir, angle;

    if (LD16(LD32(CURRENT) + 60)) {
        dir = 8;
        angle = 0x8000;
    } else {
        dir = 4;
        angle = 0x6000;
    }
    if (LDU16(mover + 48) != dir) {
        ST16(mover + 48, dir);
        GCALL4(0x0606B6BC, mover, b, c, d);
        ST16(LD32(CURRENT) + 12, 0);
        ST16(LD32(CURRENT) + 10, angle);
    }
    return 0;
}

int f0606FE7C(int dir)
{
    int cell = LDU16(LD32(CURRENT) + 20);

    if (!(LDU16(FLAGS_AT(LD16(0x060B90A0 + dir * 2) + cell)) & 144)) {
        return 0;
    }
    return (LDU16(FLAGS_AT(LD16(0x060B90AA + dir * 2) + cell)) & 32) != 0;
}
