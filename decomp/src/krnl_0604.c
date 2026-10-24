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

int f06040AEE(void)
{
    int r0, r1, r2, r3, r4, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r3 = LD32(0x060D7E64);
    r13 = 0x060D7E60;
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 0x400));
    r14 = LD32(0x060D7E60);
    r0 = LD16(r14 + 10);
    if (!((r0 & r0) == 0)) {
        r0 = LD16(r14 + 10);
        if (!((r0 & 0xFFFF) == 1)) {
            r0 = LD16(r14 + 16);
            if ((r0 & r0) == 0) {
                r0 = LD16(r14 + 12);
                if ((r0 & r0) == 0) {
                    r0 = 0;
                    ST16(r14 + 10, 0);
                }
            } else {
                r0 = LD16(r14 + 16);
                r0 = r0 - 1;
                ST16(r14 + 16, r0);
            }
        } else {
            r0 = LD16(r14 + 16);
            if ((r0 & r0) == 0) {
                r0 = LD16(r14 + 12);
                if ((r0 & r0) == 0) {
                    SETR(13, r13);
                    SETSP((sp - 12));
                    SETPR(0x06040B82);
                    r0 = GCALL0(0x06040C34);
                    r2 = LD32(r13);
                    ST16(r2 + 12, 1);
                }
            } else {
                r0 = LD16(r14 + 16);
                ST16(r14 + 16, (r0 - 1));
            }
            r0 = 60;
            r3 = LD32(0x060D7E64);
            r1 = LD16(60 + r3);
            if ((r1 & 0xFFFF) >= 0xFF00) {
                r1 = LD32(r13);
                ST16(r1 + 16, 0);
                r4 = LD32(r13);
                r0 = LD16(r4 + 8);
                SETR(13, r13);
                SETSP((sp - 12));
                SETPR(0x06040BAA);
                r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 99);
                r0 = 2;
                r3 = LD32(r13);
                ST16(r3 + 10, 2);
            }
        }
    } else {
        r0 = LD16(r14 + 14);
        SETSP((sp - 12));
        r0 = GCALL1(0x06040DEE, (r0 + 64));
        ST16(r14 + 18, r0);
        r0 = r0 & 0xFFFF;
        if (!((r0 & r0) == 0)) {
            r4 = LD32(r13);
            r0 = LD16(r4 + 8);
            SETR(13, r13);
            SETSP((sp - 12));
            SETPR(0x06040B28);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 100);
            r2 = LD32(r13);
            ST16(r2 + 10, 1);
            r0 = 40;
            r3 = LD32(r13);
            ST16(r3 + 16, 40);
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06040BD4(short n, short x)
{
    GCALL2(0x06022F1C, n, 0x0603DDA6);
    ST16(LD32(TASK_OBJ) + 44, 1);
    ST16(LD32(TASK_OBJ) + 46, 0x380);
    GCALL2(0x0606AAC8, LD32(TASK_OBJ), 3);
    TSET(h16, x);
}

int f06040CE0(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r13 = 0x060D7E64;
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 10);
    r12 = r0;
    r5 = LD32(0x060D7E64);
    if (!(((short)r12) > 0)) {
        r0 = 60;
        r2 = LD16(60 + r5);
        if ((r2 & 0xFFFF) >= 0xFF00) {
            r0 = LD16(r4 + 16);
            r0 = (short)((((r0 << 1) + r0) << 2) << 1);
            r2 = LD16(r0 + 0x060D7B54);
            ST16(r0 + 0x060D7B54, (r2 - 1));
            r4 = LD32(r14);
            r0 = LD16(r4 + 8);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x06040DDE);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
            r3 = LD32(r14);
            ST32(r3, 0x0603DDA6);
        }
    } else {
        r0 = LD16(r4 + 12);
        r6 = r0;
        r3 = ((((short)r12) >> 1) >> 1) + 128;
        r12 = r12 + r6;
        ST16(70 + r5, r3);
        ST16(68 + r5, r3);
        r4 = LD32(r13);
        r0 = LD16(r4 + 18);
        r1 = LD32(r14);
        r3 = r0 << 16;
        r0 = LD16(r4 + 14);
        r4 = r3;
        r3 = LD32(r13);
        r4 = r4 + (r0 & 0xFFFF);
        r0 = LD16(r1 + 18);
        r4 = r4 - ((r0 & 0xFFFF) << 8);
        ST16(r3 + 18, ((int)((unsigned)r4 >> 16)));
        r3 = LD32(r13);
        ST16(r3 + 14, r4);
        r3 = LD32(r13);
        ST16(38 + r3, (-(((((((short)r12) >> 1) >> 1) >> 1) >> 1) >> 1)));
        r3 = LD32(r14);
        ST16(r3 + 10, r12);
        r3 = LD32(r14);
        ST16(r3 + 12, (r6 - 1));
        SETSP((sp - 16));
        r0 = GCALL0(0x06040E4A);
        r4 = r0;
        r0 = (short)r0;
        if (!((r0 & r0) == 0)) {
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x06040D6C);
            r0 = GCALL1(0x06040E7C, r4);
        }
        if (!(((short)r12) > 0)) {
            r4 = LD32(r14);
            r0 = LD16(r4 + 8);
            SETR(13, r13);
            SETSP((sp - 16));
            SETPR(0x06040D7E);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 108);
            r0 = 15;
            r2 = LD32(r13);
            ST16(r2 + 4, 15);
        }
    }
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f06040F7C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    r0 = GCALL2(0x06022F1C, 20, 0x06041002);
    r5 = r0;
    r2 = LD32(0x060D7E60);
    ST16(r2 + 20, 128);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 18, 0);
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 18);
    ST16((0x060C1742 + ((r0 & 0xFFFF) << 1)), 0);
    r2 = LD32(0x060D7E60);
    r0 = LD16(r2 + 18);
    ST16((0x060C1746 + ((r0 & 0xFFFF) << 1)), r5);
    r2 = LD32(0x060D7E64);
    ST16(44 + r2, 1);
    r2 = LD32(0x060D7E64);
    ST16(46 + r2, 0x380);
    r2 = LD32(0x060D7E64);
    ST16(r2 + 4, 21);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 10, 0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 14, 0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 12, 0);
    r8 = LD32(0x060D7E60);
    SETSP((sp - 12));
    r0 = GCALL0(0x060413C6);
    ST16((r8 + 16), r0);
    r8 = LD32(0x060D7E60);
    SETSP((sp - 12));
    r0 = GCALL1(0x0604142A, 4);
    ST16((r8 + 12), r0);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 0);
    return r0;
}

