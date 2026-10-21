#include "krnl.h"

void f06006218(void)
{
    ST32(0x26006154, 0);
    ST32(0x26006160, 0);
    ST32(0x26006164, 0);
    ST32(0x26006168, 0);
}

void f0600622C(void)
{
    ST32(0x060BBF28, 0);
    GJUMP1(0x06006B38, LD32(0x060BBF24));
}

void f06006368(void)
{
    ST32(0x26006038, LD32(0x26006038) + 1);
}

void f06006652(void)
{
    ST16(0x060B2D20, LD16(0x060B2D20) + 1);
}

/* The first six halfwords of VDP1 VRAM, the first command table entry: skip to the next command
 * with a zero link, then the halfword the game keeps at 060BC12E. */
void f0600665C(void)
{
    H16PTR p = (H16PTR)0x25D00000;

    PUT16(p, 0);
    PUT16(p, 0);
    PUT16(p, 2);
    PUT16(p, 0);
    PUT16(p, 0);
    STORE16(p, LD16(0x060BC12E));
}

/* Records of 88 bytes: sets the first word when the byte at 80 is nonzero. */
void f06006B38(short n)
{
    short off = n * 88;
    REF(Rec88) r = BYTEOFF(Rec88, RECS, off);

    if (GET(Rec88, r, flag))
        SET(Rec88, r, active, 1);
}

/* Counts down the timers of the records of 88 bytes by the ticks since the last call, to a floor of 1. */
void f06006B9C(void)
{
    unsigned int now = LD32(0x26006038);
    unsigned int last = LD32(0x060BD050);
    unsigned int active;
    REF(Rec88) r;
    int i;

    if (now == last)
        return;
    for (i = 0; i < 18; i++) {
        r = ELEM(Rec88, RECS, i);
        if (GET(Rec88, r, flag)) {
            active = GET(Rec88, r, active);
            if (active > 1) {
                if (active > now - last)
                    SET(Rec88, r, active, active - (now - last));
                else
                    SET(Rec88, r, active, 1);
            }
        }
        POLL();
    }
    ST32(0x060BD050, now);
}

int f06006DC8(int n)
{
    int rec;

    if (n >= 18)
        return -1;
    rec = RECS + (short)(n * 88);
    if (LD8(rec + 80) != 1)
        return -1;
    ST8(rec + 80, 2);
    ST8(rec + 81, 0);
    return 0;
}

int f06006F40(short n)
{
    return RECS + (short)(n * 88);
}

void f06006FC6(void)
{
    int i = 0;

    do {
        ST32(0x060BD464 + i * 4, 0);
        ST16(0x26006096 + i * 2, 0);
        ST16(0x260060B0 + i * 2, 0);
        ST16(0x260060CA + i * 2, 0);
        ST16(0x260060E4 + i * 2, 0);
        ST32(0x26006100 + i * 4, 0);
    } while (AGAIN(++i < 13));
}

void f06007326(void)
{
    int i = 0;

    do {
        ST32(0x26006100 + i * 4, 0);
    } while (AGAIN(++i < 13));
}

void f0600733C(void)
{
    ST16(0x060BD05C, 0);
    ST16(0x060BD05A, 0);
    ST16(0x060BD058, 0);
    ST16(0x060BD062, 0);
    ST16(0x060BD060, 0);
    ST16(0x060BD05E, 0);
}

int f060074E8(void)
{
    ST32(0x2600603C, 1);
    return 0x2600603C;
}

/* 'l' and 'h' are skipped, '-' sets the byte at 25, a leading '0' the byte at 26, and digits build up the number at 20. */
int f060075D4(gaddr p, signed char c)
{
    if (c == 'l' || c == 'h')
        return 0;
    if (c == '-') {
        ST8(p + 25, 1);
        return 0;
    }
    if (c < '0' || c > '9')
        return -1;
    if (c == '0' && !LD32(p + 20))
        ST8(p + 26, 1);
    else
        ST32(p + 20, LD32(p + 20) * 10 + (c - '0'));
    return 0;
}

int f0600794E(gaddr p, unsigned char c)
{
    if (LD8(p + 24))
        ST8(p + 24, 0);
    else if (LD8(0x060B2D40 + c) & 0x80)
        ST8(p + 24, c);
    return 0;
}

void f06007A14(void)
{
    ST8(0x060BD4AF, 0);
    ST8(0x060BD4AE, 0);
}

void f06008202(void)
{
    ST16(0x060C1E4E, 0);
    ST16(0x060C1E4C, 0);
    ST16(0x060BD4B0, 1);
}

