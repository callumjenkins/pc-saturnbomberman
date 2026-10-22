#include "krnl.h"

void f0604021C(short n)
{
    REF(Task) t;
    int i = 0;
    gaddr obj;

    GCALL2(0x06022F1C, n, 0x06040336);
    TSET(h6, 0);
    ST16(LD32(TASK_OBJ) + 4, 70);
    ST16(LD32(TASK_OBJ) + 46, 0x380);
    t = TASK;
    SET(Task, t, h10, GCALL1(0x060691DA, 1));
    t = TASK;
    SET(Task, t, h12, GCALL1(0x060691DA, 1));
    do {
        if (i == 0)
            obj = OBJ(TGET(h10));
        else if (i >= 2)
            obj = LD32(TASK_OBJ);
        else
            obj = OBJ(TGET(h12));
        ST16(obj + 44, 1);
        GCALL2(0x0606AAC8, obj, 7);
        GCALL2(0x0606950C, obj, 2);
        GCALL1(0x0606AB4A, obj);
        i++;
        ST16(obj + 70, 0x100);
        ST16(obj + 68, 0x100);
    } while (AGAIN(i < 3));
    TSET(h14, 2);
    TSET(h18, 255);
    TSET(h20, 0);
}

void f060407F2(unsigned short obj, unsigned short bits)
{
    int flags = OBJ(obj) + 46;

    ST16(flags, (LDU16(flags) & 0xFC00) | bits);
}

/* 0 and 1 pick a table; any other value is taken as the table's address. */
int f06040890(int table, short i)
{
    switch ((short)table) {
    case 0:
        table = 0x060B5F1C;
        break;
    case 1:
        table = 0x060B5FF8;
        break;
    }
    return table + i * 8;
}

int f060408F4(short n)
{
    REF(Slot24) s = BYTEOFF(Slot24, SLOTS, (short)(n * 24));

    return GET(Slot24, s, w18) != 0xFF;
}

int f06040918(short slot)
{
    return LD16(SLOT(slot) + 20);
}

void f06040BD4(short n, short x)
{
    GCALL2(0x06022F1C, n, 0x0603DDA6);
    ST16(LD32(TASK_OBJ) + 44, 1);
    ST16(LD32(TASK_OBJ) + 46, 0x380);
    GCALL2(0x0606AAC8, LD32(TASK_OBJ), 3);
    TSET(h16, x);
}

int f06040DEE(unsigned short cell)
{
    int result = 0;
    gaddr a;

    if (!(LDU16(FLAGS_AT(cell)) & 7))
        return 0;
    a = 0x060D849C + GCALL1(0x06020F8C, cell) * 38;
    if ((unsigned int)LD8(a + 15) < (unsigned int)LD8(BOMBER_COUNT))
        result = SHL(1, LDU8(a + 15));
    if (LDU8(a + 15) >= 50)
        result = 3;
    return result;
}

int f06040E4A(void)
{
    unsigned short key = GCALL1(0x0600CA6A, TGET(h8));
    int i = 2;

    do {
        if (key == LDU16(0x060C1742 + (i - 1) * 2))
            break;
        i--;
    } while (AGAIN(i > 0));
    return i;
}

int f060413C6(void)
{
    return ((GCALL1(0x0600A0EC, 3) + 2) & 0xFFFF) * 60;
}

int f060413E2(void)
{
    int v = (short)TGET(h12);
    int key = GCALL1(0x0600CA6A, TGET(h8)) & 63;

    if (key == 26)
        return 0;
    if (key == 18)
        return 1;
    if ((unsigned)GCALL0(0x0600A0B8) < 16)
        v ^= 1;
    return v;
}

int f0604142A(short arg)
{
    int rnd = GCALL1(0x0600A0EC, 8) + 18;
    int flag;
    int kind;

    GCALL3(0x0600D0E4, (short)TGET(h8), rnd, arg);
    POLL();
    flag = (short)TGET(h12);
    kind = GCALL1(0x0600CA6A, TGET(h8)) & 63;
    if (kind == 26)
        flag = 0;
    else if (kind == 18)
        flag = 1;
    else if ((unsigned int)GCALL0(0x0600A0B8) < 16)
        flag ^= 1;
    return flag;
}

void f0604144E(void)
{
    int mode = TGET(h14);
    gaddr obj;
    int pos;

    if (mode != 2 && mode != 3)
        return;
    obj = LD32(TASK_OBJ);
    pos = (LD16(obj + 16) << 16) | LDU16(obj + 12);
    pos += (TGET(h20) << 8) * (TGET(h12) ? 1 : -1);
    ST16(LD32(TASK_OBJ) + 16, (unsigned)pos >> 16);
    ST16(LD32(TASK_OBJ) + 12, pos);
}