int f06041128(void)
{
    int r0, r2, r3, r4, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    SETSP((sp - 24));
    r0 = GCALL2(0x06022F1C, 21, 0x060411C6);
    ST16(sp - 24, r0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 18, 1);
    r3 = LD32(0x060D7E64);
    ST16(44 + r3, 1);
    r3 = LD32(0x060D7E64);
    ST16(46 + r3, 0x380);
    r3 = LD32(0x060D7E64);
    ST16(r3 + 4, 20);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 10, 0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 14, 0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 12, 0);
    r8 = LD32(0x060D7E60);
    SETSP((sp - 24));
    r0 = GCALL0(0x060413C6);
    ST16((r8 + 16), r0);
    r8 = LD32(0x060D7E60);
    SETSP((sp - 24));
    r0 = GCALL1(0x0604142A, 3);
    ST16((r8 + 12), r0);
    r3 = LD32(0x060D7E64);
    ST16(38 + r3, 8);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(12, 0);
    SETR(14, 0x060D7E60);
    SETSP((sp - 24));
    SETPR(0x06041194);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 20, 64);
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 18);
    ST16((0x060C1742 + ((r0 & 0xFFFF) << 1)), 0);
    r2 = LD32(0x060D7E60);
    r0 = LD16(r2 + 18);
    r3 = LD16(sp - 24);
    r0 = (r0 & 0xFFFF) << 1;
    ST16((0x060C1746 + r0), r3);
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06041264(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(8));
    ST32((sp - 28), PR());
    r14 = 0x060D7E60;
    r6 = LD32(0x060D7E60);
    r11 = 0x060D7E64;
    r0 = LD16(r6 + 18);
    r5 = LD32(0x060D7E64);
    r7 = ((((r0 & 0xFFFF) << 2) << 1) << 1) + 0x060B6090;
    r10 = r7 + 12;
    r1 = LD16(r10);
    r2 = LD16(50 + r5);
    r13 = 0;
    if ((r2 & 0xFFFF) == r1) {
        r0 = 60;
        r1 = LD16(60 + r5);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            ST16(r6 + 14, r13);
            r8 = LD32(r14);
            SETSP((sp - 28));
            r0 = GCALL0(0x060413C6);
            ST16((r8 + 16), r0);
            r3 = LD32(r11);
            ST16(62 + r3, 0x100);
            r4 = LD32(r14);
            r0 = LD16(r4 + 8);
            SETR(14, r14);
            SETSP((sp - 28));
            SETPR(0x0604135C);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
            r2 = LD32(r14);
            r0 = LD16(r2 + 18);
            if (!((r0 & r0) == 0)) {
                r8 = LD32(r14);
                SETSP((sp - 28));
                r0 = GCALL1(0x0604142A, 3);
                ST16((r8 + 12), r0);
                r0 = 64;
                r3 = LD32(r14);
                ST16(r3 + 20, 64);
                r3 = LD32(r14);
                ST32(r3, 0x060411C6);
            } else {
                r8 = LD32(r14);
                SETSP((sp - 28));
                r0 = GCALL1(0x0604142A, 4);
                ST16((r8 + 12), r0);
                r3 = LD32(r14);
                r0 = 128;
                ST16(r3 + 20, 128);
                r3 = LD32(r14);
                ST32(r3, 0x06041002);
            }
        }
    } else {
        r4 = r13;
        r0 = LD16(r7 + 8);
        r12 = 1;
        if ((r0 & r0) == 0) {
            ST16(62 + r5, r13);
            r2 = LD32(r14);
            r0 = LD16(r2 + 16);
            ST16(r2 + 16, (r0 - 1));
            r2 = LD32(r14);
            r0 = LD16(r2 + 16);
            if ((r0 & r0) == 0) {
                r4 = r12;
            }
        } else {
            r0 = LD16(r6 + 14);
            r0 = r0 & 0xFFFF;
            if (!(r0 == 3)) {
                r2 = LD16(50 + r5);
                r0 = LD16(r6 + 14);
                r1 = ((((r0 & 0xFFFF) - 1) << 1) << 1) + r7;
                r0 = LD16(r6 + 12);
                r0 = (r0 & 0xFFFF) << 1;
                r1 = LD16(r0 + r1);
                if (!((r2 & 0xFFFF) == r1)) {
                    r4 = r12;
                } else {
                    ST16(62 + r5, 0x400);
                    r0 = 60;
                    r2 = LD32(r11);
                    r1 = LD16(60 + r2);
                    if ((r1 & 0xFFFF) >= 0xFF00) {
                        r4 = r12;
                    }
                }
            } else {
                r4 = r12;
            }
        }
        if (!((((short)r4) & ((short)r4)) == 0)) {
            r4 = LD32(r14);
            r0 = LD16(r4 + 10);
            SETSP((sp - 28));
            r0 = GCALL1(0x060692DC, (r0 & 0xFFFF));
            r2 = LD32(r14);
            ST16(r2 + 10, r13);
            r5 = LD16(r10);
            r4 = LD32(r14);
            r0 = LD16(r4 + 8);
            SETR(11, r11);
            SETSP((sp - 28));
            SETPR(0x06041324);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
            r2 = LD32(r11);
            r0 = 62;
            ST16(62 + r2, 0x100);
        }
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

int f060417D0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060417DA);
    r0 = GCALL2(0x060234DE, 18, 57);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06041AE4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06041AEE);
    r0 = GCALL2(0x060234DE, 35, 51);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06041B92(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06041B9C);
    r0 = GCALL2(0x060234DE, 37, 40);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06041C5E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06041C68);
    r0 = GCALL2(0x060234DE, 53, 31);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06041D8C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06041D96);
    r0 = GCALL2(0x060234DE, 44, 18);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06041E6A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06041E74);
    r0 = GCALL2(0x060234DE, 22, 4);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f0604203E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06042048);
    r0 = GCALL2(0x060234DE, 13, 36);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06042124(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0604212E);
    r0 = GCALL2(0x060234DE, 14, 10);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06042402(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0604240A);
    r0 = GCALL0(0x06039FC4);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
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

int f060429B0(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 20));
    r0 = COPYB((sp - 20), 0x060B20C2, 6);
    SETSP((sp - 20));
    r0 = GCALL2(0x06022F1C, 2, 0x06042A9C);
    if (r0 >= 0) {
        r2 = LD32(0x060D7E60);
        ST16(r2 + 6, 0);
        SETSP((sp - 20));
        r0 = GCALL1(0x06008A96, 1);
        SETR(13, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x060429E4);
        r0 = GCALL1(0x060689F8, (sp - 20));
        r3 = LD32(0x060D7E60);
        r0 = LD16(0x060C02DA);
        ST16(r3 + 10, r0);
        r3 = LD32(0x060D7E60);
        r0 = LD16(0x060C02DE);
        ST16(r3 + 12, r0);
        r3 = LD32(0x060D7E64);
        ST16(44 + r3, 1);
        r3 = LD32(0x060D7E64);
        ST16(46 + r3, 0x200);
        r4 = LD32(0x060D7E64);
        SETSP((sp - 20));
        r0 = GCALL1(0x0606AB24, r4);
        r4 = LD32(0x060D7E64);
        SETSP((sp - 20));
        r0 = GCALL2(0x0606AAC8, r4, 0);
        r3 = LD32(0x060D7E64);
        ST16(r3 + 4, 0x1CC);
        r4 = LD32(0x060D7E64);
        SETSP((sp - 20));
        r0 = GCALL2(0x0606950C, r4, 1);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETR(13, 0x060D7E60);
        SETR(14, 0x060D7E64);
        SETSP((sp - 20));
        SETPR(0x06042A2C);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 70);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 20));
        r0 = GCALL3(0x0600D0E4, r0, 30, 43);
        r2 = LD32(0x060D7E64);
        r0 = LD16(r2 + 16);
        ST16(r2 + 16, (r0 - 8));
        r3 = LD32(0x060D7E64);
        r0 = LD16(r3 + 18);
        r0 = r0 + 8;
        ST16(r3 + 18, r0);
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06042A9C(void)
{
    int y;

    ST16(LD32(TASK_OBJ) + 36, HELPER(((short)TGET(h10) - LD32(0x060C02D8)) >> 8));
    y = HELPER(((short)TGET(h12) - LD32(0x060C02DC)) >> 8);
    ST16(LD32(TASK_OBJ) + 38, y);
    return y;
}

int f06042AD0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    r0 = LD16(0x060D7B80);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 71);
    return r0;
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

