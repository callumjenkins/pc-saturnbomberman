#include "krnl.h"

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060517D0(int r4)
{
    int r0;

    r0 = GCALL1(0x0607507C, (r4 + 100));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060517E4(int r4, int r5)
{
    int r0;

    r0 = GCALL2(0x060750DC, r5, (r4 + 100));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605180C(int r4)
{
    int r1, r2, r3;

    r3 = LD8(0x060517FC);
    ST8(0x1C4 + r4, r3);
    r3 = LD8(0x060517FD);
    r2 = (r4 + 0x1C4) + 1;
    ST8(r2, r3);
    r3 = LD8(0x060517FE);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x060517FF);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051800);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051801);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051802);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051803);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051804);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051805);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051806);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051807);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051808);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x06051809);
    r2 = r2 + 1;
    ST8(r2, r3);
    r1 = LD8(0x0605180A);
    ST8((r2 + 1), r1);
    return 0x1C4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06051874(int r4)
{
    int r0;

    r0 = GCALL3(0x0604B358, r4, 0x06079D40, 0x219);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06051B18(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06051B1C(int r4)
{
    int r1, r2, r3, r6, r7;

    r1 = LD32(r4 + 60);
    if (!(((r1 & 0x00F00000) & (r1 & 0x00F00000)) == 0)) {
        r3 = 0x10000000;
    } else {
        r3 = 0x00800000;
        ST16(0x25000380, -1);
    }
    r2 = 0x25FE00A8;
    r7 = 1;
    r6 = 0x25FE00A4;
    while (1) {
        ST32(r2, r7);
        r1 = LD32(r6);
        if (!(((r1 & r3) & (r1 & r3)) == 0)) {
            return;
        } else {
            r1 = LD32(r2);
            if ((r1 & r1) == 0) {
                POLL();
                continue;
            } else {
                return;
            }
        }
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06051B6C(void)
{
    int r1, r2, r3, r7, c2;

    r3 = 0x25FE00A8;
    r1 = LD32(0x25FE00A8);
    if (!((r1 & r1) == 0)) {
        return;
    } else {
        r1 = LD32(0x0608D854);
        r1 = LD32(r1 + 60);
        r2 = 0x10000000;
        if (((r1 & 0x00F00000) & (r1 & 0x00F00000)) == 0) {
            r2 = 0x00800000;
        }
        r1 = LD32(0x25FE00A4);
        c2 = ((r1 & r2) & (r1 & r2)) == 0;
        r7 = c2;
        if (c2) {
            ST32(r3, r7);
        }
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06051BB4(void)
{
    int r1, r2, r3;

    r3 = 0x0608B980;
    r2 = LD32(0x0608B980);
    do {
        r1 = LD32(r3);
    } while (AGAIN(r1 == r2));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06051BC8(int r4)
{
    int r0, r1, r2, r10;

    r10 = LD32(r4 + 60);
    r1 = LD32(0x06000344);
    r0 = GCALL2(r1, -1, 0x8000);
    if (((0x00F00000 & r10) & (0x00F00000 & r10)) == 0) {
        r2 = LD16(0x25000300);
        ST16(0x25000300, (r2 & -16));
    }
    r0 = GCALL0(0x06051BB4);
    r0 = GCALL3(0x06051E30, r10, 3, 3);
    r0 = GCALL0(0x06051BB4);
    r0 = GCALL3(0x06051E30, r10, 1, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06051D10(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, c3, c4, c5, c8, c10, c11;

    r3 = r5;
    if (!(((0x00F00000 & r4) & (0x00F00000 & r4)) == 0)) {
        r1 = LD8((r3 << 2) + r4);
        r6 = r1 & 255;
        ST8(0x2582503D, -1);
        r0 = r3;
    } else {
        r1 = LD16((r3 << 2) + r4);
        r7 = 0x25000000;
        r2 = -1;
        r6 = r1 & 255;
        r1 = 10;
        do {
            ST16(r7, r2);
            r1 = r1 - 1;
            r0 = r3;
        } while (AGAIN(r1 > 0));
    }
    r1 = 16;
    if (!(r0 == 5)) {
        r1 = 8;
        if (r3 == 6) {
            c8 = ((r1 & r6) & (r1 & r6)) == 0;
            r1 = 1;
            if (!(c8)) {
                if (((128 & r6) & (128 & r6)) == 0) {
                    ST32(0x0608D7D8, -1);
                    r2 = 0x0608D85C;
                    r1 = LD32(0x0608D85C);
                    r1 = r1 + 1;
                } else {
                    r1 = LD32(0x0608D3B4);
                    ST32(0x0608D3B4, (r1 + 1));
                    r2 = 0x0608D7D8;
                    r1 = 1;
                }
                ST32(r2, r1);
                r1 = 1;
            }
            c10 = ((r1 & r6) & (r1 & r6)) == 0;
            r1 = 2;
            if (!(c10)) {
                r1 = LD32(0x0608D7DC);
                ST32(0x0608D7DC, (r1 + 1));
                r1 = 2;
            }
            c11 = ((r1 & r6) & (r1 & r6)) == 0;
            r1 = 4;
            if (!(c11)) {
                r1 = LD32(0x0608D3BC);
                ST32(0x0608D3BC, (r1 + 1));
                r1 = 4;
            }
            if (!(((r1 & r6) & (r1 & r6)) == 0)) {
                r2 = 0x0608D7C0;
                r1 = LD32(0x0608D7C0);
                ST32(r2, (r1 + 1));
            }
        }
    } else {
        c3 = ((r1 & r6) & (r1 & r6)) == 0;
        r1 = 8;
        if (!(c3)) {
            r1 = LD32(0x0608D7E0);
            ST32(0x0608D7E0, (r1 + 1));
            r1 = 8;
        }
        c4 = ((r1 & r6) & (r1 & r6)) == 0;
        r1 = 4;
        if (!(c4)) {
            r1 = LD32(0x0608D7C8);
            ST32(0x0608D7C8, (r1 + 1));
            r1 = 4;
        }
        c5 = ((r1 & r6) & (r1 & r6)) == 0;
        r1 = 2;
        if (!(c5)) {
            r1 = LD32(0x0608D3B8);
            ST32(0x0608D3B8, (r1 + 1));
            r1 = 2;
        }
        if (!(((r1 & r6) & (r1 & r6)) == 0)) {
            r2 = 0x0608D7CC;
            r1 = LD32(0x0608D7CC);
            ST32(r2, (r1 + 1));
        }
    }
    return r6;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06051E30(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;

    r0 = r5;
    if (!(((0x00F00000 & r4) & (0x00F00000 & r4)) == 0)) {
        r0 = r0 << 2;
        ST8(r0 + r4, r6);
        ST8(0x2582503D, -1);
        return r0;
    } else {
        r0 = r0 << 2;
        ST16(r0 + r4, r6);
        r1 = 10;
        r3 = 0x25000000;
        r2 = -1;
        do {
            ST16(r3, r2);
            r1 = r1 - 1;
        } while (AGAIN(r1 > 0));
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06051F38(int r4)
{
    int r0, r1, c0;

    r1 = LD32(r4 + 60);
    c0 = ((r1 & 0x00F00000) & (r1 & 0x00F00000)) == 0;
    r1 = 0;
    if (c0) {
        ST16(0x25000100, r1);
        return;
    } else {
        r0 = GCALL0(0x06033050);
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06051F68(void)
{
    int r0, r1;

    r0 = GCALL0(0x06051E6C);
    r1 = LD32(0x0608D37C);
    r0 = GCALL0(r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06051F88(void)
{
    int r1, r2;

    r2 = 0x0608D37C;
    r1 = LD32(0x0608D37C);
    if ((r1 & r1) == 0) {
        r1 = LD32(0x0600002C);
        ST32(r2, r1);
    }
    ST32(0x0600002C, 0x06051F68);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605215C(void)
{
    int r0;

    r0 = LD32(0x060766B4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06052168(void)
{
    int r0, r1;

    r1 = LD32(0x0608D9CC);
    if (!((r1 & r1) == 0)) {
        r0 = GCALL0(r1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06052254(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11;

    r9 = r5;
    r10 = LD16((r9 + 4));
    r1 = LD8(r9 + r10);
    r2 = (r1 & 15) << 2;
    r5 = r5 + r10;
    if (!(r2 == 20)) {
        r11 = r5 + 2;
        r1 = LD16(r11);
        r8 = (r1 & 0xFFFF) - r2;
        r4 = r5;
        if (!((r8 & r8) == 0)) {
            r0 = GCALL3(0x0604B358, (r4 + 20), (r5 + r2), r8);
        }
        ST16(r11, (r8 + 20));
        r1 = LD8(r9 + r10);
        ST8(r9 + r10, ((r1 & 240) | 5));
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06052510(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    int v36;
    int v40;

    r12 = r4;
    r13 = r5;
    r3 = r13 + 4;
    r8 = LD16(r3);
    r10 = 20;
    if (!((r6 & r6) == 0)) {
        r9 = r12 + 4;
        r1 = LD16((r13 + 6));
        ST16((r12 + 6), r1);
        r1 = LD16(r9);
        r2 = LD16(r3);
        r0 = GCALL3(0x0604B358, (r12 + r1), (r13 + r2), r10);
        r1 = LD8(r13 + r8);
        r1 = (r1 & 15) << 2;
        v40 = r1;
        r8 = r10;
        if (!((unsigned)r10 >= (unsigned)r1)) {
            r14 = r9;
            r2 = 1;
            r1 = r13;
            while (1) {
                r1 = LD16((r1 + 4));
                r0 = r13 + r1;
                r1 = LD8(r0 + r8);
                r11 = r1 & 255;
                r8 = r8 + 1;
                r1 = LD8(r0 + r8);
                r9 = r1 & 255;
                r5 = r0 + r8;
                if (((128 & r11) & (128 & r11)) == 0) {
                    if (!((unsigned)r11 > (unsigned)r2)) {
                        r1 = LD16(r14);
                        r9 = r2;
                        ST8((r12 + r1) + r10, r11);
                        r10 = r10 + 1;
                    }
                } else {
                    r1 = LD16(r14);
                    v36 = r2;
                    r0 = GCALL6(0x0604B358, ((r12 + r1) + r10), (r5 - 1), r9, 0, v40, v36);
                    r2 = v36;
                    r10 = r10 + r9;
                }
                r8 = (r8 - 1) + r9;
                if ((r11 & r11) == 0) {
                    break;
                } else {
                    r1 = r13;
                    if (!((unsigned)r8 >= (unsigned)v40)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
        }
        r2 = r12;
        if (!(((3 & r10) & (3 & r10)) == 0)) {
            r2 = r2 + 4;
            r3 = 1;
            do {
                r1 = LD16(r2);
                ST8((r12 + r1) + r10, r3);
                r10 = r10 + 1;
            } while (AGAIN(!(((3 & r10) & (3 & r10)) == 0)));
        }
        r0 = r10;
    } else {
        r1 = LD16((r13 + 6));
        ST16((r12 + 6), r1);
        r1 = LD16((r12 + 4));
        r2 = LD16(r3);
        r3 = LD8(r13 + r8);
        r0 = GCALL3(0x0604B358, (r4 + r1), (r5 + r2), ((r3 & 15) << 2));
        r1 = LD8(r13 + r8);
        r0 = (r1 & 15) << 2;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06052638(void)
{
    int r0, r1, r2, r3, r7;

    r7 = 0x0608D380;
    r3 = 3;
    r0 = 0;
    r2 = 144;
    do {
        r1 = LD32(r7);
        ST8(r0 + r1, r3);
        r0 = r0 + 16;
    } while (AGAIN(!(r0 > r2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060528BC(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7;

    r6 = 0x0608D380;
    r7 = 0;
    r1 = 0;
    r3 = 144;
    do {
        r0 = LD32(r6);
        r2 = r0;
        r0 = LD8(r0 + r1);
        r2 = r2 + r1;
        if (!(r0 == 3)) {
            ST32(r2 + 4, r7);
        }
        r1 = r1 + 16;
    } while (AGAIN(!(r1 > r3)));
    r0 = GCALL4(0x060527F0, 0, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060528F0(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c0;

    r11 = r4;
    r9 = 0;
    r8 = 0x06079F5C;
    r10 = 1;
    while (1) {
        r1 = LD32(r8);
        c0 = r1 > r10;
        r1 = 0;
        if (c0) {
            ST32(r8, r1);
        }
        r3 = LD32(0x0608D388);
        r2 = LD32(r8);
        r2 = (r2 * 196) + r3;
        r0 = LD8((r2 + 30));
        r1 = r2;
        if (r0 == 2) {
            r9 = r9 + 1;
            r1 = LD32(r8);
            ST32(r8, (r1 + 1));
            if (!(r9 > r10)) {
                POLL();
                continue;
            } else {
                r0 = 0;
                break;
            }
        } else {
            r4 = LD32((r1 + 120));
            r0 = GCALL1(0x0605DD2C, r4);
            r9 = r9 + 1;
            if ((r0 & r0) == 0) {
                r1 = LD32(r8);
                ST32(r8, (r1 + 1));
                if (!(r9 > r10)) {
                    POLL();
                    continue;
                } else {
                    r0 = 0;
                    break;
                }
            } else {
                r1 = LD32(r8);
                ST32(r11, r1);
                break;
            }
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06052964(int r4)
{
    int r0, r1, r2;

    r0 = r4;
    r2 = r0 + 2;
    r1 = LD16(r2);
    ST16(r2, r1);
    r2 = r0 + 4;
    r1 = LD16(r2);
    ST16(r2, r1);
    r2 = r0 + 6;
    r1 = LD16(r2);
    ST16(r2, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06052980(int r4)
{
    int r0, r1, r2;

    r0 = r4;
    r2 = r0 + 2;
    r1 = LD16(r2);
    ST16(r2, r1);
    r2 = r0 + 4;
    r1 = LD16(r2);
    ST16(r2, r1);
    r2 = r0 + 6;
    r1 = LD16(r2);
    ST16(r2, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06052FA4(int r4, int r5)
{
    int r0, r1, r2, r6, r8;

    r8 = r5;
    r1 = LD16((r8 + 4));
    r2 = r8 + r1;
    r1 = LD32(0x0608D8A4);
    ST32(0x0608D8A4, (r1 + 1));
    r0 = LD8((r2 + 1));
    r4 = LD32((r4 + 120));
    r6 = 224 & r0;
    r0 = GCALL3(0x0605DCAC, r4, r5, r6);
    if (!(r0 >= 0)) {
        r1 = LD32(0x0608D988);
        ST32(0x0608D988, (r1 + 1));
        r1 = LD32(0x0608D390);
        r0 = GCALL3(r1, r8, r5, r6);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06052FFC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8;
    FRAME(sp, 8);

    r8 = r5;
    r3 = r6;
    r0 = LD16((r8 + 4));
    r6 = LD32(sp);
    r5 = r5 + r0;
    if (!(r7 >= 0)) {
        r7 = 0;
    }
    if (!(r6 >= 0)) {
        r6 = 119;
    }
    ST16((r8 + 6), 33);
    ST8(r0 + r8, 69);
    ST8((r5 + 1), r7);
    r0 = LD8(r0 + r8);
    ST16((r5 + 2), (((r0 & 15) << 2) + r3));
    r3 = LD32(0x06079F64);
    ST32(0x06079F64, (r3 + 1));
    ST16((r5 + 4), r3);
    ST16((r5 + 6), 0);
    ST8((r5 + 8), r6);
    r1 = LD8(r4);
    ST8((r5 + 16), r1);
    r1 = r4 + 1;
    r2 = LD8(r1);
    r1 = r1 + 1;
    ST8((r5 + 17), r2);
    r2 = LD8(r1);
    ST8((r5 + 18), r2);
    r1 = LD8((r1 + 1));
    ST8((r5 + 19), r1);
    r1 = LD8((r5 + 9));
    r3 = r5;
    if (!((r1 & 255) == 1)) {
        r2 = LD8(0x060530FC);
        ST8((r3 + 12), r2);
        r2 = LD8(0x060530FD);
        ST8((r5 + 13), r2);
        r2 = LD8(0x060530FE);
        ST8((r5 + 14), r2);
        r1 = LD8(0x060530FF);
        ST8((r5 + 15), r1);
    }
    r1 = LD32(0x0608D388);
    r6 = 0;
    r4 = LD32((r1 + 120));
    r5 = r8;
    r0 = GCALL3(0x0605DCAC, r4, r5, 0);
    if (!(r0 >= 0)) {
        r1 = LD32(0x0608D390);
        r0 = GCALL3(r1, r8, r5, r6);
        r1 = LD32(0x0608D984);
        ST32(0x0608D984, (r1 + 1));
    }
    r1 = LD32(0x0608D930);
    ST32(0x0608D930, (r1 + 1));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06053108(int r4)
{
    int r0, r5, r6, r8, r9, r10, r11, r12, r13;

    r9 = r4;
    r8 = 0x060752CC;
    r0 = GCALL3(0x060752CC, r4, 0x060530FC, 4);
    r6 = 4;
    if ((r0 & r0) == 0) {
        r0 = 1;
    } else {
        r0 = GCALL3(r8, r9, 0x06053104, r6);
        r12 = 0;
        if ((r0 & r0) == 0) {
            r0 = 1;
        } else {
            r11 = 0x0608D388;
            r10 = r8;
            r8 = 0;
            while (1) {
                r13 = 196;
                r5 = LD32(r11);
                r0 = GCALL3(r10, r9, ((r5 + r8) + 52), 4);
                if ((r0 & r0) == 0) {
                    r0 = 1;
                    break;
                } else {
                    r5 = LD32(r11);
                    r0 = GCALL3(r10, r9, ((r5 + r8) + 56), 4);
                    if ((r0 & r0) == 0) {
                        r0 = 1;
                        break;
                    } else {
                        r5 = LD32(r11);
                        r0 = GCALL3(r10, r9, ((r5 + r8) + 44), 4);
                        if ((r0 & r0) == 0) {
                            r0 = 1;
                            break;
                        } else {
                            r5 = LD32(r11);
                            r0 = GCALL3(r10, r9, ((r5 + r8) + 40), 4);
                            r12 = r12 + 1;
                            if (!((r0 & r0) == 0)) {
                                r8 = r8 + r13;
                                if (!(r12 > 1)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = 0;
                                    break;
                                }
                            } else {
                                r0 = 1;
                                break;
                            }
                        }
                    }
                }
                POLL();
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060531AC(int r4, int r5)
{
    int r1, r3;

    r3 = 0;
    if (r5 > 0) {
        do {
            r1 = LD16(r4);
            r4 = r4 + 2;
            r5 = r5 - 1;
            r3 = r3 + (r1 & 0xFFFF);
        } while (AGAIN(r5 > 0));
    }
    return (short)(~((((int)((unsigned)r3 >> 16)) + (r3 & 0xFFFF)) + ((int)((unsigned)(((int)((unsigned)r3 >> 16)) + (r3 & 0xFFFF)) >> 16))));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06053248(void)
{
    int r0, r4;

    r4 = LD32(0x0608D388);
    r0 = GCALL1(0x060531D4, (r4 + 196));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605328C(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;

    ST32(0x0608D380, 0);
    ST32(0x0608D388, 160);
    ST32(0x0608D880, 0x228);
    r8 = 0x228 + (r4 * 48);
    ST32(0x0608D884, r8);
    r8 = r8 + (((r4 << 2) + (r4 << 2)) << 2);
    ST32(0x0608D854, r8);
    r8 = r8 + 0xD04;
    ST32(0x0608D9C8, r8);
    r8 = r8 + 0x138;
    ST32(0x0608D990, r8);
    r8 = r8 + 240;
    r14 = 0x0608D9E4;
    ST32(0x0608D9E4, r8);
    r2 = LD32(0x0608D9E8);
    r1 = LD32(0x0608D88C);
    r8 = r8 + (((r2 + r1) + 3) * 28);
    r13 = 0x0608D9F0;
    ST32(0x0608D9F0, r8);
    r8 = r8 + (r5 * 24);
    r12 = 0x0608D890;
    ST32(0x0608D890, r8);
    r8 = r8 + (r4 * 220);
    r11 = 0x0608D9EC;
    ST32(0x0608D9EC, r8);
    r5 = ((r5 << 2) + (r5 << 2)) << 2;
    r8 = r8 + r5;
    r10 = 0x0608D38C;
    ST32(0x0608D38C, r8);
    r6 = (r6 << 2) << 2;
    r8 = r8 + r6;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL4(r0, r8, r5, r6, 0x0608D990);
    r9 = r0;
    r6 = r8;
    if ((r9 & r9) == 0) {
        r0 = -3;
    } else {
        r0 = GCALL3(0x0604B3F0, r9, 0, r6);
        r1 = LD32(0x0608D380);
        ST32(0x0608D380, (r1 + r9));
        r1 = LD32(0x0608D388);
        ST32(0x0608D388, (r1 + r9));
        r1 = LD32(0x0608D880);
        ST32(0x0608D880, (r1 + r9));
        r1 = LD32(0x0608D884);
        ST32(0x0608D884, (r1 + r9));
        r1 = LD32(0x0608D854);
        ST32(0x0608D854, (r1 + r9));
        r1 = LD32(0x0608D9C8);
        ST32(0x0608D9C8, (r1 + r9));
        r1 = LD32(0x0608D990);
        ST32(0x0608D990, (r1 + r9));
        r1 = LD32(r14);
        ST32(r14, (r1 + r9));
        r1 = LD32(r13);
        ST32(r13, (r1 + r9));
        r1 = LD32(r12);
        ST32(r12, (r1 + r9));
        r1 = LD32(r11);
        ST32(r11, (r1 + r9));
        r1 = LD32(r10);
        r0 = 0;
        ST32(r10, (r1 + r9));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060533F8(void)
{
    int r0;

    r0 = LD32(0x0608B980);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06053404(int r4)
{
    int r0;
    FRAME(sp, 104);

    ST32(sp - 104, 16);
    ST32(sp - 100, 4);
    ST32(sp - 96, 0);
    ST32(sp - 92, 0x0605E5EC);
    ST32(sp - 88, 0x0605E638);
    ST32(sp - 84, 0x0605E64C);
    ST32(sp - 80, 0x0605E714);
    ST32(sp - 76, 0x06042B28);
    ST32(sp - 72, 0x06042B84);
    ST32(sp - 68, 0x06042C0C);
    ST32(sp - 64, 0x0605E800);
    ST32(sp - 60, 0x060533F8);
    ST32(sp - 56, 10);
    r0 = 128;
    ST32(sp - 52, 128);
    if (!((r4 & r4) == 0)) {
        ST32(sp - 52, (r0 | 64));
    }
    r0 = GCALL8(0x06053480, (sp - 104), 0, 0, 0, LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)), LD32((sp - 92)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06053A18(void)
{
    int r0, r1, r8, r9;

    r9 = LD32(0x0608D854);
    r8 = LD8((r9 + 11));
    r0 = GCALL0(0x0605396C);
    ST8(((r9 + ((((signed char)r8) << 2) + (((signed char)r8) << 2))) + 98), 3);
    r1 = LD32(0x0608D7D0);
    ST32(0x0608D7D0, (r1 + 1));
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06053B24(int r4, int r5)
{
    int r0, r8;

    r8 = r5;
    r0 = GCALL2(0x0607290C, 1, r4);
    return (((r8 & r0) & (r8 & r0)) == 0) ^ 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06053B44(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r8, c0;

    r8 = r4;
    r3 = r8 + 22;
    r1 = LD16(r3);
    r7 = r5;
    r1 = r1 & 0xFFFF;
    r2 = (int)((unsigned)r1 >> 8);
    r0 = ((r1 ^ r7) & 255) + ((r1 ^ r7) & 255);
    r1 = LD16(r0 + 0x0605E90C);
    ST16(r3, ((r1 ^ r2) & 0xFFFF));
    r1 = LD16((r8 + 20));
    c0 = (r1 & 0xFFFF) == 0xBB8;
    r1 = r8;
    if (!(c0)) {
        r1 = LD8((r1 + 16));
        r0 = r7;
        if (!((r1 & r1) == 0)) {
            if (r0 == 10) {
                r0 = GCALL0(0x06053A18);
                ST8((r8 + 6), 1);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06053E68(int r4)
{
    ST8((r4 + 7), 10);
    ST32(r4 + 52, -1);
    ST8((r4 + 14), 0);
    ST8((r4 + 18), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06053E84(void)
{
    int r0, r1, r5, r6, r7;

    r6 = LD32(0x0608D854);
    r5 = r6 + 0x14C;
    r0 = SR();
    r7 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    r0 = r0 | 240;
    SETSR(r0);
    ST32(r6 + 44, r5);
    ST16((r6 + 20), 0);
    r1 = SR();
    SETSR(((r1 & -241) | ((r7 << 2) << 2)));
    ST32(r6 + 48, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06053EC4(void)
{
    int r0, r1, r8, r9;

    r8 = LD32(0x0608D854);
    r0 = GCALL1(0x06051C84, r8);
    r9 = r0;
    if (r9 >= 0) {
        r0 = GCALL1(0x0605E878, 8);
        ST32((r8 + 64), r0);
        ST8((r8 + 15), 1);
        ST8(r8, 0);
        r0 = LD32(0x0608D39C);
        r0 = GCALL1(r0, 8);
        r1 = LD32(0x0608D394);
        ST32((r8 + 76), ((r1 + r1) + r0));
    }
    r0 = GCALL0(0x06053E84);
    ST8(0x0608D3B0, 0);
    ST8(0x0608D3B1, 0);
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06054150(int r4, int r5, int r6)
{
    int r0, r8, r9, r10;

    r8 = r4;
    r10 = r5;
    r9 = r6;
    if (!((unsigned)(r8 - 125) > (unsigned)1)) {
        r0 = GCALL1(0x0605B778, 125);
        ST8((r9 + 5), r8);
        ST8((r9 + 24), r10);
        r0 = 16;
    } else {
        if (r8 > 31) {
            r0 = GCALL1(0x0605B778, (r8 & 255));
            r0 = r10;
        } else {
            r5 = LD32(r9 + 8);
            r0 = GCALL2(0x06053B24, r4, r5);
            if ((r0 & r0) == 0) {
                r0 = GCALL1(0x0605B778, (r8 & 255));
                r0 = r10;
            } else {
                r0 = GCALL1(0x0605B778, 125);
                ST8((r9 + 5), r8);
                ST8((r9 + 24), r10);
                r0 = 16;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06054420(void)
{
    int r0, r1, r2, r3, r6, r7;

    r3 = LD32(0x0608D854);
    r7 = r3 + 20;
    r1 = LD16(r7);
    r0 = -1;
    if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
        return r0;
    } else {
        r2 = LD32(r3 + 48);
        r1 = LD8(r2);
        r2 = r2 + 1;
        r6 = r1 & 255;
        if (r2 == (0xD04 + r3)) {
            r2 = r3 + 0x14C;
        }
        ST32(r3 + 48, r2);
        r0 = SR();
        r3 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
        r0 = SR();
        SETSR((r0 | 240));
        r1 = LD16(r7);
        ST16(r7, (r1 - 1));
        r1 = LD16(r7);
        r1 = SR();
        SETSR(((r1 & -241) | ((r3 << 2) << 2)));
        return r6;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06054480(int r4, int r5)
{
    int r0, r1;

    r1 = LD16((r4 + 20));
    r0 = -1;
    if (!((r1 & 0xFFFF) > r5)) {
        return r0;
    } else {
        r1 = LD32(r4 + 48);
        r5 = r5 + r1;
        if ((unsigned)r5 > (unsigned)(0xD04 + r4)) {
            r5 = r5 + -3000;
        }
        r1 = LD8(r5);
        return r1 & 255;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060546BC(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8;

    r8 = LD32(0x0608D854);
    r0 = GCALL3(0x0605457C, r8, r5, r6);
    r1 = LD8((r8 + 9));
    r2 = r8 + ((r1 << 2) + (r1 << 2));
    r1 = LD8((r2 + 98));
    r0 = 0;
    if (((signed char)r1) == 2) {
        r1 = LD16((r2 + 94));
        r3 = r1 & 0xFFFF;
        r1 = LD16((r2 + 92));
        r1 = LD8((r8 + (r1 & 0xFFFF)) + 0x14C);
        if (!(((r1 & 1) & (r1 & 1)) == 0)) {
            r3 = r3 + 1;
        }
        r0 = r3 + 134;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06054724(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14;
    int v36;
    int v40;
    int v44;

    v44 = r4;
    r10 = LD32(0x0608D854);
    r11 = v44;
    r0 = GCALL5(0x0605457C, r10, r5, r6, 0, v44);
    r1 = LD8((r10 + 9));
    r2 = ((r1 << 2) + (r1 << 2)) + 92;
    r0 = r10 + r2;
    v36 = r0;
    r1 = LD8((r0 + 6));
    r0 = r10;
    if (((signed char)r1) == 2) {
        r11 = r11 + 4;
        r1 = LD16(r0 + r2);
        r3 = 0x14C;
        r9 = r1 & 0xFFFF;
        r2 = r10 + r9;
        r1 = LD16((v36 + 2));
        r12 = r1 & 0xFFFF;
        v40 = r9;
        ST16(r11, 136);
        r1 = LD8(r2 + 0x14C);
        r14 = r12;
        if (((r1 & 1) & (r1 & 1)) == 0) {
            r2 = LD8(r2 + r3);
            r9 = r9 + 1;
            ST8((r11 + 2), r2);
            r12 = r14 - 1;
            if (r9 == 0xBB8) {
                r9 = 0;
            }
        } else {
            ST8((r11 + 2), 0);
        }
        r8 = 0x14C;
        r1 = LD8((r10 + r9) + 0x14C);
        r9 = r9 + 1;
        r13 = 0xBB8;
        ST8((r11 + 3), r1);
        if (r9 == 0xBB8) {
            r9 = 0;
        }
        r12 = r12 - 1;
        ST32(v44, r12);
        r0 = GCALL7(0x0604B3F0, (r11 + 4), 0, 128, 0, v44, v40, v36);
        r11 = r11 + 132;
        r2 = LD32(r10 + 48);
        r5 = r10 + (v40 + r8);
        r7 = r5;
        if (!(r2 == r5)) {
            r7 = r7 - r2;
            if (!(r7 >= 0)) {
                r7 = r7 + r13;
            }
            r0 = SR();
            r1 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
            r0 = SR();
            SETSR((r0 | 240));
            r6 = r1;
            r3 = r10 + 20;
            r1 = LD16(r3);
            ST16(r3, (r1 - r7));
            r1 = SR();
            SETSR(((r1 & -241) | ((r6 << 2) << 2)));
            ST32(r10 + 48, r5);
        }
        r13 = 0xBB8;
        r5 = r9;
        if ((r9 + r12) > 0xBB8) {
            r8 = r13 - r9;
            r0 = GCALL7(0x0604B358, r11, ((r5 + r10) + 0x14C), r8, 0, v44, v40, v36);
            r12 = r12 - r8;
            r11 = r11 + r8;
            r5 = 0;
        }
        r0 = GCALL7(0x0604B358, r11, ((r5 + r10) + 0x14C), r12, 0, v44, v40, v36);
        r0 = SR();
        r1 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
        r0 = SR();
        SETSR((r0 | 240));
        r6 = r1;
        r3 = r10 + 20;
        r1 = LD16(r3);
        ST16(r3, (r1 - r14));
        r1 = SR();
        SETSR(((r1 & -241) | ((r6 << 2) << 2)));
        r1 = LD32(r10 + 48);
        r2 = r1 + r14;
        ST32(r10 + 48, r2);
        if ((unsigned)r2 >= (unsigned)(0xD04 + r10)) {
            ST32(r10 + 48, (r2 - r13));
        }
        r0 = GCALL7(0x060538A0, v36, r10, 0, 0, v44, v40, v36);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06054A74(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = 0x0608D850;
    r0 = LD32(0x0608D850);
    r1 = 0;
    if (r0 > 0) {
        ST8(r0 + 0x0608D7F0, r1);
        r0 = GCALL4(0x0605DC24, 0x0608D7F0, r5, r6, r7);
        ST32(r8, 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055000(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r1 = LD32(0x0608D854);
    r8 = LD32((r1 + 64));
    r0 = GCALL1(0x0605EB28, r8);
    r5 = r4;
    if (!(r0 > 7)) {
        r0 = GCALL4(0x0605EB6C, r8, r5, r6, r7);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055124(int r4, int r5)
{
    int r0, r1, r8, r9;

    r8 = r4;
    r0 = LD32(0x0608D39C);
    r9 = r5;
    r0 = GCALL2(r0, r4, r5);
    r1 = LD32(0x0608D394);
    ST32(r8 + 40, ((r9 * r1) + r0));
    ST8((r8 + 2), 1);
    r8 = r8 + 1;
    r1 = LD8(r8);
    ST8(r8, (r1 - 1));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055210(int r4)
{
    int r0;

    r0 = GCALL3(0x06055160, r4, 0x06055208, 3);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055230(int r4)
{
    int r0;

    r0 = GCALL3(0x06055160, r4, 0x06055228, 2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06055404(int r4)
{
    ST32(r4 + 28, 0x0608AF04);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06055410(int r4)
{
    int r1, r2;

    r1 = LD32(r4 + 28);
    r2 = 0x0608AF04;
    if (!(r1 == 0x0608AF04)) {
        ST32(r4 + 28, r2);
        return;
    } else {
        r2 = r2 + 32;
        r1 = LD8(r2);
        if (!((r1 & r1) == 0)) {
            ST32(r4 + 28, r2);
        }
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060556B0(int r4)
{
    int r0, r8;

    r8 = r4;
    r0 = GCALL1(0x06053E68, r4);
    r0 = GCALL1(0x0605DBD4, ((int)0xC0210000));
    ST8((r8 + 17), 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060556D8(int r4)
{
    int r0;

    ST8((r4 + 6), 0);
    ST8((r4 + 7), 0);
    r0 = GCALL1(0x0605DBD4, ((int)0xC0210001));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060563AC(void)
{
    return -2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060565F8(int r4)
{
    int r0, r1, r2, r7, r9, r10, r12, r13;
    int v32;

    r13 = r4;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, 48);
    r12 = r0;
    r2 = r12;
    if ((r12 & r12) == 0) {
        r0 = -3;
    } else {
        ST16((r2 + 4), 8);
        r10 = r12 + 24;
        r4 = r12 + 28;
        r1 = LD16((r13 + 24));
        ST16((r12 + 20), r1);
        r1 = LD16((r13 + 26));
        ST16((r12 + 22), r1);
        r1 = LD16((r13 + 20));
        ST16(r10, r1);
        r1 = LD16((r13 + 22));
        ST16((r12 + 26), r1);
        ST8((r12 + 17), 6);
        ST8(8 + r12, 69);
        ST16((r12 + 10), 40);
        r1 = LD16((r13 + 28));
        ST16(r4, r1);
        r1 = LD16((r13 + 18));
        ST16((r12 + 30), r1);
        r1 = LD32(r13 + 44);
        ST32(r12 + 32, r1);
        ST8((r12 + 41), 4);
        ST32(r12 + 36, 0);
        ST8((r12 + 40), 80);
        ST16((r12 + 46), 0);
        ST16((r12 + 42), 0);
        r0 = GCALL1(0x060582A8, r4);
        r9 = r12 + 44;
        ST16(r9, 0);
        r0 = GCALL1(0x060585D8, (r12 + 8));
        ST16(r9, r0);
        r1 = LD32(0x0608D940);
        ST32(0x0608D940, (r1 + 1));
        r7 = LD16((r13 + 36));
        r1 = LD16((r13 + 38));
        r0 = GCALL5(0x06052FFC, r10, r12, 20, r7, r1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060567D8(int r4)
{
    int r0, r1, r2;

    r0 = r4;
    r1 = LD16(r0);
    r2 = r0 + 2;
    ST16(r0, r1);
    r1 = LD16(r2);
    ST16(r2, r1);
    r1 = LD32(r0 + 4);
    ST32(r0 + 4, r1);
    r1 = LD32(r0 + 8);
    r2 = r0 + 14;
    ST32(r0 + 8, r1);
    r1 = LD16(r2);
    ST16(r2, r1);
    r2 = r0 + 18;
    r1 = LD16(r2);
    ST16(r2, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056800(int r4, int r5)
{
    int r0, r1, r3, c2;

    if (r5 > 0) {
        r3 = r4 + 2;
        r0 = LD16(r3);
        r1 = r4;
        if (r0 == 3) {
            ST32((r1 + 100), 0);
            ST16(r3, 2);
        }
        r1 = LD32(172 + r4);
        c2 = (r1 & r1) == 0;
        r1 = 0;
        if (c2) {
            ST16(r3, r1);
        } else {
            r0 = GCALL1(0x06058918, r4);
        }
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056924(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x06058148, r5, r5, r6, r7);
    return -2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056938(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r1 = LD32(0x0608D890);
    r8 = (((r4 - r1) * 0x586FB587) >> 1) >> 1;
    r0 = GCALL4(0x06058784, r4, 0, r6, r7);
    r4 = LD32(0x0608D874);
    r0 = GCALL4(0x06058838, r4, 20, (4 | ((r8 << 2) + (r8 << 2))), 0x2EE0);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056F88(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10;

    r8 = r4;
    r9 = r5;
    r3 = r6;
    r5 = r7;
    r10 = r8 + 104;
    r1 = LD32(r10);
    r2 = 0;
    if (!(r1 == r3)) {
        r2 = r9 + 13;
        r0 = LD8(r2);
        if (!(((r0 & 1) & (r0 & 1)) == 0)) {
            r1 = LD32(r9 + 4);
            ST32(212 + r8, (r1 + r5));
        }
        r0 = LD8(r2);
        if (!(((r0 & 8) & (r0 & 8)) == 0)) {
            r1 = LD32(r9 + 4);
            ST32(216 + r8, (r1 + r5));
        }
        r0 = LD8(r2);
        ST8(r2, (r0 & 246));
        r0 = GCALL4(0x0605704C, r8, r3, r5, r7);
    } else {
        if (r5 > 0) {
            r0 = GCALL3(0x060570C8, r4, r5, r9);
            r1 = r8 + 14;
            r0 = LD16(r1);
            r2 = 1;
            ST16(r1, (r0 | 1));
        }
        r5 = r9 + 13;
        r0 = LD8(r5);
        r1 = r8;
        if (!(((r0 & 1) & (r0 & 1)) == 0)) {
            r1 = r1 + 14;
            r0 = LD16(r1);
            ST16(r1, (r0 | 9));
            r1 = LD32(r10);
            r2 = r2 + 1;
            ST32(r10, (r1 + 1));
        }
        r0 = LD8(r5);
        r1 = r8;
        if (!(((r0 & 8) & (r0 & 8)) == 0)) {
            r1 = r1 + 14;
            r0 = LD16(r1);
            r2 = r2 + 1;
            ST16(r1, (r0 | 128));
        }
        r5 = r8;
        if (!((r2 & r2) == 0)) {
            r0 = GCALL2(0x060583A4, 1, r5);
        }
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06057AB0(int r4, int r5, int r6, int r7)
{
    int r0;

    if (r5 == 1) {
        r0 = GCALL4(0x06057B38, r4, r5, r6, r7);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058114(int r4)
{
    int r0, r1, r2, r3;

    r1 = LD32(r4 + 40);
    r2 = LD32(172 + r4);
    r1 = r1 + r2;
    r2 = LD32(r4 + 44);
    r0 = LD16((r4 + 12));
    r3 = r1 - r2;
    if (!(((r0 & 2) & (r0 & 2)) == 0)) {
        r3 = r3 + 1;
    }
    r1 = LD16((r4 + 14));
    if (!(((r1 & 0x100) & (r1 & 0x100)) == 0)) {
        r3 = r3 + 1;
    }
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058148(int r4)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13;
    int v32;

    r1 = LD16((r4 + 4));
    r8 = r4 + r1;
    r12 = r8 + 33;
    r0 = LD8(r12);
    r11 = r8 + 20;
    if (((r0 & 4) & (r0 & 4)) == 0) {
        r0 = LD32(0x0608D3A0);
        r0 = GCALL1(r0, 48);
        r10 = r0;
        r2 = r10;
        if (!((r10 & r10) == 0)) {
            ST16((r2 + 4), 8);
            r13 = r10 + 8;
            r1 = LD16((r8 + 16));
            r9 = r10 + 28;
            ST16((r10 + 20), r1);
            r1 = LD16((r8 + 18));
            ST16((r10 + 22), r1);
            r1 = LD16((r8 + 12));
            ST16((r10 + 24), r1);
            r1 = LD16((r8 + 14));
            ST16((r10 + 26), r1);
            ST8((r10 + 17), 6);
            ST8(8 + r10, 69);
            ST16((r10 + 10), 40);
            r1 = LD16((r8 + 22));
            ST16(r9, r1);
            r1 = LD16(r11);
            ST16((r10 + 30), r1);
            r0 = LD8(r12);
            if (((r0 & 16) & (r0 & 16)) == 0) {
                ST32(r10 + 32, 0);
                r2 = r10 + 41;
                r1 = 20;
            } else {
                r1 = LD32(r8 + 28);
                r2 = r10 + 41;
                ST32(r10 + 32, r1);
                r1 = 4;
            }
            ST8(r2, r1);
            r2 = LD16((r8 + 2));
            r0 = LD8(r8);
            r2 = (r2 & 0xFFFF) - ((r0 & 15) << 2);
            r0 = LD8((r11 + 12));
            r2 = r2 - ((int)((unsigned)(r0 & 240) >> 2));
            r0 = LD8((r11 + 13));
            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                r2 = r2 + 1;
            }
            r1 = LD32(r11 + 4);
            ST32(r9 + 8, (r1 + r2));
            ST8((r9 + 12), 80);
            ST16((r9 + 18), 0);
            ST16((r9 + 14), 0);
            r0 = GCALL1(0x060582A8, r9);
            r9 = r9 + 16;
            ST16(r9, 0);
            r0 = GCALL1(0x060585D8, r13);
            ST16(r9, r0);
            r1 = LD32(0x0608D940);
            ST32(0x0608D940, (r1 + 1));
            r0 = GCALL5(0x06052FFC, (r13 + 16), r10, 20, -1, (-1));
        } else {
            r0 = -3;
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060582A8(int r4)
{
    int r0, r1, r2;

    r0 = r4;
    r1 = LD16(r0);
    r2 = r0 + 2;
    ST16(r0, r1);
    r1 = LD16(r2);
    ST16(r2, r1);
    r1 = LD32(r0 + 4);
    ST32(r0 + 4, r1);
    r1 = LD32(r0 + 8);
    r2 = r0 + 14;
    ST32(r0 + 8, r1);
    r1 = LD16(r2);
    ST16(r2, r1);
    r2 = r0 + 18;
    r1 = LD16(r2);
    ST16(r2, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060585D8(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7;

    r5 = r4 + 20;
    r7 = 0;
    r3 = r4 + 12;
    r2 = 0;
    r6 = 3;
    do {
        r1 = LD16(r3);
        r3 = r3 + 2;
        r2 = r2 + 1;
        r7 = r7 + (r1 & 0xFFFF);
    } while (AGAIN(!(r2 > r6)));
    r3 = r5;
    r0 = LD8(r4);
    r1 = LD16((r4 + 2));
    r0 = (r1 - ((r0 & 15) << 2)) & 0xFFFF;
    r7 = (r7 + 6) + r0;
    if (!(((1 & r0) & (1 & r0)) == 0)) {
        ST8(r0 + r3, 0);
        r0 = (r0 + 1) & 0xFFFF;
    }
    r0 = (int)((unsigned)r0 >> 1);
    r2 = 0;
    if (!(0 >= r0)) {
        do {
            r1 = LD16(r3);
            r3 = r3 + 2;
            r2 = r2 + 1;
            r7 = r7 + (r1 & 0xFFFF);
        } while (AGAIN(!(r2 >= r0)));
    }
    return (~((((int)((unsigned)r7 >> 16)) + (r7 & 0xFFFF)) + ((int)((unsigned)(((int)((unsigned)r7 >> 16)) + (r7 & 0xFFFF)) >> 16)))) & 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060587DC(int r4, int r5)
{
    int r0, r1, r2, r3, r7;

    r7 = LD32(0x0608D888);
    r0 = 0;
    if ((r7 & r7) == 0) {
        return r0;
    } else {
        r3 = 0x0608D868;
        r2 = LD32(0x0608D868);
        r1 = r2;
        if (!(r2 == ((int)0x80000000))) {
            ST32(r3, (r1 - 1));
        }
        r2 = r7;
        if ((r2 & r2) == 0) {
            r1 = LD32(0x0608D868);
            ST32(0x0608D868, (r1 + 1));
            return 0;
        } else {
            while (1) {
                r1 = LD32(r2);
                r0 = r0 + r1;
                r1 = LD32(r2 + 8);
                if (!(r1 == r4)) {
                    r2 = LD32(r2 + 20);
                    if (!((r2 & r2) == 0)) {
                        POLL();
                        continue;
                    } else {
                        r1 = LD32(0x0608D868);
                        ST32(0x0608D868, (r1 + 1));
                        return 0;
                    }
                } else {
                    r1 = LD32(r2 + 16);
                    if (!(r1 == r5)) {
                        r2 = LD32(r2 + 20);
                        if (!((r2 & r2) == 0)) {
                            POLL();
                            continue;
                        } else {
                            r1 = LD32(0x0608D868);
                            ST32(0x0608D868, (r1 + 1));
                            return 0;
                        }
                    } else {
                        r1 = LD32(r3);
                        ST32(r3, (r1 + 1));
                        return r0;
                    }
                }
                POLL();
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058918(int r4)
{
    ST8((r4 + 7), 1);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058A18(int r4)
{
    int r0, r1, r2, r3, r7;

    r0 = r4;
    r3 = LD32(r0 + 196);
    r1 = LD32(r0 + 192);
    r7 = r3 - r1;
    r2 = LD16(r4);
    r1 = r7;
    if (r2 > 4) {
        r0 = r4;
        if (!((r1 << 2) >= r3)) {
            r7 = 0;
        } else {
            r1 = LD32(r0 + 200);
            if (!(r7 >= r1)) {
                r7 = 0;
            }
        }
        r3 = 204;
        r2 = LD32(r4 + 204);
        r1 = LD32((r4 + 104));
        r2 = r2 - r1;
        if (!(r7 >= r2)) {
            r7 = r2;
        }
        ST32(r4 + r3, (r1 + r7));
        return r7;
    } else {
        return r7;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058A6C(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9;

    r1 = LD16((r5 + 4));
    r8 = r4;
    r2 = LD32(r8 + 56);
    r5 = r5 + r1;
    r3 = LD32(r5 + 24);
    r7 = r5 + 20;
    if (!((r3 - r2) >= 0)) {
        r0 = 1;
    } else {
        if (!(r3 == r2)) {
            r3 = LD32(r8 + 60);
            r1 = LD32(r8 + 52);
            r3 = r3 + r1;
            r1 = LD16((r7 + 14));
            r2 = LD32(r7 + 8);
            r1 = r1 & 0xFFFF;
            r2 = r2 + r1;
            ST32(r8 + 52, r1);
            r1 = LD32(r7 + 4);
            ST32(r8 + 56, r1);
            r1 = LD32(r7 + 8);
            ST32(r8 + 60, r1);
            if ((r2 - r3) > 0) {
                r9 = r8 + 2;
                r0 = LD16(r9);
                r2 = r8;
                if (r0 == 1) {
                    r1 = LD32(0x0608D890);
                    r4 = LD32(0x0608D874);
                    r0 = GCALL4(0x0605ED4C, r4, (2 | ((((((r2 - r1) * 0x586FB587) >> 1) >> 1) << 2) + (((((r2 - r1) * 0x586FB587) >> 1) >> 1) << 2))), r6, r7);
                    ST16(r9, 2);
                }
                r0 = GCALL1(0x06058918, r8);
            }
            r0 = 1;
        } else {
            r1 = LD32(r5 + 28);
            r2 = LD32(r8 + 60);
            r0 = 1;
            if ((r1 - r2) >= 0) {
                r3 = LD32(r8 + 60);
                r1 = LD32(r8 + 52);
                r3 = r3 + r1;
                r1 = LD16((r7 + 14));
                r2 = LD32(r7 + 8);
                r1 = r1 & 0xFFFF;
                r2 = r2 + r1;
                ST32(r8 + 52, r1);
                r1 = LD32(r7 + 4);
                ST32(r8 + 56, r1);
                r1 = LD32(r7 + 8);
                ST32(r8 + 60, r1);
                if ((r2 - r3) > 0) {
                    r9 = r8 + 2;
                    r0 = LD16(r9);
                    r2 = r8;
                    if (r0 == 1) {
                        r1 = LD32(0x0608D890);
                        r4 = LD32(0x0608D874);
                        r0 = GCALL4(0x0605ED4C, r4, (2 | ((((((r2 - r1) * 0x586FB587) >> 1) >> 1) << 2) + (((((r2 - r1) * 0x586FB587) >> 1) >> 1) << 2))), r6, r7);
                        ST16(r9, 2);
                    }
                    r0 = GCALL1(0x06058918, r8);
                }
                r0 = 1;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059398(int r4)
{
    int r1;

    r1 = LD32(0x0608D890);
    r1 = r1 + (r4 * 220);
    ST32(156 + r1, r4);
    ST16(r1, 0);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060593B8(void)
{
    int r0, r1, r8, r9, r10;

    ST32(0x0608D870, 1);
    ST32(0x0608D86C, 5);
    r1 = LD32(0x0608D88C);
    r8 = 0;
    r9 = 0x0608D88C;
    if (!(0 >= r1)) {
        r10 = 0x06059398;
        do {
            r0 = GCALL1(r10, r8);
            r1 = LD32(r9);
            r8 = r8 + 1;
        } while (AGAIN(!(r8 >= r1)));
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059404(void)
{
    int r0, r1, r2, r8;

    r8 = 0x06089634;
    r1 = LD32(0x06089634);
    if ((r1 & r1) == 0) {
        r0 = LD32(0x0608D39C);
        r0 = GCALL0(r0);
        ST32(r8, r0);
    }
    r2 = LD32(r8);
    r0 = r2 + 0x388;
    ST32(r8, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059434(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10, r11;

    r9 = r4;
    r1 = LD32(0x0608D890);
    r8 = r1 + (r9 * 220);
    r1 = r8 + 12;
    r2 = LD16(r1);
    ST16(r1, (r2 | 32));
    r1 = LD32(r8 + 128);
    r10 = 128;
    if (!((r1 & r1) == 0)) {
        r11 = 0x06057C88;
        r5 = 0;
        do {
            r0 = GCALL2(r11, r9, r5);
            r1 = LD32(r8 + r10);
            r5 = 0;
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    r1 = r8 + 12;
    r2 = LD16(r1);
    ST16(r1, (r2 & -33));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059A0C(int r4)
{
    int r0, r1, r2, r8, r9;

    r8 = 0x0608D87C;
    r2 = LD32(0x0608D87C);
    r9 = r4;
    if (!(r2 == ((int)0x80000000))) {
        ST32(r8, (r2 - 1));
    }
    r4 = LD32(r9 + 12);
    r1 = 0;
    if (!((r4 & r4) == 0)) {
        r1 = LD32(0x0608D390);
        r0 = GCALL1(r1, r4);
        r1 = 0;
    }
    ST32(r9, r1);
    r1 = LD32(r8);
    ST32(r8, (r1 + 1));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059A54(void)
{
    int r0, r1, r2, r3, r5, r6, r7;

    ST32(0x0608D878, 1);
    r2 = 0x0608D87C;
    ST32(0x0608D87C, 0);
    r7 = 0x0608D88C;
    r1 = LD32(0x0608D88C);
    r3 = 0;
    r6 = 0;
    if (!(0 >= (r1 + r1))) {
        r5 = 0x0608D884;
        r2 = 0;
        do {
            r0 = LD32(r5);
            r3 = r3 + 1;
            ST32(r0 + r2, r6);
            r1 = LD32(r7);
            r2 = r2 + 16;
        } while (AGAIN(!(r3 >= (r1 + r1))));
        r2 = 0x0608D87C;
    }
    r1 = LD32(r2);
    ST32(r2, (r1 + 1));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06059AA0(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, c0;

    r2 = 0x06079F68;
    r1 = LD32(0x06079F68);
    c0 = (r1 & r1) == 0;
    r4 = c0;
    if (c0) {
        ST32(r2, r4);
        ST32(0x0608D8AC, 0);
        ST32(0x0608D968, r4);
        ST32(0x0608D8EC, 119);
        ST32(0x0608D8A4, 0);
        ST32(0x0608D8F8, 0);
        ST32(0x0608D954, 0);
        ST32(0x0608D894, 0);
        ST32(0x0608D8D8, 0);
        ST32(0x0608D988, 0);
        ST32(0x0608D94C, 0);
        ST32(0x0608D930, 0);
        ST32(0x0608D984, 0);
        ST32(0x0608D93C, 0);
        ST32(0x0608D8F0, 60);
        ST32(0x0608D960, 0);
        ST32(0x0608D928, 0);
        ST32(0x0608D904, 0);
        ST32(0x0608D918, 0);
        ST32(0x0608D974, 0);
        ST32(0x0608D8E0, 0);
        ST32(0x0608D95C, 0);
        ST32(0x0608D8A0, 0);
        ST32(0x0608D8B0, 0);
        ST32(0x0608D8DC, 0);
        ST32(0x0608D898, 0);
        ST32(0x0608D934, 0);
        ST32(0x0608D910, 0);
        ST32(0x0608D958, 0);
        ST32(0x0608D944, 0);
        ST32(0x0608D8C4, 0);
        ST32(0x0608D8FC, 0);
        ST32(0x0608D914, 0);
        ST32(0x0608D8A8, 0);
        ST32(0x0608D900, 0);
        ST32(0x0608D98C, 0);
        ST32(0x0608D8B8, 0);
        ST32(0x0608D908, 0);
        ST32(0x0608D91C, 0);
        ST32(0x0608D97C, 0);
        ST32(0x0608D8B4, 0);
        ST32(0x0608D980, 0);
        ST32(0x0608D89C, 0);
        ST32(0x0608D970, 0);
        ST32(0x0608D8D0, 0);
        ST32(0x0608D92C, 0);
        ST32(0x0608D8C8, 0);
        ST32(0x0608D90C, 4);
        ST32(0x0608D8D4, 0x3E8);
        ST32(0x0608D8E4, 0x4E20);
        r2 = LD32(0x0608D88C);
        r5 = 0x0608D388;
        r0 = 144;
        r6 = 0;
        r7 = 1;
        ST32(0x0608D8F4, r2);
        ST32(0x0608D920, 0);
        ST32(0x0608D924, 0);
        ST32(0x0608D938, 0);
        ST32(0x0608D8C0, 0);
        ST32(0x0608D948, 0);
        ST32(0x0608D8E8, 0);
        ST32(0x0608D940, 0);
        ST32(0x0608D8BC, 0);
        ST32(0x0608D96C, 0);
        ST32(0x0608D8CC, 0);
        ST32(0x0608D950, 0);
        ST32(0x0608D964, 0);
        r3 = 0;
        r2 = 0;
        do {
            r1 = LD32(r5);
            r3 = r3 + 1;
            ST32(r0 + (r1 + r2), r6);
            r2 = r2 + 196;
        } while (AGAIN(!(r3 > r7)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059EBC(int r4)
{
    int r0, r1, r8, r9, r10;

    r0 = LD32(0x0608D39C);
    r9 = r4;
    r0 = GCALL1(r0, r4);
    r1 = LD32(0x0608D394);
    r10 = 0x0608D39C;
    r8 = 0x0605299C;
    r9 = r0 + (r9 * r1);
    r0 = LD32(0x0608D39C);
    while (1) {
        r0 = GCALL0(r0);
        if ((unsigned)r0 >= (unsigned)r9) {
            break;
        } else {
            r0 = GCALL0(r8);
            r0 = LD32(r10);
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059F04(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;

    r8 = r4;
    r1 = LD32(r8 + 28);
    r0 = r1;
    r9 = r5;
    if (!(r0 == -1)) {
        r0 = GCALL4(0x0605B208, r1, 0, 0, r7);
    }
    r4 = LD32(r8 + 4);
    if (!((r4 & r4) == 0)) {
        r1 = LD32(0x0608D390);
        r0 = GCALL1(r1, r4);
    }
    r4 = LD32(r8 + 24);
    r1 = 0;
    if (!((r4 & r4) == 0)) {
        r1 = LD32(0x0608D390);
        r0 = GCALL1(r1, r4);
        r1 = 0;
    }
    ST32(r8 + 4, r1);
    ST32(r8 + 24, r1);
    ST32(r8 + 28, -1);
    ST32(r8 + 8, 1);
    ST32(r8 + 12, r9);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605A290(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x06059F04, r4, -1, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605A72C(int r4)
{
    int r1, r2, r3;

    r2 = LD8(0x0608AF44);
    ST8(r4, r2);
    r3 = LD8(0x0608AF45);
    r2 = r4 + 1;
    ST8(r2, r3);
    r3 = LD8(0x0608AF46);
    r2 = r2 + 1;
    ST8(r2, r3);
    r3 = LD8(0x0608AF47);
    ST8((r2 + 1), r3);
    r2 = LD8(0x0608AF48);
    ST8((r4 + 4), r2);
    r2 = LD8(0x0608AF49);
    ST8((r4 + 5), r2);
    r2 = LD8(0x0608AF4A);
    ST8((r4 + 6), r2);
    r1 = LD8(0x0608AF4B);
    ST8((r4 + 7), r1);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605A8B0(int r4)
{
    int r1, r2, c0;

    r2 = 0x0608D9B0;
    r1 = LD32(0x0608D9B0);
    c0 = (r1 & r1) == 0;
    r1 = 0;
    if (c0) {
        return 0;
    } else {
        ST32(r2 + 4, r1);
        r1 = LD32(r2 + 8);
        ST32(r4, r1);
        return 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605A8FC(void)
{
    int r0, r4;

    r4 = LD32(0x0608D990);
    r0 = GCALL3(0x0604B3F0, r4, 0, 240);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605A91C(void)
{
    int r0, r1, r4, r8, r9, r10, r11;

    r1 = LD32(0x0608D990);
    r9 = 10;
    r11 = 0x0608D390;
    r10 = 0;
    r8 = r1 + 8;
    do {
        r4 = LD32(r8);
        if (!((r4 & r4) == 0)) {
            r1 = LD32(r11);
            r0 = GCALL1(r1, r4);
            ST32(r8, r10);
        }
        r9 = r9 - 1;
        r8 = r8 + 24;
    } while (AGAIN(r9 > 0));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605A960(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x0605A91C, 0, r5, r6, r7);
    ST32(0x0608963C, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605A97C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 32);

    r8 = r4;
    r9 = r5;
    r13 = LD32(sp);
    r10 = r6;
    r14 = LD32(sp + 4);
    r11 = r7;
    r12 = LD32(sp + 8);
    if (!((r9 & r9) == 0)) {
        r4 = LD32(r8 + 8);
        if (!((r4 & r4) == 0)) {
            r1 = LD32(0x0608D390);
            r0 = GCALL4(r1, r4, r5, r6, r7);
        }
        ST32(r8, r9);
        ST32(r8 + 4, r10);
        ST32(r8 + 8, r11);
        ST32(r8 + 20, r13);
        r1 = LD32(0x0608D394);
        r0 = 1;
        ST32(r8 + 16, r12);
        ST32(r8 + 12, ((r14 * r1) + r12));
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605AA78(int r4, int r5)
{
    int r0, r8, r9, r10, c0;

    r8 = r4;
    r9 = r5;
    r5 = LD32(r8);
    r10 = 0x06075104;
    r0 = GCALL2(0x06075104, r9, r5);
    c0 = (r0 & r0) == 0;
    r0 = c0;
    if (!(c0)) {
        r5 = LD32(r8 + 4);
        if ((r5 & r5) == 0) {
            r0 = 0;
        } else {
            r0 = GCALL2(r10, r9, r5);
            r0 = (r0 & r0) == 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605ACB8(int r4, int r5, int r6)
{
    int r0;

    r0 = GCALL4(0x0605F1D4, r4, r5, r6, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605AE6C(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, c0, c3, c4;

    r10 = r4;
    r9 = r5;
    r0 = GCALL0(0x0605F490);
    r2 = r0;
    c0 = r2 >= 0;
    r2 = r2 << 2;
    if (c0) {
        r1 = LD32(0x0608D9EC);
        r8 = r1 + ((r2 + r2) << 2);
        if (!((r9 & r9) == 0)) {
            r2 = LD32(0x0608D9E8);
            r3 = 0;
            r5 = r2;
            if (0 >= r2) {
                r0 = GCALL2(0x0605F538, r8, r10);
                r7 = r0;
                r1 = 0;
                if (!(r7 >= 0)) {
                    ST32(r8 + 4, r1);
                    r0 = r7;
                } else {
                    r0 = GCALL0(0x0605E574);
                    r7 = r0;
                    r1 = 0;
                    if (r7 >= 0) {
                        r1 = LD32(0x0608D9F0);
                        r2 = (r7 * 24) + r1;
                        ST32(r8 + 8, r9);
                        ST16((r2 + 4), r9);
                        r1 = LD32(r2 + 20);
                        r0 = LD32(r8);
                        ST32(r8 + 20, r1);
                        ST32(r8 + 24, r7);
                        ST32(r8 + 28, 9);
                    } else {
                        ST32(r8 + 4, r1);
                        r0 = r7;
                    }
                }
            } else {
                r6 = LD32(0x0608D9F0);
                r7 = 0;
                r1 = r6;
                while (1) {
                    r2 = r1;
                    r1 = LD8(r7 + r6);
                    c3 = (r1 & r1) == 0;
                    r1 = r2;
                    if (c3) {
                        r1 = r1 + 24;
                        r3 = r3 + 1;
                        r7 = r7 + 24;
                        if (!(r3 >= r5)) {
                            POLL();
                            continue;
                        } else {
                            r0 = GCALL2(0x0605F538, r8, r10);
                            r7 = r0;
                            r1 = 0;
                            if (!(r7 >= 0)) {
                                ST32(r8 + 4, r1);
                                r0 = r7;
                                break;
                            } else {
                                r0 = GCALL0(0x0605E574);
                                r7 = r0;
                                r1 = 0;
                                if (r7 >= 0) {
                                    r1 = LD32(0x0608D9F0);
                                    r2 = (r7 * 24) + r1;
                                    ST32(r8 + 8, r9);
                                    ST16((r2 + 4), r9);
                                    r1 = LD32(r2 + 20);
                                    r0 = LD32(r8);
                                    ST32(r8 + 20, r1);
                                    ST32(r8 + 24, r7);
                                    ST32(r8 + 28, 9);
                                    break;
                                } else {
                                    ST32(r8 + 4, r1);
                                    r0 = r7;
                                    break;
                                }
                            }
                        }
                    } else {
                        r1 = LD16((r1 + 4));
                        c4 = (r1 & 0xFFFF) == r9;
                        r1 = r2;
                        if (c4) {
                            r0 = -505;
                            ST32(r8 + 4, 0);
                            break;
                        } else {
                            r1 = r1 + 24;
                            r3 = r3 + 1;
                            r7 = r7 + 24;
                            if (!(r3 >= r5)) {
                                POLL();
                                continue;
                            } else {
                                r0 = GCALL2(0x0605F538, r8, r10);
                                r7 = r0;
                                r1 = 0;
                                if (!(r7 >= 0)) {
                                    ST32(r8 + 4, r1);
                                    r0 = r7;
                                    break;
                                } else {
                                    r0 = GCALL0(0x0605E574);
                                    r7 = r0;
                                    r1 = 0;
                                    if (r7 >= 0) {
                                        r1 = LD32(0x0608D9F0);
                                        r2 = (r7 * 24) + r1;
                                        ST32(r8 + 8, r9);
                                        ST16((r2 + 4), r9);
                                        r1 = LD32(r2 + 20);
                                        r0 = LD32(r8);
                                        ST32(r8 + 20, r1);
                                        ST32(r8 + 24, r7);
                                        ST32(r8 + 28, 9);
                                        break;
                                    } else {
                                        ST32(r8 + 4, r1);
                                        r0 = r7;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    POLL();
                }
            }
        } else {
            r0 = GCALL0(0x0605F4CC);
            r9 = r0 & 0xFFFF;
            r0 = GCALL2(0x0605F538, r8, r10);
            r7 = r0;
            r1 = 0;
            if (!(r7 >= 0)) {
                ST32(r8 + 4, r1);
                r0 = r7;
            } else {
                r0 = GCALL0(0x0605E574);
                r7 = r0;
                r1 = 0;
                if (r7 >= 0) {
                    r1 = LD32(0x0608D9F0);
                    r2 = (r7 * 24) + r1;
                    ST32(r8 + 8, r9);
                    ST16((r2 + 4), r9);
                    r1 = LD32(r2 + 20);
                    r0 = LD32(r8);
                    ST32(r8 + 20, r1);
                    ST32(r8 + 24, r7);
                    ST32(r8 + 28, 9);
                } else {
                    ST32(r8 + 4, r1);
                    r0 = r7;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605AF48(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r0 = r5;
    r1 = LD32(0x0608D9EC);
    r8 = 1;
    r1 = r1 + (((r4 << 2) + (r4 << 2)) << 2);
    if (r0 == 1) {
        ST32(r1 + 28, r6);
    } else {
        if (r0 == 2) {
            r4 = LD32(r1 + 20);
            r0 = GCALL4(0x0605F5E0, r4, 0x0605B1F4, 0, r7);
        } else {
            r8 = -2;
        }
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B1F4(void)
{
    int r0, r1;

    r1 = LD32(0x0608D390);
    r0 = GCALL0(r1);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B208(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10;

    r1 = LD32(0x0608D9EC);
    r8 = LD32(0x0608D9F0);
    r10 = r1 + (((r4 << 2) + (r4 << 2)) << 2);
    r2 = LD32(r10 + 24);
    r9 = r2 * 24;
    r3 = r8 + r9;
    ST16((r3 + 4), 0);
    r4 = LD32(r3 + 20);
    r1 = 0;
    if (r4 >= 0) {
        r0 = GCALL4(0x0605ECFC, r4, 0x0605B1F4, 0, r7);
        r1 = 0;
    }
    ST8(r8 + r9, r1);
    ST32(r10 + 4, 0);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B26C(int r4)
{
    int r0;

    r0 = GCALL2(0x0605B280, 1, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B280(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, c3, c7;

    r11 = r5;
    if ((r4 & r4) == 0) {
        r0 = -2;
    } else {
        r0 = -2;
        if (!((unsigned)r4 > (unsigned)1)) {
            r9 = 0x0608D388;
            r10 = 196;
            r1 = LD32(0x0608D388);
            r8 = r1 + (r4 * 196);
            r1 = LD32((r8 + 104));
            c3 = (r1 & r1) == 0;
            r1 = r8;
            if (c3) {
                r0 = GCALL1(0x060531D4, r8);
                r1 = r8;
                if (r0 == -502) {
                    r1 = LD32(r9);
                    r0 = LD8(((r1 + r10) + 30));
                    r1 = r8;
                    if (r0 == 5) {
                        r10 = 0x0605299C;
                        do {
                            r0 = GCALL0(r10);
                            r0 = LD32(r9);
                            r0 = LD8(r0 + 226);
                            r1 = r8;
                        } while (AGAIN(r0 == 5));
                    }
                }
            }
            r1 = LD32((r1 + 104));
            c7 = (r1 & r1) == 0;
            r1 = r8;
            if (c7) {
                r0 = -2;
            } else {
                r1 = LD8((r1 + 36));
                r0 = 1;
                ST8(r11, r1);
                r2 = LD8((r8 + 37));
                r1 = r11 + 1;
                ST8(r1, r2);
                r2 = LD8((r8 + 38));
                r1 = r1 + 1;
                ST8(r1, r2);
                r2 = LD8((r8 + 39));
                ST8((r1 + 1), r2);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B748(void)
{
    int r0, r8;

    r8 = LD32(0x0608D854);
    r0 = GCALL0(0x06051B18);
    r0 = GCALL0(0x0605B664);
    r0 = GCALL1(0x06051B1C, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B778(int r4)
{
    int r0, r1, r6;

    r1 = LD32(0x0608D854);
    r6 = r4 & 255;
    r4 = LD32(r1 + 60);
    r0 = GCALL3(0x06051E30, r4, 0, r6);
    ST8(0x0608D3B0, 1);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B7A4(int r4)
{
    int r0;

    r0 = GCALL2(0x06051D10, r4, 1);
    r0 = GCALL3(0x06051E30, r4, 1, (r0 | 2));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B7CC(int r4)
{
    int r0;

    r0 = GCALL2(0x06051D10, r4, 6);
    return ((r0 & 144) == 128) ^ 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B808(int r4)
{
    int r0;

    r0 = GCALL3(0x06051E30, r4, 4, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B81C(int r4)
{
    int r0;

    r0 = GCALL3(0x06051E30, r4, 1, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B830(void)
{
    return -1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B834(void)
{
    int r0, r1;

    r1 = LD32(0x0608D9C0);
    r0 = 0;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL0(r1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B850(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x0605B834, 0, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B864(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x0605B834, 1, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B878(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x0605B834, 2, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B88C(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x0605B834, 3, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B8A0(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x0605B834, 4, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B8B4(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x0605B834, 5, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605BC88(int r4)
{
    int r0, r1, r2, r5, r6, r7, r8, r9, r10;

    r8 = r4;
    r9 = r8 + 12;
    r1 = LD16(r9);
    r10 = 0;
    if (!((r1 & 0xFFFF) == 0xC023)) {
        r0 = LD32(0x0608D3A0);
        r0 = GCALL1(r0, 140);
        r5 = r0;
        r7 = r5;
        if ((r5 & r5) == 0) {
            r2 = r8 + 80;
            r1 = LD32(r2);
            ST32(r2, (r1 + 1));
        } else {
            r7 = r7 + 4;
            ST16(r7, 8);
            ST8(8 + r5, 5);
            r2 = r8 + 9;
            r1 = LD8(r2);
            r1 = r1 + 1;
            ST8(r2, r1);
            ST8((r5 + 9), r1);
            ST16((r5 + 10), 4);
            r6 = LD16(r7);
            r4 = LD16(r9);
            r0 = GCALL3(0x0605BA98, (r4 & 0xFFFF), r5, (r6 + 4));
            r10 = r0;
        }
        r1 = LD16((r8 + 12));
        r2 = r8;
        if ((r1 & 0xFFFF) == 0xC021) {
            r2 = LD32(0x0608D9C8);
            ST8(r2, 5);
            r2 = r8;
        }
        r2 = r2 + 3;
        r1 = LD8(r2);
        ST8(r2, (r1 - 1));
        r0 = LD32(0x0608D39C);
        r0 = GCALL0(r0);
        r2 = LD32(r8 + 32);
        r1 = LD32(0x0608D394);
        ST32(r8 + 28, ((r2 * r1) + r0));
        ST8((r8 + 4), 1);
        r0 = r10;
    } else {
        ST8((r8 + 3), -1);
        r0 = LD32(0x0608D39C);
        r0 = GCALL1(r0, r4);
        ST32(r8 + 28, r0);
        ST8((r8 + 4), 1);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605BD7C(int r4)
{
    int r0, r1, r2, r3, r6, r7, r8, r9;

    r8 = r4;
    r0 = LD32(0x0608D3A0);
    r9 = 0;
    r0 = GCALL1(r0, 140);
    r7 = r0;
    r3 = r7;
    if ((r7 & r7) == 0) {
        r2 = r8 + 80;
        r1 = LD32(r2);
        ST32(r2, (r1 + 1));
    } else {
        r3 = r3 + 4;
        ST16(r3, 8);
        ST8(8 + r7, 6);
        r1 = LD8((r8 + 8));
        ST8((r7 + 9), r1);
        ST16((r7 + 10), 4);
        r6 = LD16(r3);
        r4 = LD16((r8 + 12));
        r0 = GCALL3(0x0605BA98, (r4 & 0xFFFF), r7, (r6 + 4));
        r9 = r0;
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605BFA4(int r4)
{
    int r0, r1, r2, r8, r9, r10, r11, c1, c5;

    r10 = r4;
    r8 = LD32(r10 + 20);
    r2 = r8;
    if ((r8 & r8) == 0) {
        r1 = r10;
    } else {
        r2 = r2 + 1;
        r1 = LD8(r2);
        c1 = r1 >= 0;
        r1 = r10;
        if (c1) {
            r11 = 0x0606094C;
            r9 = r2;
            do {
                r0 = GCALL2(r11, r8, (r10 + 44));
                r9 = r9 + 8;
                r1 = LD8(r9);
                r8 = r8 + 8;
            } while (AGAIN(r1 >= 0));
            r1 = r10;
        }
    }
    r1 = LD16((r1 + 12));
    r2 = r1 & 0xFFFF;
    r4 = 2;
    if (!(r2 == 0xC021)) {
        if (!(r2 == 0x8021)) {
            c5 = r2 == 0xC023;
            r2 = r10;
            if (c5) {
                ST8((r2 + 11), 0);
                r4 = (int)0xC0210002;
                r1 = 0x0605DBD4;
                r0 = GCALL1(r1, r4);
            }
        } else {
            r4 = (int)0xC0230002;
            r1 = 0x0605DBD4;
            r0 = GCALL1(r1, r4);
        }
    } else {
        r1 = 0x06055000;
        r0 = GCALL1(r1, r4);
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605C040(int r4)
{
    int r0, r1, r2, c0;

    r1 = LD16((r4 + 12));
    r2 = r1 & 0xFFFF;
    c0 = r2 == 0xC021;
    r4 = c0;
    if (!(c0)) {
        if (!(r2 == 0x8021)) {
            if (r2 == 0xC023) {
                r4 = (int)0xC0210003;
                r1 = 0x0605DBD4;
                r0 = GCALL1(r1, r4);
            }
        } else {
            r4 = (int)0xC0230003;
            r1 = 0x0605DBD4;
            r0 = GCALL1(r1, r4);
        }
    } else {
        r1 = 0x06055000;
        r0 = GCALL1(r1, r4);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605C094(int r4)
{
    int r0, r1, r2, r8, r9, r10, r11, r12;

    r11 = r4;
    r12 = LD32(r11 + 40);
    r2 = LD32(0x0608D9C8);
    r1 = LD16((r12 + 2));
    r10 = r1 & 0xFFFF;
    r1 = LD16((r2 + 70));
    r1 = (r1 & 0xFFFF) - 12;
    r8 = 0;
    if (r10 > r1) {
        r10 = r1;
    }
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, (r10 + 140));
    r9 = r0;
    if ((r9 & r9) == 0) {
        r2 = r11 + 80;
        r1 = LD32(r2);
        ST32(r2, (r1 + 1));
    } else {
        r8 = r9 + 4;
        ST16(r8, 8);
        ST8(8 + r9, 7);
        r2 = r11 + 7;
        r1 = LD8(r2);
        r1 = r1 + 1;
        ST8(r2, r1);
        ST8((r9 + 9), r1);
        ST16((r9 + 10), (r10 + 4));
        r0 = GCALL3(0x0604B358, (r9 + 12), r12, r10);
        r1 = LD16(r8);
        r4 = LD16((r11 + 12));
        r0 = GCALL3(0x0605BA98, (r4 & 0xFFFF), r9, (r10 + (r1 + 4)));
        r8 = r0;
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605C14C(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10;

    r8 = r4;
    r1 = LD16((r8 + 14));
    r0 = LD32(0x0608D3A0);
    r10 = r1 & 0xFFFF;
    r0 = GCALL1(r0, (r10 + 140));
    r9 = r0;
    r1 = r9;
    if (!((r9 & r9) == 0)) {
        ST16((r1 + 4), 8);
        r0 = LD8((r8 + 2));
        r4 = r9 + 8;
        if (r0 == 2) {
            r1 = 4;
        } else {
            r1 = 3;
            if ((r0 & r0) == 0) {
                r1 = 2;
            }
        }
        ST8(r4, r1);
        r1 = LD8((r8 + 1));
        ST8((r4 + 1), r1);
        ST16((r4 + 2), (r10 + 4));
        r5 = LD32(r8 + 24);
        r0 = GCALL3(0x0604B358, (r4 + 4), r5, r10);
        r1 = LD16((r9 + 4));
        r4 = LD16((r8 + 12));
        r0 = GCALL3(0x0605BA98, (r4 & 0xFFFF), r9, (r10 + (r1 + 4)));
    } else {
        r2 = r8 + 80;
        r1 = LD32(r2);
        r0 = 0;
        ST32(r2, (r1 + 1));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605C1F4(int r4, int r5, int r6, int r7)
{
    int r0, r1;

    r1 = LD16((r4 + 12));
    r0 = 0;
    if ((r1 & 0xFFFF) == 0xC023) {
        return r0;
    } else {
        r0 = GCALL4(0x0605C14C, r4, r5, r6, r7);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605C250(int r4)
{
    int r1, r2;

    r1 = LD16((r4 + 12));
    r2 = r1 & 0xFFFF;
    if (r2 == 0xC021) {
        return;
    } else {
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605CA14(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9;

    r8 = r4;
    r2 = LD8(r8);
    r9 = 0;
    if ((unsigned)r2 > (unsigned)1) {
        r0 = GCALL4(0x0605C094, r8, r5, r6, r7);
        r9 = r0;
        r4 = LD32(r8 + 40);
    } else {
        r0 = GCALL1(0x0605C250, r4);
        r4 = LD32(r8 + 40);
    }
    if (!((r4 & r4) == 0)) {
        r1 = LD32(0x0608D390);
        r0 = GCALL1(r1, r4);
        ST32(r8 + 40, 0);
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605CA60(void)
{
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605CB04(void)
{
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605CC30(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13;

    r11 = r4;
    r1 = LD16((r6 + 4));
    r12 = r6 + r1;
    r10 = (r7 - 2) - r1;
    r1 = LD16((r11 + 70));
    r1 = (r1 & 0xFFFF) - 6;
    r13 = r5;
    if (r10 > r1) {
        r10 = r1;
    }
    r0 = LD32(0x0608D3A0);
    r0 = GCALL4(r0, (r10 + 142), r5, r6, r7);
    r9 = r0;
    r8 = r9;
    if (!((r9 & r9) == 0)) {
        r8 = r8 + 4;
        ST16(r8, 8);
        ST8(8 + r9, 8);
        r2 = r11 + 18;
        r1 = LD8(r2);
        r1 = r1 + 1;
        ST8(r2, r1);
        ST8((r9 + 9), r1);
        ST16((r9 + 10), (r10 + 6));
        ST16((r9 + 12), r13);
        r0 = GCALL3(0x0604B358, (r9 + 14), r12, r10);
        r1 = LD16(r8);
        r0 = GCALL3(0x0605BA98, 0xC021, r9, (r10 + (r1 + 6)));
    } else {
        r2 = r11 + 88;
        r1 = LD32(r2);
        ST32(r2, (r1 + 1));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605CCF0(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11;

    r11 = r6;
    r1 = LD16((r11 + 2));
    r10 = (r1 & 0xFFFF) - 4;
    r1 = LD16((r4 + 70));
    r1 = (r1 & 0xFFFF) - 4;
    r8 = r5;
    if (r10 > r1) {
        r10 = r1;
    }
    r0 = LD32(0x0608D3A0);
    r0 = GCALL3(r0, (r10 + 140), r5, r6);
    r9 = r0;
    r1 = 8;
    if (!((r9 & r9) == 0)) {
        r8 = r9 + 4;
        ST16(r8, r1);
        ST8(8 + r9, 10);
        r1 = LD8((r11 + 1));
        ST8((r9 + 9), r1);
        ST16((r9 + 10), (r10 + 4));
        r0 = GCALL3(0x0604B358, (r9 + 12), (r11 + 4), r10);
        r1 = LD16(r8);
        r0 = GCALL3(0x0605BA98, 0xC021, r9, (r10 + (r1 + 4)));
    } else {
        r2 = r8 + 80;
        r1 = LD32(r2);
        ST32(r2, (r1 + 1));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CDCC(int r4)
{
    int r1, r2, r3, r7, c2;

    r2 = LD8((r4 + 2));
    r3 = 4;
    r1 = LD8((r4 + 3));
    r2 = (((r2 << 8) | (r1 & 255)) & 0xFFFF) - 4;
    r1 = 0;
    if (!(4 >= r2)) {
        r7 = 24;
        do {
            c2 = r1 > r7;
            r1 = r1 + 1;
            if (c2) {
                r1 = 0;
            }
            r3 = r3 + 1;
        } while (AGAIN(!(r3 >= r2)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE00(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE04(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE08(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE0C(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE10(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE14(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE18(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE1C(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE20(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE24(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CE28(int r4)
{
    int r1, r2, r3, r7, c2;

    r1 = LD8((r4 + 1));
    r3 = 0;
    r1 = (r1 & 255) - 2;
    r2 = 0;
    if (!(0 >= r1)) {
        r7 = 20;
        do {
            c2 = r2 > r7;
            r2 = r2 + 1;
            if (c2) {
                r2 = 0;
            }
            r3 = r3 + 1;
        } while (AGAIN(!(r3 >= r1)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CEFC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13;

    r10 = r4;
    r13 = r6;
    r12 = r7;
    r2 = LD8((r10 + 2));
    r1 = LD8((r10 + 3));
    r8 = (((r2 << 8) | (r1 & 255)) & 0xFFFF) - 4;
    r9 = 0;
    if (r8 > 0) {
        r11 = 0x0605CEA0;
        do {
            r0 = GCALL4(r11, r10, r9, r13, r12);
            r8 = r8 - r0;
            r9 = r9 + r0;
        } while (AGAIN(r8 > 0));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D108(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D10C(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605D8A0(int r4)
{
    int r0, r8, r9, r10, c1;

    r9 = r4;
    r8 = LD32(0x0608D9C8);
    r10 = 0x0605D734;
    while (1) {
        r0 = GCALL1(r10, r8);
        if (!(((-65536 & r0) & (-65536 & r0)) == 0)) {
            break;
        } else {
            r0 = LD32(0x0608D39C);
            r0 = GCALL0(r0);
            c1 = (unsigned)r0 >= (unsigned)r9;
            r0 = 0;
            if (!(c1)) {
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DA18(int r4)
{
    int r0, r1, r5, r8, r9, r10, r11, r12;

    r10 = r4;
    r9 = 0;
    r8 = 0x0605DBD4;
    r11 = LD32(0x0608D9C8);
    r0 = GCALL1(0x0605DBD4, ((int)0x80210002));
    r12 = 0x0605D8E4;
    while (1) {
        r0 = LD32(0x0608D39C);
        r0 = GCALL0(r0);
        r5 = r10;
        if ((unsigned)r0 >= (unsigned)r10) {
            break;
        } else {
            r0 = GCALL2(r12, 0, r5);
            r9 = r0;
            if (!(r9 >= 0)) {
                break;
            } else {
                r1 = LD32(140 + r11);
                if (!((r1 & r1) == 0)) {
                    break;
                } else {
                    r0 = GCALL1(r8, ((int)0x80210001));
                    r0 = GCALL1(r8, ((int)0x80210000));
                }
            }
        }
        POLL();
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DB10(int r4)
{
    int r1, r2, c0;

    r2 = r4;
    r1 = LD8(r2);
    r2 = LD8((r2 + 1));
    c0 = (((r1 & 255) << 8) + (r2 & 255)) == 0xC021;
    r1 = r4;
    if (c0) {
        r1 = LD8((r1 + 2));
        return (unsigned)6 >= (unsigned)((r1 & 255) - 1);
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DB40(void)
{
    int r0, r8;

    r8 = LD32(0x0608D9C8);
    r0 = GCALL3(0x0604B3F0, r8, 0, 0x138);
    ST8(r8, 1);
    ST32(r8 + 28, 0x06060378);
    ST16((r8 + 20), -16351);
    ST8((r8 + 13), -1);
    ST32((r8 + 112), 0x060603A8);
    ST16((r8 + 104), -32735);
    ST8((r8 + 97), -1);
    ST32(196 + r8, 0);
    ST16(188 + r8, -16349);
    ST8(181 + r8, -1);
    r0 = GCALL1(0x0605E878, 4);
    ST32(r8 + 4, r0);
    ST32(r8 + 40, 1);
    ST32((r8 + 124), 3);
    ST32(208 + r8, 3);
    return 208;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DBD4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r1 = LD32(0x0608D9C8);
    r8 = LD32(r1 + 4);
    r0 = GCALL1(0x0605EB28, r8);
    r5 = r4;
    if (!(r0 > 3)) {
        r0 = GCALL4(0x0605EB6C, r8, r5, r6, r7);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605DC0C(void)
{
    int r0, r1;

    r1 = LD32(0x0608D9D8);
    if (!((r1 & r1) == 0)) {
        r0 = GCALL0(r1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605DC24(void)
{
    int r0, r1;

    r1 = LD32(0x0608D9D0);
    if (!((r1 & r1) == 0)) {
        r0 = GCALL0(r1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DC3C(int r4)
{
    int r0, r1, r2, r5, r6, r8, r9, r10;

    r9 = r4;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, 32);
    r8 = r0;
    r6 = 4;
    if (!((r8 & r8) == 0)) {
        r10 = 0x060752CC;
        r0 = GCALL3(0x060752CC, r9, 0x06053100, r6);
        r6 = 4;
        if ((r0 & r0) == 0) {
            r2 = r8 + 14;
            r1 = 0;
        } else {
            r5 = LD32(0x0608D388);
            r0 = GCALL3(r10, r9, (r5 + 232), r6);
            r2 = r8;
            if (!((r0 & r0) == 0)) {
                r2 = r2 + 14;
                r1 = 1;
            } else {
                r2 = r8 + 14;
                r1 = 0;
            }
        }
        ST16(r2, r1);
        ST16((r8 + 12), 0);
        r0 = r8;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DD2C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, c1;

    r0 = r4;
    if ((r0 & r0) == 0) {
        r0 = 0;
    } else {
        r4 = LD32(r0 + 4);
        c1 = r4 > 0;
        r4 = r4 - 1;
        if (c1) {
            r1 = LD32(r0 + 16);
            r7 = r4;
            r2 = r1;
            r5 = r1;
            r1 = LD32(r0 + 12);
            r8 = LD32(r2);
            r2 = r2 + 4;
            r3 = r1 + 4;
            r6 = r1;
            if (r4 > 0) {
                do {
                    r7 = r7 - 1;
                    r1 = LD32(r2);
                    r2 = r2 + 4;
                    ST32(r5, r1);
                    r1 = LD32(r3);
                    r3 = r3 + 4;
                    r5 = r5 + 4;
                    ST32(r6, r1);
                    r6 = r6 + 4;
                } while (AGAIN(r7 > 0));
            }
            ST32(r0 + 4, r4);
            r0 = r8;
        } else {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DD70(int r4)
{
    int r1, r2, r3;

    if ((r4 & r4) == 0) {
        return 0;
    } else {
        r2 = LD32(r4 + 4);
        if (!((r2 & r2) == 0)) {
            r1 = LD32(r4 + 8);
            r3 = r1 + 1;
            r1 = -1;
            if (r3 >= r2) {
                ST32(r4 + 8, r1);
                return 0;
            } else {
                r2 = LD32(r4 + 16);
                r1 = LD32((r3 << 2) + r2);
                ST32(r4 + 8, r3);
                return r1;
            }
        } else {
            return 0;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DDA0(int r4)
{
    int r0, r1, r8, r9, r10;

    r8 = r4;
    r10 = 0x0608D3A0;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, 20);
    r9 = r0;
    if ((r9 & r9) == 0) {
        r0 = 0;
    } else {
        ST32(r9, r8);
        ST32(r9 + 4, 0);
        ST32(r9 + 8, -1);
        r8 = r8 << 2;
        r0 = LD32(r10);
        r0 = GCALL1(r0, r8);
        ST32(r9 + 16, r0);
        if (!((r0 & r0) == 0)) {
            r0 = LD32(r10);
            r0 = GCALL1(r0, r8);
            ST32(r9 + 12, r0);
            if ((r0 & r0) == 0) {
                r1 = LD32(0x0608D390);
                r4 = LD32(r9 + 16);
                r0 = GCALL1(r1, r4);
                r1 = LD32(0x0608D390);
                r0 = GCALL1(r1, r9);
                r0 = 0;
            } else {
                r0 = r9;
            }
        } else {
            r1 = LD32(0x0608D390);
            r0 = GCALL1(r1, r9);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DE08(int r4)
{
    int r0, r1, r9;

    r9 = r4;
    if ((r9 & r9) == 0) {
        r0 = -1;
    } else {
        r1 = LD32(r9 + 4);
        if ((r1 & r1) == 0) {
            r1 = LD32(0x0608D390);
            r4 = LD32(r9 + 12);
            r0 = GCALL1(r1, r4);
            r1 = LD32(0x0608D390);
            r4 = LD32(r9 + 16);
            r0 = GCALL1(r1, r4);
            r1 = LD32(0x0608D390);
            r0 = GCALL1(r1, r9);
            r0 = 0;
        } else {
            r0 = -1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DE50(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;

    r2 = r4;
    r4 = r5;
    r0 = LD8((r2 + 30));
    r5 = r6;
    if (r0 == 1) {
        r1 = LD32(0x0608D388);
        if (r2 == r1) {
            r0 = GCALL1(0x06061298, r4);
        } else {
            r0 = GCALL4(0x0605DA94, r4, r5, r6, r7);
            r0 = 1;
        }
        return r0;
    } else {
        r1 = LD32(0x0608D390);
        r0 = GCALL4(r1, r4, r5, r6, r7);
        return -506;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E488(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9;

    r9 = r4;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, ((r4 << 2) + (r4 << 2)));
    ST32(0x0608D9DC, r0);
    if (!((r0 & r0) == 0)) {
        r5 = 0x0608D9E8;
        r1 = LD32(0x0608D9E8);
        r6 = 0x0608D88C;
        r2 = LD32(0x0608D88C);
        r7 = 0;
        if (!(0 >= ((r1 + r2) + 3))) {
            r4 = 1;
            r8 = 0x0608D9E4;
            r3 = 0;
            do {
                r0 = LD32(r8);
                ST8(r0 + r3, r4);
                r1 = LD32(r5);
                r7 = r7 + 1;
                r2 = LD32(r6);
                r3 = r3 + 28;
            } while (AGAIN(!(r7 >= ((r1 + r2) + 3))));
        }
        r1 = LD32(0x0608D9E8);
        r2 = LD32(0x0608D88C);
        r9 = r9 - 1;
        ST32(0x0608D9E0, ((r1 + r2) + 2));
        r2 = LD32(0x0608D9DC);
        r1 = r2;
        if (r9 > 0) {
            do {
                r1 = r1 + 8;
                ST32(r2 + 4, r1);
                r9 = r9 - 1;
                r2 = r1;
            } while (AGAIN(r9 > 0));
        }
        ST32(r2 + 4, 0);
        r0 = 0;
    } else {
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E520(int r4)
{
    int r1;

    r1 = LD32(0x0608D9EC);
    r1 = r1 + (((r4 << 2) + (r4 << 2)) << 2);
    ST32(r1, r4);
    ST32(r1 + 4, 0);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E53C(void)
{
    int r0, r1, r8, r9, r10;

    r1 = LD32(0x0608D9E8);
    r8 = 0;
    r9 = 0x0608D9E8;
    if (!(0 >= r1)) {
        r10 = 0x0605E520;
        do {
            r0 = GCALL1(r10, r8);
            r1 = LD32(r9);
            r8 = r8 + 1;
        } while (AGAIN(!(r8 >= r1)));
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E574(void)
{
    int r0, r1, r2, r3, r7, r8, r9;

    r1 = LD32(0x0608D9E8);
    r9 = 0;
    r3 = 0;
    if (0 >= r1) {
        r0 = -531;
    } else {
        r7 = 0x0608D9F0;
        r2 = 0;
        while (1) {
            r0 = LD32(r7);
            r1 = LD8(r0 + r2);
            r8 = r0 + r2;
            if (!((r1 & r1) == 0)) {
                r1 = LD32(0x0608D9E8);
                r9 = r9 + 1;
                r2 = r2 + 24;
                if (!(r9 >= r1)) {
                    POLL();
                    continue;
                } else {
                    r0 = -531;
                    break;
                }
            } else {
                ST8(r0 + r2, 1);
                ST16((r8 + 4), r3);
                ST16((r8 + 6), r3);
                ST32(r8 + 8, r3);
                ST32(r8 + 12, r3);
                ST32(r8 + 16, r3);
                r0 = GCALL1(0x0605E878, 50);
                ST32(r8 + 20, r0);
                ST8((r8 + 1), 0);
                ST8((r8 + 2), 119);
                r0 = r9;
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E638(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E64C(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x06027C18, 0, r4, r5, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605E714(int r4)
{
    int r0, r1, r5;

    if (!((unsigned)r4 > (unsigned)9)) {
        r0 = (r4 << 2) + (r4 << 2);
        r1 = LD8(r0 + 0x0605E664);
        r5 = LD32((r0 + 0x0605E664) + 4);
        ST32(0x060767E4, r1);
        r0 = GCALL2(0x060750DC, 0x060767D0, r5);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E878(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10;

    if (r4 >= 0) {
        r1 = LD32(0x0608D9E8);
        r7 = 0x0608D88C;
        r2 = LD32(0x0608D88C);
        r6 = 0;
        r10 = 0x0608D9E8;
        if (0 >= ((r1 + r2) + 3)) {
            r0 = -1;
        } else {
            r5 = 0x0608D9E0;
            r9 = r7;
            r8 = 0x0608D9E4;
            while (1) {
                r3 = LD32(r5);
                ST32(r5, (r3 - 1));
                if (!(r3 > 0)) {
                    r1 = LD32(r10);
                    r2 = LD32(r9);
                    ST32(r5, ((r1 + r2) + 2));
                }
                r1 = LD32(r8);
                r2 = (r3 * 28) + r1;
                r0 = LD8(r2);
                r6 = r6 + 1;
                if (r0 == 1) {
                    POLL();
                    ST8(r2, 3);
                    ST32(r2 + 4, r4);
                    ST32(r2 + 8, 0);
                    ST32(r2 + 24, 0);
                    ST32(r2 + 20, 0);
                    r1 = LD32(r2 + 16);
                    ST32(r2 + 12, r4);
                    r0 = r3;
                    ST32(r2 + 16, (r1 + 1));
                    break;
                } else {
                    r1 = LD32(0x0608D9E8);
                    r2 = LD32(0x0608D88C);
                    if (!(r6 >= ((r1 + r2) + 3))) {
                        POLL();
                        continue;
                    } else {
                        r0 = -1;
                        break;
                    }
                }
                POLL();
            }
        }
    } else {
        r0 = -1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605EB28(int r4)
{
    int r0, r1, r2, c1, c2;

    if (!(r4 >= 0)) {
        return -2;
    } else {
        r1 = LD32(0x0608D9E8);
        r2 = LD32(0x0608D88C);
        c1 = r4 >= ((r1 + r2) + 3);
        r1 = 28;
        if (c1) {
            return -2;
        } else {
            c2 = r4 * r1;
            r1 = LD32(0x0608D9E4);
            r1 = r1 + c2;
            r0 = LD8(r1);
            if (r0 == 3) {
                r0 = LD32(r1 + 8);
                r1 = LD32(r1 + 4);
                if (!(r1 >= 0)) {
                    r0 = r0 - r1;
                }
                return r0;
            } else {
                return -2;
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605EB6C(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10, r11;

    r11 = r5;
    if (!(r4 >= 0)) {
        r0 = -2;
    } else {
        r1 = LD32(0x0608D9E8);
        r2 = LD32(0x0608D88C);
        r0 = -2;
        if (!(r4 >= ((r1 + r2) + 3))) {
            r1 = LD32(0x0608D9E4);
            r8 = r1 + (r4 * 28);
            r0 = LD8(r8);
            if (!(r0 == 3)) {
                r0 = -2;
            } else {
                r1 = LD32(r8 + 4);
                r10 = LD32(r8 + 16);
                r1 = r1 - 1;
                ST32(r8 + 4, r1);
                if (!(r1 >= 0)) {
                    r9 = 0x0605299C;
                    do {
                        r0 = GCALL0(r9);
                        r1 = LD32(r8 + 4);
                    } while (AGAIN(!(r1 >= 0)));
                }
                r0 = LD8(r8);
                if (!(r0 == 3)) {
                    r0 = -2;
                } else {
                    r1 = LD32(r8 + 16);
                    if (!(r1 == r10)) {
                        r0 = -2;
                    } else {
                        r3 = 0x0608D9DC;
                        r2 = LD32(0x0608D9DC);
                        if (!((r2 & r2) == 0)) {
                            r1 = LD32(r2 + 4);
                            ST32(r3, r1);
                            ST32(r2 + 4, 0);
                            ST32(r2, r11);
                            r1 = LD32(r8 + 24);
                            if (!((r1 & r1) == 0)) {
                                ST32(r1 + 4, r2);
                                ST32(r8 + 24, r2);
                            } else {
                                ST32(r8 + 20, r2);
                                ST32(r8 + 24, r2);
                            }
                            r1 = LD32(r8 + 8);
                            r0 = 1;
                            ST32(r8 + 8, (r1 + 1));
                        } else {
                            r0 = -2;
                        }
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605EC14(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10, c1, c2;

    if (!(r4 >= 0)) {
        r0 = -2;
    } else {
        r1 = LD32(0x0608D9E8);
        r2 = LD32(0x0608D88C);
        c1 = r4 >= ((r1 + r2) + 3);
        r1 = 28;
        if (c1) {
            r0 = -2;
        } else {
            c2 = r4 * r1;
            r1 = LD32(0x0608D9E4);
            r8 = r1 + c2;
            r0 = LD8(r8);
            if (!(r0 == 3)) {
                r0 = -2;
            } else {
                r1 = LD32(r8 + 8);
                r10 = LD32(r8 + 16);
                r1 = r1 - 1;
                ST32(r8 + 8, r1);
                if (!(r1 >= 0)) {
                    r9 = 0x0605299C;
                    do {
                        r0 = GCALL0(r9);
                        r1 = LD32(r8 + 8);
                    } while (AGAIN(!(r1 >= 0)));
                }
                r0 = LD8(r8);
                if (!(r0 == 3)) {
                    r0 = -2;
                } else {
                    r1 = LD32(r8 + 16);
                    if (r1 == r10) {
                        r3 = LD32(r8 + 20);
                        r1 = LD32(r8 + 24);
                        r0 = LD32(r3);
                        if (!(r3 == r1)) {
                            r1 = LD32(r3 + 4);
                        } else {
                            r1 = 0;
                            ST32(r8 + 24, 0);
                        }
                        ST32(r8 + 20, r1);
                        r1 = LD32(0x0608D9DC);
                        ST32(r3 + 4, r1);
                        ST32(0x0608D9DC, r3);
                        r1 = LD32(r8 + 4);
                        ST32(r8 + 4, (r1 + 1));
                    } else {
                        r0 = -2;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605ECAC(int r4, int r5)
{
    int r0, r1, r2, c1, c2;

    if (!(r4 >= 0)) {
        return -2;
    } else {
        r1 = LD32(0x0608D9E8);
        r2 = LD32(0x0608D88C);
        c1 = r4 >= ((r1 + r2) + 3);
        r1 = 28;
        if (c1) {
            return -2;
        } else {
            c2 = r4 * r1;
            r1 = LD32(0x0608D9E4);
            r2 = c2 + r1;
            r0 = LD8(r2);
            if (r0 == 3) {
                r1 = LD32(r2 + 8);
                if (!(r1 > r5)) {
                    POLL();
                    return -2;
                } else {
                    r0 = LD32(r2 + 20);
                    r1 = r5;
                    while (1) {
                        r5 = r5 - 1;
                        if (r1 > 0) {
                            POLL();
                            r0 = LD32(r0 + 4);
                            r1 = r5;
                            continue;
                        } else {
                            break;
                        }
                    }
                    r0 = LD32(r0);
                    return r0;
                }
            } else {
                return -2;
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605ED4C(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9;

    r3 = 0x0608D868;
    r2 = LD32(0x0608D868);
    r1 = r2;
    if (!(r2 == ((int)0x80000000))) {
        ST32(r3, (r1 - 1));
    }
    r8 = LD32(0x0608D888);
    r9 = 0;
    if ((r8 & r8) == 0) {
        r1 = LD32(0x0608D868);
        ST32(0x0608D868, (r1 + 1));
        r0 = -2;
    } else {
        while (1) {
            r1 = LD32(r8 + 8);
            if (!(r1 == r4)) {
                r9 = r8;
                r8 = LD32(r8 + 20);
                if (!((r8 & r8) == 0)) {
                    POLL();
                    continue;
                } else {
                    r1 = LD32(0x0608D868);
                    ST32(0x0608D868, (r1 + 1));
                    r0 = -2;
                    break;
                }
            } else {
                r1 = LD32(r8 + 16);
                if (!(r1 == r5)) {
                    r9 = r8;
                    r8 = LD32(r8 + 20);
                    if (!((r8 & r8) == 0)) {
                        POLL();
                        continue;
                    } else {
                        r1 = LD32(0x0608D868);
                        ST32(0x0608D868, (r1 + 1));
                        r0 = -2;
                        break;
                    }
                } else {
                    r0 = LD32(0x0608D39C);
                    r0 = GCALL2(r0, r4, r5);
                    r5 = LD32(0x0608D394);
                    r0 = GCALL2(0x060745A0, ((r0 * 100) + ((int)((unsigned)r5 >> 1))), r5);
                    r1 = LD32(r8 + 4);
                    r0 = r0 - r1;
                    if ((r9 & r9) == 0) {
                        r1 = LD32(r8 + 20);
                        ST32(0x0608D888, r1);
                        r3 = LD32(r8 + 20);
                        if ((r3 & r3) == 0) {
                            r2 = LD32(0x0608D868);
                            ST32(0x0608D868, (r2 + 1));
                            ST32(r8 + 12, 0);
                            break;
                        } else {
                            r1 = LD32(r3);
                            r2 = LD32(r8);
                            ST32(r3, (r1 + r2));
                            r2 = LD32(0x0608D868);
                            ST32(0x0608D868, (r2 + 1));
                            ST32(r8 + 12, 0);
                            break;
                        }
                    } else {
                        r1 = LD32(r8 + 20);
                        ST32(r9 + 20, r1);
                        r3 = LD32(r8 + 20);
                        if ((r3 & r3) == 0) {
                            r2 = LD32(0x0608D868);
                            ST32(0x0608D868, (r2 + 1));
                            ST32(r8 + 12, 0);
                            break;
                        } else {
                            r1 = LD32(r3);
                            r2 = LD32(r8);
                            ST32(r3, (r1 + r2));
                            r2 = LD32(0x0608D868);
                            ST32(0x0608D868, (r2 + 1));
                            ST32(r8 + 12, 0);
                            break;
                        }
                    }
                }
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605EDF8(void)
{
    int r0, r1, r2;

    r1 = LD32(0x0608D88C);
    r2 = r1 + r1;
    r0 = LD32(0x0608D880);
    if (r2 > 0) {
        while (1) {
            r1 = LD32(r0 + 12);
            if ((r1 & r1) == 0) {
                break;
            } else {
                r2 = r2 - 1;
                r0 = r0 + 24;
                if (r2 > 0) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    if ((r2 & r2) == 0) {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605EE28(int r4, int r5)
{
    int r0, r1, r2, r8;

    r8 = r4;
    if ((r5 & r5) == 0) {
        ST16(r8, 0);
        ST32(r8 + 8, ((int)0x80000000));
        r0 = -2;
    } else {
        ST16((r8 + 4), 1);
        ST16((r8 + 28), r5);
        ST16(r8, 2);
        r4 = LD32(0x0608D86C);
        ST32(r8 + 140, r4);
        r0 = GCALL1(0x0605E878, r4);
        r2 = r0;
        r0 = r8;
        ST32(r0 + 144, r2);
        ST32((r8 + 72), 0);
        r1 = LD32(r8 + 8);
        ST32(r8 + 8, (r1 + 1));
        r0 = LD32(r0 + 156);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605F0E4(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12;

    r10 = r4;
    r8 = r5;
    r9 = 0;
    if ((r8 & r8) == 0) {
        r1 = 3;
        r2 = 0;
        if (!(r9 > 3)) {
            r0 = r10;
            do {
                ST8(r0 + r9, r2);
                r9 = r9 + 1;
            } while (AGAIN(!(r9 > r1)));
        }
    } else {
        r12 = 0x06075438;
        r11 = 0x060754B8;
        while (!(r9 > 3)) {
            r0 = GCALL1(r12, r8);
            ST8(r10 + r9, r0);
            r0 = GCALL2(r11, r8, 46);
            r8 = r0;
            if (!((r8 & r8) == 0)) {
                r8 = r8 + 1;
            }
            r9 = r9 + 1;
            if (!((r8 & r8) == 0)) {
                POLL();
                continue;
            } else {
                r1 = 3;
                r2 = 0;
                if (r9 > 3) {
                    break;
                } else {
                    r0 = r10;
                    do {
                        ST8(r0 + r9, r2);
                        r9 = r9 + 1;
                    } while (AGAIN(!(r9 > r1)));
                    break;
                }
            }
            POLL();
        }
    }
    return r10;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605F490(void)
{
    int r0, r1, r2, r3, r5, r6, r7, c1;

    r1 = LD32(0x0608D9E8);
    r0 = 0;
    r7 = 0x0608D9E8;
    if (0 >= r1) {
        return -531;
    } else {
        r6 = 0x0608D9EC;
        r3 = 0;
        while (1) {
            r1 = LD32(r6);
            r2 = r1 + r3;
            r1 = LD32(r2 + 4);
            c1 = (r1 & r1) == 0;
            r5 = c1;
            if (!(c1)) {
                r1 = LD32(r7);
                r0 = r0 + 1;
                r3 = r3 + 32;
                if (!(r0 >= r1)) {
                    POLL();
                    continue;
                } else {
                    return -531;
                }
            } else {
                ST32(r2 + 4, r5);
                return r0;
            }
            POLL();
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605F5E0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, c1, c2;

    if (!(r4 >= 0)) {
        r0 = -2;
    } else {
        r1 = LD32(0x0608D9E8);
        r2 = LD32(0x0608D88C);
        c1 = r4 >= ((r1 + r2) + 3);
        r1 = 28;
        if (c1) {
            r0 = -2;
        } else {
            c2 = r4 * r1;
            r1 = LD32(0x0608D9E4);
            r4 = r1 + c2;
            r0 = LD8(r4);
            r6 = r5;
            if (r0 == 3) {
                r0 = GCALL4(0x06061940, r4, 3, r6, r7);
                r0 = 1;
            } else {
                r0 = -2;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605F634(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, c2, c3;

    r8 = r4;
    r11 = r5;
    if (r8 >= 0) {
        r0 = LD32(0x0608D39C);
        r0 = GCALL2(r0, r4, r5);
        r1 = LD32(0x0608D394);
        r10 = 0x0605299C;
        r2 = LD32(0x0605F630);
        r9 = 0x0605EB28;
        r8 = r0 + ((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)((r8 * r1) + 5) * (unsigned)r2)) >> 32)) >> 2)) >> 1));
        while (1) {
            r0 = GCALL0(r10);
            r0 = LD32(0x0608D39C);
            r0 = GCALL0(r0);
            c2 = (unsigned)r0 >= (unsigned)r8;
            r0 = -3;
            if (c2) {
                break;
            } else {
                r0 = GCALL1(r9, r11);
                c3 = r0 > 0;
                r0 = c3;
                if (!(c3)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    } else {
        r0 = -2;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605F844(int r4, int r5)
{
    int r0, r1, r6, r8, r9, r10, r11, r12, r13;

    r11 = r4;
    r10 = r5;
    r9 = r11;
    r8 = 0;
    r13 = 0x06045264;
    r12 = 0x0607507C;
    do {
        r1 = LD8(r10 + r8);
        r5 = 0x0605F840;
        r6 = r1 & 255;
        if ((r8 & r8) == 0) {
            r5 = 0x0605F83C;
        }
        r0 = GCALL3(r13, r9, r5, r6);
        r0 = GCALL1(r12, r9);
        r8 = r8 + 1;
        r9 = r9 + r0;
    } while (AGAIN(!(r8 > 3)));
    ST8(r9, 0);
    return r11;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06051C30(int r4)
{
    int r0, r9, r10, r11, c0, c1;

    r9 = r4;
    r11 = 0x06051E30;
    r4 = LD32(r9 + 60);
    r0 = GCALL3(0x06051E30, r4, 7, 90);
    r10 = 0x06051D10;
    r4 = LD32(r9 + 60);
    r0 = GCALL2(0x06051D10, r4, 7);
    c0 = r0 == 90;
    r0 = 0;
    if (c0) {
        r4 = LD32(r9 + 60);
        r0 = GCALL3(r11, r4, 7, 161);
        r4 = LD32(r9 + 60);
        r0 = GCALL2(r10, r4, 7);
        c1 = r0 == 161;
        r0 = 0;
        if (c1) {
            r0 = 1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06052F04(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r10, r11, c3;
    FRAME(sp, 28);

    r10 = r4;
    r9 = r6;
    r1 = LD16((r10 + 4));
    r4 = r4 + r1;
    if (!((r5 & r5) == 0)) {
        r1 = LD16((r9 + 14));
        r11 = r4;
        if (r5 == r1) {
            r11 = r11 + 12;
            r0 = GCALL4(0x0605DC3C, r11, 1, r6, r7);
            r1 = r0;
            if (!((r0 & r0) == 0)) {
                r1 = LD16((r1 + 12));
                c3 = (r1 & r1) == 0;
                r1 = LD32(0x0608D390);
                r0 = GCALL1(r1, r0);
                r5 = r9;
                if (!((c3 & c3) == 0)) {
                    r0 = GCALL2(0x0605E358, (sp - 24), r5);
                    r0 = GCALL3(0x060752CC, (r9 + 4), (sp - 24), 4);
                    r5 = 1;
                    if ((r0 & r0) == 0) {
                        r5 = 0;
                    }
                    ST32((sp - 28), (r9 + 8));
                    r0 = GCALL5(0x0605DEA4, 5, ((short)r5), r11, r10, LD32((sp - 28)));
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605381C(void)
{
    int r0, r1, r2, r3, r5, r6, r7, c2;

    r6 = LD32(0x0608D854);
    r7 = 0;
    r0 = LD8((r6 + 9));
    r3 = 0;
    if (r0 >= 0) {
        r5 = 29;
        while (1) {
            r1 = r0;
            if (r3 > r5) {
                break;
            } else {
                r2 = r6 + ((r1 << 2) + (r1 << 2));
                r1 = LD8((r2 + 98));
                c2 = (((signed char)r1) & ((signed char)r1)) == 0;
                r1 = r2;
                if (c2) {
                    r7 = 1;
                    POLL();
                    break;
                } else {
                    r1 = LD8((r1 + 96));
                    r0 = (signed char)r1;
                    r3 = r3 + 1;
                    if (r0 >= 0) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
            }
            POLL();
        }
    }
    r1 = r0;
    if ((r7 & r7) == 0) {
        return -1;
    } else {
        r3 = r6 + ((r1 << 2) + (r1 << 2));
        ST8((r3 + 98), 1);
        r1 = LD32(r6 + 44);
        ST16((r3 + 92), ((r1 + -332) - r6));
        ST16((r3 + 94), 0);
        r2 = r6 + 8;
        r1 = LD8(r2);
        ST8(r2, (r1 - 1));
        r1 = LD8(r2);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06053BA8(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, c2;

    ST8((r4 + 6), 0);
    ST32(r4 + 56, -1025);
    ST8((r4 + 13), 0);
    ST8((r4 + 8), 30);
    r8 = r4 + 92;
    r2 = 1;
    r9 = 30;
    r0 = 0;
    r5 = r4 + 98;
    r6 = r4 + 97;
    r7 = r4 + 96;
    r3 = r4 + 94;
    do {
        ST16(r8, r0);
        ST16(r3, r0);
        ST8(r7, r2);
        ST8(r6, (r2 - 2));
        ST8(r5, r0);
        r5 = r5 + 8;
        r6 = r6 + 8;
        r7 = r7 + 8;
        r3 = r3 + 8;
        r2 = r2 + 1;
        r8 = r8 + 8;
    } while (AGAIN(!(r2 > r9)));
    ST8((r8 - 4), -1);
    ST8((r4 + 9), 0);
    ST8((r4 + 10), 29);
    ST8((r4 + 11), -1);
    ST8((r4 + 12), 0);
    r8 = r4 + 92;
    r1 = LD32(r4 + 48);
    ST16(r8, ((r1 + -332) - r4));
    ST8((r4 + 98), 3);
    r0 = (SR() & ~1) | 1;
    r7 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = (SR() & ~1) | 1;
    r0 = r0 | 240;
    SETSR(r0);
    r2 = LD32(r4 + 44);
    r1 = LD32(r4 + 48);
    r6 = r2 - r1;
    r1 = LD16((r4 + 20));
    r5 = r1 & 0xFFFF;
    ST8((r4 + 6), 1);
    r1 = SR();
    SETSR(((r1 & -241) | ((r7 << 2) << 2)));
    c2 = (r6 & r6) == 0;
    if (r6 >= 0) {
        r1 = r8;
        if (c2) {
            r1 = 0xBB8;
            if (r5 == 0xBB8) {
                r6 = r1;
            }
            r1 = r8;
        }
    } else {
        r6 = r6 + 0xBB8;
        r1 = r8;
    }
    ST16((r1 + 2), r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060552F0(int r4)
{
    int r0, r1, r5, r6, r8, r9, c1;

    r9 = r4;
    r1 = LD8((r9 + 3));
    c1 = (r1 & r1) == 0;
    if (r1 >= 0) {
        if (!(c1)) {
            r1 = LD8(0x0608AD42);
            r6 = 2;
            if (!((r1 & r1) == 0)) {
                r5 = 0x060552E8;
                r1 = 0x06055160;
                r0 = GCALL3(r1, r9, r5, r6);
            }
        } else {
            r8 = 0x0608AEA4;
            r0 = GCALL1(0x0607507C, 0x0608AEA4);
            r0 = LD8(((r0 + 0x0608AEA4) - 1));
            if (!(r0 == 13)) {
                r0 = GCALL2(0x06075408, r8, 0x06054B54);
            }
            r1 = 0x06055160;
            r6 = 2;
            r5 = r8;
            r0 = GCALL3(r1, r9, r5, r6);
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055360(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r9, r10, r11, r12, c4;

    r9 = r4;
    r11 = r5;
    r12 = r6;
    r0 = GCALL2(0x060754B8, r4, 40);
    r10 = r0;
    r0 = GCALL2(0x060754B8, r9, 41);
    r3 = r0;
    if ((r10 & r10) == 0) {
        r0 = GCALL2(0x060750DC, r12, r9);
        ST8(r11, 0);
    } else {
        r2 = r10;
        if (!((r3 & r3) == 0)) {
            r2 = r2 + 1;
            r5 = r11;
            if (!((unsigned)r2 >= (unsigned)r3)) {
                r7 = 0x06075135;
                do {
                    r1 = LD8(r2);
                    r2 = r2 + 1;
                    r6 = LD8(r1 + r7);
                    r0 = 8;
                    c4 = (unsigned)r2 >= (unsigned)r3;
                    if (((r6 & 8) & (r6 & 8)) == 0) {
                        ST8(r5, r1);
                        r5 = r5 + 1;
                    }
                } while (AGAIN(!(c4)));
            }
            ST8(r5, 0);
            r2 = r3 + 1;
            r1 = LD8(r2);
            r2 = r2 + 1;
            r5 = r12;
            if (!((r1 & r1) == 0)) {
                r3 = 0x06075135;
                r0 = r1;
                do {
                    r7 = LD8(r0 + r3);
                    if (((r7 & 8) & (r7 & 8)) == 0) {
                        ST8(r5, r1);
                        r5 = r5 + 1;
                    }
                    r1 = LD8(r2);
                    r2 = r2 + 1;
                    r0 = r1;
                } while (AGAIN(!((r1 & r1) == 0)));
            }
            ST8(r5, 0);
        } else {
            r0 = GCALL2(0x060750DC, r12, r9);
            ST8(r11, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055594(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11;

    r10 = r4;
    r8 = 0x0605DC0C;
    r0 = GCALL4(0x0605DC0C, 8, r5, r6, r7);
    r11 = 0x0605B7E8;
    r4 = LD32(r10 + 60);
    r0 = GCALL1(0x0605B7E8, r4);
    if (!((r0 & r0) == 0)) {
        r4 = LD32(r10 + 60);
        r0 = GCALL1(0x0605B808, r4);
        r8 = 0x0608D39C;
        r0 = LD32(0x0608D39C);
        r0 = GCALL1(r0, r4);
        r1 = LD32(0x0608D394);
        r9 = r0 + (r1 + r1);
        while (1) {
            r4 = LD32(r10 + 60);
            r0 = GCALL1(r11, r4);
            if ((r0 & r0) == 0) {
                break;
            } else {
                r0 = LD32(r8);
                r0 = GCALL0(r0);
                if (!((unsigned)r0 >= (unsigned)r9)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        r4 = LD32(r10 + 60);
        r0 = GCALL1(r11, r4);
        if (!((r0 & r0) == 0)) {
            r0 = LD32(0x0608D3A0);
            r0 = GCALL1(r0, 3);
            r7 = r0;
            r3 = r7;
            if (!((r7 & r7) == 0)) {
                ST8((r7 + 2), 43);
                ST8((r3 + 1), 43);
                ST8(r7, 43);
                r0 = GCALL4(0x06054010, r7, 3, 0, r7);
            }
            r8 = 0x0608D39C;
            r0 = LD32(0x0608D39C);
            r0 = GCALL0(r0);
            r1 = LD32(0x0608D394);
            r9 = r0 + (r1 + r1);
            do {
                r0 = LD32(r8);
                r0 = GCALL0(r0);
            } while (AGAIN(!((unsigned)r0 >= (unsigned)r9)));
            r0 = LD32(0x0608D3A0);
            r0 = GCALL1(r0, 5);
            r7 = r0;
            r6 = 0;
            if (!((r7 & r7) == 0)) {
                r2 = LD8(0x0605558C);
                ST8(r7, r2);
                r3 = LD8(0x0605558D);
                r2 = r7 + 1;
                ST8(r2, r3);
                r3 = LD8(0x0605558E);
                r2 = r2 + 1;
                ST8(r2, r3);
                r3 = LD8(0x0605558F);
                r2 = r2 + 1;
                ST8(r2, r3);
                r1 = LD8(0x06055590);
                ST8((r2 + 1), r1);
                r0 = GCALL4(0x06054010, r7, 5, r6, r7);
            }
        }
    } else {
        r0 = LD32(0x0608D3A0);
        r0 = GCALL1(r0, 1);
        r7 = r0;
        r1 = 13;
        if (!((r7 & r7) == 0)) {
            ST8(r7, r1);
            r0 = GCALL4(0x06054010, r7, 1, 0, r7);
        }
        r0 = GCALL1(r8, 9);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605785C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11;

    r10 = r4;
    r8 = r5;
    r1 = LD16((r6 + 4));
    r6 = r6 + r1;
    r1 = LD16((r6 + 34));
    ST32(r8 + 52, (r1 & 0xFFFF));
    r1 = LD32(r6 + 24);
    r11 = r6 + 20;
    ST32(r8 + 56, r1);
    r1 = LD32((r8 + 76));
    ST32(r8 + 60, r1);
    r0 = GCALL4(0x0605DC3C, (r6 + 12), 0, (r6 + 12), r7);
    r7 = r0;
    r9 = 0;
    if (!((r7 & r7) == 0)) {
        r1 = LD16((r7 + 12));
        if ((r1 & r1) == 0) {
            r9 = 1;
        }
    }
    r2 = LD16((r7 + 14));
    r1 = LD32(0x0608D388);
    ST32(r8 + 32, (r1 + ((short)r2 * (short)196)));
    r1 = LD32(0x0608D390);
    r0 = GCALL4(r1, r7, 0, 0, r7);
    if ((r9 & r9) == 0) {
        r2 = 0x12C;
    } else {
        r1 = LD32(r8 + 32);
        r1 = LD32(r1 + 32);
        r2 = r1 - 40;
    }
    r4 = r10 + 72;
    r1 = LD32(r4);
    r3 = r8;
    if ((r1 & r1) == 0) {
        ST32((r8 + 72), r2);
    } else {
        r3 = r3 + 72;
        if (r1 > r2) {
            r1 = r2;
        }
        ST32(r3, r1);
        ST32(r4, 0);
    }
    r0 = r8;
    ST32(r0 + 200, r2);
    r1 = LD32((r8 + 72));
    ST32((r8 + 64), r1);
    ST32((r8 + 68), 0xFFFF);
    r2 = LD32(r11 + 4);
    ST32((r8 + 104), r2);
    r1 = LD32(r0 + 196);
    ST32(r0 + 204, (r2 + r1));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06057ACC(int r4, int r5)
{
    int r0, r1, r2, r7, r8, r9;

    r8 = r4;
    r1 = LD32(0x0608D890);
    r9 = r1 + (r8 * 220);
    if (r5 == 2) {
        r0 = GCALL2(0x06057C88, r8, 1);
        r2 = r9 + 88;
        r1 = LD32(r2);
        r7 = r1 + r1;
        r1 = 0x1770;
        if (r7 > 0x1770) {
            r7 = r1;
        }
        ST32(r2, r7);
        r4 = LD32(0x0608D874);
        r0 = GCALL4(0x06058838, r4, 20, (2 | ((r8 << 2) + (r8 << 2))), r7);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060583A4(int r4, int r5)
{
    int r0, r1, r2, r3, r7, c2, c4, c5, c7, c8, c11;

    r2 = r4;
    r1 = r5;
    if (((1 & r2) & (1 & r2)) == 0) {
        r0 = r2;
    } else {
        r0 = LD16((r1 + 14));
        if (!(((r0 & 8) & (r0 & 8)) == 0)) {
            r3 = 180;
            r0 = r5;
            r1 = LD32(r0 + 180);
            c4 = r1 > 0;
            r1 = r1 + 1;
            if (!(c4)) {
                ST32(r0 + r3, r1);
            }
            r0 = r2;
        } else {
            r1 = LD32(192 + r5);
            c2 = r1 > 0;
            r1 = r5;
            if (c2) {
                r3 = 180;
                r0 = r5;
                r1 = LD32(r0 + 180);
                c4 = r1 > 0;
                r1 = r1 + 1;
                if (!(c4)) {
                    ST32(r0 + r3, r1);
                }
                r0 = r2;
            } else {
                r1 = LD32((r1 + 112));
                r0 = r2;
                if (!((r1 & r1) == 0)) {
                    r3 = 180;
                    r0 = r5;
                    r1 = LD32(r0 + 180);
                    c4 = r1 > 0;
                    r1 = r1 + 1;
                    if (!(c4)) {
                        ST32(r0 + r3, r1);
                    }
                    r0 = r2;
                }
            }
        }
    }
    c5 = ((r0 & 2) & (r0 & 2)) == 0;
    r0 = r5;
    if (!(c5)) {
        r1 = LD32(r0 + 176);
        r2 = LD32(r0 + 172);
        r2 = r1 - r2;
        r1 = LD16((r5 + 14));
        c7 = r2 > 0;
        if (!(((r1 & 16) & (r1 & 16)) == 0)) {
            r2 = 160;
            r0 = r5;
            r1 = LD32(r0 + 160);
            c8 = r1 > 0;
            r1 = r1 + 1;
            if (!(c8)) {
                ST32(r0 + r2, r1);
            }
            r1 = r5;
        } else {
            r1 = r5;
            if (c7) {
                r2 = 160;
                r0 = r5;
                r1 = LD32(r0 + 160);
                c8 = r1 > 0;
                r1 = r1 + 1;
                if (!(c8)) {
                    ST32(r0 + r2, r1);
                }
                r1 = r5;
            }
        }
        r1 = LD16((r1 + 16));
        r0 = r5;
        if (!((r1 & r1) == 0)) {
            r7 = 152;
            r3 = LD32(r0 + 152);
            r1 = r5;
            if (!(r3 == ((int)0x80000000))) {
                r1 = LD16((r1 + 14));
                c11 = ((r1 & 0x200) & (r1 & 0x200)) == 0;
                r1 = r3;
                if (c11) {
                    ST32(r0 + r7, (r1 + 1));
                }
            }
        }
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058B18(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, c3, c7;

    r6 = r6 + 1;
    r1 = LD8(r6);
    r6 = r6 + 1;
    r0 = LD8((r5 + 13));
    r3 = r1 & 255;
    if (!(((r0 & 2) & (r0 & 2)) == 0)) {
        r0 = r3 - 2;
        if (r0 == 2) {
            r2 = LD8(r6);
            r1 = LD8((r6 + 1));
            r1 = ((r2 << 8) | (r1 & 255)) & 0xFFFF;
        } else {
            c3 = r0 == 1;
            if ((unsigned)r0 > (unsigned)2) {
                r1 = r6;
                if (r0 == 4) {
                    r2 = LD8(r1);
                    r1 = LD8((r1 + 1));
                    r2 = ((r2 << 16) << 8) | ((r1 & 255) << 16);
                    r1 = LD8((r6 + 2));
                    r2 = r2 | ((r1 & 255) << 8);
                    r1 = LD8((r6 + 3));
                    r1 = (r1 & 255) | r2;
                } else {
                    r1 = r4;
                    r1 = LD32((r1 + 72));
                }
            } else {
                if (c3) {
                    r1 = LD8(r6);
                    r1 = r1 & 255;
                } else {
                    r1 = r4;
                    r1 = LD32((r1 + 72));
                }
            }
        }
        r1 = r1 - 20;
        r2 = 0x7FFFFFFF;
        if ((unsigned)r1 > (unsigned)0x7FFFFFFF) {
            r1 = r2;
        }
        r4 = r4 + 72;
        r2 = LD32(r4);
        c7 = r1 >= r2;
        if (!((r2 & r2) == 0)) {
            if (c7) {
                r1 = r2;
            }
        }
        ST32(r4, r1);
        return r3;
    } else {
        return r3;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058BB0(int r4, int r5)
{
    int r0, r1, r2, r6, r8, r9, r10, r11, r12, r13, r14, c2, c3, c7;

    r13 = r4;
    r1 = LD16((r5 + 4));
    r9 = r5 + r1;
    r0 = LD8((r9 + 32));
    r1 = 240 & r0;
    r11 = r9 + 20;
    if (!(((int)((unsigned)r1 >> 2)) == 20)) {
        r8 = r9 + 40;
        r10 = r9 + (((int)((unsigned)r1 >> 2)) + 20);
        r12 = 1;
        r14 = 0x06058B18;
        while (1) {
            r1 = LD8(r8);
            r0 = r1 & 255;
            c2 = r0 > r12;
            if (r0 == 1) {
                r8 = r8 + 1;
                r1 = LD8(r8);
                r1 = r1 & 255;
            } else {
                c3 = (r0 & r0) == 0;
                if (c2) {
                    r6 = r8;
                    if (r0 == 2) {
                        r0 = GCALL3(r14, r13, r11, r6);
                        r8 = r8 + r0;
                    } else {
                        r1 = r8;
                        r1 = LD8((r1 + 1));
                        r1 = r1 & 255;
                        if (!(r1 > r12)) {
                            r1 = r10 - r8;
                        }
                        r8 = r8 + r1;
                    }
                    r1 = LD8(r8);
                    r1 = r1 & 255;
                } else {
                    r1 = r1 & 255;
                    if (!(c3)) {
                        r1 = r8;
                        r1 = LD8((r1 + 1));
                        r1 = r1 & 255;
                        if (!(r1 > r12)) {
                            r1 = r10 - r8;
                        }
                        r8 = r8 + r1;
                        r1 = LD8(r8);
                        r1 = r1 & 255;
                    }
                }
            }
            c7 = (unsigned)r8 >= (unsigned)r10;
            if ((r1 & r1) == 0) {
                break;
            } else {
                if (!(c7)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        r12 = r9 + 2;
        r2 = LD16(r12);
        r10 = r11 + 12;
        r0 = LD8(r9);
        r2 = (r2 & 0xFFFF) - ((r0 & 15) << 2);
        r0 = LD8(r10);
        r0 = r0 & 240;
        r8 = r2 - ((int)((unsigned)r0 >> 2));
        r4 = r11;
        if (!((r8 & r8) == 0)) {
            r0 = GCALL3(0x0604B358, (r4 + 20), ((((int)((unsigned)r0 >> 2)) + r9) + 20), r8);
        }
        r0 = LD8(r9);
        ST16(r12, ((((r0 & 15) << 2) + 20) + r8));
        ST8(r10, 80);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059968(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, c3;

    r1 = LD32(0x0608D878);
    if ((r1 & r1) == 0) {
        r0 = GCALL0(0x06059A54);
    }
    r3 = 0x0608D87C;
    r2 = LD32(0x0608D87C);
    r1 = r2;
    if (!(r2 == ((int)0x80000000))) {
        ST32(r3, (r1 - 1));
    }
    r1 = LD32(0x0608D88C);
    r7 = 0;
    r4 = 0x0608D88C;
    if (0 >= (r1 + r1)) {
        r1 = LD32(0x0608D87C);
        ST32(0x0608D87C, (r1 + 1));
        r0 = -2;
    } else {
        r6 = 0x06089638;
        r8 = 0x0608D884;
        r5 = r3;
        while (1) {
            r2 = LD32(r6);
            r2 = r2 + 1;
            ST32(r6, r2);
            r1 = LD32(r4);
            c3 = r2 >= (r1 + r1);
            r1 = 0;
            if (c3) {
                ST32(r6, r1);
            }
            r1 = LD32(r6);
            r0 = LD32(r8);
            r2 = (r1 << 2) << 2;
            r1 = LD32(r0 + r2);
            r3 = r0 + r2;
            if (!((r1 & r1) == 0)) {
                r1 = LD32(r4);
                r7 = r7 + 1;
                if (!(r7 >= (r1 + r1))) {
                    POLL();
                    continue;
                } else {
                    r1 = LD32(0x0608D87C);
                    ST32(0x0608D87C, (r1 + 1));
                    r0 = -2;
                    break;
                }
            } else {
                ST32(r0 + r2, 1);
                r1 = LD32(r5);
                ST32(r5, (r1 + 1));
                r0 = r3;
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605A6B8(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10;
    FRAME(sp, 60);

    r9 = r4;
    r0 = GCALL3(0x0605A15C, r5, (sp - 60), -1);
    r8 = 0x0605A2A8;
    r10 = 0x0605A290;
    while (1) {
        r0 = GCALL1(r8, (sp - 60));
        r2 = r9;
        if (!((r0 & r0) == 0)) {
            break;
        } else {
            r0 = GCALL0(0x0605215C);
            if ((r0 & r0) == 0) {
                POLL();
                continue;
            } else {
                r0 = GCALL1(r10, (sp - 60));
                r0 = -1;
                r2 = r9;
                break;
            }
        }
        POLL();
    }
    r1 = LD8(sp - 60);
    r2 = r2 + 1;
    ST8(r9, r1);
    r1 = (sp - 60) + 1;
    r3 = LD8(r1);
    r1 = r1 + 1;
    ST8(r2, r3);
    r3 = LD8(r1);
    r2 = r2 + 1;
    ST8(r2, r3);
    r1 = LD8((r1 + 1));
    ST8((r2 + 1), r1);
    if (r0 >= 0) {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605A8CC(int r4)
{
    int r0, r1, r2, c1;

    r2 = 0x0608D9B0;
    r0 = LD32(0x0608D9B0);
    c1 = r0 == 1;
    if (!((r0 & r0) == 0)) {
        if (c1) {
            r1 = LD32(r2 + 8);
            ST32(r4, r1);
            r1 = 0;
        } else {
            r0 = LD32(r2 + 4);
            if (!(r0 == 1)) {
                r1 = LD32(r2 + 12);
                ST32(r4, r1);
                r1 = 1;
            } else {
                r1 = LD32(r2 + 8);
                ST32(r4, r1);
                r1 = 0;
            }
        }
        ST32(r2 + 4, r1);
        return 1;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605A9E4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, c2;
    FRAME(sp, 40);

    r11 = r4;
    r10 = r5;
    r9 = r6;
    r12 = LD32(sp);
    r0 = LD32(0x0608D39C);
    r8 = r7;
    r0 = GCALL4(r0, r4, r5, r6, r7);
    r6 = r0;
    r1 = LD32(0x0608D990);
    if (!((r12 & r12) == 0)) {
        r4 = r1;
        r7 = 10;
        r13 = 0x0605A97C;
        r3 = r1;
        while (1) {
            r2 = LD32(r3 + 12);
            c2 = (unsigned)r2 > (unsigned)r0;
            if ((r2 & r2) == 0) {
                ST32((sp - 32), r0);
                ST32((sp - 36), r12);
                ST32((sp - 40), r8);
                r0 = GCALL7(r13, r4, r11, r10, r9, LD32((sp - 40)), LD32((sp - 36)), LD32((sp - 32)));
                break;
            } else {
                if (c2) {
                    r2 = LD32(r3 + 16);
                    if (!((unsigned)r2 >= (unsigned)r6)) {
                        r1 = r3;
                        r6 = r2;
                    }
                    r3 = r3 + 24;
                    r7 = r7 - 1;
                    r4 = r4 + 24;
                    if (r7 > 0) {
                        POLL();
                        continue;
                    } else {
                        ST32((sp - 32), r0);
                        ST32((sp - 36), r12);
                        ST32((sp - 40), r8);
                        r0 = GCALL7(0x0605A97C, r1, r11, r10, r9, LD32((sp - 40)), LD32((sp - 36)), LD32((sp - 32)));
                        break;
                    }
                } else {
                    ST32((sp - 32), r0);
                    ST32((sp - 36), r12);
                    ST32((sp - 40), r8);
                    r0 = GCALL7(r13, r4, r11, r10, r9, LD32((sp - 40)), LD32((sp - 36)), LD32((sp - 32)));
                    break;
                }
            }
            POLL();
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605AB6C(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c3, c5;

    r10 = r5;
    r2 = 0;
    r8 = r4;
    r3 = LD8(r8);
    r9 = 0;
    if (!(((r3 & 255) & (r3 & 255)) == 0)) {
        r11 = 0x0605AB6C;
        while (1) {
            if (((192 & r3) & (192 & r3)) == 0) {
                r1 = r3 & 255;
                r9 = r9 + r1;
                r8 = (r8 + 1) + r1;
            } else {
                r2 = LD8((r8 + 1));
                r0 = GCALL2(r11, (r10 + (0x3FFF & ((r2 & 255) | ((r3 & 255) << 8)))), r10);
                r9 = r9 + r0;
                r2 = 1;
                r8 = r8 + 2;
            }
            r1 = LD8(r8);
            c3 = (r2 & r2) == 0;
            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                if (c3) {
                    r9 = r9 + 1;
                }
            }
            r3 = LD8(r8);
            c5 = (r2 & r2) == 0;
            if (((r3 & 255) & (r3 & 255)) == 0) {
                break;
            } else {
                if (c5) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    if ((r2 & r2) == 0) {
        r9 = r9 + 1;
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605B664(void)
{
    int r0, r1, r5, r8, r9, r10, r11, r12, c1, c3, c4;

    r10 = LD32(0x0608D854);
    r1 = LD8((r10 + 15));
    if (!((r1 & r1) == 0)) {
        r8 = LD32(r10 + 60);
        r0 = (SR() & ~1) | 0;
        r12 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
        r0 = (SR() & ~1) | 0;
        SETSR((r0 | 240));
        r9 = 0x06051D10;
        r0 = GCALL2(0x06051D10, r8, 2);
        c1 = ((1 & r0) & (1 & r0)) == 0;
        r0 = r0 & 14;
        if (c1) {
            c3 = (r0 & r0) == 0;
            if (!(r0 == 6)) {
                c4 = r0 == 2;
                if (!(c3)) {
                    r5 = 16;
                    if (c4) {
                        r0 = GCALL2(0x060541A8, r10, r5);
                        r5 = 1;
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL2(r9, r8, r5);
                            r0 = GCALL3(0x06051E30, r8, 1, (r0 & -3));
                        }
                    }
                } else {
                    r5 = 6;
                    r0 = GCALL2(r9, r8, r5);
                }
            } else {
                r5 = 5;
                r0 = GCALL2(r9, r8, r5);
            }
        }
        r9 = 0x06051D10;
        r11 = 0x0608D3B1;
        r5 = 5;
        while (1) {
            r0 = GCALL2(r9, r8, r5);
            r1 = 1;
            if (((r0 & 1) & (r0 & 1)) == 0) {
                break;
            } else {
                ST8(r11, r1);
                r0 = GCALL2(r9, r8, 0);
                r1 = LD32(0x0608D858);
                ST32(0x0608D858, (r1 + 1));
                r0 = GCALL2(0x06053C9C, r10, r0);
                r5 = 5;
            }
            POLL();
        }
        r1 = (SR() & ~1) | 1;
        SETSR(((r1 & -241) | ((r12 << 2) << 2)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605BBC4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, c3, c7, c12;

    r9 = r4;
    r8 = r5;
    r3 = LD8(r9);
    if (!(r8 > 3)) {
        r2 = r9;
        if (!((unsigned)(r3 - 4) > (unsigned)4)) {
            ST8((r2 + 4), 0);
        }
        r1 = r9;
    } else {
        r1 = r9;
        if (r8 == 9) {
            r2 = r9;
            if (!((unsigned)(r3 - 4) > (unsigned)4)) {
                ST8((r2 + 4), 0);
            }
            r1 = r9;
        }
    }
    r1 = LD16((r1 + 12));
    c3 = (r1 & 0xFFFF) == 0xC021;
    r1 = r9;
    if (c3) {
        r1 = r9;
        if (!(r8 > 1)) {
            r2 = LD32(0x0608D9C8);
            ST8(r2, 1);
            r1 = r9;
        }
    }
    r1 = LD16((r1 + 12));
    r0 = r3;
    if ((r1 & 0xFFFF) == 0x8021) {
        r2 = r3;
        if (r0 == 1) {
            r0 = r8;
            if ((r8 & r8) == 0) {
                r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                r2 = LD32(0x0608D388);
                r2 = r2 + 226;
                r0 = LD8(r2);
                r1 = 2;
                if (!(r0 == 4)) {
                    ST8(r2, r1);
                }
            } else {
                r2 = r8;
                if (r0 == 2) {
                    r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                    r2 = LD32(0x0608D388);
                    r2 = r2 + 226;
                    r0 = LD8(r2);
                    r1 = 2;
                    if (!(r0 == 4)) {
                        ST8(r2, r1);
                    }
                } else {
                    c12 = r0 == 5;
                    if (!((unsigned)(r2 - 3) > (unsigned)1)) {
                        r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                        r2 = LD32(0x0608D388);
                        r2 = r2 + 226;
                        r0 = LD8(r2);
                        r1 = 2;
                        if (!(r0 == 4)) {
                            ST8(r2, r1);
                        }
                    } else {
                        if (c12) {
                            r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                            r2 = LD32(0x0608D388);
                            r2 = r2 + 226;
                            r0 = LD8(r2);
                            r1 = 2;
                            if (!(r0 == 4)) {
                                ST8(r2, r1);
                            }
                        }
                    }
                }
            }
        } else {
            c7 = (unsigned)(r2 - 6) > (unsigned)1;
            r2 = r3;
            if (!(c7)) {
                r0 = r8;
                if ((r8 & r8) == 0) {
                    r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                    r2 = LD32(0x0608D388);
                    r2 = r2 + 226;
                    r0 = LD8(r2);
                    r1 = 2;
                    if (!(r0 == 4)) {
                        ST8(r2, r1);
                    }
                } else {
                    r2 = r8;
                    if (r0 == 2) {
                        r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                        r2 = LD32(0x0608D388);
                        r2 = r2 + 226;
                        r0 = LD8(r2);
                        r1 = 2;
                        if (!(r0 == 4)) {
                            ST8(r2, r1);
                        }
                    } else {
                        c12 = r0 == 5;
                        if (!((unsigned)(r2 - 3) > (unsigned)1)) {
                            r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                            r2 = LD32(0x0608D388);
                            r2 = r2 + 226;
                            r0 = LD8(r2);
                            r1 = 2;
                            if (!(r0 == 4)) {
                                ST8(r2, r1);
                            }
                        } else {
                            if (c12) {
                                r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                                r2 = LD32(0x0608D388);
                                r2 = r2 + 226;
                                r0 = LD8(r2);
                                r1 = 2;
                                if (!(r0 == 4)) {
                                    ST8(r2, r1);
                                }
                            }
                        }
                    }
                }
            } else {
                if (!((unsigned)(r2 - 8) > (unsigned)1)) {
                    r0 = r8;
                    if ((r8 & r8) == 0) {
                        r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                        r2 = LD32(0x0608D388);
                        r2 = r2 + 226;
                        r0 = LD8(r2);
                        r1 = 2;
                        if (!(r0 == 4)) {
                            ST8(r2, r1);
                        }
                    } else {
                        r2 = r8;
                        if (r0 == 2) {
                            r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                            r2 = LD32(0x0608D388);
                            r2 = r2 + 226;
                            r0 = LD8(r2);
                            r1 = 2;
                            if (!(r0 == 4)) {
                                ST8(r2, r1);
                            }
                        } else {
                            c12 = r0 == 5;
                            if (!((unsigned)(r2 - 3) > (unsigned)1)) {
                                r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                                r2 = LD32(0x0608D388);
                                r2 = r2 + 226;
                                r0 = LD8(r2);
                                r1 = 2;
                                if (!(r0 == 4)) {
                                    ST8(r2, r1);
                                }
                            } else {
                                if (c12) {
                                    r0 = GCALL4(0x0605DC0C, 7, r5, r6, r7);
                                    r2 = LD32(0x0608D388);
                                    r2 = r2 + 226;
                                    r0 = LD8(r2);
                                    r1 = 2;
                                    if (!(r0 == 4)) {
                                        ST8(r2, r1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ST8(r9, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605CBC4(int r4)
{
    int r0, r1, r2, r3, c2;

    r3 = LD32(0x0608D9C8);
    r2 = (int)((unsigned)r4 >> 16);
    if (!(r2 == 0xC021)) {
        if (!(r2 == 0x8021)) {
            c2 = r2 == 0xC023;
            r2 = 0;
            if (c2) {
                r2 = 2;
            }
            r1 = 84;
        } else {
            r2 = 1;
            r1 = 84;
        }
    } else {
        r2 = 0;
        r1 = 84;
    }
    r4 = r4 & 0xFFFF;
    r2 = r3 + ((r2 * r1) + 8);
    r0 = r4;
    if (!((unsigned)r4 > (unsigned)15)) {
        r0 = LD32((r0 << 2) + 0x0605CB84);
        r0 = GCALL1(r0, r2);
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DCAC(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, c2;

    if ((r4 & r4) == 0) {
        return -1;
    } else {
        r2 = LD32(r4 + 4);
        r1 = LD32(r4);
        c2 = r2 >= 0;
        if (!(r2 >= r1)) {
            r1 = 0;
            if (!(c2)) {
                ST32(r4 + 4, r1);
            }
            r1 = LD32(r4 + 4);
            r7 = r1 - 1;
            r3 = r1;
            if (r7 >= 0) {
                r2 = LD32(r4 + 12);
                r0 = r7 << 2;
                while (1) {
                    r1 = LD32(r0 + r2);
                    if (!(r6 > r1)) {
                        break;
                    } else {
                        r7 = r7 - 1;
                        r0 = r0 - 4;
                        if (r7 >= 0) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
                r1 = LD32(r4 + 4);
                r3 = r1;
            }
            r3 = r3 - 1;
            r1 = r7;
            if (r3 > r7) {
                do {
                    r0 = r3 << 2;
                    r1 = LD32(r4 + 12);
                    r2 = r0 + r1;
                    r1 = LD32(r0 + r1);
                    r3 = r3 - 1;
                    ST32(r2 + 4, r1);
                    r1 = LD32(r4 + 16);
                    r2 = r0 + r1;
                    r1 = LD32(r0 + r1);
                    ST32(r2 + 4, r1);
                } while (AGAIN(r3 > r7));
                r1 = r7;
            }
            r2 = LD32(r4 + 12);
            r1 = r1 << 2;
            ST32((r2 + r1) + 4, r6);
            r2 = LD32(r4 + 16);
            ST32((r1 + r2) + 4, r5);
            r1 = LD32(r4 + 4);
            r2 = LD32(r4);
            r1 = r1 + 1;
            ST32(r4 + 4, r1);
            return r2 - r1;
        } else {
            return -1;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E0EC(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, c9, c16;
    FRAME(sp, 64);

    r6 = LD32(0x0608D88C);
    r1 = 16;
    r2 = sp - 64;
    if (r6 > 16) {
        r6 = r1;
    }
    r3 = 0;
    if (!(0 >= r6)) {
        r5 = 11;
        r4 = 0x0608D890;
        r7 = 0;
        do {
            r0 = LD32(r4);
            r0 = LD16(r0 + r7);
            r1 = 46;
            if (r0 >= 0) {
                if (!((unsigned)r0 > (unsigned)r5)) {
                    r1 = LD8(r0 + 0x0605E0D0);
                }
            }
            ST8(r2, r1);
            r2 = r2 + 1;
            r3 = r3 + 1;
            r7 = r7 + 220;
        } while (AGAIN(!(r3 >= r6)));
    }
    r1 = 15;
    if (!(r3 > 15)) {
        r7 = 70;
        do {
            ST8(r2, r7);
            r3 = r3 + 1;
            r2 = r2 + 1;
        } while (AGAIN(!(r3 > r1)));
    }
    ST8(r2, 32);
    r3 = 0;
    r2 = r2 + 1;
    if (!(0 >= r6)) {
        r4 = 0x0608D890;
        r5 = 3;
        r7 = 0;
        do {
            r1 = LD32(r4);
            r0 = LD16(((r1 + r7) + 2));
            c9 = (unsigned)r0 > (unsigned)r5;
            if (!(r0 >= 0)) {
                r1 = 46;
            } else {
                if (c9) {
                    r1 = 46;
                } else {
                    r1 = LD8(r0 + 0x0605E0DC);
                }
            }
            ST8(r2, r1);
            r2 = r2 + 1;
            r3 = r3 + 1;
            r7 = r7 + 220;
        } while (AGAIN(!(r3 >= r6)));
    }
    r1 = 15;
    if (!(r3 > 15)) {
        r7 = 73;
        do {
            ST8(r2, r7);
            r3 = r3 + 1;
            r2 = r2 + 1;
        } while (AGAIN(!(r3 > r1)));
    }
    ST8(r2, 32);
    r6 = LD32(0x0608D398);
    r1 = 16;
    r2 = r2 + 1;
    if (r6 > 16) {
        r6 = r1;
    }
    r3 = 0;
    if (!(0 >= r6)) {
        r8 = 10;
        r9 = 0x0608D38C;
        r4 = 0x0605E0E0;
        r5 = 46;
        r7 = 0;
        do {
            r0 = LD32(r9);
            r1 = LD8(r0 + r7);
            r0 = r1 & 255;
            c16 = (unsigned)r0 > (unsigned)r8;
            if (!(r0 >= 0)) {
                ST8(r2, r5);
            } else {
                if (c16) {
                    ST8(r2, r5);
                } else {
                    r1 = LD8(r0 + r4);
                    ST8(r2, r1);
                }
            }
            r2 = r2 + 1;
            r3 = r3 + 1;
            r7 = r7 + 16;
        } while (AGAIN(!(r3 >= r6)));
    }
    r1 = 15;
    r7 = 78;
    if (!(r3 > 15)) {
        do {
            ST8(r2, r7);
            r3 = r3 + 1;
            r2 = r2 + 1;
        } while (AGAIN(!(r3 > r1)));
    }
    ST8(r2, 0);
    r8 = 0x06079F74;
    r0 = GCALL2(0x06075104, (sp - 64), 0x06079F74);
    r5 = 0x06079F74;
    if (!((r0 & r0) == 0)) {
        r5 = r5 + 8;
        r1 = LD32(sp - 64);
        ST32(r8, r1);
        r1 = LD32(sp - 60);
        r2 = (sp - 64) + 8;
        ST32(r8 + 4, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r0 = 1;
        ST32(r5, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r5 = r5 + 4;
        ST32(r5, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r5 = r5 + 4;
        ST32(r5, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r5 = r5 + 4;
        ST32(r5, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r5 = r5 + 4;
        ST32(r5, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r5 = r5 + 4;
        ST32(r5, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r5 = r5 + 4;
        ST32(r5, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r5 = r5 + 4;
        ST32(r5, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r5 = r5 + 4;
        ST32(r5, r1);
        r1 = LD32(r2);
        r2 = r2 + 4;
        r5 = r5 + 4;
        ST32(r5, r1);
        r1 = LD16(r2);
        r5 = r5 + 4;
        ST16(r5, r1);
        r1 = LD8((r2 + 2));
        ST8((r5 + 2), r1);
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E358(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14, c3;
    FRAME(sp, 36);

    r12 = r4;
    r11 = r5;
    r7 = 1;
    r10 = 4;
    r8 = 0;
    r3 = -1;
    r2 = 3;
    r0 = r12;
    do {
        ST8(r0 + r8, r3);
        r1 = LD8(r11 + r8);
        r0 = 1;
        if (!((r1 & r1) == 0)) {
            r7 = 0;
        } else {
            r7 = r7 & r0;
        }
        r8 = r8 + 1;
        r0 = r12;
    } while (AGAIN(!(r8 > r2)));
    r2 = r12;
    if ((r7 & r7) == 0) {
        r0 = GCALL2(0x060618E8, (sp - 36), r11);
        r8 = 0;
        r13 = 0x0608D388;
        r14 = 0x060752CC;
        r9 = 0;
        while (1) {
            r1 = LD32(r13);
            r4 = r9 + r1;
            r1 = LD32((r4 + 112));
            c3 = (r1 & r1) == 0;
            r1 = r4;
            if (c3) {
                r9 = r9 + 196;
                r8 = r8 + 1;
                if (!(r8 > 1)) {
                    POLL();
                    continue;
                } else {
                    r3 = LD8(r11);
                    if (!(((128 & r3) & (128 & r3)) == 0)) {
                        if (!((192 & r3) == 128)) {
                            if (!((r3 & 224) == 192)) {
                                r1 = 3;
                                r2 = 0;
                                if (r10 > 3) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r0 = r12;
                                    do {
                                        ST8(r0 + r10, r2);
                                        r10 = r10 + 1;
                                    } while (AGAIN(!(r10 > r1)));
                                    r0 = 1;
                                    break;
                                }
                            } else {
                                r10 = 3;
                                r1 = 3;
                                r2 = 0;
                                if (r10 > 3) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r0 = r12;
                                    do {
                                        ST8(r0 + r10, r2);
                                        r10 = r10 + 1;
                                    } while (AGAIN(!(r10 > r1)));
                                    r0 = 1;
                                    break;
                                }
                            }
                        } else {
                            r10 = 2;
                            if (!((r3 & 224) == 192)) {
                                r1 = 3;
                                r2 = 0;
                                if (r10 > 3) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r0 = r12;
                                    do {
                                        ST8(r0 + r10, r2);
                                        r10 = r10 + 1;
                                    } while (AGAIN(!(r10 > r1)));
                                    r0 = 1;
                                    break;
                                }
                            } else {
                                r10 = 3;
                                r1 = 3;
                                r2 = 0;
                                if (r10 > 3) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r0 = r12;
                                    do {
                                        ST8(r0 + r10, r2);
                                        r10 = r10 + 1;
                                    } while (AGAIN(!(r10 > r1)));
                                    r0 = 1;
                                    break;
                                }
                            }
                        }
                    } else {
                        r10 = 1;
                        if (!((192 & r3) == 128)) {
                            if (!((r3 & 224) == 192)) {
                                r1 = 3;
                                r2 = 0;
                                if (r10 > 3) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r0 = r12;
                                    do {
                                        ST8(r0 + r10, r2);
                                        r10 = r10 + 1;
                                    } while (AGAIN(!(r10 > r1)));
                                    r0 = 1;
                                    break;
                                }
                            } else {
                                r10 = 3;
                                r1 = 3;
                                r2 = 0;
                                if (r10 > 3) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r0 = r12;
                                    do {
                                        ST8(r0 + r10, r2);
                                        r10 = r10 + 1;
                                    } while (AGAIN(!(r10 > r1)));
                                    r0 = 1;
                                    break;
                                }
                            }
                        } else {
                            r10 = 2;
                            if (!((r3 & 224) == 192)) {
                                r1 = 3;
                                r2 = 0;
                                if (r10 > 3) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r0 = r12;
                                    do {
                                        ST8(r0 + r10, r2);
                                        r10 = r10 + 1;
                                    } while (AGAIN(!(r10 > r1)));
                                    r0 = 1;
                                    break;
                                }
                            } else {
                                r10 = 3;
                                r1 = 3;
                                r2 = 0;
                                if (r10 > 3) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r0 = r12;
                                    do {
                                        ST8(r0 + r10, r2);
                                        r10 = r10 + 1;
                                    } while (AGAIN(!(r10 > r1)));
                                    r0 = 1;
                                    break;
                                }
                            }
                        }
                    }
                }
            } else {
                r1 = LD32((r1 + 104));
                r4 = r4 + 40;
                if ((r1 & r1) == 0) {
                    r9 = r9 + 196;
                    r8 = r8 + 1;
                    if (!(r8 > 1)) {
                        POLL();
                        continue;
                    } else {
                        r3 = LD8(r11);
                        if (!(((128 & r3) & (128 & r3)) == 0)) {
                            if (!((192 & r3) == 128)) {
                                if (!((r3 & 224) == 192)) {
                                    r1 = 3;
                                    r2 = 0;
                                    if (r10 > 3) {
                                        r0 = 1;
                                        break;
                                    } else {
                                        r0 = r12;
                                        do {
                                            ST8(r0 + r10, r2);
                                            r10 = r10 + 1;
                                        } while (AGAIN(!(r10 > r1)));
                                        r0 = 1;
                                        break;
                                    }
                                } else {
                                    r10 = 3;
                                    r1 = 3;
                                    r2 = 0;
                                    if (r10 > 3) {
                                        r0 = 1;
                                        break;
                                    } else {
                                        r0 = r12;
                                        do {
                                            ST8(r0 + r10, r2);
                                            r10 = r10 + 1;
                                        } while (AGAIN(!(r10 > r1)));
                                        r0 = 1;
                                        break;
                                    }
                                }
                            } else {
                                r10 = 2;
                                if (!((r3 & 224) == 192)) {
                                    r1 = 3;
                                    r2 = 0;
                                    if (r10 > 3) {
                                        r0 = 1;
                                        break;
                                    } else {
                                        r0 = r12;
                                        do {
                                            ST8(r0 + r10, r2);
                                            r10 = r10 + 1;
                                        } while (AGAIN(!(r10 > r1)));
                                        r0 = 1;
                                        break;
                                    }
                                } else {
                                    r10 = 3;
                                    r1 = 3;
                                    r2 = 0;
                                    if (r10 > 3) {
                                        r0 = 1;
                                        break;
                                    } else {
                                        r0 = r12;
                                        do {
                                            ST8(r0 + r10, r2);
                                            r10 = r10 + 1;
                                        } while (AGAIN(!(r10 > r1)));
                                        r0 = 1;
                                        break;
                                    }
                                }
                            }
                        } else {
                            r10 = 1;
                            if (!((192 & r3) == 128)) {
                                if (!((r3 & 224) == 192)) {
                                    r1 = 3;
                                    r2 = 0;
                                    if (r10 > 3) {
                                        r0 = 1;
                                        break;
                                    } else {
                                        r0 = r12;
                                        do {
                                            ST8(r0 + r10, r2);
                                            r10 = r10 + 1;
                                        } while (AGAIN(!(r10 > r1)));
                                        r0 = 1;
                                        break;
                                    }
                                } else {
                                    r10 = 3;
                                    r1 = 3;
                                    r2 = 0;
                                    if (r10 > 3) {
                                        r0 = 1;
                                        break;
                                    } else {
                                        r0 = r12;
                                        do {
                                            ST8(r0 + r10, r2);
                                            r10 = r10 + 1;
                                        } while (AGAIN(!(r10 > r1)));
                                        r0 = 1;
                                        break;
                                    }
                                }
                            } else {
                                r10 = 2;
                                if (!((r3 & 224) == 192)) {
                                    r1 = 3;
                                    r2 = 0;
                                    if (r10 > 3) {
                                        r0 = 1;
                                        break;
                                    } else {
                                        r0 = r12;
                                        do {
                                            ST8(r0 + r10, r2);
                                            r10 = r10 + 1;
                                        } while (AGAIN(!(r10 > r1)));
                                        r0 = 1;
                                        break;
                                    }
                                } else {
                                    r10 = 3;
                                    r1 = 3;
                                    r2 = 0;
                                    if (r10 > 3) {
                                        r0 = 1;
                                        break;
                                    } else {
                                        r0 = r12;
                                        do {
                                            ST8(r0 + r10, r2);
                                            r10 = r10 + 1;
                                        } while (AGAIN(!(r10 > r1)));
                                        r0 = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    r0 = GCALL3(r14, r4, (sp - 36), 4);
                    r3 = r9;
                    if ((r0 & r0) == 0) {
                        POLL();
                        r1 = LD32(r13);
                        r0 = 1;
                        r3 = r3 + r1;
                        r1 = LD8((r3 + 48));
                        ST8(r12, r1);
                        r2 = LD8((r3 + 49));
                        r1 = r12 + 1;
                        ST8(r1, r2);
                        r2 = LD8((r3 + 50));
                        r1 = r1 + 1;
                        ST8(r1, r2);
                        r2 = LD8((r3 + 51));
                        ST8((r1 + 1), r2);
                        break;
                    } else {
                        r9 = r9 + 196;
                        r8 = r8 + 1;
                        if (!(r8 > 1)) {
                            POLL();
                            continue;
                        } else {
                            r3 = LD8(r11);
                            if (!(((128 & r3) & (128 & r3)) == 0)) {
                                if (!((192 & r3) == 128)) {
                                    if (!((r3 & 224) == 192)) {
                                        r1 = 3;
                                        r2 = 0;
                                        if (r10 > 3) {
                                            r0 = 1;
                                            break;
                                        } else {
                                            r0 = r12;
                                            do {
                                                ST8(r0 + r10, r2);
                                                r10 = r10 + 1;
                                            } while (AGAIN(!(r10 > r1)));
                                            r0 = 1;
                                            break;
                                        }
                                    } else {
                                        r10 = 3;
                                        r1 = 3;
                                        r2 = 0;
                                        if (r10 > 3) {
                                            r0 = 1;
                                            break;
                                        } else {
                                            r0 = r12;
                                            do {
                                                ST8(r0 + r10, r2);
                                                r10 = r10 + 1;
                                            } while (AGAIN(!(r10 > r1)));
                                            r0 = 1;
                                            break;
                                        }
                                    }
                                } else {
                                    r10 = 2;
                                    if (!((r3 & 224) == 192)) {
                                        r1 = 3;
                                        r2 = 0;
                                        if (r10 > 3) {
                                            r0 = 1;
                                            break;
                                        } else {
                                            r0 = r12;
                                            do {
                                                ST8(r0 + r10, r2);
                                                r10 = r10 + 1;
                                            } while (AGAIN(!(r10 > r1)));
                                            r0 = 1;
                                            break;
                                        }
                                    } else {
                                        r10 = 3;
                                        r1 = 3;
                                        r2 = 0;
                                        if (r10 > 3) {
                                            r0 = 1;
                                            break;
                                        } else {
                                            r0 = r12;
                                            do {
                                                ST8(r0 + r10, r2);
                                                r10 = r10 + 1;
                                            } while (AGAIN(!(r10 > r1)));
                                            r0 = 1;
                                            break;
                                        }
                                    }
                                }
                            } else {
                                r10 = 1;
                                if (!((192 & r3) == 128)) {
                                    if (!((r3 & 224) == 192)) {
                                        r1 = 3;
                                        r2 = 0;
                                        if (r10 > 3) {
                                            r0 = 1;
                                            break;
                                        } else {
                                            r0 = r12;
                                            do {
                                                ST8(r0 + r10, r2);
                                                r10 = r10 + 1;
                                            } while (AGAIN(!(r10 > r1)));
                                            r0 = 1;
                                            break;
                                        }
                                    } else {
                                        r10 = 3;
                                        r1 = 3;
                                        r2 = 0;
                                        if (r10 > 3) {
                                            r0 = 1;
                                            break;
                                        } else {
                                            r0 = r12;
                                            do {
                                                ST8(r0 + r10, r2);
                                                r10 = r10 + 1;
                                            } while (AGAIN(!(r10 > r1)));
                                            r0 = 1;
                                            break;
                                        }
                                    }
                                } else {
                                    r10 = 2;
                                    if (!((r3 & 224) == 192)) {
                                        r1 = 3;
                                        r2 = 0;
                                        if (r10 > 3) {
                                            r0 = 1;
                                            break;
                                        } else {
                                            r0 = r12;
                                            do {
                                                ST8(r0 + r10, r2);
                                                r10 = r10 + 1;
                                            } while (AGAIN(!(r10 > r1)));
                                            r0 = 1;
                                            break;
                                        }
                                    } else {
                                        r10 = 3;
                                        r1 = 3;
                                        r2 = 0;
                                        if (r10 > 3) {
                                            r0 = 1;
                                            break;
                                        } else {
                                            r0 = r12;
                                            do {
                                                ST8(r0 + r10, r2);
                                                r10 = r10 + 1;
                                            } while (AGAIN(!(r10 > r1)));
                                            r0 = 1;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            POLL();
        }
    } else {
        r1 = LD8(r11);
        r2 = r2 + 1;
        ST8(r12, r1);
        r1 = r11 + 1;
        r3 = LD8(r1);
        r1 = r1 + 1;
        r0 = 1;
        ST8(r2, r3);
        r3 = LD8(r1);
        r2 = r2 + 1;
        ST8(r2, r3);
        r1 = LD8((r1 + 1));
        ST8((r2 + 1), r1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605ECFC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, c1, c2;

    if (!(r4 >= 0)) {
        r0 = -2;
    } else {
        r1 = LD32(0x0608D9E8);
        r2 = LD32(0x0608D88C);
        c1 = r4 >= ((r1 + r2) + 3);
        r1 = 28;
        if (c1) {
            r0 = -2;
        } else {
            c2 = r4 * r1;
            r1 = LD32(0x0608D9E4);
            r4 = r1 + c2;
            r0 = LD8(r4);
            r6 = r5;
            if (r0 == 3) {
                r0 = GCALL4(0x06061940, r4, 1, r6, r7);
                r0 = 1;
            } else {
                r0 = -2;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06052180(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, c3;

    r11 = r5;
    r1 = LD16((r11 + 4));
    r12 = r11 + r1;
    r1 = LD16((r6 + 14));
    r9 = r4;
    if ((r1 & r1) == 0) {
        r8 = r12 + 16;
        r0 = GCALL1(0x06053108, r8);
        r5 = 1;
        if (!((r0 & r0) == 0)) {
            r0 = GCALL2(0x0605DC3C, r8, r5);
            r10 = r0;
            r1 = r10;
            if (!((r10 & r10) == 0)) {
                r1 = LD16((r1 + 14));
                c3 = r1 == r9;
                r1 = r12;
                if (!(c3)) {
                    r1 = LD16((r1 + 2));
                    r9 = (r1 & 0xFFFF) + 8;
                    r0 = LD32(0x0608D3A0);
                    r0 = GCALL1(r0, r9);
                    r8 = r0;
                    r3 = r8;
                    if (!((r8 & r8) == 0)) {
                        r3 = r3 + 4;
                        ST16(r3, 8);
                        r1 = LD16((r11 + 6));
                        ST16((r8 + 6), r1);
                        r2 = LD16(r3);
                        r1 = LD16((r11 + 4));
                        r0 = GCALL3(0x0604B358, (r8 + r2), (r11 + r1), (r9 - 8));
                        r4 = LD16((r10 + 14));
                        r0 = GCALL3(0x06052BD0, r4, (r12 + 16), r8);
                    }
                }
                r1 = LD32(0x0608D390);
                r0 = GCALL1(r1, r10);
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060522C0(int r4, int r5)
{
    int r0, r1, r6, r8, r9, r10, r11;

    r9 = r4;
    r0 = LD8(r9);
    r8 = r5;
    if (r0 == 1) {
        r1 = LD16((r8 + 4));
        r1 = LD16(((r1 + r8) + 6));
        r5 = r8;
        r4 = LD32(r9 + 12);
        r6 = -(0x1FFF & r1);
        r0 = GCALL3(0x0605DCAC, r4, r5, r6);
        r1 = 60;
        if (r0 >= 0) {
            ST32(r9 + 4, r1);
            r0 = 1;
        } else {
            r1 = LD32(0x0608D390);
            r0 = GCALL3(r1, r8, r5, r6);
            r11 = 0x0605DD2C;
            r1 = LD32(0x0608D904);
            r10 = 0x0608D904;
            ST32(0x0608D904, (r1 + 1));
            while (1) {
                r4 = LD32(r9 + 12);
                r0 = GCALL1(r11, r4);
                r8 = r0;
                if ((r8 & r8) == 0) {
                    break;
                } else {
                    r1 = LD32(0x0608D390);
                    r0 = GCALL1(r1, r8);
                    r1 = LD32(r10);
                    ST32(r10, (r1 + 1));
                }
                POLL();
            }
            r4 = LD32(r9 + 12);
            r0 = GCALL1(0x0605DE08, r4);
            ST8(r9, 2);
            r0 = 0;
        }
    } else {
        r1 = LD32(0x0608D390);
        r0 = GCALL2(r1, r8, r5);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06052364(int r4)
{
    int r0, r1, r2, r3, r5, r8, r9, r10, r11, r12, r13, r14;

    r13 = r4;
    r4 = LD32(r13 + 12);
    r0 = GCALL1(0x0605DD70, r4);
    r9 = r0;
    r0 = LD16((r9 + 4));
    r12 = 0;
    r0 = LD8(r0 + r9);
    r11 = 0x0605DD70;
    r10 = ((r0 & 15) << 2) + 8;
    r1 = r9;
    do {
        r0 = LD16((r1 + 4));
        r5 = r9 + r0;
        r0 = LD8(r0 + r9);
        r2 = LD16((r5 + 6));
        r1 = LD16((r5 + 2));
        r4 = LD32(r13 + 12);
        r10 = r10 + ((r1 & 0xFFFF) - ((((r0 & 15) << 2) + r12) - (((0x1FFF & r2) << 2) + ((0x1FFF & r2) << 2))));
        r0 = GCALL2(r11, r4, r5);
        r9 = r0;
        r1 = r9;
    } while (AGAIN(!((r9 & r9) == 0)));
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, r10);
    r11 = r0;
    r8 = r11;
    if (!((r11 & r11) == 0)) {
        r8 = r8 + 4;
        ST16(r8, 8);
        r4 = LD32(r13 + 12);
        r0 = GCALL1(0x0605DD2C, r4);
        r9 = r0;
        r3 = r9 + 4;
        r12 = 0;
        r0 = LD16(r3);
        r0 = LD8(r0 + r9);
        r1 = LD16((r9 + 6));
        r10 = (r0 & 15) << 2;
        ST16((r11 + 6), r1);
        r1 = LD16(r8);
        r2 = LD16(r3);
        r0 = GCALL3(0x0604B358, (r11 + r1), (r9 + r2), r10);
        r14 = 0x0604B358;
        if (!((r9 & r9) == 0)) {
            r1 = r9;
            do {
                r0 = LD16((r1 + 4));
                r5 = r9 + r0;
                r0 = LD8(r0 + r9);
                r2 = LD16((r5 + 6));
                r3 = (((r0 & 15) << 2) + r12) - (((0x1FFF & r2) << 2) + ((0x1FFF & r2) << 2));
                r1 = LD16((r5 + 2));
                r8 = (r1 & 0xFFFF) - r3;
                r1 = LD16((r11 + 4));
                r0 = GCALL3(r14, ((r11 + r1) + r10), (r5 + r3), r8);
                r10 = r10 + r8;
                r12 = r12 + r8;
                r1 = LD32(0x0608D390);
                r0 = GCALL1(r1, r9);
                r4 = LD32(r13 + 12);
                r0 = GCALL1(0x0605DD2C, r4);
                r9 = r0;
                r1 = r9;
            } while (AGAIN(!((r9 & r9) == 0)));
        }
        r1 = LD16((r11 + 4));
        r5 = r11 + r1;
        ST16((r5 + 2), r10);
        ST16((r5 + 6), 0);
        r4 = LD32(r13 + 12);
        r0 = GCALL2(0x0605DE08, r4, r5);
        ST8(r13, 3);
        r1 = LD32(0x0608D928);
        r0 = r11;
        ST32(0x0608D928, (r1 + 1));
    } else {
        r10 = 0x0605DD2C;
        r8 = 0x0608D904;
        while (1) {
            r4 = LD32(r13 + 12);
            r0 = GCALL1(r10, r4);
            r9 = r0;
            if ((r9 & r9) == 0) {
                break;
            } else {
                r1 = LD32(r8);
                ST32(r8, (r1 + 1));
                r1 = LD32(0x0608D390);
                r0 = GCALL1(r1, r9);
            }
            POLL();
        }
        r4 = LD32(r13 + 12);
        r0 = GCALL1(0x0605DE08, r4);
        ST8(r13, 3);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06052DD4(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, r14, c5;

    r13 = r4;
    r1 = LD16((r13 + 4));
    r11 = r13 + r1;
    r2 = LD16((r11 + 6));
    r12 = -1;
    if (!(((0x3FFF & r2) & (0x3FFF & r2)) == 0)) {
        r1 = LD32(0x0608D960);
        r10 = 0;
        r14 = 0x060752CC;
        r9 = 0;
        ST32(0x0608D960, (r1 + 1));
        while (1) {
            r0 = LD32(0x0608D380);
            r8 = r0;
            r0 = LD8(r0 + r9);
            r8 = r8 + r9;
            if (!(r0 == 3)) {
                r2 = LD16((r8 + 2));
                r1 = LD16((r11 + 4));
                r4 = r8;
                if (!((r2 & 0xFFFF) == (r1 & 0xFFFF))) {
                    r10 = r10 + 1;
                    r9 = r9 + 16;
                    if (!(r10 > 9)) {
                        POLL();
                        continue;
                    } else {
                        if (!(r12 >= 0)) {
                            r1 = LD32(0x0608D390);
                            r0 = GCALL2(r1, r13, r5);
                            r0 = 0;
                            break;
                        } else {
                            r0 = GCALL2(0x0605DDA0, 10, r5);
                            r7 = (r12 << 2) << 2;
                            r6 = LD32(0x0608D380);
                            r2 = r7 + r6;
                            ST32(r2 + 12, r0);
                            r1 = LD16((r11 + 12));
                            ST16((r2 + 8), r1);
                            r1 = LD16((r11 + 14));
                            ST16((r2 + 10), r1);
                            r1 = LD16((r11 + 4));
                            ST16((r2 + 2), r1);
                            ST32(r2 + 4, 60);
                            ST8(r7 + r6, 1);
                            r4 = LD32(0x0608D380);
                            r0 = GCALL4(0x060522C0, (r4 + r7), r13, r6, r7);
                            r0 = 0;
                            break;
                        }
                    }
                } else {
                    r0 = GCALL3(r14, (r4 + 8), (r11 + 12), 4);
                    r5 = r13;
                    if (!((r0 & r0) == 0)) {
                        r10 = r10 + 1;
                        r9 = r9 + 16;
                        if (!(r10 > 9)) {
                            POLL();
                            continue;
                        } else {
                            if (!(r12 >= 0)) {
                                r1 = LD32(0x0608D390);
                                r0 = GCALL2(r1, r13, r5);
                                r0 = 0;
                                break;
                            } else {
                                r0 = GCALL2(0x0605DDA0, 10, r5);
                                r7 = (r12 << 2) << 2;
                                r6 = LD32(0x0608D380);
                                r2 = r7 + r6;
                                ST32(r2 + 12, r0);
                                r1 = LD16((r11 + 12));
                                ST16((r2 + 8), r1);
                                r1 = LD16((r11 + 14));
                                ST16((r2 + 10), r1);
                                r1 = LD16((r11 + 4));
                                ST16((r2 + 2), r1);
                                ST32(r2 + 4, 60);
                                ST8(r7 + r6, 1);
                                r4 = LD32(0x0608D380);
                                r0 = GCALL4(0x060522C0, (r4 + r7), r13, r6, r7);
                                r0 = 0;
                                break;
                            }
                        }
                    } else {
                        r0 = GCALL2(0x060522C0, r8, r5);
                        c5 = (r0 & r0) == 0;
                        r0 = 0;
                        if (c5) {
                            break;
                        } else {
                            r0 = GCALL1(0x06052654, r8);
                            break;
                        }
                    }
                }
            } else {
                if (!(r12 == -1)) {
                    r10 = r10 + 1;
                } else {
                    r12 = r10;
                    r10 = r10 + 1;
                }
                r9 = r9 + 16;
                if (!(r10 > 9)) {
                    POLL();
                    continue;
                } else {
                    if (!(r12 >= 0)) {
                        r1 = LD32(0x0608D390);
                        r0 = GCALL2(r1, r13, r5);
                        r0 = 0;
                        break;
                    } else {
                        r0 = GCALL2(0x0605DDA0, 10, r5);
                        r7 = (r12 << 2) << 2;
                        r6 = LD32(0x0608D380);
                        r2 = r7 + r6;
                        ST32(r2 + 12, r0);
                        r1 = LD16((r11 + 12));
                        ST16((r2 + 8), r1);
                        r1 = LD16((r11 + 14));
                        ST16((r2 + 10), r1);
                        r1 = LD16((r11 + 4));
                        ST16((r2 + 2), r1);
                        ST32(r2 + 4, 60);
                        ST8(r7 + r6, 1);
                        r4 = LD32(0x0608D380);
                        r0 = GCALL4(0x060522C0, (r4 + r7), r13, r6, r7);
                        r0 = 0;
                        break;
                    }
                }
            }
            POLL();
        }
    } else {
        r0 = r13;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060531D4(int r4)
{
    int r0, r1, r2, c3;

    r2 = LD32(0x0608D388);
    if (!(r4 == r2)) {
        r0 = -1;
        if (!(r4 == (196 + r2))) {
            return r0;
        } else {
            r2 = r4 + 30;
            r0 = LD8(r2);
            c3 = r0 == 5;
            if (!(r0 == 4)) {
                r1 = 5;
                if (!(c3)) {
                    ST8(r2, r1);
                    r0 = GCALL1(0x0605DBD4, ((int)0x80210002));
                    r0 = GCALL0(0x0605299C);
                    return -502;
                } else {
                    return -502;
                }
            } else {
                r0 = -506;
                ST8(r2, 2);
                return r0;
            }
        }
    } else {
        ST8((r4 + 30), 1);
        r0 = 1;
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06053268(void)
{
    int r0;

    r0 = GCALL1(0x0605DBD4, ((int)0x80210003));
    r0 = GCALL0(0x0605299C);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060549D8(void)
{
    int r0, r1, r2, r3, r8, c3;
    FRAME(sp, 16);

    r1 = LD32(0x0608D39C);
    ST32(sp - 12, r1);
    r0 = GCALL0(r1);
    r2 = LD32(0x0608D394);
    r0 = GCALL3(0x060544AC, (sp - 16), 1, (r0 + (((r2 << 2) + r2) + ((r2 << 2) + r2))));
    r1 = LD8(sp - 16);
    r3 = 127 & r1;
    r1 = LD8(r3 + 0x06075135);
    if (!(((r1 & 151) & (r1 & 151)) == 0)) {
        r0 = LD32(0x0608D850);
        ST32(0x0608D850, (r0 + 1));
        ST8(r0 + 0x0608D7F0, r3);
    }
    r8 = 0x0608D850;
    r2 = LD32(0x0608D850);
    if (r2 > 78) {
        ST8(r2 + 0x0608D7F0, 0);
        r0 = GCALL1(0x0605DC24, 0x0608D7F0);
        ST32(r8, 0);
        r1 = LD8(sp - 16);
    } else {
        c3 = r2 > 0;
        if (!(r3 == 10)) {
            r1 = LD8(sp - 16);
        } else {
            r1 = LD8(sp - 16);
            if (c3) {
                ST8(r2 + 0x0608D7F0, 0);
                r0 = GCALL1(0x0605DC24, 0x0608D7F0);
                ST32(r8, 0);
                r1 = LD8(sp - 16);
            }
        }
    }
    return r1 & 255;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055074(int r4)
{
    int r0, r1, r8;

    r1 = LD32(0x0608D9D4);
    r8 = r4;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL1(r1, r4);
    }
    r0 = GCALL1(0x0605DC0C, 0);
    ST8((r8 + 18), 0);
    r0 = GCALL2(0x06051FAC, r8, 48);
    r8 = r0;
    if (!((r8 & r8) == 0)) {
        r1 = LD32(0x0608D9CC);
        if (!((r1 & r1) == 0)) {
            r0 = GCALL0(r1);
        }
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055160(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, r14;

    r11 = r4;
    r10 = r5;
    r14 = r6;
    r0 = GCALL0(0x06053E84);
    r13 = 0x0607507C;
    r0 = GCALL1(0x0607507C, r10);
    r9 = r0;
    r12 = 0x0608D3A0;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, r9);
    r8 = r0;
    r6 = r9;
    if (!((r8 & r8) == 0)) {
        r0 = GCALL3(0x0604B358, r8, r10, r6);
        r0 = GCALL3(0x06054010, r8, r9, 0);
    }
    r4 = LD32(r11 + 32);
    if (!((r4 & r4) == 0)) {
        r1 = LD32(0x0608D390);
        r0 = GCALL1(r1, r4);
    }
    r0 = GCALL1(r13, r10);
    r4 = r0;
    r0 = LD32(r12);
    r0 = GCALL1(r0, (r4 + 1));
    r1 = r0;
    ST32(r11 + 32, r1);
    if (!((r1 & r1) == 0)) {
        r0 = GCALL2(0x060750DC, r1, r10);
    }
    r0 = GCALL2(0x06055124, r11, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060556FC(int r4, int r5)
{
    int r0, r1, r2, r8, r9;

    r9 = r4;
    r8 = r5;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL2(r0, 1, r5);
    r2 = r0;
    r1 = 13;
    if (!((r2 & r2) == 0)) {
        ST8(r2, r1);
        r0 = GCALL3(0x06054010, r2, 1, 0);
    }
    r0 = GCALL2(0x06055124, r9, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055740(int r4)
{
    int r0, r5, r8, r9, r10, r11;

    r11 = r4;
    r9 = 0x0608AD40;
    r10 = 0x060517D0;
    r0 = GCALL1(0x060517D0, 0x0608AD40);
    r4 = r0;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, (r4 + 1));
    r8 = r0;
    r5 = r8;
    if (!((r8 & r8) == 0)) {
        r0 = GCALL2(0x060517E4, r9, r5);
        r0 = GCALL1(r10, r9);
        r0 = GCALL3(0x06054010, r8, r0, 0);
    }
    r0 = GCALL2(0x060556FC, r11, 30);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060557A8(int r4)
{
    int r0, r6, r8, r9, r10, r11;

    r11 = r4;
    r10 = 0x0608ADC4;
    r0 = GCALL1(0x0607507C, 0x0608ADC4);
    r9 = r0;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, r9);
    r8 = r0;
    r6 = r9;
    if (!((r8 & r8) == 0)) {
        r0 = GCALL3(0x0604B358, r8, r10, r6);
        r0 = GCALL3(0x06054010, r8, r9, 0);
    }
    r0 = GCALL2(0x060556FC, r11, 30);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605580C(int r4)
{
    int r0, r5, r8, r9, r10, r11;

    r11 = r4;
    r10 = r11 + 72;
    r4 = LD32(r10);
    r0 = GCALL1(0x0607507C, r4);
    r9 = r0;
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, r9);
    r8 = r0;
    if (!((r8 & r8) == 0)) {
        r5 = LD32(r10);
        r0 = GCALL3(0x0604B358, r8, r5, r9);
        r0 = GCALL3(0x06054010, r8, r9, 0);
    }
    r0 = GCALL2(0x06055124, r11, 30);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055870(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r0 = r5;
    r8 = r4;
    if (r0 == 2) {
        r0 = GCALL1(0x06055404, r4);
        ST8((r8 + 1), 10);
        r0 = GCALL4(0x06055074, r8, r5, r6, r7);
        if ((r0 & r0) == 0) {
            r0 = GCALL1(0x06055210, r8);
            r0 = GCALL2(0x06055038, r8, 1);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605617C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r0 = r5;
    r8 = r4;
    if (r0 == 1) {
        r0 = GCALL4(0x06055594, r8, r5, r6, r7);
        r0 = GCALL1(0x060556D8, r8);
        r1 = 0x06055038;
        r5 = 0;
        r0 = GCALL2(r1, r8, r5);
    } else {
        if (r0 == 7) {
            r0 = GCALL1(0x060556D8, r8);
            ST8((r8 + 1), 10);
            r0 = GCALL1(0x06055074, r8);
            if ((r0 & r0) == 0) {
                r0 = GCALL1(0x06055210, r8);
                r1 = 0x06055038;
                r5 = 1;
                r0 = GCALL2(r1, r8, r5);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056218(void)
{
    int r0, r1, r2, r4, r8, r9, r10, r11, c8, c9, c10;

    r9 = LD32(0x0608D854);
    r8 = LD32((r9 + 80));
    r1 = r9;
    if (!((r8 & r8) == 0)) {
        r10 = 0x0608D390;
        r1 = r8;
        while (1) {
            r0 = LD8((r1 + 4));
            if (!((r0 & 3) == 3)) {
                break;
            } else {
                r4 = LD32(r8 + 12);
                ST32(r8 + 12, 0);
                r1 = LD32(r10);
                r0 = GCALL1(r1, r4);
                r4 = r8;
                r8 = LD32(r8);
                ST32((r9 + 80), r8);
                r1 = LD32(r10);
                r0 = GCALL1(r1, r4);
                r1 = r8;
                if (!((r8 & r8) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        r1 = r9;
    }
    r1 = LD32((r1 + 80));
    r2 = r9;
    if ((r1 & r1) == 0) {
        ST32((r2 + 84), 0);
    }
    r0 = LD32(0x0608D388);
    r0 = LD8(r0 + 226);
    if (!(r0 == 4)) {
        r10 = 0x0608D39C;
        r0 = LD32(0x0608D39C);
        r0 = GCALL0(r0);
        r8 = r9 + 76;
        r1 = LD32(r8);
        if ((unsigned)r0 >= (unsigned)r1) {
            r0 = GCALL1(0x06051C30, r9);
            if ((r0 & r0) == 0) {
                r0 = GCALL1(0x06051F38, r9);
                r0 = GCALL1(0x06055000, 7);
            }
            r0 = LD32(r10);
            r0 = GCALL0(r0);
            r1 = LD32(0x0608D394);
            ST32(r8, ((r1 + r1) + r0));
        }
    }
    r0 = GCALL1(0x06054B88, r9);
    r4 = LD32(r9 + 60);
    r0 = GCALL1(0x0605B7E8, r4);
    r1 = LD8((r9 + 4));
    r8 = r0;
    c8 = (r8 & r8) == 0;
    if (!(r8 == r1)) {
        r4 = 8;
        if (c8) {
            r1 = 0x06055000;
            r4 = 7;
        } else {
            r1 = 0x06055000;
        }
        r0 = GCALL1(r1, r4);
        ST8((r9 + 4), r8);
    }
    r8 = r9 + 2;
    r1 = LD8(r8);
    c9 = (r1 & r1) == 0;
    r1 = r9;
    if (!(c9)) {
        r0 = LD32(0x0608D39C);
        r0 = GCALL0(r0);
        r1 = LD32(r9 + 40);
        c10 = (unsigned)r0 >= (unsigned)r1;
        r1 = r9;
        if (c10) {
            ST8(r8, 0);
            r1 = LD8((r9 + 1));
            if (!(r1 > 0)) {
                r1 = 0x06055000;
                r4 = 13;
            } else {
                r4 = 12;
                r1 = 0x06055000;
            }
            r0 = GCALL1(r1, r4);
            r1 = r9;
        }
    }
    r10 = LD32((r1 + 64));
    r11 = 0x0605EB28;
    while (1) {
        r0 = GCALL1(r11, r10);
        if (!(r0 > 0)) {
            break;
        } else {
            r0 = GCALL1(0x0605EC14, r10);
            r8 = r0;
            if (r0 == 1) {
                ST8((r9 + 17), 0);
            }
            if (r8 == 7) {
                r0 = GCALL1(0x0605DC0C, 9);
            }
            r1 = LD8(r9);
            r1 = LD32((r1 << 2) + 0x060561E4);
            r0 = GCALL2(r1, r9, r8);
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056518(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, c0, c2;

    r8 = r4;
    r1 = LD16(r8);
    c0 = (r1 & r1) == 0;
    r1 = r8;
    if (c0) {
        r0 = 1;
    } else {
        r1 = LD16((r1 + 4));
        r0 = r1;
        c2 = r0 == 2;
        if (r0 == 1) {
            r4 = LD32(144 + r8);
            r0 = GCALL4(0x0605ECFC, r4, 0, 0, r7);
            r2 = 0;
            ST16(r8, r2);
            ST16((r8 + 2), r2);
            ST32(r8 + 8, ((int)0x80000000));
            r0 = 1;
        } else {
            if (!(c2)) {
                r1 = LD32(r8 + 8);
                ST32(r8 + 8, (r1 + 1));
                r0 = -2;
            } else {
                r0 = GCALL4(0x06058784, r8, 0, r6, r7);
                ST32(152 + r8, ((int)0x80000000));
                ST32(160 + r8, ((int)0x80000000));
                ST32(180 + r8, ((int)0x80000000));
                r4 = LD32(164 + r8);
                if (!((r4 & r4) == 0)) {
                    r1 = LD32(0x0608D390);
                    r0 = GCALL1(r1, r4);
                }
                r1 = LD32(0x0608D390);
                r4 = LD32(r8 + 184);
                r0 = GCALL1(r1, r4);
                r1 = LD32(r8 + 208);
                r9 = 208;
                if (!((r1 & r1) == 0)) {
                    r10 = 0x0605DD2C;
                    r0 = r8;
                    while (1) {
                        r4 = LD32(r0 + r9);
                        r0 = GCALL1(r10, r4);
                        r2 = r0;
                        r0 = r8;
                        if ((r2 & r2) == 0) {
                            break;
                        } else {
                            r1 = LD32(0x0608D390);
                            r0 = GCALL1(r1, r2);
                            r0 = r8;
                        }
                        POLL();
                    }
                    r4 = LD32(r0 + r9);
                    r0 = GCALL1(0x0605DE08, r4);
                    ST32(r8 + r9, 0);
                }
                r2 = 0;
                ST16(r8, r2);
                ST16((r8 + 2), r2);
                ST32(r8 + 8, ((int)0x80000000));
                r0 = 1;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056704(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10;

    r9 = r4;
    r10 = LD16((r9 + 4));
    r8 = r9 + r10;
    r0 = GCALL1(0x060585D8, r8);
    r4 = r8;
    if (((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
        r1 = LD16((r8 + 2));
        r2 = LD8(r9 + r10);
        r1 = (r1 & 0xFFFF) - ((r2 & 15) << 2);
        r2 = LD8((r8 + 32));
        r4 = r4 + 20;
        if ((r1 - ((int)((unsigned)(r2 & 240) >> 2))) >= 0) {
            r0 = GCALL1(0x060567D8, r4);
            r0 = GCALL1(0x0605864C, r9);
            r8 = r0;
            r5 = r9;
            if (!((r8 & r8) == 0)) {
                r0 = GCALL2(0x06058454, r8, r5);
                r5 = r9;
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL2(0x06058BB0, r8, r5);
                    r1 = LD16(r8);
                    r5 = r9;
                    r0 = LD32((r1 << 2) + 0x060563B0);
                } else {
                    r0 = 0x06058F30;
                }
                r0 = GCALL2(r0, r8, r5);
                r1 = LD16(r8);
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r8 + 8);
                    ST32(r8 + 8, (r1 + 1));
                }
            } else {
                r0 = GCALL2(0x06058148, r9, r5);
            }
        }
    }
    r1 = LD32(0x0608D390);
    r0 = GCALL1(r1, r9);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056988(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;

    r8 = r5;
    r1 = LD16((r8 + 4));
    r0 = LD8(((r1 + r8) + 33));
    r9 = r4;
    if (((4 & r0) & (4 & r0)) == 0) {
        r5 = r8;
        if (!(((r0 & 2) & (r0 & 2)) == 0)) {
            r0 = GCALL4(0x06058148, r8, r5, r6, r7);
            r0 = GCALL1(0x06056518, r9);
        } else {
            r0 = GCALL4(0x06058DF0, r9, r5, r6, r7);
            r0 = GCALL2(0x06056E34, r9, r8);
            r0 = GCALL1(0x06056938, r9);
            r0 = 1;
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060569F4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8;

    r8 = r4;
    r4 = r5;
    r1 = LD16((r4 + 4));
    r2 = LD8(((r1 + r4) + 33));
    r0 = r2;
    if (!(((4 & r2) & (4 & r2)) == 0)) {
        r0 = GCALL1(0x06056518, r8);
    } else {
        r5 = r4;
        if (((r0 & 2) & (r0 & 2)) == 0) {
            r0 = GCALL4(0x06058DF0, r8, r5, r6, r7);
            r0 = LD16((r8 + 12));
            r1 = 11;
            if (((r0 & 1) & (r0 & 1)) == 0) {
                ST16(r8, r1);
                ST8((r8 + 6), 4);
                r1 = LD16((r8 + 14));
                if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                    r1 = LD32(152 + r8);
                    ST32(152 + r8, (r1 + 1));
                }
                r0 = GCALL1(0x06056938, r8);
                r1 = LD32(0x0608D390);
                r4 = LD32(r8 + 164);
                r0 = GCALL1(r1, r4);
                r0 = r8;
                ST32(r0 + 176, 0);
                ST32(r0 + 164, 0);
            }
            r0 = 1;
        } else {
            r0 = GCALL4(0x06058148, r4, r5, r6, r7);
            r0 = GCALL1(0x06056518, r8);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056AA4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9;

    r9 = r5;
    r1 = LD16((r9 + 4));
    r2 = LD8(((r1 + r9) + 33));
    r8 = r4;
    if (((4 & r2) & (4 & r2)) == 0) {
        r5 = r9;
        if (((r2 & 2) & (r2 & 2)) == 0) {
            r0 = GCALL4(0x06058DF0, r8, r5, r6, r7);
            r5 = r9;
            if (!(r0 == -2)) {
                r0 = GCALL2(0x06056E34, r8, r5);
                r0 = LD16((r8 + 14));
                r1 = 11;
                if (!(((r0 & 8) & (r0 & 8)) == 0)) {
                    ST16(r8, r1);
                    r0 = GCALL1(0x06056938, r8);
                    r1 = LD32(0x0608D390);
                    r4 = LD32(r8 + 164);
                    r0 = GCALL1(r1, r4);
                    r0 = r8;
                    ST32(r0 + 176, 0);
                    ST32(r0 + 164, 0);
                }
            }
            r0 = 1;
        } else {
            r0 = GCALL4(0x06058148, r9, r5, r6, r7);
            r0 = GCALL2(0x0605723C, r8, -510);
        }
    } else {
        r0 = GCALL4(0x0605723C, r4, -510, r6, r7);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056B50(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, c7;

    r9 = r5;
    r1 = LD16((r9 + 4));
    r2 = LD8(((r1 + r9) + 33));
    r8 = r4;
    if (((4 & r2) & (4 & r2)) == 0) {
        r5 = r9;
        if (((r2 & 2) & (r2 & 2)) == 0) {
            r0 = GCALL4(0x06058DF0, r8, r5, r6, r7);
            r5 = r9;
            if (!(r0 == -2)) {
                r0 = GCALL2(0x06056E34, r8, r5);
                r0 = GCALL2(0x06058A6C, r8, r9);
                r3 = r8 + 14;
                r0 = LD16(r3);
                r1 = r8;
                if (((r0 & 8) & (r0 & 8)) == 0) {
                    r0 = LD16((r1 + 12));
                    r2 = r8;
                    if (((r0 & 1) & (r0 & 1)) == 0) {
                        ST8((r2 + 6), 4);
                        r1 = LD16(r3);
                        c7 = ((r1 & 0x200) & (r1 & 0x200)) == 0;
                        r1 = 7;
                        if (c7) {
                            r1 = LD32(152 + r8);
                            ST32(152 + r8, (r1 + 1));
                            r1 = 7;
                        }
                        ST16(r8, r1);
                    }
                } else {
                    r0 = LD16((r1 + 12));
                    r1 = 10;
                    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                        ST16(r8, r1);
                    } else {
                        ST16(r8, 11);
                        ST8((r8 + 6), 4);
                        r1 = LD16(r3);
                        if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                            r1 = LD32(152 + r8);
                            ST32(152 + r8, (r1 + 1));
                        }
                        r0 = GCALL1(0x06056938, r8);
                        r1 = LD32(0x0608D390);
                        r4 = LD32(r8 + 164);
                        r0 = GCALL1(r1, r4);
                        r0 = r8;
                        ST32(r0 + 176, 0);
                        ST32(r0 + 164, 0);
                    }
                }
            }
            r0 = 1;
        } else {
            r0 = GCALL4(0x06058148, r9, r5, r6, r7);
            r0 = GCALL2(0x0605723C, r8, -510);
        }
    } else {
        r0 = GCALL4(0x0605723C, r4, -510, r6, r7);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056C60(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;

    r8 = r5;
    r1 = LD16((r8 + 4));
    r0 = LD8(((r1 + r8) + 33));
    r9 = r4;
    if (((4 & r0) & (4 & r0)) == 0) {
        r4 = r8;
        if (!(((r0 & 2) & (r0 & 2)) == 0)) {
            r1 = LD32(0x0608D8C0);
            ST32(0x0608D8C0, (r1 + 1));
            r1 = LD32(0x0608D948);
            ST32(0x0608D948, (r1 - 1));
            r0 = GCALL4(0x06058148, r4, r5, r6, r7);
            r5 = -510;
            r0 = 0x0605723C;
            r4 = r9;
            r0 = GCALL2(r0, r4, r5);
        } else {
            r0 = GCALL4(0x06058DF0, r9, r8, r6, r7);
            r0 = GCALL2(0x06058A6C, r9, r8);
            r0 = 1;
        }
    } else {
        r5 = -510;
        r1 = LD32(0x0608D8C0);
        r0 = 0x0605723C;
        ST32(0x0608D8C0, (r1 + 1));
        r1 = LD32(0x0608D948);
        ST32(0x0608D948, (r1 - 1));
        r0 = GCALL2(r0, r4, r5);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056CF0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, c0;

    r8 = r4;
    r4 = r5;
    r1 = LD16((r4 + 4));
    r0 = LD8(((r1 + r4) + 33));
    c0 = ((4 & r0) & (4 & r0)) == 0;
    r0 = r0 & 2;
    if (!(c0)) {
        r0 = GCALL2(0x0605723C, r8, -510);
    } else {
        r5 = r4;
        if ((r0 & r0) == 0) {
            r0 = GCALL4(0x06058DF0, r8, r5, r6, r7);
            r0 = LD16((r8 + 12));
            r2 = r8;
            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                r0 = 1;
            } else {
                ST8((r2 + 6), 4);
                r1 = LD16((r8 + 14));
                if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                    r1 = LD32(152 + r8);
                    ST32(152 + r8, (r1 + 1));
                    r0 = 1;
                } else {
                    r0 = GCALL1(0x06056518, r8);
                    r0 = 1;
                }
            }
        } else {
            r0 = GCALL4(0x06058148, r4, r5, r6, r7);
            r0 = GCALL2(0x0605723C, r8, -510);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056D80(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;

    r8 = r5;
    r1 = LD16((r8 + 4));
    r0 = LD8(((r1 + r8) + 33));
    r9 = r4;
    if (((4 & r0) & (4 & r0)) == 0) {
        r4 = r8;
        if (((r0 & 2) & (r0 & 2)) == 0) {
            r0 = GCALL4(0x06058DF0, r9, r8, r6, r7);
            r5 = r8;
            if (!(r0 == -2)) {
                r0 = GCALL2(0x06056E34, r9, r5);
                r0 = GCALL2(0x06058A6C, r9, r8);
                r0 = LD16((r9 + 14));
                r1 = 8;
                if (!(((r0 & 8) & (r0 & 8)) == 0)) {
                    ST16(r9, r1);
                }
            }
            r0 = 1;
        } else {
            r1 = LD32(0x0608D8C0);
            ST32(0x0608D8C0, (r1 + 1));
            r1 = LD32(0x0608D948);
            ST32(0x0608D948, (r1 - 1));
            r0 = GCALL4(0x06058148, r4, r5, r6, r7);
            r0 = GCALL2(0x0605723C, r9, -510);
        }
    } else {
        r1 = LD32(0x0608D8C0);
        ST32(0x0608D8C0, (r1 + 1));
        r1 = LD32(0x0608D948);
        ST32(0x0608D948, (r1 - 1));
        r0 = GCALL4(0x0605723C, r4, -510, r6, r7);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605704C(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r11, c3;

    r10 = r4;
    r9 = r6;
    r11 = r5;
    if ((r9 & r9) == 0) {
        r0 = 1;
    } else {
        r0 = LD32(0x0608D3A0);
        r0 = GCALL3(r0, 8, r5, r6);
        r8 = r0;
        if ((r8 & r8) == 0) {
            r0 = 1;
        } else {
            ST32(r8, r11);
            ST32(r8 + 4, r9);
            r9 = 208;
            r0 = r10;
            r1 = LD32(r0 + 208);
            if ((r1 & r1) == 0) {
                r0 = GCALL1(0x0605DDA0, 10);
                ST32(r10 + r9, r0);
                r0 = r10;
            }
            r6 = LD32(r8);
            r5 = r8;
            r4 = LD32(r0 + r9);
            r6 = -r6;
            r0 = GCALL3(0x0605DCAC, r4, r5, r6);
            c3 = r0 >= 0;
            r0 = 1;
            if (!(c3)) {
                r1 = LD32(0x0608D390);
                r0 = GCALL3(r1, r8, r5, r6);
                r0 = 1;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605723C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, c0;

    r10 = r4;
    r9 = r5;
    r0 = GCALL4(0x06058784, r4, 0, r6, r7);
    r8 = r10 + 14;
    r0 = LD16(r8);
    ST16(r8, (r0 | 24));
    ST16((r10 + 16), r9);
    r0 = GCALL2(0x060583A4, 3, r10);
    r1 = LD16(r8);
    c0 = ((r1 & 0x200) & (r1 & 0x200)) == 0;
    r1 = r10;
    if (!(c0)) {
        r0 = LD8((r1 + 6));
        if (r0 == 3) {
            r0 = GCALL1(0x06056518, r10);
        }
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060573E0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, c6, c9;

    r8 = r4;
    r9 = r5;
    r1 = LD16((r9 + 4));
    r2 = r9 + r1;
    r0 = LD8((r2 + 33));
    r3 = r2 + 20;
    if (((r0 & 16) & (r0 & 16)) == 0) {
        r10 = r3;
        r10 = r10 + 13;
        r2 = LD8(r10);
        r1 = 1;
        if (((4 & r2) & (4 & r2)) == 0) {
            r1 = r3;
            if (((r2 & 2) & (r2 & 2)) == 0) {
                r0 = 1;
            } else {
                r0 = r8;
                r1 = LD16((r1 + 14));
                ST32(r8 + 52, (r1 & 0xFFFF));
                r1 = LD32(r3 + 4);
                ST32(r8 + 56, r1);
                r2 = LD32(r3 + 4);
                ST32((r8 + 104), r2);
                r1 = LD32(r0 + 196);
                ST32(r0 + 204, (r2 + r1));
                r0 = GCALL4(0x06058DF0, r8, r9, r6, r7);
                r0 = GCALL2(0x06056E34, r8, r9);
                r1 = LD8(r10);
                ST8(r10, (r1 & 254));
                r1 = LD16((r8 + 12));
                c6 = ((r1 & 2) & (r1 & 2)) == 0;
                r1 = 4;
                if (c6) {
                    r2 = LD32(0x0608D948);
                    r3 = r8 + 6;
                    ST32(0x0608D948, (r2 + 1));
                    ST16(r8, 5);
                    r0 = LD8(r3);
                    r1 = r8;
                    if (r0 == 1) {
                        ST8(r3, 2);
                        r1 = r8;
                    }
                    r1 = LD16((r1 + 14));
                    if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                        r1 = LD32(152 + r8);
                        ST32(152 + r8, (r1 + 1));
                        r0 = 1;
                    } else {
                        r0 = LD8(r3);
                        c9 = r0 == 2;
                        r0 = 1;
                        if (!(c9)) {
                            r0 = GCALL1(0x0605909C, r8);
                            r0 = 1;
                        }
                    }
                } else {
                    ST16(r8, r1);
                    r0 = 1;
                }
            }
        } else {
            ST16(r8, r1);
            ST16((r8 + 16), -510);
            r1 = LD32(0x0608D938);
            ST32(0x0608D938, (r1 + 1));
            r0 = GCALL4(0x06058784, r8, 0, r6, r7);
            r1 = LD16((r8 + 14));
            r0 = 1;
            if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                r1 = LD32(152 + r8);
                ST32(152 + r8, (r1 + 1));
                r0 = 1;
            }
        }
    } else {
        r2 = LD32(r2 + 28);
        r1 = LD32((r8 + 76));
        if (!((r2 - r1) > 0)) {
            r0 = GCALL4(0x06058148, r9, r5, r6, r7);
        } else {
            r1 = LD32(r8 + 44);
            r10 = r3;
            if (!((r2 - r1) > 0)) {
                r10 = r10 + 13;
                r2 = LD8(r10);
                r1 = 1;
                if (((4 & r2) & (4 & r2)) == 0) {
                    r1 = r3;
                    if (((r2 & 2) & (r2 & 2)) == 0) {
                        r0 = 1;
                    } else {
                        r0 = r8;
                        r1 = LD16((r1 + 14));
                        ST32(r8 + 52, (r1 & 0xFFFF));
                        r1 = LD32(r3 + 4);
                        ST32(r8 + 56, r1);
                        r2 = LD32(r3 + 4);
                        ST32((r8 + 104), r2);
                        r1 = LD32(r0 + 196);
                        ST32(r0 + 204, (r2 + r1));
                        r0 = GCALL4(0x06058DF0, r8, r9, r6, r7);
                        r0 = GCALL2(0x06056E34, r8, r9);
                        r1 = LD8(r10);
                        ST8(r10, (r1 & 254));
                        r1 = LD16((r8 + 12));
                        c6 = ((r1 & 2) & (r1 & 2)) == 0;
                        r1 = 4;
                        if (c6) {
                            r2 = LD32(0x0608D948);
                            r3 = r8 + 6;
                            ST32(0x0608D948, (r2 + 1));
                            ST16(r8, 5);
                            r0 = LD8(r3);
                            r1 = r8;
                            if (r0 == 1) {
                                ST8(r3, 2);
                                r1 = r8;
                            }
                            r1 = LD16((r1 + 14));
                            if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                                r1 = LD32(152 + r8);
                                ST32(152 + r8, (r1 + 1));
                                r0 = 1;
                            } else {
                                r0 = LD8(r3);
                                c9 = r0 == 2;
                                r0 = 1;
                                if (!(c9)) {
                                    r0 = GCALL1(0x0605909C, r8);
                                    r0 = 1;
                                }
                            }
                        } else {
                            ST16(r8, r1);
                            r0 = 1;
                        }
                    }
                } else {
                    ST16(r8, r1);
                    ST16((r8 + 16), -510);
                    r1 = LD32(0x0608D938);
                    ST32(0x0608D938, (r1 + 1));
                    r0 = GCALL4(0x06058784, r8, 0, r6, r7);
                    r1 = LD16((r8 + 14));
                    r0 = 1;
                    if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                        r1 = LD32(152 + r8);
                        ST32(152 + r8, (r1 + 1));
                        r0 = 1;
                    }
                }
            } else {
                r0 = GCALL4(0x06058148, r9, r5, r6, r7);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06057538(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, c3, c7, c8;

    r10 = r5;
    r1 = LD16((r10 + 4));
    r2 = LD8(((r1 + r10) + 33));
    r9 = r4;
    if (((4 & r2) & (4 & r2)) == 0) {
        r4 = r10;
        if (((r2 & 2) & (r2 & 2)) == 0) {
            r0 = GCALL4(0x06058DF0, r9, r10, r6, r7);
            c3 = r0 == -2;
            r0 = 1;
            if (!(c3)) {
                r1 = LD32(148 + r9);
                r8 = r1;
                if ((r1 & r1) == 0) {
                    r2 = r9 + 6;
                    r0 = LD8(r2);
                    r1 = r9;
                    if (r0 == 1) {
                        ST8(r2, 2);
                        r1 = r9;
                    }
                    r1 = LD16((r1 + 14));
                    if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                        r1 = LD32(152 + r9);
                        ST32(152 + r9, (r1 + 1));
                    }
                    r2 = LD32(0x0608D948);
                    r8 = r9 + 6;
                    ST32(0x0608D948, (r2 + 1));
                    ST16(r9, 5);
                    r0 = LD8(r8);
                    r1 = 2;
                    if (r0 == 1) {
                        ST8(r8, r1);
                    }
                    r0 = GCALL2(0x06056E34, r9, r10);
                    r1 = LD16((r9 + 14));
                    if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                        r1 = r9;
                    } else {
                        r0 = LD8(r8);
                        r1 = r9;
                        if (r0 == 3) {
                            r0 = GCALL1(0x0605909C, r9);
                            r1 = r9;
                        }
                    }
                    r0 = LD16((r1 + 14));
                    r1 = 8;
                    if (!(((r0 & 8) & (r0 & 8)) == 0)) {
                        ST16(r9, r1);
                    }
                    r0 = 1;
                } else {
                    r2 = LD32(r8 + 8);
                    r1 = r2;
                    if (r2 == ((int)0x80000000)) {
                        r1 = -2;
                    } else {
                        ST32(r8 + 8, (r1 - 1));
                        r1 = 1;
                    }
                    r4 = r10;
                    if (r1 == 1) {
                        r0 = LD16(r8);
                        c7 = r0 == 2;
                        r0 = r8;
                        if (c7) {
                            r11 = 144;
                            r4 = LD32(r0 + 144);
                            r0 = GCALL1(0x0605EB28, r4);
                            r1 = LD32(r8 + 140);
                            c8 = r0 >= r1;
                            r0 = r9;
                            if (!(c8)) {
                                r5 = LD32(r0 + 156);
                                r4 = LD32(r8 + r11);
                                r0 = GCALL2(0x0605EB6C, r4, r5);
                                r1 = LD32(r8 + 8);
                                ST32(r8 + 8, (r1 + 1));
                                r2 = LD32(0x0608D948);
                                r8 = r9 + 6;
                                ST32(0x0608D948, (r2 + 1));
                                ST16(r9, 5);
                                r0 = LD8(r8);
                                r1 = 2;
                                if (r0 == 1) {
                                    ST8(r8, r1);
                                }
                                r0 = GCALL2(0x06056E34, r9, r10);
                                r1 = LD16((r9 + 14));
                                if (((r1 & 0x200) & (r1 & 0x200)) == 0) {
                                    r1 = r9;
                                } else {
                                    r0 = LD8(r8);
                                    r1 = r9;
                                    if (r0 == 3) {
                                        r0 = GCALL1(0x0605909C, r9);
                                        r1 = r9;
                                    }
                                }
                                r0 = LD16((r1 + 14));
                                r1 = 8;
                                if (!(((r0 & 8) & (r0 & 8)) == 0)) {
                                    ST16(r9, r1);
                                }
                                r0 = 1;
                            } else {
                                r1 = LD32(0x0608D938);
                                ST32(0x0608D938, (r1 + 1));
                                r1 = LD32(r8 + 8);
                                ST32(r8 + 8, (r1 + 1));
                                r0 = GCALL1(0x06056518, r9);
                            }
                        } else {
                            r1 = LD32(0x0608D938);
                            ST32(0x0608D938, (r1 + 1));
                            r0 = GCALL1(0x06058148, r4);
                            r1 = LD32(r8 + 8);
                            ST32(r8 + 8, (r1 + 1));
                            r0 = GCALL1(0x06056518, r9);
                        }
                    } else {
                        r1 = LD32(0x0608D938);
                        ST32(0x0608D938, (r1 + 1));
                        r0 = GCALL1(0x06058148, r4);
                        r0 = GCALL1(0x06056518, r9);
                    }
                }
            }
        } else {
            r1 = LD32(0x0608D938);
            ST32(0x0608D938, (r1 + 1));
            r0 = GCALL4(0x06058148, r4, r5, r6, r7);
            r5 = -510;
            r0 = GCALL2(0x0605723C, r9, r5);
        }
    } else {
        r2 = LD32(0x0608D938);
        ST32(0x0608D938, (r2 + 1));
        r1 = LD32(148 + r9);
        if ((r1 & r1) == 0) {
            r5 = -511;
            r0 = GCALL2(0x0605723C, r9, r5);
        } else {
            r0 = GCALL4(0x06056518, r4, 0, r6, r7);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06057704(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13;

    r10 = r4;
    r11 = r5;
    r1 = LD16((r11 + 4));
    r9 = r11 + r1;
    r12 = r9 + 33;
    r2 = LD8(r12);
    r13 = r9 + 20;
    if (!(((4 & r2) & (4 & r2)) == 0)) {
        r0 = 1;
    } else {
        if ((r2 & 18) == 2) {
            r0 = GCALL4(0x060563F0, 0, 0, r6, r7);
            r8 = r0;
            if (r0 == -2) {
                r0 = -2;
            } else {
                r0 = GCALL1(0x06057298, r8);
                r1 = 4;
                if (!(r0 == -2)) {
                    ST16(r8, r1);
                    ST16((r8 + 2), 0);
                    ST16((r8 + 16), 0);
                    ST32(r8 + 148, r10);
                    r1 = LD16((r10 + 36));
                    ST16((r8 + 36), r1);
                    r1 = LD16((r10 + 38));
                    ST16((r8 + 38), r1);
                    r1 = LD16((r9 + 12));
                    ST16((r8 + 20), r1);
                    r1 = LD16((r9 + 14));
                    ST16((r8 + 22), r1);
                    r1 = LD16(r13);
                    ST16((r8 + 18), r1);
                    r1 = LD16((r9 + 16));
                    ST16((r8 + 24), r1);
                    r1 = LD16((r9 + 18));
                    ST16((r8 + 26), r1);
                    r1 = LD16((r9 + 22));
                    ST16((r8 + 28), r1);
                    r0 = GCALL3(0x0605785C, r10, r8, r11);
                    r0 = r8;
                    ST32(r0 + 216, 0);
                    ST32(r0 + 212, 0);
                    ST8((r8 + 6), 1);
                    r2 = r8 + 14;
                    ST16(r2, 1);
                    r1 = LD16((r10 + 14));
                    r0 = 0x200;
                    if (!((((short)(r1 & 0x200)) & ((short)(r1 & 0x200))) == 0)) {
                        ST16(r2, (r0 | 1));
                    }
                    r1 = LD32(0x0608D924);
                    ST32(0x0608D924, (r1 + 1));
                    r0 = LD8(r12);
                    ST8(r12, (r0 & 254));
                    r0 = GCALL2(0x06056E34, r8, r11);
                    r1 = LD32(r8 + 8);
                    ST32(r8 + 8, (r1 + 1));
                    r0 = 1;
                } else {
                    r0 = -2;
                }
            }
        } else {
            r0 = GCALL4(0x06058148, r11, r5, r6, r7);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060579FC(void)
{
    int r0, r1, r2, r4, r8, r9, r10, r11, r12, c5;

    r9 = LD32(0x0608D890);
    r0 = 0;
    r1 = LD32(0x0608D88C);
    r10 = 0;
    if (!(0 >= r1)) {
        r11 = 0x0608D874;
        r12 = 0x06058838;
        r1 = r9;
        do {
            r1 = LD8((r1 + 7));
            if (!((r1 & r1) == 0)) {
                r8 = 1 | ((r10 << 2) + (r10 << 2));
                r0 = LD16((r9 + 14));
                if (((r0 & 32) & (r0 & 32)) == 0) {
                    r4 = LD32(r11);
                    r0 = GCALL1(0x0605EB28, r4);
                    if (!(r0 > 19)) {
                        r4 = LD32(r11);
                        r0 = GCALL2(0x0605EB6C, r4, r8);
                    }
                    r2 = r9;
                } else {
                    r4 = LD32(r11);
                    r0 = GCALL2(0x060587DC, r4, r8);
                    if (!((r0 & r0) == 0)) {
                        r4 = LD32(r11);
                        r0 = GCALL1(0x0605EB28, r4);
                        if (!(r0 > 19)) {
                            r4 = LD32(r11);
                            r0 = GCALL2(0x0605EB6C, r4, r8);
                        }
                        r2 = r9;
                    } else {
                        r4 = LD32(r11);
                        r0 = GCALL4(r12, r4, 20, r8, 20);
                        r2 = r9;
                    }
                }
                ST8((r2 + 7), 0);
                r0 = 1;
            }
            r9 = r9 + 220;
            r1 = LD32(0x0608D88C);
            r10 = r10 + 1;
            c5 = r10 >= r1;
            r1 = r9;
        } while (AGAIN(!(c5)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06057B38(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, c5, c8, c9;

    r11 = r4;
    r8 = r5;
    r1 = LD32(0x0608D890);
    r9 = r1 + (r11 * 220);
    if (!(r8 == 3)) {
        r0 = GCALL1(0x06059434, r11);
        r12 = 0x06058114;
        r0 = GCALL1(0x06058114, r9);
        r1 = r9;
        if (!((r0 & r0) == 0)) {
            r1 = LD32(r9 + 52);
            c5 = (r1 & r1) == 0;
            r1 = r9;
            if (!(c5)) {
                ST16((r1 + 2), 2);
                r10 = LD32(r9 + 52);
                r1 = LD32((r9 + 64));
                if (r10 > r1) {
                    r10 = r1;
                }
                r13 = r12;
                r2 = LD32(r9 + 44);
                r12 = 0x06057C88;
                while (1) {
                    r1 = LD32(r9 + 40);
                    r8 = r2 - r1;
                    r0 = GCALL1(r13, r9);
                    c8 = r8 > r10;
                    if (!(r0 > 0)) {
                        break;
                    } else {
                        r5 = 0;
                        if (c8) {
                            break;
                        } else {
                            r0 = GCALL2(r12, r11, r5);
                            r2 = LD32(r9 + 44);
                        }
                    }
                    POLL();
                }
                r0 = r11;
                r8 = 3 | ((r0 << 2) + (r0 << 2));
                r10 = 0x0608D874;
                r4 = LD32(0x0608D874);
                r0 = GCALL2(0x060587DC, r4, r8);
                c9 = (r0 & r0) == 0;
                r0 = 1;
                if (c9) {
                    r0 = 0x06058838;
                    r7 = LD32((r9 + 96));
                    r6 = r8;
                    r4 = LD32(r10);
                    r0 = GCALL4(r0, r4, 20, r6, r7);
                    r0 = 1;
                }
            } else {
                ST16((r9 + 2), 1);
                r8 = r9 + 88;
                r1 = LD32((r9 + 96));
                ST32(r8, r1);
                r0 = GCALL2(0x06057C88, r11, 0);
                r0 = 0x06058838;
                r7 = LD32(r8);
                r6 = 2 | ((r11 << 2) + (r11 << 2));
                r4 = LD32(0x0608D874);
                r0 = GCALL4(r0, r4, 20, r6, r7);
                r0 = 1;
            }
        } else {
            r0 = LD16((r1 + 14));
            r5 = 0;
            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                r0 = GCALL2(0x06057C88, r11, r5);
            }
            r2 = LD32(r9 + 44);
            r1 = LD32(r9 + 40);
            r0 = 1;
            if (!(r2 == r1)) {
                r0 = r11;
                r8 = 3 | ((r0 << 2) + (r0 << 2));
                r10 = 0x0608D874;
                r4 = LD32(0x0608D874);
                r0 = GCALL2(0x060587DC, r4, r8);
                c9 = (r0 & r0) == 0;
                r0 = 1;
                if (c9) {
                    r0 = 0x06058838;
                    r7 = LD32((r9 + 96));
                    r6 = r8;
                    r4 = LD32(r10);
                    r0 = GCALL4(r0, r4, 20, r6, r7);
                    r0 = 1;
                }
            }
        }
    } else {
        r4 = LD32(0x0608D874);
        r0 = GCALL4(0x0605ED4C, r4, (1 | ((r11 << 2) + (r11 << 2))), r6, r7);
        r0 = GCALL2(0x06058924, r11, r8);
        ST16((r9 + 2), 3);
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058784(int r4, int r5, int r6, int r7)
{
    int r0, r1, r10;

    r1 = LD32(0x0608D890);
    r10 = (((((r4 - r1) * 0x586FB587) >> 1) >> 1) << 2) + (((((r4 - r1) * 0x586FB587) >> 1) >> 1) << 2);
    r4 = LD32(0x0608D874);
    r0 = GCALL4(0x0605ED4C, r4, (1 | r10), r6, r7);
    r4 = LD32(0x0608D874);
    r0 = GCALL2(0x0605ED4C, r4, (3 | r10));
    r4 = LD32(0x0608D874);
    r0 = GCALL2(0x0605ED4C, r4, (r10 | 2));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058838(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, c4;

    r11 = r4;
    r12 = r5;
    r10 = r6;
    r9 = r7;
    r0 = GCALL0(0x0605EDF8);
    r8 = r0;
    r0 = -3;
    if (!((r8 & r8) == 0)) {
        ST32(r8, r9);
        r0 = LD32(0x0608D39C);
        r0 = GCALL4(r0, r4, r5, r6, r7);
        r5 = LD32(0x0608D394);
        r0 = GCALL2(0x060745A0, ((r0 * 100) + ((int)((unsigned)r5 >> 1))), r5);
        ST32(r8 + 4, r0);
        ST32(r8 + 8, r11);
        ST32(r8 + 12, r12);
        ST32(r8 + 16, r10);
        ST32(r8 + 20, 0);
        r0 = GCALL2(0x0605ED4C, r11, r10);
        r3 = 0x0608D868;
        r2 = LD32(0x0608D868);
        r1 = r2;
        if (!(r2 == ((int)0x80000000))) {
            ST32(r3, (r1 - 1));
        }
        r2 = 0x0608D888;
        r1 = LD32(0x0608D888);
        r7 = 0;
        if (!((r1 & r1) == 0)) {
            r3 = r1;
            while (1) {
                r1 = LD32(r8);
                r2 = LD32(r3);
                c4 = r1 >= r2;
                r1 = r1 - r2;
                if (!(c4)) {
                    break;
                } else {
                    ST32(r8, r1);
                    r7 = r3;
                    r3 = LD32(r3 + 20);
                    if (!((r3 & r3) == 0)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
            ST32(r8 + 20, r3);
            if ((r7 & r7) == 0) {
                ST32(0x0608D888, r8);
            } else {
                ST32(r7 + 20, r8);
            }
            if (!((r3 & r3) == 0)) {
                r1 = LD32(r3);
                r2 = LD32(r8);
                ST32(r3, (r1 - r2));
            }
            r1 = LD32(0x0608D868);
            ST32(0x0608D868, (r1 + 1));
        } else {
            ST32(r2, r8);
            r1 = LD32(r3);
            ST32(r3, (r1 + 1));
        }
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058924(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10;

    r10 = r4;
    r1 = LD32(0x0608D890);
    r9 = r1 + (r10 * 220);
    if (r5 == 3) {
        r8 = r9 + 100;
        r1 = LD32(r8);
        r1 = r1 + 1;
        ST32(r8, r1);
        if (!(r1 > 30)) {
            r0 = GCALL2(0x06057C88, r10, 1);
            r4 = LD32((r9 + 96));
            r5 = LD32(r8);
            r0 = GCALL2(0x0607290C, r4, r5);
            r2 = r0;
            r0 = 0x7D0;
            if (r2 > 0x7D0) {
                r2 = r0;
            }
            r4 = LD32(0x0608D874);
            r0 = GCALL4(0x06058838, r4, 20, (3 | ((r10 << 2) + (r10 << 2))), r2);
            r0 = LD16((r9 + 2));
            r1 = r9;
            if (!(r0 == 3)) {
                r2 = LD32((r9 + 64));
                ST32((r1 + 68), r2);
            }
            r2 = LD32(r9 + 52);
            r3 = r9 + 68;
            r1 = LD32(r3);
            if (r2 > r1) {
                r2 = r1;
            }
            r1 = (((int)((unsigned)r2 >> 31)) + r2) >> 1;
            ST32(r3, r1);
            r7 = r9 + 72;
            r2 = LD32(r7);
            if (!(r1 >= r2)) {
                ST32(r3, r2);
            }
            r1 = LD32(r7);
            r0 = 1;
            ST32((r9 + 64), r1);
        } else {
            r0 = LD16(r9);
            if (r0 == 3) {
                r0 = GCALL4(0x060565F8, r9, r5, r6, r7);
            }
            r0 = GCALL2(0x0605723C, r9, -513);
            r0 = 1;
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605909C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8;

    r1 = LD32(0x0608D948);
    r8 = r4;
    ST32(0x0608D948, (r1 - 1));
    r0 = LD16(r8);
    r3 = r8;
    if (!(r0 == 8)) {
        r0 = GCALL4(0x060565F8, r8, r5, r6, r7);
        r0 = GCALL2(0x0605723C, r8, -507);
        r0 = 0x06056518;
        r4 = r8;
    } else {
        r3 = r3 + 14;
        r1 = LD16(r3);
        ST16(r3, (r1 | 0x100));
        r1 = LD32(r8 + 40);
        r2 = LD32(172 + r8);
        ST32(r8 + 48, (r1 + r2));
        ST16(r8, 9);
        r0 = LD16(r3);
        ST16(r3, (r0 | 1));
        r0 = 0x06058918;
    }
    r0 = GCALL1(r0, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060594A0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c4, c6;

    r11 = r4;
    r9 = r5;
    r12 = r6;
    r13 = 136;
    r4 = LD32(r11 + 136);
    r10 = 0;
    if ((r4 & r4) == 0) {
        r0 = r9;
    } else {
        r0 = GCALL1(0x0605DD2C, r4);
        r8 = r0;
        if ((r8 & r8) == 0) {
            r4 = LD32(r11 + 136);
            r0 = GCALL1(0x0605DE08, r4);
            ST32(r11 + 136, 0);
            r0 = r9;
        } else {
            r14 = 0x06059A0C;
            while (1) {
                r3 = LD32(r11 + 44);
                r2 = LD32(r8 + 4);
                r1 = ((r3 + r9) - 1) - r2;
                if (r1 > 0) {
                    r10 = r1;
                }
                if (r10 >= r9) {
                    r1 = LD32(r8 + 8);
                    r10 = (r1 + r2) - r3;
                    if (r10 > 0) {
                        r1 = LD32(r12);
                        r1 = r1 + r10;
                        ST32(r12, r1);
                        r2 = LD32(176 + r11);
                        c6 = r1 > r2;
                        r1 = r1 - r2;
                        if (c6) {
                            ST32(r12, r1);
                        }
                        r9 = r9 - r10;
                        if (!(r9 >= 0)) {
                            r9 = 0;
                        }
                    }
                    r0 = GCALL1(r14, r8);
                    r4 = LD32(r11 + r13);
                    r0 = GCALL1(0x0605DD2C, r4);
                    r8 = r0;
                    if (!((r8 & r8) == 0)) {
                        POLL();
                        continue;
                    } else {
                        r4 = LD32(r11 + 136);
                        r0 = GCALL1(0x0605DE08, r4);
                        ST32(r11 + 136, 0);
                        r0 = r9;
                        break;
                    }
                } else {
                    r9 = r9 - r10;
                    r0 = r11;
                    r6 = LD32(r0 + 132);
                    r5 = r8;
                    r4 = LD32(r0 + r13);
                    r6 = r6 - r2;
                    r0 = GCALL3(0x0605DCAC, r4, r5, r6);
                    c4 = r0 >= 0;
                    r0 = r9;
                    if (c4) {
                        break;
                    } else {
                        r0 = GCALL3(r14, r8, r5, r6);
                        r0 = r9;
                        break;
                    }
                }
                POLL();
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059580(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r8, r9, r10, r11, r12, r13, c7;

    r13 = r4;
    r0 = LD16((r5 + 4));
    r9 = r5 + r0;
    r2 = LD16((r9 + 2));
    r3 = r9 + 38;
    r0 = LD8(r0 + r5);
    r2 = (r2 & 0xFFFF) - ((r0 & 15) << 2);
    r0 = LD8((r9 + 32));
    r12 = r2 - ((int)((unsigned)(r0 & 240) >> 2));
    r1 = LD16(r3);
    r2 = r1 & 0xFFFF;
    r10 = r9 + 20;
    if (r2 >= r12) {
        ST16(r3, (r12 - 1));
    } else {
        if ((unsigned)r2 > (unsigned)0x5E3) {
            ST16(r3, (r12 - 1));
        }
    }
    r0 = GCALL0(0x06059968);
    r8 = r0;
    if (r0 == -2) {
        r0 = -2;
    } else {
        r1 = LD32(r10 + 4);
        ST32(r8 + 4, r1);
        r4 = LD16((r10 + 18));
        r4 = (r4 & 0xFFFF) + 1;
        ST32(r8 + 8, r4);
        r0 = LD32(0x0608D3A0);
        r0 = GCALL1(r0, r4);
        r2 = r0;
        ST32(r8 + 12, r2);
        if (!((r2 & r2) == 0)) {
            r0 = LD8((r10 + 12));
            r6 = LD32(r8 + 8);
            r0 = GCALL3(0x0604B358, r2, ((((int)((unsigned)(r0 & 240) >> 2)) + r9) + 20), r6);
            r11 = r13 + 112;
            r1 = LD32(r11);
            r2 = r13;
            if (!((r1 & r1) == 0)) {
                r2 = LD32(r8 + 8);
                r1 = r13;
                if (r12 > r2) {
                    r1 = LD32(r10 + 4);
                    ST32(r10 + 4, (r1 + r2));
                    r0 = LD8((r10 + 12));
                    r1 = LD32(r8 + 8);
                    r0 = GCALL3(0x0604B358, ((((int)((unsigned)(r0 & 240) >> 2)) + r9) + 20), (((((int)((unsigned)(r0 & 240) >> 2)) + r1) + r9) + 20), (r12 - r1));
                    ST16((r10 + 18), 0);
                    r2 = LD32(r8 + 8);
                    r3 = r9 + 2;
                    r1 = LD16(r3);
                    ST16(r3, (r1 - r2));
                    r1 = r13;
                }
                r6 = LD32((r1 + 108));
                r1 = LD32(r8 + 4);
                r4 = LD32((r13 + 112));
                r0 = GCALL3(0x0605DCAC, r4, r8, (r6 - r1));
                c7 = r0 >= 0;
                r0 = c7;
                if (!(c7)) {
                    r0 = GCALL1(0x06059A0C, r8);
                    r0 = -2;
                }
            } else {
                r1 = LD32((r13 + 104));
                ST32((r2 + 108), r1);
                r0 = GCALL1(0x0605DDA0, 5);
                ST32(r11, r0);
                if ((r0 & r0) == 0) {
                    r0 = GCALL1(0x06059A0C, r8);
                    r0 = -2;
                } else {
                    r2 = LD32(r8 + 8);
                    r1 = r13;
                    if (r12 > r2) {
                        r1 = LD32(r10 + 4);
                        ST32(r10 + 4, (r1 + r2));
                        r0 = LD8((r10 + 12));
                        r1 = LD32(r8 + 8);
                        r0 = GCALL3(0x0604B358, ((((int)((unsigned)(r0 & 240) >> 2)) + r9) + 20), (((((int)((unsigned)(r0 & 240) >> 2)) + r1) + r9) + 20), (r12 - r1));
                        ST16((r10 + 18), 0);
                        r2 = LD32(r8 + 8);
                        r3 = r9 + 2;
                        r1 = LD16(r3);
                        ST16(r3, (r1 - r2));
                        r1 = r13;
                    }
                    r6 = LD32((r1 + 108));
                    r1 = LD32(r8 + 4);
                    r4 = LD32((r13 + 112));
                    r0 = GCALL3(0x0605DCAC, r4, r8, (r6 - r1));
                    c7 = r0 >= 0;
                    r0 = c7;
                    if (!(c7)) {
                        r0 = GCALL1(0x06059A0C, r8);
                        r0 = -2;
                    }
                }
            }
        } else {
            ST32(r8 + 12, 0);
            r0 = GCALL1(0x06059A0C, r8);
            r0 = -2;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605987C(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r11, c1, c2;

    r9 = r4;
    r10 = r5;
    r11 = r6;
    r0 = GCALL0(0x06059968);
    r8 = r0;
    if (r0 == -2) {
        r0 = -2;
    } else {
        r1 = LD32(r9 + 40);
        ST32(r8 + 4, (r1 + r10));
        ST32(r8 + 8, r11);
        ST32(r8 + 12, 0);
        r10 = 128;
        r1 = LD32(r9 + 128);
        c1 = (r1 & r1) == 0;
        r1 = r9;
        if (c1) {
            r0 = GCALL1(0x0605DDA0, 5);
            ST32(r9 + r10, r0);
            r1 = LD32(r8 + 4);
            ST32((r9 + 124), r1);
            r1 = r9;
        }
        r6 = LD32((r1 + 124));
        r4 = LD32(r9 + r10);
        r5 = r8;
        r1 = LD32(r8 + 4);
        r6 = r6 - r1;
        r0 = GCALL3(0x0605DCAC, r4, r5, r6);
        c2 = r0 >= 0;
        r0 = r11;
        if (!(c2)) {
            r0 = GCALL3(0x06059A0C, r8, r5, r6);
            r0 = -2;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059904(int r4, int r5)
{
    int r0, r1, r6, r8, r9, r10, c0;

    r10 = r4;
    r9 = r5;
    r1 = LD32(0x0608D390);
    r4 = LD32(r9 + 12);
    r0 = GCALL2(r1, r4, r5);
    ST32(r9 + 12, 0);
    r8 = r10 + 120;
    r1 = LD32(r8);
    c0 = (r1 & r1) == 0;
    r1 = r10;
    if (c0) {
        r0 = GCALL1(0x0605DDA0, 5);
        ST32(r8, r0);
        r1 = r10;
    }
    r6 = LD32((r1 + 116));
    r1 = LD32(r9 + 4);
    r5 = r9;
    r4 = LD32(r8);
    r6 = r6 - r1;
    r0 = GCALL3(0x0605DCAC, r4, r5, r6);
    if (!(r0 >= 0)) {
        r0 = GCALL3(0x06059A0C, r9, r5, r6);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059F5C(int r4)
{
    int r0, r1, r5, r6, r7, r8;

    r8 = r4;
    r5 = LD32(r8 + 24);
    r4 = LD32(r8 + 28);
    ST16((r5 + 4), 53);
    ST16((r5 + 6), 0);
    ST16((r5 + 10), 0x100);
    r7 = r5 + 14;
    ST16((r5 + 18), 0);
    ST16((r5 + 16), 0);
    ST16(r7, 0);
    r6 = LD32(r8 + 32);
    r0 = GCALL4(0x0605B0D8, r4, r5, r6, r7);
    if (r0 >= 0) {
        r0 = LD32(0x0608D39C);
        r0 = GCALL0(r0);
        r1 = LD32(0x0608D394);
        ST32(r8 + 20, ((r1 + r1) + r0));
        r1 = 2;
        ST32(r8 + 8, r1);
    } else {
        r5 = r0;
        if (!(r0 == -502)) {
            r0 = GCALL2(0x06059F04, r8, r5);
        } else {
            r1 = 5;
            ST32(r8 + 8, r1);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06059FE0(int r4)
{
    int r0, r2, r5, r8, c1;

    r8 = r4;
    r0 = GCALL2(0x0605AE6C, 0, 0);
    r2 = r0;
    c1 = r2 >= 0;
    if (!(r2 == -531)) {
        r5 = r2;
        if (c1) {
            ST32(r8 + 28, r2);
            r0 = GCALL3(0x0605AF48, r2, 1, 25);
            r0 = GCALL1(0x06059F5C, r8);
        } else {
            r0 = GCALL2(0x06059F04, r8, r5);
        }
    } else {
        ST32(r8 + 8, 3);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605AF90(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, c7, c10;

    r8 = r4;
    r12 = r5;
    r11 = r6;
    r0 = GCALL4(0x0605299C, r4, r5, r6, r7);
    r1 = LD32(0x0608D9EC);
    r8 = (((r8 << 2) + (r8 << 2)) << 2) + r1;
    r3 = LD32(0x0608D9F0);
    r2 = LD32(r8 + 24);
    r2 = (r2 * 24) + r3;
    r0 = LD32(r2 + 16);
    r1 = 0;
    if ((r0 & r0) == 0) {
        r0 = LD32(r8 + 28);
        if (((r0 & 16) & (r0 & 16)) == 0) {
            r0 = LD32(r8 + 28);
            if (((r0 & 4) & (r0 & 4)) == 0) {
                r4 = LD32(r8 + 20);
                r0 = GCALL1(0x0605EC14, r4);
                r10 = r0;
                r1 = LD16((r10 + 4));
                r0 = LD32(r8 + 28);
                r5 = r10 + r1;
                r3 = r5 + 20;
                r1 = LD16((r5 + 24));
                r2 = r1 & 0xFFFF;
                r9 = r2 - 8;
                if (((r0 & 1) & (r0 & 1)) == 0) {
                    if (r9 > r11) {
                        r9 = r11;
                    }
                    r5 = r5 + 28;
                    r1 = 0x0604B358;
                    r6 = r9;
                    r4 = r12;
                    r0 = GCALL3(r1, r4, r5, r6);
                    r1 = LD32(0x0608D390);
                    r0 = GCALL1(r1, r10);
                    r0 = r9;
                } else {
                    c10 = r2 > r11;
                    if (r11 > 7) {
                        r1 = r5;
                        if (c10) {
                            r9 = r11 - 8;
                        }
                        r4 = r12 + 8;
                        r1 = LD16((r1 + 12));
                        r6 = r9;
                        ST16(r12, r1);
                        r1 = LD16((r5 + 14));
                        ST16((r12 + 2), r1);
                        r1 = LD16(r3);
                        ST16((r12 + 4), r1);
                        r1 = LD32(r8 + 8);
                        ST16((r12 + 6), r1);
                        r1 = 0x0604B358;
                        r5 = r5 + 28;
                        r0 = GCALL3(r1, r4, r5, r6);
                        r1 = LD32(0x0608D390);
                        r0 = GCALL1(r1, r10);
                        r0 = r9;
                    } else {
                        r1 = LD32(0x0608D390);
                        r0 = GCALL2(r1, r10, r5);
                        r0 = -2;
                    }
                }
            } else {
                r2 = LD32(r8 + 24);
                r4 = LD32(r8 + 20);
                r1 = LD32(0x0608D9F0);
                r9 = r1 + (r2 * 24);
                r0 = GCALL1(0x0605EB28, r4);
                if (r0 > 0) {
                    r4 = LD32(r8 + 20);
                    r0 = GCALL1(0x0605EC14, r4);
                    r10 = r0;
                    r1 = LD16((r10 + 4));
                    r0 = LD32(r8 + 28);
                    r5 = r10 + r1;
                    r3 = r5 + 20;
                    r1 = LD16((r5 + 24));
                    r2 = r1 & 0xFFFF;
                    r9 = r2 - 8;
                    if (((r0 & 1) & (r0 & 1)) == 0) {
                        if (r9 > r11) {
                            r9 = r11;
                        }
                        r5 = r5 + 28;
                        r1 = 0x0604B358;
                        r6 = r9;
                        r4 = r12;
                        r0 = GCALL3(r1, r4, r5, r6);
                        r1 = LD32(0x0608D390);
                        r0 = GCALL1(r1, r10);
                        r0 = r9;
                    } else {
                        c10 = r2 > r11;
                        if (r11 > 7) {
                            r1 = r5;
                            if (c10) {
                                r9 = r11 - 8;
                            }
                            r4 = r12 + 8;
                            r1 = LD16((r1 + 12));
                            r6 = r9;
                            ST16(r12, r1);
                            r1 = LD16((r5 + 14));
                            ST16((r12 + 2), r1);
                            r1 = LD16(r3);
                            ST16((r12 + 4), r1);
                            r1 = LD32(r8 + 8);
                            ST16((r12 + 6), r1);
                            r1 = 0x0604B358;
                            r5 = r5 + 28;
                            r0 = GCALL3(r1, r4, r5, r6);
                            r1 = LD32(0x0608D390);
                            r0 = GCALL1(r1, r10);
                            r0 = r9;
                        } else {
                            r1 = LD32(0x0608D390);
                            r0 = GCALL2(r1, r10, r5);
                            r0 = -2;
                        }
                    }
                } else {
                    r5 = LD32(r9 + 20);
                    r0 = GCALL2(0x0605F634, 30, r5);
                    c7 = r0 == -3;
                    r0 = -3;
                    if (!(c7)) {
                        r4 = LD32(r8 + 20);
                        r0 = GCALL1(0x0605EC14, r4);
                        r10 = r0;
                        r1 = LD16((r10 + 4));
                        r0 = LD32(r8 + 28);
                        r5 = r10 + r1;
                        r3 = r5 + 20;
                        r1 = LD16((r5 + 24));
                        r2 = r1 & 0xFFFF;
                        r9 = r2 - 8;
                        if (((r0 & 1) & (r0 & 1)) == 0) {
                            if (r9 > r11) {
                                r9 = r11;
                            }
                            r5 = r5 + 28;
                            r1 = 0x0604B358;
                            r6 = r9;
                            r4 = r12;
                            r0 = GCALL3(r1, r4, r5, r6);
                            r1 = LD32(0x0608D390);
                            r0 = GCALL1(r1, r10);
                            r0 = r9;
                        } else {
                            c10 = r2 > r11;
                            if (r11 > 7) {
                                r1 = r5;
                                if (c10) {
                                    r9 = r11 - 8;
                                }
                                r4 = r12 + 8;
                                r1 = LD16((r1 + 12));
                                r6 = r9;
                                ST16(r12, r1);
                                r1 = LD16((r5 + 14));
                                ST16((r12 + 2), r1);
                                r1 = LD16(r3);
                                ST16((r12 + 4), r1);
                                r1 = LD32(r8 + 8);
                                ST16((r12 + 6), r1);
                                r1 = 0x0604B358;
                                r5 = r5 + 28;
                                r0 = GCALL3(r1, r4, r5, r6);
                                r1 = LD32(0x0608D390);
                                r0 = GCALL1(r1, r10);
                                r0 = r9;
                            } else {
                                r1 = LD32(0x0608D390);
                                r0 = GCALL2(r1, r10, r5);
                                r0 = -2;
                            }
                        }
                    }
                }
            }
        } else {
            r4 = LD32(r8 + 20);
            r0 = GCALL1(0x0605EB28, r4);
            if (r0 > 0) {
                r0 = LD32(r8 + 28);
                if (((r0 & 4) & (r0 & 4)) == 0) {
                    r4 = LD32(r8 + 20);
                    r0 = GCALL1(0x0605EC14, r4);
                    r10 = r0;
                    r1 = LD16((r10 + 4));
                    r0 = LD32(r8 + 28);
                    r5 = r10 + r1;
                    r3 = r5 + 20;
                    r1 = LD16((r5 + 24));
                    r2 = r1 & 0xFFFF;
                    r9 = r2 - 8;
                    if (((r0 & 1) & (r0 & 1)) == 0) {
                        if (r9 > r11) {
                            r9 = r11;
                        }
                        r5 = r5 + 28;
                        r1 = 0x0604B358;
                        r6 = r9;
                        r4 = r12;
                        r0 = GCALL3(r1, r4, r5, r6);
                        r1 = LD32(0x0608D390);
                        r0 = GCALL1(r1, r10);
                        r0 = r9;
                    } else {
                        c10 = r2 > r11;
                        if (r11 > 7) {
                            r1 = r5;
                            if (c10) {
                                r9 = r11 - 8;
                            }
                            r4 = r12 + 8;
                            r1 = LD16((r1 + 12));
                            r6 = r9;
                            ST16(r12, r1);
                            r1 = LD16((r5 + 14));
                            ST16((r12 + 2), r1);
                            r1 = LD16(r3);
                            ST16((r12 + 4), r1);
                            r1 = LD32(r8 + 8);
                            ST16((r12 + 6), r1);
                            r1 = 0x0604B358;
                            r5 = r5 + 28;
                            r0 = GCALL3(r1, r4, r5, r6);
                            r1 = LD32(0x0608D390);
                            r0 = GCALL1(r1, r10);
                            r0 = r9;
                        } else {
                            r1 = LD32(0x0608D390);
                            r0 = GCALL2(r1, r10, r5);
                            r0 = -2;
                        }
                    }
                } else {
                    r2 = LD32(r8 + 24);
                    r4 = LD32(r8 + 20);
                    r1 = LD32(0x0608D9F0);
                    r9 = r1 + (r2 * 24);
                    r0 = GCALL1(0x0605EB28, r4);
                    if (r0 > 0) {
                        r4 = LD32(r8 + 20);
                        r0 = GCALL1(0x0605EC14, r4);
                        r10 = r0;
                        r1 = LD16((r10 + 4));
                        r0 = LD32(r8 + 28);
                        r5 = r10 + r1;
                        r3 = r5 + 20;
                        r1 = LD16((r5 + 24));
                        r2 = r1 & 0xFFFF;
                        r9 = r2 - 8;
                        if (((r0 & 1) & (r0 & 1)) == 0) {
                            if (r9 > r11) {
                                r9 = r11;
                            }
                            r5 = r5 + 28;
                            r1 = 0x0604B358;
                            r6 = r9;
                            r4 = r12;
                            r0 = GCALL3(r1, r4, r5, r6);
                            r1 = LD32(0x0608D390);
                            r0 = GCALL1(r1, r10);
                            r0 = r9;
                        } else {
                            c10 = r2 > r11;
                            if (r11 > 7) {
                                r1 = r5;
                                if (c10) {
                                    r9 = r11 - 8;
                                }
                                r4 = r12 + 8;
                                r1 = LD16((r1 + 12));
                                r6 = r9;
                                ST16(r12, r1);
                                r1 = LD16((r5 + 14));
                                ST16((r12 + 2), r1);
                                r1 = LD16(r3);
                                ST16((r12 + 4), r1);
                                r1 = LD32(r8 + 8);
                                ST16((r12 + 6), r1);
                                r1 = 0x0604B358;
                                r5 = r5 + 28;
                                r0 = GCALL3(r1, r4, r5, r6);
                                r1 = LD32(0x0608D390);
                                r0 = GCALL1(r1, r10);
                                r0 = r9;
                            } else {
                                r1 = LD32(0x0608D390);
                                r0 = GCALL2(r1, r10, r5);
                                r0 = -2;
                            }
                        }
                    } else {
                        r5 = LD32(r9 + 20);
                        r0 = GCALL2(0x0605F634, 30, r5);
                        c7 = r0 == -3;
                        r0 = -3;
                        if (!(c7)) {
                            r4 = LD32(r8 + 20);
                            r0 = GCALL1(0x0605EC14, r4);
                            r10 = r0;
                            r1 = LD16((r10 + 4));
                            r0 = LD32(r8 + 28);
                            r5 = r10 + r1;
                            r3 = r5 + 20;
                            r1 = LD16((r5 + 24));
                            r2 = r1 & 0xFFFF;
                            r9 = r2 - 8;
                            if (((r0 & 1) & (r0 & 1)) == 0) {
                                if (r9 > r11) {
                                    r9 = r11;
                                }
                                r5 = r5 + 28;
                                r1 = 0x0604B358;
                                r6 = r9;
                                r4 = r12;
                                r0 = GCALL3(r1, r4, r5, r6);
                                r1 = LD32(0x0608D390);
                                r0 = GCALL1(r1, r10);
                                r0 = r9;
                            } else {
                                c10 = r2 > r11;
                                if (r11 > 7) {
                                    r1 = r5;
                                    if (c10) {
                                        r9 = r11 - 8;
                                    }
                                    r4 = r12 + 8;
                                    r1 = LD16((r1 + 12));
                                    r6 = r9;
                                    ST16(r12, r1);
                                    r1 = LD16((r5 + 14));
                                    ST16((r12 + 2), r1);
                                    r1 = LD16(r3);
                                    ST16((r12 + 4), r1);
                                    r1 = LD32(r8 + 8);
                                    ST16((r12 + 6), r1);
                                    r1 = 0x0604B358;
                                    r5 = r5 + 28;
                                    r0 = GCALL3(r1, r4, r5, r6);
                                    r1 = LD32(0x0608D390);
                                    r0 = GCALL1(r1, r10);
                                    r0 = r9;
                                } else {
                                    r1 = LD32(0x0608D390);
                                    r0 = GCALL2(r1, r10, r5);
                                    r0 = -2;
                                }
                            }
                        }
                    }
                }
            } else {
                r0 = -502;
            }
        }
    } else {
        ST32(r2 + 16, r1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B398(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r8, r9, r10, r11, r12, r13, r14, c10, c12;
    FRAME(sp, 60);

    ST32(sp - 40, r4);
    r0 = LD32(0x0608D3A0);
    r13 = r5;
    r0 = GCALL2(r0, 128, r5);
    r11 = r0;
    ST32(sp - 36, r11);
    if (!((r11 & r11) == 0)) {
        ST8(r13, 0);
        ST16(r11, 0);
        ST16((r11 + 2), 0x100);
        ST16((r11 + 4), 1);
        ST16((r11 + 10), 0);
        ST16((r11 + 8), 0);
        ST16((r11 + 6), 0);
        r9 = r11 + 12;
        r10 = 3;
        r12 = 0x0607507C;
        r14 = 0x060750DC;
        do {
            r0 = LD32(sp - 40);
            r6 = LD8(r0 + r10);
            r0 = GCALL3(0x06045264, (sp - 60), 0x0605B334, (r6 & 255));
            r8 = r9;
            r9 = r9 + 1;
            r0 = GCALL1(r12, (sp - 60));
            ST8(r8, r0);
            r0 = GCALL2(r14, r9, (sp - 60));
            r0 = GCALL1(r12, (sp - 60));
            r10 = r10 - 1;
            r9 = r9 + r0;
        } while (AGAIN(r10 >= 0));
        ST8(r9, 7);
        r9 = r9 + 1;
        r2 = LD8(0x0605B338);
        ST8(r9, r2);
        r2 = r9 + 1;
        r3 = LD8(0x0605B339);
        r9 = r9 + 7;
        ST8(r2, r3);
        r3 = LD8(0x0605B33A);
        r2 = r2 + 1;
        ST8(r2, r3);
        r3 = LD8(0x0605B33B);
        r2 = r2 + 1;
        ST8(r2, r3);
        r3 = LD8(0x0605B33C);
        r2 = r2 + 1;
        ST8(r2, r3);
        r3 = LD8(0x0605B33D);
        r2 = r2 + 1;
        ST8(r2, r3);
        r3 = LD8(0x0605B33E);
        r2 = r2 + 1;
        ST8(r2, r3);
        r1 = LD8(0x0605B33F);
        ST8((r2 + 1), r1);
        ST8(r9, 4);
        r2 = LD8(0x0605B340);
        r9 = r9 + 1;
        ST8(r9, r2);
        r2 = r9 + 1;
        r3 = LD8(0x0605B341);
        r9 = r9 + 4;
        ST8(r2, r3);
        r3 = LD8(0x0605B342);
        r2 = r2 + 1;
        ST8(r2, r3);
        r3 = LD8(0x0605B343);
        r2 = r2 + 1;
        ST8(r2, r3);
        r1 = LD8(0x0605B344);
        ST8((r2 + 1), r1);
        ST8(r9, 0);
        r9 = r9 + 1;
        ST8(r9, 0);
        ST8((r9 + 1), 12);
        ST8((r9 + 2), 0);
        ST8((r9 + 3), 1);
        r9 = r9 + 4;
        r0 = GCALL2(0x0605AE6C, 0x0605B348, 0);
        r12 = r0;
        r0 = GCALL3(0x0605AF48, r12, 1, 14);
        r0 = GCALL3(0x0605B0D8, r12, r11, (r9 - r11));
        if (r0 == -2) {
            r0 = GCALL3(0x06045264, 0x0608B9D0, 0x0605B370, 0x0605B358);
            r0 = GCALL1(0x0602BA00, 0x0608B9D0);
        }
        r0 = GCALL3(0x0605AF90, r12, r11, 128);
        r10 = r0;
        if (r0 == -2) {
            r0 = GCALL3(0x06045264, 0x0608B9D0, 0x0605B370, 0x0605B37C);
            r0 = GCALL1(0x0602BA00, 0x0608B9D0);
        }
        if (!(r10 == -3)) {
            r0 = GCALL1(0x0605B208, r12);
            r1 = LD32(sp - 36);
            r0 = LD16((r1 + 2));
            r1 = LD32(sp - 36);
            if (!(((r0 & 15) & (r0 & 15)) == 0)) {
                r1 = LD32(0x0608D390);
                r0 = GCALL1(r1, r11);
                r5 = LD32(sp - 40);
                r0 = GCALL2(0x0605F844, r13, r5);
                r0 = 1;
            } else {
                r1 = LD16((r1 + 6));
                if (r1 > 0) {
                    r2 = LD8(r9);
                    if (!((((signed char)r2) & ((signed char)r2)) == 0)) {
                        r3 = 0;
                        do {
                            r2 = (signed char)r2;
                            if (((192 & r2) & (192 & r2)) == 0) {
                                r9 = r9 + (r2 + 1);
                            } else {
                                r9 = r9 + 1;
                                ST8(r9, r3);
                            }
                            r2 = LD8(r9);
                        } while (AGAIN(!((((signed char)r2) & ((signed char)r2)) == 0)));
                    }
                    r9 = r9 + 11;
                    ST8(r13, 0);
                    r6 = LD8(r9);
                    c10 = (((signed char)r6) & ((signed char)r6)) == 0;
                    r6 = (signed char)r6;
                    if (!(c10)) {
                        r10 = 0x06075470;
                        r8 = 0x06075408;
                        do {
                            if (((192 & r6) & (192 & r6)) == 0) {
                                r0 = GCALL3(r10, r13, (r9 + 1), r6);
                                r0 = GCALL2(r8, r13, 0x0605B394);
                                r1 = LD8(r9);
                                r1 = r1 + 1;
                            } else {
                                r1 = LD32(r9);
                                r1 = r1 & 0x3FFF;
                                r9 = r11;
                            }
                            r9 = r9 + r1;
                            r6 = LD8(r9);
                            c12 = (((signed char)r6) & ((signed char)r6)) == 0;
                            r6 = (signed char)r6;
                        } while (AGAIN(!(c12)));
                    }
                    r8 = 0x0607507C;
                    r0 = GCALL1(0x0607507C, r13);
                    r5 = LD32(sp - 40);
                    if ((r0 & r0) == 0) {
                        r0 = GCALL2(0x0605F844, r13, r5);
                    } else {
                        r0 = GCALL3(r8, r13, r5, r6);
                        ST8(((r0 + r13) - 1), 0);
                    }
                    r1 = LD32(0x0608D390);
                    r0 = GCALL1(r1, r11);
                    r0 = 1;
                } else {
                    r1 = LD32(0x0608D390);
                    r0 = GCALL1(r1, r11);
                    r5 = LD32(sp - 40);
                    r0 = GCALL2(0x0605F844, r13, r5);
                    r0 = 1;
                }
            }
        } else {
            r0 = GCALL1(0x0605B208, r12);
            r5 = LD32(sp - 40);
            r0 = GCALL2(0x0605F844, r13, r5);
            r0 = 1;
        }
    } else {
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605BDEC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, c0, c1;

    r1 = LD16((r4 + 12));
    r2 = r1 & 0xFFFF;
    c0 = r2 == 0xC021;
    r9 = c0;
    if (!(c0)) {
        r0 = 0;
        if (r2 == 0x8021) {
            r2 = LD32(0x0608D388);
            r2 = r2 + 226;
            r0 = LD8(r2);
            r1 = 2;
            if (!(r0 == 4)) {
                ST8(r2, r1);
            }
            r0 = GCALL4(0x06060240, 0, 0, r6, r7);
            r0 = GCALL0(0x060528BC);
            r0 = 1;
        }
    } else {
        r8 = LD32(0x0608D9C8);
        r1 = LD8(176 + r8);
        c1 = r1 > r9;
        r1 = r8;
        if (c1) {
            r0 = GCALL1(0x0605DBD4, ((int)0xC0230001));
            r1 = r8;
        }
        r1 = LD8((r1 + 92));
        r0 = 0;
        if (r1 > r9) {
            r0 = GCALL1(0x0605DBD4, ((int)0x80210001));
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DA94(int r4, int r5)
{
    int r0, r2, r8, r9;

    r9 = r4;
    r0 = LD32(0x0608D39C);
    r8 = r5;
    r0 = GCALL2(r0, r4, r5);
    r2 = LD32(0x0608D394);
    r0 = GCALL2(0x0605D980, 0, (r0 + (((r2 << 2) + r2) + ((r2 << 2) + r2))));
    r0 = GCALL3(0x0605BA98, 33, r9, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605DADC(void)
{
    int r0, r2;

    r0 = LD32(0x0608D39C);
    r0 = GCALL0(r0);
    r2 = LD32(0x0608D394);
    r0 = GCALL2(0x0605D980, 0, (r0 + (r2 * 0x12C)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605E27C(void)
{
    int r0, r1, r2, r4, r8, r9, r10, r11, r12, r13, r14, c3, c6, c8;

    r12 = LD32(0x0608D398);
    r10 = LD32(0x0608D38C);
    if (r12 > 0) {
        r14 = 0;
        r9 = r10 + 4;
        r13 = r10 + 1;
        do {
            r1 = LD8(r10);
            r2 = r1 & 255;
            if (!((r2 & r2) == 0)) {
                r1 = LD8(r13);
                r0 = r1 & 255;
                c3 = r0 == 2;
                if (!(r0 == 1)) {
                    if (c3) {
                        r1 = LD32(r9 + 4);
                        if ((r1 & r1) == 0) {
                            r1 = LD32(r9);
                            r4 = LD32(r1 + 16);
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(0x060618C4, r4);
                                ST32(r9 + 4, r0);
                                r1 = LD32(r9);
                                ST32(r1 + 16, r14);
                            }
                        }
                    }
                } else {
                    r11 = LD32(r9);
                    if (r2 == 3) {
                        r0 = LD16(r11);
                        r1 = 6;
                        if (r0 == 5) {
                            ST8(r10, r1);
                        }
                    }
                    r1 = LD32(r9 + 4);
                    c6 = (r1 & r1) == 0;
                    r1 = r11;
                    if (c6) {
                        r1 = LD16((r1 + 16));
                        if (!((r1 & r1) == 0)) {
                            r1 = LD8(r10);
                            c8 = (r1 & 255) == 3;
                            r1 = 9;
                            if (c8) {
                                r1 = 5;
                            }
                            ST8(r10, r1);
                            r8 = r11 + 16;
                            r4 = LD16(r8);
                            r0 = GCALL1(0x060618C4, r4);
                            ST32(r9 + 4, r0);
                            ST16(r8, r14);
                            r0 = GCALL1(0x06056518, r11);
                            ST32(r9, r14);
                        }
                    }
                }
            }
            r12 = r12 - 1;
            r9 = r9 + 16;
            r13 = r13 + 16;
            r10 = r10 + 16;
        } while (AGAIN(r12 > 0));
    }
    r0 = GCALL0(0x0605E0EC);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605EFC8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10;

    r8 = r4;
    r10 = r5;
    r0 = GCALL4(0x0605DC3C, (r4 + 20), 0, r6, r7);
    r2 = r0;
    r9 = 0;
    if (!((r2 & r2) == 0)) {
        r1 = LD16((r2 + 14));
        if ((r1 & r1) == 0) {
            r9 = 1;
        }
    }
    r1 = LD32(0x0608D390);
    r0 = GCALL1(r1, r2);
    if ((r9 & r9) == 0) {
        r1 = 0x12C;
    } else {
        r1 = LD32(r8 + 32);
        r1 = LD32(r1 + 32);
        r1 = r1 - 40;
    }
    r2 = r8 + 72;
    ST32(r2, r1);
    r0 = r8;
    ST32(r0 + 200, r1);
    r1 = LD32(r2);
    ST32(r8 + 52, r1);
    r1 = LD32(r2);
    ST32((r8 + 64), r1);
    ST32((r8 + 68), 0xFFFF);
    ST32((r8 + 104), 0);
    ST32(r0 + 212, 0);
    ST32(r0 + 216, 0);
    r2 = 3;
    if (r10 == 1) {
        r2 = r2 | 0x200;
    }
    ST16((r8 + 14), r2);
    ST16((r8 + 2), 0);
    ST16(r8, 3);
    r0 = GCALL1(0x06058918, r8);
    ST32(144 + r8, -2);
    r1 = LD32(0x0608D920);
    ST32(0x0608D920, (r1 + 1));
    ST8((r8 + 6), 1);
    r1 = LD32(r8 + 8);
    ST32(r8 + 8, (r1 + 1));
    if (!((r10 & r10) == 0)) {
        r9 = 0;
    } else {
        r2 = 152;
        r0 = r8;
        r1 = LD32(r0 + 152);
        r1 = r1 - 1;
        ST32(r0 + 152, r1);
        if (!(r1 >= 0)) {
            r10 = 0x0605299C;
            r9 = r2;
            do {
                r0 = GCALL0(r10);
                r1 = LD32(r8 + r9);
            } while (AGAIN(!(r1 >= 0)));
        }
        r9 = LD16((r8 + 16));
        if (!((r9 & r9) == 0)) {
            r0 = GCALL1(0x06056518, r8);
        }
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060538A0(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r8;

    r8 = r4;
    r1 = LD8((r8 + 4));
    r4 = r5;
    r7 = (signed char)r1;
    r1 = LD8((r8 + 5));
    r3 = (signed char)r1;
    if (!(r7 >= 0)) {
        r5 = r4 + 10;
    } else {
        r5 = (((r7 << 2) + (r7 << 2)) + r4) + 97;
    }
    r1 = r4;
    if (r3 >= 0) {
        r1 = (((r3 << 2) + (r3 << 2)) + r4) + 96;
    } else {
        r1 = r1 + 9;
    }
    r0 = SR();
    r2 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    SETSR((r0 | 240));
    ST8(r5, r3);
    ST8(r1, r7);
    r1 = SR();
    SETSR(((r1 & -241) | ((r2 << 2) << 2)));
    r2 = ((((r8 - 92) - r4) >> 1) >> 1) >> 1;
    r5 = r4 + 10;
    r7 = LD8(r5);
    ST8((r8 + 5), r7);
    ST8((r8 + 4), -1);
    r0 = SR();
    r3 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r1 = SR();
    r0 = (r1 & -241) | 240;
    SETSR(r0);
    ST8(((r4 + ((r7 << 2) + (r7 << 2))) + 96), r2);
    ST8(r5, r2);
    r2 = r4 + 8;
    r1 = LD8(r2);
    ST8(r2, (r1 + 1));
    r1 = LD8(r2);
    r1 = SR();
    SETSR(((r1 & -241) | ((r3 << 2) << 2)));
    ST8((r8 + 6), 0);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06053F40(void)
{
    int r0, r1, r8, r9, r10;

    r9 = LD32(0x0608D854);
    r10 = r9 + 15;
    r1 = LD8(r10);
    if (!((r1 & r1) == 0)) {
        r1 = (SR() & ~1) | 0;
        r0 = (SR() & ~1) | 0;
        SETSR((r0 | 240));
        r8 = LD32(r9 + 60);
        r0 = GCALL1(0x0605B808, r8);
        r0 = GCALL1(0x0605B81C, r8);
        r0 = GCALL1(0x06051F38, r9);
        ST8(r10, 0);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060548E0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8;

    r8 = LD32(0x0608D854);
    r0 = GCALL3(0x0605457C, r8, r5, r6);
    r1 = LD8((r8 + 9));
    r4 = r8 + (((r1 << 2) + (r1 << 2)) + 92);
    r1 = LD8((r4 + 6));
    r0 = (signed char)r1;
    r1 = r4;
    if (r0 == 2) {
        r6 = LD16((r1 + 2));
        r6 = r6 & 0xFFFF;
        r0 = (SR() & ~1) | 1;
        r7 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
        r0 = (SR() & ~1) | 1;
        SETSR((r0 | 240));
        r3 = r8 + 20;
        r1 = LD16(r3);
        ST16(r3, (r1 - r6));
        r1 = SR();
        SETSR(((r1 & -241) | ((r7 << 2) << 2)));
        r1 = LD32(r8 + 48);
        r2 = r1 + r6;
        ST32(r8 + 48, r2);
        if ((unsigned)r2 >= (unsigned)(0xD04 + r8)) {
            ST32(r8 + 48, (-3000 + r2));
        }
        r0 = GCALL2(0x060538A0, r4, r8);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06054970(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9;

    r9 = LD32(0x0608D854);
    r0 = GCALL3(0x0605457C, r9, r5, r6);
    r8 = 0;
    r3 = 0;
    r7 = 29;
    r1 = LD8((r9 + 9));
    do {
        r2 = r9 + ((r1 << 2) + (r1 << 2));
        r1 = LD8((r2 + 98));
        if (((signed char)r1) == 2) {
            r8 = r8 + 1;
        }
        r1 = LD8((r2 + 96));
        r3 = r3 + 1;
        r1 = (signed char)r1;
    } while (AGAIN(!(r3 > r7)));
    if (!((r8 & r8) == 0)) {
        r1 = LD32(0x0608D9CC);
        if (!((r1 & r1) == 0)) {
            r0 = GCALL4(r1, 0, 0, 0, r7);
        }
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06055038(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;
    int v12;

    r0 = r5;
    r8 = r4;
    if ((r0 & r0) == 0) {
        ST8((r8 + 2), 0);
        if ((r0 & r0) == 0) {
            r1 = LD32(0x0608D9CC);
            if (!((r1 & r1) == 0)) {
                v12 = r0;
                r0 = GCALL5(r1, r4, r5, r6, r7, v12);
                r0 = v12;
            }
        }
    } else {
        if (r0 == 9) {
            ST8((r8 + 2), 0);
            if ((r0 & r0) == 0) {
                r1 = LD32(0x0608D9CC);
                if (!((r1 & r1) == 0)) {
                    v12 = r0;
                    r0 = GCALL5(r1, r4, r5, r6, r7, v12);
                    r0 = v12;
                }
            }
        }
    }
    ST8(r8, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060563F0(void)
{
    int r0, r1, r2, r3, r4, r8, r9, r10, r11, r12, r13, r14;

    r3 = 0x0608D870;
    r2 = LD32(0x0608D870);
    r1 = r2;
    if (!(r2 == ((int)0x80000000))) {
        ST32(r3, (r1 - 1));
    }
    r8 = LD32(0x0608D890);
    r1 = LD32(0x0608D88C);
    r9 = 0;
    r2 = r1;
    if (!(0 >= r1)) {
        r3 = 220;
        while (1) {
            r1 = LD16(r8);
            if ((r1 & r1) == 0) {
                break;
            } else {
                r9 = r9 + 1;
                r8 = r8 + r3;
                if (!(r9 >= r2)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    r2 = LD32(0x0608D88C);
    r1 = 1;
    if (!(r9 >= r2)) {
        ST16(r8, r1);
        ST32(r8 + 8, 0);
        ST16((r8 + 16), 0);
    } else {
        r12 = 0;
        r13 = 0;
        r8 = LD32(0x0608D890);
        r9 = 0;
        if (!(0 >= r2)) {
            r14 = 0x060587DC;
            r11 = 0;
            while (1) {
                r0 = LD16(r8);
                r1 = r8;
                if (!(r0 == 9)) {
                    r8 = r8 + 220;
                    r1 = LD32(0x0608D88C);
                    r9 = r9 + 1;
                    r11 = r11 + 8;
                    if (!(r9 >= r1)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                } else {
                    r1 = LD32((r1 + 100));
                    if (r1 >= r12) {
                        r12 = r1;
                        r13 = r8;
                    }
                    r0 = LD16((r8 + 2));
                    if (!(r0 == 3)) {
                        r8 = r8 + 220;
                        r1 = LD32(0x0608D88C);
                        r9 = r9 + 1;
                        r11 = r11 + 8;
                        if (!(r9 >= r1)) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        r4 = LD32(0x0608D874);
                        r10 = 1 | r11;
                        r0 = GCALL4(r14, r4, (3 | r11), 0, 0x0608D874);
                        if (!((r0 & r0) == 0)) {
                            r8 = r8 + 220;
                            r1 = LD32(0x0608D88C);
                            r9 = r9 + 1;
                            r11 = r11 + 8;
                            if (!(r9 >= r1)) {
                                POLL();
                                continue;
                            } else {
                                break;
                            }
                        } else {
                            r4 = LD32(0x0608D874);
                            r0 = GCALL4(r14, r4, r10, 0, 0x0608D874);
                            if ((r0 & r0) == 0) {
                                break;
                            } else {
                                r8 = r8 + 220;
                                r1 = LD32(0x0608D88C);
                                r9 = r9 + 1;
                                r11 = r11 + 8;
                                if (!(r9 >= r1)) {
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
        r1 = LD32(0x0608D88C);
        if (r9 == r1) {
            r8 = r13;
        }
        if ((r8 & r8) == 0) {
            r8 = -2;
        } else {
            r0 = GCALL2(0x0605723C, r8, -507);
            r2 = LD32(r8 + 8);
            r1 = r2;
            if (!(r2 == ((int)0x80000000))) {
                ST32(r8 + 8, (r1 - 1));
            }
            r0 = GCALL1(0x06056518, r8);
            r1 = 1;
            ST16(r8, r1);
            ST32(r8 + 8, 0);
            ST16((r8 + 16), 0);
        }
    }
    r1 = LD32(0x0608D870);
    ST32(0x0608D870, (r1 + 1));
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058F30(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r12, r13, r14, c1;
    int v36;
    int v40;

    r14 = r4;
    r0 = LD16((r5 + 4));
    r8 = r5 + r0;
    r7 = LD8((r8 + 33));
    r12 = r8 + 20;
    if (!(((4 & r7) & (4 & r7)) == 0)) {
        r0 = 1;
    } else {
        r0 = LD8(r0 + r5);
        r3 = LD16((r8 + 2));
        r2 = (r0 & 15) << 2;
        r0 = LD8((r8 + 32));
        c1 = (r3 & 0xFFFF) > (r2 + ((int)((unsigned)(r0 & 240) >> 2)));
        r0 = r7;
        if (c1) {
            r0 = LD32(0x0608D3A0);
            r0 = GCALL4(r0, 48, r5, r6, r7);
            r13 = r0;
            r2 = r13;
            if ((r13 & r13) == 0) {
                r0 = -2;
            } else {
                ST16((r2 + 4), 8);
                v36 = r13 + 8;
                r10 = r13 + 24;
                r9 = r13 + 28;
                r1 = LD16((r8 + 16));
                ST16((r13 + 20), r1);
                r1 = LD16((r8 + 18));
                ST16((r13 + 22), r1);
                r1 = LD16((r8 + 12));
                ST16(r10, r1);
                r1 = LD16((r8 + 14));
                ST16((r13 + 26), r1);
                ST8((r13 + 17), 6);
                ST8(8 + r13, 69);
                ST16((r13 + 10), 40);
                r1 = LD16((r12 + 2));
                ST16(r9, r1);
                r1 = LD16(r12);
                ST16((r13 + 30), r1);
                r1 = LD32(r14 + 44);
                ST32(r13 + 32, r1);
                r1 = LD32((r14 + 104));
                ST32(r13 + 36, r1);
                ST8((r13 + 41), 16);
                ST8((r13 + 40), 80);
                r0 = GCALL5(0x06058A18, r14, 0, 0, 0, v36);
                ST16((r13 + 42), r0);
                ST16((r13 + 46), 0);
                r8 = r13 + 44;
                ST16(r8, 0);
                r0 = GCALL5(0x060582A8, r9, 0, 0, 0, v36);
                r0 = GCALL5(0x060585D8, v36, 0, 0, 0, v36);
                ST16(r8, r0);
                r1 = LD32(0x0608D940);
                ST32(0x0608D940, (r1 + 1));
                r7 = LD16((r14 + 36));
                r1 = LD16((r14 + 38));
                r0 = GCALL6(0x06052FFC, r10, r13, 20, r7, r1, v36);
            }
        } else {
            if (!(((r0 & 3) & (r0 & 3)) == 0)) {
                r0 = LD32(0x0608D3A0);
                r0 = GCALL4(r0, 48, r5, r6, r7);
                r13 = r0;
                r2 = r13;
                if ((r13 & r13) == 0) {
                    r0 = -2;
                } else {
                    ST16((r2 + 4), 8);
                    v36 = r13 + 8;
                    r10 = r13 + 24;
                    r9 = r13 + 28;
                    r1 = LD16((r8 + 16));
                    ST16((r13 + 20), r1);
                    r1 = LD16((r8 + 18));
                    ST16((r13 + 22), r1);
                    r1 = LD16((r8 + 12));
                    ST16(r10, r1);
                    r1 = LD16((r8 + 14));
                    ST16((r13 + 26), r1);
                    ST8((r13 + 17), 6);
                    ST8(8 + r13, 69);
                    ST16((r13 + 10), 40);
                    r1 = LD16((r12 + 2));
                    ST16(r9, r1);
                    r1 = LD16(r12);
                    ST16((r13 + 30), r1);
                    r1 = LD32(r14 + 44);
                    ST32(r13 + 32, r1);
                    r1 = LD32((r14 + 104));
                    ST32(r13 + 36, r1);
                    ST8((r13 + 41), 16);
                    ST8((r13 + 40), 80);
                    r0 = GCALL5(0x06058A18, r14, 0, 0, 0, v36);
                    ST16((r13 + 42), r0);
                    ST16((r13 + 46), 0);
                    r8 = r13 + 44;
                    ST16(r8, 0);
                    r0 = GCALL5(0x060582A8, r9, 0, 0, 0, v36);
                    r0 = GCALL5(0x060585D8, v36, 0, 0, 0, v36);
                    ST16(r8, r0);
                    r1 = LD32(0x0608D940);
                    ST32(0x0608D940, (r1 + 1));
                    r7 = LD16((r14 + 36));
                    r1 = LD16((r14 + 38));
                    r0 = GCALL6(0x06052FFC, r10, r13, 20, r7, r1, v36);
                }
            } else {
                r0 = 1;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CF70(int r4)
{
    int r0;

    r0 = GCALL4(0x0605CEFC, r4, 0, 0x0605CE50, 6);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CFA4(int r4)
{
    int r0;

    r0 = GCALL4(0x0605CEFC, r4, 0, 0x0605CE50, 6);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605CFD8(int r4)
{
    int r0;

    r0 = GCALL4(0x0605CEFC, r4, 0, 0x0605CE50, 6);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D010(int r4)
{
    int r0;

    r0 = GCALL4(0x0605CEFC, r4, 0, 0x0605CE50, 6);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D048(int r4)
{
    int r0;

    r0 = GCALL4(0x0605CEFC, r4, 0, 0x0605CE80, 4);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D07C(int r4)
{
    int r0;

    r0 = GCALL4(0x0605CEFC, r4, 0, 0x0605CE80, 4);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D0B0(int r4)
{
    int r0;

    r0 = GCALL4(0x0605CEFC, r4, 0, 0x0605CE80, 4);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D0E8(int r4)
{
    int r0;

    r0 = GCALL4(0x0605CEFC, r4, 0, 0x0605CE80, 4);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D110(void)
{
    int r0;

    r0 = GCALL0(0x0605D108);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D128(void)
{
    int r0;

    r0 = GCALL0(0x0605D108);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D140(void)
{
    int r0;

    r0 = GCALL0(0x0605D10C);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D158(void)
{
    int r0;

    r0 = GCALL0(0x0605D10C);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D1AC(int r4)
{
    int r0;

    r0 = GCALL2(0x0605D170, 0, r4);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D1CC(int r4)
{
    int r0;

    r0 = GCALL2(0x0605D170, 0, r4);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D2B8(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, c0;

    r9 = r4;
    r1 = LD8(r9);
    r8 = 0;
    r2 = 0x0605D238;
    r7 = 0x0605D238;
    r6 = 0;
    r3 = r1 & 255;
    while (1) {
        r1 = LD32(r6 + r7);
        c0 = r3 == r1;
        r1 = 6;
        if (!(c0)) {
            r2 = r2 + 8;
            r8 = r8 + 1;
            r6 = r6 + 8;
            if (!(r8 > r1)) {
                POLL();
                continue;
            } else {
                r0 = r8;
                break;
            }
        } else {
            r1 = LD32(r2 + 4);
            r0 = GCALL4(r1, r9, r5, r6, r7);
            r0 = r8;
            break;
        }
        POLL();
    }
    if (r0 == 7) {
        r0 = GCALL1(0x0605CD98, r9);
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D30C(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, c0;

    r9 = r4;
    r1 = LD8(r9);
    r8 = 0;
    r2 = 0x0605D270;
    r7 = 0x0605D270;
    r6 = 0;
    r3 = r1 & 255;
    while (1) {
        r1 = LD32(r6 + r7);
        c0 = r3 == r1;
        r1 = 5;
        if (!(c0)) {
            r2 = r2 + 8;
            r8 = r8 + 1;
            r6 = r6 + 8;
            if (!(r8 > r1)) {
                POLL();
                continue;
            } else {
                r0 = r8;
                break;
            }
        } else {
            r1 = LD32(r2 + 4);
            r0 = GCALL4(r1, r9, r5, r6, r7);
            r0 = r8;
            break;
        }
        POLL();
    }
    if (r0 == 6) {
        r0 = GCALL1(0x0605CD98, r9);
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0605D360(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, c0;

    r9 = r4;
    r1 = LD8(r9);
    r8 = 0;
    r2 = 0x0605D2A0;
    r7 = 0x0605D2A0;
    r6 = 0;
    r3 = r1 & 255;
    while (1) {
        r1 = LD32(r6 + r7);
        c0 = r3 == r1;
        r1 = 2;
        if (!(c0)) {
            r2 = r2 + 8;
            r8 = r8 + 1;
            r6 = r6 + 8;
            if (!(r8 > r1)) {
                POLL();
                continue;
            } else {
                r0 = r8;
                break;
            }
        } else {
            r1 = LD32(r2 + 4);
            r0 = GCALL4(r1, r9, r5, r6, r7);
            r0 = r8;
            break;
        }
        POLL();
    }
    if (r0 == 3) {
        r0 = GCALL1(0x0605CD98, r9);
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060550C8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = r4;
    r0 = GCALL4(0x0605DC0C, 1, r5, r6, r7);
    r5 = LD32(r8 + 36);
    r7 = 48;
    if (!((r5 & r5) == 0)) {
        r0 = GCALL2(0x0607286C, 0x0001C200, r5);
        r7 = r0;
    }
    ST8((r8 + 18), 0);
    r0 = GCALL2(0x06051FAC, r8, r7);
    r8 = r0;
    if (!((r8 & r8) == 0)) {
        r1 = LD32(0x0608D9CC);
        if (!((r1 & r1) == 0)) {
            r0 = GCALL0(r1);
        }
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06056E34(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14;

    r8 = r4;
    r3 = LD16((r5 + 4));
    r10 = r5 + r3;
    r6 = r10 + 33;
    r0 = LD8(r6);
    r13 = r10 + 20;
    if (!(((r0 & 2) & (r0 & 2)) == 0)) {
        r2 = r8 + 104;
        r1 = LD32(r2);
        ST32(r2, (r1 + 1));
        r1 = r8 + 14;
        r0 = LD16(r1);
        ST16(r1, (r0 | 1));
        r1 = LD32(r10 + 24);
        ST32(r10 + 24, (r1 + 1));
    }
    r2 = LD16((r10 + 2));
    r12 = 196;
    r11 = LD32(r10 + 24);
    r4 = 192;
    r1 = LD8(r5 + r3);
    r2 = (r2 & 0xFFFF) - ((r1 & 15) << 2);
    r1 = LD8((r10 + 32));
    r9 = r2 - ((int)((unsigned)(r1 & 240) >> 2));
    r0 = r8;
    r2 = LD32(r0 + 196);
    r1 = LD32(r0 + 192);
    r5 = r8 + 104;
    r3 = LD32(r5);
    r7 = (r3 + (r2 - r1)) - 1;
    r2 = r3 - r11;
    r1 = (r11 + r9) - 1;
    if (r2 > 0) {
        r9 = r9 - r2;
        r11 = r3;
    }
    r1 = r1 - r7;
    if (r1 > 0) {
        r0 = LD8(r6);
        r9 = r9 - r1;
        ST8(r6, (r0 & 254));
    }
    r0 = r8;
    r2 = LD32(r0 + 188);
    r1 = LD32(r0 + r4);
    r14 = r2 + r1;
    r1 = LD32(r5);
    r6 = LD32(r8 + r12);
    r14 = r14 + (r11 - r1);
    if (r6 > 0) {
        r0 = GCALL2(0x0607286C, r14, r6);
        r14 = r14 - (r0 * r6);
    }
    r1 = LD32(r10 + 24);
    r2 = 0;
    r7 = r11 - r1;
    if (!(0 >= r9)) {
        r5 = 184;
        r6 = r12;
        r0 = r8;
        do {
            r3 = LD32(r0 + r5);
            r1 = LD8(((r13 + r7) + 20));
            ST8(r3 + r14, r1);
            r1 = LD32(r8 + r6);
            r14 = r14 + 1;
            r7 = r7 + 1;
            if (r14 >= r1) {
                r14 = 0;
            }
            r2 = r2 + 1;
            r0 = r8;
        } while (AGAIN(!(r2 >= r9)));
    }
    r0 = GCALL4(0x06056F88, r8, r13, r11, r9);
    r0 = LD16((r8 + 14));
    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
        r0 = GCALL1(0x06058918, r8);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06057C88(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14, c3;
    FRAME(sp, 48);

    ST32(sp - 44, r5);
    r5 = LD32(sp - 44);
    r1 = LD32(0x0608D890);
    r9 = r1 + (r4 * 220);
    r0 = GCALL3(0x06057F80, r9, r5, (sp - 48));
    r13 = r0;
    r8 = r9 + 12;
    r0 = LD16(r8);
    r4 = r13 + 48;
    if (!(((r0 & 2) & (r0 & 2)) == 0)) {
        r4 = r13 + 52;
    }
    r0 = LD32(0x0608D3A0);
    r0 = GCALL1(r0, ((r4 + 3) & -4));
    r11 = r0;
    r2 = r11;
    if (!((r11 & r11) == 0)) {
        ST16((r2 + 4), 8);
        ST32(sp - 40, (r11 + 8));
        r1 = LD16((r9 + 24));
        r12 = r11 + 28;
        ST16((r11 + 20), r1);
        r1 = LD16((r9 + 26));
        ST16((r11 + 22), r1);
        r1 = LD16((r9 + 20));
        ST16((r11 + 24), r1);
        r1 = LD16((r9 + 22));
        ST16((r11 + 26), r1);
        ST8((r11 + 17), 6);
        r1 = LD16((r9 + 28));
        ST16(r12, r1);
        r1 = LD16((r9 + 18));
        ST16((r11 + 30), r1);
        r1 = LD16(r8);
        ST32(sp - 36, (r1 & 1));
        r0 = LD32(sp - 44);
        c3 = (r0 & r0) == 0;
        r0 = r1;
        if (!(c3)) {
            r1 = LD32(r9 + 40);
            ST32(r11 + 32, r1);
        } else {
            if (((r0 & 32) & (r0 & 32)) == 0) {
                r1 = LD32(r9 + 44);
                ST32(r11 + 32, r1);
                r0 = LD32(sp - 36);
                r1 = r1 - 1;
                if (!((r0 & r0) == 0)) {
                    ST32(r11 + 32, r1);
                }
            } else {
                r1 = LD32(r9 + 40);
                r2 = LD32(sp - 48);
                r1 = r1 + r2;
                ST32(r11 + 32, r1);
            }
        }
        r1 = LD32((r9 + 104));
        ST32(r12 + 8, r1);
        r1 = LD16((r9 + 14));
        if (((r1 & 0x100) & (r1 & 0x100)) == 0) {
            r10 = r12;
        } else {
            r1 = LD32(r12 + 4);
            r2 = LD32(r9 + 48);
            r10 = r12;
            if ((r1 + r13) == r2) {
                r1 = r9 + 12;
                r0 = LD16(r1);
                ST16(r1, (r0 | 1));
                r10 = r12;
            }
        }
        r10 = r10 + 13;
        r14 = r9 + 12;
        r1 = LD16(r14);
        r8 = r12 + 12;
        ST8(r10, r1);
        ST8(r8, 80);
        r0 = LD16((r9 + 14));
        if (((r0 & 2) & (r0 & 2)) == 0) {
            r0 = LD8(r10);
            ST8(r10, (r0 | 16));
        }
        r0 = LD8(r10);
        r5 = LD32(sp - 40);
        if (!(((r0 & 2) & (r0 & 2)) == 0)) {
            r0 = GCALL2(0x06058CA4, r9, r5);
        }
        r0 = LD32(sp - 40);
        ST8(r0, 69);
        r2 = LD32(sp - 40);
        r1 = LD8(r8);
        ST16((r2 + 2), ((((int)((unsigned)(r1 & 240) >> 2)) + 20) + r13));
        if (r13 > 0) {
            r0 = LD8(r10);
            ST8(r10, (r0 | 8));
        }
        r0 = GCALL1(0x06058A18, r9);
        ST16((r12 + 14), r0);
        r0 = LD16(r14);
        r2 = r12;
        if (((r0 & 32) & (r0 & 32)) == 0) {
            r2 = r2 + 18;
            r1 = 0;
        } else {
            r2 = r2 + 18;
            r1 = r13 - 1;
        }
        ST16(r2, r1);
        r0 = LD8((r12 + 12));
        r10 = LD32(sp - 40);
        r10 = r10 + (((int)((unsigned)(r0 & 240) >> 2)) + 20);
        if (!(r13 > 0)) {
            r1 = r9 + 14;
            r2 = LD16(r1);
            ST16(r1, (r2 & -2));
            r0 = LD32(sp - 44);
            if ((r0 & r0) == 0) {
                r0 = LD16((r9 + 12));
                r3 = r13;
                if (!(((r0 & 2) & (r0 & 2)) == 0)) {
                    r3 = r3 + 1;
                }
            } else {
                r1 = LD32(r9 + 40);
                r2 = LD32(r9 + 44);
                r3 = (r1 + r13) - r2;
                if (!(r3 >= 0)) {
                    r3 = 0;
                }
                r1 = LD32(0x0608D8BC);
                ST32(0x0608D8BC, (r1 + 1));
            }
            r0 = LD32(sp - 36);
            r1 = r9;
            if ((r0 & r0) == 0) {
                r0 = LD16((r1 + 12));
                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                    r3 = r3 + 1;
                }
            }
            r1 = LD32(r9 + 44);
            ST32(r9 + 44, (r1 + r3));
            if (r3 >= 0) {
                r1 = LD32(0x0608D940);
                ST32(0x0608D940, (r1 + 1));
            }
            r0 = LD16(r9);
            r1 = r12;
            if (r0 == 11) {
                r0 = GCALL1(0x06056938, r9);
                r1 = r12;
            }
            r0 = LD8((r1 + 12));
            r13 = r13 + ((int)((unsigned)(r0 & 240) >> 2));
            r0 = GCALL1(0x060582A8, r12);
            r8 = r12 + 16;
            ST16(r8, 0);
            r4 = LD32(sp - 40);
            r0 = GCALL1(0x060585D8, r4);
            ST16(r8, r0);
            r7 = LD16((r9 + 36));
            r4 = LD32(sp - 40);
            r1 = LD16((r9 + 38));
            ST32((sp - 52), r1);
            r0 = GCALL5(0x06052FFC, (r4 + 16), r11, r13, r7, LD32((sp - 52)));
        } else {
            r14 = 176;
            r8 = LD32(r9 + 176);
            r5 = r8;
            if (!((r8 & r8) == 0)) {
                r6 = LD32(168 + r9);
                r1 = LD32(sp - 48);
                r6 = r6 + r1;
                r0 = GCALL2(0x0607286C, r6, r5);
                r3 = r13;
                r7 = r14;
                r2 = r6 - (r0 * r8);
                r6 = 164;
                r0 = r9;
                do {
                    r1 = LD32(r0 + r6);
                    r1 = LD8(r1 + r2);
                    ST8(r10, r1);
                    r1 = LD32(r9 + r7);
                    r2 = r2 + 1;
                    r10 = r10 + 1;
                    if (r2 >= r1) {
                        r2 = 0;
                    }
                    r3 = r3 - 1;
                    r0 = r9;
                } while (AGAIN(r3 > 0));
                r1 = r9 + 14;
                r2 = LD16(r1);
                ST16(r1, (r2 & -2));
                r0 = LD32(sp - 44);
                if ((r0 & r0) == 0) {
                    r0 = LD16((r9 + 12));
                    r3 = r13;
                    if (!(((r0 & 2) & (r0 & 2)) == 0)) {
                        r3 = r3 + 1;
                    }
                } else {
                    r1 = LD32(r9 + 40);
                    r2 = LD32(r9 + 44);
                    r3 = (r1 + r13) - r2;
                    if (!(r3 >= 0)) {
                        r3 = 0;
                    }
                    r1 = LD32(0x0608D8BC);
                    ST32(0x0608D8BC, (r1 + 1));
                }
                r0 = LD32(sp - 36);
                r1 = r9;
                if ((r0 & r0) == 0) {
                    r0 = LD16((r1 + 12));
                    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                        r3 = r3 + 1;
                    }
                }
                r1 = LD32(r9 + 44);
                ST32(r9 + 44, (r1 + r3));
                if (r3 >= 0) {
                    r1 = LD32(0x0608D940);
                    ST32(0x0608D940, (r1 + 1));
                }
                r0 = LD16(r9);
                r1 = r12;
                if (r0 == 11) {
                    r0 = GCALL1(0x06056938, r9);
                    r1 = r12;
                }
                r0 = LD8((r1 + 12));
                r13 = r13 + ((int)((unsigned)(r0 & 240) >> 2));
                r0 = GCALL1(0x060582A8, r12);
                r8 = r12 + 16;
                ST16(r8, 0);
                r4 = LD32(sp - 40);
                r0 = GCALL1(0x060585D8, r4);
                ST16(r8, r0);
                r7 = LD16((r9 + 36));
                r4 = LD32(sp - 40);
                r1 = LD16((r9 + 38));
                ST32((sp - 52), r1);
                r0 = GCALL5(0x06052FFC, (r4 + 16), r11, r13, r7, LD32((sp - 52)));
            } else {
                r0 = -2;
            }
        }
    } else {
        r0 = -2;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058D10(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, c3, c6;

    r8 = r4;
    r1 = LD32(0x0608D890);
    r4 = LD32(0x0608D874);
    r0 = GCALL4(0x0605ED4C, r4, (3 | ((((((r8 - r1) * 0x586FB587) >> 1) >> 1) << 2) + (((((r8 - r1) * 0x586FB587) >> 1) >> 1) << 2))), r6, r7);
    r3 = r0;
    if (!(r0 == -2)) {
        r0 = LD16((r8 + 2));
        r7 = r8;
        if (!(r0 == 3)) {
            r7 = r7 + 80;
            r1 = LD32(r7);
            c3 = (r1 & r1) == 0;
            r1 = r3;
            if (c3) {
                ST32(r7, ((r1 << 2) + (r1 << 2)));
            }
            r2 = LD32(r7);
            r6 = r3 - (((r2 >> 1) >> 1) >> 1);
            ST32(r7, (r2 + r6));
            if (!(r6 >= 0)) {
                r6 = -r6;
            }
            r3 = r8 + 84;
            r2 = LD32(r3);
            r2 = r2 + (r6 - ((r2 >> 1) >> 1));
            ST32(r3, r2);
            r1 = LD32(r7);
            r3 = r8 + 96;
            r1 = (((r1 >> 1) >> 1) + r2) >> 1;
            ST32(r3, r1);
            if (!(r1 > 99)) {
                ST32(r3, 100);
            }
        }
    }
    r9 = r8 + 64;
    r6 = LD32(r9);
    r1 = LD32((r8 + 68));
    c6 = r6 >= r1;
    r1 = r8;
    if (c6) {
        r1 = LD32((r1 + 72));
        r0 = GCALL2(0x0607286C, (r1 * r1), r6);
        r1 = r6 + r0;
    } else {
        r1 = LD32((r1 + 72));
        r1 = r1 + r6;
    }
    ST32(r9, r1);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06058DF0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c10, c12;
    int v24;

    r8 = r4;
    r4 = r5;
    r1 = LD16((r4 + 4));
    r2 = r4 + r1;
    r0 = LD8((r2 + 33));
    r10 = r2 + 20;
    if (!(((r0 & 16) & (r0 & 16)) == 0)) {
        r2 = LD32(r2 + 28);
        r1 = LD32(r8 + 40);
        r9 = r2 - r1;
        r11 = 0;
        if (r9 >= 0) {
            r0 = 0;
            if (r9 > 0) {
                r1 = LD32(r10 + 8);
                r2 = LD32(r8 + 44);
                if (!((r1 - r2) > 0)) {
                    r0 = GCALL4(0x06058D10, r8, 0, r6, r7);
                    r1 = LD32(r10 + 8);
                    ST32(r8 + 40, r1);
                    if (!((r9 & r9) == 0)) {
                        r7 = r8 + 12;
                        r2 = LD16(r7);
                        if (!(((2 & r2) & (2 & r2)) == 0)) {
                            r9 = r9 - 1;
                            ST16(r7, (r2 & -3));
                            r2 = r8 + 14;
                            r1 = LD16(r2);
                            r11 = r11 + 1;
                            ST16(r2, (r1 & -3));
                        }
                    }
                    r7 = r8 + 12;
                    r3 = LD16(r7);
                    if (!(((1 & r3) & (1 & r3)) == 0)) {
                        r2 = LD32(r10 + 8);
                        r1 = LD32(r8 + 44);
                        if (r2 == r1) {
                            r9 = r9 - 1;
                            r11 = r11 + 1;
                            ST16(r7, (-2 & r3));
                            r3 = r8 + 14;
                            r1 = LD16(r3);
                            ST16(r3, (r1 & -257));
                        }
                    }
                    r0 = r8;
                    r6 = LD32(r0 + 168);
                    r1 = LD32(r0 + 176);
                    r6 = r6 + r9;
                    v24 = r1;
                    r5 = v24;
                    r0 = GCALL5(0x0607286C, r6, r5, 0, 0, v24);
                    c10 = r0 * r5;
                    r0 = r8;
                    ST32(r0 + 168, (r6 - c10));
                    r1 = LD32(r0 + 172);
                    ST32(r0 + 172, (r1 - r9));
                    if (!((r9 & r9) == 0)) {
                        r2 = 160;
                        r1 = LD32(r0 + 160);
                        c12 = r1 > 0;
                        r1 = r1 + 1;
                        if (!(c12)) {
                            ST32(r0 + r2, r1);
                        }
                    }
                    r0 = GCALL5(0x06056800, r8, (r9 + r11), 0, 0, v24);
                    r0 = r9;
                } else {
                    r0 = LD16(r8);
                    r5 = r4;
                    if (!(r0 == 4)) {
                        r0 = GCALL3(0x06058F30, r8, r5, r6);
                    } else {
                        r0 = GCALL4(0x06058148, r4, r5, r6, r7);
                        r0 = -2;
                    }
                }
            }
        } else {
            r0 = LD16(r8);
            if (r0 == 4) {
                r0 = GCALL4(0x06058148, r4, r5, r6, r7);
                r0 = -2;
            } else {
                r0 = 0;
                if (r9 > 0) {
                    r1 = LD32(r10 + 8);
                    r2 = LD32(r8 + 44);
                    if (!((r1 - r2) > 0)) {
                        r0 = GCALL4(0x06058D10, r8, 0, r6, r7);
                        r1 = LD32(r10 + 8);
                        ST32(r8 + 40, r1);
                        if (!((r9 & r9) == 0)) {
                            r7 = r8 + 12;
                            r2 = LD16(r7);
                            if (!(((2 & r2) & (2 & r2)) == 0)) {
                                r9 = r9 - 1;
                                ST16(r7, (r2 & -3));
                                r2 = r8 + 14;
                                r1 = LD16(r2);
                                r11 = r11 + 1;
                                ST16(r2, (r1 & -3));
                            }
                        }
                        r7 = r8 + 12;
                        r3 = LD16(r7);
                        if (!(((1 & r3) & (1 & r3)) == 0)) {
                            r2 = LD32(r10 + 8);
                            r1 = LD32(r8 + 44);
                            if (r2 == r1) {
                                r9 = r9 - 1;
                                r11 = r11 + 1;
                                ST16(r7, (-2 & r3));
                                r3 = r8 + 14;
                                r1 = LD16(r3);
                                ST16(r3, (r1 & -257));
                            }
                        }
                        r0 = r8;
                        r6 = LD32(r0 + 168);
                        r1 = LD32(r0 + 176);
                        r6 = r6 + r9;
                        v24 = r1;
                        r5 = v24;
                        r0 = GCALL5(0x0607286C, r6, r5, 0, 0, v24);
                        c10 = r0 * r5;
                        r0 = r8;
                        ST32(r0 + 168, (r6 - c10));
                        r1 = LD32(r0 + 172);
                        ST32(r0 + 172, (r1 - r9));
                        if (!((r9 & r9) == 0)) {
                            r2 = 160;
                            r1 = LD32(r0 + 160);
                            c12 = r1 > 0;
                            r1 = r1 + 1;
                            if (!(c12)) {
                                ST32(r0 + r2, r1);
                            }
                        }
                        r0 = GCALL5(0x06056800, r8, (r9 + r11), 0, 0, v24);
                        r0 = r9;
                    } else {
                        r0 = LD16(r8);
                        r5 = r4;
                        if (!(r0 == 4)) {
                            r0 = GCALL3(0x06058F30, r8, r5, r6);
                        } else {
                            r0 = GCALL4(0x06058148, r4, r5, r6, r7);
                            r0 = -2;
                        }
                    }
                }
            }
        }
    } else {
        r0 = -2;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060596D8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11;

    r10 = r5;
    r1 = LD32(r10 + 4);
    r2 = LD32(r10 + 8);
    r9 = r4;
    if (!(r6 >= (r1 + r2))) {
        r0 = r9;
        r1 = LD32(r0 + 192);
        r11 = 188;
        ST32(r0 + 192, (r1 - r2));
        r2 = LD32(r0 + 188);
        r1 = LD32(r10 + 8);
        r6 = r2 + r1;
        ST32(r0 + 188, r6);
        r8 = LD32(r0 + 196);
        r4 = r6;
        if (r8 > 0) {
            r5 = r8;
            r0 = GCALL2(0x0607286C, r4, r5);
            r7 = r0;
            r6 = r6 - (r7 * r8);
            ST32(r9 + r11, r6);
        }
    }
    r0 = GCALL4(0x06059A0C, r10, r5, r6, r7);
    r8 = r9 + 120;
    r4 = LD32(r8);
    r0 = GCALL1(0x0605DD2C, r4);
    r10 = r0;
    if ((r10 & r10) == 0) {
        r4 = LD32(r8);
        r0 = GCALL1(0x0605DE08, r4);
        ST32(r8, 0);
    }
    return r10;
}