void f0604271C(void)
{
    short ids[5];
    int phase = TGET(h18) & 1;
    int delta = LD16(TASK + 20) - LD32(0x060C02DC);
    int k;

    ids[0] = TGET(h8);
    ids[1] = TGET(h10);
    ids[2] = TGET(h12);
    ids[3] = TGET(h14);
    ids[4] = TGET(h16);
    k = 0;
    do {
        gaddr obj = OBJ(ids[k]);

        ST16(obj + 38, HELPER((int)((16 - k) * delta) >> 12));
        switch (k) {
        case 0:
            ST16(obj + 36, LD16(obj + 36) - (phase + 2));
            break;
        case 1:
            ST16(obj + 36, LD16(obj + 36) - 2);
            break;
        case 2:
            ST16(obj + 36, LD16(obj + 36) - (phase + 1));
            break;
        case 3:
            ST16(obj + 36, LD16(obj + 36) - 1);
            break;
        case 4:
            ST16(obj + 36, LD16(obj + 36) - phase);
            break;
        }
        if (LD16(obj + 36) < -464) {
            ST16(obj + 36, 0);
            GCALL1(0x0600A0EC, 48);
            ST16(obj + 18, k * 10);
        }
    } while (AGAIN(++k < 5));
    TSET(h18, TGET(h18) + 1);
    if (TGET(h18) == 6)
        TSET(h18, 0);
}

void f060429A8(void)
{
    SET(Slot24, ELEM(Slot24, SLOTS, 1), fn, 0x06042864);
}

int f06042A9C(void)
{
    int y;

    ST16(LD32(TASK_OBJ) + 36, HELPER(((short)TGET(h10) - LD32(0x060C02D8)) >> 8));
    y = HELPER(((short)TGET(h12) - LD32(0x060C02DC)) >> 8);
    ST16(LD32(TASK_OBJ) + 38, y);
    return y;
}

int f06042C8C(void)
{
    gaddr obj = LD32(TASK_OBJ);
    int y;

    ST16(obj + 36, LD16(obj + 36) + (short)TGET(h12));
    obj = LD32(TASK_OBJ);
    ST16(obj + 38, LD16(obj + 38) + (short)TGET(h14));
    TSET(h14, TGET(h14) + 1);
    TSET(h10, TGET(h10) + 3);
    ST16(LD32(TASK_OBJ) + 68, (short)TGET(h10) * 2 + 0x100);
    ST16(LD32(TASK_OBJ) + 70, (short)TGET(h10) * 2 + 0x100);
    obj = LD32(TASK_OBJ);
    y = LD16(obj + 18) + LD16(obj + 38);
    if (y <= 240)
        return y;
    return GJUMP0(0x06022F14);
}

int f06042F96(void)
{
    FRAME(sp, 16);

    COPYB(sp - 16, 0x060B20CE, 6);
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068A5E, sp - 16);
    if (LD16(SLOT(1) + 8) == 0)
        return 0;
    GCALL1(0x060692DC, LDU16(SLOT(1) + 10));
    return GCALL1(0x06022EDA, 1);
}

int f06043194(void)
{
    FRAME(sp, 16);

    COPYB(sp - 16, 0x060B20DA, 6);
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068A5E, sp - 16);
    if (LD16(SLOT(2) + 8) == 0)
        return 0;
    GCALL1(0x060692DC, LDU16(SLOT(2) + 10));
    return GCALL1(0x06022EDA, 2);
}

int f0604327A(void)
{
    FRAME(sp, 12);

    COPYB(sp - 12, 0x060B20E8, 8);
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068A5E, sp - 12);
    return GCALL1(0x06022EDA, 11);
}

int f06043454(void)
{
    FRAME(sp, 12);

    COPYB(sp - 12, 0x060B20F8, 8);
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068A5E, sp - 12);
    return GCALL1(0x06022EDA, 10);
}

int f060437A6(int n)
{
    int obj = OBJ(LDU16(0x060D7C68 + 12));
    int top;

    ST8(OBJ(LDU16(0x060D7C68 + 8)) + 78, n >= 6 ? 10 : 242 + n);
    ST16(obj + 22, LD16(obj + 18));
    top = LD16(obj + 18) + (n >= 6 ? 29 : n + 14);
    ST16(obj + 26, top);
    return top;
}