int f06042CFE(void)
{
    gaddr mover;
    int d;
    int result;

    ST32(MOVER_PTR, OBJ(LDU16(LD32(CURRENT) + 22)));
    GCALL1(0x0606948A, LD16(LD32(CURRENT) + 22));
    mover = LD32(MOVER_PTR);
    ST16(mover + 38, GCALL0(0x060167DE));
    result = LDU16(LD32(CURRENT) + 82);
    if (result == 6) {
        d = 144 - LDU16(LD32(CURRENT) + 56);
        if ((unsigned int)d < 32) {
            result = 38;
            ST16(LD32(MOVER_PTR) + 38, LD16(LD32(MOVER_PTR) + 38) - LDU8(0x060B6400 + d));
        } else if ((unsigned int)d < 112) {
            result = LD32(MOVER_PTR);
            ST16(result + 38, LD16(result + 38) - 21);
        } else {
            result = 143;
            ST16(LD32(MOVER_PTR) + 38, LD16(LD32(MOVER_PTR) + 38) - LDU8(0x060B6400 + 143 - d));
        }
    }
    return result;
}

int f06042DC8(void)
{
    gaddr mover;
    int d;
    int result;

    ST32(MOVER_PTR, OBJ(LDU16(LD32(CURRENT) + 22)));
    GCALL1(0x0606948A, LD16(LD32(CURRENT) + 22));
    mover = LD32(MOVER_PTR);
    ST16(mover + 38, GCALL0(0x060167DE));
    result = LDU16(LD32(CURRENT) + 82);
    if (result == 4) {
        d = 144 - LDU16(LD32(CURRENT) + 56);
        if ((unsigned int)d < 64) {
            result = 38;
            ST16(LD32(MOVER_PTR) + 38, LD16(LD32(MOVER_PTR) + 38) - LDU8(0x060B6420 + d));
        } else if ((unsigned int)d < 80) {
            result = LD32(MOVER_PTR);
            ST16(result + 38, LD16(result + 38) - 30);
        } else {
            result = 143;
            ST16(LD32(MOVER_PTR) + 38, LD16(LD32(MOVER_PTR) + 38) - LDU8(0x060B6420 + 143 - d));
        }
    }
    return result;
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

int f06043342(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    r0 = LD16(0x060D7C58);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 41);
    return r0;
}

int f06043454(void)
{
    FRAME(sp, 12);

    COPYB(sp - 12, 0x060B20F8, 8);
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068A5E, sp - 12);
    return GCALL1(0x06022EDA, 10);
}

int f06043480(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x0600996A, 80);
    r0 = LD16(0x060D7C40);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 45);
    return r0;
}

int f060436E8(void)
{
    FRAME(sp, 24);
    gaddr buf = sp - 24;
    int result;

    COPYB(buf, 0x060B210A, 10);
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068A5E, buf);
    result = LD16(0x060D7C70);
    if (result != 0) {
        GCALL1(0x060692DC, LDU16(0x060D7C68 + 10));
        GCALL1(0x060692DC, LDU16(0x060D7C68 + 12));
        GCALL1(0x060692DC, LDU16(0x060D7C68 + 14));
        result = GCALL1(0x06022EDA, 12);
    }
    return result;
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

int f0604380C(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = LD32(0x060D7E60);
    r0 = LD16(r14 + 18);
    if (((r0 & 0xFFFF) & 224) == 0) {
        r0 = LD16(r14 + 18);
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x060437A6, (31 & (r0 & 0xFFFF)));
        return r0;
    } else {
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06043736);
        return r0;
    }
}

int f06043B78(int n)
{
    FRAME(sp, 16);
    gaddr buf = sp - 16;
    gaddr slot = SLOT(n);

    ST16(buf, LD16(slot + 10));
    ST16(buf + 2, LD16(slot + 12));
    ST16(buf + 4, LD16(slot + 14));
    ST16(buf + 6, -1);
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068A5E, buf);
    return GCALL1(0x06022EDA, n);
}

int f06043BFC(int n)
{
    if (LD16(0x060D7B5C + (short)(n * 24)))
        return -1;
    return 0;
}

int f06043C7A(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 12));
    r0 = COPYB((sp - 12), 0x060B2114, 8);
    ST32((sp - 16), (sp - 12));
    ST32((sp - 20), 8);
    ST32((sp - 24), 0);
    ST32((sp - 28), 32);
    ST32((sp - 32), 0);
    ST32((sp - 36), 45);
    SETSP((sp - 36));
    SETPR(0x06043CA8);
    r0 = GCALL4(0x06043854, 6, 35, 48, 35);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06043CB0(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 16));
    r0 = COPYB((sp - 16), 0x060B211C, 8);
    ST32((sp - 20), (sp - 16));
    ST32((sp - 24), 0);
    ST32((sp - 28), -8);
    ST32((sp - 32), 0);
    ST32((sp - 36), 0);
    ST32((sp - 40), 37);
    SETSP((sp - 40));
    SETPR(0x06043CDE);
    r0 = GCALL4(0x06043854, 7, 37, 39, 48);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06043D76(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 16));
    r0 = COPYB((sp - 16), 0x060B212C, 8);
    ST32((sp - 20), (sp - 16));
    ST32((sp - 24), 8);
    ST32((sp - 28), 0);
    ST32((sp - 32), 0);
    ST32((sp - 36), 0);
    ST32((sp - 40), 25);
    SETSP((sp - 40));
    SETPR(0x06043DA4);
    r0 = GCALL4(0x06043854, 4, 53, 30, 53);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06043DAC(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 12));
    r0 = COPYB((sp - 12), 0x060B2134, 8);
    ST32((sp - 16), (sp - 12));
    ST32((sp - 20), 0);
    ST32((sp - 24), -8);
    ST32((sp - 28), 0);
    ST32((sp - 32), -8);
    ST32((sp - 36), 18);
    SETSP((sp - 36));
    SETPR(0x06043DD8);
    r0 = GCALL4(0x06043854, 5, 43, 18, 30);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06043F48(int n)
{
    gaddr slot = SLOT(n);

    if (LD16(slot + 8) == 0)
        return 0;
    GCALL1(0x060692DC, LDU16(slot + 10));
    GCALL1(0x060692DC, LDU16(slot + 12));
    GCALL1(0x060692DC, LDU16(slot + 14));
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068CC4, LDU16(slot + 16));
    GCALL1(0x06068CC4, LDU16(slot + 18));
    return GJUMP1(0x06022EDA, n);
}

int f06044176(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0604417E);
    r0 = GCALL2(0x060441AC, 13, 22);
    SETSP((sp - 4));
    SETPR(0x06044184);
    r0 = GCALL2(0x060441AC, 14, 23);
    SETSP((sp - 4));
    SETPR(0x0604418A);
    r0 = GCALL2(0x060441AC, 15, 24);
    SETSP((sp - 4));
    SETPR(0x06044190);
    r0 = GCALL2(0x060441AC, 16, 25);
    SETSP((sp - 4));
    SETPR(0x06044196);
    r0 = GCALL2(0x060441AC, 17, 26);
    SETSP((sp - 4));
    SETPR(0x0604419C);
    r0 = GCALL2(0x060441AC, 18, 27);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x060441AC, 19, 28);
    return r0;
}

void f060442A0(int n)
{
    gaddr slot = SLOT(n);

    ST32(TASK_PTR, slot);
    if (LD16(slot + 8) == 0)
        return;
    GCALL1(0x060692DC, LDU16(slot + 10));
    GCALL2(0x06008A6A, 8, 1);
    GCALL1(0x06068CC4, LDU16(LD32(TASK_PTR) + 18));
    GJUMP1(0x06022EDA, n);
}

