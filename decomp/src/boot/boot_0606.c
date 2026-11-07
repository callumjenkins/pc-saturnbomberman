#include "krnl.h"

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06060240(void)
{
    int r0, r1, r4, r8, r9, r10, r11, r12;

    r1 = LD32(0x0608D88C);
    r9 = 0;
    r8 = 0;
    if (!(0 >= r1)) {
        r12 = 0x0608D890;
        r11 = 0x0605723C;
        do {
            r0 = LD32(r12);
            r10 = 220;
            r1 = LD16(r0 + r8);
            r4 = r0 + r8;
            if (!((r1 & r1) == 0)) {
                r0 = GCALL2(r11, r4, -506);
            }
            r1 = LD32(0x0608D88C);
            r9 = r9 + 1;
            r8 = r8 + r10;
        } while (AGAIN(!(r9 >= r1)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060603F8(int r4, int r5)
{
    ST8(r5, 0);
    ST8((r5 + 1), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06060404(int r4)
{
    ST8(r4, 0);
    ST8((r4 + 1), 45);
    ST8((r4 + 2), 15);
    ST8((r4 + 3), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06060420(int r4, int r5, int r6)
{
    int r1;

    r1 = LD8((r4 + 4));
    ST8(r6, r1);
    r1 = LD8((r4 + 5));
    ST8((r6 + 1), r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060434(int r4, int r5)
{
    int r0, r1, r2, r3, c0, c2, c3;

    r1 = LD8((r4 + 1));
    r2 = LD8((r5 + 1));
    c0 = r2 == ((r1 & 255) - 2);
    r2 = r4;
    if (c0) {
        r2 = r2 + 2;
        r1 = LD8(r2);
        r3 = 0;
        if (((r1 & 255) & (r1 & 255)) == 0) {
            r1 = LD8((r4 + 3));
            c2 = (r1 & 255) == 45;
            r1 = r2;
            if (c2) {
                r1 = LD8((r1 + 2));
                c3 = (unsigned)((r1 - 3) & 255) > (unsigned)251;
                r1 = r4;
                if (!(c3)) {
                    r1 = LD8((r1 + 5));
                    r0 = 1;
                    if (!((unsigned)(r1 & 255) > (unsigned)1)) {
                        r3 = r0;
                    }
                }
            }
        }
        return r3;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606048C(int r4)
{
    int r1;

    r1 = LD8(r4);
    return ((r1 & 255) & (r1 & 255)) == 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06060498(int r4, int r5)
{
    int r1;

    ST8(r4, 0);
    ST8((r4 + 1), 45);
    r1 = LD8(r5);
    ST8((r4 + 2), r1);
    r1 = LD8((r5 + 1));
    ST8((r4 + 3), r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060604B4(int r4)
{
    ST8(r4, 15);
    ST8((r4 + 1), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060604D8(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x060604C0, -1, r5, 1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060604EC(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x060604C0, -1, r5, 3);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060500(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;

    r3 = r4;
    r2 = r3 + 2;
    r4 = LD8(r2);
    r1 = LD8((r3 + 3));
    r4 = ((r4 << 16) << 8) | ((r1 & 255) << 16);
    r1 = LD8((r2 + 2));
    r4 = r4 | ((r1 & 255) << 8);
    r1 = LD8((r3 + 5));
    r0 = GCALL3(0x060604C0, (r4 | (r1 & 255)), r6, 1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060540(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;

    r3 = r4;
    r2 = r3 + 2;
    r4 = LD8(r2);
    r1 = LD8((r3 + 3));
    r4 = ((r4 << 16) << 8) | ((r1 & 255) << 16);
    r1 = LD8((r2 + 2));
    r4 = r4 | ((r1 & 255) << 8);
    r1 = LD8((r3 + 5));
    r0 = GCALL3(0x060604C0, (r4 | (r1 & 255)), r6, 3);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06060580(int r4)
{
    ST8(r4, 0);
    ST8((r4 + 1), 0);
    ST8((r4 + 2), 0);
    ST8((r4 + 3), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06060598(int r4, int r5)
{
    int r2;

    r2 = LD32(r5);
    ST8(r4, ((int)((unsigned)((int)((unsigned)r2 >> 16)) >> 8)));
    ST8((r4 + 1), ((int)((unsigned)r2 >> 16)));
    ST8((r4 + 2), ((int)((unsigned)r2 >> 8)));
    ST8((r4 + 3), r2);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060605BC(int r4)
{
    int r0;

    r0 = LD32(r4);
    return r0 == -1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060605C4(int r4)
{
    int r0;

    r0 = GCALL3(0x060604C0, 0, r4, 3);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060605F4(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x060605DC, 0, r5, 2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060608(int r4, int r5)
{
    int r0;

    r0 = GCALL3(0x060605DC, 0, r5, 4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606061C(int r4)
{
    int r0;

    r0 = GCALL3(0x060605DC, 1, r4, 4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060634(int r4, int r5, int r6)
{
    int r0;

    r0 = GCALL3(0x060605DC, 1, r6, 2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606064C(int r4, int r5, int r6)
{
    int r0;

    r0 = GCALL3(0x060605DC, 1, r6, 4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06060664(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06060668(void)
{
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606066C(int r4)
{
    int r1;

    r1 = LD8(r4);
    return (r1 & r1) == 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060674(int r4, int r5)
{
    int r1, r2;

    r1 = LD8((r4 + 1));
    r2 = LD8((r5 + 1));
    return ((r1 & 255) - 2) == r2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06060710(int r4, int r5)
{
    int r0, r1, r6;

    r1 = LD8((r5 + 3));
    if ((r1 & r1) == 0) {
        r6 = LD8((r5 + 1));
        if (!((r6 & r6) == 0)) {
            r1 = LD32(r5 + 4);
            r0 = GCALL3(0x0604B358, r4, (((r6 + r6) + r6) + r1), r6);
        }
        return;
    } else {
        r1 = LD32(r5 + 4);
        r1 = LD32(r1 + 8);
        r0 = GCALL2(r1, r4, r5);
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060750(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;

    r3 = r4;
    r2 = r6;
    r0 = LD8((r5 + 2));
    r1 = LD8((r5 + 3));
    r4 = r2 + r0;
    if ((r1 & r1) == 0) {
        r6 = LD8((r5 + 1));
        r5 = r3;
        if (!((r6 & r6) == 0)) {
            r0 = GCALL3(0x0604B358, r4, (r5 + 2), r6);
        } else {
            ST8(r0 + r2, 1);
        }
        return r0;
    } else {
        r1 = LD32(r5 + 4);
        r1 = LD32(r1 + 12);
        r0 = GCALL3(r1, r3, r5, r4);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060814(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, r11, c2;

    r1 = LD8((r5 + 3));
    if ((r1 & r1) == 0) {
        r9 = LD8((r5 + 1));
        r1 = LD8((r4 + 1));
        r1 = (r1 & 255) - 2;
        if (!((r9 & r9) == 0)) {
            r0 = 0;
            if (r9 == r1) {
                r10 = r4 + 2;
                r11 = 0x060603D0;
                r1 = LD8((r5 + 1));
                r2 = LD32(r5 + 4);
                r8 = r2 + (r1 << 2);
                r0 = GCALL3(0x060603D0, r10, r8, r9);
                r8 = r8 + r9;
                if (!(r0 >= 0)) {
                    r0 = 0;
                } else {
                    r0 = GCALL3(r11, r10, r8, r9);
                    r0 = 0 >= r0;
                }
            }
        } else {
            c2 = (r1 & r1) == 0;
            r0 = c2;
            if (!(c2)) {
                r0 = 0;
                if (r9 == r1) {
                    r10 = r4 + 2;
                    r11 = 0x060603D0;
                    r1 = LD8((r5 + 1));
                    r2 = LD32(r5 + 4);
                    r8 = r2 + (r1 << 2);
                    r0 = GCALL3(0x060603D0, r10, r8, r9);
                    r8 = r8 + r9;
                    if (!(r0 >= 0)) {
                        r0 = 0;
                    } else {
                        r0 = GCALL3(r11, r10, r8, r9);
                        r0 = 0 >= r0;
                    }
                }
            }
        }
    } else {
        r1 = LD32(r5 + 4);
        r0 = LD32(r1 + 32);
        r0 = GCALL2(r0, r4, r5);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060898(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;

    r3 = r4;
    r2 = r6;
    r0 = LD8((r5 + 2));
    r1 = LD8((r5 + 3));
    r4 = r2 + r0;
    if ((r1 & r1) == 0) {
        r6 = LD8((r5 + 1));
        r5 = r3;
        if (!((r6 & r6) == 0)) {
            r0 = GCALL3(0x0604B358, r4, (r5 + 2), r6);
        } else {
            ST8(r0 + r2, 1);
        }
        return r0;
    } else {
        r1 = LD32(r5 + 4);
        r1 = LD32(r1 + 16);
        r0 = GCALL3(r1, r3, r5, r4);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606091C(int r4, int r5, int r6)
{
    int r0, r1;

    r1 = LD8((r6 + 3));
    if ((r1 & r1) == 0) {
        r6 = LD8((r6 + 1));
        r0 = GCALL3(0x0604B358, r4, r5, r6);
        return r0;
    } else {
        r1 = LD32(r6 + 4);
        r1 = LD32(r1 + 28);
        r0 = GCALL3(r1, r4, r5, r6);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060994(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11;

    r10 = r4;
    r11 = r5;
    r1 = LD32(r11);
    r2 = r6;
    r4 = LD32(r10);
    r8 = r1 - r4;
    r9 = r8;
    if (!((r2 - r8) >= r7)) {
        r9 = r9 + r7;
        r0 = LD32(0x0608D3A8);
        r0 = GCALL4(r0, r4, r9, r6, r7);
        r2 = r9;
        if (!((r0 & r0) == 0)) {
            ST32(r10, r0);
            ST32(r11, (r0 + r8));
        } else {
            r2 = -1;
        }
    }
    return r2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060618C4(int r4)
{
    int r0, r1, r2, r3;

    r0 = r4;
    r2 = 19;
    r3 = 0x0606182C;
    while (1) {
        r1 = LD32(r3);
        if (r1 == r0) {
            break;
        } else {
            r2 = r2 - 1;
            r3 = r3 + 8;
            if (r2 > 0) {
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
    }
    if (!((r2 & r2) == 0)) {
        r0 = LD32(r3 + 4);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06061A64(int r4)
{
    int r1, r2;

    r1 = LD16(r4);
    r2 = r4 + 2;
    ST16(r4, r1);
    r1 = LD16(r2);
    r4 = r4 + 4;
    ST16(r2, r1);
    r1 = LD16(r4);
    ST16(r4, r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06061A78(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7;

    r5 = r4 + 20;
    r0 = LD16((r4 + 24));
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
    r1 = LD8((r4 + 9));
    r7 = r7 + ((r1 & 255) + r0);
    r3 = r5;
    if (!(((1 & r0) & (1 & r0)) == 0)) {
        ST8(r0 + r3, 0);
        r0 = (short)(r0 + 1);
    }
    r0 = (short)((((int)((unsigned)r0 >> 31)) + r0) >> 1);
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
void f06061F9C(int r4)
{
    int r1, r2;

    r1 = LD16(r4);
    r2 = r4 + 2;
    ST16(r4, r1);
    r1 = LD16(r2);
    r4 = r4 + 4;
    ST16(r2, r1);
    r1 = LD16(r4);
    ST16(r4, r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060622B4(void)
{
    FRAME(sp, 4);

    ST16(0x06079FB4, 0);
    ST32(0x06079FB8, 1);
    ST32(0x06079FBC, 0);
    ST32(0x06079FC0, 0);
    ST32(0x06079FC4, 0);
    ST32(0x06079FC8, 0);
    ST32(0x06079FCC, 0);
    ST32(0x06089644, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606301C(void)
{
    FRAME(sp, 4);

    ST32(0x06079FE0, 0x060FFE1C);
    ST16(0x0608DA0A, 1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606303C(void)
{
    FRAME(sp, 4);

    ST16(0x0608DA0A, 0);
    ST32(0x06079FE0, 0x0608E7A0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06063248(int r4, int r5, int r6)
{
    int r0, r2;
    FRAME(sp, 4);

    r0 = LD8(0x0608E920);
    r0 = r0 | 128;
    ST8(0x0608E920, r0);
    r2 = LD16(0x0608E9A0);
    r0 = r0 | 128;
    r4 = (r4 & 255) | (r2 & 0xFFF0);
    ST16(0x0608E9A0, r4);
    ST8(0x0608E920, r0);
    r4 = (r4 & 0xFFDF) | ((((r5 & 255) << 2) + ((r5 & 255) << 2)) << 2);
    ST16(0x0608E9A0, r4);
    ST8(0x0608E920, r0);
    ST16(0x0608E9A0, ((r4 & 0xFFEF) | (((r6 & 255) << 2) << 2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06063E44(int r4)
{
    FRAME(sp, 4);

    ST32(r4, 0);
    ST32(r4 + 4, 0);
    ST8((r4 + 8), 0);
    ST8((r4 + 9), 0);
    ST8((r4 + 10), 0);
    ST8((r4 + 11), 0);
    ST8((r4 + 12), 0);
    ST8((r4 + 13), 0);
    ST8((r4 + 14), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060643D8(void)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD16(0x0608E6FE);
    return ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 8)) >> 2)) >> 2)) & 3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060643F4(void)
{
    FRAME(sp, 4);

    ST8(0x0608E97A, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06064E00(void)
{
    int r0, r1, r2, r3, r7;
    FRAME(sp, 28);

    r0 = LD8(0x0608E920);
    r0 = r0 | 128;
    ST8(0x0608E920, r0);
    r0 = r0 | 128;
    r2 = LD16(0x0608E9A0);
    r7 = r0;
    r1 = 0x3000 | (r2 & 0xFFF);
    ST16(0x0608E9A0, r1);
    ST8(0x0608E920, r0);
    r0 = r1 | 32;
    r3 = LD16(0x0608E9AC);
    r1 = 0xFFEF & r0;
    r3 = r3 & 0xFFBF;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A0, r0);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A0, r1);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A0, ((r1 & 0xFFF0) | 7));
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608E9A4);
    r1 = r1 & 0xFFF0;
    ST16(0x0608E9A4, r1);
    ST8(0x0608E920, r7);
    r0 = r1 & -241;
    ST16(0x0608E9A4, r0);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A4, (-3841 & r0));
    ST8(0x0608E920, r7);
    r1 = 255 & r0;
    ST16(0x0608E9A4, r1);
    ST8(0x0608E920, r7);
    r2 = LD16(0x0608E9A6);
    r1 = r1 & 0xFFF0;
    r2 = r2 & 0xFFF0;
    ST16(0x0608E9A6, r2);
    ST8(0x0608E920, r7);
    r2 = r2 & -241;
    ST16(0x0608E9A6, r2);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A4, r1);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A4, (r1 & -241));
    ST8(0x0608E920, r7);
    ST16(0x0608E9A4, 0);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A4, 0);
    ST8(0x0608E920, r7);
    r2 = r2 & 0xFFF0;
    ST16(0x0608E9A6, r2);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A6, (r2 & -241));
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608E9A8);
    r1 = r1 & 0xFFFE;
    ST16(0x0608E9A8, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFFD;
    ST16(0x0608E9A8, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFFB;
    ST16(0x0608E9A8, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFF7;
    ST16(0x0608E9A8, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFEF;
    ST16(0x0608E9A8, r1);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A8, (r1 & 0xFFDF));
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608E9AA);
    r1 = r1 & 0xFFFC;
    ST16(0x0608E9AA, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFF3;
    ST16(0x0608E9AA, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFCF;
    ST16(0x0608E9AA, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFF3F;
    ST16(0x0608E9AA, r1);
    ST8(0x0608E920, r7);
    ST16(0x0608E9AA, (r1 & 0xFCFF));
    ST8(0x0608E920, r7);
    r3 = r3 & 0x7FFF;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = r3 & -28673;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = r3 & -1025;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = r3 & -513;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = (r3 & 0xFEFF) | 0x100;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = r3 & 0xFFBF;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = r3 & 0xFFDF;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = r3 & 0xFFEF;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = r3 & 0xFFF7;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = r3 & 0xFFFB;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    r3 = r3 & 0xFFFD;
    ST16(0x0608E9AC, r3);
    ST8(0x0608E920, r7);
    ST16(0x0608E9AC, (r3 & 0xFFFE));
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608E9AE);
    r1 = r1 & 0xFFFC;
    ST16(0x0608E9AE, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFF3;
    ST16(0x0608E9AE, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFCF;
    ST16(0x0608E9AE, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFF3F;
    ST16(0x0608E9AE, r1);
    ST8(0x0608E920, r7);
    ST16(0x0608E9AE, (r1 & 0xFCFF));
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608E9A2);
    r1 = r1 & 0xFFFE;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFFD;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFFB;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFF7;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFEF;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r7);
    r1 = r1 & 0xFFDF;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r7);
    ST16(0x0608E9A2, (r1 & 0xFEFF));
    ST8(0x0608E920, r7);
    return 0xFFFC;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606503C(void)
{
    int r0, r1, r7;
    FRAME(sp, 4);

    r0 = LD8(0x0608E920);
    r0 = r0 | 64;
    ST8(0x0608E920, r0);
    r0 = r0 | 64;
    r1 = LD16(0x0608EFB8);
    r7 = r0;
    r1 = r1 & 0xFFF0;
    ST16(0x0608EFB8, r1);
    ST8(0x0608E920, r0);
    ST16(0x0608EFB8, (r1 & -3841));
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608EFBA);
    r1 = r1 & 0xFFF0;
    ST16(0x0608EFBA, r1);
    ST8(0x0608E920, r7);
    ST16(0x0608EFBA, (r1 & -3841));
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608EFBC);
    r1 = r1 & 0xFFF0;
    ST16(0x0608EFBC, r1);
    ST8(0x0608E920, r7);
    ST16(0x0608EFBC, (r1 & -3841));
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608EFBE);
    r1 = r1 & 0xFFF0;
    ST16(0x0608EFBE, r1);
    ST8(0x0608E920, r7);
    ST16(0x0608EFBE, (r1 & -3841));
    ST8(0x0608E920, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060650A8(void)
{
    int r0, r1, r2, r6;
    FRAME(sp, 4);

    r0 = LD8(0x0608E920);
    r2 = 32 | r0;
    ST8(0x0608E920, r2);
    r2 = r2 | 32;
    r1 = LD16(0x0608E970);
    r6 = r2;
    r0 = (r1 & -256) | 3;
    ST16(0x0608E970, r0);
    ST8(0x0608E920, r2);
    ST16(0x0608E970, (0x200 | (r0 & 3)));
    ST8(0x0608E920, r6);
    r1 = LD16(0x0608E972);
    r0 = (r1 & -256) | 1;
    ST16(0x0608E972, r0);
    ST8(0x0608E920, r6);
    r0 = r0 & 1;
    ST16(0x0608E972, r0);
    ST8(0x0608E920, r6);
    ST16(0x0608E974, 4);
    ST8(0x0608E920, r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06065104(void)
{
    int r0, r1, r7;
    FRAME(sp, 4);

    r0 = LD8(0x0608E920);
    r0 = r0 | 16;
    ST8(0x0608E920, r0);
    r0 = r0 | 16;
    r1 = LD16(0x0608E958);
    r7 = r0;
    ST16(0x0608E958, (r1 & -256));
    ST8(0x0608E920, r0);
    ST16(0x0608E958, 0);
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608E95A);
    ST16(0x0608E95A, (r1 & -256));
    ST8(0x0608E920, r7);
    ST16(0x0608E95A, 0);
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608E95C);
    ST16(0x0608E95C, (r1 & -256));
    ST8(0x0608E920, r7);
    ST16(0x0608E95C, 0);
    ST8(0x0608E920, r7);
    r1 = LD16(0x0608E95E);
    ST16(0x0608E95E, (r1 & -256));
    ST8(0x0608E920, r7);
    ST16(0x0608E95C, 0);
    ST8(0x0608E920, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06065164(void)
{
    int r0, r1, r6;
    FRAME(sp, 4);

    r0 = LD8(0x0608E920);
    r0 = r0 | 8;
    ST8(0x0608E920, r0);
    r0 = r0 | 8;
    r1 = LD16(0x0608E980);
    r6 = r0;
    ST16(0x0608E980, (r1 & -256));
    ST8(0x0608E920, r0);
    ST16(0x0608E980, 0);
    ST8(0x0608E920, r6);
    r1 = LD16(0x0608E982);
    ST16(0x0608E982, (r1 & -256));
    ST8(0x0608E920, r6);
    ST16(0x0608E982, 0);
    ST8(0x0608E920, r6);
    ST16(0x0608E984, 0);
    ST8(0x0608E920, r6);
    r1 = LD16(0x0608E986);
    ST16(0x0608E986, (r1 & -256));
    ST8(0x0608E920, r6);
    ST16(0x0608E986, 0);
    ST8(0x0608E920, r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060651BC(void)
{
    int r0, r1, r2;
    FRAME(sp, 24);

    r0 = LD8(0x0608E920);
    r0 = r0 | 4;
    ST8(0x0608E920, r0);
    r0 = r0 | 4;
    r1 = LD16(0x0608E910);
    r2 = r0;
    r1 = r1 & 0xFFFE;
    ST16(0x0608E910, r1);
    ST8(0x0608E920, r0);
    r1 = r1 & 0xFFFD;
    ST16(0x0608E910, r1);
    ST8(0x0608E920, r2);
    r1 = r1 & 0xFFFB;
    ST16(0x0608E910, r1);
    ST8(0x0608E920, r2);
    r1 = r1 & 0xFFF7;
    ST16(0x0608E910, r1);
    ST8(0x0608E920, r2);
    r1 = r1 & 0xFFEF;
    ST16(0x0608E910, r1);
    ST8(0x0608E920, r2);
    r1 = r1 & 0xFFDF;
    ST16(0x0608E910, r1);
    ST8(0x0608E920, r2);
    ST16(0x0608E910, (r1 & 0xFFBF));
    ST8(0x0608E920, r2);
    r1 = LD16(0x0608E912);
    r1 = r1 & 0xFFFE;
    ST16(0x0608E912, r1);
    ST8(0x0608E920, r2);
    r1 = r1 & 0xFFFD;
    ST16(0x0608E912, r1);
    ST8(0x0608E920, r2);
    r1 = r1 & 0xFFFB;
    ST16(0x0608E912, r1);
    ST8(0x0608E920, r2);
    r1 = r1 & 0xFFF7;
    ST16(0x0608E912, r1);
    ST8(0x0608E920, r2);
    r1 = r1 & 0xFFEF;
    ST16(0x0608E912, r1);
    ST8(0x0608E920, r2);
    r1 = r1 & 0xFFDF;
    ST16(0x0608E912, r1);
    ST8(0x0608E920, r2);
    ST16(0x0608E912, (r1 & 0xFFBF));
    ST8(0x0608E920, r2);
    ST16(0x0608E914, 0);
    ST8(0x0608E920, r2);
    ST16(0x0608E916, 0);
    ST8(0x0608E920, r2);
    ST16(0x0608E918, 0);
    ST8(0x0608E920, r2);
    ST16(0x0608E91A, 0);
    ST8(0x0608E920, r2);
    ST16(0x0608E91C, 0);
    ST8(0x0608E920, r2);
    ST16(0x0608E91E, 0);
    ST8(0x0608E920, r2);
    return 0xFFEF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06067730(int r4, int r5)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD32(0x060896A4);
    r5 = ((r5 & 255) + (r5 & 255)) + r1;
    r1 = LD16(r5);
    ST16(r4, (r1 & 0xFF00));
    r1 = LD16(r5);
    ST8((r4 + 2), r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06067758(int r4, int r5)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD32(0x060896B4);
    r1 = LD16((((r5 & 255) + (r5 & 255)) + r1));
    ST16(r4, r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06067774(int r4, int r5)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD32(0x060896B0);
    r5 = (r5 & 255) + (r5 & 255);
    r1 = LD16((r1 + r5));
    ST8(r4, ((int)((unsigned)r1 >> 8)));
    r1 = LD32(0x060896B0);
    r1 = LD16((r5 + r1));
    ST8((r4 + 1), r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606779C(int r4, int r5)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD32(0x060896A8);
    r1 = LD16(r1);
    ST16(r4, r1);
    r1 = LD32(0x060896A8);
    r1 = LD16((r1 + 2));
    ST16(r5, r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060677B8(int r4)
{
    int r1, r2;
    FRAME(sp, 4);

    r2 = LD32(0x060896AC);
    r1 = LD16(r2);
    ST16(r4, r1);
    r1 = LD16((r2 + 2));
    ST16((r4 + 2), r1);
    r1 = LD16((r2 + 4));
    ST16((r4 + 4), r1);
    r1 = LD16((r2 + 6));
    ST16((r4 + 6), r1);
    r1 = LD16((r2 + 8));
    ST16((r4 + 8), r1);
    r1 = LD16((r2 + 10));
    ST16((r4 + 10), r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06069E98(int r4)
{
    int r0;
    FRAME(sp, 4);

    r0 = LD32(((r4 << 2) + 0x0608F030));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606B84C(int r4)
{
    int r2, r3;
    FRAME(sp, 4);

    r2 = LD32(0x0608F444);
    r2 = r2 + 184;
    r3 = LD32(r2);
    r2 = r2 + 4;
    ST32(r4, r3);
    r4 = r4 + 4;
    r3 = LD32(r2);
    ST32(r4, r3);
    r2 = LD32((r2 + 4));
    ST32(r4 + 4, r2);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B964(void)
{
    FRAME(sp, 4);

    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606B970(void)
{
    int r1, r2;
    FRAME(sp, 4);

    r1 = LD32(0x0608F444);
    r2 = r1 + 4;
    ST32(r2, 0x0606DB98);
    ST32(r2 + 4, 0x0606DCEC);
    ST32(r1 + 12, 0x0606DDEC);
    ST32(r1 + 16, 0x0606DDD4);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606BAF8(int r4)
{
    FRAME(sp, 4);

    ST32(r4, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C204(int r4)
{
    int r0;
    FRAME(sp, 4);

    r0 = LD32((r4 + 88));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C2D8(void)
{
    FRAME(sp, 4);

    return 0x25818000;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C2E8(void)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD16(0x25890008);
    return r1 & 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606C32C(int r4)
{
    FRAME(sp, 4);

    ST16(0x25890008, r4);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606C364(int r4)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD16(0x06089738);
    ST16(0x06089738, (r1 | r4));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C378(void)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD16(0x2589000C);
    return r1 & 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606C53C(int r4)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD16(r4);
    ST16(0x25890018, r1);
    r1 = LD16((r4 + 2));
    ST16(0x2589001C, r1);
    r1 = LD16((r4 + 4));
    ST16(0x25890020, r1);
    r1 = LD16((r4 + 6));
    ST16(0x25890024, r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606C578(int r4)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD16(0x25890018);
    ST16(r4, r1);
    r1 = LD16(0x2589001C);
    ST16((r4 + 2), r1);
    r1 = LD16(0x25890020);
    ST16((r4 + 4), r1);
    r1 = LD16(0x25890024);
    ST16((r4 + 6), r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C6BC(int r4, int r5)
{
    int r0;

    ST32(-256, r5);
    ST32(-240, ((short)((r4 << 16) | (int)((unsigned)r4 >> 16))));
    ST32(-236, (r4 << 16));
    r0 = LD32(-236);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C740(int r4)
{
    int r0, r2, r14;

    r14 = 0;
    if (!(r4 >= 0)) {
        r14 = 1;
        r4 = -r4;
    }
    r2 = 0x00B40000;
    if (!(r4 >= 0x00B40000)) {
        if (r4 > 0x005A0000) {
            r4 = r2 - r4;
        }
    } else {
        r4 = 0;
    }
    r0 = GCALL1(0x0606C7E2, r4);
    if (!((r14 & r14) == 0)) {
        r0 = -r0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C78C(int r4)
{
    int r0, r14;

    if (!(r4 >= 0)) {
        r4 = -r4;
    }
    r14 = 1;
    if (!(r4 >= 0x00B40000)) {
        if (!(r4 > 0x005A0000)) {
            r14 = 0;
        } else {
            r4 = 0x00B40000 - r4;
        }
    } else {
        r4 = 0;
    }
    r0 = GCALL1(0x0606C7DC, r4);
    if (!((r14 & r14) == 0)) {
        r0 = -r0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606CD9A(int r4, int r5, int r6)
{
    int r0;

    if (r6 > 0) {
        do {
            r0 = LD16(r5);
            r5 = r5 + 2;
            ST16(r4, r0);
            r6 = r6 - 1;
            r4 = r4 + 2;
        } while (AGAIN(!(r6 == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606CDAC(int r4)
{
    int r0, r1, r5, r6, r7;

    r1 = LD32(0x0608F008);
    if (r4 >= r1) {
        r4 = r1 - 1;
    }
    r5 = 0x0608F01C;
    r6 = LD32(0x0608EFEC);
    r6 = r6 + (r4 << 2);
    r0 = LD16(r6);
    if (!(((short)r0) == -1)) {
        r0 = LD16(r6 + 2);
        r7 = LD32(0x0608EFD8);
        r7 = r7 + ((((r0 & 0xFFFF) << 2) << 2) << 1);
        r0 = LD32(r5);
        ST16(r7 + 2, r0);
    } else {
        r0 = LD32(r5);
        ST16(r6, r0);
    }
    ST16(r6 + 2, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D144(int r4, int r5)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r1 = SR();
    r2 = (int)((unsigned)((int)((unsigned)(r1 & 240) >> 2)) >> 2);
    r1 = SR();
    SETSR((r1 | 240));
    r0 = r5;
    r1 = LD8(r0 + 0x06089758);
    ST32(r4, (r1 & 255));
    r1 = SR();
    SETSR(((r1 & -241) | ((r2 << 2) << 2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D2D4(void)
{
    int r0, r2;

    r0 = 0;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D2DA(void)
{
    int r0, r2;

    r0 = 4;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D2E0(void)
{
    int r0, r2;

    r0 = 8;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D2E6(void)
{
    int r0, r2;

    r0 = 12;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D2EC(void)
{
    int r0, r2;

    r0 = 16;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D2F8(void)
{
    int r0, r2;

    r0 = 24;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D2FE(void)
{
    int r0, r2;

    r0 = 28;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D304(void)
{
    int r0, r2;

    r0 = 32;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D30A(void)
{
    int r0, r2;

    r0 = 36;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D310(void)
{
    int r0, r2;

    r0 = 40;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D316(void)
{
    int r0, r2;

    r0 = 44;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D31C(void)
{
    int r0, r2;

    r0 = 48;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D322(void)
{
    int r0, r2;

    r0 = 52;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D328(void)
{
    int r0, r2;

    r0 = 56;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D32E(void)
{
    int r0, r2;

    r0 = 60;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D334(void)
{
    int r0, r2;

    r0 = 64;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D33A(void)
{
    int r0, r2;

    r0 = 68;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D340(void)
{
    int r0, r2;

    r0 = 72;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D346(void)
{
    int r0, r2;

    r0 = 76;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D34C(void)
{
    int r0, r2;

    r0 = 80;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D352(void)
{
    int r0, r2;

    r0 = 84;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D358(void)
{
    int r0, r2;

    r0 = 88;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D35E(void)
{
    int r0, r2;

    r0 = 92;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D364(void)
{
    int r0, r2;

    r0 = 96;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D36A(void)
{
    int r0, r2;

    r0 = 100;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D370(void)
{
    int r0, r2;

    r0 = 104;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D376(void)
{
    int r0, r2;

    r0 = 108;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D37C(void)
{
    int r0, r2;

    r0 = 112;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D382(void)
{
    int r0, r2;

    r0 = 116;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D388(void)
{
    int r0, r2;

    r0 = 120;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D38E(void)
{
    int r0, r2;

    r0 = 124;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D394(void)
{
    int r0, r2;

    r0 = 128;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D39A(void)
{
    int r0, r2;

    r0 = 132;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3A0(void)
{
    int r0, r2;

    r0 = 136;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3A6(void)
{
    int r0, r2;

    r0 = 140;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3AC(void)
{
    int r0, r2;

    r0 = 144;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3B2(void)
{
    int r0, r2;

    r0 = 148;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3B8(void)
{
    int r0, r2;

    r0 = 152;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3BE(void)
{
    int r0, r2;

    r0 = 156;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3C4(void)
{
    int r0, r2;

    r0 = 160;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3CA(void)
{
    int r0, r2;

    r0 = 164;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3D0(void)
{
    int r0, r2;

    r0 = 168;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3D6(void)
{
    int r0, r2;

    r0 = 172;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3DC(void)
{
    int r0, r2;

    r0 = 176;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3E2(void)
{
    int r0, r2;

    r0 = 180;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3E8(void)
{
    int r0, r2;

    r0 = 184;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3EE(void)
{
    int r0, r2;

    r0 = 188;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3F4(void)
{
    int r0, r2;

    r0 = 192;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D3FA(void)
{
    int r0, r2;

    r0 = 196;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D400(void)
{
    int r0, r2;

    r0 = 200;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D406(void)
{
    int r0, r2;

    r0 = 204;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D40C(void)
{
    int r0, r2;

    r0 = 208;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D412(void)
{
    int r0, r2;

    r0 = 212;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D418(void)
{
    int r0, r2;

    r0 = 216;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D41E(void)
{
    int r0, r2;

    r0 = 220;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D424(void)
{
    int r0, r2;

    r0 = 224;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D42A(void)
{
    int r0, r2;

    r0 = 228;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D430(void)
{
    int r0, r2;

    r0 = 232;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D436(void)
{
    int r0, r2;

    r0 = 236;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D43C(void)
{
    int r0, r2;

    r0 = 240;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D442(void)
{
    int r0, r2;

    r0 = 244;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D448(void)
{
    int r0, r2;

    r0 = 248;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D44E(void)
{
    int r0, r2;

    r0 = 252;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D454(void)
{
    int r0, r2;

    r0 = 0x100;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D45A(void)
{
    int r0, r2;

    r0 = 0x104;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D460(void)
{
    int r0, r2;

    r0 = 0x108;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D466(void)
{
    int r0, r2;

    r0 = 0x10C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D46C(void)
{
    int r0, r2;

    r0 = 0x110;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D472(void)
{
    int r0, r2;

    r0 = 0x114;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D478(void)
{
    int r0, r2;

    r0 = 0x118;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D47E(void)
{
    int r0, r2;

    r0 = 0x11C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D484(void)
{
    int r0, r2;

    r0 = 0x120;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D48A(void)
{
    int r0, r2;

    r0 = 0x124;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D490(void)
{
    int r0, r2;

    r0 = 0x128;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D496(void)
{
    int r0, r2;

    r0 = 0x12C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D49C(void)
{
    int r0, r2;

    r0 = 0x130;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4A2(void)
{
    int r0, r2;

    r0 = 0x134;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4A8(void)
{
    int r0, r2;

    r0 = 0x138;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4AE(void)
{
    int r0, r2;

    r0 = 0x13C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4B4(void)
{
    int r0, r2;

    r0 = 0x140;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4BA(void)
{
    int r0, r2;

    r0 = 0x144;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4C0(void)
{
    int r0, r2;

    r0 = 0x148;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4C6(void)
{
    int r0, r2;

    r0 = 0x14C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4CC(void)
{
    int r0, r2;

    r0 = 0x150;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4D2(void)
{
    int r0, r2;

    r0 = 0x154;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4D8(void)
{
    int r0, r2;

    r0 = 0x158;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4DE(void)
{
    int r0, r2;

    r0 = 0x15C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4E4(void)
{
    int r0, r2;

    r0 = 0x160;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4EA(void)
{
    int r0, r2;

    r0 = 0x164;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4F0(void)
{
    int r0, r2;

    r0 = 0x168;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4F6(void)
{
    int r0, r2;

    r0 = 0x16C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D4FC(void)
{
    int r0, r2;

    r0 = 0x170;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D502(void)
{
    int r0, r2;

    r0 = 0x174;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D508(void)
{
    int r0, r2;

    r0 = 0x178;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D50E(void)
{
    int r0, r2;

    r0 = 0x17C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D514(void)
{
    int r0, r2;

    r0 = 0x180;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D51A(void)
{
    int r0, r2;

    r0 = 0x184;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D520(void)
{
    int r0, r2;

    r0 = 0x188;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D526(void)
{
    int r0, r2;

    r0 = 0x18C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D52C(void)
{
    int r0, r2;

    r0 = 0x190;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D532(void)
{
    int r0, r2;

    r0 = 0x194;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D538(void)
{
    int r0, r2;

    r0 = 0x198;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D53E(void)
{
    int r0, r2;

    r0 = 0x19C;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D544(void)
{
    int r0, r2;

    r0 = 0x1A0;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D54A(void)
{
    int r0, r2;

    r0 = 0x1A4;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D550(void)
{
    int r0, r2;

    r0 = 0x1A8;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D556(void)
{
    int r0, r2;

    r0 = 0x1AC;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D55C(void)
{
    int r0, r2;

    r0 = 0x1B0;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D562(void)
{
    int r0, r2;

    r0 = 0x1B4;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D568(void)
{
    int r0, r2;

    r0 = 0x1B8;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D56E(void)
{
    int r0, r2;

    r0 = 0x1BC;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D574(void)
{
    int r0, r2;

    r0 = 0x1C0;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D57A(void)
{
    int r0, r2;

    r0 = 0x1C4;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D580(void)
{
    int r0, r2;

    r0 = 0x1C8;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D586(void)
{
    int r0, r2;

    r0 = 0x1CC;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D58C(void)
{
    int r0, r2;

    r0 = 0x1D0;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D592(void)
{
    int r0, r2;

    r0 = 0x1D4;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D598(void)
{
    int r0, r2;

    r0 = 0x1D8;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D59E(void)
{
    int r0, r2;

    r0 = 0x1DC;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5A4(void)
{
    int r0, r2;

    r0 = 0x1E0;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5AA(void)
{
    int r0, r2;

    r0 = 0x1E4;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5B0(void)
{
    int r0, r2;

    r0 = 0x1E8;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5B6(void)
{
    int r0, r2;

    r0 = 0x1EC;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5BC(void)
{
    int r0, r2;

    r0 = 0x1F0;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5C2(void)
{
    int r0, r2;

    r0 = 0x1F4;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5C8(void)
{
    int r0, r2;

    r0 = 0x1F8;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5CE(void)
{
    int r0, r2;

    r0 = 0x1FC;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5D4(void)
{
    int r0, r2;

    r0 = -512;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5DA(void)
{
    int r0, r2;

    r0 = -508;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5E0(void)
{
    int r0, r2;

    r0 = -504;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5E6(void)
{
    int r0, r2;

    r0 = -500;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5EC(void)
{
    int r0, r2;

    r0 = -496;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5F2(void)
{
    int r0, r2;

    r0 = -492;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5F8(void)
{
    int r0, r2;

    r0 = -488;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D5FE(void)
{
    int r0, r2;

    r0 = -484;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D604(void)
{
    int r0, r2;

    r0 = -480;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D60A(void)
{
    int r0, r2;

    r0 = -476;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D610(void)
{
    int r0, r2;

    r0 = -472;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D616(void)
{
    int r0, r2;

    r0 = -468;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D61C(void)
{
    int r0, r2;

    r0 = -464;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D622(void)
{
    int r0, r2;

    r0 = -460;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D628(void)
{
    int r0, r2;

    r0 = -456;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D62E(void)
{
    int r0, r2;

    r0 = -452;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D634(void)
{
    int r0, r2;

    r0 = -448;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D63A(void)
{
    int r0, r2;

    r0 = -444;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D640(void)
{
    int r0, r2;

    r0 = -440;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D646(void)
{
    int r0, r2;

    r0 = -436;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D64C(void)
{
    int r0, r2;

    r0 = -432;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D652(void)
{
    int r0, r2;

    r0 = -428;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D658(void)
{
    int r0, r2;

    r0 = -424;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D65E(void)
{
    int r0, r2;

    r0 = -420;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D664(void)
{
    int r0, r2;

    r0 = -416;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D66A(void)
{
    int r0, r2;

    r0 = -412;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D670(void)
{
    int r0, r2;

    r0 = -408;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D676(void)
{
    int r0, r2;

    r0 = -404;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D67C(void)
{
    int r0, r2;

    r0 = -400;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D682(void)
{
    int r0, r2;

    r0 = -396;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D688(void)
{
    int r0, r2;

    r0 = -392;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D69A(void)
{
    int r0, r2;

    r0 = -380;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6A0(void)
{
    int r0, r2;

    r0 = -376;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6A6(void)
{
    int r0, r2;

    r0 = -372;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6AC(void)
{
    int r0, r2;

    r0 = -368;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6B2(void)
{
    int r0, r2;

    r0 = -364;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6B8(void)
{
    int r0, r2;

    r0 = -360;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6BE(void)
{
    int r0, r2;

    r0 = -356;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6C4(void)
{
    int r0, r2;

    r0 = -352;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6CA(void)
{
    int r0, r2;

    r0 = -348;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6D0(void)
{
    int r0, r2;

    r0 = -344;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6D6(void)
{
    int r0, r2;

    r0 = -340;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6DC(void)
{
    int r0, r2;

    r0 = -336;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6E2(void)
{
    int r0, r2;

    r0 = -332;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6E8(void)
{
    int r0, r2;

    r0 = -328;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6EE(void)
{
    int r0, r2;

    r0 = -324;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6F4(void)
{
    int r0, r2;

    r0 = -320;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D6FA(void)
{
    int r0, r2;

    r0 = -316;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D700(void)
{
    int r0, r2;

    r0 = -312;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D706(void)
{
    int r0, r2;

    r0 = -308;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D70C(void)
{
    int r0, r2;

    r0 = -304;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D712(void)
{
    int r0, r2;

    r0 = -300;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D718(void)
{
    int r0, r2;

    r0 = -296;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D71E(void)
{
    int r0, r2;

    r0 = -292;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D724(void)
{
    int r0, r2;

    r0 = -288;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D72A(void)
{
    int r0, r2;

    r0 = -284;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D730(void)
{
    int r0, r2;

    r0 = -280;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D736(void)
{
    int r0, r2;

    r0 = -276;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D73C(void)
{
    int r0, r2;

    r0 = -272;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D742(void)
{
    int r0, r2;

    r0 = -268;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D748(void)
{
    int r0, r2;

    r0 = -264;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D74E(void)
{
    int r0, r2;

    r0 = -260;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D754(void)
{
    int r0, r2;

    r0 = -256;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D75A(void)
{
    int r0, r2;

    r0 = -252;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D760(void)
{
    int r0, r2;

    r0 = -248;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D766(void)
{
    int r0, r2;

    r0 = -244;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D76C(void)
{
    int r0, r2;

    r0 = -240;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D772(void)
{
    int r0, r2;

    r0 = -236;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D778(void)
{
    int r0, r2;

    r0 = -232;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D77E(void)
{
    int r0, r2;

    r0 = -228;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D784(void)
{
    int r0, r2;

    r0 = -224;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D78A(void)
{
    int r0, r2;

    r0 = -220;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D790(void)
{
    int r0, r2;

    r0 = -216;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D796(void)
{
    int r0, r2;

    r0 = -212;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D79C(void)
{
    int r0, r2;

    r0 = -208;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7A2(void)
{
    int r0, r2;

    r0 = -204;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7A8(void)
{
    int r0, r2;

    r0 = -200;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7AE(void)
{
    int r0, r2;

    r0 = -196;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7B4(void)
{
    int r0, r2;

    r0 = -192;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7BA(void)
{
    int r0, r2;

    r0 = -188;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7C0(void)
{
    int r0, r2;

    r0 = -184;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7C6(void)
{
    int r0, r2;

    r0 = -180;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7CC(void)
{
    int r0, r2;

    r0 = -176;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7D2(void)
{
    int r0, r2;

    r0 = -172;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7D8(void)
{
    int r0, r2;

    r0 = -168;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7DE(void)
{
    int r0, r2;

    r0 = -164;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7E4(void)
{
    int r0, r2;

    r0 = -160;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7EA(void)
{
    int r0, r2;

    r0 = -156;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7F0(void)
{
    int r0, r2;

    r0 = -152;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7F6(void)
{
    int r0, r2;

    r0 = -148;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D7FC(void)
{
    int r0, r2;

    r0 = -144;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D802(void)
{
    int r0, r2;

    r0 = -140;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D808(void)
{
    int r0, r2;

    r0 = -136;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D80E(void)
{
    int r0, r2;

    r0 = -132;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D814(void)
{
    int r0, r2;

    r0 = -128;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D81A(void)
{
    int r0, r2;

    r0 = -124;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D820(void)
{
    int r0, r2;

    r0 = -120;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D826(void)
{
    int r0, r2;

    r0 = -116;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D82C(void)
{
    int r0, r2;

    r0 = -112;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D832(void)
{
    int r0, r2;

    r0 = -108;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D838(void)
{
    int r0, r2;

    r0 = -104;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D83E(void)
{
    int r0, r2;

    r0 = -100;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D844(void)
{
    int r0, r2;

    r0 = -96;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D84A(void)
{
    int r0, r2;

    r0 = -92;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D850(void)
{
    int r0, r2;

    r0 = -88;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D856(void)
{
    int r0, r2;

    r0 = -84;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D85C(void)
{
    int r0, r2;

    r0 = -80;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D862(void)
{
    int r0, r2;

    r0 = -76;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D868(void)
{
    int r0, r2;

    r0 = -72;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D86E(void)
{
    int r0, r2;

    r0 = -68;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D874(void)
{
    int r0, r2;

    r0 = -64;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D87A(void)
{
    int r0, r2;

    r0 = -60;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D880(void)
{
    int r0, r2;

    r0 = -56;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D886(void)
{
    int r0, r2;

    r0 = -52;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D88C(void)
{
    int r0, r2;

    r0 = -48;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D892(void)
{
    int r0, r2;

    r0 = -44;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D898(void)
{
    int r0, r2;

    r0 = -40;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D89E(void)
{
    int r0, r2;

    r0 = -36;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D8A4(void)
{
    int r0, r2;

    r0 = -32;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D8AA(void)
{
    int r0, r2;

    r0 = -28;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D8B0(void)
{
    int r0, r2;

    r0 = -24;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D8B6(void)
{
    int r0, r2;

    r0 = -20;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D8BC(void)
{
    int r0, r2;

    r0 = -16;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D8C2(void)
{
    int r0, r2;

    r0 = -12;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D8C8(void)
{
    int r0, r2;

    r0 = -8;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D8CE(void)
{
    int r0, r2;

    r0 = -4;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E2A0(int r4, int r5)
{
    FRAME(sp, 4);

    return r5 + (((r4 + r4) + r4) << 2);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E2B4(int r4, int r5)
{
    FRAME(sp, 4);

    return r5 + (r4 * 24);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E2C8(int r4, int r5)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD8((((((r4 + r4) + r4) << 2) + r5) + 11));
    return r1 & 255;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E2E0(int r4, int r5)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD8((((r4 * 24) + r5) + 11));
    return r1 & 255;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606E4B4(int r4, int r5)
{
    int r1;
    FRAME(sp, 4);

    ST32(r4, r5);
    r1 = LD32(0x0608F444);
    ST32(r4 + 4, (r1 + 0x460));
    ST32(r4 + 8, -1);
    r5 = LD32(r5 + 32);
    ST32(r4 + 16, r5);
    ST32(r4 + 12, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606EAB8(int r4, int r5)
{
    int r1, r3;
    FRAME(sp, 4);

    r3 = LD32(r5);
    ST32(r4, r3);
    r3 = LD32(r5 + 4);
    ST32(r4 + 4, r3);
    r1 = LD8((r5 + 25));
    ST8((r4 + 10), r1);
    r1 = LD8((r5 + 9));
    ST8((r4 + 11), r1);
    r1 = LD8((r5 + 10));
    ST8((r4 + 8), r1);
    r1 = LD8((r5 + 11));
    ST8((r4 + 9), r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606EB68(int r4, int r5)
{
    int r0;
    FRAME(sp, 4);

    ST32(r4 + 36, 0);
    ST32(r4 + 40, 0);
    r0 = LD32(r4 + 56);
    ST32(r4 + 56, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606EB7C(int r4, int r5)
{
    FRAME(sp, 4);

    ST32(r4 + 44, r5);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606EBBC(int r4)
{
    int r0;
    FRAME(sp, 4);

    r0 = LD32(r4 + 24);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606EBC8(int r4)
{
    int r0;
    FRAME(sp, 4);

    r0 = LD32(r4 + 28);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606EBD4(int r4, int r5)
{
    int r0;
    FRAME(sp, 4);

    r0 = LD32(r4 + 20);
    ST32(r4 + 20, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606EBE0(int r4)
{
    FRAME(sp, 4);

    ST32(r4 + 48, 1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606EBEC(int r4)
{
    FRAME(sp, 4);

    ST32(r4 + 48, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606EF98(void)
{
    FRAME(sp, 4);

    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F074(void)
{
    FRAME(sp, 4);

    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F250(void)
{
    FRAME(sp, 4);

    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F29C(void)
{
    FRAME(sp, 4);

    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F48C(int r4)
{
    int r0;
    FRAME(sp, 4);

    r0 = LD32(r4 + 8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F498(int r4)
{
    int r1, r2;
    FRAME(sp, 4);

    r2 = LD32(r4 + 4);
    r1 = LD32(r4 + 44);
    r2 = r2 * r1;
    r1 = LD32(r4 + 8);
    return r2 - r1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606F500(int r4, int r5, int r6, int r7)
{
    int r1;
    FRAME(sp, 4);

    r1 = LD32(r4);
    ST32(r5, r1);
    r1 = LD32(r4 + 4);
    ST32(r6, r1);
    r4 = LD32(r4 + 44);
    ST32(r7, r4);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606F514(int r4, int r5, int r6, int r7)
{
    FRAME(sp, 4);

    ST32(r4, r5);
    ST32(r4 + 4, r6);
    ST32(r4 + 44, r7);
    ST32(r4 + 8, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606F528(int r4, int r5, int r6)
{
    FRAME(sp, 4);

    r4 = r4 + 108;
    ST32(r4 + 36, r6);
    ST32(r4 + 40, r5);
    ST32(r4 + 56, 4);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F638(void)
{
    FRAME(sp, 4);

    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F838(void)
{
    FRAME(sp, 4);

    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F8D4(int r4)
{
    int r1, r2;
    FRAME(sp, 4);

    r2 = LD32(r4 + 32);
    r1 = LD32(r4 + 36);
    return r2 + r1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FB48(void)
{
    FRAME(sp, 4);

    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060603D0(int r4, int r5, int r6)
{
    int r1, r2, c2;

    if (!(r6 > 0)) {
        return 0;
    } else {
        while (1) {
            r1 = LD8(r4);
            r4 = r4 + 1;
            r2 = r1 & 255;
            r1 = LD8(r5);
            r5 = r5 + 1;
            r1 = r1 & 255;
            c2 = (unsigned)r1 >= (unsigned)r2;
            if ((unsigned)r2 >= (unsigned)r1) {
                r6 = r6 - 1;
                if (c2) {
                    if (r6 > 0) {
                        POLL();
                        continue;
                    } else {
                        return 0;
                    }
                } else {
                    return 1;
                }
            } else {
                return -1;
            }
            POLL();
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060688(int r4, int r5)
{
    int r0, r1, r2, r6;

    r2 = r5;
    r1 = LD8((r2 + 2));
    r4 = r4 + r1;
    r1 = LD8((r2 + 3));
    if ((r1 & r1) == 0) {
        r6 = LD8((r2 + 1));
        if ((r6 & r6) == 0) {
            r6 = 1;
        }
        r5 = LD32(r2 + 4);
        r0 = GCALL3(0x0604B358, r4, r5, r6);
        return r0;
    } else {
        r1 = LD32(r2 + 4);
        r1 = LD32(r1);
        r0 = GCALL2(r1, r2, r4);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060606CC(int r4, int r5)
{
    int r0, r1, r2, r6;

    r1 = LD8((r4 + 2));
    r2 = r5 + r1;
    r1 = LD8((r4 + 3));
    if ((r1 & r1) == 0) {
        r6 = LD8((r4 + 1));
        if ((r6 & r6) == 0) {
            r6 = 1;
        }
        r5 = LD32(r4 + 4);
        r0 = GCALL3(0x0604B358, r2, r5, r6);
        return r0;
    } else {
        r1 = LD32(r4 + 4);
        r1 = LD32(r1 + 4);
        r0 = GCALL2(r1, r4, r2);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606079C(int r4, int r5)
{
    int r0, r1, r3, r6, r7, r8, r9;

    r1 = LD8((r5 + 3));
    if ((r1 & r1) == 0) {
        r0 = 0;
        r8 = 0;
        r9 = 0;
        r6 = LD8((r5 + 1));
        r4 = r4 + 2;
        r1 = LD32(r5 + 4);
        r3 = r1 + (r6 + r6);
        r7 = r3 + r6;
        do {
            r1 = LD8(r4);
            r4 = r4 + 1;
            r6 = r6 - 1;
            r0 = (r0 << 8) | (r1 & 255);
            r1 = LD8(r7);
            r7 = r7 + 1;
            r8 = (r8 << 8) | (r1 & 255);
            r1 = LD8(r3);
            r3 = r3 + 1;
            r9 = (r9 << 8) | (r1 & 255);
        } while (AGAIN(r6 > 0));
        r1 = 0;
        if (!((unsigned)r0 > (unsigned)r8)) {
            if ((unsigned)r0 >= (unsigned)r9) {
                r1 = 1;
            }
        }
        r0 = r1;
    } else {
        r1 = LD32(r5 + 4);
        r0 = LD32(r1 + 20);
        r0 = GCALL2(r0, r4, r5);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060608E4(int r4, int r5)
{
    int r0, r1, r6;

    r1 = LD8((r5 + 3));
    if ((r1 & r1) == 0) {
        r6 = LD8((r5 + 1));
        if ((r6 & r6) == 0) {
            r6 = 1;
        }
        r5 = LD32(r5 + 4);
        r0 = GCALL3(0x060603D0, r4, r5, r6);
        return (r0 & r0) == 0;
    } else {
        r1 = LD32(r5 + 4);
        r0 = LD32(r1 + 24);
        r0 = GCALL2(r0, r4, r5);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606094C(int r4, int r5)
{
    int r0, r1, r2, r6;

    r1 = LD8((r4 + 2));
    r2 = r5 + r1;
    r1 = LD8((r4 + 3));
    if ((r1 & r1) == 0) {
        r6 = LD8((r4 + 1));
        if ((r6 & r6) == 0) {
            r6 = 1;
        }
        r5 = LD32(r4 + 4);
        r0 = GCALL3(0x0604B358, r2, (r5 + r6), r6);
        return r0;
    } else {
        r1 = LD32(r4 + 4);
        r1 = LD32(r1 + 36);
        r0 = GCALL2(r1, r2, r4);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06061298(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, c3;
    int v20;

    r8 = r4;
    r10 = LD32(0x0608D388);
    r1 = LD16((r8 + 4));
    r0 = GCALL1(0x06052980, (r8 + r1));
    r0 = GCALL4(0x06052DD4, r8, r5, r6, r7);
    r8 = r0;
    r1 = r8;
    if (!((r8 & r8) == 0)) {
        r1 = LD16((r1 + 4));
        r9 = r8 + r1;
        r0 = GCALL2(0x06052254, 0, r8);
        r1 = LD8((r9 + 9));
        r0 = r1 & 255;
        r1 = 6;
        if (r0 == 6) {
            r2 = LD32(0x0608D8E8);
            ST32(0x0608D8E8, (r2 + 1));
            r0 = GCALL1(0x06056704, r8);
            r0 = 1;
            r1 = LD32(0x0608D94C);
            ST32(0x0608D94C, (r1 + 1));
        } else {
            c3 = r0 == 1;
            if (r0 > r1) {
                r5 = r8;
                if (!(r0 == 17)) {
                    r1 = LD32(0x0608D8D8);
                    ST32(0x0608D8D8, (r1 + 1));
                    r0 = GCALL5(0x0605DEA4, 3, 2, (r9 + 12), r8, 0);
                    r0 = 1;
                } else {
                    r0 = 0x06061AEC;
                    r0 = GCALL2(r0, r10, r5);
                    r1 = LD32(0x0608D94C);
                    ST32(0x0608D94C, (r1 + 1));
                }
            } else {
                r5 = r8;
                if (c3) {
                    r0 = 0x06061CB4;
                    r0 = GCALL2(r0, r10, r5);
                    r1 = LD32(0x0608D94C);
                    ST32(0x0608D94C, (r1 + 1));
                } else {
                    r1 = LD32(0x0608D8D8);
                    ST32(0x0608D8D8, (r1 + 1));
                    r0 = GCALL5(0x0605DEA4, 3, 2, (r9 + 12), r8, 0);
                    r0 = 1;
                }
            }
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060618E8(int r4, int r5)
{
    int r0, r1, r2, r3;

    r1 = LD8(r5);
    r5 = r5 + 1;
    ST8(r4, r1);
    r2 = LD8(r5);
    r5 = r5 + 1;
    r1 = r4 + 1;
    ST8(r1, r2);
    r2 = LD8(r5);
    r1 = r1 + 1;
    ST8(r1, r2);
    r2 = LD8((r5 + 1));
    ST8((r1 + 1), r2);
    r3 = LD8(r4);
    r0 = 4;
    if (((128 & r3) & (128 & r3)) == 0) {
        r0 = 1;
    }
    if ((192 & r3) == 128) {
        r0 = 2;
    }
    if ((224 & r3) == 192) {
        r0 = 3;
    }
    r1 = 3;
    r2 = 0;
    if (!(r0 > 3)) {
        do {
            ST8(r0 + r4, r2);
            r0 = r0 + 1;
        } while (AGAIN(!(r0 > r1)));
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06061940(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c2;

    r9 = r4;
    r11 = r5;
    ST8(r9, 2);
    r1 = LD32(r9 + 16);
    r10 = r6;
    r8 = LD32(r9 + 20);
    ST32(r9 + 16, (r1 + 1));
    if (!((r8 & r8) == 0)) {
        c2 = (r8 & r8) == 0;
        if (!((r10 & r10) == 0)) {
            if (!(c2)) {
                do {
                    r4 = LD32(r8);
                    r0 = GCALL1(r10, r4);
                    r8 = LD32(r8 + 4);
                } while (AGAIN(!((r8 & r8) == 0)));
            }
        }
        r3 = LD32(r9 + 24);
        r1 = LD32(0x0608D9DC);
        ST32(r3 + 4, r1);
        r1 = LD32(r9 + 20);
        ST32(0x0608D9DC, r1);
    }
    r0 = r11;
    r2 = 0;
    if (r0 == 3) {
        ST32(r9 + 20, r2);
        ST32(r9 + 24, r2);
        r1 = LD32(r9 + 12);
        ST32(r9 + 8, r2);
        ST32(r9 + 4, r1);
    }
    ST8(r9, r11);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06061F44(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, c2;

    r8 = r6;
    r0 = 0;
    r3 = 3;
    while (1) {
        r1 = LD8(r0 + r8);
        r2 = LD8(r0 + r4);
        r2 = r2 & r1;
        r1 = LD8(r0 + r5);
        r0 = r0 + 1;
        if (!(r2 == r1)) {
            r0 = 0;
            break;
        } else {
            c2 = (r7 & r7) == 0;
            if (!(r0 > r3)) {
                POLL();
                continue;
            } else {
                r0 = 1;
                if (c2) {
                    break;
                } else {
                    r0 = GCALL1(0x06053108, r4);
                    r6 = 4;
                    if ((r0 & r0) == 0) {
                        r0 = 1;
                        break;
                    } else {
                        r0 = GCALL3(0x060752CC, r8, 0x06053104, r6);
                        r0 = ((r0 & r0) == 0) ^ 1;
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
int f060621C4(int r4)
{
    int r0, r1, r2, r3, r6, r7, c4;
    FRAME(sp, 4);

    r7 = r4;
    r3 = r7 & 0xFFFF;
    if (!(r3 == 0xFFFF)) {
        r0 = r4;
        if (!(r3 == 0xFFFE)) {
            r6 = 0;
            if (((((int)((unsigned)(((int)((unsigned)r0 >> 8)) + ((int)((unsigned)r0 >> 8))) >> 8)) & 1) & (((int)((unsigned)(((int)((unsigned)r0 >> 8)) + ((int)((unsigned)r0 >> 8))) >> 8)) & 1)) == 0) {
                r1 = 0x06079FB8;
                r6 = 1;
            } else {
                r1 = 0x06079FB8;
            }
            ST32(r1, r6);
            r7 = r7 & 0x7FFF;
            r0 = r7 & 0xFFFF;
            c4 = r0 == 1;
            if ((r0 & r0) == 0) {
                ST16(0x06079FB4, 0);
            } else {
                r1 = 1;
                if (c4) {
                    ST16(0x06079FB4, 0);
                } else {
                    ST16(0x06079FB4, r1);
                }
            }
            ST32(0x06079FBC, (r7 & 0xFFFF));
            r1 = LD16(0x06079FB4);
            if (!(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0)) {
                r0 = LD16(0x0608F434);
                r0 = r0 | 3;
                ST16(0x25D00002, r0);
            } else {
                r2 = LD16(0x0608F434);
                ST16(0x25D00002, r2);
            }
        } else {
            r2 = 0x06079FB4;
            r1 = 3;
            ST16(r2, r1);
            ST32(0x06079FB8, 0);
            r0 = LD16(0x0608F434);
            r0 = r0 | 3;
            ST16(0x25D00002, r0);
            ST32(0x06079FBC, r3);
        }
    } else {
        r2 = 0x06079FB4;
        r1 = 2;
        ST16(r2, r1);
        ST32(0x06079FB8, 0);
        r0 = LD16(0x0608F434);
        r0 = r0 | 3;
        ST16(0x25D00002, r0);
        ST32(0x06079FBC, r3);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06062280(void)
{
    int r1, r2;
    FRAME(sp, 4);

    r1 = LD32(0x06079FBC);
    if (!((r1 & r1) == 0)) {
        r2 = 0x06079FC4;
        ST32(0x06079FC4, 1);
        do {
            r1 = LD32(r2);
        } while (AGAIN(!((r1 & r1) == 0)));
        r2 = 0x06079FC8;
        do {
            r1 = LD32(r2);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06062304(void)
{
    int r0, r1, r3;
    FRAME(sp, 8);

    r1 = LD16(0x06079FB4);
    r0 = r1 & 0xFFFF;
    if (!(r0 == 1)) {
        r0 = GCALL0(0x06062C90);
    } else {
        r1 = LD32(0x06079FC0);
        ST32(0x06079FC0, (r1 + 1));
        r1 = LD32(0x06079FC0);
        r3 = LD32(0x06079FBC);
        r1 = LD32(0x06079FC0);
        if (!(r3 > r1)) {
            r0 = GCALL0(0x06062C90);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06062348(void)
{
    int r0, r1, r2, r3, r7, c1, c4, c8, c14;
    FRAME(sp, 4);

    r2 = 0x06079FB4;
    r1 = LD16(0x06079FB4);
    r0 = r1 & 0xFFFF;
    if (!(r0 == 2)) {
        r1 = LD16(r2);
        r0 = r1 & 0xFFFF;
        if (!(r0 == 3)) {
            r1 = LD16(r2);
            c4 = ((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0;
            r1 = 4;
            if (!(c4)) {
                r0 = LD32(0x06079FB8);
                if (r0 == 1) {
                    r1 = LD32(0x06079FBC);
                    r2 = LD32(0x06079FC0);
                    if (!((r1 - 1) > r2)) {
                        r0 = LD16(0x0608F434);
                        r0 = r0 | 2;
                        ST16(0x25D00002, r0);
                    }
                }
                r2 = LD32(0x06079FBC);
                r3 = 0x06079FC0;
                r1 = LD32(0x06079FC0);
                if (!(r2 > r1)) {
                    r1 = LD32(0x06079FC4);
                    c8 = (r1 & r1) == 0;
                    r1 = 1;
                    if (!(c8)) {
                        ST32(0x06089644, r1);
                    }
                    ST32(r3, 0);
                }
            } else {
                ST32(0x06089644, r1);
            }
        } else {
            r1 = LD32(0x06079FC4);
            if (!((r1 & r1) == 0)) {
                r0 = LD16(0x0608F43A);
                ST16(0x25D00000, (r0 | 8));
                r0 = LD16(0x0608F434);
                r0 = r0 | 3;
                ST16(0x25D00002, r0);
                ST32(0x06089644, 3);
            }
        }
    } else {
        r1 = LD32(0x06079FC4);
        c1 = (r1 & r1) == 0;
        r1 = 2;
        if (!(c1)) {
            ST32(0x06089644, r1);
        }
    }
    r1 = LD16(0x0608F438);
    if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
        r2 = 0x06089644;
        r1 = LD32(0x06089644);
        if (!((r1 & r1) == 0)) {
            r0 = LD32(r2);
            if (!(r0 == 2)) {
                r1 = 0x06089644;
                r0 = LD32(0x06089644);
                if (!(r0 == 3)) {
                    r0 = LD32(r1);
                    if (r0 == 1) {
                        r0 = LD16(0x0608F434);
                        r0 = r0 | 3;
                        ST16(0x25D00002, r0);
                    } else {
                        r0 = LD32(r1);
                        if (r0 == 2) {
                            r0 = LD16(0x0608F434);
                            r0 = r0 | 3;
                            ST16(0x25D00002, r0);
                        }
                    }
                } else {
                    r2 = LD16(0x0608F43A);
                    ST16(0x25D00000, r2);
                }
                r7 = 0;
                ST32(0x06089644, 0);
                r1 = 0x06079FC8;
            } else {
                r1 = LD32(0x0607A420);
                if ((r1 & r1) == 0) {
                    r1 = 0x06089644;
                    r0 = LD32(0x06089644);
                    if (!(r0 == 3)) {
                        r0 = LD32(r1);
                        if (r0 == 1) {
                            r0 = LD16(0x0608F434);
                            r0 = r0 | 3;
                            ST16(0x25D00002, r0);
                        } else {
                            r0 = LD32(r1);
                            if (r0 == 2) {
                                r0 = LD16(0x0608F434);
                                r0 = r0 | 3;
                                ST16(0x25D00002, r0);
                            }
                        }
                    } else {
                        r2 = LD16(0x0608F43A);
                        ST16(0x25D00000, r2);
                    }
                    r7 = 0;
                    ST32(0x06089644, 0);
                    r1 = 0x06079FC8;
                } else {
                    r0 = LD16(0x25D00010);
                    r0 = r0 & 2;
                    c14 = (r0 & r0) == 0;
                    r7 = c14;
                    if (!(c14)) {
                        r1 = 0x06089644;
                        r0 = LD32(0x06089644);
                        if (!(r0 == 3)) {
                            r0 = LD32(r1);
                            if (r0 == 1) {
                                r0 = LD16(0x0608F434);
                                r0 = r0 | 3;
                                ST16(0x25D00002, r0);
                            } else {
                                r0 = LD32(r1);
                                if (r0 == 2) {
                                    r0 = LD16(0x0608F434);
                                    r0 = r0 | 3;
                                    ST16(0x25D00002, r0);
                                }
                            }
                        } else {
                            r2 = LD16(0x0608F43A);
                            ST16(0x25D00000, r2);
                        }
                        r7 = 0;
                        ST32(0x06089644, 0);
                        r1 = 0x06079FC8;
                    } else {
                        r1 = 0x06079FC8;
                    }
                }
            }
            ST32(r1, r7);
            r1 = 0x06079FC4;
            r7 = 0;
            ST32(r1, r7);
        }
    } else {
        r0 = LD16(0x25F80004);
        if (((r0 & 2) & (r0 & 2)) == 0) {
            r0 = LD16(0x0608F434);
            r2 = 0x25D00002;
            r0 = r0 | 8;
        } else {
            r0 = LD16(0x0608F434);
            r2 = 0x25D00002;
            r0 = r0 | 12;
        }
        ST16(r2, r0);
        r7 = 0;
        ST32(0x06089644, 0);
        r1 = 0x06079FC4;
        ST32(r1, r7);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060624C0(void)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL0(0x060622B4);
    ST32(0x0608E718, 0);
    ST32(0x0608E71C, 0);
    ST32(0x0608E878, 0);
    ST32(0x0608E87C, 0);
    ST32(0x0608E770, 0);
    ST32(0x0608E774, 0);
    ST16(0x0608E894, 0);
    ST16(0x0608E896, 0);
    ST16(0x0608E778, 0);
    ST16(0x0608E77A, 0);
    ST32(0x0608DA00, 0);
    ST32(0x0608DA04, 0);
    ST32(0x0608E798, 0);
    ST32(0x0608E79C, 0);
    ST32(0x0608E890, 0);
    r0 = GCALL0(0x06064360);
    r0 = GCALL0(0x06062544);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06062544(void)
{
    int r0, r1, r2, r3, r6, r7;
    FRAME(sp, 4);

    ST32(0x06089648, 0x25F80000);
    ST16(0x0608E6F0, -32768);
    ST16(0x0608E6F2, 0);
    ST16(0x0608E6F6, 0);
    ST16(0x0608E6FC, 0);
    ST16(0x0608E6FE, 0x2000);
    r3 = 0;
    r6 = 7;
    r2 = 0x0608E700;
    r7 = -1;
    r1 = 0;
    do {
        r0 = r1 + r1;
        r3 = r3 + 1;
        r1 = r3 & 0xFFFF;
        ST16(r0 + r2, r7);
    } while (AGAIN(!((unsigned)r1 > (unsigned)r6)));
    ST16(0x0608E710, 0);
    ST16(0x0608E712, 0);
    ST16(0x0608E714, 0);
    ST16(0x0608E716, 0);
    ST16(0x0608E720, 0);
    ST16(0x0608E722, 0);
    ST16(0x0608E724, 0);
    ST16(0x0608E726, 0);
    ST16(0x0608E728, 0);
    ST16(0x0608E72A, 0);
    ST16(0x0608E72C, 0);
    ST16(0x0608E72E, 0);
    ST16(0x0608E730, 0);
    ST16(0x0608E732, 0);
    ST16(0x0608E734, 0);
    ST16(0x0608E736, 0);
    r3 = 0;
    r7 = 7;
    r2 = 0x0608E738;
    r1 = 0;
    do {
        r0 = r1 + r1;
        r3 = r3 + 1;
        r1 = r3 & 0xFFFF;
        ST16(r0 + r2, 0);
    } while (AGAIN(!((unsigned)r1 > (unsigned)r7)));
    r3 = 0;
    r7 = 15;
    r2 = 0x0608E748;
    r1 = 0;
    do {
        r0 = r1 + r1;
        r3 = r3 + 1;
        r1 = r3 & 0xFFFF;
        ST16(r0 + r2, 0);
    } while (AGAIN(!((unsigned)r1 > (unsigned)r7)));
    ST32(0x0608E8C0, 0);
    ST32(0x0608E8C4, 0);
    ST32(0x0608E8C8, 0x00010000);
    ST32(0x0608E8CC, 0x00010000);
    ST32(0x0608E8D0, 0);
    ST32(0x0608E8D4, 0);
    ST32(0x0608E8D8, 0x00010000);
    ST32(0x0608E8DC, 0x00010000);
    ST16(0x0608E8E0, 0);
    ST16(0x0608E8E2, 0);
    ST16(0x0608E8E4, 0);
    ST16(0x0608E8E6, 0);
    ST16(0x0608E8E8, 0);
    ST16(0x0608E8EA, 0);
    ST32(0x0608E8EC, 0);
    ST32(0x0608E8F0, 0);
    ST32(0x0608E8F4, 0);
    ST32(0x0608E8F8, 0);
    ST32(0x0608E8FC, 0);
    ST16(0x0608E780, 0);
    ST16(0x0608E782, 0);
    ST16(0x0608E784, 0);
    ST16(0x0608E786, 0);
    ST16(0x0608E788, 0);
    ST16(0x0608E78A, 0);
    ST32(0x0608E78C, 0);
    ST16(0x0608E8A0, 0);
    ST16(0x0608E8A2, 0);
    ST16(0x0608E8A4, 0);
    ST16(0x0608E8A6, 0);
    ST16(0x0608E8A8, 0);
    ST16(0x0608E8AA, 0);
    ST16(0x0608E8AC, 0);
    ST16(0x0608E8AE, 0);
    ST16(0x0608E8B0, 0);
    ST16(0x0608E8B2, 0);
    ST16(0x0608E8B4, 0);
    ST16(0x0608E8B6, 0);
    ST32(0x0608E8B8, 0);
    ST32(0x0608E8BC, 0);
    r2 = 0x06079FD8;
    r1 = LD16(0x06079FD8);
    if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
        ST16(r2, 1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06062714(int r4)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r2 = 0x06079FD8;
    r1 = LD16(0x06079FD8);
    r0 = r1 & 0xFFFF;
    if (r0 == 1) {
        ST16(r2, 0);
    }
    ST32(0x06079FD4, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06062738(void)
{
    int r1, r2;
    FRAME(sp, 4);

    r2 = 0x06079FD8;
    r1 = LD16(0x06079FD8);
    if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
        ST16(r2, 1);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06062B6C(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r8, r10;
    FRAME(sp, 20);

    r8 = 0x0608E894;
    r1 = LD16(0x0608E894);
    if (!(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0)) {
        r4 = LD32(0x0608DA00);
        if (!((r4 & r4) == 0)) {
            r6 = LD32(0x0608E888);
            r0 = GCALL3(0x06062D24, r4, 0x0608DA10, (r6 + r6));
            ST16(r8, 0);
        }
    }
    r8 = 0x0608E896;
    r1 = LD16(0x0608E896);
    if (!(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0)) {
        r4 = LD32(0x0608DA04);
        if (!((r4 & r4) == 0)) {
            r6 = LD32(0x0608E88C);
            r0 = GCALL3(0x06062D24, r4, 0x0608E078, (r6 + r6));
            ST16(r8, 0);
        }
    }
    r1 = LD32(0x0608E890);
    r10 = r1 + 128;
    if (!((r1 & r1) == 0)) {
        r5 = LD32(0x06079FE0);
        r0 = GCALL3(0x06062D24, r1, r5, 96);
        r5 = LD32(0x06079FE0);
        r0 = GCALL3(0x06062D24, r10, (r5 + 104), 96);
    }
    r2 = LD32(0x06089648);
    r3 = LD16(0x0608E6F0);
    ST16(r2, r3);
    r4 = LD32(0x06089648);
    r1 = LD16(0x0608E6F2);
    ST16((r4 + 2), r1);
    r1 = LD16(0x0608E6F6);
    ST16((r4 + 6), r1);
    r0 = GCALL3(0x06062D24, (r4 + 14), 0x0608E6FE, 26);
    r4 = LD32(0x06089648);
    r0 = GCALL3(0x06062D24, (r4 + 40), 0x0608E720, 72);
    r4 = LD32(0x06089648);
    r0 = GCALL3(0x06062D24, (r4 + 112), 0x0608E8C0, 64);
    r4 = LD32(0x06089648);
    r0 = GCALL3(0x06062D24, (r4 + 176), 0x0608E780, 16);
    r4 = LD32(0x06089648);
    r0 = GCALL3(0x06062D24, (r4 + 192), 0x0608E8A0, 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06062D24(int r4, int r5, int r6)
{
    int r1, r2;
    FRAME(sp, 4);

    if (!((r4 & r4) == 0)) {
        r6 = (int)((unsigned)r6 >> 1);
        if (!((r5 & r5) == 0)) {
            r1 = 0;
            if (!((unsigned)0 >= (unsigned)r6)) {
                do {
                    r2 = LD16(r5);
                    r5 = r5 + 2;
                    r1 = r1 + 1;
                    ST16(r4, r2);
                    r4 = r4 + 2;
                } while (AGAIN(!((unsigned)r1 >= (unsigned)r6)));
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06062D4C(int r4)
{
    int r0, r1, r2, r3, c2;
    FRAME(sp, 4);

    r0 = r4;
    if (r0 == 1) {
        r3 = 0x0608E6FE;
        r1 = LD16(0x0608E6FE);
        r1 = (r1 & 0xFFF) | 0x1000;
        ST16(r3, r1);
    } else {
        c2 = r0 == 2;
        if (!((unsigned)r0 >= (unsigned)1)) {
            r3 = 0x0608E6FE;
            r1 = LD16(0x0608E6FE);
            r1 = r1 & 0xFFF;
            ST16(r3, r1);
        } else {
            if (c2) {
                r3 = 0x0608E6FE;
                r1 = LD16(0x0608E6FE);
                r1 = (r1 & 0xFFF) | 0x2000;
                ST16(r3, r1);
            }
        }
    }
    r2 = 0x06079FD8;
    r1 = LD16(0x06079FD8);
    if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
        ST16(r2, 1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06062DAC(void)
{
    int r0, r4, r8;
    FRAME(sp, 12);

    r0 = GCALL0(0x0606486C);
    r8 = 0x0608E920;
    r0 = LD8(0x0608E920);
    if (!(((r0 & 128) & (r0 & 128)) == 0)) {
        r4 = LD32(0x0607A008);
        r0 = GCALL3(0x06062D24, r4, 0x0608E9A0, 16);
        r0 = LD8(r8);
        ST8(r8, (r0 & 127));
    }
    r0 = LD8(r8);
    if (!(((r0 & 64) & (r0 & 64)) == 0)) {
        r4 = LD32(0x0607A00C);
        r0 = GCALL3(0x06062D24, r4, 0x0608EFB8, 8);
        r0 = LD8(r8);
        ST8(r8, (r0 & 191));
    }
    r0 = LD8(r8);
    if (!(((r0 & 32) & (r0 & 32)) == 0)) {
        r4 = LD32(0x0607A010);
        r0 = GCALL3(0x06062D24, r4, 0x0608E970, 6);
        r0 = LD8(r8);
        ST8(r8, (r0 & 223));
    }
    r0 = LD8(r8);
    if (!(((r0 & 16) & (r0 & 16)) == 0)) {
        r4 = LD32(0x0607A014);
        r0 = GCALL3(0x06062D24, r4, 0x0608E958, 8);
        r0 = LD8(r8);
        ST8(r8, (r0 & 239));
    }
    r0 = LD8(r8);
    if (!(((r0 & 8) & (r0 & 8)) == 0)) {
        r4 = LD32(0x0607A018);
        r0 = GCALL3(0x06062D24, r4, 0x0608E980, 8);
        r0 = LD8(r8);
        ST8(r8, (r0 & 247));
    }
    r0 = LD8(r8);
    r0 = r0 & 4;
    if (!((r0 & r0) == 0)) {
        r4 = LD32(0x0607A01C);
        r0 = GCALL3(0x06062D24, r4, 0x0608E910, 16);
        r0 = LD8(r8);
        r0 = r0 & 251;
        ST8(r8, r0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06062E9C(int r4)
{
    int r0, r1, r2, r3, r9;
    FRAME(sp, 16);

    r1 = LD16(0x0608E6F0);
    r2 = LD16(((r4 & 15) + (r4 & 15)) + 0x06079FE6);
    ST16(0x0608E6F0, (r1 | r2));
    r2 = 0x06079FD8;
    r1 = LD16(0x06079FD8);
    if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
        ST16(r2, 1);
    }
    r0 = LD8(0x0608E920);
    r9 = 16 | r0;
    ST8(0x0608E920, r9);
    r1 = LD16(0x0608E958);
    r3 = 16 | r9;
    r0 = (r1 & -256) | 8;
    ST16(0x0608E958, r0);
    ST8(0x0608E920, r3);
    ST16(0x0608E958, ((r0 & 8) | 0x800));
    ST8(0x0608E920, r3);
    r1 = LD16(0x0608E95A);
    r0 = (r1 & -256) | 8;
    ST16(0x0608E95A, r0);
    ST8(0x0608E920, r3);
    ST16(0x0608E95A, ((r0 & 8) | 0x800));
    ST8(0x0608E920, r3);
    r1 = LD16(0x0608E95C);
    r0 = (r1 & -256) | 8;
    ST16(0x0608E95C, r0);
    ST8(0x0608E920, r3);
    r4 = (r0 & 8) | 0x800;
    ST16(0x0608E95C, r4);
    ST8(0x0608E920, r3);
    r1 = LD16(0x0608E95E);
    ST16(0x0608E95E, ((r1 & -256) | 8));
    ST8(0x0608E920, r3);
    ST16(0x0608E95C, ((r4 & 8) | 0x800));
    r3 = 80 | r9;
    ST8(0x0608E920, r3);
    r1 = LD16(0x0608EFB8);
    r0 = (r1 & 0xFFF0) | 7;
    ST16(0x0608EFB8, r0);
    ST8(0x0608E920, r3);
    ST16(0x0608EFB8, ((r0 & -3841) | 0x700));
    ST8(0x0608E920, r3);
    r1 = LD16(0x0608EFBA);
    r0 = (r1 & 0xFFF0) | 7;
    ST16(0x0608EFBA, r0);
    ST8(0x0608E920, r3);
    ST16(0x0608EFBA, ((r0 & -3841) | 0x700));
    ST8(0x0608E920, r3);
    r1 = LD16(0x0608EFBC);
    r0 = (r1 & 0xFFF0) | 7;
    ST16(0x0608EFBC, r0);
    ST8(0x0608E920, r3);
    ST16(0x0608EFBC, ((r0 & -3841) | 0x700));
    ST8(0x0608E920, r3);
    r1 = LD16(0x0608EFBE);
    r2 = 208 | r9;
    r0 = (r1 & 0xFFF0) | 7;
    ST16(0x0608EFBE, r0);
    ST8(0x0608E920, r3);
    ST16(0x0608EFBE, ((r0 & -3841) | 0x700));
    ST8(0x0608E920, r2);
    r3 = r2;
    r1 = LD16(0x0608E9A0);
    r0 = (r1 & 0xFFF0) | 3;
    ST16(0x0608E9A0, r0);
    ST8(0x0608E920, r3);
    r0 = r0 | 32;
    ST16(0x0608E9A0, r0);
    ST8(0x0608E920, r3);
    r1 = 0xFFEF & r0;
    ST16(0x0608E9A0, r1);
    ST8(0x0608E920, r3);
    r1 = (r1 & 0xFFF) | 0x3000;
    ST16(0x0608E9A0, r1);
    ST8(0x0608E920, r3);
    ST16(0x0608E9A0, (r1 & -3841));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060632A0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    r0 = r5 & 0xFFFF;
    r3 = r6;
    if (r0 == 1) {
        ST32(0x0608E8FC, (0x0007FFFF & r4));
        r8 = 0x0608E8FC;
        r4 = LD32(0x0608E8FC);
        ST32(r14, r0);
        r0 = GCALL3(0x06062D24, (r4 | 0x25E00000), r3, (r0 + r0));
        r1 = LD32(0x0608E8FC);
        r0 = LD32(r14);
        r2 = (int)((unsigned)r1 >> 1);
        ST32(0x0608E8FC, r2);
        if (!(r0 == 1)) {
            ST32(r8, (((int)0x80000000) | r2));
        }
        r2 = 0x06079FD8;
        r1 = LD16(0x06079FD8);
        r7 = 1;
        if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
            ST16(r2, r7);
        }
    } else {
        r1 = LD16(0x06079FDC);
        if (r0 == (r1 & 0xFFFF)) {
            ST32(0x0608E8FC, (0x0007FFFF & r4));
            r8 = 0x0608E8FC;
            r4 = LD32(0x0608E8FC);
            ST32(r14, r0);
            r0 = GCALL3(0x06062D24, (r4 | 0x25E00000), r3, (r0 + r0));
            r1 = LD32(0x0608E8FC);
            r0 = LD32(r14);
            r2 = (int)((unsigned)r1 >> 1);
            ST32(0x0608E8FC, r2);
            if (!(r0 == 1)) {
                ST32(r8, (((int)0x80000000) | r2));
            }
            r2 = 0x06079FD8;
            r1 = LD16(0x06079FD8);
            r7 = 1;
            if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
                ST16(r2, r7);
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06063324(int r4)
{
    int r1, r2, r3, r6, r7, c0;
    FRAME(sp, 4);

    r4 = ~r4;
    r3 = 0;
    r6 = 7;
    r7 = 0x0608E930;
    r1 = 0;
    do {
        r1 = r1 + r7;
        r2 = LD32(r1);
        r3 = r3 + 1;
        ST32(r1, (r2 & r4));
        r1 = r3 & 255;
        c0 = (unsigned)r1 > (unsigned)r6;
        r1 = r1 << 2;
    } while (AGAIN(!(c0)));
    r2 = LD32(0x0608E968);
    ST32(0x0608E968, (r2 & r4));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606335C(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, c3, c7;
    FRAME(sp, 28);

    r11 = r4;
    r8 = r5;
    r12 = r6;
    r10 = 0;
    r0 = GCALL1(0x06063324, r4);
    r1 = LD32(0x0608E968);
    r9 = 0;
    if (!((r1 & r1) == 0)) {
        r0 = 0;
    } else {
        r0 = GCALL0(0x060643D8);
        r1 = 1;
        if (r0 == 1) {
            r10 = 8;
            if ((unsigned)r8 > (unsigned)0x800) {
                r0 = 0;
            } else {
                r9 = 0x200;
                c7 = (unsigned)r8 > (unsigned)0x100;
                r8 = 0;
                if (c7) {
                    r1 = r10 & 255;
                    r3 = r1;
                    if ((unsigned)r8 >= (unsigned)r1) {
                        ST32(0x0608E968, r11);
                        r0 = GCALL3(0x06066798, r11, 0, (r12 & 255));
                        r0 = 0x25F00000;
                    } else {
                        r2 = 0x0608E930;
                        while (1) {
                            r1 = LD32(r2);
                            r8 = r8 + 1;
                            if (!((r1 & r1) == 0)) {
                                POLL();
                                r0 = 0;
                                break;
                            } else {
                                r2 = r2 + 4;
                                if (!((unsigned)r8 >= (unsigned)r3)) {
                                    POLL();
                                    continue;
                                } else {
                                    ST32(0x0608E968, r11);
                                    r0 = GCALL3(0x06066798, r11, 0, (r12 & 255));
                                    r0 = 0x25F00000;
                                    break;
                                }
                            }
                            POLL();
                        }
                    }
                } else {
                    r1 = r10 & 255;
                    r7 = r1;
                    if (!((unsigned)r8 >= (unsigned)r1)) {
                        r3 = 0x0608E930;
                        while (1) {
                            r1 = LD32(r3);
                            r6 = r12 & 255;
                            if ((r1 & r1) == 0) {
                                ST32(r3, r11);
                                r0 = GCALL3(0x06066798, r11, r8, r6);
                                r0 = (r9 * r8) + 0x25F00000;
                                break;
                            } else {
                                r8 = r8 + 1;
                                r3 = r3 + 4;
                                if (!((unsigned)r8 >= (unsigned)r7)) {
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
            }
        } else {
            c3 = r0 == 2;
            if (!((unsigned)r0 >= (unsigned)r1)) {
                r10 = 4;
                if ((unsigned)r8 > (unsigned)0x400) {
                    r0 = 0;
                } else {
                    r9 = 0x200;
                    c7 = (unsigned)r8 > (unsigned)0x100;
                    r8 = 0;
                    if (c7) {
                        r1 = r10 & 255;
                        r3 = r1;
                        if ((unsigned)r8 >= (unsigned)r1) {
                            ST32(0x0608E968, r11);
                            r0 = GCALL3(0x06066798, r11, 0, (r12 & 255));
                            r0 = 0x25F00000;
                        } else {
                            r2 = 0x0608E930;
                            while (1) {
                                r1 = LD32(r2);
                                r8 = r8 + 1;
                                if (!((r1 & r1) == 0)) {
                                    POLL();
                                    r0 = 0;
                                    break;
                                } else {
                                    r2 = r2 + 4;
                                    if (!((unsigned)r8 >= (unsigned)r3)) {
                                        POLL();
                                        continue;
                                    } else {
                                        ST32(0x0608E968, r11);
                                        r0 = GCALL3(0x06066798, r11, 0, (r12 & 255));
                                        r0 = 0x25F00000;
                                        break;
                                    }
                                }
                                POLL();
                            }
                        }
                    } else {
                        r1 = r10 & 255;
                        r7 = r1;
                        if (!((unsigned)r8 >= (unsigned)r1)) {
                            r3 = 0x0608E930;
                            while (1) {
                                r1 = LD32(r3);
                                r6 = r12 & 255;
                                if ((r1 & r1) == 0) {
                                    ST32(r3, r11);
                                    r0 = GCALL3(0x06066798, r11, r8, r6);
                                    r0 = (r9 * r8) + 0x25F00000;
                                    break;
                                } else {
                                    r8 = r8 + 1;
                                    r3 = r3 + 4;
                                    if (!((unsigned)r8 >= (unsigned)r7)) {
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
                }
            } else {
                if (c3) {
                    r1 = 0x400;
                    r10 = 4;
                    if ((unsigned)r8 > (unsigned)0x400) {
                        r0 = 0;
                    } else {
                        r9 = r1;
                        c7 = (unsigned)r8 > (unsigned)0x100;
                        r8 = 0;
                        if (c7) {
                            r1 = r10 & 255;
                            r3 = r1;
                            if ((unsigned)r8 >= (unsigned)r1) {
                                ST32(0x0608E968, r11);
                                r0 = GCALL3(0x06066798, r11, 0, (r12 & 255));
                                r0 = 0x25F00000;
                            } else {
                                r2 = 0x0608E930;
                                while (1) {
                                    r1 = LD32(r2);
                                    r8 = r8 + 1;
                                    if (!((r1 & r1) == 0)) {
                                        POLL();
                                        r0 = 0;
                                        break;
                                    } else {
                                        r2 = r2 + 4;
                                        if (!((unsigned)r8 >= (unsigned)r3)) {
                                            POLL();
                                            continue;
                                        } else {
                                            ST32(0x0608E968, r11);
                                            r0 = GCALL3(0x06066798, r11, 0, (r12 & 255));
                                            r0 = 0x25F00000;
                                            break;
                                        }
                                    }
                                    POLL();
                                }
                            }
                        } else {
                            r1 = r10 & 255;
                            r7 = r1;
                            if (!((unsigned)r8 >= (unsigned)r1)) {
                                r3 = 0x0608E930;
                                while (1) {
                                    r1 = LD32(r3);
                                    r6 = r12 & 255;
                                    if ((r1 & r1) == 0) {
                                        ST32(r3, r11);
                                        r0 = GCALL3(0x06066798, r11, r8, r6);
                                        r0 = (r9 * r8) + 0x25F00000;
                                        break;
                                    } else {
                                        r8 = r8 + 1;
                                        r3 = r3 + 4;
                                        if (!((unsigned)r8 >= (unsigned)r7)) {
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
                    }
                } else {
                    c7 = (unsigned)r8 > (unsigned)0x100;
                    r8 = 0;
                    if (c7) {
                        r1 = r10 & 255;
                        r3 = r1;
                        if ((unsigned)r8 >= (unsigned)r1) {
                            ST32(0x0608E968, r11);
                            r0 = GCALL3(0x06066798, r11, 0, (r12 & 255));
                            r0 = 0x25F00000;
                        } else {
                            r2 = 0x0608E930;
                            while (1) {
                                r1 = LD32(r2);
                                r8 = r8 + 1;
                                if (!((r1 & r1) == 0)) {
                                    POLL();
                                    r0 = 0;
                                    break;
                                } else {
                                    r2 = r2 + 4;
                                    if (!((unsigned)r8 >= (unsigned)r3)) {
                                        POLL();
                                        continue;
                                    } else {
                                        ST32(0x0608E968, r11);
                                        r0 = GCALL3(0x06066798, r11, 0, (r12 & 255));
                                        r0 = 0x25F00000;
                                        break;
                                    }
                                }
                                POLL();
                            }
                        }
                    } else {
                        r1 = r10 & 255;
                        r7 = r1;
                        if (!((unsigned)r8 >= (unsigned)r1)) {
                            r3 = 0x0608E930;
                            while (1) {
                                r1 = LD32(r3);
                                r6 = r12 & 255;
                                if ((r1 & r1) == 0) {
                                    ST32(r3, r11);
                                    r0 = GCALL3(0x06066798, r11, r8, r6);
                                    r0 = (r9 * r8) + 0x25F00000;
                                    break;
                                } else {
                                    r8 = r8 + 1;
                                    r3 = r3 + 4;
                                    if (!((unsigned)r8 >= (unsigned)r7)) {
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
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060634F8(int r4)
{
    int r1, r2, r3, c0;
    FRAME(sp, 4);

    r2 = 0;
    ST8(r4, 0);
    ST8((r4 + 1), 0);
    ST8((r4 + 2), 0);
    ST8((r4 + 3), 0);
    ST8((r4 + 4), 0);
    ST8((r4 + 5), 0);
    ST8((r4 + 6), 0);
    ST8((r4 + 8), 0);
    ST8((r4 + 7), 0);
    ST16((r4 + 10), 0);
    r3 = 15;
    r1 = 0;
    do {
        ST32((r1 + r4) + 12, 0);
        r2 = r2 + 1;
        r1 = r2 & 255;
        c0 = (unsigned)r1 > (unsigned)r3;
        r1 = r1 << 2;
    } while (AGAIN(!(c0)));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06064338(int r4)
{
    int r0, r1, r2, r3, r6, r7;
    FRAME(sp, 4);

    r2 = 0;
    r7 = 7;
    r3 = 0x0608E700;
    r1 = 0;
    do {
        r0 = r1 + r1;
        r6 = LD16(r0 + r4);
        r2 = r2 + 1;
        r1 = r2 & 0xFFFF;
        ST16(r0 + r3, r6);
    } while (AGAIN(!((unsigned)r1 > (unsigned)r7)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06064360(void)
{
    int r0, r1, r2, r3, r6, r7;
    FRAME(sp, 8);

    r0 = GCALL0(0x06064E00);
    r0 = GCALL0(0x0606503C);
    r0 = GCALL0(0x060650A8);
    r0 = GCALL0(0x06065104);
    r0 = GCALL0(0x06065164);
    r0 = GCALL0(0x060651BC);
    r2 = 0;
    r7 = 7;
    r3 = 0x0608E930;
    r1 = 0;
    do {
        r0 = r1 << 2;
        r6 = 0;
        r2 = r2 + 1;
        r1 = r2 & 255;
        ST32(r0 + r3, 0);
    } while (AGAIN(!((unsigned)r1 > (unsigned)r7)));
    ST32(0x0608E968, r6);
    ST8(0x0608E97A, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06064D80(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9;
    FRAME(sp, 12);

    r8 = r6;
    r9 = r7;
    if (!((r4 & r4) == 0)) {
        r7 = 0x0608E920;
        r0 = LD8(0x0608E920);
        r6 = 0x1FF;
        r0 = r0 | 4;
        ST8(0x0608E920, r0);
        r1 = LD16(0x0608E91A);
        r0 = r0 | 4;
        ST16(0x0608E91A, ((r1 & 0x1FF) + r5));
        ST8(0x0608E920, r0);
        r2 = 0x0608E91C;
        r1 = LD16(0x0608E91C);
        r3 = 0x0608E91E;
    } else {
        r7 = 0x0608E920;
        r0 = LD8(0x0608E920);
        r6 = 0x1FF;
        r0 = r0 | 4;
        ST8(0x0608E920, r0);
        r1 = LD16(0x0608E914);
        r0 = r0 | 4;
        ST16(0x0608E914, ((r1 & 0x1FF) + r5));
        ST8(0x0608E920, r0);
        r2 = 0x0608E916;
        r1 = LD16(0x0608E916);
        r3 = 0x0608E918;
    }
    ST16(r2, ((r1 & r6) + r8));
    ST8(r7, r0);
    r1 = LD16(r3);
    ST16(r3, ((r1 & r6) + r9));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060652A4(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, c3, c4, c5, c6;
    FRAME(sp, 24);

    r6 = 0x0608E920;
    r7 = 0x0608E9A2;
    r2 = -257;
    r5 = 0xFFFE;
    r8 = 0xFFFD;
    r9 = 0xFFFB;
    r10 = 0xFFF7;
    r11 = 0xFFEF;
    r12 = 0xFFDF;
    r0 = LD8(0x0608E920);
    r0 = r0 | 128;
    ST8(0x0608E920, r0);
    r0 = r0 | 128;
    r1 = LD16(0x0608E9A2);
    r3 = r0;
    r1 = r1 & -257;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r0);
    r1 = r1 & 0xFFFE;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r3);
    r1 = r1 & 0xFFFD;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r3);
    r1 = r1 & 0xFFFB;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r3);
    r1 = r1 & 0xFFF7;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r3);
    r1 = r1 & 0xFFEF;
    ST16(0x0608E9A2, r1);
    ST8(0x0608E920, r3);
    r1 = r1 & 0xFFDF;
    ST16(0x0608E9A2, r1);
    if (!((r4 & r4) == 0)) {
        ST8(r6, r3);
        r2 = 0x100 | (r1 & r2);
        ST16(r7, r2);
        if (!(((4 & r4) & (4 & r4)) == 0)) {
            ST8(r6, r3);
            r0 = (r2 & r5) | 1;
            ST16(r7, r0);
        }
        r1 = 8;
        if (!(((2 & r4) & (2 & r4)) == 0)) {
            r0 = LD8(r6);
            ST8(r6, (r0 | 128));
            r1 = LD16(r7);
            r0 = (r1 & r5) | 1;
            ST16(r7, r0);
            r1 = 8;
        }
        c3 = ((r1 & r4) & (r1 & r4)) == 0;
        r1 = -128;
        if (!(c3)) {
            r0 = LD8(r6);
            ST8(r6, (r0 | 128));
            r1 = LD16(r7);
            r0 = (r1 & r8) | 2;
            ST16(r7, r0);
            r1 = -128;
        }
        c4 = (((r1 & 255) & r4) & ((r1 & 255) & r4)) == 0;
        r1 = 16;
        if (!(c4)) {
            r0 = LD8(r6);
            ST8(r6, (r0 | 128));
            r1 = LD16(r7);
            r0 = (r1 & r8) | 2;
            ST16(r7, r0);
            r1 = 16;
        }
        c5 = ((r1 & r4) & (r1 & r4)) == 0;
        r1 = 32;
        if (!(c5)) {
            r0 = LD8(r6);
            ST8(r6, (r0 | 128));
            r1 = LD16(r7);
            r0 = (r1 & r9) | 4;
            ST16(r7, r0);
            r1 = 32;
        }
        c6 = ((r1 & r4) & (r1 & r4)) == 0;
        r1 = 1;
        if (!(c6)) {
            r0 = LD8(r6);
            ST8(r6, (r0 | 128));
            r1 = LD16(r7);
            r0 = (r1 & r10) | 8;
            ST16(r7, r0);
            r1 = 1;
        }
        if (!(((r1 & r4) & (r1 & r4)) == 0)) {
            r0 = LD8(r6);
            ST8(r6, (r0 | 128));
            r1 = LD16(r7);
            r0 = (r1 & r11) | 16;
            ST16(r7, r0);
        }
        if (!(((0x00080000 & r4) & (0x00080000 & r4)) == 0)) {
            r0 = LD8(r6);
            ST8(r6, (r0 | 128));
            r1 = LD16(r7);
            r0 = (r1 & r12) | 32;
            ST16(r7, r0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06066798(int r4, int r5, int r6)
{
    int r0, r1, r7, c3, c5, c7;
    FRAME(sp, 4);

    r7 = 0x100;
    if (!(((r4 & 0x100) & (r4 & 0x100)) == 0)) {
        r0 = LD8(0x0608E920);
        ST8(0x0608E920, (r0 | 128));
        r1 = LD16(0x0608E9A6);
        ST16(0x0608E9A6, ((r1 & -241) | ((r5 << 2) << 2)));
    }
    r1 = -120;
    if (!(((6 & r4) & (6 & r4)) == 0)) {
        r0 = LD8(0x0608E920);
        ST8(0x0608E920, (r0 | 128));
        r1 = LD16(0x0608E9A4);
        ST16(0x0608E9A4, ((r1 & 0xFFF0) | r5));
        if (((r6 & 255) & (r6 & 255)) == 0) {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 & -257));
        } else {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 | r7));
        }
        r1 = -120;
    }
    c3 = (((r1 & 255) & r4) & ((r1 & 255) & r4)) == 0;
    r1 = 16;
    if (!(c3)) {
        r0 = LD8(0x0608E920);
        ST8(0x0608E920, (r0 | 128));
        r1 = LD16(0x0608E9A4);
        ST16(0x0608E9A4, ((r1 & -241) | ((r5 << 2) << 2)));
        if (((r6 & 255) & (r6 & 255)) == 0) {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 & -513));
        } else {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 | 0x200));
        }
        r1 = 16;
    }
    c5 = ((r1 & r4) & (r1 & r4)) == 0;
    r1 = 32;
    if (!(c5)) {
        r0 = LD8(0x0608E920);
        ST8(0x0608E920, (r0 | 128));
        r1 = LD16(0x0608E9A4);
        ST16(0x0608E9A4, ((r1 & -3841) | (r5 << 8)));
        if (((r6 & 255) & (r6 & 255)) == 0) {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 & -1025));
        } else {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 | 0x400));
        }
        r1 = 32;
    }
    c7 = ((r1 & r4) & (r1 & r4)) == 0;
    r1 = 1;
    if (!(c7)) {
        r0 = LD8(0x0608E920);
        ST8(0x0608E920, (r0 | 128));
        r1 = LD16(0x0608E9A4);
        ST16(0x0608E9A4, ((r1 & 0xFFF) | (((r5 << 8) << 2) << 2)));
        if (((r6 & 255) & (r6 & 255)) == 0) {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 & -2049));
        } else {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 | 0x800));
        }
        r1 = 1;
    }
    if (!(((r1 & r4) & (r1 & r4)) == 0)) {
        r0 = LD8(0x0608E920);
        ST8(0x0608E920, (r0 | 128));
        r1 = LD16(0x0608E9A6);
        ST16(0x0608E9A6, ((r1 & 0xFFF0) | r5));
        if (((r6 & 255) & (r6 & 255)) == 0) {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 & -4097));
        } else {
            r1 = LD16(0x0608E710);
            ST16(0x0608E710, (r1 | 0x1000));
        }
    }
    if (!(((0x00040000 & r4) & (0x00040000 & r4)) == 0)) {
        ST32(0x0608E964, r5);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606694C(int r4)
{
    int r0, r1, c2, c4, c6, c8, c9;
    FRAME(sp, 4);

    r0 = r4;
    if (r0 == 16) {
        r1 = LD16(0x0608E9A4);
        r0 = ((int)((unsigned)r1 >> 8)) & 7;
    } else {
        c2 = r0 == 2;
        if ((unsigned)r0 > (unsigned)16) {
            c8 = (unsigned)r0 > (unsigned)128;
            if (r0 == 128) {
                r0 = LD16(0x0608E9A4);
                r0 = (int)((unsigned)((int)((unsigned)(r0 & 112) >> 2)) >> 2);
            } else {
                c9 = r0 == 32;
                if (c8) {
                    if (r0 == 0x100) {
                        r0 = LD16(0x0608E9A6);
                        r0 = (int)((unsigned)((int)((unsigned)(r0 & 112) >> 2)) >> 2);
                    } else {
                        if (r0 == 0x00040000) {
                            r0 = LD32(0x0608E964);
                        }
                    }
                } else {
                    if (c9) {
                        r1 = LD16(0x0608E9A4);
                        r0 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 8)) >> 2)) >> 2)) & 7;
                    }
                }
            }
        } else {
            r1 = 2;
            if (c2) {
                r0 = LD16(0x0608E9A4);
                r0 = r0 & 7;
            } else {
                c4 = r0 == 1;
                if ((unsigned)r0 > (unsigned)r1) {
                    c6 = r0 == 8;
                    if (r0 == 4) {
                        r0 = LD16(0x0608E9A4);
                        r0 = r0 & 7;
                    } else {
                        if (c6) {
                            r0 = LD16(0x0608E9A4);
                            r0 = (int)((unsigned)((int)((unsigned)(r0 & 112) >> 2)) >> 2);
                        }
                    }
                } else {
                    if (c4) {
                        r0 = LD16(0x0608E9A6);
                        r0 = r0 & 7;
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060669F8(int r4)
{
    int r0, r1, r2, r3, r5, r6, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    ST32(r14, r4);
    r1 = 0x20100063;
    do {
        r0 = LD8(r1);
    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    ST8(0x20100063, 1);
    ST8(0x2010001F, 7);
    r1 = 0x20100063;
    do {
        r0 = LD8(r1);
    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    ST16(0x25B00400, 0x200);
    r0 = GCALL2(0x06067804, 0x25A00000, 0xB000);
    r2 = LD32(r14);
    r6 = LD16((r2 + 4));
    r5 = LD32(r2);
    r0 = GCALL3(0x060678C4, 0x25A00000, r5, (r6 & 0xFFFF));
    r1 = LD32(0x25A00400);
    ST32(0x06089698, (r1 + 0x25A00000));
    r3 = LD32(0x25A00404);
    r3 = r3 + 0x25A00000;
    ST32(0x0608969C, r3);
    r2 = LD16(0x25A00412);
    r1 = LD16(0x25A00414);
    ST32(0x0608EFD0, (((r2 << 16) | (r1 & 0xFFFF)) + 0x25A00000));
    ST32(0x060896B8, r3);
    r1 = LD32(0x25A00408);
    ST32(0x060896A0, (r1 + 0x25A00000));
    ST32(0x060896A4, (128 + r3));
    ST32(0x060896B0, (160 + r3));
    ST32(0x060896B4, (176 + r3));
    ST32(0x060896A8, (144 + r3));
    ST32(0x060896AC, (r3 + 148));
    r1 = LD32(r14);
    r1 = LD16((r1 + 12));
    r6 = (((r1 & 0xFFFF) + (r1 & 0xFFFF)) + 4) - (((r1 & 0xFFFF) + (r1 & 0xFFFF)) - (((int)((unsigned)((r1 & 0xFFFF) + (r1 & 0xFFFF)) >> 2)) << 2));
    r1 = LD32(r14);
    r5 = LD32(r1 + 8);
    r1 = LD32(0x06089698);
    r4 = LD32(r1 + 8);
    r0 = GCALL3(0x060678C4, (r4 + 0x25A00000), r5, r6);
    ST32(0x06089694, 0);
    r1 = 0x20100063;
    do {
        r0 = LD8(r1);
    } while (AGAIN(!(((r0 & 1) & (r0 & 1)) == 0)));
    ST8(0x20100063, 1);
    ST8(0x2010001F, 6);
    r1 = 0x20100063;
    do {
        r0 = LD8(r1);
        r0 = r0 & 1;
    } while (AGAIN(!((r0 & r0) == 0)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066B70(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    r8 = r5;
    r0 = GCALL4(0x06067820, r14, (r14 + 4), (r6 & 0xFFFF), (r7 & 0xFFFF));
    r5 = r4;
    r4 = LD32(r14);
    r0 = GCALL3(0x060678C4, r4, r5, r8);
    r3 = LD32(r14 + 4);
    r1 = LD32(r3);
    ST32(r3, (r1 | ((int)0x80000000)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066BBC(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9;
    FRAME(sp, 16);

    r1 = LD32(0x06089694);
    r9 = r4;
    if ((r1 & r1) == 0) {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        r5 = 0;
        if (!(((r0 & 255) & (r0 & 255)) == 0)) {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r3 = LD32(0x060896B8);
            ST16(r3, 0x800);
            r1 = LD32(0x060896B8);
            r1 = LD16(r1);
            r7 = 15;
            if (!(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0)) {
                r3 = 0x06000000;
                r6 = LD32(0x060896B8);
                r2 = 0;
                do {
                    r1 = LD32(r3);
                    r2 = r2 + 1;
                    if (!(r2 > r7)) {
                        POLL();
                        continue;
                    }
                    r1 = LD16(r6);
                    r2 = 0;
                } while (AGAIN(!(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0)));
            }
            r0 = GCALL0(0x060678DC);
            r5 = 0;
            if (!(((r0 & 255) & (r0 & 255)) == 0)) {
                r1 = LD32(0x060896B8);
                ST8((r1 + 2), r9);
                r3 = LD32(0x060896B8);
                ST16(r3, 0x800);
                r1 = LD32(0x060896B8);
                r1 = LD16(r1);
                r7 = 15;
                if (!(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0)) {
                    r3 = 0x06000000;
                    r6 = LD32(0x060896B8);
                    r2 = 0;
                    do {
                        r1 = LD32(r3);
                        r2 = r2 + 1;
                        if (!(r2 > r7)) {
                            POLL();
                            continue;
                        }
                        r1 = LD16(r6);
                        r2 = 0;
                    } while (AGAIN(!(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0)));
                }
                ST32(0x06089694, 0);
                r0 = 0;
            } else {
                ST32(0x06089694, r5);
                r0 = 1;
            }
        } else {
            ST32(r8, r5);
            r0 = 1;
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066C94(int r4)
{
    int r0, r1, r2, r8, r9, c1;
    FRAME(sp, 16);

    r1 = LD32(0x06089694);
    r9 = r4;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r2 = LD32(0x060896B8);
            ST16(r2, -32256);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066CF4(int r4)
{
    int r0, r1, r2, r8, r9, c1;
    FRAME(sp, 16);

    r1 = LD32(0x06089694);
    r9 = r4;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r2 = LD32(0x060896B8);
            ST16(r2, -32000);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066D54(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, c1;
    FRAME(sp, 20);

    r9 = r4;
    r1 = LD32(0x06089694);
    r10 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r1 = LD32(0x060896B8);
            ST8((r1 + 3), r10);
            r2 = LD32(0x060896B8);
            ST16(r2, -30976);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066DC0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r9, r10, r11, r12;
    FRAME(sp, 28);

    r10 = r4;
    r12 = r5;
    r1 = LD32(0x06089694);
    r9 = r6;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r11 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        r3 = 0;
        if (((r0 & 255) & (r0 & 255)) == 0) {
            ST32(0x06089694, r3);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r10);
            r0 = GCALL1(0x060678A8, ((signed char)r9));
            r2 = LD32(0x060896B8);
            ST8((r2 + 3), ((((r12 << 2) + (r12 << 2)) << 2) | r0));
            r2 = LD32(0x060896B8);
            ST16(r2, -30720);
            ST32(r11, 0);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066E48(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10;
    FRAME(sp, 20);

    r9 = r4;
    r1 = LD32(0x06089694);
    r10 = r5;
    if ((r1 & r1) == 0) {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        r6 = 0;
        if (!(((r0 & 255) & (r0 & 255)) == 0)) {
            ST16(0x25A00418, r6);
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r10);
            r2 = LD32(0x060896B8);
            ST16(r2, -30464);
            r1 = LD16(0x25A00418);
            ST16(r9, r1);
            r7 = 15;
            if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
                r3 = 0x06000000;
                r2 = 0;
                do {
                    r1 = LD32(r3);
                    r2 = r2 + 1;
                    if (!(r2 > r7)) {
                        POLL();
                        continue;
                    }
                    r1 = LD16(0x25A00418);
                    ST16(r9, r1);
                    r2 = 0;
                } while (AGAIN(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0));
            }
            ST32(0x06089694, 0);
            r0 = 0;
        } else {
            ST32(r8, 0);
            r0 = 1;
        }
    } else {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066EE4(void)
{
    int r0, r1, r2, r8, c1;
    FRAME(sp, 12);

    r1 = LD32(0x06089694);
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r2 = LD32(0x060896B8);
            ST16(r2, 0xC00);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066F38(void)
{
    int r0, r1, r2, r8, c1;
    FRAME(sp, 12);

    r1 = LD32(0x06089694);
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r2 = LD32(0x060896B8);
            ST16(r2, 0xD00);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06066F8C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, c1;
    FRAME(sp, 28);

    r8 = r4;
    r10 = r5;
    r11 = r6;
    r1 = LD32(0x06089694);
    r12 = r7;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r9 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r8);
            r1 = LD32(0x060896B8);
            ST8((r1 + 3), r10);
            r1 = LD32(0x060896B8);
            ST8((r1 + 4), r11);
            r1 = LD32(0x060896B8);
            ST8((r1 + 5), r12);
            r2 = LD32(0x060896B8);
            ST16(r2, 0x100);
            ST32(r9, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067010(int r4)
{
    int r0, r1, r2, r8, r9, c1;
    FRAME(sp, 16);

    r1 = LD32(0x06089694);
    r9 = r4;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r2 = LD32(0x060896B8);
            ST16(r2, 0x200);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067070(int r4)
{
    int r0, r1, r2, r8, r9, c1;
    FRAME(sp, 16);

    r1 = LD32(0x06089694);
    r9 = r4;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r2 = LD32(0x060896B8);
            ST16(r2, 0x300);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060670D0(int r4)
{
    int r0, r1, r2, r8, r9, c1;
    FRAME(sp, 16);

    r1 = LD32(0x06089694);
    r9 = r4;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r2 = LD32(0x060896B8);
            ST16(r2, 0x400);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067130(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11, c1;
    FRAME(sp, 24);

    r9 = r4;
    r10 = r5;
    r1 = LD32(0x06089694);
    r11 = r6;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r1 = LD32(0x060896B8);
            ST8((r1 + 3), r10);
            r1 = LD32(0x060896B8);
            ST8((r1 + 4), r11);
            r2 = LD32(0x060896B8);
            ST16(r2, 0x500);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067224(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14, c1;
    FRAME(sp, 40);

    r14 = sp - 40;
    r1 = LD32(r14 + 40);
    r2 = LD32(r14 + 44);
    r12 = r4;
    ST8((7 + r14), r5);
    r9 = r6;
    r13 = r1;
    ST8((3 + r14), r2);
    r1 = LD32(0x06089694);
    r11 = r7;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r10 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r2 = LD32(0x060896B8);
            r1 = LD8((7 + r14));
            ST8((r2 + 2), (((r1 << 2) + (r1 << 2)) | r9));
            r2 = LD32(0x060896B8);
            ST8((r2 + 3), ((((r12 << 2) + (r12 << 2)) << 2) | r11));
            r1 = LD32(0x060896B8);
            ST8((r1 + 4), r13);
            r1 = LD32(0x060896B8);
            r8 = LD8((3 + r14));
            ST8((r1 + 5), r8);
            r2 = LD32(0x060896B8);
            ST16(r2, 0x900);
            ST32(r10, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060672DC(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11, c1;
    FRAME(sp, 24);

    r9 = r4;
    r11 = r5;
    r1 = LD32(0x06089694);
    r10 = r6;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r1 = LD32(0x060896B8);
            ST8((r1 + 3), (r11 | r10));
            r2 = LD32(0x060896B8);
            ST16(r2, 0xE00);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067350(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r9, r10, r11;
    FRAME(sp, 24);

    r10 = r4;
    r1 = LD32(0x06089694);
    r9 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r11 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        r7 = 0;
        if (((r0 & 255) & (r0 & 255)) == 0) {
            ST32(0x06089694, r7);
            r0 = 1;
        } else {
            r3 = LD32(0x060896B8);
            r1 = LD8(r10);
            r2 = LD8(r9);
            ST8((r3 + 2), (r1 | r2));
            r4 = LD8((r9 + 2));
            r0 = GCALL1(0x060678A8, r4);
            r2 = LD32(0x060896B8);
            r1 = LD8((r9 + 1));
            ST8((r2 + 3), ((((r1 << 2) + (r1 << 2)) << 2) | r0));
            r2 = LD32(0x060896B8);
            r1 = LD8((r10 + 2));
            ST8((r2 + 4), r1);
            r2 = LD32(0x060896B8);
            r1 = LD8((r10 + 3));
            ST8((r2 + 5), r1);
            r2 = LD32(0x060896B8);
            r1 = LD8((r10 + 4));
            ST8((r2 + 6), r1);
            r2 = LD32(0x060896B8);
            r1 = LD8((r10 + 5));
            ST8((r2 + 7), r1);
            r2 = LD32(0x060896B8);
            r1 = LD8((r9 + 4));
            ST8((r2 + 8), r1);
            r2 = LD32(0x060896B8);
            r1 = LD8((r9 + 5));
            ST8((r2 + 9), r1);
            r3 = LD32(0x060896B8);
            r2 = LD8((r9 + 6));
            r1 = LD8((r9 + 7));
            ST8((r3 + 10), (((r2 << 2) + (r2 << 2)) | r1));
            r3 = LD32(0x060896B8);
            r2 = LD8((r9 + 8));
            r1 = LD8((r9 + 9));
            ST8((r3 + 11), (((r2 << 2) + (r2 << 2)) | r1));
            r1 = LD32(0x060896B8);
            ST8((r1 + 13), 0);
            r2 = LD32(0x060896B8);
            ST16(r2, -31488);
            ST32(r11, 0);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067460(int r4)
{
    int r0, r1, r2, r8, r9, c1;
    FRAME(sp, 16);

    r1 = LD32(0x06089694);
    r9 = r4;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r2 = LD32(0x060896B8);
            ST16(r2, -31232);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060674C0(int r4)
{
    int r0, r1, r2, r3, r7, r9, r10;
    FRAME(sp, 20);

    r1 = LD32(0x06089694);
    r9 = r4;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r10 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        r7 = 0;
        if (((r0 & 255) & (r0 & 255)) == 0) {
            ST32(0x06089694, r7);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            r2 = LD8(r9);
            ST8((r1 + 2), r2);
            r4 = LD8((r9 + 2));
            r0 = GCALL1(0x060678A8, r4);
            r2 = LD32(0x060896B8);
            r1 = LD8((r9 + 1));
            ST8((r2 + 3), ((((r1 << 2) + (r1 << 2)) << 2) | r0));
            r2 = LD32(0x060896B8);
            r1 = LD8((r9 + 4));
            ST8((r2 + 4), r1);
            r2 = LD32(0x060896B8);
            r1 = LD8((r9 + 5));
            ST8((r2 + 5), r1);
            r3 = LD32(0x060896B8);
            r2 = LD8((r9 + 6));
            r1 = LD8((r9 + 7));
            ST8((r3 + 6), (((r2 << 2) + (r2 << 2)) | r1));
            r3 = LD32(0x060896B8);
            r2 = LD8((r9 + 8));
            r1 = LD8((r9 + 9));
            ST8((r3 + 7), (((r2 << 2) + (r2 << 2)) | r1));
            r2 = LD32(0x060896B8);
            ST16(r2, -30208);
            ST32(r10, 0);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067590(void)
{
    int r0, r1, r2, r8, c1;
    FRAME(sp, 12);

    r1 = LD32(0x06089694);
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r2 = LD32(0x060896B8);
            ST16(r2, 0xA00);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060675E4(void)
{
    int r0, r1, r2, r8, c1;
    FRAME(sp, 12);

    r1 = LD32(0x06089694);
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r2 = LD32(0x060896B8);
            ST16(r2, 0xB00);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067638(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10;
    FRAME(sp, 20);

    r8 = r4;
    r1 = LD32(0x06089694);
    r10 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r9 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        r1 = r8 & 255;
        if (((r0 & 255) & (r0 & 255)) == 0) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r2 = LD32(0x060896B8);
            ST8((r2 + 2), (((r1 << 2) + (r1 << 2)) << 2));
            r2 = LD32(0x060896B8);
            ST8((r2 + 3), ((((r10 & 255) << 2) + ((r10 & 255) << 2)) << 2));
            r2 = LD32(0x060896B8);
            ST16(r2, -32768);
            ST32(r9, 0);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060676B4(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r10, r11;
    FRAME(sp, 24);

    r8 = r4;
    r1 = LD32(0x06089694);
    r11 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r10 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        r3 = 0;
        if (((r0 & 255) & (r0 & 255)) == 0) {
            ST32(0x06089694, r3);
            r0 = 1;
        } else {
            r0 = GCALL1(0x060678A8, ((signed char)r8));
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r0);
            r0 = GCALL1(0x060678A8, ((signed char)r11));
            r1 = LD32(0x060896B8);
            ST8((r1 + 3), r0);
            r2 = LD32(0x060896B8);
            ST16(r2, -32512);
            ST32(r10, 0);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067804(int r4, int r5)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL3(0x0604B3F0, r4, 0, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06067820(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8;
    FRAME(sp, 8);

    r8 = r5;
    r5 = r6;
    r6 = r7;
    r1 = LD32(0x060896A0);
    r2 = LD32(r1);
    r3 = 1;
    if (((((int)0x80000000) & r2) & (((int)0x80000000) & r2)) == 0) {
        r7 = 0x060896A0;
        while (1) {
            r0 = r2;
            if (!((((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)((unsigned)r2 >> 16)) >> 8)) >> 2)) >> 2)) & 7) == (r5 & 0xFFFF))) {
                r2 = LD32(r7);
                r2 = LD32((((r3 << 2) + (r3 << 2)) + r2));
                r3 = r3 + 1;
                if (((((int)0x80000000) & r2) & (((int)0x80000000) & r2)) == 0) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            } else {
                if (!((((int)((unsigned)((int)((unsigned)r0 >> 16)) >> 8)) & 15) == (r6 & 0xFFFF))) {
                    r2 = LD32(r7);
                    r2 = LD32((((r3 << 2) + (r3 << 2)) + r2));
                    r3 = r3 + 1;
                    if (((((int)0x80000000) & r2) & (((int)0x80000000) & r2)) == 0) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                } else {
                    ST32(r4, ((0x000FFFFF & r2) + 0x25A00000));
                    r2 = LD32(r7);
                    ST32(r8, (((((r3 - 1) << 2) + ((r3 - 1) << 2)) + r2) + 4));
                    break;
                }
            }
            POLL();
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060678A8(int r4)
{
    int r1;
    FRAME(sp, 4);

    if (!(((signed char)r4) >= 0)) {
        r1 = (~((signed char)r4)) + 17;
    } else {
        r1 = (signed char)r4;
    }
    return r1 & 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060678C4(int r4, int r5, int r6)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL3(0x0604B358, r4, r5, r6);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060678DC(void)
{
    int r0, r1, r2, r3, c6;
    FRAME(sp, 4);

    r2 = LD32(0x060896B8);
    r1 = LD8(r2);
    if (((r1 & 255) & (r1 & 255)) == 0) {
        r1 = LD32(0x0608969C);
        ST32(0x060896B8, r1);
        r0 = 0;
        if (!((unsigned)r1 >= (unsigned)(r1 + 112))) {
            r2 = 0x060896B8;
            r1 = LD32(0x0608969C);
            r3 = r1 + 112;
            while (1) {
                r1 = LD32(r2);
                r1 = LD8(r1);
                c6 = ((r1 & 255) & (r1 & 255)) == 0;
                r0 = c6;
                if (c6) {
                    break;
                } else {
                    r1 = LD32(r2);
                    r1 = r1 + 16;
                    ST32(r2, r1);
                    if (!((unsigned)r1 >= (unsigned)r3)) {
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
        r1 = LD32(0x0608969C);
        r0 = 0;
        if (!((unsigned)r2 >= (unsigned)(r1 + 112))) {
            r2 = LD32(0x060896B8);
            r2 = r2 + 16;
            ST32(0x060896B8, r2);
            r1 = LD32(0x0608969C);
            if (!((unsigned)r2 >= (unsigned)(r1 + 112))) {
                r2 = 0x060896B8;
                r1 = LD32(0x0608969C);
                r3 = r1 + 112;
                while (1) {
                    r1 = LD32(r2);
                    r1 = LD8(r1);
                    if (((r1 & 255) & (r1 & 255)) == 0) {
                        r0 = 1;
                        break;
                    } else {
                        r1 = LD32(r2);
                        r1 = r1 + 16;
                        ST32(r2, r1);
                        if (!((unsigned)r1 >= (unsigned)r3)) {
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
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067974(int r4, int r5)
{
    int r0, r1, r2, r8, r9, r10, c1;
    FRAME(sp, 20);

    r9 = r4;
    r1 = LD32(0x06089694);
    r10 = r5;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 2), r9);
            r1 = LD32(0x060896B8);
            ST8((r1 + 3), r10);
            r2 = LD32(0x060896B8);
            ST16(r2, 0x1200);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060679E0(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11, c1;
    FRAME(sp, 24);

    r9 = r4;
    r10 = r5;
    r1 = LD32(0x06089694);
    r11 = r6;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r1 = LD32(0x060896B8);
            ST8((r1 + 3), r9);
            r1 = LD32(0x060896B8);
            ST8((r1 + 4), r10);
            r1 = LD32(0x060896B8);
            ST8((r1 + 5), r11);
            r2 = LD32(0x060896B8);
            ST16(r2, 0x1100);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067A58(void)
{
    int r0, r1, r2, r8, c1;
    FRAME(sp, 12);

    r1 = LD32(0x06089694);
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r8 = 0x06089694;
        ST32(0x06089694, 1);
        r0 = GCALL0(0x060678DC);
        c1 = ((r0 & 255) & (r0 & 255)) == 0;
        r0 = 0;
        if (c1) {
            ST32(0x06089694, 0);
            r0 = 1;
        } else {
            r2 = LD32(0x060896B8);
            ST16(r2, 0x1300);
            ST32(r8, 0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067AAC(int r4)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, r4);
    r0 = GCALL0(0x0606CD40);
    r4 = LD32(r14);
    r0 = GCALL1(0x06067ADC, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067ADC(int r4)
{
    int r0, r1, r2, r3, r7, r14;
    FRAME(sp, 32);

    r14 = sp - 32;
    ST32(r14, r4);
    r3 = LD32(r14);
    r2 = LD16((r3 + 6));
    ST32(0x0608EFFC, (r2 & 0xFFFF));
    r2 = LD32(r14);
    r3 = LD32(r2 + 12);
    ST32(0x0608F014, r3);
    r3 = LD32(r14);
    r2 = LD16((r3 + 2));
    ST16((r14 + 12), ((r2 + 3) & -4));
    r0 = GCALL1(0x06069EAC, 0x060896C4);
    r2 = LD32(r14);
    r3 = LD16(r2);
    ST16((r14 + 14), (r3 + 4));
    r2 = LD16((r14 + 14));
    ST16(0x060896D4, r2);
    r2 = LD16((r14 + 14));
    ST16(0x060896D6, r2);
    r2 = LD16((r14 + 12));
    ST16(0x060896D8, r2);
    r2 = LD16((r14 + 12));
    ST16(0x060896DA, ((int)((unsigned)(r2 & 0xFFFF) >> 2)));
    r3 = LD32(r14);
    r2 = LD16((r3 + 4));
    ST16(0x060896DC, r2);
    r3 = LD32(r14);
    r2 = LD16((r3 + 4));
    ST16(0x060896DE, r2);
    r3 = LD16(0x060896D6);
    r7 = LD16(0x060896DA);
    r2 = ((r3 & 0xFFFF) + (r7 & 0xFFFF)) + ((r3 & 0xFFFF) + (r7 & 0xFFFF));
    r3 = LD16(0x060896DE);
    ST16((r14 + 4), ((r2 + r3) + 1));
    r2 = LD16((r14 + 4));
    ST16(0x060896EC, (0x4000 - r2));
    r3 = LD32(0x060896C4);
    ST32(0x060896F4, (r3 + 32));
    r7 = LD16(0x060896D6);
    r2 = LD32(0x060896F4);
    ST32(0x060896FC, (((r7 & 0xFFFF) * 32) + r2));
    r7 = LD16(0x060896DA);
    r2 = LD32(0x060896FC);
    ST32(0x06089704, (((r7 & 0xFFFF) * 32) + r2));
    r7 = LD16(0x060896D6);
    r2 = LD32(0x06089704);
    ST32(0x0608970C, (((r7 & 0xFFFF) * 32) + r2));
    r7 = LD16(0x060896DA);
    r2 = LD32(0x0608970C);
    ST32(0x060896E0, (((r7 & 0xFFFF) * 32) + r2));
    r3 = LD16(0x060896DE);
    r1 = LD32(0x060896E0);
    ST32(r14 + 8, (((r3 & 0xFFFF) * 32) + r1));
    r2 = LD32(r14 + 8);
    ST32(0x060896E8, r2);
    ST16(0x060896F8, 4);
    r7 = LD16(0x060896D6);
    r2 = LD16(0x060896F8);
    ST16(0x06089700, (r2 + ((r7 & 0xFFFF) << 2)));
    r7 = LD16(0x060896DA);
    r2 = LD16(0x06089700);
    ST16(0x06089708, (r2 + ((r7 & 0xFFFF) << 2)));
    r7 = LD16(0x060896D6);
    r2 = LD16(0x06089708);
    ST16(0x06089710, (r2 + ((r7 & 0xFFFF) << 2)));
    r7 = LD16(0x060896DA);
    r2 = LD16(0x06089710);
    ST16(0x060896E4, (r2 + ((r7 & 0xFFFF) << 2)));
    r0 = GCALL0(0x060682E8);
    r3 = LD32(0x060896C4);
    ST32(0x060896CC, r3);
    r1 = LD32(0x060896CC);
    ST16(r1, -32768);
    r2 = LD32(r14);
    r3 = LD32(r2 + 16);
    ST32(0x0608EFD8, r3);
    r2 = LD32(r14);
    r3 = LD32(r2 + 24);
    ST32(0x0608F020, r3);
    r2 = LD32(r14);
    r3 = LD32(r2 + 20);
    ST32(0x0608EFEC, r3);
    r2 = LD32(r14);
    r3 = LD32(r2 + 28);
    ST32(0x0608F010, r3);
    r3 = LD32(r14);
    r2 = LD16((r3 + 8));
    ST32(0x0608F008, (r2 & 0xFFFF));
    r3 = LD32(r14);
    r2 = LD16((r3 + 2));
    ST32(0x0608EFE0, (r2 & 0xFFFF));
    r2 = LD32(r14);
    r3 = LD32(r2 + 32);
    ST32(0x0608EFF0, r3);
    ST32(0x0608F000, 0);
    r2 = LD32(0x0608F008);
    r3 = LD32(0x0608EFEC);
    r0 = GCALL3(0x0604B3F0, r3, 255, (r2 << 2));
    r2 = LD32(0x0608F010);
    if (!((r2 & r2) == 0)) {
        r2 = LD32(0x0608F008);
        r3 = LD32(0x0608F010);
        r0 = GCALL3(0x0604B3F0, r3, 255, (r2 << 2));
    }
    r3 = LD16(0x060896E4);
    ST16(0x0608EFF4, r3);
    ST32(0x060896C8, 0);
    ST32(0x0608F004, 4);
    r0 = GCALL1(0x06067EF0, 0x8000);
    ST32(0x0608F024, 0);
    ST32(0x0608EFE8, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067E40(int r4, int r5, int r6)
{
    int r0, r2, r3, r7, r14;
    FRAME(sp, 48);

    r14 = sp - 48;
    ST16(r14, r4);
    ST16((r14 + 2), r5);
    ST32(r14 + 8, (r14 + 4));
    r0 = LD32(r14 + 8);
    ST16(r0, r6);
    r3 = LD16((r14 + 4));
    r7 = LD16((r14 + 2));
    r2 = r7 & 0xFFFF;
    r7 = LD16(r14);
    ST32(r14 + 12, 0x06069FA8);
    r0 = LD32(r14 + 12);
    r0 = GCALL4(r0, (r7 & 0xFFFF), r2, (r3 & 0xFFFF), r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067EB4(int r4)
{
    int r0, r2, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    ST16(r14, r4);
    r2 = LD16(r14);
    ST16(0x0608971A, r2);
    r2 = LD16(r14);
    r0 = GCALL1(0x060621C4, (r2 & 0xFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067EF0(int r4)
{
    int r0, r1, r2, r3, r14;
    FRAME(sp, 24);

    r14 = sp - 20;
    ST16(r14, r4);
    r1 = LD16(0x0608F43E);
    r2 = (r1 - 1) & 0xFFFF;
    r3 = LD16(r14);
    r1 = r3 & 0xFFFF;
    r3 = LD16(0x0608F432);
    ST32((sp - 24), ((r3 - 1) & 0xFFFF));
    r0 = GCALL5(0x0606A158, r1, 0, 0, r2, LD32((sp - 24)));
    r2 = LD16(r14);
    ST16(0x06089718, r2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067F58(int r4, int r5)
{
    int r0, r1, r3, r7, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    ST32(r14 + 4, r5);
    ST16(r14, r4);
    r1 = LD32(r14 + 4);
    r7 = LD16(r14);
    r3 = ((r7 & 0xFFFF) << 2) + ((r7 & 0xFFFF) << 2);
    r7 = LD32(0x0608EFF0);
    r0 = GCALL3(0x0604B358, (r3 + r7), r1, 8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067FFC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r13, r14;
    FRAME(sp, 124);

    r14 = sp - 124;
    ST32((88 + r14), r7);
    r13 = LD32((124 + r14));
    ST32((84 + r14), r13);
    ST16(r14, r4);
    ST32((80 + r14), r14);
    ST32(r14 + 40, (r14 + 2));
    r13 = LD32(r14 + 40);
    ST16(r13, r5);
    ST32(r14 + 44, r14);
    ST32(r14 + 48, (r14 + 4));
    r9 = LD32(r14 + 48);
    ST16(r9, r6);
    ST32(r14 + 52, r14);
    ST32(r14 + 56, (r14 + 6));
    r9 = LD16((90 + r14));
    r8 = LD32(r14 + 56);
    ST16(r8, r9);
    ST32(r14 + 60, r14);
    ST32((64 + r14), (r14 + 8));
    r8 = LD16((86 + r14));
    r13 = LD32((64 + r14));
    ST16(r13, r8);
    r2 = LD16(r14);
    r1 = LD32(0x0608F014);
    ST32(r14 + 12, (((r2 & 0xFFFF) * 10) + r1));
    r1 = LD16((r14 + 6));
    r2 = LD16((r14 + 8));
    ST32(r14 + 16, ((r1 & 0xFFFF) * (r2 & 0xFFFF)));
    ST32(r14 + 24, 1);
    r3 = LD16((r14 + 2));
    if (!((unsigned)(r3 & 0xFFFF) > (unsigned)39)) {
        r3 = LD16((r14 + 2));
        if ((unsigned)(r3 & 0xFFFF) > (unsigned)8) {
            r1 = LD32(r14 + 16);
            ST32(r14 + 20, r1);
        } else {
            r2 = LD32(r14 + 16);
            ST32(r14 + 20, ((int)((unsigned)r2 >> 1)));
        }
    } else {
        r1 = LD32(r14 + 16);
        ST32(r14 + 20, (r1 + r1));
    }
    r2 = LD32(r14 + 20);
    ST32(r14 + 20, ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r2 + 31) >> 2)) >> 1)) >> 2)));
    r1 = LD32(r14 + 12);
    r2 = LD16(r1);
    if (!(((r2 & 0xFFFF) & (r2 & 0xFFFF)) == 0)) {
        r2 = LD32(r14 + 12);
        r3 = LD16((r2 + 8));
        r2 = LD32(r14 + 20);
        if (!((unsigned)r2 > (unsigned)(r3 & 0xFFFF))) {
            r1 = LD32(r14 + 12);
            r2 = LD16(r1);
            ST32(r14 + 32, (((r2 & 0xFFFF) << 2) + ((r2 & 0xFFFF) << 2)));
            r2 = LD32(0x060896C4);
            r1 = LD32(r14 + 32);
            ST32(r14 + 36, (r2 + r1));
            r1 = LD32((128 + r14));
            if (!((r1 & r1) == 0)) {
                r2 = LD32(r14 + 20);
                r1 = ((r2 << 2) + (r2 << 2)) << 2;
                r2 = LD32((128 + r14));
                r3 = LD32(r14 + 36);
                ST32((72 + r14), 0x06069CC8);
                r13 = LD32((72 + r14));
                r0 = GCALL3(r13, r3, r2, r1);
                ST32((76 + r14), 0x06069DD4);
                r13 = LD32((76 + r14));
                r0 = GCALL0(r13);
            }
            r1 = LD32(r14 + 12);
            r2 = LD16((r14 + 2));
            ST16((r1 + 4), r2);
            r1 = LD32(r14 + 12);
            r2 = LD16((r14 + 4));
            ST16((r1 + 6), r2);
            r1 = LD32(r14 + 12);
            r7 = LD16((r14 + 6));
            r3 = LD16((r14 + 8));
            ST16((r1 + 2), (((r7 & 0xFFFF) * 32) + r3));
        } else {
            ST32(r14 + 24, 0);
        }
    } else {
        r3 = LD16((r14 + 22));
        ST32((68 + r14), 0x0606966C);
        r8 = LD32((68 + r14));
        r0 = GCALL4(r8, (r3 & 0xFFFF), r5, r6, r7);
        r2 = r14 + 28;
        ST16(r2, r0);
        r2 = LD16(r2);
        if (((r2 & 0xFFFF) & (r2 & 0xFFFF)) == 0) {
            ST32(r14 + 24, 0);
        } else {
            r1 = LD32(r14 + 12);
            r2 = LD16((r14 + 28));
            ST16(r1, r2);
            r1 = LD32(r14 + 12);
            r2 = LD16((r14 + 22));
            ST16((r1 + 8), r2);
            r2 = LD32(r14 + 12);
            r3 = LD16((r2 + 8));
            r2 = LD32(r14 + 20);
            if (!((unsigned)r2 > (unsigned)(r3 & 0xFFFF))) {
                r1 = LD32(r14 + 12);
                r2 = LD16(r1);
                ST32(r14 + 32, (((r2 & 0xFFFF) << 2) + ((r2 & 0xFFFF) << 2)));
                r2 = LD32(0x060896C4);
                r1 = LD32(r14 + 32);
                ST32(r14 + 36, (r2 + r1));
                r1 = LD32((128 + r14));
                if (!((r1 & r1) == 0)) {
                    r2 = LD32(r14 + 20);
                    r1 = ((r2 << 2) + (r2 << 2)) << 2;
                    r2 = LD32((128 + r14));
                    r3 = LD32(r14 + 36);
                    ST32((72 + r14), 0x06069CC8);
                    r13 = LD32((72 + r14));
                    r0 = GCALL3(r13, r3, r2, r1);
                    ST32((76 + r14), 0x06069DD4);
                    r13 = LD32((76 + r14));
                    r0 = GCALL0(r13);
                }
                r1 = LD32(r14 + 12);
                r2 = LD16((r14 + 2));
                ST16((r1 + 4), r2);
                r1 = LD32(r14 + 12);
                r2 = LD16((r14 + 4));
                ST16((r1 + 6), r2);
                r1 = LD32(r14 + 12);
                r7 = LD16((r14 + 6));
                r3 = LD16((r14 + 8));
                ST16((r1 + 2), (((r7 & 0xFFFF) * 32) + r3));
            } else {
                ST32(r14 + 24, 0);
            }
        }
    }
    r0 = LD32(r14 + 24);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06068240(int r4)
{
    int r0, r1, r2, r3, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    ST16(r14, r4);
    r2 = LD16(r14);
    r1 = (((r2 & 0xFFFF) << 2) + (r2 & 0xFFFF)) + (((r2 & 0xFFFF) << 2) + (r2 & 0xFFFF));
    r2 = LD32(0x0608F014);
    r2 = LD16((r1 + r2));
    if (!(((r2 & 0xFFFF) & (r2 & 0xFFFF)) == 0)) {
        r2 = LD16(r14);
        r1 = (((r2 & 0xFFFF) << 2) + (r2 & 0xFFFF)) + (((r2 & 0xFFFF) << 2) + (r2 & 0xFFFF));
        r2 = LD32(0x0608F014);
        r3 = LD16(((r1 + r2) + 8));
        r1 = r3 & 0xFFFF;
        r3 = LD16(r14);
        r2 = (((r3 & 0xFFFF) << 2) + (r3 & 0xFFFF)) + (((r3 & 0xFFFF) << 2) + (r3 & 0xFFFF));
        r3 = LD32(0x0608F014);
        r3 = LD16((r2 + r3));
        r0 = GCALL2(0x06069780, (r3 & 0xFFFF), r1);
        r2 = LD16(r14);
        r1 = (((r2 & 0xFFFF) << 2) + (r2 & 0xFFFF)) + (((r2 & 0xFFFF) << 2) + (r2 & 0xFFFF));
        r2 = LD32(0x0608F014);
        ST16((r1 + r2), 0);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060682E8(void)
{
    int r1, r2, r3, r14;
    FRAME(sp, 8);

    r14 = sp - 8;
    ST32(r14, 0);
    while (1) {
        r2 = LD32(r14);
        r1 = LD32(0x0608EFFC);
        if (!(r2 >= r1)) {
            r1 = LD32(r14);
            r2 = LD32(0x0608F014);
            ST16(((((r1 << 2) + r1) + ((r1 << 2) + r1)) + r2), 0);
            r2 = LD32(r14);
            ST32(r14, (r2 + 1));
            POLL();
            continue;
        } else {
            break;
        }
        POLL();
    }
    r2 = LD16(0x060896EC);
    if (((r2 & 0xFFFF) & (r2 & 0xFFFF)) == 0) {
        ST32(0x06089714, 0);
    } else {
        r3 = LD32(0x060896E8);
        ST32(0x06089714, r3);
        r1 = LD32(0x06089714);
        ST32(r1, 0);
        r3 = LD32(0x06089714);
        r1 = r3 + 4;
        r3 = LD16(0x060896EC);
        ST16(r1, r3);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606837C(int r4)
{
    int r0, r2, r3, r14;
    FRAME(sp, 8);

    r14 = sp - 8;
    ST16(r14, r4);
    r3 = LD32(0x060896C8);
    r2 = LD16(((((r3 << 2) << 2) + 0x060896F4) + 12));
    r3 = LD16(r14);
    r0 = (r2 + r3) & 0xFFFF;
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060683BC(int r4)
{
    int r0, r2, r7, r14;
    FRAME(sp, 8);

    r14 = sp - 8;
    ST16(r14, r4);
    r7 = LD16(r14);
    r2 = LD16(0x060896E4);
    r0 = (r2 + ((r7 & 0xFFFF) << 2)) & 0xFFFF;
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060683F0(int r4)
{
    int r0, r2, r3, r14;
    FRAME(sp, 8);

    r14 = sp - 8;
    ST16(r14, r4);
    r3 = LD16(r14);
    r2 = (((r3 & 0xFFFF) << 2) + (r3 & 0xFFFF)) + (((r3 & 0xFFFF) << 2) + (r3 & 0xFFFF));
    r3 = LD32(0x0608F014);
    r3 = LD16((r2 + r3));
    r0 = r3 & 0xFFFF;
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06068428(int r4)
{
    int r1, r2, r3, r7, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, r4);
    r2 = LD32(0x06089714);
    ST32(r14 + 4, r2);
    ST16((r14 + 8), 0);
    ST16((r14 + 10), 0);
    while (1) {
        r1 = LD32(r14 + 4);
        if (!((r1 & r1) == 0)) {
            r2 = LD32(r14 + 4);
            r3 = LD16((r14 + 8));
            r1 = r3 & 0xFFFF;
            r3 = LD16((r2 + 4));
            if (!((unsigned)r1 >= (unsigned)(r3 & 0xFFFF))) {
                r3 = LD32(r14 + 4);
                r2 = LD16((r3 + 4));
                ST16((r14 + 8), r2);
            }
            r7 = LD32(r14 + 4);
            r2 = LD16((r14 + 10));
            r3 = LD16((r7 + 4));
            ST16((r14 + 10), (r2 + r3));
            r1 = LD32(r14 + 4);
            r2 = LD32(r1);
            ST32(r14 + 4, r2);
            POLL();
            continue;
        } else {
            break;
        }
        POLL();
    }
    r1 = LD32(r14);
    r2 = LD16((r14 + 10));
    ST16((r1 + 12), r2);
    r1 = LD32(r14);
    r2 = LD16((r14 + 8));
    ST16((r1 + 14), r2);
    r1 = LD32(r14);
    r3 = LD16(0x060896D4);
    ST16(r1, r3);
    r1 = LD32(r14);
    r3 = LD16(0x060896D8);
    ST16((r1 + 2), r3);
    r1 = LD32(r14);
    r3 = LD16(0x060896DC);
    ST16((r1 + 4), r3);
    r1 = LD32(r14);
    r2 = LD16(0x0608EFFE);
    ST16((r1 + 6), r2);
    r1 = LD32(r14);
    r2 = LD16(0x0608F00A);
    ST16((r1 + 8), r2);
    r1 = LD32(r14);
    r2 = LD16(0x0608F006);
    ST16((r1 + 10), r2);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06068538(int r4)
{
    int r2, r3, r7, r14;
    FRAME(sp, 12);

    r14 = sp - 12;
    ST16(r14, r4);
    ST32(0x0608EFDC, 1);
    r7 = LD32(0x060896C8);
    ST32(0x060896C8, (1 ^ r7));
    ST32(0x0608F004, 4);
    r3 = LD16(r14);
    ST32(0x0608F000, (r3 & 0xFFFF));
    r7 = LD32(0x060896C8);
    r7 = LD32((((r7 << 2) << 2) + 0x060896F4));
    ST32(0x0608EFF8, r7);
    r7 = LD32(0x060896C8);
    r3 = LD16(((((r7 << 2) << 2) + 0x060896F4) + 4));
    ST16(0x0608F018, r3);
    r7 = LD32(0x060896C8);
    r3 = LD16(((((r7 << 2) << 2) + 0x060896F4) + 12));
    ST16(0x0608971C, r3);
    r7 = LD32(0x060896C8);
    r7 = LD32((((r7 << 2) << 2) + 0x060896F4) + 8);
    ST32(0x06089720, r7);
    r7 = LD32(0x0608F004);
    r2 = LD32(0x0608EFF8);
    ST32(r14 + 4, ((r7 * 32) + r2));
    r2 = LD32(r14 + 4);
    ST16(r2, 0x4000);
    r7 = LD32(0x0608F004);
    ST32(0x0608F004, (r7 + 1));
    r7 = LD32(0x0608EFD8);
    ST32(0x060896BC, r7);
    r7 = LD32(0x0608F020);
    ST32(0x060896C0, r7);
    ST32(0x0608F01C, 0);
    ST32(0x0608F00C, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060688C0(int r4, int r5)
{
    int r0, r1, r2, r3, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    ST32(r14, r4);
    ST32(r14 + 4, r5);
    r4 = LD32(r14);
    r0 = GCALL1(0x0606CDAC, r4);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 8, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 8);
    ST16(r1, 0x100A);
    r1 = LD32(r14 + 8);
    r2 = LD32(r14 + 4);
    r3 = LD16(r2);
    ST16((r1 + 12), r3);
    r1 = LD32(r14 + 8);
    r3 = LD32(r14 + 4);
    r2 = LD16((r3 + 2));
    ST16((r1 + 14), r2);
    r2 = LD32(r14 + 4);
    r3 = LD16(r2);
    ST32(0x0608EFE8, r3);
    r3 = LD32(r14 + 4);
    r2 = LD16((r3 + 2));
    ST32(0x0608F024, r2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606894C(int r4, int r5)
{
    int r0, r1, r2, r3, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    ST32(r14, r4);
    ST32(r14 + 4, r5);
    r4 = LD32(r14);
    r0 = GCALL1(0x0606CDAC, r4);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 8, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 8);
    ST16(r1, 0x1009);
    r1 = LD32(r14 + 8);
    r2 = LD32(r14 + 4);
    r3 = LD16(r2);
    ST16((r1 + 20), r3);
    r1 = LD32(r14 + 8);
    r3 = LD32(r14 + 4);
    r2 = LD16((r3 + 2));
    ST16((r1 + 22), r2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060689BC(int r4, int r5)
{
    int r0, r1, r2, r3, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    ST32(r14, r4);
    ST32(r14 + 4, r5);
    r4 = LD32(r14);
    r0 = GCALL1(0x0606CDAC, r4);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 8, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 8);
    ST16(r1, 0x1008);
    r1 = LD32(r14 + 8);
    r2 = LD32(r14 + 4);
    r3 = LD16(r2);
    ST16((r1 + 12), r3);
    r1 = LD32(r14 + 8);
    r3 = LD32(r14 + 4);
    r2 = LD16((r3 + 2));
    ST16((r1 + 14), r2);
    r1 = LD32(r14 + 8);
    r3 = LD32(r14 + 4);
    r3 = LD16((r3 + 4));
    ST16((r1 + 20), r3);
    r1 = LD32(r14 + 8);
    r2 = LD32(r14 + 4);
    r2 = LD16(((r2 + 4) + 2));
    ST16((r1 + 22), r2);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06068A50(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r14;
    FRAME(sp, 72);

    r14 = sp - 72;
    ST32(r14, r4);
    ST32(r14 + 8, r7);
    r8 = LD32((72 + r14));
    ST32(r14 + 20, (r14 + 4));
    r0 = LD32(r14 + 20);
    ST16(r0, r5);
    ST32(r14 + 24, (r14 + 6));
    r0 = LD32(r14 + 24);
    ST16(r0, r6);
    ST32(r14 + 28, (r14 + 12));
    r0 = LD32(r14 + 28);
    ST16(r0, r8);
    r4 = LD32(r14);
    ST32(r14 + 32, 0x0606CDAC);
    r0 = LD32(r14 + 32);
    r0 = GCALL4(r0, r4, r5, r6, r7);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 16, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 16);
    ST16(r1, 0x1006);
    r1 = LD32(r14 + 16);
    r2 = LD16((r14 + 4));
    ST16((r1 + 4), r2);
    r1 = LD16((r14 + 4));
    ST32(r14 + 36, ((56 & r1) & 0xFFFF));
    r0 = LD32(r14 + 36);
    if (!(r0 == 8)) {
        r1 = LD32(r14 + 16);
        r2 = LD16((r14 + 6));
        ST16((r1 + 6), r2);
    } else {
        r1 = LD32(r14 + 16);
        r6 = LD16((r14 + 6));
        r2 = LD16(0x060896E4);
        ST16((r1 + 6), (r2 + ((r6 & 0xFFFF) << 2)));
    }
    r1 = LD32(r14 + 16);
    r2 = LD32(r14 + 8);
    r3 = LD16(r2);
    ST16((r1 + 12), r3);
    r1 = LD32(r14 + 16);
    r3 = LD32(r14 + 8);
    r2 = LD16((r3 + 2));
    ST16((r1 + 14), r2);
    r1 = LD32(r14 + 16);
    r3 = LD32(r14 + 8);
    r3 = LD16((r3 + 4));
    ST16((r1 + 16), r3);
    r1 = LD32(r14 + 16);
    r2 = LD32(r14 + 8);
    r2 = LD16(((r2 + 4) + 2));
    ST16((r1 + 18), r2);
    r3 = LD16((r14 + 12));
    if (!((r3 & 0xFFFF) == 0xFFFF)) {
        r1 = LD32(r14 + 16);
        r2 = LD16(0x0608971C);
        r3 = LD16((r14 + 12));
        ST16((r1 + 28), (r2 + r3));
    } else {
        r2 = LD32(r14 + 16);
        ST16((r2 + 28), 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06068BC4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r14;
    FRAME(sp, 76);

    r14 = sp - 76;
    ST32(r14, r4);
    ST32(r14 + 8, r7);
    r8 = LD32((76 + r14));
    ST32(r14 + 20, (r14 + 4));
    r0 = LD32(r14 + 20);
    ST16(r0, r5);
    ST32(r14 + 24, (r14 + 6));
    r0 = LD32(r14 + 24);
    ST16(r0, r6);
    ST32(r14 + 28, (r14 + 12));
    r0 = LD32(r14 + 28);
    ST16(r0, r8);
    r4 = LD32(r14);
    ST32(r14 + 32, 0x0606CDAC);
    r0 = LD32(r14 + 32);
    r0 = GCALL4(r0, r4, r5, r6, r7);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 16, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 16);
    ST16(r1, 0x1005);
    r1 = LD32(r14 + 16);
    r2 = LD16((r14 + 4));
    ST16((r1 + 4), r2);
    r1 = LD16((r14 + 4));
    ST32(r14 + 40, ((56 & r1) & 0xFFFF));
    r0 = LD32(r14 + 40);
    if (!(r0 == 8)) {
        r1 = LD32(r14 + 16);
        r2 = LD16((r14 + 6));
        ST16((r1 + 6), r2);
    } else {
        r1 = LD32(r14 + 16);
        r6 = LD16((r14 + 6));
        r2 = LD16(0x060896E4);
        ST16((r1 + 6), (r2 + ((r6 & 0xFFFF) << 2)));
    }
    r1 = LD32(r14 + 8);
    r3 = LD32(r14 + 16);
    ST32(r14 + 36, 0x0606CD9A);
    r0 = LD32(r14 + 36);
    r0 = GCALL3(r0, (r3 + 12), r1, 8);
    r3 = LD16((r14 + 12));
    if (!((r3 & 0xFFFF) == 0xFFFF)) {
        r1 = LD32(r14 + 16);
        r2 = LD16(0x0608971C);
        r3 = LD16((r14 + 12));
        ST16((r1 + 28), (r2 + r3));
    } else {
        r2 = LD32(r14 + 16);
        ST16((r2 + 28), 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06068D14(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r14;
    FRAME(sp, 76);

    r14 = sp - 76;
    ST32(r14, r4);
    ST32(r14 + 8, r7);
    r8 = LD32((76 + r14));
    ST32(r14 + 20, (r14 + 4));
    r0 = LD32(r14 + 20);
    ST16(r0, r5);
    ST32(r14 + 24, (r14 + 6));
    r0 = LD32(r14 + 24);
    ST16(r0, r6);
    ST32(r14 + 28, (r14 + 12));
    r0 = LD32(r14 + 28);
    ST16(r0, r8);
    r4 = LD32(r14);
    ST32(r14 + 32, 0x0606CDAC);
    r0 = LD32(r14 + 32);
    r0 = GCALL4(r0, r4, r5, r6, r7);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 16, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 16);
    ST16(r1, 0x1004);
    r1 = LD32(r14 + 16);
    r2 = LD16((r14 + 4));
    ST16((r1 + 4), r2);
    r1 = LD16((r14 + 4));
    ST32(r14 + 40, ((56 & r1) & 0xFFFF));
    r0 = LD32(r14 + 40);
    if (!(r0 == 8)) {
        r1 = LD32(r14 + 16);
        r2 = LD16((r14 + 6));
        ST16((r1 + 6), r2);
    } else {
        r1 = LD32(r14 + 16);
        r6 = LD16((r14 + 6));
        r2 = LD16(0x060896E4);
        ST16((r1 + 6), (r2 + ((r6 & 0xFFFF) << 2)));
    }
    r1 = LD32(r14 + 8);
    r3 = LD32(r14 + 16);
    ST32(r14 + 36, 0x0606CD9A);
    r0 = LD32(r14 + 36);
    r0 = GCALL3(r0, (r3 + 12), r1, 8);
    r3 = LD16((r14 + 12));
    if (!((r3 & 0xFFFF) == 0xFFFF)) {
        r1 = LD32(r14 + 16);
        r2 = LD16(0x0608971C);
        r3 = LD16((r14 + 12));
        ST16((r1 + 28), (r2 + r3));
    } else {
        r2 = LD32(r14 + 16);
        ST16((r2 + 28), 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06068E64(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r14;
    FRAME(sp, 96);

    r14 = sp - 96;
    ST32(r14, r4);
    r9 = LD32((96 + r14));
    r8 = LD32((104 + r14));
    ST32(r14 + 20, (r14 + 4));
    r0 = LD32(r14 + 20);
    ST16(r0, r5);
    ST32(r14 + 24, r14);
    ST32(r14 + 28, (r14 + 6));
    r0 = LD32(r14 + 28);
    ST16(r0, r6);
    ST32(r14 + 32, r14);
    ST32(r14 + 36, (r14 + 8));
    r0 = LD32(r14 + 36);
    ST16(r0, r7);
    ST32(r14 + 40, r14);
    ST32(r14 + 44, (r14 + 10));
    r0 = LD32(r14 + 44);
    ST16(r0, r9);
    ST32(r14 + 48, r14);
    ST32(r14 + 52, (r14 + 12));
    r0 = LD32(r14 + 52);
    ST16(r0, r8);
    r4 = LD32(r14);
    ST32(r14 + 56, 0x0606CDAC);
    r0 = LD32(r14 + 56);
    r0 = GCALL4(r0, r4, r5, r6, r7);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 16, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 16);
    r2 = LD16((r14 + 4));
    ST16(r1, (r2 | 0x1000));
    r1 = LD32(r14 + 16);
    r7 = LD16((r14 + 10));
    r3 = LD32(0x0608F014);
    r3 = LD16((((((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF)) + (((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF))) + r3));
    ST16((r1 + 8), r3);
    r1 = LD32(r14 + 16);
    r7 = LD16((r14 + 10));
    r3 = LD32(0x0608F014);
    r2 = LD16(((((((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF)) + (((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF))) + r3) + 2));
    ST16((r1 + 10), r2);
    r2 = LD16((r14 + 6));
    r6 = LD16((r14 + 10));
    r7 = LD32(0x0608F014);
    r3 = LD16(((((((r6 & 0xFFFF) << 2) + (r6 & 0xFFFF)) + (((r6 & 0xFFFF) << 2) + (r6 & 0xFFFF))) + r7) + 4));
    ST16((r14 + 6), ((r2 & 0xFFC7) | r3));
    r1 = LD32(r14 + 16);
    r2 = LD16((r14 + 6));
    ST16((r1 + 4), r2);
    r3 = LD16((r14 + 8));
    if ((r3 & 0xFFFF) == 0xFFFF) {
        r7 = LD16((r14 + 10));
        r3 = LD32(0x0608F014);
        r2 = LD16(((((((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF)) + (((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF))) + r3) + 6));
        ST16((r14 + 8), r2);
    }
    r1 = LD16((r14 + 6));
    ST32(r14 + 60, ((56 & r1) & 0xFFFF));
    r0 = LD32(r14 + 60);
    if (!(r0 == 8)) {
        r1 = LD32(r14 + 16);
        r2 = LD16((r14 + 8));
        ST16((r1 + 6), r2);
    } else {
        r1 = LD32(r14 + 16);
        r6 = LD16((r14 + 8));
        r2 = LD16(0x060896E4);
        ST16((r1 + 6), (r2 + ((r6 & 0xFFFF) << 2)));
    }
    r1 = LD32(r14 + 16);
    r2 = LD32((100 + r14));
    r3 = LD16(r2);
    ST16((r1 + 12), r3);
    r1 = LD32(r14 + 16);
    r0 = 100 + r14;
    r3 = LD32(r0);
    r2 = LD16((r3 + 2));
    ST16((r1 + 14), r2);
    r3 = LD16((r14 + 12));
    if (!((r3 & 0xFFFF) == 0xFFFF)) {
        r1 = LD32(r14 + 16);
        r2 = LD16(0x0608971C);
        r3 = LD16((r14 + 12));
        ST16((r1 + 28), (r2 + r3));
    } else {
        r2 = LD32(r14 + 16);
        ST16((r2 + 28), 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060690BC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r14;
    FRAME(sp, 96);

    r14 = sp - 96;
    ST32(r14, r4);
    r9 = LD32((96 + r14));
    r8 = LD32((104 + r14));
    ST32(r14 + 20, (r14 + 4));
    r0 = LD32(r14 + 20);
    ST16(r0, r5);
    ST32(r14 + 24, r14);
    ST32(r14 + 28, (r14 + 6));
    r0 = LD32(r14 + 28);
    ST16(r0, r6);
    ST32(r14 + 32, r14);
    ST32(r14 + 36, (r14 + 8));
    r0 = LD32(r14 + 36);
    ST16(r0, r7);
    ST32(r14 + 40, r14);
    ST32(r14 + 44, (r14 + 10));
    r0 = LD32(r14 + 44);
    ST16(r0, r9);
    ST32(r14 + 48, r14);
    ST32(r14 + 52, (r14 + 12));
    r0 = LD32(r14 + 52);
    ST16(r0, r8);
    r4 = LD32(r14);
    ST32(r14 + 56, 0x0606CDAC);
    r0 = LD32(r14 + 56);
    r0 = GCALL4(r0, r4, r5, r6, r7);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 16, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 16);
    r2 = LD16((r14 + 4));
    ST16(r1, (r2 | 0x1001));
    r1 = LD32(r14 + 16);
    r7 = LD16((r14 + 10));
    r3 = LD32(0x0608F014);
    r3 = LD16((((((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF)) + (((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF))) + r3));
    ST16((r1 + 8), r3);
    r1 = LD32(r14 + 16);
    r7 = LD16((r14 + 10));
    r3 = LD32(0x0608F014);
    r2 = LD16(((((((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF)) + (((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF))) + r3) + 2));
    ST16((r1 + 10), r2);
    r2 = LD16((r14 + 6));
    r6 = LD16((r14 + 10));
    r7 = LD32(0x0608F014);
    r3 = LD16(((((((r6 & 0xFFFF) << 2) + (r6 & 0xFFFF)) + (((r6 & 0xFFFF) << 2) + (r6 & 0xFFFF))) + r7) + 4));
    ST16((r14 + 6), ((r2 & 0xFFC7) | r3));
    r1 = LD32(r14 + 16);
    r2 = LD16((r14 + 6));
    ST16((r1 + 4), r2);
    r3 = LD16((r14 + 8));
    if ((r3 & 0xFFFF) == 0xFFFF) {
        r7 = LD16((r14 + 10));
        r3 = LD32(0x0608F014);
        r2 = LD16(((((((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF)) + (((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF))) + r3) + 6));
        ST16((r14 + 8), r2);
    }
    r1 = LD16((r14 + 6));
    ST32(r14 + 60, ((56 & r1) & 0xFFFF));
    r0 = LD32(r14 + 60);
    if (!(r0 == 8)) {
        r1 = LD32(r14 + 16);
        r2 = LD16((r14 + 8));
        ST16((r1 + 6), r2);
    } else {
        r1 = LD32(r14 + 16);
        r6 = LD16((r14 + 8));
        r2 = LD16(0x060896E4);
        ST16((r1 + 6), (r2 + ((r6 & 0xFFFF) << 2)));
    }
    r1 = LD16((r14 + 4));
    if ((((r1 & 0xF00) & 0xFFFF) & ((r1 & 0xF00) & 0xFFFF)) == 0) {
        r1 = LD32(r14 + 16);
        r2 = LD32((100 + r14));
        r3 = LD16(r2);
        ST16((r1 + 12), r3);
        r1 = LD32(r14 + 16);
        r3 = LD32((100 + r14));
        r2 = LD16((r3 + 2));
        ST16((r1 + 14), r2);
        r1 = LD32(r14 + 16);
        r3 = LD32((100 + r14));
        r3 = LD16((r3 + 4));
        ST16((r1 + 20), r3);
        r1 = LD32(r14 + 16);
        r0 = 100 + r14;
        r2 = LD32(r0);
        r2 = LD16(((r2 + 4) + 2));
        ST16((r1 + 22), r2);
    } else {
        r1 = LD32(r14 + 16);
        r2 = LD32((100 + r14));
        r3 = LD16(r2);
        ST16((r1 + 12), r3);
        r1 = LD32(r14 + 16);
        r3 = LD32((100 + r14));
        r2 = LD16((r3 + 2));
        ST16((r1 + 14), r2);
        r1 = LD32(r14 + 16);
        r3 = LD32((100 + r14));
        r3 = LD16((r3 + 4));
        ST16((r1 + 16), r3);
        r1 = LD32(r14 + 16);
        r0 = 100 + r14;
        r2 = LD32(r0);
        r2 = LD16(((r2 + 4) + 2));
        ST16((r1 + 18), r2);
    }
    r3 = LD16((r14 + 12));
    if (!((r3 & 0xFFFF) == 0xFFFF)) {
        r1 = LD32(r14 + 16);
        r2 = LD16(0x0608971C);
        r3 = LD16((r14 + 12));
        ST16((r1 + 28), (r2 + r3));
    } else {
        r2 = LD32(r14 + 16);
        ST16((r2 + 28), 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060693AC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r13, r14;
    FRAME(sp, 104);

    r14 = sp - 104;
    ST32(r14, r4);
    r9 = LD32((104 + r14));
    r8 = LD32((112 + r14));
    ST32((68 + r14), r14);
    ST32(r14 + 20, (r14 + 4));
    r0 = LD32(r14 + 20);
    ST16(r0, r5);
    ST32(r14 + 24, r14);
    ST32(r14 + 28, (r14 + 6));
    r0 = LD32(r14 + 28);
    ST16(r0, r6);
    ST32(r14 + 32, r14);
    ST32(r14 + 36, (r14 + 8));
    r0 = LD32(r14 + 36);
    ST16(r0, r7);
    ST32(r14 + 40, r14);
    ST32(r14 + 44, (r14 + 10));
    r0 = LD32(r14 + 44);
    ST16(r0, r9);
    ST32(r14 + 48, r14);
    ST32(r14 + 52, (r14 + 12));
    r0 = LD32(r14 + 52);
    ST16(r0, r8);
    r4 = LD32(r14);
    ST32(r14 + 56, 0x0606CDAC);
    r0 = LD32(r14 + 56);
    r0 = GCALL4(r0, r4, r5, r6, r7);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 16, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 16);
    r2 = LD16((r14 + 4));
    ST16(r1, (r2 | 0x1002));
    r1 = LD32(r14 + 16);
    r7 = LD16((r14 + 10));
    r3 = LD32(0x0608F014);
    r3 = LD16((((((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF)) + (((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF))) + r3));
    ST16((r1 + 8), r3);
    r1 = LD32(r14 + 16);
    r7 = LD16((r14 + 10));
    r3 = LD32(0x0608F014);
    r2 = LD16(((((((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF)) + (((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF))) + r3) + 2));
    ST16((r1 + 10), r2);
    r2 = LD16((r14 + 6));
    r6 = LD16((r14 + 10));
    r7 = LD32(0x0608F014);
    r7 = (((((r6 & 0xFFFF) << 2) + (r6 & 0xFFFF)) + (((r6 & 0xFFFF) << 2) + (r6 & 0xFFFF))) + r7) + 4;
    r3 = LD16(r7);
    ST16((r14 + 6), ((r2 & 0xFFC7) | r3));
    r1 = LD32(r14 + 16);
    r2 = LD16((r14 + 6));
    ST16((r1 + 4), r2);
    r3 = LD16((r14 + 8));
    if ((r3 & 0xFFFF) == 0xFFFF) {
        r7 = LD16((r14 + 10));
        r3 = LD32(0x0608F014);
        r7 = ((((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF)) + (((r7 & 0xFFFF) << 2) + (r7 & 0xFFFF))) + r3;
        r2 = LD16((r7 + 6));
        ST16((r14 + 8), r2);
    }
    r1 = LD16((r14 + 6));
    ST32((64 + r14), ((56 & r1) & 0xFFFF));
    r0 = LD32((64 + r14));
    if (!(r0 == 8)) {
        r1 = LD32(r14 + 16);
        r2 = LD16((r14 + 8));
        ST16((r1 + 6), r2);
    } else {
        r1 = LD32(r14 + 16);
        r6 = LD16((r14 + 8));
        r7 = r6 & 0xFFFF;
        r2 = LD16(0x060896E4);
        ST16((r1 + 6), (r2 + (r7 << 2)));
    }
    r1 = LD32((108 + r14));
    r3 = LD32(r14 + 16);
    ST32(r14 + 60, 0x0606CD9A);
    r13 = LD32(r14 + 60);
    r0 = GCALL4(r13, (r3 + 12), r1, 8, r7);
    r3 = LD16((r14 + 12));
    if (!((r3 & 0xFFFF) == 0xFFFF)) {
        r1 = LD32(r14 + 16);
        r2 = LD16(0x0608971C);
        r3 = LD16((r14 + 12));
        ST16((r1 + 28), (r2 + r3));
    } else {
        r2 = LD32(r14 + 16);
        ST16((r2 + 28), 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606960C(int r4, int r5)
{
    int r0, r1, r2, r3, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    ST32(r14, r4);
    ST32(r14 + 4, r5);
    r4 = LD32(r14);
    r0 = GCALL1(0x0606CDAC, r4);
    r2 = LD32(0x060896BC);
    ST32(0x060896BC, (r2 + 32));
    ST32(r14 + 8, r2);
    r3 = LD32(0x0608F01C);
    ST32(0x0608F01C, (r3 + 1));
    r1 = LD32(r14 + 4);
    r2 = LD32(r14 + 8);
    r0 = GCALL3(0x0606CD9A, r2, r1, 16);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606966C(int r4)
{
    int r0, r2, r3, r7, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    ST16(r14, r4);
    r3 = LD32(0x06089714);
    ST32(r14 + 4, r3);
    ST16((r14 + 28), 0);
    ST16((r14 + 20), -1);
    ST32(r14 + 8, 0);
    ST32(r14 + 12, 0);
    ST32(r14 + 16, 0);
    while (1) {
        r2 = LD32(r14 + 4);
        if (!((r2 & r2) == 0)) {
            r2 = LD32(r14 + 4);
            r7 = LD16(r14);
            r3 = r7 & 0xFFFF;
            r7 = LD16((r2 + 4));
            if (!((unsigned)r3 > (unsigned)(r7 & 0xFFFF))) {
                r3 = LD32(r14 + 4);
                r7 = LD16((r14 + 20));
                r2 = r7 & 0xFFFF;
                r7 = LD16((r3 + 4));
                if ((unsigned)r2 > (unsigned)(r7 & 0xFFFF)) {
                    r7 = LD32(r14 + 4);
                    r3 = LD16((r7 + 4));
                    ST16((r14 + 20), r3);
                    r2 = LD32(r14 + 4);
                    ST32(r14 + 8, r2);
                    r2 = LD32(r14 + 12);
                    ST32(r14 + 16, r2);
                }
            }
            r2 = LD32(r14 + 4);
            ST32(r14 + 12, r2);
            r2 = LD32(r14 + 4);
            r3 = LD32(r2);
            ST32(r14 + 4, r3);
            POLL();
            continue;
        } else {
            break;
        }
        POLL();
    }
    r2 = LD32(r14 + 8);
    if (!((r2 & r2) == 0)) {
        r2 = LD32(r14 + 8);
        r7 = LD32(r14 + 8);
        r3 = LD16((r7 + 4));
        r7 = LD16(r14);
        ST16((r2 + 4), (r3 - r7));
        r3 = LD32(r14 + 8);
        r7 = LD16((r3 + 4));
        r3 = LD32(r14 + 8);
        ST32(r14 + 24, (((r7 & 0xFFFF) * 32) + r3));
        r3 = LD32(r14 + 24);
        r2 = LD32(0x060896C4);
        ST32(r14 + 24, (r3 - r2));
        r7 = LD32(r14 + 24);
        ST16((r14 + 28), ((int)((unsigned)((int)((unsigned)r7 >> 2)) >> 1)));
        r3 = LD32(r14 + 8);
        r7 = LD16((r3 + 4));
        if (((r7 & 0xFFFF) & (r7 & 0xFFFF)) == 0) {
            r2 = LD32(r14 + 16);
            if (!((r2 & r2) == 0)) {
                r2 = LD32(r14 + 16);
                r3 = LD32(r14 + 8);
                r7 = LD32(r3);
                ST32(r2, r7);
            }
        }
    }
    r7 = LD16((r14 + 28));
    r0 = r7 & 0xFFFF;
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06069780(int r4, int r5)
{
    int r0, r6, r14;
    FRAME(sp, 36);

    r14 = sp - 36;
    ST16(r14, r4);
    ST16((r14 + 2), r5);
    r4 = LD16(r14);
    r6 = LD32(0x060896C4);
    ST32(r14 + 4, ((((r4 & 0xFFFF) << 2) + ((r4 & 0xFFFF) << 2)) + r6));
    r4 = LD16((r14 + 2));
    r5 = LD32(r14 + 4);
    ST32(r14 + 8, (((r4 & 0xFFFF) * 32) + r5));
    r5 = LD32(0x060896C4);
    ST32(r14 + 12, r5);
    r5 = LD32(0x060896C4);
    ST32(r14 + 16, (r5 + 0x00080000));
    r6 = LD32(r14 + 12);
    ST32(r14 + 20, r6);
    r5 = LD32(0x06089714);
    ST32(r14 + 24, r5);
    while (1) {
        r6 = LD32(r14 + 20);
        r5 = LD32(r14 + 4);
        if (!((unsigned)r6 > (unsigned)r5)) {
            r6 = LD32(r14 + 4);
            r5 = LD32(r14 + 24);
            if (!((unsigned)r6 >= (unsigned)r5)) {
                r6 = LD32(r14 + 20);
                r5 = LD32(r14 + 12);
                if (!(r6 == r5)) {
                    r6 = LD32(r14 + 24);
                    r5 = LD32(r14 + 16);
                    if (!(r6 == r5)) {
                        r5 = LD32(r14 + 20);
                        r4 = LD16((r5 + 4));
                        r5 = LD32(r14 + 20);
                        ST32(r14 + 28, (((r4 & 0xFFFF) * 32) + r5));
                        r6 = LD32(r14 + 28);
                        r5 = LD32(r14 + 4);
                        if (!(r6 == r5)) {
                            r6 = LD32(r14 + 28);
                            r5 = LD32(r14 + 4);
                            if (!((unsigned)r6 >= (unsigned)r5)) {
                                r6 = LD32(r14 + 8);
                                r5 = LD32(r14 + 24);
                                if (r6 == r5) {
                                    r6 = LD32(r14 + 4);
                                    r5 = LD32(r14 + 24);
                                    r4 = LD32(r5);
                                    ST32(r6, r4);
                                    r6 = LD32(r14 + 4);
                                    r5 = LD32(r14 + 24);
                                    r5 = LD16((r5 + 4));
                                    r4 = LD16((r14 + 2));
                                    ST16((r6 + 4), (r5 + r4));
                                    r6 = LD32(r14 + 20);
                                    r5 = LD32(r14 + 4);
                                    ST32(r6, r5);
                                    break;
                                } else {
                                    r6 = LD32(r14 + 28);
                                    r5 = LD32(r14 + 4);
                                    if (!((unsigned)r6 >= (unsigned)r5)) {
                                        r6 = LD32(r14 + 8);
                                        r5 = LD32(r14 + 24);
                                        if (!((unsigned)r6 >= (unsigned)r5)) {
                                            r6 = LD32(r14 + 4);
                                            r5 = LD32(r14 + 24);
                                            ST32(r6, r5);
                                            r6 = LD32(r14 + 4);
                                            r5 = LD16((r14 + 2));
                                            ST16((r6 + 4), r5);
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 4);
                                            ST32(r6, r5);
                                            break;
                                        } else {
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 24);
                                            r4 = LD32(r5);
                                            ST32(r6, r4);
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 20);
                                            r5 = LD16((r5 + 4));
                                            r4 = LD16((r14 + 2));
                                            ST16((r6 + 4), (r5 + r4));
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 20);
                                            r0 = LD32(r14 + 24);
                                            r5 = LD16((r5 + 4));
                                            r4 = LD16((r0 + 4));
                                            ST16((r6 + 4), (r5 + r4));
                                            break;
                                        }
                                    } else {
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 24);
                                        r4 = LD32(r5);
                                        ST32(r6, r4);
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 20);
                                        r5 = LD16((r5 + 4));
                                        r4 = LD16((r14 + 2));
                                        ST16((r6 + 4), (r5 + r4));
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 20);
                                        r0 = LD32(r14 + 24);
                                        r5 = LD16((r5 + 4));
                                        r4 = LD16((r0 + 4));
                                        ST16((r6 + 4), (r5 + r4));
                                        break;
                                    }
                                }
                            } else {
                                r6 = LD32(r14 + 28);
                                r5 = LD32(r14 + 4);
                                if (!((unsigned)r6 >= (unsigned)r5)) {
                                    r6 = LD32(r14 + 8);
                                    r5 = LD32(r14 + 24);
                                    if (!((unsigned)r6 >= (unsigned)r5)) {
                                        r6 = LD32(r14 + 4);
                                        r5 = LD32(r14 + 24);
                                        ST32(r6, r5);
                                        r6 = LD32(r14 + 4);
                                        r5 = LD16((r14 + 2));
                                        ST16((r6 + 4), r5);
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 4);
                                        ST32(r6, r5);
                                        break;
                                    } else {
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 24);
                                        r4 = LD32(r5);
                                        ST32(r6, r4);
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 20);
                                        r5 = LD16((r5 + 4));
                                        r4 = LD16((r14 + 2));
                                        ST16((r6 + 4), (r5 + r4));
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 20);
                                        r0 = LD32(r14 + 24);
                                        r5 = LD16((r5 + 4));
                                        r4 = LD16((r0 + 4));
                                        ST16((r6 + 4), (r5 + r4));
                                        break;
                                    }
                                } else {
                                    r6 = LD32(r14 + 20);
                                    r5 = LD32(r14 + 24);
                                    r4 = LD32(r5);
                                    ST32(r6, r4);
                                    r6 = LD32(r14 + 20);
                                    r5 = LD32(r14 + 20);
                                    r5 = LD16((r5 + 4));
                                    r4 = LD16((r14 + 2));
                                    ST16((r6 + 4), (r5 + r4));
                                    r6 = LD32(r14 + 20);
                                    r5 = LD32(r14 + 20);
                                    r0 = LD32(r14 + 24);
                                    r5 = LD16((r5 + 4));
                                    r4 = LD16((r0 + 4));
                                    ST16((r6 + 4), (r5 + r4));
                                    break;
                                }
                            }
                        } else {
                            r6 = LD32(r14 + 8);
                            r5 = LD32(r14 + 24);
                            if ((unsigned)r6 >= (unsigned)r5) {
                                r6 = LD32(r14 + 28);
                                r5 = LD32(r14 + 4);
                                if (!((unsigned)r6 >= (unsigned)r5)) {
                                    r6 = LD32(r14 + 8);
                                    r5 = LD32(r14 + 24);
                                    if (r6 == r5) {
                                        r6 = LD32(r14 + 4);
                                        r5 = LD32(r14 + 24);
                                        r4 = LD32(r5);
                                        ST32(r6, r4);
                                        r6 = LD32(r14 + 4);
                                        r5 = LD32(r14 + 24);
                                        r5 = LD16((r5 + 4));
                                        r4 = LD16((r14 + 2));
                                        ST16((r6 + 4), (r5 + r4));
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 4);
                                        ST32(r6, r5);
                                        break;
                                    } else {
                                        r6 = LD32(r14 + 28);
                                        r5 = LD32(r14 + 4);
                                        if (!((unsigned)r6 >= (unsigned)r5)) {
                                            r6 = LD32(r14 + 8);
                                            r5 = LD32(r14 + 24);
                                            if (!((unsigned)r6 >= (unsigned)r5)) {
                                                r6 = LD32(r14 + 4);
                                                r5 = LD32(r14 + 24);
                                                ST32(r6, r5);
                                                r6 = LD32(r14 + 4);
                                                r5 = LD16((r14 + 2));
                                                ST16((r6 + 4), r5);
                                                r6 = LD32(r14 + 20);
                                                r5 = LD32(r14 + 4);
                                                ST32(r6, r5);
                                                break;
                                            } else {
                                                r6 = LD32(r14 + 20);
                                                r5 = LD32(r14 + 24);
                                                r4 = LD32(r5);
                                                ST32(r6, r4);
                                                r6 = LD32(r14 + 20);
                                                r5 = LD32(r14 + 20);
                                                r5 = LD16((r5 + 4));
                                                r4 = LD16((r14 + 2));
                                                ST16((r6 + 4), (r5 + r4));
                                                r6 = LD32(r14 + 20);
                                                r5 = LD32(r14 + 20);
                                                r0 = LD32(r14 + 24);
                                                r5 = LD16((r5 + 4));
                                                r4 = LD16((r0 + 4));
                                                ST16((r6 + 4), (r5 + r4));
                                                break;
                                            }
                                        } else {
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 24);
                                            r4 = LD32(r5);
                                            ST32(r6, r4);
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 20);
                                            r5 = LD16((r5 + 4));
                                            r4 = LD16((r14 + 2));
                                            ST16((r6 + 4), (r5 + r4));
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 20);
                                            r0 = LD32(r14 + 24);
                                            r5 = LD16((r5 + 4));
                                            r4 = LD16((r0 + 4));
                                            ST16((r6 + 4), (r5 + r4));
                                            break;
                                        }
                                    }
                                } else {
                                    r6 = LD32(r14 + 28);
                                    r5 = LD32(r14 + 4);
                                    if (!((unsigned)r6 >= (unsigned)r5)) {
                                        r6 = LD32(r14 + 8);
                                        r5 = LD32(r14 + 24);
                                        if (!((unsigned)r6 >= (unsigned)r5)) {
                                            r6 = LD32(r14 + 4);
                                            r5 = LD32(r14 + 24);
                                            ST32(r6, r5);
                                            r6 = LD32(r14 + 4);
                                            r5 = LD16((r14 + 2));
                                            ST16((r6 + 4), r5);
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 4);
                                            ST32(r6, r5);
                                            break;
                                        } else {
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 24);
                                            r4 = LD32(r5);
                                            ST32(r6, r4);
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 20);
                                            r5 = LD16((r5 + 4));
                                            r4 = LD16((r14 + 2));
                                            ST16((r6 + 4), (r5 + r4));
                                            r6 = LD32(r14 + 20);
                                            r5 = LD32(r14 + 20);
                                            r0 = LD32(r14 + 24);
                                            r5 = LD16((r5 + 4));
                                            r4 = LD16((r0 + 4));
                                            ST16((r6 + 4), (r5 + r4));
                                            break;
                                        }
                                    } else {
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 24);
                                        r4 = LD32(r5);
                                        ST32(r6, r4);
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 20);
                                        r5 = LD16((r5 + 4));
                                        r4 = LD16((r14 + 2));
                                        ST16((r6 + 4), (r5 + r4));
                                        r6 = LD32(r14 + 20);
                                        r5 = LD32(r14 + 20);
                                        r0 = LD32(r14 + 24);
                                        r5 = LD16((r5 + 4));
                                        r4 = LD16((r0 + 4));
                                        ST16((r6 + 4), (r5 + r4));
                                        break;
                                    }
                                }
                            } else {
                                r6 = LD32(r14 + 20);
                                r5 = LD32(r14 + 20);
                                r5 = LD16((r5 + 4));
                                r4 = LD16((r14 + 2));
                                ST16((r6 + 4), (r5 + r4));
                                break;
                            }
                        }
                    } else {
                        r5 = LD32(r14 + 20);
                        r4 = LD16((r5 + 4));
                        r5 = LD32(r14 + 20);
                        ST32(r14 + 28, (((r4 & 0xFFFF) * 32) + r5));
                        r6 = LD32(r14 + 28);
                        r5 = LD32(r14 + 4);
                        if (!(r6 == r5)) {
                            r6 = LD32(r14 + 20);
                            r5 = LD32(r14 + 4);
                            ST32(r6, r5);
                            r6 = LD32(r14 + 4);
                            ST32(r6, 0);
                            r6 = LD32(r14 + 4);
                            r5 = LD16((r14 + 2));
                            ST16((r6 + 4), r5);
                            break;
                        } else {
                            r6 = LD32(r14 + 20);
                            r5 = LD32(r14 + 20);
                            r5 = LD16((r5 + 4));
                            r4 = LD16((r14 + 2));
                            ST16((r6 + 4), (r5 + r4));
                            break;
                        }
                    }
                } else {
                    r6 = LD32(r14 + 24);
                    r5 = LD32(r14 + 8);
                    if (!(r6 == r5)) {
                        r6 = LD32(r14 + 4);
                        r4 = LD32(0x06089714);
                        ST32(r6, r4);
                        r6 = LD32(r14 + 4);
                        r5 = LD16((r14 + 2));
                        ST16((r6 + 4), r5);
                        r5 = LD32(r14 + 4);
                        ST32(0x06089714, r5);
                        break;
                    } else {
                        r6 = LD32(r14 + 4);
                        r5 = LD32(r14 + 24);
                        r4 = LD32(r5);
                        ST32(r6, r4);
                        r6 = LD32(r14 + 4);
                        r5 = LD32(r14 + 24);
                        r5 = LD16((r5 + 4));
                        r4 = LD16((r14 + 2));
                        ST16((r6 + 4), (r5 + r4));
                        r5 = LD32(r14 + 4);
                        ST32(0x06089714, r5);
                        break;
                    }
                }
            } else {
                r6 = LD32(r14 + 24);
                r5 = LD32(r14 + 16);
                if (r6 == r5) {
                    break;
                } else {
                    r6 = LD32(r14 + 24);
                    ST32(r14 + 20, r6);
                    r6 = LD32(r14 + 24);
                    r5 = LD32(r6);
                    ST32(r14 + 24, r5);
                    r6 = LD32(r14 + 24);
                    if ((r6 & r6) == 0) {
                        r6 = LD32(r14 + 16);
                        ST32(r14 + 24, r6);
                    }
                    POLL();
                    continue;
                }
            }
        } else {
            r6 = LD32(r14 + 24);
            r5 = LD32(r14 + 16);
            if (r6 == r5) {
                break;
            } else {
                r6 = LD32(r14 + 24);
                ST32(r14 + 20, r6);
                r6 = LD32(r14 + 24);
                r5 = LD32(r6);
                ST32(r14 + 24, r5);
                r6 = LD32(r14 + 24);
                if ((r6 & r6) == 0) {
                    r6 = LD32(r14 + 16);
                    ST32(r14 + 24, r6);
                }
            }
        }
        POLL();
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06069C28(void)
{
    int r0, r2, r3, r6;
    FRAME(sp, 12);

    r2 = LD32(0x0608F010);
    r3 = LD32(0x0608EFEC);
    r6 = LD32(0x0608F008);
    r0 = GCALL4(0x0606CDF8, (r6 >> 1), r3, r2, 0x06089724);
    ST16(0x06089728, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06069C78(void)
{
    int r0, r1, r8;
    FRAME(sp, 16);

    r0 = SR();
    r8 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    SETSR((r0 | 240));
    r1 = LD32(0x06000344);
    r0 = GCALL2(r1, -2049, 0);
    ST8(0x06089736, 0);
    r1 = SR();
    SETSR(((r1 & -241) | ((r8 << 2) << 2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06069DD4(void)
{
    int r0, r1, r4, r5, r8, r9, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    r0 = SR();
    r9 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    r8 = -241;
    SETSR((r0 | 240));
    r1 = LD8(0x06089736);
    if (!((r1 & 255) == 1)) {
        r1 = SR();
        SETSR(((r1 & r8) | ((r9 << 2) << 2)));
        r0 = 0;
    } else {
        r1 = LD8(0x06089734);
        r5 = 0;
        if (((r1 & 255) & (r1 & 255)) == 0) {
            r1 = SR();
            SETSR(((r1 & r8) | ((r9 << 2) << 2)));
            r0 = 0;
        } else {
            r0 = GCALL2(0x0606D144, r14, r5);
            r0 = LD32(r14);
            if (!(r0 == 1)) {
                r5 = LD32(0x06089730);
                r4 = LD32(0x0608972C);
                r0 = GCALL2(0x0606C668, r4, r5);
                r1 = SR();
                SETSR(((r1 & r8) | ((r9 << 2) << 2)));
                r0 = 0;
            } else {
                r1 = (SR() & ~1) | 1;
                SETSR(((r1 & r8) | ((r9 << 2) << 2)));
                r0 = 2;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06069E6C(int r4, int r5)
{
    int r0, r1;
    FRAME(sp, 8);

    r0 = r4 << 2;
    ST32(r0 + 0x0608F030, r5);
    r5 = LD32(r0 + 0x0607A020);
    r1 = LD32(0x06000300);
    r0 = GCALL2(r1, r4, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06069EAC(int r4)
{
    int r0, r1, r2, r3, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    ST32(r14, r4);
    r0 = GCALL0(0x0606A724);
    ST32(r14 + 4, r0);
    r0 = GCALL1(0x0606A75C, 15);
    r0 = GCALL1(0x0606A6F8, 0);
    r0 = GCALL3(0x06069FA8, 0, 0, 0);
    r3 = LD16(0x0608F434);
    ST16(0x25D00002, r3);
    ST16(0x25D00004, 2);
    ST16(0x25D00006, -32768);
    ST16(0x25D00008, 0);
    ST16(0x25D0000A, -1);
    r1 = LD16(0x0608F43E);
    r3 = LD16(0x0608F432);
    ST32((sp - 24), ((r3 - 1) & 0xFFFF));
    r0 = GCALL5(0x0606A158, 0x8000, 0, 0, ((r1 - 1) & 0xFFFF), LD32((sp - 24)));
    r1 = LD32(r14);
    ST32(r1, 0x25C00000);
    r1 = LD32(r14);
    r2 = LD32(r1);
    ST8(r2, -128);
    r1 = LD32(r14);
    r2 = LD32(r1);
    ST8((r2 + 1), 0);
    r1 = LD32(r14 + 4);
    r0 = GCALL1(0x0606A75C, r1);
    ST32(0x0607A420, 1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06069FA8(int r4, int r5, int r6)
{
    int r8, r9, r10, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    ST16(r14, r4);
    ST16((r14 + 2), r5);
    ST16((r14 + 4), r6);
    r8 = LD16(r14);
    ST16(0x0608F43A, (7 & r8));
    r9 = LD16(0x0608F43A);
    ST16(0x25D00000, r9);
    r9 = LD16((r14 + 2));
    if ((unsigned)(r9 & 0xFFFF) > (unsigned)7) {
        ST16((r14 + 2), 0);
    }
    r10 = LD16((r14 + 2));
    r9 = LD16((((r10 & 0xFFFF) << 2) + 0x0607A434));
    ST32(0x0608F43C, r9);
    r10 = LD16((r14 + 2));
    r8 = LD16(((((r10 & 0xFFFF) << 2) + 0x0607A434) + 2));
    ST32(0x0608F430, r8);
    r9 = LD16((r14 + 4));
    if ((r9 & 0xFFFF) == 1) {
        r9 = LD32(0x0608F430);
        ST32(0x0608F430, (r9 + r9));
    }
    r8 = LD16(r14);
    if ((r8 & 0xFFFF) == 1) {
        ST16(0x0607A432, 1);
    } else {
        r8 = LD16(r14);
        if ((r8 & 0xFFFF) == 3) {
            ST16(0x0607A432, 1);
        } else {
            ST16(0x0607A432, 0);
        }
    }
    r9 = LD16((r14 + 4));
    if (((r9 & 0xFFFF) & (r9 & 0xFFFF)) == 0) {
        ST16(0x0608F438, 0);
    } else {
        ST16(0x0608F438, 8);
    }
    ST16(0x0608F436, 0);
    return 0x0608F436;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606A0C8(int r4)
{
    int r1, r3, r14;
    FRAME(sp, 8);

    r14 = sp - 8;
    ST32(r14, r4);
    r1 = LD32(r14);
    r3 = LD16(0x06079FB4);
    ST16(r1, r3);
    r1 = LD32(r14);
    r3 = LD32(0x06079FB8);
    ST16((r1 + 2), r3);
    r1 = LD32(r14);
    r3 = LD32(0x06079FBC);
    ST16((r1 + 4), r3);
    r1 = LD32(r14);
    r3 = LD16(0x0607A428);
    ST16((r1 + 6), r3);
    r1 = LD32(r14);
    r3 = LD16(0x0607A42A);
    ST16((r1 + 8), r3);
    r1 = LD32(r14);
    r3 = LD16(0x0607A42C);
    ST16((r1 + 10), r3);
    r1 = LD32(r14);
    r3 = LD16(0x0607A42E);
    ST16((r1 + 12), r3);
    r1 = LD32(r14);
    r3 = LD16(0x0607A430);
    ST16((r1 + 14), r3);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606A6D0(void)
{
    int r2;
    FRAME(sp, 4);

    do {
        r2 = LD16(0x25D00010);
    } while (AGAIN((((2 & r2) & 0xFFFF) & ((2 & r2) & 0xFFFF)) == 0));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606A6F8(int r4)
{
    int r1, r14;
    FRAME(sp, 8);

    r14 = sp - 8;
    ST32(r14, r4);
    r1 = LD32(r14);
    if ((r1 & r1) == 0) {
        ST16(0x0608F434, 0);
    } else {
        ST16(0x0608F434, 16);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606A724(void)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    r0 = GCALL0(0x0606A7B8);
    ST32(r14, ((int)((unsigned)((int)((unsigned)(240 & r0) >> 2)) >> 2)));
    r0 = LD32(r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606A7A8(int r4)
{
    FRAME(sp, 4);

    SETSR(r4);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606A7B8(void)
{
    int r0, r1, r14;
    FRAME(sp, 8);

    r14 = sp - 8;
    r1 = SR();
    ST32(r14, r1);
    r0 = LD32(r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606A984(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8;
    FRAME(sp, 12);

    r1 = LD32(0x0608F444);
    r8 = r1 + 152;
    if (!((r4 & r4) == 0)) {
        r1 = r4;
        r3 = LD32(r1);
        r1 = r1 + 4;
        r2 = r8 + 4;
        ST32(r8, r3);
        r3 = LD32(r1);
        ST32(r2, r3);
        r1 = LD32((r1 + 4));
        ST32(r2 + 4, r1);
        r0 = GCALL4(0x0606BA48, r4, 0, r6, r7);
        ST32(r8 + 12, r0);
        r0 = 0x0606BB88;
        r4 = 0;
    } else {
        r1 = LD32(r8 + 8);
        r4 = -7;
        if ((r1 & r1) == 0) {
            ST32(r8 + 8, 0);
            ST32(r8 + 12, 0);
            ST32(r8 + 4, 0);
            r0 = 0x0606BB88;
            r4 = 0;
        } else {
            r0 = 0x0606BB88;
        }
    }
    r0 = GCALL1(r0, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606AA50(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, c2, c4;
    FRAME(sp, 12);

    r1 = LD32(0x0608F444);
    r1 = r1 + 152;
    r5 = LD32(r1 + 8);
    if ((r5 & r5) == 0) {
        r0 = GCALL4(0x0606BB88, -8, 0, r6, r7);
        r0 = 0;
    } else {
        r0 = LD32(r1);
        c2 = r4 >= 0;
        if (r0 == 1) {
            if (!(c2)) {
                r0 = GCALL4(0x0606BB88, -9, 0, r6, r7);
                r0 = 0;
            } else {
                r1 = LD32(r1 + 12);
                if (r1 > r4) {
                    r0 = GCALL2(0x0606E2B4, r4, r5);
                    r8 = r0;
                    r0 = GCALL4(0x0606BB88, 0, 0, r6, r7);
                    c4 = r0 >= 0;
                    r0 = r8;
                    if (!(c4)) {
                        r0 = 0;
                    } else {
                        r0 = r0 + 12;
                    }
                } else {
                    r0 = GCALL4(0x0606BB88, -9, 0, r6, r7);
                    r0 = 0;
                }
            }
        } else {
            r0 = GCALL4(0x0606BB88, -8, 0, r6, r7);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606AABC(int r4, int r5)
{
    int r0, r1, r2, r3, r8;
    FRAME(sp, 12);

    r8 = r5;
    r1 = LD32(0x0608F444);
    r2 = 152 + r1;
    r5 = LD32(r2 + 8);
    if ((r5 & r5) == 0) {
        r0 = 0x0606BB88;
        r4 = -10;
    } else {
        if (!(r4 >= 0)) {
            r0 = 0x0606BB88;
            r4 = -10;
        } else {
            r1 = LD32(r2 + 12);
            if (!(r4 >= r1)) {
                r0 = LD32(r2);
                if (!(r0 == 1)) {
                    r0 = 0x0606E2A0;
                } else {
                    r0 = 0x0606E2B4;
                }
                r0 = GCALL2(r0, r4, r5);
                r3 = LD32(r0);
                r0 = r0 + 4;
                r1 = r8 + 4;
                ST32(r8, r3);
                r3 = LD32(r0);
                ST32(r1, r3);
                r0 = LD32((r0 + 4));
                ST32(r1 + 4, r0);
                r0 = 0x0606BB88;
                r4 = 0;
            } else {
                r0 = 0x0606BB88;
                r4 = -10;
            }
        }
    }
    r0 = GCALL1(r0, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606AB2C(void)
{
    int r0, r1, r6, r8, r9, r10, r11, r12, r13;
    FRAME(sp, 32);

    r1 = LD32(0x0608F444);
    r9 = 0;
    r8 = r1;
    r1 = LD32(r1);
    r8 = r8 + 0xC60;
    if (!(0 >= r1)) {
        r13 = 0x0606F528;
        r12 = 0x0606AC64;
        r11 = 168;
        r10 = r8 + 164;
        do {
            r0 = LD32(r8);
            if (r0 == 1) {
                r0 = LD32(r10);
                r6 = r8;
                if (r0 == 4) {
                    r0 = GCALL3(r13, r8, 0x0606B964, r6);
                }
                r0 = GCALL1(r12, r8);
            }
            r9 = r9 + 1;
            r1 = LD32(0x0608F444);
            r10 = r10 + r11;
            r1 = LD32(r1);
            r8 = r8 + r11;
        } while (AGAIN(!(r9 >= r1)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606AF1C(int r4)
{
    int r0;
    FRAME(sp, 8);

    if ((r4 & r4) == 0) {
        r0 = 0x0606BB88;
        r4 = -11;
    } else {
        r0 = 0x0606F594;
    }
    r0 = GCALL1(r0, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B258(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10;
    FRAME(sp, 20);

    r8 = r4;
    r9 = r5;
    if (!((r8 & r8) == 0)) {
        r1 = LD32(r8 + 4);
        r10 = r8 + 12;
        if ((r1 & r1) == 0) {
            r0 = GCALL4(0x0606AD50, r8, r5, r6, r7);
            r1 = LD32(r8 + 32);
            r5 = r1 - r0;
            if (r5 > r9) {
                r5 = r9;
            }
            r0 = GCALL2(0x0606C124, r10, r5);
            ST32(r8 + 4, 2);
            ST32(r8 + 8, 1);
            r0 = GCALL1(0x0606BC48, r8);
            r0 = 0x0606BB88;
            r4 = 0;
        } else {
            r0 = 0x0606BB88;
            r4 = -16;
        }
    } else {
        r0 = 0x0606BB88;
        r4 = -11;
    }
    r0 = GCALL1(r0, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B2D0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, c1;
    FRAME(sp, 12);

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r0 = GCALL4(0x0606BB88, 0, 0, r6, r7);
        c1 = r0 >= 0;
        r0 = 1;
        if (c1) {
            r1 = LD32(r8 + 8);
            r0 = (r1 & r1) == 0;
        }
    } else {
        r0 = GCALL4(0x0606BB88, -11, 0, r6, r7);
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B3F0(int r4)
{
    int r0, r1, r2, r8, c1;
    FRAME(sp, 12);

    r8 = r4;
    r1 = LD32(r8 + 40);
    r4 = r4 + 12;
    if ((r1 & r1) == 0) {
        r0 = GCALL1(0x0606DD8C, r4);
        c1 = r0 == 2;
        r2 = c1;
        if (c1) {
            ST32(r8 + 8, r2);
        }
    }
    r0 = LD32(r8 + 8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B768(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9;
    FRAME(sp, 16);

    r9 = r5;
    if (!((r4 & r4) == 0)) {
        r8 = LD32((r4 + 108) + 12);
        r5 = r4 + 40;
        r1 = LD32(r5);
        if ((r1 & r1) == 0) {
            r0 = GCALL2(0x0606FB10, r8, r5);
        }
        r2 = LD32(r8 + 4);
        ST32(r9, r2);
        r0 = LD32(r8);
    } else {
        r0 = GCALL4(0x0606BB88, -11, 0, r6, r7);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B7B4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;
    FRAME(sp, 16);

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r1 = LD32(r8 + 40);
        r9 = r8 + 12;
        if (!((r1 & r1) == 0)) {
            r0 = 0x0606BB88;
            r4 = 0;
        } else {
            r0 = GCALL4(0x0606AD50, r8, r5, r6, r7);
            r0 = GCALL2(0x0606DE04, r9, r0);
            r1 = r0;
            r4 = r1;
            if ((r1 & r1) == 0) {
                r1 = LD32(0x0608F444);
                ST32(168 + r1, r8);
                r0 = 0x0606BB88;
                r4 = 0;
            } else {
                r0 = 0x0606BB88;
            }
        }
    } else {
        r0 = 0x0606BB88;
        r4 = -11;
    }
    r0 = GCALL1(r0, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B820(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    FRAME(sp, 8);

    r2 = LD32(0x0608F444);
    r2 = r2 + 184;
    ST32(r2, r4);
    ST32(r2 + 4, r5);
    r0 = GCALL4(0x0606BB88, 0, 0, r6, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B870(int r4)
{
    int r1, r2;
    FRAME(sp, 4);

    r1 = LD8(0x06000CCC);
    r2 = r4;
    if ((r1 & 255) == 1) {
        r1 = LD8(0x06000CCD);
        r2 = r2 + (r1 & 255);
    }
    return r2;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B9A4(int r4)
{
    int r0, r1, r2, r3, r9;
    FRAME(sp, 16);

    r1 = LD32(0x0608F444);
    r9 = r4;
    ST32(r1, r9);
    r0 = GCALL0(0x0606B970);
    r3 = LD32(0x0608F444);
    ST32(((r3 + 52) + 96), 0);
    r0 = r3;
    ST32(r0 + 180, 0);
    ST32(r0 + 168, 0);
    ST32(r0 + 176, 0);
    ST32(r0 + 172, 0);
    ST32(r0 + 184, 0);
    ST32(r0 + 196, 0);
    r3 = r3 + 0xC60;
    r1 = 0;
    r2 = 168;
    if (!(0 >= r9)) {
        r0 = 0;
        do {
            ST32(r3, r0);
            r1 = r1 + 1;
            r3 = r3 + r2;
        } while (AGAIN(!(r1 >= r9)));
    }
    r3 = LD32(0x0608F444);
    r1 = r3 + 0x438;
    ST32(r1, 0);
    ST32(r1 + 12, 0);
    ST32(r1 + 8, 0);
    ST32(r1 + 4, 0);
    ST32(r1 + 16, 0);
    r1 = 0x44C + r3;
    ST32(r1, 0);
    ST32(r1 + 12, 0);
    ST32(r1 + 8, 0);
    ST32(r1 + 4, 0);
    ST32(r1 + 16, 0);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606BA48(int r4)
{
    int r0, r1, r5, r8, r9, r10, r11;
    FRAME(sp, 24);

    r9 = r4;
    r1 = LD32(r9 + 4);
    r8 = 0;
    if (!(0 >= r1)) {
        r11 = 0x0606E2C8;
        r10 = 0x0606E2E0;
        while (1) {
            r1 = LD32(r9);
            if (!((r1 & r1) == 0)) {
                r5 = LD32(r9 + 8);
                r0 = GCALL2(r10, r8, r5);
                r0 = r0 & 1;
            } else {
                r5 = LD32(r9 + 8);
                r0 = GCALL2(r11, r8, r5);
                r0 = r0 & 1;
            }
            if (!((r0 & r0) == 0)) {
                break;
            } else {
                r1 = LD32(r9 + 4);
                r8 = r8 + 1;
                if (!(r8 >= r1)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        r1 = LD32(r9 + 4);
    }
    r0 = r8;
    if (r8 > r1) {
        r0 = 0;
    } else {
        r0 = r0 + 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606BAB0(void)
{
    int r0, r1, r2, r3, r6, r7;
    FRAME(sp, 4);

    r1 = LD32(0x0608F444);
    r0 = r1 + 0xC60;
    r1 = LD32(r1);
    r2 = 0;
    if (!(0 >= r1)) {
        r3 = 168;
        r7 = r1;
        while (1) {
            r1 = LD32(r0);
            if ((r1 & r1) == 0) {
                break;
            } else {
                r2 = r2 + 1;
                r0 = r0 + r3;
                if (!(r2 >= r7)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    r1 = LD32(0x0608F444);
    r1 = LD32(r1);
    r6 = 1;
    if (!(r2 == r1)) {
        ST32(r0, r6);
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606BB04(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c3;
    FRAME(sp, 24);

    r8 = r4;
    r10 = r5;
    r9 = 0x0608F444;
    r1 = LD32(0x0608F444);
    r2 = 180 + r1;
    r1 = LD32(r2);
    r11 = r8 + 12;
    if (r1 == r8) {
        ST32(r2, 0);
        r0 = GCALL4(0x0606EBF8, r4, -1, 0, r7);
    }
    r7 = LD32(r9);
    r3 = r7 + 168;
    r2 = LD32(r3);
    r1 = LD32(r8 + 40);
    if (r2 == r8) {
        ST32(r3, 0);
        r1 = LD32(((((r1 << 2) << 2) + 4) + r7) + 4);
        r0 = GCALL4(r1, r11, r10, 0, r7);
        ST32((r8 + 92), 0);
        ST32((r8 + 100), 0);
    } else {
        c3 = (r2 & r2) == 0;
        if (!((r1 & r1) == 0)) {
            if (c3) {
                ST32(r3, 0);
                r1 = LD32(((((r1 << 2) << 2) + 4) + r7) + 4);
                r0 = GCALL4(r1, r11, r10, 0, r7);
                ST32((r8 + 92), 0);
                ST32((r8 + 100), 0);
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606BC08(int r4)
{
    int r0, r1, r2, r3, r7;
    FRAME(sp, 4);

    r1 = LD32(0x0608F444);
    r3 = r1 + 52;
    r1 = LD32((r3 + 96));
    r0 = 0;
    if (!(0 >= r1)) {
        r7 = r1;
        r2 = r3;
        while (1) {
            r1 = LD32(r2);
            if (r4 == r1) {
                break;
            } else {
                r0 = r0 + 1;
                r2 = r2 + 4;
                if (!(r0 >= r7)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    r1 = LD32((r3 + 96));
    if (r0 == r1) {
        r0 = -1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606BC48(int r4)
{
    int r0, r1, r2, r3, r8;
    FRAME(sp, 12);

    r8 = r4;
    r0 = GCALL1(0x0606BC08, r4);
    if (r0 == -1) {
        r1 = LD32(0x0608F444);
        r1 = r1 + 52;
        r3 = r1 + 96;
        r2 = LD32(r3);
        r0 = r2 << 2;
        ST32(r0 + r1, r8);
        r1 = LD32(r3);
        ST32(r3, (r1 + 1));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606BC84(int r4)
{
    int r0, r1, r2, r3, r6, r7;
    FRAME(sp, 8);

    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x0606BC08, r4);
        if (!(r0 == -1)) {
            r1 = LD32(0x0608F444);
            r7 = r1 + 52;
            r2 = r7 + 96;
            r1 = LD32(r2);
            r1 = r1 - 1;
            r3 = r1;
            ST32(r2, r1);
            if (!(r0 >= r1)) {
                r2 = (r0 << 2) + r7;
                do {
                    r1 = r2 + 4;
                    r6 = LD32(r1);
                    r0 = r0 + 1;
                    ST32(r2, r6);
                    r2 = r1;
                } while (AGAIN(!(r0 >= r3)));
            }
            ST32((r0 << 2) + r7, 0);
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606BCE0(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10;
    FRAME(sp, 20);

    r8 = r4;
    r10 = r5;
    r9 = r6;
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        r0 = GCALL1(0x0606EB24, (r8 + 108));
        r0 = GCALL3(0x0606D998, (r8 + 12), r10, r9);
        r1 = 0;
        if ((r0 & r0) == 0) {
            r0 = 0;
        } else {
            ST32(r8 + 4, r1);
            ST32(r8 + 8, r1);
            r0 = r8;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606C124(int r4, int r5)
{
    int r0, r1, r8;
    FRAME(sp, 12);

    r8 = r4;
    r1 = LD32(r8 + 28);
    if (!((r1 & r1) == 0)) {
        ST32((r8 + 84), r5);
        ST32((r8 + 88), 0);
        r1 = r8;
    } else {
        r0 = GCALL2(0x0606DAE0, r4, r5);
        r1 = r8;
    }
    ST32((r1 + 80), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C164(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r14, c2, c3, c4, c5;
    FRAME(sp, 12);

    r14 = sp - 12;
    r1 = LD32(r14 + 12);
    r3 = LD32(r14 + 16);
    r0 = LD32(r14 + 20);
    r8 = LD32(r14 + 24);
    if (!((r5 & r5) == 0)) {
        r9 = LD32(r4);
        ST32(r5, r9);
    }
    c2 = (r7 & r7) == 0;
    if (!((r6 & r6) == 0)) {
        r9 = LD32(r4 + 4);
        ST32(r6, r9);
    }
    c3 = (r1 & r1) == 0;
    if (!(c2)) {
        r9 = LD32(r4 + 16);
        ST32(r7, r9);
    }
    c4 = (r3 & r3) == 0;
    if (!(c3)) {
        r9 = LD32(r4 + 20);
        ST32(r1, r9);
    }
    c5 = (r0 & r0) == 0;
    if (!(c4)) {
        r1 = LD32(r4 + 16);
        r2 = LD32(r4 + 24);
        ST32(r3, (r1 - r2));
    }
    r1 = r4;
    if (!(c5)) {
        r1 = LD8((r1 + 14));
        ST32(r0, (r1 & 255));
    }
    if (!((r8 & r8) == 0)) {
        r1 = LD8((r4 + 15));
        ST32(r8, (r1 & 255));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606C1C8(int r4)
{
    int r0, r9;
    FRAME(sp, 16);

    r9 = r4;
    if (!((r9 & r9) == 0)) {
        r0 = GCALL1(0x0606BC84, r4);
        r0 = GCALL1(0x0606BAF8, r9);
        r0 = GCALL1(0x0606F764, (r9 + 40));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C3AC(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    r8 = r4;
    r9 = r5;
    r0 = GCALL1(0x06071924, 0);
    r2 = 0;
    if ((r0 & r0) == 0) {
        r5 = r9;
        if (!(r2 >= r8)) {
            r3 = 0x25898000;
            do {
                r1 = LD16(r3);
                r2 = r2 + 1;
                ST16(r5, r1);
                r5 = r5 + 2;
            } while (AGAIN(!(r2 >= r8)));
        }
        r0 = GCALL1(0x06071990, r14);
        r1 = LD32(r14);
        if ((r0 & r0) == 0) {
            if (!(r8 == r1)) {
                r0 = -7;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C408(int r4, int r5, int r6)
{
    int r0, r1, r8;
    FRAME(sp, 16);

    r0 = SR();
    r8 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    SETSR((r0 | 240));
    r0 = GCALL3(0x0606C448, r4, r5, r6);
    r1 = SR();
    SETSR(((r1 & -241) | ((r8 << 2) << 2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C508(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7;
    FRAME(sp, 4);

    r0 = -3;
    r3 = 0;
    r6 = 0x25890008;
    r7 = 0x0023FFFF;
    while (1) {
        r1 = LD16(r6);
        r2 = r1 & 0xFFFF;
        r3 = r3 + 1;
        if (((r2 & r4) & (r2 & r4)) == 0) {
            if (!(r3 > r7)) {
                POLL();
                continue;
            } else {
                break;
            }
        } else {
            r0 = 0;
            ST32(r5, r2);
            break;
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606C668(int r4, int r5)
{
    int r2, r3, c0;
    FRAME(sp, 4);

    r3 = 0;
    r4 = (r4 & 0x1FFFFFFF) | 0x40000000;
    r2 = (r4 + r5) - 16;
    r4 = r4 & -16;
    do {
        ST32(r4, r3);
        c0 = (unsigned)r4 >= (unsigned)r2;
        r4 = r4 + 16;
    } while (AGAIN(!(c0)));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606CD40(void)
{
    FRAME(sp, 4);

}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606CD4C(int r4, int r5)
{
    int r0, r1, r2, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, r4);
    ST32(r14 + 4, r5);
    r2 = LD32(r14 + 4);
    ST32(0x0607A45C, r2);
    r2 = LD32(0x0607A45C);
    r1 = LD32(r14);
    r0 = GCALL2(r1, r2, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606CD7C(void)
{
    FRAME(sp, 4);

}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606CFCC(int r4, int r5)
{
    int r0, r1, r2, c2;
    FRAME(sp, 4);

    r0 = LD32(r4 + 36);
    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
        r2 = LD32(r4);
        ST32(((((r5 << 2) + (r5 << 2)) << 2) + 0x25FE0000), r2);
    }
    r0 = LD32(r4 + 36);
    r0 = r0 & 2;
    r1 = r5;
    if (!((r0 & r0) == 0)) {
        r2 = LD32(r4 + 4);
        ST32(((((r1 << 2) + (r1 << 2)) << 2) + 0x25FE0004), r2);
    }
    c2 = r5 * 32;
    r2 = LD32(r4 + 8);
    ST32((c2 + 0x25FE0008), r2);
    r1 = LD32(r4 + 12);
    r2 = LD32(r4 + 16);
    ST32((c2 + 0x25FE000C), (r1 | r2));
    r2 = LD32(r4 + 24);
    r1 = LD32(r4 + 20);
    r2 = (r2 << 16) | r1;
    r1 = LD32(r4 + 28);
    r2 = r2 | (r1 << 8);
    r1 = LD32(r4 + 32);
    ST32((c2 + 0x25FE0014), (r2 | r1));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D184(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;
    FRAME(sp, 24);

    r0 = SR();
    r8 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    SETSR((r0 | 240));
    ST8(0x06089758, 0);
    r5 = LD32(0x0608973C);
    r0 = GCALL4(0x06069E6C, 75, r5, r6, r7);
    r5 = LD32(0x0608974C);
    r1 = LD32(0x06000310);
    r0 = GCALL2(r1, 75, r5);
    ST8(0x06089758, 0);
    r1 = SR();
    SETSR(((r1 & -241) | ((r8 << 2) << 2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D1F4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;
    FRAME(sp, 24);

    r0 = SR();
    r8 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    SETSR((r0 | 240));
    ST8(0x06089759, 0);
    r5 = LD32(0x06089740);
    r0 = GCALL4(0x06069E6C, 74, r5, r6, r7);
    r5 = LD32(0x06089750);
    r1 = LD32(0x06000310);
    r0 = GCALL2(r1, 74, r5);
    ST8(0x06089759, 0);
    r1 = SR();
    SETSR(((r1 & -241) | ((r8 << 2) << 2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606D264(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;
    FRAME(sp, 24);

    r0 = SR();
    r8 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    SETSR((r0 | 240));
    ST8(0x0608975A, 0);
    r5 = LD32(0x06089744);
    r0 = GCALL4(0x06069E6C, 73, r5, r6, r7);
    r5 = LD32(0x06089754);
    r1 = LD32(0x06000310);
    r0 = GCALL2(r1, 73, r5);
    ST8(0x0608975A, 0);
    r1 = SR();
    SETSR(((r1 & -241) | ((r8 << 2) << 2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606DAE0(int r4, int r5)
{
    int r0, r1, r8, r9;
    FRAME(sp, 16);

    r8 = r4;
    r9 = r5;
    ST32((r8 + 84), r9);
    r0 = GCALL3(0x0606F78C, r4, 0x7FFFFFFF, 0);
    r1 = r8;
    if (!(r0 >= 0)) {
        r0 = 0;
    }
    r1 = r1 + 88;
    if (r0 > r9) {
        r0 = r9;
    }
    ST32(r1, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606DB24(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r14, c2, c4, c5;
    FRAME(sp, 12);

    r14 = sp - 12;
    r0 = LD32(r14 + 12);
    r3 = LD32(r14 + 16);
    r2 = LD32(r14 + 20);
    r8 = LD32(r14 + 24);
    if (!((r5 & r5) == 0)) {
        r9 = LD32(r4);
        ST32(r5, r9);
    }
    c2 = (r2 & r2) == 0;
    if (!((r6 & r6) == 0)) {
        r9 = LD32(r4 + 4);
        ST32(r6, r9);
    }
    r1 = r4;
    if (!(c2)) {
        r1 = LD8((r1 + 14));
        ST32(r2, (r1 & 255));
    }
    c4 = (r0 & r0) == 0;
    if (!((r7 & r7) == 0)) {
        r9 = LD32(r4 + 16);
        ST32(r7, r9);
    }
    c5 = (r8 & r8) == 0;
    if (!(c4)) {
        r9 = LD32(r4 + 20);
        ST32(r0, r9);
    }
    r1 = r4;
    if (!(c5)) {
        r1 = LD8((r1 + 15));
        ST32(r8, (r1 & 255));
    }
    r1 = r4;
    if (!((r3 & r3) == 0)) {
        r0 = LD8((r1 + 15));
        r0 = r0 & 24;
        r9 = 0;
        if (!(r0 == 24)) {
            r1 = LD32(r4 + 16);
            r2 = LD32(r4 + 24);
            ST32(r3, (r1 - r2));
        } else {
            ST32(r3, r9);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606DB98(int r4)
{
    int r0, r1, r2, r3, r5, r7, r8, r9, r10, r11, r14, c0, c2, c3, c8;
    FRAME(sp, 60);

    r14 = sp - 60;
    r8 = r4;
    r9 = r8 + 28;
    r0 = GCALL2(0x0606DEF4, (r14 + 20), (r14 + 24));
    r10 = r0;
    ST32(0x0608F450, r10);
    r7 = LD32(r14 + 20);
    r11 = r14 + 28;
    ST32(0x0608F44C, r7);
    r0 = GCALL3(0x0606DFC8, r8, r10, r11);
    c0 = (r0 & r0) == 0;
    r0 = LD32(r14 + 28);
    if (!(c0)) {
        r0 = GCALL1(0x0606FC14, r9);
        r2 = LD32(r14 + 20);
        if (!((r0 & r0) == 0)) {
            r1 = LD32(r9 + 44);
            r0 = 2;
            if (r2 >= r1) {
                r0 = LD32(r14 + 24);
                c8 = (r10 & r10) == 0;
                if (!(((r0 & 4) & (r0 & 4)) == 0)) {
                    r0 = GCALL1(0x0606FC2C, r9);
                    r3 = LD32((r8 + 84));
                    r1 = LD32((r8 + 88));
                    r0 = 2;
                    if (r3 == r1) {
                        r3 = LD32(0x0608F444);
                        r2 = LD32(176 + r3);
                        r1 = LD32(r14 + 20);
                        r0 = r10;
                        if (r2 > r1) {
                            r0 = 2;
                        } else {
                            if (r0 == 2) {
                                r0 = 2;
                            } else {
                                ST32(172 + r3, r2);
                                r0 = 4;
                            }
                        }
                    }
                } else {
                    r0 = 2;
                    if (c8) {
                        r0 = GCALL1(0x0606FC2C, r9);
                        r3 = LD32((r8 + 84));
                        r1 = LD32((r8 + 88));
                        r0 = 2;
                        if (r3 == r1) {
                            r3 = LD32(0x0608F444);
                            r2 = LD32(176 + r3);
                            r1 = LD32(r14 + 20);
                            r0 = r10;
                            if (r2 > r1) {
                                r0 = 2;
                            } else {
                                if (r0 == 2) {
                                    r0 = 2;
                                } else {
                                    ST32(172 + r3, r2);
                                    r0 = 4;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            r0 = GCALL3(0x0606E088, r8, (r14 + 32), r11);
            c2 = (r0 & r0) == 0;
            r0 = LD32(r14 + 28);
            if (!(c2)) {
                r0 = GCALL1(0x0606FBEC, r9);
                c3 = (r0 & r0) == 0;
                r0 = 8;
                if (!(c3)) {
                    r0 = GCALL1(0x0606FBB8, r9);
                    r1 = 1;
                    if ((r0 & r0) == 0) {
                        r0 = 8;
                    } else {
                        ST32(r14, r1);
                        r2 = LD32(r9 + 40);
                        ST32(r14 + 4, r2);
                        ST32(r14 + 8, r1);
                        r1 = LD32(r9 + 44);
                        ST32(r14 + 12, (r1 - r2));
                        ST8((r14 + 16), 0);
                        r5 = LD32(r8 + 56);
                        r0 = GCALL2(0x060701D4, r14, r5);
                        ST32(r14 + 28, r0);
                        if ((r0 & r0) == 0) {
                            r3 = r8 + 88;
                            r1 = LD32(r3);
                            r2 = LD32(r14 + 32);
                            ST32(r3, (r1 + r2));
                            r1 = LD32(0x0608F444);
                            r7 = LD32(r14 + 4);
                            r0 = r1;
                            ST32(r0 + 172, r7);
                            r9 = LD32(r9 + 44);
                            ST32(r0 + 176, r9);
                            r0 = 1;
                        } else {
                            r0 = 8;
                        }
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606DCEC(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r14;
    FRAME(sp, 40);

    r14 = sp - 40;
    r8 = r5;
    r9 = r4 + 28;
    r12 = 0x0608F444;
    r1 = LD32(0x0608F444);
    r11 = 172;
    r10 = 176;
    r0 = r1;
    ST32(r0 + 176, 0);
    ST32(r0 + 172, 0);
    ST32(r14, 3);
    r0 = GCALL2(0x0606FB9C, r9, r14);
    if (!((r8 & r8) == 0)) {
        r0 = GCALL0(0x060715F8);
    }
    r0 = GCALL1(0x0606F8AC, r9);
    r0 = GCALL1(0x0606FC14, r9);
    if (!((r0 & r0) == 0)) {
        r0 = GCALL1(0x0606FC2C, r9);
        r0 = GCALL2(0x0606DEF4, (r14 + 8), 0);
        r3 = LD32(r12);
        r1 = LD32(r14 + 8);
        r0 = r3;
        r2 = LD32(r0 + r10);
        if (!(r2 > r1)) {
            ST32(r0 + r11, r2);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606DD8C(int r4)
{
    int r0, r1, r5, r8, r14, c1;
    FRAME(sp, 32);

    r14 = sp - 32;
    r8 = r4;
    r0 = GCALL1(0x0606FC14, (r4 + 28));
    r1 = 3;
    if ((r0 & r0) == 0) {
        r0 = 8;
    } else {
        ST32(r14, r1);
        ST32(r14 + 8, r1);
        ST8((r14 + 16), -1);
        r5 = LD32(r8 + 56);
        r0 = GCALL2(0x060701D4, r14, r5);
        c1 = (r0 & r0) == 0;
        r0 = 2;
        if (!(c1)) {
            r0 = 8;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606DDD4(int r4)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL1(0x0606F8D4, (r4 + 28));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606DDEC(int r4, int r5)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL3(0x0606F934, r4, r5, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606DF8C(int r4)
{
    int r0, c2;
    FRAME(sp, 4);

    r0 = r4;
    if (((64 & r0) & (64 & r0)) == 0) {
        if (((16 & r0) & (16 & r0)) == 0) {
            r0 = 0x800;
        } else {
            c2 = ((r0 & 8) & (r0 & 8)) == 0;
            r0 = 0x914;
            if (!(c2)) {
                r0 = 0;
            }
        }
    } else {
        r0 = 0x930;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E240(int r4, int r5, int r6)
{
    int r0, r8, r9, r10, r11, r12, r13, c1;
    FRAME(sp, 32);

    r9 = r4;
    r11 = r6;
    r8 = 0;
    r12 = r5;
    if (0 >= r11) {
        r0 = -1;
    } else {
        r13 = 0x060752FC;
        r10 = r9 + 11;
        while (1) {
            r0 = GCALL3(r13, r12, (r9 + 12), 12);
            c1 = (r0 & r0) == 0;
            r0 = r8;
            if (c1) {
                break;
            } else {
                r0 = LD8(r10);
                r8 = r8 + 1;
                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                    r0 = -1;
                    break;
                } else {
                    r10 = r10 + 24;
                    r9 = r9 + 24;
                    if (!(r8 >= r11)) {
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
int f0606E2F8(void)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL1(0x0606E310, -1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E310(int r4)
{
    int r0, r6, r8, r9, r14, c0, c2, c3, c5;
    FRAME(sp, 20);

    r8 = r4;
    r14 = sp - 20;
    r0 = GCALL1(0x06070A18, 0x00030000);
    r9 = 0x060705A8;
    r6 = r14;
    while (1) {
        r0 = GCALL3(r9, r8, 23, r6);
        c0 = r0 == -5;
        r0 = -7;
        if (c0) {
            break;
        } else {
            r0 = GCALL0(0x06070818);
            c2 = r0 == -16;
            if (r0 == -12) {
                r0 = -22;
                break;
            } else {
                c3 = (r0 & r0) == 0;
                if (c2) {
                    r0 = -25;
                    break;
                } else {
                    r6 = r14;
                    if (!(c3)) {
                        POLL();
                        continue;
                    } else {
                        r0 = GCALL0(0x06070A2C);
                        c5 = (r0 & r0) == 0;
                        if (!(r0 == -16)) {
                            r0 = -1;
                            if (!(c5)) {
                                break;
                            } else {
                                r0 = LD32(r14);
                                break;
                            }
                        } else {
                            r0 = -25;
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
int f0606E384(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 80);

    r14 = sp - 80;
    r9 = r6;
    r8 = r5;
    r0 = GCALL2(0x0606E4B4, r14, r4);
    r11 = 0;
    if (!(r9 > 0)) {
        r1 = r8 - 1;
        r0 = LD8(r1);
        ST8(r1, (r0 | 1));
        r0 = r11;
    } else {
        r10 = r14 + 20;
        r13 = 0x0606E740;
        r12 = 0x0606EAB8;
        while (1) {
            r0 = GCALL2(r13, r14, r10);
            r1 = r14;
            if (!((r0 & r0) == 0)) {
                break;
            } else {
                r1 = LD8((r1 + 28));
                r5 = r10;
                if (((r1 & 255) & (r1 & 255)) == 0) {
                    r1 = r8 - 1;
                    r0 = LD8(r1);
                    ST8(r1, (r0 | 1));
                    r0 = r11;
                    break;
                } else {
                    r0 = GCALL2(r12, r8, r5);
                    r8 = r8 + 12;
                    r9 = r9 - 1;
                    r11 = r11 + 1;
                    if (r9 > 0) {
                        POLL();
                        continue;
                    } else {
                        r1 = r8 - 1;
                        r0 = LD8(r1);
                        ST8(r1, (r0 | 1));
                        r0 = r11;
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
int f0606E59C(int r4, int r5)
{
    int r0, r1, r8, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    r8 = r5;
    r0 = GCALL3(0x0606E4DC, r4, r14, 1);
    ST32(r8, r0);
    r1 = LD8(r14);
    return r1 & 255;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E5C8(int r4, int r5)
{
    int r0, r1, r8, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    r8 = r5;
    r0 = GCALL3(0x0606E4DC, r4, r14, 2);
    ST32(r8, r0);
    r1 = LD16(r14);
    return r1 & 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E5F4(int r4, int r5)
{
    int r0, r1, r8, r9, r10, r11, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r9 = r4;
    r10 = r5;
    r11 = 0x0606E4DC;
    r0 = GCALL3(0x0606E4DC, r4, r14, 2);
    ST32(r10, r0);
    if (!((r0 & r0) == 0)) {
        r0 = 0;
    } else {
        r8 = r14 + 2;
        r0 = GCALL3(r11, r9, r8, 2);
        ST32(r10, r0);
        if (!((r0 & r0) == 0)) {
            r0 = 0;
        } else {
            r1 = LD16(r8);
            r0 = r1 & 0xFFFF;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E648(int r4, int r5)
{
    int r0, r8, r9, r10, r14;
    FRAME(sp, 28);

    r14 = sp - 28;
    r8 = r4;
    r9 = r5;
    r10 = 0x0606E4DC;
    r0 = GCALL3(0x0606E4DC, r4, r14, 4);
    ST32(r9, r0);
    if (!((r0 & r0) == 0)) {
        r0 = 0;
    } else {
        r0 = GCALL3(r10, r8, (r14 + 4), 4);
        ST32(r9, r0);
        if (!((r0 & r0) == 0)) {
            r0 = 0;
        } else {
            r0 = LD32(r14 + 4);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E6BC(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r8, r10, r11, c4;
    FRAME(sp, 24);

    r8 = r4;
    r11 = 0x0606E59C;
    r10 = r5;
    r0 = GCALL2(0x0606E59C, r4, r5);
    r1 = LD32(r10);
    r0 = r0 & 255;
    if (!((r1 & r1) == 0)) {
        r0 = 0;
    } else {
        if ((r0 & r0) == 0) {
            r1 = LD32(r8 + 12);
            r2 = LD32(r8 + 16);
            r1 = r1 + 1;
            ST32(r8 + 12, r1);
            if (!(r1 >= r2)) {
                r6 = LD32(r8 + 4);
                r4 = LD32(r8);
                r0 = GCALL4(0x0606B008, r4, 1, r6, 0x800);
                c4 = r0 > 0;
                if (r0 == 0x800) {
                    ST32(r8 + 8, 0);
                    r0 = GCALL2(r11, r8, r10);
                    r1 = LD32(r10);
                    r0 = r0 & 255;
                    if (!((r1 & r1) == 0)) {
                        r0 = 0;
                    }
                } else {
                    r3 = -1;
                    if (!(c4)) {
                        ST32(r10, r0);
                    } else {
                        ST32(r10, r3);
                    }
                    r0 = 0;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606EB24(int r4)
{
    int r0, r8;
    FRAME(sp, 12);

    r8 = r4;
    ST32(r8, 0);
    ST32(r8 + 4, 0);
    ST32(r8 + 8, 0);
    ST32(r8 + 12, 0);
    ST32(r8 + 16, 0);
    ST32(r8 + 20, 1);
    ST32(r8 + 24, 0);
    ST32(r8 + 28, 0);
    ST32(r8 + 32, 0);
    r0 = GCALL2(0x0606EB7C, r4, 1);
    ST32(r8 + 52, 0);
    r0 = GCALL2(0x0606EB68, r8, 3);
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606EB88(int r4, int r5)
{
    int r0, r1, r3, c2;
    FRAME(sp, 4);

    ST32(r4 + 24, r5);
    r3 = 0;
    r0 = LD32(r4 + 52);
    ST32(r4 + 28, 0);
    if (r0 == 6) {
        ST32(r4 + 52, r3);
        r0 = LD32(r4 + 56);
        c2 = r0 == 3;
        if (!((unsigned)(r0 - 1) > (unsigned)1)) {
            r1 = LD32(r4 + 8);
            ST32(r4 + 8, (((int)((unsigned)(r1 + 3) >> 2)) << 2));
        } else {
            if (c2) {
                r1 = LD32(r4 + 8);
                ST32(r4 + 8, (((int)((unsigned)(r1 + 3) >> 2)) << 2));
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606EF3C(int r4)
{
    int r0, r1, r2, r8, r9, r10, c1;
    FRAME(sp, 20);

    r9 = r4;
    r2 = LD32(r9 + 44);
    if (!(r2 > 1)) {
        r1 = LD32(r9 + 12);
        r10 = 0x0606F498;
        r2 = LD32(r1 + 8);
        r1 = LD32(r9 + 32);
        r8 = r2 - r1;
        r0 = GCALL1(0x0606F498, r9);
        c1 = r8 >= r0;
        r0 = r8;
        if (!(c1)) {
            r8 = r0;
        } else {
            r0 = GCALL1(r10, r9);
            r8 = r0;
        }
    } else {
        r1 = LD32(r9 + 12);
        r8 = LD32(r1 + 8);
    }
    r0 = GCALL2(0x0606F4B0, r9, r8);
    ST32(r9 + 16, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F040(void)
{
    int r0, r2, r14;
    FRAME(sp, 12);

    r14 = sp - 12;
    r0 = GCALL2(0x0606D144, r14, 0);
    r0 = LD32(r14);
    r2 = 0;
    if (r0 == 1) {
        r0 = 1;
    } else {
        ST32(0x0608F448, r2);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F080(int r4, int r5, int r6, int r7)
{
    int r0, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 88);

    r14 = sp - 88;
    r9 = r4;
    ST32(r14 + 52, r7);
    r13 = LD32((88 + r14));
    r11 = r5;
    r12 = LD32((92 + r14));
    r8 = (int)((unsigned)r12 >> 2);
    r10 = r6;
    if (r8 > 0) {
        r0 = GCALL1(0x06071B48, r4);
        ST32(r14, 0);
        ST32(r14 + 4, 1);
        ST32(r14 + 8, 15);
        r0 = GCALL1(0x060719E8, r14);
        r3 = LD32(r14 + 52);
        ST32(r14 + 16, r11);
        ST32(r14 + 20, r8);
        ST32(r14 + 12, r3);
        if (!(r10 > 0)) {
            r3 = 2;
            if (r10 >= 0) {
                r3 = 0;
            }
        } else {
            r3 = 1;
        }
        ST32(r14 + 24, r3);
        if (!(r13 > 0)) {
            r3 = 2;
            if (r13 >= 0) {
                r3 = 0;
            }
        } else {
            r3 = 1;
        }
        ST32(r14 + 28, r3);
        ST32(r14 + 32, 0x800);
        ST32(r14 + 36, 0x200);
        ST32(r14 + 40, 0);
        ST32(r14 + 48, 0x2FF);
        r0 = GCALL2(0x06071A30, (r14 + 12), r9);
        r0 = GCALL1(0x06071B34, r9);
        r0 = GCALL2(0x0606C668, r11, r12);
    }
    r0 = r12 & 3;
    ST32(0x0608975C, r0);
    r3 = LD32(r14 + 52);
    ST32(0x06089764, (((r8 * r10) << 2) + r11));
    ST32(0x06089760, (((r8 * r13) << 2) + r3));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F170(int r4)
{
    int r0, r5, r6, c0;
    FRAME(sp, 8);

    r0 = GCALL1(0x06071B8C, r4);
    c0 = (r0 & r0) == 0;
    r0 = c0;
    if (!(c0)) {
        r6 = LD32(0x06089760);
        r5 = LD32(0x06089764);
        r4 = LD32(0x0608975C);
        r0 = GCALL3(0x0606F464, r4, r5, r6);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F1A8(void)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL0(0x0606F074);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F1C0(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    FRAME(sp, 16);

    r2 = LD32(sp);
    ST32((sp - 12), r2);
    ST32((sp - 16), r7);
    r0 = GCALL6(0x0606F080, 0, r4, r5, r6, LD32((sp - 16)), LD32((sp - 12)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F1E4(void)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL1(0x0606F170, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F1FC(void)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL0(0x0606F074);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F214(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    FRAME(sp, 16);

    r2 = LD32(sp);
    ST32((sp - 12), r2);
    ST32((sp - 16), r7);
    r0 = GCALL6(0x0606F080, 1, r4, r5, r6, LD32((sp - 16)), LD32((sp - 12)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F238(void)
{
    int r0;
    FRAME(sp, 8);

    r0 = GCALL1(0x0606F170, 1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F2A8(int r4)
{
    int r0, r1, r2, r3;
    FRAME(sp, 8);

    r0 = LD32(r4 + 56);
    r1 = LD32(r4 + 16);
    r2 = LD32(r1);
    if ((r0 & r0) == 0) {
        r3 = r2 & 0x0FFFFFFF;
        r2 = r3;
        if (!((unsigned)(r3 + ((int)0xFFE00000)) > (unsigned)0x000FFFFF)) {
            r0 = 3;
            r1 = 3;
        } else {
            r1 = r0;
            if (!((unsigned)(r2 + ((int)0xFE000000)) > (unsigned)0x038FFFFF)) {
                r0 = 3;
                r1 = 3;
            }
        }
        r0 = LD32((((r1 + r1) + r0) << 2) + 0x0606EAF4);
        r0 = GCALL1(r0, r4);
    } else {
        r1 = r0;
        if (!(r0 == 4)) {
            r0 = LD32((((r1 + r1) + r0) << 2) + 0x0606EAF4);
            r0 = GCALL1(r0, r4);
        } else {
            r0 = 1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F318(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c4;
    FRAME(sp, 28);

    r9 = r4 + 108;
    r8 = LD32(r9 + 12);
    r0 = LD32(r9 + 56);
    r10 = LD32(r9 + 16);
    if (!(r0 == 4)) {
        r1 = LD32(r9 + 32);
        r5 = r4;
        if (!((r1 & r1) == 0)) {
            r7 = LD32(r8 + 4);
            r1 = LD32(r9 + 32);
            r5 = LD32(r10 + 4);
            r0 = LD32(r9 + 56);
            r4 = LD32(r10);
            r2 = r7 * r1;
            r1 = LD32(r8);
            r8 = LD32(r10 + 8);
            r6 = r2 + r1;
            if (!((r0 & r0) == 0)) {
                r1 = r0;
            } else {
                r3 = r4 & 0x0FFFFFFF;
                r2 = r3;
                if (!((unsigned)(r3 + ((int)0xFFE00000)) > (unsigned)0x000FFFFF)) {
                    r0 = 3;
                    r1 = r0;
                } else {
                    r1 = r0;
                    if (!((unsigned)(r2 + ((int)0xFE000000)) > (unsigned)0x038FFFFF)) {
                        r0 = 3;
                        r1 = r0;
                    }
                }
            }
            r1 = LD32(((((r1 + r1) + r0) << 2) + 0x0606EAF4) + 4);
            ST32((sp - 28), r8);
            r0 = GCALL5(r1, r4, r5, r6, r7, LD32((sp - 28)));
            r1 = LD32(r9 + 32);
            ST32(r9 + 32, (r1 + r8));
            r0 = 1;
        } else {
            r0 = GCALL4(0x0606F5EC, r8, (r5 + 12), r6, r7);
            c4 = (r0 & r0) == 0;
            r0 = 0;
            if (!(c4)) {
                r7 = LD32(r8 + 4);
                r1 = LD32(r9 + 32);
                r5 = LD32(r10 + 4);
                r0 = LD32(r9 + 56);
                r4 = LD32(r10);
                r2 = r7 * r1;
                r1 = LD32(r8);
                r8 = LD32(r10 + 8);
                r6 = r2 + r1;
                if (!((r0 & r0) == 0)) {
                    r1 = r0;
                } else {
                    r3 = r4 & 0x0FFFFFFF;
                    r2 = r3;
                    if (!((unsigned)(r3 + ((int)0xFFE00000)) > (unsigned)0x000FFFFF)) {
                        r0 = 3;
                        r1 = r0;
                    } else {
                        r1 = r0;
                        if (!((unsigned)(r2 + ((int)0xFE000000)) > (unsigned)0x038FFFFF)) {
                            r0 = 3;
                            r1 = r0;
                        }
                    }
                }
                r1 = LD32(((((r1 + r1) + r0) << 2) + 0x0606EAF4) + 4);
                ST32((sp - 28), r8);
                r0 = GCALL5(r1, r4, r5, r6, r7, LD32((sp - 28)));
                r1 = LD32(r9 + 32);
                ST32(r9 + 32, (r1 + r8));
                r0 = 1;
            }
        }
    } else {
        r5 = LD32(r8 + 12);
        r0 = LD32(r9 + 40);
        r4 = LD32(r9 + 36);
        r0 = GCALL4(r0, r4, r5, r6, r7);
        if (!(r0 >= 0)) {
            ST32(r8 + 8, r0);
            r0 = 0;
        } else {
            ST32(r8 + 12, r0);
            ST32(r10 + 12, r0);
            r1 = LD32(r9 + 44);
            r11 = r0 * r1;
            ST32(r8 + 8, r11);
            ST32(r10 + 8, r11);
            ST32(r9 + 32, r11);
            r0 = 1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F3F0(int r4)
{
    int r0, r1, r2, r3;
    FRAME(sp, 8);

    r0 = LD32(r4 + 56);
    r1 = LD32(r4 + 16);
    r2 = LD32(r1);
    if ((r0 & r0) == 0) {
        r3 = r2 & 0x0FFFFFFF;
        r2 = r3;
        if (!((unsigned)(r3 + ((int)0xFFE00000)) > (unsigned)0x000FFFFF)) {
            r0 = 3;
            r1 = r0;
        } else {
            r1 = r0;
            if (!((unsigned)(r2 + ((int)0xFE000000)) > (unsigned)0x038FFFFF)) {
                r0 = 3;
                r1 = r0;
            }
        }
        r0 = LD32(((((r1 + r1) + r0) << 2) + 0x0606EAF4) + 8);
        r0 = GCALL1(r0, r4);
    } else {
        if (!(r0 == 4)) {
            r1 = r0;
            r0 = LD32(((((r1 + r1) + r0) << 2) + 0x0606EAF4) + 8);
            r0 = GCALL1(r0, r4);
        } else {
            r1 = LD32(r1 + 12);
            r0 = (int)((unsigned)(((int)((unsigned)r1 >> 16)) + ((int)((unsigned)r1 >> 16))) >> 16);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606F464(int r4, int r5, int r6)
{
    int r0, r1, r14;
    FRAME(sp, 8);

    r14 = sp - 8;
    if (r4 > 0) {
        r6 = LD32(r6);
        r0 = 0;
        ST32(r14, r6);
        if (!(0 >= r4)) {
            do {
                r1 = LD8(r0 + r14);
                ST8(r5, r1);
                r0 = r0 + 1;
                r5 = r5 + 1;
            } while (AGAIN(!(r0 >= r4)));
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F4B0(int r4, int r5)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r1 = LD32(0x0608F444);
    r0 = r1 + 0x44C;
    r1 = LD32(r0 + 16);
    if (!((r1 & r1) == 0)) {
        r0 = 0;
    } else {
        r1 = LD32(r4);
        r2 = LD32(r4 + 8);
        ST32(r0, (r1 + r2));
        ST32(r0 + 4, 1);
        ST32(r0 + 8, r5);
        ST32(r0 + 16, 1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F4E4(int r4, int r5)
{
    int r0, r1, r2;
    FRAME(sp, 4);

    r0 = LD32(r4 + 56);
    if (!(r0 == 4)) {
        r1 = LD32(r4 + 8);
        r2 = LD32(r5 + 8);
        ST32(r4 + 8, (r1 + r2));
    }
    ST32(r5 + 16, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F56C(int r4)
{
    int r0, r1;
    FRAME(sp, 8);

    r1 = LD32(r4 + 40);
    r0 = LD32(((r1 << 2) << 2) + 0x0606F53C);
    r0 = GCALL1(r0, (r4 + 12));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F594(int r4)
{
    int r0, r1;
    FRAME(sp, 8);

    r1 = LD32(r4 + 40);
    r0 = LD32(((r1 << 2) << 2) + 0x0606F53C);
    r0 = GCALL3(r0, (r4 + 12), 0xFFFF, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F5C4(int r4)
{
    int r0, r1;
    FRAME(sp, 8);

    r1 = LD32(r4 + 40);
    r0 = LD32((((r1 << 2) << 2) + 0x0606F53C) + 4);
    r0 = GCALL1(r0, (r4 + 12));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F610(int r4)
{
    int r0, r1;
    FRAME(sp, 8);

    r1 = LD32(r4 + 40);
    r1 = LD32((((r1 << 2) << 2) + 0x0606F53C) + 12);
    r0 = GCALL1(r1, (r4 + 12));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F644(int r4)
{
    int r0, r1, r2, r5, r7, r8, r9, r10, r11, r14, c0, c3, c4, c5;
    FRAME(sp, 44);

    r14 = sp - 40;
    r8 = r4;
    r9 = r8 + 28;
    ST32(r9, 0);
    ST32(r8 + 52, 1);
    r10 = -1;
    r7 = LD8((r8 + 14));
    ST8(r14, r7);
    r1 = r14 + 1;
    ST8(r1, 0);
    ST8((r14 + 2), 0);
    ST8((r14 + 3), 0);
    ST8((r14 + 4), 0);
    ST8((r14 + 5), 0);
    ST8((r8 + 44), r7);
    r2 = LD8(r1);
    r1 = r1 + 1;
    ST8((r8 + 45), r2);
    r2 = LD8(r1);
    r1 = r1 + 1;
    ST8((r8 + 46), r2);
    r2 = LD8(r1);
    r1 = r1 + 1;
    ST8((r8 + 47), r2);
    r2 = LD8(r1);
    ST8((r8 + 48), r2);
    r1 = LD8((r1 + 1));
    ST8((r8 + 49), r1);
    ST32(r8 + 56, -1);
    ST32(r9 + 36, 0);
    ST32(r8 + 60, 0);
    ST32(r9 + 44, 0);
    ST32(r9 + 40, 0);
    r0 = GCALL1(0x0606FEE0, (r14 + 8));
    c0 = (r0 & r0) == 0;
    r0 = 0;
    if (c0) {
        r11 = LD32(r14 + 8);
        ST32(r8 + 32, r11);
        r0 = GCALL1(0x0606FE74, (r14 + 12));
        r11 = 0;
        if ((r0 & r0) == 0) {
            r4 = LD32(r14 + 12);
            r5 = LD32(r8 + 52);
            ST32(r8 + 40, r4);
            ST32((sp - 44), r11);
            r0 = GCALL5(0x06070070, r4, r5, r14, 0, LD32((sp - 44)));
            if (!((r0 & r0) == 0)) {
                r0 = 0;
            } else {
                r5 = LD32(r14 + 8);
                r4 = LD32(r14 + 12);
                r0 = GCALL3(0x0607061C, r4, r5, (r10 & 255));
                c3 = (r0 & r0) == 0;
                r0 = 0;
                if (c3) {
                    r0 = GCALL0(0x06070A2C);
                    c4 = (r0 & r0) == 0;
                    r0 = 0;
                    if (c4) {
                        r0 = GCALL1(0x0606F8AC, r9);
                        c5 = (r0 & r0) == 0;
                        r0 = 0;
                        if (c5) {
                            r0 = 1;
                        }
                    }
                }
            }
        } else {
            r4 = LD32(r14 + 8);
            r0 = GCALL1(0x0606FF14, r4);
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F764(int r4)
{
    int r0, r8;
    FRAME(sp, 12);

    r8 = r4;
    r4 = LD32(r8 + 4);
    r0 = GCALL1(0x0606FF14, r4);
    r4 = LD32(r8 + 12);
    r0 = GCALL1(0x0606FEB0, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F844(int r4, int r5, int r6)
{
    int r0, r1, r2;
    FRAME(sp, 16);

    ST32(r4 + 24, r5);
    r1 = r6;
    r2 = LD8(r1);
    r1 = r1 + 1;
    ST8((r4 + 16), r2);
    r2 = LD8(r1);
    r1 = r1 + 1;
    ST8((r4 + 17), r2);
    r2 = LD8(r1);
    r1 = r1 + 1;
    ST8((r4 + 18), r2);
    r2 = LD8(r1);
    r1 = r1 + 1;
    ST8((r4 + 19), r2);
    r2 = LD8(r1);
    ST8((r4 + 20), r2);
    r1 = LD8((r1 + 1));
    ST8((r4 + 21), r1);
    r4 = LD32(r4 + 12);
    ST32((sp - 16), 0);
    r0 = GCALL5(0x06070070, r4, r5, r6, 0, LD32((sp - 16)));
    if ((r0 & r0) == 0) {
        r0 = GCALL0(0x06070A2C);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F8AC(int r4)
{
    int r0;
    FRAME(sp, 8);

    r4 = LD32(r4 + 4);
    r0 = GCALL3(0x06070340, r4, 0, -1);
    r0 = GCALL0(0x06070A2C);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F8E4(int r4)
{
    int r0, r1, r2, r14;
    FRAME(sp, 16);

    r14 = sp - 12;
    r4 = LD32(r4 + 4);
    ST32((sp - 16), 0);
    r0 = GCALL5(0x06070234, r4, 0, 0xFFFF, r14, LD32((sp - 16)));
    if (!((r0 & r0) == 0)) {
        r0 = -1;
    } else {
        r0 = GCALL0(0x06070A2C);
        r1 = LD32(r14);
        if ((r0 & r0) == 0) {
            r2 = 0;
            if (!(r1 >= 0)) {
                ST32(r14, r2);
            }
            r0 = LD32(r14);
        } else {
            r0 = -1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FA30(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r14, c6;
    FRAME(sp, 60);

    r14 = sp - 44;
    r9 = r4;
    r6 = r5;
    r1 = LD32(0x0608F444);
    r8 = r1 + 0x438;
    r1 = LD32(r8 + 16);
    r10 = r9 + 28;
    if (!((r1 & r1) == 0)) {
        r0 = 0;
    } else {
        r5 = LD32(r10 + 36);
        r4 = LD32(r9 + 32);
        ST32((sp - 48), (r14 + 4));
        r0 = GCALL5(0x06070234, r4, r5, r6, r14, LD32((sp - 48)));
        if (!((r0 & r0) == 0)) {
            r0 = 0;
        } else {
            r0 = GCALL0(0x06070A2C);
            r1 = LD32(r14 + 4);
            if (!((r0 & r0) == 0)) {
                r0 = 0;
            } else {
                r7 = r14;
                if (r1 > 0) {
                    ST32((sp - 48), 0);
                    ST32((sp - 52), 0);
                    ST32((sp - 56), (r14 + 16));
                    ST32((sp - 60), (r14 + 12));
                    r0 = GCALL8(0x0606DB24, r9, 0, 0, (r7 + 8), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                    r0 = GCALL8(0x0606F8D4, r10, 0, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                    r3 = LD32(r14);
                    r1 = LD32(r14 + 12);
                    if ((r0 + r3) >= r1) {
                        r1 = LD32(r14 + 16);
                        c6 = r3 > 0;
                        if (!((r1 & r1) == 0)) {
                            r2 = LD32(r14 + 8);
                            if (c6) {
                                r2 = r2 - r1;
                                r1 = LD32(r14 + 4);
                                ST32(r14 + 4, (r1 - r2));
                            }
                        }
                    }
                    r0 = GCALL0(0x0606C2D8);
                    ST32(r8 + 4, 0);
                    r11 = LD32(r14 + 4);
                    ST32(r8, r0);
                    ST32(r8 + 8, r11);
                    r11 = LD32(r14);
                    r0 = r8;
                    ST32(r8 + 12, r11);
                    ST32(r8 + 16, 1);
                } else {
                    r0 = 0;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FB10(int r4, int r5)
{
    int r0, r1, r6, c0, c1;
    FRAME(sp, 8);

    r6 = LD32(r4 + 12);
    r1 = LD32(r5 + 36);
    r4 = LD32(r5 + 4);
    r0 = GCALL3(0x0607029C, r4, r1, r6);
    c0 = (r0 & r0) == 0;
    r0 = 0;
    if (c0) {
        r0 = GCALL0(0x06070A2C);
        c1 = (r0 & r0) == 0;
        r0 = 0;
        if (c1) {
            r0 = 1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FB54(int r4, int r5, int r6)
{
    int r0, r8, r9, r10, r14;
    FRAME(sp, 24);

    r14 = sp - 24;
    r10 = r4;
    r9 = r5;
    r8 = r6;
    r0 = GCALL1(0x060702F8, r14);
    r6 = 1;
    if (r8 == -1) {
        r8 = LD32(r9 + 12);
    }
    r0 = GCALL3(0x0606F934, r10, r8, r6);
    ST32(r9 + 16, 0);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FB9C(int r4, int r5)
{
    int r0, r1;
    FRAME(sp, 8);

    r1 = r5;
    r5 = LD32(r4 + 28);
    r0 = GCALL2(0x0607047C, r1, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FBB8(int r4)
{
    int r0, r5, c0, c1;
    FRAME(sp, 8);

    r5 = LD32(r4 + 28);
    r4 = LD32(r4 + 12);
    r0 = GCALL2(0x0607017C, r4, r5);
    c0 = (r0 & r0) == 0;
    r0 = 0;
    if (c0) {
        r0 = GCALL0(0x06070A2C);
        c1 = (r0 & r0) == 0;
        r0 = 0;
        if (c1) {
            r0 = 1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FBEC(int r4)
{
    int r0, r8;
    FRAME(sp, 12);

    r8 = r4;
    r0 = GCALL0(0x0606FFEC);
    if (!(r0 >= 0)) {
        r0 = 0;
    } else {
        ST32(r8 + 28, r0);
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FC14(int r4)
{
    int r0;
    FRAME(sp, 8);

    r4 = LD32(r4 + 28);
    r0 = GCALL1(0x0607004C, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FC2C(int r4)
{
    int r0;
    FRAME(sp, 8);

    r4 = LD32(r4 + 28);
    r0 = GCALL1(0x06070020, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606FC44(int r4)
{
    int r1, r2, r3;
    FRAME(sp, 4);

    if ((r4 & r4) == 0) {
        r3 = 0x0608F458;
        r1 = LD32(0x0608F458);
        r2 = 0;
    } else {
        r3 = 0x0608F458;
        r1 = LD32(0x0608F458);
        r2 = 1;
    }
    ST8((r1 + 23), r2);
    r1 = LD32(r3);
    ST8((r1 + 47), r2);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FE74(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8;
    FRAME(sp, 8);

    r3 = 0;
    r6 = 0x0608F458;
    r5 = 1;
    r7 = 23;
    while (1) {
        r1 = LD32(r6);
        r2 = (r1 + r3) + 24;
        r1 = LD8(r2);
        r0 = 0;
        if (!((r1 & r1) == 0)) {
            r3 = r3 + 1;
            r8 = -1;
            if (!(r3 > r7)) {
                POLL();
                continue;
            } else {
                ST32(r4, r8);
                r0 = -3;
                break;
            }
        } else {
            ST8(r2, r5);
            ST32(r4, r3);
            break;
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FEB0(int r4)
{
    int r0, r1, r2, c1;
    FRAME(sp, 4);

    if (!((unsigned)r4 > (unsigned)23)) {
        r1 = LD32(0x0608F458);
        r2 = (r1 + r4) + 24;
        r0 = LD8(r2);
        c1 = r0 == 1;
        r0 = -7;
        if (c1) {
            ST8(r2, 0);
            r0 = 0;
        }
    } else {
        r0 = -6;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FEE0(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7;
    FRAME(sp, 4);

    r0 = 0;
    r7 = 0x0608F458;
    r6 = 1;
    r3 = 23;
    while (1) {
        r2 = LD32(r7);
        r1 = LD8(r0 + r2);
        if (!((r1 & r1) == 0)) {
            r0 = r0 + 1;
            r5 = -1;
            if (!(r0 > r3)) {
                POLL();
                continue;
            } else {
                ST32(r4, r5);
                r0 = -4;
                break;
            }
        } else {
            ST8(r0 + r2, r6);
            ST32(r4, r0);
            r0 = 0;
            break;
        }
        POLL();
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606FF14(int r4)
{
    int r0, r1, r2, r8, r9, r10, c4;
    FRAME(sp, 20);

    r1 = 0x0608F454;
    r0 = LD32(0x0608F454);
    r9 = r4;
    if (r0 == -16) {
        ST32(r1, 0);
    }
    r0 = -6;
    if (!((unsigned)r9 > (unsigned)23)) {
        r1 = LD32(0x0608F458);
        r1 = LD8(r1 + r9);
        r0 = -7;
        if (r1 == 1) {
            r0 = GCALL3(0x06070340, r9, 0, -1);
            r8 = 0x06070A18;
            r0 = GCALL1(0x06070A18, 0x00030000);
            r10 = 0x06070398;
            while (1) {
                r0 = GCALL0(0x06070818);
                if (r0 == 3) {
                    POLL();
                    r0 = -12;
                    break;
                } else {
                    c4 = r0 == 2;
                    r0 = -16;
                    if (c4) {
                        break;
                    } else {
                        r0 = GCALL1(r10, r9);
                        if (!(r0 == 1)) {
                            POLL();
                            continue;
                        } else {
                            r0 = GCALL1(r8, 0);
                            r2 = LD32(0x0608F458);
                            ST8(r2 + r9, 0);
                            r0 = 0;
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
int f0606FFEC(void)
{
    int r0, r1, r2, r3;
    FRAME(sp, 4);

    r3 = 0x0608F458;
    r2 = LD32(0x0608F458);
    r0 = LD32(r2 + 48);
    if (!(r0 == 1)) {
        r1 = LD32(r2 + 56);
        ST32(r2 + 48, 1);
        r1 = r1 + 1;
        ST32(r2 + 56, r1);
        if (!(r1 >= 0)) {
            ST32(r2 + 56, 0);
        }
        r1 = LD32(r3);
        r0 = LD32(r1 + 56);
    } else {
        r0 = -5;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606A7F4(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11;
    FRAME(sp, 24);

    r11 = r4;
    r10 = r5;
    ST32(0x0608F448, 0);
    r8 = r6;
    if (!((unsigned)(r11 - 1) > (unsigned)23)) {
        r0 = -21;
        if (((3 & r10) & (3 & r10)) == 0) {
            r2 = 1;
            if ((r8 & r8) == 0) {
                r1 = LD32(0x06000344);
                r0 = GCALL3(r1, -2049, 0, r6);
                r9 = 0x0608F444;
                ST32(0x0608F444, r10);
                r0 = GCALL1(0x0606B9A4, r11);
                r0 = GCALL1(0x0606D8F8, ((r8 & r8) == 0));
                r1 = r0;
                if ((r1 & r1) == 0) {
                    r1 = LD32(r9);
                    r0 = LD32(196 + r1);
                    if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                        r0 = GCALL1(0x0606B898, r8);
                        r8 = r0;
                        if (r8 >= 0) {
                            r0 = GCALL1(0x0606BB88, 0);
                            r1 = r0;
                            r0 = r1;
                            if (r1 >= 0) {
                                r0 = r8;
                            }
                        } else {
                            r0 = GCALL1(0x0606BB88, r8);
                        }
                    } else {
                        r0 = GCALL1(0x0606BB88, -2);
                    }
                } else {
                    r0 = GCALL1(0x0606BB88, r1);
                }
            } else {
                r1 = LD32(r8);
                r0 = -4;
                if (!((unsigned)r1 > (unsigned)r2)) {
                    r1 = LD32(r8 + 4);
                    if (r1 > r2) {
                        r1 = LD32(r8 + 8);
                        if (!((r1 & r1) == 0)) {
                            r1 = LD32(0x06000344);
                            r0 = GCALL3(r1, -2049, 0, r6);
                            r9 = 0x0608F444;
                            ST32(0x0608F444, r10);
                            r0 = GCALL1(0x0606B9A4, r11);
                            r0 = GCALL1(0x0606D8F8, ((r8 & r8) == 0));
                            r1 = r0;
                            if ((r1 & r1) == 0) {
                                r1 = LD32(r9);
                                r0 = LD32(196 + r1);
                                if (!(((r0 & 1) & (r0 & 1)) == 0)) {
                                    r0 = GCALL1(0x0606B898, r8);
                                    r8 = r0;
                                    if (r8 >= 0) {
                                        r0 = GCALL1(0x0606BB88, 0);
                                        r1 = r0;
                                        r0 = r1;
                                        if (r1 >= 0) {
                                            r0 = r8;
                                        }
                                    } else {
                                        r0 = GCALL1(0x0606BB88, r8);
                                    }
                                } else {
                                    r0 = GCALL1(0x0606BB88, -2);
                                }
                            } else {
                                r0 = GCALL1(0x0606BB88, r1);
                            }
                        }
                    }
                }
            }
        }
    } else {
        r0 = -5;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606A9EC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;
    FRAME(sp, 12);

    r5 = r4;
    r1 = LD32(0x0608F444);
    r1 = r1 + 152;
    r4 = LD32(r1 + 8);
    if ((r4 & r4) == 0) {
        r0 = GCALL4(0x0606BB88, -8, 0, r6, r7);
    } else {
        r0 = LD32(r1);
        if (r0 == 1) {
            r6 = LD32(r1 + 4);
            r0 = GCALL3(0x0606E240, r4, r5, r6);
            r8 = r0;
            if (r8 >= 0) {
                r0 = GCALL1(0x0606BB88, 0);
                if (r0 >= 0) {
                    r0 = r8;
                }
            } else {
                r0 = GCALL1(0x0606BB88, -9);
            }
        } else {
            r0 = GCALL4(0x0606BB88, -8, 0, r6, r7);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606ABB0(int r4)
{
    int r0, r1, r2, r5, r8, r9, r10, c7;
    FRAME(sp, 20);

    r2 = LD32(0x0608F444);
    r8 = r2 + 152;
    r1 = LD32(r8 + 8);
    r10 = r4;
    if ((r1 & r1) == 0) {
        r0 = GCALL0(0x0606BAB0);
        r9 = r0;
        r4 = -19;
        if (!((r9 & r9) == 0)) {
            r5 = LD32(r8 + 8);
            r1 = 0;
            if (!((r5 & r5) == 0)) {
                r1 = LD32(r8);
                if (!((r1 & r1) == 0)) {
                    r0 = 0x0606E2B4;
                } else {
                    r0 = 0x0606E2A0;
                }
                r0 = GCALL2(r0, r10, r5);
                r1 = r0;
            }
            r0 = GCALL3(0x0606BCE0, r9, r1, r10);
            r9 = r0;
            if ((r9 & r9) == 0) {
                r0 = GCALL1(0x0606BB88, -10);
                r0 = r9;
            } else {
                r0 = GCALL1(0x0606BB88, 0);
                c7 = r0 >= 0;
                r0 = 0;
                if (c7) {
                    r0 = r9;
                }
            }
        } else {
            r0 = 0x0606BB88;
            r0 = GCALL1(r0, r4);
            r0 = 0;
        }
    } else {
        r4 = -10;
        if (!(r10 >= 0)) {
            r0 = 0x0606BB88;
            r0 = GCALL1(r0, r4);
            r0 = 0;
        } else {
            r1 = LD32(r8 + 12);
            if (!(r10 >= r1)) {
                r0 = GCALL0(0x0606BAB0);
                r9 = r0;
                r4 = -19;
                if (!((r9 & r9) == 0)) {
                    r5 = LD32(r8 + 8);
                    r1 = 0;
                    if (!((r5 & r5) == 0)) {
                        r1 = LD32(r8);
                        if (!((r1 & r1) == 0)) {
                            r0 = 0x0606E2B4;
                        } else {
                            r0 = 0x0606E2A0;
                        }
                        r0 = GCALL2(r0, r10, r5);
                        r1 = r0;
                    }
                    r0 = GCALL3(0x0606BCE0, r9, r1, r10);
                    r9 = r0;
                    if ((r9 & r9) == 0) {
                        r0 = GCALL1(0x0606BB88, -10);
                        r0 = r9;
                    } else {
                        r0 = GCALL1(0x0606BB88, 0);
                        c7 = r0 >= 0;
                        r0 = 0;
                        if (c7) {
                            r0 = r9;
                        }
                    }
                } else {
                    r0 = 0x0606BB88;
                    r0 = GCALL1(r0, r4);
                    r0 = 0;
                }
            } else {
                r0 = 0x0606BB88;
                r0 = GCALL1(r0, r4);
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606AC64(int r4, int r5, int r6, int r7)
{
    int r0, r8;
    FRAME(sp, 12);

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r0 = GCALL4(0x0606BB04, r4, 1, 0, r7);
        r0 = GCALL1(0x0606C1C8, r8);
    }
    r0 = GCALL1(0x0606BB88, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606ADA0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r14;
    FRAME(sp, 20);

    r8 = r4;
    r14 = sp - 20;
    if ((r8 & r8) == 0) {
        r0 = GCALL4(0x0606BB88, -11, 0, r6, r7);
    } else {
        r0 = GCALL4(0x0606AD50, r4, r5, r6, r7);
        r9 = r0;
        r0 = GCALL4(0x0606AE50, r8, 0, r14, 0);
        r0 = GCALL1(0x0606BB88, 0);
        r1 = LD32(r14);
        r0 = r9 >= r1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606AE50(int r4, int r5, int r6, int r7)
{
    int r0, r8, r14;
    FRAME(sp, 32);

    r14 = sp - 16;
    r8 = r5;
    if (!((r4 & r4) == 0)) {
        ST32((sp - 20), r14);
        ST32((sp - 24), 0);
        ST32((sp - 28), r7);
        ST32((sp - 32), r6);
        r0 = GCALL8(0x0606C164, (r4 + 12), 0, 0, r8, LD32((sp - 32)), LD32((sp - 28)), LD32((sp - 24)), LD32((sp - 20)));
        r0 = LD32(r14);
        if ((r0 & 24) == 24) {
            ST32(r8, 0);
        }
    } else {
        r0 = GCALL4(0x0606BB88, -11, 0, r6, r7);
    }
    r0 = GCALL1(0x0606BB88, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606AEA8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r14;
    FRAME(sp, 40);

    r14 = sp - 24;
    r9 = r7;
    r8 = LD32(r14 + 24);
    if (!((r4 & r4) == 0)) {
        ST32((sp - 28), r8);
        ST32((sp - 32), r6);
        ST32((sp - 36), (r14 + 4));
        ST32((sp - 40), r14);
        r0 = GCALL8(0x0606C164, (r4 + 12), r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)), LD32((sp - 32)), LD32((sp - 28)));
        if (!((r8 & r8) == 0)) {
            r1 = LD32(r8);
            ST32(r8, (r1 & -7));
        }
        r1 = LD32(r14);
        if (!((r9 & r9) == 0)) {
            r2 = LD32(r14 + 4);
            ST32(r9, (((((r1 - 1) << 8) + ((r1 - 1) << 8)) << 2) + r2));
        }
    } else {
        r0 = GCALL4(0x0606BB88, -11, 0, r6, r7);
    }
    r0 = GCALL1(0x0606BB88, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B308(int r4, int r5, int r6, int r7)
{
    int r0, r8;
    FRAME(sp, 12);

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        ST32(r8 + 4, 0);
        ST32(r8 + 8, 0);
        r0 = GCALL1(0x0606BC84, r8);
        r0 = GCALL1(0x0606C204, r8);
        r5 = 1;
        if ((r0 & r0) == 0) {
            r5 = 0;
        }
        r0 = GCALL2(0x0606BB04, r8, r5);
        r0 = GCALL1(0x0606AD50, r8);
        r8 = r0;
        r0 = GCALL1(0x0606BB88, 0);
        if (r0 >= 0) {
            r0 = r8;
        }
    } else {
        r0 = GCALL4(0x0606BB88, -11, 0, r6, r7);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B374(int r4, int r5, int r6, int r7)
{
    int r0, r2, r8, r9, r10, r14;
    FRAME(sp, 28);

    r14 = sp - 24;
    r8 = r4;
    r9 = r6;
    if (!((r8 & r8) == 0)) {
        r10 = r8 + 108;
        r2 = LD32(r8 + 4);
        ST32(r5, r2);
        ST32((sp - 28), r14);
        r0 = GCALL5(0x0606AEA8, r8, 0, 0, 0, LD32((sp - 28)));
        r0 = LD32(r14);
        if (((r0 & 64) & (r0 & 64)) == 0) {
            r0 = LD32(r8 + 4);
            if (!(r0 == 2)) {
                r10 = LD32(r10 + 8);
                ST32(r9, r10);
            } else {
                r0 = GCALL1(0x0606F594, r8);
                ST32(r9, r0);
            }
        } else {
            ST32(r9, 0);
        }
    } else {
        r0 = GCALL4(0x0606BB88, -11, 0, r6, r7);
    }
    r0 = GCALL1(0x0606BB88, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606B898(int r4)
{
    int r0, r1, r8, r9;
    FRAME(sp, 16);

    r1 = LD8(0x06000CCC);
    r9 = r4;
    if (!((r1 & 255) == 1)) {
        if (!((r9 & r9) == 0)) {
            r0 = GCALL1(0x0606BEF8, r9);
            r8 = r0;
            if (r8 > 0) {
                r0 = GCALL1(0x0606A984, r9);
                r0 = GCALL1(0x0606BB88, 0);
                r0 = r8;
            } else {
                r0 = GCALL1(0x0606BB88, r8);
            }
        } else {
            r0 = GCALL0(0x0606E2F8);
            r8 = r0;
            if (r0 >= 0) {
                r0 = GCALL1(0x0606A984, r9);
                r0 = GCALL1(0x0606BB88, 0);
                r0 = r8;
            } else {
                r0 = GCALL1(0x0606BB88, -7);
            }
        }
    } else {
        if (!((r9 & r9) == 0)) {
            r0 = GCALL1(0x0606FC44, 1);
        }
        r0 = GCALL0(0x0606E2F8);
        r4 = 0;
        if (!(r0 >= 0)) {
            r0 = GCALL1(0x0606BB88, -7);
        } else {
            r1 = LD32(0x0608F444);
            r1 = r1 + 152;
            ST32(r1 + 8, 0);
            ST32(r1 + 12, 0);
            ST32(r1 + 4, 0);
            r0 = GCALL1(0x0606A984, r4);
            if (!((r9 & r9) == 0)) {
                r0 = GCALL1(0x0606FC44, 0);
            }
            r4 = LD16(0x06000CCE);
            r0 = GCALL2(0x0606A8DC, (r4 & 0xFFFF), r9);
            r8 = r0;
            r0 = GCALL1(0x0606A984, r9);
            r0 = GCALL1(0x0606BB88, 0);
            r0 = r8;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606BD38(int r4)
{
    int r0, r6, r7, r8, r9, r10, r11, r14;
    FRAME(sp, 48);

    r14 = sp - 48;
    r11 = r4;
    r0 = GCALL0(0x0606FFB8);
    ST32(r14, (166 + r0));
    r10 = 0x800;
    ST32(r14 + 4, 0x800);
    ST8((r14 + 10), 0);
    ST8((r14 + 11), 0);
    ST8((r14 + 8), 0);
    ST8((r14 + 9), 0);
    r0 = GCALL0(0x0606BAB0);
    r0 = GCALL3(0x0606BCE0, r0, r14, 0);
    r9 = r0;
    r7 = 0x800;
    if ((r9 & r9) == 0) {
        r0 = -1;
    } else {
        r0 = GCALL4(0x0606B008, r9, 1, r11, r7);
        r4 = r14;
        if (r0 == r10) {
            r0 = GCALL1(0x0606B84C, (r4 + 12));
            r8 = LD32(r14 + 20);
            r6 = 6;
            if ((r8 & r8) == 0) {
                r0 = GCALL3(0x060752CC, r11, 0x0606BD30, r6);
                if (!((r0 & r0) == 0)) {
                    r8 = -3;
                }
            }
            r0 = GCALL3(0x0606AC64, r9, 0, r6);
            r0 = r8;
        } else {
            r0 = -1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606BEF8(int r4)
{
    int r0, r1, r6, r8, r9, r10, r14;
    FRAME(sp, 32);

    r14 = sp - 32;
    r10 = r4;
    r0 = GCALL1(0x0606BDFC, r14);
    r9 = r0;
    r8 = 0;
    if ((r9 & r9) == 0) {
        r0 = GCALL0(0x0606BAB0);
        r0 = GCALL3(0x0606BCE0, r0, r14, 0);
        r8 = r0;
    }
    r1 = LD32(0x0608F444);
    r0 = LD32(196 + r1);
    r6 = LD32(r14 + 4);
    if (((r0 & 1) & (r0 & 1)) == 0) {
        r0 = GCALL3(0x0606E1CC, r8, r10, r6);
        r9 = r0;
        if (!((r8 & r8) == 0)) {
            r0 = GCALL1(0x0606AC64, r8);
        }
        r0 = r9;
    } else {
        r0 = r9;
        if (!((r8 & r8) == 0)) {
            r0 = GCALL3(0x0606E1CC, r8, r10, r6);
            r9 = r0;
            if (!((r8 & r8) == 0)) {
                r0 = GCALL1(0x0606AC64, r8);
            }
            r0 = r9;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606C210(int r4)
{
    int r0, r8, r14, c1, c2;
    FRAME(sp, 20);

    r14 = sp - 16;
    r8 = r4;
    ST32((sp - 20), r14);
    r0 = GCALL5(0x0606AEA8, r4, 0, 0, 0, LD32((sp - 20)));
    r0 = LD32((r8 + 92));
    if (!(r0 == 4)) {
        r0 = 0;
    } else {
        r0 = GCALL1(0x0606F594, r8);
        c1 = (r0 & r0) == 0;
        r0 = LD32(r14);
        if (c1) {
            r0 = 1;
        } else {
            c2 = ((r0 & 64) & (r0 & 64)) == 0;
            r0 = 0;
            if (!(c2)) {
                r0 = 1;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606E1CC(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r14;
    FRAME(sp, 28);

    r14 = sp - 24;
    r9 = r4;
    r8 = r5;
    r10 = r6;
    if ((r9 & r9) == 0) {
        r1 = LD32(r8);
        if (!((r1 & r1) == 0)) {
            r6 = LD32(r8 + 4);
            r0 = 0x0606E408;
        } else {
            r0 = 0x0606E384;
            r6 = LD32(r8 + 4);
        }
        r5 = LD32(r8 + 8);
        r0 = GCALL3(r0, r9, r5, r6);
    } else {
        ST32((sp - 28), r14);
        r0 = GCALL5(0x0606AEA8, r4, 0, 0, 0, LD32((sp - 28)));
        r0 = LD32(r14);
        if (!(((r0 & 128) & (r0 & 128)) == 0)) {
            r0 = GCALL2(0x0606B258, r9, r10);
            if ((r0 & r0) == 0) {
                r1 = LD32(r8);
                if (!((r1 & r1) == 0)) {
                    r6 = LD32(r8 + 4);
                    r0 = 0x0606E408;
                } else {
                    r0 = 0x0606E384;
                    r6 = LD32(r8 + 4);
                }
                r5 = LD32(r8 + 8);
                r0 = GCALL3(r0, r9, r5, r6);
            }
        } else {
            r0 = -6;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606EBF8(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r8, r9, r10, r11, r12, r13, r14, c3;
    FRAME(sp, 36);

    r14 = sp - 36;
    r9 = r4;
    r8 = r9 + 108;
    r1 = LD32(0x0608F444);
    r0 = 200;
    ST32(200 + r1, 0);
    r2 = LD32(r8 + 52);
    r13 = r5;
    if (!((r2 & r2) == 0)) {
        r12 = 0x0606EDAC;
        r11 = r0;
        r10 = 0x00600000;
        r2 = r2 - 6;
        while (1) {
            r5 = r14;
            if (!((unsigned)r2 > (unsigned)1)) {
                break;
            } else {
                r0 = GCALL2(r12, r9, r5);
                r2 = LD32(0x0608F444);
                r2 = r2 + r11;
                r1 = LD32(r2);
                r1 = r1 + 1;
                ST32(r2, r1);
                if (r1 > r10) {
                    break;
                } else {
                    r2 = LD32(r8 + 52);
                    c3 = (r2 & r2) == 0;
                    r2 = r2 - 6;
                    if (!(c3)) {
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
    r5 = LD32(r8 + 12);
    r6 = r13;
    if (!((r5 & r5) == 0)) {
        r0 = GCALL3(0x0606F610, r9, r5, r6);
        r2 = LD32(r8 + 12);
        r1 = LD32(r8 + 28);
        r2 = LD32(r2 + 12);
        ST32(r8 + 28, (r1 + r2));
        ST32(r8 + 12, 0);
    }
    r5 = LD32(r8 + 16);
    r3 = 6;
    if (!((r5 & r5) == 0)) {
        r0 = GCALL2(0x0606F4E4, r8, r5);
        ST32(r8 + 16, 0);
        r3 = 6;
    }
    ST32(r8 + 52, r3);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060604C0(int r4, int r5, int r6)
{
    int r0;

    ST32(r5, r4);
    r0 = GCALL2(0x06054FBC, r6, r4);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060605DC(int r4, int r5, int r6)
{
    int r0;

    ST8(r5, r4);
    r0 = GCALL2(0x06054FBC, r6, r4);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06060D10(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;

    r12 = r4;
    r1 = LD32(0x0608D9C8);
    ST8(r1, 3);
    r1 = LD16((r1 + 72));
    r9 = 0;
    if (!(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0)) {
        r13 = 0x0608AD40;
        r10 = 0x060517D0;
        r0 = GCALL1(0x060517D0, 0x0608AD40);
        r8 = r0;
        r14 = 0x0608ADC4;
        r0 = GCALL1(0x0607507C, 0x0608ADC4);
        r4 = (140 + r0) + r8;
        r0 = LD32(0x0608D3A0);
        r0 = GCALL4(r0, (r4 + 2), r5, r6, 0x0607507C);
        r11 = r0;
        r2 = r11;
        if ((r11 & r11) == 0) {
            r2 = r12 + 80;
            r1 = LD32(r2);
            ST32(r2, (r1 + 1));
        } else {
            ST16((r2 + 4), 8);
            ST8(8 + r11, 1);
            r2 = r12 + 6;
            r1 = LD8(r2);
            r1 = r1 + 1;
            ST8(r2, r1);
            ST8((r11 + 9), r1);
            r0 = GCALL1(r10, r13);
            r10 = r0;
            ST8((r11 + 12), r10);
            r9 = r11 + 13;
            r0 = GCALL2(0x060517E4, r13, r9);
            r9 = r9 + r10;
            r0 = GCALL1(0x0607507C, r14);
            r10 = r0;
            ST8(r9, r10);
            r9 = r9 + 1;
            r0 = GCALL3(0x0604B358, r9, r14, r10);
            r4 = (r9 + r10) - (r11 + 8);
            ST16((r11 + 10), r4);
            r6 = r4 + 8;
            r4 = LD16((r12 + 12));
            r0 = GCALL3(0x0605BA98, (r4 & 0xFFFF), r11, r6);
            r9 = r0;
        }
        r2 = r12 + 3;
        r1 = LD8(r2);
        ST8(r2, (r1 - 1));
        r0 = LD32(0x0608D39C);
        r0 = GCALL0(r0);
        r2 = LD32(r12 + 32);
        r1 = LD32(0x0608D394);
        ST32(r12 + 28, ((r2 * r1) + r0));
        ST8((r12 + 4), 1);
        r0 = r9;
    } else {
        r0 = GCALL1(0x0605DBD4, ((int)0xC0230008));
        r0 = GCALL1(0x0605DBD4, ((int)0xC0230006));
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606345C(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11;
    FRAME(sp, 24);

    r10 = r4;
    r11 = r5;
    r8 = r6;
    r9 = r7;
    r0 = GCALL0(0x060643D8);
    if (!(r0 == 2)) {
        r0 = GCALL1(0x0606694C, r10);
        r4 = (r0 << 8) + (r0 << 8);
        r0 = r8;
        r4 = r4 + ((r11 + r11) + 0x25F00000);
        if (!(r0 == 1)) {
            r6 = r8 + r8;
            r0 = GCALL3(0x06062D24, r4, r9, r6);
        } else {
            r9 = LD16(r9);
            ST16(r4, r9);
        }
    } else {
        r0 = GCALL1(0x0606694C, r10);
        r4 = (r0 << 8) << 2;
        r0 = r8;
        r4 = r4 + ((r11 << 2) + 0x25F00000);
        if (!(r0 == 1)) {
            r6 = r8 << 2;
            r0 = GCALL3(0x06062D24, r4, r9, r6);
        } else {
            r9 = LD32(r9);
            ST32(r4, r9);
        }
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606A75C(int r4)
{
    int r0, r1, r2, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    r0 = GCALL0(0x0606A7B8);
    ST32(r14, r0);
    r1 = LD32(r14);
    ST32(r14, (r1 & -241));
    r2 = LD32(r14);
    ST32(r14, (((r4 << 2) << 2) | r2));
    r4 = LD32(r14);
    r0 = GCALL1(0x0606A7A8, r4);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606AD50(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8;
    FRAME(sp, 12);

    r1 = r4;
    if (!((r1 & r1) == 0)) {
        r4 = r1;
        r1 = LD32(r1 + 40);
        r2 = LD32(0x0608F444);
        r0 = LD32(((((r1 << 2) << 2) + 4) + r2) + 12);
        r0 = GCALL4(r0, (r4 + 12), r5, r6, r7);
        r8 = r0;
        r0 = GCALL1(0x0606BB88, 0);
        if (r0 >= 0) {
            r0 = r8;
        }
    } else {
        r0 = GCALL4(0x0606BB88, -11, 0, r6, r7);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606B704(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10;
    FRAME(sp, 20);

    r9 = r4;
    r10 = r5;
    if (!((r9 & r9) == 0)) {
        r8 = r9 + 108;
        r0 = GCALL4(0x0606F514, r8, 0, 0x000FFFFF, 0x800);
        r0 = GCALL2(0x0606EB68, r8, 4);
        r0 = GCALL3(0x0606F528, r9, r10, r9);
    } else {
        r0 = GCALL4(0x0606BB88, -11, 0, r6, r7);
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606C2FC(int r4)
{
    int r0, r1, r2;
    FRAME(sp, 8);

    r1 = LD16(0x06089738);
    r2 = LD16(0x25890008);
    ST16(0x06089738, (r1 | r2));
    r0 = GCALL1(0x0606C32C, (r4 | 1));
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606C33C(void)
{
    int r0;
    FRAME(sp, 12);

    r0 = GCALL1(0x0606C32C, 0xBE1);
    ST16(0x06089738, 0xBE1);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606D2F2(void)
{
    int r0, r2;

    r0 = 20;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606D68E(void)
{
    int r0, r2;

    r0 = -388;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606D694(void)
{
    int r0, r2;

    r0 = -384;
    r2 = LD32(r0 + 0x0608F030);
    if (!((r2 & r2) == 0)) {
        r0 = GCALL0(r2);
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0606F25C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    FRAME(sp, 8);

    r0 = LD32(sp);
    if (!((r4 & r4) == 0)) {
        r2 = (int)((unsigned)r0 >> 2);
        r1 = 0;
        r5 = r5 << 2;
        if (!(0 >= r2)) {
            r7 = r7 << 2;
            do {
                r3 = LD32(r6);
                r1 = r1 + 1;
                ST32(r4, r3);
                r4 = r4 + r5;
                r6 = r6 + r7;
            } while (AGAIN(!(r1 >= r2)));
        }
        r0 = GCALL3(0x0606F464, (r0 & 3), r4, r6);
    }
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0606F5EC(int r4, int r5)
{
    int r0, r1;
    FRAME(sp, 8);

    r5 = r5 + 28;
    r1 = LD32(r5);
    r0 = LD32((((r1 << 2) << 2) + 0x0606F53C) + 8);
    r0 = GCALL2(r0, r4, r5);
    return r0;
}