int f06043BFC(int n)
{
    if (LD16(0x060D7B5C + (short)(n * 24)))
        return -1;
    return 0;
}

void f06045208(unsigned short value)
{
    gaddr e = 0x060B65B8;
    int i = 0;

    do {
        GCALL3(0x060090A8, LDU16(e), LDU16(e + 2), value);
        i++;
        e += 4;
    } while (AGAIN(i < 4));
}

void f06045C70(unsigned short first)
{
    int i = 0;

    do {
        int flags = 0x060EC8B0 + (unsigned short)(first + i) * 2;

        ST16(flags, LDU16(flags) & ~0x80);
    } while (AGAIN(++i < 2));
}

int f06045CBC(short from, short to, short step)
{
    int count = (short)(DIVS(to - from, step) + 1);

    return (unsigned short)GCALL1(0x0600A0EC, count) * (unsigned short)step + from;
}

void f060460AA(int base)
{
    unsigned int i = 0;
    int p = base + 64;

    do {
        if ((unsigned short)p < 0x1000)
            GCALL1(0x06060038, p);
        i++;
        p += 64;
    } while (AGAIN(i < 5));
}

void f0604655A(void)
{
    GCALL1(0x0600996A, 193);
    ST32(0x060D7BA8, 0x0604656E);
}

int f060465AC(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 4);

    if (!GET(Slot24, s, w12))
        return 0;
    return LDU16(OBJS + 60 + (unsigned short)(GET(Slot24, s, obj) * 84)) >= 0xFF00;
}

int f06046712(void)
{
    gaddr obj = LD32(TASK_OBJ);
    int v;
    int left;

    if (!TGET(h20)) {
        if (LDU16(obj + 68) > 0) {
            v = LD16(obj + 68) - 16;
            ST16(obj + 68, v);
            ST16(obj + 70, v);
            return 70;
        }
        TSET(h14, TGET(h10));
        GCALL1(0x0600C9AA, TGET(h10));
        GCALL3(0x0600D0E4, TGET(h8), LD16(0x060D7EB4), LD16(0x060D7EB6));
        obj = LD32(TASK_OBJ);
        ST16(obj + 68, 0);
        ST16(obj + 70, 0);
        TSET(h20, 0x384);
        TSET(h12, 0);
        if (!GCALL1(0x0600A0EC, 2)) {
            TSET(h4, 0x708);
            return 0x708;
        }
        TSET(h4, 0x384);
        return 0x384;
    }
    if (LD16(obj + 68) && LDU16(obj + 68) >= 0x100) {
        ST16(obj + 68, 0x100);
        ST16(obj + 70, 0x100);
        GCALL2(0x06046834, obj, 0x100);
    } else {
        v = LD16(obj + 68) + 16;
        ST16(obj + 68, v);
        ST16(obj + 70, v);
    }
    left = (short)TGET(h20) - 1;
    TSET(h20, left);
    return left;
}

void f06046834(void)
{
    unsigned short blocked[8];
    unsigned short open[8];
    int base;
    int facing;
    int mask;
    int dir;
    int n;
    int i;
    int result;

    if ((unsigned short)GCALL0(0x060469A4) == 0)
        return;
    base = TGET(h14);
    facing = TGET(h12) & 255;
    mask = (unsigned short)GCALL1(0x06046A5C, base);
    if (mask == 0) {
        TSET(h16, 0);
        result = facing;
    } else {
        i = 0;
        do {
            blocked[i] = 0;
            i++;
        } while (AGAIN(i < 8));
        dir = 0;
        do {
            if (SHL(1, dir) & mask) {
                blocked[(dir * 2 - 1) & 7] = 1;
                blocked[dir * 2] = 1;
                blocked[dir * 2 + 1] = 1;
            }
            dir++;
        } while (AGAIN(dir < 4));
        result = facing;
        if (TGET(h16) == 0 || blocked[facing] != 0) {
            blocked[facing ^ 4] = 1;
            if (TGET(h16) == 0) {
                TSET(h16, GCALL1(0x0600A0EC, 3) + 2);
            } else {
                i = 1;
                do {
                    i += 2;
                    blocked[i - 2] = 1;
                } while (AGAIN(i < 7));
            }
            n = 0;
            i = 0;
            if (i < 8) {
                do {
                    if (blocked[i] == 0) {
                        open[n] = i;
                        n++;
                    }
                    i++;
                } while (AGAIN(i < 8));
            }
            if (n == 0)
                result = 4 ^ facing;
            else
                result = open[GCALL1(0x0600A0EC, n)];
        }
        if (TGET(h16) != 0)
            TSET(h16, TGET(h16) - 1);
    }
    TSET(h12, result);
    TSET(h14, LD16(0x060B671A + (unsigned short)result * 2) + base);
}