int f060445DC(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 8));
    r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
    r4 = LD16(((r0 - 1) << 1) + 0x060EC8B0);
    r4 = (r4 & 0xFFFF) & 7;
    r0 = (r0 + 1) << 1;
    r3 = LD16(r0 + 0x060EC8B0);
    r5 = (r3 & 0xFFFF) & 7;
    if (!((r4 & r4) == 0)) {
        r0 = r4;
        if (r0 == 4) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r0 = r4;
            if (r0 == 2) {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                r0 = r5;
                if (r0 == 4) {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    r0 = r5;
                    if (r0 == 2) {
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        SETSP((sp - 8));
                        r0 = GCALL1(0x0600996A, 81);
                        r2 = LD32(r14);
                        ST32(r2, 0x06044654);
                        r2 = LD32(r14);
                        ST16(r2 + 10, 90);
                        r4 = LD32(r14);
                        r0 = LD16(r4 + 8);
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 59);
                        return r0;
                    }
                }
            }
        }
    } else {
        if ((r5 & r5) == 0) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r0 = r4;
            if (r0 == 4) {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                r0 = r4;
                if (r0 == 2) {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    r0 = r5;
                    if (r0 == 4) {
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        r0 = r5;
                        if (r0 == 2) {
                            SETPR(LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        } else {
                            SETSP((sp - 8));
                            r0 = GCALL1(0x0600996A, 81);
                            r2 = LD32(r14);
                            ST32(r2, 0x06044654);
                            r2 = LD32(r14);
                            ST16(r2 + 10, 90);
                            r4 = LD32(r14);
                            r0 = LD16(r4 + 8);
                            SETPR(LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            UNFRAME(sp);
                            r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 59);
                            return r0;
                        }
                    }
                }
            }
        }
    }
}

int f06044868(void)
{
    int flags;

    GCALL1(0x0600C4E0, 0);
    GCALL2(0x0600C7BE, LD16(LD32(TASK_PTR) + 16) + LD16(LD32(TASK_PTR) + 10), LD16(LD32(TASK_PTR) + 14));
    flags = LDU16(FLAGS_AT(LDU16(LD32(TASK_PTR) + 14)));
    if ((flags & 7) == 0)
        return flags;
    TSET(h18, 120);
    TSET(fn, 0x060448BC);
    return GJUMP1(0x0600996A, 86);
}

int f060448BC(void)
{
    gaddr task = LD32(TASK_PTR);
    int pos = LD16(task + 16);

    if (LD16(task + 18) == 0) {
        ST16(task + 10, LD16(task + 10) ^ 1);
        pos += LD16(LD32(TASK_PTR) + 10);
        TSET(fn, 0x06044868);
    } else {
        pos += (LDU16(task + 18) >> 1) & 1;
        ST16(task + 18, LD16(task + 18) - 1);
    }
    GCALL1(0x0600C4E0, 0);
    return GJUMP2(0x0600C7BE, pos, LD16(LD32(TASK_PTR) + 14));
}

int f06044A7E(int arg)
{
    int who = GCALL1(0x06018DD6, arg);
    gaddr flags;

    ST16(0x060C062C, who);
    who &= 0xFFFF;
    if (who < LDU8(BOMBER_COUNT)) {
        flags = 0x060D5F34 + LDU16(0x060C062C) * 124;
        ST8(flags, LD8(flags) | 64);
        return 0x060D5F34;
    }
    return who;
}

int f06044B54(int r4)
{
    int r0, r2, r3, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST16(sp - 16, r4);
    SETSP((sp - 16));
    r0 = GCALL2(0x06022F1C, 0, 0x06044C60);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 6, 0);
    r3 = LD32(0x060D7E64);
    ST16(44 + r3, 1);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 16));
    r0 = GCALL3(0x0600D0E4, r0, 13, 35);
    r5 = LD16(sp - 16);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(13, 0x060D7E64);
    SETR(14, 0x060D7E60);
    SETSP((sp - 16));
    SETPR(0x06044B94);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r5 + 84));
    r4 = LD32(0x060D7E64);
    SETSP((sp - 16));
    r0 = GCALL2(0x0606950C, r4, 1);
    r3 = LD32(0x060D7E64);
    ST16(46 + r3, 0x200);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 10, 0);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

int f06044C60(void)
{
    int r0, r1, r3, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = LD32(0x060D7E64);
    r13 = LD32(0x060D7E60);
    r1 = LD16(50 + r14);
    r0 = LD16(r13 + 10);
    if (r1 == r0) {
        r0 = 60;
        r1 = LD16(60 + r14);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            r5 = LD16(50 + r14);
            r0 = LD16(r13 + 8);
            SETSP((sp - 12));
            SETPR(0x06044C94);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), ((r5 & 0xFFFF) + 1));
            r3 = LD32(0x060D7E64);
            r0 = 60;
            ST16(60 + r3, 0);
            r3 = LD32(0x060D7E60);
            ST32(r3, 0x060143D8);
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f06045358(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL2(0x06022F1C, 8, 0x0603DDA6);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 6, 0);
    ST16(0x060DFE14, 0x380);
    r3 = LD32(0x060D7E60);
    ST32((sp - 12), (r3 + 8));
    ST32((sp - 16), 10);
    SETR(14, 0x060D7E60);
    SETSP((sp - 16));
    SETPR(0x06045388);
    r0 = GCALL4(0x0605895E, 0x172, 1, 0, 0);
    r4 = LD32(0x060D7E60);
    SETPR(LD32((sp - 8)));
    r0 = LD16(r4 + 8);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP3(0x0600D0E4, r0, 32, 35);
    return r0;
}

int f0604539C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    r0 = LD16(0x060D7C10);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 0x173);
    return r0;
}

int f060454F0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST16(sp - 12, r4);
    ST16(sp - 16, r5);
    r0 = LD16(sp - 12);
    SETSP((sp - 16));
    r0 = GCALL2(0x06022F1C, (r0 & 0xFFFF), 0x06045690);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 6, 1);
    r3 = LD32(0x060D7E60);
    r0 = LD16(sp - 16);
    ST16(r3 + 4, r0);
    r3 = LD32(0x060D7E64);
    ST16(44 + r3, 1);
    r3 = LD32(0x060D7E64);
    ST16(46 + r3, 0x380);
    r3 = LD32(0x060D7E64);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 0x400));
    r3 = LD32(0x060D7E60);
    ST16(r3 + 10, 0);
    SETR(14, 0x060D7E60);
    SETSP((sp - 16));
    SETPR(0x0604553E);
    r0 = GCALL0(0x06045552);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP3(0x0600D0E4, r0, 14, 20);
    return r0;
}

