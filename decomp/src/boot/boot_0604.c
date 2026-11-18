#include "krnl.h"

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604034C(int r4)
{
    int r0, r1, r2, r3, r7;

    while (1) {
        r2 = LD8(r4);
        r0 = r2 & 255;
        if (!(((r2 & 255) & (r2 & 255)) == 0)) {
            POLL();
            if (r0 == 46) {
                break;
            } else {
                r4 = r4 + 1;
                continue;
            }
        } else {
            break;
        }
    }
    r2 = LD8(r4);
    r7 = r4;
    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
        r3 = 0x06075135;
        r0 = r2 & 255;
        while (1) {
            r0 = LD8(r0 + r3);
            if (((r0 & 4) & (r0 & 4)) == 0) {
                break;
            } else {
                r4 = r4 + 1;
                r2 = LD8(r4);
                r0 = r2 & 255;
                if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    ST8((r4 - 2), 0);
    r4 = r7;
    r1 = LD8(r4);
    r0 = 1;
    if (!((r1 & 255) == 46)) {
        return r0;
    } else {
        r0 = GCALL1(0x06075438, (r4 + 1));
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060408C4(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041080(int r4)
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
int f060410CC(int r4)
{
    int r0, r1, r2, c2;

    r1 = LD16((r4 + 4));
    if (!((unsigned)((r1 - 1) & 0xFFFF) > (unsigned)1)) {
        r2 = LD32(r4 + 8);
        r1 = r4;
        if (!((unsigned)r2 > (unsigned)0xAC44)) {
            r1 = LD16((r1 + 12));
            c2 = (unsigned)((r1 - 1) & 0xFFFF) > (unsigned)3;
            r1 = r4;
            if (!(c2)) {
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
    } else {
        r0 = -401;
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060412F4(int r4)
{
    int r0, r1, r2, r9, r10;

    r2 = ~r4;
    r1 = r2 & 255;
    r10 = 128 & r2;
    r2 = ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) & 7;
    r9 = r2 + r2;
    r0 = GCALL2(0x0607290C, (r1 & 15), (r2 + 3));
    r1 = LD16(r9 + 0x06079098);
    r1 = (short)(r1 + r0);
    if (!((r10 & r10) == 0)) {
        r1 = (short)(-r1);
    }
    return r1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041590(int r4)
{
    int r0, r1, r2, c1;

    r1 = r4;
    r2 = LD8(r1);
    r1 = LD8((r1 + 1));
    if (!((((r2 & 255) << 16) | (r1 & 255)) == 2)) {
        r0 = -1;
    } else {
        r0 = GCALL3(0x060752FC, 0x0604158C, (r4 + 2), 2);
        c1 = (r0 & r0) == 0;
        r0 = 0;
        if (!(c1)) {
            r0 = -1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041638(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9;

    r1 = r4;
    r2 = LD8(r1);
    r1 = LD8((r1 + 1));
    r8 = ((r2 & 255) << 16) | (r1 & 255);
    r9 = r5;
    if (r8 > (r6 - 1)) {
        r0 = -1;
    } else {
        r0 = GCALL3(0x0604B358, r9, (r4 + 2), r8);
        ST8(r9 + r8, 0);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604167C(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x06041638, r4, (r5 + 100), 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041690(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10;
    int v20;

    r9 = r4;
    r10 = r6;
    r1 = r9;
    r2 = LD8(r1);
    r1 = LD8((r1 + 1));
    r8 = ((r2 & 255) << 16) | (r1 & 255);
    r0 = GCALL4(0x060279E0, 0, (r8 + 1), -1, 1);
    r5 = r9;
    if ((r0 & r0) == 0) {
        r0 = -3;
    } else {
        v20 = r0;
        r0 = GCALL5(0x0604B358, r0, (r5 + 2), r8, 0, v20);
        r0 = v20;
        ST8(r0 + r8, 0);
        ST32(r10, r0);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041748(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x06041638, r4, (r5 + 132), 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041760(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x06041638, r4, (r5 + 0x1C4), 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041778(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x06041638, r4, (r5 + 0x1E4), 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041868(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x06041638, r4, (r5 + 0x144), 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041910(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x06041638, r4, (r5 + 196), 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041928(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x06041638, r4, (r5 + 228), 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041948(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, c1, c2, c3;

    r10 = r5;
    r1 = r4;
    r2 = LD8(r1);
    r1 = LD8((r1 + 1));
    r8 = ((r2 & 255) << 16) | (r1 & 255);
    r0 = r8;
    r9 = r4 + 2;
    if (!(r0 == 2)) {
        c2 = r0 == 3;
        r0 = -1;
        if (c2) {
            r0 = GCALL3(0x060752FC, 0x06041944, r9, 3);
            c3 = (r0 & r0) == 0;
            r0 = c3;
            if (!(c3)) {
                r0 = -1;
            } else {
                ST32(r10, r0);
                r0 = 0;
            }
        }
    } else {
        r0 = GCALL3(0x060752FC, 0x06041940, r9, 2);
        c1 = (r0 & r0) == 0;
        r0 = r8;
        if (!(c1)) {
            c2 = r0 == 3;
            r0 = -1;
            if (c2) {
                r0 = GCALL3(0x060752FC, 0x06041944, r9, 3);
                c3 = (r0 & r0) == 0;
                r0 = c3;
                if (!(c3)) {
                    r0 = -1;
                } else {
                    ST32(r10, r0);
                    r0 = 0;
                }
            }
        } else {
            ST32(r10, 0);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060419B8(int r4, int r5, int r6)
{
    int r0;

    r0 = GCALL2(0x06041948, r4, r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060419CC(int r4, int r5, int r6)
{
    int r0;

    r0 = GCALL2(0x06041948, r4, r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06041DAC(int r4, int r5)
{
    int r1;

    do {
        r1 = LD8(r5);
        r5 = r5 + 1;
        r1 = r1 & 255;
        ST8(r4, r1);
        r4 = r4 + 1;
    } while (AGAIN(!((r1 & r1) == 0)));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604266C(int r4, int r5)
{
    int r0, r1, r2, r3, r7;

    if (!((r4 & r4) == 0)) {
        r1 = LD32(r4 + 44);
        r1 = r1 + r5;
        if (!(r1 >= 0)) {
            POLL();
            return 0;
        } else {
            r3 = LD32(r4 + 40);
            ST32(r4 + 44, r1);
            r1 = LD32(r4 + 32);
            r7 = 1;
            if (!(r3 >= ((r1 + r3) + 1))) {
                while (1) {
                    r1 = LD32(r4 + 20);
                    r0 = r3;
                    if (r3 >= r1) {
                        break;
                    } else {
                        r1 = LD32(r4 + 12);
                        ST32((r0 << 2) + r1, r7);
                        r1 = LD32(r4 + 40);
                        r2 = LD32(r4 + 32);
                        r3 = r3 + 1;
                        if (!(r3 >= ((r1 + r2) + 1))) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
            }
            return 1;
        }
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060426AC(int r4)
{
    int r0, r1, r2, r8, r9;

    r9 = r4;
    if ((r9 & r9) == 0) {
        r0 = 0;
    } else {
        r1 = LD32(r9 + 24);
        r2 = LD32(r9 + 4);
        r8 = LD32((r1 << 2) + r2);
        if (!((r8 & r8) == 0)) {
            r0 = GCALL1(0x0607507C, r8);
            r2 = r0;
            r1 = r2;
            if (r2 > 0) {
                r1 = LD8(((r1 + r8) - 1));
                if ((r1 & 255) == 10) {
                    r2 = r2 - 1;
                }
            }
            r1 = LD32(r9 + 28);
            if (r1 > r2) {
                ST32(r9 + 28, r2);
            }
            r0 = 1;
        } else {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060426FC(int r4)
{
    int r0, r1, r8, r9, r10;

    r9 = r4;
    if (!((r9 & r9) == 0)) {
        r8 = LD32(r9 + 24);
        r0 = r8;
        if (r8 > 0) {
            r10 = 0x0607507C;
            while (1) {
                r1 = LD32(r9 + 4);
                r4 = LD32((r0 << 2) + r1);
                if ((r4 & r4) == 0) {
                    break;
                } else {
                    r0 = GCALL1(r10, r4);
                    if (!((r0 & r0) == 0)) {
                        break;
                    } else {
                        r8 = r8 - 1;
                        r0 = r8;
                        if (r8 > 0) {
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
        ST32(r9 + 24, r8);
        r0 = GCALL1(0x060426AC, r9);
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06042D14(int r4)
{
    int r1, r2;

    if ((r4 & r4) == 0) {
        return -1;
    } else {
        r2 = LD32(r4 + 4);
        r1 = LD32(r4);
        return r2 * r1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06042D28(int r4, int r5)
{
    int r0, r1, r9, r10, r11;

    r10 = r4;
    r11 = r5;
    r0 = GCALL1(0x0607507C, r4);
    r9 = r0;
    r0 = GCALL1(0x0607507C, r11);
    r1 = r9;
    if (!(r9 >= r0)) {
        r0 = 0;
    } else {
        r0 = GCALL2(0x06075104, (r10 + (r1 - r0)), r11);
        r0 = (r0 & r0) == 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060432EC(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r4 = LD32(r8 + 12);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
            ST32(r8 + 12, 0);
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043310(int r4, int r5)
{
    int r0, c0;
    FRAME(sp, 20);

    r0 = GCALL4(0x0604326C, (sp - 20), r4, r5, 1);
    c0 = (r0 & r0) == 0;
    r0 = -1;
    if (c0) {
        r0 = GCALL1(0x06042D14, (sp - 20));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06043340(int r4)
{
    ST8((r4 + 12), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060433A8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;

    if (!((r4 & r4) == 0)) {
        r2 = LD32(r4 + 32);
        if (!((r2 & r2) == 0)) {
            r1 = LD32(r4 + 36);
            ST32(r2 + 36, r1);
        }
        r2 = LD32(r4 + 36);
        r1 = LD32(r4 + 32);
        if ((r2 & r2) == 0) {
            ST32(0x0608BCDC, r1);
        } else {
            ST32(r2 + 32, r1);
        }
        r2 = LD32(r4 + 24);
        if (!((r2 & r2) == 0)) {
            r1 = LD32(r4 + 28);
            ST32(r2 + 28, r1);
        }
        r2 = LD32(r4 + 28);
        if ((r2 & r2) == 0) {
            r1 = LD8((r4 + 10));
            r3 = LD32(0x0608BCE0);
            r2 = LD32(r4 + 24);
            ST32(((r1 & 255) << 2) + r3, r2);
        } else {
            r1 = LD32(r4 + 24);
            ST32(r2 + 24, r1);
        }
        r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604340C(int r4, int r5)
{
    int r0, r1, r2, r3, c2;

    r5 = r5 & 255;
    r2 = r5;
    r1 = LD8((r4 + 4));
    r3 = 128;
    r0 = -1;
    if (!((r1 & 255) == 128)) {
        if (!((unsigned)r2 > (unsigned)63)) {
            return r0;
        } else {
            return r2 - 64;
        }
    } else {
        r2 = 31;
        r1 = r5;
        if (!((unsigned)r5 > (unsigned)31)) {
            return r0;
        } else {
            c2 = (unsigned)((r1 + r3) & 255) > (unsigned)r2;
            r1 = 127;
            if (!(c2)) {
                return r0;
            } else {
                r0 = r5;
                if ((unsigned)r5 > (unsigned)r1) {
                    return r0 - 64;
                } else {
                    return r0 - 32;
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043924(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;

    r0 = GCALL4(0x06025A0C, 6, r5, r6, r7);
    r2 = LD32(0x0608BCDC);
    r3 = 0;
    if (!((r2 & r2) == 0)) {
        r1 = r2;
        do {
            ST8((r1 + 9), r3);
            r2 = LD32(r2 + 32);
            r1 = r2;
        } while (AGAIN(!((r2 & r2) == 0)));
    }
    r1 = LD32(0x06000334);
    r0 = GCALL1(r1, 6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043FF8(int r4)
{
    int r0, r1, r2, r8;

    r8 = r4;
    r0 = GCALL0(0x0602E26C);
    if (!(r0 == -1)) {
        r1 = LD32(0x0608BCFC);
        r2 = 0;
        if (!((r1 + r0) >= r8)) {
            ST32(0x060769D4, r2);
            ST32(0x060791AC, r0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060442F4(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7;

    r7 = 0x060791B0;
    r1 = LD32(0x060791B0);
    r6 = 0x060791B0;
    if (!((r1 & r1) == 0)) {
        do {
            r1 = LD32(r7);
            r3 = LD32(r6);
            r2 = LD32(r1 + 20);
            r1 = LD32(r3 + 20);
            if ((unsigned)r2 > (unsigned)r1) {
                r7 = r6;
            }
            r1 = LD32(r3 + 28);
            r6 = r3 + 28;
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    r4 = LD32(r7);
    if (!((r4 & r4) == 0)) {
        r1 = LD32(r4 + 28);
        ST32(r7, r1);
        r1 = LD32(0x060791B4);
        ST32(0x060791B4, (r1 - 1));
        r0 = GCALL4(0x060445F8, r4, r5, r6, r7);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06044380(int r4)
{
    int r1, r2, r3;

    r2 = LD32(0x060791B0);
    r3 = 0;
    if ((r2 & r2) == 0) {
        return;
    } else {
        while (1) {
            r1 = LD32(r2 + 24);
            if (!(r1 == r4)) {
                r2 = LD32(r2 + 28);
                if (!((r2 & r2) == 0)) {
                    POLL();
                    continue;
                } else {
                    return;
                }
            } else {
                ST32(r2 + 24, r3);
                return;
            }
            POLL();
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060443A4(int r4, int r5)
{
    int r0, r1, r2, r8, r9;

    r8 = 0x060791B4;
    r2 = LD32(0x060791B4);
    r9 = r4;
    if (r2 > 4) {
        r0 = GCALL2(0x060442F4, 0, r5);
    }
    r2 = r8 - 4;
    r1 = LD32(r2);
    ST32(r9 + 28, r1);
    ST32(r2, r9);
    r1 = LD32(r8);
    ST32(r8, (r1 + 1));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060443E0(void)
{
    int r0;

    r0 = LD32(0x060791B8);
    ST32(0x060791B8, (r0 + 1));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0604461C(void)
{
    int r0, r4, r8, r9;

    r8 = LD32(0x060791B0);
    r4 = r8;
    if (!((r8 & r8) == 0)) {
        r9 = 0x060445F8;
        do {
            r8 = LD32(r8 + 28);
            r0 = GCALL1(r9, r4);
            r4 = r8;
        } while (AGAIN(!((r8 & r8) == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06044688(int r4, int r5)
{
    int r0, r1, r8, r9, r10, r11, r12, r13;

    r8 = r4;
    r9 = r5;
    r0 = GCALL1(0x0607507C, r9);
    r12 = r0;
    r0 = GCALL4(0x060279E0, 0, (r12 + r12), -1, 1);
    ST32(r8, r0);
    if (!((r0 & r0) == 0)) {
        r1 = 0;
        ST8(r0, 0);
        r8 = LD32(r8);
        if (r12 > 0) {
            r13 = 0x06044648;
            r11 = r9 + 2;
            r10 = r9 + 1;
            while (1) {
                r1 = LD8(r9);
                r0 = GCALL1(r13, ((int)((unsigned)(r1 & 255) >> 2)));
                ST8(r8, r0);
                r1 = LD8(r9);
                r8 = r8 + 1;
                r0 = (r1 << 2) << 2;
                r1 = LD8(r10);
                r0 = GCALL1(r13, ((r0 & 48) | ((int)((unsigned)((int)((unsigned)(r1 & 255) >> 2)) >> 2))));
                ST8(r8, r0);
                r1 = LD8(r10);
                r1 = r1 & 255;
                r8 = r8 + 1;
                if ((r1 & r1) == 0) {
                    POLL();
                    r1 = 61;
                    ST8(r8, 61);
                    r8 = r8 + 1;
                    ST8(r8, r1);
                    r8 = r8 + 1;
                    break;
                } else {
                    r0 = r1 << 2;
                    r1 = LD8(r11);
                    r0 = GCALL1(r13, ((r0 & 60) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r1 & 255) >> 2)) >> 2)) >> 2))));
                    ST8(r8, r0);
                    r0 = LD8(r11);
                    r8 = r8 + 1;
                    if (((r0 & 255) & (r0 & 255)) == 0) {
                        POLL();
                        r1 = 61;
                        ST8(r8, r1);
                        r8 = r8 + 1;
                        break;
                    } else {
                        r0 = GCALL1(r13, (r0 & 63));
                        ST8(r8, r0);
                        r8 = r8 + 1;
                        r12 = r12 - 3;
                        r11 = r11 + 3;
                        r10 = r10 + 3;
                        r9 = r9 + 3;
                        if (r12 > 0) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                }
                POLL();
            }
            r1 = 0;
        }
        ST8(r8, r1);
        r0 = 1;
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0604476C(int r4)
{
    int r1, r2, r3, r7;

    if ((r4 & r4) == 0) {
        return;
    } else {
        r2 = LD32(144 + r4);
        if ((r2 & r2) == 0) {
            return;
        } else {
            r1 = LD32(164 + r4);
            r3 = 0;
            if (!((r1 & r1) == 0)) {
                r1 = r2;
                while (!((r1 & r1) == 0)) {
                    POLL();
                    r2 = LD32(r1 + 4);
                    ST32(r1 + 4, r3);
                    r3 = r1;
                    r1 = r2;
                }
                r1 = r3;
                r3 = 0;
                r7 = LD32(r1 + 12);
                if (!((r1 & r1) == 0)) {
                    do {
                        r2 = LD32(r1 + 12);
                        if (!(r2 >= r7)) {
                            r7 = r2;
                        }
                        r2 = LD32(r1 + 4);
                        ST32(r1 + 20, r7);
                        ST32(r1 + 4, r3);
                        r3 = r1;
                        r1 = r2;
                    } while (AGAIN(!((r1 & r1) == 0)));
                }
            }
            return;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045264(int r4, int r5, int r6, int r7)
{
    int r0, r8;
    FRAME(sp, 20);

    ST32((sp - 4), r7);
    ST32((sp - 8), r6);
    ST32((sp - 12), r5);
    r8 = r4;
    r6 = LD32(sp - 12);
    r0 = GCALL4(0x06044A0C, r4, -1, r6, (sp - 8));
    ST8(r0 + r8, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604528C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r9, r10;
    FRAME(sp, 24);

    ST32((sp - 4), r7);
    ST32((sp - 8), r6);
    r10 = r4;
    r8 = r5;
    r6 = LD32(sp - 8);
    r9 = r8 - 1;
    r0 = GCALL4(0x06044A0C, r4, r9, r6, (sp - 4));
    r3 = r0;
    r2 = r9;
    if (!((unsigned)r3 >= (unsigned)r8)) {
        r2 = r3;
    }
    ST8(r10 + r2, 0);
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060452D0(int r4, int r5, int r6, int r7)
{
    int v4;
    int v8;
    int v12;
    int v16;

    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045560(int r4)
{
    int r0, r1, r3, r7, r8, c3;

    r8 = r4;
    r0 = GCALL1(0x0607507C, r4);
    r7 = 30;
    if (!(r0 > 0)) {
        r0 = 0;
    } else {
        while (1) {
            r3 = LD8(r8);
            if ((unsigned)((r3 + 127) & 255) > (unsigned)r7) {
                r1 = r3;
                if (!((unsigned)((r3 + 95) & 255) > (unsigned)62)) {
                    r0 = 2;
                    break;
                } else {
                    c3 = (unsigned)((r1 + 21) & 255) > (unsigned)9;
                    r1 = r3;
                    if (c3) {
                        if ((unsigned)((r1 + 32) & 255) > (unsigned)10) {
                            r8 = r8 + 1;
                            r0 = r0 - 1;
                        } else {
                            r8 = r8 + 2;
                            r0 = r0 - 2;
                        }
                        if (r0 > 0) {
                            POLL();
                            continue;
                        } else {
                            r0 = 0;
                            break;
                        }
                    } else {
                        r0 = 2;
                        break;
                    }
                }
            } else {
                r0 = 1;
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060455FC(int r4)
{
    int r0, r1, r2;

    r0 = 0;
    r2 = -256;
    do {
        r1 = LD16(r4);
        r4 = r4 + 2;
        r0 = r0 + 1;
    } while (AGAIN(!((((r1 & 0xFFFF) & r2) & ((r1 & 0xFFFF) & r2)) == 0)));
    return r0 - 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045654(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9;

    r9 = r4;
    r8 = r5;
    r0 = GCALL1(0x060455FC, r4);
    r1 = 0;
    if (r0 > 0) {
        r5 = 128;
        r6 = 0x8140;
        r7 = 32;
        do {
            r1 = LD16(r9);
            r9 = r9 + 2;
            r2 = r1 & 0xFFFF;
            r3 = r2;
            if (!(((int)((unsigned)r2 >> 8)) == r5)) {
                if (r3 == r6) {
                    ST8(r8, r7);
                    r8 = r8 + 1;
                }
            } else {
                ST8(r8, r2);
                r8 = r8 + 1;
            }
            r0 = r0 - 1;
            r1 = 0;
        } while (AGAIN(r0 > 0));
    }
    ST8(r8, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060456A4(int r4)
{
    int r0, r5, r8, r9;

    r9 = r4;
    r0 = GCALL1(0x06045614, r4);
    r0 = GCALL2(0x06028380, r0, 15);
    r8 = r0;
    r5 = r8;
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        r0 = GCALL2(0x06045654, r9, r5);
        r0 = r8;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060456E4(int r4, int r5, int r6)
{
    int r0, r2;

    r2 = r5;
    if ((r4 & r4) == 0) {
        r0 = GCALL2(0x060750DC, r2, r6);
        return r0;
    } else {
        r0 = GCALL2(0x06045654, r6, r5);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060457E8(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12;

    r9 = r4;
    r8 = r6;
    r11 = (signed char)r5;
    r12 = r8;
    r0 = GCALL1(0x0607507C, r4);
    r10 = r0;
    while (1) {
        r1 = 0;
        if (!(r10 > 0)) {
            break;
        } else {
            r3 = LD8(r9);
            r1 = r3;
            if (!((unsigned)((r3 + 127) & 255) > (unsigned)30)) {
                ST8(r8, r3);
                r9 = r9 + 1;
                r8 = r8 + 1;
                r1 = LD8(r9);
                r9 = r9 + 1;
                r10 = r10 - 2;
                ST8(r8, r1);
                r8 = r8 + 1;
                POLL();
                continue;
            } else {
                r0 = r11;
                if ((unsigned)((r1 + 32) & 255) > (unsigned)10) {
                    r2 = 62;
                    r1 = r9;
                    if (!((unsigned)((r3 + 95) & 255) > (unsigned)r2)) {
                        r4 = LD8(r1);
                        r1 = LD8((r1 + 1));
                        r0 = GCALL1(0x06045A0C, (((((r4 & 255) - 128) << 8) | ((r1 & 255) - 128)) & 0xFFFF));
                        r2 = r0 & 0xFFFF;
                        ST8(r8, ((int)((unsigned)r2 >> 8)));
                        r8 = r8 + 1;
                        ST8(r8, r2);
                        r8 = r8 + 1;
                        r9 = r9 + 2;
                        r10 = r10 - 2;
                        POLL();
                        continue;
                    } else {
                        r1 = r9;
                        if (!((unsigned)((r3 + 21) & 255) > (unsigned)9)) {
                            r4 = LD8(r1);
                            r1 = LD8((r1 + 1));
                            r0 = GCALL1(0x06045A0C, (((((r4 & 255) - 128) << 8) | ((r1 & 255) - 128)) & 0xFFFF));
                            r2 = r0 & 0xFFFF;
                            ST8(r8, ((int)((unsigned)r2 >> 8)));
                            r8 = r8 + 1;
                            ST8(r8, r2);
                            r8 = r8 + 1;
                            r9 = r9 + 2;
                            r10 = r10 - 2;
                            POLL();
                            continue;
                        } else {
                            r0 = r11;
                            if ((unsigned)((r3 + 32) & 255) > (unsigned)10) {
                                r1 = -128;
                                ST8(r8, r1);
                                r8 = r8 + 1;
                                r1 = LD8(r9);
                                r9 = r9 + 1;
                                r10 = r10 - 1;
                                ST8(r8, r1);
                                r8 = r8 + 1;
                                POLL();
                                continue;
                            } else {
                                r1 = -128;
                                if (!(r0 == 2)) {
                                    ST8(r8, r1);
                                    r8 = r8 + 1;
                                    r1 = LD8(r9);
                                    r9 = r9 + 1;
                                    r10 = r10 - 1;
                                    ST8(r8, r1);
                                    r8 = r8 + 1;
                                    POLL();
                                    continue;
                                } else {
                                    r1 = r9;
                                    r4 = LD8(r1);
                                    r1 = LD8((r1 + 1));
                                    r0 = GCALL1(0x06045A0C, (((((r4 & 255) - 128) << 8) | ((r1 & 255) - 128)) & 0xFFFF));
                                    r2 = r0 & 0xFFFF;
                                    ST8(r8, ((int)((unsigned)r2 >> 8)));
                                    r8 = r8 + 1;
                                    ST8(r8, r2);
                                    r8 = r8 + 1;
                                    r9 = r9 + 2;
                                    r10 = r10 - 2;
                                    POLL();
                                    continue;
                                }
                            }
                        }
                    }
                } else {
                    r2 = 62;
                    if (!(r0 == 1)) {
                        r1 = r9;
                        if (!((unsigned)((r3 + 95) & 255) > (unsigned)r2)) {
                            r4 = LD8(r1);
                            r1 = LD8((r1 + 1));
                            r0 = GCALL1(0x06045A0C, (((((r4 & 255) - 128) << 8) | ((r1 & 255) - 128)) & 0xFFFF));
                            r2 = r0 & 0xFFFF;
                            ST8(r8, ((int)((unsigned)r2 >> 8)));
                            r8 = r8 + 1;
                            ST8(r8, r2);
                            r8 = r8 + 1;
                            r9 = r9 + 2;
                            r10 = r10 - 2;
                            POLL();
                            continue;
                        } else {
                            r1 = r9;
                            if (!((unsigned)((r3 + 21) & 255) > (unsigned)9)) {
                                r4 = LD8(r1);
                                r1 = LD8((r1 + 1));
                                r0 = GCALL1(0x06045A0C, (((((r4 & 255) - 128) << 8) | ((r1 & 255) - 128)) & 0xFFFF));
                                r2 = r0 & 0xFFFF;
                                ST8(r8, ((int)((unsigned)r2 >> 8)));
                                r8 = r8 + 1;
                                ST8(r8, r2);
                                r8 = r8 + 1;
                                r9 = r9 + 2;
                                r10 = r10 - 2;
                                POLL();
                                continue;
                            } else {
                                r0 = r11;
                                if ((unsigned)((r3 + 32) & 255) > (unsigned)10) {
                                    r1 = -128;
                                    ST8(r8, r1);
                                    r8 = r8 + 1;
                                    r1 = LD8(r9);
                                    r9 = r9 + 1;
                                    r10 = r10 - 1;
                                    ST8(r8, r1);
                                    r8 = r8 + 1;
                                    POLL();
                                    continue;
                                } else {
                                    r1 = -128;
                                    if (!(r0 == 2)) {
                                        ST8(r8, r1);
                                        r8 = r8 + 1;
                                        r1 = LD8(r9);
                                        r9 = r9 + 1;
                                        r10 = r10 - 1;
                                        ST8(r8, r1);
                                        r8 = r8 + 1;
                                        POLL();
                                        continue;
                                    } else {
                                        r1 = r9;
                                        r4 = LD8(r1);
                                        r1 = LD8((r1 + 1));
                                        r0 = GCALL1(0x06045A0C, (((((r4 & 255) - 128) << 8) | ((r1 & 255) - 128)) & 0xFFFF));
                                        r2 = r0 & 0xFFFF;
                                        ST8(r8, ((int)((unsigned)r2 >> 8)));
                                        r8 = r8 + 1;
                                        ST8(r8, r2);
                                        r8 = r8 + 1;
                                        r9 = r9 + 2;
                                        r10 = r10 - 2;
                                        POLL();
                                        continue;
                                    }
                                }
                            }
                        }
                    } else {
                        ST8(r8, r3);
                        r9 = r9 + 1;
                        r8 = r8 + 1;
                        r1 = LD8(r9);
                        r9 = r9 + 1;
                        r10 = r10 - 2;
                        ST8(r8, r1);
                        r8 = r8 + 1;
                    }
                }
            }
        }
        POLL();
    }
    ST8(r8, r1);
    return r8 - r12;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045D70(void)
{
    int r0, r1, r2, r3, r6, r7;
    FRAME(sp, 48);

    r0 = GCALL1(0x06032D18, (sp - 12));
    r2 = LD8(0x0608AF55);
    r6 = 0;
    if (r2 > 9) {
        r7 = sp - 48;
        if (r2 > 10) {
            r6 = (-r2) + 10;
            r7 = sp - 48;
        }
    } else {
        r6 = r2 - 10;
        r7 = sp - 48;
    }
    r7 = r7 + 40;
    r1 = LD8(r7);
    r3 = (r1 & 255) + r6;
    r1 = sp - 48;
    if (r3 >= 0) {
        r1 = sp - 48;
        if (!(r3 > 24)) {
            ST8(r7, r3);
        } else {
            r1 = r1 + 39;
            r2 = LD8(r1);
            ST8(r1, (r2 + 1));
            ST8(r7, (r3 - 24));
        }
    } else {
        r1 = r1 + 39;
        r2 = LD8(r1);
        ST8(r1, (r2 - 1));
        ST8(r7, (r3 + 24));
    }
    r1 = LD8((sp - 9));
    ST32(sp - 36, (r1 & 255));
    r1 = LD8((sp - 10));
    ST32(sp - 32, (r1 & 255));
    r1 = LD16((sp - 12));
    ST32(sp - 28, ((r1 & 0xFFFF) + -1900));
    r1 = LD8((sp - 8));
    ST32(sp - 40, ((r1 & 255) + r6));
    r1 = LD8((sp - 7));
    ST32(sp - 44, (r1 & 255));
    r1 = LD8((sp - 6));
    ST32(sp - 48, (r1 & 255));
    r0 = GCALL8(0x060756C4, (sp - 48), 0, 0, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045E34(int r4)
{
    int r0, r1, r2, r3, r8, c1, c5, c10;
    FRAME(sp, 60);

    ST32(sp - 12, r4);
    r0 = LD8(r4);
    r1 = LD32(sp - 12);
    if (!(r0 == 32)) {
        r2 = LD32(sp - 12);
        while (1) {
            r1 = LD8(r2);
            c1 = (r1 & r1) == 0;
            r1 = r2;
            if (c1) {
                break;
            } else {
                r1 = r1 + 1;
                ST32(sp - 12, r1);
                r0 = LD8(r1);
                r2 = LD32(sp - 12);
                if (!(r0 == 32)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        r1 = LD32(sp - 12);
    }
    r1 = LD8(r1);
    r0 = r1;
    if ((r1 & r1) == 0) {
        r0 = 0;
    } else {
        r1 = LD32(sp - 12);
        if (r0 == 32) {
            r2 = LD32(sp - 12);
            while (1) {
                r1 = LD8(r2);
                c5 = (r1 & r1) == 0;
                r1 = r2;
                if (c5) {
                    break;
                } else {
                    r1 = r1 + 1;
                    ST32(sp - 12, r1);
                    r0 = LD8(r1);
                    r2 = LD32(sp - 12);
                    if (r0 == 32) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
            r1 = LD32(sp - 12);
        }
        r1 = LD8(r1);
        r3 = 0;
        if ((r1 & r1) == 0) {
            r0 = 0;
        } else {
            r0 = r1;
            while (1) {
                r1 = LD32(sp - 12);
                if (!(r0 == 32)) {
                    POLL();
                    r2 = LD8(r1);
                    if ((((signed char)r2) & ((signed char)r2)) == 0) {
                        break;
                    } else {
                        ST8((sp - 60) + r3, r2);
                        r1 = LD32(sp - 12);
                        r1 = r1 + 1;
                        ST32(sp - 12, r1);
                        r1 = LD8(r1);
                        r3 = r3 + 1;
                        r0 = r1;
                        continue;
                    }
                } else {
                    break;
                }
            }
            r1 = LD32(sp - 12);
            r1 = LD8(r1);
            c10 = (r1 & r1) == 0;
            r1 = 0;
            if (!(c10)) {
                ST8((sp - 60) + r3, r1);
                ST32(sp - 16, 0);
                ST32(sp - 24, 0);
                r1 = LD32(sp - 12);
                r0 = r3;
                r4 = r1 + 1;
                ST32(sp - 12, r4);
                if (r0 == 3) {
                    r0 = GCALL1(0x06045C9C, (sp - 12));
                    ST32(sp - 32, r0);
                    r4 = LD32(sp - 12);
                    r0 = GCALL1(0x06075438, r4);
                    r4 = LD32(sp - 12);
                    ST32(sp - 36, r0);
                    r4 = r4 + 3;
                    ST32(sp - 12, r4);
                    r0 = GCALL1(0x06075438, r4);
                    r4 = LD32(sp - 12);
                    ST32(sp - 40, r0);
                    r4 = r4 + 3;
                    ST32(sp - 12, r4);
                    r0 = GCALL1(0x06075438, r4);
                    r4 = LD32(sp - 12);
                    ST32(sp - 44, r0);
                    r4 = r4 + 3;
                    ST32(sp - 12, r4);
                    r0 = GCALL1(0x06075438, r4);
                    r4 = LD32(sp - 12);
                    ST32(sp - 48, r0);
                    r4 = r4 + 5;
                    ST32(sp - 12, r4);
                    r0 = GCALL1(0x06075438, r4);
                    r1 = LD32(sp - 12);
                    ST32(sp - 28, r0);
                    r1 = r1 + 4;
                } else {
                    if (r0 == 4) {
                        r8 = 0x06075438;
                        r0 = GCALL1(0x06075438, r4);
                        ST32(sp - 36, r0);
                        r1 = LD32(sp - 12);
                        ST32(sp - 12, (r1 + 3));
                        r0 = GCALL1(0x06045C9C, (sp - 12));
                        r4 = LD32(sp - 12);
                        ST32(sp - 32, r0);
                        r4 = r4 + 2;
                        ST32(sp - 12, r4);
                    } else {
                        r8 = 0x06075438;
                        r4 = LD32(sp - 12);
                        r0 = GCALL1(0x06075438, r4);
                        ST32(sp - 36, r0);
                        r1 = LD32(sp - 12);
                        ST32(sp - 12, (r1 + 3));
                        r0 = GCALL1(0x06045C9C, (sp - 12));
                        r4 = LD32(sp - 12);
                        ST32(sp - 32, r0);
                    }
                    r0 = GCALL1(r8, r4);
                    r4 = LD32(sp - 12);
                    ST32(sp - 28, r0);
                    r4 = r4 + 3;
                    ST32(sp - 12, r4);
                    r0 = GCALL1(r8, r4);
                    r4 = LD32(sp - 12);
                    ST32(sp - 40, r0);
                    r4 = r4 + 3;
                    ST32(sp - 12, r4);
                    r0 = GCALL1(r8, r4);
                    r4 = LD32(sp - 12);
                    ST32(sp - 44, r0);
                    r4 = r4 + 3;
                    ST32(sp - 12, r4);
                    r0 = GCALL1(r8, r4);
                    r1 = LD32(sp - 12);
                    ST32(sp - 48, r0);
                    r1 = r1 + 3;
                }
                ST32(sp - 12, r1);
                r0 = GCALL1(0x060756C4, (sp - 48));
            } else {
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046478(int r4)
{
    int r0, r1, r2, r5, r6, r8, r9, r10, r11, r12, r13, r14;

    r13 = r4;
    r11 = LD32((r13 + 92));
    r14 = r13;
    if (r11 > 99) {
        r0 = 0;
    } else {
        r14 = r14 + 108;
        r12 = r11 * 44;
        while (1) {
            r9 = r12 + 0x0608BD10;
            r1 = LD32(r9 + 40);
            if ((r1 & r1) == 0) {
                r11 = r11 + 1;
                r12 = r12 + 44;
                if (!(r11 > 99)) {
                    POLL();
                    continue;
                } else {
                    r0 = 0;
                    break;
                }
            } else {
                r8 = LD32(r9 + 24);
                r10 = LD32(r9 + 8);
                if ((r8 & r8) == 0) {
                    r8 = LD32(r9 + 28);
                    r10 = LD32(r9 + 12);
                }
                r4 = LD32(r14);
                r0 = GCALL1(0x0607507C, r4);
                r4 = LD32(r14);
                r0 = GCALL4(0x06045F9C, r4, r8, r0, r10);
                if ((r0 & r0) == 0) {
                    r11 = r11 + 1;
                    r12 = r12 + 44;
                    if (!(r11 > 99)) {
                        POLL();
                        continue;
                    } else {
                        r0 = 0;
                        break;
                    }
                } else {
                    r5 = LD32(r9 + 20);
                    r8 = 1;
                    if (!((r5 & r5) == 0)) {
                        r6 = LD32(r9 + 4);
                        r4 = LD32((r13 + 116));
                        r0 = GCALL3(0x060752FC, r4, r5, r6);
                        if (!((r0 & r0) == 0)) {
                            r8 = 0;
                        }
                    }
                    r2 = r13;
                    if ((r8 & r8) == 0) {
                        r11 = r11 + 1;
                        r12 = r12 + 44;
                        if (!(r11 > 99)) {
                            POLL();
                            continue;
                        } else {
                            r0 = 0;
                            break;
                        }
                    } else {
                        ST32((r2 + 96), (r11 + 1));
                        r2 = r9 + 2;
                        r1 = LD16(r2);
                        ST16(r2, (r1 + 1));
                        r0 = LD32(r9 + 40);
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
int f06046534(int r4, int r5, int r6)
{
    int r0, r2;

    r2 = (r4 + 3) & -4;
    r0 = ((-r4) + 4) & 3;
    ST32(r6, r2);
    ST32(r2, 0);
    ST32(r2 + 4, (r5 - r0));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060468E8(void)
{
    int r0;

    r0 = GCALL0(0x06046D2C);
    return (short)r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046AA4(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r9, r10;

    r10 = r5;
    r1 = LD32(0x060759CC);
    r2 = r10 + r1;
    r1 = LD32(r4 + 4);
    r9 = r6;
    ST32(0x0608802C, (r2 + (r1 * r9)));
    ST32(0x06088030, r9);
    r5 = LD32(r4);
    ST32(0x06089614, r5);
    r0 = LD32(r4 + 4);
    ST32(0x06089618, r0);
    r6 = LD32(r4 + 8);
    ST32(0x0608961C, r6);
    r2 = ((r5 + r6) + ((int)((unsigned)(r5 + r6) >> 31))) >> 1;
    r4 = LD32(r4 + 12);
    ST32(0x06089620, r4);
    ST32(0x06089624, r2);
    r1 = ((r0 + r4) + ((int)((unsigned)(r0 + r4) >> 31))) >> 1;
    ST32(0x06089628, r1);
    ST32(0x06089614, (r5 - r2));
    ST32(0x0608961C, (r6 - r2));
    ST32(0x06089618, (r0 - r1));
    ST32(0x06089620, (r4 - r1));
    ST32(0x0608962C, 2);
    r1 = 0;
    r7 = 0x06088034;
    r3 = 0;
    r2 = 199;
    r0 = 0;
    do {
        ST32(r0 + r7, r3);
        r1 = r1 + 1;
        r0 = r0 + 28;
    } while (AGAIN(!(r1 > r2)));
    r0 = GCALL3(0x0604B3F0, r10, 0, ((r9 << 8) + (r9 << 8)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046B60(int r4, int r5, int r6)
{
    int r0, r1, r2;

    r1 = LD32(r6);
    r2 = r4;
    if (!(r2 >= r1)) {
        return 0;
    } else {
        r1 = LD32(r6 + 8);
        if (r2 > r1) {
            return 0;
        } else {
            r1 = LD32(r6 + 4);
            r4 = r5;
            if (!(r4 >= r1)) {
                return 0;
            } else {
                r1 = LD32(r6 + 12);
                r0 = 1;
                if (!(r4 > r1)) {
                    return r0;
                } else {
                    return 0;
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046D2C(void)
{
    int r1, r2;

    r2 = LD32(0x060791C0);
    r1 = (r2 * 0x41C64E6D) + 0x3039;
    ST32(0x060791C0, r1);
    return r1 & 0x7FFFFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046DD8(int r4)
{
    int r0, r1, r7, r8;

    r7 = 0x0608AE44;
    r1 = LD8(0x0608AE44);
    r8 = r4;
    if ((r1 & r1) == 0) {
        r0 = GCALL2(0x060750DC, r8, 0x0608ADA4);
        r0 = 1;
    } else {
        r0 = GCALL4(0x06045264, r4, 0x06046DD0, 0x0608ADA4, r7);
        ST8((r8 + 40), 0);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0604880C(int r4, int r5, int r6)
{
    ST32(r6, r4);
    ST32(r6 + 4, 0);
    ST32(r6 + 8, r5);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06048D3C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12;

    r11 = r5;
    r12 = r6;
    r9 = 0x060791C8;
    r2 = LD32(0x060791C8);
    r10 = r7;
    if (r2 > 31) {
        ST32(r9, 0);
        r2 = LD32(r9);
    }
    r8 = 0x0608CE90;
    r0 = ((r2 << 2) + r2) << 2;
    r1 = LD32(r0 + 0x0608CE90);
    r2 = r2 - 1;
    if (!((r1 & r1) == 0)) {
        r1 = ((r2 << 2) + r2) << 2;
        r2 = LD32(r10);
        ST32((r1 + r8) + 16, r2);
        r5 = LD32(r0 + r8);
        r0 = GCALL2(0x0603CCE0, r4, r5);
        r2 = LD32(r9);
        r1 = LD32(((((r2 << 2) + r2) << 2) + r8) + 8);
        if (!((r1 & r1) == 0)) {
            ST32(r11, r1);
        }
        r2 = LD32(r9);
        r1 = LD32(((((r2 << 2) + r2) << 2) + r8) + 12);
        if (!((r1 & r1) == 0)) {
            ST32(r12, r1);
        }
        r1 = LD32(r9);
        r1 = LD32(((((r1 << 2) + r1) << 2) + r8) + 16);
        r0 = 1;
        ST32(r10, r1);
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06048DE0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12;

    r10 = r5;
    r11 = r6;
    r8 = 0x060791C8;
    r3 = LD32(0x060791C8);
    r12 = r7;
    r1 = r3 - 1;
    r2 = r1 - 1;
    ST32(0x060791C8, r1);
    if (!(r2 >= 0)) {
        r2 = 31;
    }
    r0 = ((r2 << 2) + r2) << 2;
    r9 = 0x0608CE90;
    r1 = LD32(r0 + 0x0608CE90);
    if (!((r1 & r1) == 0)) {
        ST32(r8, r2);
        r5 = LD32(r0 + r9);
        r0 = GCALL2(0x0603CCE0, r4, r5);
        r2 = LD32(r8);
        r1 = LD32(((((r2 << 2) + r2) << 2) + r9) + 8);
        if (!((r1 & r1) == 0)) {
            ST32(r10, r1);
        }
        r2 = LD32(r8);
        r1 = LD32(((((r2 << 2) + r2) << 2) + r9) + 12);
        if (!((r1 & r1) == 0)) {
            ST32(r11, r1);
        }
        r2 = LD32(r8);
        r1 = LD32(((((r2 << 2) + r2) << 2) + r9) + 16);
        ST32(r12, r1);
        r1 = LD32(r8);
        r0 = 1;
        ST32(r8, (r1 + 1));
    } else {
        ST32(r8, r3);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06048E80(int r4, int r5, int r6, int r7)
{
    int r0, r2, r8;

    r8 = r4;
    r0 = GCALL4(0x06048C08, r5, 0, 0, r7);
    r2 = LD32(0x060791C8);
    r2 = r2 - 1;
    ST32(0x060791C8, r2);
    r5 = LD32((((r2 << 2) + r2) << 2) + 0x0608CE90);
    r0 = GCALL2(0x0603CCE0, r8, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06048EC4(int r4)
{
    int r0;

    r0 = GCALL2(0x0603CCE0, 0x0608CE90, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06048EE0(void)
{
    int r0, r1, r8, r9, r10;

    r8 = 0;
    r10 = 0x06048CC0;
    r9 = 31;
    do {
        r0 = GCALL1(r10, r8);
        r8 = r8 + 1;
        r1 = 0;
    } while (AGAIN(!(r8 > r9)));
    ST32(0x060791C8, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06048F10(void)
{
    int r1;

    r1 = LD32(0x060791C8);
    ST32(0x060791C8, (r1 + 1));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049078(void)
{
    int r0, r1;

    r1 = LD32(0x060791C8);
    ST32(0x060791CC, (r1 - 1));
    r0 = GCALL0(0x06048FA0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060490E8(void)
{
    int r0, r1, r2;

    r1 = LD32(0x060791CC);
    r2 = r1 + 1;
    if (r2 > 31) {
        r2 = 0;
    }
    r1 = LD32((((r2 << 2) + r2) << 2) + 0x0608CE90);
    r0 = 0;
    if ((r1 & r1) == 0) {
        return r0;
    } else {
        return 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604911C(int r4)
{
    int r0, r1, r2, r3;

    if (r4 >= 0) {
        r0 = GCALL0(0x060490E8);
        r2 = 31;
        if (!((r0 & r0) == 0)) {
            r3 = 0x060791CC;
            r1 = LD32(0x060791CC);
            r1 = r1 + 1;
            ST32(0x060791CC, r1);
            if (r1 > r2) {
                ST32(r3, 0);
            }
        }
    } else {
        r0 = GCALL0(0x0604909C);
        if (!((r0 & r0) == 0)) {
            r2 = 0x060791CC;
            r1 = LD32(0x060791CC);
            r1 = r1 - 1;
            ST32(0x060791CC, r1);
            if (!(r1 >= 0)) {
                ST32(r2, 31);
            }
        }
    }
    r0 = GCALL0(0x06048FA0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06049178(int r4)
{
    int r1, r2, c0;

    r1 = LD32(0x060791CC);
    r2 = 0x060791C8;
    r1 = r1 - r4;
    c0 = r1 >= 0;
    r1 = r1 + 2;
    if (!(c0)) {
        ST32(r2, 0);
        return;
    } else {
        ST32(r2, r1);
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06049198(int r4)
{
    int r0, r1, r2, r6, r8, r9, r10, r11, r12;

    r12 = 0x060791C8;
    r1 = LD32(0x060791C8);
    r10 = r4;
    if (r1 > 0) {
        r11 = 0x0608CE90;
        r1 = LD32((((((r1 - 1) << 2) + (r1 - 1)) << 2) + 0x0608CE90) + 4);
        if ((r1 & r1) == 0) {
            r0 = GCALL1(0x0607507C, r4);
            r9 = r0;
            r1 = 128;
            if (!(r9 > 128)) {
                r1 = r9;
            }
            r9 = r1;
            r0 = GCALL4(0x060279E0, 0, (r9 + 1), -1, 1);
            r8 = r0;
            r6 = r9;
            if (!((r8 & r8) == 0)) {
                r0 = GCALL3(0x060750A0, r8, r10, r6);
                ST8(r8 + r9, 0);
                r2 = LD32(r12);
                ST32((((((r2 - 1) << 2) + (r2 - 1)) << 2) + r11) + 4, r8);
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0604922C(int r4)
{
    int r1, r2;

    r1 = LD32(0x060791C8);
    r2 = r1;
    if (!(r1 > 0)) {
        return;
    } else {
        ST32((((((r2 - 1) << 2) + (r2 - 1)) << 2) + 0x0608CE90) + 16, r4);
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060493C4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8;

    r8 = r5;
    r0 = GCALL4(0x060492D0, r4, r5, r6, r7);
    r2 = r0;
    r0 = r2;
    if (r2 > 0) {
        r1 = LD8(r8);
        r0 = r2;
        if ((r1 & 255) == 45) {
            r0 = -1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049548(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = r5;
    r0 = GCALL4(0x060492D0, r4, r5, r6, r7);
    r1 = 0;
    if (r0 >= 0) {
        ST8(r0 + r8, r1);
        r0 = GCALL1(0x06075438, r8);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604B3F0(int r4, int r5, int r6)
{
    int r0, r2, r3;

    r3 = r4;
    if (!(r6 == 0)) {
        if (12 > r6) {
            do {
                ST8(r4, r5);
                r6 = r6 - 1;
                r4 = r4 + 1;
            } while (AGAIN(!(r6 == 0)));
        } else {
            r0 = ((-r4) + 4) & 3;
            if (!((r0 & r0) == 0)) {
                do {
                    ST8(r4, r5);
                    r4 = r4 + 1;
                    r0 = r0 - 1;
                    r6 = r6 - 1;
                } while (AGAIN(!(r0 == 0)));
            }
            r5 = ((r5 & 255) | (((r5 & 255) & 0xFFFF0000) | ((((r5 & 255) & 255) << 8) | (((unsigned)(r5 & 255) >> 8) & 255)))) | ((((r5 & 255) | (((r5 & 255) & 0xFFFF0000) | ((((r5 & 255) & 255) << 8) | (((unsigned)(r5 & 255) >> 8) & 255)))) << 16) | (int)((unsigned)((r5 & 255) | (((r5 & 255) & 0xFFFF0000) | ((((r5 & 255) & 255) << 8) | (((unsigned)(r5 & 255) >> 8) & 255)))) >> 16));
            r2 = (int)((unsigned)((int)((unsigned)r6 >> 2)) >> 1);
            do {
                ST32(r4, r5);
                r2 = r2 - 1;
                ST32(r4 + 4, r5);
                r4 = r4 + 8;
            } while (AGAIN(!(r2 == 0)));
            r6 = r6 & 7;
            if (!((r6 & r6) == 0)) {
                do {
                    ST8(r4, r5);
                    r6 = r6 - 1;
                    r4 = r4 + 1;
                } while (AGAIN(!(r6 == 0)));
            }
        }
    }
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604B4B0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;

    r5 = (r5 + 3) & -4;
    r1 = 0x0604B53C;
    r0 = 0x0604B4B0;
    r7 = r6 + r5;
    if (!((unsigned)0x0604B4B0 >= (unsigned)r6)) {
        if (!((unsigned)r1 > (unsigned)r6)) {
            r0 = r6;
            if (!((unsigned)r6 > (unsigned)r4)) {
                r5 = (int)((unsigned)r5 >> 2);
                do {
                    r2 = LD32(r4);
                    r4 = r4 + 4;
                    r5 = r5 - 1;
                    ST32(r6, r2);
                    r6 = r6 + 4;
                } while (AGAIN(!(r5 == 0)));
                POLL();
                r0 = GJUMP4(r0, r4, r5, r6, r7);
                return r0;
            } else {
                if ((unsigned)(r4 + r5) > (unsigned)r6) {
                    r4 = r4 + r5;
                    r6 = r6 + r5;
                    r5 = (int)((unsigned)r5 >> 2);
                    r4 = r4 - 4;
                    do {
                        r2 = LD32(r4);
                        r5 = r5 - 1;
                        r6 = r6 - 4;
                        ST32(r6, r2);
                        r4 = r4 - 4;
                    } while (AGAIN(!(r5 == 0)));
                    POLL();
                    r0 = GJUMP4(r0, r4, r5, r6, r7);
                    return r0;
                } else {
                    r5 = (int)((unsigned)r5 >> 2);
                    do {
                        r2 = LD32(r4);
                        r4 = r4 + 4;
                        r5 = r5 - 1;
                        ST32(r6, r2);
                        r6 = r6 + 4;
                    } while (AGAIN(!(r5 == 0)));
                    POLL();
                    r0 = GJUMP4(r0, r4, r5, r6, r7);
                    return r0;
                }
            }
        } else {
            if (!((unsigned)r7 >= (unsigned)r1)) {
                r0 = r6;
                if (!((unsigned)r6 > (unsigned)r4)) {
                    r5 = (int)((unsigned)r5 >> 2);
                    do {
                        r2 = LD32(r4);
                        r4 = r4 + 4;
                        r5 = r5 - 1;
                        ST32(r6, r2);
                        r6 = r6 + 4;
                    } while (AGAIN(!(r5 == 0)));
                    POLL();
                    r0 = GJUMP4(r0, r4, r5, r6, r7);
                    return r0;
                } else {
                    if ((unsigned)(r4 + r5) > (unsigned)r6) {
                        r4 = r4 + r5;
                        r6 = r6 + r5;
                        r5 = (int)((unsigned)r5 >> 2);
                        r4 = r4 - 4;
                        do {
                            r2 = LD32(r4);
                            r5 = r5 - 1;
                            r6 = r6 - 4;
                            ST32(r6, r2);
                            r4 = r4 - 4;
                        } while (AGAIN(!(r5 == 0)));
                        POLL();
                        r0 = GJUMP4(r0, r4, r5, r6, r7);
                        return r0;
                    } else {
                        r5 = (int)((unsigned)r5 >> 2);
                        do {
                            r2 = LD32(r4);
                            r4 = r4 + 4;
                            r5 = r5 - 1;
                            ST32(r6, r2);
                            r6 = r6 + 4;
                        } while (AGAIN(!(r5 == 0)));
                        POLL();
                        r0 = GJUMP4(r0, r4, r5, r6, r7);
                        return r0;
                    }
                }
            } else {
                r1 = ((r1 - r0) + 3) & -4;
                r2 = 0x06100000 - r1;
                if (!((unsigned)((0x06100000 - r4) - r5) >= (unsigned)r1)) {
                    r2 = 0x06004000;
                }
                r1 = (int)((unsigned)r1 >> 2);
                r7 = r2;
                do {
                    r3 = LD32(r0);
                    r0 = r0 + 4;
                    r1 = r1 - 1;
                    ST32(r2, r3);
                    r2 = r2 + 4;
                } while (AGAIN(!(r1 == 0)));
                POLL();
                r0 = GJUMP4(r7, r4, r5, r6, r7);
                return r0;
            }
        }
    } else {
        if ((unsigned)r7 > (unsigned)r0) {
            r1 = ((r1 - r0) + 3) & -4;
            r2 = 0x06100000 - r1;
            if (!((unsigned)((0x06100000 - r4) - r5) >= (unsigned)r1)) {
                r2 = 0x06004000;
            }
            r1 = (int)((unsigned)r1 >> 2);
            r7 = r2;
            do {
                r3 = LD32(r0);
                r0 = r0 + 4;
                r1 = r1 - 1;
                ST32(r2, r3);
                r2 = r2 + 4;
            } while (AGAIN(!(r1 == 0)));
            POLL();
            r0 = GJUMP4(r7, r4, r5, r6, r7);
            return r0;
        } else {
            if (!((unsigned)r1 > (unsigned)r6)) {
                r0 = r6;
                if (!((unsigned)r6 > (unsigned)r4)) {
                    r5 = (int)((unsigned)r5 >> 2);
                    do {
                        r2 = LD32(r4);
                        r4 = r4 + 4;
                        r5 = r5 - 1;
                        ST32(r6, r2);
                        r6 = r6 + 4;
                    } while (AGAIN(!(r5 == 0)));
                    POLL();
                    r0 = GJUMP4(r0, r4, r5, r6, r7);
                    return r0;
                } else {
                    if ((unsigned)(r4 + r5) > (unsigned)r6) {
                        r4 = r4 + r5;
                        r6 = r6 + r5;
                        r5 = (int)((unsigned)r5 >> 2);
                        r4 = r4 - 4;
                        do {
                            r2 = LD32(r4);
                            r5 = r5 - 1;
                            r6 = r6 - 4;
                            ST32(r6, r2);
                            r4 = r4 - 4;
                        } while (AGAIN(!(r5 == 0)));
                        POLL();
                        r0 = GJUMP4(r0, r4, r5, r6, r7);
                        return r0;
                    } else {
                        r5 = (int)((unsigned)r5 >> 2);
                        do {
                            r2 = LD32(r4);
                            r4 = r4 + 4;
                            r5 = r5 - 1;
                            ST32(r6, r2);
                            r6 = r6 + 4;
                        } while (AGAIN(!(r5 == 0)));
                        POLL();
                        r0 = GJUMP4(r0, r4, r5, r6, r7);
                        return r0;
                    }
                }
            } else {
                if (!((unsigned)r7 >= (unsigned)r1)) {
                    r0 = r6;
                    if (!((unsigned)r6 > (unsigned)r4)) {
                        r5 = (int)((unsigned)r5 >> 2);
                        do {
                            r2 = LD32(r4);
                            r4 = r4 + 4;
                            r5 = r5 - 1;
                            ST32(r6, r2);
                            r6 = r6 + 4;
                        } while (AGAIN(!(r5 == 0)));
                        POLL();
                        r0 = GJUMP4(r0, r4, r5, r6, r7);
                        return r0;
                    } else {
                        if ((unsigned)(r4 + r5) > (unsigned)r6) {
                            r4 = r4 + r5;
                            r6 = r6 + r5;
                            r5 = (int)((unsigned)r5 >> 2);
                            r4 = r4 - 4;
                            do {
                                r2 = LD32(r4);
                                r5 = r5 - 1;
                                r6 = r6 - 4;
                                ST32(r6, r2);
                                r4 = r4 - 4;
                            } while (AGAIN(!(r5 == 0)));
                            POLL();
                            r0 = GJUMP4(r0, r4, r5, r6, r7);
                            return r0;
                        } else {
                            r5 = (int)((unsigned)r5 >> 2);
                            do {
                                r2 = LD32(r4);
                                r4 = r4 + 4;
                                r5 = r5 - 1;
                                ST32(r6, r2);
                                r6 = r6 + 4;
                            } while (AGAIN(!(r5 == 0)));
                            POLL();
                            r0 = GJUMP4(r0, r4, r5, r6, r7);
                            return r0;
                        }
                    }
                } else {
                    r1 = ((r1 - r0) + 3) & -4;
                    r2 = 0x06100000 - r1;
                    if (!((unsigned)((0x06100000 - r4) - r5) >= (unsigned)r1)) {
                        r2 = 0x06004000;
                    }
                    r1 = (int)((unsigned)r1 >> 2);
                    r7 = r2;
                    do {
                        r3 = LD32(r0);
                        r0 = r0 + 4;
                        r1 = r1 - 1;
                        ST32(r2, r3);
                        r2 = r2 + 4;
                    } while (AGAIN(!(r1 == 0)));
                    POLL();
                    r0 = GJUMP4(r7, r4, r5, r6, r7);
                    return r0;
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060410AC(int r4, int r5)
{
    int r0, c0;

    r0 = GCALL3(0x06041134, 0, r4, r5);
    c0 = (r0 & r0) == 0;
    r0 = 0;
    if (c0) {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041134(int r4, int r5, int r6)
{
    int r0, r1, r2, r7, r8, r9, r10, r11, c2, c5, c6;

    r10 = r4;
    r9 = r5;
    r11 = r6;
    if (!((r10 & r10) == 0)) {
        r0 = GCALL2(0x0603F000, r4, 0);
    }
    r1 = r9;
    r8 = LD8(r1);
    r1 = LD8((r1 + 1));
    r8 = ((r8 << 16) << 8) + ((r1 & 255) << 16);
    r1 = LD8((r9 + 2));
    r8 = r8 + ((r1 & 255) << 8);
    r1 = LD8((r9 + 3));
    r8 = r8 + (r1 & 255);
    r0 = GCALL1(0x06041080, 0x0604112C);
    c2 = (r10 & r10) == 0;
    if (r8 == r0) {
        r4 = r9;
        if (!(c2)) {
            r4 = r4 + 4;
            r5 = r9 + 5;
            r6 = r9 + 6;
            r2 = LD8(r4);
            r1 = LD8(r5);
            r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
            r1 = LD8(r6);
            r7 = r9 + 7;
            r2 = r2 + ((r1 & 255) << 8);
            r1 = LD8(r7);
            ST32(r10 + 20, (r9 + (r2 + (r1 & 255))));
            r2 = LD8((r9 + 8));
            r1 = LD8((r9 + 9));
            r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
            r1 = LD8((r9 + 10));
            r2 = r2 + ((r1 & 255) << 8);
            r1 = LD8((r9 + 11));
            ST32(r10 + 24, (r2 + (r1 & 255)));
            r2 = LD8((r9 + 12));
            r1 = LD8((r9 + 13));
            r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
            r1 = LD8((r9 + 14));
            r2 = r2 + ((r1 & 255) << 8);
            r1 = LD8((r9 + 15));
            ST32(r10 + 32, (r2 + (r1 & 255)));
            r2 = LD8((r9 + 16));
            r1 = LD8((r9 + 17));
            r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
            r1 = LD8((r9 + 18));
            r2 = r2 + ((r1 & 255) << 8);
            r1 = LD8((r9 + 19));
            ST32(r10 + 8, (r2 + (r1 & 255)));
            r2 = LD8((r9 + 22));
            r1 = LD8((r9 + 23));
            ST16((r10 + 4), ((r1 & 255) + ((r2 & 255) << 8)));
            r0 = LD32(r10 + 24);
            if (r0 == -1) {
                r2 = LD8(r4);
                r1 = LD8(r5);
                r2 = ((r2 << 16) << 8) + ((r1 & 255) << 16);
                r1 = LD8(r6);
                r2 = r2 + ((r1 & 255) << 8);
                r1 = LD8(r7);
                ST32(r10 + 24, (r11 - (r2 + (r1 & 255))));
            }
            r0 = LD32(r10 + 32);
            c5 = r0 == 3;
            if (r0 == 2) {
                r2 = r10;
                r2 = r2 + 14;
                r1 = 8;
                ST16(r2, r1);
                r1 = LD16((r10 + 14));
                r1 = (((r1 + 7) >> 1) >> 1) >> 1;
                ST16((r10 + 16), r1);
                r2 = LD16((r10 + 4));
                ST16((r10 + 12), ((r1 & 0xFFFF) * r2));
                r0 = 0;
            } else {
                c6 = r0 == 1;
                if (!(c5)) {
                    r2 = r10;
                    if (c6) {
                        r2 = r2 + 14;
                        r1 = 8;
                        ST16(r2, r1);
                        r1 = LD16((r10 + 14));
                        r1 = (((r1 + 7) >> 1) >> 1) >> 1;
                        ST16((r10 + 16), r1);
                        r2 = LD16((r10 + 4));
                        ST16((r10 + 12), ((r1 & 0xFFFF) * r2));
                        r0 = 0;
                    } else {
                        r0 = -408;
                    }
                } else {
                    r2 = r10 + 14;
                    r1 = 16;
                    ST16(r2, r1);
                    r1 = LD16((r10 + 14));
                    r1 = (((r1 + 7) >> 1) >> 1) >> 1;
                    ST16((r10 + 16), r1);
                    r2 = LD16((r10 + 4));
                    ST16((r10 + 12), ((r1 & 0xFFFF) * r2));
                    r0 = 0;
                }
            }
        } else {
            r0 = 0;
        }
    } else {
        r0 = -407;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041D58(int r4)
{
    int r0, r1, r2, r3, r6, r7, r8, c3;

    r8 = r4;
    r0 = GCALL1(0x0607507C, r4);
    r2 = r0 - 1;
    r0 = 0;
    if (r2 >= 0) {
        r7 = 0x06075135;
        r3 = 141;
        r0 = r8;
        while (1) {
            r1 = LD8(r0 + r2);
            r1 = r1 & 255;
            r6 = LD8(r1 + r7);
            r0 = 1;
            if (!(((r6 & 8) & (r6 & 8)) == 0)) {
                break;
            } else {
                c3 = r1 == r3;
                if (r1 == 8) {
                    r0 = 1;
                    break;
                } else {
                    r2 = r2 - 1;
                    if (!(c3)) {
                        r0 = r8;
                        if (r2 >= 0) {
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
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060425D4(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, c3, c4;

    if ((r4 & r4) == 0) {
        r0 = 0;
    } else {
        r7 = LD32(r4 + 40);
        r2 = r7 + r5;
        r0 = 0;
        if (r2 >= 0) {
            r3 = LD32(r4 + 32);
            r1 = LD32(r4 + 20);
            c3 = (r6 & r6) == 0;
            if (!((r2 + r3) > r1)) {
                c4 = r5 > 0;
                if (!(c3)) {
                    r1 = LD32(r4 + 40);
                    r1 = r1 + r5;
                    ST32(r4 + 40, r1);
                    r3 = r1;
                    r1 = LD32(r4 + 32);
                    if (!(r3 >= ((r1 + r3) + 1))) {
                        r7 = 1;
                        while (1) {
                            r1 = LD32(r4 + 20);
                            r0 = r3;
                            if (r3 >= r1) {
                                break;
                            } else {
                                r1 = LD32(r4 + 12);
                                ST32((r0 << 2) + r1, r7);
                                r1 = LD32(r4 + 40);
                                r2 = LD32(r4 + 32);
                                r3 = r3 + 1;
                                if (!(r3 >= ((r1 + r2) + 1))) {
                                    POLL();
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            POLL();
                        }
                    }
                    r3 = LD32(r4 + 24);
                    r2 = LD32(r4 + 40);
                    if (r3 >= r2) {
                        r1 = LD32(r4 + 32);
                        r1 = r1 + r2;
                        r0 = 1;
                        if (r3 > r1) {
                            ST32(r4 + 24, r1);
                            r0 = GCALL1(0x060426AC, r4);
                            r0 = 1;
                        }
                    } else {
                        ST32(r4 + 24, r2);
                        r0 = GCALL1(0x060426AC, r4);
                        r0 = 1;
                    }
                } else {
                    r1 = r7;
                    if (!(c4)) {
                        r1 = LD32(r4 + 40);
                        r1 = r1 + r5;
                        ST32(r4 + 40, r1);
                        r3 = r1;
                        r1 = LD32(r4 + 32);
                        if (!(r3 >= ((r1 + r3) + 1))) {
                            r7 = 1;
                            while (1) {
                                r1 = LD32(r4 + 20);
                                r0 = r3;
                                if (r3 >= r1) {
                                    break;
                                } else {
                                    r1 = LD32(r4 + 12);
                                    ST32((r0 << 2) + r1, r7);
                                    r1 = LD32(r4 + 40);
                                    r2 = LD32(r4 + 32);
                                    r3 = r3 + 1;
                                    if (!(r3 >= ((r1 + r2) + 1))) {
                                        POLL();
                                        continue;
                                    } else {
                                        break;
                                    }
                                }
                                POLL();
                            }
                        }
                        r3 = LD32(r4 + 24);
                        r2 = LD32(r4 + 40);
                        if (r3 >= r2) {
                            r1 = LD32(r4 + 32);
                            r1 = r1 + r2;
                            r0 = 1;
                            if (r3 > r1) {
                                ST32(r4 + 24, r1);
                                r0 = GCALL1(0x060426AC, r4);
                                r0 = 1;
                            }
                        } else {
                            ST32(r4 + 24, r2);
                            r0 = GCALL1(0x060426AC, r4);
                            r0 = 1;
                        }
                    } else {
                        r2 = LD32(r4 + 4);
                        r1 = LD32((((r1 + r3) << 2) + r2) + 4);
                        r1 = LD8(r1);
                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                            r1 = LD32(r4 + 40);
                            r1 = r1 + r5;
                            ST32(r4 + 40, r1);
                            r3 = r1;
                            r1 = LD32(r4 + 32);
                            if (!(r3 >= ((r1 + r3) + 1))) {
                                r7 = 1;
                                while (1) {
                                    r1 = LD32(r4 + 20);
                                    r0 = r3;
                                    if (r3 >= r1) {
                                        break;
                                    } else {
                                        r1 = LD32(r4 + 12);
                                        ST32((r0 << 2) + r1, r7);
                                        r1 = LD32(r4 + 40);
                                        r2 = LD32(r4 + 32);
                                        r3 = r3 + 1;
                                        if (!(r3 >= ((r1 + r2) + 1))) {
                                            POLL();
                                            continue;
                                        } else {
                                            break;
                                        }
                                    }
                                    POLL();
                                }
                            }
                            r3 = LD32(r4 + 24);
                            r2 = LD32(r4 + 40);
                            if (r3 >= r2) {
                                r1 = LD32(r4 + 32);
                                r1 = r1 + r2;
                                r0 = 1;
                                if (r3 > r1) {
                                    ST32(r4 + 24, r1);
                                    r0 = GCALL1(0x060426AC, r4);
                                    r0 = 1;
                                }
                            } else {
                                ST32(r4 + 24, r2);
                                r0 = GCALL1(0x060426AC, r4);
                                r0 = 1;
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
void f06042B84(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12, c0, c3;

    r11 = 0x0608BCD0;
    r1 = LD32(0x0608BCD0);
    c0 = (r1 & r1) == 0;
    r1 = 0;
    if (!(c0)) {
        ST32(0x060769D4, r1);
        r0 = GCALL4(0x0602D5C0, 13, r5, r6, r7);
        r1 = LD32(r11 + 4);
        r9 = 0x060773C8;
        ST32(0x060766C0, r1);
        r1 = LD32(r11 + 8);
        ST32(0x0607668C, r1);
        r1 = LD32(0x060773C8);
        r8 = 0x060773C8;
        if (!((r1 & r1) == 0)) {
            r10 = 0x060791A8;
            r12 = 0x06027F48;
            r8 = r8 + 12;
            do {
                r4 = LD32(r8);
                c3 = r4 == r10;
                if (!((r4 & r4) == 0)) {
                    if (!(c3)) {
                        r0 = GCALL1(r12, r4);
                        ST32(r8, r10);
                    }
                }
                r9 = r9 + 24;
                r1 = LD32(r9);
                r8 = r8 + 24;
            } while (AGAIN(!((r1 & r1) == 0)));
        }
        ST32(r11, 0);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06044648(int r4)
{
    int r0, r1, c1, c3;

    r0 = r4;
    r1 = 51;
    if (r0 > 25) {
        c1 = r0 > r1;
        r1 = 61;
        if (c1) {
            c3 = r0 == 62;
            if (r0 > r1) {
                r0 = 47;
                if (!(c3)) {
                    return r0;
                } else {
                    return 43;
                }
            } else {
                return ((r0 & 63) - 4) & 255;
            }
        } else {
            return ((r0 & 63) + 71) & 255;
        }
    } else {
        return ((r0 & 63) + 65) & 255;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045614(int r4)
{
    int r0, r1, r2, r3, r6, r7, r8, c2;

    r8 = r4;
    r0 = GCALL1(0x060455FC, r4);
    r3 = 0;
    if (r0 > 0) {
        r6 = 128;
        r7 = 0x8140;
        do {
            r1 = LD16(r8);
            r8 = r8 + 2;
            r2 = r1 & 0xFFFF;
            c2 = r2 == r7;
            if (((int)((unsigned)r2 >> 8)) == r6) {
                r3 = r3 + 1;
            } else {
                if (c2) {
                    r3 = r3 + 1;
                }
            }
            r0 = r0 - 1;
        } while (AGAIN(r0 > 0));
    }
    return r3 + 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045760(int r4, int r5)
{
    int r0, r1, r2, r3, c2, c6;

    r3 = LD8(r4);
    r0 = (signed char)r5;
    if (!((unsigned)((r3 + 127) & 255) > (unsigned)30)) {
        r1 = LD8((r4 + 1));
        r2 = (r3 & 255) << 8;
        r1 = (r1 & 255) | r2;
    } else {
        c2 = r0 == 1;
        if ((unsigned)((r3 + 32) & 255) > (unsigned)10) {
            if (!((unsigned)((r3 + 95) & 255) > (unsigned)62)) {
                r1 = LD8(r4);
                r2 = LD8((r4 + 1));
                r0 = GCALL1(0x06045A0C, (((((r1 & 255) - 128) << 8) | ((r2 & 255) - 128)) & 0xFFFF));
                r1 = r0 & 0xFFFF;
            } else {
                if (!((unsigned)((r3 + 21) & 255) > (unsigned)9)) {
                    r1 = LD8(r4);
                    r2 = LD8((r4 + 1));
                    r0 = GCALL1(0x06045A0C, (((((r1 & 255) - 128) << 8) | ((r2 & 255) - 128)) & 0xFFFF));
                    r1 = r0 & 0xFFFF;
                } else {
                    c6 = r0 == 2;
                    if ((unsigned)((r3 + 32) & 255) > (unsigned)10) {
                        r1 = LD8(r4);
                        r2 = 0x8000;
                        r1 = (r1 & 255) | r2;
                    } else {
                        if (!(c6)) {
                            r1 = LD8(r4);
                            r2 = 0x8000;
                            r1 = (r1 & 255) | r2;
                        } else {
                            r1 = LD8(r4);
                            r2 = LD8((r4 + 1));
                            r0 = GCALL1(0x06045A0C, (((((r1 & 255) - 128) << 8) | ((r2 & 255) - 128)) & 0xFFFF));
                            r1 = r0 & 0xFFFF;
                        }
                    }
                }
            }
        } else {
            if (!(c2)) {
                if (!((unsigned)((r3 + 95) & 255) > (unsigned)62)) {
                    r1 = LD8(r4);
                    r2 = LD8((r4 + 1));
                    r0 = GCALL1(0x06045A0C, (((((r1 & 255) - 128) << 8) | ((r2 & 255) - 128)) & 0xFFFF));
                    r1 = r0 & 0xFFFF;
                } else {
                    if (!((unsigned)((r3 + 21) & 255) > (unsigned)9)) {
                        r1 = LD8(r4);
                        r2 = LD8((r4 + 1));
                        r0 = GCALL1(0x06045A0C, (((((r1 & 255) - 128) << 8) | ((r2 & 255) - 128)) & 0xFFFF));
                        r1 = r0 & 0xFFFF;
                    } else {
                        c6 = r0 == 2;
                        if ((unsigned)((r3 + 32) & 255) > (unsigned)10) {
                            r1 = LD8(r4);
                            r2 = 0x8000;
                            r1 = (r1 & 255) | r2;
                        } else {
                            if (!(c6)) {
                                r1 = LD8(r4);
                                r2 = 0x8000;
                                r1 = (r1 & 255) | r2;
                            } else {
                                r1 = LD8(r4);
                                r2 = LD8((r4 + 1));
                                r0 = GCALL1(0x06045A0C, (((((r1 & 255) - 128) << 8) | ((r2 & 255) - 128)) & 0xFFFF));
                                r1 = r0 & 0xFFFF;
                            }
                        }
                    }
                }
            } else {
                r1 = LD8((r4 + 1));
                r2 = (r3 & 255) << 8;
                r1 = (r1 & 255) | r2;
            }
        }
    }
    return r1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06047668(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, c2;

    r8 = 0;
    r1 = LD8(r5);
    r2 = r4;
    while (1) {
        r3 = r1 & 255;
        r0 = r3;
        if ((r3 & r3) == 0) {
            break;
        } else {
            c2 = r8 >= r6;
            if (!(r0 == 38)) {
                POLL();
                if (c2) {
                    break;
                } else {
                    ST8(r2, r1);
                    r5 = r5 + 1;
                    r2 = r2 + 1;
                    r1 = LD8(r5);
                    r8 = r8 + 1;
                    continue;
                }
            } else {
                break;
            }
        }
    }
    ST8(r4 + r8, 0);
    r0 = GCALL1(0x0603FC68, r4);
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06048818(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, c0;

    r9 = LD32(r4 + 8);
    r2 = LD32(r4 + 4);
    r3 = r9 - r2;
    c0 = (r3 & r3) == 0;
    r3 = r3 - 2;
    if (!(c0)) {
        r0 = -1;
        if (r3 >= 0) {
            r1 = LD32(r4);
            r7 = r1 + r2;
            r2 = LD8(r1 + r2);
            r1 = LD8((r7 + 1));
            r6 = ((r2 & 255) << 8) | (r1 & 255);
            r3 = (r3 - 2) - r6;
            r8 = r7;
            if (!(r3 >= 0)) {
                r0 = -1;
            } else {
                r1 = r7 + r6;
                r7 = r1 + 2;
                r2 = LD8(r7);
                r1 = LD8((r1 + 3));
                r10 = ((r2 & 255) << 8) | (r1 & 255);
                r3 = r3 - r10;
                r8 = r8 + 2;
                if (!(r3 >= 0)) {
                    r0 = -1;
                } else {
                    ST32(r4 + 4, (r9 - r3));
                    ST32(r5, r8);
                    ST32(r5 + 4, r6);
                    ST32(r5 + 8, (r7 + 2));
                    ST32(r5 + 12, r10);
                    r0 = 0;
                }
            }
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06048F28(int r4)
{
    int r0, r1, r8, r9, r10, r11, c1;

    r11 = r4;
    r1 = LD32(0x060791C8);
    r10 = 0x06075238;
    r8 = r1 - 1;
    r9 = r8;
    r8 = r8 - 1;
    while (1) {
        c1 = r8 >= 0;
        if (r8 == r9) {
            break;
        } else {
            if (!(c1)) {
                r8 = 31;
            }
            r4 = LD32((((r8 << 2) + r8) << 2) + 0x0608CE90);
            r8 = r8 - 1;
            if ((r4 & r4) == 0) {
                POLL();
                continue;
            } else {
                r0 = GCALL3(r10, r4, 0x06048F20, 7);
                r8 = (r8 + 1) - 1;
                if (!((r0 & r0) == 0)) {
                    POLL();
                    continue;
                } else {
                    r8 = r8 + 1;
                    break;
                }
            }
        }
        POLL();
    }
    r1 = LD32((((r8 << 2) + r8) << 2) + 0x0608CE90);
    ST32(r11, r1);
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604909C(void)
{
    int r0, r1, r2, r3, r6, r7;

    r7 = 0;
    r3 = 0;
    r1 = LD32(0x060791CC);
    r6 = 0x0608CE90;
    r2 = r1 - 1;
    r1 = 31;
    while (1) {
        if (!(r2 >= 0)) {
            r2 = r1;
        }
        r1 = LD32((((r2 << 2) + r2) << 2) + r6);
        if ((r1 & r1) == 0) {
            break;
        } else {
            r7 = r7 + 1;
            r3 = r3 + 1;
            r1 = 31;
            r2 = r2 - 1;
            if (!(r3 > 31)) {
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
    }
    r0 = 0;
    if (!(r7 > 7)) {
        return r0;
    } else {
        return 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049ED0(int r4, int r5, int r6, int r7)
{
    int r0, r8, c1;

    r8 = r5;
    r0 = GCALL4(0x060492D0, r4, r5, r6, r7);
    c1 = r0 == -12;
    if (r0 >= 0) {
        r0 = GCALL1(0x06075438, r8);
    } else {
        r0 = -600;
        if (c1) {
            r0 = -12;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A218(int r4, int r5, int r6)
{
    int r0, r1, r2, c1;

    r6 = r6 & 255;
    r2 = LD8(r5);
    r0 = 0;
    while (1) {
        r1 = r2 & 255;
        c1 = r1 == r6;
        if (!((r1 & r1) == 0)) {
            POLL();
            if (c1) {
                break;
            } else {
                ST8(r4, r2);
                r5 = r5 + 1;
                r4 = r4 + 1;
                r2 = LD8(r5);
                r0 = r0 + 1;
                continue;
            }
        } else {
            break;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A7CC(int r4, int r5)
{
    int r0, r1, r2, r6, r8;
    FRAME(sp, 520);

    r2 = r5;
    r8 = r4;
    if (!((r2 & r2) == 0)) {
        r1 = LD8(r2);
        r6 = r2;
        if (!((r1 & 255) == 64)) {
            r5 = 0x0604A7B8;
            r0 = 0x06045264;
        } else {
            r5 = 0x0604A7B8;
            r0 = 0x06045264;
        }
    } else {
        r5 = 0x0604A7B8;
        r0 = 0x06045264;
    }
    r0 = GCALL2(r0, (sp - 520), r5);
    r0 = GCALL1(0x0607507C, (sp - 520));
    r0 = GCALL3(0x0605ACB8, r8, (sp - 520), r0);
    if (r0 >= 0) {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A898(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11;

    r8 = r4;
    r10 = r5;
    r9 = r6;
    r11 = r7;
    if (!((r8 & r8) == 0)) {
        r0 = GCALL1(0x0607507C, r11);
        r4 = r8;
        if (!((unsigned)((r9 + r0) + 1) > (unsigned)r10)) {
            r0 = GCALL2(0x060750DC, (r4 + r9), r11);
            r0 = GCALL1(0x0607507C, r11);
            r0 = 0;
        } else {
            r0 = GCALL4(0x06027C18, 0, r8, (r10 + 0x400), r7);
            r8 = r0;
            r4 = r8;
            if (!((r8 & r8) == 0)) {
                r0 = GCALL2(0x060750DC, (r4 + r9), r11);
                r0 = GCALL1(0x0607507C, r11);
                r0 = 0;
            } else {
                r0 = -3;
            }
        }
    } else {
        r0 = GCALL4(0x060279E0, 1, 0x400, 15, 1);
        r8 = r0;
        r9 = 0;
        if ((r8 & r8) == 0) {
            r0 = -3;
        } else {
            r4 = r8;
            r0 = GCALL2(0x060750DC, (r4 + r9), r11);
            r0 = GCALL1(0x0607507C, r11);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06040704(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8;
    FRAME(sp, 264);

    r8 = r4;
    if (r6 >= 0) {
        if (!(r6 > 0)) {
            r6 = LD32(r8 + 16);
            r0 = GCALL4(0x060403D0, r8, r5, r6, r7);
            if (!((r0 & r0) == 0)) {
                r1 = LD32(r8 + 52);
                if (!((r1 & r1) == 0)) {
                    r0 = GCALL1(r1, r0);
                }
            } else {
                r1 = LD32(r8 + 44);
                if (!((r1 & r1) == 0)) {
                    r6 = LD32(r8 + 16);
                    r0 = GCALL3(0x06045264, (sp - 264), 0x060406F0, r6);
                    r1 = LD32(r8 + 44);
                    r0 = GCALL1(r1, (sp - 264));
                }
            }
        } else {
            r1 = LD32(r8 + 16);
            r3 = LD32(r8 + 28);
            r1 = r1 + 1;
            ST32(r8 + 16, r1);
            if (!(r1 >= (r3 + 1))) {
                r6 = LD32(r8 + 16);
                r0 = GCALL4(0x060403D0, r8, r5, r6, r7);
                if (!((r0 & r0) == 0)) {
                    r1 = LD32(r8 + 52);
                    if (!((r1 & r1) == 0)) {
                        r0 = GCALL1(r1, r0);
                    }
                } else {
                    r1 = LD32(r8 + 44);
                    if (!((r1 & r1) == 0)) {
                        r6 = LD32(r8 + 16);
                        r0 = GCALL3(0x06045264, (sp - 264), 0x060406F0, r6);
                        r1 = LD32(r8 + 44);
                        r0 = GCALL1(r1, (sp - 264));
                    }
                }
            } else {
                ST32(r8 + 16, (r3 - 1));
            }
        }
    } else {
        r1 = LD32(r8 + 16);
        r1 = r1 - 1;
        ST32(r8 + 16, r1);
        if (r1 > 0) {
            r6 = LD32(r8 + 16);
            r0 = GCALL4(0x060403D0, r8, r5, r6, r7);
            if (!((r0 & r0) == 0)) {
                r1 = LD32(r8 + 52);
                if (!((r1 & r1) == 0)) {
                    r0 = GCALL1(r1, r0);
                }
            } else {
                r1 = LD32(r8 + 44);
                if (!((r1 & r1) == 0)) {
                    r6 = LD32(r8 + 16);
                    r0 = GCALL3(0x06045264, (sp - 264), 0x060406F0, r6);
                    r1 = LD32(r8 + 44);
                    r0 = GCALL1(r1, (sp - 264));
                }
            }
        } else {
            ST32(r8 + 16, 1);
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041810(int r4, int r5)
{
    int r0, r8;

    r0 = GCALL2(0x06041790, r4, (r5 + 0x204));
    r8 = r0;
    if ((r8 & r8) == 0) {
        r0 = GCALL0(0x0605A960);
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604183C(int r4, int r5)
{
    int r0, r8;

    r0 = GCALL2(0x06041790, r4, (r5 + 0x208));
    r8 = r0;
    if ((r8 & r8) == 0) {
        r0 = GCALL0(0x0605A960);
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060419E0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c1, c2, c8;
    FRAME(sp, 40);

    r14 = r4;
    r8 = r5;
    r12 = r6;
    r13 = r7;
    r11 = 82;
    r0 = GCALL4(0x06028254, 0, r5, r6, r7);
    c1 = (r8 & r8) == 0;
    if (r8 > 0) {
        r11 = r8 + 1;
    }
    c2 = r8 >= 0;
    if (c1) {
        r0 = 0;
    } else {
        if (!(c2)) {
            r11 = 22;
        }
        r10 = 0x06028380;
        r0 = GCALL2(0x06028380, 48, 13);
        r9 = r0;
        r6 = 48;
        if ((r9 & r9) == 0) {
            r0 = 0;
        } else {
            r0 = GCALL3(0x0604B3F0, r9, 0, r6);
            r0 = GCALL2(r10, 80, 13);
            ST32(r9 + 4, r0);
            if (!((r0 & r0) == 0)) {
                ST32(r9 + 32, r12);
                ST32(r9 + 36, r13);
                if (r8 >= 0) {
                    ST32(r9 + 8, 0);
                    r0 = GCALL2(0x06028380, 80, 13);
                    ST32(r9 + 12, r0);
                    if (!((r0 & r0) == 0)) {
                        c8 = r8 > 0;
                        ST32(r9, c8);
                        ST32(r9 + 16, r8);
                        if (!(c8)) {
                            ST32(r9 + 16, -1);
                        }
                        r8 = 0;
                        r10 = 0x06027F48;
                        r5 = 13;
                        while (1) {
                            r0 = GCALL2(0x06028380, r11, r5);
                            r2 = r0;
                            r3 = r8 << 2;
                            r1 = LD32(r9 + 4);
                            r0 = r3;
                            ST32(r0 + r1, r2);
                            r1 = LD32(r9 + 4);
                            r1 = LD32(r0 + r1);
                            if (!((r1 & r1) == 0)) {
                                r1 = LD32(r9);
                                if ((r1 & r1) == 0) {
                                    r0 = LD32(r9 + 8);
                                    ST32(r0 + r3, r11);
                                }
                                r0 = LD32(r9 + 4);
                                r2 = LD32(r0 + r3);
                                r8 = r8 + 1;
                                ST8(r2, 0);
                                r0 = LD32(r9 + 12);
                                ST32(r0 + r3, 1);
                                r5 = 13;
                                if (!(r8 > 19)) {
                                    POLL();
                                    continue;
                                } else {
                                    ST32(r9 + 20, 20);
                                    ST32(r9 + 24, 0);
                                    ST32(r9 + 28, 0);
                                    ST32(r9 + 40, 0);
                                    ST32(r9 + 44, 0);
                                    ST32(sp - 40, 0);
                                    ST32(sp - 36, 0);
                                    r0 = GCALL6(0x06041ED8, r9, r14, (sp - 40), (sp - 36), LD32((sp - 40)), LD32((sp - 36)));
                                    r0 = r9;
                                    break;
                                }
                            } else {
                                r8 = r8 - 1;
                                while (1) {
                                    r0 = r8;
                                    if (r8 >= 0) {
                                        POLL();
                                        r1 = LD32(r9 + 4);
                                        r4 = LD32((r0 << 2) + r1);
                                        r0 = GCALL1(r10, r4);
                                        r8 = r8 - 1;
                                        continue;
                                    } else {
                                        break;
                                    }
                                }
                                r4 = LD32(r9 + 8);
                                r0 = GCALL1(r10, r4);
                                r4 = LD32(r9 + 4);
                                r0 = GCALL1(r10, r4);
                                r4 = LD32(r9 + 12);
                                r0 = GCALL1(r10, r4);
                                r0 = GCALL1(r10, r9);
                                r0 = 0;
                                break;
                            }
                            POLL();
                        }
                    } else {
                        r8 = 0x06027F48;
                        r4 = LD32(r9 + 8);
                        r0 = GCALL1(0x06027F48, r4);
                        r4 = LD32(r9 + 4);
                        r0 = GCALL1(r8, r4);
                        r0 = GCALL1(r8, r9);
                        r0 = 0;
                    }
                } else {
                    r0 = GCALL2(r10, 80, 13);
                    ST32(r9 + 8, r0);
                    if (!((r0 & r0) == 0)) {
                        r0 = GCALL2(0x06028380, 80, 13);
                        ST32(r9 + 12, r0);
                        if (!((r0 & r0) == 0)) {
                            c8 = r8 > 0;
                            ST32(r9, c8);
                            ST32(r9 + 16, r8);
                            if (!(c8)) {
                                ST32(r9 + 16, -1);
                            }
                            r8 = 0;
                            r10 = 0x06027F48;
                            r5 = 13;
                            while (1) {
                                r0 = GCALL2(0x06028380, r11, r5);
                                r2 = r0;
                                r3 = r8 << 2;
                                r1 = LD32(r9 + 4);
                                r0 = r3;
                                ST32(r0 + r1, r2);
                                r1 = LD32(r9 + 4);
                                r1 = LD32(r0 + r1);
                                if (!((r1 & r1) == 0)) {
                                    r1 = LD32(r9);
                                    if ((r1 & r1) == 0) {
                                        r0 = LD32(r9 + 8);
                                        ST32(r0 + r3, r11);
                                    }
                                    r0 = LD32(r9 + 4);
                                    r2 = LD32(r0 + r3);
                                    r8 = r8 + 1;
                                    ST8(r2, 0);
                                    r0 = LD32(r9 + 12);
                                    ST32(r0 + r3, 1);
                                    r5 = 13;
                                    if (!(r8 > 19)) {
                                        POLL();
                                        continue;
                                    } else {
                                        ST32(r9 + 20, 20);
                                        ST32(r9 + 24, 0);
                                        ST32(r9 + 28, 0);
                                        ST32(r9 + 40, 0);
                                        ST32(r9 + 44, 0);
                                        ST32(sp - 40, 0);
                                        ST32(sp - 36, 0);
                                        r0 = GCALL6(0x06041ED8, r9, r14, (sp - 40), (sp - 36), LD32((sp - 40)), LD32((sp - 36)));
                                        r0 = r9;
                                        break;
                                    }
                                } else {
                                    r8 = r8 - 1;
                                    while (1) {
                                        r0 = r8;
                                        if (r8 >= 0) {
                                            POLL();
                                            r1 = LD32(r9 + 4);
                                            r4 = LD32((r0 << 2) + r1);
                                            r0 = GCALL1(r10, r4);
                                            r8 = r8 - 1;
                                            continue;
                                        } else {
                                            break;
                                        }
                                    }
                                    r4 = LD32(r9 + 8);
                                    r0 = GCALL1(r10, r4);
                                    r4 = LD32(r9 + 4);
                                    r0 = GCALL1(r10, r4);
                                    r4 = LD32(r9 + 12);
                                    r0 = GCALL1(r10, r4);
                                    r0 = GCALL1(r10, r9);
                                    r0 = 0;
                                    break;
                                }
                                POLL();
                            }
                        } else {
                            r8 = 0x06027F48;
                            r4 = LD32(r9 + 8);
                            r0 = GCALL1(0x06027F48, r4);
                            r4 = LD32(r9 + 4);
                            r0 = GCALL1(r8, r4);
                            r0 = GCALL1(r8, r9);
                            r0 = 0;
                        }
                    } else {
                        r8 = 0x06027F48;
                        r4 = LD32(r9 + 4);
                        r0 = GCALL1(r8, r4);
                        r0 = GCALL1(r8, r9);
                        r0 = 0;
                    }
                }
            } else {
                r0 = GCALL1(0x06027F48, r9);
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06042468(int r4)
{
    int r0, r1, r8, r9, r10;

    r9 = r4;
    r1 = LD32(r9 + 20);
    r8 = 0;
    r0 = 0;
    if (!(0 >= r1)) {
        r10 = 0x06027F48;
        do {
            r1 = LD32(r9 + 4);
            r4 = LD32((r0 << 2) + r1);
            r0 = GCALL1(r10, r4);
            r1 = LD32(r9 + 20);
            r8 = r8 + 1;
            r0 = r8;
        } while (AGAIN(!(r8 >= r1)));
    }
    r4 = LD32(r9 + 8);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
    }
    r4 = LD32(r9 + 12);
    r0 = GCALL1(0x06027F48, r4);
    r4 = LD32(r9 + 4);
    r0 = GCALL1(0x06027F48, r4);
    r0 = GCALL1(0x06027F48, r9);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06044594(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r4 = LD32(r8);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
            ST32(r8, 0);
        }
        r4 = LD32(r8 + 4);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
            ST32(r8 + 4, 0);
        }
        r4 = LD32(r8 + 8);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
            ST32(r8 + 8, 0);
        }
        r4 = LD32(r8 + 12);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
            ST32(r8 + 12, 0);
        }
        r4 = LD32(r8 + 16);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
            ST32(r8 + 16, 0);
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060445F8(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r0 = GCALL4(0x06044594, r4, r5, r6, r7);
        r0 = GCALL1(0x06027F48, r8);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045BFC(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, c0;

    r10 = r4;
    r9 = r5;
    r0 = GCALL1(0x0607507C, r4);
    r8 = r0;
    c0 = (r8 & r8) == 0;
    r8 = r8 + r8;
    if (c0) {
        r0 = 1;
    } else {
        r8 = r8 + 2;
        r7 = 1;
        if ((unsigned)r8 > (unsigned)r9) {
            r0 = 0;
        } else {
            r0 = GCALL4(0x060279E0, 0, r8, -1, r7);
            r9 = r0;
            r2 = r10;
            if (!((r9 & r9) == 0)) {
                r1 = LD8(r10);
                r0 = r9;
                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                    r3 = -128;
                    do {
                        ST8(r0, r3);
                        r1 = LD8(r2);
                        r2 = r2 + 1;
                        r0 = r0 + 1;
                        ST8(r0, r1);
                        r1 = LD8(r2);
                        r0 = r0 + 1;
                    } while (AGAIN(!(((r1 & 255) & (r1 & 255)) == 0)));
                }
                ST8(r0, 0);
                ST8((r0 + 1), 0);
                r0 = GCALL3(0x0604B358, r10, r9, r8);
                r0 = GCALL1(0x06027F48, r9);
                r0 = 1;
            } else {
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06048B28(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12, r13, c1;
    FRAME(sp, 76);

    r8 = 0x06048B1C;
    r0 = GCALL4(0x06025948, 0x06048B1C, 0, r6, r7);
    r11 = r0;
    r9 = 0x060279E0;
    r0 = GCALL4(0x060279E0, 0, (r11 + 1), -1, 1);
    r10 = r0;
    r6 = 48;
    if (!((r10 & r10) == 0)) {
        r13 = 0x0604B3F0;
        r0 = GCALL3(0x0604B3F0, (sp - 76), 0, r6);
        r0 = GCALL4(0x060258EC, r8, (sp - 76), r10, r11);
        r0 = GCALL1(0x06025984, (sp - 76));
        c1 = (r0 & r0) == 0;
        r7 = c1;
        if (!(c1)) {
            r0 = GCALL1(0x06027F48, r10);
        } else {
            r12 = 0x14C;
            r0 = GCALL4(r9, 0, 0x14C, -1, r7);
            r9 = r0;
            ST32(0x060791C4, r9);
            if ((r9 & r9) == 0) {
                r0 = GCALL1(0x06027F48, r10);
            } else {
                r0 = GCALL3(r13, r9, 0, r12);
                r0 = r9;
                ST32(r0 + 252, r10);
                ST32(r0 + 0x100, r11);
                ST32(r0 + 0x104, 0);
                ST32(r0 + 0x108, -1);
                ST32(r0 + 0x10C, r11);
                r0 = GCALL3(0x06026208, r9, 0, 1);
                ST32(r9 + 12, 1);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06048CC0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10;

    if (!((unsigned)r4 > (unsigned)31)) {
        r8 = ((r4 << 2) + r4) << 2;
        r10 = 0x0608CE90;
        r4 = LD32(r8 + 0x0608CE90);
        r9 = r8 + 0x0608CE90;
        if (!((r4 & r4) == 0)) {
            r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
            ST32(r8 + r10, 0);
        }
        r4 = LD32(r9 + 4);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
            ST32(r9 + 4, 0);
        }
        r4 = LD32(r9 + 8);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
            ST32(r9 + 8, 0);
        }
        r4 = LD32(r9 + 12);
        r1 = 0;
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
            ST32(r9 + 12, 0);
            r1 = 0;
        }
        ST32(r9 + 16, r1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049370(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10;

    r10 = r4;
    r9 = r5;
    r8 = r6;
    while (1) {
        r0 = GCALL0(0x0605299C);
        r0 = GCALL3(0x0605ACB8, r10, r9, r8);
        r1 = LD32(0x060766B4);
        if ((r1 & r1) == 0) {
            if (!(r0 > 0)) {
                if (r0 == -502) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            } else {
                r0 = 0;
                break;
            }
        } else {
            r0 = -12;
            break;
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A4DC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, c13, c15;
    FRAME(sp, 540);

    r8 = r4;
    r10 = r5;
    r11 = r6;
    r12 = r7;
    r9 = LD32((0x21C + (sp - 540)));
    r0 = GCALL3(0x06075238, r9, 0x0604A478, 4);
    r6 = r12;
    if (!((r0 & r0) == 0)) {
        r8 = 0x06075830;
        r0 = GCALL2(0x06075830, r9, 0x0604A490);
        if (!((r0 & r0) == 0)) {
            r0 = -1000;
        } else {
            r0 = GCALL3(r8, r9, 0x0604A498, r6);
            if (!((r0 & r0) == 0)) {
                r0 = -1000;
            } else {
                r0 = GCALL2(r8, r9, 0x0604A4A0);
                if ((r0 & r0) == 0) {
                    r0 = GCALL2(r8, r9, 0x0604A4CC);
                    if ((r0 & r0) == 0) {
                        r0 = GCALL2(r8, r9, 0x0604A4D4);
                        r8 = r0;
                        r4 = r9;
                        if ((r8 & r8) == 0) {
                            r0 = -1;
                        } else {
                            r2 = LD8(r4);
                            r8 = r8 + 8;
                            while (1) {
                                r0 = r2 & 255;
                                if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                    POLL();
                                    if (r0 == 58) {
                                        break;
                                    } else {
                                        r4 = r4 + 1;
                                        r2 = LD8(r4);
                                        continue;
                                    }
                                } else {
                                    break;
                                }
                            }
                            r0 = GCALL3(0x0604A218, r10, (r4 + 1), 33);
                            ST8(r0 + r10, 0);
                            while (1) {
                                r2 = LD8(r8);
                                r0 = r2 & 255;
                                if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                    POLL();
                                    if (r0 == 58) {
                                        break;
                                    } else {
                                        r8 = r8 + 1;
                                        continue;
                                    }
                                } else {
                                    break;
                                }
                            }
                            r1 = LD8(r8);
                            r0 = -1;
                            if ((r1 & 255) == 58) {
                                r0 = GCALL2(0x060750DC, r11, (r8 + 1));
                                r1 = LD8(r11);
                                r0 = r1 & 255;
                                c13 = r0 == 10;
                                if (r0 == 47) {
                                    r0 = -1;
                                } else {
                                    r8 = r11;
                                    if (!(c13)) {
                                        r1 = LD8(r8);
                                        r1 = r1 & 255;
                                        do {
                                            r8 = r8 + 1;
                                            r1 = LD8(r8);
                                            c15 = (r1 & 255) == 10;
                                            r1 = r1 & 255;
                                        } while (AGAIN(!(c15)));
                                    }
                                    r1 = LD8(r8);
                                    r0 = 0;
                                    if ((r1 & 255) == 10) {
                                        ST8(r8, 0);
                                    }
                                }
                            }
                        }
                    } else {
                        r0 = -1000;
                    }
                } else {
                    r0 = GCALL1(0x0602BA00, r9);
                    r0 = GCALL3(0x0604A218, (sp - 540), (r9 + 1), 33);
                    ST8(r0 + (sp - 540), 0);
                    r2 = LD8(0x0604A4A8);
                    ST8(r10, r2);
                    r3 = LD8(0x0604A4A9);
                    r2 = r10 + 1;
                    ST8(r2, r3);
                    r3 = LD8(0x0604A4AA);
                    r2 = r2 + 1;
                    ST8(r2, r3);
                    r3 = LD8(0x0604A4AB);
                    r2 = r2 + 1;
                    ST8(r2, r3);
                    r3 = LD8(0x0604A4AC);
                    r2 = r2 + 1;
                    ST8(r2, r3);
                    r3 = LD8(0x0604A4AD);
                    r2 = r2 + 1;
                    ST8(r2, r3);
                    r3 = LD8(0x0604A4AE);
                    r2 = r2 + 1;
                    ST8(r2, r3);
                    r1 = LD8(0x0604A4AF);
                    ST8((r2 + 1), r1);
                    r0 = GCALL4(0x06045264, r11, 0x0604A4B0, (sp - 540), r12);
                    r0 = -1002;
                }
            }
        }
    } else {
        r7 = LD32(0x060791D0);
        r0 = GCALL4(0x06045264, r9, 0x0604A480, r6, r7);
        r0 = GCALL1(0x0607507C, r9);
        r0 = GCALL3(0x06049370, r8, r9, r0);
        if (r0 >= 0) {
            r0 = -1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A83C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9;

    r9 = r4;
    r1 = LD32(r9);
    r0 = 0;
    if (r1 >= 0) {
        if (!((r5 & r5) == 0)) {
            r0 = GCALL4(0x06045264, 0x0608D110, 0x0604A834, r6, r7);
            r0 = GCALL1(0x0607507C, 0x0608D110);
            r4 = LD32(r9);
            r0 = GCALL3(0x0605ACB8, r4, 0x0608D110, r0);
        }
        r4 = LD32(r9);
        r0 = GCALL1(0x0605926C, r4);
        ST32(r9, -1);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A9E4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c16;
    FRAME(sp, 1072);

    r12 = r4;
    ST32(0x408 + (sp - 1072), r5);
    r11 = r6;
    r8 = r7;
    r2 = 0x06075984;
    r1 = LD32(0x06075984);
    r9 = LD32((0x430 + (sp - 1072)));
    if ((r1 & r1) == 0) {
        ST32(r2, 0x06079488);
    }
    if (!((r8 & r8) == 0)) {
        r2 = LD32(r12 + 12);
        r1 = r2;
        if (r2 > 29) {
            r4 = LD32(r12 + 52);
            ST32(r12 + 60, 0);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
            }
            r4 = LD32(r12 + 56);
            r10 = 0;
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(0x06027F48, r4);
            }
            r6 = 28;
            do {
                r3 = r12 + (((r10 + r10) + r10) << 2);
                r7 = r10 + 1;
                r2 = r12 + (((r7 + r7) + r7) << 2);
                r1 = LD32(r2 + 52);
                ST32(r3 + 52, r1);
                r1 = LD32(r2 + 56);
                r10 = r7;
                ST32(r3 + 56, r1);
                r1 = LD32(r2 + 60);
                ST32(r3 + 60, r1);
            } while (AGAIN(!(r10 > r6)));
            ST32(r12 + 12, 29);
            r2 = LD32(r12 + 12);
            r1 = r2;
        }
        ST32(((((r1 + r1) + r2) << 2) + r12) + 60, r9);
        r9 = 0x0607507C;
        r0 = GCALL1(0x0607507C, r8);
        r10 = 0x060279E0;
        r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
        r2 = LD32(r12 + 12);
        ST32(((((r2 + r2) + r2) << 2) + r12) + 52, r0);
        r2 = LD32(r12 + 12);
        r4 = LD32(((((r2 + r2) + r2) << 2) + r12) + 52);
        if (!((r4 & r4) == 0)) {
            r13 = 0x060750DC;
            r0 = GCALL2(0x060750DC, r4, r8);
            if ((r11 & r11) == 0) {
                r1 = LD32(r12 + 12);
                ST32(r12 + 12, (r1 + 1));
                r8 = 0x0607507C;
                r13 = 0;
                r0 = GCALL1(0x0607507C, 0x060792CC);
                r4 = LD32(0x06075984);
                r10 = r0;
                r0 = GCALL1(0x0607507C, r4);
                r11 = r10 + r0;
                r0 = GCALL1(0x0607507C, 0x06079370);
                r4 = LD32(0x06075984);
                r10 = r0;
                r0 = GCALL1(0x0607507C, r4);
                r11 = r11 + (r10 + r0);
                r10 = 0;
                r9 = r12;
                do {
                    r4 = LD32(r9 + 52);
                    if (!((r4 & r4) == 0)) {
                        r13 = r13 + 1;
                        r0 = GCALL1(r8, r4);
                        r11 = r11 + ((r0 << 2) + r0);
                    }
                    r4 = LD32(r9 + 56);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(r8, r4);
                        r11 = r11 + ((r0 << 2) + r0);
                    }
                    r10 = r10 + 1;
                    r9 = r9 + 12;
                } while (AGAIN(!(r10 > 29)));
                r0 = GCALL1(0x0607507C, 0x0607945C);
                r0 = GCALL4(0x060279E0, 0, ((r11 + (r0 * r13)) + 1), -1, 1);
                r13 = r0;
                if (!((r13 & r13) == 0)) {
                    r6 = LD32(0x06075984);
                    r8 = 0x06045264;
                    r0 = GCALL3(0x06045264, r13, 0x060792CC, r6);
                    r10 = 0;
                    r11 = 0x400;
                    r14 = 0x404;
                    ST32(0x40C + (sp - 1072), ((sp - 1072) + 0x404));
                    r9 = r12;
                    do {
                        r1 = LD32(r9 + 52);
                        c16 = (r1 & r1) == 0;
                        r1 = 0;
                        if (!(c16)) {
                            r0 = sp - 1072;
                            ST32(r0 + r11, r1);
                            ST32(r0 + r14, r1);
                            r5 = LD32(r9 + 56);
                            r0 = GCALL4(0x06018688, ((sp - 1072) + r11), r5, 0, 0);
                            r5 = LD32(r9 + 52);
                            r4 = LD32((0x40C + (sp - 1072)));
                            r0 = GCALL4(0x06018688, r4, r5, 0, 0);
                            r1 = LD32(r9 + 60);
                            r0 = sp - 1072;
                            if ((r1 & r1) == 0) {
                                r7 = LD32(r0 + r14);
                                r5 = 0x0607945C;
                            } else {
                                r5 = 0x06079438;
                                r7 = LD32(r0 + r14);
                            }
                            r6 = LD32(r0 + r11);
                            r0 = GCALL4(r8, (sp - 1072), r5, r6, r7);
                            r0 = GCALL2(0x06075408, r13, (sp - 1072));
                            r0 = sp - 1072;
                            r4 = LD32(r0 + r11);
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(0x06027F48, r4);
                                r0 = sp - 1072;
                            }
                            r4 = LD32(r0 + r14);
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(0x06027F48, r4);
                            }
                        }
                        r10 = r10 + 1;
                        r9 = r9 + 12;
                    } while (AGAIN(!(r10 > 29)));
                    r8 = LD32(0x06075984);
                    r0 = GCALL1(0x0607507C, r13);
                    r0 = GCALL3(0x06045264, (r13 + r0), 0x06079370, r8);
                    r0 = LD32((0x408 + (sp - 1072)));
                    r4 = LD32(r0);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                    }
                    r0 = LD32((0x408 + (sp - 1072)));
                    ST32(r0, r13);
                }
            } else {
                r5 = LD32(r12 + 16);
                r0 = GCALL2(0x06075104, r11, r5);
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL1(r9, r11);
                    r0 = GCALL4(r10, 0, (r0 + 1), -1, 1);
                    r2 = LD32(r12 + 12);
                    ST32(((((r2 + r2) + r2) << 2) + r12) + 56, r0);
                    r2 = LD32(r12 + 12);
                    r4 = LD32(((((r2 + r2) + r2) << 2) + r12) + 56);
                    r5 = r11;
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL2(r13, r4, r5);
                        r1 = LD32(r12 + 12);
                        ST32(r12 + 12, (r1 + 1));
                        r8 = 0x0607507C;
                        r13 = 0;
                        r0 = GCALL1(0x0607507C, 0x060792CC);
                        r4 = LD32(0x06075984);
                        r10 = r0;
                        r0 = GCALL1(0x0607507C, r4);
                        r11 = r10 + r0;
                        r0 = GCALL1(0x0607507C, 0x06079370);
                        r4 = LD32(0x06075984);
                        r10 = r0;
                        r0 = GCALL1(0x0607507C, r4);
                        r11 = r11 + (r10 + r0);
                        r10 = 0;
                        r9 = r12;
                        do {
                            r4 = LD32(r9 + 52);
                            if (!((r4 & r4) == 0)) {
                                r13 = r13 + 1;
                                r0 = GCALL1(r8, r4);
                                r11 = r11 + ((r0 << 2) + r0);
                            }
                            r4 = LD32(r9 + 56);
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(r8, r4);
                                r11 = r11 + ((r0 << 2) + r0);
                            }
                            r10 = r10 + 1;
                            r9 = r9 + 12;
                        } while (AGAIN(!(r10 > 29)));
                        r0 = GCALL1(0x0607507C, 0x0607945C);
                        r0 = GCALL4(0x060279E0, 0, ((r11 + (r0 * r13)) + 1), -1, 1);
                        r13 = r0;
                        if (!((r13 & r13) == 0)) {
                            r6 = LD32(0x06075984);
                            r8 = 0x06045264;
                            r0 = GCALL3(0x06045264, r13, 0x060792CC, r6);
                            r10 = 0;
                            r11 = 0x400;
                            r14 = 0x404;
                            ST32(0x40C + (sp - 1072), ((sp - 1072) + 0x404));
                            r9 = r12;
                            do {
                                r1 = LD32(r9 + 52);
                                c16 = (r1 & r1) == 0;
                                r1 = 0;
                                if (!(c16)) {
                                    r0 = sp - 1072;
                                    ST32(r0 + r11, r1);
                                    ST32(r0 + r14, r1);
                                    r5 = LD32(r9 + 56);
                                    r0 = GCALL4(0x06018688, ((sp - 1072) + r11), r5, 0, 0);
                                    r5 = LD32(r9 + 52);
                                    r4 = LD32((0x40C + (sp - 1072)));
                                    r0 = GCALL4(0x06018688, r4, r5, 0, 0);
                                    r1 = LD32(r9 + 60);
                                    r0 = sp - 1072;
                                    if ((r1 & r1) == 0) {
                                        r7 = LD32(r0 + r14);
                                        r5 = 0x0607945C;
                                    } else {
                                        r5 = 0x06079438;
                                        r7 = LD32(r0 + r14);
                                    }
                                    r6 = LD32(r0 + r11);
                                    r0 = GCALL4(r8, (sp - 1072), r5, r6, r7);
                                    r0 = GCALL2(0x06075408, r13, (sp - 1072));
                                    r0 = sp - 1072;
                                    r4 = LD32(r0 + r11);
                                    if (!((r4 & r4) == 0)) {
                                        r0 = GCALL1(0x06027F48, r4);
                                        r0 = sp - 1072;
                                    }
                                    r4 = LD32(r0 + r14);
                                    if (!((r4 & r4) == 0)) {
                                        r0 = GCALL1(0x06027F48, r4);
                                    }
                                }
                                r10 = r10 + 1;
                                r9 = r9 + 12;
                            } while (AGAIN(!(r10 > 29)));
                            r8 = LD32(0x06075984);
                            r0 = GCALL1(0x0607507C, r13);
                            r0 = GCALL3(0x06045264, (r13 + r0), 0x06079370, r8);
                            r0 = LD32((0x408 + (sp - 1072)));
                            r4 = LD32(r0);
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(0x06027F48, r4);
                            }
                            r0 = LD32((0x408 + (sp - 1072)));
                            ST32(r0, r13);
                        }
                    }
                } else {
                    r4 = LD32(r12 + 16);
                    r0 = GCALL1(r9, r4);
                    r0 = GCALL4(r10, 0, (r0 + 1), -1, 1);
                    r2 = LD32(r12 + 12);
                    ST32(((((r2 + r2) + r2) << 2) + r12) + 56, r0);
                    r2 = LD32(r12 + 12);
                    r4 = LD32(((((r2 + r2) + r2) << 2) + r12) + 56);
                    if (!((r4 & r4) == 0)) {
                        r5 = LD32(r12 + 16);
                        r0 = GCALL2(r13, r4, r5);
                        r1 = LD32(r12 + 12);
                        ST32(r12 + 12, (r1 + 1));
                        r8 = 0x0607507C;
                        r13 = 0;
                        r0 = GCALL1(0x0607507C, 0x060792CC);
                        r4 = LD32(0x06075984);
                        r10 = r0;
                        r0 = GCALL1(0x0607507C, r4);
                        r11 = r10 + r0;
                        r0 = GCALL1(0x0607507C, 0x06079370);
                        r4 = LD32(0x06075984);
                        r10 = r0;
                        r0 = GCALL1(0x0607507C, r4);
                        r11 = r11 + (r10 + r0);
                        r10 = 0;
                        r9 = r12;
                        do {
                            r4 = LD32(r9 + 52);
                            if (!((r4 & r4) == 0)) {
                                r13 = r13 + 1;
                                r0 = GCALL1(r8, r4);
                                r11 = r11 + ((r0 << 2) + r0);
                            }
                            r4 = LD32(r9 + 56);
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(r8, r4);
                                r11 = r11 + ((r0 << 2) + r0);
                            }
                            r10 = r10 + 1;
                            r9 = r9 + 12;
                        } while (AGAIN(!(r10 > 29)));
                        r0 = GCALL1(0x0607507C, 0x0607945C);
                        r0 = GCALL4(0x060279E0, 0, ((r11 + (r0 * r13)) + 1), -1, 1);
                        r13 = r0;
                        if (!((r13 & r13) == 0)) {
                            r6 = LD32(0x06075984);
                            r8 = 0x06045264;
                            r0 = GCALL3(0x06045264, r13, 0x060792CC, r6);
                            r10 = 0;
                            r11 = 0x400;
                            r14 = 0x404;
                            ST32(0x40C + (sp - 1072), ((sp - 1072) + 0x404));
                            r9 = r12;
                            do {
                                r1 = LD32(r9 + 52);
                                c16 = (r1 & r1) == 0;
                                r1 = 0;
                                if (!(c16)) {
                                    r0 = sp - 1072;
                                    ST32(r0 + r11, r1);
                                    ST32(r0 + r14, r1);
                                    r5 = LD32(r9 + 56);
                                    r0 = GCALL4(0x06018688, ((sp - 1072) + r11), r5, 0, 0);
                                    r5 = LD32(r9 + 52);
                                    r4 = LD32((0x40C + (sp - 1072)));
                                    r0 = GCALL4(0x06018688, r4, r5, 0, 0);
                                    r1 = LD32(r9 + 60);
                                    r0 = sp - 1072;
                                    if ((r1 & r1) == 0) {
                                        r7 = LD32(r0 + r14);
                                        r5 = 0x0607945C;
                                    } else {
                                        r5 = 0x06079438;
                                        r7 = LD32(r0 + r14);
                                    }
                                    r6 = LD32(r0 + r11);
                                    r0 = GCALL4(r8, (sp - 1072), r5, r6, r7);
                                    r0 = GCALL2(0x06075408, r13, (sp - 1072));
                                    r0 = sp - 1072;
                                    r4 = LD32(r0 + r11);
                                    if (!((r4 & r4) == 0)) {
                                        r0 = GCALL1(0x06027F48, r4);
                                        r0 = sp - 1072;
                                    }
                                    r4 = LD32(r0 + r14);
                                    if (!((r4 & r4) == 0)) {
                                        r0 = GCALL1(0x06027F48, r4);
                                    }
                                }
                                r10 = r10 + 1;
                                r9 = r9 + 12;
                            } while (AGAIN(!(r10 > 29)));
                            r8 = LD32(0x06075984);
                            r0 = GCALL1(0x0607507C, r13);
                            r0 = GCALL3(0x06045264, (r13 + r0), 0x06079370, r8);
                            r0 = LD32((0x408 + (sp - 1072)));
                            r4 = LD32(r0);
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(0x06027F48, r4);
                            }
                            r0 = LD32((0x408 + (sp - 1072)));
                            ST32(r0, r13);
                        }
                    }
                }
            }
        }
    } else {
        r8 = 0x0607507C;
        r13 = 0;
        r0 = GCALL1(0x0607507C, 0x060792CC);
        r4 = LD32(0x06075984);
        r10 = r0;
        r0 = GCALL1(0x0607507C, r4);
        r11 = r10 + r0;
        r0 = GCALL1(0x0607507C, 0x06079370);
        r4 = LD32(0x06075984);
        r10 = r0;
        r0 = GCALL1(0x0607507C, r4);
        r11 = r11 + (r10 + r0);
        r10 = 0;
        r9 = r12;
        do {
            r4 = LD32(r9 + 52);
            if (!((r4 & r4) == 0)) {
                r13 = r13 + 1;
                r0 = GCALL1(r8, r4);
                r11 = r11 + ((r0 << 2) + r0);
            }
            r4 = LD32(r9 + 56);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(r8, r4);
                r11 = r11 + ((r0 << 2) + r0);
            }
            r10 = r10 + 1;
            r9 = r9 + 12;
        } while (AGAIN(!(r10 > 29)));
        r0 = GCALL1(0x0607507C, 0x0607945C);
        r0 = GCALL4(0x060279E0, 0, ((r11 + (r0 * r13)) + 1), -1, 1);
        r13 = r0;
        if (!((r13 & r13) == 0)) {
            r6 = LD32(0x06075984);
            r8 = 0x06045264;
            r0 = GCALL3(0x06045264, r13, 0x060792CC, r6);
            r10 = 0;
            r11 = 0x400;
            r14 = 0x404;
            ST32(0x40C + (sp - 1072), ((sp - 1072) + 0x404));
            r9 = r12;
            do {
                r1 = LD32(r9 + 52);
                c16 = (r1 & r1) == 0;
                r1 = 0;
                if (!(c16)) {
                    r0 = sp - 1072;
                    ST32(r0 + r11, r1);
                    ST32(r0 + r14, r1);
                    r5 = LD32(r9 + 56);
                    r0 = GCALL4(0x06018688, ((sp - 1072) + r11), r5, 0, 0);
                    r5 = LD32(r9 + 52);
                    r4 = LD32((0x40C + (sp - 1072)));
                    r0 = GCALL4(0x06018688, r4, r5, 0, 0);
                    r1 = LD32(r9 + 60);
                    r0 = sp - 1072;
                    if ((r1 & r1) == 0) {
                        r7 = LD32(r0 + r14);
                        r5 = 0x0607945C;
                    } else {
                        r5 = 0x06079438;
                        r7 = LD32(r0 + r14);
                    }
                    r6 = LD32(r0 + r11);
                    r0 = GCALL4(r8, (sp - 1072), r5, r6, r7);
                    r0 = GCALL2(0x06075408, r13, (sp - 1072));
                    r0 = sp - 1072;
                    r4 = LD32(r0 + r11);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                        r0 = sp - 1072;
                    }
                    r4 = LD32(r0 + r14);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                    }
                }
                r10 = r10 + 1;
                r9 = r9 + 12;
            } while (AGAIN(!(r10 > 29)));
            r8 = LD32(0x06075984);
            r0 = GCALL1(0x0607507C, r13);
            r0 = GCALL3(0x06045264, (r13 + r0), 0x06079370, r8);
            r0 = LD32((0x408 + (sp - 1072)));
            r4 = LD32(r0);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(0x06027F48, r4);
            }
            r0 = LD32((0x408 + (sp - 1072)));
            ST32(r0, r13);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604B0E0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, c9;
    FRAME(sp, 28);

    r10 = r4;
    r9 = r5;
    r11 = r6;
    r1 = LD32(0x060791E0);
    r6 = -1;
    r12 = LD32(sp);
    if (!(r1 > 0)) {
        r4 = LD32(r10);
        ST32((sp - 28), 0x0608D110);
        r0 = GCALL5(0x0604A6B8, r4, r9, r11, r7, LD32((sp - 28)));
        r6 = r0;
    } else {
        r3 = 0x0608D110;
        r2 = LD8(0x0608D110);
        while (1) {
            r0 = r2 & 255;
            if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                POLL();
                if (r0 == 13) {
                    break;
                } else {
                    r3 = r3 + 1;
                    r2 = LD8(r3);
                    continue;
                }
            } else {
                break;
            }
        }
        r1 = LD8(r3);
        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
            r4 = LD32(r10);
            ST32((sp - 28), (r3 + 2));
            r0 = GCALL5(0x0604A4DC, r4, r9, r11, r7, LD32((sp - 28)));
            r6 = r0;
        }
        ST32(0x060791E0, 0);
    }
    r1 = 0;
    if (!(r6 == -1000)) {
        c9 = (r6 & r6) == 0;
        if (!(r6 == -1002)) {
            r0 = -1;
            if (c9) {
                ST32(r12, 0);
                r5 = LD32(r10 + 16);
                r0 = GCALL2(0x06075830, 0x0608D110, r5);
                r1 = 1;
                if ((r0 & r0) == 0) {
                    POLL();
                } else {
                    ST32(r12, r1);
                    POLL();
                }
                r0 = 0;
            }
        } else {
            ST32(0x060791E0, 0);
            r0 = GCALL1(0x0604AD10, r10);
            r0 = GCALL1(0x0602CC0C, 0);
            ST32(r12, 0);
            r0 = 0;
        }
    } else {
        ST32(0x060791E0, r1);
        r0 = GCALL1(0x0604AD10, r10);
        r0 = GCALL1(0x0602CC0C, 0);
        r8 = 0x0608D110;
        r10 = 0x06075830;
        r0 = GCALL2(0x06075830, 0x0608D110, 0x0604B0B4);
        r5 = 0x0608D110;
        if ((r0 & r0) == 0) {
            r0 = GCALL2(r10, r8, 0x0604B0C8);
            r5 = r8;
            if (!((r0 & r0) == 0)) {
                r0 = GCALL3(0x0604A218, r9, (r5 + 1), 33);
                ST8(r0 + r9, 0);
                r2 = LD8(0x0604B0D0);
                r1 = 0x0604B0D1;
                ST8(r11, r2);
                r2 = r11;
                r3 = LD8(r1);
                r1 = r1 + 1;
                r2 = r2 + 1;
                ST8(r2, r3);
                r3 = LD8(r1);
                r1 = r1 + 1;
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
            } else {
                r0 = GCALL2(r10, r8, 0x0604B0D8);
                r5 = r8;
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL3(0x0604A218, r9, (r5 + 1), 33);
                    ST8(r0 + r9, 0);
                    r2 = LD8(0x0604B0D0);
                    r1 = 0x0604B0D1;
                    ST8(r11, r2);
                    r2 = r11;
                    r3 = LD8(r1);
                    r1 = r1 + 1;
                    r2 = r2 + 1;
                    ST8(r2, r3);
                    r3 = LD8(r1);
                    r1 = r1 + 1;
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
            }
        } else {
            r0 = GCALL3(0x0604A218, r9, (r5 + 1), 33);
            ST8(r0 + r9, 0);
            r2 = LD8(0x0604B0BC);
            ST8(r11, r2);
            r3 = LD8(0x0604B0BD);
            r2 = r11 + 1;
            ST8(r2, r3);
            r3 = LD8(0x0604B0BE);
            r2 = r2 + 1;
            ST8(r2, r3);
            r3 = LD8(0x0604B0BF);
            r2 = r2 + 1;
            ST8(r2, r3);
            r3 = LD8(0x0604B0C0);
            r2 = r2 + 1;
            ST8(r2, r3);
            r3 = LD8(0x0604B0C1);
            r2 = r2 + 1;
            ST8(r2, r3);
            r3 = LD8(0x0604B0C2);
            r1 = 0x0604B0C3;
            r2 = r2 + 1;
            ST8(r2, r3);
            r3 = LD8(r1);
            r1 = r1 + 1;
            r2 = r2 + 1;
            ST8(r2, r3);
            r3 = LD8(r1);
            r1 = r1 + 1;
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
        r1 = 0;
        ST32(r12, r1);
        POLL();
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604B280(int r4, int r5, int r6, int r7)
{
    int r0, r2, r8, r9, r10, r11;

    r8 = r4;
    r9 = 0;
    ST32(r8 + 44, 0);
    ST32(0x0608B97C, 0);
    r5 = LD32(r8 + 16);
    r0 = GCALL4(0x0604A83C, r4, r5, r6, r7);
    r4 = LD32(r8 + 4);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r8 + 4, r9);
    }
    r4 = LD32(r8 + 16);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r8 + 16, r9);
    }
    r4 = LD32(r8 + 24);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r8 + 24, r9);
    }
    r4 = LD32(r8 + 40);
    r2 = r8;
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r8 + 40, r9);
        r2 = r8;
    }
    ST8((r2 + 28), 0);
    r9 = 0;
    r10 = 0;
    r11 = 0x06027F48;
    do {
        r4 = LD32(r8 + 52);
        ST32(r8 + 60, r10);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(r11, r4);
            ST32(r8 + 52, r10);
        }
        r4 = LD32(r8 + 56);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(r11, r4);
            ST32(r8 + 56, r10);
        }
        r9 = r9 + 1;
        r8 = r8 + 12;
    } while (AGAIN(!(r9 > 29)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06044340(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, c1;

    r2 = 0x060791B0;
    r1 = LD32(0x060791B0);
    r3 = r4;
    if (!((r1 & r1) == 0)) {
        r7 = 0x060445F8;
        r8 = r2;
        while (1) {
            r4 = LD32(r2);
            r1 = LD32(r4 + 24);
            c1 = r1 == r3;
            r1 = LD32(r4 + 28);
            if (!(c1)) {
                r2 = r4 + 28;
                if (!((r1 & r1) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            } else {
                ST32(r2, r1);
                r0 = GCALL4(r7, r4, r5, r6, r7);
                r1 = LD32(r8 + 4);
                ST32(r8 + 4, (r1 - 1));
                break;
            }
            POLL();
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046D54(int r4)
{
    int r1;

    r4 = ((signed char)r4) - 65;
    r1 = r4;
    if ((unsigned)r4 > (unsigned)24) {
        return 0;
    } else {
        r1 = LD16(0x06046D6C + (r1 + r1));
        switch (r1) {
        case 84:
            return 0;
        case 50:
            return -900;
        case 56:
            return -901;
        case 80:
            return -1;
        case 74:
            return -903;
        case 62:
            return -902;
        case 68:
            return -905;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060415D8(int r4)
{
    int r0, r1, r2, r8, r9, c0, c1, c3, c1003;

    r8 = r4;
    r1 = r8;
    r2 = LD8(r1);
    r1 = LD8((r1 + 1));
    r9 = ((r2 & 255) << 16) | (r1 & 255);
    c0 = r9 == 4;
    c1003 = c0;
    if (!(c0)) {
        r0 = -1;
        if (c1003) {
            r0 = GCALL3(0x060752FC, 0x060415D0, (r8 + 2), 4);
            c3 = (r0 & r0) == 0;
            r0 = -1;
            if (c3) {
                r0 = 1;
            }
        }
    } else {
        r0 = GCALL3(0x060752FC, 0x060415C8, (r8 + 2), 4);
        c1 = (r0 & r0) == 0;
        r0 = 0;
        if (!(c1)) {
            c1003 = r9 == 4;
            r0 = -1;
            if (c1003) {
                r0 = GCALL3(0x060752FC, 0x060415D0, (r8 + 2), 4);
                c3 = (r0 & r0) == 0;
                r0 = -1;
                if (c3) {
                    r0 = 1;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041B44(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, c3, c4, c6, c8, c1007, c1010, c1011;

    r2 = 0;
    r1 = LD8(r4);
    r1 = r1 & 255;
    r3 = 0;
    if (!((r1 & r1) == 0)) {
        r7 = 0x06075135;
        r0 = r1;
        while (1) {
            r1 = LD8(r0 + r7);
            if (((r1 & 8) & (r1 & 8)) == 0) {
                break;
            } else {
                r2 = r2 + 1;
                r1 = LD8(r4 + r2);
                r1 = r1 & 255;
                r0 = r1;
                if (!((r1 & r1) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    r1 = LD8(r4 + r2);
    r1 = r1 & 255;
    c3 = (r1 & r1) == 0;
    r0 = r1;
    c1010 = c3;
    if (c3) {
        r0 = r4;
        c1011 = c1010;
    } else {
        r7 = 0x06075135;
        r8 = LD8(r0 + 0x06075135);
        c4 = ((r8 & 8) & (r8 & 8)) == 0;
        r6 = r6 - 1;
        c1010 = c4;
        if (!(c4)) {
            r0 = r4;
            c1011 = c1010;
        } else {
            c1007 = r3 >= r6;
            while (1) {
                r0 = r5;
                c1010 = c1007;
                if (c1007) {
                    r0 = r4;
                    c1011 = c1010;
                    break;
                } else {
                    ST8(r0 + r3, r1);
                    r2 = r2 + 1;
                    r0 = r4;
                    r1 = LD8(r0 + r2);
                    r1 = r1 & 255;
                    c6 = (r1 & r1) == 0;
                    r3 = r3 + 1;
                    c1011 = c6;
                    if (c6) {
                        break;
                    } else {
                        r8 = LD8(r1 + r7);
                        c8 = r3 >= r6;
                        c1007 = c8;
                        c1010 = c8;
                        if (((r8 & 8) & (r8 & 8)) == 0) {
                            POLL();
                            continue;
                        } else {
                            r0 = r4;
                            c1011 = c1010;
                            break;
                        }
                    }
                }
                POLL();
            }
        }
    }
    r1 = LD8(r0 + r2);
    while (1) {
        r1 = r1 & 255;
        if (!((r1 & r1) == 0)) {
            POLL();
            if (!(r1 == 32)) {
                break;
            } else {
                ST8(r5 + r3, r1);
                r2 = r2 + 1;
                r1 = LD8(r4 + r2);
                r3 = r3 + 1;
                continue;
            }
        } else {
            break;
        }
    }
    ST8(r5 + r3, 0);
    return r2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060455C4(int r4)
{
    int r0, r1, r3, c1003;

    r4 = r4 & 0xFFFF;
    r3 = r4;
    if (!(((int)((unsigned)r4 >> 8)) == 128)) {
        c1003 = r3 == 0x8140;
        POLL();
        if (!(c1003)) {
            return 0;
        } else {
            return 1;
        }
    } else {
        r0 = r4 & 255;
        r1 = r0;
        if (r0 == 32) {
            return 1;
        } else {
            c1003 = r0 == 13;
            if (!((unsigned)((r1 - 9) & 255) > (unsigned)1)) {
                return 1;
            } else {
                if (!(c1003)) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06045B68(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, c5, c8, c9, c1006, c1008, c1011, c1012, c1016;

    r8 = 0;
    r5 = 0;
    r1 = LD8(r4);
    r2 = r1 & 255;
    r6 = r4;
    if (!((r2 & r2) == 0)) {
        r7 = r4 + 2;
        r3 = r4 + 1;
        do {
            r9 = r2;
            if (!(r2 == 27)) {
                r1 = r4;
                c9 = (r8 & r8) == 0;
                r4 = r4 + 1;
                c1016 = c9;
                if (!(c9)) {
                    r9 = 128 | r2;
                    c1016 = 0;
                }
                ST8(r1, r9);
                r7 = r7 + 1;
                r3 = r3 + 1;
                r6 = r6 + 1;
            } else {
                r1 = LD8(r3);
                r0 = r1 & 255;
                c1008 = r0 == 36;
                if (!(r0 == 40)) {
                    r9 = r2;
                    if (!(c1008)) {
                        r1 = r4;
                        c9 = (r8 & r8) == 0;
                        r4 = r4 + 1;
                        c1016 = c9;
                        if (!(c9)) {
                            r9 = 128 | r2;
                            c1016 = 0;
                        }
                        ST8(r1, r9);
                        r7 = r7 + 1;
                        r3 = r3 + 1;
                        r6 = r6 + 1;
                    } else {
                        r1 = LD8(r7);
                        r0 = r1 & 255;
                        c8 = r0 == 66;
                        c1011 = c8;
                        if (r0 == 64) {
                            r8 = 1;
                            c1012 = c1011;
                            r7 = r7 + 3;
                            r3 = r3 + 3;
                            r6 = r6 + 3;
                            r5 = r5 + 3;
                        } else {
                            r1 = r4;
                            c1011 = c8;
                            if (!(c8)) {
                                c9 = (r8 & r8) == 0;
                                r4 = r4 + 1;
                                c1016 = c9;
                                if (!(c9)) {
                                    r9 = 128 | r2;
                                    c1016 = 0;
                                }
                                ST8(r1, r9);
                                r7 = r7 + 1;
                                r3 = r3 + 1;
                                r6 = r6 + 1;
                            } else {
                                r8 = 1;
                                c1012 = c1011;
                                r7 = r7 + 3;
                                r3 = r3 + 3;
                                r6 = r6 + 3;
                                r5 = r5 + 3;
                            }
                        }
                    }
                } else {
                    r1 = LD8(r7);
                    r0 = r1 & 255;
                    c5 = r0 == 74;
                    c1006 = c5;
                    if (r0 == 66) {
                        r8 = 0;
                        c1012 = c1006;
                        r7 = r7 + 3;
                        r3 = r3 + 3;
                        r6 = r6 + 3;
                        r5 = r5 + 3;
                    } else {
                        c1006 = c5;
                        if (!(c5)) {
                            r1 = LD8(r3);
                            c1008 = (r1 & 255) == 36;
                            r9 = r2;
                            if (!(c1008)) {
                                r1 = r4;
                                c9 = (r8 & r8) == 0;
                                r4 = r4 + 1;
                                c1016 = c9;
                                if (!(c9)) {
                                    r9 = 128 | r2;
                                    c1016 = 0;
                                }
                                ST8(r1, r9);
                                r7 = r7 + 1;
                                r3 = r3 + 1;
                                r6 = r6 + 1;
                            } else {
                                r1 = LD8(r7);
                                r0 = r1 & 255;
                                c8 = r0 == 66;
                                c1011 = c8;
                                if (r0 == 64) {
                                    r8 = 1;
                                    c1012 = c1011;
                                    r7 = r7 + 3;
                                    r3 = r3 + 3;
                                    r6 = r6 + 3;
                                    r5 = r5 + 3;
                                } else {
                                    r1 = r4;
                                    c1011 = c8;
                                    if (!(c8)) {
                                        c9 = (r8 & r8) == 0;
                                        r4 = r4 + 1;
                                        c1016 = c9;
                                        if (!(c9)) {
                                            r9 = 128 | r2;
                                            c1016 = 0;
                                        }
                                        ST8(r1, r9);
                                        r7 = r7 + 1;
                                        r3 = r3 + 1;
                                        r6 = r6 + 1;
                                    } else {
                                        r8 = 1;
                                        c1012 = c1011;
                                        r7 = r7 + 3;
                                        r3 = r3 + 3;
                                        r6 = r6 + 3;
                                        r5 = r5 + 3;
                                    }
                                }
                            }
                        } else {
                            r8 = 0;
                            c1012 = c1006;
                            r7 = r7 + 3;
                            r3 = r3 + 3;
                            r6 = r6 + 3;
                            r5 = r5 + 3;
                        }
                    }
                }
            }
            r1 = LD8(r6);
            r2 = r1 & 255;
        } while (AGAIN(!((r2 & r2) == 0)));
    }
    r1 = 0;
    ST8(r4, 0);
    r4 = r4 + 1;
    if (r5 > 0) {
        ST8(r4, r1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045F9C(int r4, int r5, int r6, int r7)
{
    int r1, r2, r3, c1001;

    r3 = r6;
    c1001 = r7 > 0;
    while (1) {
        r3 = r3 - 1;
        if (!(c1001)) {
            return 1;
        } else {
            r2 = LD8(r4 + r3);
            r7 = r7 - 1;
            r1 = LD8(r5 + r7);
            c1001 = r7 > 0;
            if (r2 == r1) {
                POLL();
                continue;
            } else {
                return 0;
            }
        }
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046550(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, c0, c1004, c1009;

    r3 = ((((int)((unsigned)((int)((unsigned)(r4 + 7) >> 2)) >> 1)) + 1) << 2) + ((((int)((unsigned)((int)((unsigned)(r4 + 7) >> 2)) >> 1)) + 1) << 2);
    r0 = LD32(r5);
    c0 = (r0 & r0) == 0;
    r6 = 0;
    c1004 = c0;
    if (!(c0)) {
        while (1) {
            r1 = LD32(r0 + 4);
            if ((unsigned)r1 >= (unsigned)r3) {
                break;
            } else {
                r6 = r0;
                r0 = LD32(r0);
                if (!((r0 & r0) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        c1004 = (r0 & r0) == 0;
    }
    if (!(c1004)) {
        r1 = LD32(r0 + 4);
        r7 = r1 - r3;
        if ((unsigned)r7 > (unsigned)16) {
            r2 = r0 + r3;
            ST32(r0 + 4, r3);
            ST32(r2 + 4, r7);
            r1 = LD32(r0);
            ST32(r0 + r3, r1);
            c1009 = (r6 & r6) == 0;
        } else {
            r2 = LD32(r0);
            c1009 = (r6 & r6) == 0;
        }
        if (c1009) {
            ST32(r5, r2);
            r1 = 0;
        } else {
            ST32(r6, r2);
            r1 = 0;
        }
        ST32(r0, r1);
        return r0 + 8;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041790(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, c1, c5, c7;

    r8 = r5;
    r1 = r4;
    r4 = r4 + 2;
    r6 = 0;
    r7 = 0;
    r2 = LD8(r1);
    r5 = 0x06075135;
    r1 = LD8((r1 + 1));
    r2 = ((r2 & 255) << 16) | (r1 & 255);
    while (1) {
        r3 = 0;
        if (r2 > 0) {
            while (1) {
                r6 = LD8(r4);
                r4 = r4 + 1;
                r1 = LD8(r6 + r5);
                c1 = ((r1 & 4) & (r1 & 4)) == 0;
                r1 = r3;
                if (c1) {
                    break;
                } else {
                    r2 = r2 - 1;
                    r3 = ((((r1 << 2) + r3) + ((r1 << 2) + r3)) - 48) + r6;
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
        r1 = 2;
        if (r3 > 0x100) {
            r0 = -1;
            break;
        } else {
            r0 = r6;
            if (r7 > r1) {
                c7 = r2 > 0;
                if (!(r7 == 3)) {
                    r0 = r8;
                    ST8(r0 + r7, r3);
                    r7 = r7 + 1;
                    r2 = r2 - 1;
                    if (!(r7 > 3)) {
                        POLL();
                        continue;
                    } else {
                        r0 = 0;
                        break;
                    }
                } else {
                    r0 = r8;
                    if (!(c7)) {
                        ST8(r0 + r7, r3);
                        r7 = r7 + 1;
                        r2 = r2 - 1;
                        if (!(r7 > 3)) {
                            POLL();
                            continue;
                        } else {
                            r0 = 0;
                            break;
                        }
                    } else {
                        r0 = -1;
                        break;
                    }
                }
            } else {
                c5 = r0 == 46;
                r0 = -1;
                if (!(c5)) {
                    break;
                } else {
                    c7 = r2 > 0;
                    if (!(r7 == 3)) {
                        r0 = r8;
                        ST8(r0 + r7, r3);
                        r7 = r7 + 1;
                        r2 = r2 - 1;
                        if (!(r7 > 3)) {
                            POLL();
                            continue;
                        } else {
                            r0 = 0;
                            break;
                        }
                    } else {
                        r0 = r8;
                        if (!(c7)) {
                            ST8(r0 + r7, r3);
                            r7 = r7 + 1;
                            r2 = r2 - 1;
                            if (!(r7 > 3)) {
                                POLL();
                                continue;
                            } else {
                                r0 = 0;
                                break;
                            }
                        } else {
                            r0 = -1;
                            break;
                        }
                    }
                }
            }
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041DBC(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10, r11, r12, r13, r14, c2, c5, c11, c14, c1013, c1021;

    r14 = r4;
    r13 = 0;
    r0 = GCALL1(0x0607507C, r4);
    r12 = r0;
    r8 = 0;
    if (!(0 >= r12)) {
        r10 = 1;
        r11 = r14;
        do {
            r1 = LD8(r11);
            r2 = r1 & 255;
            c2 = r8 > 0;
            if (!(r2 == 8)) {
                r5 = r14;
                if (!(r2 == 141)) {
                    r10 = r10 + 1;
                    r11 = r11 + 1;
                    r8 = r8 + 1;
                    c1021 = r8 >= r12;
                } else {
                    r0 = GCALL2(0x06041DAC, r11, (r5 + r10));
                    r10 = r10 - 1;
                    r11 = r11 - 1;
                    r8 = r8 - 1;
                    r13 = r13 + 1;
                    c5 = r8 >= 0;
                    r12 = r12 - 1;
                    c1013 = c5;
                    if (c5) {
                        r9 = r8 + r14;
                        while (1) {
                            r1 = LD8(r9);
                            r1 = LD8(0x06075135 + (r1 & 255));
                            r5 = r14;
                            if (((r1 & 8) & (r1 & 8)) == 0) {
                                break;
                            } else {
                                r0 = GCALL2(0x06041DAC, r9, (r5 + r10));
                                r9 = r9 - 1;
                                r10 = r10 - 1;
                                r11 = r11 - 1;
                                r8 = r8 - 1;
                                r13 = r13 + 1;
                                r12 = r12 - 1;
                                if (r8 >= 0) {
                                    POLL();
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            POLL();
                        }
                        c1013 = r8 >= 0;
                    }
                    c1021 = r8 >= r12;
                    if (c1013) {
                        r1 = LD8(r11);
                        r1 = LD8(0x06075135 + (r1 & 255));
                        c11 = r8 >= r12;
                        c1021 = c11;
                        if (((r1 & 8) & (r1 & 8)) == 0) {
                            r9 = r8 + r14;
                            r5 = r14;
                            while (1) {
                                r0 = GCALL2(0x06041DAC, r9, (r5 + r10));
                                r9 = r9 - 1;
                                r10 = r10 - 1;
                                r11 = r11 - 1;
                                r8 = r8 - 1;
                                r13 = r13 + 1;
                                r12 = r12 - 1;
                                if (!(r8 >= 0)) {
                                    c1021 = r8 >= r12;
                                    break;
                                } else {
                                    r1 = LD8(r9);
                                    r1 = LD8(0x06075135 + (r1 & 255));
                                    c14 = r8 >= r12;
                                    c1021 = c14;
                                    if (!(((r1 & 8) & (r1 & 8)) == 0)) {
                                        break;
                                    } else {
                                        r5 = r14;
                                    }
                                }
                                POLL();
                            }
                        }
                    }
                }
            } else {
                r13 = r13 + 1;
                if (!(c2)) {
                    r12 = r12 - 1;
                    r5 = r14 + r10;
                    r4 = r11;
                } else {
                    r13 = r13 + 1;
                    r12 = r12 - 2;
                    r5 = r14 + r10;
                    r4 = r14 + (r8 - 1);
                }
                r0 = GCALL2(0x06041DAC, r4, r5);
                c1021 = r8 >= r12;
            }
        } while (AGAIN(!(c1021)));
    }
    return r13;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043EC0(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10, r11, r12, r13, r14;

    r10 = r4;
    r13 = LD32(r10 + 4);
    r0 = GCALL4(0x060279E0, 0, (r13 << 2), -1, 1);
    r2 = 0x0608BCF0;
    ST32(0x0608BCF8, r0);
    if (!((r0 & r0) == 0)) {
        r1 = LD32(r10);
        r12 = r0;
        r11 = 0;
        ST32(r2, r1);
        ST32(r2 + 4, r13);
        r10 = r10 + 8;
        if (0 >= r13) {
            r0 = 0;
        } else {
            r14 = 0x060750DC;
            while (1) {
                r9 = 0;
                r1 = LD8(r10);
                r2 = r10;
                if (!((r1 & r1) == 0)) {
                    do {
                        r2 = r2 + 1;
                        r1 = LD8(r2);
                        r9 = r9 + 1;
                    } while (AGAIN(!((r1 & r1) == 0)));
                }
                r9 = r9 + 1;
                r0 = GCALL4(0x060279E0, 0, r9, -1, 1);
                r8 = r0;
                r5 = r10;
                if ((r8 & r8) == 0) {
                    POLL();
                    r0 = -3;
                    break;
                } else {
                    r0 = GCALL2(r14, r8, r5);
                    ST32(r12, r8);
                    r10 = r10 + r9;
                    r11 = r11 + 1;
                    r12 = r12 + 4;
                    if (!(r11 >= r13)) {
                        POLL();
                        continue;
                    } else {
                        r0 = 0;
                        break;
                    }
                }
                POLL();
            }
        }
    } else {
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043F5C(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10, r11, r12, r13, r14;

    r10 = r4;
    r13 = LD32(r10 + 4);
    r0 = GCALL4(0x060279E0, 0, (r13 << 2), -1, 1);
    r2 = 0x0608BD00;
    ST32(0x0608BD08, r0);
    if (!((r0 & r0) == 0)) {
        r1 = LD32(r10);
        r12 = r0;
        r11 = 0;
        ST32(r2, r1);
        ST32(r2 + 4, r13);
        r10 = r10 + 8;
        if (0 >= r13) {
            r0 = 0;
        } else {
            r14 = 0x060750DC;
            while (1) {
                r9 = 0;
                r1 = LD8(r10);
                r2 = r10;
                if (!((r1 & r1) == 0)) {
                    do {
                        r2 = r2 + 1;
                        r1 = LD8(r2);
                        r9 = r9 + 1;
                    } while (AGAIN(!((r1 & r1) == 0)));
                }
                r9 = r9 + 1;
                r0 = GCALL4(0x060279E0, 0, r9, -1, 1);
                r8 = r0;
                r5 = r10;
                if ((r8 & r8) == 0) {
                    POLL();
                    r0 = -3;
                    break;
                } else {
                    r0 = GCALL2(r14, r8, r5);
                    ST32(r12, r8);
                    r10 = r10 + r9;
                    r11 = r11 + 1;
                    r12 = r12 + 4;
                    if (!(r11 >= r13)) {
                        POLL();
                        continue;
                    } else {
                        r0 = 0;
                        break;
                    }
                }
                POLL();
            }
        }
    } else {
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06048FA0(void)
{
    int r0, r1, r2, r3, r4, r5, r7, r8, r9, r10, r11, r12, r13, r14, c2, c4, c1006, c1010;

    r14 = LD32(0x060791CC);
    r10 = 0;
    r13 = 128;
    r11 = 0x0608AF60;
    r1 = r14;
    do {
        if (!((r1 - r10) >= 0)) {
            r14 = r10 + 31;
        }
        r9 = (((r14 - r10) << 2) + (r14 - r10)) << 2;
        r12 = 0x0608CE90 + r9;
        r4 = LD32(r12 + 4);
        if ((r4 & r4) == 0) {
            r0 = 0x0608CE90;
            r4 = LD32(0x0608CE90 + r9);
            r2 = 7;
            if ((r4 & r4) == 0) {
                if (!(r10 > r2)) {
                    r7 = r10 << 8;
                    r3 = 0;
                    r0 = 0x0608AF60;
                    do {
                        ST8(r0 + r7, r3);
                        r7 = r7 + 0x100;
                        r10 = r10 + 1;
                        r11 = r11 + 0x100;
                    } while (AGAIN(!(r10 > r2)));
                }
            } else {
                r0 = GCALL1(0x0607507C, r4);
                r8 = r0;
                c4 = r0 > r13;
                r1 = r13;
                c1010 = c4;
                if (!(c4)) {
                    r1 = r8;
                    c1010 = 0;
                }
                r8 = r1;
                r5 = LD32(0x0608CE90 + r9);
                r0 = GCALL3(0x060750A0, r11, r5, r8);
                r0 = r11;
                ST8(r0 + r8, 0);
            }
        } else {
            r0 = GCALL1(0x0607507C, r4);
            r8 = r0;
            c2 = r0 > r13;
            r1 = r13;
            c1006 = c2;
            if (!(c2)) {
                r1 = r8;
                c1006 = 0;
            }
            r8 = r1;
            r5 = LD32(r12 + 4);
            r0 = GCALL3(0x060750A0, r11, r5, r8);
            r0 = r11;
            ST8(r0 + r8, 0);
        }
        r11 = r11 + 0x100;
        r10 = r10 + 1;
        r1 = r14;
    } while (AGAIN(!(r10 > 7)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060458C0(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, c3, c6, c8, c9, c1012, c1018, c1019;
    FRAME(sp, 32);

    r6 = r4 & 0xFFFF;
    ST16(sp - 32, -32448);
    ST16((sp - 30), -31553);
    ST16((sp - 28), -30912);
    ST16((sp - 26), -30817);
    ST16((sp - 24), -30561);
    ST16((sp - 22), -24577);
    ST16((sp - 20), -8128);
    ST16((sp - 18), -5468);
    ST16((sp - 16), 0x2121);
    ST16((sp - 14), 0x2D21);
    ST16((sp - 12), 0x3021);
    ST16((sp - 10), 0x5F21);
    r8 = (int)((unsigned)r6 >> 8);
    r5 = r6 & 255;
    r2 = 0;
    r7 = 0;
    r4 = 3;
    r0 = 0;
    while (1) {
        r0 = r0 << 2;
        r1 = LD16(r0 + (sp - 32));
        r3 = r0 + (sp - 32);
        if (!((unsigned)r6 >= (unsigned)(r1 & 0xFFFF))) {
            r2 = (short)(r2 + 1);
            r0 = r2;
            if (!(r2 > r4)) {
                POLL();
                continue;
            } else {
                break;
            }
        } else {
            r1 = LD16((r3 + 2));
            if (!((unsigned)r6 > (unsigned)(r1 & 0xFFFF))) {
                r7 = r2;
                POLL();
                break;
            } else {
                r2 = (short)(r2 + 1);
                r0 = r2;
                if (!(r2 > r4)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
        }
        POLL();
    }
    c3 = r2 == 4;
    r2 = r7;
    if (!(c3)) {
        r1 = LD16((r7 << 2) + (sp - 32));
        r4 = HELPER((int)(r6 - (r1 & 0xFFFF)) >> 8);
        r1 = LD16((((r2 + r2) + (sp - 32)) + 16));
        r3 = (r1 + ((r4 << 8) + (r4 << 8))) & 0xFFFF;
        if (!(r7 == 2)) {
            c6 = (unsigned)r5 > (unsigned)158;
            c1012 = c6;
            if (c6) {
                r3 = (0x100 + r3) & 0xFFFF;
                c1012 = (unsigned)r5 > (unsigned)158;
            }
            r0 = r8;
            if (c1012) {
                r0 = (r0 << 8) | 159;
            } else {
                r0 = (r0 << 8) | 64;
            }
        } else {
            r0 = r8;
            if ((unsigned)r5 > (unsigned)158) {
                r0 = (r0 << 8) | 159;
            } else {
                r3 = (0x100 + r3) & 0xFFFF;
                c1012 = (unsigned)r5 > (unsigned)158;
                r0 = r8;
                if (c1012) {
                    r0 = (r0 << 8) | 159;
                } else {
                    r0 = (r0 << 8) | 64;
                }
            }
        }
        r3 = ((r6 - ((short)r0)) + r3) & 0xFFFF;
        c8 = (((int)((unsigned)r3 >> 8)) & 1) == 1;
        r2 = r3 & 255;
        c1018 = c8;
        if (!(c8)) {
            r0 = r3;
            c1019 = c1018;
        } else {
            c9 = (unsigned)r2 > (unsigned)95;
            r0 = r3;
            c1019 = c9;
            if (c9) {
                r3 = (r3 - 1) & 0xFFFF;
                c1018 = 1;
                r0 = r3;
                c1019 = c1018;
            }
        }
    } else {
        r0 = 0x2121;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045A0C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, c5, c8, c1010, c1016;
    FRAME(sp, 36);

    r6 = r4 & 0xFFFF;
    ST16(sp - 36, 0x2121);
    ST16((sp - 34), 0x2841);
    ST16((sp - 32), 0x2D21);
    ST16((sp - 30), 0x2D7F);
    ST16((sp - 28), 0x3021);
    ST16((sp - 26), 0x537E);
    ST16((sp - 24), 0x5F21);
    ST16((sp - 22), 0x7426);
    ST16((sp - 20), -32512);
    ST16((sp - 18), -30976);
    ST16((sp - 16), -30720);
    ST16((sp - 14), -8192);
    r8 = (int)((unsigned)r6 >> 8);
    r9 = r6 & 255;
    r2 = 0;
    r5 = 0;
    r7 = 3;
    r0 = 0;
    while (1) {
        r0 = r0 << 2;
        r1 = LD16(r0 + (sp - 36));
        r3 = r0 + (sp - 36);
        if (!((unsigned)r6 >= (unsigned)(r1 & 0xFFFF))) {
            r2 = (short)(r2 + 1);
            r0 = r2;
            if (!(r2 > r7)) {
                POLL();
                continue;
            } else {
                break;
            }
        } else {
            r1 = LD16((r3 + 2));
            if (!((unsigned)r6 > (unsigned)(r1 & 0xFFFF))) {
                r5 = r2;
                POLL();
                break;
            } else {
                r2 = (short)(r2 + 1);
                r0 = r2;
                if (!(r2 > r7)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
        }
        POLL();
    }
    r1 = r5;
    if (!(r2 == 4)) {
        r1 = LD16((r1 << 2) + (sp - 36));
        r4 = HELPER((int)(r6 - (r1 & 0xFFFF)) >> 8);
        r4 = (short)r4;
        r2 = (r4 + ((int)((unsigned)r4 >> 31))) >> 1;
        r1 = LD16((((r5 + r5) + (sp - 36)) + 16));
        r3 = (r1 + (r2 << 8)) & 0xFFFF;
        c5 = ((short)(r4 - (r2 + r2))) == 1;
        r0 = r5;
        c1010 = c5;
        if (!(c5)) {
            r1 = r8;
        } else {
            r1 = r8;
            if (r0 == 2) {
                r3 = (0x100 + r3) & 0xFFFF;
                c1010 = 1;
                r1 = r8;
            }
        }
        r3 = ((r6 - ((short)((r1 << 8) | 33))) + r3) & 0xFFFF;
        r1 = r3;
        if (((1 & r8) & (1 & r8)) == 0) {
            r1 = 159 + r3;
            r0 = r1 & 0xFFFF;
            c1016 = 1;
        } else {
            r3 = (r1 + 64) & 0xFFFF;
            c8 = (unsigned)r9 > (unsigned)95;
            r0 = r3;
            c1016 = c8;
            if (c8) {
                r1 = r3 + 1;
                r0 = r1 & 0xFFFF;
                c1016 = 1;
            }
        }
    } else {
        r0 = 0x8140;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06042B28(void)
{
    int r0, r1, r2, r3, r8;

    r8 = 0x0608BCD0;
    r1 = LD32(0x0608BCD0);
    if ((r1 & r1) == 0) {
        r2 = 0x060773C8;
        r1 = LD32(0x060773C8);
        if (!((r1 & r1) == 0)) {
            r3 = 0x060791A8;
            do {
                ST32(r2 + 12, r3);
                r2 = r2 + 24;
                r1 = LD32(r2);
            } while (AGAIN(!((r1 & r1) == 0)));
        }
        r1 = LD32(0x060766C0);
        ST32(r8 + 4, r1);
        r1 = LD32(0x0607668C);
        ST32(r8 + 8, r1);
        ST32(0x0607668C, 2);
        r0 = GCALL1(0x0602CDDC, 13);
        ST32(r8, 1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049254(int r4, int r5)
{
    int r0, r1, r2, r3, r8;
    FRAME(sp, 52);

    r8 = r5;
    r0 = GCALL3(0x0605A15C, r4, (sp - 52), 0);
    while (1) {
        r0 = GCALL0(0x0605299C);
        r0 = GCALL1(0x0605A2A8, (sp - 52));
        r1 = LD32(0x060766B4);
        if ((r1 & r1) == 0) {
            r3 = r8;
            if ((r0 & r0) == 0) {
                POLL();
                continue;
            } else {
                r1 = LD8(sp - 52);
                r3 = r3 + 1;
                ST8(r8, r1);
                r1 = (sp - 52) + 1;
                r2 = LD8(r1);
                r1 = r1 + 1;
                ST8(r3, r2);
                r2 = LD8(r1);
                r3 = r3 + 1;
                ST8(r3, r2);
                r1 = LD8((r1 + 1));
                ST8((r3 + 1), r1);
                if (r0 >= 0) {
                    r0 = 0;
                    break;
                } else {
                    if (r0 == -506) {
                        break;
                    } else {
                        r0 = -529;
                        break;
                    }
                }
            }
        } else {
            r0 = -12;
            break;
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049858(int r4, int r5)
{
    int r0, r1, r8, r9, r10, c4, c7, c1004, c1010;
    FRAME(sp, 276);

    r8 = r4;
    r9 = r5;
    r1 = LD32(r8);
    r10 = 0;
    if (r1 >= 0) {
        r0 = GCALL3(0x06045264, (sp - 276), 0x0604984C, r9);
        r0 = GCALL1(0x0607507C, (sp - 276));
        r4 = LD32(r8);
        r0 = GCALL3(0x06049370, r4, (sp - 276), r0);
        c4 = r0 == -12;
        if (r0 >= 0) {
            r4 = LD32(r8);
            r0 = GCALL2(0x060493C4, r4, (sp - 276));
            c7 = r0 == -12;
            if (r0 >= 0) {
                r0 = 0;
                c1010 = (r10 & r10) == 0;
            } else {
                r0 = -1;
                c1004 = c7;
                POLL();
                if (!(c1004)) {
                    c1010 = (r10 & r10) == 0;
                } else {
                    r0 = -12;
                    c1010 = (r10 & r10) == 0;
                }
            }
        } else {
            r0 = -600;
            c1004 = c4;
            if (!(c1004)) {
                c1010 = (r10 & r10) == 0;
            } else {
                r0 = -12;
                c1010 = (r10 & r10) == 0;
            }
        }
    } else {
        r10 = 1;
        r0 = GCALL1(0x06049414, r4);
        c1010 = 1 == 0;
        if (r0 >= 0) {
            r0 = GCALL3(0x06045264, (sp - 276), 0x0604984C, r9);
            r0 = GCALL1(0x0607507C, (sp - 276));
            r4 = LD32(r8);
            r0 = GCALL3(0x06049370, r4, (sp - 276), r0);
            c4 = r0 == -12;
            if (r0 >= 0) {
                r4 = LD32(r8);
                r0 = GCALL2(0x060493C4, r4, (sp - 276));
                c7 = r0 == -12;
                if (r0 >= 0) {
                    r0 = 0;
                    c1010 = (r10 & r10) == 0;
                } else {
                    r0 = -1;
                    c1004 = c7;
                    POLL();
                    if (!(c1004)) {
                        c1010 = (r10 & r10) == 0;
                    } else {
                        r0 = -12;
                        c1010 = (r10 & r10) == 0;
                    }
                }
            } else {
                r0 = -600;
                c1004 = c4;
                if (!(c1004)) {
                    c1010 = (r10 & r10) == 0;
                } else {
                    r0 = -12;
                    c1010 = (r10 & r10) == 0;
                }
            }
        }
    }
    r4 = r8;
    if (!(c1010)) {
        ST32((0x100 + (sp - 276)), r0);
        r0 = GCALL1(0x060496CC, r4);
        r0 = LD32((0x100 + (sp - 276)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049910(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, c3, c5, c1006;

    r8 = r4;
    r10 = r5;
    r1 = LD32(r8);
    r9 = r6;
    if (r1 >= 0) {
        r0 = GCALL3(0x06045264, r9, 0x06049904, r10);
        r0 = GCALL1(0x0607507C, r9);
        r4 = LD32(r8);
        r0 = GCALL3(0x06049370, r4, r9, r0);
        c3 = r0 == -12;
        if (r0 >= 0) {
            r4 = LD32(r8);
            r0 = GCALL2(0x060493C4, r4, r9);
            c5 = r0 == -12;
            if (!(r0 >= 0)) {
                r0 = -1;
                c1006 = c5;
                if (c1006) {
                    r0 = -12;
                }
            }
        } else {
            r0 = -600;
            c1006 = c3;
            if (c1006) {
                r0 = -12;
            }
        }
    } else {
        r0 = GCALL1(0x06049414, r4);
        if (r0 >= 0) {
            r0 = GCALL3(0x06045264, r9, 0x06049904, r10);
            r0 = GCALL1(0x0607507C, r9);
            r4 = LD32(r8);
            r0 = GCALL3(0x06049370, r4, r9, r0);
            c3 = r0 == -12;
            if (r0 >= 0) {
                r4 = LD32(r8);
                r0 = GCALL2(0x060493C4, r4, r9);
                c5 = r0 == -12;
                if (!(r0 >= 0)) {
                    r0 = -1;
                    c1006 = c5;
                    if (c1006) {
                        r0 = -12;
                    }
                }
            } else {
                r0 = -600;
                c1006 = c3;
                if (c1006) {
                    r0 = -12;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604999C(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, c3, c5, c1006;

    r8 = r4;
    r10 = r5;
    r1 = LD32(r8);
    r9 = r6;
    if (r1 >= 0) {
        r0 = GCALL3(0x06045264, r9, 0x06049990, r10);
        r0 = GCALL1(0x0607507C, r9);
        r4 = LD32(r8);
        r0 = GCALL3(0x06049370, r4, r9, r0);
        c3 = r0 == -12;
        if (r0 >= 0) {
            r4 = LD32(r8);
            r0 = GCALL2(0x060493C4, r4, r9);
            c5 = r0 == -12;
            if (!(r0 >= 0)) {
                r0 = -1;
                c1006 = c5;
                if (c1006) {
                    r0 = -12;
                }
            }
        } else {
            r0 = -600;
            c1006 = c3;
            if (c1006) {
                r0 = -12;
            }
        }
    } else {
        r0 = GCALL1(0x06049414, r4);
        if (r0 >= 0) {
            r0 = GCALL3(0x06045264, r9, 0x06049990, r10);
            r0 = GCALL1(0x0607507C, r9);
            r4 = LD32(r8);
            r0 = GCALL3(0x06049370, r4, r9, r0);
            c3 = r0 == -12;
            if (r0 >= 0) {
                r4 = LD32(r8);
                r0 = GCALL2(0x060493C4, r4, r9);
                c5 = r0 == -12;
                if (!(r0 >= 0)) {
                    r0 = -1;
                    c1006 = c5;
                    if (c1006) {
                        r0 = -12;
                    }
                }
            } else {
                r0 = -600;
                c1006 = c3;
                if (c1006) {
                    r0 = -12;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041BDC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, r14, c1, c4, c8;
    int v36;

    r10 = r4;
    v36 = r5;
    r14 = 0;
    r8 = r5 << 2;
    r9 = LD32(r10 + 20);
    r5 = LD32(r10 + 4);
    r0 = GCALL5(0x06027C18, 0, r5, r8, r7, v36);
    r13 = r0;
    if (!((r13 & r13) == 0)) {
        ST32(r10 + 4, r13);
        r5 = LD32(r10 + 12);
        r8 = v36 << 2;
        r7 = R(7);
        r0 = GCALL5(0x06027C18, 0, r5, r8, 0, v36);
        r12 = r0;
        if (!((r12 & r12) == 0)) {
            r1 = LD32(r10);
            ST32(r10 + 12, r12);
            if (!((r1 & r1) == 0)) {
                r1 = LD32(r10);
                if ((r1 & r1) == 0) {
                    r11 = 22;
                } else {
                    r1 = LD32(r10 + 16);
                    r11 = r1 + 1;
                }
                r0 = v36;
                r8 = r9;
                if (r9 >= r0) {
                    ST32(r10 + 20, r0);
                } else {
                    r8 = r8 << 2;
                    while (1) {
                        r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                        r1 = r0;
                        r0 = r8;
                        ST32(r0 + r13, r1);
                        if ((r1 & r1) == 0) {
                            POLL();
                            ST32(r10 + 20, (r9 - 1));
                            break;
                        } else {
                            r1 = LD32(r10);
                            if ((r1 & r1) == 0) {
                                ST32(r0 + r14, r11);
                                r0 = r8;
                            }
                            r1 = LD32(r0 + r13);
                            ST8(r1, 0);
                            ST32(r0 + r12, 1);
                            r9 = r9 + 1;
                            r8 = r8 + 4;
                            if (!(r9 >= v36)) {
                                POLL();
                                continue;
                            } else {
                                r0 = v36;
                                ST32(r10 + 20, r0);
                                break;
                            }
                        }
                        POLL();
                    }
                }
                r0 = 1;
            } else {
                r8 = v36 << 2;
                r5 = LD32(r10 + 8);
                r7 = R(7);
                r0 = GCALL5(0x06027C18, 0, r5, r8, 0, v36);
                r14 = r0;
                if (!((r14 & r14) == 0)) {
                    ST32(r10 + 8, r14);
                    r1 = LD32(r10);
                    if ((r1 & r1) == 0) {
                        r11 = 22;
                    } else {
                        r1 = LD32(r10 + 16);
                        r11 = r1 + 1;
                    }
                    r0 = v36;
                    r8 = r9;
                    if (r9 >= r0) {
                        ST32(r10 + 20, r0);
                    } else {
                        r8 = r8 << 2;
                        while (1) {
                            r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                            r1 = r0;
                            r0 = r8;
                            ST32(r0 + r13, r1);
                            if ((r1 & r1) == 0) {
                                POLL();
                                ST32(r10 + 20, (r9 - 1));
                                break;
                            } else {
                                r1 = LD32(r10);
                                if ((r1 & r1) == 0) {
                                    ST32(r0 + r14, r11);
                                    r0 = r8;
                                }
                                r1 = LD32(r0 + r13);
                                ST8(r1, 0);
                                ST32(r0 + r12, 1);
                                r9 = r9 + 1;
                                r8 = r8 + 4;
                                if (!(r9 >= v36)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = v36;
                                    ST32(r10 + 20, r0);
                                    break;
                                }
                            }
                            POLL();
                        }
                    }
                    r0 = 1;
                } else {
                    r4 = LD32(r10 + 8);
                    r0 = GCALL5(0x06027800, r4, 0, 0, 0, v36);
                    c8 = (r0 & r0) == 0;
                    r0 = 0;
                    if (c8) {
                        r0 = GCALL5(0x060279E0, 1, r8, 13, 1, v36);
                        r14 = r0;
                        r6 = r8;
                        if ((r14 & r14) == 0) {
                            r0 = 0;
                        } else {
                            r5 = LD32(r10 + 8);
                            r0 = GCALL5(0x0604B358, r14, r5, r6, 0, v36);
                            r4 = LD32(r10 + 8);
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL5(0x06027F48, r4, 0, 0, 0, v36);
                            ST32(r10 + 8, r14);
                            r1 = LD32(r10);
                            if ((r1 & r1) == 0) {
                                r11 = 22;
                            } else {
                                r1 = LD32(r10 + 16);
                                r11 = r1 + 1;
                            }
                            r0 = v36;
                            r8 = r9;
                            if (r9 >= r0) {
                                ST32(r10 + 20, r0);
                            } else {
                                r8 = r8 << 2;
                                while (1) {
                                    r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                    r1 = r0;
                                    r0 = r8;
                                    ST32(r0 + r13, r1);
                                    if ((r1 & r1) == 0) {
                                        POLL();
                                        ST32(r10 + 20, (r9 - 1));
                                        break;
                                    } else {
                                        r1 = LD32(r10);
                                        if ((r1 & r1) == 0) {
                                            ST32(r0 + r14, r11);
                                            r0 = r8;
                                        }
                                        r1 = LD32(r0 + r13);
                                        ST8(r1, 0);
                                        ST32(r0 + r12, 1);
                                        r9 = r9 + 1;
                                        r8 = r8 + 4;
                                        if (!(r9 >= v36)) {
                                            POLL();
                                            continue;
                                        } else {
                                            r0 = v36;
                                            ST32(r10 + 20, r0);
                                            break;
                                        }
                                    }
                                    POLL();
                                }
                            }
                            r0 = 1;
                        }
                    }
                }
            }
        } else {
            r4 = LD32(r10 + 12);
            r0 = GCALL5(0x06027800, r4, 0, 0, 0, v36);
            c4 = (r0 & r0) == 0;
            r0 = 0;
            if (c4) {
                r0 = GCALL5(0x060279E0, 1, r8, 13, 1, v36);
                r12 = r0;
                r6 = r8;
                if ((r12 & r12) == 0) {
                    r0 = 0;
                } else {
                    r5 = LD32(r10 + 12);
                    r0 = GCALL5(0x0604B358, r12, r5, r6, 0, v36);
                    r4 = LD32(r10 + 12);
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, v36);
                    r1 = LD32(r10);
                    ST32(r10 + 12, r12);
                    if (!((r1 & r1) == 0)) {
                        r1 = LD32(r10);
                        if ((r1 & r1) == 0) {
                            r11 = 22;
                        } else {
                            r1 = LD32(r10 + 16);
                            r11 = r1 + 1;
                        }
                        r0 = v36;
                        r8 = r9;
                        if (r9 >= r0) {
                            ST32(r10 + 20, r0);
                        } else {
                            r8 = r8 << 2;
                            while (1) {
                                r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                r1 = r0;
                                r0 = r8;
                                ST32(r0 + r13, r1);
                                if ((r1 & r1) == 0) {
                                    POLL();
                                    ST32(r10 + 20, (r9 - 1));
                                    break;
                                } else {
                                    r1 = LD32(r10);
                                    if ((r1 & r1) == 0) {
                                        ST32(r0 + r14, r11);
                                        r0 = r8;
                                    }
                                    r1 = LD32(r0 + r13);
                                    ST8(r1, 0);
                                    ST32(r0 + r12, 1);
                                    r9 = r9 + 1;
                                    r8 = r8 + 4;
                                    if (!(r9 >= v36)) {
                                        POLL();
                                        continue;
                                    } else {
                                        r0 = v36;
                                        ST32(r10 + 20, r0);
                                        break;
                                    }
                                }
                                POLL();
                            }
                        }
                        r0 = 1;
                    } else {
                        r8 = v36 << 2;
                        r5 = LD32(r10 + 8);
                        r7 = R(7);
                        r0 = GCALL5(0x06027C18, 0, r5, r8, 0, v36);
                        r14 = r0;
                        if (!((r14 & r14) == 0)) {
                            ST32(r10 + 8, r14);
                            r1 = LD32(r10);
                            if ((r1 & r1) == 0) {
                                r11 = 22;
                            } else {
                                r1 = LD32(r10 + 16);
                                r11 = r1 + 1;
                            }
                            r0 = v36;
                            r8 = r9;
                            if (r9 >= r0) {
                                ST32(r10 + 20, r0);
                            } else {
                                r8 = r8 << 2;
                                while (1) {
                                    r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                    r1 = r0;
                                    r0 = r8;
                                    ST32(r0 + r13, r1);
                                    if ((r1 & r1) == 0) {
                                        POLL();
                                        ST32(r10 + 20, (r9 - 1));
                                        break;
                                    } else {
                                        r1 = LD32(r10);
                                        if ((r1 & r1) == 0) {
                                            ST32(r0 + r14, r11);
                                            r0 = r8;
                                        }
                                        r1 = LD32(r0 + r13);
                                        ST8(r1, 0);
                                        ST32(r0 + r12, 1);
                                        r9 = r9 + 1;
                                        r8 = r8 + 4;
                                        if (!(r9 >= v36)) {
                                            POLL();
                                            continue;
                                        } else {
                                            r0 = v36;
                                            ST32(r10 + 20, r0);
                                            break;
                                        }
                                    }
                                    POLL();
                                }
                            }
                            r0 = 1;
                        } else {
                            r4 = LD32(r10 + 8);
                            r0 = GCALL5(0x06027800, r4, 0, 0, 0, v36);
                            c8 = (r0 & r0) == 0;
                            r0 = 0;
                            if (c8) {
                                r0 = GCALL5(0x060279E0, 1, r8, 13, 1, v36);
                                r14 = r0;
                                r6 = r8;
                                if ((r14 & r14) == 0) {
                                    r0 = 0;
                                } else {
                                    r5 = LD32(r10 + 8);
                                    r0 = GCALL5(0x0604B358, r14, r5, r6, 0, v36);
                                    r4 = LD32(r10 + 8);
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, v36);
                                    ST32(r10 + 8, r14);
                                    r1 = LD32(r10);
                                    if ((r1 & r1) == 0) {
                                        r11 = 22;
                                    } else {
                                        r1 = LD32(r10 + 16);
                                        r11 = r1 + 1;
                                    }
                                    r0 = v36;
                                    r8 = r9;
                                    if (r9 >= r0) {
                                        ST32(r10 + 20, r0);
                                    } else {
                                        r8 = r8 << 2;
                                        while (1) {
                                            r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                            r1 = r0;
                                            r0 = r8;
                                            ST32(r0 + r13, r1);
                                            if ((r1 & r1) == 0) {
                                                POLL();
                                                ST32(r10 + 20, (r9 - 1));
                                                break;
                                            } else {
                                                r1 = LD32(r10);
                                                if ((r1 & r1) == 0) {
                                                    ST32(r0 + r14, r11);
                                                    r0 = r8;
                                                }
                                                r1 = LD32(r0 + r13);
                                                ST8(r1, 0);
                                                ST32(r0 + r12, 1);
                                                r9 = r9 + 1;
                                                r8 = r8 + 4;
                                                if (!(r9 >= v36)) {
                                                    POLL();
                                                    continue;
                                                } else {
                                                    r0 = v36;
                                                    ST32(r10 + 20, r0);
                                                    break;
                                                }
                                            }
                                            POLL();
                                        }
                                    }
                                    r0 = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        r4 = LD32(r10 + 4);
        r0 = GCALL5(0x06027800, r4, 0, 0, 0, v36);
        c1 = (r0 & r0) == 0;
        r0 = 0;
        if (c1) {
            r0 = GCALL5(0x060279E0, 1, r8, 13, 1, v36);
            r13 = r0;
            r6 = r8;
            if ((r13 & r13) == 0) {
                r0 = 0;
            } else {
                r5 = LD32(r10 + 4);
                r0 = GCALL5(0x0604B358, r13, r5, r6, 0, v36);
                r4 = LD32(r10 + 4);
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, v36);
                ST32(r10 + 4, r13);
                r5 = LD32(r10 + 12);
                r8 = v36 << 2;
                r7 = R(7);
                r0 = GCALL5(0x06027C18, 0, r5, r8, 0, v36);
                r12 = r0;
                if (!((r12 & r12) == 0)) {
                    r1 = LD32(r10);
                    ST32(r10 + 12, r12);
                    if (!((r1 & r1) == 0)) {
                        r1 = LD32(r10);
                        if ((r1 & r1) == 0) {
                            r11 = 22;
                        } else {
                            r1 = LD32(r10 + 16);
                            r11 = r1 + 1;
                        }
                        r0 = v36;
                        r8 = r9;
                        if (r9 >= r0) {
                            ST32(r10 + 20, r0);
                        } else {
                            r8 = r8 << 2;
                            while (1) {
                                r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                r1 = r0;
                                r0 = r8;
                                ST32(r0 + r13, r1);
                                if ((r1 & r1) == 0) {
                                    POLL();
                                    ST32(r10 + 20, (r9 - 1));
                                    break;
                                } else {
                                    r1 = LD32(r10);
                                    if ((r1 & r1) == 0) {
                                        ST32(r0 + r14, r11);
                                        r0 = r8;
                                    }
                                    r1 = LD32(r0 + r13);
                                    ST8(r1, 0);
                                    ST32(r0 + r12, 1);
                                    r9 = r9 + 1;
                                    r8 = r8 + 4;
                                    if (!(r9 >= v36)) {
                                        POLL();
                                        continue;
                                    } else {
                                        r0 = v36;
                                        ST32(r10 + 20, r0);
                                        break;
                                    }
                                }
                                POLL();
                            }
                        }
                        r0 = 1;
                    } else {
                        r8 = v36 << 2;
                        r5 = LD32(r10 + 8);
                        r7 = R(7);
                        r0 = GCALL5(0x06027C18, 0, r5, r8, 0, v36);
                        r14 = r0;
                        if (!((r14 & r14) == 0)) {
                            ST32(r10 + 8, r14);
                            r1 = LD32(r10);
                            if ((r1 & r1) == 0) {
                                r11 = 22;
                            } else {
                                r1 = LD32(r10 + 16);
                                r11 = r1 + 1;
                            }
                            r0 = v36;
                            r8 = r9;
                            if (r9 >= r0) {
                                ST32(r10 + 20, r0);
                            } else {
                                r8 = r8 << 2;
                                while (1) {
                                    r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                    r1 = r0;
                                    r0 = r8;
                                    ST32(r0 + r13, r1);
                                    if ((r1 & r1) == 0) {
                                        POLL();
                                        ST32(r10 + 20, (r9 - 1));
                                        break;
                                    } else {
                                        r1 = LD32(r10);
                                        if ((r1 & r1) == 0) {
                                            ST32(r0 + r14, r11);
                                            r0 = r8;
                                        }
                                        r1 = LD32(r0 + r13);
                                        ST8(r1, 0);
                                        ST32(r0 + r12, 1);
                                        r9 = r9 + 1;
                                        r8 = r8 + 4;
                                        if (!(r9 >= v36)) {
                                            POLL();
                                            continue;
                                        } else {
                                            r0 = v36;
                                            ST32(r10 + 20, r0);
                                            break;
                                        }
                                    }
                                    POLL();
                                }
                            }
                            r0 = 1;
                        } else {
                            r4 = LD32(r10 + 8);
                            r0 = GCALL5(0x06027800, r4, 0, 0, 0, v36);
                            c8 = (r0 & r0) == 0;
                            r0 = 0;
                            if (c8) {
                                r0 = GCALL5(0x060279E0, 1, r8, 13, 1, v36);
                                r14 = r0;
                                r6 = r8;
                                if ((r14 & r14) == 0) {
                                    r0 = 0;
                                } else {
                                    r5 = LD32(r10 + 8);
                                    r0 = GCALL5(0x0604B358, r14, r5, r6, 0, v36);
                                    r4 = LD32(r10 + 8);
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, v36);
                                    ST32(r10 + 8, r14);
                                    r1 = LD32(r10);
                                    if ((r1 & r1) == 0) {
                                        r11 = 22;
                                    } else {
                                        r1 = LD32(r10 + 16);
                                        r11 = r1 + 1;
                                    }
                                    r0 = v36;
                                    r8 = r9;
                                    if (r9 >= r0) {
                                        ST32(r10 + 20, r0);
                                    } else {
                                        r8 = r8 << 2;
                                        while (1) {
                                            r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                            r1 = r0;
                                            r0 = r8;
                                            ST32(r0 + r13, r1);
                                            if ((r1 & r1) == 0) {
                                                POLL();
                                                ST32(r10 + 20, (r9 - 1));
                                                break;
                                            } else {
                                                r1 = LD32(r10);
                                                if ((r1 & r1) == 0) {
                                                    ST32(r0 + r14, r11);
                                                    r0 = r8;
                                                }
                                                r1 = LD32(r0 + r13);
                                                ST8(r1, 0);
                                                ST32(r0 + r12, 1);
                                                r9 = r9 + 1;
                                                r8 = r8 + 4;
                                                if (!(r9 >= v36)) {
                                                    POLL();
                                                    continue;
                                                } else {
                                                    r0 = v36;
                                                    ST32(r10 + 20, r0);
                                                    break;
                                                }
                                            }
                                            POLL();
                                        }
                                    }
                                    r0 = 1;
                                }
                            }
                        }
                    }
                } else {
                    r4 = LD32(r10 + 12);
                    r0 = GCALL5(0x06027800, r4, 0, 0, 0, v36);
                    c4 = (r0 & r0) == 0;
                    r0 = 0;
                    if (c4) {
                        r0 = GCALL5(0x060279E0, 1, r8, 13, 1, v36);
                        r12 = r0;
                        r6 = r8;
                        if ((r12 & r12) == 0) {
                            r0 = 0;
                        } else {
                            r5 = LD32(r10 + 12);
                            r0 = GCALL5(0x0604B358, r12, r5, r6, 0, v36);
                            r4 = LD32(r10 + 12);
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL5(0x06027F48, r4, 0, 0, 0, v36);
                            r1 = LD32(r10);
                            ST32(r10 + 12, r12);
                            if (!((r1 & r1) == 0)) {
                                r1 = LD32(r10);
                                if ((r1 & r1) == 0) {
                                    r11 = 22;
                                } else {
                                    r1 = LD32(r10 + 16);
                                    r11 = r1 + 1;
                                }
                                r0 = v36;
                                r8 = r9;
                                if (r9 >= r0) {
                                    ST32(r10 + 20, r0);
                                } else {
                                    r8 = r8 << 2;
                                    while (1) {
                                        r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                        r1 = r0;
                                        r0 = r8;
                                        ST32(r0 + r13, r1);
                                        if ((r1 & r1) == 0) {
                                            POLL();
                                            ST32(r10 + 20, (r9 - 1));
                                            break;
                                        } else {
                                            r1 = LD32(r10);
                                            if ((r1 & r1) == 0) {
                                                ST32(r0 + r14, r11);
                                                r0 = r8;
                                            }
                                            r1 = LD32(r0 + r13);
                                            ST8(r1, 0);
                                            ST32(r0 + r12, 1);
                                            r9 = r9 + 1;
                                            r8 = r8 + 4;
                                            if (!(r9 >= v36)) {
                                                POLL();
                                                continue;
                                            } else {
                                                r0 = v36;
                                                ST32(r10 + 20, r0);
                                                break;
                                            }
                                        }
                                        POLL();
                                    }
                                }
                                r0 = 1;
                            } else {
                                r8 = v36 << 2;
                                r5 = LD32(r10 + 8);
                                r7 = R(7);
                                r0 = GCALL5(0x06027C18, 0, r5, r8, 0, v36);
                                r14 = r0;
                                if (!((r14 & r14) == 0)) {
                                    ST32(r10 + 8, r14);
                                    r1 = LD32(r10);
                                    if ((r1 & r1) == 0) {
                                        r11 = 22;
                                    } else {
                                        r1 = LD32(r10 + 16);
                                        r11 = r1 + 1;
                                    }
                                    r0 = v36;
                                    r8 = r9;
                                    if (r9 >= r0) {
                                        ST32(r10 + 20, r0);
                                    } else {
                                        r8 = r8 << 2;
                                        while (1) {
                                            r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                            r1 = r0;
                                            r0 = r8;
                                            ST32(r0 + r13, r1);
                                            if ((r1 & r1) == 0) {
                                                POLL();
                                                ST32(r10 + 20, (r9 - 1));
                                                break;
                                            } else {
                                                r1 = LD32(r10);
                                                if ((r1 & r1) == 0) {
                                                    ST32(r0 + r14, r11);
                                                    r0 = r8;
                                                }
                                                r1 = LD32(r0 + r13);
                                                ST8(r1, 0);
                                                ST32(r0 + r12, 1);
                                                r9 = r9 + 1;
                                                r8 = r8 + 4;
                                                if (!(r9 >= v36)) {
                                                    POLL();
                                                    continue;
                                                } else {
                                                    r0 = v36;
                                                    ST32(r10 + 20, r0);
                                                    break;
                                                }
                                            }
                                            POLL();
                                        }
                                    }
                                    r0 = 1;
                                } else {
                                    r4 = LD32(r10 + 8);
                                    r0 = GCALL5(0x06027800, r4, 0, 0, 0, v36);
                                    c8 = (r0 & r0) == 0;
                                    r0 = 0;
                                    if (c8) {
                                        r0 = GCALL5(0x060279E0, 1, r8, 13, 1, v36);
                                        r14 = r0;
                                        r6 = r8;
                                        if ((r14 & r14) == 0) {
                                            r0 = 0;
                                        } else {
                                            r5 = LD32(r10 + 8);
                                            r0 = GCALL5(0x0604B358, r14, r5, r6, 0, v36);
                                            r4 = LD32(r10 + 8);
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL5(0x06027F48, r4, 0, 0, 0, v36);
                                            ST32(r10 + 8, r14);
                                            r1 = LD32(r10);
                                            if ((r1 & r1) == 0) {
                                                r11 = 22;
                                            } else {
                                                r1 = LD32(r10 + 16);
                                                r11 = r1 + 1;
                                            }
                                            r0 = v36;
                                            r8 = r9;
                                            if (r9 >= r0) {
                                                ST32(r10 + 20, r0);
                                            } else {
                                                r8 = r8 << 2;
                                                while (1) {
                                                    r0 = GCALL5(0x06028380, r11, 13, 0, 0, v36);
                                                    r1 = r0;
                                                    r0 = r8;
                                                    ST32(r0 + r13, r1);
                                                    if ((r1 & r1) == 0) {
                                                        POLL();
                                                        ST32(r10 + 20, (r9 - 1));
                                                        break;
                                                    } else {
                                                        r1 = LD32(r10);
                                                        if ((r1 & r1) == 0) {
                                                            ST32(r0 + r14, r11);
                                                            r0 = r8;
                                                        }
                                                        r1 = LD32(r0 + r13);
                                                        ST8(r1, 0);
                                                        ST32(r0 + r12, 1);
                                                        r9 = r9 + 1;
                                                        r8 = r8 + 4;
                                                        if (!(r9 >= v36)) {
                                                            POLL();
                                                            continue;
                                                        } else {
                                                            r0 = v36;
                                                            ST32(r10 + 20, r0);
                                                            break;
                                                        }
                                                    }
                                                    POLL();
                                                }
                                            }
                                            r0 = 1;
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
void f06042C0C(int r4)
{
    int r0, r1, r2, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    int v36;

    r1 = LD32(0x0608BCD0);
    r13 = r4;
    if (!((r1 & r1) == 0)) {
        r1 = 0x06077CF8;
        r0 = LD32(0x06077CF8);
        while (1) {
            r1 = r1 + 24;
            if (!(r0 == 13)) {
                POLL();
                r0 = LD32(r1);
                continue;
            } else {
                break;
            }
        }
        r1 = LD32((r1 - 24) + 20);
        r2 = LD16((r1 + 8));
        r1 = LD16((r1 + 4));
        v36 = r2 - r1;
        r0 = GCALL5(0x0607507C, r13, 0, 0, 0, v36);
        r14 = r0;
        r11 = 0;
        do {
            r12 = r14 - 1;
            do {
                r6 = r12;
                r5 = r11;
                r0 = GCALL5(0x060221DC, r13, r5, r6, 0, v36);
                r12 = r12 - 1;
            } while (AGAIN(r0 > v36));
            r9 = 0x060773C8;
            r0 = LD32(0x060773D4);
            r12 = r12 + 1;
            if (!((r0 & r0) == 0)) {
                r1 = 0x060791A8;
                if (!(r0 == 0x060791A8)) {
                    ST32(r9 + 12, r1);
                    r7 = R(7);
                    r0 = GCALL5(0x06027F48, r0, r5, r6, 0, v36);
                }
            }
            r9 = r9 + 24;
            r1 = LD32(r9);
            r2 = r9;
            if (!((r1 & r1) == 0)) {
                r2 = r2 - 24;
                do {
                    r1 = LD32(r2 + 36);
                    r9 = r9 + 24;
                    ST32(r2 + 12, r1);
                    r1 = LD32(r9);
                    r2 = r2 + 24;
                } while (AGAIN(!((r1 & r1) == 0)));
            }
            r9 = r9 - 24;
            r10 = r12 - r11;
            r0 = GCALL5(0x060279E0, 0, (r10 + 2), -1, 1, v36);
            r8 = r0;
            r6 = r10;
            if ((r8 & r8) == 0) {
                r8 = 0x060791A8;
            } else {
                r0 = GCALL5(0x060750A0, r8, (r13 + r11), (r6 + 1), 0, v36);
                ST8(((r10 + r8) + 1), 0);
            }
            r11 = r12 + 1;
            ST32(r9 + 12, r8);
        } while (AGAIN(!(r11 >= r14)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604326C(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12, c2, c3;
    FRAME(sp, 32);

    r9 = r4;
    r11 = r5;
    r10 = r6;
    r12 = r7;
    ST32(sp - 32, 0);
    if (!((r9 & r9) == 0)) {
        r8 = LD32(r9 + 12);
        r0 = GCALL5(0x0604B3F0, r4, 0, 16, 0, LD32((sp - 32)));
        ST32(r9 + 12, r8);
    }
    r0 = GCALL5(0x06042D88, r9, r11, r10, (sp - 32), LD32((sp - 32)));
    c2 = (r9 & r9) == 0;
    if ((r0 & r0) == 0) {
        c3 = (r12 & r12) == 0;
        if (!(c2)) {
            r0 = 0;
            if (c3) {
                r0 = GCALL5(0x06043050, r9, r11, r10, (sp - 32), LD32((sp - 32)));
                r4 = r9;
                if (!((r0 & r0) == 0)) {
                    ST32(sp - 28, r0);
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(0x060432EC, r4, 0, 0, 0, LD32((sp - 32)), LD32((sp - 28)));
                    r0 = LD32(sp - 28);
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060473B4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r9, r10, r11, c4;
    FRAME(sp, 156);

    r9 = r4;
    r1 = LD32(r9);
    r10 = r5;
    if (r1 >= 0) {
        if (!((r6 & r6) == 0)) {
            r0 = GCALL3(0x0604B3F0, (sp - 156), 0, 136);
            ST16(sp - 156, 136);
            ST16((sp - 154), 0x7D6);
            r11 = (sp - 156) + 22;
            r1 = LD32(r9 + 28);
            ST32(sp - 144, r1);
            r1 = LD32(r9 + 16);
            r1 = r1 + 1;
            ST32(r9 + 16, r1);
            ST16(r11, r1);
            r0 = GCALL5(0x060750A0, (sp - 132), r10, 112, 0, LD32((sp - 156)));
            ST8(135 + (sp - 156), 0);
            r4 = LD32(r9 + 52);
            r0 = GCALL5(0x0604B358, (r4 + 8), (sp - 156), 136, 0, LD32((sp - 156)));
            r5 = LD32(r9 + 52);
            r4 = LD32(r9);
            r7 = R(7);
            r0 = GCALL5(0x0605B0D8, r4, r5, 136, 0, LD32((sp - 156)));
            c4 = r0 >= 0;
            r0 = 0;
            if (!(c4)) {
                r0 = -900;
            } else {
                r1 = LD32(0x0608B980);
                ST32(r9 + 8, r1);
                ST32(r9 + 4, 0);
                r1 = LD16(r11);
                ST32(r9 + 20, r1);
            }
        } else {
            r4 = LD32(r9 + 48);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
            }
            r0 = GCALL1(0x0607507C, r10);
            r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
            r1 = r0;
            ST32(r9 + 48, r1);
            if (!((r1 & r1) == 0)) {
                r0 = GCALL2(0x060750DC, r1, r10);
                r0 = GCALL3(0x0604B3F0, (sp - 156), 0, 136);
                ST16(sp - 156, 136);
                ST16((sp - 154), 0x7D6);
                r11 = (sp - 156) + 22;
                r1 = LD32(r9 + 28);
                ST32(sp - 144, r1);
                r1 = LD32(r9 + 16);
                r1 = r1 + 1;
                ST32(r9 + 16, r1);
                ST16(r11, r1);
                r0 = GCALL5(0x060750A0, (sp - 132), r10, 112, 0, LD32((sp - 156)));
                ST8(135 + (sp - 156), 0);
                r4 = LD32(r9 + 52);
                r0 = GCALL5(0x0604B358, (r4 + 8), (sp - 156), 136, 0, LD32((sp - 156)));
                r5 = LD32(r9 + 52);
                r4 = LD32(r9);
                r7 = R(7);
                r0 = GCALL5(0x0605B0D8, r4, r5, 136, 0, LD32((sp - 156)));
                c4 = r0 >= 0;
                r0 = 0;
                if (!(c4)) {
                    r0 = -900;
                } else {
                    r1 = LD32(0x0608B980);
                    ST32(r9 + 8, r1);
                    ST32(r9 + 4, 0);
                    r1 = LD16(r11);
                    ST32(r9 + 20, r1);
                }
            } else {
                r0 = -3;
            }
        }
    } else {
        r0 = -904;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06048C08(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14, c5;

    r9 = r4;
    r13 = r5;
    r14 = r6;
    if (!((r9 & r9) == 0)) {
        r1 = LD8(r9);
        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
            r8 = 0x060791C8;
            r1 = LD32(0x060791C8);
            r2 = r1 - 1;
            if (!(r2 >= 0)) {
                r2 = r1 + 31;
            }
            r10 = 0x0608CE90;
            r4 = LD32((((r2 << 2) + r2) << 2) + 0x0608CE90);
            if ((r4 & r4) == 0) {
                r1 = LD32(r8);
                r11 = 31;
                c5 = r1 > 31;
                r1 = 0;
                if (c5) {
                    ST32(r8, r1);
                }
                r12 = 0x06048CC0;
                r4 = LD32(r8);
                r5 = R(5);
                r0 = GCALL3(0x06048CC0, r4, r5, r6);
                r1 = LD32(r8);
                r0 = GCALL2(0x0603CCE0, ((((r1 << 2) + r1) << 2) + r10), r9);
                r2 = LD32(r8);
                r1 = (((r2 << 2) + r2) << 2) + r10;
                ST32(r1 + 8, r13);
                ST32(r1 + 12, r14);
                r2 = r2 + 1;
                ST32(r8, r2);
                if (r2 > r11) {
                    ST32(r8, 0);
                }
                r4 = LD32(r8);
                r0 = GCALL1(r12, r4);
            } else {
                r0 = GCALL2(0x0607533C, r4, r9);
                if (!((r0 & r0) == 0)) {
                    r1 = LD32(r8);
                    r11 = 31;
                    c5 = r1 > 31;
                    r1 = 0;
                    if (c5) {
                        ST32(r8, r1);
                    }
                    r12 = 0x06048CC0;
                    r4 = LD32(r8);
                    r5 = R(5);
                    r0 = GCALL3(0x06048CC0, r4, r5, r6);
                    r1 = LD32(r8);
                    r0 = GCALL2(0x0603CCE0, ((((r1 << 2) + r1) << 2) + r10), r9);
                    r2 = LD32(r8);
                    r1 = (((r2 << 2) + r2) << 2) + r10;
                    ST32(r1 + 8, r13);
                    ST32(r1 + 12, r14);
                    r2 = r2 + 1;
                    ST32(r8, r2);
                    if (r2 > r11) {
                        ST32(r8, 0);
                    }
                    r4 = LD32(r8);
                    r0 = GCALL1(r12, r4);
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060496CC(int r4)
{
    int r0, r1, r5, r6, r7, r8;
    FRAME(sp, 264);

    r8 = r4;
    r1 = LD32(r8);
    if (r1 >= 0) {
        r1 = LD32(0x060496C4);
        ST32(sp - 264, r1);
        r1 = LD16(0x060496C8);
        ST16((sp - 260), r1);
        r1 = LD8(0x060496CA);
        r7 = (sp - 264) + 6;
        ST8(r7, r1);
        r0 = GCALL5(0x0607507C, (sp - 264), 0, 0, 0, LD32((sp - 264)));
        r4 = LD32(r8);
        r0 = GCALL5(0x06049370, r4, (sp - 264), r0, r7, LD32((sp - 264)));
        r4 = LD32(r8);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL5(0x060493C4, r4, (sp - 264), 0, 0, LD32((sp - 264)));
        r4 = LD32(r8);
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL5(0x0605926C, r4, 0, 0, 0, LD32((sp - 264)));
        ST32(r8, -1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049748(int r4)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, c4, c7, c1004, c1018;
    FRAME(sp, 284);

    r8 = r4;
    r1 = LD32(r8);
    r9 = 0;
    if (r1 >= 0) {
        r1 = LD32(0x06049740);
        ST32(sp - 284, r1);
        r1 = LD16(0x06049744);
        ST16((sp - 280), r1);
        r1 = LD8(0x06049746);
        r7 = (sp - 284) + 6;
        ST8(r7, r1);
        r0 = GCALL5(0x0607507C, (sp - 284), 0, 0, 0, LD32((sp - 284)));
        r4 = LD32(r8);
        r0 = GCALL5(0x06049370, r4, (sp - 284), r0, r7, LD32((sp - 284)));
        c4 = r0 == -12;
        if (r0 >= 0) {
            r4 = LD32(r8);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL5(0x060493C4, r4, (sp - 284), 0, 0, LD32((sp - 284)));
            c7 = r0 == -12;
            if (r0 >= 0) {
                r1 = LD8(sp - 284);
                r3 = sp - 284;
                while (!((r1 & 255) == 32)) {
                    POLL();
                    r1 = LD8(r3);
                    if (((r1 & 255) & (r1 & 255)) == 0) {
                        break;
                    } else {
                        r3 = r3 + 1;
                        r1 = LD8(r3);
                    }
                }
                r3 = r3 + 1;
                r2 = LD8(r3);
                r7 = (sp - 284) + 0x100;
                while (1) {
                    r1 = r2 & 255;
                    if (!((r2 & 255) == 32)) {
                        POLL();
                        if ((r1 & r1) == 0) {
                            break;
                        } else {
                            ST8(r7, r2);
                            r3 = r3 + 1;
                            r2 = LD8(r3);
                            r7 = r7 + 1;
                            continue;
                        }
                    } else {
                        break;
                    }
                }
                ST8(r7, 0);
                r0 = GCALL5(0x06075438, ((sp - 284) + 0x100), 0, 0, 0, LD32((sp - 284)));
                c1018 = (r9 & r9) == 0;
            } else {
                r0 = -1;
                c1004 = c7;
                POLL();
                if (!(c1004)) {
                    c1018 = (r9 & r9) == 0;
                } else {
                    r0 = -12;
                    c1018 = (r9 & r9) == 0;
                }
            }
        } else {
            r0 = -600;
            c1004 = c4;
            if (!(c1004)) {
                c1018 = (r9 & r9) == 0;
            } else {
                r0 = -12;
                c1018 = (r9 & r9) == 0;
            }
        }
    } else {
        r9 = 1;
        r0 = GCALL1(0x06049414, r4);
        c1018 = 1 == 0;
        if (r0 >= 0) {
            r1 = LD32(0x06049740);
            ST32(sp - 284, r1);
            r1 = LD16(0x06049744);
            ST16((sp - 280), r1);
            r1 = LD8(0x06049746);
            r7 = (sp - 284) + 6;
            ST8(r7, r1);
            r0 = GCALL5(0x0607507C, (sp - 284), 0, 0, 0, LD32((sp - 284)));
            r4 = LD32(r8);
            r0 = GCALL5(0x06049370, r4, (sp - 284), r0, r7, LD32((sp - 284)));
            c4 = r0 == -12;
            if (r0 >= 0) {
                r4 = LD32(r8);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(0x060493C4, r4, (sp - 284), 0, 0, LD32((sp - 284)));
                c7 = r0 == -12;
                if (r0 >= 0) {
                    r1 = LD8(sp - 284);
                    r3 = sp - 284;
                    while (!((r1 & 255) == 32)) {
                        POLL();
                        r1 = LD8(r3);
                        if (((r1 & 255) & (r1 & 255)) == 0) {
                            break;
                        } else {
                            r3 = r3 + 1;
                            r1 = LD8(r3);
                        }
                    }
                    r3 = r3 + 1;
                    r2 = LD8(r3);
                    r7 = (sp - 284) + 0x100;
                    while (1) {
                        r1 = r2 & 255;
                        if (!((r2 & 255) == 32)) {
                            POLL();
                            if ((r1 & r1) == 0) {
                                break;
                            } else {
                                ST8(r7, r2);
                                r3 = r3 + 1;
                                r2 = LD8(r3);
                                r7 = r7 + 1;
                                continue;
                            }
                        } else {
                            break;
                        }
                    }
                    ST8(r7, 0);
                    r0 = GCALL5(0x06075438, ((sp - 284) + 0x100), 0, 0, 0, LD32((sp - 284)));
                    c1018 = (r9 & r9) == 0;
                } else {
                    r0 = -1;
                    c1004 = c7;
                    POLL();
                    if (!(c1004)) {
                        c1018 = (r9 & r9) == 0;
                    } else {
                        r0 = -12;
                        c1018 = (r9 & r9) == 0;
                    }
                }
            } else {
                r0 = -600;
                c1004 = c4;
                if (!(c1004)) {
                    c1018 = (r9 & r9) == 0;
                } else {
                    r0 = -12;
                    c1018 = (r9 & r9) == 0;
                }
            }
        }
    }
    r4 = r8;
    if (!(c1018)) {
        ST32((0x108 + (sp - 284)), r0);
        r0 = GCALL5(0x060496CC, r4, 0, 0, 0, LD32((sp - 284)));
        r0 = LD32((0x108 + (sp - 284)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A250(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 548);

    r10 = r4;
    ST32(0x200 + (sp - 548), r5);
    r14 = r6;
    if ((r7 & r7) == 0) {
        r11 = 0x060791D8;
        r1 = LD32(0x060791D8);
        r4 = r10;
        if (r1 > 0) {
            r1 = LD32(0x060791D8);
            r0 = 0;
            if (r1 > 0) {
                r12 = 0x060791DC;
                r4 = LD32(0x060791DC);
                r13 = 0x0608D110;
                r0 = GCALL2(0x06075830, (r4 + 0x0608D110), r14);
                r11 = r0;
                r2 = r11;
                if ((r11 & r11) == 0) {
                    r4 = LD32(r12);
                    r0 = GCALL1(0x0607507C, (r4 + 0x0608D110));
                    r10 = r0;
                    r5 = LD32(r12);
                    r0 = GCALL2(0x060750DC, (sp - 548), (r5 + 0x0608D110));
                    r2 = LD32(r12);
                    ST8((sp - 547) + r2, 0);
                    r0 = GCALL2(0x060750DC, 0x0608D110, (sp - 548));
                    ST32(0x060791D8, 0);
                    ST32(r12, r10);
                    r0 = LD32((0x200 + (sp - 548)));
                    ST8(r0, 0);
                    r0 = 0;
                } else {
                    r1 = LD32(r12);
                    r8 = ((r2 - r13) - r1) + 1;
                    r0 = GCALL1(0x0607507C, r14);
                    r1 = LD32(r12);
                    ST32(r12, (r1 + (r8 + r0)));
                    r0 = GCALL1(0x0607507C, r14);
                    r11 = r11 + (r0 + 1);
                    r1 = LD8(r11);
                    r6 = 32;
                    if (!((r1 & 255) == 58)) {
                        r4 = LD32((0x200 + (sp - 548)));
                        r0 = GCALL3(0x0604A218, r4, r11, r6);
                        r3 = LD32((0x200 + (sp - 548)));
                        ST8(r0 + r3, 0);
                        r1 = LD32(0x060791DC);
                        ST32(0x060791DC, ((r1 + 1) + r0));
                        r0 = 0;
                    } else {
                        r0 = GCALL2(0x06075830, r11, 0x0604A240);
                        r1 = 0;
                        if ((r0 & r0) == 0) {
                            r6 = 32;
                            r4 = LD32((0x200 + (sp - 548)));
                            r0 = GCALL3(0x0604A218, r4, r11, r6);
                            r3 = LD32((0x200 + (sp - 548)));
                            ST8(r0 + r3, 0);
                            r1 = LD32(0x060791DC);
                            ST32(0x060791DC, ((r1 + 1) + r0));
                            r0 = 0;
                        } else {
                            ST32(0x060791D8, r1);
                            ST32(r12, r1);
                            r0 = -1;
                        }
                    }
                }
            }
        } else {
            r8 = 0x060791DC;
            r5 = LD32(0x060791DC);
            r9 = 0x0608D110;
            r6 = R(6);
            r0 = GCALL4(0x060492D0, r4, (r5 + 0x0608D110), r6, r7);
            r7 = r0;
            if (r7 >= 0) {
                r1 = LD32(r8);
                ST8((r7 + r1) + (r9 + 1), 0);
                ST32(r11, r7);
                ST32(r8, 0);
                r1 = LD32(0x060791D8);
                r0 = 0;
                if (r1 > 0) {
                    r12 = 0x060791DC;
                    r4 = LD32(0x060791DC);
                    r13 = 0x0608D110;
                    r0 = GCALL2(0x06075830, (r4 + 0x0608D110), r14);
                    r11 = r0;
                    r2 = r11;
                    if ((r11 & r11) == 0) {
                        r4 = LD32(r12);
                        r0 = GCALL1(0x0607507C, (r4 + 0x0608D110));
                        r10 = r0;
                        r5 = LD32(r12);
                        r0 = GCALL2(0x060750DC, (sp - 548), (r5 + 0x0608D110));
                        r2 = LD32(r12);
                        ST8((sp - 547) + r2, 0);
                        r0 = GCALL2(0x060750DC, 0x0608D110, (sp - 548));
                        ST32(0x060791D8, 0);
                        ST32(r12, r10);
                        r0 = LD32((0x200 + (sp - 548)));
                        ST8(r0, 0);
                        r0 = 0;
                    } else {
                        r1 = LD32(r12);
                        r8 = ((r2 - r13) - r1) + 1;
                        r0 = GCALL1(0x0607507C, r14);
                        r1 = LD32(r12);
                        ST32(r12, (r1 + (r8 + r0)));
                        r0 = GCALL1(0x0607507C, r14);
                        r11 = r11 + (r0 + 1);
                        r1 = LD8(r11);
                        r6 = 32;
                        if (!((r1 & 255) == 58)) {
                            r4 = LD32((0x200 + (sp - 548)));
                            r0 = GCALL3(0x0604A218, r4, r11, r6);
                            r3 = LD32((0x200 + (sp - 548)));
                            ST8(r0 + r3, 0);
                            r1 = LD32(0x060791DC);
                            ST32(0x060791DC, ((r1 + 1) + r0));
                            r0 = 0;
                        } else {
                            r0 = GCALL2(0x06075830, r11, 0x0604A240);
                            r1 = 0;
                            if ((r0 & r0) == 0) {
                                r6 = 32;
                                r4 = LD32((0x200 + (sp - 548)));
                                r0 = GCALL3(0x0604A218, r4, r11, r6);
                                r3 = LD32((0x200 + (sp - 548)));
                                ST8(r0 + r3, 0);
                                r1 = LD32(0x060791DC);
                                ST32(0x060791DC, ((r1 + 1) + r0));
                                r0 = 0;
                            } else {
                                ST32(0x060791D8, r1);
                                ST32(r12, r1);
                                r0 = -1;
                            }
                        }
                    }
                }
            }
        }
    } else {
        r0 = GCALL4(0x06045264, 0x0608D110, 0x0604A238, r6, r7);
        r0 = GCALL1(0x0607507C, 0x0608D110);
        r0 = GCALL3(0x06049370, r10, 0x0608D110, r0);
        r7 = r0;
        r1 = 0;
        if (r7 >= 0) {
            ST32(0x060791D8, r1);
            ST32(0x060791DC, r1);
            r11 = 0x060791D8;
            r1 = LD32(0x060791D8);
            r4 = r10;
            if (r1 > 0) {
                r1 = LD32(0x060791D8);
                r0 = 0;
                if (r1 > 0) {
                    r12 = 0x060791DC;
                    r4 = LD32(0x060791DC);
                    r13 = 0x0608D110;
                    r0 = GCALL2(0x06075830, (r4 + 0x0608D110), r14);
                    r11 = r0;
                    r2 = r11;
                    if ((r11 & r11) == 0) {
                        r4 = LD32(r12);
                        r0 = GCALL1(0x0607507C, (r4 + 0x0608D110));
                        r10 = r0;
                        r5 = LD32(r12);
                        r0 = GCALL2(0x060750DC, (sp - 548), (r5 + 0x0608D110));
                        r2 = LD32(r12);
                        ST8((sp - 547) + r2, 0);
                        r0 = GCALL2(0x060750DC, 0x0608D110, (sp - 548));
                        ST32(0x060791D8, 0);
                        ST32(r12, r10);
                        r0 = LD32((0x200 + (sp - 548)));
                        ST8(r0, 0);
                        r0 = 0;
                    } else {
                        r1 = LD32(r12);
                        r8 = ((r2 - r13) - r1) + 1;
                        r0 = GCALL1(0x0607507C, r14);
                        r1 = LD32(r12);
                        ST32(r12, (r1 + (r8 + r0)));
                        r0 = GCALL1(0x0607507C, r14);
                        r11 = r11 + (r0 + 1);
                        r1 = LD8(r11);
                        r6 = 32;
                        if (!((r1 & 255) == 58)) {
                            r4 = LD32((0x200 + (sp - 548)));
                            r0 = GCALL3(0x0604A218, r4, r11, r6);
                            r3 = LD32((0x200 + (sp - 548)));
                            ST8(r0 + r3, 0);
                            r1 = LD32(0x060791DC);
                            ST32(0x060791DC, ((r1 + 1) + r0));
                            r0 = 0;
                        } else {
                            r0 = GCALL2(0x06075830, r11, 0x0604A240);
                            r1 = 0;
                            if ((r0 & r0) == 0) {
                                r6 = 32;
                                r4 = LD32((0x200 + (sp - 548)));
                                r0 = GCALL3(0x0604A218, r4, r11, r6);
                                r3 = LD32((0x200 + (sp - 548)));
                                ST8(r0 + r3, 0);
                                r1 = LD32(0x060791DC);
                                ST32(0x060791DC, ((r1 + 1) + r0));
                                r0 = 0;
                            } else {
                                ST32(0x060791D8, r1);
                                ST32(r12, r1);
                                r0 = -1;
                            }
                        }
                    }
                }
            } else {
                r8 = 0x060791DC;
                r5 = LD32(0x060791DC);
                r9 = 0x0608D110;
                r6 = R(6);
                r0 = GCALL4(0x060492D0, r4, (r5 + 0x0608D110), r6, r7);
                r7 = r0;
                if (r7 >= 0) {
                    r1 = LD32(r8);
                    ST8((r7 + r1) + (r9 + 1), 0);
                    ST32(r11, r7);
                    ST32(r8, 0);
                    r1 = LD32(0x060791D8);
                    r0 = 0;
                    if (r1 > 0) {
                        r12 = 0x060791DC;
                        r4 = LD32(0x060791DC);
                        r13 = 0x0608D110;
                        r0 = GCALL2(0x06075830, (r4 + 0x0608D110), r14);
                        r11 = r0;
                        r2 = r11;
                        if ((r11 & r11) == 0) {
                            r4 = LD32(r12);
                            r0 = GCALL1(0x0607507C, (r4 + 0x0608D110));
                            r10 = r0;
                            r5 = LD32(r12);
                            r0 = GCALL2(0x060750DC, (sp - 548), (r5 + 0x0608D110));
                            r2 = LD32(r12);
                            ST8((sp - 547) + r2, 0);
                            r0 = GCALL2(0x060750DC, 0x0608D110, (sp - 548));
                            ST32(0x060791D8, 0);
                            ST32(r12, r10);
                            r0 = LD32((0x200 + (sp - 548)));
                            ST8(r0, 0);
                            r0 = 0;
                        } else {
                            r1 = LD32(r12);
                            r8 = ((r2 - r13) - r1) + 1;
                            r0 = GCALL1(0x0607507C, r14);
                            r1 = LD32(r12);
                            ST32(r12, (r1 + (r8 + r0)));
                            r0 = GCALL1(0x0607507C, r14);
                            r11 = r11 + (r0 + 1);
                            r1 = LD8(r11);
                            r6 = 32;
                            if (!((r1 & 255) == 58)) {
                                r4 = LD32((0x200 + (sp - 548)));
                                r0 = GCALL3(0x0604A218, r4, r11, r6);
                                r3 = LD32((0x200 + (sp - 548)));
                                ST8(r0 + r3, 0);
                                r1 = LD32(0x060791DC);
                                ST32(0x060791DC, ((r1 + 1) + r0));
                                r0 = 0;
                            } else {
                                r0 = GCALL2(0x06075830, r11, 0x0604A240);
                                r1 = 0;
                                if ((r0 & r0) == 0) {
                                    r6 = 32;
                                    r4 = LD32((0x200 + (sp - 548)));
                                    r0 = GCALL3(0x0604A218, r4, r11, r6);
                                    r3 = LD32((0x200 + (sp - 548)));
                                    ST8(r0 + r3, 0);
                                    r1 = LD32(0x060791DC);
                                    ST32(0x060791DC, ((r1 + 1) + r0));
                                    r0 = 0;
                                } else {
                                    ST32(0x060791D8, r1);
                                    ST32(r12, r1);
                                    r0 = -1;
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
int f060407B0(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r11, r12, c2011;

    r11 = R(11);
    r10 = r4;
    r12 = r6;
    r0 = LD32(r10 + 16);
    r8 = -1;
    if (r0 == -1) {
        r4 = LD32(r5);
        r0 = GCALL1(0x0604034C, r4);
    }
    r1 = LD32(r10 + 52);
    r9 = r0;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL1(r1, -607);
        r8 = r0;
    }
    r1 = 2;
    if ((r8 & r8) == 0) {
        ST32(0x0607668C, r1);
        r1 = LD32(r10 + 40);
        if (!((r1 & r1) == 0)) {
            r0 = GCALL2(r1, 0x06040788, 5);
        }
        c2011 = R(11);
        SETR(11, r11);
        r0 = GCALL2(0x06049858, r10, r9);
        SETR(11, c2011);
        if (!((r0 & r0) == 0)) {
            r1 = LD32(r10 + 52);
            r4 = r0;
            if (!((r1 & r1) == 0)) {
                r0 = GCALL1(r1, r4);
            }
            r0 = GCALL1(0x060496CC, r10);
        } else {
            r4 = LD32(r10 + 4);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(0x06027F48, r4);
                ST32(r10 + 4, 0);
            }
            r0 = GCALL2(0x0603F42C, r10, 0);
            if (!(r0 >= 0)) {
                r1 = LD32(r10 + 52);
                r4 = -3;
                if (!((r1 & r1) == 0)) {
                    r0 = GCALL1(r1, r4);
                }
                r0 = GCALL1(0x060496CC, r10);
            } else {
                r11 = 0x0607507C;
                r4 = LD32(r10 + 4);
                r0 = GCALL1(0x0607507C, r4);
                r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                r9 = r0;
                ST32(r12, r9);
                if (!((r9 & r9) == 0)) {
                    r8 = LD32(r10 + 4);
                    r0 = GCALL1(r11, r8);
                    r0 = GCALL3(0x0604B358, r9, r8, (r0 + 1));
                    r1 = LD32(r10 + 44);
                    if (!((r1 & r1) == 0)) {
                        r0 = GCALL1(r1, 0x06040798);
                    }
                    r0 = GCALL1(0x060496CC, r10);
                } else {
                    r1 = LD32(r10 + 52);
                    if (!((r1 & r1) == 0)) {
                        r0 = GCALL1(r1, -3);
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043D04(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r8, r9, r10, r11, r12, c0, c5, c2011;

    r11 = R(11);
    r12 = 0x060791AC;
    r2 = LD32(0x060791AC);
    c0 = r2 > -1;
    r0 = c0;
    if (c0) {
        ST32(0x06077030, r0);
        c2011 = R(11);
        SETR(11, r11);
        r0 = GCALL1(0x06010DDC, 5);
        SETR(11, c2011);
        if ((r0 & r0) == 0) {
            r1 = LD32(r12);
            r2 = LD32(0x0608BCFC);
            r11 = 0x0608BD04;
            r6 = LD32(0x0608BD08);
            r2 = (r2 + r1) << 2;
            r10 = r6 + r2;
            r1 = LD32(0x0608BD04);
            ST32(0x0608BD04, (r1 - 1));
            r4 = LD32(r6 + r2);
            r5 = R(5);
            r0 = GCALL4(0x06027F48, r4, r5, r6, 0x0608BD00);
            r2 = LD32(0x0608BCFC);
            r1 = LD32(r12);
            r2 = r2 + r1;
            r1 = LD32(0x0608BD04);
            r9 = r10 + 4;
            if (!(r2 >= r1)) {
                r3 = r11;
                do {
                    r1 = LD32(r9);
                    r9 = r9 + 4;
                    r2 = r2 + 1;
                    ST32(r10, r1);
                    r1 = LD32(r3);
                    r10 = r10 + 4;
                } while (AGAIN(!(r2 >= r1)));
            }
            r0 = GCALL0(0x06043B20);
            if (!((r0 & r0) == 0)) {
                r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
                c2011 = R(11);
                SETR(11, r11);
                r0 = GCALL1(0x06010DDC, 24);
                SETR(11, c2011);
            }
            r8 = 0x0608BD04;
            r6 = LD32(0x0608BD04);
            c5 = r6 > 1;
            r6 = r6 << 2;
            if (c5) {
                r5 = LD32(r8 + 4);
                r0 = GCALL3(0x06027C18, 0, r5, r6);
                ST32(r8 + 4, r0);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06043DE4(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r8, r9, r10, r11, r12, c0, c5, c2011;

    r11 = R(11);
    r12 = 0x060791AC;
    r2 = LD32(0x060791AC);
    c0 = r2 > -1;
    r2 = 0;
    if (c0) {
        ST32(0x06077030, r2);
        c2011 = R(11);
        SETR(11, r11);
        r0 = GCALL1(0x06010DDC, 5);
        SETR(11, c2011);
        if ((r0 & r0) == 0) {
            r1 = LD32(r12);
            r2 = LD32(0x0608BCFC);
            r11 = 0x0608BCF4;
            r6 = LD32(0x0608BCF8);
            r2 = (r2 + r1) << 2;
            r10 = r6 + r2;
            r1 = LD32(0x0608BCF4);
            ST32(0x0608BCF4, (r1 - 1));
            r4 = LD32(r6 + r2);
            r5 = R(5);
            r0 = GCALL4(0x06027F48, r4, r5, r6, 0x0608BCF0);
            r2 = LD32(0x0608BCFC);
            r1 = LD32(r12);
            r2 = r2 + r1;
            r1 = LD32(0x0608BCF4);
            r9 = r10 + 4;
            if (!(r2 >= r1)) {
                r3 = r11;
                do {
                    r1 = LD32(r9);
                    r9 = r9 + 4;
                    r2 = r2 + 1;
                    ST32(r10, r1);
                    r1 = LD32(r3);
                    r10 = r10 + 4;
                } while (AGAIN(!(r2 >= r1)));
            }
            r0 = GCALL0(0x06043C08);
            if (!((r0 & r0) == 0)) {
                r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
                c2011 = R(11);
                SETR(11, r11);
                r0 = GCALL1(0x06010DDC, 24);
                SETR(11, c2011);
            }
            r8 = 0x0608BCF4;
            r6 = LD32(0x0608BCF4);
            c5 = r6 > 1;
            r6 = r6 << 2;
            if (c5) {
                r5 = LD32(r8 + 4);
                r0 = GCALL3(0x06027C18, 0, r5, r6);
                ST32(r8 + 4, r0);
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046B88(void)
{
    int r0, r1, r2, r4, r5, r6, r7, r8, r9, r12, r13, r14;
    long long m0;

    r13 = 0;
    r14 = 0x060468FC;
    r8 = 0x06088034;
    r12 = 0;
    while (1) {
        r1 = LD32(0x06088034 + r12);
        if ((r1 & r1) == 0) {
            r0 = GCALL0(0x060468E8);
            r2 = (short)r0;
            r4 = HELPER((int)(((int)(((long long)r2 * ((int)0x80808081)) >> 32)) + r2) >> 7);
            if ((((short)(r2 - (((r4 - (((r2 << 1) - (r2 << 1)) - ((unsigned)r2 >> 31))) << 8) - (r4 - (((r2 << 1) - (r2 << 1)) - ((unsigned)r2 >> 31)))))) & ((short)(r2 - (((r4 - (((r2 << 1) - (r2 << 1)) - ((unsigned)r2 >> 31))) << 8) - (r4 - (((r2 << 1) - (r2 << 1)) - ((unsigned)r2 >> 31))))))) == 0) {
                r0 = 0x0608962C;
                r1 = LD32(0x0608962C);
                if (!((r1 & r1) == 0)) {
                    r0 = GCALL1(0x060469B4, r8);
                    r0 = 0x06088034;
                    ST32(0x06088034 + r12, 1);
                }
            }
            r8 = r8 + 28;
        } else {
            r1 = LD32(0x0608962C);
            if (!((r1 & r1) == 0)) {
                r5 = LD32(r8 + 24);
                r4 = LD32(r8 + 20);
                r0 = GCALL3(r14, r4, r5, 0);
                r2 = LD32(r8 + 16);
                r1 = LD32(0x0608962C);
                r5 = r2 - r1;
                ST32(r8 + 16, r5);
                if (!(r5 > 0)) {
                    r0 = GCALL1(0x060469B4, r8);
                    r8 = r8 + 28;
                } else {
                    r1 = LD32(r8 + 8);
                    r7 = 0x06089624;
                    r0 = GCALL2(0x0607286C, (r1 * 200), r5);
                    r1 = LD32(0x06089624);
                    r9 = r0;
                    ST32(r8 + 20, (r1 + r9));
                    r1 = LD32(r8 + 12);
                    r5 = LD32(r8 + 16);
                    r0 = GCALL2(0x0607286C, (r1 * 200), r5);
                    r6 = r0;
                    r1 = LD32(0x06089628);
                    ST32(r8 + 24, (r1 + r6));
                    r0 = GCALL3(0x06046B60, r9, r6, 0x06089614);
                    r1 = r8;
                    if (!((r0 & r0) == 0)) {
                        r6 = LD8((r1 + 4));
                        r5 = LD32(r8 + 24);
                        r4 = LD32(r8 + 20);
                        r0 = GCALL4(r14, r4, r5, r6, r7);
                        r8 = r8 + 28;
                    } else {
                        r0 = GCALL1(0x060469B4, r8);
                        r8 = r8 + 28;
                    }
                }
            } else {
                r0 = GCALL0(0x060468E8);
                r2 = (short)r0;
                m0 = (long long)r2 * 0x10624DD3;
                r4 = HELPER((int)((int)(m0 >> 32)) >> 6);
                if (!((((short)(r2 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)((r4 - (((r2 << 1) - (r2 << 1)) - ((unsigned)r2 >> 31))) * 0x3E8))))) & ((short)(r2 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)((r4 - (((r2 << 1) - (r2 << 1)) - ((unsigned)r2 >> 31))) * 0x3E8)))))) == 0)) {
                    r8 = r8 + 28;
                } else {
                    r1 = LD32(r8 + 16);
                    if (!(r1 > 0)) {
                        r8 = r8 + 28;
                    } else {
                        r0 = GCALL0(0x060468E8);
                        r6 = (short)r0;
                        m0 = (long long)r6 * ((int)0x81020409);
                        r4 = HELPER((int)(((int)(m0 >> 32)) + r6) >> 7);
                        r6 = (r6 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)((r4 - (((r6 << 1) - (r6 << 1)) - ((unsigned)r6 >> 31))) * 254)))) + 1;
                        ST8((r8 + 4), r6);
                        r5 = LD32(r8 + 24);
                        r4 = LD32(r8 + 20);
                        r0 = GCALL3(r14, r4, r5, ((signed char)r6));
                        r8 = r8 + 28;
                    }
                }
            }
        }
        r13 = r13 + 1;
        r12 = r12 + 28;
        if (r13 > 199) {
            break;
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06042A20(int r4, int r5)
{
    int r0, r1, r6, r7, r8, r9, r10, r11, r12, r13, r14, c2, c5;
    long long m0;
    int v36;

    r8 = r4;
    r14 = r5;
    r11 = 0;
    r13 = r8;
    r0 = GCALL1(0x060255E0, (r13 + 10));
    r13 = r13 + r0;
    r0 = GCALL1(0x060255E0, (r8 + 30));
    r10 = r0;
    r0 = GCALL1(0x060255E0, (r8 + 18));
    r12 = r0;
    r0 = GCALL1(0x060255E0, (r8 + 22));
    r9 = r0;
    r0 = r10;
    r1 = 1;
    if (r0 == 1) {
        r0 = GCALL2(0x06028380, (r12 * r9), -1);
        r11 = r0;
        r7 = r9;
        if ((r11 & r11) == 0) {
            r0 = 0;
        } else {
            r0 = GCALL4(0x0604274C, r13, r11, r12, r7);
            r0 = r11;
        }
    } else {
        c2 = (r10 & r10) == 0;
        if (r10 > r1) {
            c5 = (r14 & r14) == 0;
            if (r0 == 2) {
                m0 = (unsigned)(r12 * r9);
                if (c5) {
                    r8 = r12 >> 1;
                    r0 = GCALL2(0x06028380, (r8 * r9), -1);
                    r11 = r0;
                    r7 = r9;
                    if (!((r11 & r11) == 0)) {
                        v36 = r14;
                        r1 = 0x06042804;
                        r6 = r8;
                        r0 = GCALL5(r1, r13, r11, r6, r7, v36);
                        r0 = r11;
                    } else {
                        r0 = 0;
                    }
                } else {
                    r0 = GCALL2(0x06028380, ((int)m0), -1);
                    r11 = r0;
                    if ((r11 & r11) == 0) {
                        r0 = 0;
                    } else {
                        v36 = r14;
                        r1 = 0x06042804;
                        r7 = r9;
                        r6 = r12;
                        r0 = GCALL5(r1, r13, r11, r6, r7, v36);
                        r0 = r11;
                    }
                }
            } else {
                r0 = r11;
            }
        } else {
            m0 = (unsigned)(r12 * r9);
            if (c2) {
                r0 = GCALL2(0x06028380, ((int)m0), -1);
                r11 = r0;
                m0 = (m0 & ~0xFFFFFFFFLL) | (unsigned)((int)m0);
                if ((r11 & r11) == 0) {
                    r0 = 0;
                } else {
                    r0 = GCALL3(0x0604B358, r11, r13, ((int)m0));
                    r0 = r11;
                }
            } else {
                r0 = r11;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045430(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, c3, c10, c19, c20, c21, c23, c28, c1007, c1013, c1023, c1029, c1041;
    long long m0;

    r10 = r4;
    r11 = r5;
    r8 = r6;
    r7 = r10;
    r9 = 0;
    r3 = 0x06075135;
    do {
        r1 = LD8(r7);
        r7 = r7 + 1;
        r2 = r1 & 255;
        r1 = LD8(r2 + r3);
        r0 = r2;
    } while (AGAIN(!(((r1 & 8) & (r1 & 8)) == 0)));
    if (!(r0 == 45)) {
        c3 = (r8 & r8) == 0;
        c1007 = c3;
        if (r0 == 43) {
            r1 = LD8(r7);
            r7 = r7 + 1;
            r2 = r1 & 255;
            c1007 = (r8 & r8) == 0;
        }
    } else {
        r1 = LD8(r7);
        r7 = r7 + 1;
        r9 = 1;
        r2 = r1 & 255;
        c1007 = (r8 & r8) == 0;
    }
    r0 = r8;
    if (c1007) {
        c1013 = (r8 & r8) == 0;
        if (r2 == 48) {
            r1 = LD8(r7);
            r0 = r1;
            c10 = r0 == 88;
            if (r0 == 120) {
                r1 = LD8((r7 + 1));
                r7 = r7 + 2;
                r8 = 16;
                r2 = r1 & 255;
                c1013 = 16 == 0;
            } else {
                c1013 = (r8 & r8) == 0;
                if (c10) {
                    r1 = LD8((r7 + 1));
                    r7 = r7 + 2;
                    r8 = 16;
                    r2 = r1 & 255;
                    c1013 = 16 == 0;
                }
            }
        }
    } else {
        c1013 = (r8 & r8) == 0;
        if (r0 == 16) {
            c1013 = (r8 & r8) == 0;
            if (r2 == 48) {
                r1 = LD8(r7);
                r0 = r1;
                c10 = r0 == 88;
                if (r0 == 120) {
                    r1 = LD8((r7 + 1));
                    r7 = r7 + 2;
                    r8 = 16;
                    r2 = r1 & 255;
                    c1013 = 16 == 0;
                } else {
                    c1013 = (r8 & r8) == 0;
                    if (c10) {
                        r1 = LD8((r7 + 1));
                        r7 = r7 + 2;
                        r8 = 16;
                        r2 = r1 & 255;
                        c1013 = 16 == 0;
                    }
                }
            }
        }
    }
    r4 = -1;
    if (c1013) {
        r8 = 10;
        if (r2 == 48) {
            r8 = 8;
            r4 = -1;
        }
    }
    r0 = GCALL2(0x060745A0, r4, r8);
    r5 = r0;
    r3 = 0;
    r6 = 0;
    r4 = ~(r5 * r8);
    while (!((unsigned)r2 > (unsigned)127)) {
        POLL();
        r12 = LD8(r2 + 0x06075135);
        r1 = r2;
        if (((4 & r12) & (4 & r12)) == 0) {
            r0 = r12;
            if (((3 & r12) & (3 & r12)) == 0) {
                break;
            } else {
                r1 = r2;
                if (((r0 & 1) & (r0 & 1)) == 0) {
                    r1 = r1 - 87;
                    c1023 = 1;
                } else {
                    r1 = r1 - 55;
                    c1023 = 0;
                }
                r2 = r1 & 255;
                c19 = r6 >= 0;
                if (r2 >= r8) {
                    break;
                } else {
                    c20 = (unsigned)r3 > (unsigned)r5;
                    c1029 = c20;
                    if (!(c19)) {
                        r6 = -1;
                    } else {
                        c21 = r3 == r5;
                        c1029 = c21;
                        if (c20) {
                            r6 = -1;
                        } else {
                            m0 = (unsigned)(r3 * r8);
                            if (!(c21)) {
                                r6 = 1;
                                r3 = ((int)m0) + r2;
                            } else {
                                c23 = r2 > r4;
                                r6 = 1;
                                c1029 = c23;
                                if (!(c23)) {
                                    r3 = ((int)m0) + r2;
                                } else {
                                    r6 = -1;
                                }
                            }
                        }
                    }
                    r1 = LD8(r7);
                    r7 = r7 + 1;
                    r2 = r1 & 255;
                    continue;
                }
            }
        } else {
            r2 = (r1 - 48) & 255;
            c19 = r6 >= 0;
            if (r2 >= r8) {
                break;
            } else {
                c20 = (unsigned)r3 > (unsigned)r5;
                c1029 = c20;
                if (!(c19)) {
                    r6 = -1;
                } else {
                    c21 = r3 == r5;
                    c1029 = c21;
                    if (c20) {
                        r6 = -1;
                    } else {
                        m0 = (unsigned)(r3 * r8);
                        if (!(c21)) {
                            r6 = 1;
                            r3 = ((int)m0) + r2;
                        } else {
                            c23 = r2 > r4;
                            r6 = 1;
                            c1029 = c23;
                            if (!(c23)) {
                                r3 = ((int)m0) + r2;
                            } else {
                                r6 = -1;
                            }
                        }
                    }
                }
                r1 = LD8(r7);
                r7 = r7 + 1;
                r2 = r1 & 255;
            }
        }
    }
    if (r6 >= 0) {
        if (!((r9 & r9) == 0)) {
            r3 = -r3;
        }
    } else {
        r3 = -1;
        ST32(0x06089CA8, 34);
    }
    c28 = (r6 & r6) == 0;
    if (!((r11 & r11) == 0)) {
        r4 = r10;
        c1041 = c28;
        if (!(c28)) {
            r4 = r7 - 1;
            c1041 = 0;
        }
        ST32(r11, r4);
    }
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045C9C(int r4)
{
    int r0, r1, r2, r3, r7, c1, c2, c3, c6, c8, c10, c11, c13, c15, c17, c19, c21, c23, c25, c1010, c1013, c1016, c1021, c1026, c1029, c1032, c1035;
    FRAME(sp, 12);

    r3 = LD32(r4);
    r2 = LD8(r3);
    r7 = 0;
    while (1) {
        r1 = (signed char)r2;
        r0 = r1;
        c1 = r0 == 45;
        if (r0 == 32) {
            break;
        } else {
            c2 = (r1 & r1) == 0;
            if (!(c1)) {
                POLL();
                if (c2) {
                    break;
                } else {
                    ST8((sp - 12) + r7, r2);
                    r3 = r3 + 1;
                    r2 = LD8(r3);
                    r7 = r7 + 1;
                    continue;
                }
            } else {
                break;
            }
        }
    }
    r1 = LD8(r3);
    c3 = (r1 & r1) == 0;
    r3 = r3 + 1;
    c1010 = c3;
    if (c3) {
        r0 = 0;
    } else {
        ST32(r4, r3);
        r2 = LD8((sp - 11));
        r3 = LD8(sp - 12);
        r0 = r3;
        r1 = LD8((sp - 10));
        if (r0 == 106) {
            r0 = r2;
            c8 = r0 == 65;
            c1010 = c8;
            if (r0 == 97) {
                r0 = 0;
            } else {
                r0 = r1;
                c1010 = c8;
                if (!(c8)) {
                    c10 = r0 == 78;
                    c1013 = c10;
                    if (r0 == 110) {
                        r0 = 5;
                    } else {
                        r0 = 6;
                        c1013 = c10;
                        if (c10) {
                            r0 = 5;
                        }
                    }
                } else {
                    r0 = 0;
                }
            }
        } else {
            c6 = r0 == 102;
            if (!(r0 == 74)) {
                c11 = r0 == 70;
                c1016 = c11;
                if (c6) {
                    r0 = 1;
                } else {
                    r0 = r3;
                    c1016 = c11;
                    if (!(c11)) {
                        c13 = r0 == 77;
                        if (r0 == 109) {
                            r0 = r1;
                            c15 = r0 == 82;
                            c1021 = c15;
                            if (r0 == 114) {
                                r0 = 2;
                            } else {
                                r0 = 4;
                                c1021 = c15;
                                if (c15) {
                                    r0 = 2;
                                }
                            }
                        } else {
                            r0 = r3;
                            if (!(c13)) {
                                c17 = r0 == 65;
                                if (r0 == 97) {
                                    r0 = r2;
                                    c19 = r0 == 80;
                                    c1026 = c19;
                                    if (r0 == 112) {
                                        r0 = 3;
                                    } else {
                                        r0 = 7;
                                        c1026 = c19;
                                        if (c19) {
                                            r0 = 3;
                                        }
                                    }
                                } else {
                                    r0 = r3;
                                    if (!(c17)) {
                                        c21 = r0 == 83;
                                        c1029 = c21;
                                        if (r0 == 115) {
                                            r0 = 8;
                                        } else {
                                            r0 = r3;
                                            c1029 = c21;
                                            if (!(c21)) {
                                                c23 = r0 == 79;
                                                c1032 = c23;
                                                if (r0 == 111) {
                                                    r0 = 9;
                                                } else {
                                                    r0 = r3;
                                                    c1032 = c23;
                                                    if (!(c23)) {
                                                        c25 = r0 == 78;
                                                        c1035 = c25;
                                                        if (r0 == 110) {
                                                            r0 = 10;
                                                        } else {
                                                            r0 = 11;
                                                            c1035 = c25;
                                                            if (c25) {
                                                                r0 = 10;
                                                            }
                                                        }
                                                    } else {
                                                        r0 = 9;
                                                    }
                                                }
                                            } else {
                                                r0 = 8;
                                            }
                                        }
                                    } else {
                                        r0 = r2;
                                        c19 = r0 == 80;
                                        c1026 = c19;
                                        if (r0 == 112) {
                                            r0 = 3;
                                        } else {
                                            r0 = 7;
                                            c1026 = c19;
                                            if (c19) {
                                                r0 = 3;
                                            }
                                        }
                                    }
                                }
                            } else {
                                r0 = r1;
                                c15 = r0 == 82;
                                c1021 = c15;
                                if (r0 == 114) {
                                    r0 = 2;
                                } else {
                                    r0 = 4;
                                    c1021 = c15;
                                    if (c15) {
                                        r0 = 2;
                                    }
                                }
                            }
                        }
                    } else {
                        r0 = 1;
                    }
                }
            } else {
                r0 = r2;
                c8 = r0 == 65;
                c1010 = c8;
                if (r0 == 97) {
                    r0 = 0;
                } else {
                    r0 = r1;
                    c1010 = c8;
                    if (!(c8)) {
                        c10 = r0 == 78;
                        c1013 = c10;
                        if (r0 == 110) {
                            r0 = 5;
                        } else {
                            r0 = 6;
                            c1013 = c10;
                            if (c10) {
                                r0 = 5;
                            }
                        }
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
int f060416F0(int r4)
{
    int r0, r1, r2, r5, r9, r15;
    FRAME(sp, 16);

    r5 = r4;
    r1 = r5;
    r2 = LD8(r1);
    r1 = LD8((r1 + 1));
    r9 = ((r2 & 255) << 16) | (r1 & 255);
    r15 = ALLOCA(sp - 16, (((int)((unsigned)(r9 + 4) >> 2)) << 2));
    r0 = GCALL3(0x0604B358, r15, (r5 + 2), r9);
    ST8(r15 + r9, 0);
    r0 = GCALL1(0x060440E4, r15);
    SETSP((sp - 16));
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041ED8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c0, c5, c6, c15, c16, c17, c18, c24, c25, c27, c28, c32, c33, c36, c39, c41, c43, c45, c49, c51, c52, c55, c1037, c1055, c1057, c1068, c1083, c1090, c1100, c1103;
    int v36;
    int v40;
    int v44;
    int v48;
    int v52;
    int v56;
    int v60;
    int v64;
    int v68;
    int v72;
    int v76;
    int v80;
    int v84;
    int v88;

    r13 = r4;
    v88 = r5;
    v84 = r6;
    v80 = r7;
    v40 = 1;
    r0 = GCALL7(0x0607507C, v88, 0, 0, 0, v88, v84, v80);
    c0 = (r0 & r0) == 0;
    r0 = c0;
    if (!(c0)) {
        goto L06041F08;
    }
    goto L06042434;
    L06041F08:
    r0 = LD32(r13);
    v64 = r0;
    if ((r0 & r0) == 0) {
        goto L06041F18;
    }
    r1 = LD32(r13 + 16);
    v72 = r1 + 1;
    goto L06041F1C;
    L06041F18:
    v72 = 20;
    L06041F1C:
    r0 = GCALL7(0x06028380, v72, 13, 0, 0, v88, v84, v80);
    v76 = r0;
    if (!((r0 & r0) == 0)) {
        goto L06041F2E;
    }
    goto L06042432;
    L06041F2E:
    r10 = LD32(v80);
    r0 = LD32(v84);
    r12 = 0;
    v68 = r0;
    r1 = LD32(r13 + 4);
    r0 = r0 << 2;
    v36 = r0;
    r11 = LD32(r0 + r1);
    r9 = 0x0607507C;
    r0 = GCALL8(0x0607507C, r11, 0, 0, 0, v88, v84, v80, v76);
    r8 = r0;
    if (!(r10 > r8)) {
        goto L06041F50;
    }
    r10 = r8;
    L06041F50:
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r9, v88, r5, r6, r7, v88, v84, v80, v76);
    r0 = GCALL8(0x06028380, ((r0 + r8) + 1), 13, 0, 0, v88, v84, v80, v76);
    v56 = r0;
    if (!((r0 & r0) == 0)) {
        goto L06041F6C;
    }
    goto L06042432;
    L06041F6C:
    r0 = GCALL8(0x060750A0, v56, r11, r10, 0, v88, v84, v80, v76);
    ST8(v56 + r10, 0);
    r14 = 0x06075408;
    r0 = GCALL8(0x06075408, v56, v88, 0, 0, v88, v84, v80, v76);
    r0 = GCALL8(0x06075408, v56, (r11 + r10), 0, 0, v88, v84, v80, v76);
    ST8(r11, 0);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r9, v88, r5, r6, r7, v88, v84, v80, v76);
    v52 = r0 + r10;
    r2 = LD32(r13 + 12);
    r10 = 0;
    ST32(v36 + r2, 1);
    r0 = GCALL8(0x06041D58, v88, 0, 0, 0, v88, v84, v80, v76);
    c5 = (r0 & r0) == 0;
    r0 = v68;
    if (c5) {
        goto L06042012;
    }
    c6 = r0 > 0;
    r0 = r0 - 1;
    if (!(c6)) {
        goto L06042012;
    }
    v68 = r0;
    r2 = LD32(r13 + 4);
    r11 = LD32((r0 << 2) + r2);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r9, r11, r5, r6, r7, v88, v84, v80, v76);
    r8 = r0;
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r9, v56, r5, r6, r7, v88, v84, v80, v76);
    r0 = GCALL8(0x06028380, ((r0 + r8) + 1), 13, 0, 0, v88, v84, v80, v76);
    v88 = r0;
    if (!((r0 & r0) == 0)) {
        goto L06041FF0;
    }
    r0 = 0;
    goto L06042434;
    L06041FE6:
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(0x06027F48, v56, 0, 0, 0, v88, v84, v80, v76);
    r0 = 0;
    goto L06042434;
    L06041FF0:
    r0 = GCALL8(0x060750DC, v88, r11, 0, 0, v88, v84, v80, v76);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(r14, v88, v56, r6, r7, v88, v84, v80, v76);
    ST8(r11, 0);
    v52 = v52 + r8;
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(0x06027F48, v56, 0, 0, 0, v88, v84, v80, v76);
    v56 = v88;
    L06042012:
    r0 = GCALL8(0x06041DBC, v56, 0, 0, 0, v88, v84, v80, v76);
    r3 = v52 - r0;
    v52 = r3;
    if (!((r3 & r3) == 0)) {
        goto L06042030;
    }
    ST32(v84, v68);
    ST32(v80, 0);
    L06042030:
    r3 = v68;
    v48 = r12;
    v44 = r3;
    r1 = LD8(v56 + r12);
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        goto L06042044;
    }
    goto L06042354;
    L06042044:
    r14 = r3 << 2;
    r3 = v64;
    L0604204A:
    v48 = r12;
    if ((r3 & r3) == 0) {
        goto L06042058;
    }
    r1 = LD32(r13 + 16);
    r8 = r1 - r10;
    goto L06042064;
    L06042058:
    r0 = LD32(r13 + 8);
    r1 = LD32(r0 + r14);
    r8 = r1 - (r10 + 1);
    L06042064:
    r0 = v64;
    if (r8 > 0) {
        goto L060420B8;
    }
    r3 = 1;
    if ((r0 & r0) == 0) {
        goto L06042074;
    }
    v60 = r3;
    goto L0604229A;
    L06042074:
    r1 = LD32(r13 + 8);
    r8 = LD32(r14 + r1);
    r0 = GCALL8(0x0607507C, v88, 0, 0, 0, v88, v84, v80, v76);
    r8 = (r8 + 20) + r0;
    r1 = LD32(r13 + 4);
    r5 = LD32(r14 + r1);
    r7 = R(7);
    r0 = GCALL8(0x06027C18, 0, r5, r8, 0, v88, v84, v80, v76);
    r2 = r0;
    if (!((r2 & r2) == 0)) {
        goto L0604209E;
    }
    goto L06042432;
    L0604209E:
    r1 = LD32(r13 + 4);
    r0 = r14;
    ST32(r0 + r1, r2);
    r1 = LD32(r13 + 8);
    ST32(r0 + r1, r8);
    r1 = LD32(r13 + 4);
    r11 = LD32(r0 + r1);
    r0 = GCALL8(0x0607507C, r11, 0, 0, 0, v88, v84, v80, v76);
    v60 = 0;
    goto L0604229A;
    L060420B8:
    r1 = LD8(v56 + r12);
    r2 = r1 & 255;
    v60 = 0;
    r0 = r2;
    r1 = LD8(r0 + 0x06075135);
    c15 = r0 == 13;
    if (((r1 & 8) & (r1 & 8)) == 0) {
        goto L06042160;
    }
    c16 = r0 == 10;
    if (c15) {
        goto L060420DA;
    }
    r0 = r11;
    if (!(c16)) {
        goto L06042102;
    }
    L060420DA:
    v60 = 1;
    c17 = r2 == 13;
    r12 = r12 + 1;
    c1037 = c17;
    if (!(c17)) {
        goto L060420F4;
    }
    r1 = LD8(v56 + r12);
    c18 = (r1 & 255) == 10;
    c1037 = c18;
    if (!(c18)) {
        goto L060420F4;
    }
    r12 = r12 + 1;
    c1037 = 1;
    L060420F4:
    r0 = r11;
    ST8(r0 + r10, 10);
    r10 = r10 + 1;
    ST8(r0 + r10, 0);
    goto L0604210C;
    L06042102:
    r12 = r12 + 1;
    ST8(r0 + r10, r2);
    r10 = r10 + 1;
    ST8(r0 + r10, 0);
    L0604210C:
    r3 = v60;
    if (v52 == r12) {
        goto L06042118;
    }
    goto L0604229C;
    L06042118:
    r1 = v68;
    if ((r3 & r3) == 0) {
        goto L06042154;
    }
    ST32(v84, (r1 + 1));
    r0 = 0;
    ST32(v80, 0);
    goto L06042298;
    L06042154:
    ST32(v84, v68);
    ST32(v80, r10);
    c1068 = 1;
    goto L06042296;
    L06042160:
    v48 = r12;
    r0 = GCALL8(0x06041B44, (v56 + r12), v76, v72, 0, v88, v84, v80, v76);
    r12 = r12 + r0;
    r0 = GCALL8(0x0607507C, v76, 0, 0, 0, v88, v84, v80, v76);
    r9 = r0;
    r1 = LD8(((v76 + r9) - 1));
    r2 = r9;
    if ((r1 & 255) == 32) {
        goto L0604218E;
    }
    r2 = r2 + 1;
    L0604218E:
    r5 = v76;
    if (r2 > r8) {
        goto L0604219E;
    }
    r0 = GCALL8(0x06075408, r11, r5, 0, 0, v88, v84, v80, v76);
    r10 = r10 + r9;
    goto L0604225E;
    L0604219E:
    r1 = v72;
    if ((v64 & v64) == 0) {
        goto L0604221C;
    }
    c24 = r2 > (r1 - 1);
    r1 = 0;
    if (!(c24)) {
        goto L060421FE;
    }
    r0 = GCALL8(0x06075470, r11, v76, r8, 0, v88, v84, v80, v76);
    r12 = r12 - (r9 - r8);
    r10 = r10 + r8;
    ST8(r11 + r10, 0);
    c25 = (v40 & v40) == 0;
    c1057 = c25;
    if (c25) {
        goto L06042204;
    }
    r3 = v52;
    c27 = r12 >= r3;
    c1057 = c27;
    if (v48 >= r3) {
        goto L06042204;
    }
    r3 = 1;
    if (!(c27)) {
        goto L06042206;
    }
    ST32(v84, v68);
    r1 = r10 - (r12 - v52);
    r0 = v80;
    c28 = r1 >= 0;
    ST32(r0, r1);
    c1055 = c28;
    if (c28) {
        goto L060421F8;
    }
    ST32(r0, v60);
    c1055 = 0;
    L060421F8:
    v40 = 0;
    c1057 = c1055;
    goto L06042204;
    L060421FE:
    r12 = r12 - r9;
    ST8(r11 + r10, r1);
    c1057 = 0;
    L06042204:
    r3 = 1;
    L06042206:
    v60 = r3;
    goto L06042264;
    L0604221C:
    r0 = LD32(r13 + 8);
    r8 = LD32(r0 + r14);
    r0 = LD32(r13 + 4);
    r8 = (r8 + 20) + r9;
    r5 = LD32(r0 + r14);
    r7 = R(7);
    r0 = GCALL8(0x06027C18, 0, r5, r8, 0, v88, v84, v80, v76);
    r2 = r0;
    if (!((r2 & r2) == 0)) {
        goto L0604223E;
    }
    goto L06042432;
    L0604223E:
    r1 = LD32(r13 + 4);
    r0 = r14;
    ST32(r0 + r1, r2);
    r1 = LD32(r13 + 8);
    ST32(r0 + r1, r8);
    r1 = LD32(r13 + 4);
    r11 = LD32(r0 + r1);
    r0 = GCALL8(0x0607507C, r11, 0, 0, 0, v88, v84, v80, v76);
    r0 = GCALL8(0x06075470, r11, v76, r9, 0, v88, v84, v80, v76);
    r10 = r10 + r9;
    L0604225E:
    ST8(r11 + r10, 0);
    L06042264:
    if ((v40 & v40) == 0) {
        goto L0604229A;
    }
    r3 = v52;
    c32 = r12 >= r3;
    if (v48 >= r3) {
        goto L0604229A;
    }
    r3 = v60;
    if (!(c32)) {
        goto L0604229C;
    }
    ST32(v84, v68);
    r1 = r10 - (r12 - v52);
    r0 = v80;
    c33 = r1 >= 0;
    ST32(r0, r1);
    c1068 = c33;
    if (c33) {
        goto L06042296;
    }
    ST32(r0, 0);
    c1068 = 0;
    L06042296:
    r0 = 0;
    L06042298:
    v40 = r0;
    L0604229A:
    r3 = v60;
    L0604229C:
    r0 = v56;
    if ((r3 & r3) == 0) {
        goto L06042346;
    }
    r0 = v68 + 1;
    v68 = r0;
    r1 = LD32(r13 + 20);
    r14 = r14 + 4;
    if (!(r0 >= r1)) {
        goto L060422C4;
    }
    r7 = R(7);
    r0 = GCALL8(0x06041BDC, r13, (r0 + 10), 0, 0, v88, v84, v80, v76);
    c36 = (r0 & r0) == 0;
    r0 = 0;
    if (!(c36)) {
        goto L060422C4;
    }
    goto L06042434;
    L060422C4:
    r1 = LD32(r13 + 4);
    r11 = LD32(r14 + r1);
    r0 = GCALL8(0x0607507C, r11, 0, 0, 0, v88, v84, v80, v76);
    r1 = 0;
    if (!(r0 > 0)) {
        goto L0604231A;
    }
    r0 = GCALL8(0x0607507C, v56, 0, 0, 0, v88, v84, v80, v76);
    r8 = r0;
    r0 = GCALL8(0x0607507C, r11, 0, 0, 0, v88, v84, v80, v76);
    r0 = GCALL8(0x06028380, ((r8 + r0) + 1), 13, 0, 0, v88, v84, v80, v76);
    v88 = r0;
    if (!((r0 & r0) == 0)) {
        goto L060422FE;
    }
    POLL();
    goto L06041FE6;
    L060422FE:
    r0 = GCALL8(0x060750DC, v88, v56, 0, 0, v88, v84, v80, v76);
    r0 = GCALL8(0x06075408, v88, r11, 0, 0, v88, v84, v80, v76);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(0x06027F48, v56, 0, 0, 0, v88, v84, v80, v76);
    v56 = v88;
    r1 = 0;
    L0604231A:
    ST8(r11, r1);
    c39 = (v40 & v40) == 0;
    r10 = 0;
    c1083 = c39;
    if (c39) {
        goto L06042344;
    }
    r0 = v52;
    c41 = r12 >= r0;
    c1083 = c41;
    if (v48 >= r0) {
        goto L06042344;
    }
    r0 = v56;
    if (!(c41)) {
        goto L06042346;
    }
    ST32(v84, v68);
    ST32(v80, (v52 - r12));
    v40 = 0;
    c1083 = 1;
    L06042344:
    r0 = v56;
    L06042346:
    r1 = LD8(r0 + r12);
    r3 = v64;
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L06042354;
    }
    POLL();
    goto L0604204A;
    L06042354:
    c43 = (v40 & v40) == 0;
    c1090 = c43;
    if (c43) {
        goto L0604237C;
    }
    r3 = v52;
    c45 = r12 >= r3;
    c1090 = c45;
    if (v48 >= r3) {
        goto L0604237C;
    }
    r2 = v68;
    if (!(c45)) {
        goto L0604237E;
    }
    ST32(v84, v68);
    ST32(v80, (r10 - (r12 - v52)));
    c1090 = 1;
    L0604237C:
    r2 = v68;
    L0604237E:
    r8 = v44;
    if (r8 > r2) {
        goto L06042394;
    }
    r7 = 1;
    L06042386:
    r1 = LD32(r13 + 12);
    r0 = r8 << 2;
    r8 = r8 + 1;
    ST32(r0 + r1, r7);
    if (!(r8 > r2)) {
        POLL();
        goto L06042386;
    }
    L06042394:
    r1 = LD32(r13 + 20);
    r0 = v68;
    r6 = 0;
    if (r0 >= (r1 - 1)) {
        goto L06042428;
    }
    r2 = r0 << 2;
    r7 = LD32(r13 + 4);
    r1 = LD32(r2 + r7);
    r1 = LD8(r1);
    c49 = ((r1 & 255) & (r1 & 255)) == 0;
    r5 = c49;
    if (!(c49)) {
        goto L06042428;
    }
    r1 = r2;
    L060423B6:
    r1 = LD32((r1 + r7) + 4);
    r1 = LD8(r1);
    r0 = r2;
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L06042428;
    }
    r1 = LD32(r13 + 8);
    c51 = (r1 & r1) == 0;
    r7 = LD32(r0 + r7);
    c1100 = c51;
    if (c51) {
        goto L060423CE;
    }
    r6 = LD32(r0 + r1);
    c1100 = 0;
    L060423CE:
    r1 = LD32(r13 + 20);
    r8 = v68;
    goto L060423FA;
    L060423D4:
    r4 = r4 << 2;
    r2 = LD32(r13 + 4);
    r1 = LD32((r4 + r2) + 4);
    r0 = r4;
    ST32(r0 + r2, r1);
    r2 = LD32(r13 + 8);
    c52 = (r2 & r2) == 0;
    r1 = r4;
    c1103 = c52;
    if (c52) {
        goto L060423F0;
    }
    r1 = LD32((r1 + r2) + 4);
    ST32(r0 + r2, r1);
    c1103 = 0;
    L060423F0:
    r1 = LD32(r13 + 12);
    ST32(r4 + r1, r5);
    r1 = LD32(r13 + 20);
    r8 = r8 + 1;
    L060423FA:
    r4 = r8;
    if (!(r8 >= (r1 - 1))) {
        POLL();
        goto L060423D4;
    }
    r0 = LD32(r13 + 4);
    r1 = r8 << 2;
    ST32(r0 + r1, r7);
    r2 = LD32(r13 + 8);
    r0 = r1;
    if ((r2 & r2) == 0) {
        goto L06042414;
    }
    ST32(r0 + r2, r6);
    L06042414:
    r7 = LD32(r13 + 4);
    r2 = v68 << 2;
    r1 = LD32(r2 + r7);
    r1 = LD8(r1);
    c55 = ((r1 & 255) & (r1 & 255)) == 0;
    r1 = r2;
    if (c55) {
        POLL();
        goto L060423B6;
    }
    L06042428:
    r5 = R(5);
    r7 = R(7);
    r0 = GCALL8(0x06027F48, v56, r5, r6, 0, v88, v84, v80, v76);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(0x06027F48, v76, 0, 0, 0, v88, v84, v80, v76);
    L06042432:
    r0 = 0;
    L06042434:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06042D88(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c1, c3, c4, c7, c9, c11, c22, c24, c27, c31, c32, c33, c38, c41, c42, c45, c1012, c1020, c1029, c1036, c1048, c1068;
    FRAME(sp, 168);

    ST32(132 + (sp - 168), r4);
    r11 = r5;
    r10 = r6;
    ST32((128 + (sp - 168)), r7);
    r13 = LD32(128 + (sp - 168));
    r12 = 0;
    r8 = LD32(r13);
    r14 = 0x060752FC;
    r9 = r8 + r11;
    L06042DB8:
    r0 = GCALL1(0x0607507C, 0x06042D70);
    r0 = GCALL3(r14, 0x06042D70, r9, r0);
    c1 = (unsigned)r8 >= (unsigned)r10;
    c1012 = c1;
    if ((r0 & r0) == 0) {
        goto L06042E04;
    }
    c1012 = c1;
    if (c1) {
        goto L06042E04;
    }
    r1 = LD8(r9);
    r1 = r1 & 255;
    goto L06042DE0;
    L06042DD6:
    if (c4) {
        goto L06042DEC;
    }
    r9 = r9 + 1;
    r1 = LD8(r9);
    r8 = r8 + 1;
    r1 = r1 & 255;
    L06042DE0:
    r0 = r1;
    c3 = r0 == 13;
    if (r0 == 10) {
        goto L06042DEC;
    }
    c4 = (unsigned)r8 >= (unsigned)r10;
    if (!(c3)) {
        POLL();
        goto L06042DD6;
    }
    L06042DEC:
    if ((unsigned)r8 >= (unsigned)r10) {
        POLL();
        goto L06042DB8;
    }
    r1 = LD8(r9);
    r0 = r1 & 255;
    c7 = r0 == 13;
    if (r0 == 10) {
        goto L06042DFE;
    }
    if (!(c7)) {
        POLL();
        goto L06042DB8;
    }
    L06042DFE:
    r9 = r9 + 1;
    r8 = r8 + 1;
    POLL();
    goto L06042DB8;
    L06042E04:
    if (!(c1012)) {
        goto L06042E20;
    }
    r0 = -700;
    goto L0604302E;
    L06042E20:
    r14 = 0x06075135;
    L06042E22:
    r13 = 0x0607507C;
    r0 = GCALL1(0x0607507C, 0x06042D70);
    r6 = r0;
    r0 = GCALL3(0x060752FC, 0x06042D70, (r11 + r8), r6);
    c9 = (unsigned)r8 >= (unsigned)r10;
    if ((r0 & r0) == 0) {
        goto L06042E44;
    }
    c1068 = c9;
    goto L06042FD4;
    L06042E44:
    r0 = GCALL3(r13, 0x06042D70, 0, r6);
    r8 = r8 + r0;
    r1 = LD8(r11 + r8);
    r1 = LD8((r1 & 255) + r14);
    c11 = (unsigned)r8 >= (unsigned)r10;
    if (!(((r1 & 8) & (r1 & 8)) == 0)) {
        goto L06042E66;
    }
    goto L06043014;
    L06042E66:
    r2 = 0x06075135;
    c1020 = c11;
    L06042E68:
    if (c1020) {
        goto L06042E80;
    }
    r8 = r8 + 1;
    r1 = LD8(r11 + r8);
    r1 = LD8((r1 & 255) + r2);
    c1020 = (unsigned)r8 >= (unsigned)r10;
    if (!(((r1 & 8) & (r1 & 8)) == 0)) {
        POLL();
        goto L06042E68;
    }
    L06042E80:
    r0 = r11;
    if (!((unsigned)r8 >= (unsigned)r10)) {
        goto L06042E8A;
    }
    c1068 = 1;
    goto L06042FD4;
    L06042E8A:
    r3 = LD8(r0 + r8);
    r1 = r3 & 255;
    r0 = r1;
    if (r0 == 95) {
        goto L06042EA2;
    }
    r2 = LD8(r0 + r14);
    if (!(((r2 & 7) & (r2 & 7)) == 0)) {
        goto L06042EA2;
    }
    goto L0604301A;
    L06042EA2:
    r2 = 0;
    r1 = LD8(r1 + r14);
    r7 = r14;
    if (!(((r1 & 8) & (r1 & 8)) == 0)) {
        goto L06042ED8;
    }
    r1 = 126;
    c1029 = (unsigned)r8 >= (unsigned)r10;
    L06042EB6:
    r0 = sp - 168;
    if (c1029) {
        goto L06042ED8;
    }
    ST8(r0 + r2, r3);
    r8 = r8 + 1;
    r3 = LD8(r11 + r8);
    r6 = LD8((r3 & 255) + r7);
    r2 = r2 + 1;
    if (!(((r6 & 8) & (r6 & 8)) == 0)) {
        goto L06042ED8;
    }
    c1029 = (unsigned)r8 >= (unsigned)r10;
    if (!(r2 > r1)) {
        POLL();
        goto L06042EB6;
    }
    L06042ED8:
    c22 = (unsigned)r8 >= (unsigned)r10;
    ST8((sp - 168) + r2, 0);
    c1068 = c22;
    if (c22) {
        goto L06042FD4;
    }
    r1 = LD8(r11 + r8);
    r1 = LD8((r1 & 255) + r14);
    c24 = (unsigned)r8 >= (unsigned)r10;
    if (!(((r1 & 8) & (r1 & 8)) == 0)) {
        goto L06042EFA;
    }
    goto L06043020;
    L06042EFA:
    r2 = 0x06075135;
    c1036 = c24;
    L06042EFC:
    if (c1036) {
        goto L06042F14;
    }
    r8 = r8 + 1;
    r1 = LD8(r11 + r8);
    r1 = LD8((r1 & 255) + r2);
    c1036 = (unsigned)r8 >= (unsigned)r10;
    if (!(((r1 & 8) & (r1 & 8)) == 0)) {
        POLL();
        goto L06042EFC;
    }
    L06042F14:
    c27 = (unsigned)r8 >= (unsigned)r10;
    r0 = r11;
    c1068 = c27;
    if (c27) {
        goto L06042FD4;
    }
    r1 = LD8(r0 + r8);
    r0 = r1 & 255;
    r2 = LD8(r0 + r14);
    r4 = r11;
    if (!(((r2 & 4) & (r2 & 4)) == 0)) {
        goto L06042F30;
    }
    if (!(r0 == 45)) {
        goto L06043026;
    }
    L06042F30:
    r0 = GCALL1(0x06075454, (r4 + r8));
    r9 = r0;
    goto L06042F3E;
    L06042F3A:
    if (c32) {
        goto L06042F50;
    }
    r8 = r8 + 1;
    L06042F3E:
    r1 = LD8(r11 + r8);
    r0 = r1 & 255;
    c31 = r0 == 13;
    if (r0 == 10) {
        goto L06042F50;
    }
    c32 = (unsigned)r8 >= (unsigned)r10;
    if (!(c31)) {
        POLL();
        goto L06042F3A;
    }
    L06042F50:
    c33 = (unsigned)r8 >= (unsigned)r10;
    c1068 = c33;
    if (c33) {
        goto L06042FD4;
    }
    r0 = r11;
    goto L06042F60;
    L06042F5A:
    if (c1048) {
        goto L06042F72;
    }
    r8 = r8 + 1;
    r0 = r11;
    L06042F60:
    r1 = LD8(r0 + r8);
    r0 = r1 & 255;
    c1048 = (unsigned)r8 >= (unsigned)r10;
    if (r0 == 10) {
        POLL();
        goto L06042F5A;
    }
    c1048 = (unsigned)r8 >= (unsigned)r10;
    if (r0 == 13) {
        POLL();
        goto L06042F5A;
    }
    L06042F72:
    c38 = (unsigned)r8 >= (unsigned)r10;
    c1068 = c38;
    if (c38) {
        goto L06042FD4;
    }
    r0 = GCALL2(0x06042D28, (sp - 168), 0x06042D78);
    if ((r0 & r0) == 0) {
        goto L06042F9C;
    }
    r13 = LD32((132 + (sp - 168)));
    c41 = (r9 & r9) == 0;
    if ((r13 & r13) == 0) {
        goto L06042F94;
    }
    r13 = LD32(132 + (sp - 168));
    ST32(r13, r9);
    L06042F94:
    c42 = (r12 & r12) == 0;
    if (c41) {
        goto L06042F9C;
    }
    if (!(c42)) {
        goto L06042F9C;
    }
    r12 = 1;
    L06042F9C:
    r0 = GCALL2(0x06042D28, (sp - 168), 0x06042D80);
    if (!((r0 & r0) == 0)) {
        goto L06042FAC;
    }
    POLL();
    goto L06042E22;
    L06042FAC:
    r0 = LD32(132 + (sp - 168));
    c45 = (r9 & r9) == 0;
    if ((r0 & r0) == 0) {
        goto L06042FBE;
    }
    r0 = LD32((132 + (sp - 168)));
    ST32(r0 + 4, r9);
    L06042FBE:
    r0 = r12;
    if (!(c45)) {
        goto L06042FC6;
    }
    POLL();
    goto L06042E22;
    L06042FC6:
    if (r0 == 1) {
        goto L06042FCE;
    }
    POLL();
    goto L06042E22;
    L06042FCE:
    r12 = 2;
    POLL();
    goto L06042E22;
    L06042FD4:
    r0 = r12;
    if (!(c1068)) {
        goto L06042FDE;
    }
    r0 = -707;
    goto L0604302E;
    L06042FDE:
    if (!(r0 == 2)) {
        goto L0604302C;
    }
    r0 = LD32((128 + (sp - 168)));
    ST32(r0, r8);
    r0 = 0;
    goto L0604302E;
    L06043014:
    r0 = -701;
    goto L0604302E;
    L0604301A:
    r0 = -702;
    goto L0604302E;
    L06043020:
    r0 = -703;
    goto L0604302E;
    L06043026:
    r0 = -704;
    goto L0604302E;
    L0604302C:
    r0 = -705;
    L0604302E:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060447C4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, c2, c4, c5, c16, c17, c1008, c1016;
    FRAME(sp, 0);

    r0 = r6;
    r2 = LD32(sp);
    r3 = r5;
    if (r0 == 10) {
        goto L060447E0;
    }
    c2 = r0 == 8;
    c1016 = c2;
    if (r0 > 10) {
        goto L06044860;
    }
    r1 = 7;
    if (c2) {
        goto L06044842;
    }
    r0 = r4;
    goto L06044862;
    L060447E0:
    r1 = r4;
    if ((unsigned)r4 > (unsigned)9) {
        goto L060447F0;
    }
    r3 = r3 - 1;
    ST8(r3, (r1 + 48));
    return r3;
    L060447F0:
    c4 = (unsigned)r4 > (unsigned)0x7FFFFFFF;
    c1008 = c4;
    if (!(c4)) {
        goto L06044814;
    }
    r1 = LD32(0x060447C0);
    r2 = (int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r4 * (unsigned)r1)) >> 32)) >> 2);
    c5 = r2 & 1;
    r2 = (int)((unsigned)r2 >> 1);
    r3 = r3 - 1;
    ST8(r3, ((r4 - (((r2 << 2) + r2) + ((r2 << 2) + r2))) + 48));
    r4 = r2;
    c1008 = c5;
    L06044814:
    r7 = 0x66666667;
    L06044816:
    r2 = ((((int)(((long long)r4 * r7) >> 32)) >> 1) >> 1) - (((r4 << 1) - (r4 << 1)) - ((unsigned)r4 >> 31));
    r1 = (r4 - (((r2 << 2) + r2) + ((r2 << 2) + r2))) + 48;
    r4 = r2;
    r3 = r3 - 1;
    ST8(r3, r1);
    if (!((r4 & r4) == 0)) {
        POLL();
        goto L06044816;
    }
    goto L06044870;
    L06044840:
    r1 = 7;
    L06044842:
    r0 = (r1 & r4) + 48;
    r4 = (int)((unsigned)((int)((unsigned)r4 >> 2)) >> 1);
    r3 = r3 - 1;
    ST8(r3, r0);
    if (!((r4 & r4) == 0)) {
        POLL();
        goto L06044840;
    }
    c16 = r0 == 48;
    if ((r7 & r7) == 0) {
        goto L06044870;
    }
    r1 = 48;
    if (c16) {
        goto L06044870;
    }
    r3 = r3 - 1;
    ST8(r3, r1);
    goto L06044870;
    L06044860:
    r0 = r4;
    L06044862:
    r1 = LD8((r0 & 15) + r2);
    r4 = (int)((unsigned)((int)((unsigned)r4 >> 2)) >> 2);
    c17 = (r4 & r4) == 0;
    r3 = r3 - 1;
    ST8(r3, r1);
    c1016 = c17;
    if (!(c17)) {
        POLL();
        goto L06044860;
    }
    L06044870:
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060492D0(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, c2, c1014;

    r12 = r4;
    r10 = r5;
    r8 = 0;
    r13 = 0x0605ACCC;
    r11 = 0;
    L060492E8:
    r0 = GCALL0(0x0605299C);
    r9 = r10 + r8;
    r0 = GCALL3(r13, r12, r9, (0x100 - r8));
    r1 = LD32(0x060766B4);
    r3 = r0;
    if ((r1 & r1) == 0) {
        goto L06049308;
    }
    r0 = -12;
    c1014 = 0;
    goto L06049350;
    L06049308:
    c2 = (r3 & r3) == 0;
    if (r3 >= 0) {
        goto L0604931A;
    }
    r0 = -1;
    if (r3 == -502) {
        POLL();
        goto L060492E8;
    }
    goto L06049352;
    L0604931A:
    r2 = 0;
    if (c2) {
        goto L06049348;
    }
    r6 = r9;
    if (r2 >= r3) {
        goto L06049344;
    }
    r7 = r8 + r3;
    r0 = r6;
    L0604932A:
    r1 = LD8(r0 + r2);
    r2 = r2 + 1;
    if (!((r1 & 255) == 13)) {
        goto L0604933E;
    }
    ST8(r10 + r7, r11);
    r0 = r7;
    c1014 = 1;
    goto L06049350;
    L0604933E:
    r0 = r6;
    if (!(r2 >= r3)) {
        POLL();
        goto L0604932A;
    }
    L06049344:
    r8 = r8 + r3;
    POLL();
    goto L060492E8;
    L06049348:
    ST8(r10 + r8, 0);
    r0 = r8;
    c1014 = 1;
    L06049350:
    L06049352:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049AB0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c4, c5, c8, c10, c14, c16, c19, c20, c21, c23, c25, c26, c30, c32, c34, c1008, c1065, c1067, c2011, c2012, c2013, c2014;
    FRAME(sp, 576);

    r11 = R(11);
    r12 = r4;
    ST32(0x208 + (sp - 576), r6);
    ST32((0x20C + (sp - 576)), r7);
    ST32(0x210 + (sp - 576), 0);
    ST32(0x214 + (sp - 576), 0);
    r0 = LD32(0x20C + (sp - 576));
    r8 = r5;
    if ((r0 & r0) == 0) {
        goto L06049B2C;
    }
    if ((r8 & r8) == 0) {
        goto L06049B32;
    }
    r0 = GCALL1(0x0607507C, r8);
    r2 = r8;
    if ((r0 & r0) == 0) {
        goto L06049B32;
    }
    r1 = LD8(r8);
    r14 = 0;
    r1 = r1 & 255;
    goto L06049B1A;
    L06049AFE:
    if (c8) {
        goto L06049B22;
    }
    r0 = r1;
    c4 = r0 == 32;
    c1008 = c4;
    if (r0 == 44) {
        goto L06049B0E;
    }
    c5 = r0 == 38;
    c1008 = c5;
    if (c4) {
        goto L06049B0E;
    }
    c1008 = c5;
    if (!(c5)) {
        goto L06049B10;
    }
    L06049B0E:
    r14 = r14 + 1;
    L06049B10:
    r1 = LD8(r2);
    r2 = r2 + 1;
    r1 = r1 & 255;
    if (!((r14 & r14) == 0)) {
        goto L06049B1A;
    }
    r14 = r14 + 1;
    L06049B1A:
    c8 = (r1 & r1) == 0;
    if (!(r1 == 38)) {
        POLL();
        goto L06049AFE;
    }
    L06049B22:
    r1 = LD8(r2);
    c10 = (r14 & r14) == 0;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        goto L06049B30;
    }
    L06049B2C:
    r0 = -1;
    goto L06049E8C;
    L06049B30:
    if (!(c10)) {
        goto L06049B48;
    }
    L06049B32:
    r0 = -605;
    goto L06049E8C;
    L06049B48:
    r1 = LD32(r12);
    r13 = r8;
    if (r1 >= 0) {
        goto L06049B6A;
    }
    c2011 = R(11);
    SETR(11, r11);
    c2012 = R(12);
    SETR(12, r12);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL1(0x0604958C, r12);
    SETR(11, c2011);
    SETR(12, c2012);
    SETR(13, c2013);
    SETR(14, c2014);
    r2 = r0;
    ST32((0x210 + (sp - 576)), 1);
    if (r2 >= 0) {
        goto L06049B68;
    }
    goto L06049E6E;
    L06049B68:
    r13 = r8;
    L06049B6A:
    r0 = GCALL3(0x06045264, (sp - 576), 0x06049A1C, 0x0608AE24);
    r0 = GCALL1(0x0607507C, (sp - 576));
    r4 = LD32(r12);
    r0 = GCALL3(0x06049370, r4, (sp - 576), r0);
    c14 = r0 == -12;
    if (r0 >= 0) {
        goto L06049B92;
    }
    c1065 = c14;
    goto L06049E56;
    L06049B92:
    r4 = LD32(r12);
    r0 = GCALL2(0x06049548, r4, (sp - 576));
    c16 = r0 == -12;
    if (r0 == 250) {
        goto L06049BA8;
    }
    c1065 = c16;
    goto L06049E56;
    L06049BA8:
    r3 = LD32((0x214 + (sp - 576)));
    r10 = LD32((0x214 + (sp - 576)));
    if (r3 >= r14) {
        goto L06049C7A;
    }
    r9 = 0x100 + (sp - 576);
    L06049BBC:
    r2 = LD8(r13);
    r8 = 0;
    goto L06049BCE;
    L06049BC2:
    r0 = r9;
    if (c21) {
        goto L06049BE0;
    }
    ST8(r0 + r8, r2);
    r13 = r13 + 1;
    r2 = LD8(r13);
    r8 = r8 + 1;
    L06049BCE:
    r1 = r2 & 255;
    r0 = r1;
    c19 = r0 == 32;
    if (r0 == 44) {
        goto L06049BE0;
    }
    c20 = r0 == 38;
    if (c19) {
        goto L06049BE0;
    }
    c21 = (r1 & r1) == 0;
    if (!(c20)) {
        POLL();
        goto L06049BC2;
    }
    L06049BE0:
    ST8(r9 + r8, 0);
    r13 = r13 + 1;
    r0 = GCALL3(0x06045264, (sp - 576), 0x06049A30, r9);
    r0 = GCALL1(0x0607507C, (sp - 576));
    r4 = LD32(r12);
    r0 = GCALL3(0x06049370, r4, (sp - 576), r0);
    c23 = r0 == -12;
    if (r0 >= 0) {
        goto L06049C10;
    }
    c1065 = c23;
    goto L06049E56;
    L06049C10:
    r4 = LD32(r12);
    r0 = GCALL2(0x06049548, r4, (sp - 576));
    r2 = r0;
    c25 = r2 > 250;
    if (r2 == 250) {
        goto L06049C74;
    }
    c26 = r0 == -12;
    if (c25) {
        goto L06049C32;
    }
    r2 = -12;
    if (!(c26)) {
        goto L06049C2E;
    }
    goto L06049E6E;
    L06049C2E:
    goto L06049C42;
    L06049C32:
    if (!(r2 == 0x228)) {
        goto L06049C42;
    }
    ST32((0x214 + (sp - 576)), r10);
    r10 = r14;
    goto L06049C74;
    L06049C42:
    r2 = -604;
    goto L06049E6E;
    L06049C74:
    r10 = r10 + 1;
    if (!(r10 >= r14)) {
        POLL();
        goto L06049BBC;
    }
    L06049C7A:
    r0 = GCALL2(0x06045264, (sp - 576), 0x06049A40);
    r0 = GCALL1(0x0607507C, (sp - 576));
    r4 = LD32(r12);
    r0 = GCALL3(0x06049370, r4, (sp - 576), r0);
    c30 = r0 == -12;
    if (r0 >= 0) {
        goto L06049CA0;
    }
    c1065 = c30;
    goto L06049E56;
    L06049CA0:
    r4 = LD32(r12);
    r0 = GCALL2(0x06049548, r4, (sp - 576));
    c32 = r0 == -12;
    if (r0 == 0x162) {
        goto L06049CB6;
    }
    c1065 = c32;
    goto L06049E56;
    L06049CB6:
    r9 = 0x0608AE24;
    r0 = GCALL3(0x06045264, (sp - 576), 0x06049A48, 0x0608AE24);
    r0 = GCALL1(0x0607507C, (sp - 576));
    r4 = LD32(r12);
    r0 = GCALL3(0x06049370, r4, (sp - 576), r0);
    c34 = r0 == -12;
    if (r0 >= 0) {
        goto L06049CE0;
    }
    c1065 = c34;
    goto L06049E56;
    L06049CE0:
    r0 = GCALL1(0x06032D18, ((sp - 576) + 0x200));
    r0 = sp - 576;
    r7 = LD8(r0 + 0x203);
    r6 = LD8(r0 + 0x202);
    r1 = LD8(r0 + 0x205);
    ST32((sp - 580), (r1 & 255));
    r1 = LD8(0x204 + (4 + (sp - 580)));
    ST32((sp - 584), (r1 & 255));
    r1 = LD16(0x200 + (8 + (sp - 584)));
    ST32((sp - 588), (r1 & 0xFFFF));
    r0 = GCALL7(0x06045264, (sp - 576), 0x06049A58, (r6 & 255), (r7 & 255), LD32((sp - 588)), LD32((sp - 584)), LD32((sp - 580)));
    r0 = GCALL7(0x0607507C, (sp - 576), 0, 0, 0, LD32((sp - 588)), LD32((sp - 584)), LD32((sp - 580)));
    r4 = LD32(r12);
    r7 = R(7);
    r0 = GCALL7(0x06049370, r4, (sp - 576), r0, 0, LD32((sp - 588)), LD32((sp - 584)), LD32((sp - 580)));
    if (r0 >= 0) {
        goto L06049D46;
    }
    goto L06049E54;
    L06049D46:
    r0 = GCALL4(0x06045264, (sp - 576), 0x06049A70, 0x0608AD84, r9);
    r0 = GCALL1(0x0607507C, (sp - 576));
    r4 = LD32(r12);
    r0 = GCALL3(0x06049370, r4, (sp - 576), r0);
    c1065 = r0 == -12;
    if (!(r0 >= 0)) {
        goto L06049E56;
    }
    r0 = LD32(0x208 + (sp - 576));
    if (!((r0 & r0) == 0)) {
        goto L06049DC0;
    }
    r0 = GCALL2(0x06045264, (sp - 576), 0x06049A80);
    goto L06049DCC;
    L06049DC0:
    r6 = LD32(0x208 + (sp - 576));
    r0 = GCALL3(0x06045264, (sp - 576), 0x06049A98, r6);
    L06049DCC:
    r0 = GCALL1(0x0607507C, (sp - 576));
    r4 = LD32(r12);
    r0 = GCALL3(0x06049370, r4, (sp - 576), r0);
    c1065 = r0 == -12;
    if (!(r0 >= 0)) {
        goto L06049E56;
    }
    r4 = LD32((0x20C + (sp - 576)));
    r0 = GCALL1(0x0607507C, r4);
    r9 = r0;
    if (!(r9 > 0)) {
        goto L06049E22;
    }
    r10 = 0;
    r11 = 0x200;
    L06049DFA:
    r8 = r9;
    if (!(r9 > r11)) {
        goto L06049E02;
    }
    r8 = r11;
    L06049E02:
    r5 = LD32((0x20C + (sp - 576)));
    r4 = LD32(r12);
    r0 = GCALL3(0x06049370, r4, (r5 + r10), r8);
    c1065 = r0 == -12;
    if (!(r0 >= 0)) {
        goto L06049E56;
    }
    r9 = r9 - r8;
    r10 = r10 + r8;
    if (r9 > 0) {
        POLL();
        goto L06049DFA;
    }
    L06049E22:
    r0 = GCALL2(0x06045264, (sp - 576), 0x06049AA8);
    r0 = GCALL1(0x0607507C, (sp - 576));
    r4 = LD32(r12);
    r0 = GCALL3(0x06049370, r4, (sp - 576), r0);
    c1065 = r0 == -12;
    if (!(r0 >= 0)) {
        goto L06049E56;
    }
    r4 = LD32(r12);
    r0 = GCALL2(0x06049548, r4, (sp - 576));
    if (r0 == 250) {
        goto L06049E60;
    }
    L06049E54:
    c1065 = r0 == -12;
    L06049E56:
    r1 = -604;
    c1067 = c1065;
    if (!(c1065)) {
        goto L06049E5C;
    }
    r1 = -12;
    c1067 = 1;
    L06049E5C:
    r2 = r1;
    goto L06049E6E;
    L06049E60:
    r0 = LD32(0x214 + (sp - 576));
    r2 = 0;
    if ((r0 & r0) == 0) {
        goto L06049E6E;
    }
    POLL();
    goto L06049B6A;
    L06049E6E:
    r3 = LD32((0x210 + (sp - 576)));
    r4 = r12;
    if ((r3 & r3) == 0) {
        goto L06049E8A;
    }
    ST32((0x21C + (sp - 576)), r2);
    r0 = GCALL1(0x060496CC, r4);
    r2 = LD32((0x21C + (sp - 576)));
    L06049E8A:
    r0 = r2;
    L06049E8C:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A6B8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c3, c5, c10, c1019;
    FRAME(sp, 40);

    r11 = r4;
    ST32(sp - 36, r5);
    r14 = r6;
    r13 = r7;
    r10 = LD32(sp);
    r8 = 0;
    if (r11 >= 0) {
        goto L0604A6EA;
    }
    L0604A6DA:
    r0 = -1;
    goto L0604A78E;
    L0604A6DE:
    r0 = r8 + r3;
    ST8(r0 + r10, 0);
    r8 = r0;
    goto L0604A73C;
    L0604A6EA:
    r12 = 0x0605ACCC;
    L0604A6EC:
    r9 = r10 + r8;
    r7 = R(7);
    r0 = GCALL5(r12, r11, r9, (0x200 - r8), r7, LD32((sp - 36)));
    r1 = LD32(0x060766B4);
    r3 = r0;
    if (!((r1 & r1) == 0)) {
        goto L0604A78C;
    }
    c3 = (r3 & r3) == 0;
    if (r3 >= 0) {
        goto L0604A71A;
    }
    c5 = (r8 & r8) == 0;
    if (!(r3 == -502)) {
        POLL();
        goto L0604A6DA;
    }
    r0 = -1;
    if (!(c5)) {
        POLL();
        goto L0604A6EC;
    }
    goto L0604A78E;
    L0604A71A:
    r2 = 0;
    if (c3) {
        goto L0604A73C;
    }
    r7 = r9;
    if (r2 >= r3) {
        goto L0604A738;
    }
    r0 = r7;
    L0604A726:
    r1 = LD8(r0 + r2);
    r2 = r2 + 1;
    if ((r1 & 255) == 13) {
        POLL();
        goto L0604A6DE;
    }
    r0 = r7;
    if (!(r2 >= r3)) {
        POLL();
        goto L0604A726;
    }
    L0604A738:
    r8 = r8 + r3;
    POLL();
    goto L0604A6EC;
    L0604A73C:
    r1 = 0;
    if ((r8 & r8) == 0) {
        POLL();
        goto L0604A6DA;
    }
    ST8(r10 + r8, r1);
    r3 = 0x060791E0;
    ST32(0x060791E0, 0);
    r1 = LD8(r10);
    r2 = r10;
    goto L0604A764;
    L0604A752:
    r1 = LD8(r2);
    c10 = (r1 & 255) == 13;
    c1019 = c10;
    if (!(c10)) {
        goto L0604A760;
    }
    r1 = LD32(r3);
    ST32(r3, (r1 + 1));
    c1019 = 1;
    L0604A760:
    r2 = r2 + 1;
    r1 = LD8(r2);
    L0604A764:
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L0604A752;
    }
    r2 = 0x060791E0;
    r1 = LD32(0x060791E0);
    r1 = r1 - 1;
    ST32(0x060791E0, r1);
    if (r1 >= 0) {
        goto L0604A77A;
    }
    ST32(r2, 0);
    L0604A77A:
    ST32((sp - 40), r10);
    r5 = LD32(sp - 36);
    r0 = GCALL6(0x0604A4DC, r11, r5, r14, r13, LD32((sp - 40)), LD32((sp - 36)));
    goto L0604A78E;
    L0604A78C:
    r0 = -12;
    L0604A78E:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041880(int r4, int r5)
{
    int r0, r1, r2, r9, r10, r15;
    FRAME(sp, 20);

    r10 = r5;
    r2 = r4;
    r1 = LD8(r2);
    r2 = LD8((r2 + 1));
    r1 = ((r1 & 255) << 16) | (r2 & 255);
    r15 = ALLOCA(sp - 20, (((int)((unsigned)(r1 + 4) >> 2)) << 2));
    SETSP(r15);
    r0 = GCALL3(0x06041638, r4, r15, (r1 + 1));
    SETSP(r15);
    r0 = GCALL2(0x060754B8, r15, 64);
    r9 = r0;
    r1 = 0;
    if ((r9 & r9) == 0) {
        SETSP(r15);
        r0 = GCALL3(0x060750A0, (r10 + 0x124), r15, 32);
        SETSP((sp - 20));
    } else {
        ST8(r9, r1);
        SETSP(r15);
        r0 = GCALL3(0x060750A0, (r10 + 164), r15, 32);
        SETSP(r15);
        r0 = GCALL3(0x060750A0, (r10 + 0x124), (r9 + 1), 32);
        SETSP((sp - 20));
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043AC0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, c2;

    r0 = GCALL4(0x06025A0C, 6, r5, r6, r7);
    r2 = LD32(0x0608BCDC);
    r7 = 0;
    if (!((r2 & r2) == 0)) {
        r3 = r2;
        do {
            r3 = r3 + 14;
            r1 = LD8(r3);
            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                ST8(r3, r7);
                r1 = LD32(r2 + 20);
                c2 = (r1 & r1) == 0;
                r1 = r2;
                if (!(c2)) {
                    ST8((r1 + 13), r7);
                }
            }
            r2 = LD32(r2 + 32);
            r3 = r2;
        } while (AGAIN(!((r2 & r2) == 0)));
    }
    r1 = LD32(0x06000334);
    r5 = R(5);
    r6 = R(6);
    r0 = GCALL4(r1, 6, r5, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06044030(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, c2011;

    r11 = r4;
    r10 = 0x0608BD04;
    r6 = LD32(0x0608BD04);
    r5 = LD32(0x0608BD08);
    r0 = GCALL4(0x06027C18, 0, r5, ((r6 + 1) << 2), r7);
    r9 = r0;
    if ((r9 & r9) == 0) {
        r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
        c2011 = R(11);
        SETR(11, r11);
        r0 = GCALL1(0x06010DDC, 24);
        SETR(11, c2011);
        ST32(0x060766C0, 0);
    } else {
        ST32(r10 + 4, r9);
        r0 = GCALL1(0x0607507C, r11);
        r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
        r8 = r0;
        r5 = r11;
        if ((r8 & r8) == 0) {
            r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
            c2011 = R(11);
            SETR(11, r11);
            r0 = GCALL1(0x06010DDC, 24);
            SETR(11, c2011);
            ST32(0x060766C0, 0);
        } else {
            r0 = GCALL2(0x060750DC, r8, r5);
            r1 = LD32(r10);
            ST32((r1 << 2) + r9, r8);
            r1 = LD32(r10);
            ST32(r10, (r1 + 1));
            r0 = GCALL0(0x06043B20);
            if (!((r0 & r0) == 0)) {
                r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
                c2011 = R(11);
                SETR(11, r11);
                r0 = GCALL1(0x06010DDC, 24);
                SETR(11, c2011);
                ST32(0x060766C0, 0);
            } else {
                c2011 = R(11);
                SETR(11, r11);
                r0 = GCALL1(0x06010DDC, 16);
                SETR(11, c2011);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060440E4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, c2011;

    r11 = r4;
    r10 = 0x0608BCF4;
    r6 = LD32(0x0608BCF4);
    r5 = LD32(0x0608BCF8);
    r0 = GCALL4(0x06027C18, 0, r5, ((r6 + 1) << 2), r7);
    r9 = r0;
    if ((r9 & r9) == 0) {
        r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
        c2011 = R(11);
        SETR(11, r11);
        r0 = GCALL1(0x06010DDC, 24);
        SETR(11, c2011);
    } else {
        ST32(r10 + 4, r9);
        r0 = GCALL1(0x0607507C, r11);
        r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
        r8 = r0;
        r5 = r11;
        if ((r8 & r8) == 0) {
            r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
            c2011 = R(11);
            SETR(11, r11);
            r0 = GCALL1(0x06010DDC, 24);
            SETR(11, c2011);
        } else {
            r0 = GCALL2(0x060750DC, r8, r5);
            r1 = LD32(r10);
            ST32((r1 << 2) + r9, r8);
            r1 = LD32(r10);
            ST32(r10, (r1 + 1));
            r0 = GCALL0(0x06043C08);
            if (!((r0 & r0) == 0)) {
                r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
                c2011 = R(11);
                SETR(11, r11);
                r0 = GCALL1(0x06010DDC, 24);
                SETR(11, c2011);
            }
        }
    }
    ST32(0x060766C0, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060465B0(int r4, int r5)
{
    int r1, r2, r3, r7, c1002;

    r4 = r4 - 8;
    r2 = LD32(r5);
    r3 = 0;
    if (!((r2 & r2) == 0)) {
        c1002 = (unsigned)r2 >= (unsigned)r4;
        while (!(c1002)) {
            r3 = r2;
            r2 = LD32(r2);
            c1002 = (unsigned)r2 >= (unsigned)r4;
            if (!((r2 & r2) == 0)) {
                POLL();
                continue;
            } else {
                break;
            }
            POLL();
        }
    }
    if ((r3 & r3) == 0) {
        ST32(r5, r4);
    } else {
        r7 = LD32(r3 + 4);
        if (!((r3 + r7) == r4)) {
            ST32(r3, r4);
        } else {
            r1 = LD32(r4 + 4);
            ST32(r3 + 4, (r1 + r7));
            r4 = r3;
        }
    }
    r3 = LD32(r4 + 4);
    if (!((r4 + r3) == r2)) {
        ST32(r4, r2);
        return;
    } else {
        r1 = LD32(r2 + 4);
        ST32(r4 + 4, (r1 + r3));
        r1 = LD32(r2);
        ST32(r4, r1);
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046600(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, c7, c8, c1002, c1011;

    r12 = r4;
    r10 = r5;
    r11 = r6;
    r7 = r12 - 8;
    r0 = ((((int)((unsigned)((int)((unsigned)(r10 + 7) >> 2)) >> 1)) + 1) << 2) + ((((int)((unsigned)((int)((unsigned)(r10 + 7) >> 2)) >> 1)) + 1) << 2);
    r2 = LD32(r11);
    r3 = 0;
    r8 = LD32(r7 + 4);
    if (!((r2 & r2) == 0)) {
        c1002 = (unsigned)r2 >= (unsigned)r7;
        while (!(c1002)) {
            r3 = r2;
            r2 = LD32(r3);
            c1002 = (unsigned)r2 >= (unsigned)r7;
            if (!((r2 & r2) == 0)) {
                POLL();
                continue;
            } else {
                break;
            }
            POLL();
        }
    }
    r1 = 0;
    if ((r7 + r8) == r2) {
        r1 = LD32(r2 + 4);
    }
    r6 = r8 + r1;
    c7 = (r1 & r1) == 0;
    if ((unsigned)r0 > (unsigned)r6) {
        r0 = GCALL2(0x06046550, r10, r11);
        r9 = r0;
        r8 = r8 - 8;
        if (!((r9 & r9) == 0)) {
            if ((unsigned)r8 > (unsigned)r10) {
                r8 = r10;
            }
            r0 = GCALL3(0x0604B358, r9, r12, r8);
            r0 = GCALL2(0x060465B0, r12, r11);
            r0 = r9;
        } else {
            r0 = 0;
        }
    } else {
        c8 = (r3 & r3) == 0;
        if (!(c7)) {
            ST32(r7 + 4, r6);
            if (!(c8)) {
                r1 = LD32(r2);
                ST32(r3, r1);
                c1011 = 0;
            } else {
                r1 = LD32(r2);
                ST32(r11, r1);
                c1011 = 1;
            }
            r2 = LD32(r2);
        }
        r6 = r6 - r0;
        r1 = r7;
        if ((unsigned)r6 > (unsigned)16) {
            r1 = r1 + r0;
            ST32(r7 + 4, r0);
            ST32(r0 + r7, r2);
            ST32(r1 + 4, r6);
            if ((r3 & r3) == 0) {
                ST32(r11, r1);
            } else {
                ST32(r3, r1);
            }
        }
        r0 = r12;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060438A4(void)
{
    int r0, r1, r2, r4, r8, r9, c3;

    r0 = GCALL1(0x0602BA00, 0x06043890);
    r0 = LD32(0x06000330);
    r0 = GCALL1(r0, 6);
    r2 = 17;
    if (!((r0 & r0) == 0)) {
        ST8(-366, r2);
        r4 = LD32(0x0608BCDC);
        r1 = r4;
        if (!((r4 & r4) == 0)) {
            r9 = 0x060433A8;
            do {
                r1 = LD8((r1 + 9));
                r8 = LD32(r4 + 32);
                if (((r1 & 255) & (r1 & 255)) == 0) {
                    r1 = 0x2000000C + r4;
                    c3 = LD8(r1);
                    ST8(r1, (c3 | 0x80));
                    if (!(((c3 == 0) & (c3 == 0)) == 0)) {
                        r0 = GCALL1(r9, r4);
                    }
                }
                r4 = r8;
                r1 = r4;
            } while (AGAIN(!((r8 & r8) == 0)));
        }
        r1 = LD32(0x06000334);
        r0 = GCALL1(r1, 6);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046844(void)
{
    int r0;

    r0 = GCALL0(0x060466D0);
    r0 = GCALL2(0x060753DC, 0x0608CE40, 1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604688C(int r4, int r5, int r6)
{
    int r0, r8, r9, r10, r11;

    r9 = r4;
    r11 = r5;
    r10 = r6;
    r0 = GCALL0(0x060466D0);
    r6 = 140;
    if (!((((int)0xFFE00000) + r9) >= 140)) {
        r8 = 0x00300000 - r6;
    } else {
        r8 = 0x00200000;
    }
    r0 = GCALL3(0x0604B358, r8, 0x0604B4B0, r6);
    r0 = GCALL3(r8, r9, r11, r10);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0604274C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, c8, c14, c16, c1002, c1022;
    long long m0;

    r11 = r5;
    r10 = r6;
    r9 = r7;
    r5 = 0;
    r6 = 0;
    if (!(0 >= r9)) {
        m0 = (unsigned)(r6 * r10);
        c1002 = 0;
        while (1) {
            r8 = 0;
            r7 = r11 + ((int)m0);
            while (1) {
                r1 = LD8(r4);
                r4 = r4 + 1;
                r2 = r1 & 255;
                r3 = r2;
                if ((r2 & r2) == 0) {
                    r1 = LD8(r4);
                    r4 = r4 + 1;
                    r2 = r1 & 255;
                    r0 = r2;
                    r1 = 1;
                    if (r0 == 1) {
                        r5 = 1;
                    } else {
                        c8 = (r2 & r2) == 0;
                        if (r2 > r1) {
                            r3 = r2;
                            if (r0 == 2) {
                                r4 = r4 + 1;
                                r1 = LD8(r4);
                                r4 = r4 + 1;
                                r6 = r1 & 255;
                            } else {
                                r12 = 0;
                                r0 = 0;
                                if (!((unsigned)0 >= (unsigned)r3)) {
                                    do {
                                        r1 = LD8(r4);
                                        r4 = r4 + 1;
                                        r12 = r12 + 1;
                                        ST8(r7, r1);
                                        r7 = r7 + 1;
                                    } while (AGAIN(!((unsigned)r12 >= (unsigned)r3)));
                                    r0 = r12;
                                }
                                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                                    r4 = r4 + 1;
                                }
                            }
                        } else {
                            r3 = r2;
                            if (c8) {
                                r8 = 1;
                            } else {
                                r12 = 0;
                                r0 = 0;
                                if (!((unsigned)0 >= (unsigned)r3)) {
                                    do {
                                        r1 = LD8(r4);
                                        r4 = r4 + 1;
                                        r12 = r12 + 1;
                                        ST8(r7, r1);
                                        r7 = r7 + 1;
                                    } while (AGAIN(!((unsigned)r12 >= (unsigned)r3)));
                                    r0 = r12;
                                }
                                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                                    r4 = r4 + 1;
                                }
                            }
                        }
                    }
                    c1022 = (r8 & r8) == 0;
                } else {
                    r1 = LD8(r4);
                    r4 = r4 + 1;
                    r12 = 0;
                    r2 = r1 & 255;
                    if ((unsigned)0 >= (unsigned)r3) {
                        c1022 = (r8 & r8) == 0;
                    } else {
                        do {
                            ST8(r7, r2);
                            r12 = r12 + 1;
                            r7 = r7 + 1;
                        } while (AGAIN(!((unsigned)r12 >= (unsigned)r3)));
                        c1022 = (r8 & r8) == 0;
                    }
                }
                c14 = (r5 & r5) == 0;
                if (!(c1022)) {
                    break;
                } else {
                    if (c14) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
            r6 = r6 + 1;
            c16 = (r5 & r5) == 0;
            if (r6 >= r9) {
                break;
            } else {
                m0 = (unsigned)(r6 * r10);
                c1002 = c16;
                if (c16) {
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

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06042804(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c14, c19, c23, c30, c31, c34, c1004, c1018, c1028, c1047, c1051, c1054;
    FRAME(sp, 52);

    ST32(sp - 36, r5);
    ST32(sp - 32, r6);
    r1 = LD32(sp);
    r13 = r7;
    if ((r1 & r1) == 0) {
        r9 = 0;
        r11 = 0;
        if (!(0 >= r13)) {
            r14 = 1;
            r12 = 0;
            r6 = LD32(sp - 36);
            c1028 = 0;
            while (1) {
                r10 = 0;
                r8 = 0;
                r6 = r6 + r12;
                while (1) {
                    r1 = LD16(r4);
                    r4 = r4 + 2;
                    r2 = r1 & 0xFFFF;
                    c19 = (r2 & r2) == 0;
                    if ((unsigned)r2 > (unsigned)r14) {
                        r5 = r2;
                        if (!(((-256 & r2) & (-256 & r2)) == 0)) {
                            r5 = (int)((unsigned)r5 >> 8);
                            r1 = 15 & ((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 2));
                            ST32(sp - 52, r1);
                            r0 = r2 & 15;
                            ST32(sp - 48, r0);
                            ST32(sp - 44, ((r1 << 2) << 2));
                            r3 = 0;
                            ST32(sp - 40, ((r0 << 2) << 2));
                            if (!((unsigned)0 >= (unsigned)r5)) {
                                do {
                                    r8 = ~r8;
                                    r1 = 1;
                                    if ((r8 & r8) == 0) {
                                        c31 = ((r1 & r3) & (r1 & r3)) == 0;
                                        r1 = LD32(sp - 48);
                                        if (c31) {
                                            r1 = LD32(sp - 52);
                                            r2 = r1 & 0xFFFF;
                                            c1051 = 1;
                                        } else {
                                            r2 = r1 & 0xFFFF;
                                            c1051 = 0;
                                        }
                                        r1 = LD8(r6);
                                        ST8(r6, (r1 | r2));
                                        r6 = r6 + 1;
                                    } else {
                                        c30 = ((r1 & r3) & (r1 & r3)) == 0;
                                        r1 = LD32(sp - 40);
                                        c1047 = c30;
                                        if (c30) {
                                            r1 = LD32(sp - 44);
                                            c1047 = 1;
                                        }
                                        ST8(r6, (r1 & 0xFFFF));
                                    }
                                    r3 = r3 + 1;
                                } while (AGAIN(!((unsigned)r3 >= (unsigned)r5)));
                            }
                            c1054 = (r10 & r10) == 0;
                        } else {
                            r5 = r2 & 255;
                            r3 = 0;
                            c23 = (r10 & r10) == 0;
                            c1054 = c23;
                            if (!((unsigned)0 >= (unsigned)r5)) {
                                r7 = 3;
                                do {
                                    r7 = r7 & r3;
                                    if ((r7 & r7) == 0) {
                                        r1 = LD16(r4);
                                        r4 = r4 + 2;
                                        r2 = r1 & 0xFFFF;
                                        ST32(sp - 52, ((int)((unsigned)((int)((unsigned)((int)((unsigned)r2 >> 8)) >> 2)) >> 2)));
                                        ST32(sp - 48, (((int)((unsigned)r2 >> 8)) & 15));
                                        ST32(sp - 44, (((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 2)) & 15));
                                        ST32(sp - 40, (r2 & 15));
                                    }
                                    r8 = ~r8;
                                    r0 = r7;
                                    if ((r8 & r8) == 0) {
                                        r2 = LD32((r0 << 2) + (sp - 52));
                                        r1 = LD8(r6);
                                        ST8(r6, (r1 | r2));
                                        r6 = r6 + 1;
                                    } else {
                                        r1 = LD32((r0 << 2) + (sp - 52));
                                        ST8(r6, ((r1 << 2) << 2));
                                    }
                                    r3 = r3 + 1;
                                    r7 = 3;
                                } while (AGAIN(!((unsigned)r3 >= (unsigned)r5)));
                                c1054 = (r10 & r10) == 0;
                            }
                        }
                    } else {
                        if (!(c19)) {
                            r9 = r14;
                            c1054 = (r10 & r10) == 0;
                        } else {
                            r10 = 1;
                            c1054 = 1 == 0;
                        }
                    }
                    c34 = (r9 & r9) == 0;
                    if (!(c1054)) {
                        break;
                    } else {
                        if (c34) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
                r0 = LD32(sp - 32);
                r11 = r11 + 1;
                r12 = r12 + r0;
                if (r11 >= r13) {
                    break;
                } else {
                    r6 = LD32(sp - 36);
                    if (!((r9 & r9) == 0)) {
                        break;
                    } else {
                        c1028 = 1;
                    }
                }
                POLL();
            }
        }
    } else {
        r9 = 0;
        r11 = 0;
        if (!(0 >= r13)) {
            r8 = 0;
            r6 = LD32(sp - 36);
            c1004 = 0;
            while (1) {
                r10 = 0;
                r6 = r6 + r8;
                while (1) {
                    r1 = LD16(r4);
                    r4 = r4 + 2;
                    r2 = r1 & 0xFFFF;
                    r0 = r2;
                    if (!((r2 & r2) == 0)) {
                        if (!(r0 == 1)) {
                            r5 = r2;
                            if (!(((-256 & r2) & (-256 & r2)) == 0)) {
                                r5 = (int)((unsigned)r5 >> 8);
                                ST32(sp - 52, (((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 2)) & 15));
                                r3 = 0;
                                ST32(sp - 48, (r2 & 15));
                                if (!((unsigned)0 >= (unsigned)r5)) {
                                    do {
                                        r1 = LD32(((1 & r3) << 2) + (sp - 52));
                                        r3 = r3 + 1;
                                        ST8(r6, r1);
                                        r6 = r6 + 1;
                                    } while (AGAIN(!((unsigned)r3 >= (unsigned)r5)));
                                }
                                c1018 = (r10 & r10) == 0;
                            } else {
                                r5 = r2 & 255;
                                r3 = 0;
                                c1018 = (r10 & r10) == 0;
                                if (!((unsigned)0 >= (unsigned)r5)) {
                                    do {
                                        r7 = 3 & r3;
                                        r0 = r7;
                                        if ((r7 & r7) == 0) {
                                            r1 = LD16(r4);
                                            r4 = r4 + 2;
                                            r2 = r1 & 0xFFFF;
                                            ST32(sp - 52, ((int)((unsigned)((int)((unsigned)((int)((unsigned)r2 >> 8)) >> 2)) >> 2)));
                                            ST32(sp - 48, (((int)((unsigned)r2 >> 8)) & 15));
                                            ST32(sp - 44, (((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 2)) & 15));
                                            ST32(sp - 40, (r2 & 15));
                                            r0 = r7;
                                        }
                                        r1 = LD32((r0 << 2) + (sp - 52));
                                        r3 = r3 + 1;
                                        ST8(r6, r1);
                                        r6 = r6 + 1;
                                    } while (AGAIN(!((unsigned)r3 >= (unsigned)r5)));
                                    c1018 = (r10 & r10) == 0;
                                }
                            }
                        } else {
                            r9 = 1;
                            c1018 = (r10 & r10) == 0;
                        }
                    } else {
                        r10 = 1;
                        c1018 = (r10 & r10) == 0;
                    }
                    c14 = (r9 & r9) == 0;
                    if (!(c1018)) {
                        break;
                    } else {
                        if (c14) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
                r0 = LD32(sp - 32);
                r11 = r11 + 1;
                r8 = r8 + r0;
                if (!(r11 >= r13)) {
                    r6 = LD32(sp - 36);
                    if ((r9 & r9) == 0) {
                        c1004 = 1;
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
                POLL();
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043050(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c6, c8, c13, c19, c24, c26, c1017, c1029, c1031, c1039, c1048;
    int v36;
    int v40;
    int v44;

    r14 = r4;
    r12 = r5;
    r13 = r6;
    v44 = 0;
    v40 = 0;
    r1 = LD32(r14 + 12);
    r11 = r7;
    if (!((r1 & r1) == 0)) {
        goto L06043094;
    }
    r0 = GCALL6(0x06042D14, r4, 0, 0, 0, v44, v40);
    r0 = GCALL6(0x060279E0, 1, r0, -1, 1, v44, v40);
    ST32(r14 + 12, r0);
    if (!((r0 & r0) == 0)) {
        goto L06043094;
    }
    r0 = -3;
    goto L06043250;
    L06043094:
    r0 = GCALL6(0x06042D14, r14, 0, 0, 0, v44, v40);
    r4 = LD32(r14 + 12);
    r0 = GCALL6(0x0604B3F0, r4, 255, r0, 0, v44, v40);
    r0 = LD32(r11);
    ST32(r11, (r0 + 1));
    r1 = LD8(r0 + r12);
    if ((r1 & 255) == 123) {
        goto L060430CE;
    }
    L060430B6:
    r2 = LD32(r11);
    r1 = r2;
    if ((unsigned)r2 >= (unsigned)r13) {
        goto L060430CE;
    }
    ST32(r11, (r1 + 1));
    r1 = LD8(r12 + r2);
    if (!((r1 & 255) == 123)) {
        POLL();
        goto L060430B6;
    }
    L060430CE:
    r1 = LD32(r11);
    if (!((unsigned)r1 >= (unsigned)r13)) {
        goto L060430D8;
    }
    goto L0604324E;
    L060430D8:
    r7 = 0x06075135;
    L060430DA:
    r2 = LD32(r11);
    c6 = (unsigned)r2 >= (unsigned)r13;
    c1017 = c6;
    if (c6) {
        goto L06043128;
    }
    r1 = LD8(r12 + r2);
    r1 = LD8((r1 & 255) + r7);
    c8 = (unsigned)r2 >= (unsigned)r13;
    c1017 = c8;
    if (!(((r1 & 4) & (r1 & 4)) == 0)) {
        goto L06043128;
    }
    r3 = 0x06075135;
    L060430F6:
    r1 = LD8(r12 + r2);
    if (!((r1 & 255) == 125)) {
        goto L06043106;
    }
    ST32(r14 + 8, 1);
    L06043106:
    r1 = LD32(r11);
    r1 = r1 + 1;
    ST32(r11, r1);
    if ((unsigned)r1 >= (unsigned)r13) {
        goto L06043124;
    }
    r2 = r1;
    r1 = LD8(r12 + r2);
    r1 = LD8((r1 & 255) + r3);
    if (((r1 & 4) & (r1 & 4)) == 0) {
        POLL();
        goto L060430F6;
    }
    L06043124:
    r2 = LD32(r11);
    c1017 = (unsigned)r2 >= (unsigned)r13;
    L06043128:
    r0 = r12;
    if (!(c1017)) {
        goto L06043130;
    }
    goto L0604324E;
    L06043130:
    r1 = LD8(r0 + r2);
    c13 = (r1 & 255) == 48;
    r1 = r2;
    if (!(c13)) {
        goto L060431CA;
    }
    r1 = LD8(((r1 + r12) + 1));
    r1 = r1 & 255;
    r3 = LD8(r1 + r7);
    if (((r3 & 2) & (r3 & 2)) == 0) {
        goto L06043152;
    }
    r1 = r1 - 32;
    L06043152:
    r0 = r2;
    if (!(r1 == 88)) {
        goto L060431CA;
    }
    r0 = r0 + 2;
    ST32(r11, r0);
    r1 = LD8(r0 + r12);
    r0 = LD8((r1 & 255) + r7);
    r10 = 0;
    L06043166:
    if (((r0 & 68) & (r0 & 68)) == 0) {
        goto L060431D6;
    }
    r1 = LD32(r11);
    r0 = r12;
    if ((unsigned)r1 >= (unsigned)r13) {
        goto L060431D6;
    }
    r1 = LD8(r0 + r1);
    r3 = r1 & 255;
    r6 = LD8(r3 + r7);
    r1 = r10;
    if (((3 & r6) & (3 & r6)) == 0) {
        goto L060431B0;
    }
    r1 = (r1 << 2) << 2;
    c19 = ((r6 & 2) & (r6 & 2)) == 0;
    r2 = r3;
    c1029 = c19;
    if (c19) {
        goto L06043196;
    }
    r2 = r2 - 32;
    c1029 = 0;
    L06043196:
    r10 = (r1 + r2) - 55;
    c1031 = c1029;
    goto L060431BA;
    L060431B0:
    r10 = (((r1 << 2) << 2) + r3) - 48;
    c1031 = 1;
    L060431BA:
    r1 = LD32(r11);
    r0 = r1 + 1;
    ST32(r11, r0);
    r1 = LD8(r0 + r12);
    r0 = LD8((r1 & 255) + r7);
    POLL();
    goto L06043166;
    L060431CA:
    r0 = -706;
    goto L06043252;
    L060431D0:
    v44 = 0;
    goto L0604321C;
    L060431D6:
    r9 = 1;
    r8 = 0;
    r4 = r14;
    L060431DC:
    v36 = r7;
    r0 = GCALL7(0x06042D14, r4, 0, 0, 0, v44, v40, v36);
    r1 = r0;
    r0 = v40;
    r7 = v36;
    if (r0 >= r1) {
        goto L06043200;
    }
    r2 = LD32(r14 + 12);
    if (((r10 & r9) & (r10 & r9)) == 0) {
        goto L060431FA;
    }
    r1 = 4;
    c1039 = 0;
    goto L060431FC;
    L060431FA:
    r1 = -1;
    c1039 = 1;
    L060431FC:
    ST8(r0 + r2, r1);
    r0 = v40;
    L06043200:
    v40 = r0 + 1;
    r0 = v44 + 1;
    v44 = r0;
    r1 = LD32(r14);
    r8 = r8 + 1;
    if (r0 >= r1) {
        POLL();
        goto L060431D0;
    }
    r9 = r9 + r9;
    r4 = r14;
    if (!(r8 > 7)) {
        POLL();
        goto L060431DC;
    }
    L0604321C:
    r1 = LD32(r11);
    c24 = (unsigned)r1 >= (unsigned)r13;
    c1048 = c24;
    if (c24) {
        goto L06043248;
    }
    L06043222:
    r1 = LD8(r12 + r1);
    r0 = r1 & 255;
    c26 = r0 == 125;
    if (r0 == 44) {
        goto L06043244;
    }
    r0 = c26;
    if (!(c26)) {
        goto L06043236;
    }
    ST32(r14 + 8, r0);
    L06043236:
    r1 = LD32(r11);
    r0 = r1 + 1;
    r1 = r0;
    ST32(r11, r0);
    if (!((unsigned)r1 >= (unsigned)r13)) {
        POLL();
        goto L06043222;
    }
    L06043244:
    r1 = LD32(r11);
    c1048 = (unsigned)r1 >= (unsigned)r13;
    L06043248:
    if (c1048) {
        goto L0604324E;
    }
    POLL();
    goto L060430DA;
    L0604324E:
    r0 = 0;
    L06043250:
    L06043252:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06044A0C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c3, c5, c6, c11, c13, c16, c18, c20, c21, c22, c23, c24, c30, c33, c34, c40, c41, c43, c44, c45, c48, c49, c63, c74, c80, c86, c88, c1013, c1051, c1054, c1055, c1068, c1069, c1070, c1087, c1088, c1089, c1097, c1098, c1106, c1107, c1139, c1158, c1167, c1180;
    FRAME(sp, 212);

    r13 = r4;
    r12 = r5;
    ST32((156 + (sp - 204)), r6);
    ST32((152 + (sp - 204)), r7);
    r10 = sp - 204;
    r0 = GCALL3(0x0604B3F0, (sp - 204), 0, 64);
    r8 = LD32((156 + (sp - 204)));
    ST32(sp - 204, r8);
    ST32(sp - 188, 0);
    ST32((136 + (sp - 204)), (sp - 140));
    r8 = LD32((136 + (sp - 204)));
    ST32((148 + (sp - 204)), (r8 + 68));
    r11 = LD32((152 + (sp - 204)));
    r14 = 16;
    r11 = r11 - 8;
    L06044A6A:
    r1 = LD32(r10);
    ST32(r10 + 8, r1);
    r1 = LD32(r10);
    goto L06044A7E;
    L06044A72:
    r0 = LD32(r10 + 4);
    if (r0 == 37) {
        goto L06044A86;
    }
    r1 = LD32(r10);
    r1 = r1 + 1;
    ST32(r10, r1);
    L06044A7E:
    r1 = LD8(r1);
    ST32(r10 + 4, r1);
    if (!((r1 & r1) == 0)) {
        POLL();
        goto L06044A72;
    }
    L06044A86:
    r1 = LD32(r10);
    r5 = LD32(r10 + 8);
    r7 = r1 - r5;
    c3 = (unsigned)r7 >= (unsigned)r12;
    if ((r7 & r7) == 0) {
        goto L06044AC4;
    }
    r1 = r12;
    if (c3) {
        goto L06044A9A;
    }
    r1 = r7;
    L06044A9A:
    ST32((160 + (sp - 204)), r1);
    ST32((168 + (sp - 204)), r7);
    r0 = GCALL5(0x0604B358, r13, r5, r1, 0, LD32((sp - 204)));
    r1 = LD32((160 + (sp - 204)));
    r7 = LD32((168 + (sp - 204)));
    r13 = r13 + r1;
    r12 = r12 - r1;
    r1 = LD32(r10 + 16);
    ST32(r10 + 16, (r1 + r7));
    L06044AC4:
    r1 = LD32(r10 + 4);
    if (!((r1 & r1) == 0)) {
        goto L06044ACE;
    }
    goto L0604523C;
    L06044ACE:
    r1 = LD32(r10);
    ST32(r10 + 12, 0);
    ST32(r10 + 48, 0);
    ST32(r10 + 20, 0);
    ST32(r10 + 28, 0);
    ST32(r10, (r1 + 1));
    r1 = -1;
    L06044AE0:
    ST32(r10 + 24, r1);
    c1013 = 0;
    L06044AE2:
    r1 = LD32(r10);
    ST32(r10, (r1 + 1));
    r1 = LD8(r1);
    ST32(r10 + 4, r1);
    L06044AEE:
    r1 = LD32(r10 + 4);
    r1 = r1 - 32;
    c5 = (unsigned)r1 > (unsigned)88;
    r1 = r1 + r1;
    if (!(c5)) {
        goto L06044AFE;
    }
    goto L06044F58;
    L06044AFE:
    r1 = LD16(0x06044B08 + r1);
    switch (r1) {
    case 200:
        goto L06044BD0;
    case 1104:
        goto L06044F58;
    case 212:
        goto L06044BDC;
    case 220:
        goto L06044BE4;
    case 246:
        goto L06044BFE;
    case 238:
        goto L06044BF6;
    case 252:
        goto L06044C04;
    case 350:
        goto L06044C66;
    case 358:
        goto L06044C6E;
    case 444:
        goto L06044CC4;
    case 624:
        goto L06044D78;
    case 790:
        goto L06044E1E;
    case 852:
        goto L06044E5C;
    case 426:
        goto L06044CB2;
    case 450:
        goto L06044CCA;
    case 402:
        goto L06044C9A;
    case 410:
        goto L06044CA2;
    case 560:
        goto L06044D38;
    case 630:
        goto L06044D7E;
    case 692:
        goto L06044DBC;
    case 418:
        goto L06044CAA;
    case 722:
        goto L06044DDA;
    case 796:
        goto L06044E24;
    case 858:
        goto L06044E62;
    }
    L06044BD0:
    r1 = LD32(r10 + 28);
    c6 = (r1 & r1) == 0;
    r1 = 32;
    c1013 = c6;
    if (!(c6)) {
        POLL();
        goto L06044AE2;
    }
    ST32(r10 + 28, r1);
    c1013 = 1;
    POLL();
    goto L06044AE2;
    L06044BDC:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 1));
    c1013 = 0;
    POLL();
    goto L06044AE2;
    L06044BE4:
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    ST32(r10 + 20, r1);
    if (!(r1 >= 0)) {
        goto L06044BF2;
    }
    c1013 = 1;
    POLL();
    goto L06044AE2;
    L06044BF2:
    ST32(r10 + 20, (-r1));
    L06044BF6:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 4));
    c1013 = 0;
    POLL();
    goto L06044AE2;
    L06044BFE:
    ST32(r10 + 28, 43);
    c1013 = 0;
    POLL();
    goto L06044AE2;
    L06044C04:
    r2 = LD32(r10);
    ST32(r10, (r2 + 1));
    r0 = LD8(r2);
    ST32(r10 + 4, r0);
    if (!(r0 == 42)) {
        goto L06044C26;
    }
    r11 = r11 + 4;
    r7 = LD32(r11 + 4);
    ST32(r10 + 24, r7);
    if (!(r7 >= 0)) {
        goto L06044C22;
    }
    c1013 = 1;
    POLL();
    goto L06044AE2;
    L06044C22:
    r1 = -1;
    POLL();
    goto L06044AE0;
    L06044C26:
    r3 = 9;
    r7 = 0;
    if ((unsigned)(r0 - 48) > (unsigned)9) {
        goto L06044C56;
    }
    r1 = r7;
    L06044C34:
    r2 = LD32(r10 + 4);
    r7 = ((((r1 << 2) + r7) + ((r1 << 2) + r7)) - 48) + r2;
    r2 = LD32(r10);
    ST32(r10, (r2 + 1));
    r1 = LD8(r2);
    ST32(r10 + 4, r1);
    c11 = (unsigned)(r1 - 48) > (unsigned)r3;
    r1 = r7;
    if (!(c11)) {
        POLL();
        goto L06044C34;
    }
    L06044C56:
    ST32(r10 + 24, r7);
    if (!(r7 >= 0)) {
        goto L06044C60;
    }
    POLL();
    goto L06044AEE;
    L06044C60:
    ST32(r10 + 24, -1);
    POLL();
    goto L06044AEE;
    L06044C66:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 128));
    c1013 = 0;
    POLL();
    goto L06044AE2;
    L06044C6E:
    r7 = 0;
    r3 = 9;
    r1 = 0;
    L06044C74:
    r2 = LD32(r10 + 4);
    r7 = ((((r1 << 2) + r7) + ((r1 << 2) + r7)) - 48) + r2;
    r2 = LD32(r10);
    ST32(r10, (r2 + 1));
    r1 = LD8(r2);
    ST32(r10 + 4, r1);
    c13 = (unsigned)(r1 - 48) > (unsigned)r3;
    r1 = r7;
    if (!(c13)) {
        POLL();
        goto L06044C74;
    }
    ST32(r10 + 20, r7);
    POLL();
    goto L06044AEE;
    L06044C9A:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 64));
    c1013 = 0;
    POLL();
    goto L06044AE2;
    L06044CA2:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 16));
    c1013 = 0;
    POLL();
    goto L06044AE2;
    L06044CAA:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 32));
    c1013 = 0;
    POLL();
    goto L06044AE2;
    L06044CB2:
    r11 = r11 + 4;
    r9 = LD32((136 + (sp - 204)));
    ST32(r10 + 8, r9);
    r1 = LD32(r11 + 4);
    r8 = 136 + (sp - 204);
    goto L06044F70;
    L06044CC4:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 16));
    L06044CCA:
    r0 = LD32(r10 + 12);
    if (((32 & r0) & (32 & r0)) == 0) {
        goto L06044D0A;
    }
    r11 = r11 + 8;
    r1 = LD32(r11);
    r2 = LD32(r11 + 4);
    ST32(r10 + 36, r1);
    ST32(r10 + 40, r2);
    r3 = LD32(r10 + 36);
    c16 = 0;
    if (!(r3 >= 0)) {
        goto L06044CEA;
    }
    c1055 = (r3 & r3) == 0;
    goto L06044D32;
    L06044CEA:
    c18 = 0 - r2;
    r9 = c18 - c16;
    ST32((144 + (sp - 204)), r9);
    c20 = 0 - r1;
    r1 = c20 - (((unsigned)c18 != 0) | ((unsigned)c18 < (unsigned)r9));
    c21 = ((unsigned)c20 != 0) | ((unsigned)c20 < (unsigned)r1);
    ST32((140 + (sp - 204)), r1);
    r9 = 140 + (sp - 204);
    r8 = LD32(r9);
    r9 = LD32(r9 + 4);
    r1 = 45;
    ST32(r10 + 36, r8);
    ST32(r10 + 40, r9);
    c1054 = c21;
    goto L06044D30;
    L06044D0A:
    c22 = ((16 & r0) & (16 & r0)) == 0;
    r0 = r0 & 64;
    c1051 = c22;
    if (!(c22)) {
        goto L06044D20;
    }
    c23 = (r0 & r0) == 0;
    c1051 = c23;
    if (c23) {
        goto L06044D20;
    }
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    r1 = (short)r1;
    goto L06044D24;
    L06044D20:
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    L06044D24:
    c24 = r1 >= 0;
    ST32(r10 + 32, r1);
    c1055 = c24;
    if (c24) {
        goto L06044D32;
    }
    ST32(r10 + 32, (-r1));
    r1 = 45;
    c1054 = 0;
    L06044D30:
    ST32(r10 + 28, r1);
    c1055 = c1054;
    L06044D32:
    ST32(r10 + 44, 10);
    goto L06044ECE;
    L06044D38:
    r0 = LD32(r10 + 12);
    if (((32 & r0) & (32 & r0)) == 0) {
        goto L06044D56;
    }
    r1 = LD32(r10 + 16);
    r11 = r11 + 4;
    r3 = LD32(r11 + 4);
    r1 = r1;
    ST32(r3, (((r1 << 1) - (r1 << 1)) - ((unsigned)r1 >> 31)));
    ST32(r3 + 4, r1);
    POLL();
    goto L06044A6A;
    L06044D56:
    c30 = ((16 & r0) & (16 & r0)) == 0;
    r0 = r0 & 64;
    if (!(c30)) {
        goto L06044D6E;
    }
    if ((r0 & r0) == 0) {
        goto L06044D6E;
    }
    r11 = r11 + 4;
    r2 = LD32(r11 + 4);
    r1 = LD32(r10 + 16);
    ST16(r2, r1);
    POLL();
    goto L06044A6A;
    L06044D6E:
    r11 = r11 + 4;
    r2 = LD32(r11 + 4);
    r1 = LD32(r10 + 16);
    ST32(r2, r1);
    POLL();
    goto L06044A6A;
    L06044D78:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 16));
    L06044D7E:
    r0 = LD32(r10 + 12);
    if (((32 & r0) & (32 & r0)) == 0) {
        goto L06044D9A;
    }
    r11 = r11 + 8;
    r1 = LD32(r11);
    r2 = LD32(r11 + 4);
    ST32(r10 + 36, r1);
    ST32(r10 + 40, r2);
    c1070 = 0;
    goto L06044DB6;
    L06044D9A:
    c33 = ((16 & r0) & (16 & r0)) == 0;
    r0 = r0 & 64;
    c1068 = c33;
    if (!(c33)) {
        goto L06044DB0;
    }
    c34 = (r0 & r0) == 0;
    c1068 = c34;
    if (c34) {
        goto L06044DB0;
    }
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    r1 = r1 & 0xFFFF;
    c1069 = 0;
    goto L06044DB4;
    L06044DB0:
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    c1069 = c1068;
    L06044DB4:
    ST32(r10 + 32, r1);
    c1070 = c1069;
    L06044DB6:
    ST32(r10 + 44, 8);
    c1106 = c1070;
    goto L06044ECA;
    L06044DBC:
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    r2 = LD32(r10 + 12);
    ST32(r10 + 32, r1);
    ST32(r10 + 44, r14);
    ST32(r10 + 60, 0x060449DC);
    ST32(r10 + 12, ((r2 & -33) | 2));
    ST32(r10 + 4, 120);
    c1106 = 0;
    goto L06044ECA;
    L06044DDA:
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    ST32(r10 + 8, r1);
    if (!((r1 & r1) == 0)) {
        goto L06044DE8;
    }
    ST32(r10 + 8, 0x060449F0);
    L06044DE8:
    r6 = LD32(r10 + 24);
    if (!(r6 >= 0)) {
        goto L06044E14;
    }
    r4 = LD32(r10 + 8);
    r0 = GCALL5(0x060754D0, r4, 0, r6, 0, LD32((sp - 204)));
    if ((r0 & r0) == 0) {
        goto L06044E10;
    }
    r1 = LD32(r10 + 8);
    r2 = LD32(r10 + 24);
    r1 = r0 - r1;
    ST32(r10 + 56, r1);
    if (r1 > r2) {
        goto L06044E0C;
    }
    goto L06044F78;
    L06044E0C:
    ST32(r10 + 56, r2);
    goto L06044F78;
    L06044E10:
    r1 = LD32(r10 + 24);
    goto L06044F76;
    L06044E14:
    r4 = LD32(r10 + 8);
    r0 = GCALL5(0x0607507C, r4, 0, 0, 0, LD32((sp - 204)));
    ST32(r10 + 56, r0);
    goto L06044F78;
    L06044E1E:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 16));
    L06044E24:
    r0 = LD32(r10 + 12);
    if (((32 & r0) & (32 & r0)) == 0) {
        goto L06044E3A;
    }
    r11 = r11 + 8;
    r1 = LD32(r11);
    r2 = LD32(r11 + 4);
    ST32(r10 + 36, r1);
    ST32(r10 + 40, r2);
    c1089 = 0;
    goto L06044E56;
    L06044E3A:
    c40 = ((16 & r0) & (16 & r0)) == 0;
    r0 = r0 & 64;
    c1087 = c40;
    if (!(c40)) {
        goto L06044E50;
    }
    c41 = (r0 & r0) == 0;
    c1087 = c41;
    if (c41) {
        goto L06044E50;
    }
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    r1 = r1 & 0xFFFF;
    c1088 = 0;
    goto L06044E54;
    L06044E50:
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    c1088 = c1087;
    L06044E54:
    ST32(r10 + 32, r1);
    c1089 = c1088;
    L06044E56:
    ST32(r10 + 44, 10);
    c1106 = c1089;
    goto L06044ECA;
    L06044E5C:
    ST32(r10 + 60, 0x060449F8);
    goto L06044E66;
    L06044E62:
    ST32(r10 + 60, 0x060449DC);
    L06044E66:
    r0 = LD32(r10 + 12);
    if (((32 & r0) & (32 & r0)) == 0) {
        goto L06044E7C;
    }
    r11 = r11 + 8;
    r1 = LD32(r11);
    r2 = LD32(r11 + 4);
    ST32(r10 + 36, r1);
    ST32(r10 + 40, r2);
    goto L06044E98;
    L06044E7C:
    c43 = ((16 & r0) & (16 & r0)) == 0;
    r0 = r0 & 64;
    c1097 = c43;
    if (!(c43)) {
        goto L06044E92;
    }
    c44 = (r0 & r0) == 0;
    c1097 = c44;
    if (c44) {
        goto L06044E92;
    }
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    r1 = r1 & 0xFFFF;
    c1098 = 0;
    goto L06044E96;
    L06044E92:
    r11 = r11 + 4;
    r1 = LD32(r11 + 4);
    c1098 = c1097;
    L06044E96:
    ST32(r10 + 32, r1);
    L06044E98:
    ST32(r10 + 44, r14);
    r0 = LD32(r10 + 12);
    c45 = ((1 & r0) & (1 & r0)) == 0;
    r0 = r0 & 32;
    c1106 = c45;
    if (c45) {
        goto L06044ECA;
    }
    if ((r0 & r0) == 0) {
        goto L06044EBC;
    }
    r1 = LD32(r10 + 36);
    if (!((r1 & r1) == 0)) {
        goto L06044EC4;
    }
    r1 = LD32(r10 + 40);
    c48 = (r1 & r1) == 0;
    r1 = 0;
    if (!(c48)) {
        goto L06044EC4;
    }
    c1107 = 1;
    goto L06044ECC;
    L06044EBC:
    r1 = LD32(r10 + 32);
    c49 = (r1 & r1) == 0;
    r1 = 0;
    c1107 = c49;
    if (c49) {
        goto L06044ECC;
    }
    L06044EC4:
    r0 = LD32(r10 + 12);
    ST32(r10 + 12, (r0 | 2));
    c1106 = 0;
    L06044ECA:
    r1 = 0;
    c1107 = c1106;
    L06044ECC:
    ST32(r10 + 28, r1);
    L06044ECE:
    r1 = LD32(r10 + 24);
    ST32(r10 + 48, r1);
    if (!(r1 >= 0)) {
        goto L06044EDE;
    }
    r1 = LD32(r10 + 12);
    ST32(r10 + 12, (r1 & -129));
    L06044EDE:
    r8 = LD32((148 + (sp - 204)));
    r0 = LD32(r10 + 12);
    ST32(r10 + 8, r8);
    if (((32 & r0) & (32 & r0)) == 0) {
        goto L06044F20;
    }
    r1 = LD32(r10 + 36);
    if (!((r1 & r1) == 0)) {
        goto L06044F02;
    }
    r1 = LD32(r10 + 40);
    if (!((r1 & r1) == 0)) {
        goto L06044F02;
    }
    r1 = LD32(r10 + 24);
    if ((r1 & r1) == 0) {
        goto L06044F46;
    }
    L06044F02:
    r7 = LD32(r10 + 44);
    r6 = LD32(r10 + 8);
    r1 = LD32(r10 + 60);
    r4 = LD32(r10 + 36);
    r5 = LD32(r10 + 40);
    ST32((sp - 208), r1);
    r0 = LD32(r10 + 12);
    ST32((sp - 212), (r0 & 1));
    r0 = GCALL7(0x06044880, r4, r5, r6, r7, LD32((sp - 212)), LD32((sp - 208)), LD32((sp - 204)));
    ST32(r10 + 8, r0);
    goto L06044F46;
    L06044F20:
    r4 = LD32(r10 + 32);
    r2 = 1;
    if (!((r4 & r4) == 0)) {
        goto L06044F2E;
    }
    r1 = LD32(r10 + 24);
    if ((r1 & r1) == 0) {
        goto L06044F46;
    }
    L06044F2E:
    r6 = LD32(r10 + 44);
    r1 = LD32(r10 + 60);
    ST32((sp - 208), r1);
    r5 = LD32((152 + (sp - 208)));
    r0 = GCALL6(0x060447C4, r4, r5, r6, (r2 & r0), LD32((sp - 208)), LD32((sp - 204)));
    ST32(r10 + 8, r0);
    L06044F46:
    r1 = LD32(r10 + 8);
    r8 = LD32((136 + (sp - 204)));
    ST32(r10 + 56, (r8 - (r1 - 68)));
    goto L06044F7C;
    L06044F58:
    r1 = LD32(r10 + 4);
    r0 = LD32(sp - 188);
    if (!((r1 & r1) == 0)) {
        goto L06044F64;
    }
    goto L0604523E;
    L06044F64:
    r9 = LD32((136 + (sp - 204)));
    r8 = 136 + (sp - 204);
    ST32(r10 + 8, r9);
    L06044F70:
    r9 = LD32(r8);
    ST8(r9, r1);
    r1 = 1;
    L06044F76:
    ST32(r10 + 56, r1);
    L06044F78:
    ST32(r10 + 28, 0);
    L06044F7C:
    r2 = LD32(r10 + 48);
    r1 = LD32(r10 + 56);
    if (r2 >= r1) {
        goto L06044F86;
    }
    r2 = r1;
    L06044F86:
    r1 = LD32(r10 + 28);
    ST32(r10 + 52, r2);
    if ((r1 & r1) == 0) {
        goto L06044FB8;
    }
    r1 = r2 + 1;
    goto L06044FC4;
    L06044FB8:
    r0 = LD32(r10 + 12);
    r1 = r2;
    if (((r0 & 2) & (r0 & 2)) == 0) {
        goto L06044FC6;
    }
    r1 = r1 + 2;
    L06044FC4:
    ST32(r10 + 52, r1);
    L06044FC6:
    r0 = LD32(r10 + 12);
    if (!(((r0 & 132) & (r0 & 132)) == 0)) {
        goto L06045036;
    }
    r2 = LD32(r10 + 20);
    r1 = LD32(r10 + 52);
    r1 = r2 - r1;
    c63 = r1 > r14;
    if (!(r1 > 0)) {
        goto L06045036;
    }
    c1139 = (unsigned)r1 >= (unsigned)r12;
    if (!(c63)) {
        goto L06045016;
    }
    L06044FE0:
    r2 = r14;
    if ((unsigned)r12 > (unsigned)r14) {
        goto L06044FE8;
    }
    r2 = r12;
    L06044FE8:
    ST32((160 + (sp - 204)), r1);
    ST32((164 + (sp - 204)), r2);
    r0 = GCALL5(0x0604B358, r13, 0x060449BC, r2, 0, LD32((sp - 204)));
    r2 = LD32((164 + (sp - 204)));
    r1 = LD32((160 + (sp - 204)));
    r13 = r13 + r2;
    r1 = r1 - 16;
    r12 = r12 - r2;
    if (r1 > r14) {
        POLL();
        goto L06044FE0;
    }
    c1139 = (unsigned)r1 >= (unsigned)r12;
    L06045016:
    r2 = r12;
    if (c1139) {
        goto L0604501C;
    }
    r2 = r1;
    L0604501C:
    ST32((164 + (sp - 204)), r2);
    r0 = GCALL5(0x0604B358, r13, 0x060449BC, r2, 0, LD32((sp - 204)));
    r2 = LD32((164 + (sp - 204)));
    r13 = r13 + r2;
    r12 = r12 - r2;
    L06045036:
    r1 = LD32(r10 + 28);
    r5 = sp - 204;
    if ((r1 & r1) == 0) {
        goto L06045070;
    }
    ST8(132 + (sp - 204), r1);
    r1 = 1;
    r5 = r5 + 132;
    if ((unsigned)r12 > (unsigned)1) {
        goto L0604504C;
    }
    r1 = r12;
    L0604504C:
    ST32((160 + (sp - 204)), r1);
    r0 = GCALL5(0x0604B358, r13, r5, r1, 0, LD32((sp - 204)));
    r1 = LD32((160 + (sp - 204)));
    goto L060450A4;
    L06045070:
    r0 = LD32(r10 + 12);
    r1 = 48;
    if (((r0 & 2) & (r0 & 2)) == 0) {
        goto L060450A8;
    }
    r5 = r5 + 132;
    ST8(132 + (sp - 204), r1);
    r1 = LD32(r10 + 4);
    ST8((r5 + 1), r1);
    r1 = 2;
    if ((unsigned)r12 > (unsigned)2) {
        goto L06045090;
    }
    r1 = r12;
    L06045090:
    ST32((160 + (sp - 204)), r1);
    r0 = GCALL5(0x0604B358, r13, r5, r1, 0, LD32((sp - 204)));
    r1 = LD32((160 + (sp - 204)));
    L060450A4:
    r13 = r13 + r1;
    r12 = r12 - r1;
    L060450A8:
    r0 = LD32(r10 + 12);
    if (!((r0 & 132) == 128)) {
        goto L0604511A;
    }
    r2 = LD32(r10 + 20);
    r1 = LD32(r10 + 52);
    r1 = r2 - r1;
    c74 = r1 > r14;
    if (!(r1 > 0)) {
        goto L0604511A;
    }
    c1158 = (unsigned)r1 >= (unsigned)r12;
    if (!(c74)) {
        goto L060450FA;
    }
    L060450C4:
    r2 = r14;
    if ((unsigned)r12 > (unsigned)r14) {
        goto L060450CC;
    }
    r2 = r12;
    L060450CC:
    ST32((160 + (sp - 204)), r1);
    ST32((164 + (sp - 204)), r2);
    r0 = GCALL5(0x0604B358, r13, 0x060449CC, r2, 0, LD32((sp - 204)));
    r2 = LD32((164 + (sp - 204)));
    r1 = LD32((160 + (sp - 204)));
    r13 = r13 + r2;
    r1 = r1 - 16;
    r12 = r12 - r2;
    if (r1 > r14) {
        POLL();
        goto L060450C4;
    }
    c1158 = (unsigned)r1 >= (unsigned)r12;
    L060450FA:
    r2 = r12;
    if (c1158) {
        goto L06045100;
    }
    r2 = r1;
    L06045100:
    ST32((164 + (sp - 204)), r2);
    r0 = GCALL5(0x0604B358, r13, 0x060449CC, r2, 0, LD32((sp - 204)));
    r2 = LD32((164 + (sp - 204)));
    r13 = r13 + r2;
    r12 = r12 - r2;
    L0604511A:
    r2 = LD32(r10 + 48);
    r1 = LD32(r10 + 56);
    r1 = r2 - r1;
    c80 = r1 > r14;
    if (!(r1 > 0)) {
        goto L06045182;
    }
    c1167 = (unsigned)r1 >= (unsigned)r12;
    if (!(c80)) {
        goto L06045162;
    }
    L0604512C:
    r2 = r14;
    if ((unsigned)r12 > (unsigned)r14) {
        goto L06045134;
    }
    r2 = r12;
    L06045134:
    ST32((160 + (sp - 204)), r1);
    ST32((164 + (sp - 204)), r2);
    r0 = GCALL5(0x0604B358, r13, 0x060449CC, r2, 0, LD32((sp - 204)));
    r2 = LD32((164 + (sp - 204)));
    r1 = LD32((160 + (sp - 204)));
    r13 = r13 + r2;
    r1 = r1 - 16;
    r12 = r12 - r2;
    if (r1 > r14) {
        POLL();
        goto L0604512C;
    }
    c1167 = (unsigned)r1 >= (unsigned)r12;
    L06045162:
    r2 = r12;
    if (c1167) {
        goto L06045168;
    }
    r2 = r1;
    L06045168:
    ST32((164 + (sp - 204)), r2);
    r0 = GCALL5(0x0604B358, r13, 0x060449CC, r2, 0, LD32((sp - 204)));
    r2 = LD32((164 + (sp - 204)));
    r13 = r13 + r2;
    r12 = r12 - r2;
    L06045182:
    r1 = LD32(r10 + 56);
    r2 = r12;
    if ((unsigned)r1 >= (unsigned)r12) {
        goto L0604518C;
    }
    r2 = r1;
    L0604518C:
    r5 = LD32(r10 + 8);
    ST32((164 + (sp - 204)), r2);
    r0 = GCALL5(0x0604B358, r13, r5, r2, 0, LD32((sp - 204)));
    r2 = LD32((164 + (sp - 204)));
    r0 = LD32(r10 + 12);
    r13 = r13 + r2;
    r12 = r12 - r2;
    c86 = ((r0 & 4) & (r0 & 4)) == 0;
    if (c86) {
        goto L0604522A;
    }
    r2 = LD32(r10 + 20);
    r1 = LD32(r10 + 52);
    r1 = r2 - r1;
    c88 = r1 > r14;
    if (!(r1 > 0)) {
        goto L0604522A;
    }
    c1180 = (unsigned)r1 >= (unsigned)r12;
    if (!(c88)) {
        goto L0604520A;
    }
    L060451D4:
    r2 = r14;
    if ((unsigned)r12 > (unsigned)r14) {
        goto L060451DC;
    }
    r2 = r12;
    L060451DC:
    ST32((160 + (sp - 204)), r1);
    ST32((164 + (sp - 204)), r2);
    r0 = GCALL5(0x0604B358, r13, 0x060449BC, r2, 0, LD32((sp - 204)));
    r2 = LD32((164 + (sp - 204)));
    r1 = LD32((160 + (sp - 204)));
    r13 = r13 + r2;
    r1 = r1 - 16;
    r12 = r12 - r2;
    if (r1 > r14) {
        POLL();
        goto L060451D4;
    }
    c1180 = (unsigned)r1 >= (unsigned)r12;
    L0604520A:
    r2 = r12;
    if (c1180) {
        goto L06045210;
    }
    r2 = r1;
    L06045210:
    ST32((164 + (sp - 204)), r2);
    r0 = GCALL5(0x0604B358, r13, 0x060449BC, r2, 0, LD32((sp - 204)));
    r2 = LD32((164 + (sp - 204)));
    r13 = r13 + r2;
    r12 = r12 - r2;
    L0604522A:
    r2 = LD32(r10 + 20);
    r1 = LD32(r10 + 52);
    if (r2 >= r1) {
        goto L06045234;
    }
    r2 = r1;
    L06045234:
    r1 = LD32(r10 + 16);
    ST32(r10 + 16, (r1 + r2));
    POLL();
    goto L06044A6A;
    L0604523C:
    r0 = LD32(sp - 188);
    L0604523E:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060452E0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, c3, c10, c21, c22, c23, c25, c28, c30, c1007, c1013, c1017, c1026, c1032, c1040, c1046;
    long long m0;

    r11 = r4;
    r12 = r5;
    r9 = r6;
    r6 = r11;
    r10 = 0;
    r2 = 0x06075135;
    do {
        r1 = LD8(r6);
        r6 = r6 + 1;
        r3 = r1 & 255;
        r1 = LD8(r3 + r2);
        r0 = r3;
    } while (AGAIN(!(((r1 & 8) & (r1 & 8)) == 0)));
    if (!(r0 == 45)) {
        c3 = (r9 & r9) == 0;
        c1007 = c3;
        if (r0 == 43) {
            r1 = LD8(r6);
            r6 = r6 + 1;
            r3 = r1 & 255;
            c1007 = (r9 & r9) == 0;
        }
    } else {
        r1 = LD8(r6);
        r6 = r6 + 1;
        r10 = 1;
        r3 = r1 & 255;
        c1007 = (r9 & r9) == 0;
    }
    r0 = r9;
    if (c1007) {
        c1013 = (r9 & r9) == 0;
        if (r3 == 48) {
            r1 = LD8(r6);
            r0 = r1;
            c10 = r0 == 88;
            if (r0 == 120) {
                r1 = LD8((r6 + 1));
                r6 = r6 + 2;
                r9 = 16;
                r3 = r1 & 255;
                c1013 = 16 == 0;
            } else {
                c1013 = (r9 & r9) == 0;
                if (c10) {
                    r1 = LD8((r6 + 1));
                    r6 = r6 + 2;
                    r9 = 16;
                    r3 = r1 & 255;
                    c1013 = 16 == 0;
                }
            }
        }
    } else {
        c1013 = (r9 & r9) == 0;
        if (r0 == 16) {
            c1013 = (r9 & r9) == 0;
            if (r3 == 48) {
                r1 = LD8(r6);
                r0 = r1;
                c10 = r0 == 88;
                if (r0 == 120) {
                    r1 = LD8((r6 + 1));
                    r6 = r6 + 2;
                    r9 = 16;
                    r3 = r1 & 255;
                    c1013 = 16 == 0;
                } else {
                    c1013 = (r9 & r9) == 0;
                    if (c10) {
                        r1 = LD8((r6 + 1));
                        r6 = r6 + 2;
                        r9 = 16;
                        r3 = r1 & 255;
                        c1013 = 16 == 0;
                    }
                }
            }
        }
    }
    c1017 = (r10 & r10) == 0;
    if (c1013) {
        r9 = 10;
        if (r3 == 48) {
            r9 = 8;
        }
        c1017 = (r10 & r10) == 0;
    }
    r8 = 0x7FFFFFFF;
    r4 = 0x7FFFFFFF;
    if (!(c1017)) {
        r8 = (int)0x80000000;
        r4 = r8;
    }
    r5 = r9;
    r0 = GCALL2(0x060745A0, r4, r5);
    r7 = 0;
    r2 = r8 - (r0 * r9);
    r0 = GCALL2(0x060745A0, r8, r5);
    r8 = r0;
    r5 = 0;
    while (!((unsigned)r3 > (unsigned)127)) {
        POLL();
        r4 = LD8(r3 + 0x06075135);
        r1 = r3;
        if (((4 & r4) & (4 & r4)) == 0) {
            r0 = r4;
            if (((3 & r4) & (3 & r4)) == 0) {
                break;
            } else {
                r1 = r3;
                if (((r0 & 1) & (r0 & 1)) == 0) {
                    r1 = r1 - 87;
                    c1026 = 1;
                } else {
                    r1 = r1 - 55;
                    c1026 = 0;
                }
                r3 = r1 & 255;
                c21 = r5 >= 0;
                if (r3 >= r9) {
                    break;
                } else {
                    c22 = (unsigned)r7 > (unsigned)r8;
                    c1032 = c22;
                    if (!(c21)) {
                        r5 = -1;
                    } else {
                        c23 = r7 == r8;
                        c1032 = c23;
                        if (c22) {
                            r5 = -1;
                        } else {
                            m0 = (unsigned)(r7 * r9);
                            if (!(c23)) {
                                r5 = 1;
                                r7 = ((int)m0) + r3;
                            } else {
                                c25 = r3 > r2;
                                r5 = 1;
                                c1032 = c25;
                                if (!(c25)) {
                                    r7 = ((int)m0) + r3;
                                } else {
                                    r5 = -1;
                                }
                            }
                        }
                    }
                    r1 = LD8(r6);
                    r6 = r6 + 1;
                    r3 = r1 & 255;
                    continue;
                }
            }
        } else {
            r3 = (r1 - 48) & 255;
            c21 = r5 >= 0;
            if (r3 >= r9) {
                break;
            } else {
                c22 = (unsigned)r7 > (unsigned)r8;
                c1032 = c22;
                if (!(c21)) {
                    r5 = -1;
                } else {
                    c23 = r7 == r8;
                    c1032 = c23;
                    if (c22) {
                        r5 = -1;
                    } else {
                        m0 = (unsigned)(r7 * r9);
                        if (!(c23)) {
                            r5 = 1;
                            r7 = ((int)m0) + r3;
                        } else {
                            c25 = r3 > r2;
                            r5 = 1;
                            c1032 = c25;
                            if (!(c25)) {
                                r7 = ((int)m0) + r3;
                            } else {
                                r5 = -1;
                            }
                        }
                    }
                }
                r1 = LD8(r6);
                r6 = r6 + 1;
                r3 = r1 & 255;
            }
        }
    }
    c28 = (r10 & r10) == 0;
    if (r5 >= 0) {
        if (!(c28)) {
            r7 = -r7;
        }
    } else {
        r7 = 0x7FFFFFFF;
        c1040 = c28;
        if (!(c28)) {
            r7 = (int)0x80000000;
            c1040 = 0;
        }
        ST32(0x06089CA8, 34);
    }
    c30 = (r5 & r5) == 0;
    if (!((r12 & r12) == 0)) {
        r4 = r11;
        c1046 = c30;
        if (!(c30)) {
            r4 = r6 - 1;
            c1046 = 0;
        }
        ST32(r12, r4);
    }
    return r7;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060474B0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, c3, c9, c10, c12, c16;
    FRAME(sp, 152);

    r0 = R(0);
    r8 = r4;
    r10 = 0;
    r0 = GCALL3(0x0604B3F0, (sp - 152), 0, 136);
    r5 = LD32(r8 + 52);
    r4 = LD32(r8);
    r0 = GCALL4(0x0605AF90, r4, r5, 0x1FE4, r7);
    c3 = r0 >= 0;
    if (!(r0 == -502)) {
        if (c3) {
            r3 = LD32(r8 + 52);
            r1 = LD16((r3 + 8));
            ST16(sp - 152, r1);
            r2 = LD16((r3 + 10));
            r1 = (sp - 152) + 2;
            ST16(r1, r2);
            r2 = LD16((r3 + 12));
            r1 = r1 + 2;
            ST16(r1, r2);
            r2 = LD16((r3 + 14));
            r1 = r1 + 2;
            ST16(r1, r2);
            r2 = LD16((r3 + 16));
            r1 = r1 + 2;
            ST16(r1, r2);
            r2 = LD16((r3 + 18));
            r1 = r1 + 2;
            ST16(r1, r2);
            r2 = LD16((r3 + 20));
            r1 = r1 + 2;
            ST16(r1, r2);
            r2 = LD16((r3 + 22));
            ST16((r1 + 2), r2);
            r2 = LD16((sp - 138));
            r1 = LD32(r8 + 20);
            if (r1 == r2) {
                r0 = LD8((sp - 140));
                c9 = r0 == 82;
                if (!(r0 == 78)) {
                    c10 = r0 == 83;
                    if (!(c9)) {
                        r1 = 1;
                        if (!(c10)) {
                            ST32(r8 + 4, r1);
                        } else {
                            r4 = LD32(r8);
                            r7 = R(7);
                            r0 = GCALL5(0x0605B208, r4, 0, 0, 0, LD32((sp - 152)));
                            r4 = LD32(r8 + 52);
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 152)));
                            ST32(r8 + 52, r10);
                            r9 = -1;
                            ST32(r8, -1);
                            r0 = GCALL5(0x06046E64, r8, 0, 0, 0, LD32((sp - 152)));
                            c12 = r0 > -900;
                            if (r0 == -900) {
                                r4 = LD32(r8);
                                r1 = -1;
                                if (r4 >= 0) {
                                    r7 = R(7);
                                    r0 = GCALL5(0x0605B208, r4, 0, 0, 0, LD32((sp - 152)));
                                    r1 = -1;
                                }
                                ST32(r8, r1);
                                r1 = 1;
                                ST32(0x06075990, 1);
                                ST32(r8 + 4, r1);
                            } else {
                                if (c12) {
                                    c16 = (r0 & r0) == 0;
                                    if (r0 == -506) {
                                        r4 = LD32(r8);
                                        r1 = -1;
                                        if (r4 >= 0) {
                                            r7 = R(7);
                                            r0 = GCALL5(0x0605B208, r4, 0, 0, 0, LD32((sp - 152)));
                                            r1 = -1;
                                        }
                                        ST32(r8, r1);
                                        r1 = 1;
                                        ST32(0x06075990, 1);
                                        ST32(r8 + 4, r1);
                                    } else {
                                        r1 = 1;
                                        if (!(c16)) {
                                            ST32(r8 + 4, r1);
                                        } else {
                                            ST32(0x06075990, r10);
                                            ST32(r8 + 12, r10);
                                            r5 = LD32(r8 + 48);
                                            r7 = R(7);
                                            r0 = GCALL5(0x060473B4, r8, r5, 1, 0, LD32((sp - 152)));
                                        }
                                    }
                                } else {
                                    r1 = 1;
                                    if (!(r0 == -902)) {
                                        r1 = 1;
                                        if (r0 == -901) {
                                            ST32(0x06075990, r9);
                                            r1 = 1;
                                        }
                                    }
                                    ST32(r8 + 4, r1);
                                }
                            }
                        }
                    } else {
                        ST32(r8 + 4, -905);
                    }
                } else {
                    ST32(r8 + 4, -903);
                }
            }
        }
    } else {
        r3 = 0x0608B980;
        r1 = LD32(0x0608B980);
        r2 = LD32(r8 + 8);
        r1 = r1 - r2;
        r2 = LD32(0x060474B0);
        r1 = (int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)(r1 + 5) * (unsigned)r2)) >> 32)) >> 2)) >> 1);
        r2 = 5;
        if (r1 > 5) {
            r1 = LD32(r3);
            ST32(r8 + 8, r1);
            r1 = LD32(r8 + 12);
            r1 = r1 + 1;
            ST32(r8 + 12, r1);
            if (r1 > r2) {
                ST32(r8 + 4, 1);
            } else {
                r5 = LD32(r8 + 48);
                r7 = R(7);
                r0 = GCALL5(0x060473B4, r8, r5, 1, 0, LD32((sp - 152)));
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604B358(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;

    r3 = r4;
    if (r6 == 0) {
        goto L0604B3EC;
    }
    if (!(r6 > 12)) {
        goto L0604B3E2;
    }
    r0 = ((-r5) + 4) & 3;
    if ((r0 & r0) == 0) {
        goto L0604B380;
    }
    r1 = r0;
    L0604B374:
    r0 = LD8(r5);
    r5 = r5 + 1;
    r1 = r1 - 1;
    ST8(r4, r0);
    r6 = r6 - 1;
    r4 = r4 + 1;
    if (!(r1 == 0)) {
        POLL();
        goto L0604B374;
    }
    L0604B380:
    r2 = (int)((unsigned)r6 >> 2);
    if ((r2 & r2) == 0) {
        goto L0604B3D6;
    }
    r1 = LD8(0x0604B398 + (r4 & 3));
    switch (r1) {
    case 4:
        goto L0604B39C;
    case 40:
        goto L0604B3C0;
    case 20:
        goto L0604B3AC;
    }
    L0604B39C:
    r0 = LD32(r5);
    r5 = r5 + 4;
    r2 = r2 - 1;
    ST32(r4, r0);
    r4 = r4 + 4;
    if (!(r2 == 0)) {
        POLL();
        goto L0604B39C;
    }
    goto L0604B3D6;
    L0604B3AC:
    r0 = LD32(r5);
    r5 = r5 + 4;
    r2 = r2 - 1;
    ST16(r4 + 2, r0);
    ST16(r4, ((int)((unsigned)r0 >> 16)));
    r4 = r4 + 4;
    if (!(r2 == 0)) {
        POLL();
        goto L0604B3AC;
    }
    goto L0604B3D6;
    L0604B3C0:
    r0 = LD32(r5);
    r5 = r5 + 4;
    r2 = r2 - 1;
    ST8(r4 + 3, r0);
    r0 = (int)((unsigned)r0 >> 8);
    ST16((r4 + 1), r0);
    ST8(r4, ((int)((unsigned)r0 >> 16)));
    r4 = r4 + 4;
    if (!(r2 == 0)) {
        POLL();
        goto L0604B3C0;
    }
    L0604B3D6:
    r0 = r6 & 3;
    if ((r0 & r0) == 0) {
        goto L0604B3EC;
    }
    r6 = r0;
    L0604B3E2:
    r0 = LD8(r5);
    r5 = r5 + 1;
    r6 = r6 - 1;
    ST8(r4, r0);
    r4 = r4 + 1;
    if (!(r6 == 0)) {
        POLL();
        goto L0604B3E2;
    }
    L0604B3EC:
    return r3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060424BC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c8;
    int v36;
    int v40;

    r14 = r4;
    v40 = r5;
    r8 = 0;
    r12 = 0;
    r9 = 0;
    if (!((r14 & r14) == 0)) {
        r0 = LD32(r14 + 20);
        r13 = 0;
        v36 = r0;
        if (r8 >= r0) {
            r0 = r8;
        } else {
            r2 = r13;
            SETIN(7, r7);
            while (1) {
                r1 = LD32(r14 + 4);
                r11 = LD32((r2 << 2) + r1);
                r0 = GCALL6(0x0607507C, r11, 0, 0, 0, v40, v36);
                r10 = r0;
                r1 = r10;
                if (!(r10 > 0)) {
                    r0 = v36;
                    r13 = r13 + 1;
                    r2 = r13;
                    if (!(r13 >= r0)) {
                        POLL();
                        continue;
                    } else {
                        r0 = r8;
                        break;
                    }
                } else {
                    r5 = r11;
                    if (!(((r1 + r9) + 2) > r12)) {
                        r0 = GCALL6(0x06075408, r8, r5, 0, 0, v40, v36);
                        r0 = GCALL6(0x0607507C, r8, 0, 0, 0, v40, v36);
                        r9 = r0;
                        r1 = r10;
                        if ((v40 & v40) == 0) {
                            r1 = LD8(((r1 + r11) - 1));
                            r0 = v36;
                            if ((r1 & 255) == 10) {
                                r3 = r9 + r8;
                                ST8((r3 - 1), 13);
                                ST8(r8 + r9, 10);
                                ST8((r3 + 1), 0);
                                r0 = GCALL6(0x0607507C, r8, 0, 0, 0, v40, v36);
                                r9 = r0;
                                r0 = v36;
                            }
                        } else {
                            r1 = LD8(((r1 + r11) - 1));
                            c8 = (r1 & 255) == 10;
                            r1 = r10;
                            if (c8) {
                                r1 = LD8(((r1 + r11) - 1));
                                r0 = v36;
                                if ((r1 & 255) == 10) {
                                    r3 = r9 + r8;
                                    ST8((r3 - 1), 13);
                                    ST8(r8 + r9, 10);
                                    ST8((r3 + 1), 0);
                                    r0 = GCALL6(0x0607507C, r8, 0, 0, 0, v40, v36);
                                    r9 = r0;
                                    r0 = v36;
                                }
                            } else {
                                r0 = GCALL6(0x06075408, r8, 0x060424B8, 0, 0, v40, v36);
                                r0 = v36;
                            }
                        }
                        r13 = r13 + 1;
                        r2 = r13;
                        if (!(r13 >= r0)) {
                            POLL();
                            continue;
                        } else {
                            r0 = r8;
                            break;
                        }
                    } else {
                        r9 = r12;
                        if ((r8 & r8) == 0) {
                            r0 = GCALL6(0x06028380, 0x400, 13, 0, 0, v40, v36);
                            r8 = r0;
                            r1 = 0;
                            if ((r8 & r8) == 0) {
                                POLL();
                                r0 = 0;
                                break;
                            } else {
                                r12 = 0x400;
                                ST8(r8, r1);
                                r5 = r11;
                                r0 = GCALL6(0x06075408, r8, r5, 0, 0, v40, v36);
                                r0 = GCALL6(0x0607507C, r8, 0, 0, 0, v40, v36);
                                r9 = r0;
                                r1 = r10;
                                if ((v40 & v40) == 0) {
                                    r1 = LD8(((r1 + r11) - 1));
                                    r0 = v36;
                                    if ((r1 & 255) == 10) {
                                        r3 = r9 + r8;
                                        ST8((r3 - 1), 13);
                                        ST8(r8 + r9, 10);
                                        ST8((r3 + 1), 0);
                                        r0 = GCALL6(0x0607507C, r8, 0, 0, 0, v40, v36);
                                        r9 = r0;
                                        r0 = v36;
                                    }
                                } else {
                                    r1 = LD8(((r1 + r11) - 1));
                                    c8 = (r1 & 255) == 10;
                                    r1 = r10;
                                    if (c8) {
                                        r1 = LD8(((r1 + r11) - 1));
                                        r0 = v36;
                                        if ((r1 & 255) == 10) {
                                            r3 = r9 + r8;
                                            ST8((r3 - 1), 13);
                                            ST8(r8 + r9, 10);
                                            ST8((r3 + 1), 0);
                                            r0 = GCALL6(0x0607507C, r8, 0, 0, 0, v40, v36);
                                            r9 = r0;
                                            r0 = v36;
                                        }
                                    } else {
                                        r0 = GCALL6(0x06075408, r8, 0x060424B8, 0, 0, v40, v36);
                                        r0 = v36;
                                    }
                                }
                                r13 = r13 + 1;
                                r2 = r13;
                                if (!(r13 >= r0)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = r8;
                                    break;
                                }
                            }
                        } else {
                            r9 = r9 + r9;
                            r7 = R(7);
                            r0 = GCALL6(0x06027C18, 0, r8, r9, 0, v40, v36);
                            r8 = r0;
                            r12 = r9;
                            if ((r8 & r8) == 0) {
                                POLL();
                                r0 = 0;
                                break;
                            } else {
                                r5 = r11;
                                r0 = GCALL6(0x06075408, r8, r5, 0, 0, v40, v36);
                                r0 = GCALL6(0x0607507C, r8, 0, 0, 0, v40, v36);
                                r9 = r0;
                                r1 = r10;
                                if ((v40 & v40) == 0) {
                                    r1 = LD8(((r1 + r11) - 1));
                                    r0 = v36;
                                    if ((r1 & 255) == 10) {
                                        r3 = r9 + r8;
                                        ST8((r3 - 1), 13);
                                        ST8(r8 + r9, 10);
                                        ST8((r3 + 1), 0);
                                        r0 = GCALL6(0x0607507C, r8, 0, 0, 0, v40, v36);
                                        r9 = r0;
                                        r0 = v36;
                                    }
                                } else {
                                    r1 = LD8(((r1 + r11) - 1));
                                    c8 = (r1 & 255) == 10;
                                    r1 = r10;
                                    if (c8) {
                                        r1 = LD8(((r1 + r11) - 1));
                                        r0 = v36;
                                        if ((r1 & 255) == 10) {
                                            r3 = r9 + r8;
                                            ST8((r3 - 1), 13);
                                            ST8(r8 + r9, 10);
                                            ST8((r3 + 1), 0);
                                            r0 = GCALL6(0x0607507C, r8, 0, 0, 0, v40, v36);
                                            r9 = r0;
                                            r0 = v36;
                                        }
                                    } else {
                                        r0 = GCALL6(0x06075408, r8, 0x060424B8, 0, 0, v40, v36);
                                        r0 = v36;
                                    }
                                }
                                r13 = r13 + 1;
                                r2 = r13;
                                if (!(r13 >= r0)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = r8;
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
int f06047240(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r10, c3, c1006;
    FRAME(sp, 288);

    r10 = r4;
    r1 = LD32(r10);
    if (r1 >= 0) {
        r0 = GCALL3(0x0604B3F0, (sp - 152), 0, 136);
        r0 = GCALL3(0x0604B3F0, (sp - 288), 0, 136);
        ST16(sp - 288, 20);
        r1 = (sp - 288) + 2;
        ST16(r1, 0x7D4);
        r2 = LD32(r10 + 28);
        ST32(sp - 276, r2);
        r3 = LD32(r10 + 52);
        ST16((r3 + 8), 20);
        r2 = LD16(r1);
        r1 = r1 + 2;
        ST16((r3 + 10), r2);
        r2 = LD16(r1);
        r1 = r1 + 2;
        ST16((r3 + 12), r2);
        r2 = LD16(r1);
        r1 = r1 + 2;
        ST16((r3 + 14), r2);
        r2 = LD16(r1);
        r1 = r1 + 2;
        ST16((r3 + 16), r2);
        r2 = LD16(r1);
        r1 = r1 + 2;
        ST16((r3 + 18), r2);
        r2 = LD16(r1);
        r1 = r1 + 2;
        ST16((r3 + 20), r2);
        r2 = LD16(r1);
        r1 = r1 + 2;
        ST16((r3 + 22), r2);
        r2 = LD16(r1);
        ST16((r3 + 24), r2);
        r1 = LD16((r1 + 2));
        r7 = r3 + 26;
        ST16(r7, r1);
        r5 = LD32(r10 + 52);
        r4 = LD32(r10);
        r0 = GCALL5(0x0605B0D8, r4, r5, 20, r7, LD32((sp - 288)));
        if (!(r0 >= 0)) {
            r4 = LD32(r10);
            r7 = R(7);
            r0 = GCALL5(0x0605B208, r4, 0, 0, 0, LD32((sp - 288)));
            r4 = LD32(r10 + 52);
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 288)));
            ST32(r10 + 52, 0);
            r0 = -900;
            ST32(r10, -1);
        } else {
            r5 = LD32(r10 + 52);
            r4 = LD32(r10);
            r7 = R(7);
            r0 = GCALL5(0x0605AF90, r4, r5, 0x1FE4, 0, LD32((sp - 288)));
            c3 = r0 == -3;
            c1006 = c3;
            if (r0 >= 0) {
                r3 = LD32(r10 + 52);
                r2 = LD16((r3 + 8));
                ST16(136 + (sp - 288), r2);
                r2 = LD16((r3 + 10));
                r1 = (sp - 152) + 2;
                ST16(r1, r2);
                r2 = LD16((r3 + 12));
                r1 = r1 + 2;
                ST16(r1, r2);
                r2 = LD16((r3 + 14));
                r1 = r1 + 2;
                ST16(r1, r2);
                r2 = LD16((r3 + 16));
                r1 = r1 + 2;
                ST16(r1, r2);
                r2 = LD16((r3 + 18));
                r1 = r1 + 2;
                ST16(r1, r2);
                r2 = LD16((r3 + 20));
                r1 = r1 + 2;
                ST16(r1, r2);
                r2 = LD16((r3 + 22));
                r1 = r1 + 2;
                ST16(r1, r2);
                r2 = LD16((r3 + 24));
                r1 = r1 + 2;
                ST16(r1, r2);
                r2 = LD16((r3 + 26));
                ST16((r1 + 2), r2);
                r4 = LD32(r10);
                r7 = R(7);
                r0 = GCALL5(0x0605B208, r4, 0, 0, 0, LD32((sp - 288)));
                r4 = LD32(r10 + 52);
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 288)));
                ST32(r10 + 52, 0);
                ST32(r10, -1);
                r0 = 0;
            } else {
                c1006 = c3;
                if (c3) {
                    r3 = LD32(r10 + 52);
                    r2 = LD16((r3 + 8));
                    ST16(136 + (sp - 288), r2);
                    r2 = LD16((r3 + 10));
                    r1 = (sp - 152) + 2;
                    ST16(r1, r2);
                    r2 = LD16((r3 + 12));
                    r1 = r1 + 2;
                    ST16(r1, r2);
                    r2 = LD16((r3 + 14));
                    r1 = r1 + 2;
                    ST16(r1, r2);
                    r2 = LD16((r3 + 16));
                    r1 = r1 + 2;
                    ST16(r1, r2);
                    r2 = LD16((r3 + 18));
                    r1 = r1 + 2;
                    ST16(r1, r2);
                    r2 = LD16((r3 + 20));
                    r1 = r1 + 2;
                    ST16(r1, r2);
                    r2 = LD16((r3 + 22));
                    r1 = r1 + 2;
                    ST16(r1, r2);
                    r2 = LD16((r3 + 24));
                    r1 = r1 + 2;
                    ST16(r1, r2);
                    r2 = LD16((r3 + 26));
                    ST16((r1 + 2), r2);
                    r4 = LD32(r10);
                    r7 = R(7);
                    r0 = GCALL5(0x0605B208, r4, 0, 0, 0, LD32((sp - 288)));
                    r4 = LD32(r10 + 52);
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 288)));
                    ST32(r10 + 52, 0);
                    ST32(r10, -1);
                    r0 = 0;
                } else {
                    r4 = LD32(r10);
                    r7 = R(7);
                    r0 = GCALL5(0x0605B208, r4, 0, 0, 0, LD32((sp - 288)));
                    r4 = LD32(r10 + 52);
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 288)));
                    ST32(r10 + 52, 0);
                    r0 = -900;
                    ST32(r10, -1);
                }
            }
        }
    } else {
        SETIN(7, r7);
        r4 = LD32(r10);
        r7 = R(7);
        r0 = GCALL5(0x0605B208, r4, 0, 0, 0, LD32((sp - 288)));
        r4 = LD32(r10 + 52);
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 288)));
        ST32(r10 + 52, 0);
        ST32(r10, -1);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060403D0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c2011, c2013, c2014;
    FRAME(sp, 56);

    r13 = r4;
    ST32(sp - 36, r5);
    r11 = r6;
    r4 = LD32(r13 + 24);
    r12 = 0;
    if ((r4 & r4) == 0) {
        goto L060403F8;
    }
    r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
    ST32(r13 + 24, r12);
    L060403F8:
    r8 = 0x800;
    r0 = GCALL4(0x060279E0, 1, 0x800, 15, 1);
    r10 = r0;
    r9 = r10;
    if (!((r10 & r10) == 0)) {
        goto L06040412;
    }
    goto L06040600;
    L06040412:
    r1 = LD32(r13 + 40);
    r14 = r8;
    if ((r1 & r1) == 0) {
        goto L06040420;
    }
    SETIN(0, r0);
    r0 = GCALL2(r1, 0x0603F3E0, 0);
    L06040420:
    c2011 = R(11);
    SETR(11, r11);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL3(0x06049910, r13, r11, r10);
    SETR(11, c2011);
    SETR(13, c2013);
    SETR(14, c2014);
    r8 = r0;
    if (r8 > 0) {
        goto L0604043A;
    }
    goto L060406B8;
    L06040436:
    ST8(r2, r1);
    goto L06040528;
    L0604043A:
    ST32(sp - 40, r10);
    r1 = LD8(r10);
    goto L06040466;
    L06040454:
    r1 = LD8(r2);
    r0 = r1 & 255;
    r1 = r2;
    if (r0 == 10) {
        goto L0604046E;
    }
    r1 = r1 + 1;
    ST32(sp - 40, r1);
    r1 = LD8(r1);
    r8 = r8 - 1;
    L06040466:
    r2 = LD32(sp - 40);
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        POLL();
        goto L06040454;
    }
    L0604046E:
    r5 = LD32(sp - 40);
    if (!(r8 > 0)) {
        goto L06040488;
    }
    r1 = LD8(r5);
    r6 = r8;
    if (((r1 & 255) & (r1 & 255)) == 0) {
        goto L06040488;
    }
    r0 = GCALL3(0x0604B358, r9, r5, r6);
    r12 = r12 + r8;
    r9 = r9 + r8;
    L06040488:
    r1 = LD32(r13 + 40);
    r11 = 40;
    if ((r1 & r1) == 0) {
        goto L06040498;
    }
    r4 = 0x060403B0;
    r5 = r11;
    L06040494:
    SETIN(0, r0);
    r0 = GCALL2(r1, r4, r5);
    L06040498:
    r0 = GCALL0(0x0605299C);
    r4 = LD32(r13);
    r0 = GCALL3(0x0605ACCC, r4, r9, 0x114);
    r1 = LD32(0x060766B4);
    r8 = r0;
    if ((r1 & r1) == 0) {
        goto L060404B6;
    }
    goto L06040670;
    L060404B6:
    if (!(r8 > 0)) {
        goto L0604051C;
    }
    r9 = r9 + r8;
    r2 = r9 - 5;
    r1 = LD8(r2);
    r0 = r1 & 255;
    r12 = r12 + r8;
    if (!(r0 == 13)) {
        goto L060404E4;
    }
    r1 = LD8((r9 - 4));
    r0 = r1 & 255;
    r1 = r9;
    if (!(r0 == 10)) {
        goto L060404E4;
    }
    r1 = LD8((r1 - 3));
    r0 = r1 & 255;
    r1 = 0;
    if (r0 == 46) {
        POLL();
        goto L06040436;
    }
    L060404E4:
    r8 = r14;
    if (!((0x114 + r12) > r14)) {
        goto L0604050E;
    }
    r8 = r8 + 0x800;
    r0 = GCALL3(0x06027C18, 0, r10, r8);
    ST32(sp - 40, r0);
    if (!((r0 & r0) == 0)) {
        goto L06040506;
    }
    goto L0604067A;
    L06040506:
    r10 = r0;
    r14 = r8;
    r9 = r10 + r12;
    L0604050E:
    r1 = LD32(r13 + 40);
    r11 = r11 + 2;
    if ((r1 & r1) == 0) {
        POLL();
        goto L06040498;
    }
    r4 = 0x060403B0;
    r5 = r11;
    POLL();
    goto L06040494;
    L0604051C:
    r0 = -1;
    if (r8 == -502) {
        POLL();
        goto L06040498;
    }
    goto L060406B8;
    L06040528:
    ST32(r13 + 24, r10);
    r1 = LD32(r13 + 40);
    r11 = 90;
    if ((r1 & r1) == 0) {
        goto L06040538;
    }
    SETIN(0, r0);
    r0 = GCALL2(r1, 0x060403B0, r11);
    L06040538:
    r1 = LD8(0x0608AF4C);
    r4 = sp - 48;
    if (!((r1 & r1) == 0)) {
        goto L06040622;
    }
    r0 = GCALL2(0x0603FA9C, r10, (sp - 48));
    r8 = r0;
    r4 = sp - 48;
    if ((r8 & r8) == 0) {
        goto L06040600;
    }
    r9 = 0x06018688;
    r5 = LD32(sp - 48);
    r0 = GCALL4(0x06018688, (r4 + 4), r5, 1, 0);
    r1 = LD32(sp - 44);
    r4 = LD32(sp - 48);
    if (!((r1 & r1) == 0)) {
        goto L0604056C;
    }
    r1 = 0x06027F48;
    goto L0604067E;
    L0604056C:
    r11 = 0x06027F48;
    r4 = LD32(sp - 48);
    r0 = GCALL1(0x06027F48, r4);
    SETIN(0, r0);
    r0 = GCALL4(r9, (sp - 40), (r10 + r8), 1, 0);
    r1 = LD32(sp - 40);
    if (!((r1 & r1) == 0)) {
        goto L060405BC;
    }
    r4 = LD32(sp - 44);
    goto L060405FC;
    L060405BC:
    r12 = 0x06078D8C;
    r0 = GCALL1(0x0607507C, 0x06078D8C);
    r8 = r0;
    r10 = 0x06078E20;
    r0 = GCALL1(0x0607507C, 0x06078E20);
    r4 = LD32(sp - 44);
    r8 = r8 + (r0 + r0);
    r0 = GCALL1(0x0607507C, r4);
    r4 = LD32(sp - 40);
    r8 = r8 + r0;
    r0 = GCALL1(0x0607507C, r4);
    r0 = GCALL4(0x060279E0, 1, ((r8 + r0) + 1), 15, 1);
    r2 = r0;
    r3 = LD32(sp - 36);
    ST32(r3, r2);
    if (!((r2 & r2) == 0)) {
        goto L06040604;
    }
    r4 = LD32(sp - 44);
    SETIN(0, r0);
    r0 = GCALL1(r11, r4);
    r4 = LD32(sp - 40);
    L060405FC:
    SETIN(0, r0);
    r0 = GCALL1(r11, r4);
    L06040600:
    r0 = -3;
    goto L060406B6;
    L06040604:
    r7 = LD32(sp - 44);
    ST32((sp - 52), r10);
    r1 = LD32(sp - 40);
    ST32((sp - 56), r1);
    r0 = GCALL6(0x06045264, r2, r12, r10, r7, LD32((sp - 56)), LD32((sp - 52)));
    r4 = LD32(sp - 40);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL6(r11, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)));
    r4 = LD32(sp - 44);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL6(r11, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)));
    goto L0604069C;
    L06040622:
    r0 = GCALL4(0x06018688, (r4 + 8), r10, 1, 0);
    r1 = LD32(sp - 40);
    r0 = -3;
    if ((r1 & r1) == 0) {
        goto L060406B6;
    }
    r11 = 0x06078D00;
    r0 = GCALL1(0x0607507C, 0x06078D00);
    r8 = r0;
    r10 = 0x06078E20;
    r0 = GCALL1(0x0607507C, 0x06078E20);
    r4 = LD32(sp - 40);
    r8 = r8 + (r0 + r0);
    r0 = GCALL1(0x0607507C, r4);
    r0 = GCALL4(0x060279E0, 1, ((r8 + r0) + 1), 15, 1);
    r1 = r0;
    r3 = LD32(sp - 36);
    ST32(r3, r1);
    if (!((r1 & r1) == 0)) {
        goto L06040686;
    }
    r1 = 0x06027F48;
    r4 = LD32(sp - 40);
    goto L0604067E;
    L06040670:
    r0 = GCALL1(0x06027F48, r10);
    r0 = -12;
    goto L060406B6;
    L0604067A:
    r1 = 0x06027F48;
    r4 = r10;
    L0604067E:
    SETIN(0, r0);
    r0 = GCALL1(r1, r4);
    r0 = -3;
    goto L060406B6;
    L06040686:
    r7 = LD32(sp - 40);
    ST32((sp - 52), r10);
    r0 = GCALL5(0x06045264, r1, r11, r10, r7, LD32((sp - 52)));
    r4 = LD32(sp - 40);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 52)));
    L0604069C:
    r1 = LD32(r13 + 40);
    r3 = LD32(sp - 36);
    if ((r1 & r1) == 0) {
        goto L060406AC;
    }
    SETIN(0, r0);
    r0 = GCALL2(r1, 0x060403C0, 100);
    r3 = LD32(sp - 36);
    L060406AC:
    r4 = LD32(r3);
    r0 = GCALL1(0x0607507C, r4);
    ST32(r13 + 8, r0);
    r0 = 0;
    L060406B6:
    L060406B8:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06040A04(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r13, r14, c23, c26, c2011;
    FRAME(sp, 300);

    r10 = r5;
    r0 = 0x100;
    ST32(0x100 + (sp - 296), r6);
    r8 = LD32((r10 + 104));
    r13 = r4;
    if ((r8 & r8) == 0) {
        r1 = LD32(r13 + 52);
        if (!((r1 & r1) == 0)) {
            SETIN(0, r0);
            r0 = GCALL4(r1, -1, r5, r6, r7);
        }
    } else {
        r0 = GCALL1(0x0607507C, r8);
        if ((unsigned)r0 > (unsigned)8) {
            r9 = 0x060752FC;
            r6 = 9;
            while (1) {
                SETIN(0, r0);
                r0 = GCALL3(r9, r8, 0x060409EC, r6);
                if ((r0 & r0) == 0) {
                    break;
                } else {
                    r1 = LD8(r8);
                    r1 = r1 & 255;
                    r0 = r1;
                    if ((r1 & r1) == 0) {
                        break;
                    } else {
                        if (r0 == 38) {
                            break;
                        } else {
                            r8 = r8 + 1;
                            r6 = 9;
                        }
                    }
                }
                POLL();
            }
            r1 = LD8(r8);
            r1 = r1 & 255;
            if ((r1 & r1) == 0) {
                r1 = LD32(r13 + 52);
                if (!((r1 & r1) == 0)) {
                    SETIN(0, r0);
                    r0 = GCALL1(r1, -605);
                }
            } else {
                r0 = r1;
                r11 = r8;
                if (!(r0 == 38)) {
                    r11 = r11 + 9;
                    r9 = 0x060752FC;
                    r6 = 8;
                    while (1) {
                        SETIN(0, r0);
                        r0 = GCALL3(r9, r8, 0x060409F8, r6);
                        if ((r0 & r0) == 0) {
                            break;
                        } else {
                            r1 = LD8(r8);
                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                break;
                            } else {
                                r8 = r8 + 1;
                                r6 = 8;
                            }
                        }
                        POLL();
                    }
                    r1 = LD8(r8);
                    r9 = 0;
                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                        r8 = r8 + 8;
                        r2 = LD8(r8);
                        r3 = 0;
                        if (!((r2 & 255) == 38)) {
                            r1 = r2 & 255;
                            while (1) {
                                r0 = sp - 296;
                                if ((r1 & r1) == 0) {
                                    break;
                                } else {
                                    ST8(r0 + r3, r2);
                                    r8 = r8 + 1;
                                    r2 = LD8(r8);
                                    r1 = r2 & 255;
                                    r3 = r3 + 1;
                                    if (!(r1 == 38)) {
                                        POLL();
                                        continue;
                                    } else {
                                        break;
                                    }
                                }
                                POLL();
                            }
                        }
                        ST8((sp - 296) + r3, 0);
                        if (r3 > 0) {
                            r0 = GCALL1(0x0603FC68, (sp - 296));
                        }
                        r9 = sp - 296;
                        while (1) {
                            r1 = LD8(r8);
                            r0 = r1 & 255;
                            r1 = r1 & 255;
                            if (!(r0 == 61)) {
                                POLL();
                                if ((r1 & r1) == 0) {
                                    r8 = r8 + 1;
                                    r1 = LD8(r8);
                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                        r2 = -608;
                                        if (!((r2 & r2) == 0)) {
                                            r1 = LD32(r13 + 52);
                                            if ((r1 & r1) == 0) {
                                                r4 = LD32((r10 + 104));
                                                c23 = (r4 & r4) == 0;
                                                r4 = r4 + 9;
                                                if (!(c23)) {
                                                    ST32((0x104 + (sp - 296)), r4);
                                                    r4 = LD32((0x104 + (sp - 296)));
                                                    r0 = LD32((0x104 + (sp - 296)));
                                                    r1 = LD8(r0);
                                                    if ((r1 & 255) == 38) {
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r1 = LD8(r4);
                                                        r1 = r1 & 255;
                                                        while (!((r1 & r1) == 0)) {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                            if (!(c26)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                break;
                                                            }
                                                            POLL();
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            } else {
                                                SETIN(0, r0);
                                                r0 = GCALL1(r1, r2);
                                                r4 = LD32((r10 + 104));
                                                c23 = (r4 & r4) == 0;
                                                r4 = r4 + 9;
                                                if (!(c23)) {
                                                    ST32((0x104 + (sp - 296)), r4);
                                                    r4 = LD32((0x104 + (sp - 296)));
                                                    r0 = LD32((0x104 + (sp - 296)));
                                                    r1 = LD8(r0);
                                                    if ((r1 & 255) == 38) {
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r1 = LD8(r4);
                                                        r1 = r1 & 255;
                                                        while (!((r1 & r1) == 0)) {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                            if (!(c26)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                break;
                                                            }
                                                            POLL();
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            }
                                        } else {
                                            r8 = 0x060408E4;
                                            r0 = GCALL1(0x0607507C, 0x060408E4);
                                            r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                            r1 = r0;
                                            r0 = LD32((0x100 + (sp - 296)));
                                            ST32(r0, r1);
                                            if (!((r1 & r1) == 0)) {
                                                r0 = GCALL2(0x06045264, r1, r8);
                                                r8 = r10;
                                                r8 = r8 + 104;
                                                r4 = LD32(r8);
                                                if ((r4 & r4) == 0) {
                                                    break;
                                                } else {
                                                    r0 = GCALL1(0x06027F48, r4);
                                                    ST32(r8, 0);
                                                    break;
                                                }
                                            } else {
                                                r1 = LD32(r13 + 52);
                                                if (!((r1 & r1) == 0)) {
                                                    SETIN(0, r0);
                                                    r0 = GCALL1(r1, -3);
                                                    break;
                                                } else {
                                                    break;
                                                }
                                            }
                                        }
                                    } else {
                                        r0 = GCALL1(0x0603FC68, r8);
                                        c2011 = R(11);
                                        SETR(11, r11);
                                        r0 = GCALL4(0x06049AB0, r13, r11, r9, r8);
                                        SETR(11, c2011);
                                        r2 = r0;
                                        if (!((r2 & r2) == 0)) {
                                            r1 = LD32(r13 + 52);
                                            if ((r1 & r1) == 0) {
                                                r4 = LD32((r10 + 104));
                                                c23 = (r4 & r4) == 0;
                                                r4 = r4 + 9;
                                                if (!(c23)) {
                                                    ST32((0x104 + (sp - 296)), r4);
                                                    r4 = LD32((0x104 + (sp - 296)));
                                                    r0 = LD32((0x104 + (sp - 296)));
                                                    r1 = LD8(r0);
                                                    if ((r1 & 255) == 38) {
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r1 = LD8(r4);
                                                        r1 = r1 & 255;
                                                        while (!((r1 & r1) == 0)) {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                            if (!(c26)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                break;
                                                            }
                                                            POLL();
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            } else {
                                                SETIN(0, r0);
                                                r0 = GCALL1(r1, r2);
                                                r4 = LD32((r10 + 104));
                                                c23 = (r4 & r4) == 0;
                                                r4 = r4 + 9;
                                                if (!(c23)) {
                                                    ST32((0x104 + (sp - 296)), r4);
                                                    r4 = LD32((0x104 + (sp - 296)));
                                                    r0 = LD32((0x104 + (sp - 296)));
                                                    r1 = LD8(r0);
                                                    if ((r1 & 255) == 38) {
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r1 = LD8(r4);
                                                        r1 = r1 & 255;
                                                        while (!((r1 & r1) == 0)) {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                            if (!(c26)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                break;
                                                            }
                                                            POLL();
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            }
                                        } else {
                                            r8 = 0x060408E4;
                                            r0 = GCALL1(0x0607507C, 0x060408E4);
                                            r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                            r1 = r0;
                                            r0 = LD32((0x100 + (sp - 296)));
                                            ST32(r0, r1);
                                            if (!((r1 & r1) == 0)) {
                                                r0 = GCALL2(0x06045264, r1, r8);
                                                r8 = r10;
                                                r8 = r8 + 104;
                                                r4 = LD32(r8);
                                                if ((r4 & r4) == 0) {
                                                    break;
                                                } else {
                                                    r0 = GCALL1(0x06027F48, r4);
                                                    ST32(r8, 0);
                                                    break;
                                                }
                                            } else {
                                                r1 = LD32(r13 + 52);
                                                if (!((r1 & r1) == 0)) {
                                                    SETIN(0, r0);
                                                    r0 = GCALL1(r1, -3);
                                                    break;
                                                } else {
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    r8 = r8 + 1;
                                    continue;
                                }
                            } else {
                                r8 = r8 + 1;
                                r1 = LD8(r8);
                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                    r2 = -608;
                                    if (!((r2 & r2) == 0)) {
                                        r1 = LD32(r13 + 52);
                                        if ((r1 & r1) == 0) {
                                            r4 = LD32((r10 + 104));
                                            c23 = (r4 & r4) == 0;
                                            r4 = r4 + 9;
                                            if (!(c23)) {
                                                ST32((0x104 + (sp - 296)), r4);
                                                r4 = LD32((0x104 + (sp - 296)));
                                                r0 = LD32((0x104 + (sp - 296)));
                                                r1 = LD8(r0);
                                                if ((r1 & 255) == 38) {
                                                    r1 = LD8(r4);
                                                    r0 = r1 & 255;
                                                    r1 = 0;
                                                    if (!(r0 == 38)) {
                                                        break;
                                                    } else {
                                                        ST8(r4, r1);
                                                        r11 = r4 + 9;
                                                        r1 = LD8(r11);
                                                        r4 = r11;
                                                        while (!((r1 & 255) == 38)) {
                                                            POLL();
                                                            r1 = LD8(r4);
                                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                break;
                                                            } else {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                            }
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r14 = r4 + 6;
                                                            r10 = r10 + 104;
                                                            r4 = LD32(r10);
                                                            r0 = GCALL1(0x06027F48, r4);
                                                            r4 = LD32((0x104 + (sp - 296)));
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r8 = r0;
                                                            r0 = GCALL1(0x0607507C, r11);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, r14);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, 0x060408C8);
                                                            r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                            r1 = r0;
                                                            ST32(r10, r1);
                                                            if ((r1 & r1) == 0) {
                                                                break;
                                                            } else {
                                                                ST32((sp - 300), r14);
                                                                r6 = LD32((0x108 + (sp - 300)));
                                                                r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                r6 = LD32(r10);
                                                                r5 = LD32(0x104 + (sp - 300));
                                                                r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                r4 = LD32(r10);
                                                                r5 = R(5);
                                                                r6 = R(6);
                                                                r7 = R(7);
                                                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                ST32(r10, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    r1 = LD8(r4);
                                                    r1 = r1 & 255;
                                                    while (!((r1 & r1) == 0)) {
                                                        r4 = r4 + 1;
                                                        r1 = LD8(r4);
                                                        c26 = (r1 & 255) == 38;
                                                        r1 = r1 & 255;
                                                        if (!(c26)) {
                                                            POLL();
                                                            continue;
                                                        } else {
                                                            break;
                                                        }
                                                        POLL();
                                                    }
                                                    r1 = LD8(r4);
                                                    r0 = r1 & 255;
                                                    r1 = 0;
                                                    if (!(r0 == 38)) {
                                                        break;
                                                    } else {
                                                        ST8(r4, r1);
                                                        r11 = r4 + 9;
                                                        r1 = LD8(r11);
                                                        r4 = r11;
                                                        while (!((r1 & 255) == 38)) {
                                                            POLL();
                                                            r1 = LD8(r4);
                                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                break;
                                                            } else {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                            }
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r14 = r4 + 6;
                                                            r10 = r10 + 104;
                                                            r4 = LD32(r10);
                                                            r0 = GCALL1(0x06027F48, r4);
                                                            r4 = LD32((0x104 + (sp - 296)));
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r8 = r0;
                                                            r0 = GCALL1(0x0607507C, r11);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, r14);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, 0x060408C8);
                                                            r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                            r1 = r0;
                                                            ST32(r10, r1);
                                                            if ((r1 & r1) == 0) {
                                                                break;
                                                            } else {
                                                                ST32((sp - 300), r14);
                                                                r6 = LD32((0x108 + (sp - 300)));
                                                                r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                r6 = LD32(r10);
                                                                r5 = LD32(0x104 + (sp - 300));
                                                                r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                r4 = LD32(r10);
                                                                r5 = R(5);
                                                                r6 = R(6);
                                                                r7 = R(7);
                                                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                ST32(r10, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                break;
                                            }
                                        } else {
                                            SETIN(0, r0);
                                            r0 = GCALL1(r1, r2);
                                            r4 = LD32((r10 + 104));
                                            c23 = (r4 & r4) == 0;
                                            r4 = r4 + 9;
                                            if (!(c23)) {
                                                ST32((0x104 + (sp - 296)), r4);
                                                r4 = LD32((0x104 + (sp - 296)));
                                                r0 = LD32((0x104 + (sp - 296)));
                                                r1 = LD8(r0);
                                                if ((r1 & 255) == 38) {
                                                    r1 = LD8(r4);
                                                    r0 = r1 & 255;
                                                    r1 = 0;
                                                    if (!(r0 == 38)) {
                                                        break;
                                                    } else {
                                                        ST8(r4, r1);
                                                        r11 = r4 + 9;
                                                        r1 = LD8(r11);
                                                        r4 = r11;
                                                        while (!((r1 & 255) == 38)) {
                                                            POLL();
                                                            r1 = LD8(r4);
                                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                break;
                                                            } else {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                            }
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r14 = r4 + 6;
                                                            r10 = r10 + 104;
                                                            r4 = LD32(r10);
                                                            r0 = GCALL1(0x06027F48, r4);
                                                            r4 = LD32((0x104 + (sp - 296)));
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r8 = r0;
                                                            r0 = GCALL1(0x0607507C, r11);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, r14);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, 0x060408C8);
                                                            r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                            r1 = r0;
                                                            ST32(r10, r1);
                                                            if ((r1 & r1) == 0) {
                                                                break;
                                                            } else {
                                                                ST32((sp - 300), r14);
                                                                r6 = LD32((0x108 + (sp - 300)));
                                                                r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                r6 = LD32(r10);
                                                                r5 = LD32(0x104 + (sp - 300));
                                                                r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                r4 = LD32(r10);
                                                                r5 = R(5);
                                                                r6 = R(6);
                                                                r7 = R(7);
                                                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                ST32(r10, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    r1 = LD8(r4);
                                                    r1 = r1 & 255;
                                                    while (!((r1 & r1) == 0)) {
                                                        r4 = r4 + 1;
                                                        r1 = LD8(r4);
                                                        c26 = (r1 & 255) == 38;
                                                        r1 = r1 & 255;
                                                        if (!(c26)) {
                                                            POLL();
                                                            continue;
                                                        } else {
                                                            break;
                                                        }
                                                        POLL();
                                                    }
                                                    r1 = LD8(r4);
                                                    r0 = r1 & 255;
                                                    r1 = 0;
                                                    if (!(r0 == 38)) {
                                                        break;
                                                    } else {
                                                        ST8(r4, r1);
                                                        r11 = r4 + 9;
                                                        r1 = LD8(r11);
                                                        r4 = r11;
                                                        while (!((r1 & 255) == 38)) {
                                                            POLL();
                                                            r1 = LD8(r4);
                                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                break;
                                                            } else {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                            }
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r14 = r4 + 6;
                                                            r10 = r10 + 104;
                                                            r4 = LD32(r10);
                                                            r0 = GCALL1(0x06027F48, r4);
                                                            r4 = LD32((0x104 + (sp - 296)));
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r8 = r0;
                                                            r0 = GCALL1(0x0607507C, r11);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, r14);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, 0x060408C8);
                                                            r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                            r1 = r0;
                                                            ST32(r10, r1);
                                                            if ((r1 & r1) == 0) {
                                                                break;
                                                            } else {
                                                                ST32((sp - 300), r14);
                                                                r6 = LD32((0x108 + (sp - 300)));
                                                                r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                r6 = LD32(r10);
                                                                r5 = LD32(0x104 + (sp - 300));
                                                                r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                r4 = LD32(r10);
                                                                r5 = R(5);
                                                                r6 = R(6);
                                                                r7 = R(7);
                                                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                ST32(r10, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                    } else {
                                        r8 = 0x060408E4;
                                        r0 = GCALL1(0x0607507C, 0x060408E4);
                                        r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                        r1 = r0;
                                        r0 = LD32((0x100 + (sp - 296)));
                                        ST32(r0, r1);
                                        if (!((r1 & r1) == 0)) {
                                            r0 = GCALL2(0x06045264, r1, r8);
                                            r8 = r10;
                                            r8 = r8 + 104;
                                            r4 = LD32(r8);
                                            if ((r4 & r4) == 0) {
                                                break;
                                            } else {
                                                r0 = GCALL1(0x06027F48, r4);
                                                ST32(r8, 0);
                                                break;
                                            }
                                        } else {
                                            r1 = LD32(r13 + 52);
                                            if (!((r1 & r1) == 0)) {
                                                SETIN(0, r0);
                                                r0 = GCALL1(r1, -3);
                                                break;
                                            } else {
                                                break;
                                            }
                                        }
                                    }
                                } else {
                                    r0 = GCALL1(0x0603FC68, r8);
                                    c2011 = R(11);
                                    SETR(11, r11);
                                    r0 = GCALL4(0x06049AB0, r13, r11, r9, r8);
                                    SETR(11, c2011);
                                    r2 = r0;
                                    if (!((r2 & r2) == 0)) {
                                        r1 = LD32(r13 + 52);
                                        if ((r1 & r1) == 0) {
                                            r4 = LD32((r10 + 104));
                                            c23 = (r4 & r4) == 0;
                                            r4 = r4 + 9;
                                            if (!(c23)) {
                                                ST32((0x104 + (sp - 296)), r4);
                                                r4 = LD32((0x104 + (sp - 296)));
                                                r0 = LD32((0x104 + (sp - 296)));
                                                r1 = LD8(r0);
                                                if ((r1 & 255) == 38) {
                                                    r1 = LD8(r4);
                                                    r0 = r1 & 255;
                                                    r1 = 0;
                                                    if (!(r0 == 38)) {
                                                        break;
                                                    } else {
                                                        ST8(r4, r1);
                                                        r11 = r4 + 9;
                                                        r1 = LD8(r11);
                                                        r4 = r11;
                                                        while (!((r1 & 255) == 38)) {
                                                            POLL();
                                                            r1 = LD8(r4);
                                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                break;
                                                            } else {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                            }
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r14 = r4 + 6;
                                                            r10 = r10 + 104;
                                                            r4 = LD32(r10);
                                                            r0 = GCALL1(0x06027F48, r4);
                                                            r4 = LD32((0x104 + (sp - 296)));
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r8 = r0;
                                                            r0 = GCALL1(0x0607507C, r11);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, r14);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, 0x060408C8);
                                                            r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                            r1 = r0;
                                                            ST32(r10, r1);
                                                            if ((r1 & r1) == 0) {
                                                                break;
                                                            } else {
                                                                ST32((sp - 300), r14);
                                                                r6 = LD32((0x108 + (sp - 300)));
                                                                r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                r6 = LD32(r10);
                                                                r5 = LD32(0x104 + (sp - 300));
                                                                r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                r4 = LD32(r10);
                                                                r5 = R(5);
                                                                r6 = R(6);
                                                                r7 = R(7);
                                                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                ST32(r10, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    r1 = LD8(r4);
                                                    r1 = r1 & 255;
                                                    while (!((r1 & r1) == 0)) {
                                                        r4 = r4 + 1;
                                                        r1 = LD8(r4);
                                                        c26 = (r1 & 255) == 38;
                                                        r1 = r1 & 255;
                                                        if (!(c26)) {
                                                            POLL();
                                                            continue;
                                                        } else {
                                                            break;
                                                        }
                                                        POLL();
                                                    }
                                                    r1 = LD8(r4);
                                                    r0 = r1 & 255;
                                                    r1 = 0;
                                                    if (!(r0 == 38)) {
                                                        break;
                                                    } else {
                                                        ST8(r4, r1);
                                                        r11 = r4 + 9;
                                                        r1 = LD8(r11);
                                                        r4 = r11;
                                                        while (!((r1 & 255) == 38)) {
                                                            POLL();
                                                            r1 = LD8(r4);
                                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                break;
                                                            } else {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                            }
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r14 = r4 + 6;
                                                            r10 = r10 + 104;
                                                            r4 = LD32(r10);
                                                            r0 = GCALL1(0x06027F48, r4);
                                                            r4 = LD32((0x104 + (sp - 296)));
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r8 = r0;
                                                            r0 = GCALL1(0x0607507C, r11);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, r14);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, 0x060408C8);
                                                            r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                            r1 = r0;
                                                            ST32(r10, r1);
                                                            if ((r1 & r1) == 0) {
                                                                break;
                                                            } else {
                                                                ST32((sp - 300), r14);
                                                                r6 = LD32((0x108 + (sp - 300)));
                                                                r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                r6 = LD32(r10);
                                                                r5 = LD32(0x104 + (sp - 300));
                                                                r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                r4 = LD32(r10);
                                                                r5 = R(5);
                                                                r6 = R(6);
                                                                r7 = R(7);
                                                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                ST32(r10, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                break;
                                            }
                                        } else {
                                            SETIN(0, r0);
                                            r0 = GCALL1(r1, r2);
                                            r4 = LD32((r10 + 104));
                                            c23 = (r4 & r4) == 0;
                                            r4 = r4 + 9;
                                            if (!(c23)) {
                                                ST32((0x104 + (sp - 296)), r4);
                                                r4 = LD32((0x104 + (sp - 296)));
                                                r0 = LD32((0x104 + (sp - 296)));
                                                r1 = LD8(r0);
                                                if ((r1 & 255) == 38) {
                                                    r1 = LD8(r4);
                                                    r0 = r1 & 255;
                                                    r1 = 0;
                                                    if (!(r0 == 38)) {
                                                        break;
                                                    } else {
                                                        ST8(r4, r1);
                                                        r11 = r4 + 9;
                                                        r1 = LD8(r11);
                                                        r4 = r11;
                                                        while (!((r1 & 255) == 38)) {
                                                            POLL();
                                                            r1 = LD8(r4);
                                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                break;
                                                            } else {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                            }
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r14 = r4 + 6;
                                                            r10 = r10 + 104;
                                                            r4 = LD32(r10);
                                                            r0 = GCALL1(0x06027F48, r4);
                                                            r4 = LD32((0x104 + (sp - 296)));
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r8 = r0;
                                                            r0 = GCALL1(0x0607507C, r11);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, r14);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, 0x060408C8);
                                                            r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                            r1 = r0;
                                                            ST32(r10, r1);
                                                            if ((r1 & r1) == 0) {
                                                                break;
                                                            } else {
                                                                ST32((sp - 300), r14);
                                                                r6 = LD32((0x108 + (sp - 300)));
                                                                r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                r6 = LD32(r10);
                                                                r5 = LD32(0x104 + (sp - 300));
                                                                r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                r4 = LD32(r10);
                                                                r5 = R(5);
                                                                r6 = R(6);
                                                                r7 = R(7);
                                                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                ST32(r10, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    r1 = LD8(r4);
                                                    r1 = r1 & 255;
                                                    while (!((r1 & r1) == 0)) {
                                                        r4 = r4 + 1;
                                                        r1 = LD8(r4);
                                                        c26 = (r1 & 255) == 38;
                                                        r1 = r1 & 255;
                                                        if (!(c26)) {
                                                            POLL();
                                                            continue;
                                                        } else {
                                                            break;
                                                        }
                                                        POLL();
                                                    }
                                                    r1 = LD8(r4);
                                                    r0 = r1 & 255;
                                                    r1 = 0;
                                                    if (!(r0 == 38)) {
                                                        break;
                                                    } else {
                                                        ST8(r4, r1);
                                                        r11 = r4 + 9;
                                                        r1 = LD8(r11);
                                                        r4 = r11;
                                                        while (!((r1 & 255) == 38)) {
                                                            POLL();
                                                            r1 = LD8(r4);
                                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                break;
                                                            } else {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                            }
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r14 = r4 + 6;
                                                            r10 = r10 + 104;
                                                            r4 = LD32(r10);
                                                            r0 = GCALL1(0x06027F48, r4);
                                                            r4 = LD32((0x104 + (sp - 296)));
                                                            r0 = GCALL1(0x0607507C, r4);
                                                            r8 = r0;
                                                            r0 = GCALL1(0x0607507C, r11);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, r14);
                                                            r8 = r8 + r0;
                                                            r0 = GCALL1(0x0607507C, 0x060408C8);
                                                            r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                            r1 = r0;
                                                            ST32(r10, r1);
                                                            if ((r1 & r1) == 0) {
                                                                break;
                                                            } else {
                                                                ST32((sp - 300), r14);
                                                                r6 = LD32((0x108 + (sp - 300)));
                                                                r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                r6 = LD32(r10);
                                                                r5 = LD32(0x104 + (sp - 300));
                                                                r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                r4 = LD32(r10);
                                                                r5 = R(5);
                                                                r6 = R(6);
                                                                r7 = R(7);
                                                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                ST32(r10, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                    } else {
                                        r8 = 0x060408E4;
                                        r0 = GCALL1(0x0607507C, 0x060408E4);
                                        r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                        r1 = r0;
                                        r0 = LD32((0x100 + (sp - 296)));
                                        ST32(r0, r1);
                                        if (!((r1 & r1) == 0)) {
                                            r0 = GCALL2(0x06045264, r1, r8);
                                            r8 = r10;
                                            r8 = r8 + 104;
                                            r4 = LD32(r8);
                                            if ((r4 & r4) == 0) {
                                                break;
                                            } else {
                                                r0 = GCALL1(0x06027F48, r4);
                                                ST32(r8, 0);
                                                break;
                                            }
                                        } else {
                                            r1 = LD32(r13 + 52);
                                            if (!((r1 & r1) == 0)) {
                                                SETIN(0, r0);
                                                r0 = GCALL1(r1, -3);
                                                break;
                                            } else {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        return r0;
                    } else {
                        r1 = LD8(r8);
                    }
                    r0 = r1 & 255;
                    r1 = r1 & 255;
                    if (!(r0 == 61)) {
                        POLL();
                        if (!((r1 & r1) == 0)) {
                            r8 = r8 + 1;
                            while (1) {
                                r1 = LD8(r8);
                                r0 = r1 & 255;
                                r1 = r1 & 255;
                                if (!(r0 == 61)) {
                                    POLL();
                                    if ((r1 & r1) == 0) {
                                        r8 = r8 + 1;
                                        r1 = LD8(r8);
                                        if (((r1 & 255) & (r1 & 255)) == 0) {
                                            r2 = -608;
                                            if (!((r2 & r2) == 0)) {
                                                r1 = LD32(r13 + 52);
                                                if ((r1 & r1) == 0) {
                                                    r4 = LD32((r10 + 104));
                                                    c23 = (r4 & r4) == 0;
                                                    r4 = r4 + 9;
                                                    if (!(c23)) {
                                                        ST32((0x104 + (sp - 296)), r4);
                                                        r4 = LD32((0x104 + (sp - 296)));
                                                        r0 = LD32((0x104 + (sp - 296)));
                                                        r1 = LD8(r0);
                                                        if ((r1 & 255) == 38) {
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r11 = r4 + 9;
                                                                r1 = LD8(r11);
                                                                r4 = r11;
                                                                while (!((r1 & 255) == 38)) {
                                                                    POLL();
                                                                    r1 = LD8(r4);
                                                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r4 = r4 + 1;
                                                                        r1 = LD8(r4);
                                                                    }
                                                                }
                                                                r1 = LD8(r4);
                                                                r0 = r1 & 255;
                                                                r1 = 0;
                                                                if (!(r0 == 38)) {
                                                                    break;
                                                                } else {
                                                                    ST8(r4, r1);
                                                                    r14 = r4 + 6;
                                                                    r10 = r10 + 104;
                                                                    r4 = LD32(r10);
                                                                    r0 = GCALL1(0x06027F48, r4);
                                                                    r4 = LD32((0x104 + (sp - 296)));
                                                                    r0 = GCALL1(0x0607507C, r4);
                                                                    r8 = r0;
                                                                    r0 = GCALL1(0x0607507C, r11);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, r14);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                    r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                    r1 = r0;
                                                                    ST32(r10, r1);
                                                                    if ((r1 & r1) == 0) {
                                                                        break;
                                                                    } else {
                                                                        ST32((sp - 300), r14);
                                                                        r6 = LD32((0x108 + (sp - 300)));
                                                                        r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                        r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                        r6 = LD32(r10);
                                                                        r5 = LD32(0x104 + (sp - 300));
                                                                        r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                        r4 = LD32(r10);
                                                                        r5 = R(5);
                                                                        r6 = R(6);
                                                                        r7 = R(7);
                                                                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                        ST32(r10, 0);
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r1 = LD8(r4);
                                                            r1 = r1 & 255;
                                                            while (!((r1 & r1) == 0)) {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                                c26 = (r1 & 255) == 38;
                                                                r1 = r1 & 255;
                                                                if (!(c26)) {
                                                                    POLL();
                                                                    continue;
                                                                } else {
                                                                    break;
                                                                }
                                                                POLL();
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r11 = r4 + 9;
                                                                r1 = LD8(r11);
                                                                r4 = r11;
                                                                while (!((r1 & 255) == 38)) {
                                                                    POLL();
                                                                    r1 = LD8(r4);
                                                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r4 = r4 + 1;
                                                                        r1 = LD8(r4);
                                                                    }
                                                                }
                                                                r1 = LD8(r4);
                                                                r0 = r1 & 255;
                                                                r1 = 0;
                                                                if (!(r0 == 38)) {
                                                                    break;
                                                                } else {
                                                                    ST8(r4, r1);
                                                                    r14 = r4 + 6;
                                                                    r10 = r10 + 104;
                                                                    r4 = LD32(r10);
                                                                    r0 = GCALL1(0x06027F48, r4);
                                                                    r4 = LD32((0x104 + (sp - 296)));
                                                                    r0 = GCALL1(0x0607507C, r4);
                                                                    r8 = r0;
                                                                    r0 = GCALL1(0x0607507C, r11);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, r14);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                    r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                    r1 = r0;
                                                                    ST32(r10, r1);
                                                                    if ((r1 & r1) == 0) {
                                                                        break;
                                                                    } else {
                                                                        ST32((sp - 300), r14);
                                                                        r6 = LD32((0x108 + (sp - 300)));
                                                                        r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                        r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                        r6 = LD32(r10);
                                                                        r5 = LD32(0x104 + (sp - 300));
                                                                        r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                        r4 = LD32(r10);
                                                                        r5 = R(5);
                                                                        r6 = R(6);
                                                                        r7 = R(7);
                                                                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                        ST32(r10, 0);
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                } else {
                                                    SETIN(0, r0);
                                                    r0 = GCALL1(r1, r2);
                                                    r4 = LD32((r10 + 104));
                                                    c23 = (r4 & r4) == 0;
                                                    r4 = r4 + 9;
                                                    if (!(c23)) {
                                                        ST32((0x104 + (sp - 296)), r4);
                                                        r4 = LD32((0x104 + (sp - 296)));
                                                        r0 = LD32((0x104 + (sp - 296)));
                                                        r1 = LD8(r0);
                                                        if ((r1 & 255) == 38) {
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r11 = r4 + 9;
                                                                r1 = LD8(r11);
                                                                r4 = r11;
                                                                while (!((r1 & 255) == 38)) {
                                                                    POLL();
                                                                    r1 = LD8(r4);
                                                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r4 = r4 + 1;
                                                                        r1 = LD8(r4);
                                                                    }
                                                                }
                                                                r1 = LD8(r4);
                                                                r0 = r1 & 255;
                                                                r1 = 0;
                                                                if (!(r0 == 38)) {
                                                                    break;
                                                                } else {
                                                                    ST8(r4, r1);
                                                                    r14 = r4 + 6;
                                                                    r10 = r10 + 104;
                                                                    r4 = LD32(r10);
                                                                    r0 = GCALL1(0x06027F48, r4);
                                                                    r4 = LD32((0x104 + (sp - 296)));
                                                                    r0 = GCALL1(0x0607507C, r4);
                                                                    r8 = r0;
                                                                    r0 = GCALL1(0x0607507C, r11);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, r14);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                    r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                    r1 = r0;
                                                                    ST32(r10, r1);
                                                                    if ((r1 & r1) == 0) {
                                                                        break;
                                                                    } else {
                                                                        ST32((sp - 300), r14);
                                                                        r6 = LD32((0x108 + (sp - 300)));
                                                                        r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                        r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                        r6 = LD32(r10);
                                                                        r5 = LD32(0x104 + (sp - 300));
                                                                        r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                        r4 = LD32(r10);
                                                                        r5 = R(5);
                                                                        r6 = R(6);
                                                                        r7 = R(7);
                                                                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                        ST32(r10, 0);
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r1 = LD8(r4);
                                                            r1 = r1 & 255;
                                                            while (!((r1 & r1) == 0)) {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                                c26 = (r1 & 255) == 38;
                                                                r1 = r1 & 255;
                                                                if (!(c26)) {
                                                                    POLL();
                                                                    continue;
                                                                } else {
                                                                    break;
                                                                }
                                                                POLL();
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r11 = r4 + 9;
                                                                r1 = LD8(r11);
                                                                r4 = r11;
                                                                while (!((r1 & 255) == 38)) {
                                                                    POLL();
                                                                    r1 = LD8(r4);
                                                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r4 = r4 + 1;
                                                                        r1 = LD8(r4);
                                                                    }
                                                                }
                                                                r1 = LD8(r4);
                                                                r0 = r1 & 255;
                                                                r1 = 0;
                                                                if (!(r0 == 38)) {
                                                                    break;
                                                                } else {
                                                                    ST8(r4, r1);
                                                                    r14 = r4 + 6;
                                                                    r10 = r10 + 104;
                                                                    r4 = LD32(r10);
                                                                    r0 = GCALL1(0x06027F48, r4);
                                                                    r4 = LD32((0x104 + (sp - 296)));
                                                                    r0 = GCALL1(0x0607507C, r4);
                                                                    r8 = r0;
                                                                    r0 = GCALL1(0x0607507C, r11);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, r14);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                    r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                    r1 = r0;
                                                                    ST32(r10, r1);
                                                                    if ((r1 & r1) == 0) {
                                                                        break;
                                                                    } else {
                                                                        ST32((sp - 300), r14);
                                                                        r6 = LD32((0x108 + (sp - 300)));
                                                                        r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                        r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                        r6 = LD32(r10);
                                                                        r5 = LD32(0x104 + (sp - 300));
                                                                        r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                        r4 = LD32(r10);
                                                                        r5 = R(5);
                                                                        r6 = R(6);
                                                                        r7 = R(7);
                                                                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                        ST32(r10, 0);
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                            } else {
                                                r8 = 0x060408E4;
                                                r0 = GCALL1(0x0607507C, 0x060408E4);
                                                r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                                r1 = r0;
                                                r0 = LD32((0x100 + (sp - 296)));
                                                ST32(r0, r1);
                                                if (!((r1 & r1) == 0)) {
                                                    r0 = GCALL2(0x06045264, r1, r8);
                                                    r8 = r10;
                                                    r8 = r8 + 104;
                                                    r4 = LD32(r8);
                                                    if ((r4 & r4) == 0) {
                                                        break;
                                                    } else {
                                                        r0 = GCALL1(0x06027F48, r4);
                                                        ST32(r8, 0);
                                                        break;
                                                    }
                                                } else {
                                                    r1 = LD32(r13 + 52);
                                                    if (!((r1 & r1) == 0)) {
                                                        SETIN(0, r0);
                                                        r0 = GCALL1(r1, -3);
                                                        break;
                                                    } else {
                                                        break;
                                                    }
                                                }
                                            }
                                        } else {
                                            r0 = GCALL1(0x0603FC68, r8);
                                            c2011 = R(11);
                                            SETR(11, r11);
                                            r0 = GCALL4(0x06049AB0, r13, r11, r9, r8);
                                            SETR(11, c2011);
                                            r2 = r0;
                                            if (!((r2 & r2) == 0)) {
                                                r1 = LD32(r13 + 52);
                                                if ((r1 & r1) == 0) {
                                                    r4 = LD32((r10 + 104));
                                                    c23 = (r4 & r4) == 0;
                                                    r4 = r4 + 9;
                                                    if (!(c23)) {
                                                        ST32((0x104 + (sp - 296)), r4);
                                                        r4 = LD32((0x104 + (sp - 296)));
                                                        r0 = LD32((0x104 + (sp - 296)));
                                                        r1 = LD8(r0);
                                                        if ((r1 & 255) == 38) {
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r11 = r4 + 9;
                                                                r1 = LD8(r11);
                                                                r4 = r11;
                                                                while (!((r1 & 255) == 38)) {
                                                                    POLL();
                                                                    r1 = LD8(r4);
                                                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r4 = r4 + 1;
                                                                        r1 = LD8(r4);
                                                                    }
                                                                }
                                                                r1 = LD8(r4);
                                                                r0 = r1 & 255;
                                                                r1 = 0;
                                                                if (!(r0 == 38)) {
                                                                    break;
                                                                } else {
                                                                    ST8(r4, r1);
                                                                    r14 = r4 + 6;
                                                                    r10 = r10 + 104;
                                                                    r4 = LD32(r10);
                                                                    r0 = GCALL1(0x06027F48, r4);
                                                                    r4 = LD32((0x104 + (sp - 296)));
                                                                    r0 = GCALL1(0x0607507C, r4);
                                                                    r8 = r0;
                                                                    r0 = GCALL1(0x0607507C, r11);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, r14);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                    r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                    r1 = r0;
                                                                    ST32(r10, r1);
                                                                    if ((r1 & r1) == 0) {
                                                                        break;
                                                                    } else {
                                                                        ST32((sp - 300), r14);
                                                                        r6 = LD32((0x108 + (sp - 300)));
                                                                        r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                        r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                        r6 = LD32(r10);
                                                                        r5 = LD32(0x104 + (sp - 300));
                                                                        r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                        r4 = LD32(r10);
                                                                        r5 = R(5);
                                                                        r6 = R(6);
                                                                        r7 = R(7);
                                                                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                        ST32(r10, 0);
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r1 = LD8(r4);
                                                            r1 = r1 & 255;
                                                            while (!((r1 & r1) == 0)) {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                                c26 = (r1 & 255) == 38;
                                                                r1 = r1 & 255;
                                                                if (!(c26)) {
                                                                    POLL();
                                                                    continue;
                                                                } else {
                                                                    break;
                                                                }
                                                                POLL();
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r11 = r4 + 9;
                                                                r1 = LD8(r11);
                                                                r4 = r11;
                                                                while (!((r1 & 255) == 38)) {
                                                                    POLL();
                                                                    r1 = LD8(r4);
                                                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r4 = r4 + 1;
                                                                        r1 = LD8(r4);
                                                                    }
                                                                }
                                                                r1 = LD8(r4);
                                                                r0 = r1 & 255;
                                                                r1 = 0;
                                                                if (!(r0 == 38)) {
                                                                    break;
                                                                } else {
                                                                    ST8(r4, r1);
                                                                    r14 = r4 + 6;
                                                                    r10 = r10 + 104;
                                                                    r4 = LD32(r10);
                                                                    r0 = GCALL1(0x06027F48, r4);
                                                                    r4 = LD32((0x104 + (sp - 296)));
                                                                    r0 = GCALL1(0x0607507C, r4);
                                                                    r8 = r0;
                                                                    r0 = GCALL1(0x0607507C, r11);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, r14);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                    r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                    r1 = r0;
                                                                    ST32(r10, r1);
                                                                    if ((r1 & r1) == 0) {
                                                                        break;
                                                                    } else {
                                                                        ST32((sp - 300), r14);
                                                                        r6 = LD32((0x108 + (sp - 300)));
                                                                        r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                        r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                        r6 = LD32(r10);
                                                                        r5 = LD32(0x104 + (sp - 300));
                                                                        r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                        r4 = LD32(r10);
                                                                        r5 = R(5);
                                                                        r6 = R(6);
                                                                        r7 = R(7);
                                                                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                        ST32(r10, 0);
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                } else {
                                                    SETIN(0, r0);
                                                    r0 = GCALL1(r1, r2);
                                                    r4 = LD32((r10 + 104));
                                                    c23 = (r4 & r4) == 0;
                                                    r4 = r4 + 9;
                                                    if (!(c23)) {
                                                        ST32((0x104 + (sp - 296)), r4);
                                                        r4 = LD32((0x104 + (sp - 296)));
                                                        r0 = LD32((0x104 + (sp - 296)));
                                                        r1 = LD8(r0);
                                                        if ((r1 & 255) == 38) {
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r11 = r4 + 9;
                                                                r1 = LD8(r11);
                                                                r4 = r11;
                                                                while (!((r1 & 255) == 38)) {
                                                                    POLL();
                                                                    r1 = LD8(r4);
                                                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r4 = r4 + 1;
                                                                        r1 = LD8(r4);
                                                                    }
                                                                }
                                                                r1 = LD8(r4);
                                                                r0 = r1 & 255;
                                                                r1 = 0;
                                                                if (!(r0 == 38)) {
                                                                    break;
                                                                } else {
                                                                    ST8(r4, r1);
                                                                    r14 = r4 + 6;
                                                                    r10 = r10 + 104;
                                                                    r4 = LD32(r10);
                                                                    r0 = GCALL1(0x06027F48, r4);
                                                                    r4 = LD32((0x104 + (sp - 296)));
                                                                    r0 = GCALL1(0x0607507C, r4);
                                                                    r8 = r0;
                                                                    r0 = GCALL1(0x0607507C, r11);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, r14);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                    r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                    r1 = r0;
                                                                    ST32(r10, r1);
                                                                    if ((r1 & r1) == 0) {
                                                                        break;
                                                                    } else {
                                                                        ST32((sp - 300), r14);
                                                                        r6 = LD32((0x108 + (sp - 300)));
                                                                        r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                        r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                        r6 = LD32(r10);
                                                                        r5 = LD32(0x104 + (sp - 300));
                                                                        r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                        r4 = LD32(r10);
                                                                        r5 = R(5);
                                                                        r6 = R(6);
                                                                        r7 = R(7);
                                                                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                        ST32(r10, 0);
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r1 = LD8(r4);
                                                            r1 = r1 & 255;
                                                            while (!((r1 & r1) == 0)) {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                                c26 = (r1 & 255) == 38;
                                                                r1 = r1 & 255;
                                                                if (!(c26)) {
                                                                    POLL();
                                                                    continue;
                                                                } else {
                                                                    break;
                                                                }
                                                                POLL();
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r11 = r4 + 9;
                                                                r1 = LD8(r11);
                                                                r4 = r11;
                                                                while (!((r1 & 255) == 38)) {
                                                                    POLL();
                                                                    r1 = LD8(r4);
                                                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                        break;
                                                                    } else {
                                                                        r4 = r4 + 1;
                                                                        r1 = LD8(r4);
                                                                    }
                                                                }
                                                                r1 = LD8(r4);
                                                                r0 = r1 & 255;
                                                                r1 = 0;
                                                                if (!(r0 == 38)) {
                                                                    break;
                                                                } else {
                                                                    ST8(r4, r1);
                                                                    r14 = r4 + 6;
                                                                    r10 = r10 + 104;
                                                                    r4 = LD32(r10);
                                                                    r0 = GCALL1(0x06027F48, r4);
                                                                    r4 = LD32((0x104 + (sp - 296)));
                                                                    r0 = GCALL1(0x0607507C, r4);
                                                                    r8 = r0;
                                                                    r0 = GCALL1(0x0607507C, r11);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, r14);
                                                                    r8 = r8 + r0;
                                                                    r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                    r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                    r1 = r0;
                                                                    ST32(r10, r1);
                                                                    if ((r1 & r1) == 0) {
                                                                        break;
                                                                    } else {
                                                                        ST32((sp - 300), r14);
                                                                        r6 = LD32((0x108 + (sp - 300)));
                                                                        r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                        r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                        r6 = LD32(r10);
                                                                        r5 = LD32(0x104 + (sp - 300));
                                                                        r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                        r4 = LD32(r10);
                                                                        r5 = R(5);
                                                                        r6 = R(6);
                                                                        r7 = R(7);
                                                                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                        ST32(r10, 0);
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                            } else {
                                                r8 = 0x060408E4;
                                                r0 = GCALL1(0x0607507C, 0x060408E4);
                                                r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                                r1 = r0;
                                                r0 = LD32((0x100 + (sp - 296)));
                                                ST32(r0, r1);
                                                if (!((r1 & r1) == 0)) {
                                                    r0 = GCALL2(0x06045264, r1, r8);
                                                    r8 = r10;
                                                    r8 = r8 + 104;
                                                    r4 = LD32(r8);
                                                    if ((r4 & r4) == 0) {
                                                        break;
                                                    } else {
                                                        r0 = GCALL1(0x06027F48, r4);
                                                        ST32(r8, 0);
                                                        break;
                                                    }
                                                } else {
                                                    r1 = LD32(r13 + 52);
                                                    if (!((r1 & r1) == 0)) {
                                                        SETIN(0, r0);
                                                        r0 = GCALL1(r1, -3);
                                                        break;
                                                    } else {
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        r8 = r8 + 1;
                                        continue;
                                    }
                                } else {
                                    r8 = r8 + 1;
                                    r1 = LD8(r8);
                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                        r2 = -608;
                                        if (!((r2 & r2) == 0)) {
                                            r1 = LD32(r13 + 52);
                                            if ((r1 & r1) == 0) {
                                                r4 = LD32((r10 + 104));
                                                c23 = (r4 & r4) == 0;
                                                r4 = r4 + 9;
                                                if (!(c23)) {
                                                    ST32((0x104 + (sp - 296)), r4);
                                                    r4 = LD32((0x104 + (sp - 296)));
                                                    r0 = LD32((0x104 + (sp - 296)));
                                                    r1 = LD8(r0);
                                                    if ((r1 & 255) == 38) {
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r1 = LD8(r4);
                                                        r1 = r1 & 255;
                                                        while (!((r1 & r1) == 0)) {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                            if (!(c26)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                break;
                                                            }
                                                            POLL();
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            } else {
                                                SETIN(0, r0);
                                                r0 = GCALL1(r1, r2);
                                                r4 = LD32((r10 + 104));
                                                c23 = (r4 & r4) == 0;
                                                r4 = r4 + 9;
                                                if (!(c23)) {
                                                    ST32((0x104 + (sp - 296)), r4);
                                                    r4 = LD32((0x104 + (sp - 296)));
                                                    r0 = LD32((0x104 + (sp - 296)));
                                                    r1 = LD8(r0);
                                                    if ((r1 & 255) == 38) {
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r1 = LD8(r4);
                                                        r1 = r1 & 255;
                                                        while (!((r1 & r1) == 0)) {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                            if (!(c26)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                break;
                                                            }
                                                            POLL();
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            }
                                        } else {
                                            r8 = 0x060408E4;
                                            r0 = GCALL1(0x0607507C, 0x060408E4);
                                            r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                            r1 = r0;
                                            r0 = LD32((0x100 + (sp - 296)));
                                            ST32(r0, r1);
                                            if (!((r1 & r1) == 0)) {
                                                r0 = GCALL2(0x06045264, r1, r8);
                                                r8 = r10;
                                                r8 = r8 + 104;
                                                r4 = LD32(r8);
                                                if ((r4 & r4) == 0) {
                                                    break;
                                                } else {
                                                    r0 = GCALL1(0x06027F48, r4);
                                                    ST32(r8, 0);
                                                    break;
                                                }
                                            } else {
                                                r1 = LD32(r13 + 52);
                                                if (!((r1 & r1) == 0)) {
                                                    SETIN(0, r0);
                                                    r0 = GCALL1(r1, -3);
                                                    break;
                                                } else {
                                                    break;
                                                }
                                            }
                                        }
                                    } else {
                                        r0 = GCALL1(0x0603FC68, r8);
                                        c2011 = R(11);
                                        SETR(11, r11);
                                        r0 = GCALL4(0x06049AB0, r13, r11, r9, r8);
                                        SETR(11, c2011);
                                        r2 = r0;
                                        if (!((r2 & r2) == 0)) {
                                            r1 = LD32(r13 + 52);
                                            if ((r1 & r1) == 0) {
                                                r4 = LD32((r10 + 104));
                                                c23 = (r4 & r4) == 0;
                                                r4 = r4 + 9;
                                                if (!(c23)) {
                                                    ST32((0x104 + (sp - 296)), r4);
                                                    r4 = LD32((0x104 + (sp - 296)));
                                                    r0 = LD32((0x104 + (sp - 296)));
                                                    r1 = LD8(r0);
                                                    if ((r1 & 255) == 38) {
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r1 = LD8(r4);
                                                        r1 = r1 & 255;
                                                        while (!((r1 & r1) == 0)) {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                            if (!(c26)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                break;
                                                            }
                                                            POLL();
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            } else {
                                                SETIN(0, r0);
                                                r0 = GCALL1(r1, r2);
                                                r4 = LD32((r10 + 104));
                                                c23 = (r4 & r4) == 0;
                                                r4 = r4 + 9;
                                                if (!(c23)) {
                                                    ST32((0x104 + (sp - 296)), r4);
                                                    r4 = LD32((0x104 + (sp - 296)));
                                                    r0 = LD32((0x104 + (sp - 296)));
                                                    r1 = LD8(r0);
                                                    if ((r1 & 255) == 38) {
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r1 = LD8(r4);
                                                        r1 = r1 & 255;
                                                        while (!((r1 & r1) == 0)) {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                            if (!(c26)) {
                                                                POLL();
                                                                continue;
                                                            } else {
                                                                break;
                                                            }
                                                            POLL();
                                                        }
                                                        r1 = LD8(r4);
                                                        r0 = r1 & 255;
                                                        r1 = 0;
                                                        if (!(r0 == 38)) {
                                                            break;
                                                        } else {
                                                            ST8(r4, r1);
                                                            r11 = r4 + 9;
                                                            r1 = LD8(r11);
                                                            r4 = r11;
                                                            while (!((r1 & 255) == 38)) {
                                                                POLL();
                                                                r1 = LD8(r4);
                                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                                    break;
                                                                } else {
                                                                    r4 = r4 + 1;
                                                                    r1 = LD8(r4);
                                                                }
                                                            }
                                                            r1 = LD8(r4);
                                                            r0 = r1 & 255;
                                                            r1 = 0;
                                                            if (!(r0 == 38)) {
                                                                break;
                                                            } else {
                                                                ST8(r4, r1);
                                                                r14 = r4 + 6;
                                                                r10 = r10 + 104;
                                                                r4 = LD32(r10);
                                                                r0 = GCALL1(0x06027F48, r4);
                                                                r4 = LD32((0x104 + (sp - 296)));
                                                                r0 = GCALL1(0x0607507C, r4);
                                                                r8 = r0;
                                                                r0 = GCALL1(0x0607507C, r11);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, r14);
                                                                r8 = r8 + r0;
                                                                r0 = GCALL1(0x0607507C, 0x060408C8);
                                                                r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                                                r1 = r0;
                                                                ST32(r10, r1);
                                                                if ((r1 & r1) == 0) {
                                                                    break;
                                                                } else {
                                                                    ST32((sp - 300), r14);
                                                                    r6 = LD32((0x108 + (sp - 300)));
                                                                    r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                                                    r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                                                    r6 = LD32(r10);
                                                                    r5 = LD32(0x104 + (sp - 300));
                                                                    r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                                                    r4 = LD32(r10);
                                                                    r5 = R(5);
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                                                    ST32(r10, 0);
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    break;
                                                }
                                            }
                                        } else {
                                            r8 = 0x060408E4;
                                            r0 = GCALL1(0x0607507C, 0x060408E4);
                                            r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                            r1 = r0;
                                            r0 = LD32((0x100 + (sp - 296)));
                                            ST32(r0, r1);
                                            if (!((r1 & r1) == 0)) {
                                                r0 = GCALL2(0x06045264, r1, r8);
                                                r8 = r10;
                                                r8 = r8 + 104;
                                                r4 = LD32(r8);
                                                if ((r4 & r4) == 0) {
                                                    break;
                                                } else {
                                                    r0 = GCALL1(0x06027F48, r4);
                                                    ST32(r8, 0);
                                                    break;
                                                }
                                            } else {
                                                r1 = LD32(r13 + 52);
                                                if (!((r1 & r1) == 0)) {
                                                    SETIN(0, r0);
                                                    r0 = GCALL1(r1, -3);
                                                    break;
                                                } else {
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            return r0;
                        }
                    }
                    r8 = r8 + 1;
                    r1 = LD8(r8);
                    if (((r1 & 255) & (r1 & 255)) == 0) {
                        r2 = -608;
                    } else {
                        r0 = GCALL1(0x0603FC68, r8);
                        c2011 = R(11);
                        SETR(11, r11);
                        r0 = GCALL4(0x06049AB0, r13, r11, r9, r8);
                        SETR(11, c2011);
                        r2 = r0;
                    }
                    if (!((r2 & r2) == 0)) {
                        r1 = LD32(r13 + 52);
                        if (!((r1 & r1) == 0)) {
                            SETIN(0, r0);
                            r0 = GCALL1(r1, r2);
                        }
                        r4 = LD32((r10 + 104));
                        c23 = (r4 & r4) == 0;
                        r4 = r4 + 9;
                        if (!(c23)) {
                            ST32((0x104 + (sp - 296)), r4);
                            r4 = LD32((0x104 + (sp - 296)));
                            r0 = LD32((0x104 + (sp - 296)));
                            r1 = LD8(r0);
                            if (!((r1 & 255) == 38)) {
                                r1 = LD8(r4);
                                r1 = r1 & 255;
                                while (!((r1 & r1) == 0)) {
                                    r4 = r4 + 1;
                                    r1 = LD8(r4);
                                    c26 = (r1 & 255) == 38;
                                    r1 = r1 & 255;
                                    if (!(c26)) {
                                        POLL();
                                        continue;
                                    } else {
                                        break;
                                    }
                                    POLL();
                                }
                            }
                            r1 = LD8(r4);
                            r0 = r1 & 255;
                            r1 = 0;
                            if (r0 == 38) {
                                ST8(r4, r1);
                                r11 = r4 + 9;
                                r1 = LD8(r11);
                                r4 = r11;
                                while (!((r1 & 255) == 38)) {
                                    POLL();
                                    r1 = LD8(r4);
                                    if (((r1 & 255) & (r1 & 255)) == 0) {
                                        break;
                                    } else {
                                        r4 = r4 + 1;
                                        r1 = LD8(r4);
                                    }
                                }
                                r1 = LD8(r4);
                                r0 = r1 & 255;
                                r1 = 0;
                                if (r0 == 38) {
                                    ST8(r4, r1);
                                    r14 = r4 + 6;
                                    r10 = r10 + 104;
                                    r4 = LD32(r10);
                                    r0 = GCALL1(0x06027F48, r4);
                                    r4 = LD32((0x104 + (sp - 296)));
                                    r0 = GCALL1(0x0607507C, r4);
                                    r8 = r0;
                                    r0 = GCALL1(0x0607507C, r11);
                                    r8 = r8 + r0;
                                    r0 = GCALL1(0x0607507C, r14);
                                    r8 = r8 + r0;
                                    r0 = GCALL1(0x0607507C, 0x060408C8);
                                    r0 = GCALL4(0x060279E0, 0, ((r8 + r0) + 1), -1, 1);
                                    r1 = r0;
                                    ST32(r10, r1);
                                    if (!((r1 & r1) == 0)) {
                                        ST32((sp - 300), r14);
                                        r6 = LD32((0x108 + (sp - 300)));
                                        r0 = GCALL5(0x06045264, r1, 0x060408C8, r6, r11, LD32((sp - 300)));
                                        r0 = GCALL5(0x060408C4, 0, 0, 0, 0, LD32((sp - 300)));
                                        r6 = LD32(r10);
                                        r5 = LD32(0x104 + (sp - 300));
                                        r0 = GCALL5(0x0603FD18, 0, r5, r6, 4, LD32((sp - 300)));
                                        r4 = LD32(r10);
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 300)));
                                        ST32(r10, 0);
                                    }
                                }
                            }
                        }
                    } else {
                        r8 = 0x060408E4;
                        r0 = GCALL1(0x0607507C, 0x060408E4);
                        r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                        r1 = r0;
                        r0 = LD32((0x100 + (sp - 296)));
                        ST32(r0, r1);
                        if (!((r1 & r1) == 0)) {
                            r0 = GCALL2(0x06045264, r1, r8);
                            r8 = r10;
                            r8 = r8 + 104;
                            r4 = LD32(r8);
                            if (!((r4 & r4) == 0)) {
                                r0 = GCALL1(0x06027F48, r4);
                                ST32(r8, 0);
                            }
                        } else {
                            r1 = LD32(r13 + 52);
                            if (!((r1 & r1) == 0)) {
                                SETIN(0, r0);
                                r0 = GCALL1(r1, -3);
                            }
                        }
                    }
                } else {
                    r1 = LD32(r13 + 52);
                    if (!((r1 & r1) == 0)) {
                        SETIN(0, r0);
                        r0 = GCALL1(r1, -605);
                    }
                }
            }
        } else {
            r1 = LD32(r13 + 52);
            if (!((r1 & r1) == 0)) {
                SETIN(0, r0);
                r0 = GCALL4(r1, -1, r5, r6, r7);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06040D7C(int r4, int r5, int r6)
{
    int r0, r1, r2, r7, r8, r9, r10, r11, r12, c4, c14, c15;
    FRAME(sp, 328);

    r10 = r4;
    r12 = r5;
    r11 = r6;
    r8 = r12 + 108;
    r4 = LD32(r8);
    r9 = 0x060752FC;
    r0 = GCALL3(0x060752FC, r4, 0x06040CE0, 9);
    if (!((r0 & r0) == 0)) {
        goto L06040DAC;
    }
    r6 = LD32(r10 + 24);
    r1 = 0x0603FD18;
    r7 = 1;
    goto L06040DD2;
    L06040DAC:
    r4 = LD32(r8);
    SETIN(0, r0);
    r0 = GCALL3(r9, r4, 0x06040CEC, 12);
    if (!((r0 & r0) == 0)) {
        goto L06040DC0;
    }
    r6 = LD32(r10 + 24);
    r1 = 0x0603FD18;
    r7 = 2;
    goto L06040DD2;
    L06040DC0:
    r4 = LD32(r8);
    SETIN(0, r0);
    r0 = GCALL3(r9, r4, 0x06040CFC, 11);
    if (!((r0 & r0) == 0)) {
        goto L06040DDC;
    }
    r6 = LD32(r10 + 24);
    r1 = 0x0603FD18;
    r7 = 0;
    L06040DD2:
    SETIN(0, r0);
    r0 = GCALL4(r1, r10, r11, r6, r7);
    r1 = LD32(r10);
    goto L0604102C;
    L06040DDC:
    r4 = LD32(r8);
    SETIN(0, r0);
    r0 = GCALL3(r9, r4, 0x06040D08, 8);
    r6 = -1;
    if (!((r0 & r0) == 0)) {
        goto L06040DF0;
    }
    r1 = 0x06040704;
    r5 = r11;
    goto L06040E46;
    L06040DF0:
    r4 = LD32(r8);
    SETIN(0, r0);
    r0 = GCALL3(r9, r4, 0x06040D14, 12);
    c4 = (r0 & r0) == 0;
    r6 = c4;
    if (!(c4)) {
        goto L06040E04;
    }
    r1 = 0x06040704;
    r5 = r11;
    goto L06040E46;
    L06040E04:
    r4 = LD32(r8);
    SETIN(0, r0);
    r0 = GCALL3(r9, r4, 0x06040D24, 6);
    if (!((r0 & r0) == 0)) {
        goto L06040E20;
    }
    r4 = LD32(r12);
    r0 = GCALL1(0x0604034C, r4);
    ST32(r10 + 16, r0);
    r1 = 0x06040704;
    r6 = 0;
    r5 = r11;
    goto L06040E46;
    L06040E20:
    r4 = LD32(r8);
    SETIN(0, r0);
    r0 = GCALL3(r9, r4, 0x06040D2C, 10);
    r6 = r11;
    if (!((r0 & r0) == 0)) {
        goto L06040E34;
    }
    r1 = 0x060407B0;
    goto L06040E44;
    L06040E34:
    r4 = LD32(r8);
    SETIN(0, r0);
    r0 = GCALL3(r9, r4, 0x06040D38, 11);
    r6 = r11;
    if (!((r0 & r0) == 0)) {
        goto L06040E88;
    }
    r1 = 0x06040A04;
    L06040E44:
    r5 = r12;
    L06040E46:
    SETIN(0, r0);
    r0 = GCALL3(r1, r10, r5, r6);
    r1 = LD32(r10);
    goto L0604102C;
    L06040E88:
    r4 = LD32(r8);
    SETIN(0, r0);
    r0 = GCALL3(r9, r4, 0x06040D44, 7);
    if (!((r0 & r0) == 0)) {
        goto L06040F20;
    }
    r5 = LD32(r10 + 24);
    if (!((r5 & r5) == 0)) {
        goto L06040E9E;
    }
    goto L0604102A;
    L06040E9E:
    r1 = LD32(r10 + 48);
    if (!((r1 & r1) == 0)) {
        goto L06040EA8;
    }
    goto L0604102A;
    L06040EA8:
    r0 = GCALL2(0x0603F318, ((sp - 328) + 0x100), r5);
    r8 = LD32(0x108 + (sp - 328));
    r11 = 0;
    if (!((r8 & r8) == 0)) {
        goto L06040EC2;
    }
    goto L0604102A;
    L06040EC2:
    r1 = LD8(r8);
    goto L06040ECE;
    L06040EC6:
    if ((r1 & r1) == 0) {
        goto L06040EE0;
    }
    r8 = r8 + 1;
    r1 = LD8(r8);
    L06040ECE:
    r0 = r1 & 255;
    c14 = r0 == 13;
    if (r0 == 10) {
        goto L06040EE0;
    }
    c15 = r0 == 60;
    if (c14) {
        goto L06040EE0;
    }
    r1 = r1 & 255;
    if (!(c15)) {
        POLL();
        goto L06040EC6;
    }
    L06040EE0:
    r1 = LD8(r8);
    r8 = r8 + 1;
    if ((r1 & 255) == 60) {
        goto L06040EEE;
    }
    goto L0604102A;
    L06040EEE:
    ST8(sp - 328, r11);
    r2 = LD8(r8);
    r9 = 0;
    if ((r2 & 255) == 62) {
        goto L06040F12;
    }
    r1 = r2 & 255;
    L06040EFC:
    r0 = sp - 328;
    if ((r1 & r1) == 0) {
        goto L06040F12;
    }
    ST8(r0 + r9, r2);
    r8 = r8 + 1;
    r2 = LD8(r8);
    r1 = r2 & 255;
    r9 = r9 + 1;
    if (!(r1 == 62)) {
        POLL();
        goto L06040EFC;
    }
    L06040F12:
    r0 = sp - 328;
    ST8(r0 + r9, r11);
    r1 = LD32(r10 + 48);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r1, (sp - 328), r5, r6, r7, LD32((sp - 328)));
    r1 = LD8(r8);
    POLL();
    goto L06040ECE;
    L06040F20:
    r8 = r12 + 108;
    r4 = LD32(r8);
    r0 = GCALL5(0x060752FC, r4, 0x06040D4C, 11, 0, LD32((sp - 328)));
    r9 = 0;
    SETIN(6, 11);
    if (!((r0 & r0) == 0)) {
        goto L06040F3E;
    }
    r4 = LD32(r8);
    r0 = GCALL5(0x06075438, (r4 + 11), 0, 0, 0, LD32((sp - 328)));
    r9 = r0;
    L06040F3E:
    r4 = LD32(r10 + 4);
    if ((r4 & r4) == 0) {
        goto L06040FC6;
    }
    r1 = LD32(r10 + 20);
    r6 = r9;
    if (!(r9 == r1)) {
        goto L06040FBC;
    }
    r7 = R(7);
    r0 = GCALL5(0x06045264, (sp - 328), 0x06040D58, r6, 0, LD32((sp - 328)));
    r1 = LD32(r10 + 44);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r1, (sp - 328), r5, r6, r7, LD32((sp - 328)));
    r12 = 0x0607507C;
    r4 = LD32(r10 + 4);
    r0 = GCALL5(0x0607507C, r4, 0, 0, 0, LD32((sp - 328)));
    r0 = GCALL5(0x060279E0, 0, (r0 + 1), -1, 1, LD32((sp - 328)));
    r9 = r0;
    ST32(r11, r9);
    if ((r9 & r9) == 0) {
        goto L06041006;
    }
    r8 = LD32(r10 + 4);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r12, r8, r5, r6, r7, LD32((sp - 328)));
    r0 = GCALL5(0x0604B358, r9, r8, (r0 + 1), 0, LD32((sp - 328)));
    ST32(r10 + 16, -1);
    goto L06041044;
    L06040FBC:
    r5 = R(5);
    r7 = R(7);
    r0 = GCALL5(0x06027F48, r4, r5, r6, 0, LD32((sp - 328)));
    ST32(r10 + 4, 0);
    L06040FC6:
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL5(0x0603F42C, r10, r9, 0, 0, LD32((sp - 328)));
    r2 = r0;
    if (!(r2 >= 0)) {
        goto L06041020;
    }
    r1 = LD32(r10 + 44);
    r6 = r9;
    SETIN(6, r6);
    if ((r1 & r1) == 0) {
        goto L0604102A;
    }
    r7 = R(7);
    r0 = GCALL5(0x06045264, (sp - 328), 0x06040D58, r6, 0, LD32((sp - 328)));
    r1 = LD32(r10 + 44);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r1, (sp - 328), r5, r6, r7, LD32((sp - 328)));
    r12 = 0x0607507C;
    r4 = LD32(r10 + 4);
    r0 = GCALL5(0x0607507C, r4, 0, 0, 0, LD32((sp - 328)));
    r0 = GCALL5(0x060279E0, 0, (r0 + 1), -1, 1, LD32((sp - 328)));
    r9 = r0;
    ST32(r11, r9);
    if (!((r9 & r9) == 0)) {
        goto L0604100A;
    }
    L06041006:
    r0 = -3;
    goto L06041046;
    L0604100A:
    r8 = LD32(r10 + 4);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r12, r8, r5, r6, r7, LD32((sp - 328)));
    r0 = GCALL5(0x0604B358, r9, r8, (r0 + 1), 0, LD32((sp - 328)));
    r1 = LD32(r10);
    goto L0604102C;
    L06041020:
    r1 = LD32(r10 + 52);
    if ((r1 & r1) == 0) {
        goto L0604102A;
    }
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r1, r2, r5, r6, r7, LD32((sp - 328)));
    L0604102A:
    r1 = LD32(r10);
    L0604102C:
    r0 = 0;
    if (!(r1 >= 0)) {
        goto L06041046;
    }
    r1 = LD32(r10 + 40);
    if ((r1 & r1) == 0) {
        goto L0604103E;
    }
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r1, 0x06040D70, 99, r6, r7, LD32((sp - 328)));
    L0604103E:
    r0 = GCALL5(0x060496CC, r10, 0, 0, 0, LD32((sp - 328)));
    L06041044:
    r0 = 0;
    L06041046:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06041410(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14, c1012, c1016, c2011;
    FRAME(sp, 64);

    ST32(sp - 52, r4);
    r12 = r5;
    ST32(sp - 48, r6);
    ST32(sp - 64, 0);
    ST32(sp - 60, 0);
    r3 = LD32(sp - 48);
    r8 = 0x219;
    ST32(r3, 0);
    ST32(sp - 56, 0);
    ST32(0x06079164, sp - 64);
    ST32(0x06079174, (sp - 60));
    ST32(0x060791A4, (sp - 56));
    ST32(sp - 36, r12);
    r0 = GCALL8(0x060279E0, 0, 0x219, -1, 1, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
    ST32(sp - 40, r0);
    if (!((r0 & r0) == 0)) {
        r4 = LD32(sp - 40);
        r0 = GCALL8(0x0604B358, r4, 0x0608AD40, r8, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
        ST32(sp - 44, 0);
        r3 = LD32(sp - 36);
        r14 = LD32(sp - 52);
        if (!(r3 > 0)) {
            r3 = LD32(sp - 44);
            r4 = LD32(sp - 56);
            if (!((r3 & r3) == 0)) {
                if (!((r4 & r4) == 0)) {
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                }
            } else {
                r5 = LD32(sp - 40);
                r0 = GCALL8(0x0604B358, 0x0608AD40, r5, 0x219, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                r1 = LD32(sp - 56);
                r3 = LD32(sp - 48);
                ST32(r3, r1);
            }
            r4 = LD32(sp - 40);
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
            r0 = LD32(sp - 44);
        } else {
            r3 = 1;
            while (1) {
                r11 = r14;
                if (!(r12 > r3)) {
                    ST32(sp - 44, -1);
                    r3 = LD32(sp - 44);
                    r4 = LD32(sp - 56);
                    if (!((r3 & r3) == 0)) {
                        if ((r4 & r4) == 0) {
                            r4 = LD32(sp - 40);
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r0 = LD32(sp - 44);
                            break;
                        } else {
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r4 = LD32(sp - 40);
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r0 = LD32(sp - 44);
                            break;
                        }
                    } else {
                        r5 = LD32(sp - 40);
                        r0 = GCALL8(0x0604B358, 0x0608AD40, r5, 0x219, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                        r1 = LD32(sp - 56);
                        r3 = LD32(sp - 48);
                        ST32(r3, r1);
                        r4 = LD32(sp - 40);
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                        r0 = LD32(sp - 44);
                        break;
                    }
                } else {
                    r1 = r11;
                    r2 = LD8(r1);
                    r1 = LD8((r1 + 1));
                    r10 = ((r2 & 255) << 8) | (r1 & 255);
                    r12 = (r12 - 2) - r10;
                    r0 = r10 + 2;
                    r14 = r14 + r0;
                    if (!(r12 > r3)) {
                        ST32(sp - 44, -1);
                        r3 = LD32(sp - 44);
                        r4 = LD32(sp - 56);
                        if (!((r3 & r3) == 0)) {
                            if ((r4 & r4) == 0) {
                                r4 = LD32(sp - 40);
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r0 = LD32(sp - 44);
                                break;
                            } else {
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r4 = LD32(sp - 40);
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r0 = LD32(sp - 44);
                                break;
                            }
                        } else {
                            r5 = LD32(sp - 40);
                            r0 = GCALL8(0x0604B358, 0x0608AD40, r5, 0x219, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r1 = LD32(sp - 56);
                            r3 = LD32(sp - 48);
                            ST32(r3, r1);
                            r4 = LD32(sp - 40);
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r0 = LD32(sp - 44);
                            break;
                        }
                    } else {
                        r13 = r14;
                        r2 = LD8(r0 + r11);
                        r1 = LD8((r13 + 1));
                        r2 = ((r2 & 255) << 8) | (r1 & 255);
                        r12 = (r12 - 2) - r2;
                        r14 = r14 + (r2 + 2);
                        if (!(r12 >= 0)) {
                            ST32(sp - 44, -1);
                            r3 = LD32(sp - 44);
                            r4 = LD32(sp - 56);
                            if (!((r3 & r3) == 0)) {
                                if ((r4 & r4) == 0) {
                                    r4 = LD32(sp - 40);
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                    r0 = LD32(sp - 44);
                                    break;
                                } else {
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                    r4 = LD32(sp - 40);
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                    r0 = LD32(sp - 44);
                                    break;
                                }
                            } else {
                                r5 = LD32(sp - 40);
                                r0 = GCALL8(0x0604B358, 0x0608AD40, r5, 0x219, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r1 = LD32(sp - 56);
                                r3 = LD32(sp - 48);
                                ST32(r3, r1);
                                r4 = LD32(sp - 40);
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r0 = LD32(sp - 44);
                                break;
                            }
                        } else {
                            r8 = 0x060790A8;
                            r9 = 16;
                            while (1) {
                                r1 = LD32(r8);
                                if (!(r10 == r1)) {
                                    r9 = r9 - 1;
                                    r8 = r8 + 16;
                                    if (r9 > 0) {
                                        POLL();
                                        continue;
                                    } else {
                                        c1012 = (r9 & r9) == 0;
                                        break;
                                    }
                                } else {
                                    r4 = LD32(r8 + 4);
                                    r6 = r10;
                                    r0 = GCALL8(0x060752FC, r4, (r11 + 2), r6, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                    SETIN(6, r6);
                                    c1012 = (r9 & r9) == 0;
                                    if ((r0 & r0) == 0) {
                                        break;
                                    } else {
                                        r9 = r9 - 1;
                                        r8 = r8 + 16;
                                        if (r9 > 0) {
                                            POLL();
                                            continue;
                                        } else {
                                            c1012 = (r9 & r9) == 0;
                                            break;
                                        }
                                    }
                                }
                                POLL();
                            }
                            c1016 = r12 > 0;
                            if (c1012) {
                                r3 = 1;
                                if (c1016) {
                                    POLL();
                                    continue;
                                } else {
                                    r3 = LD32(sp - 44);
                                    r4 = LD32(sp - 56);
                                    if (!((r3 & r3) == 0)) {
                                        if ((r4 & r4) == 0) {
                                            r4 = LD32(sp - 40);
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                            r0 = LD32(sp - 44);
                                            break;
                                        } else {
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                            r4 = LD32(sp - 40);
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                            r0 = LD32(sp - 44);
                                            break;
                                        }
                                    } else {
                                        r5 = LD32(sp - 40);
                                        r0 = GCALL8(0x0604B358, 0x0608AD40, r5, 0x219, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        r1 = LD32(sp - 56);
                                        r3 = LD32(sp - 48);
                                        ST32(r3, r1);
                                        r4 = LD32(sp - 40);
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        r0 = LD32(sp - 44);
                                        break;
                                    }
                                }
                            } else {
                                r6 = LD32(r8 + 12);
                                r0 = LD32(r8 + 8);
                                r5 = LD32(sp - 40);
                                r7 = R(7);
                                SETIN(0, r0);
                                r0 = GCALL8(r0, r13, r5, r6, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                c1016 = r12 > 0;
                                if ((r0 & r0) == 0) {
                                    r3 = 1;
                                    if (c1016) {
                                        POLL();
                                        continue;
                                    } else {
                                        r3 = LD32(sp - 44);
                                        r4 = LD32(sp - 56);
                                        if (!((r3 & r3) == 0)) {
                                            if ((r4 & r4) == 0) {
                                                r4 = LD32(sp - 40);
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                                r0 = LD32(sp - 44);
                                                break;
                                            } else {
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                                r4 = LD32(sp - 40);
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                                r0 = LD32(sp - 44);
                                                break;
                                            }
                                        } else {
                                            r5 = LD32(sp - 40);
                                            r0 = GCALL8(0x0604B358, 0x0608AD40, r5, 0x219, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                            r1 = LD32(sp - 56);
                                            r3 = LD32(sp - 48);
                                            ST32(r3, r1);
                                            r4 = LD32(sp - 40);
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                            r0 = LD32(sp - 44);
                                            break;
                                        }
                                    }
                                } else {
                                    if (r0 == 1) {
                                        r4 = LD32(sp - 40);
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        r5 = LD32(sp - 36);
                                        r4 = LD32(sp - 52);
                                        c2011 = R(11);
                                        SETR(11, r11);
                                        r0 = GCALL8(0x060488B8, r4, r5, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        SETR(11, c2011);
                                        break;
                                    } else {
                                        ST32(sp - 44, -1);
                                        r3 = LD32(sp - 44);
                                        r4 = LD32(sp - 56);
                                        if (!((r3 & r3) == 0)) {
                                            if ((r4 & r4) == 0) {
                                                r4 = LD32(sp - 40);
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                                r0 = LD32(sp - 44);
                                                break;
                                            } else {
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                                r4 = LD32(sp - 40);
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                                r0 = LD32(sp - 44);
                                                break;
                                            }
                                        } else {
                                            r5 = LD32(sp - 40);
                                            r0 = GCALL8(0x0604B358, 0x0608AD40, r5, 0x219, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                            r1 = LD32(sp - 56);
                                            r3 = LD32(sp - 48);
                                            ST32(r3, r1);
                                            r4 = LD32(sp - 40);
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            r0 = GCALL8(0x06027F48, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                            r0 = LD32(sp - 44);
                                            break;
                                        }
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
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043348(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8;

    r0 = GCALL4(0x06025A0C, 6, r5, r6, r7);
    r8 = 0x0608BCE0;
    r0 = GCALL2(0x06028380, 0x3F4, -1);
    ST32(0x0608BCE0, r0);
    if (!((r0 & r0) == 0)) {
        r1 = 0;
        ST32(0x0608BCDC, 0);
        r6 = 252;
        r7 = r8;
        r3 = 0;
        do {
            r2 = LD32(r7);
            r0 = r1 << 2;
            r1 = r1 + 1;
            ST32(r0 + r2, r3);
        } while (AGAIN(!(r1 > r6)));
        r1 = LD32(0x06000334);
        r5 = R(5);
        SETIN(0, r0);
        r0 = GCALL4(r1, 6, r5, r6, r7);
        r0 = 1;
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043454(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c5, c7, c10, c11, c38, c1011, c1032, c1043;
    FRAME(sp, 96);

    r13 = r4;
    r5 = r5 & 255;
    ST32(sp - 56, r5);
    r8 = 0;
    if (!((r13 & r13) == 0)) {
        goto L06043480;
    }
    r0 = 0;
    goto L060437E2;
    L06043476:
    r5 = R(5);
    r6 = R(6);
    r0 = GCALL4(0x060433A8, r9, r5, r6, r7);
    r8 = 1;
    goto L06043532;
    L06043480:
    r0 = GCALL4(0x06025A0C, 6, r5, r6, r7);
    r2 = LD8((r13 + 4));
    r0 = LD32(sp - 56);
    r1 = LD32(r13);
    r2 = (r2 & 255) ^ r1;
    r1 = LD32(0x06043450);
    ST32(sp - 52, (((r2 ^ r0) - ((int)((((long long)((unsigned long long)(unsigned)(r2 ^ r0) * (unsigned)r1)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)(r2 ^ r0) * (unsigned)r1)) >> 32)) >> 2)) >> 2)) >> 1)) >> 2)) * 253)))) & 255));
    r2 = LD32(0x0608BCE0);
    r1 = LD32(sp - 52);
    r9 = LD32((r1 << 2) + r2);
    r1 = r13;
    if ((r9 & r9) == 0) {
        goto L06043532;
    }
    r7 = 0x06000334;
    L060434C6:
    r2 = LD8((r1 + 4));
    r1 = LD8((r9 + 4));
    if (!((r2 & 255) == (r1 & 255))) {
        goto L0604352A;
    }
    r2 = LD32(r13);
    r1 = LD32(r9);
    c5 = r2 == r1;
    r1 = r9;
    if (!(c5)) {
        goto L0604352A;
    }
    r1 = LD8((r1 + 5));
    r0 = LD32(sp - 56);
    if (!(r0 == (r1 & 255))) {
        goto L0604352A;
    }
    r1 = 0x2000000C + r9;
    c7 = LD8(r1);
    ST8(r1, (c7 | 0x80));
    r2 = r9;
    if (((c7 == 0) & (c7 == 0)) == 0) {
        goto L06043520;
    }
    r2 = r2 + 9;
    r1 = LD8(r2);
    ST8(r2, (r1 + 1));
    ST8(-366, 17);
    r1 = LD8((r9 + 13));
    c10 = ((r1 & 255) & (r1 & 255)) == 0;
    c1011 = c10;
    if (c10) {
        goto L0604351C;
    }
    r1 = LD32(r9 + 20);
    c11 = (r1 & r1) == 0;
    c1011 = c11;
    if (c11) {
        POLL();
        goto L06043476;
    }
    L0604351C:
    r1 = LD32(r7);
    goto L060437DC;
    L06043520:
    r1 = LD32(r7);
    r5 = R(5);
    r6 = R(6);
    SETIN(0, r0);
    r0 = GCALL4(r1, 6, r5, r6, r7);
    r0 = 0;
    goto L060437E2;
    L0604352A:
    r9 = LD32(r9 + 24);
    r1 = r13;
    SETIN(7, r7);
    if (!((r9 & r9) == 0)) {
        POLL();
        goto L060434C6;
    }
    L06043532:
    r9 = sp - 96;
    r0 = GCALL3(0x0604B3F0, (sp - 96), 0, 40);
    r1 = LD8((r13 + 4));
    ST8((sp - 92), r1);
    r1 = LD32(r13);
    ST32(sp - 96, r1);
    r0 = LD8((43 + (sp - 96)));
    ST8((sp - 91), r0);
    r11 = LD8((47 + (sp - 96)));
    ST8((sp - 86), r11);
    ST8((sp - 87), 1);
    ST8((sp - 84), 0);
    ST8((sp - 83), r8);
    ST32(sp - 76, 0);
    ST8((0x2000000C + (sp - 96)), ((LD8((0x2000000C + (sp - 96)))) | 0x80));
    r5 = LD32(sp - 56);
    r0 = GCALL5(0x0604340C, r13, r5, 0, 0, LD32((sp - 96)));
    r10 = r0;
    r8 = (int)((unsigned)(~r10) >> 31);
    r11 = LD32(r13 + 8);
    ST32(sp - 48, r11);
    if (!((r8 & r8) == 0)) {
        goto L060435A4;
    }
    c1032 = 1;
    goto L0604370C;
    L060435A4:
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL5(0x06021780, r13, 0, 0, 0, LD32((sp - 96)));
    if (!((r0 & r0) == 0)) {
        goto L060435B2;
    }
    goto L0604370A;
    L060435B2:
    r0 = LD32(r13 + 12);
    r11 = LD32(sp - 56);
    ST32(sp - 44, r0);
    r0 = LD32(sp - 48);
    r1 = LD8(r0 + r11);
    r6 = r1 & 255;
    r1 = LD32(r13 + 44);
    r2 = (short)r1;
    r1 = LD32(r13);
    r3 = r6;
    if (((r1 & 4) & (r1 & 4)) == 0) {
        goto L060435FC;
    }
    r12 = (short)r6;
    goto L06043606;
    L060435FC:
    r12 = (int)((unsigned)((r3 & 0xFFFF) * 3) >> 1);
    L06043606:
    r1 = r12;
    if (r12 > r2) {
        goto L0604361A;
    }
    r12 = (short)(((((int)((unsigned)(r1 << 8) >> 2)) << 8) << 16) | (int)((unsigned)(((int)((unsigned)(r1 << 8) >> 2)) << 8) >> 16));
    goto L06043624;
    L0604361A:
    r12 = (r2 >> 1) >> 1;
    L06043624:
    r3 = r9 + 8;
    r1 = LD32(r13 + 24);
    r10 = ((r2 * r10) >> 1) >> 1;
    ST32(sp - 40, (r1 >> 1));
    ST8((r9 + 6), r12);
    ST8(r3, ((r12 + 1) >> 1));
    r2 = LD32(r13 + 28);
    ST8((r9 + 7), r2);
    r1 = LD8(r3);
    r8 = ((r1 & 255) * (r2 & 255)) + 40;
    r0 = GCALL5(0x06028380, r8, 12, 0, 0, LD32((sp - 96)));
    r9 = r0;
    r3 = r9;
    if (!((r9 & r9) == 0)) {
        goto L0604367E;
    }
    r1 = LD32(0x06000334);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r1, 6, r5, r6, r7, LD32((sp - 96)));
    ST8((r13 + 6), 0);
    r0 = 0;
    goto L060437E2;
    L0604367E:
    r1 = LD32(sp - 96);
    ST32(r9, r1);
    r1 = LD32(sp - 92);
    r2 = (sp - 96) + 8;
    ST32(r9 + 4, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 8;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32((r2 + 4));
    ST32(r3 + 4, r1);
    ST32(r9 + 20, (r9 + 40));
    ST16((r9 + 16), r8);
    if (!(r12 > 0)) {
        goto L06043792;
    }
    r1 = LD8((r9 + 8));
    r12 = r1 & 255;
    r1 = LD8((r9 + 7));
    r2 = r10 >> 1;
    r8 = r1 & 255;
    r10 = LD32(r9 + 20);
    if (!(r8 > 0)) {
        goto L06043792;
    }
    r14 = 0x0604B358;
    L060436E4:
    r5 = LD32(sp - 44);
    ST32(sp - 36, r2);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r14, r10, (r5 + r2), r12, r7, LD32((sp - 96)));
    r2 = LD32(sp - 36);
    r8 = r8 - 1;
    r11 = LD32(sp - 40);
    r1 = LD8((r9 + 8));
    r2 = r2 + r11;
    r10 = r10 + (r1 & 255);
    if (r8 > 0) {
        POLL();
        goto L060436E4;
    }
    r2 = r13;
    goto L06043794;
    L0604370A:
    c1032 = (r8 & r8) == 0;
    L0604370C:
    r2 = r9;
    if (c1032) {
        goto L06043716;
    }
    r2 = r2 + 13;
    r1 = 1;
    goto L0604371A;
    L06043716:
    r2 = r2 + 13;
    r1 = 0;
    L0604371A:
    ST8(r2, r1);
    ST32(r9 + 20, 0);
    r8 = 0;
    ST8((r9 + 6), 0);
    ST8((r9 + 7), 0);
    r0 = GCALL5(0x06028380, 40, 11, 0, 0, LD32((sp - 96)));
    r9 = r0;
    r3 = r9;
    if (!((r9 & r9) == 0)) {
        goto L06043750;
    }
    r1 = LD32(0x06000334);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r1, 6, r5, r6, r7, LD32((sp - 96)));
    ST8((r13 + 6), r8);
    r0 = 0;
    goto L060437E2;
    L06043750:
    r1 = LD32(sp - 96);
    ST32(r9, r1);
    r1 = LD32(sp - 92);
    r2 = (sp - 96) + 8;
    ST32(r9 + 4, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 8;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r2 = r2 + 4;
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32(r2);
    r3 = r3 + 4;
    ST32(r3, r1);
    r1 = LD32((r2 + 4));
    ST32(r3 + 4, r1);
    ST16((r9 + 16), 40);
    L06043792:
    r2 = r13;
    L06043794:
    ST8((r2 + 6), 0);
    r0 = LD32(sp - 48);
    r11 = LD32(sp - 56);
    r1 = LD8(r0 + r11);
    ST8((r9 + 11), r1);
    r2 = LD32(sp - 52);
    r3 = 0x0608BCE0;
    r1 = LD32(0x0608BCE0);
    r2 = r2 << 2;
    r1 = LD32(r2 + r1);
    r7 = 0;
    ST32(r9 + 24, r1);
    r1 = LD32(r9 + 24);
    ST32(r9 + 28, 0);
    if ((r1 & r1) == 0) {
        goto L060437C0;
    }
    ST32(r1 + 28, r9);
    L060437C0:
    r1 = LD32(r3);
    r0 = r2;
    ST32(r0 + r1, r9);
    r1 = LD32(0x0608BCDC);
    ST32(r9 + 32, r1);
    ST32(0x0608BCDC, r9);
    r1 = LD32(r9 + 32);
    c38 = (r1 & r1) == 0;
    ST32(r9 + 36, r7);
    c1043 = c38;
    if (c38) {
        goto L060437D8;
    }
    ST32(r1 + 36, r9);
    c1043 = 0;
    L060437D8:
    r1 = LD32(0x06000334);
    L060437DC:
    r5 = R(5);
    r6 = R(6);
    SETIN(0, r0);
    r0 = GCALL5(r1, 6, r5, r6, r7, LD32((sp - 96)));
    r0 = r9;
    L060437E2:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0604396C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c3, c9, c14, c1023;
    FRAME(sp, 36);

    r12 = r5;
    if (!(r4 > 1)) {
        goto L06043A7A;
    }
    r0 = LD32(0x06000330);
    SETIN(0, r0);
    r0 = GCALL4(r0, 6, r5, r6, r7);
    if ((r0 & r0) == 0) {
        goto L06043A7A;
    }
    r0 = GCALL1(0x0602BA00, 0x06043960);
    r8 = LD32(0x0608BCDC);
    r13 = -r12;
    if ((r8 & r8) == 0) {
        goto L06043A72;
    }
    ST32(sp - 36, (r13 + 1));
    r14 = 0x06027F48;
    L060439AA:
    r1 = 0x2000000C + r8;
    c3 = LD8(r1);
    ST8(r1, (c3 | 0x80));
    if (((c3 == 0) & (c3 == 0)) == 0) {
        goto L06043A6C;
    }
    r0 = GCALL5(0x06027800, r8, 0, 0, 0, LD32((sp - 36)));
    r10 = r8;
    if (!(r0 == r12)) {
        goto L06043A66;
    }
    r10 = r10 + 16;
    r5 = LD16(r10);
    r4 = LD32(sp - 36);
    r0 = GCALL5(0x060279E0, r4, (r5 & 0xFFFF), 11, 0, LD32((sp - 36)));
    r9 = r0;
    r5 = r8;
    SETIN(5, r5);
    if ((r9 & r9) == 0) {
        goto L06043A66;
    }
    r6 = LD16(r10);
    r0 = GCALL5(0x0604B358, r9, r5, (r6 & 0xFFFF), 0, LD32((sp - 36)));
    r11 = r8;
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r14, r11, r5, r6, r7, LD32((sp - 36)));
    r10 = r9 + 16;
    r5 = LD16(r10);
    r0 = GCALL5(0x060279E0, r12, (r5 & 0xFFFF), 11, 0, LD32((sp - 36)));
    r8 = r0;
    r5 = r9;
    if (!((r8 & r8) == 0)) {
        goto L06043A08;
    }
    r8 = r9;
    SETIN(5, r5);
    goto L06043A16;
    L06043A08:
    r6 = LD16(r10);
    r0 = GCALL5(0x0604B358, r8, r5, (r6 & 0xFFFF), 0, LD32((sp - 36)));
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r14, r9, r5, r6, r7, LD32((sp - 36)));
    L06043A16:
    r1 = LD32(r8 + 20);
    c9 = (r1 & r1) == 0;
    r1 = r8;
    if (c9) {
        goto L06043A22;
    }
    ST32(r8 + 20, (r1 + 40));
    L06043A22:
    r1 = LD32(r8 + 36);
    if ((r1 & r1) == 0) {
        goto L06043A2E;
    }
    ST32(r1 + 32, r8);
    r1 = LD32(r8 + 32);
    goto L06043A34;
    L06043A2E:
    ST32(0x0608BCDC, r8);
    r1 = LD32(r8 + 32);
    L06043A34:
    if ((r1 & r1) == 0) {
        goto L06043A3A;
    }
    ST32(r1 + 36, r8);
    L06043A3A:
    r1 = LD32(r8 + 28);
    if ((r1 & r1) == 0) {
        goto L06043A4A;
    }
    ST32(r1 + 24, r8);
    r1 = LD32(r8 + 24);
    goto L06043A60;
    L06043A46:
    ST32(r3, r8);
    c1023 = 1;
    goto L06043A5E;
    L06043A4A:
    r3 = LD32(0x0608BCE0);
    r2 = 253;
    L06043A50:
    r1 = LD32(r3);
    r2 = r2 - 1;
    if (r1 == r11) {
        POLL();
        goto L06043A46;
    }
    c14 = r2 > 0;
    r3 = r3 + 4;
    c1023 = c14;
    if (c14) {
        POLL();
        goto L06043A50;
    }
    L06043A5E:
    r1 = LD32(r8 + 24);
    L06043A60:
    if ((r1 & r1) == 0) {
        goto L06043A66;
    }
    ST32(r1 + 28, r8);
    L06043A66:
    r0 = GCALL5(0x06043340, r8, 0, 0, 0, LD32((sp - 36)));
    L06043A6C:
    r8 = LD32(r8 + 32);
    if (!((r8 & r8) == 0)) {
        POLL();
        goto L060439AA;
    }
    L06043A72:
    r1 = LD32(0x06000334);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r1, 6, r5, r6, r7, LD32((sp - 36)));
    L06043A7A:
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043B20(void)
{
    int r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    int v36;
    int v40;

    r9 = LD32(0x0608BD08);
    r2 = 0x0608BD04;
    r1 = LD32(0x0608BD04);
    r10 = 0;
    r12 = 12;
    if (!(0 >= r1)) {
        r13 = 0x0607507C;
        r11 = r2;
        do {
            r4 = LD32(r9);
            r9 = r9 + 4;
            r0 = GCALL1(r13, r4);
            r1 = LD32(r11);
            r10 = r10 + 1;
            r12 = (r12 + 1) + r0;
        } while (AGAIN(!(r10 >= r1)));
    }
    r0 = GCALL4(0x060279E0, 0, r12, -1, 1);
    r11 = r0;
    r1 = 1;
    if (!((r11 & r11) == 0)) {
        ST32(r11, r1);
        r1 = LD32(0x0608BD04);
        r8 = r11 + 8;
        ST32(r11 + 4, r1);
        r1 = LD32(0x0608BD04);
        r10 = 0;
        r9 = LD32(0x0608BD08);
        if (!(0 >= r1)) {
            r14 = 0x060750DC;
            r13 = 0x0607507C;
            do {
                r5 = LD32(r9);
                SETIN(0, r0);
                r0 = GCALL2(r14, r8, r5);
                r4 = LD32(r9);
                r9 = r9 + 4;
                SETIN(0, r0);
                r0 = GCALL1(r13, r4);
                r8 = r8 + r0;
                ST8(r8, 0);
                r1 = LD32(0x0608BD04);
                r10 = r10 + 1;
                r8 = r8 + 1;
            } while (AGAIN(!(r10 >= r1)));
        }
        v40 = r12;
        r0 = GCALL6(0x06032A08, 0, 0x06043B14, 0x06043B10, r11, v40, 1);
        r8 = r0;
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL6(0x06027F48, r11, 0, 0, 0, v40, 1);
        r0 = r8;
    } else {
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06043C08(void)
{
    int r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    int v36;
    int v40;

    r9 = LD32(0x0608BCF8);
    r2 = 0x0608BCF4;
    r1 = LD32(0x0608BCF4);
    r10 = 0;
    r12 = 12;
    if (!(0 >= r1)) {
        r13 = 0x0607507C;
        r11 = r2;
        do {
            r4 = LD32(r9);
            r9 = r9 + 4;
            r0 = GCALL1(r13, r4);
            r1 = LD32(r11);
            r10 = r10 + 1;
            r12 = (r12 + 1) + r0;
        } while (AGAIN(!(r10 >= r1)));
    }
    r0 = GCALL4(0x060279E0, 0, r12, -1, 1);
    r11 = r0;
    r1 = 2;
    if (!((r11 & r11) == 0)) {
        ST32(r11, r1);
        r1 = LD32(0x0608BCF4);
        r8 = r11 + 8;
        ST32(r11 + 4, r1);
        r1 = LD32(0x0608BCF4);
        r10 = 0;
        r9 = LD32(0x0608BCF8);
        if (!(0 >= r1)) {
            r14 = 0x060750DC;
            r13 = 0x0607507C;
            do {
                r5 = LD32(r9);
                SETIN(0, r0);
                r0 = GCALL2(r14, r8, r5);
                r4 = LD32(r9);
                r9 = r9 + 4;
                SETIN(0, r0);
                r0 = GCALL1(r13, r4);
                r8 = r8 + r0;
                ST8(r8, 0);
                r1 = LD32(0x0608BCF4);
                r10 = r10 + 1;
                r8 = r8 + 1;
            } while (AGAIN(!(r10 >= r1)));
        }
        v40 = r12;
        r0 = GCALL6(0x06032A08, 0, 0x06043BFC, 0x06043B10, r11, v40, 1);
        r8 = r0;
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL6(0x06027F48, r11, 0, 0, 0, v40, 1);
        r0 = r8;
    } else {
        r0 = -3;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060441C8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, r14, c2, c7, c9, c1010, c2011;
    int v36;
    int v40;

    r11 = R(11);
    r14 = r4;
    r13 = r5;
    v36 = r6;
    r12 = r7;
    r9 = LD32(r12);
    r8 = 0;
    if (!((r9 & r9) == 0)) {
        r0 = GCALL5(0x06044340, r9, r5, r6, 0, v36);
        ST32(r12, r8);
        c1010 = (r9 & r9) == 0;
        r6 = 26;
        if (c1010) {
            r4 = 0x0608B860;
            r5 = 0x060441AC;
            r1 = 0x0604B358;
            r6 = 25;
        } else {
            r4 = 0x0608B860;
            r5 = 0x06044190;
            r1 = 0x0604B358;
        }
        r7 = R(7);
        r0 = GCALL5(r1, r4, r5, r6, r7, v36);
        c2011 = R(11);
        SETR(11, r11);
        r0 = GCALL5(0x06010DDC, 15, 0, 0, 0, v36);
        SETR(11, c2011);
        c9 = (r0 & r0) == 0;
        r0 = 0;
        if (c9) {
            r0 = GCALL6(0x060443F8, r14, r13, 0x0608AF60, 0x0608B760, r12, v36);
            r8 = r0;
            if ((r8 & r8) == 0) {
                r0 = 0;
            } else {
                r5 = R(5);
                r0 = GCALL5(0x060443A4, r8, 0, 0, 0, v36);
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r1 = LD32(r8 + 16);
                    r0 = 1;
                    ST32(v36, r1);
                }
            }
        }
    } else {
        r8 = LD32(0x060791B0);
        c2 = (r9 & r9) == 0;
        SETIN(7, r7);
        c1010 = c2;
        if ((r8 & r8) == 0) {
            r6 = 26;
            if (c1010) {
                r4 = 0x0608B860;
                r5 = 0x060441AC;
                r1 = 0x0604B358;
                r6 = 25;
            } else {
                r4 = 0x0608B860;
                r5 = 0x06044190;
                r1 = 0x0604B358;
            }
            r7 = R(7);
            r0 = GCALL5(r1, r4, r5, r6, r7, v36);
            c2011 = R(11);
            SETR(11, r11);
            r0 = GCALL5(0x06010DDC, 15, 0, 0, 0, v36);
            SETR(11, c2011);
            c9 = (r0 & r0) == 0;
            r0 = 0;
            if (c9) {
                r0 = GCALL6(0x060443F8, r14, r13, 0x0608AF60, 0x0608B760, r12, v36);
                r8 = r0;
                if ((r8 & r8) == 0) {
                    r0 = 0;
                } else {
                    r5 = R(5);
                    r0 = GCALL5(0x060443A4, r8, 0, 0, 0, v36);
                    if ((r0 & r0) == 0) {
                        r0 = 0;
                    } else {
                        r1 = LD32(r8 + 16);
                        r0 = 1;
                        ST32(v36, r1);
                    }
                }
            }
        } else {
            r11 = 0x0607507C;
            r10 = 0x06075238;
            SETIN(5, r5);
            SETIN(6, r6);
            SETIN(7, r7);
            while (1) {
                r4 = LD32(r8);
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(r11, r4, r5, r6, r7, v36);
                r5 = LD32(r8);
                r7 = R(7);
                SETIN(0, r0);
                r0 = GCALL5(r10, r14, r5, r0, r7, v36);
                if (!((r0 & r0) == 0)) {
                    r8 = LD32(r8 + 28);
                    c7 = (r9 & r9) == 0;
                    if (!((r8 & r8) == 0)) {
                        POLL();
                        continue;
                    } else {
                        c1010 = c7;
                        r6 = 26;
                        if (c1010) {
                            r4 = 0x0608B860;
                            r5 = 0x060441AC;
                            r1 = 0x0604B358;
                            r6 = 25;
                            r7 = R(7);
                            r0 = GCALL5(r1, r4, r5, r6, r7, v36);
                            c2011 = R(11);
                            SETR(11, r11);
                            r0 = GCALL5(0x06010DDC, 15, 0, 0, 0, v36);
                            SETR(11, c2011);
                            c9 = (r0 & r0) == 0;
                            r0 = 0;
                            if (!(c9)) {
                                break;
                            } else {
                                r0 = GCALL6(0x060443F8, r14, r13, 0x0608AF60, 0x0608B760, r12, v36);
                                r8 = r0;
                                if ((r8 & r8) == 0) {
                                    r0 = 0;
                                    break;
                                } else {
                                    r5 = R(5);
                                    r0 = GCALL5(0x060443A4, r8, 0, 0, 0, v36);
                                    if ((r0 & r0) == 0) {
                                        r0 = 0;
                                        break;
                                    } else {
                                        r1 = LD32(r8 + 16);
                                        r0 = 1;
                                        ST32(v36, r1);
                                        break;
                                    }
                                }
                            }
                        } else {
                            r4 = 0x0608B860;
                            r5 = 0x06044190;
                            r1 = 0x0604B358;
                            r7 = R(7);
                            r0 = GCALL5(r1, r4, r5, r6, r7, v36);
                            c2011 = R(11);
                            SETR(11, r11);
                            r0 = GCALL5(0x06010DDC, 15, 0, 0, 0, v36);
                            SETR(11, c2011);
                            c9 = (r0 & r0) == 0;
                            r0 = 0;
                            if (!(c9)) {
                                break;
                            } else {
                                r0 = GCALL6(0x060443F8, r14, r13, 0x0608AF60, 0x0608B760, r12, v36);
                                r8 = r0;
                                if ((r8 & r8) == 0) {
                                    r0 = 0;
                                    break;
                                } else {
                                    r5 = R(5);
                                    r0 = GCALL5(0x060443A4, r8, 0, 0, 0, v36);
                                    if ((r0 & r0) == 0) {
                                        r0 = 0;
                                        break;
                                    } else {
                                        r1 = LD32(r8 + 16);
                                        r0 = 1;
                                        ST32(v36, r1);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    r4 = LD32(r8 + 4);
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    SETIN(0, r0);
                    r0 = GCALL5(r11, r4, r5, r6, r7, v36);
                    r5 = LD32(r8 + 4);
                    r7 = R(7);
                    SETIN(0, r0);
                    r0 = GCALL5(r10, r13, r5, r0, r7, v36);
                    if (!((r0 & r0) == 0)) {
                        r8 = LD32(r8 + 28);
                        c7 = (r9 & r9) == 0;
                        if (!((r8 & r8) == 0)) {
                            POLL();
                            continue;
                        } else {
                            c1010 = c7;
                            r6 = 26;
                            if (c1010) {
                                r4 = 0x0608B860;
                                r5 = 0x060441AC;
                                r1 = 0x0604B358;
                                r6 = 25;
                                r7 = R(7);
                                r0 = GCALL5(r1, r4, r5, r6, r7, v36);
                                c2011 = R(11);
                                SETR(11, r11);
                                r0 = GCALL5(0x06010DDC, 15, 0, 0, 0, v36);
                                SETR(11, c2011);
                                c9 = (r0 & r0) == 0;
                                r0 = 0;
                                if (!(c9)) {
                                    break;
                                } else {
                                    r0 = GCALL6(0x060443F8, r14, r13, 0x0608AF60, 0x0608B760, r12, v36);
                                    r8 = r0;
                                    if ((r8 & r8) == 0) {
                                        r0 = 0;
                                        break;
                                    } else {
                                        r5 = R(5);
                                        r0 = GCALL5(0x060443A4, r8, 0, 0, 0, v36);
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                            break;
                                        } else {
                                            r1 = LD32(r8 + 16);
                                            r0 = 1;
                                            ST32(v36, r1);
                                            break;
                                        }
                                    }
                                }
                            } else {
                                r4 = 0x0608B860;
                                r5 = 0x06044190;
                                r1 = 0x0604B358;
                                r7 = R(7);
                                r0 = GCALL5(r1, r4, r5, r6, r7, v36);
                                c2011 = R(11);
                                SETR(11, r11);
                                r0 = GCALL5(0x06010DDC, 15, 0, 0, 0, v36);
                                SETR(11, c2011);
                                c9 = (r0 & r0) == 0;
                                r0 = 0;
                                if (!(c9)) {
                                    break;
                                } else {
                                    r0 = GCALL6(0x060443F8, r14, r13, 0x0608AF60, 0x0608B760, r12, v36);
                                    r8 = r0;
                                    if ((r8 & r8) == 0) {
                                        r0 = 0;
                                        break;
                                    } else {
                                        r5 = R(5);
                                        r0 = GCALL5(0x060443A4, r8, 0, 0, 0, v36);
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                            break;
                                        } else {
                                            r1 = LD32(r8 + 16);
                                            r0 = 1;
                                            ST32(v36, r1);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        r1 = LD32(r8 + 16);
                        ST32(v36, r1);
                        r1 = LD32(r8 + 24);
                        r0 = 1;
                        if (!((r1 & r1) == 0)) {
                            break;
                        } else {
                            r0 = GCALL5(0x060443E0, 0, 0, 0, 0, v36);
                            ST32(r12, r0);
                            ST32(r8 + 24, r0);
                            r1 = LD32(0x0608B980);
                            r0 = 1;
                            ST32(r8 + 20, r1);
                            break;
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
int f060443F8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 36);

    r13 = r4;
    ST32(sp - 36, r5);
    r12 = r6;
    r11 = r7;
    r14 = 0x060279E0;
    r0 = GCALL5(0x060279E0, 0, 32, -1, 1, LD32((sp - 36)));
    r9 = r0;
    r1 = 0;
    if (!((r9 & r9) == 0)) {
        ST32(r9 + 28, r1);
        r10 = 0x0607507C;
        r0 = GCALL5(0x0607507C, r13, 0, 0, 0, LD32((sp - 36)));
        SETIN(0, r0);
        r0 = GCALL5(r14, 0, (r0 + 1), -1, 1, LD32((sp - 36)));
        ST32(r9, r0);
        if (!((r0 & r0) == 0)) {
            r8 = 0x060750DC;
            r0 = GCALL5(0x060750DC, r0, r13, 0, 0, LD32((sp - 36)));
            r4 = LD32(sp - 36);
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            SETIN(0, r0);
            r0 = GCALL5(r10, r4, r5, r6, r7, LD32((sp - 36)));
            SETIN(0, r0);
            r0 = GCALL5(r14, 0, (r0 + 1), -1, 1, LD32((sp - 36)));
            ST32(r9 + 4, r0);
            if (!((r0 & r0) == 0)) {
                r5 = LD32(sp - 36);
                r6 = R(6);
                r7 = R(7);
                SETIN(0, r0);
                r0 = GCALL5(r8, r0, r5, r6, r7, LD32((sp - 36)));
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                SETIN(0, r0);
                r0 = GCALL5(r10, r12, r5, r6, r7, LD32((sp - 36)));
                SETIN(0, r0);
                r0 = GCALL5(r14, 0, (r0 + 1), -1, 1, LD32((sp - 36)));
                ST32(r9 + 8, r0);
                if (!((r0 & r0) == 0)) {
                    r6 = R(6);
                    r7 = R(7);
                    SETIN(0, r0);
                    r0 = GCALL5(r8, r0, r12, r6, r7, LD32((sp - 36)));
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    SETIN(0, r0);
                    r0 = GCALL5(r10, r11, r5, r6, r7, LD32((sp - 36)));
                    SETIN(0, r0);
                    r0 = GCALL5(r14, 0, (r0 + 1), -1, 1, LD32((sp - 36)));
                    ST32(r9 + 12, r0);
                    if (!((r0 & r0) == 0)) {
                        r6 = R(6);
                        r7 = R(7);
                        SETIN(0, r0);
                        r0 = GCALL5(r8, r0, r11, r6, r7, LD32((sp - 36)));
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        SETIN(0, r0);
                        r0 = GCALL5(r10, r12, r5, r6, r7, LD32((sp - 36)));
                        r8 = r0;
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        SETIN(0, r0);
                        r0 = GCALL5(r10, r11, r5, r6, r7, LD32((sp - 36)));
                        SETIN(0, r0);
                        r0 = GCALL5(r14, 0, ((r0 + r8) + 2), -1, 1, LD32((sp - 36)));
                        r10 = r0;
                        r7 = r11;
                        if (!((r10 & r10) == 0)) {
                            r0 = GCALL5(0x06045264, r10, 0x060443F0, r12, r7, LD32((sp - 36)));
                            r0 = GCALL5(0x06044688, (r9 + 16), r10, 0, 0, LD32((sp - 36)));
                            if ((r0 & r0) == 0) {
                                r8 = 0x06027F48;
                                r4 = LD32(r9);
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                                r4 = LD32(r9 + 4);
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                                r4 = LD32(r9 + 8);
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                                r4 = LD32(r9 + 12);
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL5(0x06027F48, r9, 0, 0, 0, LD32((sp - 36)));
                                r4 = r10;
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                SETIN(0, r0);
                                r0 = GCALL5(r8, r4, r5, r6, r7, LD32((sp - 36)));
                                r0 = 0;
                            } else {
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL5(0x06027F48, r10, 0, 0, 0, LD32((sp - 36)));
                                r1 = LD32(0x0608B980);
                                ST32(r9 + 20, r1);
                                r0 = GCALL5(0x060443E0, 0, 0, 0, 0, LD32((sp - 36)));
                                ST32(r9 + 24, r0);
                                r2 = LD32(sp);
                                ST32(r2, r0);
                                r0 = r9;
                            }
                        } else {
                            r8 = 0x06027F48;
                            r4 = LD32(r9);
                            r5 = R(5);
                            r6 = R(6);
                            r0 = GCALL5(0x06027F48, r4, r5, r6, r7, LD32((sp - 36)));
                            r4 = LD32(r9 + 4);
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                            r4 = LD32(r9 + 8);
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                            r4 = LD32(r9 + 12);
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                            r4 = r9;
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            SETIN(0, r0);
                            r0 = GCALL5(r8, r4, r5, r6, r7, LD32((sp - 36)));
                            r0 = 0;
                        }
                    } else {
                        r8 = 0x06027F48;
                        r4 = LD32(r9);
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                        r4 = LD32(r9 + 4);
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                        r4 = LD32(r9 + 8);
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                        r4 = r9;
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        SETIN(0, r0);
                        r0 = GCALL5(r8, r4, r5, r6, r7, LD32((sp - 36)));
                        r0 = 0;
                    }
                } else {
                    r8 = 0x06027F48;
                    r4 = LD32(r9);
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                    r4 = LD32(r9 + 4);
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                    r4 = r9;
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    SETIN(0, r0);
                    r0 = GCALL5(r8, r4, r5, r6, r7, LD32((sp - 36)));
                    r0 = 0;
                }
            } else {
                r8 = 0x06027F48;
                r4 = LD32(r9);
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(0x06027F48, r4, 0, 0, 0, LD32((sp - 36)));
                r4 = r9;
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                SETIN(0, r0);
                r0 = GCALL5(r8, r4, r5, r6, r7, LD32((sp - 36)));
                r0 = 0;
            }
        } else {
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL5(0x06027F48, r9, 0, 0, 0, LD32((sp - 36)));
            r0 = 0;
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06044880(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, c4, c12, c14, c17, c1013, c1019;
    FRAME(sp, 28);

    r8 = r4;
    r9 = r5;
    r2 = r7;
    r10 = r6;
    r3 = r8;
    r5 = LD32(sp);
    r6 = LD32(sp + 4);
    if ((unsigned)r3 > (unsigned)0) {
        goto L060448B6;
    }
    ST32((sp - 28), r6);
    r0 = GCALL5(0x060447C4, r9, r10, r2, r5, LD32((sp - 28)));
    goto L06044996;
    L060448B6:
    r0 = r2;
    r1 = 10;
    if (r0 == 10) {
        goto L060448CC;
    }
    c4 = r0 == 8;
    c1019 = c4;
    if (r2 > r1) {
        goto L06044964;
    }
    r1 = 7;
    if (c4) {
        goto L06044926;
    }
    r0 = r9;
    goto L06044966;
    L060448CC:
    r1 = 0x7FFFFFFF;
    if (!((unsigned)r3 > (unsigned)0x7FFFFFFF)) {
        goto L060448F4;
    }
    r0 = GCALL4(0x060747B8, r8, r9, 0, 10);
    r1 = R(1);
    r10 = r10 - 1;
    ST8(r10, (r1 + 48));
    r0 = GCALL4(0x060747D8, r8, r9, 0, 10);
    r8 = r0;
    r1 = R(1);
    r9 = r1;
    L060448F4:
    r12 = 0x060747F4;
    r11 = 0x06074888;
    r6 = 0;
    L060448FA:
    r7 = 10;
    L060448FC:
    SETIN(0, r0);
    SETIN(1, r1);
    r0 = GCALL4(r12, r8, r9, r6, r7);
    r1 = R(1);
    r1 = r1 + 48;
    r10 = r10 - 1;
    ST8(r10, r1);
    SETIN(0, r0);
    SETIN(1, r1);
    r0 = GCALL4(r11, r8, r9, 0, 10);
    r8 = r0;
    r1 = R(1);
    r9 = r1;
    r6 = 0;
    if (!((r8 & r8) == 0)) {
        POLL();
        goto L060448FA;
    }
    r7 = 10;
    if (!((r9 & r9) == 0)) {
        POLL();
        goto L060448FC;
    }
    r0 = r10;
    goto L06044996;
    L06044924:
    r1 = 7;
    L06044926:
    r6 = (r1 & r9) + 48;
    r2 = (((int)((unsigned)((int)((unsigned)(r8 << 16) >> 1)) >> 2)) << 16) | ((int)((unsigned)((int)((unsigned)r9 >> 2)) >> 1));
    r8 = (int)((unsigned)((int)((unsigned)r8 >> 2)) >> 1);
    r9 = r2;
    c12 = (r8 & r8) == 0;
    r10 = r10 - 1;
    ST8(r10, r6);
    c1013 = c12;
    if (!(c12)) {
        POLL();
        goto L06044924;
    }
    c14 = (r5 & r5) == 0;
    c1013 = c14;
    if (!((r9 & r9) == 0)) {
        POLL();
        goto L06044924;
    }
    r0 = r6;
    if (c14) {
        goto L06044994;
    }
    r1 = 48;
    if (r0 == 48) {
        goto L06044994;
    }
    r10 = r10 - 1;
    ST8(r10, r1);
    goto L06044994;
    L06044964:
    r0 = r9;
    L06044966:
    r1 = LD8((r0 & 15) + r6);
    r10 = r10 - 1;
    ST8(r10, r1);
    r2 = ((((r8 << 16) << 8) << 2) << 2) | ((int)((unsigned)((int)((unsigned)r9 >> 2)) >> 2));
    r8 = (int)((unsigned)((int)((unsigned)r8 >> 2)) >> 2);
    r9 = r2;
    c17 = (r9 & r9) == 0;
    c1019 = c17;
    if (!((r8 & r8) == 0)) {
        POLL();
        goto L06044964;
    }
    r0 = r9;
    if (!(c17)) {
        POLL();
        goto L06044966;
    }
    L06044994:
    r0 = r10;
    L06044996:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045710(int r4, int r5)
{
    int r0, r8, r15;
    FRAME(sp, 12);

    r8 = r5;
    if ((r4 & r4) == 0) {
        r0 = 0x06075438;
        r4 = r8;
        r15 = sp - 12;
    } else {
        r0 = GCALL1(0x06045614, r8);
        r15 = ALLOCA(sp - 12, (((int)((unsigned)(r0 + 3) >> 2)) << 2));
        SETSP(r15);
        r0 = GCALL2(0x06045654, r8, r15);
        r0 = 0x06075454;
        r4 = r15;
    }
    SETSP(r15);
    SETIN(0, r0);
    r0 = GCALL1(r0, r4);
    SETSP((sp - 12));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06045FE0(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14, c3, c16, c28, c32, c40, c1014;
    int v36;

    r12 = r4;
    r11 = r5;
    r9 = 0;
    r0 = GCALL0(0x06045D70);
    v36 = r0;
    r1 = LD32(0x060791BC);
    r10 = 99;
    r14 = -1;
    if (!(r1 > 99)) {
        goto L06046014;
    }
    r0 = GCALL5(0x060462F8, 1, 0, 0, 0, v36);
    r14 = -1;
    L06046014:
    r8 = 0;
    r7 = r10;
    r3 = 0x0608BD10;
    L0604601A:
    r1 = LD32(r3 + 40);
    if ((r1 & r1) == 0) {
        goto L06046040;
    }
    r8 = r8 + 1;
    r3 = r3 + 44;
    if (!(r8 > r7)) {
        POLL();
        goto L0604601A;
    }
    L0604602A:
    r0 = GCALL5(0x0607507C, r11, 0, 0, 0, v36);
    r8 = r0 + 1;
    c3 = r8 > 1;
    r7 = c3;
    if (c3) {
        goto L06046046;
    }
    r0 = 0;
    goto L060462CA;
    L06046040:
    r9 = r3;
    r14 = r8;
    POLL();
    goto L0604602A;
    L06046046:
    r0 = GCALL5(0x060279E0, 0, r8, -1, r7, v36);
    ST32(r9 + 40, r0);
    if (!((r0 & r0) == 0)) {
        goto L0604605A;
    }
    goto L060461AC;
    L0604605A:
    r0 = GCALL5(0x0604B358, r0, r11, r8, 0, v36);
    r8 = LD32(r9 + 40);
    ST32(r9 + 16, v36);
    ST32(r9 + 32, 0);
    ST32(r9 + 28, 0);
    ST32(r9 + 36, 0);
    ST32(r9 + 24, 0);
    ST32(r9 + 20, 0);
    r2 = LD8(r8);
    if ((((signed char)r2) & ((signed char)r2)) == 0) {
        goto L0604617A;
    }
    r10 = 0x06075238;
    c1014 = 0;
    goto L06046090;
    L06046084:
    if (!(r0 == 32)) {
        goto L06046094;
    }
    r8 = r8 + 1;
    r2 = LD8(r8);
    c1014 = (((signed char)r2) & ((signed char)r2)) == 0;
    L06046090:
    r0 = (signed char)r2;
    if (!(c1014)) {
        POLL();
        goto L06046084;
    }
    L06046094:
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r10, r8, 0x06045FBC, 8, r7, v36);
    r6 = 5;
    if (!((r0 & r0) == 0)) {
        goto L060460B0;
    }
    r0 = GCALL5(0x06045E34, (r8 + 8), 0, 0, 0, v36);
    ST32(r9 + 16, r0);
    goto L06046164;
    L060460B0:
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r10, r8, 0x06045FC8, r6, r7, v36);
    r6 = 7;
    if (!((r0 & r0) == 0)) {
        goto L060460E8;
    }
    r1 = r8 + 5;
    goto L060460C6;
    L060460C2:
    r1 = LD32(r9 + 20);
    r1 = r1 + 1;
    L060460C6:
    ST32(r9 + 20, r1);
    r0 = LD8(r1);
    r1 = 0;
    if (r0 == 32) {
        POLL();
        goto L060460C2;
    }
    r3 = LD32(r9 + 20);
    L060460D2:
    ST32(r9 + 4, r1);
    r1 = LD8(r3);
    if ((r1 & r1) == 0) {
        goto L06046164;
    }
    r0 = LD8(r3);
    if (r0 == 59) {
        goto L06046164;
    }
    r1 = LD32(r9 + 4);
    r3 = r3 + 1;
    r1 = r1 + 1;
    POLL();
    goto L060460D2;
    L060460E8:
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r10, r8, 0x06045FD0, r6, r7, v36);
    r6 = 7;
    if (!((r0 & r0) == 0)) {
        goto L06046114;
    }
    r1 = r8 + 7;
    ST32(r9 + 24, r1);
    r3 = r1;
    r1 = 0;
    L060460FE:
    ST32(r9 + 8, r1);
    r1 = LD8(r3);
    if ((r1 & r1) == 0) {
        goto L06046164;
    }
    r0 = LD8(r3);
    if (r0 == 59) {
        goto L06046164;
    }
    r1 = LD32(r9 + 8);
    r3 = r3 + 1;
    r1 = r1 + 1;
    POLL();
    goto L060460FE;
    L06046114:
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r10, r8, 0x06045FD8, r6, r7, v36);
    c16 = (r0 & r0) == 0;
    r13 = c16;
    if (!(c16)) {
        goto L06046124;
    }
    ST32(r9 + 32, r13);
    goto L06046164;
    L06046124:
    r1 = LD32(r9 + 36);
    if (!((r1 & r1) == 0)) {
        goto L06046164;
    }
    ST32(r9 + 36, r8);
    r3 = r8;
    r2 = LD8(r3);
    r6 = 0;
    goto L0604613E;
    L06046134:
    if (r0 == 59) {
        goto L06046146;
    }
    r3 = r3 + 1;
    r2 = LD8(r3);
    r6 = r6 + 1;
    L0604613E:
    r0 = (signed char)r2;
    if (!((((signed char)r2) & ((signed char)r2)) == 0)) {
        POLL();
        goto L06046134;
    }
    L06046146:
    r0 = LD8(r3);
    r1 = 1;
    if (!(r0 == 59)) {
        goto L06046154;
    }
    ST8(r3, 0);
    r1 = 1;
    L06046154:
    SETIN(6, r6);
    if (!(r6 > r1)) {
        goto L060461A2;
    }
    r2 = LD8(r8);
    goto L06046166;
    L0604615E:
    if (r0 == 59) {
        goto L0604616E;
    }
    r8 = r8 + 1;
    L06046164:
    r2 = LD8(r8);
    L06046166:
    r0 = (signed char)r2;
    if (!((((signed char)r2) & ((signed char)r2)) == 0)) {
        POLL();
        goto L0604615E;
    }
    L0604616E:
    r8 = r8 + 1;
    r2 = LD8(r8);
    r0 = (signed char)r2;
    if (!((((signed char)r2) & ((signed char)r2)) == 0)) {
        POLL();
        goto L06046084;
    }
    L0604617A:
    r1 = LD32(r9 + 24);
    r10 = 0;
    if (!((r1 & r1) == 0)) {
        goto L060461F8;
    }
    r8 = r12 + 108;
    r10 = 0x0607507C;
    r4 = LD32(r8);
    r0 = GCALL5(0x0607507C, r4, 0, 0, 0, v36);
    r0 = GCALL5(0x060279E0, 0, (r0 + 1), -1, 1, v36);
    r1 = r0;
    ST32(r9 + 28, r1);
    if (!((r1 & r1) == 0)) {
        goto L060461E8;
    }
    L060461A2:
    r4 = LD32(r9 + 40);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL5(0x06027F48, r4, 0, 0, 0, v36);
    ST32(r9 + 40, 0);
    L060461AC:
    r0 = 0;
    goto L060462CA;
    L060461E8:
    r5 = LD32(r8);
    r0 = GCALL5(0x060750DC, r1, r5, 0, 0, v36);
    r4 = LD32(r8);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r10, r4, r5, r6, r7, v36);
    ST32(r9 + 12, r0);
    r10 = 0;
    L060461F8:
    r12 = 0x06027F48;
    r11 = 0;
    r8 = 0x0608BD10;
    L060461FE:
    r1 = LD32(r8 + 40);
    c28 = r10 == r14;
    if ((r1 & r1) == 0) {
        goto L060462B6;
    }
    if (c28) {
        goto L060462B6;
    }
    r4 = LD32(r9 + 24);
    r6 = LD32(r9 + 8);
    if (!((r4 & r4) == 0)) {
        goto L06046214;
    }
    r4 = LD32(r9 + 28);
    r6 = LD32(r9 + 12);
    L06046214:
    r5 = LD32(r8 + 24);
    r7 = LD32(r8 + 8);
    if (!((r5 & r5) == 0)) {
        goto L06046220;
    }
    r5 = LD32(r8 + 28);
    r7 = LD32(r8 + 12);
    L06046220:
    c32 = (r5 & r5) == 0;
    if ((r4 & r4) == 0) {
        goto L06046232;
    }
    if (c32) {
        goto L06046232;
    }
    r0 = GCALL5(0x06045F9C, r4, r5, r6, r7, v36);
    if ((r0 & r0) == 0) {
        goto L060462B6;
    }
    L06046232:
    r4 = LD32(r9 + 20);
    if ((r4 & r4) == 0) {
        goto L06046248;
    }
    r5 = LD32(r8 + 20);
    if ((r5 & r5) == 0) {
        goto L06046248;
    }
    r6 = LD32(r8 + 4);
    r0 = GCALL5(0x060752FC, r4, r5, r6, 0, v36);
    if (!((r0 & r0) == 0)) {
        goto L060462B6;
    }
    L06046248:
    r2 = LD32(r9 + 36);
    if ((r2 & r2) == 0) {
        goto L060462B6;
    }
    r1 = LD32(r8 + 36);
    r3 = r2;
    if ((r1 & r1) == 0) {
        goto L060462B6;
    }
    r1 = LD8(r3);
    r6 = 0;
    goto L06046266;
    L0604625C:
    r3 = r3 + 1;
    if ((r1 & r1) == 0) {
        goto L0604626E;
    }
    r1 = LD8(r3);
    r6 = r6 + 1;
    L06046266:
    c40 = ((signed char)r1) == 61;
    r1 = (signed char)r1;
    if (!(c40)) {
        POLL();
        goto L0604625C;
    }
    L0604626E:
    r5 = LD32(r8 + 36);
    r4 = LD32(r9 + 36);
    r0 = GCALL5(0x060752FC, r4, r5, r6, 0, v36);
    if (!((r0 & r0) == 0)) {
        goto L060462B6;
    }
    r4 = LD32(r8 + 40);
    r5 = R(5);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r12, r4, r5, r6, r7, v36);
    r4 = LD32(r8 + 28);
    ST32(r8 + 40, r11);
    if ((r4 & r4) == 0) {
        goto L0604628C;
    }
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r12, r4, r5, r6, r7, v36);
    ST32(r8 + 28, r11);
    L0604628C:
    r1 = LD32(r9 + 16);
    r0 = 1;
    if ((unsigned)r1 >= (unsigned)v36) {
        goto L060462CA;
    }
    r4 = LD32(r9 + 40);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r12, r4, r5, r6, r7, v36);
    r4 = LD32(r9 + 28);
    ST32(r9 + 40, r11);
    if ((r4 & r4) == 0) {
        goto L060462A8;
    }
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r12, r4, r5, r6, r7, v36);
    ST32(r9 + 28, r11);
    L060462A8:
    ST32(r8 + 40, r11);
    r1 = LD32(0x060791BC);
    ST32(0x060791BC, (r1 - 1));
    r0 = 1;
    goto L060462CA;
    L060462B6:
    r10 = r10 + 1;
    r8 = r8 + 44;
    if (!(r10 > 99)) {
        POLL();
        goto L060461FE;
    }
    r1 = LD32(0x060791BC);
    r0 = 1;
    ST32(0x060791BC, (r1 + 1));
    L060462CA:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060462F8(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14, c1, c5, c10, c13, c19, c20, c1004, c1005, c1023, c1033;
    int v36;
    int v40;
    int v44;

    r12 = r4;
    v44 = r5;
    v40 = 0;
    r13 = 0;
    if (r12 >= 0) {
        c1 = (r12 & r12) == 0;
        r14 = 0;
        c1005 = c1;
        if (c1) {
            v40 = 1;
            c1004 = 1;
            r14 = 0;
            c1005 = c1004;
        }
    } else {
        r12 = 100;
        c1004 = 0;
        r14 = 0;
        c1005 = c1004;
    }
    v36 = 0;
    while (1) {
        r9 = v36 + 0x0608BD10;
        r1 = LD32(r9 + 40);
        r3 = v36;
        if ((r1 & r1) == 0) {
            r14 = r14 + 1;
            r1 = 99;
            v36 = r3 + 44;
            if (!(r14 > 99)) {
                POLL();
                continue;
            } else {
                r0 = r13;
                if (!((v40 & v40) == 0)) {
                    break;
                } else {
                    r14 = 0;
                    r11 = r1;
                    r7 = -1;
                    c1023 = 1;
                    while (1) {
                        r6 = r7;
                        r2 = 0;
                        r5 = 0x0608BD10;
                        do {
                            r9 = r5;
                            r1 = LD32(r9 + 40);
                            c13 = (r1 & r1) == 0;
                            r1 = r9;
                            if (!(c13)) {
                                r1 = LD16((r1 + 2));
                                if (!((unsigned)r1 >= (unsigned)r6)) {
                                    r6 = r1;
                                    r7 = r2;
                                }
                            }
                            r2 = r2 + 1;
                            r5 = r5 + 44;
                        } while (AGAIN(!(r2 > r11)));
                        r3 = 44;
                        if (!(r7 > -1)) {
                            r14 = r14 + 1;
                            c20 = r14 > r11;
                            r7 = -1;
                            c1023 = c20;
                            c1033 = c20;
                            if (!(c20)) {
                                POLL();
                                continue;
                            } else {
                                break;
                            }
                        } else {
                            r9 = 0x0608BD10 + (r7 * r3);
                            r10 = 0x06027F48;
                            r4 = LD32(r9 + 40);
                            r0 = GCALL7(0x06027F48, r4, r5, r6, r7, v44, v40, v36);
                            r8 = 0;
                            r4 = LD32(r9 + 28);
                            ST32(r9 + 40, 0);
                            if (!((r4 & r4) == 0)) {
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                SETIN(0, r0);
                                r0 = GCALL7(r10, r4, r5, r6, r7, v44, v40, v36);
                                ST32(r9 + 28, r8);
                            }
                            r1 = LD32(0x060791BC);
                            r13 = 1;
                            r12 = r12 - 1;
                            c19 = r12 > 0;
                            ST32(0x060791BC, (r1 - 1));
                            c1033 = c19;
                            if (!(c19)) {
                                break;
                            } else {
                                r14 = r14 + 1;
                                c20 = r14 > r11;
                                r7 = -1;
                                c1023 = c20;
                                c1033 = c20;
                                if (!(c20)) {
                                    POLL();
                                    continue;
                                } else {
                                    break;
                                }
                            }
                        }
                        POLL();
                    }
                    r0 = r13;
                    break;
                }
            }
        } else {
            r0 = GCALL7(0x06045D70, 0, 0, 0, 0, v44, v40, v36);
            r1 = LD32(r9 + 16);
            r3 = v44;
            if ((unsigned)r1 >= (unsigned)r0) {
                if ((r3 & r3) == 0) {
                    r3 = v36;
                    r14 = r14 + 1;
                    r1 = 99;
                    v36 = r3 + 44;
                    if (!(r14 > 99)) {
                        POLL();
                        continue;
                    } else {
                        r0 = r13;
                        if (!((v40 & v40) == 0)) {
                            break;
                        } else {
                            r14 = 0;
                            r11 = r1;
                            r7 = -1;
                            c1023 = 1;
                            while (1) {
                                r6 = r7;
                                r2 = 0;
                                r5 = 0x0608BD10;
                                do {
                                    r9 = r5;
                                    r1 = LD32(r9 + 40);
                                    c13 = (r1 & r1) == 0;
                                    r1 = r9;
                                    if (!(c13)) {
                                        r1 = LD16((r1 + 2));
                                        if (!((unsigned)r1 >= (unsigned)r6)) {
                                            r6 = r1;
                                            r7 = r2;
                                        }
                                    }
                                    r2 = r2 + 1;
                                    r5 = r5 + 44;
                                } while (AGAIN(!(r2 > r11)));
                                r3 = 44;
                                if (!(r7 > -1)) {
                                    r14 = r14 + 1;
                                    c20 = r14 > r11;
                                    r7 = -1;
                                    c1023 = c20;
                                    c1033 = c20;
                                    if (!(c20)) {
                                        POLL();
                                        continue;
                                    } else {
                                        break;
                                    }
                                } else {
                                    r9 = 0x0608BD10 + (r7 * r3);
                                    r10 = 0x06027F48;
                                    r4 = LD32(r9 + 40);
                                    r0 = GCALL7(0x06027F48, r4, r5, r6, r7, v44, v40, v36);
                                    r8 = 0;
                                    r4 = LD32(r9 + 28);
                                    ST32(r9 + 40, 0);
                                    if (!((r4 & r4) == 0)) {
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        SETIN(0, r0);
                                        r0 = GCALL7(r10, r4, r5, r6, r7, v44, v40, v36);
                                        ST32(r9 + 28, r8);
                                    }
                                    r1 = LD32(0x060791BC);
                                    r13 = 1;
                                    r12 = r12 - 1;
                                    c19 = r12 > 0;
                                    ST32(0x060791BC, (r1 - 1));
                                    c1033 = c19;
                                    if (!(c19)) {
                                        break;
                                    } else {
                                        r14 = r14 + 1;
                                        c20 = r14 > r11;
                                        r7 = -1;
                                        c1023 = c20;
                                        c1033 = c20;
                                        if (!(c20)) {
                                            POLL();
                                            continue;
                                        } else {
                                            break;
                                        }
                                    }
                                }
                                POLL();
                            }
                            r0 = r13;
                            break;
                        }
                    }
                } else {
                    r10 = LD32(r9 + 24);
                    if ((r10 & r10) == 0) {
                        r10 = LD32(r9 + 28);
                    }
                    r0 = GCALL7(0x0607507C, r10, 0, 0, 0, v44, v40, v36);
                    r11 = r0;
                    r0 = GCALL7(0x0607507C, v44, 0, 0, 0, v44, v40, v36);
                    r6 = r0;
                    r5 = r10;
                    r0 = GCALL7(0x06045F9C, v44, r5, r6, r11, v44, v40, v36);
                    r3 = v36;
                    if ((r0 & r0) == 0) {
                        r14 = r14 + 1;
                        r1 = 99;
                        v36 = r3 + 44;
                        if (!(r14 > 99)) {
                            POLL();
                            continue;
                        } else {
                            r0 = r13;
                            if (!((v40 & v40) == 0)) {
                                break;
                            } else {
                                r14 = 0;
                                r11 = r1;
                                r7 = -1;
                                c1023 = 1;
                                while (1) {
                                    r6 = r7;
                                    r2 = 0;
                                    r5 = 0x0608BD10;
                                    do {
                                        r9 = r5;
                                        r1 = LD32(r9 + 40);
                                        c13 = (r1 & r1) == 0;
                                        r1 = r9;
                                        if (!(c13)) {
                                            r1 = LD16((r1 + 2));
                                            if (!((unsigned)r1 >= (unsigned)r6)) {
                                                r6 = r1;
                                                r7 = r2;
                                            }
                                        }
                                        r2 = r2 + 1;
                                        r5 = r5 + 44;
                                    } while (AGAIN(!(r2 > r11)));
                                    r3 = 44;
                                    if (!(r7 > -1)) {
                                        r14 = r14 + 1;
                                        c20 = r14 > r11;
                                        r7 = -1;
                                        c1023 = c20;
                                        c1033 = c20;
                                        if (!(c20)) {
                                            POLL();
                                            continue;
                                        } else {
                                            break;
                                        }
                                    } else {
                                        r9 = 0x0608BD10 + (r7 * r3);
                                        r10 = 0x06027F48;
                                        r4 = LD32(r9 + 40);
                                        r0 = GCALL7(0x06027F48, r4, r5, r6, r7, v44, v40, v36);
                                        r8 = 0;
                                        r4 = LD32(r9 + 28);
                                        ST32(r9 + 40, 0);
                                        if (!((r4 & r4) == 0)) {
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            SETIN(0, r0);
                                            r0 = GCALL7(r10, r4, r5, r6, r7, v44, v40, v36);
                                            ST32(r9 + 28, r8);
                                        }
                                        r1 = LD32(0x060791BC);
                                        r13 = 1;
                                        r12 = r12 - 1;
                                        c19 = r12 > 0;
                                        ST32(0x060791BC, (r1 - 1));
                                        c1033 = c19;
                                        if (!(c19)) {
                                            break;
                                        } else {
                                            r14 = r14 + 1;
                                            c20 = r14 > r11;
                                            r7 = -1;
                                            c1023 = c20;
                                            c1033 = c20;
                                            if (!(c20)) {
                                                POLL();
                                                continue;
                                            } else {
                                                break;
                                            }
                                        }
                                    }
                                    POLL();
                                }
                                r0 = r13;
                                break;
                            }
                        }
                    } else {
                        r4 = LD32(r9 + 40);
                        r7 = R(7);
                        r0 = GCALL7(0x06027F48, r4, r5, r6, 0, v44, v40, v36);
                        r4 = LD32(r9 + 28);
                        ST32(r9 + 40, 0);
                        if (!((r4 & r4) == 0)) {
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL7(0x06027F48, r4, 0, 0, 0, v44, v40, v36);
                            ST32(r9 + 28, 0);
                        }
                        r1 = LD32(0x060791BC);
                        r13 = 1;
                        r12 = r12 - 1;
                        c10 = r12 > 0;
                        ST32(0x060791BC, (r1 - 1));
                        c1033 = c10;
                        if (!(c10)) {
                            r0 = r13;
                            break;
                        } else {
                            r3 = v36;
                            r14 = r14 + 1;
                            r1 = 99;
                            v36 = r3 + 44;
                            if (!(r14 > 99)) {
                                POLL();
                                continue;
                            } else {
                                r0 = r13;
                                if (!((v40 & v40) == 0)) {
                                    break;
                                } else {
                                    r14 = 0;
                                    r11 = r1;
                                    r7 = -1;
                                    c1023 = 1;
                                    while (1) {
                                        r6 = r7;
                                        r2 = 0;
                                        r5 = 0x0608BD10;
                                        do {
                                            r9 = r5;
                                            r1 = LD32(r9 + 40);
                                            c13 = (r1 & r1) == 0;
                                            r1 = r9;
                                            if (!(c13)) {
                                                r1 = LD16((r1 + 2));
                                                if (!((unsigned)r1 >= (unsigned)r6)) {
                                                    r6 = r1;
                                                    r7 = r2;
                                                }
                                            }
                                            r2 = r2 + 1;
                                            r5 = r5 + 44;
                                        } while (AGAIN(!(r2 > r11)));
                                        r3 = 44;
                                        if (!(r7 > -1)) {
                                            r14 = r14 + 1;
                                            c20 = r14 > r11;
                                            r7 = -1;
                                            c1023 = c20;
                                            c1033 = c20;
                                            if (!(c20)) {
                                                POLL();
                                                continue;
                                            } else {
                                                break;
                                            }
                                        } else {
                                            r9 = 0x0608BD10 + (r7 * r3);
                                            r10 = 0x06027F48;
                                            r4 = LD32(r9 + 40);
                                            r0 = GCALL7(0x06027F48, r4, r5, r6, r7, v44, v40, v36);
                                            r8 = 0;
                                            r4 = LD32(r9 + 28);
                                            ST32(r9 + 40, 0);
                                            if (!((r4 & r4) == 0)) {
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                SETIN(0, r0);
                                                r0 = GCALL7(r10, r4, r5, r6, r7, v44, v40, v36);
                                                ST32(r9 + 28, r8);
                                            }
                                            r1 = LD32(0x060791BC);
                                            r13 = 1;
                                            r12 = r12 - 1;
                                            c19 = r12 > 0;
                                            ST32(0x060791BC, (r1 - 1));
                                            c1033 = c19;
                                            if (!(c19)) {
                                                break;
                                            } else {
                                                r14 = r14 + 1;
                                                c20 = r14 > r11;
                                                r7 = -1;
                                                c1023 = c20;
                                                c1033 = c20;
                                                if (!(c20)) {
                                                    POLL();
                                                    continue;
                                                } else {
                                                    break;
                                                }
                                            }
                                        }
                                        POLL();
                                    }
                                    r0 = r13;
                                    break;
                                }
                            }
                        }
                    }
                }
            } else {
                r4 = LD32(r9 + 40);
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL7(0x06027F48, r4, 0, 0, 0, v44, v40, v36);
                r4 = LD32(r9 + 28);
                ST32(r9 + 40, 0);
                if (!((r4 & r4) == 0)) {
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL7(0x06027F48, r4, 0, 0, 0, v44, v40, v36);
                    ST32(r9 + 28, 0);
                }
                r1 = LD32(0x060791BC);
                r13 = 1;
                r12 = r12 - 1;
                c5 = r12 > 0;
                ST32(0x060791BC, (r1 - 1));
                c1033 = c5;
                if (!(c5)) {
                    r0 = r13;
                    break;
                } else {
                    r3 = v44;
                    if ((r3 & r3) == 0) {
                        r3 = v36;
                        r14 = r14 + 1;
                        r1 = 99;
                        v36 = r3 + 44;
                        if (!(r14 > 99)) {
                            POLL();
                            continue;
                        } else {
                            r0 = r13;
                            if (!((v40 & v40) == 0)) {
                                break;
                            } else {
                                r14 = 0;
                                r11 = r1;
                                r7 = -1;
                                c1023 = 1;
                                while (1) {
                                    r6 = r7;
                                    r2 = 0;
                                    r5 = 0x0608BD10;
                                    do {
                                        r9 = r5;
                                        r1 = LD32(r9 + 40);
                                        c13 = (r1 & r1) == 0;
                                        r1 = r9;
                                        if (!(c13)) {
                                            r1 = LD16((r1 + 2));
                                            if (!((unsigned)r1 >= (unsigned)r6)) {
                                                r6 = r1;
                                                r7 = r2;
                                            }
                                        }
                                        r2 = r2 + 1;
                                        r5 = r5 + 44;
                                    } while (AGAIN(!(r2 > r11)));
                                    r3 = 44;
                                    if (!(r7 > -1)) {
                                        r14 = r14 + 1;
                                        c20 = r14 > r11;
                                        r7 = -1;
                                        c1023 = c20;
                                        c1033 = c20;
                                        if (!(c20)) {
                                            POLL();
                                            continue;
                                        } else {
                                            break;
                                        }
                                    } else {
                                        r9 = 0x0608BD10 + (r7 * r3);
                                        r10 = 0x06027F48;
                                        r4 = LD32(r9 + 40);
                                        r0 = GCALL7(0x06027F48, r4, r5, r6, r7, v44, v40, v36);
                                        r8 = 0;
                                        r4 = LD32(r9 + 28);
                                        ST32(r9 + 40, 0);
                                        if (!((r4 & r4) == 0)) {
                                            r5 = R(5);
                                            r6 = R(6);
                                            r7 = R(7);
                                            SETIN(0, r0);
                                            r0 = GCALL7(r10, r4, r5, r6, r7, v44, v40, v36);
                                            ST32(r9 + 28, r8);
                                        }
                                        r1 = LD32(0x060791BC);
                                        r13 = 1;
                                        r12 = r12 - 1;
                                        c19 = r12 > 0;
                                        ST32(0x060791BC, (r1 - 1));
                                        c1033 = c19;
                                        if (!(c19)) {
                                            break;
                                        } else {
                                            r14 = r14 + 1;
                                            c20 = r14 > r11;
                                            r7 = -1;
                                            c1023 = c20;
                                            c1033 = c20;
                                            if (!(c20)) {
                                                POLL();
                                                continue;
                                            } else {
                                                break;
                                            }
                                        }
                                    }
                                    POLL();
                                }
                                r0 = r13;
                                break;
                            }
                        }
                    } else {
                        r10 = LD32(r9 + 24);
                        if ((r10 & r10) == 0) {
                            r10 = LD32(r9 + 28);
                        }
                        r0 = GCALL7(0x0607507C, r10, 0, 0, 0, v44, v40, v36);
                        r11 = r0;
                        r0 = GCALL7(0x0607507C, v44, 0, 0, 0, v44, v40, v36);
                        r6 = r0;
                        r5 = r10;
                        r0 = GCALL7(0x06045F9C, v44, r5, r6, r11, v44, v40, v36);
                        r3 = v36;
                        if ((r0 & r0) == 0) {
                            r14 = r14 + 1;
                            r1 = 99;
                            v36 = r3 + 44;
                            if (!(r14 > 99)) {
                                POLL();
                                continue;
                            } else {
                                r0 = r13;
                                if (!((v40 & v40) == 0)) {
                                    break;
                                } else {
                                    r14 = 0;
                                    r11 = r1;
                                    r7 = -1;
                                    c1023 = 1;
                                    while (1) {
                                        r6 = r7;
                                        r2 = 0;
                                        r5 = 0x0608BD10;
                                        do {
                                            r9 = r5;
                                            r1 = LD32(r9 + 40);
                                            c13 = (r1 & r1) == 0;
                                            r1 = r9;
                                            if (!(c13)) {
                                                r1 = LD16((r1 + 2));
                                                if (!((unsigned)r1 >= (unsigned)r6)) {
                                                    r6 = r1;
                                                    r7 = r2;
                                                }
                                            }
                                            r2 = r2 + 1;
                                            r5 = r5 + 44;
                                        } while (AGAIN(!(r2 > r11)));
                                        r3 = 44;
                                        if (!(r7 > -1)) {
                                            r14 = r14 + 1;
                                            c20 = r14 > r11;
                                            r7 = -1;
                                            c1023 = c20;
                                            c1033 = c20;
                                            if (!(c20)) {
                                                POLL();
                                                continue;
                                            } else {
                                                break;
                                            }
                                        } else {
                                            r9 = 0x0608BD10 + (r7 * r3);
                                            r10 = 0x06027F48;
                                            r4 = LD32(r9 + 40);
                                            r0 = GCALL7(0x06027F48, r4, r5, r6, r7, v44, v40, v36);
                                            r8 = 0;
                                            r4 = LD32(r9 + 28);
                                            ST32(r9 + 40, 0);
                                            if (!((r4 & r4) == 0)) {
                                                r5 = R(5);
                                                r6 = R(6);
                                                r7 = R(7);
                                                SETIN(0, r0);
                                                r0 = GCALL7(r10, r4, r5, r6, r7, v44, v40, v36);
                                                ST32(r9 + 28, r8);
                                            }
                                            r1 = LD32(0x060791BC);
                                            r13 = 1;
                                            r12 = r12 - 1;
                                            c19 = r12 > 0;
                                            ST32(0x060791BC, (r1 - 1));
                                            c1033 = c19;
                                            if (!(c19)) {
                                                break;
                                            } else {
                                                r14 = r14 + 1;
                                                c20 = r14 > r11;
                                                r7 = -1;
                                                c1023 = c20;
                                                c1033 = c20;
                                                if (!(c20)) {
                                                    POLL();
                                                    continue;
                                                } else {
                                                    break;
                                                }
                                            }
                                        }
                                        POLL();
                                    }
                                    r0 = r13;
                                    break;
                                }
                            }
                        } else {
                            r4 = LD32(r9 + 40);
                            r7 = R(7);
                            r0 = GCALL7(0x06027F48, r4, r5, r6, 0, v44, v40, v36);
                            r4 = LD32(r9 + 28);
                            ST32(r9 + 40, 0);
                            if (!((r4 & r4) == 0)) {
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL7(0x06027F48, r4, 0, 0, 0, v44, v40, v36);
                                ST32(r9 + 28, 0);
                            }
                            r1 = LD32(0x060791BC);
                            r13 = 1;
                            r12 = r12 - 1;
                            c10 = r12 > 0;
                            ST32(0x060791BC, (r1 - 1));
                            c1033 = c10;
                            if (!(c10)) {
                                r0 = r13;
                                break;
                            } else {
                                r3 = v36;
                                r14 = r14 + 1;
                                r1 = 99;
                                v36 = r3 + 44;
                                if (!(r14 > 99)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = r13;
                                    if (!((v40 & v40) == 0)) {
                                        break;
                                    } else {
                                        r14 = 0;
                                        r11 = r1;
                                        r7 = -1;
                                        c1023 = 1;
                                        while (1) {
                                            r6 = r7;
                                            r2 = 0;
                                            r5 = 0x0608BD10;
                                            do {
                                                r9 = r5;
                                                r1 = LD32(r9 + 40);
                                                c13 = (r1 & r1) == 0;
                                                r1 = r9;
                                                if (!(c13)) {
                                                    r1 = LD16((r1 + 2));
                                                    if (!((unsigned)r1 >= (unsigned)r6)) {
                                                        r6 = r1;
                                                        r7 = r2;
                                                    }
                                                }
                                                r2 = r2 + 1;
                                                r5 = r5 + 44;
                                            } while (AGAIN(!(r2 > r11)));
                                            r3 = 44;
                                            if (!(r7 > -1)) {
                                                r14 = r14 + 1;
                                                c20 = r14 > r11;
                                                r7 = -1;
                                                c1023 = c20;
                                                c1033 = c20;
                                                if (!(c20)) {
                                                    POLL();
                                                    continue;
                                                } else {
                                                    break;
                                                }
                                            } else {
                                                r9 = 0x0608BD10 + (r7 * r3);
                                                r10 = 0x06027F48;
                                                r4 = LD32(r9 + 40);
                                                r0 = GCALL7(0x06027F48, r4, r5, r6, r7, v44, v40, v36);
                                                r8 = 0;
                                                r4 = LD32(r9 + 28);
                                                ST32(r9 + 40, 0);
                                                if (!((r4 & r4) == 0)) {
                                                    r5 = R(5);
                                                    r6 = R(6);
                                                    r7 = R(7);
                                                    SETIN(0, r0);
                                                    r0 = GCALL7(r10, r4, r5, r6, r7, v44, v40, v36);
                                                    ST32(r9 + 28, r8);
                                                }
                                                r1 = LD32(0x060791BC);
                                                r13 = 1;
                                                r12 = r12 - 1;
                                                c19 = r12 > 0;
                                                ST32(0x060791BC, (r1 - 1));
                                                c1033 = c19;
                                                if (!(c19)) {
                                                    break;
                                                } else {
                                                    r14 = r14 + 1;
                                                    c20 = r14 > r11;
                                                    r7 = -1;
                                                    c1023 = c20;
                                                    c1033 = c20;
                                                    if (!(c20)) {
                                                        POLL();
                                                        continue;
                                                    } else {
                                                        break;
                                                    }
                                                }
                                            }
                                            POLL();
                                        }
                                        r0 = r13;
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
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060466D0(void)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10;
    int v20;

    r0 = SR();
    SETSR((r0 | 240));
    r1 = LD32(0x06075994);
    if (!((r1 & r1) == 0)) {
        r0 = GCALL0(0x06066F38);
    }
    ST16(0x25D0000C, 0);
    ST16(0x25D00004, 0);
    r8 = 0;
    r0 = GCALL0(0x06051E6C);
    r1 = LD32(0x06000344);
    SETIN(0, r0);
    r0 = GCALL2(r1, -1, 0xBFFF);
    r10 = 0x06000310;
    r9 = 63;
    do {
        r1 = LD32(r10);
        SETIN(0, r0);
        r0 = GCALL2(r1, r8, 0);
        r8 = r8 + 1;
        r1 = 95;
    } while (AGAIN(!(r8 > r9)));
    if (!(r8 > r1)) {
        r9 = r1;
        r10 = 0x06000300;
        do {
            r1 = LD32(r10);
            SETIN(0, r0);
            r0 = GCALL2(r1, r8, 0);
            r8 = r8 + 1;
        } while (AGAIN(!(r8 > r9)));
    }
    r1 = 127;
    if (!(r8 > 127)) {
        r9 = r1;
        r10 = 0x06000310;
        do {
            r1 = LD32(r10);
            SETIN(0, r0);
            r0 = GCALL2(r1, r8, 0);
            r8 = r8 + 1;
        } while (AGAIN(!(r8 > r9)));
    }
    r3 = 0x20100063;
    do {
        r0 = LD8(r3);
        r1 = 1;
    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    ST8(r3, r1);
    ST8(0x2010001F, 3);
    r0 = LD8(r3);
    r1 = r3;
    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
        do {
            r0 = LD8(r1);
        } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    }
    r0 = LD8(-384);
    ST16(-384, (-23296 | (r0 & 223)));
    ST8(-496, 0);
    ST16(0x25C00000, -32768);
    r0 = GCALL3(0x0604B3F0, 0x25E00000, 0, 0x00080000);
    r0 = GCALL3(0x0604B3F0, 0x25C80000, 0, 0x00040000);
    ST16(0x25D00000, 0);
    ST16(0x25D00002, 3);
    v20 = 0;
    r2 = 0x4E1F;
    if (!(v20 > 0x4E1F)) {
        do {
            v20 = v20 + 1;
        } while (AGAIN(!(v20 > r2)));
    }
    r0 = GCALL5(0x0604B3F0, 0x25C80000, 0, 0x00040000, 0, v20);
    r8 = 0;
    r10 = 0x06000334;
    r9 = 255;
    do {
        r1 = LD32(r10);
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        SETIN(0, r0);
        r0 = GCALL5(r1, r8, r5, r6, r7, v20);
        r8 = r8 + 1;
    } while (AGAIN(!(r8 > r9)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046860(void)
{
    int r0, r1;

    r0 = SR();
    SETSR((r0 | 240));
    r0 = GCALL0(0x06066F38);
    r0 = GCALL0(0x06051E6C);
    r1 = LD32(0x0600026C);
    SETIN(0, r0);
    r0 = GCALL0(r1);
    while (1) {
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060468FC(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13;

    r13 = r4;
    r6 = (signed char)r6;
    r9 = r6;
    r11 = 0x060759B4;
    r1 = LD32(0x060759B4);
    r2 = r5 + r1;
    r4 = r2;
    if (!(r2 >= 0)) {
        r4 = r4 + 0x1FF;
    }
    r12 = 0x060727A6;
    r4 = HELPER((int)r4 >> 9);
    r10 = 0x06088030;
    r1 = LD32(0x06088030);
    r7 = 0x0608802C;
    r8 = 0x25E80000;
    r3 = LD32(0x0608802C);
    r2 = ((r2 - ((r4 << 8) + (r4 << 8))) * r1) + r13;
    r0 = r3;
    if (!((r3 + r2) > 0x25E80000)) {
        ST8(r0 + r2, r6);
        r1 = LD32(r7);
        ST8(((r1 + r2) + 1), r6);
        r1 = LD32(r11);
        r2 = r5 + (r1 + 1);
        r4 = r2;
        if (!(r2 >= 0)) {
            r4 = r4 + 0x1FF;
        }
        r1 = LD32(r10);
        SETIN(0, r0);
        SETIN(1, r1);
        SETIN(2, r2);
        r0 = GCALL4(r12, r4, r5, r6, r7);
        r4 = R(4);
        r2 = R(2);
        r1 = R(1);
        r7 = R(7);
        r3 = LD32(r7);
        r2 = ((r2 - ((r4 << 8) + (r4 << 8))) * r1) + r13;
        r0 = r3;
        if (!((r3 + r2) > r8)) {
            ST8(r0 + r2, r9);
            r1 = LD32(r7);
            ST8(((r1 + r2) + 1), r9);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060469B4(int r4)
{
    int r0, r1, r5, r6, r8, r9, r10, r11;
    long long m0;

    r11 = 0x060468E8;
    r8 = r4;
    r0 = GCALL0(0x060468E8);
    r0 = (short)r0;
    r4 = r0;
    if (!(r0 >= 0)) {
        r4 = r4 + 63;
    }
    r10 = 0x060727AC;
    r9 = 64;
    r4 = HELPER((int)r4 >> 6);
    r4 = ((r4 << 2) << 2) << 2;
    ST32(r8 + 8, ((short)(r0 - r4)));
    SETIN(0, r0);
    r0 = GCALL1(r11, r4);
    r0 = (short)r0;
    r4 = r0;
    if (!(r0 >= 0)) {
        r4 = r4 + 63;
    }
    SETIN(0, r0);
    r0 = GCALL1(r10, r4);
    r4 = R(4);
    r0 = r0 - (r4 * r9);
    ST32(r8 + 12, ((short)r0));
    r9 = 200;
    ST32(r8 + 16, 200);
    SETIN(0, r0);
    r0 = GCALL1(r11, r4);
    r0 = r0 & 1;
    if ((r0 & r0) == 0) {
        r1 = LD32(r8 + 8);
        ST32(r8 + 8, (-r1));
    }
    SETIN(0, r0);
    r0 = GCALL0(r11);
    if (((r0 & 1) & (r0 & 1)) == 0) {
        r1 = LD32(r8 + 12);
        ST32(r8 + 12, (-r1));
    }
    r1 = LD32(r8 + 8);
    r5 = LD32(r8 + 16);
    r0 = GCALL2(0x0607286C, (r1 * r9), r5);
    r1 = LD32(0x06089624);
    ST32(r8 + 20, (r1 + r0));
    r1 = LD32(r8 + 12);
    r5 = LD32(r8 + 16);
    r4 = r1 * r9;
    r0 = GCALL2(0x0607286C, r4, r5);
    r1 = LD32(0x06089628);
    ST32(r8 + 24, (r1 + r0));
    SETIN(0, r0);
    r0 = GCALL4(r11, r4, r5, 0x0607286C, 0x06089624);
    r6 = (short)r0;
    m0 = (long long)r6 * ((int)0x81020409);
    r4 = HELPER((int)(((int)(m0 >> 32)) + r6) >> 7);
    r6 = (r6 - ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)((r4 - (((r6 << 1) - (r6 << 1)) - ((unsigned)r6 >> 31))) * 254)))) + 1;
    ST8((r8 + 4), r6);
    r5 = LD32(r8 + 24);
    r4 = LD32(r8 + 20);
    r0 = GCALL3(0x060468FC, r4, r5, ((signed char)r6));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06046E64(int r4)
{
    int r0, r1, r2, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, c14, c18, c1011, c1033, c2011, c2012, c2013, c2014;
    FRAME(sp, 360);

    r13 = R(13);
    r14 = R(14);
    r10 = r4;
    r2 = (sp - 348) + 0x130;
    ST8((sp - 348) + 0x130, -50);
    ST32((0x138 + (sp - 348)), (r2 + 1));
    r0 = LD32((0x138 + (sp - 348)));
    ST8(r0, 86);
    ST32((0x138 + (sp - 348)), (r2 + 2));
    r0 = LD32((0x138 + (sp - 348)));
    ST8(r0, 40);
    ST8((r2 + 3), 20);
    ST32((0x134 + (sp - 348)), 1);
    r1 = LD32(r10);
    if (!(r1 >= 0)) {
        goto L06046EC6;
    }
    goto L0604704E;
    L06046EC6:
    r7 = LD32((0x134 + (sp - 348)));
    r0 = GCALL4(0x060279E0, 0, 44, -1, r7);
    r9 = r0;
    r0 = -3;
    if (!((r9 & r9) == 0)) {
        goto L06046EE2;
    }
    goto L060471F6;
    L06046EE2:
    r0 = GCALL1(0x06010510, 0x06046E20);
    r4 = LD32(r10 + 44);
    r0 = GCALL3(0x0605A15C, r4, r9, 0);
    r11 = 0x060766B4;
    r12 = 0x06027F48;
    L06046EF8:
    c2011 = R(11);
    SETR(11, r11);
    c2012 = R(12);
    SETR(12, r12);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL1(0x0605A2A8, r9);
    SETR(11, c2011);
    SETR(12, c2012);
    SETR(13, c2013);
    SETR(14, c2014);
    r1 = LD32(r11);
    r8 = r0;
    if ((r1 & r1) == 0) {
        goto L06046F30;
    }
    r0 = LD32(0x0608D388);
    r0 = LD8(r0 + 226);
    c1011 = (r8 & r8) == 0;
    if (r0 == 1) {
        goto L06046F32;
    }
    r0 = GCALL0(0x0605299C);
    ST32(r11, 0);
    if (!((r8 & r8) == 0)) {
        goto L06046F28;
    }
    r0 = GCALL1(0x0605A290, r9);
    L06046F28:
    SETIN(0, r0);
    r0 = GCALL1(r12, r9);
    r0 = -12;
    goto L060471F6;
    L06046F30:
    c1011 = (r8 & r8) == 0;
    L06046F32:
    if (c1011) {
        POLL();
        goto L06046EF8;
    }
    r1 = LD32(r9);
    r11 = 0x130;
    r0 = sp - 348;
    ST32(r0 + 0x130, r1);
    SETIN(0, r0);
    r0 = GCALL1(r12, r9);
    if (r8 >= 0) {
        goto L06046F56;
    }
    r0 = r8;
    if (!(r8 == -506)) {
        goto L06046F50;
    }
    goto L060471F6;
    L06046F50:
    r0 = -900;
    goto L060471F6;
    L06046F56:
    r4 = LD32(r10 + 52);
    if ((r4 & r4) == 0) {
        goto L06046F62;
    }
    r0 = GCALL1(0x06027F48, r4);
    L06046F62:
    r0 = GCALL4(0x060279E0, 0, 0x1FE4, -1, 1);
    r2 = r0;
    ST32(r10 + 52, r2);
    if (!((r2 & r2) == 0)) {
        goto L06046FB4;
    }
    r0 = -3;
    goto L060471F6;
    L06046FB4:
    r0 = sp - 348;
    r1 = LD8(r0 + r11);
    ST8(r2, r1);
    r1 = LD32(r10 + 52);
    r2 = LD8(r0 + 0x131);
    ST8((r1 + 1), r2);
    r1 = LD32(r10 + 52);
    r2 = LD8(r0 + 0x132);
    ST8((r1 + 2), r2);
    r1 = LD32(r10 + 52);
    r2 = LD8(r0 + 0x133);
    ST8((r1 + 3), r2);
    r1 = LD32(r10 + 52);
    ST32((0x138 + (sp - 348)), (r10 + 42));
    r0 = LD32((0x138 + (sp - 348)));
    r2 = LD16(r0);
    ST16((r1 + 4), r2);
    r1 = LD32(r10 + 52);
    r0 = sp - 348;
    ST16((r1 + 6), 0);
    r7 = LD8(r0 + 0x131);
    r6 = LD8(r0 + r11);
    r8 = (sp - 348) + 0x110;
    r0 = LD32((0x138 + (sp - 348)));
    r1 = LD16(r0);
    ST32((sp - 352), r1);
    r1 = LD8(0x133 + (4 + (sp - 352)));
    ST32((sp - 356), (r1 & 255));
    r1 = LD8(0x132 + (8 + (sp - 356)));
    ST32((sp - 360), (r1 & 255));
    r0 = GCALL7(0x06045264, r8, 0x06046E30, (r6 & 255), (r7 & 255), LD32((sp - 360)), LD32((sp - 356)), LD32((sp - 352)));
    r0 = GCALL7(0x0605AE6C, r8, 0, 0, 0, LD32((sp - 360)), LD32((sp - 356)), LD32((sp - 352)));
    r1 = r0;
    ST32(r10, r1);
    if (!(r1 >= 0)) {
        POLL();
        goto L06046F50;
    }
    r0 = GCALL3(0x0605AF48, r1, 1, 25);
    L0604704E:
    r0 = GCALL3(0x0604B3F0, (sp - 212), 0, 136);
    r0 = GCALL3(0x0604B3F0, (sp - 348), 0, 136);
    r13 = 112;
    ST16(sp - 348, 112);
    ST16((sp - 346), 0x7E6);
    r1 = LD16((r10 + 40));
    ST16((sp - 336), r1);
    r1 = LD32(0x06046E40);
    ST32(sp - 328, r1);
    r0 = GCALL5(0x06046DD8, (sp - 307), 0, 0, 0, LD32((sp - 348)));
    ST8((sp - 240), r0);
    r1 = LD16(0x06046E40);
    ST16((sp - 266), r1);
    r1 = LD16(0x06046E42);
    ST16((sp - 264), r1);
    r4 = LD32(r10 + 52);
    r0 = GCALL5(0x0604B358, (r4 + 8), (sp - 348), 112, 0, LD32((sp - 348)));
    r11 = 0;
    r0 = GCALL5(0x06010510, 0x06046E44, 0, 0, 0, LD32((sp - 348)));
    r14 = 0x0605AF90;
    L060470B6:
    r5 = LD32(r10 + 52);
    r4 = LD32(r10);
    r7 = R(7);
    r0 = GCALL5(0x0605B0D8, r4, r5, r13, 0, LD32((sp - 348)));
    r8 = 0;
    if (r0 >= 0) {
        goto L060470CC;
    }
    POLL();
    goto L06046F50;
    L060470CC:
    r1 = LD32(0x0608B980);
    r9 = 5;
    ST32(r10 + 8, r1);
    r12 = LD32(0x06046E60);
    L060470D8:
    r5 = LD32(r10 + 52);
    r4 = LD32(r10);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r14, r4, r5, 0x1FE4, r7, LD32((sp - 348)));
    r2 = r0;
    c14 = r2 >= 0;
    if (!(r2 == -502)) {
        goto L06047158;
    }
    r1 = LD32(0x0608B980);
    r2 = LD32(r10 + 8);
    if (!(((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)((r1 - r2) + 5) * (unsigned)r12)) >> 32)) >> 2)) >> 1)) > r9)) {
        POLL();
        goto L060470D8;
    }
    r11 = r11 + 1;
    c18 = 1 == 0;
    c1033 = c18;
    if (!(r11 > r9)) {
        goto L06047168;
    }
    POLL();
    goto L06046F50;
    L06047158:
    c1033 = (r8 & r8) == 0;
    if (c14) {
        goto L06047168;
    }
    r0 = r2;
    if (r2 == -506) {
        goto L060471F6;
    }
    POLL();
    goto L06046F50;
    L06047168:
    r6 = 84;
    if (!(c1033)) {
        POLL();
        goto L060470B6;
    }
    r8 = 0x0604B358;
    r5 = LD32(r10 + 52);
    r0 = GCALL5(0x0604B358, (sp - 212), (r5 + 8), r6, 0, LD32((sp - 348)));
    r0 = LD32(0x134 + (sp - 348));
    if ((r0 & r0) == 0) {
        goto L060471A6;
    }
    r0 = LD8(172 + (sp - 348));
    r1 = sp - 348;
    if (!(r0 == 73)) {
        goto L060471A6;
    }
    ST16((r1 + 2), 0x7E7);
    r4 = LD32(r10 + 52);
    r7 = R(7);
    SETIN(0, r0);
    r0 = GCALL5(r8, (r4 + 8), (sp - 348), r13, r7, LD32((sp - 348)));
    ST32((0x134 + (sp - 348)), 0);
    POLL();
    goto L060470B6;
    L060471A6:
    r1 = LD32(148 + (sp - 348));
    ST32(r10 + 28, r1);
    r1 = LD32(160 + (sp - 348));
    ST32(r10 + 32, r1);
    r1 = LD32(164 + (sp - 348));
    ST32(r10 + 36, r1);
    r1 = LD16(152 + (sp - 348));
    r4 = 0x0608AE44;
    ST16((r10 + 24), r1);
    r1 = LD16(154 + (sp - 348));
    ST16((r10 + 26), r1);
    r1 = LD8(0x0608AE44);
    r5 = sp - 348;
    if (!((r1 & r1) == 0)) {
        goto L060471E4;
    }
    r0 = GCALL5(0x060750DC, r4, (r5 + 174), 0, 0, LD32((sp - 348)));
    r0 = GCALL5(0x06010EE0, 0, 0, 0, 0, LD32((sp - 348)));
    L060471E4:
    r0 = GCALL5(0x06010510, 0x06046E54, 0, 0, 0, LD32((sp - 348)));
    r4 = LD8(172 + (sp - 348));
    r0 = GCALL5(0x06046D54, r4, 0, 0, 0, LD32((sp - 348)));
    L060471F6:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06047784(int r4)
{
    int r0, r1, r5, r6, r8, r9, r10, r11, r12, r13;
    FRAME(sp, 96);

    r9 = r4;
    r1 = LD8(r9);
    if (!((r1 & r1) == 0)) {
        r10 = 0x06075238;
        r11 = 0x06047668;
        r12 = 0x060897A1;
        r13 = 0x060897A2;
        r6 = 9;
        while (1) {
            r0 = GCALL3(r10, r9, 0x060476A8, r6);
            r6 = 9;
            if (!((r0 & r0) == 0)) {
                SETIN(0, r0);
                r0 = GCALL3(r10, r9, 0x060476B4, r6);
                r6 = 9;
                if (!((r0 & r0) == 0)) {
                    SETIN(0, r0);
                    r0 = GCALL3(r10, r9, 0x060476C0, r6);
                    r6 = 7;
                    if (!((r0 & r0) == 0)) {
                        SETIN(0, r0);
                        r0 = GCALL3(r10, r9, 0x060476CC, r6);
                        r6 = 7;
                        if (!((r0 & r0) == 0)) {
                            SETIN(0, r0);
                            r0 = GCALL3(r10, r9, 0x060476D4, r6);
                            r6 = 5;
                            if (!((r0 & r0) == 0)) {
                                SETIN(0, r0);
                                r0 = GCALL3(r10, r9, 0x060476DC, r6);
                                r6 = 5;
                                if (!((r0 & r0) == 0)) {
                                    SETIN(0, r0);
                                    r0 = GCALL3(r10, r9, 0x060476E8, r6);
                                    r6 = 9;
                                    if (!((r0 & r0) == 0)) {
                                        SETIN(0, r0);
                                        r0 = GCALL3(r10, r9, 0x060476F0, r6);
                                        r6 = 9;
                                        if (!((r0 & r0) == 0)) {
                                            SETIN(0, r0);
                                            r0 = GCALL3(r10, r9, 0x060476FC, r6);
                                            r6 = 9;
                                            if (!((r0 & r0) == 0)) {
                                                SETIN(0, r0);
                                                r0 = GCALL3(r10, r9, 0x06047708, r6);
                                                r6 = 12;
                                                if (!((r0 & r0) == 0)) {
                                                    SETIN(0, r0);
                                                    r0 = GCALL3(r10, r9, 0x06047714, r6);
                                                    r6 = 9;
                                                    if (!((r0 & r0) == 0)) {
                                                        SETIN(0, r0);
                                                        r0 = GCALL3(r10, r9, 0x06047724, r6);
                                                        r6 = 10;
                                                        if (!((r0 & r0) == 0)) {
                                                            SETIN(0, r0);
                                                            r0 = GCALL3(r10, r9, 0x06047738, r6);
                                                            r6 = 10;
                                                            if (!((r0 & r0) == 0)) {
                                                                SETIN(0, r0);
                                                                r0 = GCALL3(r10, r9, 0x0604774C, r6);
                                                                r6 = 10;
                                                                if (!((r0 & r0) == 0)) {
                                                                    SETIN(0, r0);
                                                                    r0 = GCALL3(r10, r9, 0x06047758, r6);
                                                                    r6 = 13;
                                                                    if (!((r0 & r0) == 0)) {
                                                                        SETIN(0, r0);
                                                                        r0 = GCALL3(r10, r9, 0x06047764, r6);
                                                                        r6 = 5;
                                                                        if (!((r0 & r0) == 0)) {
                                                                            SETIN(0, r0);
                                                                            r0 = GCALL3(r10, r9, 0x06047774, r6);
                                                                            r6 = 5;
                                                                            if (!((r0 & r0) == 0)) {
                                                                                SETIN(0, r0);
                                                                                r0 = GCALL3(r10, r9, 0x0604777C, r6);
                                                                                if (!((r0 & r0) == 0)) {
                                                                                    r9 = r9 + 1;
                                                                                } else {
                                                                                    r9 = r9 + 5;
                                                                                    r6 = 32;
                                                                                    r5 = r9;
                                                                                    r4 = 0x060898E4;
                                                                                    SETIN(0, r0);
                                                                                    r0 = GCALL3(r11, r4, r5, r6);
                                                                                    r9 = r9 + r0;
                                                                                }
                                                                            } else {
                                                                                r9 = r9 + 5;
                                                                                r6 = 32;
                                                                                r4 = 0x060898C4;
                                                                                r5 = r9;
                                                                                SETIN(0, r0);
                                                                                r0 = GCALL3(r11, r4, r5, r6);
                                                                                r9 = r9 + r0;
                                                                            }
                                                                        } else {
                                                                            r9 = r9 + 13;
                                                                            r6 = 32;
                                                                            r4 = 0x06089884;
                                                                            r5 = r9;
                                                                            SETIN(0, r0);
                                                                            r0 = GCALL3(r11, r4, r5, r6);
                                                                            r9 = r9 + r0;
                                                                        }
                                                                    } else {
                                                                        r9 = r9 + 10;
                                                                        r6 = 32;
                                                                        r4 = 0x06089864;
                                                                        r5 = r9;
                                                                        SETIN(0, r0);
                                                                        r0 = GCALL3(r11, r4, r5, r6);
                                                                        r9 = r9 + r0;
                                                                    }
                                                                } else {
                                                                    r9 = r9 + 10;
                                                                    r6 = 32;
                                                                    r4 = 0x06089844;
                                                                    r5 = r9;
                                                                    SETIN(0, r0);
                                                                    r0 = GCALL3(r11, r4, r5, r6);
                                                                    r9 = r9 + r0;
                                                                }
                                                            } else {
                                                                r9 = r9 + 10;
                                                                r0 = GCALL3(0x060752FC, r9, 0x06047744, 4);
                                                                r1 = 0;
                                                                if ((r0 & r0) == 0) {
                                                                    r1 = 1;
                                                                }
                                                                ST8(r13, r1);
                                                                r9 = r9 + 4;
                                                            }
                                                        } else {
                                                            r9 = r9 + 9;
                                                            r0 = GCALL3(0x060752FC, r9, 0x06047730, 4);
                                                            r1 = 0;
                                                            if ((r0 & r0) == 0) {
                                                                r1 = 1;
                                                            }
                                                            ST8(r12, r1);
                                                            r9 = r9 + 4;
                                                        }
                                                    } else {
                                                        r9 = r9 + 12;
                                                        r6 = 32;
                                                        r4 = 0x060897A4;
                                                        r5 = r9;
                                                        SETIN(0, r0);
                                                        r0 = GCALL3(r11, r4, r5, r6);
                                                        r9 = r9 + r0;
                                                    }
                                                } else {
                                                    r9 = r9 + 9;
                                                    r6 = 32;
                                                    r4 = 0x060897C4;
                                                    r5 = r9;
                                                    SETIN(0, r0);
                                                    r0 = GCALL3(r11, r4, r5, r6);
                                                    r9 = r9 + r0;
                                                }
                                            } else {
                                                r9 = r9 + 9;
                                                r6 = 32;
                                                r4 = 0x06089944;
                                                r5 = r9;
                                                SETIN(0, r0);
                                                r0 = GCALL3(r11, r4, r5, r6);
                                                r9 = r9 + r0;
                                            }
                                        } else {
                                            r9 = r9 + 9;
                                            r6 = 32;
                                            r4 = 0x06089924;
                                            r5 = r9;
                                            SETIN(0, r0);
                                            r0 = GCALL3(r11, r4, r5, r6);
                                            r9 = r9 + r0;
                                        }
                                        r1 = LD8(r9);
                                    } else {
                                        r9 = r9 + 5;
                                        r8 = (sp - 96) + 32;
                                        SETIN(0, r0);
                                        r0 = GCALL3(r11, r8, r9, 32);
                                        r9 = r9 + r0;
                                        r0 = GCALL2(0x06075408, r8, 0x060476E4);
                                        r0 = GCALL3(0x06059CE4, r8, 0x060899A8, (sp - 32));
                                        r1 = LD8(r9);
                                    }
                                } else {
                                    r9 = r9 + 5;
                                    SETIN(0, r0);
                                    r0 = GCALL3(r11, (sp - 96), r9, 32);
                                    r9 = r9 + r0;
                                    r0 = GCALL2(0x06075408, (sp - 96), 0x060476E4);
                                    r0 = GCALL3(0x06059CE4, (sp - 96), 0x060899A4, (sp - 32));
                                    r1 = LD8(r9);
                                }
                            } else {
                                r9 = r9 + 7;
                                r6 = 32;
                                r4 = 0x06089984;
                                r5 = r9;
                                SETIN(0, r0);
                                r0 = GCALL3(r11, r4, r5, r6);
                                r9 = r9 + r0;
                                r1 = LD8(r9);
                            }
                        } else {
                            r9 = r9 + 7;
                            r6 = 32;
                            r4 = 0x06089964;
                            r5 = r9;
                            SETIN(0, r0);
                            r0 = GCALL3(r11, r4, r5, r6);
                            r9 = r9 + r0;
                            r1 = LD8(r9);
                        }
                    } else {
                        r9 = r9 + 9;
                        r6 = 32;
                        r4 = 0x06089824;
                        r5 = r9;
                        SETIN(0, r0);
                        r0 = GCALL3(r11, r4, r5, r6);
                        r9 = r9 + r0;
                        r1 = LD8(r9);
                    }
                } else {
                    r9 = r9 + 9;
                    r6 = 32;
                    r4 = 0x06089804;
                    r5 = r9;
                    SETIN(0, r0);
                    r0 = GCALL3(r11, r4, r5, r6);
                    r9 = r9 + r0;
                    r1 = LD8(r9);
                }
            } else {
                r9 = r9 + 9;
                r6 = 32;
                r4 = 0x060897E4;
                r5 = r9;
                SETIN(0, r0);
                r0 = GCALL3(r11, r4, r5, r6);
                r9 = r9 + r0;
                r1 = LD8(r9);
            }
            r6 = 9;
            if ((r1 & r1) == 0) {
                break;
            }
            POLL();
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06047B60(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c6, c7, c15, c16, c18, c19, c22, c24, c25, c26, c1015, c1020, c1039, c1043, c1049, c1053;
    FRAME(sp, 252);

    ST32(128 + (sp - 188), r4);
    ST32((132 + (sp - 188)), r5);
    ST32((136 + (sp - 188)), r7);
    r8 = LD32((188 + (sp - 188)));
    ST32((148 + (sp - 188)), 1);
    r12 = LD32(128 + (sp - 188));
    ST32(r12, 0);
    r12 = LD32(132 + (sp - 188));
    ST32(r12, 0);
    ST32(r8, 0);
    r9 = LD32((136 + (sp - 188)));
    r14 = 0x06075238;
    r9 = r9 + 108;
    r4 = LD32(r9);
    r0 = GCALL3(0x06075238, r4, 0x06047A60, 4);
    r4 = sp - 188;
    if ((r0 & r0) == 0) {
        r3 = LD32(0x06047A68);
        ST32(sp - 188, r3);
        r1 = LD32(0x06047A6C);
        ST32(sp - 184, r1);
        r1 = LD16(0x06047A70);
        ST16((sp - 180), r1);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL6(0x06025948, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
        ST32((152 + (sp - 188)), r0);
        r5 = LD32((152 + (sp - 188)));
        r7 = LD32((148 + (sp - 188)));
        r0 = GCALL6(0x060279E0, 0, (r5 + 1), -1, r7, LD32((sp - 188)), LD32((sp - 184)));
        r11 = r0;
        r8 = sp - 188;
        if (!((r11 & r11) == 0)) {
            r8 = r8 + 16;
            r0 = GCALL6(0x0604B3F0, r8, 0, 48, 0, LD32((sp - 188)), LD32((sp - 184)));
            r7 = LD32((152 + (sp - 188)));
            r0 = GCALL6(0x060258EC, (sp - 188), r8, r11, r7, LD32((sp - 188)), LD32((sp - 184)));
            r0 = GCALL6(0x06025984, r8, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
            r0 = GCALL6(0x0603CCE0, 0x060767CC, 0x06047A74, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
            r4 = LD32(0x060767CC);
            r7 = R(7);
            r0 = GCALL6(0x06048C08, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
            r10 = 0x060897E4;
            r0 = GCALL6(0x0607507C, 0x060897E4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
            r8 = LD32(152 + (sp - 188));
            r8 = r8 + r0;
            r0 = GCALL6(0x0607507C, 0x06089804, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
            r8 = r8 + r0;
            r14 = 0x06089824;
            r0 = GCALL6(0x0607507C, 0x06089824, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
            r7 = LD32((148 + (sp - 188)));
            r0 = GCALL6(0x060279E0, 0, ((r8 + r0) + 1), -1, r7, LD32((sp - 188)), LD32((sp - 184)));
            r12 = LD32((128 + (sp - 188)));
            ST32(r12, r0);
            r1 = LD32((152 + (sp - 188)));
            ST8(((r1 + r11) - 1), 0);
            r12 = LD32((128 + (sp - 188)));
            r4 = LD32(r12);
            if (!((r4 & r4) == 0)) {
                ST32((sp - 192), r14);
                r0 = GCALL7(0x06045264, r4, r11, r10, 0x06089804, LD32((sp - 192)), LD32((sp - 188)), LD32((sp - 184)));
            }
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL6(0x06027F48, r11, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
        }
        ST32((148 + (sp - 188)), 0);
    } else {
        r4 = LD32(r9);
        r7 = R(7);
        SETIN(0, r0);
        r0 = GCALL6(r14, r4, 0x06047A84, 4, r7, LD32((sp - 188)), LD32((sp - 184)));
        if ((r0 & r0) == 0) {
            r1 = LD32((136 + (sp - 188)));
            r11 = LD32((r1 + 104));
            r0 = GCALL6(0x06047784, r11, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
            r3 = LD32(0x06047A8C);
            ST32(sp - 188, r3);
            r2 = LD32(0x06047A90);
            ST32(sp - 184, r2);
            r2 = LD16(0x06047A94);
            r3 = (sp - 188) + 8;
            ST16(r3, r2);
            r1 = LD8(0x06047A96);
            ST8((r3 + 2), r1);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL6(0x06025948, (sp - 188), 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
            ST32((152 + (sp - 188)), r0);
            r5 = LD32((152 + (sp - 188)));
            r7 = LD32((148 + (sp - 188)));
            r0 = GCALL6(0x060279E0, 0, (r5 + 1), -1, r7, LD32((sp - 188)), LD32((sp - 184)));
            r11 = r0;
            r8 = sp - 188;
            if (!((r11 & r11) == 0)) {
                r8 = r8 + 16;
                r0 = GCALL6(0x0604B3F0, r8, 0, 48, 0, LD32((sp - 188)), LD32((sp - 184)));
                r7 = LD32((152 + (sp - 188)));
                r0 = GCALL6(0x060258EC, (sp - 188), r8, r11, r7, LD32((sp - 188)), LD32((sp - 184)));
                r0 = GCALL6(0x06025984, r8, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                r0 = GCALL6(0x0603CCE0, 0x060767CC, 0x06047A98, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                r4 = LD32(0x060767CC);
                r7 = R(7);
                r0 = GCALL6(0x06048C08, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                r7 = LD8(0x060899A5);
                r6 = LD8(0x060899A4);
                ST32((140 + (sp - 188)), (sp - 124));
                r1 = LD8(0x060899A7);
                ST32((sp - 192), (r1 & 255));
                r1 = LD8(0x060899A6);
                ST32((sp - 196), (r1 & 255));
                r4 = LD32((148 + (sp - 196)));
                r0 = GCALL8(0x06045264, r4, 0x06047AA8, (r6 & 255), (r7 & 255), LD32((sp - 196)), LD32((sp - 192)), LD32((sp - 188)), LD32((sp - 184)));
                r14 = (sp - 196) + 104;
                r7 = LD8(0x060899A9);
                r6 = LD8(0x060899A8);
                r1 = LD8(0x060899AB);
                ST32((sp - 200), (r1 & 255));
                r1 = LD8(0x060899AA);
                ST32((sp - 204), (r1 & 255));
                r0 = GCALL8(0x06045264, r14, 0x06047AA8, (r6 & 255), (r7 & 255), LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r0 = GCALL8(0x0607507C, 0x06089964, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r8 = LD32((168 + (sp - 204)));
                r8 = r8 + r0;
                r0 = GCALL8(0x0607507C, 0x06089984, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r4 = LD32(156 + (sp - 204));
                r8 = r8 + r0;
                r0 = GCALL8(0x0607507C, r4, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r8 = r8 + r0;
                r0 = GCALL8(0x0607507C, r14, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r8 = r8 + r0;
                r0 = GCALL8(0x0607507C, 0x06089924, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r8 = r8 + r0;
                r0 = GCALL8(0x0607507C, 0x06089944, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r8 = r8 + r0;
                r0 = GCALL8(0x0607507C, 0x060897C4, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r8 = (r8 + r0) + 14;
                r10 = 0x060897A4;
                r0 = GCALL8(0x0607507C, 0x060897A4, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r7 = LD32((164 + (sp - 204)));
                r0 = GCALL8(0x060279E0, 0, ((r8 + r0) + 1), -1, r7, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                r12 = LD32((144 + (sp - 204)));
                ST32(r12, r0);
                r1 = LD32((168 + (sp - 204)));
                ST8(((r1 + r11) - 1), 0);
                r12 = LD32(128 + (sp - 188));
                r4 = LD32(r12);
                if (!((r4 & r4) == 0)) {
                    r2 = 0x060897A2;
                    r1 = LD8(0x060897A2);
                    c6 = (r1 & r1) == 0;
                    r1 = 0x06047ABC;
                    c1015 = c6;
                    if (c6) {
                        r1 = 0x06047AB4;
                        c1015 = 1;
                    }
                    ST32((sp - 192), r1);
                    r1 = 0x06047ABC;
                    if (!(c1015)) {
                        r1 = 0x06047AB4;
                    }
                    ST32((sp - 196), r1);
                    r1 = LD8((r2 - 1));
                    c7 = (r1 & r1) == 0;
                    r1 = 0x06047ABC;
                    c1020 = c7;
                    if (c7) {
                        r1 = 0x06047AB4;
                        c1020 = 1;
                    }
                    ST32((sp - 200), r1);
                    r1 = 0x06047ABC;
                    if (!(c1020)) {
                        r1 = 0x06047AB4;
                    }
                    ST32((sp - 204), r1);
                    ST32((sp - 208), r10);
                    ST32((sp - 212), 0x060897C4);
                    ST32((sp - 216), 0x06089944);
                    ST32((sp - 220), 0x06089924);
                    ST32((sp - 224), r14);
                    r13 = LD32((176 + (sp - 224)));
                    ST32((sp - 228), r13);
                    r0 = GCALL8(0x06045264, r4, r11, 0x06089964, 0x06089984, LD32((sp - 228)), LD32((sp - 224)), LD32((sp - 220)), LD32((sp - 216)));
                }
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL6(0x06027F48, r11, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
            }
            ST32((148 + (sp - 188)), 0);
        } else {
            r4 = LD32(r9);
            r7 = R(7);
            SETIN(0, r0);
            r0 = GCALL6(r14, r4, 0x06047AC0, 4, r7, LD32((sp - 188)), LD32((sp - 184)));
            if ((r0 & r0) == 0) {
                r1 = LD32(136 + (sp - 188));
                r11 = LD32((r1 + 104));
                r0 = GCALL6(0x06047784, r11, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                r3 = LD32(0x06047AC8);
                ST32(sp - 188, r3);
                r2 = LD32(0x06047ACC);
                ST32(sp - 184, r2);
                r2 = LD16(0x06047AD0);
                r3 = (sp - 188) + 8;
                ST16(r3, r2);
                r1 = LD8(0x06047AD2);
                ST8((r3 + 2), r1);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL6(0x06025948, (sp - 188), 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                ST32((152 + (sp - 188)), r0);
                r5 = LD32((152 + (sp - 188)));
                r7 = LD32((148 + (sp - 188)));
                r0 = GCALL6(0x060279E0, 0, (r5 + 1), -1, r7, LD32((sp - 188)), LD32((sp - 184)));
                r11 = r0;
                r8 = sp - 188;
                if (!((r11 & r11) == 0)) {
                    r8 = r8 + 16;
                    r0 = GCALL6(0x0604B3F0, r8, 0, 48, 0, LD32((sp - 188)), LD32((sp - 184)));
                    r7 = LD32((152 + (sp - 188)));
                    r0 = GCALL6(0x060258EC, (sp - 188), r8, r11, r7, LD32((sp - 188)), LD32((sp - 184)));
                    r0 = GCALL6(0x06025984, r8, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    r0 = GCALL6(0x0603CCE0, 0x060767CC, 0x06047AD4, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    r4 = LD32(0x060767CC);
                    r7 = R(7);
                    r0 = GCALL6(0x06048C08, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    r10 = 0x06089844;
                    r0 = GCALL6(0x0607507C, 0x06089844, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    r8 = LD32((152 + (sp - 188)));
                    r8 = r8 + r0;
                    r0 = GCALL6(0x0607507C, 0x06089864, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    r8 = r8 + r0;
                    r0 = GCALL6(0x0607507C, 0x06089884, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    r8 = r8 + r0;
                    r0 = GCALL6(0x0607507C, 0x060898C4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    r8 = r8 + r0;
                    r14 = 0x060898E4;
                    r0 = GCALL6(0x0607507C, 0x060898E4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    r7 = LD32((148 + (sp - 188)));
                    r0 = GCALL6(0x060279E0, 0, ((r8 + r0) + 1), -1, r7, LD32((sp - 188)), LD32((sp - 184)));
                    r13 = LD32((128 + (sp - 188)));
                    ST32(r13, r0);
                    r1 = LD32((152 + (sp - 188)));
                    ST8(((r1 + r11) - 1), 0);
                    r13 = LD32((128 + (sp - 188)));
                    r4 = LD32(r13);
                    if (!((r4 & r4) == 0)) {
                        ST32((sp - 192), r14);
                        ST32((sp - 196), 0x060898C4);
                        ST32((sp - 200), 0x06089884);
                        r0 = GCALL8(0x06045264, r4, r11, r10, 0x06089864, LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)), LD32((sp - 188)));
                    }
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(0x06027F48, r11, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                }
                r12 = 0;
                ST32((148 + (sp - 188)), r12);
            } else {
                r4 = LD32(r9);
                r7 = R(7);
                SETIN(0, r0);
                r0 = GCALL6(r14, r4, 0x06047AE4, 4, r7, LD32((sp - 188)), LD32((sp - 184)));
                r4 = sp - 188;
                if ((r0 & r0) == 0) {
                    r3 = LD32(0x06047AEC);
                    ST32(sp - 188, r3);
                    r2 = LD32(0x06047AF0);
                    ST32(sp - 184, r2);
                    r2 = LD16(0x06047AF4);
                    r3 = (sp - 188) + 8;
                    ST16(r3, r2);
                    r1 = LD8(0x06047AF6);
                    ST8((r3 + 2), r1);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(0x06025948, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    ST32((152 + (sp - 188)), r0);
                    r5 = LD32((152 + (sp - 188)));
                    r7 = LD32((148 + (sp - 188)));
                    r0 = GCALL6(0x060279E0, 0, (r5 + 1), -1, r7, LD32((sp - 188)), LD32((sp - 184)));
                    r11 = r0;
                    r8 = sp - 188;
                    if (!((r11 & r11) == 0)) {
                        r8 = r8 + 16;
                        r0 = GCALL6(0x0604B3F0, r8, 0, 48, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r7 = LD32((152 + (sp - 188)));
                        r0 = GCALL6(0x060258EC, (sp - 188), r8, r11, r7, LD32((sp - 188)), LD32((sp - 184)));
                        r0 = GCALL6(0x06025984, r8, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r0 = GCALL6(0x0603CCE0, 0x060767CC, 0x06047AF8, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r4 = LD32(0x060767CC);
                        r7 = R(7);
                        r0 = GCALL6(0x06048C08, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r10 = 0x0607507C;
                        r0 = GCALL6(0x0607507C, 0x06089924, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r8 = LD32(152 + (sp - 188));
                        r8 = r8 + r0;
                        r0 = GCALL6(0x0607507C, 0x06089944, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r8 = r8 + r0;
                        r0 = GCALL6(0x0607507C, 0x060897C4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r8 = r8 + r0;
                        r0 = GCALL6(0x0607507C, 0x060897A4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r8 = (r8 + r0) + 15;
                        r4 = LD32(r9);
                        r7 = R(7);
                        SETIN(0, r0);
                        r0 = GCALL6(r14, r4, 0x06047B08, 5, r7, LD32((sp - 188)), LD32((sp - 184)));
                        r6 = -1;
                        if (!((r0 & r0) == 0)) {
                            r7 = LD32((148 + (sp - 188)));
                            r0 = GCALL6(0x060279E0, 0, r8, r6, r7, LD32((sp - 188)), LD32((sp - 184)));
                            r13 = LD32((128 + (sp - 188)));
                            ST32(r13, r0);
                            r1 = LD32((152 + (sp - 188)));
                            ST8(((r1 + r11) - 1), 0);
                            r13 = LD32((128 + (sp - 188)));
                            r4 = LD32(r13);
                            if (!((r4 & r4) == 0)) {
                                r2 = 0x060897A2;
                                r1 = LD8(0x060897A2);
                                c18 = (r1 & r1) == 0;
                                r1 = 0x06047ABC;
                                c1049 = c18;
                                if (c18) {
                                    r1 = 0x06047AB4;
                                    c1049 = 1;
                                }
                                ST32((sp - 192), r1);
                                r1 = 0x06047ABC;
                                if (!(c1049)) {
                                    r1 = 0x06047AB4;
                                }
                                ST32((sp - 196), r1);
                                r1 = LD8((r2 - 1));
                                c19 = (r1 & r1) == 0;
                                r1 = 0x06047ABC;
                                c1053 = c19;
                                if (c19) {
                                    r1 = 0x06047AB4;
                                    c1053 = 1;
                                }
                                ST32((sp - 200), r1);
                                r1 = 0x06047ABC;
                                if (!(c1053)) {
                                    r1 = 0x06047AB4;
                                }
                                ST32((sp - 204), r1);
                                ST32((sp - 208), 0x060897A4);
                                ST32((sp - 212), 0x060897C4);
                                r0 = GCALL8(0x06045264, r4, r11, 0x06089924, 0x06089944, LD32((sp - 212)), LD32((sp - 208)), LD32((sp - 204)), LD32((sp - 200)));
                            }
                        } else {
                            r9 = 0x06089964;
                            r5 = R(5);
                            r7 = R(7);
                            SETIN(0, r0);
                            r0 = GCALL6(r10, 0x06089964, r5, r6, r7, LD32((sp - 188)), LD32((sp - 184)));
                            r7 = LD32((148 + (sp - 188)));
                            r0 = GCALL6(0x060279E0, 0, (r8 + r0), -1, r7, LD32((sp - 188)), LD32((sp - 184)));
                            r12 = LD32((128 + (sp - 188)));
                            ST32(r12, r0);
                            r1 = LD32((152 + (sp - 188)));
                            ST8(((r1 + r11) - 1), 0);
                            r12 = LD32((128 + (sp - 188)));
                            r4 = LD32(r12);
                            if (!((r4 & r4) == 0)) {
                                r2 = 0x060897A2;
                                r1 = LD8(0x060897A2);
                                c15 = (r1 & r1) == 0;
                                r1 = 0x06047ABC;
                                c1039 = c15;
                                if (c15) {
                                    r1 = 0x06047AB4;
                                    c1039 = 1;
                                }
                                ST32((sp - 192), r1);
                                r1 = 0x06047ABC;
                                if (!(c1039)) {
                                    r1 = 0x06047AB4;
                                }
                                ST32((sp - 196), r1);
                                r1 = LD8((r2 - 1));
                                c16 = (r1 & r1) == 0;
                                r1 = 0x06047ABC;
                                c1043 = c16;
                                if (c16) {
                                    r1 = 0x06047AB4;
                                    c1043 = 1;
                                }
                                ST32((sp - 200), r1);
                                r1 = 0x06047ABC;
                                if (!(c1043)) {
                                    r1 = 0x06047AB4;
                                }
                                ST32((sp - 204), r1);
                                ST32((sp - 208), 0x060897A4);
                                ST32((sp - 212), 0x060897C4);
                                r0 = GCALL8(0x06045264, r4, r11, 0x06089924, r9, LD32((sp - 212)), LD32((sp - 208)), LD32((sp - 204)), LD32((sp - 200)));
                            }
                        }
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL6(0x06027F48, r11, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                    }
                    r12 = 1;
                    ST32((148 + (sp - 188)), r12);
                } else {
                    r4 = LD32(r9);
                    r7 = R(7);
                    SETIN(0, r0);
                    r0 = GCALL6(r14, r4, 0x06047B10, 4, r7, LD32((sp - 188)), LD32((sp - 184)));
                    if ((r0 & r0) == 0) {
                        r1 = LD32((136 + (sp - 188)));
                        r11 = LD32((r1 + 104));
                        r0 = GCALL6(0x06047784, r11, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r8 = 0x060897A0;
                        r0 = GCALL6(0x0605180C, 0x060897A0, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        r3 = LD32(0x06047B18);
                        ST32(sp - 188, r3);
                        r1 = LD32(0x06047B1C);
                        ST32(sp - 184, r1);
                        r1 = LD8(0x06047B20);
                        ST8((sp - 180), r1);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL6(0x06025948, (sp - 188), 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        ST32((152 + (sp - 188)), r0);
                        r5 = LD32((152 + (sp - 188)));
                        r7 = LD32((148 + (sp - 188)));
                        r0 = GCALL6(0x060279E0, 0, (r5 + 1), -1, r7, LD32((sp - 188)), LD32((sp - 184)));
                        r1 = r0;
                        r0 = LD32((128 + (sp - 188)));
                        ST32(r0, r1);
                        if (!((r1 & r1) == 0)) {
                            r0 = GCALL6(0x0604B358, 0x0608AD40, r8, 0x219, 0, LD32((sp - 188)), LD32((sp - 184)));
                            r0 = GCALL6(0x06010EE0, 0, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                            r8 = (sp - 188) + 16;
                            r0 = GCALL6(0x0604B3F0, r8, 0, 48, 0, LD32((sp - 188)), LD32((sp - 184)));
                            r0 = LD32((128 + (sp - 188)));
                            r7 = LD32((152 + (sp - 188)));
                            r6 = LD32(r0);
                            r0 = GCALL6(0x060258EC, (sp - 188), r8, r6, r7, LD32((sp - 188)), LD32((sp - 184)));
                            r0 = GCALL6(0x06025984, r8, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                            r13 = LD32((128 + (sp - 188)));
                            r2 = LD32(r13);
                            r13 = LD32((152 + (sp - 188)));
                            ST8(r2 + r13, 0);
                            r0 = GCALL6(0x0603CCE0, 0x060767CC, 0x06047B24, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                            r4 = LD32(0x060767CC);
                            r7 = R(7);
                            r0 = GCALL6(0x06048C08, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                        }
                    } else {
                        r4 = LD32(r9);
                        r7 = R(7);
                        SETIN(0, r0);
                        r0 = GCALL6(r14, r4, 0x06047B34, 4, r7, LD32((sp - 188)), LD32((sp - 184)));
                        c22 = (r0 & r0) == 0;
                        r0 = c22;
                        if (!(c22)) {
                            r1 = LD32(136 + (sp - 188));
                            r11 = LD32((r1 + 104));
                            r0 = GCALL6(0x06047784, r11, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                            r3 = LD32(0x06047B3C);
                            ST32(sp - 188, r3);
                            r1 = LD32(0x06047B40);
                            ST32(sp - 184, r1);
                            r1 = LD16(0x06047B44);
                            ST16((sp - 180), r1);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL6(0x06025948, (sp - 188), 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                            ST32((152 + (sp - 188)), r0);
                            r5 = LD32((152 + (sp - 188)));
                            r7 = LD32((148 + (sp - 188)));
                            r0 = GCALL6(0x060279E0, 0, (r5 + 1), -1, r7, LD32((sp - 188)), LD32((sp - 184)));
                            r11 = r0;
                            r8 = sp - 188;
                            if (!((r11 & r11) == 0)) {
                                r8 = r8 + 16;
                                r0 = GCALL6(0x0604B3F0, r8, 0, 48, 0, LD32((sp - 188)), LD32((sp - 184)));
                                r7 = LD32((152 + (sp - 188)));
                                r0 = GCALL6(0x060258EC, (sp - 188), r8, r11, r7, LD32((sp - 188)), LD32((sp - 184)));
                                r0 = GCALL6(0x06025984, r8, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                                r0 = GCALL6(0x0603CCE0, 0x060767CC, 0x06047B48, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                                r4 = LD32(0x060767CC);
                                r7 = R(7);
                                r0 = GCALL6(0x06048C08, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                                r7 = LD8(0x060899A5);
                                r6 = LD8(0x060899A4);
                                ST32((144 + (sp - 188)), (sp - 124));
                                r1 = LD8(0x060899A7);
                                ST32((sp - 192), (r1 & 255));
                                r1 = LD8(0x060899A6);
                                ST32((sp - 196), (r1 & 255));
                                r4 = LD32((152 + (sp - 196)));
                                r0 = GCALL8(0x06045264, r4, 0x06047AA8, (r6 & 255), (r7 & 255), LD32((sp - 196)), LD32((sp - 192)), LD32((sp - 188)), LD32((sp - 184)));
                                r14 = (sp - 196) + 104;
                                r7 = LD8(0x060899A9);
                                r6 = LD8(0x060899A8);
                                r1 = LD8(0x060899AB);
                                ST32((sp - 200), (r1 & 255));
                                r1 = LD8(0x060899AA);
                                ST32((sp - 204), (r1 & 255));
                                r0 = GCALL8(0x06045264, r14, 0x06047AA8, (r6 & 255), (r7 & 255), LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r0 = GCALL8(0x0607507C, 0x060897E4, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = LD32((168 + (sp - 204)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x06089804, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x06089824, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x06089964, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x06089984, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r4 = LD32(160 + (sp - 204));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, r4, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, r14, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x06089924, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x06089944, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x060897C4, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x060897A4, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = (r8 + r0) + 6;
                                r0 = GCALL8(0x0607507C, 0x06089844, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x06089864, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x06089884, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r0 = GCALL8(0x0607507C, 0x060898C4, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r8 = r8 + r0;
                                r10 = 0x060898E4;
                                r0 = GCALL8(0x0607507C, 0x060898E4, 0, 0, 0, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r7 = LD32((164 + (sp - 204)));
                                r0 = GCALL8(0x060279E0, 0, ((r8 + r0) + 1), -1, r7, LD32((sp - 204)), LD32((sp - 200)), LD32((sp - 196)), LD32((sp - 192)));
                                r12 = LD32((144 + (sp - 204)));
                                ST32(r12, r0);
                                r1 = LD32((168 + (sp - 204)));
                                ST8(((r1 + r11) - 1), 0);
                                r12 = LD32(128 + (sp - 188));
                                r4 = LD32(r12);
                                c24 = (r4 & r4) == 0;
                                if (!(c24)) {
                                    ST32((sp - 192), r10);
                                    ST32((sp - 196), 0x060898C4);
                                    ST32((sp - 200), 0x06089884);
                                    ST32((sp - 204), 0x06089864);
                                    ST32((sp - 208), 0x06089844);
                                    r1 = LD8(0x060897A2);
                                    c25 = (r1 & r1) == 0;
                                    r1 = 0x06047B5C;
                                    if (!(c25)) {
                                        r1 = 0x06047B58;
                                    }
                                    ST32((sp - 212), r1);
                                    r8 = 0x060897A1;
                                    r1 = LD8(0x060897A1);
                                    c26 = (r1 & r1) == 0;
                                    r1 = 0x06047B5C;
                                    if (!(c26)) {
                                        r1 = 0x06047B58;
                                    }
                                    ST32((sp - 216), r1);
                                    ST32((sp - 220), 0x060897A4);
                                    ST32((sp - 224), 0x060897C4);
                                    ST32((sp - 228), 0x06089944);
                                    ST32((sp - 232), 0x06089924);
                                    ST32((sp - 236), r14);
                                    r12 = LD32((192 + (sp - 236)));
                                    ST32((sp - 240), r12);
                                    ST32((sp - 244), 0x06089984);
                                    ST32((sp - 248), 0x06089964);
                                    ST32((sp - 252), 0x06089824);
                                    r0 = GCALL8(0x06045264, r4, r11, 0x060897E4, 0x06089804, LD32((sp - 252)), LD32((sp - 248)), LD32((sp - 244)), LD32((sp - 240)));
                                    r0 = GCALL8(0x0604B358, 0x0608AD40, (r8 - 1), 0x219, 0, LD32((sp - 252)), LD32((sp - 248)), LD32((sp - 244)), LD32((sp - 240)));
                                    r0 = GCALL6(0x06010EE0, 0, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                                    ST32(0x06075988, 0);
                                }
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL6(0x06027F48, r11, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
                            }
                        } else {
                            ST32(r8, r0);
                        }
                        ST32((148 + (sp - 188)), 0);
                    }
                }
            }
        }
    }
    r12 = LD32(128 + (sp - 188));
    r4 = LD32(r12);
    r0 = GCALL6(0x0607507C, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
    r12 = LD32((132 + (sp - 188)));
    ST32(r12, r0);
    r8 = LD32((136 + (sp - 188)));
    r8 = r8 + 104;
    r4 = LD32(r8);
    if (!((r4 & r4) == 0)) {
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 188)), LD32((sp - 184)));
        ST32(r8, 0);
    }
    r0 = LD32(148 + (sp - 188));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060488B8(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14, c2, c5, c13, c1011, c1035, c2011;
    FRAME(sp, 108);

    r11 = R(11);
    ST32((64 + (sp - 100)), r4);
    r14 = r5;
    r0 = GCALL4(0x06032C60, 0, 0x060488A0, (sp - 44), (sp - 40));
    r1 = 0;
    if ((r0 & r0) == 0) {
        goto L060488EE;
    }
    ST32(sp - 44, r1);
    ST32(sp - 40, r1);
    L060488EE:
    r9 = 0;
    r4 = LD32((64 + (sp - 100)));
    r0 = GCALL3(0x0604880C, r4, r14, (sp - 100));
    r10 = 0x06048818;
    r13 = 0x0604880C;
    r12 = 0x060752FC;
    r5 = sp - 100;
    L06048906:
    SETIN(0, r0);
    r0 = GCALL2(r10, (sp - 100), (r5 + 24));
    r8 = r0;
    r5 = LD32(sp - 40);
    if (!((r8 & r8) == 0)) {
        goto L06048964;
    }
    r4 = LD32(sp - 44);
    SETIN(0, r0);
    r0 = GCALL3(r13, r4, r5, (sp - 88));
    r5 = sp - 100;
    L0604891E:
    SETIN(0, r0);
    r0 = GCALL2(r10, (sp - 88), (r5 + 40));
    r11 = r0;
    c2 = (r11 & r11) == 0;
    r6 = LD32(sp - 72);
    c1011 = c2;
    if (!(c2)) {
        goto L06048950;
    }
    r1 = LD32(sp - 56);
    r5 = sp - 100;
    if (!(r6 == r1)) {
        POLL();
        goto L0604891E;
    }
    r5 = LD32(sp - 60);
    r4 = LD32(sp - 76);
    SETIN(0, r0);
    r0 = GCALL3(r12, r4, r5, r6);
    r5 = sp - 100;
    if (!((r0 & r0) == 0)) {
        POLL();
        goto L0604891E;
    }
    r1 = LD32(sp - 64);
    r2 = LD32(sp - 48);
    c5 = r1 > r2;
    r1 = r1 - r2;
    if (!(c5)) {
        goto L0604894E;
    }
    r9 = r9 + r1;
    L0604894E:
    c1011 = (r11 & r11) == 0;
    L06048950:
    r5 = sp - 100;
    if (c1011) {
        POLL();
        goto L06048906;
    }
    r2 = LD32(sp - 72);
    r3 = LD32(sp - 64);
    r9 = (r9 + 4) + (r2 + r3);
    POLL();
    goto L06048906;
    L06048964:
    r4 = LD32(sp - 44);
    if (r8 >= 0) {
        goto L0604897E;
    }
    if ((r4 & r4) == 0) {
        goto L06048974;
    }
    r0 = GCALL2(0x06027F48, r4, r5);
    L06048974:
    c2011 = R(11);
    SETR(11, r11);
    r0 = GCALL1(0x06010DDC, 22);
    SETR(11, c2011);
    r0 = r8;
    goto L06048AD2;
    L0604897E:
    r5 = LD32(sp - 44);
    if (!(r9 > 0)) {
        goto L060489B4;
    }
    r6 = LD32(sp - 40);
    if ((r5 & r5) == 0) {
        goto L06048996;
    }
    r0 = GCALL3(0x06027C18, 0, r5, (r6 + r9));
    ST32(sp - 44, r0);
    goto L060489A4;
    L06048996:
    r0 = GCALL4(0x060279E0, 0, r9, -1, 1);
    ST32(sp - 44, r0);
    L060489A4:
    r1 = LD32(sp - 44);
    if (!((r1 & r1) == 0)) {
        goto L060489B4;
    }
    c2011 = R(11);
    SETR(11, r11);
    r0 = GCALL1(0x06010DDC, 22);
    SETR(11, c2011);
    r0 = -3;
    goto L06048AD2;
    L060489B4:
    r4 = LD32((64 + (sp - 100)));
    r0 = GCALL3(0x0604880C, r4, r14, (sp - 100));
    r13 = 0x06048818;
    r14 = 0x060752FC;
    r12 = 0x0604B358;
    L060489C8:
    r5 = sp - 100;
    L060489CA:
    SETIN(0, r0);
    r0 = GCALL2(r13, (sp - 100), (r5 + 24));
    r5 = LD32(sp - 40);
    if (!((r0 & r0) == 0)) {
        goto L06048AA6;
    }
    r4 = LD32(sp - 44);
    r0 = GCALL3(0x0604880C, r4, r5, (sp - 88));
    r5 = sp - 100;
    L060489E2:
    SETIN(0, r0);
    r0 = GCALL2(r13, (sp - 88), (r5 + 40));
    r11 = r0;
    c13 = (r11 & r11) == 0;
    r6 = LD32(sp - 72);
    c1035 = c13;
    if (!(c13)) {
        goto L06048A52;
    }
    r1 = LD32(sp - 56);
    r5 = sp - 100;
    if (!(r6 == r1)) {
        POLL();
        goto L060489E2;
    }
    r5 = LD32(sp - 60);
    r4 = LD32(sp - 76);
    SETIN(0, r0);
    r0 = GCALL3(r14, r4, r5, r6);
    r5 = sp - 100;
    if (!((r0 & r0) == 0)) {
        POLL();
        goto L060489E2;
    }
    r2 = LD32(sp - 64);
    r1 = LD32(sp - 48);
    r10 = LD32(sp - 52);
    r9 = r2 - r1;
    r8 = r10 - 2;
    if ((r9 & r9) == 0) {
        goto L06048A46;
    }
    r1 = LD32(sp - 80);
    r2 = LD32(sp - 84);
    r6 = r1 - r2;
    r1 = LD32(sp - 64);
    if (!(r6 > 0)) {
        goto L06048A34;
    }
    r5 = LD32(sp - 44);
    r0 = GCALL3(0x060757E4, ((r5 + r2) + r9), (r5 + r2), r6);
    r1 = LD32(sp - 64);
    L06048A34:
    ST8(r8, ((int)((unsigned)r1 >> 8)));
    r1 = LD32(sp - 64);
    ST8((r10 - 1), r1);
    r1 = LD32(sp - 40);
    ST32(sp - 40, (r1 + r9));
    L06048A46:
    r5 = LD32(sp - 68);
    r6 = LD32(sp - 64);
    SETIN(0, r0);
    r0 = GCALL3(r12, (r8 + 2), r5, r6);
    c1035 = (r11 & r11) == 0;
    L06048A52:
    r5 = sp - 100;
    if (c1035) {
        POLL();
        goto L060489CA;
    }
    r2 = LD32(sp - 44);
    r0 = LD32(sp - 40);
    r1 = LD32(sp - 72);
    r8 = r2 + r0;
    ST8(r0 + r2, ((int)((unsigned)r1 >> 8)));
    r1 = LD32(sp - 72);
    ST8((r8 + 1), r1);
    r5 = LD32(sp - 76);
    r6 = LD32(sp - 72);
    SETIN(0, r0);
    r0 = GCALL3(r12, (r8 + 2), r5, r6);
    r1 = LD32(sp - 72);
    r2 = r8 + r1;
    r1 = LD32(sp - 64);
    r8 = r2 + 2;
    ST8(r8, ((int)((unsigned)r1 >> 8)));
    r1 = LD32(sp - 64);
    ST8((r2 + 3), r1);
    r5 = LD32(sp - 68);
    r6 = LD32(sp - 64);
    SETIN(0, r0);
    r0 = GCALL3(r12, (r8 + 2), r5, r6);
    r1 = LD32(sp - 72);
    r2 = LD32(sp - 64);
    r2 = r2 + (r1 + 4);
    r1 = LD32(sp - 40);
    ST32(sp - 40, (r1 + r2));
    POLL();
    goto L060489C8;
    L06048AA6:
    r7 = LD32(sp - 44);
    ST32((sp - 104), 1);
    r1 = LD32((64 + (sp - 104)));
    ST32((sp - 108), r1);
    r0 = GCALL6(0x06032A08, 0, 0x060488A0, 0x060488AC, r7, LD32((sp - 108)), LD32((sp - 104)));
    r4 = LD32((64 + (sp - 108)));
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL6(0x06027F48, r4, 0, 0, 0, LD32((sp - 108)), LD32((sp - 104)));
    c2011 = R(11);
    SETR(11, r11);
    r0 = GCALL6(0x06010DDC, 23, 0, 0, 0, LD32((sp - 108)), LD32((sp - 104)));
    SETR(11, c2011);
    r0 = 1;
    L06048AD2:
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049414(int r4)
{
    int r0, r1, r6, r7, r8, r9, r10, r11, r12, r13, r14, c7, c11, c1006, c1007, c2011, c2012, c2013, c2014;
    FRAME(sp, 300);

    r11 = R(11);
    r13 = R(13);
    r14 = R(14);
    r9 = r4;
    r12 = 0x0608AE64;
    c2011 = R(11);
    SETR(11, r11);
    c2012 = R(12);
    SETR(12, 0x0608AE64);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL2(0x06049254, 0x0608AE64, (sp - 292));
    SETR(11, c2011);
    SETR(12, c2012);
    SETR(13, c2013);
    SETR(14, c2014);
    r1 = sp - 292;
    if (r0 >= 0) {
        r8 = (sp - 292) + 4;
        r11 = 0x06045264;
        r7 = LD8((r1 + 1));
        r6 = LD8(sp - 292);
        r1 = LD8((sp - 289));
        ST32((sp - 296), (r1 & 255));
        r1 = LD8((sp - 290));
        ST32((sp - 300), (r1 & 255));
        r0 = GCALL6(0x06045264, r8, 0x060493EC, (r6 & 255), (r7 & 255), LD32((sp - 300)), LD32((sp - 296)));
        r7 = R(7);
        r0 = GCALL6(0x06059D88, r8, 0, 1, 0, LD32((sp - 300)), LD32((sp - 296)));
        ST32(r9, r0);
        if (r0 >= 0) {
            r10 = 0x060493C4;
            r0 = GCALL2(0x060493C4, r0, r8);
            r6 = r12;
            if (r0 >= 0) {
                SETIN(0, r0);
                r0 = GCALL3(r11, r8, 0x060493FC, (r6 - 128));
                r13 = 0x0607507C;
                r0 = GCALL1(0x0607507C, r8);
                r4 = LD32(r9);
                r14 = 0x06049370;
                r0 = GCALL3(0x06049370, r4, r8, r0);
                c1006 = r0 == -12;
                if (!(r0 >= 0)) {
                    POLL();
                    r0 = -600;
                    c1007 = c1006;
                    if (c1007) {
                        r0 = -12;
                    }
                } else {
                    r4 = LD32(r9);
                    SETIN(0, r0);
                    r0 = GCALL2(r10, r4, r8);
                    c7 = r0 == -12;
                    if (r0 >= 0) {
                        SETIN(0, r0);
                        r0 = GCALL3(r11, r8, 0x06049408, (r12 - 96));
                        SETIN(0, r0);
                        r0 = GCALL1(r13, r8);
                        r4 = LD32(r9);
                        SETIN(0, r0);
                        r0 = GCALL3(r14, r4, r8, r0);
                        c1006 = r0 == -12;
                        if (!(r0 >= 0)) {
                            POLL();
                            r0 = -600;
                            c1007 = c1006;
                            if (c1007) {
                                r0 = -12;
                            }
                        } else {
                            r4 = LD32(r9);
                            SETIN(0, r0);
                            r0 = GCALL2(r10, r4, r8);
                            c11 = r0 == -12;
                            if (r0 >= 0) {
                                r0 = 0;
                            } else {
                                r0 = -602;
                                c1007 = c11;
                                POLL();
                                if (c1007) {
                                    r0 = -12;
                                }
                            }
                        }
                    } else {
                        r0 = -601;
                        c1007 = c7;
                        POLL();
                        if (c1007) {
                            r0 = -12;
                        }
                    }
                }
            } else {
                c1006 = r0 == -12;
                r0 = -600;
                c1007 = c1006;
                if (c1007) {
                    r0 = -12;
                }
            }
        } else {
            r0 = -600;
        }
    } else {
        r0 = -603;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604958C(int r4)
{
    int r0, r1, r5, r6, r7, r8, r9, r10, r11, c9, c1009, c1010, c2011;
    FRAME(sp, 548);

    r11 = R(11);
    r9 = r4;
    r8 = (sp - 540) + 4;
    r0 = GCALL1(0x0605B26C, r8);
    r4 = sp - 540;
    if (!(r0 == 1)) {
        r5 = 0x0608ADE4;
        r4 = r4 + 8;
        r0 = 0x060750DC;
    } else {
        r5 = (sp - 540) + 8;
        r0 = 0x0605B398;
        r4 = r8;
    }
    SETIN(0, r0);
    r0 = GCALL2(r0, r4, r5);
    c2011 = R(11);
    SETR(11, r11);
    r0 = GCALL2(0x06049254, 0x0608AE84, (sp - 540));
    SETR(11, c2011);
    r1 = sp - 540;
    if ((((int)((unsigned)r0 >> 31)) & ((int)((unsigned)r0 >> 31))) == 0) {
        r7 = LD8((r1 + 1));
        r10 = 0x06045264;
        r6 = LD8(sp - 540);
        r8 = (sp - 540) + 0x108;
        r1 = LD8((sp - 537));
        ST32((sp - 544), (r1 & 255));
        r1 = LD8((sp - 538));
        ST32((sp - 548), (r1 & 255));
        r0 = GCALL6(0x06045264, r8, 0x06049570, (r6 & 255), (r7 & 255), LD32((sp - 548)), LD32((sp - 544)));
        r7 = R(7);
        r0 = GCALL6(0x06059D88, r8, 0, 1, 0, LD32((sp - 548)), LD32((sp - 544)));
        ST32(r9, r0);
        if (r0 >= 0) {
            r11 = 0x06049548;
            r0 = GCALL2(0x06049548, r0, r8);
            r6 = sp - 540;
            if (r0 == 220) {
                SETIN(0, r0);
                r0 = GCALL3(r10, r8, 0x06049580, (r6 + 8));
                r0 = GCALL1(0x0607507C, r8);
                r4 = LD32(r9);
                r0 = GCALL3(0x06049370, r4, r8, r0);
                c1009 = r0 == -12;
                if (!(r0 >= 0)) {
                    POLL();
                    r0 = -600;
                    c1010 = c1009;
                    if (c1010) {
                        r0 = -12;
                    }
                } else {
                    r4 = LD32(r9);
                    SETIN(0, r0);
                    r0 = GCALL2(r11, r4, r8);
                    c9 = r0 == -12;
                    if (r0 == 250) {
                        r0 = 0;
                    } else {
                        r0 = -604;
                        c1010 = c9;
                        POLL();
                        if (c1010) {
                            r0 = -12;
                        }
                    }
                }
            } else {
                c1009 = r0 == -12;
                r0 = -600;
                c1010 = c1009;
                if (c1010) {
                    r0 = -12;
                }
            }
        } else {
            r0 = -600;
        }
    } else {
        r0 = -603;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06049F90(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14, c0, c2011, c2012, c2013, c2014;
    FRAME(sp, 728);

    r12 = R(12);
    r14 = R(14);
    r13 = r4;
    ST32((0x2A8 + (sp - 716)), r7);
    ST32(0x060791D0, r5);
    r10 = 0x060791D4;
    ST32(0x060791D4, r6);
    r11 = 0x0601057C;
    r0 = GCALL2(0x0601057C, 0x06049F00, 5);
    r9 = (sp - 716) + 32;
    r4 = LD32(0x060791D0);
    c2011 = R(11);
    SETR(11, 0x0601057C);
    c2012 = R(12);
    SETR(12, r12);
    c2013 = R(13);
    SETR(13, r13);
    c2014 = R(14);
    SETR(14, r14);
    r0 = GCALL2(0x06049254, r4, r9);
    SETR(11, c2011);
    SETR(12, c2012);
    SETR(13, c2013);
    SETR(14, c2014);
    c0 = (r0 & r0) == 0;
    r0 = -1;
    if (c0) {
        r7 = LD8((sp - 683));
        r6 = LD8(r9);
        r1 = LD32(r10);
        ST32((sp - 720), r1);
        r1 = LD8((sp - 681));
        ST32((sp - 724), (r1 & 255));
        r1 = LD8((sp - 682));
        ST32((sp - 728), (r1 & 255));
        r0 = GCALL7(0x06045264, (sp - 716), 0x06049F0C, (r6 & 255), (r7 & 255), LD32((sp - 728)), LD32((sp - 724)), LD32((sp - 720)));
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL7(0x060452D0, (sp - 716), 0, 0, 0, LD32((sp - 728)), LD32((sp - 724)), LD32((sp - 720)));
        r0 = GCALL7(0x06059D88, (sp - 716), 0, 1, r7, LD32((sp - 728)), LD32((sp - 724)), LD32((sp - 720)));
        ST32(r13, r0);
        if (r0 >= 0) {
            SETIN(0, r0);
            r0 = GCALL2(r11, (sp - 716), 15);
            r8 = (sp - 716) + 36;
            r0 = GCALL1(0x0605B26C, r8);
            if (!(r0 == 1)) {
                r5 = 0x0608ADE4;
                r4 = (sp - 716) + 104;
                r0 = 0x060750DC;
            } else {
                r5 = (sp - 716) + 104;
                r0 = 0x0605B398;
                r4 = r8;
            }
            SETIN(0, r0);
            r0 = GCALL2(r0, r4, r5);
            r10 = 0x0601057C;
            r0 = GCALL2(0x0601057C, 0x06049F1C, 35);
            r11 = 0x0608ADA4;
            r9 = (sp - 716) + 168;
            r12 = 0x06045264;
            r0 = GCALL3(0x06045264, r9, 0x06049F24, 0x0608ADA4);
            r14 = 0x0607507C;
            r0 = GCALL1(0x0607507C, r9);
            r4 = LD32(r13);
            r0 = GCALL3(0x06049370, r4, r9, r0);
            r8 = r0;
            if (r8 >= 0) {
                SETIN(0, r0);
                r0 = GCALL2(r10, 0x06049F40, 50);
                r6 = LD32((0x2A8 + (sp - 716)));
                SETIN(0, r0);
                r0 = GCALL3(r12, r9, 0x06049F48, r6);
                SETIN(0, r0);
                r0 = GCALL1(r14, r9);
                r4 = LD32(r13);
                r0 = GCALL3(0x06049370, r4, r9, r0);
                if (r0 >= 0) {
                    SETIN(0, r0);
                    r0 = GCALL2(r10, 0x06049F54, 65);
                    r6 = r11 - 32;
                    r1 = LD8(r6);
                    r7 = sp - 716;
                    if ((r1 & r1) == 0) {
                        r7 = r7 + 104;
                        r5 = 0x06049F5C;
                        r2 = LD32((0x2A8 + (sp - 716)));
                        r6 = r11;
                        ST32((sp - 720), r2);
                        r1 = LD32(0x060791D0);
                    } else {
                        r7 = r7 + 104;
                        r5 = 0x06049F5C;
                        ST32((sp - 720), r6);
                        r1 = LD32(0x060791D0);
                        r6 = r11;
                    }
                    ST32((sp - 724), r1);
                    SETIN(0, r0);
                    r0 = GCALL6(r12, r9, r5, r6, r7, LD32((sp - 724)), LD32((sp - 720)));
                    r8 = (sp - 716) + 168;
                    r0 = GCALL1(0x0607507C, r8);
                    r4 = LD32(r13);
                    r0 = GCALL3(0x06049370, r4, r8, r0);
                    if (r0 >= 0) {
                        r0 = GCALL2(0x0601057C, 0x06049F70, 75);
                        r7 = LD32((0x2A8 + (sp - 716)));
                        r6 = LD32((0x2A8 + (sp - 716)));
                        r0 = GCALL4(0x06045264, (sp - 676), 0x06049F78, r6, r7);
                        while (1) {
                            r9 = 0x0608D110;
                            r4 = LD32(r13);
                            r0 = GCALL2(0x060492D0, r4, 0x0608D110);
                            r8 = r0;
                            r5 = sp - 716;
                            if (r8 > 0) {
                                r8 = 0x06075830;
                                r0 = GCALL2(0x06075830, r9, (r5 + 40));
                                if ((r0 & r0) == 0) {
                                    SETIN(0, r0);
                                    r0 = GCALL2(r8, r9, 0x06049F84);
                                    if ((r0 & r0) == 0) {
                                        POLL();
                                        continue;
                                    } else {
                                        r0 = -1001;
                                        break;
                                    }
                                } else {
                                    r0 = GCALL2(0x0601057C, 0x06049F88, 85);
                                    r0 = 0;
                                    break;
                                }
                            } else {
                                POLL();
                                r0 = r8;
                                break;
                            }
                            POLL();
                        }
                    }
                }
            } else {
                r0 = GCALL2(0x060452D0, 0x06049F30, r8);
                r0 = r8;
            }
        } else {
            r0 = -1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A400(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10;
    FRAME(sp, 528);

    r8 = r4;
    r0 = GCALL4(0x06045264, (sp - 528), 0x0604A3EC, r5, r7);
    r0 = GCALL1(0x0607507C, (sp - 528));
    r0 = GCALL3(0x06049370, r8, (sp - 528), r0);
    r5 = sp - 528;
    if (r0 >= 0) {
        r10 = 0x060492D0;
        r9 = 0x06075830;
        while (1) {
            SETIN(0, r0);
            r0 = GCALL2(r10, r8, r5);
            if (!(r0 >= 0)) {
                break;
            } else {
                SETIN(0, r0);
                r0 = GCALL2(r9, (sp - 528), 0x0604A3F8);
                r5 = sp - 528;
                if ((r0 & r0) == 0) {
                    POLL();
                    continue;
                } else {
                    r0 = 0;
                    break;
                }
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604A920(int r4)
{
    int r0, r1, r6, r8, r9, r10, r11, r12, r13, c0, c3, c5;
    FRAME(sp, 284);

    r8 = r4;
    r11 = 0;
    r10 = 0;
    r4 = LD32(r8 + 4);
    r12 = 0x0604A898;
    r0 = GCALL4(0x0604A898, r4, 0, 0, 0x060791E4);
    c0 = (r0 & r0) == 0;
    r0 = -3;
    if (c0) {
        r4 = LD32(r8);
        r0 = GCALL4(0x0604A250, r4, (sp - 284), (r8 + 0x19C), 1);
        if (!((r0 & r0) == 0)) {
            r4 = LD32(r8 + 4);
            r0 = GCALL4(0x0604A898, r4, r11, r10, 0x0607923C);
            c5 = (r0 & r0) == 0;
            r0 = -3;
            if (c5) {
                r0 = 0;
            }
        } else {
            r9 = (sp - 284) + 128;
            r13 = 0x06045264;
            r1 = LD8(sp - 284);
            while (1) {
                r6 = sp - 284;
                if (((r1 & 255) & (r1 & 255)) == 0) {
                    r4 = LD32(r8);
                    r0 = GCALL4(0x0604A250, r4, (sp - 284), (r8 + 0x19C), 0);
                    r1 = LD8(sp - 284);
                    if ((r0 & r0) == 0) {
                        POLL();
                        continue;
                    } else {
                        r4 = LD32(r8 + 4);
                        r0 = GCALL4(0x0604A898, r4, r11, r10, 0x0607923C);
                        c5 = (r0 & r0) == 0;
                        r0 = -3;
                        if (!(c5)) {
                            break;
                        } else {
                            r0 = 0;
                            break;
                        }
                    }
                } else {
                    SETIN(0, r0);
                    r0 = GCALL3(r13, r9, 0x06079258, r6);
                    r4 = LD32(r8 + 4);
                    SETIN(0, r0);
                    r0 = GCALL4(r12, r4, r11, r10, r9);
                    c3 = (r0 & r0) == 0;
                    r0 = -3;
                    if (!(c3)) {
                        break;
                    } else {
                        r4 = LD32(r8);
                        r0 = GCALL4(0x0604A250, r4, (sp - 284), (r8 + 0x19C), 0);
                        r1 = LD8(sp - 284);
                        if ((r0 & r0) == 0) {
                            POLL();
                            continue;
                        } else {
                            r4 = LD32(r8 + 4);
                            r0 = GCALL4(0x0604A898, r4, r11, r10, 0x0607923C);
                            c5 = (r0 & r0) == 0;
                            r0 = -3;
                            if (!(c5)) {
                                break;
                            } else {
                                r0 = 0;
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
int f0604AD10(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, c7;
    FRAME(sp, 528);

    r9 = r4;
    r6 = LD32(r9 + 16);
    r0 = GCALL4(0x06045264, (sp - 528), 0x0604ACF8, r6, r7);
    r0 = GCALL1(0x0607507C, (sp - 528));
    r4 = LD32(r9);
    r0 = GCALL3(0x06049370, r4, (sp - 528), r0);
    if (r0 >= 0) {
        r10 = 0x06075830;
        while (1) {
            r4 = LD32(r9);
            r0 = GCALL2(0x060492D0, r4, (sp - 528));
            if (r0 >= 0) {
                SETIN(0, r0);
                r0 = GCALL2(r10, (sp - 528), 0x0604AD04);
                if ((r0 & r0) == 0) {
                    SETIN(0, r0);
                    r0 = GCALL2(r10, (sp - 528), 0x0604AD08);
                    if ((r0 & r0) == 0) {
                        POLL();
                        continue;
                    } else {
                        r8 = LD32(r9 + 24);
                        ST32(r9 + 8, 0);
                        if (!((r8 & r8) == 0)) {
                            r10 = r9 + 28;
                            r0 = GCALL2(0x06075830, r8, r10);
                            r1 = 0;
                            if (!((r0 & r0) == 0)) {
                                while (1) {
                                    r1 = LD8(r8);
                                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                        POLL();
                                        r1 = LD32(r9 + 8);
                                        ST32(r9 + 8, (r1 + 1));
                                        while (1) {
                                            r2 = LD8(r8);
                                            r0 = r2 & 255;
                                            if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                POLL();
                                                if (r0 == 32) {
                                                    break;
                                                } else {
                                                    r8 = r8 + 1;
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r1 = LD8(r8);
                                        r8 = r8 + 1;
                                        if (((r1 & 255) & (r1 & 255)) == 0) {
                                            break;
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                                r0 = 0;
                                break;
                            } else {
                                ST8(r10, r1);
                                while (1) {
                                    r1 = LD8(r8);
                                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                        POLL();
                                        r1 = LD32(r9 + 8);
                                        ST32(r9 + 8, (r1 + 1));
                                        while (1) {
                                            r2 = LD8(r8);
                                            r0 = r2 & 255;
                                            if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                POLL();
                                                if (r0 == 32) {
                                                    break;
                                                } else {
                                                    r8 = r8 + 1;
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r1 = LD8(r8);
                                        r8 = r8 + 1;
                                        if (((r1 & 255) & (r1 & 255)) == 0) {
                                            break;
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                                r0 = 0;
                                break;
                            }
                        } else {
                            ST8((r9 + 28), 0);
                            r0 = 0;
                            break;
                        }
                    }
                } else {
                    r5 = LD32(r9 + 16);
                    SETIN(0, r0);
                    r0 = GCALL2(r10, (sp - 528), r5);
                    r8 = r0;
                    if ((r8 & r8) == 0) {
                        SETIN(0, r0);
                        r0 = GCALL2(r10, (sp - 528), 0x0604AD08);
                        if ((r0 & r0) == 0) {
                            POLL();
                            continue;
                        } else {
                            r8 = LD32(r9 + 24);
                            ST32(r9 + 8, 0);
                            if (!((r8 & r8) == 0)) {
                                r10 = r9 + 28;
                                r0 = GCALL2(0x06075830, r8, r10);
                                r1 = 0;
                                if (!((r0 & r0) == 0)) {
                                    while (1) {
                                        r1 = LD8(r8);
                                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                            POLL();
                                            r1 = LD32(r9 + 8);
                                            ST32(r9 + 8, (r1 + 1));
                                            while (1) {
                                                r2 = LD8(r8);
                                                r0 = r2 & 255;
                                                if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                    POLL();
                                                    if (r0 == 32) {
                                                        break;
                                                    } else {
                                                        r8 = r8 + 1;
                                                        continue;
                                                    }
                                                } else {
                                                    break;
                                                }
                                            }
                                            r1 = LD8(r8);
                                            r8 = r8 + 1;
                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                break;
                                            } else {
                                                continue;
                                            }
                                        } else {
                                            break;
                                        }
                                    }
                                    r0 = 0;
                                    break;
                                } else {
                                    ST8(r10, r1);
                                    while (1) {
                                        r1 = LD8(r8);
                                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                            POLL();
                                            r1 = LD32(r9 + 8);
                                            ST32(r9 + 8, (r1 + 1));
                                            while (1) {
                                                r2 = LD8(r8);
                                                r0 = r2 & 255;
                                                if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                    POLL();
                                                    if (r0 == 32) {
                                                        break;
                                                    } else {
                                                        r8 = r8 + 1;
                                                        continue;
                                                    }
                                                } else {
                                                    break;
                                                }
                                            }
                                            r1 = LD8(r8);
                                            r8 = r8 + 1;
                                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                                break;
                                            } else {
                                                continue;
                                            }
                                        } else {
                                            break;
                                        }
                                    }
                                    r0 = 0;
                                    break;
                                }
                            } else {
                                ST8((r9 + 28), 0);
                                r0 = 0;
                                break;
                            }
                        }
                    } else {
                        r1 = LD8(r8);
                        while (1) {
                            r8 = r8 + 1;
                            if (!((r1 & 255) == 58)) {
                                POLL();
                                r1 = LD8(r8);
                                continue;
                            } else {
                                break;
                            }
                        }
                        r8 = (r8 - 1) + 1;
                        r1 = LD8(r8);
                        r2 = r8;
                        while (!((r1 & 255) == 13)) {
                            POLL();
                            r1 = LD8(r2);
                            if (((r1 & 255) & (r1 & 255)) == 0) {
                                break;
                            } else {
                                r2 = r2 + 1;
                                r1 = LD8(r2);
                            }
                        }
                        r1 = LD8(r2);
                        c7 = (r1 & 255) == 13;
                        r1 = 0;
                        if (!(c7)) {
                            r4 = LD32(r9 + 24);
                            if ((r4 & r4) == 0) {
                                r0 = GCALL1(0x0607507C, r8);
                                r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                r1 = r0;
                                ST32(r9 + 24, r1);
                                r0 = GCALL2(0x060750DC, r1, r8);
                                r8 = LD32(r9 + 24);
                                ST32(r9 + 8, 0);
                                if (!((r8 & r8) == 0)) {
                                    r10 = r9 + 28;
                                    r0 = GCALL2(0x06075830, r8, r10);
                                    r1 = 0;
                                    if (!((r0 & r0) == 0)) {
                                        while (1) {
                                            r1 = LD8(r8);
                                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                POLL();
                                                r1 = LD32(r9 + 8);
                                                ST32(r9 + 8, (r1 + 1));
                                                while (1) {
                                                    r2 = LD8(r8);
                                                    r0 = r2 & 255;
                                                    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                        POLL();
                                                        if (r0 == 32) {
                                                            break;
                                                        } else {
                                                            r8 = r8 + 1;
                                                            continue;
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                                r1 = LD8(r8);
                                                r8 = r8 + 1;
                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                    break;
                                                } else {
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r0 = 0;
                                        break;
                                    } else {
                                        ST8(r10, r1);
                                        while (1) {
                                            r1 = LD8(r8);
                                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                POLL();
                                                r1 = LD32(r9 + 8);
                                                ST32(r9 + 8, (r1 + 1));
                                                while (1) {
                                                    r2 = LD8(r8);
                                                    r0 = r2 & 255;
                                                    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                        POLL();
                                                        if (r0 == 32) {
                                                            break;
                                                        } else {
                                                            r8 = r8 + 1;
                                                            continue;
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                                r1 = LD8(r8);
                                                r8 = r8 + 1;
                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                    break;
                                                } else {
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r0 = 0;
                                        break;
                                    }
                                } else {
                                    ST8((r9 + 28), 0);
                                    r0 = 0;
                                    break;
                                }
                            } else {
                                r0 = GCALL1(0x06027F48, r4);
                                r0 = GCALL1(0x0607507C, r8);
                                r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                r1 = r0;
                                ST32(r9 + 24, r1);
                                r0 = GCALL2(0x060750DC, r1, r8);
                                r8 = LD32(r9 + 24);
                                ST32(r9 + 8, 0);
                                if (!((r8 & r8) == 0)) {
                                    r10 = r9 + 28;
                                    r0 = GCALL2(0x06075830, r8, r10);
                                    r1 = 0;
                                    if (!((r0 & r0) == 0)) {
                                        while (1) {
                                            r1 = LD8(r8);
                                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                POLL();
                                                r1 = LD32(r9 + 8);
                                                ST32(r9 + 8, (r1 + 1));
                                                while (1) {
                                                    r2 = LD8(r8);
                                                    r0 = r2 & 255;
                                                    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                        POLL();
                                                        if (r0 == 32) {
                                                            break;
                                                        } else {
                                                            r8 = r8 + 1;
                                                            continue;
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                                r1 = LD8(r8);
                                                r8 = r8 + 1;
                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                    break;
                                                } else {
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r0 = 0;
                                        break;
                                    } else {
                                        ST8(r10, r1);
                                        while (1) {
                                            r1 = LD8(r8);
                                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                POLL();
                                                r1 = LD32(r9 + 8);
                                                ST32(r9 + 8, (r1 + 1));
                                                while (1) {
                                                    r2 = LD8(r8);
                                                    r0 = r2 & 255;
                                                    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                        POLL();
                                                        if (r0 == 32) {
                                                            break;
                                                        } else {
                                                            r8 = r8 + 1;
                                                            continue;
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                                r1 = LD8(r8);
                                                r8 = r8 + 1;
                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                    break;
                                                } else {
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r0 = 0;
                                        break;
                                    }
                                } else {
                                    ST8((r9 + 28), 0);
                                    r0 = 0;
                                    break;
                                }
                            }
                        } else {
                            ST8(r2, r1);
                            r4 = LD32(r9 + 24);
                            if ((r4 & r4) == 0) {
                                r0 = GCALL1(0x0607507C, r8);
                                r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                r1 = r0;
                                ST32(r9 + 24, r1);
                                r0 = GCALL2(0x060750DC, r1, r8);
                                r8 = LD32(r9 + 24);
                                ST32(r9 + 8, 0);
                                if (!((r8 & r8) == 0)) {
                                    r10 = r9 + 28;
                                    r0 = GCALL2(0x06075830, r8, r10);
                                    r1 = 0;
                                    if (!((r0 & r0) == 0)) {
                                        while (1) {
                                            r1 = LD8(r8);
                                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                POLL();
                                                r1 = LD32(r9 + 8);
                                                ST32(r9 + 8, (r1 + 1));
                                                while (1) {
                                                    r2 = LD8(r8);
                                                    r0 = r2 & 255;
                                                    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                        POLL();
                                                        if (r0 == 32) {
                                                            break;
                                                        } else {
                                                            r8 = r8 + 1;
                                                            continue;
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                                r1 = LD8(r8);
                                                r8 = r8 + 1;
                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                    break;
                                                } else {
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r0 = 0;
                                        break;
                                    } else {
                                        ST8(r10, r1);
                                        while (1) {
                                            r1 = LD8(r8);
                                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                POLL();
                                                r1 = LD32(r9 + 8);
                                                ST32(r9 + 8, (r1 + 1));
                                                while (1) {
                                                    r2 = LD8(r8);
                                                    r0 = r2 & 255;
                                                    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                        POLL();
                                                        if (r0 == 32) {
                                                            break;
                                                        } else {
                                                            r8 = r8 + 1;
                                                            continue;
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                                r1 = LD8(r8);
                                                r8 = r8 + 1;
                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                    break;
                                                } else {
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r0 = 0;
                                        break;
                                    }
                                } else {
                                    ST8((r9 + 28), 0);
                                    r0 = 0;
                                    break;
                                }
                            } else {
                                r0 = GCALL1(0x06027F48, r4);
                                r0 = GCALL1(0x0607507C, r8);
                                r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                                r1 = r0;
                                ST32(r9 + 24, r1);
                                r0 = GCALL2(0x060750DC, r1, r8);
                                r8 = LD32(r9 + 24);
                                ST32(r9 + 8, 0);
                                if (!((r8 & r8) == 0)) {
                                    r10 = r9 + 28;
                                    r0 = GCALL2(0x06075830, r8, r10);
                                    r1 = 0;
                                    if (!((r0 & r0) == 0)) {
                                        while (1) {
                                            r1 = LD8(r8);
                                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                POLL();
                                                r1 = LD32(r9 + 8);
                                                ST32(r9 + 8, (r1 + 1));
                                                while (1) {
                                                    r2 = LD8(r8);
                                                    r0 = r2 & 255;
                                                    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                        POLL();
                                                        if (r0 == 32) {
                                                            break;
                                                        } else {
                                                            r8 = r8 + 1;
                                                            continue;
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                                r1 = LD8(r8);
                                                r8 = r8 + 1;
                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                    break;
                                                } else {
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r0 = 0;
                                        break;
                                    } else {
                                        ST8(r10, r1);
                                        while (1) {
                                            r1 = LD8(r8);
                                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                POLL();
                                                r1 = LD32(r9 + 8);
                                                ST32(r9 + 8, (r1 + 1));
                                                while (1) {
                                                    r2 = LD8(r8);
                                                    r0 = r2 & 255;
                                                    if (!(((r2 & 255) & (r2 & 255)) == 0)) {
                                                        POLL();
                                                        if (r0 == 32) {
                                                            break;
                                                        } else {
                                                            r8 = r8 + 1;
                                                            continue;
                                                        }
                                                    } else {
                                                        break;
                                                    }
                                                }
                                                r1 = LD8(r8);
                                                r8 = r8 + 1;
                                                if (((r1 & 255) & (r1 & 255)) == 0) {
                                                    break;
                                                } else {
                                                    continue;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                        r0 = 0;
                                        break;
                                    }
                                } else {
                                    ST8((r9 + 28), 0);
                                    r0 = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            } else {
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0604AE98(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c4, c1008, c2012, c2014;
    FRAME(sp, 544);

    r12 = R(12);
    r10 = r4;
    r13 = r5;
    r14 = r6;
    r9 = 1;
    r4 = LD32(r10 + 40);
    ST32(r10 + 44, 1);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
    }
    r8 = r13 + 108;
    r4 = LD32(r8);
    r0 = GCALL1(0x0607507C, r4);
    r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, r9);
    r1 = r0;
    ST32(r10 + 40, r1);
    if ((r1 & r1) == 0) {
        r0 = -3;
    } else {
        r5 = LD32(r8);
        r0 = GCALL2(0x060750DC, r1, r5);
        r0 = LD32(r13 + 52);
        ST32(r10 + 48, r0);
        if (r0 == 80) {
            ST32(r13 + 52, 0x1A0A);
        }
        r1 = LD32(r10);
        if (r1 >= 0) {
            r4 = LD32((r13 + 116));
            r6 = 9;
            r0 = GCALL3(0x060752FC, r4, 0x0604AE70, 9);
            if (!((r0 & r0) == 0)) {
                r4 = LD32(r10 + 16);
                if (!((r4 & r4) == 0)) {
                    r5 = R(5);
                    r0 = GCALL3(0x06027F48, r4, r5, r6);
                }
                r8 = 128;
                r4 = LD32(r13 + 128);
                r0 = GCALL1(0x0607507C, r4);
                r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                r1 = r0;
                ST32(r10 + 16, r1);
                if (!((r1 & r1) == 0)) {
                    r5 = LD32(r13 + r8);
                    r0 = GCALL2(0x060750DC, r1, r5);
                    r0 = GCALL2(0x0601057C, 0x0604AE7C, 99);
                    r5 = LD32(r13 + r8);
                    r4 = LD32(r10);
                    r0 = GCALL2(0x0604A400, r4, r5);
                    r8 = r0;
                    r1 = 0;
                    if (!((r8 & r8) == 0)) {
                        r0 = GCALL1(0x0604B280, r10);
                        r0 = r8;
                    } else {
                        ST32(r10 + 12, r1);
                        r9 = 0;
                        r11 = 0;
                        r12 = 0x06027F48;
                        r8 = r10;
                        do {
                            r4 = LD32(r8 + 52);
                            ST32(r8 + 60, r11);
                            if (!((r4 & r4) == 0)) {
                                SETIN(0, r0);
                                r0 = GCALL1(r12, r4);
                                ST32(r8 + 52, r11);
                            }
                            r4 = LD32(r8 + 56);
                            if (!((r4 & r4) == 0)) {
                                SETIN(0, r0);
                                r0 = GCALL1(r12, r4);
                                ST32(r8 + 56, r11);
                            }
                            r9 = r9 + 1;
                            r8 = r8 + 12;
                        } while (AGAIN(!(r9 > 29)));
                        r0 = GCALL1(0x0604AD10, r10);
                        r8 = r0;
                        r4 = sp - 544;
                        if (!(r8 >= 0)) {
                            r0 = GCALL1(0x0604B280, r10);
                            r0 = r8;
                        } else {
                            r6 = LD32(128 + r13);
                            r0 = GCALL3(0x06045264, r4, 0x0604AE84, (r6 + 1));
                            ST32((sp - 548), 0);
                            r0 = GCALL5(0x0604A9E4, r10, r14, (r10 + 0x19C), (sp - 544), LD32((sp - 548)));
                            ST32(r10 + 44, 0);
                            r0 = 0;
                        }
                    }
                } else {
                    r0 = -3;
                }
            } else {
                r0 = GCALL1(0x0604A920, r10);
                r1 = LD32(r10 + 4);
                ST32(r14, r1);
                ST32(r10 + 4, 0);
            }
        } else {
            r2 = 0x0608AD84;
            r1 = LD8(0x0608AD84);
            c4 = (r1 & r1) == 0;
            c1008 = c4;
            if (c4) {
                r2 = r2 + 32;
                c1008 = 1;
            }
            r9 = 0;
            r6 = 0x06075135;
            r7 = 0x19C;
            r3 = 7;
            while (1) {
                r1 = LD8(r2);
                r5 = r1 & 255;
                r0 = r5;
                if ((r5 & r5) == 0) {
                    break;
                } else {
                    r5 = LD8(r0 + r6);
                    r0 = r10;
                    if (!(((r5 & 7) & (r5 & 7)) == 0)) {
                        ST8((r0 + r9) + r7, r1);
                        r9 = r9 + 1;
                    }
                    r2 = r2 + 1;
                    if (!(r9 > r3)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
            ST8((r10 + r9) + 0x19C, 0);
            r6 = LD32(r10 + 48);
            r5 = LD32(r10 + 40);
            c2012 = R(12);
            SETR(12, r12);
            c2014 = R(14);
            SETR(14, r14);
            r0 = GCALL4(0x06049F90, r10, r5, r6, (r10 + 0x19C));
            SETR(12, c2012);
            SETR(14, c2014);
            r8 = r0;
            if ((r8 & r8) == 0) {
                r4 = LD32((r13 + 116));
                r6 = 9;
                r0 = GCALL3(0x060752FC, r4, 0x0604AE70, 9);
                if (!((r0 & r0) == 0)) {
                    r4 = LD32(r10 + 16);
                    if (!((r4 & r4) == 0)) {
                        r5 = R(5);
                        r0 = GCALL3(0x06027F48, r4, r5, r6);
                    }
                    r8 = 128;
                    r4 = LD32(r13 + 128);
                    r0 = GCALL1(0x0607507C, r4);
                    r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
                    r1 = r0;
                    ST32(r10 + 16, r1);
                    if (!((r1 & r1) == 0)) {
                        r5 = LD32(r13 + r8);
                        r0 = GCALL2(0x060750DC, r1, r5);
                        r0 = GCALL2(0x0601057C, 0x0604AE7C, 99);
                        r5 = LD32(r13 + r8);
                        r4 = LD32(r10);
                        r0 = GCALL2(0x0604A400, r4, r5);
                        r8 = r0;
                        r1 = 0;
                        if (!((r8 & r8) == 0)) {
                            r0 = GCALL1(0x0604B280, r10);
                            r0 = r8;
                        } else {
                            ST32(r10 + 12, r1);
                            r9 = 0;
                            r11 = 0;
                            r12 = 0x06027F48;
                            r8 = r10;
                            do {
                                r4 = LD32(r8 + 52);
                                ST32(r8 + 60, r11);
                                if (!((r4 & r4) == 0)) {
                                    SETIN(0, r0);
                                    r0 = GCALL1(r12, r4);
                                    ST32(r8 + 52, r11);
                                }
                                r4 = LD32(r8 + 56);
                                if (!((r4 & r4) == 0)) {
                                    SETIN(0, r0);
                                    r0 = GCALL1(r12, r4);
                                    ST32(r8 + 56, r11);
                                }
                                r9 = r9 + 1;
                                r8 = r8 + 12;
                            } while (AGAIN(!(r9 > 29)));
                            r0 = GCALL1(0x0604AD10, r10);
                            r8 = r0;
                            r4 = sp - 544;
                            if (!(r8 >= 0)) {
                                r0 = GCALL1(0x0604B280, r10);
                                r0 = r8;
                            } else {
                                r6 = LD32(128 + r13);
                                r0 = GCALL3(0x06045264, r4, 0x0604AE84, (r6 + 1));
                                ST32((sp - 548), 0);
                                r0 = GCALL5(0x0604A9E4, r10, r14, (r10 + 0x19C), (sp - 544), LD32((sp - 548)));
                                ST32(r10 + 44, 0);
                                r0 = 0;
                            }
                        }
                    } else {
                        r0 = -3;
                    }
                } else {
                    r0 = GCALL1(0x0604A920, r10);
                    r1 = LD32(r10 + 4);
                    ST32(r14, r1);
                    ST32(r10 + 4, 0);
                }
            } else {
                r0 = GCALL1(0x0604B280, r10);
                r0 = r8;
            }
        }
    }
    return r0;
}