void f060086E2(void)
{
}

void f060086E6(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060086EA(void)
{
}

void f06008810(void)
{
}

void f060089AC(void)
{
    int i = 0;

    do {
        ST32(0x060BD8C4 + i * 4, -1);
    } while (AGAIN(++i < 4));
}

void f06008A6A(unsigned short i, unsigned int n)
{
    if (n < 4) {
        ST32(0x060BD8E4 + i * 4, LD32(LD32(0x060BD8D4 + n * 4) + i * 4));
        ST16(0x060BD914 + i * 2, n);
    }
}

void f06008AEC(int n)
{
    ST32(0x060BD8C0, LDU16(0x06093F5C + n * 2));
    ST32(0x060BF49C, LD32(0x06093FEC + n * 4));
    ST32(0x060BD8BC, LDU16(0x06093ECC + n * 2));
}

int f06008F28(int a, int k)
{
    if (k < 0x100)
        return (unsigned int)(k * a) >> 8;
    return a + ((unsigned int)((k & 255) * (31 - a)) >> 8);
}

/* Copies each flagged row of 16 colours to color RAM and clears its flag. */
int f060090D8(void)
{
    int flag = LD16(0x26006048);
    int i, j;

    if (flag) {
        for (i = 0; i < LDU16(0x060BF4A8); i++) {
            flag = LD16(0x060CBB60 + i * 2);
            if (flag) {
                j = 0;
                do {
                    ST16(0x25F00000 + i * 32 + j * 2, LD16(0x060CBC60 + i * 32 + j * 2));
                } while (AGAIN(++j < 16));
                ST16(0x060CBB60 + i * 2, 0);
            }
            POLL();
        }
        ST16(0x26006048, 0);
    }
    return flag;
}

void f060093E6(int n, unsigned char v)
{
    if (n)
        ST8(ENTS + (n - 1) * 16 + 12, v);
}

/* Entries of 16 bytes, numbered from 1: clears the byte at 11 and counts it down. */
void f0600940A(int n)
{
    REF(Ent16) e;

    if (n) {
        e = ELEM(Ent16, ENTS, n - 1);
        if (GET(Ent16, e, f)) {
            SET(Ent16, e, f, 0);
            ST8(CNT, LD8(CNT) - 1);
        }
    }
}

void f0600942E(void)
{
    unsigned int i = 1;

    do {
        POLL();                 /* the game's bsr */
        f0600940A(i);
    } while (AGAIN(++i <= 16));
}

void f0600944A(void)
{
    ST8(0x060BF4A1, 1);
}

int f06009452(void)
{
    ST8(0x060BF4A1, 0);
    return 0x060BF4A1;
}

void f0600992C(unsigned char mode)
{
    ST8(0x060B2E84, mode);
    ST8(0x060B2E85, 0);
    ST8(0x060BF4DC, 0);
    ST8(0x060BF4DD, 0);
}

void f06009D06(unsigned int n)
{
    if (LD8(0x060B2E84) == 16) {
        ST8(0x060BF4DC, n > 30 ? 30 : n);
        ST8(0x060BF4DD, LD8(0x060BF4DC) * 7);
    }
}

void f06009ECE(unsigned int n)
{
    POLL();
    if ((unsigned char)LD8(0x060B2E84) == 2) {
        ST8(0x060BF4DC, n > 30 ? 30 : n);
        ST8(0x060BF4DD, LD8(0x060BF4DC) * 7);
    }
}

void f06009FA8(void)
{
    int i = 0;
    int v;

    do {
        v = LD32(0x060BF4FC + i * 4) - LD32(0x060BF578 + i * 4);
        ST32(0x060BF4FC + i * 4, WRAP(v));
    } while (AGAIN(++i < 24));
    i = 0;
    do {
        v = LD32(0x060BF55C + i * 4) - LD32(0x060BF4FC + i * 4);
        ST32(0x060BF55C + i * 4, WRAP(v));
    } while (AGAIN(++i < 31));
}

void f0600A186(REF(Rec14) r)
{
    int sum;

    if (GET(Rec14, r, h0) < GET(Rec14, r, h2)) {
        sum = GET(Rec14, r, h0) + GET(Rec14, r, h4);
        if (sum < GET(Rec14, r, h2)) {
            SET(Rec14, r, h4, sum);
        } else {
            SET(Rec14, r, h4, sum - GET(Rec14, r, h2));
            SET(Rec14, r, b6, GET(Rec14, r, b6) + GET(Rec14, r, b8));
        }
        SET(Rec14, r, b7, GET(Rec14, r, b7) + GET(Rec14, r, b9));
    } else {
        sum = GET(Rec14, r, h2) + GET(Rec14, r, h4);
        if (sum < GET(Rec14, r, h0)) {
            SET(Rec14, r, h4, sum);
        } else {
            SET(Rec14, r, h4, sum - GET(Rec14, r, h0));
            SET(Rec14, r, b7, GET(Rec14, r, b7) + GET(Rec14, r, b9));
        }
        SET(Rec14, r, b6, GET(Rec14, r, b6) + GET(Rec14, r, b8));
    }
}

/* Zeroes the bytes at 6 and 7, then runs f0600A186 on the same record. */
void f0600A1F4(gaddr p)
{
    ST8(p + 7, 0);
    ST8(p + 6, 0);
    GJUMP1(0x0600A186, p);
}

/* Objects of 84 bytes: adds d to the 32-bit value held as two halfwords at 12 (low) and 16 (high). */
void f0600A25E(int d)
{
    REF(Obj84) o = BYTEOFF(Obj84, OBJS, (unsigned short)(LDU16(OBJIDX) * 84));
    unsigned int v = ((unsigned int)GET(Obj84, o, w16) << 16) + (unsigned short)GET(Obj84, o, w12) + d;

    SET(Obj84, o, w16, v >> 16);
    SET(Obj84, o, w12, v);
}

void f0600A28C(short d)
{
    GJUMP1(0x0600A25E, d * 256);
}

void f0600A2B0(signed char d)
{
    REF(Obj84) o = BYTEOFF(Obj84, OBJS, (unsigned short)(LDU16(OBJIDX) * 84));
    unsigned int v = ((unsigned int)GET(Obj84, o, w16) << 16) + (unsigned short)GET(Obj84, o, w12) + d * 0x1000;

    SET(Obj84, o, w16, v >> 16);
    SET(Obj84, o, w12, v);
}

/* The same at 14 (low) and 18 (high). */
void f0600A2D8(int d)
{
    REF(Obj84) o = BYTEOFF(Obj84, OBJS, (unsigned short)(LDU16(OBJIDX) * 84));
    unsigned int v = ((unsigned int)GET(Obj84, o, w18) << 16) + (unsigned short)GET(Obj84, o, w14) + d;

    SET(Obj84, o, w18, v >> 16);
    SET(Obj84, o, w14, v);
}

/* Adds the sign-extended halfword, times 256, to the object's 32-bit value at 14 and 18. */
void f0600A306(short d)
{
    GJUMP1(0x0600A2D8, d * 256);
}

/* Adds the low byte, signed, times 0x1000 to the 32-bit value at 14 (low) and 18 (high). */
void f0600A32A(signed char d)
{
    REF(Obj84) o = BYTEOFF(Obj84, OBJS, (unsigned short)(LDU16(OBJIDX) * 84));
    unsigned int v = ((unsigned int)GET(Obj84, o, w18) << 16) + (unsigned short)GET(Obj84, o, w14) + d * 0x1000;

    SET(Obj84, o, w18, v >> 16);
    SET(Obj84, o, w14, v);
}

/* Copies one object's fields to another's; the halfwords at 36 and 38 only when bit 0 of flags is set. */
void f0600A378(unsigned short from, unsigned short to, int flags)
{
    int src = OBJ(from);
    int dst = OBJ(to);
    int off;

    for (off = 12; off < 20; off += 2)
        ST16(dst + off, LD16(src + off));
    if (flags & 1) {
        ST16(dst + 36, LD16(src + 36));
        ST16(dst + 38, LD16(src + 38));
    }
    for (off = 20; off < 36; off += 2)
        ST16(dst + off, LD16(src + off));
}

void f0600A3D8(unsigned short from, unsigned short to)
{
    POLL();
    f0600A378(from, to, 0);
}

void f0600A3DC(unsigned short from, unsigned short to)
{
    int src = OBJ(from);
    int dst = OBJ(to);
    int off;

    POLL();
    for (off = 12; off < 20; off += 2)
        ST16(dst + off, LD16(src + off));
    ST16(dst + 36, LD16(src + 36));
    ST16(dst + 38, LD16(src + 38));
    for (off = 20; off < 36; off += 2)
        ST16(dst + off, LD16(src + off));
}

void f0600A3E0(REF(Pos) p, gaddr b, int c)
{
    SET(Pos, p, w20, GET(Pos, p, w16) - c);
    SET(Pos, p, w24, GET(Pos, p, w16) + GETB(b, 0) - GETB(b, 2) + c);
}

/* The highest of four pad bits: 0x4000 is 3, 0x2000 is 2, 0x8000 is 1, 0x1000 is 4. */
int f0600A4B0(unsigned int x)
{
    if (x & 0x4000)
        return 3;
    if (x & 0x2000)
        return 2;
    if (x & 0x8000)
        return 1;
    if (x & 0x1000)
        return 4;
    return 0;
}

int f0600AA8A(int n)
{
    switch (n) {
    case 1:
        return LDU16(0x060FA9D8) >> 15;
    case 2:
    case 4:
        return LDU16(0x060FA9D0) >> 15;
    case 8:
        return LDU16(0x060FA9D2) >> 15;
    case 16:
        return LDU16(0x060FA9D4) >> 15;
    case 32:
        return LDU16(0x060FA9D6) >> 15;
    }
    return n;
}

void f0600AC1E(int buttons)
{
    int i;

    for (i = 0; i < 4; i++)
        if (buttons & (4 << i))
            ST16(0x060FA9C0, LD16(0x060FA9C0) | 1 << i);
    if (buttons)
        ST16(0x060FA9A0, LD16(0x060FA9A0) | 0x8000);
    ST16(0x060BB8FC, 1);
}

void f0600AC90(int mask)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (mask & (4 << i))
            ST16(0x060FA9C0, LD16(0x060FA9C0) & ~(1 << i));
    }
    if ((LD16(0x060FA9C0) & 15) == 0)
        ST16(0x060FA9A0, LD16(0x060FA9A0) & 0x7FFF);
    ST16(0x060BB8FC, 1);
}

