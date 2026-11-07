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
        r0 = GCALL4(r1, 6, 0, r6, r7);
        r0 = 1;
    } else {
        r0 = 0;
    }
    return r0;
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
    r0 = GCALL4(r1, 6, 0, 0, r7);
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
int f06046860(void)
{
    int r0, r1;

    r0 = SR();
    SETSR((r0 | 240));
    r0 = GCALL0(0x06066F38);
    r0 = GCALL0(0x06051E6C);
    r1 = LD32(0x0600026C);
    r0 = GCALL0(r1);
    while (1) {
        POLL();
    }
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
                r0 = GCALL3(r10, r9, 0x060476B4, r6);
                r6 = 9;
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL3(r10, r9, 0x060476C0, r6);
                    r6 = 7;
                    if (!((r0 & r0) == 0)) {
                        r0 = GCALL3(r10, r9, 0x060476CC, r6);
                        r6 = 7;
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL3(r10, r9, 0x060476D4, r6);
                            r6 = 5;
                            if (!((r0 & r0) == 0)) {
                                r0 = GCALL3(r10, r9, 0x060476DC, r6);
                                r6 = 5;
                                if (!((r0 & r0) == 0)) {
                                    r0 = GCALL3(r10, r9, 0x060476E8, r6);
                                    r6 = 9;
                                    if (!((r0 & r0) == 0)) {
                                        r0 = GCALL3(r10, r9, 0x060476F0, r6);
                                        r6 = 9;
                                        if (!((r0 & r0) == 0)) {
                                            r0 = GCALL3(r10, r9, 0x060476FC, r6);
                                            r6 = 9;
                                            if (!((r0 & r0) == 0)) {
                                                r0 = GCALL3(r10, r9, 0x06047708, r6);
                                                r6 = 12;
                                                if (!((r0 & r0) == 0)) {
                                                    r0 = GCALL3(r10, r9, 0x06047714, r6);
                                                    r6 = 9;
                                                    if (!((r0 & r0) == 0)) {
                                                        r0 = GCALL3(r10, r9, 0x06047724, r6);
                                                        r6 = 10;
                                                        if (!((r0 & r0) == 0)) {
                                                            r0 = GCALL3(r10, r9, 0x06047738, r6);
                                                            r6 = 10;
                                                            if (!((r0 & r0) == 0)) {
                                                                r0 = GCALL3(r10, r9, 0x0604774C, r6);
                                                                r6 = 10;
                                                                if (!((r0 & r0) == 0)) {
                                                                    r0 = GCALL3(r10, r9, 0x06047758, r6);
                                                                    r6 = 13;
                                                                    if (!((r0 & r0) == 0)) {
                                                                        r0 = GCALL3(r10, r9, 0x06047764, r6);
                                                                        r6 = 5;
                                                                        if (!((r0 & r0) == 0)) {
                                                                            r0 = GCALL3(r10, r9, 0x06047774, r6);
                                                                            r6 = 5;
                                                                            if (!((r0 & r0) == 0)) {
                                                                                r0 = GCALL3(r10, r9, 0x0604777C, r6);
                                                                                if (!((r0 & r0) == 0)) {
                                                                                    r9 = r9 + 1;
                                                                                } else {
                                                                                    r9 = r9 + 5;
                                                                                    r6 = 32;
                                                                                    r5 = r9;
                                                                                    r4 = 0x060898E4;
                                                                                    r0 = GCALL3(r11, r4, r5, r6);
                                                                                    r9 = r9 + r0;
                                                                                }
                                                                            } else {
                                                                                r9 = r9 + 5;
                                                                                r6 = 32;
                                                                                r4 = 0x060898C4;
                                                                                r5 = r9;
                                                                                r0 = GCALL3(r11, r4, r5, r6);
                                                                                r9 = r9 + r0;
                                                                            }
                                                                        } else {
                                                                            r9 = r9 + 13;
                                                                            r6 = 32;
                                                                            r4 = 0x06089884;
                                                                            r5 = r9;
                                                                            r0 = GCALL3(r11, r4, r5, r6);
                                                                            r9 = r9 + r0;
                                                                        }
                                                                    } else {
                                                                        r9 = r9 + 10;
                                                                        r6 = 32;
                                                                        r4 = 0x06089864;
                                                                        r5 = r9;
                                                                        r0 = GCALL3(r11, r4, r5, r6);
                                                                        r9 = r9 + r0;
                                                                    }
                                                                } else {
                                                                    r9 = r9 + 10;
                                                                    r6 = 32;
                                                                    r4 = 0x06089844;
                                                                    r5 = r9;
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
                                                        r0 = GCALL3(r11, r4, r5, r6);
                                                        r9 = r9 + r0;
                                                    }
                                                } else {
                                                    r9 = r9 + 9;
                                                    r6 = 32;
                                                    r4 = 0x060897C4;
                                                    r5 = r9;
                                                    r0 = GCALL3(r11, r4, r5, r6);
                                                    r9 = r9 + r0;
                                                }
                                            } else {
                                                r9 = r9 + 9;
                                                r6 = 32;
                                                r4 = 0x06089944;
                                                r5 = r9;
                                                r0 = GCALL3(r11, r4, r5, r6);
                                                r9 = r9 + r0;
                                            }
                                        } else {
                                            r9 = r9 + 9;
                                            r6 = 32;
                                            r4 = 0x06089924;
                                            r5 = r9;
                                            r0 = GCALL3(r11, r4, r5, r6);
                                            r9 = r9 + r0;
                                        }
                                        r1 = LD8(r9);
                                    } else {
                                        r9 = r9 + 5;
                                        r8 = (sp - 96) + 32;
                                        r0 = GCALL3(r11, r8, r9, 32);
                                        r9 = r9 + r0;
                                        r0 = GCALL2(0x06075408, r8, 0x060476E4);
                                        r0 = GCALL3(0x06059CE4, r8, 0x060899A8, (sp - 32));
                                        r1 = LD8(r9);
                                    }
                                } else {
                                    r9 = r9 + 5;
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
                                r0 = GCALL3(r11, r4, r5, r6);
                                r9 = r9 + r0;
                                r1 = LD8(r9);
                            }
                        } else {
                            r9 = r9 + 7;
                            r6 = 32;
                            r4 = 0x06089964;
                            r5 = r9;
                            r0 = GCALL3(r11, r4, r5, r6);
                            r9 = r9 + r0;
                            r1 = LD8(r9);
                        }
                    } else {
                        r9 = r9 + 9;
                        r6 = 32;
                        r4 = 0x06089824;
                        r5 = r9;
                        r0 = GCALL3(r11, r4, r5, r6);
                        r9 = r9 + r0;
                        r1 = LD8(r9);
                    }
                } else {
                    r9 = r9 + 9;
                    r6 = 32;
                    r4 = 0x06089804;
                    r5 = r9;
                    r0 = GCALL3(r11, r4, r5, r6);
                    r9 = r9 + r0;
                    r1 = LD8(r9);
                }
            } else {
                r9 = r9 + 9;
                r6 = 32;
                r4 = 0x060897E4;
                r5 = r9;
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
                    r0 = GCALL3(r13, r9, 0x06079258, r6);
                    r4 = LD32(r8 + 4);
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
            r0 = GCALL2(r10, r8, r5);
            if (!(r0 >= 0)) {
                break;
            } else {
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
                r0 = GCALL2(r10, (sp - 528), 0x0604AD04);
                if ((r0 & r0) == 0) {
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
                    r0 = GCALL2(r10, (sp - 528), r5);
                    r8 = r0;
                    if ((r8 & r8) == 0) {
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
int f06044030(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11;

    r11 = r4;
    r10 = 0x0608BD04;
    r6 = LD32(0x0608BD04);
    r5 = LD32(0x0608BD08);
    r0 = GCALL4(0x06027C18, 0, r5, ((r6 + 1) << 2), r7);
    r9 = r0;
    if ((r9 & r9) == 0) {
        r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
        r0 = GCALL1(0x06010DDC, 24);
        ST32(0x060766C0, 0);
    } else {
        ST32(r10 + 4, r9);
        r0 = GCALL1(0x0607507C, r11);
        r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
        r8 = r0;
        r5 = r11;
        if ((r8 & r8) == 0) {
            r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
            r0 = GCALL1(0x06010DDC, 24);
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
                r0 = GCALL1(0x06010DDC, 24);
                ST32(0x060766C0, 0);
            } else {
                r0 = GCALL1(0x06010DDC, 16);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060440E4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11;

    r11 = r4;
    r10 = 0x0608BCF4;
    r6 = LD32(0x0608BCF4);
    r5 = LD32(0x0608BCF8);
    r0 = GCALL4(0x06027C18, 0, r5, ((r6 + 1) << 2), r7);
    r9 = r0;
    if ((r9 & r9) == 0) {
        r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
        r0 = GCALL1(0x06010DDC, 24);
    } else {
        ST32(r10 + 4, r9);
        r0 = GCALL1(0x0607507C, r11);
        r0 = GCALL4(0x060279E0, 0, (r0 + 1), -1, 1);
        r8 = r0;
        r5 = r11;
        if ((r8 & r8) == 0) {
            r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
            r0 = GCALL1(0x06010DDC, 24);
        } else {
            r0 = GCALL2(0x060750DC, r8, r5);
            r1 = LD32(r10);
            ST32((r1 << 2) + r9, r8);
            r1 = LD32(r10);
            ST32(r10, (r1 + 1));
            r0 = GCALL0(0x06043C08);
            if (!((r0 & r0) == 0)) {
                r0 = GCALL2(0x06045264, 0x0608B860, 0x06043CE4);
                r0 = GCALL1(0x06010DDC, 24);
            }
        }
    }
    ST32(0x060766C0, 0);
    return r0;
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
void f060465B0(int r4, int r5)
{
    int r1, r2, r3, r7, c1002;

    r4 = r4 - 8;
    r2 = LD32(r5);
    r3 = 0;
    if (!((r2 & r2) == 0)) {
        c1002 = (unsigned)r2 >= (unsigned)r4;
        do {
            r3 = r2;
            r2 = LD32(r2);
            c1002 = (unsigned)r2 >= (unsigned)r4;
        } while (AGAIN(!((r2 & r2) == 0)));
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
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, c6, c7, c1002, c1011;

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
        do {
            r3 = r2;
            r2 = LD32(r3);
            c1002 = (unsigned)r2 >= (unsigned)r7;
        } while (AGAIN(!((r2 & r2) == 0)));
    }
    r1 = 0;
    if ((r7 + r8) == r2) {
        r1 = LD32(r2 + 4);
    }
    r6 = r8 + r1;
    c6 = (r1 & r1) == 0;
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
        c7 = (r3 & r3) == 0;
        if (!(c6)) {
            ST32(r7 + 4, r6);
            if (!(c7)) {
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
