#include "krnl.h"

/* Rows of 16 bytes: mode 1 ORs 14 into the cell down and right of each 15, mode 2 ORs byte pairs together, mode 3 ORs each cell with the one before. */
void f0603110C(gaddr buf, unsigned short mode)
{
    int x, y;
    int prev, cell;

    switch (mode) {
    case 1:
        y = 0;
        do {
            x = 0;
            do {
                if (LD8(buf + y * 16 + x) == 15)
                    ST8(buf + y * 16 + x + 17, LD8(buf + y * 16 + x + 17) | 14);
            } while (AGAIN(++x < 15));
        } while (AGAIN(++y < 15));
        break;
    case 2:
        y = 0;
        do {
            x = 0;
            do {
                ST8(buf + y * 16 + x, LD8(buf + y * 16 + x * 2) | LD8(buf + y * 16 + x * 2 + 1));
            } while (AGAIN(++x < 8));
        } while (AGAIN(++y < 16));
        break;
    case 3:
        y = 0;
        do {
            prev = 0;
            x = 0;
            do {
                cell = LD8(buf + y * 16 + x);
                ST8(buf + y * 16 + x, cell | prev);
                prev = cell;
            } while (AGAIN(++x < 15));
        } while (AGAIN(++y < 16));
        break;
    }
}

void f060311BA(int a, unsigned short b, unsigned short c)
{
    ST32(0x060DFE08, a);
    ST32(0x060DFE0C, b);
    ST32(0x060DFE10, c);
}

void f0603176E(short v)
{
    ST16(0x060DFE14, v);
}

void f060317D0(void)
{
    ST16(0x060DFE90, 0);
    ST16(0x060DFE16, 0);
}

void f0603184E(int v)
{
    ST32(0x060C1250, v);
}

void f06031854(short a, short b)
{
    ST16(0x060C1246, a);
    ST16(0x060C1248, b);
}

void f0603185E(unsigned char a, unsigned char b, unsigned char c)
{
    ST8(0x060C123D, a);
    ST8(0x060C123E, b);
    ST8(0x060C123C, c);
}

/* Follows the chain of 16-byte nodes from 0 for the one whose key at 4 is key. */
int f06031AE2(int key)
{
    unsigned int i;
    int cur = 0;
    REF(Node16) node;

    if (!key)
        return 0;
    for (i = 0; i < (unsigned char)LD8(0x060C1244); i++) {
        POLL();
        node = ELEM(Node16, 0x060C104C, cur);
        if (GET(Node16, node, key) == key)
            break;
        cur = GET(Node16, node, next);
    }
    return i == (unsigned char)LD8(0x060C1244) ? 0 : cur;
}

int f06032EF2(void)
{
    int mode = LD32(0x060C1048);
    int ret = mode & 48;
    int sum, i;

    ST8(0x060C1254, 1);
    if (ret == 16) {
        i = 0;
        do {
            if (LDU16(0x060C065E + i * 2) >= (unsigned char)LD8(0x060C0683))
                ST8(0x060C1254, 0);
        } while (AGAIN(++i < 10));
    } else if ((mode & 0x3000) == 0x1000) {
        sum = 0;
        i = 0;
        do {
            sum += (unsigned char)LD8(0x060E1C4E + i);
        } while (AGAIN(++i < 8));
        ret = 0x060E1C4E;
        if (sum == 0)
            ST8(0x060C1254, 0);
    } else {
        ret = 0x060C1256;
        if (LDU16(0x060C1256) >= (unsigned char)LD8(0x060C0683))
            ST8(0x060C1254, 0);
    }
    return ret;
}

int f06032F6E(short who)
{
    unsigned char me;
    unsigned char mine;
    unsigned char other;

    if (!LD8(0x060C063C))
        return 0;
    me = LD8(0x060C063F);
    if ((LD32(0x060C1048) & 0xC00) == 0x400)
        return me == who ? -1 : 0;
    other = LD8(0x060C0640 + who);
    mine = LD8(0x060C0640 + me);
    if ((other & 3) && (other & ~3) == (mine & ~3))
        return -1;
    return 0;
}

short f06032FF2(short x)
{
    if (LD8(0x060C063C) && (LD32(0x060C1048) & 0xC00) == 0x800
        && (short)(x * 4) == ((unsigned char)LD8(0x060C0640 + (unsigned char)LD8(0x060C063F)) & -4))
        return -1;
    return 0;
}

