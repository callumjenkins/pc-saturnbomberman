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
int f06040A04(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r13, r14, c23, c26, c2011;
    FRAME(sp, 300);

    r10 = r5;
    r0 = 0x100;
    ST32(0x100 + (sp - 296), r6);
    r8 = LD32((r10 + 104));
    r13 = r4;
    if ((r8 & r8) == 0) {
        r1 = LD32(r13 + 52);
        if (!((r1 & r1) == 0)) {
            r0 = GCALL3(r1, -1, r5, r6);
        }
    } else {
        r0 = GCALL1(0x0607507C, r8);
        if ((unsigned)r0 > (unsigned)8) {
            r9 = 0x060752FC;
            r6 = 9;
            while (1) {
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
                                                        do {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                        } while (AGAIN(!(c26)));
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
                                                        do {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                        } while (AGAIN(!(c26)));
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
                                                        do {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                        } while (AGAIN(!(c26)));
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
                                                        do {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                        } while (AGAIN(!(c26)));
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
                                                    do {
                                                        r4 = r4 + 1;
                                                        r1 = LD8(r4);
                                                        c26 = (r1 & 255) == 38;
                                                        r1 = r1 & 255;
                                                    } while (AGAIN(!(c26)));
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
                                                    do {
                                                        r4 = r4 + 1;
                                                        r1 = LD8(r4);
                                                        c26 = (r1 & 255) == 38;
                                                        r1 = r1 & 255;
                                                    } while (AGAIN(!(c26)));
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
                                                    do {
                                                        r4 = r4 + 1;
                                                        r1 = LD8(r4);
                                                        c26 = (r1 & 255) == 38;
                                                        r1 = r1 & 255;
                                                    } while (AGAIN(!(c26)));
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
                                                    do {
                                                        r4 = r4 + 1;
                                                        r1 = LD8(r4);
                                                        c26 = (r1 & 255) == 38;
                                                        r1 = r1 & 255;
                                                    } while (AGAIN(!(c26)));
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
                                                            do {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                                c26 = (r1 & 255) == 38;
                                                                r1 = r1 & 255;
                                                            } while (AGAIN(!(c26)));
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
                                                            do {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                                c26 = (r1 & 255) == 38;
                                                                r1 = r1 & 255;
                                                            } while (AGAIN(!(c26)));
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
                                                            do {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                                c26 = (r1 & 255) == 38;
                                                                r1 = r1 & 255;
                                                            } while (AGAIN(!(c26)));
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
                                                            do {
                                                                r4 = r4 + 1;
                                                                r1 = LD8(r4);
                                                                c26 = (r1 & 255) == 38;
                                                                r1 = r1 & 255;
                                                            } while (AGAIN(!(c26)));
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
                                                        do {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                        } while (AGAIN(!(c26)));
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
                                                        do {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                        } while (AGAIN(!(c26)));
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
                                                        do {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                        } while (AGAIN(!(c26)));
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
                                                        do {
                                                            r4 = r4 + 1;
                                                            r1 = LD8(r4);
                                                            c26 = (r1 & 255) == 38;
                                                            r1 = r1 & 255;
                                                        } while (AGAIN(!(c26)));
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
                                do {
                                    r4 = r4 + 1;
                                    r1 = LD8(r4);
                                    c26 = (r1 & 255) == 38;
                                    r1 = r1 & 255;
                                } while (AGAIN(!(c26)));
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
                                r0 = GCALL1(r1, -3);
                            }
                        }
                    }
                } else {
                    r1 = LD32(r13 + 52);
                    if (!((r1 & r1) == 0)) {
                        r0 = GCALL1(r1, -605);
                    }
                }
            }
        } else {
            r1 = LD32(r13 + 52);
            if (!((r1 & r1) == 0)) {
                r0 = GCALL3(r1, -1, r5, r6);
            }
        }
    }
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
                                    r0 = GCALL8(0x060752FC, r4, (r11 + 2), r10, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
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
int f060424BC(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14, c8;
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
                r0 = GCALL2(r14, r8, r5);
                r4 = LD32(r9);
                r9 = r9 + 4;
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
                r0 = GCALL2(r14, r8, r5);
                r4 = LD32(r9);
                r9 = r9 + 4;
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
        r0 = GCALL5(r14, 0, (r0 + 1), -1, 1, LD32((sp - 36)));
        ST32(r9, r0);
        if (!((r0 & r0) == 0)) {
            r8 = 0x060750DC;
            r0 = GCALL5(0x060750DC, r0, r13, 0, 0, LD32((sp - 36)));
            r4 = LD32(sp - 36);
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL5(r10, r4, r5, r6, r7, LD32((sp - 36)));
            r0 = GCALL5(r14, 0, (r0 + 1), -1, 1, LD32((sp - 36)));
            ST32(r9 + 4, r0);
            if (!((r0 & r0) == 0)) {
                r5 = LD32(sp - 36);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(r8, r0, r5, r6, r7, LD32((sp - 36)));
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(r10, r12, r5, r6, r7, LD32((sp - 36)));
                r0 = GCALL5(r14, 0, (r0 + 1), -1, 1, LD32((sp - 36)));
                ST32(r9 + 8, r0);
                if (!((r0 & r0) == 0)) {
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(r8, r0, r12, r6, r7, LD32((sp - 36)));
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(r10, r11, r5, r6, r7, LD32((sp - 36)));
                    r0 = GCALL5(r14, 0, (r0 + 1), -1, 1, LD32((sp - 36)));
                    ST32(r9 + 12, r0);
                    if (!((r0 & r0) == 0)) {
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(r8, r0, r11, r6, r7, LD32((sp - 36)));
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(r10, r12, r5, r6, r7, LD32((sp - 36)));
                        r8 = r0;
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(r10, r11, r5, r6, r7, LD32((sp - 36)));
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
    r0 = GCALL2(r1, -1, 0xBFFF);
    r10 = 0x06000310;
    r9 = 63;
    do {
        r1 = LD32(r10);
        r0 = GCALL2(r1, r8, 0);
        r8 = r8 + 1;
        r1 = 95;
    } while (AGAIN(!(r8 > r9)));
    if (!(r8 > r1)) {
        r9 = r1;
        r10 = 0x06000300;
        do {
            r1 = LD32(r10);
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
        r0 = GCALL5(r1, r8, r5, r6, r7, v20);
        r8 = r8 + 1;
    } while (AGAIN(!(r8 > r9)));
    return r0;
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
int f06047240(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r10, c3, c1006;
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
                            r7 = R(7);
                            r0 = GCALL6(r10, 0x06089964, 0, r6, r7, LD32((sp - 188)), LD32((sp - 184)));
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
