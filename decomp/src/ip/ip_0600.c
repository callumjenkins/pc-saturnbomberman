#include "krnl.h"

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060022E4(void)
{
    int r0, r1, r2;
    int v4;
    int v8;
    int v12;
    int v16;
    int v20;

    r2 = LD32(0x06002D80);
    ST32(0x06002D80, (r2 - 1));
    v4 = 0x06002D84;
    r0 = LD32(v4);
    if (r0 == 1) {
        ST32(v4, 0);
        r2 = LD32(0x06002D7C);
        v16 = r2;
        v20 = 0x25F80000;
        v12 = 144;
        do {
            r1 = LD16(v16);
            ST16(v20, r1);
            v20 = v20 + 2;
            v16 = v16 + 2;
            r1 = v12 - 1;
            v12 = r1;
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06002348(void)
{
    int r2, r3;
    int v4;
    int v8;
    int v12;
    short v14;
    int v20;
    int v24;
    int v28;
    int v32;

    v4 = 0x06002100;
    v20 = 0;
    v24 = 0;
    v28 = 0x53454741;
    v32 = 0;
    while (!((unsigned)v32 >= (unsigned)0xD00)) {
        POLL();
        r2 = v4 + 4;
        v4 = r2;
        r3 = LD32((r2 - 4));
        r2 = v20 + r3;
        v20 = r2;
        v24 = v24 ^ r2;
        v28 = v28 - v24;
        v32 = v32 + 4;
    }
    v8 = 0x25F80002;
    v12 = 0x25F80008;
    v32 = 0;
    while (!((unsigned)v32 >= (unsigned)0x100)) {
        POLL();
        r3 = LD16(v8);
        r3 = LD16(v12);
        r2 = v20 + (r3 & 0xFFFF);
        v20 = r2;
        v24 = v24 + r2;
        v28 = v28 ^ v24;
        v32 = v32 + 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060023E6(void)
{
    int r0;

    ST32(0x06002D84, 1);
    do {
        r0 = LD32(0x06002D84);
    } while (AGAIN(r0 == 1));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06002404(int r4, int r5, int r6)
{
    int r1;
    int v4;
    int v8;
    int v12;

    v4 = r4;
    v8 = r5;
    v12 = r6;
    do {
        r1 = LD16(v4);
        ST16(v8, r1);
        v8 = v8 + 2;
        v4 = v4 + 2;
        r1 = v12 - 1;
        v12 = r1;
    } while (AGAIN(!((r1 & r1) == 0)));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06002430(int r4, int r5, int r6)
{
    int r1;
    int v4;
    int v8;
    int v12;

    v4 = r4;
    v8 = r5;
    v12 = r6;
    do {
        r1 = LD8(v4);
        ST8(v8, r1);
        v8 = v8 + 1;
        v4 = v4 + 1;
        r1 = v12 - 1;
        v12 = r1;
    } while (AGAIN(!((r1 & r1) == 0)));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0600245C(int r4, int r5, int r6)
{
    int r0, r2, r3;
    FRAME(sp, 12);

    ST32(sp - 4, r4);
    ST32(sp - 8, r5);
    ST16((sp - 10), r6);
    do {
        r2 = LD32(sp - 4);
        r2 = r2 + 2;
        ST32(sp - 4, r2);
        r0 = LD16(sp - 10);
        ST16((r2 - 2), r0);
        r3 = LD32(sp - 8);
        r3 = r3 - 1;
        ST32(sp - 8, r3);
    } while (AGAIN(!((r3 & r3) == 0)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060024D8(int r4)
{
    int r0, r2, r3;
    FRAME(sp, 8);

    ST16((sp - 2), r4);
    r2 = LD32(0x06002D7C);
    r2 = (r2 + 0x100) + 20;
    ST32(sp - 8, r2);
    r0 = LD16(sp - 2);
    ST16(r2, r0);
    r3 = LD32(sp - 8);
    r3 = r3 + 2;
    ST32(sp - 8, r3);
    r0 = LD16(sp - 2);
    ST16(r3, r0);
    r3 = LD32(sp - 8);
    r3 = r3 + 2;
    ST32(sp - 8, r3);
    r0 = LD16(sp - 2);
    ST16(r3, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06002510(int r4)
{
    int r0, r3;
    FRAME(sp, 8);

    ST16((sp - 6), r4);
    ST16(sp - 8, 0x100);
    while (1) {
        r3 = LD16(sp - 8);
        if (!((r3 & 0xFFFF) >= 0x200)) {
            POLL();
            r4 = LD16(sp - 8);
            r0 = GCALL5(0x060024D8, r4, 0, 0, 0, LD32((sp - 8)));
            r0 = GCALL5(0x060023E6, 0, 0, 0, 0, LD32((sp - 8)));
            r0 = LD16(sp - 6);
            r3 = LD16(sp - 8);
            ST16(sp - 8, (r3 + (r0 & 0xFFFF)));
            continue;
        } else {
            break;
        }
    }
    r0 = GCALL5(0x060024D8, 0x200, 0, 0, 0, LD32((sp - 8)));
    r0 = GCALL5(0x060023E6, 0, 0, 0, 0, LD32((sp - 8)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0600255C(void)
{
    int v4;
    int v8;
    int v12;

    v4 = 0x25D00000;
    v8 = 0;
    while (!((unsigned)v8 >= (unsigned)6)) {
        POLL();
        ST16(v4, 0);
        v4 = v4 + 2;
        v8 = v8 + 1;
    }
    ST16(0x25C00000, 0x8000);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06002594(void)
{
    int r0, r1, r2, r3, r4;
    int v8;
    int v12;
    int v16;
    int v20;
    int v32;
    int v36;
    int v40;
    int v44;
    int v48;

    r4 = LD32(0x06002D7C);
    r0 = GCALL3(0x0600245C, r4, 144, 0);
    r2 = LD32(0x06002D7C);
    v12 = r2;
    ST16(32 + v12, 1);
    v44 = 0x060027AC;
    v48 = v12 + 16;
    v8 = 0;
    while (!((unsigned)v8 >= (unsigned)8)) {
        POLL();
        r1 = LD16(v44);
        ST16(v48, r1);
        v48 = v48 + 2;
        v44 = v44 + 2;
        v8 = v8 + 1;
    }
    r2 = LD32(0x06002D7C);
    v16 = r2 + 40;
    ST16(v16 + 8, 0x8000);
    ST16(v16 + 24, 0x303);
    ST16(v16 + 26, 0x303);
    r3 = LD32(0x06002D7C);
    v20 = r3 + 112;
    ST32(v20 + 8, 0x00010000);
    ST32(v20 + 12, 0x00010000);
    ST32(v20 + 24, 0x00010000);
    ST32(v20 + 28, 0x00010000);
    ST32(v20 + 60, 0x4000);
    ST16(0x25E08000, 0);
    r3 = LD32(0x06002D7C);
    ST16((r3 + 224), 32);
    r3 = LD32(0x06002D7C);
    ST16((r3 + 240) + 8, 7);
    r3 = LD32(0x06002D7C);
    v40 = r3 + 0x100;
    r0 = 1;
    ST16(v40 + 16, 1);
    v8 = 0x100;
    r2 = ((v40 + 20) + 6) - 2;
    ST16(r2, (v8 & 0xFFFF));
    r3 = r2 - 2;
    v48 = r3;
    r2 = v8 & 0xFFFF;
    ST16(r3, r2);
    ST16((v48 - 2), (v8 & 0xFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06002E20(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;

    r5 = 0x060002DC;
    r7 = LD32(0x06000260);
    r3 = LD32(0x060002DC);
    ST32(0x06002E9C, r3);
    r0 = 0x06002E48;
    r1 = r7;
    r2 = 22;
    do {
        r4 = LD32(r0);
        r0 = r0 + 4;
        r2 = r2 - 1;
        ST32(r1, r4);
        r1 = r1 + 4;
    } while (AGAIN(!(r2 == 0)));
    ST32(r5, r7);
    r0 = GJUMP4(0x06006000, r4, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06002486(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    FRAME(sp, 24);

    ST32(sp - 4, r4);
    ST16((sp - 6), r5);
    ST32(sp - 12, r6);
    ST32(sp - 16, r7);
    do {
        r2 = LD32(sp - 4);
        ST32(sp - 24, r2);
        r3 = LD32(sp - 12);
        ST32(sp - 20, r3);
        do {
            r3 = LD32(sp - 24);
            r0 = LD16(sp - 6);
            ST16(r3, r0);
            r0 = LD16(sp - 6);
            r0 = r0 + 1;
            ST16(sp - 6, r0);
            r2 = LD32(sp - 24);
            ST32(sp - 24, (r2 + 2));
            r1 = LD32(sp - 20);
            r1 = r1 - 1;
            ST32(sp - 20, r1);
        } while (AGAIN(!((r1 & r1) == 0)));
        r2 = LD32(sp - 4);
        ST32(sp - 4, (r2 + 128));
        r3 = LD32(sp - 16);
        r3 = r3 - 1;
        ST32(sp - 16, r3);
    } while (AGAIN(!((r3 & r3) == 0)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06002280(void)
{
    int r0, r3;
    FRAME(sp, 16);

    r3 = LD32(0x060027A4);
    ST32(sp - 12, r3);
    r3 = LD32(0x060027A8);
    ST32(sp - 16, r3);
    ST16(sp - 4, 0);
    while (1) {
        r0 = LD16(sp - 4);
        if (!(r0 >= 6)) {
            POLL();
            r0 = LD8(sp - 12);
            ST8(sp - 1, r0);
            r3 = LD8(sp - 16);
            ST8(sp - 2, r3);
            r3 = LD32(sp - 12);
            r0 = LD8(sp - 2);
            ST32(sp - 12, ((r3 << 8) + (r0 & 255)));
            r3 = LD32(sp - 16);
            r0 = LD8(sp - 1);
            ST32(sp - 16, ((r3 << 8) + (r0 & 255)));
            r0 = LD16(sp - 4);
            ST16(sp - 4, (r0 + 1));
            continue;
        } else {
            break;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0600270A(int r4, int r5)
{
    int r0, r1, r2, r8, r9, c6, c8;

    r0 = R(0);
    r1 = R(1);
    r2 = R(2);
    r8 = R(8);
    r9 = R(9);
    if (r5 > 0) {
        r2 = ((r2 << 2) << 2) + r0;
        if ((r5 - 1) == 0) {
            r2 = r2 + 2;
            do {
                c6 = r8 & 1;
                r8 = (int)((unsigned)r8 >> 1);
                if (c6) {
                    r1 = r1 | r4;
                    ST8(r9, r1);
                    r9 = r9 + 1;
                } else {
                    r8 = r8 + 1;
                    r1 = (r4 << 2) << 2;
                }
                r2 = r2 - 1;
            } while (AGAIN(!(r2 == 0)));
        }
        return;
    } else {
        if (r0 == 12) {
            return;
        } else {
            if (r0 == 14) {
                return;
            } else {
                if (r0 == 13) {
                    return;
                } else {
                    r5 = 2;
                    if (r0 == 15) {
                        return;
                    } else {
                        c8 = r8 & 1;
                        r8 = (int)((unsigned)r8 >> 1);
                        if (c8) {
                            ST8(r9, (r1 | r0));
                            return;
                        } else {
                            return;
                        }
                    }
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06002D88(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;

    r10 = R(10);
    r11 = R(11);
    r12 = R(12);
    r13 = R(13);
    r14 = R(14);
    r2 = R(2);
    r3 = R(3);
    r8 = R(8);
    r9 = R(9);
    r1 = LD32(0x5EC);
    SETIN(1, r1);
    SETIN(2, r2);
    SETIN(3, r3);
    r0 = GCALL4(r1, r4, r5, r6, r7);
    r0 = r0 ^ r0;
    r1 = R(1);
    r2 = R(2);
    r3 = R(3);
    SETGBR(r0);
    r4 = R(4);
    r5 = R(5);
    r6 = R(6);
    r6 = r6 ^ r6;
    SETPR(r0);
    r7 = R(7);
    SETSR(r0);
    r0 = GJUMP3(0x06002E20, 0, 0, r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06002100(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    int v8;
    int v40;

    r1 = R(1);
    r3 = LD32(0x06000260);
    ST32(0x06002D7C, r3);
    r3 = LD32(0x06000300);
    SETIN(1, r1);
    r0 = GCALL4(r3, 64, 0x060022E4, r6, r7);
    r2 = LD32(0x06000344);
    SETIN(0, r0);
    r0 = GCALL2(r2, -2, 0);
    r0 = SR();
    SETSR(((r0 & -241) | 0));
    GCALL0(0x0600255C);
    r0 = GCALL0(0x06002594);
    r0 = GCALL0(0x060023E6);
    r0 = GCALL3(0x0600245C, 0x25E06000, 0x1000, 0);
    r2 = LD32(0x5E4);
    SETIN(0, r0);
    r0 = GCALL3(r2, 0x25E06000, 0x1000, 0);
    r3 = LD32(0x5E8);
    SETIN(0, r0);
    r0 = GCALL2(r3, 0x0600276C, 0x0600278D);
    r1 = R(1);
    SETIN(1, r1);
    r0 = GCALL3(0x060026DC, 0x060027DC, 0x25E04000, 0x59F);
    r2 = LD32(0x06000248);
    if (((r2 & 0x800) & (r2 & 0x800)) == 0) {
        v40 = 0x25E06498;
    } else {
        v40 = 0x25E06598;
    }
    r7 = 6;
    r0 = GCALL5(0x06002486, v40, 0x200, 18, 6, v40);
    r6 = 16;
    r5 = 0x25F00000;
    GCALL5(0x06002404, 0x060027BC, 0x25F00000, 16, 0, v40);
    r0 = GCALL5(0x06002280, 0, 0, 0, 0, v40);
    r2 = LD32(0x06002D7C);
    v8 = r2;
    r3 = LD32(0x06000248);
    if (((r3 & 0x800) & (r3 & 0x800)) == 0) {
        ST16(v8, 0x8000);
        ST32(0x06002D80, 120);
    } else {
        ST16(v8, 0x8020);
        ST32(0x06002D80, 100);
    }
    r0 = GCALL5(0x06002510, 32, 0, 0, 0, v40);
    r2 = LD32(0x00200000);
    r4 = R(4);
    SETIN(0, r0);
    r0 = GCALL5(r2, r4, r5, r6, r7, v40);
    while (1) {
        r0 = LD32(0x06002D80);
        if (!((r0 & r0) == 0)) {
            POLL();
            r0 = GCALL5(0x060023E6, 0, 0, 0, 0, v40);
            continue;
        } else {
            break;
        }
    }
    r3 = LD32(0x06000344);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r3, -1, 1, r6, r7, v40);
    r2 = LD32(0x06000300);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r2, 64, 0, r6, r7, v40);
    r0 = GCALL5(0x06002348, 0, 0, 0, 0, v40);
    r4 = R(4);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL5(0x06002D88, 0, 0, 0, 0, v40);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060026DC(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, c2008, c2009;

    r1 = R(1);
    r2 = R(2);
    r8 = R(8);
    r7 = r6;
    r9 = r5;
    r3 = r4;
    r8 = r8 ^ r8;
    SETIN(1, r1);
    SETIN(2, (r2 ^ r2));
    do {
        r6 = LD8(r3);
        r3 = r3 + 1;
        c2008 = R(8);
        SETR(8, r8);
        c2009 = R(9);
        SETR(9, r9);
        SETIN(0, ((int)((unsigned)((int)((unsigned)(r6 & 255) >> 2)) >> 2)));
        r1 = R(1);
        SETIN(1, r1);
        r2 = R(2);
        SETIN(2, r2);
        GCALL0(0x0600270A);
        SETR(8, c2008);
        SETR(9, c2009);
        r0 = r6 & 15;
        c2008 = R(8);
        SETR(8, r8);
        c2009 = R(9);
        SETR(9, r9);
        SETIN(0, r0);
        r1 = R(1);
        SETIN(1, r1);
        r2 = R(2);
        SETIN(2, r2);
        GCALL0(0x0600270A);
        SETR(8, c2008);
        SETR(9, c2009);
        r7 = r7 - 1;
    } while (AGAIN(!(r7 == 0)));
    return r0;
}
