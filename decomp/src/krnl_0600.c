#include "krnl.h"

void f0600620C(void)
{
    ST16(0xFFFFFE92, 17);
}

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

int f060062BC(void)
{
    int mask = LD32(0x2600614C);
    int i = 0;

    do {
        if (mask < 0 && ((mask >> i) & 1) && (LDU16(0x26006096 + i * 2) & 0xF00) == 0xF00) {
            ST32(0x2600614C, 1);
            return 1;
        }
    } while (AGAIN(++i < 12));
    return 0;
}

void f06006368(void)
{
    ST32(0x26006038, LD32(0x26006038) + 1);
}

void f060065FC(gaddr dst, int value, int size)
{
    int i = 0;

    if (size > 0) {
        do {
            i += 2;
            ST16(dst, value);
            dst += 2;
        } while (AGAIN(i < size));
    }
}

int f06006626(gaddr dst, int value, int end)
{
    int n = dst & end;

    if (n <= end) {
        do {
            n += 2;
            ST16(dst, value);
            dst += 2;
        } while (AGAIN(n <= end));
    }
    return dst;
}

void f0600663C(gaddr dst, int value, int limit)
{
    int n = dst & limit;

    if (n > limit)
        return;
    do {
        ST32(dst, value);
        n += 4;
        dst += 4;
    } while (AGAIN(n <= limit));
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

void f060066A4(void)
{
    gaddr src = 0x060BC130;
    gaddr dst = 0x25C00000;
    int i = 0;

    GCALL3(0x060065FC, 0x060BC130, 0, 96);
    ST16(0x060BC130, 9);
    ST16(0x060BC144, 0x13F);
    ST16(0x060BC146, LD16(0x060BC12C));
    ST16(0x060BC150, 10);
    ST16(0x060BC170, -32768);
    POLL();
    do {
        i += 2;
        ST16(dst, LD16(src));
        src += 2;
        dst += 2;
    } while (AGAIN(i < 96));
}

void f060066D8(void)
{
    ST32(0x060B2D24, GCALL3(0x0600663C, LD32(0x060B2D24), 0, 0x0001FFFC));
}

void f060066EC(void)
{
    ST32(0x060B2D28, GCALL3(0x06006626, LD32(0x060B2D28), 0, 0x1FE));
}

int f06006700(int mode)
{
    if (mode == 0) {
        ST8(0x2010001F, 7);
    } else if (mode == 1) {
        ST8(0x25B00400, 2);
        GCALL3(0x0600663C, 0x25A00000, 0x400, 0x3FC);
        ST32(0x25A00000, 0x0007FFFC);
        ST32(0x25A00400, 0x4E7160FC);
        return 0x25A00400;
    } else if (mode == 2) {
        ST8(0x2010001F, 6);
    }
    return mode;
}

void f06006742(void)
{
    int ch = 0;

    do {
        ST32(0xFFFFFF80 + ch * 16, 0);
        ST32(0xFFFFFF84 + ch * 16, 0);
        ST32(0xFFFFFF88 + ch * 16, 1);
        (void)LD32(0xFFFFFF8C + ch * 16);
        ST32(0xFFFFFF8C + ch * 16, 0);
        ST8(0xFFFFFE71 + ch, 0);
    } while (AGAIN(++ch < 2));
    (void)LD32(0xFFFFFFB0);
    ST32(0xFFFFFFB0, 0);
    ST32(0xFFFFFFB8, 0);
}

void f06006780(void)
{
    int i;

    ST32(0x25FE0080, 0);
    i = 0x100;
    do {
        ST32(0x25FE0084, 0xF0000000);
    } while (AGAIN(--i != 0));
    i = 0;
    do {
        ST32(0x25FE0088, i);
        ST32(0x25FE008C, 0);
    } while (AGAIN(++i < 0x100));
}

void f060067F8(void)
{
    gaddr p = 0x25B00800;
    int i = 0;

    POLL();
    do {
        ST16(p, 0);
        p += 2;
        i += 2;
    } while (AGAIN(i < 0x400));
}

void f0600687A(int n)
{
    int rec = RECS + (short)(n * 88);
    signed char parent = LD8(rec + 82);
    int p, i;

    if (parent == -1) {
        i = 0;
        do {
            if (LD8(RECS + i * 88 + 82) == n)
                ST8(RECS + i * 88 + 82, -1);
        } while (AGAIN(++i < 18));
    } else {
        p = RECS + (short)(parent * 88);
        ST8(p + 83, LD8(p + 83) - 1);
        ST8(rec + 82, -1);
        i = 0;
        do {
            if (LD8(RECS + i * 88 + 82) == n && LD8(RECS + i * 88 + 80)) {
                ST8(RECS + i * 88 + 82, parent);
                ST8(p + 83, LD8(p + 83) + 1);
            }
        } while (AGAIN(++i < 18));
        if (!LD8(p + 83) && (unsigned char)LD8(p + 81) == 4)
            GCALL1(0x06006B38, parent);
    }
    ST8(rec + 83, 0);
}

int f060069B2(int a, int b, int c, int d)
{
    return GCALL5(0x06006AA0, a, b, c, d, 0);
}

int f060069C2(int a, int b, int c, int d)
{
    return GCALL5(0x06006AA0, a, b, c, d, 1);
}

int f06006AA0(int a, gaddr buf, int size, int d)
{
    FRAME(sp, 0);
    gaddr rec = RECS;
    int n;

    do {
        if (LD8(rec + 80) != 0 && LD32(rec + 20) == buf)
            GCALL0(0x06006808);
        rec += 88;
    } while (AGAIN(rec < RECS + 18 * 88));
    if (LD32(sp) != 0) {
        n = 17;
        do {
            if (GCALL5(0x060069D2, a, buf, (unsigned)size >> 2, d, n) == n)
                return n;
            n--;
        } while (AGAIN(n >= 0));
    } else {
        n = 0;
        do {
            if (GCALL5(0x060069D2, a, buf, (unsigned)size >> 2, d, n) == n)
                return n;
            n++;
        } while (AGAIN(n < 18));
    }
    GCALL0(0x06006808);
    return -1;
}

/* Records of 88 bytes: sets the first word when the byte at 80 is nonzero. */
void f06006B38(short n)
{
    short off = n * 88;
    REF(Rec88) r = BYTEOFF(Rec88, RECS, off);

    if (GET(Rec88, r, flag))
        SET(Rec88, r, active, 1);
}

int f06006B56(int id)
{
    int result;
    int i = 0;

    do {
        gaddr rec = RECS + i * 88;

        result = 81;
        if (LDU8(rec + 81) == id) {
            ST8(rec + 81, 0);
            result = GCALL5(0x06006B38, i, 0, 0, 0, id);
        }
    } while (AGAIN(++i < 18));
    return result;
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

int f06006E34(int n)
{
    int count = 0;
    int i = 0;

    do {
        if (LD8(RECS + (short)(i * 88) + 82) == n) {
            GCALL1(0x06006E34, i);
            if (GCALL1(0x06006DC8, i) == 0)
                count++;
        }
    } while (AGAIN(++i < 18));
    return count;
}

int f06006F40(short n)
{
    return RECS + (short)(n * 88);
}

void f06006FBA(int a)
{
    POLL();
    GJUMP1(0x06006B56, a + 1);
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

void f060073B8(void)
{
    ST32(0x060BD054, GCALL4(0x060069B2, 0x06007014, 0x060BD064, 0x400, 1));
    ST32(0x26006150, 1);
    ST32(0x26006148, 0xFFFF);
    GJUMP0(0x0600733C);
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

int f060079B6(gaddr cursor, char c)
{
    ST8(LD32(cursor), c);
    ST8(LD32(cursor) + 1, 0);
    ST32(cursor, LD32(cursor) + 1);
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

void f06008214(void)
{
    ST16(0x060C034C, 8);
    ST16(0x060FAA34, 8);
    ST16(0x060C034E, 0xFFF0);
    ST16(0x060FAA36, 0xFFF0);
    ST16(0x060BB8FC, 1);
    GJUMP1(0x0603176E, 50);
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

int f060088E2(void)
{
    GCALL0(0x06008202);
    GCALL0(0x06007A14);
    GCALL0(0x060086EA);
    if (LD16(0x060BD4AC) == 0)
        return 0;
    return GJUMP4(0x060069B2, 0x0600890C, 0x060BD4BC, 0x400, 1);
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

void f06008A96(int n)
{
    int i = 0;

    do {
        GCALL2(0x06008A6A, i, n);
    } while (AGAIN(++i < 12));
}

int f06008ABA(unsigned short id, unsigned short bank)
{
    return LD32(LD32(0x060BD8E4 + bank * 4) + (id - 1) * 4);
}

int f06008ACC(unsigned short n)
{
    return LD32(LD32(LD32(0x060BD904)) + (n - 1) * 4);
}

int f06008ADC(unsigned short n)
{
    return LD32(LD32(LD32(0x060BD904) + 4) + (n - 1) * 4);
}

void f06008AEC(int n)
{
    ST32(0x060BD8C0, LDU16(0x06093F5C + n * 2));
    ST32(0x060BF49C, LD32(0x06093FEC + n * 4));
    ST32(0x060BD8BC, LDU16(0x06093ECC + n * 2));
}

int f06008C7A(gaddr out, gaddr filter)
{
    FRAME(sp, 40);
    gaddr buf = sp - 40;
    gaddr rec = 0x060BF198;
    int count = 0;

    do {
        if (LD8(rec + 12) != 0) {
            gaddr ext = GCALL2(0x06094A24, rec + 12, 46);

            if (ext != 0) {
                gaddr token = GCALL2(0x06094A24, filter, 46);

                while (token != 0) {
                    POLL();
                    GCALL3(0x060949E0, buf, token, 8);
                    GCALL2(0x06094A7C, buf + 1, 0x060B1AC4);
                    token++;
                    if (GCALL2(0x06094A44, ext, buf) == 0) {
                        GCALL2(0x06094A58, out + 4, rec + 12);
                        ST32(out, LD32(rec + 4));
                        out += 20;
                        count++;
                    }
                    token = GCALL2(0x06094A24, token, 46);
                }
            }
        }
        rec += 24;
    } while (AGAIN(rec < 0x060BF498));
    return count;
}

void f06008D5C(void)
{
    gaddr p;
    int i;

    ST16(0x26006048, 0);
    GCALL3(0x0600A49C, 0x060CBB60, 0, 128);
    GCALL3(0x0600A49C, 0x060CBC60, 0, 0x800);
    GCALL3(0x0600A49C, 0x060CCC60, 0, 0x800);
    i = 0;
    do {
        p = 0x060BF4AA + i * 10;
        ST16(p, 0xFFF);
        ST16(p + 2, 0xFFF);
        ST16(p + 4, 0xFFF);
        ST16(p + 6, 0xFFF);
        ST16(p + 8, 0xFFF);
    } while (AGAIN(++i < 4));
    ST16(0x060BF4A8, GCALL0(0x0609C062) ? 128 : 64);
}

void f06008DB6(void)
{
    int i;

    GCALL0(0x06008D5C);
    i = 0;
    do {
        SET(Ent16, ELEM(Ent16, ENTS, i), f, 0);
    } while (AGAIN(++i < 16));
    ST8(CNT, 0);
    ST32(CNT + 4, -1);
    ST8(CNT + 1, 0);
    ST32(0x26006168, 0x060090D8);
}

int f06008DE8(void)
{
    GCALL0(0x06008D5C);
    GCALL3(0x0600A49C, 0x060CBB60, 1, LDU16(0x060BF4A8));
    ST16(0x26006048, 1);
    return 0x060BF4A8;
}

/* Copies a run of colours from the table GCALL2(0x06008ABA, id, 1) names into both palette copies,
 * marks each row of 16 as dirty, then uploads them unless an upload is already pending. */
static int load_colors(unsigned short id, unsigned short first)
{
    gaddr src = GCALL2(0x06008ABA, id, 1);
    gaddr colors, copy;
    unsigned short count;
    int v;

    if (first >= 0x8000)
        first = LDU16(src) >> 1;
    src += 2;
    colors = 0x060CBC60 + first * 2;
    copy = 0x060CCC60 + first * 2;
    count = LDU16(src);
    src += 2;
    ST16(0x26006048, 0);
    while (count) {
        POLL();
        v = LD16(src);
        src += 2;
        ST16(colors, v);
        count--;
        ST16(copy, v);
        colors += 2;
        copy += 2;
        ST16(0x060CBB60 + (first >> 4) * 2, 1);
        first++;
    }
    ST16(0x26006048, 1);
    if (LD32(0x26006168))
        return LD32(0x26006168);
    return GJUMP0(0x060090D8);
}

int f06008ECA(unsigned short id, unsigned short first)
{
    POLL();
    return load_colors(id, first);
}

int f06008ECE(unsigned short id)
{
    POLL();
    return load_colors(id, 0x8000);
}

void f06008EE8(int first, int last)
{
    gaddr dst = 0x060CBC60 + first * 2;
    gaddr src = 0x060CCC60 + first * 2;
    int count = last - first + 1;

    POLL();
    while (count != 0) {
        POLL();
        ST16(dst, LD16(src));
        src += 2;
        dst += 2;
        count--;
    }
}

void f06008F08(int first, int last)
{
    gaddr dst = 0x060CCC60 + first * 2;
    gaddr src = 0x060CBC60 + first * 2;
    int count = last - first + 1;

    POLL();
    while (count != 0) {
        POLL();
        ST16(dst, LD16(src));
        src += 2;
        dst += 2;
        count--;
    }
}

int f06008F28(int a, int k)
{
    if (k < 0x100)
        return (unsigned int)(k * a) >> 8;
    return a + ((unsigned int)((k & 255) * (31 - a)) >> 8);
}

/* The fifth and sixth arguments are on the stack: the blue mask and the flag that reads from the second table. */
void f06008F50(unsigned int first, unsigned int last, int red, int green)
{
    FRAME(sp, 0);
    int blue = LD32(sp);
    gaddr dst = 0x060CBC60 + 2 * first;
    gaddr src = LD32(sp + 4) ? 0x060CCC60 + 2 * first : dst;

    ST16(0x26006048, 0);
    if (first <= last) {
        do {
            int c = LDU16(src);
            int r = c & 31;
            int g = (c >> 5) & 31;
            int b = (c >> 10) & 31;

            if (!(red & 0x8000) || r != 0)
                r = GCALL2(0x06008F28, r, red & 0x7FFF);
            if (!(green & 0x8000) || g != 0)
                g = GCALL2(0x06008F28, g, green & 0x7FFF);
            if (!(blue & 0x8000) || b != 0)
                b = GCALL2(0x06008F28, b, blue & 0x7FFF);
            ST16(dst, (c & 0x8000) | r | (g << 5) | (b << 10));
            ST16(0x060CBB60 + ((first >> 4) << 1), 1);
            first++;
            dst += 2;
            src += 2;
        } while (AGAIN(first <= last));
    }
    ST16(0x26006048, 1);
}

void f06009078(int first, int last, int mask)
{
    GCALL6(0x06008F50, first, last, mask, mask, mask, 0);
}

void f06009092(int a, int b, int c, int d)
{
    FRAME(sp, 0);

    GCALL6(0x06008F50, a, b, c, d, LD32(sp), 0);
}

void f060090A8(int first, int last, int mask)
{
    GCALL6(0x06008F50, first, last, mask, mask, mask, 1);
}

void f060090C2(int first, int last, int red, int green)
{
    FRAME(sp, 0);

    GCALL6(0x06008F50, first, last, red, green, LD32(sp), 1);
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

void f06009288(int n, short x, short y, short z)
{
    FRAME(sp, 0);
    gaddr rec = 0x060BF4AA + (signed char)(n * 10);

    ST16(rec, x);
    ST16(rec + 2, y);
    ST16(rec + 4, z);
    ST16(rec + 6, LD16(sp + 2));
    ST16(rec + 8, LD16(sp + 6));
}

void f060092AA(int index)
{
    gaddr p = 0x060BF4AA + (signed char)(index * 10);

    GCALL3(0x060090A8, LDU16(p), LDU16(p + 2), 0x100);
    ST16(p, 0xFFF);
}

int f060092D4(int id)
{
    int i = 0;
    gaddr e = ENTS;
    gaddr p;

    if (LD32(0x060BF4A4) < 0)
        ST32(0x060BF4A4, GCALL4(0x060069B2, 0x06009134, 0x060CDC60, 0x400, 1));
    while (i < 16 && LD8(e + 11) != 0) {
        i++;
        e += 16;
        POLL();
    }
    if (i >= 16)
        return 0;
    p = GCALL2(0x06008ABA, id, 3);
    ST16(e + 8, LD16(p));
    ST8(e + 10, 0);
    ST8(e + 11, LD8(p + 3));
    ST8(e + 12, 0);
    ST8(e + 13, 1);
    ST32(e + 4, p + 4);
    ST32(e, p + 4);
    ST8(CNT, LD8(CNT) + 1);
    return i + 1;
}

int f06009380(int id, short flags)
{
    int n = GCALL1(0x060092D4, id);

    if (n != 0) {
        gaddr e = ENTS + (n - 1) * 16;

        ST16(e + 8, (LD16(e + 8) & 15) | flags);
    }
    return n;
}

int f060093B0(int n)
{
    gaddr ent = ENTS + (n - 1) * 16;
    gaddr p = LD32(ent);
    int count = 0;

    while ((unsigned int)LD32(ent + 4) > p && LD16(p) != 0) {
        POLL();
        count++;
        p += (LDU8(ent + 11) + 1) * 2;
    }
    if (LD16(p) == 0)
        count = -1;
    return count;
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

int f060095E0(int bank)
{
    FRAME(sp, 60);
    int k = 1;
    int result;

    for (;;) {
        gaddr rec;
        int type;

        result = LD32(LD32(0x060BD8E4 + bank * 4) + ((k & 0xFFFF) - 1) * 4);
        if (result == -1)
            break;
        rec = GCALL2(0x06008ABA, k, bank);
        type = LDU16(rec);
        result = type;
        if (type == 0) {
            ST32(sp - 48, rec + 4);
            result = LD16(rec + 2);
            ST16(sp - 44, result);
        } else if (type == 1) {
            ST32(sp - 40, rec + 4);
            ST16(sp - 36, LD16(rec + 2));
            result = GCALL1(0x0609E28C, sp - 48);
        } else if (type == 2) {
            result = GCALL4(0x0609E3FA, rec + 10, (LDU16(rec + 2) << 16) + LDU16(rec + 4), LD16(rec + 6), LD16(rec + 8));
        } else if (type == 3) {
            int n;

            GCALL2(0x0609E4E4, 0, rec + 4);
            n = LD16(rec + 2);
            GCALL0(0x0609E750);
            GCALL0(0x0609E708);
            result = GCALL1(0x0609E434, n);
        } else if (type == 4) {
            GCALL2(0x0609E586, 5, 0);
            result = GCALL1(0x0609E53C, LD16(rec + 2));
        } else if (type == 5) {
            GCALL2(0x0609E586, LD16(rec + 2), LD16(rec + 4));
            result = GCALL1(0x0609E4E4, 13);
        } else if (type == 6) {
            result = GCALL4(0x060096FA, sp - 56, sp - 60, LD16(rec + 2), LD16(rec + 4));
            ST32(LD32(sp - 60), LD32(LD32(sp - 60)) | 0x80000000);
        }
        k++;
        if ((k & 0xFFFF) >= 16)
            break;
        POLL();
    }
    return result;
}

void f060096FA(gaddr out, gaddr link, unsigned short kind, unsigned short index)
{
    gaddr entry = 0x25A00000 + LD32(0x25A00408);
    unsigned int head = LD32(entry);

    while (!(head & 0x80000000)) {
        POLL();
        if (((head & 0x70000000) >> 28) == kind && ((head & 0x0F000000) >> 24) == index) {
            ST32(out, (head & 0x000FFFFF) + 0x25A00000);
            ST32(link, entry + 4);
            break;
        }
        entry += 8;
        head = LD32(entry);
    }
}

void f06009762(int a, int b)
{
    FRAME(sp, 60);
    gaddr found = sp - 60;
    gaddr cfg = sp - 48;
    gaddr list = 0x060BD8E4 + (b << 2);
    int i = 1;

    GCALL1(0x06008A96, a);
    POLL();
    do {
        gaddr rec;

        if (LD32(LD32(list) + (i - 1) * 4) == -1)
            break;
        rec = GCALL2(0x06008ABA, i, b);
        switch (LDU16(rec)) {
        case 0:
            ST32(cfg, rec + 4);
            ST16(cfg + 4, LD16(rec + 2));
            break;
        case 1:
            ST32(cfg + 8, rec + 4);
            ST16(cfg + 12, LD16(rec + 2));
            GCALL1(0x0609E28C, cfg);
            break;
        case 2:
            GCALL4(0x0609E3FA, rec + 10, (LDU16(rec + 2) << 16) + LDU16(rec + 4), LD16(rec + 6), LD16(rec + 8));
            break;
        case 3: {
            int value;

            GCALL2(0x0609E4E4, 0, rec + 4);
            value = LD16(rec + 2);
            GCALL0(0x0609E750);
            GCALL0(0x0609E708);
            GCALL1(0x0609E434, value);
            break;
        }
        case 4:
            GCALL2(0x0609E586, 5, 0);
            GCALL1(0x0609E53C, LD16(rec + 2));
            break;
        case 5:
            GCALL2(0x0609E586, LD16(rec + 2), LD16(rec + 4));
            GCALL1(0x0609E4E4, 13);
            break;
        case 6:
            GCALL4(0x060096FA, found + 4, found, LD16(rec + 2), LD16(rec + 4));
            ST32(LD32(found), LD32(LD32(found)) | 0x80000000);
            break;
        }
    } while (AGAIN(++i < 16));
}

int f060097E0(void)
{
    int r;

    GCALL1(0x0600992C, 0);
    ST32(0x060B2E80, GCALL4(0x060069B2, 0x06009836, 0x060CE160, 0x400, 1));
    ST8(LD32(0x060FBF38) + 3, LD8(0x060BF4D4));
    GCALL0(0x06009BFE);
    r = GCALL1(0x0609E4E4, 13);
    ST32(0x060BF4D8, -1);
    return r;
}

void f0600992C(unsigned char mode)
{
    ST8(0x060B2E84, mode);
    ST8(0x060B2E85, 0);
    ST8(0x060BF4DC, 0);
    ST8(0x060BF4DD, 0);
}

void f06009940(void)
{
    FRAME(sp, 12);

    GCALL0(0x06009A6C);
    GCALL0(0x06009E48);
    if (LDU8(0x060B2E84) == 1 && LD8(0x060B2E85) == 0) {
        ST8(0x060B2E85, 1);
        ST32(sp - 12, 3);
        GCALL1(0x0609580A, sp - 12);
    }
}

void f0600994E(void)
{
    GCALL0(0x06009AC0);
    GCALL0(0x06009E7E);
    GJUMP0(0x06009CC8);
}

unsigned char f0600996A(int id)
{
    gaddr p;

    if (LD32(0x060BF4D8) == id)
        return 0;
    ST32(0x060BF4D8, id);
    p = GCALL1(0x060099AC, id);
    GCALL4(0x0609E78C, LD8(p), LD8(p + 1), LD8(p + 2), LD8(p + 3));
    return LD8(p + 2);
}

int f060099AC(int n)
{
    GCALL2(0x06008A6A, 10, 0);
    return GCALL2(0x06008ABA, 1, 10) + n * 4;
}

int f06009A08(signed char port)
{
    FRAME(sp, 12);
    int status;

    GCALL2(0x0609EEA8, sp - 8, port);
    status = LDU16(sp - 8);
    if (status == 0x100) {
        status = LD8(sp - 6);
        if (status == 0)
            status = GCALL1(0x0609E80C, port);
    }
    return status;
}

int f06009A3A(int n)
{
    signed char port = LD8(GCALL1(0x060099AC, n));

    POLL();
    return GJUMP1(0x06009A08, port);
}

void f06009A4E(void)
{
    unsigned char i = 0;

    do {
        GCALL1(0x06009A08, i);
    } while (AGAIN(++i < 8));
}

void f06009A6C(void)
{
    FRAME(sp, 32);
    int port = 0;

    do {
        int wait = 5000;

        do {
            wait--;
        } while (AGAIN(wait != 0));
        GCALL2(0x0609EEA8, sp - 32, port);
        if (LDU16(sp - 32) == 0x100 && LD8(sp - 30) == 0)
            GCALL1(0x0609E862, port);
    } while (AGAIN((unsigned char)++port < 7));
}

int f06009AC0(void)
{
    FRAME(sp, 32);
    int port = 0;
    int result;

    do {
        int wait = 5000;

        do {
            wait--;
        } while (AGAIN(wait != 0));
        result = GCALL2(0x0609EEA8, sp - 32, port);
        if (LDU16(sp - 32) == 0x300)
            result = GCALL1(0x0609E8B8, port);
    } while (AGAIN((unsigned char)++port < 7));
    return result;
}

void f06009BFE(void)
{
    if (LD8(0x060BF4D4)) {
        GCALL2(0x0609EDB4, 6, 6);
        GJUMP2(0x0609EE2A, 0, 0);
    } else {
        GCALL2(0x0609EDB4, 7, 7);
        GJUMP2(0x0609EE2A, -15, 15);
    }
}

void f06009C2C(void)
{
    FRAME(sp, 16);

    if (LDU8(0x060B2E84) == 1) {
        ST32(sp - 16, 0);
        GCALL1(0x0609580A, sp - 16);
        GCALL4(0x06095622, 0, 0, 5, 15);
        GCALL1(0x0600992C, 0);
    }
}

void f06009C60(void)
{
    FRAME(sp, 12);

    if (LDU8(0x060B2E84) == 1 && LD8(0x060B2E85) == 0) {
        ST8(0x060B2E85, 1);
        ST32(sp - 12, 3);
        GCALL1(0x0609580A, sp - 12);
    }
}

void f06009CC8(void)
{
    FRAME(sp, 24);

    if (LDU8(0x060B2E84) == 1 && LD8(0x060B2E85) != 0) {
        ST32(sp - 24, 3);
        ST32(sp - 16, 3);
        ST8(sp - 8, 255);
        GCALL1(0x0609576C, sp - 24);
        ST8(0x060B2E85, 0);
    }
}

void f06009D06(unsigned int n)
{
    if (LD8(0x060B2E84) == 16) {
        ST8(0x060BF4DC, n > 30 ? 30 : n);
        ST8(0x060BF4DD, LD8(0x060BF4DC) * 7);
    }
}

void f06009E38(int value, int ignored, int c, int d)
{
    GJUMP4(0x060A499C, LD32(0x060BF4E4), value, c, d);
}

void f06009E48(void)
{
    if (LD8(0x060B2E84) != 2 || LD8(0x060B2E85))
        return;
    ST8(0x060B2E85, 1);
    GCALL2(0x060A49F0, 0x060D3730, 0x2000);
    GJUMP2(0x060A4810, LD32(0x060BF4E4), 0);
}

void f06009E7E(void)
{
    if (LD8(0x060B2E84) != 2 || !LD8(0x060B2E85))
        return;
    ST8(0x060B2E85, 0);
    GJUMP2(0x060A4810, LD32(0x060BF4E4), 1);
}

void f06009ECE(unsigned int n)
{
    POLL();
    if ((unsigned char)LD8(0x060B2E84) == 2) {
        ST8(0x060BF4DC, n > 30 ? 30 : n);
        ST8(0x060BF4DD, LD8(0x060BF4DC) * 7);
    }
}

int f06009EDA(void)
{
    return GCALL1(0x060A4AF4, LD32(0x060BF4E4)) != 5 && GCALL1(0x060A4AF4, LD32(0x060BF4E4)) != -1;
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

int f0600A08C(void)
{
    int i = LD32(0x060BF4F4) + 1;

    ST32(0x060BF4F4, i);
    if (i > 55) {
        GCALL0(0x06009FA8);
        ST32(0x060BF4F4, 1);
        i = 1;
    }
    return LD32(0x060BF4F8 + i * 4);
}

void f0600A0B4(void)
{
    int prev = 1;
    int i = 21;
    int slot;
    int value;

    POLL();
    ST32(0x060BF5D8, 0x4D2);
    ST32(0x060BF5D4, 0x4D2);
    do {
        slot = MODS(i, 55);
        ST32(0x060BF4F8 + slot * 4, prev);
        value = prev;
        prev = LD32(0x060BF5D8) - prev;
        if (prev < 0)
            prev += 0x8000;
        ST32(0x060BF5D8, value);
        i += 21;
    } while (AGAIN(i <= 0x46E));
    GCALL0(0x06009FA8);
    GCALL0(0x06009FA8);
    GCALL0(0x06009FA8);
    ST32(0x060BF4F4, 55);
}

unsigned char f0600A0B8(void)
{
    return GCALL0(0x0600A08C);
}

int f0600A0E0(void)
{
    return GCALL0(0x0600A08C);
}

unsigned char f0600A0EC(unsigned int n)
{
    return ((GCALL0(0x0600A08C) & 255) * n) >> 8;
}

unsigned short f0600A10E(unsigned int n)
{
    return (unsigned int)GCALL0(0x0600A08C) * n >> 15;
}

int f0600A138(gaddr line, int x0, int y0, int x1)
{
    FRAME(sp, 0);
    int y1 = LD32(sp);
    int dx, dy, major;

    if (x1 >= x0) {
        ST8(line + 8, 1);
        ST16(line, x1 - x0);
    } else {
        ST8(line + 8, -1);
        ST16(line, x0 - x1);
    }
    if (y1 >= y0) {
        ST8(line + 9, 1);
        ST16(line + 2, y1 - y0);
    } else {
        ST8(line + 9, -1);
        ST16(line + 2, y0 - y1);
    }
    dx = LD16(line);
    dy = LD16(line + 2);
    major = dx >= dy ? dx : dy;
    ST16(line + 4, major >> 1);
    return major;
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

int f0600A1FC(gaddr rec, unsigned short obj, unsigned int count)
{
    unsigned int i;
    gaddr o;

    for (i = 0; i < count; i++) {
        if (i != 0)
            GCALL1(0x0600A186, rec);
        else
            GCALL1(0x0600A1F4, rec);
        if (i + 1 < count)
            POLL();
    }
    o = OBJ(obj);
    ST16(o + 16, LD16(o + 16) + LD8(rec + 6));
    ST16(o + 18, LD16(o + 18) + LD8(rec + 7));
    return i;
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

void f0600A3FA(unsigned short i, gaddr box, short dy, short dx)
{
    gaddr o = OBJ(i);

    GCALL3(0x0600A3E0, o, box, dx);
    ST16(o + 22, LD16(o + 18) - dy);
    ST16(o + 26, dy + LD16(o + 18) + LD8(box + 1) - LD8(box + 3));
}

void f0600A44A(unsigned short i, gaddr box, short dy, short dx)
{
    gaddr o = OBJ(i);

    GCALL3(0x0600A3E0, o, box, dx);
    ST16(o + 22, LD16(o + 18) - dy - dy);
    ST16(o + 26, LD16(o + 18) + LD8(box + 1) + LD8(box + 1) - LD8(box + 3));
}

void f0600A49C(gaddr dst, int value, int size)
{
    int i;

    if (size <= 0)
        return;
    i = 0;
    do {
        i += 2;
        ST16(dst, value);
        dst += 2;
    } while (AGAIN(i < size));
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

int f0600A4EC(int n)
{
    return (unsigned char)LD8(LD32(0x060FA8F0) + 2) == n;
}

int f0600A570(int mode)
{
    int bits = mode;

    switch (mode) {
    case 1:
        bits = (LD16(0x060FA9D8) & 0x8000) | (HELPER(LDU16(0x060FA9CA) >> 8) & 1);
        break;
    case 2:
    case 4:
        bits = (LD16(0x060FA9D0) & 0x8000) | (LD16(0x060FA9C8) & 1);
        break;
    case 8:
        bits = (LD16(0x060FA9D2) & 0x8000) | (LDU16(0x060FA9C8) >> 8 & 1);
        break;
    case 16:
        bits = (LD16(0x060FA9D4) & 0x8000) | (LD16(0x060FA9CA) & 1);
        break;
    case 32:
        bits = (LD16(0x060FA9D6) & 0x8000) | (LDU16(0x060FA9CA) >> 4 & 1);
        break;
    }
    switch (bits & 0xFFFF) {
    case 0:
        return 0x4000;
    case 1:
        return 0x1000;
    case 0x8000:
        return 0x2000;
    case 0x8001:
        return 0x800;
    }
    return bits;
}

int f0600A63E(int mode)
{
    unsigned int a = LDU16(0x060FA9DE);
    unsigned int b = LDU16(0x060FA9DA);
    unsigned int c = LDU16(0x060FA9DC);
    unsigned int offset = c;
    int shape = 0x060FA9C8;

    switch (mode) {
    case 1:
        offset = (a << 6 & 0x1C0) | (LDU16(0x060FA9F0) & 63);
        shape = HELPER(b >> 8) & 3;
        break;
    case 2:
        offset = (a << 2 & 0x1C0) | (LDU16(0x060FAA00) & 63);
        shape = HELPER(b >> 12) & 3;
        break;
    case 4:
        offset = (c << 6 & 0x1C0) | (LDU16(0x060FA9E0) & 63);
        shape = b & 3;
        break;
    case 8:
        offset = (c << 2 & 0x1C0) | (LDU16(0x060FA9E4) & 63);
        shape = b >> 2 & 3;
        break;
    case 16:
        offset = (c >> 2 & 0x1C0) | (LDU16(0x060FA9E8) & 63);
        shape = b >> 4 & 3;
        break;
    case 32:
        offset = (c >> 6 & 0x1C0) | (LDU16(0x060FA9EC) & 63);
        shape = b >> 6 & 3;
        break;
    }
    if ((unsigned short)shape == 1)
        offset &= 0x1FE;
    else if ((unsigned short)shape == 3)
        offset &= 0x1FC;
    return (0x000FFFFF & (offset * GCALL1(0x0600A570, mode))) + 0x25E00000;
}

int f0600A76E(int mode, unsigned int value)
{
    unsigned int a = LDU16(0x060FA9C8);
    unsigned int b = LDU16(0x060FA9CA);
    unsigned int bits = mode;
    unsigned int sel = a;
    unsigned int out;

    switch (mode) {
    case 1:
        bits = (b >> 4 & 16) | (HELPER(b >> 12) & 7);
        sel = LDU16(0x060FA9D8) & 0xC000;
        break;
    case 2:
    case 4:
        bits = (a << 4 & 16) | (a >> 4 & 7);
        sel = LDU16(0x060FA9D0) & 0xC000;
        break;
    case 8:
        bits = (a >> 4 & 16) | (HELPER(a >> 12) & 3);
        sel = LDU16(0x060FA9D2) & 0xC000;
        break;
    case 16:
        bits = (b << 4 & 16) | (b >> 1 & 1);
        sel = LDU16(0x060FA9D4) & 0xC000;
        break;
    case 32:
        bits = (b & 16) | (b >> 5 & 1);
        sel = LDU16(0x060FA9D6) & 0xC000;
        break;
    }
    if (!(sel & 0x8000))
        return value;
    out = bits;
    switch ((bits & 16) | sel) {
    case 0x8000:
        out = (value & 0x3FF) | (value >> 12 & 0xC00);
        break;
    case 0x8010:
        out = (value >> 2 & 0x3FF) | (value >> 12 & 0xC00);
        break;
    case 0xC000:
        out = value & 0xFFF;
        break;
    case 0xC010:
        out = value >> 2 & 0xFFF;
        break;
    }
    if ((bits & 15) == 0)
        out |= value >> 4 & 0xF000;
    else
        out |= value >> 8 & 0x7000;
    return out;
}

int f0600A8F4(int mode, int value)
{
    gaddr dst = GCALL1(0x0600A63E, mode);
    unsigned int a = LDU16(0x060FA9C8);
    unsigned int b = LDU16(0x060FA9CA);
    unsigned int c = LDU16(0x060FA9DA);
    unsigned int bit = a << 4 & 16;
    unsigned int sel = b;
    unsigned int field = 0x060FA9C8;
    unsigned int count;
    int color;

    switch (mode) {
    case 1:
        bit = b >> 4 & 16;
        sel = LDU16(0x060FA9D8) & 0x8000;
        field = HELPER(c >> 8) & 3;
        break;
    case 2:
        sel = LDU16(0x060FA9D0) & 0x8000;
        field = HELPER(c >> 12) & 3;
        break;
    case 4:
        sel = LDU16(0x060FA9D0) & 0x8000;
        field = c & 3;
        break;
    case 8:
        bit = a >> 4 & 16;
        sel = LDU16(0x060FA9D2) & 0x8000;
        field = c >> 2 & 3;
        break;
    case 16:
        bit = b << 4 & 16;
        sel = LDU16(0x060FA9D4) & 0x8000;
        field = c >> 4 & 3;
        break;
    case 32:
        bit = b & 16;
        sel = LDU16(0x060FA9D6) & 0x8000;
        field = c >> 6 & 3;
        break;
    }
    count = ((field & 0xFFFF) + 1) << (bit ? 10 : 12);
    color = GCALL2(0x0600A76E, mode, value);
    if (sel & 0xFFFF) {
        do {
            ST16(dst, color);
            count--;
            dst += 2;
        } while (AGAIN(count != 0));
    } else {
        do {
            count--;
            ST16(dst, (unsigned int)color >> 16);
            dst += 2;
            ST16(dst, color);
            dst += 2;
        } while (AGAIN(count != 0));
    }
    return color;
}

int f0600AA2A(int which)
{
    int hi = LDU16(0x060FA9CA);
    int lo = LDU16(0x060FA9C8);

    if (which == 1)
        return HELPER(hi >> 8) & 1;
    if (which == 2 || which == 4)
        return lo & 1;
    if (which == 8)
        return (lo >> 8) & 1;
    if (which == 16)
        return hi & 1;
    if (which == 32)
        return (hi >> 4) & 1;
    return which;
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

int f0600AAE4(int which)
{
    int hi = LDU16(0x060FA9CA);
    int lo = LDU16(0x060FA9C8);

    if (which == 1)
        return HELPER(hi >> 12) & 7;
    if (which == 2 || which == 4)
        return (lo >> 4) & 7;
    if (which == 8)
        return HELPER(lo >> 12) & 3;
    if (which == 16)
        return (hi >> 1) & 1;
    if (which == 32)
        return (hi >> 5) & 1;
    return which;
}

int f0600AB46(int which)
{
    int v = LDU16(0x060FA9DA);

    if (which == 1)
        return HELPER(v >> 8) & 3;
    if (which == 2)
        return HELPER(v >> 12) & 3;
    if (which == 4)
        return v & 3;
    if (which == 8)
        return (v >> 2) & 3;
    if (which == 16)
        return (v >> 4) & 3;
    if (which == 32)
        return (v >> 6) & 3;
    return which;
}

int f0600ABA4(int layer, unsigned short x, unsigned short y)
{
    int base = GCALL1(0x0600A63E, layer);
    int step = GCALL1(0x0600A570, layer);
    unsigned short page = ((y >> 6) << 1) + (x >> 6);
    int unit;

    base += step * page;
    unit = (GCALL1(0x0600AA8A, layer) & 0xFFFF) ? 2 : 4;
    return base + (((y & 63) << 6) + (x & 63)) * unit;
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

void f0600B67E(unsigned int w, unsigned int h)
{
    unsigned int x = (320 - w) >> 1;
    unsigned int y = (224 - h) >> 1;

    ST16(0x060B2F6E, (w >> 3 << 8) | h);
    ST16(0x060B2F70, x);
    ST16(0x060B2F72, y);
    ST16(0x060B2F74, w + x - 1);
    ST16(0x060B2F76, y);
    ST16(0x060B2F78, w + x - 1);
    ST16(0x060B2F7A, h + y - 1);
    ST16(0x060B2F7C, x);
    ST16(0x060B2F7E, h + y - 1);
    GJUMP3(0x060949E0, 0x25C00000, 0x060B2F04, 160);
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

int f0600BC34(void)
{
    int left = GCALL1(0x0600A0EC, LDU8(0x060C063C)) + 1;
    int i = 0;

    while (i < LDU8(0x060C063D)) {
        POLL();
        if (LD8(0x060C0654 + i) && --left == 0)
            break;
        i++;
    }
    return i;
}

void f0600BCC8(void)
{
    int i;

    for (i = 0; i < (unsigned char)LD8(BOMBER_COUNT); i++) {
        ST32(0x060C0524 + i * 4, i);
        POLL();
    }
    if (!(LD8(0x060C0682) & 128))
        return;
    for (i = 0; i < (unsigned char)LD8(BOMBER_COUNT); i++) {
        if (LD8(0x060C0654 + i)) {
            int j = GCALL0(0x0600BC34);
            int t = LD32(0x060C0524 + i * 4);

            ST32(0x060C0524 + i * 4, LD32(0x060C0524 + j * 4));
            ST32(0x060C0524 + j * 4, t);
        }
        POLL();
    }
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

void f0600BD74(void)
{
    GCALL1(0x0600C9AA, GCALL0(0x0600BD3C));
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

/* Copies the 16 bytes of tile `tile` (as two pairs of words, 0x100 apart) to dst. */
static int copy_tile(unsigned short tile, gaddr dst)
{
    gaddr src = LD32(0x060D7E98) + tile * 16;

    ST32(dst, LD32(src));
    ST32(dst + 4, LD32(src + 4));
    ST32(dst + 0x100, LD32(src + 8));
    ST32(dst + 0x104, LD32(src + 12));
    return 0x104;
}

void f0600C796(unsigned short tile, short col, short row)
{
    gaddr dst = GCALL2(0x0600C962, col, row);

    dst += LD32(0x060D7EA0);
    POLL();
    copy_tile(tile, dst);
}

void f0600C7BE(unsigned short tile, short cell)
{
    gaddr dst = GCALL1(0x0600CA20, cell);

    dst += LD32(0x060D7EA0);
    POLL();
    copy_tile(tile, dst);
}

void f0600C876(void)
{
    int x, y;
    gaddr tiles;
    int saved;

    if (!LD16(0x060D7E6C))
        return;
    GCALL0(0x0600C434);
    POLL();
    y = 0;
    do {
        tiles = LD32(0x060D7E94) + y * 128;
        x = 0;
        do {
            if (LDU16(FLAGS_AT(y * 64 + x)) & 16) {
                saved = LD32(0x060D7EA0);
                ST32(0x060D7EA0, LD32(0x060DF98C));
                GCALL3(0x0600C796, 1, x, y);
                ST32(0x060D7EA0, saved);
            }
            GCALL3(0x0600C796, LD16(tiles + x * 2), x, y);
        } while (AGAIN(++x < 64));
    } while (AGAIN(++y < 64));
}

void f0600C8AC(void)
{
    gaddr src;
    int row, col;

    if (LD16(0x060D7E6E) == 0)
        return;
    GCALL0(0x0600C44C);
    POLL();
    row = 0;
    do {
        src = LD32(0x060D7E94) + row * 128;
        col = 0;
        do {
            GCALL3(0x0600C796, LD16(src), col, row);
            src += 2;
            col++;
        } while (AGAIN(col < 64));
        row++;
    } while (AGAIN(row < 64));
}

void f0600C8C6(void)
{
    int x, y;
    gaddr row;

    if (!LD16(0x060D7E70))
        return;
    GCALL0(0x0600C4B0);
    POLL();
    y = 0;
    do {
        row = LD32(0x060D7E94) + y * 128;
        x = 0;
        do {
            GCALL3(0x0600C796, LD16(row + x * 2), x, y);
        } while (AGAIN(++x < 64));
    } while (AGAIN(++y < 64));
}

void f0600C8E0(void)
{
    int x, y;
    gaddr row;

    if (!LD16(0x060D7E72))
        return;
    GCALL0(0x0600C4C8);
    POLL();
    y = 0;
    do {
        row = LD32(0x060D7E94) + y * 128;
        x = 0;
        do {
            if (!(LDU16(0x060EC8B0 + y * 128 + x * 2) & 16))
                GCALL3(0x0600C796, LD16(row + x * 2), x, y);
        } while (AGAIN(++x < 64));
    } while (AGAIN(++y < 64));
}

void f0600C8FA(void)
{
    GCALL0(0x0600C876);
    GCALL0(0x0600C8AC);
    GCALL0(0x0600C8C6);
    GJUMP0(0x0600C8E0);
}

void f0600C90C(unsigned short i)
{
    gaddr o = OBJ(i);
    int y = LD16(o + 18) + LDU16(0x060D82BC);

    ST16(0x060D7E88, LD16(o + 16) + LD16(0x060D82BA));
    ST16(0x060D7E8A, y - GCALL0(0x0600D0D0));
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

int f0600CA20(int cell)
{
    unsigned int x, y;

    GCALL1(0x0600C9AA, cell);
    y = LDU16(0x060D7EB6);
    x = LDU16(0x060D7EB4);
    POLL();
    return ((y >> 5) << 15) + ((x >> 5) << 14) + ((y & 31) << 9) + ((x & 31) << 3);
}

void f0600CA32(int x, int y)
{
    int top;

    ST16(0x060D7E88, x * 16 - LD16(0x060D82BA));
    top = y * 16 - LD16(0x060D82BC);
    ST16(0x060D7E8A, top + GCALL0(0x0600D0D0));
}

unsigned short f0600CA6A(int i)
{
    GCALL1(0x0600C90C, i);
    return GJUMP2(0x0600CAE4, LD16(0x060D7E88), LD16(0x060D7E8A));
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

unsigned short f0600CA84(void)
{
    int y = LD16(LD32(CURRENT) + 28);
    int x;

    ST16(0x060D7E8A, y);
    x = LD16(LD32(CURRENT) + 24);
    ST16(0x060D7E88, x);
    return GCALL2(0x0600CAE4, x, y);
}

void f0600CAA4(void)
{
    gaddr obj;
    int y;

    ST16(LD32(MOVER_PTR) + 16, LD16(LD32(CURRENT) + 24) - LD16(0x060D82BA));
    obj = LD32(MOVER_PTR);
    y = LDU16(LD32(CURRENT) + 28) - LDU16(0x060D82BC);
    ST16(obj + 18, y + GCALL0(0x0600D0D0));
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

void f0600CB78(int x, int y)
{
    unsigned short pos = GCALL1(0x0600C9C0, GCALL2(0x0600CAE4, x, y));
    unsigned short cell;

    cell = GCALL1(0x0600C9C0, pos - 64);
    if (!(LDU16(0x060EC8B0 + cell * 2) & LDU16(0x060D7E92)))
        ST16(0x060D7E8E, LD16(0x060D7E8E) | 0x1000);
    cell = GCALL1(0x0600C9C0, pos + 64);
    if (!(LDU16(0x060EC8B0 + cell * 2) & LDU16(0x060D7E92)))
        ST16(0x060D7E8E, LD16(0x060D7E8E) | 0x2000);
    if (!(LDU16(0x060EC8B0 + (pos - 1) * 2) & LDU16(0x060D7E92)))
        ST16(0x060D7E8E, LD16(0x060D7E8E) | 0x4000);
    if (!(LDU16(0x060EC8B0 + (pos + 1) * 2) & LDU16(0x060D7E92)))
        ST16(0x060D7E8E, LD16(0x060D7E8E) | 0x8000);
}

void f0600CC18(int i)
{
    int fx, fy;
    unsigned short flags;

    ST16(0x060D7E90, 0);
    ST16(0x060D7E8E, 0);
    GCALL1(0x0600C90C, i);
    fx = LD16(0x060D7E88) & 15;
    if (fx) {
        ST16(0x060D7E90, LD16(0x060D7E90) | 0x3000);
        ST16(0x060D7E8E, LD16(0x060D7E8E) | (fx < 8 ? 0x4000 : 0x8000));
    }
    fy = LD16(0x060D7E8A) & 15;
    if (fy) {
        ST16(0x060D7E90, LD16(0x060D7E90) | 0xC000);
        ST16(0x060D7E8E, LD16(0x060D7E8E) | (fy < 8 ? 0x1000 : 0x2000));
    }
    flags = LD16(0x060D7E8E);
    GCALL2(0x0600CB78, LD16(0x060D7E88), LD16(0x060D7E8A));
    ST16(0x060D7E8E, (~LDU16(0x060D7E90) & LDU16(0x060D7E8E)) | flags);
}

int f0600CCD4(int i)
{
    int flags = 0;
    int x, y;

    ST16(0x060D7E8E, 0);
    GCALL1(0x0600C90C, i);
    x = LD16(0x060D7E88);
    if (x & 15)
        flags = x & 8 ? 0x8000 : 0x4000;
    y = LD16(0x060D7E8A);
    if (y & 15)
        flags |= y & 8 ? 0x2000 : 0x1000;
    if (flags)
        GCALL2(0x0600CB78, (x + 8) & 0xFFF0, (y + 8) & 0xFFF0);
    else
        GCALL2(0x0600CB78, x, y);
    return flags;
}

unsigned short f0600CD74(int n)
{
    unsigned short flags = LD16(0x060D7E8E) & LD16(0x060B35BC + n * 2);

    ST16(0x060D7E8E, flags);
    if (flags) {
        int y = (LD16(0x060B35B2 + n * 2) + LD16(0x060D7E8A) + 8) & 0xFFF0;

        GCALL2(0x0600CB78, (LD16(0x060B35A8 + n * 2) + LD16(0x060D7E88) + 8) & 0xFFF0, y);
    }
    return flags;
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

int f0600CE6C(void)
{
    gaddr p = 0x060C02D8;
    int i = 0;
    int mode;

    ST16(0x060D82BC, 0);
    ST16(0x060D82BA, 0);
    ST8(0x060D82B8, 0);
    ST16(0x060D82C6, 60);
    ST16(0x060D82C8, 0);
    do {
        ST32(p + 4, 0);
        ST32(p, 0);
        ST32(p + 12, 0x100);
        ST32(p + 8, 0x100);
        ST16(p + 18, 0);
        ST16(p + 16, 0);
        p += 20;
        i++;
    } while (AGAIN(i < 4));
    ST16(0x060D82CA, 0);
    mode = LDU8(0x060C029C);
    if (mode != 8 && mode != 17)
        ST32(0x060C0350, GCALL4(0x060069B2, 0x0600D6B2, 0x060D7EB8, 0x400, 1));
    POLL();
    ST32(0x060C0328, 0);
    ST32(0x060C032C, 0);
    ST32(0x060C0330, 0x00010000);
    ST32(0x060C0334, 0x00010000);
    ST32(0x060C0338, 0);
    ST32(0x060C033C, 0);
    ST32(0x060C0340, 0x00010000);
    ST32(0x060C0344, 0x00010000);
    ST16(0x060C0348, 0);
    ST16(0x060C034A, 0);
    ST16(0x060C034C, 0);
    ST16(0x060C034E, 0);
    ST32(0x26006160, 0x0600CE24);
    return GJUMP0(0x0609DA34);
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

int f0600D066(int i)
{
    GCALL1(0x0600C90C, i);
    return !((LD16(0x060D7E88) + LD16(0x060D7E8A)) & 15);
}

int f0600D08A(void)
{
    return GJUMP1(0x0600D066, LDU16(OBJIDX));
}

int f0600D0D0(void)
{
    return (unsigned char)LD8(0x060C029C) == 17 ? 8 : 24;
}

void f0600D0E4(unsigned short i, unsigned short x, unsigned short y)
{
    gaddr o = OBJ(i);
    int top;

    ST16(o + 16, (x << 4) - LD16(0x060D82BA));
    top = (y << 4) - LDU16(0x060D82BC);
    ST16(o + 18, GCALL0(0x0600D0D0) + top);
    GCALL2(0x0600C950, x, y);
}

void f0600D148(short index, short cell)
{
    unsigned short x = GCALL1(0x0600C9AA, cell);
    unsigned short y = LDU16(0x060D7EB6);
    gaddr obj;
    int py;

    POLL();
    obj = OBJ(index);
    ST16(obj + 16, (x << 4) - LD16(0x060D82BA));
    py = (y << 4) - LDU16(0x060D82BC);
    ST16(obj + 18, GCALL0(0x0600D0D0) + py);
    GCALL2(0x0600C950, x, y);
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

int f0600D1A6(void)
{
    gaddr o = OBJ(LD16(OBJIDX));
    int moved = 0;
    int x0, y0, x1, y1;

    GCALL2(0x0600CA32, LDU16(0x060D7E7C), LDU16(0x060D7E7E) - 1);
    x0 = LD16(0x060D7E88);
    y0 = LD16(0x060D7E8A) - 8;
    GCALL2(0x0600CA32, LDU16(0x060D7E80) - 1, LDU16(0x060D7E82) + 1);
    x1 = LD16(0x060D7E88);
    y1 = LD16(0x060D7E8A) - 8;
    if (LD16(o + 16) <= x0) {
        moved = 1;
        ST16(o + 16, LD16(o + 16) + (x1 - x0));
    }
    if (LD16(o + 16) >= x1) {
        moved = 1;
        ST16(o + 16, LD16(o + 16) - (x1 - x0));
    }
    if (LD16(o + 18) <= y0) {
        moved = 1;
        ST16(o + 18, LD16(o + 18) + (y1 - y0));
    }
    if (LD16(o + 18) >= y1) {
        moved = 1;
        ST16(o + 18, LD16(o + 18) - (y1 - y0));
    }
    return moved;
}

void f0600D290(void)
{
    int cell = GCALL1(0x0600CA6A, LDU16(OBJIDX));

    GJUMP2(0x06069546, LDU16(OBJIDX), (LDU16(FLAGS_AT(cell)) & 0x1000) != 0);
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

void f0600D38A(int a, short amount)
{
    GCALL2(0x0600D2BE, a, amount);
    ST16(0x060C1AAE, LD16(0x060C1AAE) - amount);
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

void f0600D4BE(int a, int b, short c)
{
    GCALL2(0x0600D2BE, a, b);
    GJUMP2(0x0600D3D4, a, c);
}

void f0600D4DA(int a, int b, short c)
{
    GCALL2(0x0600D38A, a, b);
    POLL();
    GCALL2(0x0600D3D4, a, c);
    ST16(0x060C1AB0, LD16(0x060C1AB0) - c);
}

int f0600D600(int step, int x, int y)
{
    int cx = LD16(0x060D82BA);
    int cy;

    if ((unsigned short)x >= (unsigned short)cx) {
        if ((unsigned short)x == (unsigned short)cx) {
            x = 0;
        } else {
            x -= cx;
            if ((unsigned short)x > (unsigned short)step)
                x = step;
        }
    } else {
        x = cx - x;
        if ((unsigned short)x > (unsigned short)step)
            x = step;
        x = -x;
    }
    cy = LD16(0x060D82BC);
    if ((unsigned short)y >= (unsigned short)cy) {
        if ((unsigned short)y == (unsigned short)cy) {
            y = 0;
        } else {
            y -= cy;
            if ((unsigned short)y > (unsigned short)step)
                y = step;
        }
    } else {
        y = cy - y;
        if ((unsigned short)y > (unsigned short)step)
            y = step;
        y = -y;
    }
    if (!((unsigned short)x | (unsigned short)y))
        return 0;
    GCALL2(0x0600D5EA, x, y);
    ST16(0x060D82CA, 1);
    return 1;
}

void f0600D8F8(void)
{
    ST16(0x060D82CA, 128);
}

void f0600D900(void)
{
    ST16(0x060D82CA, 0);
}

int f0600E096(void)
{
    int v;

    ST32(CURRENT, REC(0));
    v = LDU16(REC(0) + 20);
    if (v != 0x44E)
        return v;
    v = LDU16(LD32(0x060D7E64) + 60);
    if (v != 0xFF00)
        return v;
    v = (LDU16(REC(0) + 24) + 4) & 15;
    if (v >= 8)
        return v;
    v = (LDU16(REC(0) + 28) + 4) & 15;
    if (v >= 8)
        return v;
    v = LDU16(0x060D7E68);
    if (v & 64)
        return v;
    GCALL1(0x0600D16A, LDU16(REC(0) + 22));
    v = LD16(0x060D7E68) | 66;
    ST16(0x060D7E68, v);
    return v;
}

int f0600E140(void)
{
    gaddr obj;

    GCALL2(0x06022F1C, 2, 0x0600E1BC);
    ST16(LD32(TASK_OBJ) + 44, 0);
    GCALL2(0x0606AAC8, LD32(TASK_OBJ), 5);
    obj = LD32(TASK_OBJ);
    ST16(obj + 42, LD16(obj + 42) | 0x100);
    obj = LD32(TASK_OBJ);
    ST16(obj + 24, 0x120);
    ST16(obj + 20, 0x120);
    obj = LD32(TASK_OBJ);
    ST16(obj + 26, 212);
    ST16(obj + 22, 212);
    ST16(LD32(TASK_OBJ) + 46, 0x31F);
    GCALL2(0x06069462, (short)TGET(h8), 0x1EA);
    TSET(h12, 0);
    TSET(h10, 0);
    TSET(h4, 60);
    return 60;
}

int f0600E1BC(void)
{
    gaddr task = LD32(TASK_PTR);
    gaddr obj;
    int limit;

    ST16(task + 12, LD16(0x060B3604 + LDU16(0x060C035E) * 2));
    if (LDU16(LD32(TASK_PTR) + 10) <= 8) {
        obj = LD32(TASK_OBJ);
        ST16(obj + 26, LD16(obj + 26) + 1);
    }
    if (LDU16(LD32(TASK_PTR) + 10) <= 9) {
        obj = LD32(TASK_OBJ);
        ST16(obj + 24, LD16(obj + 24) + 1);
        obj = LD32(TASK_OBJ);
        ST16(obj + 22, LD16(obj + 22) - 1);
    }
    task = LD32(TASK_PTR);
    limit = LD16(task + 12);
    if ((unsigned int)LD16(task + 10) < (unsigned int)limit) {
        obj = LD32(TASK_OBJ);
        ST16(obj + 20, LD16(obj + 20) - 1);
        task = LD32(TASK_PTR);
        limit = LD16(task + 10) + 1;
        ST16(task + 10, limit);
    }
    return limit;
}

int f0600E318(void)
{
    gaddr obj = LD32(TASK_OBJ);
    int y;

    if (LD16(obj + 16) >= 160) {
        if (LD16(obj + 16) >= 0x120) {
            TSET(fn, 0x0600E38C);
            TSET(h12, 0);
            return 0;
        }
        y = LD16(obj + 16) + 2;
    } else {
        y = LD16(obj + 16) + 4;
    }
    ST16(obj + 16, y);
    return y;
}

int f0600E38C(void)
{
    gaddr task = LD32(TASK_PTR);
    gaddr obj;

    if (LD16(0x060C035E) == LD16(task + 10))
        return LD16(task + 10);
    obj = LD32(TASK_OBJ);
    ST16(obj + 16, LD16(obj + 16) - 1);
    if (LDU16(task + 12) >= 16) {
        ST16(task + 10, LD16(task + 10) + 1);
        ST16(task + 12, 0);
        return 0;
    }
    ST16(task + 12, LD16(task + 12) + 1);
    return task;
}

void f0600E3D6(gaddr dst, int n)
{
    ST16(dst + 16, LD16(0x060B3632 + n * 2));
    ST16(dst + 18, LD16(0x060B3632 + n * 2 + 2));
    ST16(dst + 44, 1);
}

void f0600E4A4(short first, short second, short x, short y)
{
    ST16(OBJIDX, first);
    GCALL1(0x0600A2B0, x);
    GCALL1(0x0600A32A, y);
    ST16(OBJIDX, second);
    GCALL1(0x0600A2B0, x);
    GJUMP1(0x0600A32A, y);
}

void f0600E5CC(unsigned short a, unsigned short b)
{
    if (a)
        GCALL1(0x060692DC, a);
    if (b)
        GJUMP1(0x060692DC, b);
}

int f0600E94C(void)
{
    gaddr t = LD32(TASK_PTR);
    int dir = LD16(t + 12) ? 4 : -4;
    gaddr obj;
    int n = LD16(t + 16);

    if (n) {
        ST16(t + 16, n - 1);
        return n - 1;
    }
    ST16(t + 14, LD16(t + 14) + 1);
    obj = LD32(0x060D7E64);
    ST16(obj + 16, LD16(obj + 16) + dir);
    if ((unsigned short)LD16(t + 14) < (unsigned short)LD16(t + 10))
        return LD16(t + 10);
    if (LDU16(t + 12) > 1)
        return GJUMP0(0x06022F14);
    ST16(t + 12, LD16(t + 12) + 1);
    ST16(t + 14, 0);
    ST16(t + 16, 210);
    return 210;
}

int f0600E960(void)
{
    gaddr t = LD32(TASK_PTR);
    int dir = LD16(t + 12) ? -4 : 4;
    gaddr obj;
    int n = LD16(t + 16);

    if (n) {
        ST16(t + 16, n - 1);
        return n - 1;
    }
    ST16(t + 14, LD16(t + 14) + 1);
    obj = LD32(0x060D7E64);
    ST16(obj + 16, LD16(obj + 16) + dir);
    if ((unsigned short)LD16(t + 14) < (unsigned short)LD16(t + 10))
        return LD16(t + 10);
    if (LDU16(t + 12) > 1)
        return GJUMP0(0x06022F14);
    ST16(t + 12, LD16(t + 12) + 1);
    ST16(t + 14, 0);
    ST16(t + 16, 210);
    return 210;
}

int f0600E974(void)
{
    if (LD16(LD32(TASK_PTR) + 18)) {
        gaddr obj = LD32(0x060D7E64);
        int v = (LD32(0x26006034) & 12) ? 0x100 : 0;

        ST16(obj + 70, v);
        ST16(obj + 68, v);
        ST32(0x060C09B0 + ((unsigned char)LD8(0x060C029D) - 1) * 4, LD32(0x060C0698));
    }
    return GJUMP0(0x0600E94C);
}

int f0600E9B0(void)
{
    ST16(LD32(TASK_PTR) + 4, 240);
    ST32(LD32(TASK_PTR), 0x06022F14);
    return 240;
}

int f0600F104(void)
{
    int y;

    if ((unsigned char)LD8(0x060C02A1) != 2) {
        GCALL2(0x060695B0, LD32(0x060D7E64), 1);
        GCALL1(0x0600A28C, GCALL1(0x06069562, LD32(0x060D7E64)) ? 40 : 24);
    } else {
        GCALL1(0x0600A28C, GCALL1(0x06069562, LD32(0x060D7E64)) ? 80 : 48);
    }
    if ((unsigned char)LD8(0x060C02A1) == 1)
        GCALL1(0x0600A306, GCALL1(0x06069562, LD32(0x060D7E64)) ? -40 : -24);
    y = LD16(LD32(0x060D7E64) + 16);
    if (y > 0x170) {
        y = -48;
        ST16(LD32(0x060D7E64) + 16, -48);
    }
    return y;
}

int f0600F1C6(void)
{
    unsigned char mode;

    if (LD8(0x060C02A1) == 1)
        GCALL1(0x0600A32A, 240);
    mode = LD8(0x060C02A1);
    if (mode != 2)
        return mode;
    return GJUMP1(0x0600A2B0, 250);
}

int f0600F272(void)
{
    int y;

    if (!LD8(0x060C02A1) && LD32(0x060FAA20) >= 0x00400000)
        return 0x060FAA20;
    y = LD16(LD32(0x060D7E64) + 18);
    if (y > 104)
        return GJUMP1(0x0600A32A, -4);
    return y;
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

int f0600FE8A(void)
{
    unsigned int key = GCALL0(0x0600FF94);
    unsigned int count = LDU8(0x060C029D) + 1;
    unsigned int a = LD32(0x060C0690);
    unsigned int b = GCALL0(0x060279E2);
    gaddr entry = 0x060C0910;
    int i = 0;
    int last = 8;

    while (i < 10) {
        int older;

        POLL();
        if (LDU16(entry + 14) != key)
            older = LDU16(entry + 14) < key;
        else if (LDU16(entry + 12) != count)
            older = LDU16(entry + 12) < count;
        else if ((unsigned int)LD32(entry) != a)
            older = (unsigned int)LD32(entry) < a;
        else if ((unsigned int)LD32(entry + 4) != b)
            older = (unsigned int)LD32(entry + 4) < b;
        else
            older = (unsigned int)LD32(entry + 8) < (unsigned int)LD32(0x060C06C0);
        if (older) {
            if (last >= i) {
                gaddr src = 0x060C0990;

                do {
                    ST32(src + 16, LD32(src));
                    ST32(src + 20, LD32(src + 4));
                    ST32(src + 24, LD32(src + 8));
                    ST16(src + 28, LD16(src + 12));
                    ST16(src + 30, LD16(src + 14));
                    last--;
                    src -= 16;
                } while (AGAIN(last >= i));
            }
            ST32(entry, a);
            ST32(entry + 4, b);
            ST32(entry + 8, LD32(0x060C06C0));
            ST16(entry + 12, count);
            ST16(entry + 14, key);
            break;
        }
        i++;
        entry += 16;
    }
    return i;
}

unsigned char f0600FF94(void)
{
    int a = 0;
    int b = 0;
    int limit;
    unsigned char v;

    while ((unsigned int)LD32(0x060C0690) >= (unsigned int)LD32(0x060B3768 + a * 4)) {
        if (++a >= 16)
            break;
        POLL();
    }
    limit = GCALL0(0x060279E2);
    while ((unsigned int)limit >= (unsigned int)LD32(0x060B37A8 + b * 4)) {
        if (++b >= 16)
            break;
        POLL();
    }
    v = LD8(0x060B37E8 + (short)(a * 17) + b);
    if (v >= 16 && (unsigned char)LD8(0x060C029D) >= 20) {
        if (LD32(0x060C0A88) <= 7)
            v = 17;
        if (LD32(0x060C0A88) <= 3 && LD32(0x060C0A4C + 48) >= 0xBB8)
            v = 18;
    }
    return v;
}