void f0603302C(void)
{
    int i;

    ST8(0x060C063C, 0);
    i = 0;
    do {
        if (LD8(0x060C0640 + i) & 3) {
            ST8(0x060C0FC4 + i, 1);
            ST8(0x060C063C, LD8(0x060C063C) + 1);
        } else {
            ST8(0x060C0FC4 + i, 0);
        }
        ST8(0x060E1A98 + i, 0xFF);
    } while (AGAIN(++i < 10));
}

void f06033098(void)
{
    int i, j;

    ST16(0x060C1256, 0);
    ST16(0x060C1258, 0);
    ST8(0x060C1254, 1);
    i = 0;
    do {
        ST16(0x060C0672 + i * 2, 0);
    } while (AGAIN(++i < 5));
    i = 0;
    do {
        ST16(0x060C065E + i * 2, 0);
        ST16(0x060E1C32 + i * 2, 0);
        j = 0;
        do {
            ST16(0x060E1AA2 + i * 20 + j, 0);
            ST16(0x060E1B6A + i * 20 + j, 0);
        } while (AGAIN((j += 2) < 20));
    } while (AGAIN(++i < 10));
    i = 0;
    do {
        ST8(0x060E1C46 + i, 0);
        j = 0;
        do {
            ST16(0x060E1C56 + i * 20 + j * 2, 0);
        } while (AGAIN(++j < 10));
    } while (AGAIN(++i < 8));
    GJUMP0(0x0603302C);
}

void f06033198(void)
{
    int i, j;

    i = 0;
    do {
        ST8(0x060E1A98 + i, 0);
        j = 0;
        do {
            ST16(0x060E1B6A + (i * 10 + j) * 2, 0);
            ST16(0x060E1AA2 + (i * 10 + j) * 2, 0);
        } while (AGAIN(++j < 10));
    } while (AGAIN(++i < 10));
    i = 0;
    do {
        ST8(0x060E1C4E + i, 0);
        ST8(0x060E1C46 + i, 0);
        j = 0;
        do {
            ST16(0x060E1C56 + (i * 10 + j) * 2, 0);
        } while (AGAIN(++j < 10));
    } while (AGAIN(++i < 8));
    ST8(0x060C0683, 0);
}

void f0603320C(void)
{
    int v;
    int i;

    ST8(0x060C0681, 3);
    ST8(0x060C0683, 3);
    ST8(0x060C0682, 0);
    ST8(0x060C0680, 0);
    ST8(0x060C029C, 9);
    ST8(0x060C029D, 0);
    ST32(0x060C1048, 2);
    v = LD32(0x060C1238);
    i = 9;
    do {
        v = v << 2 | (LD8(0x26006134 + i) == 0);
    } while (AGAIN(--i > 4));
    do {
        v = v << 2 | (LD8(0x26006134 + i) == 0 ? 1 : 2);
    } while (AGAIN(--i >= 0));
    ST32(0x060C1238, v);
    i = 0;
    do {
        ST8(0x060C1905 + i, 0);
        ST8(0x060C18FC + i, 0);
        ST8(0x060E1C4E + i, 0);
    } while (AGAIN(++i < 8));
    ST8(0x060C1905 + i, 0);
    ST8(0x060C18FC + i, 0);
}

int f06033380(void)
{
    unsigned int bits = (LD32(0x060C1048) & 0x3000) == 0x1000 ? 0xFFFF : 0xFFFFF;
    int changed = 0;
    int i = 0;
    int p;

    bits &= LD32(0x060C1234);
    do {
        p = 0x060C0640 + i;
        if (((LD8(p) & 3) != 0) != ((bits & 3) != 0)) {
            changed++;
            ST8(p, (LD8(p) & 0xFC) | (bits & 3));
        }
        bits >>= 2;
    } while (AGAIN(++i < 10));
    return changed ? -1 : 0;
}

