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