int f060469A4(void)
{
    gaddr obj;
    int target;

    GCALL1(0x0600C9AA, (short)TGET(h14));
    GCALL2(0x0600CA32, LDU16(0x060D7EB4), LDU16(0x060D7EB6));
    obj = LD32(TASK_OBJ);
    target = LD16(0x060D7E88);
    if (LD16(obj + 16) >= target) {
        if (LD16(obj + 16) > target)
            ST16(obj + 16, LD16(obj + 16) - 1);
    } else {
        ST16(obj + 16, LD16(obj + 16) + 1);
    }
    target = LD16(0x060D7E8A);
    obj = LD32(TASK_OBJ);
    if (LD16(obj + 18) >= target) {
        if (LD16(LD32(TASK_OBJ) + 18) > target)
            ST16(LD32(TASK_OBJ) + 18, LD16(LD32(TASK_OBJ) + 18) - 1);
    } else {
        ST16(LD32(TASK_OBJ) + 18, LD16(LD32(TASK_OBJ) + 18) + 1);
    }
    return LD16(LD32(TASK_OBJ) + 18) == LD16(0x060D7E8A) && LD16(LD32(TASK_OBJ) + 16) == LD16(0x060D7E88);
}

int f06046A5C(unsigned short cell)
{
    gaddr flags = 0x060EE8B0 + cell * 2;
    int mask = 0;
    int i = 0;
    int kind;

    do {
        kind = LD16(flags + LD16(0x060B672A + i * 2) * 2) & 15;
        if (kind == 13 || kind == 14)
            mask |= SHL(1, DIVU(i, 3));
        i++;
    } while (AGAIN(i < 12));
    return mask;
}

void f06046C7E(void)
{
    if (GCALL2(0x06022F1C, 0, 0x06046D50) < 0)
        return;
    TSET(h6, 0);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A6, LD16(0x060FB8A6) & 0xFFF3);
    GCALL2(0x0609BBC0, 8, 1);
    GCALL1(0x0609AFCC, 0x060B6790);
    TSET(h6, 0);
    GCALL1(0x06046CD8, 128);
    GCALL0(0x06046D50);
    TSET(h10, 0);
}

void f06046CD8(short value)
{
    ST16(SLOTS + 12, value);
}

int f06046D50(void)
{
    FRAME(sp, 12);
    int q;

    ST16(sp - 12, LD16(0x060C0348));
    ST16(sp - 10, LD16(0x060C034A));
    q = GCALL2(0x060980C8, 0x10000, LDU16(0x060D7B54) << 8);

    return GCALL4(0x06047884, 8, q, q, sp - 12);
}

int f06047884(int which, int x, int y, gaddr pos)
{
    int a = x & 0x0007FF00;
    int b = y & 0x0007FF00;
    int px = (LD16(pos) + 160) << 16;
    int py;

    px = (px - GCALL2(0x060980B4, a, 0x00A00000)) & 0x07FFFF00;
    py = (LD16(pos + 2) + 112) << 16;
    py = (py - GCALL2(0x060980B4, b, 0x00700000)) & 0x07FFFF00;
    if (which == 4) {
        ST32(0x060C0328, px);
        ST32(0x060C0328 + 4, py);
        ST32(0x060C0328 + 8, a);
        ST32(0x060C0328 + 12, b);
    } else if (which == 8) {
        ST32(0x060C0328 + 16, px);
        ST32(0x060C0328 + 20, py);
        ST32(0x060C0328 + 24, a);
        ST32(0x060C0328 + 28, b);
    }
    ST16(0x060BB8FC, 1);
    return which;
}

int f060482A6(unsigned short a, unsigned short b)
{
    if (b < 6)
        return 26;
    return a >= 5 ? 30 : 22;
}

int f060482C4(unsigned short n)
{
    return MODS(n, 5) * 3 + 5;
}

void f06049694(unsigned char flag)
{
    if (flag)
        ST8(0x060C1044, LD8(POINTS + 3 + (unsigned char)LD8(0x060C122C) * 24));
    else
        ST8(0x060C1044, 10);
}

int f060496E4(void)
{
    unsigned char i = LD8(0x060C063F);

    if ((LD32(0x060C1048) & 0xC00) == 0x400)
        return LD32(0x060B68C0 + (unsigned char)LD8(0x060C064A + i) * 4);
    return LD32(0x060B68F0 + ((unsigned char)LD8(0x060C0640 + i) >> 2) * 4);
}

