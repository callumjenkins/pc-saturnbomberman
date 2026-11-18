#include "krnl.h"

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030250(int r4, int r5)
{
    int r0, r1, r8, r9, r10, r11;

    r10 = r4;
    r9 = r5;
    r8 = 0;
    r11 = 0x0607462C;
    r5 = 0;
    do {
        r0 = GCALL2(r11, r9, (((r5 + 3) << 2) + ((r5 + 3) << 2)));
        r1 = r0;
        r0 = r10;
        ST8(r0 + r8, r1);
        r8 = (short)(r8 + 1);
        r5 = -r8;
    } while (AGAIN(!((unsigned)(r8 & 0xFFFF) > (unsigned)3)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060305F8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 32);

    r9 = r4;
    r12 = LD32(sp);
    r10 = r5;
    r3 = LD32(sp + 4);
    r8 = r6;
    r1 = LD32(sp + 8);
    r13 = (short)r7;
    r2 = LD32(sp + 12);
    r11 = (short)r1;
    r14 = (short)r2;
    if ((r3 & r3) == 0) {
        r4 = LD32(r9 + 12);
        r0 = 0x0602FFD0;
    } else {
        r4 = LD32(r9 + 12);
        r0 = 0x0602FFD0;
        r4 = r4 + r4;
    }
    r0 = GCALL4(r0, r4, r5, r6, r7);
    r7 = r0 & 0xFFFF;
    r0 = 0;
    if (!((r12 & r12) == 0)) {
        r0 = 128;
    }
    r2 = LD16((r9 + 18));
    if (!(r2 > 8)) {
        r0 = r0 | 16;
    }
    ST8(r10, r0);
    r1 = LD32((r9 + 68));
    ST16((r10 + 2), ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)));
    r3 = LD16((r9 + 62));
    r2 = r10;
    if ((unsigned)(r3 & 0xFFFF) > (unsigned)0xFFF) {
        ST16((r10 + 4), r3);
    } else {
        ST16((r2 + 4), 0x2000);
    }
    ST8(r8, r13);
    ST8((r8 + 1), r11);
    ST8((r8 + 2), r14);
    ST16((r8 + 4), r7);
    ST8((r8 + 8), 0);
    ST8((r8 + 9), r11);
    ST8((r8 + 6), 0);
    ST8((r8 + 7), r11);
    r0 = GCALL2(0x06067350, r10, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060306D0(int r4, int r5)
{
    int r1, r2, r3;

    r3 = LD32(r4 + 4);
    r1 = r4 + 4;
    ST32(r5 + 4, r3);
    r3 = LD32(r1 + 4);
    r2 = r5 + 4;
    ST32(r2 + 4, r3);
    r1 = r1 + 8;
    r3 = LD32(r1);
    r1 = r1 + 4;
    r2 = r2 + 8;
    ST32(r2, r3);
    r3 = LD32(r1);
    r1 = r1 + 4;
    r2 = r2 + 4;
    ST32(r2, r3);
    r3 = LD32(r1);
    r1 = r1 + 4;
    r2 = r2 + 4;
    ST32(r2, r3);
    r3 = LD32(r1);
    r1 = r1 + 4;
    r2 = r2 + 4;
    ST32(r2, r3);
    r3 = LD32(r1);
    r1 = r1 + 4;
    r2 = r2 + 4;
    ST32(r2, r3);
    r3 = LD32(r1);
    r2 = r2 + 4;
    ST32(r2, r3);
    r1 = LD32((r1 + 4));
    ST32(r2 + 4, r1);
    ST32(r5 + 40, 0);
    ST32(r5 + 44, 0);
    ST32(r5 + 48, 0);
    ST32(r5 + 52, 0);
    ST16((r5 + 56), 0);
    ST16((r5 + 58), 0);
    ST32(r5, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06031190(int r4, int r5, int r6)
{
    int r0, r8, r9;
    FRAME(sp, 104);

    r9 = r6;
    r8 = (sp - 104) + 4;
    r0 = GCALL3(0x0603EE88, r8, r4, r5);
    if ((r0 & r0) == 0) {
        r0 = GCALL1(0x0603EE14, r8);
        r5 = r9;
        if ((r0 & r0) == 0) {
            r0 = GCALL2(0x0603104C, (sp - 104), r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060311D4(int r4, int r5, int r6)
{
    int r0;
    FRAME(sp, 96);

    ST32(sp - 72, r4);
    ST32(sp - 68, 0x1000);
    ST16((sp - 88), 1);
    ST16((sp - 76), 1);
    ST32(sp - 92, 3);
    r0 = GCALL2(0x0603104C, (sp - 96), r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06031208(int r4, int r5, int r6)
{
    int r0, r8, r9;
    FRAME(sp, 104);

    r9 = r6;
    r8 = (sp - 104) + 4;
    r0 = GCALL3(0x0603EA7C, r8, r4, r5);
    if ((r0 & r0) == 0) {
        r0 = GCALL1(0x0603E9D8, r8);
        r5 = r9;
        if ((r0 & r0) == 0) {
            r0 = GCALL2(0x0603104C, (sp - 104), r5);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060314EC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12;
    int v28;
    int v32;
    int v36;
    int v40;

    r8 = r4;
    r12 = r5;
    r11 = r6;
    r10 = r7;
    r5 = LD32(r8 + 16);
    r9 = -1;
    r4 = LD32(r8 + 12);
    r0 = GCALL2(0x0603E9B8, r4, r5);
    r1 = r8;
    if (!((r0 & r0) == 0)) {
        r0 = 0x06030914;
        r1 = r1 + 20;
        r5 = LD32(r8 + 16);
        r4 = LD32(r8 + 12);
        r0 = GCALL8(r0, r4, r5, 7, 0, ((short)r12), r11, r10, r1);
        r9 = r0;
    } else {
        r5 = LD32(r8 + 16);
        r4 = LD32(r8 + 12);
        r0 = GCALL2(0x060410AC, r4, r5);
        r1 = r8;
        if ((r0 & r0) == 0) {
            r5 = LD32(r8 + 16);
            r4 = LD32(r8 + 12);
            r0 = GCALL2(0x0603EDF4, r4, r5);
            r1 = r8;
            if (!((r0 & r0) == 0)) {
                r1 = r1 + 20;
                r0 = 0x06030738;
                r5 = LD32(r8 + 16);
                r4 = LD32(r8 + 12);
                r0 = GCALL8(r0, r4, r5, 7, 0, ((short)r12), r11, r10, r1);
                r9 = r0;
            }
        } else {
            r0 = 0x06030914;
            r1 = r1 + 20;
            r5 = LD32(r8 + 16);
            r4 = LD32(r8 + 12);
            r0 = GCALL8(r0, r4, r5, 7, 0, ((short)r12), r11, r10, r1);
            r9 = r0;
        }
    }
    r1 = LD32(0x06089CB8);
    ST32(r8 + 24, r1);
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06031D74(int r4)
{
    int r0, r1, r8, r9;

    r0 = (short)r4;
    if (!(r0 == -1)) {
        r9 = 0x06087DD8;
        r8 = (short)r0 * (short)92;
        r1 = LD32((r8 + 0x06087DD8));
        r4 = r0 & 255;
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x06067460, r4);
            r0 = r8;
            ST32(r0 + r9, 1);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06032158(int r4)
{
    ST32(0x06078040, r4);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06032440(void)
{
    int r1;

    r1 = LD32(0x06087F7C);
    ST32(0x06087F78, r1);
    ST16(0x06087F84, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603245C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    FRAME(sp, 8);

    if ((r4 & r4) == 0) {
        r0 = GCALL4(0x06032718, 0, (sp - 8), 0, r7);
        r1 = -1;
        if (!((r0 & r0) == 0)) {
            r2 = 0x0607811C;
        } else {
            r2 = 0x0607811C;
            r1 = LD32(sp - 8);
        }
        ST32(r2, r1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032914(int r4)
{
    int r1, r2;

    r1 = 28;
    if (!((r4 & r4) == 0)) {
        r2 = r4;
        if (!((unsigned)r4 > (unsigned)r1)) {
            return 1;
        } else {
            r1 = LD32(0x06032910);
            return ((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)(r2 - 29) * (unsigned)r1)) >> 32)) >> 2)) >> 1)) >> 2)) + 2;
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032D18(int r4)
{
    int r0, r1, r3;

    r0 = LD8(0x06089CF3);
    ST8((r4 + 2), (r0 & 15));
    r0 = LD8(0x06089CF4);
    ST8((r4 + 3), ((((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2))) + ((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)))) + (r0 & 15)));
    r0 = LD8(0x06089CF1);
    r3 = (((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) * 0x3E8) + ((r0 & 15) * 100);
    r0 = LD8(0x06089CF2);
    ST16(r4, ((r0 & 15) + (r3 + (((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2))) + ((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)))))));
    r0 = LD8(0x06089CF5);
    ST8((r4 + 4), ((((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2))) + ((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)))) + (r0 & 15)));
    r0 = LD8(0x06089CF6);
    ST8((r4 + 5), ((((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2))) + ((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)))) + (r0 & 15)));
    r0 = LD8(0x06089CF7);
    r1 = ((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2))) + ((((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)) << 2) + ((int)((unsigned)((int)((unsigned)(r0 & 255) >> 2)) >> 2)));
    r0 = r0 & 15;
    ST8((r4 + 6), (r1 + r0));
    r1 = LD8(0x06089CF3);
    ST8((r4 + 7), ((int)((unsigned)((int)((unsigned)(r1 & 255) >> 2)) >> 2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06032DE8(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033050(void)
{
    int r0, r1;

    r1 = 0x20100063;
    do {
        r0 = LD8(r1);
    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    ST8(0x20100063, 1);
    ST8(0x2010001F, 11);
    r0 = LD8(0x20100063);
    r0 = r0 & 1;
    r1 = 0x20100063;
    if (!((r0 & r0) == 0)) {
        do {
            r0 = LD8(r1);
            r0 = r0 & 1;
        } while (AGAIN(!((r0 & r0) == 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06033084(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033088(void)
{
    int r0;

    r0 = LD32(0x06078120);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603313C(int r4)
{
    int r0, r8;

    r8 = r4;
    r0 = GCALL2(0x060193B0, r4, 0x06033094);
    r0 = GCALL2(0x060193B0, r8, 0x06033094);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033378(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9;
    FRAME(sp, 20);

    r8 = r4;
    r9 = r5;
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        r7 = sp - 20;
        if (!((r9 & r9) == 0)) {
            r0 = GCALL4(0x0603510C, r8, r9, (sp - 20), (r7 + 4));
            r6 = LD32(sp - 20);
            r0 = GCALL3(0x0601CF94, r8, 3, r6);
            r7 = LD32(r8 + 56);
            r1 = r7 + r7;
            ST16((r1 + r8) + 0xEB0, r0);
            r5 = r8 + (((r1 + r7) << 2) + 0x2B0);
            ST32(r5 + 4, r9);
            ST32(r5 + 8, 0);
            r2 = LD32(sp - 16);
            r3 = LD32(r8 + 32);
            if (r2 > r3) {
                r1 = LD32(r8 + 36);
                ST32(r8 + 36, (r1 - r3));
                r1 = LD32(r8 + 36);
                ST32(r8 + 32, r2);
                ST32(r8 + 36, (r1 + r2));
            }
            r0 = GCALL2(0x0601E884, r8, r5);
            r1 = LD32(r8 + 56);
            r0 = 1;
            ST32(r8 + 56, (r1 + 1));
        } else {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033540(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, c2, c8;

    r9 = r4;
    r11 = 0x06078128;
    r1 = LD32(0x06078128);
    r10 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r1 = LD32(0x10C8 + r9);
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x060287D0, 32);
            r8 = r0;
            r0 = 1;
            if (!((r8 & r8) == 0)) {
                r0 = GCALL1(0x06034DE8, r8);
                r0 = GCALL3(0x06034990, r9, r8, r10);
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL1(0x06033930, r8);
                    r1 = r11;
                    if (!((r0 & r0) == 0)) {
                        r1 = LD32((r1 - 4));
                        if ((r1 & r1) == 0) {
                            r0 = 1;
                        } else {
                            r1 = LD32(r1 + 4);
                            if ((r1 & r1) == 0) {
                                r0 = 1;
                            } else {
                                r0 = LD32(r1);
                                c8 = r0 == 1;
                                r0 = 1;
                                if (c8) {
                                    r2 = r1 + 40;
                                    r1 = LD16(r2);
                                    ST16((r8 + 20), r1);
                                    r1 = LD16(r2);
                                    ST16(r2, (r1 + 1));
                                    r0 = 1;
                                }
                            }
                        }
                    } else {
                        r1 = 0x06027F48;
                        POLL();
                        r0 = GCALL1(r1, r8);
                        r0 = 1;
                    }
                } else {
                    r1 = 0x06034E64;
                    r0 = GCALL1(r1, r8);
                    r0 = 1;
                }
            }
        } else {
            r0 = LD32(0x10CC + r9);
            c2 = r0 == 1;
            r0 = 1;
            if (c2) {
                r0 = GCALL1(0x060287D0, 32);
                r8 = r0;
                r0 = 1;
                if (!((r8 & r8) == 0)) {
                    r0 = GCALL1(0x06034DE8, r8);
                    r0 = GCALL3(0x06034990, r9, r8, r10);
                    if (!((r0 & r0) == 0)) {
                        r0 = GCALL1(0x06033930, r8);
                        r1 = r11;
                        if (!((r0 & r0) == 0)) {
                            r1 = LD32((r1 - 4));
                            if ((r1 & r1) == 0) {
                                r0 = 1;
                            } else {
                                r1 = LD32(r1 + 4);
                                if ((r1 & r1) == 0) {
                                    r0 = 1;
                                } else {
                                    r0 = LD32(r1);
                                    c8 = r0 == 1;
                                    r0 = 1;
                                    if (c8) {
                                        r2 = r1 + 40;
                                        r1 = LD16(r2);
                                        ST16((r8 + 20), r1);
                                        r1 = LD16(r2);
                                        ST16(r2, (r1 + 1));
                                        r0 = 1;
                                    }
                                }
                            }
                        } else {
                            r1 = 0x06027F48;
                            POLL();
                            r0 = GCALL1(r1, r8);
                            r0 = 1;
                        }
                    } else {
                        r1 = 0x06034E64;
                        r0 = GCALL1(r1, r8);
                        r0 = 1;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033828(int r4, int r5)
{
    int r0, r1, r2, c4;

    r0 = 0;
    if ((r5 & r5) == 0) {
        return r0;
    } else {
        r2 = 0x06078120;
        r1 = LD32(0x06078120);
        if (!((r1 & r1) == 0)) {
            r1 = LD32(r2 + 4);
            ST32(r1 + 28, r5);
            ST32(r2 + 4, r5);
        } else {
            ST32(r2, r5);
            ST32(r2 + 4, r5);
        }
        r1 = LD32(0x10C8 + r4);
        if (!((r1 & r1) == 0)) {
            r0 = LD32(0x10CC + r4);
            if (r0 == 1) {
                r2 = 0x06078134;
                r1 = LD32(0x06078134);
                c4 = (r1 & r1) == 0;
                r1 = 0x06078134;
                if (!(c4)) {
                    r1 = LD32((r1 - 16));
                    ST32(r2 + 4, r1);
                    ST32(r2, 0);
                }
            }
        }
        return 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603387C(int r4, int r5)
{
    int r0, r8, r9;

    r8 = r5;
    r9 = r4;
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        r0 = LD32(r8 + 32);
        if (!(r0 == 5)) {
            r0 = GCALL2(0x06033974, r9, r8);
        } else {
            r0 = GCALL1(0x060338B8, r8);
            if (!((r0 & r0) == 0)) {
                r0 = GCALL2(0x06033974, r9, r8);
            } else {
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033974(int r4, int r5)
{
    int r0, r1, r2;

    if (!((r5 & r5) == 0)) {
        r2 = 0x06078120;
        r1 = LD32(0x06078120);
        if ((r1 & r1) == 0) {
            POLL();
            return 0;
        } else {
            r2 = LD32(r2 + 4);
            if ((r2 & r2) == 0) {
                POLL();
                return 0;
            } else {
                r1 = LD32(r2);
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r2 + 4);
                    ST32(r5 + 8, r1);
                    r1 = LD32(r2 + 4);
                    ST32(r1 + 4, r5);
                    ST32(r2 + 4, r5);
                } else {
                    ST32(r2, r5);
                    ST32(r2 + 4, r5);
                }
                r1 = LD32(0x10C8 + r4);
                if (!((r1 & r1) == 0)) {
                    r0 = LD32(0x10CC + r4);
                    if (r0 == 1) {
                        r2 = 0x0607812C;
                        r1 = LD32(0x0607812C);
                        if (!((r1 & r1) == 0)) {
                            ST32(r2 + 4, r5);
                            ST32(r2, 0);
                        }
                    }
                }
                return 1;
            }
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033E0C(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, c1;

    r9 = r5;
    if ((r9 & r9) == 0) {
        r0 = 0;
    } else {
        r1 = LD32(r9 + 36);
        c1 = (r1 & r1) == 0;
        r1 = r9;
        if (c1) {
            r0 = 0;
        } else {
            r1 = LD32((r1 + 72));
            if ((r1 & r1) == 0) {
                r0 = 0;
            } else {
                r8 = LD32(r1 + 8);
                r11 = 0;
                if ((r8 & r8) == 0) {
                    r0 = 0;
                } else {
                    r12 = 0x06075104;
                    r10 = 1;
                    while (1) {
                        r4 = LD32(r8 + 36);
                        r1 = r8;
                        if ((r4 & r4) == 0) {
                            r8 = LD32((r1 + 80));
                            if (!((r8 & r8) == 0)) {
                                POLL();
                                continue;
                            } else {
                                r0 = 0;
                                break;
                            }
                        } else {
                            r5 = LD32(r9 + 36);
                            r0 = GCALL2(r12, r4, r5);
                            r1 = r8;
                            if (!((r0 & r0) == 0)) {
                                r8 = LD32((r1 + 80));
                                if (!((r8 & r8) == 0)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = 0;
                                    break;
                                }
                            } else {
                                r0 = 1;
                                if ((r8 & r8) == 0) {
                                    break;
                                } else {
                                    r2 = r8;
                                    do {
                                        r2 = r2 + 64;
                                        r1 = LD32(r2);
                                        if (!((r1 & r1) == 0)) {
                                            ST32(r2, r11);
                                            ST32(r8 + 24, r10);
                                        }
                                        r8 = LD32((r8 + 76));
                                        r2 = r8;
                                    } while (AGAIN(!((r8 & r8) == 0)));
                                    r0 = 1;
                                    break;
                                }
                            }
                        }
                        POLL();
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033E8C(void)
{
    int r1, r2, c0;

    r2 = 0x06078120;
    r1 = LD32(0x06078120);
    c0 = (r1 & r1) == 0;
    r1 = 0;
    if (c0) {
        ST32(r2 + 4, r1);
        return 0;
    } else {
        ST32(r2 + 8, 1);
        ST32(r2 + 4, r1);
        return 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06033EA8(void)
{
    ST32(0x0607812C, 1);
    ST32(0x06078134, 1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06033EB8(void)
{
    ST32(0x0607812C, 0);
    ST32(0x06078130, 0);
    ST32(0x06078134, 0);
    ST32(0x06078138, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033ECC(int r4)
{
    int r0, r1, r2, r3, r7;

    r2 = 0x06078120;
    r1 = LD32(0x06078120);
    r0 = 0;
    if ((r1 & r1) == 0) {
        return r0;
    } else {
        r1 = LD32(0x10C8 + r4);
        if ((r1 & r1) == 0) {
            r3 = 0x06078124;
            r1 = LD32(0x06078124);
            r7 = 0;
            if (!((r1 & r1) == 0)) {
                ST32(r1 + 4, r7);
                r1 = LD32(r3);
                r1 = LD32(r1 + 28);
                r2 = r3 - 4;
                ST32(r3, r1);
                if ((r1 & r1) == 0) {
                    r1 = LD32(r2);
                    ST32(r3, r1);
                    if (!((r1 & r1) == 0)) {
                        ST32(r1 + 4, r7);
                    }
                }
                r3 = 0x06078124;
            } else {
                r2 = LD32((r3 - 4));
                ST32(r3, r2);
                if (!((r2 & r2) == 0)) {
                    ST32(r2 + 4, 0);
                }
            }
            r2 = LD32(r3);
            r1 = 0;
            if (!((r2 & r2) == 0)) {
                ST32(r2 + 4, r1);
            }
            r1 = LD32(0x10C8 + r4);
            if (!((r1 & r1) == 0)) {
                r0 = LD32(0x10CC + r4);
                if (r0 == 1) {
                    r1 = LD32(r3 + 16);
                    if (!((r1 & r1) == 0)) {
                        r1 = LD32(r3);
                        ST32(r3 + 20, r1);
                        ST32(r3 + 16, 0);
                    }
                }
            }
            return 1;
        } else {
            r1 = LD32(0x10CC + r4);
            r0 = 1;
            if (!(r1 > 1)) {
                r3 = 0x06078124;
                r1 = LD32(0x06078124);
                r7 = 0;
                if (!((r1 & r1) == 0)) {
                    ST32(r1 + 4, r7);
                    r1 = LD32(r3);
                    r1 = LD32(r1 + 28);
                    r2 = r3 - 4;
                    ST32(r3, r1);
                    if ((r1 & r1) == 0) {
                        r1 = LD32(r2);
                        ST32(r3, r1);
                        if (!((r1 & r1) == 0)) {
                            ST32(r1 + 4, r7);
                        }
                    }
                    r3 = 0x06078124;
                } else {
                    r2 = LD32((r3 - 4));
                    ST32(r3, r2);
                    if (!((r2 & r2) == 0)) {
                        ST32(r2 + 4, 0);
                    }
                }
                r2 = LD32(r3);
                r1 = 0;
                if (!((r2 & r2) == 0)) {
                    ST32(r2 + 4, r1);
                }
                r1 = LD32(0x10C8 + r4);
                if (!((r1 & r1) == 0)) {
                    r0 = LD32(0x10CC + r4);
                    if (r0 == 1) {
                        r1 = LD32(r3 + 16);
                        if (!((r1 & r1) == 0)) {
                            r1 = LD32(r3);
                            ST32(r3 + 20, r1);
                            ST32(r3 + 16, 0);
                        }
                    }
                }
                return 1;
            } else {
                r1 = LD32(r2 + 20);
                if ((r1 & r1) == 0) {
                    r3 = 0x06078124;
                    r1 = LD32(0x06078124);
                    r7 = 0;
                    if (!((r1 & r1) == 0)) {
                        ST32(r1 + 4, r7);
                        r1 = LD32(r3);
                        r1 = LD32(r1 + 28);
                        r2 = r3 - 4;
                        ST32(r3, r1);
                        if ((r1 & r1) == 0) {
                            r1 = LD32(r2);
                            ST32(r3, r1);
                            if (!((r1 & r1) == 0)) {
                                ST32(r1 + 4, r7);
                            }
                        }
                        r3 = 0x06078124;
                    } else {
                        r2 = LD32((r3 - 4));
                        ST32(r3, r2);
                        if (!((r2 & r2) == 0)) {
                            ST32(r2 + 4, 0);
                        }
                    }
                    r2 = LD32(r3);
                    r1 = 0;
                    if (!((r2 & r2) == 0)) {
                        ST32(r2 + 4, r1);
                    }
                    r1 = LD32(0x10C8 + r4);
                    if (!((r1 & r1) == 0)) {
                        r0 = LD32(0x10CC + r4);
                        if (r0 == 1) {
                            r1 = LD32(r3 + 16);
                            if (!((r1 & r1) == 0)) {
                                r1 = LD32(r3);
                                ST32(r3 + 20, r1);
                                ST32(r3 + 16, 0);
                            }
                        }
                    }
                    return 1;
                } else {
                    r1 = LD32(r2 + 24);
                    ST32(r2 + 4, r1);
                    ST32(r2 + 20, 0);
                    return r0;
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033F6C(int r4)
{
    int r0, r1, r2, r3;

    r3 = 0x06078124;
    r2 = LD32(0x06078124);
    if (!((r2 & r2) == 0)) {
        r1 = LD32(r2);
        if ((r1 & r1) == 0) {
            POLL();
            return 0;
        } else {
            r1 = LD32(0x10C8 + r4);
            if ((r1 & r1) == 0) {
                r1 = LD32(r2 + 4);
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r1 + 4);
                    ST32(r2 + 4, r1);
                } else {
                    r1 = LD32(r2);
                    ST32(r2 + 4, r1);
                }
                r1 = LD32(0x10C8 + r4);
                if (!((r1 & r1) == 0)) {
                    r0 = LD32(0x10CC + r4);
                    if (r0 == 1) {
                        r3 = 0x0607812C;
                        r1 = LD32(0x0607812C);
                        if (!((r1 & r1) == 0)) {
                            r1 = LD32(r2 + 4);
                            ST32(r3 + 4, r1);
                            ST32(r3, 0);
                        }
                    }
                }
                return 1;
            } else {
                r1 = LD32(0x10CC + r4);
                r0 = 1;
                if (!(r1 > 1)) {
                    r1 = LD32(r2 + 4);
                    if (!((r1 & r1) == 0)) {
                        r1 = LD32(r1 + 4);
                        ST32(r2 + 4, r1);
                    } else {
                        r1 = LD32(r2);
                        ST32(r2 + 4, r1);
                    }
                    r1 = LD32(0x10C8 + r4);
                    if (!((r1 & r1) == 0)) {
                        r0 = LD32(0x10CC + r4);
                        if (r0 == 1) {
                            r3 = 0x0607812C;
                            r1 = LD32(0x0607812C);
                            if (!((r1 & r1) == 0)) {
                                r1 = LD32(r2 + 4);
                                ST32(r3 + 4, r1);
                                ST32(r3, 0);
                            }
                        }
                    }
                    return 1;
                } else {
                    r1 = LD32(r3 + 8);
                    if ((r1 & r1) == 0) {
                        r1 = LD32(r2 + 4);
                        if (!((r1 & r1) == 0)) {
                            r1 = LD32(r1 + 4);
                            ST32(r2 + 4, r1);
                        } else {
                            r1 = LD32(r2);
                            ST32(r2 + 4, r1);
                        }
                        r1 = LD32(0x10C8 + r4);
                        if (!((r1 & r1) == 0)) {
                            r0 = LD32(0x10CC + r4);
                            if (r0 == 1) {
                                r3 = 0x0607812C;
                                r1 = LD32(0x0607812C);
                                if (!((r1 & r1) == 0)) {
                                    r1 = LD32(r2 + 4);
                                    ST32(r3 + 4, r1);
                                    ST32(r3, 0);
                                }
                            }
                        }
                        return 1;
                    } else {
                        r1 = LD32(r3 + 12);
                        ST32(r2 + 4, r1);
                        ST32(r3 + 8, 0);
                        return r0;
                    }
                }
            }
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033FE0(void)
{
    int r0, r1;

    r0 = LD32(0x06078124);
    if (!((r0 & r0) == 0)) {
        r0 = LD32(r0 + 4);
        if ((r0 & r0) == 0) {
            POLL();
            return 0;
        } else {
            r1 = LD32(r0);
            if (!((r1 & r1) == 0)) {
                POLL();
                return 0;
            } else {
                return r0;
            }
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06034000(void)
{
    int r0, r1, r2;

    r1 = LD32(0x06078124);
    if (!((r1 & r1) == 0)) {
        r2 = LD32(r1 + 4);
        if ((r2 & r2) == 0) {
            POLL();
            return 0;
        } else {
            r1 = LD32(r2);
            r0 = r2;
            if (!(r1 == 1)) {
                POLL();
                return 0;
            } else {
                return r0;
            }
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06034024(void)
{
    int r0, r1, r2;

    r1 = LD32(0x06078124);
    if (!((r1 & r1) == 0)) {
        r2 = LD32(r1 + 4);
        if ((r2 & r2) == 0) {
            POLL();
            return 0;
        } else {
            r1 = LD32(r2);
            r0 = r2;
            if (!(r1 == 2)) {
                POLL();
                return 0;
            } else {
                return r0;
            }
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06034CEC(int r4)
{
    int r0, r1;

    r1 = LD32(0x10C8 + r4);
    if ((r1 & r1) == 0) {
        return 1;
    } else {
        r0 = LD32(0x10CC + r4);
        if (!(r0 == 3)) {
            return 0;
        } else {
            return 1;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034D08(int r4)
{
    ST32(r4, 0);
    ST32(r4 + 4, 0);
    ST32(r4 + 8, 0);
    ST32(r4 + 12, 0);
    ST32(r4 + 16, 0);
    ST32(r4 + 20, 0);
    ST8((r4 + 24), 0);
    ST32(r4 + 28, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034D24(int r4)
{
    int r1;

    ST32(r4, 0);
    ST32(r4 + 4, 0);
    ST32(r4 + 8, 0);
    ST32(r4 + 32, 8);
    ST32(r4 + 36, 0);
    ST32(r4 + 40, -1);
    ST32(r4 + 44, 0);
    ST32(r4 + 48, 20);
    ST32(r4 + 52, 0);
    ST32(r4 + 56, 0);
    ST32(r4 + 60, 0);
    ST32((r4 + 64), 0);
    ST32((r4 + 68), 0);
    r1 = LD32(0x06078124);
    ST32((r4 + 72), r1);
    ST32((r4 + 76), 0);
    ST32((r4 + 80), 0);
    ST16((r4 + 12), 0);
    ST32(r4 + 16, 0);
    ST16((r4 + 14), 0);
    ST32(r4 + 20, 0);
    ST32((r4 + 92), 0);
    ST32(r4 + 24, 0);
    ST32((r4 + 88), 0);
    ST32((r4 + 84), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034D90(int r4)
{
    ST32(r4, 1);
    ST32(r4 + 4, 0);
    ST32(r4 + 8, 0);
    ST32(r4 + 44, 0);
    ST32(r4 + 48, 0);
    ST32(r4 + 52, 0);
    ST32(r4 + 56, 0);
    ST32(r4 + 60, 0);
    ST16((r4 + 64), 0);
    ST16((r4 + 66), 0);
    ST16((r4 + 12), 0);
    ST32(r4 + 16, 0);
    ST16((r4 + 14), 0);
    ST32(r4 + 20, 0);
    ST32((r4 + 72), 0);
    ST32(r4 + 24, 0);
    ST16((r4 + 32), 0);
    ST16((r4 + 34), 0);
    ST16((r4 + 36), 0);
    ST16((r4 + 38), 0);
    ST16((r4 + 40), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034DE8(int r4)
{
    ST32(r4, 0);
    ST32(r4 + 4, 0);
    ST32(r4 + 8, 0);
    ST32(r4 + 12, 0);
    ST32(r4 + 16, 0);
    ST32(r4 + 24, 0);
    ST32(r4 + 28, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034DFC(int r4)
{
    ST32(r4, 2);
    ST32(r4 + 4, 0);
    ST32(r4 + 8, 0);
    ST32(r4 + 32, 0);
    ST32(r4 + 36, 0);
    ST32(r4 + 40, 0);
    ST16((r4 + 44), 20);
    ST16((r4 + 46), 1);
    ST32(r4 + 48, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034E98(int r4)
{
    int r0, r1, r8, r9, r10;

    r9 = r4;
    if (!((r9 & r9) == 0)) {
        r8 = LD32(r9);
        r1 = 0;
        if (!((r8 & r8) == 0)) {
            r10 = 0x06034E64;
            r4 = r8;
            do {
                r8 = LD32(r8 + 24);
                r0 = GCALL1(r10, r4);
                r4 = r8;
            } while (AGAIN(!((r8 & r8) == 0)));
            r1 = 0;
        }
        ST32(r9, r1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06035068(int r4, int r5)
{
    int r0, r1, r2;

    r0 = r4;
    r1 = LD32(r0 + 0x10B8);
    r2 = LD16(r1);
    ST16(r5, r2);
    r1 = LD16((r1 + 2));
    ST16((r5 + 2), r1);
    r2 = LD32(r0 + 0x10B8);
    ST16(r2, 0);
    r1 = LD32(r0 + 0x10B8);
    r1 = r1 + 2;
    r2 = LD8(r1);
    ST8(r1, (r2 & 127));
    r1 = LD32(r4 + 0x10B8);
    r1 = r1 + 2;
    r2 = LD8(r1);
    ST8(r1, (r2 & 191));
    r1 = LD32(r4 + 0x10B8);
    r1 = r1 + 2;
    r2 = LD8(r1);
    ST8(r1, (r2 & 223));
    return 223;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060350B0(int r4, int r5)
{
    int r1, r2;

    r1 = LD32(0x10B8 + r4);
    r2 = LD16(r5);
    ST16(r1, r2);
    r2 = LD16((r5 + 2));
    ST16((r1 + 2), r2);
    return 0x10B8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060350C4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;

    r8 = r5;
    r9 = r6;
    if ((r4 & r4) == 0) {
        r0 = 0;
    } else {
        r0 = GCALL1(0x060216EC, 0x204);
        r0 = GCALL4(0x0601CC78, (4 | (r0 << 8)), 128, 0, r7);
        r1 = LD32(r0 + 40);
        ST32(r8, r1);
        r1 = LD32(r0 + 36);
        ST32(r9, r1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603510C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c5;
    FRAME(sp, 44);

    r11 = r4;
    r10 = r5;
    r14 = r6;
    ST32(sp - 36, r7);
    r0 = GCALL3(0x060350C4, r4, (sp - 44), (sp - 40));
    r2 = r10 + 66;
    r1 = LD16(r2);
    if ((r1 & r1) == 0) {
        r8 = LD32(r10 + 44);
        if (!((r8 & r8) == 0)) {
            r9 = r2;
            r13 = 0x060455FC;
            r12 = 0x0607507C;
            do {
                r1 = LD32(0x10D4 + r11);
                if ((r1 & r1) == 0) {
                    r4 = LD32(r8 + 16);
                    r0 = GCALL1(r12, r4);
                    r1 = LD16(r9);
                } else {
                    r4 = LD32(r8 + 16);
                    r0 = GCALL1(r13, r4);
                    r1 = LD16(r9);
                }
                if (r0 > r1) {
                    ST16(r9, r0);
                }
                r8 = LD32(r8 + 24);
            } while (AGAIN(!((r8 & r8) == 0)));
        }
    }
    r2 = LD16((r10 + 64));
    c5 = r2 > 1;
    r2 = LD32(sp - 44);
    if (!(c5)) {
        r1 = LD16((r10 + 66));
        r1 = r1 + 6;
    } else {
        r1 = LD16((r10 + 66));
        r1 = r1 + 4;
    }
    ST32(r14, ((r2 * r1) + 4));
    r2 = LD16((r10 + 64));
    r1 = LD32(sp - 40);
    r3 = LD32(sp - 36);
    ST32(r3, ((r1 * r2) + 3));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060351C4(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10;
    FRAME(sp, 24);

    r8 = r4;
    r9 = r5;
    r0 = GCALL4(0x0603510C, r4, r5, (sp - 24), (sp - 20));
    r1 = LD32(r8 + 32);
    r2 = LD32(sp - 20);
    r1 = r1 - r2;
    r2 = LD32(r8 + 12);
    r10 = r2 + r1;
    r0 = GCALL1(0x06034CEC, r8);
    r2 = r9;
    if (!((r0 & r0) == 0)) {
        r1 = LD32(r8 + 8);
        ST16((r2 + 12), r1);
        ST32(r9 + 16, r10);
        r1 = LD32(r8 + 8);
        r2 = LD32(sp - 24);
        ST16((r9 + 14), (r1 + r2));
        r1 = LD32(sp - 20);
        ST32(r9 + 20, (r1 + r10));
    }
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        if (r0 == 1) {
            r4 = LD32(sp - 24);
            r0 = GCALL1(0x0602AC28, r4);
            r1 = LD32(0x10D0 + r8);
            r4 = LD32(sp - 24);
            ST32(0x10D0 + r8, (r1 + r4));
            r0 = GCALL1(0x0602AC4C, r4);
        }
    }
    r0 = GCALL2(0x06035454, r8, r9);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06035820(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10;
    FRAME(sp, 24);

    r8 = r5;
    r9 = r6;
    r10 = r7;
    r0 = GCALL3(0x060350C4, r4, (sp - 24), (sp - 20));
    r3 = r8 + 46;
    r0 = LD16(r3);
    r2 = 2;
    if (r0 == 1) {
        r2 = 4;
    }
    r1 = LD16((r8 + 44));
    r1 = r1 + (r2 + 2);
    r2 = LD32(sp - 24);
    ST32(r9, ((r2 * r1) + 4));
    r1 = LD16(r3);
    r2 = LD32(sp - 20);
    ST32(r10, ((r2 * (r1 + 1)) + 4));
    r1 = LD32(sp - 20);
    ST16((r8 + 28), r1);
    r1 = LD32(sp - 24);
    ST16((r8 + 30), r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603588C(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10;
    FRAME(sp, 24);

    r8 = r4;
    r9 = r5;
    r0 = GCALL4(0x06035820, r4, r5, (sp - 24), (sp - 20));
    r1 = LD32(r8 + 32);
    r2 = LD32(sp - 20);
    r1 = r1 - r2;
    r2 = LD32(r8 + 12);
    r10 = r2 + r1;
    r0 = GCALL1(0x06034CEC, r8);
    r2 = r9;
    if (!((r0 & r0) == 0)) {
        r1 = LD32(r8 + 8);
        ST16((r2 + 12), r1);
        ST32(r9 + 16, r10);
        r1 = LD32(r8 + 8);
        r2 = LD32(sp - 24);
        ST16((r9 + 14), (r1 + r2));
        r1 = LD32(sp - 20);
        ST32(r9 + 20, (r1 + r10));
    }
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        if (r0 == 1) {
            r4 = LD32(sp - 24);
            r0 = GCALL1(0x0602AC28, r4);
            r1 = LD32(0x10D0 + r8);
            r4 = LD32(sp - 24);
            ST32(0x10D0 + r8, (r1 + r4));
            r0 = GCALL1(0x0602AC4C, r4);
        }
    }
    r0 = GCALL3(0x0603592C, r8, r9, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036138(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, r14, c0, c2;
    int v36;
    int v40;
    int v44;
    int v48;
    int v52;
    int v56;
    int v60;
    int v64;

    r11 = r4;
    r10 = r5;
    r8 = 136;
    r0 = LD32(r11 + 136);
    v36 = r0;
    r2 = LD16((r10 + 14));
    r1 = LD16((r10 + 12));
    v40 = r2 - r1;
    r0 = GCALL6(0x06034CEC, r4, 0, 0, 0, v40, v36);
    c0 = (r0 & r0) == 0;
    r0 = r11;
    if (!(c0)) {
        r1 = LD32(r0 + r8);
        r5 = 28;
        if ((r1 & r1) == 0) {
            ST32(136 + r11, 0);
            r9 = r10 + 14;
            r7 = LD16(r9);
            r8 = r10 + 12;
            r6 = LD32(r10 + 16);
            r5 = LD16(r8);
            r1 = LD32(r10 + 20);
            r0 = GCALL8(0x06015154, r11, r5, r6, r7, r1, (-110), v40, v36);
            r5 = LD16(r8);
            r7 = LD16(r9);
            r8 = r10 + 64;
            r1 = LD32(r8);
            r6 = LD32(r10 + 16);
            v52 = r1 & 255;
            r1 = LD32(r10 + 20);
            r0 = GCALL8(0x060153C8, r11, r5, r6, r7, r1, (-1), 2, v52);
            r1 = LD32(r8);
            if (!((r1 & r1) == 0)) {
                r9 = 0;
                r14 = 0x06036108;
                r13 = 0x06036108;
                r12 = 0;
                r8 = 4;
                do {
                    r7 = LD16((r10 + 14));
                    r1 = LD16(r8 + r14);
                    r6 = LD32(r10 + 16);
                    r7 = r7 + r1;
                    r1 = LD16((r13 + 2));
                    r6 = r6 + r1;
                    r5 = LD16((r10 + 12));
                    r1 = LD16(r12 + r14);
                    r2 = LD16(((r8 + r14) + 2));
                    r5 = r5 + r1;
                    r1 = LD32(r10 + 20);
                    r0 = GCALL8(0x06014C4C, r11, r5, r6, r7, (r1 + r2), 0, v40, v36);
                    r13 = r13 + 8;
                    r12 = r12 + 8;
                    r9 = r9 + 1;
                    r8 = r8 + 8;
                } while (AGAIN(!(r9 > 2)));
                r9 = 0;
                r14 = 0x06036120;
                r13 = 0x06036120;
                r12 = 0;
                r8 = 4;
                do {
                    r7 = LD16((r10 + 12));
                    r1 = LD16(r8 + r14);
                    r6 = LD32(r10 + 16);
                    r7 = r7 + r1;
                    r1 = LD16((r13 + 2));
                    r6 = r6 + r1;
                    r5 = LD16((r10 + 14));
                    r1 = LD16(r12 + r14);
                    r2 = LD16(((r8 + r14) + 2));
                    r5 = r5 + r1;
                    r1 = LD32(r10 + 20);
                    r0 = GCALL8(0x06014C4C, r11, r5, r6, r7, (r1 + r2), 0, v40, v36);
                    r13 = r13 + 8;
                    r12 = r12 + 8;
                    r9 = r9 + 1;
                    r8 = r8 + 8;
                } while (AGAIN(!(r9 > 2)));
            }
            ST32(r11 + 136, v36);
            r0 = v40;
        } else {
            r0 = GCALL6(0x06015D00, r11, r5, 0, 0, v40, v36);
            c2 = (r0 & r0) == 0;
            r0 = r11;
            if (c2) {
                r0 = -1;
            } else {
                r6 = 152;
                r2 = LD32(r0 + 152);
                ST32(r2, 9);
                ST32(r2 + 4, 0);
                ST32(r2 + 24, r10);
                r1 = LD32(r10 + 16);
                ST32(r2 + 12, r1);
                r1 = LD32(r10 + 20);
                r7 = 148;
                ST32(r2 + 16, r1);
                r1 = LD32(r0 + 148);
                if (!((r1 & r1) == 0)) {
                    ST32(r1, r2);
                }
                r0 = r11;
                ST32(r0 + r7, (r2 + 4));
                r1 = LD32(r0 + r6);
                ST32(r0 + r6, (r1 + 28));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                ST32((r10 + 92), r2);
                ST32(136 + r11, 0);
                r9 = r10 + 14;
                r7 = LD16(r9);
                r8 = r10 + 12;
                r6 = LD32(r10 + 16);
                r5 = LD16(r8);
                r1 = LD32(r10 + 20);
                r0 = GCALL8(0x06015154, r11, r5, r6, r7, r1, (-110), v40, v36);
                r5 = LD16(r8);
                r7 = LD16(r9);
                r8 = r10 + 64;
                r1 = LD32(r8);
                r6 = LD32(r10 + 16);
                v52 = r1 & 255;
                r1 = LD32(r10 + 20);
                r0 = GCALL8(0x060153C8, r11, r5, r6, r7, r1, (-1), 2, v52);
                r1 = LD32(r8);
                if (!((r1 & r1) == 0)) {
                    r9 = 0;
                    r14 = 0x06036108;
                    r13 = 0x06036108;
                    r12 = 0;
                    r8 = 4;
                    do {
                        r7 = LD16((r10 + 14));
                        r1 = LD16(r8 + r14);
                        r6 = LD32(r10 + 16);
                        r7 = r7 + r1;
                        r1 = LD16((r13 + 2));
                        r6 = r6 + r1;
                        r5 = LD16((r10 + 12));
                        r1 = LD16(r12 + r14);
                        r2 = LD16(((r8 + r14) + 2));
                        r5 = r5 + r1;
                        r1 = LD32(r10 + 20);
                        r0 = GCALL8(0x06014C4C, r11, r5, r6, r7, (r1 + r2), 0, v40, v36);
                        r13 = r13 + 8;
                        r12 = r12 + 8;
                        r9 = r9 + 1;
                        r8 = r8 + 8;
                    } while (AGAIN(!(r9 > 2)));
                    r9 = 0;
                    r14 = 0x06036120;
                    r13 = 0x06036120;
                    r12 = 0;
                    r8 = 4;
                    do {
                        r7 = LD16((r10 + 12));
                        r1 = LD16(r8 + r14);
                        r6 = LD32(r10 + 16);
                        r7 = r7 + r1;
                        r1 = LD16((r13 + 2));
                        r6 = r6 + r1;
                        r5 = LD16((r10 + 14));
                        r1 = LD16(r12 + r14);
                        r2 = LD16(((r8 + r14) + 2));
                        r5 = r5 + r1;
                        r1 = LD32(r10 + 20);
                        r0 = GCALL8(0x06014C4C, r11, r5, r6, r7, (r1 + r2), 0, v40, v36);
                        r13 = r13 + 8;
                        r12 = r12 + 8;
                        r9 = r9 + 1;
                        r8 = r8 + 8;
                    } while (AGAIN(!(r9 > 2)));
                }
                ST32(r11 + 136, v36);
                r0 = v40;
            }
        }
    } else {
        r1 = LD32(r11 + 8);
        ST32(r11 + 8, (r1 + v40));
        ST32(r11 + 136, v36);
        r0 = v40;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036310(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r14, c1, c5;
    int v36;
    int v40;
    int v44;

    r8 = r4;
    r9 = r5;
    r11 = 136;
    r0 = LD32(r8 + 136);
    v36 = r0;
    r2 = LD16((r9 + 14));
    r1 = LD16((r9 + 12));
    r14 = r2 - r1;
    r1 = LD32(r9 + 20);
    r2 = LD32(r9 + 16);
    r10 = ((r1 - r2) + ((int)((unsigned)(r1 - r2) >> 31))) >> 1;
    r0 = GCALL5(0x06034CEC, r4, 0, 0, 0, v36);
    c1 = (r0 & r0) == 0;
    r0 = r8;
    if (c1) {
        ST32(r8 + 136, v36);
        r0 = r14;
    } else {
        r1 = LD32(r0 + r11);
        if ((r1 & r1) == 0) {
            r12 = 0;
            ST32(r8 + 136, 0);
            r11 = r9 + 12;
            r6 = LD32(r9 + 16);
            r5 = LD16(r11);
            r0 = GCALL6(0x06014FE4, r8, (r5 + r10), (r6 + r10), r10, 0, v36);
            r6 = LD32(r9 + 16);
            r5 = LD16(r11);
            r0 = GCALL7(0x06014E74, r8, (r5 + r10), (r6 + r10), (r10 - 2), (-1), 0, v36);
            r1 = LD32((r9 + 64));
            if (!((r1 & r1) == 0)) {
                r6 = LD32(r9 + 16);
                r5 = LD16(r11);
                r0 = GCALL6(0x06014E74, r8, (r5 + r10), (r6 + r10), (r10 - 4), r12, v36);
            }
            ST32(r8 + 136, v36);
            r0 = r14;
        } else {
            r1 = LD32(0x10C8 + r8);
            if ((r1 & r1) == 0) {
                r0 = GCALL5(0x06015D00, r8, 28, 0, 0, v36);
                c5 = (r0 & r0) == 0;
                r0 = r8;
                if (c5) {
                    r0 = -1;
                } else {
                    r3 = 152;
                    r2 = LD32(r0 + 152);
                    ST32(r2, 10);
                    ST32(r2 + 4, 0);
                    ST32(r2 + 24, r9);
                    r1 = LD32(r9 + 16);
                    ST32(r2 + 12, r1);
                    r1 = LD32(r9 + 20);
                    r7 = 148;
                    ST32(r2 + 16, r1);
                    r1 = LD32(r0 + 148);
                    if (!((r1 & r1) == 0)) {
                        ST32(r1, r2);
                    }
                    r0 = r8;
                    ST32(r0 + r7, (r2 + 4));
                    r1 = LD32(r0 + r3);
                    ST32(r0 + r3, (r1 + 28));
                    r1 = LD32(r0 + 164);
                    ST32(r0 + 164, (r1 + 1));
                    ST32((r9 + 92), r2);
                    r12 = 0;
                    ST32(r8 + 136, 0);
                    r11 = r9 + 12;
                    r6 = LD32(r9 + 16);
                    r5 = LD16(r11);
                    r0 = GCALL6(0x06014FE4, r8, (r5 + r10), (r6 + r10), r10, 0, v36);
                    r6 = LD32(r9 + 16);
                    r5 = LD16(r11);
                    r0 = GCALL7(0x06014E74, r8, (r5 + r10), (r6 + r10), (r10 - 2), (-1), 0, v36);
                    r1 = LD32((r9 + 64));
                    if (!((r1 & r1) == 0)) {
                        r6 = LD32(r9 + 16);
                        r5 = LD16(r11);
                        r0 = GCALL6(0x06014E74, r8, (r5 + r10), (r6 + r10), (r10 - 4), r12, v36);
                    }
                    ST32(r8 + 136, v36);
                    r0 = r14;
                }
            } else {
                r0 = LD32(0x10CC + r8);
                if (!(r0 == 3)) {
                    r12 = 0;
                    ST32(r8 + 136, 0);
                    r11 = r9 + 12;
                    r6 = LD32(r9 + 16);
                    r5 = LD16(r11);
                    r0 = GCALL6(0x06014FE4, r8, (r5 + r10), (r6 + r10), r10, 0, v36);
                    r6 = LD32(r9 + 16);
                    r5 = LD16(r11);
                    r0 = GCALL7(0x06014E74, r8, (r5 + r10), (r6 + r10), (r10 - 2), (-1), 0, v36);
                    r1 = LD32((r9 + 64));
                    if (!((r1 & r1) == 0)) {
                        r6 = LD32(r9 + 16);
                        r5 = LD16(r11);
                        r0 = GCALL6(0x06014E74, r8, (r5 + r10), (r6 + r10), (r10 - 4), r12, v36);
                    }
                    ST32(r8 + 136, v36);
                    r0 = r14;
                } else {
                    r0 = GCALL5(0x06015D00, r8, 28, 0, 0, v36);
                    c5 = (r0 & r0) == 0;
                    r0 = r8;
                    if (c5) {
                        r0 = -1;
                    } else {
                        r3 = 152;
                        r2 = LD32(r0 + 152);
                        ST32(r2, 10);
                        ST32(r2 + 4, 0);
                        ST32(r2 + 24, r9);
                        r1 = LD32(r9 + 16);
                        ST32(r2 + 12, r1);
                        r1 = LD32(r9 + 20);
                        r7 = 148;
                        ST32(r2 + 16, r1);
                        r1 = LD32(r0 + 148);
                        if (!((r1 & r1) == 0)) {
                            ST32(r1, r2);
                        }
                        r0 = r8;
                        ST32(r0 + r7, (r2 + 4));
                        r1 = LD32(r0 + r3);
                        ST32(r0 + r3, (r1 + 28));
                        r1 = LD32(r0 + 164);
                        ST32(r0 + 164, (r1 + 1));
                        ST32((r9 + 92), r2);
                        r12 = 0;
                        ST32(r8 + 136, 0);
                        r11 = r9 + 12;
                        r6 = LD32(r9 + 16);
                        r5 = LD16(r11);
                        r0 = GCALL6(0x06014FE4, r8, (r5 + r10), (r6 + r10), r10, 0, v36);
                        r6 = LD32(r9 + 16);
                        r5 = LD16(r11);
                        r0 = GCALL7(0x06014E74, r8, (r5 + r10), (r6 + r10), (r10 - 2), (-1), 0, v36);
                        r1 = LD32((r9 + 64));
                        if (!((r1 & r1) == 0)) {
                            r6 = LD32(r9 + 16);
                            r5 = LD16(r11);
                            r0 = GCALL6(0x06014E74, r8, (r5 + r10), (r6 + r10), (r10 - 4), r12, v36);
                        }
                        ST32(r8 + 136, v36);
                        r0 = r14;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036454(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14, c2, c4, c7;
    FRAME(sp, 60);

    r8 = r4;
    r9 = r5;
    r10 = 136;
    r0 = LD32(r8 + 136);
    ST32(sp - 40, r0);
    if (!((r8 & r8) == 0)) {
        r6 = sp - 52;
        if (!((r9 & r9) == 0)) {
            r0 = GCALL3(0x060350C4, r8, (sp - 48), (r6 + 8));
            r13 = r0;
            r0 = GCALL2(0x06035068, r8, (sp - 52));
            r14 = LD32(r9 + 52);
            r0 = GCALL1(0x06034CEC, r8);
            c2 = (r0 & r0) == 0;
            r0 = r8;
            if (c2) {
                r11 = LD32(sp - 40);
                ST32(r8 + 136, r11);
                r0 = GCALL2(0x060350B0, r8, (sp - 52));
                r0 = 1;
            } else {
                r1 = LD32(r0 + r10);
                r5 = 28;
                if ((r1 & r1) == 0) {
                    ST32(136 + r8, 0);
                    r1 = LD32(140 + r8);
                    r12 = r9;
                    if ((r1 & r1) == 0) {
                        r12 = r12 + 14;
                        r11 = r9 + 12;
                        r7 = LD16(r12);
                        r6 = LD32(r9 + 16);
                        r10 = r9 + 64;
                        ST32(sp - 36, r11);
                        r1 = LD32(r10);
                        r5 = LD16(r11);
                        c7 = (r1 & r1) == 0;
                        r1 = -110;
                        if (!(c7)) {
                            r1 = -1;
                        }
                        ST32((sp - 56), r1);
                        r1 = LD32(r9 + 20);
                        ST32((sp - 60), r1);
                        r0 = GCALL6(0x06015154, r8, r5, r6, r7, LD32((sp - 60)), LD32((sp - 56)));
                        r7 = LD16(r12);
                        r6 = LD32(r9 + 16);
                        r11 = LD32(sp - 36);
                        r1 = LD32(r10);
                        r5 = LD16(r11);
                        ST32((sp - 64), (r1 & 255));
                        ST32((sp - 68), 4);
                        ST32((sp - 72), -1);
                        r1 = LD32(r9 + 20);
                        ST32((sp - 76), r1);
                        r0 = GCALL8(0x060153C8, r8, r5, r6, r7, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                    }
                    r0 = GCALL1(0x0607507C, r14);
                    r1 = LD32(r13);
                    ST32((sp - 56), r1);
                    r1 = LD32(0x10B8 + r8);
                    ST32((sp - 60), r1);
                    r1 = LD32(r13 + 32);
                    ST32((sp - 64), (r1 + 4));
                    r1 = LD32(r9 + 16);
                    ST32((sp - 68), (r1 + 2));
                    r1 = LD16((r9 + 12));
                    r2 = LD32(sp - 48);
                    ST32((sp - 72), (r1 + r2));
                    r0 = GCALL8(0x06014880, r8, r14, 0, (r0 - 1), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                    r11 = LD32(sp - 40);
                    ST32(r8 + 136, r11);
                    r0 = GCALL2(0x060350B0, r8, (sp - 52));
                    r0 = 1;
                } else {
                    r0 = GCALL2(0x06015D00, r8, r5);
                    c4 = (r0 & r0) == 0;
                    r0 = r8;
                    if (c4) {
                        r0 = 0;
                    } else {
                        r3 = 152;
                        r2 = LD32(r0 + 152);
                        ST32(r2, 11);
                        ST32(r2 + 4, 0);
                        ST32(r2 + 24, r9);
                        r1 = LD32(r9 + 16);
                        ST32(r2 + 12, r1);
                        r1 = LD32(r9 + 20);
                        r7 = 148;
                        ST32(r2 + 16, r1);
                        r1 = LD32(r0 + 148);
                        if (!((r1 & r1) == 0)) {
                            ST32(r1, r2);
                        }
                        r0 = r8;
                        ST32(r0 + r7, (r2 + 4));
                        r1 = LD32(r0 + r3);
                        ST32(r0 + r3, (r1 + 28));
                        r1 = LD32(r0 + 164);
                        ST32(r0 + 164, (r1 + 1));
                        ST32((r9 + 92), r2);
                        ST32(136 + r8, 0);
                        r1 = LD32(140 + r8);
                        r12 = r9;
                        if ((r1 & r1) == 0) {
                            r12 = r12 + 14;
                            r11 = r9 + 12;
                            r7 = LD16(r12);
                            r6 = LD32(r9 + 16);
                            r10 = r9 + 64;
                            ST32(sp - 36, r11);
                            r1 = LD32(r10);
                            r5 = LD16(r11);
                            c7 = (r1 & r1) == 0;
                            r1 = -110;
                            if (!(c7)) {
                                r1 = -1;
                            }
                            ST32((sp - 56), r1);
                            r1 = LD32(r9 + 20);
                            ST32((sp - 60), r1);
                            r0 = GCALL6(0x06015154, r8, r5, r6, r7, LD32((sp - 60)), LD32((sp - 56)));
                            r7 = LD16(r12);
                            r6 = LD32(r9 + 16);
                            r11 = LD32(sp - 36);
                            r1 = LD32(r10);
                            r5 = LD16(r11);
                            ST32((sp - 64), (r1 & 255));
                            ST32((sp - 68), 4);
                            ST32((sp - 72), -1);
                            r1 = LD32(r9 + 20);
                            ST32((sp - 76), r1);
                            r0 = GCALL8(0x060153C8, r8, r5, r6, r7, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                        }
                        r0 = GCALL1(0x0607507C, r14);
                        r1 = LD32(r13);
                        ST32((sp - 56), r1);
                        r1 = LD32(0x10B8 + r8);
                        ST32((sp - 60), r1);
                        r1 = LD32(r13 + 32);
                        ST32((sp - 64), (r1 + 4));
                        r1 = LD32(r9 + 16);
                        ST32((sp - 68), (r1 + 2));
                        r1 = LD16((r9 + 12));
                        r2 = LD32(sp - 48);
                        ST32((sp - 72), (r1 + r2));
                        r0 = GCALL8(0x06014880, r8, r14, 0, (r0 - 1), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                        r11 = LD32(sp - 40);
                        ST32(r8 + 136, r11);
                        r0 = GCALL2(0x060350B0, r8, (sp - 52));
                        r0 = 1;
                    }
                }
            }
        } else {
            r0 = 1;
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060368C4(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, c4;
    int v24;

    r8 = r4;
    r10 = r5;
    r9 = LD32((r10 + 84));
    r0 = GCALL1(0x06034CEC, r4);
    r11 = r10;
    if (!((r0 & r0) == 0)) {
        r11 = r11 + 12;
        r7 = LD32(r10 + 16);
        r6 = LD16(r11);
        r0 = GCALL5(0x060159A4, r8, r9, r6, r7, 0);
        r5 = LD32(r9 + 4);
        r0 = GCALL5(0x06025DFC, r8, r5, 0, 0, 0);
        r9 = r0;
        r1 = LD32(0x20000014 + r9);
        if ((r1 & r1) == 0) {
            r1 = LD32(r8 + 16);
            r7 = LD32(r10 + 16);
            r3 = r1 + r7;
            r1 = LD32(200 + r9);
            r2 = r3 + r1;
            r1 = LD32(r8 + 28);
            if (r2 >= r1) {
                r1 = LD32(r8 + 24);
                if (!(r3 >= r1)) {
                    r1 = LD32(0x10C8 + r8);
                    c4 = (r1 & r1) == 0;
                    r1 = 2;
                    if (c4) {
                        r6 = LD16(r11);
                        r0 = GCALL4(0x06015A5C, r8, r9, r6, r7);
                    } else {
                        r2 = LD32(0x10CC + r8);
                        if (r2 > r1) {
                            r6 = LD16(r11);
                            r0 = GCALL4(0x06015A5C, r8, r9, r6, r7);
                        }
                    }
                }
            }
        }
    }
    r0 = LD32(196 + r9);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036D34(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = r5 + 64;
    r1 = LD32(r8);
    r0 = 1;
    if ((r1 & r1) == 0) {
        r0 = GCALL4(0x06033E0C, 0, r5, r6, r7);
        ST32(r8, 1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06037298(int r4)
{
    int r1;

    r1 = 0;
    if (!((r4 & r4) == 0)) {
        do {
            ST32(r4, r1);
            r4 = LD32(r4 + 24);
        } while (AGAIN(!((r4 & r4) == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060378C8(int r4)
{
    int r0, r1, r2, r3, r7, r8, r9;

    r8 = r4;
    r9 = LD32(r8 + 40);
    r0 = GCALL1(0x060426AC, r9);
    r3 = LD16((r8 + 12));
    ST16(0x06088008, r3);
    r7 = LD32(r8 + 16);
    ST16(0x0608800A, r7);
    r1 = LD32(r9 + 28);
    r2 = LD32(r9 + 44);
    r1 = r1 - r2;
    r2 = LD16((r8 + 30));
    ST16(0x06088008, (r3 + ((r1 + 1) * r2)));
    r2 = LD32(r9 + 24);
    r1 = LD32(r9 + 40);
    r2 = r2 - r1;
    r1 = LD16((r8 + 28));
    ST16(0x0608800A, (r7 + (r2 * r1)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037DBC(int r4, int r5)
{
    int r1, r2;

    r2 = LD32(r5 + 44);
    if (!((r2 & r2) == 0)) {
        do {
            r1 = LD32(r2 + 4);
            ST32(r2, r1);
            r2 = LD32(r2 + 24);
        } while (AGAIN(!((r2 & r2) == 0)));
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037DD0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = r5;
    r4 = LD32(r8 + 40);
    r1 = r8;
    if (!((r4 & r4) == 0)) {
        r0 = GCALL4(0x06042468, r4, r5, r6, r7);
        ST32(r8 + 40, 0);
        r1 = r8;
    }
    r7 = LD16((r1 + 44));
    r6 = LD16((r8 + 46));
    r1 = LD32(r8 + 48);
    r5 = -1;
    if (!((r1 & r1) == 0)) {
        r5 = r7;
    }
    r4 = LD32(r8 + 36);
    r0 = GCALL4(0x060419E0, r4, r5, r6, r7);
    ST32(r8 + 40, r0);
    r1 = LD32(0x06088028);
    r0 = 1;
    if (r8 == r1) {
        ST16(0x06088010, 0);
        r1 = LD32(0x0608800C);
        ST8(r1, 0);
        ST16(0x06088012, 0);
        r1 = LD16(0x06087FF8);
        ST16(0x06088000, r1);
        r1 = LD16(0x06087FFA);
        ST16(0x06088002, r1);
        ST8(0x06088014, 0);
        ST16(0x06088018, 0);
        r1 = LD32(r8 + 40);
        ST32(r1 + 24, 0);
        r1 = LD32(r8 + 40);
        ST32(r1 + 28, 0);
        r0 = GCALL1(0x060378C8, r8);
        r0 = 1;
    }
    ST32(r8 + 24, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060387C8(int r4)
{
    int r0, r1, r3;

    r0 = r4 & 15;
    r3 = r0;
    if ((unsigned)(r0 & 255) > (unsigned)9) {
        r1 = r3;
        if (!((unsigned)((r0 - 10) & 255) > (unsigned)5)) {
            return (signed char)(r1 + 55);
        } else {
            return 48;
        }
    } else {
        return r0 | 48;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038938(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10;

    r10 = r4;
    r9 = r5;
    r4 = 0;
    if (!((r9 & r9) == 0)) {
        r8 = r9;
        while (1) {
            r2 = LD8(r8);
            r0 = r2 & 255;
            if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                POLL();
                if (!(r0 == 38)) {
                    r4 = r4 + 1;
                    r8 = r8 + 1;
                    continue;
                } else {
                    r4 = r4 + 3;
                    r8 = r8 + 1;
                    continue;
                }
            } else {
                break;
            }
        }
        r1 = 0;
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x060287D0, (r4 + 1));
            ST32(r10, r0);
            if (!((r0 & r0) == 0)) {
                r8 = r9;
                r3 = r0;
                ST8(r3, 0);
                r2 = LD8(r8);
                r1 = 0;
                if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                    r9 = 0x060389D4;
                    r0 = r2 & 255;
                    do {
                        r5 = r0;
                        if (!(r0 == 38)) {
                            ST8(r3, r2);
                            r3 = r3 + 1;
                        } else {
                            r0 = GCALL2(r9, r3, r5);
                            r3 = r0;
                        }
                        r8 = r8 + 1;
                        r2 = LD8(r8);
                        r0 = r2 & 255;
                    } while (AGAIN(!(((r2 & 255) & (r2 & 255)) == 0)));
                    r1 = 0;
                }
                ST8(r3, r1);
                r0 = 1;
            } else {
                r0 = 0;
            }
        } else {
            ST32(r10, r1);
            r0 = 1;
        }
        return r0;
    } else {
        ST32(r10, r4);
        r0 = 0;
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060389D4(int r4, int r5)
{
    int r0, r8, r10;

    r8 = r5 & 255;
    ST8(r4, 37);
    r10 = r4 + 1;
    r0 = GCALL1(0x060387C8, ((int)((unsigned)((int)((unsigned)r8 >> 2)) >> 2)));
    ST8(r10, r0);
    r10 = r10 + 1;
    r0 = GCALL1(0x060387C8, ((signed char)r8));
    ST8(r10, r0);
    return r10 + 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038A10(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;

    r0 = LD32(0x060759B4);
    r3 = r4 + 12;
    r1 = LD16(r3);
    ST16(0x06087FD4, r1);
    r1 = LD32(r4 + 16);
    ST32(0x06087FE0, r1);
    r1 = LD16((r4 + 14));
    r2 = LD16(r3);
    ST16(0x06087FD6, (r1 - r2));
    r1 = LD32(r4 + 20);
    r2 = LD32(r4 + 16);
    ST32(0x06087FE4, (r1 - r2));
    r1 = LD16(r3);
    ST16(0x06087FD8, (r5 - r1));
    r1 = LD32(r4 + 16);
    ST32(0x06087FE8, (r6 - (r1 - r0)));
    ST8(0x06087FDA, 0);
    ST8(0x06087FDB, 0);
    ST32(0x06087FEC, -1);
    ST32(0x06087FF0, r4);
    ST32(0x06087FD0, 0);
    ST32(0x06087FF4, 0);
    return 0x06087FD0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038D40(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10;

    r1 = LD32(0x1DF0 + r4);
    r7 = 0;
    r6 = 1;
    r9 = 0x1DEC;
    r5 = 0x1DF0;
    r10 = 148;
    r8 = 0x5D4;
    ST32(r1, 1);
    r0 = r4;
    do {
        r1 = LD32(r0 + r9);
        r3 = r6 << 2;
        r1 = LD32(r3 + r1);
        r0 = r4;
        if (!((r1 & r1) == 0)) {
            r1 = LD32(r0 + r5);
            ST32((r3 + r1) + 0x124, r7);
            r1 = LD32(r4 + r5);
            r2 = r3 + r1;
            r1 = LD32(((r7 << 2) + r4) + r8);
            ST32(r2 + r10, r1);
            r1 = LD32(r4 + r9);
            r1 = LD32(r3 + r1);
            r7 = (r7 - 1) + r1;
            r1 = LD32(r4 + r5);
            r2 = r3 + r1;
            r1 = LD32(((r7 << 2) + r4) + r8);
            ST32(r2 + 4, r1);
            r1 = LD32(r4 + r5);
            r7 = r7 + 1;
            ST32(r1, r6);
        } else {
            r1 = LD32(r0 + r5);
            ST32((r3 + r1) + 4, -1);
        }
        r6 = r6 + 1;
        r0 = r4;
    } while (AGAIN(!(r6 > 16)));
    r1 = LD32(0x1DF0 + r4);
    r2 = LD32(r1);
    r2 = (r2 << 2) + r1;
    r1 = LD32(r2 + 4);
    ST32(r2 + 4, (r1 + 1));
    return 0x1DF0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038F58(int r4)
{
    int r0, r2, r8, r9;

    r8 = r4;
    r9 = 0x06028380;
    r0 = GCALL2(0x06028380, 0x494, 7);
    r2 = r0;
    ST32(r8 + 0x1DEC, r2);
    if ((r2 & r2) == 0) {
        r0 = -3;
    } else {
        r0 = GCALL2(r9, 0x1B4, 7);
        r2 = r0;
        ST32(r8 + 0x1DF0, r2);
        if ((r2 & r2) == 0) {
            r0 = -3;
        } else {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038FA0(int r4, int r5)
{
    int r0, r1;

    r5 = (r5 << 2) + r4;
    r1 = LD32(r4 + 0x1DEC);
    ST32(r5 + 0x108, r1);
    r1 = LD32(r4 + 0x1DF0);
    r0 = r5;
    ST32(r0 + 200, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038FC8(int r4, int r5)
{
    int r0, r1;

    r5 = (r5 << 2) + r4;
    r1 = LD32(r4 + 0x1DEC);
    ST32(r5 + 0x18C, r1);
    r1 = LD32(r4 + 0x1DF0);
    r0 = r5;
    ST32(r0 + 0x14C, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038FF0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12;

    r10 = r4;
    r11 = r5;
    r6 = (r6 << 2) + r10;
    r1 = LD32(r6 + 0x108);
    ST32(r10 + 0x1DEC, r1);
    r1 = LD32(r6 + 200);
    ST32(r10 + 0x1DF0, r1);
    r2 = r11 + 4;
    r1 = 0x100 + r11;
    r3 = 0;
    if (!((unsigned)r2 >= (unsigned)r1)) {
        do {
            ST32(r2, r3);
            r2 = r2 + 4;
        } while (AGAIN(!((unsigned)r2 >= (unsigned)r1)));
    }
    r9 = 1;
    r12 = 63;
    while (1) {
        r0 = GCALL1(0x06038EA0, r10);
        r2 = r0;
        r0 = 0x1DE8;
        r1 = LD32(0x1DE8 + r10);
        r8 = 15;
        if (!((r1 & r1) == 0)) {
            break;
        } else {
            r8 = r8 & r2;
            r0 = (((r2 >> 1) >> 1) >> 1) >> 1;
            r1 = 15 & r0;
            if ((r8 & r8) == 0) {
                r0 = r1;
                r9 = r9 + 16;
                if (!(r0 == 15)) {
                    break;
                } else {
                    if (!(r9 > r12)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
            } else {
                r9 = r9 + r1;
                r5 = r8;
                if (r9 > r12) {
                    break;
                } else {
                    r0 = GCALL2(0x06039C1C, r10, r5);
                    r7 = r0;
                    r3 = r9 << 2;
                    ST32(r3 + r11, r7);
                    r0 = (r8 - 1) << 2;
                    r1 = LD32(r0 + 0x0607818C);
                    if (((r1 & r7) & (r1 & r7)) == 0) {
                        r1 = LD32(r0 + 0x0607813C);
                        r0 = r3;
                        ST32(r0 + r11, ((r1 | r7) + 1));
                    }
                    r9 = r9 + 1;
                    if (!(r9 > r12)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060390CC(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11;

    r10 = r4;
    r11 = 0x1DF4;
    r1 = LD32(r10 + 0x1DF4);
    r9 = 0;
    if (!((r1 & r1) == 0)) {
        r9 = LD32(r1);
    }
    r2 = (r5 << 2) + r10;
    r1 = LD32(r2 + 0x18C);
    ST32(r10 + 0x1DEC, r1);
    r1 = LD32(r2 + 0x14C);
    ST32(r10 + 0x1DF0, r1);
    r0 = GCALL1(0x06038EA0, r10);
    r8 = r0;
    r1 = LD32(r10 + 0x1DE8);
    r0 = 0;
    if ((r1 & r1) == 0) {
        r5 = r8;
        if (!((r8 & r8) == 0)) {
            r0 = GCALL2(0x06039C1C, r10, r5);
            r9 = r0;
            r0 = (r8 - 1) << 2;
            r1 = LD32(r0 + 0x0607818C);
            if (((r1 & r9) & (r1 & r9)) == 0) {
                r1 = LD32(r0 + 0x0607813C);
                r9 = (r9 | r1) + 1;
            }
            r4 = LD32(r10 + r11);
            if (!((r4 & r4) == 0)) {
                r1 = LD32(r4);
                r9 = r9 + r1;
                ST32(r4, r9);
            }
        }
        r0 = r9;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039178(int r4)
{
    int r0, r1, r2, r3, r7, c1;

    r0 = 0x1DE0;
    r1 = LD32(0x1DE0 + r4);
    r1 = LD32(r1);
    r3 = 0;
    r7 = 0;
    if (!(0 >= r1)) {
        r1 = r3;
        do {
            r2 = LD32(r0 + r4);
            ST32(((r1 << 2) + r2) + 4, r7);
            r1 = LD32(r0 + r4);
            r1 = LD32(r1);
            r3 = r3 + 1;
            c1 = r3 >= r1;
            r1 = r3;
        } while (AGAIN(!(c1)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060391A4(int r4, int r5)
{
    int r0, r1;

    r0 = r4;
    r1 = LD32(r0 + 0x1DE0);
    ST32(r0 + 0x1DF4, (r1 + ((r5 << 2) + 4)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060391BC(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12;

    r10 = r4;
    ST8((r10 + 40), r5);
    r0 = GCALL1(0x06039B40, r4);
    r11 = r0;
    r0 = GCALL1(0x06039B14, r10);
    ST8((r10 + 42), r0);
    r0 = GCALL1(0x06039B40, r10);
    ST32(r10 + 4, r0);
    r0 = GCALL1(0x06039B40, r10);
    ST32(r10, r0);
    r0 = GCALL1(0x06039B14, r10);
    ST32(r10 + 16, r0);
    r5 = r11 - 8;
    r9 = 0;
    r6 = 255;
    r7 = 0x9DC;
    r3 = 0xDDC;
    r4 = 0x11DC;
    r2 = 0;
    r1 = r10;
    do {
        r0 = r1;
        ST32(r0 + r4, r2);
        ST32(r0 + r3, r2);
        ST32(r0 + r7, r2);
        r9 = r9 + 1;
        r1 = r1 + 4;
    } while (AGAIN(!(r9 > r6)));
    r2 = LD32(r10 + 16);
    r9 = 0;
    if (r5 == ((r2 + r2) + r2)) {
        if (!(r9 >= r2)) {
            r11 = 0x06039B14;
            r12 = 0x9DC;
            do {
                r0 = GCALL1(r11, r10);
                r8 = r0;
                r0 = GCALL1(r11, r10);
                r2 = r0;
                r8 = (r8 << 2) + r10;
                ST32(r8 + r12, (((((r2 >> 1) >> 1) >> 1) >> 1) & 15));
                ST32(r8 + 0xDDC, (r2 & 15));
                r0 = GCALL1(r11, r10);
                ST32(r8 + 0x11DC, r0);
                r1 = LD32(r10 + 16);
                r9 = r9 + 1;
            } while (AGAIN(!(r9 >= r1)));
        }
        r0 = GCALL1(0x0603997C, r10);
    } else {
        r0 = -303;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603941C(int r4)
{
    int r0, r1, r5, r8, r9, r10, r11, r12, r13, c1;
    FRAME(sp, 32);

    r9 = r4;
    r0 = GCALL1(0x06039B40, r4);
    r11 = r0 - 2;
    r0 = 0;
    if (r11 > 0) {
        r13 = 196;
        r12 = 0x148;
        while (1) {
            r0 = GCALL1(0x06039B14, r9);
            r8 = r0;
            r11 = r11 - 1;
            r10 = 15 & ((((r8 >> 1) >> 1) >> 1) >> 1);
            r8 = r8 & 15;
            r0 = GCALL2(0x06038DF4, r9, (sp - 32));
            c1 = (r0 & r0) == 0;
            r0 = -3;
            if (!(c1)) {
                break;
            } else {
                r5 = r8;
                if ((r10 & r10) == 0) {
                    r0 = GCALL2(0x06038FC8, r9, r5);
                    r0 = r9;
                    r1 = LD32(r0 + r12);
                    r5 = r8 + 1;
                    if (!(r1 >= r5)) {
                        r1 = r5;
                        r0 = r9;
                    }
                    ST32(r0 + r12, r1);
                } else {
                    r0 = GCALL2(0x06038FA0, r9, r5);
                    r0 = r9;
                    r1 = LD32(r0 + r13);
                    r5 = r8 + 1;
                    if (!(r1 >= r5)) {
                        r1 = r5;
                        r0 = r9;
                    }
                    ST32(r0 + r13, r1);
                }
                r1 = LD32(sp - 32);
                r11 = (r11 - 16) - r1;
                r0 = 0;
                if (r11 > 0) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060394E0(int r4)
{
    int r0, r8, r9;

    r9 = 0x06039B40;
    r8 = r4;
    r0 = GCALL1(0x06039B40, r4);
    if (!(r0 == 4)) {
        r0 = -303;
    } else {
        r0 = GCALL1(r9, r8);
        ST8((r8 + 41), r0);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039510(int r4)
{
    int r0, r1, r2, r5, r8, r9, c2;

    r9 = 0x06039B40;
    r8 = r4;
    r0 = GCALL1(0x06039B40, r4);
    if (r0 == 4) {
        r0 = GCALL1(r9, r8);
        ST32(r8 + 4, r0);
        r9 = 0x1DE0;
        r1 = LD32(r8 + 0x1DE0);
        r1 = LD32(r1);
        r0 = 0;
        if (!((r1 & r1) == 0)) {
            r0 = GCALL1(0x0603997C, r8);
            c2 = (r0 & r0) == 0;
            r0 = -1;
            if (c2) {
                r0 = GCALL1(0x060398B0, r8);
                r0 = GCALL1(0x0603A3E8, r8);
                r1 = LD32(r8 + 4);
                r5 = 0;
                if ((r1 & r1) == 0) {
                    ST32(r8 + 60, -1);
                } else {
                    r0 = GCALL2(0x0603AB10, r8, r5);
                    r1 = LD32(r8 + r9);
                    r2 = LD32((r1 + 68));
                    r1 = LD32((r1 + 72));
                    ST32(r8 + 60, (r2 * r1));
                }
                r0 = 0;
            }
        }
    } else {
        r0 = -303;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603970C(int r4)
{
    int r0, r8, r9, r10;

    r8 = r4;
    r0 = GCALL1(0x06039B04, r4);
    r10 = r0;
    r0 = GCALL1(0x06039B40, r8);
    r9 = r0;
    if (r9 > 0xFFBF) {
        r0 = GCALL2(0x06039B0C, r8, r10);
        r0 = r9 & 255;
    } else {
        r0 = GCALL2(0x06039B0C, r8, r10);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603975C(int r4)
{
    int r0, r1, r2, r3, r5, r7, r8, r9, r10, r11, r12, r13, c2, c4;

    r9 = r4;
    r0 = GCALL1(0x06039B40, r4);
    r8 = 0x06039B14;
    r0 = GCALL1(0x06039B14, r9);
    r3 = r0;
    r2 = 0x1DE0;
    r0 = r9;
    r1 = LD32(r0 + 0x1DE0);
    ST32(r1, r3);
    r1 = LD32(r0 + 0x1DE0);
    r1 = LD32(r1);
    r10 = 0;
    if (!(0 >= r1)) {
        r12 = r8;
        r11 = r2;
        r13 = 0x10C;
        do {
            r0 = GCALL1(r12, r9);
            r8 = r10 << 2;
            r1 = LD32(r9 + r11);
            ST32((r8 + r1) + 140, r0);
            r0 = GCALL1(r12, r9);
            r3 = r0;
            r1 = LD32(r9 + r11);
            ST32((r1 + r8) + r13, (((((r3 >> 1) >> 1) >> 1) >> 1) & 15));
            r1 = LD32(r9 + r11);
            ST32((r1 + r8) + 204, (r3 & 15));
            r1 = LD32(r9 + r11);
            r1 = LD32(r1);
            r10 = r10 + 1;
        } while (AGAIN(!(r10 >= r1)));
    }
    r0 = GCALL1(0x06039B14, r9);
    ST8((r9 + 47), r0);
    r0 = GCALL1(0x06039B14, r9);
    ST8((r9 + 48), r0);
    r0 = GCALL1(0x06039B14, r9);
    ST8((r9 + 49), (((((r0 >> 1) >> 1) >> 1) >> 1) & 15));
    ST8((r9 + 50), (r0 & 15));
    r0 = GCALL1(0x0603BAF8, r9);
    c2 = (r0 & r0) == 0;
    r0 = -1;
    if (c2) {
        r0 = GCALL1(0x060398B0, r9);
        r2 = LD8((r9 + 42));
        r7 = 1;
        if (r2 > 8) {
            r7 = 2;
        }
        r0 = GCALL4(0x0603A458, r9, 0, 0, r7);
        c4 = (r0 & r0) == 0;
        r0 = -1;
        if (c4) {
            r1 = LD32(r9 + 4);
            r5 = 0;
            if ((r1 & r1) == 0) {
                ST32(r9 + 60, -1);
            } else {
                r0 = GCALL2(0x0603AB10, r9, r5);
                r1 = LD32(r9 + 0x1DE0);
                r2 = LD32((r1 + 68));
                r1 = LD32((r1 + 72));
                ST32(r9 + 60, (r2 * r1));
            }
            r0 = GCALL1(0x06039178, r9);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039B04(int r4)
{
    int r0;

    r0 = LD32((r4 + 76));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039B0C(int r4, int r5)
{
    ST32((r4 + 76), r5);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039B14(int r4)
{
    int r1, r2, r3, c0;

    r1 = r4 + 76;
    r2 = LD32(r1);
    r2 = r2 + 1;
    ST32(r1, r2);
    r1 = LD32(r4 + 12);
    c0 = r2 > r1;
    r3 = c0;
    if (c0) {
        ST32(0x1DE8 + r4, r3);
        return 0;
    } else {
        r1 = LD32((r4 + 72));
        r1 = LD8(((r1 + r2) - 1));
        return r1 & 255;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039B40(int r4)
{
    int r0, r10;

    r0 = GCALL1(0x06039B14, r4);
    r10 = r0;
    r0 = GCALL1(0x06039B14, r4);
    return r0 | (r10 << 8);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039BC8(int r4)
{
    int r0, r1, r2, r3, r8, r9;

    r8 = r4;
    r9 = r8 + 124;
    r1 = LD32(r9);
    r3 = r8;
    if (!(r1 >= 0)) {
        r0 = GCALL1(0x06039B68, r4);
        ST32((r8 + 116), r0);
        ST32(r9, 7);
        r3 = r8;
    }
    r2 = LD32(r9);
    ST32(r9, (r2 - 1));
    r1 = LD32((r3 + 116));
    r2 = LD32((r2 << 2) + 0x0607818C);
    r0 = 1;
    if (((r1 & r2) & (r1 & r2)) == 0) {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A2DC(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8;

    r3 = 0;
    r5 = 15;
    r6 = 0x1E08;
    r8 = 0x1DE0;
    r1 = LD32((r4 + 116));
    r7 = r4;
    ST32(0x1DF8 + r4, r1);
    r1 = LD32((r4 + 120));
    ST32(0x1DFC + r4, r1);
    r1 = LD32((r4 + 124));
    ST32(0x1E00 + r4, r1);
    r1 = LD32((r4 + 76));
    ST32(0x1E04 + r4, r1);
    do {
        r1 = r3 << 2;
        r3 = r3 + 1;
        r2 = LD32(r4 + r8);
        r0 = r7;
        r1 = LD32((r1 + r2) + 4);
        r7 = r7 + 4;
        ST32(r0 + r6, r1);
    } while (AGAIN(!(r3 > r5)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A338(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8;

    r3 = 0;
    r5 = 15;
    r6 = 0x1DE0;
    r8 = 0x1E08;
    r1 = LD32(0x1DF8 + r4);
    r7 = r4;
    ST32((r4 + 116), r1);
    r1 = LD32(0x1DFC + r4);
    ST32((r4 + 120), r1);
    r1 = LD32(0x1E00 + r4);
    ST32((r4 + 124), r1);
    r1 = LD32(0x1E04 + r4);
    ST32((r4 + 76), r1);
    do {
        r2 = r3 << 2;
        r3 = r3 + 1;
        r1 = LD32(r4 + r6);
        r2 = r2 + r1;
        r0 = r7;
        r1 = LD32(r0 + r8);
        r7 = r7 + 4;
        ST32(r2 + 4, r1);
    } while (AGAIN(!(r3 > r5)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A394(int r4, int r5)
{
    int r0, r8, r9, r10, r11;

    r10 = r4;
    r9 = r5;
    r11 = 0x06028380;
    r0 = GCALL2(0x06028380, 36, 7);
    r8 = r0;
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        ST32(r8 + 4, r9);
        ST32(r8 + 12, 0);
        ST32(r8 + 16, 0);
        ST32(r8 + 8, (r10 * r9));
        r4 = LD32(r8 + 8);
        r0 = GCALL2(r11, (r4 + 1), 7);
        ST32(r8 + 20, r0);
        if ((r0 & r0) == 0) {
            r0 = 0;
        } else {
            ST32(r8 + 24, r0);
            ST32(r8 + 28, r0);
            r0 = r8;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A3E8(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8;

    r0 = r4;
    r1 = LD32(r0 + 0x1DE0);
    r1 = LD32(r1);
    r7 = 0;
    r6 = 0x1DE0;
    if (!(0 >= r1)) {
        r5 = 140;
        r0 = r4;
        r3 = r7;
        do {
            r3 = r3 << 2;
            r1 = LD32(r0 + r6);
            r8 = r3 + r1;
            r2 = LD32((r8 + 76));
            r1 = LD32(r8 + r5);
            r1 = LD32(((r1 << 2) + r4) + 0x15DC);
            ST32(r2 + 28, r1);
            r1 = LD32(r4 + r6);
            r3 = r3 + r1;
            r2 = LD32((r3 + 76));
            r1 = LD32(r3 + r5);
            r1 = LD32(((r1 << 2) + r4) + 0x19DC);
            ST32(r2 + 32, r1);
            r0 = r4;
            r1 = LD32(r0 + r6);
            r1 = LD32(r1);
            r7 = r7 + 1;
            r3 = r7;
        } while (AGAIN(!(r7 >= r1)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A76C(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, r14, c1;
    int v36;

    r11 = r4;
    r12 = r5;
    r1 = LD32(r12 + 24);
    r5 = LD32(r12 + 20);
    r8 = r1 - r5;
    r1 = LD32(r11 + 0x1DE4);
    r4 = LD32(r1 + 44);
    r1 = LD32(r1 + 48);
    r0 = GCALL3(0x0604B358, (r4 + r1), r5, r8);
    r0 = r11;
    r2 = LD32(r0 + 0x1DE4);
    r1 = LD32(r2 + 48);
    ST32(r2 + 48, (r1 + r8));
    if (!((r8 & r8) == 0)) {
        r1 = LD32(r12 + 32);
        r1 = LD32(r1);
        c1 = (r1 & r1) == 0;
        r1 = r11;
        if (c1) {
            ST32((r1 + 88), r8);
            r2 = r11 + 92;
            r1 = LD32(r2);
            ST32(r2, (r1 + 1));
        }
    }
    r1 = LD32(r12);
    r14 = 0;
    if (!((r1 & r1) == 0)) {
        r1 = LD32(0x1DE4 + r11);
        ST32(r1 + 48, r14);
        r1 = LD32(r12 + 32);
        r1 = LD32(r1);
        r0 = r1;
        if (!((r1 & r1) == 0)) {
            r10 = r11;
            if (r0 == 2) {
                r10 = r10 + 92;
                r6 = LD32(r10);
                r9 = r11;
                if (!((r6 & r6) == 0)) {
                    r9 = r9 + 84;
                    r7 = LD32(0x1DDC + r11);
                    r8 = r11 + 88;
                    r1 = LD32(r9);
                    r5 = LD32(r8);
                    r0 = GCALL4(0x0603AE98, r11, r5, r6, (r7 + r1));
                    r1 = LD32((r11 + 80));
                    r2 = LD32(r8);
                    ST32(r9, (r1 + r2));
                    r1 = LD32(r11 + 8);
                    r2 = LD32(r10);
                    ST32(r11 + 8, (r1 + r2));
                    ST32(r10, r14);
                }
            }
        } else {
            r1 = LD32(r12 + 16);
            r2 = LD32(r12 + 12);
            r13 = r11 + 80;
            ST32(r13, (r1 + r2));
            r0 = LD32(r11 + 36);
            r10 = r11;
            if (r0 == 1) {
                r10 = r10 + 84;
                r7 = LD32(0x1DDC + r11);
                r8 = r11 + 92;
                r1 = LD32(r10);
                r6 = LD32(r8);
                r9 = r11 + 88;
                r5 = LD32(r9);
                r7 = r7 + r1;
                r1 = LD32(r11);
                r0 = GCALL5(0x0603B094, r11, r5, r6, r7, r1);
                r1 = LD32(r13);
                r2 = LD32(r9);
                ST32(r10, (r1 + r2));
                r1 = LD32(r11 + 8);
                r2 = LD32(r8);
                ST32(r11 + 8, (r1 + r2));
                ST32(r8, r14);
            }
        }
    }
    r2 = LD32(r12 + 24);
    r1 = LD32(r12 + 20);
    r2 = r2 - r1;
    r1 = LD32(r12 + 12);
    ST32(r12 + 12, (r1 + r2));
    r1 = LD32(r12 + 20);
    ST32(r12 + 24, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603AA44(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, c1;

    r1 = LD32(r4 + 0x1DE4);
    r1 = LD32(r1 + 24);
    r6 = 0;
    r5 = 0x1DE4;
    if (!(0 >= ((r1 << 2) + (r1 << 2)))) {
        r8 = 0;
        r0 = r4;
        r3 = r6;
        do {
            r1 = LD32(r0 + r5);
            r3 = r3 << 2;
            r1 = LD32(r1 + 40);
            r1 = LD32(r3 + r1);
            r2 = LD32(r1 + 20);
            ST32(r1 + 24, r2);
            ST32(r1 + 28, r2);
            r1 = LD32(r4 + r5);
            r1 = LD32(r1 + 40);
            r1 = LD32(r3 + r1);
            ST32(r1 + 12, r8);
            r2 = LD32(r4 + r5);
            r1 = LD32(r2 + 40);
            r7 = LD32(r3 + r1);
            r1 = LD32(r2 + 28);
            c1 = r6 * r1;
            r1 = LD32(r2 + 8);
            ST32(r7 + 16, (c1 * r1));
            r0 = r4;
            r1 = LD32(r0 + r5);
            r1 = LD32(r1 + 24);
            r6 = r6 + 1;
            r3 = r6;
        } while (AGAIN(!(r6 >= ((r1 << 2) + (r1 << 2)))));
    }
    r2 = LD32(0x1DE4 + r4);
    ST32(r2 + 16, 0);
    ST32(r2 + 12, 0);
    return 0x1DE4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603AAB8(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10, r11;

    r9 = r4;
    r0 = r9;
    r1 = LD32(r0 + 0x1DE4);
    r1 = LD32(r1 + 24);
    r8 = 0;
    r10 = 0x1DE4;
    if (!(0 >= ((r1 << 2) + (r1 << 2)))) {
        r11 = 0x0603A76C;
        r0 = r9;
        r2 = r8;
        do {
            r1 = LD32(r0 + r10);
            r1 = LD32(r1 + 40);
            r5 = LD32((r2 << 2) + r1);
            r0 = GCALL2(r11, r9, r5);
            r0 = r9;
            r1 = LD32(r0 + r10);
            r1 = LD32(r1 + 24);
            r8 = r8 + 1;
            r2 = r8;
        } while (AGAIN(!(r8 >= ((r1 << 2) + (r1 << 2)))));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603AB10(int r4, int r5)
{
    int r0, r1;

    r0 = r4;
    r1 = LD32(r0 + 0x1DE0);
    r1 = LD32((((r5 << 2) + r1) + 76));
    ST32(r0 + 0x1DE4, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603AB28(int r4)
{
    int r0, r1, r5, r8, r9, r10, r11;

    r9 = r4;
    r1 = LD32(r9 + 4);
    r0 = r9;
    if (!((r1 & r1) == 0)) {
        r1 = LD32(r0 + 0x1DE0);
        r1 = LD32(r1);
        r8 = 0;
        r10 = 0x1DE0;
        if (!(0 >= r1)) {
            r11 = 0x0603AB10;
            r0 = r9;
            do {
                r1 = LD32(r0 + r10);
                r1 = LD32((((r8 << 2) + r1) + 76));
                r5 = r8;
                if (!((r1 & r1) == 0)) {
                    r0 = GCALL2(r11, r9, r5);
                    r0 = GCALL1(0x0603AAB8, r9);
                    r0 = r9;
                }
                r1 = LD32(r0 + r10);
                r1 = LD32(r1);
                r8 = r8 + 1;
                r0 = r9;
            } while (AGAIN(!(r8 >= r1)));
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603ACEC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11;

    r8 = r4;
    ST32(0x1DDC + r8, r5);
    if (r6 >= 0) {
        r3 = 0;
        r5 = 15;
        r6 = 0x1DE0;
        r4 = 0x1E08;
        r7 = r8;
        do {
            r2 = r3 << 2;
            r3 = r3 + 1;
            r1 = LD32(r8 + r6);
            r2 = r2 + r1;
            r1 = LD32(r7 + r4);
            r7 = r7 + 4;
            ST32(r2 + 4, r1);
        } while (AGAIN(!(r3 > r5)));
        r9 = r8 + 68;
        r10 = 0x0603B6E0;
        r0 = GCALL2(0x0603B6E0, r8, r9);
        r11 = r0;
        if (!(r0 == -1)) {
            ST32(r9, 0);
            r0 = GCALL2(r10, r8, r9);
            ST32(r9, 1);
        }
        r3 = 0;
        r5 = 15;
        r6 = 0x1E08;
        r4 = 0x1DE0;
        r7 = r8;
        do {
            r1 = r3 << 2;
            r3 = r3 + 1;
            r2 = LD32(r8 + r4);
            r0 = r7;
            r1 = LD32((r1 + r2) + 4);
            r7 = r7 + 4;
            ST32(r0 + r6, r1);
        } while (AGAIN(!(r3 > r5)));
        r2 = LD32(r8 + 56);
        r1 = LD32(r8 + 60);
        r0 = r11;
        if (r2 >= r1) {
            r0 = -1;
        }
    } else {
        r0 = GCALL4(0x0603B390, r4, r5, r6, r7);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603BA4C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10;

    r8 = r4;
    r10 = 0x20C;
    r0 = GCALL2(0x06028380, 0x20C, 7);
    r1 = r0;
    r9 = 0x1DE0;
    ST32(r8 + 0x1DE0, r1);
    if (!((r1 & r1) == 0)) {
        r0 = GCALL3(0x0604B3F0, r1, 0, r10);
        r2 = LD32(r8 + r9);
        r3 = 0;
        r4 = 15;
        r6 = r9;
        r5 = 204;
        r7 = 0;
        ST32(r2, 0);
        do {
            r2 = r3 << 2;
            r1 = LD32(r8 + r6);
            ST32((r1 + r2) + r5, r7);
            r1 = LD32(r8 + r6);
            r3 = r3 + 1;
            ST32((r2 + r1) + 0x10C, r7);
            r1 = LD32(r8 + r6);
            ST32((r2 + r1) + 0x14C, r7);
            r1 = LD32(r8 + r6);
            ST32((r2 + r1) + 0x18C, r7);
            r1 = LD32(r8 + r6);
            ST32((r2 + r1) + 0x1CC, r7);
        } while (AGAIN(!(r3 > r4)));
        r0 = 0;
    } else {
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603BFAC(int r4, int r5)
{
    int r0, r1, r2, r3;

    r0 = -1;
    if ((r5 & r5) == 0) {
        return r0;
    } else {
        r1 = 0x100 + r4;
        r3 = r1;
        if (!((unsigned)r4 >= (unsigned)r1)) {
            do {
                r2 = LD32(r4);
                r1 = LD32(r5);
                r5 = r5 + 4;
                ST32(r4, (r2 * r1));
                r4 = r4 + 4;
            } while (AGAIN(!((unsigned)r4 >= (unsigned)r3)));
        }
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603BFD8(int r4, int r5, int r6)
{
    int r1, r2, r3;

    r1 = 0x100 + r4;
    r3 = 0;
    if (!((unsigned)r4 >= (unsigned)r1)) {
        r2 = r1;
        do {
            r1 = LD32(r4);
            r1 = r1 + r5;
            ST32(r4, r1);
            if (r1 >= 0) {
                if (r1 > r6) {
                    ST32(r4, r6);
                }
            } else {
                ST32(r4, r3);
            }
            r4 = r4 + 4;
        } while (AGAIN(!((unsigned)r4 >= (unsigned)r2)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603C004(int r4, int r5)
{
    int r1, r2, r3;

    r2 = 0x06078590;
    r3 = 0x06078690;
    if ((unsigned)0x06078590 >= (unsigned)0x06078690) {
        return;
    } else {
        do {
            r1 = LD32(r2);
            r2 = r2 + 4;
            r1 = LD32((r1 << 2) + r4);
            ST32(r5, r1);
            r5 = r5 + 4;
        } while (AGAIN(!((unsigned)r2 >= (unsigned)r3)));
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603C02C(int r4)
{
    int r1, r2;

    r1 = 0x100 + r4;
    r2 = 0;
    if (!((unsigned)r4 >= (unsigned)r1)) {
        do {
            ST32(r4, r2);
            r4 = r4 + 4;
        } while (AGAIN(!((unsigned)r4 >= (unsigned)r1)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603D2BC(int r4)
{
    int r0, r2, r6, r9, r10;

    r9 = r4;
    r10 = 0;
    ST32(r9 + 44, 0);
    ST32(r9 + 48, 0);
    ST32(r9 + 36, -1);
    r0 = GCALL1(0x06010510, 0x0603D2AC);
    ST32(0x060767E4, 12);
    r0 = GCALL4(0x060279E0, 0, 44, -1, 1);
    r2 = r0;
    ST32(r9 + 132, r2);
    if ((r2 & r2) == 0) {
        r0 = -3;
        ST32(r9 + 40, -3);
    } else {
        r6 = LD8((r9 + 22));
        r4 = LD32((r9 + 108));
        r0 = GCALL3(0x0605A15C, r4, r2, r6);
        ST32(r9 + 40, r10);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603D628(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603D62C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r8, r9, r10;

    r10 = r4;
    r2 = LD8((r10 + 23));
    r0 = r5;
    if (r2 > 1) {
        if (r0 >= -510) {
            r9 = r10;
            if (!(r0 > -527)) {
                r9 = r9 + 22;
                r8 = LD8(r9);
                r0 = GCALL4(0x0603E514, r4, r5, r6, r7);
                ST8(r9, (r8 + 1));
                r0 = GCALL1(0x0603D2BC, r10);
                ST32(r10 + 40, r0);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603E6E4(int r4)
{
    int r1, r2;

    r2 = LD8(r4);
    r1 = LD8((r4 + 1));
    r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
    r1 = LD8((r4 + 2));
    r2 = r2 + ((r1 & 255) << 8);
    r1 = LD8((r4 + 3));
    return r2 + (r1 & 255);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603E710(int r4, int r5)
{
    int r0, r1, r2, r3, r8;

    r0 = r5;
    r3 = r0 + r4;
    r2 = LD8(r0 + r4);
    r5 = LD8((r3 + 1));
    r8 = 128 & r2;
    r4 = LD8((r3 + 2));
    r1 = LD8((r3 + 3));
    r4 = ((r4 << 16) << 8) + ((r1 & 255) << 16);
    r1 = LD8((r3 + 4));
    r4 = r4 + ((r1 & 255) << 8);
    r1 = LD8((r3 + 5));
    r0 = GCALL2(0x0607462C, (r4 + (r1 & 255)), ((-((short)(((r5 & 255) + ((r2 & 255) << 8)) + -16383))) + 23));
    r0 = (int)((unsigned)(r0 + 128) >> 8);
    if (!((r8 & r8) == 0)) {
        r0 = -r0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603E9D8(int r4)
{
    int r0, r1, r2, r8, c3, c5;

    r8 = r4;
    r1 = LD16((r8 + 4));
    if (!((unsigned)((r1 - 1) & 0xFFFF) > (unsigned)1)) {
        r2 = LD32(r8 + 8);
        if ((r2 & r2) == 0) {
            r0 = -402;
        } else {
            r1 = r8;
            if (!((unsigned)r2 > (unsigned)0xAC44)) {
                r1 = LD16((r1 + 12));
                c3 = (unsigned)((r1 - 1) & 0xFFFF) > (unsigned)3;
                r1 = r8;
                if (!(c3)) {
                    r1 = LD16((r1 + 14));
                    if (!((unsigned)((r1 - 1) & 0xFFFF) > (unsigned)15)) {
                        r0 = GCALL1(0x0603E6E4, 0x0603E788);
                        r1 = LD32(r8 + 28);
                        c5 = r1 == r0;
                        r0 = 0;
                        if (!(c5)) {
                            r0 = -405;
                        }
                    } else {
                        r0 = -404;
                    }
                } else {
                    r0 = -403;
                }
            } else {
                r0 = -402;
            }
        }
    } else {
        r0 = -401;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603EBE4(int r4)
{
    int r0, r8;

    r8 = r4;
    ST32(r8, 1);
    r0 = GCALL1(0x0603E6E4, 0x0603E788);
    ST32(r8 + 28, r0);
    ST32(r8 + 32, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603EC08(int r4)
{
    int r1, r2;

    r2 = LD8(r4);
    r1 = LD8((r4 + 1));
    r2 = (r2 & 255) + ((r1 & 255) << 8);
    r1 = LD8((r4 + 2));
    r2 = r2 + ((r1 & 255) << 16);
    r1 = LD8((r4 + 3));
    return r2 + ((r1 << 16) << 8);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603EE14(int r4)
{
    int r0, r1, r2, c3;

    r1 = LD16((r4 + 4));
    if (!((unsigned)((r1 - 1) & 0xFFFF) > (unsigned)1)) {
        r2 = LD32(r4 + 8);
        if ((r2 & r2) == 0) {
            return -402;
        } else {
            r1 = r4;
            if (!((unsigned)r2 > (unsigned)0xAC44)) {
                r1 = LD16((r1 + 12));
                c3 = (unsigned)((r1 - 1) & 0xFFFF) > (unsigned)3;
                r1 = r4;
                if (!(c3)) {
                    r1 = LD16((r1 + 14));
                    r0 = 0;
                    if (!((unsigned)((r1 - 1) & 0xFFFF) > (unsigned)15)) {
                        POLL();
                        return r0;
                    } else {
                        return -404;
                    }
                } else {
                    return -403;
                }
            } else {
                return -402;
            }
        }
    } else {
        r0 = -401;
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603F000(int r4, int r5)
{
    int r0, r8, r9;

    r8 = r4;
    r9 = r5;
    r0 = GCALL3(0x0604B3F0, r4, 0, 36);
    ST32(r8, r9);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0603FC68(int r4)
{
    int r1, r2, r3, r7;

    if (!((r4 & r4) == 0)) {
        r1 = LD8(r4);
        r2 = r4;
        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
            r7 = 38;
            do {
                r1 = LD8(r2);
                if (!((r1 & 255) == 37)) {
                    ST8(r4, r1);
                } else {
                    r1 = LD8((r2 + 1));
                    r3 = r2;
                    if (!((r1 & 255) == 50)) {
                        r1 = LD8(r2);
                        ST8(r4, r1);
                    } else {
                        r3 = r3 + 2;
                        r1 = LD8(r3);
                        if (!((r1 & 255) == 54)) {
                            r1 = LD8(r2);
                            ST8(r4, r1);
                        } else {
                            ST8(r4, r7);
                            r2 = r3;
                        }
                    }
                }
                r2 = r2 + 1;
                r1 = LD8(r2);
                r4 = r4 + 1;
            } while (AGAIN(!(((r1 & 255) & (r1 & 255)) == 0)));
        }
        ST8(r4, 0);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030098(void)
{
    int r0, r1, r2, r4, r8, r9, r10, r11, r12, r13, r14, c1, c5, c7, c9;
    FRAME(sp, 296);

    ST16(0x25B0042E, 32);
    r2 = LD32(0x0608EFD0);
    r1 = LD8((r2 + 1));
    r0 = r1 & 255;
    if (r0 == 1) {
        r1 = LD8((r2 + 2));
        r10 = 0;
        r12 = 1;
        r14 = 1;
        r13 = (sp - 296) + 4;
        ST32((0x104 + (sp - 296)), (r1 & 255));
        do {
            r1 = LD32(0x104 + (sp - 296));
            c1 = ((r1 & r12) & (r1 & r12)) == 0;
            r1 = r10;
            if (!(c1)) {
                r11 = r10 & 255;
                r0 = GCALL2(0x06067774, (sp - 296), r11);
                r8 = (short)r10 * (short)92;
                r9 = 0x06087DD8 + r8;
                r1 = r9 + 58;
                r2 = LD16(r1);
                r2 = r2 + 1;
                ST16(r1, r2);
                r1 = LD16((r9 + 56));
                if (!(((short)r2) >= r1)) {
                    r1 = LD32(r9 + 4);
                    r4 = r9;
                    if ((unsigned)r1 > (unsigned)r14) {
                        c5 = r1 == 2;
                        r1 = r10;
                        if (c5) {
                            r0 = GCALL2(0x0602FBE4, r9, 1);
                            r0 = GCALL2(0x0602FBE4, r9, 0);
                            r1 = r10;
                        }
                    } else {
                        r0 = GCALL2(0x06030034, (r4 + 4), r13);
                        r0 = GCALL3(0x0602FDD4, r9, r14, r13);
                        r0 = GCALL3(0x0602FDD4, r9, 0, r13);
                        r1 = r10;
                    }
                } else {
                    r0 = GCALL1(0x06067460, r11);
                    ST32(0x06087DD8 + r8, r14);
                    r1 = r10;
                }
            }
            r10 = (short)(r1 + 1);
            r12 = (r12 + r12) & 0xFFFF;
        } while (AGAIN(!(r10 > 3)));
        r10 = 0;
        r11 = 0x06087F48;
        do {
            r0 = 0x104;
            r1 = LD32(0x104 + (sp - 296));
            c7 = ((r1 & r12) & (r1 & r12)) == 0;
            r1 = r10;
            if (!(c7)) {
                r8 = (short)r10 * (short)12;
                r9 = r8 + r11;
                r2 = r9 + 4;
                r1 = LD16(r2);
                ST16(r2, (r1 - 1));
                r1 = LD16(r2);
                r1 = LD16(r2);
                c9 = ((short)r1) > 0;
                r1 = r10;
                if (!(c9)) {
                    r0 = GCALL1(0x06067460, ((r10 + 4) & 255));
                    r0 = r8;
                    ST32(r0 + r11, 1);
                    r1 = LD32(0x06089CB8);
                    ST32(r9 + 8, r1);
                    r1 = r10;
                }
            }
            r10 = (short)(r1 + 1);
            r12 = (r12 + r12) & 0xFFFF;
        } while (AGAIN(!(r10 > 3)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603157C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c3, c8, c10;
    FRAME(sp, 32);

    r8 = r4;
    r12 = r5;
    r11 = r6;
    r13 = LD32(sp);
    r10 = (short)r7;
    r14 = LD32(sp + 4);
    r0 = GCALL0(0x06016A10);
    r3 = r0;
    r2 = LD32(r3 + 8);
    r9 = 0;
    r0 = (((r2 & 65) & (r2 & 65)) == 0) ^ 1;
    r2 = LD32(r3 + 36);
    r3 = 0;
    if (!((r0 & r0) == 0)) {
        r0 = 1;
    } else {
        r0 = r2;
        if (!(((1 & r2) & (1 & r2)) == 0)) {
            r0 = 1;
        } else {
            c3 = ((r0 & 64) & (r0 & 64)) == 0;
            r0 = r3;
            if (!(c3)) {
                r0 = 1;
            }
        }
    }
    r2 = r13;
    if ((r0 & r0) == 0) {
        r4 = LD16((r8 + 20));
        r0 = GCALL1(0x06031D74, r4);
        r2 = r8 + 2;
        r0 = LD16(r2);
        c8 = r0 == -1;
        if (!(r0 == 2)) {
            r1 = -1;
            if (c8) {
                r1 = LD32(r8 + 28);
                c10 = (r1 & r1) == 0;
                r1 = 5;
                if (!(c10)) {
                    ST16(r2, r1);
                    ST16((r8 + 8), 10);
                }
                r1 = -1;
            }
        } else {
            r5 = LD32(r8 + 28);
            r0 = GCALL4(0x060314EC, r8, r5, 0, 0);
            r9 = r0;
            r1 = -1;
            if ((r9 & r9) == 0) {
                r1 = LD32(0x06089CB8);
                ST32(r8 + 24, r1);
                r1 = -1;
            }
        }
        ST16(r14, r1);
    } else {
        r1 = LD32(r8 + 28);
        r1 = r1 + (r2 + r2);
        ST32(r8 + 28, r1);
        if (!(r1 >= 0)) {
            ST32(r8 + 28, 0);
        }
        r2 = LD32(r8 + 28);
        r1 = LD32(r8 + 32);
        r0 = r10;
        if (!(r2 >= r1)) {
            r0 = r0 << 2;
            r1 = LD16(((r0 + 0x06078044) + 2));
            r6 = r11 + r1;
            r1 = LD16(r0 + 0x06078044);
            r0 = GCALL3(0x06031448, r10, (r12 + r1), r6);
        } else {
            ST16((r8 + 2), -1);
            ST16((r8 + 4), -1);
            ST32(r8 + 28, 0);
        }
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06031DB0(int r4, int r5, int r6)
{
    int r0, r1, r2, c2, c3, c4;

    r4 = (short)r4;
    r0 = r4;
    if (!((unsigned)(r4 & 0xFFFF) > (unsigned)1)) {
        r0 = r0 << 2;
        r2 = r0 + 0x06078044;
        r1 = LD16(r0 + 0x06078044);
        c2 = r5 >= r1;
        r1 = r1 + 32;
        if (!(c2)) {
            return 0;
        } else {
            c3 = r5 > r1;
            r1 = r2;
            if (c3) {
                return 0;
            } else {
                r1 = LD16((r1 + 2));
                c4 = r6 >= r1;
                r1 = r1 + 22;
                if (!(c4)) {
                    return 0;
                } else {
                    r0 = 1;
                    if (!(r6 > r1)) {
                        return r0;
                    } else {
                        return 0;
                    }
                }
            }
        }
    } else {
        r0 = r0 << 2;
        if (!((unsigned)((r4 - 2) & 0xFFFF) > (unsigned)1)) {
            r2 = r0 + 0x06078044;
            r1 = LD16(r0 + 0x06078044);
            c2 = r5 >= r1;
            r1 = r1 + 32;
            if (!(c2)) {
                return 0;
            } else {
                c3 = r5 > r1;
                r1 = r2;
                if (c3) {
                    return 0;
                } else {
                    r1 = LD16((r1 + 2));
                    c4 = r6 >= r1;
                    r1 = r1 + 22;
                    if (!(c4)) {
                        return 0;
                    } else {
                        r0 = 1;
                        if (!(r6 > r1)) {
                            return r0;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            return 0;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060320AC(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12, r13;
    FRAME(sp, 260);

    r13 = LD32(0x0607668C);
    ST32(0x0607668C, 2);
    r0 = GCALL4(0x06045264, (sp - 36), 0x060320A4, (r4 + 1), r7);
    r10 = 0;
    r12 = 0x060750DC;
    r11 = 0x06075408;
    r9 = (sp - 260) + 56;
    r8 = 0;
    do {
        r0 = r8;
        ST32(r0 + (sp - 260), r9);
        r5 = LD32(r0 + 0x060780CC);
        r0 = GCALL2(r12, r9, r5);
        r4 = LD32(r8 + (sp - 260));
        r0 = GCALL2(r11, r4, (sp - 36));
        r9 = r9 + 12;
        r10 = r10 + 1;
        r8 = r8 + 4;
    } while (AGAIN(!(r10 > 13)));
    r0 = GCALL0(0x06032440);
    r0 = GCALL3(0x0603124C, (sp - 260), 0x06087F88, 14);
    ST32(0x0607668C, r13);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06032164(int r4)
{
    int r0, r1, c2;

    r1 = LD32(0x06078040);
    r4 = (short)r4;
    if (!((r1 & r1) == 0)) {
        r1 = LD8(0x0608AF52);
        c2 = r4 >= 0;
        if (!((r1 & r1) == 0)) {
            if (c2) {
                r1 = LD16(0x06087F84);
                r0 = r4;
                if (!(r4 >= r1)) {
                    r4 = LD16((r0 + r0) + 0x06087F88);
                    r0 = GCALL3(0x06030E28, r4, 7, 0);
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032574(int r4)
{
    int r0, c1, c2, c3, c4, c5;

    r0 = r4;
    c1 = r0 == 1;
    if (!((r0 & r0) == 0)) {
        c2 = r0 == 2;
        if (!(c1)) {
            c3 = r0 == 3;
            if (!(c2)) {
                c4 = r0 == 5;
                if (!(c3)) {
                    c5 = r0 == 6;
                    if (!(c4)) {
                        r0 = -1;
                        if (!(c5)) {
                            POLL();
                            return r0;
                        } else {
                            return -205;
                        }
                    } else {
                        return -2;
                    }
                } else {
                    return -204;
                }
            } else {
                r0 = -203;
                return r0;
            }
        } else {
            return -7;
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060337C0(int r4)
{
    int r0, r1, r5, r6, r7, r8, r9;

    r9 = r4;
    r0 = GCALL0(0x06034024);
    r8 = r0;
    r0 = 0;
    if (!((r8 & r8) == 0)) {
        r1 = LD32(r8 + 52);
        ST32(r9, r1);
        r1 = LD32(r8 + 40);
        r0 = 1;
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x060287D0, 1);
            r9 = r0;
            r1 = 0;
            if (!((r9 & r9) == 0)) {
                ST8(r9, r1);
                r7 = LD16((r8 + 44));
                r6 = LD16((r8 + 46));
                r1 = LD32(r8 + 48);
                r5 = -1;
                if (!((r1 & r1) == 0)) {
                    r5 = r7;
                }
                r0 = GCALL4(0x060419E0, r9, r5, r6, r7);
                ST32(r8 + 40, r0);
                ST32(r8 + 36, r9);
            }
            r0 = 1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060338B8(int r4)
{
    int r0, r1, r5, r8, r9, r10;

    r9 = r4;
    if ((r9 & r9) == 0) {
        r0 = 0;
    } else {
        r1 = LD32(r9 + 36);
        r0 = 0;
        if (!((r1 & r1) == 0)) {
            r1 = LD32(0x06078124);
            r8 = r1;
            if (!((r1 & r1) == 0)) {
                r1 = LD32(r1 + 8);
                r8 = r8 + 8;
                if ((r1 & r1) == 0) {
                    ST32(r8, r9);
                    r0 = 1;
                } else {
                    r10 = 0x06075104;
                    r1 = LD32(r8);
                    while (1) {
                        r4 = LD32(r1 + 36);
                        if ((r4 & r4) == 0) {
                            r8 = r1 + 80;
                            r1 = LD32(r8);
                            if (!((r1 & r1) == 0)) {
                                POLL();
                                continue;
                            } else {
                                ST32(r8, r9);
                                r0 = 1;
                                break;
                            }
                        } else {
                            r5 = LD32(r9 + 36);
                            r0 = GCALL2(r10, r4, r5);
                            r1 = LD32(r8);
                            if ((r0 & r0) == 0) {
                                POLL();
                                r1 = LD32((r1 + 80));
                                r0 = 1;
                                ST32((r9 + 80), r1);
                                r1 = LD32(r8);
                                ST32((r9 + 76), r1);
                                ST32(r8, r9);
                                break;
                            } else {
                                r8 = r1 + 80;
                                r1 = LD32(r8);
                                if (!((r1 & r1) == 0)) {
                                    POLL();
                                    continue;
                                } else {
                                    ST32(r8, r9);
                                    r0 = 1;
                                    break;
                                }
                            }
                        }
                        POLL();
                    }
                }
            } else {
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033930(int r4)
{
    int r0, r1, r2, c4;

    if (!((r4 & r4) == 0)) {
        r2 = 0x06078120;
        r1 = LD32(0x06078120);
        if ((r1 & r1) == 0) {
            POLL();
            return 0;
        } else {
            r1 = LD32(r2 + 4);
            r2 = LD32(r1 + 4);
            if ((r2 & r2) == 0) {
                POLL();
                return 0;
            } else {
                r0 = LD32(r2);
                c4 = (r2 & r2) == 0;
                if (!(r0 == 1)) {
                    POLL();
                    return 0;
                } else {
                    if (c4) {
                        POLL();
                        return 0;
                    } else {
                        r1 = LD32(r2 + 44);
                        if (!((r1 & r1) == 0)) {
                            r1 = LD32(r2 + 48);
                            ST32(r4 + 28, r1);
                            r1 = LD32(r2 + 48);
                            ST32(r1 + 24, r4);
                            ST32(r2 + 48, r4);
                        } else {
                            ST32(r2 + 44, r4);
                            ST32(r2 + 48, r4);
                            ST32(r2 + 52, r4);
                        }
                        return 1;
                    }
                }
            }
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034F50(int r4)
{
    int r0, r1, c3;

    if ((r4 & r4) == 0) {
        return;
    } else {
        r0 = LD32(r4);
        r1 = 1;
        if (r0 == 1) {
            r1 = 0x06034ED0;
            r0 = GCALL1(r1, r4);
            return;
        } else {
            c3 = (r0 & r0) == 0;
            if (r0 > r1) {
                if (r0 == 2) {
                    r1 = 0x06034E20;
                    r0 = GCALL1(r1, r4);
                }
                return;
            } else {
                if (c3) {
                    r1 = 0x06034F00;
                    r0 = GCALL1(r1, r4);
                    return;
                } else {
                    return;
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603592C(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14, c1, c3, c6, c13;
    FRAME(sp, 116);

    r14 = r4;
    r13 = r5;
    ST32(sp - 76, r6);
    r8 = 136;
    r0 = LD32(r14 + 136);
    ST32(sp - 64, r0);
    r0 = GCALL3(0x060350C4, r4, (sp - 92), (sp - 88));
    ST32(sp - 72, r0);
    r0 = GCALL2(0x06035068, r14, (sp - 96));
    r0 = LD32(sp - 72);
    r0 = LD32(r0 + 32);
    ST32(sp - 68, r0);
    r0 = GCALL4(0x06035820, r14, r13, (sp - 84), (sp - 80));
    ST32(sp - 44, 2);
    r1 = LD16((r13 + 46));
    r3 = 4;
    if (r1 == 1) {
        ST32(sp - 44, r3);
    }
    r0 = GCALL1(0x06034CEC, r14);
    c1 = (r0 & r0) == 0;
    r0 = r14;
    if (!(c1)) {
        r1 = LD32(r0 + r8);
        r5 = 28;
        if ((r1 & r1) == 0) {
            ST32(r14 + 136, 0);
            r3 = LD32(sp - 76);
            r1 = r13;
            if ((r3 & r3) == 0) {
                r1 = LD32(140 + r14);
                c6 = (r1 & r1) == 0;
                r1 = r13;
                if (c6) {
                    r8 = r13 + 14;
                    r7 = LD16(r8);
                    r9 = r13 + 12;
                    r6 = LD32(r13 + 16);
                    r5 = LD16(r9);
                    ST32((sp - 100), -110);
                    r1 = LD32(r13 + 20);
                    ST32((sp - 104), r1);
                    r0 = GCALL6(0x06015154, r14, r5, r6, r7, LD32((sp - 104)), LD32((sp - 100)));
                    r7 = LD16(r8);
                    r1 = LD32(sp - 92);
                    r0 = LD32(sp - 44);
                    r6 = LD32(r13 + 16);
                    r5 = LD16(r9);
                    r7 = r7 - (r0 * r1);
                    ST32((sp - 108), -1);
                    r1 = LD32(r13 + 20);
                    r2 = LD32(sp - 88);
                    ST32((sp - 112), ((r1 - r2) - 2));
                    r0 = GCALL8(0x06015154, r14, (r5 + 2), (r6 + 2), (r7 - 2), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                    r1 = r13;
                }
            }
            r1 = LD16((r1 + 46));
            r11 = LD32(r13 + 40);
            ST32(sp - 48, r1);
            r1 = LD32(r11 + 20);
            r3 = LD32(sp - 48);
            if (!(r1 >= r3)) {
                ST32(sp - 48, r1);
            }
            r1 = LD16((r13 + 12));
            r0 = LD32(sp - 92);
            ST32(sp - 60, ((r1 + r0) + 2));
            r2 = LD16((r13 + 14));
            r1 = LD32(sp - 44);
            r10 = 0;
            r3 = LD32(sp - 48);
            ST32(sp - 56, ((r2 - ((r1 + 1) * r0)) - 2));
            r1 = LD32(r13 + 16);
            r9 = r1 + 2;
            if (!(0 >= r3)) {
                do {
                    r1 = LD32(r11 + 40);
                    r2 = LD32(r11 + 4);
                    r12 = LD32(((r1 + r10) << 2) + r2);
                    r0 = GCALL1(0x0607507C, r12);
                    r8 = r0;
                    r6 = LD32(r11 + 44);
                    r1 = LD16((r13 + 44));
                    r0 = LD32(sp - 76);
                    if ((r8 - r6) >= r1) {
                        r8 = r1 + r6;
                    }
                    if ((r0 & r0) == 0) {
                        r0 = LD32(sp - 72);
                        r1 = LD32(r0);
                        r7 = r8 - 1;
                        ST32((sp - 100), r1);
                        r1 = 0x10B8;
                        r0 = r14;
                        r1 = LD32(r0 + r1);
                        ST32((sp - 104), r1);
                        r3 = LD32(sp - 68);
                        ST32((sp - 108), r3);
                        ST32((sp - 112), r9);
                        r0 = LD32(sp - 60);
                        ST32((sp - 116), r0);
                        r0 = GCALL8(0x06014880, r14, r12, r6, r7, LD32((sp - 116)), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)));
                        r1 = LD32(sp - 88);
                    } else {
                        r1 = LD32(r11 + 40);
                        r2 = LD32(r11 + 12);
                        r1 = LD32(((r1 + r10) << 2) + r2);
                        c13 = (r1 & r1) == 0;
                        r1 = LD32(sp - 88);
                        if (!(c13)) {
                            r1 = LD32(140 + r14);
                            r6 = r9;
                            if ((r1 & r1) == 0) {
                                ST32((sp - 100), -1);
                                r1 = LD32(sp - 88);
                                ST32((sp - 104), ((r1 + r9) - 1));
                                r7 = LD32(sp - 56);
                                r5 = LD32(sp - 60);
                                r0 = GCALL6(0x06015154, r14, r5, (r6 + 1), r7, LD32((sp - 104)), LD32((sp - 100)));
                            }
                            r6 = LD32(r11 + 44);
                            r3 = LD32(sp - 72);
                            r7 = r8 - 1;
                            r1 = LD32(r3);
                            ST32((sp - 100), r1);
                            r1 = 0x10B8;
                            r0 = r14;
                            r1 = LD32(r0 + r1);
                            ST32((sp - 104), r1);
                            r3 = LD32(sp - 68);
                            ST32((sp - 108), r3);
                            ST32((sp - 112), r9);
                            r0 = LD32(sp - 60);
                            ST32((sp - 116), r0);
                            r0 = GCALL8(0x06014880, r14, r12, r6, r7, LD32((sp - 116)), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)));
                            r1 = LD32(sp - 88);
                        }
                    }
                    r10 = r10 + 1;
                    r0 = LD32(sp - 48);
                    r9 = r9 + r1;
                } while (AGAIN(!(r10 >= r0)));
            }
            r3 = LD32(sp - 76);
            if ((r3 & r3) == 0) {
                r1 = LD32(140 + r14);
                r12 = r13;
                if ((r1 & r1) == 0) {
                    r1 = LD32(sp - 92);
                    r0 = LD32(sp - 44);
                    r12 = r12 + 14;
                    r7 = LD16(r12);
                    r9 = r7 - (r0 * r1);
                    ST32(sp - 52, (r9 - 2));
                    r2 = LD32(r13 + 20);
                    r1 = LD32(sp - 88);
                    r6 = LD32(r13 + 16);
                    r11 = (r2 - r1) - 2;
                    r5 = LD16((r13 + 12));
                    ST32((sp - 100), 1);
                    ST32((sp - 104), 2);
                    ST32((sp - 108), -1);
                    ST32((sp - 112), r2);
                    r0 = GCALL8(0x060153C8, r14, r5, r6, r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                    r8 = r13 + 46;
                    r1 = LD16(r8);
                    if (!(r1 == 1)) {
                        r9 = r9 - 1;
                        r10 = 0;
                        r7 = LD16(r12);
                        r2 = LD32(r13 + 16);
                        ST32((sp - 100), 0);
                        ST32((sp - 104), 2);
                        ST32((sp - 108), -1);
                        r1 = LD32(sp - 88);
                        ST32((sp - 112), ((r2 + r1) + 2));
                        r0 = GCALL8(0x060153C8, r14, r9, (r2 + 2), (r7 - 2), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        r1 = LD32(r13 + 16);
                        ST32((sp - 116), 0);
                        r2 = LD32(sp - 88);
                        r7 = r1;
                        ST32((sp - 120), ((r1 + r2) + 2));
                        r1 = LD16(r12);
                        ST32((sp - 124), (r1 - 2));
                        r0 = GCALL8(0x06035264, r14, 0, r9, (r7 + 2), LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                        r7 = LD16(r12);
                        r1 = LD32(sp - 88);
                        ST32((sp - 128), 0);
                        ST32((sp - 132), 2);
                        ST32((sp - 136), -1);
                        ST32((sp - 140), r11);
                        r0 = GCALL8(0x060153C8, r14, r9, (r11 - r1), (r7 - 2), LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                        r1 = LD32(sp - 88);
                        r7 = r11 - r1;
                        ST32((sp - 100), 0);
                        ST32((sp - 104), r11);
                        r1 = LD16(r12);
                        ST32((sp - 108), (r1 - 2));
                        r0 = GCALL7(0x06035264, r14, 1, r9, r7, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        r2 = LD16(r8);
                        if (r2 > 4) {
                            r7 = LD16(r12);
                            r2 = LD32(sp - 88);
                            r1 = LD32(r13 + 16);
                            ST32((sp - 100), r10);
                            ST32((sp - 104), 2);
                            ST32((sp - 108), -1);
                            ST32((sp - 112), ((r1 + (r2 + r2)) + 4));
                            r0 = GCALL8(0x060153C8, r14, r9, ((r2 + 4) + r1), (r7 - 2), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            r2 = LD32(sp - 88);
                            ST32((76 + (sp - 112)), (r2 + 4));
                            r1 = LD32(r13 + 16);
                            r7 = LD32(76 + (sp - 112));
                            r7 = r7 + r1;
                            ST32((sp - 116), r10);
                            ST32((sp - 120), ((r1 + (r2 + r2)) + 4));
                            r1 = LD16(r12);
                            ST32((sp - 124), (r1 - 2));
                            r0 = GCALL8(0x06035264, r14, 1, r9, r7, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                            r8 = r11 - 2;
                            r7 = LD16(r12);
                            r2 = LD32(sp - 88);
                            ST32((sp - 128), r10);
                            ST32((sp - 132), 2);
                            ST32((sp - 136), -1);
                            ST32((sp - 140), ((r11 - r2) - 2));
                            r0 = GCALL8(0x060153C8, r14, r9, (r8 - (r2 + r2)), (r7 - 2), LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                            r2 = LD32(sp - 88);
                            ST32((sp - 100), r10);
                            ST32((sp - 104), ((r11 - r2) - 2));
                            r1 = LD16(r12);
                            ST32((sp - 108), (r1 - 2));
                            r0 = GCALL7(0x06035264, r14, 0, r9, (r8 - (r2 + r2)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        }
                    } else {
                        r9 = r9 - 1;
                        r7 = LD16(r12);
                        r1 = LD32(sp - 92);
                        r2 = LD32(r13 + 16);
                        r7 = (r7 - 2) - (r1 + r1);
                        ST32((sp - 100), 0);
                        ST32((sp - 104), 2);
                        ST32((sp - 108), -1);
                        r1 = LD32(sp - 88);
                        ST32((sp - 112), ((r2 + r1) + 2));
                        r0 = GCALL8(0x060153C8, r14, r9, (r2 + 2), r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        r1 = LD32(r13 + 16);
                        ST32((sp - 116), 0);
                        r2 = LD32(sp - 88);
                        ST32((sp - 120), ((r1 + r2) + 2));
                        r2 = LD16(r12);
                        r7 = r1 + 2;
                        r1 = LD32(sp - 92);
                        ST32((sp - 124), ((r2 - 2) - (r1 + r1)));
                        r0 = GCALL8(0x06035264, r14, 0, r9, r7, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                        r5 = LD16(r12);
                        r2 = LD32(r13 + 16);
                        r1 = LD32(sp - 92);
                        r7 = r5 - 2;
                        r5 = (r5 - (r1 + r1)) - 2;
                        ST32((sp - 128), 0);
                        ST32((sp - 132), 2);
                        ST32((sp - 136), -1);
                        r1 = LD32(sp - 88);
                        ST32((sp - 140), ((r2 + r1) + 2));
                        r0 = GCALL8(0x060153C8, r14, r5, (r2 + 2), r7, LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                        r2 = LD32(r13 + 16);
                        r12 = LD16(r12);
                        r1 = LD32(sp - 92);
                        ST32(sp - 36, r12);
                        r6 = r12 - (r1 + r1);
                        ST32((sp - 100), 0);
                        r1 = LD32(sp - 88);
                        ST32((sp - 104), ((r2 + r1) + 2));
                        r3 = 68 + (sp - 104);
                        r0 = LD32(r3);
                        ST32(r3, (r0 - 2));
                        r3 = LD32((68 + (sp - 104)));
                        ST32((sp - 108), r3);
                        r0 = GCALL7(0x06035264, r14, 1, (r6 - 2), (r2 + 2), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                    }
                    r0 = r13 + 44;
                    ST32(sp - 40, r0);
                    r1 = LD16(r0);
                    r8 = r13;
                    if (!(r1 == 1)) {
                        r8 = r8 + 12;
                        r11 = r11 + 1;
                        r9 = 0;
                        r10 = 2;
                        r12 = -1;
                        r1 = LD32(sp - 92);
                        r5 = LD16(r8);
                        r7 = (r5 + (r1 + r1)) + 2;
                        ST32((sp - 100), 0);
                        ST32((sp - 104), 2);
                        ST32((sp - 108), -1);
                        r1 = LD32(r13 + 20);
                        ST32((sp - 112), (r1 - 2));
                        r0 = GCALL8(0x060153C8, r14, (r5 + 2), r11, r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        r2 = LD16(r8);
                        ST32((sp - 116), 0);
                        r1 = LD32(r13 + 20);
                        ST32((sp - 120), (r1 - 2));
                        r1 = LD32(sp - 92);
                        ST32((sp - 124), ((r2 + (r1 + r1)) + 2));
                        r0 = GCALL8(0x06035264, r14, 2, (r2 + 2), r11, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                        r1 = LD32(sp - 92);
                        r5 = LD32((72 + (sp - 124)));
                        r5 = r5 - (r1 + r1);
                        ST32((sp - 128), 0);
                        ST32((sp - 132), 2);
                        ST32((sp - 136), -1);
                        r1 = LD32(r13 + 20);
                        ST32((sp - 140), (r1 - 2));
                        r7 = LD32((88 + (sp - 140)));
                        r0 = GCALL8(0x060153C8, r14, r5, r11, r7, LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                        r1 = LD32(sp - 92);
                        r6 = LD32(sp - 52);
                        r6 = r6 - (r1 + r1);
                        ST32((sp - 100), 0);
                        r1 = LD32(r13 + 20);
                        ST32((sp - 104), (r1 - 2));
                        r0 = LD32(sp - 52);
                        ST32((sp - 108), r0);
                        r0 = GCALL7(0x06035264, r14, 3, r6, r11, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        r0 = LD32(sp - 40);
                        r2 = LD16(r0);
                        r6 = r11;
                        if (r2 > 9) {
                            r1 = LD32(sp - 92);
                            r5 = LD16(r8);
                            r7 = (r5 + (r1 << 2)) + 6;
                            r5 = r5 + (r1 + r1);
                            ST32((sp - 100), r9);
                            ST32((sp - 104), r10);
                            ST32((sp - 108), r12);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 112), (r1 - 2));
                            r0 = GCALL8(0x060153C8, r14, (r5 + 4), r6, r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            r2 = LD16(r8);
                            r3 = LD32(sp - 92);
                            ST32((76 + (sp - 112)), r3);
                            r1 = LD32(76 + (sp - 112));
                            r6 = r2 + (r1 + r1);
                            ST32((sp - 116), r9);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 120), (r1 - 2));
                            r3 = 84 + (sp - 120);
                            r0 = LD32(r3);
                            ST32(r3, (r0 << 2));
                            r3 = LD32((84 + (sp - 120)));
                            ST32((sp - 124), ((r2 + r3) + 6));
                            r0 = GCALL8(0x06035264, r14, 3, (r6 + 4), r11, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                            r8 = LD32((72 + (sp - 124)));
                            r1 = LD32(sp - 92);
                            r8 = r8 - 2;
                            r2 = r1 + r1;
                            r5 = r8 - (r1 << 2);
                            ST32((sp - 128), r9);
                            ST32((sp - 132), r10);
                            ST32((sp - 136), r12);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 140), (r1 - 2));
                            r0 = GCALL8(0x060153C8, r14, r5, r11, (r8 - r2), LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                            r2 = LD32(sp - 92);
                            ST32((sp - 100), r9);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 104), (r1 - 2));
                            ST32((sp - 108), (r8 - (r2 + r2)));
                            r0 = GCALL7(0x06035264, r14, r10, (r8 - (r2 << 2)), r11, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        }
                    } else {
                        r10 = r13 + 12;
                        r11 = r11 + 1;
                        r1 = LD32(sp - 92);
                        r5 = LD16(r10);
                        r7 = (r5 + (r1 + r1)) + 2;
                        ST32((sp - 100), 0);
                        ST32((sp - 104), 2);
                        ST32((sp - 108), -1);
                        r1 = LD32(r13 + 20);
                        ST32((sp - 112), (r1 - 2));
                        r0 = GCALL8(0x060153C8, r14, (r5 + 2), r11, r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        r2 = LD16(r10);
                        ST32((sp - 116), 0);
                        r1 = LD32(r13 + 20);
                        ST32((sp - 120), (r1 - 2));
                        r1 = LD32(sp - 92);
                        ST32((sp - 124), ((r2 + (r1 + r1)) + 2));
                        r0 = GCALL8(0x06035264, r14, 2, (r2 + 2), r11, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                        r1 = LD32(sp - 92);
                        r5 = LD16(r10);
                        r7 = (r5 + (r1 << 2)) + 2;
                        r5 = r5 + (r1 + r1);
                        ST32((sp - 128), 0);
                        ST32((sp - 132), 2);
                        ST32((sp - 136), -1);
                        r1 = LD32(r13 + 20);
                        ST32((sp - 140), (r1 - 2));
                        r0 = GCALL8(0x060153C8, r14, (r5 + 2), r11, r7, LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                        r2 = LD16(r10);
                        r0 = LD32(sp - 92);
                        ST32(sp - 36, r0);
                        r6 = r2 + (r0 + r0);
                        ST32((sp - 100), 0);
                        r1 = LD32(r13 + 20);
                        ST32((sp - 104), (r1 - 2));
                        r3 = 68 + (sp - 104);
                        r0 = LD32(r3);
                        ST32(r3, (r0 << 2));
                        r3 = LD32((68 + (sp - 104)));
                        ST32((sp - 108), ((r2 + r3) + 2));
                        r0 = GCALL7(0x06035264, r14, 3, (r6 + 2), r11, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                    }
                }
            }
            r3 = LD32(sp - 64);
            ST32(r14 + 136, r3);
            r0 = GCALL2(0x060350B0, r14, (sp - 96));
            r0 = LD32(sp - 84);
        } else {
            r0 = GCALL2(0x06015D00, r14, r5);
            c3 = (r0 & r0) == 0;
            r0 = r14;
            if (c3) {
                r0 = -1;
            } else {
                r6 = 152;
                r2 = LD32(r0 + 152);
                ST32(r2, 14);
                ST32(r2 + 4, 0);
                ST32(r2 + 24, r13);
                r1 = LD32(r13 + 16);
                ST32(r2 + 12, r1);
                r1 = LD32(r13 + 20);
                r7 = 148;
                ST32(r2 + 16, r1);
                r1 = LD32(r0 + 148);
                if (!((r1 & r1) == 0)) {
                    ST32(r1, r2);
                }
                r0 = r14;
                ST32(r0 + r7, (r2 + 4));
                r1 = LD32(r0 + r6);
                ST32(r0 + r6, (r1 + 28));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                ST32(r13 + 56, r2);
                ST32(r14 + 136, 0);
                r3 = LD32(sp - 76);
                r1 = r13;
                if ((r3 & r3) == 0) {
                    r1 = LD32(140 + r14);
                    c6 = (r1 & r1) == 0;
                    r1 = r13;
                    if (c6) {
                        r8 = r13 + 14;
                        r7 = LD16(r8);
                        r9 = r13 + 12;
                        r6 = LD32(r13 + 16);
                        r5 = LD16(r9);
                        ST32((sp - 100), -110);
                        r1 = LD32(r13 + 20);
                        ST32((sp - 104), r1);
                        r0 = GCALL6(0x06015154, r14, r5, r6, r7, LD32((sp - 104)), LD32((sp - 100)));
                        r7 = LD16(r8);
                        r1 = LD32(sp - 92);
                        r0 = LD32(sp - 44);
                        r6 = LD32(r13 + 16);
                        r5 = LD16(r9);
                        r7 = r7 - (r0 * r1);
                        ST32((sp - 108), -1);
                        r1 = LD32(r13 + 20);
                        r2 = LD32(sp - 88);
                        ST32((sp - 112), ((r1 - r2) - 2));
                        r0 = GCALL8(0x06015154, r14, (r5 + 2), (r6 + 2), (r7 - 2), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        r1 = r13;
                    }
                }
                r1 = LD16((r1 + 46));
                r11 = LD32(r13 + 40);
                ST32(sp - 48, r1);
                r1 = LD32(r11 + 20);
                r3 = LD32(sp - 48);
                if (!(r1 >= r3)) {
                    ST32(sp - 48, r1);
                }
                r1 = LD16((r13 + 12));
                r0 = LD32(sp - 92);
                ST32(sp - 60, ((r1 + r0) + 2));
                r2 = LD16((r13 + 14));
                r1 = LD32(sp - 44);
                r10 = 0;
                r3 = LD32(sp - 48);
                ST32(sp - 56, ((r2 - ((r1 + 1) * r0)) - 2));
                r1 = LD32(r13 + 16);
                r9 = r1 + 2;
                if (!(0 >= r3)) {
                    do {
                        r1 = LD32(r11 + 40);
                        r2 = LD32(r11 + 4);
                        r12 = LD32(((r1 + r10) << 2) + r2);
                        r0 = GCALL1(0x0607507C, r12);
                        r8 = r0;
                        r6 = LD32(r11 + 44);
                        r1 = LD16((r13 + 44));
                        r0 = LD32(sp - 76);
                        if ((r8 - r6) >= r1) {
                            r8 = r1 + r6;
                        }
                        if ((r0 & r0) == 0) {
                            r0 = LD32(sp - 72);
                            r1 = LD32(r0);
                            r7 = r8 - 1;
                            ST32((sp - 100), r1);
                            r1 = 0x10B8;
                            r0 = r14;
                            r1 = LD32(r0 + r1);
                            ST32((sp - 104), r1);
                            r3 = LD32(sp - 68);
                            ST32((sp - 108), r3);
                            ST32((sp - 112), r9);
                            r0 = LD32(sp - 60);
                            ST32((sp - 116), r0);
                            r0 = GCALL8(0x06014880, r14, r12, r6, r7, LD32((sp - 116)), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)));
                            r1 = LD32(sp - 88);
                        } else {
                            r1 = LD32(r11 + 40);
                            r2 = LD32(r11 + 12);
                            r1 = LD32(((r1 + r10) << 2) + r2);
                            c13 = (r1 & r1) == 0;
                            r1 = LD32(sp - 88);
                            if (!(c13)) {
                                r1 = LD32(140 + r14);
                                r6 = r9;
                                if ((r1 & r1) == 0) {
                                    ST32((sp - 100), -1);
                                    r1 = LD32(sp - 88);
                                    ST32((sp - 104), ((r1 + r9) - 1));
                                    r7 = LD32(sp - 56);
                                    r5 = LD32(sp - 60);
                                    r0 = GCALL6(0x06015154, r14, r5, (r6 + 1), r7, LD32((sp - 104)), LD32((sp - 100)));
                                }
                                r6 = LD32(r11 + 44);
                                r3 = LD32(sp - 72);
                                r7 = r8 - 1;
                                r1 = LD32(r3);
                                ST32((sp - 100), r1);
                                r1 = 0x10B8;
                                r0 = r14;
                                r1 = LD32(r0 + r1);
                                ST32((sp - 104), r1);
                                r3 = LD32(sp - 68);
                                ST32((sp - 108), r3);
                                ST32((sp - 112), r9);
                                r0 = LD32(sp - 60);
                                ST32((sp - 116), r0);
                                r0 = GCALL8(0x06014880, r14, r12, r6, r7, LD32((sp - 116)), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)));
                                r1 = LD32(sp - 88);
                            }
                        }
                        r10 = r10 + 1;
                        r0 = LD32(sp - 48);
                        r9 = r9 + r1;
                    } while (AGAIN(!(r10 >= r0)));
                }
                r3 = LD32(sp - 76);
                if ((r3 & r3) == 0) {
                    r1 = LD32(140 + r14);
                    r12 = r13;
                    if ((r1 & r1) == 0) {
                        r1 = LD32(sp - 92);
                        r0 = LD32(sp - 44);
                        r12 = r12 + 14;
                        r7 = LD16(r12);
                        r9 = r7 - (r0 * r1);
                        ST32(sp - 52, (r9 - 2));
                        r2 = LD32(r13 + 20);
                        r1 = LD32(sp - 88);
                        r6 = LD32(r13 + 16);
                        r11 = (r2 - r1) - 2;
                        r5 = LD16((r13 + 12));
                        ST32((sp - 100), 1);
                        ST32((sp - 104), 2);
                        ST32((sp - 108), -1);
                        ST32((sp - 112), r2);
                        r0 = GCALL8(0x060153C8, r14, r5, r6, r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        r8 = r13 + 46;
                        r1 = LD16(r8);
                        if (!(r1 == 1)) {
                            r9 = r9 - 1;
                            r10 = 0;
                            r7 = LD16(r12);
                            r2 = LD32(r13 + 16);
                            ST32((sp - 100), 0);
                            ST32((sp - 104), 2);
                            ST32((sp - 108), -1);
                            r1 = LD32(sp - 88);
                            ST32((sp - 112), ((r2 + r1) + 2));
                            r0 = GCALL8(0x060153C8, r14, r9, (r2 + 2), (r7 - 2), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            r1 = LD32(r13 + 16);
                            ST32((sp - 116), 0);
                            r2 = LD32(sp - 88);
                            r7 = r1;
                            ST32((sp - 120), ((r1 + r2) + 2));
                            r1 = LD16(r12);
                            ST32((sp - 124), (r1 - 2));
                            r0 = GCALL8(0x06035264, r14, 0, r9, (r7 + 2), LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                            r7 = LD16(r12);
                            r1 = LD32(sp - 88);
                            ST32((sp - 128), 0);
                            ST32((sp - 132), 2);
                            ST32((sp - 136), -1);
                            ST32((sp - 140), r11);
                            r0 = GCALL8(0x060153C8, r14, r9, (r11 - r1), (r7 - 2), LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                            r1 = LD32(sp - 88);
                            r7 = r11 - r1;
                            ST32((sp - 100), 0);
                            ST32((sp - 104), r11);
                            r1 = LD16(r12);
                            ST32((sp - 108), (r1 - 2));
                            r0 = GCALL7(0x06035264, r14, 1, r9, r7, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            r2 = LD16(r8);
                            if (r2 > 4) {
                                r7 = LD16(r12);
                                r2 = LD32(sp - 88);
                                r1 = LD32(r13 + 16);
                                ST32((sp - 100), r10);
                                ST32((sp - 104), 2);
                                ST32((sp - 108), -1);
                                ST32((sp - 112), ((r1 + (r2 + r2)) + 4));
                                r0 = GCALL8(0x060153C8, r14, r9, ((r2 + 4) + r1), (r7 - 2), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                                r2 = LD32(sp - 88);
                                ST32((76 + (sp - 112)), (r2 + 4));
                                r1 = LD32(r13 + 16);
                                r7 = LD32(76 + (sp - 112));
                                r7 = r7 + r1;
                                ST32((sp - 116), r10);
                                ST32((sp - 120), ((r1 + (r2 + r2)) + 4));
                                r1 = LD16(r12);
                                ST32((sp - 124), (r1 - 2));
                                r0 = GCALL8(0x06035264, r14, 1, r9, r7, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                                r8 = r11 - 2;
                                r7 = LD16(r12);
                                r2 = LD32(sp - 88);
                                ST32((sp - 128), r10);
                                ST32((sp - 132), 2);
                                ST32((sp - 136), -1);
                                ST32((sp - 140), ((r11 - r2) - 2));
                                r0 = GCALL8(0x060153C8, r14, r9, (r8 - (r2 + r2)), (r7 - 2), LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                                r2 = LD32(sp - 88);
                                ST32((sp - 100), r10);
                                ST32((sp - 104), ((r11 - r2) - 2));
                                r1 = LD16(r12);
                                ST32((sp - 108), (r1 - 2));
                                r0 = GCALL7(0x06035264, r14, 0, r9, (r8 - (r2 + r2)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            }
                        } else {
                            r9 = r9 - 1;
                            r7 = LD16(r12);
                            r1 = LD32(sp - 92);
                            r2 = LD32(r13 + 16);
                            r7 = (r7 - 2) - (r1 + r1);
                            ST32((sp - 100), 0);
                            ST32((sp - 104), 2);
                            ST32((sp - 108), -1);
                            r1 = LD32(sp - 88);
                            ST32((sp - 112), ((r2 + r1) + 2));
                            r0 = GCALL8(0x060153C8, r14, r9, (r2 + 2), r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            r1 = LD32(r13 + 16);
                            ST32((sp - 116), 0);
                            r2 = LD32(sp - 88);
                            ST32((sp - 120), ((r1 + r2) + 2));
                            r2 = LD16(r12);
                            r7 = r1 + 2;
                            r1 = LD32(sp - 92);
                            ST32((sp - 124), ((r2 - 2) - (r1 + r1)));
                            r0 = GCALL8(0x06035264, r14, 0, r9, r7, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                            r5 = LD16(r12);
                            r2 = LD32(r13 + 16);
                            r1 = LD32(sp - 92);
                            r7 = r5 - 2;
                            r5 = (r5 - (r1 + r1)) - 2;
                            ST32((sp - 128), 0);
                            ST32((sp - 132), 2);
                            ST32((sp - 136), -1);
                            r1 = LD32(sp - 88);
                            ST32((sp - 140), ((r2 + r1) + 2));
                            r0 = GCALL8(0x060153C8, r14, r5, (r2 + 2), r7, LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                            r2 = LD32(r13 + 16);
                            r12 = LD16(r12);
                            r1 = LD32(sp - 92);
                            ST32(sp - 36, r12);
                            r6 = r12 - (r1 + r1);
                            ST32((sp - 100), 0);
                            r1 = LD32(sp - 88);
                            ST32((sp - 104), ((r2 + r1) + 2));
                            r3 = 68 + (sp - 104);
                            r0 = LD32(r3);
                            ST32(r3, (r0 - 2));
                            r3 = LD32((68 + (sp - 104)));
                            ST32((sp - 108), r3);
                            r0 = GCALL7(0x06035264, r14, 1, (r6 - 2), (r2 + 2), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        }
                        r0 = r13 + 44;
                        ST32(sp - 40, r0);
                        r1 = LD16(r0);
                        r8 = r13;
                        if (!(r1 == 1)) {
                            r8 = r8 + 12;
                            r11 = r11 + 1;
                            r9 = 0;
                            r10 = 2;
                            r12 = -1;
                            r1 = LD32(sp - 92);
                            r5 = LD16(r8);
                            r7 = (r5 + (r1 + r1)) + 2;
                            ST32((sp - 100), 0);
                            ST32((sp - 104), 2);
                            ST32((sp - 108), -1);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 112), (r1 - 2));
                            r0 = GCALL8(0x060153C8, r14, (r5 + 2), r11, r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            r2 = LD16(r8);
                            ST32((sp - 116), 0);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 120), (r1 - 2));
                            r1 = LD32(sp - 92);
                            ST32((sp - 124), ((r2 + (r1 + r1)) + 2));
                            r0 = GCALL8(0x06035264, r14, 2, (r2 + 2), r11, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                            r1 = LD32(sp - 92);
                            r5 = LD32((72 + (sp - 124)));
                            r5 = r5 - (r1 + r1);
                            ST32((sp - 128), 0);
                            ST32((sp - 132), 2);
                            ST32((sp - 136), -1);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 140), (r1 - 2));
                            r7 = LD32((88 + (sp - 140)));
                            r0 = GCALL8(0x060153C8, r14, r5, r11, r7, LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                            r1 = LD32(sp - 92);
                            r6 = LD32(sp - 52);
                            r6 = r6 - (r1 + r1);
                            ST32((sp - 100), 0);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 104), (r1 - 2));
                            r0 = LD32(sp - 52);
                            ST32((sp - 108), r0);
                            r0 = GCALL7(0x06035264, r14, 3, r6, r11, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            r0 = LD32(sp - 40);
                            r2 = LD16(r0);
                            r6 = r11;
                            if (r2 > 9) {
                                r1 = LD32(sp - 92);
                                r5 = LD16(r8);
                                r7 = (r5 + (r1 << 2)) + 6;
                                r5 = r5 + (r1 + r1);
                                ST32((sp - 100), r9);
                                ST32((sp - 104), r10);
                                ST32((sp - 108), r12);
                                r1 = LD32(r13 + 20);
                                ST32((sp - 112), (r1 - 2));
                                r0 = GCALL8(0x060153C8, r14, (r5 + 4), r6, r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                                r2 = LD16(r8);
                                r3 = LD32(sp - 92);
                                ST32((76 + (sp - 112)), r3);
                                r1 = LD32(76 + (sp - 112));
                                r6 = r2 + (r1 + r1);
                                ST32((sp - 116), r9);
                                r1 = LD32(r13 + 20);
                                ST32((sp - 120), (r1 - 2));
                                r3 = 84 + (sp - 120);
                                r0 = LD32(r3);
                                ST32(r3, (r0 << 2));
                                r3 = LD32((84 + (sp - 120)));
                                ST32((sp - 124), ((r2 + r3) + 6));
                                r0 = GCALL8(0x06035264, r14, 3, (r6 + 4), r11, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                                r8 = LD32((72 + (sp - 124)));
                                r1 = LD32(sp - 92);
                                r8 = r8 - 2;
                                r2 = r1 + r1;
                                r5 = r8 - (r1 << 2);
                                ST32((sp - 128), r9);
                                ST32((sp - 132), r10);
                                ST32((sp - 136), r12);
                                r1 = LD32(r13 + 20);
                                ST32((sp - 140), (r1 - 2));
                                r0 = GCALL8(0x060153C8, r14, r5, r11, (r8 - r2), LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                                r2 = LD32(sp - 92);
                                ST32((sp - 100), r9);
                                r1 = LD32(r13 + 20);
                                ST32((sp - 104), (r1 - 2));
                                ST32((sp - 108), (r8 - (r2 + r2)));
                                r0 = GCALL7(0x06035264, r14, r10, (r8 - (r2 << 2)), r11, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            }
                        } else {
                            r10 = r13 + 12;
                            r11 = r11 + 1;
                            r1 = LD32(sp - 92);
                            r5 = LD16(r10);
                            r7 = (r5 + (r1 + r1)) + 2;
                            ST32((sp - 100), 0);
                            ST32((sp - 104), 2);
                            ST32((sp - 108), -1);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 112), (r1 - 2));
                            r0 = GCALL8(0x060153C8, r14, (r5 + 2), r11, r7, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                            r2 = LD16(r10);
                            ST32((sp - 116), 0);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 120), (r1 - 2));
                            r1 = LD32(sp - 92);
                            ST32((sp - 124), ((r2 + (r1 + r1)) + 2));
                            r0 = GCALL8(0x06035264, r14, 2, (r2 + 2), r11, LD32((sp - 124)), LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)));
                            r1 = LD32(sp - 92);
                            r5 = LD16(r10);
                            r7 = (r5 + (r1 << 2)) + 2;
                            r5 = r5 + (r1 + r1);
                            ST32((sp - 128), 0);
                            ST32((sp - 132), 2);
                            ST32((sp - 136), -1);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 140), (r1 - 2));
                            r0 = GCALL8(0x060153C8, r14, (r5 + 2), r11, r7, LD32((sp - 140)), LD32((sp - 136)), LD32((sp - 132)), LD32((sp - 128)));
                            r2 = LD16(r10);
                            r0 = LD32(sp - 92);
                            ST32(sp - 36, r0);
                            r6 = r2 + (r0 + r0);
                            ST32((sp - 100), 0);
                            r1 = LD32(r13 + 20);
                            ST32((sp - 104), (r1 - 2));
                            r3 = 68 + (sp - 104);
                            r0 = LD32(r3);
                            ST32(r3, (r0 << 2));
                            r3 = LD32((68 + (sp - 104)));
                            ST32((sp - 108), ((r2 + r3) + 2));
                            r0 = GCALL7(0x06035264, r14, 3, (r6 + 2), r11, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                        }
                    }
                }
                r3 = LD32(sp - 64);
                ST32(r14 + 136, r3);
                r0 = GCALL2(0x060350B0, r14, (sp - 96));
                r0 = LD32(sp - 84);
            }
        }
    } else {
        r0 = GCALL2(0x060350B0, r14, (sp - 96));
        r0 = LD32(sp - 84);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036C40(int r4, int r5)
{
    int r1, c0, c1;

    c0 = (r5 & r5) == 0;
    r5 = r5 + 64;
    if (!(c0)) {
        r1 = LD32(r5);
        c1 = (r1 & r1) == 0;
        r1 = 0;
        if (c1) {
            ST32(r5, 1);
        } else {
            ST32(r5, r1);
        }
        return 1;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036D78(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12;
    FRAME(sp, 292);

    r12 = r4;
    r11 = r5;
    r8 = r6;
    r9 = r7;
    r4 = LD32(r8 + 36);
    r10 = LD32((0x118 + (sp - 280)));
    if ((r4 & r4) == 0) {
        r0 = GCALL4(0x06045264, (sp - 280), 0x06036D6C, r9, r10);
    } else {
        r0 = GCALL1(0x0607507C, r4);
        if ((r0 & r0) == 0) {
            r0 = GCALL4(0x06045264, (sp - 280), 0x06036D6C, r9, r10);
        } else {
            r6 = LD32(r8 + 36);
            ST32((sp - 284), r10);
            ST32((sp - 288), r6);
            r0 = GCALL6(0x06045264, (sp - 280), 0x06036D58, r6, r9, LD32((sp - 288)), LD32((sp - 284)));
        }
    }
    ST32(0x0607668C, 2);
    r6 = LD32((r8 + 72));
    ST32((sp - 284), r8);
    ST32((sp - 288), 0);
    ST32((sp - 292), 0);
    r0 = GCALL7(0x060384AC, r12, r11, r6, (sp - 280), LD32((sp - 292)), LD32((sp - 288)), LD32((sp - 284)));
    ST32(0x0607668C, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06036E1C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, c3;

    r8 = LD32(0x06088028);
    if (!((r8 & r8) == 0)) {
        r1 = LD32(r8);
        if ((r1 & r1) == 0) {
            r0 = LD32(r8 + 32);
            c3 = r0 == 4;
            if (r0 == 8) {
                r6 = LD32(r8 + 56);
                r5 = LD32(r8 + 52);
                r0 = GCALL4(0x06027C18, 0, r5, (r6 + 20), r7);
                if (!((r0 & r0) == 0)) {
                    ST32(r8 + 52, r0);
                    r1 = LD32((r8 + 88));
                    ST32(r1 + 20, r0);
                    r1 = LD32(r8 + 56);
                    ST32(r8 + 56, (r1 + 20));
                }
            } else {
                if (c3) {
                    r6 = LD32(r8 + 56);
                    r5 = LD32(r8 + 52);
                    r0 = GCALL4(0x06027C18, 0, r5, (r6 + 20), r7);
                    if (!((r0 & r0) == 0)) {
                        ST32(r8 + 52, r0);
                        r1 = LD32((r8 + 88));
                        ST32(r1 + 20, r0);
                        r1 = LD32(r8 + 56);
                        ST32(r8 + 56, (r1 + 20));
                    }
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037C2C(int r4, int r5, int r6)
{
    int r0, r1, r2, r7, c3;
    int v8;

    r2 = r5;
    r5 = LD32(r6 + 32);
    if ((r5 & r5) == 0) {
        r0 = 0;
    } else {
        r0 = LD32(r5);
        r1 = 1;
        if (r0 == 1) {
            r7 = LD32(r6 + 24);
            r0 = 0x060372AC;
            r6 = LD16((r6 + 8));
            r0 = GCALL4(r0, r4, r5, r6, r7);
            r0 = 1;
        } else {
            c3 = (r0 & r0) == 0;
            if (r0 > r1) {
                r1 = r6;
                if (r0 == 2) {
                    r7 = LD32(r6 + 24);
                    r6 = LD16((r1 + 8));
                    r0 = 0x06037924;
                    r0 = GCALL4(r0, r4, r5, r6, r7);
                    r0 = 1;
                } else {
                    r0 = 1;
                }
            } else {
                r1 = r6;
                if (c3) {
                    r7 = LD16((r1 + 8));
                    r1 = LD32(r6 + 24);
                    r0 = GCALL5(0x06037108, r4, 0, r5, r7, r1);
                } else {
                    r0 = 1;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037E74(int r4, int r5)
{
    int r0, r1, r8, r9, r10, r11, r12, c3;

    r8 = LD32(r5);
    r9 = r4;
    if (!((r8 & r8) == 0)) {
        r12 = 0x06037C9C;
        r11 = 0x06037DBC;
        r10 = 0x06037DD0;
        do {
            r0 = LD32(r8);
            r1 = 1;
            if (r0 == 1) {
                r0 = GCALL2(r11, r9, r8);
                r8 = LD32(r8 + 4);
            } else {
                c3 = (r0 & r0) == 0;
                if (r0 > r1) {
                    r5 = r8;
                    if (r0 == 2) {
                        r0 = GCALL2(r10, r9, r5);
                        r8 = LD32(r8 + 4);
                    } else {
                        r8 = LD32(r8 + 4);
                    }
                } else {
                    r5 = r8;
                    if (c3) {
                        r0 = GCALL2(r12, r9, r5);
                        r8 = LD32(r8 + 4);
                    } else {
                        r8 = LD32(r8 + 4);
                    }
                }
            }
        } while (AGAIN(!((r8 & r8) == 0)));
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037FBC(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r11, c1, c3, c5, c7;

    r8 = r4;
    r10 = r5;
    r1 = LD32(r8 + 12);
    r11 = r6;
    if (!((r1 & r1) == 0)) {
        r5 = r10;
        if ((r10 & r10) == 0) {
            r0 = 0;
        } else {
            r9 = 0x06037EE8;
            r0 = GCALL2(0x06037EE8, r8, r5);
            c3 = (r0 & r0) == 0;
            r0 = 0;
            if (!(c3)) {
                r0 = GCALL2(r9, r8, 0x06037FB8);
                c5 = (r11 & r11) == 0;
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r5 = r11;
                    if (c5) {
                        r1 = LD32(r8 + 12);
                        c7 = (r1 & r1) == 0;
                        r1 = 0;
                        if (!(c7)) {
                            ST32(r8 + 12, r1);
                        }
                        r0 = 1;
                    } else {
                        r0 = GCALL2(r9, r8, r5);
                        if (!((r0 & r0) == 0)) {
                            r1 = LD32(r8 + 12);
                            c7 = (r1 & r1) == 0;
                            r1 = 0;
                            if (!(c7)) {
                                ST32(r8 + 12, r1);
                            }
                            r0 = 1;
                        } else {
                            r0 = 0;
                        }
                    }
                }
            }
        }
    } else {
        r0 = GCALL2(0x06037EE8, r4, 0x06037FB4);
        c1 = (r0 & r0) == 0;
        r0 = 0;
        if (!(c1)) {
            r5 = r10;
            if ((r10 & r10) == 0) {
                r0 = 0;
            } else {
                r9 = 0x06037EE8;
                r0 = GCALL2(0x06037EE8, r8, r5);
                c3 = (r0 & r0) == 0;
                r0 = 0;
                if (!(c3)) {
                    r0 = GCALL2(r9, r8, 0x06037FB8);
                    c5 = (r11 & r11) == 0;
                    if ((r0 & r0) == 0) {
                        r0 = 0;
                    } else {
                        r5 = r11;
                        if (c5) {
                            r1 = LD32(r8 + 12);
                            c7 = (r1 & r1) == 0;
                            r1 = 0;
                            if (!(c7)) {
                                ST32(r8 + 12, r1);
                            }
                            r0 = 1;
                        } else {
                            r0 = GCALL2(r9, r8, r5);
                            if (!((r0 & r0) == 0)) {
                                r1 = LD32(r8 + 12);
                                c7 = (r1 & r1) == 0;
                                r1 = 0;
                                if (!(c7)) {
                                    ST32(r8 + 12, r1);
                                }
                                r0 = 1;
                            } else {
                                r0 = 0;
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
int f06038DF4(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, c0;

    r9 = r4;
    r13 = r5;
    r0 = GCALL1(0x06038F58, r4);
    c0 = (r0 & r0) == 0;
    r0 = -3;
    if (c0) {
        r10 = 0;
        r8 = 1;
        r12 = 0x06039B14;
        r11 = 0x1DEC;
        do {
            r0 = GCALL1(r12, r9);
            r1 = LD32(r9 + r11);
            r3 = r8 << 2;
            ST32(r3 + r1, r0);
            r1 = LD32(r9 + r11);
            r1 = LD32(r3 + r1);
            r8 = r8 + 1;
            r10 = r10 + r1;
        } while (AGAIN(!(r8 > 16)));
        r8 = 0;
        if (!(0 >= r10)) {
            r12 = 0x06039B14;
            r11 = 0x1DEC;
            do {
                r0 = GCALL1(r12, r9);
                r2 = LD32(r9 + r11);
                r1 = r8 << 2;
                r8 = r8 + 1;
                ST32((r2 + r1) + 144, r0);
            } while (AGAIN(!(r8 >= r10)));
        }
        r0 = GCALL1(0x06038C8C, r9);
        r0 = GCALL1(0x06038CE8, r9);
        r0 = GCALL1(0x06038D40, r9);
        ST32(r13, r10);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A9AC(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, c2, c4;

    r0 = r4;
    r2 = LD32(r0 + 0x1DE4);
    r1 = LD32(r2 + 12);
    r9 = (r1 << 2) + (r1 << 2);
    r1 = LD32(r2 + 16);
    r6 = (r1 << 2) + (r1 << 2);
    r1 = LD32(r2 + 24);
    r5 = 0;
    r8 = 0x1DE4;
    if (!(0 >= ((r1 << 2) + (r1 << 2)))) {
        r0 = r4;
        do {
            r1 = LD32(r0 + r8);
            r1 = LD32(r1 + 32);
            c2 = r6 >= r1;
            if (!((r1 & r1) == 0)) {
                r2 = r6;
                if (c2) {
                    r2 = r1 - 1;
                }
                r6 = r2;
                r0 = r4;
            }
            r1 = LD32(r0 + r8);
            r3 = r5 << 2;
            r1 = LD32(r1 + 40);
            r1 = LD32(r3 + r1);
            r2 = LD32(r1 + 20);
            ST32(r1 + 24, r2);
            ST32(r1 + 28, r2);
            r1 = LD32(r4 + r8);
            r2 = LD32(r1 + 40);
            r1 = LD32(r1 + 8);
            r2 = LD32(r3 + r2);
            ST32(r2 + 12, (r9 * r1));
            r2 = LD32(r4 + r8);
            r1 = LD32(r2 + 40);
            r7 = LD32(r3 + r1);
            r1 = LD32(r2 + 28);
            c4 = r6 * r1;
            r1 = LD32(r2 + 8);
            ST32(r7 + 16, (c4 * r1));
            r0 = r4;
            r1 = LD32(r0 + r8);
            r5 = r5 + 1;
            r1 = LD32(r1 + 24);
            r6 = r6 + 1;
        } while (AGAIN(!(r5 >= ((r1 << 2) + (r1 << 2)))));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603CCE0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12;

    r10 = r4;
    r11 = r5;
    r9 = LD32(r10);
    r0 = GCALL1(0x0607507C, r11);
    r8 = r0 + 1;
    if (r8 > 0) {
        r2 = LD32(0x060767CC);
        if ((r2 & r2) == 0) {
            if (!((r9 & r9) == 0)) {
                r0 = GCALL4(0x06027F48, r9, r5, r6, r7);
            }
            r9 = 0x060279E0;
            r0 = GCALL4(0x060279E0, 0, r8, 9, 1);
            ST32(r10, r0);
            if ((r0 & r0) == 0) {
                r0 = GCALL4(r9, 1, r8, 9, 1);
                ST32(r10, r0);
            }
            r1 = LD32(r10);
            if (!((r1 & r1) == 0)) {
                r2 = LD32(0x060767CC);
                if ((r2 & r2) == 0) {
                    r4 = LD32(r10);
                    r0 = GCALL2(0x060750DC, r4, r11);
                } else {
                    r1 = LD32(r10);
                    if (r2 == r1) {
                        r0 = (SR() & ~1) | 1;
                        r12 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
                        r0 = (SR() & ~1) | 1;
                        r9 = -241;
                        SETSR((r0 | 240));
                        r8 = LD32(0x0608AB68);
                        r2 = r8;
                        if (!((r8 & r8) == 0)) {
                            ST16((r2 + 26), 0);
                            r0 = GCALL1(0x0607507C, r11);
                            ST16((r8 + 24), r0);
                        }
                        r4 = LD32(r10);
                        r0 = GCALL2(0x060750DC, r4, r11);
                        r1 = SR();
                        SETSR(((r1 & r9) | ((r12 << 2) << 2)));
                    } else {
                        r4 = LD32(r10);
                        r0 = GCALL2(0x060750DC, r4, r11);
                    }
                }
            }
        } else {
            r1 = LD32(r10);
            if (r2 == r1) {
                if (r8 > 0x1000) {
                    r0 = GCALL1(0x0602BA00, 0x0603CCC4);
                    r0 = GCALL1(0x0602BA00, 0x0603CCC4);
                    r0 = GCALL1(0x0602BA00, 0x0603CCC4);
                    r0 = GCALL1(0x0602BA00, 0x0603CCC4);
                    r0 = GCALL1(0x0602BA00, 0x0603CCC4);
                    r0 = GCALL1(0x0602BA00, 0x0603CCC4);
                    r0 = GCALL1(0x0602BA00, 0x0603CCC4);
                    r0 = GCALL1(0x0602BA00, 0x0603CCC4);
                    r0 = GCALL1(0x0602BA00, 0x0603CCC4);
                    while (1) {
                        POLL();
                    }
                }
                r2 = LD32(0x060767CC);
                if ((r2 & r2) == 0) {
                    r4 = LD32(r10);
                    r0 = GCALL2(0x060750DC, r4, r11);
                } else {
                    r1 = LD32(r10);
                    if (r2 == r1) {
                        r0 = (SR() & ~1) | 1;
                        r12 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
                        r0 = (SR() & ~1) | 1;
                        r9 = -241;
                        SETSR((r0 | 240));
                        r8 = LD32(0x0608AB68);
                        r2 = r8;
                        if (!((r8 & r8) == 0)) {
                            ST16((r2 + 26), 0);
                            r0 = GCALL1(0x0607507C, r11);
                            ST16((r8 + 24), r0);
                        }
                        r4 = LD32(r10);
                        r0 = GCALL2(0x060750DC, r4, r11);
                        r1 = SR();
                        SETSR(((r1 & r9) | ((r12 << 2) << 2)));
                    } else {
                        r4 = LD32(r10);
                        r0 = GCALL2(0x060750DC, r4, r11);
                    }
                }
            } else {
                if (!((r9 & r9) == 0)) {
                    r0 = GCALL4(0x06027F48, r9, r5, r6, r7);
                }
                r9 = 0x060279E0;
                r0 = GCALL4(0x060279E0, 0, r8, 9, 1);
                ST32(r10, r0);
                if ((r0 & r0) == 0) {
                    r0 = GCALL4(r9, 1, r8, 9, 1);
                    ST32(r10, r0);
                }
                r1 = LD32(r10);
                if (!((r1 & r1) == 0)) {
                    r2 = LD32(0x060767CC);
                    if ((r2 & r2) == 0) {
                        r4 = LD32(r10);
                        r0 = GCALL2(0x060750DC, r4, r11);
                    } else {
                        r1 = LD32(r10);
                        if (r2 == r1) {
                            r0 = (SR() & ~1) | 1;
                            r12 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
                            r0 = (SR() & ~1) | 1;
                            r9 = -241;
                            SETSR((r0 | 240));
                            r8 = LD32(0x0608AB68);
                            r2 = r8;
                            if (!((r8 & r8) == 0)) {
                                ST16((r2 + 26), 0);
                                r0 = GCALL1(0x0607507C, r11);
                                ST16((r8 + 24), r0);
                            }
                            r4 = LD32(r10);
                            r0 = GCALL2(0x060750DC, r4, r11);
                            r1 = SR();
                            SETSR(((r1 & r9) | ((r12 << 2) << 2)));
                        } else {
                            r4 = LD32(r10);
                            r0 = GCALL2(0x060750DC, r4, r11);
                        }
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603D3DC(int r4, int r5)
{
    int r0, r1, r6, r8, r9, r10, r11, c17;

    r8 = r5;
    r10 = r4;
    if (!((r8 & r8) == 0)) {
        r1 = LD8(r8);
        if (!((r1 & 255) == 13)) {
            r9 = 0x06075238;
            r11 = r8 + 1;
            while (1) {
                r6 = 5;
                if (((r1 & 255) & (r1 & 255)) == 0) {
                    break;
                } else {
                    r0 = GCALL3(r9, r8, 0x0603D330, r6);
                    r6 = 4;
                    if ((r0 & r0) == 0) {
                        POLL();
                        r1 = 3;
                        POLL();
                        ST32(r10 + 44, r1);
                        break;
                    } else {
                        r0 = GCALL3(r9, r8, 0x0603D338, r6);
                        r6 = 5;
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL3(r9, r8, 0x0603D348, r6);
                            r6 = 43;
                            if ((r0 & r0) == 0) {
                                POLL();
                                r1 = 4;
                                POLL();
                                ST32(r10 + 44, r1);
                                break;
                            } else {
                                r0 = GCALL3(r9, r8, 0x0603D350, r6);
                                r6 = 38;
                                if ((r0 & r0) == 0) {
                                    POLL();
                                    r1 = 5;
                                    ST32(r10 + 44, r1);
                                    break;
                                } else {
                                    r0 = GCALL3(r9, r8, 0x0603D37C, r6);
                                    r6 = 11;
                                    if ((r0 & r0) == 0) {
                                        POLL();
                                        r1 = 7;
                                        POLL();
                                        ST32(r10 + 44, r1);
                                        break;
                                    } else {
                                        r0 = GCALL3(r9, r8, 0x0603D3A4, r6);
                                        r6 = 5;
                                        if ((r0 & r0) == 0) {
                                            POLL();
                                            r1 = 6;
                                            POLL();
                                            ST32(r10 + 44, r1);
                                            break;
                                        } else {
                                            r0 = GCALL3(r9, r8, 0x0603D3B0, r6);
                                            r6 = 6;
                                            if ((r0 & r0) == 0) {
                                                POLL();
                                                r1 = 8;
                                                POLL();
                                                ST32(r10 + 44, r1);
                                                break;
                                            } else {
                                                r0 = GCALL3(r9, r8, 0x0603D3B8, r6);
                                                r6 = 3;
                                                if ((r0 & r0) == 0) {
                                                    POLL();
                                                    ST32(r10 + 44, 1);
                                                    break;
                                                } else {
                                                    r0 = GCALL3(r9, r8, 0x0603D3C0, r6);
                                                    r6 = 4;
                                                    if ((r0 & r0) == 0) {
                                                        POLL();
                                                        r1 = 3;
                                                        POLL();
                                                        ST32(r10 + 44, r1);
                                                        break;
                                                    } else {
                                                        r0 = GCALL3(r9, r8, 0x0603D3C4, r6);
                                                        r6 = 4;
                                                        if ((r0 & r0) == 0) {
                                                            POLL();
                                                            r1 = 4;
                                                            POLL();
                                                            ST32(r10 + 44, r1);
                                                            break;
                                                        } else {
                                                            r0 = GCALL3(r9, r8, 0x0603D3CC, r6);
                                                            r6 = 4;
                                                            if ((r0 & r0) == 0) {
                                                                POLL();
                                                                r1 = 4;
                                                                POLL();
                                                                ST32(r10 + 44, r1);
                                                                break;
                                                            } else {
                                                                r0 = GCALL3(r9, r8, 0x0603D3D4, r6);
                                                                if ((r0 & r0) == 0) {
                                                                    POLL();
                                                                    r1 = 4;
                                                                    POLL();
                                                                    ST32(r10 + 44, r1);
                                                                    break;
                                                                } else {
                                                                    r1 = LD8(r8);
                                                                    if (!((r1 & 255) == 255)) {
                                                                        r8 = r8 + 1;
                                                                        r1 = LD8(r8);
                                                                        r11 = r11 + 1;
                                                                        if (!((r1 & 255) == 13)) {
                                                                            POLL();
                                                                            continue;
                                                                        } else {
                                                                            break;
                                                                        }
                                                                    } else {
                                                                        r1 = LD8(r11);
                                                                        c17 = (r1 & 255) == 216;
                                                                        r1 = 3;
                                                                        if (c17) {
                                                                            POLL();
                                                                            ST32(r10 + 44, r1);
                                                                            break;
                                                                        } else {
                                                                            r8 = r8 + 1;
                                                                            r1 = LD8(r8);
                                                                            r11 = r11 + 1;
                                                                            if (!((r1 & 255) == 13)) {
                                                                                POLL();
                                                                                continue;
                                                                            } else {
                                                                                break;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            r0 = GCALL3(r9, (r8 + 5), 0x0603D340, 4);
                            r1 = 2;
                            if (!((r0 & r0) == 0)) {
                                POLL();
                                ST32(r10 + 44, r1);
                                break;
                            } else {
                                r1 = 1;
                                POLL();
                                ST32(r10 + 44, r1);
                                break;
                            }
                        }
                    }
                }
                POLL();
            }
        }
        r1 = LD32(r10 + 44);
        r0 = r8;
        if ((r1 & r1) == 0) {
            ST32(r10 + 44, 1);
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603E798(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14, c4;
    int v36;
    int v40;

    r11 = r4;
    r14 = r5;
    r12 = r7;
    v40 = r6;
    if (!((unsigned)r12 >= (unsigned)r6)) {
        v36 = r11 + 4;
        r0 = r14;
        while (1) {
            r10 = r12 + r14;
            r2 = LD8(r0 + r12);
            r1 = LD8((r10 + 1));
            r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
            r1 = LD8((r10 + 2));
            r2 = r2 + ((r1 & 255) << 8);
            r1 = LD8((r10 + 3));
            r8 = r2 + (r1 & 255);
            r2 = LD8((r10 + 4));
            r1 = LD8((r10 + 5));
            r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
            r1 = LD8((r10 + 6));
            r2 = r2 + ((r1 & 255) << 8);
            r1 = LD8((r10 + 7));
            r13 = r2 + (r1 & 255);
            r1 = r13;
            if (!((r13 & r13) == 0)) {
                if (!((unsigned)(((((int)((unsigned)(r1 + 1) >> 1)) + ((int)((unsigned)(r1 + 1) >> 1))) + r12) + 8) > (unsigned)v40)) {
                    r0 = GCALL6(0x0603E6E4, 0x0603E780, 0, 0, 0, v40, v36);
                    c4 = (r11 & r11) == 0;
                    if (!(r8 == r0)) {
                        r0 = GCALL6(0x0603E6E4, 0x0603E790, 0, 0, 0, v40, v36);
                        r2 = r12;
                        if (r8 == r0) {
                            r1 = r10;
                            if (!((r11 & r11) == 0)) {
                                r2 = LD8((r1 + 8));
                                r1 = LD8((r10 + 9));
                                r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
                                r1 = LD8((r10 + 10));
                                r2 = r2 + ((r1 & 255) << 8);
                                r1 = LD8((r10 + 11));
                                ST32(r11 + 20, (r14 + (((r2 + (r1 & 255)) + r12) + 16)));
                                r2 = r12;
                            }
                        }
                    } else {
                        r1 = r10;
                        if (!(c4)) {
                            r2 = LD8((r1 + 8));
                            r0 = v36;
                            r1 = LD8((r10 + 9));
                            ST16(r0, ((r1 & 255) + ((r2 & 255) << 8)));
                            r8 = LD8((r10 + 10));
                            r1 = LD8((r10 + 11));
                            r8 = ((r8 << 16) << 8) + ((r1 & 255) << 16);
                            r1 = LD8((r10 + 12));
                            r9 = r11 + 12;
                            r8 = r8 + ((r1 & 255) << 8);
                            r1 = LD8((r10 + 13));
                            r8 = r8 + (r1 & 255);
                            r2 = LD8((r10 + 14));
                            r1 = LD8((r10 + 15));
                            r1 = (r1 & 255) + ((r2 & 255) << 8);
                            ST16((r11 + 14), r1);
                            r1 = (((((short)r1) + 7) >> 1) >> 1) >> 1;
                            ST16((r11 + 16), r1);
                            r2 = LD16(r0);
                            ST16(r9, ((r1 & 0xFFFF) * r2));
                            r0 = GCALL6(0x0603E710, r14, (r12 + 16), 0, 0, v40, v36);
                            ST32(r11 + 8, r0);
                            r1 = LD16(r9);
                            ST32(r11 + 24, (r8 * r1));
                            if (!((unsigned)r13 > (unsigned)18)) {
                                r0 = GCALL6(0x0603E6E4, 0x0603E788, 0, 0, 0, v40, v36);
                                ST32(r11 + 28, r0);
                            } else {
                                r2 = LD8((r10 + 26));
                                r1 = LD8((r10 + 27));
                                r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
                                r1 = LD8((r10 + 28));
                                r2 = r2 + ((r1 & 255) << 8);
                                r1 = LD8((r10 + 29));
                                ST32(r11 + 28, (r2 + (r1 & 255)));
                            }
                        }
                        r2 = r12;
                    }
                    r12 = (r2 + 8) + (((int)((unsigned)(r13 + 1) >> 1)) + ((int)((unsigned)(r13 + 1) >> 1)));
                    r0 = r14;
                    if ((unsigned)r12 >= (unsigned)v40) {
                        break;
                    } else {
                        POLL();
                        continue;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
            POLL();
        }
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603E9B8(int r4, int r5)
{
    int r0, c0;

    r0 = GCALL3(0x0603EA7C, 0, r4, r5);
    c0 = (r0 & r0) == 0;
    r0 = 0;
    if (c0) {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603EC4C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14, c4, c7;

    r10 = r4;
    r14 = r6;
    r11 = r7;
    r13 = r5;
    if (!((unsigned)r11 >= (unsigned)r14)) {
        r0 = r13;
        while (1) {
            r8 = r11 + r13;
            r2 = LD8(r0 + r11);
            r1 = LD8((r8 + 1));
            r2 = (r2 & 255) + ((r1 & 255) << 8);
            r1 = LD8((r8 + 2));
            r2 = r2 + ((r1 & 255) << 16);
            r1 = LD8((r8 + 3));
            r9 = r2 + ((r1 << 16) << 8);
            r2 = LD8((r8 + 4));
            r1 = LD8((r8 + 5));
            r2 = (r2 & 255) + ((r1 & 255) << 8);
            r1 = LD8((r8 + 6));
            r2 = r2 + ((r1 & 255) << 16);
            r1 = LD8((r8 + 7));
            r12 = r2 + ((r1 << 16) << 8);
            r1 = r11;
            if ((r12 & r12) == 0) {
                break;
            } else {
                if ((unsigned)((r1 + r12) + 8) > (unsigned)r14) {
                    break;
                } else {
                    r0 = GCALL1(0x0603EC08, 0x0603EC34);
                    c4 = (r10 & r10) == 0;
                    if (!(r9 == r0)) {
                        r0 = GCALL1(0x0603EC08, 0x0603EC3C);
                        c7 = (r10 & r10) == 0;
                        if (!(r9 == r0)) {
                            r0 = GCALL1(0x0603EC08, 0x0603EC44);
                        } else {
                            if (!(c7)) {
                                ST32(r10 + 24, r12);
                                ST32(r10 + 20, ((r11 + 8) + r13));
                            }
                        }
                    } else {
                        r1 = r8;
                        if (!(c4)) {
                            r2 = LD8((r1 + 8));
                            r1 = LD8((r8 + 9));
                            r0 = (r2 & 255) | ((r1 & 255) << 8);
                            r2 = LD8((r8 + 10));
                            r1 = LD8((r8 + 11));
                            ST16((r10 + 4), ((r2 & 255) + ((r1 & 255) << 8)));
                            r2 = LD8((r8 + 12));
                            r1 = LD8((r8 + 13));
                            r2 = (r2 & 255) + ((r1 & 255) << 8);
                            r1 = LD8((r8 + 14));
                            r2 = r2 + ((r1 & 255) << 16);
                            r1 = LD8((r8 + 15));
                            ST32(r10 + 8, (r2 + ((r1 << 16) << 8)));
                            r2 = LD8((r8 + 20));
                            r1 = LD8((r8 + 21));
                            ST16((r10 + 12), ((r2 & 255) + ((r1 & 255) << 8)));
                            if (r0 == 1) {
                                r1 = LD8((r8 + 22));
                                r2 = LD8((r8 + 23));
                                r1 = (r1 & 255) + ((r2 & 255) << 8);
                                ST16((r10 + 14), r1);
                                ST16((r10 + 16), ((((((short)r1) + 7) >> 1) >> 1) >> 1));
                            }
                        }
                    }
                    r11 = (r11 + 8) + r12;
                    r0 = r13;
                    if ((unsigned)r11 >= (unsigned)r14) {
                        break;
                    }
                }
            }
            POLL();
        }
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603EDF4(int r4, int r5)
{
    int r0, c0;

    r0 = GCALL3(0x0603EE88, 0, r4, r5);
    c0 = (r0 & r0) == 0;
    r0 = 0;
    if (c0) {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603EE88(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14, c4, c5, c6;
    int v36;

    r9 = r4;
    r11 = r5;
    r12 = r6;
    r8 = 0;
    v36 = 0;
    r10 = 0;
    r13 = 0;
    r14 = 0;
    if (!((r9 & r9) == 0)) {
        r0 = GCALL5(0x0603F000, r4, 2, 0, 0, v36);
        ST16((r9 + 4), 1);
        ST32(r9 + 8, 0x5622);
        ST16((r9 + 12), 1);
        ST16((r9 + 14), 8);
        ST16((r9 + 16), 1);
    }
    while (1) {
        r0 = r11;
        if (!((unsigned)r8 >= (unsigned)r12)) {
            POLL();
            r3 = r8 + r11;
            r2 = LD8(r0 + r8);
            r1 = LD8((r3 + 1));
            r2 = (r2 & 255) + ((r1 & 255) << 8);
            r1 = LD8((r3 + 2));
            r2 = r2 + ((r1 & 255) << 16);
            r1 = LD8((r3 + 3));
            r2 = r2 + ((r1 << 16) << 8);
            r1 = r3;
            if (!((r2 & r2) == 0)) {
                v36 = r2;
                r2 = LD8((r1 + 4));
                r1 = LD8((r3 + 5));
                r2 = (r2 & 255) + ((r1 & 255) << 8);
                r1 = LD8((r3 + 6));
                r2 = r2 + ((r1 & 255) << 16);
                r1 = LD8((r3 + 7));
                r10 = r2 + ((r1 << 16) << 8);
                r2 = LD8((r3 + 8));
                r1 = LD8((r3 + 9));
                r2 = (r2 & 255) + ((r1 & 255) << 8);
                r1 = LD8((r3 + 10));
                r2 = r2 + ((r1 & 255) << 16);
                r1 = LD8((r3 + 11));
                r13 = r2 + ((r1 << 16) << 8);
            } else {
                r14 = 1;
            }
            r0 = GCALL5(0x0603EC08, 0x0603EE78, 0, 0, 0, v36);
            if (!(v36 == r0)) {
                r0 = -409;
                break;
            } else {
                r0 = GCALL5(0x0603EC08, 0x0603EE80, 0, 0, 0, v36);
                c4 = (r10 & r10) == 0;
                if (r13 == r0) {
                    c5 = (r14 & r14) == 0;
                    if (c4) {
                        r0 = 0;
                        break;
                    } else {
                        c6 = (r9 & r9) == 0;
                        if (!(c5)) {
                            r0 = 0;
                            break;
                        } else {
                            if (!(c6)) {
                                ST32(r9 + 24, r10);
                                ST32(r9 + 20, ((r8 + 8) + r11));
                            }
                            r7 = r8;
                            if ((unsigned)((r8 + r10) + 8) > (unsigned)r12) {
                                r0 = 0;
                                break;
                            } else {
                                r0 = GCALL5(0x0603EC4C, r9, r11, r12, (r7 + 12), v36);
                                r8 = r8 + (((int)((unsigned)(r10 + 9) >> 1)) + ((int)((unsigned)(r10 + 9) >> 1)));
                                continue;
                            }
                        }
                    }
                } else {
                    r0 = -409;
                    break;
                }
            }
        } else {
            r0 = 0;
            break;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603F020(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, c2, c5, c6;
    FRAME(sp, 52);

    r10 = r4;
    r8 = r6;
    r9 = r5;
    if ((r8 & r8) == 0) {
        r8 = sp - 52;
    }
    r0 = GCALL3(0x0603EA7C, r8, r10, r9);
    if (!((r0 & r0) == 0)) {
        r0 = GCALL3(0x0603EE88, r8, r10, r9);
        if (!((r0 & r0) == 0)) {
            r0 = GCALL3(0x06041134, r8, r10, r9);
            c5 = (r0 & r0) == 0;
            r0 = 0;
            if (c5) {
                r0 = GCALL1(0x060410CC, r8);
                c6 = (r0 & r0) == 0;
                r0 = 0;
                if (c6) {
                    r1 = 0;
                    ST32(r8, r1);
                    r0 = 1;
                }
            }
        } else {
            r0 = GCALL1(0x0603EE14, r8);
            r1 = 2;
            if ((r0 & r0) == 0) {
                ST32(r8, r1);
                r0 = 1;
            } else {
                r0 = GCALL3(0x06041134, r8, r10, r9);
                c5 = (r0 & r0) == 0;
                r0 = 0;
                if (c5) {
                    r0 = GCALL1(0x060410CC, r8);
                    c6 = (r0 & r0) == 0;
                    r0 = 0;
                    if (c6) {
                        r1 = 0;
                        ST32(r8, r1);
                        r0 = 1;
                    }
                }
            }
        }
    } else {
        r0 = GCALL1(0x0603E9D8, r8);
        c2 = (r0 & r0) == 0;
        r2 = c2;
        if (!(c2)) {
            r0 = GCALL3(0x0603EE88, r8, r10, r9);
            if (!((r0 & r0) == 0)) {
                r0 = GCALL3(0x06041134, r8, r10, r9);
                c5 = (r0 & r0) == 0;
                r0 = 0;
                if (c5) {
                    r0 = GCALL1(0x060410CC, r8);
                    c6 = (r0 & r0) == 0;
                    r0 = 0;
                    if (c6) {
                        r1 = 0;
                        ST32(r8, r1);
                        r0 = 1;
                    }
                }
            } else {
                r0 = GCALL1(0x0603EE14, r8);
                r1 = 2;
                if ((r0 & r0) == 0) {
                    ST32(r8, r1);
                    r0 = 1;
                } else {
                    r0 = GCALL3(0x06041134, r8, r10, r9);
                    c5 = (r0 & r0) == 0;
                    r0 = 0;
                    if (c5) {
                        r0 = GCALL1(0x060410CC, r8);
                        c6 = (r0 & r0) == 0;
                        r0 = 0;
                        if (c6) {
                            r1 = 0;
                            ST32(r8, r1);
                            r0 = 1;
                        }
                    }
                }
            }
        } else {
            ST32(r8, r2);
            r0 = 1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603F1AC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10;

    r8 = r4;
    r1 = LD32(r8 + 4);
    r9 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL1(0x0607507C, r9);
        r1 = LD32(r8 + 12);
        r6 = LD32(r8 + 8);
        if (!((unsigned)((r1 + r0) + 1) > (unsigned)r6)) {
            r4 = LD32(r8 + 4);
            r1 = LD32(r8 + 12);
            r0 = GCALL2(0x060750DC, (r4 + r1), r9);
            r0 = GCALL1(0x0607507C, r9);
            r1 = LD32(r8 + 12);
            ST32(r8 + 12, (r1 + r0));
            r0 = 0;
        } else {
            r5 = LD32(r8 + 4);
            r10 = 0x200;
            r0 = GCALL4(0x06027C18, 0, r5, (r6 + 0x200), r7);
            ST32(r8 + 4, r0);
            if (!((r0 & r0) == 0)) {
                r1 = LD32(r8 + 8);
                ST32(r8 + 8, (r1 + r10));
                r4 = LD32(r8 + 4);
                r1 = LD32(r8 + 12);
                r0 = GCALL2(0x060750DC, (r4 + r1), r9);
                r0 = GCALL1(0x0607507C, r9);
                r1 = LD32(r8 + 12);
                ST32(r8 + 12, (r1 + r0));
                r0 = 0;
            } else {
                r0 = -3;
            }
        }
    } else {
        r10 = 0x200;
        r0 = GCALL4(0x060279E0, 1, 0x200, 15, 1);
        ST32(r8 + 4, r0);
        if ((r0 & r0) == 0) {
            r0 = -3;
        } else {
            ST32(r8 + 8, r10);
            ST32(r8 + 12, 0);
            r4 = LD32(r8 + 4);
            r1 = LD32(r8 + 12);
            r0 = GCALL2(0x060750DC, (r4 + r1), r9);
            r0 = GCALL1(0x0607507C, r9);
            r1 = LD32(r8 + 12);
            ST32(r8 + 12, (r1 + r0));
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603F240(int r4, int r5)
{
    int r0, r1, r2, c2, c3, c5, c6;

    r2 = 0;
    if (!((r4 & r4) == 0)) {
        r1 = LD8(r5);
        r0 = r1 & 255;
        while (1) {
            c5 = r0 == 13;
            if (r0 == 10) {
                break;
            } else {
                c6 = (r0 & r0) == 0;
                if (!(c5)) {
                    POLL();
                    if (c6) {
                        break;
                    } else {
                        r1 = LD8(r5);
                        r5 = r5 + 1;
                        r2 = r2 + 1;
                        ST8(r4, r1);
                        r0 = r1 & 255;
                        r4 = r4 + 1;
                        continue;
                    }
                } else {
                    break;
                }
            }
        }
        r1 = 0;
        if (!((r0 & r0) == 0)) {
            ST8(r4, r1);
        }
    } else {
        r1 = LD8(r5);
        while (1) {
            r0 = r1 & 255;
            c2 = r0 == 13;
            if (r0 == 10) {
                break;
            } else {
                c3 = (r0 & r0) == 0;
                if (c2) {
                    break;
                } else {
                    if (c3) {
                        break;
                    } else {
                        r1 = LD8(r5);
                        r5 = r5 + 1;
                        r2 = r2 + 1;
                    }
                }
            }
            POLL();
        }
    }
    return r2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06031448(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r12, r13, r14;
    FRAME(sp, 40);

    r14 = sp - 40;
    r9 = r5;
    r10 = r6;
    ST16(r14, r9);
    r12 = r14 + 2;
    ST16(r12, r10);
    r13 = (((short)r4) << 2) + (((short)r4) << 2);
    r8 = r13 + 0x06078054;
    r1 = LD16((r8 + 4));
    ST16((r14 + 4), ((r1 + r9) - 1));
    r1 = LD16((r8 + 6));
    ST16((r14 + 6), ((r1 + r10) - 1));
    r0 = GCALL2(0x060689BC, 0, r14);
    r1 = LD16(r13 + 0x06078054);
    ST16(r14, (r9 - r1));
    r1 = LD16((r8 + 2));
    ST16(r12, (r10 - r1));
    ST32((sp - 44), 0xFFFF);
    ST32((sp - 48), r14);
    ST32((sp - 52), 15);
    r0 = GCALL7(0x06068E64, 0, 0, 0x480, 0xFFFF, LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603248C(int r4, int r5)
{
    int r0, r1, r8, r9, r10, r11;

    r9 = r4;
    r8 = r5;
    r10 = 0x06078108;
    ST32(0x06078108, 0);
    if (!((r9 & r9) == 0)) {
        r10 = 0x0607810C;
        r11 = 0;
        ST32(0x0607810C, 0);
        if (!((r8 & r8) == 0)) {
            if (((3 & r8) & (3 & r8)) == 0) {
                r1 = LD32(0x06000358);
                r0 = GCALL3(r1, r9, r8, 0x06087FA4);
                r0 = 0;
            } else {
                r0 = -200;
            }
        } else {
            r0 = GCALL4(0x060279E0, 0, 0x2000, -1, 1);
            ST32(r10, r0);
            if (!((r0 & r0) == 0)) {
                r8 = r0;
                r1 = LD32(0x06000358);
                r0 = GCALL3(r1, r9, r8, 0x06087FA4);
                r0 = 0;
            } else {
                r8 = 0x06078108;
                r4 = LD32(0x06078108);
                r0 = -3;
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(0x06027F48, r4);
                    ST32(r8, r11);
                    POLL();
                    r0 = -3;
                }
            }
        }
    } else {
        r0 = GCALL4(0x060279E0, 0, 0x4000, -1, 1);
        ST32(r10, r0);
        if (!((r0 & r0) == 0)) {
            r9 = r0;
            r10 = 0x0607810C;
            r11 = 0;
            ST32(0x0607810C, 0);
            if (!((r8 & r8) == 0)) {
                if (((3 & r8) & (3 & r8)) == 0) {
                    r1 = LD32(0x06000358);
                    r0 = GCALL3(r1, r9, r8, 0x06087FA4);
                    r0 = 0;
                } else {
                    r0 = -200;
                }
            } else {
                r0 = GCALL4(0x060279E0, 0, 0x2000, -1, 1);
                ST32(r10, r0);
                if (!((r0 & r0) == 0)) {
                    r8 = r0;
                    r1 = LD32(0x06000358);
                    r0 = GCALL3(r1, r9, r8, 0x06087FA4);
                    r0 = 0;
                } else {
                    r8 = 0x06078108;
                    r4 = LD32(0x06078108);
                    r0 = -3;
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                        ST32(r8, r11);
                        POLL();
                        r0 = -3;
                    }
                }
            }
        } else {
            r0 = -3;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06032538(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = 0x06078108;
    r4 = LD32(0x06078108);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
        ST32(r8, 0);
    }
    r8 = 0x0607810C;
    r4 = LD32(0x0607810C);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r8, 0);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603262C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;

    r9 = r4;
    r4 = r5;
    r5 = r6;
    if (!((unsigned)r9 > (unsigned)2)) {
        r1 = LD32((r9 << 2) + 0x06078110);
        if ((r1 & r1) == 0) {
            r1 = LD16(0x06078104);
            if (!((r1 & r1) == 0)) {
                r0 = GCALL2(0x060325B4, r9, 0);
                r8 = r0;
                r0 = r9;
                if (!((r8 & r8) == 0)) {
                    r1 = LD16(0x06078104);
                    r0 = r8;
                    if ((r1 & r1) == 0) {
                        r0 = GCALL0(0x06032538);
                        r0 = r8;
                    }
                } else {
                    r1 = LD16(0x06078104);
                    ST16(0x06078104, (r1 + 1));
                    ST32((r0 << 2) + 0x06078110, 1);
                    r0 = GCALL1(0x0603245C, r9);
                    r0 = r8;
                }
            } else {
                r0 = GCALL4(0x0603248C, r4, r5, 0, r7);
                if ((r0 & r0) == 0) {
                    r0 = GCALL2(0x060325B4, r9, 0);
                    r8 = r0;
                    r0 = r9;
                    if (!((r8 & r8) == 0)) {
                        r1 = LD16(0x06078104);
                        r0 = r8;
                        if ((r1 & r1) == 0) {
                            r0 = GCALL0(0x06032538);
                            r0 = r8;
                        }
                    } else {
                        r1 = LD16(0x06078104);
                        ST16(0x06078104, (r1 + 1));
                        ST32((r0 << 2) + 0x06078110, 1);
                        r0 = GCALL1(0x0603245C, r9);
                        r0 = r8;
                    }
                }
            }
        } else {
            r0 = -201;
        }
    } else {
        r0 = -7;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603277C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;

    r9 = r4;
    if (!((unsigned)r9 > (unsigned)2)) {
        r1 = LD16(0x06078104);
        r5 = 0;
        if (!((r1 & r1) == 0)) {
            r1 = 0x20100063;
            do {
                r0 = LD8(r1);
            } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
            ST8(0x20100063, 1);
            ST8(0x2010001F, 26);
            r0 = LD8(0x20100063);
            r1 = 0x20100063;
            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                do {
                    r0 = LD8(r1);
                } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
            }
            r1 = LD32(0x06000354);
            r0 = LD32(r1 + 8);
            r0 = GCALL1(r0, r9);
            r0 = GCALL1(0x06032574, r0);
            r8 = r0;
            r1 = 0x20100063;
            do {
                r0 = LD8(r1);
            } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
            ST8(0x20100063, 1);
            ST8(0x2010001F, 25);
            r0 = LD8(0x20100063);
            r1 = 0x20100063;
            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                do {
                    r0 = LD8(r1);
                } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
            }
            r1 = LD16(0x06078104);
            r0 = r9;
            if ((r1 & r1) == 0) {
                r0 = GCALL0(0x06032538);
                r0 = r9;
            }
            r1 = LD32((r0 << 2) + 0x06078110);
            r0 = r8;
            if (!((r1 & r1) == 0)) {
                r0 = GCALL1(0x0603245C, r9);
                r0 = r8;
            }
        } else {
            r0 = GCALL4(0x0603248C, 0, r5, 0, r7);
            if ((r0 & r0) == 0) {
                r1 = 0x20100063;
                do {
                    r0 = LD8(r1);
                } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
                ST8(0x20100063, 1);
                ST8(0x2010001F, 26);
                r0 = LD8(0x20100063);
                r1 = 0x20100063;
                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                    do {
                        r0 = LD8(r1);
                    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
                }
                r1 = LD32(0x06000354);
                r0 = LD32(r1 + 8);
                r0 = GCALL1(r0, r9);
                r0 = GCALL1(0x06032574, r0);
                r8 = r0;
                r1 = 0x20100063;
                do {
                    r0 = LD8(r1);
                } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
                ST8(0x20100063, 1);
                ST8(0x2010001F, 25);
                r0 = LD8(0x20100063);
                r1 = 0x20100063;
                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                    do {
                        r0 = LD8(r1);
                    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
                }
                r1 = LD16(0x06078104);
                r0 = r9;
                if ((r1 & r1) == 0) {
                    r0 = GCALL0(0x06032538);
                    r0 = r9;
                }
                r1 = LD32((r0 << 2) + 0x06078110);
                r0 = r8;
                if (!((r1 & r1) == 0)) {
                    r0 = GCALL1(0x0603245C, r9);
                    r0 = r8;
                }
            }
        }
    } else {
        r0 = -7;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603285C(int r4)
{
    int r0, r1, r8, r9;

    r8 = r4;
    if (!((unsigned)r8 > (unsigned)2)) {
        r1 = LD32((r8 << 2) + 0x06078110);
        if (!((r1 & r1) == 0)) {
            r1 = 0x20100063;
            do {
                r0 = LD8(r1);
            } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
            ST8(0x20100063, 1);
            ST8(0x2010001F, 26);
            r0 = LD8(0x20100063);
            r1 = 0x20100063;
            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                do {
                    r0 = LD8(r1);
                } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
            }
            r1 = LD32(0x06000354);
            r0 = LD32(r1 + 24);
            r0 = GCALL1(r0, r8);
            r0 = GCALL1(0x06032574, r0);
            r9 = r0;
            r1 = 0x20100063;
            do {
                r0 = LD8(r1);
            } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
            ST8(0x20100063, 1);
            ST8(0x2010001F, 25);
            r0 = LD8(0x20100063);
            r1 = 0x20100063;
            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                do {
                    r0 = LD8(r1);
                } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
            }
            r0 = GCALL1(0x0603245C, r8);
            r0 = r9;
        } else {
            r0 = -202;
        }
    } else {
        r0 = -7;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032A08(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8, r10, r11, r12, r14;
    FRAME(sp, 96);

    ST32(sp - 36, r6);
    ST32(sp - 44, r7);
    r14 = LD32((96 + (sp - 96)));
    r11 = r4;
    r1 = LD32((100 + (sp - 96)));
    r12 = r5;
    ST32(sp - 40, ((r1 & r1) == 0));
    if (!((unsigned)r11 > (unsigned)2)) {
        r1 = LD32((r11 << 2) + 0x06078110);
        r6 = r14;
        if (!((r1 & r1) == 0)) {
            r0 = GCALL3(0x06032944, r11, r12, r6);
            r8 = sp - 96;
            if (!((r0 & r0) == 0)) {
                r8 = r8 + 44;
                r0 = GCALL1(0x06032D18, r8);
                r10 = (sp - 96) + 36;
                r1 = LD16(r8);
                ST8(r10, (r1 + 68));
                r1 = LD8((sp - 50));
                ST8((sp - 59), r1);
                r1 = LD8((sp - 49));
                ST8((sp - 58), r1);
                r1 = LD8((sp - 48));
                ST8((sp - 57), r1);
                r1 = LD8((sp - 47));
                ST8((sp - 56), r1);
                r1 = LD8((sp - 45));
                ST8((sp - 55), r1);
                r0 = GCALL3(0x060750A0, (sp - 96), r12, 12);
                ST8((sp - 85), 0);
                r5 = LD32(sp - 36);
                r0 = GCALL3(0x060750A0, (sp - 84), r5, 11);
                ST8((sp - 74), 0);
                ST8((sp - 73), 1);
                r1 = LD32(0x06000354);
                r0 = LD32(r1 + 40);
                r0 = GCALL1(r0, r10);
                ST32(sp - 72, r0);
                ST32(sp - 68, r14);
                ST16((sp - 64), 0);
                r1 = 0x20100063;
                do {
                    r0 = LD8(r1);
                } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
                ST8(0x20100063, 1);
                ST8(0x2010001F, 26);
                r0 = LD8(0x20100063);
                r1 = 0x20100063;
                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                    do {
                        r0 = LD8(r1);
                    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
                }
                r1 = LD32(0x06000354);
                r7 = LD32(sp - 40);
                r6 = LD32(sp - 44);
                r0 = LD32(r1 + 16);
                r0 = GCALL4(r0, r11, (sp - 96), r6, r7);
                r0 = GCALL1(0x06032574, r0);
                r8 = r0;
                r1 = 0x20100063;
                do {
                    r0 = LD8(r1);
                } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
                r3 = 0x20100063;
                ST8(0x20100063, 1);
                ST8(0x2010001F, 25);
                r0 = LD8(0x20100063);
                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                    r1 = r3;
                    do {
                        r0 = LD8(r1);
                    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
                }
                r0 = r8;
                if ((r8 & r8) == 0) {
                    r0 = GCALL1(0x0603245C, r11);
                    r0 = r8;
                }
            } else {
                r0 = -6;
            }
        } else {
            r0 = -202;
        }
    } else {
        r0 = -7;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032BA4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, c5;
    FRAME(sp, 64);

    r9 = r4;
    r12 = r5;
    r10 = r6;
    r8 = r7;
    r11 = 0;
    ST32(r10, 0);
    r13 = 0;
    ST16(r8, 0);
    if (!((unsigned)r9 > (unsigned)2)) {
        r1 = LD32((r9 << 2) + 0x06078110);
        r7 = r8;
        if (!((r1 & r1) == 0)) {
            r0 = GCALL4(0x060325F4, r9, r12, (sp - 64), r7);
            r2 = LD16(r8);
            r1 = 36;
            if (((r2 & 0xFFFF) & (r2 & 0xFFFF)) == 0) {
                r0 = r11;
            } else {
                r0 = GCALL4(0x060279E0, 0, ((r2 & 0xFFFF) * (r1 & 0xFFFF)), -1, 1);
                r2 = r0;
                ST32(r10, r2);
                if (!((r2 & r2) == 0)) {
                    r1 = LD32(0x06000354);
                    r6 = LD16(r8);
                    r0 = LD32(r1 + 28);
                    r0 = GCALL4(r0, r9, r12, (r6 & 0xFFFF), r2);
                    c5 = r0 >= 0;
                    r0 = r11;
                    if (!(c5)) {
                        r4 = LD32(r10);
                        r0 = GCALL1(0x06027F48, r4);
                        ST32(r10, r11);
                        ST16(r8, r13);
                        r11 = -207;
                        r0 = r11;
                    }
                } else {
                    r0 = -3;
                }
            }
        } else {
            r0 = -202;
        }
    } else {
        r0 = -7;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032C60(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12;
    FRAME(sp, 68);

    r9 = r4;
    r12 = r6;
    r11 = r7;
    ST32(r11, 0);
    ST32(r12, 0);
    r10 = r5;
    if (!((unsigned)r9 > (unsigned)2)) {
        r1 = LD32((r9 << 2) + 0x06078110);
        r7 = sp - 68;
        if (!((r1 & r1) == 0)) {
            r0 = GCALL4(0x060325F4, r9, r10, (sp - 68), (r7 + 36));
            r5 = LD32(sp - 40);
            if ((r0 & r0) == 0) {
                r0 = GCALL4(0x060279E0, 0, r5, -1, 1);
                r8 = r0;
                r6 = r8;
                if (!((r8 & r8) == 0)) {
                    r1 = LD32(0x06000354);
                    r0 = LD32(r1 + 20);
                    r0 = GCALL3(r0, r9, r10, r6);
                    r0 = GCALL1(0x06032574, r0);
                    r4 = r8;
                    if (!((r0 & r0) == 0)) {
                        ST32(sp - 28, r0);
                        r0 = GCALL1(0x06027F48, r4);
                        r0 = LD32(sp - 28);
                    } else {
                        r1 = LD32(sp - 40);
                        ST32(r11, r1);
                        ST32(r12, r8);
                    }
                } else {
                    r0 = -3;
                }
            }
        } else {
            r0 = -202;
        }
    } else {
        r0 = -7;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032FD4(int r4)
{
    int r0, r1, r2, r3, r8;

    r8 = r4;
    r1 = LD32(0x06000344);
    r0 = GCALL2(r1, -1, 0x8000);
    r0 = GCALL2(0x06069E6C, 92, r8);
    ST32(0x06089CBC, 1);
    r3 = 0x06089CB8;
    r2 = LD32(0x06089CB8);
    do {
        r1 = LD32(r3);
    } while (AGAIN(r2 == r1));
    r1 = 0x20100063;
    do {
        r0 = LD8(r1);
    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    ST8(0x20100063, 1);
    ST8(0x2010001F, 10);
    r0 = LD8(0x20100063);
    r1 = 0x20100063;
    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
        do {
            r0 = LD8(r1);
        } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    }
    ST32(0x06089CBC, 0);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033098(int r4, int r5)
{
    int r0, r1, r8, r9, r10;

    r10 = r4;
    r1 = LD32(0x06078128);
    r9 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL1(0x06033ECC, r10);
        r0 = GCALL2(0x060193B0, r10, 0x06033094);
        r0 = GCALL2(0x060193B0, r10, 0x06033094);
        r0 = 1;
    } else {
        r1 = LD32(0x10C8 + r10);
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x060287D0, 32);
            r8 = r0;
            r0 = 1;
            if (!((r8 & r8) == 0)) {
                r0 = GCALL1(0x06034D08, r8);
                r0 = GCALL3(0x0603407C, r10, r8, r9);
                r5 = r8;
                r0 = GCALL2(0x06033828, r10, r5);
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL2(0x060193B0, r10, 0x06033094);
                    r0 = GCALL2(0x060193B0, r10, 0x06033094);
                    r0 = 1;
                } else {
                    r0 = GCALL2(0x06027F48, r8, r5);
                    r0 = 1;
                }
            }
        } else {
            r0 = LD32(0x10CC + r10);
            if (!(r0 == 1)) {
                r0 = GCALL1(0x06033ECC, r10);
                r0 = GCALL2(0x060193B0, r10, 0x06033094);
                r0 = GCALL2(0x060193B0, r10, 0x06033094);
                r0 = 1;
            } else {
                r0 = GCALL1(0x060287D0, 32);
                r8 = r0;
                r0 = 1;
                if (!((r8 & r8) == 0)) {
                    r0 = GCALL1(0x06034D08, r8);
                    r0 = GCALL3(0x0603407C, r10, r8, r9);
                    r5 = r8;
                    r0 = GCALL2(0x06033828, r10, r5);
                    if (!((r0 & r0) == 0)) {
                        r0 = GCALL2(0x060193B0, r10, 0x06033094);
                        r0 = GCALL2(0x060193B0, r10, 0x06033094);
                        r0 = 1;
                    } else {
                        r0 = GCALL2(0x06027F48, r8, r5);
                        r0 = 1;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603340C(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10;

    r9 = r4;
    r1 = LD32(0x06078128);
    r10 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL1(0x06033F6C, r9);
        r0 = GCALL0(0x06034000);
        r8 = r0;
        r1 = r8;
        if ((r8 & r8) == 0) {
            POLL();
            r0 = 1;
        } else {
            r2 = LD32(r9);
            r0 = 1;
            ST32((r1 + 68), r2);
            ST32(r9, 0);
        }
    } else {
        r1 = LD32(0x10C8 + r9);
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x060287D0, 76);
            r8 = r0;
            r0 = 1;
            if (!((r8 & r8) == 0)) {
                r0 = GCALL1(0x06034D90, r8);
                r0 = GCALL3(0x0603486C, r9, r8, r10);
                r5 = r8;
                r0 = GCALL2(0x06033974, r9, r5);
                r1 = r8;
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(r9);
                    r0 = 1;
                    ST32((r1 + 68), r2);
                    ST32(r9, 0);
                } else {
                    r0 = GCALL2(0x06027F48, r8, r5);
                    r0 = 1;
                }
            }
        } else {
            r0 = LD32(0x10CC + r9);
            if (!(r0 == 1)) {
                r0 = GCALL1(0x06033F6C, r9);
                r0 = GCALL0(0x06034000);
                r8 = r0;
                r1 = r8;
                if ((r8 & r8) == 0) {
                    POLL();
                    r0 = 1;
                } else {
                    r2 = LD32(r9);
                    r0 = 1;
                    ST32((r1 + 68), r2);
                    ST32(r9, 0);
                }
            } else {
                r0 = GCALL1(0x060287D0, 76);
                r8 = r0;
                r0 = 1;
                if (!((r8 & r8) == 0)) {
                    r0 = GCALL1(0x06034D90, r8);
                    r0 = GCALL3(0x0603486C, r9, r8, r10);
                    r5 = r8;
                    r0 = GCALL2(0x06033974, r9, r5);
                    r1 = r8;
                    if (!((r0 & r0) == 0)) {
                        r2 = LD32(r9);
                        r0 = 1;
                        ST32((r1 + 68), r2);
                        ST32(r9, 0);
                    } else {
                        r0 = GCALL2(0x06027F48, r8, r5);
                        r0 = 1;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033710(int r4, int r5)
{
    int r0, r1, r8, r9, r10;

    r9 = r4;
    r1 = LD32(0x06078128);
    r10 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL1(0x06033F6C, r9);
        r0 = GCALL0(0x06034024);
        r8 = r0;
        r0 = 1;
        if (!((r8 & r8) == 0)) {
            r1 = LD32(r9);
            ST32(r8 + 52, r1);
            ST32(r9, 0);
            r0 = GCALL2(0x060335FC, r9, r8);
            r0 = 1;
        }
    } else {
        r1 = LD32(0x10C8 + r9);
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x060287D0, 60);
            r8 = r0;
            r0 = 1;
            if (!((r8 & r8) == 0)) {
                r0 = GCALL1(0x06034DFC, r8);
                r0 = GCALL3(0x06034AE0, r9, r8, r10);
                r5 = r8;
                r0 = GCALL2(0x06033974, r9, r5);
                if (!((r0 & r0) == 0)) {
                    r1 = LD32(r9);
                    ST32(r8 + 52, r1);
                    ST32(r9, 0);
                    r0 = GCALL2(0x060335FC, r9, r8);
                    r0 = 1;
                } else {
                    r0 = GCALL2(0x06027F48, r8, r5);
                    r0 = 1;
                }
            }
        } else {
            r0 = LD32(0x10CC + r9);
            if (!(r0 == 1)) {
                r0 = GCALL1(0x06033F6C, r9);
                r0 = GCALL0(0x06034024);
                r8 = r0;
                r0 = 1;
                if (!((r8 & r8) == 0)) {
                    r1 = LD32(r9);
                    ST32(r8 + 52, r1);
                    ST32(r9, 0);
                    r0 = GCALL2(0x060335FC, r9, r8);
                    r0 = 1;
                }
            } else {
                r0 = GCALL1(0x060287D0, 60);
                r8 = r0;
                r0 = 1;
                if (!((r8 & r8) == 0)) {
                    r0 = GCALL1(0x06034DFC, r8);
                    r0 = GCALL3(0x06034AE0, r9, r8, r10);
                    r5 = r8;
                    r0 = GCALL2(0x06033974, r9, r5);
                    if (!((r0 & r0) == 0)) {
                        r1 = LD32(r9);
                        ST32(r8 + 52, r1);
                        ST32(r9, 0);
                        r0 = GCALL2(0x060335FC, r9, r8);
                        r0 = 1;
                    } else {
                        r0 = GCALL2(0x06027F48, r8, r5);
                        r0 = 1;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033C2C(int r4, int r5)
{
    int r0, r1, r8, r9, r10;

    r1 = LD32(0x10D4 + r4);
    r10 = r5;
    if ((r1 & r1) == 0) {
        r0 = GCALL1(0x0607507C, r10);
        r0 = GCALL1(0x060287D0, (r0 + 1));
        r8 = r0;
        r5 = r10;
        if (!((r8 & r8) == 0)) {
            r0 = GCALL2(0x06018930, r8, r5);
            r0 = r8;
        } else {
            r0 = 0;
        }
    } else {
        r0 = GCALL1(0x060455FC, r10);
        r9 = (r0 + 1) + (r0 + 1);
        r0 = GCALL1(0x060287D0, r9);
        r8 = r0;
        if ((r0 & r0) == 0) {
            r0 = 0;
        } else {
            r0 = GCALL3(0x0604B358, r8, r10, r9);
            r0 = r8;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033CA8(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, c2;

    r11 = r4;
    r9 = LD32(0x10D4 + r11);
    r8 = r5;
    r0 = GCALL0(0x06034000);
    if ((r0 & r0) == 0) {
        r0 = 0;
    } else {
        r10 = LD32(r0 + 48);
        c2 = (r9 & r9) == 0;
        if (!((r10 & r10) == 0)) {
            if (c2) {
                r0 = GCALL1(0x0607507C, r8);
                r2 = 0x06075135;
                r1 = LD8(r8);
                while (1) {
                    r0 = LD8((r1 & 255) + r2);
                    r1 = r1 & 255;
                    if (!(((r0 & 8) & (r0 & 8)) == 0)) {
                        POLL();
                        if ((r1 & r1) == 0) {
                            break;
                        } else {
                            r8 = r8 + 1;
                            r1 = LD8(r8);
                            continue;
                        }
                    } else {
                        break;
                    }
                }
                r0 = 0x0607507C;
            } else {
                r0 = GCALL1(0x060455FC, r8);
                r9 = 0x060455C4;
                r4 = LD16(r8);
                while (1) {
                    r0 = GCALL1(r9, (r4 & 0xFFFF));
                    if ((r0 & r0) == 0) {
                        break;
                    } else {
                        r1 = LD16(r8);
                        if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
                            break;
                        } else {
                            r8 = r8 + 2;
                            r4 = LD16(r8);
                        }
                    }
                    POLL();
                }
                r0 = 0x060455FC;
            }
            r0 = GCALL1(r0, r8);
            r1 = LD32(r10 + 12);
            r5 = r8;
            if ((r1 & r1) == 0) {
                r0 = GCALL2(0x06033C2C, r11, r5);
                ST32(r10 + 12, r0);
            }
            r4 = LD32(r10 + 16);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(0x06027F48, r4);
            }
            r0 = GCALL2(0x06033C2C, r11, r8);
            ST32(r10 + 16, r0);
            r0 = 1;
        } else {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033D70(int r4, int r5)
{
    int r0, r1, r6, r7, r8, r9, r10;

    r9 = r4;
    r10 = r5;
    r0 = GCALL0(0x06034024);
    r8 = r0;
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        r1 = LD32(r8 + 40);
        r0 = 1;
        if ((r1 & r1) == 0) {
            r1 = LD32(0x10D4 + r9);
            if ((r1 & r1) == 0) {
                r0 = GCALL1(0x0607507C, r10);
                r4 = r0 + 1;
            } else {
                r0 = GCALL1(0x060455FC, r10);
                r4 = r0 + 2;
            }
            r0 = GCALL1(0x060287D0, r4);
            r9 = r0;
            r5 = r10;
            if (!((r9 & r9) == 0)) {
                r0 = GCALL2(0x06018930, r9, r5);
                r7 = LD16((r8 + 44));
                r6 = LD16((r8 + 46));
                r1 = LD32(r8 + 48);
                r5 = -1;
                if (!((r1 & r1) == 0)) {
                    r5 = r7;
                }
                r0 = GCALL4(0x060419E0, r9, r5, r6, r7);
                ST32(r8 + 40, r0);
                ST32(r8 + 36, r9);
                r0 = 1;
            } else {
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034E20(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r4 = LD32(r8 + 36);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
        }
        r4 = LD32(r8 + 40);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06042468, r4);
        }
        r4 = LD32(r8 + 32);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
        }
        r0 = GCALL1(0x06027F48, r8);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034E64(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r4 = LD32(r8 + 12);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
        }
        r4 = LD32(r8 + 16);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
        }
        r0 = GCALL1(0x06027F48, r8);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034ED0(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r0 = GCALL4(0x06034E98, (r4 + 44), r5, r6, r7);
        r4 = LD32(r8 + 60);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
        }
        r0 = GCALL1(0x06027F48, r8);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034F00(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r4 = LD32(r8 + 52);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
        }
        r4 = LD32(r8 + 60);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
        }
        r4 = LD32(r8 + 36);
        r1 = r8;
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
            r1 = r8;
        }
        r4 = LD32((r1 + 88));
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
        }
        r0 = GCALL1(0x06027F48, r8);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034F98(int r4)
{
    int r0, r8, r9, r10;

    r9 = r4;
    if (!((r9 & r9) == 0)) {
        r8 = LD32(r9);
        r4 = r8;
        if (!((r8 & r8) == 0)) {
            r10 = 0x06034F50;
            do {
                r8 = LD32(r8 + 4);
                r0 = GCALL1(r10, r4);
                r4 = r8;
            } while (AGAIN(!((r8 & r8) == 0)));
        }
        r4 = LD32(r9 + 12);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
        }
        r4 = LD32(r9 + 20);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
        }
        r0 = GCALL1(0x06027F48, r9);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036C60(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10;

    r9 = r4;
    r8 = r5;
    r10 = r8 + 64;
    ST32(r10, 1);
    r0 = GCALL4(0x06016610, r4, 0x060162B4, r6, r7);
    r5 = LD32((r8 + 72));
    r0 = GCALL2(0x06037E74, r9, r5);
    r0 = GCALL1(0x06013EC8, 12);
    ST32(r10, 0);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036CB0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r10, r11, r12, r13, r14;
    int v36;
    int v40;
    int v44;

    r10 = r4;
    r11 = r5;
    r8 = r6;
    r13 = r8 + 64;
    r14 = 1;
    ST32(r13, 1);
    r0 = GCALL4(0x06016610, r4, 0x060162B4, r6, r7);
    ST32(0x0607668C, 2);
    r12 = 0;
    r6 = LD32((r8 + 72));
    r1 = LD32(r8 + 52);
    v40 = r1;
    r1 = LD32(r8 + 36);
    r0 = GCALL7(0x060384AC, r10, r11, r6, 0, r1, v40, 0);
    ST32(0x0607668C, 0);
    if ((r0 & r0) == 0) {
        r0 = 0;
    } else {
        r0 = GCALL1(0x06013EC8, 12);
        ST32(r13, r12);
        r0 = r14;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038B78(int r4, int r5)
{
    int r0, r1, r6, r8, r9, r10, r11, r12, r13, r14, c8;

    r11 = r4;
    r10 = r5;
    r12 = 0x0607507C;
    r0 = GCALL1(0x0607507C, r10);
    r1 = LD32(0x06078120);
    r8 = r0;
    if (!((r1 & r1) == 0)) {
        r9 = LD32(r1);
        r13 = r12;
        if ((r9 & r9) == 0) {
            r0 = 0;
        } else {
            r12 = r8 + 1;
            r14 = 0x060750DC;
            while (1) {
                r1 = LD32(r9);
                if (!((r1 & r1) == 0)) {
                    r9 = LD32(r9 + 4);
                    if (!((r9 & r9) == 0)) {
                        POLL();
                        continue;
                    } else {
                        r0 = 0;
                        break;
                    }
                } else {
                    r0 = LD32(r9 + 32);
                    if (!(r0 == 8)) {
                        r9 = LD32(r9 + 4);
                        if (!((r9 & r9) == 0)) {
                            POLL();
                            continue;
                        } else {
                            r0 = 0;
                            break;
                        }
                    } else {
                        r1 = LD32(r9 + 36);
                        if ((r1 & r1) == 0) {
                            r9 = LD32(r9 + 4);
                            if (!((r9 & r9) == 0)) {
                                POLL();
                                continue;
                            } else {
                                r0 = 0;
                                break;
                            }
                        } else {
                            r0 = GCALL1(r13, r11);
                            r4 = LD32(r9 + 36);
                            r0 = GCALL3(0x06075238, r4, r11, r0);
                            if (!((r0 & r0) == 0)) {
                                r9 = LD32(r9 + 4);
                                if (!((r9 & r9) == 0)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = 0;
                                    break;
                                }
                            } else {
                                r4 = LD32(r9 + 52);
                                if (!((r4 & r4) == 0)) {
                                    r0 = GCALL1(r13, r4);
                                    r6 = LD32(r9 + 56);
                                    c8 = (unsigned)((r0 + r8) + 1) > (unsigned)r6;
                                    r6 = r6 + r8;
                                    if (!(c8)) {
                                        r4 = LD32(r9 + 52);
                                        r1 = LD8(r4);
                                        if ((r1 & r1) == 0) {
                                            r0 = GCALL2(r14, r4, r10);
                                            r0 = 1;
                                            ST32(r9 + 24, r0);
                                            ST32(0x060766C0, -12);
                                            break;
                                        } else {
                                            r0 = GCALL2(0x06075408, r4, 0x06038B74);
                                            r4 = LD32(r9 + 52);
                                            r0 = GCALL2(0x06075408, r4, r10);
                                            r0 = 1;
                                            ST32(r9 + 24, r0);
                                            ST32(0x060766C0, -12);
                                            break;
                                        }
                                    } else {
                                        r5 = LD32(r9 + 52);
                                        r0 = GCALL3(0x06027C18, 0, r5, (r6 + 1));
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                            break;
                                        } else {
                                            r1 = LD32(r9 + 56);
                                            ST32(r9 + 52, r0);
                                            ST32(r9 + 56, ((r1 + 1) + r8));
                                            r4 = LD32(r9 + 52);
                                            r1 = LD8(r4);
                                            if ((r1 & r1) == 0) {
                                                r0 = GCALL2(r14, r4, r10);
                                                r0 = 1;
                                                ST32(r9 + 24, r0);
                                                ST32(0x060766C0, -12);
                                                break;
                                            } else {
                                                r0 = GCALL2(0x06075408, r4, 0x06038B74);
                                                r4 = LD32(r9 + 52);
                                                r0 = GCALL2(0x06075408, r4, r10);
                                                r0 = 1;
                                                ST32(r9 + 24, r0);
                                                ST32(0x060766C0, -12);
                                                break;
                                            }
                                        }
                                    }
                                } else {
                                    r0 = GCALL1(0x060287D0, r12);
                                    ST32(r9 + 52, r0);
                                    if ((r0 & r0) == 0) {
                                        POLL();
                                        ST32(r9 + 56, 0);
                                        r0 = 0;
                                        break;
                                    } else {
                                        ST8(r0, 0);
                                        r4 = LD32(r9 + 52);
                                        r0 = GCALL2(r14, r4, r10);
                                        ST32(r9 + 56, r12);
                                        r0 = 1;
                                        ST32(r9 + 24, r0);
                                        ST32(0x060766C0, -12);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                POLL();
            }
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038EA0(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12;

    r10 = r4;
    r11 = 0x1DF0;
    r1 = LD32(r10 + 0x1DF0);
    r0 = -1;
    if (!((r1 & r1) == 0)) {
        r12 = 0x06039BC8;
        r0 = GCALL1(0x06039BC8, r10);
        r8 = r0;
        r1 = LD32(r10 + r11);
        r1 = LD32(r1 + 8);
        r9 = 1;
        if (r8 > r1) {
            r11 = r12;
            do {
                r0 = GCALL1(r11, r10);
                r8 = (r8 + r8) + r0;
                r9 = r9 + 1;
                r2 = LD32(0x1DF0 + r10);
                r1 = LD32(((r9 << 2) + r2) + 4);
            } while (AGAIN(r8 > r1));
        }
        r1 = LD32(0x1DE8 + r10);
        r0 = 0;
        if ((r1 & r1) == 0) {
            r2 = LD32(0x1DF0 + r10);
            r1 = LD32(r2);
            r1 = LD32(((r1 << 2) + r2) + 4);
            r3 = r9;
            if (!(r8 >= r1)) {
                r0 = (r3 << 2) + r2;
                r1 = LD32(r0 + 0x124);
                r2 = LD32(r0 + 148);
                r1 = (r1 + r8) - r2;
                r2 = LD32(r10 + 0x1DEC);
                r0 = LD32(((r1 << 2) + r2) + 144);
            } else {
                r0 = GCALL1(0x06039FD8, r10);
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039B68(int r4)
{
    int r0, r1, r8, r9, r10, r11;

    r9 = r4;
    r1 = LD32((r9 + 96));
    r0 = 0;
    if ((r1 & r1) == 0) {
        r10 = 0x06039B14;
        r0 = GCALL1(0x06039B14, r9);
        r8 = r0;
        r11 = 255;
        r0 = r8;
        if (r8 == 255) {
            r0 = GCALL1(r10, r9);
            r8 = r0;
            r1 = r9;
            if (!((r8 & r8) == 0)) {
                r1 = LD32((r1 + 100));
                r0 = r8;
                if ((r1 & r1) == 0) {
                    r0 = GCALL1(0x0603A1C0, r9);
                    r0 = r8;
                }
            } else {
                r0 = r11;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039F2C(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c4;

    r8 = r4;
    r3 = r8 + 124;
    r0 = LD32(r3);
    r2 = r8;
    if (r0 == 7) {
        r2 = LD32((r2 + 116));
        ST32((r8 + 120), r2);
        r9 = r8 + 120;
        r2 = LD32(r9);
        r10 = 255;
        r1 = r8;
        if (r2 == 255) {
            r11 = 0x06039B14;
            while (1) {
                r0 = GCALL1(r11, r8);
                ST32(r9, r0);
                if (r0 == r10) {
                    POLL();
                    r0 = GCALL1(r11, r8);
                    ST32(r9, r0);
                    if (!(r0 == r10)) {
                        POLL();
                        r0 = -1;
                        break;
                    } else {
                        c4 = r0 == -1;
                        r0 = -1;
                        if (c4) {
                            break;
                        } else {
                            continue;
                        }
                    }
                } else {
                    r1 = LD32((r8 + 120));
                    r2 = r8;
                    if (!((r1 & r1) == 0)) {
                        r0 = GCALL1(0x06039CF8, r8);
                        break;
                    } else {
                        ST32((r2 + 116), 255);
                        ST32((r8 + 124), 7);
                        POLL();
                        r0 = -1;
                        break;
                    }
                }
            }
        } else {
            ST32((r1 + 116), r2);
            ST32((r8 + 124), 7);
            POLL();
            r0 = -1;
        }
    } else {
        ST32((r2 + 116), 0);
        ST32(r3, -1);
        r0 = GCALL1(0x06039B14, r4);
        ST32((r8 + 120), r0);
        if (!(r0 == -1)) {
            r9 = r8 + 120;
            r2 = LD32(r9);
            r10 = 255;
            r1 = r8;
            if (r2 == 255) {
                r11 = 0x06039B14;
                while (1) {
                    r0 = GCALL1(r11, r8);
                    ST32(r9, r0);
                    if (r0 == r10) {
                        POLL();
                        r0 = GCALL1(r11, r8);
                        ST32(r9, r0);
                        if (!(r0 == r10)) {
                            POLL();
                            r0 = -1;
                            break;
                        } else {
                            c4 = r0 == -1;
                            r0 = -1;
                            if (c4) {
                                break;
                            } else {
                                continue;
                            }
                        }
                    } else {
                        r1 = LD32((r8 + 120));
                        r2 = r8;
                        if (!((r1 & r1) == 0)) {
                            r0 = GCALL1(0x06039CF8, r8);
                            break;
                        } else {
                            ST32((r2 + 116), 255);
                            ST32((r8 + 124), 7);
                            POLL();
                            r0 = -1;
                            break;
                        }
                    }
                }
            } else {
                ST32((r1 + 116), r2);
                ST32((r8 + 124), 7);
                POLL();
                r0 = -1;
            }
        } else {
            r0 = -1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A0B4(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c0, c3;

    r9 = r4;
    ST32((r9 + 64), 1);
    r11 = 0x06039F2C;
    r10 = 0x1DE8;
    r8 = r9 + 120;
    while (1) {
        r0 = GCALL1(r11, r9);
        c0 = r0 == -1;
        r0 = r9;
        if (c0) {
            r1 = LD32(0x1DE8 + r9);
            r0 = -1;
            if (!((r1 & r1) == 0)) {
                break;
            } else {
                r0 = GCALL2(0x06045264, 0x0608B9D0, 0x0603A094);
                r0 = GCALL1(0x0602BA00, 0x0608B9D0);
                r0 = GCALL1(0x06039FD8, r9);
                ST32((r9 + 64), 0);
                r0 = -1;
                break;
            }
        } else {
            r1 = LD32(r0 + r10);
            if (!((r1 & r1) == 0)) {
                r0 = -1;
                break;
            } else {
                r3 = LD32(r8);
                r0 = r3;
                if (!((248 & r3) == 208)) {
                    POLL();
                    continue;
                } else {
                    ST32(r8, (r0 & 7));
                    r2 = r9 + 104;
                    r1 = LD32(r2);
                    ST32(r2, ((r1 + 1) & 7));
                    while (1) {
                        r0 = GCALL1(r11, r9);
                        c3 = r0 == -1;
                        r0 = r9;
                        if (c3) {
                            ST32((r9 + 64), 0);
                            r0 = 0;
                            break;
                        } else {
                            r1 = LD32(r0 + r10);
                            r0 = -1;
                            if ((r1 & r1) == 0) {
                                POLL();
                                continue;
                            } else {
                                break;
                            }
                        }
                        POLL();
                    }
                    break;
                }
            }
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A178(int r4, int r5, int r6, int r7)
{
    int r0, r2, r8, c0, c2;

    r8 = r4;
    ST32((r8 + 124), -1);
    r0 = GCALL4(0x06039F2C, r4, r5, r6, r7);
    c0 = r0 == -1;
    r0 = -1;
    if (!(c0)) {
        while (1) {
            r0 = GCALL1(0x06039F2C, r8);
            r2 = r0;
            if (!(r0 >= -305)) {
                r0 = -1;
                break;
            } else {
                c2 = r0 > -304;
                r0 = 0;
                if (!(c2)) {
                    break;
                } else {
                    if ((r2 & r2) == 0) {
                        POLL();
                        continue;
                    } else {
                        r0 = -1;
                        break;
                    }
                }
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A1C0(int r4, int r5, int r6, int r7)
{
    int r0, r8, c0, c2, c3, c4;

    r8 = r4;
    r0 = GCALL4(0x06039CF8, r4, r5, r6, r7);
    c0 = r0 == -1;
    r0 = -1;
    if (!(c0)) {
        while (1) {
            r0 = GCALL1(0x06039F2C, r8);
            c2 = (unsigned)r0 > (unsigned)-305;
            if (r0 == -305) {
                r0 = 0;
                break;
            } else {
                c3 = (r0 & r0) == 0;
                if (c2) {
                    c4 = r0 == -304;
                    r0 = -1;
                    if (!(c4)) {
                        break;
                    } else {
                        r0 = 0;
                        break;
                    }
                } else {
                    r0 = -1;
                    if (c3) {
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
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603B390(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10, r11, r12, c2;

    r9 = r4;
    r10 = 0x1DE0;
    r12 = 0x0603AB10;
    r11 = 0x0603AAB8;
    r2 = LD32(r9 + 60);
    while (1) {
        if (!(r2 >= 0)) {
            r0 = GCALL1(0x0603B41C, r9);
            r2 = LD32(r9 + 60);
            POLL();
            continue;
        } else {
            r1 = LD32(r9 + 56);
            r0 = r9;
            if (!(r1 >= r2)) {
                r0 = GCALL1(0x0603B41C, r9);
                r2 = LD32(r9 + 60);
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
    }
    r1 = LD32(r0 + r10);
    r1 = LD32(r1);
    r8 = 0;
    c2 = 0 >= r1;
    r1 = 0;
    if (!(c2)) {
        r5 = r8;
        do {
            r0 = GCALL2(r12, r9, r5);
            r0 = GCALL1(r11, r9);
            r1 = LD32(r9 + r10);
            r1 = LD32(r1);
            r8 = r8 + 1;
            r5 = r8;
        } while (AGAIN(!(r8 >= r1)));
        r1 = 0;
    }
    ST32(r9 + 56, r1);
    r0 = GCALL1(0x0603A178, r9);
    r0 = GCALL1(0x0603AB28, r9);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603CC04(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;

    r8 = r4;
    r0 = LD32(r8 + 28);
    r1 = 0;
    if (!(r0 == 9)) {
        ST32(r8 + 4, r1);
        ST32(r8 + 8, r1);
        r9 = r8;
    } else {
        r4 = LD32(r8 + 4);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
            ST32(r8 + 4, 0);
        }
        r4 = LD32(r8 + 8);
        r9 = r8;
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
            r1 = 0;
            ST32(r8 + 8, r1);
            r9 = r8;
        }
    }
    r9 = r9 + 108;
    r4 = LD32(r9);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r9, 0);
    }
    r9 = r8 + 112;
    r4 = LD32(r9);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r9, 0);
    }
    r9 = r8 + 116;
    r4 = LD32(r9);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r9, 0);
    }
    r9 = r8 + 120;
    r4 = LD32(r9);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r9, 0);
    }
    r9 = r8 + 124;
    r4 = LD32(r9);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r9, 0);
    }
    r9 = 128;
    r0 = r8;
    r4 = LD32(r0 + 128);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        r0 = r8;
        ST32(r0 + r9, 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603D67C(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, c3;

    r10 = r4;
    r12 = r5;
    r0 = GCALL1(0x0607507C, r12);
    r2 = r10 + 88;
    r1 = LD32(r2);
    r11 = r0;
    r9 = r2;
    if (r1 >= r11) {
        r0 = 1;
    } else {
        r13 = 0x0605ACB8;
        while (1) {
            r1 = LD32(r9);
            r2 = 0x200;
            r8 = r11 - r1;
            if (r8 > 0x200) {
                r8 = r2;
            }
            r4 = LD16((r10 + 20));
            r0 = GCALL3(r13, r4, (r12 + r1), r8);
            r2 = r0;
            c3 = r2 > 0;
            if (!(r2 == -502)) {
                r5 = r2;
                if (c3) {
                    r1 = LD32(r9);
                    r5 = LD32(r10 + 36);
                    r0 = GCALL0(0x0603D628);
                    r1 = LD32(r9);
                    r1 = r1 + r8;
                    ST32(r9, r1);
                    if (!(r1 >= r11)) {
                        POLL();
                        continue;
                    } else {
                        r0 = 1;
                        break;
                    }
                } else {
                    r0 = GCALL2(0x0603D62C, r10, r5);
                    ST32(r10 + 40, r0);
                    r0 = 0;
                    break;
                }
            } else {
                ST32(r10 + 40, 0);
                r0 = 0;
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060325B4(int r4, int r5)
{
    int r0, r1, r8, c2;
    FRAME(sp, 32);

    r8 = r5;
    if (!((r8 & r8) == 0)) {
        ST32(r8, 0);
    }
    r1 = LD32(0x06000354);
    r0 = LD32(r1 + 12);
    r0 = GCALL3(r0, r4, 0, (sp - 32));
    r0 = GCALL1(0x06032574, r0);
    c2 = (r8 & r8) == 0;
    if ((r0 & r0) == 0) {
        r1 = LD32(sp - 20);
        if (!(c2)) {
            ST32(r8, r1);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060325F4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = r7;
    r1 = LD32(0x06000354);
    r0 = LD32(r1 + 28);
    r0 = GCALL4(r0, r4, r5, 1, r6);
    r1 = -r0;
    if (r0 >= 0) {
        ST16(r8, r0);
    } else {
        ST16(r8, r1);
    }
    r1 = LD16(r8);
    r0 = 0;
    if (!((r1 & 0xFFFF) == 1)) {
        r0 = -206;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06034FEC(int r4)
{
    int r0, r1, r3, r8, r9;

    if (!((r4 & r4) == 0)) {
        r1 = LD32(r4);
        if (!((r1 & r1) == 0)) {
            r0 = (SR() & ~1) | 0;
            r3 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
            r0 = (SR() & ~1) | 0;
            SETSR((r0 | 240));
            r8 = r1;
            ST32(r4, 0);
            r1 = SR();
            SETSR(((r1 & -241) | ((r3 << 2) << 2)));
            r4 = r8;
            if (!((r8 & r8) == 0)) {
                r9 = 0x06034F98;
                do {
                    r8 = LD32(r8 + 28);
                    r0 = GCALL1(r9, r4);
                    r4 = r8;
                } while (AGAIN(!((r8 & r8) == 0)));
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06035040(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x06034FEC, 0x06078120, r5, r6, r7);
    ST32(0x06078124, 0);
    ST32(0x06078128, 0);
    ST32(0x0607812C, 0);
    ST32(0x06078130, 0);
    ST32(0x06078134, 0);
    ST32(0x06078138, 0);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036E68(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, c4, c7, c9, c10, c14, c16, c22, c23, c27, c30, c31, c32;

    r8 = r4;
    r4 = LD32(r8 + 20);
    r0 = GCALL1(0x0607507C, r4);
    r10 = r0;
    r2 = r8 + 28;
    r1 = LD8(r2);
    r3 = 0;
    r7 = r1 & 255;
    ST8(r2, 0);
    if (!((r7 & r7) == 0)) {
        r11 = 0x06088028;
        r4 = LD32(0x06088028);
        if (!((r4 & r4) == 0)) {
            r1 = LD32(r4);
            r9 = r4;
            if ((r1 & r1) == 0) {
                r1 = LD32(r9 + 32);
                r0 = r1;
                c4 = r0 == 4;
                if (r0 == 8) {
                    r0 = r7;
                    r1 = 22;
                    if (r0 == 22) {
                        r2 = r8 + 24;
                        r1 = LD16(r2);
                        r1 = r1 - 1;
                        ST16(r2, r1);
                        c22 = ((short)r1) >= 0;
                        r1 = 0;
                        if (!(c22)) {
                            ST16(r2, r1);
                        }
                        r2 = LD32(0x06088028);
                        ST32(r2 + 24, 1);
                        r2 = 0x060766C0;
                        r1 = -12;
                        ST32(r2, r1);
                    } else {
                        c7 = r0 == 8;
                        if (r7 > r1) {
                            c14 = r7 > 128;
                            if (r7 == 128) {
                                ST32(0x06078024, 0);
                                r2 = LD32(0x06088028);
                                ST32(r2 + 24, 1);
                                r2 = 0x060766C0;
                                r1 = -12;
                                ST32(r2, r1);
                            } else {
                                r0 = r7;
                                if (c14) {
                                    if (r7 == 129) {
                                        r0 = GCALL1(0x060339D0, 0);
                                        if (!((r0 & r0) == 0)) {
                                            r2 = LD32(r11);
                                            ST32(r2 + 24, 1);
                                            r2 = 0x060766C0;
                                            r1 = -19;
                                        } else {
                                            r2 = LD32(0x06088028);
                                            ST32(r2 + 24, 1);
                                            r2 = 0x060766C0;
                                            r1 = -12;
                                        }
                                        ST32(r2, r1);
                                    } else {
                                        if (r7 == 141) {
                                            r1 = 0x0602F6CC;
                                            r5 = 1;
                                            r0 = GCALL4(r1, r8, r5, r6, r7);
                                            r2 = LD32(0x06088028);
                                            ST32(r2 + 24, 1);
                                            r2 = 0x060766C0;
                                            r1 = -12;
                                            ST32(r2, r1);
                                        } else {
                                            r0 = GCALL1(0x060111D8, r8);
                                            if (!((r0 & r0) == 0)) {
                                                r2 = LD32(0x06088028);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -12;
                                                ST32(r2, r1);
                                            } else {
                                                r1 = LD8(0x0608AF53);
                                                r7 = r8;
                                                if (!((r1 & r1) == 0)) {
                                                    r7 = r7 + 24;
                                                    r3 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    r1 = LD8(((r3 + r2) - 1));
                                                    r0 = r2;
                                                    ST8(r0 + r3, r1);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) - 1), -128);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) + 1), 0);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) + 2), 0);
                                                    r1 = LD16(r7);
                                                    ST16(r7, (r1 + 1));
                                                }
                                                r2 = LD32(r9 + 44);
                                                c27 = r10 >= r2;
                                                if (!((r2 & r2) == 0)) {
                                                    r3 = r8;
                                                    if (c27) {
                                                        r3 = r3 + 24;
                                                        r1 = LD16(r3);
                                                        if (r1 >= r2) {
                                                            ST16(r3, r2);
                                                        }
                                                        r3 = LD32(r8 + 20);
                                                        r2 = LD32(r9 + 44);
                                                        ST8(r3 + r2, 0);
                                                        r4 = LD32(r8 + 20);
                                                        r0 = GCALL1(0x0607507C, r4);
                                                        r10 = r0;
                                                    }
                                                }
                                                r2 = LD32(r9 + 56);
                                                r1 = r2;
                                                if (!(r10 > (r2 - 5))) {
                                                    r1 = LD32(r9 + 56);
                                                    c31 = r10 > (r1 - 3);
                                                    r1 = -20;
                                                    if (!(c31)) {
                                                        r2 = LD32(0x06088028);
                                                        ST32(r2 + 24, 1);
                                                        r2 = 0x060766C0;
                                                        r1 = -12;
                                                        ST32(r2, r1);
                                                    } else {
                                                        ST32(0x060766C0, r1);
                                                        r1 = LD32(r9 + 56);
                                                        r2 = LD32(r8 + 20);
                                                        r4 = r8 + 24;
                                                        ST8(((r1 + r2) - 3), 0);
                                                        r3 = LD16(r4);
                                                        r1 = LD32(r9 + 56);
                                                        c32 = ((short)r3) > (r1 - 3);
                                                        r1 = r3;
                                                        if (c32) {
                                                            ST16(r4, (r1 - 1));
                                                        }
                                                    }
                                                } else {
                                                    c30 = r10 >= (r1 - 3);
                                                    r1 = -20;
                                                    if (c30) {
                                                        r1 = LD32(r9 + 56);
                                                        c31 = r10 > (r1 - 3);
                                                        r1 = -20;
                                                        if (!(c31)) {
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                            r2 = 0x060766C0;
                                                            r1 = -12;
                                                            ST32(r2, r1);
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r1 = LD32(r9 + 56);
                                                            r2 = LD32(r8 + 20);
                                                            r4 = r8 + 24;
                                                            ST8(((r1 + r2) - 3), 0);
                                                            r3 = LD16(r4);
                                                            r1 = LD32(r9 + 56);
                                                            c32 = ((short)r3) > (r1 - 3);
                                                            r1 = r3;
                                                            if (c32) {
                                                                ST16(r4, (r1 - 1));
                                                            }
                                                        }
                                                    } else {
                                                        ST32(0x060766C0, r1);
                                                        r2 = LD32(0x06088028);
                                                        ST32(r2 + 24, 1);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    c16 = r0 == 27;
                                    if (r0 == 23) {
                                        r3 = r8 + 24;
                                        r2 = LD16(r3);
                                        r1 = LD32(r8 + 20);
                                        r0 = r2;
                                        r1 = LD8(r0 + r1);
                                        c23 = ((r1 & 255) & (r1 & 255)) == 0;
                                        r1 = r2;
                                        if (!(c23)) {
                                            ST16(r3, (r1 + 1));
                                        }
                                        r2 = LD32(0x06088028);
                                        ST32(r2 + 24, 1);
                                        r2 = 0x060766C0;
                                        r1 = -12;
                                        ST32(r2, r1);
                                    } else {
                                        r2 = 0;
                                        if (c16) {
                                            r1 = LD32(r8 + 20);
                                            ST8(r1, r3);
                                            ST16((r8 + 24), r2);
                                            ST16((r8 + 26), r2);
                                            r2 = LD32(0x06088028);
                                            ST32(r2 + 24, 1);
                                            r2 = 0x060766C0;
                                            r1 = -12;
                                            ST32(r2, r1);
                                        } else {
                                            r0 = GCALL1(0x060111D8, r8);
                                            if (!((r0 & r0) == 0)) {
                                                r2 = LD32(0x06088028);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -12;
                                                ST32(r2, r1);
                                            } else {
                                                r1 = LD8(0x0608AF53);
                                                r7 = r8;
                                                if (!((r1 & r1) == 0)) {
                                                    r7 = r7 + 24;
                                                    r3 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    r1 = LD8(((r3 + r2) - 1));
                                                    r0 = r2;
                                                    ST8(r0 + r3, r1);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) - 1), -128);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) + 1), 0);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) + 2), 0);
                                                    r1 = LD16(r7);
                                                    ST16(r7, (r1 + 1));
                                                }
                                                r2 = LD32(r9 + 44);
                                                c27 = r10 >= r2;
                                                if (!((r2 & r2) == 0)) {
                                                    r3 = r8;
                                                    if (c27) {
                                                        r3 = r3 + 24;
                                                        r1 = LD16(r3);
                                                        if (r1 >= r2) {
                                                            ST16(r3, r2);
                                                        }
                                                        r3 = LD32(r8 + 20);
                                                        r2 = LD32(r9 + 44);
                                                        ST8(r3 + r2, 0);
                                                        r4 = LD32(r8 + 20);
                                                        r0 = GCALL1(0x0607507C, r4);
                                                        r10 = r0;
                                                    }
                                                }
                                                r2 = LD32(r9 + 56);
                                                r1 = r2;
                                                if (!(r10 > (r2 - 5))) {
                                                    r1 = LD32(r9 + 56);
                                                    c31 = r10 > (r1 - 3);
                                                    r1 = -20;
                                                    if (!(c31)) {
                                                        r2 = LD32(0x06088028);
                                                        ST32(r2 + 24, 1);
                                                        r2 = 0x060766C0;
                                                        r1 = -12;
                                                        ST32(r2, r1);
                                                    } else {
                                                        ST32(0x060766C0, r1);
                                                        r1 = LD32(r9 + 56);
                                                        r2 = LD32(r8 + 20);
                                                        r4 = r8 + 24;
                                                        ST8(((r1 + r2) - 3), 0);
                                                        r3 = LD16(r4);
                                                        r1 = LD32(r9 + 56);
                                                        c32 = ((short)r3) > (r1 - 3);
                                                        r1 = r3;
                                                        if (c32) {
                                                            ST16(r4, (r1 - 1));
                                                        }
                                                    }
                                                } else {
                                                    c30 = r10 >= (r1 - 3);
                                                    r1 = -20;
                                                    if (c30) {
                                                        r1 = LD32(r9 + 56);
                                                        c31 = r10 > (r1 - 3);
                                                        r1 = -20;
                                                        if (!(c31)) {
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                            r2 = 0x060766C0;
                                                            r1 = -12;
                                                            ST32(r2, r1);
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r1 = LD32(r9 + 56);
                                                            r2 = LD32(r8 + 20);
                                                            r4 = r8 + 24;
                                                            ST8(((r1 + r2) - 3), 0);
                                                            r3 = LD16(r4);
                                                            r1 = LD32(r9 + 56);
                                                            c32 = ((short)r3) > (r1 - 3);
                                                            r1 = r3;
                                                            if (c32) {
                                                                ST16(r4, (r1 - 1));
                                                            }
                                                        }
                                                    } else {
                                                        ST32(0x060766C0, r1);
                                                        r2 = LD32(0x06088028);
                                                        ST32(r2 + 24, 1);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            r1 = 8;
                            if (c7) {
                                r1 = 0x0602F6CC;
                                r5 = 0;
                                r0 = GCALL4(r1, r8, r5, r6, r7);
                                r2 = LD32(0x06088028);
                                ST32(r2 + 24, 1);
                                r2 = 0x060766C0;
                                r1 = -12;
                                ST32(r2, r1);
                            } else {
                                c9 = r0 == 4;
                                if (r7 > r1) {
                                    if (r0 == 9) {
                                        r0 = GCALL1(0x060339D0, 1);
                                        if (!((r0 & r0) == 0)) {
                                            r2 = LD32(r11);
                                            ST32(r2 + 24, 1);
                                            r2 = 0x060766C0;
                                            r1 = -18;
                                        } else {
                                            r2 = LD32(0x06088028);
                                            ST32(r2 + 24, 1);
                                            r2 = 0x060766C0;
                                            r1 = -12;
                                        }
                                        ST32(r2, r1);
                                    } else {
                                        r1 = 0;
                                        if (r0 == 13) {
                                            ST32(0x06078024, r1);
                                            r1 = LD32((r9 + 72));
                                            r0 = LD8((r1 + 24));
                                            if (r0 == 1) {
                                                r6 = LD32(r9 + 16);
                                                r1 = LD32(0x060759B4);
                                                r5 = LD16((r9 + 12));
                                                r0 = GCALL3(0x06038A10, r9, (r5 - 1), (r6 - (r1 + 1)));
                                                ST32(0x060766C0, r0);
                                            }
                                        } else {
                                            r0 = GCALL1(0x060111D8, r8);
                                            if (!((r0 & r0) == 0)) {
                                                r2 = LD32(0x06088028);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -12;
                                                ST32(r2, r1);
                                            } else {
                                                r1 = LD8(0x0608AF53);
                                                r7 = r8;
                                                if (!((r1 & r1) == 0)) {
                                                    r7 = r7 + 24;
                                                    r3 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    r1 = LD8(((r3 + r2) - 1));
                                                    r0 = r2;
                                                    ST8(r0 + r3, r1);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) - 1), -128);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) + 1), 0);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) + 2), 0);
                                                    r1 = LD16(r7);
                                                    ST16(r7, (r1 + 1));
                                                }
                                                r2 = LD32(r9 + 44);
                                                c27 = r10 >= r2;
                                                if (!((r2 & r2) == 0)) {
                                                    r3 = r8;
                                                    if (c27) {
                                                        r3 = r3 + 24;
                                                        r1 = LD16(r3);
                                                        if (r1 >= r2) {
                                                            ST16(r3, r2);
                                                        }
                                                        r3 = LD32(r8 + 20);
                                                        r2 = LD32(r9 + 44);
                                                        ST8(r3 + r2, 0);
                                                        r4 = LD32(r8 + 20);
                                                        r0 = GCALL1(0x0607507C, r4);
                                                        r10 = r0;
                                                    }
                                                }
                                                r2 = LD32(r9 + 56);
                                                r1 = r2;
                                                if (!(r10 > (r2 - 5))) {
                                                    r1 = LD32(r9 + 56);
                                                    c31 = r10 > (r1 - 3);
                                                    r1 = -20;
                                                    if (!(c31)) {
                                                        r2 = LD32(0x06088028);
                                                        ST32(r2 + 24, 1);
                                                        r2 = 0x060766C0;
                                                        r1 = -12;
                                                        ST32(r2, r1);
                                                    } else {
                                                        ST32(0x060766C0, r1);
                                                        r1 = LD32(r9 + 56);
                                                        r2 = LD32(r8 + 20);
                                                        r4 = r8 + 24;
                                                        ST8(((r1 + r2) - 3), 0);
                                                        r3 = LD16(r4);
                                                        r1 = LD32(r9 + 56);
                                                        c32 = ((short)r3) > (r1 - 3);
                                                        r1 = r3;
                                                        if (c32) {
                                                            ST16(r4, (r1 - 1));
                                                        }
                                                    }
                                                } else {
                                                    c30 = r10 >= (r1 - 3);
                                                    r1 = -20;
                                                    if (c30) {
                                                        r1 = LD32(r9 + 56);
                                                        c31 = r10 > (r1 - 3);
                                                        r1 = -20;
                                                        if (!(c31)) {
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                            r2 = 0x060766C0;
                                                            r1 = -12;
                                                            ST32(r2, r1);
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r1 = LD32(r9 + 56);
                                                            r2 = LD32(r8 + 20);
                                                            r4 = r8 + 24;
                                                            ST8(((r1 + r2) - 3), 0);
                                                            r3 = LD16(r4);
                                                            r1 = LD32(r9 + 56);
                                                            c32 = ((short)r3) > (r1 - 3);
                                                            r1 = r3;
                                                            if (c32) {
                                                                ST16(r4, (r1 - 1));
                                                            }
                                                        }
                                                    } else {
                                                        ST32(0x060766C0, r1);
                                                        r2 = LD32(0x06088028);
                                                        ST32(r2 + 24, 1);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    c10 = r0 == 7;
                                    if (c9) {
                                        r0 = GCALL1(0x06032164, 4);
                                        r2 = LD32(0x06088028);
                                        ST32(r2 + 24, 1);
                                        r2 = 0x060766C0;
                                        r1 = -12;
                                        ST32(r2, r1);
                                    } else {
                                        if (c10) {
                                            ST32(0x06078024, 0);
                                            r2 = LD32(0x06088028);
                                            ST32(r2 + 24, 1);
                                            r2 = 0x060766C0;
                                            r1 = -12;
                                            ST32(r2, r1);
                                        } else {
                                            r0 = GCALL1(0x060111D8, r8);
                                            if (!((r0 & r0) == 0)) {
                                                r2 = LD32(0x06088028);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -12;
                                                ST32(r2, r1);
                                            } else {
                                                r1 = LD8(0x0608AF53);
                                                r7 = r8;
                                                if (!((r1 & r1) == 0)) {
                                                    r7 = r7 + 24;
                                                    r3 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    r1 = LD8(((r3 + r2) - 1));
                                                    r0 = r2;
                                                    ST8(r0 + r3, r1);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) - 1), -128);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) + 1), 0);
                                                    r1 = LD16(r7);
                                                    r2 = LD32(r8 + 20);
                                                    ST8(((r1 + r2) + 2), 0);
                                                    r1 = LD16(r7);
                                                    ST16(r7, (r1 + 1));
                                                }
                                                r2 = LD32(r9 + 44);
                                                c27 = r10 >= r2;
                                                if (!((r2 & r2) == 0)) {
                                                    r3 = r8;
                                                    if (c27) {
                                                        r3 = r3 + 24;
                                                        r1 = LD16(r3);
                                                        if (r1 >= r2) {
                                                            ST16(r3, r2);
                                                        }
                                                        r3 = LD32(r8 + 20);
                                                        r2 = LD32(r9 + 44);
                                                        ST8(r3 + r2, 0);
                                                        r4 = LD32(r8 + 20);
                                                        r0 = GCALL1(0x0607507C, r4);
                                                        r10 = r0;
                                                    }
                                                }
                                                r2 = LD32(r9 + 56);
                                                r1 = r2;
                                                if (!(r10 > (r2 - 5))) {
                                                    r1 = LD32(r9 + 56);
                                                    c31 = r10 > (r1 - 3);
                                                    r1 = -20;
                                                    if (!(c31)) {
                                                        r2 = LD32(0x06088028);
                                                        ST32(r2 + 24, 1);
                                                        r2 = 0x060766C0;
                                                        r1 = -12;
                                                        ST32(r2, r1);
                                                    } else {
                                                        ST32(0x060766C0, r1);
                                                        r1 = LD32(r9 + 56);
                                                        r2 = LD32(r8 + 20);
                                                        r4 = r8 + 24;
                                                        ST8(((r1 + r2) - 3), 0);
                                                        r3 = LD16(r4);
                                                        r1 = LD32(r9 + 56);
                                                        c32 = ((short)r3) > (r1 - 3);
                                                        r1 = r3;
                                                        if (c32) {
                                                            ST16(r4, (r1 - 1));
                                                        }
                                                    }
                                                } else {
                                                    c30 = r10 >= (r1 - 3);
                                                    r1 = -20;
                                                    if (c30) {
                                                        r1 = LD32(r9 + 56);
                                                        c31 = r10 > (r1 - 3);
                                                        r1 = -20;
                                                        if (!(c31)) {
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                            r2 = 0x060766C0;
                                                            r1 = -12;
                                                            ST32(r2, r1);
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r1 = LD32(r9 + 56);
                                                            r2 = LD32(r8 + 20);
                                                            r4 = r8 + 24;
                                                            ST8(((r1 + r2) - 3), 0);
                                                            r3 = LD16(r4);
                                                            r1 = LD32(r9 + 56);
                                                            c32 = ((short)r3) > (r1 - 3);
                                                            r1 = r3;
                                                            if (c32) {
                                                                ST16(r4, (r1 - 1));
                                                            }
                                                        }
                                                    } else {
                                                        ST32(0x060766C0, r1);
                                                        r2 = LD32(0x06088028);
                                                        ST32(r2 + 24, 1);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (c4) {
                        r0 = r7;
                        r1 = 22;
                        if (r0 == 22) {
                            r2 = r8 + 24;
                            r1 = LD16(r2);
                            r1 = r1 - 1;
                            ST16(r2, r1);
                            c22 = ((short)r1) >= 0;
                            r1 = 0;
                            if (!(c22)) {
                                ST16(r2, r1);
                            }
                            r2 = LD32(0x06088028);
                            ST32(r2 + 24, 1);
                            r2 = 0x060766C0;
                            r1 = -12;
                            ST32(r2, r1);
                        } else {
                            c7 = r0 == 8;
                            if (r7 > r1) {
                                c14 = r7 > 128;
                                if (r7 == 128) {
                                    ST32(0x06078024, 0);
                                    r2 = LD32(0x06088028);
                                    ST32(r2 + 24, 1);
                                    r2 = 0x060766C0;
                                    r1 = -12;
                                    ST32(r2, r1);
                                } else {
                                    r0 = r7;
                                    if (c14) {
                                        if (r7 == 129) {
                                            r0 = GCALL1(0x060339D0, 0);
                                            if (!((r0 & r0) == 0)) {
                                                r2 = LD32(r11);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -19;
                                            } else {
                                                r2 = LD32(0x06088028);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -12;
                                            }
                                            ST32(r2, r1);
                                        } else {
                                            if (r7 == 141) {
                                                r1 = 0x0602F6CC;
                                                r5 = 1;
                                                r0 = GCALL4(r1, r8, r5, r6, r7);
                                                r2 = LD32(0x06088028);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -12;
                                                ST32(r2, r1);
                                            } else {
                                                r0 = GCALL1(0x060111D8, r8);
                                                if (!((r0 & r0) == 0)) {
                                                    r2 = LD32(0x06088028);
                                                    ST32(r2 + 24, 1);
                                                    r2 = 0x060766C0;
                                                    r1 = -12;
                                                    ST32(r2, r1);
                                                } else {
                                                    r1 = LD8(0x0608AF53);
                                                    r7 = r8;
                                                    if (!((r1 & r1) == 0)) {
                                                        r7 = r7 + 24;
                                                        r3 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        r1 = LD8(((r3 + r2) - 1));
                                                        r0 = r2;
                                                        ST8(r0 + r3, r1);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) - 1), -128);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) + 1), 0);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) + 2), 0);
                                                        r1 = LD16(r7);
                                                        ST16(r7, (r1 + 1));
                                                    }
                                                    r2 = LD32(r9 + 44);
                                                    c27 = r10 >= r2;
                                                    if (!((r2 & r2) == 0)) {
                                                        r3 = r8;
                                                        if (c27) {
                                                            r3 = r3 + 24;
                                                            r1 = LD16(r3);
                                                            if (r1 >= r2) {
                                                                ST16(r3, r2);
                                                            }
                                                            r3 = LD32(r8 + 20);
                                                            r2 = LD32(r9 + 44);
                                                            ST8(r3 + r2, 0);
                                                            r4 = LD32(r8 + 20);
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r10 = r0;
                                                        }
                                                    }
                                                    r2 = LD32(r9 + 56);
                                                    r1 = r2;
                                                    if (!(r10 > (r2 - 5))) {
                                                        r1 = LD32(r9 + 56);
                                                        c31 = r10 > (r1 - 3);
                                                        r1 = -20;
                                                        if (!(c31)) {
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                            r2 = 0x060766C0;
                                                            r1 = -12;
                                                            ST32(r2, r1);
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r1 = LD32(r9 + 56);
                                                            r2 = LD32(r8 + 20);
                                                            r4 = r8 + 24;
                                                            ST8(((r1 + r2) - 3), 0);
                                                            r3 = LD16(r4);
                                                            r1 = LD32(r9 + 56);
                                                            c32 = ((short)r3) > (r1 - 3);
                                                            r1 = r3;
                                                            if (c32) {
                                                                ST16(r4, (r1 - 1));
                                                            }
                                                        }
                                                    } else {
                                                        c30 = r10 >= (r1 - 3);
                                                        r1 = -20;
                                                        if (c30) {
                                                            r1 = LD32(r9 + 56);
                                                            c31 = r10 > (r1 - 3);
                                                            r1 = -20;
                                                            if (!(c31)) {
                                                                r2 = LD32(0x06088028);
                                                                ST32(r2 + 24, 1);
                                                                r2 = 0x060766C0;
                                                                r1 = -12;
                                                                ST32(r2, r1);
                                                            } else {
                                                                ST32(0x060766C0, r1);
                                                                r1 = LD32(r9 + 56);
                                                                r2 = LD32(r8 + 20);
                                                                r4 = r8 + 24;
                                                                ST8(((r1 + r2) - 3), 0);
                                                                r3 = LD16(r4);
                                                                r1 = LD32(r9 + 56);
                                                                c32 = ((short)r3) > (r1 - 3);
                                                                r1 = r3;
                                                                if (c32) {
                                                                    ST16(r4, (r1 - 1));
                                                                }
                                                            }
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        c16 = r0 == 27;
                                        if (r0 == 23) {
                                            r3 = r8 + 24;
                                            r2 = LD16(r3);
                                            r1 = LD32(r8 + 20);
                                            r0 = r2;
                                            r1 = LD8(r0 + r1);
                                            c23 = ((r1 & 255) & (r1 & 255)) == 0;
                                            r1 = r2;
                                            if (!(c23)) {
                                                ST16(r3, (r1 + 1));
                                            }
                                            r2 = LD32(0x06088028);
                                            ST32(r2 + 24, 1);
                                            r2 = 0x060766C0;
                                            r1 = -12;
                                            ST32(r2, r1);
                                        } else {
                                            r2 = 0;
                                            if (c16) {
                                                r1 = LD32(r8 + 20);
                                                ST8(r1, r3);
                                                ST16((r8 + 24), r2);
                                                ST16((r8 + 26), r2);
                                                r2 = LD32(0x06088028);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -12;
                                                ST32(r2, r1);
                                            } else {
                                                r0 = GCALL1(0x060111D8, r8);
                                                if (!((r0 & r0) == 0)) {
                                                    r2 = LD32(0x06088028);
                                                    ST32(r2 + 24, 1);
                                                    r2 = 0x060766C0;
                                                    r1 = -12;
                                                    ST32(r2, r1);
                                                } else {
                                                    r1 = LD8(0x0608AF53);
                                                    r7 = r8;
                                                    if (!((r1 & r1) == 0)) {
                                                        r7 = r7 + 24;
                                                        r3 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        r1 = LD8(((r3 + r2) - 1));
                                                        r0 = r2;
                                                        ST8(r0 + r3, r1);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) - 1), -128);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) + 1), 0);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) + 2), 0);
                                                        r1 = LD16(r7);
                                                        ST16(r7, (r1 + 1));
                                                    }
                                                    r2 = LD32(r9 + 44);
                                                    c27 = r10 >= r2;
                                                    if (!((r2 & r2) == 0)) {
                                                        r3 = r8;
                                                        if (c27) {
                                                            r3 = r3 + 24;
                                                            r1 = LD16(r3);
                                                            if (r1 >= r2) {
                                                                ST16(r3, r2);
                                                            }
                                                            r3 = LD32(r8 + 20);
                                                            r2 = LD32(r9 + 44);
                                                            ST8(r3 + r2, 0);
                                                            r4 = LD32(r8 + 20);
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r10 = r0;
                                                        }
                                                    }
                                                    r2 = LD32(r9 + 56);
                                                    r1 = r2;
                                                    if (!(r10 > (r2 - 5))) {
                                                        r1 = LD32(r9 + 56);
                                                        c31 = r10 > (r1 - 3);
                                                        r1 = -20;
                                                        if (!(c31)) {
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                            r2 = 0x060766C0;
                                                            r1 = -12;
                                                            ST32(r2, r1);
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r1 = LD32(r9 + 56);
                                                            r2 = LD32(r8 + 20);
                                                            r4 = r8 + 24;
                                                            ST8(((r1 + r2) - 3), 0);
                                                            r3 = LD16(r4);
                                                            r1 = LD32(r9 + 56);
                                                            c32 = ((short)r3) > (r1 - 3);
                                                            r1 = r3;
                                                            if (c32) {
                                                                ST16(r4, (r1 - 1));
                                                            }
                                                        }
                                                    } else {
                                                        c30 = r10 >= (r1 - 3);
                                                        r1 = -20;
                                                        if (c30) {
                                                            r1 = LD32(r9 + 56);
                                                            c31 = r10 > (r1 - 3);
                                                            r1 = -20;
                                                            if (!(c31)) {
                                                                r2 = LD32(0x06088028);
                                                                ST32(r2 + 24, 1);
                                                                r2 = 0x060766C0;
                                                                r1 = -12;
                                                                ST32(r2, r1);
                                                            } else {
                                                                ST32(0x060766C0, r1);
                                                                r1 = LD32(r9 + 56);
                                                                r2 = LD32(r8 + 20);
                                                                r4 = r8 + 24;
                                                                ST8(((r1 + r2) - 3), 0);
                                                                r3 = LD16(r4);
                                                                r1 = LD32(r9 + 56);
                                                                c32 = ((short)r3) > (r1 - 3);
                                                                r1 = r3;
                                                                if (c32) {
                                                                    ST16(r4, (r1 - 1));
                                                                }
                                                            }
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                r1 = 8;
                                if (c7) {
                                    r1 = 0x0602F6CC;
                                    r5 = 0;
                                    r0 = GCALL4(r1, r8, r5, r6, r7);
                                    r2 = LD32(0x06088028);
                                    ST32(r2 + 24, 1);
                                    r2 = 0x060766C0;
                                    r1 = -12;
                                    ST32(r2, r1);
                                } else {
                                    c9 = r0 == 4;
                                    if (r7 > r1) {
                                        if (r0 == 9) {
                                            r0 = GCALL1(0x060339D0, 1);
                                            if (!((r0 & r0) == 0)) {
                                                r2 = LD32(r11);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -18;
                                            } else {
                                                r2 = LD32(0x06088028);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -12;
                                            }
                                            ST32(r2, r1);
                                        } else {
                                            r1 = 0;
                                            if (r0 == 13) {
                                                ST32(0x06078024, r1);
                                                r1 = LD32((r9 + 72));
                                                r0 = LD8((r1 + 24));
                                                if (r0 == 1) {
                                                    r6 = LD32(r9 + 16);
                                                    r1 = LD32(0x060759B4);
                                                    r5 = LD16((r9 + 12));
                                                    r0 = GCALL3(0x06038A10, r9, (r5 - 1), (r6 - (r1 + 1)));
                                                    ST32(0x060766C0, r0);
                                                }
                                            } else {
                                                r0 = GCALL1(0x060111D8, r8);
                                                if (!((r0 & r0) == 0)) {
                                                    r2 = LD32(0x06088028);
                                                    ST32(r2 + 24, 1);
                                                    r2 = 0x060766C0;
                                                    r1 = -12;
                                                    ST32(r2, r1);
                                                } else {
                                                    r1 = LD8(0x0608AF53);
                                                    r7 = r8;
                                                    if (!((r1 & r1) == 0)) {
                                                        r7 = r7 + 24;
                                                        r3 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        r1 = LD8(((r3 + r2) - 1));
                                                        r0 = r2;
                                                        ST8(r0 + r3, r1);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) - 1), -128);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) + 1), 0);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) + 2), 0);
                                                        r1 = LD16(r7);
                                                        ST16(r7, (r1 + 1));
                                                    }
                                                    r2 = LD32(r9 + 44);
                                                    c27 = r10 >= r2;
                                                    if (!((r2 & r2) == 0)) {
                                                        r3 = r8;
                                                        if (c27) {
                                                            r3 = r3 + 24;
                                                            r1 = LD16(r3);
                                                            if (r1 >= r2) {
                                                                ST16(r3, r2);
                                                            }
                                                            r3 = LD32(r8 + 20);
                                                            r2 = LD32(r9 + 44);
                                                            ST8(r3 + r2, 0);
                                                            r4 = LD32(r8 + 20);
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r10 = r0;
                                                        }
                                                    }
                                                    r2 = LD32(r9 + 56);
                                                    r1 = r2;
                                                    if (!(r10 > (r2 - 5))) {
                                                        r1 = LD32(r9 + 56);
                                                        c31 = r10 > (r1 - 3);
                                                        r1 = -20;
                                                        if (!(c31)) {
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                            r2 = 0x060766C0;
                                                            r1 = -12;
                                                            ST32(r2, r1);
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r1 = LD32(r9 + 56);
                                                            r2 = LD32(r8 + 20);
                                                            r4 = r8 + 24;
                                                            ST8(((r1 + r2) - 3), 0);
                                                            r3 = LD16(r4);
                                                            r1 = LD32(r9 + 56);
                                                            c32 = ((short)r3) > (r1 - 3);
                                                            r1 = r3;
                                                            if (c32) {
                                                                ST16(r4, (r1 - 1));
                                                            }
                                                        }
                                                    } else {
                                                        c30 = r10 >= (r1 - 3);
                                                        r1 = -20;
                                                        if (c30) {
                                                            r1 = LD32(r9 + 56);
                                                            c31 = r10 > (r1 - 3);
                                                            r1 = -20;
                                                            if (!(c31)) {
                                                                r2 = LD32(0x06088028);
                                                                ST32(r2 + 24, 1);
                                                                r2 = 0x060766C0;
                                                                r1 = -12;
                                                                ST32(r2, r1);
                                                            } else {
                                                                ST32(0x060766C0, r1);
                                                                r1 = LD32(r9 + 56);
                                                                r2 = LD32(r8 + 20);
                                                                r4 = r8 + 24;
                                                                ST8(((r1 + r2) - 3), 0);
                                                                r3 = LD16(r4);
                                                                r1 = LD32(r9 + 56);
                                                                c32 = ((short)r3) > (r1 - 3);
                                                                r1 = r3;
                                                                if (c32) {
                                                                    ST16(r4, (r1 - 1));
                                                                }
                                                            }
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        c10 = r0 == 7;
                                        if (c9) {
                                            r0 = GCALL1(0x06032164, 4);
                                            r2 = LD32(0x06088028);
                                            ST32(r2 + 24, 1);
                                            r2 = 0x060766C0;
                                            r1 = -12;
                                            ST32(r2, r1);
                                        } else {
                                            if (c10) {
                                                ST32(0x06078024, 0);
                                                r2 = LD32(0x06088028);
                                                ST32(r2 + 24, 1);
                                                r2 = 0x060766C0;
                                                r1 = -12;
                                                ST32(r2, r1);
                                            } else {
                                                r0 = GCALL1(0x060111D8, r8);
                                                if (!((r0 & r0) == 0)) {
                                                    r2 = LD32(0x06088028);
                                                    ST32(r2 + 24, 1);
                                                    r2 = 0x060766C0;
                                                    r1 = -12;
                                                    ST32(r2, r1);
                                                } else {
                                                    r1 = LD8(0x0608AF53);
                                                    r7 = r8;
                                                    if (!((r1 & r1) == 0)) {
                                                        r7 = r7 + 24;
                                                        r3 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        r1 = LD8(((r3 + r2) - 1));
                                                        r0 = r2;
                                                        ST8(r0 + r3, r1);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) - 1), -128);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) + 1), 0);
                                                        r1 = LD16(r7);
                                                        r2 = LD32(r8 + 20);
                                                        ST8(((r1 + r2) + 2), 0);
                                                        r1 = LD16(r7);
                                                        ST16(r7, (r1 + 1));
                                                    }
                                                    r2 = LD32(r9 + 44);
                                                    c27 = r10 >= r2;
                                                    if (!((r2 & r2) == 0)) {
                                                        r3 = r8;
                                                        if (c27) {
                                                            r3 = r3 + 24;
                                                            r1 = LD16(r3);
                                                            if (r1 >= r2) {
                                                                ST16(r3, r2);
                                                            }
                                                            r3 = LD32(r8 + 20);
                                                            r2 = LD32(r9 + 44);
                                                            ST8(r3 + r2, 0);
                                                            r4 = LD32(r8 + 20);
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r10 = r0;
                                                        }
                                                    }
                                                    r2 = LD32(r9 + 56);
                                                    r1 = r2;
                                                    if (!(r10 > (r2 - 5))) {
                                                        r1 = LD32(r9 + 56);
                                                        c31 = r10 > (r1 - 3);
                                                        r1 = -20;
                                                        if (!(c31)) {
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                            r2 = 0x060766C0;
                                                            r1 = -12;
                                                            ST32(r2, r1);
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r1 = LD32(r9 + 56);
                                                            r2 = LD32(r8 + 20);
                                                            r4 = r8 + 24;
                                                            ST8(((r1 + r2) - 3), 0);
                                                            r3 = LD16(r4);
                                                            r1 = LD32(r9 + 56);
                                                            c32 = ((short)r3) > (r1 - 3);
                                                            r1 = r3;
                                                            if (c32) {
                                                                ST16(r4, (r1 - 1));
                                                            }
                                                        }
                                                    } else {
                                                        c30 = r10 >= (r1 - 3);
                                                        r1 = -20;
                                                        if (c30) {
                                                            r1 = LD32(r9 + 56);
                                                            c31 = r10 > (r1 - 3);
                                                            r1 = -20;
                                                            if (!(c31)) {
                                                                r2 = LD32(0x06088028);
                                                                ST32(r2 + 24, 1);
                                                                r2 = 0x060766C0;
                                                                r1 = -12;
                                                                ST32(r2, r1);
                                                            } else {
                                                                ST32(0x060766C0, r1);
                                                                r1 = LD32(r9 + 56);
                                                                r2 = LD32(r8 + 20);
                                                                r4 = r8 + 24;
                                                                ST8(((r1 + r2) - 3), 0);
                                                                r3 = LD16(r4);
                                                                r1 = LD32(r9 + 56);
                                                                c32 = ((short)r3) > (r1 - 3);
                                                                r1 = r3;
                                                                if (c32) {
                                                                    ST16(r4, (r1 - 1));
                                                                }
                                                            }
                                                        } else {
                                                            ST32(0x060766C0, r1);
                                                            r2 = LD32(0x06088028);
                                                            ST32(r2 + 24, 1);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
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
void f0603739C(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, c2, c4, c5, c8, c12, c13, c15, c20, c21, c22, c25;
    FRAME(sp, 32);

    r10 = r4;
    r9 = r10 + 24;
    r3 = LD16(r9);
    r11 = r10 + 28;
    r1 = LD8(r11);
    r12 = 0x06088028;
    r13 = LD32(0x06088028);
    r7 = r1 & 255;
    r0 = r7;
    r8 = LD32(r13 + 40);
    if (!(r0 == 21)) {
        c2 = r0 == 8;
        if (r7 > 21) {
            r1 = 27;
            if (r0 == 27) {
                r0 = GCALL1(0x06032164, 4);
                r2 = LD32(0x06088028);
                ST32(r2 + 24, 1);
                ST32(0x060766C0, -12);
                ST8((r10 + 28), 0);
            } else {
                c12 = r0 == 22;
                if (r7 > r1) {
                    c15 = r7 > 129;
                    if (r7 == 129) {
                        r0 = GCALL1(0x060339D0, 0);
                        if (!((r0 & r0) == 0)) {
                            r2 = LD32(r12);
                            ST32(r2 + 24, 1);
                            r2 = 0x060766C0;
                            r1 = -19;
                            ST32(r2, r1);
                            ST8(r11, 0);
                        } else {
                            r2 = LD32(0x06088028);
                            ST32(r2 + 24, 1);
                            ST32(0x060766C0, -12);
                            ST8((r10 + 28), 0);
                        }
                    } else {
                        if (c15) {
                            r2 = 141;
                            if (r7 == 141) {
                                r1 = LD32(r10 + 20);
                                ST8(r1 + r3, r2);
                                r3 = r3 + 1;
                                r2 = LD32(r10 + 20);
                                r0 = r2;
                                ST8(r0 + r3, 0);
                                ST16(r9, r3);
                            } else {
                                r0 = GCALL1(0x060111D8, r10);
                                r1 = LD8(0x0608AF53);
                                r7 = r10;
                                if (!((r1 & r1) == 0)) {
                                    r7 = r7 + 24;
                                    r3 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    r1 = LD8(((r3 + r2) - 1));
                                    r0 = r2;
                                    ST8(r0 + r3, r1);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) - 1), -128);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) + 1), 0);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) + 2), 0);
                                    r1 = LD16(r7);
                                    ST16(r7, (r1 + 1));
                                }
                            }
                        } else {
                            if (r7 == 128) {
                                ST32(0x06078024, 0);
                            } else {
                                r0 = GCALL1(0x060111D8, r10);
                                r1 = LD8(0x0608AF53);
                                r7 = r10;
                                if (!((r1 & r1) == 0)) {
                                    r7 = r7 + 24;
                                    r3 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    r1 = LD8(((r3 + r2) - 1));
                                    r0 = r2;
                                    ST8(r0 + r3, r1);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) - 1), -128);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) + 1), 0);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) + 2), 0);
                                    r1 = LD16(r7);
                                    ST16(r7, (r1 + 1));
                                }
                            }
                        }
                        r2 = LD32(0x06088028);
                        ST32(r2 + 24, 1);
                        ST32(0x060766C0, -12);
                        ST8((r10 + 28), 0);
                    }
                } else {
                    c13 = r0 == 23;
                    if (c12) {
                        r1 = LD32(r8 + 28);
                        c20 = r1 > 0;
                        r1 = r1 - 1;
                        if (!(c20)) {
                            r1 = LD32(r8 + 24);
                            c21 = r1 > 0;
                            r1 = r1 - 1;
                            if (c21) {
                                ST32(r8 + 24, r1);
                                r2 = LD32(r8 + 4);
                                r4 = LD32((r1 << 2) + r2);
                                r0 = GCALL1(0x0607507C, r4);
                                r1 = r0;
                                ST32(r8 + 28, r1);
                            }
                        } else {
                            ST32(r8 + 28, r1);
                        }
                        r0 = GCALL1(0x060378C8, r13);
                    } else {
                        if (!(c13)) {
                            r0 = GCALL1(0x060111D8, r10);
                            r1 = LD8(0x0608AF53);
                            r7 = r10;
                            if (!((r1 & r1) == 0)) {
                                r7 = r7 + 24;
                                r3 = LD16(r7);
                                r2 = LD32(r10 + 20);
                                r1 = LD8(((r3 + r2) - 1));
                                r0 = r2;
                                ST8(r0 + r3, r1);
                                r1 = LD16(r7);
                                r2 = LD32(r10 + 20);
                                ST8(((r1 + r2) - 1), -128);
                                r1 = LD16(r7);
                                r2 = LD32(r10 + 20);
                                ST8(((r1 + r2) + 1), 0);
                                r1 = LD16(r7);
                                r2 = LD32(r10 + 20);
                                ST8(((r1 + r2) + 2), 0);
                                r1 = LD16(r7);
                                ST16(r7, (r1 + 1));
                            }
                        } else {
                            r1 = LD32(r8 + 24);
                            r2 = LD32(r8 + 4);
                            r9 = 0x0607507C;
                            r4 = LD32((r1 << 2) + r2);
                            r0 = GCALL1(0x0607507C, r4);
                            r1 = LD32(r8 + 28);
                            c22 = (unsigned)r1 >= (unsigned)r0;
                            r1 = r1 + 1;
                            if (c22) {
                                r1 = LD32(r8 + 24);
                                r2 = LD32(r8 + 4);
                                r1 = r1 + 1;
                                ST32(r8 + 24, r1);
                                r4 = LD32((r1 << 2) + r2);
                                r0 = GCALL4(r9, r4, r5, r6, r7);
                                r2 = LD32(r8 + 24);
                                r1 = LD32(r8 + 20);
                                r3 = r0;
                                if (r2 >= r1) {
                                    r1 = r2;
                                    r1 = r1 - 1;
                                    ST32(r8 + 24, r1);
                                } else {
                                    r1 = 0;
                                    if ((r3 & r3) == 0) {
                                        r1 = r2;
                                        r1 = r1 - 1;
                                        ST32(r8 + 24, r1);
                                    } else {
                                        ST32(r8 + 28, r1);
                                    }
                                }
                            } else {
                                ST32(r8 + 28, r1);
                            }
                            r0 = GCALL1(0x060378C8, r13);
                        }
                    }
                    r2 = LD32(0x06088028);
                    ST32(r2 + 24, 1);
                    ST32(0x060766C0, -12);
                    ST8((r10 + 28), 0);
                }
            }
        } else {
            r1 = 8;
            if (c2) {
                r2 = LD32(r10 + 20);
                ST8(r2 + r3, 8);
                r3 = r3 + 1;
                r2 = LD32(r10 + 20);
                r0 = r2;
                ST8(r0 + r3, 0);
                ST16(r9, r3);
                r2 = LD32(0x06088028);
                ST32(r2 + 24, 1);
                ST32(0x060766C0, -12);
                ST8((r10 + 28), 0);
            } else {
                c4 = r0 == 4;
                if (r7 > r1) {
                    r1 = 13;
                    if (r0 == 13) {
                        r2 = LD32(r10 + 20);
                        ST8(r2 + r3, 10);
                        r3 = r3 + 1;
                        r2 = LD32(r10 + 20);
                        r0 = r2;
                        ST8(r0 + r3, 0);
                        ST16(r9, r3);
                        r2 = LD32(0x06088028);
                        ST32(r2 + 24, 1);
                        ST32(0x060766C0, -12);
                        ST8((r10 + 28), 0);
                    } else {
                        c8 = r0 == 9;
                        if (r7 > r1) {
                            r0 = r7;
                            if (!(r0 == 20)) {
                                r0 = GCALL1(0x060111D8, r10);
                                r1 = LD8(0x0608AF53);
                                r7 = r10;
                                if (!((r1 & r1) == 0)) {
                                    r7 = r7 + 24;
                                    r3 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    r1 = LD8(((r3 + r2) - 1));
                                    r0 = r2;
                                    ST8(r0 + r3, r1);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) - 1), -128);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) + 1), 0);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) + 2), 0);
                                    r1 = LD16(r7);
                                    ST16(r7, (r1 + 1));
                                }
                            } else {
                                r1 = LD32(r8 + 24);
                                c25 = r1 > 0;
                                r1 = r1 - 1;
                                if (c25) {
                                    ST32(r8 + 24, r1);
                                    r2 = LD32(r8 + 4);
                                    r4 = LD32((r1 << 2) + r2);
                                    r0 = GCALL1(0x0607507C, r4);
                                    r3 = r0;
                                    if (!((r3 & r3) == 0)) {
                                        r1 = LD32(r8 + 28);
                                        if (!(r3 >= r1)) {
                                            ST32(r8 + 28, r3);
                                        }
                                    } else {
                                        r1 = LD32(r8 + 24);
                                        r1 = r1 + 1;
                                        ST32(r8 + 24, r1);
                                    }
                                    r0 = GCALL1(0x060378C8, r13);
                                }
                            }
                            r2 = LD32(0x06088028);
                            ST32(r2 + 24, 1);
                            ST32(0x060766C0, -12);
                            ST8((r10 + 28), 0);
                        } else {
                            if (c8) {
                                r0 = GCALL1(0x060339D0, 1);
                                if (!((r0 & r0) == 0)) {
                                    r2 = LD32(r12);
                                    ST32(r2 + 24, 1);
                                    r2 = 0x060766C0;
                                    r1 = -18;
                                    ST32(r2, r1);
                                    ST8(r11, 0);
                                } else {
                                    r2 = LD32(0x06088028);
                                    ST32(r2 + 24, 1);
                                    ST32(0x060766C0, -12);
                                    ST8((r10 + 28), 0);
                                }
                            } else {
                                r0 = GCALL1(0x060111D8, r10);
                                r1 = LD8(0x0608AF53);
                                r7 = r10;
                                if (!((r1 & r1) == 0)) {
                                    r7 = r7 + 24;
                                    r3 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    r1 = LD8(((r3 + r2) - 1));
                                    r0 = r2;
                                    ST8(r0 + r3, r1);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) - 1), -128);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) + 1), 0);
                                    r1 = LD16(r7);
                                    r2 = LD32(r10 + 20);
                                    ST8(((r1 + r2) + 2), 0);
                                    r1 = LD16(r7);
                                    ST16(r7, (r1 + 1));
                                }
                                r2 = LD32(0x06088028);
                                ST32(r2 + 24, 1);
                                ST32(0x060766C0, -12);
                                ST8((r10 + 28), 0);
                            }
                        }
                    }
                } else {
                    c5 = r0 == 7;
                    if (c4) {
                        r0 = GCALL4(0x06048F28, (sp - 32), 0, 0, r7);
                        r1 = LD16(r9);
                        r4 = LD32(r10 + 20);
                        r5 = LD32(sp - 32);
                        r0 = GCALL2(0x060750DC, (r4 + r1), r5);
                        r4 = LD32(sp - 32);
                        r0 = GCALL1(0x0607507C, r4);
                        r1 = LD16(r9);
                        r1 = r1 + r0;
                        ST16(r9, r1);
                        r2 = LD32(r10 + 20);
                        r1 = (short)r1;
                        r3 = LD8(0x06037398);
                        r0 = r2;
                        ST8(r0 + r1, r3);
                        r2 = r2 + r1;
                        r1 = LD8(0x06037399);
                        ST8((r2 + 1), r1);
                        r1 = LD16(r9);
                        ST16(r9, (r1 + 1));
                    } else {
                        if (c5) {
                            ST32(0x06078024, 0);
                        } else {
                            r0 = GCALL1(0x060111D8, r10);
                            r1 = LD8(0x0608AF53);
                            r7 = r10;
                            if (!((r1 & r1) == 0)) {
                                r7 = r7 + 24;
                                r3 = LD16(r7);
                                r2 = LD32(r10 + 20);
                                r1 = LD8(((r3 + r2) - 1));
                                r0 = r2;
                                ST8(r0 + r3, r1);
                                r1 = LD16(r7);
                                r2 = LD32(r10 + 20);
                                ST8(((r1 + r2) - 1), -128);
                                r1 = LD16(r7);
                                r2 = LD32(r10 + 20);
                                ST8(((r1 + r2) + 1), 0);
                                r1 = LD16(r7);
                                r2 = LD32(r10 + 20);
                                ST8(((r1 + r2) + 2), 0);
                                r1 = LD16(r7);
                                ST16(r7, (r1 + 1));
                            }
                        }
                    }
                    r2 = LD32(0x06088028);
                    ST32(r2 + 24, 1);
                    ST32(0x060766C0, -12);
                    ST8((r10 + 28), 0);
                }
            }
        }
    } else {
        r1 = LD32(r8 + 24);
        r2 = LD32(r8 + 4);
        r1 = r1 + 1;
        ST32(r8 + 24, r1);
        r4 = LD32((r1 << 2) + r2);
        r0 = GCALL1(0x0607507C, r4);
        r2 = LD32(r8 + 24);
        r1 = LD32(r8 + 20);
        r3 = r0;
        if (r2 >= r1) {
            r1 = r2;
            r1 = r1 - 1;
            ST32(r8 + 24, r1);
        } else {
            r1 = r2;
            if ((r3 & r3) == 0) {
                r1 = r1 - 1;
                ST32(r8 + 24, r1);
            } else {
                r1 = LD32(r8 + 28);
                if (!(r3 >= r1)) {
                    ST32(r8 + 28, r3);
                }
            }
        }
        r0 = GCALL1(0x060378C8, r13);
        r2 = LD32(0x06088028);
        ST32(r2 + 24, 1);
        ST32(0x060766C0, -12);
        ST8((r10 + 28), 0);
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603AE98(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, c1;
    int v12;

    r8 = r4;
    r1 = LD32(r8 + 0x1DE0);
    r1 = LD32(r1 + 140);
    r1 = LD32(((r1 << 2) + r8) + 0x9DC);
    r0 = r1;
    c1 = r0 == 2;
    if (r0 == 1) {
        r1 = LD32(r8);
        r4 = r8;
        v12 = r1;
        r1 = 0x0603B100;
        r0 = GCALL5(r1, r4, r5, r6, r7, v12);
        r1 = LD32(r8 + 8);
        r2 = LD32(r8 + 4);
        if (r1 > r2) {
            ST32(r8 + 8, r2);
        }
        r0 = 0;
    } else {
        r6 = r6 + 1;
        if (!(c1)) {
            r0 = -302;
        } else {
            r1 = LD32(r8);
            v12 = r1;
            r1 = 0x0603B1DC;
            r6 = r6 >> 1;
            r0 = GCALL5(r1, r4, r5, r6, r7, v12);
            r1 = LD32(r8 + 8);
            r2 = LD32(r8 + 4);
            if (r1 > r2) {
                ST32(r8 + 8, r2);
            }
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06031BE8(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c2, c13;
    int v36;
    int v40;

    r10 = r4;
    r12 = r5;
    r11 = r6;
    r13 = 0x06031448;
    r0 = GCALL3(0x06031448, 4, r5, r6);
    r0 = LD16(r10);
    r6 = r11;
    if (!(r0 == -1)) {
        r2 = LD16(0x0607804A);
        r1 = LD16(0x06078048);
        r0 = GCALL3(r13, 1, (r12 + r1), (r6 + r2));
    }
    r14 = r10 + 2;
    r0 = LD16(r14);
    r9 = r11;
    if (!(r0 == -1)) {
        r2 = LD16(0x0607804E);
        r1 = LD16(0x0607804C);
        r9 = r9 + r2;
        r8 = r12 + r1;
        r0 = GCALL1(0x06031ABC, r10);
        r0 = GCALL3(r13, ((short)r0), r8, r9);
    }
    r2 = r10 + 6;
    r1 = LD16(r2);
    c2 = (r1 & r1) == 0;
    r1 = r10;
    if (c2) {
        r0 = GCALL6(0x0603157C, r10, r12, r11, 0, (-2), r2);
        r1 = r10;
    }
    r1 = r1 + 4;
    r0 = LD16(r1);
    if (r0 == 3) {
        r0 = GCALL6(0x0603157C, r10, r12, r11, 3, 2, r1);
    }
    r0 = LD16(r14);
    r4 = LD32(r10 + 28);
    if (!(r0 == 2)) {
        r1 = 125;
    } else {
        r0 = LD32(r10 + 4);
        r1 = 125;
        if (r0 == -1) {
            r1 = LD32(0x06089CB8);
            r2 = LD32(r10 + 24);
            r4 = r4 + (r1 - r2);
            r1 = 125;
        }
    }
    r5 = LD32(r10 + 32);
    r0 = GCALL2(0x0607286C, (r4 * r1), r5);
    r4 = r0 + 6;
    r1 = 131;
    if (r4 > 131) {
        r4 = r1;
    }
    r0 = GCALL3(0x06031448, 7, (r12 + r4), (r11 + 8));
    r0 = GCALL2(0x060689BC, 0, 0x06075A00);
    r9 = r10 + 2;
    r0 = LD16(r9);
    r3 = r10;
    if (r0 == 2) {
        r8 = r10 + 20;
        r4 = LD16(r8);
        r0 = GCALL1(0x0602FBCC, r4);
        r3 = r10;
        if ((r0 & r0) == 0) {
            ST16(r10, 1);
            ST16(r9, -1);
            ST16(r8, -1);
            ST32(r10 + 28, 0);
            ST16((r10 + 6), -1);
            ST16((r10 + 4), -1);
        }
    }
    r3 = r3 + 8;
    r2 = LD16(r3);
    r1 = r2;
    if ((((short)r2) & ((short)r2)) == 0) {
        r0 = LD16(r10);
        r4 = r10;
        if (r0 == 1) {
            ST16(r10, -1);
        }
        r4 = r4 + 2;
        r0 = LD16(r4);
        c13 = r0 == 6;
        if (!(r0 == 5)) {
            r1 = 5;
            if (c13) {
                ST16(r4, r1);
                r1 = 10;
                ST16(r3, r1);
            }
        } else {
            r1 = 6;
            ST16(r4, r1);
            r1 = 10;
            ST16(r3, r1);
        }
    } else {
        r1 = r1 - 1;
        ST16(r3, r1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033168(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, c3;
    FRAME(sp, 40);

    r8 = r4;
    r10 = r5;
    ST32(sp - 32, 0);
    ST32(sp - 28, 0);
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        r11 = sp - 40;
        if (!((r10 & r10) == 0)) {
            r11 = r11 + 4;
            r12 = 0x06036024;
            r0 = GCALL4(0x06036024, r8, r10, (sp - 40), r11);
            r1 = LD32(r10 + 32);
            r0 = r1;
            c3 = r0 == 8;
            if (r0 == 4) {
                r1 = LD32(0x10C8 + r8);
                if ((r1 & r1) == 0) {
                    r3 = LD32((r8 + 68));
                    r1 = LD32((r8 + 64));
                    r4 = LD32(sp - 40);
                    r3 = r3 - r1;
                    r5 = 2;
                    if (r4 > r3) {
                        r9 = r4 - r3;
                        r0 = GCALL3(0x060350C4, r8, (sp - 32), (sp - 28));
                        r5 = LD32(sp - 32);
                        r0 = GCALL2(0x0607286C, r9, r5);
                        r7 = r0;
                        if (!(r7 > 0)) {
                            r5 = 2;
                        } else {
                            r1 = LD32(r10 + 48);
                            r4 = r1 - r7;
                            r5 = 2;
                            if (r4 > 5) {
                                ST32(r10 + 48, r4);
                                r0 = GCALL4(r12, r8, r10, (sp - 40), r11);
                                r5 = 2;
                            }
                        }
                    }
                } else {
                    r0 = LD32(0x10CC + r8);
                    r5 = 2;
                    if (r0 == 3) {
                        r3 = LD32((r8 + 68));
                        r1 = LD32((r8 + 64));
                        r4 = LD32(sp - 40);
                        r3 = r3 - r1;
                        r5 = 2;
                        if (r4 > r3) {
                            r9 = r4 - r3;
                            r0 = GCALL3(0x060350C4, r8, (sp - 32), (sp - 28));
                            r5 = LD32(sp - 32);
                            r0 = GCALL2(0x0607286C, r9, r5);
                            r7 = r0;
                            if (!(r7 > 0)) {
                                r5 = 2;
                            } else {
                                r1 = LD32(r10 + 48);
                                r4 = r1 - r7;
                                r5 = 2;
                                if (r4 > 5) {
                                    ST32(r10 + 48, r4);
                                    r0 = GCALL4(r12, r8, r10, (sp - 40), r11);
                                    r5 = 2;
                                }
                            }
                        }
                    }
                }
            } else {
                r5 = 2;
                if (c3) {
                    r1 = LD32(0x10C8 + r8);
                    if ((r1 & r1) == 0) {
                        r3 = LD32((r8 + 68));
                        r1 = LD32((r8 + 64));
                        r4 = LD32(sp - 40);
                        r3 = r3 - r1;
                        r5 = 2;
                        if (r4 > r3) {
                            r9 = r4 - r3;
                            r0 = GCALL3(0x060350C4, r8, (sp - 32), (sp - 28));
                            r5 = LD32(sp - 32);
                            r0 = GCALL2(0x0607286C, r9, r5);
                            r7 = r0;
                            if (!(r7 > 0)) {
                                r5 = 2;
                            } else {
                                r1 = LD32(r10 + 48);
                                r4 = r1 - r7;
                                r5 = 2;
                                if (r4 > 5) {
                                    ST32(r10 + 48, r4);
                                    r0 = GCALL4(r12, r8, r10, (sp - 40), r11);
                                    r5 = 2;
                                }
                            }
                        }
                    } else {
                        r0 = LD32(0x10CC + r8);
                        r5 = 2;
                        if (r0 == 3) {
                            r3 = LD32((r8 + 68));
                            r1 = LD32((r8 + 64));
                            r4 = LD32(sp - 40);
                            r3 = r3 - r1;
                            r5 = 2;
                            if (r4 > r3) {
                                r9 = r4 - r3;
                                r0 = GCALL3(0x060350C4, r8, (sp - 32), (sp - 28));
                                r5 = LD32(sp - 32);
                                r0 = GCALL2(0x0607286C, r9, r5);
                                r7 = r0;
                                if (!(r7 > 0)) {
                                    r5 = 2;
                                } else {
                                    r1 = LD32(r10 + 48);
                                    r4 = r1 - r7;
                                    r5 = 2;
                                    if (r4 > 5) {
                                        ST32(r10 + 48, r4);
                                        r0 = GCALL4(r12, r8, r10, (sp - 40), r11);
                                        r5 = 2;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            r6 = LD32(sp - 40);
            r0 = GCALL3(0x0601CF94, r8, r5, r6);
            r7 = LD32(r8 + 56);
            r1 = r7 + r7;
            ST16((r1 + r8) + 0xEB0, r0);
            r5 = r8 + (((r1 + r7) << 2) + 0x2B0);
            ST32(r5 + 4, r10);
            ST32(r5 + 8, 0);
            r2 = LD32(sp - 36);
            r3 = LD32(r8 + 32);
            if (r2 > r3) {
                r1 = LD32(r8 + 36);
                ST32(r8 + 36, (r1 - r3));
                r1 = LD32(r8 + 36);
                ST32(r8 + 32, r2);
                ST32(r8 + 36, (r1 + r2));
            }
            r0 = GCALL2(0x0601E884, r8, r5);
            r1 = LD32(r8 + 56);
            r0 = 1;
            ST32(r8 + 56, (r1 + 1));
        } else {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060335FC(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12;
    FRAME(sp, 40);

    r9 = r4;
    r10 = r5;
    if ((r9 & r9) == 0) {
        r0 = 0;
    } else {
        r11 = sp - 40;
        if (!((r10 & r10) == 0)) {
            r11 = r11 + 4;
            r12 = 0x06035820;
            r0 = GCALL4(0x06035820, r9, r10, (sp - 40), r11);
            r1 = LD32(0x10C8 + r9);
            if ((r1 & r1) == 0) {
                r3 = LD32((r9 + 68));
                r1 = LD32((r9 + 64));
                r8 = LD32(sp - 40);
                r3 = r3 - r1;
                r5 = 4;
                if (r8 > r3) {
                    r8 = r8 - r3;
                    r0 = GCALL3(0x060350C4, r9, (sp - 32), (sp - 28));
                    r5 = LD32(sp - 32);
                    r0 = GCALL2(0x0607286C, r8, r5);
                    r6 = r0;
                    r7 = r10;
                    if (!(r6 > 0)) {
                        r5 = 4;
                    } else {
                        r7 = r7 + 44;
                        r3 = LD16(r7);
                        r5 = 4;
                        if ((r3 - r6) > 5) {
                            ST16(r7, (r3 - r6));
                            r0 = GCALL4(r12, r9, r10, (sp - 40), r11);
                            r5 = 4;
                        }
                    }
                }
            } else {
                r0 = LD32(0x10CC + r9);
                r5 = 4;
                if (r0 == 3) {
                    r3 = LD32((r9 + 68));
                    r1 = LD32((r9 + 64));
                    r8 = LD32(sp - 40);
                    r3 = r3 - r1;
                    r5 = 4;
                    if (r8 > r3) {
                        r8 = r8 - r3;
                        r0 = GCALL3(0x060350C4, r9, (sp - 32), (sp - 28));
                        r5 = LD32(sp - 32);
                        r0 = GCALL2(0x0607286C, r8, r5);
                        r6 = r0;
                        r7 = r10;
                        if (!(r6 > 0)) {
                            r5 = 4;
                        } else {
                            r7 = r7 + 44;
                            r3 = LD16(r7);
                            r5 = 4;
                            if ((r3 - r6) > 5) {
                                ST16(r7, (r3 - r6));
                                r0 = GCALL4(r12, r9, r10, (sp - 40), r11);
                                r5 = 4;
                            }
                        }
                    }
                }
            }
            r6 = LD32(sp - 40);
            r0 = GCALL3(0x0601CF94, r9, r5, r6);
            r7 = LD32(r9 + 56);
            r1 = r7 + r7;
            ST16((r1 + r9) + 0xEB0, r0);
            r5 = r9 + (((r1 + r7) << 2) + 0x2B0);
            ST32(r5 + 4, r10);
            ST32(r5 + 8, 0);
            r2 = LD32(sp - 36);
            r3 = LD32(r9 + 32);
            if (r2 > r3) {
                r1 = LD32(r9 + 36);
                ST32(r9 + 36, (r1 - r3));
                r1 = LD32(r9 + 36);
                ST32(r9 + 32, r2);
                ST32(r9 + 36, (r1 + r2));
            }
            r0 = GCALL2(0x0601E884, r9, r5);
            r1 = LD32(r9 + 56);
            r0 = 1;
            ST32(r9 + 56, (r1 + 1));
        } else {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060398B0(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7;

    r6 = r4;
    r3 = 0x1DE0;
    r2 = LD32(r6 + 0x1DE0);
    r1 = LD32(r2);
    r0 = r6;
    if (!(r1 == 1)) {
        r1 = LD32(r6 + 28);
        ST32((r2 + 68), r1);
        r1 = LD32(r0 + r3);
        r2 = LD32(r6 + 32);
    } else {
        r1 = LD32(r2 + 140);
        r3 = LD32(r6);
        r1 = LD32(((r1 << 2) + r6) + 0x9DC);
        r5 = LD32(r6 + 20);
        r0 = GCALL2(0x0607286C, ((r3 * r1) - 1), r5);
        r7 = r0;
        r1 = LD8((r6 + 40));
        r2 = r7 + 1;
        if (!(r1 == 3)) {
            r1 = r7;
            if (!(r1 >= 0)) {
                r1 = r1 + 7;
            }
            r2 = (((r1 >> 1) >> 1) >> 1) + 1;
        }
        r0 = r6;
        r1 = LD32(r0 + 0x1DE0);
        ST32((r1 + 68), r2);
        r1 = LD32(r0 + 0x1DE0);
        r1 = LD32(r1 + 140);
        r3 = LD32(r6 + 4);
        r1 = LD32(((r1 << 2) + r6) + 0xDDC);
        r5 = LD32(r6 + 24);
        r0 = GCALL2(0x0607286C, ((r3 * r1) - 1), r5);
        r7 = r0;
        r1 = LD8((r6 + 40));
        r2 = r7 + 1;
        if (!(r1 == 3)) {
            r1 = r7;
            if (!(r1 >= 0)) {
                r1 = r1 + 7;
            }
            r2 = (((r1 >> 1) >> 1) >> 1) + 1;
        }
        r1 = LD32(0x1DE0 + r6);
    }
    ST32((r1 + 72), r2);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A68C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12;

    r11 = r4;
    r9 = r7;
    r1 = LD32(r9 + 24);
    r12 = r5;
    r2 = LD32(r9 + 20);
    r8 = r6;
    r1 = r1 - r2;
    r2 = LD32(r9 + 8);
    r5 = LD32(r9 + 4);
    r0 = GCALL2(0x0607286C, (r2 - r1), r5);
    r10 = r0;
    r7 = r9;
    if (r12 > r10) {
        r0 = GCALL4(0x0603A68C, r11, r10, r6, r7);
        r0 = GCALL2(0x0603A76C, r11, r9);
        r12 = r12 - r10;
        r8 = r8 + (r10 << 2);
    }
    r12 = r12 - 1;
    r0 = r12;
    if (!(r0 == -1)) {
        do {
            r12 = r12 - 1;
            r0 = r12;
            r2 = LD32(r9 + 24);
            r3 = LD32(r8);
            r8 = r8 + 4;
            ST32(r9 + 24, (r2 + 1));
            ST8(r2, r3);
        } while (AGAIN(!(r0 == -1)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A710(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, c1;

    r9 = r6;
    r11 = r7;
    r6 = LD32(r11 + 32);
    r1 = LD32(r11 + 28);
    r10 = r4;
    r2 = LD32(r11 + 24);
    r8 = r5;
    r4 = LD32(r11 + 12);
    r5 = LD32(r11 + 4);
    r0 = GCALL2(0x0607286C, (r4 - (r1 - r2)), r5);
    r1 = LD32(r6 + 28);
    r5 = r1 - r0;
    c1 = r5 > 0;
    if (r5 > r8) {
        r1 = 0x0603A68C;
        r7 = r11;
        r6 = r9;
        r5 = r8;
        r0 = GCALL4(r1, r10, r5, r6, r7);
    } else {
        r7 = r11;
        if (c1) {
            r1 = 0x0603A68C;
            r6 = r9;
            r0 = GCALL4(r1, r10, r5, r6, r7);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603F180(int r4)
{
    int r0, r5, r6;

    r6 = r4;
    r5 = LD16((r6 + 12));
    r4 = LD32(r6 + 24);
    r0 = GCALL2(0x0607286C, r4, r5);
    r5 = LD32(r6 + 8);
    r0 = GCALL2(0x060745A0, (r0 * 60), r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06036024(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12;
    FRAME(sp, 32);

    r12 = r4;
    r8 = r5;
    r10 = r6;
    r11 = r7;
    ST32(r10, 0);
    ST32(r11, 0);
    r0 = GCALL3(0x060350C4, r4, (sp - 32), (sp - 28));
    r1 = LD32(sp - 28);
    ST16((r8 + 28), r1);
    r1 = LD32(sp - 32);
    ST16((r8 + 30), r1);
    r1 = LD32(r8 + 32);
    r1 = r1 - 1;
    r3 = r0;
    if (!((unsigned)r1 > (unsigned)7)) {
        r1 = LD16(0x06036074 + (r1 + r1));
        r0 = 0x06036074 + r1;
        switch (r1) {
        case 16:
            r1 = 15;
            ST32(r10, 15);
            ST32(r11, r1);
            break;
        case 114:
            break;
        case 22:
            r2 = LD32((r8 + 84));
            r1 = LD32(196 + r2);
            ST32(r10, r1);
            r0 = 200;
            r1 = LD32(200 + r2);
            ST32(r11, r1);
            break;
        case 94:
            r1 = LD32(r8 + 48);
            r2 = LD32(sp - 32);
            ST32(r10, ((r2 * (r1 + 2)) + 4));
            r1 = LD32(sp - 28);
            r1 = r1 + 4;
            ST32(r11, r1);
            break;
        case 40:
            r1 = 14;
            ST32(r10, 14);
            ST32(r11, r1);
            break;
        case 46:
            r8 = LD32(r8 + 52);
            r9 = LD32(r3);
            r0 = GCALL1(0x0607507C, r8);
            ST32((sp - 36), (r0 - 1));
            r0 = GCALL5(0x0601CD5C, r12, r9, r8, 0, LD32((sp - 36)));
            r1 = LD32(sp - 32);
            ST32(r10, (((r1 + r1) + r0) + 8));
            r1 = LD32(sp - 28);
            ST32(r11, (r1 + 8));
            break;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603696C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c8, c18;
    FRAME(sp, 44);

    r12 = r4;
    r10 = r5;
    r8 = 0;
    r14 = LD32(r12 + 8);
    r11 = LD32(r12 + 12);
    r4 = LD32(0x10B4 + r12);
    r13 = LD32(r12 + 32);
    r0 = GCALL4(0x0601CC78, r4, 128, 0, r7);
    r9 = r0;
    r0 = GCALL3(0x060350C4, r12, (sp - 44), (sp - 40));
    r1 = LD32(r10 + 32);
    r1 = r1 - 1;
    r3 = r0;
    if (!((unsigned)r1 > (unsigned)7)) {
        r1 = LD16(0x060369C0 + (r1 + r1));
        switch (r1) {
        case 16:
            r8 = 15;
            r1 = r13;
            if (r13 > 15) {
                r11 = r11 + (((r1 - 15) + ((int)((unsigned)(r1 - 15) >> 31))) >> 1);
            }
            r0 = GCALL1(0x06034CEC, r12);
            r1 = r10;
            if (!((r0 & r0) == 0)) {
                ST16((r1 + 12), r14);
                ST32(r10 + 16, r11);
                ST16((r10 + 14), (r14 + 15));
                ST32(r10 + 20, (r11 + r8));
            }
            r0 = 0x06036138;
            r5 = r10;
            r0 = GCALL2(r0, r12, r5);
            r1 = LD32(0x10C8 + r12);
            r0 = r8;
            if (!((r1 & r1) == 0)) {
                r0 = LD32(0x10CC + r12);
                c18 = r0 == 1;
                r0 = r8;
                if (c18) {
                    r0 = GCALL1(0x0602AC28, r8);
                    r1 = LD32(0x10D0 + r12);
                    ST32(0x10D0 + r12, (r1 + r8));
                    r0 = GCALL1(0x0602AC4C, r8);
                    r0 = r8;
                }
            }
            break;
        case 538:
            r1 = LD32(0x10C8 + r12);
            r0 = r8;
            if (!((r1 & r1) == 0)) {
                r0 = LD32(0x10CC + r12);
                c18 = r0 == 1;
                r0 = r8;
                if (c18) {
                    r0 = GCALL1(0x0602AC28, r8);
                    r1 = LD32(0x10D0 + r12);
                    ST32(0x10D0 + r12, (r1 + r8));
                    r0 = GCALL1(0x0602AC4C, r8);
                    r0 = r8;
                }
            }
            break;
        case 158:
            r1 = LD32((r10 + 84));
            r0 = LD32(196 + r1);
            ST32(sp - 36, r0);
            r8 = LD32(200 + r1);
            r0 = GCALL1(0x06034CEC, r12);
            if (!((r0 & r0) == 0)) {
                r1 = LD32(r10 + 40);
                r1 = r1 - 4;
                c8 = (unsigned)r1 > (unsigned)5;
                r1 = r1 + r1;
                if (c8) {
                    r1 = r13;
                    r1 = r1 - r8;
                    r11 = r11 + r1;
                } else {
                    r1 = LD16(0x06036A90 + r1);
                    switch (r1) {
                    case 100:
                        r1 = r13;
                        r1 = r1 - r8;
                        r11 = r11 + r1;
                        break;
                    case 12:
                        r1 = r13 - ((((int)((unsigned)r8 >> 31)) + r8) >> 1);
                        r11 = r11 + r1;
                        break;
                    case 106:
                        break;
                    case 28:
                        r1 = LD32(r9 + 32);
                        r1 = r13 - r1;
                        r11 = r11 + r1;
                        break;
                    case 64:
                        r1 = LD32(r9 + 32);
                        r11 = r11 + ((r13 - ((r1 + ((int)((unsigned)r1 >> 31))) >> 1)) - ((((int)((unsigned)r8 >> 31)) + r8) >> 1));
                        break;
                    case 96:
                        r1 = LD32(r12 + 36);
                        r1 = r1 - r8;
                        r11 = r11 + r1;
                        break;
                    }
                }
                ST16((r10 + 12), r14);
                ST32(r10 + 16, r11);
                r1 = LD32(sp - 36);
                ST16((r10 + 14), (r1 + r14));
                ST32(r10 + 20, (r11 + r8));
            }
            r0 = GCALL2(0x060368C4, r12, r10);
            r8 = r0;
            r1 = LD32(0x10C8 + r12);
            r0 = r8;
            if (!((r1 & r1) == 0)) {
                r0 = LD32(0x10CC + r12);
                c18 = r0 == 1;
                r0 = r8;
                if (c18) {
                    r0 = GCALL1(0x0602AC28, r8);
                    r1 = LD32(0x10D0 + r12);
                    ST32(0x10D0 + r12, (r1 + r8));
                    r0 = GCALL1(0x0602AC4C, r8);
                    r0 = r8;
                }
            }
            break;
        case 464:
            r1 = LD32(r10 + 48);
            r2 = LD32(sp - 44);
            r8 = r2 * (r1 + 2);
            r2 = LD32(sp - 40);
            r11 = r11 + ((r13 - 2) - r2);
            r0 = GCALL1(0x06034CEC, r12);
            r1 = r10;
            if (!((r0 & r0) == 0)) {
                ST16((r1 + 12), r14);
                ST32(r10 + 16, r11);
                ST16((r10 + 14), (r14 + r8));
                r1 = LD32(sp - 40);
                ST32(r10 + 20, ((r1 + r11) + 2));
            }
            r0 = GCALL2(0x060366D8, r12, r10);
            r8 = r8 + 4;
            if (!((r0 & r0) == 0)) {
                r1 = LD32(0x10C8 + r12);
                r0 = r8;
                if (!((r1 & r1) == 0)) {
                    r0 = LD32(0x10CC + r12);
                    c18 = r0 == 1;
                    r0 = r8;
                    if (c18) {
                        r0 = GCALL1(0x0602AC28, r8);
                        r1 = LD32(0x10D0 + r12);
                        ST32(0x10D0 + r12, (r1 + r8));
                        r0 = GCALL1(0x0602AC4C, r8);
                        r0 = r8;
                    }
                }
            } else {
                r0 = -1;
            }
            break;
        case 78:
            r8 = 14;
            r6 = sp - 44;
            if (r13 > 14) {
                r11 = r11 + (((r13 - 14) + ((int)((unsigned)(r13 - 14) >> 31))) >> 1);
            }
            r0 = GCALL3(0x060350C4, r12, (sp - 44), (r6 + 4));
            r0 = GCALL1(0x06034CEC, r12);
            r1 = r10;
            if (!((r0 & r0) == 0)) {
                ST16((r1 + 12), r14);
                ST32(r10 + 16, r11);
                ST16((r10 + 14), (r14 + 14));
                ST32(r10 + 20, (r11 + r8));
            }
            r0 = 0x06036310;
            r5 = r10;
            r0 = GCALL2(r0, r12, r5);
            r1 = LD32(0x10C8 + r12);
            r0 = r8;
            if (!((r1 & r1) == 0)) {
                r0 = LD32(0x10CC + r12);
                c18 = r0 == 1;
                r0 = r8;
                if (c18) {
                    r0 = GCALL1(0x0602AC28, r8);
                    r1 = LD32(0x10D0 + r12);
                    ST32(0x10D0 + r12, (r1 + r8));
                    r0 = GCALL1(0x0602AC4C, r8);
                    r0 = r8;
                }
            }
            break;
        case 350:
            r8 = LD32(r10 + 52);
            r9 = LD32(r3);
            r0 = GCALL1(0x0607507C, r8);
            ST32((sp - 48), (r0 - 1));
            r0 = GCALL5(0x0601CD5C, r12, r9, r8, 0, LD32((sp - 48)));
            r9 = r0;
            r1 = LD32(sp - 44);
            r2 = LD32(sp - 40);
            r8 = (r1 + r1) + r9;
            r11 = r11 + ((r13 - 8) - r2);
            r0 = GCALL5(0x06034CEC, r12, 0, 0, 0, LD32((sp - 48)));
            if (!((r0 & r0) == 0)) {
                ST16((r10 + 12), r14);
                ST32(r10 + 16, (r11 - 2));
                ST16((r10 + 14), (r14 + r8));
                r1 = LD32(sp - 40);
                ST32(r10 + 20, ((r1 + r11) + 8));
            }
            r0 = GCALL2(0x06036454, r12, r10);
            r1 = LD32(sp - 44);
            if ((r0 & r0) == 0) {
                r0 = -1;
            } else {
                r8 = ((r1 + r1) + r9) + 8;
                r1 = LD32(0x10C8 + r12);
                r0 = r8;
                if (!((r1 & r1) == 0)) {
                    r0 = LD32(0x10CC + r12);
                    c18 = r0 == 1;
                    r0 = r8;
                    if (c18) {
                        r0 = GCALL1(0x0602AC28, r8);
                        r1 = LD32(0x10D0 + r12);
                        ST32(0x10D0 + r12, (r1 + r8));
                        r0 = GCALL1(0x0602AC4C, r8);
                        r0 = r8;
                    }
                }
            }
            break;
        }
    } else {
        r1 = LD32(0x10C8 + r12);
        r0 = r8;
        if (!((r1 & r1) == 0)) {
            r0 = LD32(0x10CC + r12);
            c18 = r0 == 1;
            r0 = r8;
            if (c18) {
                r0 = GCALL1(0x0602AC28, r8);
                r1 = LD32(0x10D0 + r12);
                ST32(0x10D0 + r12, (r1 + r8));
                r0 = GCALL1(0x0602AC4C, r8);
                r0 = r8;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037108(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r10, r11, c2, c4;
    FRAME(sp, 32);

    r10 = r6;
    r3 = LD32(sp);
    ST32(r10 + 24, 1);
    r1 = LD32(r10 + 32);
    r1 = r1 - 1;
    r11 = r4;
    if (!((unsigned)r1 > (unsigned)7)) {
        r1 = LD16(0x06037138 + (r1 + r1));
        switch (r1) {
        case 16:
            r0 = 0x06036C40;
            r5 = r10;
            r0 = GCALL4(r0, r11, r5, r6, r7);
            break;
        case 288:
            r0 = 1;
            break;
        case 52:
            ST32((sp - 24), r3);
            r0 = GCALL5(0x06036D78, r11, r5, r10, r7, LD32((sp - 24)));
            break;
        case 66:
            c2 = r3 >= 0;
            if (!(r7 >= 0)) {
                ST32(0x0607668C, 2);
                r6 = LD32((r10 + 72));
                ST32((sp - 24), 0);
                ST32((sp - 28), 0);
                ST32((sp - 32), 0);
                r0 = GCALL7(0x060384AC, r11, r5, r6, 0, LD32((sp - 32)), LD32((sp - 28)), LD32((sp - 24)));
                ST32(0x0607668C, 0);
                if (!((r0 & r0) == 0)) {
                    r1 = LD32(r10 + 52);
                    c4 = (r1 & r1) == 0;
                    r1 = r10;
                    if (!(c4)) {
                        r6 = r10 + 12;
                        r3 = LD32((r1 + 88));
                        r1 = LD16(r6);
                        r7 = r3 + 2;
                        ST16(r3, (r1 >> 1));
                        r1 = LD32(r10 + 16);
                        ST16(r7, (r1 >> 1));
                        r1 = LD16(r3);
                        ST16((r3 + 8), r1);
                        r1 = LD16(r7);
                        ST16((r3 + 10), r1);
                        r1 = LD16(r6);
                        ST16((r3 + 16), r1);
                        r1 = LD32(r10 + 16);
                        ST16((r3 + 18), r1);
                        r1 = LD16((r10 + 14));
                        r2 = LD16(r6);
                        ST16((r3 + 4), ((r1 - r2) >> 1));
                        r1 = LD32(r10 + 20);
                        r2 = LD32(r10 + 16);
                        ST16((r3 + 6), ((r1 - r2) >> 1));
                        r1 = LD32(r10 + 52);
                        ST32(r3 + 20, r1);
                        ST8((r3 + 28), 0);
                        ST16((r3 + 32), 0);
                        ST32(r3 + 12, 1);
                        ST32(r3 + 36, 0x06036E68);
                        ST32(r3 + 40, 0);
                        ST32(r3 + 44, 0);
                        ST32(0x06088028, r10);
                        ST32(0x06078024, r3);
                        r5 = LD32(r10 + 16);
                        r0 = GCALL2(0x060106BC, r11, r5);
                        r0 = 1;
                    } else {
                        ST32(r10 + 56, 20);
                        r0 = GCALL1(0x060287D0, 20);
                        ST32(r10 + 52, r0);
                        if (!((r0 & r0) == 0)) {
                            ST8(r0, 0);
                            r1 = r10;
                            r6 = r10 + 12;
                            r3 = LD32((r1 + 88));
                            r1 = LD16(r6);
                            r7 = r3 + 2;
                            ST16(r3, (r1 >> 1));
                            r1 = LD32(r10 + 16);
                            ST16(r7, (r1 >> 1));
                            r1 = LD16(r3);
                            ST16((r3 + 8), r1);
                            r1 = LD16(r7);
                            ST16((r3 + 10), r1);
                            r1 = LD16(r6);
                            ST16((r3 + 16), r1);
                            r1 = LD32(r10 + 16);
                            ST16((r3 + 18), r1);
                            r1 = LD16((r10 + 14));
                            r2 = LD16(r6);
                            ST16((r3 + 4), ((r1 - r2) >> 1));
                            r1 = LD32(r10 + 20);
                            r2 = LD32(r10 + 16);
                            ST16((r3 + 6), ((r1 - r2) >> 1));
                            r1 = LD32(r10 + 52);
                            ST32(r3 + 20, r1);
                            ST8((r3 + 28), 0);
                            ST16((r3 + 32), 0);
                            ST32(r3 + 12, 1);
                            ST32(r3 + 36, 0x06036E68);
                            ST32(r3 + 40, 0);
                            ST32(r3 + 44, 0);
                            ST32(0x06088028, r10);
                            ST32(0x06078024, r3);
                            r5 = LD32(r10 + 16);
                            r0 = GCALL2(0x060106BC, r11, r5);
                            r0 = 1;
                        } else {
                            ST32(r10 + 56, 0);
                            r0 = 0;
                        }
                    }
                } else {
                    r0 = 0;
                }
            } else {
                if (c2) {
                    r1 = LD32(r10 + 52);
                    c4 = (r1 & r1) == 0;
                    r1 = r10;
                    if (!(c4)) {
                        r6 = r10 + 12;
                        r3 = LD32((r1 + 88));
                        r1 = LD16(r6);
                        r7 = r3 + 2;
                        ST16(r3, (r1 >> 1));
                        r1 = LD32(r10 + 16);
                        ST16(r7, (r1 >> 1));
                        r1 = LD16(r3);
                        ST16((r3 + 8), r1);
                        r1 = LD16(r7);
                        ST16((r3 + 10), r1);
                        r1 = LD16(r6);
                        ST16((r3 + 16), r1);
                        r1 = LD32(r10 + 16);
                        ST16((r3 + 18), r1);
                        r1 = LD16((r10 + 14));
                        r2 = LD16(r6);
                        ST16((r3 + 4), ((r1 - r2) >> 1));
                        r1 = LD32(r10 + 20);
                        r2 = LD32(r10 + 16);
                        ST16((r3 + 6), ((r1 - r2) >> 1));
                        r1 = LD32(r10 + 52);
                        ST32(r3 + 20, r1);
                        ST8((r3 + 28), 0);
                        ST16((r3 + 32), 0);
                        ST32(r3 + 12, 1);
                        ST32(r3 + 36, 0x06036E68);
                        ST32(r3 + 40, 0);
                        ST32(r3 + 44, 0);
                        ST32(0x06088028, r10);
                        ST32(0x06078024, r3);
                        r5 = LD32(r10 + 16);
                        r0 = GCALL2(0x060106BC, r11, r5);
                        r0 = 1;
                    } else {
                        ST32(r10 + 56, 20);
                        r0 = GCALL1(0x060287D0, 20);
                        ST32(r10 + 52, r0);
                        if (!((r0 & r0) == 0)) {
                            ST8(r0, 0);
                            r1 = r10;
                            r6 = r10 + 12;
                            r3 = LD32((r1 + 88));
                            r1 = LD16(r6);
                            r7 = r3 + 2;
                            ST16(r3, (r1 >> 1));
                            r1 = LD32(r10 + 16);
                            ST16(r7, (r1 >> 1));
                            r1 = LD16(r3);
                            ST16((r3 + 8), r1);
                            r1 = LD16(r7);
                            ST16((r3 + 10), r1);
                            r1 = LD16(r6);
                            ST16((r3 + 16), r1);
                            r1 = LD32(r10 + 16);
                            ST16((r3 + 18), r1);
                            r1 = LD16((r10 + 14));
                            r2 = LD16(r6);
                            ST16((r3 + 4), ((r1 - r2) >> 1));
                            r1 = LD32(r10 + 20);
                            r2 = LD32(r10 + 16);
                            ST16((r3 + 6), ((r1 - r2) >> 1));
                            r1 = LD32(r10 + 52);
                            ST32(r3 + 20, r1);
                            ST8((r3 + 28), 0);
                            ST16((r3 + 32), 0);
                            ST32(r3 + 12, 1);
                            ST32(r3 + 36, 0x06036E68);
                            ST32(r3 + 40, 0);
                            ST32(r3 + 44, 0);
                            ST32(0x06088028, r10);
                            ST32(0x06078024, r3);
                            r5 = LD32(r10 + 16);
                            r0 = GCALL2(0x060106BC, r11, r5);
                            r0 = 1;
                        } else {
                            ST32(r10 + 56, 0);
                            r0 = 0;
                        }
                    }
                } else {
                    ST32(0x0607668C, 2);
                    r6 = LD32((r10 + 72));
                    ST32((sp - 24), 0);
                    ST32((sp - 28), 0);
                    ST32((sp - 32), 0);
                    r0 = GCALL7(0x060384AC, r11, r5, r6, 0, LD32((sp - 32)), LD32((sp - 28)), LD32((sp - 24)));
                    ST32(0x0607668C, 0);
                    if (!((r0 & r0) == 0)) {
                        r1 = LD32(r10 + 52);
                        c4 = (r1 & r1) == 0;
                        r1 = r10;
                        if (!(c4)) {
                            r6 = r10 + 12;
                            r3 = LD32((r1 + 88));
                            r1 = LD16(r6);
                            r7 = r3 + 2;
                            ST16(r3, (r1 >> 1));
                            r1 = LD32(r10 + 16);
                            ST16(r7, (r1 >> 1));
                            r1 = LD16(r3);
                            ST16((r3 + 8), r1);
                            r1 = LD16(r7);
                            ST16((r3 + 10), r1);
                            r1 = LD16(r6);
                            ST16((r3 + 16), r1);
                            r1 = LD32(r10 + 16);
                            ST16((r3 + 18), r1);
                            r1 = LD16((r10 + 14));
                            r2 = LD16(r6);
                            ST16((r3 + 4), ((r1 - r2) >> 1));
                            r1 = LD32(r10 + 20);
                            r2 = LD32(r10 + 16);
                            ST16((r3 + 6), ((r1 - r2) >> 1));
                            r1 = LD32(r10 + 52);
                            ST32(r3 + 20, r1);
                            ST8((r3 + 28), 0);
                            ST16((r3 + 32), 0);
                            ST32(r3 + 12, 1);
                            ST32(r3 + 36, 0x06036E68);
                            ST32(r3 + 40, 0);
                            ST32(r3 + 44, 0);
                            ST32(0x06088028, r10);
                            ST32(0x06078024, r3);
                            r5 = LD32(r10 + 16);
                            r0 = GCALL2(0x060106BC, r11, r5);
                            r0 = 1;
                        } else {
                            ST32(r10 + 56, 20);
                            r0 = GCALL1(0x060287D0, 20);
                            ST32(r10 + 52, r0);
                            if (!((r0 & r0) == 0)) {
                                ST8(r0, 0);
                                r1 = r10;
                                r6 = r10 + 12;
                                r3 = LD32((r1 + 88));
                                r1 = LD16(r6);
                                r7 = r3 + 2;
                                ST16(r3, (r1 >> 1));
                                r1 = LD32(r10 + 16);
                                ST16(r7, (r1 >> 1));
                                r1 = LD16(r3);
                                ST16((r3 + 8), r1);
                                r1 = LD16(r7);
                                ST16((r3 + 10), r1);
                                r1 = LD16(r6);
                                ST16((r3 + 16), r1);
                                r1 = LD32(r10 + 16);
                                ST16((r3 + 18), r1);
                                r1 = LD16((r10 + 14));
                                r2 = LD16(r6);
                                ST16((r3 + 4), ((r1 - r2) >> 1));
                                r1 = LD32(r10 + 20);
                                r2 = LD32(r10 + 16);
                                ST16((r3 + 6), ((r1 - r2) >> 1));
                                r1 = LD32(r10 + 52);
                                ST32(r3 + 20, r1);
                                ST8((r3 + 28), 0);
                                ST16((r3 + 32), 0);
                                ST32(r3 + 12, 1);
                                ST32(r3 + 36, 0x06036E68);
                                ST32(r3 + 40, 0);
                                ST32(r3 + 44, 0);
                                ST32(0x06088028, r10);
                                ST32(0x06078024, r3);
                                r5 = LD32(r10 + 16);
                                r0 = GCALL2(0x060106BC, r11, r5);
                                r0 = 1;
                            } else {
                                ST32(r10 + 56, 0);
                                r0 = 0;
                            }
                        }
                    } else {
                        r0 = 0;
                    }
                }
            }
            break;
        case 40:
            r0 = 0x06036D34;
            r5 = r10;
            r0 = GCALL4(r0, r11, r5, r6, r7);
            break;
        case 22:
            r0 = 0x06036C60;
            r5 = r10;
            r0 = GCALL4(r0, r11, r5, r6, r7);
            break;
        case 28:
            r0 = GCALL4(0x06036CB0, r11, r5, r10, r7);
            break;
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037C9C(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, c0, c4;

    r10 = r5;
    ST32(r10 + 24, 1);
    r1 = LD32(r10 + 32);
    r1 = r1 - 1;
    c0 = (unsigned)r1 > (unsigned)7;
    r1 = r1 + r1;
    if (c0) {
        r0 = 1;
    } else {
        r1 = LD16(0x06037CC0 + r1);
        switch (r1) {
        case 16:
            r1 = LD32((r10 + 68));
            r2 = r10;
            if ((r1 & r1) == 0) {
                ST32((r2 + 64), 0);
            } else {
                ST32((r2 + 64), 1);
            }
            r0 = 1;
            break;
        case 224:
            r0 = 1;
            break;
        case 44:
            r4 = LD32(r10 + 60);
            if ((r4 & r4) == 0) {
                r2 = LD32(r10 + 52);
                r1 = 0;
                if (!((r2 & r2) == 0)) {
                    ST8(r2, r1);
                    r9 = r10;
                    r9 = r9 + 88;
                    r2 = LD32(r9);
                    r1 = LD32(r10 + 52);
                    ST32(r2 + 20, r1);
                    r8 = LD32(r9);
                    r4 = LD32(r10 + 52);
                    r0 = GCALL1(0x0607507C, r4);
                    ST16((r8 + 24), r0);
                    r1 = LD32(r9);
                    ST16((r1 + 26), 0);
                    r0 = 1;
                } else {
                    ST32(r10 + 56, 20);
                    r0 = GCALL1(0x060287D0, 20);
                    ST32(r10 + 52, r0);
                    if (!((r0 & r0) == 0)) {
                        ST8(r0, 0);
                        r9 = r10;
                        r9 = r9 + 88;
                        r2 = LD32(r9);
                        r1 = LD32(r10 + 52);
                        ST32(r2 + 20, r1);
                        r8 = LD32(r9);
                        r4 = LD32(r10 + 52);
                        r0 = GCALL1(0x0607507C, r4);
                        ST16((r8 + 24), r0);
                        r1 = LD32(r9);
                        ST16((r1 + 26), 0);
                        r0 = 1;
                    } else {
                        ST32(r10 + 56, 0);
                        r0 = 0;
                    }
                }
            } else {
                r1 = LD32(r10 + 52);
                if ((r1 & r1) == 0) {
                    ST32(r10 + 56, 20);
                    r0 = GCALL1(0x060287D0, 20);
                    ST32(r10 + 52, r0);
                    if ((r0 & r0) == 0) {
                        ST32(r10 + 56, 0);
                        r0 = 0;
                    } else {
                        ST8(r0, 0);
                        r5 = LD32(r10 + 60);
                        r4 = LD32(r10 + 52);
                        r0 = GCALL2(0x060750DC, r4, r5);
                        r9 = r10;
                        r9 = r9 + 88;
                        r2 = LD32(r9);
                        r1 = LD32(r10 + 52);
                        ST32(r2 + 20, r1);
                        r8 = LD32(r9);
                        r4 = LD32(r10 + 52);
                        r0 = GCALL1(0x0607507C, r4);
                        ST16((r8 + 24), r0);
                        r1 = LD32(r9);
                        ST16((r1 + 26), 0);
                        r0 = 1;
                    }
                } else {
                    r8 = 0x0607507C;
                    r0 = GCALL1(0x0607507C, r4);
                    r1 = LD32(r10 + 56);
                    c4 = (unsigned)r1 >= (unsigned)(r0 + 1);
                    r1 = 0;
                    if (c4) {
                        r2 = LD32(r10 + 52);
                        ST8(r2, r1);
                        r5 = LD32(r10 + 60);
                        r4 = LD32(r10 + 52);
                        r0 = GCALL2(0x060750DC, r4, r5);
                        r9 = r10;
                        r9 = r9 + 88;
                        r2 = LD32(r9);
                        r1 = LD32(r10 + 52);
                        ST32(r2 + 20, r1);
                        r8 = LD32(r9);
                        r4 = LD32(r10 + 52);
                        r0 = GCALL1(0x0607507C, r4);
                        ST16((r8 + 24), r0);
                        r1 = LD32(r9);
                        ST16((r1 + 26), 0);
                        r0 = 1;
                    } else {
                        r4 = LD32(r10 + 60);
                        r0 = GCALL2(r8, r4, r5);
                        r5 = LD32(r10 + 52);
                        r0 = GCALL3(0x06027C18, 0, r5, (r0 + 1));
                        if (!((r0 & r0) == 0)) {
                            r4 = LD32(r10 + 60);
                            ST32(r10 + 52, r0);
                            r0 = GCALL1(r8, r4);
                            ST32(r10 + 56, (r0 + 1));
                            r2 = LD32(r10 + 52);
                            ST8(r2, 0);
                            r5 = LD32(r10 + 60);
                            r4 = LD32(r10 + 52);
                            r0 = GCALL2(0x060750DC, r4, r5);
                            r9 = r10;
                            r9 = r9 + 88;
                            r2 = LD32(r9);
                            r1 = LD32(r10 + 52);
                            ST32(r2 + 20, r1);
                            r8 = LD32(r9);
                            r4 = LD32(r10 + 52);
                            r0 = GCALL1(0x0607507C, r4);
                            ST16((r8 + 24), r0);
                            r1 = LD32(r9);
                            ST16((r1 + 26), 0);
                            r0 = 1;
                        } else {
                            r0 = 0;
                        }
                    }
                }
            }
            break;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A208(int r4, int r5)
{
    int r1, r2, r3, r6, r7, c0, c2, c3, c4;

    r1 = LD8(r4);
    r2 = 255;
    c0 = (r1 & 255) == 255;
    r1 = c0;
    if (c0) {
        r6 = r2;
        if (!(r5 > r1)) {
            return -313;
        } else {
            r7 = 217;
            r3 = 37;
            while (1) {
                r1 = LD8(r4);
                c2 = (r1 & 255) == r6;
                r1 = r4;
                if (!(c2)) {
                    r5 = r5 - 1;
                    r4 = r4 + 1;
                    if (r5 > 1) {
                        POLL();
                        continue;
                    } else {
                        return -313;
                    }
                } else {
                    r1 = LD8((r1 + 1));
                    r1 = (r1 & 255) - r7;
                    c3 = (unsigned)r1 > (unsigned)r3;
                    r1 = r1 + r1;
                    if (c3) {
                        r5 = r5 - 1;
                        r4 = r4 + 1;
                        if (r5 > 1) {
                            POLL();
                            continue;
                        } else {
                            return -313;
                        }
                    } else {
                        r1 = LD16(0x0603A248 + r1);
                        switch (r1) {
                        case 90:
                            return -305;
                        case 76:
                            c4 = r5 > 16;
                            r5 = r5 - 1;
                            if (!(c4)) {
                                r4 = r4 + 1;
                                if (r5 > 1) {
                                    POLL();
                                    continue;
                                } else {
                                    return -313;
                                }
                            } else {
                                return -304;
                            }
                            break;
                        case 120:
                            r5 = r5 - 1;
                            r4 = r4 + 1;
                            if (r5 > 1) {
                                POLL();
                                continue;
                            } else {
                                return -313;
                            }
                            break;
                        case 96:
                            r2 = LD8((r4 + 2));
                            r1 = LD8((r4 + 3));
                            r2 = ((r2 & 255) << 8) | (r1 & 255);
                            r5 = r5 - r2;
                            r4 = r4 + r2;
                            r5 = r5 - 1;
                            r4 = r4 + 1;
                            if (r5 > 1) {
                                POLL();
                                continue;
                            } else {
                                return -313;
                            }
                            break;
                        }
                    }
                }
                POLL();
            }
        }
    } else {
        return -300;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060334B4(int r4)
{
    int r0, r1, r2, r8, r9, r10, c1010;

    r9 = r4;
    r10 = 0;
    r0 = GCALL0(0x06034000);
    r8 = r0;
    r1 = r8;
    if (!((r8 & r8) == 0)) {
        r1 = LD32((r1 + 68));
        ST32(r9, r1);
        r0 = GCALL2(0x06033378, r9, r8);
        r1 = LD32(0x06078128);
        r0 = 1;
        if ((r1 & r1) == 0) {
            r0 = LD16((r8 + 64));
            if (!(r0 == 1)) {
                r0 = 1;
            } else {
                r1 = LD32(r8 + 56);
                if (!((r1 & r1) == 0)) {
                    r0 = 1;
                } else {
                    r2 = LD32(r8 + 44);
                    c1010 = (r10 & r10) == 0;
                    if (!((r2 & r2) == 0)) {
                        while (1) {
                            r1 = LD32(r2 + 4);
                            if (!((r1 & r1) == 0)) {
                                POLL();
                                r10 = 1;
                                ST32(r8 + 52, r2);
                                break;
                            } else {
                                r2 = LD32(r2 + 24);
                                if (!((r2 & r2) == 0)) {
                                    POLL();
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            POLL();
                        }
                        c1010 = (r10 & r10) == 0;
                    }
                    r0 = 1;
                    if (c1010) {
                        r2 = LD32(r8 + 44);
                        r1 = 1;
                        if (!((r2 & r2) == 0)) {
                            ST32(r2 + 4, r1);
                            ST32(r2, r1);
                            ST32(r8 + 52, r2);
                            r0 = 1;
                        }
                    }
                }
            }
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06033A1C(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, c8, c10, c14, c1007, c1020, c1023;

    r1 = LD32(0x06088028);
    r11 = r4;
    if (!((r1 & r1) == 0)) {
        if ((r5 & r5) == 0) {
            r8 = LD32(r1 + 8);
            c1007 = (r8 & r8) == 0;
        } else {
            r8 = LD32(r1 + 4);
            c1007 = (r8 & r8) == 0;
        }
        r10 = 1;
        if (c1007) {
            r0 = 0;
        } else {
            r9 = 0;
            while (1) {
                r0 = LD32(r8);
                c8 = r0 == 2;
                if (!((r0 & r0) == 0)) {
                    if (!(c8)) {
                        c1020 = (r5 & r5) == 0;
                        if (c1020) {
                            r8 = LD32(r8 + 8);
                            c1023 = (r8 & r8) == 0;
                        } else {
                            r8 = LD32(r8 + 4);
                            c1023 = (r8 & r8) == 0;
                        }
                        if (!(c1023)) {
                            POLL();
                            continue;
                        } else {
                            r0 = 0;
                            break;
                        }
                    } else {
                        POLL();
                        ST32(r8 + 24, 1);
                        r6 = r8 + 12;
                        r7 = LD16(r6);
                        r7 = r7 >> 1;
                        ST16(0x06087FF8, r7);
                        r2 = LD32(r8 + 16);
                        r2 = r2 >> 1;
                        ST16(0x06087FFA, r2);
                        ST16(0x06088000, r7);
                        ST16(0x06088002, r2);
                        r1 = LD16((r8 + 14));
                        r2 = LD16(r6);
                        ST16(0x06087FFC, ((r1 - r2) >> 1));
                        r1 = LD32(r8 + 20);
                        r2 = LD32(r8 + 16);
                        ST16(0x06087FFE, ((r1 - r2) >> 1));
                        ST32(0x0608800C, 0x06087FB0);
                        ST8(0x06087FB0, 0);
                        ST16(0x06088010, 0);
                        ST16(0x06088012, 0);
                        ST8(0x06088014, 0);
                        ST16(0x06088018, 0);
                        ST32(0x06088004, 1);
                        ST32(0x0608801C, 0x0603739C);
                        ST32(0x06088020, 0);
                        ST32(0x06088024, 0);
                        ST32(0x06088028, r8);
                        ST32(0x06078024, 0x06087FF8);
                        r4 = LD32(r8 + 40);
                        r7 = LD16(r6);
                        ST16(0x06088008, r7);
                        r6 = LD32(r8 + 16);
                        ST16(0x0608800A, r6);
                        r1 = LD32(r4 + 28);
                        r2 = LD16((r8 + 30));
                        ST16(0x06088008, (r7 + ((r1 + 1) * r2)));
                        r7 = r8 + 28;
                        r2 = LD16(r7);
                        r1 = LD32(r4 + 24);
                        ST16(0x0608800A, (r6 + (r1 * r2)));
                        r1 = LD32(r8 + 40);
                        r1 = LD32(r1 + 24);
                        r2 = LD16(r7);
                        r4 = r11;
                        r5 = LD32(r8 + 16);
                        r5 = r5 + ((r1 + 1) * r2);
                        r0 = GCALL2(0x060106BC, r4, r5);
                        r0 = 1;
                        break;
                    }
                } else {
                    r0 = LD32(r8 + 32);
                    c10 = r0 == 4;
                    if (r0 == 8) {
                        r1 = LD32(r8 + 52);
                        ST32(r8 + 24, r10);
                        if (!((r1 & r1) == 0)) {
                            r3 = LD32((r8 + 88));
                            r5 = r8 + 12;
                            r7 = r3 + 2;
                            r1 = LD16(r5);
                            ST16(r3, (r1 >> 1));
                            r1 = LD32(r8 + 16);
                            ST16(r7, (r1 >> 1));
                            r1 = LD16(r3);
                            r6 = r3 + 16;
                            ST16((r3 + 8), r1);
                            r1 = LD16(r7);
                            ST16((r3 + 10), r1);
                            r1 = LD16(r5);
                            ST16(r6, r1);
                            r1 = LD32(r8 + 16);
                            r4 = r3 + 18;
                            ST16(r4, r1);
                            r1 = LD16((r8 + 14));
                            r2 = LD16(r5);
                            ST16((r3 + 4), ((r1 - r2) >> 1));
                            r1 = LD32(r8 + 20);
                            r2 = LD32(r8 + 16);
                            ST16((r3 + 6), ((r1 - r2) >> 1));
                            r1 = LD32(r8 + 52);
                            ST32(r3 + 20, r1);
                            ST8((r3 + 28), 0);
                            ST16((r3 + 32), r9);
                            ST32(r3 + 12, r10);
                            ST32(r3 + 40, r9);
                            ST32(r3 + 44, r9);
                            ST32(0x06088028, r8);
                            ST32(0x06078024, r3);
                            r1 = LD16(r5);
                            ST16(r6, r1);
                            r1 = LD32(r8 + 16);
                            ST16(r4, r1);
                            r2 = LD16((r3 + 24));
                            r1 = LD16((r8 + 30));
                            c14 = (r2 + 1) * r1;
                            r4 = r11;
                            r1 = LD16(r6);
                            ST16(r6, (r1 + c14));
                            r5 = LD32(r8 + 16);
                            r0 = GCALL2(0x060106BC, r4, r5);
                            r0 = 1;
                            break;
                        } else {
                            ST32(r8 + 56, 20);
                            r0 = GCALL1(0x060287D0, 20);
                            ST32(r8 + 52, r0);
                            if ((r0 & r0) == 0) {
                                POLL();
                                ST32(r8 + 56, 0);
                                r0 = 0;
                                break;
                            } else {
                                ST8(r0, 0);
                                r3 = LD32((r8 + 88));
                                r5 = r8 + 12;
                                r7 = r3 + 2;
                                r1 = LD16(r5);
                                ST16(r3, (r1 >> 1));
                                r1 = LD32(r8 + 16);
                                ST16(r7, (r1 >> 1));
                                r1 = LD16(r3);
                                r6 = r3 + 16;
                                ST16((r3 + 8), r1);
                                r1 = LD16(r7);
                                ST16((r3 + 10), r1);
                                r1 = LD16(r5);
                                ST16(r6, r1);
                                r1 = LD32(r8 + 16);
                                r4 = r3 + 18;
                                ST16(r4, r1);
                                r1 = LD16((r8 + 14));
                                r2 = LD16(r5);
                                ST16((r3 + 4), ((r1 - r2) >> 1));
                                r1 = LD32(r8 + 20);
                                r2 = LD32(r8 + 16);
                                ST16((r3 + 6), ((r1 - r2) >> 1));
                                r1 = LD32(r8 + 52);
                                ST32(r3 + 20, r1);
                                ST8((r3 + 28), 0);
                                ST16((r3 + 32), r9);
                                ST32(r3 + 12, r10);
                                ST32(r3 + 40, r9);
                                ST32(r3 + 44, r9);
                                ST32(0x06088028, r8);
                                ST32(0x06078024, r3);
                                r1 = LD16(r5);
                                ST16(r6, r1);
                                r1 = LD32(r8 + 16);
                                ST16(r4, r1);
                                r2 = LD16((r3 + 24));
                                r1 = LD16((r8 + 30));
                                c14 = (r2 + 1) * r1;
                                r4 = r11;
                                r1 = LD16(r6);
                                ST16(r6, (r1 + c14));
                                r5 = LD32(r8 + 16);
                                r0 = GCALL2(0x060106BC, r4, r5);
                                r0 = 1;
                                break;
                            }
                        }
                    } else {
                        c1020 = (r5 & r5) == 0;
                        if (!(c10)) {
                            if (c1020) {
                                r8 = LD32(r8 + 8);
                                c1023 = (r8 & r8) == 0;
                            } else {
                                r8 = LD32(r8 + 4);
                                c1023 = (r8 & r8) == 0;
                            }
                            if (!(c1023)) {
                                POLL();
                                continue;
                            } else {
                                r0 = 0;
                                break;
                            }
                        } else {
                            r1 = LD32(r8 + 52);
                            ST32(r8 + 24, r10);
                            if (!((r1 & r1) == 0)) {
                                r3 = LD32((r8 + 88));
                                r5 = r8 + 12;
                                r7 = r3 + 2;
                                r1 = LD16(r5);
                                ST16(r3, (r1 >> 1));
                                r1 = LD32(r8 + 16);
                                ST16(r7, (r1 >> 1));
                                r1 = LD16(r3);
                                r6 = r3 + 16;
                                ST16((r3 + 8), r1);
                                r1 = LD16(r7);
                                ST16((r3 + 10), r1);
                                r1 = LD16(r5);
                                ST16(r6, r1);
                                r1 = LD32(r8 + 16);
                                r4 = r3 + 18;
                                ST16(r4, r1);
                                r1 = LD16((r8 + 14));
                                r2 = LD16(r5);
                                ST16((r3 + 4), ((r1 - r2) >> 1));
                                r1 = LD32(r8 + 20);
                                r2 = LD32(r8 + 16);
                                ST16((r3 + 6), ((r1 - r2) >> 1));
                                r1 = LD32(r8 + 52);
                                ST32(r3 + 20, r1);
                                ST8((r3 + 28), 0);
                                ST16((r3 + 32), r9);
                                ST32(r3 + 12, r10);
                                ST32(r3 + 40, r9);
                                ST32(r3 + 44, r9);
                                ST32(0x06088028, r8);
                                ST32(0x06078024, r3);
                                r1 = LD16(r5);
                                ST16(r6, r1);
                                r1 = LD32(r8 + 16);
                                ST16(r4, r1);
                                r2 = LD16((r3 + 24));
                                r1 = LD16((r8 + 30));
                                c14 = (r2 + 1) * r1;
                                r4 = r11;
                                r1 = LD16(r6);
                                ST16(r6, (r1 + c14));
                                r5 = LD32(r8 + 16);
                                r0 = GCALL2(0x060106BC, r4, r5);
                                r0 = 1;
                                break;
                            } else {
                                ST32(r8 + 56, 20);
                                r0 = GCALL1(0x060287D0, 20);
                                ST32(r8 + 52, r0);
                                if ((r0 & r0) == 0) {
                                    POLL();
                                    ST32(r8 + 56, 0);
                                    r0 = 0;
                                    break;
                                } else {
                                    ST8(r0, 0);
                                    r3 = LD32((r8 + 88));
                                    r5 = r8 + 12;
                                    r7 = r3 + 2;
                                    r1 = LD16(r5);
                                    ST16(r3, (r1 >> 1));
                                    r1 = LD32(r8 + 16);
                                    ST16(r7, (r1 >> 1));
                                    r1 = LD16(r3);
                                    r6 = r3 + 16;
                                    ST16((r3 + 8), r1);
                                    r1 = LD16(r7);
                                    ST16((r3 + 10), r1);
                                    r1 = LD16(r5);
                                    ST16(r6, r1);
                                    r1 = LD32(r8 + 16);
                                    r4 = r3 + 18;
                                    ST16(r4, r1);
                                    r1 = LD16((r8 + 14));
                                    r2 = LD16(r5);
                                    ST16((r3 + 4), ((r1 - r2) >> 1));
                                    r1 = LD32(r8 + 20);
                                    r2 = LD32(r8 + 16);
                                    ST16((r3 + 6), ((r1 - r2) >> 1));
                                    r1 = LD32(r8 + 52);
                                    ST32(r3 + 20, r1);
                                    ST8((r3 + 28), 0);
                                    ST16((r3 + 32), r9);
                                    ST32(r3 + 12, r10);
                                    ST32(r3 + 40, r9);
                                    ST32(r3 + 44, r9);
                                    ST32(0x06088028, r8);
                                    ST32(0x06078024, r3);
                                    r1 = LD16(r5);
                                    ST16(r6, r1);
                                    r1 = LD32(r8 + 16);
                                    ST16(r4, r1);
                                    r2 = LD16((r3 + 24));
                                    r1 = LD16((r8 + 30));
                                    c14 = (r2 + 1) * r1;
                                    r4 = r11;
                                    r1 = LD16(r6);
                                    ST16(r6, (r1 + c14));
                                    r5 = LD32(r8 + 16);
                                    r0 = GCALL2(0x060106BC, r4, r5);
                                    r0 = 1;
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
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603486C(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, c0, c1, c11, c1012;
    FRAME(sp, 572);

    r11 = r4;
    r8 = r5;
    r13 = LD32(r11 + 0x10D4);
    r9 = r6;
    r10 = (sp - 572) + 32;
    r12 = 0x06075104;
    do {
        r0 = GCALL4(0x06018CC0, r11, r9, (sp - 572), r10);
        r9 = r0;
        c0 = (r9 & r9) == 0;
        c1012 = c0;
        if (!(c0)) {
            r0 = GCALL2(r12, 0x06034860, (sp - 572));
            c1 = (r0 & r0) == 0;
            r0 = c1;
            if (!(c1)) {
                r0 = GCALL2(r12, 0x06034260, (sp - 572));
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL2(r12, 0x06034268, (sp - 572));
                    c1012 = (r9 & r9) == 0;
                    if ((r0 & r0) == 0) {
                        r0 = GCALL2(0x06045710, r13, r10);
                        ST16((r8 + 64), r0);
                        c1012 = (r9 & r9) == 0;
                    }
                } else {
                    r4 = LD32(r8 + 60);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                        ST32(r8 + 60, 0);
                    }
                    r0 = GCALL1(0x0607507C, r10);
                    r0 = GCALL1(0x060287D0, (r0 + 1));
                    r2 = r0;
                    ST32(r8 + 60, r2);
                    if ((r2 & r2) == 0) {
                        c1012 = (r9 & r9) == 0;
                    } else {
                        r0 = GCALL2(0x06018930, r2, r10);
                        c1012 = (r9 & r9) == 0;
                    }
                }
            } else {
                ST32(r8 + 56, r0);
                c1012 = (r9 & r9) == 0;
            }
        }
    } while (AGAIN(!(c1012)));
    r1 = LD32(r8 + 56);
    r5 = r8;
    if ((r1 & r1) == 0) {
        r5 = r5 + 64;
        r1 = LD16(r5);
        c11 = (r1 & r1) == 0;
        r1 = 1;
        if (c11) {
            ST16(r5, r1);
        }
    } else {
        r5 = r5 + 64;
        r2 = LD16(r5);
        r1 = 3;
        if (!(r2 > 2)) {
            ST16(r5, r1);
        }
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06034990(int r4, int r5, int r6)
{
    int r0, r2, r8, r9, r10, r11, r12, r13, r14, c0, c7, c8, c1018;
    FRAME(sp, 576);

    r12 = r4;
    r8 = r5;
    r11 = (sp - 576) + 32;
    r13 = 0x06075104;
    r14 = 0x06027F48;
    r10 = r6;
    while (1) {
        r0 = GCALL4(0x06018CC0, r12, r10, (sp - 576), r11);
        r9 = r0;
        c0 = (r9 & r9) == 0;
        c1018 = c0;
        if (c0) {
            r10 = r9;
            if (!(c1018)) {
                POLL();
                continue;
            } else {
                r0 = 1;
                break;
            }
        } else {
            r0 = GCALL2(r13, 0x060342C4, (sp - 576));
            if (!((r0 & r0) == 0)) {
                r0 = GCALL2(r13, 0x06034978, (sp - 576));
                c7 = (r0 & r0) == 0;
                r2 = c7;
                if (!(c7)) {
                    r0 = GCALL2(r13, 0x06034984, (sp - 576));
                    c8 = (r0 & r0) == 0;
                    r2 = c8;
                    if (c8) {
                        ST32(r8 + 8, r2);
                        r0 = GCALL3(0x06018AFC, r12, r10, (sp - 576));
                        r9 = r0;
                    }
                } else {
                    ST32(r8, r2);
                    ST32(r8 + 4, r2);
                    r0 = GCALL3(0x06018AFC, r12, r10, (sp - 576));
                    r9 = r0;
                }
                c1018 = (r9 & r9) == 0;
                r10 = r9;
                if (!(c1018)) {
                    POLL();
                    continue;
                } else {
                    r0 = 1;
                    break;
                }
            } else {
                r4 = LD32(r8 + 12);
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(r14, r4);
                    ST32(r8 + 12, 0);
                }
                r0 = GCALL1(0x0607507C, r11);
                r10 = 0x060287D0;
                r0 = GCALL1(0x060287D0, (r0 + 1));
                ST32(r8 + 12, r0);
                if (!((r0 & r0) == 0)) {
                    r4 = LD32(r8 + 16);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(r14, r4);
                        ST32(r8 + 16, 0);
                    }
                    r0 = GCALL1(0x0607507C, r11);
                    r0 = GCALL1(r10, (r0 + 1));
                    ST32(r8 + 16, r0);
                    if (!((r0 & r0) == 0)) {
                        r4 = LD32(r8 + 12);
                        r0 = GCALL2(0x06018930, r4, r11);
                        r5 = LD32(r8 + 12);
                        r4 = LD32(r8 + 16);
                        r0 = GCALL2(0x060750DC, r4, r5);
                        c1018 = (r9 & r9) == 0;
                        r10 = r9;
                        if (!(c1018)) {
                            POLL();
                            continue;
                        } else {
                            r0 = 1;
                            break;
                        }
                    } else {
                        r4 = LD32(r8 + 12);
                        r0 = GCALL1(r14, r4);
                        ST32(r8 + 12, 0);
                        r0 = 0;
                        break;
                    }
                } else {
                    r0 = 0;
                    break;
                }
            }
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060365E8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c1, c1004, c1007;
    FRAME(sp, 44);

    r8 = r4;
    r14 = r5;
    r9 = r6;
    r13 = r7;
    r11 = LD32(sp + 4);
    r0 = GCALL1(0x0607507C, r13);
    r10 = r0;
    r0 = GCALL3(0x060350C4, r8, (sp - 44), (sp - 40));
    r2 = r9 + 26;
    r1 = LD16(r2);
    c1 = r10 > r11;
    if (!((r1 + r10) >= r11)) {
        r1 = r11;
        if (!(c1)) {
            r1 = 0;
            c1004 = 0;
        } else {
            r1 = r1 - r10;
            c1004 = 1;
        }
        ST16(r2, r1);
    }
    r12 = r9 + 24;
    r2 = LD16(r12);
    r3 = r9 + 26;
    r1 = LD16(r3);
    r2 = r2 + r1;
    c1007 = r2 >= 0;
    if (r2 > r11) {
        r2 = r2 - r1;
        r1 = r11 - r10;
        ST16(r3, r1);
        r2 = r2 + ((short)r1);
        c1007 = r2 >= 0;
    }
    if (!(c1007)) {
        r1 = LD16(r3);
        ST16(r3, (r1 - r2));
    }
    r8 = LD16(r3);
    r1 = r10 + r8;
    if (r11 > r1) {
        r11 = r1;
    }
    r4 = LD32(sp);
    r0 = GCALL3(0x0604B358, r4, (r13 - r8), r11);
    r0 = LD32(sp);
    ST8(r0 + r11, 0);
    r1 = LD16((r14 + 12));
    r6 = r9 + 2;
    ST16(r9, (r1 >> 1));
    r1 = LD32(r14 + 16);
    ST16(r6, (r1 >> 1));
    r2 = LD16(r9);
    r7 = r9 + 16;
    r2 = r2 + r2;
    ST16(r7, r2);
    r1 = LD16(r12);
    r3 = LD32(sp - 44);
    ST16(r7, ((r2 + ((r1 + 1) * r3)) + (r8 * r3)));
    r1 = LD16(r6);
    ST16((r9 + 18), (r1 + r1));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060372AC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, c1, c2, c12, c13, c1006;

    r9 = r5;
    r10 = 1;
    ST32(r9 + 24, 1);
    r2 = LD16((r9 + 64));
    r4 = r7;
    if (!(r2 > 1)) {
        r1 = LD16((r9 + 34));
        c13 = r6 > r1;
        r1 = r9;
        if (!(c13)) {
            r1 = LD16((r1 + 32));
            if (r6 > r1) {
                r1 = LD32(r9 + 52);
                r8 = LD32(r1 + 24);
                r1 = 0;
                if ((r8 & r8) == 0) {
                    ST32(r9 + 24, r1);
                } else {
                    r4 = LD32(r9 + 44);
                    r0 = GCALL1(0x06037298, r4);
                    ST32(r9 + 52, r8);
                    ST32(r8, r10);
                }
            }
        } else {
            r1 = LD32(r9 + 52);
            r8 = LD32(r1 + 28);
            r1 = 0;
            if (!((r8 & r8) == 0)) {
                r4 = LD32(r9 + 44);
                r0 = GCALL1(0x06037298, r4);
                ST32(r9 + 52, r8);
                ST32(r8, r10);
            } else {
                ST32(r9 + 24, r1);
            }
        }
    } else {
        r1 = LD16((r9 + 36));
        c1 = r6 >= r1;
        r1 = r9;
        if (c1) {
            r1 = LD16((r1 + 32));
            if (r4 >= r1) {
                r1 = LD16((r9 + 34));
                if (r4 > r1) {
                    r1 = LD32(r9 + 52);
                    r8 = LD32(r1 + 24);
                    r1 = r1 + 20;
                    if ((r8 & r8) == 0) {
                        r1 = 0;
                        ST32(r9 + 24, r1);
                    } else {
                        r1 = LD16(r1);
                        r1 = r1 + r2;
                        r2 = LD16((r9 + 40));
                        c12 = r1 >= r2;
                        r1 = 0;
                        if (c12) {
                            ST32(r9 + 24, r1);
                        } else {
                            ST32(r9 + 52, r8);
                        }
                    }
                }
            } else {
                r1 = LD32(r9 + 52);
                r8 = LD32(r1 + 28);
                r1 = 0;
                if (!((r8 & r8) == 0)) {
                    ST32(r9 + 52, r8);
                } else {
                    ST32(r9 + 24, r1);
                }
            }
        } else {
            r5 = LD16((r1 + 38));
            r8 = LD32(r9 + 52);
            r0 = GCALL2(0x0607286C, r4, r5);
            c2 = (r8 & r8) == 0;
            c1006 = c2;
            if (!(c2)) {
                do {
                    r8 = LD32(r8 + 24);
                    r0 = r0 - 1;
                } while (AGAIN(!((r8 & r8) == 0)));
                c1006 = (r8 & r8) == 0;
            }
            if (!(c1006)) {
                r1 = LD32(r9 + 56);
                if ((r1 & r1) == 0) {
                    r4 = LD32(r9 + 44);
                    r0 = GCALL1(0x06037298, r4);
                }
                r1 = LD32(r8);
                ST32(r8, ((r1 & r1) == 0));
            }
        }
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037924(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c11, c18, c25, c29, c30, c31, c33, c1034, c1050;
    int v36;
    int v40;

    v40 = r4;
    r8 = r5;
    r10 = r6;
    r4 = r7;
    r14 = 0;
    ST32(0x060766C0, 0);
    r0 = LD16((r8 + 46));
    r5 = 2;
    if (r0 == 1) {
        r5 = 4;
    }
    ST32(r8 + 24, 1);
    r0 = r8 + 14;
    r13 = r8 + 12;
    r2 = LD16(r0);
    r12 = r8 + 30;
    v36 = r13;
    r1 = LD16(r12);
    r7 = LD16(r13);
    r6 = (r2 - r7) - (r5 * r1);
    r1 = LD32(r8 + 20);
    r6 = r6 - 2;
    r2 = LD32(r8 + 16);
    r11 = r8 + 28;
    r9 = LD32(r8 + 40);
    r1 = r1 - r2;
    r2 = LD16(r11);
    r3 = (r1 - r2) - 2;
    if (r10 >= r6) {
        c1034 = r4 > r3;
        if (!(r10 > r6)) {
            r1 = r8;
            if (c1034) {
                r0 = LD16((r1 + 44));
                c25 = r10 >= r6;
                if (!(r0 == 1)) {
                    r1 = r8;
                    if (!(c25)) {
                        r3 = LD16((r1 + 30));
                        r2 = r3 + r3;
                        c29 = r10 > (r6 - r2);
                        r5 = c29;
                        if (!(c29)) {
                            c30 = r10 >= r2;
                            r1 = 9;
                            c1050 = c30;
                            if (!(c30)) {
                                r0 = 0x0604266C;
                                r5 = -1;
                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                if (!((r0 & r0) == 0)) {
                                    ST32(0x060766C0, -12);
                                }
                            } else {
                                c31 = r0 > r1;
                                r1 = r3;
                                if (c31) {
                                    r1 = r1 << 2;
                                    r5 = 1;
                                    if (r10 >= r1) {
                                        r6 = r6 - r1;
                                        c33 = r10 > r6;
                                        c1050 = c33;
                                        if (c33) {
                                            r0 = 0x0604266C;
                                            r5 = -1;
                                            r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                            if (!((r0 & r0) == 0)) {
                                                ST32(0x060766C0, -12);
                                            }
                                        }
                                    } else {
                                        r0 = 0x0604266C;
                                        r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                        if (!((r0 & r0) == 0)) {
                                            ST32(0x060766C0, -12);
                                        }
                                    }
                                }
                            }
                        } else {
                            r0 = 0x0604266C;
                            r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                            if (!((r0 & r0) == 0)) {
                                ST32(0x060766C0, -12);
                            }
                        }
                    }
                } else {
                    r2 = LD16((r8 + 30));
                    r1 = r8;
                    if (!(r10 > (r2 + r2))) {
                        r1 = LD16((r1 + 30));
                        if (!(r10 >= (r1 + r1))) {
                            c1050 = 0;
                            r0 = 0x0604266C;
                            r5 = -1;
                            r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                            if (!((r0 & r0) == 0)) {
                                ST32(0x060766C0, -12);
                            }
                        }
                    } else {
                        r5 = 1;
                        if (r10 >= (r2 << 2)) {
                            r1 = r8;
                            r1 = LD16((r1 + 30));
                            if (!(r10 >= (r1 + r1))) {
                                c1050 = 0;
                                r0 = 0x0604266C;
                                r5 = -1;
                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                if (!((r0 & r0) == 0)) {
                                    ST32(0x060766C0, -12);
                                }
                            }
                        } else {
                            r0 = 0x0604266C;
                            r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                            if (!((r0 & r0) == 0)) {
                                ST32(0x060766C0, -12);
                            }
                        }
                    }
                }
            }
        } else {
            r1 = r8;
            if (r4 >= r3) {
                c1034 = r4 > r3;
                r1 = r8;
                if (c1034) {
                    r0 = LD16((r1 + 44));
                    c25 = r10 >= r6;
                    if (!(r0 == 1)) {
                        r1 = r8;
                        if (!(c25)) {
                            r3 = LD16((r1 + 30));
                            r2 = r3 + r3;
                            c29 = r10 > (r6 - r2);
                            r5 = c29;
                            if (!(c29)) {
                                c30 = r10 >= r2;
                                r1 = 9;
                                c1050 = c30;
                                if (!(c30)) {
                                    r0 = 0x0604266C;
                                    r5 = -1;
                                    r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                    if (!((r0 & r0) == 0)) {
                                        ST32(0x060766C0, -12);
                                    }
                                } else {
                                    c31 = r0 > r1;
                                    r1 = r3;
                                    if (c31) {
                                        r1 = r1 << 2;
                                        r5 = 1;
                                        if (r10 >= r1) {
                                            r6 = r6 - r1;
                                            c33 = r10 > r6;
                                            c1050 = c33;
                                            if (c33) {
                                                r0 = 0x0604266C;
                                                r5 = -1;
                                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                                if (!((r0 & r0) == 0)) {
                                                    ST32(0x060766C0, -12);
                                                }
                                            }
                                        } else {
                                            r0 = 0x0604266C;
                                            r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                            if (!((r0 & r0) == 0)) {
                                                ST32(0x060766C0, -12);
                                            }
                                        }
                                    }
                                }
                            } else {
                                r0 = 0x0604266C;
                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                if (!((r0 & r0) == 0)) {
                                    ST32(0x060766C0, -12);
                                }
                            }
                        }
                    } else {
                        r2 = LD16((r8 + 30));
                        r1 = r8;
                        if (!(r10 > (r2 + r2))) {
                            r1 = LD16((r1 + 30));
                            if (!(r10 >= (r1 + r1))) {
                                c1050 = 0;
                                r0 = 0x0604266C;
                                r5 = -1;
                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                if (!((r0 & r0) == 0)) {
                                    ST32(0x060766C0, -12);
                                }
                            }
                        } else {
                            r5 = 1;
                            if (r10 >= (r2 << 2)) {
                                r1 = r8;
                                r1 = LD16((r1 + 30));
                                if (!(r10 >= (r1 + r1))) {
                                    c1050 = 0;
                                    r0 = 0x0604266C;
                                    r5 = -1;
                                    r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                    if (!((r0 & r0) == 0)) {
                                        ST32(0x060766C0, -12);
                                    }
                                }
                            } else {
                                r0 = 0x0604266C;
                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                if (!((r0 & r0) == 0)) {
                                    ST32(0x060766C0, -12);
                                }
                            }
                        }
                    }
                }
            } else {
                r0 = LD16((r1 + 46));
                r1 = r8;
                if (!(r0 == 1)) {
                    r2 = LD16((r1 + 28));
                    r6 = 0;
                    if (r4 >= r2) {
                        r1 = 5;
                        if (!(r4 > (r3 - r2))) {
                            c18 = r0 > r1;
                            r1 = r2;
                            if (c18) {
                                r1 = r1 + r1;
                                r6 = 0;
                                if (r4 >= r1) {
                                    r5 = -1;
                                    if (r4 > (r3 - r1)) {
                                        r0 = GCALL6(0x060425D4, r9, r5, r6, 0, v40, v36);
                                        if (!((r0 & r0) == 0)) {
                                            r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                                            ST32(0x060766C0, -12);
                                        }
                                    }
                                } else {
                                    r0 = GCALL6(0x060425D4, r9, 1, r6, 0, v40, v36);
                                    if (!((r0 & r0) == 0)) {
                                        r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                                        ST32(0x060766C0, -12);
                                    }
                                }
                            }
                        } else {
                            r0 = GCALL6(0x060425D4, r9, 1, 0, 0, v40, v36);
                            if (!((r0 & r0) == 0)) {
                                r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                                ST32(0x060766C0, -12);
                            }
                        }
                    } else {
                        r0 = GCALL6(0x060425D4, r9, -1, r6, 0, v40, v36);
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                            ST32(0x060766C0, -12);
                        }
                    }
                } else {
                    r1 = LD16((r1 + 30));
                    c11 = r10 >= ((r1 + r1) + r6);
                    r6 = 0;
                    if (c11) {
                        r0 = GCALL6(0x060425D4, r9, 1, r6, 0, v40, v36);
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                            ST32(0x060766C0, -12);
                        }
                    } else {
                        r0 = GCALL6(0x060425D4, r9, -1, r6, 0, v40, v36);
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                            ST32(0x060766C0, -12);
                        }
                    }
                }
            }
        }
    } else {
        r7 = r7 + 2;
        if (r4 >= r3) {
            c1034 = r4 > r3;
            if (!(r10 > r6)) {
                r1 = r8;
                if (c1034) {
                    r0 = LD16((r1 + 44));
                    c25 = r10 >= r6;
                    if (!(r0 == 1)) {
                        r1 = r8;
                        if (!(c25)) {
                            r3 = LD16((r1 + 30));
                            r2 = r3 + r3;
                            c29 = r10 > (r6 - r2);
                            r5 = c29;
                            if (!(c29)) {
                                c30 = r10 >= r2;
                                r1 = 9;
                                c1050 = c30;
                                if (!(c30)) {
                                    r0 = 0x0604266C;
                                    r5 = -1;
                                    r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                    if (!((r0 & r0) == 0)) {
                                        ST32(0x060766C0, -12);
                                    }
                                } else {
                                    c31 = r0 > r1;
                                    r1 = r3;
                                    if (c31) {
                                        r1 = r1 << 2;
                                        r5 = 1;
                                        if (r10 >= r1) {
                                            r6 = r6 - r1;
                                            c33 = r10 > r6;
                                            c1050 = c33;
                                            if (c33) {
                                                r0 = 0x0604266C;
                                                r5 = -1;
                                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                                if (!((r0 & r0) == 0)) {
                                                    ST32(0x060766C0, -12);
                                                }
                                            }
                                        } else {
                                            r0 = 0x0604266C;
                                            r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                            if (!((r0 & r0) == 0)) {
                                                ST32(0x060766C0, -12);
                                            }
                                        }
                                    }
                                }
                            } else {
                                r0 = 0x0604266C;
                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                if (!((r0 & r0) == 0)) {
                                    ST32(0x060766C0, -12);
                                }
                            }
                        }
                    } else {
                        r2 = LD16((r8 + 30));
                        r1 = r8;
                        if (!(r10 > (r2 + r2))) {
                            r1 = LD16((r1 + 30));
                            if (!(r10 >= (r1 + r1))) {
                                c1050 = 0;
                                r0 = 0x0604266C;
                                r5 = -1;
                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                if (!((r0 & r0) == 0)) {
                                    ST32(0x060766C0, -12);
                                }
                            }
                        } else {
                            r5 = 1;
                            if (r10 >= (r2 << 2)) {
                                r1 = r8;
                                r1 = LD16((r1 + 30));
                                if (!(r10 >= (r1 + r1))) {
                                    c1050 = 0;
                                    r0 = 0x0604266C;
                                    r5 = -1;
                                    r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                    if (!((r0 & r0) == 0)) {
                                        ST32(0x060766C0, -12);
                                    }
                                }
                            } else {
                                r0 = 0x0604266C;
                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                if (!((r0 & r0) == 0)) {
                                    ST32(0x060766C0, -12);
                                }
                            }
                        }
                    }
                }
            } else {
                r1 = r8;
                if (r4 >= r3) {
                    c1034 = r4 > r3;
                    r1 = r8;
                    if (c1034) {
                        r0 = LD16((r1 + 44));
                        c25 = r10 >= r6;
                        if (!(r0 == 1)) {
                            r1 = r8;
                            if (!(c25)) {
                                r3 = LD16((r1 + 30));
                                r2 = r3 + r3;
                                c29 = r10 > (r6 - r2);
                                r5 = c29;
                                if (!(c29)) {
                                    c30 = r10 >= r2;
                                    r1 = 9;
                                    c1050 = c30;
                                    if (!(c30)) {
                                        r0 = 0x0604266C;
                                        r5 = -1;
                                        r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                        if (!((r0 & r0) == 0)) {
                                            ST32(0x060766C0, -12);
                                        }
                                    } else {
                                        c31 = r0 > r1;
                                        r1 = r3;
                                        if (c31) {
                                            r1 = r1 << 2;
                                            r5 = 1;
                                            if (r10 >= r1) {
                                                r6 = r6 - r1;
                                                c33 = r10 > r6;
                                                c1050 = c33;
                                                if (c33) {
                                                    r0 = 0x0604266C;
                                                    r5 = -1;
                                                    r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                                    if (!((r0 & r0) == 0)) {
                                                        ST32(0x060766C0, -12);
                                                    }
                                                }
                                            } else {
                                                r0 = 0x0604266C;
                                                r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                                if (!((r0 & r0) == 0)) {
                                                    ST32(0x060766C0, -12);
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    r0 = 0x0604266C;
                                    r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                    if (!((r0 & r0) == 0)) {
                                        ST32(0x060766C0, -12);
                                    }
                                }
                            }
                        } else {
                            r2 = LD16((r8 + 30));
                            r1 = r8;
                            if (!(r10 > (r2 + r2))) {
                                r1 = LD16((r1 + 30));
                                if (!(r10 >= (r1 + r1))) {
                                    c1050 = 0;
                                    r0 = 0x0604266C;
                                    r5 = -1;
                                    r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                    if (!((r0 & r0) == 0)) {
                                        ST32(0x060766C0, -12);
                                    }
                                }
                            } else {
                                r5 = 1;
                                if (r10 >= (r2 << 2)) {
                                    r1 = r8;
                                    r1 = LD16((r1 + 30));
                                    if (!(r10 >= (r1 + r1))) {
                                        c1050 = 0;
                                        r0 = 0x0604266C;
                                        r5 = -1;
                                        r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                        if (!((r0 & r0) == 0)) {
                                            ST32(0x060766C0, -12);
                                        }
                                    }
                                } else {
                                    r0 = 0x0604266C;
                                    r0 = GCALL6(r0, r9, r5, r6, r7, v40, v36);
                                    if (!((r0 & r0) == 0)) {
                                        ST32(0x060766C0, -12);
                                    }
                                }
                            }
                        }
                    }
                } else {
                    r0 = LD16((r1 + 46));
                    r1 = r8;
                    if (!(r0 == 1)) {
                        r2 = LD16((r1 + 28));
                        r6 = 0;
                        if (r4 >= r2) {
                            r1 = 5;
                            if (!(r4 > (r3 - r2))) {
                                c18 = r0 > r1;
                                r1 = r2;
                                if (c18) {
                                    r1 = r1 + r1;
                                    r6 = 0;
                                    if (r4 >= r1) {
                                        r5 = -1;
                                        if (r4 > (r3 - r1)) {
                                            r0 = GCALL6(0x060425D4, r9, r5, r6, 0, v40, v36);
                                            if (!((r0 & r0) == 0)) {
                                                r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                                                ST32(0x060766C0, -12);
                                            }
                                        }
                                    } else {
                                        r0 = GCALL6(0x060425D4, r9, 1, r6, 0, v40, v36);
                                        if (!((r0 & r0) == 0)) {
                                            r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                                            ST32(0x060766C0, -12);
                                        }
                                    }
                                }
                            } else {
                                r0 = GCALL6(0x060425D4, r9, 1, 0, 0, v40, v36);
                                if (!((r0 & r0) == 0)) {
                                    r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                                    ST32(0x060766C0, -12);
                                }
                            }
                        } else {
                            r0 = GCALL6(0x060425D4, r9, -1, r6, 0, v40, v36);
                            if (!((r0 & r0) == 0)) {
                                r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                                ST32(0x060766C0, -12);
                            }
                        }
                    } else {
                        r1 = LD16((r1 + 30));
                        c11 = r10 >= ((r1 + r1) + r6);
                        r6 = 0;
                        if (c11) {
                            r0 = GCALL6(0x060425D4, r9, 1, r6, 0, v40, v36);
                            if (!((r0 & r0) == 0)) {
                                r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                                ST32(0x060766C0, -12);
                            }
                        } else {
                            r0 = GCALL6(0x060425D4, r9, -1, r6, 0, v40, v36);
                            if (!((r0 & r0) == 0)) {
                                r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
                                ST32(0x060766C0, -12);
                            }
                        }
                    }
                }
            }
        } else {
            r7 = r7 >> 1;
            ST16(0x06087FF8, r7);
            r1 = LD32(r8 + 16);
            r1 = (r1 + 2) >> 1;
            ST16(0x06087FFA, r1);
            ST16(0x06088000, r7);
            ST16(0x06088002, r1);
            r2 = LD16(r12);
            r1 = LD16(r0);
            r1 = (r1 - ((r5 + 2) * r2)) - 4;
            r2 = LD16(r13);
            ST16(0x06087FFC, ((r1 - r2) >> 1));
            r1 = LD32(r8 + 20);
            r2 = LD16(r11);
            r1 = r1 - r2;
            r2 = LD32(r8 + 16);
            ST16(0x06087FFE, (((r1 - 4) - r2) >> 1));
            ST32(0x0608800C, 0x06087FC0);
            ST8(0x06087FC0, 0);
            ST16(0x06088010, 0);
            ST16(0x06088012, 0);
            ST8(0x06088014, 0);
            ST16(0x06088018, 0);
            ST32(0x06088004, 1);
            ST32(0x0608801C, 0x0603739C);
            ST32(0x06088020, r14);
            ST32(0x06088024, r14);
            ST32(0x06088028, r8);
            ST32(0x06078024, 0x06087FF8);
            r5 = LD16(r11);
            r0 = GCALL6(0x0607286C, r4, r5, 0, 0, v40, v36);
            r1 = LD32(r9 + 40);
            ST32(r9 + 24, (r1 + r0));
            r5 = LD16(r12);
            r0 = GCALL6(0x0607286C, r10, r5, 0, 0, v40, v36);
            r1 = LD32(r9 + 44);
            ST32(r9 + 28, ((r1 - 1) + r0));
            r0 = GCALL6(0x060426FC, r9, 0, 0, 0, v40, v36);
            r1 = LD32(r9 + 28);
            if (!(r1 >= 0)) {
                ST32(r9 + 28, r14);
            }
            r0 = GCALL6(0x060378C8, r8, 0, 0, 0, v40, v36);
            r1 = LD32(r9 + 24);
            r2 = LD32(r9 + 40);
            r5 = LD32(r8 + 16);
            r1 = r1 - r2;
            r2 = LD16(r11);
            r0 = GCALL6(0x060106BC, v40, (r5 + ((r1 + 1) * r2)), 0, 0, v40, v36);
        }
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603807C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r14, c2, c30, c1029, c1036;
    FRAME(sp, 104);

    r9 = r5;
    r14 = r6;
    r12 = r7;
    r5 = LD32((104 + (sp - 104)));
    r11 = 0;
    ST32((sp - 36), 0);
    if (!((r9 & r9) == 0)) {
        r10 = LD32(r9 + 36);
        if ((r10 & r10) == 0) {
            r10 = 0x06033094;
        }
        r1 = LD32(r9 + 32);
        r1 = r1 - 1;
        c2 = (unsigned)r1 > (unsigned)7;
        r1 = r1 + r1;
        if (!(c2)) {
            r1 = LD16(0x060380CC + r1);
            switch (r1) {
            case 16:
                r1 = LD32((r9 + 64));
                c1029 = (r11 & r11) == 0;
                if (!((r1 & r1) == 0)) {
                    r11 = 1;
                    c1029 = (r11 & r11) == 0;
                }
                break;
            case 48:
                r1 = LD32(r9 + 52);
                r11 = 1;
                if ((r1 & r1) == 0) {
                    r8 = 0x060752FC;
                    r0 = GCALL3(0x060752FC, r10, 0x06038034, 15);
                    r6 = 14;
                    if (!((r0 & r0) == 0)) {
                        r0 = GCALL3(r8, r10, 0x06038044, r6);
                        r6 = 18;
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL3(r8, r10, 0x06038058, r6);
                            c1029 = (r11 & r11) == 0;
                            if ((r0 & r0) == 0) {
                                r0 = GCALL1(0x060287D0, 6);
                                ST32(r9 + 52, r0);
                                if (!((r0 & r0) == 0)) {
                                    r2 = LD8(0x06038074);
                                    ST8(r0, r2);
                                    r3 = LD8(0x06038075);
                                    r2 = r0 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06038076);
                                    r1 = 0x06038077;
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(r1);
                                    r1 = r1 + 1;
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(r1);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r1 = LD8((r1 + 1));
                                    ST8((r2 + 1), r1);
                                }
                                c1029 = (r11 & r11) == 0;
                            }
                        } else {
                            r0 = GCALL1(0x060287D0, 4);
                            ST32(r9 + 52, r0);
                            if (!((r0 & r0) == 0)) {
                                r2 = LD8(0x06038054);
                                r1 = 0x06038055;
                                ST8(r0, r2);
                                r2 = r0;
                                r3 = LD8(r1);
                                r1 = r1 + 1;
                                r2 = r2 + 1;
                                ST8(r2, r3);
                                r3 = LD8(r1);
                                r2 = r2 + 1;
                                ST8(r2, r3);
                                r1 = LD8((r1 + 1));
                                ST8((r2 + 1), r1);
                            }
                            c1029 = (r11 & r11) == 0;
                        }
                    } else {
                        r0 = GCALL1(0x06046DD8, (sp - 104));
                        r0 = GCALL1(0x0607507C, (sp - 104));
                        r0 = GCALL1(0x060287D0, (r0 + 1));
                        r1 = r0;
                        ST32(r9 + 52, r1);
                        if ((r1 & r1) == 0) {
                            c1029 = (r11 & r11) == 0;
                        } else {
                            r0 = GCALL2(0x060750DC, r1, (sp - 104));
                            c1029 = (r11 & r11) == 0;
                        }
                    }
                } else {
                    r1 = LD8(r1);
                    c1029 = (r11 & r11) == 0;
                    if ((r1 & r1) == 0) {
                        r8 = 0x060752FC;
                        r0 = GCALL3(0x060752FC, r10, 0x06038034, 15);
                        r6 = 14;
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL3(r8, r10, 0x06038044, r6);
                            r6 = 18;
                            if (!((r0 & r0) == 0)) {
                                r0 = GCALL3(r8, r10, 0x06038058, r6);
                                c1029 = (r11 & r11) == 0;
                                if ((r0 & r0) == 0) {
                                    r0 = GCALL1(0x060287D0, 6);
                                    ST32(r9 + 52, r0);
                                    if (!((r0 & r0) == 0)) {
                                        r2 = LD8(0x06038074);
                                        ST8(r0, r2);
                                        r3 = LD8(0x06038075);
                                        r2 = r0 + 1;
                                        ST8(r2, r3);
                                        r3 = LD8(0x06038076);
                                        r1 = 0x06038077;
                                        r2 = r2 + 1;
                                        ST8(r2, r3);
                                        r3 = LD8(r1);
                                        r1 = r1 + 1;
                                        r2 = r2 + 1;
                                        ST8(r2, r3);
                                        r3 = LD8(r1);
                                        r2 = r2 + 1;
                                        ST8(r2, r3);
                                        r1 = LD8((r1 + 1));
                                        ST8((r2 + 1), r1);
                                    }
                                    c1029 = (r11 & r11) == 0;
                                }
                            } else {
                                r0 = GCALL1(0x060287D0, 4);
                                ST32(r9 + 52, r0);
                                if (!((r0 & r0) == 0)) {
                                    r2 = LD8(0x06038054);
                                    r1 = 0x06038055;
                                    ST8(r0, r2);
                                    r2 = r0;
                                    r3 = LD8(r1);
                                    r1 = r1 + 1;
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(r1);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r1 = LD8((r1 + 1));
                                    ST8((r2 + 1), r1);
                                }
                                c1029 = (r11 & r11) == 0;
                            }
                        } else {
                            r0 = GCALL1(0x06046DD8, (sp - 104));
                            r0 = GCALL1(0x0607507C, (sp - 104));
                            r0 = GCALL1(0x060287D0, (r0 + 1));
                            r1 = r0;
                            ST32(r9 + 52, r1);
                            if ((r1 & r1) == 0) {
                                c1029 = (r11 & r11) == 0;
                            } else {
                                r0 = GCALL2(0x060750DC, r1, (sp - 104));
                                c1029 = (r11 & r11) == 0;
                            }
                        }
                    }
                }
                break;
            case 260:
                c1029 = (r11 & r11) == 0;
                break;
            case 32:
                r0 = GCALL1(0x0607507C, r10);
                c1029 = (r11 & r11) == 0;
                if (!((r0 & r0) == 0)) {
                    r11 = 1;
                    c1029 = (r11 & r11) == 0;
                }
                break;
            case 218:
                c1029 = (r11 & r11) == 0;
                if (!((r5 & r5) == 0)) {
                    r8 = 0x06075104;
                    r0 = GCALL2(0x06075104, r10, r5);
                    c1029 = (r11 & r11) == 0;
                    if ((r0 & r0) == 0) {
                        r4 = LD32(r9 + 52);
                        r5 = LD32((108 + (sp - 104)));
                        r0 = GCALL4(r8, r4, r5, r6, r7);
                        c1029 = (r11 & r11) == 0;
                        if ((r0 & r0) == 0) {
                            c1029 = (r11 & r11) == 0;
                            if ((r12 & r12) == 0) {
                                r11 = 1;
                                c1029 = (r11 & r11) == 0;
                            }
                        }
                    }
                }
                break;
            }
        } else {
            c1029 = (r11 & r11) == 0;
        }
        r8 = sp - 104;
        if (c1029) {
            r0 = 1;
        } else {
            r8 = r8 + 64;
            r11 = 0x060387F4;
            r0 = GCALL2(0x060387F4, r8, r10);
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r1 = LD32(r8);
                if ((r1 & r1) == 0) {
                    r0 = 0;
                } else {
                    r5 = LD32(r9 + 52);
                    c30 = (r12 & r12) == 0;
                    if ((r5 & r5) == 0) {
                        r9 = sp - 104;
                        r9 = r9 + 68;
                        r8 = (sp - 104) + 64;
                        r6 = LD32(r9);
                        r5 = LD32(r8);
                        r0 = GCALL3(0x06037FBC, r14, r5, r6);
                        r4 = LD32(r8);
                        if (!((r0 & r0) == 0)) {
                            r8 = 0x06027F48;
                            r0 = GCALL1(0x06027F48, r4);
                            r4 = LD32(r9);
                            r0 = 1;
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(r8, r4);
                                r0 = 1;
                            }
                        } else {
                            r8 = 0x06027F48;
                            r0 = GCALL1(0x06027F48, r4);
                            r4 = LD32(r9);
                            r0 = 0;
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(r8, r4);
                                r0 = 0;
                            }
                        }
                    } else {
                        r4 = sp - 104;
                        if (!(c30)) {
                            r0 = GCALL2(0x06038938, (r4 + 68), r5);
                            c1036 = (r0 & r0) == 0;
                        } else {
                            r0 = GCALL2(r11, (r4 + 68), r5);
                            c1036 = (r0 & r0) == 0;
                        }
                        r9 = sp - 104;
                        if (!(c1036)) {
                            r9 = r9 + 68;
                            r8 = (sp - 104) + 64;
                            r6 = LD32(r9);
                            r5 = LD32(r8);
                            r0 = GCALL3(0x06037FBC, r14, r5, r6);
                            r4 = LD32(r8);
                            if (!((r0 & r0) == 0)) {
                                r8 = 0x06027F48;
                                r0 = GCALL1(0x06027F48, r4);
                                r4 = LD32(r9);
                                r0 = 1;
                                if (!((r4 & r4) == 0)) {
                                    r0 = GCALL1(r8, r4);
                                    r0 = 1;
                                }
                            } else {
                                r8 = 0x06027F48;
                                r0 = GCALL1(0x06027F48, r4);
                                r4 = LD32(r9);
                                r0 = 0;
                                if (!((r4 & r4) == 0)) {
                                    r0 = GCALL1(r8, r4);
                                    r0 = 0;
                                }
                            }
                        } else {
                            r4 = LD32(r8);
                            r0 = GCALL1(0x06027F48, r4);
                            r0 = 0;
                        }
                    }
                }
            }
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060395A0(int r4)
{
    int r0, r1, r8, r9, r10, r11, r12, c1, c11, c1010;
    FRAME(sp, 40);

    r11 = r4;
    r0 = GCALL1(0x06039B40, r4);
    r9 = r0 - 2;
    r1 = 13;
    c1 = r9 > 0;
    c1010 = c1;
    if (r9 > 13) {
        r8 = 0;
        r12 = 0x06039B14;
        r10 = r1;
        do {
            r0 = GCALL1(r12, r11);
            ST8((sp - 40) + r8, r0);
            r8 = r8 + 1;
            r1 = LD8(sp - 40);
        } while (AGAIN(!(r8 > r10)));
        r9 = r9 - 14;
        if (!((r1 & 255) == 74)) {
            c1010 = r9 > 0;
        } else {
            r1 = LD8((sp - 39));
            c1010 = r9 > 0;
            if ((r1 & 255) == 70) {
                r1 = LD8((sp - 38));
                c1010 = r9 > 0;
                if ((r1 & 255) == 73) {
                    r1 = LD8((sp - 37));
                    c1010 = r9 > 0;
                    if ((r1 & 255) == 70) {
                        r1 = LD8((sp - 36));
                        c11 = r9 > 0;
                        c1010 = c11;
                        if (((r1 & 255) & (r1 & 255)) == 0) {
                            ST8((r11 + 43), 1);
                            c1010 = r9 > 0;
                        }
                    }
                }
            }
        }
    }
    r8 = 2;
    if (c1010) {
        if (!(r8 >= r9)) {
            r10 = 0x06039B14;
            do {
                r0 = GCALL1(r10, r11);
                r8 = r8 + 1;
            } while (AGAIN(!(r8 >= r9)));
        }
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039650(int r4)
{
    int r0, r1, r3, r8, r9, r10, r11, r12, c1, c11, c1010;
    FRAME(sp, 36);

    r10 = r4;
    r0 = GCALL1(0x06039B40, r4);
    r9 = r0 - 2;
    r1 = 11;
    c1 = r9 > 0;
    c1010 = c1;
    if (r9 > 11) {
        r8 = 0;
        r12 = 0x06039B14;
        r11 = r1;
        do {
            r0 = GCALL1(r12, r10);
            ST8((sp - 36) + r8, r0);
            r8 = r8 + 1;
            r1 = LD8(sp - 36);
        } while (AGAIN(!(r8 > r11)));
        r9 = r9 - 12;
        if (!((r1 & 255) == 65)) {
            c1010 = r9 > 0;
        } else {
            r1 = LD8((sp - 35));
            c1010 = r9 > 0;
            if ((r1 & 255) == 100) {
                r1 = LD8((sp - 34));
                c1010 = r9 > 0;
                if ((r1 & 255) == 111) {
                    r1 = LD8((sp - 33));
                    c1010 = r9 > 0;
                    if ((r1 & 255) == 98) {
                        r1 = LD8((sp - 32));
                        c11 = r9 > 0;
                        c1010 = c11;
                        if ((r1 & 255) == 101) {
                            r3 = LD8((sp - 25));
                            ST8((r10 + 44), 1);
                            ST8((r10 + 46), r3);
                            c1010 = r9 > 0;
                        }
                    }
                }
            }
        }
    }
    r8 = 2;
    if (c1010) {
        if (!(r8 >= r9)) {
            r11 = 0x06039B14;
            do {
                r0 = GCALL1(r11, r10);
                r8 = r8 + 1;
            } while (AGAIN(!(r8 >= r9)));
        }
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039C1C(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, c1, c1005;

    r10 = r4;
    r12 = r5 - 1;
    r2 = r10 + 124;
    r1 = LD32(r2);
    r9 = r12 - r1;
    c1 = (r9 & r9) == 0;
    c1005 = c1;
    if (!(r9 > 0)) {
        r9 = -r9;
        if (c1005) {
            ST32((r10 + 124), -1);
            r0 = r12 << 2;
            r2 = LD32((r10 + 116));
        } else {
            ST32((r10 + 124), (r9 - 1));
            r4 = LD32((r10 + 116));
            r0 = GCALL2(0x0607462C, r4, r9);
            r2 = r0;
            r0 = r12 << 2;
        }
    } else {
        r11 = r2;
        r13 = 0x06039B68;
        r8 = r10 + 116;
        while (1) {
            r2 = LD32(r11);
            if (r2 > 23) {
                r8 = r10 + 116;
                r4 = LD32(r8);
                r0 = GCALL2(0x0607290C, r4, r9);
                r13 = r0;
                r0 = GCALL1(0x06039B68, r10);
                r1 = r0;
                ST32(r8, r1);
                r0 = GCALL2(0x0607462C, r1, ((-r9) + 8));
                r2 = r13 | r0;
                ST32(r11, ((-r9) + 7));
                r0 = r12 << 2;
                break;
            } else {
                r0 = GCALL1(r13, r10);
                r1 = LD32(r8);
                r9 = r9 - 8;
                ST32(r8, ((r1 << 8) | r0));
                r1 = LD32(r11);
                ST32(r11, (r1 + 8));
                if (r9 > 0) {
                    POLL();
                    continue;
                } else {
                    c1005 = (r9 & r9) == 0;
                    r9 = -r9;
                    if (c1005) {
                        ST32((r10 + 124), -1);
                        r0 = r12 << 2;
                        r2 = LD32((r10 + 116));
                        break;
                    } else {
                        ST32((r10 + 124), (r9 - 1));
                        r4 = LD32((r10 + 116));
                        r0 = GCALL2(0x0607462C, r4, r9);
                        r2 = r0;
                        r0 = r12 << 2;
                        break;
                    }
                }
            }
            POLL();
        }
    }
    r1 = LD32(r0 + 0x0607820C);
    return r2 & r1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603CE40(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, c1, c6, c9, c1012;
    int v36;
    int v40;
    int v44;

    r9 = r5;
    ST32(r9 + 60, 0);
    r11 = -1;
    ST32(r9 + 56, -1);
    ST32((r9 + 64), 0);
    ST32(r9 + 12, 0x0608BAA0);
    ST32((r9 + 68), 0);
    r2 = LD8(0x060787C8);
    r10 = r4;
    if (r2 > 3) {
        r0 = 0;
    } else {
        r8 = 0x115;
        r12 = 0x060279E0;
        r0 = GCALL4(0x060279E0, 0, 0x115, r11, 1);
        r13 = r0;
        c1 = (r13 & r13) == 0;
        r7 = c1;
        if (!(c1)) {
            r8 = 136;
            r0 = r9;
            r4 = LD32(r0 + 136);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(0x06027F48, r4);
                r0 = r9;
            }
            ST32(r0 + r8, r13);
            ST32(r0 + 140, 0x115);
            r7 = LD8((r10 + 1));
            r6 = LD8(r10);
            r1 = LD32(r9 + 52);
            v36 = r1;
            r1 = LD8((r10 + 3));
            v40 = r1 & 255;
            r1 = LD8((r10 + 2));
            v44 = r1 & 255;
            r0 = GCALL7(0x06045264, 0x0608BAA0, 0x0603CE00, (r6 & 255), (r7 & 255), v44, v40, v36);
            r10 = 0;
            r0 = GCALL7(0x06010510, 0x0603CE10, 0, 0, 0, v44, v40, v36);
            r12 = 0x06059D88;
            r11 = 0x060767E4;
            r6 = 1;
            while (1) {
                r0 = GCALL3(r12, 0x0608BAA0, 0, r6);
                r1 = r0;
                r8 = (short)r1;
                ST16((r9 + 20), r1);
                if (r8 >= 0) {
                    c1012 = r8 == -502;
                    break;
                } else {
                    if (r8 == -506) {
                        c1012 = r8 == -502;
                        break;
                    } else {
                        c6 = r8 == -502;
                        c1012 = c6;
                        if (c6) {
                            break;
                        } else {
                            r0 = GCALL1(0x06059EBC, 2);
                            r1 = LD32(r11);
                            r10 = r10 + 1;
                            ST32(r11, (r1 + 12));
                            r6 = 1;
                            if (!(r10 > 4)) {
                                POLL();
                                continue;
                            } else {
                                c1012 = r8 == -502;
                                break;
                            }
                        }
                    }
                }
                POLL();
            }
            c9 = r8 >= 0;
            if (!(c1012)) {
                if (!(c9)) {
                    r0 = GCALL1(0x06010510, 0x0603CE1C);
                    r4 = LD32(r9 + 136);
                    r0 = GCALL1(0x06027F48, r4);
                    r0 = r9;
                    ST32(r0 + 136, 0);
                    ST32(r0 + 140, 0);
                    r0 = -1;
                } else {
                    r0 = GCALL1(0x06010510, 0x0603CE30);
                    ST32(0x060767E4, 100);
                    r1 = LD32(0x0608B980);
                    ST32((r9 + 80), r1);
                    ST32((r9 + 76), 0);
                    ST32((r9 + 88), 0);
                    r1 = LD8(0x060787C8);
                    r0 = 0;
                    ST8(0x060787C8, (r1 + 1));
                    ST32(r9 + 36, 1);
                }
            } else {
                r4 = LD32(r9 + 136);
                r0 = GCALL1(0x06027F48, r4);
                r0 = r9;
                ST32(r0 + 136, 0);
                ST32(r0 + 140, 0);
                r0 = 0;
            }
        } else {
            r0 = GCALL4(r12, 1, r8, r11, r7);
            r13 = r0;
            r0 = 0;
            if (!((r13 & r13) == 0)) {
                r8 = 136;
                r0 = r9;
                r4 = LD32(r0 + 136);
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(0x06027F48, r4);
                    r0 = r9;
                }
                ST32(r0 + r8, r13);
                ST32(r0 + 140, 0x115);
                r7 = LD8((r10 + 1));
                r6 = LD8(r10);
                r1 = LD32(r9 + 52);
                v36 = r1;
                r1 = LD8((r10 + 3));
                v40 = r1 & 255;
                r1 = LD8((r10 + 2));
                v44 = r1 & 255;
                r0 = GCALL7(0x06045264, 0x0608BAA0, 0x0603CE00, (r6 & 255), (r7 & 255), v44, v40, v36);
                r10 = 0;
                r0 = GCALL7(0x06010510, 0x0603CE10, 0, 0, 0, v44, v40, v36);
                r12 = 0x06059D88;
                r11 = 0x060767E4;
                r6 = 1;
                while (1) {
                    r0 = GCALL3(r12, 0x0608BAA0, 0, r6);
                    r1 = r0;
                    r8 = (short)r1;
                    ST16((r9 + 20), r1);
                    if (r8 >= 0) {
                        c1012 = r8 == -502;
                        break;
                    } else {
                        if (r8 == -506) {
                            c1012 = r8 == -502;
                            break;
                        } else {
                            c6 = r8 == -502;
                            c1012 = c6;
                            if (c6) {
                                break;
                            } else {
                                r0 = GCALL1(0x06059EBC, 2);
                                r1 = LD32(r11);
                                r10 = r10 + 1;
                                ST32(r11, (r1 + 12));
                                r6 = 1;
                                if (!(r10 > 4)) {
                                    POLL();
                                    continue;
                                } else {
                                    c1012 = r8 == -502;
                                    break;
                                }
                            }
                        }
                    }
                    POLL();
                }
                c9 = r8 >= 0;
                if (!(c1012)) {
                    if (!(c9)) {
                        r0 = GCALL1(0x06010510, 0x0603CE1C);
                        r4 = LD32(r9 + 136);
                        r0 = GCALL1(0x06027F48, r4);
                        r0 = r9;
                        ST32(r0 + 136, 0);
                        ST32(r0 + 140, 0);
                        r0 = -1;
                    } else {
                        r0 = GCALL1(0x06010510, 0x0603CE30);
                        ST32(0x060767E4, 100);
                        r1 = LD32(0x0608B980);
                        ST32((r9 + 80), r1);
                        ST32((r9 + 76), 0);
                        ST32((r9 + 88), 0);
                        r1 = LD8(0x060787C8);
                        r0 = 0;
                        ST8(0x060787C8, (r1 + 1));
                        ST32(r9 + 36, 1);
                    }
                } else {
                    r4 = LD32(r9 + 136);
                    r0 = GCALL1(0x06027F48, r4);
                    r0 = r9;
                    ST32(r0 + 136, 0);
                    ST32(r0 + 140, 0);
                    r0 = 0;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603EA7C(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14, c3, c7, c8, c9, c1009, c1010, c1015, c1016;
    int v36;
    int v40;

    v40 = r4;
    r13 = r5;
    r10 = r6;
    r9 = 0;
    v36 = 0;
    r12 = 0;
    r11 = 0;
    r14 = 0;
    if (!((r4 & r4) == 0)) {
        r0 = GCALL6(0x0603F000, v40, 1, 0, 0, v40, v36);
        c1015 = (unsigned)r9 >= (unsigned)r10;
        while (1) {
            r0 = r13;
            c1016 = c1015;
            if (!(c1015)) {
                POLL();
                r3 = r9 + r13;
                r2 = LD8(r0 + r9);
                r1 = LD8((r3 + 1));
                r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
                r1 = LD8((r3 + 2));
                r2 = r2 + ((r1 & 255) << 8);
                r1 = LD8((r3 + 3));
                r2 = r2 + (r1 & 255);
                r1 = r3;
                if (!((r2 & r2) == 0)) {
                    v36 = r2;
                    r2 = LD8((r1 + 4));
                    r1 = LD8((r3 + 5));
                    r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
                    r1 = LD8((r3 + 6));
                    r2 = r2 + ((r1 & 255) << 8);
                    r1 = LD8((r3 + 7));
                    r12 = r2 + (r1 & 255);
                    r2 = LD8((r3 + 8));
                    r1 = LD8((r3 + 9));
                    r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
                    r1 = LD8((r3 + 10));
                    r2 = r2 + ((r1 & 255) << 8);
                    r1 = LD8((r3 + 11));
                    r11 = r2 + (r1 & 255);
                } else {
                    r14 = 1;
                }
                r0 = GCALL6(0x0603E6E4, 0x0603EA64, 0, 0, 0, v40, v36);
                c3 = v36 == r0;
                c1009 = c3;
                if (!(c3)) {
                    r0 = -406;
                    break;
                } else {
                    r0 = GCALL6(0x0603E6E4, 0x0603EA6C, 0, 0, 0, v40, v36);
                    c1010 = (r12 & r12) == 0;
                    if (r11 == r0) {
                        c8 = (r14 & r14) == 0;
                        c1016 = c8;
                        if (c1010) {
                            r0 = 0;
                            break;
                        } else {
                            r1 = r12;
                            c1016 = c8;
                            if (!(c8)) {
                                r0 = 0;
                                break;
                            } else {
                                r8 = ((int)((unsigned)(r1 + 1) >> 1)) + ((int)((unsigned)(r1 + 1) >> 1));
                                c9 = (unsigned)((r9 + r8) + 8) > (unsigned)r10;
                                r7 = r9;
                                c1016 = c9;
                                if (c9) {
                                    r0 = 0;
                                    break;
                                } else {
                                    r0 = GCALL6(0x0603E798, v40, r13, r10, (r7 + 12), v40, v36);
                                    r9 = (r9 + 8) + r8;
                                    c1015 = (unsigned)r9 >= (unsigned)r10;
                                    continue;
                                }
                            }
                        }
                    } else {
                        r0 = GCALL6(0x0603E6E4, 0x0603EA74, 0, 0, 0, v40, v36);
                        c7 = (r12 & r12) == 0;
                        c1010 = c7;
                        c1009 = c7;
                        if (r11 == r0) {
                            c8 = (r14 & r14) == 0;
                            c1016 = c8;
                            if (c1010) {
                                r0 = 0;
                                break;
                            } else {
                                r1 = r12;
                                c1016 = c8;
                                if (!(c8)) {
                                    r0 = 0;
                                    break;
                                } else {
                                    r8 = ((int)((unsigned)(r1 + 1) >> 1)) + ((int)((unsigned)(r1 + 1) >> 1));
                                    c9 = (unsigned)((r9 + r8) + 8) > (unsigned)r10;
                                    r7 = r9;
                                    c1016 = c9;
                                    if (c9) {
                                        r0 = 0;
                                        break;
                                    } else {
                                        r0 = GCALL6(0x0603E798, v40, r13, r10, (r7 + 12), v40, v36);
                                        r9 = (r9 + 8) + r8;
                                        c1015 = (unsigned)r9 >= (unsigned)r10;
                                        continue;
                                    }
                                }
                            }
                        } else {
                            r0 = -406;
                            break;
                        }
                    }
                }
            } else {
                r0 = 0;
                break;
            }
        }
    } else {
        c1015 = (unsigned)r9 >= (unsigned)r10;
        while (1) {
            r0 = r13;
            c1016 = c1015;
            if (!(c1015)) {
                POLL();
                r3 = r9 + r13;
                r2 = LD8(r0 + r9);
                r1 = LD8((r3 + 1));
                r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
                r1 = LD8((r3 + 2));
                r2 = r2 + ((r1 & 255) << 8);
                r1 = LD8((r3 + 3));
                r2 = r2 + (r1 & 255);
                r1 = r3;
                if (!((r2 & r2) == 0)) {
                    v36 = r2;
                    r2 = LD8((r1 + 4));
                    r1 = LD8((r3 + 5));
                    r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
                    r1 = LD8((r3 + 6));
                    r2 = r2 + ((r1 & 255) << 8);
                    r1 = LD8((r3 + 7));
                    r12 = r2 + (r1 & 255);
                    r2 = LD8((r3 + 8));
                    r1 = LD8((r3 + 9));
                    r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
                    r1 = LD8((r3 + 10));
                    r2 = r2 + ((r1 & 255) << 8);
                    r1 = LD8((r3 + 11));
                    r11 = r2 + (r1 & 255);
                } else {
                    r14 = 1;
                }
                r0 = GCALL6(0x0603E6E4, 0x0603EA64, 0, 0, 0, v40, v36);
                c3 = v36 == r0;
                c1009 = c3;
                if (!(c3)) {
                    r0 = -406;
                    break;
                } else {
                    r0 = GCALL6(0x0603E6E4, 0x0603EA6C, 0, 0, 0, v40, v36);
                    c1010 = (r12 & r12) == 0;
                    if (r11 == r0) {
                        c8 = (r14 & r14) == 0;
                        c1016 = c8;
                        if (c1010) {
                            r0 = 0;
                            break;
                        } else {
                            r1 = r12;
                            c1016 = c8;
                            if (!(c8)) {
                                r0 = 0;
                                break;
                            } else {
                                r8 = ((int)((unsigned)(r1 + 1) >> 1)) + ((int)((unsigned)(r1 + 1) >> 1));
                                c9 = (unsigned)((r9 + r8) + 8) > (unsigned)r10;
                                r7 = r9;
                                c1016 = c9;
                                if (c9) {
                                    r0 = 0;
                                    break;
                                } else {
                                    r0 = GCALL6(0x0603E798, v40, r13, r10, (r7 + 12), v40, v36);
                                    r9 = (r9 + 8) + r8;
                                    c1015 = (unsigned)r9 >= (unsigned)r10;
                                    continue;
                                }
                            }
                        }
                    } else {
                        r0 = GCALL6(0x0603E6E4, 0x0603EA74, 0, 0, 0, v40, v36);
                        c7 = (r12 & r12) == 0;
                        c1010 = c7;
                        c1009 = c7;
                        if (r11 == r0) {
                            c8 = (r14 & r14) == 0;
                            c1016 = c8;
                            if (c1010) {
                                r0 = 0;
                                break;
                            } else {
                                r1 = r12;
                                c1016 = c8;
                                if (!(c8)) {
                                    r0 = 0;
                                    break;
                                } else {
                                    r8 = ((int)((unsigned)(r1 + 1) >> 1)) + ((int)((unsigned)(r1 + 1) >> 1));
                                    c9 = (unsigned)((r9 + r8) + 8) > (unsigned)r10;
                                    r7 = r9;
                                    c1016 = c9;
                                    if (c9) {
                                        r0 = 0;
                                        break;
                                    } else {
                                        r0 = GCALL6(0x0603E798, v40, r13, r10, (r7 + 12), v40, v36);
                                        r9 = (r9 + 8) + r8;
                                        c1015 = (unsigned)r9 >= (unsigned)r10;
                                        continue;
                                    }
                                }
                            }
                        } else {
                            r0 = -406;
                            break;
                        }
                    }
                }
            } else {
                r0 = 0;
                break;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06038B3C(int r4, int r5)
{
    int r0, r1, r2, r3, r7;

    r5 = LD32(r5);
    r7 = 0;
    if (!((r5 & r5) == 0)) {
        do {
            r0 = LD32(r5);
            ST32(r5 + 24, r7);
            if (r0 == 2) {
                r1 = LD32(r5 + 40);
                if (!((r1 & r1) == 0)) {
                    r3 = r1;
                    r1 = LD32(r3 + 20);
                    r1 = r1 - 1;
                    if (r1 >= 0) {
                        do {
                            r2 = LD32(r3 + 12);
                            r0 = r1 << 2;
                            r1 = r1 - 1;
                            ST32(r0 + r2, r7);
                        } while (AGAIN(r1 >= 0));
                    }
                }
            }
            r5 = LD32(r5 + 4);
        } while (AGAIN(!((r5 & r5) == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038C8C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, c0;

    r6 = 0;
    r7 = 1;
    r5 = 0x1DEC;
    r8 = 0x1CC;
    r3 = 4;
    do {
        r1 = LD32(r4 + r5);
        r1 = LD32(r3 + r1);
        r2 = 1;
        c0 = 1 > r1;
        r1 = r6;
        if (!(c0)) {
            r9 = (r1 << 2) + r4;
            do {
                ST32(r9 + r8, r7);
                r9 = r9 + 4;
                r1 = LD32(r4 + r5);
                r1 = LD32(r3 + r1);
                r2 = r2 + 1;
                r6 = r6 + 1;
            } while (AGAIN(!(r2 > r1)));
        }
        r7 = r7 + 1;
        r3 = r3 + 4;
    } while (AGAIN(!(r7 > 16)));
    r0 = (r6 << 2) + r4;
    ST32(r0 + 0x1CC, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038CE8(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10;

    r7 = 0;
    r2 = 0;
    r3 = LD32(0x1CC + r4);
    r9 = 0x5D4;
    r5 = 0x1CC;
    r8 = 0x100;
    r6 = r4;
    r1 = 0;
    while (1) {
        r10 = (r1 << 2) + r4;
        r0 = r10;
        while (1) {
            ST32(r0 + r9, r2);
            r2 = r2 + 1;
            r10 = r10 + 4;
            r6 = r6 + 4;
            r0 = r10;
            r1 = LD32(r0 + r5);
            r7 = r7 + 1;
            if (!(r1 == r3)) {
                break;
            } else {
                if (!(r7 > r8)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        r0 = r6;
        if ((r1 & r1) == 0) {
            break;
        } else {
            r1 = LD32(r0 + r5);
            do {
                r3 = r3 + 1;
                r2 = r2 + r2;
            } while (AGAIN(!(r1 == r3)));
            r1 = r7;
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060392A0(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    int v36;

    r14 = r4;
    r0 = GCALL1(0x06039B40, r4);
    r13 = r0 - 2;
    r0 = 0;
    if (r13 > 0) {
        r12 = 132;
        r11 = 0x06078690;
        while (1) {
            r0 = GCALL1(0x06039B14, r14);
            r2 = r0;
            v36 = ((((r2 >> 1) >> 1) >> 1) >> 1) & 15;
            r1 = r2 & 15;
            if (!(v36 > 1)) {
                r8 = (r1 << 2) + r14;
                r1 = LD32(r8 + r12);
                r0 = v36;
                if ((r1 & r1) == 0) {
                    r0 = GCALL5(0x060279E0, 0, 0x104, -1, 1, v36);
                    ST32(r8 + r12, r0);
                    r0 = v36;
                }
                r9 = 0;
                if ((r0 & r0) == 0) {
                    r10 = r8;
                    r8 = 0;
                    do {
                        r0 = GCALL5(0x06039B14, r14, 0, 0, 0, v36);
                        r2 = r0;
                        r1 = LD32(r8 + r11);
                        r3 = LD32(r10 + r12);
                        ST32((r1 << 2) + r3, r2);
                        if ((r2 & r2) == 0) {
                            r0 = r8;
                            if ((r9 & r9) == 0) {
                                r1 = LD32(r0 + r11);
                                r2 = LD32(r10 + r12);
                                ST32((r1 << 2) + r2, 16);
                            } else {
                                r1 = LD32(r0 + r11);
                                r2 = r1 << 2;
                                r3 = LD32(r10 + r12);
                                r1 = LD32(r8 + (r11 - 4));
                                r1 = LD32((r1 << 2) + r3);
                                ST32(r2 + r3, r1);
                            }
                        }
                        r9 = r9 + 1;
                        r8 = r8 + 4;
                    } while (AGAIN(!(r9 > 63)));
                    r0 = v36;
                } else {
                    r10 = r8;
                    r8 = 0;
                    do {
                        r0 = GCALL5(0x06039B40, r14, 0, 0, 0, v36);
                        r2 = r0;
                        r1 = LD32(r8 + r11);
                        r3 = LD32(r10 + r12);
                        ST32((r1 << 2) + r3, r2);
                        if ((r2 & r2) == 0) {
                            r0 = r8;
                            if ((r9 & r9) == 0) {
                                r1 = LD32(r0 + r11);
                                r2 = LD32(r10 + r12);
                                ST32((r1 << 2) + r2, 16);
                            } else {
                                r1 = LD32(r0 + r11);
                                r2 = r1 << 2;
                                r3 = LD32(r10 + r12);
                                r1 = LD32(r8 + (r11 - 4));
                                r1 = LD32((r1 << 2) + r3);
                                ST32(r2 + r3, r1);
                            }
                        }
                        r9 = r9 + 1;
                        r8 = r8 + 4;
                    } while (AGAIN(!(r9 > 63)));
                    r0 = v36;
                }
                r13 = r13 - 65;
                if (!((r0 & r0) == 0)) {
                    r13 = r13 - 64;
                }
                r0 = 0;
                if (!(r13 > 0)) {
                    break;
                } else {
                    POLL();
                    continue;
                }
            } else {
                r0 = -303;
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603AD94(int r4)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, c7, c15;

    r12 = r4;
    r10 = 0;
    r9 = 0x06027F48;
    r8 = r12;
    do {
        r4 = LD32(0x108 + r8);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(r9, r4);
        }
        r4 = LD32(200 + r8);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(r9, r4);
        }
        r4 = LD32(0x18C + r8);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(r9, r4);
        }
        r4 = LD32(0x14C + r8);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(r9, r4);
        }
        r4 = LD32(132 + r8);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(r9, r4);
        }
        r10 = r10 + 1;
        r8 = r8 + 4;
    } while (AGAIN(!(r10 > 15)));
    r2 = 0x1DE0;
    r0 = r12;
    r1 = LD32(r0 + 0x1DE0);
    if (!((r1 & r1) == 0)) {
        r1 = LD32(r1);
        r10 = 0;
        c7 = 0 >= r1;
        r1 = 0;
        if (!(c7)) {
            r11 = 0x06027F48;
            do {
                r2 = LD32(r0 + r2);
                r9 = LD32((((r1 << 2) + r2) + 76));
                if (!((r9 & r9) == 0)) {
                    r1 = LD32(r9 + 4);
                    r8 = LD32(r9 + 40);
                    if (!((unsigned)r8 >= (unsigned)((r1 << 2) + r8))) {
                        do {
                            r4 = LD32(r8);
                            if (!((r4 & r4) == 0)) {
                                r4 = LD32(r4 + 20);
                                if (!((r4 & r4) == 0)) {
                                    r0 = GCALL1(r11, r4);
                                }
                                r4 = LD32(r8);
                                r0 = GCALL1(r11, r4);
                            }
                            r2 = LD32(r9 + 4);
                            r8 = r8 + 4;
                            r1 = LD32(r9 + 40);
                        } while (AGAIN(!((unsigned)r8 >= (unsigned)(r1 + (r2 << 2)))));
                    }
                    r4 = LD32(r9 + 44);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(r11, r4);
                    }
                    r4 = LD32(r9 + 40);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(r11, r4);
                    }
                    r0 = GCALL1(r11, r9);
                }
                r2 = 0x1DE0;
                r0 = r12;
                r1 = LD32(r0 + 0x1DE0);
                r1 = LD32(r1);
                r10 = r10 + 1;
                c15 = r10 >= r1;
                r1 = r10;
            } while (AGAIN(!(c15)));
        }
        r4 = LD32(r12 + 0x1DE0);
        r0 = GCALL1(0x06027F48, r4);
        r0 = r12;
        ST32(r0 + 0x1DE0, 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603B100(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c2;
    FRAME(sp, 72);

    ST32(sp - 72, r5);
    ST32(sp - 68, r7);
    r2 = LD32(sp - 72);
    r0 = 0x1DE0;
    ST32(sp - 64, r2);
    r4 = LD32(0x1DE0 + r4);
    ST32(sp - 36, r4);
    r1 = LD32((r4 + 76));
    r1 = LD32(r1 + 44);
    ST32(sp - 60, r1);
    r1 = LD32((r4 + 80));
    r1 = LD32(r1 + 44);
    ST32(sp - 56, r1);
    r1 = LD32((r4 + 84));
    r1 = LD32(r1 + 44);
    r12 = 0;
    ST32(sp - 52, r1);
    ST32(sp - 44, r6);
    if (r6 > 0) {
        do {
            r14 = LD32(sp - 68);
            r10 = LD32(sp - 60);
            r9 = LD32(sp - 56);
            r8 = LD32(sp - 52);
            r11 = LD32(sp - 64);
            ST32(sp - 36, 0);
            r2 = LD32(sp - 64);
            r11 = r11 - 1;
            if (!((r2 & r2) == 0)) {
                do {
                    r4 = LD8(r10);
                    r10 = r10 + 1;
                    r5 = LD8(r9);
                    r9 = r9 + 1;
                    r6 = LD8(r8);
                    r8 = r8 + 1;
                    r7 = LD32(sp - 36);
                    r0 = GCALL8(0x0603AF04, (r4 & 255), ((r5 & 255) - 128), ((r6 & 255) - 128), (r7 + r12), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                    ST8(r14, r0);
                    r13 = LD32(sp - 36);
                    r14 = r14 + 1;
                    ST32(sp - 36, ((-r13) + 1));
                    c2 = (r11 & r11) == 0;
                    r11 = r11 - 1;
                } while (AGAIN(!(c2)));
            }
            r12 = r12 + 2;
            r1 = r12;
            if (!(r12 >= 0)) {
                r1 = r1 + 3;
            }
            r3 = LD32(sp - 68);
            r2 = LD32((72 + (sp - 72)));
            r13 = LD32(sp - 72);
            ST32(sp - 68, (r3 + r2));
            r3 = LD32(sp - 60);
            r12 = r12 - (r1 & -4);
            r2 = LD32(sp - 56);
            ST32(sp - 60, (r3 + r13));
            r3 = LD32(sp - 52);
            ST32(sp - 56, (r2 + r13));
            r3 = r3 + r13;
            r13 = LD32(sp - 44);
            ST32(sp - 52, r3);
            r13 = r13 - 1;
            ST32(sp - 44, r13);
        } while (AGAIN(r13 > 0));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603B1DC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 112);

    ST32(sp - 112, r5);
    ST32(sp - 108, r7);
    ST32(sp - 100, ((r5 + 1) >> 1));
    r0 = 0x1DE0;
    r2 = LD32(sp - 100);
    ST32(sp - 96, r2);
    r4 = LD32(0x1DE0 + r4);
    ST32((68 + (sp - 112)), r4);
    r1 = LD32((68 + (sp - 112)));
    r2 = LD32(sp - 112);
    r1 = LD32((r1 + 76));
    r10 = LD32(r1 + 44);
    ST32(sp - 80, (r2 + r10));
    r1 = LD32((68 + (sp - 112)));
    r1 = LD32((r1 + 80));
    r11 = 68 + (sp - 112);
    r1 = LD32(r1 + 44);
    ST32(sp - 76, r1);
    r2 = LD32(r11);
    ST32(r11, (r2 + 84));
    r11 = LD32((68 + (sp - 112)));
    r1 = LD32(r11);
    r1 = LD32(r1 + 44);
    ST32(sp - 72, r1);
    ST32(sp - 104, r6);
    if (r6 > 0) {
        while (1) {
            r2 = LD32(sp - 108);
            r14 = LD32(sp - 72);
            ST32(sp - 68, r2);
            r3 = LD32((112 + (sp - 112)));
            r13 = LD32(sp - 96);
            r2 = r2 + r3;
            ST32(sp - 64, r2);
            r11 = LD32((112 + (sp - 112)));
            r13 = r13 - 1;
            r3 = LD32(sp - 76);
            ST32(sp - 108, (r2 + r11));
            ST32(sp - 92, r10);
            r2 = LD32(sp - 80);
            ST32(sp - 84, r3);
            r11 = LD32(sp - 96);
            ST32(sp - 88, r2);
            if (!((r11 & r11) == 0)) {
                r2 = LD32(sp - 80);
                ST32(sp - 60, (r2 + 1));
                r3 = LD32(sp - 64);
                ST32(sp - 56, (r10 + 1));
                r2 = LD32(sp - 68);
                ST32(sp - 52, (r3 + 1));
                ST32((64 + (sp - 112)), (r2 + 1));
                do {
                    r3 = LD32(sp - 92);
                    r11 = LD32(sp - 56);
                    r2 = LD32(sp - 88);
                    r4 = LD8(r3);
                    r10 = LD8(r11);
                    r3 = LD8(r2);
                    ST8((79 + (sp - 112)), r3);
                    r11 = LD8((79 + (sp - 112)));
                    ST32((72 + (sp - 112)), (r11 & 255));
                    r2 = LD32(sp - 60);
                    r3 = LD32(sp - 84);
                    r12 = LD8(r2);
                    r3 = r3 + 1;
                    ST32(sp - 84, r3);
                    r9 = LD8((r3 - 1));
                    r8 = LD8(r14);
                    r14 = r14 + 1;
                    r9 = (r9 & 255) - 128;
                    r8 = (r8 & 255) - 128;
                    r0 = GCALL8(0x0603AF04, (r4 & 255), r9, r8, 0, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                    r2 = LD32(sp - 68);
                    ST8(r2, r0);
                    r0 = GCALL8(0x0603AF04, (r10 & 255), r9, r8, 1, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                    r11 = LD32((64 + (sp - 112)));
                    ST8(r11, r0);
                    r4 = LD32((72 + (sp - 112)));
                    r0 = GCALL8(0x0603AF04, r4, r9, r8, 2, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                    r11 = LD32(sp - 64);
                    ST8(r11, r0);
                    r0 = GCALL8(0x0603AF04, (r12 & 255), r9, r8, 3, LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)));
                    r11 = 64 + (sp - 112);
                    r3 = LD32(sp - 52);
                    r1 = r13;
                    ST8(r3, r0);
                    r2 = LD32(r11);
                    r13 = r13 - 1;
                    ST32(r11, (r2 + 2));
                    r3 = LD32(sp - 68);
                    r11 = LD32(sp - 52);
                    r2 = LD32(sp - 64);
                    ST32(sp - 68, (r3 + 2));
                    ST32(sp - 52, (r11 + 2));
                    r3 = LD32(sp - 56);
                    r11 = LD32(sp - 92);
                    ST32(sp - 64, (r2 + 2));
                    r2 = LD32(sp - 60);
                    ST32(sp - 56, (r3 + 2));
                    ST32(sp - 92, (r11 + 2));
                    r3 = LD32(sp - 88);
                    ST32(sp - 60, (r2 + 2));
                    ST32(sp - 88, (r3 + 2));
                } while (AGAIN(!((r1 & r1) == 0)));
            }
            r10 = LD32(sp - 80);
            r11 = LD32(sp - 112);
            r2 = LD32(sp - 76);
            r3 = LD32(sp - 100);
            r10 = r10 + r11;
            ST32(sp - 80, (r11 + r10));
            r11 = LD32(sp - 72);
            ST32(sp - 76, (r2 + r3));
            r2 = LD32(sp - 104);
            ST32(sp - 72, (r11 + r3));
            r2 = r2 - 1;
            ST32(sp - 104, r2);
            if (!(r2 > 0)) {
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603B41C(int r4)
{
    int r0, r1, r2, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, c13, c15;
    FRAME(sp, 560);

    r8 = r4;
    ST32(0x204 + (sp - 560), (r8 + 41));
    ST32(0x208 + (sp - 560), (r8 + 96));
    while (1) {
        r1 = LD32(r8 + 60);
        if (!(r1 >= 0)) {
            r7 = LD32(r8 + 56);
            r1 = LD32(0x1DE0 + r8);
            r4 = r7;
            r6 = LD32((r1 + 68));
            r0 = GCALL2(0x0607286C, r4, r6);
            if (((r7 - (r0 * r6)) & (r7 - (r0 * r6))) == 0) {
                r0 = GCALL1(0x0603970C, r4);
                if (r0 == 220) {
                    r0 = GCALL1(0x06039F2C, r8);
                }
            }
        }
        r2 = LD32(r8 + 60);
        if (!(r2 >= 0)) {
            r0 = LD32((0x204 + (sp - 560)));
            r1 = LD8(r0);
            r2 = r8;
            if (!((r1 & r1) == 0)) {
                ST32((r2 + 100), 1);
            }
            r6 = LD32(r8 + 56);
            if (!((r6 & r6) == 0)) {
                r0 = LD32((0x204 + (sp - 560)));
                r7 = LD8(r0);
                if (!((r7 & r7) == 0)) {
                    r0 = GCALL2(0x0607286C, r6, r7);
                    r5 = r0;
                    r6 = r6 - (r5 * r7);
                    if ((r6 & r6) == 0) {
                        r0 = LD32((0x208 + (sp - 560)));
                        r1 = LD32(r0);
                        if ((r1 & r1) == 0) {
                            r0 = GCALL4(0x0603A0B4, r8, r5, r6, r7);
                        }
                        r0 = LD32((0x208 + (sp - 560)));
                        r1 = LD32(r0);
                        if (!((r1 & r1) == 0)) {
                            r4 = LD32(r8 + 56);
                            r0 = LD32((0x204 + (sp - 560)));
                            r5 = LD8(r0);
                            r0 = GCALL2(0x0607286C, r4, r5);
                            r1 = LD32((r8 + 108));
                            c13 = (7 & r0) == ((r1 + 1) & 7);
                            r1 = 0;
                            if (c13) {
                                r13 = LD32(0x208 + (sp - 560));
                                ST32(r13, r1);
                            }
                        }
                        r0 = GCALL1(0x06039178, r8);
                    }
                }
            }
            r1 = LD32(0x1DE0 + r8);
            r1 = LD32(r1);
            r12 = 0;
            if (!(0 >= r1)) {
                ST32((0x20C + (sp - 560)), (0x100 + (sp - 560)));
                while (1) {
                    r0 = GCALL2(0x060391A4, r8, r12);
                    r0 = GCALL2(0x0603AB10, r8, r12);
                    r2 = LD32(0x1DE0 + r8);
                    r1 = LD32(r2);
                    c15 = r1 == 1;
                    r1 = r12;
                    if (!(c15)) {
                        r1 = LD32((r2 + (r1 << 2)) + 140);
                        r0 = (r1 << 2) + r8;
                        r14 = LD32(r0 + 0x9DC);
                        r2 = LD32(r0 + 0xDDC);
                        ST32((0x200 + (sp - 560)), r2);
                    } else {
                        ST32((0x200 + (sp - 560)), 1);
                        r14 = 1;
                    }
                    r0 = LD32(0x200 + (sp - 560));
                    r11 = 0;
                    if (!(0 >= r0)) {
                        r10 = r12 << 2;
                        do {
                            r9 = 0;
                            if (!(0 >= r14)) {
                                do {
                                    r0 = LD32((0x208 + (sp - 560)));
                                    r1 = LD32(r0);
                                    r2 = r10;
                                    if ((r1 & r1) == 0) {
                                        r1 = LD32(0x1DE0 + r8);
                                        r5 = LD32((r2 + r1) + 0x10C);
                                        r0 = GCALL2(0x060390CC, r8, r5);
                                        ST32(sp - 560, r0);
                                        r1 = LD32(0x1DE0 + r8);
                                        r6 = LD32((r10 + r1) + 204);
                                        r0 = GCALL5(0x06038FF0, r8, (sp - 560), r6, 0, LD32((sp - 560)));
                                        r5 = LD32((0x20C + (sp - 560)));
                                        r0 = GCALL5(0x0603C004, (sp - 560), r5, 0, 0, LD32((sp - 560)));
                                        r1 = LD32(0x1DE0 + r8);
                                        r1 = LD32((r10 + r1) + 140);
                                        r1 = LD32(((r1 << 2) + r8) + 0x11DC);
                                        r5 = LD32(((r1 << 2) + r8) + 132);
                                        r4 = LD32((0x20C + (sp - 560)));
                                        r0 = GCALL5(0x0603BFAC, r4, r5, 0, 0, LD32((sp - 560)));
                                        r4 = LD32((0x20C + (sp - 560)));
                                        r0 = GCALL5(0x0603BC80, r4, (sp - 560), 0, 0, LD32((sp - 560)));
                                        r0 = GCALL5(0x0603BFD8, (sp - 560), 128, 255, 0, LD32((sp - 560)));
                                    } else {
                                        r0 = GCALL1(0x0603C02C, (sp - 560));
                                    }
                                    r0 = GCALL5(0x0603A890, r8, (sp - 560), 0, 0, LD32((sp - 560)));
                                    r9 = r9 + 1;
                                } while (AGAIN(!(r9 >= r14)));
                            }
                            r0 = LD32(0x200 + (sp - 560));
                            r11 = r11 + 1;
                        } while (AGAIN(!(r11 >= r0)));
                    }
                    r1 = LD32(0x1DE0 + r8);
                    r1 = LD32(r1);
                    r12 = r12 + 1;
                    if (r12 >= r1) {
                        break;
                    }
                    POLL();
                }
            }
            r1 = LD32(r8 + 56);
            ST32(r8 + 56, (r1 + 1));
            POLL();
            continue;
        } else {
            r1 = LD32(r8 + 56);
            r0 = 0;
            if (!(r1 >= r2)) {
                r0 = LD32((0x204 + (sp - 560)));
                r1 = LD8(r0);
                r2 = r8;
                if (!((r1 & r1) == 0)) {
                    ST32((r2 + 100), 1);
                }
                r6 = LD32(r8 + 56);
                if (!((r6 & r6) == 0)) {
                    r0 = LD32((0x204 + (sp - 560)));
                    r7 = LD8(r0);
                    if (!((r7 & r7) == 0)) {
                        r0 = GCALL2(0x0607286C, r6, r7);
                        r5 = r0;
                        r6 = r6 - (r5 * r7);
                        if ((r6 & r6) == 0) {
                            r0 = LD32((0x208 + (sp - 560)));
                            r1 = LD32(r0);
                            if ((r1 & r1) == 0) {
                                r0 = GCALL4(0x0603A0B4, r8, r5, r6, r7);
                            }
                            r0 = LD32((0x208 + (sp - 560)));
                            r1 = LD32(r0);
                            if (!((r1 & r1) == 0)) {
                                r4 = LD32(r8 + 56);
                                r0 = LD32((0x204 + (sp - 560)));
                                r5 = LD8(r0);
                                r0 = GCALL2(0x0607286C, r4, r5);
                                r1 = LD32((r8 + 108));
                                c13 = (7 & r0) == ((r1 + 1) & 7);
                                r1 = 0;
                                if (c13) {
                                    r13 = LD32(0x208 + (sp - 560));
                                    ST32(r13, r1);
                                }
                            }
                            r0 = GCALL1(0x06039178, r8);
                        }
                    }
                }
                r1 = LD32(0x1DE0 + r8);
                r1 = LD32(r1);
                r12 = 0;
                if (!(0 >= r1)) {
                    ST32((0x20C + (sp - 560)), (0x100 + (sp - 560)));
                    while (1) {
                        r0 = GCALL2(0x060391A4, r8, r12);
                        r0 = GCALL2(0x0603AB10, r8, r12);
                        r2 = LD32(0x1DE0 + r8);
                        r1 = LD32(r2);
                        c15 = r1 == 1;
                        r1 = r12;
                        if (!(c15)) {
                            r1 = LD32((r2 + (r1 << 2)) + 140);
                            r0 = (r1 << 2) + r8;
                            r14 = LD32(r0 + 0x9DC);
                            r2 = LD32(r0 + 0xDDC);
                            ST32((0x200 + (sp - 560)), r2);
                        } else {
                            ST32((0x200 + (sp - 560)), 1);
                            r14 = 1;
                        }
                        r0 = LD32(0x200 + (sp - 560));
                        r11 = 0;
                        if (!(0 >= r0)) {
                            r10 = r12 << 2;
                            do {
                                r9 = 0;
                                if (!(0 >= r14)) {
                                    do {
                                        r0 = LD32((0x208 + (sp - 560)));
                                        r1 = LD32(r0);
                                        r2 = r10;
                                        if ((r1 & r1) == 0) {
                                            r1 = LD32(0x1DE0 + r8);
                                            r5 = LD32((r2 + r1) + 0x10C);
                                            r0 = GCALL2(0x060390CC, r8, r5);
                                            ST32(sp - 560, r0);
                                            r1 = LD32(0x1DE0 + r8);
                                            r6 = LD32((r10 + r1) + 204);
                                            r0 = GCALL5(0x06038FF0, r8, (sp - 560), r6, 0, LD32((sp - 560)));
                                            r5 = LD32((0x20C + (sp - 560)));
                                            r0 = GCALL5(0x0603C004, (sp - 560), r5, 0, 0, LD32((sp - 560)));
                                            r1 = LD32(0x1DE0 + r8);
                                            r1 = LD32((r10 + r1) + 140);
                                            r1 = LD32(((r1 << 2) + r8) + 0x11DC);
                                            r5 = LD32(((r1 << 2) + r8) + 132);
                                            r4 = LD32((0x20C + (sp - 560)));
                                            r0 = GCALL5(0x0603BFAC, r4, r5, 0, 0, LD32((sp - 560)));
                                            r4 = LD32((0x20C + (sp - 560)));
                                            r0 = GCALL5(0x0603BC80, r4, (sp - 560), 0, 0, LD32((sp - 560)));
                                            r0 = GCALL5(0x0603BFD8, (sp - 560), 128, 255, 0, LD32((sp - 560)));
                                        } else {
                                            r0 = GCALL1(0x0603C02C, (sp - 560));
                                        }
                                        r0 = GCALL5(0x0603A890, r8, (sp - 560), 0, 0, LD32((sp - 560)));
                                        r9 = r9 + 1;
                                    } while (AGAIN(!(r9 >= r14)));
                                }
                                r0 = LD32(0x200 + (sp - 560));
                                r11 = r11 + 1;
                            } while (AGAIN(!(r11 >= r0)));
                        }
                        r1 = LD32(0x1DE0 + r8);
                        r1 = LD32(r1);
                        r12 = r12 + 1;
                        if (r12 >= r1) {
                            break;
                        }
                        POLL();
                    }
                }
                r1 = LD32(r8 + 56);
                ST32(r8 + 56, (r1 + 1));
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
int f06030034(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10;

    r1 = LD32(r4);
    r9 = r5;
    if (!((r1 & r1) == 0)) {
        r8 = 0;
        r2 = 255;
        r0 = r9;
        do {
            ST8(r0 + r8, r8);
            r8 = (r8 + 1) & 0xFFFF;
        } while (AGAIN(!((unsigned)r8 > (unsigned)r2)));
    } else {
        r0 = LD32(r4 + 32);
        r8 = 0;
        if (!(r0 == 1)) {
            r2 = 255;
            r0 = r9;
            do {
                ST8(r0 + r8, r8);
                r8 = (r8 + 1) & 0xFFFF;
            } while (AGAIN(!((unsigned)r8 > (unsigned)r2)));
        } else {
            r10 = 0x060412F4;
            do {
                r0 = GCALL1(r10, (r8 & 255));
                r4 = (short)r0;
                r0 = r9;
                r4 = HELPER((int)r4 >> 8);
                ST8(r0 + r8, r4);
                r8 = (r8 + 1) & 0xFFFF;
            } while (AGAIN(!((unsigned)r8 > (unsigned)255)));
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030E28(int r4, int r5, int r6)
{
    int r0, r1, r2, r7, r8, r9, r10, r11, r12, r13, r14, c1, c2, c5, c10;
    FRAME(sp, 88);

    r4 = (short)r4;
    ST32(sp - 52, ((short)r5));
    r11 = (short)r6;
    if (!(r4 >= 0)) {
        r0 = -413;
    } else {
        r1 = LD16(0x06087F84);
        c1 = r4 >= r1;
        r1 = 92;
        if (!(c1)) {
            c2 = (short)r4 * (short)r1;
            r1 = LD32(0x06087F80);
            r9 = r1 + c2;
            r0 = LD32(r9 + 4);
            r1 = r9;
            if (!(r0 == 3)) {
                r0 = LD16((r1 + 84));
                c5 = (r0 & r0) == 0;
                if (r0 == 16) {
                    r0 = GCALL0(0x06030DD8);
                    r8 = (short)r0;
                    r7 = r8;
                    if (!(r8 >= 0)) {
                        r0 = -400;
                    } else {
                        ST32((sp - 76), r11);
                        r13 = LD32(sp - 52);
                        ST32((sp - 80), r13);
                        ST32((sp - 84), 0);
                        r0 = LD16((r9 + 8));
                        ST32((sp - 88), (r0 == 2));
                        r0 = GCALL8(0x060305F8, r9, (sp - 72), (sp - 64), ((short)(r7 + 4)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)));
                        r1 = LD16((r9 + 62));
                        r4 = HELPER((int)((r1 & 0xFFFF) + 0xFFF) >> 12);
                        r5 = LD16((r9 + 20));
                        r0 = GCALL2(0x0607286C, r4, (r5 & 0xFFFF));
                        ST16((((short)r8 * (short)12) + 0x06087F4C), (r0 - 1));
                        r0 = 0;
                    }
                } else {
                    if (!(c5)) {
                        if (r0 == 144) {
                            r10 = 0x06030DD8;
                            r0 = GCALL0(0x06030DD8);
                            r8 = (short)r0;
                            if (!(r8 >= 0)) {
                                r0 = -400;
                            } else {
                                r0 = GCALL1(r10, r4);
                                r12 = (short)r0;
                                r2 = 12;
                                if (r12 >= 0) {
                                    r6 = -15;
                                    if (r11 >= 0) {
                                        r6 = (short)((r11 + r11) - 15);
                                        ST32(sp - 44, 15);
                                    } else {
                                        ST32(sp - 44, ((short)((r11 + r11) + 15)));
                                    }
                                    r14 = r9 + 62;
                                    r1 = LD16(r14);
                                    r4 = HELPER((int)((r1 & 0xFFFF) + 0xFFF) >> 12);
                                    r13 = r9 + 20;
                                    ST32(sp - 36, r13);
                                    r5 = LD16(r13);
                                    r0 = GCALL2(0x0607286C, r4, (r5 & 0xFFFF));
                                    ST16(((((short)r8 * (short)12) + 0x06087F48) + 4), (r0 - 1));
                                    ST32(sp - 40, (sp - 64));
                                    ST32((sp - 76), r6);
                                    r13 = LD32(sp - 52);
                                    ST32((sp - 80), r13);
                                    ST32((sp - 84), 0);
                                    ST32((sp - 88), 0);
                                    r6 = LD32(sp - 40);
                                    r0 = GCALL8(0x060305F8, r9, (sp - 72), r6, ((short)(r8 + 4)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)));
                                    r8 = r9 + 68;
                                    r13 = LD32(r8);
                                    ST32(sp - 48, r13);
                                    r1 = LD32((r9 + 72));
                                    ST32(r8, r1);
                                    r1 = LD16(r14);
                                    r4 = HELPER((int)((r1 & 0xFFFF) + 0xFFF) >> 12);
                                    r13 = LD32(sp - 36);
                                    r5 = LD16(r13);
                                    r0 = GCALL8(0x0607286C, r4, (r5 & 0xFFFF), 0, 0, LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)));
                                    ST16(((((short)r12 * (short)12) + 0x06087F48) + 4), (r0 - 1));
                                    r13 = LD32(sp - 44);
                                    ST32((sp - 92), r13);
                                    r13 = LD32(sp - 52);
                                    ST32((sp - 96), r13);
                                    ST32((sp - 100), 0);
                                    ST32((sp - 104), 0);
                                    r6 = LD32((64 + (sp - 104)));
                                    r0 = GCALL8(0x060305F8, r9, (sp - 72), r6, ((short)(r12 + 4)), LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)), LD32((sp - 92)));
                                    r13 = LD32(sp - 48);
                                    ST32(r8, r13);
                                    r0 = 0;
                                } else {
                                    ST32(((short)r8 * (short)r2) + 0x06087F48, 1);
                                    r0 = -400;
                                }
                            }
                        } else {
                            c10 = r0 == 128;
                            r0 = 0;
                            if (c10) {
                                r10 = 0x06030DD8;
                                r0 = GCALL0(0x06030DD8);
                                r8 = (short)r0;
                                if (!(r8 >= 0)) {
                                    r0 = -400;
                                } else {
                                    r0 = GCALL1(r10, r4);
                                    r12 = (short)r0;
                                    r2 = 12;
                                    if (r12 >= 0) {
                                        r6 = -15;
                                        if (r11 >= 0) {
                                            r6 = (short)((r11 + r11) - 15);
                                            ST32(sp - 44, 15);
                                        } else {
                                            ST32(sp - 44, ((short)((r11 + r11) + 15)));
                                        }
                                        r14 = r9 + 62;
                                        r1 = LD16(r14);
                                        r4 = HELPER((int)((r1 & 0xFFFF) + 0xFFF) >> 12);
                                        r13 = r9 + 20;
                                        ST32(sp - 36, r13);
                                        r5 = LD16(r13);
                                        r0 = GCALL2(0x0607286C, r4, (r5 & 0xFFFF));
                                        ST16(((((short)r8 * (short)12) + 0x06087F48) + 4), (r0 - 1));
                                        ST32(sp - 40, (sp - 64));
                                        ST32((sp - 76), r6);
                                        r13 = LD32(sp - 52);
                                        ST32((sp - 80), r13);
                                        ST32((sp - 84), 0);
                                        ST32((sp - 88), 0);
                                        r6 = LD32(sp - 40);
                                        r0 = GCALL8(0x060305F8, r9, (sp - 72), r6, ((short)(r8 + 4)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)));
                                        r8 = r9 + 68;
                                        r13 = LD32(r8);
                                        ST32(sp - 48, r13);
                                        r1 = LD32((r9 + 72));
                                        ST32(r8, r1);
                                        r1 = LD16(r14);
                                        r4 = HELPER((int)((r1 & 0xFFFF) + 0xFFF) >> 12);
                                        r13 = LD32(sp - 36);
                                        r5 = LD16(r13);
                                        r0 = GCALL8(0x0607286C, r4, (r5 & 0xFFFF), 0, 0, LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)));
                                        ST16(((((short)r12 * (short)12) + 0x06087F48) + 4), (r0 - 1));
                                        r13 = LD32(sp - 44);
                                        ST32((sp - 92), r13);
                                        r13 = LD32(sp - 52);
                                        ST32((sp - 96), r13);
                                        ST32((sp - 100), 0);
                                        ST32((sp - 104), 0);
                                        r6 = LD32((64 + (sp - 104)));
                                        r0 = GCALL8(0x060305F8, r9, (sp - 72), r6, ((short)(r12 + 4)), LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)), LD32((sp - 92)));
                                        r13 = LD32(sp - 48);
                                        ST32(r8, r13);
                                        r0 = 0;
                                    } else {
                                        ST32(((short)r8 * (short)r2) + 0x06087F48, 1);
                                        r0 = -400;
                                    }
                                }
                            }
                        }
                    } else {
                        r0 = GCALL0(0x06030DD8);
                        r8 = (short)r0;
                        r7 = r8;
                        if (!(r8 >= 0)) {
                            r0 = -400;
                        } else {
                            ST32((sp - 76), r11);
                            r13 = LD32(sp - 52);
                            ST32((sp - 80), r13);
                            ST32((sp - 84), 0);
                            r0 = LD16((r9 + 8));
                            ST32((sp - 88), (r0 == 2));
                            r0 = GCALL8(0x060305F8, r9, (sp - 72), (sp - 64), ((short)(r7 + 4)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)));
                            r1 = LD16((r9 + 62));
                            r4 = HELPER((int)((r1 & 0xFFFF) + 0xFFF) >> 12);
                            r5 = LD16((r9 + 20));
                            r0 = GCALL2(0x0607286C, r4, (r5 & 0xFFFF));
                            ST16((((short)r8 * (short)12) + 0x06087F4C), (r0 - 1));
                            r0 = 0;
                        }
                    }
                }
            } else {
                r0 = 0;
            }
        } else {
            r0 = -413;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06035454(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14, c0, c2, c3, c1006;
    FRAME(sp, 84);

    r13 = r4;
    r12 = r5;
    r8 = 136;
    r0 = LD32(r13 + 136);
    ST32(sp - 44, r0);
    r0 = GCALL3(0x060350C4, r4, (sp - 64), (sp - 60));
    ST32(sp - 48, r0);
    r0 = LD32(r12 + 52);
    ST32(sp - 40, r0);
    r0 = GCALL2(0x06035068, r13, (sp - 68));
    r0 = GCALL4(0x0603510C, r13, r12, (sp - 56), (sp - 52));
    r0 = GCALL1(0x06034CEC, r13);
    c0 = (r0 & r0) == 0;
    r0 = r13;
    if (!(c0)) {
        r1 = LD32(r0 + r8);
        r5 = 28;
        if ((r1 & r1) == 0) {
            ST32(136 + r13, 0);
            r1 = LD32(140 + r13);
            r8 = r12;
            if ((r1 & r1) == 0) {
                r8 = r8 + 14;
                r7 = LD16(r8);
                r5 = LD16((r12 + 12));
                r6 = LD32(r12 + 16);
                ST32((sp - 72), -1);
                r1 = LD32(r12 + 20);
                ST32((sp - 76), r1);
                r0 = GCALL6(0x06015154, r13, r5, r6, r7, LD32((sp - 76)), LD32((sp - 72)));
                r2 = LD16((r12 + 64));
                if (!(r2 > 1)) {
                    r1 = LD32(sp - 64);
                    r2 = LD16(r8);
                    r1 = r1 << 2;
                } else {
                    r1 = LD32(sp - 64);
                    r2 = LD16(r8);
                    r1 = r1 + r1;
                }
                r14 = r2 - r1;
                r3 = r12 + 12;
                ST32(sp - 36, r3);
                r1 = LD16(r3);
                ST16((r12 + 36), (r14 - r1));
                r1 = LD32(sp - 60);
                ST16((r12 + 38), r1);
                r5 = LD16(r3);
                r6 = LD32(r12 + 16);
                ST32((sp - 72), 1);
                ST32((sp - 76), 2);
                ST32((sp - 80), -1);
                r1 = LD32(r12 + 20);
                ST32((sp - 84), r1);
                r0 = GCALL8(0x060153C8, r13, r5, r6, r14, LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
                r1 = LD16((r12 + 64));
                if (!(r1 > 1)) {
                    r11 = r14;
                    r1 = LD32(sp - 64);
                    r3 = LD32(sp - 36);
                    r14 = r14 + (r1 + r1);
                    r1 = LD16(r3);
                    ST16((r12 + 32), (r11 - r1));
                    r6 = LD32(r12 + 16);
                    ST32((sp - 72), -110);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 76), r1);
                    r0 = GCALL6(0x06015154, r13, r11, r6, r14, LD32((sp - 76)), LD32((sp - 72)));
                    r6 = LD32(r12 + 16);
                    ST32((sp - 80), 0);
                    ST32((sp - 84), 2);
                    ST32((sp - 88), -1);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 92), r1);
                    r0 = GCALL8(0x060153C8, r13, r11, r6, r14, LD32((sp - 92)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)));
                    r7 = LD32(r12 + 16);
                    ST32((sp - 96), 0);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 100), r1);
                    ST32((sp - 104), r14);
                    r0 = GCALL8(0x06035264, r13, 1, r11, r7, LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)), LD32((sp - 92)));
                    r11 = r14;
                    r1 = LD32(sp - 64);
                    r0 = LD32((68 + (sp - 104)));
                    r14 = r14 + (r1 + r1);
                    r1 = LD16(r0);
                    ST16((r12 + 34), (r11 - r1));
                    r6 = LD32(r12 + 16);
                    ST32((sp - 72), -110);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 76), r1);
                    r0 = GCALL6(0x06015154, r13, r11, r6, r14, LD32((sp - 76)), LD32((sp - 72)));
                    r6 = LD32(r12 + 16);
                    ST32((sp - 80), 0);
                    ST32((sp - 84), 2);
                    ST32((sp - 88), -1);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 92), r1);
                    r0 = GCALL8(0x060153C8, r13, r11, r6, r14, LD32((sp - 92)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)));
                    r7 = LD32(r12 + 16);
                    ST32((sp - 96), 0);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 100), r1);
                    ST32((sp - 104), r14);
                    r0 = GCALL8(0x06035264, r13, 0, r11, r7, LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)), LD32((sp - 92)));
                } else {
                    r11 = r14;
                    r10 = r12 + 14;
                    r14 = LD32(r12 + 16);
                    r1 = LD32(sp - 60);
                    r8 = r14 + r1;
                    ST16((r12 + 32), r1);
                    r7 = LD16(r10);
                    ST32((sp - 72), -110);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 76), r1);
                    r0 = GCALL6(0x06015154, r13, r11, r14, r7, LD32((sp - 76)), LD32((sp - 72)));
                    r7 = LD16(r10);
                    ST32((sp - 80), 0);
                    ST32((sp - 84), 2);
                    ST32((sp - 88), -1);
                    r1 = LD32(r12 + 20);
                    r2 = LD32(sp - 60);
                    ST32((sp - 92), ((r1 - r2) - 1));
                    r0 = GCALL8(0x060153C8, r13, r11, (r8 + 1), r7, LD32((sp - 92)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)));
                    r7 = LD16(r10);
                    ST32((sp - 96), 0);
                    ST32((sp - 100), 2);
                    ST32((sp - 104), -1);
                    ST32((sp - 108), r8);
                    r0 = GCALL8(0x060153C8, r13, r11, r14, r7, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)));
                    ST32((sp - 72), 0);
                    ST32((sp - 76), r8);
                    r1 = LD16(r10);
                    ST32((sp - 80), r1);
                    r0 = GCALL7(0x06035264, r13, 0, r11, r14, LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
                    r8 = LD32(r12 + 20);
                    r1 = LD32(sp - 60);
                    r14 = r8 - r1;
                    r1 = LD32(r12 + 16);
                    ST16((r12 + 34), (r14 - r1));
                    r7 = LD16(r10);
                    ST32((sp - 84), 0);
                    ST32((sp - 88), 2);
                    ST32((sp - 92), -1);
                    ST32((sp - 96), r8);
                    r0 = GCALL8(0x060153C8, r13, r11, r14, r7, LD32((sp - 96)), LD32((sp - 92)), LD32((sp - 88)), LD32((sp - 84)));
                    ST32((sp - 100), 0);
                    ST32((sp - 104), r8);
                    r1 = LD16(r10);
                    ST32((sp - 108), r1);
                    r0 = GCALL8(0x06035264, r13, 1, r11, r14, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)));
                }
            }
            r1 = LD32(r12 + 16);
            r10 = 0;
            r0 = LD32(sp - 40);
            r14 = r1 + 2;
            r2 = LD16((r12 + 12));
            r1 = LD32(sp - 64);
            r11 = r2 + r1;
            if (!((r0 & r0) == 0)) {
                while (1) {
                    r1 = LD16((r12 + 64));
                    r3 = LD32(sp - 40);
                    if (r10 >= r1) {
                        break;
                    } else {
                        r2 = LD32(0x10B8 + r13);
                        r9 = LD32(r3 + 16);
                        r2 = r2 + 2;
                        r7 = LD8(r2);
                        r4 = HELPER((int)((signed char)r7) >> 7);
                        r8 = (signed char)r4;
                        r1 = LD32(r3);
                        ST8(r2, (((((r1 << 2) << 2) + ((r1 << 2) << 2)) << 2) | (r7 & 127)));
                        r0 = GCALL1(0x0607507C, r9);
                        r3 = LD32(sp - 48);
                        r1 = LD32(r3);
                        ST32((sp - 72), r1);
                        r1 = LD32(0x10B8 + r13);
                        ST32((sp - 76), r1);
                        r3 = LD32(sp - 48);
                        r1 = LD32(r3 + 32);
                        ST32((sp - 80), r1);
                        ST32((sp - 84), r14);
                        ST32((sp - 88), r11);
                        r0 = GCALL8(0x06014880, r13, r9, 0, (r0 - 1), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)));
                        r2 = LD32(0x10B8 + r13);
                        r2 = r2 + 2;
                        r1 = LD8(r2);
                        ST8(r2, ((r1 & 127) | ((((r8 << 2) << 2) + ((r8 << 2) << 2)) << 2)));
                        r1 = LD32(sp - 60);
                        r0 = LD32(sp - 40);
                        r10 = r10 + 1;
                        r0 = LD32(r0 + 24);
                        ST32(sp - 40, r0);
                        r3 = LD32(sp - 40);
                        r14 = r14 + r1;
                        if (!((r3 & r3) == 0)) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
            }
            r3 = LD32(sp - 44);
            ST32(r13 + 136, r3);
            r0 = GCALL2(0x060350B0, r13, (sp - 68));
            r0 = LD32(sp - 56);
        } else {
            r0 = GCALL2(0x06015D00, r13, r5);
            c2 = (r0 & r0) == 0;
            r0 = r13;
            if (c2) {
                r0 = -1;
            } else {
                r6 = 152;
                r2 = LD32(r0 + 152);
                ST32(r2, 13);
                ST32(r2 + 4, 0);
                ST32(r2 + 24, r12);
                r1 = LD32(r12 + 16);
                ST32(r2 + 12, r1);
                r1 = LD32(r12 + 20);
                r7 = 148;
                ST32(r2 + 16, r1);
                r1 = LD32(r0 + 148);
                c3 = (r1 & r1) == 0;
                c1006 = c3;
                if (!(c3)) {
                    ST32(r1, r2);
                    c1006 = 0;
                }
                r0 = r13;
                ST32(r0 + r7, (r2 + 4));
                r1 = LD32(r0 + r6);
                ST32(r0 + r6, (r1 + 28));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                ST32((r12 + 72), r2);
                ST32(136 + r13, 0);
                r1 = LD32(140 + r13);
                r8 = r12;
                if ((r1 & r1) == 0) {
                    r8 = r8 + 14;
                    r7 = LD16(r8);
                    r5 = LD16((r12 + 12));
                    r6 = LD32(r12 + 16);
                    ST32((sp - 72), -1);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 76), r1);
                    r0 = GCALL6(0x06015154, r13, r5, r6, r7, LD32((sp - 76)), LD32((sp - 72)));
                    r2 = LD16((r12 + 64));
                    if (!(r2 > 1)) {
                        r1 = LD32(sp - 64);
                        r2 = LD16(r8);
                        r1 = r1 << 2;
                    } else {
                        r1 = LD32(sp - 64);
                        r2 = LD16(r8);
                        r1 = r1 + r1;
                    }
                    r14 = r2 - r1;
                    r3 = r12 + 12;
                    ST32(sp - 36, r3);
                    r1 = LD16(r3);
                    ST16((r12 + 36), (r14 - r1));
                    r1 = LD32(sp - 60);
                    ST16((r12 + 38), r1);
                    r5 = LD16(r3);
                    r6 = LD32(r12 + 16);
                    ST32((sp - 72), 1);
                    ST32((sp - 76), 2);
                    ST32((sp - 80), -1);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 84), r1);
                    r0 = GCALL8(0x060153C8, r13, r5, r6, r14, LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
                    r1 = LD16((r12 + 64));
                    if (!(r1 > 1)) {
                        r11 = r14;
                        r1 = LD32(sp - 64);
                        r3 = LD32(sp - 36);
                        r14 = r14 + (r1 + r1);
                        r1 = LD16(r3);
                        ST16((r12 + 32), (r11 - r1));
                        r6 = LD32(r12 + 16);
                        ST32((sp - 72), -110);
                        r1 = LD32(r12 + 20);
                        ST32((sp - 76), r1);
                        r0 = GCALL6(0x06015154, r13, r11, r6, r14, LD32((sp - 76)), LD32((sp - 72)));
                        r6 = LD32(r12 + 16);
                        ST32((sp - 80), 0);
                        ST32((sp - 84), 2);
                        ST32((sp - 88), -1);
                        r1 = LD32(r12 + 20);
                        ST32((sp - 92), r1);
                        r0 = GCALL8(0x060153C8, r13, r11, r6, r14, LD32((sp - 92)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)));
                        r7 = LD32(r12 + 16);
                        ST32((sp - 96), 0);
                        r1 = LD32(r12 + 20);
                        ST32((sp - 100), r1);
                        ST32((sp - 104), r14);
                        r0 = GCALL8(0x06035264, r13, 1, r11, r7, LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)), LD32((sp - 92)));
                        r11 = r14;
                        r1 = LD32(sp - 64);
                        r0 = LD32((68 + (sp - 104)));
                        r14 = r14 + (r1 + r1);
                        r1 = LD16(r0);
                        ST16((r12 + 34), (r11 - r1));
                        r6 = LD32(r12 + 16);
                        ST32((sp - 72), -110);
                        r1 = LD32(r12 + 20);
                        ST32((sp - 76), r1);
                        r0 = GCALL6(0x06015154, r13, r11, r6, r14, LD32((sp - 76)), LD32((sp - 72)));
                        r6 = LD32(r12 + 16);
                        ST32((sp - 80), 0);
                        ST32((sp - 84), 2);
                        ST32((sp - 88), -1);
                        r1 = LD32(r12 + 20);
                        ST32((sp - 92), r1);
                        r0 = GCALL8(0x060153C8, r13, r11, r6, r14, LD32((sp - 92)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)));
                        r7 = LD32(r12 + 16);
                        ST32((sp - 96), 0);
                        r1 = LD32(r12 + 20);
                        ST32((sp - 100), r1);
                        ST32((sp - 104), r14);
                        r0 = GCALL8(0x06035264, r13, 0, r11, r7, LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)), LD32((sp - 92)));
                    } else {
                        r11 = r14;
                        r10 = r12 + 14;
                        r14 = LD32(r12 + 16);
                        r1 = LD32(sp - 60);
                        r8 = r14 + r1;
                        ST16((r12 + 32), r1);
                        r7 = LD16(r10);
                        ST32((sp - 72), -110);
                        r1 = LD32(r12 + 20);
                        ST32((sp - 76), r1);
                        r0 = GCALL6(0x06015154, r13, r11, r14, r7, LD32((sp - 76)), LD32((sp - 72)));
                        r7 = LD16(r10);
                        ST32((sp - 80), 0);
                        ST32((sp - 84), 2);
                        ST32((sp - 88), -1);
                        r1 = LD32(r12 + 20);
                        r2 = LD32(sp - 60);
                        ST32((sp - 92), ((r1 - r2) - 1));
                        r0 = GCALL8(0x060153C8, r13, r11, (r8 + 1), r7, LD32((sp - 92)), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)));
                        r7 = LD16(r10);
                        ST32((sp - 96), 0);
                        ST32((sp - 100), 2);
                        ST32((sp - 104), -1);
                        ST32((sp - 108), r8);
                        r0 = GCALL8(0x060153C8, r13, r11, r14, r7, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)));
                        ST32((sp - 72), 0);
                        ST32((sp - 76), r8);
                        r1 = LD16(r10);
                        ST32((sp - 80), r1);
                        r0 = GCALL7(0x06035264, r13, 0, r11, r14, LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
                        r8 = LD32(r12 + 20);
                        r1 = LD32(sp - 60);
                        r14 = r8 - r1;
                        r1 = LD32(r12 + 16);
                        ST16((r12 + 34), (r14 - r1));
                        r7 = LD16(r10);
                        ST32((sp - 84), 0);
                        ST32((sp - 88), 2);
                        ST32((sp - 92), -1);
                        ST32((sp - 96), r8);
                        r0 = GCALL8(0x060153C8, r13, r11, r14, r7, LD32((sp - 96)), LD32((sp - 92)), LD32((sp - 88)), LD32((sp - 84)));
                        ST32((sp - 100), 0);
                        ST32((sp - 104), r8);
                        r1 = LD16(r10);
                        ST32((sp - 108), r1);
                        r0 = GCALL8(0x06035264, r13, 1, r11, r14, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)));
                    }
                }
                r1 = LD32(r12 + 16);
                r10 = 0;
                r0 = LD32(sp - 40);
                r14 = r1 + 2;
                r2 = LD16((r12 + 12));
                r1 = LD32(sp - 64);
                r11 = r2 + r1;
                if (!((r0 & r0) == 0)) {
                    while (1) {
                        r1 = LD16((r12 + 64));
                        r3 = LD32(sp - 40);
                        if (r10 >= r1) {
                            break;
                        } else {
                            r2 = LD32(0x10B8 + r13);
                            r9 = LD32(r3 + 16);
                            r2 = r2 + 2;
                            r7 = LD8(r2);
                            r4 = HELPER((int)((signed char)r7) >> 7);
                            r8 = (signed char)r4;
                            r1 = LD32(r3);
                            ST8(r2, (((((r1 << 2) << 2) + ((r1 << 2) << 2)) << 2) | (r7 & 127)));
                            r0 = GCALL1(0x0607507C, r9);
                            r3 = LD32(sp - 48);
                            r1 = LD32(r3);
                            ST32((sp - 72), r1);
                            r1 = LD32(0x10B8 + r13);
                            ST32((sp - 76), r1);
                            r3 = LD32(sp - 48);
                            r1 = LD32(r3 + 32);
                            ST32((sp - 80), r1);
                            ST32((sp - 84), r14);
                            ST32((sp - 88), r11);
                            r0 = GCALL8(0x06014880, r13, r9, 0, (r0 - 1), LD32((sp - 88)), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)));
                            r2 = LD32(0x10B8 + r13);
                            r2 = r2 + 2;
                            r1 = LD8(r2);
                            ST8(r2, ((r1 & 127) | ((((r8 << 2) << 2) + ((r8 << 2) << 2)) << 2)));
                            r1 = LD32(sp - 60);
                            r0 = LD32(sp - 40);
                            r10 = r10 + 1;
                            r0 = LD32(r0 + 24);
                            ST32(sp - 40, r0);
                            r3 = LD32(sp - 40);
                            r14 = r14 + r1;
                            if (!((r3 & r3) == 0)) {
                                POLL();
                                continue;
                            } else {
                                break;
                            }
                        }
                        POLL();
                    }
                }
                r3 = LD32(sp - 44);
                ST32(r13 + 136, r3);
                r0 = GCALL2(0x060350B0, r13, (sp - 68));
                r0 = LD32(sp - 56);
            }
        }
    } else {
        r0 = GCALL2(0x060350B0, r13, (sp - 68));
        r0 = LD32(sp - 56);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060316A0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c4, c11, c2008;
    FRAME(sp, 292);

    r10 = r5;
    ST32(0x100 + (sp - 292), r7);
    r12 = LD32((0x128 + (sp - 292)));
    r13 = LD32((0x12C + (sp - 292)));
    r5 = LD32(0x0603169C);
    r0 = GCALL2(0x06072FC4, r6, r5);
    r8 = LD32(r10 + 8);
    r9 = r0;
    r14 = LD32((0x130 + (sp - 292)));
    if (!(r8 >= 0)) {
        c2008 = R(8);
        SETR(8, r8);
        r0 = GCALL1(0x06073368, ((1 & r8) | ((int)((unsigned)r8 >> 1))));
        SETR(8, c2008);
        r0 = GCALL2(0x06072CD4, r0, r0);
        r2 = r0;
    } else {
        c2008 = R(8);
        SETR(8, r8);
        r0 = GCALL1(0x06073368, r8);
        SETR(8, c2008);
        r2 = r0;
    }
    r0 = GCALL2(0x06072EA8, r9, r2);
    r0 = GCALL1(0x060733D8, r0);
    r1 = LD16((r10 + 12));
    r4 = LD32((0x100 + (sp - 292)));
    r5 = LD32(0x0603169C);
    r8 = r0 * r1;
    r0 = GCALL2(0x06072FC4, r4, r5);
    ST32((0x100 + (sp - 292)), r0);
    r9 = LD32(r10 + 8);
    if (!(r9 >= 0)) {
        c2008 = R(8);
        SETR(8, r8);
        r0 = GCALL1(0x06073368, ((1 & r9) | ((int)((unsigned)r9 >> 1))));
        SETR(8, c2008);
        r0 = GCALL2(0x06072CD4, r0, r0);
        r2 = r0;
    } else {
        c2008 = R(8);
        SETR(8, r8);
        r0 = GCALL1(0x06073368, r9);
        SETR(8, c2008);
        r2 = r0;
    }
    r4 = LD32(0x100 + (sp - 292));
    r0 = GCALL2(0x06072EA8, r4, r2);
    r0 = GCALL1(0x060733D8, r0);
    ST32((0x100 + (sp - 292)), r0);
    r6 = LD32(r10 + 20);
    r1 = LD32(r10);
    r9 = r6;
    if (r1 == 2) {
        r1 = LD16((r10 + 16));
        c4 = (r1 & 0xFFFF) == 1;
        r1 = 0;
        if (!(c4)) {
            ST32(r12, r1);
            ST32(r13, r1);
            ST32(r14, r1);
            r0 = LD32((0x134 + (sp - 292)));
            ST32(r0, r1);
            r11 = LD32((0x100 + (sp - 292)));
            r7 = 0;
            if (!(0 >= r11)) {
                do {
                    if (r8 >= 0) {
                        r1 = LD32(r10 + 24);
                        r3 = r8;
                        if (!((unsigned)r8 >= (unsigned)r1)) {
                            r3 = r3 + r6;
                            r2 = LD8((r3 + 1));
                            r1 = LD8(r9 + r8);
                            r2 = (r2 << 8) + (r1 & 255);
                            r1 = LD32(r13);
                            if (r2 > r1) {
                                ST32(r13, r2);
                            }
                            r1 = LD32(r12);
                            if (!(r2 >= r1)) {
                                ST32(r12, r2);
                            }
                            r11 = LD32((0x124 + (sp - 292)));
                            r1 = r3;
                            if (!((r11 & r11) == 0)) {
                                r2 = LD8((r1 + 3));
                                r11 = LD32(0x134 + (sp - 292));
                                r1 = LD8(((r8 + r9) + 2));
                                r2 = (r2 << 8) + (r1 & 255);
                                r1 = LD32(r11);
                                if (r2 > r1) {
                                    r11 = LD32(0x134 + (sp - 292));
                                    ST32(r11, r2);
                                }
                                r1 = LD32(r14);
                                if (!(r2 >= r1)) {
                                    ST32(r14, r2);
                                }
                            }
                        }
                    }
                    r7 = r7 + 1;
                    r1 = LD16((r10 + 12));
                    r0 = LD32(0x100 + (sp - 292));
                    r8 = r8 + r1;
                } while (AGAIN(!(r7 >= r0)));
            }
            r4 = LD32(r12);
            r4 = HELPER((int)r4 >> 8);
            ST32(r12, (r4 + 127));
            r4 = LD32(r13);
            r4 = HELPER((int)r4 >> 8);
            ST32(r13, (r4 + 127));
            r4 = LD32(r14);
            r4 = HELPER((int)r4 >> 8);
            ST32(r14, (r4 + 127));
            r0 = LD32((0x134 + (sp - 292)));
            r4 = LD32(r0);
            r4 = HELPER((int)r4 >> 8);
            r0 = LD32((0x134 + (sp - 292)));
            ST32(r0, (r4 + 127));
        } else {
            ST32(r12, 127);
            ST32(r13, 127);
            ST32(r14, 127);
            r0 = LD32((0x134 + (sp - 292)));
            ST32(r0, 127);
            r11 = LD32((0x100 + (sp - 292)));
            r7 = 0;
            if (!(0 >= r11)) {
                do {
                    if (r8 >= 0) {
                        r1 = LD32(r10 + 24);
                        r0 = r9;
                        if (!((unsigned)r8 >= (unsigned)r1)) {
                            r1 = LD8(r0 + r8);
                            r2 = r1 & 255;
                            r1 = LD32(r13);
                            if (r2 > r1) {
                                ST32(r13, r2);
                                r0 = r9;
                            }
                            r1 = LD8(r0 + r8);
                            r2 = r1 & 255;
                            r1 = LD32(r12);
                            if (!(r2 >= r1)) {
                                ST32(r12, r2);
                            }
                            r11 = LD32((0x124 + (sp - 292)));
                            r1 = r8;
                            if (!((r11 & r11) == 0)) {
                                r3 = (r1 + r9) + 1;
                                r1 = LD8(r3);
                                r11 = LD32(0x134 + (sp - 292));
                                r2 = r1 & 255;
                                r1 = LD32(r11);
                                c11 = r2 > r1;
                                if (c11) {
                                    r11 = LD32(0x134 + (sp - 292));
                                    ST32(r11, r2);
                                }
                                r1 = LD8(r3);
                                r2 = r1 & 255;
                                r1 = LD32(r14);
                                if (!(r2 >= r1)) {
                                    ST32(r14, r2);
                                }
                            }
                        }
                    }
                    r7 = r7 + 1;
                    r1 = LD16((r10 + 12));
                    r0 = LD32(0x100 + (sp - 292));
                    r8 = r8 + r1;
                } while (AGAIN(!(r7 >= r0)));
            }
        }
    } else {
        ST32(r12, 0);
        ST32(r13, 0);
        ST32(r14, 0);
        r0 = LD32((0x134 + (sp - 292)));
        ST32(r0, 0);
        r1 = LD16((r10 + 16));
        r7 = 0;
        if (!((r1 & 0xFFFF) == 1)) {
            r0 = LD32(0x100 + (sp - 292));
            if (!(r7 >= r0)) {
                do {
                    if (r8 >= 0) {
                        r1 = LD32(r10 + 24);
                        r0 = r6;
                        if (!((unsigned)r8 >= (unsigned)r1)) {
                            r3 = r8 + r9;
                            r2 = LD8(r0 + r8);
                            r1 = LD8((r3 + 1));
                            r2 = (r2 << 8) + (r1 & 255);
                            r1 = LD32(r13);
                            if (r2 > r1) {
                                ST32(r13, r2);
                            }
                            r1 = LD32(r12);
                            if (!(r2 >= r1)) {
                                ST32(r12, r2);
                            }
                            r11 = LD32((0x124 + (sp - 292)));
                            r1 = r8;
                            if (!((r11 & r11) == 0)) {
                                r2 = LD8(((r1 + r6) + 2));
                                r11 = LD32(0x134 + (sp - 292));
                                r1 = LD8((r3 + 3));
                                r2 = (r2 << 8) + (r1 & 255);
                                r1 = LD32(r11);
                                if (r2 > r1) {
                                    r11 = LD32(0x134 + (sp - 292));
                                    ST32(r11, r2);
                                }
                                r1 = LD32(r14);
                                if (!(r2 >= r1)) {
                                    ST32(r14, r2);
                                }
                            }
                        }
                    }
                    r7 = r7 + 1;
                    r1 = LD16((r10 + 12));
                    r0 = LD32(0x100 + (sp - 292));
                    r8 = r8 + r1;
                } while (AGAIN(!(r7 >= r0)));
            }
            r4 = LD32(r12);
            r4 = HELPER((int)r4 >> 8);
            ST32(r12, r4);
            r4 = LD32(r13);
            r4 = HELPER((int)r4 >> 8);
            ST32(r13, r4);
            r4 = LD32(r14);
            r4 = HELPER((int)r4 >> 8);
            ST32(r14, r4);
            r0 = LD32((0x134 + (sp - 292)));
            r4 = LD32(r0);
            r0 = LD32((0x134 + (sp - 292)));
            r4 = HELPER((int)r4 >> 8);
            ST32(r0, r4);
            r1 = LD32(r12);
        } else {
            r0 = GCALL2(0x06030034, r10, (sp - 292));
            r11 = LD32((0x100 + (sp - 292)));
            r7 = 0;
            r3 = sp - 292;
            if (!(0 >= r11)) {
                do {
                    if (r8 >= 0) {
                        r1 = LD32(r10 + 24);
                        if (!((unsigned)r8 >= (unsigned)r1)) {
                            r1 = LD8(r9 + r8);
                            r2 = LD8(r3 + (r1 & 255));
                            r1 = LD32(r13);
                            if (r2 > r1) {
                                ST32(r13, r2);
                            }
                            r1 = LD32(r12);
                            if (!(r2 >= r1)) {
                                ST32(r12, r2);
                            }
                            r11 = LD32((0x124 + (sp - 292)));
                            r1 = r8;
                            if (!((r11 & r11) == 0)) {
                                r1 = LD8(((r1 + r9) + 1));
                                r2 = LD8(r3 + (r1 & 255));
                                r0 = LD32((0x134 + (sp - 292)));
                                r1 = LD32(r0);
                                if (r2 > r1) {
                                    r0 = LD32((0x134 + (sp - 292)));
                                    ST32(r0, r2);
                                }
                                r1 = LD32(r14);
                                if (!(r2 >= r1)) {
                                    ST32(r14, r2);
                                }
                            }
                        }
                    }
                    r7 = r7 + 1;
                    r1 = LD16((r10 + 12));
                    r11 = LD32((0x100 + (sp - 292)));
                    r8 = r8 + r1;
                } while (AGAIN(!(r7 >= r11)));
                r1 = LD32(r12);
            } else {
                r1 = LD32(r12);
            }
        }
        ST32(r12, (r1 + 127));
        r1 = LD32(r13);
        ST32(r13, (r1 + 127));
        r1 = LD32(r14);
        ST32(r14, (r1 + 127));
        r0 = LD32((0x134 + (sp - 292)));
        r1 = LD32(r0);
        r0 = LD32((0x134 + (sp - 292)));
        ST32(r0, (r1 + 127));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06031ABC(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10, r11, c2, c6, c1013, c2008;
    FRAME(sp, 88);

    r9 = r4;
    ST16((sp - 52), 2);
    ST16((sp - 50), 8);
    ST16((sp - 48), 9);
    ST16((sp - 46), 10);
    ST16((sp - 44), 11);
    ST16((sp - 42), 12);
    ST16((sp - 40), 13);
    ST16((sp - 38), 14);
    r8 = r9 + 2;
    r0 = LD16(r8);
    if (r0 == 2) {
        r5 = LD32(r9 + 16);
        r4 = LD32(r9 + 12);
        r0 = GCALL3(0x0603F020, r4, r5, (sp - 88));
        r1 = sp - 88;
        if (!((r0 & r0) == 0)) {
            r0 = LD16((r1 + 4));
            c2 = r0 == 2;
            r0 = LD32(r9 + 4);
            r11 = c2;
            if (r0 == -1) {
                r1 = LD32(r9 + 28);
                r2 = LD32(0x06089CB8);
                r1 = r1 + r2;
                r2 = LD32(r9 + 24);
                r4 = r1 - r2;
            } else {
                r4 = LD32(r9 + 28);
            }
            r8 = LD32(0x06031AB8);
            c2008 = R(8);
            SETR(8, r8);
            r0 = GCALL1(0x06073368, r4);
            SETR(8, c2008);
            r10 = (sp - 88) + 64;
            ST32((sp - 92), r10);
            ST32((sp - 96), (sp - 28));
            ST32((sp - 100), (sp - 32));
            ST32((sp - 104), (sp - 36));
            ST32((sp - 108), r11);
            r0 = GCALL8(0x060316A0, 0, (sp - 88), r0, r8, LD32((sp - 108)), LD32((sp - 104)), LD32((sp - 100)), LD32((sp - 96)));
            if ((r11 & r11) == 0) {
                r2 = LD32(sp - 32);
                r1 = (short)(((((0x100 - r2) >> 1) >> 1) >> 1) >> 1);
            } else {
                r1 = LD32(sp - 32);
                r2 = LD32(r10);
                r1 = (short)(((((0x100 - ((r1 + r2) >> 1)) >> 1) >> 1) >> 1) >> 1);
            }
            if (!(r1 >= 0)) {
                r1 = 0;
            }
            r2 = 7;
            c6 = r1 > 7;
            c1013 = c6;
            if (c6) {
                r1 = r2;
                c1013 = 1;
            }
            r0 = LD16((((((-r1) + 7) + ((-r1) + 7)) + (sp - 88)) + 36));
        } else {
            r0 = LD16(r8);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603D880(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, c1, c3, c5, c7;
    FRAME(sp, 144);

    r2 = 128;
    ST32((sp - 144) + 128, r5);
    r1 = LD8(r5);
    r9 = r4;
    while (1) {
        r0 = sp - 144;
        if (!((r1 & 255) == 32)) {
            POLL();
            r1 = LD32(r0 + r2);
            r1 = r1 + 1;
            ST32(r0 + r2, r1);
            r1 = LD8(r1);
            continue;
        } else {
            break;
        }
    }
    r3 = 128;
    r1 = LD32(r0 + 128);
    while (1) {
        r1 = LD8(r1);
        r0 = sp - 144;
        if ((r1 & 255) == 32) {
            POLL();
            r2 = LD32(r0 + r3);
            r1 = LD8(r2);
            c1 = ((r1 & 255) & (r1 & 255)) == 0;
            r1 = r2;
            if (c1) {
                break;
            } else {
                r1 = r1 + 1;
                ST32(r0 + r3, r1);
                continue;
            }
        } else {
            break;
        }
    }
    r8 = 128;
    r4 = LD32(sp - 16);
    r0 = GCALL3(0x06075238, r4, 0x0603D85C, 5);
    c3 = (r0 & r0) == 0;
    r0 = 0;
    if (c3) {
        r0 = sp - 144;
        r1 = LD32(r0 + r8);
        r1 = r1 + 5;
        ST32(r0 + r8, r1);
        r1 = LD8(r1);
        r3 = r8;
        if (!((r1 & 255) == 61)) {
            r0 = sp - 144;
            while (1) {
                r2 = LD32(r0 + r3);
                r1 = LD8(r2);
                c5 = ((r1 & 255) & (r1 & 255)) == 0;
                r1 = r2;
                if (c5) {
                    break;
                } else {
                    r1 = r1 + 1;
                    ST32(r0 + r3, r1);
                    r1 = LD8(r1);
                    r0 = sp - 144;
                    if (!((r1 & 255) == 61)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
        }
        r7 = 128;
        r0 = sp - 144;
        r3 = LD32(r0 + 128);
        r1 = LD8(r3);
        c7 = ((r1 & 255) & (r1 & 255)) == 0;
        r1 = r3;
        if (c7) {
            r0 = 0;
        } else {
            r1 = r1 + 1;
            ST32(r0 + r7, r1);
            r1 = LD8(r1);
            r2 = 0;
            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                r3 = r7;
                r0 = sp - 144;
                do {
                    r1 = LD32(r0 + r3);
                    r1 = LD8(r1);
                    r0 = sp - 144;
                    if (!((r1 & 255) == 34)) {
                        ST8(r0 + r2, r1);
                        r2 = r2 + 1;
                    }
                    r0 = sp - 144;
                    r1 = LD32(r0 + r3);
                    r1 = r1 + 1;
                    ST32(r0 + r3, r1);
                    r1 = LD8(r1);
                } while (AGAIN(!(((r1 & 255) & (r1 & 255)) == 0)));
            }
            ST8((sp - 144) + r2, 0);
            r8 = 128;
            r4 = LD32((r9 + 108));
            r0 = GCALL4(0x060441C8, r4, (sp - 144), (sp - 16), (r9 + 24));
            r1 = 2;
            if (!((r0 & r0) == 0)) {
                ST32(0x0607668C, r1);
                r4 = LD32((sp - 144) + r8);
                r0 = GCALL1(0x0607507C, r4);
                r0 = GCALL4(0x060279E0, 0, (r0 + 24), -1, 1);
                r2 = r0;
                ST32((r9 + 100), r2);
                if (!((r2 & r2) == 0)) {
                    r6 = LD32((sp - 144) + r8);
                    r0 = GCALL3(0x06045264, r2, 0x0603D864, r6);
                    ST32(r9 + 36, 11);
                    r0 = 0;
                } else {
                    r0 = -3;
                }
            } else {
                r0 = -1;
                ST32(r9 + 40, -1);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603042C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, c0, c2, c1003;
    FRAME(sp, 92);

    r4 = r4 & 0xFFFF;
    r9 = 0;
    ST16((sp - 28), 2);
    ST16((sp - 26), 2);
    ST16(0x0607803C, r4);
    c0 = (r4 & r4) == 0;
    ST16(0x06087F84, 0);
    c1003 = c0;
    if (c0) {
        r1 = 0;
        r5 = 3;
        r3 = 0x06087F48;
        r6 = 1;
        r7 = 0;
        r2 = 0x06087F48;
        r0 = 0;
        do {
            ST32(r0 + r3, r6);
            ST32(r2 + 8, r7);
            r2 = r2 + 12;
            r1 = r1 + 1;
            r0 = r0 + 12;
        } while (AGAIN(!(r1 > r5)));
        r8 = 0x06087DD8;
        r0 = GCALL3(0x0604B3F0, 0x06087DD8, 0, 0x170);
        r1 = 0;
        r3 = 3;
        r2 = 1;
        r0 = 0;
        do {
            ST32(r0 + r8, r2);
            r1 = r1 + 1;
            r0 = r0 + 92;
        } while (AGAIN(!(r1 > r3)));
        r0 = GCALL3(0x06030294, (sp - 28), (sp - 24), 0x06087DD8);
        r10 = r0;
        r5 = 64;
        if (!((r10 & r10) == 0)) {
            r1 = LD32(0x06000344);
            r0 = GCALL2(r1, -1, r5);
            r0 = GCALL2(0x06069E6C, 70, 0x06030098);
            r1 = LD32(0x06000344);
            r0 = GCALL2(r1, -65, 0);
            r11 = 0x06030420;
            r0 = GCALL1(0x06025948, 0x06030420);
            r8 = r0;
            r5 = -1;
            if (!(r8 > 0)) {
                r8 = 0;
                r4 = sp - 92;
            } else {
                r0 = GCALL2(0x06028380, r8, r5);
                r9 = r0;
                r7 = r8;
                if ((r9 & r9) == 0) {
                    r8 = 0;
                    r4 = sp - 92;
                } else {
                    r0 = GCALL4(0x060258EC, r11, (sp - 92), r9, r7);
                    if (!((r0 & r0) == 0)) {
                        r8 = 0;
                        r4 = sp - 92;
                    } else {
                        r0 = GCALL1(0x06025984, (sp - 92));
                        r4 = sp - 92;
                    }
                }
            }
            ST32(sp - 44, r9);
            ST16((sp - 40), r8);
            ST32(sp - 36, r10);
            r1 = LD32((sp - 24));
            ST16((sp - 32), ((int)((unsigned)r1 >> 1)));
            r0 = GCALL1(0x060669F8, (r4 + 48));
            r0 = GCALL1(0x06066BBC, 0);
            ST16(0x25B0042E, 32);
            r0 = SR();
            ST32(0x0608EFD4, ((int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2)));
            r0 = SR();
            SETSR((r0 | 240));
            r2 = LD32(0x0608EFD0);
            ST8(r2, -128);
            r2 = LD32(0x0608EFD4);
            r1 = SR();
            SETSR(((r1 & -241) | ((r2 << 2) << 2)));
            r8 = 0x06027F48;
            r5 = R(5);
            r6 = R(6);
            r0 = GCALL4(0x06027F48, r10, r5, r6, 0x0608EFD4);
            r0 = 0;
            if (!((r9 & r9) == 0)) {
                r0 = GCALL1(r8, r9);
                r0 = 0;
            }
        } else {
            r4 = LD32(0x06087F80);
            r0 = GCALL2(0x06027F48, r4, r5);
            r0 = -3;
        }
    } else {
        r0 = GCALL4(0x060279E0, 0, ((r4 & 0xFFFF) * 92), -1, 1);
        c2 = (r0 & r0) == 0;
        ST32(0x06087F80, r0);
        c1003 = c2;
        if (!(c2)) {
            r1 = 0;
            r5 = 3;
            r3 = 0x06087F48;
            r6 = 1;
            r7 = 0;
            r2 = 0x06087F48;
            r0 = 0;
            do {
                ST32(r0 + r3, r6);
                ST32(r2 + 8, r7);
                r2 = r2 + 12;
                r1 = r1 + 1;
                r0 = r0 + 12;
            } while (AGAIN(!(r1 > r5)));
            r8 = 0x06087DD8;
            r0 = GCALL3(0x0604B3F0, 0x06087DD8, 0, 0x170);
            r1 = 0;
            r3 = 3;
            r2 = 1;
            r0 = 0;
            do {
                ST32(r0 + r8, r2);
                r1 = r1 + 1;
                r0 = r0 + 92;
            } while (AGAIN(!(r1 > r3)));
            r0 = GCALL3(0x06030294, (sp - 28), (sp - 24), 0x06087DD8);
            r10 = r0;
            r5 = 64;
            if (!((r10 & r10) == 0)) {
                r1 = LD32(0x06000344);
                r0 = GCALL2(r1, -1, r5);
                r0 = GCALL2(0x06069E6C, 70, 0x06030098);
                r1 = LD32(0x06000344);
                r0 = GCALL2(r1, -65, 0);
                r11 = 0x06030420;
                r0 = GCALL1(0x06025948, 0x06030420);
                r8 = r0;
                r5 = -1;
                if (!(r8 > 0)) {
                    r8 = 0;
                    r4 = sp - 92;
                } else {
                    r0 = GCALL2(0x06028380, r8, r5);
                    r9 = r0;
                    r7 = r8;
                    if ((r9 & r9) == 0) {
                        r8 = 0;
                        r4 = sp - 92;
                    } else {
                        r0 = GCALL4(0x060258EC, r11, (sp - 92), r9, r7);
                        if (!((r0 & r0) == 0)) {
                            r8 = 0;
                            r4 = sp - 92;
                        } else {
                            r0 = GCALL1(0x06025984, (sp - 92));
                            r4 = sp - 92;
                        }
                    }
                }
                ST32(sp - 44, r9);
                ST16((sp - 40), r8);
                ST32(sp - 36, r10);
                r1 = LD32((sp - 24));
                ST16((sp - 32), ((int)((unsigned)r1 >> 1)));
                r0 = GCALL1(0x060669F8, (r4 + 48));
                r0 = GCALL1(0x06066BBC, 0);
                ST16(0x25B0042E, 32);
                r0 = SR();
                ST32(0x0608EFD4, ((int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2)));
                r0 = SR();
                SETSR((r0 | 240));
                r2 = LD32(0x0608EFD0);
                ST8(r2, -128);
                r2 = LD32(0x0608EFD4);
                r1 = SR();
                SETSR(((r1 & -241) | ((r2 << 2) << 2)));
                r8 = 0x06027F48;
                r5 = R(5);
                r6 = R(6);
                r0 = GCALL4(0x06027F48, r10, r5, r6, 0x0608EFD4);
                r0 = 0;
                if (!((r9 & r9) == 0)) {
                    r0 = GCALL1(r8, r9);
                    r0 = 0;
                }
            } else {
                r4 = LD32(0x06087F80);
                r0 = GCALL2(0x06027F48, r4, r5);
                r0 = -3;
            }
        } else {
            r0 = -3;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030738(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c1009, c2008;
    FRAME(sp, 148);

    r14 = (short)r7;
    r10 = 0;
    r8 = (sp - 148) + 24;
    r1 = LD32((148 + (sp - 148)));
    r13 = LD32((160 + (sp - 148)));
    ST32((112 + (sp - 148)), ((short)r6));
    r11 = (short)r1;
    r9 = r11;
    ST16(r13, -1);
    r0 = GCALL3(0x0603EE88, r8, r4, r5);
    if ((r0 & r0) == 0) {
        r0 = GCALL1(0x0603EE14, r8);
        if ((r0 & r0) == 0) {
            r12 = LD32((156 + (sp - 148)));
            r5 = r9;
            if ((r12 & r12) == 0) {
                c2008 = R(8);
                SETR(8, r8);
                r0 = GCALL2(0x0603F0C8, r8, r5);
                SETR(8, c2008);
                if ((r0 & r0) == 0) {
                    r1 = sp - 148;
                    r4 = LD16((r1 + 40));
                    r0 = GCALL1(0x06030210, (r4 & 0xFFFF));
                    ST16(r13, r0);
                    if (((short)r0) >= 0) {
                        r9 = ((short)r0 * (short)92) + 0x06087DD8;
                        r0 = GCALL2(0x060306D0, (sp - 128), r9);
                        r3 = LD32((156 + (sp - 148)));
                        ST32((r9 + 88), r3);
                        r12 = LD32((156 + (sp - 148)));
                        if (!((r12 & r12) == 0)) {
                            ST32(r9 + 48, r10);
                            ST32(r9 + 52, r10);
                        }
                        r0 = GCALL2(0x0602FBE4, r9, 1);
                        r0 = GCALL2(0x0602FBE4, r9, 1);
                        r0 = GCALL2(0x0602FBE4, r9, 0);
                        r0 = GCALL2(0x0602FBE4, r9, 0);
                        r7 = LD16(r13);
                        ST32((sp - 152), r14);
                        r3 = LD32((116 + (sp - 152)));
                        ST32((sp - 156), r3);
                        r12 = LD32((160 + (sp - 156)));
                        ST32((sp - 160), r12);
                        r0 = LD16((r9 + 8));
                        ST32((sp - 164), (r0 == 2));
                        r0 = GCALL8(0x060305F8, r9, (sp - 148), (sp - 140), r7, LD32((sp - 164)), LD32((sp - 160)), LD32((sp - 156)), LD32((sp - 152)));
                        r0 = 0;
                    } else {
                        r0 = -400;
                    }
                }
            } else {
                c2008 = R(8);
                SETR(8, r8);
                r0 = GCALL1(0x060743C8, r11);
                SETR(8, c2008);
                r8 = LD32(sp - 116);
                r10 = r0;
                r1 = R(1);
                r11 = r1;
                c2008 = R(8);
                SETR(8, r8);
                r0 = GCALL1(0x060743C8, r8);
                SETR(8, c2008);
                r4 = r0;
                r1 = R(1);
                r5 = r1;
                if (!(r8 >= 0)) {
                    r6 = LD32(0x06030728);
                    r7 = LD32(0x0603072C);
                    r0 = GCALL4(0x060739C0, r4, r5, r6, r7);
                    r4 = r0;
                    r1 = R(1);
                    r5 = r1;
                }
                r0 = GCALL4(0x06073E18, r10, r11, r4, r5);
                r1 = R(1);
                r6 = LD32(0x06030730);
                r7 = LD32(0x06030734);
                r0 = GCALL4(0x06073FDC, r0, r1, r6, r7);
                r1 = R(1);
                r0 = GCALL2(0x06074454, r0, r1);
                r2 = LD16((sp - 112));
                r1 = LD32(sp - 100);
                r10 = r0 * r2;
                c1009 = r10 >= 0;
                if ((unsigned)r10 >= (unsigned)r1) {
                    r10 = r1 - r2;
                    c1009 = r10 >= 0;
                }
                if (c1009) {
                    r1 = sp - 148;
                } else {
                    r10 = 0;
                    r1 = sp - 148;
                }
                r4 = LD16((r1 + 40));
                r0 = GCALL1(0x06030210, (r4 & 0xFFFF));
                ST16(r13, r0);
                if (((short)r0) >= 0) {
                    r9 = ((short)r0 * (short)92) + 0x06087DD8;
                    r0 = GCALL2(0x060306D0, (sp - 128), r9);
                    r3 = LD32((156 + (sp - 148)));
                    ST32((r9 + 88), r3);
                    r12 = LD32((156 + (sp - 148)));
                    if (!((r12 & r12) == 0)) {
                        ST32(r9 + 48, r10);
                        ST32(r9 + 52, r10);
                    }
                    r0 = GCALL2(0x0602FBE4, r9, 1);
                    r0 = GCALL2(0x0602FBE4, r9, 1);
                    r0 = GCALL2(0x0602FBE4, r9, 0);
                    r0 = GCALL2(0x0602FBE4, r9, 0);
                    r7 = LD16(r13);
                    ST32((sp - 152), r14);
                    r3 = LD32((116 + (sp - 152)));
                    ST32((sp - 156), r3);
                    r12 = LD32((160 + (sp - 156)));
                    ST32((sp - 160), r12);
                    r0 = LD16((r9 + 8));
                    ST32((sp - 164), (r0 == 2));
                    r0 = GCALL8(0x060305F8, r9, (sp - 148), (sp - 140), r7, LD32((sp - 164)), LD32((sp - 160)), LD32((sp - 156)), LD32((sp - 152)));
                    r0 = 0;
                } else {
                    r0 = -400;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030914(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c3, c1012, c2008;
    FRAME(sp, 412);

    r11 = r4;
    r10 = r5;
    r9 = 0;
    r8 = (sp - 412) + 24;
    r1 = LD32((0x19C + (sp - 412)));
    r13 = LD32((0x1A4 + (sp - 412)));
    r14 = LD32((0x1A8 + (sp - 412)));
    ST32((0x170 + (sp - 412)), ((short)r6));
    ST32((0x174 + (sp - 412)), ((short)r7));
    ST32((0x178 + (sp - 412)), ((short)r1));
    ST16(r14, -1);
    r0 = GCALL3(0x0603EA7C, r8, r11, r10);
    r6 = r10;
    if (!((r0 & r0) == 0)) {
        r0 = GCALL3(0x06041134, r8, r11, r6);
        if ((r0 & r0) == 0) {
            r0 = 0x060410CC;
            r0 = GCALL1(r0, r8);
            c3 = (r13 & r13) == 0;
            if ((r0 & r0) == 0) {
                r4 = sp - 412;
                if (c3) {
                    r5 = LD32((0x178 + (sp - 412)));
                    c2008 = R(8);
                    SETR(8, r8);
                    r0 = GCALL2(0x0603F0C8, (r4 + 24), r5);
                    SETR(8, c2008);
                    if ((r0 & r0) == 0) {
                        r1 = sp - 412;
                        r4 = LD16((r1 + 40));
                        r0 = GCALL1(0x06030210, (r4 & 0xFFFF));
                        ST16(r14, r0);
                        if (((short)r0) >= 0) {
                            r10 = ((short)r0 * (short)92) + 0x06087DD8;
                            r0 = GCALL2(0x060306D0, (sp - 392), r10);
                            ST32((r10 + 88), r13);
                            if (!((r13 & r13) == 0)) {
                                ST32(r10 + 48, r9);
                                ST32(r10 + 52, r9);
                            }
                            r8 = (sp - 412) + 112;
                            r0 = GCALL2(0x06030034, (r10 + 4), r8);
                            r0 = GCALL3(0x0602FDD4, r10, 1, r8);
                            r0 = GCALL3(0x0602FDD4, r10, 1, r8);
                            r0 = GCALL3(0x0602FDD4, r10, 0, r8);
                            r0 = GCALL3(0x0602FDD4, r10, 0, r8);
                            r7 = LD16(r14);
                            r3 = LD32((0x174 + (sp - 412)));
                            ST32((sp - 416), r3);
                            r12 = LD32((0x174 + (sp - 416)));
                            ST32((sp - 420), r12);
                            r3 = LD32((0x1A8 + (sp - 420)));
                            ST32((sp - 424), r3);
                            r0 = LD16((r10 + 8));
                            ST32((sp - 428), (r0 == 2));
                            r0 = GCALL8(0x060305F8, r10, (sp - 412), (sp - 404), r7, LD32((sp - 428)), LD32((sp - 424)), LD32((sp - 420)), LD32((sp - 416)));
                            r0 = 0;
                        } else {
                            r0 = -400;
                        }
                    }
                } else {
                    r4 = LD32((0x178 + (sp - 412)));
                    c2008 = R(8);
                    SETR(8, r8);
                    r0 = GCALL1(0x060743C8, r4);
                    SETR(8, c2008);
                    r8 = LD32(sp - 380);
                    r10 = r0;
                    r1 = R(1);
                    r11 = r1;
                    c2008 = R(8);
                    SETR(8, r8);
                    r0 = GCALL1(0x060743C8, r8);
                    SETR(8, c2008);
                    r4 = r0;
                    r1 = R(1);
                    r5 = r1;
                    if (!(r8 >= 0)) {
                        r6 = LD32(0x06030904);
                        r7 = LD32(0x06030908);
                        r0 = GCALL4(0x060739C0, r4, r5, r6, r7);
                        r4 = r0;
                        r1 = R(1);
                        r5 = r1;
                    }
                    r0 = GCALL4(0x06073E18, r10, r11, r4, r5);
                    r1 = R(1);
                    r6 = LD32(0x0603090C);
                    r7 = LD32(0x06030910);
                    r0 = GCALL4(0x06073FDC, r0, r1, r6, r7);
                    r1 = R(1);
                    r0 = GCALL2(0x06074454, r0, r1);
                    r2 = LD16((sp - 376));
                    r1 = LD32(sp - 364);
                    r9 = r0 * r2;
                    c1012 = r9 >= 0;
                    if ((unsigned)r9 >= (unsigned)r1) {
                        r9 = r1 - r2;
                        c1012 = r9 >= 0;
                    }
                    if (c1012) {
                        r1 = sp - 412;
                    } else {
                        r9 = 0;
                        r1 = sp - 412;
                    }
                    r4 = LD16((r1 + 40));
                    r0 = GCALL1(0x06030210, (r4 & 0xFFFF));
                    ST16(r14, r0);
                    if (((short)r0) >= 0) {
                        r10 = ((short)r0 * (short)92) + 0x06087DD8;
                        r0 = GCALL2(0x060306D0, (sp - 392), r10);
                        ST32((r10 + 88), r13);
                        if (!((r13 & r13) == 0)) {
                            ST32(r10 + 48, r9);
                            ST32(r10 + 52, r9);
                        }
                        r8 = (sp - 412) + 112;
                        r0 = GCALL2(0x06030034, (r10 + 4), r8);
                        r0 = GCALL3(0x0602FDD4, r10, 1, r8);
                        r0 = GCALL3(0x0602FDD4, r10, 1, r8);
                        r0 = GCALL3(0x0602FDD4, r10, 0, r8);
                        r0 = GCALL3(0x0602FDD4, r10, 0, r8);
                        r7 = LD16(r14);
                        r3 = LD32((0x174 + (sp - 412)));
                        ST32((sp - 416), r3);
                        r12 = LD32((0x174 + (sp - 416)));
                        ST32((sp - 420), r12);
                        r3 = LD32((0x1A8 + (sp - 420)));
                        ST32((sp - 424), r3);
                        r0 = LD16((r10 + 8));
                        ST32((sp - 428), (r0 == 2));
                        r0 = GCALL8(0x060305F8, r10, (sp - 412), (sp - 404), r7, LD32((sp - 428)), LD32((sp - 424)), LD32((sp - 420)), LD32((sp - 416)));
                        r0 = 0;
                    } else {
                        r0 = -400;
                    }
                }
            }
        }
    } else {
        r0 = 0x0603E9D8;
        r0 = GCALL1(r0, r8);
        c3 = (r13 & r13) == 0;
        if ((r0 & r0) == 0) {
            r4 = sp - 412;
            if (c3) {
                r5 = LD32((0x178 + (sp - 412)));
                c2008 = R(8);
                SETR(8, r8);
                r0 = GCALL2(0x0603F0C8, (r4 + 24), r5);
                SETR(8, c2008);
                if ((r0 & r0) == 0) {
                    r1 = sp - 412;
                    r4 = LD16((r1 + 40));
                    r0 = GCALL1(0x06030210, (r4 & 0xFFFF));
                    ST16(r14, r0);
                    if (((short)r0) >= 0) {
                        r10 = ((short)r0 * (short)92) + 0x06087DD8;
                        r0 = GCALL2(0x060306D0, (sp - 392), r10);
                        ST32((r10 + 88), r13);
                        if (!((r13 & r13) == 0)) {
                            ST32(r10 + 48, r9);
                            ST32(r10 + 52, r9);
                        }
                        r8 = (sp - 412) + 112;
                        r0 = GCALL2(0x06030034, (r10 + 4), r8);
                        r0 = GCALL3(0x0602FDD4, r10, 1, r8);
                        r0 = GCALL3(0x0602FDD4, r10, 1, r8);
                        r0 = GCALL3(0x0602FDD4, r10, 0, r8);
                        r0 = GCALL3(0x0602FDD4, r10, 0, r8);
                        r7 = LD16(r14);
                        r3 = LD32((0x174 + (sp - 412)));
                        ST32((sp - 416), r3);
                        r12 = LD32((0x174 + (sp - 416)));
                        ST32((sp - 420), r12);
                        r3 = LD32((0x1A8 + (sp - 420)));
                        ST32((sp - 424), r3);
                        r0 = LD16((r10 + 8));
                        ST32((sp - 428), (r0 == 2));
                        r0 = GCALL8(0x060305F8, r10, (sp - 412), (sp - 404), r7, LD32((sp - 428)), LD32((sp - 424)), LD32((sp - 420)), LD32((sp - 416)));
                        r0 = 0;
                    } else {
                        r0 = -400;
                    }
                }
            } else {
                r4 = LD32((0x178 + (sp - 412)));
                c2008 = R(8);
                SETR(8, r8);
                r0 = GCALL1(0x060743C8, r4);
                SETR(8, c2008);
                r8 = LD32(sp - 380);
                r10 = r0;
                r1 = R(1);
                r11 = r1;
                c2008 = R(8);
                SETR(8, r8);
                r0 = GCALL1(0x060743C8, r8);
                SETR(8, c2008);
                r4 = r0;
                r1 = R(1);
                r5 = r1;
                if (!(r8 >= 0)) {
                    r6 = LD32(0x06030904);
                    r7 = LD32(0x06030908);
                    r0 = GCALL4(0x060739C0, r4, r5, r6, r7);
                    r4 = r0;
                    r1 = R(1);
                    r5 = r1;
                }
                r0 = GCALL4(0x06073E18, r10, r11, r4, r5);
                r1 = R(1);
                r6 = LD32(0x0603090C);
                r7 = LD32(0x06030910);
                r0 = GCALL4(0x06073FDC, r0, r1, r6, r7);
                r1 = R(1);
                r0 = GCALL2(0x06074454, r0, r1);
                r2 = LD16((sp - 376));
                r1 = LD32(sp - 364);
                r9 = r0 * r2;
                c1012 = r9 >= 0;
                if ((unsigned)r9 >= (unsigned)r1) {
                    r9 = r1 - r2;
                    c1012 = r9 >= 0;
                }
                if (c1012) {
                    r1 = sp - 412;
                } else {
                    r9 = 0;
                    r1 = sp - 412;
                }
                r4 = LD16((r1 + 40));
                r0 = GCALL1(0x06030210, (r4 & 0xFFFF));
                ST16(r14, r0);
                if (((short)r0) >= 0) {
                    r10 = ((short)r0 * (short)92) + 0x06087DD8;
                    r0 = GCALL2(0x060306D0, (sp - 392), r10);
                    ST32((r10 + 88), r13);
                    if (!((r13 & r13) == 0)) {
                        ST32(r10 + 48, r9);
                        ST32(r10 + 52, r9);
                    }
                    r8 = (sp - 412) + 112;
                    r0 = GCALL2(0x06030034, (r10 + 4), r8);
                    r0 = GCALL3(0x0602FDD4, r10, 1, r8);
                    r0 = GCALL3(0x0602FDD4, r10, 1, r8);
                    r0 = GCALL3(0x0602FDD4, r10, 0, r8);
                    r0 = GCALL3(0x0602FDD4, r10, 0, r8);
                    r7 = LD16(r14);
                    r3 = LD32((0x174 + (sp - 412)));
                    ST32((sp - 416), r3);
                    r12 = LD32((0x174 + (sp - 416)));
                    ST32((sp - 420), r12);
                    r3 = LD32((0x1A8 + (sp - 420)));
                    ST32((sp - 424), r3);
                    r0 = LD16((r10 + 8));
                    ST32((sp - 428), (r0 == 2));
                    r0 = GCALL8(0x060305F8, r10, (sp - 412), (sp - 404), r7, LD32((sp - 428)), LD32((sp - 424)), LD32((sp - 420)), LD32((sp - 416)));
                    r0 = 0;
                } else {
                    r0 = -400;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030B38(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 48);

    ST32(sp - 48, r4);
    r1 = LD32(sp);
    ST32(sp - 44, r5);
    r2 = LD32(sp + 4);
    r13 = r6;
    r3 = LD32(sp + 8);
    r9 = r7;
    r7 = LD32(sp + 12);
    ST32(sp - 40, ((short)r1));
    r12 = (short)r2;
    ST32(sp - 36, ((short)r7));
    r1 = LD32(0x06087F78);
    r10 = r1 + 0x25A00000;
    r14 = (((((int)((unsigned)((int)((unsigned)((int)((unsigned)((r1 + r9) + 0xFFF) >> 8)) >> 2)) >> 2)) << 8) << 2) << 2) + 0x1000;
    r11 = (short)r3;
    if (!((unsigned)r14 > (unsigned)0x00080000)) {
        r0 = LD32(sp - 48);
        r1 = LD32(r0 + 4);
        r8 = 0;
        if (!(r1 == 2)) {
            r5 = r12;
            if (!((unsigned)r8 >= (unsigned)r9)) {
                do {
                    r0 = GCALL8(0x0607290C, r8, r5, 0, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                    r1 = LD8(r13 + (r0 + r11));
                    ST8(r10 + r8, r1);
                    r8 = r8 + 1;
                    r5 = r12;
                } while (AGAIN(!((unsigned)r8 >= (unsigned)r9)));
            }
        } else {
            r5 = r12;
            if (!((unsigned)r8 >= (unsigned)r9)) {
                do {
                    r0 = GCALL8(0x0607290C, r8, r5, 0, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                    r1 = LD8(r13 + (r0 + r11));
                    ST8(r10 + r8, (r1 + 128));
                    r8 = r8 + 1;
                    r5 = r12;
                } while (AGAIN(!((unsigned)r8 >= (unsigned)r9)));
            }
        }
        r2 = 0x06087F78;
        r1 = LD32(0x06087F78);
        r3 = 0;
        if (!((unsigned)r8 >= (unsigned)(r14 - r1))) {
            do {
                ST8(r10 + r8, r3);
                r8 = r8 + 1;
                r1 = LD32(r2);
            } while (AGAIN(!((unsigned)r8 >= (unsigned)(r14 - r1))));
        }
        r8 = 0;
        r7 = LD32(sp - 44);
        r6 = 3;
        r3 = LD32(sp - 48);
        do {
            r1 = r3 + 68;
            r2 = LD32((r7 + 68));
            r7 = r7 + 4;
            r3 = r3 + 4;
            r8 = r8 + 1;
            ST32(r1, r2);
        } while (AGAIN(!(r8 > r6)));
        r1 = LD32(sp - 36);
        r0 = LD32(sp - 48);
        r2 = LD32(0x06087F78);
        ST32((((r1 << 2) + r0) + 68), r2);
        r3 = LD32(sp - 48);
        ST16((r3 + 62), (r14 - r2));
        r4 = LD32(sp - 44);
        r5 = LD32(sp - 48);
        r0 = GCALL8(0x06072820, r4, r5, 9, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
        r1 = LD32(sp - 44);
        r0 = LD16((10 + (sp - 48)));
        ST16((r1 + 84), r0);
        r2 = LD32(sp - 44);
        r0 = 0;
        ST32((r2 + 88), 0);
        r7 = R(7);
        ST32(r7, r14);
    } else {
        r0 = -414;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030C94(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 60);

    ST32(sp - 60, r4);
    ST32(sp - 56, r5);
    r2 = LD32(64 + (sp - 60));
    r13 = r7;
    r1 = LD32(sp);
    r3 = LD32((68 + (sp - 60)));
    r7 = LD32(72 + (sp - 60));
    ST32(sp - 52, ((short)r1));
    ST32(sp - 48, ((short)r2));
    ST32(sp - 44, ((short)r3));
    ST32(sp - 40, ((short)r7));
    r1 = LD32(0x06087F78);
    r7 = r1 + 0x25A00000;
    r12 = (((((int)((unsigned)((int)((unsigned)((int)((unsigned)((r1 + r13) + 0xFFF) >> 8)) >> 2)) >> 2)) << 8) << 2) << 2) + 0x1000;
    r14 = r6;
    if (!((unsigned)r12 > (unsigned)0x00080000)) {
        r0 = LD32(sp - 60);
        r1 = LD32(r0 + 4);
        r11 = 0;
        if (!(r1 == 2)) {
            r10 = 1;
        } else {
            r11 = 1;
            r10 = 0;
        }
        r8 = 0;
        if (!((unsigned)0 >= (unsigned)r13)) {
            r9 = r7;
            do {
                ST32(sp - 36, r7);
                r5 = LD32(sp - 48);
                r0 = GCALL8(0x0607290C, r8, r5, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                r1 = r0;
                r0 = r14;
                r3 = LD32(sp - 44);
                r3 = r3 + r1;
                r1 = LD8(r0 + (r3 + r11));
                r8 = r8 + 2;
                ST8(r9, r1);
                r1 = LD8(r0 + (r3 + r10));
                ST8((r9 + 1), r1);
                r7 = LD32(sp - 36);
                r9 = r9 + 2;
            } while (AGAIN(!((unsigned)r8 >= (unsigned)r13)));
        }
        r2 = 0x06087F78;
        r1 = LD32(0x06087F78);
        r3 = 0;
        if (!((unsigned)r8 >= (unsigned)(r12 - r1))) {
            r0 = r7;
            do {
                ST8(r0 + r8, r3);
                r8 = r8 + 1;
                r1 = LD32(r2);
                r0 = r7;
            } while (AGAIN(!((unsigned)r8 >= (unsigned)(r12 - r1))));
        }
        r1 = LD32(sp - 40);
        r0 = LD32(sp - 60);
        ST32((((r1 << 2) + r0) + 68), r7);
        r2 = LD32(sp - 60);
        r1 = LD32(0x06087F78);
        ST16((r2 + 62), (r12 - r1));
        r4 = LD32(sp - 56);
        r5 = LD32(sp - 60);
        r0 = GCALL8(0x06072820, r4, r5, 9, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
        r1 = LD32(sp - 56);
        r0 = LD16((10 + (sp - 60)));
        ST16((r1 + 84), r0);
        r2 = LD32(sp - 56);
        r0 = 0;
        ST32((r2 + 88), 0);
        r3 = R(3);
        ST32(r3, r12);
    } else {
        r0 = -414;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603104C(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, r14, c1, c2, c5, c9, c1014, c1017;
    int v36;
    int v40;
    int v44;
    int v48;
    int v52;

    r8 = r4;
    r10 = r5;
    r9 = r8 + 8;
    r5 = LD16(r9);
    r4 = LD32(r8 + 28);
    r0 = GCALL2(0x060745A0, r4, r5);
    if (!((unsigned)r0 > (unsigned)0xFFFF)) {
        r6 = 0x06087F84;
        r7 = LD16(0x06087F84);
        r1 = LD16(0x0607803C);
        c1 = ((short)r7) >= (r1 & 0xFFFF);
        r1 = 92;
        if (!(c1)) {
            c2 = (short)r7 * (short)r1;
            r1 = LD32(0x06087F80);
            r12 = r1 + c2;
            ST16(r10, r7);
            r1 = LD16(r6);
            ST16(r6, (r1 + 1));
            r1 = LD32(0x06087F78);
            v36 = r1;
            r2 = LD16(r9);
            r10 = (short)(r2 - 1);
            r1 = LD16((r8 + 20));
            r11 = 0;
            if ((r1 & 0xFFFF) == 1) {
                r11 = 16;
            }
            r0 = (short)r2;
            r9 = 0;
            if (!(r0 == 1)) {
                r11 = r11 | 128;
            }
            c5 = r9 >= r0;
            r0 = 0;
            c1017 = c5;
            if (!(c5)) {
                r13 = 0x0607462C;
                r14 = 0x06030B38;
                r1 = r8;
                while (1) {
                    r1 = LD16((r1 + 20));
                    r4 = LD32(r8 + 28);
                    if (!((r1 & 0xFFFF) == 1)) {
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(r13, r4, r10, r6, r7, v36);
                        r6 = LD32(r8 + 24);
                        r0 = GCALL8(0x06030C94, r8, r12, r6, r0, ((short)r11), r10, ((short)(r9 + r9)), ((short)r9));
                        c1014 = (r0 & r0) == 0;
                    } else {
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(r13, r4, r10, r6, r7, v36);
                        r6 = LD32(r8 + 24);
                        r0 = GCALL8(r14, r8, r12, r6, r0, ((short)r11), r10, ((short)r9), ((short)r9));
                        c1014 = (r0 & r0) == 0;
                    }
                    if (!(c1014)) {
                        POLL();
                        r2 = LD16(0x06087F84);
                        ST16(0x06087F84, (r2 - 1));
                        ST32(0x06087F78, v36);
                        c1017 = 0;
                        break;
                    } else {
                        r1 = LD16((r8 + 8));
                        r9 = r9 + 1;
                        c9 = r9 >= r1;
                        r1 = r8;
                        if (!(c9)) {
                            POLL();
                            continue;
                        } else {
                            r0 = 0;
                            c1017 = 1;
                            break;
                        }
                    }
                    POLL();
                }
            }
        } else {
            r0 = -411;
        }
    } else {
        r0 = -410;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032718(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;
    int v16;

    r8 = r5;
    r1 = LD32(r8);
    r9 = r4;
    if (!((r1 & r1) == 0)) {
        ST32(r8, 0);
    }
    r0 = -7;
    if (!((unsigned)r9 > (unsigned)2)) {
        r1 = LD16(0x06078104);
        r5 = 0;
        if (!((r1 & r1) == 0)) {
            r0 = GCALL2(0x060325B4, r9, r8);
            r1 = LD16(0x06078104);
            if ((r1 & r1) == 0) {
                v16 = r0;
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(0x06032538, 0, 0, 0, 0, v16);
                r0 = v16;
            }
        } else {
            r0 = GCALL4(0x0603248C, 0, r5, 0, r7);
            if ((r0 & r0) == 0) {
                r0 = GCALL2(0x060325B4, r9, r8);
                r1 = LD16(0x06078104);
                if ((r1 & r1) == 0) {
                    v16 = r0;
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(0x06032538, 0, 0, 0, 0, v16);
                    r0 = v16;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032944(int r4, int r5, int r6)
{
    int r0, r1, r7, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 44);

    r13 = r4;
    r11 = r5;
    r14 = r6;
    r8 = (sp - 44) + 4;
    r0 = GCALL4(0x06032BA4, r4, r5, (sp - 44), r8);
    r10 = 0;
    if ((r0 & r0) == 0) {
        r1 = LD16(r8);
        r9 = 0;
        if (!(r10 >= (r1 & 0xFFFF))) {
            r12 = 0x06075104;
            r8 = 0;
            while (1) {
                r5 = LD32(sp - 44);
                r0 = GCALL2(r12, r11, (r5 + r8));
                r1 = sp - 44;
                if ((r0 & r0) == 0) {
                    POLL();
                    r1 = LD32(sp - 44);
                    r4 = LD32((r1 + r8) + 28);
                    r0 = GCALL1(0x06032914, r4);
                    r10 = r0;
                    break;
                } else {
                    r1 = LD16((r1 + 4));
                    r9 = r9 + 1;
                    r8 = r8 + 36;
                    if (!(r9 >= (r1 & 0xFFFF))) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
        }
        r4 = LD32(sp - 44);
        r5 = sp - 44;
        if (!((r4 & r4) == 0)) {
            r0 = GCALL2(0x06027F48, r4, r5);
            ST32(sp - 44, 0);
            r5 = sp - 44;
        }
        r7 = R(7);
        r0 = GCALL5(0x06032718, r13, (r5 + 8), 0, 0, LD32((sp - 44)));
        if (!((r0 & r0) == 0)) {
            r0 = 0;
        } else {
            r4 = LD32(sp - 36);
            r0 = GCALL5(0x06032914, r4, 0, 0, 0, LD32((sp - 44)));
            r10 = r10 + r0;
            r0 = GCALL5(0x06032914, r14, 0, 0, 0, LD32((sp - 44)));
            r0 = (unsigned)r10 >= (unsigned)r0;
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603328C(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, c7, c10, c2010;

    r9 = r4;
    r11 = 0x06078128;
    r1 = LD32(0x06078128);
    r10 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL1(0x06033F6C, r9);
        r0 = GCALL0(0x06033FE0);
        r8 = r0;
        r0 = 1;
        if (!((r8 & r8) == 0)) {
            r0 = GCALL2(0x06033168, r9, r8);
            r0 = 1;
        }
    } else {
        r1 = LD32(0x10C8 + r9);
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x060287D0, 96);
            r8 = r0;
            r0 = 1;
            if (!((r8 & r8) == 0)) {
                r0 = GCALL1(0x06034D24, r8);
                c2010 = R(10);
                SETR(10, r10);
                r0 = GCALL3(0x060342CC, r9, r8, r10);
                SETR(10, c2010);
                r5 = r8;
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL2(0x0603387C, r9, r5);
                    if (!((r0 & r0) == 0)) {
                        r0 = LD32(r8 + 32);
                        c7 = r0 == 4;
                        if (r0 == 8) {
                            r1 = LD32((r11 - 4));
                            r2 = r1;
                            if (!((r1 & r1) == 0)) {
                                r2 = r2 + 24;
                                r0 = LD8(r2);
                                c10 = r0 == 1;
                                if (!((r0 & r0) == 0)) {
                                    r1 = 2;
                                    if (c10) {
                                        ST8(r2, r1);
                                    }
                                } else {
                                    ST8(r2, 1);
                                }
                            }
                        } else {
                            if (c7) {
                                r1 = LD32((r11 - 4));
                                r2 = r1;
                                if (!((r1 & r1) == 0)) {
                                    r2 = r2 + 24;
                                    r0 = LD8(r2);
                                    c10 = r0 == 1;
                                    if (!((r0 & r0) == 0)) {
                                        r1 = 2;
                                        if (c10) {
                                            ST8(r2, r1);
                                        }
                                    } else {
                                        ST8(r2, 1);
                                    }
                                }
                            }
                        }
                        r0 = GCALL2(0x06033168, r9, r8);
                        r0 = 1;
                    } else {
                        r0 = GCALL1(0x06027F48, r8);
                        r0 = 1;
                    }
                } else {
                    r0 = GCALL2(0x06034F00, r8, r5);
                    r0 = 1;
                }
            }
        } else {
            r0 = LD32(0x10CC + r9);
            if (!(r0 == 1)) {
                r0 = GCALL1(0x06033F6C, r9);
                r0 = GCALL0(0x06033FE0);
                r8 = r0;
                r0 = 1;
                if (!((r8 & r8) == 0)) {
                    r0 = GCALL2(0x06033168, r9, r8);
                    r0 = 1;
                }
            } else {
                r0 = GCALL1(0x060287D0, 96);
                r8 = r0;
                r0 = 1;
                if (!((r8 & r8) == 0)) {
                    r0 = GCALL1(0x06034D24, r8);
                    c2010 = R(10);
                    SETR(10, r10);
                    r0 = GCALL3(0x060342CC, r9, r8, r10);
                    SETR(10, c2010);
                    r5 = r8;
                    if (!((r0 & r0) == 0)) {
                        r0 = GCALL2(0x0603387C, r9, r5);
                        if (!((r0 & r0) == 0)) {
                            r0 = LD32(r8 + 32);
                            c7 = r0 == 4;
                            if (r0 == 8) {
                                r1 = LD32((r11 - 4));
                                r2 = r1;
                                if (!((r1 & r1) == 0)) {
                                    r2 = r2 + 24;
                                    r0 = LD8(r2);
                                    c10 = r0 == 1;
                                    if (!((r0 & r0) == 0)) {
                                        r1 = 2;
                                        if (c10) {
                                            ST8(r2, r1);
                                        }
                                    } else {
                                        ST8(r2, 1);
                                    }
                                }
                            } else {
                                if (c7) {
                                    r1 = LD32((r11 - 4));
                                    r2 = r1;
                                    if (!((r1 & r1) == 0)) {
                                        r2 = r2 + 24;
                                        r0 = LD8(r2);
                                        c10 = r0 == 1;
                                        if (!((r0 & r0) == 0)) {
                                            r1 = 2;
                                            if (c10) {
                                                ST8(r2, r1);
                                            }
                                        } else {
                                            ST8(r2, 1);
                                        }
                                    }
                                }
                            }
                            r0 = GCALL2(0x06033168, r9, r8);
                            r0 = 1;
                        } else {
                            r0 = GCALL1(0x06027F48, r8);
                            r0 = 1;
                        }
                    } else {
                        r0 = GCALL2(0x06034F00, r8, r5);
                        r0 = 1;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060366D8(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r11, r12, r13, r14, c0, c2, c3, c10, c1006, c1010, c1014;
    FRAME(sp, 72);

    r11 = r4;
    r12 = r5;
    r8 = 136;
    r0 = LD32(r11 + 136);
    ST32(sp - 36, r0);
    r0 = GCALL3(0x060350C4, r4, (sp - 48), (sp - 44));
    ST32(sp - 40, r0);
    r0 = GCALL2(0x06035068, r11, (sp - 52));
    r13 = 0;
    r14 = LD32(r12 + 52);
    r0 = GCALL1(0x06034CEC, r11);
    c0 = (r0 & r0) == 0;
    r0 = r11;
    if (!(c0)) {
        r1 = LD32(r0 + r8);
        r5 = 28;
        if ((r1 & r1) == 0) {
            ST32(136 + r11, 0);
            r1 = LD32(r11 + 140);
            c1010 = (r14 & r14) == 0;
            if ((r1 & r1) == 0) {
                r9 = r12 + 14;
                r7 = LD16(r9);
                r8 = r12 + 12;
                r6 = LD32(r12 + 16);
                r5 = LD16(r8);
                ST32((sp - 56), -1);
                r1 = LD32(r12 + 20);
                ST32((sp - 60), r1);
                r0 = GCALL6(0x06015154, r11, r5, r6, r7, LD32((sp - 60)), LD32((sp - 56)));
                r7 = LD16(r9);
                r6 = LD32(r12 + 16);
                r5 = LD16(r8);
                ST32((sp - 64), 1);
                ST32((sp - 68), 2);
                ST32((sp - 72), -1);
                r1 = LD32(r12 + 20);
                ST32((sp - 76), r1);
                r0 = GCALL8(0x060153C8, r11, r5, r6, r7, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                c1010 = (r14 & r14) == 0;
            }
            c1014 = (r13 & r13) == 0;
            if (c1010) {
                if (!(c1014)) {
                    r0 = GCALL1(0x0607507C, r13);
                    r8 = r0;
                    r0 = LD32(r12 + 32);
                    c10 = r0 == 4;
                    r0 = LD32(sp - 40);
                    if (c10) {
                        r0 = GCALL3(0x0604B3F0, r13, 42, r8);
                        r0 = LD32(sp - 40);
                    }
                    r1 = LD32(r0);
                    ST32((sp - 56), r1);
                    r1 = LD32(r11 + 0x10B8);
                    ST32((sp - 60), r1);
                    r9 = LD32(sp - 40);
                    r1 = LD32(r9 + 32);
                    ST32((sp - 64), r1);
                    r1 = LD32(r12 + 16);
                    ST32((sp - 68), (r1 + 2));
                    r1 = LD16((r12 + 12));
                    r2 = LD32(sp - 48);
                    ST32((sp - 72), (r1 + r2));
                    r0 = GCALL8(0x06014880, r11, r13, 0, (r8 - 1), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL8(0x06027F48, r13, 0, 0, 0, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                }
                r9 = LD32(sp - 36);
                ST32(r11 + 136, r9);
                r0 = GCALL2(0x060350B0, r11, (sp - 52));
            } else {
                r0 = GCALL1(0x0607507C, r14);
                r0 = GCALL1(0x060287D0, (r0 + 1));
                r13 = r0;
                r1 = r12;
                if (!((r13 & r13) == 0)) {
                    r6 = LD32((r1 + 88));
                    r1 = LD32(r12 + 48);
                    ST32((sp - 56), r1);
                    ST32((sp - 60), r13);
                    r0 = GCALL6(0x060365E8, r11, r12, r6, r14, LD32((sp - 60)), LD32((sp - 56)));
                    c1014 = (r13 & r13) == 0;
                    if (!(c1014)) {
                        r0 = GCALL1(0x0607507C, r13);
                        r8 = r0;
                        r0 = LD32(r12 + 32);
                        c10 = r0 == 4;
                        r0 = LD32(sp - 40);
                        if (c10) {
                            r0 = GCALL3(0x0604B3F0, r13, 42, r8);
                            r0 = LD32(sp - 40);
                        }
                        r1 = LD32(r0);
                        ST32((sp - 56), r1);
                        r1 = LD32(r11 + 0x10B8);
                        ST32((sp - 60), r1);
                        r9 = LD32(sp - 40);
                        r1 = LD32(r9 + 32);
                        ST32((sp - 64), r1);
                        r1 = LD32(r12 + 16);
                        ST32((sp - 68), (r1 + 2));
                        r1 = LD16((r12 + 12));
                        r2 = LD32(sp - 48);
                        ST32((sp - 72), (r1 + r2));
                        r0 = GCALL8(0x06014880, r11, r13, 0, (r8 - 1), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL8(0x06027F48, r13, 0, 0, 0, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                    }
                    r9 = LD32(sp - 36);
                    ST32(r11 + 136, r9);
                    r0 = GCALL2(0x060350B0, r11, (sp - 52));
                } else {
                    r9 = LD32(sp - 36);
                    ST32(136 + r11, r9);
                }
            }
            r0 = 1;
        } else {
            r0 = GCALL2(0x06015D00, r11, r5);
            c2 = (r0 & r0) == 0;
            r0 = r11;
            if (c2) {
                r0 = 0;
            } else {
                r3 = 152;
                r2 = LD32(r0 + 152);
                ST32(r2, 12);
                ST32(r2 + 4, r13);
                ST32(r2 + 24, r12);
                r1 = LD32(r12 + 16);
                ST32(r2 + 12, r1);
                r1 = LD32(r12 + 20);
                r7 = 148;
                ST32(r2 + 16, r1);
                r1 = LD32(r0 + 148);
                c3 = (r1 & r1) == 0;
                c1006 = c3;
                if (!(c3)) {
                    ST32(r1, r2);
                    c1006 = 0;
                }
                r0 = r11;
                ST32(r0 + r7, (r2 + 4));
                r1 = LD32(r0 + r3);
                ST32(r0 + r3, (r1 + 28));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                ST32((r12 + 92), r2);
                ST32(136 + r11, 0);
                r1 = LD32(r11 + 140);
                c1010 = (r14 & r14) == 0;
                if ((r1 & r1) == 0) {
                    r9 = r12 + 14;
                    r7 = LD16(r9);
                    r8 = r12 + 12;
                    r6 = LD32(r12 + 16);
                    r5 = LD16(r8);
                    ST32((sp - 56), -1);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 60), r1);
                    r0 = GCALL6(0x06015154, r11, r5, r6, r7, LD32((sp - 60)), LD32((sp - 56)));
                    r7 = LD16(r9);
                    r6 = LD32(r12 + 16);
                    r5 = LD16(r8);
                    ST32((sp - 64), 1);
                    ST32((sp - 68), 2);
                    ST32((sp - 72), -1);
                    r1 = LD32(r12 + 20);
                    ST32((sp - 76), r1);
                    r0 = GCALL8(0x060153C8, r11, r5, r6, r7, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                    c1010 = (r14 & r14) == 0;
                }
                c1014 = (r13 & r13) == 0;
                if (c1010) {
                    if (!(c1014)) {
                        r0 = GCALL1(0x0607507C, r13);
                        r8 = r0;
                        r0 = LD32(r12 + 32);
                        c10 = r0 == 4;
                        r0 = LD32(sp - 40);
                        if (c10) {
                            r0 = GCALL3(0x0604B3F0, r13, 42, r8);
                            r0 = LD32(sp - 40);
                        }
                        r1 = LD32(r0);
                        ST32((sp - 56), r1);
                        r1 = LD32(r11 + 0x10B8);
                        ST32((sp - 60), r1);
                        r9 = LD32(sp - 40);
                        r1 = LD32(r9 + 32);
                        ST32((sp - 64), r1);
                        r1 = LD32(r12 + 16);
                        ST32((sp - 68), (r1 + 2));
                        r1 = LD16((r12 + 12));
                        r2 = LD32(sp - 48);
                        ST32((sp - 72), (r1 + r2));
                        r0 = GCALL8(0x06014880, r11, r13, 0, (r8 - 1), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL8(0x06027F48, r13, 0, 0, 0, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                    }
                    r9 = LD32(sp - 36);
                    ST32(r11 + 136, r9);
                    r0 = GCALL2(0x060350B0, r11, (sp - 52));
                } else {
                    r0 = GCALL1(0x0607507C, r14);
                    r0 = GCALL1(0x060287D0, (r0 + 1));
                    r13 = r0;
                    r1 = r12;
                    if (!((r13 & r13) == 0)) {
                        r6 = LD32((r1 + 88));
                        r1 = LD32(r12 + 48);
                        ST32((sp - 56), r1);
                        ST32((sp - 60), r13);
                        r0 = GCALL6(0x060365E8, r11, r12, r6, r14, LD32((sp - 60)), LD32((sp - 56)));
                        c1014 = (r13 & r13) == 0;
                        if (!(c1014)) {
                            r0 = GCALL1(0x0607507C, r13);
                            r8 = r0;
                            r0 = LD32(r12 + 32);
                            c10 = r0 == 4;
                            r0 = LD32(sp - 40);
                            if (c10) {
                                r0 = GCALL3(0x0604B3F0, r13, 42, r8);
                                r0 = LD32(sp - 40);
                            }
                            r1 = LD32(r0);
                            ST32((sp - 56), r1);
                            r1 = LD32(r11 + 0x10B8);
                            ST32((sp - 60), r1);
                            r9 = LD32(sp - 40);
                            r1 = LD32(r9 + 32);
                            ST32((sp - 64), r1);
                            r1 = LD32(r12 + 16);
                            ST32((sp - 68), (r1 + 2));
                            r1 = LD16((r12 + 12));
                            r2 = LD32(sp - 48);
                            ST32((sp - 72), (r1 + r2));
                            r0 = GCALL8(0x06014880, r11, r13, 0, (r8 - 1), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL8(0x06027F48, r13, 0, 0, 0, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                        }
                        r9 = LD32(sp - 36);
                        ST32(r11 + 136, r9);
                        r0 = GCALL2(0x060350B0, r11, (sp - 52));
                    } else {
                        r9 = LD32(sp - 36);
                        ST32(136 + r11, r9);
                    }
                }
                r0 = 1;
            }
        }
    } else {
        r9 = LD32(sp - 36);
        ST32(r11 + 136, r9);
        r0 = GCALL2(0x060350B0, r11, (sp - 52));
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037EE8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, c0;

    r9 = r4;
    r12 = r5;
    r10 = LD32(r9 + 4);
    r0 = GCALL1(0x0607507C, r12);
    r11 = r0;
    c0 = (r11 & r11) == 0;
    r0 = c0;
    if (!(c0)) {
        r1 = LD32(r9 + 4);
        r2 = LD32(r9 + 8);
        while (r11 > ((r1 - r2) - 1)) {
            POLL();
            r10 = r10 + r10;
            r1 = r10;
        }
        r1 = LD32(r9 + 4);
        if (r10 == r1) {
            r4 = LD32(r9);
            r0 = GCALL3(0x06075470, r4, r12, r11);
            r1 = LD32(r9 + 8);
            r0 = 1;
            ST32(r9 + 8, (r1 + r11));
        } else {
            r5 = LD32(r9);
            r0 = GCALL4(0x06027C18, 0, r5, r10, r7);
            r8 = r0;
            if (!((r8 & r8) == 0)) {
                ST32(r9 + 4, r10);
                ST32(r9, r8);
                r4 = LD32(r9);
                r0 = GCALL3(0x06075470, r4, r12, r11);
                r1 = LD32(r9 + 8);
                r0 = 1;
                ST32(r9 + 8, (r1 + r11));
            } else {
                r4 = LD32(r9);
                r0 = GCALL1(0x06027800, r4);
                r7 = 1;
                if (!((r0 & r0) == 0)) {
                    r0 = 0x060279E0;
                    r6 = 3;
                    r5 = r10;
                    r4 = 0;
                } else {
                    r0 = 0x060279E0;
                    r7 = 1;
                    r6 = 3;
                    r5 = r10;
                    r4 = 1;
                }
                r0 = GCALL4(r0, r4, r5, r6, r7);
                r8 = r0;
                r1 = 0;
                if (!((r8 & r8) == 0)) {
                    ST8(r8, r1);
                    r5 = LD32(r9);
                    r0 = GCALL2(0x060750DC, r8, r5);
                    r4 = LD32(r9);
                    r0 = GCALL1(0x06027F48, r4);
                    ST32(r9, 0);
                    ST32(r9 + 4, r10);
                    ST32(r9, r8);
                    r4 = LD32(r9);
                    r0 = GCALL3(0x06075470, r4, r12, r11);
                    r1 = LD32(r9 + 8);
                    r0 = 1;
                    ST32(r9 + 8, (r1 + r11));
                } else {
                    r0 = 0;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060382AC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, c2, c3, c6, c1008;
    FRAME(sp, 36);

    r13 = r6;
    ST32(sp - 36, 0);
    ST32(sp - 32, 0);
    r10 = LD32(r5 + 60);
    r12 = r7;
    if ((r10 & r10) == 0) {
        r10 = 0x06033094;
    }
    r8 = LD32(r5 + 44);
    r4 = LD32(sp - 36);
    if ((r8 & r8) == 0) {
        r0 = 1;
        if (!((r4 & r4) == 0)) {
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
            r0 = 1;
        }
    } else {
        r11 = 0x060387F4;
        r9 = 0x06027F48;
        while (1) {
            r1 = LD32(r8);
            c2 = (r1 & r1) == 0;
            r1 = LD32(sp - 36);
            if (c2) {
                r8 = LD32(r8 + 24);
                r4 = LD32(sp - 36);
                if (!((r8 & r8) == 0)) {
                    POLL();
                    continue;
                } else {
                    r0 = 1;
                    if ((r4 & r4) == 0) {
                        break;
                    } else {
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
                        r0 = 1;
                        break;
                    }
                }
            } else {
                c3 = (r1 & r1) == 0;
                r5 = r10;
                c1008 = c3;
                if (!(c3)) {
                    c6 = (r12 & r12) == 0;
                    if (c1008) {
                        r0 = 0;
                        break;
                    } else {
                        r5 = LD32(r8 + 12);
                        if (!(c6)) {
                            r0 = GCALL6(0x06038938, (sp - 32), r5, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
                            r6 = LD32(sp - 32);
                            if (!((r0 & r0) == 0)) {
                                r5 = LD32(sp - 36);
                                r0 = GCALL6(0x06037FBC, r13, r5, r6, 0, LD32((sp - 36)), LD32((sp - 32)));
                                r4 = LD32(sp - 32);
                                if (!((r0 & r0) == 0)) {
                                    if (!((r4 & r4) == 0)) {
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                    }
                                    r8 = LD32(r8 + 24);
                                    r4 = LD32(sp - 36);
                                    if (!((r8 & r8) == 0)) {
                                        POLL();
                                        continue;
                                    } else {
                                        r0 = 1;
                                        if ((r4 & r4) == 0) {
                                            break;
                                        } else {
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
                                            r0 = 1;
                                            break;
                                        }
                                    }
                                } else {
                                    r4 = LD32(sp - 36);
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                    r4 = LD32(sp - 32);
                                    r0 = 0;
                                    if ((r4 & r4) == 0) {
                                        break;
                                    } else {
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                        r0 = 0;
                                        break;
                                    }
                                }
                            } else {
                                r4 = LD32(sp - 36);
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                r0 = 0;
                                break;
                            }
                        } else {
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL6(r11, (sp - 32), r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                            r6 = LD32(sp - 32);
                            if (!((r0 & r0) == 0)) {
                                r5 = LD32(sp - 36);
                                r0 = GCALL6(0x06037FBC, r13, r5, r6, 0, LD32((sp - 36)), LD32((sp - 32)));
                                r4 = LD32(sp - 32);
                                if (!((r0 & r0) == 0)) {
                                    if (!((r4 & r4) == 0)) {
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                    }
                                    r8 = LD32(r8 + 24);
                                    r4 = LD32(sp - 36);
                                    if (!((r8 & r8) == 0)) {
                                        POLL();
                                        continue;
                                    } else {
                                        r0 = 1;
                                        if ((r4 & r4) == 0) {
                                            break;
                                        } else {
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
                                            r0 = 1;
                                            break;
                                        }
                                    }
                                } else {
                                    r4 = LD32(sp - 36);
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                    r4 = LD32(sp - 32);
                                    r0 = 0;
                                    if ((r4 & r4) == 0) {
                                        break;
                                    } else {
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                        r0 = 0;
                                        break;
                                    }
                                }
                            } else {
                                r4 = LD32(sp - 36);
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                r0 = 0;
                                break;
                            }
                        }
                    }
                } else {
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(r11, (sp - 36), r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                    r1 = LD32(sp - 36);
                    if ((r0 & r0) == 0) {
                        r0 = 0;
                        break;
                    } else {
                        c1008 = (r1 & r1) == 0;
                        c6 = (r12 & r12) == 0;
                        if (c1008) {
                            r0 = 0;
                            break;
                        } else {
                            r5 = LD32(r8 + 12);
                            if (!(c6)) {
                                r0 = GCALL6(0x06038938, (sp - 32), r5, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
                                r6 = LD32(sp - 32);
                                if (!((r0 & r0) == 0)) {
                                    r5 = LD32(sp - 36);
                                    r0 = GCALL6(0x06037FBC, r13, r5, r6, 0, LD32((sp - 36)), LD32((sp - 32)));
                                    r4 = LD32(sp - 32);
                                    if (!((r0 & r0) == 0)) {
                                        if (!((r4 & r4) == 0)) {
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                        }
                                        r8 = LD32(r8 + 24);
                                        r4 = LD32(sp - 36);
                                        if (!((r8 & r8) == 0)) {
                                            POLL();
                                            continue;
                                        } else {
                                            r0 = 1;
                                            if ((r4 & r4) == 0) {
                                                break;
                                            } else {
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
                                                r0 = 1;
                                                break;
                                            }
                                        }
                                    } else {
                                        r4 = LD32(sp - 36);
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                        r4 = LD32(sp - 32);
                                        r0 = 0;
                                        if ((r4 & r4) == 0) {
                                            break;
                                        } else {
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                            r0 = 0;
                                            break;
                                        }
                                    }
                                } else {
                                    r4 = LD32(sp - 36);
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                    r0 = 0;
                                    break;
                                }
                            } else {
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL6(r11, (sp - 32), r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                r6 = LD32(sp - 32);
                                if (!((r0 & r0) == 0)) {
                                    r5 = LD32(sp - 36);
                                    r0 = GCALL6(0x06037FBC, r13, r5, r6, 0, LD32((sp - 36)), LD32((sp - 32)));
                                    r4 = LD32(sp - 32);
                                    if (!((r0 & r0) == 0)) {
                                        if (!((r4 & r4) == 0)) {
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                        }
                                        r8 = LD32(r8 + 24);
                                        r4 = LD32(sp - 36);
                                        if (!((r8 & r8) == 0)) {
                                            POLL();
                                            continue;
                                        } else {
                                            r0 = 1;
                                            if ((r4 & r4) == 0) {
                                                break;
                                            } else {
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
                                                r0 = 1;
                                                break;
                                            }
                                        }
                                    } else {
                                        r4 = LD32(sp - 36);
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                        r4 = LD32(sp - 32);
                                        r0 = 0;
                                        if ((r4 & r4) == 0) {
                                            break;
                                        } else {
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                            r0 = 0;
                                            break;
                                        }
                                    }
                                } else {
                                    r4 = LD32(sp - 36);
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL6(r9, r4, r5, r6, r7, LD32((sp - 36)), LD32((sp - 32)));
                                    r0 = 0;
                                    break;
                                }
                            }
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
int f06038384(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12, c4, c5, c1012;
    FRAME(sp, 32);

    r12 = r6;
    r1 = 0;
    ST32(sp - 32, 0);
    ST32(sp - 28, 0);
    r0 = LD32(r5 + 48);
    r11 = r7;
    if (r0 == 2) {
        r1 = 1;
    }
    r8 = LD32(r5 + 32);
    if ((r8 & r8) == 0) {
        r8 = 0x06033094;
    }
    r4 = LD32(r5 + 40);
    r0 = GCALL6(0x060424BC, r4, r1, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
    r9 = r0;
    r10 = 0x060387F4;
    r0 = GCALL6(0x060387F4, (sp - 32), r8, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
    r1 = LD32(sp - 32);
    if ((r0 & r0) == 0) {
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL6(0x06027F48, r9, 0, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
        r0 = 0;
    } else {
        c4 = (r9 & r9) == 0;
        if (!((r1 & r1) == 0)) {
            c5 = (r11 & r11) == 0;
            if (c4) {
                r6 = LD32(sp - 28);
                r5 = LD32(sp - 32);
                r0 = GCALL6(0x06037FBC, r12, r5, r6, 0, LD32((sp - 32)), LD32((sp - 28)));
                r10 = r0;
                if (!((r9 & r9) == 0)) {
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(0x06027F48, r9, 0, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
                }
                r8 = 0x06027F48;
                r4 = LD32(sp - 32);
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
                r4 = LD32(sp - 28);
                r0 = r10;
                if (!((r4 & r4) == 0)) {
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(r8, r4, r5, r6, r7, LD32((sp - 32)), LD32((sp - 28)));
                    r0 = r10;
                }
            } else {
                r4 = sp - 32;
                if (!(c5)) {
                    r0 = GCALL6(0x06038938, (r4 + 4), r9, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
                    c1012 = (r0 & r0) == 0;
                } else {
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(r10, (r4 + 4), r9, r6, r7, LD32((sp - 32)), LD32((sp - 28)));
                    c1012 = (r0 & r0) == 0;
                }
                r6 = LD32(sp - 28);
                if (!(c1012)) {
                    r5 = LD32(sp - 32);
                    r0 = GCALL6(0x06037FBC, r12, r5, r6, 0, LD32((sp - 32)), LD32((sp - 28)));
                    r10 = r0;
                    if (!((r9 & r9) == 0)) {
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL6(0x06027F48, r9, 0, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
                    }
                    r8 = 0x06027F48;
                    r4 = LD32(sp - 32);
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
                    r4 = LD32(sp - 28);
                    r0 = r10;
                    if (!((r4 & r4) == 0)) {
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL6(r8, r4, r5, r6, r7, LD32((sp - 32)), LD32((sp - 28)));
                        r0 = r10;
                    }
                } else {
                    r4 = LD32(sp - 32);
                    r5 = R(5);
                    r7 = R(7);
                    r0 = GCALL6(0x06027F48, r4, r5, r6, 0, LD32((sp - 32)), LD32((sp - 28)));
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(0x06027F48, r9, 0, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
                    r0 = 0;
                }
            }
        } else {
            r0 = 0;
            if (!(c4)) {
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL6(0x06027F48, r9, 0, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603997C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;

    r9 = r4;
    r10 = 1;
    r6 = 1;
    r8 = 0;
    r7 = 0xDDC;
    r5 = 0x9DC;
    r3 = 255;
    r2 = r9;
    do {
        r0 = r2;
        r1 = LD32(r0 + r7);
        if (r1 > r10) {
            r10 = r1;
            r0 = r2;
        }
        r1 = LD32(r0 + r5);
        if (r1 > r6) {
            r6 = r1;
        }
        r8 = r8 + 1;
        r2 = r2 + 4;
    } while (AGAIN(!(r8 > r3)));
    r8 = 0;
    r13 = 0x15DC;
    r12 = 0x0607286C;
    r11 = 0x19DC;
    r14 = 0xDDC;
    r7 = r9;
    do {
        r2 = LD32(0x9DC + r7);
        if (!((r2 & r2) == 0)) {
            r0 = r7;
            r1 = LD32(r0 + r13);
            if ((r1 & r1) == 0) {
                r1 = LD32(r9);
                r6 = R(6);
                r0 = GCALL4(r12, ((r1 * r2) - 1), r6, r6, r7);
                r7 = R(7);
                ST32(r7 + r13, (r0 + 1));
                r0 = r7;
            }
            r1 = LD32(r0 + r11);
            if ((r1 & r1) == 0) {
                r2 = LD32(r9 + 4);
                r1 = LD32(r0 + r14);
                r0 = GCALL4(r12, ((r2 * r1) - 1), r10, 0, r7);
                r7 = R(7);
                ST32(r7 + r11, (r0 + 1));
            }
        }
        r8 = r8 + 1;
        r7 = r7 + 4;
    } while (AGAIN(!(r8 > 255)));
    ST32(r9 + 24, r10);
    r6 = R(6);
    ST32(r9 + 20, r6);
    r4 = LD32(r9);
    r7 = 0x0607286C;
    r0 = GCALL2(0x0607286C, (r4 - 1), r6);
    r4 = LD32(r9 + 4);
    ST32(r9 + 28, (r0 + 1));
    if ((r4 & r4) == 0) {
        r1 = 0;
    } else {
        r0 = GCALL4(r7, (r4 - 1), r10, r6, r7);
        r1 = r0 + 1;
    }
    ST32(r9 + 32, r1);
    r0 = LD8((r9 + 40));
    if (!(r0 == 3)) {
        r2 = LD32(r9 + 28);
        r1 = r2 - 1;
        if (!(r1 >= 0)) {
            r1 = r2 + 6;
        }
        r2 = LD32(r9 + 32);
        ST32(r9 + 28, ((((r1 >> 1) >> 1) >> 1) + 1));
        if (!((r2 & r2) == 0)) {
            r1 = r2 - 1;
            if (!(r1 >= 0)) {
                r1 = r2 + 6;
            }
            ST32(r9 + 32, ((((r1 >> 1) >> 1) >> 1) + 1));
        }
    }
    r8 = 0;
    r11 = 0x0607286C;
    r10 = r9 + 40;
    r6 = r9;
    do {
        r5 = LD32(0x9DC + r6);
        r0 = r6;
        if (!((r5 & r5) == 0)) {
            r4 = LD32(r0 + 0x15DC);
            r0 = GCALL3(r11, (r4 - 1), r5, r6);
            r1 = LD8(r10);
            r7 = r0;
            r0 = r7;
            r1 = LD32(r9 + 32);
            r6 = R(6);
            r0 = r6;
            if (!((r1 & r1) == 0)) {
                r4 = LD32(r0 + 0x19DC);
                r5 = LD32(r0 + 0xDDC);
                r0 = GCALL4(r11, (r4 - 1), r5, r6, r7);
                r1 = LD8(r10);
                r0 = r0;
            }
        }
        r8 = r8 + 1;
        r6 = R(6);
        r6 = r6 + 4;
    } while (AGAIN(!(r8 > 255)));
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A890(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, c9;
    int v32;

    r10 = r4;
    r1 = LD32(r10 + 0x1DE4);
    r6 = LD32(r1 + 16);
    r11 = r5;
    r1 = LD32(r1 + 24);
    v32 = r1;
    r5 = v32;
    r0 = GCALL5(0x0607286C, r6, r5, 0, 0, v32);
    r8 = ((r6 - (r0 * r5)) << 2) + ((r6 - (r0 * r5)) << 2);
    r12 = r8;
    if (!(r8 >= (r8 + 8))) {
        r13 = 0x0603A710;
        do {
            r6 = LD32(0x1DE4 + r10);
            r9 = LD32(r6 + 32);
            if ((r9 & r9) == 0) {
                r1 = LD32(r6 + 40);
                r7 = LD32((r8 << 2) + r1);
                r0 = GCALL5(r13, r10, 8, r11, r7, v32);
                r11 = r11 + 32;
            } else {
                r4 = LD32(r6 + 16);
                r5 = LD32(r6 + 24);
                r0 = GCALL5(0x0607286C, r4, r5, 0, 0, v32);
                if (!((((r0 << 2) + (r0 << 2)) + r8) >= r9)) {
                    r1 = LD32(r6 + 40);
                    r7 = LD32((r8 << 2) + r1);
                    r0 = GCALL5(r13, r10, 8, r11, r7, v32);
                    r11 = r11 + 32;
                }
            }
            r8 = r8 + 1;
        } while (AGAIN(!(r8 >= (r12 + 8))));
    }
    r9 = 0x1DE4;
    r0 = r10;
    r1 = LD32(r0 + 0x1DE4);
    r7 = LD32(r1 + 12);
    r7 = r7 + 1;
    ST32(r1 + 12, r7);
    r8 = LD32(r0 + 0x1DE4);
    r11 = 0x0607286C;
    r6 = LD32(r8 + 20);
    r0 = GCALL5(0x0607286C, r7, r6, 0, 0, v32);
    if (((r7 - (r0 * r6)) & (r7 - (r0 * r6))) == 0) {
        r7 = LD32(r8 + 16);
        r7 = r7 + 1;
        ST32(r8 + 16, r7);
        r6 = LD32(r10 + r9);
        r8 = LD32(r6 + 24);
        r0 = GCALL5(r11, r7, r8, r6, r7, v32);
        r7 = R(7);
        if (!(((r7 - (r0 * r8)) & (r7 - (r0 * r8))) == 0)) {
            r6 = R(6);
            r1 = LD32(r6 + 12);
            r2 = LD32(r6 + 20);
            ST32(r6 + 12, (r1 - r2));
        } else {
            r0 = 0x1DE0;
            r1 = LD32(0x1DE0 + r10);
            r2 = LD32((r1 + 68));
            r6 = R(6);
            r1 = LD32(r6 + 20);
            c9 = r2 * r1;
            r1 = LD32(r6 + 12);
            if (r1 >= c9) {
                ST32(r6 + 12, 0);
                r0 = GCALL5(0x0603AAB8, r10, 0, 0, 0, v32);
                r0 = GCALL5(0x0603A9AC, r10, 0, 0, 0, v32);
            } else {
                r1 = LD32(r6 + 16);
                ST32(r6 + 16, (r1 - r8));
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603ABAC(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, c3, c6, c1010;

    r9 = r4;
    r10 = r5;
    r8 = LD32(r9 + 12);
    r0 = GCALL3(0x0604B3F0, r4, 0, 0x1E48);
    ST32(r9 + 12, r8);
    r0 = GCALL2(0x0603A208, r10, r8);
    r1 = r9;
    if (r0 == -304) {
        ST32((r1 + 72), r10);
        ST32((r9 + 76), 0);
        r0 = r9;
        ST32(r0 + 0x1DE8, 0);
        ST8((r9 + 42), 8);
        ST32(r0 + 128, 2);
        r8 = 0x104;
        r11 = 0x060279E0;
        r0 = GCALL4(0x060279E0, 0, 0x104, -1, 1);
        r1 = r0;
        r10 = 132;
        ST32(r9 + 132, r1);
        if ((r1 & r1) == 0) {
            r0 = -3;
        } else {
            r0 = GCALL4(r11, 0, r8, -1, 1);
            r1 = r0;
            r0 = r9;
            ST32(r0 + 136, r1);
            if (!((r1 & r1) == 0)) {
                r4 = LD32(r0 + r10);
                r0 = GCALL3(0x06072820, r4, 0x0607828C, 64);
                r2 = R(2);
                r4 = LD32(r9 + r2);
                r1 = R(1);
                r0 = GCALL3(r1, r4, 0x0607838C, 64);
                r0 = GCALL1(0x0603BA4C, r9);
                c3 = (r0 & r0) == 0;
                r0 = -1;
                if (c3) {
                    ST8((r9 + 45), 0);
                    r0 = GCALL1(0x0603A178, r9);
                    if ((r0 & r0) == 0) {
                        r1 = LD32(r9 + 36);
                        r0 = r1;
                        c6 = r0 == 3;
                        c1010 = c6;
                        if (r0 == 1) {
                            ST32(r9 + 52, 0x100);
                            ST32(r9 + 8, 0);
                            ST32((r9 + 68), 1);
                            r0 = 0;
                        } else {
                            c1010 = c6;
                            if (c6) {
                                ST32(r9 + 52, 0x100);
                                ST32(r9 + 8, 0);
                                ST32((r9 + 68), 1);
                                r0 = 0;
                            } else {
                                r0 = -302;
                            }
                        }
                    } else {
                        r0 = GCALL2(0x06045264, 0x0608B9D0, 0x0603AB90);
                        r0 = GCALL1(0x0602BA00, 0x0608B9D0);
                        r0 = -300;
                    }
                }
            } else {
                r0 = -3;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603B094(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8, r9, r10, r11, r12;
    FRAME(sp, 24);

    r0 = 0x1DE0;
    r1 = LD32(0x1DE0 + r4);
    r12 = r5;
    r11 = LD32(sp);
    r1 = LD32((r1 + 76));
    r8 = r7;
    r5 = LD32(r1 + 44);
    if (r6 > 0) {
        r10 = -32;
        r9 = 0x060727AC;
        do {
            r3 = r12;
            r7 = r8;
            if (r3 > 0) {
                do {
                    r5 = R(5);
                    r0 = LD8(r5);
                    r0 = GCALL4(r9, (r0 & 192), (r5 + 1), 0, r7);
                    r1 = R(1);
                    r4 = R(4);
                    r7 = R(7);
                    ST8(r7, (r1 | r4));
                    r3 = R(3);
                    r7 = r7 + 1;
                } while (AGAIN(r3 > 0));
            }
            r6 = R(6);
            r8 = r8 + r11;
        } while (AGAIN((r6 - 1) > 0));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603D720(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14, c4, c5, c9;

    r9 = r4;
    r2 = LD32(136 + r9);
    r13 = r5;
    r1 = LD8(r2);
    r8 = 0;
    if (!((r1 & 255) == 32)) {
        r8 = r8 + 1;
        do {
            r1 = LD8(r2 + r8);
            r8 = r8 + 1;
        } while (AGAIN(!((r1 & 255) == 32)));
        r8 = r8 - 1;
    }
    r2 = LD32(r9 + 136);
    do {
        r1 = LD8(r2 + r8);
        r8 = r8 + 1;
    } while (AGAIN((r1 & 255) == 32));
    r8 = r8 - 1;
    r11 = 136;
    r4 = LD32(r9 + 136);
    r12 = 0x0607507C;
    r14 = LD32(r9);
    r0 = GCALL1(0x0607507C, (r4 + r8));
    r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
    r10 = r0;
    r0 = r9;
    if (!((r10 & r10) == 0)) {
        r5 = LD32(r0 + r11);
        r0 = GCALL2(0x060750DC, r10, (r5 + r8));
        r1 = LD32(r9 + 4);
        c4 = (r1 & r1) == 0;
        r1 = 0;
        if (!(c4)) {
            ST32(r9 + 4, r1);
        }
        r1 = LD32(r9 + 8);
        c5 = (r1 & r1) == 0;
        r1 = 0;
        if (!(c5)) {
            ST32(r9 + 8, r1);
        }
        ST32(r9, r10);
        r0 = GCALL1(0x0603C2FC, r9);
        r0 = LD32(r9 + 28);
        if (!(r0 == 12)) {
            r8 = 0x060767CC;
            r0 = GCALL2(0x0603D034, r9, 0x060767CC);
            r4 = LD32(0x060767CC);
            r0 = GCALL1(r12, r4);
            r0 = GCALL1(0x060111C0, r0);
            r1 = LD32(0x06075988);
            if ((r1 & r1) == 0) {
                r1 = LD32(0x06075990);
                c9 = (r13 & r13) == 0;
                if ((r1 & r1) == 0) {
                    if (!(c9)) {
                        r5 = LD32(r8);
                        r0 = GCALL3(0x060473B4, r13, r5, 0);
                    }
                }
            }
            r4 = LD32(r9);
            r0 = GCALL1(0x06027F48, r4);
            ST32(r9, r14);
            r2 = r9 + 22;
            r1 = LD8(r2);
            r0 = 0;
            ST8(r2, (r1 + 1));
            ST32(r9 + 36, 11);
            ST32(r9 + 40, -9);
            ST32(r9 + 44, 1);
        } else {
            r0 = -802;
            ST32(r9 + 40, -802);
        }
    } else {
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603E514(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c8;

    r8 = r4;
    r10 = 0;
    ST8((r8 + 22), 0);
    r1 = LD32(r8 + 44);
    if ((r1 & r1) == 0) {
        r5 = LD32(r8 + 16);
        r0 = GCALL4(0x0603D3DC, r4, r5, 0, r7);
    }
    r9 = 132;
    r4 = LD32(r8 + 132);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x0605A290, r4);
        ST32(r8 + r9, 0);
    }
    r9 = 136;
    r4 = LD32(r8 + 136);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r8 + r9, 0);
    }
    r9 = r8 + 20;
    r1 = LD16(r9);
    if (r1 >= 0) {
        r1 = LD32(r8 + 12);
        r2 = LD32(r8 + 16);
        ST32(r8 + 56, (r1 - r2));
        r2 = 0x060787C8;
        r1 = LD8(0x060787C8);
        r1 = r1 - 1;
        ST8(0x060787C8, r1);
        if (!(((signed char)r1) >= 0)) {
            ST8(r2, r10);
        }
        r4 = LD16(r9);
        r0 = GCALL1(0x0605926C, r4);
        ST16(r9, -1);
        r0 = LD32(r8 + 40);
        if (r0 == -9) {
            r4 = LD32(r8 + 16);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL3(0x06075238, r4, 0x0603D3C0, 3);
                if ((r0 & r0) == 0) {
                    r1 = 3;
                    ST32(r8 + 44, r1);
                } else {
                    r3 = LD32(r8 + 16);
                    r1 = LD8(r3);
                    c8 = (r1 & 255) == 255;
                    r1 = r3;
                    if (!(c8)) {
                        r4 = LD32(r8 + 16);
                        r9 = 0x06075238;
                        r0 = GCALL3(0x06075238, r4, 0x0603D3C4, 4);
                        if ((r0 & r0) == 0) {
                            r1 = 4;
                            ST32(r8 + 44, r1);
                        } else {
                            r4 = LD32(r8 + 16);
                            r0 = GCALL3(r9, r4, 0x0603D3CC, 4);
                            if ((r0 & r0) == 0) {
                                r1 = 4;
                                ST32(r8 + 44, r1);
                            } else {
                                r4 = LD32(r8 + 16);
                                r0 = GCALL3(r9, r4, 0x0603D3D4, 4);
                                if ((r0 & r0) == 0) {
                                    r1 = 4;
                                    ST32(r8 + 44, r1);
                                }
                            }
                        }
                    } else {
                        r1 = LD8((r1 + 1));
                        if (!((r1 & 255) == 216)) {
                            r4 = LD32(r8 + 16);
                            r9 = 0x06075238;
                            r0 = GCALL3(0x06075238, r4, 0x0603D3C4, 4);
                            if ((r0 & r0) == 0) {
                                r1 = 4;
                                ST32(r8 + 44, r1);
                            } else {
                                r4 = LD32(r8 + 16);
                                r0 = GCALL3(r9, r4, 0x0603D3CC, 4);
                                if ((r0 & r0) == 0) {
                                    r1 = 4;
                                    ST32(r8 + 44, r1);
                                } else {
                                    r4 = LD32(r8 + 16);
                                    r0 = GCALL3(r9, r4, 0x0603D3D4, 4);
                                    if ((r0 & r0) == 0) {
                                        r1 = 4;
                                        ST32(r8 + 44, r1);
                                    }
                                }
                            }
                        } else {
                            r1 = 3;
                            ST32(r8 + 44, r1);
                        }
                    }
                }
            }
            r1 = LD32(r8 + 44);
            r11 = 1;
            r0 = 0;
            if ((unsigned)(r1 - 4) > (unsigned)1) {
                r1 = LD32(r8 + 28);
                if (!((r1 & r1) == 0)) {
                    ST32(r8 + 32, r1);
                }
                r10 = r8 + 116;
                r1 = LD32(r10);
                r9 = r8;
                if ((r1 & r1) == 0) {
                    r9 = r8 + 108;
                    r1 = LD32(r9);
                    r8 = r8 + 112;
                    if ((r1 & r1) == 0) {
                        r0 = 0;
                    } else {
                        r4 = LD32(r8);
                        if (!((r4 & r4) == 0)) {
                            r0 = GCALL1(0x06027F48, r4);
                            ST32(r8, 0);
                        }
                        r4 = LD32(r9);
                        r0 = GCALL1(0x0607507C, r4);
                        r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                        r1 = r0;
                        ST32(r8, r1);
                        if (!((r1 & r1) == 0)) {
                            r5 = LD32(r9);
                            r0 = GCALL2(0x060750DC, r1, r5);
                            r0 = 0;
                        } else {
                            r0 = -3;
                        }
                    }
                } else {
                    r9 = r9 + 120;
                    r4 = LD32(r9);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                        ST32(r9, 0);
                    }
                    r4 = LD32(r10);
                    r0 = GCALL1(0x0607507C, r4);
                    r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, r11);
                    r1 = r0;
                    ST32(r9, r1);
                    if ((r1 & r1) == 0) {
                        r0 = -3;
                    } else {
                        r5 = LD32(r10);
                        r0 = GCALL2(0x060750DC, r1, r5);
                        r9 = r8 + 108;
                        r1 = LD32(r9);
                        r8 = r8 + 112;
                        if ((r1 & r1) == 0) {
                            r0 = 0;
                        } else {
                            r4 = LD32(r8);
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(0x06027F48, r4);
                                ST32(r8, 0);
                            }
                            r4 = LD32(r9);
                            r0 = GCALL1(0x0607507C, r4);
                            r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                            r1 = r0;
                            ST32(r8, r1);
                            if (!((r1 & r1) == 0)) {
                                r5 = LD32(r9);
                                r0 = GCALL2(0x060750DC, r1, r5);
                                r0 = 0;
                            } else {
                                r0 = -3;
                            }
                        }
                    }
                }
            }
        } else {
            r0 = 0;
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603FD18(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c5, c7, c9, c11, c17, c21, c29, c33, c37, c38, c41, c42, c44, c45, c47, c48, c51, c52, c54, c55, c60, c62, c63, c65, c1015, c1018, c1023, c1032, c1039, c1048, c1054, c1059, c1062, c1067, c1072, c1075, c1076, c1077, c1090;
    FRAME(sp, 1408);

    r0 = 0x544;
    ST32(0x544 + (sp - 1400), r5);
    r9 = r6;
    ST32((0x548 + (sp - 1400)), r7);
    if (!((r9 & r9) == 0)) {
        r3 = LD32(0x0603FCB8);
        ST32(sp - 1400, r3);
        r2 = LD32(0x0603FCBC);
        ST32(sp - 1396, r2);
        r1 = LD32(0x0603FCC0);
        ST32(sp - 1392, r1);
        r0 = GCALL7(0x06025948, (sp - 1400), 0, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
        r10 = r0;
        r0 = GCALL7(0x060279E0, 1, (r10 + 1), 15, 1, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
        ST32((0x54C + (sp - 1400)), r0);
        r13 = LD32((0x54C + (sp - 1400)));
        r8 = sp - 1400;
        if (!((r13 & r13) == 0)) {
            r8 = r8 + 16;
            r0 = GCALL7(0x0604B3F0, r8, 0, 48, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
            r6 = LD32((0x54C + (sp - 1400)));
            r0 = GCALL7(0x060258EC, (sp - 1400), r8, r6, r10, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
            r0 = GCALL7(0x06025984, r8, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
            r0 = sp - 1400;
            ST8(r0 + 0x2C0, 0);
            ST8(r0 + 0x340, 0);
            ST8(r0 + 192, 0);
            ST8((sp - 1336), 0);
            ST8(r0 + 0x1C0, 0);
            r11 = r9;
            r1 = LD8(r11);
            r0 = r1 & 255;
            while (1) {
                r1 = r11;
                if (r0 == 10) {
                    r1 = LD8((r1 + 1));
                    if ((r1 & 255) == 13) {
                        break;
                    } else {
                        POLL();
                        r1 = LD8(r11);
                        r6 = 8;
                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                            r8 = 0x06075238;
                            r0 = GCALL7(0x06075238, r11, 0x0603F30C, r6, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                            r6 = 5;
                            if (!((r0 & r0) == 0)) {
                                r7 = R(7);
                                r0 = GCALL7(r8, r11, 0x0603F2FC, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                                r6 = 12;
                                if (!((r0 & r0) == 0)) {
                                    r7 = R(7);
                                    r0 = GCALL7(r8, r11, 0x0603FCC4, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                                    r6 = 3;
                                    if (!((r0 & r0) == 0)) {
                                        r7 = R(7);
                                        r0 = GCALL7(r8, r11, 0x0603F2EC, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                                        r6 = 3;
                                        if (!((r0 & r0) == 0)) {
                                            r7 = R(7);
                                            r0 = GCALL7(r8, r11, 0x0603F2E8, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                                            if ((r0 & r0) == 0) {
                                                r11 = r11 + 4;
                                                r2 = LD8(r11);
                                                r0 = r2 & 255;
                                                c47 = r0 == 10;
                                                r3 = 0;
                                                c1075 = c47;
                                                if (!(c47)) {
                                                    c48 = r0 == 13;
                                                    c1075 = c48;
                                                    if (!(c48)) {
                                                        r7 = r2 & 255;
                                                        r1 = 0x340 + (sp - 1400);
                                                        c1067 = (r7 & r7) == 0;
                                                        while (1) {
                                                            r0 = r7;
                                                            c1075 = c1067;
                                                            if (c1067) {
                                                                break;
                                                            } else {
                                                                c51 = r0 == 62;
                                                                c1072 = c51;
                                                                if (r0 == 60) {
                                                                    r11 = r11 + 1;
                                                                } else {
                                                                    c52 = r0 == 32;
                                                                    c1072 = c52;
                                                                    if (c51) {
                                                                        r11 = r11 + 1;
                                                                    } else {
                                                                        r0 = r1;
                                                                        c1072 = c52;
                                                                        if (c52) {
                                                                            r11 = r11 + 1;
                                                                        } else {
                                                                            ST8(r0 + r3, r2);
                                                                            r11 = r11 + 1;
                                                                            r3 = r3 + 1;
                                                                        }
                                                                    }
                                                                }
                                                                r2 = LD8(r11);
                                                                r7 = r2 & 255;
                                                                r0 = r7;
                                                                c54 = r0 == 13;
                                                                c1075 = c54;
                                                                if (r0 == 10) {
                                                                    break;
                                                                } else {
                                                                    c55 = (r7 & r7) == 0;
                                                                    c1067 = c55;
                                                                    c1075 = c55;
                                                                    if (!(c54)) {
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
                                                }
                                                r1 = 0x340;
                                                r0 = sp - 1400;
                                                c1076 = c1075;
                                                r0 = r0 + r1;
                                                r1 = 0;
                                                c1077 = c1076;
                                                ST8(r0 + r3, r1);
                                            }
                                        } else {
                                            r11 = r11 + 4;
                                            r2 = LD8(r11);
                                            r0 = r2 & 255;
                                            c37 = r0 == 10;
                                            r3 = 0;
                                            c1062 = c37;
                                            if (!(c37)) {
                                                c38 = r0 == 13;
                                                c1062 = c38;
                                                if (!(c38)) {
                                                    r7 = r2 & 255;
                                                    r1 = 0x2C0 + (sp - 1400);
                                                    c1054 = (r7 & r7) == 0;
                                                    while (1) {
                                                        r0 = r7;
                                                        c1062 = c1054;
                                                        if (c1054) {
                                                            break;
                                                        } else {
                                                            c41 = r0 == 62;
                                                            c1059 = c41;
                                                            if (r0 == 60) {
                                                                r11 = r11 + 1;
                                                            } else {
                                                                c42 = r0 == 32;
                                                                c1059 = c42;
                                                                if (c41) {
                                                                    r11 = r11 + 1;
                                                                } else {
                                                                    r0 = r1;
                                                                    c1059 = c42;
                                                                    if (c42) {
                                                                        r11 = r11 + 1;
                                                                    } else {
                                                                        ST8(r0 + r3, r2);
                                                                        r11 = r11 + 1;
                                                                        r3 = r3 + 1;
                                                                    }
                                                                }
                                                            }
                                                            r2 = LD8(r11);
                                                            r7 = r2 & 255;
                                                            r0 = r7;
                                                            c44 = r0 == 13;
                                                            c1062 = c44;
                                                            if (r0 == 10) {
                                                                break;
                                                            } else {
                                                                c45 = (r7 & r7) == 0;
                                                                c1054 = c45;
                                                                c1062 = c45;
                                                                if (!(c44)) {
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
                                            }
                                            r1 = 0x2C0;
                                            r0 = sp - 1400;
                                            c1076 = c1062;
                                            r0 = r0 + r1;
                                            r1 = 0;
                                            c1077 = c1076;
                                            ST8(r0 + r3, r1);
                                        }
                                    } else {
                                        r11 = r11 + 13;
                                        r2 = LD8(r11);
                                        r0 = r2 & 255;
                                        r3 = -1;
                                        if (r0 == 10) {
                                            c1048 = r3 >= 0;
                                        } else {
                                            if (r0 == 13) {
                                                c1048 = r3 >= 0;
                                            } else {
                                                r7 = (sp - 1400) + 192;
                                                r1 = r2 & 255;
                                                c1039 = (r1 & r1) == 0;
                                                while (1) {
                                                    if (c1039) {
                                                        c1048 = r3 >= 0;
                                                        break;
                                                    } else {
                                                        r0 = r1;
                                                        c29 = r0 == 62;
                                                        if (!(r0 == 60)) {
                                                            c1048 = r3 >= 0;
                                                            if (c29) {
                                                                break;
                                                            } else {
                                                                if (r3 >= 0) {
                                                                    r1 = LD8(r11);
                                                                    ST8(r7 + r3, r1);
                                                                    r3 = r3 + 1;
                                                                }
                                                                r11 = r11 + 1;
                                                                r2 = LD8(r11);
                                                                r1 = r2 & 255;
                                                                r0 = r1;
                                                                c33 = r0 == 13;
                                                                if (r0 == 10) {
                                                                    c1048 = r3 >= 0;
                                                                    break;
                                                                } else {
                                                                    c1039 = (r1 & r1) == 0;
                                                                    if (!(c33)) {
                                                                        POLL();
                                                                        continue;
                                                                    } else {
                                                                        c1048 = r3 >= 0;
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r3 = 0;
                                                            r11 = r11 + 1;
                                                            if (r3 >= 0) {
                                                                r1 = LD8(r11);
                                                                ST8(r7 + r3, r1);
                                                                r3 = r3 + 1;
                                                            }
                                                            r11 = r11 + 1;
                                                            r2 = LD8(r11);
                                                            r1 = r2 & 255;
                                                            r0 = r1;
                                                            c33 = r0 == 13;
                                                            if (r0 == 10) {
                                                                c1048 = r3 >= 0;
                                                                break;
                                                            } else {
                                                                c1039 = (r1 & r1) == 0;
                                                                if (!(c33)) {
                                                                    POLL();
                                                                    continue;
                                                                } else {
                                                                    c1048 = r3 >= 0;
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    POLL();
                                                }
                                            }
                                        }
                                        r0 = sp - 1400;
                                        if (c1048) {
                                            r1 = 192;
                                            c1076 = 1;
                                            r0 = r0 + r1;
                                            r1 = 0;
                                            c1077 = c1076;
                                            ST8(r0 + r3, r1);
                                        }
                                    }
                                } else {
                                    r11 = r11 + 6;
                                    r2 = LD8(r11);
                                    r0 = r2 & 255;
                                    r3 = -1;
                                    if (r0 == 10) {
                                        c1032 = r3 >= 0;
                                    } else {
                                        if (r0 == 13) {
                                            c1032 = r3 >= 0;
                                        } else {
                                            r7 = (sp - 1400) + 0x1C0;
                                            r1 = r2 & 255;
                                            c1023 = (r1 & r1) == 0;
                                            while (1) {
                                                if (c1023) {
                                                    c1032 = r3 >= 0;
                                                    break;
                                                } else {
                                                    r0 = r1;
                                                    c17 = r0 == 62;
                                                    if (!(r0 == 60)) {
                                                        c1032 = r3 >= 0;
                                                        if (c17) {
                                                            break;
                                                        } else {
                                                            if (r3 >= 0) {
                                                                r1 = LD8(r11);
                                                                ST8(r7 + r3, r1);
                                                                r3 = r3 + 1;
                                                            }
                                                            r11 = r11 + 1;
                                                            r2 = LD8(r11);
                                                            r1 = r2 & 255;
                                                            r0 = r1;
                                                            c21 = r0 == 13;
                                                            if (r0 == 10) {
                                                                c1032 = r3 >= 0;
                                                                break;
                                                            } else {
                                                                c1023 = (r1 & r1) == 0;
                                                                if (!(c21)) {
                                                                    POLL();
                                                                    continue;
                                                                } else {
                                                                    c1032 = r3 >= 0;
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r3 = 0;
                                                        r11 = r11 + 1;
                                                        if (r3 >= 0) {
                                                            r1 = LD8(r11);
                                                            ST8(r7 + r3, r1);
                                                            r3 = r3 + 1;
                                                        }
                                                        r11 = r11 + 1;
                                                        r2 = LD8(r11);
                                                        r1 = r2 & 255;
                                                        r0 = r1;
                                                        c21 = r0 == 13;
                                                        if (r0 == 10) {
                                                            c1032 = r3 >= 0;
                                                            break;
                                                        } else {
                                                            c1023 = (r1 & r1) == 0;
                                                            if (!(c21)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                c1032 = r3 >= 0;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                                POLL();
                                            }
                                        }
                                    }
                                    r0 = sp - 1400;
                                    if (c1032) {
                                        r1 = 0x1C0;
                                        c1076 = 1;
                                        r0 = r0 + r1;
                                        r1 = 0;
                                        c1077 = c1076;
                                        ST8(r0 + r3, r1);
                                    }
                                }
                            } else {
                                r3 = 0;
                                r12 = LD32((0x548 + (sp - 1400)));
                                r11 = r11 + 9;
                                if (!((r12 & r12) == 0)) {
                                    r2 = LD32((0x548 + (sp - 1400)));
                                    c5 = (unsigned)(r2 - 1) > (unsigned)1;
                                    r2 = sp - 1400;
                                    if (!(c5)) {
                                        ST8((r2 + 64), 114);
                                        ST8((sp - 1335), 101);
                                        ST8((sp - 1334), 58);
                                        r3 = 3;
                                    }
                                } else {
                                    ST8((sp - 1336), 102);
                                    ST8((sp - 1335), 119);
                                    ST8((sp - 1334), 100);
                                    ST8((sp - 1333), 58);
                                    r3 = 4;
                                }
                                r2 = LD8(r11);
                                r0 = r2 & 255;
                                c7 = r0 == 13;
                                c1018 = c7;
                                if (!(r0 == 10)) {
                                    r7 = sp - 1400;
                                    c1018 = c7;
                                    if (!(c7)) {
                                        r7 = r7 + 64;
                                        c1015 = ((r2 & 255) & (r2 & 255)) == 0;
                                        while (1) {
                                            r0 = r7;
                                            c1018 = c1015;
                                            if (c1015) {
                                                break;
                                            } else {
                                                ST8(r0 + r3, r2);
                                                r11 = r11 + 1;
                                                r2 = LD8(r11);
                                                r1 = r2 & 255;
                                                r0 = r1;
                                                c9 = r0 == 10;
                                                r3 = r3 + 1;
                                                c1018 = c9;
                                                if (c9) {
                                                    break;
                                                } else {
                                                    c11 = (r1 & r1) == 0;
                                                    c1015 = c11;
                                                    c1018 = c11;
                                                    if (!(r0 == 13)) {
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
                                }
                                r1 = 0;
                                r0 = (sp - 1400) + 64;
                                c1077 = c1018;
                                ST8(r0 + r3, r1);
                            }
                            r11 = r11 + 1;
                            r1 = LD8(r11);
                            r0 = r1 & 255;
                            continue;
                        } else {
                            break;
                        }
                    }
                } else {
                    POLL();
                    r1 = LD8(r11);
                    r6 = 8;
                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                        r8 = 0x06075238;
                        r0 = GCALL7(0x06075238, r11, 0x0603F30C, r6, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                        r6 = 5;
                        if (!((r0 & r0) == 0)) {
                            r7 = R(7);
                            r0 = GCALL7(r8, r11, 0x0603F2FC, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                            r6 = 12;
                            if (!((r0 & r0) == 0)) {
                                r7 = R(7);
                                r0 = GCALL7(r8, r11, 0x0603FCC4, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                                r6 = 3;
                                if (!((r0 & r0) == 0)) {
                                    r7 = R(7);
                                    r0 = GCALL7(r8, r11, 0x0603F2EC, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                                    r6 = 3;
                                    if (!((r0 & r0) == 0)) {
                                        r7 = R(7);
                                        r0 = GCALL7(r8, r11, 0x0603F2E8, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                                        if ((r0 & r0) == 0) {
                                            r11 = r11 + 4;
                                            r2 = LD8(r11);
                                            r0 = r2 & 255;
                                            c47 = r0 == 10;
                                            r3 = 0;
                                            c1075 = c47;
                                            if (!(c47)) {
                                                c48 = r0 == 13;
                                                c1075 = c48;
                                                if (!(c48)) {
                                                    r7 = r2 & 255;
                                                    r1 = 0x340 + (sp - 1400);
                                                    c1067 = (r7 & r7) == 0;
                                                    while (1) {
                                                        r0 = r7;
                                                        c1075 = c1067;
                                                        if (c1067) {
                                                            break;
                                                        } else {
                                                            c51 = r0 == 62;
                                                            c1072 = c51;
                                                            if (r0 == 60) {
                                                                r11 = r11 + 1;
                                                            } else {
                                                                c52 = r0 == 32;
                                                                c1072 = c52;
                                                                if (c51) {
                                                                    r11 = r11 + 1;
                                                                } else {
                                                                    r0 = r1;
                                                                    c1072 = c52;
                                                                    if (c52) {
                                                                        r11 = r11 + 1;
                                                                    } else {
                                                                        ST8(r0 + r3, r2);
                                                                        r11 = r11 + 1;
                                                                        r3 = r3 + 1;
                                                                    }
                                                                }
                                                            }
                                                            r2 = LD8(r11);
                                                            r7 = r2 & 255;
                                                            r0 = r7;
                                                            c54 = r0 == 13;
                                                            c1075 = c54;
                                                            if (r0 == 10) {
                                                                break;
                                                            } else {
                                                                c55 = (r7 & r7) == 0;
                                                                c1067 = c55;
                                                                c1075 = c55;
                                                                if (!(c54)) {
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
                                            }
                                            r1 = 0x340;
                                            r0 = sp - 1400;
                                            c1076 = c1075;
                                            r0 = r0 + r1;
                                            r1 = 0;
                                            c1077 = c1076;
                                            ST8(r0 + r3, r1);
                                        }
                                    } else {
                                        r11 = r11 + 4;
                                        r2 = LD8(r11);
                                        r0 = r2 & 255;
                                        c37 = r0 == 10;
                                        r3 = 0;
                                        c1062 = c37;
                                        if (!(c37)) {
                                            c38 = r0 == 13;
                                            c1062 = c38;
                                            if (!(c38)) {
                                                r7 = r2 & 255;
                                                r1 = 0x2C0 + (sp - 1400);
                                                c1054 = (r7 & r7) == 0;
                                                while (1) {
                                                    r0 = r7;
                                                    c1062 = c1054;
                                                    if (c1054) {
                                                        break;
                                                    } else {
                                                        c41 = r0 == 62;
                                                        c1059 = c41;
                                                        if (r0 == 60) {
                                                            r11 = r11 + 1;
                                                        } else {
                                                            c42 = r0 == 32;
                                                            c1059 = c42;
                                                            if (c41) {
                                                                r11 = r11 + 1;
                                                            } else {
                                                                r0 = r1;
                                                                c1059 = c42;
                                                                if (c42) {
                                                                    r11 = r11 + 1;
                                                                } else {
                                                                    ST8(r0 + r3, r2);
                                                                    r11 = r11 + 1;
                                                                    r3 = r3 + 1;
                                                                }
                                                            }
                                                        }
                                                        r2 = LD8(r11);
                                                        r7 = r2 & 255;
                                                        r0 = r7;
                                                        c44 = r0 == 13;
                                                        c1062 = c44;
                                                        if (r0 == 10) {
                                                            break;
                                                        } else {
                                                            c45 = (r7 & r7) == 0;
                                                            c1054 = c45;
                                                            c1062 = c45;
                                                            if (!(c44)) {
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
                                        }
                                        r1 = 0x2C0;
                                        r0 = sp - 1400;
                                        c1076 = c1062;
                                        r0 = r0 + r1;
                                        r1 = 0;
                                        c1077 = c1076;
                                        ST8(r0 + r3, r1);
                                    }
                                } else {
                                    r11 = r11 + 13;
                                    r2 = LD8(r11);
                                    r0 = r2 & 255;
                                    r3 = -1;
                                    if (r0 == 10) {
                                        c1048 = r3 >= 0;
                                    } else {
                                        if (r0 == 13) {
                                            c1048 = r3 >= 0;
                                        } else {
                                            r7 = (sp - 1400) + 192;
                                            r1 = r2 & 255;
                                            c1039 = (r1 & r1) == 0;
                                            while (1) {
                                                if (c1039) {
                                                    c1048 = r3 >= 0;
                                                    break;
                                                } else {
                                                    r0 = r1;
                                                    c29 = r0 == 62;
                                                    if (!(r0 == 60)) {
                                                        c1048 = r3 >= 0;
                                                        if (c29) {
                                                            break;
                                                        } else {
                                                            if (r3 >= 0) {
                                                                r1 = LD8(r11);
                                                                ST8(r7 + r3, r1);
                                                                r3 = r3 + 1;
                                                            }
                                                            r11 = r11 + 1;
                                                            r2 = LD8(r11);
                                                            r1 = r2 & 255;
                                                            r0 = r1;
                                                            c33 = r0 == 13;
                                                            if (r0 == 10) {
                                                                c1048 = r3 >= 0;
                                                                break;
                                                            } else {
                                                                c1039 = (r1 & r1) == 0;
                                                                if (!(c33)) {
                                                                    POLL();
                                                                    continue;
                                                                } else {
                                                                    c1048 = r3 >= 0;
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r3 = 0;
                                                        r11 = r11 + 1;
                                                        if (r3 >= 0) {
                                                            r1 = LD8(r11);
                                                            ST8(r7 + r3, r1);
                                                            r3 = r3 + 1;
                                                        }
                                                        r11 = r11 + 1;
                                                        r2 = LD8(r11);
                                                        r1 = r2 & 255;
                                                        r0 = r1;
                                                        c33 = r0 == 13;
                                                        if (r0 == 10) {
                                                            c1048 = r3 >= 0;
                                                            break;
                                                        } else {
                                                            c1039 = (r1 & r1) == 0;
                                                            if (!(c33)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                c1048 = r3 >= 0;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                                POLL();
                                            }
                                        }
                                    }
                                    r0 = sp - 1400;
                                    if (c1048) {
                                        r1 = 192;
                                        c1076 = 1;
                                        r0 = r0 + r1;
                                        r1 = 0;
                                        c1077 = c1076;
                                        ST8(r0 + r3, r1);
                                    }
                                }
                            } else {
                                r11 = r11 + 6;
                                r2 = LD8(r11);
                                r0 = r2 & 255;
                                r3 = -1;
                                if (r0 == 10) {
                                    c1032 = r3 >= 0;
                                } else {
                                    if (r0 == 13) {
                                        c1032 = r3 >= 0;
                                    } else {
                                        r7 = (sp - 1400) + 0x1C0;
                                        r1 = r2 & 255;
                                        c1023 = (r1 & r1) == 0;
                                        while (1) {
                                            if (c1023) {
                                                c1032 = r3 >= 0;
                                                break;
                                            } else {
                                                r0 = r1;
                                                c17 = r0 == 62;
                                                if (!(r0 == 60)) {
                                                    c1032 = r3 >= 0;
                                                    if (c17) {
                                                        break;
                                                    } else {
                                                        if (r3 >= 0) {
                                                            r1 = LD8(r11);
                                                            ST8(r7 + r3, r1);
                                                            r3 = r3 + 1;
                                                        }
                                                        r11 = r11 + 1;
                                                        r2 = LD8(r11);
                                                        r1 = r2 & 255;
                                                        r0 = r1;
                                                        c21 = r0 == 13;
                                                        if (r0 == 10) {
                                                            c1032 = r3 >= 0;
                                                            break;
                                                        } else {
                                                            c1023 = (r1 & r1) == 0;
                                                            if (!(c21)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                c1032 = r3 >= 0;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    r3 = 0;
                                                    r11 = r11 + 1;
                                                    if (r3 >= 0) {
                                                        r1 = LD8(r11);
                                                        ST8(r7 + r3, r1);
                                                        r3 = r3 + 1;
                                                    }
                                                    r11 = r11 + 1;
                                                    r2 = LD8(r11);
                                                    r1 = r2 & 255;
                                                    r0 = r1;
                                                    c21 = r0 == 13;
                                                    if (r0 == 10) {
                                                        c1032 = r3 >= 0;
                                                        break;
                                                    } else {
                                                        c1023 = (r1 & r1) == 0;
                                                        if (!(c21)) {
                                                            POLL();
                                                            continue;
                                                        } else {
                                                            c1032 = r3 >= 0;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                            POLL();
                                        }
                                    }
                                }
                                r0 = sp - 1400;
                                if (c1032) {
                                    r1 = 0x1C0;
                                    c1076 = 1;
                                    r0 = r0 + r1;
                                    r1 = 0;
                                    c1077 = c1076;
                                    ST8(r0 + r3, r1);
                                }
                            }
                        } else {
                            r3 = 0;
                            r12 = LD32((0x548 + (sp - 1400)));
                            r11 = r11 + 9;
                            if (!((r12 & r12) == 0)) {
                                r2 = LD32((0x548 + (sp - 1400)));
                                c5 = (unsigned)(r2 - 1) > (unsigned)1;
                                r2 = sp - 1400;
                                if (!(c5)) {
                                    ST8((r2 + 64), 114);
                                    ST8((sp - 1335), 101);
                                    ST8((sp - 1334), 58);
                                    r3 = 3;
                                }
                            } else {
                                ST8((sp - 1336), 102);
                                ST8((sp - 1335), 119);
                                ST8((sp - 1334), 100);
                                ST8((sp - 1333), 58);
                                r3 = 4;
                            }
                            r2 = LD8(r11);
                            r0 = r2 & 255;
                            c7 = r0 == 13;
                            c1018 = c7;
                            if (!(r0 == 10)) {
                                r7 = sp - 1400;
                                c1018 = c7;
                                if (!(c7)) {
                                    r7 = r7 + 64;
                                    c1015 = ((r2 & 255) & (r2 & 255)) == 0;
                                    while (1) {
                                        r0 = r7;
                                        c1018 = c1015;
                                        if (c1015) {
                                            break;
                                        } else {
                                            ST8(r0 + r3, r2);
                                            r11 = r11 + 1;
                                            r2 = LD8(r11);
                                            r1 = r2 & 255;
                                            r0 = r1;
                                            c9 = r0 == 10;
                                            r3 = r3 + 1;
                                            c1018 = c9;
                                            if (c9) {
                                                break;
                                            } else {
                                                c11 = (r1 & r1) == 0;
                                                c1015 = c11;
                                                c1018 = c11;
                                                if (!(r0 == 13)) {
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
                            }
                            r1 = 0;
                            r0 = (sp - 1400) + 64;
                            c1077 = c1018;
                            ST8(r0 + r3, r1);
                        }
                        r11 = r11 + 1;
                        r1 = LD8(r11);
                        r0 = r1 & 255;
                        continue;
                    } else {
                        break;
                    }
                }
            }
            r11 = r11 + 3;
            r1 = LD8(192 + (sp - 1400));
            r4 = (sp - 1400) + 192;
            if (((r1 & 255) & (r1 & 255)) == 0) {
                r1 = LD8(0x1C0 + (sp - 1400));
                r5 = (sp - 1400) + 0x1C0;
                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                    r0 = GCALL7(0x060750DC, r4, r5, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                }
            }
            r8 = 0x540;
            ST32((sp - 1400) + 0x540, 0);
            r12 = LD32((0x548 + (sp - 1400)));
            c60 = (r12 & r12) == 0;
            r4 = (sp - 1400) + 0x540;
            c1090 = c60;
            if (c60) {
                r0 = 0x06018688;
                r7 = 1;
                r6 = 0;
                r0 = GCALL7(r0, r4, r11, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                c63 = (r0 & r0) == 0;
                r0 = sp - 1400;
                if (!(c63)) {
                    r11 = LD32(r0 + r8);
                }
            } else {
                r0 = LD32(0x548 + (sp - 1400));
                r7 = 0;
                if (!(r0 == 4)) {
                    r1 = LD8(0x0608AF51);
                    c62 = (r1 & r1) == 0;
                    r1 = 0;
                    c1090 = c62;
                    if (c62) {
                        ST8(r11, r1);
                    } else {
                        r0 = 0x06018688;
                        r7 = 1;
                        r6 = 0;
                        r0 = GCALL7(r0, r4, r11, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                        c63 = (r0 & r0) == 0;
                        r0 = sp - 1400;
                        if (!(c63)) {
                            r11 = LD32(r0 + r8);
                        }
                    }
                } else {
                    r0 = 0x06018688;
                    r6 = 0;
                    r0 = GCALL7(r0, r4, r11, r6, r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                    c63 = (r0 & r0) == 0;
                    r0 = sp - 1400;
                    if (!(c63)) {
                        r11 = LD32(r0 + r8);
                    }
                }
            }
            r1 = 4;
            if (!((r11 & r11) == 0)) {
                r12 = LD32((0x548 + (sp - 1400)));
                c65 = (unsigned)r12 > (unsigned)r1;
                r1 = 0;
                if (!(c65)) {
                    r1 = LD32((0x548 + (sp - 1400)));
                    r1 = LD16(0x060400F0 + (r1 + r1));
                    switch (r1) {
                    case 36:
                        r1 = LD32(0x0603FCD4);
                        ST32(0x3C0 + (sp - 1400), r1);
                        r1 = LD32(0x0603FCD8);
                        ST32(((sp - 1400) + 0x3C0) + 4, r1);
                        r1 = 0;
                        ST8(192 + (sp - 1400), 0);
                        break;
                    case 60:
                        r2 = LD32(0x0603FCDC);
                        ST32(0x3C0 + (sp - 1400), r2);
                        r1 = LD16(0x0603FCE0);
                        ST16((((sp - 1400) + 0x3C0) + 4), r1);
                        r1 = 0;
                        break;
                    case 80:
                        r7 = (sp - 1400) + 0x3C0;
                        r3 = LD32(0x0603FCE4);
                        ST32(0x3C0 + (sp - 1400), r3);
                        r1 = LD32(0x0603FCE8);
                        ST32(r7 + 4, r1);
                        r1 = LD16(0x0603FCEC);
                        ST16((r7 + 8), r1);
                        r9 = (sp - 1400) + 192;
                        r8 = (sp - 1400) + 0x440;
                        ST32((sp - 1404), (0x340 + (sp - 1400)));
                        r0 = GCALL8(0x06045264, r8, 0x0603FCF0, r9, ((sp - 1400) + 0x2C0), LD32((sp - 1404)), LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                        r0 = GCALL8(0x060750DC, r9, r8, 0, 0, LD32((sp - 1404)), LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                        r1 = 0;
                        break;
                    case 152:
                        r11 = 0;
                        r6 = sp - 1400;
                        r5 = 0x0603FD04;
                        r1 = LD32(0x0603FCFC);
                        r8 = sp - 1400;
                        ST32(0x3C0 + (sp - 1400), r1);
                        r1 = LD32(0x0603FD00);
                        r0 = 0x06045264;
                        ST32(((sp - 1400) + 0x3C0) + 4, r1);
                        ST8((sp - 1336), 0);
                        r8 = r8 + 0x440;
                        r7 = R(7);
                        r0 = GCALL7(r0, r8, r5, (r6 + 0x2C0), r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                        r0 = GCALL7(0x060750DC, (sp - 1208), r8, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                        r1 = 0;
                        break;
                    case 188:
                        r7 = (sp - 1400) + 0x3C0;
                        r6 = sp - 1400;
                        r5 = 0x0603FD04;
                        r3 = LD32(0x0603FD08);
                        r8 = sp - 1400;
                        ST32(0x3C0 + (sp - 1400), r3);
                        r2 = LD32(0x0603FD0C);
                        ST32(r7 + 4, r2);
                        r2 = LD32(0x0603FD10);
                        r7 = r7 + 8;
                        ST32(r7, r2);
                        r1 = LD32(0x0603FD14);
                        r0 = 0x06045264;
                        ST32(r7 + 4, r1);
                        r8 = r8 + 0x440;
                        r7 = R(7);
                        r0 = GCALL7(r0, r8, r5, (r6 + 0x2C0), r7, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                        r0 = GCALL7(0x060750DC, (sp - 1208), r8, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                        r1 = 0;
                        break;
                    }
                }
                r13 = LD32((0x54C + (sp - 1400)));
                ST8(r10 + r13, r1);
                r0 = GCALL7(0x0607507C, r11, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                r8 = r0;
                r14 = (sp - 1400) + 192;
                r0 = GCALL7(0x0607507C, r14, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                ST32(0x554 + (sp - 1400), (sp - 1336));
                r4 = LD32((0x554 + (sp - 1400)));
                r8 = r8 + r0;
                r0 = GCALL7(0x0607507C, r4, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                r8 = r8 + r0;
                ST32(0x550 + (sp - 1400), (0x3C0 + (sp - 1400)));
                r4 = LD32((0x550 + (sp - 1400)));
                r0 = GCALL7(0x0607507C, r4, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                r10 = (r10 + 1) + (r8 + r0);
                r0 = GCALL7(0x060279E0, 1, r10, 15, 1, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                r1 = r0;
                r12 = LD32(0x544 + (sp - 1400));
                ST32(r12, r1);
                if ((r1 & r1) == 0) {
                    r4 = LD32(0x540 + (sp - 1400));
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL7(0x06027F48, r4, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                    r4 = LD32(0x54C + (sp - 1400));
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL7(0x06027F48, r4, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                } else {
                    r0 = LD32(0x548 + (sp - 1400));
                    r7 = r14;
                    if (!(r0 == 3)) {
                        ST32((sp - 1404), r11);
                        r0 = LD32((0x558 + (sp - 1404)));
                        ST32((sp - 1408), r0);
                        r6 = LD32((0x558 + (sp - 1408)));
                        r5 = LD32((0x554 + (sp - 1408)));
                        r0 = GCALL8(0x06045264, r1, r5, r6, r7, LD32((sp - 1408)), LD32((sp - 1404)), LD32((sp - 1400)), LD32((sp - 1396)));
                    } else {
                        r12 = LD32((0x554 + (sp - 1400)));
                        ST32((sp - 1404), r12);
                        r13 = LD32((0x558 + (sp - 1404)));
                        ST32((sp - 1408), r13);
                        r6 = LD32(0x558 + (sp - 1408));
                        r5 = LD32((0x554 + (sp - 1408)));
                        r0 = GCALL8(0x06045264, r1, r5, r6, r7, LD32((sp - 1408)), LD32((sp - 1404)), LD32((sp - 1400)), LD32((sp - 1396)));
                    }
                    r13 = LD32((0x544 + (sp - 1400)));
                    r1 = LD32(r13);
                    r0 = sp - 1400;
                    ST8(((r1 + r10) - 1), 0);
                    r4 = LD32(r0 + 0x540);
                    if (!((r4 & r4) == 0)) {
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL7(0x06027F48, r4, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                    }
                    r12 = LD32((0x54C + (sp - 1400)));
                    if (!((r12 & r12) == 0)) {
                        r4 = LD32((0x54C + (sp - 1400)));
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL7(0x06027F48, r4, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
                    }
                }
            } else {
                r4 = LD32(0x54C + (sp - 1400));
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL7(0x06027F48, r4, 0, 0, 0, LD32((sp - 1400)), LD32((sp - 1396)), LD32((sp - 1392)));
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603F0C8(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r10, r11, r12, c2, c2008;

    r8 = R(8);
    r10 = r4;
    r4 = (short)r5;
    if (!((r4 & r4) == 0)) {
        c2008 = R(8);
        SETR(8, r8);
        r0 = GCALL1(0x060743C8, r4);
        SETR(8, c2008);
        r8 = LD32(r10 + 8);
        r11 = r0;
        r1 = R(1);
        r12 = r1;
        c2008 = R(8);
        SETR(8, r8);
        r0 = GCALL1(0x060743C8, r8);
        SETR(8, c2008);
        r4 = r0;
        r1 = R(1);
        r5 = r1;
        if (!(r8 >= 0)) {
            r6 = LD32(0x0603F0B8);
            r7 = LD32(0x0603F0BC);
            r0 = GCALL4(0x060739C0, r4, r5, r6, r7);
            r4 = r0;
            r1 = R(1);
            r5 = r1;
        }
        r0 = GCALL4(0x06073E18, r11, r12, r4, r5);
        r1 = R(1);
        r6 = LD32(0x0603F0C0);
        r7 = LD32(0x0603F0C4);
        r0 = GCALL4(0x06073FDC, r0, r1, r6, r7);
        r1 = R(1);
        r0 = GCALL2(0x06074454, r0, r1);
        r1 = LD16((r10 + 12));
        c2 = r0 * r1;
        r1 = LD32(r10 + 24);
        r2 = c2;
        if ((unsigned)r2 >= (unsigned)r1) {
            r0 = -415;
        } else {
            r1 = LD32(r10 + 20);
            ST32(r10 + 20, (r1 + r2));
            r1 = LD32(r10 + 24);
            r0 = 0;
            ST32(r10 + 24, (r1 - r2));
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06031E00(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, c19, c1007;

    r9 = r4;
    r11 = r5;
    r12 = r6;
    r0 = 0;
    if (!((unsigned)r11 > (unsigned)130)) {
        r2 = r11;
        if (!((unsigned)(r12 - 8) > (unsigned)29)) {
            r2 = r2 - 7;
            ST32(r9 + 28, r2);
            if (r2 >= 0) {
                r1 = LD32(r9 + 32);
                ST32(r9 + 28, ((((((int)(((long long)(r2 * r1) * 0x10624DD3) >> 32)) >> 1) >> 1) >> 1) - ((((r2 * r1) << 1) - ((r2 * r1) << 1)) - ((unsigned)(r2 * r1) >> 31))));
            } else {
                ST32(r9 + 28, r0);
            }
            r10 = r9 + 2;
            r0 = LD16(r10);
            c1007 = r0 == -1;
            if (r0 == 2) {
                r8 = r9 + 20;
                r4 = LD16(r8);
                r0 = GCALL1(0x06031D74, r4);
                ST16(r8, -1);
                r0 = LD16(r10);
                c1007 = r0 == -1;
            }
            r1 = 2;
            if (c1007) {
                ST16(r10, r1);
            }
            r0 = LD16(r10);
            if (r0 == 2) {
                r5 = LD32(r9 + 28);
                r0 = GCALL4(0x060314EC, r9, r5, 0, 0);
            }
        }
    }
    r8 = 0x06031DB0;
    r0 = GCALL3(0x06031DB0, 1, r11, r12);
    r6 = r12;
    if ((r0 & r0) == 0) {
        r0 = GCALL3(r8, 2, r11, r6);
        r10 = r9;
        if (!((r0 & r0) == 0)) {
            r10 = r10 + 2;
            r1 = LD16(r10);
            r0 = (short)r1;
            c19 = r0 == 2;
            if (!(r0 == -1)) {
                r2 = 1;
                if (!(c19)) {
                    if (!((unsigned)((r1 - 5) & 0xFFFF) > (unsigned)r2)) {
                        r5 = LD32(r9 + 28);
                        r0 = GCALL4(0x060314EC, r9, r5, 0, 0);
                        r8 = r9;
                        if (!((r0 & r0) == 0)) {
                            r8 = r8 + 20;
                            r4 = LD16(r8);
                            r0 = GCALL1(0x06031D74, r4);
                            ST16(r8, -1);
                            ST16(r9, -1);
                            ST16(r10, -1);
                            r1 = 0;
                            ST32(r9 + 28, r1);
                        } else {
                            ST16(r10, 2);
                            r1 = LD32(0x06089CB8);
                            ST32(r9 + 24, r1);
                        }
                    }
                } else {
                    ST16(r10, 5);
                    ST16((r9 + 8), 10);
                    r8 = r9 + 20;
                    r4 = LD16(r8);
                    r0 = GCALL1(0x06031D74, r4);
                    ST16(r8, -1);
                    r2 = LD32(0x06089CB8);
                    r1 = LD32(r9 + 24);
                    r2 = r2 - r1;
                    r1 = LD32(r9 + 28);
                    r1 = r1 + r2;
                    ST32(r9 + 28, r1);
                }
            } else {
                ST16(r10, 2);
                ST32(r9 + 28, 0);
                r0 = GCALL4(0x060314EC, r9, 0, 0, 0);
            }
        }
    } else {
        r10 = 0x06032164;
        r0 = GCALL1(0x06032164, 3);
        r2 = LD32(r9);
        r1 = 0;
        if (r2 == -65534) {
            r8 = r9 + 20;
            r4 = LD16(r8);
            r0 = GCALL1(0x06031D74, r4);
            ST16(r8, -1);
            r1 = 0;
        }
        ST32(r9 + 24, r1);
        ST32(r9 + 28, r1);
        ST16(r9, 1);
        ST16((r9 + 2), -1);
        ST16((r9 + 8), 6);
        r0 = GCALL1(r10, 3);
    }
    r0 = GCALL3(0x06031DB0, 0, r11, r12);
    r1 = r9;
    if (!((r0 & r0) == 0)) {
        r0 = LD16((r1 + 2));
        r2 = r9;
        if (r0 == 2) {
            r8 = r9 + 20;
            r4 = LD16(r8);
            r0 = GCALL1(0x06031D74, r4);
            ST16(r8, -1);
            r1 = LD32(0x06089CB8);
            r2 = LD32(r9 + 24);
            r5 = LD32(r9 + 28);
            r5 = r5 + (r1 - r2);
            ST32(r9 + 28, r5);
            r0 = GCALL4(0x060314EC, r9, r5, 1, 1);
            r2 = r9;
        }
        ST16((r2 + 6), 0);
    }
    r0 = GCALL3(0x06031DB0, 3, r11, r12);
    r1 = r9;
    if (!((r0 & r0) == 0)) {
        r0 = LD16((r1 + 2));
        r2 = r9;
        if (r0 == 2) {
            r8 = r9 + 20;
            r4 = LD16(r8);
            r0 = GCALL1(0x06031D74, r4);
            ST16(r8, -1);
            r1 = LD32(0x06089CB8);
            r2 = LD32(r9 + 24);
            r5 = LD32(r9 + 28);
            r5 = r5 + (r1 - r2);
            ST32(r9 + 28, r5);
            r0 = GCALL4(0x060314EC, r9, r5, 1, 0);
            r2 = r9;
        }
        ST16((r2 + 4), 3);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06032DEC(int r4)
{
    int r0, r1, r2, r3, r7, r8;
    long long m0;
    FRAME(sp, 16);

    r1 = LD32(r4 + 20);
    r8 = r1 + 0x76C;
    if (!(r8 > 0x7BB)) {
        r8 = r8 + 100;
    }
    r7 = LD32(r4);
    ST8(sp - 16, ((((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) << 2) + (r7 - ((((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) + (((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31)))) + (((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) + (((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))))))));
    r7 = LD32(r4 + 4);
    ST8((sp - 15), ((((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) << 2) + (r7 - ((((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) + (((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31)))) + (((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) + (((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))))))));
    r7 = LD32(r4 + 8);
    ST8((sp - 14), ((((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) << 2) + (r7 - ((((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) + (((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31)))) + (((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) + (((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))))))));
    r7 = LD32(r4 + 12);
    ST8((sp - 13), ((((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) << 2) + (r7 - ((((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) + (((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31)))) + (((((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))) << 2) + (((((int)(((long long)r7 * 0x66666667) >> 32)) >> 1) >> 1) - (((r7 << 1) - (r7 << 1)) - ((unsigned)r7 >> 31))))))));
    r2 = LD32(r4 + 24);
    r1 = LD32(r4 + 16);
    m0 = (long long)r8 * 0x51EB851F;
    ST8((sp - 12), (((r2 << 2) << 2) + (r1 + 1)));
    r0 = ((r8 << 1) - (r8 << 1)) - ((unsigned)r8 >> 31);
    r3 = (((((((int)(m0 >> 32)) >> 1) >> 1) >> 1) >> 1) >> 1) - r0;
    ST8((sp - 11), ((((((((int)(((long long)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) * 0x66666667) >> 32)) >> 1) >> 1) - ((((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1) - ((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1)) - ((unsigned)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) >> 31))) << 2) << 2) + ((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) - ((((((((int)(((long long)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) * 0x66666667) >> 32)) >> 1) >> 1) - ((((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1) - ((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1)) - ((unsigned)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) >> 31))) << 2) + (((((int)(((long long)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) * 0x66666667) >> 32)) >> 1) >> 1) - ((((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1) - ((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1)) - ((unsigned)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) >> 31)))) + (((((((int)(((long long)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) * 0x66666667) >> 32)) >> 1) >> 1) - ((((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1) - ((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1)) - ((unsigned)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) >> 31))) << 2) + (((((int)(((long long)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) * 0x66666667) >> 32)) >> 1) >> 1) - ((((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1) - ((r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) << 1)) - ((unsigned)(r8 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)(r3 * 100)))) >> 31))))))));
    r4 = HELPER((int)((int)(((long long)r8 * 0x10624DD3) >> 32)) >> 6);
    ST8((sp - 10), ((((r4 - r0) << 2) << 2) + (r3 - ((((r4 - r0) << 2) + (r4 - r0)) + (((r4 - r0) << 2) + (r4 - r0))))));
    r1 = 0x20100063;
    do {
        r0 = LD8(r1);
    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    ST8(0x20100063, 1);
    r1 = LD8(sp - 16);
    ST8(0x2010000D, r1);
    r1 = LD8((sp - 15));
    ST8(0x2010000B, r1);
    r1 = LD8((sp - 14));
    ST8(0x20100009, r1);
    r1 = LD8((sp - 13));
    ST8(0x20100007, r1);
    r1 = LD8((sp - 12));
    ST8(0x20100005, r1);
    r1 = LD8((sp - 11));
    ST8(0x20100003, r1);
    r1 = LD8((sp - 10));
    ST8(0x20100001, r1);
    ST8(0x2010001F, 22);
    r0 = LD8(0x20100063);
    r0 = r0 & 1;
    r1 = 0x20100063;
    if (!((r0 & r0) == 0)) {
        do {
            r0 = LD8(r1);
            r0 = r0 & 1;
        } while (AGAIN(!((r0 & r0) == 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603D540(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, c11, c1008;

    r8 = r4;
    r13 = r5;
    r12 = r6;
    r0 = LD32(r8 + 44);
    r9 = 0;
    if (r0 == 6) {
        r0 = -800;
    } else {
        r1 = 12;
        if (!(r0 == 8)) {
            ST32(r8 + 36, r1);
            r1 = LD32(r8 + 56);
            r7 = r8;
            if (!(r1 > 0)) {
                ST32(r8 + 56, 0x2800);
            }
            r3 = LD32(r8 + 56);
            ST32((r7 + 72), (r3 + ((((((int)(((long long)r3 * 0x66666667) >> 32)) >> 1) >> 1) >> 1) - (((r3 << 1) - (r3 << 1)) - ((unsigned)r3 >> 31)))));
            r0 = LD32(r8 + 44);
            r2 = 1;
            c11 = r0 == 7;
            if (!((unsigned)(r0 - 3) > (unsigned)1)) {
                r9 = r2;
                c1008 = (r9 & r9) == 0;
            } else {
                c1008 = (r9 & r9) == 0;
                if (c11) {
                    r9 = r2;
                    c1008 = (r9 & r9) == 0;
                }
            }
            r10 = r8;
            if (c1008) {
                r2 = LD32((r8 + 72));
                if (r2 > 0x4000) {
                    r9 = 1;
                    r10 = r8;
                }
            }
            r10 = r10 + 72;
            r5 = LD32(r10);
            r11 = 0x060279E0;
            r0 = GCALL4(0x060279E0, r9, r5, 6, 1);
            ST32(r8 + 16, r0);
            if (!((r0 & r0) == 0)) {
                r1 = LD32(r8 + 16);
                r2 = LD32(r8 + 16);
                ST32(r8 + 12, r1);
                ST32(r8 + 60, 0);
                ST8(r2, 0);
                if (r12 > 0) {
                    r4 = LD32(r8 + 12);
                    r0 = GCALL3(0x0604B358, r4, r13, r12);
                }
                r0 = 0;
            } else {
                r5 = LD32(r10);
                r0 = GCALL4(r11, ((r9 & r9) == 0), r5, 6, 1);
                ST32(r8 + 16, r0);
                if (!((r0 & r0) == 0)) {
                    r1 = LD32(r8 + 16);
                    r2 = LD32(r8 + 16);
                    ST32(r8 + 12, r1);
                    ST32(r8 + 60, 0);
                    ST8(r2, 0);
                    if (r12 > 0) {
                        r4 = LD32(r8 + 12);
                        r0 = GCALL3(0x0604B358, r4, r13, r12);
                    }
                    r0 = 0;
                } else {
                    r0 = -3;
                    ST32(r8 + 40, -3);
                }
            }
        } else {
            r0 = -800;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030210(int r4)
{
    int r0, r1, r2, r3, r6, r7, c1, c2;
    long long m0;

    r4 = r4 & 0xFFFF;
    r0 = 0;
    r6 = 92;
    r7 = 0x06087DD8;
    r3 = 3;
    m0 = (unsigned)((short)0 * (short)92);
    while (1) {
        r2 = ((int)m0) + r7;
        r1 = LD32(r2);
        c1 = (r1 & r1) == 0;
        r1 = r0;
        if (c1) {
            r0 = (short)(r1 + 1);
            m0 = (unsigned)((short)r0 * (short)r6);
            if (!(r0 > r3)) {
                POLL();
                continue;
            } else {
                return -1;
            }
        } else {
            r1 = LD16((r2 + 20));
            c2 = (r1 & 0xFFFF) == r4;
            r1 = r0;
            if (c2) {
                return r0;
            } else {
                r0 = (short)(r1 + 1);
                m0 = (unsigned)((short)r0 * (short)r6);
                if (!(r0 > r3)) {
                    POLL();
                    continue;
                } else {
                    return -1;
                }
            }
        }
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030DD8(void)
{
    int r1, r2, r3, r5, r6, r7, c1;
    long long m0;

    r3 = 0;
    r5 = 12;
    r7 = 0x06087F48;
    r6 = 0x06089CB8;
    m0 = (unsigned)((short)0 * (short)12);
    while (1) {
        r2 = ((int)m0) + r7;
        r1 = LD32(r2);
        c1 = (r1 & r1) == 0;
        r1 = r3;
        if (c1) {
            r3 = (short)(r1 + 1);
            m0 = (unsigned)((short)r3 * (short)r5);
            if (!(r3 > 3)) {
                POLL();
                continue;
            } else {
                return -1;
            }
        } else {
            r2 = LD32(r2 + 8);
            r1 = LD32(r6);
            r2 = r2 - r1;
            if (!(r2 >= 0)) {
                r2 = -r2;
            }
            r1 = r3;
            if (!(r2 > 1)) {
                r3 = (short)(r1 + 1);
                m0 = (unsigned)((short)r3 * (short)r5);
                if (!(r3 > 3)) {
                    POLL();
                    continue;
                } else {
                    return -1;
                }
            } else {
                ST32(((int)m0) + r7, 0);
                return r3;
            }
        }
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060321BC(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, c0, c2, c13, c1001, c1015, c2008;
    FRAME(sp, 112);

    r8 = R(8);
    ST32(sp - 60, r4);
    ST32((64 + (sp - 112)), 0);
    r13 = 0;
    r0 = GCALL1(0x060683F0, 15);
    r10 = LD32(sp - 60);
    ST32(sp - 52, ((((r0 & 0xFFFF) << 2) + ((r0 & 0xFFFF) << 2)) + 0x25C00000));
    r5 = LD32(r10 + 16);
    r4 = LD32(r10 + 12);
    r0 = GCALL3(0x0603F020, r4, r5, (sp - 112));
    ST32((68 + (sp - 112)), r0);
    r11 = 8;
    r6 = 134;
    r0 = LD16((sp - 108));
    r7 = 4;
    r2 = LD32(sp - 52);
    c0 = r0 == 2;
    ST32(sp - 56, c0);
    r2 = r2 + 0x980;
    c1001 = c0;
    do {
        r1 = r2;
        r0 = 4;
        do {
            ST8(r0 + r1, r7);
            r0 = r0 + 1;
        } while (AGAIN(!(r0 > r6)));
        r11 = r11 + 1;
        c2 = r11 > 33;
        r2 = r2 + 0x130;
        c1001 = c2;
    } while (AGAIN(!(c2)));
    r11 = 0;
    r14 = 7;
    while (1) {
        r12 = LD32((68 + (sp - 112)));
        r10 = LD32(sp - 60);
        if (!((r12 & r12) == 0)) {
            r9 = LD32(r10 + 32);
            c2008 = R(8);
            SETR(8, r8);
            r0 = GCALL1(0x060743C8, r9);
            SETR(8, c2008);
            r1 = R(1);
            r6 = LD32(0x060321B0);
            r7 = LD32(0x060321B4);
            r0 = GCALL4(0x06073FDC, r0, r1, r6, r7);
            r1 = R(1);
            c2008 = R(8);
            SETR(8, r8);
            r0 = GCALL2(0x06074550, r0, r1);
            SETR(8, c2008);
            ST32((76 + (sp - 112)), r0);
            r8 = 0x06073368;
            c2008 = R(8);
            SETR(8, 0x06073368);
            r0 = GCALL1(0x06073368, r11);
            SETR(8, c2008);
            ST32((72 + (sp - 112)), r0);
            c2008 = R(8);
            SETR(8, 0x06073368);
            r0 = GCALL1(0x06073368, r9);
            SETR(8, c2008);
            r4 = LD32((72 + (sp - 112)));
            r0 = GCALL2(0x06072EA8, r4, r0);
            r5 = LD32(0x060321B8);
            r0 = GCALL2(0x06072FC4, r0, r5);
            ST32((sp - 116), (sp - 64));
            ST32((sp - 120), (sp - 68));
            ST32((sp - 124), (sp - 72));
            ST32((sp - 128), (sp - 76));
            r10 = LD32((72 + (sp - 128)));
            ST32((sp - 132), r10);
            r7 = LD32((96 + (sp - 132)));
            r4 = LD32((72 + (sp - 132)));
            r0 = GCALL8(0x060316A0, 0, (sp - 112), r0, r7, LD32((sp - 132)), LD32((sp - 128)), LD32((sp - 124)), LD32((sp - 120)));
            r12 = LD32(sp - 56);
            r1 = LD32(sp - 72);
            if ((r12 & r12) == 0) {
                r2 = LD32(sp - 72);
                r1 = LD32(sp - 76);
                r4 = HELPER((int)((0x100 - r2) * 26) >> 8);
                r5 = r4;
                r4 = HELPER((int)((r2 - r1) * 26) >> 8);
                r3 = r4;
                c13 = (r3 & r3) == 0;
                c1015 = c13;
                if (!(c13)) {
                    r12 = LD32(sp - 56);
                } else {
                    r3 = 1;
                    r12 = LD32(sp - 56);
                }
            } else {
                r2 = LD32(sp - 76);
                r4 = HELPER((int)((0x100 - r1) * 13) >> 8);
                r5 = r4;
                r4 = HELPER((int)((r1 - r2) * 13) >> 8);
                r3 = r4;
                if ((r3 & r3) == 0) {
                    r3 = 1;
                }
                r1 = LD32(sp - 64);
                r4 = HELPER((int)((0x100 - r1) * 13) >> 8);
                ST32((64 + (sp - 112)), r4);
                r12 = 64 + (sp - 112);
                r10 = LD32(r12);
                ST32(r12, (r10 + 13));
                r2 = LD32(sp - 68);
                r4 = HELPER((int)((r1 - r2) * 13) >> 8);
                r13 = r4;
                r12 = LD32(sp - 56);
                if ((r13 & r13) == 0) {
                    r13 = 1;
                }
            }
        } else {
            r5 = 13;
            r3 = 1;
            ST32((64 + (sp - 112)), 13);
            r13 = 1;
            c1015 = 1;
            r12 = LD32(sp - 56);
        }
        r10 = 64;
        if (!((r12 & r12) == 0)) {
            r1 = LD32((r10 + (sp - 112)));
            r10 = LD32(sp - 52);
            r0 = 0;
            r1 = (((r1 + 8) * 0x130) + r14) + r10;
            if (!((unsigned)0 >= (unsigned)r13)) {
                r2 = -32;
                do {
                    ST8(r1, r2);
                    r0 = r0 + 1;
                    r1 = r1 + 0x130;
                } while (AGAIN(!((unsigned)r0 >= (unsigned)r13)));
            }
        }
        r7 = r5 + 9;
        r12 = LD32(sp - 52);
        r0 = 0;
        r1 = ((r7 * 0x130) + r14) + r12;
        if (!((unsigned)0 >= (unsigned)r3)) {
            r4 = 33;
            r6 = 12;
            r2 = r1 + 2;
            do {
                if (!((r7 + r0) > r4)) {
                    ST8(r2, r6);
                }
                r0 = r0 + 1;
                r2 = r2 + 0x130;
            } while (AGAIN(!((unsigned)r0 >= (unsigned)r3)));
        }
        r10 = LD32(sp - 52);
        r0 = 0;
        r1 = (((r5 + 8) * 0x130) + r14) + r10;
        if (!((unsigned)0 >= (unsigned)r3)) {
            r2 = 28;
            do {
                ST8(r1, r2);
                r0 = r0 + 1;
                r1 = r1 + 0x130;
            } while (AGAIN(!((unsigned)r0 >= (unsigned)r3)));
        }
        r11 = r11 + 1;
        r14 = r14 + 1;
        if (r11 > 125) {
            break;
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060387F4(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, c6, c7, c9, c10, c11, c21, c22, c23, c25, c1004, c1016, c1020, c1042;

    r10 = r4;
    r9 = r5;
    r11 = LD8(0x0608AF53);
    r4 = 0;
    if (!((r9 & r9) == 0)) {
        r8 = r9;
        r1 = LD8(r8);
        r3 = r1 & 255;
        c1020 = (r4 & r4) == 0;
        if (!((r3 & r3) == 0)) {
            r7 = 128;
            c1004 = (r11 & r11) == 0;
            do {
                if (c1004) {
                    r2 = 1;
                } else {
                    r8 = r8 + 1;
                    if (r3 == r7) {
                        r1 = LD8(r8);
                        r2 = 1;
                        r3 = r1 & 255;
                    } else {
                        r2 = 0;
                    }
                }
                r0 = r3;
                if (!((r2 & r2) == 0)) {
                    r1 = LD8(r0 + 0x06075135);
                    c6 = ((r1 & 7) & (r1 & 7)) == 0;
                    r0 = r3;
                    c1016 = c6;
                    if (!(c6)) {
                        r4 = r4 + 1;
                    } else {
                        c7 = r0 == 95;
                        r1 = r3;
                        c1016 = c7;
                        if (c7) {
                            r4 = r4 + 1;
                        } else {
                            c9 = r0 == 42;
                            c1016 = c9;
                            if (!((unsigned)((r1 - 45) & 255) > (unsigned)1)) {
                                r4 = r4 + 1;
                            } else {
                                c10 = r0 == 64;
                                c1016 = c10;
                                if (c9) {
                                    r4 = r4 + 1;
                                } else {
                                    c11 = r0 == 32;
                                    c1016 = c11;
                                    if (c10) {
                                        r4 = r4 + 1;
                                    } else {
                                        c1016 = c11;
                                        if (!(c11)) {
                                            r4 = r4 + 3;
                                        } else {
                                            r4 = r4 + 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                r8 = r8 + 1;
                r1 = LD8(r8);
                r3 = r1 & 255;
                c1004 = (r11 & r11) == 0;
            } while (AGAIN(!((r3 & r3) == 0)));
            c1020 = (r4 & r4) == 0;
        }
        r1 = 0;
        if (!(c1020)) {
            r0 = GCALL1(0x060287D0, (r4 + 1));
            r1 = r0;
            ST32(r10, r1);
            if (!((r1 & r1) == 0)) {
                r8 = r9;
                r7 = r1;
                ST8(r7, 0);
                while (1) {
                    r1 = LD8(r8);
                    r3 = r1 & 255;
                    c25 = (r11 & r11) == 0;
                    if (!((r3 & r3) == 0)) {
                        POLL();
                        r2 = c25;
                        if (!(c25)) {
                            r8 = r8 + 1;
                            if (r3 == 128) {
                                r1 = LD8(r8);
                                r2 = 1;
                                r3 = r1 & 255;
                            } else {
                                r2 = 0;
                            }
                        }
                        r0 = r3;
                        if (!((r2 & r2) == 0)) {
                            r1 = LD8(r0 + 0x06075135);
                            r0 = r3;
                            if (!(((r1 & 7) & (r1 & 7)) == 0)) {
                                ST8(r7, r3);
                                r7 = r7 + 1;
                            } else {
                                r1 = r3;
                                if (r0 == 95) {
                                    ST8(r7, r3);
                                    r7 = r7 + 1;
                                } else {
                                    c21 = r0 == 42;
                                    if (!((unsigned)((r1 - 45) & 255) > (unsigned)1)) {
                                        ST8(r7, r3);
                                        r7 = r7 + 1;
                                    } else {
                                        c22 = r0 == 64;
                                        if (c21) {
                                            ST8(r7, r3);
                                            r7 = r7 + 1;
                                        } else {
                                            c23 = r0 == 32;
                                            if (!(c22)) {
                                                r5 = r3;
                                                if (!(c23)) {
                                                    r0 = GCALL2(0x060389D4, r7, r5);
                                                    r7 = r0;
                                                } else {
                                                    ST8(r7, 43);
                                                    r7 = r7 + 1;
                                                }
                                            } else {
                                                ST8(r7, r3);
                                                r7 = r7 + 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        r8 = r8 + 1;
                        continue;
                    } else {
                        break;
                    }
                }
                ST8(r7, 0);
                c1042 = c25;
                r0 = 1;
                return r0;
            } else {
                r0 = 0;
                return r0;
            }
        } else {
            ST32(r10, r1);
            c1042 = 1;
            r0 = 1;
            return r0;
        }
    } else {
        ST32(r10, r4);
        r0 = 0;
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039CF8(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c0, c3, c5, c8, c14, c16, c22, c25, c28, c30, c1038, c1061;

    r10 = r4;
    ST32((r10 + 116), 0);
    ST32((r10 + 124), -1);
    r2 = r10 + 120;
    r1 = LD32(r2);
    r3 = 255;
    c0 = r1 == 255;
    r1 = r10;
    if (c0) {
        r11 = 0x06039B14;
        r8 = r2;
        r9 = r3;
        do {
            r0 = GCALL1(r11, r10);
            ST32(r8, r0);
        } while (AGAIN(r0 == r9));
        r1 = r10;
    }
    r0 = LD32((r1 + 120));
    r1 = LD32((r10 + 64));
    r2 = r0;
    if ((r1 & r1) == 0) {
        c5 = r0 > 216;
        if (r0 == 216) {
            ST32((r10 + 112), 0);
            c1061 = c5;
            r0 = 0;
        } else {
            if (c5) {
                c14 = r0 > 224;
                if (r0 == 224) {
                    r0 = 0x060395A0;
                    r0 = GCALL1(r0, r10);
                    c30 = (r0 & r0) == 0;
                    r0 = 0;
                    if (!(c30)) {
                        r0 = -303;
                    }
                } else {
                    if (c14) {
                        c22 = r0 >= 238;
                        if (r0 == 238) {
                            r0 = 0x06039650;
                            r0 = GCALL1(r0, r10);
                            c30 = (r0 & r0) == 0;
                            r0 = 0;
                            if (!(c30)) {
                                r0 = -303;
                            }
                        } else {
                            if (!(c22)) {
                                r0 = GCALL1(0x06039B40, r10);
                                r9 = r0;
                                r8 = 2;
                                r0 = 0;
                                if (!(2 >= r9)) {
                                    r11 = 0x06039B14;
                                    do {
                                        r0 = GCALL1(r11, r10);
                                        r8 = r8 + 1;
                                        r0 = 0;
                                    } while (AGAIN(!(r8 >= r9)));
                                }
                            } else {
                                if (r0 == 239) {
                                    r0 = GCALL1(0x06039B40, r10);
                                    r9 = r0;
                                    r8 = 2;
                                    r0 = 0;
                                    if (!(2 >= r9)) {
                                        r11 = 0x06039B14;
                                        do {
                                            r0 = GCALL1(r11, r10);
                                            r8 = r8 + 1;
                                            r0 = 0;
                                        } while (AGAIN(!(r8 >= r9)));
                                    }
                                } else {
                                    if (r0 == 254) {
                                        r0 = GCALL1(0x06039B40, r10);
                                        r9 = r0;
                                        r8 = 2;
                                        r0 = 0;
                                        if (!(2 >= r9)) {
                                            r11 = 0x06039B14;
                                            do {
                                                r0 = GCALL1(r11, r10);
                                                r8 = r8 + 1;
                                                r0 = 0;
                                            } while (AGAIN(!(r8 >= r9)));
                                        }
                                    } else {
                                        r0 = GCALL1(0x06039FD8, r10);
                                        r0 = -306;
                                    }
                                }
                            }
                        }
                    } else {
                        c16 = r0 > 219;
                        if (r0 == 219) {
                            r0 = 0x060392A0;
                            r0 = GCALL1(r0, r10);
                            c30 = (r0 & r0) == 0;
                            r0 = 0;
                            if (!(c30)) {
                                r0 = -303;
                            }
                        } else {
                            if (c16) {
                                if (r0 == 220) {
                                    r0 = 0x06039510;
                                    r0 = GCALL1(r0, r10);
                                    c30 = (r0 & r0) == 0;
                                    r0 = 0;
                                    if (!(c30)) {
                                        r0 = -303;
                                    }
                                } else {
                                    if (r0 == 221) {
                                        r0 = 0x060394E0;
                                        r0 = GCALL1(r0, r10);
                                        c30 = (r0 & r0) == 0;
                                        r0 = 0;
                                        if (!(c30)) {
                                            r0 = -303;
                                        }
                                    } else {
                                        r0 = GCALL1(0x06039FD8, r10);
                                        r0 = -306;
                                    }
                                }
                            } else {
                                r1 = r10;
                                if (r0 == 217) {
                                    ST32((r1 + 112), 1);
                                    c1061 = 1;
                                    r0 = 0;
                                } else {
                                    r2 = r10;
                                    if (r0 == 218) {
                                        r2 = r2 + 45;
                                        r1 = LD8(r2);
                                        c28 = (r1 & r1) == 0;
                                        r1 = 1;
                                        if (c28) {
                                            ST8(r2, r1);
                                            ST32((r10 + 104), 0);
                                            r0 = GCALL1(0x0603975C, r10);
                                            if ((r0 & r0) == 0) {
                                                POLL();
                                                r0 = -304;
                                            } else {
                                                r0 = -303;
                                            }
                                        } else {
                                            r0 = -304;
                                        }
                                    } else {
                                        r0 = GCALL1(0x06039FD8, r10);
                                        r0 = -306;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (r0 > 195) {
                    if (!(r0 > 207)) {
                        if (r0 >= 197) {
                            r0 = GCALL1(0x06039B40, r10);
                            r9 = r0;
                            r8 = 2;
                            if (!(2 >= r9)) {
                                r11 = 0x06039B14;
                                do {
                                    r0 = GCALL1(r11, r10);
                                    r8 = r8 + 1;
                                } while (AGAIN(!(r8 >= r9)));
                            }
                            r0 = -301;
                        } else {
                            r0 = 0x0603941C;
                            r0 = GCALL1(r0, r10);
                            c30 = (r0 & r0) == 0;
                            r0 = 0;
                            if (!(c30)) {
                                r0 = -303;
                            }
                        }
                    } else {
                        c1061 = 1;
                        r0 = 0;
                    }
                } else {
                    c8 = r0 == 1;
                    if (r0 >= 194) {
                        r0 = GCALL1(0x06039B40, r10);
                        r9 = r0;
                        r8 = 2;
                        if (!(2 >= r9)) {
                            r11 = 0x06039B14;
                            do {
                                r0 = GCALL1(r11, r10);
                                r8 = r8 + 1;
                            } while (AGAIN(!(r8 >= r9)));
                        }
                        r0 = -301;
                    } else {
                        r1 = 1;
                        if (!(c8)) {
                            if (r0 >= r1) {
                                r1 = 15;
                                if (r0 >= 192) {
                                    r0 = GCALL2(0x060391BC, r10, (r1 & r0));
                                    c25 = (r0 & r0) == 0;
                                    r0 = 0;
                                    c1038 = c25;
                                    if (!(c25)) {
                                        r0 = -1;
                                    }
                                } else {
                                    r0 = GCALL1(0x06039FD8, r10);
                                    r0 = -306;
                                }
                            } else {
                                r0 = GCALL1(0x06039FD8, r10);
                                r0 = -306;
                            }
                        } else {
                            c1061 = 1;
                            r0 = 0;
                        }
                    }
                }
            }
        }
    } else {
        c3 = (unsigned)(r2 + -208) > (unsigned)7;
        c1038 = c3;
        if (c3) {
            r0 = -1;
        } else {
            c5 = r0 > 216;
            if (r0 == 216) {
                ST32((r10 + 112), 0);
                c1061 = c5;
                r0 = 0;
            } else {
                if (c5) {
                    c14 = r0 > 224;
                    if (r0 == 224) {
                        r0 = 0x060395A0;
                        r0 = GCALL1(r0, r10);
                        c30 = (r0 & r0) == 0;
                        r0 = 0;
                        if (!(c30)) {
                            r0 = -303;
                        }
                    } else {
                        if (c14) {
                            c22 = r0 >= 238;
                            if (r0 == 238) {
                                r0 = 0x06039650;
                                r0 = GCALL1(r0, r10);
                                c30 = (r0 & r0) == 0;
                                r0 = 0;
                                if (!(c30)) {
                                    r0 = -303;
                                }
                            } else {
                                if (!(c22)) {
                                    r0 = GCALL1(0x06039B40, r10);
                                    r9 = r0;
                                    r8 = 2;
                                    r0 = 0;
                                    if (!(2 >= r9)) {
                                        r11 = 0x06039B14;
                                        do {
                                            r0 = GCALL1(r11, r10);
                                            r8 = r8 + 1;
                                            r0 = 0;
                                        } while (AGAIN(!(r8 >= r9)));
                                    }
                                } else {
                                    if (r0 == 239) {
                                        r0 = GCALL1(0x06039B40, r10);
                                        r9 = r0;
                                        r8 = 2;
                                        r0 = 0;
                                        if (!(2 >= r9)) {
                                            r11 = 0x06039B14;
                                            do {
                                                r0 = GCALL1(r11, r10);
                                                r8 = r8 + 1;
                                                r0 = 0;
                                            } while (AGAIN(!(r8 >= r9)));
                                        }
                                    } else {
                                        if (r0 == 254) {
                                            r0 = GCALL1(0x06039B40, r10);
                                            r9 = r0;
                                            r8 = 2;
                                            r0 = 0;
                                            if (!(2 >= r9)) {
                                                r11 = 0x06039B14;
                                                do {
                                                    r0 = GCALL1(r11, r10);
                                                    r8 = r8 + 1;
                                                    r0 = 0;
                                                } while (AGAIN(!(r8 >= r9)));
                                            }
                                        } else {
                                            r0 = GCALL1(0x06039FD8, r10);
                                            r0 = -306;
                                        }
                                    }
                                }
                            }
                        } else {
                            c16 = r0 > 219;
                            if (r0 == 219) {
                                r0 = 0x060392A0;
                                r0 = GCALL1(r0, r10);
                                c30 = (r0 & r0) == 0;
                                r0 = 0;
                                if (!(c30)) {
                                    r0 = -303;
                                }
                            } else {
                                if (c16) {
                                    if (r0 == 220) {
                                        r0 = 0x06039510;
                                        r0 = GCALL1(r0, r10);
                                        c30 = (r0 & r0) == 0;
                                        r0 = 0;
                                        if (!(c30)) {
                                            r0 = -303;
                                        }
                                    } else {
                                        if (r0 == 221) {
                                            r0 = 0x060394E0;
                                            r0 = GCALL1(r0, r10);
                                            c30 = (r0 & r0) == 0;
                                            r0 = 0;
                                            if (!(c30)) {
                                                r0 = -303;
                                            }
                                        } else {
                                            r0 = GCALL1(0x06039FD8, r10);
                                            r0 = -306;
                                        }
                                    }
                                } else {
                                    r1 = r10;
                                    if (r0 == 217) {
                                        ST32((r1 + 112), 1);
                                        c1061 = 1;
                                        r0 = 0;
                                    } else {
                                        r2 = r10;
                                        if (r0 == 218) {
                                            r2 = r2 + 45;
                                            r1 = LD8(r2);
                                            c28 = (r1 & r1) == 0;
                                            r1 = 1;
                                            if (c28) {
                                                ST8(r2, r1);
                                                ST32((r10 + 104), 0);
                                                r0 = GCALL1(0x0603975C, r10);
                                                if ((r0 & r0) == 0) {
                                                    POLL();
                                                    r0 = -304;
                                                } else {
                                                    r0 = -303;
                                                }
                                            } else {
                                                r0 = -304;
                                            }
                                        } else {
                                            r0 = GCALL1(0x06039FD8, r10);
                                            r0 = -306;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (r0 > 195) {
                        if (!(r0 > 207)) {
                            if (r0 >= 197) {
                                r0 = GCALL1(0x06039B40, r10);
                                r9 = r0;
                                r8 = 2;
                                if (!(2 >= r9)) {
                                    r11 = 0x06039B14;
                                    do {
                                        r0 = GCALL1(r11, r10);
                                        r8 = r8 + 1;
                                    } while (AGAIN(!(r8 >= r9)));
                                }
                                r0 = -301;
                            } else {
                                r0 = 0x0603941C;
                                r0 = GCALL1(r0, r10);
                                c30 = (r0 & r0) == 0;
                                r0 = 0;
                                if (!(c30)) {
                                    r0 = -303;
                                }
                            }
                        } else {
                            c1061 = 1;
                            r0 = 0;
                        }
                    } else {
                        c8 = r0 == 1;
                        if (r0 >= 194) {
                            r0 = GCALL1(0x06039B40, r10);
                            r9 = r0;
                            r8 = 2;
                            if (!(2 >= r9)) {
                                r11 = 0x06039B14;
                                do {
                                    r0 = GCALL1(r11, r10);
                                    r8 = r8 + 1;
                                } while (AGAIN(!(r8 >= r9)));
                            }
                            r0 = -301;
                        } else {
                            r1 = 1;
                            if (!(c8)) {
                                if (r0 >= r1) {
                                    r1 = 15;
                                    if (r0 >= 192) {
                                        r0 = GCALL2(0x060391BC, r10, (r1 & r0));
                                        c25 = (r0 & r0) == 0;
                                        r0 = 0;
                                        c1038 = c25;
                                        if (!(c25)) {
                                            r0 = -1;
                                        }
                                    } else {
                                        r0 = GCALL1(0x06039FD8, r10);
                                        r0 = -306;
                                    }
                                } else {
                                    r0 = GCALL1(0x06039FD8, r10);
                                    r0 = -306;
                                }
                            } else {
                                c1061 = 1;
                                r0 = 0;
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
int f0603AF04(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, c35, c1031;

    r2 = (short)(((((r4 << 16) + (r6 * 0x000166E9)) + 0x8000) << 16) | (int)((unsigned)(((r4 << 16) + (r6 * 0x000166E9)) + 0x8000) >> 16));
    r1 = 255;
    r8 = r7;
    if (r2 > 255) {
        r7 = r1;
    } else {
        r7 = r2;
        if (!(r7 >= 0)) {
            r7 = 0;
        }
    }
    r2 = (short)((((((r4 << 16) + (r5 * -22553)) + (r6 * -46801)) + 0x8000) << 16) | (int)((unsigned)((((r4 << 16) + (r5 * -22553)) + (r6 * -46801)) + 0x8000) >> 16));
    r1 = 255;
    r6 = r2;
    if (r2 > 255) {
        r6 = r1;
    } else {
        if (!(r6 >= 0)) {
            r6 = 0;
        }
    }
    r2 = (short)(((((r4 << 16) + (r5 * 0x0001C5A1)) + 0x8000) << 16) | (int)((unsigned)(((r4 << 16) + (r5 * 0x0001C5A1)) + 0x8000) >> 16));
    r1 = 255;
    r3 = r2;
    if (r2 > 255) {
        r3 = r1;
        r0 = r7;
    } else {
        if (r3 >= 0) {
            r0 = r7;
        } else {
            r3 = 0;
            r0 = r7;
        }
    }
    r2 = 3 & (((r0 >> 1) >> 1) >> 1);
    r5 = 3 & (((r6 >> 1) >> 1) >> 1);
    r4 = 3 & ((((r3 >> 1) >> 1) >> 1) >> 1);
    if (!((unsigned)r8 > (unsigned)3)) {
        r1 = LD16(0x0603AFC4 + (r8 + r8));
        switch (r1) {
        case 8:
            r1 = r2 - 1;
            r2 = 1;
            if (!((unsigned)r1 > (unsigned)1)) {
                r7 = r7 + 31;
            }
            if (!((unsigned)(r5 - 1) > (unsigned)r2)) {
                r6 = r6 + 31;
            }
            if (!((unsigned)(r4 - 1) > (unsigned)r2)) {
                r3 = r3 + 31;
            }
            break;
        case 44:
            if (r2 == 3) {
                r7 = r7 + 31;
            }
            if (r5 == 3) {
                r6 = r6 + 31;
            }
            c1031 = r4 == 3;
            if (c1031) {
                r3 = r3 + 31;
            }
            break;
        case 88:
            r1 = 2;
            if (r2 > 2) {
                r7 = r7 + 31;
            }
            if (r5 > r1) {
                r6 = r6 + 31;
            }
            c1031 = r4 > r1;
            if (c1031) {
                r3 = r3 + 31;
            }
            break;
        }
    }
    r2 = 255;
    r1 = r7;
    if (r7 > 255) {
        r1 = r2;
        r7 = r1;
    } else {
        if (r1 >= 0) {
            r7 = r1;
        } else {
            r7 = 0;
        }
    }
    r1 = 255;
    if (!(r6 > 255)) {
        r1 = r6;
        if (!(r1 >= 0)) {
            r1 = 0;
        }
    }
    r6 = r1;
    r1 = 255;
    c35 = r3 >= 0;
    if (r3 > 255) {
        r3 = r1;
    } else {
        if (!(c35)) {
            r3 = 0;
        }
    }
    r4 = HELPER((int)(r3 & 192) >> 6);
    return ((((int)((unsigned)((int)((unsigned)(224 & r6) >> 2)) >> 1)) | (224 & r7)) | r4) & 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603BAF8(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, c1, c12, c14, c15, c17, c23, c24, c25, c27, c1034, c1047, c1048;

    r1 = LD32(r4);
    r5 = 0xFFFF;
    if (!((unsigned)r1 > (unsigned)0xFFFF)) {
        r1 = LD32(r4 + 4);
        c1 = (unsigned)r1 > (unsigned)r5;
        r1 = r4;
        if (!(c1)) {
            r0 = LD8((r1 + 42));
            if (r0 == 8) {
                r6 = LD32(0x1DE0 + r4);
                r3 = LD32(r6);
                r7 = 0;
                if (!((unsigned)(r3 - 1) > (unsigned)255)) {
                    r2 = r5;
                    if (r7 >= r3) {
                        r2 = LD32(r4 + 16);
                        r0 = r2;
                        r1 = 3;
                        if (r0 == 3) {
                            r1 = LD8((r4 + 43));
                            c14 = (r1 & r1) == 0;
                            r1 = 3;
                            c1047 = c14;
                            if (!(c14)) {
                                ST32(r4 + 36, r1);
                                c1048 = c1047;
                            } else {
                                r1 = LD8((r4 + 44));
                                c15 = (r1 & r1) == 0;
                                r1 = r4;
                                if (c15) {
                                    r1 = LD32(r4 + 0x1DE0);
                                    r0 = r1;
                                    r2 = LD32(r0 + 140);
                                    r3 = LD32(r0 + 144);
                                    r1 = LD32(r0 + 148);
                                    r0 = r2;
                                    c1034 = r0 == 82;
                                    if (!(r0 == 1)) {
                                        r0 = r3;
                                        if (!(c1034)) {
                                            r1 = 3;
                                            c1047 = 0;
                                        } else {
                                            c23 = r0 == 71;
                                            r0 = r1;
                                            if (!(c23)) {
                                                r1 = 3;
                                                c1047 = 0;
                                            } else {
                                                c24 = r0 == 66;
                                                r1 = 3;
                                                c1047 = c24;
                                                if (c24) {
                                                    r1 = 2;
                                                    c1047 = 1;
                                                }
                                            }
                                        }
                                    } else {
                                        r0 = r2;
                                        if (!(r3 == 2)) {
                                            c1034 = r0 == 82;
                                            r0 = r3;
                                            if (!(c1034)) {
                                                r1 = 3;
                                                c1047 = 0;
                                            } else {
                                                c23 = r0 == 71;
                                                r0 = r1;
                                                if (!(c23)) {
                                                    r1 = 3;
                                                    c1047 = 0;
                                                } else {
                                                    c24 = r0 == 66;
                                                    r1 = 3;
                                                    c1047 = c24;
                                                    if (c24) {
                                                        r1 = 2;
                                                        c1047 = 1;
                                                    }
                                                }
                                            }
                                        } else {
                                            r0 = r2;
                                            if (!(r1 == 3)) {
                                                c1034 = r0 == 82;
                                                r0 = r3;
                                                if (!(c1034)) {
                                                    r1 = 3;
                                                    c1047 = 0;
                                                } else {
                                                    c23 = r0 == 71;
                                                    r0 = r1;
                                                    if (!(c23)) {
                                                        r1 = 3;
                                                        c1047 = 0;
                                                    } else {
                                                        c24 = r0 == 66;
                                                        r1 = 3;
                                                        c1047 = c24;
                                                        if (c24) {
                                                            r1 = 2;
                                                            c1047 = 1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                r1 = 3;
                                                c1047 = 1;
                                            }
                                        }
                                    }
                                    ST32(r4 + 36, r1);
                                    c1048 = c1047;
                                } else {
                                    r1 = LD8((r1 + 46));
                                    r1 = r1 & 255;
                                    r0 = r1;
                                    if ((r1 & r1) == 0) {
                                        r1 = 2;
                                        c1047 = 1;
                                        ST32(r4 + 36, r1);
                                        c1048 = c1047;
                                    } else {
                                        c17 = r0 == 1;
                                        r1 = 3;
                                        c1047 = c17;
                                        if (c17) {
                                            ST32(r4 + 36, r1);
                                            c1048 = c1047;
                                        } else {
                                            ST32(r4 + 36, r1);
                                            c1048 = 0;
                                        }
                                    }
                                }
                            }
                        } else {
                            c12 = r0 == 1;
                            if (r2 > r1) {
                                r1 = r4;
                                if (r0 == 4) {
                                    r1 = LD8((r1 + 44));
                                    c25 = (r1 & r1) == 0;
                                    r1 = r4;
                                    if (c25) {
                                        r1 = 4;
                                        c1047 = 1;
                                        ST32(r4 + 36, r1);
                                        c1048 = c1047;
                                    } else {
                                        r1 = LD8((r1 + 46));
                                        r1 = r1 & 255;
                                        r0 = r1;
                                        if ((r1 & r1) == 0) {
                                            r1 = 4;
                                            c1047 = 1;
                                            ST32(r4 + 36, r1);
                                            c1048 = c1047;
                                        } else {
                                            c27 = r0 == 2;
                                            r1 = 5;
                                            c1047 = c27;
                                            if (c27) {
                                                ST32(r4 + 36, r1);
                                                c1048 = c1047;
                                            } else {
                                                ST32(r4 + 36, r1);
                                                c1048 = 0;
                                            }
                                        }
                                    }
                                } else {
                                    r1 = 0;
                                    c1047 = 0;
                                    ST32(r4 + 36, r1);
                                    c1048 = c1047;
                                }
                            } else {
                                r0 = c12;
                                if (c12) {
                                    ST32(r4 + 36, r0);
                                    c1048 = 1;
                                } else {
                                    r1 = 0;
                                    c1047 = 0;
                                    ST32(r4 + 36, r1);
                                    c1048 = c1047;
                                }
                            }
                        }
                        r0 = 0;
                    } else {
                        r5 = 14;
                        r8 = r3;
                        while (1) {
                            r1 = LD32(140 + r6);
                            r3 = (r1 << 2) + r4;
                            r1 = LD32(0x15DC + r3);
                            if (!((unsigned)r1 > (unsigned)r2)) {
                                r1 = LD32(0x19DC + r3);
                                if ((unsigned)r1 > (unsigned)r2) {
                                    r0 = -307;
                                    break;
                                } else {
                                    r1 = LD32(0x9DC + r3);
                                    if ((unsigned)(r1 - 1) > (unsigned)r5) {
                                        r0 = -309;
                                        break;
                                    } else {
                                        r1 = LD32(0xDDC + r3);
                                        r7 = r7 + 1;
                                        if ((unsigned)(r1 - 1) > (unsigned)r5) {
                                            r0 = -309;
                                            break;
                                        } else {
                                            r6 = r6 + 4;
                                            if (!(r7 >= r8)) {
                                                POLL();
                                                continue;
                                            } else {
                                                r2 = LD32(r4 + 16);
                                                r0 = r2;
                                                r1 = 3;
                                                if (r0 == 3) {
                                                    r1 = LD8((r4 + 43));
                                                    c14 = (r1 & r1) == 0;
                                                    r1 = 3;
                                                    c1047 = c14;
                                                    if (!(c14)) {
                                                        ST32(r4 + 36, r1);
                                                        c1048 = c1047;
                                                        r0 = 0;
                                                        break;
                                                    } else {
                                                        r1 = LD8((r4 + 44));
                                                        c15 = (r1 & r1) == 0;
                                                        r1 = r4;
                                                        if (c15) {
                                                            r1 = LD32(r4 + 0x1DE0);
                                                            r0 = r1;
                                                            r2 = LD32(r0 + 140);
                                                            r3 = LD32(r0 + 144);
                                                            r1 = LD32(r0 + 148);
                                                            r0 = r2;
                                                            c1034 = r0 == 82;
                                                            if (!(r0 == 1)) {
                                                                r0 = r3;
                                                                if (!(c1034)) {
                                                                    r1 = 3;
                                                                    c1047 = 0;
                                                                    ST32(r4 + 36, r1);
                                                                    c1048 = c1047;
                                                                    r0 = 0;
                                                                    break;
                                                                } else {
                                                                    c23 = r0 == 71;
                                                                    r0 = r1;
                                                                    if (!(c23)) {
                                                                        r1 = 3;
                                                                        c1047 = 0;
                                                                        ST32(r4 + 36, r1);
                                                                        c1048 = c1047;
                                                                        r0 = 0;
                                                                        break;
                                                                    } else {
                                                                        c24 = r0 == 66;
                                                                        r1 = 3;
                                                                        c1047 = c24;
                                                                        if (!(c24)) {
                                                                            ST32(r4 + 36, r1);
                                                                            c1048 = c1047;
                                                                            r0 = 0;
                                                                            break;
                                                                        } else {
                                                                            r1 = 2;
                                                                            c1047 = 1;
                                                                            ST32(r4 + 36, r1);
                                                                            c1048 = c1047;
                                                                            r0 = 0;
                                                                            break;
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                r0 = r2;
                                                                if (!(r3 == 2)) {
                                                                    c1034 = r0 == 82;
                                                                    r0 = r3;
                                                                    if (!(c1034)) {
                                                                        r1 = 3;
                                                                        c1047 = 0;
                                                                        ST32(r4 + 36, r1);
                                                                        c1048 = c1047;
                                                                        r0 = 0;
                                                                        break;
                                                                    } else {
                                                                        c23 = r0 == 71;
                                                                        r0 = r1;
                                                                        if (!(c23)) {
                                                                            r1 = 3;
                                                                            c1047 = 0;
                                                                            ST32(r4 + 36, r1);
                                                                            c1048 = c1047;
                                                                            r0 = 0;
                                                                            break;
                                                                        } else {
                                                                            c24 = r0 == 66;
                                                                            r1 = 3;
                                                                            c1047 = c24;
                                                                            if (!(c24)) {
                                                                                ST32(r4 + 36, r1);
                                                                                c1048 = c1047;
                                                                                r0 = 0;
                                                                                break;
                                                                            } else {
                                                                                r1 = 2;
                                                                                c1047 = 1;
                                                                                ST32(r4 + 36, r1);
                                                                                c1048 = c1047;
                                                                                r0 = 0;
                                                                                break;
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    r0 = r2;
                                                                    if (!(r1 == 3)) {
                                                                        c1034 = r0 == 82;
                                                                        r0 = r3;
                                                                        if (!(c1034)) {
                                                                            r1 = 3;
                                                                            c1047 = 0;
                                                                            ST32(r4 + 36, r1);
                                                                            c1048 = c1047;
                                                                            r0 = 0;
                                                                            break;
                                                                        } else {
                                                                            c23 = r0 == 71;
                                                                            r0 = r1;
                                                                            if (!(c23)) {
                                                                                r1 = 3;
                                                                                c1047 = 0;
                                                                                ST32(r4 + 36, r1);
                                                                                c1048 = c1047;
                                                                                r0 = 0;
                                                                                break;
                                                                            } else {
                                                                                c24 = r0 == 66;
                                                                                r1 = 3;
                                                                                c1047 = c24;
                                                                                if (!(c24)) {
                                                                                    ST32(r4 + 36, r1);
                                                                                    c1048 = c1047;
                                                                                    r0 = 0;
                                                                                    break;
                                                                                } else {
                                                                                    r1 = 2;
                                                                                    c1047 = 1;
                                                                                    ST32(r4 + 36, r1);
                                                                                    c1048 = c1047;
                                                                                    r0 = 0;
                                                                                    break;
                                                                                }
                                                                            }
                                                                        }
                                                                    } else {
                                                                        r1 = 3;
                                                                        c1047 = 1;
                                                                        ST32(r4 + 36, r1);
                                                                        c1048 = c1047;
                                                                        r0 = 0;
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r1 = LD8((r1 + 46));
                                                            r1 = r1 & 255;
                                                            r0 = r1;
                                                            if ((r1 & r1) == 0) {
                                                                r1 = 2;
                                                                c1047 = 1;
                                                                ST32(r4 + 36, r1);
                                                                c1048 = c1047;
                                                                r0 = 0;
                                                                break;
                                                            } else {
                                                                c17 = r0 == 1;
                                                                r1 = 3;
                                                                c1047 = c17;
                                                                if (c17) {
                                                                    ST32(r4 + 36, r1);
                                                                    c1048 = c1047;
                                                                    r0 = 0;
                                                                    break;
                                                                } else {
                                                                    ST32(r4 + 36, r1);
                                                                    c1048 = 0;
                                                                    r0 = 0;
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    c12 = r0 == 1;
                                                    if (r2 > r1) {
                                                        r1 = r4;
                                                        if (r0 == 4) {
                                                            r1 = LD8((r1 + 44));
                                                            c25 = (r1 & r1) == 0;
                                                            r1 = r4;
                                                            if (c25) {
                                                                r1 = 4;
                                                                c1047 = 1;
                                                                ST32(r4 + 36, r1);
                                                                c1048 = c1047;
                                                                r0 = 0;
                                                                break;
                                                            } else {
                                                                r1 = LD8((r1 + 46));
                                                                r1 = r1 & 255;
                                                                r0 = r1;
                                                                if ((r1 & r1) == 0) {
                                                                    r1 = 4;
                                                                    c1047 = 1;
                                                                    ST32(r4 + 36, r1);
                                                                    c1048 = c1047;
                                                                    r0 = 0;
                                                                    break;
                                                                } else {
                                                                    c27 = r0 == 2;
                                                                    r1 = 5;
                                                                    c1047 = c27;
                                                                    if (c27) {
                                                                        ST32(r4 + 36, r1);
                                                                        c1048 = c1047;
                                                                        r0 = 0;
                                                                        break;
                                                                    } else {
                                                                        ST32(r4 + 36, r1);
                                                                        c1048 = 0;
                                                                        r0 = 0;
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r1 = 0;
                                                            c1047 = 0;
                                                            ST32(r4 + 36, r1);
                                                            c1048 = c1047;
                                                            r0 = 0;
                                                            break;
                                                        }
                                                    } else {
                                                        r0 = c12;
                                                        if (c12) {
                                                            ST32(r4 + 36, r0);
                                                            c1048 = 1;
                                                            r0 = 0;
                                                            break;
                                                        } else {
                                                            r1 = 0;
                                                            c1047 = 0;
                                                            ST32(r4 + 36, r1);
                                                            c1048 = c1047;
                                                            r0 = 0;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                r0 = -307;
                                break;
                            }
                            POLL();
                        }
                    }
                } else {
                    r0 = -311;
                }
            } else {
                r0 = -308;
            }
        } else {
            r0 = -307;
        }
    } else {
        r0 = -307;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603BC80(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    long long m0;
    int v36;
    int v40;
    int v44;
    int v48;
    int v52;
    int v56;
    int v60;

    v60 = r4;
    v56 = r5;
    v44 = 0;
    while (1) {
        r3 = v60 + v44;
        r1 = LD32(v44 + v60);
        r11 = r1 << 2;
        r1 = LD32(r3 + 32);
        v40 = r1 << 2;
        r1 = LD32((r3 + 64));
        r3 = r3 + 96;
        r12 = r1 << 2;
        r1 = LD32(r3);
        r6 = r1 << 2;
        r1 = LD32(r3 + 32);
        v36 = r1 << 2;
        r1 = LD32((r3 + 64));
        r3 = r3 + 96;
        r7 = r1 << 2;
        r1 = LD32(r3);
        r9 = r1 << 2;
        r1 = LD32(r3 + 32);
        r2 = r1 << 2;
        r4 = HELPER((int)((v40 * 100) - (r2 * 0x1F6)) >> 9);
        r14 = r4;
        r4 = HELPER((int)((r7 * 0x1AA) - (r6 * 0x11C)) >> 9);
        r13 = r4;
        r4 = HELPER((int)((r6 * 0x1AA) + (r7 * 0x11C)) >> 9);
        r10 = r4;
        r4 = HELPER((int)((v40 * 0x1F6) + (r2 * 100)) >> 9);
        r5 = r4;
        r4 = HELPER((int)((v36 + r11) * 0x16A) >> 9);
        v40 = r4;
        r4 = HELPER((int)((r11 - v36) * 0x16A) >> 9);
        r6 = r4;
        r4 = HELPER((int)((r12 * 196) - (r9 * 0x1D9)) >> 9);
        r7 = r4;
        r4 = r12 * 0x1D9;
        r12 = r6 - r7;
        r4 = HELPER((int)(r4 + (r9 * 196)) >> 9);
        r2 = r4;
        r11 = v40 + r2;
        v36 = r6 + r7;
        r6 = r14 - r13;
        r7 = r5 - r10;
        r14 = r14 + r13;
        r9 = v40 - r2;
        r5 = r5 + r10;
        r4 = HELPER((int)((r7 - r6) * 0x16A) >> 9);
        r13 = r4;
        r4 = HELPER((int)((r7 + r6) * 0x16A) >> 9);
        r10 = r4;
        r0 = v44;
        r3 = v56 + v44;
        ST32(r0 + v56, (r11 + r5));
        r0 = r0 + 4;
        ST32(r3 + 32, (v36 + r10));
        ST32((r3 + 64), (r12 + r13));
        r3 = r3 + 96;
        ST32(r3, (r9 + r14));
        ST32(r3 + 32, (r9 - r14));
        ST32((r3 + 64), (r12 - r13));
        r3 = r3 + 96;
        ST32(r3, (v36 - r10));
        ST32(r3 + 32, (r11 - r5));
        v44 = r0;
        if (r0 > 28) {
            break;
        }
        POLL();
    }
    v52 = 0;
    r3 = v56;
    v48 = 0;
    while (1) {
        r0 = LD32(r3 + 4);
        r2 = LD32(r3 + 28);
        r6 = LD32(r3 + 12);
        r7 = LD32(r3 + 20);
        r4 = HELPER((int)((r0 * 100) - (r2 * 0x1F6)) >> 9);
        r14 = r4;
        r4 = HELPER((int)((r7 * 0x1AA) - (r6 * 0x11C)) >> 9);
        r13 = r4;
        r4 = HELPER((int)((r6 * 0x1AA) + (r7 * 0x11C)) >> 9);
        r10 = r4;
        r4 = HELPER((int)((r0 * 0x1F6) + (r2 * 100)) >> 9);
        r5 = r4;
        r11 = LD32(v48 + v56);
        r0 = LD32(r3 + 16);
        r4 = HELPER((int)((r0 + r11) * 0x16A) >> 9);
        v40 = r4;
        r12 = LD32(r3 + 8);
        r9 = LD32(r3 + 24);
        r8 = 0x060727A6;
        r4 = HELPER((int)((r11 - r0) * 0x16A) >> 9);
        r6 = r4;
        r11 = v40;
        r4 = HELPER((int)((r12 * 196) - (r9 * 0x1D9)) >> 9);
        r7 = r4;
        r4 = r12 * 0x1D9;
        m0 = (unsigned)(r9 * 196);
        r12 = r6 - r7;
        r0 = GCALL8(r8, (r4 + ((int)m0)), r5, r6, r7, v60, v56, v52, v48);
        r4 = R(4);
        r2 = r4;
        r11 = r11 + r2;
        r6 = R(6);
        r7 = R(7);
        v36 = r6 + r7;
        r6 = r14 - r13;
        r5 = R(5);
        r7 = r5 - r10;
        r14 = r14 + r13;
        r9 = v40 - r2;
        r5 = r5 + r10;
        r4 = HELPER((int)((r7 - r6) * 0x16A) >> 9);
        r13 = r4;
        r4 = HELPER((int)((r7 + r6) * 0x16A) >> 9);
        r10 = r4;
        r0 = v48;
        ST32(r0 + v56, (r11 + r5));
        r3 = R(3);
        ST32(r3 + 4, (v36 + r10));
        ST32(r3 + 8, (r12 + r13));
        ST32(r3 + 12, (r9 + r14));
        ST32(r3 + 16, (r9 - r14));
        ST32(r3 + 20, (r12 - r13));
        ST32(r3 + 24, (v36 - r10));
        ST32(r3 + 28, (r11 - r5));
        v48 = r0 + 32;
        r3 = r3 + 32;
        r0 = v52 + 1;
        v52 = r0;
        if (r0 > 7) {
            break;
        }
        POLL();
    }
    r0 = 0;
    v52 = 0;
    r3 = v56;
    r7 = 63;
    do {
        r2 = LD32(r3);
        r1 = r2;
        if (r2 >= 0) {
            r1 = r1 + 8;
            if (!(r1 >= 0)) {
                r1 = r2 + 23;
            }
        } else {
            r1 = r1 - 8;
            if (!(r1 >= 0)) {
                r1 = r2 + 7;
            }
        }
        ST32(r3, ((((r1 >> 1) >> 1) >> 1) >> 1));
        r3 = r3 + 4;
        r8 = v52 + 1;
        v52 = r8;
    } while (AGAIN(!(r8 > r7)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603407C(int r4, int r5, int r6)
{
    int r0, r1, r7, r8, r9, r10, r11, r12, r14, r15, c1031;
    FRAME(sp, 580);

    r14 = sp - 580;
    ST32(0x220 + r14, r4);
    r9 = r5;
    r11 = r6;
    r0 = LD32((0x220 + r14));
    r10 = r14 + 32;
    r12 = LD32(r0 + 0x10D4);
    r7 = r10;
    while (1) {
        r4 = LD32((0x220 + r14));
        r0 = GCALL4(0x06018CC0, r4, r11, r14, r7);
        r11 = r0;
        if (!((r11 & r11) == 0)) {
            r0 = GCALL2(0x06075104, 0x06034048, r14);
            if (!((r0 & r0) == 0)) {
                r0 = GCALL2(0x06075104, 0x06034050, r14);
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL2(0x06075104, 0x06034058, r14);
                    c1031 = (r11 & r11) == 0;
                    if ((r0 & r0) == 0) {
                        if ((r12 & r12) == 0) {
                            r1 = -1;
                        } else {
                            r0 = GCALL1(0x06045614, r10);
                            r1 = r0 - 1;
                        }
                        r15 = ALLOCA(sp - 580, (((int)((unsigned)(r1 + 4) >> 2)) << 2));
                        if ((r12 & r12) == 0) {
                            r8 = r14 + 32;
                            r6 = 4;
                        } else {
                            r8 = r15;
                            r0 = GCALL2(0x06045654, (r14 + 32), r15);
                            r6 = 4;
                        }
                        r0 = GCALL3(0x06075238, 0x06034060, r8, r6);
                        r6 = 3;
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL3(0x06075238, 0x06034068, r8, r6);
                            r6 = 6;
                            if (!((r0 & r0) == 0)) {
                                r0 = GCALL3(0x06075238, 0x0603406C, r8, r6);
                                r6 = 5;
                                if (!((r0 & r0) == 0)) {
                                    r0 = GCALL3(0x06075238, 0x06034074, r8, r6);
                                    SETSP((sp - 580));
                                    if ((r0 & r0) == 0) {
                                        r1 = 3;
                                        ST32(r9 + 16, r1);
                                        SETSP((sp - 580));
                                    }
                                } else {
                                    r1 = 2;
                                    ST32(r9 + 16, r1);
                                    SETSP((sp - 580));
                                }
                            } else {
                                r1 = 0;
                                ST32(r9 + 16, r1);
                                SETSP((sp - 580));
                            }
                        } else {
                            ST32(r9 + 16, 1);
                            SETSP((sp - 580));
                        }
                        c1031 = (r11 & r11) == 0;
                    }
                } else {
                    r4 = LD32(r9 + 20);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                        ST32(r9 + 20, 0);
                    }
                    r0 = GCALL1(0x0607507C, r10);
                    r0 = GCALL1(0x060287D0, (r0 + 1));
                    r1 = r0;
                    ST32(r9 + 20, r1);
                    r6 = r10;
                    if ((r1 & r1) == 0) {
                        c1031 = (r11 & r11) == 0;
                    } else {
                        r0 = GCALL3(0x060456E4, r12, r1, r6);
                        c1031 = (r11 & r11) == 0;
                    }
                }
            } else {
                r4 = LD32(r9 + 12);
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(0x06027F48, r4);
                    ST32(r9 + 12, 0);
                }
                r0 = GCALL1(0x0607507C, r10);
                r0 = GCALL1(0x060287D0, (r0 + 1));
                r1 = r0;
                ST32(r9 + 12, r1);
                r6 = r10;
                if ((r1 & r1) == 0) {
                    c1031 = (r11 & r11) == 0;
                } else {
                    r0 = GCALL3(0x060456E4, r12, r1, r6);
                    c1031 = (r11 & r11) == 0;
                }
            }
        } else {
            c1031 = 1;
        }
        r7 = r10;
        if (c1031) {
            break;
        }
        POLL();
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06034AE0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r13, r14, r15, c3, c11, c1019, c1033;
    FRAME(sp, 588);

    r14 = sp - 588;
    ST32(0x220 + r14, r4);
    r11 = r5;
    r13 = r6;
    r0 = LD32((0x220 + r14));
    r10 = r14 + 32;
    r1 = LD32(r0 + 0x10D4);
    ST32(0x224 + r14, r1);
    ST32(0x228 + r14, (r11 + 44));
    r7 = r10;
    while (1) {
        r4 = LD32((0x220 + r14));
        r0 = GCALL4(0x06018CC0, r4, r13, r14, r7);
        r13 = r0;
        if (!((r13 & r13) == 0)) {
            r0 = GCALL2(0x06075104, 0x06034AB4, r14);
            if (!((r0 & r0) == 0)) {
                r0 = GCALL2(0x06075104, 0x06034260, r14);
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL2(0x06075104, 0x06034ABC, r14);
                    if (!((r0 & r0) == 0)) {
                        r0 = GCALL2(0x06075104, 0x06034AC4, r14);
                        c1033 = (r13 & r13) == 0;
                        if ((r0 & r0) == 0) {
                            r3 = LD32((0x224 + r14));
                            if ((r3 & r3) == 0) {
                                r1 = -1;
                            } else {
                                r0 = GCALL1(0x06045614, r10);
                                r1 = r0 - 1;
                            }
                            r0 = LD32(0x224 + r14);
                            r15 = ALLOCA(sp - 588, (((int)((unsigned)(r1 + 4) >> 2)) << 2));
                            if ((r0 & r0) == 0) {
                                r8 = r14 + 32;
                            } else {
                                r8 = r15;
                                r0 = GCALL2(0x06045654, (r14 + 32), r15);
                            }
                            r9 = 0x06075238;
                            r0 = GCALL3(0x06075238, 0x06034ACC, r8, 7);
                            r6 = 8;
                            if (!((r0 & r0) == 0)) {
                                r0 = GCALL3(r9, 0x06034AD4, r8, r6);
                                SETSP((sp - 588));
                                if ((r0 & r0) == 0) {
                                    ST32(r11 + 48, 2);
                                    SETSP((sp - 588));
                                }
                            } else {
                                ST32(r11 + 48, 1);
                                SETSP((sp - 588));
                            }
                            c1033 = (r13 & r13) == 0;
                        }
                    } else {
                        r1 = LD8(r10);
                        r5 = r10;
                        if ((r1 & 255) == 48) {
                            r2 = r11 + 46;
                            r1 = 1;
                            c1019 = 1;
                            ST16(r2, r1);
                            c1033 = (r13 & r13) == 0;
                        } else {
                            r4 = LD32((0x224 + r14));
                            r0 = GCALL2(0x06045710, r4, r5);
                            r1 = r0;
                            r2 = r11 + 46;
                            ST16(r2, r1);
                            c11 = (r13 & r13) == 0;
                            c1033 = c11;
                            if (!(((short)r1) > 0)) {
                                r1 = 1;
                                c1019 = c11;
                                ST16(r2, r1);
                                c1033 = (r13 & r13) == 0;
                            }
                        }
                    }
                } else {
                    r4 = LD32(r11 + 32);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                        ST32(r11 + 32, 0);
                    }
                    r0 = GCALL1(0x0607507C, r10);
                    r0 = GCALL1(0x060287D0, (r0 + 1));
                    r2 = r0;
                    ST32(r11 + 32, r2);
                    if ((r2 & r2) == 0) {
                        c1033 = (r13 & r13) == 0;
                    } else {
                        r0 = GCALL2(0x06018930, r2, r10);
                        c1033 = (r13 & r13) == 0;
                    }
                }
            } else {
                r1 = LD8(r10);
                r5 = r10;
                if ((r1 & 255) == 48) {
                    r3 = LD32(0x228 + r14);
                    ST16(r3, 20);
                } else {
                    r4 = LD32((0x224 + r14));
                    r0 = GCALL2(0x06045710, r4, r5);
                    r1 = r0;
                    r0 = LD32((0x228 + r14));
                    ST16(r0, r1);
                    c3 = ((short)r1) > 0;
                    r1 = 20;
                    if (!(c3)) {
                        ST16(r0, r1);
                    }
                }
                c1033 = (r13 & r13) == 0;
            }
        } else {
            c1033 = 1;
        }
        r7 = r10;
        if (c1033) {
            break;
        }
        POLL();
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06037674(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r11, r12, r13, r14, r15, c2, c6, c12, c14, c18, c1011, c1019, c1021;
    FRAME(sp, 56);

    r14 = sp - 56;
    ST32(r14 + 8, r4);
    ST32(r14 + 16, 0);
    r0 = SR();
    r13 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    r11 = -241;
    SETSR((r0 | 240));
    r1 = LD32(0x06088028);
    r0 = LD32(r1);
    if (r0 == 2) {
        ST32(r14 + 12, r1);
        r9 = LD32(r1 + 40);
        r4 = LD32(0x0608800C);
        r0 = GCALL1(0x0607507C, r4);
        ST32(r14 + 20, r0);
        r15 = ALLOCA(sp - 56, (((int)((unsigned)(r0 + 52) >> 2)) << 2));
        r8 = r15 + 48;
        r2 = LD32(0x06087FF8);
        r6 = LD32(r14 + 20);
        ST32(r15, r2);
        r3 = LD32(0x06087FFC);
        ST32(r15 + 4, r3);
        r3 = LD32(0x06088000);
        r2 = (r15 + 4) + 4;
        ST32(r2, r3);
        r3 = LD32(0x06088004);
        r2 = r2 + 4;
        ST32(r2, r3);
        r3 = LD32(0x06088008);
        r2 = r2 + 4;
        ST32(r2, r3);
        r3 = LD32(0x0608800C);
        r2 = r2 + 4;
        ST32(r2, r3);
        r3 = LD32(0x06088010);
        r2 = r2 + 4;
        ST32(r2, r3);
        r3 = LD32(0x06088014);
        r2 = r2 + 4;
        ST32(r2, r3);
        r3 = LD32(0x06088018);
        r2 = r2 + 4;
        ST32(r2, r3);
        r3 = LD32(0x0608801C);
        r2 = r2 + 4;
        ST32(r2, r3);
        r3 = LD32(0x06088020);
        r2 = r2 + 4;
        ST32(r2, r3);
        r1 = LD32(0x06088024);
        ST32(r2 + 4, r1);
        r5 = LD32(0x0608800C);
        r0 = GCALL3(0x0604B358, r8, r5, (r6 + 1));
        ST16(0x06088010, 0);
        r2 = LD32(0x0608800C);
        ST8(r2, 0);
        ST16(0x06088012, 0);
        r1 = SR();
        SETSR(((r1 & r11) | ((r13 << 2) << 2)));
        r12 = LD32(r14 + 20);
        ST32(r15 + 20, r8);
        if (r12 > 0) {
            ST32(r14 + 16, 1);
        }
        r1 = LD32(r9 + 24);
        ST32(r14, r1);
        r1 = LD32(r9 + 28);
        r5 = LD32(r15 + 20);
        ST32(r14 + 4, r1);
        r0 = GCALL4(0x06041ED8, r9, r5, r14, (r14 + 4));
        r1 = LD32(r14);
        ST32(r9 + 24, r1);
        r1 = LD32(r14 + 4);
        c2 = (r0 & r0) == 0;
        ST32(r9 + 28, r1);
        c1021 = c2;
        if (c2) {
            r1 = LD32(r9 + 40);
            r2 = LD32(r9 + 32);
            r1 = r1 + r2;
            r2 = LD32(r9 + 24);
            r6 = 1;
            if (r2 >= r1) {
                r8 = 0x060425D4;
                do {
                    r0 = GCALL3(r8, r9, 1, r6);
                    r1 = LD32(r9 + 40);
                    r2 = LD32(r9 + 32);
                    r1 = r1 + r2;
                    r2 = LD32(r9 + 24);
                    r6 = 1;
                } while (AGAIN(r2 >= r1));
                r2 = LD32(r9 + 24);
            }
            r1 = LD32(r9 + 40);
            c6 = r2 >= 0;
            if (!(r2 >= r1)) {
                r8 = 0x060425D4;
                c1011 = c6;
                while (1) {
                    r6 = 0;
                    if (!(c1011)) {
                        break;
                    } else {
                        r0 = GCALL3(r8, r9, -1, r6);
                        r2 = LD32(r9 + 24);
                        r1 = LD32(r9 + 40);
                        c1011 = r2 >= 0;
                        if (!(r2 >= r1)) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
            }
            r1 = LD32(r9 + 44);
            r2 = LD32(r9 + 36);
            r1 = r1 + r2;
            r2 = LD32(r9 + 28);
            r5 = 1;
            if (r2 > r1) {
                r8 = 0x0604266C;
                do {
                    r0 = GCALL2(r8, r9, r5);
                    r1 = LD32(r9 + 44);
                    r2 = LD32(r9 + 36);
                    r1 = r1 + r2;
                    r2 = LD32(r9 + 28);
                    r5 = 1;
                } while (AGAIN(r2 > r1));
                r2 = LD32(r9 + 28);
            }
            r1 = LD32(r9 + 44);
            c12 = r2 >= 0;
            c1021 = c12;
            if (!(r2 >= r1)) {
                r8 = 0x0604266C;
                c1019 = c12;
                while (1) {
                    r5 = -1;
                    c1021 = c1019;
                    if (!(c1019)) {
                        break;
                    } else {
                        r0 = GCALL2(r8, r9, r5);
                        r2 = LD32(r9 + 28);
                        r1 = LD32(r9 + 44);
                        c14 = r2 >= 0;
                        c1019 = c14;
                        c1021 = c14;
                        if (!(r2 >= r1)) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
            }
        }
        r0 = (SR() & ~1) | c1021;
        r13 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
        r0 = (SR() & ~1) | c1021;
        r0 = r0 | 240;
        SETSR(r0);
        r1 = LD32(r14 + 12);
        r3 = LD16((r1 + 12));
        r12 = LD32(r14 + 12);
        r3 = r3 + 2;
        ST16(0x06088008, r3);
        r7 = LD32(r12 + 16);
        r1 = LD32(r14 + 4);
        r7 = r7 + 2;
        ST16(0x0608800A, r7);
        r2 = LD32(r9 + 44);
        r1 = r1 - r2;
        r2 = LD32(r14 + 12);
        r2 = LD16((r2 + 30));
        ST16(0x06088008, (r3 + ((r1 + 1) * r2)));
        r5 = LD32(r14);
        r1 = LD32(r9 + 40);
        r3 = LD32(r14 + 12);
        r2 = r5 - r1;
        r3 = r3 + 28;
        r1 = LD16(r3);
        ST16(0x0608800A, (r7 + (r2 * r1)));
        r1 = SR();
        SETSR(((r1 & -241) | ((r13 << 2) << 2)));
        r12 = LD32(r14 + 16);
        if (!((r12 & r12) == 0)) {
            r1 = LD32(r9 + 40);
            r2 = LD16(r3);
            r12 = LD32(r14 + 12);
            c18 = ((r5 - r1) + 1) * r2;
            r5 = LD32(r12 + 16);
            r4 = LD32(r14 + 8);
            r0 = GCALL2(0x060106BC, r4, (r5 + c18));
        }
    } else {
        r1 = (SR() & ~1) | 0;
        SETSR(((r1 & r11) | ((r13 << 2) << 2)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06030294(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14, c4;
    FRAME(sp, 84);

    ST32(sp - 84, r4);
    ST32(sp - 80, r5);
    ST32(sp - 76, r6);
    ST32(0x06087F78, 0xB000);
    r0 = LD32(sp - 80);
    ST32(r0, 130);
    ST32(sp - 52, 0);
    r0 = GCALL7(0x060279E0, 0, 130, -1, 1, LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)));
    r7 = r0;
    r3 = LD32(sp - 52);
    if (!((r7 & r7) == 0)) {
        goto L060302D4;
    }
    r0 = LD32(sp - 80);
    ST32(r0, r3);
    goto L060303E2;
    L060302D4:
    r12 = 0;
    ST32(sp - 72, 0);
    r6 = 0x06078030;
    ST32(sp - 60, 0);
    ST32(sp - 40, 0);
    L060302E2:
    r1 = LD16((r6 + 2));
    r14 = r1 & 0xFFFF;
    r1 = LD16((r6 + 4));
    r0 = LD32(sp - 60);
    ST32(sp - 68, (r1 & 0xFFFF));
    r1 = LD16(r0 + 0x06078030);
    ST32(sp - 36, 0);
    r0 = LD32(sp - 40);
    r13 = LD32(sp - 84);
    ST32(sp - 64, (r1 & 0xFFFF));
    goto L060303AA;
    L06030308:
    r8 = 0;
    r13 = LD32(sp - 76);
    r1 = (r3 * r1) + r13;
    ST16((r1 + 60), r14);
    r0 = LD16((18 + (sp - 84)));
    ST16((r1 + 62), r0);
    ST16((r1 + 64), r12);
    r13 = LD16((22 + (sp - 84)));
    ST16((r1 + 20), r13);
    r1 = (r12 << 2) + (r12 << 2);
    r11 = r1 + 4;
    r10 = r1 + r7;
    r9 = (r12 << 16) << 8;
    L06030348:
    r0 = LD32(sp - 76);
    r5 = LD32(0x06087F78);
    ST32((((r8 << 2) + ((r3 * 92) + r0)) + 68), r5);
    ST32(sp - 52, r3);
    ST32(sp - 48, r6);
    ST32(sp - 44, r7);
    r0 = GCALL8(0x06030250, r10, (r5 + r9), 0, 0, LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
    r7 = LD32(sp - 44);
    r0 = GCALL8(0x06030250, (r7 + r11), r14, 0, 0, LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
    r11 = r11 + 8;
    r10 = r10 + 8;
    r9 = r9 + 0x01000000;
    r1 = LD32(0x06087F78);
    r12 = r12 + 1;
    ST32(0x06087F78, (r1 + r14));
    r3 = LD32(sp - 52);
    r8 = r8 + 1;
    r6 = LD32(sp - 48);
    r7 = LD32(sp - 44);
    if (!(r8 > 3)) {
        POLL();
        goto L06030348;
    }
    r13 = LD32(sp - 36);
    r0 = LD32(sp - 40);
    ST32(sp - 36, (r13 + 1));
    r13 = LD32(sp - 84);
    r3 = (short)(r3 + 1);
    L060303AA:
    r1 = LD16(r0 + r13);
    r0 = LD32(sp - 36);
    c4 = r0 >= r1;
    r1 = 92;
    if (!(c4)) {
        POLL();
        goto L06030308;
    }
    r6 = r6 + 6;
    r13 = LD32(sp - 60);
    r0 = LD32(sp - 40);
    ST32(sp - 60, (r13 + 6));
    r13 = LD32(sp - 72);
    ST32(sp - 40, (r0 + 2));
    r13 = r13 + 1;
    ST32(sp - 72, r13);
    if (!(r13 > 1)) {
        POLL();
        goto L060302E2;
    }
    r0 = LD32(sp - 80);
    r1 = LD32(r0);
    ST8(((r1 + r7) - 2), -1);
    r1 = LD32(r0);
    ST8(((r1 + r7) - 1), -1);
    L060303E2:
    r2 = LD32(0x06087F78);
    ST32(0x06087F7C, r2);
    return r7;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603124C(int r4, int r5, int r6)
{
    int r0, r1, r7, r8, r9, r10, r11, r12, r13, r14, c7, c8, c15, c16, c17, c18, c1020, c1036;
    int v36;
    int v40;
    int v44;

    r14 = r4;
    v44 = r5;
    v40 = r6;
    r13 = 0;
    if (r6 > 0) {
        goto L0603126E;
    }
    goto L060313F0;
    L0603126E:
    r8 = 0x060279E0;
    r0 = GCALL6(0x060279E0, 0, (v40 * 48), -1, 1, v44, v40);
    v36 = r0;
    if (!((r0 & r0) == 0)) {
        goto L0603128A;
    }
    r0 = -3;
    goto L060313F2;
    L0603128A:
    r9 = v40 << 2;
    r0 = GCALL7(r8, 0, r9, -1, 1, v44, v40, v36);
    r12 = r0;
    r7 = 1;
    if (!((r12 & r12) == 0)) {
        goto L060312AA;
    }
    r5 = R(5);
    r6 = R(6);
    r0 = GCALL7(0x06027F48, v36, r5, r6, r7, v44, v40, v36);
    r0 = -3;
    goto L060313F2;
    L060312AA:
    r0 = GCALL7(r8, 0, r9, -1, r7, v44, v40, v36);
    r10 = r0;
    r0 = v40;
    if (!((r10 & r10) == 0)) {
        goto L060312C8;
    }
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL7(0x06027F48, v36, 0, 0, 0, v44, v40, v36);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL7(0x06027F48, r12, 0, 0, 0, v44, v40, v36);
    r0 = -3;
    goto L060313F2;
    L060312C8:
    r11 = r8;
    if (0 >= r0) {
        goto L060312F8;
    }
    r8 = 0;
    L060312D2:
    r4 = LD32(r8 + r14);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL7(0x06025948, r4, 0, 0, 0, v44, v40, v36);
    r1 = r0;
    ST32(r8 + r12, r1);
    r0 = GCALL7(r11, 1, r1, -1, 1, v44, v40, v36);
    r1 = r0;
    r0 = r8;
    r8 = r8 + 4;
    ST32(r0 + r10, r1);
    if (!(r8 >= r9)) {
        POLL();
        goto L060312D2;
    }
    L060312F8:
    r11 = 0;
    c7 = 0 >= v40;
    c1020 = c7;
    if (c7) {
        goto L06031348;
    }
    r9 = v36;
    r8 = 0;
    L06031304:
    r0 = r8;
    r7 = LD32(r0 + r12);
    r6 = LD32(r0 + r10);
    r4 = LD32(r0 + r14);
    r0 = GCALL7(0x060258EC, r4, r9, r6, r7, v44, v40, v36);
    c8 = (r0 & r0) == 0;
    r0 = r8;
    if (c8) {
        goto L06031330;
    }
    r4 = LD32(r0 + r10);
    r1 = 0;
    if ((r4 & r4) == 0) {
        goto L0603132C;
    }
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL7(0x06027F48, r4, 0, 0, 0, v44, v40, v36);
    r1 = 0;
    r0 = r8;
    L0603132C:
    ST32(r0 + r10, r1);
    goto L06031336;
    L06031330:
    r0 = GCALL7(0x060259B4, r9, 0, 0, 0, v44, v40, v36);
    L06031336:
    r9 = r9 + 48;
    r11 = r11 + 1;
    r8 = r8 + 4;
    if (!(r11 >= v40)) {
        POLL();
        goto L06031304;
    }
    r11 = 0;
    c1020 = 0 >= v40;
    L06031348:
    r9 = v44;
    if (c1020) {
        goto L060313E2;
    }
    r8 = 0;
    r14 = v36;
    L06031350:
    r1 = LD32(r8 + r10);
    r0 = r13;
    if ((r1 & r1) == 0) {
        goto L06031372;
    }
    goto L06031364;
    L0603135E:
    r4 = R(4);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL7(0x0605299C, 0, 0, 0, 0, v44, v40, v36);
    L06031364:
    r1 = LD8(r14);
    r13 = r1 & 255;
    r0 = r13;
    if ((r13 & r13) == 0) {
        POLL();
        goto L0603135E;
    }
    if (r0 == 1) {
        POLL();
        goto L0603135E;
    }
    L06031372:
    c15 = r0 == 2;
    r0 = r8;
    if (!(c15)) {
        goto L060313C2;
    }
    r4 = LD32(r0 + r10);
    c16 = (r4 & r4) == 0;
    c1036 = c16;
    if (c16) {
        goto L060313C6;
    }
    r5 = LD32(r0 + r12);
    r0 = GCALL7(0x0603E9B8, r4, r5, 0, 0, v44, v40, v36);
    c17 = (r0 & r0) == 0;
    r0 = r8;
    if (c17) {
        goto L06031398;
    }
    r5 = LD32(r0 + r12);
    r4 = LD32(r0 + r10);
    r0 = 0x06031208;
    r6 = r9;
    goto L060313BC;
    L06031398:
    r5 = LD32(r0 + r12);
    r4 = LD32(r0 + r10);
    r0 = GCALL7(0x0603EDF4, r4, r5, 0, 0, v44, v40, v36);
    c18 = (r0 & r0) == 0;
    r0 = r8;
    if (c18) {
        goto L060313B4;
    }
    r5 = LD32(r0 + r12);
    r4 = LD32(r0 + r10);
    r0 = 0x06031190;
    r6 = r9;
    goto L060313BC;
    L060313B4:
    r5 = LD32(r0 + r12);
    r4 = LD32(r0 + r10);
    r6 = r9;
    r0 = 0x060311D4;
    L060313BC:
    r7 = R(7);
    r0 = GCALL7(r0, r4, r5, r6, r7, v44, v40, v36);
    r0 = r8;
    L060313C2:
    r4 = LD32(r0 + r10);
    c1036 = (r4 & r4) == 0;
    L060313C6:
    if (c1036) {
        goto L060313D4;
    }
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL7(0x06027F48, r4, 0, 0, 0, v44, v40, v36);
    ST32(r8 + r10, 0);
    L060313D4:
    r9 = r9 + 2;
    r14 = r14 + 48;
    r11 = r11 + 1;
    r8 = r8 + 4;
    if (!(r11 >= v40)) {
        POLL();
        goto L06031350;
    }
    L060313E2:
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL7(0x06027F48, v36, 0, 0, 0, v44, v40, v36);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL7(0x06027F48, r12, 0, 0, 0, v44, v40, v36);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL7(0x06027F48, r10, 0, 0, 0, v44, v40, v36);
    L060313F0:
    r0 = 0;
    L060313F2:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060339D0(int r4)
{
    int r0, r1, c4, c6, c7, c8, c1002, c1012;

    r1 = LD32(0x06088028);
    c1002 = (r4 & r4) == 0;
    if (!((r1 & r1) == 0)) {
        goto L060339DE;
    }
    return 0;
    L060339DE:
    if (c1002) {
        goto L06033A0A;
    }
    r1 = LD32(r1 + 4);
    c1012 = (r1 & r1) == 0;
    goto L06033A0E;
    L060339E6:
    return 1;
    L060339EA:
    r0 = LD32(r1);
    c4 = r0 == 2;
    if (!((r0 & r0) == 0)) {
        goto L06033A02;
    }
    r0 = LD32(r1 + 32);
    c6 = r0 == 4;
    if (r0 == 8) {
        POLL();
        goto L060339E6;
    }
    c7 = (r4 & r4) == 0;
    c1002 = c7;
    if (!(c6)) {
        POLL();
        goto L060339DE;
    }
    POLL();
    goto L060339E6;
    L06033A02:
    c8 = (r4 & r4) == 0;
    if (c4) {
        POLL();
        goto L060339E6;
    }
    c1002 = c8;
    POLL();
    goto L060339DE;
    L06033A0A:
    r1 = LD32(r1 + 8);
    c1012 = (r1 & r1) == 0;
    L06033A0E:
    r0 = 0;
    if (!(c1012)) {
        POLL();
        goto L060339EA;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06035264(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 52);

    ST32(sp - 44, r4);
    r2 = LD32(sp + 4);
    r13 = r6;
    r1 = LD32(sp + 8);
    r14 = r7;
    r11 = LD32(sp);
    ST32(sp - 40, ((signed char)r1));
    r12 = r2 - r14;
    r11 = r11 - r13;
    r2 = ((r12 - (((r11 - 4) + ((int)((unsigned)(r11 - 4) >> 31))) >> 1)) + ((int)((unsigned)(r12 - (((r11 - 4) + ((int)((unsigned)(r11 - 4) >> 31))) >> 1)) >> 31))) >> 1;
    r1 = r11;
    if ((unsigned)r5 > (unsigned)1) {
        goto L060352C0;
    }
    r1 = (((int)((unsigned)r1 >> 31)) + r11) >> 1;
    r10 = r13;
    goto L060352CC;
    L060352C0:
    r1 = (((int)((unsigned)r12 >> 31)) + r12) >> 1;
    r10 = r14;
    L060352CC:
    r10 = r10 + r1;
    r1 = r5;
    if (!((unsigned)r5 > (unsigned)3)) {
        goto L060352DA;
    }
    goto L0603543A;
    L060352DA:
    r1 = LD16(0x060352E8 + (r1 + r1));
    switch (r1) {
    case 8:
        goto L060352F0;
    case 100:
        goto L0603534C;
    case 184:
        goto L060353A0;
    case 262:
        goto L060353EE;
    }
    L060352F0:
    r9 = r14 + r2;
    r8 = 0;
    if (!(r9 >= (((r14 + r12) - r2) + 1))) {
        goto L06035306;
    }
    goto L0603543A;
    L06035306:
    r11 = (r11 + ((int)((unsigned)r11 >> 31))) >> 1;
    r1 = r11;
    L06035312:
    r7 = r10;
    if (!(r8 >= (r1 - 2))) {
        goto L0603531E;
    }
    goto L0603543A;
    L0603531E:
    r3 = LD32(sp - 40);
    ST32((sp - 48), r3);
    ST32((sp - 52), r9);
    r4 = LD32(sp - 44);
    ST32(sp - 36, r2);
    r0 = GCALL8(0x06014C4C, r4, (r10 - r8), r9, (r7 + r8), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
    r9 = r9 + 1;
    r2 = LD32(sp - 36);
    r8 = r8 + 1;
    if (r9 >= (((r14 + r12) - r2) + 1)) {
        goto L0603543A;
    }
    r1 = r11;
    POLL();
    goto L06035312;
    L0603534C:
    r9 = (r14 + r12) - r2;
    r8 = 0;
    if (!(r9 > ((r14 + r2) - 1))) {
        goto L0603543A;
    }
    r11 = (r11 + ((int)((unsigned)r11 >> 31))) >> 1;
    r1 = r11;
    L0603536C:
    r7 = r10;
    if (r8 >= (r1 - 2)) {
        goto L0603543A;
    }
    r3 = LD32(sp - 40);
    ST32((sp - 48), r3);
    ST32((sp - 52), r9);
    r4 = LD32(sp - 44);
    ST32(sp - 36, r2);
    r0 = GCALL8(0x06014C4C, r4, (r10 - r8), r9, (r7 + r8), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
    r9 = r9 - 1;
    r2 = LD32(sp - 36);
    r8 = r8 + 1;
    if (!(r9 > ((r14 + r2) - 1))) {
        goto L0603543A;
    }
    r1 = r11;
    POLL();
    goto L0603536C;
    L060353A0:
    r8 = r13 + 6;
    r9 = 0;
    if (r8 >= ((r13 + r11) - 6)) {
        goto L0603543A;
    }
    r12 = (r12 + ((int)((unsigned)r12 >> 31))) >> 1;
    r1 = r12;
    L060353BC:
    r6 = r10;
    if (r9 >= (r1 - 1)) {
        goto L0603543A;
    }
    r3 = LD32(sp - 40);
    ST32((sp - 48), r3);
    ST32((sp - 52), (r10 + r9));
    r4 = LD32(sp - 44);
    r0 = GCALL8(0x06014C4C, r4, r8, (r6 - r9), r8, LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
    r8 = r8 + 1;
    r9 = r9 + 1;
    if (r8 >= ((r13 + r11) - 6)) {
        goto L0603543A;
    }
    r1 = r12;
    POLL();
    goto L060353BC;
    L060353EE:
    r8 = (r13 + r11) - 6;
    r9 = 0;
    if (!(r8 > (r13 + 6))) {
        goto L0603543A;
    }
    r11 = (r12 + ((int)((unsigned)r12 >> 31))) >> 1;
    L0603540C:
    r6 = r10;
    if (r9 >= (r11 - 1)) {
        goto L0603543A;
    }
    r3 = LD32(sp - 40);
    ST32((sp - 48), r3);
    ST32((sp - 52), (r10 + r9));
    r4 = LD32(sp - 44);
    r0 = GCALL8(0x06014C4C, r4, r8, (r6 - r9), r8, LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
    r8 = r8 - 1;
    r9 = r9 + 1;
    if (r8 > (r13 + 6)) {
        POLL();
        goto L0603540C;
    }
    L0603543A:
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060384AC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c5, c7, c10, c13, c15, c23, c33, c1012, c1031, c1037;
    FRAME(sp, 336);

    r12 = r4;
    ST32(0x120 + (sp - 328), r5);
    r14 = r6;
    r13 = r7;
    r9 = 0;
    r8 = 0x100;
    r0 = GCALL1(0x060287D0, 0x100);
    r2 = r0;
    ST32(sp - 328, r2);
    if (!((r2 & r2) == 0)) {
        goto L060384E0;
    }
    r0 = 0;
    goto L06038780;
    L060384E0:
    ST8(r2, 0);
    ST32(sp - 324, r8);
    ST32(sp - 320, r9);
    r2 = 1;
    ST32(sp - 316, 1);
    r1 = LD32(r14 + 12);
    ST32((0x124 + (sp - 328)), r1);
    if (!((r1 & r1) == 0)) {
        goto L06038500;
    }
    ST32((0x124 + (sp - 328)), 0x06033094);
    L06038500:
    r11 = LD32(r14 + 16);
    r1 = r11;
    if (!((r11 & r11) == 0)) {
        goto L06038530;
    }
    r8 = 0x06037EE8;
    r5 = LD32((0x124 + (sp - 328)));
    r0 = GCALL8(0x06037EE8, (sp - 328), r5, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    if (!((r0 & r0) == 0)) {
        goto L0603851E;
    }
    goto L0603874C;
    L0603851E:
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r8, (sp - 328), 0x06038458, r6, r7, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    if (!((r0 & r0) == 0)) {
        goto L0603852C;
    }
    goto L0603874C;
    L0603852C:
    r8 = LD32(r14);
    goto L0603853A;
    L06038530:
    c5 = (unsigned)(r1 - 2) > (unsigned)r2;
    c1012 = c5;
    if (c5) {
        goto L06038538;
    }
    r9 = r2;
    c1012 = 0;
    L06038538:
    r8 = LD32(r14);
    L0603853A:
    c7 = (r11 & r11) == 0;
    c1037 = c7;
    if ((r8 & r8) == 0) {
        goto L0603861E;
    }
    r10 = 0x06027F48;
    L06038542:
    r2 = LD32(r8);
    r0 = r2;
    r1 = 1;
    if (r0 == 1) {
        goto L060385EC;
    }
    c10 = (r2 & r2) == 0;
    if (r2 > r1) {
        goto L0603855A;
    }
    if (c10) {
        goto L06038564;
    }
    r8 = LD32(r8 + 4);
    goto L06038618;
    L0603855A:
    r7 = r9;
    if (r0 == 2) {
        goto L06038604;
    }
    r8 = LD32(r8 + 4);
    goto L06038618;
    L06038564:
    r3 = LD32((0x150 + (sp - 328)));
    c13 = (r13 & r13) == 0;
    if (!(r8 == r3)) {
        goto L060385C8;
    }
    r0 = r11;
    if (c13) {
        goto L060385C8;
    }
    r1 = LD32(sp - 316);
    if (r0 == 2) {
        goto L060385C8;
    }
    c15 = (r1 & r1) == 0;
    r1 = 0;
    if (!(c15)) {
        goto L060385B8;
    }
    r0 = GCALL8(0x06037EE8, (sp - 328), 0x06037FB4, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r5 = r13;
    if (!((r0 & r0) == 0)) {
        goto L060385BC;
    }
    goto L060385FC;
    L060385B8:
    ST32(sp - 316, r1);
    r5 = r13;
    L060385BC:
    r0 = GCALL8(0x06037EE8, (sp - 328), r5, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    c1031 = (r0 & r0) == 0;
    goto L060385FA;
    L060385C8:
    r3 = LD32((0x14C + (sp - 328)));
    ST32((sp - 332), r3);
    r0 = LD32(0x14C + (sp - 332));
    ST32((sp - 336), r0);
    r0 = GCALL8(0x0603807C, 0, r8, (sp - 328), r9, LD32((sp - 336)), LD32((sp - 332)), LD32((sp - 328)), LD32((sp - 324)));
    c1031 = (r0 & r0) == 0;
    goto L060385FA;
    L060385EC:
    r0 = GCALL8(0x060382AC, 0, r8, (sp - 328), r9, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    c1031 = (r0 & r0) == 0;
    L060385FA:
    if (!(c1031)) {
        goto L06038616;
    }
    L060385FC:
    r4 = LD32(sp - 328);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r10, r4, r5, r6, r7, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r0 = 0;
    goto L06038780;
    L06038604:
    r0 = GCALL8(0x06038384, 0, r8, (sp - 328), r7, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    if (!((r0 & r0) == 0)) {
        goto L06038616;
    }
    goto L0603874C;
    L06038616:
    r8 = LD32(r8 + 4);
    L06038618:
    c1037 = (r11 & r11) == 0;
    if (!((r8 & r8) == 0)) {
        POLL();
        goto L06038542;
    }
    L0603861E:
    r0 = r11;
    if (!(c1037)) {
        goto L06038638;
    }
    r5 = LD32(sp - 328);
    r0 = GCALL8(0x0603CCE0, 0x060767CC, r5, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r4 = LD32(sp - 328);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    ST32(0x060766C0, -6);
    goto L06038720;
    L06038638:
    c23 = r0 == 1;
    r0 = r11;
    if (!(c23)) {
        goto L06038722;
    }
    r8 = 0x100;
    r0 = GCALL8(0x060287D0, 0x100, 0, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r2 = r0;
    r9 = (sp - 328) + 16;
    ST32(sp - 312, r2);
    if ((r2 & r2) == 0) {
        goto L0603874C;
    }
    ST8(r2, 0);
    ST32(sp - 308, r8);
    ST32(sp - 304, 0);
    ST32(sp - 300, 1);
    r8 = 0x06037EE8;
    r0 = GCALL8(0x06037EE8, r9, 0x0603845C, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    if ((r0 & r0) == 0) {
        goto L06038712;
    }
    r4 = LD32(r14 + 20);
    if ((r4 & r4) == 0) {
        goto L060386BC;
    }
    r0 = GCALL8(0x0607507C, r4, 0, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    if ((r0 & r0) == 0) {
        goto L060386BC;
    }
    r5 = LD32(r14 + 20);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r8, r9, r5, r6, r7, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    if ((r0 & r0) == 0) {
        goto L06038712;
    }
    goto L060386CA;
    L060386BC:
    r0 = GCALL8(0x06037EE8, (sp - 312), 0x0603846C, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    if ((r0 & r0) == 0) {
        goto L06038712;
    }
    L060386CA:
    r12 = 0x06038490;
    r9 = (sp - 328) + 16;
    r10 = 0x06037EE8;
    r0 = GCALL8(0x06037EE8, r9, 0x06038490, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    if ((r0 & r0) == 0) {
        goto L06038712;
    }
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r10, r9, 0x06038494, r6, r7, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    if ((r0 & r0) == 0) {
        goto L06038712;
    }
    r4 = LD32(sp - 328);
    r0 = GCALL8(0x0607507C, r4, 0, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r8 = (sp - 328) + 32;
    r7 = R(7);
    r0 = GCALL8(0x06045264, r8, 0x060384A8, r0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r10, r9, r8, r6, r7, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r5 = r12;
    if ((r0 & r0) == 0) {
        goto L06038712;
    }
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r10, r9, r5, r6, r7, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    c33 = (r0 & r0) == 0;
    r0 = r11;
    if (!(c33)) {
        goto L06038722;
    }
    L06038712:
    r4 = LD32(sp - 328);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r4 = LD32(sp - 312);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r0 = 0;
    goto L06038780;
    L06038720:
    r0 = r11;
    L06038722:
    r2 = r11;
    if (!(r0 == 1)) {
        goto L06038756;
    }
    r5 = LD32((0x124 + (sp - 328)));
    r0 = GCALL8(0x0603CCE0, 0x060767CC, r5, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    ST32(0x060766C0, -6);
    r2 = LD32((0x120 + (sp - 328)));
    r3 = 0x120 + (sp - 328);
    r1 = LD32(sp - 312);
    ST32((r2 + 100), r1);
    goto L06038776;
    L0603874C:
    r4 = LD32(sp - 328);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    r0 = 0;
    goto L06038780;
    L06038756:
    r0 = 1;
    if ((unsigned)(r2 - 2) > (unsigned)1) {
        goto L06038780;
    }
    r5 = LD32((0x124 + (sp - 328)));
    r0 = GCALL8(0x0603CCE0, 0x060767CC, r5, 0, 0, LD32((sp - 328)), LD32((sp - 324)), LD32((sp - 320)), LD32((sp - 316)));
    ST32(0x060766C0, -6);
    r3 = 0x120 + (sp - 328);
    L06038776:
    r2 = LD32(r3);
    r1 = LD32(sp - 328);
    ST32((r2 + 104), r1);
    r0 = 1;
    L06038780:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06038A7C(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, c2, c6, c7, c8, c9, c10, c1012, c1013;

    r10 = r4;
    r11 = LD32(0x060759B4);
    r9 = r5;
    r0 = GCALL0(0x06033088);
    if ((r0 & r0) == 0) {
        goto L06038B20;
    }
    r2 = 0x06038A10;
    L06038A98:
    r8 = LD32(r0);
    r1 = r8;
    if ((r8 & r8) == 0) {
        goto L06038B1A;
    }
    L06038AA0:
    r1 = LD16((r1 + 12));
    c2 = r1 >= r10;
    r1 = r8;
    if (c2) {
        goto L06038B12;
    }
    r1 = LD16((r1 + 14));
    if (!(r1 > r10)) {
        goto L06038B12;
    }
    r1 = LD32(r8 + 16);
    if ((r1 - r11) >= r9) {
        goto L06038B12;
    }
    r1 = LD32(r8 + 20);
    r6 = r9;
    if (!((r1 - r11) > r9)) {
        goto L06038B12;
    }
    r0 = GCALL3(r2, r8, r10, r6);
    r7 = r0;
    r0 = LD32(r8);
    c6 = r0 == 1;
    r1 = r8;
    c1013 = c6;
    if (!(c6)) {
        goto L06038B0E;
    }
    r2 = LD16((r1 + 64));
    c7 = r2 > 1;
    r1 = r7;
    c1013 = c7;
    if (!(c7)) {
        goto L06038B0E;
    }
    r2 = LD16((r1 + 8));
    r1 = LD16((r8 + 36));
    c8 = r2 >= r1;
    r3 = LD32(r7 + 24);
    c1013 = c8;
    if (!(c8)) {
        goto L06038B0E;
    }
    r1 = LD16((r8 + 32));
    c9 = r3 >= r1;
    r1 = r8;
    c1012 = c9;
    if (!(c9)) {
        goto L06038B06;
    }
    r1 = LD16((r1 + 34));
    c10 = r3 > r1;
    r0 = r7;
    c1012 = c10;
    if (!(c10)) {
        goto L06038B22;
    }
    L06038B06:
    ST8((r7 + 11), 1);
    c1013 = c1012;
    L06038B0E:
    r0 = r7;
    goto L06038B22;
    L06038B12:
    r8 = LD32(r8 + 4);
    r1 = r8;
    if (!((r8 & r8) == 0)) {
        POLL();
        goto L06038AA0;
    }
    L06038B1A:
    r0 = LD32(r0 + 28);
    if (!((r0 & r0) == 0)) {
        POLL();
        goto L06038A98;
    }
    L06038B20:
    r0 = 0;
    L06038B22:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06039FD8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8, r9, r10, r11, r12;

    r8 = r4;
    r1 = LD32((r8 + 100));
    r9 = r8;
    if (!((r1 & r1) == 0)) {
        goto L06039FFC;
    }
    r0 = GCALL4(0x0603AB28, r4, 0, r6, r7);
    r0 = -1;
    goto L0603A072;
    L06039FFC:
    r10 = 0x06039B14;
    r11 = 255;
    r12 = 0x0603AB28;
    r9 = r9 + 120;
    goto L0603A01E;
    L0603A006:
    r0 = LD32(r9);
    if (r0 == -1) {
        goto L0603A014;
    }
    r1 = LD32(0x1DE8 + r8);
    if ((r1 & r1) == 0) {
        goto L0603A01E;
    }
    L0603A014:
    r0 = GCALL1(r12, r8);
    r0 = -312;
    goto L0603A074;
    L0603A01E:
    r0 = GCALL1(r10, r8);
    ST32(r9, r0);
    if (!(r0 == r11)) {
        POLL();
        goto L0603A006;
    }
    r0 = GCALL1(r10, r8);
    ST32(r9, r0);
    r3 = r8;
    if (!((r0 & 248) == 208)) {
        POLL();
        goto L0603A01E;
    }
    r3 = r3 + 108;
    r0 = LD32((r8 + 120));
    ST32(r3, (r0 & 7));
    ST32((r8 + 96), 1);
    r1 = LD32(r3);
    ST32((r8 + 104), ((r1 + 1) & 7));
    ST32((r8 + 116), 0);
    ST32((r8 + 124), -1);
    r0 = GCALL1(0x06039178, r8);
    r0 = 0;
    L0603A072:
    L0603A074:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603A458(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c6, c9, c12, c13, c15, c1013, c1018;
    long long m0;
    int v36;
    int v40;

    r10 = r4;
    v40 = r7;
    ST32((r10 + 80), 0);
    ST32((r10 + 84), 0);
    ST32((r10 + 88), 0);
    v36 = 0;
    r1 = LD32(r10 + 0x1DE0);
    r1 = LD32(r1);
    r14 = 0x1DE0;
    if (!(v36 >= r1)) {
        goto L0603A49A;
    }
    goto L0603A660;
    L0603A49A:
    r13 = 0;
    L0603A49C:
    r0 = GCALL6(0x06028380, 52, 7, 0, 0, v40, v36);
    r9 = r0;
    r1 = r10;
    if (!((r9 & r9) == 0)) {
        goto L0603A4B0;
    }
    goto L0603A636;
    L0603A4B0:
    ST32(r9, v36);
    r5 = LD8((r1 + 42));
    r0 = GCALL6(0x0607290C, 1, (r5 - 1), 0, 0, v40, v36);
    ST32(r9 + 36, r0);
    ST32(r9 + 8, v40);
    ST32(r9 + 12, 0);
    ST32(r9 + 16, 0);
    r1 = LD32(r10 + r14);
    r1 = LD32(140 + (r1 + r13));
    r1 = LD32(((r1 << 2) + r10) + 0x15DC);
    ST32(r9 + 28, r1);
    r1 = LD32(r10 + r14);
    r1 = LD32(140 + (r1 + r13));
    r1 = LD32(((r1 << 2) + r10) + 0x19DC);
    ST32(r9 + 32, r1);
    r1 = LD32(r10 + r14);
    r2 = LD32(r1);
    r1 = r1 + r13;
    if (!(r2 == 1)) {
        goto L0603A524;
    }
    ST32(r9 + 20, 1);
    ST32(r9 + 24, 1);
    goto L0603A54E;
    L0603A524:
    r1 = LD32(140 + r1);
    r1 = LD32(((r1 << 2) + r10) + 0x9DC);
    ST32(r9 + 20, r1);
    r1 = LD32(r10 + r14);
    r1 = LD32(140 + (r1 + r13));
    r1 = LD32(((r1 << 2) + r10) + 0xDDC);
    ST32(r9 + 24, r1);
    L0603A54E:
    r4 = LD32(r9 + 24);
    r4 = (r4 << 2) + (r4 << 2);
    ST32(r9 + 4, r4);
    r0 = GCALL6(0x06028380, (r4 << 2), 7, 0, 0, v40, v36);
    r1 = r0;
    ST32(r9 + 40, r1);
    if ((r1 & r1) == 0) {
        goto L0603A636;
    }
    r12 = 0;
    r8 = r1;
    r1 = LD32(r9 + 4);
    r11 = 0;
    if ((unsigned)r8 >= (unsigned)((r1 << 2) + r8)) {
        goto L0603A5D8;
    }
    L0603A576:
    r4 = LD32(r10);
    r0 = GCALL6(0x0603A394, r4, v40, 0, 0, v40, v36);
    r1 = r0;
    ST32(r8, r1);
    if ((r1 & r1) == 0) {
        goto L0603A636;
    }
    ST32(r1 + 16, r11);
    r1 = LD32(r8);
    ST32(r1 + 32, r9);
    r2 = LD32(r8);
    ST32(r2, 0);
    r2 = LD32(r9 + 32);
    c6 = (r2 & r2) == 0;
    c1013 = c6;
    if (c6) {
        goto L0603A5AA;
    }
    r1 = LD32(r9 + 40);
    c9 = (((r8 - r1) >> 1) >> 1) >= (r2 - 1);
    c1013 = c9;
    if (c9) {
        goto L0603A5C8;
    }
    L0603A5AA:
    r1 = LD32(r10 + r14);
    r1 = LD32(140 + (r1 + r13));
    r1 = LD32(((r1 << 2) + r10) + 0x15DC);
    r11 = r11 + (r1 * v40);
    L0603A5C8:
    r2 = LD32(r9 + 4);
    r8 = r8 + 4;
    r1 = LD32(r9 + 40);
    r12 = r12 + 1;
    if (!((unsigned)r8 >= (unsigned)(r1 + (r2 << 2)))) {
        POLL();
        goto L0603A576;
    }
    L0603A5D8:
    r1 = LD32((r8 - 4));
    ST32(r1, 1);
    r1 = LD32(r10);
    c12 = r1 * r12;
    m0 = (unsigned)c12;
    c13 = v36 > 1;
    r3 = c12;
    c1018 = c13;
    if (!(c13)) {
        goto L0603A610;
    }
    r1 = LD32(r10 + r14);
    r1 = LD32(140 + r1);
    r1 = LD32(((r1 << 2) + r10) + 0x9DC);
    r5 = r3;
    if (!(r1 == 2)) {
        goto L0603A612;
    }
    r3 = (int)m0;
    c15 = r3 & 1;
    r3 = r3 >> 1;
    c1018 = c15;
    L0603A610:
    r5 = r3;
    L0603A612:
    r5 = r5 + 8;
    if (r5 >= 0) {
        goto L0603A61C;
    }
    r5 = r3 + 15;
    L0603A61C:
    r0 = GCALL6(0x060279E0, 1, (((((r5 >> 1) >> 1) >> 1) << 2) + ((((r5 >> 1) >> 1) >> 1) << 2)), 7, 1, v40, v36);
    ST32(r9 + 44, r0);
    if (!((r0 & r0) == 0)) {
        goto L0603A63A;
    }
    L0603A636:
    r0 = -3;
    goto L0603A662;
    L0603A63A:
    ST32(r9 + 48, 0);
    r1 = LD32(r10 + r14);
    ST32(((r1 + r13) + 76), r9);
    v36 = v36 + 1;
    r1 = LD32(r10 + r14);
    r1 = LD32(r1);
    r13 = r13 + 4;
    if (v36 >= r1) {
        goto L0603A660;
    }
    POLL();
    goto L0603A49C;
    L0603A660:
    r0 = 0;
    L0603A662:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603B6E0(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, r14, c15, c16, c20;
    FRAME(sp, 556);

    r8 = r4;
    r10 = r5;
    r7 = LD32(r10);
    ST32((0x204 + (sp - 556)), r7);
    ST32(r8 + 0x1DE8, 0);
    r0 = LD32(0x204 + (sp - 556));
    if (r0 == 1) {
        goto L0603B714;
    }
    goto L0603B834;
    L0603B714:
    r0 = GCALL1(0x0603A2DC, r4);
    r1 = LD32(r8 + 60);
    r0 = r8;
    if (r1 >= 0) {
        goto L0603B762;
    }
    r1 = LD32(r0 + 0x1DE0);
    r6 = LD32(r8 + 56);
    r4 = r6;
    r1 = LD32((r1 + 68));
    ST32((0x208 + (sp - 556)), r1);
    r5 = LD32((0x208 + (sp - 556)));
    r7 = LD32((0x208 + (sp - 556)));
    r0 = GCALL2(0x0607286C, r4, r5);
    if (!(((r6 - (r0 * r7)) & (r6 - (r0 * r7))) == 0)) {
        goto L0603B762;
    }
    r0 = GCALL1(0x0603970C, r4);
    if (!(r0 == 220)) {
        goto L0603B762;
    }
    r0 = GCALL1(0x06039F2C, r8);
    L0603B762:
    r1 = LD32(0x1DE8 + r8);
    if (!((r1 & r1) == 0)) {
        goto L0603B7CA;
    }
    r2 = LD32(r8 + 60);
    r5 = r8;
    if (!(r2 >= 0)) {
        goto L0603B77E;
    }
    r1 = LD32(r8 + 56);
    r0 = 0;
    if (!(r1 >= r2)) {
        goto L0603B77E;
    }
    goto L0603BA0A;
    L0603B77E:
    r5 = r5 + 41;
    r1 = LD8(r5);
    r2 = r8;
    if ((r1 & r1) == 0) {
        goto L0603B78E;
    }
    ST32((r2 + 100), 1);
    L0603B78E:
    r6 = LD32(r8 + 56);
    if ((r6 & r6) == 0) {
        goto L0603B82E;
    }
    r9 = LD8(r5);
    r4 = r6;
    if ((r9 & r9) == 0) {
        goto L0603B82E;
    }
    r7 = 0x0607286C;
    r5 = r9;
    r0 = GCALL2(0x0607286C, r4, r5);
    r1 = r8;
    if (!(((r6 - (r0 * r9)) & (r6 - (r0 * r9))) == 0)) {
        goto L0603B82E;
    }
    r1 = LD32((r1 + 96));
    r6 = r8;
    if (!((r1 & r1) == 0)) {
        goto L0603B7FC;
    }
    r0 = GCALL4(0x0603A0B4, r8, r5, r6, r7);
    r1 = LD32(0x1DE8 + r8);
    r6 = r8;
    if ((r1 & r1) == 0) {
        goto L0603B7FC;
    }
    L0603B7CA:
    r0 = GCALL1(0x0603A338, r8);
    ST32(r10, 1);
    r0 = -1;
    goto L0603BA0A;
    L0603B7FC:
    r6 = r6 + 96;
    r1 = LD32(r6);
    c15 = (r1 & r1) == 0;
    r1 = r8;
    if (c15) {
        goto L0603B828;
    }
    r5 = LD8((r1 + 41));
    r4 = LD32(r8 + 56);
    r0 = GCALL2(0x0607286C, r4, r5);
    r1 = LD32((r8 + 108));
    c16 = (7 & r0) == ((r1 + 1) & 7);
    r1 = 0;
    if (!(c16)) {
        goto L0603B828;
    }
    ST32(r6, r1);
    L0603B828:
    r0 = GCALL1(0x06039178, r8);
    L0603B82E:
    r0 = GCALL1(0x0603A2DC, r8);
    L0603B834:
    r0 = LD32(0x204 + (sp - 556));
    if ((r0 & r0) == 0) {
        goto L0603B842;
    }
    r1 = LD32(r10);
    ST32(r10, (r1 + 1));
    L0603B842:
    r1 = LD32(r8 + 0x1DE0);
    r1 = LD32(r1);
    r11 = 0;
    if (!(0 >= r1)) {
        goto L0603B854;
    }
    goto L0603B9E4;
    L0603B854:
    r14 = (sp - 556) + 0x100;
    L0603B85A:
    r7 = LD32((0x204 + (sp - 556)));
    r5 = r11;
    if (!((r7 & r7) == 0)) {
        goto L0603B874;
    }
    r0 = GCALL2(0x060391A4, r8, r5);
    r0 = GCALL2(0x0603AB10, r8, r11);
    L0603B874:
    r2 = LD32(0x1DE0 + r8);
    r1 = LD32(r2);
    c20 = r1 == 1;
    r1 = r11;
    if (!(c20)) {
        goto L0603B88E;
    }
    ST32((0x200 + (sp - 556)), 1);
    r13 = 1;
    goto L0603B8AE;
    L0603B88E:
    r1 = LD32((r2 + (r1 << 2)) + 140);
    r0 = (r1 << 2) + r8;
    r13 = LD32(r0 + 0x9DC);
    r2 = LD32(r0 + 0xDDC);
    ST32((0x200 + (sp - 556)), r2);
    L0603B8AE:
    r0 = LD32(0x200 + (sp - 556));
    r12 = 0;
    if (!(0 >= r0)) {
        goto L0603B8BC;
    }
    goto L0603B9D4;
    L0603B8BC:
    r10 = r11 << 2;
    L0603B8C0:
    r9 = 0;
    r1 = r8;
    if (!(0 >= r13)) {
        goto L0603B8CC;
    }
    goto L0603B9C4;
    L0603B8CC:
    r1 = LD32((r1 + 96));
    r2 = r10;
    if ((r1 & r1) == 0) {
        goto L0603B8E0;
    }
    r0 = GCALL1(0x0603C02C, (sp - 556));
    goto L0603B9AC;
    L0603B8E0:
    r1 = LD32(0x1DE0 + r8);
    r5 = LD32((r2 + r1) + 0x10C);
    r0 = GCALL2(0x060390CC, r8, r5);
    ST32(sp - 556, r0);
    r0 = LD32(0x204 + (sp - 556));
    if ((r0 & r0) == 0) {
        goto L0603B906;
    }
    r1 = LD32(0x1DE8 + r8);
    if (!((r1 & r1) == 0)) {
        goto L0603B9FA;
    }
    L0603B906:
    r1 = LD32(0x1DE0 + r8);
    r6 = LD32((r10 + r1) + 204);
    r0 = GCALL5(0x06038FF0, r8, (sp - 556), r6, 0, LD32((sp - 556)));
    r7 = LD32((0x204 + (sp - 556)));
    r5 = r14;
    if ((r7 & r7) == 0) {
        goto L0603B968;
    }
    r1 = LD32(0x1DE8 + r8);
    if ((r1 & r1) == 0) {
        goto L0603B9AC;
    }
    goto L0603B9FA;
    L0603B968:
    r0 = GCALL5(0x0603C004, (sp - 556), r5, 0, 0, LD32((sp - 556)));
    r1 = LD32(0x1DE0 + r8);
    r1 = LD32((r10 + r1) + 140);
    r1 = LD32(((r1 << 2) + r8) + 0x11DC);
    r5 = LD32(((r1 << 2) + r8) + 132);
    r0 = GCALL5(0x0603BFAC, r14, r5, 0, 0, LD32((sp - 556)));
    r0 = GCALL5(0x0603BC80, r14, (sp - 556), 0, 0, LD32((sp - 556)));
    r0 = GCALL5(0x0603BFD8, (sp - 556), 128, 255, 0, LD32((sp - 556)));
    L0603B9AC:
    r0 = LD32(0x204 + (sp - 556));
    r5 = sp - 556;
    if (!((r0 & r0) == 0)) {
        goto L0603B9BC;
    }
    r0 = GCALL5(0x0603A890, r8, r5, 0, 0, LD32((sp - 556)));
    L0603B9BC:
    r9 = r9 + 1;
    r1 = r8;
    if (!(r9 >= r13)) {
        POLL();
        goto L0603B8CC;
    }
    L0603B9C4:
    r7 = LD32((0x200 + (sp - 556)));
    r12 = r12 + 1;
    if (r12 >= r7) {
        goto L0603B9D4;
    }
    POLL();
    goto L0603B8C0;
    L0603B9D4:
    r1 = LD32(0x1DE0 + r8);
    r1 = LD32(r1);
    r11 = r11 + 1;
    if (r11 >= r1) {
        goto L0603B9E4;
    }
    POLL();
    goto L0603B85A;
    L0603B9E4:
    r7 = LD32((0x204 + (sp - 556)));
    r0 = 0;
    if ((r7 & r7) == 0) {
        goto L0603BA04;
    }
    r0 = GCALL5(0x0603A338, r8, 0, 0, 0, LD32((sp - 556)));
    r0 = 0;
    goto L0603BA0A;
    L0603B9FA:
    r0 = GCALL5(0x0603A338, r8, 0, 0, 0, LD32((sp - 556)));
    r0 = -1;
    goto L0603BA0A;
    L0603BA04:
    r1 = LD32(r8 + 56);
    ST32(r8 + 56, (r1 + 1));
    L0603BA0A:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603C0BC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c7, c10, c12;
    int v36;
    int v40;

    r12 = r4;
    r14 = r5;
    v40 = r6;
    v36 = r7;
    r2 = LD32(r12);
    r13 = 0;
    r1 = LD8(r2);
    r8 = 0;
    r0 = r1 & 255;
    r1 = 0x06075135;
    r0 = LD8(r0 + 0x06075135);
    r10 = 0;
    if (((r0 & 8) & (r0 & 8)) == 0) {
        goto L0603C106;
    }
    r3 = r1;
    r10 = r10 + 1;
    L0603C0F0:
    r1 = LD8(r2 + r10);
    r1 = LD8((r1 & 255) + r3);
    r10 = r10 + 1;
    if (!(((r1 & 8) & (r1 & 8)) == 0)) {
        POLL();
        goto L0603C0F0;
    }
    r10 = r10 - 1;
    L0603C106:
    if (!(r10 > 0)) {
        goto L0603C114;
    }
    r4 = LD32(r12);
    r0 = GCALL6(0x060750DC, r4, (r4 + r10), 0, 0, v40, v36);
    L0603C114:
    r4 = LD32(r12);
    r0 = GCALL6(0x0607507C, r4, 0, 0, 0, v40, v36);
    r7 = r0;
    r10 = 0;
    r11 = 0;
    if (0 >= r7) {
        goto L0603C21A;
    }
    L0603C124:
    r0 = LD32(r12);
    r3 = LD8(r0 + r10);
    r2 = r3 - 34;
    r1 = r2;
    if ((unsigned)r2 > (unsigned)29) {
        goto L0603C20E;
    }
    r1 = LD16(0x0603C140 + (r1 + r1));
    switch (r1) {
    case 212:
        goto L0603C214;
    case 60:
        goto L0603C17C;
    case 206:
        goto L0603C20E;
    case 128:
        goto L0603C1C0;
    case 186:
        goto L0603C1FA;
    }
    L0603C17C:
    r0 = LD32(r12);
    r8 = 0;
    r1 = LD8(r0 + r10);
    r9 = r0 + r10;
    goto L0603C18C;
    L0603C188:
    r1 = LD8(r9);
    r8 = r8 + 1;
    L0603C18C:
    r9 = r9 + 1;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L0603C188;
    }
    r0 = GCALL6(0x060279E0, 0, (r8 + 1), -1, 1, v40, v36);
    r13 = r0;
    if ((r13 & r13) == 0) {
        goto L0603C25E;
    }
    r5 = LD32(r12);
    r0 = GCALL6(0x0604B358, r13, (r5 + r10), r8, 0, v40, v36);
    ST8(r13 + r8, 0);
    r10 = r10 + r8;
    goto L0603C21A;
    L0603C1C0:
    r1 = LD32(r12);
    r1 = LD8(((r1 + r10) + 1));
    c7 = (r1 & 255) == 47;
    r1 = r10;
    if (!(c7)) {
        goto L0603C1D4;
    }
    r10 = r10 + 1;
    goto L0603C1F6;
    L0603C1D4:
    ST8(r14 + r11, r3);
    r2 = LD32(r12);
    r1 = LD8(((r1 + r2) + 1));
    r11 = r11 + 1;
    if (!((r1 & 255) == 46)) {
        goto L0603C1F6;
    }
    r10 = r10 + 1;
    r1 = LD8(r2 + r10);
    ST8(r14 + r11, r1);
    r11 = r11 + 1;
    L0603C1F6:
    r8 = 1;
    goto L0603C214;
    L0603C1FA:
    r1 = LD32(r12);
    r1 = LD8(((r1 + r10) + 1));
    c10 = (r8 & r8) == 0;
    if (!((r1 & 255) == 47)) {
        goto L0603C20E;
    }
    if (!(c10)) {
        goto L0603C214;
    }
    r8 = 1;
    L0603C20E:
    ST8(r14 + r11, r3);
    r11 = r11 + 1;
    L0603C214:
    r10 = r10 + 1;
    if (!(r10 >= r7)) {
        POLL();
        goto L0603C124;
    }
    L0603C21A:
    r3 = 0;
    ST8(r14 + r11, 0);
    r5 = r11 + r14;
    r2 = r5 - 1;
    r1 = LD8(r2);
    c12 = (r1 & 255) == 46;
    r1 = r5;
    if (!(c12)) {
        goto L0603C240;
    }
    r1 = LD8((r1 - 2));
    if (!((r1 & 255) == 47)) {
        goto L0603C240;
    }
    ST8(r2, r3);
    L0603C240:
    r5 = r10 + 16;
    r8 = 0x060279E0;
    ST32(v40, r5);
    r0 = GCALL6(0x060279E0, 0, r5, -1, 1, v40, v36);
    r2 = r0;
    ST32((r12 + 116), r2);
    if (!((r2 & r2) == 0)) {
        goto L0603C262;
    }
    L0603C25E:
    r0 = -3;
    goto L0603C2D2;
    L0603C262:
    ST8(r2, 0);
    if ((r13 & r13) == 0) {
        goto L0603C2CC;
    }
    r1 = LD8(r13);
    r9 = r13;
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L0603C2CC;
    }
    r3 = r8;
    r10 = 128;
    r11 = 0x0604B358;
    L0603C27A:
    r1 = LD8(r9);
    r1 = r1 & 255;
    r8 = 0;
    if (!(r1 == 35)) {
        goto L0603C2C2;
    }
    r2 = r9;
    if ((r1 & r1) == 0) {
        goto L0603C298;
    }
    L0603C28C:
    r2 = r2 + 1;
    r1 = LD8(r2);
    r8 = r8 + 1;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L0603C28C;
    }
    L0603C298:
    r0 = GCALL6(r3, 0, (r8 + 1), -1, 1, v40, v36);
    r1 = r0;
    ST32(r12 + r10, r1);
    if ((r1 & r1) == 0) {
        POLL();
        goto L0603C25E;
    }
    r7 = R(7);
    r0 = GCALL6(r11, r1, r9, r8, r7, v40, v36);
    r2 = LD32(r12 + r10);
    ST8(r2 + r8, 0);
    goto L0603C2CC;
    L0603C2C2:
    r9 = r9 + 1;
    r1 = LD8(r9);
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L0603C27A;
    }
    L0603C2CC:
    ST32(v36, r13);
    r0 = 0;
    L0603C2D2:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603C2FC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c3, c10, c16, c20, c25, c26, c29, c32, c41, c49, c51, c60, c62, c68, c71, c76, c79, c83, c84, c96, c105, c112, c114, c117, c127, c1100, c1143, c1158, c1177, c1190, c1213;
    FRAME(sp, 2164);

    r12 = r4;
    ST32(0x848 + (sp - 2164), 0);
    ST32(0x84C + (sp - 2164), 0);
    r9 = r12 + 108;
    r4 = LD32(r9);
    r11 = 0;
    if ((r4 & r4) == 0) {
        goto L0603C334;
    }
    r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
    r0 = LD32(0x848 + (sp - 2164));
    ST32(r9, r0);
    L0603C334:
    r8 = r12 + 116;
    r4 = LD32(r8);
    if ((r4 & r4) == 0) {
        goto L0603C34C;
    }
    r0 = GCALL1(0x06027F48, r4);
    r13 = LD32((0x848 + (sp - 2164)));
    ST32(r8, r13);
    L0603C34C:
    r8 = 128;
    r4 = LD32(r12 + 128);
    if ((r4 & r4) == 0) {
        goto L0603C364;
    }
    r0 = GCALL1(0x06027F48, r4);
    r13 = LD32(0x848 + (sp - 2164));
    ST32(r12 + r8, r13);
    L0603C364:
    r1 = LD32(r12 + 52);
    c3 = (r1 & r1) == 0;
    r1 = 80;
    if (!(c3)) {
        goto L0603C36E;
    }
    ST32(r12 + 52, r1);
    L0603C36E:
    r0 = GCALL4(0x0603C0BC, r12, (sp - 2164), ((sp - 2164) + 0x840), ((sp - 2164) + 0x844));
    r1 = LD8(sp - 2164);
    if (!((r0 & r0) == 0)) {
        goto L0603C468;
    }
    r8 = sp - 2164;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        goto L0603C394;
    }
    goto L0603C65A;
    L0603C394:
    ST32(0x850 + (sp - 2164), r9);
    L0603C398:
    r13 = LD32((0x848 + (sp - 2164)));
    if (!((r13 & r13) == 0)) {
        goto L0603C3D6;
    }
    ST32(0x848 + (sp - 2164), 2);
    r9 = 1;
    r14 = 0x0607507C;
    r2 = 1;
    L0603C3AE:
    r11 = LD32((r2 << 2) + 0x0607878C);
    r0 = GCALL1(r14, r11);
    r10 = r0;
    r0 = GCALL3(0x06075238, r8, r11, r10);
    if ((r0 & r0) == 0) {
        goto L0603C46C;
    }
    r9 = r9 + 1;
    r2 = r9;
    if (!(r9 > 14)) {
        POLL();
        goto L0603C3AE;
    }
    L0603C3D6:
    r1 = LD8(r8);
    r2 = r1 & 255;
    r0 = r2;
    c10 = r0 == 46;
    if (r0 == 47) {
        goto L0603C3E6;
    }
    goto L0603C5C4;
    L0603C3E6:
    r1 = LD8((r8 + 1));
    if ((r1 & 255) == 47) {
        goto L0603C3F6;
    }
    goto L0603C540;
    L0603C3F6:
    r0 = LD32(0x848 + (sp - 2164));
    r10 = r8;
    if (!(r0 == 9)) {
        goto L0603C404;
    }
    goto L0603C540;
    L0603C404:
    r10 = r10 + 2;
    r8 = r10;
    r1 = LD8(r10);
    r9 = 0;
    goto L0603C43E;
    L0603C430:
    r1 = LD8(r8);
    if ((r1 & 255) == 35) {
        goto L0603C44E;
    }
    r8 = r8 + 1;
    r1 = LD8(r8);
    r9 = r9 + 1;
    L0603C43E:
    r1 = r1 & 255;
    r0 = r1;
    if ((r1 & r1) == 0) {
        goto L0603C44E;
    }
    c16 = r0 == 58;
    if (r0 == 47) {
        goto L0603C44E;
    }
    if (!(c16)) {
        POLL();
        goto L0603C430;
    }
    L0603C44E:
    r0 = GCALL4(0x060279E0, 0, (r9 + 1), -1, 1);
    r1 = r0;
    r13 = LD32(0x850 + (sp - 2164));
    ST32(r13, r1);
    if (!((r1 & r1) == 0)) {
        goto L0603C474;
    }
    L0603C468:
    r0 = -3;
    goto L0603CBCE;
    L0603C46C:
    ST32(0x848 + (sp - 2164), r9);
    r8 = r8 + r10;
    POLL();
    goto L0603C3D6;
    L0603C474:
    r8 = r10;
    r1 = LD8(r8);
    r1 = r1 & 255;
    r9 = 0;
    if ((r1 & r1) == 0) {
        goto L0603C4C6;
    }
    r0 = r1;
    c20 = r0 == 58;
    if (r0 == 47) {
        goto L0603C4C6;
    }
    if (c20) {
        goto L0603C4C6;
    }
    r3 = 0x06075135;
    L0603C48C:
    r1 = LD8(r8);
    r1 = r1 & 255;
    if (r1 == 35) {
        goto L0603C4C6;
    }
    r0 = LD32((0x850 + (sp - 2164)));
    r2 = LD32(r0);
    r7 = LD8(r1 + r3);
    r8 = r8 + 1;
    if (((r7 & 1) & (r7 & 1)) == 0) {
        goto L0603C4AE;
    }
    r1 = r1 + 32;
    L0603C4AE:
    ST8(r2 + r9, r1);
    r1 = LD8(r8);
    r1 = r1 & 255;
    r9 = r9 + 1;
    if ((r1 & r1) == 0) {
        goto L0603C4C6;
    }
    r0 = r1;
    c25 = r0 == 58;
    if (r0 == 47) {
        goto L0603C4C6;
    }
    if (!(c25)) {
        POLL();
        goto L0603C48C;
    }
    L0603C4C6:
    r0 = LD32((0x850 + (sp - 2164)));
    r2 = LD32(r0);
    ST8(r2 + r9, 0);
    r1 = LD8(r8);
    c26 = (r1 & 255) == 58;
    r1 = 80;
    if (!(c26)) {
        goto L0603C528;
    }
    r8 = r8 + 1;
    r2 = LD8(r8);
    r1 = r2 & 255;
    r9 = 0;
    if ((r1 & r1) == 0) {
        goto L0603C514;
    }
    r0 = r2 & 255;
    if (r1 == 47) {
        goto L0603C514;
    }
    r1 = 0x800 + (sp - 2164);
    L0603C4F8:
    c29 = r0 == 35;
    r0 = r1;
    if (c29) {
        goto L0603C514;
    }
    ST8(r0 + r9, r2);
    r8 = r8 + 1;
    r2 = LD8(r8);
    r3 = r2 & 255;
    r9 = r9 + 1;
    if ((r3 & r3) == 0) {
        goto L0603C514;
    }
    r0 = r2 & 255;
    if (!(r3 == 47)) {
        POLL();
        goto L0603C4F8;
    }
    L0603C514:
    r2 = (sp - 2164) + 0x800;
    ST8(r2 + r9, 0);
    r0 = GCALL1(0x06075438, r2);
    r1 = r0;
    L0603C528:
    ST32(r12 + 52, r1);
    r8 = r8 - 1;
    goto L0603C64C;
    L0603C540:
    r1 = LD8((r8 + 1));
    c32 = (r1 & 255) == 46;
    r1 = r8;
    if (!(c32)) {
        goto L0603C592;
    }
    r1 = LD8((r1 + 2));
    if (!((r1 & 255) == 46)) {
        goto L0603C592;
    }
    r2 = LD8(r8);
    r9 = 0;
    if (((r2 & 255) & (r2 & 255)) == 0) {
        goto L0603C57C;
    }
    r3 = r12 + 116;
    L0603C566:
    if ((r2 & 255) == 35) {
        goto L0603C57C;
    }
    r0 = LD32(r3);
    r8 = r8 + 1;
    ST8(r0 + r9, r2);
    r2 = LD8(r8);
    r9 = r9 + 1;
    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
        POLL();
        goto L0603C566;
    }
    L0603C57C:
    r2 = LD32((r12 + 116));
    r8 = r8 - 1;
    r13 = 0x84C + (sp - 2164);
    ST8(r2 + r9, 0);
    r0 = 1;
    goto L0603C64A;
    L0603C592:
    r2 = LD8(r8);
    r9 = 0;
    if (((r2 & 255) & (r2 & 255)) == 0) {
        goto L0603C5B6;
    }
    r3 = r12 + 116;
    L0603C5A0:
    if ((r2 & 255) == 35) {
        goto L0603C5B6;
    }
    r0 = LD32(r3);
    r8 = r8 + 1;
    ST8(r0 + r9, r2);
    r2 = LD8(r8);
    r9 = r9 + 1;
    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
        POLL();
        goto L0603C5A0;
    }
    L0603C5B6:
    r0 = LD32((r12 + 116));
    r8 = r8 - 1;
    ST8(r0 + r9, 0);
    goto L0603C64C;
    L0603C5C4:
    r1 = r8;
    if (!(c10)) {
        goto L0603C60C;
    }
    r1 = LD8((r1 + 1));
    c41 = (r2 & r2) == 0;
    if (!((r1 & 255) == 46)) {
        goto L0603C60C;
    }
    r9 = 0;
    if (c41) {
        goto L0603C5F4;
    }
    r2 = r12 + 116;
    L0603C5DC:
    r1 = LD8(r8);
    if ((r1 & 255) == 35) {
        goto L0603C5F4;
    }
    r0 = LD32(r2);
    r8 = r8 + 1;
    ST8(r0 + r9, r1);
    r1 = LD8(r8);
    r9 = r9 + 1;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L0603C5DC;
    }
    L0603C5F4:
    r2 = LD32((r12 + 116));
    r8 = r8 - 1;
    r13 = 0x84C + (sp - 2164);
    ST8(r2 + r9, 0);
    r0 = 2;
    goto L0603C64A;
    L0603C60C:
    r3 = LD8(r8);
    r9 = 0;
    if ((r3 & r3) == 0) {
        goto L0603C636;
    }
    r2 = r12 + 116;
    L0603C618:
    if (r3 == 35) {
        goto L0603C636;
    }
    r1 = LD32(r2);
    ST8(r1 + r9, r3);
    r1 = LD8(r8);
    r8 = r8 + 1;
    r3 = LD8(r8);
    r9 = r9 + 1;
    if (!((r3 & r3) == 0)) {
        POLL();
        goto L0603C618;
    }
    L0603C636:
    r2 = LD32((r12 + 116));
    r8 = r8 - 1;
    ST8(r2 + r9, 0);
    r0 = 3;
    r13 = 0x84C + (sp - 2164);
    L0603C64A:
    ST32(r13, r0);
    L0603C64C:
    r8 = r8 + 1;
    r1 = LD8(r8);
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L0603C65A;
    }
    POLL();
    goto L0603C398;
    L0603C65A:
    r0 = LD32(0x848 + (sp - 2164));
    c49 = r0 == 4;
    r0 = 0;
    if (!(c49)) {
        goto L0603C66A;
    }
    ST32((0x84C + (sp - 2164)), r0);
    L0603C66A:
    r0 = LD32(0x848 + (sp - 2164));
    r8 = r12;
    if (!(r0 == 2)) {
        goto L0603C6D0;
    }
    r8 = r8 + 108;
    r1 = LD32(r8);
    c51 = (r1 & r1) == 0;
    r1 = r12;
    if (!(c51)) {
        goto L0603C6D0;
    }
    r1 = LD32((r1 + 112));
    r2 = r12;
    if (!((r1 & r1) == 0)) {
        goto L0603C6D0;
    }
    r2 = r2 + 116;
    r1 = LD32(r2);
    if ((r1 & r1) == 0) {
        goto L0603C6D0;
    }
    r4 = LD32(r12 + 8);
    r0 = 0;
    if ((r4 & r4) == 0) {
        goto L0603C6C4;
    }
    r0 = GCALL1(0x0607507C, r4);
    r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
    r1 = r0;
    ST32(r8, r1);
    if (!((r1 & r1) == 0)) {
        goto L0603C6B8;
    }
    POLL();
    goto L0603C468;
    L0603C6B8:
    r5 = LD32(r12 + 8);
    r0 = GCALL2(0x060750DC, r1, r5);
    r0 = 0;
    goto L0603C6CA;
    L0603C6C4:
    ST32(r8, r1);
    ST32(r2, 0);
    L0603C6CA:
    ST32((0x84C + (sp - 2164)), r0);
    L0603C6D0:
    r13 = LD32((0x84C + (sp - 2164)));
    if (!((r13 & r13) == 0)) {
        goto L0603C6DE;
    }
    goto L0603CA62;
    L0603C6DE:
    r8 = LD32(r12 + 4);
    r1 = r12;
    if (!((r8 & r8) == 0)) {
        goto L0603C6EA;
    }
    r8 = LD32((r1 + 120));
    L0603C6EA:
    r0 = GCALL1(0x0607507C, r8);
    r0 = GCALL4(0x060279E0, 0, (r0 + 4), -1, 1);
    r14 = r0;
    r6 = r14;
    if (!((r14 & r14) == 0)) {
        goto L0603C70A;
    }
    POLL();
    goto L0603C468;
    L0603C70A:
    r2 = LD8(r8);
    if (((r2 & 255) & (r2 & 255)) == 0) {
        goto L0603C74E;
    }
    r3 = 1;
    r7 = 0;
    L0603C716:
    c60 = (unsigned)((r2 - 34) & 255) > (unsigned)r3;
    r1 = r2 & 255;
    c1100 = c60;
    if (!(c60)) {
        goto L0603C72C;
    }
    r0 = r1;
    c62 = r0 == 59;
    c1100 = c62;
    if (r0 == 63) {
        goto L0603C72C;
    }
    c1100 = c62;
    if (!(c62)) {
        goto L0603C740;
    }
    L0603C72C:
    ST8(r6, r7);
    goto L0603C74E;
    L0603C740:
    ST8(r6, r2);
    r8 = r8 + 1;
    r2 = LD8(r8);
    r6 = r6 + 1;
    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
        POLL();
        goto L0603C716;
    }
    L0603C74E:
    r2 = 0;
    ST8(r6, 0);
    r0 = LD32(0x84C + (sp - 2164));
    r6 = r14;
    if (r0 == 2) {
        goto L0603C83E;
    }
    r13 = LD32((0x84C + (sp - 2164)));
    if (r13 > 2) {
        goto L0603C776;
    }
    r0 = LD32(0x84C + (sp - 2164));
    r1 = r12;
    if (r0 == 1) {
        goto L0603C788;
    }
    r1 = r1 + 116;
    goto L0603CA0E;
    L0603C776:
    r0 = LD32(0x84C + (sp - 2164));
    c68 = (r14 & r14) == 0;
    if (!(r0 == 3)) {
        goto L0603C784;
    }
    goto L0603C92C;
    L0603C784:
    r1 = r12;
    goto L0603CA0C;
    L0603C788:
    r3 = LD32((r1 + 116));
    r8 = sp - 2164;
    r1 = LD8(r3);
    r11 = r14;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        goto L0603C79C;
    }
    goto L0603CA16;
    L0603C79C:
    r7 = 0;
    r1 = LD8(r3);
    L0603C7A0:
    r0 = r1 & 255;
    c71 = r0 == 46;
    if (!(r0 == 35)) {
        goto L0603C7AE;
    }
    goto L0603CA16;
    L0603C7AE:
    r2 = r3;
    if (!(c71)) {
        goto L0603C7F4;
    }
    r2 = r2 + 1;
    r1 = LD8(r2);
    if (!((r1 & 255) == 46)) {
        goto L0603C7F4;
    }
    r1 = LD8(r11);
    r11 = r11 + 1;
    r3 = r2;
    goto L0603C7C4;
    L0603C7C2:
    r1 = LD8(r11);
    r11 = r11 + 1;
    L0603C7C4:
    if ((r1 & 255) == 47) {
        POLL();
        goto L0603C7C2;
    }
    r11 = r11 - 1;
    r1 = LD8(r11);
    goto L0603C7DE;
    L0603C7D2:
    if (r0 == 47) {
        goto L0603C7EC;
    }
    ST8(r8, r1);
    r11 = r11 + 1;
    r1 = LD8(r11);
    r8 = r8 + 1;
    L0603C7DE:
    r2 = r1 & 255;
    r0 = r2;
    if ((r2 & r2) == 0) {
        goto L0603C7EC;
    }
    c76 = r0 == 35;
    r0 = r1 & 255;
    if (!(c76)) {
        POLL();
        goto L0603C7D2;
    }
    L0603C7EC:
    r1 = LD8(r11);
    ST8(r8, r1);
    r8 = r8 + 1;
    ST8(r8, r7);
    L0603C7F4:
    r1 = LD8(r3);
    r2 = r3;
    if (!((r1 & 255) == 47)) {
        goto L0603C82A;
    }
    r2 = r2 + 1;
    r1 = LD8(r2);
    r1 = r1 & 255;
    c79 = (r1 & r1) == 0;
    if (r1 == 46) {
        goto L0603C82A;
    }
    r3 = r2;
    if (c79) {
        goto L0603C826;
    }
    L0603C810:
    r1 = LD8(r3);
    if ((r1 & 255) == 35) {
        goto L0603C826;
    }
    ST8(r8, r1);
    r3 = r3 + 1;
    r1 = LD8(r3);
    r8 = r8 + 1;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L0603C810;
    }
    L0603C826:
    ST8(r8, r7);
    goto L0603CA16;
    L0603C82A:
    r3 = r3 + 1;
    r1 = LD8(r3);
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        goto L0603C838;
    }
    goto L0603CA16;
    L0603C838:
    r1 = LD8(r3);
    POLL();
    goto L0603C7A0;
    L0603C83E:
    r8 = LD32((r12 + 116));
    r2 = LD8(r8);
    r10 = 0;
    goto L0603C87E;
    L0603C84A:
    c83 = r0 == 46;
    r1 = r8;
    c1143 = c83;
    if (!(c83)) {
        goto L0603C87A;
    }
    r1 = LD8((r1 + 1));
    c84 = (r1 & 255) == 46;
    c1143 = c84;
    if (!(c84)) {
        goto L0603C87A;
    }
    r8 = r8 + 2;
    r1 = LD8(r8);
    goto L0603C86A;
    L0603C860:
    if ((r1 & 255) == 47) {
        goto L0603C876;
    }
    r8 = r8 + 1;
    r1 = LD8(r8);
    L0603C86A:
    r2 = r1 & 255;
    if ((r2 & r2) == 0) {
        goto L0603C876;
    }
    if (!(r2 == 35)) {
        POLL();
        goto L0603C860;
    }
    L0603C876:
    r11 = r8;
    r10 = r10 + 1;
    c1143 = 1;
    L0603C87A:
    r8 = r8 + 1;
    r2 = LD8(r8);
    L0603C87E:
    r0 = r2 & 255;
    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
        POLL();
        goto L0603C84A;
    }
    L0603C886:
    r1 = LD8(r11);
    r11 = r11 + 1;
    if ((r1 & 255) == 47) {
        POLL();
        goto L0603C886;
    }
    r11 = r11 - 1;
    r8 = r11;
    r1 = LD8(r11);
    r9 = 0;
    goto L0603C8A6;
    L0603C898:
    r1 = LD8(r8);
    if ((r1 & 255) == 47) {
        goto L0603C8B2;
    }
    r8 = r8 + 1;
    r1 = LD8(r8);
    r9 = r9 + 1;
    L0603C8A6:
    r1 = r1 & 255;
    if ((r1 & r1) == 0) {
        goto L0603C8B2;
    }
    if (!(r1 == 35)) {
        POLL();
        goto L0603C898;
    }
    L0603C8B2:
    r3 = sp - 2164;
    if (!((r9 & r9) == 0)) {
        goto L0603C8C0;
    }
    if (!((r10 & r10) == 0)) {
        goto L0603C8C0;
    }
    goto L0603CA16;
    L0603C8C0:
    r8 = r6;
    r1 = LD8(r6);
    r7 = 0;
    goto L0603C8DC;
    L0603C8C8:
    r1 = LD8(r8);
    r0 = r1 & 255;
    c96 = r0 == 47;
    if (r0 == 35) {
        goto L0603C8E2;
    }
    c1158 = c96;
    if (!(c96)) {
        goto L0603C8D8;
    }
    r7 = r7 + 1;
    c1158 = 1;
    L0603C8D8:
    r8 = r8 + 1;
    r1 = LD8(r8);
    L0603C8DC:
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L0603C8C8;
    }
    L0603C8E2:
    r1 = (r7 - 1) - r10;
    if (r1 >= 0) {
        goto L0603C8F2;
    }
    r1 = 0;
    L0603C8F2:
    r7 = r1;
    r8 = r6;
    if (!(r7 >= 0)) {
        goto L0603C90E;
    }
    L0603C8FA:
    r1 = LD8(r8);
    if (!((r1 & 255) == 47)) {
        goto L0603C904;
    }
    r7 = r7 - 1;
    L0603C904:
    ST8(r3, r1);
    r8 = r8 + 1;
    r3 = r3 + 1;
    if (r7 >= 0) {
        POLL();
        goto L0603C8FA;
    }
    L0603C90E:
    r2 = LD8(r11);
    goto L0603C91E;
    L0603C912:
    if (r0 == 35) {
        goto L0603C926;
    }
    ST8(r3, r2);
    r11 = r11 + 1;
    r2 = LD8(r11);
    r3 = r3 + 1;
    L0603C91E:
    r0 = r2 & 255;
    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
        POLL();
        goto L0603C912;
    }
    L0603C926:
    ST8(r3, 0);
    goto L0603CA16;
    L0603C92C:
    r5 = r14;
    if (c68) {
        goto L0603C972;
    }
    r0 = GCALL2(0x060750DC, (sp - 2164), r5);
    r8 = 0x0607507C;
    r0 = GCALL1(0x0607507C, (sp - 2164));
    r1 = LD8(r0 + (sp - 2165));
    if ((r1 & 255) == 47) {
        goto L0603C97C;
    }
    r0 = GCALL3(r8, (sp - 2164), 0, r6);
    r9 = r0;
    goto L0603C95C;
    L0603C950:
    r1 = LD8(r0 + r9);
    c105 = (r1 & 255) == 47;
    r1 = 47;
    c1177 = c105;
    if (c105) {
        goto L0603C966;
    }
    L0603C95C:
    r9 = r9 - 1;
    r0 = sp - 2164;
    if (r9 > 0) {
        POLL();
        goto L0603C950;
    }
    r1 = 47;
    c1177 = 0;
    L0603C966:
    r0 = sp - 2164;
    ST8(r0 + r9, r1);
    ST8(r0 + (r9 + 1), 0);
    goto L0603C97C;
    L0603C972:
    ST8(sp - 2164, 47);
    ST8((sp - 2163), r2);
    L0603C97C:
    r0 = GCALL5(0x0607507C, (sp - 2164), 0, 0, 0, LD32((sp - 2164)));
    r10 = LD32((r12 + 116));
    r6 = (sp - 2164) + r0;
    r2 = LD8(r10);
    r7 = 1;
    if (((r2 & 255) & (r2 & 255)) == 0) {
        goto L0603CA06;
    }
    r4 = r10 + 3;
    r5 = r10 + 2;
    r3 = r10 + 1;
    L0603C9A2:
    if (!((r2 & 255) == 47)) {
        goto L0603C9E4;
    }
    r1 = LD8(r3);
    if (!((r1 & 255) == 46)) {
        goto L0603C9E4;
    }
    r1 = LD8(r5);
    if (!((r1 & 255) == 46)) {
        goto L0603C9E4;
    }
    r1 = LD8(r4);
    c112 = r7 > 0;
    if (!((r1 & 255) == 47)) {
        goto L0603C9E4;
    }
    if (!(c112)) {
        goto L0603C9E4;
    }
    r1 = LD8(r6);
    goto L0603C9D0;
    L0603C9CA:
    c1190 = c114;
    if (!(c114)) {
        goto L0603C9D8;
    }
    r6 = r6 - 1;
    r1 = LD8(r6);
    L0603C9D0:
    c114 = (unsigned)r6 > (unsigned)(sp - 2164);
    c1190 = c114;
    if (!((r1 & 255) == 47)) {
        POLL();
        goto L0603C9CA;
    }
    L0603C9D8:
    r4 = r4 + 3;
    r5 = r5 + 3;
    r3 = r3 + 3;
    r10 = r10 + 3;
    r7 = r7 - 1;
    goto L0603C9EE;
    L0603C9E4:
    r1 = LD8(r10);
    if (!((r1 & 255) == 47)) {
        goto L0603C9EE;
    }
    r7 = r7 + 1;
    L0603C9EE:
    r4 = r4 + 1;
    r1 = LD8(r10);
    r10 = r10 + 1;
    r5 = r5 + 1;
    ST8(r6, r1);
    r6 = r6 + 1;
    ST8(r6, 0);
    r2 = LD8(r10);
    r3 = r3 + 1;
    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
        POLL();
        goto L0603C9A2;
    }
    L0603CA06:
    ST8(r6, 0);
    goto L0603CA16;
    L0603CA0C:
    r1 = r1 + 116;
    L0603CA0E:
    r5 = LD32(r1);
    r0 = GCALL5(0x060750DC, (sp - 2164), r5, 0, 0, LD32((sp - 2164)));
    L0603CA16:
    r5 = R(5);
    r7 = R(7);
    r0 = GCALL5(0x06027F48, r14, r5, r6, 0, LD32((sp - 2164)));
    r8 = r12 + 116;
    r9 = 0x0607507C;
    r10 = LD32(r8);
    r0 = GCALL5(0x0607507C, (sp - 2164), 0, 0, 0, LD32((sp - 2164)));
    r1 = LD32((sp - 2164) + 0x840);
    c117 = (unsigned)r1 >= (unsigned)(r0 + 1);
    r1 = r12;
    if (c117) {
        goto L0603CA56;
    }
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL5(r9, (sp - 2164), r5, r6, r7, LD32((sp - 2164)));
    r5 = LD32(r8);
    r7 = R(7);
    r0 = GCALL5(0x06027C18, 0, r5, (r0 + 1), 0, LD32((sp - 2164)));
    r10 = r0;
    r1 = r12;
    if (!((r10 & r10) == 0)) {
        goto L0603CA56;
    }
    POLL();
    goto L0603C468;
    L0603CA56:
    ST32((r1 + 116), r10);
    r0 = GCALL5(0x060750DC, r10, (sp - 2164), 0, 0, LD32((sp - 2164)));
    L0603CA62:
    r13 = LD32((0x848 + (sp - 2164)));
    r8 = r12 + 108;
    ST32(r12 + 28, r13);
    r1 = LD32(r8);
    if ((r1 & r1) == 0) {
        goto L0603CA7C;
    }
    r0 = LD32(0x848 + (sp - 2164));
    c1213 = (r0 & r0) == 0;
    goto L0603CAF8;
    L0603CA7C:
    r4 = LD32(r12 + 8);
    r9 = r12;
    if ((r4 & r4) == 0) {
        goto L0603CAC0;
    }
    r0 = GCALL5(0x0607507C, r4, 0, 0, 0, LD32((sp - 2164)));
    r0 = GCALL5(0x060279E0, 0, (r0 + 1), -1, 1, LD32((sp - 2164)));
    r1 = r0;
    ST32(r8, r1);
    if (!((r1 & r1) == 0)) {
        goto L0603CAA4;
    }
    POLL();
    goto L0603C468;
    L0603CAA4:
    r5 = LD32(r12 + 8);
    goto L0603CAEA;
    L0603CAC0:
    r9 = r9 + 112;
    r4 = LD32(r9);
    if ((r4 & r4) == 0) {
        goto L0603CAF0;
    }
    r0 = GCALL5(0x0607507C, r4, 0, 0, 0, LD32((sp - 2164)));
    r0 = GCALL5(0x060279E0, 0, (r0 + 1), -1, 1, LD32((sp - 2164)));
    r1 = r0;
    ST32(r8, r1);
    if (!((r1 & r1) == 0)) {
        goto L0603CAE8;
    }
    POLL();
    goto L0603C468;
    L0603CAE8:
    r5 = LD32(r9);
    L0603CAEA:
    r0 = GCALL5(0x060750DC, r1, r5, 0, 0, LD32((sp - 2164)));
    L0603CAF0:
    r13 = LD32((0x848 + (sp - 2164)));
    c1213 = (r13 & r13) == 0;
    L0603CAF8:
    r8 = r12;
    if (!(c1213)) {
        goto L0603CB00;
    }
    r1 = LD32(r12 + 32);
    ST32(r12 + 28, r1);
    L0603CB00:
    r8 = r8 + 116;
    r2 = LD32(r8);
    r1 = LD8(r2);
    c127 = (r2 & r2) == 0;
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L0603CB10;
    }
    if (!(c127)) {
        goto L0603CB38;
    }
    L0603CB10:
    r1 = 47;
    if (!((r2 & r2) == 0)) {
        goto L0603CB26;
    }
    r0 = GCALL5(0x060279E0, 0, 2, -1, 1, LD32((sp - 2164)));
    ST32(r8, r0);
    r1 = 47;
    L0603CB26:
    r2 = LD32(r8);
    ST8(r2, r1);
    r1 = LD32(r8);
    ST8((r1 + 1), 0);
    ST32(0x840 + (sp - 2164), 2);
    L0603CB38:
    r8 = r12 + 108;
    r1 = LD32(r8);
    if (!((r1 & r1) == 0)) {
        goto L0603CB70;
    }
    r4 = LD32(r12 + 8);
    if ((r4 & r4) == 0) {
        goto L0603CB70;
    }
    r0 = GCALL5(0x0607507C, r4, 0, 0, 0, LD32((sp - 2164)));
    r0 = GCALL5(0x060279E0, 0, (r0 + 1), -1, 1, LD32((sp - 2164)));
    r1 = r0;
    ST32(r8, r1);
    if (!((r1 & r1) == 0)) {
        goto L0603CB68;
    }
    POLL();
    goto L0603C468;
    L0603CB68:
    r5 = LD32(r12 + 8);
    r0 = GCALL5(0x060750DC, r1, r5, 0, 0, LD32((sp - 2164)));
    L0603CB70:
    r14 = 0x844;
    r1 = LD32((sp - 2164) + 0x844);
    r11 = r12;
    if ((r1 & r1) == 0) {
        goto L0603CBCC;
    }
    r11 = r11 + 116;
    r10 = LD32(r11);
    r0 = GCALL5(0x0607507C, r10, 0, 0, 0, LD32((sp - 2164)));
    r9 = r0;
    r4 = LD32((sp - 2164) + r14);
    r0 = GCALL5(0x0607507C, r4, 0, 0, 0, LD32((sp - 2164)));
    r9 = (r0 + r9) + 1;
    r1 = LD32((sp - 2164) + 0x840);
    if (r1 >= r9) {
        goto L0603CBB2;
    }
    r5 = LD32(r11);
    r7 = R(7);
    r0 = GCALL5(0x06027C18, 0, r5, r9, 0, LD32((sp - 2164)));
    r10 = r0;
    r0 = -3;
    if ((r10 & r10) == 0) {
        goto L0603CBCE;
    }
    L0603CBB2:
    r5 = LD32((sp - 2164) + 0x844);
    r0 = GCALL5(0x06075408, r10, r5, 0, 0, LD32((sp - 2164)));
    ST32((r12 + 116), r10);
    r4 = LD32((sp - 2164) + 0x844);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 2164)));
    L0603CBCC:
    r0 = 0;
    L0603CBCE:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603DB94(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c4, c9, c10, c11, c19, c24, c25, c34, c35, c36, c37, c39, c42, c55, c58, c63, c69, c70, c71, c72, c73, c75, c76, c77, c78, c79, c85, c88, c89, c92, c101, c1051, c1077, c1078, c1137, c1161, c2011, c2012, c2013, c2014;
    FRAME(sp, 1068);

    r11 = R(11);
    r12 = R(12);
    r13 = R(13);
    r14 = R(14);
    r10 = r4;
    ST32(0x400 + (sp - 1064), r5);
    r2 = LD32(r10 + 36);
    r0 = r10;
    if (r2 >= 0) {
        goto L0603DC18;
    }
    r9 = 132;
    r4 = LD32(r0 + 132);
    c2011 = R(11);
    SETR(11, r11);
    c2012 = R(12);
    SETR(12, r12);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL4(0x0605A2A8, r4, 0, 0, r7);
    SETR(11, c2011);
    SETR(12, c2012);
    SETR(13, c2013);
    SETR(14, c2014);
    r8 = r0;
    r2 = r10;
    if (!((r8 & r8) == 0)) {
        goto L0603DBCA;
    }
    goto L0603E4F8;
    L0603DBCA:
    r0 = r10;
    r1 = LD32(r0 + r9);
    r1 = LD32(r1);
    ST32((r2 + 84), r1);
    r4 = LD32(r0 + r9);
    r0 = GCALL1(0x06027F48, r4);
    r2 = 0;
    ST32(r10 + r9, 0);
    if (r8 >= 0) {
        goto L0603DC06;
    }
    r1 = r10;
    if (r8 == -506) {
        goto L0603DC00;
    }
    r5 = LD32((r1 + 108));
    r0 = GCALL2(0x0603D114, r10, r5);
    c4 = (r0 & r0) == 0;
    r0 = 0;
    if (c4) {
        goto L0603DC00;
    }
    goto L0603E4FA;
    L0603DC00:
    r0 = -801;
    ST32(r10 + 40, -801);
    goto L0603E4FA;
    L0603DC06:
    ST8((r10 + 23), r8);
    ST32(r10 + 36, r2);
    r0 = GCALL1(0x06010510, 0x0603D9F4);
    r0 = 0;
    goto L0603E4FA;
    L0603DC18:
    r1 = 8;
    if (r2 > 0) {
        goto L0603DC4E;
    }
    r2 = LD8(0x060787C8);
    r4 = r10;
    if (r2 > 3) {
        goto L0603DC3E;
    }
    r0 = GCALL2(0x0603CE40, (r4 + 84), r10);
    r1 = r0;
    ST32(r10 + 40, r1);
    if ((r1 & r1) == 0) {
        goto L0603DC3E;
    }
    goto L0603E4FA;
    L0603DC3E:
    r1 = LD32(r10 + 36);
    r0 = 0;
    if (!(r1 > 0)) {
        goto L0603DC4A;
    }
    goto L0603DF50;
    L0603DC4A:
    goto L0603E4FA;
    L0603DC4E:
    c9 = r2 > r1;
    r1 = 2;
    if (!(c9)) {
        goto L0603DC58;
    }
    goto L0603DF50;
    L0603DC58:
    c10 = r2 > r1;
    r1 = r10;
    if (c10) {
        goto L0603DD10;
    }
    r8 = LD32((r1 + 116));
    r2 = LD8(r8);
    r9 = 0;
    goto L0603DC9E;
    L0603DC90:
    c11 = r0 == 35;
    r0 = sp - 1064;
    if (c11) {
        goto L0603DCA6;
    }
    ST8(r0 + r9, r2);
    r8 = r8 + 1;
    r2 = LD8(r8);
    r9 = r9 + 1;
    L0603DC9E:
    r0 = r2 & 255;
    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
        POLL();
        goto L0603DC90;
    }
    L0603DCA6:
    ST8((sp - 1064) + r9, 0);
    r1 = LD32((r10 + 104));
    r2 = LD32(r10 + 52);
    if ((r1 & r1) == 0) {
        goto L0603DCD0;
    }
    r1 = r10;
    if (r2 == 80) {
        goto L0603DCC8;
    }
    r5 = 0x0603DA00;
    r7 = LD32((r1 + 108));
    goto L0603DCDE;
    L0603DCC8:
    r5 = 0x0603DA20;
    r7 = LD32((r1 + 108));
    goto L0603DCF4;
    L0603DCD0:
    r1 = r10;
    if (r2 == 80) {
        goto L0603DCEE;
    }
    r7 = LD32((r1 + 108));
    r5 = 0x0603DA40;
    L0603DCDE:
    ST32((sp - 1068), r2);
    r0 = GCALL5(0x06045264, 0x0608BAA0, r5, (sp - 1064), r7, LD32((sp - 1068)));
    goto L0603DCFC;
    L0603DCEE:
    r7 = LD32((r1 + 108));
    r5 = 0x0603DA60;
    L0603DCF4:
    r0 = GCALL4(0x06045264, 0x0608BAA0, r5, (sp - 1064), r7);
    L0603DCFC:
    r0 = GCALL2(0x0603D67C, r10, 0x0608BAA0);
    r1 = 3;
    if (!((r0 & r0) == 0)) {
        goto L0603DD0E;
    }
    goto L0603E47C;
    L0603DD0E:
    ST32(r10 + 36, r1);
    L0603DD10:
    r2 = LD32(r10 + 36);
    r1 = 4;
    if (r2 > 3) {
        goto L0603DD6C;
    }
    r9 = 0x0608BAA0;
    r0 = GCALL3(0x06045264, 0x0608BAA0, 0x0603DA7C, 0x06079D34);
    r0 = GCALL1(0x0607507C, 0x0608BAA0);
    r4 = LD16((r10 + 20));
    r0 = GCALL3(0x0605ACB8, r4, 0x0608BAA0, r0);
    r8 = r0;
    c19 = r8 > 0;
    if (!(r8 == -502)) {
        goto L0603DD4A;
    }
    goto L0603E4F4;
    L0603DD4A:
    r5 = r8;
    if (c19) {
        goto L0603DD54;
    }
    r0 = 0x0603D62C;
    goto L0603E474;
    L0603DD54:
    r5 = LD32(r10 + 36);
    r0 = GCALL0(0x0603D628);
    ST32(r10 + 36, 4);
    ST32((r10 + 88), 0);
    r2 = LD32(r10 + 36);
    r1 = 4;
    L0603DD6C:
    r8 = r10;
    if (r2 > r1) {
        goto L0603DDA0;
    }
    r8 = r8 + 124;
    r5 = LD32(r8);
    r1 = 5;
    if ((r5 & r5) == 0) {
        goto L0603DD96;
    }
    r0 = GCALL2(0x0603D67C, r10, r5);
    if (!((r0 & r0) == 0)) {
        goto L0603DD8A;
    }
    goto L0603E47C;
    L0603DD8A:
    r4 = LD32(r8);
    r0 = GCALL1(0x06027F48, r4);
    ST32(r8, 0);
    r1 = 5;
    L0603DD96:
    ST32(r10 + 36, r1);
    ST32((r10 + 88), 0);
    L0603DDA0:
    r2 = LD32(r10 + 36);
    r1 = r10;
    if (r2 > 5) {
        goto L0603DDDE;
    }
    r5 = LD32((r1 + 100));
    c24 = (r5 & r5) == 0;
    r1 = 6;
    c1051 = c24;
    if (c24) {
        goto L0603DDC4;
    }
    r0 = GCALL2(0x0603D67C, r10, r5);
    c25 = (r0 & r0) == 0;
    r1 = 6;
    c1051 = c25;
    if (!(c25)) {
        goto L0603DDC4;
    }
    goto L0603E47C;
    L0603DDC4:
    ST32(r10 + 36, r1);
    ST32((r10 + 88), 0);
    ST32((r10 + 96), -1);
    ST32((r10 + 92), 0);
    r2 = LD32(r10 + 36);
    L0603DDDE:
    r11 = r10;
    if (r2 > 6) {
        goto L0603DE9E;
    }
    r11 = r11 + 92;
    r12 = 0x06045264;
    L0603DDEA:
    r0 = GCALL1(0x06046478, r10);
    r8 = r0;
    r1 = 7;
    if ((r8 & r8) == 0) {
        goto L0603DE94;
    }
    r0 = GCALL1(0x0607507C, r8);
    r0 = GCALL2(0x06028380, (r0 + 12), -1);
    r9 = r0;
    if ((r9 & r9) == 0) {
        goto L0603DE40;
    }
    r1 = LD32(r11);
    r6 = r8;
    if (!((r1 & r1) == 0)) {
        goto L0603DE1C;
    }
    r5 = 0x0603DAF8;
    goto L0603DE1E;
    L0603DE1C:
    r5 = 0x0603DB04;
    L0603DE1E:
    r0 = GCALL3(r12, r9, r5, r6);
    r0 = GCALL2(0x0603D67C, r10, r9);
    if (!((r0 & r0) == 0)) {
        goto L0603DE32;
    }
    goto L0603E47C;
    L0603DE32:
    r0 = GCALL1(0x06027F48, r9);
    r1 = LD32((r10 + 96));
    ST32(r11, r1);
    L0603DE40:
    ST32((r10 + 88), 0);
    POLL();
    goto L0603DDEA;
    L0603DE94:
    ST32(r10 + 36, r1);
    ST32((r10 + 88), 0);
    L0603DE9E:
    r5 = LD32(r10 + 36);
    r1 = r10;
    if (r5 > 7) {
        goto L0603DF1C;
    }
    r0 = LD32((r1 + 96));
    if (r0 == -1) {
        goto L0603DEC6;
    }
    r0 = GCALL0(0x0603D628);
    r5 = 0x0603DB10;
    r4 = LD16((r10 + 20));
    r0 = 0x0605ACB8;
    r6 = 4;
    goto L0603DEDA;
    L0603DEC6:
    r0 = GCALL0(0x0603D628);
    r5 = 0x0603DB18;
    r4 = LD16((r10 + 20));
    r0 = 0x0605ACB8;
    r6 = 2;
    L0603DEDA:
    r0 = GCALL3(r0, r4, r5, r6);
    r8 = r0;
    c34 = r8 > 0;
    if (!(r8 == -502)) {
        goto L0603DEEC;
    }
    goto L0603E4F4;
    L0603DEEC:
    r5 = r8;
    if (c34) {
        goto L0603DF10;
    }
    r0 = 0x0603D62C;
    goto L0603E474;
    L0603DF10:
    ST32(r10 + 36, 8);
    ST32((r10 + 88), 0);
    L0603DF1C:
    r2 = LD32(r10 + 36);
    c35 = r2 > 8;
    r1 = r10;
    c1077 = c35;
    if (c35) {
        goto L0603DF3E;
    }
    r5 = LD32((r1 + 104));
    c36 = (r5 & r5) == 0;
    r1 = 0;
    c1078 = c36;
    if (c36) {
        goto L0603DF40;
    }
    r0 = GCALL2(0x0603D67C, r10, r5);
    c37 = (r0 & r0) == 0;
    c1077 = c37;
    if (!(c37)) {
        goto L0603DF3E;
    }
    goto L0603E47C;
    L0603DF3E:
    r1 = 0;
    c1078 = c1077;
    L0603DF40:
    ST32(r10 + 40, r1);
    r1 = LD32(0x0608B980);
    ST32((r10 + 80), r1);
    ST32(r10 + 36, 9);
    L0603DF50:
    r5 = LD32(r10 + 12);
    r4 = LD16((r10 + 20));
    r0 = GCALL3(0x0605ACCC, r4, r5, 0x114);
    r12 = r0;
    c39 = (r12 & r12) == 0;
    if (r12 > 0) {
        goto L0603DF6A;
    }
    goto L0603E436;
    L0603DF6A:
    r1 = LD32(0x0608B980);
    ST32((r10 + 80), r1);
    r2 = LD32(r10 + 36);
    if (!(r2 > 11)) {
        goto L0603DF80;
    }
    goto L0603E3A6;
    L0603DF80:
    r0 = LD32(r10 + 12);
    r1 = r12;
    r12 = r12 - 1;
    ST32((0x404 + (sp - 1064)), r0);
    if (r1 > 0) {
        goto L0603DF94;
    }
    goto L0603E3A6;
    L0603DF94:
    r14 = r10 + 68;
    r11 = 136;
    r13 = 0x06075238;
    L0603DF9C:
    r3 = 0x404 + (sp - 1064);
    r0 = LD32(r3);
    r0 = r0 + 1;
    ST32(r3, r0);
    r1 = LD8((r0 - 1));
    r2 = LD32(r14);
    r9 = r1 & 255;
    ST32(r14, (r2 + 1));
    r1 = LD32(r10 + r11);
    ST8(r1 + r2, r9);
    r1 = LD32(r14);
    r6 = LD32(140 + r10);
    c42 = r1 >= r6;
    r1 = r6;
    if (!(c42)) {
        goto L0603E03C;
    }
    r5 = LD32(r10 + r11);
    r0 = GCALL3(0x06027C18, 0, r5, (r6 + ((((int)((unsigned)r1 >> 31)) + r6) >> 1)));
    r8 = r0;
    r0 = r10;
    if (!((r8 & r8) == 0)) {
        goto L0603E028;
    }
    r4 = LD32(140 + r10);
    r0 = GCALL2(0x06028380, (r4 + ((((int)((unsigned)r4 >> 31)) + r4) >> 1)), -1);
    r8 = r0;
    r5 = 0;
    if (!((r8 & r8) == 0)) {
        goto L0603E006;
    }
    goto L0603E480;
    L0603E006:
    r6 = LD32(140 + r10);
    r0 = GCALL3(0x0604B3F0, r8, r5, r6);
    r5 = LD32(r10 + r11);
    r6 = LD32(140 + r10);
    r0 = GCALL3(0x0604B358, r8, r5, r6);
    r4 = LD32(r10 + r11);
    r0 = GCALL1(0x06027F48, r4);
    r0 = r10;
    L0603E028:
    ST32(r0 + r11, r8);
    r2 = LD32(140 + r10);
    ST32(140 + r10, (r2 + ((((int)((unsigned)r2 >> 31)) + r2) >> 1)));
    L0603E03C:
    r2 = LD32(r10 + 36);
    if (r2 > 9) {
        goto L0603E07A;
    }
    r1 = LD32(r14);
    r6 = 4;
    r0 = r9;
    if (!(r1 > 4)) {
        goto L0603E07C;
    }
    r4 = LD32(r10 + r11);
    r0 = GCALL3(r13, r4, 0x0603DB1C, r6);
    if ((r0 & r0) == 0) {
        goto L0603E07A;
    }
    r12 = r12 + 1;
    r5 = LD32(r10 + 12);
    r0 = GCALL3(0x0603D540, r10, r5, r12);
    r1 = r0;
    ST32(r10 + 40, r1);
    if (!((r1 & r1) == 0)) {
        goto L0603E074;
    }
    goto L0603E3A6;
    L0603E074:
    r0 = 0x0603D62C;
    r5 = r1;
    goto L0603E474;
    L0603E07A:
    r0 = r9;
    L0603E07C:
    c55 = r0 == 10;
    r0 = r12;
    if (c55) {
        goto L0603E086;
    }
    goto L0603E39C;
    L0603E086:
    r2 = LD32(r10 + r11);
    r3 = LD32(r14);
    ST8(r2 + r3, 0);
    r2 = LD32(r10 + r11);
    r1 = LD8(r2);
    r8 = 0;
    goto L0603E0E2;
    L0603E0D4:
    r1 = LD8(r2);
    r2 = r2 + 1;
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L0603E0EE;
    }
    r1 = LD8(r2);
    r8 = r8 + 1;
    L0603E0E2:
    r0 = r1 & 255;
    c58 = r0 == 13;
    if (r0 == 10) {
        goto L0603E0EE;
    }
    if (!(c58)) {
        POLL();
        goto L0603E0D4;
    }
    L0603E0EE:
    r2 = LD32(r10 + r11);
    ST8(r2 + r8, 0);
    r5 = LD32(r10 + 36);
    r4 = LD32(r10 + r11);
    r0 = GCALL0(0x0603D628);
    r2 = LD32(r10 + 36);
    r0 = r10;
    if (r2 > 9) {
        goto L0603E16C;
    }
    r4 = LD32(r0 + r11);
    r0 = GCALL3(r13, r4, 0x0603DB1C, 4);
    if ((r0 & r0) == 0) {
        goto L0603E138;
    }
    r12 = r12 + 1;
    r5 = LD32(r10 + 12);
    r0 = GCALL3(0x0603D540, r10, r5, r12);
    r1 = r0;
    ST32(r10 + 40, r1);
    if (!((r1 & r1) == 0)) {
        goto L0603E132;
    }
    goto L0603E390;
    L0603E132:
    r0 = 0x0603D62C;
    r5 = r1;
    goto L0603E474;
    L0603E138:
    r8 = LD32(r10 + r11);
    goto L0603E146;
    L0603E13E:
    r0 = -1;
    if (!(c63)) {
        goto L0603E146;
    }
    goto L0603E486;
    L0603E146:
    r1 = LD8(r8);
    r8 = r8 + 1;
    r9 = r1 & 255;
    c63 = (r9 & r9) == 0;
    if (!(r9 == 32)) {
        POLL();
        goto L0603E13E;
    }
    r0 = -1;
    if (!(c63)) {
        goto L0603E15A;
    }
    goto L0603E486;
    L0603E15A:
    r0 = GCALL1(0x06075438, r8);
    ST32((r10 + 76), r0);
    ST32(r10 + 36, 10);
    goto L0603E390;
    L0603E16C:
    r1 = r10;
    if (!((r8 & r8) == 0)) {
        goto L0603E1AC;
    }
    if (!(r2 == 11)) {
        goto L0603E17C;
    }
    goto L0603E48A;
    L0603E17C:
    r4 = LD32(r10 + 24);
    r6 = r12;
    if ((r4 & r4) == 0) {
        goto L0603E190;
    }
    r0 = GCALL1(0x06044380, r4);
    ST32(r10 + 24, 0);
    r6 = r12;
    L0603E190:
    r5 = LD32((0x404 + (sp - 1064)));
    r0 = GCALL3(0x0603D540, r10, r5, r6);
    r1 = r0;
    ST32(r10 + 40, r1);
    if (!((r1 & r1) == 0)) {
        goto L0603E1A8;
    }
    goto L0603E3A6;
    L0603E1A8:
    goto L0603E4FA;
    L0603E1AC:
    r2 = LD32((r1 + 76));
    r0 = r10;
    if (!(r2 == 0x191)) {
        goto L0603E1DC;
    }
    r4 = LD32(r0 + r11);
    r0 = GCALL3(r13, r4, 0x0603DB24, 16);
    c69 = (r0 & r0) == 0;
    r0 = r10;
    if (!(c69)) {
        goto L0603E22C;
    }
    r5 = LD32(r0 + r11);
    c2011 = R(11);
    SETR(11, r11);
    r0 = GCALL2(0x0603D880, r10, r5);
    SETR(11, c2011);
    r1 = r0;
    c70 = (r1 & r1) == 0;
    ST32(r10 + 40, r1);
    c1137 = c70;
    if (c70) {
        goto L0603E22A;
    }
    goto L0603E4FA;
    L0603E1DC:
    c71 = (unsigned)(r2 + -300) > (unsigned)99;
    r1 = r10;
    c1137 = c71;
    if (c71) {
        goto L0603E22A;
    }
    r2 = LD8((r1 + 22));
    c72 = r2 > 4;
    r0 = r10;
    c1137 = c72;
    if (c72) {
        goto L0603E22A;
    }
    r4 = LD32(r0 + r11);
    r0 = GCALL3(r13, r4, 0x0603DB38, 8);
    c73 = (r0 & r0) == 0;
    c1137 = c73;
    if (!(c73)) {
        goto L0603E22A;
    }
    r4 = LD32(r10 + 24);
    if ((r4 & r4) == 0) {
        goto L0603E212;
    }
    r0 = GCALL1(0x06044380, r4);
    ST32(r10 + 24, 0);
    L0603E212:
    r5 = LD32((0x400 + (sp - 1064)));
    r0 = GCALL2(0x0603D720, r10, r5);
    r1 = r0;
    c75 = (r1 & r1) == 0;
    r0 = r1;
    c1137 = c75;
    if (c75) {
        goto L0603E22A;
    }
    goto L0603E4FA;
    L0603E22A:
    r0 = r10;
    L0603E22C:
    r4 = LD32(r0 + r11);
    r0 = GCALL3(r13, r4, 0x0603DB44, 6);
    c76 = (r0 & r0) == 0;
    r0 = r10;
    if (!(c76)) {
        goto L0603E240;
    }
    goto L0603E390;
    L0603E240:
    r4 = LD32(r0 + r11);
    r0 = GCALL3(r13, r4, 0x0603DB4C, 4);
    c77 = (r0 & r0) == 0;
    r0 = r10;
    if (!(c77)) {
        goto L0603E25E;
    }
    r4 = LD32(r0 + r11);
    r0 = GCALL1(0x06045E34, (r4 + 4));
    r1 = 0;
    goto L0603E392;
    L0603E25E:
    r4 = LD32(r0 + r11);
    r0 = GCALL3(r13, r4, 0x0603DB54, 11);
    c78 = (r0 & r0) == 0;
    r0 = r10;
    if (!(c78)) {
        goto L0603E2C0;
    }
    r5 = LD32(r0 + r11);
    r0 = GCALL2(0x06045FE0, r10, (r5 + 12));
    r1 = 0;
    goto L0603E392;
    L0603E2C0:
    r4 = LD32(r0 + r11);
    r0 = GCALL3(r13, r4, 0x0603DB60, 12);
    c79 = (r0 & r0) == 0;
    r0 = r10;
    if (!(c79)) {
        goto L0603E324;
    }
    r5 = LD32(r0 + r11);
    r0 = GCALL2(0x0603D3DC, r10, (r5 + 12));
    r8 = r0;
    r6 = 8;
    L0603E2DE:
    r0 = GCALL3(r13, r8, 0x0603DB70, r6);
    if ((r0 & r0) == 0) {
        goto L0603E2F6;
    }
    r1 = LD8(r8);
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L0603E2F6;
    }
    r8 = r8 + 1;
    r6 = 8;
    POLL();
    goto L0603E2DE;
    L0603E2F6:
    r1 = LD8(r8);
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L0603E390;
    }
    r8 = r8 + 8;
    ST32(r10 + 48, 0);
    r0 = GCALL3(r13, r8, 0x0603DB7C, 3);
    r1 = 0;
    if (!((r0 & r0) == 0)) {
        goto L0603E392;
    }
    r2 = LD32(r10 + 48);
    r1 = LD8((r8 + 10));
    ST32(r10 + 48, ((r2 - 48) + (r1 & 255)));
    goto L0603E390;
    L0603E324:
    r4 = LD32(r0 + r11);
    r0 = GCALL3(r13, r4, 0x0603DB80, 14);
    r1 = 0;
    if (!((r0 & r0) == 0)) {
        goto L0603E392;
    }
    r2 = LD32(r10 + r11);
    r8 = r2 + 14;
    r1 = LD8(r8);
    r0 = r1 & 255;
    c85 = r0 == 13;
    c1161 = c85;
    if (c85) {
        goto L0603E384;
    }
    r3 = 4;
    r7 = 0x06075135;
    r1 = LD8(r0 + 0x06075135);
    c1161 = r0 == 13;
    if (!(((r1 & 4) & (r1 & 4)) == 0)) {
        goto L0603E384;
    }
    r8 = r2 + 15;
    r1 = LD8(r8);
    r9 = r1 & 255;
    r0 = r9;
    c88 = r0 == 13;
    c1161 = c88;
    if (c88) {
        goto L0603E384;
    }
    r1 = LD8(r0 + r7);
    r1 = r1 & r3;
    goto L0603E378;
    L0603E368:
    r1 = LD8(r8);
    r9 = r1 & 255;
    r0 = r9;
    c89 = r0 == 13;
    c1161 = c89;
    if (c89) {
        goto L0603E384;
    }
    r1 = LD8(r0 + r7);
    r1 = r1 & 4;
    L0603E378:
    r8 = r8 + 1;
    if ((r1 & r1) == 0) {
        POLL();
        goto L0603E368;
    }
    r8 = r8 - 1;
    c1161 = r9 == 13;
    L0603E384:
    r1 = 0;
    if (c1161) {
        goto L0603E392;
    }
    r0 = GCALL1(0x06075438, r8);
    ST32(r10 + 56, r0);
    L0603E390:
    r1 = 0;
    L0603E392:
    ST32(r14, r1);
    r0 = LD32(r10 + 36);
    c92 = r0 == 12;
    r0 = r12;
    if (c92) {
        goto L0603E3A6;
    }
    L0603E39C:
    r12 = r12 - 1;
    if (!(r0 > 0)) {
        goto L0603E3A6;
    }
    POLL();
    goto L0603DF9C;
    L0603E3A6:
    r0 = LD32(r10 + 36);
    if (!(r0 == 12)) {
        goto L0603E3B8;
    }
    r1 = LD32(r10 + 12);
    ST32(r10 + 12, (r1 + r12));
    r1 = LD32(r10 + 60);
    ST32(r10 + 60, (r1 + r12));
    L0603E3B8:
    r5 = LD32(r10 + 16);
    r9 = r10;
    if (!((r5 & r5) == 0)) {
        goto L0603E3C4;
    }
    goto L0603E4F4;
    L0603E3C4:
    r2 = LD32(r10 + 60);
    r9 = r9 + 72;
    r6 = LD32(r9);
    r1 = 0;
    if ((r2 + 0x114) > r6) {
        goto L0603E3D8;
    }
    goto L0603E4F6;
    L0603E3D8:
    r11 = 0x2800;
    r0 = GCALL3(0x06027C18, 1, r5, (r6 + 0x2800));
    r8 = r0;
    if (!((r8 & r8) == 0)) {
        goto L0603E420;
    }
    r4 = LD32(r9);
    r0 = GCALL2(0x06028380, (r4 + r11), -1);
    r8 = r0;
    r5 = 0;
    if (!((r8 & r8) == 0)) {
        goto L0603E406;
    }
    r4 = LD32(r10 + 16);
    r0 = GCALL2(0x06027F48, r4, r5);
    ST32(r10 + 16, 0);
    goto L0603E480;
    L0603E406:
    r6 = LD32(r9);
    r0 = GCALL3(0x0604B3F0, r8, r5, (r6 + r11));
    r5 = LD32(r10 + 16);
    r6 = LD32(r9);
    r0 = GCALL3(0x0604B358, r8, r5, r6);
    r4 = LD32(r10 + 16);
    r0 = GCALL1(0x06027F48, r4);
    L0603E420:
    ST32(r10 + 16, r8);
    r1 = LD32(r10 + 60);
    r3 = r10 + 72;
    ST32(r10 + 12, (r1 + r8));
    r1 = LD32(r3);
    ST32(r3, (r1 + 0x2800));
    goto L0603E4F4;
    L0603E436:
    r0 = -9;
    if (!(c39)) {
        goto L0603E43E;
    }
    ST32(r10 + 40, r0);
    goto L0603E4FA;
    L0603E43E:
    if (r12 == -502) {
        goto L0603E44A;
    }
    ST32(r10 + 40, r12);
    r0 = r12;
    goto L0603E4FA;
    L0603E44A:
    r1 = LD32(0x0608B980);
    r2 = LD32((r10 + 80));
    r1 = r1 - r2;
    r2 = LD32(0x0603DB90);
    c101 = ((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)(r1 + 5) * (unsigned)r2)) >> 32)) >> 2)) >> 1)) > 200;
    r1 = 0;
    if (!(c101)) {
        goto L0603E4F6;
    }
    ST32(r10 + 56, r1);
    r5 = -10;
    ST32(r10 + 40, -10);
    r0 = 0x0603D62C;
    L0603E474:
    r0 = GCALL2(r0, r10, r5);
    ST32(r10 + 40, r0);
    goto L0603E4FA;
    L0603E47C:
    r0 = LD32(r10 + 40);
    goto L0603E4FA;
    L0603E480:
    r0 = -3;
    ST32(r10 + 40, -3);
    goto L0603E4FA;
    L0603E486:
    ST32(r10 + 40, r0);
    goto L0603E4FA;
    L0603E48A:
    r8 = r10 + 22;
    r9 = LD8(r8);
    r0 = GCALL2(0x0603E514, r10, r5);
    ST8(r8, (r9 + 1));
    r0 = GCALL1(0x0603D2BC, r10);
    ST32(r10 + 40, r0);
    goto L0603E4FA;
    L0603E4F4:
    r1 = 0;
    L0603E4F6:
    ST32(r10 + 40, r1);
    L0603E4F8:
    r0 = 0;
    L0603E4FA:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603F318(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;

    r13 = r4;
    r10 = r5;
    r9 = 12;
    r1 = 0;
    r2 = 48;
    L0603F332:
    r2 = r2 - 4;
    r9 = r9 - 1;
    r0 = r2;
    ST32(r0 + r13, r1);
    if (r9 > 0) {
        POLL();
        goto L0603F332;
    }
    r1 = LD8(r10);
    r9 = 11;
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L0603F3C0;
    }
    r12 = 0x060787CC;
    r14 = 0x0607507C;
    L0603F34C:
    r11 = 0x06075238;
    r8 = 44;
    L0603F350:
    r4 = LD32(r8 + r12);
    r0 = GCALL1(r14, r4);
    r4 = LD32(r8 + r12);
    r0 = GCALL3(r11, r4, r10, r0);
    r9 = r9 - 1;
    if (!((r0 & r0) == 0)) {
        goto L0603F37C;
    }
    r4 = LD32(r8 + r12);
    r0 = GCALL1(r14, r4);
    ST32(r8 + r13, ((r0 + r10) + 1));
    goto L0603F38C;
    L0603F37C:
    r8 = r8 - 4;
    if (r9 >= 0) {
        POLL();
        goto L0603F350;
    }
    r2 = LD8(r10);
    goto L0603F38E;
    L0603F386:
    if (r0 == 13) {
        goto L0603F396;
    }
    r10 = r10 + 1;
    L0603F38C:
    r2 = LD8(r10);
    L0603F38E:
    r0 = r2 & 255;
    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
        POLL();
        goto L0603F386;
    }
    L0603F396:
    r1 = LD8(r10);
    r10 = r10 + 1;
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L0603F3C0;
    }
    r1 = LD8(r10);
    r0 = r1 & 255;
    r1 = r10;
    if (!(r0 == 10)) {
        goto L0603F3B4;
    }
    r1 = LD8((r1 + 1));
    r0 = r1 & 255;
    if (r0 == 13) {
        goto L0603F3C0;
    }
    L0603F3B4:
    r10 = r10 + 1;
    r1 = LD8(r10);
    r9 = 11;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L0603F34C;
    }
    L0603F3C0:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603F42C(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14, c7, c8, c16, c21, c22, c23, c34, c35, c38, c45, c1044, c1070, c2011, c2013, c2014;
    FRAME(sp, 1576);

    r14 = R(14);
    r13 = r4;
    ST32(0x5CC + (sp - 1560), r5);
    r11 = 0x5E4 + (sp - 1560);
    ST32(r11, 0);
    ST32(r13 + 16, -1);
    r1 = LD32(r13);
    if (r1 >= 0) {
        goto L0603F474;
    }
    r1 = LD32(r13 + 40);
    if ((r1 & r1) == 0) {
        goto L0603F464;
    }
    r0 = GCALL2(r1, 0x0603F3E0, 0);
    L0603F464:
    c2011 = R(11);
    SETR(11, r11);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL1(0x06049414, r13);
    SETR(11, c2011);
    SETR(13, c2013);
    SETR(14, c2014);
    if ((r0 & r0) == 0) {
        goto L0603F474;
    }
    goto L0603FA52;
    L0603F474:
    r1 = LD32(r13 + 40);
    if ((r1 & r1) == 0) {
        goto L0603F480;
    }
    r0 = GCALL2(r1, 0x0603F3EC, 5);
    L0603F480:
    c2011 = R(11);
    SETR(11, 0x06049748);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL1(0x06049748, r13);
    SETR(11, c2011);
    SETR(13, c2013);
    SETR(14, c2014);
    r8 = r0;
    if (r8 >= 0) {
        goto L0603F490;
    }
    goto L0603FA52;
    L0603F490:
    ST32(r13 + 28, r8);
    r8 = 0x0603F1AC;
    r0 = GCALL2(0x0603F1AC, r13, 0x060787FC);
    if ((r0 & r0) == 0) {
        goto L0603F4A4;
    }
    L0603F4A0:
    r0 = -3;
    goto L0603FA52;
    L0603F4A4:
    r2 = LD32(r13 + 28);
    r1 = 20;
    if (r2 > 0) {
        goto L0603F4E8;
    }
    r0 = GCALL2(r8, r13, 0x06078C18);
    r0 = GCALL2(r8, r13, 0x06078CE4);
    r0 = 0;
    goto L0603FA52;
    L0603F4BC:
    r0 = -12;
    goto L0603FA52;
    L0603F4E8:
    r0 = LD32((0x5CC + (sp - 1560)));
    ST32((0x5DC + (sp - 1560)), r0);
    ST32((0x5D8 + (sp - 1560)), r2);
    r12 = LD32((0x5D8 + (sp - 1560)));
    c7 = r12 > r1;
    r12 = 10;
    if (!(c7)) {
        goto L0603F520;
    }
    r11 = LD32(0x5CC + (sp - 1560));
    ST32(0x5D8 + (sp - 1560), (r11 + 20));
    r12 = LD32((0x5D8 + (sp - 1560)));
    c8 = r12 > r2;
    r12 = 10;
    if (!(c8)) {
        goto L0603F520;
    }
    ST32(0x5D8 + (sp - 1560), r2);
    L0603F520:
    ST32((0x5D4 + (sp - 1560)), r12);
    r11 = LD32((0x5DC + (sp - 1560)));
    ST32(0x5D0 + (sp - 1560), r11);
    r0 = LD32((0x5DC + (sp - 1560)));
    r12 = LD32((0x5D8 + (sp - 1560)));
    if (!(r0 >= r12)) {
        goto L0603F544;
    }
    goto L0603F9E4;
    L0603F544:
    ST32(0x5E8 + (sp - 1560), (0x380 + (sp - 1560)));
    L0603F54C:
    r1 = LD32(r13 + 40);
    if ((r1 & r1) == 0) {
        goto L0603F578;
    }
    r6 = LD32(r13 + 28);
    r7 = LD32((0x5D0 + (sp - 1560)));
    r0 = GCALL4(0x06045264, (sp - 1560), 0x0603F3FC, r6, r7);
    r1 = LD32(r13 + 40);
    r5 = LD32((0x5D4 + (sp - 1560)));
    r0 = GCALL2(r1, (sp - 1560), r5);
    r12 = 0x5D4 + (sp - 1560);
    r0 = LD32(r12);
    ST32(r12, (r0 + 4));
    L0603F578:
    r5 = LD32(r13 + 28);
    r11 = LD32((0x5D0 + (sp - 1560)));
    r6 = LD32((0x5E8 + (sp - 1560)));
    c2011 = R(11);
    SETR(11, r11);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL3(0x0604999C, r13, (r5 - r11), r6);
    SETR(11, c2011);
    SETR(13, c2013);
    SETR(14, c2014);
    r8 = r0;
    if (r8 >= 0) {
        goto L0603F5B6;
    }
    r5 = LD32(r13 + 28);
    r11 = LD32((0x5D0 + (sp - 1560)));
    r6 = LD32((0x5E8 + (sp - 1560)));
    c2011 = R(11);
    SETR(11, r11);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL3(0x06049910, r13, (r5 - r11), r6);
    SETR(11, c2011);
    SETR(13, c2013);
    SETR(14, c2014);
    r8 = r0;
    r0 = r8;
    if (r8 >= 0) {
        goto L0603F5B6;
    }
    goto L0603FA52;
    L0603F5B6:
    r11 = LD32((0x5E4 + (sp - 1560)));
    if ((r11 & r11) == 0) {
        goto L0603F5CA;
    }
    r4 = LD32((0x5E4 + (sp - 1560)));
    r0 = GCALL1(0x06027F48, r4);
    L0603F5CA:
    ST32(0x5F0 + (sp - 1560), 0x5000);
    r5 = LD32((0x5F0 + (sp - 1560)));
    r0 = GCALL4(0x060279E0, 0, r5, -1, 1);
    ST32((0x5E4 + (sp - 1560)), r0);
    r0 = LD32(0x5E4 + (sp - 1560));
    r9 = LD32((0x5E4 + (sp - 1560)));
    if (!((r0 & r0) == 0)) {
        goto L0603F5F8;
    }
    POLL();
    goto L0603F4A0;
    L0603F5F8:
    r14 = 0;
    r10 = 0;
    ST32((0x5E0 + (sp - 1560)), 0);
    L0603F604:
    r0 = GCALL0(0x0605299C);
    r1 = LD32(0x060766B4);
    c16 = r8 > 0;
    if ((r1 & r1) == 0) {
        goto L0603F618;
    }
    POLL();
    goto L0603F4BC;
    L0603F618:
    r2 = r14;
    if (c16) {
        goto L0603F620;
    }
    goto L0603F752;
    L0603F620:
    r0 = LD32(0x5F0 + (sp - 1560));
    r2 = r2 + r8;
    r4 = 0;
    if (!(r2 > r0)) {
        goto L0603F6AE;
    }
    r9 = LD32((0x5F0 + (sp - 1560)));
    r5 = LD32((0x5E4 + (sp - 1560)));
    r9 = r9 + 0x2800;
    r6 = r9;
    r11 = 0x06027C18;
    ST32((0x5F4 + (sp - 1560)), r2);
    r0 = GCALL3(r11, r4, r5, r6);
    r1 = r0;
    ST32(0x5C8 + (sp - 1560), r1);
    r2 = LD32((0x5F4 + (sp - 1560)));
    if (!((r1 & r1) == 0)) {
        goto L0603F6A0;
    }
    goto L0603FA34;
    L0603F6A0:
    ST32((0x5F0 + (sp - 1560)), r9);
    r9 = r1 + r14;
    ST32(0x5E4 + (sp - 1560), r1);
    L0603F6AE:
    r5 = LD32((0x5E8 + (sp - 1560)));
    ST32((0x5F4 + (sp - 1560)), r2);
    r0 = GCALL3(0x0604B358, r9, r5, r8);
    r9 = r9 + r8;
    r2 = LD32((0x5F4 + (sp - 1560)));
    r14 = r2;
    ST8((0x381 + (sp - 1560)) + r8, 0);
    r1 = r8;
    r8 = r8 - 1;
    r11 = LD32((0x5E8 + (sp - 1560)));
    ST32(0x5C8 + (sp - 1560), r11);
    if (!(r1 > 0)) {
        goto L0603F738;
    }
    r6 = (sp - 1560) + 0x4B0;
    r7 = (sp - 1560) + 0x4AF;
    r3 = (sp - 1560) + 0x4AE;
    L0603F6FA:
    r2 = LD32(0x5C8 + (sp - 1560));
    r1 = LD8(r2);
    r1 = r1 & 255;
    ST32(0x5C8 + (sp - 1560), (r2 + 1));
    ST8(r6 + r10, r1);
    r10 = r10 + 1;
    if (!(r1 == 10)) {
        goto L0603F730;
    }
    ST8(r7 + r10, 0);
    c21 = r10 > 3;
    ST8(r3 + r10, 0);
    c1044 = c21;
    if (c21) {
        goto L0603F72E;
    }
    r1 = LD8(((sp - 1560) + 0x4AD) + r10);
    c22 = (r1 & 255) == 46;
    c1044 = c22;
    if (c22) {
        goto L0603F748;
    }
    L0603F72E:
    r10 = 0;
    L0603F730:
    c23 = r8 > 0;
    r8 = r8 - 1;
    if (c23) {
        POLL();
        goto L0603F6FA;
    }
    L0603F738:
    r12 = LD32((0x5E0 + (sp - 1560)));
    r1 = r9;
    if (!((r12 & r12) == 0)) {
        goto L0603F77A;
    }
    goto L0603F75E;
    L0603F748:
    ST32((0x5E0 + (sp - 1560)), 1);
    POLL();
    goto L0603F738;
    L0603F752:
    r0 = -1;
    if (r8 == -502) {
        goto L0603F75E;
    }
    goto L0603FA52;
    L0603F75E:
    r4 = LD32(r13);
    r0 = GCALL3(0x0605ACCC, r4, (0x380 + (sp - 1560)), 0x114);
    r8 = r0;
    r0 = LD32(0x5E0 + (sp - 1560));
    r1 = r9;
    if (!((r0 & r0) == 0)) {
        goto L0603F77A;
    }
    POLL();
    goto L0603F604;
    L0603F77A:
    ST8((r1 + 1), 0);
    r5 = LD32((0x5E4 + (sp - 1560)));
    r0 = GCALL2(0x0603F318, ((sp - 1560) + 0x480), r5);
    r5 = LD32((sp - 1560) + 0x480);
    r7 = sp - 1560;
    if (!((r5 & r5) == 0)) {
        goto L0603F7EC;
    }
    r2 = LD32(0x0603F408);
    r7 = r7 + 0x200;
    ST32(0x200 + (sp - 1560), r2);
    r2 = LD32(0x0603F40C);
    ST32(r7 + 4, r2);
    r2 = LD16(0x0603F410);
    r7 = r7 + 8;
    ST16(r7, r2);
    r1 = LD8(0x0603F412);
    ST8((r7 + 2), r1);
    goto L0603F7F6;
    L0603F7EC:
    r0 = GCALL2(0x0603F240, ((sp - 1560) + 0x200), r5);
    L0603F7F6:
    r5 = LD32(0x484 + (sp - 1560));
    r3 = sp - 1560;
    if (!((r5 & r5) == 0)) {
        goto L0603F810;
    }
    r1 = LD32(0x0603F414);
    ST32(0x300 + (sp - 1560), r1);
    r1 = LD32(0x0603F418);
    ST32((r3 + 0x300) + 4, r1);
    goto L0603F81A;
    L0603F810:
    r0 = GCALL2(0x0603F240, ((sp - 1560) + 0x300), r5);
    L0603F81A:
    r5 = LD32(0x488 + (sp - 1560));
    if (!((r5 & r5) == 0)) {
        goto L0603F860;
    }
    r5 = LD32(0x49C + (sp - 1560));
    r7 = sp - 1560;
    if (!((r5 & r5) == 0)) {
        goto L0603F852;
    }
    r2 = LD32(0x0603F41C);
    r7 = r7 + 0x280;
    ST32(0x280 + (sp - 1560), r2);
    r2 = LD32(0x0603F420);
    ST32(r7 + 4, r2);
    r2 = LD32(0x0603F424);
    r7 = r7 + 8;
    ST32(r7, r2);
    r2 = LD16(0x0603F428);
    r7 = r7 + 4;
    ST16(r7, r2);
    r1 = LD8(0x0603F42A);
    ST8((r7 + 2), r1);
    goto L0603F86A;
    L0603F852:
    r0 = GCALL2(0x0603F240, ((sp - 1560) + 0x280), r5);
    goto L0603F86A;
    L0603F860:
    r0 = GCALL2(0x0603F240, ((sp - 1560) + 0x280), r5);
    L0603F86A:
    r1 = LD32(0x4A0 + (sp - 1560));
    r10 = 0;
    if ((r1 & r1) == 0) {
        goto L0603F8AC;
    }
    ST32(0x5C8 + (sp - 1560), r1);
    r1 = LD8(r1);
    r0 = sp - 1560;
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L0603F8AC;
    }
    r2 = 0x5C8;
    L0603F884:
    r1 = LD32(r0 + r2);
    r1 = LD8(r1);
    r0 = r1 & 255;
    c34 = r0 == 82;
    if (r0 == 13) {
        goto L0603F8AC;
    }
    c35 = r0 == 114;
    c1070 = c35;
    if (c34) {
        goto L0603F898;
    }
    c1070 = c35;
    if (!(c35)) {
        goto L0603F89A;
    }
    L0603F898:
    r10 = 1;
    L0603F89A:
    r1 = LD32(0x5C8 + (sp - 1560));
    r1 = r1 + 1;
    ST32(0x5C8 + (sp - 1560), r1);
    r1 = LD8(r1);
    r0 = sp - 1560;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L0603F884;
    }
    L0603F8AC:
    r1 = LD32(r13 + 28);
    r11 = LD32((0x5D0 + (sp - 1560)));
    r8 = r1 - r11;
    ST32(0x5C8 + (sp - 1560), 0);
    r9 = (sp - 1560) + 0x200;
    r0 = GCALL4(0x06018688, (0x5C8 + (sp - 1560)), r9, 0, 0);
    c38 = (r10 & r10) == 0;
    if ((r0 & r0) == 0) {
        goto L0603F95E;
    }
    ST32((sp - 1564), r8);
    if (c38) {
        goto L0603F934;
    }
    r1 = LD32((0x5CC + (sp - 1564)));
    ST32((sp - 1568), r1);
    ST32((sp - 1572), r8);
    ST32((sp - 1576), ((0x300 + (sp - 1572)) + 12));
    r0 = GCALL8(0x06045264, (sp - 1560), 0x06078920, r8, (((sp - 1576) + 0x280) + 16), LD32((sp - 1576)), LD32((sp - 1572)), LD32((sp - 1568)), LD32((sp - 1564)));
    goto L0603F9A8;
    L0603F934:
    r1 = LD32((0x5CC + (sp - 1564)));
    ST32((sp - 1568), r1);
    ST32((sp - 1572), r8);
    ST32((sp - 1576), ((0x300 + (sp - 1572)) + 12));
    r0 = GCALL8(0x06045264, (sp - 1560), 0x06078A84, r8, (((sp - 1576) + 0x280) + 16), LD32((sp - 1576)), LD32((sp - 1572)), LD32((sp - 1568)), LD32((sp - 1564)));
    goto L0603F9A8;
    L0603F95E:
    ST32((sp - 1564), r8);
    if (c38) {
        goto L0603F986;
    }
    ST32((sp - 1568), r9);
    ST32((sp - 1572), r8);
    ST32((sp - 1576), ((0x300 + (sp - 1572)) + 12));
    r0 = GCALL8(0x06045264, (sp - 1560), 0x06078920, r8, (((sp - 1576) + 0x280) + 16), LD32((sp - 1576)), LD32((sp - 1572)), LD32((sp - 1568)), LD32((sp - 1564)));
    goto L0603F9A8;
    L0603F986:
    ST32((sp - 1568), r9);
    ST32((sp - 1572), r8);
    ST32((sp - 1576), ((0x300 + (sp - 1572)) + 12));
    r0 = GCALL8(0x06045264, (sp - 1560), 0x06078A84, r8, (((sp - 1576) + 0x280) + 16), LD32((sp - 1576)), LD32((sp - 1572)), LD32((sp - 1568)), LD32((sp - 1564)));
    L0603F9A8:
    r4 = LD32(0x5C8 + (sp - 1560));
    r5 = sp - 1560;
    if ((r4 & r4) == 0) {
        goto L0603F9BA;
    }
    r0 = GCALL2(0x06027F48, r4, r5);
    r5 = sp - 1560;
    L0603F9BA:
    r0 = GCALL2(0x0603F1AC, r13, r5);
    if (!((r0 & r0) == 0)) {
        goto L0603F9E4;
    }
    r12 = 0x5D0 + (sp - 1560);
    r0 = LD32(r12);
    ST32(r12, (r0 + 1));
    r12 = LD32((0x5D0 + (sp - 1560)));
    r11 = LD32((0x5D8 + (sp - 1560)));
    if (r12 >= r11) {
        goto L0603F9E4;
    }
    POLL();
    goto L0603F54C;
    L0603F9E4:
    r12 = LD32((0x5CC + (sp - 1560)));
    if (!(r12 > 0)) {
        goto L0603FA0C;
    }
    r8 = LD32(0x5DC + (sp - 1560));
    r8 = r8 - 20;
    if (r8 >= 0) {
        goto L0603F9FA;
    }
    r8 = 0;
    L0603F9FA:
    r0 = GCALL3(0x06045264, (sp - 1560), 0x06078CA4, r8);
    r0 = GCALL2(0x0603F1AC, r13, (sp - 1560));
    L0603FA0C:
    r1 = LD32(r13 + 28);
    r0 = LD32(0x5D8 + (sp - 1560));
    if (r0 >= r1) {
        goto L0603FA2C;
    }
    r6 = LD32((0x5D8 + (sp - 1560)));
    r0 = GCALL3(0x06045264, (sp - 1560), 0x06078C64, r6);
    r0 = GCALL2(0x0603F1AC, r13, (sp - 1560));
    L0603FA2C:
    r11 = LD32((0x5CC + (sp - 1560)));
    ST32(r13 + 20, r11);
    L0603FA34:
    r0 = GCALL2(0x0603F1AC, r13, 0x06078CE4);
    r0 = LD32(0x5E4 + (sp - 1560));
    c45 = (r0 & r0) == 0;
    r0 = 0;
    if (c45) {
        goto L0603FA52;
    }
    r4 = LD32((0x5E4 + (sp - 1560)));
    r0 = GCALL1(0x06027F48, r4);
    r0 = 0;
    L0603FA52:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0603D034(int r4, int r5)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, r14, r15;
    FRAME(sp, 44);

    r14 = sp - 40;
    r12 = r4;
    r13 = r5;
    ST8(r14, 0);
    r10 = LD32((r12 + 108));
    ST32(r14 + 4, sp - 40);
    if ((r10 & r10) == 0) {
        r10 = r14;
    }
    r9 = LD32((r12 + 116));
    if ((r9 & r9) == 0) {
        r9 = r14;
    }
    r0 = GCALL1(0x0607507C, r10);
    r11 = r0;
    r0 = GCALL1(0x0607507C, r9);
    r15 = ALLOCA(sp - 40, (((int)((unsigned)((r11 + r0) + 18) >> 2)) << 2));
    r1 = LD8(r9);
    r8 = r15;
    if (!((r1 & 255) == 47)) {
        r1 = LD32(r12 + 52);
        if (r1 == 80) {
            r5 = 0x0603D024;
            SETSP(r15);
            r0 = GCALL4(0x06045264, r15, r5, r10, r9);
        } else {
            r15 = r15 - 4;
            ST32(r15, r9);
            r5 = 0x0603D014;
            SETSP(r15);
            r0 = GCALL4(0x06045264, r8, r5, r10, r1);
            r15 = r15 + 4;
        }
    } else {
        r1 = LD32(r12 + 52);
        if (r1 == 80) {
            r5 = 0x0603D008;
            SETSP(r15);
            r0 = GCALL4(0x06045264, r15, r5, r10, r9);
        } else {
            r15 = r15 - 4;
            ST32(r15, r9);
            r5 = 0x0603CFF8;
            SETSP(r15);
            r0 = GCALL4(0x06045264, r8, r5, r10, r1);
            r15 = r15 + 4;
        }
    }
    SETSP(r15);
    r0 = GCALL2(0x0603CCE0, r13, r8);
    SETSP((sp - 40));
    return r0;
}