void f060337BE(signed char on)
{
    int e;

    if (on == 0) {
        ST32(0x060C125C, 0x06033894);
        return;
    }
    e = POINTS + (short)((unsigned char)LD8(0x060C122C) * 24);
    switch (LDU16(e + 2)) {
    case 1:
        ST32(0x060C125C, 0x0605A258);
        break;
    case 2:
        ST32(0x060C125C, 0x0605ACD8);
        break;
    case 3:
        ST32(0x060C125C, 0x0605B2CE);
        break;
    case 4:
        ST32(0x060C125C, 0x0602AEF0);
        break;
    case 5:
        ST32(0x060C125C, 0x0602BDAC);
        break;
    case 255:
        ST32(0x060C125C, 0x0602DE14);
        break;
    }
    e = POINTS + (short)((unsigned char)LD8(0x060C122C) * 24);
    ST32(e + 12, LD32(e + 12) | 128);
}

void f06033A30(void)
{
    GJUMP1(0x06035D64, 0x060B5244);
}

void f06033A60(void)
{
    int mode = LD32(0x060C1048) & 48;
    int i;

    if (mode == 16) {
        ST32(0x060C1048, LD32(0x060C1048) & ~0x02000000);
        ST8(0x060C0683, 3);
    } else if (mode == 32) {
        ST32(0x060C1048, LD32(0x060C1048) & ~0x01000000);
        i = 0;
        do {
            ST8(0x060C18FC + i, 0);
            ST8(0x060E1C46 + i, 0);
        } while (AGAIN(++i < 9));
        ST8(0x060C0683, 0);
    }
}

void f06033BD6(unsigned char on)
{
    if (on)
        ST32(0x060C1048, (LD32(0x060C1048) & ~0xC0) | (LDU16(0x060EC47A + (unsigned char)LD8(0x060C122C) * 24) == 1 ? 64 : 128));
}

void f06033C12(void)
{
    if (LD32(0x060C1040) & 4)
        return;
    if (LDU16(0x26006096) == 136)
        ST8(0x060C0FC0, LD8(0x060C0FC0) + 1);
    else
        ST8(0x060C0FC0, 0);
    if ((unsigned char)LD8(0x060C0FC0) >= 60) {
        ST32(0x060C1040, LD32(0x060C1040) | 12);
        GJUMP1(0x0600996A, 5);
    }
}

/* Reads the next bit, least significant first, from the bytes at r->src. */
int f060342F8(REF(BitReader) r)
{
    int at;

    if (!GET(BitReader, r, count)) {
        at = GET(BitReader, r, src) + 1;
        SET(BitReader, r, src, at);
        SET(BitReader, r, byte, LD8(at - 1));
    }
    SET(BitReader, r, bit, GET(BitReader, r, byte) & 1);
    SET(BitReader, r, byte, (unsigned int)GET(BitReader, r, byte) >> 1);
    SET(BitReader, r, count, (GET(BitReader, r, count) + 1) & 7);
    return GET(BitReader, r, count);
}

int f06034322(REF(Unpack) u)
{
    int src;

    if (GET(Unpack, u, phase) == 0) {
        src = GET(Unpack, u, src);
        SET(Unpack, u, src, src + 1);
        SET(Unpack, u, w32, LD8(src));
    }
    SET(Unpack, u, out, GET(Unpack, u, w32) & 3);
    SET(Unpack, u, w32, (unsigned int)GET(Unpack, u, w32) >> 2);
    SET(Unpack, u, phase, (GET(Unpack, u, phase) + 2) & 7);
    return GET(Unpack, u, phase);
}

void f0603434C(REF(Unpack) u)
{
    int src;

    if (GET(Unpack, u, phase) == 0) {
        src = GET(Unpack, u, src);
        SET(Unpack, u, src, src + 1);
        SET(Unpack, u, w32, LD8(src));
        src = GET(Unpack, u, src);
        SET(Unpack, u, src, src + 1);
        SET(Unpack, u, w36, LD8(src));
        src = GET(Unpack, u, src);
        SET(Unpack, u, src, src + 1);
        SET(Unpack, u, w40, LD8(src));
    }
    SET(Unpack, u, out, (GET(Unpack, u, w40) & 1) << 2 | (GET(Unpack, u, w36) & 1) << 1 | (GET(Unpack, u, w32) & 1));
    SET(Unpack, u, w32, (unsigned int)GET(Unpack, u, w32) >> 1);
    SET(Unpack, u, w36, (unsigned int)GET(Unpack, u, w36) >> 1);
    SET(Unpack, u, w40, (unsigned int)GET(Unpack, u, w40) >> 1);
    SET(Unpack, u, phase, (GET(Unpack, u, phase) + 1) & 7);
}