void f0600AD62(int a, unsigned short b)
{
    ST32(0x2600615C, a);
    ST16(0x26006158, b);
}

/* Each halfword is also kept at 060BF5DA + off. */
#define COPY_KEEP(off) \
    do { \
        int w = LD16(src + (off)); \
        ST16(dst + (off), w); \
        ST16(0x060BF5DA + (off), w); \
    } while (0)

void f0600B41A(int slot, unsigned short id)
{
    int dst = 0x060BF5EC + slot * 16;
    int src = 0x060B2EB0 + id * 16;

    ST16(dst, id);
    COPY_KEEP(2);
    COPY_KEEP(4);
    COPY_KEEP(10);
    COPY_KEEP(6);
    COPY_KEEP(8);
    COPY_KEEP(12);
    COPY_KEEP(14);
}

#undef COPY_KEEP

int f0600B8F0(void)
{
    if (!LDU16(0x060BF5EA))
        return 0;
    if ((unsigned int)(LDU16(0x060C02AA) - LD32(0x060C1000)) > 0x4B0
        || (LDU16(0x260060AE) & 0xE00)
        || (LDU16(0x060D7E68) & 0x40)) {
        ST16(0x060D7E68, LD16(0x060D7E68) | 0x440);
        return 1;
    }
    return 0;
}