void f06049B38(gaddr p)
{
    ST16(OBJ(LDU16(p + 18)) + 4, LD32(TICK) & 1 ? 40 : 60);
}

void f06049E8C(gaddr p, unsigned char kind)
{
    gaddr a = OBJ(LDU16(p + 2));
    gaddr b = OBJ(LDU16(p + 70));
    gaddr q;
    int v;

    v = HELPER(GCALL1(0x0606CE8C, kind) >> 13);
    ST16(a + 38, v);
    ST16(b + 38, v);
    q = p + 20;
    do {
        ST16(OBJ(LDU16(q)) + 38, v);
        q += 2;
    } while (AGAIN(q < p + 38));
}

void f0604A8B4(short width, short height, gaddr slots, unsigned short mode)
{
    FRAME(sp, 72);
    gaddr table = sp - 56;
    int scale = DIVS(width << 8, 128) - 256;
    int ratio = DIVS(height << 8, 136);
    short i = 0;
    int k = 0;
    gaddr obj;
    int t;
    int top;
    int bottom;
    int half_w;
    int half_h;
    int s;

    COPYB(table, 0x060B22BE, 20);
    while (i < LDU8(0x060C1760)) {
        POLL();
        obj = OBJ(LDU16(slots + k + 20));
        t = LD16(table + k);
        top = t * 24 - 116;
        bottom = top + 20;
        top -= 12;
        half_w = (t & 1) ? 120 : 64;
        half_h = (t & 1) ? 72 : 16;
        if (mode == 64) {
            ST16(obj + 32, top);
            ST16(obj + 20, top);
            ST16(obj + 28, bottom);
            ST16(obj + 24, bottom);
            ST16(obj + 26, -half_w);
            ST16(obj + 22, -half_w);
            ST16(obj + 34, -half_h);
            ST16(obj + 30, -half_h);
        } else {
            s = scale * DIVS(half_w << 8, 136);
            ST16(obj + 20, (short)((unsigned int)(s * top) >> 16) + top);
            ST16(obj + 24, (short)((unsigned int)(s * bottom) >> 16) + bottom);
            s = scale * DIVS(half_h << 8, 136);
            ST16(obj + 32, (short)((unsigned int)(s * top) >> 16) + top);
            ST16(obj + 28, (short)((unsigned int)(s * bottom) >> 16) + bottom);
            ST16(obj + 26, HELPER((ratio * half_w) >> 8));
            ST16(obj + 22, LD16(obj + 26));
            ST16(obj + 34, HELPER((ratio * half_h) >> 8));
            ST16(obj + 30, LD16(obj + 34));
            ST16(obj + 36, 160);
            ST16(obj + 38, 160);
        }
        k += 2;
        ST16(obj + 24, LD16(obj + 24) - 1);
        ST16(obj + 28, LD16(obj + 28) - 1);
        ST16(obj + 30, LD16(obj + 30) - 1);
        ST16(obj + 34, LD16(obj + 34) - 1);
        i++;
    }
}

void f0604ABAC(short id, short px, short py, unsigned char turn)
{
    FRAME(sp, 44);
    int angle = LDU16(sp + 2) & 255;
    int x = px << 16;
    int y = py << 16;
    int west, east, sx, sy, north, south;
    int tx, ty;
    gaddr obj;

    if (angle & 127) {
        int t = LD32(0x060B9108 + angle * 4);
        int s = GCALL2(0x060980B4, GCALL1(0x0609812C, t), x);
        int c = GCALL2(0x060980B4, GCALL1(0x0609816C, t), x);

        sx = s;
        east = c;
        west = -c;
        sy = -s;
    } else {
        west = (angle & 128) ? x : -x;
        east = (angle & 128) ? -x : x;
        sx = 0;
        sy = 0;
    }
    if (turn & 127) {
        int t = LD32(0x060B9108 + turn * 4);
        int s = GCALL1(0x0609812C, t);
        int lift = -GCALL2(0x060980B4, GCALL1(0x0609816C, t), y);

        north = lift + GCALL2(0x060980B4, s, sx);
        south = lift + GCALL2(0x060980B4, s, sy);
    } else {
        north = (turn & 128) ? y : -y;
        south = north;
    }
    tx = (short)((unsigned)west >> 16);
    ty = (short)((unsigned)east >> 16);
    obj = OBJ(id);
    ST16(obj + 20, tx);
    ST16(obj + 24, ty - 1);
    ST16(obj + 28, -1 - tx);
    ST16(obj + 32, -ty);
    tx = (short)((unsigned)north >> 16);
    ty = (short)((unsigned)south >> 16);
    ST16(obj + 22, tx);
    ST16(obj + 26, ty);
    ST16(obj + 30, -1 - tx);
    ST16(obj + 34, -1 - ty);
}