int f060343BA(REF(Unpack) u)
{
    int src;

    if (GET(Unpack, u, phase) == 0) {
        src = GET(Unpack, u, src);
        SET(Unpack, u, src, src + 1);
        SET(Unpack, u, w32, LD8(src));
    }
    SET(Unpack, u, out, GET(Unpack, u, w32) & 15);
    SET(Unpack, u, w32, (unsigned int)GET(Unpack, u, w32) >> 4);
    SET(Unpack, u, phase, (GET(Unpack, u, phase) + 4) & 7);
    return GET(Unpack, u, phase);
}

void f060343E6(void)
{
    int i = 0;

    do {
        ST8(0x060C1260 + i, 0);
    } while (AGAIN(++i < 512));
}

void f060343F8(void)
{
    int n = LD8(0x060C146E);

    if (n < 2)
        ST32(0x060C162C, 1);
    else if (n < 4)
        ST32(0x060C162C, 2);
    else
        ST32(0x060C162C, 4);
}

int f0603441A(void)
{
    int p = 0x060B53C8 + LD8(0x060C146E) * 16;

    ST32(0x060C160C, LD32(p));
    ST32(0x060C15F0, LD32(p + 4));
    ST32(0x060C15F4, LD32(p + 8));
    return LD32(p + 12);
}

int f06034A8C(unsigned char who)
{
    int team = (LD32(0x060C1048) & 0xC00) == 0x800 ? (unsigned char)LD8(0x060C0640 + who) & 252 : 255;
    int score = 0;
    int base, j;

    if (LD8(0x060C0640 + who) & 3) {
        base = 0x060E1AA2 + (unsigned char)(who * 20);
        for (j = 0; j < 10; j++) {
            if (j != who) {
                if (((unsigned char)LD8(0x060C0640 + j) & 252) == team)
                    score -= LD16(base + j * 2) * 3;
                else
                    score += LD16(base + j * 2);
                score = (short)score;
                if (score > 9999)
                    score = 9999;
            }
            POLL();
        }
    }
    return score;
}

void f06035926(void)
{
    ST8(0x060C1660, 255);
    ST8(0x060C1661, 255);
    ST8(0x060C1662, 0);
    ST8(0x060C1663, 0);
}

void f060359F0(void)
{
    ST16(0x060C1656, 80);
    ST16(0x060C1654, -256);
}

void f06035A0A(unsigned short id)
{
    int left = 255, top = 255, right = 0, bottom = 0;
    int i, e, x, y, x1;

    for (i = 0; i < 30; i++) {
        e = POINTS + i * 24;
        if (LD32(e + 12) != -1 && LD8(e + 22) != 0 && LDU16(e) == id) {
            x = (unsigned char)LD8(e + 20);
            y = (unsigned char)LD8(e + 21);
            x1 = x + (unsigned char)LD8(e + 22);
            if (x < left)
                left = x;
            if (x1 > right)
                right = x1;
            if (y < top)
                top = y;
            if (y > bottom)
                bottom = y;
        }
        POLL();
    }
    ST8(0x060C1660, left & 63);
    ST8(0x060C1662, right & 63);
    ST8(0x060C1661, top & 63);
    ST8(0x060C1663, (bottom + 2) & 63);
}

void f06035DC4(unsigned short i, int mode)
{
    int e, w;

    if (i >= 30)
        return;
    e = POINTS + (short)(i * 24);
    w = LD32(e + 12);
    if (w == -1)
        return;
    w &= 0x7FFFFFFF;
    if (mode == 0 || mode == 0x01000000 || mode == 0x02000000)
        w = (w & 0xFCFFFFFF) | mode;
    else if (mode == 0x00100000)
        w |= 0x80000000;
    ST32(e + 12, w);
}

void f06035E18(unsigned short i, int op)
{
    int e;
    int flags;

    if (i >= 30)
        return;
    e = 0x060EC478 + (short)(i * 24);
    flags = LD32(e + 12);
    if (flags == -1)
        return;
    switch (op) {
    case 0:
    case 0x01000000:
    case 0x02000000:
        flags = (flags & 0xFCFFFFFF) | op;
        break;
    case 0x00100000:
        flags |= 0x80000000;
        break;
    case 0x00200000:
        flags &= 0x7FFFFFFF;
        break;
    }
    ST32(e + 12, flags);
}