int f0600B934(int n, int m)
{
    return (10 * n + m) * 152 + 0x00207F74;
}

int f0600B950(int n, int m)
{
    return (10 * n + m) * 16 + 0x060B30C4;
}

int f0600BD3C(void)
{
    unsigned char kind = LD8(0x060C029C);

    if (kind == 17)
        return 196;
    if (kind >= 9)
        return LD16(0x060B356E + (unsigned char)LD8(0x060C029D) * 2);
    if (kind == 8)
        return 0x404;
    return 0;
}

void f0600C364(void)
{
    int i;

    i = 0;
    do {
        ST16(0x060F08B0 + i * 2, 0);
        ST16(0x060EE8B0 + i * 2, 0);
        ST16(0x060EC8B0 + i * 2, 0);
    } while (AGAIN(++i < 0x1000));
    ST16(0x060D7E6A, 0);
    i = 0;
    do {
        ST16(0x060D7E6C + i * 2, 0);
        ST32(0x060D7EA4 + i * 4, 0);
        ST16(0x060D7E74 + i * 2, 0);
    } while (AGAIN(++i < 4));
}

void f0600C434(void)
{
    ST32(0x060D7E98, LD32(0x060D7E9C));
    ST32(0x060D7E94, 0x060F28B0);
    ST32(0x060D7EA0, LD32(0x060D7EA4));
}