void f0604AFE2(unsigned int n, gaddr list)
{
    int value = (DIVU(n, 10) << 7) + 128;
    short i;

    list += 20;
    for (i = 0; i < (unsigned char)LD8(0x060C1760); i++, list += 2) {
        POLL();
        ST16(OBJ(LDU16(list)) + 62, value);
    }
}

int f0604B4CC(short n, gaddr list)
{
    int obj = OBJ(LDU16(list + 20 + n * 2));
    int y = LD16(obj + 16);

    ST16(obj + 16, y > 160 ? y + 1 : y - 1);
    if (LD16(obj + 16) > 0x154)
        ST8(0x060C1764 + n, 0);
    y = LD16(obj + 16);
    if (y < -20) {
        ST8(0x060C1764 + n, 0);
        return n;
    }
    return y;
}

int f0604CBD2(void)
{
    int best = 0;
    int i = 0;

    do {
        int v = (short)GCALL1(0x0604CC00, i);

        i++;
        if (best < v)
            best = v;
    } while (AGAIN(i < 10));
    return best;
}

int f0604CC00(unsigned char who)
{
    int sum = 0;
    int i = 0;

    do {
        sum += LD16(0x060E1B6A + (unsigned char)(who * 20) + i * 2);
    } while (AGAIN(++i < 10));
    return sum;
}

/* Position from 1 of the pair in a table of halfword pairs that ends at a negative first half, 0 if absent. */
int f0604D47C(short a, short b)
{
    int p = 0x060B69CC;
    int n = 1;

    while (LD16(p) >= 0) {
        POLL();
        if (LD16(p) == a && LD16(p + 2) == b)
            break;
        n++;
        p += 4;
    }
    return LD16(p) < 0 ? 0 : n;
}

int f0604D4D4(int a, short limit)
{
    int count = 0;
    int i;

    if ((short)GCALL2(0x0604D47C, a, limit) != 0)
        return 0;
    if (limit >= 0) {
        i = 0;
        do {
            if ((short)GCALL2(0x0604D47C, a, i) == 0)
                count++;
            i++;
        } while (AGAIN((short)i <= limit));
    }
    return count;
}

int f0604D55E(short i)
{
    return LD16(0x060B6A00 + i * 2);
}

void f0604D568(void)
{
    ST8(0x060C179A, 0);
    ST8(0x060C179B, 0);
    ST8(0x060C029E, 0);
    ST8(0x060C029F, 0);
    ST8(0x060C179C, 0);
    ST8(0x060C179D, 0);
}

void f0604D584(void)
{
    ST8(0x060C179C, 0);
    ST8(0x060C179D, 0);
}

int f0604D590(void)
{
    if (LDU16(0x060BF5EA))
        return 1;
    return ((unsigned char)LD8(0x060C179C) << 4) + (unsigned char)LD8(0x060C179D)
         > ((unsigned char)LD8(0x060C029C) << 4) + (unsigned char)LD8(0x060C029D);
}

int f0604D5D4(unsigned short x, unsigned short y, unsigned short x2, unsigned short y2)
{
    if (x2 != x || y2 != y + 1)
        return 1;
    POLL();
    if (LD16(0x060BF5EA))
        return 1;
    return (LD8(0x060C179C) & 255) * 16 + (LD8(0x060C179D) & 255) > x * 16 + y2;
}

void f0604D602(void)
{
    int next;

    if ((GCALL0(0x0604D590) & 0xFFFF) != 0)
        return;
    if (LD16(0x060BF5EA) != 0)
        return;
    next = GCALL2(0x0604D736, LD8(0x060C029C) & 255, LD8(0x060C029D) & 255) & 255;
    ST8(0x060C179C, LD8(0x060C029C));
    if (next == 0)
        ST8(0x060C179C, LD8(0x060C179C) + 1);
    ST8(0x060C179D, next);
}

int f0604D644(unsigned short a, unsigned short b)
{
    unsigned int hi = LD8(0x060C029E) & 255;

    if (hi > a)
        return 1;
    if (hi == a)
        return (LD8(0x060C029F) & 255) > b;
    return 0;
}

void f0604D66C(unsigned char a, unsigned char b)
{
    ST8(0x060C029E, a);
    ST8(0x060C179C, a);
    ST8(0x060C029F, b);
    ST8(0x060C179D, b);
}