int f06045552(void)
{
    int r0, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = LD32(0x060D7E60);
    r0 = LD16(r14 + 10);
    r4 = LD32(0x060D7E60);
    r14 = (r0 & 0xFFFF) << 1;
    r0 = LD16(r4 + 8);
    r14 = (r14 << 1) + 0x060B665A;
    r5 = LD16(r14);
    SETR(13, 0x060D7E60);
    SETR(14, r14);
    SETSP((sp - 12));
    SETPR(0x06045576);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r5 & 0xFFFF));
    r3 = LD32(0x060D7E60);
    r0 = LD16(r14 + 2);
    ST16(r3 + 12, r0);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060455C0(void)
{
    int r0, r1, r2, r3, r4, r5, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    r13 = 0x060D7E60;
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 10);
    ST16(r3 + 10, (r0 + 1));
    SETR(13, 0x060D7E60);
    SETSP((sp - 28));
    SETPR(0x060455DC);
    r0 = GCALL0(0x06045552);
    r2 = LD32(0x060D7E64);
    r0 = LD16(50 + r2);
    if ((r0 & r0) == 0) {
        r1 = LD32(r13);
        ST16(r1 + 10, 0);
        SETR(13, r13);
        SETSP((sp - 28));
        SETPR(0x060455F0);
        r0 = GCALL0(0x06045552);
        r3 = LD32(r13);
        ST16(r3 + 4, 120);
        r4 = LD32(r13);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL3(0x0600D0E4, r0, 14, 20);
    }
    r14 = 0x06068A8E;
    r12 = 0x060B6648;
    r0 = LD32(r13);
    r9 = 0x060C174E;
    r0 = LD16(r0 + 10);
    r11 = 0x060C1750;
    r0 = r0 & 0xFFFF;
    r10 = 0x060C1752;
    if (r0 == 1) {
        r5 = 0;
        r4 = LD16(r9);
        SETSP((sp - 28));
        SETPR(0x06045668);
        r0 = GCALL2(r14, (r4 & 0xFFFF), r5);
    } else {
        if (r0 == 2) {
            r5 = LD16(r12);
            r5 = r5 & 0xFFFF;
            r4 = LD16(r9);
            SETSP((sp - 28));
            SETPR(0x06045668);
            r0 = GCALL2(r14, (r4 & 0xFFFF), r5);
        } else {
            if (r0 == 3) {
                r5 = 0;
                r4 = LD16(r9);
                SETSP((sp - 28));
                SETPR(0x06045668);
                r0 = GCALL2(r14, (r4 & 0xFFFF), r5);
            } else {
                if (r0 == 4) {
                    r5 = LD16(r12);
                    r5 = r5 & 0xFFFF;
                    r4 = LD16(r9);
                    SETSP((sp - 28));
                    SETPR(0x06045668);
                    r0 = GCALL2(r14, (r4 & 0xFFFF), r5);
                } else {
                    if (r0 == 5) {
                        r0 = LD16(r12 + 6);
                        r5 = r0 & 0xFFFF;
                        r4 = LD16(r11);
                        SETSP((sp - 28));
                        SETPR(0x06045668);
                        r0 = GCALL2(r14, (r4 & 0xFFFF), r5);
                    } else {
                        if (r0 == 6) {
                            r5 = 0;
                            r4 = LD16(r11);
                            SETSP((sp - 28));
                            SETPR(0x06045668);
                            r0 = GCALL2(r14, (r4 & 0xFFFF), r5);
                        } else {
                            if (r0 == 9) {
                                r0 = LD16(r12 + 12);
                                r5 = r0 & 0xFFFF;
                                r4 = LD16(r10);
                                SETSP((sp - 28));
                                SETPR(0x06045668);
                                r0 = GCALL2(r14, (r4 & 0xFFFF), r5);
                            } else {
                                if (r0 == 10) {
                                    r4 = LD16(r10);
                                    r5 = 0;
                                    SETSP((sp - 28));
                                    SETPR(0x06045668);
                                    r0 = GCALL2(r14, (r4 & 0xFFFF), r5);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06045690(void)
{
    int r0, r2, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 12);
    if ((r0 & r0) == 0) {
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x060456A2);
        r0 = GCALL0(0x060455C0);
    }
    r3 = LD32(r14);
    r0 = LD16(r3 + 12);
    r4 = LD32(0x060D7E64);
    if (!((r0 & 0xFFFF) == 255)) {
        r0 = LD16(r4 + 16);
        ST16(r4 + 16, (r0 + 1));
        r2 = LD32(r14);
        r0 = LD16(r2 + 12);
        r0 = r0 - 1;
        ST16(r2 + 12, r0);
    } else {
        r0 = LD16(60 + r4);
        r0 = r0 & 0xFFFF;
        if (r0 >= 0xFF00) {
            r0 = LD32(r14);
            ST16((12 + r0), 0);
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060456DE(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST16(sp - 24, r4);
    ST16(sp - 28, r5);
    r0 = LD16(sp - 24);
    SETSP((sp - 28));
    r0 = GCALL2(0x06022F1C, r0, 0x06045760);
    r14 = LD16(sp - 28);
    r14 = (r14 << 1) + 0x060B6692;
    ST16(0x060DFE14, 0x380);
    r0 = LD32(0x060D7E60);
    ST32((sp - 32), (r0 + 8));
    ST32((sp - 36), 9);
    SETR(13, 0x060D7E60);
    SETR(14, r14);
    SETSP((sp - 36));
    SETPR(0x0604571E);
    r0 = GCALL4(0x0605895E, 0, 1, 0, 0);
    r0 = LD8(r14 + 1);
    r5 = LD8(r14);
    r6 = r0 & 255;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 36));
    r0 = GCALL3(0x0600D0E4, r0, (r5 & 255), r6);
    r2 = LD32(0x060D7E64);
    r0 = LD16(r2 + 16);
    ST16(r2 + 16, (r0 + 10));
    r3 = LD32(0x060D7E64);
    r0 = LD16(r3 + 18);
    ST16(r3 + 18, (r0 + 4));
    r3 = LD32(0x060D7E60);
    ST16(r3 + 20, 0);
    SETSP((sp - 36));
    r0 = GCALL2(0x0609C0B4, 0x200, 7);
    r4 = LD32(0x060D7E64);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x060695B0, r4, 1);
    return r0;
}

int f06045760(void)
{
    int r0, r1, r2, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 20));
    r0 = GCALL2(0x0605EC1E, (sp - 20), 2);
    r13 = 0x060D7E60;
    r14 = LD32(0x060D7E60);
    r0 = LD16(r14 + 20);
    if (!((r0 & r0) == 0)) {
        r0 = 60;
        r2 = LD32(0x060D7E64);
        r1 = LD16(60 + r2);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            r0 = LD16(r14 + 8);
            SETR(13, r13);
            SETSP((sp - 20));
            SETPR(0x060457A6);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0x131);
            r2 = LD32(r13);
            ST32(r2, 0x0603DDA6);
        }
    } else {
        r0 = LD16(r14 + 8);
        SETR(13, r13);
        SETSP((sp - 20));
        SETPR(0x06045784);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0x132);
        r2 = LD32(r13);
        r0 = 1;
        ST16(r2 + 20, 1);
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060457F8(void)
{
    int r0, r3, r4, r6, r7, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    SETSP((sp - 40));
    r0 = GCALL2(0x06022F1C, 5, 0x0603DDA6);
    if (r0 >= 0) {
        r3 = LD32(0x060D7E60);
        ST16(r3 + 6, 0);
        SETSP((sp - 40));
        r0 = GCALL1(0x06008A96, 1);
        r11 = sp - 40;
        SETSP((sp - 40));
        r0 = GCALL4(0x0605EAF6, r11, 4, r6, r7);
        SETR(11, r11);
        SETSP((sp - 40));
        SETPR(0x06045832);
        r0 = GCALL2(0x0603FA30, r11, 0x060B6698);
        r13 = 0;
        r10 = 0x060695EA;
        r12 = 4;
        r14 = 0 + r11;
        do {
            r4 = LD16(r14);
            SETSP((sp - 40));
            r0 = GCALL2(r10, r4, 1);
            r13 = r13 + 1;
            r14 = r14 + 2;
        } while (AGAIN(!(((short)r13) >= r12)));
    }
    SETPR(LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06045974(void)
{
    int result = 60;

    if (LDU16(LD32(TASK_OBJ) + 60) >= 0xFF00) {
        ST8(0x060C1754, LD8(0x060C1754) - 1);
        if (LD8(0x060C1754) == 0)
            result = GCALL1(0x06009A3A, 197);
        TSET(fn, 0x060459AA);
    }
    return result;
}

int f06045B98(int speed)
{
    int ax;
    int ay;
    int dx;
    int dy;
    gaddr obj;

    GCALL2(0x0600CA32, LDU16(LD32(TASK_PTR) + 16), LDU16(LD32(TASK_PTR) + 14));
    ax = (short)LD16(0x060D7E88);
    ay = (short)LD16(0x060D7E8A);
    obj = LD32(TASK_OBJ);
    if (ax > LD16(obj + 16))
        dx = speed;
    else if (ax >= LD16(obj + 16))
        dx = 0;
    else
        dx = -speed;
    if (ay > LD16(obj + 18))
        dy = speed;
    else if (ay >= LD16(obj + 18))
        dy = 0;
    else
        dy = -speed;
    ST16(0x060C1AA8, LD16(LD32(TASK_PTR) + 8));
    GCALL1(0x0600A28C, (short)dx);
    GCALL1(0x0600A306, (short)dy);
    return (short)dx == 0 && (short)dy == 0;
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

int f06045CFA(int r4)
{
    int r0, r3, r5, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r14 = (((((short)r4) << 1) + ((short)r4)) << 2) + 0x060B66FA;
    SETSP((sp - 16));
    r0 = GCALL1(0x06008A96, 1);
    r12 = 6;
    ST8(0x060C1755, 0);
    r13 = 0;
    while (1) {
        r3 = LD8(r14);
        if ((r3 & r3) == 0) {
            break;
        } else {
            r0 = LD8(r14 + 1);
            r5 = LD8(r14);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x06045D34);
            r0 = GCALL3(0x06045D46, (r13 + 10), (r5 & 255), (r0 & 255));
            r13 = r13 + 1;
            r14 = r14 + 2;
            if (!((unsigned)r13 >= (unsigned)r12)) {
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
    }
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06045E00(void)
{
    gaddr task;
    int result;

    ST8(0x060C1755, LD8(0x060C1755) - 1);
    if (LD8(0x060C1755) == 0)
        GCALL1(0x06009A3A, 194);
    task = LD32(TASK_PTR);
    if (LDU16(0x060D7E68) & 0x1052) {
        ST32(task, 0x0603DDA6);
        return 0x1052;
    }
    result = GCALL3(0x06045CBC, 150, 0x1C2, 150);
    ST16(task + 20, result);
    TSET(fn, 0x06045F4A);
    return result;
}

int f06045E48(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(14, 0x060D7E60);
    SETSP((sp - 8));
    SETPR(0x06045E5A);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0x15A);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 10);
    SETSP((sp - 8));
    r0 = GCALL1(0x060692DC, (r0 & 0xFFFF));
    r2 = LD32(0x060D7E60);
    ST16(r2 + 10, 0);
    r3 = LD32(0x060D7E60);
    ST32(r3, 0x06045EDC);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

int f06045F4A(int r4, int r5, int r6, int r7)
{
    int r0, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 20);
    if ((r0 & r0) == 0) {
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06045F66);
        r0 = GCALL4(0x060462A8, 1, 0, r6, r7);
        r3 = LD32(r14);
        ST32(r3, 0x06045F94);
    } else {
        r0 = LD16(r4 + 20);
        ST16(r4 + 20, (r0 - 1));
    }
    r4 = LD32(r14);
    r0 = LD16(r4 + 8);
    SETSP((sp - 12));
    r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
    ST16(sp - 12, r0);
    r5 = LD16(sp - 12);
    SETSP((sp - 12));
    r0 = GCALL2(0x060647BA, 0, r5);
    r0 = (short)r0;
    if (!((r0 & r0) == 0)) {
        r3 = LD32(r14);
        ST32(r3, 0x06045E48);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0604604A(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E64);
    r0 = LD16(48 + r4);
    if ((r0 & r0) == 0) {
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x0604609C);
        r0 = GCALL4(0x060462A8, 3, 0, r6, r7);
        r3 = LD32(r14);
        ST32(r3, 0x060460E2);
    } else {
        r2 = LD16(48 + r4);
        ST16(48 + r4, (r2 - 1));
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETSP((sp - 12));
        r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
        SETSP((sp - 12));
        r0 = GCALL1(0x060460AA, r0);
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETSP((sp - 12));
        r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
        ST16(sp - 12, r0);
        r5 = LD16(sp - 12);
        SETSP((sp - 12));
        r0 = GCALL2(0x060647BA, 0, r5);
        r0 = (short)r0;
        if (!((r0 & r0) == 0)) {
            r3 = LD32(r14);
            ST32(r3, 0x06045E76);
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

void f06046174(void)
{
    short ids[6];
    gaddr obj = LD32(TASK_OBJ);
    int x = LD16(obj + 16);
    int y = LD16(obj + 18) + 32;
    int k = 1;

    do {
        gaddr seg;

        ids[k] = GCALL1(0x060691DA, 1);
        ST16(0x060C1AA8, ids[k]);
        seg = OBJ(LDU16(0x060C1AA8));
        ST16(seg + 44, 1);
        ST16(seg + 16, x);
        ST16(seg + 18, y);
        ST16(seg + 38, 0);
        ST16(seg + 46, 0x380);
        ST16(seg + 42, LD16(seg + 42) | 0x400);
        y += 16;
        k++;
    } while (AGAIN(k < 6));
    TSET(h12, ids[1]);
    TSET(h14, ids[2]);
    TSET(h16, ids[3]);
    TSET(h18, ids[4]);
    TSET(h20, ids[5]);
}

int f060462A8(int r4)
{
    int r0, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r0 = r4 & 0xFFFF;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    if (!((r0 & r0) == 0)) {
        r11 = r4 & 0xFFFF;
        if (r11 == 2) {
            SETSP((sp - 48));
            r0 = GCALL0(0x06046174);
        }
        r14 = 0x060D7E60;
        r10 = 0;
        r9 = 0x06068A8E;
        r13 = sp - 48;
        r3 = LD32(0x060D7E60);
        r0 = LD16(r3 + 10);
        ST16(r13, r0);
        r0 = LD32(0x060D7E60);
        r0 = LD16(r0 + 12);
        ST16(r13 + 2, r0);
        r0 = LD32(0x060D7E60);
        r0 = LD16(r0 + 14);
        ST16(r13 + 4, r0);
        r0 = LD32(0x060D7E60);
        r0 = LD16(r0 + 16);
        ST16(r13 + 6, r0);
        r0 = LD32(0x060D7E60);
        r0 = LD16(r0 + 18);
        ST16(r13 + 8, r0);
        r0 = LD32(0x060D7E60);
        r0 = LD16(r0 + 20);
        ST16(r13 + 10, r0);
        r0 = r11;
        r12 = 6;
        if (r0 == 1) {
            r4 = LD16(r13);
            SETSP((sp - 48));
            SETPR(0x06046312);
            r0 = GCALL2(r9, r4, 0x156);
        } else {
            if (r0 == 2) {
                r11 = 0x15C;
                r4 = 0 + r13;
                r14 = r4;
                r13 = r4;
                do {
                    r0 = LD16(r13);
                    if (!((r0 & r0) == 0)) {
                        r4 = LD16(r14);
                        SETR(9, r9);
                        SETR(10, r10);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 48));
                        SETPR(0x0604632C);
                        r0 = GCALL2(r9, r4, r11);
                    }
                    r10 = r10 + 1;
                    r14 = r14 + 2;
                    r11 = r11 + 1;
                    r13 = r13 + 2;
                } while (AGAIN(!(((short)r10) >= r12)));
            } else {
                if (r0 == 3) {
                    r4 = LD16(r13);
                    SETR(10, r10);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 48));
                    SETPR(0x06046344);
                    r0 = GCALL2(r9, r4, 0x15B);
                    r8 = 0x060692DC;
                    r9 = 1;
                    r4 = 2 + r13;
                    r11 = r4;
                    r13 = r4;
                    do {
                        r0 = LD16(r13);
                        if (!((r0 & r0) == 0)) {
                            r4 = LD16(r11);
                            SETSP((sp - 48));
                            r0 = GCALL1(r8, r4);
                        }
                        r9 = r9 + 1;
                        r11 = r11 + 2;
                        r13 = r13 + 2;
                    } while (AGAIN(!(((short)r9) >= r12)));
                    r0 = r10;
                    r3 = LD32(r14);
                    ST16(r3 + 12, r0);
                    r3 = LD32(r14);
                    ST16(r3 + 14, r0);
                    r3 = LD32(r14);
                    ST16(r3 + 16, r0);
                    r3 = LD32(r14);
                    ST16(r3 + 18, r0);
                    r3 = LD32(r14);
                    ST16(r3 + 20, r0);
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

void f0604655A(void)
{
    GCALL1(0x0600996A, 193);
    ST32(0x060D7BA8, 0x0604656E);
}

int f0604656E(void)
{
    int r0, r1, r2, r3, r4;
    ENTRY_SP(sp);

    r0 = 60;
    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r2 = LD32(0x060D7E64);
    r3 = LD16(60 + r2);
    if ((r3 & 0xFFFF) >= 0xFF00) {
        r1 = LD32(0x060D7E60);
        ST16(r1 + 12, 1);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETR(14, 0x060D7E60);
        SETSP((sp - 8));
        SETPR(0x06046596);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0x168);
        r0 = LD32(0x060D7E60);
        r2 = LD32(0x060D7E64);
        r0 = LD16(r0 + 14);
        ST16(r2 + 4, r0);
        r2 = LD32(0x060D7E60);
        ST32(r2, 0x0603DDA6);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

void f060483CC(gaddr ids)
{
    FRAME(sp, 44);
    gaddr pts = sp - 44;
    int i = 0;

    COPYB(sp - 36, 0x060B2278, 6);
    COPYB(pts, 0x060B227E, 8);
    GCALL2(0x06008A6A, 8, 1);
    do {
        gaddr obj = OBJ(LDU16(ids));

        ST16(obj + 16, LD16(pts));
        ST16(obj + 18, LD16(pts + 2));
        ST16(obj + 46, (LD16(obj + 46) & 0xFC00) | 0x340);
        ST16(obj + 4, 0x190);
        i++;
        pts += 4;
        ids += 2;
    } while (AGAIN((short)i < 2));
}

int f06048A68(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r0 = LD8(0x060FB8DC);
    ST8(0x060FB8DC, (r0 | 32));
    r0 = LD16(0x060FB8B4);
    ST16(0x060FB8B4, ((r0 & 255) | 0x200));
    r0 = LD16(0x060FA9DA);
    ST16(0x060FA9DA, (r0 & 0xFFF3));
    r0 = LD16(0x060FA9DA);
    ST16(0x060FA9DA, (r0 | 4));
    r0 = LD16(0x060FAA70);
    ST16(0x060FAA70, (r0 & 0xF0FF));
    r0 = LD16(0x060FAA70);
    ST16(0x060FAA70, (r0 | 0x300));
    ST32(0x060FAA24, ((int)0xFFF00000));
    ST16(0x060BB8FC, 1);
    SETSP((sp - 4));
    r0 = GCALL1(0x06008A96, 1);
    SETSP((sp - 4));
    SETPR(0x06048ABA);
    r0 = GCALL1(0x060094DE, 22);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06008ECA, 75, 0x180);
    return r0;
}

void f06048C40(gaddr out)
{
    FRAME(sp, 80);
    gaddr counts = sp - 64;
    gaddr groups = sp - 44;
    int i;

    if ((LD32(0x060C1048) & 0xC00) != 0x800) {
        GCALL1(0x06034C3A, groups);
        i = 0;
        do {
            ST16(counts + i * 2, i);
        } while (AGAIN(++i < 10));
        i = 0;
        do {
            if (LDU8(0x060C0640 + i) & 3) {
                gaddr slot = counts + (short)(LDU8(groups + i) - 1) * 2;

                ST8(LD16(slot) + out, i);
                ST16(slot, LD16(slot) + 1);
            }
        } while (AGAIN(++i < 10));
    } else {
        short total = 0;
        int k;
        int j;

        GCALL1(0x06034D20, groups);
        for (k = 0; k < 5; k++) {
            POLL();
            j = 0;
            do {
                if (LDU8(groups + j) == k + 1) {
                    ST16(counts + j * 2, total);
                    total += GCALL1(0x0602C430, j);
                }
            } while (AGAIN(++j < 5));
        }
        i = 0;
        do {
            if (LDU8(0x060C0640 + i) & 3) {
                gaddr slot = counts + (short)(LDU8(0x060C0640 + i) >> 2) * 2;

                ST8(LD16(slot) + out, i);
                ST16(slot, LD16(slot) + 1);
            }
        } while (AGAIN(++i < 10));
    }
}

int f06049310(gaddr ids)
{
    FRAME(sp, 40);
    gaddr pts = sp - 36;
    int i = 0;

    COPYB(pts, 0x060B2298, 8);
    GCALL2(0x06008A6A, 8, 1);
    do {
        gaddr obj = OBJ(LDU16(ids + i * 2 + 160));
        gaddr pt = pts + (short)(i * 4);

        ST16(obj + 4, 0x190);
        i++;
        ST16(obj + 44, 1);
        ST16(obj + 16, LD16(pt) * 8);
        ST16(obj + 18, LD16(pt + 2) * 8);
        ST16(obj + 38, 0);
        ST16(obj + 36, 0);
    } while (AGAIN((short)i < 2));
    return i;
}

void f06049478(int base, int fill, int x0, int y0)
{
    FRAME(sp, 0);
    int run0 = 64 - (63 & x0);
    int y = y0;

    while ((unsigned short)y <= LDU16(sp + 6)) {
        gaddr cell;
        int x = x0;
        int run = run0;

        POLL();
        cell = GCALL3(0x0600ABA4, base, x0, y);
        if (!((unsigned short)x > LDU16(sp + 2))) {
            do {
                if ((run & 0xFFFF) == 0)
                    cell = GCALL3(0x0600ABA4, base, x, y);
                x++;
                ST32(cell, fill);
                run--;
                cell += 4;
            } while (AGAIN(!((unsigned short)x > LDU16(sp + 2))));
        }
        y++;
    }
}

void f06049516(int base, int bits, short x0, int y0)
{
    FRAME(sp, 0);
    int attr = ((bits & 0xFFFF) << 12) & 0x007F0000;
    int run0 = 64 - (x0 & 63);
    int y = y0;

    while ((unsigned short)y <= LDU16(sp + 6)) {
        gaddr cell;
        int x = x0;
        int run = run0;

        POLL();
        cell = GCALL3(0x0600ABA4, base, x0, y);
        if (!((unsigned short)x > LDU16(sp + 2))) {
            do {
                if ((run & 0xFFFF) == 0) {
                    cell = GCALL3(0x0600ABA4, base, x, y);
                    run0 = 64 - (63 & x);
                }
                ST32(cell, (LD32(cell) & 0xFF80FFFF) | attr);
                x++;
                run--;
                cell += 4;
            } while (AGAIN(!((unsigned short)x > LDU16(sp + 2))));
        }
        y++;
    }
}

void f060495B6(short sel)
{
    int rows = (LD32(0x060C1048) & 0xC00) != 0x400 ? 18 : 12;
    int k = 0;
    gaddr p = 0x060C0640;
    gaddr rec;
    int handle;

    handle = GCALL7(0x06035CDA, 210, 0, 211, 0, 0, 0, sel) & 0xFFFF;
    rec = POINTS + (short)(handle * 24);
    ST32(rec + 12, LD32(rec + 12) | 0x10008000);
    do {
        if (LDU8(p) & 3) {
            handle = GCALL7(0x06035CDA, 211, k, 255, rows, k * 2 + 4, 0x06049694, sel) & 0xFFFF;
            if (k == (sel & 0xFFFF)) {
                rec = POINTS + (short)(handle * 24);
                ST32(rec + 12, LD32(rec + 12) | 64);
            }
            k++;
        }
        p++;
    } while (AGAIN(p < 0x060C064A));
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

void f06049F98(gaddr p)
{
    gaddr obj = OBJ(LD16(p + 6));
    int v;

    if (LD16(obj + 38) > 100) {
        if (LD16(obj + 36) < 350) {
            ST16(obj + 36, LD16(obj + 36) + 5);
            v = GCALL1(0x0609812C, LD32(0x060B9108 + ((LD16(obj + 36) / 2) & 255) * 4));
            ST16(obj + 38, DIVS(v, 0x2000) + 170);
            return;
        }
        ST16(obj + 16, 0);
        ST16(obj + 18, 50);
        ST16(obj + 36, 600);
        ST16(obj + 38, 0);
        ST16(obj + 4, 20);
        GCALL2(0x0606950C, obj, 1);
        GJUMP2(0x0606AAC8, obj, 3);
        return;
    }
    if (LD16(obj + 36) > -300) {
        ST16(obj + 36, LD16(obj + 36) - 1);
        v = GCALL1(0x0609812C, LD32(0x060B9108 + (LD16(obj + 36) & 255) * 4));
        ST16(obj + 38, DIVS(v, 0x2000));
        v = DIVS(v, 0x800) + 256;
        ST16(obj + 70, v);
        ST16(obj + 68, v);
        return;
    }
    ST16(obj + 38, 170);
    ST16(obj + 36, LD16(obj + 36) - 200);
    ST16(obj + 20, 399);
    ST16(obj + 24, 0);
    ST16(obj + 22, 0);
    ST16(obj + 26, 199);
    ST16(obj + 4, 495);
    GCALL2(0x0606950C, obj, 0);
    GJUMP2(0x0606AAC8, obj, 1);
}

void f0604A7B4(gaddr pair, short angle)
{
    int a = -GCALL2(0x060980B4, GCALL1(0x0606CE8C, angle), 192);
    int b = 128 + GCALL2(0x060980B4, GCALL1(0x0606CEB0, angle), 52);
    gaddr first = OBJ(LD16(pair));
    gaddr second;
    int height = LD16(first + 38);
    int a2;
    int b2;

    ST16(first + 20, -b);
    ST16(first + 24, b - 1);
    ST16(first + 28, 127);
    ST16(first + 32, -128);
    ST16(first + 26, a + 48);
    ST16(first + 22, a + 48);
    ST16(first + 34, (243 - height) / 2);
    ST16(first + 30, (243 - height) / 2);
    a2 = -GCALL2(0x060980B4, GCALL1(0x0606CE8C, angle + 64), 191);
    b2 = b + GCALL2(0x060980B4, GCALL1(0x0606CEB0, angle + 64), 52);
    second = OBJ(LD16(pair + 2));
    ST16(second + 20, -b2);
    ST16(second + 24, b2 - 1);
    ST16(second + 28, b - 1);
    ST16(second + 32, -b);
    ST16(second + 26, a2 + a + 48);
    ST16(second + 22, a2 + a + 48);
    ST16(second + 34, a + 48);
    ST16(second + 30, a + 48);
    ST16(second + 38, height);
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

void f0604AF5C(int unused, gaddr p)
{
    gaddr obj = OBJ(LD16(p + 2));
    short y = LD16(obj + 22);
    int target = LD16(obj + 30) - 191;
    int step = target == y ? 0 : 32;

    if (target >= y) {
        ST16(VELOCITY, LD16(VELOCITY) + step);
        y += LD16(VELOCITY) >> 3;
        if (target < y)
            ST16(VELOCITY, LD16(VELOCITY) / 2);
    }
    if (target <= y) {
        ST16(VELOCITY, LD16(VELOCITY) - step);
        y += LD16(VELOCITY) >> 3;
        if (target > y)
            ST16(VELOCITY, LD16(VELOCITY) / 2);
    }
    ST16(obj + 26, y);
    ST16(obj + 22, y);
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

void f0604B1B4(int r4)
{
    int r0, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = r4;
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r11 = 0x060C1760;
    r12 = 0x060C1764;
    r14 = 0;
    while (1) {
        r2 = LD8(r11);
        if (!(((short)r14) >= (r2 & 255))) {
            POLL();
            r4 = ((short)r14) + r12;
            r3 = LD8(r4);
            if (r3 > 0) {
                r0 = LD8(r4);
                if (r0 == 1) {
                    SETR(11, r11);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 20));
                    SETPR(0x0604B21A);
                    r0 = GCALL2(0x0604B23C, r14, r13);
                } else {
                    if (r0 == 2) {
                        SETSP((sp - 20));
                        r0 = GCALL2(0x0604B4CC, r14, r13);
                    }
                }
            }
            r14 = r14 + 1;
            continue;
        } else {
            break;
        }
    }
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
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

int f0604B53A(int delta, gaddr rec)
{
    gaddr obj = OBJ(LDU16(rec + 4));
    int result = LD16(rec + 4);

    if (delta == 0) {
        GCALL2(0x0606AAC8, obj, 7);
        ST8(obj + 78, 0);
        ST16(obj + 80, -64);
        ST16(obj + 82, -16);
        return 82;
    }
    if ((unsigned int)delta < 3) {
        ST8(obj + 78, LD8(obj + 78) + delta);
        result = 78;
    }
    return result;
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

int f0604D526(short a, short b)
{
    int i = 0;

    for (;;) {
        if (b == (short)GCALL2(0x0604D4D4, a, i))
            break;
        i++;
        if (i >= 10)
            break;
        POLL();
    }
    return i;
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

void f0604D7F4(void)
{
    ST16(0x060D7E68, 0x2000);
    ST8(0x060C17C4, 0);
    if ((GCALL0(0x0604D7C6) & 0xFFFF) == 0) {
        int mode = 7 & ((unsigned int)LD32(0x060C1040) >> 4);
        int v = LD16(0x060B6A0A + mode * 2);

        if (mode != 0)
            ST8(0x060C17C4, 1);
        if ((v & 0xFFFF) == 0)
            ST16(0x060D7E68, 0);
        ST8(0x060C17A0, v);
        ST8(0x060C179A, v);
        ST8(0x060C029C, v);
        ST8(0x060C029E, v);
        ST8(0x060C17A1, 0);
        ST8(0x060C179B, 0);
        ST8(0x060C029D, 0);
        ST8(0x060C029F, 0);
        ST8(0x060C179E, 0);
    } else {
        ST8(0x060C179A, LD8(0x060C17A0));
        ST8(0x060C029C, LD8(0x060C17A0));
        ST8(0x060C029E, LD8(0x060C17A0));
        ST8(0x060C179B, LD8(0x060C17A1));
        ST8(0x060C029D, LD8(0x060C17A1));
        ST8(0x060C029F, LD8(0x060C17A1));
        ST8(0x060C179E, 1);
    }
    GCALL2(0x0604D66C, LDU8(0x060C029C), LDU8(0x060C029D));
    GJUMP0(0x0602E674);
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

int f0604F5C8(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    r4 = LD16(0x060C1798);
    UNFRAME(sp);
    r0 = GJUMP1(0x0606B51C, (r4 & 0xFFFF));
    return r0;
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
