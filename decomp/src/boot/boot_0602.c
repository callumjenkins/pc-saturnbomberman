#include "krnl.h"

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06020218(int r4, int r5, int r6)
{
    int r1;

    r6 = r6 & 255;
    r1 = r5;
    if (!((r6 & r6) == 0)) {
        ST16((r1 + 26), r6);
        return;
    } else {
        ST16((r5 + 26), 4);
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06020DCC(int r4)
{
    int r0, r1, r2, c0;

    r1 = LD32(r4 + 28);
    c0 = (r1 & r1) == 0;
    r1 = c0;
    if (!(c0)) {
        r0 = LD32(r4 + 32);
        return r0;
    } else {
        r2 = LD32(0x340 + r4);
        return r2 > r1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060216EC(int r4)
{
    int r0, r1, r2, c2;

    r0 = r4;
    r1 = ((int)((unsigned)r0 >> 8)) & 255;
    if (!(r1 > 0)) {
        r1 = 1;
    }
    r2 = 7;
    if (r1 > 7) {
        r1 = r2;
    }
    c2 = ((r0 & 4) & (r0 & 4)) == 0;
    r0 = r1;
    if (c2) {
        r0 = LD32((r0 << 2) + 0x06076580);
        return r0;
    } else {
        r0 = LD32((r0 << 2) + 0x0607659C);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06021A70(int r4)
{
    int r0, r1, r2, r5, r6, r7, r8, r9, r10, r11;
    int v24;
    int v28;

    r9 = r4;
    r0 = GCALL4(0x060279E0, 0, 0x100, 1, 1);
    r10 = r0;
    r5 = LD32(r9 + 8);
    r0 = GCALL3(0x0604B358, r10, r5, 0x100);
    r0 = 0;
    r1 = LD32(r9 + 36);
    r11 = 0x06016478;
    ST32(0x060767F8, r1);
    ST32(0x0608AB70, r10);
    r1 = LD32(r9 + 44);
    ST32(0x0608AB6C, ((r1 >> 1) >> 1));
    r1 = 0;
    do {
        r7 = LD32(r9 + 24);
        r6 = LD32(r9 + 28);
        r5 = LD8(((r1 + r10) + 32));
        r8 = 0x0608AB6C;
        r1 = LD32(0x0608AB6C);
        r4 = LD32(r9 + 12);
        v24 = r0;
        r0 = GCALL6(r11, (r4 + (r1 * r0)), ((int)((unsigned)(r5 & 255) >> 2)), r6, r7, (r0 + 19), v24);
        r0 = v24 + 1;
        r1 = r0;
    } while (AGAIN(!(r0 > 95)));
    r0 = 160;
    r11 = r8;
    r8 = 0x06016478;
    do {
        r7 = LD32(r9 + 24);
        r6 = LD32(r9 + 28);
        r5 = LD8(r0 + r10);
        r1 = LD32(r11);
        r4 = LD32(r9 + 12);
        v24 = r0;
        r0 = GCALL6(r8, (r4 + (r1 * (r0 - 64))), ((int)((unsigned)(r5 & 255) >> 2)), r6, r7, (r0 - 45), v24);
        r0 = v24 + 1;
        r2 = r9;
    } while (AGAIN(!(r0 > 255)));
    ST8((r2 + 6), 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060221DC(int r4, int r5, int r6)
{
    int r1, r2, r3, r7;

    r2 = r5;
    r3 = 0;
    if (!(r2 > r6)) {
        r7 = LD32(0x0608AB70);
        do {
            r1 = LD8(r4 + r2);
            r2 = r2 + 1;
            r1 = LD8(r7 + (r1 & 127));
            r3 = r3 + ((int)((unsigned)(r1 & 255) >> 2));
        } while (AGAIN(!(r2 > r6)));
    }
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602306C(void)
{
    int r0, r1, r2, r7, r8, r9, r10, r11, r12, r13;
    FRAME(sp, 56);

    ST16(sp - 52, 16);
    ST16((sp - 50), 208);
    ST16((sp - 48), 22);
    ST16((sp - 46), 221);
    ST32((sp - 56), 0);
    r0 = GCALL6(0x06022750, (sp - 52), 0x1000, 0x2C0, 32, LD32((sp - 56)), LD32((sp - 52)));
    r12 = (sp - 56) + 12;
    ST16(r12, 16);
    r11 = (sp - 56) + 14;
    ST16(r11, 208);
    ST16((sp - 40), 22);
    r9 = (sp - 56) + 18;
    ST16(r9, 208);
    ST16((r12 + 8), 22);
    r10 = (sp - 56) + 22;
    r2 = LD16(r9);
    r8 = (sp - 56) + 26;
    r2 = r2 + 6;
    ST16(r10, r2);
    r1 = LD16(r12);
    r13 = 0x0608D3B0;
    ST16((sp - 32), r1);
    ST16(r8, r2);
    r1 = LD8(0x0608D3B0);
    if (!((((signed char)r1) & ((signed char)r1)) == 0)) {
        ST32((sp - 56), 0xFFFF);
        r0 = GCALL6(0x06068D14, 0, 192, 0x1003, r12, LD32((sp - 56)), LD32((sp - 52)));
    }
    r1 = LD16(r11);
    ST16(r11, (r1 + 7));
    r1 = LD16(r9);
    ST16(r9, (r1 + 7));
    r1 = LD16(r10);
    ST16(r10, (r1 + 7));
    r1 = LD16(r8);
    ST16(r8, (r1 + 7));
    r8 = r13 + 1;
    r1 = LD8(r8);
    r7 = r12;
    if (!((((signed char)r1) & ((signed char)r1)) == 0)) {
        ST32((sp - 56), 0xFFFF);
        r0 = GCALL6(0x06068D14, 0, 192, 0x101C, r7, LD32((sp - 56)), LD32((sp - 52)));
    }
    ST8(r8, 0);
    ST8(r13, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060232A8(void)
{
    int r0, r1, r2, r3, r6, r7, r8;
    FRAME(sp, 28);

    r8 = LD32(0x06078024);
    if (!((r8 & r8) == 0)) {
        r1 = LD32(r8 + 12);
        r3 = r8;
        if (!((r1 & r1) == 0)) {
            r2 = LD16((r8 + 16));
            r1 = LD32(0x060759CC);
            ST16((r3 + 8), ((r2 >> 1) - (r1 >> 1)));
            r1 = LD16((r8 + 18));
            r2 = LD32(0x060759B4);
            ST16((r8 + 10), ((r1 - r2) >> 1));
        } else {
            r1 = LD16((r8 + 2));
            ST16((r8 + 10), (r1 + 1));
        }
        r6 = r8 + 8;
        r1 = LD16(r6);
        r7 = r8 + 10;
        ST16(sp - 24, r1);
        r1 = LD16(r7);
        ST16((sp - 22), r1);
        r2 = LD16(r6);
        r2 = r2 + 1;
        ST16((sp - 20), r2);
        r1 = LD16(r7);
        ST16((sp - 18), r1);
        ST16((sp - 16), r2);
        r1 = LD32(0x060767F8);
        r2 = LD16(r7);
        r2 = (r2 + r1) - 4;
        ST16((sp - 14), r2);
        r1 = LD16(r6);
        ST16((sp - 12), r1);
        ST16((sp - 10), r2);
        r1 = LD32(0x06089B00);
        r6 = 255;
        if (!(r1 >= 0)) {
            r6 = 227;
        }
        ST32((sp - 28), 0xFFFF);
        r0 = GCALL6(0x06068D14, 0, 192, r6, (sp - 24), LD32((sp - 28)), LD32((sp - 24)));
        r1 = LD32(0x0607685C);
        if (!(r8 == r1)) {
            if (!((r1 & r1) == 0)) {
                r0 = GCALL5(0x06032164, 8, 0, 0, 0, LD32((sp - 24)));
            }
        }
    }
    ST32(0x0607685C, r8);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602443C(int r4, int r5, int r6, int r7)
{
    int r1, r2, c1, c3;

    ST32(r6, 0);
    ST32(r7, 0);
    r2 = LD32(r4);
    r1 = r2;
    if (!(r2 > 7)) {
        ST32(r6, (r1 - 8));
        ST32(r4, 8);
    }
    r1 = LD32(r4);
    r2 = 0x138;
    c1 = r1 > 0x138;
    r1 = r1 - 0x138;
    if (c1) {
        ST32(r6, r1);
        ST32(r4, r2);
    }
    r2 = LD32(r5);
    r1 = r2;
    if (!(r2 > 15)) {
        ST32(r7, (r1 - 16));
        ST32(r5, 16);
    }
    r1 = LD32(r5);
    r2 = 224;
    c3 = r1 > 224;
    r1 = r1 - 224;
    if (!(c3)) {
        return;
    } else {
        ST32(r7, r1);
        ST32(r5, r2);
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060255E0(int r4)
{
    int r1, r2, r3, r7;

    r1 = r4;
    r7 = LD8(r1);
    r3 = LD8((r1 + 1));
    r2 = LD8((r4 + 2));
    r1 = LD8((r4 + 3));
    return ((((r1 << 16) << 8) | ((r2 & 255) << 16)) | ((r3 & 255) << 8)) | (r7 & 255);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025608(int r4)
{
    int r1, r2;

    r2 = LD8(r4);
    r1 = LD8((r4 + 1));
    return ((r1 & 255) << 8) | (r2 & 255);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025618(int r4)
{
    int r1, r2;

    r2 = LD8(r4);
    r1 = LD8((r4 + 1));
    return ((r2 & 255) << 8) | (r1 & 255);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060258EC(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12;

    r11 = r4;
    r8 = r5;
    r9 = r6;
    r10 = r7;
    r12 = 0x0608AB80;
    ST8(0x0608AB80, 1);
    r0 = GCALL4(0x0606A9EC, r4, 0, r6, r7);
    if (!(r0 >= 0)) {
        r0 = -2;
    } else {
        ST32(r8 + 20, r0);
        ST32(r8 + 8, r9);
        ST32(r8 + 12, r10);
        ST32(r8 + 16, 0);
        r0 = GCALL3(0x060750A0, (r8 + 28), r11, 20);
        ST8(r12, 0);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025948(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8;

    r8 = 0x0608AB80;
    ST8(0x0608AB80, 1);
    r0 = GCALL4(0x0606A9EC, r4, 0, r6, r7);
    r1 = 0;
    if (!(r0 >= 0)) {
        ST8(r8, r1);
        r0 = -2;
    } else {
        r3 = LD32(r8 + 12);
        r1 = LD32(r3 + 8);
        ST8(r8, 0);
        r0 = LD32((r1 + (r0 * 24)) + 4);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060259B4(int r4)
{
    int r1, r2;

    r2 = 0x0608AB80;
    ST32(r4 + 4, 0);
    ST8(r4, 0);
    ST8(0x0608AB80, 1);
    r1 = LD32(0x0608AB84);
    if (!((r1 & r1) == 0)) {
        r1 = LD32(r2 + 8);
        ST32(r1 + 4, r4);
    } else {
        ST32(r2 + 4, r4);
    }
    ST32(r2 + 8, r4);
    ST8(r2, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060259E0(void)
{
    int r0;

    r0 = LD32(0x060769B8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060259EC(int r4)
{
    int r0;

    r0 = r4;
    ST32(0x060769B8, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060259F8(int r4)
{
    int r0;

    r0 = 1;
    if (!((unsigned)r4 >= (unsigned)0x0600A000)) {
        return r0;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025AB4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = r4;
    r0 = GCALL4(0x06025A0C, 4, r5, r6, r7);
    ST8(184 + r8, 0);
    r1 = LD32(0x06000334);
    r0 = GCALL1(r1, 4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025B44(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8;

    r8 = r4;
    r0 = GCALL4(0x06025A0C, 2, r5, r6, r7);
    r1 = LD32(0x060769B0);
    r2 = 0;
    if (!((r1 & r1) == 0)) {
        do {
            r2 = r1;
            r1 = LD32(r2);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    if (!((r2 & r2) == 0)) {
        ST32(r2, r8);
    } else {
        ST32(0x060769B0, r8);
    }
    ST32(r8, 0);
    r1 = LD32(0x06000334);
    r0 = GCALL1(r1, 2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06026F98(int r4, int r5)
{
    int r0, r1, c2;

    r1 = LD32(144 + r4);
    r0 = 0;
    if ((r1 & r1) == 0) {
        return r0;
    } else {
        r0 = LD32(r1);
        if (!(r0 == 7)) {
            return 0;
        } else {
            r1 = LD32(r1 + 36);
            c2 = r1 == r5;
            r0 = c2;
            if (c2) {
                return r0;
            } else {
                return 0;
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06027620(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11;

    r0 = GCALL4(0x06025A0C, 2, r5, r6, r7);
    r8 = LD32(0x060769B0);
    if (!((r8 & r8) == 0)) {
        r11 = 0x06025AE0;
        r10 = 0x118;
        r9 = 0x06025AB4;
        do {
            r0 = GCALL1(r11, r8);
            ST32(r8 + r10, 0);
            r0 = GCALL1(r9, r8);
            r8 = LD32(r8);
        } while (AGAIN(!((r8 & r8) == 0)));
    }
    r1 = LD32(0x06000334);
    r0 = GCALL1(r1, 2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06027800(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7;

    r3 = 0;
    r5 = 0x0608AC30;
    r6 = 0x0608AC98;
    r7 = 1;
    r0 = 0;
    while (1) {
        r2 = LD32(r0 + r5);
        if (!((unsigned)r4 >= (unsigned)r2)) {
            r3 = r3 + 1;
            r0 = r0 + 4;
            if (!(r3 > r7)) {
                POLL();
                continue;
            } else {
                return -1;
            }
        } else {
            r1 = LD32(r0 + r6);
            if ((unsigned)r4 >= (unsigned)(r1 + r2)) {
                r3 = r3 + 1;
                r0 = r0 + 4;
                if (!(r3 > r7)) {
                    POLL();
                    continue;
                } else {
                    return -1;
                }
            } else {
                return r3;
            }
        }
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06027988(int r4)
{
    int r0, r1;

    r0 = r4;
    if (!((unsigned)r4 > (unsigned)1)) {
        r4 = LD32((r0 << 2) + 0x0608ACA0);
        r1 = 0;
        if (!((r4 & r4) == 0)) {
            do {
                r0 = LD32(r4 + 4);
                if ((unsigned)r0 > (unsigned)r1) {
                    r1 = r0;
                }
                r4 = LD32(r4);
            } while (AGAIN(!((r4 & r4) == 0)));
        }
        return r1;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06027BC4(int r4, int r5)
{
    int r0, r6, r8, r9;

    r9 = r5;
    r0 = GCALL4(0x060279E0, r4, r5, -1, 1);
    r8 = r0;
    r6 = r9;
    if (!((r8 & r8) == 0)) {
        r0 = GCALL3(0x0604B3F0, r8, 0, r6);
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06028378(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602837C(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06028380(int r4, int r5)
{
    int r0, r1, r2, r7, r8, r9, r10, r11;

    r10 = r4;
    r9 = r5;
    r2 = 0;
    r8 = 0;
    r11 = 0x060279E0;
    r0 = 0;
    while (1) {
        r0 = r0 << 2;
        r1 = LD32(r0 + 0x0608AC98);
        if ((r1 & r1) == 0) {
            r8 = r8 + 1;
            r0 = r8;
            if (!(r8 > 1)) {
                POLL();
                continue;
            } else {
                r8 = 0;
                r11 = 0x060279E0;
                r0 = 0;
                while (1) {
                    r0 = r0 << 2;
                    r1 = LD32(r0 + 0x0608AC98);
                    if ((r1 & r1) == 0) {
                        r8 = r8 + 1;
                        r0 = r8;
                        if (!(r8 > 1)) {
                            POLL();
                            continue;
                        } else {
                            r0 = r2;
                            break;
                        }
                    } else {
                        r1 = LD32(r0 + 0x0608AC30);
                        r7 = 1;
                        if ((r1 & r1) == 0) {
                            r8 = r8 + 1;
                            r0 = r8;
                            if (!(r8 > 1)) {
                                POLL();
                                continue;
                            } else {
                                r0 = r2;
                                break;
                            }
                        } else {
                            r0 = GCALL4(r11, r8, r10, r9, r7);
                            r2 = r0;
                            if (!((r2 & r2) == 0)) {
                                break;
                            } else {
                                r8 = r8 + 1;
                                r0 = r8;
                                if (!(r8 > 1)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = r2;
                                    break;
                                }
                            }
                        }
                    }
                    POLL();
                }
                break;
            }
        } else {
            r1 = LD32(r0 + 0x0608AC30);
            r7 = 0;
            if ((r1 & r1) == 0) {
                r8 = r8 + 1;
                r0 = r8;
                if (!(r8 > 1)) {
                    POLL();
                    continue;
                } else {
                    r8 = 0;
                    r11 = 0x060279E0;
                    r0 = 0;
                    while (1) {
                        r0 = r0 << 2;
                        r1 = LD32(r0 + 0x0608AC98);
                        if ((r1 & r1) == 0) {
                            r8 = r8 + 1;
                            r0 = r8;
                            if (!(r8 > 1)) {
                                POLL();
                                continue;
                            } else {
                                r0 = r2;
                                break;
                            }
                        } else {
                            r1 = LD32(r0 + 0x0608AC30);
                            r7 = 1;
                            if ((r1 & r1) == 0) {
                                r8 = r8 + 1;
                                r0 = r8;
                                if (!(r8 > 1)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = r2;
                                    break;
                                }
                            } else {
                                r0 = GCALL4(r11, r8, r10, r9, r7);
                                r2 = r0;
                                if (!((r2 & r2) == 0)) {
                                    break;
                                } else {
                                    r8 = r8 + 1;
                                    r0 = r8;
                                    if (!(r8 > 1)) {
                                        POLL();
                                        continue;
                                    } else {
                                        r0 = r2;
                                        break;
                                    }
                                }
                            }
                        }
                        POLL();
                    }
                    break;
                }
            } else {
                r0 = GCALL4(r11, r8, r10, r9, r7);
                r2 = r0;
                if (!((r2 & r2) == 0)) {
                    break;
                } else {
                    r8 = r8 + 1;
                    r0 = r8;
                    if (!(r8 > 1)) {
                        POLL();
                        continue;
                    } else {
                        r8 = 0;
                        r11 = 0x060279E0;
                        r0 = 0;
                        while (1) {
                            r0 = r0 << 2;
                            r1 = LD32(r0 + 0x0608AC98);
                            if ((r1 & r1) == 0) {
                                r8 = r8 + 1;
                                r0 = r8;
                                if (!(r8 > 1)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = r2;
                                    break;
                                }
                            } else {
                                r1 = LD32(r0 + 0x0608AC30);
                                r7 = 1;
                                if ((r1 & r1) == 0) {
                                    r8 = r8 + 1;
                                    r0 = r8;
                                    if (!(r8 > 1)) {
                                        POLL();
                                        continue;
                                    } else {
                                        r0 = r2;
                                        break;
                                    }
                                } else {
                                    r0 = GCALL4(r11, r8, r10, r9, r7);
                                    r2 = r0;
                                    if (!((r2 & r2) == 0)) {
                                        break;
                                    } else {
                                        r8 = r8 + 1;
                                        r0 = r8;
                                        if (!(r8 > 1)) {
                                            POLL();
                                            continue;
                                        } else {
                                            r0 = r2;
                                            break;
                                        }
                                    }
                                }
                            }
                            POLL();
                        }
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
int f06028410(int r4)
{
    int r0;

    r0 = LD32((r4 << 2) + 0x2608AC38);
    if ((unsigned)r0 > (unsigned)15) {
        return r0 - 16;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060284CC(void)
{
    int r1, r2, r3, r6, r7;

    r7 = 0x060875D0;
    r6 = 0;
    r2 = 0x060875D0;
    r3 = 0x060877C8;
    do {
        r1 = r2 + 9;
        r2 = r2 + 8;
        ST8(r1, r6);
    } while (AGAIN(!(r2 > r3)));
    ST8((r7 + 1), -1);
    ST8(r7, -1);
    ST16((r7 + 6), 0);
    ST16((r7 + 2), 0);
    ST16((r7 + 4), 0x180);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06028688(int r4)
{
    int r0, r1;

    r0 = 63;
    r4 = r4 + 0x1F8;
    while (1) {
        r1 = LD8((r4 + 9));
        if (((r1 & 255) & (r1 & 255)) == 0) {
            break;
        } else {
            r0 = r0 - 1;
            r4 = r4 - 8;
            if (r0 >= 0) {
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
int f06028878(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10, r11;

    r9 = 0;
    r8 = r4;
    r10 = 0;
    if (!((r8 & r8) == 0)) {
        r11 = 0;
        while (1) {
            r0 = GCALL1(0x060287D0, 20);
            r1 = r8;
            if ((r0 & r0) == 0) {
                break;
            } else {
                r2 = LD32(r1);
                ST32(r0, r2);
                r2 = LD32(r8 + 4);
                r1 = (r1 + 4) + 4;
                ST32(r0 + 4, r2);
                r2 = LD32(r1);
                r1 = r1 + 4;
                r3 = r0 + 8;
                ST32(r3, r2);
                r2 = LD32(r1);
                r3 = r3 + 4;
                ST32(r3, r2);
                r1 = LD32((r1 + 4));
                ST32(r3 + 4, r1);
                if (!((r9 & r9) == 0)) {
                    ST32(r10 + 12, r0);
                    ST32(r0 + 12, r11);
                    r10 = r0;
                } else {
                    r9 = r0;
                    r10 = r9;
                    ST32(r9 + 12, r11);
                }
                r8 = LD32(r8 + 12);
                if (!((r8 & r8) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060288E0(int r4)
{
    int r0, r8, r9;

    if (!((r4 & r4) == 0)) {
        r9 = 0x06027F48;
        do {
            r8 = LD32(r4 + 12);
            r0 = GCALL1(r9, r4);
            r4 = r8;
        } while (AGAIN(!((r4 & r4) == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06029058(int r4)
{
    int r0, r1, r2;

    r1 = LD32(0x10C8 + r4);
    r0 = 0;
    if ((r1 & r1) == 0) {
        return r0;
    } else {
        r2 = LD32(0x060769C8);
        r0 = r2;
        if ((r2 & r2) == 0) {
            return 0;
        } else {
            r0 = LD32(r0 + 144);
            return r0;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06029084(int r4)
{
    int r0, r1, r2, r3, c0;

    r1 = LD32(0x10C8 + r4);
    c0 = (r1 & r1) == 0;
    r0 = c0;
    if (c0) {
        return r0;
    } else {
        r2 = LD32(0x060769C8);
        r3 = r2;
        if (!((r2 & r2) == 0)) {
            r3 = r3 + 68;
            r1 = LD32(r3);
            if ((r1 & r1) == 0) {
                r1 = LD32(r2 + 60);
                ST32(r3, r1);
            }
            return 1;
        } else {
            return 0;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060290B8(int r4)
{
    int r0, r1, c1;

    r1 = LD32(0x10C8 + r4);
    r0 = 0;
    if ((r1 & r1) == 0) {
        return r0;
    } else {
        r1 = LD32(0x060769C8);
        c1 = (r1 & r1) == 0;
        r1 = r1 + 72;
        if (c1) {
            return r0;
        } else {
            r0 = LD32(r1);
            return r0;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060290DC(int r4)
{
    int r0, r1, c1;

    r1 = LD32(0x10C8 + r4);
    r0 = 0;
    if ((r1 & r1) == 0) {
        return r0;
    } else {
        r1 = LD32(0x060769C8);
        c1 = (r1 & r1) == 0;
        r1 = r1 + 76;
        if (c1) {
            return r0;
        } else {
            r0 = LD32(r1);
            return r0;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06029634(int r4, int r5)
{
    int r0, r1;

    r1 = LD8((r5 + 64));
    r0 = r1 & 255;
    if (r0 == 2) {
        r0 = GCALL1(0x0601A024, r4);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06029658(int r4, int r5)
{
    int r0, r1;

    r1 = LD8((r5 + 64));
    r0 = r1 & 255;
    if (r0 == 2) {
        r0 = GCALL1(0x0601A074, r4);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06029E2C(int r4)
{
    ST32(r4, 0);
    ST32(r4 + 4, 0);
    ST32(r4 + 8, 0);
    ST32(r4 + 12, 0);
    ST32(r4 + 24, 0);
    ST32(r4 + 28, 0);
    ST32(r4 + 32, 0);
    ST32(r4 + 36, 0);
    ST32(r4 + 40, 0);
    ST32(r4 + 44, 0);
    ST32(r4 + 48, 0);
    ST32(r4 + 52, 0);
    ST32(r4 + 56, 0);
    ST32(r4 + 60, 0);
    ST32((r4 + 64), 0);
    ST32((r4 + 68), 0);
    ST32((r4 + 72), 0);
    ST32((r4 + 76), 0);
    ST32((r4 + 80), 0);
    ST32((r4 + 92), 0);
    ST32((r4 + 96), 0);
    ST32((r4 + 100), 0);
    ST32((r4 + 104), 0);
    ST32((r4 + 108), 0);
    ST32((r4 + 112), 0);
    ST16((r4 + 116), 146);
    ST32((r4 + 120), 0);
    ST32((r4 + 124), -1);
    ST32(128 + r4, 0);
    ST32(132 + r4, 0);
    ST32(136 + r4, 0);
    ST32(140 + r4, 0);
    ST32(144 + r4, 0);
    return 144;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06029EC4(int r4)
{
    ST32(r4, 0);
    ST32(r4 + 4, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06029ECC(int r4, int r5)
{
    int r1;

    r1 = LD32(0x060769CC);
    r1 = r1 + 1;
    ST32(0x060769CC, r1);
    ST32(r5, r1);
    ST32(r5 + 4, 0);
    ST32(r5 + 8, 0);
    ST32(r5 + 12, 0);
    ST32(r5 + 16, 0);
    ST32(r5 + 20, 0);
    ST32(r5 + 24, 0);
    ST32(r5 + 28, 0);
    ST32(r5 + 32, 0);
    ST32(r5 + 36, 0);
    ST32(r5 + 40, 0);
    ST32(r5 + 44, r4);
    ST32(r5 + 48, 0);
    ST32(r5 + 52, 0);
    ST32(r5 + 56, 0);
    ST32(r5 + 60, 0);
    ST8((r5 + 64), 1);
    ST8((r5 + 65), 0);
    ST32((r5 + 68), 1);
    ST32((r5 + 72), 1);
    ST32((r5 + 76), -1);
    ST32((r5 + 80), 0);
    ST32((r5 + 84), 0);
    ST32((r5 + 88), 0);
    ST32((r5 + 92), 0);
    ST16((r5 + 96), 146);
    ST32((r5 + 100), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06029F48(int r4)
{
    ST32(r4, 0);
    ST32(r4 + 4, 0);
    ST32(r4 + 8, 1);
    ST32(r4 + 12, 0);
    ST32(r4 + 16, 1);
    ST32(r4 + 20, 1);
    ST32(r4 + 24, 1);
    ST32(r4 + 32, 0);
    ST32(r4 + 36, 0);
    ST32(r4 + 28, 0);
    ST32(r4 + 40, 0);
    ST32(r4 + 44, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06029F68(int r4)
{
    ST32(r4, 0);
    ST32(r4 + 4, 1);
    ST32(r4 + 8, 1);
    ST32(r4 + 12, 0);
    ST32(r4 + 16, 0);
    ST32(r4 + 20, 1);
    ST32(r4 + 24, 0);
    ST32(r4 + 28, 0);
    ST32(r4 + 32, -1);
    ST32(r4 + 36, 0);
    ST16((r4 + 40), 146);
    ST32(r4 + 44, 0);
    ST32(r4 + 48, 0);
    ST32(r4 + 52, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06029F94(int r4)
{
    int r0, r8, r9, r10, r11;

    r9 = r4;
    if (!((r9 & r9) == 0)) {
        r11 = 0x0602A030;
        r10 = 0x06027F48;
        r8 = r9;
        do {
            r4 = LD32(r8);
            r9 = LD32(r9 + 4);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(r11, r4);
                r4 = LD32(r8);
                r0 = GCALL1(r10, r4);
            }
            r0 = GCALL1(r10, r8);
            r8 = r9;
        } while (AGAIN(!((r9 & r9) == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602A030(int r4)
{
    int r0, r8, r9, r10;

    r9 = r4;
    r8 = LD32(r9 + 40);
    r4 = r8;
    if (!((r8 & r8) == 0)) {
        r10 = 0x06027F48;
        do {
            r8 = LD32(r8 + 44);
            r0 = GCALL1(r10, r4);
            r4 = r8;
        } while (AGAIN(!((r8 & r8) == 0)));
    }
    r8 = LD32(r9 + 56);
    r4 = r8;
    if (!((r8 & r8) == 0)) {
        r9 = 0x06029FF8;
        do {
            r8 = LD32(r8 + 52);
            r0 = GCALL1(r9, r4);
            r4 = r8;
        } while (AGAIN(!((r8 & r8) == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602A9F0(int r4)
{
    int r0, r1, r2, r3, r8;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r1 = LD32(r8 + 56);
        r3 = r8;
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x0602A984, r8);
            r1 = LD32((r8 + 64));
            ST32(r8 + 60, r1);
            r1 = LD32(r8 + 40);
            r2 = r8 + 72;
            ST32(r8 + 44, r1);
            r1 = LD32(r2);
            r0 = 1;
            ST32(r2, (r1 + 1));
        } else {
            r1 = LD32((r8 + 64));
            r3 = r3 + 72;
            r2 = LD32(r3);
            r1 = LD32(r1 + 20);
            if (r2 >= r1) {
                r0 = GCALL1(0x0602A984, r8);
                r1 = LD32((r8 + 64));
                ST32(r8 + 60, r1);
                r1 = LD32(r8 + 40);
                r2 = r8 + 72;
                ST32(r8 + 44, r1);
                r1 = LD32(r2);
                r0 = 1;
                ST32(r2, (r1 + 1));
            } else {
                r1 = LD32(r8 + 60);
                r1 = LD32(r1 + 52);
                ST32(r8 + 60, r1);
                r1 = LD32(r8 + 40);
                ST32(r8 + 44, r1);
                r1 = LD32(r3);
                r0 = 1;
                ST32(r3, (r1 + 1));
            }
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602AAC4(int r4, int r5)
{
    int r0, r1;

    r0 = 0;
    if ((r4 & r4) == 0) {
        return r0;
    } else {
        r0 = LD32(r4 + 40);
        if ((r0 & r0) == 0) {
            return 0;
        } else {
            while (1) {
                r1 = LD32(r0 + 12);
                if (r1 == r5) {
                    return r0;
                } else {
                    r0 = LD32(r0 + 44);
                    if (!((r0 & r0) == 0)) {
                        POLL();
                        continue;
                    } else {
                        return 0;
                    }
                }
                POLL();
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602AAE4(int r4, int r5)
{
    int r0, r1;

    r0 = 0;
    if ((r4 & r4) == 0) {
        return r0;
    } else {
        r0 = LD32(r4 + 56);
        if ((r0 & r0) == 0) {
            return 0;
        } else {
            while (1) {
                r1 = LD32(r0 + 20);
                if (r1 == r5) {
                    return r0;
                } else {
                    r0 = LD32(r0 + 52);
                    if (!((r0 & r0) == 0)) {
                        POLL();
                        continue;
                    } else {
                        return 0;
                    }
                }
                POLL();
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602AB04(int r4, int r5)
{
    int r0, r1, r8, r9;
    int v16;

    r8 = r4;
    r9 = r5;
    r0 = GCALL1(0x060287D0, 8);
    r4 = r0;
    if (!((r0 & r0) == 0)) {
        v16 = r0;
        r0 = GCALL5(0x06029EC4, r4, 0, 0, 0, v16);
        r0 = v16;
        ST32(r0, r9);
        r1 = LD32(r8 + 20);
        if (!((r1 & r1) == 0)) {
            r1 = LD32(r8 + 24);
            ST32(r1 + 4, r0);
            ST32(r8 + 24, r0);
        } else {
            ST32(r8 + 20, r0);
            ST32(r8 + 24, r0);
        }
        r0 = 1;
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602AB9C(void)
{
    int r0, r1, r2, r3, r7, c0, c1;

    r7 = 0x060769C8;
    r1 = LD32(0x060769C8);
    c0 = (r1 & r1) == 0;
    r1 = r1 + 76;
    if (c0) {
        r0 = 0;
    } else {
        r2 = LD32(r1);
        c1 = (r2 & r2) == 0;
        r0 = c1;
        if (!(c1)) {
            r3 = LD32(r2 + 20);
            if ((r3 & r3) == 0) {
                r0 = GCALL0(0x0602ABEC);
                r0 = 0;
            } else {
                r1 = LD32(r2 + 28);
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r1 + 4);
                    if ((r1 & r1) == 0) {
                        ST32(r2 + 28, 0);
                        r0 = GCALL0(0x0602ABEC);
                        r0 = 0;
                    } else {
                        ST32(r2 + 28, r1);
                        r1 = LD32(r1);
                        r0 = 1;
                        ST32(r7, r1);
                    }
                } else {
                    r1 = LD32(r2 + 20);
                    ST32(r2 + 28, r3);
                    r1 = LD32(r1);
                    r0 = 1;
                    ST32(r7, r1);
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602ABEC(void)
{
    int r1, r2, c0, c5;

    r2 = 0x060769C8;
    r1 = LD32(0x060769C8);
    c0 = (r1 & r1) == 0;
    r1 = r1 + 80;
    if (c0) {
        return;
    } else {
        r1 = LD32(r1);
        if ((r1 & r1) == 0) {
            return;
        } else {
            r1 = LD32(r1 + 44);
            if ((r1 & r1) == 0) {
                return;
            } else {
                ST32(r2, r1);
                r2 = LD32((r1 + 76));
                if ((r2 & r2) == 0) {
                    return;
                } else {
                    r1 = LD32(r2 + 28);
                    if ((r1 & r1) == 0) {
                        return;
                    } else {
                        r1 = LD32(r1 + 4);
                        c5 = (r1 & r1) == 0;
                        r1 = 0;
                        if (!(c5)) {
                            return;
                        } else {
                            ST32(r2 + 28, r1);
                            return;
                        }
                    }
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602AC28(int r4)
{
    int r1, r2, c0;

    r1 = LD32(0x060769C8);
    c0 = (r1 & r1) == 0;
    r1 = r1 + 76;
    if (!(c0)) {
        r2 = LD32(r1);
        if ((r2 & r2) == 0) {
            POLL();
            return 0;
        } else {
            r1 = LD32(r2 + 32);
            if (r4 > r1) {
                ST32(r2 + 32, r4);
            }
            return 1;
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602AC4C(int r4)
{
    int r1, r2, c0;

    r1 = LD32(0x060769C8);
    c0 = (r1 & r1) == 0;
    r1 = r1 + 76;
    if (!(c0)) {
        r2 = LD32(r1);
        if ((r2 & r2) == 0) {
            POLL();
            return 0;
        } else {
            r1 = LD32(r2 + 36);
            if (r4 > r1) {
                ST32(r2 + 36, r4);
            }
            return 1;
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B0B0(void)
{
    int r0, r1, r2, r3, r7;

    r2 = LD32(0x060769C8);
    r1 = r2;
    if (!((r2 & r2) == 0)) {
        r3 = LD32((r1 + 96));
        r0 = LD32((r2 + 92));
        if (r0 > 0) {
            r3 = r3 + 2;
        }
        r7 = r2 + 100;
        r1 = LD32(r7);
        r2 = LD32(r2 + 40);
        r0 = (r0 + r0) + r1;
        if (!((r2 & r2) == 0)) {
            do {
                r1 = LD32(r2 + 32);
                if (!((r1 & r1) == 0)) {
                    r0 = r0 + r3;
                }
                r1 = LD32(r2 + 36);
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r7);
                    r0 = (r0 + r3) + r1;
                }
                r2 = LD32(r2 + 44);
            } while (AGAIN(!((r2 & r2) == 0)));
        }
        return r0;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B100(void)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, c4;

    r8 = LD32(0x060769C8);
    r9 = 0;
    r10 = 0;
    if (!((r8 & r8) == 0)) {
        r2 = LD32(r8 + 40);
        if (!((r2 & r2) == 0)) {
            do {
                r1 = LD32(r2 + 20);
                r9 = r9 + r1;
                r1 = LD32(r2 + 24);
                r2 = LD32(r2 + 44);
                r10 = r10 + r1;
            } while (AGAIN(!((r2 & r2) == 0)));
        }
        r0 = GCALL0(0x0602B0B0);
        r9 = r9 + r0;
        r10 = r10 + r0;
        ST32(r8 + 32, r9);
        ST32(r8 + 36, r10);
        r6 = r8 + 80;
        r7 = LD32(r6);
        r1 = r8;
        if ((r7 & r7) == 0) {
            r0 = 1;
        } else {
            r1 = LD32((r1 + 104));
            c4 = (r1 & r1) == 0;
            r1 = r8;
            if (c4) {
                r3 = r8;
                r3 = r3 + 80;
                r2 = LD32(r3);
                r1 = LD32(r2 + 32);
                if (r9 > r1) {
                    ST32(r2 + 32, r9);
                }
                r2 = LD32(r3);
                r1 = LD32(r2 + 36);
                if (r10 > r1) {
                    ST32(r2 + 36, r10);
                }
                r0 = 1;
            } else {
                r1 = LD32((r1 + 112));
                r3 = r8;
                if (!((r1 & r1) == 0)) {
                    r3 = r3 + 80;
                    r2 = LD32(r3);
                    r1 = LD32(r2 + 32);
                    if (r9 > r1) {
                        ST32(r2 + 32, r9);
                    }
                    r2 = LD32(r3);
                    r1 = LD32(r2 + 36);
                    if (r10 > r1) {
                        ST32(r2 + 36, r10);
                    }
                    r0 = 1;
                } else {
                    r3 = LD32(r8 + 32);
                    r5 = r8 + 108;
                    r2 = LD32(r5);
                    r1 = LD32(r7 + 32);
                    if (!(r3 > r2)) {
                        if (r2 > r1) {
                            ST32(r7 + 32, r2);
                        }
                        r3 = LD32(r6);
                        r2 = LD32(r5);
                    } else {
                        if (r3 > r1) {
                            ST32(r7 + 32, r3);
                        }
                        r3 = LD32(r6);
                        r2 = LD32(r8 + 32);
                    }
                    r1 = LD32(r3 + 36);
                    if (!(r2 > r1)) {
                        r0 = 1;
                    } else {
                        ST32(r3 + 36, r2);
                        r0 = 1;
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
int f0602B1B8(int r4, int r5, int r6)
{
    int r0, r2, r8, r9, r10, r11, r12, r13;

    r13 = r4;
    r11 = r5;
    r10 = LD32(0x060769C8);
    r12 = r6;
    if ((r10 & r10) == 0) {
        r0 = 0;
    } else {
        r8 = r13;
        r2 = LD32((r12 + 72));
        r9 = r11;
        if (!(r2 > 1)) {
            r2 = LD32((r12 + 68));
            r0 = 1;
            if (!(r2 > 1)) {
                ST32(r13 + 32, r0);
                ST32(r11 + 24, r0);
                ST32(r8 + 36, r0);
                ST32(r9 + 28, r0);
            } else {
                r5 = LD32(r11 + 20);
                r0 = GCALL2(0x0602AAE4, r10, ((r5 + r2) - 1));
                r9 = r0;
                r0 = 1;
                if (!((r9 & r9) == 0)) {
                    ST32(r13 + 32, r0);
                    ST32(r11 + 24, r0);
                    ST32(r8 + 36, r0);
                    ST32(r9 + 28, r0);
                } else {
                    r0 = 0;
                }
            }
        } else {
            r5 = LD32(r8 + 12);
            r0 = GCALL2(0x0602AAC4, r10, ((r5 + r2) - 1));
            r8 = r0;
            r0 = 0;
            if (!((r8 & r8) == 0)) {
                r2 = LD32((r12 + 68));
                r0 = 1;
                if (!(r2 > 1)) {
                    ST32(r13 + 32, r0);
                    ST32(r11 + 24, r0);
                    ST32(r8 + 36, r0);
                    ST32(r9 + 28, r0);
                } else {
                    r5 = LD32(r11 + 20);
                    r0 = GCALL2(0x0602AAE4, r10, ((r5 + r2) - 1));
                    r9 = r0;
                    r0 = 1;
                    if (!((r9 & r9) == 0)) {
                        ST32(r13 + 32, r0);
                        ST32(r11 + 24, r0);
                        ST32(r8 + 36, r0);
                        ST32(r9 + 28, r0);
                    } else {
                        r0 = 0;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B4E0(void)
{
    int r1, r2, r3, r4, r5, r6, r7;

    r5 = LD32(0x060769C8);
    r1 = r5;
    if (!((r5 & r5) == 0)) {
        r6 = LD32((r1 + 96));
        r2 = LD32((r5 + 92));
        if (r2 > 0) {
            r6 = r6 + 2;
        }
        r1 = LD32(r5);
        r7 = 0;
        r3 = LD32(r5 + 40);
        r2 = r2 + r1;
        if (!((r3 & r3) == 0)) {
            r4 = r5 + 100;
            do {
                r1 = LD32(r3 + 32);
                ST32(r3 + 4, r2);
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r4);
                    ST32(r3 + 4, ((r1 + r6) + r2));
                }
                r1 = LD32(r3 + 4);
                r2 = LD32(r3 + 16);
                r1 = r1 + r2;
                ST32(r3 + 8, r1);
                r2 = r1;
                r1 = LD32(r3 + 36);
                if (!((r1 & r1) == 0)) {
                    r2 = r2 + r6;
                }
                r7 = r3;
                r3 = LD32(r7 + 44);
            } while (AGAIN(!((r3 & r3) == 0)));
        }
        r2 = r5;
        if (!((r7 & r7) == 0)) {
            r3 = LD32(0x060769C8);
            r1 = LD32(r7 + 8);
            r2 = LD32((r2 + 100));
            r1 = (r1 + r6) + r2;
            r2 = LD32((r5 + 92));
            ST32(r3 + 8, (r1 + r2));
        }
        return 1;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B560(void)
{
    int r0, r1, r2, r4, r5, r8, r9, r10;

    r10 = 0x060769C8;
    r4 = LD32(0x060769C8);
    r1 = r4;
    if ((r4 & r4) == 0) {
        r0 = 0;
    } else {
        r8 = LD32((r1 + 76));
        r0 = 0;
        if (!((r8 & r8) == 0)) {
            r9 = 0x0602AAC4;
            r5 = LD32(r8 + 48);
            r0 = GCALL2(0x0602AAC4, r4, r5);
            r2 = r0;
            if ((r2 & r2) == 0) {
                r0 = 0;
            } else {
                r1 = LD32(r2 + 4);
                ST32(r8 + 4, r1);
                r1 = LD32((r8 + 72));
                if (!(r1 == 1)) {
                    r5 = LD32(r8 + 48);
                    r4 = LD32(r10);
                    r0 = GCALL2(r9, r4, ((r5 + r1) - 1));
                    r2 = r0;
                    r0 = 1;
                    if (!((r2 & r2) == 0)) {
                        r1 = LD32(r2 + 8);
                        ST32(r8 + 8, r1);
                    } else {
                        r1 = LD32(r8 + 4);
                        r0 = 0;
                        ST32(r8 + 8, r1);
                    }
                } else {
                    r1 = LD32(r2 + 8);
                    ST32(r8 + 8, r1);
                    r0 = 0;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B7C0(void)
{
    int r1, r2, r3, r4, r5, r6, r7;

    r5 = LD32(0x060769C8);
    r1 = r5;
    if (!((r5 & r5) == 0)) {
        r6 = LD32((r1 + 96));
        r2 = LD32((r5 + 92));
        if (r2 > 0) {
            r6 = r6 + 2;
        }
        r1 = LD32(r5 + 4);
        r7 = 0;
        r3 = LD32(r5 + 56);
        r2 = r2 + r1;
        if (!((r3 & r3) == 0)) {
            r4 = r5 + 100;
            do {
                r1 = LD32(r3 + 24);
                ST32(r3, r2);
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r4);
                    ST32(r3, ((r1 + r6) + r2));
                }
                r1 = LD32(r3);
                r2 = LD32(r3 + 8);
                r1 = r1 + r2;
                ST32(r3 + 4, r1);
                r2 = r1;
                r1 = LD32(r3 + 28);
                if (!((r1 & r1) == 0)) {
                    r2 = r2 + r6;
                }
                r7 = r3;
                r3 = LD32(r7 + 52);
            } while (AGAIN(!((r3 & r3) == 0)));
        }
        r2 = r5;
        if (!((r7 & r7) == 0)) {
            r3 = LD32(0x060769C8);
            r1 = LD32(r7 + 4);
            r2 = LD32((r2 + 100));
            r1 = (r1 + r6) + r2;
            r2 = LD32((r5 + 92));
            ST32(r3 + 12, (r1 + r2));
        }
        return 1;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B840(void)
{
    int r0, r1, r2, r4, r5, r8, r9, r10;

    r10 = 0x060769C8;
    r4 = LD32(0x060769C8);
    r1 = r4;
    if ((r4 & r4) == 0) {
        r0 = 0;
    } else {
        r8 = LD32((r1 + 76));
        r0 = 0;
        if (!((r8 & r8) == 0)) {
            r9 = 0x0602AAE4;
            r5 = LD32(r8 + 52);
            r0 = GCALL2(0x0602AAE4, r4, r5);
            r2 = r0;
            if ((r2 & r2) == 0) {
                r0 = 0;
            } else {
                r1 = LD32(r2);
                ST32(r8 + 12, r1);
                r1 = LD32((r8 + 68));
                if (!(r1 == 1)) {
                    r5 = LD32(r8 + 52);
                    r4 = LD32(r10);
                    r0 = GCALL2(r9, r4, ((r5 + r1) - 1));
                    r2 = r0;
                    r0 = 1;
                    if (!((r2 & r2) == 0)) {
                        r1 = LD32(r2 + 4);
                        ST32(r8 + 16, r1);
                    } else {
                        r1 = LD32(r8 + 12);
                        r0 = 0;
                        ST32(r8 + 16, r1);
                    }
                } else {
                    r1 = LD32(r2 + 4);
                    ST32(r8 + 16, r1);
                    r0 = 0;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602BA00(int r4)
{
    int r0, r1, r2, r3, r6, r7, r8;

    r6 = 0x0608ACB8;
    r2 = LD32(0x0608ACB8);
    r3 = 0;
    if (!((r2 & r2) == 0)) {
        r7 = 0x0608ACB0;
        r1 = LD32(0x0608ACB0);
        r8 = LD32(r2);
        while (1) {
            r0 = r3;
            if (!(r3 >= (r1 - 1))) {
                POLL();
                r0 = r0 << 2;
                r2 = LD32(r6);
                r1 = LD32((r0 + r2) + 4);
                ST32(r0 + r2, r1);
                r1 = LD32(r7);
                r3 = r3 + 1;
                continue;
            } else {
                break;
            }
        }
        r2 = LD32(0x0608ACB8);
        ST32((r3 << 2) + r2, r8);
        r0 = GCALL3(0x060750A0, r8, r4, 49);
        ST8((r8 + 49), 0);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602BF00(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c1;
    FRAME(sp, 80);

    r10 = r4;
    r3 = LD32(76 + (sp - 76));
    r11 = r5;
    r1 = LD32(80 + (sp - 76));
    r2 = LD32(84 + (sp - 76));
    ST32(sp - 60, ((short)r6));
    r6 = r1 & 0xFFFF;
    r12 = (short)r6;
    if ((r7 & r7) == 0) {
        ST32(sp - 56, 12);
        ST32(sp - 52, 28);
        ST32(sp - 48, (-r2));
        ST32(sp - 44, r2);
    } else {
        ST32(sp - 56, 28);
        ST32(sp - 52, 12);
        ST32(sp - 44, (-r2));
        r0 = LD32(sp - 44);
        ST32(sp - 48, r0);
    }
    c1 = (r3 & r3) == 0;
    r3 = r10;
    if (!(c1)) {
        r7 = r10 + 4;
        r1 = LD16(r3);
        r3 = r3 + 2;
        ST16(sp - 76, r1);
        r1 = LD16(r3);
        ST16((sp - 74), r1);
        r1 = LD16(r7);
        ST16((sp - 72), r1);
        r1 = LD16(r3);
        ST16((sp - 70), r1);
        r1 = LD16(r7);
        r3 = r10 + 6;
        ST16((sp - 68), r1);
        r1 = LD16(r3);
        ST16((sp - 66), r1);
        r1 = LD16(r10);
        ST16((sp - 64), r1);
        r1 = LD16(r3);
        ST16((sp - 62), r1);
        r0 = LD32(sp - 60);
        ST32((sp - 80), 0xFFFF);
        r0 = GCALL6(0x06068D14, 0, 192, (((r0 | r6) | 18) & 0xFFFF), (sp - 76), LD32((sp - 80)), LD32((sp - 76)));
    }
    r2 = r10;
    r5 = (sp - 76) + 2;
    r1 = LD16(r2);
    r2 = r2 + 2;
    r7 = r10 + 4;
    ST16(sp - 76, r1);
    r1 = LD16(r2);
    ST16(r5, r1);
    r1 = LD16(r7);
    r6 = (sp - 76) + 6;
    ST16((sp - 72), r1);
    r1 = LD16(r2);
    ST16(r6, r1);
    r1 = LD16(r7);
    ST16((sp - 68), r1);
    r7 = (sp - 76) + 10;
    r1 = LD16(r2);
    ST16(r7, r1);
    r1 = LD16(r10);
    ST16((sp - 64), r1);
    r1 = LD16(r2);
    ST16((sp - 62), r1);
    r8 = LD32(sp - 60);
    r9 = 0;
    r0 = LD32(sp - 56);
    r8 = r8 | r0;
    if (!(0 > r11)) {
        ST32(sp - 40, r5);
        r14 = r6;
        r13 = r7;
        r2 = sp - 76;
        do {
            r1 = LD16((r10 + 2));
            r1 = r1 - r9;
            ST16((r2 + 14), r1);
            ST16(r13, r1);
            ST16(r14, r1);
            r0 = LD32(sp - 40);
            ST16(r0, r1);
            ST32((sp - 80), 0xFFFF);
            r0 = GCALL6(0x06068D14, 0, 192, ((r12 | r8) & 0xFFFF), (sp - 76), LD32((sp - 80)), LD32((sp - 76)));
            r1 = LD16((4 + (sp - 80)));
            r2 = (sp - 80) + 16;
            ST16(4 + (sp - 80), (r1 - 1));
            r1 = LD16(r2);
            ST16(r2, (r1 - 1));
            r2 = (sp - 80) + 8;
            r1 = LD16(r2);
            ST16(r2, (r1 + 1));
            r2 = (sp - 80) + 12;
            r1 = LD16(r2);
            ST16(r2, (r1 + 1));
            r1 = LD32(sp - 48);
            r8 = (short)(r1 + r8);
            if (r8 >= 0) {
                r1 = 31;
                if (r8 > 31) {
                    r8 = r1;
                }
            } else {
                r8 = 0;
            }
            r9 = r9 + 1;
            r2 = sp - 76;
        } while (AGAIN(!(r9 > r11)));
    }
    r5 = (sp - 76) + 2;
    r7 = r10 + 4;
    r3 = r10 + 6;
    r1 = LD16(r10);
    ST16(sp - 76, r1);
    r1 = LD16(r3);
    ST16(r5, r1);
    r1 = LD16(r7);
    r6 = (sp - 76) + 6;
    ST16((sp - 72), r1);
    r1 = LD16(r3);
    ST16(r6, r1);
    r1 = LD16(r7);
    ST16((sp - 68), r1);
    r7 = (sp - 76) + 10;
    r1 = LD16(r3);
    ST16(r7, r1);
    r1 = LD16(r10);
    ST16((sp - 64), r1);
    r1 = LD16(r3);
    ST16((sp - 62), r1);
    r8 = LD32(sp - 60);
    r9 = 0;
    r0 = LD32(sp - 52);
    r8 = r8 | r0;
    if (!(0 > r11)) {
        ST32(sp - 36, r5);
        r14 = r6;
        r13 = r7;
        r2 = sp - 76;
        do {
            r1 = LD16((r10 + 6));
            r1 = r1 + r9;
            ST16((r2 + 14), r1);
            ST16(r13, r1);
            ST16(r14, r1);
            r0 = LD32(sp - 36);
            ST16(r0, r1);
            ST32((sp - 80), 0xFFFF);
            r0 = GCALL6(0x06068D14, 0, 192, ((r12 | r8) & 0xFFFF), (sp - 76), LD32((sp - 80)), LD32((sp - 76)));
            r1 = LD16((4 + (sp - 80)));
            r2 = (sp - 80) + 16;
            ST16(4 + (sp - 80), (r1 - 1));
            r1 = LD16(r2);
            ST16(r2, (r1 - 1));
            r2 = (sp - 80) + 8;
            r1 = LD16(r2);
            ST16(r2, (r1 + 1));
            r2 = (sp - 80) + 12;
            r1 = LD16(r2);
            ST16(r2, (r1 + 1));
            r1 = LD32(sp - 44);
            r8 = (short)(r1 + r8);
            if (r8 >= 0) {
                r1 = 31;
                if (r8 > 31) {
                    r8 = r1;
                }
            } else {
                r8 = 0;
            }
            r9 = r9 + 1;
            r2 = sp - 76;
        } while (AGAIN(!(r9 > r11)));
    }
    r2 = r10;
    r6 = (sp - 76) + 4;
    r1 = LD16(r2);
    r2 = r2 + 2;
    ST16(sp - 76, r1);
    r1 = LD16(r2);
    r7 = (sp - 76) + 8;
    ST16((sp - 74), r1);
    r1 = LD16(r10);
    ST16(r6, r1);
    r1 = LD16(r2);
    ST16((sp - 70), r1);
    r1 = LD16(r10);
    r3 = r10 + 6;
    ST16(r7, r1);
    r1 = LD16(r3);
    ST16((sp - 66), (r1 - 1));
    r1 = LD16(r10);
    ST16((sp - 64), r1);
    r1 = LD16(r3);
    ST16((sp - 62), (r1 - 1));
    r8 = LD32(sp - 60);
    r9 = 0;
    r0 = LD32(sp - 56);
    r8 = r8 | r0;
    if (!(0 > r11)) {
        r14 = r6;
        r13 = r7;
        r2 = sp - 76;
        do {
            r1 = LD16(r10);
            r1 = r1 - r9;
            ST16((r2 + 12), r1);
            ST16(r13, r1);
            ST16(r14, r1);
            ST16(sp - 76, r1);
            ST32((sp - 80), 0xFFFF);
            r0 = GCALL6(0x06068D14, 0, 192, ((r12 | r8) & 0xFFFF), (sp - 76), LD32((sp - 80)), LD32((sp - 76)));
            r2 = (sp - 80) + 6;
            r1 = LD16(r2);
            ST16(r2, (r1 - 1));
            r2 = (sp - 80) + 10;
            r1 = LD16(r2);
            ST16(r2, (r1 - 1));
            r2 = (sp - 80) + 14;
            r1 = LD16(r2);
            ST16(r2, (r1 + 1));
            r2 = (sp - 80) + 18;
            r1 = LD16(r2);
            ST16(r2, (r1 + 1));
            r1 = LD32(sp - 48);
            r8 = (short)(r1 + r8);
            if (r8 >= 0) {
                r1 = 31;
                if (r8 > 31) {
                    r8 = r1;
                }
            } else {
                r8 = 0;
            }
            r9 = r9 + 1;
            r2 = sp - 76;
        } while (AGAIN(!(r9 > r11)));
    }
    r3 = r10 + 4;
    r7 = r10 + 2;
    r5 = (sp - 76) + 4;
    r1 = LD16(r3);
    ST16(sp - 76, r1);
    r1 = LD16(r7);
    r6 = (sp - 76) + 8;
    ST16((sp - 74), (r1 + 1));
    r1 = LD16(r3);
    ST16(r5, r1);
    r1 = LD16(r7);
    ST16((sp - 70), (r1 + 1));
    r1 = LD16(r3);
    r7 = r10 + 6;
    ST16(r6, r1);
    r1 = LD16(r7);
    ST16((sp - 66), r1);
    r1 = LD16(r3);
    ST16((sp - 64), r1);
    r1 = LD16(r7);
    ST16((sp - 62), r1);
    r8 = LD32(sp - 60);
    r9 = 0;
    r0 = LD32(sp - 52);
    r8 = r8 | r0;
    if (!(0 > r11)) {
        r14 = r5;
        r13 = r6;
        r2 = sp - 76;
        do {
            r1 = LD16((r10 + 4));
            r1 = r1 + r9;
            ST16((r2 + 12), r1);
            ST16(r13, r1);
            ST16(r14, r1);
            ST16(sp - 76, r1);
            ST32((sp - 80), 0xFFFF);
            r0 = GCALL6(0x06068D14, 0, 192, ((r12 | r8) & 0xFFFF), (sp - 76), LD32((sp - 80)), LD32((sp - 76)));
            r2 = (sp - 80) + 6;
            r1 = LD16(r2);
            ST16(r2, (r1 - 1));
            r2 = (sp - 80) + 10;
            r1 = LD16(r2);
            ST16(r2, (r1 - 1));
            r2 = (sp - 80) + 14;
            r1 = LD16(r2);
            ST16(r2, (r1 + 1));
            r2 = (sp - 80) + 18;
            r1 = LD16(r2);
            ST16(r2, (r1 + 1));
            r1 = LD32(sp - 44);
            r8 = (short)(r1 + r8);
            if (r8 >= 0) {
                r1 = 31;
                if (r8 > 31) {
                    r8 = r1;
                }
            } else {
                r8 = 0;
            }
            r9 = r9 + 1;
            r2 = sp - 76;
        } while (AGAIN(!(r9 > r11)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602C62C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r12, r13;
    FRAME(sp, 28);

    r13 = r4;
    r12 = r5;
    r9 = r6;
    r10 = r7;
    r8 = LD32(sp);
    r0 = GCALL2(0x060689BC, 0, r8);
    r1 = LD16((r8 + 4));
    ST32((sp - 32), (r1 - r9));
    r0 = GCALL5(0x06022690, r13, r12, r9, r10, LD32((sp - 32)));
    r0 = GCALL5(0x060689BC, 0, 0x06075A00, 0, 0, LD32((sp - 32)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602C684(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 68);

    r8 = r4;
    r11 = r8;
    r2 = (sp - 64) + 2;
    r10 = r8 + 4;
    r12 = (sp - 64) + 6;
    r9 = r8 + 6;
    r1 = LD16(r11);
    r11 = r11 + 2;
    ST16(sp - 64, r1);
    ST32(sp - 48, r2);
    r1 = LD16(r11);
    r13 = (sp - 64) + 12;
    ST16(r2, r1);
    r2 = (sp - 64) + 4;
    ST32(sp - 44, r2);
    r1 = LD16(r10);
    ST16(r2, r1);
    r1 = LD16(r11);
    r2 = (sp - 64) + 8;
    ST16(r12, r1);
    ST32(sp - 40, r2);
    r1 = LD16(r10);
    r14 = (sp - 64) + 14;
    ST16(r2, r1);
    r2 = (sp - 64) + 10;
    ST32(sp - 36, r2);
    r1 = LD16(r9);
    ST16(r2, r1);
    r1 = LD16(r8);
    ST16(r13, r1);
    r1 = LD16(r9);
    ST16(r14, r1);
    ST32((sp - 68), 0xFFFF);
    r0 = GCALL6(0x06068D14, 0, 192, (r5 & 255), (sp - 64), LD32((sp - 68)), LD32((sp - 64)));
    r1 = LD16(r8);
    ST16((4 + (sp - 68)), (r1 + 1));
    r1 = LD16(r9);
    r2 = LD32(sp - 48);
    ST16(r2, (r1 + 1));
    r1 = LD16(r10);
    r2 = LD32(sp - 44);
    ST16(r2, (r1 + 1));
    r1 = LD16(r9);
    ST16(r12, (r1 + 1));
    r1 = LD16(r10);
    r2 = LD32(sp - 40);
    ST16(r2, (r1 + 1));
    r1 = LD16(r9);
    r2 = LD32(sp - 36);
    ST16(r2, (r1 + 2));
    r1 = LD16(r8);
    ST16(r13, (r1 + 1));
    r1 = LD16(r9);
    ST16(r14, (r1 + 2));
    ST32((sp - 72), 0xFFFF);
    r0 = GCALL7(0x06068D14, 0, 192, 4, (sp - 64), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
    r1 = LD16(r10);
    ST16((8 + (sp - 72)), (r1 + 1));
    r1 = LD16(r11);
    r2 = LD32(sp - 48);
    ST16(r2, (r1 + 1));
    r1 = LD16(r10);
    r2 = LD32(sp - 44);
    ST16(r2, (r1 + 2));
    r1 = LD16(r11);
    ST16(r12, (r1 + 1));
    r1 = LD16(r10);
    r2 = LD32(sp - 40);
    ST16(r2, (r1 + 2));
    r1 = LD16(r9);
    r2 = LD32(sp - 36);
    ST16(r2, (r1 + 1));
    r1 = LD16(r10);
    ST16(r13, (r1 + 1));
    r1 = LD16(r9);
    ST16(r14, (r1 + 1));
    ST32((sp - 76), 0xFFFF);
    r0 = GCALL8(0x06068D14, 0, 192, 4, (sp - 64), LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602C7B8(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 72);

    r11 = r4;
    r13 = r5 & 255;
    r10 = r11;
    r2 = (sp - 68) + 2;
    r9 = r11 + 4;
    r1 = LD16(r10);
    r10 = r10 + 2;
    ST16(sp - 68, r1);
    ST32(sp - 52, r2);
    r1 = LD16(r10);
    r12 = (sp - 68) + 12;
    ST16(r2, r1);
    r2 = (sp - 68) + 4;
    ST32(sp - 48, r2);
    r1 = LD16(r9);
    ST16(r2, r1);
    r2 = (sp - 68) + 6;
    ST32(sp - 44, r2);
    r1 = LD16(r10);
    r14 = (sp - 68) + 14;
    ST16(r2, r1);
    r2 = (sp - 68) + 8;
    ST32(sp - 40, r2);
    r1 = LD16(r9);
    ST16(r2, r1);
    r2 = (sp - 68) + 10;
    ST32(sp - 36, r2);
    r1 = LD16(r10);
    ST16(r2, (r1 + 1));
    r1 = LD16(r11);
    ST16(r12, r1);
    r1 = LD16(r10);
    ST16(r14, (r1 + 1));
    ST32((sp - 72), 0xFFFF);
    r0 = GCALL6(0x06068D14, 0, 192, r13, (sp - 68), LD32((sp - 72)), LD32((sp - 68)));
    r1 = LD16(r9);
    ST16((4 + (sp - 72)), (r1 - 1));
    r1 = LD16(r10);
    r2 = LD32(sp - 52);
    ST16(r2, r1);
    r1 = LD16(r9);
    r2 = LD32(sp - 48);
    ST16(r2, r1);
    r1 = LD16(r10);
    r2 = LD32(sp - 44);
    ST16(r2, r1);
    r1 = LD16(r9);
    r2 = LD32(sp - 40);
    r8 = r11 + 6;
    ST16(r2, r1);
    r1 = LD16(r8);
    r2 = LD32(sp - 36);
    ST16(r2, r1);
    r1 = LD16(r9);
    ST16(r12, (r1 - 1));
    r1 = LD16(r8);
    ST16(r14, r1);
    ST32((sp - 76), 0xFFFF);
    r0 = GCALL7(0x06068D14, 0, 192, r13, (sp - 68), LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)));
    r1 = LD16(r11);
    ST16((8 + (sp - 76)), r1);
    r1 = LD16(r8);
    r2 = LD32(sp - 52);
    ST16(r2, (r1 - 1));
    r1 = LD16(r9);
    r2 = LD32(sp - 48);
    ST16(r2, r1);
    r1 = LD16(r8);
    r2 = LD32(sp - 44);
    ST16(r2, (r1 - 1));
    r1 = LD16(r9);
    r2 = LD32(sp - 40);
    ST16(r2, r1);
    r1 = LD16(r8);
    r2 = LD32(sp - 36);
    ST16(r2, r1);
    r1 = LD16(r11);
    ST16(r12, r1);
    r1 = LD16(r8);
    ST16(r14, r1);
    ST32((sp - 80), 0xFFFF);
    r0 = GCALL8(0x06068D14, 0, 192, r13, (sp - 68), LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)));
    r1 = LD16(r11);
    ST16((12 + (sp - 80)), r1);
    r1 = LD16(r10);
    r2 = LD32(sp - 52);
    ST16(r2, r1);
    r1 = LD16(r11);
    r2 = LD32(sp - 48);
    ST16(r2, (r1 + 1));
    r1 = LD16(r10);
    r2 = LD32(sp - 44);
    ST16(r2, r1);
    r1 = LD16(r11);
    r2 = LD32(sp - 40);
    ST16(r2, (r1 + 1));
    r1 = LD16(r8);
    r2 = LD32(sp - 36);
    ST16(r2, r1);
    r1 = LD16(r11);
    ST16(r12, r1);
    r1 = LD16(r8);
    ST16(r14, r1);
    ST32((sp - 84), 0xFFFF);
    r0 = GCALL8(0x06068D14, 0, 192, r13, (sp - 68), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602C924(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 68);

    r9 = r4;
    ST32(sp - 48, r5);
    r8 = r9;
    r3 = (sp - 64) + 2;
    r2 = r9 + 4;
    r12 = (sp - 64) + 6;
    r11 = (sp - 64) + 8;
    r10 = (sp - 64) + 10;
    r0 = LD8((19 + (sp - 64)));
    r14 = (sp - 64) + 12;
    ST32(sp - 44, (r0 & 255));
    r1 = LD16(r8);
    r8 = r8 + 2;
    ST16(sp - 64, r1);
    ST32(sp - 40, r3);
    r1 = LD16(r8);
    r0 = (sp - 64) + 4;
    ST16(r3, r1);
    ST32(sp - 36, r0);
    r1 = LD16(r2);
    ST16(r0, r1);
    r1 = LD16(r8);
    r13 = (sp - 64) + 14;
    ST16(r12, r1);
    r1 = LD16(r2);
    ST16(r11, r1);
    r1 = LD16(r8);
    ST16(r10, (r1 + 1));
    r1 = LD16(r9);
    ST16(r14, r1);
    r1 = LD16(r8);
    ST16(r13, (r1 + 1));
    ST32((sp - 68), 0xFFFF);
    r6 = LD32(sp - 44);
    r0 = GCALL6(0x06068D14, 0, 192, r6, (sp - 64), LD32((sp - 68)), LD32((sp - 64)));
    r1 = LD16(r9);
    ST16((4 + (sp - 68)), r1);
    r1 = LD16(r8);
    r0 = LD32(sp - 40);
    ST16(r0, r1);
    r1 = LD16(r9);
    r3 = LD32(sp - 36);
    ST16(r3, (r1 + 1));
    r1 = LD16(r8);
    r2 = r9 + 6;
    ST16(r12, r1);
    r1 = LD16(r9);
    ST16(r11, (r1 + 1));
    r1 = LD16(r2);
    ST16(r10, r1);
    r1 = LD16(r9);
    ST16(r14, r1);
    r1 = LD16(r2);
    ST16(r13, r1);
    ST32((sp - 72), 0xFFFF);
    r6 = LD32(sp - 44);
    r0 = GCALL7(0x06068D14, 0, 192, r6, (sp - 64), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602CA04(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 72);

    r10 = r4;
    ST32(sp - 52, r5);
    r9 = r10 + 4;
    r3 = (sp - 68) + 2;
    r2 = r10 + 2;
    r11 = (sp - 68) + 8;
    r12 = (sp - 68) + 10;
    r8 = r10 + 6;
    r14 = (sp - 68) + 12;
    r0 = LD8((19 + (sp - 68)));
    ST32(sp - 48, (r0 & 255));
    r1 = LD16(r9);
    ST16(sp - 68, (r1 - 1));
    ST32(sp - 44, r3);
    r1 = LD16(r2);
    r0 = (sp - 68) + 4;
    ST16(r3, (r1 + 1));
    ST32(sp - 40, r0);
    r1 = LD16(r9);
    r3 = (sp - 68) + 6;
    ST16(r0, r1);
    ST32(sp - 36, r3);
    r1 = LD16(r2);
    r13 = (sp - 68) + 14;
    ST16(r3, (r1 + 1));
    r1 = LD16(r9);
    ST16(r11, r1);
    r1 = LD16(r8);
    ST16(r12, r1);
    r1 = LD16(r9);
    ST16(r14, (r1 - 1));
    r1 = LD16(r8);
    ST16(r13, r1);
    ST32((sp - 72), 0xFFFF);
    r6 = LD32(sp - 48);
    r0 = GCALL6(0x06068D14, 0, 192, r6, (sp - 68), LD32((sp - 72)), LD32((sp - 68)));
    r1 = LD16(r10);
    ST16((4 + (sp - 72)), (r1 + 2));
    r1 = LD16(r8);
    r3 = LD32(sp - 44);
    ST16(r3, (r1 - 1));
    r1 = LD16(r9);
    r0 = LD32(sp - 40);
    ST16(r0, r1);
    r1 = LD16(r8);
    r3 = LD32(sp - 36);
    ST16(r3, (r1 - 1));
    r1 = LD16(r9);
    ST16(r11, r1);
    r1 = LD16(r8);
    ST16(r12, r1);
    r1 = LD16(r10);
    ST16(r14, (r1 + 2));
    r1 = LD16(r8);
    ST16(r13, r1);
    ST32((sp - 76), 0xFFFF);
    r6 = LD32(sp - 48);
    r0 = GCALL7(0x06068D14, 0, 192, r6, (sp - 68), LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602E2A4(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;

    r13 = r4;
    r11 = r5;
    if (r6 >= 0) {
        r3 = 0x0608BCFC;
        r1 = LD32(0x0608BCFC);
        r2 = r11 - 8;
        r1 = r1 + 1;
        ST32(0x0608BCFC, r1);
        if (!(r1 > r2)) {
            r8 = 0;
            r12 = 0x0608AF60;
            r14 = 0x060750DC;
            r10 = 0x0608AF60;
            r9 = 0;
            do {
                r1 = LD32(0x0608BCFC);
                r1 = r1 + r8;
                r0 = r1;
                if (!(r1 >= r11)) {
                    r5 = LD32((r0 << 2) + r13);
                    r0 = GCALL2(r14, r10, r5);
                } else {
                    ST8(r9 + r12, 0);
                }
                r10 = r10 + 0x100;
                r9 = r9 + 0x100;
                r8 = r8 + 1;
            } while (AGAIN(!(r8 > 7)));
            r0 = GCALL1(0x06032164, 12);
        } else {
            ST32(r3, r2);
            if (!(r2 >= 0)) {
                ST32(r3, 0);
            }
        }
    } else {
        r2 = 0x0608BCFC;
        r1 = LD32(0x0608BCFC);
        r1 = r1 - 1;
        ST32(0x0608BCFC, r1);
        if (r1 >= 0) {
            r8 = 0;
            r12 = 0x0608AF60;
            r14 = 0x060750DC;
            r10 = 0x0608AF60;
            r9 = 0;
            while (1) {
                r1 = LD32(0x0608BCFC);
                r1 = r1 + r8;
                r0 = r1;
                if (!(r1 >= r11)) {
                    r5 = LD32((r0 << 2) + r13);
                    r0 = GCALL2(r14, r10, r5);
                } else {
                    ST8(r9 + r12, 0);
                }
                r10 = r10 + 0x100;
                r9 = r9 + 0x100;
                r8 = r8 + 1;
                if (r8 > 7) {
                    break;
                }
                POLL();
            }
            r0 = GCALL1(0x06032164, 12);
        } else {
            ST32(r2, 0);
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602E488(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, c1;

    r2 = r6;
    r1 = LD8(0x0608AF56);
    r6 = 5;
    if (!((r1 & r1) == 0)) {
        r6 = 8;
    }
    c1 = r2 >= 0;
    r2 = r5;
    if (c1) {
        r3 = 0x0608BCFC;
        r1 = LD32(0x0608BCFC);
        r2 = r2 - r6;
        r1 = r1 + 1;
        ST32(0x0608BCFC, r1);
        if (!(r1 > r2)) {
            r0 = GCALL3(0x0602E380, r4, r5, r6);
        } else {
            ST32(r3, r2);
            if (!(r2 >= 0)) {
                ST32(r3, 0);
            }
        }
    } else {
        r2 = 0x0608BCFC;
        r1 = LD32(0x0608BCFC);
        r1 = r1 - 1;
        ST32(0x0608BCFC, r1);
        if (r1 >= 0) {
            r0 = GCALL3(0x0602E380, r4, r5, r6);
        } else {
            ST32(r2, 0);
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602E4E4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;

    r2 = 0x060769D4;
    r1 = LD32(0x060769D4);
    r0 = LD32(r1);
    r6 = r4;
    if (!(r0 == 3)) {
        r1 = LD32(r2);
        r0 = LD32(r1);
        if (!(r0 == 4)) {
            r1 = LD32(r2);
            r0 = LD32(r1);
            if (r0 == 25) {
                r0 = GCALL1(0x0604911C, r6);
            }
            return r0;
        } else {
            r1 = 0x0608BD04;
            r5 = LD32(0x0608BD04);
            r4 = LD32(r1 + 4);
            r0 = GCALL4(0x0602E2A4, r4, r5, r6, r7);
            return r0;
        }
    } else {
        r1 = 0x0608BCF4;
        r5 = LD32(0x0608BCF4);
        r4 = LD32(r1 + 4);
        r0 = GCALL4(0x0602E2A4, r4, r5, r6, r7);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602F1FC(int r4)
{
    int r1;

    ST32(r4, 16);
    ST32(r4 + 4, 150);
    r1 = LD32(r4);
    ST32(r4 + 8, (r1 + 0x120));
    r1 = LD32(r4 + 4);
    ST32(r4 + 12, (r1 + 80));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602F218(int r4, int r5)
{
    int r1, r2, r3, r6, r7, r8, r9;

    r7 = 0;
    r9 = 1;
    r6 = 0x0602EE4C;
    r8 = 58;
    r2 = 0x0602EE5C;
    r3 = 16;
    while (1) {
        r1 = LD32(r3 + r6);
        if (!(r4 >= r1)) {
            r2 = r2 + 16;
            r9 = r9 + 1;
            r3 = r3 + 16;
            if (!(r9 > r8)) {
                POLL();
                continue;
            } else {
                break;
            }
        } else {
            r1 = LD32(r2 + 8);
            if (r4 > r1) {
                r2 = r2 + 16;
                r9 = r9 + 1;
                r3 = r3 + 16;
                if (!(r9 > r8)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            } else {
                r1 = LD32(r2 + 4);
                if (!(r5 >= r1)) {
                    r2 = r2 + 16;
                    r9 = r9 + 1;
                    r3 = r3 + 16;
                    if (!(r9 > r8)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                } else {
                    r1 = LD32(r2 + 12);
                    r2 = r2 + 16;
                    if (r5 > r1) {
                        r9 = r9 + 1;
                        r3 = r3 + 16;
                        if (!(r9 > r8)) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        r7 = r9;
                        break;
                    }
                }
            }
        }
        POLL();
    }
    return r7;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602F630(int r4)
{
    int r0, r2;

    r4 = r4 & 255;
    r2 = r4;
    if ((unsigned)r4 > (unsigned)31) {
        if (!((unsigned)r4 > (unsigned)159)) {
            if (r4 == 128) {
                POLL();
                return 0;
            } else {
                if (r4 == 129) {
                    POLL();
                    return 0;
                } else {
                    r0 = 0;
                    if (!(r2 == 141)) {
                        POLL();
                        return 1;
                    } else {
                        return r0;
                    }
                }
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602F668(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7;

    r2 = r4 + 24;
    r3 = LD16(r2);
    r7 = LD32(r4 + 20);
    r0 = (short)r3;
    r1 = LD8(r0 + r7);
    r5 = r5 & 255;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        r0 = r0 + 1;
        do {
            r1 = LD8(r0 + r7);
            r0 = r0 + 1;
        } while (AGAIN(!(((r1 & 255) & (r1 & 255)) == 0)));
        r0 = r0 - 1;
        r6 = r4 + 24;
        r1 = LD16(r6);
        r2 = r4;
        if (r0 >= r1) {
            r3 = r0 + r7;
            do {
                r2 = LD8(r3);
                r0 = r0 - 1;
                ST8((r3 + 1), r2);
                r1 = LD16(r6);
                r3 = r3 - 1;
            } while (AGAIN(r0 >= r1));
            r2 = r4;
        }
        r2 = r2 + 24;
        r0 = LD16(r2);
        ST16(r2, (r0 + 1));
        ST8(r0 + r7, r5);
        return r0;
    } else {
        ST16(r2, (r3 + 1));
        ST8(r0 + r7, r5);
        r0 = LD16(r2);
        ST8(r0 + r7, 0);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602F6CC(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7;

    r7 = LD32(r4 + 20);
    r3 = LD16((r4 + 24));
    if ((r5 & r5) == 0) {
        if (!(r3 > 0)) {
            return;
        } else {
            r1 = LD8(0x0608AF53);
            r6 = r3;
            if ((r1 & r1) == 0) {
                r5 = r3;
                r3 = LD8(r7 + r5);
                r2 = r5;
                if (!(((r3 & 255) & (r3 & 255)) == 0)) {
                    r2 = r2 + r7;
                    do {
                        ST8((r2 - 1), r3);
                        r2 = r2 + 1;
                        r3 = LD8(r2);
                        r5 = r5 + 1;
                    } while (AGAIN(!(((r3 & 255) & (r3 & 255)) == 0)));
                }
                r1 = r5;
                r2 = LD8(r7 + r5);
                ST8(((r1 + r7) - 1), r2);
                r2 = r4 + 24;
                r1 = LD16(r2);
                ST16(r2, (r1 - 1));
                return;
            } else {
                r6 = r6 + r7;
                r1 = LD8((r6 - 2));
                r5 = r3;
                if (!((unsigned)(r1 & 255) > (unsigned)127)) {
                    r3 = LD8(r7 + r5);
                    r2 = r6;
                    if (((r3 & 255) & (r3 & 255)) == 0) {
                        r1 = r5;
                    } else {
                        do {
                            ST8((r2 - 1), r3);
                            r2 = r2 + 1;
                            r3 = LD8(r2);
                            r5 = r5 + 1;
                        } while (AGAIN(!(((r3 & 255) & (r3 & 255)) == 0)));
                        r1 = r5;
                    }
                    r2 = LD8(r7 + r5);
                    ST8(((r1 + r7) - 1), r2);
                    r2 = r4 + 24;
                    r1 = LD16(r2);
                    ST16(r2, (r1 - 1));
                    return;
                } else {
                    r2 = LD8(r7 + r5);
                    r3 = r6;
                    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                        do {
                            ST8((r3 - 2), r2);
                            r2 = r3 - 1;
                            r1 = LD8((r3 + 1));
                            r3 = r3 + 2;
                            ST8(r2, r1);
                            r2 = LD8(r3);
                            r5 = r5 + 2;
                        } while (AGAIN(!(((r2 & 255) & (r2 & 255)) == 0)));
                    }
                    r1 = r5 + r7;
                    r2 = LD8(r7 + r5);
                    ST8((r1 - 2), r2);
                    r2 = r1;
                    r1 = LD8((r1 + 1));
                    ST8((r2 - 1), r1);
                    r2 = r4 + 24;
                    r1 = LD16(r2);
                    ST16(r2, (r1 - 2));
                    return;
                }
            }
        }
    } else {
        r1 = r4;
        if (r3 > 0) {
            r2 = 0x06075135;
            r0 = r7;
            while (1) {
                r1 = LD8(r0 + r3);
                r1 = LD8((r1 & 255) + r2);
                if (!(((r1 & 8) & (r1 & 8)) == 0)) {
                    break;
                } else {
                    r3 = r3 - 1;
                    r0 = r7;
                    if (r3 > 0) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
            r1 = r4;
        }
        r1 = r1 + 24;
        r5 = LD16(r1);
        ST16(r1, r3);
        r2 = LD8(r7 + r5);
        while (1) {
            r0 = r7;
            if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                POLL();
                ST8(r0 + r3, r2);
                r5 = r5 + 1;
                r2 = LD8(r0 + r5);
                r3 = r3 + 1;
                continue;
            } else {
                break;
            }
        }
        r1 = LD8(r0 + r5);
        ST8(r0 + r3, r1);
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602FBCC(int r4)
{
    int r1;

    r1 = LD32(((r4 * 92) + 0x06087DD8));
    return (r1 & r1) == 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602316C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, c2;
    FRAME(sp, 28);

    r7 = LD32(0x060759B4);
    r8 = 0x060766C4;
    ST32(0x060766C4, 0);
    if (!((r4 & r4) == 0)) {
        r0 = LD32(r4 + 28);
        c2 = r0 == -1;
        if ((r0 & r0) == 0) {
            r3 = LD16((r4 + 4));
            r3 = r3 >> 1;
            ST16(sp - 16, r3);
            r2 = LD32(r4 + 16);
            r2 = (r2 - r7) >> 1;
            ST16((sp - 14), r2);
            r1 = LD16((r4 + 6));
            ST16((sp - 12), (r3 + (r1 >> 1)));
            r1 = LD32(r4 + 20);
            ST16((sp - 10), (r2 + (r1 >> 1)));
            r1 = LD32(r4 + 36);
            ST32(0x060766C4, r1);
            ST16(0x060766C8, -1);
            ST16(0x060766CA, -1);
            r3 = (sp - 16) + 4;
            r2 = LD32(0x060759CC);
            r1 = LD16(sp - 16);
            ST16(sp - 16, (r1 - ((r2 + ((int)((unsigned)r2 >> 31))) >> 1)));
            r2 = LD32(0x060759CC);
            r1 = LD16(r3);
            ST16(r3, (r1 - ((r2 + ((int)((unsigned)r2 >> 31))) >> 1)));
            ST32((sp - 20), 2);
            ST32((sp - 24), 0x260);
            ST32((sp - 28), 1);
            r0 = GCALL8(0x0602BF00, (sp - 16), 2, 0x1000, 1, LD32((sp - 28)), LD32((sp - 24)), LD32((sp - 20)), LD32((sp - 16)));
        } else {
            if (c2) {
                r3 = LD16((r4 + 4));
                r3 = r3 >> 1;
                ST16(sp - 16, r3);
                r2 = LD32(r4 + 16);
                r2 = (r2 - r7) >> 1;
                ST16((sp - 14), r2);
                r1 = LD16((r4 + 6));
                ST16((sp - 12), (r3 + (r1 >> 1)));
                r1 = LD32(r4 + 20);
                ST16((sp - 10), (r2 + (r1 >> 1)));
                r1 = LD32(r4 + 36);
                ST32(0x060766C4, r1);
                ST16(0x060766C8, -1);
                ST16(0x060766CA, -1);
                r3 = (sp - 16) + 4;
                r2 = LD32(0x060759CC);
                r1 = LD16(sp - 16);
                ST16(sp - 16, (r1 - ((r2 + ((int)((unsigned)r2 >> 31))) >> 1)));
                r2 = LD32(0x060759CC);
                r1 = LD16(r3);
                ST16(r3, (r1 - ((r2 + ((int)((unsigned)r2 >> 31))) >> 1)));
                ST32((sp - 20), 2);
                ST32((sp - 24), 0x260);
                ST32((sp - 28), 1);
                r0 = GCALL8(0x0602BF00, (sp - 16), 2, 0x1000, 1, LD32((sp - 28)), LD32((sp - 24)), LD32((sp - 20)), LD32((sp - 16)));
            } else {
                r3 = LD32(r4 + 32);
                r1 = r4;
                if (!((r3 & r3) == 0)) {
                    r2 = LD16((r1 + 4));
                    r1 = LD32(r3);
                    r5 = (r1 + r2) >> 1;
                    ST16(sp - 16, r5);
                    r1 = LD32(r4 + 32);
                    r2 = LD32(r4 + 16);
                    r1 = LD32(r1 + 4);
                    r6 = ((r1 + r2) - r7) >> 1;
                    ST16((sp - 14), r6);
                    r1 = LD32(r4 + 32);
                    r3 = LD32(r1 + 8);
                    r7 = LD32(r1 + 12);
                    r1 = LD16((r4 + 6));
                    if (r3 > r1) {
                        r3 = r1;
                    }
                    r1 = LD32(r4 + 20);
                    if (r7 > r1) {
                        r7 = r1;
                    }
                    ST16((sp - 12), ((r3 >> 1) + r5));
                    ST16((sp - 10), ((r7 >> 1) + r6));
                    r1 = LD32(r4 + 32);
                    r1 = LD32(r1 + 32);
                    ST32(r8, r1);
                    r1 = LD16((r4 + 8));
                    ST16(0x060766C8, r1);
                    r1 = LD32(r4 + 24);
                    ST16(0x060766CA, r1);
                    r3 = (sp - 16) + 4;
                    r2 = LD32(0x060759CC);
                    r1 = LD16(sp - 16);
                    ST16(sp - 16, (r1 - ((r2 + ((int)((unsigned)r2 >> 31))) >> 1)));
                    r2 = LD32(0x060759CC);
                    r1 = LD16(r3);
                    ST16(r3, (r1 - ((r2 + ((int)((unsigned)r2 >> 31))) >> 1)));
                    ST32((sp - 20), 2);
                    ST32((sp - 24), 0x260);
                    ST32((sp - 28), 1);
                    r0 = GCALL8(0x0602BF00, (sp - 16), 2, 0x1000, 1, LD32((sp - 28)), LD32((sp - 24)), LD32((sp - 20)), LD32((sp - 16)));
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060233A8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c9, c11, c12, c17, c19;
    FRAME(sp, 40);

    r9 = r4;
    r8 = r5;
    r11 = r6;
    r0 = LD32(0x0607668C);
    r10 = r7;
    if (r0 == 2) {
        r0 = 0;
    } else {
        r1 = LD8(0x0608AF56);
        r0 = 0;
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x0602F1FC, (sp - 40));
            r3 = LD32(sp - 40);
            r0 = 0;
            if (r9 >= (r3 + 8)) {
                r1 = LD32(sp - 32);
                r2 = LD32(sp - 36);
                if (!(r9 > (r1 - 8))) {
                    r1 = LD32(sp - 28);
                    if (r8 >= (r2 + 8)) {
                        r9 = r9 - r3;
                        if (!(r8 > (r1 - 8))) {
                            r0 = GCALL2(0x0602F218, r9, (r8 - r2));
                            r8 = r0;
                            r0 = 1;
                            if (r8 > 0) {
                                r0 = GCALL1(0x06032164, 9);
                                r0 = r8;
                                r1 = 16;
                                if (r0 == 16) {
                                    ST8(0x0607802E, r8);
                                    ST8(0x0607802F, 3);
                                    r1 = LD32(0x06078024);
                                    r1 = LD16((r1 + 24));
                                    c12 = r1 >= 0;
                                    r1 = (signed char)r8;
                                    if (c12) {
                                        r3 = LD32((r1 << 2) + 0x06076860);
                                        r3 = ((r3 & 255) - ((int)((((long long)((unsigned long long)(unsigned)(r3 & 255) * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)(r3 & 255) * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                        r1 = LD8(r3 + 0x06075A74);
                                        r7 = LD16(r11);
                                        r8 = r1 & 255;
                                        if (!(((64 & r7) & (64 & r7)) == 0)) {
                                            if (((r7 & 1) & (r7 & 1)) == 0) {
                                                r0 = LD8(r10);
                                                c17 = ((r0 & 1) & (r0 & 1)) == 0;
                                                r0 = r3;
                                                if (c17) {
                                                    r1 = LD8(r0 + 0x06075B74);
                                                    r8 = r1 & 255;
                                                    r1 = LD8(r8 + 0x06075135);
                                                    r2 = r8;
                                                    if (!(((r1 & 2) & (r1 & 2)) == 0)) {
                                                        r2 = r2 - 32;
                                                    }
                                                    r8 = r2 & 255;
                                                }
                                            }
                                        } else {
                                            r2 = LD8(r10);
                                            r0 = r7;
                                            if (((2 & r2) & (2 & r2)) == 0) {
                                                c19 = ((r0 & 1) & (r0 & 1)) == 0;
                                                r0 = r2;
                                                if (!(c19)) {
                                                    r1 = LD8(r3 + 0x06075B74);
                                                    r8 = r1 & 255;
                                                } else {
                                                    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                                                        r1 = LD8(r3 + 0x06075B74);
                                                        r8 = r1 & 255;
                                                    }
                                                }
                                            } else {
                                                if (((r7 & 1) & (r7 & 1)) == 0) {
                                                    r0 = LD8(r10);
                                                    c17 = ((r0 & 1) & (r0 & 1)) == 0;
                                                    r0 = r3;
                                                    if (c17) {
                                                        r1 = LD8(r0 + 0x06075B74);
                                                        r8 = r1 & 255;
                                                        r1 = LD8(r8 + 0x06075135);
                                                        r2 = r8;
                                                        if (!(((r1 & 2) & (r1 & 2)) == 0)) {
                                                            r2 = r2 - 32;
                                                        }
                                                        r8 = r2 & 255;
                                                    }
                                                }
                                            }
                                        }
                                        r9 = 0x06078024;
                                        r1 = LD32(0x06078024);
                                        ST8((r1 + 28), r8);
                                        r0 = GCALL1(0x0602F630, r8);
                                        if (!((r0 & r0) == 0)) {
                                            r4 = LD32(r9);
                                            r0 = GCALL2(0x0602F668, r4, r8);
                                        }
                                        r4 = LD32(r9);
                                        r1 = LD32(r4 + 36);
                                        if (!((r1 & r1) == 0)) {
                                            r0 = GCALL1(r1, r4);
                                        }
                                    }
                                    r2 = LD8(r10);
                                    r0 = r2;
                                    if (!(((1 & r2) & (1 & r2)) == 0)) {
                                        r0 = r0 ^ 1;
                                        ST8(r10, r0);
                                    }
                                    r0 = 1;
                                } else {
                                    c9 = (r8 & r8) == 0;
                                    if (r8 > r1) {
                                        c11 = r0 == 45;
                                        if (r0 == 31) {
                                            r0 = LD8(r10);
                                            r0 = r0 ^ 2;
                                            ST8(r10, r0);
                                        } else {
                                            if (!(c11)) {
                                                ST8(0x0607802E, r8);
                                                ST8(0x0607802F, 3);
                                                r1 = LD32(0x06078024);
                                                r1 = LD16((r1 + 24));
                                                c12 = r1 >= 0;
                                                r1 = (signed char)r8;
                                                if (c12) {
                                                    r3 = LD32((r1 << 2) + 0x06076860);
                                                    r3 = ((r3 & 255) - ((int)((((long long)((unsigned long long)(unsigned)(r3 & 255) * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)(r3 & 255) * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                                    r1 = LD8(r3 + 0x06075A74);
                                                    r7 = LD16(r11);
                                                    r8 = r1 & 255;
                                                    if (!(((64 & r7) & (64 & r7)) == 0)) {
                                                        if (((r7 & 1) & (r7 & 1)) == 0) {
                                                            r0 = LD8(r10);
                                                            c17 = ((r0 & 1) & (r0 & 1)) == 0;
                                                            r0 = r3;
                                                            if (c17) {
                                                                r1 = LD8(r0 + 0x06075B74);
                                                                r8 = r1 & 255;
                                                                r1 = LD8(r8 + 0x06075135);
                                                                r2 = r8;
                                                                if (!(((r1 & 2) & (r1 & 2)) == 0)) {
                                                                    r2 = r2 - 32;
                                                                }
                                                                r8 = r2 & 255;
                                                            }
                                                        }
                                                    } else {
                                                        r2 = LD8(r10);
                                                        r0 = r7;
                                                        if (((2 & r2) & (2 & r2)) == 0) {
                                                            c19 = ((r0 & 1) & (r0 & 1)) == 0;
                                                            r0 = r2;
                                                            if (!(c19)) {
                                                                r1 = LD8(r3 + 0x06075B74);
                                                                r8 = r1 & 255;
                                                            } else {
                                                                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                                                                    r1 = LD8(r3 + 0x06075B74);
                                                                    r8 = r1 & 255;
                                                                }
                                                            }
                                                        } else {
                                                            if (((r7 & 1) & (r7 & 1)) == 0) {
                                                                r0 = LD8(r10);
                                                                c17 = ((r0 & 1) & (r0 & 1)) == 0;
                                                                r0 = r3;
                                                                if (c17) {
                                                                    r1 = LD8(r0 + 0x06075B74);
                                                                    r8 = r1 & 255;
                                                                    r1 = LD8(r8 + 0x06075135);
                                                                    r2 = r8;
                                                                    if (!(((r1 & 2) & (r1 & 2)) == 0)) {
                                                                        r2 = r2 - 32;
                                                                    }
                                                                    r8 = r2 & 255;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    r9 = 0x06078024;
                                                    r1 = LD32(0x06078024);
                                                    ST8((r1 + 28), r8);
                                                    r0 = GCALL1(0x0602F630, r8);
                                                    if (!((r0 & r0) == 0)) {
                                                        r4 = LD32(r9);
                                                        r0 = GCALL2(0x0602F668, r4, r8);
                                                    }
                                                    r4 = LD32(r9);
                                                    r1 = LD32(r4 + 36);
                                                    if (!((r1 & r1) == 0)) {
                                                        r0 = GCALL1(r1, r4);
                                                    }
                                                }
                                                r2 = LD8(r10);
                                                r0 = r2;
                                                if (!(((1 & r2) & (1 & r2)) == 0)) {
                                                    r0 = r0 ^ 1;
                                                    ST8(r10, r0);
                                                }
                                            } else {
                                                r0 = LD8(r10);
                                                r0 = r0 ^ 1;
                                                ST8(r10, r0);
                                            }
                                        }
                                        r0 = 1;
                                    } else {
                                        r0 = 1;
                                        if (!(c9)) {
                                            ST8(0x0607802E, r8);
                                            ST8(0x0607802F, 3);
                                            r1 = LD32(0x06078024);
                                            r1 = LD16((r1 + 24));
                                            c12 = r1 >= 0;
                                            r1 = (signed char)r8;
                                            if (c12) {
                                                r3 = LD32((r1 << 2) + 0x06076860);
                                                r3 = ((r3 & 255) - ((int)((((long long)((unsigned long long)(unsigned)(r3 & 255) * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)(r3 & 255) * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                                r1 = LD8(r3 + 0x06075A74);
                                                r7 = LD16(r11);
                                                r8 = r1 & 255;
                                                if (!(((64 & r7) & (64 & r7)) == 0)) {
                                                    if (((r7 & 1) & (r7 & 1)) == 0) {
                                                        r0 = LD8(r10);
                                                        c17 = ((r0 & 1) & (r0 & 1)) == 0;
                                                        r0 = r3;
                                                        if (c17) {
                                                            r1 = LD8(r0 + 0x06075B74);
                                                            r8 = r1 & 255;
                                                            r1 = LD8(r8 + 0x06075135);
                                                            r2 = r8;
                                                            if (!(((r1 & 2) & (r1 & 2)) == 0)) {
                                                                r2 = r2 - 32;
                                                            }
                                                            r8 = r2 & 255;
                                                        }
                                                    }
                                                } else {
                                                    r2 = LD8(r10);
                                                    r0 = r7;
                                                    if (((2 & r2) & (2 & r2)) == 0) {
                                                        c19 = ((r0 & 1) & (r0 & 1)) == 0;
                                                        r0 = r2;
                                                        if (!(c19)) {
                                                            r1 = LD8(r3 + 0x06075B74);
                                                            r8 = r1 & 255;
                                                        } else {
                                                            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                                                                r1 = LD8(r3 + 0x06075B74);
                                                                r8 = r1 & 255;
                                                            }
                                                        }
                                                    } else {
                                                        if (((r7 & 1) & (r7 & 1)) == 0) {
                                                            r0 = LD8(r10);
                                                            c17 = ((r0 & 1) & (r0 & 1)) == 0;
                                                            r0 = r3;
                                                            if (c17) {
                                                                r1 = LD8(r0 + 0x06075B74);
                                                                r8 = r1 & 255;
                                                                r1 = LD8(r8 + 0x06075135);
                                                                r2 = r8;
                                                                if (!(((r1 & 2) & (r1 & 2)) == 0)) {
                                                                    r2 = r2 - 32;
                                                                }
                                                                r8 = r2 & 255;
                                                            }
                                                        }
                                                    }
                                                }
                                                r9 = 0x06078024;
                                                r1 = LD32(0x06078024);
                                                ST8((r1 + 28), r8);
                                                r0 = GCALL1(0x0602F630, r8);
                                                if (!((r0 & r0) == 0)) {
                                                    r4 = LD32(r9);
                                                    r0 = GCALL2(0x0602F668, r4, r8);
                                                }
                                                r4 = LD32(r9);
                                                r1 = LD32(r4 + 36);
                                                if (!((r1 & r1) == 0)) {
                                                    r0 = GCALL1(r1, r4);
                                                }
                                            }
                                            r2 = LD8(r10);
                                            r0 = r2;
                                            if (!(((1 & r2) & (1 & r2)) == 0)) {
                                                r0 = r0 ^ 1;
                                                ST8(r10, r0);
                                            }
                                            r0 = 1;
                                        }
                                    }
                                }
                            }
                        } else {
                            r0 = 0;
                        }
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06023AC0(int r4, int r5)
{
    int r0, r1, r3, r6, r7, c2;

    r0 = r4;
    r3 = r5;
    if (r0 == 1) {
        r0 = 14;
        r7 = 27;
    } else {
        c2 = r0 == 2;
        if (!(r0 > 1)) {
            r0 = 1;
            r7 = 13;
        } else {
            r0 = 29;
            if (c2) {
                r7 = 43;
            } else {
                r0 = 1;
                r7 = 13;
            }
        }
    }
    r6 = r0;
    if (!(r3 >= r0)) {
        r3 = r0;
    } else {
        if (!(r3 > r7)) {
            r1 = LD32(0x0607694C);
            r0 = (r1 + 1) & 3;
            ST32(0x0607694C, r0);
            if ((r0 & r0) == 0) {
                r3 = r3 + 1;
                if (r3 > r7) {
                    r3 = r6;
                }
            }
        } else {
            r3 = r0;
        }
    }
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060243C0(int r4)
{
    int r0, r1, r2, r3, r7, c3, c5, c7;

    r3 = r4 & 255;
    r2 = r3;
    r1 = LD32(0x06078024);
    r7 = 0;
    if ((r1 & r1) == 0) {
        r0 = r3;
        r1 = 25;
        if (r0 == 25) {
            r7 = -160;
        } else {
            c3 = r0 == 24;
            if (r3 > r1) {
                r0 = r2;
                c5 = r0 == 115;
                if (r0 == 83) {
                    r2 = LD8(0x0608AF52);
                    ST8(0x0608AF52, ((r2 & r2) == 0));
                } else {
                    if (c5) {
                        r2 = LD8(0x0608AF52);
                        ST8(0x0608AF52, ((r2 & r2) == 0));
                    }
                }
            } else {
                if (c3) {
                    r7 = 160;
                }
            }
        }
    }
    r2 = 0x060759CC;
    r1 = LD32(0x060759CC);
    c7 = r1 >= 0;
    r1 = 0;
    if (!(c7)) {
        ST32(r2, r1);
    }
    r1 = LD32(r2);
    r3 = 0x180;
    if (r1 > 0x180) {
        ST32(r2, r3);
    }
    return r7;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025A74(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, c0;

    r8 = r4;
    r0 = GCALL4(0x06025A0C, 4, r5, r6, r7);
    r1 = LD8(0x200000B8 + r8);
    c0 = ((r1 & 255) & (r1 & 255)) == 0;
    r1 = -1;
    if (!(c0)) {
        r8 = 0;
    } else {
        ST8(184 + r8, r1);
        r8 = 1;
    }
    r1 = LD32(0x06000334);
    r0 = GCALL1(r1, 4);
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060278E0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10;
    int v20;

    r9 = r4;
    r10 = r5;
    r4 = 1;
    r8 = r6;
    if (!((unsigned)r9 > (unsigned)1)) {
        r0 = GCALL4(0x06025A0C, r4, r5, r6, r7);
        r0 = r9 << 2;
        ST32(r0 + 0x0608AC30, r10);
        ST32(r0 + 0x0608AC98, r8);
        v20 = r0;
        r0 = GCALL5(0x06046534, r10, r8, (r0 + 0x0608ACA0), 0, v20);
        r0 = v20;
        r5 = 15;
        r6 = 64;
        r7 = 0x0608ABB0;
        r3 = 0;
        ST32(r0 + 0x0608AC90, 0);
        ST32(r0 + 0x0608ABA0, r8);
        ST32(r0 + 0x0608AC38, r8);
        r2 = 0;
        do {
            r0 = r2 << 2;
            r2 = r2 + 1;
            ST32(r0 + ((r9 * r6) + r7), r3);
        } while (AGAIN(!(r2 > r5)));
        r1 = LD32(0x06000334);
        r0 = GCALL5(r1, 1, r5, r6, r7, v20);
        r0 = 1;
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060286A8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c2;
    FRAME(sp, 44);

    ST32((sp - 4), r7);
    ST32((sp - 8), r6);
    ST32((sp - 12), r5);
    r12 = r4;
    r8 = LD32(sp - 12);
    r14 = 0;
    r9 = 0x060875D0;
    r13 = (sp - 44) + 36;
    r10 = 0x06000330;
    r11 = r8;
    do {
        r0 = LD32(r10);
        r0 = GCALL1(r0, 0);
    } while (AGAIN((r0 & r0) == 0));
    r5 = 0x808;
    r0 = GCALL2(0x0606C668, r9, 0x808);
    ST8(-366, 17);
    r0 = GCALL1(0x06028688, r9);
    r6 = r0;
    r1 = r9;
    if (!(r6 >= 0)) {
        r8 = -1;
    } else {
        r1 = LD16((r1 + 4));
        c2 = r11 > r1;
        r1 = r6;
        if (!(c2)) {
            r0 = ((r1 << 2) + (r1 << 2)) + 8;
            r2 = r9 + r0;
            ST8((r2 + 1), 1);
            ST8(r0 + r9, -1);
            ST32(r2 + 4, r12);
            ST8((r2 + 2), r8);
            r3 = LD16((r9 + 6));
            if (r8 > 0) {
                r4 = 0x208;
                r5 = 0x17F;
                r7 = (r13 - 4) + 4;
                do {
                    r2 = LD32(r7);
                    r0 = (r3 << 2) + r9;
                    r3 = r3 + 1;
                    ST32(r0 + r4, r2);
                    if (r3 > r5) {
                        r3 = 0;
                    }
                    r8 = r8 - 1;
                    r7 = r7 + 4;
                } while (AGAIN(r8 > 0));
            }
            r1 = r9 + 4;
            r2 = LD16(r1);
            ST16(r1, (r2 - r11));
            ST16((r9 + 6), r3);
            r0 = LD8(r9);
            r1 = r9;
            if (!(r0 == -1)) {
                r1 = LD8((r1 + 1));
                ST8(((((r1 << 2) + (r1 << 2)) + r9) + 8), r6);
                r1 = r9;
            } else {
                ST8(r9, r6);
                r14 = 1;
            }
            ST8((r1 + 1), r6);
            r8 = 0;
        } else {
            r8 = -1;
        }
    }
    r1 = LD32(0x06000334);
    r0 = GCALL3(r1, 0, r5, r6);
    r1 = -1;
    if (!((r14 & r14) == 0)) {
        ST16(0x21000000, r1);
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060287D0(int r4)
{
    int r0, r7, r8, r9, c0;

    r8 = r4;
    r9 = 0x060279E0;
    r0 = GCALL4(0x060279E0, 0, r8, 3, 1);
    c0 = (r0 & r0) == 0;
    r7 = c0;
    if (c0) {
        r0 = GCALL4(r9, 1, r8, 3, r7);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06028800(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, c5;

    r10 = r4;
    r8 = r5;
    r9 = -1;
    r0 = GCALL1(0x0601D4D8, r4);
    r2 = r10;
    if (!((r8 & r8) == 0)) {
        r2 = r2 + 80;
        r1 = LD32(r2);
        if ((r1 & r1) == 0) {
            r1 = LD32(r10 + 12);
            r2 = LD32(r8 + 12);
            ST32(r8 + 40, (r1 - r2));
        } else {
            r11 = 0x06027F48;
            do {
                r4 = LD32(r2);
                r1 = LD32(r4 + 12);
                ST32(r2, r1);
                r2 = LD32(r4);
                if (!(r2 == 0x7FFFFFFF)) {
                    r1 = LD32(r8 + 12);
                    r1 = r2 - r1;
                    if (!(r9 >= r1)) {
                        r9 = r1;
                    }
                }
                r0 = GCALL1(r11, r4);
                r2 = r10 + 80;
                r1 = LD32(r2);
                c5 = r9 > 0;
            } while (AGAIN(!((r1 & r1) == 0)));
            if (!(c5)) {
                r1 = LD32(r10 + 12);
                r2 = LD32(r8 + 12);
                ST32(r8 + 40, (r1 - r2));
            } else {
                ST32(r8 + 40, r9);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06028FE0(int r4)
{
    int r0, r1, r2, r8, r9, c2;

    r9 = LD32(0x060769C8);
    r8 = r4;
    if (!((r9 & r9) == 0)) {
        ST32(r9 + 144, 0);
        r0 = GCALL1(0x0601D4D8, r8);
        r0 = GCALL1(0x06018ACC, r8);
        r1 = LD32(r8 + 0x10CC);
        r0 = r1;
        c2 = r0 == 3;
        if (!(r0 == 2)) {
            r0 = 1;
            if (c2) {
                r1 = LD32(r8 + 12);
                ST32(136 + r9, r1);
                r0 = 1;
            }
        } else {
            r1 = LD32(r8 + 12);
            r0 = r9;
            r2 = LD32(r0 + 132);
            ST32(r0 + 140, (r1 - r2));
            r1 = LD32(r8 + 12);
            ST32(r0 + 136, r1);
            r0 = 1;
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602A664(int r4, int r5)
{
    int r0, r6, r8, r9, r10;

    r8 = r4;
    r9 = r5;
    r10 = 0x06075238;
    r0 = GCALL3(0x06075238, 0x06028D38, r8, 3);
    r6 = 6;
    if (!((r0 & r0) == 0)) {
        r0 = GCALL3(r10, 0x0602A650, r8, r6);
        r6 = 6;
        if (!((r0 & r0) == 0)) {
            r0 = GCALL3(r10, 0x06028D3C, r8, r6);
            r6 = 8;
            if (!((r0 & r0) == 0)) {
                r0 = GCALL3(r10, 0x0602A658, r8, r6);
                if ((r0 & r0) == 0) {
                    r9 = 4;
                }
            } else {
                r9 = 3;
            }
        } else {
            r9 = 2;
        }
    } else {
        r9 = 1;
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602A6F0(int r4, int r5)
{
    int r0, r6, r8, r9, r10;

    r8 = r4;
    r9 = r5;
    r10 = 0x06075238;
    r0 = GCALL3(0x06075238, 0x0602A6D0, r8, 4);
    r6 = 6;
    if (!((r0 & r0) == 0)) {
        r0 = GCALL3(r10, 0x0602A6D8, r8, r6);
        r6 = 5;
        if (!((r0 & r0) == 0)) {
            r0 = GCALL3(r10, 0x0602A6E0, r8, r6);
            r6 = 5;
            if (!((r0 & r0) == 0)) {
                r0 = GCALL3(r10, 0x0602A6E8, r8, r6);
                if ((r0 & r0) == 0) {
                    r9 = 3;
                }
            } else {
                r9 = 2;
            }
        } else {
            r9 = 1;
        }
    } else {
        r9 = 0;
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602A984(int r4)
{
    int r0, r1, r8;
    int v12;

    r8 = r4;
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        r0 = GCALL4(0x060279E0, 0, 56, 3, 1);
        r4 = r0;
        if ((r0 & r0) == 0) {
            r0 = 0;
        } else {
            v12 = r0;
            r0 = GCALL5(0x06029F68, r4, 0, 0, 0, v12);
            r1 = LD32(r8 + 56);
            r0 = v12;
            if (!((r1 & r1) == 0)) {
                r4 = r8 + 64;
                r1 = LD32(r4);
                if (!((r1 & r1) == 0)) {
                    ST32(r0 + 48, r1);
                    r1 = LD32(r4);
                    r1 = LD32(r1 + 20);
                    ST32(r0 + 20, (r1 + 1));
                    r1 = LD32(r4);
                    ST32(r1 + 52, r0);
                    ST32(r4, r0);
                    r0 = 1;
                } else {
                    r0 = 0;
                }
            } else {
                ST32(r8 + 56, r0);
                ST32((r8 + 64), r0);
                ST32(r0 + 20, 1);
                ST32(r0 + 12, 1);
                r0 = 1;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B8B4(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7;
    int v8;
    int v12;
    int v16;
    int v20;

    r2 = r5;
    if (!((r2 & r2) == 0)) {
        r3 = LD32((r2 + 92));
        if ((r3 & r3) == 0) {
            r0 = 1;
        } else {
            r7 = LD32(r2 + 8);
            r6 = LD32(r2 + 4);
            r5 = LD32(r2);
            r1 = LD32(r2 + 12);
            r0 = GCALL8(0x060153C8, r4, r5, r6, r7, r1, (-1), (r3 & 255), 0);
            r0 = 1;
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B8F8(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, c2;
    int v12;
    int v16;
    int v20;
    int v24;

    if ((r5 & r5) == 0) {
        r0 = 0;
    } else {
        r1 = r5;
        if (!((r4 & r4) == 0)) {
            r1 = LD32((r1 + 92));
            c2 = (r1 & r1) == 0;
            r1 = r5;
            if (c2) {
                r0 = 1;
            } else {
                r2 = LD32((r1 + 96));
                r1 = LD32((r5 + 76));
                r5 = LD32(r1 + 4);
                r6 = LD32(r1 + 12);
                r7 = LD32(r1 + 8);
                r3 = LD32(r1 + 16);
                r0 = GCALL8(0x060153C8, r4, (r5 - (r2 + 2)), (r6 - (r2 + 2)), (r7 + (r2 + 2)), (r3 + (r2 + 2)), (-1), 2, 1);
                r0 = 1;
            }
        } else {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602C310(int r4)
{
    int r0, r1, r2, r3, r5, r8, c2, c4, c5, c7, c9, c11, c18, c19, c20;

    r8 = r4;
    r1 = LD8((r8 + 28));
    r2 = r1 & 255;
    r0 = r2;
    r3 = 0;
    if (r0 == 22) {
        r2 = r8 + 24;
        r1 = LD16(r2);
        r1 = r1 - 1;
        ST16(r2, r1);
        c18 = ((short)r1) >= 0;
        r1 = 0;
        if (!(c18)) {
            ST16(r2, r1);
        }
        r3 = r8;
    } else {
        c2 = r0 == 8;
        if (r2 > 22) {
            c9 = r2 > 128;
            if (r2 == 128) {
                ST32(0x060769D4, 0);
                ST32(0x06076694, 0);
                r3 = r8;
            } else {
                r0 = r2;
                if (c9) {
                    if (r2 == 129) {
                        r2 = 0x06078024;
                        r1 = LD32(0x06078024);
                        r1 = LD32(r1 + 40);
                        ST32(0x06078024, r1);
                        if ((r1 & r1) == 0) {
                            r1 = LD32(0x06078028);
                            ST32(r2, r1);
                        }
                        r3 = r8;
                    } else {
                        if (r2 == 141) {
                            r1 = 0x0602F6CC;
                            r5 = 1;
                            r0 = GCALL2(r1, r8, r5);
                            r3 = r8;
                        } else {
                            r0 = GCALL1(0x060111D8, r8);
                            r3 = r8;
                        }
                    }
                } else {
                    c11 = r0 == 27;
                    if (r0 == 23) {
                        r3 = r8 + 24;
                        r2 = LD16(r3);
                        r1 = LD32(r8 + 20);
                        r0 = r2;
                        r1 = LD8(r0 + r1);
                        c19 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c19)) {
                            ST16(r3, (r1 + 1));
                        }
                    } else {
                        r1 = 0;
                        if (c11) {
                            r2 = LD32(r8 + 20);
                            ST8(r2, r1);
                            ST16((r8 + 24), 0);
                            ST16((r8 + 26), 0);
                        } else {
                            r0 = GCALL1(0x060111D8, r8);
                        }
                    }
                    r3 = r8;
                }
            }
        } else {
            r1 = 8;
            if (c2) {
                r1 = 0x0602F6CC;
                r5 = 0;
                r0 = GCALL2(r1, r8, r5);
                r3 = r8;
            } else {
                c4 = r0 == 4;
                if (r2 > r1) {
                    c7 = r0 == 13;
                    if (r0 == 9) {
                        r2 = 0x06078024;
                        r1 = LD32(0x06078024);
                        r1 = LD32(r1 + 44);
                        ST32(0x06078024, r1);
                        if ((r1 & r1) == 0) {
                            r1 = LD32(0x06078028);
                            while (1) {
                                ST32(r2, r1);
                                if (!((r1 & r1) == 0)) {
                                    POLL();
                                    r3 = LD32(r2);
                                    r1 = LD32(r3 + 40);
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            if ((r3 & r3) == 0) {
                                r2 = LD32(0x06078028);
                                ST32(0x06078024, r2);
                            } else {
                                ST32(0x06078024, r3);
                            }
                        }
                    } else {
                        if (c7) {
                            ST32(0x060769D4, 0);
                            ST32(0x06076694, 0);
                        } else {
                            r0 = GCALL1(0x060111D8, r8);
                        }
                    }
                    r3 = r8;
                } else {
                    c5 = r0 == 7;
                    if (c4) {
                        r0 = GCALL1(0x06032164, 4);
                        r3 = r8;
                    } else {
                        if (c5) {
                            ST32(0x060769D4, 0);
                            ST32(0x06076694, 0);
                        } else {
                            r0 = GCALL1(0x060111D8, r8);
                        }
                        r3 = r8;
                    }
                }
            }
        }
    }
    r3 = r3 + 24;
    r2 = LD16(r3);
    c20 = r2 > 31;
    r2 = r8;
    if (c20) {
        ST16(r3, 31);
        r1 = LD32(r8 + 20);
        ST8((r1 + 31), 0);
        r2 = r8;
    }
    ST8((r2 + 28), 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602C47C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r8, c2, c4, c5, c7, c9, c11, c13, c18, c19, c21;

    r8 = r4;
    r1 = LD8((r8 + 28));
    r2 = r1 & 255;
    r0 = r2;
    r3 = 0;
    if (r0 == 22) {
        r2 = r8 + 24;
        r1 = LD16(r2);
        r1 = r1 - 1;
        ST16(r2, r1);
        c18 = ((short)r1) >= 0;
        r1 = 0;
        if (!(c18)) {
            ST16(r2, r1);
        }
        r3 = r8;
    } else {
        c2 = r0 == 8;
        if (r2 > 22) {
            c9 = r2 > 128;
            if (r2 == 128) {
                ST32(0x060769D4, 0);
                ST32(0x06076694, 0);
                r3 = r8;
            } else {
                r0 = r2;
                if (c9) {
                    if (r2 == 129) {
                        r2 = 0x06078024;
                        r1 = LD32(0x06078024);
                        r1 = LD32(r1 + 40);
                        ST32(0x06078024, r1);
                        if ((r1 & r1) == 0) {
                            r1 = LD32(0x06078028);
                            ST32(r2, r1);
                        }
                        r3 = r8;
                    } else {
                        c13 = r2 == 141;
                        r2 = r8;
                        if (c13) {
                            r1 = 0x0602F6CC;
                            r5 = 1;
                            r0 = GCALL2(r1, r8, r5);
                            r3 = r8;
                        } else {
                            r2 = r2 + 28;
                            r1 = LD8(r2);
                            r0 = LD8((r1 & 255) + 0x06075135);
                            r0 = r0 & 151;
                            r6 = r8;
                            if (!((r0 & r0) == 0)) {
                                r6 = r6 + 24;
                                r3 = LD16(r6);
                                r1 = LD32(r8 + 20);
                                r1 = LD8(((r1 + r3) - 1));
                                ST8(r3 + 0x0608B75F, r1);
                                ST8(r2, 42);
                                r1 = LD16(r6);
                                r2 = LD32(r8 + 20);
                                ST8(((r1 + r2) - 1), 42);
                                r1 = LD16(r6);
                                ST8(r1 + 0x0608B760, 0);
                                r1 = LD32(r8 + 20);
                                r2 = LD16(r6);
                                r0 = r1;
                                ST8(r0 + r2, 0);
                            }
                            r3 = r8;
                        }
                    }
                } else {
                    c11 = r0 == 27;
                    if (r0 == 23) {
                        r3 = r8 + 24;
                        r2 = LD16(r3);
                        r1 = LD32(r8 + 20);
                        r0 = r2;
                        r1 = LD8(r0 + r1);
                        c19 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c19)) {
                            ST16(r3, (r1 + 1));
                        }
                    } else {
                        r1 = 0;
                        if (c11) {
                            r2 = LD32(r8 + 20);
                            ST8(r2, r1);
                            ST16((r8 + 24), 0);
                            ST16((r8 + 26), 0);
                        } else {
                            r2 = r8;
                            r2 = r2 + 28;
                            r1 = LD8(r2);
                            r0 = LD8((r1 & 255) + 0x06075135);
                            r0 = r0 & 151;
                            r6 = r8;
                            if (!((r0 & r0) == 0)) {
                                r6 = r6 + 24;
                                r3 = LD16(r6);
                                r1 = LD32(r8 + 20);
                                r1 = LD8(((r1 + r3) - 1));
                                ST8(r3 + 0x0608B75F, r1);
                                ST8(r2, 42);
                                r1 = LD16(r6);
                                r2 = LD32(r8 + 20);
                                ST8(((r1 + r2) - 1), 42);
                                r1 = LD16(r6);
                                ST8(r1 + 0x0608B760, 0);
                                r1 = LD32(r8 + 20);
                                r2 = LD16(r6);
                                r0 = r1;
                                ST8(r0 + r2, 0);
                            }
                        }
                    }
                    r3 = r8;
                }
            }
        } else {
            r1 = 8;
            if (c2) {
                r1 = 0x0602F6CC;
                r5 = 0;
                r0 = GCALL2(r1, r8, r5);
                r3 = r8;
            } else {
                c4 = r0 == 4;
                if (r2 > r1) {
                    c7 = r0 == 13;
                    if (r0 == 9) {
                        r2 = 0x06078024;
                        r1 = LD32(0x06078024);
                        r1 = LD32(r1 + 44);
                        ST32(0x06078024, r1);
                        if ((r1 & r1) == 0) {
                            r1 = LD32(0x06078028);
                            while (1) {
                                ST32(r2, r1);
                                if (!((r1 & r1) == 0)) {
                                    POLL();
                                    r3 = LD32(r2);
                                    r1 = LD32(r3 + 40);
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            if ((r3 & r3) == 0) {
                                r2 = LD32(0x06078028);
                                ST32(0x06078024, r2);
                            } else {
                                ST32(0x06078024, r3);
                            }
                        }
                    } else {
                        r2 = r8;
                        if (c7) {
                            ST32(0x060769D4, 0);
                            ST32(0x06076694, 0);
                        } else {
                            r2 = r2 + 28;
                            r1 = LD8(r2);
                            r0 = LD8((r1 & 255) + 0x06075135);
                            r0 = r0 & 151;
                            r6 = r8;
                            if (!((r0 & r0) == 0)) {
                                r6 = r6 + 24;
                                r3 = LD16(r6);
                                r1 = LD32(r8 + 20);
                                r1 = LD8(((r1 + r3) - 1));
                                ST8(r3 + 0x0608B75F, r1);
                                ST8(r2, 42);
                                r1 = LD16(r6);
                                r2 = LD32(r8 + 20);
                                ST8(((r1 + r2) - 1), 42);
                                r1 = LD16(r6);
                                ST8(r1 + 0x0608B760, 0);
                                r1 = LD32(r8 + 20);
                                r2 = LD16(r6);
                                r0 = r1;
                                ST8(r0 + r2, 0);
                            }
                        }
                    }
                    r3 = r8;
                } else {
                    c5 = r0 == 7;
                    if (c4) {
                        r0 = GCALL1(0x06032164, 4);
                        r3 = r8;
                    } else {
                        r2 = r8;
                        if (c5) {
                            ST32(0x060769D4, 0);
                            ST32(0x06076694, 0);
                        } else {
                            r2 = r2 + 28;
                            r1 = LD8(r2);
                            r0 = LD8((r1 & 255) + 0x06075135);
                            r0 = r0 & 151;
                            r6 = r8;
                            if (!((r0 & r0) == 0)) {
                                r6 = r6 + 24;
                                r3 = LD16(r6);
                                r1 = LD32(r8 + 20);
                                r1 = LD8(((r1 + r3) - 1));
                                ST8(r3 + 0x0608B75F, r1);
                                ST8(r2, 42);
                                r1 = LD16(r6);
                                r2 = LD32(r8 + 20);
                                ST8(((r1 + r2) - 1), 42);
                                r1 = LD16(r6);
                                ST8(r1 + 0x0608B760, 0);
                                r1 = LD32(r8 + 20);
                                r2 = LD16(r6);
                                r0 = r1;
                                ST8(r0 + r2, 0);
                            }
                        }
                        r3 = r8;
                    }
                }
            }
        }
    }
    r3 = r3 + 24;
    r2 = LD16(r3);
    c21 = r2 > 31;
    r2 = r8;
    if (c21) {
        ST16(r3, 31);
        r1 = LD32(r8 + 20);
        ST8((r1 + 31), 0);
        r2 = r8;
    }
    ST8((r2 + 28), 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602E380(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 168);

    ST32(128 + (sp - 168), r5);
    ST32((132 + (sp - 168)), r6);
    r2 = 0x0608BCFC;
    r1 = LD32(0x0608BCFC);
    r8 = 0;
    r12 = r4;
    if (!(0 >= r1)) {
        r10 = 0x0604A218;
        r9 = r2;
        r6 = 32;
        do {
            r0 = GCALL3(r10, (sp - 168), r12, r6);
            r12 = r12 + (r0 + 1);
            r1 = LD32(r9);
            r8 = r8 + 1;
            r6 = 32;
        } while (AGAIN(!(r8 >= r1)));
    }
    r0 = LD32(132 + (sp - 168));
    r8 = 0;
    r14 = 0;
    if (!(0 >= r0)) {
        r10 = 0;
        r9 = 0x0608AF60;
        r13 = 0;
        do {
            r1 = LD32(0x0608BCFC);
            r3 = LD32((128 + (sp - 168)));
            r6 = 32;
            if (!((r1 + r8) >= r3)) {
                r0 = GCALL3(0x0604A218, r9, r12, r6);
                r11 = r0;
                ST8(r9 + r11, 0);
                r0 = GCALL2(0x06075104, r9, 0x06089B1C);
                if (!((r0 & r0) == 0)) {
                    r0 = 0x0608B97C;
                    r1 = LD32(0x0608B97C);
                    r1 = LD32(r1 + 20);
                    ST32(((r1 + r10) + 48) + 16, r14);
                } else {
                    r0 = 0x0608B97C;
                    r1 = LD32(0x0608B97C);
                    r1 = LD32(r1 + 20);
                    ST32(((r1 + r10) + 48) + 16, 1);
                }
                r12 = r12 + (r11 + 1);
            } else {
                r0 = 0x0608AF60;
                ST8(0x0608AF60 + r13, r14);
                r1 = LD32(0x0608B97C);
                r1 = LD32(r1 + 20);
                ST32(((r1 + r10) + 48) + 16, r14);
            }
            r10 = r10 + 24;
            r9 = r9 + 0x100;
            r3 = LD32((132 + (sp - 168)));
            r8 = r8 + 1;
            r13 = r13 + 0x100;
        } while (AGAIN(!(r8 >= r3)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602F7F4(int r4)
{
    int r0, c10;

    r0 = r4 & 255;
    if (!(r0 == 105)) {
        if (r0 == 107) {
            POLL();
            return 1;
        } else {
            if (r0 == 108) {
                POLL();
                return 1;
            } else {
                if (r0 == 112) {
                    POLL();
                    return 1;
                } else {
                    if (r0 == 113) {
                        POLL();
                        return 1;
                    } else {
                        if (r0 == 114) {
                            POLL();
                            return 1;
                        } else {
                            if (r0 == 115) {
                                POLL();
                                return 1;
                            } else {
                                if (r0 == 116) {
                                    POLL();
                                    return 1;
                                } else {
                                    if (r0 == 117) {
                                        POLL();
                                        return 1;
                                    } else {
                                        if (r0 == 122) {
                                            POLL();
                                            return 1;
                                        } else {
                                            c10 = r0 == 125;
                                            r0 = 0;
                                            if (!(c10)) {
                                                return r0;
                                            } else {
                                                return 1;
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
        return 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602F830(int r4)
{
    int r0, r1, r2, c2, c3, c4, c5, c6, c7, c8, c9;

    r2 = r4 & 255;
    r0 = r2;
    r1 = r2;
    if (!(r0 == 105)) {
        c2 = r0 == 108;
        if (!(r0 == 107)) {
            r0 = r2;
            if (!(c2)) {
                c3 = r0 == 112;
                r0 = r2;
                if (!(c3)) {
                    c4 = r0 == 113;
                    r0 = r2;
                    if (!(c4)) {
                        c5 = r0 == 114;
                        r0 = r2;
                        if (!(c5)) {
                            c6 = r0 == 116;
                            r0 = r2;
                            if (!(c6)) {
                                c7 = r0 == 117;
                                r0 = r2;
                                if (!(c7)) {
                                    c8 = r0 == 122;
                                    r0 = r1;
                                    if (c8) {
                                        POLL();
                                        return 138;
                                    } else {
                                        c9 = r0 == 125;
                                        r0 = 0;
                                        if (!(c9)) {
                                            POLL();
                                            return r0;
                                        } else {
                                            return 139;
                                        }
                                    }
                                } else {
                                    return 137;
                                }
                            } else {
                                return 141;
                            }
                        } else {
                            return 138;
                        }
                    } else {
                        return 133;
                    }
                } else {
                    return 129;
                }
            } else {
                return 135;
            }
        } else {
            return 134;
        }
    } else {
        r0 = 136;
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602220C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 68);

    r14 = sp - 56;
    r13 = r4;
    ST32(r14 + 20, r5);
    r11 = r6;
    r0 = GCALL1(0x0607507C, r4);
    r12 = r0;
    if (!((r7 & r7) == 0)) {
        r9 = r14 + 2;
        r8 = r14 + 4;
        r10 = r14 + 6;
        r0 = LD16((22 + r14));
        ST16(r14, r0);
        ST16(r9, r11);
        r0 = LD16(22 + r14);
        ST16(r8, r0);
        ST16(r10, r11);
        r0 = GCALL3(0x060221DC, r13, 0, (r12 - 1));
        r7 = r14 + 14;
        r2 = LD16(r14);
        r2 = r2 + r0;
        ST16(r14, r2);
        ST16((r14 + 12), r2);
        r3 = LD32(0x060767F8);
        r1 = LD16(r9);
        ST16(r7, (r1 + r3));
        ST16((r8 + 4), r2);
        r1 = LD16(r10);
        ST16((r14 + 10), r1);
        r1 = LD16(r8);
        ST16((r14 + 16), r1);
        r1 = LD16(r7);
        ST16((r14 + 18), r1);
        ST32((sp - 60), 0xFFFF);
        r0 = GCALL5(0x06068D14, 0, 0x4C0, 20, r8, LD32((sp - 60)));
    }
    r0 = LD16(22 + r14);
    r8 = 0;
    ST16(r14, r0);
    ST16((r14 + 2), r11);
    if (!(0 >= r12)) {
        r10 = 0xFFFF;
        r11 = 0x06068E64;
        do {
            r1 = LD8(r13 + r8);
            r2 = r1 & 255;
            r1 = LD32(0x0608AB70);
            r1 = LD8(r1 + r2);
            r9 = (int)((unsigned)(r1 & 255) >> 2);
            if ((unsigned)r2 > (unsigned)31) {
                r1 = r2;
                if ((unsigned)r2 > (unsigned)127) {
                    r1 = r1 - 64;
                } else {
                    r1 = r1 - 32;
                }
                ST32((sp - 60), r10);
                ST32((sp - 64), r14);
                ST32((sp - 68), (((r1 & 255) + 19) & 0xFFFF));
                r0 = GCALL7(r11, 0, 32, 0x480, r10, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
            }
            r1 = LD16(r14);
            r8 = r8 + 1;
            ST16(r14, (r1 + r9));
        } while (AGAIN(!(r8 >= r12)));
    }
    r1 = LD16(r14);
    r0 = LD32(r14 + 20);
    return r1 - r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602234C(void)
{
    int r0, r14;
    FRAME(sp, 24);

    r14 = sp - 12;
    ST16(r14, 247);
    ST16((r14 + 2), 206);
    ST32((sp - 16), 0xFFFF);
    ST32((sp - 20), r14);
    ST32((sp - 24), 10);
    r0 = GCALL7(0x06068E64, 0, 0, 128, 0x1000, LD32((sp - 24)), LD32((sp - 20)), LD32((sp - 16)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06023578(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r13, r14;
    FRAME(sp, 60);

    r14 = sp - 48;
    r11 = r14 + 2;
    r10 = r14 + 4;
    r9 = r14 + 6;
    r13 = LD16(0x060766B0);
    ST16(0x060766AC, ((r4 + r4) - 48));
    ST16(0x060766AE, ((r5 + r5) - 24));
    r8 = r13 + 4;
    r3 = r13 * 48;
    r4 = r4 - r3;
    ST16(r14, r4);
    r5 = r5 - (r13 * 24);
    ST16(r11, r5);
    r2 = r4 + (r13 * 96);
    ST16(r10, r2);
    r1 = r5 + r3;
    ST16(r9, r1);
    ST16(r14, (r4 + r8));
    ST16(r11, (r5 + r8));
    ST16(r10, (r2 + r8));
    ST16(r9, (r1 + r8));
    ST32((sp - 52), 0xFFFF);
    ST32((sp - 56), r14);
    ST32((sp - 60), 4);
    r0 = GCALL7(0x060690BC, 0, 0, 0x8080, 0xFFFF, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
    r1 = LD16(r14);
    ST16(r14, (r1 - r8));
    r1 = LD16(r11);
    ST16(r11, (r1 - r8));
    r1 = LD16(r10);
    ST16(r10, (r1 - r8));
    r1 = LD16(r9);
    ST16(r9, (r1 - r8));
    ST32((sp - 64), 4);
    ST32((sp - 68), 255);
    ST32((sp - 72), 1);
    r0 = GCALL8(0x0602BF00, r14, r13, 0, 1, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
    ST32((sp - 76), 0xFFFF);
    ST32((sp - 80), r14);
    ST32((sp - 84), 4);
    r0 = GCALL8(0x060690BC, 0, 0, 128, 0, LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
    r1 = LD16(r10);
    ST16(r10, (r1 - 9));
    r1 = LD16(r9);
    ST16(r9, (r1 - 9));
    ST32((sp - 52), 0xFFFF);
    ST32((sp - 56), r10);
    ST32((sp - 60), 5);
    r0 = GCALL7(0x06068E64, 0, 0, 128, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
    r5 = r14 + 8;
    r3 = LD16(r10);
    r3 = r3 + 18;
    ST16(r10, r3);
    r1 = LD16(r9);
    r1 = r1 + 19;
    ST16(r9, r1);
    ST16(r5, r3);
    ST16((r14 + 10), r1);
    ST16((r14 + 12), (r3 + 23));
    ST16((r14 + 14), (r1 + 23));
    ST16(r10, (r3 - ((r13 - 1) * 24)));
    r0 = GCALL7(0x060689BC, 0, r5, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
    ST32((sp - 64), 0xFFFF);
    ST32((sp - 68), r10);
    ST32((sp - 72), 6);
    r0 = GCALL8(0x06068E64, 0, 0, 0x480, 0, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06021DD8(int r4, int r5)
{
    int r0, r1, r7, r8;

    r8 = r5;
    if (!((r8 & r8) == 0)) {
        r1 = LD32(0x2000000C + r8);
        if (!((r1 & r1) == 0)) {
            r1 = LD32(192 + r8);
            r7 = 0;
            if (!((r1 & r1) == 0)) {
                r0 = GCALL4(0x06015A5C, r4, r5, 0, r7);
            }
            r0 = GCALL1(0x06026B64, r8);
            r8 = 0;
        }
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025630(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, c2;

    r10 = r4;
    r9 = r10 * 24;
    r0 = GCALL4(0x060279E0, r5, (r9 + 0xD14), -1, 1);
    r8 = r0;
    r2 = r8;
    if (!((r8 & r8) == 0)) {
        ST32(r8, 1);
        ST32(r8 + 4, r10);
        ST32(r8 + 8, (r2 + 12));
        r0 = GCALL3(0x0606A7F4, 1, (r8 + (r9 + 12)), r8);
        c2 = r0 >= 0;
        r0 = -4;
        if (c2) {
            r0 = GCALL1(0x0606A9EC, 0x06025628);
            r1 = r0;
            r5 = r8;
            if (r1 >= 0) {
                r0 = GCALL2(0x0606A8DC, r1, r5);
                r0 = GCALL1(0x0606A984, r8);
            }
            ST32(0x0608AB8C, r8);
            ST32(0x0608AB84, 0);
            ST32(0x0608AB88, 0);
            ST8(0x0608AB80, 0);
            r0 = LD8(-384);
            ST16(-384, ((r0 & 223) | -23296));
            ST16(-384, 0x5A00);
            r0 = LD8(-384);
            ST16(-384, (((r0 & 152) | 2) | -23296));
            r1 = LD16(-286);
            ST16(-286, ((r1 & 0xFFFF) | 240));
            r1 = LD32(0x06000310);
            r0 = GCALL2(r1, 104, 0x0602571C);
            r0 = LD8(-384);
            ST16(-384, (((r0 & 223) | 32) | -23296));
            r0 = 0;
        }
    } else {
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025984(int r4)
{
    int r0, r1, r8, c1;

    r8 = r4;
    r0 = GCALL1(0x060259B4, r4);
    while (1) {
        r1 = LD8(r8);
        r0 = r1 & 255;
        c1 = r0 == 1;
        if ((r0 & r0) == 0) {
            POLL();
            r0 = GCALL0(0x0605299C);
            continue;
        } else {
            if (c1) {
                POLL();
                r0 = GCALL0(0x0605299C);
                continue;
            } else {
                break;
            }
        }
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025D24(int r4, int r5)
{
    int r0, r1, r8, r9;
    FRAME(sp, 2092);

    r0 = LD32(r4 + 28);
    r9 = r5;
    if (r0 == 2) {
        r1 = 0x0603D034;
        r5 = r9;
    } else {
        r1 = r4;
        if (r0 == 9) {
            r4 = LD32((r1 + 116));
            r0 = GCALL3(0x0601897C, r4, (sp - 2092), 0x800);
            r8 = 0x800 + (sp - 2092);
            r0 = GCALL2(0x060189FC, (sp - 2092), r8);
            r0 = GCALL1(0x06018A78, r8);
            r0 = GCALL3(0x06045264, (sp - 2092), 0x06025D18, r8);
            r1 = 0x0603CCE0;
            r5 = sp - 2092;
            r4 = r9;
        } else {
            r1 = r1 + 116;
            r5 = LD32(r1);
            r4 = r9;
            r1 = 0x0603CCE0;
        }
    }
    r0 = GCALL2(r1, r4, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06025DB0(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    r4 = LD32(r8 + 4);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
        ST32(r8 + 4, 0);
    }
    r4 = LD32(r8 + 8);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r8 + 8, 0);
    }
    r4 = LD32(r8);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r8, 0);
    }
    r0 = GCALL1(0x0603CC04, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06026C54(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, c1;

    r8 = r4;
    r9 = 252;
    r4 = LD32(r8 + 252);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
        r0 = r8;
        r2 = LD32(r0 + r9);
        r1 = LD32(r8 + 56);
        c1 = r2 == r1;
        r1 = 0;
        if (c1) {
            ST32(r8 + 56, r1);
            r1 = 0;
            r0 = r8;
        }
        ST32(r0 + r9, r1);
    }
    r4 = LD32(r8 + 56);
    r2 = 0;
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r8 + 56, 0);
        r2 = 0;
    }
    ST32(r8 + 20, r2);
    ST32(0x100 + r8, r2);
    ST32(0x104 + r8, r2);
    ST32(0x108 + r8, -1);
    ST32(0x10C + r8, r2);
    ST32(r8 + 24, 1);
    ST32(0x114 + r8, r2);
    ST32((r8 + 76), 13);
    r0 = GCALL1(0x06026A1C, r8);
    r0 = GCALL1(0x06025AB4, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06026FBC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, c2;

    r9 = r4;
    r0 = 252;
    r1 = LD32(252 + r9);
    if (!((r1 & r1) == 0)) {
        r4 = LD32(r9 + 56);
        c2 = r4 == r1;
        if (!((r4 & r4) == 0)) {
            if (!(c2)) {
                r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
            }
        }
        ST32(r9 + 56, 0);
        r4 = LD32(r9 + 252);
        r0 = GCALL1(0x06027F48, r4);
        r0 = r9;
        ST32(r0 + 252, 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602767C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11;

    r0 = GCALL4(0x06025A0C, 2, r5, r6, r7);
    r8 = LD32(0x060769B0);
    if (!((r8 & r8) == 0)) {
        r11 = 0x06025AE0;
        r10 = 0x06025AB4;
        do {
            r0 = GCALL1(r11, r8);
            r1 = LD32(0x20000118 + r8);
            r9 = LD32(r8);
            if (!((r1 & r1) == 0)) {
                r0 = GCALL1(r10, r8);
            } else {
                r0 = GCALL1(r10, r8);
                r1 = LD32(0x06000334);
                r0 = GCALL1(r1, 2);
                r0 = GCALL1(0x06026B64, r8);
                r0 = GCALL1(0x06025A0C, 2);
                r9 = LD32(0x060769B0);
            }
            r8 = r9;
        } while (AGAIN(!((r8 & r8) == 0)));
    }
    r1 = LD32(0x06000334);
    r0 = GCALL1(r1, 2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06027700(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11;

    r0 = GCALL4(0x06025A0C, 2, r5, r6, r7);
    r8 = LD32(0x060769B0);
    r10 = 0;
    if (!((r8 & r8) == 0)) {
        r11 = 0x06025AE0;
        r9 = 0x328;
        do {
            r0 = GCALL1(r11, r8);
            ST32(r8 + 28, r10);
            r1 = LD32(236 + r8);
            if (!((r1 & r1) == 0)) {
                r1 = LD32(r8 + 32);
                r0 = r8;
                if (!((r1 & r1) == 0)) {
                    r2 = LD32(r0 + 240);
                    r0 = r2;
                    r1 = LD32(r0 + r9);
                    if (!((r1 & r1) == 0)) {
                        ST32(r0 + r9, r10);
                    }
                }
            }
            r0 = GCALL1(0x06025AB4, r8);
            r8 = LD32(r8);
        } while (AGAIN(!((r8 & r8) == 0)));
    }
    r1 = LD32(0x06000334);
    r0 = GCALL1(r1, 2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602777C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11;

    r0 = GCALL4(0x06025A0C, 2, r5, r6, r7);
    r8 = LD32(0x060769B0);
    if (!((r8 & r8) == 0)) {
        r11 = 0x06025AE0;
        r10 = 0x06025AB4;
        do {
            r0 = GCALL1(r11, r8);
            r1 = LD32(0x20000018 + r8);
            r9 = LD32(r8);
            if ((r1 & r1) == 0) {
                r0 = GCALL1(r10, r8);
            } else {
                r0 = GCALL1(r10, r8);
                r1 = LD32(0x06000334);
                r0 = GCALL1(r1, 2);
                r0 = GCALL1(0x06026B64, r8);
                r0 = GCALL1(0x06025A0C, 2);
                r9 = LD32(0x060769B0);
            }
            r8 = r9;
        } while (AGAIN(!((r8 & r8) == 0)));
    }
    r1 = LD32(0x06000334);
    r0 = GCALL1(r1, 2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06029100(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, c4;

    r10 = r4;
    r1 = LD32(0x10C8 + r10);
    r12 = r5;
    if (!((r1 & r1) == 0)) {
        r9 = LD32(0x060769C8);
        r11 = 0;
        ST32((r9 + 68), 0);
        if (!((r9 & r9) == 0)) {
            r0 = GCALL1(0x0601D4D8, r10);
            r2 = LD32(r10 + 0x10CC);
            r0 = r2;
            r1 = 2;
            if (r0 == 2) {
                r8 = r9 + 76;
                r5 = LD32(r8);
                if (!((r5 & r5) == 0)) {
                    r0 = GCALL2(0x06028800, r10, r5);
                    r5 = LD32(r8);
                    r0 = GCALL2(0x06029658, r10, r5);
                    r0 = GCALL1(0x06018ACC, r10);
                }
                r8 = r10 + 80;
                r4 = LD32(r8);
                r0 = GCALL1(0x060288E0, r4);
                ST32(r8, r11);
                r1 = LD32(r9 + 60);
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r1 + 52);
                    ST32(r9 + 60, r1);
                } else {
                    r1 = LD32(r9 + 56);
                    ST32(r9 + 60, r1);
                }
                ST32((r9 + 76), 0);
                r2 = LD32(r9 + 60);
                if ((r2 & r2) == 0) {
                    r0 = 0;
                } else {
                    r1 = LD32(r10 + 12);
                    ST32(r2, r1);
                    r2 = r9 + 72;
                    r1 = LD32(r2);
                    ST32(r2, (r1 + 1));
                    r0 = 1;
                }
            } else {
                c4 = r0 == 1;
                if (r2 > r1) {
                    r1 = r9;
                    if (r0 == 3) {
                        r5 = LD32((r1 + 76));
                        if (!((r5 & r5) == 0)) {
                            r0 = GCALL2(0x06029658, r10, r5);
                            r0 = GCALL1(0x06018ACC, r10);
                            r0 = GCALL2(0x0602B8F8, r10, r9);
                        }
                        r1 = LD32(r9 + 60);
                        if (!((r1 & r1) == 0)) {
                            r1 = LD32(r1 + 52);
                            ST32(r9 + 60, r1);
                        } else {
                            r1 = LD32(r9 + 56);
                            ST32(r9 + 60, r1);
                        }
                        ST32((r9 + 76), 0);
                        r1 = LD32(r9 + 60);
                        r0 = 0;
                        if (!((r1 & r1) == 0)) {
                            r2 = r9 + 72;
                            r1 = LD32(r2);
                            ST32(r2, (r1 + 1));
                            r0 = 1;
                        }
                    } else {
                        r0 = 0;
                    }
                } else {
                    r1 = r9;
                    if (c4) {
                        r5 = LD32((r1 + 76));
                        if (!((r5 & r5) == 0)) {
                            r0 = GCALL2(0x06029658, r10, r5);
                            r0 = GCALL1(0x06018ACC, r10);
                            r4 = LD32(r10 + 0x10D0);
                            r0 = GCALL1(0x0602AC4C, r4);
                            ST32(r10 + 0x10D0, r11);
                        }
                        r0 = GCALL1(0x0602A9F0, r9);
                        r5 = LD32(r9 + 60);
                        r0 = GCALL3(0x0602A4F4, r10, r5, r12);
                        r0 = 1;
                    } else {
                        r0 = 0;
                    }
                }
            }
        } else {
            r0 = 0;
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602929C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, c6, c13;

    r10 = r4;
    r1 = LD32(0x10C8 + r10);
    if (!((r1 & r1) == 0)) {
        r11 = LD32(0x060769C8);
        r2 = r11;
        if (!((r11 & r11) == 0)) {
            ST32((r2 + 68), 0);
            r0 = GCALL1(0x0601D4D8, r10);
            r9 = r10 + 84;
            r1 = LD32(r9);
            if (!((r1 & r1) == 0)) {
                r12 = 0x06027F48;
                do {
                    r4 = LD32(r9);
                    r1 = LD32(r4 + 12);
                    ST32(r9, r1);
                    r0 = GCALL1(r12, r4);
                    r1 = LD32(r9);
                } while (AGAIN(!((r1 & r1) == 0)));
            }
            r12 = 0x10CC;
            r2 = LD32(r10 + 0x10CC);
            r0 = r2;
            r1 = 2;
            if (r0 == 2) {
                r12 = r11 + 76;
                r5 = LD32(r12);
                r8 = r10;
                if (!((r5 & r5) == 0)) {
                    r0 = GCALL2(0x06028800, r10, r5);
                    r5 = LD32(r12);
                    r0 = GCALL2(0x06029658, r10, r5);
                    r0 = GCALL1(0x06018ACC, r10);
                    r8 = r10;
                }
                r8 = r8 + 80;
                r4 = LD32(r8);
                r0 = GCALL1(0x060288E0, r4);
                r9 = 0;
                ST32(r8, 0);
                r0 = GCALL1(0x0602B648, r10);
                ST32(r11 + 60, 0);
                ST32(r12, 0);
                r1 = LD32(0x060769C4);
                r3 = r11;
                if (!(r11 == r1)) {
                    r3 = r3 + 80;
                    r1 = LD32(r3);
                    r1 = LD32(r1 + 4);
                    r8 = r10 + 64;
                    ST32(r8, r1);
                    r1 = LD32(r3);
                    r1 = LD32(r1 + 8);
                    ST32((r10 + 68), r1);
                    r1 = LD32(r8);
                    ST32(r10 + 8, r1);
                    r0 = GCALL0(0x0602ABEC);
                    r1 = LD32((r11 + 124));
                    r0 = r1;
                    if (!((r1 & r1) == 0)) {
                        c13 = r0 == 2;
                        r0 = 1;
                        if (c13) {
                            r0 = 0x0601B028;
                            r1 = LD32(r8);
                            r5 = -1;
                            ST32(r10 + 8, r1);
                            r6 = LD32(r11);
                            r4 = r10;
                            r7 = LD32(r10 + 12);
                            r6 = r6 - 2;
                            r0 = GCALL4(r0, r4, r5, r6, r7);
                            r1 = LD32(r11 + 4);
                            ST32(r10 + 12, r1);
                            r0 = 1;
                        }
                    } else {
                        r0 = 0x0601B028;
                        r1 = LD32(r11 + 8);
                        r6 = -1;
                        ST32(r10 + 8, (r1 + 2));
                        r5 = LD32(r11 + 8);
                        r4 = r10;
                        r7 = LD32(r10 + 12);
                        r5 = r5 + 2;
                        r0 = GCALL4(r0, r4, r5, r6, r7);
                        r1 = LD32(r11 + 4);
                        ST32(r10 + 12, r1);
                        r0 = 1;
                    }
                } else {
                    ST32(0x10C8 + r10, r9);
                    r0 = 0;
                }
            } else {
                c6 = r0 == 1;
                if (r2 > r1) {
                    r8 = r11;
                    if (!(r0 == 3)) {
                        r0 = 1;
                    } else {
                        r8 = r8 + 76;
                        r5 = LD32(r8);
                        r9 = 0;
                        if (!((r5 & r5) == 0)) {
                            r0 = GCALL2(0x06029658, r10, r5);
                            r0 = GCALL1(0x06018ACC, r10);
                            r0 = GCALL2(0x0602B8F8, r10, r11);
                            r9 = 0;
                        }
                        ST32(r8, r9);
                        r0 = GCALL2(0x0602B8B4, r10, r11);
                        r1 = LD32(0x060769C4);
                        r3 = r11;
                        if (!(r11 == r1)) {
                            r3 = r3 + 80;
                            r1 = LD32(r3);
                            r1 = LD32(r1 + 4);
                            r7 = r10 + 64;
                            ST32(r7, r1);
                            r1 = LD32(r3);
                            r1 = LD32(r1 + 8);
                            ST32((r10 + 68), r1);
                            r1 = LD32(r7);
                            ST32(r10 + 8, r1);
                            r0 = GCALL0(0x0602ABEC);
                        } else {
                            r1 = LD32(r10 + 136);
                            ST32(r11 + 0x124, r1);
                            r1 = LD32(r10 + 144);
                            ST32(r11 + 0x12C, r1);
                            r1 = LD32(r10 + 148);
                            ST32(r11 + 0x130, r1);
                            r1 = LD32(r10 + 152);
                            ST32(r11 + 0x134, r1);
                            r1 = LD32(r10 + 156);
                            ST32(r11 + 0x138, r1);
                            r1 = LD32(r10 + 164);
                            ST32(r11 + 0x140, r1);
                            r1 = LD32(r10 + 160);
                            r0 = r11;
                            ST32(r0 + 0x13C, r1);
                            r1 = LD32((r10 + 88));
                            ST32(r0 + 244, r1);
                            r4 = LD32((r10 + 80));
                            r0 = GCALL1(0x060288E0, r4);
                            r0 = GCALL3(0x06072820, r10, (r11 + 156), 0x424);
                            r0 = r10;
                            ST32(r0 + 0x10C8, r9);
                            ST32(r0 + r12, r9);
                        }
                        r1 = LD32(r11 + 12);
                        r1 = r1 + 1;
                        ST32(r10 + 12, r1);
                        r2 = LD32(140 + r11);
                        if (r2 > 0) {
                            r0 = LD32(128 + r11);
                            r1 = r1 + r2;
                            if (r0 == 2) {
                                ST32(r10 + 12, r1);
                            }
                        }
                        r1 = LD32((r11 + 124));
                        r0 = r1;
                        if (!((r1 & r1) == 0)) {
                            r1 = r10;
                            if (r0 == 2) {
                                r0 = 0x0601B028;
                                r1 = LD32((r1 + 64));
                                r5 = -1;
                                ST32(r10 + 8, r1);
                                r6 = LD32(r11);
                                r4 = r10;
                                r7 = LD32(r10 + 12);
                                r6 = r6 - 2;
                                r0 = GCALL4(r0, r4, r5, r6, r7);
                                r1 = LD32(r11 + 4);
                                ST32(r10 + 12, r1);
                            }
                        } else {
                            r0 = 0x0601B028;
                            r1 = LD32(r11 + 8);
                            r6 = -1;
                            ST32(r10 + 8, (r1 + 2));
                            r5 = LD32(r11 + 8);
                            r4 = r10;
                            r7 = LD32(r10 + 12);
                            r5 = r5 + 2;
                            r0 = GCALL4(r0, r4, r5, r6, r7);
                            r1 = LD32(r11 + 4);
                            ST32(r10 + 12, r1);
                        }
                        r3 = LD32(r10 + 0x10B8);
                        r8 = 0x060769C4;
                        r0 = r11;
                        r1 = LD16(r0 + 148);
                        ST16(r3, r1);
                        r1 = LD16(((r11 + 148) + 2));
                        ST16((r3 + 2), r1);
                        r1 = LD32(r0 + 152);
                        ST32(r10 + 0x10B0, r1);
                        r1 = LD32(0x060769C4);
                        r0 = 1;
                        if (r11 == r1) {
                            r0 = GCALL1(0x0602A030, r11);
                            r0 = GCALL1(0x06027F48, r11);
                            ST32(0x060769C8, 0);
                            ST32(r8, 0);
                            r1 = 0x06033EB8;
                            r0 = GCALL0(r1);
                            r0 = 1;
                        }
                    }
                } else {
                    r9 = r11;
                    if (c6) {
                        r9 = r9 + 76;
                        r5 = LD32(r9);
                        if (!((r5 & r5) == 0)) {
                            r0 = GCALL2(0x06029658, r10, r5);
                            r0 = GCALL1(0x06018ACC, r10);
                            r4 = LD32(r10 + 0x10D0);
                            r0 = GCALL1(0x0602AC4C, r4);
                            ST32(r10 + 0x10D0, 0);
                        }
                        r0 = GCALL0(0x0602B244);
                        r0 = GCALL0(0x0602B100);
                        r2 = 0;
                        ST32(r11 + 60, 0);
                        ST32(r9, 0);
                        r1 = LD32(0x060769C4);
                        if (!(r11 == r1)) {
                            r1 = 0x0602ABEC;
                            r0 = GCALL0(r1);
                            r0 = 1;
                        } else {
                            ST32(0x10C8 + r10, r2);
                            r0 = 0;
                        }
                    } else {
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
int f06029FD8(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    r4 = LD32(r8 + 20);
    r0 = GCALL4(0x06029F94, r4, r5, r6, r7);
    r0 = GCALL1(0x06027F48, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06029FF8(int r4)
{
    int r0, r8, r9, r10;

    r9 = r4;
    r8 = LD32(r9 + 16);
    r4 = r8;
    if (!((r8 & r8) == 0)) {
        r10 = 0x06029FD8;
        do {
            r8 = LD32(r8 + 56);
            r0 = GCALL1(r10, r4);
            r4 = r8;
        } while (AGAIN(!((r8 & r8) == 0)));
    }
    r0 = GCALL1(0x06027F48, r9);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B968(int r4)
{
    int r0, r1, r2, r7, r8, r9, r10, r11;

    r9 = r4;
    r10 = 0x060279E0;
    r0 = GCALL4(0x060279E0, 0, (r9 << 2), -1, 1);
    ST32(0x0608ACB8, r0);
    r8 = 0;
    ST32(0x0608ACB0, r9);
    if (!(0 >= r9)) {
        r11 = r10;
        r10 = 0x0604B3F0;
        r7 = 1;
        do {
            r0 = GCALL4(r11, 0, 50, -1, r7);
            r2 = r0;
            r1 = LD32(0x0608ACB8);
            ST32((r8 << 2) + r1, r2);
            r0 = GCALL3(r10, r2, 0, 50);
            r8 = r8 + 1;
            r7 = 1;
        } while (AGAIN(!(r8 >= r9)));
    }
    r2 = LD32(0x0608ACB8);
    r4 = LD32((((r8 << 2) + r2) - 4));
    r0 = GCALL3(0x06045264, r4, 0x0602B954, r9);
    ST32(0x0608ACAC, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602CAF0(int r4, int r5)
{
    int r0, r1, r6, r7, r8, r9, r10, r11, r12;
    FRAME(sp, 72);

    ST32(0x0607668C, 2);
    ST32(0x06077F98, 1);
    r11 = r5;
    r0 = GCALL2(0x060750DC, (sp - 60), ((r4 * 22) + 0x06077F9C));
    r0 = GCALL0(0x060259E0);
    r12 = r0;
    r0 = GCALL1(0x060259EC, 0);
    r0 = GCALL2(0x06025DFC, r11, (sp - 60));
    r9 = r0;
    ST32(r9 + 36, 1);
    r10 = 0x06027000;
    r8 = 0x0605299C;
    r5 = sp - 60;
    do {
        r0 = GCALL2(r10, r11, (r5 + 32));
        r0 = GCALL0(r8);
        r1 = LD32(0x20000014 + r9);
        r5 = sp - 60;
    } while (AGAIN(!((r1 & r1) == 0)));
    r10 = 168;
    r8 = 0x06026208;
    r0 = r11;
    do {
        r5 = LD8(r0 + r10);
        r0 = GCALL3(r8, r9, r5, 0);
        r0 = GCALL0(0x0605299C);
        r1 = LD32(r9 + 0x2000000C);
        r0 = r11;
    } while (AGAIN((r1 & r1) == 0));
    r1 = LD32(192 + r9);
    if (!((r1 & r1) == 0)) {
        r7 = LD32(212 + r9);
        r6 = LD32(200 + r9);
        r5 = LD32(196 + r9);
        r4 = LD32(232 + r9);
        ST32((sp - 64), 0x100);
        r1 = LD32(0x110 + r9);
        ST32((sp - 68), r1);
        ST32((sp - 72), 18);
        r0 = GCALL7(0x0601637C, r4, r5, r6, 0, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
    }
    r0 = GCALL1(0x06026B64, r9);
    r0 = GCALL1(0x060259EC, r12);
    ST32(0x06077F98, 0);
    ST32(0x0607668C, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06020230(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r9, r10, r11;

    r10 = r4;
    r9 = r5;
    r7 = r9 + 22;
    r2 = LD8((r9 + 18));
    r1 = LD8((r9 + 19));
    ST16((r10 + 38), ((r2 & 255) + ((r1 & 255) << 8)));
    r2 = LD8((r9 + 20));
    r1 = LD8((r9 + 21));
    ST16((r10 + 40), ((r2 & 255) + ((r1 & 255) << 8)));
    r3 = LD8(r7);
    r11 = 0;
    if (!(((128 & r3) & (128 & r3)) == 0)) {
        r11 = 1;
    }
    ST16((r10 + 36), ((((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) & 7) + 1));
    r0 = LD8(r7);
    r5 = (r0 & 7) + 1;
    ST8((r9 + 36), r5);
    r0 = GCALL2(0x0607290C, 1, r5);
    ST16((r9 + 38), r0);
    r1 = LD8((r9 + 23));
    ST8(0x338 + r10, r1);
    if ((r11 & r11) == 0) {
        r1 = 0x0601F3FC;
        r5 = 9;
    } else {
        ST16((r9 + 4), 0);
        r1 = 0x0601F3FC;
        r5 = 2;
    }
    r0 = GCALL2(r1, r9, r5);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060202EC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, c2;

    r8 = r4;
    r9 = r5;
    r10 = r6;
    if ((r7 & r7) == 0) {
        r1 = LD16((r10 + 28));
        if (!((unsigned)((r1 - 2) & 0xFFFF) > (unsigned)1)) {
            r1 = LD32(r8 + 24);
            c2 = (r1 & r1) == 0;
            r1 = r10;
            if (!(c2)) {
                r1 = LD16((r1 + 26));
                r5 = r1 & 0xFFFF;
            } else {
                r0 = GCALL1(0x06020DCC, r4);
                r1 = r10;
                if (!((r0 & r0) == 0)) {
                    r1 = LD16((r1 + 26));
                    r5 = r1 & 0xFFFF;
                } else {
                    r5 = 0;
                }
            }
            r0 = GCALL2(0x0601F0F0, r8, r5);
        }
    }
    r0 = GCALL3(0x0604B358, (r8 + 52), (r9 + 36), 0x304);
    r5 = r8 + 44;
    r4 = r8 + 46;
    r2 = LD8((r9 + 18));
    r7 = r8 + 48;
    r1 = LD8((r9 + 19));
    ST16(r5, ((r2 & 255) + ((r1 & 255) << 8)));
    r2 = LD8((r9 + 20));
    r1 = LD8((r9 + 21));
    ST16(r4, ((r2 & 255) + ((r1 & 255) << 8)));
    r2 = LD8((r9 + 22));
    r6 = r8 + 50;
    r1 = LD8((r9 + 23));
    ST16(r7, ((r2 & 255) + ((r1 & 255) << 8)));
    r2 = LD8((r9 + 24));
    r1 = LD8((r9 + 25));
    ST16(r6, ((r2 & 255) + ((r1 & 255) << 8)));
    r1 = LD32(0x340 + r8);
    ST32(0x340 + r8, (r1 + 1));
    r1 = LD32(r8);
    r2 = r8;
    if ((r1 & r1) == 0) {
        r1 = LD16(r5);
        r3 = r8 + 38;
        r2 = LD16(r7);
        r2 = (r2 & 0xFFFF) + (r1 & 0xFFFF);
        r1 = LD16(r3);
        r1 = r1 & 0xFFFF;
        if (!(r1 >= r2)) {
            r1 = r2;
        }
        ST16(r3, r1);
        r1 = LD16(r4);
        r3 = r8 + 40;
        r2 = LD16(r6);
        r2 = (r2 & 0xFFFF) + (r1 & 0xFFFF);
        r1 = LD16(r3);
        r1 = r1 & 0xFFFF;
        if (!(r1 >= r2)) {
            r1 = r2;
        }
        ST16(r3, r1);
        r2 = r8;
    }
    r1 = LD16((r8 + 48));
    ST16((r2 + 42), r1);
    r0 = LD8((r9 + 26));
    r2 = 0;
    if (!(((128 & r0) & (128 & r0)) == 0)) {
        r2 = 1;
    }
    r1 = 1;
    if (((r0 & 64) & (r0 & 64)) == 0) {
        r1 = 0;
    }
    ST32(r8 + 20, r1);
    r0 = LD8((r9 + 26));
    if ((r2 & r2) == 0) {
        ST32(0x33C + r8, 1);
        r1 = 0x0601F3FC;
        r5 = 7;
    } else {
        r5 = (r0 & 7) + 1;
        ST8((r8 + 52), r5);
        r0 = GCALL2(0x0607290C, 1, r5);
        ST16((r8 + 54), r0);
        ST16((r9 + 4), 0);
        r1 = 0x0601F3FC;
        r5 = 5;
    }
    r0 = GCALL2(r1, r9, r5);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06027EF0(int r4, int r5, int r6, int r7)
{
    int r0;
    FRAME(sp, 132);

    ST32(0x0608ACAC, 1);
    r0 = GCALL4(0x06045264, (sp - 132), 0x06027ED8, r4, r7);
    r0 = GCALL1(0x0602BA00, (sp - 132));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06028168(int r4, int r5, int r6, int r7)
{
    int r0, r8;
    FRAME(sp, 76);

    ST32(sp - 76, r4);
    ST32(0x0608ACAC, 1);
    r8 = (sp - 76) + 4;
    r6 = LD32(sp - 76);
    r0 = GCALL5(0x06045264, r8, 0x0602814C, r6, r7, LD32((sp - 76)));
    r0 = GCALL5(0x0602BA00, r8, 0, 0, 0, LD32((sp - 76)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060281C0(int r4, int r5, int r6, int r7)
{
    int r0;

    ST32(0x0608ACAC, 1);
    r0 = GCALL4(0x06045264, 0x0608B9D0, 0x060281A4, r4, r7);
    r0 = GCALL1(0x0602BA00, 0x0608B9D0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602842C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    int v8;

    ST32(0x2608ACA8, 1);
    r1 = 0x20100063;
    r0 = LD8(0x20100063);
    r5 = r4;
    while (!(((r0 & 1) & (r0 & 1)) == 0)) {
        POLL();
        r0 = LD8(r1);
    }
    ST8(0x20100063, 1);
    ST8(0x2010001F, 3);
    r0 = LD8(0x20100063);
    r1 = 0x20100063;
    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
        do {
            r0 = LD8(r1);
        } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    }
    v8 = 0;
    r2 = 0x3E7;
    if (!(v8 > 0x3E7)) {
        do {
            v8 = v8 + 1;
        } while (AGAIN(!(v8 > r2)));
    }
    r1 = LD32(0x06000310);
    r0 = GCALL5(r1, 148, r5, r6, r7, v8);
    ST8(0x20100063, 1);
    ST8(0x2010001F, 2);
    r0 = LD8(0x20100063);
    r0 = r0 & 1;
    r1 = 0x20100063;
    if (!((r0 & r0) == 0)) {
        do {
            r0 = LD8(r1);
            r0 = r0 & 1;
        } while (AGAIN(!((r0 & r0) == 0)));
    }
    r2 = 0x2608ACA8;
    do {
        r1 = LD32(r2);
    } while (AGAIN(!((r1 & r1) == 0)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602EC44(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r8, r9, c0, c3;

    r9 = r4;
    r8 = r5;
    r0 = LD32(0x06000330);
    r0 = GCALL2(r0, 3, r5);
    c0 = (r0 & r0) == 0;
    r0 = 0;
    if (!(c0)) {
        r2 = LD32(0x06078028);
        if ((r2 & r2) == 0) {
            r1 = LD32(0x06000334);
            r0 = GCALL1(r1, 3);
            r0 = LD32(0x060766C0);
        } else {
            r7 = 0x060759B4;
            while (1) {
                r3 = LD16(r2);
                r1 = r2;
                if (r3 > r9) {
                    r2 = LD32(r2 + 40);
                    if (!((r2 & r2) == 0)) {
                        POLL();
                        continue;
                    } else {
                        r1 = LD32(0x06000334);
                        r0 = GCALL1(r1, 3);
                        r0 = LD32(0x060766C0);
                        break;
                    }
                } else {
                    r1 = LD16((r1 + 4));
                    c3 = (r1 + r3) > r9;
                    r1 = r2;
                    if (!(c3)) {
                        r2 = LD32(r2 + 40);
                        if (!((r2 & r2) == 0)) {
                            POLL();
                            continue;
                        } else {
                            r1 = LD32(0x06000334);
                            r0 = GCALL1(r1, 3);
                            r0 = LD32(0x060766C0);
                            break;
                        }
                    } else {
                        r3 = LD16((r1 + 2));
                        r1 = LD32(r2 + 12);
                        if (!((r1 & r1) == 0)) {
                            r1 = LD32(r7);
                        }
                        r3 = (short)r3;
                        r1 = r2;
                        if (r3 > r8) {
                            r2 = LD32(r2 + 40);
                            if (!((r2 & r2) == 0)) {
                                POLL();
                                continue;
                            } else {
                                r1 = LD32(0x06000334);
                                r0 = GCALL1(r1, 3);
                                r0 = LD32(0x060766C0);
                                break;
                            }
                        } else {
                            r1 = LD16((r1 + 6));
                            if ((r1 + r3) > r8) {
                                POLL();
                                ST32(0x06078024, r2);
                                r1 = LD32(0x06000334);
                                r0 = GCALL4(r1, 3, 0, 0, r7);
                                r0 = 0;
                                break;
                            } else {
                                r2 = LD32(r2 + 40);
                                if (!((r2 & r2) == 0)) {
                                    POLL();
                                    continue;
                                } else {
                                    r1 = LD32(0x06000334);
                                    r0 = GCALL1(r1, 3);
                                    r0 = LD32(0x060766C0);
                                    break;
                                }
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
void f0602F540(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, c3, c4, c5, c6, c10;
    FRAME(sp, 32);

    r10 = r4;
    r8 = r5;
    r9 = r6;
    r0 = GCALL1(0x0602F1FC, (sp - 32));
    r1 = LD32(sp - 28);
    r2 = LD32(r9);
    if (r2 >= (r1 + 8)) {
        if (((0x400 & r10) & (0x400 & r10)) == 0) {
            if (!(((0x800 & r10) & (0x800 & r10)) == 0)) {
                r1 = LD32(r8);
                r1 = r1 + 8;
                ST32(r8, r1);
            }
        } else {
            r1 = LD32(r8);
            ST32(r8, (r1 - 16));
            r0 = LD16(0x0607802C);
            c3 = r0 == 15;
            if (r0 == 57) {
                r1 = LD32(r8);
                r1 = r1 - 16;
                ST32(r8, r1);
            } else {
                c4 = r0 == 30;
                if (c3) {
                    r1 = LD32(r8);
                    r1 = r1 - 16;
                    ST32(r8, r1);
                } else {
                    c5 = r0 == 44;
                    if (c4) {
                        r1 = LD32(r8);
                        r1 = r1 - 16;
                        ST32(r8, r1);
                    } else {
                        c6 = r0 == 58;
                        if (c5) {
                            r1 = LD32(r8);
                            r1 = r1 - 16;
                            ST32(r8, r1);
                        } else {
                            if (c6) {
                                r1 = LD32(r8);
                                r1 = r1 - 16;
                                ST32(r8, r1);
                            }
                        }
                    }
                }
            }
        }
        if (((0x1000 & r10) & (0x1000 & r10)) == 0) {
            if (!(((0x2000 & r10) & (0x2000 & r10)) == 0)) {
                r1 = LD32(r9);
                r1 = r1 + 10;
                ST32(r9, r1);
                r3 = LD32(sp - 20);
                c10 = r1 > (r3 - 12);
                r1 = r3;
                if (c10) {
                    r1 = r1 - 15;
                    ST32(r9, r1);
                }
            }
        } else {
            r1 = LD32(r8);
            ST32(r8, (r1 + 2));
            r1 = LD32(r9);
            r1 = r1 - 14;
            ST32(r9, r1);
        }
        r4 = LD32(r8);
        r1 = LD32(sp - 32);
        r10 = 0x0607802C;
        r5 = LD32(r9);
        r4 = r4 - r1;
        r1 = LD32(sp - 28);
        r0 = GCALL2(0x0602F218, r4, (r5 - r1));
        ST16(0x0607802C, r0);
        r0 = (short)r0;
        r2 = r0;
        if (!((r0 & r0) == 0)) {
            r1 = LD32(sp - 32);
            r2 = LD32((((r2 << 2) << 2) + 0x0602EE4C) + 8);
            ST32(r8, ((r1 + r2) - 8));
            r1 = LD16(r10);
            r2 = LD32(sp - 28);
            r1 = LD32((((r1 << 2) << 2) + 0x0602EE4C) + 12);
            ST32(r9, ((r2 + r1) - 5));
        }
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06022750(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 84);

    r12 = r4;
    ST32(sp - 64, ((short)r5));
    r14 = r6 & 0xFFFF;
    r9 = r7 & 0xFFFF;
    r1 = LD16(r12);
    ST16((sp - 68), r1);
    ST16(sp - 80, r1);
    r1 = LD16((r12 + 4));
    ST16((sp - 72), r1);
    ST16((sp - 76), r1);
    r6 = LD16((r12 + 6));
    r1 = LD16((r12 + 2));
    r8 = 0;
    r6 = (r6 - r1) + 1;
    r0 = GCALL5(0x0607286C, 0x200, (((r6 + 1) + ((int)((unsigned)(r6 + 1) >> 31))) >> 1), 0, 0, LD32((sp - 80)));
    r11 = (short)r0;
    r10 = (((int)((unsigned)r6 >> 31)) + r6) >> 1;
    ST32(sp - 36, (r6 - r10));
    if (!(0 >= r10)) {
        ST32(sp - 60, (sp - 78));
        ST32(sp - 56, (sp - 74));
        ST32(sp - 52, (sp - 70));
        do {
            r1 = LD16((r12 + 2));
            r1 = r1 + r8;
            ST16((sp - 66), r1);
            r0 = LD32(sp - 52);
            ST16(r0, r1);
            r13 = LD32(sp - 56);
            ST16(r13, r1);
            r0 = LD32(sp - 60);
            ST16(r0, r1);
            r13 = LD32((80 + (sp - 80)));
            r1 = r8;
            if ((r13 & r13) == 0) {
                r1 = (short)(((((r8 * r11) >> 1) >> 1) >> 1) >> 1);
                r13 = LD32(sp - 64);
                if (r1 > r9) {
                    r1 = (short)r9;
                }
            } else {
                r1 = (short)((((((r10 - (r1 + 1)) * r11) >> 1) >> 1) >> 1) >> 1);
                r13 = LD32(sp - 64);
                if (!(r1 >= r9)) {
                    r1 = (short)r9;
                }
            }
            ST32((sp - 84), 0xFFFF);
            r0 = GCALL6(0x06068D14, 0, 192, ((r14 | (r1 | r13)) & 0xFFFF), (sp - 80), LD32((sp - 84)), LD32((sp - 80)));
            r8 = r8 + 1;
        } while (AGAIN(!(r8 >= r10)));
    }
    r0 = LD32(sp - 36);
    r8 = 0;
    r13 = sp - 80;
    if (!(0 >= r0)) {
        ST32(sp - 48, (r13 + 2));
        ST32(sp - 44, (sp - 74));
        ST32(sp - 40, (sp - 70));
        r2 = sp - 80;
        do {
            r1 = LD16((r12 + 2));
            r1 = (r1 + r8) + r10;
            ST16((r2 + 14), r1);
            r0 = LD32(sp - 40);
            ST16(r0, r1);
            r13 = LD32(sp - 44);
            ST16(r13, r1);
            r0 = LD32(sp - 48);
            ST16(r0, r1);
            r13 = LD32((80 + (sp - 80)));
            r1 = r8;
            if ((r13 & r13) == 0) {
                r1 = (short)((-(((((r8 * r11) >> 1) >> 1) >> 1) >> 1)) + 31);
                r6 = r14;
                if (r1 > r9) {
                    r1 = (short)r9;
                }
            } else {
                r1 = (short)((-((((((r10 - (r1 + 1)) * r11) >> 1) >> 1) >> 1) >> 1)) + 31);
                r6 = r14;
                if (!(r1 >= r9)) {
                    r1 = (short)r9;
                }
            }
            r13 = LD32(sp - 64);
            ST32((sp - 84), 0xFFFF);
            r0 = GCALL6(0x06068D14, 0, 192, ((r6 | (r1 | r13)) & 0xFFFF), (sp - 80), LD32((sp - 84)), LD32((sp - 80)));
            r0 = LD32(sp - 36);
            r8 = r8 + 1;
            r2 = sp - 80;
        } while (AGAIN(!(r8 >= r0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B408(void)
{
    int r0, r1, r2, r3, r4, r5, r7, r8, r9, r10, r11, r12, c5, c9, c11;

    r8 = LD32(0x060769C8);
    r0 = 0;
    if (!((r8 & r8) == 0)) {
        r3 = LD32(r8 + 40);
        r9 = 0;
        if (!((r3 & r3) == 0)) {
            do {
                r1 = LD32(r3 + 20);
                ST32(r3 + 16, r1);
                r3 = LD32(r3 + 44);
                r9 = 0;
            } while (AGAIN(!((r3 & r3) == 0)));
        }
        r10 = 0;
        r3 = LD32(r8 + 40);
        r11 = 0;
        if (!((r3 & r3) == 0)) {
            do {
                r2 = LD32(r3 + 16);
                r7 = LD32(r3 + 24);
                r9 = r9 + r2;
                if (!(r2 >= r7)) {
                    r1 = LD32(r3 + 28);
                    c5 = (r1 & r1) == 0;
                    r1 = r7;
                    if (c5) {
                        r10 = r10 + (r1 - r2);
                        r11 = r11 + 1;
                    }
                }
                r3 = LD32(r3 + 44);
            } while (AGAIN(!((r3 & r3) == 0)));
        }
        ST32(r8 + 28, r9);
        r0 = GCALL0(0x0602B0B0);
        r1 = LD32(r8 + 28);
        r12 = r0;
        ST32(r8 + 28, (r1 + r12));
        r1 = LD32(r8 + 24);
        r2 = r1 - r12;
        if (r11 > 0) {
            c9 = r9 >= r2;
            r2 = r2 - r9;
            if (!(c9)) {
                r1 = r8;
                if (!(r2 >= r10)) {
                    r10 = r2;
                    r1 = r8;
                } else {
                    r1 = LD32((r1 + 104));
                    c11 = (r1 & r1) == 0;
                    r1 = r8;
                    if (!(c11)) {
                        r10 = r2;
                        r1 = r8;
                    }
                }
                r7 = LD32((r1 + 104));
                r5 = LD32(r8 + 52);
                r4 = LD32(r8 + 40);
                r0 = GCALL4(0x0602AF00, r4, r5, r10, r7);
                r3 = LD32(r8 + 40);
                ST32(r8 + 28, 0);
                if (!((r3 & r3) == 0)) {
                    do {
                        r1 = LD32(r8 + 28);
                        r2 = LD32(r3 + 16);
                        ST32(r8 + 28, (r1 + r2));
                        r3 = LD32(r3 + 44);
                    } while (AGAIN(!((r3 & r3) == 0)));
                }
                r1 = LD32(r8 + 28);
                ST32(r8 + 28, (r1 + r12));
            }
            r0 = 1;
        } else {
            r1 = LD32((r8 + 104));
            r0 = 1;
            if (!((r1 & r1) == 0)) {
                c9 = r9 >= r2;
                r2 = r2 - r9;
                if (!(c9)) {
                    r1 = r8;
                    if (!(r2 >= r10)) {
                        r10 = r2;
                        r1 = r8;
                    } else {
                        r1 = LD32((r1 + 104));
                        c11 = (r1 & r1) == 0;
                        r1 = r8;
                        if (!(c11)) {
                            r10 = r2;
                            r1 = r8;
                        }
                    }
                    r7 = LD32((r1 + 104));
                    r5 = LD32(r8 + 52);
                    r4 = LD32(r8 + 40);
                    r0 = GCALL4(0x0602AF00, r4, r5, r10, r7);
                    r3 = LD32(r8 + 40);
                    ST32(r8 + 28, 0);
                    if (!((r3 & r3) == 0)) {
                        do {
                            r1 = LD32(r8 + 28);
                            r2 = LD32(r3 + 16);
                            ST32(r8 + 28, (r1 + r2));
                            r3 = LD32(r3 + 44);
                        } while (AGAIN(!((r3 & r3) == 0)));
                    }
                    r1 = LD32(r8 + 28);
                    ST32(r8 + 28, (r1 + r12));
                }
                r0 = 1;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602FFD0(int r4)
{
    int r0, r8, r9;

    r8 = r4;
    r0 = GCALL2(0x0607286C, 0xAC44, (r8 + 1));
    r9 = LD8(r0 + 0x0602FA7C);
    r0 = GCALL2(0x06074734, 0xAC44, r9);
    r0 = GCALL2(0x0607286C, (((r8 - r0) << 8) << 2), r0);
    return (0x3FF & r0) | (((((-r9) & 15) << 8) + (((-r9) & 15) << 8)) << 2);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602A150(int r4)
{
    int r0, r1, r2, r6, r7, c1;

    r6 = LD32(0x060769C8);
    c1 = (r4 & r4) == 0;
    if ((r6 & r6) == 0) {
        return 0;
    } else {
        r1 = r4;
        if (!(c1)) {
            r1 = LD32((r1 + 68));
            r2 = LD32((r4 + 64));
            r1 = r1 - r2;
            r2 = LD32(r6 + 28);
            r2 = r1 - r2;
            r0 = LD32((r6 + 124));
            r1 = 4;
            if (r0 == -1) {
                r0 = LD32((r4 + 104));
                r1 = 4;
            }
            r7 = r0 + 1;
            if ((unsigned)r7 > (unsigned)r1) {
                r1 = LD32((r4 + 64));
            } else {
                r1 = LD16(0x0602A1A0 + (r7 + r7));
                switch (r1) {
                case 10:
                    r1 = LD32((r4 + 64));
                    break;
                case 18:
                    r1 = r4;
                    if (r2 > 1) {
                        r1 = LD32((r4 + 64));
                        r2 = (r2 + ((int)((unsigned)r2 >> 31))) >> 1;
                        r1 = r1 + r2;
                    } else {
                        r1 = LD32((r1 + 64));
                    }
                    break;
                case 50:
                    r1 = r4;
                    if (r2 > 0) {
                        r1 = LD32((r1 + 64));
                        r1 = r1 + r2;
                    } else {
                        r1 = LD32((r1 + 64));
                    }
                    break;
                }
            }
            ST32(r6, r1);
            return 1;
        } else {
            return 0;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06021990(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, r14, c5, c1010;

    r8 = 0;
    r0 = GCALL4(0x0601CB70, 0, r5, r6, r7);
    r9 = r0;
    r14 = 1;
    if (!((r9 & r9) == 0)) {
        r13 = 0;
        r12 = 0x060255E0;
        r11 = 0x060765BC;
        do {
            r4 = LD32(r9 + 56);
            r10 = LD32(r9 + 52);
            if ((r4 & r4) == 0) {
                r9 = r10;
                c1010 = (r10 & r10) == 0;
            } else {
                r1 = LD8(r4);
                if (!((unsigned)(r1 & 255) > (unsigned)r14)) {
                    r1 = LD32(r11);
                    if ((r1 & r1) == 0) {
                        r0 = GCALL1(0x06025948, (r9 + 60));
                        r1 = r0;
                        c5 = r1 > 0;
                        r7 = c5;
                        if (c5) {
                            r0 = GCALL4(0x060279E0, 1, r1, 2, r7);
                            if (!((r0 & r0) == 0)) {
                                r1 = LD32(r9 + 56);
                                ST32(r11, r1);
                                r1 = LD32(r9 + 56);
                                ST32(r9 + 16, r0);
                                ST32(r1 + 8, r0);
                                r4 = LD32(r9 + 56);
                                r0 = GCALL1(0x060259B4, r4);
                            }
                        }
                    }
                    r9 = r10;
                    c1010 = (r10 & r10) == 0;
                } else {
                    r0 = GCALL1(0x06027F48, r4);
                    r8 = LD32(r9 + 16);
                    ST32(r9 + 56, r13);
                    r0 = GCALL1(r12, (r8 + 18));
                    ST32(r9 + 24, r0);
                    r0 = GCALL1(r12, (r8 + 22));
                    ST32(r9 + 28, r0);
                    ST32(r11, r13);
                    r8 = r14;
                    r0 = GCALL0(0x0601CB88);
                    r0 = GCALL1(0x06021780, r9);
                    r9 = r10;
                    r0 = GCALL0(0x0601CB70);
                    c1010 = (r9 & r9) == 0;
                }
            }
        } while (AGAIN(!(c1010)));
    }
    r0 = GCALL0(0x0601CB88);
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06023B1C(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r10, r11, r12, c3, c5, c9, c11, c13, c16, c22, c23, c36, c1052;

    r0 = r4;
    r12 = r5;
    r11 = LD32(r12);
    if (!(r0 == 4)) {
        r10 = 1;
        if (((0x200 & r11) & (0x200 & r11)) == 0) {
            r1 = 4;
            if (((2 & r11) & (2 & r11)) == 0) {
                c9 = ((r1 & r11) & (r1 & r11)) == 0;
                r1 = 8;
                if (c9) {
                    c11 = ((r1 & r11) & (r1 & r11)) == 0;
                    r1 = 16;
                    if (c11) {
                        c16 = ((r1 & r11) & (r1 & r11)) == 0;
                        r1 = 32;
                        if (c16) {
                            c22 = ((r1 & r11) & (r1 & r11)) == 0;
                            r1 = 64;
                            if (c22) {
                                if (((r1 & r11) & (r1 & r11)) == 0) {
                                    r10 = 0;
                                    if (!(((0x100 & r11) & (0x100 & r11)) == 0)) {
                                        r4 = 0x06078024;
                                        r2 = LD32(0x06078024);
                                        r1 = LD32(r2 + 36);
                                        r2 = r2 + 28;
                                        if (!((r1 & r1) == 0)) {
                                            r1 = 23;
                                            ST8(r2, r1);
                                            r4 = LD32(r4);
                                            r1 = LD32(r4 + 36);
                                            r0 = GCALL2(r1, r4, r5);
                                            r10 = 0;
                                        }
                                    }
                                } else {
                                    r4 = 0x06078024;
                                    r2 = LD32(0x06078024);
                                    r1 = LD32(r2 + 36);
                                    r2 = r2 + 28;
                                    if (!((r1 & r1) == 0)) {
                                        r1 = 22;
                                        ST8(r2, r1);
                                        r4 = LD32(r4);
                                        r1 = LD32(r4 + 36);
                                        r0 = GCALL2(r1, r4, r5);
                                    }
                                    r10 = 0;
                                }
                            } else {
                                r2 = LD32(0x06078024);
                                r1 = LD32(r2 + 36);
                                c23 = (r1 & r1) == 0;
                                r1 = r2;
                                if (!(c23)) {
                                    r0 = LD16((r1 + 32));
                                    r1 = r2;
                                    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                                        r2 = r2 + 28;
                                        r1 = 13;
                                    } else {
                                        r0 = LD8((r1 + 29));
                                        r1 = 9;
                                        if (((r0 & 1) & (r0 & 1)) == 0) {
                                            r2 = r2 + 28;
                                        } else {
                                            r2 = r2 + 28;
                                            r1 = 13;
                                        }
                                    }
                                    ST8(r2, r1);
                                    r4 = LD32(0x06078024);
                                    r1 = LD32(r4 + 36);
                                    r0 = GCALL2(r1, r4, r5);
                                }
                                r1 = LD32(0x06078024);
                                r2 = r1 + 29;
                                r3 = LD8(r2);
                                r0 = r3;
                                if (!(((1 & r3) & (1 & r3)) == 0)) {
                                    r0 = r0 ^ 1;
                                    ST8(r2, r0);
                                }
                                r10 = 0;
                            }
                        } else {
                            r2 = LD32(0x06078024);
                            r0 = LD16((r2 + 32));
                            r1 = r2;
                            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                                r2 = r2 + 28;
                                r1 = 47;
                            } else {
                                r0 = LD8((r1 + 29));
                                r1 = 32;
                                if (((r0 & 1) & (r0 & 1)) == 0) {
                                    r2 = r2 + 28;
                                } else {
                                    r2 = r2 + 28;
                                    r1 = 47;
                                }
                            }
                            ST8(r2, r1);
                            r1 = LD32(0x06078024);
                            r4 = LD32(r1 + 20);
                            r0 = GCALL1(0x0607507C, r4);
                            r1 = LD32(0x06078024);
                            r3 = r0 + 1;
                            r1 = LD32(r1 + 20);
                            ST8(((r1 + r3) + 1), 0);
                            r1 = LD32(0x06078024);
                            r1 = LD16((r1 + 24));
                            r2 = 0x06078024;
                            if (r3 > r1) {
                                do {
                                    r1 = LD32(r2);
                                    r0 = LD32(r1 + 20);
                                    r1 = LD8(((r3 + r0) - 1));
                                    ST8(r0 + r3, r1);
                                    r1 = LD32(r2);
                                    r1 = LD16((r1 + 24));
                                    r3 = r3 - 1;
                                } while (AGAIN(r3 > r1));
                            }
                            r1 = LD32(0x06078024);
                            r3 = LD16((r1 + 24));
                            r2 = LD32(r1 + 20);
                            r1 = LD8((r1 + 28));
                            ST8(r2 + r3, r1);
                            r4 = LD32(0x06078024);
                            r2 = r4 + 24;
                            r1 = LD16(r2);
                            ST16(r2, (r1 + 1));
                            r1 = LD32(r4 + 36);
                            r10 = 0;
                            r0 = GCALL2(r1, r4, r5);
                            r0 = GCALL1(0x06032164, 9);
                            r1 = LD32(0x06078024);
                            r2 = r1 + 29;
                            r3 = LD8(r2);
                            r0 = r3;
                            if (!(((1 & r3) & (1 & r3)) == 0)) {
                                r0 = r0 ^ 1;
                                ST8(r2, r0);
                            }
                        }
                        c1052 = (r10 & r10) == 0;
                    } else {
                        r8 = 0x06078024;
                        r2 = LD32(0x06078024);
                        r1 = LD8((r2 + 30));
                        c13 = (r10 & r10) == 0;
                        if ((r1 & r1) == 0) {
                            r0 = LD16((r2 + 32));
                            if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                                r1 = LD16((r2 + 24));
                                r4 = LD32(r2 + 20);
                                r0 = GCALL2(0x060750DC, (r4 + r1), 0x06079CF8);
                                r8 = LD32(r8);
                                r8 = r8 + 24;
                                r0 = GCALL1(0x0607507C, 0x06079CF8);
                                r1 = LD16(r8);
                                ST16(r8, (r1 + r0));
                            } else {
                                r0 = LD8((r2 + 29));
                                if (((r0 & 1) & (r0 & 1)) == 0) {
                                    r2 = LD32(r2 + 20);
                                    r3 = LD8(0x06023B10);
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B11);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B12);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B13);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B14);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B15);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B16);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B17);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B18);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B19);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r3 = LD8(0x06023B1A);
                                    r2 = r2 + 1;
                                    ST8(r2, r3);
                                    r1 = LD8(0x06023B1B);
                                    ST8((r2 + 1), r1);
                                    r1 = LD32(r8);
                                    ST16((r1 + 24), 11);
                                } else {
                                    r1 = LD16((r2 + 24));
                                    r4 = LD32(r2 + 20);
                                    r0 = GCALL2(0x060750DC, (r4 + r1), 0x06079CF8);
                                    r8 = LD32(r8);
                                    r8 = r8 + 24;
                                    r0 = GCALL1(0x0607507C, 0x06079CF8);
                                    r1 = LD16(r8);
                                    ST16(r8, (r1 + r0));
                                }
                            }
                            r0 = GCALL1(0x06032164, 9);
                            r1 = LD32(0x06078024);
                            r2 = r1 + 29;
                            r3 = LD8(r2);
                            r0 = r3;
                            if (!(((1 & r3) & (1 & r3)) == 0)) {
                                r0 = r0 ^ 1;
                                ST8(r2, r0);
                            }
                            c1052 = (r10 & r10) == 0;
                        } else {
                            c1052 = c13;
                        }
                    }
                } else {
                    r1 = LD32(0x06078024);
                    r1 = r1 + 29;
                    r0 = LD8(r1);
                    ST8(r1, (r0 ^ 1));
                    r0 = GCALL1(0x06032164, 9);
                    c1052 = (r10 & r10) == 0;
                }
            } else {
                r0 = GCALL1(0x06032164, 9);
                r3 = 0x06078024;
                r2 = LD32(0x06078024);
                r1 = LD32(r2 + 36);
                c5 = (r1 & r1) == 0;
                r1 = r2;
                if (!(c5)) {
                    ST8((r1 + 28), 8);
                    r2 = LD32(r3);
                    r0 = LD16((r2 + 32));
                    if (((r0 & 1) & (r0 & 1)) == 0) {
                        r0 = LD8((r2 + 29));
                        r2 = r2 + 28;
                        if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                            ST8(r2, -115);
                            r1 = LD32(r3);
                            r1 = r1 + 29;
                            r0 = LD8(r1);
                            ST8(r1, (r0 ^ 1));
                        }
                    } else {
                        ST8((r2 + 28), -115);
                    }
                    r4 = LD32(0x06078024);
                    r1 = LD32(r4 + 36);
                    r0 = GCALL1(r1, r4);
                    c1052 = (r10 & r10) == 0;
                } else {
                    c1052 = (r10 & r10) == 0;
                }
            }
        } else {
            r1 = LD32(0x06089B00);
            c3 = (r10 & r10) == 0;
            if (!(r1 >= 0)) {
                r0 = GCALL1(0x06032164, 5);
                ST32(0x06078020, -100);
                r10 = 0;
                c1052 = (r10 & r10) == 0;
            } else {
                c1052 = c3;
            }
        }
        if (c1052) {
            ST32(r12, r11);
        } else {
            r4 = 0x06078024;
            r2 = LD32(0x06078024);
            r1 = LD32(r2 + 36);
            r2 = r2 + 28;
            if ((r1 & r1) == 0) {
                ST32(r12, r11);
            } else {
                ST8(r2, 0);
                r4 = LD32(r4);
                r1 = LD32(r4 + 36);
                r0 = GCALL1(r1, r4);
                ST32(r12, r11);
            }
        }
    } else {
        if (!(((0x200 & r11) & (0x200 & r11)) == 0)) {
            r1 = LD32(0x06089B00);
            r2 = -100;
            if (!(r1 >= 0)) {
                ST32(0x06078020, r2);
                r0 = GCALL1(0x06032164, 5);
            }
        }
        if (!(((128 & r11) & (128 & r11)) == 0)) {
            r0 = GCALL1(0x06032164, 9);
            r3 = 0x06078024;
            r2 = LD32(0x06078024);
            r1 = LD32(r2 + 36);
            c36 = (r1 & r1) == 0;
            r1 = r2;
            if (!(c36)) {
                ST8((r1 + 28), 8);
                r2 = LD32(r3);
                r0 = LD16((r2 + 32));
                if (((r0 & 1) & (r0 & 1)) == 0) {
                    r0 = LD8((r2 + 29));
                    r2 = r2 + 28;
                    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                        ST8(r2, -115);
                        r1 = LD32(r3);
                        r1 = r1 + 29;
                        r0 = LD8(r1);
                        ST8(r1, (r0 ^ 1));
                    }
                } else {
                    ST8((r2 + 28), -115);
                }
                r4 = LD32(0x06078024);
                r1 = LD32(r4 + 36);
                r0 = GCALL1(r1, r4);
            }
        }
        if (!(((0x100 & r11) & (0x100 & r11)) == 0)) {
            r1 = LD32(0x06078024);
            r1 = r1 + 29;
            r0 = LD8(r1);
            r0 = r0 ^ 1;
            ST8(r1, r0);
            r11 = r11 & -129;
        }
        ST32(r12, r11);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602AB50(void)
{
    int r1, r2, r3, c1010;

    r3 = LD32(0x060769C8);
    r1 = r3;
    if (!((r3 & r3) == 0)) {
        r1 = LD32((r1 + 76));
        if (!((r1 & r1) == 0)) {
            r2 = LD32(r1 + 56);
            while (1) {
                c1010 = (r2 & r2) == 0;
                r1 = r2;
                if (!(c1010)) {
                    POLL();
                    r1 = LD8((r1 + 65));
                    if (((r1 & 255) & (r1 & 255)) == 0) {
                        POLL();
                        ST32((r3 + 76), r2);
                        return 1;
                    } else {
                        r2 = LD32(r2 + 56);
                        continue;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            r1 = LD32(r3 + 60);
            if ((r1 & r1) == 0) {
                POLL();
                return 0;
            } else {
                r2 = LD32(r1 + 16);
                c1010 = (r2 & r2) == 0;
                r1 = r2;
                if (!(c1010)) {
                    POLL();
                    r1 = LD8((r1 + 65));
                    if (((r1 & 255) & (r1 & 255)) == 0) {
                        POLL();
                        ST32((r3 + 76), r2);
                        return 1;
                    } else {
                        r2 = LD32(r2 + 56);
                        while (1) {
                            c1010 = (r2 & r2) == 0;
                            r1 = r2;
                            if (!(c1010)) {
                                POLL();
                                r1 = LD8((r1 + 65));
                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                    POLL();
                                    ST32((r3 + 76), r2);
                                    return 1;
                                } else {
                                    r2 = LD32(r2 + 56);
                                    continue;
                                }
                            } else {
                                return 0;
                            }
                        }
                    }
                } else {
                    return 0;
                }
            }
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06021724(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, c3, c1001;

    r0 = r4;
    r6 = 3;
    r5 = ((int)((unsigned)r0 >> 8)) & 255;
    r3 = 0;
    r7 = 0x270F;
    r4 = 4 & r0;
    c1001 = (r4 & r4) == 0;
    while (1) {
        r0 = r3;
        if (c1001) {
            r0 = r0 << 2;
            r1 = 0x06076584;
        } else {
            r1 = 0x060765A0;
            r0 = r0 << 2;
        }
        r1 = LD32(r0 + r1);
        r1 = r1 - r5;
        r2 = r1;
        if (!(r1 >= 0)) {
            r2 = -r1;
        }
        r1 = r2;
        c3 = (r1 & r1) == 0;
        if (r1 >= r7) {
            r3 = r3 + 1;
            c1001 = (r4 & r4) == 0;
            if (!(r3 > 6)) {
                POLL();
                continue;
            } else {
                return r6 + 1;
            }
        } else {
            r6 = r3;
            if (!(c3)) {
                r7 = r1;
                r3 = r3 + 1;
                c1001 = (r4 & r4) == 0;
                if (!(r3 > 6)) {
                    POLL();
                    continue;
                } else {
                    return r6 + 1;
                }
            } else {
                return r6 + 1;
            }
        }
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06021780(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14, c7, c8, c1015;

    r11 = r4;
    r2 = 1;
    ST8((r11 + 6), 1);
    r1 = LD32(r11 + 12);
    r0 = 1;
    if ((r1 & r1) == 0) {
        r1 = LD32(r11 + 56);
        r0 = 0;
        if ((r1 & r1) == 0) {
            r1 = LD32(r11 + 16);
            r12 = r1;
            if (!((r1 & r1) == 0)) {
                r14 = r11 + 5;
                ST8(r14, r2);
                r13 = LD32(r11 + 16);
                r9 = 0x060255E0;
                r0 = GCALL1(0x060255E0, (r13 + 30));
                r1 = LD32(r11 + 8);
                ST32(r11 + 20, (((r0 & r0) == 0) ^ 1));
                if (!((r1 & r1) == 0)) {
                    r0 = GCALL1(0x060255E0, (r13 + 18));
                    ST32(r11 + 24, r0);
                    r0 = GCALL1(0x060255E0, (r13 + 22));
                    ST32(r11 + 28, r0);
                    r0 = GCALL2(0x06042A20, r13, 0);
                    ST32(r11 + 12, r0);
                    if ((r0 & r0) == 0) {
                        ST8((r11 + 5), 0);
                        POLL();
                        r0 = 0;
                    } else {
                        r0 = GCALL2(0x06021318, r11, r13);
                        r1 = 0;
                        if (!((r0 & r0) == 0)) {
                            ST32(r11 + 16, r1);
                            ST8((r11 + 5), 0);
                            if (!((r12 & r12) == 0)) {
                                r0 = GCALL1(0x06027F48, r12);
                            }
                            r0 = 1;
                        } else {
                            ST8((r11 + 5), 0);
                            POLL();
                            r0 = 0;
                        }
                    }
                } else {
                    r0 = GCALL3(r9, (r13 + 10), r5, r6);
                    r8 = r0;
                    r0 = GCALL1(r9, (r13 + 34));
                    r9 = r12 + (r8 + r0);
                    r0 = GCALL4(0x060279E0, 0, 0x100, 1, 1);
                    r10 = r0;
                    r8 = 0;
                    if (!((r10 & r10) == 0)) {
                        ST32(r11 + 8, r10);
                        r14 = 255;
                        do {
                            r0 = GCALL1(0x06025618, r9);
                            r1 = r0;
                            r0 = r10;
                            ST8(r0 + r8, r1);
                            r8 = r8 + 1;
                            r9 = r9 + 2;
                        } while (AGAIN(!(r8 > r14)));
                        r1 = LD8(r0);
                        r2 = (int)((unsigned)((r1 & 255) + 3) >> 2);
                        ST32(r11 + 32, r2);
                        r1 = LD8((r0 + 1));
                        ST32(r11 + 36, (((int)((unsigned)((r1 & 255) + 3) >> 2)) + r2));
                        r1 = LD8((r10 + 2));
                        ST32(r11 + 44, (r1 & 255));
                        r1 = LD8((r10 + 77));
                        ST32(r11 + 40, ((int)((unsigned)(r1 & 255) >> 2)));
                        r0 = GCALL1(0x060255E0, (r13 + 18));
                        ST32(r11 + 24, r0);
                        r0 = GCALL1(0x060255E0, (r13 + 22));
                        ST32(r11 + 28, r0);
                        r0 = GCALL2(0x06042A20, r13, 0);
                        ST32(r11 + 12, r0);
                        if ((r0 & r0) == 0) {
                            ST8((r11 + 5), 0);
                            POLL();
                            r0 = 0;
                        } else {
                            r0 = GCALL2(0x06021318, r11, r13);
                            r1 = 0;
                            if (!((r0 & r0) == 0)) {
                                ST32(r11 + 16, r1);
                                ST8((r11 + 5), 0);
                                if (!((r12 & r12) == 0)) {
                                    r0 = GCALL1(0x06027F48, r12);
                                }
                                r0 = 1;
                            } else {
                                ST8((r11 + 5), 0);
                                POLL();
                                r0 = 0;
                            }
                        }
                    } else {
                        ST8(r14, 0);
                        POLL();
                        r0 = 0;
                    }
                }
            } else {
                r10 = r11 + 60;
                r0 = GCALL4(0x06025948, r10, 0, r6, r7);
                r9 = r0;
                r0 = 0;
                if (r9 > 0) {
                    r13 = 0x060279E0;
                    r0 = GCALL4(0x060279E0, 0, 48, -1, 1);
                    r8 = r0;
                    r7 = r9;
                    if ((r8 & r8) == 0) {
                        r0 = 0;
                    } else {
                        r0 = GCALL4(0x060258EC, r10, r8, 0, r7);
                        r4 = r8;
                        if ((r0 & r0) == 0) {
                            ST8(r8, 0);
                            ST32(r11 + 56, r8);
                            r1 = LD32(0x060765BC);
                            r0 = 0;
                            if ((r1 & r1) == 0) {
                                r0 = GCALL4(r13, 1, r9, 2, 0);
                                r12 = r0;
                                c7 = (r12 & r12) == 0;
                                r5 = c7;
                                c1015 = c7;
                                if (c7) {
                                    r0 = GCALL2(0x0601CE48, 2, r5);
                                    r0 = GCALL4(r13, 1, r9, 2, 0);
                                    r12 = r0;
                                    c8 = (r12 & r12) == 0;
                                    r5 = 2;
                                    c1015 = c8;
                                    if (c8) {
                                        r0 = GCALL2(0x06028380, r9, r5);
                                        r12 = r0;
                                        c1015 = (r12 & r12) == 0;
                                    }
                                }
                                r4 = r8;
                                if (!(c1015)) {
                                    ST32(r11 + 16, r12);
                                    r1 = LD32(r11 + 56);
                                    ST32(r1 + 8, r12);
                                    ST32(0x060765BC, r8);
                                    r1 = 0x060259B4;
                                    r0 = GCALL1(r1, r4);
                                    r0 = 0;
                                } else {
                                    r0 = GCALL1(0x06027F48, r8);
                                    ST32(r11 + 56, 0);
                                    r0 = 0;
                                }
                            }
                        } else {
                            r1 = 0x06027F48;
                            r0 = GCALL1(r1, r4);
                            r0 = 0;
                        }
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06022690(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, c2, c1005, c1008, c1010;
    FRAME(sp, 28);

    r10 = r4;
    r12 = r5;
    r11 = r6;
    r13 = r7;
    r9 = LD32(sp);
    r0 = GCALL1(0x0607507C, r12);
    r0 = GCALL3(0x060221DC, r12, 0, (r0 - 1));
    r8 = r0;
    if ((r10 & r10) == 0) {
        r1 = 0;
        if (r8 > r9) {
            r1 = r9 - r8;
        }
    } else {
        r2 = r10 + 26;
        r1 = LD16(r2);
        c2 = r8 > r9;
        if (!((r1 + r8) >= r9)) {
            r1 = r9;
            if (!(c2)) {
                r1 = 0;
                c1005 = 0;
            } else {
                r1 = r1 - r8;
                c1005 = 1;
            }
            ST16(r2, r1);
        }
        r6 = LD16((r10 + 24));
        r0 = GCALL3(0x060221DC, r12, 0, (r6 - 1));
        r3 = r10 + 26;
        r1 = LD16(r3);
        r0 = r0 + r1;
        c1008 = r0 >= 0;
        if (r0 > r9) {
            r0 = r0 - r1;
            r1 = r9 - r8;
            ST16(r3, r1);
            r0 = r0 + ((short)r1);
            c1008 = r0 >= 0;
        }
        c1010 = c1008;
        if (!(c1008)) {
            r1 = LD16(r3);
            ST16(r3, (r1 - r0));
            c1010 = 0;
        }
        ST16((r10 + 8), (r0 + r11));
        r1 = LD16(r3);
    }
    r0 = GCALL4(0x0602220C, r12, (r11 + r1), r13, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602464C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, c2, c6, c9, c13, c17, c21, c1014, c1016, c1019, c1021;
    FRAME(sp, 4);

    r2 = LD32(0x060759B4);
    r3 = 0x060759B8;
    r1 = LD32(0x060759B8);
    r8 = r4;
    r4 = LD32(sp);
    if (!(r2 == r1)) {
        c1019 = r6 >= 0;
    } else {
        c2 = (r7 & r7) == 0;
        if (r8 == 4) {
            r0 = r4;
            if (!(r4 == 224)) {
                c1014 = r7 > 0;
                if (r0 == 16) {
                    r2 = 0x060759C4;
                    r1 = LD32(0x060759C4);
                    c13 = r7 > 0;
                    c1014 = c13;
                    if ((r1 & r1) == 0) {
                        r1 = LD32(r2);
                        r1 = r1 - 16;
                        ST32(r2, r1);
                        c1014 = r7 > 0;
                    }
                }
            } else {
                r2 = 0x060759C4;
                r1 = LD32(0x060759C4);
                c9 = r7 > 0;
                c1014 = c9;
                if ((r1 & r1) == 0) {
                    r1 = LD32(r2);
                    r1 = r1 + 16;
                    ST32(r2, r1);
                    c1014 = r7 > 0;
                }
            }
        } else {
            c1014 = r7 > 0;
            if (c2) {
                if (!(((64 & r5) & (64 & r5)) == 0)) {
                    r1 = LD32(r3);
                    ST32(r3, (r1 + 16));
                    ST32(0x060759C4, 144);
                }
                c6 = r7 > 0;
                c1014 = c6;
                if (!(((0x100 & r5) & (0x100 & r5)) == 0)) {
                    r1 = LD32(r3);
                    r2 = 0x060759C4;
                    ST32(r3, (r1 - 16));
                    r1 = -144;
                    ST32(r2, r1);
                    c1014 = r7 > 0;
                }
            }
        }
        c1016 = r7 >= 0;
        if (c1014) {
            r1 = LD32(0x060759B8);
            ST32(0x060759B8, (r1 + 16));
            c1016 = r7 >= 0;
        }
        c17 = r6 >= 0;
        c1019 = c17;
        if (!(c1016)) {
            r1 = LD32(0x060759B8);
            ST32(0x060759B8, (r1 - 16));
            c1019 = r6 >= 0;
        }
    }
    c1021 = r6 > 0;
    if (!(c1019)) {
        r1 = LD32(0x060759CC);
        ST32(0x060759CC, (r1 - 4));
        c1021 = r6 > 0;
    }
    if (c1021) {
        r1 = LD32(0x060759CC);
        ST32(0x060759CC, (r1 + 4));
    }
    r2 = 0x060759CC;
    r1 = LD32(0x060759CC);
    c21 = r1 >= 0;
    r1 = 0;
    if (!(c21)) {
        ST32(r2, r1);
    }
    r1 = LD32(r2);
    r3 = 0x180;
    if (r1 > 0x180) {
        ST32(r2, r3);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060261A4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, c1, c1002;

    r8 = r4;
    r0 = GCALL4(0x06025A0C, 2, r5, r6, r7);
    r1 = LD32(0x060769B0);
    c1 = r1 == r8;
    if ((r1 & r1) == 0) {
        r1 = LD32(0x06000334);
        r0 = GCALL1(r1, 2);
        r0 = 0;
    } else {
        r2 = 0x06000334;
        c1002 = c1;
        while (1) {
            if (!(c1002)) {
                r1 = LD32(r1);
                c1002 = r1 == r8;
                if (!((r1 & r1) == 0)) {
                    POLL();
                    continue;
                } else {
                    r1 = LD32(0x06000334);
                    r0 = GCALL1(r1, 2);
                    r0 = 0;
                    break;
                }
            } else {
                r1 = LD32(r2);
                r0 = GCALL1(r1, 2);
                r0 = 1;
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06026A1C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, c7, c1016;

    r9 = r4;
    r8 = 0;
    ST32(r9 + 32, 0);
    r12 = 236;
    r0 = r9;
    r2 = LD32(r0 + 236);
    if (!((r2 & r2) == 0)) {
        r2 = LD32(r2);
        r3 = 192;
        r1 = LD32(r0 + 192);
        if (r2 == r1) {
            ST32(r0 + r3, r8);
        }
        r2 = 228;
        r0 = r9;
        r1 = LD32(r0 + 228);
        if (!((r1 & r1) == 0)) {
            ST32(r0 + r2, r8);
            ST32(r0 + 232, r8);
            r0 = r9;
        }
        r4 = LD32(r0 + r12);
        r0 = GCALL4(0x0601F2FC, r4, r5, r6, r7);
        r10 = 0x06027F48;
        r4 = LD32(r9 + r12);
        r0 = GCALL1(0x06027F48, r4);
        r13 = 240;
        r4 = LD32(r9 + 240);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(r10, r4);
        }
        r11 = 244;
        r0 = r9;
        r4 = LD32(r0 + 244);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(r10, r4);
            r0 = r9;
        }
        ST32(r0 + r12, r8);
        ST32(r0 + r13, r8);
        ST32(r0 + r11, r8);
    }
    r2 = 228;
    r0 = r9;
    r1 = LD32(r0 + 228);
    if ((r1 & r1) == 0) {
        r8 = 192;
        r4 = LD32(r9 + 192);
        c1016 = (r4 & r4) == 0;
    } else {
        r10 = 232;
        r1 = LD32(r0 + 232);
        r8 = 0;
        if (!((r1 & r1) == 0)) {
            ST32(r0 + r2, r8);
            r4 = LD32(r0 + r10);
            r0 = GCALL1(0x06027F48, r4);
            ST32(r9 + r10, r8);
        }
        r8 = 192;
        r4 = LD32(r9 + 192);
        c7 = (r4 & r4) == 0;
        c1016 = c7;
        if (!(c7)) {
            r0 = GCALL1(0x0601F1D0, r4);
            ST32(r9 + r8, 0);
            ST32(r9 + 12, 0);
            ST32(r9 + 8, 0);
            r8 = 192;
            r4 = LD32(r9 + 192);
            c1016 = (r4 & r4) == 0;
        }
    }
    if (!(c1016)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r9 + r8, 0);
        ST32(r9 + 12, 0);
        ST32(r9 + 8, 0);
    }
    r8 = 248;
    r4 = LD32(r9 + 248);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x0603AD94, r4);
        r4 = LD32(r9 + r8);
        r0 = GCALL1(0x06027F48, r4);
        ST32(r9 + r8, 0);
    }
    r8 = 0x110;
    r0 = r9;
    r4 = LD32(r0 + 0x110);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        r0 = r9;
        ST32(r0 + r8, 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06026B64(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, c1, c6, c8, c11, c1004, c1007;

    r8 = r4;
    r0 = GCALL4(0x06025A0C, 2, r5, r6, r7);
    r0 = GCALL1(0x06025AE0, r8);
    r0 = GCALL0(0x06028254);
    if (!((r0 & r0) == 0)) {
        r0 = GCALL1(0x0602BA00, 0x06026B44);
    }
    r1 = LD32(0x060769B0);
    c1 = (r1 & r1) == 0;
    r2 = 0;
    c1007 = c1;
    if (!(c1)) {
        c1004 = r1 == r8;
        do {
            r2 = r1;
            r1 = LD32(r2);
            c1004 = r1 == r8;
        } while (AGAIN(!((r1 & r1) == 0)));
        c1007 = (r1 & r1) == 0;
    }
    c6 = (r2 & r2) == 0;
    if (!(c1007)) {
        r1 = LD32(r1);
        if (c6) {
            r2 = 0x060769B0;
        }
        ST32(r2, r1);
        r0 = GCALL1(0x06026A1C, r8);
        r9 = 252;
        r0 = r8;
        r2 = LD32(r0 + 252);
        if (!((r2 & r2) == 0)) {
            r1 = LD32(r8 + 56);
            c8 = r1 == r2;
            r1 = 0;
            if (c8) {
                ST32(r8 + 56, r1);
                r0 = r8;
            }
            r4 = LD32(r0 + r9);
            r0 = GCALL1(0x06027F48, r4);
            ST32(r8 + r9, 0);
        }
        r4 = LD32(r8 + 4);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
        }
        r1 = LD32(r8 + 4);
        r4 = LD32(r8 + 40);
        c11 = (r4 & r4) == 0;
        if (r1 == r4) {
            r1 = 0;
        } else {
            r1 = 0;
            if (!(c11)) {
                r0 = GCALL1(0x06027F48, r4);
                r1 = 0;
            }
        }
        ST32(r8 + 4, r1);
        ST32(r8 + 40, r1);
        r0 = GCALL1(0x06025DB0, (r8 + 40));
        r0 = GCALL1(0x06027F48, r8);
        r1 = LD32(0x06000334);
        r0 = GCALL1(r1, 2);
        r0 = 1;
    } else {
        r1 = LD32(0x06000334);
        r0 = GCALL1(r1, 2);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06026DEC(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, c1034;

    r11 = r4;
    if (r5 == 1) {
        r0 = LD32(0x06000330);
        r0 = GCALL2(r0, 2, r5);
        r2 = 17;
        if (!((r0 & r0) == 0)) {
            ST8(-366, r2);
            r8 = LD32(0x060769B0);
            r10 = 0;
            if (!((r8 & r8) == 0)) {
                r12 = 252;
                do {
                    ST32(r8 + 32, r10);
                    r1 = LD32(0x20000014 + r8);
                    r9 = LD32(r8);
                    if (!((r1 & r1) == 0)) {
                        c1034 = (r9 & r9) == 0;
                    } else {
                        r0 = GCALL1(0x06025A74, r8);
                        r2 = 17;
                        if ((r0 & r0) == 0) {
                            c1034 = (r9 & r9) == 0;
                        } else {
                            ST8(-366, r2);
                            r1 = 1;
                            if (r11 > 2) {
                                r0 = GCALL1(0x06026A1C, r8);
                                ST32(r8 + 12, r10);
                                ST32(r8 + 24, 1);
                                r1 = 1;
                            }
                            r0 = r8;
                            if (r11 > r1) {
                                r2 = LD32(r0 + r12);
                                if (!((r2 & r2) == 0)) {
                                    r1 = LD32(r8 + 56);
                                    if (r2 == r1) {
                                        ST32(r8 + 56, r10);
                                        r0 = r8;
                                    }
                                    r4 = LD32(r0 + r12);
                                    r0 = GCALL1(0x06027F48, r4);
                                    ST32(r8 + r12, r10);
                                }
                            }
                            r0 = GCALL1(0x06025AB4, r8);
                            c1034 = (r9 & r9) == 0;
                            if (r11 > 3) {
                                r1 = LD32(0x06000334);
                                r0 = GCALL1(r1, 2);
                                r0 = GCALL1(0x06026B64, r8);
                                r0 = GCALL1(0x06025A0C, 2);
                                r9 = LD32(0x060769B0);
                                c1034 = (r9 & r9) == 0;
                            }
                        }
                    }
                    r8 = r9;
                } while (AGAIN(!(c1034)));
            }
            r1 = LD32(0x06000334);
            r0 = GCALL1(r1, 2);
            r0 = 1;
        } else {
            r0 = GCALL1(0x0602BA00, 0x06026DD0);
            r8 = LD32(0x060769B0);
            r10 = 0;
            if (!((r8 & r8) == 0)) {
                r12 = 252;
                do {
                    r1 = LD32(0x20000014 + r8);
                    r9 = LD32(r8);
                    if (!((r1 & r1) == 0)) {
                        r8 = r9;
                    } else {
                        r1 = LD32(0x20000008 + r8);
                        if (!((r1 & r1) == 0)) {
                            r8 = r9;
                        } else {
                            r0 = GCALL1(0x06025A74, r8);
                            r2 = 17;
                            if ((r0 & r0) == 0) {
                                ST32(r8 + 32, r10);
                                r8 = r9;
                            } else {
                                ST8(-366, r2);
                                r1 = 1;
                                if (r11 > 2) {
                                    r0 = GCALL1(0x06026A1C, r8);
                                    ST32(r8 + 12, r10);
                                    ST32(r8 + 24, 1);
                                    r1 = 1;
                                }
                                r0 = r8;
                                if (r11 > r1) {
                                    r2 = LD32(r0 + r12);
                                    if (!((r2 & r2) == 0)) {
                                        r1 = LD32(r8 + 56);
                                        if (r2 == r1) {
                                            ST32(r8 + 56, r10);
                                            r0 = r8;
                                        }
                                        r4 = LD32(r0 + r12);
                                        r0 = GCALL1(0x06027F48, r4);
                                        ST32(r8 + r12, r10);
                                    }
                                }
                                r0 = GCALL1(0x06025AB4, r8);
                                r8 = r9;
                            }
                        }
                    }
                } while (AGAIN(!((r9 & r9) == 0)));
            }
            ST8(-366, 17);
            r0 = 0;
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602A074(int r4)
{
    int r0, r1, r2, r3, r7, c5, c6, c1005;

    if (!((r4 & r4) == 0)) {
        r1 = LD8(r4);
        r1 = r1 & 255;
        r2 = 0;
        if (r1 == 62) {
            return 0;
        } else {
            r3 = 0x06075135;
            c1005 = (r1 & r1) == 0;
            while (1) {
                r0 = r1;
                if (c1005) {
                    return 0;
                } else {
                    r7 = LD8(r0 + r3);
                    r0 = r1;
                    if (!(((r7 & 8) & (r7 & 8)) == 0)) {
                        POLL();
                        return 0;
                    } else {
                        c5 = r0 == 61;
                        if (r0 == 34) {
                            POLL();
                            return 0;
                        } else {
                            c6 = r0 == 37;
                            if (c5) {
                                POLL();
                                return 0;
                            } else {
                                r2 = r2 + 1;
                                if (c6) {
                                    POLL();
                                    return 1;
                                } else {
                                    r1 = LD8(r4 + r2);
                                    r1 = r1 & 255;
                                    c1005 = (r1 & r1) == 0;
                                    if (!(r1 == 62)) {
                                        POLL();
                                        continue;
                                    } else {
                                        return 0;
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
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602B5D4(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, c0, c2, c4, c8, c9, c1003, c1011, c1013;

    r8 = r4;
    c0 = (r8 & r8) == 0;
    r9 = r5;
    c1003 = c0;
    if (c0) {
        r0 = 0;
    } else {
        r0 = 0;
        if (r9 > 0) {
            c2 = r6 > 0;
            r4 = r6;
            c1003 = c2;
            if (c2) {
                r0 = GCALL2(0x0607286C, r4, r9);
                r7 = r0;
                r3 = 0;
                r2 = r8;
                c4 = 0 >= r9;
                r4 = r4 - (r7 * r9);
                c1011 = c4;
                if (c4) {
                    while (1) {
                        c8 = (r2 & r2) == 0;
                        c1013 = c8;
                        if (c1011) {
                            r0 = 1;
                            break;
                        } else {
                            c9 = r4 > 0;
                            c1013 = c9;
                            if (!(c8)) {
                                POLL();
                                r4 = r4 - 1;
                                c1013 = c9;
                                if (!(c9)) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r1 = LD32(r2 + 8);
                                    r3 = r3 + 1;
                                    ST32(r2 + 8, (r1 + 1));
                                    r2 = LD32(r2 + 52);
                                    c1011 = r3 >= r9;
                                    continue;
                                }
                            } else {
                                r0 = 1;
                                break;
                            }
                        }
                    }
                    return r0;
                } else {
                    do {
                        r1 = LD32(r2 + 8);
                        r3 = r3 + 1;
                        ST32(r2 + 8, (r1 + r7));
                        r2 = LD32(r2 + 52);
                    } while (AGAIN(!(r3 >= r9)));
                    r3 = 0;
                    r2 = r8;
                    c1011 = r3 >= r9;
                    while (1) {
                        c8 = (r2 & r2) == 0;
                        c1013 = c8;
                        if (c1011) {
                            r0 = 1;
                            break;
                        } else {
                            c9 = r4 > 0;
                            c1013 = c9;
                            if (!(c8)) {
                                POLL();
                                r4 = r4 - 1;
                                c1013 = c9;
                                if (!(c9)) {
                                    r0 = 1;
                                    break;
                                } else {
                                    r1 = LD32(r2 + 8);
                                    r3 = r3 + 1;
                                    ST32(r2 + 8, (r1 + 1));
                                    r2 = LD32(r2 + 52);
                                    c1011 = r3 >= r9;
                                    continue;
                                }
                            } else {
                                r0 = 1;
                                break;
                            }
                        }
                    }
                    return r0;
                }
                r0 = 1;
            } else {
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602E26C(void)
{
    int r0, r1, r2, r3, r7, c1002;

    r1 = LD32(0x060769D4);
    r2 = LD32(r1 + 20);
    r0 = LD32(r2);
    r3 = 0;
    if ((r0 & r0) == 0) {
        return -1;
    } else {
        r7 = 0x7FFF;
        c1002 = r0 == 10;
        while (1) {
            if (!(c1002)) {
                r2 = r2 + 24;
                r0 = LD32(r2);
                c1002 = r0 == 10;
                if (!((r0 & r0) == 0)) {
                    POLL();
                    continue;
                } else {
                    return -1;
                }
            } else {
                r1 = LD32(r2 + 16);
                r0 = r3;
                if (!(((r1 & r7) & (r1 & r7)) == 0)) {
                    return r0;
                } else {
                    r3 = r3 + 1;
                    r2 = r2 + 24;
                    r0 = LD32(r2);
                    c1002 = r0 == 10;
                    if (!((r0 & r0) == 0)) {
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
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0602EDBC(int r4)
{
    int r0, r1, r2, r3, r8, r9, c2, c3, c1009;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r9 = 0x06000330;
        do {
            r0 = LD32(r9);
            r0 = GCALL1(r0, 3);
        } while (AGAIN((r0 & r0) == 0));
        r2 = 0x06078024;
        r1 = LD32(0x06078024);
        c2 = r1 == r8;
        r1 = 0;
        if (c2) {
            ST32(r2, r1);
        }
        r2 = 0x0608AB68;
        r1 = LD32(0x0608AB68);
        c3 = r1 == r8;
        r1 = 0;
        if (c3) {
            ST32(r2, r1);
        }
        r4 = LD32(0x06078028);
        r3 = 0x06078028;
        if (!((r4 & r4) == 0)) {
            c1009 = r4 == r8;
            while (1) {
                if (!(c1009)) {
                    r4 = LD32(r4 + 40);
                    c1009 = r4 == r8;
                    if (!((r4 & r4) == 0)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                } else {
                    r2 = LD32(r4 + 44);
                    r1 = LD32(r4 + 40);
                    if ((r2 & r2) == 0) {
                        ST32(r3, r1);
                        r2 = LD32(r4 + 40);
                        if ((r2 & r2) == 0) {
                            r0 = GCALL1(0x06027F48, r4);
                            break;
                        } else {
                            r1 = LD32(r4 + 44);
                            ST32(r2 + 44, r1);
                            r0 = GCALL1(0x06027F48, r4);
                            break;
                        }
                    } else {
                        ST32(r2 + 40, r1);
                        r2 = LD32(r4 + 40);
                        if ((r2 & r2) == 0) {
                            r0 = GCALL1(0x06027F48, r4);
                            break;
                        } else {
                            r1 = LD32(r4 + 44);
                            ST32(r2 + 44, r1);
                            r0 = GCALL1(0x06027F48, r4);
                            break;
                        }
                    }
                }
                POLL();
            }
        }
        r1 = LD32(0x06000334);
        r0 = GCALL1(r1, 3);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602FBE4(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, c0, c2, c5, c10, c11, c12, c15, c18, c19, c20, c21, c1003, c1015, c1027, c1034;

    r12 = r5;
    c0 = (r12 & r12) == 0;
    r1 = r4;
    c1003 = c0;
    if (!(c0)) {
        if (!(c1003)) {
            r1 = LD32(r4 + 44);
            r6 = LD32(r4 + 52);
            r3 = (short)r1;
            r1 = LD32(r4 + 28);
            r2 = r4;
            if (!((unsigned)r6 >= (unsigned)r1)) {
                r2 = r2 + 56;
                r1 = LD16(r2);
                ST16(r2, (r1 + 1));
            }
            r0 = LD16((r4 + 8));
            r1 = r4;
            if (!(r0 == 1)) {
                r9 = LD16((r1 + 20));
            } else {
                r9 = 0;
            }
        } else {
            r1 = LD32(r4 + 40);
            r9 = 0;
            r6 = LD32(r4 + 48);
            r3 = (short)(r1 + 2);
        }
        r2 = LD32((((r3 << 2) + r4) + 68));
        r7 = r4 + 20;
        r5 = r2 + 0x25A00000;
        r1 = LD16(r7);
        c5 = (r1 & 0xFFFF) == 1;
        r1 = r4;
        if (!(c5)) {
            r1 = LD32((r1 + 88));
            r8 = r4;
            if ((r1 & r1) == 0) {
                r8 = r8 + 60;
                r1 = LD16(r8);
                r3 = 0;
                c19 = 0 >= (r1 & 0xFFFF);
                c1034 = c19;
                if (!(c19)) {
                    r11 = r4 + 16;
                    r10 = r7;
                    while (1) {
                        r1 = LD32(r4 + 28);
                        c20 = (unsigned)r6 >= (unsigned)r1;
                        r7 = r6;
                        c1034 = c20;
                        if (c20) {
                            break;
                        } else {
                            r7 = r7 + r9;
                            r1 = LD32(r4 + 24);
                            r1 = LD8(((r1 + r7) + 1));
                            ST8(r5 + r3, r1);
                            r1 = LD32(r4 + 24);
                            r1 = LD8(r1 + r7);
                            ST8(((r3 + r5) + 1), r1);
                            r1 = LD16(r11);
                            r6 = r6 + r1;
                            r1 = LD16(r10);
                            r3 = r3 + (r1 & 0xFFFF);
                            r1 = LD16(r8);
                            c21 = r3 >= (r1 & 0xFFFF);
                            c1034 = c21;
                            if (!(c21)) {
                                POLL();
                                continue;
                            } else {
                                break;
                            }
                        }
                        POLL();
                    }
                }
                r2 = r4;
            } else {
                r8 = r8 + 60;
                r1 = LD16(r8);
                r3 = 0;
                c15 = 0 >= (r1 & 0xFFFF);
                c1034 = c15;
                if (c15) {
                    r2 = r4;
                } else {
                    r11 = r4 + 16;
                    r10 = r7;
                    c1027 = r6 >= 0;
                    while (1) {
                        r7 = r6;
                        c1034 = c1027;
                        if (!(c1027)) {
                            r2 = r4;
                            break;
                        } else {
                            r7 = r7 + r9;
                            r1 = LD32(r4 + 24);
                            r1 = LD8(((r1 + r7) + 1));
                            ST8(r5 + r3, r1);
                            r1 = LD32(r4 + 24);
                            r1 = LD8(r1 + r7);
                            ST8(((r3 + r5) + 1), r1);
                            r1 = LD16(r11);
                            r6 = r6 - r1;
                            r1 = LD16(r10);
                            r3 = r3 + (r1 & 0xFFFF);
                            r1 = LD16(r8);
                            c18 = r6 >= 0;
                            c1027 = c18;
                            if (!(r3 >= (r1 & 0xFFFF))) {
                                POLL();
                                continue;
                            } else {
                                r2 = r4;
                                break;
                            }
                        }
                        POLL();
                    }
                }
            }
        } else {
            r1 = LD32((r1 + 88));
            r2 = r4;
            if ((r1 & r1) == 0) {
                r2 = r2 + 60;
                r1 = LD16(r2);
                r3 = 0;
                c11 = 0 >= (r1 & 0xFFFF);
                c1034 = c11;
                if (c11) {
                    r2 = r4;
                } else {
                    r10 = 128;
                    r8 = r4 + 16;
                    while (1) {
                        r1 = LD32(r4 + 28);
                        c12 = (unsigned)r6 >= (unsigned)r1;
                        c1034 = c12;
                        if (c12) {
                            r2 = r4;
                            break;
                        } else {
                            r1 = LD32(r4 + 24);
                            r1 = LD8(r1 + (r6 + r9));
                            ST8(r5 + r3, (r1 + r10));
                            r1 = LD16(r8);
                            r6 = r6 + r1;
                            r1 = LD16(r7);
                            r3 = r3 + (r1 & 0xFFFF);
                            r1 = LD16(r2);
                            if (!(r3 >= (r1 & 0xFFFF))) {
                                POLL();
                                continue;
                            } else {
                                r2 = r4;
                                break;
                            }
                        }
                        POLL();
                    }
                }
            } else {
                r2 = r2 + 60;
                r1 = LD16(r2);
                r3 = 0;
                if (!(0 >= (r1 & 0xFFFF))) {
                    r10 = 128;
                    r8 = r4 + 16;
                    c1015 = r6 >= 0;
                    while (1) {
                        if (c1015) {
                            r1 = LD32(r4 + 24);
                            r1 = LD8(r1 + (r6 + r9));
                            ST8(r5 + r3, (r1 + r10));
                            r1 = LD16(r8);
                            r6 = r6 - r1;
                            r1 = LD16(r7);
                            r3 = r3 + (r1 & 0xFFFF);
                            r1 = LD16(r2);
                            c10 = r6 >= 0;
                            c1015 = c10;
                            if (!(r3 >= (r1 & 0xFFFF))) {
                                POLL();
                                continue;
                            } else {
                                r2 = r4;
                                break;
                            }
                        } else {
                            c1034 = 0;
                            r2 = r4;
                            break;
                        }
                        POLL();
                    }
                } else {
                    c1034 = 1;
                    r2 = r4;
                }
            }
        }
        r2 = r2 + 60;
        r1 = LD16(r2);
        if (!(r3 >= (r1 & 0xFFFF))) {
            r7 = 0;
            r0 = r5;
            do {
                ST8(r0 + r3, r7);
                r1 = LD16(r2);
                r3 = r3 + 1;
            } while (AGAIN(!(r3 >= (r1 & 0xFFFF))));
        }
        if (!((r12 & r12) == 0)) {
            r1 = LD32(r4 + 44);
            ST32(r4 + 52, r6);
            r0 = (~r1) & 1;
            ST32(r4 + 44, r0);
        } else {
            r1 = LD32(r4 + 40);
            ST32(r4 + 48, r6);
            r0 = (~r1) & 1;
            ST32(r4 + 40, r0);
        }
    } else {
        r0 = LD16((r1 + 8));
        c2 = (r12 & r12) == 0;
        c1003 = c2;
        if (!(r0 == 1)) {
            if (!(c1003)) {
                r1 = LD32(r4 + 44);
                r6 = LD32(r4 + 52);
                r3 = (short)r1;
                r1 = LD32(r4 + 28);
                r2 = r4;
                if (!((unsigned)r6 >= (unsigned)r1)) {
                    r2 = r2 + 56;
                    r1 = LD16(r2);
                    ST16(r2, (r1 + 1));
                }
                r0 = LD16((r4 + 8));
                r1 = r4;
                if (!(r0 == 1)) {
                    r9 = LD16((r1 + 20));
                } else {
                    r9 = 0;
                }
            } else {
                r1 = LD32(r4 + 40);
                r9 = 0;
                r6 = LD32(r4 + 48);
                r3 = (short)(r1 + 2);
            }
            r2 = LD32((((r3 << 2) + r4) + 68));
            r7 = r4 + 20;
            r5 = r2 + 0x25A00000;
            r1 = LD16(r7);
            c5 = (r1 & 0xFFFF) == 1;
            r1 = r4;
            if (!(c5)) {
                r1 = LD32((r1 + 88));
                r8 = r4;
                if ((r1 & r1) == 0) {
                    r8 = r8 + 60;
                    r1 = LD16(r8);
                    r3 = 0;
                    c19 = 0 >= (r1 & 0xFFFF);
                    c1034 = c19;
                    if (!(c19)) {
                        r11 = r4 + 16;
                        r10 = r7;
                        while (1) {
                            r1 = LD32(r4 + 28);
                            c20 = (unsigned)r6 >= (unsigned)r1;
                            r7 = r6;
                            c1034 = c20;
                            if (c20) {
                                break;
                            } else {
                                r7 = r7 + r9;
                                r1 = LD32(r4 + 24);
                                r1 = LD8(((r1 + r7) + 1));
                                ST8(r5 + r3, r1);
                                r1 = LD32(r4 + 24);
                                r1 = LD8(r1 + r7);
                                ST8(((r3 + r5) + 1), r1);
                                r1 = LD16(r11);
                                r6 = r6 + r1;
                                r1 = LD16(r10);
                                r3 = r3 + (r1 & 0xFFFF);
                                r1 = LD16(r8);
                                c21 = r3 >= (r1 & 0xFFFF);
                                c1034 = c21;
                                if (!(c21)) {
                                    POLL();
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            POLL();
                        }
                    }
                    r2 = r4;
                } else {
                    r8 = r8 + 60;
                    r1 = LD16(r8);
                    r3 = 0;
                    c15 = 0 >= (r1 & 0xFFFF);
                    c1034 = c15;
                    if (c15) {
                        r2 = r4;
                    } else {
                        r11 = r4 + 16;
                        r10 = r7;
                        c1027 = r6 >= 0;
                        while (1) {
                            r7 = r6;
                            c1034 = c1027;
                            if (!(c1027)) {
                                r2 = r4;
                                break;
                            } else {
                                r7 = r7 + r9;
                                r1 = LD32(r4 + 24);
                                r1 = LD8(((r1 + r7) + 1));
                                ST8(r5 + r3, r1);
                                r1 = LD32(r4 + 24);
                                r1 = LD8(r1 + r7);
                                ST8(((r3 + r5) + 1), r1);
                                r1 = LD16(r11);
                                r6 = r6 - r1;
                                r1 = LD16(r10);
                                r3 = r3 + (r1 & 0xFFFF);
                                r1 = LD16(r8);
                                c18 = r6 >= 0;
                                c1027 = c18;
                                if (!(r3 >= (r1 & 0xFFFF))) {
                                    POLL();
                                    continue;
                                } else {
                                    r2 = r4;
                                    break;
                                }
                            }
                            POLL();
                        }
                    }
                }
            } else {
                r1 = LD32((r1 + 88));
                r2 = r4;
                if ((r1 & r1) == 0) {
                    r2 = r2 + 60;
                    r1 = LD16(r2);
                    r3 = 0;
                    c11 = 0 >= (r1 & 0xFFFF);
                    c1034 = c11;
                    if (c11) {
                        r2 = r4;
                    } else {
                        r10 = 128;
                        r8 = r4 + 16;
                        while (1) {
                            r1 = LD32(r4 + 28);
                            c12 = (unsigned)r6 >= (unsigned)r1;
                            c1034 = c12;
                            if (c12) {
                                r2 = r4;
                                break;
                            } else {
                                r1 = LD32(r4 + 24);
                                r1 = LD8(r1 + (r6 + r9));
                                ST8(r5 + r3, (r1 + r10));
                                r1 = LD16(r8);
                                r6 = r6 + r1;
                                r1 = LD16(r7);
                                r3 = r3 + (r1 & 0xFFFF);
                                r1 = LD16(r2);
                                if (!(r3 >= (r1 & 0xFFFF))) {
                                    POLL();
                                    continue;
                                } else {
                                    r2 = r4;
                                    break;
                                }
                            }
                            POLL();
                        }
                    }
                } else {
                    r2 = r2 + 60;
                    r1 = LD16(r2);
                    r3 = 0;
                    if (!(0 >= (r1 & 0xFFFF))) {
                        r10 = 128;
                        r8 = r4 + 16;
                        c1015 = r6 >= 0;
                        while (1) {
                            if (c1015) {
                                r1 = LD32(r4 + 24);
                                r1 = LD8(r1 + (r6 + r9));
                                ST8(r5 + r3, (r1 + r10));
                                r1 = LD16(r8);
                                r6 = r6 - r1;
                                r1 = LD16(r7);
                                r3 = r3 + (r1 & 0xFFFF);
                                r1 = LD16(r2);
                                c10 = r6 >= 0;
                                c1015 = c10;
                                if (!(r3 >= (r1 & 0xFFFF))) {
                                    POLL();
                                    continue;
                                } else {
                                    r2 = r4;
                                    break;
                                }
                            } else {
                                c1034 = 0;
                                r2 = r4;
                                break;
                            }
                            POLL();
                        }
                    } else {
                        c1034 = 1;
                        r2 = r4;
                    }
                }
            }
            r2 = r2 + 60;
            r1 = LD16(r2);
            if (!(r3 >= (r1 & 0xFFFF))) {
                r7 = 0;
                r0 = r5;
                do {
                    ST8(r0 + r3, r7);
                    r1 = LD16(r2);
                    r3 = r3 + 1;
                } while (AGAIN(!(r3 >= (r1 & 0xFFFF))));
            }
            if (!((r12 & r12) == 0)) {
                r1 = LD32(r4 + 44);
                ST32(r4 + 52, r6);
                r0 = (~r1) & 1;
                ST32(r4 + 44, r0);
            } else {
                r1 = LD32(r4 + 40);
                ST32(r4 + 48, r6);
                r0 = (~r1) & 1;
                ST32(r4 + 40, r0);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0602FDD4(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, c3, c8, c9, c10, c13, c16, c17, c18, c19, c1012, c1024, c1031;

    r13 = r5;
    r9 = r6;
    if (!((r13 & r13) == 0)) {
        r1 = LD32(r4 + 44);
        r6 = LD32(r4 + 52);
        r3 = (short)r1;
        r1 = LD32(r4 + 28);
        r2 = r4;
        if (!((unsigned)r6 >= (unsigned)r1)) {
            r2 = r2 + 56;
            r1 = LD16(r2);
            ST16(r2, (r1 + 1));
        }
        r0 = LD16((r4 + 8));
        r1 = r4;
        if (!(r0 == 1)) {
            r10 = LD16((r1 + 20));
        } else {
            r10 = 0;
        }
    } else {
        r1 = LD32(r4 + 40);
        r10 = 0;
        r6 = LD32(r4 + 48);
        r3 = (short)(r1 + 2);
    }
    r2 = LD32((((r3 << 2) + r4) + 68));
    r7 = r4 + 20;
    r5 = r2 + 0x25A00000;
    r1 = LD16(r7);
    c3 = (r1 & 0xFFFF) == 1;
    r1 = r4;
    if (!(c3)) {
        r1 = LD32((r1 + 88));
        r8 = r4;
        if ((r1 & r1) == 0) {
            r8 = r8 + 60;
            r1 = LD16(r8);
            r3 = 0;
            c17 = 0 >= (r1 & 0xFFFF);
            c1031 = c17;
            if (!(c17)) {
                r11 = r4 + 16;
                while (1) {
                    r1 = LD32(r4 + 28);
                    c18 = (unsigned)r6 >= (unsigned)r1;
                    r7 = r6;
                    c1031 = c18;
                    if (c18) {
                        break;
                    } else {
                        r1 = LD32(r4 + 24);
                        r7 = r7 + r10;
                        r1 = LD8(r1 + r7);
                        r1 = LD8(r9 + (r1 & 255));
                        ST8(r5 + r3, r1);
                        r1 = LD32(r4 + 24);
                        r1 = LD8(((r1 + r7) + 1));
                        r1 = LD8(r9 + (r1 & 255));
                        ST8(((r3 + r5) + 1), r1);
                        r1 = LD16(r11);
                        r6 = r6 + r1;
                        r1 = LD16((r4 + 20));
                        r3 = r3 + (r1 & 0xFFFF);
                        r1 = LD16(r8);
                        c19 = r3 >= (r1 & 0xFFFF);
                        c1031 = c19;
                        if (!(c19)) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
            }
            r2 = r4;
        } else {
            r8 = r8 + 60;
            r1 = LD16(r8);
            r3 = 0;
            c13 = 0 >= (r1 & 0xFFFF);
            r12 = r4;
            c1031 = c13;
            if (c13) {
                r2 = r4;
            } else {
                r12 = r12 + 16;
                r11 = r7;
                c1024 = r6 >= 0;
                while (1) {
                    r7 = r6;
                    c1031 = c1024;
                    if (!(c1024)) {
                        r2 = r4;
                        break;
                    } else {
                        r1 = LD32(r4 + 24);
                        r7 = r7 + r10;
                        r1 = LD8(r1 + r7);
                        r1 = LD8(r9 + (r1 & 255));
                        ST8(r5 + r3, r1);
                        r1 = LD32(r4 + 24);
                        r1 = LD8(((r1 + r7) + 1));
                        r1 = LD8(r9 + (r1 & 255));
                        ST8(((r3 + r5) + 1), r1);
                        r1 = LD16(r12);
                        r6 = r6 - r1;
                        r1 = LD16(r11);
                        r3 = r3 + (r1 & 0xFFFF);
                        r1 = LD16(r8);
                        c16 = r6 >= 0;
                        c1024 = c16;
                        if (!(r3 >= (r1 & 0xFFFF))) {
                            POLL();
                            continue;
                        } else {
                            r2 = r4;
                            break;
                        }
                    }
                    POLL();
                }
            }
        }
    } else {
        r1 = LD32((r1 + 88));
        r2 = r4;
        if ((r1 & r1) == 0) {
            r2 = r2 + 60;
            r1 = LD16(r2);
            r3 = 0;
            c9 = 0 >= (r1 & 0xFFFF);
            c1031 = c9;
            if (c9) {
                r2 = r4;
            } else {
                r8 = r4 + 16;
                while (1) {
                    r1 = LD32(r4 + 28);
                    c10 = (unsigned)r6 >= (unsigned)r1;
                    c1031 = c10;
                    if (c10) {
                        r2 = r4;
                        break;
                    } else {
                        r1 = LD32(r4 + 24);
                        r1 = LD8(r1 + (r6 + r10));
                        r1 = LD8(r9 + (r1 & 255));
                        ST8(r5 + r3, r1);
                        r1 = LD16(r8);
                        r6 = r6 + r1;
                        r1 = LD16(r7);
                        r3 = r3 + (r1 & 0xFFFF);
                        r1 = LD16(r2);
                        if (!(r3 >= (r1 & 0xFFFF))) {
                            POLL();
                            continue;
                        } else {
                            r2 = r4;
                            break;
                        }
                    }
                    POLL();
                }
            }
        } else {
            r2 = r2 + 60;
            r1 = LD16(r2);
            r3 = 0;
            if (!(0 >= (r1 & 0xFFFF))) {
                r8 = r4 + 16;
                c1012 = r6 >= 0;
                while (1) {
                    if (c1012) {
                        r1 = LD32(r4 + 24);
                        r1 = LD8(r1 + (r6 + r10));
                        r1 = LD8(r9 + (r1 & 255));
                        ST8(r5 + r3, r1);
                        r1 = LD16(r8);
                        r6 = r6 - r1;
                        r1 = LD16(r7);
                        r3 = r3 + (r1 & 0xFFFF);
                        r1 = LD16(r2);
                        c8 = r6 >= 0;
                        c1012 = c8;
                        if (!(r3 >= (r1 & 0xFFFF))) {
                            POLL();
                            continue;
                        } else {
                            r2 = r4;
                            break;
                        }
                    } else {
                        c1031 = 0;
                        r2 = r4;
                        break;
                    }
                    POLL();
                }
            } else {
                c1031 = 1;
                r2 = r4;
            }
        }
    }
    r2 = r2 + 60;
    r1 = LD16(r2);
    if (!(r3 >= (r1 & 0xFFFF))) {
        r7 = 0;
        r0 = r5;
        do {
            ST8(r0 + r3, r7);
            r1 = LD16(r2);
            r3 = r3 + 1;
        } while (AGAIN(!(r3 >= (r1 & 0xFFFF))));
    }
    if (!((r13 & r13) == 0)) {
        r1 = LD32(r4 + 44);
        ST32(r4 + 52, r6);
        r0 = (~r1) & 1;
        ST32(r4 + 44, r0);
    } else {
        r1 = LD32(r4 + 40);
        ST32(r4 + 48, r6);
        r0 = (~r1) & 1;
        ST32(r4 + 40, r0);
    }
    return r0;
}
