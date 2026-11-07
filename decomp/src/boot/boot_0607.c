#include "krnl.h"

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06070A18(int r4)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD32(0x0608F458);
    ST32(r1 + 60, r4);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06071558(int r4, int r5)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD32(0x0608F458);
    ST32((r1 + 76), r4);
    ST32((r1 + 80), r5);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071B34(int r4)
{
    int r0;
    FRAME(sp, 4);

    r4 = ((r4 << 2) << 2) - 116;
    r0 = LD32(r4);
    r0 = r0 | 1;
    ST32(r4, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06071B48(int r4)
{
    int r1;
    FRAME(sp, 4);

    r4 = ((r4 << 2) << 2) - 116;
    r1 = LD32(r4);
    ST32(r4, (r1 & -2));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06071B60(void)
{
    int r2;
    FRAME(sp, 4);

    r2 = LD32(-80);
    ST32(-80, (r2 & -2));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071B74(int r4)
{
    int r0;
    FRAME(sp, 4);

    r0 = LD32(-80);
    ST32(r4, (4 & r0));
    r0 = r0 & 2;
    ST32(r4 + 4, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071B8C(int r4)
{
    int r0;
    FRAME(sp, 4);

    r0 = LD32((((r4 << 2) << 2) - 116));
    return r0 & 2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060726C0(int r4)
{
    int r0, r1, r2, r7;
    FRAME(sp, 4);

    r0 = SR();
    r2 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    SETSR((r0 | 240));
    r7 = LD32(0x06089768);
    ST32(r4, r7);
    r4 = r4 + 4;
    r7 = LD32(0x0608976C);
    ST32(r4, r7);
    r1 = LD32(0x06089770);
    ST32(r4 + 4, r1);
    r1 = SR();
    SETSR(((r1 & -241) | ((r2 << 2) << 2)));
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06072700(int r4, int r5)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD8(r4);
    ST8(r5, r1);
    r1 = LD8((r4 + 1));
    ST8((r5 + 4), r1);
    r1 = LD8((r4 + 2));
    ST8((r5 + 5), r1);
    r1 = LD8((r4 + 3));
    r4 = r4 + 4;
    ST8((r5 + 6), r1);
    r1 = LD8(r4);
    ST8((r5 + 7), r1);
    r1 = LD32(r4);
    ST32(r5 + 8, (r1 & 0x00FFFFFF));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0607277E(int r4)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A0(int r4)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060727E0(int r4, int r5)
{
    int r0;

    r0 = LD32(r5 + 44);
    ST32(r4 + 44, r0);
    r0 = LD32(r5 + 40);
    ST32(r4 + 40, r0);
    r0 = LD32(r5 + 36);
    ST32(r4 + 36, r0);
    r0 = LD32(r5 + 32);
    ST32(r4 + 32, r0);
    r0 = LD32(r5 + 28);
    ST32(r4 + 28, r0);
    r0 = LD32(r5 + 24);
    ST32(r4 + 24, r0);
    r0 = LD32(r5 + 20);
    ST32(r4 + 20, r0);
    r0 = LD32(r5 + 16);
    ST32(r4 + 16, r0);
    r0 = LD32(r5 + 12);
    ST32(r4 + 12, r0);
    r0 = LD32(r5 + 8);
    ST32(r4 + 8, r0);
    r0 = LD32(r5 + 4);
    ST32(r4 + 4, r0);
    r0 = LD32(r5);
    ST32(r4, r0);
    return r0 | r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072820(int r4, int r5, int r6, int r7)
{
    int r0;

    while (1) {
        r0 = LD32(r5 + 60);
        ST32(r4 + 60, r0);
        r0 = LD32(r5 + 56);
        ST32(r4 + 56, r0);
        r0 = LD32(r5 + 52);
        ST32(r4 + 52, r0);
        r0 = LD32(r5 + 48);
        ST32(r4 + 48, r0);
        r0 = LD32(r5 + 44);
        ST32(r4 + 44, r0);
        r0 = LD32(r5 + 40);
        ST32(r4 + 40, r0);
        r0 = LD32(r5 + 36);
        ST32(r4 + 36, r0);
        r0 = LD32(r5 + 32);
        ST32(r4 + 32, r0);
        r0 = LD32(r5 + 28);
        ST32(r4 + 28, r0);
        r0 = LD32(r5 + 24);
        ST32(r4 + 24, r0);
        r0 = LD32(r5 + 20);
        ST32(r4 + 20, r0);
        r0 = LD32(r5 + 16);
        ST32(r4 + 16, r0);
        r0 = LD32(r5 + 12);
        ST32(r4 + 12, r0);
        r0 = LD32(r5 + 8);
        ST32(r4 + 8, r0);
        r0 = LD32(r5 + 4);
        ST32(r4 + 4, r0);
        r0 = LD32(r5);
        ST32(r4, r0);
        r6 = r6 - 16;
        if (!(r6 > 0)) {
            POLL();
            break;
        } else {
            r5 = r5 + 64;
            r4 = r4 + 64;
        }
        POLL();
    }
    POLL();
    r0 = GJUMP4((0x06072810 + (r6 << 2)), (r4 + 64), (r5 + 64), (r6 << 2), r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070020(int r4)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r2 = LD32(0x0608F458);
    r1 = LD32(r2 + 48);
    if (!((r1 & r1) == 0)) {
        r1 = LD32(r2 + 56);
        r0 = -9;
        if (r1 == r4) {
            ST32(r2 + 48, 0);
            r0 = 0;
        }
    } else {
        r0 = -7;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607004C(int r4)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r2 = LD32(0x0608F458);
    r1 = LD32(r2 + 48);
    if ((r1 & r1) == 0) {
        r0 = 0;
    } else {
        r1 = LD32(r2 + 56);
        r0 = r1 == r4;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070070(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r14, c2;
    FRAME(sp, 20);

    r3 = r4;
    r4 = 0x0608F458;
    r2 = LD32(0x0608F458);
    r8 = r7;
    r7 = LD32((r2 + 84));
    r0 = LD8(((r2 + r3) + 24));
    r14 = sp - 20;
    if (r0 == 1) {
        r2 = r2 + 88;
        if (!(r7 > 23)) {
            r1 = LD32(r2);
            c2 = (r1 & r1) == 0;
            r9 = c2;
            if (c2) {
                ST32(r2, r9);
            }
            r1 = LD32(r4);
            r7 = (r7 << 2) << 2;
            ST8(((r1 + r7) + 92), r3);
            r1 = LD32(r4);
            ST8(((r1 + r7) + 93), r5);
            r3 = LD32(r4);
            r1 = LD8(r6);
            r6 = r6 + 1;
            r3 = r3 + r7;
            ST8((r3 + 94), r1);
            r1 = r6;
            r2 = LD8(r1);
            r1 = r1 + 1;
            ST8((r3 + 95), r2);
            r2 = LD8(r1);
            r1 = r1 + 1;
            ST8((r3 + 96), r2);
            r2 = LD8(r1);
            r1 = r1 + 1;
            ST8((r3 + 97), r2);
            r2 = LD8(r1);
            ST8((r3 + 98), r2);
            r1 = LD8((r1 + 1));
            ST8((r3 + 99), r1);
            r3 = LD32(r4);
            r1 = r3 + r7;
            ST32((r1 + 100), r8);
            r9 = LD32(r14 + 20);
            r3 = r3 + 84;
            ST32((r1 + 104), r9);
            r1 = LD32(r3);
            ST32(r3, (r1 + 1));
            r0 = GCALL4(0x06070A68, r14, 0, r6, r7);
            r0 = 0;
        } else {
            r0 = -8;
        }
    } else {
        r0 = -7;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070134(int r4, int r5, int r6)
{
    int r0, r8, r9, c0, c1;
    FRAME(sp, 16);

    r8 = r4;
    r9 = r6;
    r0 = GCALL2(0x060720C4, r4, r5);
    c0 = (r0 & r0) == 0;
    r0 = -10;
    if (c0) {
        r0 = GCALL2(0x06072014, r8, r9);
        c1 = (r0 & r0) == 0;
        r0 = -10;
        if (c1) {
            r0 = GCALL0(0x0607152C);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607017C(int r4, int r5)
{
    int r0, r1, r2, r3, r14, c1, c2;
    FRAME(sp, 12);

    r14 = sp - 12;
    if (r4 == 255) {
        r2 = LD32(0x0608F458);
        r1 = LD32(r2 + 56);
        c2 = r1 == r5;
        r3 = c2;
        if (!(c2)) {
            r0 = -9;
        } else {
            ST32(0x304 + r2, r3);
            ST32(0x308 + r2, r4);
            r0 = GCALL1(0x06070C2C, r14);
            r0 = 0;
        }
    } else {
        r1 = LD32(0x0608F458);
        r0 = LD8(((r1 + r4) + 24));
        c1 = r0 == 1;
        r0 = -7;
        if (c1) {
            r2 = LD32(0x0608F458);
            r1 = LD32(r2 + 56);
            c2 = r1 == r5;
            r3 = c2;
            if (!(c2)) {
                r0 = -9;
            } else {
                ST32(0x304 + r2, r3);
                ST32(0x308 + r2, r4);
                r0 = GCALL1(0x06070C2C, r14);
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060701D4(int r4, int r5)
{
    int r0, r1, r8, r14;
    FRAME(sp, 24);

    r1 = LD32(0x0608F458);
    r14 = sp - 24;
    r1 = LD32(r1 + 56);
    r8 = r4;
    if (r1 == r5) {
        r0 = GCALL1(0x060703C8, r14);
        r0 = LD32(0x0608F454);
        if ((r0 & r0) == 0) {
            r0 = GCALL1(0x0606C2FC, -21);
            r0 = GCALL1(0x060721D0, r8);
            ST32(0x0608F45C, 1);
            r0 = 0;
        }
    } else {
        r0 = -9;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070234(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r14;
    FRAME(sp, 16);

    r2 = LD32(0x0608F458);
    r3 = r2 + 0x30C;
    r1 = LD32(r3);
    r14 = sp - 16;
    if (!((r1 & r1) == 0)) {
        r0 = -1;
    } else {
        ST32(r3, 1);
        ST32(0x310 + r2, r4);
        ST32(0x314 + r2, r5);
        ST32(0x318 + r2, r6);
        ST32(0x31C + r2, 0);
        ST32(0x320 + r2, r7);
        r8 = LD32(r14 + 16);
        ST32(0x324 + r2, r8);
        r0 = GCALL1(0x06070CBC, r14);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607029C(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r14, c1;
    FRAME(sp, 12);

    r2 = LD32(0x0608F458);
    r3 = r2 + 0x328;
    r1 = LD32(r3);
    r14 = sp - 12;
    if ((r1 & r1) == 0) {
        r0 = LD32(r2 + 52);
        c1 = r0 == -1;
        r7 = c1;
        if (!(c1)) {
            r0 = -5;
        } else {
            ST32(r2 + 52, r4);
            ST32(r3, r7);
            ST32(0x32C + r2, r4);
            ST32(0x330 + r2, r5);
            ST32(0x334 + r2, r6);
            r0 = GCALL1(0x06070E10, r14);
            r0 = 0;
        }
    } else {
        r0 = -1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060702F8(int r4)
{
    int r0, r1, r8;
    FRAME(sp, 12);

    r8 = 0x0608F458;
    r1 = LD32(0x0608F458);
    r0 = LD32(r1 + 52);
    if (!(r0 == -1)) {
        r0 = GCALL1(0x06071990, r4);
        r1 = LD32(r8);
        ST32(r1 + 52, -1);
        if (!((r0 & r0) == 0)) {
            r0 = -10;
        } else {
            r0 = GCALL0(0x0607152C);
            r0 = 0;
        }
    } else {
        r0 = -7;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070340(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r14;
    FRAME(sp, 12);

    r2 = LD32(0x0608F458);
    r3 = r2 + 0x338;
    r1 = LD32(r3);
    r14 = sp - 12;
    if ((r1 & r1) == 0) {
        r1 = LD32(r2 + 52);
        r7 = 1;
        if (r1 == r4) {
            r0 = -5;
        } else {
            ST32(r3, r7);
            ST32(0x33C + r2, r4);
            ST32(0x340 + r2, r5);
            ST32(0x344 + r2, r6);
            r0 = GCALL1(0x06070EB0, r14);
            r0 = 0;
        }
    } else {
        r0 = -1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070398(int r4)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r2 = LD32(0x0608F458);
    r1 = LD32(0x338 + r2);
    if ((r1 & r1) == 0) {
        r0 = 1;
    } else {
        r1 = LD32(0x33C + r2);
        r0 = 1;
        if (r1 == r4) {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607047C(int r4, int r5)
{
    int r0, r1, r8, r14;
    FRAME(sp, 24);

    r1 = LD32(0x0608F458);
    r14 = sp - 24;
    r1 = LD32(r1 + 56);
    r8 = r4;
    if (r1 == r5) {
        r0 = GCALL1(0x060703C8, r14);
        r0 = LD32(0x0608F454);
        if ((r0 & r0) == 0) {
            r0 = GCALL1(0x0607229C, r8);
            r0 = 0;
        }
    } else {
        r0 = -9;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060704C8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r14, c2;
    FRAME(sp, 16);

    r2 = LD32(0x0608F458);
    r1 = LD8(((r2 + r4) + 24));
    r14 = sp - 16;
    if ((r1 & r1) == 0) {
        r0 = -7;
    } else {
        r1 = LD8(((r2 + r5) + 24));
        r3 = r2;
        if (!((r1 & r1) == 0)) {
            r3 = r3 + 0x348;
            r1 = LD32(r3);
            c2 = (r1 & r1) == 0;
            r8 = c2;
            if (!(c2)) {
                r0 = -1;
            } else {
                ST32(r3, r8);
                ST32(0x34C + r2, r4);
                ST32(0x350 + r2, r5);
                ST32(0x354 + r2, r6);
                ST32(0x358 + r2, r7);
                r0 = GCALL1(0x06070FE4, r14);
                r0 = 0;
            }
        } else {
            r0 = -7;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607053C(void)
{
    int r0, r1;
    FRAME(sp, 4);

    r1 = LD32(0x0608F458);
    r1 = LD32(0x348 + r1);
    if (!((r1 & r1) == 0)) {
        r0 = 0;
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070560(int r4, int r5, int r6)
{
    int r0, r1, r2, c2;
    FRAME(sp, 8);

    r2 = r4;
    if (!((unsigned)r2 > (unsigned)23)) {
        r1 = LD32(0x0608F458);
        r1 = LD8(r1 + r2);
        r0 = -7;
        if (!((r1 & r1) == 0)) {
            r0 = GCALL3(0x0607245C, r2, r5, r6);
            c2 = (r0 & r0) == 0;
            r0 = -10;
            if (c2) {
                r0 = GCALL0(0x0607152C);
                r0 = 0;
            }
        }
    } else {
        r0 = -6;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060705A8(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r14;
    FRAME(sp, 12);

    r3 = LD32(0x0608F458);
    r14 = sp - 12;
    r2 = r3 + r5;
    r0 = LD8((r2 + 24));
    r7 = r4;
    if (!(r0 == 1)) {
        r0 = -5;
    } else {
        r0 = LD8(r2);
        r2 = r3;
        if (r0 == 1) {
            r2 = r2 + 0x360;
            r1 = LD32(r2);
            r0 = -1;
            if ((r1 & r1) == 0) {
                r0 = 1;
                if (r7 == -1) {
                    r0 = 3;
                }
                ST32(r2, r0);
                r1 = LD32(0x0608F458);
                ST16(0x364 + r1, r7);
                ST16(0x366 + r1, r5);
                ST32(0x368 + r1, r6);
                r0 = GCALL1(0x06071148, r14);
                r0 = 0;
            }
        } else {
            r0 = -5;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070704(int r4, int r5)
{
    int r0, r1, r2, r6, r8, r9, r10, r11, r14, c3, c9, c10;
    FRAME(sp, 36);

    r14 = sp - 36;
    r9 = r4;
    r11 = r5;
    r0 = GCALL3(0x06071C08, r14, (r14 + 4), (r14 + 8));
    r2 = LD32(r14);
    if (!((r0 & r0) == 0)) {
        r0 = -11;
    } else {
        r5 = r9;
        if (!(r9 >= r2)) {
            r0 = GCALL2(0x06071BD4, 23, r5);
            c3 = (r0 & r0) == 0;
            r0 = -11;
            if (c3) {
                r8 = 0x200;
                r10 = 0x06071488;
                do {
                    r0 = GCALL1(r10, r8);
                    r6 = r14;
                } while (AGAIN((r0 & r0) == 0));
                r0 = GCALL3(0x06071C08, r14, (r14 + 4), (r6 + 8));
                r2 = LD32(r14);
                if (!((r0 & r0) == 0)) {
                    r0 = -11;
                } else {
                    r1 = LD32(r14 + 4);
                    if (r9 >= r2) {
                        r0 = GCALL2(0x06071C68, r9, r11);
                        r5 = r11;
                        if ((r0 & r0) == 0) {
                            r5 = r5 + 11;
                            r0 = LD8(r5);
                            c9 = ((2 & r0) & (2 & r0)) == 0;
                            r0 = r0 | 128;
                            if (!(c9)) {
                                ST8(r5, r0);
                            }
                            r1 = LD32(r14 + 8);
                            c10 = (r1 & r1) == 0;
                            r1 = LD32(r14);
                            if (!(c10)) {
                                r2 = LD32(r14 + 4);
                                if (((r1 + r2) - 1) == r9) {
                                    r0 = LD8(r5);
                                    ST8(r5, (r0 | 1));
                                }
                            }
                            r0 = GCALL0(0x0607152C);
                            r0 = 0;
                        } else {
                            r0 = -11;
                        }
                    } else {
                        r0 = -11;
                        if ((r1 + r2) > r9) {
                            r0 = GCALL2(0x06071C68, r9, r11);
                            r5 = r11;
                            if ((r0 & r0) == 0) {
                                r5 = r5 + 11;
                                r0 = LD8(r5);
                                c9 = ((2 & r0) & (2 & r0)) == 0;
                                r0 = r0 | 128;
                                if (!(c9)) {
                                    ST8(r5, r0);
                                }
                                r1 = LD32(r14 + 8);
                                c10 = (r1 & r1) == 0;
                                r1 = LD32(r14);
                                if (!(c10)) {
                                    r2 = LD32(r14 + 4);
                                    if (((r1 + r2) - 1) == r9) {
                                        r0 = LD8(r5);
                                        ST8(r5, (r0 | 1));
                                    }
                                }
                                r0 = GCALL0(0x0607152C);
                                r0 = 0;
                            } else {
                                r0 = -11;
                            }
                        }
                    }
                }
            }
        } else {
            r1 = LD32(r14 + 4);
            if ((r1 + r2) > r9) {
                r0 = GCALL2(0x06071C68, r9, r11);
                r5 = r11;
                if ((r0 & r0) == 0) {
                    r5 = r5 + 11;
                    r0 = LD8(r5);
                    c9 = ((2 & r0) & (2 & r0)) == 0;
                    r0 = r0 | 128;
                    if (!(c9)) {
                        ST8(r5, r0);
                    }
                    r1 = LD32(r14 + 8);
                    c10 = (r1 & r1) == 0;
                    r1 = LD32(r14);
                    if (!(c10)) {
                        r2 = LD32(r14 + 4);
                        if (((r1 + r2) - 1) == r9) {
                            r0 = LD8(r5);
                            ST8(r5, (r0 | 1));
                        }
                    }
                    r0 = GCALL0(0x0607152C);
                    r0 = 0;
                } else {
                    r0 = -11;
                }
            } else {
                r0 = GCALL2(0x06071BD4, 23, r5);
                c3 = (r0 & r0) == 0;
                r0 = -11;
                if (c3) {
                    r8 = 0x200;
                    r10 = 0x06071488;
                    do {
                        r0 = GCALL1(r10, r8);
                        r6 = r14;
                    } while (AGAIN((r0 & r0) == 0));
                    r0 = GCALL3(0x06071C08, r14, (r14 + 4), (r6 + 8));
                    r2 = LD32(r14);
                    if (!((r0 & r0) == 0)) {
                        r0 = -11;
                    } else {
                        r1 = LD32(r14 + 4);
                        if (r9 >= r2) {
                            r0 = GCALL2(0x06071C68, r9, r11);
                            r5 = r11;
                            if ((r0 & r0) == 0) {
                                r5 = r5 + 11;
                                r0 = LD8(r5);
                                c9 = ((2 & r0) & (2 & r0)) == 0;
                                r0 = r0 | 128;
                                if (!(c9)) {
                                    ST8(r5, r0);
                                }
                                r1 = LD32(r14 + 8);
                                c10 = (r1 & r1) == 0;
                                r1 = LD32(r14);
                                if (!(c10)) {
                                    r2 = LD32(r14 + 4);
                                    if (((r1 + r2) - 1) == r9) {
                                        r0 = LD8(r5);
                                        ST8(r5, (r0 | 1));
                                    }
                                }
                                r0 = GCALL0(0x0607152C);
                                r0 = 0;
                            } else {
                                r0 = -11;
                            }
                        } else {
                            r0 = -11;
                            if ((r1 + r2) > r9) {
                                r0 = GCALL2(0x06071C68, r9, r11);
                                r5 = r11;
                                if ((r0 & r0) == 0) {
                                    r5 = r5 + 11;
                                    r0 = LD8(r5);
                                    c9 = ((2 & r0) & (2 & r0)) == 0;
                                    r0 = r0 | 128;
                                    if (!(c9)) {
                                        ST8(r5, r0);
                                    }
                                    r1 = LD32(r14 + 8);
                                    c10 = (r1 & r1) == 0;
                                    r1 = LD32(r14);
                                    if (!(c10)) {
                                        r2 = LD32(r14 + 4);
                                        if (((r1 + r2) - 1) == r9) {
                                            r0 = LD8(r5);
                                            ST8(r5, (r0 | 1));
                                        }
                                    }
                                    r0 = GCALL0(0x0607152C);
                                    r0 = 0;
                                } else {
                                    r0 = -11;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060707E0(void)
{
    int r0, r14, c0;
    FRAME(sp, 20);

    r14 = sp - 20;
    r0 = GCALL3(0x06072300, r14, (r14 + 4), (r14 + 8));
    c0 = (r0 & r0) == 0;
    r0 = -10;
    if (c0) {
        r0 = GCALL0(0x0607152C);
        r0 = LD32(r14 + 8);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070C2C(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10;
    FRAME(sp, 20);

    r10 = 0x0608F458;
    r1 = LD32(0x0608F458);
    r9 = 0x304;
    r2 = LD32(r1 + 0x304);
    r8 = r4;
    if (r2 == 1) {
        r4 = LD32(0x308 + r1);
        r0 = GCALL1(0x06072570, r4);
        r1 = LD32(r8);
        ST32(r8, (r1 + 1));
        if ((r0 & r0) == 0) {
            r1 = LD32(r10);
            ST32(r1 + r9, 2);
        }
        r0 = GCALL0(0x0607152C);
    }
    r9 = 0x0608F458;
    r1 = LD32(0x0608F458);
    r8 = 0x304;
    r1 = LD32(r1 + 0x304);
    if (r1 == 2) {
        r0 = GCALL1(0x06071488, 64);
        r3 = 0;
        if (!((r0 & r0) == 0)) {
            r1 = LD32(r9);
            ST32(r1 + r8, r3);
        }
    }
    r1 = LD32(0x0608F458);
    r0 = LD32((r1 + 0x304));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070CBC(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r14, c2, c5, c6;
    FRAME(sp, 28);

    r14 = sp - 28;
    r10 = 0x0608F458;
    r1 = LD32(0x0608F458);
    r8 = 0x30C;
    r2 = LD32(r1 + 0x30C);
    r9 = r4;
    if (!(r2 == 1)) {
        r3 = LD32(r10);
        r8 = 0x30C;
        r1 = LD32(r3 + 0x30C);
        if (!(r1 == 2)) {
            r8 = 0x0608F458;
            r1 = LD32(0x0608F458);
            r10 = 0x30C;
            r1 = LD32(r1 + 0x30C);
            r0 = 1;
            if (r1 == 3) {
                r0 = GCALL1(0x060723DC, (r14 + 4));
                if (!((r0 & r0) == 0)) {
                    r0 = 1;
                } else {
                    r0 = GCALL0(0x0607152C);
                    r1 = LD32(r9);
                    ST32(r9, (r1 + 1));
                    r1 = LD32(r8);
                    r0 = r1;
                    ST32(r0 + r10, 0);
                    r2 = LD32(r0 + 0x324);
                    r1 = LD32(r14 + 4);
                    ST32(r2, (r1 + r1));
                    r1 = LD32(r8);
                    ST32(r1 + 52, -1);
                    r0 = 0;
                }
            }
        } else {
            r0 = LD32(r3 + 52);
            c5 = r0 == -1;
            r0 = 2;
            if (c5) {
                r2 = r3 + 0x310;
                r7 = LD32(r2);
                r0 = r3;
                ST32(r3 + 52, r7);
                r1 = LD32(r0 + 0x320);
                r6 = LD32(r1);
                r4 = LD32(r2);
                r5 = LD32(r0 + 0x314);
                r0 = GCALL3(0x060723A0, r4, r5, r6);
                c6 = (r0 & r0) == 0;
                r0 = 2;
                if (c6) {
                    r0 = GCALL0(0x0607152C);
                    r1 = LD32(r9);
                    ST32(r9, (r1 + 1));
                    r1 = LD32(r10);
                    ST32(r1 + r8, 3);
                    r8 = 0x0608F458;
                    r1 = LD32(0x0608F458);
                    r10 = 0x30C;
                    r1 = LD32(r1 + 0x30C);
                    r0 = 1;
                    if (r1 == 3) {
                        r0 = GCALL1(0x060723DC, (r14 + 4));
                        if (!((r0 & r0) == 0)) {
                            r0 = 1;
                        } else {
                            r0 = GCALL0(0x0607152C);
                            r1 = LD32(r9);
                            ST32(r9, (r1 + 1));
                            r1 = LD32(r8);
                            r0 = r1;
                            ST32(r0 + r10, 0);
                            r2 = LD32(r0 + 0x324);
                            r1 = LD32(r14 + 4);
                            ST32(r2, (r1 + r1));
                            r1 = LD32(r8);
                            ST32(r1 + 52, -1);
                            r0 = 0;
                        }
                    }
                }
            }
        }
    } else {
        r4 = LD32(0x310 + r1);
        r0 = GCALL2(0x0607235C, r4, r14);
        r0 = GCALL0(0x0607152C);
        r1 = LD32(r9);
        ST32(r9, (r1 + 1));
        r3 = LD32(r10);
        r1 = LD32(r14);
        r2 = LD32(0x314 + r3);
        r1 = r1 - r2;
        ST32(r14, r1);
        r2 = r1;
        r1 = LD32(0x318 + r3);
        if (r2 > r1) {
            r2 = r1;
        }
        r1 = LD32(0x320 + r3);
        ST32(r14, r2);
        ST32(r1, r2);
        r2 = LD32(r10);
        r3 = r2 + 0x324;
        r1 = LD32(r3);
        c2 = (r1 & r1) == 0;
        r1 = LD32(r14);
        if (!(c2)) {
            r7 = 0;
            if (r1 > 0) {
                ST32(r2 + r8, 2);
                r10 = 0x0608F458;
                r3 = LD32(r10);
                r8 = 0x30C;
                r1 = LD32(r3 + 0x30C);
                if (!(r1 == 2)) {
                    r8 = 0x0608F458;
                    r1 = LD32(0x0608F458);
                    r10 = 0x30C;
                    r1 = LD32(r1 + 0x30C);
                    r0 = 1;
                    if (r1 == 3) {
                        r0 = GCALL1(0x060723DC, (r14 + 4));
                        if (!((r0 & r0) == 0)) {
                            r0 = 1;
                        } else {
                            r0 = GCALL0(0x0607152C);
                            r1 = LD32(r9);
                            ST32(r9, (r1 + 1));
                            r1 = LD32(r8);
                            r0 = r1;
                            ST32(r0 + r10, 0);
                            r2 = LD32(r0 + 0x324);
                            r1 = LD32(r14 + 4);
                            ST32(r2, (r1 + r1));
                            r1 = LD32(r8);
                            ST32(r1 + 52, -1);
                            r0 = 0;
                        }
                    }
                } else {
                    r0 = LD32(r3 + 52);
                    c5 = r0 == -1;
                    r0 = 2;
                    if (c5) {
                        r2 = r3 + 0x310;
                        r7 = LD32(r2);
                        r0 = r3;
                        ST32(r3 + 52, r7);
                        r1 = LD32(r0 + 0x320);
                        r6 = LD32(r1);
                        r4 = LD32(r2);
                        r5 = LD32(r0 + 0x314);
                        r0 = GCALL3(0x060723A0, r4, r5, r6);
                        c6 = (r0 & r0) == 0;
                        r0 = 2;
                        if (c6) {
                            r0 = GCALL0(0x0607152C);
                            r1 = LD32(r9);
                            ST32(r9, (r1 + 1));
                            r1 = LD32(r10);
                            ST32(r1 + r8, 3);
                            r8 = 0x0608F458;
                            r1 = LD32(0x0608F458);
                            r10 = 0x30C;
                            r1 = LD32(r1 + 0x30C);
                            r0 = 1;
                            if (r1 == 3) {
                                r0 = GCALL1(0x060723DC, (r14 + 4));
                                if (!((r0 & r0) == 0)) {
                                    r0 = 1;
                                } else {
                                    r0 = GCALL0(0x0607152C);
                                    r1 = LD32(r9);
                                    ST32(r9, (r1 + 1));
                                    r1 = LD32(r8);
                                    r0 = r1;
                                    ST32(r0 + r10, 0);
                                    r2 = LD32(r0 + 0x324);
                                    r1 = LD32(r14 + 4);
                                    ST32(r2, (r1 + r1));
                                    r1 = LD32(r8);
                                    ST32(r1 + 52, -1);
                                    r0 = 0;
                                }
                            }
                        }
                    }
                }
            } else {
                ST32(r2 + r8, r7);
                r1 = LD32(r3);
                r0 = 0;
                ST32(r1, 0);
            }
        } else {
            ST32(r2 + r8, 0);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070E10(int r4)
{
    int r0, r1, r2, r5, r6, r8, r9, r10, c1;
    FRAME(sp, 20);

    r10 = 0x0608F458;
    r1 = LD32(0x0608F458);
    r9 = 0x328;
    r2 = LD32(r1 + 0x328);
    r8 = r4;
    if (!(r2 == 1)) {
        r9 = 0x0608F458;
        r1 = LD32(0x0608F458);
        r8 = 0x328;
        r1 = LD32(r1 + 0x328);
        r0 = 1;
        if (r1 == 2) {
            r0 = GCALL1(0x06071924, 0);
            r2 = 0;
            if (!((r0 & r0) == 0)) {
                r0 = 1;
            } else {
                r1 = LD32(r9);
                ST32(r1 + r8, r2);
                r0 = 0;
            }
        }
    } else {
        r6 = LD32(0x334 + r1);
        r5 = LD32(0x330 + r1);
        r4 = LD32(0x32C + r1);
        r0 = GCALL3(0x06071D68, r4, r5, r6);
        c1 = (r0 & r0) == 0;
        r0 = 1;
        if (c1) {
            r0 = GCALL0(0x0607152C);
            r1 = LD32(r8);
            ST32(r8, (r1 + 1));
            r1 = LD32(r10);
            ST32(r1 + r9, 2);
            r9 = 0x0608F458;
            r1 = LD32(0x0608F458);
            r8 = 0x328;
            r1 = LD32(r1 + 0x328);
            r0 = 1;
            if (r1 == 2) {
                r0 = GCALL1(0x06071924, 0);
                r2 = 0;
                if (!((r0 & r0) == 0)) {
                    r0 = 1;
                } else {
                    r1 = LD32(r9);
                    ST32(r1 + r8, r2);
                    r0 = 0;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070EB0(int r4)
{
    int r0, r1, r2, r3, r5, r6, r8, r9, r10, r11, c3, c9, c10;
    FRAME(sp, 24);

    r8 = r4;
    r11 = 0x0608F458;
    r2 = LD32(0x0608F458);
    r10 = 0x338;
    r1 = LD32(r2 + 0x338);
    r9 = 1;
    if (!(r1 == 1)) {
        r1 = LD32(r11);
        r10 = 0x338;
        r2 = LD32(r1 + 0x338);
        if (r2 == 2) {
            r6 = LD32(0x344 + r1);
            r5 = LD32(0x340 + r1);
            r4 = LD32(0x33C + r1);
            r0 = GCALL3(0x06071DA4, r4, r5, r6);
            r1 = LD32(r8);
            ST32(r8, (r1 + 1));
            if ((r0 & r0) == 0) {
                r1 = LD32(r11);
                ST32(r1 + r10, 3);
                r0 = GCALL0(0x0607152C);
            }
        }
        r1 = LD32(0x0608F458);
        r0 = LD32(0x338 + r1);
        if (r0 == 3) {
            r0 = GCALL1(0x06071488, 128);
            if (!((r0 & r0) == 0)) {
                r9 = 0;
            }
        }
        r1 = LD32(0x0608F458);
        r0 = LD32(0x338 + r1);
        c9 = r0 == 4;
        r0 = r9;
        if (c9) {
            r0 = GCALL1(0x06071488, 64);
            c10 = (r0 & r0) == 0;
            r0 = r9;
            if (!(c10)) {
                r0 = 0;
            }
        }
        if (r0 == 1) {
            r0 = 1;
        } else {
            r0 = GCALL1(0x0606C2FC, -9);
            r1 = LD32(0x0608F458);
            ST32(r1 + 0x338, 0);
            r0 = 0;
        }
    } else {
        r1 = LD32(0x340 + r2);
        if (!((r1 & r1) == 0)) {
            r2 = LD32(0x0608F458);
            r1 = LD32(0x344 + r2);
            r3 = 2;
            if (!((r1 & r1) == 0)) {
                ST32(r2 + 0x338, r3);
            } else {
                r9 = 0;
            }
            r11 = 0x0608F458;
            r1 = LD32(r11);
            r10 = 0x338;
            r2 = LD32(r1 + 0x338);
            if (r2 == 2) {
                r6 = LD32(0x344 + r1);
                r5 = LD32(0x340 + r1);
                r4 = LD32(0x33C + r1);
                r0 = GCALL3(0x06071DA4, r4, r5, r6);
                r1 = LD32(r8);
                ST32(r8, (r1 + 1));
                if ((r0 & r0) == 0) {
                    r1 = LD32(r11);
                    ST32(r1 + r10, 3);
                    r0 = GCALL0(0x0607152C);
                }
            }
            r1 = LD32(0x0608F458);
            r0 = LD32(0x338 + r1);
            if (r0 == 3) {
                r0 = GCALL1(0x06071488, 128);
                if (!((r0 & r0) == 0)) {
                    r9 = 0;
                }
            }
            r1 = LD32(0x0608F458);
            r0 = LD32(0x338 + r1);
            c9 = r0 == 4;
            r0 = r9;
            if (c9) {
                r0 = GCALL1(0x06071488, 64);
                c10 = (r0 & r0) == 0;
                r0 = r9;
                if (!(c10)) {
                    r0 = 0;
                }
            }
            if (r0 == 1) {
                r0 = 1;
            } else {
                r0 = GCALL1(0x0606C2FC, -9);
                r1 = LD32(0x0608F458);
                ST32(r1 + 0x338, 0);
                r0 = 0;
            }
        } else {
            r0 = LD32(0x344 + r2);
            if (!(r0 == -1)) {
                r2 = LD32(0x0608F458);
                r1 = LD32(0x344 + r2);
                r3 = 2;
                if (!((r1 & r1) == 0)) {
                    ST32(r2 + 0x338, r3);
                } else {
                    r9 = 0;
                }
                r11 = 0x0608F458;
                r1 = LD32(r11);
                r10 = 0x338;
                r2 = LD32(r1 + 0x338);
                if (r2 == 2) {
                    r6 = LD32(0x344 + r1);
                    r5 = LD32(0x340 + r1);
                    r4 = LD32(0x33C + r1);
                    r0 = GCALL3(0x06071DA4, r4, r5, r6);
                    r1 = LD32(r8);
                    ST32(r8, (r1 + 1));
                    if ((r0 & r0) == 0) {
                        r1 = LD32(r11);
                        ST32(r1 + r10, 3);
                        r0 = GCALL0(0x0607152C);
                    }
                }
                r1 = LD32(0x0608F458);
                r0 = LD32(0x338 + r1);
                if (r0 == 3) {
                    r0 = GCALL1(0x06071488, 128);
                    if (!((r0 & r0) == 0)) {
                        r9 = 0;
                    }
                }
                r1 = LD32(0x0608F458);
                r0 = LD32(0x338 + r1);
                c9 = r0 == 4;
                r0 = r9;
                if (c9) {
                    r0 = GCALL1(0x06071488, 64);
                    c10 = (r0 & r0) == 0;
                    r0 = r9;
                    if (!(c10)) {
                        r0 = 0;
                    }
                }
                if (r0 == 1) {
                    r0 = 1;
                } else {
                    r0 = GCALL1(0x0606C2FC, -9);
                    r1 = LD32(0x0608F458);
                    ST32(r1 + 0x338, 0);
                    r0 = 0;
                }
            } else {
                r5 = LD32(0x33C + r2);
                r0 = GCALL2(0x0607219C, 0, r5);
                c3 = (r0 & r0) == 0;
                r0 = 1;
                if (c3) {
                    r0 = GCALL0(0x0607152C);
                    r1 = LD32(r8);
                    ST32(r8, (r1 + 1));
                    r1 = LD32(r11);
                    ST32(r1 + r10, 4);
                    r11 = 0x0608F458;
                    r1 = LD32(r11);
                    r10 = 0x338;
                    r2 = LD32(r1 + 0x338);
                    if (r2 == 2) {
                        r6 = LD32(0x344 + r1);
                        r5 = LD32(0x340 + r1);
                        r4 = LD32(0x33C + r1);
                        r0 = GCALL3(0x06071DA4, r4, r5, r6);
                        r1 = LD32(r8);
                        ST32(r8, (r1 + 1));
                        if ((r0 & r0) == 0) {
                            r1 = LD32(r11);
                            ST32(r1 + r10, 3);
                            r0 = GCALL0(0x0607152C);
                        }
                    }
                    r1 = LD32(0x0608F458);
                    r0 = LD32(0x338 + r1);
                    if (r0 == 3) {
                        r0 = GCALL1(0x06071488, 128);
                        if (!((r0 & r0) == 0)) {
                            r9 = 0;
                        }
                    }
                    r1 = LD32(0x0608F458);
                    r0 = LD32(0x338 + r1);
                    c9 = r0 == 4;
                    r0 = r9;
                    if (c9) {
                        r0 = GCALL1(0x06071488, 64);
                        c10 = (r0 & r0) == 0;
                        r0 = r9;
                        if (!(c10)) {
                            r0 = 0;
                        }
                    }
                    if (r0 == 1) {
                        r0 = 1;
                    } else {
                        r0 = GCALL1(0x0606C2FC, -9);
                        r1 = LD32(0x0608F458);
                        ST32(r1 + 0x338, 0);
                        r0 = 0;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070FE4(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r12, c1, c3, c7;
    FRAME(sp, 28);

    r10 = 0x0608F458;
    r2 = LD32(0x0608F458);
    r12 = 0x348;
    r1 = LD32(r2 + 0x348);
    r8 = r4;
    if (!(r1 == 1)) {
        r1 = LD32(r10);
        r9 = 0x348;
        r2 = LD32(r1 + 0x348);
        r0 = r1;
        if (!(r2 == 2)) {
            r1 = LD32(r0 + r9);
            if (r1 == 3) {
                r0 = GCALL1(0x06071488, 0x100);
                if (!((r0 & r0) == 0)) {
                    r1 = LD32(r10);
                    ST32(r1 + r9, 4);
                }
            }
            r10 = 0x0608F458;
            r1 = LD32(0x0608F458);
            r9 = 0x348;
            r2 = LD32(r1 + 0x348);
            if (!(r2 == 4)) {
                r9 = 0x0608F458;
                r1 = LD32(0x0608F458);
                r8 = 0x348;
                r1 = LD32(r1 + 0x348);
                if (r1 == 5) {
                    r0 = GCALL1(0x06071488, 64);
                    r3 = 0;
                    if (r0 == 1) {
                        r1 = LD32(r9);
                        ST32(r1 + r8, r3);
                    }
                }
                r1 = LD32(0x0608F458);
                r0 = LD32((r1 + 0x348));
            } else {
                r5 = LD32(0x35C + r1);
                r4 = LD32(0x34C + r1);
                r0 = GCALL2(0x06072090, r4, r5);
                c7 = (r0 & r0) == 0;
                r0 = 1;
                if (c7) {
                    r1 = LD32(r8);
                    ST32(r8, (r1 + 1));
                    r1 = LD32(r10);
                    ST32(r1 + r9, 5);
                    r9 = 0x0608F458;
                    r1 = LD32(0x0608F458);
                    r8 = 0x348;
                    r1 = LD32(r1 + 0x348);
                    if (r1 == 5) {
                        r0 = GCALL1(0x06071488, 64);
                        r3 = 0;
                        if (r0 == 1) {
                            r1 = LD32(r9);
                            ST32(r1 + r8, r3);
                        }
                    }
                    r1 = LD32(0x0608F458);
                    r0 = LD32((r1 + 0x348));
                }
            }
        } else {
            r7 = LD32(0x34C + r1);
            r6 = LD32(0x358 + r1);
            r5 = LD32(0x354 + r1);
            r4 = LD32(0x350 + r1);
            r0 = GCALL4(0x06071E98, r4, r5, r6, r7);
            c3 = (r0 & r0) == 0;
            r0 = 1;
            if (c3) {
                r0 = GCALL0(0x0607152C);
                r1 = LD32(r8);
                ST32(r8, (r1 + 1));
                r1 = LD32(r10);
                ST32(r1 + r9, 3);
                r10 = 0x0608F458;
                r1 = LD32(0x0608F458);
                r9 = 0x348;
                r0 = r1;
                r1 = LD32(r0 + r9);
                if (r1 == 3) {
                    r0 = GCALL1(0x06071488, 0x100);
                    if (!((r0 & r0) == 0)) {
                        r1 = LD32(r10);
                        ST32(r1 + r9, 4);
                    }
                }
                r10 = 0x0608F458;
                r1 = LD32(0x0608F458);
                r9 = 0x348;
                r2 = LD32(r1 + 0x348);
                if (!(r2 == 4)) {
                    r9 = 0x0608F458;
                    r1 = LD32(0x0608F458);
                    r8 = 0x348;
                    r1 = LD32(r1 + 0x348);
                    if (r1 == 5) {
                        r0 = GCALL1(0x06071488, 64);
                        r3 = 0;
                        if (r0 == 1) {
                            r1 = LD32(r9);
                            ST32(r1 + r8, r3);
                        }
                    }
                    r1 = LD32(0x0608F458);
                    r0 = LD32((r1 + 0x348));
                } else {
                    r5 = LD32(0x35C + r1);
                    r4 = LD32(0x34C + r1);
                    r0 = GCALL2(0x06072090, r4, r5);
                    c7 = (r0 & r0) == 0;
                    r0 = 1;
                    if (c7) {
                        r1 = LD32(r8);
                        ST32(r8, (r1 + 1));
                        r1 = LD32(r10);
                        ST32(r1 + r9, 5);
                        r9 = 0x0608F458;
                        r1 = LD32(0x0608F458);
                        r8 = 0x348;
                        r1 = LD32(r1 + 0x348);
                        if (r1 == 5) {
                            r0 = GCALL1(0x06071488, 64);
                            r3 = 0;
                            if (r0 == 1) {
                                r1 = LD32(r9);
                                ST32(r1 + r8, r3);
                            }
                        }
                        r1 = LD32(0x0608F458);
                        r0 = LD32((r1 + 0x348));
                    }
                }
            }
        }
    } else {
        r4 = LD32(r2 + 0x34C);
        r0 = GCALL2(0x060720C4, r4, (r2 + 0x35C));
        r1 = LD32(r8);
        r9 = 0x0607152C;
        ST32(r8, (r1 + 1));
        r0 = GCALL0(0x0607152C);
        r1 = LD32(r10);
        r4 = LD32(r1 + 0x34C);
        r0 = GCALL2(0x06072090, r4, 0);
        c1 = (r0 & r0) == 0;
        r0 = 1;
        if (c1) {
            r0 = GCALL0(r9);
            r1 = LD32(r8);
            ST32(r8, (r1 + 1));
            r1 = LD32(r10);
            ST32(r1 + r12, 2);
            r10 = 0x0608F458;
            r1 = LD32(r10);
            r9 = 0x348;
            r2 = LD32(r1 + 0x348);
            r0 = r1;
            if (!(r2 == 2)) {
                r1 = LD32(r0 + r9);
                if (r1 == 3) {
                    r0 = GCALL1(0x06071488, 0x100);
                    if (!((r0 & r0) == 0)) {
                        r1 = LD32(r10);
                        ST32(r1 + r9, 4);
                    }
                }
                r10 = 0x0608F458;
                r1 = LD32(0x0608F458);
                r9 = 0x348;
                r2 = LD32(r1 + 0x348);
                if (!(r2 == 4)) {
                    r9 = 0x0608F458;
                    r1 = LD32(0x0608F458);
                    r8 = 0x348;
                    r1 = LD32(r1 + 0x348);
                    if (r1 == 5) {
                        r0 = GCALL1(0x06071488, 64);
                        r3 = 0;
                        if (r0 == 1) {
                            r1 = LD32(r9);
                            ST32(r1 + r8, r3);
                        }
                    }
                    r1 = LD32(0x0608F458);
                    r0 = LD32((r1 + 0x348));
                } else {
                    r5 = LD32(0x35C + r1);
                    r4 = LD32(0x34C + r1);
                    r0 = GCALL2(0x06072090, r4, r5);
                    c7 = (r0 & r0) == 0;
                    r0 = 1;
                    if (c7) {
                        r1 = LD32(r8);
                        ST32(r8, (r1 + 1));
                        r1 = LD32(r10);
                        ST32(r1 + r9, 5);
                        r9 = 0x0608F458;
                        r1 = LD32(0x0608F458);
                        r8 = 0x348;
                        r1 = LD32(r1 + 0x348);
                        if (r1 == 5) {
                            r0 = GCALL1(0x06071488, 64);
                            r3 = 0;
                            if (r0 == 1) {
                                r1 = LD32(r9);
                                ST32(r1 + r8, r3);
                            }
                        }
                        r1 = LD32(0x0608F458);
                        r0 = LD32((r1 + 0x348));
                    }
                }
            } else {
                r7 = LD32(0x34C + r1);
                r6 = LD32(0x358 + r1);
                r5 = LD32(0x354 + r1);
                r4 = LD32(0x350 + r1);
                r0 = GCALL4(0x06071E98, r4, r5, r6, r7);
                c3 = (r0 & r0) == 0;
                r0 = 1;
                if (c3) {
                    r0 = GCALL0(0x0607152C);
                    r1 = LD32(r8);
                    ST32(r8, (r1 + 1));
                    r1 = LD32(r10);
                    ST32(r1 + r9, 3);
                    r10 = 0x0608F458;
                    r1 = LD32(0x0608F458);
                    r9 = 0x348;
                    r0 = r1;
                    r1 = LD32(r0 + r9);
                    if (r1 == 3) {
                        r0 = GCALL1(0x06071488, 0x100);
                        if (!((r0 & r0) == 0)) {
                            r1 = LD32(r10);
                            ST32(r1 + r9, 4);
                        }
                    }
                    r10 = 0x0608F458;
                    r1 = LD32(0x0608F458);
                    r9 = 0x348;
                    r2 = LD32(r1 + 0x348);
                    if (!(r2 == 4)) {
                        r9 = 0x0608F458;
                        r1 = LD32(0x0608F458);
                        r8 = 0x348;
                        r1 = LD32(r1 + 0x348);
                        if (r1 == 5) {
                            r0 = GCALL1(0x06071488, 64);
                            r3 = 0;
                            if (r0 == 1) {
                                r1 = LD32(r9);
                                ST32(r1 + r8, r3);
                            }
                        }
                        r1 = LD32(0x0608F458);
                        r0 = LD32((r1 + 0x348));
                    } else {
                        r5 = LD32(0x35C + r1);
                        r4 = LD32(0x34C + r1);
                        r0 = GCALL2(0x06072090, r4, r5);
                        c7 = (r0 & r0) == 0;
                        r0 = 1;
                        if (c7) {
                            r1 = LD32(r8);
                            ST32(r8, (r1 + 1));
                            r1 = LD32(r10);
                            ST32(r1 + r9, 5);
                            r9 = 0x0608F458;
                            r1 = LD32(0x0608F458);
                            r8 = 0x348;
                            r1 = LD32(r1 + 0x348);
                            if (r1 == 5) {
                                r0 = GCALL1(0x06071488, 64);
                                r3 = 0;
                                if (r0 == 1) {
                                    r1 = LD32(r9);
                                    ST32(r1 + r8, r3);
                                }
                            }
                            r1 = LD32(0x0608F458);
                            r0 = LD32((r1 + 0x348));
                        }
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071344(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12;
    FRAME(sp, 28);

    r3 = 0x0608F458;
    r1 = LD32(0x0608F458);
    r1 = LD32(r1 + 0x1DC);
    r8 = 0;
    r11 = r4;
    if (!(0 >= r1)) {
        r10 = r3;
        r9 = 0;
        while (1) {
            r1 = LD32(r3);
            r1 = LD32((r1 + r9) + 0x1E8);
            r5 = 1;
            if (!(r1 == -2)) {
                r3 = r1;
            } else {
                r3 = 255;
                r5 = 0;
            }
            r1 = LD32(r10);
            r1 = LD32((r1 + r9) + 0x1EC);
            r12 = 2;
            if (!(r1 == -2)) {
                r5 = r5 | r12;
                r2 = r1;
            } else {
                r2 = 255;
            }
            r1 = LD32(r10);
            r4 = LD32(0x1E4 + (r1 + r9));
            r0 = GCALL4(0x06072108, r4, r5, r3, r2);
            if (!((r0 & r0) == 0)) {
                break;
            } else {
                r9 = r9 + 12;
                r0 = GCALL0(0x0607152C);
                r1 = LD32(r11);
                r8 = r8 + 1;
                ST32(r11, (r1 + 1));
                r1 = LD32(r10);
                r1 = LD32(0x1DC + r1);
                r3 = r10;
                if (!(r8 >= r1)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    r1 = LD32(0x0608F458);
    r3 = 0x1DC;
    r2 = r1 + 0x1DC;
    r1 = LD32(r2);
    r6 = 0;
    if (!(r8 >= r1)) {
        r9 = 0x1E4;
        r4 = 0x1E8;
        r5 = 0x1EC;
        r10 = r3;
        r7 = 0;
        r3 = ((r8 + r8) + r8) << 2;
        do {
            r2 = LD32(0x0608F458);
            r1 = r2 + r7;
            r11 = r2 + r3;
            r12 = LD32(r11 + r9);
            r8 = r8 + 1;
            ST32(r1 + r9, r12);
            r12 = LD32(r11 + r4);
            r6 = r6 + 1;
            ST32(r1 + r4, r12);
            r11 = LD32(r11 + r5);
            r3 = r3 + 12;
            ST32(r1 + r5, r11);
            r1 = LD32(r2 + r10);
            r7 = r7 + 12;
        } while (AGAIN(!(r8 >= r1)));
        ST32(0x1DC + r2, r6);
    } else {
        ST32(r2, 0);
    }
    r0 = GCALL1(0x06071488, 64);
    if (!((r0 & r0) == 0)) {
        r2 = LD32(0x0608F458);
        r1 = LD32(0x1DC + r2);
        r12 = 0;
        if ((r1 & r1) == 0) {
            ST32(r2 + 0x1E0, r12);
        }
    }
    r1 = LD32(0x0608F458);
    r0 = LD32((r1 + 0x1DC));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071488(int r4)
{
    int r0;
    FRAME(sp, 12);

    r0 = GCALL0(0x0606C2E8);
    return (((r4 & r0) & (r4 & r0)) == 0) ^ 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060714AC(void)
{
    int r0, r1, r2, r3, r7;
    FRAME(sp, 4);

    r0 = 0;
    r7 = 22;
    r3 = 0x0608F458;
    r2 = 0;
    do {
        r1 = LD32(r3);
        ST8(r0 + r1, r2);
        r1 = LD32(r3);
        r1 = (r1 + r0) + 24;
        r0 = r0 + 1;
        ST8(r1, r2);
    } while (AGAIN(!(r0 > r7)));
    r1 = LD32(0x0608F458);
    ST32(r1 + 48, 0);
    ST32(r1 + 52, -1);
    ST32(r1 + 56, -1);
    ST32(r1 + 60, 0);
    ST32((r1 + 76), 0);
    ST32((r1 + 80), 0);
    ST32((r1 + 84), 0);
    ST32((r1 + 88), 0);
    ST32(0x304 + r1, 0);
    ST32(0x30C + r1, 0);
    ST32(0x328 + r1, 0);
    ST32(0x338 + r1, 0);
    ST32(0x348 + r1, 0);
    ST32(0x360 + r1, 0);
    ST32(0x1DC + r1, 0);
    ST32(0x1E0 + r1, 0);
    return 0x1E0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607152C(void)
{
    int r0, r1, r2, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    r0 = GCALL1(0x06071698, r14);
    r1 = LD32(0x0608F458);
    r2 = LD8(r14);
    ST8((r1 + 64), r2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071574(void)
{
    int r0, c0;
    FRAME(sp, 8);

    r0 = GCALL0(0x0606C2E8);
    c0 = ((0x400 & r0) & (0x400 & r0)) == 0;
    r0 = 1;
    if (c0) {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071598(void)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL1(0x0606C2FC, -1025);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060715B4(void)
{
    int r0, r8, r9, r10, c1;
    FRAME(sp, 20);

    r8 = 0;
    r9 = 0x06071574;
    r10 = 0x06071598;
    while (1) {
        r0 = GCALL0(r9);
        r8 = r8 + 1;
        if (!(r0 == 1)) {
            c1 = r8 > 0x5F33;
            r0 = c1;
            if (!(c1)) {
                POLL();
                continue;
            } else {
                break;
            }
        } else {
            r0 = GCALL0(r10);
            r0 = 0;
            break;
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060715F8(void)
{
    int r0, r1, r8, r9, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = 0;
    r9 = 0x060703C8;
    while (1) {
        r0 = GCALL1(r9, r14);
        r0 = LD8(r14);
        r0 = r0 & 15;
        if (!((unsigned)((r0 - 1) & 255) > (unsigned)1)) {
            break;
        } else {
            r1 = LD32(0x0608F454);
            r8 = r8 + 1;
            if (!((r1 & r1) == 0)) {
                break;
            } else {
                if (!(r8 > 0x00069CB4)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071648(int r4)
{
    int r0, r8, r9, r10, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    r9 = r4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    r8 = r14 + 8;
    ST8(r14, 0);
    r0 = GCALL4(0x06072650, 0, r14, r8, 1);
    r10 = r0;
    r0 = GCALL2(0x06072700, r8, r9);
    return r10;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071698(int r4)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL1(0x060726C0, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060716B0(int r4)
{
    int r0, r5, r8, r9, r14, c1, c2;
    FRAME(sp, 24);

    r14 = sp - 24;
    r9 = r4;
    r0 = GCALL1(0x06071700, r14);
    r8 = r0;
    r5 = r9;
    if ((r8 & r8) == 0) {
        r0 = GCALL2(0x06072700, r14, r5);
        r0 = LD8(r9);
        c1 = (r0 & 255) == 255;
        r0 = r0 & 32;
        if (c1) {
            r0 = -8;
        } else {
            c2 = (r0 & r0) == 0;
            r0 = r8;
            if (c2) {
                r0 = -8;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071700(int r4)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 40);

    r14 = sp - 40;
    r11 = r4;
    r10 = r14;
    r12 = -3;
    r9 = 0;
    r13 = 0x0606C578;
    while (1) {
        r0 = SR();
        r8 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
        r1 = SR();
        SETSR(((-241 & r1) | 240));
        r0 = GCALL1(r13, r11);
        r0 = GCALL1(r13, r10);
        r1 = SR();
        SETSR(((r1 & -241) | ((r8 << 2) << 2)));
        r2 = LD32(r11);
        r1 = LD32(r10);
        if (!(r2 == r1)) {
            r9 = r9 + 1;
            if (!(r9 > 99)) {
                POLL();
                continue;
            } else {
                break;
            }
        } else {
            r2 = LD32(r11 + 4);
            r1 = LD32(r10 + 4);
            r9 = r9 + 1;
            if (!(r2 == r1)) {
                if (!(r9 > 99)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            } else {
                r12 = 0;
                break;
            }
        }
        POLL();
    }
    return r12;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071784(int r4)
{
    int r0, r1, r8, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = r4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 1);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r1 = LD8((r14 + 10));
    ST8(r8, r1);
    r1 = LD8((r14 + 11));
    ST8((r8 + 1), r1);
    r1 = LD8((r14 + 13));
    ST8((r8 + 2), r1);
    r1 = LD8((r14 + 14));
    ST8((r8 + 3), r1);
    r1 = LD8((r14 + 15));
    ST8((r8 + 4), r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060717EC(int r4)
{
    int r0, r5, r8, r9, r14;
    FRAME(sp, 32);

    r14 = sp - 32;
    r9 = r4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    r8 = r14 + 8;
    ST8(r14, 2);
    r0 = GCALL3(0x06072618, 0, r14, r8);
    r5 = r9;
    if ((r0 & r0) == 0) {
        r4 = LD32(r8);
        r0 = GCALL2(0x0606C3AC, (r4 & 0x00FFFFFF), r5);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607183C(int r4, int r5)
{
    int r0, r2, r8, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = r5;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 3);
    ST8((r14 + 1), r4);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r2 = LD32(r14 + 12);
    ST32(r8, r2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060718FC(void)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 5);
    r0 = GCALL2(0x06072630, 0, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071990(int r4)
{
    int r0, r1, r8, r9, r10, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    r9 = r4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    r8 = r14 + 8;
    ST8(r14, 6);
    r0 = GCALL3(0x06072618, 0, r14, r8);
    r10 = r0;
    r1 = LD32(r8);
    ST32(r9, (r1 & 0x00FFFFFF));
    r0 = GCALL1(0x0606C32C, -3);
    return r10;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060719E8(int r4)
{
    int r0, r1, r2, r3, c2;
    FRAME(sp, 4);

    r3 = -80;
    r0 = LD32(r4 + 8);
    r2 = LD32(-80);
    if (!(((1 & r0) & (1 & r0)) == 0)) {
        r1 = LD32(r4);
        r2 = (r2 & -9) | r1;
    }
    r1 = -2;
    if (!(((8 & r0) & (8 & r0)) == 0)) {
        r2 = r2 & r1;
        r1 = LD32(r4 + 4);
        r2 = r2 | r1;
    }
    c2 = ((2 & r0) & (2 & r0)) == 0;
    r0 = r0 & 4;
    if (!(c2)) {
        r2 = r2 & -5;
    }
    r1 = -3;
    if (!((r0 & r0) == 0)) {
        r2 = r2 & r1;
    }
    ST32(r3, r2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071A30(int r4, int r5)
{
    int r0, r1, r2, r3, r7, c4, c5, c6, c10;
    FRAME(sp, 4);

    r0 = LD32(r4 + 36);
    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
        r2 = LD32(r4);
        ST32((((r5 << 2) << 2) - 128), r2);
    }
    r0 = LD32(r4 + 36);
    r1 = r5;
    if (!(((r0 & 2) & (r0 & 2)) == 0)) {
        r2 = LD32(r4 + 4);
        ST32((((r1 << 2) << 2) - 124), r2);
    }
    r0 = LD32(r4 + 36);
    r0 = r0 & 4;
    r1 = r5;
    if (!((r0 & r0) == 0)) {
        r2 = LD32(r4 + 8);
        ST32((((r1 << 2) << 2) - 120), r2);
    }
    r7 = ((r5 << 2) << 2) - 116;
    r3 = LD32(r4 + 36);
    r2 = LD32(r7);
    r1 = 16;
    if (!(((8 & r3) & (8 & r3)) == 0)) {
        r1 = LD32(r4 + 12);
        r2 = (r2 & -49153) | (((int)((unsigned)(r1 << 8) >> 2)) << 8);
        r1 = 16;
    }
    c4 = ((r1 & r3) & (r1 & r3)) == 0;
    r1 = 32;
    if (!(c4)) {
        r1 = LD32(r4 + 16);
        r2 = (r2 & -12289) | (((r1 << 8) << 2) << 2);
        r1 = 32;
    }
    c5 = ((r1 & r3) & (r1 & r3)) == 0;
    r1 = 64;
    if (!(c5)) {
        r1 = LD32(r4 + 20);
        r2 = (r2 & -3073) | r1;
        r1 = 64;
    }
    c6 = ((r1 & r3) & (r1 & r3)) == 0;
    r1 = -17;
    if (!(c6)) {
        r1 = LD32(r4 + 24);
        r2 = (r2 & -513) | r1;
        r1 = -17;
    }
    r2 = (r2 & r1) & -9;
    r1 = -5;
    if (!(((128 & r3) & (128 & r3)) == 0)) {
        r2 = r2 & r1;
        r1 = LD32(r4 + 28);
        r2 = r2 | r1;
    }
    r1 = -3;
    if (!(((0x200 & r3) & (0x200 & r3)) == 0)) {
        r2 = r2 & r1;
    }
    ST32(r7, r2);
    r1 = LD32(r4 + 36);
    r2 = 1;
    if (!(((r1 & 0x100) & (r1 & 0x100)) == 0)) {
        r1 = LD32(r4 + 32);
        c10 = (unsigned)(r1 - 1) > (unsigned)r2;
        r2 = r5;
        if (!(c10)) {
            r1 = LD8((r4 + 35));
            ST8((r2 + -399), r1);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071BA0(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 112);
    ST32(r14 + 4, r5);
    ST8((r14 + 4), r4);
    r0 = GCALL2(0x06072630, 0x200, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071BD4(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 113);
    ST32(r14 + 4, r5);
    ST8((r14 + 4), r4);
    r0 = GCALL2(0x06072630, 0x200, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071C08(int r4, int r5, int r6)
{
    int r0, r1, r3, r8, r9, r10, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    r10 = r4;
    r8 = r5;
    r9 = r6;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 114);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r3 = r14 + 12;
    r1 = LD16((r14 + 10));
    ST32(r8, (r1 & 0xFFFF));
    r1 = LD8(r3);
    ST32(r9, (r1 & 255));
    r1 = LD32(r3);
    ST32(r10, (r1 & 0x00FFFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071C68(int r4, int r5)
{
    int r0, r8, r9, r14;
    FRAME(sp, 32);

    r14 = sp - 32;
    r9 = r5;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    r8 = r14 + 8;
    ST8(r14, 115);
    ST32(r14 + 4, r4);
    ST8((r14 + 4), 0);
    r0 = GCALL3(0x06072618, 0, r14, r8);
    r5 = r9;
    if ((r0 & r0) == 0) {
        r4 = LD32(r8);
        r0 = GCALL2(0x0606C3AC, (r4 & 0x00FFFFFF), r5);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071CC4(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST32(r14, r6);
    ST8(r14, 116);
    ST32(r14 + 4, r5);
    ST8((r14 + 4), r4);
    r0 = GCALL2(0x06072630, 0x200, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071CF8(void)
{
    int r0, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 117);
    r0 = GCALL1(0x0606C364, 0x200);
    r0 = GCALL2(0x06072630, 0x200, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071D34(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 96);
    ST8((r14 + 1), r4);
    ST8((r14 + 2), r5);
    r0 = GCALL2(0x06072630, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071D68(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 97);
    ST16((r14 + 2), r5);
    ST8((r14 + 4), r4);
    ST16((r14 + 6), r6);
    r0 = GCALL2(0x06072630, 128, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071DA4(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 98);
    ST16((r14 + 2), r5);
    ST8((r14 + 4), r4);
    ST16((r14 + 6), r6);
    r0 = GCALL2(0x06072630, 128, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071DE0(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 99);
    ST16((r14 + 2), r5);
    ST8((r14 + 4), r4);
    ST16((r14 + 6), r6);
    r0 = GCALL2(0x06072630, 128, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071E1C(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 100);
    ST8((r14 + 4), r4);
    ST16((r14 + 6), r5);
    r0 = GCALL2(0x06072630, 128, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071E54(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 101);
    ST8((r14 + 1), r7);
    ST16((r14 + 2), r5);
    ST8((r14 + 4), r4);
    ST16((r14 + 6), r6);
    r0 = GCALL2(0x06072630, 0x100, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071E98(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 102);
    ST8((r14 + 1), r7);
    ST16((r14 + 2), r5);
    ST8((r14 + 4), r4);
    ST16((r14 + 6), r6);
    r0 = GCALL2(0x06072630, 0x100, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071EDC(int r4)
{
    int r0, r1, r8, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = r4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 103);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r1 = LD8((r14 + 9));
    ST32(r8, (r1 & 255));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071F18(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST32(r14, r5);
    ST8(r14, 64);
    ST32(r14 + 4, r6);
    ST8((r14 + 4), r4);
    r0 = GCALL2(0x06072630, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071F4C(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    r9 = r5;
    r10 = r6;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    r8 = r14 + 8;
    ST8(r14, 65);
    ST8((r14 + 4), r4);
    r0 = GCALL3(0x06072618, 0, r14, r8);
    r1 = LD32(r8);
    ST32(r9, (r1 & 0x00FFFFFF));
    r1 = LD32(r14 + 12);
    ST32(r10, (r1 & 0x00FFFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071FA4(int r4, int r5)
{
    int r0, r1, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 66);
    r1 = LD8((r5 + 1));
    ST8((r14 + 1), r1);
    r1 = LD8((r5 + 2));
    ST8((r14 + 2), r1);
    r1 = LD8((r5 + 4));
    ST8((r14 + 3), r1);
    ST8((r14 + 4), r4);
    r1 = LD8(r5);
    ST8((r14 + 5), r1);
    r1 = LD8((r5 + 3));
    ST8((r14 + 6), r1);
    r1 = LD8((r5 + 5));
    ST8((r14 + 7), r1);
    r0 = GCALL2(0x06072630, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072014(int r4, int r5)
{
    int r0, r1, r8, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = r5;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 67);
    ST8((r14 + 4), r4);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r1 = LD8((r14 + 9));
    ST8((r8 + 1), r1);
    r1 = LD8((r14 + 10));
    ST8((r8 + 2), r1);
    r1 = LD8((r14 + 11));
    ST8((r8 + 4), r1);
    r1 = LD8((r14 + 13));
    ST8(r8, r1);
    r1 = LD8((r14 + 14));
    ST8((r8 + 3), r1);
    r1 = LD8((r14 + 15));
    ST8((r8 + 5), r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072090(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 68);
    ST8((r14 + 1), r5);
    ST8((r14 + 4), r4);
    r0 = GCALL2(0x06072630, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060720C4(int r4, int r5)
{
    int r0, r1, r8, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = r5;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 69);
    ST8((r14 + 4), r4);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r1 = LD8((r14 + 9));
    ST32(r8, (r1 & 255));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072108(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 70);
    ST8((r14 + 1), r5);
    ST8((r14 + 2), r6);
    ST8((r14 + 3), r7);
    ST8((r14 + 4), r4);
    r0 = GCALL2(0x06072630, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072148(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r14;
    FRAME(sp, 32);

    r14 = sp - 32;
    r8 = r5;
    r9 = r6;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 71);
    ST8((r14 + 4), r4);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r1 = LD8((r14 + 10));
    ST32(r8, (r1 & 255));
    r1 = LD8((r14 + 11));
    ST32(r9, (r1 & 255));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607219C(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 72);
    ST8((r14 + 1), r4);
    ST8((r14 + 4), r5);
    r0 = GCALL2(0x06072630, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060721D0(int r4)
{
    int r0, r1, r8, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    r8 = r4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 16);
    r0 = GCALL2(0x06072224, r4, (r14 + 1));
    r1 = LD8((r8 + 16));
    ST8((r14 + 4), r1);
    r0 = GCALL2(0x06072224, (r8 + 8), (r14 + 5));
    r0 = GCALL2(0x06072630, 0, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607229C(int r4)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 17);
    r0 = GCALL2(0x06072224, r4, (r14 + 1));
    r0 = GCALL2(0x06072630, 0, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060722D0(int r4)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 18);
    ST8((r14 + 1), r4);
    r0 = GCALL2(0x06072630, 0, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072300(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    r10 = r4;
    r9 = r5;
    r8 = r6;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 80);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r1 = LD16((r14 + 10));
    ST32(r8, (r1 & 0xFFFF));
    r1 = LD8((r14 + 12));
    ST32(r9, (r1 & 255));
    r1 = LD16((r14 + 14));
    ST32(r10, (r1 & 0xFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607235C(int r4, int r5)
{
    int r0, r1, r8, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = r5;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 81);
    ST8((r14 + 4), r4);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r1 = LD16((r14 + 14));
    ST32(r8, (r1 & 0xFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060723A0(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 82);
    ST16((r14 + 2), r5);
    ST8((r14 + 4), r4);
    ST16((r14 + 6), r6);
    r0 = GCALL2(0x06072630, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060723DC(int r4)
{
    int r0, r1, r8, r9, r14;
    FRAME(sp, 32);

    r14 = sp - 32;
    r9 = r4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    r8 = r14 + 8;
    ST8(r14, 83);
    r0 = GCALL2(0x06072420, r14, r8);
    r1 = LD32(r8);
    ST32(r9, (r1 & 0x00FFFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072420(int r4, int r5)
{
    int r0, r6, r9;
    FRAME(sp, 16);

    r9 = r4;
    r0 = GCALL0(0x0606C2E8);
    r6 = r5;
    if (((r0 & 64) & (r0 & 64)) == 0) {
        r0 = -1;
    } else {
        r0 = GCALL3(0x06072618, 0, r9, r6);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607245C(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r14;
    FRAME(sp, 32);

    r14 = sp - 32;
    r8 = r6;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    r9 = r14 + 8;
    ST8(r14, 84);
    ST16((r14 + 2), r5);
    ST8((r14 + 4), r4);
    r0 = GCALL3(0x06072618, 0, r14, r9);
    r1 = LD32(r9);
    ST32(r8, (r1 & 0x00FFFFFF));
    r1 = LD8((r14 + 12));
    ST8((r8 + 4), r1);
    r1 = LD8((r14 + 13));
    ST8((r8 + 5), r1);
    r1 = LD8((r14 + 14));
    ST8((r8 + 6), r1);
    r1 = LD8((r14 + 15));
    ST8((r8 + 7), r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060724DC(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 85);
    ST16((r14 + 2), r5);
    ST32(r14 + 4, r6);
    ST8((r14 + 4), r4);
    r0 = GCALL2(0x06072630, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072514(int r4, int r5, int r6)
{
    int r0, r1, r3, r8, r9, r10, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    r9 = r4;
    r8 = r5;
    r10 = r6;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 86);
    r0 = GCALL2(0x06072420, r14, (r14 + 8));
    r3 = r14 + 12;
    r1 = LD16((r14 + 10));
    ST32(r8, (r1 & 0xFFFF));
    r1 = LD8(r3);
    ST32(r9, (r1 & 255));
    r1 = LD32(r3);
    ST32(r10, (r1 & 0x00FFFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072570(int r4)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 48);
    ST8((r14 + 4), r4);
    r0 = GCALL2(0x06072630, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060725A0(int r4)
{
    int r0, r1, r8, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = r4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 49);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r1 = LD8((r14 + 12));
    ST32(r8, (r1 & 255));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060725DC(int r4)
{
    int r0, r1, r8, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = r4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 50);
    r0 = GCALL3(0x06072618, 0, r14, (r14 + 8));
    r1 = LD8((r14 + 12));
    ST32(r8, (r1 & 255));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072618(int r4, int r5, int r6)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL4(0x06072650, r4, r5, r6, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072630(int r4, int r5)
{
    int r0;
    FRAME(sp, 16);

    r0 = GCALL4(0x06072650, r4, r5, (sp - 16), 1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072650(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11;
    FRAME(sp, 24);

    r8 = r6;
    r10 = r7;
    r0 = GCALL3(0x0606C408, r4, r5, r6);
    r9 = r0;
    if ((r9 & r9) == 0) {
        r0 = (SR() & ~1) | 1;
        r11 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
        r0 = (SR() & ~1) | 1;
        SETSR((r0 | 240));
        r5 = 0x06089768;
        if ((r10 & r10) == 0) {
            r1 = LD8(r8);
            ST8(r5, r1);
        } else {
            r0 = GCALL2(0x06072700, r8, r5);
        }
        r1 = SR();
        SETSR(((r1 & -241) | ((r11 << 2) << 2)));
        r0 = r9;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06072748(int r4)
{
    int r1, r14;
    FRAME(sp, 8);

    r14 = sp - 8;
    ST32(r14, r4);
    while (1) {
        r1 = LD32(r14);
        if (r1 > 0) {
            POLL();
            r1 = LD32(r14);
            ST32(r14, (r1 - 1));
            r1 = LD32(r14);
            continue;
        } else {
            break;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A2(int r4)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A4(int r4)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A6(int r4)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A8(int r4)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727AA(int r4)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727AC(int r4)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060727F4(int r4, int r5)
{
    int r0;

    r0 = LD32(r5 + 24);
    ST32(r4 + 24, r0);
    r0 = LD32(r5 + 20);
    ST32(r4 + 20, r0);
    r0 = LD32(r5 + 16);
    ST32(r4 + 16, r0);
    r0 = LD32(r5 + 12);
    ST32(r4 + 12, r0);
    r0 = LD32(r5 + 8);
    ST32(r4 + 8, r0);
    r0 = LD32(r5 + 4);
    ST32(r4 + 4, r0);
    r0 = LD32(r5);
    ST32(r4, r0);
    return r0 | r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072AC0(int r4, int r5)
{
    int r0, r1, r2, r3, r7, c6;
    FRAME(sp, 4);

    r2 = LD32(r4);
    r2 = r2 & 0x007FFFFF;
    r1 = LD8(r4);
    r7 = (int)((unsigned)((int)((unsigned)((int)((unsigned)((int)((unsigned)(r1 & 255) >> 2)) >> 2)) >> 1)) >> 2);
    ST32(r5 + 4, r7);
    r1 = 0x7F80;
    r4 = LD16(r4);
    r3 = 0x7F80 & r4;
    if (!((r3 & r3) == 0)) {
        r0 = r4;
        if (!(r3 == (r1 & 0xFFFF))) {
            r0 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)((unsigned)r0 >> 2)) >> 2)) >> 1)) >> 2)) & 255;
            ST32(r5 + 8, (r0 - 127));
            ST32(r5, 3);
            ST32(r5 + 12, (((((r2 << 2) << 2) + ((r2 << 2) << 2)) << 2) | 0x40000000));
        } else {
            c6 = (r7 & r7) == 0;
            if (!((r2 & r2) == 0)) {
                r1 = 0;
                if (c6) {
                    ST32(r5, 1);
                } else {
                    ST32(r5, r1);
                }
                ST32(r5 + 12, r2);
            } else {
                ST32(r5, 4);
            }
        }
    } else {
        r0 = r4;
        if (!((r2 & r2) == 0)) {
            r0 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)((unsigned)r0 >> 2)) >> 2)) >> 1)) >> 2)) & 255;
            ST32(r5 + 8, (r0 - 126));
            r2 = (((r2 << 2) << 2) + ((r2 << 2) << 2)) << 2;
            r3 = 0x3FFFFFFF;
            ST32(r5, 3);
            if ((unsigned)r2 > (unsigned)0x3FFFFFFF) {
                ST32(r5 + 12, r2);
            } else {
                do {
                    r2 = r2 + r2;
                    r1 = LD32(r5 + 8);
                    ST32(r5 + 8, (r1 - 1));
                } while (AGAIN(!((unsigned)r2 > (unsigned)r3)));
                ST32(r5 + 12, r2);
            }
        } else {
            ST32(r5, 2);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060730F0(int r4, int r5)
{
    int r0, r8, r14;
    FRAME(sp, 56);

    r14 = sp - 56;
    ST32(r14 + 32, r4);
    ST32(r14 + 36, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 32), r14);
    r8 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 36), r8);
    r0 = GCALL2(0x06073018, r14, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073134(int r4, int r5)
{
    int r0, r1, r9, r14, c1;
    FRAME(sp, 56);

    r14 = sp - 56;
    ST32(r14 + 32, r4);
    ST32(r14 + 36, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 32), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 36), r9);
    r1 = LD32(r14);
    r0 = 1;
    c1 = (((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0;
    r1 = LD32(r14 + 16);
    if (c1) {
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x06073018, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073190(int r4, int r5)
{
    int r0, r1, r9, r14, c1;
    FRAME(sp, 56);

    r14 = sp - 56;
    ST32(r14 + 32, r4);
    ST32(r14 + 36, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 32), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 36), r9);
    r1 = LD32(r14);
    r0 = 1;
    c1 = (((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0;
    r1 = LD32(r14 + 16);
    if (c1) {
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x06073018, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060731EC(int r4, int r5)
{
    int r0, r1, r2, r9, r14;
    FRAME(sp, 56);

    r14 = sp - 56;
    ST32(r14 + 32, r4);
    ST32(r14 + 36, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 32), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 36), r9);
    r2 = LD32(r14);
    r0 = -1;
    if ((((unsigned)1 >= (unsigned)r2) & ((unsigned)1 >= (unsigned)r2)) == 0) {
        r1 = LD32(r14 + 16);
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x06073018, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607324C(int r4, int r5)
{
    int r0, r1, r2, r9, r14;
    FRAME(sp, 56);

    r14 = sp - 56;
    ST32(r14 + 32, r4);
    ST32(r14 + 36, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 32), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 36), r9);
    r2 = LD32(r14);
    r0 = -1;
    if ((((unsigned)1 >= (unsigned)r2) & ((unsigned)1 >= (unsigned)r2)) == 0) {
        r1 = LD32(r14 + 16);
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x06073018, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060732AC(int r4, int r5)
{
    int r0, r1, r9, r14, c1;
    FRAME(sp, 56);

    r14 = sp - 56;
    ST32(r14 + 32, r4);
    ST32(r14 + 36, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 32), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 36), r9);
    r1 = LD32(r14);
    r0 = 1;
    c1 = (((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0;
    r1 = LD32(r14 + 16);
    if (c1) {
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x06073018, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073308(int r4, int r5)
{
    int r0, r1, r9, r14, c1;
    FRAME(sp, 56);

    r14 = sp - 56;
    ST32(r14 + 32, r4);
    ST32(r14 + 36, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 32), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 36), r9);
    r1 = LD32(r14);
    r0 = 1;
    c1 = (((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0;
    r1 = LD32(r14 + 16);
    if (c1) {
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x06073018, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074130(int r4, int r5, int r6, int r7)
{
    int r0, r8, r14;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 40, r4);
    ST32(r14 + 44, r5);
    ST32(r14 + 48, r6);
    ST32(r14 + 52, r7);
    r0 = GCALL2(0x060736D8, (r14 + 40), r14);
    r8 = r14 + 20;
    r0 = GCALL2(0x060736D8, (r14 + 48), r8);
    r0 = GCALL2(0x0607403C, r14, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074178(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r14, c1;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 40, r4);
    ST32(r14 + 44, r5);
    ST32(r14 + 48, r6);
    ST32(r14 + 52, r7);
    r0 = GCALL2(0x060736D8, (r14 + 40), r14);
    r9 = r14 + 20;
    r0 = GCALL2(0x060736D8, (r14 + 48), r9);
    r1 = LD32(r14);
    r0 = 1;
    c1 = (((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0;
    r1 = LD32(r14 + 20);
    if (c1) {
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x0607403C, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060741D8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r14, c1;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 40, r4);
    ST32(r14 + 44, r5);
    ST32(r14 + 48, r6);
    ST32(r14 + 52, r7);
    r0 = GCALL2(0x060736D8, (r14 + 40), r14);
    r9 = r14 + 20;
    r0 = GCALL2(0x060736D8, (r14 + 48), r9);
    r1 = LD32(r14);
    r0 = 1;
    c1 = (((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0;
    r1 = LD32(r14 + 20);
    if (c1) {
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x0607403C, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074238(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r9, r14;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 40, r4);
    ST32(r14 + 44, r5);
    ST32(r14 + 48, r6);
    ST32(r14 + 52, r7);
    r0 = GCALL2(0x060736D8, (r14 + 40), r14);
    r9 = r14 + 20;
    r0 = GCALL2(0x060736D8, (r14 + 48), r9);
    r2 = LD32(r14);
    r0 = -1;
    if ((((unsigned)1 >= (unsigned)r2) & ((unsigned)1 >= (unsigned)r2)) == 0) {
        r1 = LD32(r14 + 20);
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x0607403C, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607429C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r9, r14;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 40, r4);
    ST32(r14 + 44, r5);
    ST32(r14 + 48, r6);
    ST32(r14 + 52, r7);
    r0 = GCALL2(0x060736D8, (r14 + 40), r14);
    r9 = r14 + 20;
    r0 = GCALL2(0x060736D8, (r14 + 48), r9);
    r2 = LD32(r14);
    r0 = -1;
    if ((((unsigned)1 >= (unsigned)r2) & ((unsigned)1 >= (unsigned)r2)) == 0) {
        r1 = LD32(r14 + 20);
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x0607403C, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074300(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r14, c1;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 40, r4);
    ST32(r14 + 44, r5);
    ST32(r14 + 48, r6);
    ST32(r14 + 52, r7);
    r0 = GCALL2(0x060736D8, (r14 + 40), r14);
    r9 = r14 + 20;
    r0 = GCALL2(0x060736D8, (r14 + 48), r9);
    r1 = LD32(r14);
    r0 = 1;
    c1 = (((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0;
    r1 = LD32(r14 + 20);
    if (c1) {
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x0607403C, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074360(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r14, c1;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 40, r4);
    ST32(r14 + 44, r5);
    ST32(r14 + 48, r6);
    ST32(r14 + 52, r7);
    r0 = GCALL2(0x060736D8, (r14 + 40), r14);
    r9 = r14 + 20;
    r0 = GCALL2(0x060736D8, (r14 + 48), r9);
    r1 = LD32(r14);
    r0 = 1;
    c1 = (((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0;
    r1 = LD32(r14 + 20);
    if (c1) {
        r5 = r9;
        if ((((unsigned)1 >= (unsigned)r1) & ((unsigned)1 >= (unsigned)r1)) == 0) {
            r0 = GCALL2(0x0607403C, r14, r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060747B8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r14;
    FRAME(sp, 20);

    r14 = sp - 16;
    ST32((sp - 20), r14);
    r0 = GCALL5(0x06074A9C, r4, r5, r6, r7, LD32((sp - 20)));
    r0 = LD32(r14);
    r1 = LD32(r14 + 4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060747D8(int r4, int r5, int r6, int r7)
{
    int r0;
    FRAME(sp, 12);

    ST32((sp - 12), 0);
    r0 = GCALL5(0x06074A9C, r4, r5, r6, r7, LD32((sp - 12)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060747F4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    FRAME(sp, 48);

    r14 = sp - 44;
    ST32(r14 + 8, 0);
    if (!(r4 >= 0)) {
        ST32(r14 + 8, -1);
        r1 = -r5;
        r4 = (-r4) - (((r1 & r1) == 0) ^ 1);
        r5 = r1;
    }
    r1 = -r7;
    if (!(r6 >= 0)) {
        r6 = (-r6) - (((r1 & r1) == 0) ^ 1);
        r7 = r1;
    }
    ST32((sp - 48), r14);
    r0 = GCALL5(0x06074A9C, r4, r5, r6, r7, LD32((sp - 48)));
    r3 = LD32(r14 + 8);
    r1 = LD32(r14);
    if (!((r3 & r3) == 0)) {
        r2 = LD32(r14 + 4);
        r3 = -r2;
        ST32(r14, ((-r1) - (((r3 & r3) == 0) ^ 1)));
        ST32(r14 + 4, r3);
    }
    r0 = LD32(r14);
    r1 = LD32(r14 + 4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074924(int r4, int r5, int r6)
{
    int r0, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    r11 = r4;
    r13 = r6;
    r12 = r5;
    if (!((r13 & r13) == 0)) {
        r5 = (-r13) + 32;
        r9 = 0;
        if (r5 > 0) {
            r0 = GCALL2(0x0607290C, r11, r5);
            ST32(r14, r0);
            r0 = GCALL2(0x0607462C, r11, r13);
            r9 = r0;
            r0 = GCALL2(0x0607462C, r12, r13);
            r10 = LD32(r14);
            r10 = r10 | r0;
        } else {
            r0 = GCALL2(0x0607462C, r11, (-r5));
            r10 = r0;
        }
        r0 = r9;
    } else {
        r0 = r11;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074A9C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c2, c7, c12, c21, c31, c36, c52;
    FRAME(sp, 80);

    r14 = sp - 80;
    r9 = r7;
    r10 = r6;
    ST32(r14 + 16, r5);
    ST32(r14 + 44, r4);
    if ((r10 & r10) == 0) {
        c2 = (r9 & r9) == 0;
        if ((unsigned)r9 > (unsigned)r4) {
            r2 = r9;
            if ((unsigned)r9 > (unsigned)0xFFFF) {
                r8 = 24;
                if (!((unsigned)r9 > (unsigned)0x00FFFFFF)) {
                    r8 = 16;
                }
            } else {
                r8 = 0;
                if ((unsigned)r9 > (unsigned)255) {
                    r8 = 8;
                }
            }
            r11 = 0x0607462C;
            r0 = GCALL2(0x0607462C, r2, r8);
            r2 = LD8(0x0607499C + r0);
            ST8(36 + r14, r2);
            r1 = LD8((36 + r14));
            r1 = r1 & 255;
            ST32(r14 + 36, r1);
            r12 = (-(r1 + r8)) + 32;
            ST32(r14 + 40, r12);
            if (!((r12 & r12) == 0)) {
                r5 = LD32(r14 + 40);
                r0 = GCALL2(0x0607290C, r9, r5);
                r5 = LD32(r14 + 40);
                r4 = LD32(r14 + 44);
                r9 = r0;
                r0 = GCALL2(0x0607290C, r4, r5);
                r10 = r0;
                r4 = LD32(r14 + 16);
                r0 = GCALL2(r11, r4, ((-r12) + 32));
                r5 = LD32(r14 + 40);
                r4 = LD32(r14 + 16);
                ST32(r14 + 44, (r10 | r0));
                r0 = GCALL2(0x0607290C, r4, r5);
                ST32(r14 + 16, r0);
            }
            r8 = (int)((unsigned)r9 >> 16);
            r11 = r9 & 0xFFFF;
            r5 = r8;
            r4 = LD32(r14 + 44);
            r7 = LD32(r14 + 44);
            r0 = GCALL2(0x060745A0, r4, r5);
            r4 = LD32(r14 + 44);
            c7 = r0 * r8;
            r0 = GCALL2(0x060745A0, r4, r5);
            r10 = r0;
            r1 = LD32(r14 + 16);
            r7 = ((r7 - c7) << 16) | ((int)((unsigned)r1 >> 16));
            r6 = r10 * r11;
            if (!((unsigned)r7 >= (unsigned)r6)) {
                r7 = r7 + r9;
                r10 = r10 - 1;
                if ((unsigned)r7 >= (unsigned)r9) {
                    if (!((unsigned)r7 >= (unsigned)r6)) {
                        r10 = r10 - 1;
                        r7 = r7 + r9;
                    }
                }
            }
            r7 = r7 - r6;
            r5 = r8;
            r0 = GCALL2(0x060745A0, r7, r5);
            c12 = r0 * r8;
            r0 = GCALL2(0x060745A0, r7, r5);
            r3 = r7 - c12;
            r7 = r0;
            r1 = LD16((18 + r14));
            r1 = r1 & 0xFFFF;
            r3 = r1 | (r3 << 16);
            r6 = r7 * r11;
            ST32(r14 + 36, r1);
            if (!((unsigned)r3 >= (unsigned)r6)) {
                r3 = r3 + r9;
                r7 = r7 - 1;
                if ((unsigned)r3 >= (unsigned)r9) {
                    if (!((unsigned)r3 >= (unsigned)r6)) {
                        r7 = r7 - 1;
                        r3 = r3 + r9;
                    }
                }
            }
            r10 = r10 << 16;
            ST32(r14 + 36, r10);
            r11 = r10 | r7;
            ST32(r14 + 16, (r3 - r6));
            ST32(r14 + 20, 0);
        } else {
            r4 = c2;
            if (c2) {
                r0 = GCALL2(0x060745A0, r4, r9);
                r9 = r0;
            }
            r2 = r9;
            if ((unsigned)r9 > (unsigned)0xFFFF) {
                r8 = 24;
                if (!((unsigned)r9 > (unsigned)0x00FFFFFF)) {
                    r8 = 16;
                }
            } else {
                r8 = 0;
                if ((unsigned)r9 > (unsigned)255) {
                    r8 = 8;
                }
            }
            r0 = GCALL2(0x0607462C, r2, r8);
            r2 = LD8(0x0607499C + r0);
            ST8(36 + r14, r2);
            r1 = LD8((36 + r14));
            r1 = r1 & 255;
            ST32(r14 + 36, r1);
            r12 = (-(r1 + r8)) + 32;
            ST32(r14 + 40, r12);
            if (!((r12 & r12) == 0)) {
                r1 = LD32(r14 + 40);
                r5 = LD32(r14 + 40);
                r1 = -r1;
                ST32(r14 + 24, r1);
                ST32(r14 + 24, (r1 + 32));
                r0 = GCALL2(0x0607290C, r9, r5);
                r5 = LD32(r14 + 24);
                r9 = r0;
                r4 = LD32(r14 + 44);
                r0 = GCALL2(0x0607462C, r4, r5);
                r5 = LD32(r14 + 40);
                r4 = LD32(r14 + 44);
                r11 = r0;
                r0 = GCALL2(0x0607290C, r4, r5);
                r5 = LD32(r14 + 24);
                r4 = LD32(r14 + 16);
                r10 = r0;
                r0 = GCALL2(0x0607462C, r4, r5);
                r5 = LD32(r14 + 40);
                r4 = LD32(r14 + 16);
                ST32(r14 + 44, (r10 | r0));
                r0 = GCALL2(0x0607290C, r4, r5);
                ST32(r14 + 16, r0);
                r8 = (int)((unsigned)r9 >> 16);
                r13 = r9 & 0xFFFF;
                ST32(r14 + 28, r13);
                r5 = r8;
                r0 = GCALL2(0x060745A0, r11, r5);
                c21 = r0 * r8;
                r0 = GCALL2(0x060745A0, r11, r5);
                r10 = r0;
                r1 = LD32(r14 + 44);
                r7 = ((int)((unsigned)r1 >> 16)) | ((r11 - c21) << 16);
                r6 = r10 * r13;
                if (!((unsigned)r7 >= (unsigned)r6)) {
                    r7 = r7 + r9;
                    r10 = r10 - 1;
                    if ((unsigned)r7 >= (unsigned)r9) {
                        if (!((unsigned)r7 >= (unsigned)r6)) {
                            r10 = r10 - 1;
                            r7 = r7 + r9;
                        }
                    }
                }
                r7 = r7 - r6;
                r5 = r8;
                r0 = GCALL2(0x060745A0, r7, r5);
                r3 = r0;
                r0 = GCALL2(0x060745A0, r7, r5);
                r12 = LD16((46 + r14));
                r12 = r12 & 0xFFFF;
                ST32(r14 + 36, r12);
                r3 = r7 - (r3 * r8);
                r7 = r0;
                r1 = LD32(r14 + 28);
                r3 = r12 | (r3 << 16);
                r6 = r7 * r1;
                if (!((unsigned)r3 >= (unsigned)r6)) {
                    r3 = r3 + r9;
                    r7 = r7 - 1;
                    if ((unsigned)r3 >= (unsigned)r9) {
                        if (!((unsigned)r3 >= (unsigned)r6)) {
                            r7 = r7 - 1;
                            r3 = r3 + r9;
                        }
                    }
                }
                ST32(r14 + 20, ((r10 << 16) | r7));
                ST32(r14 + 44, (r3 - r6));
            } else {
                r13 = LD32(r14 + 44);
                ST32(r14 + 44, (r13 - r9));
                ST32(r14 + 20, 1);
            }
            r8 = (int)((unsigned)r9 >> 16);
            r11 = r9 & 0xFFFF;
            r5 = r8;
            r4 = LD32(r14 + 44);
            r7 = LD32(r14 + 44);
            r0 = GCALL2(0x060745A0, r4, r5);
            r4 = LD32(r14 + 44);
            c31 = r0 * r8;
            r0 = GCALL2(0x060745A0, r4, r5);
            r10 = r0;
            r1 = LD32(r14 + 16);
            r7 = ((r7 - c31) << 16) | ((int)((unsigned)r1 >> 16));
            r6 = r10 * r11;
            if (!((unsigned)r7 >= (unsigned)r6)) {
                r7 = r7 + r9;
                r10 = r10 - 1;
                if ((unsigned)r7 >= (unsigned)r9) {
                    if (!((unsigned)r7 >= (unsigned)r6)) {
                        r10 = r10 - 1;
                        r7 = r7 + r9;
                    }
                }
            }
            r7 = r7 - r6;
            r5 = r8;
            r0 = GCALL2(0x060745A0, r7, r5);
            c36 = r0 * r8;
            r0 = GCALL2(0x060745A0, r7, r5);
            r3 = r7 - c36;
            r7 = r0;
            r1 = LD16((18 + r14));
            r1 = r1 & 0xFFFF;
            r3 = r1 | (r3 << 16);
            r6 = r7 * r11;
            ST32(r14 + 36, r1);
            if (!((unsigned)r3 >= (unsigned)r6)) {
                r3 = r3 + r9;
                r7 = r7 - 1;
                if ((unsigned)r3 >= (unsigned)r9) {
                    if (!((unsigned)r3 >= (unsigned)r6)) {
                        r7 = r7 - 1;
                        r3 = r3 + r9;
                    }
                }
            }
            r11 = (r10 << 16) | r7;
            ST32(r14 + 16, (r3 - r6));
        }
        r12 = LD32((80 + r14));
        r5 = LD32(r14 + 40);
        if (!((r12 & r12) == 0)) {
            r4 = LD32(r14 + 16);
            r0 = GCALL2(0x0607462C, r4, r5);
            ST32(r14 + 12, r0);
            ST32(r14 + 8, 0);
            r0 = LD32(r14 + 8);
            r1 = LD32(r14 + 12);
            r13 = LD32((80 + r14));
            ST32(r13, r0);
            ST32(r13 + 4, r1);
        }
    } else {
        r0 = LD32(r14 + 44);
        r1 = 0;
        if (!((unsigned)r10 > (unsigned)r0)) {
            r4 = r10;
            if ((unsigned)r10 > (unsigned)0xFFFF) {
                r8 = 24;
                if (!((unsigned)r10 > (unsigned)0x00FFFFFF)) {
                    r8 = 16;
                }
            } else {
                r8 = 0;
                if ((unsigned)r10 > (unsigned)255) {
                    r8 = 8;
                }
            }
            r0 = GCALL2(0x0607462C, r4, r8);
            r2 = LD8(0x0607499C + r0);
            ST8(36 + r14, r2);
            r1 = LD8((36 + r14));
            r1 = r1 & 255;
            ST32(r14 + 36, r1);
            r12 = (-(r1 + r8)) + 32;
            ST32(r14 + 40, r12);
            if (!((r12 & r12) == 0)) {
                r0 = LD32(r14 + 40);
                r5 = LD32(r14 + 40);
                r0 = -r0;
                ST32(r14 + 24, r0);
                ST32(r14 + 24, (r0 + 32));
                r0 = GCALL2(0x0607290C, r10, r5);
                r10 = r0;
                r5 = LD32(r14 + 24);
                r0 = GCALL2(0x0607462C, r9, r5);
                r10 = r10 | r0;
                r5 = LD32(r14 + 40);
                r0 = GCALL2(0x0607290C, r9, r5);
                r5 = LD32(r14 + 24);
                r9 = r0;
                r4 = LD32(r14 + 44);
                r0 = GCALL2(0x0607462C, r4, r5);
                r5 = LD32(r14 + 40);
                r4 = LD32(r14 + 44);
                r11 = r0;
                r0 = GCALL2(0x0607290C, r4, r5);
                r5 = LD32(r14 + 24);
                r4 = LD32(r14 + 16);
                ST32(r14 + 44, r0);
                r0 = GCALL2(0x0607462C, r4, r5);
                r13 = LD32(r14 + 44);
                r5 = LD32(r14 + 40);
                r4 = LD32(r14 + 16);
                r13 = r13 | r0;
                ST32(r14 + 44, r13);
                r0 = GCALL2(0x0607290C, r4, r5);
                ST32(r14 + 16, r0);
                r8 = (int)((unsigned)r10 >> 16);
                ST32(r14 + 32, (r10 & 0xFFFF));
                r5 = r8;
                r0 = GCALL2(0x060745A0, r11, r5);
                r7 = r11;
                c52 = r0 * r8;
                r0 = GCALL2(0x060745A0, r11, r5);
                r11 = r0;
                r1 = LD32(r14 + 32);
                r7 = ((int)((unsigned)r13 >> 16)) | ((r7 - c52) << 16);
                r6 = r11 * r1;
                if (!((unsigned)r7 >= (unsigned)r6)) {
                    r7 = r7 + r10;
                    r11 = r11 - 1;
                    if ((unsigned)r7 >= (unsigned)r10) {
                        if (!((unsigned)r7 >= (unsigned)r6)) {
                            r11 = r11 - 1;
                            r7 = r7 + r10;
                        }
                    }
                }
                r7 = r7 - r6;
                r5 = r8;
                r0 = GCALL2(0x060745A0, r7, r5);
                r3 = r0;
                r0 = GCALL2(0x060745A0, r7, r5);
                r12 = LD16((46 + r14));
                r12 = r12 & 0xFFFF;
                ST32(r14 + 36, r12);
                r3 = r7 - (r3 * r8);
                r7 = r0;
                r1 = LD32(r14 + 32);
                r3 = r12 | (r3 << 16);
                r6 = r7 * r1;
                if (!((unsigned)r3 >= (unsigned)r6)) {
                    r3 = r3 + r10;
                    r7 = r7 - 1;
                    if ((unsigned)r3 >= (unsigned)r10) {
                        if (!((unsigned)r3 >= (unsigned)r6)) {
                            r7 = r7 - 1;
                            r3 = r3 + r10;
                        }
                    }
                }
                r11 = (r11 << 16) | r7;
                ST32(r14 + 44, (r3 - r6));
                r4 = 0xFFFF;
                r1 = r11 & 0xFFFF;
                r7 = (int)((unsigned)r11 >> 16);
                r2 = r9 & 0xFFFF;
                r3 = (int)((unsigned)r9 >> 16);
                r5 = r1 * r2;
                r2 = r7 * r2;
                r6 = ((r1 * r3) + ((int)((unsigned)r5 >> 16))) + r2;
                r3 = r7 * r3;
                if (!((unsigned)r6 >= (unsigned)r2)) {
                    r3 = r3 + 0x00010000;
                }
                r7 = ((int)((unsigned)r6 >> 16)) + r3;
                r6 = r6 & r4;
                ST32(r14 + 36, r6);
                r1 = LD32(r14 + 44);
                r6 = (r6 << 16) + (r5 & r4);
                if ((unsigned)r7 > (unsigned)r1) {
                    r11 = r11 - 1;
                    r3 = r6 - r9;
                    r7 = (r7 - r10) - ((unsigned)r3 > (unsigned)r6);
                    r6 = r3;
                    r13 = 0;
                } else {
                    if (!(r7 == r1)) {
                        r13 = 0;
                    } else {
                        r12 = LD32(r14 + 16);
                        r13 = 0;
                        if ((unsigned)r6 > (unsigned)r12) {
                            r11 = r11 - 1;
                            r3 = r6 - r9;
                            r7 = (r7 - r10) - ((unsigned)r3 > (unsigned)r6);
                            r6 = r3;
                            r13 = 0;
                        }
                    }
                }
                ST32(r14 + 20, r13);
                r0 = LD32(80 + r14);
                r3 = LD32(r14 + 16);
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(r14 + 44);
                    r3 = r3 - r6;
                    r1 = LD32(r14 + 16);
                    ST32(r14 + 44, ((r2 - r7) - ((unsigned)r3 > (unsigned)r1)));
                    ST32(r14 + 16, r3);
                    r5 = LD32(r14 + 24);
                    r4 = LD32(r14 + 44);
                    r0 = GCALL2(0x0607290C, r4, r5);
                    r5 = LD32(r14 + 40);
                    r9 = r0;
                    r4 = LD32(r14 + 16);
                    r0 = GCALL2(0x0607462C, r4, r5);
                    r5 = LD32(r14 + 40);
                    r4 = LD32(r14 + 44);
                    ST32(r14 + 12, (r9 | r0));
                    r0 = GCALL2(0x0607462C, r4, r5);
                    ST32(r14 + 8, r0);
                    r0 = LD32(r14 + 8);
                    r1 = LD32(r14 + 12);
                    r13 = LD32((80 + r14));
                    ST32(r13, r0);
                    ST32(r13 + 4, r1);
                }
            } else {
                r13 = LD32(r14 + 44);
                r0 = LD32(r14 + 16);
                if ((unsigned)r13 > (unsigned)r10) {
                    r11 = 1;
                    r3 = LD32(r14 + 16);
                    r2 = LD32(r14 + 44);
                    r3 = r3 - r9;
                    r1 = LD32(r14 + 16);
                    ST32(r14 + 44, ((r2 - r10) - ((unsigned)r3 > (unsigned)r1)));
                    ST32(r14 + 16, r3);
                } else {
                    r11 = 0;
                    if ((unsigned)r0 >= (unsigned)r9) {
                        r11 = 1;
                        r3 = LD32(r14 + 16);
                        r2 = LD32(r14 + 44);
                        r3 = r3 - r9;
                        r1 = LD32(r14 + 16);
                        ST32(r14 + 44, ((r2 - r10) - ((unsigned)r3 > (unsigned)r1)));
                        ST32(r14 + 16, r3);
                    }
                }
                ST32(r14 + 20, 0);
                r0 = LD32(80 + r14);
                r1 = LD32(r14 + 16);
                if (!((r0 & r0) == 0)) {
                    r12 = LD32(r14 + 44);
                    ST32(r14 + 12, r1);
                    ST32(r14 + 8, r12);
                    r0 = LD32(r14 + 8);
                    r1 = LD32(r14 + 12);
                    r13 = LD32((80 + r14));
                    ST32(r13, r0);
                    ST32(r13 + 4, r1);
                }
            }
        } else {
            ST32(r14 + 20, r1);
            r12 = LD32((80 + r14));
            r11 = 0;
            if (!((r12 & r12) == 0)) {
                r13 = LD32(r14 + 16);
                ST32(r14 + 12, r13);
                ST32(r14 + 8, r0);
                r0 = LD32(r14 + 8);
                r1 = LD32(r14 + 12);
                r13 = LD32((80 + r14));
                ST32(r13, r0);
                ST32(r13 + 4, r1);
            }
        }
    }
    r0 = LD32(r14 + 20);
    ST32(r14 + 4, r11);
    ST32(r14, r0);
    r0 = LD32(r14);
    r1 = LD32(r14 + 4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607507C(int r4)
{
    int r0, r1;
    FRAME(sp, 4);

    r1 = LD8(r4);
    r0 = r4;
    if (!((r1 & r1) == 0)) {
        r4 = r4 + 1;
        do {
            r1 = LD8(r4);
            r4 = r4 + 1;
        } while (AGAIN(!((r1 & r1) == 0)));
        r4 = r4 - 1;
    }
    return r4 - r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060750A0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, c3, c4;
    FRAME(sp, 4);

    r3 = r4;
    r0 = r3;
    if (!((r6 & r6) == 0)) {
        while (1) {
            r1 = LD8(r5);
            r5 = r5 + 1;
            r6 = r6 - 1;
            ST8(r0, r1);
            r0 = r0 + 1;
            if ((((signed char)r1) & ((signed char)r1)) == 0) {
                break;
            } else {
                if (!((r6 & r6) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    c3 = (r6 & r6) == 0;
    r6 = r6 - 1;
    if (!(c3)) {
        r2 = 0;
        do {
            ST8(r0, r2);
            r0 = r0 + 1;
            c4 = (r6 & r6) == 0;
            r6 = r6 - 1;
        } while (AGAIN(!(c4)));
    }
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060750DC(int r4, int r5)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r0 = r4;
    r2 = r0;
    r1 = LD8(r5);
    r5 = r5 + 1;
    ST8(r2, r1);
    r0 = r0 + 1;
    if (!((((signed char)r1) & ((signed char)r1)) == 0)) {
        do {
            r1 = LD8(r5);
            r5 = r5 + 1;
            ST8(r0, r1);
            r0 = r0 + 1;
        } while (AGAIN(!((((signed char)r1) & ((signed char)r1)) == 0)));
    }
    return r2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06075104(int r4, int r5)
{
    int r1, r2, c1;
    FRAME(sp, 4);

    r2 = LD8(r4);
    while (1) {
        c1 = (((signed char)r2) & ((signed char)r2)) == 0;
        r2 = (signed char)r2;
        if (!(c1)) {
            POLL();
            r1 = LD8(r5);
            if (!(r2 == r1)) {
                break;
            } else {
                r4 = r4 + 1;
                r2 = LD8(r4);
                r5 = r5 + 1;
                continue;
            }
        } else {
            break;
        }
    }
    r2 = LD8(r4);
    r1 = LD8(r5);
    return (r2 & 255) - (r1 & 255);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06075238(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, c5, c6, c7;
    FRAME(sp, 12);

    if (!((r6 & r6) == 0)) {
        r6 = r6 - 1;
        if (!(r6 == -1)) {
            r8 = 0x06075135;
            while (1) {
                r7 = LD8(r4);
                r2 = LD8(r7 + r8);
                r1 = r7;
                if (!(((r2 & 2) & (r2 & 2)) == 0)) {
                    r1 = r1 - 32;
                }
                r2 = LD8(r5);
                r9 = LD8(r2 + r8);
                r3 = r2;
                if (!(((r9 & 2) & (r9 & 2)) == 0)) {
                    r3 = r3 - 32;
                }
                c5 = (r6 & r6) == 0;
                if (!(r1 == r3)) {
                    break;
                } else {
                    c6 = (r7 & r7) == 0;
                    if (c5) {
                        break;
                    } else {
                        c7 = (r2 & r2) == 0;
                        if (c6) {
                            break;
                        } else {
                            if (c7) {
                                break;
                            } else {
                                r4 = r4 + 1;
                                r6 = r6 - 1;
                                r5 = r5 + 1;
                                if (!(r6 == -1)) {
                                    POLL();
                                    continue;
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                }
                POLL();
            }
        }
        r1 = LD8(r4);
        r3 = 0x06075135;
        r2 = r1 & 255;
        r1 = LD8(r2 + 0x06075135);
        if (!(((r1 & 2) & (r1 & 2)) == 0)) {
            r2 = r2 - 32;
        }
        r1 = LD8(r5);
        r7 = r1 & 255;
        r1 = LD8(r7 + r3);
        if (!(((r1 & 2) & (r1 & 2)) == 0)) {
            r7 = r7 - 32;
        }
        r0 = r2 - r7;
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060752CC(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;
    FRAME(sp, 4);

    r3 = r6;
    while (1) {
        r3 = r3 - 1;
        r0 = 0;
        if (!(r3 == -1)) {
            POLL();
            r1 = LD8(r4);
            r2 = LD8(r5);
            r1 = r1 & 255;
            r2 = r2 & 255;
            r0 = r1;
            if (r1 == r2) {
                r4 = r4 + 1;
                r5 = r5 + 1;
                continue;
            } else {
                r0 = r0 - r2;
                break;
            }
        } else {
            break;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060752FC(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, c2, c3, c4;
    FRAME(sp, 4);

    r0 = r6;
    if (!((r0 & r0) == 0)) {
        while (1) {
            r0 = r0 - 1;
            if (!(r0 == -1)) {
                POLL();
                r3 = LD8(r4);
                r7 = LD8(r5);
                c2 = (r0 & r0) == 0;
                if (!(r3 == r7)) {
                    break;
                } else {
                    c3 = (r3 & r3) == 0;
                    if (c2) {
                        break;
                    } else {
                        c4 = (r7 & r7) == 0;
                        if (c3) {
                            break;
                        } else {
                            if (c4) {
                                break;
                            } else {
                                r4 = r4 + 1;
                                r5 = r5 + 1;
                                continue;
                            }
                        }
                    }
                }
            } else {
                break;
            }
        }
        r2 = LD8(r4);
        r1 = LD8(r5);
        r0 = (r2 & 255) - (r1 & 255);
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607533C(int r4, int r5)
{
    int r1, r2, r3, r7;
    FRAME(sp, 4);

    r2 = LD8(r4);
    if (!((((signed char)r2) & ((signed char)r2)) == 0)) {
        r3 = 0x06075135;
        while (1) {
            r2 = (signed char)r2;
            r1 = LD8(r2 + r3);
            if (!(((r1 & 2) & (r1 & 2)) == 0)) {
                r2 = r2 - 32;
            }
            r1 = LD8(r5);
            r7 = LD8(r1 + r3);
            if (!(((r7 & 2) & (r7 & 2)) == 0)) {
                r1 = r1 - 32;
            }
            if (!(r2 == r1)) {
                break;
            } else {
                r4 = r4 + 1;
                r2 = LD8(r4);
                r5 = r5 + 1;
                if (!((((signed char)r2) & ((signed char)r2)) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    r1 = LD8(r4);
    r3 = 0x06075135;
    r2 = r1 & 255;
    r1 = LD8(r2 + 0x06075135);
    if (!(((r1 & 2) & (r1 & 2)) == 0)) {
        r2 = r2 - 32;
    }
    r1 = LD8(r5);
    r7 = r1 & 255;
    r1 = LD8(r7 + r3);
    if (!(((r1 & 2) & (r1 & 2)) == 0)) {
        r7 = r7 - 32;
    }
    return r2 - r7;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06075408(int r4, int r5)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r0 = r4;
    r2 = r0;
    r1 = LD8(r2);
    if (!((r1 & r1) == 0)) {
        r0 = r0 + 1;
        do {
            r1 = LD8(r0);
            r0 = r0 + 1;
        } while (AGAIN(!((r1 & r1) == 0)));
        r0 = r0 - 1;
    }
    do {
        r1 = LD8(r5);
        r5 = r5 + 1;
        ST8(r0, r1);
        r0 = r0 + 1;
    } while (AGAIN(!((((signed char)r1) & ((signed char)r1)) == 0)));
    return r2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06075438(int r4)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL3(0x060452E0, r4, 0, 10);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06075454(int r4)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL3(0x060452E0, r4, 0, 10);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06075470(int r4, int r5, int r6)
{
    int r1, r2, r3, r7;
    FRAME(sp, 4);

    r3 = r4;
    r1 = LD8(r3);
    r2 = r6;
    if (!((r1 & r1) == 0)) {
        r4 = r4 + 1;
        do {
            r1 = LD8(r4);
            r4 = r4 + 1;
        } while (AGAIN(!((r1 & r1) == 0)));
        r4 = r4 - 1;
    }
    r2 = r2 - 1;
    r7 = 0;
    if (!(r2 == -1)) {
        while (1) {
            r1 = LD8(r5);
            r5 = r5 + 1;
            ST8(r4, r1);
            r4 = r4 + 1;
            if ((((signed char)r1) & ((signed char)r1)) == 0) {
                break;
            } else {
                if ((r2 & r2) == 0) {
                    ST8(r4, r7);
                }
                r2 = r2 - 1;
                if (!(r2 == -1)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060754B8(int r4, int r5)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL2(0x0607589C, r4, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060754D0(int r4, int r5, int r6)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r0 = r6;
    r2 = r4;
    while (1) {
        r0 = r0 - 1;
        if (!(r0 == -1)) {
            POLL();
            r1 = LD8(r2);
            if (!((r1 & 255) == r5)) {
                r2 = r2 + 1;
                continue;
            } else {
                r0 = r2;
                break;
            }
        } else {
            r0 = 0;
            break;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060757E4(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;
    FRAME(sp, 4);

    r3 = r4;
    r0 = r6;
    r2 = r3;
    if ((unsigned)r5 >= (unsigned)r3) {
        r0 = r0 - 1;
        if (!(r0 == -1)) {
            do {
                r1 = LD8(r5);
                r5 = r5 + 1;
                r0 = r0 - 1;
                ST8(r2, r1);
                r2 = r2 + 1;
            } while (AGAIN(!(r0 == -1)));
        }
    } else {
        r1 = r5 + r0;
        if ((unsigned)r3 >= (unsigned)r1) {
            r0 = r0 - 1;
            if (!(r0 == -1)) {
                do {
                    r1 = LD8(r5);
                    r5 = r5 + 1;
                    r0 = r0 - 1;
                    ST8(r2, r1);
                    r2 = r2 + 1;
                } while (AGAIN(!(r0 == -1)));
            }
        } else {
            r2 = r2 + r0;
            r0 = r0 - 1;
            r5 = r1;
            if (!(r0 == -1)) {
                do {
                    r5 = r5 - 1;
                    r1 = LD8(r5);
                    r0 = r0 - 1;
                    r2 = r2 - 1;
                    ST8(r2, r1);
                } while (AGAIN(!(r0 == -1)));
            }
        }
    }
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06075830(int r4, int r5)
{
    int r0, r1, r2, r3;
    FRAME(sp, 4);

    r3 = r4;
    r1 = LD8(r3);
    if (!((r1 & r1) == 0)) {
        r0 = 0;
        while (1) {
            r2 = LD8(r0 + r5);
            if ((r2 & r2) == 0) {
                POLL();
                r0 = r3;
                break;
            } else {
                r1 = LD8(r0 + r3);
                r0 = r0 + 1;
                if (r2 == r1) {
                    POLL();
                    continue;
                } else {
                    r3 = r3 + 1;
                    r1 = LD8(r3);
                    r0 = 0;
                    if (!((r1 & r1) == 0)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
            }
            POLL();
        }
    } else {
        r1 = LD8(r5);
        r0 = 0;
        if ((r1 & r1) == 0) {
            r0 = r3;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06075868(int r4, int r5, int r6)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL3(0x060752CC, r4, r5, r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06075880(int r4, int r5, int r6)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL3(0x060757E4, r5, r4, r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607589C(int r4, int r5)
{
    int r0, r1, r2, c1;
    FRAME(sp, 4);

    r0 = r4;
    r2 = LD8(r0);
    r5 = (signed char)r5;
    while (1) {
        r1 = (signed char)r2;
        c1 = r1 == r5;
        if (!((r1 & r1) == 0)) {
            POLL();
            if (c1) {
                break;
            } else {
                r0 = r0 + 1;
                r2 = LD8(r0);
                continue;
            }
        } else {
            break;
        }
    }
    r1 = LD8(r0);
    if (!(r1 == r5)) {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607596C(int r4)
{
    int r0;
    FRAME(sp, 4);

    r0 = r4;
    if (!(r0 >= 0)) {
        r0 = -r0;
    }
    return r0;
}