int f0604D6AC(void)
{
    int a = LD8(0x060C029C);
    int b = LD8(0x060C029D);
    int c, d, best;
    int result = 0;

    if (b != (short)GCALL1(0x0604D55E, a)) {
        c = a;
        d = b + 1;
    } else {
        c = a + 1;
        d = 0;
    }
    best = LD8(0x060C179A) & 255;
    if (best >= c) {
        if (best == c && (LD8(0x060C179B) & 255) < d) {
            result = 1;
            ST8(0x060C179B, d);
        }
    } else {
        ST8(0x060C179A, c);
        ST8(0x060C179B, d);
        result = a == c ? 1 : 2;
    }
    return result;
}

int f0604D736(int a, unsigned int n)
{
    if (n < (unsigned int)(short)GCALL1(0x0604D55E, a))
        return n + 1;
    return 0;
}

void f0604D758(void)
{
    int a = LD8(0x060C029C);
    int b = LD8(0x060C029D);
    int best;

    GCALL2(0x0604D780, a, b);
    b = LD8(0x060C029D) & 255;
    a = LD8(0x060C029C) & 255;
    POLL();
    best = LD8(0x060C029E) & 255;
    if (best >= a) {
        if (best == a && (LD8(0x060C029F) & 255) < b)
            ST8(0x060C029F, b);
    } else {
        ST8(0x060C029E, a);
        ST8(0x060C029F, b);
    }
}

/* The same greater-pair rule as f060236DE, on 179A and 179B. */
void f0604D780(unsigned int a, unsigned int b)
{
    unsigned char best = LD8(0x060C179A);

    if (best >= a) {
        if (best == a && (unsigned char)LD8(0x060C179B) < b)
            ST8(0x060C179B, b);
    } else {
        ST8(0x060C179A, a);
        ST8(0x060C179B, b);
    }
}

int f0604D7A6(unsigned char a, unsigned char b)
{
    ST8(0x060C17A0, a);
    ST8(0x060C17A1, b);
    ST8(0x060C179F, 1);
    return 0x060C179F;
}

void f0604D7BE(void)
{
    ST8(0x060C179F, 0);
}

unsigned char f0604D7C6(void)
{
    return LD8(0x060C179F);
}

int f0604D898(void)
{
    return LD8(0x060C179A) || LD8(0x060C179B);
}

void f0604D8B2(void)
{
    POLL();
    ST8(0x060C17A0, LD8(0x060C179A));
    ST8(0x060C17A1, LD8(0x060C179B));
    ST8(0x060C179F, 1);
}

int f0604D8C4(int n)
{
    int best;

    if ((short)n >= (LD8(0x060C179A) & 255))
        best = LD8(0x060C179B) & 255;
    else
        best = GCALL1(0x0604D55E, n);
    return best + 1;
}

int f0604D922(short n)
{
    return n >= (unsigned char)LD8(0x060C179A) ? 0 : -1;
}

int f0604D9D0(int kind, int row, int col, gaddr out)
{
    int last = row == 4;
    short base = LD16(0x060B6A2A + row * 4);
    int x = kind;

    if (kind == 0) {
        x = !last ? col * 2 + base - 1 : (LD8(0x060B6A3E + col) + base) + 1;
    } else if (kind == 1) {
        x = !last ? col * 2 + base - 3 : (LD8(0x060B6A3E + col - 1) + base) + 1;
    } else if (kind == 2) {
        x = LD16(0x060B6A2A + (row * 2 + 1) * 2) + base;
    }
    if (row == 0)
        x--;
    ST16(out, (short)x >= base ? 1 : 0);
    return x;
}

void f0604DFFE(gaddr p)
{
    int obj = OBJ(LDU16(p + 10));
    int v = (LD16(0x2600603A) & 31) - 16;
    int d = v * v;

    ST16(obj + 70, 0x180 - (d > 192 ? 192 : d));
    ST16(obj + 68, 0x100 + (d > 96 ? d - 96 : 0));
}

