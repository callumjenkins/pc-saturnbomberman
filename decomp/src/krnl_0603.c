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

int f06030928(void)
{
    int result = GCALL0(0x0602E88E);
    gaddr list;

    if (result) {
        list = 0x060C0FF4;
        do {
            int id = LDU16(list);
            gaddr obj;

            GCALL2(0x0606AB08, id, 3);
            obj = OBJ(id);
            list += 2;
            ST16(obj + 70, 0);
            ST16(obj + 68, 0);
        } while (AGAIN(list < 0x060C0FFC));
        result = 68;
    }
    return result;
}

int f06030F0C(short id, short which)
{
    gaddr p;
    gaddr data;
    int height;
    int stride;
    int count;
    int lo;
    int hi = 0;
    int run = 0;

    GCALL2(0x06008A6A, 9, 0);
    p = GCALL2(0x06008ABA, which, 9) + 14;
    height = LDU8(p + 1);
    stride = (short)((DIVS(LDU8(p) + 7, 8) & 0xFFFF) * height);
    count = LDU8(p + 3);
    p += 4;
    data = p + count * 4;
    lo = height;
    if (count > 0) {
        do {
            lo = LDU8(p) | (LDU8(p + 1) << 8);
            hi = LDU8(p + 2) | (LDU8(p + 3) << 8);
            p += 4;
            if ((unsigned short)id < lo)
                return 0;
            if ((unsigned short)id <= hi)
                break;
            run += hi - lo + 1;
            count--;
        } while (AGAIN((count & 255) > 0));
    }
    if ((unsigned short)id > hi)
        return 0;
    run += id - lo;
    return data + (unsigned int)(run & 0xFFFF) * (unsigned int)(stride & 0xFFFF);
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

void f060311CC(int unit, unsigned int vram, short tile)
{
    gaddr dst = GCALL3(0x0600ABA4, unit, LD32(0x060DFE0C), LD32(0x060DFE10));
    int pos = (vram & 0x000FFFFF) >> 5;

    ST16(dst, tile);
    ST16(dst + 2, pos);
    ST16(dst + 4, tile);
    ST16(dst + 6, pos + 2);
    ST16(dst + 256, tile);
    ST16(dst + 258, pos + 1);
    ST16(dst + 260, tile);
    ST16(dst + 262, pos + 3);
    ST32(0x060DFE0C, LD32(0x060DFE0C) + 2);
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

int f060319AC(unsigned int key, int a, int b, int c)
{
    FRAME(sp, 32);
    int n = 1, cur = 0, seen = 0;

    if (key == 0)
        return 0xFFFF;
    do {
        if (LD32(KEYED(n) + 4) == 0)
            break;
    } while (AGAIN(++n < 30));
    if (n == 30)
        return 0xFFFF;
    while (seen < LDU8(0x060C1244)) {
        POLL();
        if (key == LD32(KEYED(cur) + 4))
            break;
        if (key >= (unsigned int)LD32(KEYED(cur) + 4)) {
            cur = LDU8(KEYED(cur) + 1);
            seen++;
            continue;
        }
        ST8(KEYED(LDU8(KEYED(cur))) + 1, n);
        ST8(KEYED(n), LDU8(KEYED(cur)));
        ST8(KEYED(cur), n);
        ST8(KEYED(n) + 1, cur);
        ST32(KEYED(n) + 4, key);
        cur = n;
        ST8(0x060C1244, LD8(0x060C1244) + 1);
        break;
    }
    if (seen == LDU8(0x060C1244)) {
        int tail = LDU8(KEYED(0));

        ST8(KEYED(tail) + 1, n);
        ST8(KEYED(0), n);
        ST8(KEYED(n), tail);
        ST8(KEYED(n) + 1, 0);
        ST32(KEYED(n) + 4, key);
        cur = n;
        ST8(0x060C1244, LD8(0x060C1244) + 1);
    }
    ST8(KEYED(cur) + 2, a);
    ST8(KEYED(cur) + 3, b);
    ST32(KEYED(cur) + 8, c);
    ST16(KEYED(cur) + 14, LD16(sp + 2) | 0x1000);
    return cur;
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

int f06031B28(unsigned char i)
{
    int next;

    for (;;) {
        next = LD8(KEYED(i));
        if (LD32(KEYED(next & 255) + 4) != 0 && !(LDU16(KEYED(next & 255) + 14) & 48))
            return next;
        i = next;
        POLL();
    }
}

int f06031B58(unsigned char i)
{
    int prev;

    for (;;) {
        prev = LD8(KEYED(i) + 1);
        if (LD32(KEYED(prev & 255) + 4) != 0 && !(LDU16(KEYED(prev & 255) + 14) & 48))
            return prev;
        i = prev;
        POLL();
    }
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

int f06031BD2(int key)
{
    return LD16(KEYED(GCALL1(0x06031AE2, key) & 0xFFFF) + 14) & 0xF00;
}

int f06031BEA(int key, short bits)
{
    int offset = (GCALL1(0x06031AE2, key) & 0xFFFF) << 4;
    gaddr flags = 0x060C105A + offset;

    ST16(flags, (LDU16(flags) & 0xF0FF) | bits);
    return offset;
}

int f06031C12(int key, short bits)
{
    gaddr flags = 0x060C105A + ((GCALL1(0x06031AE2, key) & 0xFFFF) << 4);
    int old = LD16(flags);

    ST16(flags, (old & 0xFFCF) | bits);
    return old & 48;
}

int f06031C3C(int handle, unsigned int key)
{
    int id;
    gaddr ent;
    int prev;
    int next;
    int i = 0;
    int cur = 0;

    if (handle == 0)
        return 0;
    id = GCALL1(0x06031AE2, handle) & 0xFFFF;
    if (id == 0)
        return 0;
    ent = KEYED(id);
    prev = LDU8(ent);
    next = LDU8(ent + 1);
    ST8(KEYED(prev) + 1, next);
    ST8(KEYED(next), prev);
    ST32(ent + 4, 0);
    ST8(ent + 1, 0);
    ST8(ent, 0);
    ST8(0x060C1244, LD8(0x060C1244) - 1);
    if (key == 0)
        return 0;
    while (i < LDU8(0x060C1244)) {
        gaddr node = KEYED(cur);

        POLL();
        if (key == LD32(node + 4))
            return 0;
        if (key < (unsigned int)LD32(node + 4)) {
            prev = LDU8(node);
            ST8(KEYED(prev) + 1, id);
            ST8(node, id);
            ST8(ent, prev);
            ST8(ent + 1, cur);
            ST32(ent + 4, key);
            ST8(0x060C1244, LD8(0x060C1244) + 1);
            return key;
        }
        cur = LDU8(node + 1);
        i++;
    }
    prev = LDU8(KEYED(0));
    ST8(KEYED(prev) + 1, id);
    ST8(KEYED(0), id);
    ST8(ent, prev);
    ST8(ent + 1, 0);
    ST32(ent + 4, key);
    ST8(0x060C1244, LD8(0x060C1244) + 1);
    return key;
}

int f06032034(int handle, signed char a, signed char b, signed char c)
{
    FRAME(sp, 0);
    int arg5 = LD32(sp);
    gaddr ent = KEYED(GCALL1(0x06031AE2, handle) & 0xFFFF);

    ST8(ent + 2, a);
    ST8(ent + 3, b);
    ST8(ent + 12, c);
    ST8(ent + 13, arg5);
    return arg5;
}

void f0603214E(unsigned char i, unsigned char value)
{
    gaddr e = KEYED(i);
    gaddr cell;
    int step;
    int cols;
    int rows;
    int fill;
    int mask;
    int n;
    gaddr p;

    if ((LDU16(e + 14) & 48) == 48)
        return;
    cell = GCALL3(0x0600ABA4, 32, LDU8(e + 2), LDU8(e + 3));
    step = (unsigned short)GCALL1(0x0600AA8A, 32) == 1 ? 2 : 4;
    cols = LD8(e + 12);
    rows = LD8(e + 13);
    if ((unsigned short)GCALL1(0x0600AA8A, 32) == 1) {
        fill = value << 12;
        mask = 0xFFFF0FFF;
    } else {
        mask = -128;
        fill = value & 127;
    }
    while ((unsigned int)rows > 0) {
        POLL();
        n = cols;
        p = cell;
        if ((unsigned int)n > 0) {
            do {
                n--;
                ST16(p, (LDU16(p) & mask) | fill);
                p += step;
            } while (AGAIN((unsigned int)n > 0));
        }
        cell += step << 6;
        rows--;
    }
}

int f060329A0(void)
{
    int i = 0;
    int result;

    GCALL1(0x06008A96, 0);
    do {
        GCALL1(0x06068CC4, i + 238);
        GCALL1(0x06068CC4, i + 245);
        GCALL1(0x06068CC4, i + 242);
        result = GCALL1(0x06068CC4, i + 240);
        i += 34;
    } while (AGAIN(i < 0x198));
    return result;
}
/* The unit `back` places before the write position in the ring, as a byte, halfword or word. */
static int ring8(REF(Stream) s, int back)
{
    return LDU8(((ST_GET(s, pos) - back) & ST_GET(s, mask)) + ST_GET(s, ring));
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

int f06033148(void)
{
    return GJUMP0(0x06033152);
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

void f060335B8(void)
{
    gaddr p = POINTS + (short)(GCALL6(0x06035D36, 9, 0, 1, 0, 0, 0) * 24);
    int next;

    ST32(p + 12, LD32(p + 12) | 32);
    GCALL6(0x06035D36, 1, 1, 255, 2, 3, 0x060337BE);
    if ((LD32(0x060C1048) & 48) == 32) {
        GCALL6(0x06035D36, 1, 2, 255, 2, 6, 0x060337BE);
        next = 9;
    } else {
        next = 6;
    }
    GCALL6(0x06035D36, 1, 3, 255, 2, next, 0x060337BE);
    GCALL6(0x06035D36, 1, 4, 255, 2, next + 3, 0x060337BE);
    GCALL6(0x06035D36, 1, 5, 255, 2, next + 6, 0x060337BE);
    GCALL6(0x06035D36, 1, 10, 255, 2, 20, 0);
    GCALL6(0x06035D36, 1, 255, 255, 2, 23, 0x060337BE);
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

void f06033D22(void)
{
    int first = GCALL3(0x0603666E, 101, 1, 255);
    gaddr o1 = OBJ(LDU16(POINTS + (short)(first * 24) + 18));
    int second = GCALL3(0x0603666E, 101, 2, 255);
    gaddr o2 = OBJ(LDU16(POINTS + (short)(second * 24) + 18));
    int v;

    if (LDU16(POINTS + (short)(LDU8(0x060C122C) * 24)) == 101) {
        if (LDU16(o1 + 70) < 256) {
            v = LD16(o1 + 70) + 32;
            ST16(o1 + 70, v);
            ST16(o2 + 70, v);
        }
    } else if (LDU16(o1 + 70) > 0) {
        v = LD16(o1 + 70) - 32;
        ST16(o1 + 70, v);
        ST16(o2 + 70, v);
    }
    GJUMP0(0x06033C12);
}

static int ring16(REF(Stream) s, int back)
{
    return LDU16((((ST_GET(s, pos) - back) & ST_GET(s, mask)) << 1) + ST_GET(s, ring));
}

static int ring32(REF(Stream) s, int back)
{
    return LD32((((ST_GET(s, pos) - back) & ST_GET(s, mask)) << 2) + ST_GET(s, ring));
}

int f06033DF0(REF(Stream) s)
{
    gaddr p = ST_GET(s, in);

    ST_SET(s, in, p + 1);
    return LDU8(p);
}

void f06033DFE(REF(Stream) s)
{
    gaddr p = ST_GET(s, out) + 1;

    ST_SET(s, out, p);
    ST8(p - 1, ST_GET(s, value));
}

void f06033E0C(REF(Stream) s)
{
    int p = ST_GET(s, pos) + 1;

    ST_SET(s, pos, p);
    ST8(p - 1 + ST_GET(s, ring), ST_GET(s, value));
    ST_SET(s, pos, ST_GET(s, pos) & ST_GET(s, mask));
}

int f06033E26(REF(Stream) s)
{
    return ring8(s, 1);
}

int f06033E36(REF(Stream) s)
{
    return ring8(s, 1) + 1;
}

int f06033E48(REF(Stream) s)
{
    return ring8(s, 1) + 2;
}

int f06033E5A(REF(Stream) s)
{
    return ring8(s, 1) + 4;
}

int f06033E6C(REF(Stream) s)
{
    return ring8(s, 1) + 8;
}

int f06033E7E(REF(Stream) s)
{
    return ring8(s, 1) + 16;
}

int f06033E90(REF(Stream) s)
{
    return ring8(s, 1) + 32;
}

int f06033EA2(REF(Stream) s)
{
    return ring8(s, 1) - 1;
}

int f06033EB4(REF(Stream) s)
{
    return ring8(s, 1) - 2;
}

int f06033EC6(REF(Stream) s)
{
    return ring8(s, 1) - 4;
}

int f06033ED8(REF(Stream) s)
{
    return ring8(s, 1) - 8;
}

int f06033EEA(REF(Stream) s)
{
    return ring8(s, 1) - 16;
}

int f06033EFC(REF(Stream) s)
{
    return ring8(s, 1) - 32;
}

int f06033F0E(REF(Stream) s)
{
    return ring8(s, 2);
}

int f06033F1E(REF(Stream) s)
{
    return ring8(s, 4);
}

int f06033F2E(REF(Stream) s)
{
    return ring8(s, 8);
}

int f06033F3E(REF(Stream) s)
{
    return ring8(s, 16);
}

int f06033F4E(REF(Stream) s)
{
    return ring8(s, 32);
}

int f06033F5E(REF(Stream) s)
{
    return ring8(s, 64);
}

int f06033F6E(REF(Stream) s)
{
    gaddr p = ST_GET(s, in);

    ST_SET(s, in, ST_GET(s, in) + 2);
    return LDU8(p) << 8 | LDU8(p + 1);
}

void f06033F88(REF(Stream) s)
{
    gaddr p = ST_GET(s, out) + 1;

    ST_SET(s, out, p);
    ST8(p - 1, (unsigned int)ST_GET(s, value) >> 8);
    p = ST_GET(s, out) + 1;
    ST_SET(s, out, p);
    ST8(p - 1, ST_GET(s, value));
}

void f06033FA4(REF(Stream) s)
{
    int p = ST_GET(s, pos) + 1;

    ST_SET(s, pos, p);
    ST16((p - 1) * 2 + ST_GET(s, ring), ST_GET(s, value));
    ST_SET(s, pos, ST_GET(s, pos) & ST_GET(s, mask));
}

int f06033FC0(REF(Stream) s)
{
    return ring16(s, 1);
}

int f06033FD2(REF(Stream) s)
{
    return ring16(s, 1) + 1;
}

int f06033FE6(REF(Stream) s)
{
    return ring16(s, 1) + 2;
}

int f06033FFA(REF(Stream) s)
{
    return ring16(s, 1) + 4;
}

int f0603400E(REF(Stream) s)
{
    return ring16(s, 1) + 8;
}

int f06034022(REF(Stream) s)
{
    return LDU16(((ST_GET(s, pos) - 1) & ST_GET(s, mask)) * 2 + ST_GET(s, ring)) + 16;
}

int f06034036(REF(Stream) s)
{
    return ring16(s, 1) + 32;
}

int f0603404A(REF(Stream) s)
{
    return ring16(s, 1) - 1;
}

int f0603405E(REF(Stream) s)
{
    return ring16(s, 1) - 2;
}

int f06034072(REF(Stream) s)
{
    return LDU16(((ST_GET(s, pos) - 1) & ST_GET(s, mask)) * 2 + ST_GET(s, ring)) - 4;
}

int f06034086(REF(Stream) s)
{
    return ring16(s, 1) - 8;
}

int f0603409A(REF(Stream) s)
{
    return LDU16(((ST_GET(s, pos) - 1) & ST_GET(s, mask)) * 2 + ST_GET(s, ring)) - 16;
}

int f060340AE(REF(Stream) s)
{
    return LDU16(((ST_GET(s, pos) - 1) & ST_GET(s, mask)) * 2 + ST_GET(s, ring)) - 32;
}

int f060340C2(REF(Stream) s)
{
    return ring16(s, 2);
}

int f060340D4(REF(Stream) s)
{
    return ring16(s, 4);
}

int f060340E6(REF(Stream) s)
{
    return ring16(s, 8);
}

int f060340F8(REF(Stream) s)
{
    return ring16(s, 16);
}

int f0603410A(REF(Stream) s)
{
    return ring16(s, 32);
}

int f0603411C(REF(Stream) s)
{
    return ring16(s, 64);
}

int f0603412E(REF(Stream) s)
{
    gaddr p = ST_GET(s, in);

    ST_SET(s, in, ST_GET(s, in) + 4);
    return LDU8(p) << 24 | LDU8(p + 1) << 16 | LDU8(p + 2) << 8 | LDU8(p + 3);
}

void f0603415A(REF(Stream) s)
{
    gaddr p = ST_GET(s, out) + 1;

    ST_SET(s, out, p);
    ST8(p - 1, (unsigned int)ST_GET(s, value) >> 24);
    p = ST_GET(s, out) + 1;
    ST_SET(s, out, p);
    ST8(p - 1, (unsigned int)ST_GET(s, value) >> 16);
    p = ST_GET(s, out) + 1;
    ST_SET(s, out, p);
    ST8(p - 1, (unsigned int)ST_GET(s, value) >> 8);
    p = ST_GET(s, out) + 1;
    ST_SET(s, out, p);
    ST8(p - 1, ST_GET(s, value));
}

void f06034194(REF(Stream) s)
{
    int p = ST_GET(s, pos) + 1;

    ST_SET(s, pos, p);
    ST32((p - 1) * 4 + ST_GET(s, ring), ST_GET(s, value));
    ST_SET(s, pos, ST_GET(s, pos) & ST_GET(s, mask));
}

int f060341B0(REF(Stream) s)
{
    return ring32(s, 1);
}

int f060341C0(REF(Stream) s)
{
    return ring32(s, 1) + 1;
}

int f060341D2(REF(Stream) s)
{
    return ring32(s, 1) + 2;
}

int f060341E4(REF(Stream) s)
{
    return ring32(s, 1) + 4;
}

int f060341F6(REF(Stream) s)
{
    return ring32(s, 1) + 8;
}

int f06034208(REF(Stream) s)
{
    return ring32(s, 1) + 16;
}

int f0603421A(REF(Stream) s)
{
    return LD32(((ST_GET(s, pos) - 1) & ST_GET(s, mask)) * 4 + ST_GET(s, ring)) + 32;
}

int f0603422C(REF(Stream) s)
{
    return ring32(s, 1) - 1;
}

int f0603423E(REF(Stream) s)
{
    return ring32(s, 1) - 2;
}

int f06034250(REF(Stream) s)
{
    return ring32(s, 1) - 4;
}

int f06034262(REF(Stream) s)
{
    return ring32(s, 1) - 8;
}

int f06034274(REF(Stream) s)
{
    return LD32(((ST_GET(s, pos) - 1) & ST_GET(s, mask)) * 4 + ST_GET(s, ring)) - 16;
}

int f06034286(REF(Stream) s)
{
    return LD32(((ST_GET(s, pos) - 1) & ST_GET(s, mask)) * 4 + ST_GET(s, ring)) - 32;
}

int f06034298(REF(Stream) s)
{
    return ring32(s, 2);
}

int f060342A8(REF(Stream) s)
{
    return ring32(s, 4);
}

int f060342B8(REF(Stream) s)
{
    return ring32(s, 8);
}

int f060342C8(REF(Stream) s)
{
    return ring32(s, 16);
}

int f060342D8(REF(Stream) s)
{
    return ring32(s, 32);
}

int f060342E8(REF(Stream) s)
{
    return ring32(s, 64);
}
void f06034FC4(void)
{
    int b = SP(b1);

    SP_SET(count, ((b >> 4) - (b & 15)) * 3);
    SP_STATE(2);
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

void f0603461C(gaddr p)
{
    gaddr src;
    gaddr out;
    int i;

    ST8(0x060C146F, LD8(p));
    p++;
    if (LD8(0x060C146F) == 0) {
        ST32(0x060C15FC, p);
        return;
    }
    ST8(0x060C146E, LD8(p));
    p++;
    GCALL0(0x060343F8);
    src = GCALL0(0x0603441A);
    ST32(0x060C1570, LD32(src));
    out = 0x060C1570 + 4;
    i = 1;
    while (i < SHL(1, LDU8(0x060C146F))) {
        POLL();
        i++;
        ST32(out, LD32(src + (LD8(p) << 2)));
        p++;
        out += 4;
    }
    ST32(0x060C15F8, LD32(0x060B53B4 + LDU8(0x060C146F) * 4));
    GCALL0(0x060343E6);
    ST32(0x060C15FC, p);
    ST32(0x060C15FC + 44, 0);
    ST8(0x060C1468, 0);
    ST16(0x060C146C, 0);
    ST16(0x060C146A, 0);
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

int f06034B84(gaddr out)
{
    gaddr p;
    int i = 0;
    int result;

    p = out;
    do {
        ST16(p, 0);
        p += 2;
    } while (AGAIN(p < out + 10));
    do {
        int kind = LDU8(0x060C0640 + i);

        if (kind & 3) {
            gaddr slot = out + (kind >> 2) * 2;

            ST16(slot, LD16(slot) + GCALL1(0x06034A8C, i));
        }
    } while (AGAIN(++i < 10));
    i = 0;
    do {
        result = (short)GCALL1(0x0602C430, i);
        if (result == 0) {
            result = i * 2;
            ST16(out + i * 2, -30000);
        }
    } while (AGAIN(++i < 5));
    return result;
}

int f06034C02(void)
{
    FRAME(sp, 20);
    gaddr buf = sp - 20;
    int i = 0;

    GCALL1(0x06034C3A, buf);
    while (LDU8(buf + (i & 0xFFFF)) != 1) {
        i++;
        if ((i & 0xFFFF) >= 10)
            break;
        POLL();
    }
    return (i & 0xFFFF) >= 10 ? 0xFFFF : i;
}

void f06034C3A(gaddr dst)
{
    FRAME(sp, 88);
    gaddr table = sp - 88 + 40;
    gaddr copy = sp - 88 + 20;
    gaddr small = sp - 88;
    int i = 0;

    if ((LD32(0x060C1048) & 0xC00) == 0x400) {
        GCALL1(0x06034B24, table);
        do {
            if (LDU8(0x060C0640 + i) & 3) {
                ST16(copy + i * 2, LD16(0x060C065E + i * 2));
            } else {
                ST16(0x060C065E + i * 2, 0);
                ST16(copy + i * 2, 0);
            }
            i++;
        } while (AGAIN(i < 10));
        GCALL4(0x06034D90, 10, dst, copy, table);
    } else {
        GCALL1(0x06034D20, small);
        do {
            if (LDU8(0x060C0640 + i) & 3)
                ST8(dst + i, LD8(small + (LDU8(0x060C0640 + i) >> 2)));
            else
                ST8(dst + i, 6);
            i++;
        } while (AGAIN(i < 10));
    }
}

void f06034D20(int arg)
{
    FRAME(sp, 80);
    gaddr plain = sp - 64;
    gaddr copy = sp - 76;
    int i = 0;

    GCALL1(0x06034B84, plain);
    do {
        if ((short)GCALL1(0x0602C430, i) == 0) {
            ST16(plain + i * 2, -30000);
            ST16(0x060C0672 + i * 2, 0);
        }
        ST16(copy + i * 2, LD16(0x060C0672 + i * 2));
    } while (AGAIN(++i < 5));
    GCALL4(0x06034D90, 5, arg, copy, plain);
}

void f06034D90(unsigned char count, gaddr rank, gaddr key, gaddr tie)
{
    FRAME(sp, 68);
    gaddr order = sp - 40;
    int i, j, place;
    unsigned short last_key;
    short last_tie;

    if (count > 0) {
        i = 0;
        do {
            ST8(order + i, i);
        } while (AGAIN(++i < count));
    }
    for (i = 0; i < count; i++) {
        POLL();
        j = i + 1;
        if (j < count) {
            do {
                int swap;

                if (LDU16(key + i * 2) == LDU16(key + j * 2))
                    swap = LD16(tie + i * 2) < LD16(tie + j * 2);
                else
                    swap = LDU16(key + i * 2) < LDU16(key + j * 2);
                if (swap) {
                    unsigned short k = LDU16(key + i * 2);
                    short t;
                    unsigned char o;

                    ST16(key + i * 2, LDU16(key + j * 2));
                    ST16(key + j * 2, k);
                    t = LD16(tie + i * 2);
                    ST16(tie + i * 2, LD16(tie + j * 2));
                    ST16(tie + j * 2, t);
                    o = LDU8(order + i);
                    ST8(order + i, LDU8(order + j));
                    ST8(order + j, o);
                }
            } while (AGAIN(++j < count));
        }
    }
    place = 1;
    last_key = 0;
    last_tie = -30000;
    if (count > 0) {
        i = 0;
        do {
            if (last_key != LDU16(key + i * 2))
                place = i + 1;
            else if (last_tie != LD16(tie + i * 2))
                place = i + 1;
            last_key = LDU16(key + i * 2);
            last_tie = LD16(tie + i * 2);
            ST8(rank + LDU8(order + i), place);
        } while (AGAIN(++i < count));
    }
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

void f06034FF6(void)
{
    SP_SET(count, 0);
    SP_STATE(2);
}

void f060350AC(void)
{
    if (!SP(count))
        SP_STATE(3);
    else
        SP_SET(count, SP(count) - 1);
}

void f060350CA(void)
{
    int b = SP(b1);
    int hi = b >> 4;
    int lo = b & 15;
    int t = SP(count);
    gaddr obj = OBJ(SP(obj));
    int w8;
    int x, y, d, drift, rise;

    if (t > 30) {
        SP_SET(count, lo * 3 + 20);
        SP_STATE(4);
        return;
    }
    w8 = SP(w8);
    rise = DIVS(((t - 15) * (t - 15) - 225) * w8, 128);
    drift = ((hi - lo * 2) * w8) >> 1;
    d = DIVS(t * drift, 30);
    x = LD16(obj + 16) + d;
    y = rise + LD16(obj + 18);
    ST16(obj + 20, x);
    ST16(obj + 24, SP(b6) + x - 1);
    ST16(obj + 22, y);
    ST16(obj + 26, SP(b7) + y - 1);
    SP_SET(count, SP(count) + 1);
}

void f060351A4(void)
{
    int b = SP(b1);
    int t = SP(count);
    gaddr obj = OBJ(SP(obj));
    int hi = b >> 4;
    int lo = b & 15;
    int speed = hi - lo * 2;
    int ang, d, x, y;

    if (t > 30) {
        x = (speed * SP(w8) >> 1) + LD16(obj + 16);
        y = LD16(obj + 18);
        SP_SET(count, 20);
        SP_STATE(4);
    } else {
        ang = (int)0xFF4C0000 + MODS(t * 24, 0x168) * 65536;
        d = DIVS(speed * SP(w8) * t, 60);
        x = LD16(obj + 16);
        x -= GCALL2(0x060980B4, GCALL1(0x0609816C, ang), d);
        y = LD16(obj + 18);
        y += GCALL2(0x060980B4, GCALL1(0x0609812C, ang), d);
        SP_SET(count, SP(count) + 1);
    }
    ST16(obj + 20, x);
    ST16(obj + 24, SP(b6) + x - 1);
    ST16(obj + 22, y);
    ST16(obj + 26, SP(b7) + y - 1);
}

void f060353A2(void)
{
    if (!SP(count))
        SP_STATE(5);
    else
        SP_SET(count, SP(count) - 1);
}

void f060353C0(void)
{
    gaddr obj;

    if (SP(count) > 30) {
        SP_STATE(6);
        return;
    }
    obj = OBJ(SP(obj));
    ST16(obj + 22, LD16(obj + 26) - DIVS((SP(b7) - 1) * (30 - SP(count)), 30));
    SP_SET(count, SP(count) + 1);
}

void f0603541C(void)
{
    gaddr obj;
    int step;

    if (SP(count) > 15) {
        SP_STATE(6);
        return;
    }
    obj = OBJ(SP(obj));
    step = DIVS(15 - SP(count), DIVS(35, SP(b7)));
    ST16(obj + 26, LD16(obj + 26) - step);
    ST16(obj + 20, LD16(obj + 20) + DIVS(SP(w8), 4));
    ST16(obj + 24, LD16(obj + 24) + DIVS(SP(w8), 4));
    ST16(obj + 22, LD16(obj + 26) - DIVS(SP(b7) * (15 - SP(count)), 15));
    SP_SET(count, SP(count) + 1);
}

int f060354C0(void)
{
    int result;

    ST8(LD32(0x060C164C), 0);
    result = GCALL1(0x060692DC, LDU16(LD32(0x060C164C) + 4));
    ST32(0x060C1648, LD32(0x060C1648) - 1);
    return result;
}

int f06035840(void)
{
    FRAME(sp, 48);
    gaddr rect = sp - 48;
    int count = 0;
    int x;
    int y;

    ST16(rect + 6, 0);
    ST16(rect + 2, 0);
    ST16(rect + 12, 0);
    ST16(rect, 0);
    ST16(rect + 8, 159);
    ST16(rect + 4, 159);
    ST16(rect + 14, 111);
    ST16(rect + 10, 111);
    GCALL5(0x0609FE50, 0x1F0, 0x1C0, 0x6200, rect, 0xFFFF);
    count++;
    x = 160;
    do {
        ST16(rect + 2, 0);
        ST16(rect + 6, 224);
        ST16(rect + 4, x);
        ST16(rect, x);
        GCALL7(0x0609FCE8, 0x1F0, 192, 0x6200, rect, 0xFFFF, x, count);
        count++;
        x += 2;
    } while (AGAIN(x < 0x140));
    y = 112;
    do {
        ST16(rect, 0);
        ST16(rect + 4, 0x140);
        ST16(rect + 6, y);
        ST16(rect + 2, y);
        GCALL7(0x0609FCE8, 0x1F0, 192, 0x6200, rect, 0xFFFF, y, count);
        count++;
        y += 2;
    } while (AGAIN(y < 224));
    return count;
}

void f06035926(void)
{
    ST8(0x060C1660, 255);
    ST8(0x060C1661, 255);
    ST8(0x060C1662, 0);
    ST8(0x060C1663, 0);
}

void f0603593C(unsigned short tag, int arg)
{
    int i;

    if (tag == 255)
        return;
    i = 0;
    do {
        if (LDU16(POINTS + i * 24) == tag)
            GCALL2(0x06035DC4, i, arg);
    } while (AGAIN(++i < 30));
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

void f06035ACA(int tile, unsigned char x, unsigned char y, unsigned char width)
{
    FRAME(sp, 32);
    gaddr p;
    int step, mask, bits, rows;

    ST16(sp + 6, LDU16(sp + 6) >> 4);
    p = GCALL3(0x0600ABA4, tile, x, y);
    step = (GCALL1(0x0600AA8A, tile) & 0xFFFF) == 1 ? 2 : 4;
    if ((GCALL1(0x0600AA8A, tile) & 0xFFFF) == 1) {
        mask = -61441;
        bits = LDU16(sp + 6) << 12;
    } else {
        mask = -128;
        bits = LDU16(sp + 6) & 127;
    }
    rows = LDU8(sp + 3);
    while (rows > 0) {
        gaddr q = p;
        int cols = width;

        POLL();
        if (cols > 0) {
            do {
                cols--;
                ST16(q, (LDU16(q) & mask) | bits);
                q += step;
            } while (AGAIN(cols > 0));
        }
        p += step * 64;
        rows--;
    }
}

int f06035B7E(int n)
{
    unsigned int tag = LDU16(POINTS + (short)(n * 24));
    int found = 255;
    int i;
    gaddr e;

    if ((n & 0xFFFF) != 0) {
        e = POINTS + (short)((n - 1) * 24);
        for (i = (n & 0xFFFF) - 1; i >= 0; i--) {
            POLL();
            if (LD32(e + 12) >= 0 && LDU16(e) == tag) {
                found = i;
                break;
            }
            e -= 24;
        }
    }
    if ((found & 0xFFFF) == 255) {
        e = POINTS + 29 * 24;
        for (i = 29; i >= 0; i--) {
            POLL();
            if (LD32(e + 12) >= 0 && LDU16(e) == tag) {
                found = i;
                break;
            }
            e -= 24;
        }
    }
    return found;
}

int f06035C38(int id)
{
    unsigned short key = LDU16(POINTS + (short)(id * 24));
    int found = 255;
    int i;

    for (i = (id + 1) & 0xFFFF; i < 30; i++) {
        POLL();
        if (LD32(POINTS + (short)(i * 24) + 12) >= 0 && LDU16(POINTS + (short)(i * 24)) == key) {
            found = i;
            break;
        }
    }
    if ((found & 0xFFFF) == 255) {
        for (i = 0; i < 30; i++) {
            POLL();
            if (LD32(POINTS + i * 24 + 12) >= 0 && LDU16(POINTS + i * 24) == key) {
                found = i;
                break;
            }
        }
    }
    return found;
}

int f06035CDA(int a, int b, int c, int d)
{
    FRAME(sp, 24);
    gaddr p = POINTS;
    int i = 0;

    do {
        if (LD32(p + 12) == -1) {
            ST16(p, a);
            ST16(p + 2, b);
            ST16(p + 4, c);
            ST32(p + 8, LD32(sp + 4));
            ST8(p + 20, d);
            ST8(p + 21, LD16(sp + 2));
            ST32(p + 12, 0);
            GCALL4(0x0603847E, i, b, c, d);
            return i & 255;
        }
        p += 24;
    } while (AGAIN(++i < 30));
    return 255;
}

int f06035D36(int a, int b, int c, int d)
{
    FRAME(sp, 12);
    int i = GCALL6(0x06035CDA, a, b, c, d, LD16(sp + 2), LD32(sp + 4));
    gaddr p = POINTS + (short)(i * 24);

    ST32(p + 12, LD32(p + 12) | 0x800);
    return i;
}

void f06035D64(gaddr p)
{
    gaddr e;

    while (LD16(p) >= 0) {
        e = POINTS + (short)(GCALL6(0x06035CDA, LD16(p), LD16(p + 2), LD16(p + 4), LDU8(p + 6), LDU8(p + 7), LD32(p + 8)) * 24);
        ST32(e + 12, LD32(e + 12) | LD32(p + 12));
        p += 16;
        POLL();
    }
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

int f0603655C(int who, int flags)
{
    int keys = GCALL0(0x0602B9EC);
    int result = 255;

    if (!(flags & 0x00040000)) {
        if (keys & 0x2000)
            result = GCALL1(0x06035C38, who);
        if (keys & 0x1000)
            result = GCALL1(0x06035B7E, who);
        ST8(0x060C1672, (LD32(POINTS + 12 + (short)(who * 24)) & 0x00080000) ? 15 : 10);
        if ((who & 0xFFFF) == (GCALL1(0x06035C38, who) & 0xFFFF))
            ST8(0x060C1672, LD8(0x060C1672) & 5);
    } else {
        if (keys & 0x8000)
            result = GCALL1(0x06035C38, who);
        if (keys & 0x4000)
            result = GCALL1(0x06035B7E, who);
        ST8(0x060C1672, 5);
    }
    if ((LDU8(0x060C1672) & 5) && (keys & 0xC000))
        GCALL1(0x0600996A, 4);
    if ((LDU8(0x060C1672) & 10) && (keys & 0x3000))
        GCALL1(0x0600996A, 4);
    if (keys != 0)
        ST8(0x060C1669, 0);
    if ((result & 0xFFFF) == 255)
        result = who;
    return result;
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

void f06036778(short tag)
{
    int i;

    for (i = 0; i < 30; i++) {
        gaddr e = POINTS + i * 24;

        POLL();
        if (LD32(e + 12) != -1 && LD16(e) == tag && LD8(e + 22) != 0) {
            if (LD16(e + 18) != 0)
                GCALL1(0x060692DC, LDU16(e + 18));
            ST16(e + 18, 0);
            if (LDU16(e + 4) != 255)
                GCALL1(0x06036778, LD16(e + 4));
        }
    }
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

void f06036F40(int id)
{
    gaddr e = POINTS;
    int i = 0;
    int slot;

    if ((unsigned short)id == 255)
        return;
    while (i < 30) {
        POLL();
        if (LD32(e + 12) != -1 && !(LD32(e + 12) & 0x80000000) && LDU16(e) == (unsigned short)id && LDU16(e + 2) != 255
            && (!(LD32(e + 12) & 0x03000000) || (LD32(e + 12) & 0x03000000) == 0x01000000))
            break;
        i++;
        e += 24;
    }
    slot = GCALL3(0x0603666E, id, 255, 255);
    GCALL2(0x06035DC4, slot, 0x00200000);
    POLL();
    GJUMP2(0x06035DC4, slot, i == 30 ? 0 : 0x00100000);
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

int f0603703C(gaddr p, short link)
{
    unsigned short target = GCALL3(0x0603666E, LD16(p), LD16(p + 2), LD16(p + 4));

    if ((unsigned short)link == 0xFFFF)
        return 0;
    do {
        if ((unsigned short)link == target)
            return 1;
        link = GCALL1(0x06036FD0, link);
    } while (AGAIN((unsigned short)link != 0xFFFF));
    return 0;
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

int f06037D02(short cell, int link, short row, short col)
{
    FRAME(sp, 28);
    int id = GCALL3(0x0603666E, row, col, LD16(sp + 2)) & 0xFFFF;
    int slot;

    if (id == 255) {
        slot = -1;
    } else {
        slot = 0x060EC748;
        if (cell >= 0) {
            if (cell < 15) {
                ST32(0x060C1658, 0x060EC748 + (short)(cell * 24));
                slot = GET(Fall, FALL_PTR, fn) != 0 ? -1 : cell;
            }
        } else {
            ST32(0x060C1658, 0x060EC748);
            slot = 0;
            while (GET(Fall, FALL_PTR, fn) != 0) {
                slot++;
                ST32(0x060C1658, LD32(0x060C1658) + 24);
                if (slot >= 15)
                    break;
                POLL();
            }
            if (slot >= 15)
                slot = -1;
        }
    }
    if (slot >= 0) {
        SET(Fall, FALL_PTR, fn, link);
        SET(Fall, FALL_PTR, x, id);
        ST32(0x060C165C, POINTS + (short)(id * 24));
        ST8(0x060C1668, LD8(0x060C1668) + 1);
    }
    return slot;
}

int f06037DD6(int n)
{
    gaddr rec = 0x060EC748 + (short)(n * 24);

    if (LD32(rec + 20) != 0) {
        GCALL1(0x060692DC, LD16(rec + 10));
        GCALL1(0x060692DC, LD16(rec + 12));
        GCALL1(0x060692DC, LD16(rec + 14));
        GCALL1(0x060692DC, LD16(rec + 16));
        GCALL1(0x060692DC, LD16(rec + 18));
        ST16(rec + 8, 0);
        ST16(rec + 6, 0);
        ST16(rec + 4, 0);
        ST16(rec + 18, 0);
        ST16(rec + 16, 0);
        ST16(rec + 14, 0);
        ST16(rec + 12, 0);
        ST16(rec + 10, 0);
        ST32(rec + 20, 0);
        ST8(0x060C1668, LD8(0x060C1668) - 1);
    }
    return 0;
}

int f06037E38(void)
{
    gaddr rec = LD32(0x060C1658);

    if (LD32(rec + 20) != 0) {
        GCALL1(0x060692DC, LD16(rec + 10));
        GCALL1(0x060692DC, LD16(LD32(0x060C1658) + 12));
        GCALL1(0x060692DC, LD16(LD32(0x060C1658) + 14));
        GCALL1(0x060692DC, LD16(LD32(0x060C1658) + 16));
        GCALL1(0x060692DC, LD16(LD32(0x060C1658) + 18));
        rec = LD32(0x060C1658);
        ST16(rec + 8, 0);
        ST16(rec + 6, 0);
        ST16(rec + 4, 0);
        rec = LD32(0x060C1658);
        ST16(rec + 18, 0);
        ST16(rec + 16, 0);
        ST16(rec + 14, 0);
        ST16(rec + 12, 0);
        ST16(rec + 10, 0);
        ST32(LD32(0x060C1658) + 20, 0);
        ST8(0x060C1668, LD8(0x060C1668) - 1);
    }
    return 0;
}

int f06038004(short offset)
{
    short ids[3];
    int i = 0;
    int shift = 0;

    do {
        gaddr obj;

        ids[i] = GCALL1(0x060691DA, 0x1EB);
        obj = OBJ(ids[i] & 0xFFFF);
        ST16(obj + 16, GET(Fall, FALL_PTR, col) * 8 + offset - shift + 24);
        ST16(obj + 18, GET(Fall, FALL_PTR, row) * 8);
        ST16(obj + 44, 1);
        ST16(obj + 40, LD16(obj + 40) | 0x400);
        GCALL2(0x0606950C, obj, 2);
        shift += 8;
    } while (AGAIN((short)++i < 3));
    SET(Fall, FALL_PTR, id, ids[0]);
    SET(Fall, FALL_PTR, id2, ids[1]);
    SET(Fall, FALL_PTR, count, ids[2]);
    return ids[2];
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06038174(void)
{
}

void f06038178(unsigned short count, gaddr out)
{
    int i = 0;
    gaddr o;

    if (count > 0) {
        do {
            ST16(out, GCALL1(0x060691DA, 1));
            o = OBJ(LDU16(out));
            ST16(o + 44, 1);
            ST16(o + 38, 0);
            ST16(o + 36, 0);
            ST16(o + 40, LD16(o + 40) | 0x400);
            GCALL2(0x0606950C, o, 2);
            i++;
            out += 2;
        } while (AGAIN((short)i < count));
    }
    ST16(out, 0);
}

void f060381EA(unsigned short count, gaddr out)
{
    int i = 0;
    gaddr o;

    if (count > 0) {
        do {
            ST16(out, GCALL1(0x060691DA, 1));
            i++;
            o = OBJ(LDU16(out));
            ST16(o + 44, 0);
            ST16(o + 38, 0);
            ST16(o + 36, 0);
            out += 2;
        } while (AGAIN((short)i < count));
    }
    ST16(out, 0);
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

void f0603840E(gaddr list, short arg)
{
    while (LD16(list) > 0) {
        POLL();
        GCALL2(0x0606AB08, LD16(list), (unsigned short)arg);
        list += 2;
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

short f060387EC(int id, gaddr dst)
{
    gaddr src = GCALL2(0x06008ABA, id, 1) + 2;
    short n = LD16(src);
    int left = n;

    src += 2;
    while ((unsigned short)left) {
        POLL();
        left--;
        ST16(dst, LD16(src));
        dst += 2;
        src += 2;
    }
    return n;
}

void f0603890C(short first, short count, gaddr ramp, short step)
{
    int left = LD16(0x060C1696);
    unsigned int i;
    gaddr dst = 0x060CBC60 + first * 2;
    int color;
    int acc;

    if (step > (unsigned short)left)
        step = left;
    ST16(0x060C1696, LD16(0x060C1696) - step);
    if (step == 0)
        return;
    if (0 < (unsigned int)count) {
        i = 0;
        do {
            acc = LD16(ramp + 2) + step * LD16(ramp);
            ST16(ramp + 2, acc);
            color = HELPER(((short)acc & 0x1F00) >> 8);
            ramp += 4;
            acc = LD16(ramp + 2) + step * LD16(ramp);
            ST16(ramp + 2, acc);
            color |= ((short)acc & 0x1F00) >> 3;
            ramp += 4;
            acc = LD16(ramp + 2) + step * LD16(ramp);
            ST16(ramp + 2, acc);
            color |= ((short)acc & 0x1F00) << 2;
            ST16(dst, color);
            ST16(0x060CBB60 + ((short)(first + i) >> 4) * 2, 1);
            i++;
            dst += 2;
            ramp += 4;
        } while (AGAIN(i < (unsigned int)count));
    }
    ST16(0x26006048, 1);
    if (LD32(0x26006168) == 0) {
        POLL();
        GJUMP0(0x060090D8);
    }
}

void f060389E2(void)
{
    gaddr p;

    for (p = 0x060C168E; p <= 0x060C1694; p += 2)
        GCALL1(0x0600940A, LD16(p));
}

void f06038BF0(short x0, short y0, short x1, short y1)
{
    FRAME(sp, 64);
    gaddr masks = sp - 64;
    gaddr plane0 = 0x25E45E00;
    gaddr plane1 = 0x25E45E60;
    gaddr plane2 = 0x25E45EC0;
    int cell_x = DIVS(x0, 8);
    int cell_y = DIVS(y0, 8);
    int top = 7 & y0;
    int right = (7 & x1) + 1;
    int w;
    int h;
    int end;
    int left_mask;
    int right_mask;
    int i;
    gaddr tiles;
    gaddr row;
    int tile;

    COPYW(0x0609445C, masks, 0x060B1DF8, 36);
    ST16(0x25F007FE, LD16(sp + 2));
    w = (short)(DIVS(x1, 8) - DIVS(x0, 8));
    h = (short)(DIVS(y1, 8) - DIVS(y0, 8));
    left_mask = LD32(masks + (7 & x0) * 4);
    right_mask = ~LD32(masks + right * 4);
    if (w == 0)
        left_mask &= right_mask;
    end = (short)(h != 0 ? (7 & y1) + 1 + 16 : (7 & y1) + 1);
    i = 0;
    if (i < top) {
        do {
            i++;
            ST32(plane2, 0);
            ST32(plane1, 0);
            plane1 += 4;
            ST32(plane0, 0);
            plane0 += 4;
            plane2 += 4;
        } while (AGAIN(i < top));
    }
    if (i < end) {
        do {
            ST32(plane0, left_mask);
            i++;
            ST32(plane1, -1);
            plane0 += 4;
            ST32(plane2, right_mask);
            plane1 += 4;
            plane2 += 4;
        } while (AGAIN(i < end));
    }
    if (i < 24) {
        do {
            i++;
            ST32(plane2, 0);
            ST32(plane1, 0);
            plane1 += 4;
            ST32(plane0, 0);
            plane0 += 4;
            plane2 += 4;
        } while (AGAIN(i < 24));
    }
    tiles = GCALL3(0x0600ABA4, 32, (short)cell_x, (short)cell_y);
    tile = 0x003F22F0;
    ST32(tiles, tile);
    row = tiles;
    if (!(h > 0)) {
        tile = 0x003F22F3;
    } else {
        int j = 1;

        tile++;
        row += 0x100;
        if (j < h) {
            do {
                ST32(row, tile);
                j++;
                row += 0x100;
            } while (AGAIN(j < h));
        }
        ST32(row, tile + 1);
        tile += 2;
    }
    tiles += 4;
    fill_row(tiles, tile, w);
    if (!(h > 0)) {
        tile += 3;
    } else {
        int j = 1;

        tile++;
        row = tiles + 0x100;
        while (j < h) {
            POLL();
            fill_row(row, tile, w);
            row += 0x100;
            j++;
        }
        tile++;
        fill_row(row, tile, w);
        tile++;
    }
    tiles += (w - 1) * 4;
    if (w > 0) {
        ST32(tiles, tile);
        if (h > 0) {
            int j = 1;

            tile++;
            row = tiles + 0x100;
            if (j < h) {
                do {
                    j++;
                    ST32(row, tile);
                    row += 0x100;
                } while (AGAIN(j < h));
            }
            ST32(row, tile + 1);
        }
    }
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

void f0603968C(gaddr out, int angle, short x, short y)
{
    FRAME(sp, 0);
    int sine = GCALL1(0x0609812C, angle);
    int cosine = GCALL1(0x0609816C, angle);
    int a = FMUL(cosine, x);
    int b = FMUL(sine, y);

    ST16(out, HELPER((int)((b + a) * LDU16(sp + 2)) >> 8));
    a = FMUL(sine, x);
    b = FMUL(cosine, y);
    ST16(out + 2, HELPER((int)((b - a) * LDU16(sp + 6)) >> 8));
}

void f0603983A(void)
{
    FRAME(sp, 52);
    gaddr pts = sp - 52;
    int angle = LDU16(0x060DFE3C) << 16;
    gaddr obj;

    angle -= angle > 0x00B40000 ? 0x01680000 : 0;
    obj = OBJ(LDU16(0x060DFE28));
    GCALL6(0x0603968C, pts, angle, -80, -80, 0x100, 0x100);
    GCALL6(0x0603968C, pts + 4, angle, 80, -80, 0x100, 0x100);
    GCALL6(0x0603968C, pts + 8, angle, 80, 80, 0x100, 0x100);
    GCALL6(0x0603968C, pts + 12, angle, -80, 80, 0x100, 0x100);
    ST16(obj + 20, LD16(obj + 16) + LD16(pts));
    ST16(obj + 22, LD16(obj + 18) + LD16(pts + 2));
    ST16(obj + 24, LD16(obj + 16) + LD16(pts + 4));
    ST16(obj + 26, LD16(obj + 18) + LD16(pts + 6));
    ST16(obj + 28, LD16(obj + 16) + LD16(pts + 8));
    ST16(obj + 30, LD16(obj + 18) + LD16(pts + 10));
    ST16(obj + 32, LD16(obj + 16) + LD16(pts + 12));
    ST16(obj + 34, LD16(obj + 18) + LD16(pts + 14));
    GCALL4(0x06039A20, LD16(obj + 16), LD16(obj + 18), 1, angle);
    ST16(0x060DFE3C, LD16(0x060DFE3C) + 1);
    ST16(0x060DFE3C, MODS(LDU16(0x060DFE3C), 0x168));
}

void f06039A20(short x, short y, short slot, int angle)
{
    FRAME(sp, 52);
    gaddr pts = sp - 52;
    gaddr list = 0x060DFE28 + slot * 2;
    int count = 5;

    for (;;) {
        gaddr obj = OBJ(LDU16(list));
        int swing;

        GCALL6(0x0603968C, pts, angle, 0, 75, 0x100, 0x100);
        ST16(obj + 16, x + LD16(pts));
        ST16(obj + 18, y + LD16(pts + 2));
        swing = -(GCALL1(0x0609816C, (int)0xFF4C0000 + MODS(0x00E10000 + angle, 0x01680000)) * 40);
        GCALL6(0x0603968C, pts, swing, -20, -8, 0x100, 0x100);
        GCALL6(0x0603968C, pts + 4, swing, 20, -8, 0x100, 0x100);
        GCALL6(0x0603968C, pts + 8, swing, 20, 32, 0x100, 0x100);
        GCALL6(0x0603968C, pts + 12, swing, -20, 32, 0x100, 0x100);
        ST16(obj + 20, LD16(obj + 16) + LD16(pts));
        ST16(obj + 22, LD16(obj + 18) + LD16(pts + 2));
        ST16(obj + 24, LD16(obj + 16) + LD16(pts + 4));
        ST16(obj + 26, LD16(obj + 18) + LD16(pts + 6));
        ST16(obj + 28, LD16(obj + 16) + LD16(pts + 8));
        ST16(obj + 30, LD16(obj + 18) + LD16(pts + 10));
        ST16(obj + 32, LD16(obj + 16) + LD16(pts + 12));
        ST16(obj + 34, LD16(obj + 18) + LD16(pts + 14));
        angle += 0x00480000;
        if (angle > 0x00B40000)
            angle -= 0x01680000;
        list += 2;
        if (--count == 0)
            break;
        POLL();
    }
}

int f06039BE6(int x)
{
    if (!x)
        return 0x00010000;
    if (ABS(x) > 0x00010000)
        return 0;
    return GCALL1(0x060972D8, 0x00010000 - GCALL2(0x060980B4, x, x));
}

void f06039C28(int a, short tail, int c, short head)
{
    FRAME(sp, 68);
    int ax = (short)(a << 1);
    int cx = (short)(c << 1);
    int mid, rows, acc, step, last, diff;
    gaddr out = LD32(sp + 8);
    int i = 0;

    ST16(sp + 2, LD16(sp + 2) << 1);
    mid = LD16(sp + 2);
    rows = LD16(sp + 6);
    if (rows > 0) {
        diff = rows - head;
        step = DIVS(0x10000, head);
        acc = 0x10000;
        if (diff < 0) {
            acc = step * diff + 0x10000;
        } else if (diff > 0) {
            do {
                ST16(out, 0x3FE);
                i++;
                out += 2;
                ST16(out, 0x3FE);
                out += 2;
            } while (AGAIN(i < diff));
        }
        if (rows > 224) {
            rows = 224;
            ST16(sp + 6, 224);
        }
        if (i < rows) {
            do {
                int t = GCALL1(0x06039BE6, acc);
                int top, bottom;

                acc -= step;
                top = mid - GCALL2(0x060980B4, t, cx);
                bottom = mid + GCALL2(0x060980B4, t, ax);
                if (top < 0)
                    top = 0;
                if (bottom > 0x280)
                    bottom = 0x280;
                ST16(out, top & 0x3FE);
                ST16(out + 2, bottom & 0x3FE);
                i++;
                out += 4;
            } while (AGAIN(i < rows));
        }
    }
    if (LD16(sp + 6) < 224) {
        acc = 0;
        step = DIVS(0x10000, tail);
        last = LD16(sp + 6) + tail;
        if (last > 224)
            last = 224;
        if (i < last) {
            do {
                int t = GCALL1(0x06039BE6, acc);
                int top, bottom;

                acc += step;
                top = mid - GCALL2(0x060980B4, t, cx);
                bottom = mid + GCALL2(0x060980B4, t, ax);
                if (top < 0)
                    top = 0;
                if (bottom > 0x280)
                    bottom = 0x280;
                ST16(out, top & 0x3FE);
                ST16(out + 2, bottom & 0x3FE);
                i++;
                out += 4;
            } while (AGAIN(i < last));
        }
    }
    if (i < 224) {
        do {
            ST16(out, 0x3FE);
            i++;
            out += 2;
            ST16(out, 0x3FE);
            out += 2;
        } while (AGAIN(i < 224));
    }
}

void f06039DD8(void)
{
    ST8(0x060C1725, 0);
}

int f06039EEE(void)
{
    GCALL0(0x06039DD8);
    GCALL5(0x06039DE0, 0, 160, 112, 0x100, 128);
    GCALL6(0x06039DE0, 1, 160, 112, 128, 128, 128);
    ST16(0x060FAA70, 0x8E8E);
    ST16(0x060FAA72, 0x8E8E);
    ST16(0x060FAA74, 0x8E8E);
    ST16(0x060FAA76, 0x8E8E);
    return 0x8E8E;
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

void f0603A0A8(void)
{
    gaddr rec;

    GCALL0(0x0600D8F8);
    rec = GCALL2(0x0600B934, LDU8(0x060C029C), LDU8(0x060C029D));
    POLL();
    GJUMP2(0x0600CFC6, LDU16(rec + 124), LDU16(rec + 126));
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

int f0603A3A0(void)
{
    int i = 0;
    int result;

    do {
        gaddr rec = 0x060EC748 + i * 24;

        GCALL1(0x060692DC, LD16(rec + 10));
        result = GCALL1(0x060692DC, LD16(rec + 12));
    } while (AGAIN(++i < 4));
    return result;
}

int f0603A45A(void)
{
    return GJUMP1(0x0606948A, GET(Fall, FALL_PTR, id));
}

int f0603A466(void)
{
    gaddr obj;
    int kind;

    GCALL1(0x0606948A, GET(Fall, FALL_PTR, id));
    obj = OBJ(GET(Fall, FALL_PTR, id)) + 4;
    kind = GET(Fall, FALL_PTR, y);
    ST16(obj, LD16(obj) + (kind == 2 ? 1 : -1));
    return kind;
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

int f0603A7A6(void)
{
    int left;

    GCALL1(0x0606948A, GET(Fall, FALL_PTR, id));
    if (GET(Fall, FALL_PTR, count) == 0) {
        SET(Fall, FALL_PTR, fn, 0x0603A466);
    } else {
        gaddr obj;

        GCALL3(0x0603A614, GET(Fall, FALL_PTR, id), GET(Fall, FALL_PTR, y), GET(Fall, FALL_PTR, x));
        GCALL3(0x0603A614, GET(Fall, FALL_PTR, id2), GET(Fall, FALL_PTR, y), GET(Fall, FALL_PTR, x));
        obj = OBJ(GET(Fall, FALL_PTR, id)) + 38;
        ST16(obj, LD16(obj) + HELPER(GET(Fall, FALL_PTR, v) >> 8));
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

int f0603AA2C(void)
{
    int left;

    GCALL1(0x0606948A, GET(Fall, FALL_PTR, id));
    if (GET(Fall, FALL_PTR, count) == 0) {
        SET(Fall, FALL_PTR, fn, 0x0603A466);
    } else {
        GCALL3(0x0603A614, GET(Fall, FALL_PTR, id), GET(Fall, FALL_PTR, y), GET(Fall, FALL_PTR, x));
        GCALL3(0x0603A614, GET(Fall, FALL_PTR, id2), GET(Fall, FALL_PTR, y), GET(Fall, FALL_PTR, x));
    }
    left = GET(Fall, FALL_PTR, count) - 1;
    SET(Fall, FALL_PTR, count, left);
    return left;
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

void f0603B368(short x, short y, short value)
{
    int base;

    ST16(0x060D7E42, GCALL2(0x0600C950, x, y));
    ST16(0x060D7E44, value);
    GCALL3(0x0600D0E4, LD16(0x060D7E38), x, y);
    ST16(OBJ(LDU16(0x060D7E38)) + 38, value);
    POLL();
    GCALL2(0x0600A3DC, LDU16(0x060D7E38), LDU16(0x060D7E3A));
    GCALL2(0x0600A3DC, LDU16(0x060D7E38), LDU16(0x060D7E3C));
    GCALL2(0x0600A3DC, LDU16(0x060D7E38), LDU16(0x060D7E3E));
    GCALL2(0x0603B25E, LD16(0x060D7E38), LD16(0x060D7E40));
    GCALL1(0x0606948A, (short)TGET(h8));
    base = LD16(OBJ(TGET(h8)) + 4);
    ST16(OBJ(TGET(h10)) + 4, base + 5);
    ST16(OBJ(TGET(h12)) + 4, base + 5);
    ST16(OBJ(TGET(h14)) + 4, base + 7);
    ST16(OBJ(TGET(h16)) + 4, 10);
}

void f0603B4B2(void)
{
    FRAME(sp, 40);
    gaddr ids = sp - 40;
    int v, k;
    gaddr obj;

    GCALL2(0x0605EC1E, ids, 5);
    v = LD16(LD32(TASK_OBJ) + 68);
    if (v > 0) {
        v -= 2;
    } else {
        v = 0;
        TSET(fn, 0x0603DDA6);
    }
    k = 0;
    do {
        obj = OBJ(LDU16(ids + k * 2));
        ST16(obj + 70, v);
        ST16(obj + 68, v);
        ST16(obj + 74, -32);
    } while (AGAIN(++k < 4));
    obj = OBJ(LDU16(ids + 8));
    ST16(obj + 18, LD16(obj + 18) - 3);
    k = 0;
    do {
        obj = OBJ(LDU16(0x060C1728 + k * 2));
        ST16(obj + 70, v);
        ST16(obj + 68, v);
        ST16(obj + 74, -24);
    } while (AGAIN(++k < 2));
}

int f0603B56C(void)
{
    FRAME(sp, 40);
    gaddr list = sp - 40;
    int speed;
    int k = 0;
    gaddr obj;

    GCALL2(0x0605EC1E, list, 5);
    speed = LD16(LD32(TASK_OBJ) + 68);
    if (!(speed > 0)) {
        speed = 0;
        TSET(fn, 0x0603DDA6);
    } else {
        speed -= 2;
    }
    do {
        obj = OBJ(LDU16(list + k * 2));
        ST16(obj + 70, speed);
        ST16(obj + 68, speed);
        ST16(obj + 74, -160);
    } while (AGAIN((short)++k < 4));
    obj = OBJ(LDU16(list + 8));
    ST16(obj + 18, LD16(obj + 18) - 3);
    k = 0;
    do {
        obj = OBJ(LDU16(0x060C1728 + k * 2));
        ST16(obj + 70, speed);
        ST16(obj + 68, speed);
        ST16(obj + 74, -152);
    } while (AGAIN((short)++k < 2));
    return 74;
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

int f0603BC98(int a, short mode)
{
    gaddr obj;
    int r = GCALL2(0x06022F1C, a, 0x0603BD04);

    if (r < 0)
        return r;
    ST16(LD32(TASK_PTR) + 6, 0);
    ST16(LD32(TASK_PTR) + 4, mode);
    obj = LD32(TASK_OBJ);
    ST16(obj + 4, 0x190);
    ST16(LD32(TASK_OBJ) + 44, 0);
    GCALL1(0x0606AB24, LD32(TASK_OBJ));
    GCALL2(0x0606AAC8, LD32(TASK_OBJ), 0);
    ST16(LD32(TASK_OBJ) + 46, 0x1A0);
    GCALL2(0x0606950C, LD32(TASK_OBJ), 1);
    ST16(LD32(TASK_PTR) + 14, 0x100);
    ST16(LD32(TASK_PTR) + 16, 0);
    return 0;
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

int f0603D862(void)
{
    GCALL1(0x0603EDA6, 10);
    GCALL1(0x0603EDA6, 11);
    return GJUMP0(0x0603D878);
}

int f0603D868(void)
{
    GCALL1(0x0603EDA6, 11);
    return GJUMP0(0x0603D878);
}

int f0603D86E(void)
{
    return GJUMP0(0x0603D878);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603DDA6(void)
{
}

int f0603DE58(void)
{
    FRAME(sp, 8);

    COPYB(sp - 8, 0x060B1FC8, 4);
    GCALL1(0x06008A96, 1);
    GCALL1(0x06068A5E, sp - 8);
    return GCALL1(0x06022EDA, 0);
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

int f0603E11C(void)
{
    FRAME(sp, 24);

    COPYB(sp - 24, 0x060B1FDE, 18);
    if (LD16(0x060D7BB0) == 0)
        return 0;
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068A5E, sp - 24);
    GCALL1(0x060692DC, LDU16(0x060D7BB2));
    return GCALL1(0x06022EDA, 4);
}

int f0603E212(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 4);
    gaddr o = OBJS + (unsigned short)(GET(Slot24, s, obj) * 84);

    if (!LD16(o + 10) || LDU16(o + 60) >= 0xFF00)
        return -1;
    return 0;
}

void f0603E33C(void)
{
    FRAME(sp, 8);

    COPYB(sp - 8, 0x060B1FF4, 4);
    GCALL1(0x06008A96, 1);
    GCALL1(0x06068A5E, sp - 8);
    GCALL1(0x06022EDA, 9);
}

int f0603E366(void)
{
    FRAME(sp, 8);

    COPYB(sp - 8, 0x060B1FF8, 4);
    GCALL1(0x06008A96, 1);
    GCALL1(0x06068A5E, sp - 8);
    return GCALL1(0x06022EDA, 9);
}

int f0603E436(void)
{
    FRAME(sp, 12);

    COPYB(sp - 12, 0x060B2002, 6);
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068A5E, sp - 12);
    return GCALL1(0x06022EDA, 8);
}

int f0603E4CC(int base)
{
    return base + 70;
}

int f0603E4D2(int p)
{
    return p + 82;
}

int f0603E4D8(short index)
{
    FRAME(sp, 12);

    COPYB(sp - 12, 0x060B2008, 8);
    return LD16(sp - 12 + index * 2) + 74;
}

int f0603E4F6(int base)
{
    return base + 78;
}

int f0603E5A8(void)
{
    GCALL1(0x06008A96, 1);
    GCALL1(0x06068A5E, 0x060B5E4A);
    return GJUMP1(0x06022EDA, 10);
}

void f0603E604(void)
{
    FRAME(sp, 36);
    gaddr dirs = sp - 36;
    gaddr obj = OBJ(TGET(h8));
    int pick = 0;

    if (LD16(LD32(TASK_PTR) + 14) == LD16(LD32(TASK_PTR) + 16)) {
        pick = 1;
    } else if (TGET(h12) == 255) {
        pick = 1;
    } else if ((TGET(h16) & 63) == 0) {
        int x;
        int y;

        GCALL1(0x0600CA6A, TGET(h8));
        x = LD16(0x060D7EB4);
        y = LD16(0x060D7EB6);
        if (TGET(h12) == 0)
            x++;
        else if (TGET(h12) == 1)
            y++;
        else if (TGET(h12) == 2)
            x--;
        else if (TGET(h12) == 3)
            y--;
        if ((GCALL2(0x0603E888, x, y) & 0xFFFF) == 0)
            pick = 1;
    }
    if (pick) {
        GCALL2(0x0603E786, dirs, LD16(LD32(TASK_PTR) + 12));
        TSET(h12, GCALL2(0x0603E7AC, dirs, TGET(h8)) & 255);
        TSET(h14, ((GCALL1(0x0600A0EC, 3) + 1) & 255) << 6);
        TSET(h16, 0);
    }
    if (TGET(h12) != 255) {
        if ((TGET(h16) & 3) == 0) {
            if (TGET(h12) == 0)
                ST16(obj + 16, LD16(obj + 16) + 1);
            else if (TGET(h12) == 1)
                ST16(obj + 18, LD16(obj + 18) + 1);
            else if (TGET(h12) == 2)
                ST16(obj + 16, LD16(obj + 16) - 1);
            else if (TGET(h12) == 3)
                ST16(obj + 18, LD16(obj + 18) - 1);
        }
        TSET(h16, TGET(h16) + 1);
        TSET(h18, TGET(h12));
    }
}

void f0603E786(gaddr dir, unsigned char which)
{
    ST8(dir + 3, 0);
    ST8(dir + 2, 0);
    ST8(dir + 1, 0);
    ST8(dir, 0);
    if (which < 4) {
        ST8(dir + ((which + 2) & 3), 1);
        ST8(dir + which, 1);
    }
}

int f0603E7AC(gaddr dirs, short cell)
{
    int x;
    int y;
    int dir;
    int i = 0;

    GCALL1(0x0600CA6A, (unsigned short)cell);
    x = LD16(0x060D7EB4);
    y = LD16(0x060D7EB6);
    dir = GCALL0(0x0600A0B8) & 3;
    if (dir == 0)
        x++;
    else if (dir == 1)
        y++;
    else if (dir == 2)
        x--;
    else if (dir == 3)
        y--;
    for (;;) {
        dir &= 3;
        if (LD8(dirs + dir) != 0) {
            ST8(dirs + dir, 0);
        } else if (GCALL2(0x0603E888, x, y) & 0xFFFF) {
            break;
        }
        x += (dir & 2) ? 1 : -1;
        y += ((dir + 1) & 2) ? -1 : 1;
        i++;
        dir++;
        if (i >= 8)
            break;
        POLL();
    }
    if (i == 8)
        dir = 255;
    return dir;
}

int f0603E888(unsigned short x, unsigned short y)
{
    if (x < 32 || x > 40 || y < 19 || y > 25)
        return 0;
    return LD8(0x060B5E0A + (y - 19) * 9 + (x - 32)) & 255;
}

int f0603E930(int cell)
{
    int next = LDU8(0x060D84A3);

    for (;;) {
        ST32(ACTOR_PTR, 0x060D849C + next * 38);
        if (AGET(b7) == 0)
            return 0;
        POLL();
        if (AGET(b16) != 0 && AGET(b16) != 255 && AGET(w4) == cell)
            return LDU8(0x060D849C + AGET(b6) * 38 + 7);
        next = AGET(b7);
    }
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

int f0603F47A(short n)
{
    GCALL1(0x060692DC, LDU16(SLOT(n) + 10));
    return GJUMP1(0x06022EDA, n);
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

void f0603F904(void)
{
    FRAME(sp, 24);
    gaddr pts = sp - 24;
    int angle = -LD32(0x060B9108 + LDU16(0x060D7C02) * 4);
    gaddr a;
    gaddr b;
    gaddr c;

    GCALL6(0x0603968C, pts, angle, -47, 0, 0x100, 224);
    a = OBJ(LDU16(0x060D7C00));
    ST16(a + 32, LD16(a + 16) + LD16(pts) + 47);
    ST16(a + 20, LD16(a + 16) + LD16(pts) + 47);
    ST16(a + 28, LD16(a + 16) + 47);
    ST16(a + 24, LD16(a + 16) + 47);
    ST16(a + 22, LD16(a + 18) + LD16(pts + 2));
    ST16(a + 26, LD16(a + 18));
    ST16(a + 30, LD16(a + 26) + 47);
    ST16(a + 34, LD16(a + 22) + 47);
    GCALL6(0x0603968C, pts, angle, -31, 0, 0x100, 0x100);
    b = OBJ(LDU16(0x060D7BFC));
    c = OBJ(LDU16(0x060D7BFE));
    ST16(b + 20, LD16(b + 16) + LD16(pts) + 1);
    ST16(b + 22, LD16(b + 18) + LD16(pts + 2) - 33);
    ST16(b + 24, LD16(b + 16) + 5);
    ST16(b + 26, LD16(b + 18) - 68);
    ST16(c + 20, LD16(c + 16) + LD16(pts) + 1);
    ST16(c + 22, LD16(c + 18) + LD16(pts + 2) + 11);
    ST16(c + 24, LD16(c + 16) + 5);
    ST16(c + 26, LD16(c + 18) - 24);
    ST16(b + 28, LD16(b + 20));
    ST16(b + 32, LD16(b + 24));
    ST16(b + 30, LD16(b + 22));
    ST16(b + 34, LD16(b + 26));
    ST16(c + 28, LD16(c + 20));
    ST16(c + 32, LD16(c + 24));
    ST16(c + 30, LD16(c + 22));
    ST16(c + 34, LD16(c + 26));
}

int f0603FB16(short n)
{
    gaddr slot = SLOT(n);

    GCALL1(0x060692DC, LDU16(slot + 10));
    GCALL1(0x060692DC, LDU16(slot + 12));
    GCALL1(0x060692DC, LDU16(slot + 14));
    GCALL1(0x060692DC, LDU16(slot + 16));
    GCALL1(0x060692DC, LDU16(slot + 18));
    GCALL1(0x060692DC, LDU16(slot + 20));
    return GJUMP1(0x06022EDA, (unsigned short)n);
}

int f0603FCCC(void)
{
    gaddr obj = OBJ(TGET(h8));

    ST16(obj + 42, LD16(obj + 42) | 0x400);
    obj = OBJ(TGET(h10));
    ST16(obj + 42, LD16(obj + 42) | 0x400);
    return 42;
}
