#include "krnl.h"

int f060300C2(void)
{
    return GJUMP1(0x0600996A, 25);
}

int f060306F0(void)
{
    int found;

    if (GCALL0(0x0602E88E)) {
        gaddr a = OBJ(LDU16(0x060C0FF4));
        gaddr b = OBJ(LDU16(0x060C0FF6));
        gaddr c = OBJ(LDU16(0x060C0FF8));

        ST16(c + 70, 0);
        ST16(c + 68, 0);
        ST16(b + 70, 0);
        ST16(b + 68, 0);
        ST16(a + 70, 0);
        ST16(a + 68, 0);
    }
    found = GCALL0(0x0602F648);
    if (!found)
        return found;
    return GJUMP1(0x0600996A, 7);
}

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

void f060317E4(void)
{
    gaddr p = 0x060C104C;

    do {
        ST32(p + 4, 0);
        ST8(p + 1, 0);
        ST8(p, 0);
        ST16(p + 14, 0xFFFF);
        p += 16;
        ST32(p - 8, 0);
        ST8(p - 4, 0);
        ST8(p - 3, 0);
    } while (AGAIN(p < 0x060C122C));
    ST8(0x060C1244, 1);
    ST16(0x060C1246, 0);
    ST16(0x060C1248, 0);
    ST8(0x060C123D, 50);
    ST8(0x060C123E, 51);
    ST8(0x060C123C, 52);
    ST8(0x060C123F, 50);
    ST8(0x060C1240, 51);
    ST8(0x060C1241, 52);
    ST8(0x060C1242, 53);
    GCALL0(0x0603198C);
    ST32(0x060C1250, 0);
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

void f0603198C(void)
{
    if (LDU16(0x060C124A))
        GCALL1(0x060692DC, LDU16(0x060C124A));
    ST16(0x060C124A, 0);
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

int f06031B94(int arg)
{
    return LD16((GCALL1(0x06031AE2, arg) & 0xFFFF) * 16 + 0x060C105A) & 48;
}

void f06031BAA(int n, short bits)
{
    gaddr p = 0x060C105A + ((unsigned short)GCALL1(0x06031AE2, n) << 4);

    ST16(p, (LD16(p) & 0xFFCF) | bits);
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

void f060332A8(short a, short b, short c, int flag)
{
    GJUMP2(0x06035DC4, GCALL3(0x0603666E, a, b, c), flag ? 0x02000000 : 0);
}

int f060332E6(short a, short b, short c, int flag)
{
    GCALL2(0x06035DC4, GCALL3(0x0603666E, a, b, c), flag ? 0x00200000 : 0x00100000);
    return flag != 0;
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

void f06033686(void)
{
    int a, b, c;

    GCALL4(0x060332A8, 1, 1, 255, LD32(0x060C1048) & 0x00010000);
    GCALL4(0x060332A8, 1, 2, 255, LD32(0x060C1048) & 0x01000000);
    a = GCALL4(0x060332E6, 1, 2, 255, LD32(0x060C1048) & 0x00010000) & 0xFFFF;
    GCALL4(0x060332A8, 1, 3, 255, LD32(0x060C1048) & 0x00020000);
    if ((LD32(0x060C1048) & 48) != 32)
        b = GCALL4(0x060332E6, 1, 3, 255, (LD32(0x060C1048) & 0x00010000) * a);
    else
        b = GCALL4(0x060332E6, 1, 3, 255, (LD32(0x060C1048) & 0x01000000) * a);
    b &= 0xFFFF;
    GCALL4(0x060332A8, 1, 4, 255, LD32(0x060C1048) & 0x00040000);
    c = GCALL4(0x060332E6, 1, 4, 255, (LD32(0x060C1048) & 0x00020000) * b) & 0xFFFF;
    if (!(LD32(0x060C1048) & 0x00040000) || (LD32(0x060C1048) & 0xC00) != 0x800) {
        ST32(0x060C1048, LD32(0x060C1048) & 0xFFF7FFFF);
        GCALL2(0x06035DC4, GCALL3(0x0603666E, 1, 5, 255), 0);
        GCALL2(0x06035DC4, GCALL3(0x0603666E, 1, 5, 255), 0x00100000);
    } else {
        GCALL4(0x060332A8, 1, 5, 255, LD32(0x060C1048) & 0x00080000);
        GCALL4(0x060332E6, 1, 5, 255, (LD32(0x060C1048) & 0x00040000) * c);
    }
    GJUMP1(0x06036F40, 1);
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

void f06033A38(void)
{
    if (GCALL0(0x060504B8) & 0xFFFF)
        return;
    GJUMP2(0x06035DC4, GCALL3(0x0603666E, 101, 2, 255), 0x00100000);
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

void f06033C9C(void)
{
    int n;

    for (n = 1; n <= 2; n++) {
        gaddr obj = OBJ(LDU16(0x060EC48A + (short)(GCALL3(0x0603666E, 101, n, 255) * 24)));

        GCALL2(0x0606AAC8, obj, 3);
        ST16(obj + 70, 0);
        ST16(obj + 74, 8);
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

void f06034B24(gaddr out)
{
    int i = 0;

    do {
        if (!(LD8(0x060C0640 + i) & 3))
            ST16(out + i * 2, -30000);
        else
            ST16(out + i * 2, GCALL1(0x06034A8C, i));
        i++;
    } while (AGAIN(i < 10));
}

void f06034F80(void)
{
    gaddr p;
    int n;

    if ((LD32(0x060C1048) & 15) == 2)
        return;
    p = 0x060E1CF6;
    n = 100;
    do {
        if (LD8(p)) {
            GCALL1(0x060692DC, LDU16(p + 4));
            ST8(p, 0);
        }
        n--;
        p += 10;
    } while (AGAIN(n != 0));
    ST32(0x060C1648, 0);
}

void f06035926(void)
{
    ST8(0x060C1660, 255);
    ST8(0x060C1661, 255);
    ST8(0x060C1662, 0);
    ST8(0x060C1663, 0);
}

void f060359B0(unsigned short id, int arg)
{
    gaddr p = POINTS;
    int i = 0;

    if (id == 255)
        return;
    do {
        if (LDU16(p) == id)
            GCALL2(0x06035E18, i, arg);
        i++;
        p += 24;
    } while (AGAIN(i < 30));
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

int f0603645A(int id, int flags)
{
    int found = 255;
    int pad = LDU16(0x260060CA);

    if (!(flags & 0x00040000)) {
        if (pad & 0x2000)
            found = GCALL1(0x06035C38, id);
        if (pad & 0x1000)
            found = GCALL1(0x06035B7E, id);
        ST8(0x060C1672, (LD32(0x060EC484 + (short)(id * 24)) & 0x00080000) ? 15 : 10);
        if ((id & 0xFFFF) == (GCALL1(0x06035C38, id) & 0xFFFF))
            ST8(0x060C1672, LD8(0x060C1672) & 5);
    } else {
        if (pad & 0x8000)
            found = GCALL1(0x06035C38, id);
        if (pad & 0x4000)
            found = GCALL1(0x06035B7E, id);
        ST8(0x060C1672, 5);
    }
    if ((LD8(0x060C1672) & 5) && (pad & 0xC000))
        GCALL1(0x0600996A, 4);
    if ((LD8(0x060C1672) & 10) && (pad & 0x3000))
        GCALL1(0x0600996A, 4);
    if (pad)
        ST8(0x060C1669, 0);
    if ((found & 0xFFFF) == 255)
        found = id;
    return found;
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

void f060368DE(short id)
{
    gaddr p = POINTS;
    int i;

    for (i = 0; i < 30; i++) {
        if (LD32(p + 12) != -1 && LD16(p) == id && LD8(p + 22)) {
            if (LD16(p + 18))
                GCALL1(0x060692DC, LDU16(p + 18));
            ST16(p + 18, 0);
        }
        p += 24;
        POLL();
    }
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

int f06036BCA(void)
{
    gaddr p = POINTS;
    int i = 0;

    GCALL0(0x06037C24);
    do {
        ST32(p + 12, -1);
        ST16(p + 16, 0);
        ST16(p + 18, 0);
        ST8(p + 22, 0);
        ST16(p, 255);
        p += 24;
        i++;
    } while (AGAIN(i < 30));
    ST8(0x060C1243, 0);
    return 22;
}

void f06036C10(short id)
{
    gaddr p = POINTS;
    int i = 0;

    GCALL0(0x06037C24);
    do {
        if (LD16(p) == id) {
            if (LDU16(p + 4) != 255)
                GCALL1(0x06036C10, LD16(p + 4));
            ST32(p + 12, -1);
            ST16(p + 16, 0);
            ST16(p + 18, 0);
            ST8(p + 22, 0);
            ST16(p, 255);
        }
        i++;
        p += 24;
    } while (AGAIN(i < 30));
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

int f06037094(gaddr p)
{
    int flags;

    if (LD8(p + 23) & 128)
        return 0;
    if (LD32(p + 12) & 0x80000000)
        return 48;
    flags = LD32(p + 12) & 0x03000000;
    if (flags == 0) {
        if (GCALL2(0x0603703C, p, (unsigned char)LD8(0x060C122C)) & 0xFFFF)
            return 16;
        if (LD16(POINTS + (short)((unsigned char)LD8(0x060C122C) * 24)) == LD16(p))
            return 16;
        return (LD32(p + 12) & 128) ? 16 : 32;
    }
    if (flags == 0x02000000)
        return 0;
    return p;
}

void f060371D0(void)
{
    int id = GCALL1(0x060691DA, 5);
    gaddr obj = OBJ(id & 0xFFFF);

    ST16(0x060C1666, id);
    GCALL2(0x0606AAC8, obj, 8);
    ST16(obj + 20, 16);
    ST16(obj + 24, 0x12F);
    ST16(obj + 22, 16);
    ST16(obj + 26, 207);
    ST16(obj + 10, 1);
    GJUMP1(0x0606AB24, obj);
}

void f06037216(unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    int obj = OBJ(LDU16(0x060C1666));

    ST16(obj + 20, a);
    ST16(obj + 22, b);
    ST16(obj + 24, c);
    ST16(obj + 26, d);
}

void f06037264(void)
{
    GCALL1(0x060692DC, LDU16(0x060C1666));
    ST16(0x060C1666, 0);
    GJUMP0(0x06037C80);
}

void f060373A0(void)
{
    gaddr p = 0x060C1674;

    do {
        GCALL1(0x060692DC, LDU16(p));
        ST16(p, 0);
        p += 2;
    } while (AGAIN(p < 0x060C1688));
    p = 0x060C166A;
    do {
        GCALL1(0x060692DC, LD16(p));
        ST16(p, 0);
        p += 2;
    } while (AGAIN(p < 0x060C1672));
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

void f06037C80(void)
{
    gaddr p = 0x060EC748;
    int i = 0;
    int k;

    do {
        ST16(p + 8, 0);
        ST16(p + 6, 0);
        ST16(p + 4, 0);
        for (k = 10; k <= 18; k += 2) {
            if (LD16(p + k))
                GCALL1(0x060692DC, LD16(p + k));
        }
        ST16(p + 18, 0);
        i++;
        ST16(p + 16, 0);
        ST16(p + 14, 0);
        ST16(p + 12, 0);
        ST16(p + 10, 0);
        ST32(p + 20, 0);
        p += 24;
    } while (AGAIN(i < 15));
    ST8(0x060C1668, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06038174(void)
{
}

void f06038268(gaddr list)
{
    while (LD16(list) > 0) {
        GCALL2(0x06008A6A, 8, LDU16(OBJ(LDU16(list)) + 44));
        GCALL1(0x060692DC, LD16(list));
        ST16(list, 0);
        list += 2;
        POLL();
    }
}

void f060382B6(gaddr ids)
{
    for (; LD16(ids) > 0; ids += 2) {
        POLL();
        ST16(OBJS + (unsigned short)(LDU16(ids) * 84) + 36, -LD16(0x060C1654));
    }
}

void f060382E0(gaddr list, unsigned short arg)
{
    while (LD16(list) > 0) {
        GCALL2(0x06069546, LD16(list), arg);
        list += 2;
        POLL();
    }
}

void f0603830A(gaddr list, unsigned short arg)
{
    while (LD16(list) > 0) {
        GCALL2(0x060695EA, LD16(list), arg);
        list += 2;
        POLL();
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

void f060389E2(void)
{
    gaddr p;

    for (p = 0x060C168E; p <= 0x060C1694; p += 2)
        GCALL1(0x0600940A, LD16(p));
}

void f06038E1E(gaddr first, gaddr second)
{
    int n = 0;

    while (LD8(first) != 0) {
        ST8(0x060C1706 + n, LD8(first));
        n++;
        first++;
        if (n >= 11)
            break;
        POLL();
    }
    ST8(0x060C1706 + n, 0);
    n = 0;
    while (LD8(second) != 0) {
        ST8(0x060C1712 + n, LD8(second));
        n++;
        second++;
        if (n >= 10)
            break;
        POLL();
    }
    ST8(0x060C1712 + n, 0);
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

int f06039BE6(int x)
{
    if (!x)
        return 0x00010000;
    if (ABS(x) > 0x00010000)
        return 0;
    return GCALL1(0x060972D8, 0x00010000 - GCALL2(0x060980B4, x, x));
}

void f06039DD8(void)
{
    ST8(0x060C1725, 0);
}

void f06039F54(void)
{
    ST16(0x060C1740, (short)GCALL2(0x0604D47C, (unsigned char)LD8(0x060C029C), (unsigned char)LD8(0x060C029D)) ? 1 : 0);
    ST8(0x060C02A2, 0);
    ST8(0x060C02A3, 0);
    ST8(0x060C02A4, 0);
    ST8(0x060C02A6, GCALL0(0x0604D590));
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

int f0603A02C(short a, short b)
{
    return LD16(GCALL2(0x0600B934, a, b) + 132);
}

int f0603A04E(short a, short b)
{
    return LD16(GCALL2(0x0600B934, a, b) + 134);
}

int f0603A1BC(unsigned short who, int n)
{
    gaddr t = 0x060EC748 + (short)(n * 24);
    gaddr bomber = 0x060D5F30 + who * 124;
    gaddr obj;

    ST16(t + 10, GCALL1(0x060691DA, 1));
    ST16(t + 12, GCALL1(0x060691DA, 1));
    if (!GCALL1(0x0603A00E, who)) {
        ST32(t + 20, 0);
        return 0;
    }
    GCALL2(0x0603A132, LD16(t + 10), LD16(bomber + 22));
    GCALL2(0x0600A3D8, LDU16(bomber + 22), LD16(t + 12));
    obj = OBJ(LDU16(t + 12));
    ST16(obj + 44, 0);
    ST16(obj + 4, 10);
    ST16(obj + 46, 0x310);
    ST16(t + 4, LD8(bomber + 6) & 255);
    GCALL2(0x0606AB08, LD16(t + 10), 3);
    GCALL2(0x0606AAC8, obj, 3);
    return 1;
}

void f0603A268(int n)
{
    gaddr t = 0x060EC748 + (short)(n * 24);

    ST16(t + 10, GCALL1(0x060691DA, 1));
    ST16(t + 12, GCALL1(0x060691DA, 1));
    ST32(t + 20, 0);
}

void f0603A2B8(void)
{
    int i = 0;

    GCALL0(0x06037C24);
    do {
        short next = i + 2;
        gaddr out = 0x060C1728 + i * 2;
        gaddr bomber;
        gaddr t;

        if (!(GCALL2(0x0603A1BC, i, i) & 0xFFFF)) {
            GCALL1(0x0603A268, i);
            GCALL1(0x0603A268, next);
            ST16(out, 0);
            ST16(out + 4, 0);
        } else {
            ST32(0x060EC75C + (short)(i * 24), 0x0603A45A);
            bomber = 0x060D5F30 + i * 124;
            if (!(LDU16(bomber + 46) & 0x800)) {
                GCALL1(0x0603A268, next);
                ST16(out, 0);
                ST16(out + 4, 0);
            } else {
                t = 0x060EC748 + (short)(i * 24) + 48;
                ST32(t + 20, 0x0603A466);
                ST16(t + 8, LD16(0x060D5F30 + LDU16(bomber + 36) * 124 + 52));
                GCALL2(0x0603A1BC, LD16(bomber + 36), next);
                ST16(out, LD16(t + 10));
                ST16(out + 4, LD16(t + 12));
            }
        }
        i++;
    } while (AGAIN(i < 2));
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

int f0603A64C(void)
{
    int left;

    GCALL1(0x0606948A, GET(Fall, FALL_PTR, id));
    if (GET(Fall, FALL_PTR, count) == 0) {
        SET(Fall, FALL_PTR, fn, 0x0603A45A);
    } else {
        GCALL3(0x0603A614, GET(Fall, FALL_PTR, id), GET(Fall, FALL_PTR, y), GET(Fall, FALL_PTR, x));
        GCALL3(0x0603A614, GET(Fall, FALL_PTR, id2), GET(Fall, FALL_PTR, y), GET(Fall, FALL_PTR, x));
        ST16(OBJ(GET(Fall, FALL_PTR, id)) + 38, LD16(OBJ(GET(Fall, FALL_PTR, id)) + 38) + HELPER(GET(Fall, FALL_PTR, v) >> 8));
        SET(Fall, FALL_PTR, v, GET(Fall, FALL_PTR, v) + GET(Fall, FALL_PTR, dv));
    }
    left = GET(Fall, FALL_PTR, count) - 1;
    SET(Fall, FALL_PTR, count, left);
    return left;
}

void f0603A82E(void)
{
    int i = 0;

    do {
        gaddr obj = OBJ(LDU16(0x060EC752 + (short)((i + 2) * 24)));

        ST16(obj + 16, LD16(obj + 16) + LD16(obj + 36));
        ST16(obj + 18, LD16(obj + 18) + LD16(obj + 38));
        ST16(obj + 38, 0);
        ST16(obj + 36, 0);
        GCALL2(0x0606AAC8, obj, 3);
        ST16(obj + 72, i ? -32 : 32);
        i++;
    } while (AGAIN(i < 2));
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

void f0603AD82(void)
{
    GCALL1(0x0600996A, 64);
    ST32(0x060D7E48, 0x0603AD96);
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

void f0603B224(void)
{
    GCALL1(0x060692DC, LDU16(0x060D7E3A));
    GCALL1(0x060692DC, LDU16(0x060D7E3C));
    GCALL1(0x060692DC, LDU16(0x060D7E3E));
    GCALL1(0x060692DC, LDU16(0x060D7E40));
    GJUMP1(0x06022EDA, 31);
}

void f0603B252(unsigned char value)
{
    ST8(0x060C1734, value);
}

void f0603B258(short v)
{
    ST16(0x060C1736, v);
}

void f0603B25E(short from, short to)
{
    gaddr src, dst;
    short drop, w68, w70;
    int mag, scale;

    GCALL2(0x0600A3D8, from, to);
    src = OBJ(from);
    drop = LD16(src + 38);
    w68 = LD16(src + 68);
    w70 = LD16(src + 70);
    dst = OBJ(to);
    ST16(dst + 36, -drop);
    ST16(dst + 38, 0);
    mag = drop >= -128 ? drop * 2 + 0x100 : 0;
    scale = HELPER((LDU16(0x060C1736) * (short)mag) >> 8);
    ST16(dst + 68, HELPER((w68 * (short)scale) >> 8));
    ST16(dst + 70, HELPER((w70 * (short)scale) >> 8));
}

void f0603B32E(void)
{
    int base;

    GCALL2(0x0600A3DC, LDU16(0x060D7E38), LDU16(0x060D7E3A));
    GCALL2(0x0600A3DC, LDU16(0x060D7E38), LDU16(0x060D7E3C));
    GCALL2(0x0600A3DC, LDU16(0x060D7E38), LDU16(0x060D7E3E));
    GCALL2(0x0603B25E, LD16(0x060D7E38), LD16(0x060D7E40));
    GCALL1(0x0606948A, TGET(h8));
    base = LD16(OBJ(TGET(h8)) + 4);
    ST16(OBJ(TGET(h10)) + 4, base + 5);
    ST16(OBJ(TGET(h12)) + 4, base + 5);
    ST16(OBJ(TGET(h14)) + 4, base + 7);
    ST16(OBJ(TGET(h16)) + 4, 10);
}

void f0603B650(void)
{
    ST32(0x060D7E30, 0x0603B4B2);
}

void f0603B658(void)
{
    ST32(0x060D7E30, 0x0603B56C);
}

static int clamp(int d, int limit)
{
    int mag = (short)d >= 0 ? (short)d : -(short)d;

    if (mag > limit)
        return (short)DIVS((short)d, mag) * (short)limit;
    return d;
}

void f0603B660(void)
{
    gaddr obj;
    int dx, dy, dz, limit;

    GCALL1(0x0600C9AA, (short)TGET(h18));
    GCALL2(0x0600CA32, LDU16(0x060D7EB4), LDU16(0x060D7EB6));
    obj = LD32(TASK_OBJ);
    dx = LD16(0x060D7E88) - LD16(obj + 16);
    dy = LD16(0x060D7E8A) - LD16(obj + 18);
    limit = LD8(0x060C1734) & 255;
    dz = (short)TGET(h20) - LD16(obj + 38);
    dx = clamp(dx, limit);
    dy = clamp(dy, limit);
    dz = clamp(dz, limit);
    ST16(obj + 16, LD16(obj + 16) + dx);
    ST16(obj + 18, LD16(obj + 18) + dy);
    ST16(obj + 38, LD16(obj + 38) + DIVS((short)dz, (LD32(TICK) & 1) ? 1 : 2));
    GCALL0(0x0603B32E);
    obj = LD32(TASK_OBJ);
    if (LD16(obj + 16) == LD16(0x060D7E88) && LD16(obj + 18) == LD16(0x060D7E8A) && LD16(obj + 38) == (short)TGET(h20))
        TSET(fn, 0x0603DDA6);
}

void f0603B7EA(short a, short b, short c)
{
    ST16(0x060D7E42, GCALL2(0x0600C950, a, b));
    ST16(0x060D7E44, c);
    ST32(0x060D7E30, 0x0603B660);
}

int f0603BBD6(void)
{
    return LD32(0x060D7E30) == 0x0603DDA6 ? -1 : 0;
}

void f0603BE9E(int i)
{
    ST16(SLOTS + 16 + (short)(i * 24), 1);
}

void f0603C0B0(void)
{
    switch ((short)GCALL2(0x0604D47C, (unsigned char)LD8(0x060C029C), (unsigned char)LD8(0x060C029D))) {
    case 1:
        GCALL1(0x0600996A, 65);
        break;
    case 2:
        GCALL1(0x0600996A, 93);
        break;
    case 3:
        GCALL1(0x0600996A, 127);
        break;
    case 5:
        GCALL1(0x0600996A, 164);
        break;
    }
}

void f0603C0FA(void)
{
    switch ((short)GCALL2(0x0604D47C, (unsigned char)LD8(0x060C029C), (unsigned char)LD8(0x060C029D))) {
    case 1:
        GCALL1(0x0600996A, 77);
        break;
    case 2:
        GCALL1(0x0600996A, 100);
        break;
    case 3:
        GCALL1(0x0600996A, 142);
        break;
    case 4:
        GCALL1(0x0600996A, 180);
        break;
    case 5:
        GCALL1(0x0600996A, 185);
        break;
    case 6:
        GCALL1(0x0600996A, 203);
        break;
    case 7:
        GCALL1(0x0600996A, 237);
        break;
    }
}

void f0603C7BC(void)
{
    if (GCALL2(0x06022F1C, 0, 0x0603DDA6) >= 0) {
        TSET(h6, 0);
        TSET(h10, 0);
        TSET(h12, 0);
        TSET(h14, 0);
        TSET(h18, 0);
        TSET(h20, 0);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603C7EE(void)
{
}

void f0603C7F2(void)
{
    int kind = GCALL2(0x0604D47C, (unsigned char)LD8(0x060C029C), (unsigned char)LD8(0x060C029D)) & 0xFFFF;

    if (kind == 7)
        return;
    GCALL1(0x0600996A, 66);
    if (kind == 6)
        GCALL1(0x0600996A, 205);
    if (kind == 4)
        GCALL1(0x0600996A, 184);
}

void f0603C990(short x)
{
    GCALL0(0x0603C7F2);
    ST32(0x060D7B48, 0x0603C83A);
    ST16(0x060D7B56, 0);
    ST16(0x060D7B5A, x);
    ST16(0x060D7B5C, 0);
}

void f0603C9B6(unsigned short v)
{
    ST32(SLOTS, 0x0603C83A);
    ST16(SLOTS + 20, v);
    ST16(SLOTS + 18, 0);
}

void f0603C9C6(void)
{
    GCALL2(0x0600D5EA, -LD16(0x060D7B52), -LD16(0x060D7B54));
    ST16(0x060D7B52, 0);
    ST16(0x060D7B54, 0);
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

void f0603CEAE(void)
{
    GCALL1(0x060692DC, LDU16(0x060D7E22));
    GJUMP1(0x06022EDA, 30);
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

void f0603D374(void)
{
    GCALL1(0x060692DC, LDU16(0x060D7E0A));
    GCALL1(0x060692DC, LDU16(0x060D7E0C));
    GCALL1(0x060692DC, LDU16(0x060D7E0E));
    GJUMP1(0x06022EDA, 29);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603DDA6(void)
{
}

int f0603DEEC(void)
{
    int w = LDU16(0x060D7E68);

    if (!(w & 1)) {
        w = 0x0603DF02;
        SET(Slot24, (REF(Slot24))LD32(0x060D7E60), fn, 0x0603DF02);
    }
    return w;
}

int f0603DF02(void)
{
    gaddr obj = OBJ(TGET(h8));
    int left;
    int flags;

    TSET(h14, TGET(h14) + 0x100);
    ST16(obj + 16, LD16(obj + 16) - (TGET(h14) >> 8));
    TSET(h14, TGET(h14) & 255);
    if (LD16(obj + 16) == 0x154)
        GCALL1(0x0600996A, 52);
    if (TGET(h12)) {
        if (TGET(h12) == 0x258 && (LDU16(0x060D7E68) & 0x1052))
            TSET(fn, 0x0603DDA6);
        left = (short)TGET(h12) - 1;
        TSET(h12, left);
        return left;
    }
    TSET(h12, 0x258);
    TSET(h4, 0xE10);
    GCALL3(0x0600D0E4, TGET(h8), 28, 40);
    ST16(obj + 18, LD16(obj + 18) - 8);
    ST16(obj + 36, 0);
    ST16(obj + 38, -15);
    flags = LDU16(0x060D7E68);
    if (flags & 2)
        flags = GCALL0(0x06022F14);
    if (!LD8(0x060C029D))
        return flags;
    return GJUMP0(0x06022F14);
}

int f0603E212(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 4);
    gaddr o = OBJS + (unsigned short)(GET(Slot24, s, obj) * 84);

    if (!LD16(o + 10) || LDU16(o + 60) >= 0xFF00)
        return -1;
    return 0;
}

int f0603E4CC(int base)
{
    return base + 70;
}

int f0603E4D2(int p)
{
    return p + 82;
}

int f0603E4F6(int base)
{
    return base + 78;
}

int f0603E888(unsigned short x, unsigned short y)
{
    if (x < 32 || x > 40 || y < 19 || y > 25)
        return 0;
    return LD8(0x060B5E0A + (y - 19) * 9 + (x - 32)) & 255;
}

int f0603E9B6(void)
{
    return LD16(0x060DF97A) != 0;
}

int f0603ECFE(void)
{
    gaddr obj;
    int v;

    GCALL1(0x0606948A, TGET(h8));
    obj = LD32(TASK_OBJ);
    v = LD16(obj + 4) + 1;
    ST16(obj + 4, v);
    return v;
}

void f0603ED78(int n)
{
    GJUMP1(0x06022EDA, n);
}

int f0603EE1E(short slot)
{
    int obj = OBJ(LD16(SLOT(slot) + 8));

    if (!LD16(obj + 10))
        return -1;
    return LDU16(obj + 60) >= 0xFF00 ? -1 : 0;
}

void f0603EFDA(void)
{
    GJUMP1(0x0603C990, 128);
}

int f0603F380(short slot)
{
    unsigned short obj = LD16(SLOT(slot) + 8);

    ST16(OBJ(obj) + 38, 0);
    return GJUMP2(0x06069546, obj, 0);
}

int f0603F642(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        int obj = OBJ(LDU16(0x060D7BF8 + i * 2));

        ST16(obj + 42, LDU16(obj + 42) | 0x400);
    }
    ST16(OBJ(LDU16(0x060D7C00)) + 4, 9);
    return 9;
}

int f0603FCCC(void)
{
    gaddr obj = OBJ(TGET(h8));

    ST16(obj + 42, LD16(obj + 42) | 0x400);
    obj = OBJ(TGET(h10));
    ST16(obj + 42, LD16(obj + 42) | 0x400);
    return 42;
}