/* The first of 30 slots of 24 bytes whose word at 12 is not -1 and whose first three halfwords match, or 255. */
int f0603666E(unsigned short x, unsigned short y, unsigned short z)
{
    REF(Point24) s;
    int i;

    for (i = 0; i < 30; i++) {
        POLL();
        s = ELEM(Point24, 0x060EC478, i);
        if (GET(Point24, s, link) != -1 && GET(Point24, s, x) == x && GET(Point24, s, y) == y
            && GET(Point24, s, z) == z)
            break;
    }
    return i < 30 ? i : 255;
}

int f06036AD2(unsigned short n)
{
    int ent = 0x060EC478 + (short)(n * 24);
    short id = LD16(ent + 4);
    int armed = 0xFFFF;
    int two = 255;
    int zero = 255;
    int last = 255;
    int k;
    int e;
    int flags;

    for (k = 29; k >= 0; k--) {
        e = 0x060EC478 + k * 24;
        flags = LD32(e + 12);
        if (flags != -1 && !(flags & 0x80000000) && LD16(e) == id) {
            if (flags & 64)
                armed = k;
            if ((flags & 0x03000000) == 0x02000000)
                two = k;
            last = k;
            if (!(flags & 0x03000000))
                zero = k;
        }
        POLL();
    }
    if (armed != 0xFFFF) {
        e = 0x060EC478 + (short)(armed * 24);
        ST32(e + 12, LD32(e + 12) & ~64);
        return armed;
    }
    k = LD32(ent + 12) & 0x800 ? zero : two;
    return k == 255 ? last : k;
}

int f06036DB2(short x, short y, short z, int link)
{
    int i = 0;
    int e;

    do {
        if (LD32(POINTS + (short)(i * 24) + 12) == -1)
            break;
        i++;
    } while (AGAIN(i < 30));
    if (i == 30)
        return 255;
    e = POINTS + (short)(i * 24);
    ST32(e + 12, 0);
    ST16(e, x);
    ST16(e + 4, y);
    ST16(e + 2, z);
    ST16(e + 16, 0);
    ST32(e + 8, link);
    return i;
}

void f06036E1A(short v)
{
    ST16(0x060C1654, v);
}

int f06036E20(void)
{
    return LD16(0x060C1654);
}

void f06036E26(short v)
{
    ST16(0x060C1656, v);
}

short f06036E2C(void)
{
    return LD16(0x060C1656);
}

/* Entries of 24 bytes: the index of the first whose halfword at 4 equals entry n's halfword at 0, or 0xFFFF. */
int f06036FD0(unsigned short n)
{
    unsigned short key;
    int i;

    if (n >= 30)
        return 0xFFFF;
    key = LDU16(0x060EC478 + n * 24);
    i = 0;
    do {
        if (LDU16(0x060EC478 + i * 24 + 4) == key)
            return i;
    } while (AGAIN(++i < 30));
    return 0xFFFF;
}

void f06037216(unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    int obj = OBJ(LDU16(0x060C1666));

    ST16(obj + 20, a);
    ST16(obj + 22, b);
    ST16(obj + 24, c);
    ST16(obj + 26, d);
}

void f0603796C(unsigned short id)
{
    int e = 0x060EC478;
    int i;

    for (i = 0; i < 30; i++, e += 24) {
        if (LD32(e + 12) != -1 && LDU16(e) == id)
            ST32(e + 12, LD32(e + 12) & ~0x20000000);
        POLL();
    }
}

void f060379EE(void)
{
    ST16(0x060C1688, 0);
}

void f06037A36(unsigned short v)
{
    ST16(0x060C168A, v);
}

void f06037A74(unsigned short x)
{
    if (x == 0x100) {
        ST8(0x060FB8DC, LD8(0x060FB8DC) | 32);
        ST16(0x060FB8B6, LD16(0x060FB8B6) & 255);
        return;
    }
    if (x) {
        ST8(0x060FB8DC, LD8(0x060FB8DC) | 8);
        ST16(0x060FB8C4, (LD16(0x060FB8C4) & 255) | (x >> 3) << 8);
    }
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, x ? (LD16(0x060FB8A8) & 0xFFF7) | 8 : LD16(0x060FB8A8) & 0xFFF7);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 32);
    ST16(0x060FB8B6, (LD16(0x060FB8B6) & 255) | 0x300);
}