int f0604E250(short mode, short cell, short limit, unsigned short buttons)
{
    short ids[3];
    int bits, mask, k;
    short index;
    int exact = 0, partial = 0;

    ids[0] = cell;
    ids[1] = cell - 1;
    ids[2] = cell + 1;
    if (mode == 4) {
        ids[1] = LD8(0x060B6AB8 + (cell + 1) * 2);
        ids[2] = LD8(0x060B6AB8 + (cell + 1) * 2 + 1);
    }
    index = cell >= 0 ? cell + 1 : 0;
    if (index > 10)
        index = 10;
    mask = LDU16(0x060B6A4A + (signed char)(mode * 22) + index * 2);
    bits = ((buttons & 0x8000) ? 2 : 0) | ((buttons & 0x4000) ? 1 : 0) | ((buttons & 0x1000) ? 4 : 0)
        | ((buttons & 0x2000) ? 8 : 0);
    for (k = 1; k < 3; k++) {
        POLL();
        if (k == 1 ? ids[1] >= -1 : ids[2] <= limit) {
            int want = mask & 15;
            int hit = bits & want;

            if (hit)
                partial = k;
            if (hit == want)
                exact = k;
        }
        mask >>= 4;
    }
    return ids[exact ? exact : partial];
}

void f0604EA00(gaddr list, int unused, short hot, short max)
{
    int i = 0;

    do {
        int obj = OBJ(LDU16(list + 20 + i * 2));
        int size;

        if (i == 4) {
            size = LD16(obj + 68) << 1;
            ST16(obj + 68, size);
            ST16(obj + 70, size);
        }
        if (hot != i) {
            if (i > max) {
                ST16(obj + 70, 128);
                ST16(obj + 68, 128);
            } else {
                if (LDU16(obj + 68) > 0x100)
                    ST16(obj + 68, LD16(obj + 68) - 32);
                ST16(obj + 70, LD16(obj + 68));
                ST16(obj + 4, 0x1E8);
            }
        } else {
            if (LDU16(obj + 68) < 0x200)
                ST16(obj + 68, LD16(obj + 68) + 32);
            ST16(obj + 70, LD16(obj + 68));
            ST16(obj + 4, 0x1E9);
        }
        if (i == 4) {
            size = LDU16(obj + 68) >> 1;
            ST16(obj + 68, size);
            ST16(obj + 70, size);
        }
    } while (AGAIN(++i < 5));
}

void f0604EB80(void)
{
}

void f0604F07C(void)
{
    ST16(0x060DFE18, LD16(0x060FB8C2));
    ST16(0x060DFE1A, LD16(0x060FB8C4));
    ST16(0x060DFE1C, LD16(0x060FB8BA));
    ST16(0x060DFE1E, LD16(0x060FB8BC));
    ST16(0x060DFE20, LD16(0x060FB8AA));
    ST16(0x060DFE22, LD16(0x060FB8A8));
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
}

void f0604F0A6(void)
{
    ST16(0x060FB8C2, LD16(0x060DFE18));
    ST16(0x060FB8C4, LD16(0x060DFE1A));
    ST16(0x060FB8BA, LD16(0x060DFE1C));
    ST16(0x060FB8BC, LD16(0x060DFE1E));
    ST16(0x060FB8AA, LD16(0x060DFE20));
    ST16(0x060FB8A8, LD16(0x060DFE22));
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 0x98);
}

unsigned short f0604F1EE(void)
{
    return (unsigned char)LD8(0x060C02A0) != 255;
}

/* Folds the six bytes at 060C17A4 into four: their sum, OR, AND NOT and XOR. */
void f0604FC44(gaddr out)
{
    int i;

    ST8(out + 2, 0);
    ST8(out + 1, 0);
    ST8(out, 0);
    ST8(out + 3, 0xFF);
    i = 0;
    do {
        ST8(out, LD8(out) + LD8(0x060C17A4 + i));
        ST8(out + 1, LD8(out + 1) | LD8(0x060C17A4 + i));
        ST8(out + 2, LD8(out + 2) & ~LD8(0x060C17A4 + i));
        ST8(out + 3, LD8(out + 3) ^ LD8(0x060C17A4 + i));
    } while (AGAIN(++i < 6));
}

int f0604FC96(void)
{
    FRAME(sp, 12);
    gaddr buf = sp - 12;
    int i = 4;

    GCALL1(0x0604FC44, buf);
    do {
        if (LD8(0x060C17A9 + i) != LD8(buf + i - 1))
            break;
    } while (AGAIN(--i > 0));
    return i != 0 ? 7 : 0;
}

void f0604FCD4(void)
{
    int i = 0;

    do {
        ST8(0x060C17A4 + i * 2, 0xFF);
        ST8(0x060C17B0 + i * 2, 0xFF);
    } while (AGAIN(++i < 3));
    ST8(0x060C17AB, 0);
    ST8(0x060C17B7, 0);
}

void f0604FD0C(gaddr p)
{
    ST16(p, LD8(0x060C17AE) & 255);
    ST16(p + 2, LD8(0x060C17AF) & 255);
}