void f0600C44C(void)
{
    ST32(0x060D7E98, LD32(0x060D7E9C));
    ST32(0x060D7E94, 0x060F48B0);
    ST32(0x060D7EA0, LD32(0x060D7EA8));
}

void f0600C4B0(void)
{
    ST32(0x060D7E98, LD32(0x060D7E9C));
    ST32(0x060D7E94, 0x060F68B0);
    ST32(0x060D7EA0, LD32(0x060D7EAC));
}

void f0600C4C8(void)
{
    ST32(0x060D7E98, LD32(0x060D7E9C));
    ST32(0x060D7E94, 0x060F88B0);
    ST32(0x060D7EA0, LD32(0x060D7EB0));
}

void f0600C4E0(int n)
{
    int buf, src;

    switch (n) {
    case 1:
        buf = 0x060F48B0;
        src = 0x060D7EA8;
        break;
    case 2:
        buf = 0x060F68B0;
        src = 0x060D7EAC;
        break;
    case 3:
        buf = 0x060F88B0;
        src = 0x060D7EB0;
        break;
    default:
        GJUMP0(0x0600C434);
        return;
    }
    POLL();
    ST32(0x060D7E98, LD32(0x060D7E9C));
    ST32(0x060D7E94, buf);
    ST32(0x060D7EA0, LD32(src));
}

unsigned short f0600C950(int x, int y)
{
    ST16(0x060D7E8C, y * 64 + x);
    return y * 64 + x;
}

int f0600C962(unsigned short x, unsigned short y)
{
    return ((y >> 5) << 15) + ((x >> 5) << 14) + ((y & 31) << 9) + ((x & 31) << 3);
}

int f0600C9AA(unsigned short v)
{
    ST16(0x060D7EB6, v >> 6);
    ST16(0x060D7EB4, v & 63);
    return v & 63;
}

int f0600C9C0(unsigned short pos)
{
    unsigned int row = pos >> 6;
    unsigned int col = pos & 63;
    unsigned int row_a = LDU16(0x060D7E7E);
    unsigned int row_b = LDU16(0x060D7E82);
    unsigned int col_a = LDU16(0x060D7E7C);
    unsigned int col_b = LDU16(0x060D7E80);

    if (row >= row_a - 1) {
        if (row > row_b)
            row = row_a - 1;
    } else {
        row = row_b;
    }
    if (col >= col_a) {
        if (col > col_b - 1)
            col = col_a;
    } else {
        col = col_b - 1;
    }
    return row * 64 + col;
}

unsigned short f0600CA7C(void)
{
    int x, y;

    GCALL1(0x0600C90C, LDU16(OBJIDX));
    x = (LDU16(0x060D7E88) + 8) >> 4;
    y = (LDU16(0x060D7E8A) + 8) >> 4;
    POLL();
    ST16(0x060D7EB4, x);
    ST16(0x060D7EB6, y);
    ST16(0x060D7E8C, y * 64 + x);
    return y * 64 + x;
}

unsigned short f0600CAE4(unsigned short px, unsigned short py)
{
    int x = (px + 8) >> 4;
    int y = (py + 8) >> 4;

    ST16(0x060D7EB4, x);
    ST16(0x060D7EB6, y);
    POLL();
    return f0600C950(LDU16(0x060D7EB4), y);
}

void f0600CDC4(int i, short bits)
{
    ST16(0x060EC8B0 + i * 2, LD16(0x060EC8B0 + i * 2) | bits);
}

int f0600CE24(void)
{
    int i;

    ST16(0x060BB8FC, 0);
    for (i = 0; i < 8; i++)
        ST32(0x060FAA10 + i * 4, LD32(0x060C0328 + i * 4));
    for (i = 0; i < 4; i++)
        ST16(0x060FAA30 + i * 2, LD16(0x060C0348 + i * 2));
    ST16(0x060BB8FC, 1);
    return 38;
}

void f0600CECE(short x0, short y0, int x1, int y1)
{
    int mode = (unsigned char)LD8(0x060C029C);
    int over;

    ST16(0x060D7E7C, x0);
    ST16(0x060D7E7E, y0);
    ST16(0x060D7E80, x1);
    ST16(0x060D7E82, y1);
    ST16(0x060D82BE, x0 * 16);
    ST16(0x060D82C0, y0 * 16);
    over = x1 * 16 - (mode == 17 ? 0x160 : 16) - LDU16(0x060D82BE) - 320;
    ST16(0x060D82C2, LD16(0x060D82BE));
    if (over > 0)
        ST16(0x060D82C2, LD16(0x060D82C2) + over);
    over = (mode == 17 ? -224 : 16) + y1 * 16 - LDU16(0x060D82C0) - 224;
    ST16(0x060D82C4, LD16(0x060D82C0));
    if (over > 0)
        ST16(0x060D82C4, LD16(0x060D82C4) + over);
}