void f06037C24(void)
{
    int i = 0;
    int e;
    int off;

    do {
        e = 0x060EC748 + i * 24;
        for (off = 4; off <= 18; off += 2)
            ST16(e + off, 0);
        ST32(e + 20, 0);
    } while (AGAIN(++i < 15));
    ST8(0x060C1668, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06038174(void)
{
}

void f060382B6(gaddr ids)
{
    for (; LD16(ids) > 0; ids += 2) {
        POLL();
        ST16(OBJS + (unsigned short)(LDU16(ids) * 84) + 36, -LD16(0x060C1654));
    }
}

void f06038334(gaddr list, short clear, short set)
{
    int o;

    while (LD16(list) > 0) {
        o = OBJ(LDU16(list));
        ST16(o + 42, LD16(o + 42) & ~clear);
        o = OBJ(LDU16(list));
        list += 2;
        ST16(o + 42, LD16(o + 42) | set);
        POLL();
    }
}

void f06038392(short value, gaddr list)
{
    while (LD16(list) > 0) {
        ST16(OBJ(LDU16(list)) + 38, value);
        list += 2;
        POLL();
    }
}

void f060383B6(unsigned short v, gaddr ids)
{
    while (LD16(ids) > 0) {
        ST16(OBJ(LDU16(ids)) + 36, v);
        ids += 2;
        POLL();
    }
}

void f060383DA(gaddr list, short a, short b)
{
    int o;

    while (LD16(list) > 0) {
        o = OBJ(LDU16(list));
        ST16(o + 68, a);
        o = OBJ(LDU16(list));
        list += 2;
        ST16(o + 70, b);
        POLL();
    }
}

void f0603847E(int i)
{
    int e = POINTS + (short)(i * 24);
    short a = LD16(e);
    short b = LD16(e + 2);
    int p = 0x060B559C;

    while (LD16(p) >= 0 && !(LD16(p) == a && LD16(p + 2) == b)) {
        p += 8;
        POLL();
    }
    if (LD16(p) >= 0) {
        ST16(e + 16, LD16(p + 6));
        ST8(e + 22, LD8(p + 4));
        ST8(e + 23, LD8(p + 5));
        if (LD8(p + 5) & 128)
            ST32(e + 12, LD32(e + 12) | 0x80000000);
    } else {
        ST16(e + 16, 0);
        ST8(e + 22, 0);
    }
}

void f06039374(void)
{
}

void f060393EE(void)
{
}

/* SMPC: waits for the status flag to clear, sets it, writes command 26, and waits for it to clear again. */
void f06039598(void)
{
    if (LD32(0x060C0AA8) == 0) {
        while (AGAIN(LD8(0x20100063) & 1))
            ;
        ST8(0x20100063, 1);
        ST8(0x2010001F, 26);
        while (AGAIN(LD8(0x20100063) & 1))
            ;
    }
}

void f060395C2(void)
{
    if (LD32(0x060C0AA8))
        return;
    do {
    } while (AGAIN(LD8(0x20100063) & 1));
    ST8(0x20100063, 1);
    ST8(0x2010001F, 25);
    do {
    } while (AGAIN(LD8(0x20100063) & 1));
}

void f06039DD8(void)
{
    ST8(0x060C1725, 0);
}

unsigned short f06039F96(void)
{
    return LDU16(0x060C1740);
}

void f06039F9E(char v)
{
    ST8(0x060C02A2, v);
}

void f06039FA4(void)
{
    ST8(0x060C02A2, 1);
}

void f06039FAC(void)
{
    ST8(0x060C02A4, 1);
}

void f06039FB4(void)
{
    ST8(0x060C02A3, 1);
}

unsigned char f06039FBC(void)
{
    return LD8(0x060C02A2);
}

unsigned char f06039FE8(void)
{
    return LD8(0x060C02A3);
}

int f06039FF0(int n)
{
    return LD8((OBJECTS + 0x30) + n * 124 + 4) & 128 ? 0 : -1;
}

int f0603A00E(int n)
{
    if (LD8(0x060D5F34 + n * 124) & 192)
        return 0;
    return -1;
}

int f0603A4A4(int a, int b, int c)
{
    if ((short)c == -1)
        return 0;
    return a * 34 + c + b + 128;
}

int f0603A54A(int i)
{
    int e = 0x060EC748 + (short)(i * 24);

    if (LD16(e + 6) == -1)
        return 0;
    return 230 + LD16(e + 4) + LD16(e + 6) + i * 34;
}

void f0603A614(unsigned short obj, short dir, short amount)
{
    ST16(OBJIDX, obj);
    switch (dir) {
    case 1:
        GJUMP1(0x0600A28C, amount);
        break;
    case 2:
        GJUMP1(0x0600A306, amount);
        break;
    case 3:
        GJUMP1(0x0600A28C, (short)-amount);
        break;
    case 4:
        GJUMP1(0x0600A306, (short)-amount);
        break;
    }
}

void f0603AAD2(unsigned short a, unsigned short b, unsigned short c)
{
    int i = 0;
    int e;

    do {
        e = 0x060EC778 + i * 24;
        if (LD16(0x060C1728 + i * 2)) {
            ST16(e + 14, c);
            ST16(e + 2, a);
            ST16(e + 4, b);
            ST32(e + 20, 0x0603AA2C);
        }
    } while (AGAIN(++i < 2));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603AF08(void)
{
}

int f0603AF0C(void)
{
    return LD16(OBJ(LDU16(0x060D7E50)) + 38) == -10 ? -1 : 0;
}

void f0603AF2E(void)
{
    GJUMP1(0x06022EDA, 32);
}

void f0603B252(unsigned char value)
{
    ST8(0x060C1734, value);
}

void f0603B258(short v)
{
    ST16(0x060C1736, v);
}

void f0603B650(void)
{
    ST32(0x060D7E30, 0x0603B4B2);
}

void f0603B658(void)
{
    ST32(0x060D7E30, 0x0603B56C);
}

int f0603BBD6(void)
{
    return LD32(0x060D7E30) == 0x0603DDA6 ? -1 : 0;
}

void f0603BE9E(int i)
{
    ST16(SLOTS + 16 + (short)(i * 24), 1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603C7EE(void)
{
}

void f0603C9B6(unsigned short v)
{
    ST32(SLOTS, 0x0603C83A);
    ST16(SLOTS + 20, v);
    ST16(SLOTS + 18, 0);
}

void f0603C9E4(void)
{
    ST16(0x060C173A, 0);
    ST16(0x060C173C, 1);
    ST16(0x060C173E, 1);
}

int f0603C9F6(void)
{
    unsigned int x = LDU16(0x060C173E);
    unsigned int n = LDU16(0x060C173C);
    unsigned int next;

    ST16(0x060C173C, n + 1);
    next = (((((x << 8) ^ x) & 0xFF00) | ((n ^ x) & 255)) << 1) + (((x >> 14) ^ x) & 1);
    ST16(0x060C173E, next);
    next &= 0xFFFF;
    return (next & 255) ^ (next >> 8);
}

void f0603CC9A(unsigned short v)
{
    ST16(0x060D7E24, v);
}

void f0603CCA2(unsigned short a, unsigned short b)
{
    ST16(0x060D7E28, a);
    ST16(0x060D7E2A, b * 20);
}

int f0603D16C(unsigned short id, short kind, short snap)
{
    int obj = OBJ(id);
    short limit = kind >= 4 ? 55 : kind * 16 + 7;
    short d;

    ST16(obj + 10, 1);
    if (snap) {
        d = limit;
    } else {
        d = LD16(obj + 26) - LD16(obj + 18);
        if (d > limit)
            d -= 4;
        else if (d < limit)
            d += 4;
    }
    ST16(obj + 20, LD16(obj + 16));
    ST16(obj + 24, LD16(obj + 16) + (d > 7 ? 0x11F : 0));
    ST16(obj + 22, LD16(obj + 18) + 8);
    ST16(obj + 26, LD16(obj + 18) + d);
    return d == limit;
}

void f0603D314(void)
{
    unsigned int v = LDU16(0x060D7E14);

    if (v != 255 && v != 0) {
        ST16(0x060D7E14, 0);
        ST16(0x060D7E10, LD16(0x060D7E10) + 1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603DDA6(void)
{
}

int f0603E212(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 4);
    gaddr o = OBJS + (unsigned short)(GET(Slot24, s, obj) * 84);

    if (!LD16(o + 10) || LDU16(o + 60) >= 0xFF00)
        return -1;
    return 0;
}

void f0603ED78(int n)
{
    GJUMP1(0x06022EDA, n);
}
