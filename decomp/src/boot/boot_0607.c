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
void f06072820(int r4, int r5, int r6, int r7)
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
    return;
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

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06070974(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    FRAME(sp, 8);

    r2 = r4;
    r4 = r5;
    if (!((unsigned)r2 > (unsigned)7)) {
        r1 = LD16(0x06070994 + (r2 + r2));
        switch (r1) {
        case 16:
            r0 = GCALL4(0x06070A68, r4, 0, r6, r7);
            break;
        case 26:
            r0 = GCALL1(0x06070C2C, r4);
            break;
        case 36:
            r0 = GCALL1(0x06070CBC, r4);
            break;
        case 46:
            r0 = GCALL1(0x06070E10, r4);
            break;
        case 56:
            r0 = GCALL1(0x06070EB0, r4);
            break;
        case 66:
            r0 = GCALL1(0x06070FE4, r4);
            break;
        case 76:
            r0 = GCALL1(0x06071344, r4);
            break;
        case 86:
            r0 = GCALL1(0x06071148, r4);
            break;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06072224(int r4, int r5)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r2 = LD32(r4);
    if ((unsigned)r2 > (unsigned)3) {
        r1 = 0;
        ST8(r5, r1);
        ST8((r5 + 1), r1);
        r2 = r5;
    } else {
        r1 = LD16(0x06072240 + (r2 + r2));
        switch (r1) {
        case 70:
            r1 = 0;
            ST8(r5, r1);
            ST8((r5 + 1), r1);
            r2 = r5;
            break;
        case 34:
            r0 = LD8((r4 + 5));
            ST8(r5, (r0 | 128));
            r1 = LD8((r4 + 6));
            ST8((r5 + 1), r1);
            r2 = r5;
            r1 = LD8((r4 + 7));
            break;
        case 8:
            ST8(r5, 0);
            r1 = LD8((r4 + 4));
            ST8((r5 + 1), r1);
            r2 = r5;
            r1 = LD8((r4 + 5));
            break;
        case 66:
            r1 = -1;
            ST8(r5, r1);
            ST8((r5 + 1), r1);
            r2 = r5;
            break;
        }
    }
    ST8((r2 + 2), r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06070818(void)
{
    int r0, r1, r2, r4, r5, r8, r9, r10, r11, r14, c7, c1012;
    FRAME(sp, 28);

    r14 = sp - 28;
    ST32(r14, 0);
    r2 = LD32(0x0608F458);
    r1 = LD32(r2 + 60);
    r9 = 0;
    if ((r1 & r1) == 0) {
        r8 = 0x0608F458;
        r4 = LD32(0x0608F458);
        r0 = GCALL1(0x060703C8, (r4 + 64));
        r1 = LD32(0x0608F454);
        r0 = 2;
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x06071488, 0x400);
            if (r0 == 1) {
                r0 = GCALL1(0x0606C2FC, -1025);
                r4 = LD32(r8);
                r2 = LD32((r4 + 76));
                r1 = r4;
                if (!((r2 & r2) == 0)) {
                    r4 = LD32((r1 + 80));
                    r0 = GCALL1(r2, r4);
                }
            }
            r8 = 0;
            r11 = 0x060708EC;
            r10 = 0x06070974;
            while (1) {
                r0 = GCALL1(r11, r8);
                r5 = r14;
                if (!((r0 & r0) == 0)) {
                    r8 = r8 + 1;
                    c1012 = r9 > 0;
                    if (!(r8 > 7)) {
                        POLL();
                        continue;
                    } else {
                        r0 = c1012;
                        break;
                    }
                } else {
                    r0 = GCALL2(r10, r8, r5);
                    r2 = LD32(r14);
                    if (!(r0 >= 0)) {
                        break;
                    } else {
                        c7 = r2 > 30;
                        r9 = r9 + r0;
                        c1012 = c7;
                        if (c7) {
                            r0 = c1012;
                            break;
                        } else {
                            r8 = r8 + 1;
                            c1012 = r9 > 0;
                            if (!(r8 > 7)) {
                                POLL();
                                continue;
                            } else {
                                r0 = c1012;
                                break;
                            }
                        }
                    }
                }
                POLL();
            }
        }
    } else {
        r1 = r1 - 1;
        ST32(r2 + 60, r1);
        if (r1 > 0) {
            r8 = 0x0608F458;
            r4 = LD32(0x0608F458);
            r0 = GCALL1(0x060703C8, (r4 + 64));
            r1 = LD32(0x0608F454);
            r0 = 2;
            if ((r1 & r1) == 0) {
                r0 = GCALL1(0x06071488, 0x400);
                if (r0 == 1) {
                    r0 = GCALL1(0x0606C2FC, -1025);
                    r4 = LD32(r8);
                    r2 = LD32((r4 + 76));
                    r1 = r4;
                    if (!((r2 & r2) == 0)) {
                        r4 = LD32((r1 + 80));
                        r0 = GCALL1(r2, r4);
                    }
                }
                r8 = 0;
                r11 = 0x060708EC;
                r10 = 0x06070974;
                while (1) {
                    r0 = GCALL1(r11, r8);
                    r5 = r14;
                    if (!((r0 & r0) == 0)) {
                        r8 = r8 + 1;
                        c1012 = r9 > 0;
                        if (!(r8 > 7)) {
                            POLL();
                            continue;
                        } else {
                            r0 = c1012;
                            break;
                        }
                    } else {
                        r0 = GCALL2(r10, r8, r5);
                        r2 = LD32(r14);
                        if (!(r0 >= 0)) {
                            break;
                        } else {
                            c7 = r2 > 30;
                            r9 = r9 + r0;
                            c1012 = c7;
                            if (c7) {
                                r0 = c1012;
                                break;
                            } else {
                                r8 = r8 + 1;
                                c1012 = r9 > 0;
                                if (!(r8 > 7)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = c1012;
                                    break;
                                }
                            }
                        }
                    }
                    POLL();
                }
            }
        } else {
            r0 = GCALL0(0x060714AC);
            r0 = 3;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06071924(int r4)
{
    int r0, r1, r8, r9, r14, c2, c1006;
    FRAME(sp, 24);

    r14 = sp - 24;
    r9 = r4;
    r1 = 2;
    if (r9 == 1) {
        r1 = r1 | 128;
    }
    r0 = GCALL2(0x0606C508, r1, r14);
    r8 = r0;
    c2 = (r8 & r8) == 0;
    c1006 = c2;
    if (r9 == 1) {
        r0 = LD32(r14);
        c1006 = c2;
        if (c2) {
            c1006 = (r8 & r8) == 0;
            if (!(((r0 & 128) & (r0 & 128)) == 0)) {
                r8 = -4;
                c1006 = -4 == 0;
            }
        }
    }
    r4 = r14;
    if (!(c1006)) {
        r0 = GCALL1(0x06071990, (r4 + 4));
    }
    r0 = GCALL1(0x0606C32C, -3);
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072CD4(int r4, int r5)
{
    int r0, r9, r14, c2008;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 48, r4);
    ST32(r14 + 52, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 48), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 52), r9);
    r0 = GCALL3(0x06072B80, r14, r9, (r14 + 32));
    c2008 = R(8);
    SETR(8, 0x06072AC0);
    r0 = GCALL1(0x060729A0, r0);
    SETR(8, c2008);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072D28(int r4, int r5)
{
    int r0, r9, r14, c2008;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 48, r4);
    ST32(r14 + 52, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 48), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 52), r9);
    r0 = LD32(r14 + 20);
    ST32(r14 + 20, (r0 ^ 1));
    r0 = GCALL3(0x06072B80, r14, r9, (r14 + 32));
    c2008 = R(8);
    SETR(8, 0x06072AC0);
    r0 = GCALL1(0x060729A0, r0);
    SETR(8, c2008);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072EA8(int r4, int r5)
{
    int r0, r9, r14, c2008;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 48, r4);
    ST32(r14 + 52, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 48), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 52), r9);
    r0 = GCALL3(0x06072D80, r14, r9, (r14 + 32));
    c2008 = R(8);
    SETR(8, 0x06072AC0);
    r0 = GCALL1(0x060729A0, r0);
    SETR(8, c2008);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072FC4(int r4, int r5)
{
    int r0, r9, r14, c2008;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14 + 48, r4);
    ST32(r14 + 52, r5);
    r0 = GCALL2(0x06072AC0, (r14 + 48), r14);
    r9 = r14 + 16;
    r0 = GCALL2(0x06072AC0, (r14 + 52), r9);
    r0 = GCALL2(0x06072EFC, r14, r9);
    c2008 = R(8);
    SETR(8, 0x06072AC0);
    r0 = GCALL1(0x060729A0, r0);
    SETR(8, c2008);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073368(int r4)
{
    int r0, r1, r2, r3, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    ST32(r14, 3);
    r2 = (int)((unsigned)r4 >> 31);
    ST32(r14 + 4, r2);
    if (!((r4 & r4) == 0)) {
        ST32(r14 + 8, 30);
        if ((r2 & r2) == 0) {
            ST32(r14 + 12, r4);
            r2 = LD32(r14 + 12);
            r3 = 0x3FFFFFFF;
            if (!((unsigned)r2 > (unsigned)0x3FFFFFFF)) {
                do {
                    r2 = r2 + r2;
                    ST32(r14 + 12, r2);
                    r1 = LD32(r14 + 8);
                    ST32(r14 + 8, (r1 - 1));
                } while (AGAIN(!((unsigned)r2 > (unsigned)r3)));
            }
            r0 = GCALL1(0x060729A0, r14);
        } else {
            r1 = -r4;
            if (!(r4 == ((int)0x80000000))) {
                ST32(r14 + 12, r1);
                r2 = LD32(r14 + 12);
                r3 = 0x3FFFFFFF;
                if (!((unsigned)r2 > (unsigned)0x3FFFFFFF)) {
                    do {
                        r2 = r2 + r2;
                        ST32(r14 + 12, r2);
                        r1 = LD32(r14 + 8);
                        ST32(r14 + 8, (r1 - 1));
                    } while (AGAIN(!((unsigned)r2 > (unsigned)r3)));
                }
                r0 = GCALL1(0x060729A0, r14);
            } else {
                r0 = LD32(0x06073364);
            }
        }
    } else {
        ST32(r14, 2);
        r0 = GCALL1(0x060729A0, r14);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073464(int r4)
{
    int r0, r1, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    ST32(r14 + 16, r4);
    r0 = GCALL2(0x06072AC0, (r14 + 16), r14);
    r1 = LD32(r14 + 4);
    ST32(r14 + 4, ((r1 & r1) == 0));
    r0 = GCALL1(0x060729A0, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073498(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    ST32(r14, r4);
    ST32(r14 + 4, r5);
    ST32(r14 + 8, r6);
    ST32(r14 + 12, r7);
    r0 = GCALL1(0x060729A0, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060734BC(int r4)
{
    int r0, r5, r6, r7, r8, r14, c2008;
    FRAME(sp, 32);

    r14 = sp - 32;
    ST32(r14 + 16, r4);
    r0 = GCALL2(0x06072AC0, (r14 + 16), r14);
    r7 = LD32(r14 + 12);
    r6 = LD32(r14 + 8);
    r5 = LD32(r14 + 4);
    r8 = r7;
    r7 = ((int)((unsigned)r8 >> 2)) | (((int)((unsigned)0 >> 2)) << 16);
    r8 = ((int)((unsigned)(r8 << 16) >> 2)) << 16;
    ST32((sp - 36), r8);
    r4 = LD32(r14);
    c2008 = R(8);
    SETR(8, r8);
    r0 = GCALL5(0x06074520, r4, r5, r6, r7, LD32((sp - 36)));
    SETR(8, c2008);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073A20(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r10, r14, c2008;
    FRAME(sp, 96);

    r14 = sp - 96;
    r1 = r14 + 60;
    ST32(r1, r4);
    ST32(r1 + 4, r5);
    r9 = r14 + 68;
    ST32(r9, r6);
    ST32(r9 + 4, r7);
    r0 = GCALL2(0x060736D8, r1, r14);
    r10 = r14 + 20;
    r0 = GCALL2(0x060736D8, r9, r10);
    r0 = LD32(r14 + 24);
    ST32(r14 + 24, (r0 ^ 1));
    r0 = GCALL3(0x060737D4, r14, r10, (r14 + 40));
    c2008 = R(8);
    SETR(8, 0x060736D8);
    r0 = GCALL1(0x06073520, r0);
    SETR(8, c2008);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060744E8(int r4, int r5)
{
    int r0, r1, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    ST32(r14 + 20, r4);
    ST32(r14 + 24, r5);
    r0 = GCALL2(0x060736D8, (r14 + 20), r14);
    r1 = LD32(r14 + 4);
    ST32(r14 + 4, ((r1 & r1) == 0));
    r0 = GCALL1(0x06073520, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074520(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r14;
    FRAME(sp, 32);

    r14 = sp - 32;
    ST32(r14 + 28, r7);
    ST32(r14, r4);
    ST32(r14 + 4, r5);
    ST32(r14 + 8, r6);
    r1 = LD32(r14 + 28);
    r2 = LD32(r14 + 32);
    ST32(r14 + 12, r1);
    ST32(r14 + 16, r2);
    r0 = GCALL1(0x06073520, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074550(int r4, int r5)
{
    int r0, r1, r2, r6, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    ST32(r14 + 20, r4);
    ST32(r14 + 24, r5);
    r0 = GCALL2(0x060736D8, (r14 + 20), r14);
    r1 = LD32(r14 + 12);
    r2 = LD32(r14 + 16);
    r6 = LD32(r14 + 8);
    r5 = LD32(r14 + 4);
    r4 = LD32(r14);
    r0 = GCALL4(0x06073498, r4, r5, r6, ((r1 << 2) | ((int)((unsigned)(((int)((unsigned)r2 >> 16)) << 2) >> 16))));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060746CC(int r4, int r5)
{
    int r0, r1, r6, r7, r8, r9;
    FRAME(sp, 16);

    r8 = r4;
    r9 = r5;
    r6 = LD32(0x060746BC);
    r7 = LD32(0x060746C0);
    r0 = GCALL4(0x0607429C, r4, r5, r6, r7);
    r4 = r8;
    if (r0 >= 0) {
        r6 = LD32(0x060746C4);
        r7 = LD32(0x060746C8);
        r0 = GCALL4(0x060739C0, r4, r9, r6, r7);
        r1 = R(1);
        r0 = GCALL2(0x06074454, r0, r1);
        r0 = r0 - ((int)0x80000000);
    } else {
        r0 = GCALL2(0x06074454, r4, r9);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060729A0(int r4)
{
    int r0, r1, r5, r7, r8, c4, c6, c9, c1012;
    FRAME(sp, 12);

    r8 = R(8);
    r1 = LD32(r4 + 4);
    r0 = LD32(r4);
    r8 = (r8 & 0x7FFFFFFF) | (((int)((unsigned)(r1 << 16) >> 1)) << 16);
    r7 = LD32(r4 + 12);
    if ((((unsigned)1 >= (unsigned)r0) & ((unsigned)1 >= (unsigned)r0)) == 0) {
        c4 = r0 == 2;
        c1012 = c4;
        if (!(((r0 == 4) & (r0 == 4)) == 0)) {
            r8 = r8 | 0x7F800000;
            r8 = r8 & ((int)0xFF800000);
        } else {
            c6 = (r7 & r7) == 0;
            if ((c4 & c4) == 0) {
                r1 = -126;
                if (!(c6)) {
                    r4 = LD32(r4 + 8);
                    r5 = -r4;
                    if (r4 >= r1) {
                        c9 = r4 > 127;
                        r1 = r4;
                        c1012 = c9;
                        if (!(c9)) {
                            r8 = (r8 & ((int)0x807FFFFF)) | (((int)((unsigned)(((r1 + 127) & 255) << 16) >> 1)) << 8);
                            if (!((r7 & 127) == 64)) {
                                r7 = r7 + 63;
                            } else {
                                if (!(((128 & r7) & (128 & r7)) == 0)) {
                                    r7 = r7 + 64;
                                }
                            }
                            r1 = r7;
                            if ((unsigned)r7 > (unsigned)0x7FFFFFFF) {
                                r7 = (int)((unsigned)r7 >> 1);
                                r8 = (r8 & ((int)0x807FFFFF)) | (((int)((unsigned)(((((int)((unsigned)(((int)((unsigned)r8 >> 16)) + ((int)((unsigned)r8 >> 16))) >> 8)) + 1) & 255) << 16) >> 1)) << 8);
                                r1 = r7;
                            }
                            r1 = (int)((unsigned)((int)((unsigned)(r1 << 2) >> 8)) >> 1);
                            r8 = r8 & ((int)0xFF800000);
                            r8 = r8 | r1;
                        } else {
                            r8 = r8 | 0x7F800000;
                            r8 = r8 & ((int)0xFF800000);
                        }
                    } else {
                        r5 = r5 - 126;
                        r8 = r8 & ((int)0x807FFFFF);
                        if (!(r5 > 25)) {
                            r0 = GCALL2(0x0607462C, r7, r5);
                            r7 = r0;
                            r1 = r7;
                        } else {
                            r1 = 0;
                        }
                        r1 = (int)((unsigned)((int)((unsigned)(r1 << 2) >> 8)) >> 1);
                        r8 = r8 & ((int)0xFF800000);
                        r8 = r8 | r1;
                    }
                } else {
                    r8 = LD32(0x0607299C);
                }
            } else {
                r8 = r8 & ((int)0x807FFFFF);
                r8 = r8 & ((int)0xFF800000);
            }
        }
    } else {
        r8 = ((r8 | 0x7F800000) & ((int)0xFF800000)) | (r7 & 0x007FFFFF);
        r1 = ((r8 & 0x007FFFFF) | 0x00100000) & 0x007FFFFF;
        r8 = r8 & ((int)0xFF800000);
        r8 = r8 | r1;
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072D80(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, c9, c14, c17, c31, c33, c1026, c1027, c1028;
    long long m0;
    FRAME(sp, 4);

    r2 = LD32(r4);
    if (!((((unsigned)1 >= (unsigned)r2) & ((unsigned)1 >= (unsigned)r2)) == 0)) {
        r2 = LD32(r4 + 4);
        r1 = LD32(r5 + 4);
        c14 = r2 == r1;
        ST32(r4 + 4, (c14 ^ 1));
        r0 = r4;
        c1028 = c14;
    } else {
        r3 = LD32(r5);
        if (!((((unsigned)1 >= (unsigned)r3) & ((unsigned)1 >= (unsigned)r3)) == 0)) {
            r2 = LD32(r4 + 4);
            r1 = LD32(r5 + 4);
            c17 = r2 == r1;
            ST32(r5 + 4, (c17 ^ 1));
            r0 = r5;
            c1028 = c17;
        } else {
            r0 = r3;
            if (((r2 == 4) & (r2 == 4)) == 0) {
                c9 = ((r0 == 4) & (r0 == 4)) == 0;
                r0 = r2;
                if (c9) {
                    if (((r0 == 2) & (r0 == 2)) == 0) {
                        if (((r3 == 2) & (r3 == 2)) == 0) {
                            r2 = LD32(r4 + 12);
                            r1 = LD32(r5 + 12);
                            m0 = (long long)((unsigned long long)(unsigned)r2 * (unsigned)r1);
                            r3 = (int)(m0 >> 32);
                            r1 = LD32(r4 + 8);
                            r2 = LD32(r5 + 8);
                            ST32(r6 + 8, (r1 + r2));
                            r2 = LD32(r4 + 4);
                            r1 = LD32(r5 + 4);
                            r0 = (r2 == r1) ^ 1;
                            r1 = LD32(r6 + 8);
                            ST32(r6 + 4, r0);
                            ST32(r6 + 8, (r1 + 2));
                            r1 = 0x7FFFFFFF;
                            r7 = (int)m0;
                            if ((unsigned)r3 > (unsigned)0x7FFFFFFF) {
                                r5 = (int)0x80000000;
                                r2 = r1;
                                do {
                                    r1 = LD32(r6 + 8);
                                    ST32(r6 + 8, (r1 + 1));
                                    if (!(((1 & r3) & (1 & r3)) == 0)) {
                                        r7 = ((int)((unsigned)r7 >> 1)) | r5;
                                    }
                                    r3 = (int)((unsigned)r3 >> 1);
                                } while (AGAIN((unsigned)r3 > (unsigned)r2));
                            }
                            r1 = 0x3FFFFFFF;
                            if (!((unsigned)r3 > (unsigned)0x3FFFFFFF)) {
                                r2 = r1;
                                r5 = (int)0x80000000;
                                do {
                                    r1 = LD32(r6 + 8);
                                    r3 = r3 + r3;
                                    ST32(r6 + 8, (r1 - 1));
                                    if (!(((r7 & r5) & (r7 & r5)) == 0)) {
                                        r3 = r3 | 1;
                                    }
                                    r7 = r7 + r7;
                                } while (AGAIN(!((unsigned)r3 > (unsigned)r2)));
                            }
                            c31 = (r3 & 127) == 64;
                            c1027 = c31;
                            if (c31) {
                                c33 = (r7 & r7) == 0;
                                c1026 = c33;
                                if (!(((128 & r3) & (128 & r3)) == 0)) {
                                    r3 = r3 + 64;
                                    c1027 = c1026;
                                } else {
                                    c1027 = c33;
                                    c1026 = c33;
                                    if (!(c33)) {
                                        r3 = r3 + 64;
                                        c1027 = c1026;
                                    }
                                }
                            }
                            ST32(r6 + 12, r3);
                            ST32(r6, 3);
                            r0 = r6;
                            c1028 = c1027;
                        } else {
                            r2 = LD32(r4 + 4);
                            r1 = LD32(r5 + 4);
                            c17 = r2 == r1;
                            ST32(r5 + 4, (c17 ^ 1));
                            r0 = r5;
                            c1028 = c17;
                        }
                    } else {
                        r2 = LD32(r4 + 4);
                        r1 = LD32(r5 + 4);
                        c14 = r2 == r1;
                        ST32(r4 + 4, (c14 ^ 1));
                        r0 = r4;
                        c1028 = c14;
                    }
                } else {
                    if (((r0 == 2) & (r0 == 2)) == 0) {
                        r2 = LD32(r4 + 4);
                        r1 = LD32(r5 + 4);
                        c17 = r2 == r1;
                        ST32(r5 + 4, (c17 ^ 1));
                        r0 = r5;
                        c1028 = c17;
                    } else {
                        r0 = 0x06089774;
                    }
                }
            } else {
                if (!(((r0 == 2) & (r0 == 2)) == 0)) {
                    r0 = 0x06089774;
                } else {
                    r2 = LD32(r4 + 4);
                    r1 = LD32(r5 + 4);
                    c14 = r2 == r1;
                    ST32(r4 + 4, (c14 ^ 1));
                    r0 = r4;
                    c1028 = c14;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073520(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, c5, c7, c8, c11, c17, c18, c25, c1013;
    FRAME(sp, 24);

    r8 = R(8);
    r3 = r4;
    r4 = LD32(r3 + 12);
    r5 = LD32(r3 + 16);
    r2 = LD32(r3 + 4);
    r0 = LD32(r3);
    r8 = (0x7FFFFFFF & r8) | (((int)((unsigned)(r2 << 16) >> 1)) << 16);
    if ((((unsigned)1 >= (unsigned)r0) & ((unsigned)1 >= (unsigned)r0)) == 0) {
        c5 = r0 == 2;
        c1013 = c5;
        if (!(((r0 == 4) & (r0 == 4)) == 0)) {
            r8 = r8 | 0x7FF00000;
            r9 = 0;
            r8 = r8 & ((int)0xFFF00000);
        } else {
            c7 = (r4 & r4) == 0;
            if ((c5 & c5) == 0) {
                c8 = (r5 & r5) == 0;
                if (!(c7)) {
                    r2 = LD32(r3 + 8);
                    r6 = -1022 - r2;
                    if (r2 >= -1022) {
                        c11 = r2 > 0x3FF;
                        r2 = r2 + 0x3FF;
                        c1013 = c11;
                        if (!(c11)) {
                            r8 = (((int)0x800FFFFF) & r8) | ((((r2 & 0x7FF) << 16) << 2) << 2);
                            r3 = r5 & 255;
                            if (!(0 == 0)) {
                                r1 = 0;
                                r2 = 127;
                                c17 = r5;
                                c18 = c17 + r2;
                                r5 = c18 + 0;
                                r4 = (r4 + r1) + (((unsigned)c18 < (unsigned)c17) | ((unsigned)r5 < (unsigned)c18));
                            } else {
                                r1 = 0;
                                if (!(r3 == 128)) {
                                    r2 = 127;
                                    c17 = r5;
                                    c18 = c17 + r2;
                                    r5 = c18 + 0;
                                    r4 = (r4 + r1) + (((unsigned)c18 < (unsigned)c17) | ((unsigned)r5 < (unsigned)c18));
                                } else {
                                    r7 = r5 & 0x100;
                                    if (!(0 == 0)) {
                                        r1 = 0;
                                        r2 = 128;
                                        c17 = r5;
                                        c18 = c17 + r2;
                                        r5 = c18 + 0;
                                        r4 = (r4 + r1) + (((unsigned)c18 < (unsigned)c17) | ((unsigned)r5 < (unsigned)c18));
                                    } else {
                                        if (!((r7 & r7) == 0)) {
                                            r1 = 0;
                                            r2 = 128;
                                            c17 = r5;
                                            c18 = c17 + r2;
                                            r5 = c18 + 0;
                                            r4 = (r4 + r1) + (((unsigned)c18 < (unsigned)c17) | ((unsigned)r5 < (unsigned)c18));
                                        }
                                    }
                                }
                            }
                            if ((unsigned)r4 > (unsigned)0x1FFFFFFF) {
                                c25 = r4 & 1;
                                r4 = (int)((unsigned)r4 >> 1);
                                r5 = (int)(((unsigned)r5 >> 1) | (c25 << 31));
                                r8 = (((int)0x800FFFFF) & r8) | ((((((((int)((unsigned)((int)((unsigned)((int)((unsigned)r8 >> 16)) >> 2)) >> 2)) & 0x7FF) + 1) & 0x7FF) << 16) << 2) << 2);
                            }
                            r9 = ((r4 << 16) << 8) | ((int)((unsigned)r5 >> 8));
                            r8 = (((int)0xFFF00000) & r8) | (((int)((unsigned)r4 >> 8)) & 0x000FFFFF);
                        } else {
                            r8 = r8 | 0x7FF00000;
                            r9 = 0;
                            r8 = r8 & ((int)0xFFF00000);
                        }
                    } else {
                        r8 = r8 & ((int)0x800FFFFF);
                        if (!(r6 > 56)) {
                            r0 = GCALL3(0x06074924, r4, r5, r6);
                            r4 = r0;
                            r1 = R(1);
                            r5 = r1;
                        } else {
                            r4 = 0;
                            r5 = 0;
                        }
                        r9 = ((r4 << 16) << 8) | ((int)((unsigned)r5 >> 8));
                        r8 = (((int)0xFFF00000) & r8) | (((int)((unsigned)r4 >> 8)) & 0x000FFFFF);
                    }
                } else {
                    if (!(c8)) {
                        r2 = LD32(r3 + 8);
                        r6 = -1022 - r2;
                        if (r2 >= -1022) {
                            c11 = r2 > 0x3FF;
                            r2 = r2 + 0x3FF;
                            c1013 = c11;
                            if (!(c11)) {
                                r8 = (((int)0x800FFFFF) & r8) | ((((r2 & 0x7FF) << 16) << 2) << 2);
                                r3 = r5 & 255;
                                if (!(0 == 0)) {
                                    r1 = 0;
                                    r2 = 127;
                                    c17 = r5;
                                    c18 = c17 + r2;
                                    r5 = c18 + 0;
                                    r4 = (r4 + r1) + (((unsigned)c18 < (unsigned)c17) | ((unsigned)r5 < (unsigned)c18));
                                } else {
                                    r1 = 0;
                                    if (!(r3 == 128)) {
                                        r2 = 127;
                                        c17 = r5;
                                        c18 = c17 + r2;
                                        r5 = c18 + 0;
                                        r4 = (r4 + r1) + (((unsigned)c18 < (unsigned)c17) | ((unsigned)r5 < (unsigned)c18));
                                    } else {
                                        r7 = r5 & 0x100;
                                        if (!(0 == 0)) {
                                            r1 = 0;
                                            r2 = 128;
                                            c17 = r5;
                                            c18 = c17 + r2;
                                            r5 = c18 + 0;
                                            r4 = (r4 + r1) + (((unsigned)c18 < (unsigned)c17) | ((unsigned)r5 < (unsigned)c18));
                                        } else {
                                            if (!((r7 & r7) == 0)) {
                                                r1 = 0;
                                                r2 = 128;
                                                c17 = r5;
                                                c18 = c17 + r2;
                                                r5 = c18 + 0;
                                                r4 = (r4 + r1) + (((unsigned)c18 < (unsigned)c17) | ((unsigned)r5 < (unsigned)c18));
                                            }
                                        }
                                    }
                                }
                                if ((unsigned)r4 > (unsigned)0x1FFFFFFF) {
                                    c25 = r4 & 1;
                                    r4 = (int)((unsigned)r4 >> 1);
                                    r5 = (int)(((unsigned)r5 >> 1) | (c25 << 31));
                                    r8 = (((int)0x800FFFFF) & r8) | ((((((((int)((unsigned)((int)((unsigned)((int)((unsigned)r8 >> 16)) >> 2)) >> 2)) & 0x7FF) + 1) & 0x7FF) << 16) << 2) << 2);
                                }
                                r9 = ((r4 << 16) << 8) | ((int)((unsigned)r5 >> 8));
                                r8 = (((int)0xFFF00000) & r8) | (((int)((unsigned)r4 >> 8)) & 0x000FFFFF);
                            } else {
                                r8 = r8 | 0x7FF00000;
                                r9 = 0;
                                r8 = r8 & ((int)0xFFF00000);
                            }
                        } else {
                            r8 = r8 & ((int)0x800FFFFF);
                            if (!(r6 > 56)) {
                                r0 = GCALL3(0x06074924, r4, r5, r6);
                                r4 = r0;
                                r1 = R(1);
                                r5 = r1;
                            } else {
                                r4 = 0;
                                r5 = 0;
                            }
                            r9 = ((r4 << 16) << 8) | ((int)((unsigned)r5 >> 8));
                            r8 = (((int)0xFFF00000) & r8) | (((int)((unsigned)r4 >> 8)) & 0x000FFFFF);
                        }
                    } else {
                        r8 = LD32(0x06073518);
                        r9 = LD32(0x0607351C);
                    }
                }
            } else {
                r8 = r8 & ((int)0x800FFFFF);
                r9 = 0;
                r8 = r8 & ((int)0xFFF00000);
            }
        }
    } else {
        r8 = ((r8 | 0x7FF00000) & ((int)0xFFF00000)) | (r4 & 0x000FFFFF);
        r3 = LD32(0x06073510);
        r4 = LD32(0x06073514);
        r9 = r5;
        r8 = (r8 & ((int)0xFFF00000)) | (((r8 & 0x000FFFFF) | r3) & 0x000FFFFF);
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060736D8(int r4, int r5)
{
    int r1, r2, r3, r7, r8, r9, c3, c7, c11, c12, c1014;
    FRAME(sp, 12);

    r9 = LD32(r4 + 4);
    r2 = LD32(r4);
    r8 = r2 & 0x000FFFFF;
    r1 = LD8(r4);
    ST32(r5 + 4, ((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)((unsigned)(r1 & 255) >> 2)) >> 2)) >> 1)) >> 2)));
    r1 = 0x7FF0;
    r3 = LD16(r4);
    r2 = 0x7FF0 & r3;
    if (!((r2 & r2) == 0)) {
        r7 = r9;
        if (!(r2 == (r1 & 0xFFFF))) {
            ST32(r5 + 8, (((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)((unsigned)((r3 << 16) + (r3 << 16)) >> 16)) >> 2)) >> 1)) >> 2)) + -1023));
            ST32(r5, 3);
            r4 = LD32(0x060736D4);
            r3 = LD32(0x060736D0);
            ST32(r5 + 12, ((((int)((unsigned)((int)((unsigned)r7 >> 16)) >> 8)) | (r8 << 8)) | r3));
            ST32(r5 + 16, (r9 << 8));
        } else {
            c11 = (r9 & r9) == 0;
            if (!((r8 & r8) == 0)) {
                r1 = LD32(r5 + 4);
                c12 = (r1 & r1) == 0;
                r1 = 0;
                if (c12) {
                    ST32(r5, 1);
                    c1014 = 1;
                } else {
                    ST32(r5, r1);
                    c1014 = 0;
                }
                ST32(r5 + 12, r8);
                ST32(r5 + 16, r9);
            } else {
                r1 = 4;
                if (!(c11)) {
                    r1 = LD32(r5 + 4);
                    c12 = (r1 & r1) == 0;
                    r1 = 0;
                    if (c12) {
                        ST32(r5, 1);
                        c1014 = 1;
                    } else {
                        ST32(r5, r1);
                        c1014 = 0;
                    }
                    ST32(r5 + 12, r8);
                    ST32(r5 + 16, r9);
                } else {
                    ST32(r5, r1);
                }
            }
        }
    } else {
        c3 = (r9 & r9) == 0;
        if (!((r8 & r8) == 0)) {
            r1 = LD16(r4);
            ST32(r5 + 8, (((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)((unsigned)((r1 << 16) + (r1 << 16)) >> 16)) >> 2)) >> 1)) >> 2)) + -1022));
            r8 = ((int)((unsigned)((int)((unsigned)r9 >> 16)) >> 8)) | (r8 << 8);
            r9 = r9 << 8;
            ST32(r5, 3);
            r2 = 0x0FFFFFFF;
            while (1) {
                c1014 = r8 == r2;
                if ((unsigned)r8 > (unsigned)r2) {
                    break;
                } else {
                    c7 = (unsigned)r9 >> 31;
                    r9 = r9 << 1;
                    r8 = (r8 << 1) | c7;
                    r1 = LD32(r5 + 8);
                    r2 = 0x0FFFFFFF;
                    ST32(r5 + 8, (r1 - 1));
                }
                POLL();
            }
            ST32(r5 + 12, r8);
            ST32(r5 + 16, r9);
        } else {
            r1 = 2;
            if (!(c3)) {
                r1 = LD16(r4);
                ST32(r5 + 8, (((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)((unsigned)((r1 << 16) + (r1 << 16)) >> 16)) >> 2)) >> 1)) >> 2)) + -1022));
                r8 = ((int)((unsigned)((int)((unsigned)r9 >> 16)) >> 8)) | (r8 << 8);
                r9 = r9 << 8;
                ST32(r5, 3);
                r2 = 0x0FFFFFFF;
                while (1) {
                    c1014 = r8 == r2;
                    if ((unsigned)r8 > (unsigned)r2) {
                        break;
                    } else {
                        c7 = (unsigned)r9 >> 31;
                        r9 = r9 << 1;
                        r8 = (r8 << 1) | c7;
                        r1 = LD32(r5 + 8);
                        r2 = 0x0FFFFFFF;
                        ST32(r5 + 8, (r1 - 1));
                    }
                    POLL();
                }
                ST32(r5 + 12, r8);
                ST32(r5 + 16, r9);
            } else {
                ST32(r5, r1);
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060756C4(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, c0, c6, c10, c21, c1023, c1026;
    FRAME(sp, 12);

    r8 = r4;
    r0 = GCALL1(0x0607555C, r4);
    r2 = LD32(r8 + 4);
    c0 = r2 * 60;
    r3 = LD32(r8 + 8);
    r2 = LD32(r8);
    r4 = (r2 + c0) + (r3 * 0xE10);
    r1 = LD32(r8 + 12);
    r2 = LD32(r8 + 16);
    r7 = r1 - 1;
    r1 = LD32((r2 << 2) + 0x0607552C);
    r7 = r7 + r1;
    if (r2 > 1) {
        r0 = LD32(r8 + 20);
        if (((r0 & 3) & (r0 & 3)) == 0) {
            r7 = r7 + 1;
        }
    }
    ST32(r8 + 28, r7);
    r3 = LD32(r8 + 20);
    r0 = 70;
    if (!((unsigned)(r3 + 0x2710) > (unsigned)0x4E20)) {
        c6 = r0 >= r3;
        if (!(r3 > r0)) {
            r0 = 69;
            c10 = 69 > r3;
            c1023 = c10;
            if (!(r3 > 69)) {
                if (c10) {
                    r2 = r3;
                    r5 = -365;
                    r6 = -366;
                    r1 = 3;
                    do {
                        if (((r1 & r0) & (r1 & r0)) == 0) {
                            r7 = r7 + r6;
                            r0 = r0 - 1;
                        } else {
                            r7 = r7 + r5;
                            r0 = r0 - 1;
                        }
                        r1 = 3;
                    } while (AGAIN(r0 > r2));
                }
                if (((r0 & 3) & (r0 & 3)) == 0) {
                    r7 = r7 + -366;
                    c1023 = 1;
                } else {
                    r7 = r7 + -365;
                    c1023 = 0;
                }
            }
            r3 = r7;
        } else {
            r2 = r3;
            c1023 = c6;
            if (c6) {
                r3 = r7;
            } else {
                r5 = 0x16D;
                r6 = 0x16E;
                r1 = 3;
                do {
                    if (((r1 & r0) & (r1 & r0)) == 0) {
                        r7 = r7 + r6;
                        r0 = r0 + 1;
                    } else {
                        r7 = r7 + r5;
                        r0 = r0 + 1;
                    }
                    r1 = 3;
                } while (AGAIN(!(r0 >= r2)));
                r3 = r7;
            }
        }
        r1 = (r3 + 4) - ((int)((((long long)(r3 + 4) * ((int)0x92492493)) & ~0xFFFFFFFFLL) | (unsigned)(((((((int)(((long long)(r3 + 4) * ((int)0x92492493)) >> 32)) + (r3 + 4)) >> 1) >> 1) - ((((r3 + 4) << 1) - ((r3 + 4) << 1)) - ((unsigned)(r3 + 4) >> 31))) * 7)));
        c21 = r1 >= 0;
        ST32(r8 + 24, r1);
        c1026 = c21;
        if (!(c21)) {
            ST32(r8 + 24, (r1 + 7));
            c1026 = 0;
        }
        r0 = r4 + (r7 * 0x00015180);
    } else {
        r0 = -1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072B80(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, c1, c7, c8, c10, c12, c14, c17, c25, c28, c29, c1009, c1017, c1031, c1038;
    FRAME(sp, 12);

    r8 = r5;
    r3 = LD32(r4);
    c1 = (((unsigned)1 >= (unsigned)r3) & ((unsigned)1 >= (unsigned)r3)) == 0;
    r9 = r6;
    c1009 = c1;
    if (!(c1)) {
        r0 = r4;
        c1038 = c1009;
    } else {
        r2 = LD32(r8);
        r0 = r8;
        if ((((unsigned)1 >= (unsigned)r2) & ((unsigned)1 >= (unsigned)r2)) == 0) {
            r0 = r2;
            if (((r3 == 4) & (r3 == 4)) == 0) {
                c10 = ((r0 == 4) & (r0 == 4)) == 0;
                r0 = r8;
                c1038 = c10;
                if (c10) {
                    c12 = ((r2 == 2) & (r2 == 2)) == 0;
                    r0 = r3;
                    c1009 = c12;
                    if (c12) {
                        c14 = ((r0 == 2) & (r0 == 2)) == 0;
                        r0 = r8;
                        c1038 = c14;
                        if (c14) {
                            r7 = LD32(r4 + 8);
                            r3 = LD32(r8 + 8);
                            r6 = LD32(r4 + 12);
                            r2 = r7 - r3;
                            r5 = LD32(r8 + 12);
                            if (!(r2 >= 0)) {
                                r2 = -r2;
                            }
                            c17 = r7 > r3;
                            if (r2 > 31) {
                                if (!(c17)) {
                                    r7 = r3;
                                    r6 = 0;
                                    r2 = LD32(r4 + 4);
                                } else {
                                    r5 = 0;
                                    r2 = LD32(r4 + 4);
                                }
                            } else {
                                c1017 = r3 > r7;
                                if (c17) {
                                    do {
                                        r3 = r3 + 1;
                                        r5 = (1 & r5) | ((int)((unsigned)r5 >> 1));
                                    } while (AGAIN(r7 > r3));
                                    c1017 = r3 > r7;
                                }
                                if (!(c1017)) {
                                    r2 = LD32(r4 + 4);
                                } else {
                                    do {
                                        r7 = r7 + 1;
                                        r6 = (1 & r6) | ((int)((unsigned)r6 >> 1));
                                    } while (AGAIN(r3 > r7));
                                    r2 = LD32(r4 + 4);
                                }
                            }
                            r1 = LD32(r8 + 4);
                            c25 = (r2 & r2) == 0;
                            if (r2 == r1) {
                                r1 = LD32(r4 + 4);
                                ST32(r9 + 4, r1);
                                ST32(r9 + 8, r7);
                                ST32(r9 + 12, (r6 + r5));
                            } else {
                                r2 = r5;
                                if (c25) {
                                    r2 = r6 - r5;
                                } else {
                                    r2 = r2 - r6;
                                }
                                r1 = 1;
                                if (!(r2 > 0)) {
                                    ST32(r9 + 4, r1);
                                    ST32(r9 + 8, r7);
                                    ST32(r9 + 12, (-r2));
                                    c1031 = 0;
                                } else {
                                    ST32(r9 + 4, 0);
                                    ST32(r9 + 8, r7);
                                    ST32(r9 + 12, r2);
                                    c1031 = 1;
                                }
                                r1 = LD32(r9 + 12);
                                r2 = 0x3FFFFFFF;
                                while (!((unsigned)r1 > (unsigned)r2)) {
                                    r1 = LD32(r9 + 12);
                                    c28 = (r1 & r1) == 0;
                                    r1 = r1 + r1;
                                    if (c28) {
                                        break;
                                    } else {
                                        ST32(r9 + 12, r1);
                                        r1 = LD32(r9 + 8);
                                        ST32(r9 + 8, (r1 - 1));
                                        r1 = LD32(r9 + 12);
                                    }
                                    POLL();
                                }
                            }
                            ST32(r9, 3);
                            r2 = LD32(r9 + 12);
                            c29 = (unsigned)r2 > (unsigned)0x7FFFFFFF;
                            r0 = r9;
                            c1038 = c29;
                            if (c29) {
                                ST32(r9 + 12, ((1 & r2) | ((int)((unsigned)r2 >> 1))));
                                r1 = LD32(r9 + 8);
                                ST32(r9 + 8, (r1 + 1));
                                c1038 = r2 & 1;
                            }
                        }
                    } else {
                        r0 = r4;
                        c1038 = c1009;
                    }
                }
            } else {
                c7 = ((r0 == 4) & (r0 == 4)) == 0;
                c1009 = c7;
                if (c7) {
                    r0 = r4;
                    c1038 = c1009;
                } else {
                    r2 = LD32(r4 + 4);
                    r1 = LD32(r8 + 4);
                    c8 = r2 == r1;
                    r0 = r4;
                    c1038 = c8;
                    if (!(c8)) {
                        r0 = 0x06089774;
                    }
                }
            }
        } else {
            c1038 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06072EFC(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, c1, c3, c19, c21, c1004, c1013, c1019, c1020, c1021, c1022;
    FRAME(sp, 4);

    r7 = r4;
    r2 = LD32(r7);
    c1 = (((unsigned)1 >= (unsigned)r2) & ((unsigned)1 >= (unsigned)r2)) == 0;
    r6 = r5;
    c1021 = c1;
    if (!(c1)) {
        r0 = r7;
        c1022 = c1021;
    } else {
        r3 = LD32(r6);
        c3 = (((unsigned)1 >= (unsigned)r3) & ((unsigned)1 >= (unsigned)r3)) == 0;
        r0 = r6;
        c1022 = c3;
        if (c3) {
            r0 = r2;
            c1004 = r2 == r3;
            if (!(((r0 == 4) & (r0 == 4)) == 0)) {
                r0 = r7;
                c1022 = c1004;
                if (c1004) {
                    r0 = 0x06089774;
                }
            } else {
                c1004 = r2 == r3;
                if (((r0 == 2) & (r0 == 2)) == 0) {
                    r1 = LD32(r7 + 4);
                    r2 = LD32(r6 + 4);
                    ST32(r7 + 4, (r1 ^ r2));
                    r2 = LD32(r6);
                    r0 = r2;
                    r1 = 0;
                    if (((r0 == 4) & (r0 == 4)) == 0) {
                        r1 = 4;
                        if (((r0 == 2) & (r0 == 2)) == 0) {
                            r2 = LD32(r7 + 8);
                            r1 = LD32(r6 + 8);
                            r3 = LD32(r7 + 12);
                            r1 = r2 - r1;
                            ST32(r7 + 8, r1);
                            r5 = LD32(r6 + 12);
                            if (!((unsigned)r3 >= (unsigned)r5)) {
                                r3 = r3 + r3;
                                ST32(r7 + 8, (r1 - 1));
                            }
                            r1 = 0x40000000;
                            r2 = 0;
                            c1013 = (unsigned)r3 >= (unsigned)r5;
                            do {
                                if (c1013) {
                                    r2 = r2 | r1;
                                    r3 = r3 - r5;
                                }
                                r1 = (int)((unsigned)r1 >> 1);
                                r3 = r3 + r3;
                                c1013 = (unsigned)r3 >= (unsigned)r5;
                            } while (AGAIN(!((r1 & r1) == 0)));
                            c19 = (r2 & 127) == 64;
                            c1020 = c19;
                            if (c19) {
                                c21 = (r3 & r3) == 0;
                                c1019 = c21;
                                if (!(((128 & r2) & (128 & r2)) == 0)) {
                                    r2 = r2 + 64;
                                    c1020 = c1019;
                                } else {
                                    c1020 = c21;
                                    c1019 = c21;
                                    if (!(c21)) {
                                        r2 = r2 + 64;
                                        c1020 = c1019;
                                    }
                                }
                            }
                            ST32(r7 + 12, r2);
                            c1021 = c1020;
                            r0 = r7;
                            c1022 = c1021;
                        } else {
                            ST32(r7, r1);
                            r0 = r6;
                            c1022 = 0;
                        }
                    } else {
                        ST32(r7 + 12, r1);
                        ST32(r7 + 8, r1);
                        c1021 = 0;
                        r0 = r7;
                        c1022 = c1021;
                    }
                } else {
                    r0 = r7;
                    c1022 = c1004;
                    if (c1004) {
                        r0 = 0x06089774;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073018(int r4, int r5)
{
    int r0, r1, r2, r3, r7, c5, c17, c26, c30, c32, c1008, c1024, c1026;
    FRAME(sp, 4);

    r2 = LD32(r4);
    r3 = 1;
    if (!((((unsigned)1 >= (unsigned)r2) & ((unsigned)1 >= (unsigned)r2)) == 0)) {
        r0 = r3;
    } else {
        r7 = LD32(r5);
        r0 = r2;
        if ((((unsigned)1 >= (unsigned)r7) & ((unsigned)1 >= (unsigned)r7)) == 0) {
            c5 = ((r0 == 4) & (r0 == 4)) == 0;
            r0 = r7;
            if (c5) {
                r2 = LD32(r4);
                if (((r2 == 4) & (r2 == 4)) == 0) {
                    r3 = LD32(r5);
                    if (((r3 == 4) & (r3 == 4)) == 0) {
                        r0 = r3;
                        if (((r2 == 2) & (r2 == 2)) == 0) {
                            r0 = LD32(r4);
                            if (((r0 == 2) & (r0 == 2)) == 0) {
                                r0 = LD32(r5);
                                if (!(((r0 == 2) & (r0 == 2)) == 0)) {
                                    POLL();
                                    r1 = LD32(r4 + 4);
                                    c1008 = (r1 & r1) == 0;
                                    r1 = 1;
                                    c1026 = c1008;
                                    if (!(c1008)) {
                                        r1 = -1;
                                        c1026 = 0;
                                    }
                                    r0 = r1;
                                } else {
                                    r2 = LD32(r4 + 4);
                                    r1 = LD32(r5 + 4);
                                    c1008 = (r2 & r2) == 0;
                                    if (!(r2 == r1)) {
                                        POLL();
                                        r1 = 1;
                                        c1026 = c1008;
                                        if (!(c1008)) {
                                            r1 = -1;
                                            c1026 = 0;
                                        }
                                        r0 = r1;
                                    } else {
                                        r3 = LD32(r4 + 8);
                                        r1 = LD32(r5 + 8);
                                        c26 = r3 >= r1;
                                        if (!(r3 > r1)) {
                                            c1024 = (r2 & r2) == 0;
                                            if (!(c26)) {
                                                r1 = -1;
                                                c1026 = c1024;
                                                if (!(c1024)) {
                                                    r1 = 1;
                                                    c1026 = 0;
                                                }
                                                r0 = r1;
                                            } else {
                                                r4 = LD32(r4 + 12);
                                                r5 = LD32(r5 + 12);
                                                c30 = (unsigned)r4 >= (unsigned)r5;
                                                if (!((unsigned)r4 > (unsigned)r5)) {
                                                    c32 = (r2 & r2) == 0;
                                                    c1024 = c32;
                                                    if (c30) {
                                                        r0 = 0;
                                                    } else {
                                                        r1 = -1;
                                                        c1026 = c1024;
                                                        if (!(c1024)) {
                                                            r1 = 1;
                                                            c1026 = 0;
                                                        }
                                                        r0 = r1;
                                                    }
                                                } else {
                                                    c1008 = (r2 & r2) == 0;
                                                    POLL();
                                                    r1 = 1;
                                                    c1026 = c1008;
                                                    if (!(c1008)) {
                                                        r1 = -1;
                                                        c1026 = 0;
                                                    }
                                                    r0 = r1;
                                                }
                                            }
                                        } else {
                                            c1008 = (r2 & r2) == 0;
                                            POLL();
                                            r1 = 1;
                                            c1026 = c1008;
                                            if (!(c1008)) {
                                                r1 = -1;
                                                c1026 = 0;
                                            }
                                            r0 = r1;
                                        }
                                    }
                                }
                            } else {
                                r1 = LD32(r5 + 4);
                                c1024 = (r1 & r1) == 0;
                                r1 = -1;
                                c1026 = c1024;
                                if (!(c1024)) {
                                    r1 = 1;
                                    c1026 = 0;
                                }
                                r0 = r1;
                            }
                        } else {
                            c17 = ((r0 == 2) & (r0 == 2)) == 0;
                            r0 = 0;
                            if (c17) {
                                r0 = LD32(r4);
                                if (((r0 == 2) & (r0 == 2)) == 0) {
                                    r0 = LD32(r5);
                                    if (!(((r0 == 2) & (r0 == 2)) == 0)) {
                                        POLL();
                                        r1 = LD32(r4 + 4);
                                        c1008 = (r1 & r1) == 0;
                                        r1 = 1;
                                        c1026 = c1008;
                                        if (!(c1008)) {
                                            r1 = -1;
                                            c1026 = 0;
                                        }
                                        r0 = r1;
                                    } else {
                                        r2 = LD32(r4 + 4);
                                        r1 = LD32(r5 + 4);
                                        c1008 = (r2 & r2) == 0;
                                        if (!(r2 == r1)) {
                                            POLL();
                                            r1 = 1;
                                            c1026 = c1008;
                                            if (!(c1008)) {
                                                r1 = -1;
                                                c1026 = 0;
                                            }
                                            r0 = r1;
                                        } else {
                                            r3 = LD32(r4 + 8);
                                            r1 = LD32(r5 + 8);
                                            c26 = r3 >= r1;
                                            if (!(r3 > r1)) {
                                                c1024 = (r2 & r2) == 0;
                                                if (!(c26)) {
                                                    r1 = -1;
                                                    c1026 = c1024;
                                                    if (!(c1024)) {
                                                        r1 = 1;
                                                        c1026 = 0;
                                                    }
                                                    r0 = r1;
                                                } else {
                                                    r4 = LD32(r4 + 12);
                                                    r5 = LD32(r5 + 12);
                                                    c30 = (unsigned)r4 >= (unsigned)r5;
                                                    if (!((unsigned)r4 > (unsigned)r5)) {
                                                        c32 = (r2 & r2) == 0;
                                                        c1024 = c32;
                                                        if (c30) {
                                                            r0 = 0;
                                                        } else {
                                                            r1 = -1;
                                                            c1026 = c1024;
                                                            if (!(c1024)) {
                                                                r1 = 1;
                                                                c1026 = 0;
                                                            }
                                                            r0 = r1;
                                                        }
                                                    } else {
                                                        c1008 = (r2 & r2) == 0;
                                                        POLL();
                                                        r1 = 1;
                                                        c1026 = c1008;
                                                        if (!(c1008)) {
                                                            r1 = -1;
                                                            c1026 = 0;
                                                        }
                                                        r0 = r1;
                                                    }
                                                }
                                            } else {
                                                c1008 = (r2 & r2) == 0;
                                                POLL();
                                                r1 = 1;
                                                c1026 = c1008;
                                                if (!(c1008)) {
                                                    r1 = -1;
                                                    c1026 = 0;
                                                }
                                                r0 = r1;
                                            }
                                        }
                                    }
                                } else {
                                    r1 = LD32(r5 + 4);
                                    c1024 = (r1 & r1) == 0;
                                    r1 = -1;
                                    c1026 = c1024;
                                    if (!(c1024)) {
                                        r1 = 1;
                                        c1026 = 0;
                                    }
                                    r0 = r1;
                                }
                            }
                        }
                    } else {
                        r1 = LD32(r5 + 4);
                        c1024 = (r1 & r1) == 0;
                        r1 = -1;
                        c1026 = c1024;
                        if (!(c1024)) {
                            r1 = 1;
                            c1026 = 0;
                        }
                        r0 = r1;
                    }
                } else {
                    r1 = LD32(r4 + 4);
                    c1008 = (r1 & r1) == 0;
                    r1 = 1;
                    c1026 = c1008;
                    if (!(c1008)) {
                        r1 = -1;
                        c1026 = 0;
                    }
                    r0 = r1;
                }
            } else {
                if (((r0 == 4) & (r0 == 4)) == 0) {
                    r2 = LD32(r4);
                    if (((r2 == 4) & (r2 == 4)) == 0) {
                        r3 = LD32(r5);
                        if (((r3 == 4) & (r3 == 4)) == 0) {
                            r0 = r3;
                            if (((r2 == 2) & (r2 == 2)) == 0) {
                                r0 = LD32(r4);
                                if (((r0 == 2) & (r0 == 2)) == 0) {
                                    r0 = LD32(r5);
                                    if (!(((r0 == 2) & (r0 == 2)) == 0)) {
                                        POLL();
                                        r1 = LD32(r4 + 4);
                                        c1008 = (r1 & r1) == 0;
                                        r1 = 1;
                                        c1026 = c1008;
                                        if (!(c1008)) {
                                            r1 = -1;
                                            c1026 = 0;
                                        }
                                        r0 = r1;
                                    } else {
                                        r2 = LD32(r4 + 4);
                                        r1 = LD32(r5 + 4);
                                        c1008 = (r2 & r2) == 0;
                                        if (!(r2 == r1)) {
                                            POLL();
                                            r1 = 1;
                                            c1026 = c1008;
                                            if (!(c1008)) {
                                                r1 = -1;
                                                c1026 = 0;
                                            }
                                            r0 = r1;
                                        } else {
                                            r3 = LD32(r4 + 8);
                                            r1 = LD32(r5 + 8);
                                            c26 = r3 >= r1;
                                            if (!(r3 > r1)) {
                                                c1024 = (r2 & r2) == 0;
                                                if (!(c26)) {
                                                    r1 = -1;
                                                    c1026 = c1024;
                                                    if (!(c1024)) {
                                                        r1 = 1;
                                                        c1026 = 0;
                                                    }
                                                    r0 = r1;
                                                } else {
                                                    r4 = LD32(r4 + 12);
                                                    r5 = LD32(r5 + 12);
                                                    c30 = (unsigned)r4 >= (unsigned)r5;
                                                    if (!((unsigned)r4 > (unsigned)r5)) {
                                                        c32 = (r2 & r2) == 0;
                                                        c1024 = c32;
                                                        if (c30) {
                                                            r0 = 0;
                                                        } else {
                                                            r1 = -1;
                                                            c1026 = c1024;
                                                            if (!(c1024)) {
                                                                r1 = 1;
                                                                c1026 = 0;
                                                            }
                                                            r0 = r1;
                                                        }
                                                    } else {
                                                        c1008 = (r2 & r2) == 0;
                                                        POLL();
                                                        r1 = 1;
                                                        c1026 = c1008;
                                                        if (!(c1008)) {
                                                            r1 = -1;
                                                            c1026 = 0;
                                                        }
                                                        r0 = r1;
                                                    }
                                                }
                                            } else {
                                                c1008 = (r2 & r2) == 0;
                                                POLL();
                                                r1 = 1;
                                                c1026 = c1008;
                                                if (!(c1008)) {
                                                    r1 = -1;
                                                    c1026 = 0;
                                                }
                                                r0 = r1;
                                            }
                                        }
                                    }
                                } else {
                                    r1 = LD32(r5 + 4);
                                    c1024 = (r1 & r1) == 0;
                                    r1 = -1;
                                    c1026 = c1024;
                                    if (!(c1024)) {
                                        r1 = 1;
                                        c1026 = 0;
                                    }
                                    r0 = r1;
                                }
                            } else {
                                c17 = ((r0 == 2) & (r0 == 2)) == 0;
                                r0 = 0;
                                if (c17) {
                                    r0 = LD32(r4);
                                    if (((r0 == 2) & (r0 == 2)) == 0) {
                                        r0 = LD32(r5);
                                        if (!(((r0 == 2) & (r0 == 2)) == 0)) {
                                            POLL();
                                            r1 = LD32(r4 + 4);
                                            c1008 = (r1 & r1) == 0;
                                            r1 = 1;
                                            c1026 = c1008;
                                            if (!(c1008)) {
                                                r1 = -1;
                                                c1026 = 0;
                                            }
                                            r0 = r1;
                                        } else {
                                            r2 = LD32(r4 + 4);
                                            r1 = LD32(r5 + 4);
                                            c1008 = (r2 & r2) == 0;
                                            if (!(r2 == r1)) {
                                                POLL();
                                                r1 = 1;
                                                c1026 = c1008;
                                                if (!(c1008)) {
                                                    r1 = -1;
                                                    c1026 = 0;
                                                }
                                                r0 = r1;
                                            } else {
                                                r3 = LD32(r4 + 8);
                                                r1 = LD32(r5 + 8);
                                                c26 = r3 >= r1;
                                                if (!(r3 > r1)) {
                                                    c1024 = (r2 & r2) == 0;
                                                    if (!(c26)) {
                                                        r1 = -1;
                                                        c1026 = c1024;
                                                        if (!(c1024)) {
                                                            r1 = 1;
                                                            c1026 = 0;
                                                        }
                                                        r0 = r1;
                                                    } else {
                                                        r4 = LD32(r4 + 12);
                                                        r5 = LD32(r5 + 12);
                                                        c30 = (unsigned)r4 >= (unsigned)r5;
                                                        if (!((unsigned)r4 > (unsigned)r5)) {
                                                            c32 = (r2 & r2) == 0;
                                                            c1024 = c32;
                                                            if (c30) {
                                                                r0 = 0;
                                                            } else {
                                                                r1 = -1;
                                                                c1026 = c1024;
                                                                if (!(c1024)) {
                                                                    r1 = 1;
                                                                    c1026 = 0;
                                                                }
                                                                r0 = r1;
                                                            }
                                                        } else {
                                                            c1008 = (r2 & r2) == 0;
                                                            POLL();
                                                            r1 = 1;
                                                            c1026 = c1008;
                                                            if (!(c1008)) {
                                                                r1 = -1;
                                                                c1026 = 0;
                                                            }
                                                            r0 = r1;
                                                        }
                                                    }
                                                } else {
                                                    c1008 = (r2 & r2) == 0;
                                                    POLL();
                                                    r1 = 1;
                                                    c1026 = c1008;
                                                    if (!(c1008)) {
                                                        r1 = -1;
                                                        c1026 = 0;
                                                    }
                                                    r0 = r1;
                                                }
                                            }
                                        }
                                    } else {
                                        r1 = LD32(r5 + 4);
                                        c1024 = (r1 & r1) == 0;
                                        r1 = -1;
                                        c1026 = c1024;
                                        if (!(c1024)) {
                                            r1 = 1;
                                            c1026 = 0;
                                        }
                                        r0 = r1;
                                    }
                                }
                            }
                        } else {
                            r1 = LD32(r5 + 4);
                            c1024 = (r1 & r1) == 0;
                            r1 = -1;
                            c1026 = c1024;
                            if (!(c1024)) {
                                r1 = 1;
                                c1026 = 0;
                            }
                            r0 = r1;
                        }
                    } else {
                        r1 = LD32(r4 + 4);
                        c1008 = (r1 & r1) == 0;
                        r1 = 1;
                        c1026 = c1008;
                        if (!(c1008)) {
                            r1 = -1;
                            c1026 = 0;
                        }
                        r0 = r1;
                    }
                } else {
                    r2 = LD32(r5 + 4);
                    r1 = LD32(r4 + 4);
                    r0 = r2 - r1;
                }
            }
        } else {
            r0 = r3;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607403C(int r4, int r5)
{
    int r0, r1, r2, r3, r7, c5, c17, c26, c30, c33, c1008, c1028, c1030, c1031;
    FRAME(sp, 4);

    r2 = LD32(r4);
    r3 = 1;
    if (!((((unsigned)1 >= (unsigned)r2) & ((unsigned)1 >= (unsigned)r2)) == 0)) {
        r0 = r3;
        c1031 = 0;
    } else {
        r7 = LD32(r5);
        r0 = r2;
        if ((((unsigned)1 >= (unsigned)r7) & ((unsigned)1 >= (unsigned)r7)) == 0) {
            c5 = ((r0 == 4) & (r0 == 4)) == 0;
            r0 = r7;
            if (c5) {
                r2 = LD32(r4);
                if (((r2 == 4) & (r2 == 4)) == 0) {
                    r3 = LD32(r5);
                    if (((r3 == 4) & (r3 == 4)) == 0) {
                        r0 = r3;
                        if (((r2 == 2) & (r2 == 2)) == 0) {
                            r0 = LD32(r4);
                            if (((r0 == 2) & (r0 == 2)) == 0) {
                                r0 = LD32(r5);
                                if (!(((r0 == 2) & (r0 == 2)) == 0)) {
                                    POLL();
                                    r1 = LD32(r4 + 4);
                                    c1008 = (r1 & r1) == 0;
                                    r1 = 1;
                                    c1030 = c1008;
                                    if (!(c1008)) {
                                        r1 = -1;
                                        c1030 = 0;
                                    }
                                    r0 = r1;
                                    c1031 = c1030;
                                } else {
                                    r2 = LD32(r4 + 4);
                                    r1 = LD32(r5 + 4);
                                    c1008 = (r2 & r2) == 0;
                                    if (!(r2 == r1)) {
                                        POLL();
                                        r1 = 1;
                                        c1030 = c1008;
                                        if (!(c1008)) {
                                            r1 = -1;
                                            c1030 = 0;
                                        }
                                        r0 = r1;
                                        c1031 = c1030;
                                    } else {
                                        r3 = LD32(r4 + 8);
                                        r1 = LD32(r5 + 8);
                                        c26 = r3 >= r1;
                                        if (!(r3 > r1)) {
                                            c1028 = (r2 & r2) == 0;
                                            if (!(c26)) {
                                                r1 = -1;
                                                c1030 = c1028;
                                                if (!(c1028)) {
                                                    r1 = 1;
                                                    c1030 = 0;
                                                }
                                                r0 = r1;
                                                c1031 = c1030;
                                            } else {
                                                r2 = LD32(r4 + 12);
                                                r1 = LD32(r5 + 12);
                                                c30 = r2 == r1;
                                                if ((unsigned)r2 > (unsigned)r1) {
                                                    POLL();
                                                    r1 = LD32(r4 + 4);
                                                    c1008 = (r1 & r1) == 0;
                                                    r1 = 1;
                                                    c1030 = c1008;
                                                    if (!(c1008)) {
                                                        r1 = -1;
                                                        c1030 = 0;
                                                    }
                                                    r0 = r1;
                                                    c1031 = c1030;
                                                } else {
                                                    if (!(c30)) {
                                                        r2 = LD32(r5 + 12);
                                                        r1 = LD32(r4 + 12);
                                                        c33 = r2 == r1;
                                                        if ((unsigned)r2 > (unsigned)r1) {
                                                            r1 = LD32(r4 + 4);
                                                            c1028 = (r1 & r1) == 0;
                                                            r1 = -1;
                                                            c1030 = c1028;
                                                            if (!(c1028)) {
                                                                r1 = 1;
                                                                c1030 = 0;
                                                            }
                                                            r0 = r1;
                                                            c1031 = c1030;
                                                        } else {
                                                            r0 = 0;
                                                            c1031 = c33;
                                                            if (c33) {
                                                                r2 = LD32(r5 + 16);
                                                                r1 = LD32(r4 + 16);
                                                                if ((unsigned)r2 > (unsigned)r1) {
                                                                    r1 = LD32(r4 + 4);
                                                                    c1028 = (r1 & r1) == 0;
                                                                    r1 = -1;
                                                                    c1030 = c1028;
                                                                    if (!(c1028)) {
                                                                        r1 = 1;
                                                                        c1030 = 0;
                                                                    }
                                                                    r0 = r1;
                                                                    c1031 = c1030;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r2 = LD32(r4 + 16);
                                                        r1 = LD32(r5 + 16);
                                                        if ((unsigned)r2 > (unsigned)r1) {
                                                            POLL();
                                                            r1 = LD32(r4 + 4);
                                                            c1008 = (r1 & r1) == 0;
                                                            r1 = 1;
                                                            c1030 = c1008;
                                                            if (!(c1008)) {
                                                                r1 = -1;
                                                                c1030 = 0;
                                                            }
                                                            r0 = r1;
                                                            c1031 = c1030;
                                                        } else {
                                                            r2 = LD32(r5 + 12);
                                                            r1 = LD32(r4 + 12);
                                                            c33 = r2 == r1;
                                                            if ((unsigned)r2 > (unsigned)r1) {
                                                                r1 = LD32(r4 + 4);
                                                                c1028 = (r1 & r1) == 0;
                                                                r1 = -1;
                                                                c1030 = c1028;
                                                                if (!(c1028)) {
                                                                    r1 = 1;
                                                                    c1030 = 0;
                                                                }
                                                                r0 = r1;
                                                                c1031 = c1030;
                                                            } else {
                                                                r0 = 0;
                                                                c1031 = c33;
                                                                if (c33) {
                                                                    r2 = LD32(r5 + 16);
                                                                    r1 = LD32(r4 + 16);
                                                                    if ((unsigned)r2 > (unsigned)r1) {
                                                                        r1 = LD32(r4 + 4);
                                                                        c1028 = (r1 & r1) == 0;
                                                                        r1 = -1;
                                                                        c1030 = c1028;
                                                                        if (!(c1028)) {
                                                                            r1 = 1;
                                                                            c1030 = 0;
                                                                        }
                                                                        r0 = r1;
                                                                        c1031 = c1030;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            c1008 = (r2 & r2) == 0;
                                            POLL();
                                            r1 = 1;
                                            c1030 = c1008;
                                            if (!(c1008)) {
                                                r1 = -1;
                                                c1030 = 0;
                                            }
                                            r0 = r1;
                                            c1031 = c1030;
                                        }
                                    }
                                }
                            } else {
                                r1 = LD32(r5 + 4);
                                c1028 = (r1 & r1) == 0;
                                r1 = -1;
                                c1030 = c1028;
                                if (!(c1028)) {
                                    r1 = 1;
                                    c1030 = 0;
                                }
                                r0 = r1;
                                c1031 = c1030;
                            }
                        } else {
                            c17 = ((r0 == 2) & (r0 == 2)) == 0;
                            r0 = 0;
                            c1031 = c17;
                            if (c17) {
                                r0 = LD32(r4);
                                if (((r0 == 2) & (r0 == 2)) == 0) {
                                    r0 = LD32(r5);
                                    if (!(((r0 == 2) & (r0 == 2)) == 0)) {
                                        POLL();
                                        r1 = LD32(r4 + 4);
                                        c1008 = (r1 & r1) == 0;
                                        r1 = 1;
                                        c1030 = c1008;
                                        if (!(c1008)) {
                                            r1 = -1;
                                            c1030 = 0;
                                        }
                                        r0 = r1;
                                        c1031 = c1030;
                                    } else {
                                        r2 = LD32(r4 + 4);
                                        r1 = LD32(r5 + 4);
                                        c1008 = (r2 & r2) == 0;
                                        if (!(r2 == r1)) {
                                            POLL();
                                            r1 = 1;
                                            c1030 = c1008;
                                            if (!(c1008)) {
                                                r1 = -1;
                                                c1030 = 0;
                                            }
                                            r0 = r1;
                                            c1031 = c1030;
                                        } else {
                                            r3 = LD32(r4 + 8);
                                            r1 = LD32(r5 + 8);
                                            c26 = r3 >= r1;
                                            if (!(r3 > r1)) {
                                                c1028 = (r2 & r2) == 0;
                                                if (!(c26)) {
                                                    r1 = -1;
                                                    c1030 = c1028;
                                                    if (!(c1028)) {
                                                        r1 = 1;
                                                        c1030 = 0;
                                                    }
                                                    r0 = r1;
                                                    c1031 = c1030;
                                                } else {
                                                    r2 = LD32(r4 + 12);
                                                    r1 = LD32(r5 + 12);
                                                    c30 = r2 == r1;
                                                    if ((unsigned)r2 > (unsigned)r1) {
                                                        POLL();
                                                        r1 = LD32(r4 + 4);
                                                        c1008 = (r1 & r1) == 0;
                                                        r1 = 1;
                                                        c1030 = c1008;
                                                        if (!(c1008)) {
                                                            r1 = -1;
                                                            c1030 = 0;
                                                        }
                                                        r0 = r1;
                                                        c1031 = c1030;
                                                    } else {
                                                        if (!(c30)) {
                                                            r2 = LD32(r5 + 12);
                                                            r1 = LD32(r4 + 12);
                                                            c33 = r2 == r1;
                                                            if ((unsigned)r2 > (unsigned)r1) {
                                                                r1 = LD32(r4 + 4);
                                                                c1028 = (r1 & r1) == 0;
                                                                r1 = -1;
                                                                c1030 = c1028;
                                                                if (!(c1028)) {
                                                                    r1 = 1;
                                                                    c1030 = 0;
                                                                }
                                                                r0 = r1;
                                                                c1031 = c1030;
                                                            } else {
                                                                r0 = 0;
                                                                c1031 = c33;
                                                                if (c33) {
                                                                    r2 = LD32(r5 + 16);
                                                                    r1 = LD32(r4 + 16);
                                                                    if ((unsigned)r2 > (unsigned)r1) {
                                                                        r1 = LD32(r4 + 4);
                                                                        c1028 = (r1 & r1) == 0;
                                                                        r1 = -1;
                                                                        c1030 = c1028;
                                                                        if (!(c1028)) {
                                                                            r1 = 1;
                                                                            c1030 = 0;
                                                                        }
                                                                        r0 = r1;
                                                                        c1031 = c1030;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r2 = LD32(r4 + 16);
                                                            r1 = LD32(r5 + 16);
                                                            if ((unsigned)r2 > (unsigned)r1) {
                                                                POLL();
                                                                r1 = LD32(r4 + 4);
                                                                c1008 = (r1 & r1) == 0;
                                                                r1 = 1;
                                                                c1030 = c1008;
                                                                if (!(c1008)) {
                                                                    r1 = -1;
                                                                    c1030 = 0;
                                                                }
                                                                r0 = r1;
                                                                c1031 = c1030;
                                                            } else {
                                                                r2 = LD32(r5 + 12);
                                                                r1 = LD32(r4 + 12);
                                                                c33 = r2 == r1;
                                                                if ((unsigned)r2 > (unsigned)r1) {
                                                                    r1 = LD32(r4 + 4);
                                                                    c1028 = (r1 & r1) == 0;
                                                                    r1 = -1;
                                                                    c1030 = c1028;
                                                                    if (!(c1028)) {
                                                                        r1 = 1;
                                                                        c1030 = 0;
                                                                    }
                                                                    r0 = r1;
                                                                    c1031 = c1030;
                                                                } else {
                                                                    r0 = 0;
                                                                    c1031 = c33;
                                                                    if (c33) {
                                                                        r2 = LD32(r5 + 16);
                                                                        r1 = LD32(r4 + 16);
                                                                        if ((unsigned)r2 > (unsigned)r1) {
                                                                            r1 = LD32(r4 + 4);
                                                                            c1028 = (r1 & r1) == 0;
                                                                            r1 = -1;
                                                                            c1030 = c1028;
                                                                            if (!(c1028)) {
                                                                                r1 = 1;
                                                                                c1030 = 0;
                                                                            }
                                                                            r0 = r1;
                                                                            c1031 = c1030;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                c1008 = (r2 & r2) == 0;
                                                POLL();
                                                r1 = 1;
                                                c1030 = c1008;
                                                if (!(c1008)) {
                                                    r1 = -1;
                                                    c1030 = 0;
                                                }
                                                r0 = r1;
                                                c1031 = c1030;
                                            }
                                        }
                                    }
                                } else {
                                    r1 = LD32(r5 + 4);
                                    c1028 = (r1 & r1) == 0;
                                    r1 = -1;
                                    c1030 = c1028;
                                    if (!(c1028)) {
                                        r1 = 1;
                                        c1030 = 0;
                                    }
                                    r0 = r1;
                                    c1031 = c1030;
                                }
                            }
                        }
                    } else {
                        r1 = LD32(r5 + 4);
                        c1028 = (r1 & r1) == 0;
                        r1 = -1;
                        c1030 = c1028;
                        if (!(c1028)) {
                            r1 = 1;
                            c1030 = 0;
                        }
                        r0 = r1;
                        c1031 = c1030;
                    }
                } else {
                    r1 = LD32(r4 + 4);
                    c1008 = (r1 & r1) == 0;
                    r1 = 1;
                    c1030 = c1008;
                    if (!(c1008)) {
                        r1 = -1;
                        c1030 = 0;
                    }
                    r0 = r1;
                    c1031 = c1030;
                }
            } else {
                if (((r0 == 4) & (r0 == 4)) == 0) {
                    r2 = LD32(r4);
                    if (((r2 == 4) & (r2 == 4)) == 0) {
                        r3 = LD32(r5);
                        if (((r3 == 4) & (r3 == 4)) == 0) {
                            r0 = r3;
                            if (((r2 == 2) & (r2 == 2)) == 0) {
                                r0 = LD32(r4);
                                if (((r0 == 2) & (r0 == 2)) == 0) {
                                    r0 = LD32(r5);
                                    if (!(((r0 == 2) & (r0 == 2)) == 0)) {
                                        POLL();
                                        r1 = LD32(r4 + 4);
                                        c1008 = (r1 & r1) == 0;
                                        r1 = 1;
                                        c1030 = c1008;
                                        if (!(c1008)) {
                                            r1 = -1;
                                            c1030 = 0;
                                        }
                                        r0 = r1;
                                        c1031 = c1030;
                                    } else {
                                        r2 = LD32(r4 + 4);
                                        r1 = LD32(r5 + 4);
                                        c1008 = (r2 & r2) == 0;
                                        if (!(r2 == r1)) {
                                            POLL();
                                            r1 = 1;
                                            c1030 = c1008;
                                            if (!(c1008)) {
                                                r1 = -1;
                                                c1030 = 0;
                                            }
                                            r0 = r1;
                                            c1031 = c1030;
                                        } else {
                                            r3 = LD32(r4 + 8);
                                            r1 = LD32(r5 + 8);
                                            c26 = r3 >= r1;
                                            if (!(r3 > r1)) {
                                                c1028 = (r2 & r2) == 0;
                                                if (!(c26)) {
                                                    r1 = -1;
                                                    c1030 = c1028;
                                                    if (!(c1028)) {
                                                        r1 = 1;
                                                        c1030 = 0;
                                                    }
                                                    r0 = r1;
                                                    c1031 = c1030;
                                                } else {
                                                    r2 = LD32(r4 + 12);
                                                    r1 = LD32(r5 + 12);
                                                    c30 = r2 == r1;
                                                    if ((unsigned)r2 > (unsigned)r1) {
                                                        POLL();
                                                        r1 = LD32(r4 + 4);
                                                        c1008 = (r1 & r1) == 0;
                                                        r1 = 1;
                                                        c1030 = c1008;
                                                        if (!(c1008)) {
                                                            r1 = -1;
                                                            c1030 = 0;
                                                        }
                                                        r0 = r1;
                                                        c1031 = c1030;
                                                    } else {
                                                        if (!(c30)) {
                                                            r2 = LD32(r5 + 12);
                                                            r1 = LD32(r4 + 12);
                                                            c33 = r2 == r1;
                                                            if ((unsigned)r2 > (unsigned)r1) {
                                                                r1 = LD32(r4 + 4);
                                                                c1028 = (r1 & r1) == 0;
                                                                r1 = -1;
                                                                c1030 = c1028;
                                                                if (!(c1028)) {
                                                                    r1 = 1;
                                                                    c1030 = 0;
                                                                }
                                                                r0 = r1;
                                                                c1031 = c1030;
                                                            } else {
                                                                r0 = 0;
                                                                c1031 = c33;
                                                                if (c33) {
                                                                    r2 = LD32(r5 + 16);
                                                                    r1 = LD32(r4 + 16);
                                                                    if ((unsigned)r2 > (unsigned)r1) {
                                                                        r1 = LD32(r4 + 4);
                                                                        c1028 = (r1 & r1) == 0;
                                                                        r1 = -1;
                                                                        c1030 = c1028;
                                                                        if (!(c1028)) {
                                                                            r1 = 1;
                                                                            c1030 = 0;
                                                                        }
                                                                        r0 = r1;
                                                                        c1031 = c1030;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r2 = LD32(r4 + 16);
                                                            r1 = LD32(r5 + 16);
                                                            if ((unsigned)r2 > (unsigned)r1) {
                                                                POLL();
                                                                r1 = LD32(r4 + 4);
                                                                c1008 = (r1 & r1) == 0;
                                                                r1 = 1;
                                                                c1030 = c1008;
                                                                if (!(c1008)) {
                                                                    r1 = -1;
                                                                    c1030 = 0;
                                                                }
                                                                r0 = r1;
                                                                c1031 = c1030;
                                                            } else {
                                                                r2 = LD32(r5 + 12);
                                                                r1 = LD32(r4 + 12);
                                                                c33 = r2 == r1;
                                                                if ((unsigned)r2 > (unsigned)r1) {
                                                                    r1 = LD32(r4 + 4);
                                                                    c1028 = (r1 & r1) == 0;
                                                                    r1 = -1;
                                                                    c1030 = c1028;
                                                                    if (!(c1028)) {
                                                                        r1 = 1;
                                                                        c1030 = 0;
                                                                    }
                                                                    r0 = r1;
                                                                    c1031 = c1030;
                                                                } else {
                                                                    r0 = 0;
                                                                    c1031 = c33;
                                                                    if (c33) {
                                                                        r2 = LD32(r5 + 16);
                                                                        r1 = LD32(r4 + 16);
                                                                        if ((unsigned)r2 > (unsigned)r1) {
                                                                            r1 = LD32(r4 + 4);
                                                                            c1028 = (r1 & r1) == 0;
                                                                            r1 = -1;
                                                                            c1030 = c1028;
                                                                            if (!(c1028)) {
                                                                                r1 = 1;
                                                                                c1030 = 0;
                                                                            }
                                                                            r0 = r1;
                                                                            c1031 = c1030;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                c1008 = (r2 & r2) == 0;
                                                POLL();
                                                r1 = 1;
                                                c1030 = c1008;
                                                if (!(c1008)) {
                                                    r1 = -1;
                                                    c1030 = 0;
                                                }
                                                r0 = r1;
                                                c1031 = c1030;
                                            }
                                        }
                                    }
                                } else {
                                    r1 = LD32(r5 + 4);
                                    c1028 = (r1 & r1) == 0;
                                    r1 = -1;
                                    c1030 = c1028;
                                    if (!(c1028)) {
                                        r1 = 1;
                                        c1030 = 0;
                                    }
                                    r0 = r1;
                                    c1031 = c1030;
                                }
                            } else {
                                c17 = ((r0 == 2) & (r0 == 2)) == 0;
                                r0 = 0;
                                c1031 = c17;
                                if (c17) {
                                    r0 = LD32(r4);
                                    if (((r0 == 2) & (r0 == 2)) == 0) {
                                        r0 = LD32(r5);
                                        if (!(((r0 == 2) & (r0 == 2)) == 0)) {
                                            POLL();
                                            r1 = LD32(r4 + 4);
                                            c1008 = (r1 & r1) == 0;
                                            r1 = 1;
                                            c1030 = c1008;
                                            if (!(c1008)) {
                                                r1 = -1;
                                                c1030 = 0;
                                            }
                                            r0 = r1;
                                            c1031 = c1030;
                                        } else {
                                            r2 = LD32(r4 + 4);
                                            r1 = LD32(r5 + 4);
                                            c1008 = (r2 & r2) == 0;
                                            if (!(r2 == r1)) {
                                                POLL();
                                                r1 = 1;
                                                c1030 = c1008;
                                                if (!(c1008)) {
                                                    r1 = -1;
                                                    c1030 = 0;
                                                }
                                                r0 = r1;
                                                c1031 = c1030;
                                            } else {
                                                r3 = LD32(r4 + 8);
                                                r1 = LD32(r5 + 8);
                                                c26 = r3 >= r1;
                                                if (!(r3 > r1)) {
                                                    c1028 = (r2 & r2) == 0;
                                                    if (!(c26)) {
                                                        r1 = -1;
                                                        c1030 = c1028;
                                                        if (!(c1028)) {
                                                            r1 = 1;
                                                            c1030 = 0;
                                                        }
                                                        r0 = r1;
                                                        c1031 = c1030;
                                                    } else {
                                                        r2 = LD32(r4 + 12);
                                                        r1 = LD32(r5 + 12);
                                                        c30 = r2 == r1;
                                                        if ((unsigned)r2 > (unsigned)r1) {
                                                            POLL();
                                                            r1 = LD32(r4 + 4);
                                                            c1008 = (r1 & r1) == 0;
                                                            r1 = 1;
                                                            c1030 = c1008;
                                                            if (!(c1008)) {
                                                                r1 = -1;
                                                                c1030 = 0;
                                                            }
                                                            r0 = r1;
                                                            c1031 = c1030;
                                                        } else {
                                                            if (!(c30)) {
                                                                r2 = LD32(r5 + 12);
                                                                r1 = LD32(r4 + 12);
                                                                c33 = r2 == r1;
                                                                if ((unsigned)r2 > (unsigned)r1) {
                                                                    r1 = LD32(r4 + 4);
                                                                    c1028 = (r1 & r1) == 0;
                                                                    r1 = -1;
                                                                    c1030 = c1028;
                                                                    if (!(c1028)) {
                                                                        r1 = 1;
                                                                        c1030 = 0;
                                                                    }
                                                                    r0 = r1;
                                                                    c1031 = c1030;
                                                                } else {
                                                                    r0 = 0;
                                                                    c1031 = c33;
                                                                    if (c33) {
                                                                        r2 = LD32(r5 + 16);
                                                                        r1 = LD32(r4 + 16);
                                                                        if ((unsigned)r2 > (unsigned)r1) {
                                                                            r1 = LD32(r4 + 4);
                                                                            c1028 = (r1 & r1) == 0;
                                                                            r1 = -1;
                                                                            c1030 = c1028;
                                                                            if (!(c1028)) {
                                                                                r1 = 1;
                                                                                c1030 = 0;
                                                                            }
                                                                            r0 = r1;
                                                                            c1031 = c1030;
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                r2 = LD32(r4 + 16);
                                                                r1 = LD32(r5 + 16);
                                                                if ((unsigned)r2 > (unsigned)r1) {
                                                                    POLL();
                                                                    r1 = LD32(r4 + 4);
                                                                    c1008 = (r1 & r1) == 0;
                                                                    r1 = 1;
                                                                    c1030 = c1008;
                                                                    if (!(c1008)) {
                                                                        r1 = -1;
                                                                        c1030 = 0;
                                                                    }
                                                                    r0 = r1;
                                                                    c1031 = c1030;
                                                                } else {
                                                                    r2 = LD32(r5 + 12);
                                                                    r1 = LD32(r4 + 12);
                                                                    c33 = r2 == r1;
                                                                    if ((unsigned)r2 > (unsigned)r1) {
                                                                        r1 = LD32(r4 + 4);
                                                                        c1028 = (r1 & r1) == 0;
                                                                        r1 = -1;
                                                                        c1030 = c1028;
                                                                        if (!(c1028)) {
                                                                            r1 = 1;
                                                                            c1030 = 0;
                                                                        }
                                                                        r0 = r1;
                                                                        c1031 = c1030;
                                                                    } else {
                                                                        r0 = 0;
                                                                        c1031 = c33;
                                                                        if (c33) {
                                                                            r2 = LD32(r5 + 16);
                                                                            r1 = LD32(r4 + 16);
                                                                            if ((unsigned)r2 > (unsigned)r1) {
                                                                                r1 = LD32(r4 + 4);
                                                                                c1028 = (r1 & r1) == 0;
                                                                                r1 = -1;
                                                                                c1030 = c1028;
                                                                                if (!(c1028)) {
                                                                                    r1 = 1;
                                                                                    c1030 = 0;
                                                                                }
                                                                                r0 = r1;
                                                                                c1031 = c1030;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    c1008 = (r2 & r2) == 0;
                                                    POLL();
                                                    r1 = 1;
                                                    c1030 = c1008;
                                                    if (!(c1008)) {
                                                        r1 = -1;
                                                        c1030 = 0;
                                                    }
                                                    r0 = r1;
                                                    c1031 = c1030;
                                                }
                                            }
                                        }
                                    } else {
                                        r1 = LD32(r5 + 4);
                                        c1028 = (r1 & r1) == 0;
                                        r1 = -1;
                                        c1030 = c1028;
                                        if (!(c1028)) {
                                            r1 = 1;
                                            c1030 = 0;
                                        }
                                        r0 = r1;
                                        c1031 = c1030;
                                    }
                                }
                            }
                        } else {
                            r1 = LD32(r5 + 4);
                            c1028 = (r1 & r1) == 0;
                            r1 = -1;
                            c1030 = c1028;
                            if (!(c1028)) {
                                r1 = 1;
                                c1030 = 0;
                            }
                            r0 = r1;
                            c1031 = c1030;
                        }
                    } else {
                        r1 = LD32(r4 + 4);
                        c1008 = (r1 & r1) == 0;
                        r1 = 1;
                        c1030 = c1008;
                        if (!(c1008)) {
                            r1 = -1;
                            c1030 = 0;
                        }
                        r0 = r1;
                        c1031 = c1030;
                    }
                } else {
                    r2 = LD32(r5 + 4);
                    r1 = LD32(r4 + 4);
                    r0 = r2 - r1;
                    c1031 = 0;
                }
            }
        } else {
            r0 = r3;
            c1031 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607555C(int r4)
{
    int r0, r1, r2, r3, r8, r9, c10, c15, c16, c18, c1032;
    FRAME(sp, 16);

    r8 = r4;
    r4 = LD32(r8);
    r9 = 28;
    if ((unsigned)r4 > (unsigned)59) {
        r0 = GCALL2(0x060758C4, r4, 60);
        r2 = r0;
        r1 = R(1);
        r3 = r1;
        r1 = LD32(r8 + 4);
        r0 = r3;
        ST32(r8, r0);
        ST32(r8 + 4, (r1 + r2));
        if (!(r0 >= 0)) {
            ST32(r8, (r0 + 60));
        }
    }
    r4 = LD32(r8 + 4);
    if ((unsigned)r4 > (unsigned)59) {
        r0 = GCALL2(0x060758C4, r4, 60);
        r2 = r0;
        r1 = R(1);
        r3 = r1;
        r1 = LD32(r8 + 8);
        r0 = r3;
        ST32(r8 + 4, r0);
        ST32(r8 + 8, (r1 + r2));
        if (!(r0 >= 0)) {
            ST32(r8 + 4, (r0 + 60));
        }
    }
    r4 = LD32(r8 + 8);
    if ((unsigned)r4 > (unsigned)23) {
        r0 = GCALL2(0x060758C4, r4, 24);
        r2 = r0;
        r1 = R(1);
        r3 = r1;
        r1 = LD32(r8 + 12);
        r0 = r3;
        ST32(r8 + 8, r0);
        ST32(r8 + 12, (r1 + r2));
        if (!(r0 >= 0)) {
            ST32(r8 + 8, (r0 + 24));
        }
    }
    r4 = LD32(r8 + 16);
    if (r4 > 11) {
        r0 = GCALL2(0x060758C4, r4, 12);
        r2 = r0;
        r1 = R(1);
        r3 = r1;
        r1 = LD32(r8 + 20);
        r0 = r3;
        ST32(r8 + 16, r0);
        ST32(r8 + 20, (r1 + r2));
        if (!(r0 >= 0)) {
            ST32(r8 + 16, (r0 + 12));
        }
    }
    r0 = LD32(r8 + 20);
    if (((r0 & 3) & (r0 & 3)) == 0) {
        r9 = 29;
    }
    r1 = LD32(r8 + 12);
    r2 = r1;
    if (r1 >= 0) {
        r0 = LD32(r8 + 16);
        while (1) {
            c18 = r2 > r9;
            if (r0 == 1) {
                POLL();
                if (!(c18)) {
                    break;
                } else {
                    r0 = LD32(r8 + 16);
                    r2 = LD32(r8 + 12);
                    if (r0 == 1) {
                        r1 = r2 - r9;
                    } else {
                        r1 = LD32((r0 << 2) + 0x060754FC);
                        r1 = r2 - r1;
                    }
                    ST32(r8 + 12, r1);
                    r1 = LD32(r8 + 16);
                    r0 = r1 + 1;
                    c15 = r0 == 12;
                    ST32(r8 + 16, r0);
                    c1032 = c15;
                    if (c15) {
                        r1 = LD32(r8 + 20);
                        r9 = 28;
                        ST32(r8 + 20, (r1 + 1));
                        r0 = LD32(r8 + 20);
                        c16 = ((r0 & 3) & (r0 & 3)) == 0;
                        ST32(r8 + 16, 0);
                        c1032 = c16;
                        if (c16) {
                            r9 = 29;
                            c1032 = 1;
                        }
                    }
                    r0 = LD32(r8 + 16);
                    r2 = LD32(r8 + 12);
                    continue;
                }
            } else {
                r0 = r0 << 2;
                r1 = LD32(r0 + 0x060754FC);
                if (r2 > r1) {
                    POLL();
                    r0 = LD32(r8 + 16);
                    r2 = LD32(r8 + 12);
                    if (r0 == 1) {
                        r1 = r2 - r9;
                    } else {
                        r1 = LD32((r0 << 2) + 0x060754FC);
                        r1 = r2 - r1;
                    }
                    ST32(r8 + 12, r1);
                    r1 = LD32(r8 + 16);
                    r0 = r1 + 1;
                    c15 = r0 == 12;
                    ST32(r8 + 16, r0);
                    c1032 = c15;
                    if (c15) {
                        r1 = LD32(r8 + 20);
                        r9 = 28;
                        ST32(r8 + 20, (r1 + 1));
                        r0 = LD32(r8 + 20);
                        c16 = ((r0 & 3) & (r0 & 3)) == 0;
                        ST32(r8 + 16, 0);
                        c1032 = c16;
                        if (c16) {
                            r9 = 29;
                            c1032 = 1;
                        }
                    }
                    r0 = LD32(r8 + 16);
                    r2 = LD32(r8 + 12);
                    continue;
                } else {
                    break;
                }
            }
        }
    } else {
        r3 = 0x060754FC;
        do {
            r0 = LD32(r8 + 16);
            c10 = r0 == 1;
            r0 = r0 << 2;
            if (c10) {
                r1 = r2 + r9;
            } else {
                r1 = LD32(r0 + r3);
                r1 = r1 + r2;
            }
            ST32(r8 + 12, r1);
            r1 = LD32(r8 + 16);
            r0 = r1 - 1;
            ST32(r8 + 16, r0);
            if (r0 == -1) {
                r1 = LD32(r8 + 20);
                r9 = 28;
                ST32(r8 + 20, (r1 - 1));
                r0 = LD32(r8 + 20);
                r0 = r0 & 3;
                ST32(r8 + 16, 12);
                if ((r0 & r0) == 0) {
                    r9 = 29;
                }
            }
            r2 = LD32(r8 + 12);
        } while (AGAIN(!(r2 >= 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0607277E(int r4)
{
    SETR(4, ((signed char)((int)((unsigned)((int)((unsigned)r4 >> 16)) >> 8))));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A2(int r4)
{
    SETR(4, (((((((((((r4 >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A4(int r4)
{
    SETR(4, ((((((((((r4 >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A6(int r4)
{
    SETR(4, (((((((((r4 >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A8(int r4)
{
    SETR(4, ((((((((r4 >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727AA(int r4)
{
    SETR(4, (((((((r4 >> 1) >> 1) >> 1) >> 1) >> 1) >> 1) >> 1));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727AC(int r4)
{
    SETR(4, ((((((r4 >> 1) >> 1) >> 1) >> 1) >> 1) >> 1));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060739C0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r10, r14, c2008;
    FRAME(sp, 96);

    r14 = sp - 96;
    r1 = r14 + 60;
    ST32(r1, r4);
    ST32(r1 + 4, r5);
    r10 = r14 + 68;
    ST32(r10, r6);
    ST32(r10 + 4, r7);
    r0 = GCALL2(0x060736D8, r1, r14);
    r9 = r14 + 20;
    r0 = GCALL2(0x060736D8, r10, r9);
    r0 = GCALL3(0x060737D4, r14, r9, (r14 + 40));
    c2008 = R(8);
    SETR(8, 0x060736D8);
    r0 = GCALL1(0x06073520, r0);
    SETR(8, c2008);
    r1 = R(1);
    SETR(1, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073E18(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r10, r14, c2008;
    FRAME(sp, 96);

    r14 = sp - 96;
    r1 = r14 + 60;
    ST32(r1, r4);
    ST32(r1 + 4, r5);
    r10 = r14 + 68;
    ST32(r10, r6);
    ST32(r10 + 4, r7);
    r0 = GCALL2(0x060736D8, r1, r14);
    r9 = r14 + 20;
    r0 = GCALL2(0x060736D8, r10, r9);
    r0 = GCALL3(0x06073AA4, r14, r9, (r14 + 40));
    c2008 = R(8);
    SETR(8, 0x060736D8);
    r0 = GCALL1(0x06073520, r0);
    SETR(8, c2008);
    r1 = R(1);
    SETR(1, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06073FDC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r10, r14, c2008;
    FRAME(sp, 96);

    r14 = sp - 96;
    r1 = r14 + 60;
    ST32(r1, r4);
    ST32(r1 + 4, r5);
    r10 = r14 + 68;
    ST32(r10, r6);
    ST32(r10 + 4, r7);
    r0 = GCALL2(0x060736D8, r1, r14);
    r9 = r14 + 20;
    r0 = GCALL2(0x060736D8, r10, r9);
    r0 = GCALL2(0x06073E80, r14, r9);
    c2008 = R(8);
    SETR(8, 0x060736D8);
    r0 = GCALL1(0x06073520, r0);
    SETR(8, c2008);
    r1 = R(1);
    SETR(1, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060743C8(int r4)
{
    int r0, r1, r2, r14, c4, c5, c6, c8, c9, c10, c1007;
    FRAME(sp, 28);

    r14 = sp - 28;
    ST32(r14, 3);
    r2 = (int)((unsigned)r4 >> 31);
    ST32(r14 + 4, r2);
    if (!((r4 & r4) == 0)) {
        ST32(r14 + 8, 60);
        if ((r2 & r2) == 0) {
            r1 = r4;
            r2 = r4;
            c8 = (unsigned)r1 >> 31;
            r1 = r1 << 1;
            c9 = r1;
            c10 = c9 - r1;
            r1 = c10 - c8;
            ST32(r14 + 12, r1);
            c1007 = ((unsigned)c9 < (unsigned)c10) | ((unsigned)c10 < (unsigned)r1);
            ST32(r14 + 16, r2);
            while (1) {
                r1 = LD32(r14 + 12);
                if ((unsigned)r1 > (unsigned)0x0FFFFFFF) {
                    break;
                } else {
                    r1 = LD32(r14 + 12);
                    r2 = LD32(r14 + 16);
                    ST32(r14 + 12, ((r1 << 1) | ((unsigned)r2 >> 31)));
                    ST32(r14 + 16, (r2 << 1));
                    r1 = LD32(r14 + 8);
                    ST32(r14 + 8, (r1 - 1));
                }
                POLL();
            }
            r0 = GCALL1(0x06073520, r14);
        } else {
            if (!(r4 == ((int)0x80000000))) {
                r1 = -r4;
                r2 = r1;
                c4 = (unsigned)r1 >> 31;
                r1 = r1 << 1;
                c5 = r1;
                c6 = c5 - r1;
                r1 = c6 - c4;
                ST32(r14 + 12, r1);
                c1007 = ((unsigned)c5 < (unsigned)c6) | ((unsigned)c6 < (unsigned)r1);
                ST32(r14 + 16, r2);
                while (1) {
                    r1 = LD32(r14 + 12);
                    if ((unsigned)r1 > (unsigned)0x0FFFFFFF) {
                        break;
                    } else {
                        r1 = LD32(r14 + 12);
                        r2 = LD32(r14 + 16);
                        ST32(r14 + 12, ((r1 << 1) | ((unsigned)r2 >> 31)));
                        ST32(r14 + 16, (r2 << 1));
                        r1 = LD32(r14 + 8);
                        ST32(r14 + 8, (r1 - 1));
                    }
                    POLL();
                }
                r0 = GCALL1(0x06073520, r14);
            } else {
                r0 = LD32(0x060743C0);
                r1 = LD32(0x060743C4);
            }
        }
    } else {
        ST32(r14, 2);
        r0 = GCALL1(0x06073520, r14);
    }
    r1 = R(1);
    SETR(1, r1);
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
    SETR(1, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060747D8(int r4, int r5, int r6, int r7)
{
    int r0, r1;
    FRAME(sp, 12);

    ST32((sp - 12), 0);
    r0 = GCALL5(0x06074A9C, r4, r5, r6, r7, LD32((sp - 12)));
    r1 = R(1);
    SETR(1, r1);
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
    SETR(1, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074888(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8, r14;
    FRAME(sp, 40);

    r14 = sp - 36;
    ST32(r14, 0);
    if (!(r4 >= 0)) {
        ST32(r14, -1);
        r1 = -r5;
        r4 = (-r4) - (((r1 & r1) == 0) ^ 1);
        r5 = r1;
    }
    r3 = LD32(r14);
    if (!(r6 >= 0)) {
        ST32(r14, (~r3));
        r1 = -r7;
        r6 = (-r6) - (((r1 & r1) == 0) ^ 1);
        r7 = r1;
    }
    ST32((sp - 40), 0);
    r0 = GCALL5(0x06074A9C, r4, r5, r6, r7, LD32((sp - 40)));
    r3 = LD32(r14);
    r7 = r0;
    r1 = R(1);
    r8 = r1;
    if (!((r3 & r3) == 0)) {
        r1 = -r8;
        r7 = (-r7) - (((r1 & r1) == 0) ^ 1);
        r8 = r1;
    }
    SETR(1, r8);
    return r7;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074924(int r4, int r5, int r6)
{
    int r0, r1, r9, r10, r11, r12, r13, r14;
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
        r1 = r10;
    } else {
        r0 = r11;
        r1 = r12;
    }
    SETR(1, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06074A9C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c2, c7, c12, c14, c15, c16, c21, c28, c29, c30, c31, c36, c38, c39, c40, c52, c68, c70, c1019, c1037, c1046, c1080;
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
            c14 = (unsigned)r3 >= (unsigned)r6;
            ST32(r14 + 36, r1);
            c1019 = c14;
            if (!(c14)) {
                r3 = r3 + r9;
                c15 = (unsigned)r3 >= (unsigned)r9;
                r7 = r7 - 1;
                c1019 = c15;
                if (c15) {
                    c16 = (unsigned)r3 >= (unsigned)r6;
                    c1019 = c16;
                    if (!(c16)) {
                        r7 = r7 - 1;
                        r3 = r3 + r9;
                        c1019 = 0;
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
                c28 = (unsigned)r3 >= (unsigned)r6;
                c1037 = c28;
                if (!(c28)) {
                    r3 = r3 + r9;
                    c29 = (unsigned)r3 >= (unsigned)r9;
                    r7 = r7 - 1;
                    c1037 = c29;
                    if (c29) {
                        c30 = (unsigned)r3 >= (unsigned)r6;
                        c1037 = c30;
                        if (!(c30)) {
                            r7 = r7 - 1;
                            r3 = r3 + r9;
                            c1037 = 0;
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
            c38 = (unsigned)r3 >= (unsigned)r6;
            ST32(r14 + 36, r1);
            c1046 = c38;
            if (!(c38)) {
                r3 = r3 + r9;
                c39 = (unsigned)r3 >= (unsigned)r9;
                r7 = r7 - 1;
                c1046 = c39;
                if (c39) {
                    c40 = (unsigned)r3 >= (unsigned)r6;
                    c1046 = c40;
                    if (!(c40)) {
                        r7 = r7 - 1;
                        r3 = r3 + r9;
                        c1046 = 0;
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
                    c70 = (unsigned)r3 > (unsigned)r6;
                    r7 = (r7 - r10) - c70;
                    r6 = r3;
                    c1080 = c70;
                    r13 = 0;
                } else {
                    c68 = r7 == r1;
                    c1080 = c68;
                    if (!(c68)) {
                        r13 = 0;
                    } else {
                        r12 = LD32(r14 + 16);
                        r13 = 0;
                        if ((unsigned)r6 > (unsigned)r12) {
                            r11 = r11 - 1;
                            r3 = r6 - r9;
                            c70 = (unsigned)r3 > (unsigned)r6;
                            r7 = (r7 - r10) - c70;
                            r6 = r3;
                            c1080 = c70;
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
    SETR(1, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060758C4(int r4, int r5)
{
    int r0, r7, r8, r9, r10, r11, r12, r13, c2, c1003, c1006, c1011;
    FRAME(sp, 32);

    r12 = r5;
    r13 = r4;
    if ((r12 & r12) == 0) {
        r11 = 0;
        if (r13 >= 0) {
            r10 = 0x7FFFFFFF;
            c1011 = 1;
        } else {
            r10 = (int)0x80000000;
            c1011 = 0;
        }
    } else {
        r0 = GCALL1(0x0607596C, r4);
        r9 = r0;
        r0 = GCALL1(0x0607596C, r12);
        r0 = GCALL2(0x0607286C, r9, r0);
        r10 = r0;
        r0 = GCALL1(0x0607596C, r13);
        r8 = r0;
        r0 = GCALL1(0x0607596C, r12);
        r7 = r0;
        r0 = GCALL2(0x0607286C, r8, r7);
        c2 = r13 >= 0;
        r11 = r8 - (r0 * r7);
        c1003 = c2;
        if (c2) {
            c1006 = c1003;
            if (c1003) {
                c1006 = r13 >= 0;
                if (!(r12 >= 0)) {
                    r10 = -r10;
                    c1006 = r13 >= 0;
                }
            }
        } else {
            c1003 = r13 >= 0;
            if (r12 > 0) {
                r10 = -r10;
                c1006 = r13 >= 0;
            } else {
                c1006 = c1003;
                if (c1003) {
                    c1006 = r13 >= 0;
                    if (!(r12 >= 0)) {
                        r10 = -r10;
                        c1006 = r13 >= 0;
                    }
                }
            }
        }
        c1011 = c1006;
        if (!(c1006)) {
            r11 = -r11;
        }
    }
    SETR(1, r11);
    return r10;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060727A0(int r4)
{
}
