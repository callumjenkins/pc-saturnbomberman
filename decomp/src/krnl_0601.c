#include "krnl.h"

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

void f06011642(short bits)
{
    int i = LDU16(0x060C062C) * 2;

    ST16(0x260060B0 + i, LD16(0x260060B0 + i) | bits);
    ST16(0x26006096 + i, LD16(0x26006096 + i) | bits);
    ST16(0x260060CA + i, LD16(0x260060CA + i) | bits);
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

void f06012C7C(gaddr p)
{
    ST8(p + 28, 3);
    ST32(p, 0x06012C88);
}

int f060139AC(gaddr a, gaddr b)
{
    if (LDU16(a) & 183)
        return 0;
    return (LDU16(b) & 0xF00) < 0x300;
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

void f060144E4(int n, int v)
{
    ST32((OBJECTS + 0x30) + n * 124, v);
}

void f060144F4(int v)
{
    POLL();
    ST32((OBJECTS + 0x30) + LDU16(0x060C062C) * 124, v);
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

int f06015E96(int n)
{
    gaddr p = 0x060D5F30 + n * 124;
    unsigned int x = (((unsigned int)LDU16(p + 12) << 16) + LDU16(p + 10) - 0xC000) >> 13;

    return x > 9 ? 9 : x;
}

int f06015F48(gaddr p)
{
    if (LD16(p + 42))
        return 42;
    ST16(p + 42, LD16(LD32(0x060D7768) + 42));
    ST16(p + 44, LD16(LD32(0x060D7768) + 44));
    return GJUMP1(0x0600996A, 0x101);
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

void f0601AE68(void)
{
    int bomber = LD32(CURRENT);
    int other = LD32(0x060D7B3C);

    ST32(CURRENT, LD32(0x060D8310));
    ST32(0x060D7B3C, LD32(0x060D8314));
    ST32(0x060D8310, bomber);
    ST32(0x060D8314, other);
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