void f0600CFC6(short x, short y)
{
    int dy = LD8(0x060C029C) != 17 ? -16 : 0;
    int px;
    int py;

    ST16(0x060D82BA, x * 16);
    ST16(0x060D82BC, y * 16);
    px = LD16(0x060D82BA) + 8;
    py = LD16(0x060D82BC) + dy;
    ST32(0x060C0338, (px << 16) & 0x3FFF0000);
    ST32(0x060C0328, (px << 16) & 0x3FFF0000);
    ST32(0x060C033C, (py << 16) & 0x3FFF0000);
    ST32(0x060C032C, (py << 16) & 0x3FFF0000);
    ST16(0x060C034C, px & 0x3FFF);
    ST16(0x060C0348, px & 0x3FFF);
    ST16(0x060C034E, py & 0x3FFF);
    ST16(0x060C034A, py & 0x3FFF);
}

void f0600D026(int i, int a, int b)
{
    int bit = LD16(0x060D7E74 + i * 2);

    if ((a | b) == 0) {
        ST16(0x060D82C6, LD16(0x060D82C6) & ~bit);
    } else {
        ST16(0x060D82C6, LD16(0x060D82C6) | bit);
        ST32(0x060C02D8 + (signed char)(i * 20) + 8, a);
        ST32(0x060C02D8 + (signed char)(i * 20) + 12, b);
    }
}

int f0600D08A(void)
{
    return GJUMP1(0x0600D066, LDU16(OBJIDX));
}

int f0600D0D0(void)
{
    return (unsigned char)LD8(0x060C029C) == 17 ? 8 : 24;
}

void f0600D16A(unsigned short i)
{
    REF(Obj84) o = BYTEOFF(Obj84, OBJS, (unsigned short)(i * 84));
    int dx = LD16(0x060D82BA);
    int dy;

    SET(Obj84, o, w16, ((GET(Obj84, o, w16) + dx + 8) & -16) - dx);
    dy = LD16(0x060D82BC);
    SET(Obj84, o, w18, (((GET(Obj84, o, w18) + dy) & -16) - dy) + 8);
}

void f0600D19E(void)
{
    f0600D16A(LDU16(OBJIDX));
}

void f0600D2BE(int mask, unsigned short amt)
{
    int base;

    if (amt == 0)
        return;
    base = LD32(0x26006160) == 0x0600CE24 ? 0x060C0328 : 0x060FAA10;
    if (mask & 4)
        ST32(base, (LD32(base) + (amt << 16)) & 0x3FFF0000);
    if (mask & 8)
        ST32(base + 16, (LD32(base + 16) + (amt << 16)) & 0x3FFF0000);
    if (mask & 16)
        ST16(base + 32, (LD16(base + 32) + amt) & 0x3FFF);
    if (mask & 32)
        ST16(base + 36, (LD16(base + 36) + amt) & 0x3FFF);
}

void f0600D3D4(int mask, unsigned short n)
{
    int base;

    if (!n)
        return;
    base = LD32(0x26006160) == 0x0600CE24 ? 0x060C0328 : 0x060FAA10;
    if (mask & 4)
        ST32(base + 4, (LD32(base + 4) + (n << 16)) & 0x3FFF0000);
    if (mask & 8)
        ST32(base + 20, (LD32(base + 20) + (n << 16)) & 0x3FFF0000);
    if (mask & 16)
        ST16(base + 34, (LD16(base + 34) + n) & 0x3FFF);
    if (mask & 32)
        ST16(base + 38, (LD16(base + 38) + n) & 0x3FFF);
}

void f0600D8F8(void)
{
    ST16(0x060D82CA, 128);
}

void f0600D900(void)
{
    ST16(0x060D82CA, 0);
}

void f0600FE44(void)
{
    int i = 0;
    int rec;

    do {
        rec = 0x060C0910 + i * 16;
        ST32(rec, 0);
        ST32(rec + 4, 0);
        ST32(rec + 8, 0);
        ST16(rec + 12, 0);
        ST16(rec + 14, 0);
    } while (AGAIN(++i < 10));
    i = 0;
    do {
        ST32(0x060C09B0 + i * 4, 0);
    } while (AGAIN(++i < 20));
}
