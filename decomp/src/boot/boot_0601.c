#include "krnl.h"

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010510(int r4)
{
    int r0, r1, r8, r9, r10, r11;

    r10 = r4;
    r0 = GCALL1(0x0607507C, r4);
    r9 = r0;
    r0 = GCALL3(0x060221DC, r10, 0, (r9 - 1));
    r1 = 100;
    r11 = 0x060221DC;
    if (r0 > 100) {
        r8 = r1;
        r9 = r9 - 1;
        do {
            r0 = GCALL3(r11, r10, 0, r9);
            r9 = r9 - 1;
        } while (AGAIN(r0 > r8));
        r9 = r9 + 1;
    }
    r0 = GCALL3(0x060750A0, 0x060767D0, r10, r9);
    r0 = r9;
    ST8(r0 + 0x060767D0, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601057C(int r4, int r5)
{
    int r0, r8;

    r8 = r5;
    r0 = GCALL1(0x06010510, r4);
    ST32(0x060767E4, r8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010598(int r4)
{
    int r0;

    r0 = GCALL2(0x0603CCE0, 0x060767CC, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06010B20(int r4)
{
    int v4;

    v4 = 0;
    do {
        v4 = v4 + 1;
    } while (AGAIN(!(v4 >= r4)));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010EE0(void)
{
    int r0;
    int v20;
    int v24;

    ST8(0x0608AD40, 17);
    r0 = GCALL6(0x06032A08, 0, 0x06010ED4, 0x06010ED0, 0x0608AD40, 0x218, 1);
    ST32(0x0607598C, 1);
    ST8(0x0608AF58, 0);
    ST8(0x0608AF4E, 0);
    ST8(0x0608AF4D, 0);
    return 0x0608AD40;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06010F70(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11;

    r11 = r4;
    r10 = r5;
    r8 = LD32(r10);
    r9 = r6;
    if (!((r8 & r8) == 0)) {
        r6 = LD32(r9);
        r1 = LD8(((r6 + r8) - 1));
        r6 = r6 + 1;
        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
            r0 = GCALL4(0x06027C18, 0, r8, r6, r7);
            if (!((r0 & r0) == 0)) {
                ST32(r11, r0);
                r8 = r0;
            } else {
                r1 = LD32(r9);
                ST32(r9, (r1 - 1));
            }
            r0 = LD32(r9);
            ST8(r0 + r8, 0);
        }
        ST32(r10, r8);
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06011118(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, c1;

    r11 = r4;
    r10 = r5;
    r9 = r6;
    r0 = GCALL1(0x0607507C, r9);
    r8 = 0x00601000;
    r0 = GCALL2(0x06075104, 0x06011110, (r9 + (r0 - 4)));
    r2 = 2;
    if ((r0 & r0) == 0) {
        r6 = 0x06075135;
        r7 = 5;
        r3 = 9;
        do {
            r1 = LD8(r9 + r2);
            r5 = r1 & 255;
            r1 = LD8(r5 + r6);
            r8 = (r8 << 2) << 2;
            c1 = ((r1 & 4) & (r1 & 4)) == 0;
            r1 = r5;
            if (!(c1)) {
                r5 = r5 - 48;
                if (!(r5 > r3)) {
                    r2 = r2 + 1;
                } else {
                    r5 = r5 - 17;
                    r2 = r2 + 1;
                }
            } else {
                if ((unsigned)(r1 - 65) > (unsigned)r7) {
                    r5 = 0;
                    r2 = r2 + 1;
                } else {
                    r5 = r5 - 48;
                    if (!(r5 > r3)) {
                        r2 = r2 + 1;
                    } else {
                        r5 = r5 - 17;
                        r2 = r2 + 1;
                    }
                }
            }
            r8 = r8 | r5;
        } while (AGAIN(!(r2 > 7)));
        r0 = GCALL4(0x0604B280, 0x06089B00, 0, r6, r7);
        r0 = GCALL3(0x0604688C, r11, r10, ((r8 << 2) << 2));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060111C0(int r4)
{
    int r1, c0;

    r1 = LD32(0x0608AB68);
    c0 = (r1 & r1) == 0;
    r1 = r1 + 24;
    if (c0) {
        return;
    } else {
        ST16(r1, r4);
        return;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601213C(int r4)
{
    int r0, r1, r8, r9, r10, r11;

    r9 = r4;
    r11 = 0;
    if ((r9 & r9) == 0) {
        r0 = -1;
    } else {
        r1 = LD8(r9);
        r0 = -1;
        if ((r1 & 255) == 35) {
            r8 = LD32(0x060766BC);
            if (!((r8 & r8) == 0)) {
                r10 = 0x06075104;
                while (1) {
                    r4 = LD32(r8);
                    r0 = GCALL2(r10, (r4 + r11), r9);
                    if ((r0 & r0) == 0) {
                        POLL();
                        r0 = LD32(r8 + 4);
                        break;
                    } else {
                        r8 = LD32(r8 + 8);
                        if (!((r8 & r8) == 0)) {
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
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060122D0(void)
{
    int r0, r1, r2, r8;
    FRAME(sp, 24);

    r8 = 0x060767FC;
    r1 = LD8(0x060767FC);
    if ((((signed char)r1) & ((signed char)r1)) == 0) {
        r1 = LD32(0x0608B980);
        r2 = LD32(0x06076800);
        r1 = r1 - r2;
        r2 = LD32(0x060122CC);
        if (((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)(r1 + 5) * (unsigned)r2)) >> 32)) >> 2)) >> 1)) > 0x12C) {
            r1 = LD8(0x0608AF57);
            if ((r1 & r1) == 0) {
                r1 = LD32(0x060769D4);
                if ((r1 & r1) == 0) {
                    r0 = LD32(0x0607668C);
                    r1 = 0;
                    if (!(r0 == 2)) {
                        ST32(sp - 24, r1);
                        ST32(sp - 20, r1);
                        ST32(sp - 16, 0x280);
                        ST32(sp - 12, 0x1E0);
                        r0 = GCALL8(0x06046AA4, (sp - 24), 0x25E00000, 0x400, 0, LD32((sp - 24)), LD32((sp - 20)), LD32((sp - 16)), LD32((sp - 12)));
                        ST8(r8, 1);
                    }
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601258C(int r4)
{
    int r0, r1, r5;

    ST32(0x06075988, 0);
    r1 = LD32(r4);
    r1 = LD32(0x10E4 + r1);
    ST32(r1 + 4, 0);
    r1 = LD32(r4);
    r1 = LD32(0x10E4 + r1);
    ST32(r1 + 8, 0);
    r5 = LD32(0x060767CC);
    r4 = LD32(r4 + 12);
    r0 = GCALL2(0x0603CCE0, r4, r5);
    return -21;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060125C0(int r4)
{
    int r0;

    r4 = LD32(r4);
    r0 = GCALL2(0x06033A1C, r4, 0);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060125D4(int r4)
{
    int r0;

    r4 = LD32(r4);
    r0 = GCALL2(0x06033A1C, r4, 1);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601263C(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    r0 = GCALL4(0x06036E1C, 0, 0, 0, r7);
    r0 = GCALL1(0x060125E8, r8);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060126E4(int r4)
{
    int r0, r5, r10;

    r10 = r4;
    r0 = GCALL1(0x06032164, 4);
    ST32(0x060766C0, -6);
    r0 = GCALL2(0x0603CCE0, 0x060767CC, 0x060126D4);
    r5 = LD32(0x060767CC);
    r4 = LD32(r10 + 12);
    r0 = GCALL2(0x0603CCE0, r4, r5);
    return -6;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060127B4(int r4)
{
    int r0, r1, r5, r10;

    r10 = r4;
    r0 = GCALL1(0x06032164, 4);
    ST32(0x060766C0, -21);
    r1 = LD32(r10);
    r1 = LD32(0x10E4 + r1);
    ST32(r1 + 4, 0);
    r1 = LD32(r10);
    r1 = LD32(0x10E4 + r1);
    ST32(r1 + 8, 0);
    r0 = GCALL2(0x0603CCE0, 0x060767CC, 0x06079CD0);
    r5 = LD32(0x060767CC);
    r4 = LD32(r10 + 12);
    r0 = GCALL2(0x0603CCE0, r4, r5);
    return -21;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060128F8(void)
{
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012914(int r4, int r5, int r6, int r7)
{
    int r0, r8, r11;

    r11 = r4;
    r8 = 0x06089A34;
    r4 = LD32(0x06089A34);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
        ST32(r8, 0);
    }
    ST32(0x060766C0, -6);
    r0 = GCALL2(0x0603CCE0, 0x060767CC, 0x060128FC);
    r5 = LD32(0x060767CC);
    r4 = LD32(r11 + 12);
    r0 = GCALL2(0x0603CCE0, r4, r5);
    return -6;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012AC0(int r4)
{
    int r0, r5;

    r5 = LD32(0x060767CC);
    r4 = LD32(r4 + 12);
    r0 = GCALL2(0x0603CCE0, r4, r5);
    return -6;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012AF0(int r4)
{
    int r0, r5, r10;

    r10 = r4;
    r0 = GCALL1(0x06032164, 7);
    ST32(0x060766C0, -6);
    r0 = GCALL2(0x0603CCE0, 0x060767CC, 0x06012ADC);
    r5 = LD32(0x060767CC);
    r4 = LD32(r10 + 12);
    r0 = GCALL2(0x0603CCE0, r4, r5);
    return -6;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012BF4(int r4)
{
    int r0, r1, r5, r8, c0;

    r8 = r4;
    r0 = GCALL1(0x06032164, 4);
    r1 = LD32(0x060759B4);
    ST32(0x06089A24, r1);
    r5 = LD32(r8 + 8);
    r4 = LD32(r8 + 12);
    r0 = GCALL4(0x06048D3C, r4, (r5 + 100), (r5 + 104), 0x06089A24);
    c0 = (r0 & r0) == 0;
    r0 = -2;
    if (c0) {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012C34(int r4)
{
    int r0, r1, r5, r9;

    r9 = r4;
    r0 = GCALL1(0x06032164, 4);
    r4 = LD32(0x060759B4);
    ST32(0x06089A24, r4);
    r0 = GCALL1(0x0604922C, r4);
    r5 = LD32(r9 + 8);
    r4 = LD32(r9 + 12);
    r0 = GCALL4(0x06048DE0, r4, (r5 + 100), (r5 + 104), 0x06089A24);
    r1 = 0;
    if ((r0 & r0) == 0) {
        ST32(0x060766C0, r1);
    }
    return -1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012C8C(int r4)
{
    int r0, r1, r2, r5, r6, r7, r8, r9, r10, r11, r12;
    FRAME(sp, 88);

    r11 = r4;
    r8 = 0x06089B10;
    r9 = 0x060750DC;
    r5 = LD32(0x06089B10);
    r0 = GCALL2(0x060750DC, (sp - 88), r5);
    r5 = 0x06089B1C;
    r1 = LD8(0x06089B1C);
    r10 = 0;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        r0 = GCALL2(r9, (sp - 88), r5);
        r10 = 1;
    }
    r9 = 0x060767CC;
    r2 = LD32(0x060767CC);
    r12 = 0;
    ST8(r2 + 0x1E0, 0);
    r7 = LD32(0x060767CC);
    r1 = LD8(sp - 88);
    r5 = 0;
    r6 = LD32(r8);
    if (!((r1 & r1) == 0)) {
        r5 = sp - 88;
    }
    r8 = r8 - 16;
    r4 = LD32(r8);
    r0 = GCALL4(0x0604A7CC, r4, r5, r6, r7);
    r7 = LD32(r9);
    r5 = LD32(r11 + 16);
    ST32((sp - 92), r10);
    r0 = GCALL5(0x0604A9E4, r8, r5, 0x06089C9C, r7, LD32((sp - 92)));
    r2 = 0x0608AB68;
    r1 = LD32(0x0608AB68);
    if (!((r1 & r1) == 0)) {
        r1 = LD32(r1 + 20);
        ST8(r1, r12);
        r1 = LD32(r2);
        ST16((r1 + 24), 0);
        ST16((r1 + 26), 0);
    }
    ST32(0x060766C0, -4);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012D40(void)
{
    int r0, r1, r2, r8, r9;

    r0 = GCALL0(0x060236F4);
    r2 = 0x0607599C;
    r1 = LD32(0x0607599C);
    if (!((r1 & r1) == 0)) {
        r8 = r2;
        r9 = 0x0605299C;
        do {
            r0 = GCALL0(r9);
            r1 = LD32(r8);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    r1 = LD32(0x0607669C);
    ST32(0x060759A0, r1);
    r1 = LD32(0x060766A4);
    ST32(0x060759A4, r1);
    r1 = LD32(0x060766A0);
    ST32(0x0607599C, r1);
    r1 = LD32(0x0607599C);
    r8 = 0x0607599C;
    if (!((r1 & r1) == 0)) {
        r9 = 0x0605299C;
        do {
            r0 = GCALL0(r9);
            r1 = LD32(r8);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06013C60(int r4, int r5)
{
    int r0, r1;

    r0 = LD32(152 + r4);
    ST32(r0, r5);
    ST32(r0 + 4, 0);
    r1 = LD32(0x06089CB8);
    ST32(r0 + 8, r1);
    ST32(r0 + 12, 0);
    ST32(r0 + 16, 0);
    ST32(r0 + 20, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06013F18(void)
{
    int r0, r1;

    r1 = LD32(0x06089CB0);
    ST32(0x06089CB0, (r1 + 1));
    r0 = GCALL0(0x06062348);
    r0 = GCALL0(0x06024730);
    r0 = GCALL0(0x06051B6C);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06013F4C(void)
{
    int r1;

    r1 = LD32(0x06089CB4);
    ST32(0x06089CB4, (r1 + 1));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06013F5C(void)
{
    ST32(0x060759A8, 0);
    ST32(0x060759AC, 1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601413C(void)
{
    int r1, r2;

    r2 = LD32(0x06089CB8);
    ST32(0x06089CB8, (r2 + 1));
    r1 = LD32(0x06089CB8);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060146A4(int r4, int r5, int r6, int r7)
{
    int r1, r2, r3, r8, r9, c4;
    FRAME(sp, 8);

    r1 = LD32(sp);
    r3 = LD32(r4 + 40);
    r8 = LD32(r4 + 44);
    r9 = r1 & 255;
    if (r5 >= 0) {
        if (!(r5 >= r8)) {
            r1 = LD32(r4 + 16);
            r6 = r6 + r1;
            r7 = r7 + r1;
            r1 = LD32(r4 + 28);
            if (r7 >= r1) {
                r1 = LD32(r4 + 24);
                if (!(r6 >= r1)) {
                    r1 = LD32(0x10C8 + r4);
                    c4 = (r1 & r1) == 0;
                    r1 = 2;
                    if (c4) {
                        r3 = r3 + ((r6 * r8) + r5);
                        if (!(r6 > r7)) {
                            while (1) {
                                r1 = LD32(r4 + 24);
                                if (r6 >= r1) {
                                    break;
                                } else {
                                    r1 = LD32(r4 + 28);
                                    if (r6 >= r1) {
                                        ST8(r3, r9);
                                    }
                                    r6 = r6 + 1;
                                    r3 = r3 + r8;
                                    if (!(r6 > r7)) {
                                        POLL();
                                        continue;
                                    } else {
                                        break;
                                    }
                                }
                                POLL();
                            }
                        }
                    } else {
                        r2 = LD32(0x10CC + r4);
                        if (r2 > r1) {
                            r3 = r3 + ((r6 * r8) + r5);
                            if (!(r6 > r7)) {
                                while (1) {
                                    r1 = LD32(r4 + 24);
                                    if (r6 >= r1) {
                                        break;
                                    } else {
                                        r1 = LD32(r4 + 28);
                                        if (r6 >= r1) {
                                            ST8(r3, r9);
                                        }
                                        r6 = r6 + 1;
                                        r3 = r3 + r8;
                                        if (!(r6 > r7)) {
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
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06014E60(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x06014708, r4, r5, r6, (r7 & 255));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06014E74(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c7;
    FRAME(sp, 48);

    r13 = r4;
    ST32(sp - 40, r5);
    r14 = r6;
    r1 = LD32(sp);
    ST32(sp - 36, ((signed char)r1));
    r1 = LD32(136 + r13);
    r8 = r7;
    if ((r1 & r1) == 0) {
        r1 = r14;
        r7 = LD32(r13 + 16);
        r2 = LD32(r13 + 28);
        r0 = 1;
        if (((r1 + r8) + r7) >= r2) {
            r2 = LD32(r13 + 24);
            if (!(((r14 - r8) + r7) > r2)) {
                r1 = LD32(0x10C8 + r13);
                c7 = (r1 & r1) == 0;
                r1 = 2;
                if (c7) {
                    r10 = 0;
                    r9 = (-r8) + 1;
                    r12 = 3;
                    r11 = (-(r8 + r8)) + 5;
                    r3 = LD8((7 + (sp - 40)));
                    ST32((sp - 44), (r3 & 255));
                    ST32((sp - 48), r8);
                    r5 = LD32(sp - 40);
                    r0 = GCALL8(0x060147F0, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                    if (r8 > 0) {
                        do {
                            if (r9 >= 0) {
                                r9 = r9 + r11;
                                r12 = r12 + 2;
                                r11 = r11 + 4;
                                r10 = r10 + 1;
                                r8 = r8 - 1;
                            } else {
                                r9 = r9 + r12;
                                r12 = r12 + 2;
                                r11 = r11 + 2;
                                r10 = r10 + 1;
                            }
                            r3 = LD8((7 + (sp - 40)));
                            ST32((sp - 44), (r3 & 255));
                            ST32((sp - 48), r8);
                            r5 = LD32(sp - 40);
                            r0 = GCALL8(0x060147F0, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        } while (AGAIN(r8 > r10));
                    }
                    r0 = 1;
                } else {
                    r2 = LD32(0x10CC + r13);
                    r0 = 1;
                    if (r2 > r1) {
                        r10 = 0;
                        r9 = (-r8) + 1;
                        r12 = 3;
                        r11 = (-(r8 + r8)) + 5;
                        r3 = LD8((7 + (sp - 40)));
                        ST32((sp - 44), (r3 & 255));
                        ST32((sp - 48), r8);
                        r5 = LD32(sp - 40);
                        r0 = GCALL8(0x060147F0, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        if (r8 > 0) {
                            do {
                                if (r9 >= 0) {
                                    r9 = r9 + r11;
                                    r12 = r12 + 2;
                                    r11 = r11 + 4;
                                    r10 = r10 + 1;
                                    r8 = r8 - 1;
                                } else {
                                    r9 = r9 + r12;
                                    r12 = r12 + 2;
                                    r11 = r11 + 2;
                                    r10 = r10 + 1;
                                }
                                r3 = LD8((7 + (sp - 40)));
                                ST32((sp - 44), (r3 & 255));
                                ST32((sp - 48), r8);
                                r5 = LD32(sp - 40);
                                r0 = GCALL8(0x060147F0, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            } while (AGAIN(r8 > r10));
                        }
                        r0 = 1;
                    }
                }
            }
        }
    } else {
        r1 = LD32(0x10C8 + r13);
        if ((r1 & r1) == 0) {
            r0 = GCALL6(0x06015D00, r13, 36, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
            r5 = 4;
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r0 = GCALL6(0x06013C60, r13, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                r7 = r0;
                r3 = LD16((2 + (sp - 40)));
                r2 = 148;
                ST16((r7 + 24), r3);
                ST32(r7 + 28, r14);
                ST16((r7 + 26), r8);
                ST32(r7 + 12, (r14 - r8));
                ST32(r7 + 16, (r14 + r8));
                r0 = LD16((6 + (sp - 40)));
                ST16((r7 + 32), r0);
                r1 = LD32(r13 + 148);
                if (!((r1 & r1) == 0)) {
                    ST32(r1, r7);
                }
                r0 = r13;
                ST32(r0 + r2, (r7 + 4));
                r1 = LD32(r0 + 152);
                ST32(r0 + 152, (r1 + 36));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                r1 = r14;
                r7 = LD32(r13 + 16);
                r2 = LD32(r13 + 28);
                r0 = 1;
                if (((r1 + r8) + r7) >= r2) {
                    r2 = LD32(r13 + 24);
                    if (!(((r14 - r8) + r7) > r2)) {
                        r1 = LD32(0x10C8 + r13);
                        c7 = (r1 & r1) == 0;
                        r1 = 2;
                        if (c7) {
                            r10 = 0;
                            r9 = (-r8) + 1;
                            r12 = 3;
                            r11 = (-(r8 + r8)) + 5;
                            r3 = LD8((7 + (sp - 40)));
                            ST32((sp - 44), (r3 & 255));
                            ST32((sp - 48), r8);
                            r5 = LD32(sp - 40);
                            r0 = GCALL8(0x060147F0, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            if (r8 > 0) {
                                do {
                                    if (r9 >= 0) {
                                        r9 = r9 + r11;
                                        r12 = r12 + 2;
                                        r11 = r11 + 4;
                                        r10 = r10 + 1;
                                        r8 = r8 - 1;
                                    } else {
                                        r9 = r9 + r12;
                                        r12 = r12 + 2;
                                        r11 = r11 + 2;
                                        r10 = r10 + 1;
                                    }
                                    r3 = LD8((7 + (sp - 40)));
                                    ST32((sp - 44), (r3 & 255));
                                    ST32((sp - 48), r8);
                                    r5 = LD32(sp - 40);
                                    r0 = GCALL8(0x060147F0, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                } while (AGAIN(r8 > r10));
                            }
                            r0 = 1;
                        } else {
                            r2 = LD32(0x10CC + r13);
                            r0 = 1;
                            if (r2 > r1) {
                                r10 = 0;
                                r9 = (-r8) + 1;
                                r12 = 3;
                                r11 = (-(r8 + r8)) + 5;
                                r3 = LD8((7 + (sp - 40)));
                                ST32((sp - 44), (r3 & 255));
                                ST32((sp - 48), r8);
                                r5 = LD32(sp - 40);
                                r0 = GCALL8(0x060147F0, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                if (r8 > 0) {
                                    do {
                                        if (r9 >= 0) {
                                            r9 = r9 + r11;
                                            r12 = r12 + 2;
                                            r11 = r11 + 4;
                                            r10 = r10 + 1;
                                            r8 = r8 - 1;
                                        } else {
                                            r9 = r9 + r12;
                                            r12 = r12 + 2;
                                            r11 = r11 + 2;
                                            r10 = r10 + 1;
                                        }
                                        r3 = LD8((7 + (sp - 40)));
                                        ST32((sp - 44), (r3 & 255));
                                        ST32((sp - 48), r8);
                                        r5 = LD32(sp - 40);
                                        r0 = GCALL8(0x060147F0, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                    } while (AGAIN(r8 > r10));
                                }
                                r0 = 1;
                            }
                        }
                    }
                }
            }
        } else {
            r0 = LD32(0x10CC + r13);
            r1 = r14;
            if (!(r0 == 3)) {
                r7 = LD32(r13 + 16);
                r2 = LD32(r13 + 28);
                r0 = 1;
                if (((r1 + r8) + r7) >= r2) {
                    r2 = LD32(r13 + 24);
                    if (!(((r14 - r8) + r7) > r2)) {
                        r1 = LD32(0x10C8 + r13);
                        c7 = (r1 & r1) == 0;
                        r1 = 2;
                        if (c7) {
                            r10 = 0;
                            r9 = (-r8) + 1;
                            r12 = 3;
                            r11 = (-(r8 + r8)) + 5;
                            r3 = LD8((7 + (sp - 40)));
                            ST32((sp - 44), (r3 & 255));
                            ST32((sp - 48), r8);
                            r5 = LD32(sp - 40);
                            r0 = GCALL8(0x060147F0, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            if (r8 > 0) {
                                do {
                                    if (r9 >= 0) {
                                        r9 = r9 + r11;
                                        r12 = r12 + 2;
                                        r11 = r11 + 4;
                                        r10 = r10 + 1;
                                        r8 = r8 - 1;
                                    } else {
                                        r9 = r9 + r12;
                                        r12 = r12 + 2;
                                        r11 = r11 + 2;
                                        r10 = r10 + 1;
                                    }
                                    r3 = LD8((7 + (sp - 40)));
                                    ST32((sp - 44), (r3 & 255));
                                    ST32((sp - 48), r8);
                                    r5 = LD32(sp - 40);
                                    r0 = GCALL8(0x060147F0, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                } while (AGAIN(r8 > r10));
                            }
                            r0 = 1;
                        } else {
                            r2 = LD32(0x10CC + r13);
                            r0 = 1;
                            if (r2 > r1) {
                                r10 = 0;
                                r9 = (-r8) + 1;
                                r12 = 3;
                                r11 = (-(r8 + r8)) + 5;
                                r3 = LD8((7 + (sp - 40)));
                                ST32((sp - 44), (r3 & 255));
                                ST32((sp - 48), r8);
                                r5 = LD32(sp - 40);
                                r0 = GCALL8(0x060147F0, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                if (r8 > 0) {
                                    do {
                                        if (r9 >= 0) {
                                            r9 = r9 + r11;
                                            r12 = r12 + 2;
                                            r11 = r11 + 4;
                                            r10 = r10 + 1;
                                            r8 = r8 - 1;
                                        } else {
                                            r9 = r9 + r12;
                                            r12 = r12 + 2;
                                            r11 = r11 + 2;
                                            r10 = r10 + 1;
                                        }
                                        r3 = LD8((7 + (sp - 40)));
                                        ST32((sp - 44), (r3 & 255));
                                        ST32((sp - 48), r8);
                                        r5 = LD32(sp - 40);
                                        r0 = GCALL8(0x060147F0, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                    } while (AGAIN(r8 > r10));
                                }
                                r0 = 1;
                            }
                        }
                    }
                }
            } else {
                r0 = GCALL6(0x06015D00, r13, 36, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                r5 = 4;
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r0 = GCALL6(0x06013C60, r13, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                    r7 = r0;
                    r3 = LD16((2 + (sp - 40)));
                    r2 = 148;
                    ST16((r7 + 24), r3);
                    ST32(r7 + 28, r14);
                    ST16((r7 + 26), r8);
                    ST32(r7 + 12, (r14 - r8));
                    ST32(r7 + 16, (r14 + r8));
                    r0 = LD16((6 + (sp - 40)));
                    ST16((r7 + 32), r0);
                    r1 = LD32(r13 + 148);
                    if (!((r1 & r1) == 0)) {
                        ST32(r1, r7);
                    }
                    r0 = r13;
                    ST32(r0 + r2, (r7 + 4));
                    r1 = LD32(r0 + 152);
                    ST32(r0 + 152, (r1 + 36));
                    r1 = LD32(r0 + 164);
                    ST32(r0 + 164, (r1 + 1));
                    r1 = r14;
                    r7 = LD32(r13 + 16);
                    r2 = LD32(r13 + 28);
                    r0 = 1;
                    if (((r1 + r8) + r7) >= r2) {
                        r2 = LD32(r13 + 24);
                        if (!(((r14 - r8) + r7) > r2)) {
                            r1 = LD32(0x10C8 + r13);
                            c7 = (r1 & r1) == 0;
                            r1 = 2;
                            if (c7) {
                                r10 = 0;
                                r9 = (-r8) + 1;
                                r12 = 3;
                                r11 = (-(r8 + r8)) + 5;
                                r3 = LD8((7 + (sp - 40)));
                                ST32((sp - 44), (r3 & 255));
                                ST32((sp - 48), r8);
                                r5 = LD32(sp - 40);
                                r0 = GCALL8(0x060147F0, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                if (r8 > 0) {
                                    do {
                                        if (r9 >= 0) {
                                            r9 = r9 + r11;
                                            r12 = r12 + 2;
                                            r11 = r11 + 4;
                                            r10 = r10 + 1;
                                            r8 = r8 - 1;
                                        } else {
                                            r9 = r9 + r12;
                                            r12 = r12 + 2;
                                            r11 = r11 + 2;
                                            r10 = r10 + 1;
                                        }
                                        r3 = LD8((7 + (sp - 40)));
                                        ST32((sp - 44), (r3 & 255));
                                        ST32((sp - 48), r8);
                                        r5 = LD32(sp - 40);
                                        r0 = GCALL8(0x060147F0, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                    } while (AGAIN(r8 > r10));
                                }
                                r0 = 1;
                            } else {
                                r2 = LD32(0x10CC + r13);
                                r0 = 1;
                                if (r2 > r1) {
                                    r10 = 0;
                                    r9 = (-r8) + 1;
                                    r12 = 3;
                                    r11 = (-(r8 + r8)) + 5;
                                    r3 = LD8((7 + (sp - 40)));
                                    ST32((sp - 44), (r3 & 255));
                                    ST32((sp - 48), r8);
                                    r5 = LD32(sp - 40);
                                    r0 = GCALL8(0x060147F0, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                    if (r8 > 0) {
                                        do {
                                            if (r9 >= 0) {
                                                r9 = r9 + r11;
                                                r12 = r12 + 2;
                                                r11 = r11 + 4;
                                                r10 = r10 + 1;
                                                r8 = r8 - 1;
                                            } else {
                                                r9 = r9 + r12;
                                                r12 = r12 + 2;
                                                r11 = r11 + 2;
                                                r10 = r10 + 1;
                                            }
                                            r3 = LD8((7 + (sp - 40)));
                                            ST32((sp - 44), (r3 & 255));
                                            ST32((sp - 48), r8);
                                            r5 = LD32(sp - 40);
                                            r0 = GCALL8(0x060147F0, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                        } while (AGAIN(r8 > r10));
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
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06014FE4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c7;
    FRAME(sp, 48);

    r13 = r4;
    ST32(sp - 40, r5);
    r14 = r6;
    r1 = LD32(sp);
    ST32(sp - 36, ((signed char)r1));
    r1 = LD32(136 + r13);
    r8 = r7;
    if ((r1 & r1) == 0) {
        r1 = r14;
        r7 = LD32(r13 + 16);
        r2 = LD32(r13 + 28);
        r0 = 1;
        if (((r1 + r8) + r7) >= r2) {
            r2 = LD32(r13 + 24);
            if (!(((r14 - r8) + r7) > r2)) {
                r1 = LD32(0x10C8 + r13);
                c7 = (r1 & r1) == 0;
                r1 = 2;
                if (c7) {
                    r10 = 0;
                    r9 = (-r8) + 1;
                    r12 = 3;
                    r11 = (-(r8 + r8)) + 5;
                    r3 = LD8((7 + (sp - 40)));
                    ST32((sp - 44), (r3 & 255));
                    ST32((sp - 48), r8);
                    r5 = LD32(sp - 40);
                    r0 = GCALL8(0x0601474C, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                    if (r8 > 0) {
                        do {
                            if (r9 >= 0) {
                                r9 = r9 + r11;
                                r12 = r12 + 2;
                                r11 = r11 + 4;
                                r10 = r10 + 1;
                                r8 = r8 - 1;
                            } else {
                                r9 = r9 + r12;
                                r12 = r12 + 2;
                                r11 = r11 + 2;
                                r10 = r10 + 1;
                            }
                            r3 = LD8((7 + (sp - 40)));
                            ST32((sp - 44), (r3 & 255));
                            ST32((sp - 48), r8);
                            r5 = LD32(sp - 40);
                            r0 = GCALL8(0x0601474C, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        } while (AGAIN(r8 > r10));
                    }
                    r0 = 1;
                } else {
                    r2 = LD32(0x10CC + r13);
                    r0 = 1;
                    if (r2 > r1) {
                        r10 = 0;
                        r9 = (-r8) + 1;
                        r12 = 3;
                        r11 = (-(r8 + r8)) + 5;
                        r3 = LD8((7 + (sp - 40)));
                        ST32((sp - 44), (r3 & 255));
                        ST32((sp - 48), r8);
                        r5 = LD32(sp - 40);
                        r0 = GCALL8(0x0601474C, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        if (r8 > 0) {
                            do {
                                if (r9 >= 0) {
                                    r9 = r9 + r11;
                                    r12 = r12 + 2;
                                    r11 = r11 + 4;
                                    r10 = r10 + 1;
                                    r8 = r8 - 1;
                                } else {
                                    r9 = r9 + r12;
                                    r12 = r12 + 2;
                                    r11 = r11 + 2;
                                    r10 = r10 + 1;
                                }
                                r3 = LD8((7 + (sp - 40)));
                                ST32((sp - 44), (r3 & 255));
                                ST32((sp - 48), r8);
                                r5 = LD32(sp - 40);
                                r0 = GCALL8(0x0601474C, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            } while (AGAIN(r8 > r10));
                        }
                        r0 = 1;
                    }
                }
            }
        }
    } else {
        r1 = LD32(0x10C8 + r13);
        if ((r1 & r1) == 0) {
            r0 = GCALL6(0x06015D00, r13, 36, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
            r5 = 3;
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r0 = GCALL6(0x06013C60, r13, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                r7 = r0;
                r3 = LD16((2 + (sp - 40)));
                r2 = 148;
                ST16((r7 + 24), r3);
                ST32(r7 + 28, r14);
                ST16((r7 + 26), r8);
                ST32(r7 + 12, (r14 - r8));
                ST32(r7 + 16, (r14 + r8));
                r0 = LD16((6 + (sp - 40)));
                ST16((r7 + 32), r0);
                r1 = LD32(r13 + 148);
                if (!((r1 & r1) == 0)) {
                    ST32(r1, r7);
                }
                r0 = r13;
                ST32(r0 + r2, (r7 + 4));
                r1 = LD32(r0 + 152);
                ST32(r0 + 152, (r1 + 36));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                r1 = r14;
                r7 = LD32(r13 + 16);
                r2 = LD32(r13 + 28);
                r0 = 1;
                if (((r1 + r8) + r7) >= r2) {
                    r2 = LD32(r13 + 24);
                    if (!(((r14 - r8) + r7) > r2)) {
                        r1 = LD32(0x10C8 + r13);
                        c7 = (r1 & r1) == 0;
                        r1 = 2;
                        if (c7) {
                            r10 = 0;
                            r9 = (-r8) + 1;
                            r12 = 3;
                            r11 = (-(r8 + r8)) + 5;
                            r3 = LD8((7 + (sp - 40)));
                            ST32((sp - 44), (r3 & 255));
                            ST32((sp - 48), r8);
                            r5 = LD32(sp - 40);
                            r0 = GCALL8(0x0601474C, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            if (r8 > 0) {
                                do {
                                    if (r9 >= 0) {
                                        r9 = r9 + r11;
                                        r12 = r12 + 2;
                                        r11 = r11 + 4;
                                        r10 = r10 + 1;
                                        r8 = r8 - 1;
                                    } else {
                                        r9 = r9 + r12;
                                        r12 = r12 + 2;
                                        r11 = r11 + 2;
                                        r10 = r10 + 1;
                                    }
                                    r3 = LD8((7 + (sp - 40)));
                                    ST32((sp - 44), (r3 & 255));
                                    ST32((sp - 48), r8);
                                    r5 = LD32(sp - 40);
                                    r0 = GCALL8(0x0601474C, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                } while (AGAIN(r8 > r10));
                            }
                            r0 = 1;
                        } else {
                            r2 = LD32(0x10CC + r13);
                            r0 = 1;
                            if (r2 > r1) {
                                r10 = 0;
                                r9 = (-r8) + 1;
                                r12 = 3;
                                r11 = (-(r8 + r8)) + 5;
                                r3 = LD8((7 + (sp - 40)));
                                ST32((sp - 44), (r3 & 255));
                                ST32((sp - 48), r8);
                                r5 = LD32(sp - 40);
                                r0 = GCALL8(0x0601474C, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                if (r8 > 0) {
                                    do {
                                        if (r9 >= 0) {
                                            r9 = r9 + r11;
                                            r12 = r12 + 2;
                                            r11 = r11 + 4;
                                            r10 = r10 + 1;
                                            r8 = r8 - 1;
                                        } else {
                                            r9 = r9 + r12;
                                            r12 = r12 + 2;
                                            r11 = r11 + 2;
                                            r10 = r10 + 1;
                                        }
                                        r3 = LD8((7 + (sp - 40)));
                                        ST32((sp - 44), (r3 & 255));
                                        ST32((sp - 48), r8);
                                        r5 = LD32(sp - 40);
                                        r0 = GCALL8(0x0601474C, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                    } while (AGAIN(r8 > r10));
                                }
                                r0 = 1;
                            }
                        }
                    }
                }
            }
        } else {
            r0 = LD32(0x10CC + r13);
            r1 = r14;
            if (!(r0 == 3)) {
                r7 = LD32(r13 + 16);
                r2 = LD32(r13 + 28);
                r0 = 1;
                if (((r1 + r8) + r7) >= r2) {
                    r2 = LD32(r13 + 24);
                    if (!(((r14 - r8) + r7) > r2)) {
                        r1 = LD32(0x10C8 + r13);
                        c7 = (r1 & r1) == 0;
                        r1 = 2;
                        if (c7) {
                            r10 = 0;
                            r9 = (-r8) + 1;
                            r12 = 3;
                            r11 = (-(r8 + r8)) + 5;
                            r3 = LD8((7 + (sp - 40)));
                            ST32((sp - 44), (r3 & 255));
                            ST32((sp - 48), r8);
                            r5 = LD32(sp - 40);
                            r0 = GCALL8(0x0601474C, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            if (r8 > 0) {
                                do {
                                    if (r9 >= 0) {
                                        r9 = r9 + r11;
                                        r12 = r12 + 2;
                                        r11 = r11 + 4;
                                        r10 = r10 + 1;
                                        r8 = r8 - 1;
                                    } else {
                                        r9 = r9 + r12;
                                        r12 = r12 + 2;
                                        r11 = r11 + 2;
                                        r10 = r10 + 1;
                                    }
                                    r3 = LD8((7 + (sp - 40)));
                                    ST32((sp - 44), (r3 & 255));
                                    ST32((sp - 48), r8);
                                    r5 = LD32(sp - 40);
                                    r0 = GCALL8(0x0601474C, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                } while (AGAIN(r8 > r10));
                            }
                            r0 = 1;
                        } else {
                            r2 = LD32(0x10CC + r13);
                            r0 = 1;
                            if (r2 > r1) {
                                r10 = 0;
                                r9 = (-r8) + 1;
                                r12 = 3;
                                r11 = (-(r8 + r8)) + 5;
                                r3 = LD8((7 + (sp - 40)));
                                ST32((sp - 44), (r3 & 255));
                                ST32((sp - 48), r8);
                                r5 = LD32(sp - 40);
                                r0 = GCALL8(0x0601474C, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                if (r8 > 0) {
                                    do {
                                        if (r9 >= 0) {
                                            r9 = r9 + r11;
                                            r12 = r12 + 2;
                                            r11 = r11 + 4;
                                            r10 = r10 + 1;
                                            r8 = r8 - 1;
                                        } else {
                                            r9 = r9 + r12;
                                            r12 = r12 + 2;
                                            r11 = r11 + 2;
                                            r10 = r10 + 1;
                                        }
                                        r3 = LD8((7 + (sp - 40)));
                                        ST32((sp - 44), (r3 & 255));
                                        ST32((sp - 48), r8);
                                        r5 = LD32(sp - 40);
                                        r0 = GCALL8(0x0601474C, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                    } while (AGAIN(r8 > r10));
                                }
                                r0 = 1;
                            }
                        }
                    }
                }
            } else {
                r0 = GCALL6(0x06015D00, r13, 36, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                r5 = 3;
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r0 = GCALL6(0x06013C60, r13, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                    r7 = r0;
                    r3 = LD16((2 + (sp - 40)));
                    r2 = 148;
                    ST16((r7 + 24), r3);
                    ST32(r7 + 28, r14);
                    ST16((r7 + 26), r8);
                    ST32(r7 + 12, (r14 - r8));
                    ST32(r7 + 16, (r14 + r8));
                    r0 = LD16((6 + (sp - 40)));
                    ST16((r7 + 32), r0);
                    r1 = LD32(r13 + 148);
                    if (!((r1 & r1) == 0)) {
                        ST32(r1, r7);
                    }
                    r0 = r13;
                    ST32(r0 + r2, (r7 + 4));
                    r1 = LD32(r0 + 152);
                    ST32(r0 + 152, (r1 + 36));
                    r1 = LD32(r0 + 164);
                    ST32(r0 + 164, (r1 + 1));
                    r1 = r14;
                    r7 = LD32(r13 + 16);
                    r2 = LD32(r13 + 28);
                    r0 = 1;
                    if (((r1 + r8) + r7) >= r2) {
                        r2 = LD32(r13 + 24);
                        if (!(((r14 - r8) + r7) > r2)) {
                            r1 = LD32(0x10C8 + r13);
                            c7 = (r1 & r1) == 0;
                            r1 = 2;
                            if (c7) {
                                r10 = 0;
                                r9 = (-r8) + 1;
                                r12 = 3;
                                r11 = (-(r8 + r8)) + 5;
                                r3 = LD8((7 + (sp - 40)));
                                ST32((sp - 44), (r3 & 255));
                                ST32((sp - 48), r8);
                                r5 = LD32(sp - 40);
                                r0 = GCALL8(0x0601474C, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                if (r8 > 0) {
                                    do {
                                        if (r9 >= 0) {
                                            r9 = r9 + r11;
                                            r12 = r12 + 2;
                                            r11 = r11 + 4;
                                            r10 = r10 + 1;
                                            r8 = r8 - 1;
                                        } else {
                                            r9 = r9 + r12;
                                            r12 = r12 + 2;
                                            r11 = r11 + 2;
                                            r10 = r10 + 1;
                                        }
                                        r3 = LD8((7 + (sp - 40)));
                                        ST32((sp - 44), (r3 & 255));
                                        ST32((sp - 48), r8);
                                        r5 = LD32(sp - 40);
                                        r0 = GCALL8(0x0601474C, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                    } while (AGAIN(r8 > r10));
                                }
                                r0 = 1;
                            } else {
                                r2 = LD32(0x10CC + r13);
                                r0 = 1;
                                if (r2 > r1) {
                                    r10 = 0;
                                    r9 = (-r8) + 1;
                                    r12 = 3;
                                    r11 = (-(r8 + r8)) + 5;
                                    r3 = LD8((7 + (sp - 40)));
                                    ST32((sp - 44), (r3 & 255));
                                    ST32((sp - 48), r8);
                                    r5 = LD32(sp - 40);
                                    r0 = GCALL8(0x0601474C, r13, r5, r14, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                    if (r8 > 0) {
                                        do {
                                            if (r9 >= 0) {
                                                r9 = r9 + r11;
                                                r12 = r12 + 2;
                                                r11 = r11 + 4;
                                                r10 = r10 + 1;
                                                r8 = r8 - 1;
                                            } else {
                                                r9 = r9 + r12;
                                                r12 = r12 + 2;
                                                r11 = r11 + 2;
                                                r10 = r10 + 1;
                                            }
                                            r3 = LD8((7 + (sp - 40)));
                                            ST32((sp - 44), (r3 & 255));
                                            ST32((sp - 48), r8);
                                            r5 = LD32(sp - 40);
                                            r0 = GCALL8(0x0601474C, r13, r5, r14, r10, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                        } while (AGAIN(r8 > r10));
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
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060152A0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c7;
    FRAME(sp, 36);

    r10 = r4;
    r13 = r5;
    r11 = r6;
    r1 = LD32(sp + 4);
    r12 = LD32(sp);
    r8 = (signed char)r1;
    r1 = LD32(136 + r10);
    r14 = r7;
    r9 = LD32(r10 + 16);
    if ((r1 & r1) == 0) {
        r2 = r12;
        r1 = LD32(r10 + 28);
        r0 = 1;
        if ((r2 + r9) >= r1) {
            r1 = LD32(0x10C8 + r10);
            c7 = (r1 & r1) == 0;
            r1 = 2;
            if (c7) {
                r8 = r8 & 255;
                ST32((sp - 36), r8);
                r0 = GCALL5(0x06014638, r10, r13, r14, r11, LD32((sp - 36)));
                ST32((sp - 40), r8);
                r0 = GCALL6(0x06014638, r10, r13, r14, r12, LD32((sp - 40)), LD32((sp - 36)));
                ST32((sp - 44), r8);
                r0 = GCALL7(0x060146A4, r10, r13, r11, r12, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                ST32((sp - 48), r8);
                r0 = GCALL8(0x060146A4, r10, r14, r11, r12, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                r0 = 1;
            } else {
                r2 = LD32(0x10CC + r10);
                r0 = 1;
                if (r2 > r1) {
                    r8 = r8 & 255;
                    ST32((sp - 36), r8);
                    r0 = GCALL5(0x06014638, r10, r13, r14, r11, LD32((sp - 36)));
                    ST32((sp - 40), r8);
                    r0 = GCALL6(0x06014638, r10, r13, r14, r12, LD32((sp - 40)), LD32((sp - 36)));
                    ST32((sp - 44), r8);
                    r0 = GCALL7(0x060146A4, r10, r13, r11, r12, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                    ST32((sp - 48), r8);
                    r0 = GCALL8(0x060146A4, r10, r14, r11, r12, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                    r0 = 1;
                }
            }
        }
    } else {
        r1 = LD32(0x10C8 + r10);
        if ((r1 & r1) == 0) {
            r0 = GCALL2(0x06015D00, r10, 40);
            r5 = 1;
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r0 = GCALL2(0x06013C60, r10, r5);
                r3 = r0;
                ST16((r3 + 24), r13);
                ST32(r3 + 28, r11);
                ST16((r3 + 26), r14);
                ST32(r3 + 32, r12);
                if (r12 >= r11) {
                    ST32(r3 + 16, r12);
                    ST32(r3 + 12, r11);
                } else {
                    ST32(r3 + 12, r12);
                    ST32(r3 + 16, r11);
                }
                ST16((r3 + 36), r8);
                r2 = 148;
                r1 = LD32(r10 + 148);
                if (!((r1 & r1) == 0)) {
                    ST32(r1, r3);
                }
                r0 = r10;
                ST32(r0 + r2, (r3 + 4));
                r1 = LD32(r0 + 152);
                ST32(r0 + 152, (r1 + 40));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                r2 = r12;
                r1 = LD32(r10 + 28);
                r0 = 1;
                if ((r2 + r9) >= r1) {
                    r1 = LD32(0x10C8 + r10);
                    c7 = (r1 & r1) == 0;
                    r1 = 2;
                    if (c7) {
                        r8 = r8 & 255;
                        ST32((sp - 36), r8);
                        r0 = GCALL5(0x06014638, r10, r13, r14, r11, LD32((sp - 36)));
                        ST32((sp - 40), r8);
                        r0 = GCALL6(0x06014638, r10, r13, r14, r12, LD32((sp - 40)), LD32((sp - 36)));
                        ST32((sp - 44), r8);
                        r0 = GCALL7(0x060146A4, r10, r13, r11, r12, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        ST32((sp - 48), r8);
                        r0 = GCALL8(0x060146A4, r10, r14, r11, r12, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        r0 = 1;
                    } else {
                        r2 = LD32(0x10CC + r10);
                        r0 = 1;
                        if (r2 > r1) {
                            r8 = r8 & 255;
                            ST32((sp - 36), r8);
                            r0 = GCALL5(0x06014638, r10, r13, r14, r11, LD32((sp - 36)));
                            ST32((sp - 40), r8);
                            r0 = GCALL6(0x06014638, r10, r13, r14, r12, LD32((sp - 40)), LD32((sp - 36)));
                            ST32((sp - 44), r8);
                            r0 = GCALL7(0x060146A4, r10, r13, r11, r12, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            ST32((sp - 48), r8);
                            r0 = GCALL8(0x060146A4, r10, r14, r11, r12, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            r0 = 1;
                        }
                    }
                }
            }
        } else {
            r0 = LD32(0x10CC + r10);
            r2 = r12;
            if (!(r0 == 3)) {
                r1 = LD32(r10 + 28);
                r0 = 1;
                if ((r2 + r9) >= r1) {
                    r1 = LD32(0x10C8 + r10);
                    c7 = (r1 & r1) == 0;
                    r1 = 2;
                    if (c7) {
                        r8 = r8 & 255;
                        ST32((sp - 36), r8);
                        r0 = GCALL5(0x06014638, r10, r13, r14, r11, LD32((sp - 36)));
                        ST32((sp - 40), r8);
                        r0 = GCALL6(0x06014638, r10, r13, r14, r12, LD32((sp - 40)), LD32((sp - 36)));
                        ST32((sp - 44), r8);
                        r0 = GCALL7(0x060146A4, r10, r13, r11, r12, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        ST32((sp - 48), r8);
                        r0 = GCALL8(0x060146A4, r10, r14, r11, r12, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        r0 = 1;
                    } else {
                        r2 = LD32(0x10CC + r10);
                        r0 = 1;
                        if (r2 > r1) {
                            r8 = r8 & 255;
                            ST32((sp - 36), r8);
                            r0 = GCALL5(0x06014638, r10, r13, r14, r11, LD32((sp - 36)));
                            ST32((sp - 40), r8);
                            r0 = GCALL6(0x06014638, r10, r13, r14, r12, LD32((sp - 40)), LD32((sp - 36)));
                            ST32((sp - 44), r8);
                            r0 = GCALL7(0x060146A4, r10, r13, r11, r12, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            ST32((sp - 48), r8);
                            r0 = GCALL8(0x060146A4, r10, r14, r11, r12, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            r0 = 1;
                        }
                    }
                }
            } else {
                r0 = GCALL2(0x06015D00, r10, 40);
                r5 = 1;
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r0 = GCALL2(0x06013C60, r10, r5);
                    r3 = r0;
                    ST16((r3 + 24), r13);
                    ST32(r3 + 28, r11);
                    ST16((r3 + 26), r14);
                    ST32(r3 + 32, r12);
                    if (r12 >= r11) {
                        ST32(r3 + 16, r12);
                        ST32(r3 + 12, r11);
                    } else {
                        ST32(r3 + 12, r12);
                        ST32(r3 + 16, r11);
                    }
                    ST16((r3 + 36), r8);
                    r2 = 148;
                    r1 = LD32(r10 + 148);
                    if (!((r1 & r1) == 0)) {
                        ST32(r1, r3);
                    }
                    r0 = r10;
                    ST32(r0 + r2, (r3 + 4));
                    r1 = LD32(r0 + 152);
                    ST32(r0 + 152, (r1 + 40));
                    r1 = LD32(r0 + 164);
                    ST32(r0 + 164, (r1 + 1));
                    r2 = r12;
                    r1 = LD32(r10 + 28);
                    r0 = 1;
                    if ((r2 + r9) >= r1) {
                        r1 = LD32(0x10C8 + r10);
                        c7 = (r1 & r1) == 0;
                        r1 = 2;
                        if (c7) {
                            r8 = r8 & 255;
                            ST32((sp - 36), r8);
                            r0 = GCALL5(0x06014638, r10, r13, r14, r11, LD32((sp - 36)));
                            ST32((sp - 40), r8);
                            r0 = GCALL6(0x06014638, r10, r13, r14, r12, LD32((sp - 40)), LD32((sp - 36)));
                            ST32((sp - 44), r8);
                            r0 = GCALL7(0x060146A4, r10, r13, r11, r12, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            ST32((sp - 48), r8);
                            r0 = GCALL8(0x060146A4, r10, r14, r11, r12, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            r0 = 1;
                        } else {
                            r2 = LD32(0x10CC + r10);
                            r0 = 1;
                            if (r2 > r1) {
                                r8 = r8 & 255;
                                ST32((sp - 36), r8);
                                r0 = GCALL5(0x06014638, r10, r13, r14, r11, LD32((sp - 36)));
                                ST32((sp - 40), r8);
                                r0 = GCALL6(0x06014638, r10, r13, r14, r12, LD32((sp - 40)), LD32((sp - 36)));
                                ST32((sp - 44), r8);
                                r0 = GCALL7(0x060146A4, r10, r13, r11, r12, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                ST32((sp - 48), r8);
                                r0 = GCALL8(0x060146A4, r10, r14, r11, r12, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                r0 = 1;
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
int f060153C8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c7;
    FRAME(sp, 68);

    r10 = r4;
    r13 = r5;
    r8 = r6;
    r12 = r7;
    r9 = LD32(sp);
    r1 = LD32((64 + (sp - 60)));
    r2 = LD32((68 + (sp - 60)));
    ST32(sp - 60, ((signed char)r1));
    ST32(sp - 56, (r2 & 255));
    r0 = LD8(75 + (sp - 60));
    ST32(sp - 52, (r0 & 255));
    r1 = LD32(r10 + 136);
    r11 = LD32(r10 + 16);
    if ((r1 & r1) == 0) {
        r2 = r9;
        r1 = LD32(r10 + 28);
        r0 = 1;
        if ((r2 + r11) >= r1) {
            r1 = LD32(0x10C8 + r10);
            c7 = (r1 & r1) == 0;
            r1 = 2;
            if (c7) {
                r4 = LD8(r10 + 168);
                r0 = GCALL7(0x0601EFA4, (r4 & 255), 0, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                r2 = r0;
                ST32(sp - 44, 64);
                ST32(sp - 40, 224);
                if (r2 > 32) {
                    r3 = 0;
                    if (r2 > 66) {
                        ST32(sp - 40, 128);
                        r3 = 0;
                    }
                } else {
                    ST32(sp - 44, 128);
                    ST32(sp - 40, 192);
                    r3 = 0;
                }
                r0 = LD32(sp - 56);
                ST32(sp - 48, r3);
                if (!(r3 >= r0)) {
                    r14 = r9;
                    r1 = LD32(sp - 44);
                    r11 = r8;
                    r3 = LD32(sp - 44);
                    ST32(sp - 36, (r3 | ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1))));
                    do {
                        r0 = LD32(sp - 52);
                        r7 = r11;
                        if ((r0 & r0) == 0) {
                            r1 = LD32(sp - 40);
                            r3 = LD32(sp - 40);
                            r8 = LD32(sp - 60);
                            r8 = r8 & ((((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)));
                            ST32((sp - 64), r8);
                            r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r7 = r14;
                            r6 = r12;
                            r5 = r13;
                            r1 = LD32(sp - 44);
                            r4 = r10;
                            r3 = LD32(sp - 36);
                            r0 = 0x06014638;
                            r9 = LD32(sp - 60);
                            r1 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3;
                        } else {
                            r1 = LD32(sp - 44);
                            r3 = LD32(sp - 36);
                            r8 = LD32(sp - 60);
                            r8 = r8 & (((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3);
                            ST32((sp - 64), r8);
                            r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r7 = r14;
                            r6 = r12;
                            r5 = r13;
                            r1 = LD32(sp - 40);
                            r4 = r10;
                            r3 = LD32(sp - 40);
                            r0 = 0x06014638;
                            r9 = LD32(sp - 60);
                            r1 = (((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2));
                        }
                        r9 = r9 & r1;
                        ST32((sp - 68), r9);
                        r0 = GCALL8(r0, r4, r5, r6, r7, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
                        ST32((sp - 72), r8);
                        r0 = GCALL8(0x060146A4, r10, r13, r11, r14, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                        ST32((sp - 76), r9);
                        r0 = GCALL8(0x060146A4, r10, r12, r11, r14, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                        r14 = r14 - 1;
                        r13 = r13 + 1;
                        r12 = r12 - 1;
                        r3 = LD32(sp - 48);
                        r11 = r11 + 1;
                        r0 = LD32(sp - 56);
                        r3 = r3 + 1;
                        ST32(sp - 48, r3);
                    } while (AGAIN(!(r3 >= r0)));
                }
                r0 = 1;
            } else {
                r2 = LD32(0x10CC + r10);
                r0 = 1;
                if (r2 > r1) {
                    r4 = LD8(r10 + 168);
                    r0 = GCALL7(0x0601EFA4, (r4 & 255), 0, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                    r2 = r0;
                    ST32(sp - 44, 64);
                    ST32(sp - 40, 224);
                    if (r2 > 32) {
                        r3 = 0;
                        if (r2 > 66) {
                            ST32(sp - 40, 128);
                            r3 = 0;
                        }
                    } else {
                        ST32(sp - 44, 128);
                        ST32(sp - 40, 192);
                        r3 = 0;
                    }
                    r0 = LD32(sp - 56);
                    ST32(sp - 48, r3);
                    if (!(r3 >= r0)) {
                        r14 = r9;
                        r1 = LD32(sp - 44);
                        r11 = r8;
                        r3 = LD32(sp - 44);
                        ST32(sp - 36, (r3 | ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1))));
                        do {
                            r0 = LD32(sp - 52);
                            r7 = r11;
                            if ((r0 & r0) == 0) {
                                r1 = LD32(sp - 40);
                                r3 = LD32(sp - 40);
                                r8 = LD32(sp - 60);
                                r8 = r8 & ((((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)));
                                ST32((sp - 64), r8);
                                r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r7 = r14;
                                r6 = r12;
                                r5 = r13;
                                r1 = LD32(sp - 44);
                                r4 = r10;
                                r3 = LD32(sp - 36);
                                r0 = 0x06014638;
                                r9 = LD32(sp - 60);
                                r1 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3;
                            } else {
                                r1 = LD32(sp - 44);
                                r3 = LD32(sp - 36);
                                r8 = LD32(sp - 60);
                                r8 = r8 & (((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3);
                                ST32((sp - 64), r8);
                                r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r7 = r14;
                                r6 = r12;
                                r5 = r13;
                                r1 = LD32(sp - 40);
                                r4 = r10;
                                r3 = LD32(sp - 40);
                                r0 = 0x06014638;
                                r9 = LD32(sp - 60);
                                r1 = (((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2));
                            }
                            r9 = r9 & r1;
                            ST32((sp - 68), r9);
                            r0 = GCALL8(r0, r4, r5, r6, r7, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
                            ST32((sp - 72), r8);
                            r0 = GCALL8(0x060146A4, r10, r13, r11, r14, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                            ST32((sp - 76), r9);
                            r0 = GCALL8(0x060146A4, r10, r12, r11, r14, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                            r14 = r14 - 1;
                            r13 = r13 + 1;
                            r12 = r12 - 1;
                            r3 = LD32(sp - 48);
                            r11 = r11 + 1;
                            r0 = LD32(sp - 56);
                            r3 = r3 + 1;
                            ST32(sp - 48, r3);
                        } while (AGAIN(!(r3 >= r0)));
                    }
                    r0 = 1;
                }
            }
        }
    } else {
        r1 = LD32(0x10C8 + r10);
        if ((r1 & r1) == 0) {
            r0 = GCALL7(0x06015D00, r10, 40, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
            r5 = 8;
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r0 = GCALL7(0x06013C60, r10, r5, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                r7 = r0;
                ST16((r7 + 24), r13);
                ST32(r7 + 28, r8);
                ST16((r7 + 26), r12);
                ST32(r7 + 32, r9);
                r0 = LD16((2 + (sp - 60)));
                ST16((r7 + 36), r0);
                r3 = LD8((7 + (sp - 60)));
                ST8((r7 + 38), r3);
                r0 = LD8((11 + (sp - 60)));
                ST8((r7 + 39), r0);
                if (r8 >= r9) {
                    ST32(r7 + 12, r9);
                    ST32(r7 + 16, r8);
                } else {
                    ST32(r7 + 12, r8);
                    ST32(r7 + 16, r9);
                }
                r2 = 148;
                r1 = LD32(r10 + 148);
                if (!((r1 & r1) == 0)) {
                    ST32(r1, r7);
                }
                r0 = r10;
                ST32(r0 + r2, (r7 + 4));
                r1 = LD32(r0 + 152);
                ST32(r0 + 152, (r1 + 40));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                r2 = r9;
                r1 = LD32(r10 + 28);
                r0 = 1;
                if ((r2 + r11) >= r1) {
                    r1 = LD32(0x10C8 + r10);
                    c7 = (r1 & r1) == 0;
                    r1 = 2;
                    if (c7) {
                        r4 = LD8(r10 + 168);
                        r0 = GCALL7(0x0601EFA4, (r4 & 255), 0, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                        r2 = r0;
                        ST32(sp - 44, 64);
                        ST32(sp - 40, 224);
                        if (r2 > 32) {
                            r3 = 0;
                            if (r2 > 66) {
                                ST32(sp - 40, 128);
                                r3 = 0;
                            }
                        } else {
                            ST32(sp - 44, 128);
                            ST32(sp - 40, 192);
                            r3 = 0;
                        }
                        r0 = LD32(sp - 56);
                        ST32(sp - 48, r3);
                        if (!(r3 >= r0)) {
                            r14 = r9;
                            r1 = LD32(sp - 44);
                            r11 = r8;
                            r3 = LD32(sp - 44);
                            ST32(sp - 36, (r3 | ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1))));
                            do {
                                r0 = LD32(sp - 52);
                                r7 = r11;
                                if ((r0 & r0) == 0) {
                                    r1 = LD32(sp - 40);
                                    r3 = LD32(sp - 40);
                                    r8 = LD32(sp - 60);
                                    r8 = r8 & ((((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)));
                                    ST32((sp - 64), r8);
                                    r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                    r7 = r14;
                                    r6 = r12;
                                    r5 = r13;
                                    r1 = LD32(sp - 44);
                                    r4 = r10;
                                    r3 = LD32(sp - 36);
                                    r0 = 0x06014638;
                                    r9 = LD32(sp - 60);
                                    r1 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3;
                                } else {
                                    r1 = LD32(sp - 44);
                                    r3 = LD32(sp - 36);
                                    r8 = LD32(sp - 60);
                                    r8 = r8 & (((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3);
                                    ST32((sp - 64), r8);
                                    r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                    r7 = r14;
                                    r6 = r12;
                                    r5 = r13;
                                    r1 = LD32(sp - 40);
                                    r4 = r10;
                                    r3 = LD32(sp - 40);
                                    r0 = 0x06014638;
                                    r9 = LD32(sp - 60);
                                    r1 = (((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2));
                                }
                                r9 = r9 & r1;
                                ST32((sp - 68), r9);
                                r0 = GCALL8(r0, r4, r5, r6, r7, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
                                ST32((sp - 72), r8);
                                r0 = GCALL8(0x060146A4, r10, r13, r11, r14, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                                ST32((sp - 76), r9);
                                r0 = GCALL8(0x060146A4, r10, r12, r11, r14, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                                r14 = r14 - 1;
                                r13 = r13 + 1;
                                r12 = r12 - 1;
                                r3 = LD32(sp - 48);
                                r11 = r11 + 1;
                                r0 = LD32(sp - 56);
                                r3 = r3 + 1;
                                ST32(sp - 48, r3);
                            } while (AGAIN(!(r3 >= r0)));
                        }
                        r0 = 1;
                    } else {
                        r2 = LD32(0x10CC + r10);
                        r0 = 1;
                        if (r2 > r1) {
                            r4 = LD8(r10 + 168);
                            r0 = GCALL7(0x0601EFA4, (r4 & 255), 0, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r2 = r0;
                            ST32(sp - 44, 64);
                            ST32(sp - 40, 224);
                            if (r2 > 32) {
                                r3 = 0;
                                if (r2 > 66) {
                                    ST32(sp - 40, 128);
                                    r3 = 0;
                                }
                            } else {
                                ST32(sp - 44, 128);
                                ST32(sp - 40, 192);
                                r3 = 0;
                            }
                            r0 = LD32(sp - 56);
                            ST32(sp - 48, r3);
                            if (!(r3 >= r0)) {
                                r14 = r9;
                                r1 = LD32(sp - 44);
                                r11 = r8;
                                r3 = LD32(sp - 44);
                                ST32(sp - 36, (r3 | ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1))));
                                do {
                                    r0 = LD32(sp - 52);
                                    r7 = r11;
                                    if ((r0 & r0) == 0) {
                                        r1 = LD32(sp - 40);
                                        r3 = LD32(sp - 40);
                                        r8 = LD32(sp - 60);
                                        r8 = r8 & ((((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)));
                                        ST32((sp - 64), r8);
                                        r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        r7 = r14;
                                        r6 = r12;
                                        r5 = r13;
                                        r1 = LD32(sp - 44);
                                        r4 = r10;
                                        r3 = LD32(sp - 36);
                                        r0 = 0x06014638;
                                        r9 = LD32(sp - 60);
                                        r1 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3;
                                    } else {
                                        r1 = LD32(sp - 44);
                                        r3 = LD32(sp - 36);
                                        r8 = LD32(sp - 60);
                                        r8 = r8 & (((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3);
                                        ST32((sp - 64), r8);
                                        r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        r7 = r14;
                                        r6 = r12;
                                        r5 = r13;
                                        r1 = LD32(sp - 40);
                                        r4 = r10;
                                        r3 = LD32(sp - 40);
                                        r0 = 0x06014638;
                                        r9 = LD32(sp - 60);
                                        r1 = (((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2));
                                    }
                                    r9 = r9 & r1;
                                    ST32((sp - 68), r9);
                                    r0 = GCALL8(r0, r4, r5, r6, r7, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
                                    ST32((sp - 72), r8);
                                    r0 = GCALL8(0x060146A4, r10, r13, r11, r14, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                                    ST32((sp - 76), r9);
                                    r0 = GCALL8(0x060146A4, r10, r12, r11, r14, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                                    r14 = r14 - 1;
                                    r13 = r13 + 1;
                                    r12 = r12 - 1;
                                    r3 = LD32(sp - 48);
                                    r11 = r11 + 1;
                                    r0 = LD32(sp - 56);
                                    r3 = r3 + 1;
                                    ST32(sp - 48, r3);
                                } while (AGAIN(!(r3 >= r0)));
                            }
                            r0 = 1;
                        }
                    }
                }
            }
        } else {
            r0 = LD32(0x10CC + r10);
            r2 = r9;
            if (!(r0 == 3)) {
                r1 = LD32(r10 + 28);
                r0 = 1;
                if ((r2 + r11) >= r1) {
                    r1 = LD32(0x10C8 + r10);
                    c7 = (r1 & r1) == 0;
                    r1 = 2;
                    if (c7) {
                        r4 = LD8(r10 + 168);
                        r0 = GCALL7(0x0601EFA4, (r4 & 255), 0, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                        r2 = r0;
                        ST32(sp - 44, 64);
                        ST32(sp - 40, 224);
                        if (r2 > 32) {
                            r3 = 0;
                            if (r2 > 66) {
                                ST32(sp - 40, 128);
                                r3 = 0;
                            }
                        } else {
                            ST32(sp - 44, 128);
                            ST32(sp - 40, 192);
                            r3 = 0;
                        }
                        r0 = LD32(sp - 56);
                        ST32(sp - 48, r3);
                        if (!(r3 >= r0)) {
                            r14 = r9;
                            r1 = LD32(sp - 44);
                            r11 = r8;
                            r3 = LD32(sp - 44);
                            ST32(sp - 36, (r3 | ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1))));
                            do {
                                r0 = LD32(sp - 52);
                                r7 = r11;
                                if ((r0 & r0) == 0) {
                                    r1 = LD32(sp - 40);
                                    r3 = LD32(sp - 40);
                                    r8 = LD32(sp - 60);
                                    r8 = r8 & ((((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)));
                                    ST32((sp - 64), r8);
                                    r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                    r7 = r14;
                                    r6 = r12;
                                    r5 = r13;
                                    r1 = LD32(sp - 44);
                                    r4 = r10;
                                    r3 = LD32(sp - 36);
                                    r0 = 0x06014638;
                                    r9 = LD32(sp - 60);
                                    r1 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3;
                                } else {
                                    r1 = LD32(sp - 44);
                                    r3 = LD32(sp - 36);
                                    r8 = LD32(sp - 60);
                                    r8 = r8 & (((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3);
                                    ST32((sp - 64), r8);
                                    r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                    r7 = r14;
                                    r6 = r12;
                                    r5 = r13;
                                    r1 = LD32(sp - 40);
                                    r4 = r10;
                                    r3 = LD32(sp - 40);
                                    r0 = 0x06014638;
                                    r9 = LD32(sp - 60);
                                    r1 = (((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2));
                                }
                                r9 = r9 & r1;
                                ST32((sp - 68), r9);
                                r0 = GCALL8(r0, r4, r5, r6, r7, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
                                ST32((sp - 72), r8);
                                r0 = GCALL8(0x060146A4, r10, r13, r11, r14, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                                ST32((sp - 76), r9);
                                r0 = GCALL8(0x060146A4, r10, r12, r11, r14, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                                r14 = r14 - 1;
                                r13 = r13 + 1;
                                r12 = r12 - 1;
                                r3 = LD32(sp - 48);
                                r11 = r11 + 1;
                                r0 = LD32(sp - 56);
                                r3 = r3 + 1;
                                ST32(sp - 48, r3);
                            } while (AGAIN(!(r3 >= r0)));
                        }
                        r0 = 1;
                    } else {
                        r2 = LD32(0x10CC + r10);
                        r0 = 1;
                        if (r2 > r1) {
                            r4 = LD8(r10 + 168);
                            r0 = GCALL7(0x0601EFA4, (r4 & 255), 0, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r2 = r0;
                            ST32(sp - 44, 64);
                            ST32(sp - 40, 224);
                            if (r2 > 32) {
                                r3 = 0;
                                if (r2 > 66) {
                                    ST32(sp - 40, 128);
                                    r3 = 0;
                                }
                            } else {
                                ST32(sp - 44, 128);
                                ST32(sp - 40, 192);
                                r3 = 0;
                            }
                            r0 = LD32(sp - 56);
                            ST32(sp - 48, r3);
                            if (!(r3 >= r0)) {
                                r14 = r9;
                                r1 = LD32(sp - 44);
                                r11 = r8;
                                r3 = LD32(sp - 44);
                                ST32(sp - 36, (r3 | ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1))));
                                do {
                                    r0 = LD32(sp - 52);
                                    r7 = r11;
                                    if ((r0 & r0) == 0) {
                                        r1 = LD32(sp - 40);
                                        r3 = LD32(sp - 40);
                                        r8 = LD32(sp - 60);
                                        r8 = r8 & ((((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)));
                                        ST32((sp - 64), r8);
                                        r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        r7 = r14;
                                        r6 = r12;
                                        r5 = r13;
                                        r1 = LD32(sp - 44);
                                        r4 = r10;
                                        r3 = LD32(sp - 36);
                                        r0 = 0x06014638;
                                        r9 = LD32(sp - 60);
                                        r1 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3;
                                    } else {
                                        r1 = LD32(sp - 44);
                                        r3 = LD32(sp - 36);
                                        r8 = LD32(sp - 60);
                                        r8 = r8 & (((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3);
                                        ST32((sp - 64), r8);
                                        r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        r7 = r14;
                                        r6 = r12;
                                        r5 = r13;
                                        r1 = LD32(sp - 40);
                                        r4 = r10;
                                        r3 = LD32(sp - 40);
                                        r0 = 0x06014638;
                                        r9 = LD32(sp - 60);
                                        r1 = (((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2));
                                    }
                                    r9 = r9 & r1;
                                    ST32((sp - 68), r9);
                                    r0 = GCALL8(r0, r4, r5, r6, r7, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
                                    ST32((sp - 72), r8);
                                    r0 = GCALL8(0x060146A4, r10, r13, r11, r14, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                                    ST32((sp - 76), r9);
                                    r0 = GCALL8(0x060146A4, r10, r12, r11, r14, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                                    r14 = r14 - 1;
                                    r13 = r13 + 1;
                                    r12 = r12 - 1;
                                    r3 = LD32(sp - 48);
                                    r11 = r11 + 1;
                                    r0 = LD32(sp - 56);
                                    r3 = r3 + 1;
                                    ST32(sp - 48, r3);
                                } while (AGAIN(!(r3 >= r0)));
                            }
                            r0 = 1;
                        }
                    }
                }
            } else {
                r0 = GCALL7(0x06015D00, r10, 40, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                r5 = 8;
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r0 = GCALL7(0x06013C60, r10, r5, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                    r7 = r0;
                    ST16((r7 + 24), r13);
                    ST32(r7 + 28, r8);
                    ST16((r7 + 26), r12);
                    ST32(r7 + 32, r9);
                    r0 = LD16((2 + (sp - 60)));
                    ST16((r7 + 36), r0);
                    r3 = LD8((7 + (sp - 60)));
                    ST8((r7 + 38), r3);
                    r0 = LD8((11 + (sp - 60)));
                    ST8((r7 + 39), r0);
                    if (r8 >= r9) {
                        ST32(r7 + 12, r9);
                        ST32(r7 + 16, r8);
                    } else {
                        ST32(r7 + 12, r8);
                        ST32(r7 + 16, r9);
                    }
                    r2 = 148;
                    r1 = LD32(r10 + 148);
                    if (!((r1 & r1) == 0)) {
                        ST32(r1, r7);
                    }
                    r0 = r10;
                    ST32(r0 + r2, (r7 + 4));
                    r1 = LD32(r0 + 152);
                    ST32(r0 + 152, (r1 + 40));
                    r1 = LD32(r0 + 164);
                    ST32(r0 + 164, (r1 + 1));
                    r2 = r9;
                    r1 = LD32(r10 + 28);
                    r0 = 1;
                    if ((r2 + r11) >= r1) {
                        r1 = LD32(0x10C8 + r10);
                        c7 = (r1 & r1) == 0;
                        r1 = 2;
                        if (c7) {
                            r4 = LD8(r10 + 168);
                            r0 = GCALL7(0x0601EFA4, (r4 & 255), 0, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r2 = r0;
                            ST32(sp - 44, 64);
                            ST32(sp - 40, 224);
                            if (r2 > 32) {
                                r3 = 0;
                                if (r2 > 66) {
                                    ST32(sp - 40, 128);
                                    r3 = 0;
                                }
                            } else {
                                ST32(sp - 44, 128);
                                ST32(sp - 40, 192);
                                r3 = 0;
                            }
                            r0 = LD32(sp - 56);
                            ST32(sp - 48, r3);
                            if (!(r3 >= r0)) {
                                r14 = r9;
                                r1 = LD32(sp - 44);
                                r11 = r8;
                                r3 = LD32(sp - 44);
                                ST32(sp - 36, (r3 | ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1))));
                                do {
                                    r0 = LD32(sp - 52);
                                    r7 = r11;
                                    if ((r0 & r0) == 0) {
                                        r1 = LD32(sp - 40);
                                        r3 = LD32(sp - 40);
                                        r8 = LD32(sp - 60);
                                        r8 = r8 & ((((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)));
                                        ST32((sp - 64), r8);
                                        r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        r7 = r14;
                                        r6 = r12;
                                        r5 = r13;
                                        r1 = LD32(sp - 44);
                                        r4 = r10;
                                        r3 = LD32(sp - 36);
                                        r0 = 0x06014638;
                                        r9 = LD32(sp - 60);
                                        r1 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3;
                                    } else {
                                        r1 = LD32(sp - 44);
                                        r3 = LD32(sp - 36);
                                        r8 = LD32(sp - 60);
                                        r8 = r8 & (((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3);
                                        ST32((sp - 64), r8);
                                        r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                        r7 = r14;
                                        r6 = r12;
                                        r5 = r13;
                                        r1 = LD32(sp - 40);
                                        r4 = r10;
                                        r3 = LD32(sp - 40);
                                        r0 = 0x06014638;
                                        r9 = LD32(sp - 60);
                                        r1 = (((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2));
                                    }
                                    r9 = r9 & r1;
                                    ST32((sp - 68), r9);
                                    r0 = GCALL8(r0, r4, r5, r6, r7, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
                                    ST32((sp - 72), r8);
                                    r0 = GCALL8(0x060146A4, r10, r13, r11, r14, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                                    ST32((sp - 76), r9);
                                    r0 = GCALL8(0x060146A4, r10, r12, r11, r14, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                                    r14 = r14 - 1;
                                    r13 = r13 + 1;
                                    r12 = r12 - 1;
                                    r3 = LD32(sp - 48);
                                    r11 = r11 + 1;
                                    r0 = LD32(sp - 56);
                                    r3 = r3 + 1;
                                    ST32(sp - 48, r3);
                                } while (AGAIN(!(r3 >= r0)));
                            }
                            r0 = 1;
                        } else {
                            r2 = LD32(0x10CC + r10);
                            r0 = 1;
                            if (r2 > r1) {
                                r4 = LD8(r10 + 168);
                                r0 = GCALL7(0x0601EFA4, (r4 & 255), 0, 0, 0, LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r2 = r0;
                                ST32(sp - 44, 64);
                                ST32(sp - 40, 224);
                                if (r2 > 32) {
                                    r3 = 0;
                                    if (r2 > 66) {
                                        ST32(sp - 40, 128);
                                        r3 = 0;
                                    }
                                } else {
                                    ST32(sp - 44, 128);
                                    ST32(sp - 40, 192);
                                    r3 = 0;
                                }
                                r0 = LD32(sp - 56);
                                ST32(sp - 48, r3);
                                if (!(r3 >= r0)) {
                                    r14 = r9;
                                    r1 = LD32(sp - 44);
                                    r11 = r8;
                                    r3 = LD32(sp - 44);
                                    ST32(sp - 36, (r3 | ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1))));
                                    do {
                                        r0 = LD32(sp - 52);
                                        r7 = r11;
                                        if ((r0 & r0) == 0) {
                                            r1 = LD32(sp - 40);
                                            r3 = LD32(sp - 40);
                                            r8 = LD32(sp - 60);
                                            r8 = r8 & ((((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)));
                                            ST32((sp - 64), r8);
                                            r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                            r7 = r14;
                                            r6 = r12;
                                            r5 = r13;
                                            r1 = LD32(sp - 44);
                                            r4 = r10;
                                            r3 = LD32(sp - 36);
                                            r0 = 0x06014638;
                                            r9 = LD32(sp - 60);
                                            r1 = ((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3;
                                        } else {
                                            r1 = LD32(sp - 44);
                                            r3 = LD32(sp - 36);
                                            r8 = LD32(sp - 60);
                                            r8 = r8 & (((int)((unsigned)((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 2)) >> 2)) | r3);
                                            ST32((sp - 64), r8);
                                            r0 = GCALL8(0x06014638, r10, r13, r12, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                            r7 = r14;
                                            r6 = r12;
                                            r5 = r13;
                                            r1 = LD32(sp - 40);
                                            r4 = r10;
                                            r3 = LD32(sp - 40);
                                            r0 = 0x06014638;
                                            r9 = LD32(sp - 60);
                                            r1 = (((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) | r3) | ((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2));
                                        }
                                        r9 = r9 & r1;
                                        ST32((sp - 68), r9);
                                        r0 = GCALL8(r0, r4, r5, r6, r7, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
                                        ST32((sp - 72), r8);
                                        r0 = GCALL8(0x060146A4, r10, r13, r11, r14, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
                                        ST32((sp - 76), r9);
                                        r0 = GCALL8(0x060146A4, r10, r12, r11, r14, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
                                        r14 = r14 - 1;
                                        r13 = r13 + 1;
                                        r12 = r12 - 1;
                                        r3 = LD32(sp - 48);
                                        r11 = r11 + 1;
                                        r0 = LD32(sp - 56);
                                        r3 = r3 + 1;
                                        ST32(sp - 48, r3);
                                    } while (AGAIN(!(r3 >= r0)));
                                }
                                r0 = 1;
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
int f060159A4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c2;

    r8 = r4;
    r9 = r5;
    r11 = r6;
    r1 = LD32(136 + r8);
    r10 = r7;
    if ((r1 & r1) == 0) {
        r0 = 0;
    } else {
        r1 = LD32(0x10C8 + r8);
        if ((r1 & r1) == 0) {
            r0 = GCALL2(0x06015D00, r8, 44);
            r5 = 6;
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r0 = GCALL2(0x06013C60, r8, r5);
                r3 = r0;
                ST16((r3 + 24), r11);
                ST32(r3 + 28, r10);
                r0 = r9;
                r1 = LD32(r0 + 196);
                ST16((r3 + 26), r1);
                r1 = LD32(r0 + 200);
                ST32(r3 + 32, r1);
                r1 = LD32(r0 + 200);
                ST32(r3 + 16, (r1 + r10));
                ST32(r3 + 12, r10);
                ST32(r3 + 36, r9);
                r2 = 148;
                r1 = LD32(r9 + 12);
                ST32(r3 + 40, r1);
                r1 = LD32(r8 + 148);
                if (!((r1 & r1) == 0)) {
                    ST32(r1, r3);
                }
                r0 = r8;
                ST32(r0 + r2, (r3 + 4));
                r1 = LD32(r0 + 152);
                ST32(r0 + 152, (r1 + 44));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                r0 = 1;
            }
        } else {
            r0 = LD32(0x10CC + r8);
            c2 = r0 == 3;
            r0 = 0;
            if (c2) {
                r0 = GCALL2(0x06015D00, r8, 44);
                r5 = 6;
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r0 = GCALL2(0x06013C60, r8, r5);
                    r3 = r0;
                    ST16((r3 + 24), r11);
                    ST32(r3 + 28, r10);
                    r0 = r9;
                    r1 = LD32(r0 + 196);
                    ST16((r3 + 26), r1);
                    r1 = LD32(r0 + 200);
                    ST32(r3 + 32, r1);
                    r1 = LD32(r0 + 200);
                    ST32(r3 + 16, (r1 + r10));
                    ST32(r3 + 12, r10);
                    ST32(r3 + 36, r9);
                    r2 = 148;
                    r1 = LD32(r9 + 12);
                    ST32(r3 + 40, r1);
                    r1 = LD32(r8 + 148);
                    if (!((r1 & r1) == 0)) {
                        ST32(r1, r3);
                    }
                    r0 = r8;
                    ST32(r0 + r2, (r3 + 4));
                    r1 = LD32(r0 + 152);
                    ST32(r0 + 152, (r1 + 44));
                    r1 = LD32(r0 + 164);
                    ST32(r0 + 164, (r1 + 1));
                    r0 = 1;
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06016A10(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7;

    r4 = 0x06089CC8;
    r1 = LD32(0x06089CC8);
    r5 = 0;
    r6 = 0;
    if (!(0 >= r1)) {
        do {
            r7 = LD32(0x06089CCC);
            r1 = LD32(0x06089CD0);
            r0 = r6;
            r3 = r6 + r1;
            r1 = LD32(r0 + r1);
            r2 = r6 + r7;
            ST32(r0 + r7, r1);
            r1 = LD32(r3 + 4);
            r7 = r3 + 8;
            ST32(r2 + 4, r1);
            r1 = LD32(r7);
            r7 = r7 + 4;
            r2 = r2 + 8;
            ST32(r2, r1);
            r1 = LD32(r7);
            r7 = r7 + 4;
            r2 = r2 + 4;
            ST32(r2, r1);
            r1 = LD32(r7);
            r7 = r7 + 4;
            r2 = r2 + 4;
            ST32(r2, r1);
            r1 = LD32(r7);
            r2 = r2 + 4;
            ST32(r2, r1);
            r1 = LD32((r7 + 4));
            ST32(r2 + 4, r1);
            ST32(r3 + 12, 0);
            r1 = LD32(r4);
            r5 = r5 + 1;
            r6 = r6 + 28;
        } while (AGAIN(!(r5 >= r1)));
    }
    r0 = LD32(0x06089CCC);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06016F08(void)
{
    int r0, r3, r7;

    r7 = 0x20100063;
    r0 = LD8(0x20100063);
    r0 = r0 & 1;
    r3 = 1;
    if (!((r0 & r0) == 0)) {
        return r0;
    } else {
        ST8(0x0608AB60, r3);
        ST8(0x20100001, r3);
        ST8(0x20100003, 10);
        ST8(0x20100005, -16);
        ST8(r7, r3);
        ST8(0x2010001F, 16);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06016F50(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8;

    r0 = SR();
    r8 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    SETSR((r0 | 240));
    r2 = 0;
    r4 = 31;
    r5 = 0x06089DC4;
    r6 = 0x06089CF0;
    r7 = 0x20100021;
    do {
        r1 = LD8(r5);
        r3 = (r1 & 255) + r2;
        r1 = LD8((r2 + r2) + r7);
        ST8(r3 + r6, r1);
        r2 = (r2 + 1) & 255;
    } while (AGAIN(!((unsigned)r2 > (unsigned)r4)));
    r1 = LD8(0x06089DC4);
    ST8(0x06089DC4, (r1 + 32));
    r1 = LD8(0x06086F90);
    ST8(0x06086F90, (r1 + 1));
    r0 = LD8(0x20100061);
    r0 = r0 & 32;
    if (!((r0 & r0) == 0)) {
        r0 = LD8(0x0608AB60);
        r0 = r0 ^ 128;
        ST8(0x0608AB60, r0);
        ST8(0x20100001, r0);
    }
    r1 = SR();
    SETSR(((r1 & -241) | ((r8 << 2) << 2)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06016FE4(void)
{
    int r0, r1, r8, r9, r10;

    ST8(0x06089CE0, 32);
    r0 = GCALL2(0x060170B4, 0, 0);
    r1 = LD8(0x06089CE0);
    ST8(0x06089CE0, (r1 + 1));
    r0 = GCALL2(0x060170B4, 1, (r0 & 255));
    r8 = 0;
    r10 = 0x060172E0;
    r9 = 29;
    do {
        r0 = GCALL1(r10, r8);
        r8 = (r8 + 1) & 255;
        r1 = 0;
    } while (AGAIN(!((unsigned)r8 > (unsigned)r9)));
    ST8(0x06089DC4, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601742C(void)
{
    ST8(0x2010007D, 0);
    ST8(0x2010007F, 0);
    ST8(0x20100079, 0);
    ST8(0x2010007B, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06017450(int r4)
{
    int r0, r1, c1;

    r0 = LD8(r4);
    r4 = r4 + 1;
    r1 = 0;
    if (!((r0 & r0) == 0)) {
        r0 = r0 & 127;
        do {
            r1 = r1 ^ r0;
            r0 = LD8(r4);
            r4 = r4 + 1;
            c1 = (r0 & r0) == 0;
            r0 = r0 & 127;
        } while (AGAIN(!(c1)));
    }
    return r1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06017C80(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r8, r9, r10;

    r8 = r4;
    r9 = r8;
    if ((r5 & r5) == 0) {
        r0 = GCALL1(0x0607507C, r8);
        r1 = r0 - 1;
        r3 = 0;
        if (r1 >= 0) {
            r7 = 0x06075135;
            r2 = r1 + r8;
            r4 = r8;
            while (1) {
                r1 = LD8(r2);
                r0 = LD8((r1 & 255) + r7);
                r0 = r0 & 8;
                if ((r0 & r0) == 0) {
                    break;
                } else {
                    ST8(r2, r3);
                    r2 = r2 - 1;
                    if (r2 >= r4) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
        }
    } else {
        r0 = GCALL1(0x060455FC, r4);
        r1 = r0 - 1;
        r8 = r1;
        if (r1 >= 0) {
            r10 = 0x060455C4;
            r8 = r8 + r8;
            r0 = r8;
            while (1) {
                r4 = LD16(r0 + r9);
                r0 = GCALL1(r10, (r4 & 0xFFFF));
                r1 = 0;
                if ((r0 & r0) == 0) {
                    break;
                } else {
                    r0 = r8;
                    r8 = r8 - 2;
                    ST16(r0 + r9, r1);
                    if (!(r8 >= 0)) {
                        break;
                    } else {
                        r0 = r8;
                    }
                }
                POLL();
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601852C(int r4)
{
    int r0, r1;

    r4 = r4 & 255;
    r1 = 99;
    if ((unsigned)r4 > (unsigned)9) {
        r0 = 3;
        if ((unsigned)r4 > (unsigned)r1) {
            return r0;
        } else {
            return 2;
        }
    } else {
        return 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06018550(int r4, int r5, int r6, int r7)
{
    int r0, r8;

    r8 = r4;
    r0 = GCALL4(0x06045264, r4, 0x06018548, (r5 & 255), r7);
    return r0 + r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06018A78(int r4)
{
    int r0, r1, r2, r3, r7;

    r1 = LD8(r4);
    r1 = r1 & 255;
    r0 = r1;
    if (!((r1 & r1) == 0)) {
        r3 = 0x06075135;
        do {
            r7 = LD8(r0 + r3);
            r2 = r1;
            if (!(((r7 & 2) & (r7 & 2)) == 0)) {
                r2 = r2 - 32;
            }
            ST8(r4, r2);
            r4 = r4 + 1;
            r1 = LD8(r4);
            r1 = r1 & 255;
            r0 = r1;
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06018AA8(int r4, int r5)
{
    int r1, r2, r3, r7;

    r7 = 7;
    r3 = r4 + 28;
    do {
        r1 = r3 + 104;
        r2 = LD32((r3 + 100));
        r3 = r3 - 4;
        r7 = r7 - 1;
        ST32(r1, r2);
    } while (AGAIN(r7 > 0));
    ST32((r4 + 104), r5);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06018ACC(int r4)
{
    int r0, r1, r2, r3, r6, r7;

    r7 = 0;
    r6 = 6;
    r3 = r4;
    do {
        r1 = r3 + 104;
        r2 = LD32((r3 + 108));
        r3 = r3 + 4;
        r7 = r7 + 1;
        ST32(r1, r2);
    } while (AGAIN(!(r7 > r6)));
    r1 = LD32((r4 + 100));
    ST32(132 + r4, r1);
    r0 = LD32((r4 + 104));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019064(int r4)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10;

    r8 = r4;
    r9 = -1;
    r7 = 0x06075135;
    r2 = r8;
    r3 = r8 + 5;
    while (1) {
        r1 = LD8(r2);
        r1 = r1 & 255;
        r0 = r1;
        if ((r1 & r1) == 0) {
            break;
        } else {
            r6 = LD8(r0 + r7);
            if (!(((r6 & 1) & (r6 & 1)) == 0)) {
                r1 = r1 + 32;
            }
            ST8(r2, r1);
            r2 = r2 + 1;
            if (!(r2 > r3)) {
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
    }
    r10 = 0x060752FC;
    r0 = GCALL3(0x060752FC, 0x06019028, r8, 5);
    r6 = 5;
    if (!((r0 & r0) == 0)) {
        r0 = GCALL3(r10, 0x06019030, r8, r6);
        r6 = 3;
        if (!((r0 & r0) == 0)) {
            r0 = GCALL3(r10, 0x06019038, r8, r6);
            r6 = 5;
            if (!((r0 & r0) == 0)) {
                r0 = GCALL3(r10, 0x0601903C, r8, r6);
                r6 = 4;
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL3(r10, 0x06019044, r8, r6);
                    r6 = 6;
                    if (!((r0 & r0) == 0)) {
                        r0 = GCALL3(r10, 0x0601904C, r8, r6);
                        r6 = 6;
                        if (!((r0 & r0) == 0)) {
                            r0 = GCALL3(r10, 0x06019054, r8, r6);
                            r6 = 4;
                            if (!((r0 & r0) == 0)) {
                                r0 = GCALL3(r10, 0x0601905C, r8, r6);
                                if ((r0 & r0) == 0) {
                                    r9 = 31;
                                }
                            } else {
                                r9 = 252;
                            }
                        } else {
                            r9 = 227;
                        }
                    } else {
                        r9 = 3;
                    }
                } else {
                    r9 = 28;
                }
            } else {
                r9 = 224;
            }
        } else {
            r9 = 0;
        }
    } else {
        r9 = 255;
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060192B8(int r4, int r5)
{
    int r0, r1, r8, r9, c2, c4;

    r9 = r4;
    r8 = r5;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL2(0x06019734, r9, r8);
    r8 = r0;
    if (r0 == -1) {
        r0 = 0x10B0;
        r1 = LD32(0x10B0 + r9);
        c2 = (r1 & r1) == 0;
        r1 = 1;
        if (c2) {
            r5 = LD32((r9 + 104));
            r4 = r9;
            r1 = 0x06018AA8;
            r0 = GCALL2(r1, r4, r5);
            r0 = 0x10B0;
            r1 = 1;
        }
    } else {
        r1 = LD32(0x10B0 + r9);
        if (!((r1 & r1) == 0)) {
            r0 = GCALL1(0x06018ACC, r9);
        }
        r1 = 0x06018AA8;
        r5 = r8;
        r4 = r9;
        r0 = GCALL2(r1, r4, r5);
        r0 = 0x10B0;
        r1 = 1;
    }
    ST32(r0 + r9, r1);
    r0 = GCALL1(0x0601D1C4, r9);
    r1 = LD32(0x10C8 + r9);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r9);
        c4 = r0 == 1;
        r0 = r9;
        if (c4) {
            r4 = LD32(r0 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r9 + 0x10D0, 0);
        }
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601935C(int r4)
{
    int r0, r1, r8, r9;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r9 = 0x10B0;
    r1 = LD32(r8 + 0x10B0);
    if (!((r1 & r1) == 0)) {
        r0 = GCALL1(0x06018ACC, r8);
        ST32(r8 + r9, 0);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019538(int r4)
{
    int r0, r1, r2, r3, r8, r9;

    r8 = r4;
    r1 = LD32(r8);
    r0 = 1;
    if ((r1 & r1) == 0) {
        r0 = GCALL1(0x0601D4D8, r8);
        r9 = 0x10B4;
        r4 = LD32(r8 + 0x10B4);
        r0 = GCALL1(0x06021724, r4);
        r1 = LD32(r8 + 0x10B4);
        r0 = GCALL1(0x060216EC, ((r0 << 8) | ((r1 & 3) | 4)));
        r2 = 4 | (r0 << 8);
        r3 = LD32(r8 + 0x10B4);
        r0 = 2;
        r1 = (1 & r3) | r2;
        if (!(((r3 & 2) & (r3 & 2)) == 0)) {
            r1 = r1 | r0;
        }
        ST32(r8 + r9, r1);
        ST32(r8, 1);
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060195B0(int r4)
{
    int r0, r1, r2, r3, r8, r9;

    r8 = r4;
    r1 = LD32(r8);
    r0 = 1;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL1(0x0601D4D8, r8);
        r9 = 0x10B4;
        r4 = LD32(r8 + 0x10B4);
        r0 = GCALL1(0x06021724, r4);
        r1 = LD32(r8 + 0x10B4);
        r0 = GCALL1(0x060216EC, ((r0 << 8) | (r1 & 3)));
        r2 = r0 << 8;
        r3 = LD32(r8 + 0x10B4);
        r0 = 2;
        r1 = (1 & r3) | r2;
        if (!(((r3 & 2) & (r3 & 2)) == 0)) {
            r1 = r1 | r0;
        }
        ST32(r8 + r9, r1);
        ST32(r8, 0);
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019620(int r4)
{
    int r0, r1, r2, r3, r8, r9;

    r8 = r4;
    r9 = 0x10B4;
    r4 = LD32(r8 + 0x10B4);
    r0 = GCALL1(0x06021724, r4);
    r1 = LD32(r8 + 0x10B4);
    r0 = GCALL1(0x060216EC, ((r0 << 8) | ((r1 & 3) | 4)));
    r2 = 4 | (r0 << 8);
    r3 = LD32(r8 + 0x10B4);
    r0 = 2;
    r1 = (1 & r3) | r2;
    if (!(((r3 & 2) & (r3 & 2)) == 0)) {
        r1 = r1 | r0;
    }
    ST32(r8 + r9, r1);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019680(int r4)
{
    int r0, r1, r2, r3, r8, r9;

    r8 = r4;
    r9 = 0x10B4;
    r4 = LD32(r8 + 0x10B4);
    r0 = GCALL1(0x06021724, r4);
    r1 = LD32(r8 + 0x10B4);
    r0 = GCALL1(0x060216EC, ((r0 << 8) | (r1 & 3)));
    r2 = r0 << 8;
    r3 = LD32(r8 + 0x10B4);
    r0 = 2;
    r1 = (1 & r3) | r2;
    if (!(((r3 & 2) & (r3 & 2)) == 0)) {
        r1 = r1 | r0;
    }
    ST32(r8 + r9, r1);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019968(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r10, c1, c2;

    r8 = r4;
    r10 = r5;
    r0 = GCALL1(0x0601D4D8, r4);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        c1 = r0 == 1;
        r0 = r8;
        if (c1) {
            r4 = LD32(r0 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r2 = 0x10B4;
    r1 = LD32(0x0607656C);
    r3 = LD32(r8 + 0x10B4);
    r1 = r1 << 8;
    c2 = ((r3 & 2) & (r3 & 2)) == 0;
    r3 = 1 | r1;
    if (!(c2)) {
        r3 = 3 | r1;
    }
    ST32(r8 + r2, r3);
    r0 = GCALL2(0x06019734, r8, r10);
    r2 = r0;
    if (r0 == -1) {
        r5 = LD32((r8 + 104));
        r4 = r8;
        r1 = 0x06018AA8;
    } else {
        r1 = 0x06018AA8;
        r5 = r2;
        r4 = r8;
    }
    r0 = GCALL2(r1, r4, r5);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019A08(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r10, c1, c2;

    r8 = r4;
    r10 = r5;
    r0 = GCALL1(0x0601D4D8, r4);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        c1 = r0 == 1;
        r0 = r8;
        if (c1) {
            r4 = LD32(r0 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r2 = 0x10B4;
    r1 = LD32(0x06076570);
    r3 = LD32(r8 + 0x10B4);
    r1 = r1 << 8;
    c2 = ((r3 & 2) & (r3 & 2)) == 0;
    r3 = 1 | r1;
    if (!(c2)) {
        r3 = 3 | r1;
    }
    ST32(r8 + r2, r3);
    r0 = GCALL2(0x06019734, r8, r10);
    r2 = r0;
    if (r0 == -1) {
        r5 = LD32((r8 + 104));
        r4 = r8;
        r1 = 0x06018AA8;
    } else {
        r1 = 0x06018AA8;
        r5 = r2;
        r4 = r8;
    }
    r0 = GCALL2(r1, r4, r5);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019AA8(int r4, int r5)
{
    int r0, r1, r2, r8, r10, c1, c2;

    r8 = r4;
    r10 = r5;
    r0 = GCALL1(0x0601D4D8, r4);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        c1 = r0 == 1;
        r0 = r8;
        if (c1) {
            r4 = LD32(r0 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r1 = LD32(0x06076574);
    r2 = r8 + 0x10B4;
    r0 = LD32(0x10B4 + r8);
    r1 = r1 << 8;
    c2 = ((r0 & 1) & (r0 & 1)) == 0;
    r0 = 3;
    if (c2) {
        r0 = 2;
    }
    ST32(r2, (r1 | r0));
    r0 = GCALL2(0x06019734, r8, r10);
    r2 = r0;
    if (r0 == -1) {
        r5 = LD32((r8 + 104));
        r4 = r8;
        r1 = 0x06018AA8;
    } else {
        r1 = 0x06018AA8;
        r5 = r2;
        r4 = r8;
    }
    r0 = GCALL2(r1, r4, r5);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019B44(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r10, c1, c2;

    r8 = r4;
    r10 = r5;
    r0 = GCALL1(0x0601D4D8, r4);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        c1 = r0 == 1;
        r0 = r8;
        if (c1) {
            r4 = LD32(r0 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r2 = 0x10B4;
    r1 = LD32(0x06076578);
    r3 = LD32(r8 + 0x10B4);
    r1 = r1 << 8;
    c2 = ((r3 & 2) & (r3 & 2)) == 0;
    r3 = 1 | r1;
    if (!(c2)) {
        r3 = 3 | r1;
    }
    ST32(r8 + r2, r3);
    r0 = GCALL2(0x06019734, r8, r10);
    r2 = r0;
    if (r0 == -1) {
        r5 = LD32((r8 + 104));
        r4 = r8;
        r1 = 0x06018AA8;
    } else {
        r1 = 0x06018AA8;
        r5 = r2;
        r4 = r8;
    }
    r0 = GCALL2(r1, r4, r5);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019BE4(int r4, int r5)
{
    int r0, r1, r2, r3, r7, r8, r10, c1;

    r8 = r4;
    r10 = r5;
    r0 = GCALL1(0x0601D4D8, r4);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        c1 = r0 == 1;
        r0 = r8;
        if (c1) {
            r4 = LD32(r0 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r3 = 0x10B4;
    r2 = LD32(0x0607657C);
    r7 = LD32(r8 + 0x10B4);
    r0 = 2;
    r1 = (1 & r7) | (r2 << 8);
    if (!(((r7 & 2) & (r7 & 2)) == 0)) {
        r1 = r1 | r0;
    }
    ST32(r8 + r3, r1);
    r0 = GCALL2(0x06019734, r8, r10);
    r2 = r0;
    if (r0 == -1) {
        r5 = LD32((r8 + 104));
        r4 = r8;
        r1 = 0x06018AA8;
    } else {
        r1 = 0x06018AA8;
        r5 = r2;
        r4 = r8;
    }
    r0 = GCALL2(r1, r4, r5);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019C84(int r4, int r5)
{
    int r0, r1, r2, r3, r8, r10, c1, c2;

    r8 = r4;
    r10 = r5;
    r0 = GCALL1(0x0601D4D8, r4);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        c1 = r0 == 1;
        r0 = r8;
        if (c1) {
            r4 = LD32(r0 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r2 = 0x10B4;
    r1 = LD32(0x06076580);
    r3 = LD32(r8 + 0x10B4);
    r1 = r1 << 8;
    c2 = ((r3 & 2) & (r3 & 2)) == 0;
    r3 = 1 | r1;
    if (!(c2)) {
        r3 = 3 | r1;
    }
    ST32(r8 + r2, r3);
    r0 = GCALL2(0x06019734, r8, r10);
    r2 = r0;
    if (r0 == -1) {
        r5 = LD32((r8 + 104));
        r4 = r8;
        r1 = 0x06018AA8;
    } else {
        r1 = 0x06018AA8;
        r5 = r2;
        r4 = r8;
    }
    r0 = GCALL2(r1, r4, r5);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019D24(int r4)
{
    int r0, r1, r2, r3, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x0601D1C4, r8);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        if (r0 == 1) {
            r4 = LD32(r8 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r0 = r8;
    r1 = LD32(r0 + 0x10BC);
    ST32(r0 + 0x10B4, r1);
    r3 = LD32(r0 + 0x10B8);
    r1 = LD32(r0 + 0x10C0);
    r2 = LD16(r1);
    ST16(r3, r2);
    r1 = LD16((r1 + 2));
    ST16((r3 + 2), r1);
    r0 = GCALL1(0x06018ACC, r8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019DA4(int r4)
{
    int r0, r1, r2, r3, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x0601D1C4, r8);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        if (r0 == 1) {
            r4 = LD32(r8 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r0 = r8;
    r1 = LD32(r0 + 0x10BC);
    ST32(r0 + 0x10B4, r1);
    r3 = LD32(r0 + 0x10B8);
    r1 = LD32(r0 + 0x10C0);
    r2 = LD16(r1);
    ST16(r3, r2);
    r1 = LD16((r1 + 2));
    ST16((r3 + 2), r1);
    r0 = GCALL1(0x06018ACC, r8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019E24(int r4)
{
    int r0, r1, r2, r3, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x0601D1C4, r8);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        if (r0 == 1) {
            r4 = LD32(r8 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r0 = r8;
    r1 = LD32(r0 + 0x10BC);
    ST32(r0 + 0x10B4, r1);
    r3 = LD32(r0 + 0x10B8);
    r1 = LD32(r0 + 0x10C0);
    r2 = LD16(r1);
    ST16(r3, r2);
    r1 = LD16((r1 + 2));
    ST16((r3 + 2), r1);
    r0 = GCALL1(0x06018ACC, r8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019EA4(int r4)
{
    int r0, r1, r2, r3, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x0601D1C4, r8);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        if (r0 == 1) {
            r4 = LD32(r8 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r0 = r8;
    r1 = LD32(r0 + 0x10BC);
    ST32(r0 + 0x10B4, r1);
    r3 = LD32(r0 + 0x10B8);
    r1 = LD32(r0 + 0x10C0);
    r2 = LD16(r1);
    ST16(r3, r2);
    r1 = LD16((r1 + 2));
    ST16((r3 + 2), r1);
    r0 = GCALL1(0x06018ACC, r8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019F24(int r4)
{
    int r0, r1, r2, r3, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x0601D1C4, r8);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        if (r0 == 1) {
            r4 = LD32(r8 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r0 = r8;
    r1 = LD32(r0 + 0x10BC);
    ST32(r0 + 0x10B4, r1);
    r3 = LD32(r0 + 0x10B8);
    r1 = LD32(r0 + 0x10C0);
    r2 = LD16(r1);
    ST16(r3, r2);
    r1 = LD16((r1 + 2));
    ST16((r3 + 2), r1);
    r0 = GCALL1(0x06018ACC, r8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06019FA4(int r4)
{
    int r0, r1, r2, r3, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x0601D1C4, r8);
    r1 = LD32(0x10C8 + r8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        if (r0 == 1) {
            r4 = LD32(r8 + 0x10D0);
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + 0x10D0, 0);
        }
    }
    r0 = r8;
    r1 = LD32(r0 + 0x10BC);
    ST32(r0 + 0x10B4, r1);
    r3 = LD32(r0 + 0x10B8);
    r1 = LD32(r0 + 0x10C0);
    r2 = LD16(r1);
    ST16(r3, r2);
    r1 = LD16((r1 + 2));
    ST16((r3 + 2), r1);
    r0 = GCALL1(0x06018ACC, r8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A024(int r4)
{
    int r2;

    r2 = LD32(r4 + 0x10B4);
    ST32(r4 + 0x10B4, (r2 | 1));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A038(int r4)
{
    int r2;

    r2 = LD32(r4 + 0x10B4);
    ST32(r4 + 0x10B4, (r2 | 2));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A04C(int r4)
{
    int r0, r1;

    r1 = LD32(0x10B8 + r4);
    r1 = r1 + 2;
    r0 = LD8(r1);
    ST8(r1, (r0 | 64));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A060(int r4)
{
    int r0, r1;

    r1 = LD32(0x10B8 + r4);
    r1 = r1 + 2;
    r0 = LD8(r1);
    ST8(r1, (r0 | 32));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A074(int r4)
{
    int r1;

    r1 = LD32(0x10B4 + r4);
    ST32(0x10B4 + r4, (r1 & -2));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A084(int r4)
{
    int r1;

    r1 = LD32(0x10B4 + r4);
    ST32(0x10B4 + r4, (r1 & -3));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A094(int r4)
{
    int r0, r1;

    r1 = LD32(0x10B8 + r4);
    r1 = r1 + 2;
    r0 = LD8(r1);
    ST8(r1, (r0 & 191));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A0A8(int r4)
{
    int r0, r1;

    r1 = LD32(0x10B8 + r4);
    r1 = r1 + 2;
    r0 = LD8(r1);
    ST8(r1, (r0 & 223));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A0BC(int r4)
{
    int r0, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x0601D810, r8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A314(int r4)
{
    int r0, r1, r2, r3;

    r0 = r4;
    r1 = LD32(r0 + 0x10BC);
    ST32(r0 + 0x10B4, r1);
    r1 = LD32((r4 + 88));
    if ((r1 & r1) == 0) {
        r3 = LD32(0x10B8 + r4);
        r1 = LD32(0x10C0 + r4);
    } else {
        r3 = LD32(0x10B8 + r4);
        r1 = LD32(0x10C4 + r4);
    }
    r2 = LD16(r1);
    ST16(r3, r2);
    r1 = LD16((r1 + 2));
    ST16((r3 + 2), r1);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601AA5C(int r4)
{
    int r0, r1, r8;

    r8 = r4;
    r0 = GCALL1(0x0601A038, r4);
    r0 = GCALL2(0x0601D178, r8, 72);
    r1 = LD32(0x10D0 + r8);
    ST32(0x10D0 + r8, (r1 + 72));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601AA88(int r4)
{
    int r0;

    r0 = GCALL1(0x0601A084, r4);
    r0 = GCALL2(0x0601D178, r4, -72);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601AAAC(int r4)
{
    int r0, r1, r8, r9;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL2(0x0601D178, r8, 18);
    r0 = GCALL2(0x0601D1A0, r8, 18);
    r0 = GCALL1(0x0601D1C4, r8);
    r9 = 0x10D0;
    r0 = r8;
    r1 = LD32(r0 + 0x10D0);
    r4 = r1 + 18;
    ST32(r0 + 0x10D0, r4);
    r1 = LD32(r0 + 0x10C8);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        if (r0 == 1) {
            r0 = GCALL1(0x0602AC4C, r4);
            ST32(r8 + r9, 0);
        }
    }
    r1 = LD32(r8 + 4);
    ST32(r8 + 4, (r1 + 1));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601ABA8(int r4)
{
    ST8(0x1B0 + r4, 0);
    ST32(r4 + 48, 0);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601AC78(int r4)
{
    int r0, r1, r2, r5, r8, r9;

    r9 = r4;
    r0 = GCALL2(0x06028380, 16, -1);
    r8 = r0;
    r5 = 24;
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        r0 = GCALL2(0x0601D178, r9, r5);
        r1 = LD32(0x10D0 + r9);
        r2 = r9 + 84;
        ST32(0x10D0 + r9, (r1 + 24));
        r1 = LD32(r2);
        r0 = 1;
        ST32(r8 + 12, r1);
        ST32(r2, r8);
        ST32(r8, 1);
        ST32(r8 + 4, 1);
        ST32(r8 + 8, 1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601AFA8(int r4)
{
    int r0, r1, r2, r5, r8, r9;

    r9 = r4;
    r0 = GCALL2(0x06028380, 16, -1);
    r8 = r0;
    r5 = 24;
    if ((r8 & r8) == 0) {
        r0 = 0;
    } else {
        r0 = GCALL2(0x0601D178, r9, r5);
        r1 = LD32(0x10D0 + r9);
        r2 = r9 + 84;
        ST32(0x10D0 + r9, (r1 + 24));
        r1 = LD32(r2);
        r0 = 1;
        ST32(r8 + 12, r1);
        ST32(r2, r8);
        ST32(r8, 1);
        ST32(r8 + 4, 1);
        ST32(r8 + 8, 1);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601B028(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11;

    r10 = r4;
    r9 = r5;
    r8 = r6;
    r11 = r7;
    r0 = GCALL2(0x06028380, 20, -1);
    r2 = r0;
    if (!((r0 & r0) == 0)) {
        ST32(r0, r11);
        r7 = r10 + 64;
        r3 = r10 + 68;
        r1 = LD32(r7);
        ST16((r2 + 4), r1);
        r1 = LD32(r3);
        ST16((r0 + 6), r1);
        ST16((r0 + 8), r9);
        ST16((r0 + 10), r8);
        if (r8 >= 0) {
            ST32(r3, r8);
        }
        if (r9 >= 0) {
            ST32(r7, r9);
        }
        r2 = r10 + 80;
        r1 = LD32(r2);
        ST32(r0 + 12, r1);
        ST32(r2, r0);
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601B124(int r4)
{
    int r0, r1, r9, r10, r11, r12, r13;

    r11 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r9 = r11 + 80;
    r1 = LD32(r9);
    r10 = 0;
    if (!((r1 & r1) == 0)) {
        r12 = r11 + 64;
        r13 = 0x06027F48;
        do {
            r4 = LD32(r9);
            r1 = LD32(r4 + 12);
            ST32(r9, r1);
            r1 = r4;
            r10 = LD32(r1);
            r1 = LD16((r1 + 4));
            ST32(r12, r1);
            ST32(r11 + 8, r1);
            r0 = GCALL1(r13, r4);
            r1 = LD32(r9);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601B1E4(int r4)
{
    int r0, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x0601B188, r8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601B204(int r4)
{
    int r0, r1, r5, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x0601B188, r8);
    r5 = 36;
    if (!((r0 & r0) == 0)) {
        r0 = GCALL2(0x0601D178, r8, r5);
        r1 = LD32(0x10D0 + r8);
        ST32(0x10D0 + r8, (r1 + 36));
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601B858(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9;
    FRAME(sp, 92);

    r8 = r4;
    r0 = GCALL1(0x0607507C, r4);
    r7 = r0;
    r3 = 0;
    r5 = 0;
    if (!(0 >= r7)) {
        r6 = 1;
        r0 = r8;
        do {
            r2 = LD8(r0 + r5);
            if ((unsigned)((r2 - 34) & 255) > (unsigned)r6) {
                ST8((sp - 92) + r3, r2);
                r3 = r3 + 1;
            }
            r5 = r5 + 1;
            r0 = r8;
        } while (AGAIN(!(r5 >= r7)));
    }
    ST8((sp - 92) + r3, 0);
    r8 = LD32(0x0607655C);
    r4 = r8;
    if ((r8 & r8) == 0) {
        r0 = GCALL2(0x06028380, 88, -1);
        r8 = r0;
        r1 = 0;
        if ((r8 & r8) == 0) {
            r0 = 0;
        } else {
            ST32(r8, r1);
            r1 = LD32(0x0607655C);
            ST32(r8 + 4, r1);
            ST32(0x0607655C, r8);
            r0 = GCALL2(0x060750DC, (r8 + 8), (sp - 92));
            r0 = r8;
        }
    } else {
        r9 = 0x06075104;
        while (1) {
            r0 = GCALL2(r9, (r4 + 8), (sp - 92));
            if ((r0 & r0) == 0) {
                r0 = r8;
                break;
            } else {
                r8 = LD32(r8 + 4);
                r4 = r8;
                if (!((r8 & r8) == 0)) {
                    POLL();
                    continue;
                } else {
                    r0 = GCALL2(0x06028380, 88, -1);
                    r8 = r0;
                    r1 = 0;
                    if ((r8 & r8) == 0) {
                        r0 = 0;
                        break;
                    } else {
                        ST32(r8, r1);
                        r1 = LD32(0x0607655C);
                        ST32(r8 + 4, r1);
                        ST32(0x0607655C, r8);
                        r0 = GCALL2(0x060750DC, (r8 + 8), (sp - 92));
                        r0 = r8;
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
int f0601BDAC(int r4)
{
    int r0, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL2(0x06018AA8, r8, 1);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601BDD0(int r4)
{
    int r0, r8;

    r8 = r4;
    r0 = GCALL1(0x0601D4D8, r4);
    r0 = GCALL1(0x06018ACC, r8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601BED0(void)
{
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601C89C(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x0601DD98, r4, 0x06079D34, 0, r7);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CB70(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GCALL4(0x06025A0C, 7, r5, r6, r7);
    r0 = LD32(0x060875C8);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CB88(void)
{
    int r0, r1;

    r1 = LD32(0x06000334);
    r0 = GCALL1(r1, 7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CD44(void)
{
    int r0;

    r0 = LD32(0x06076560);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CD50(void)
{
    int r0;

    r0 = LD32(0x06076564);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CF94(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10;

    r8 = r4;
    r9 = r6;
    r2 = LD32((r8 + 68));
    r1 = LD32((r8 + 64));
    r3 = LD32(r8 + 48);
    r10 = r5 & 255;
    if ((r3 + r9) > (r2 - r1)) {
        if (r3 > 0) {
            r0 = GCALL1(0x0601D1C4, r4);
        }
    }
    r1 = LD32(r8 + 48);
    ST32(r8 + 48, (r1 + r9));
    r1 = LD32(r8 + 52);
    ST32(r8 + 52, (r1 + r9));
    r1 = LD32(0x10D4 + r8);
    if ((r1 & r1) == 0) {
        r8 = r8 + 0x1B0;
        r0 = GCALL1(0x0607507C, r8);
        r7 = r0;
        ST8(r8 + r7, r10);
        ST8(((r7 + r8) + 1), 0);
    } else {
        r8 = r8 + 0x1B0;
        r0 = GCALL1(0x060455FC, r8);
        r7 = r0;
        r3 = r7 + r7;
        ST16(r3 + r8, (-32768 | r10));
        ST16(((r3 + r8) + 2), 0);
    }
    return r7;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D104(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10;

    r8 = r4;
    r9 = r5;
    r10 = r6;
    r0 = GCALL1(0x0601D4D8, r4);
    r2 = r8 + 64;
    ST32(r2, r9);
    ST32((r8 + 68), r10);
    r1 = LD32(r2);
    ST32(r8 + 8, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D134(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10;

    r8 = r4;
    r9 = r5;
    r10 = r6;
    r0 = GCALL1(0x0601D4D8, r4);
    ST32(r8 + 8, r9);
    ST32(r8 + 12, r10);
    r9 = r8 + 80;
    r1 = LD32(r9);
    if (!((r1 & r1) == 0)) {
        r10 = 0x06027F48;
        do {
            r4 = LD32(r9);
            r1 = LD32(r4 + 12);
            ST32(r9, r1);
            r0 = GCALL1(r10, r4);
            r1 = LD32(r9);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D178(int r4, int r5)
{
    int r0, r1, r2, r8, r9;

    r8 = r4;
    r9 = r5;
    r0 = GCALL1(0x0601D4D8, r4);
    r2 = r8 + 64;
    r1 = LD32(r2);
    r1 = r1 + r9;
    ST32(r2, r1);
    ST32(r8 + 8, r1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D1A0(int r4, int r5)
{
    int r0, r1, r8, r9;

    r8 = r4;
    r9 = r5;
    r0 = GCALL1(0x0601D4D8, r4);
    r8 = r8 + 68;
    r1 = LD32(r8);
    ST32(r8, (r1 - r9));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D390(int r4, int r5, int r6, int r7)
{
    int r0;

    r5 = LD32((r4 + (((r5 + r5) + r5) << 2)) + 0x2B4);
    r0 = GCALL4(0x0603696C, r4, r5, 0, r7);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D3B8(int r4, int r5)
{
    int r0;

    r5 = LD32((r4 + (((r5 + r5) + r5) << 2)) + 0x2B4);
    r0 = GCALL2(0x060351C4, r4, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D3E0(int r4, int r5)
{
    int r0;

    r5 = LD32((r4 + (((r5 + r5) + r5) << 2)) + 0x2B4);
    r0 = GCALL2(0x0603588C, r4, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D810(int r4)
{
    int r0, r8, r9, r10, r11, r12, r13, r14;
    int v36;
    int v40;

    r10 = r4;
    r0 = GCALL1(0x0601D1C4, r4);
    r9 = 0;
    r14 = 73;
    r12 = LD32((r10 + 64));
    r13 = 0x06014C4C;
    r8 = LD32(r10 + 12);
    r11 = LD32((r10 + 68));
    do {
        r0 = GCALL6(r13, r10, r12, r8, (r11 - 1), r8, r14);
        r8 = r8 + 1;
        r9 = r9 + 1;
    } while (AGAIN(!(r9 > 1)));
    r9 = 0;
    r14 = -1;
    r13 = 0x06014C4C;
    do {
        r0 = GCALL6(r13, r10, (r12 + 1), r8, r11, r8, r14);
        r8 = r8 + 1;
        r9 = r9 + 1;
    } while (AGAIN(!(r9 > 1)));
    r0 = GCALL1(0x0601D1C4, r10);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D9E8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, c2;

    r8 = r4;
    r9 = r5;
    r4 = LD32(0x10B4 + r8);
    r0 = GCALL4(0x0601CC78, r4, 128, 0, r7);
    r2 = LD32(r0 + 40);
    if ((r9 & r9) == 0) {
        r6 = 0;
    } else {
        r1 = 3;
        if (!(r9 >= 0)) {
            r6 = 0;
        } else {
            c2 = r9 > r1;
            r1 = r2;
            if (c2) {
                r6 = 0;
            } else {
                r6 = (((r1 + r1) + r2) + ((int)((unsigned)((r1 + r1) + r2) >> 31))) >> 1;
            }
        }
    }
    r5 = 5;
    if (r6 > 0) {
        r0 = GCALL3(0x0601CF94, r8, r5, r6);
        r7 = LD32(r8 + 56);
        r1 = r7 + r7;
        ST16((r1 + r8) + 0xEB0, r0);
        r0 = r8;
        ST16(r0 + (((r1 + r7) << 2) + 0x2B0), r9);
        r1 = LD32(r8 + 56);
        ST32(r8 + 56, (r1 + 1));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601DBAC(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12, r13;
    FRAME(sp, 28);

    r11 = r4;
    r10 = r5;
    r9 = r6;
    r8 = r7;
    r13 = LD32(sp);
    if (r8 > r9) {
        r12 = 0x0601DAB0;
        r7 = r8;
        while (1) {
            r0 = GCALL4(r12, r11, r10, r9, r7);
            if (!(r0 >= r13)) {
                break;
            } else {
                r8 = r8 - 1;
                r7 = r8;
                if (r8 > r9) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601DCE8(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12, r13;
    FRAME(sp, 28);

    r11 = r4;
    r10 = r5;
    r9 = r6;
    r8 = r7;
    r13 = LD32(sp);
    if (r8 > r9) {
        r12 = 0x0601DC10;
        r7 = r8;
        while (1) {
            r0 = GCALL4(r12, r11, r10, r9, r7);
            if (!(r0 >= r13)) {
                break;
            } else {
                r8 = r8 - 1;
                r7 = r8;
                if (r8 > r9) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601F0F0(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r8, r9, r10, r11, r12, r13, r14;

    r9 = r4;
    r1 = LD32(r9);
    r14 = r5;
    if (!((r1 & r1) == 0)) {
        r1 = LD16((r9 + 46));
        r3 = 0;
        r2 = r1 & 0xFFFF;
        if (!(0 >= r2)) {
            r3 = r2;
        }
        r1 = LD16((r9 + 44));
        r11 = 0;
        r6 = r1 & 0xFFFF;
        if (!(0 >= r6)) {
            r11 = r6;
        }
        r1 = LD16((r9 + 48));
        r12 = r6 + (r1 & 0xFFFF);
        r1 = LD16((r9 + 38));
        r1 = r1 & 0xFFFF;
        if (r12 > r1) {
            r12 = r1;
        }
        r1 = LD16((r9 + 50));
        r10 = r2 + (r1 & 0xFFFF);
        r1 = LD16((r9 + 40));
        r1 = r1 & 0xFFFF;
        if (r10 > r1) {
            r10 = r1;
        }
        r8 = r3;
        r0 = r8;
        if (!(r8 >= r10)) {
            r13 = 0x0604B3F0;
            do {
                r1 = LD32(r9 + 4);
                r4 = LD32((r0 << 2) + r1);
                r0 = GCALL3(r13, (r4 + r11), r14, (r12 - r11));
                r8 = r8 + 1;
                r0 = r8;
            } while (AGAIN(!(r8 >= r10)));
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601F198(int r4, int r5, int r6)
{
    int r0, r1, r8, r9, r10, r11;

    r10 = r6;
    r8 = r4;
    r9 = (short)r5;
    if (!((r8 & r8) == 0)) {
        r11 = 0x0604B3F0;
        do {
            r1 = LD32(r8 + 8);
            r4 = LD32(r8 + 4);
            r0 = GCALL3(r11, r4, r9, (r1 * r10));
            r8 = LD32(r8);
        } while (AGAIN(!((r8 & r8) == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601F1D0(int r4)
{
    int r0, r8, r9, r10, r11;

    r8 = r4;
    if (!((r8 & r8) == 0)) {
        r11 = 0;
        r10 = 0x06027F48;
        do {
            r4 = LD32(r8 + 4);
            ST32(r8 + 8, r11);
            r9 = LD32(r8);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(r10, r4);
            }
            ST32(r8 + 4, r11);
            r0 = GCALL1(r10, r8);
            r8 = r9;
        } while (AGAIN(!((r8 & r8) == 0)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F348(int r4)
{
    int r0, r1, r2, c1;

    r1 = LD32(r4 + 44);
    r0 = 0;
    if (!((r1 & r1) == 0)) {
        r0 = 1;
    } else {
        r2 = LD16((r4 + 48));
        r1 = LD16((r4 + 38));
        c1 = (r2 & 0xFFFF) == (r1 & 0xFFFF);
        r1 = r4;
        if (!(c1)) {
            r0 = 1;
        } else {
            r2 = LD16((r1 + 50));
            r1 = LD16((r4 + 40));
            if (!((r2 & 0xFFFF) == (r1 & 0xFFFF))) {
                r0 = 1;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F380(int r4)
{
    int r1;

    r1 = LD16((r4 + 16));
    return (r1 & 0xFFFF) == 10;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F38C(int r4)
{
    int r1, r2;

    r2 = LD16((r4 + 40));
    r1 = LD16((r4 + 38));
    return (r2 & 0xFFFF) * (r1 & 0xFFFF);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F3D0(int r4, int r5, int r6)
{
    int r1, r2;

    r5 = r5 & 0xFFFF;
    r2 = r4 + 30;
    r1 = LD16(r2);
    r1 = r1 & 0xFFFF;
    r6 = r6 & 255;
    if ((unsigned)r1 >= (unsigned)r5) {
        return 0;
    } else {
        ST8(((r1 + r4) + 18), r6);
        r1 = LD16(r2);
        r1 = r1 + 1;
        ST16(r2, r1);
        return (r1 & 0xFFFF) == r5;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601F3F8(int r4, int r5)
{
    ST32(r4, r5);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601F3FC(int r4, int r5)
{
    ST16((r4 + 16), r5);
    ST16((r4 + 30), 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F40C(int r4, int r5)
{
    int r0, r8, r10;

    r8 = r4;
    r10 = r5;
    r0 = GCALL3(0x0604B3F0, r4, 0, 0x348);
    ST32(r8 + 12, 0);
    ST32(r8 + 16, 0);
    ST32(r8 + 20, 0);
    ST32(r8 + 32, 0);
    ST32(r8 + 28, 0);
    ST16(0x346 + r8, -1);
    r0 = GCALL3(0x0604B3F0, r10, 0, 0x32C);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06010F3C(int r4, int r5)
{
    int r0, r1, r2, r3, c1, c3, c4, c5, c6;

    c1 = r5 > 0;
    if (!((r4 & r4) == 0)) {
        r3 = 31;
        if (c1) {
            r2 = 32;
            do {
                r1 = LD8(r4);
                r0 = r1 & 255;
                c3 = r0 > r3;
                if ((r0 & r0) == 0) {
                    ST8(r4, r2);
                } else {
                    c4 = r0 == 10;
                    if (!(c3)) {
                        c5 = r0 == 13;
                        if (!(c4)) {
                            c6 = r0 == 9;
                            if (!(c5)) {
                                if (!(c6)) {
                                    ST8(r4, r2);
                                }
                            }
                        }
                    }
                }
                r5 = r5 - 1;
                r4 = r4 + 1;
            } while (AGAIN(r5 > 0));
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06011410(int r4)
{
    int r0, r1, r2, r5, r9, r10, c3, c5, c7, c10, c13, c16, c17;

    r10 = r4;
    r9 = r10 + 24;
    r2 = LD16(r9);
    r1 = r10;
    if (r2 > 0x1DF) {
        ST16(r9, 0x1E0);
        r2 = LD32(r10 + 20);
        ST8(0x1E0 + r2, 0);
        r1 = r10;
    }
    r1 = LD8((r1 + 28));
    r2 = r1 & 255;
    r0 = r2;
    r1 = 22;
    if (r0 == 22) {
        r1 = LD16(r9);
        r1 = r1 - 1;
        ST16(r9, r1);
        c16 = ((short)r1) >= 0;
        r1 = 0;
        if (!(c16)) {
            ST16(r9, r1);
        }
        r2 = r10;
    } else {
        c3 = r0 == 7;
        if (r2 > r1) {
            r1 = 27;
            if (r0 == 27) {
                r2 = LD32(r10 + 20);
                ST8(r2, 0);
                ST16(r9, 0);
                ST16((r10 + 26), 0);
                r2 = r10;
            } else {
                c10 = r0 == 23;
                if (r2 > r1) {
                    if (r2 == 128) {
                        r1 = LD32(0x06089B00);
                        r2 = r10;
                        if (r1 >= 0) {
                            r2 = 0x0608B97C;
                            r1 = LD32(0x0608B97C);
                            if (!((r1 & r1) == 0)) {
                                ST32(r2, 0);
                                r2 = LD32(0x0608AB68);
                                r1 = 19;
                            } else {
                                r0 = GCALL1(0x0602CC0C, 1);
                                r2 = LD32(0x0608AB68);
                                r1 = 119;
                            }
                            ST16(r2, r1);
                            ST32(0x060766C0, -4);
                            r0 = GCALL1(0x06032164, 11);
                            r2 = r10;
                        }
                    } else {
                        if (r2 == 141) {
                            r1 = 0x0602F6CC;
                            r5 = 1;
                            r0 = GCALL2(r1, r10, r5);
                            r2 = r10;
                        } else {
                            r0 = GCALL1(0x060111D8, r10);
                            r2 = r10;
                        }
                    }
                } else {
                    if (c10) {
                        r2 = LD16(r9);
                        r1 = LD32(r10 + 20);
                        r0 = r2;
                        r1 = LD8(r0 + r1);
                        c17 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c17)) {
                            ST16(r9, (r1 + 1));
                        }
                    } else {
                        r0 = GCALL1(0x060111D8, r10);
                    }
                    r2 = r10;
                }
            }
        } else {
            r1 = 7;
            if (c3) {
                r1 = LD32(0x06089B00);
                r2 = r10;
                if (r1 >= 0) {
                    r2 = 0x0608B97C;
                    r1 = LD32(0x0608B97C);
                    if (!((r1 & r1) == 0)) {
                        ST32(r2, 0);
                        r2 = LD32(0x0608AB68);
                        r1 = 19;
                    } else {
                        r0 = GCALL1(0x0602CC0C, 1);
                        r2 = LD32(0x0608AB68);
                        r1 = 119;
                    }
                    ST16(r2, r1);
                    ST32(0x060766C0, -4);
                    r0 = GCALL1(0x06032164, 11);
                    r2 = r10;
                }
            } else {
                c5 = r0 == 4;
                if (r2 > r1) {
                    c7 = r0 == 13;
                    if (r0 == 8) {
                        r1 = 0x0602F6CC;
                        r5 = 0;
                        r0 = GCALL2(r1, r10, r5);
                        r2 = r10;
                    } else {
                        if (c7) {
                            r1 = LD32(r10 + 20);
                            r1 = LD8(r1);
                            c13 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = -25;
                            if (c13) {
                                r2 = r10;
                            } else {
                                ST32(0x060766C0, r1);
                                r0 = GCALL1(0x0602BA00, 0x06011400);
                                r2 = r10;
                            }
                        } else {
                            r0 = GCALL1(0x060111D8, r10);
                            r2 = r10;
                        }
                    }
                } else {
                    if (c5) {
                        r4 = LD32(r10 + 20);
                        r0 = GCALL2(0x060750DC, r4, 0x06079D00);
                        r0 = GCALL1(0x0607507C, 0x06079D00);
                        ST16(r9, r0);
                    } else {
                        r0 = GCALL1(0x060111D8, r10);
                    }
                    r2 = r10;
                }
            }
        }
    }
    ST8((r2 + 28), 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060172E0(int r4)
{
    int r0, r1, r2, r7, r8, r10, r11, c4, c5;

    r11 = r4 & 255;
    r10 = (r11 * 112) + 0x06089DD0;
    r8 = r10 + 72;
    r0 = GCALL3(0x0604B358, (r10 + 92), r8, 20);
    r0 = GCALL3(0x0604B358, r8, 0x0608AB38, 20);
    r2 = LD8((r10 + 51));
    r0 = r2 & 255;
    r1 = 112;
    if (r0 == 2) {
        r2 = (r11 * r1) + 0x06089DD0;
        r1 = LD8((r2 + 52));
        r0 = (~r1) & 255;
        r1 = LD8((r2 + 53));
        r7 = (~r1) & 255;
        ST8((r2 + 72), (4 & r0));
        ST8((r2 + 73), (1 & r0));
        ST8((r2 + 74), (2 & r0));
        ST8((r2 + 78), (8 & r0));
        ST8((r2 + 75), (64 & r7));
        ST8((r2 + 76), (32 & r7));
        ST8((r2 + 77), (16 & r7));
        ST8((r2 + 79), (16 & r0));
        ST8((r2 + 80), (32 & r0));
        ST8((r2 + 81), (64 & r0));
        ST8((r2 + 82), (r0 & 128));
        ST8((r2 + 83), (8 & r7));
        r2 = r2 + 84;
        r0 = r7 & 128;
        ST8(r2, r0);
    } else {
        r1 = r2;
        if (r0 == 225) {
            r1 = 112;
            r2 = (r11 * r1) + 0x06089DD0;
            r1 = LD8((r2 + 52));
            r0 = (~r1) & 255;
            r1 = LD8((r2 + 53));
            r7 = (~r1) & 255;
            ST8((r2 + 72), (4 & r0));
            ST8((r2 + 73), (1 & r0));
            ST8((r2 + 74), (2 & r0));
            ST8((r2 + 78), (8 & r0));
            ST8((r2 + 75), (64 & r7));
            ST8((r2 + 76), (32 & r7));
            ST8((r2 + 77), (16 & r7));
            ST8((r2 + 79), (16 & r0));
            ST8((r2 + 80), (32 & r0));
            ST8((r2 + 81), (64 & r0));
            ST8((r2 + 82), (r0 & 128));
            ST8((r2 + 83), (8 & r7));
            r2 = r2 + 84;
            r0 = r7 & 128;
            ST8(r2, r0);
        } else {
            c4 = r0 == 19;
            if (!((unsigned)((r1 - 21) & 255) > (unsigned)1)) {
                r1 = 112;
                r2 = (r11 * r1) + 0x06089DD0;
                r1 = LD8((r2 + 52));
                r0 = (~r1) & 255;
                r1 = LD8((r2 + 53));
                r7 = (~r1) & 255;
                ST8((r2 + 72), (4 & r0));
                ST8((r2 + 73), (1 & r0));
                ST8((r2 + 74), (2 & r0));
                ST8((r2 + 78), (8 & r0));
                ST8((r2 + 75), (64 & r7));
                ST8((r2 + 76), (32 & r7));
                ST8((r2 + 77), (16 & r7));
                ST8((r2 + 79), (16 & r0));
                ST8((r2 + 80), (32 & r0));
                ST8((r2 + 81), (64 & r0));
                ST8((r2 + 82), (r0 & 128));
                ST8((r2 + 83), (8 & r7));
                r2 = r2 + 84;
                r0 = r7 & 128;
                ST8(r2, r0);
            } else {
                c5 = r0 == 52;
                if (c4) {
                    r1 = 112;
                    r2 = (r11 * r1) + 0x06089DD0;
                    r1 = LD8((r2 + 52));
                    r0 = (~r1) & 255;
                    r1 = LD8((r2 + 53));
                    r7 = (~r1) & 255;
                    ST8((r2 + 72), (4 & r0));
                    ST8((r2 + 73), (1 & r0));
                    ST8((r2 + 74), (2 & r0));
                    ST8((r2 + 78), (8 & r0));
                    ST8((r2 + 75), (64 & r7));
                    ST8((r2 + 76), (32 & r7));
                    ST8((r2 + 77), (16 & r7));
                    ST8((r2 + 79), (16 & r0));
                    ST8((r2 + 80), (32 & r0));
                    ST8((r2 + 81), (64 & r0));
                    ST8((r2 + 82), (r0 & 128));
                    ST8((r2 + 83), (8 & r7));
                    r2 = r2 + 84;
                    r0 = r7 & 128;
                    ST8(r2, r0);
                } else {
                    r1 = 112;
                    if (c5) {
                        r2 = (r11 * r1) + 0x06089DD0;
                        r1 = LD8((r2 + 52));
                        r0 = (~r1) & 255;
                        r1 = LD8((r2 + 53));
                        r7 = (~r1) & 255;
                        ST8((r2 + 72), (4 & r0));
                        ST8((r2 + 73), (1 & r0));
                        ST8((r2 + 74), (2 & r0));
                        ST8((r2 + 78), (8 & r0));
                        ST8((r2 + 75), (64 & r7));
                        ST8((r2 + 76), (32 & r7));
                        ST8((r2 + 77), (16 & r7));
                        ST8((r2 + 79), (16 & r0));
                        ST8((r2 + 80), (32 & r0));
                        ST8((r2 + 81), (64 & r0));
                        ST8((r2 + 82), (r0 & 128));
                        ST8((r2 + 83), (8 & r7));
                        r2 = r2 + 84;
                        r0 = r7 & 128;
                        ST8(r2, r0);
                    } else {
                        if (!(r0 == 226)) {
                            r2 = r10;
                            if (r0 == 227) {
                                r1 = r10 + 52;
                                r0 = LD8(r1);
                                ST8((r2 + 89), (r0 & 1));
                                r0 = LD8(r1);
                                ST8((r10 + 90), (r0 & 2));
                                r0 = LD8(r1);
                                ST8((r10 + 91), (r0 & 4));
                                r0 = LD8(r1);
                                r2 = r10 + 78;
                                r0 = r0 & 8;
                                ST8(r2, r0);
                            }
                        } else {
                            r1 = 112;
                            r2 = (r11 * r1) + 0x06089DD0;
                            r1 = LD8((r2 + 52));
                            r0 = (~r1) & 255;
                            r1 = LD8((r2 + 53));
                            r7 = (~r1) & 255;
                            ST8((r2 + 72), (4 & r0));
                            ST8((r2 + 73), (1 & r0));
                            ST8((r2 + 74), (2 & r0));
                            ST8((r2 + 78), (8 & r0));
                            ST8((r2 + 75), (64 & r7));
                            ST8((r2 + 76), (32 & r7));
                            ST8((r2 + 77), (16 & r7));
                            ST8((r2 + 79), (16 & r0));
                            ST8((r2 + 80), (32 & r0));
                            ST8((r2 + 81), (64 & r0));
                            ST8((r2 + 82), (r0 & 128));
                            ST8((r2 + 83), (8 & r7));
                            r2 = r2 + 84;
                            r0 = r7 & 128;
                            ST8(r2, r0);
                        }
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06017534(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, c8, c10, c11, c14, c23, c24, c27;

    r10 = r5;
    r12 = LD8(0x10D8 + r4);
    r8 = r6;
    r1 = LD32(0x10D4 + r4);
    r11 = 0;
    if ((r1 & r1) == 0) {
        r2 = LD8(r8);
        r0 = r2 & 255;
        if (!(((r2 & 255) & (r2 & 255)) == 0)) {
            r3 = 0x06075135;
            while (1) {
                r0 = LD8(r0 + r3);
                if (((r0 & 8) & (r0 & 8)) == 0) {
                    break;
                } else {
                    r8 = r8 + 1;
                    r2 = LD8(r8);
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
        r1 = LD8(r8);
        r1 = r1 & 255;
        r2 = r1;
        if (!((r1 & r1) == 0)) {
            r1 = 0x06075135;
            r3 = LD8(r2 + 0x06075135);
            r8 = r8 + 1;
            if (((r3 & 8) & (r3 & 8)) == 0) {
                r3 = r1;
                while (1) {
                    r1 = LD8(r2 + r3);
                    r0 = r2;
                    if (!(((r1 & 7) & (r1 & 7)) == 0)) {
                        r11 = r11 + 1;
                        if (r0 == 62) {
                            break;
                        } else {
                            if (r11 > 18) {
                                break;
                            } else {
                                r1 = LD8(r0 + r3);
                                c27 = ((r1 & 1) & (r1 & 1)) == 0;
                                r1 = r2;
                                if (!(c27)) {
                                    r2 = (r1 + 32) & 255;
                                }
                                ST8(r10, r2);
                                r1 = LD8(r8);
                                r1 = r1 & 255;
                                r10 = r10 + 1;
                                if ((r1 & r1) == 0) {
                                    break;
                                } else {
                                    r2 = r1;
                                    r1 = LD8(r2 + r3);
                                    r8 = r8 + 1;
                                    if (((r1 & 8) & (r1 & 8)) == 0) {
                                        POLL();
                                        continue;
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                    } else {
                        c23 = r0 == 33;
                        if (r0 == 47) {
                            r11 = r11 + 1;
                            if (r0 == 62) {
                                break;
                            } else {
                                if (r11 > 18) {
                                    break;
                                } else {
                                    r1 = LD8(r0 + r3);
                                    c27 = ((r1 & 1) & (r1 & 1)) == 0;
                                    r1 = r2;
                                    if (!(c27)) {
                                        r2 = (r1 + 32) & 255;
                                    }
                                    ST8(r10, r2);
                                    r1 = LD8(r8);
                                    r1 = r1 & 255;
                                    r10 = r10 + 1;
                                    if ((r1 & r1) == 0) {
                                        break;
                                    } else {
                                        r2 = r1;
                                        r1 = LD8(r2 + r3);
                                        r8 = r8 + 1;
                                        if (((r1 & 8) & (r1 & 8)) == 0) {
                                            POLL();
                                            continue;
                                        } else {
                                            break;
                                        }
                                    }
                                }
                            }
                        } else {
                            c24 = r0 == 45;
                            if (c23) {
                                r11 = r11 + 1;
                                if (r0 == 62) {
                                    break;
                                } else {
                                    if (r11 > 18) {
                                        break;
                                    } else {
                                        r1 = LD8(r0 + r3);
                                        c27 = ((r1 & 1) & (r1 & 1)) == 0;
                                        r1 = r2;
                                        if (!(c27)) {
                                            r2 = (r1 + 32) & 255;
                                        }
                                        ST8(r10, r2);
                                        r1 = LD8(r8);
                                        r1 = r1 & 255;
                                        r10 = r10 + 1;
                                        if ((r1 & r1) == 0) {
                                            break;
                                        } else {
                                            r2 = r1;
                                            r1 = LD8(r2 + r3);
                                            r8 = r8 + 1;
                                            if (((r1 & 8) & (r1 & 8)) == 0) {
                                                POLL();
                                                continue;
                                            } else {
                                                break;
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (!(c24)) {
                                    break;
                                } else {
                                    r11 = r11 + 1;
                                    if (r0 == 62) {
                                        break;
                                    } else {
                                        if (r11 > 18) {
                                            break;
                                        } else {
                                            r1 = LD8(r0 + r3);
                                            c27 = ((r1 & 1) & (r1 & 1)) == 0;
                                            r1 = r2;
                                            if (!(c27)) {
                                                r2 = (r1 + 32) & 255;
                                            }
                                            ST8(r10, r2);
                                            r1 = LD8(r8);
                                            r1 = r1 & 255;
                                            r10 = r10 + 1;
                                            if ((r1 & r1) == 0) {
                                                break;
                                            } else {
                                                r2 = r1;
                                                r1 = LD8(r2 + r3);
                                                r8 = r8 + 1;
                                                if (((r1 & 8) & (r1 & 8)) == 0) {
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
                    POLL();
                }
            }
            r8 = r8 - 1;
            r1 = 0;
            ST8(r10, r1);
            r0 = r8;
        } else {
            r0 = 0;
        }
    } else {
        r1 = LD8(r8);
        r5 = r12;
        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
            r13 = 0x06045760;
            while (1) {
                r0 = GCALL2(r13, r8, r5);
                r4 = r0 & 0xFFFF;
                r9 = 2;
                if (((int)((unsigned)r4 >> 8)) == 128) {
                    r9 = 1;
                }
                r0 = GCALL1(0x060455C4, r4);
                if ((r0 & r0) == 0) {
                    break;
                } else {
                    r8 = r8 + r9;
                    r1 = LD8(r8);
                    r5 = r12;
                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
        }
        r1 = LD8(r8);
        r0 = 0;
        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
            r13 = 0x06075135;
            while (1) {
                r0 = GCALL2(0x06045760, r8, r12);
                r4 = r0 & 0xFFFF;
                r2 = r4 & 255;
                if (((int)((unsigned)r4 >> 8)) == 128) {
                    r9 = 1;
                    r3 = LD8(r2 + r13);
                    r0 = r3;
                    if (!(((8 & r3) & (8 & r3)) == 0)) {
                        r1 = 0;
                        break;
                    } else {
                        c8 = ((r0 & 7) & (r0 & 7)) == 0;
                        r0 = r2;
                        if (!(c8)) {
                            r11 = r11 + 1;
                            if (r0 == 62) {
                                r1 = 0;
                                break;
                            } else {
                                if (r11 > 18) {
                                    r1 = 0;
                                    break;
                                } else {
                                    r1 = LD8(r0 + r13);
                                    c14 = ((r1 & 1) & (r1 & 1)) == 0;
                                    r1 = r2;
                                    if (!(c14)) {
                                        r2 = (r1 + 32) & 255;
                                    }
                                    ST8(r10, r2);
                                    r8 = r8 + r9;
                                    r1 = LD8(r8);
                                    r10 = r10 + 1;
                                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                        POLL();
                                        continue;
                                    } else {
                                        r1 = 0;
                                        break;
                                    }
                                }
                            }
                        } else {
                            c10 = r0 == 33;
                            if (r0 == 47) {
                                r11 = r11 + 1;
                                if (r0 == 62) {
                                    r1 = 0;
                                    break;
                                } else {
                                    if (r11 > 18) {
                                        r1 = 0;
                                        break;
                                    } else {
                                        r1 = LD8(r0 + r13);
                                        c14 = ((r1 & 1) & (r1 & 1)) == 0;
                                        r1 = r2;
                                        if (!(c14)) {
                                            r2 = (r1 + 32) & 255;
                                        }
                                        ST8(r10, r2);
                                        r8 = r8 + r9;
                                        r1 = LD8(r8);
                                        r10 = r10 + 1;
                                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                            POLL();
                                            continue;
                                        } else {
                                            r1 = 0;
                                            break;
                                        }
                                    }
                                }
                            } else {
                                c11 = r0 == 45;
                                if (c10) {
                                    r11 = r11 + 1;
                                    if (r0 == 62) {
                                        r1 = 0;
                                        break;
                                    } else {
                                        if (r11 > 18) {
                                            r1 = 0;
                                            break;
                                        } else {
                                            r1 = LD8(r0 + r13);
                                            c14 = ((r1 & 1) & (r1 & 1)) == 0;
                                            r1 = r2;
                                            if (!(c14)) {
                                                r2 = (r1 + 32) & 255;
                                            }
                                            ST8(r10, r2);
                                            r8 = r8 + r9;
                                            r1 = LD8(r8);
                                            r10 = r10 + 1;
                                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                POLL();
                                                continue;
                                            } else {
                                                r1 = 0;
                                                break;
                                            }
                                        }
                                    }
                                } else {
                                    r1 = 0;
                                    if (!(c11)) {
                                        break;
                                    } else {
                                        r0 = r2;
                                        r11 = r11 + 1;
                                        if (r0 == 62) {
                                            r1 = 0;
                                            break;
                                        } else {
                                            if (r11 > 18) {
                                                r1 = 0;
                                                break;
                                            } else {
                                                r1 = LD8(r0 + r13);
                                                c14 = ((r1 & 1) & (r1 & 1)) == 0;
                                                r1 = r2;
                                                if (!(c14)) {
                                                    r2 = (r1 + 32) & 255;
                                                }
                                                ST8(r10, r2);
                                                r8 = r8 + r9;
                                                r1 = LD8(r8);
                                                r10 = r10 + 1;
                                                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                    POLL();
                                                    continue;
                                                } else {
                                                    r1 = 0;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    r1 = 0;
                    break;
                }
                POLL();
            }
            ST8(r10, r1);
            r0 = r8;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060176CC(int r4)
{
    int r0, r1, r2, r3, c0, c1, c3;

    r2 = r4;
    r1 = LD8(r2);
    r3 = 0;
    while (1) {
        r0 = r1 & 255;
        c3 = (r3 & r3) == 0;
        if (!((r0 & r0) == 0)) {
            POLL();
            c0 = r0 == 34;
            if (!(c3)) {
                if (c0) {
                    r3 = 0;
                }
                r2 = r2 + 1;
                r1 = LD8(r2);
                continue;
            } else {
                c1 = r0 == 62;
                if (c0) {
                    r2 = r2 + 1;
                    r1 = LD8(r2);
                    continue;
                } else {
                    if (!(c1)) {
                        r2 = r2 + 1;
                        r1 = LD8(r2);
                        continue;
                    } else {
                        return r2 + 1;
                    }
                }
            }
        } else {
            return r2;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06018AFC(int r4, int r5, int r6)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14, c2, c6, c8, c9, c14, c15, c18, c20, c22;
    int v36;

    r12 = LD32(0x10D4 + r4);
    r11 = r5;
    r0 = LD8(0x10D8 + r4);
    r13 = r6;
    v36 = r0;
    r1 = LD8(r11);
    r14 = 0;
    while (1) {
        r8 = r1 & 255;
        c22 = (r12 & r12) == 0;
        if ((r8 & r8) == 0) {
            r1 = 0;
            break;
        } else {
            POLL();
            r5 = v36;
            if (c22) {
                r9 = 0;
                r10 = 1;
            } else {
                r0 = GCALL5(0x06045760, r11, r5, 0, 0, v36);
                r9 = r0 & 0xFFFF;
                r8 = 0;
                if (!(((int)((unsigned)r9 >> 8)) == 128)) {
                    r10 = 2;
                } else {
                    r8 = r9 & 255;
                    r10 = 1;
                }
            }
            r0 = r8;
            c2 = (r12 & r12) == 0;
            if (!(r0 == 62)) {
                if (c2) {
                    r1 = LD8(r0 + 0x06075135);
                    r1 = r1 & 8;
                } else {
                    r0 = GCALL5(0x060455C4, r9, 0, 0, 0, v36);
                    r1 = r0;
                }
                if ((r1 & r1) == 0) {
                    r1 = LD8(r11);
                    while (1) {
                        r8 = r1 & 255;
                        c20 = (r12 & r12) == 0;
                        if ((r8 & r8) == 0) {
                            r1 = 0;
                            break;
                        } else {
                            POLL();
                            r5 = v36;
                            if (c20) {
                                r9 = 0;
                                r10 = 1;
                            } else {
                                r0 = GCALL5(0x06045760, r11, r5, 0, 0, v36);
                                r9 = r0 & 0xFFFF;
                                r8 = 0;
                                if (!(((int)((unsigned)r9 >> 8)) == 128)) {
                                    r10 = 2;
                                } else {
                                    r8 = r9 & 255;
                                    r10 = 1;
                                }
                            }
                            c6 = (r12 & r12) == 0;
                            if (!((unsigned)((r8 - 61) & 255) > (unsigned)1)) {
                                r1 = 0;
                                break;
                            } else {
                                r0 = r8;
                                if (c6) {
                                    r1 = LD8(r0 + 0x06075135);
                                    r1 = r1 & 8;
                                } else {
                                    r0 = GCALL5(0x060455C4, r9, 0, 0, 0, v36);
                                    r1 = r0;
                                }
                                c8 = (r12 & r12) == 0;
                                if (!((r1 & r1) == 0)) {
                                    r1 = 0;
                                    break;
                                } else {
                                    r1 = r9;
                                    if (c8) {
                                        r1 = LD8(r8 + 0x06075135);
                                        r2 = r8;
                                        if (!(((r1 & 1) & (r1 & 1)) == 0)) {
                                            r2 = r2 + 32;
                                        }
                                        ST8(r13, r2);
                                        r13 = r13 + 1;
                                        r14 = r14 + 1;
                                        r11 = r11 + r10;
                                        if (!(r14 > 30)) {
                                            r1 = LD8(r11);
                                            continue;
                                        } else {
                                            r1 = LD8(r11);
                                            while (1) {
                                                r8 = r1 & 255;
                                                c18 = (r12 & r12) == 0;
                                                if (!((r8 & r8) == 0)) {
                                                    POLL();
                                                    r5 = v36;
                                                    if (c18) {
                                                        r9 = 0;
                                                        r10 = 1;
                                                    } else {
                                                        r0 = GCALL5(0x06045760, r11, r5, 0, 0, v36);
                                                        r9 = r0 & 0xFFFF;
                                                        r8 = 0;
                                                        if (!(((int)((unsigned)r9 >> 8)) == 128)) {
                                                            r10 = 2;
                                                        } else {
                                                            r8 = r9 & 255;
                                                            r10 = 1;
                                                        }
                                                    }
                                                    c14 = (r12 & r12) == 0;
                                                    if (!((unsigned)((r8 - 61) & 255) > (unsigned)1)) {
                                                        r1 = 0;
                                                        break;
                                                    } else {
                                                        r0 = r8;
                                                        if (c14) {
                                                            r1 = LD8(r0 + 0x06075135);
                                                            r1 = r1 & 8;
                                                        } else {
                                                            r0 = GCALL5(0x060455C4, r9, 0, 0, 0, v36);
                                                            r1 = r0;
                                                        }
                                                        c15 = (r1 & r1) == 0;
                                                        r1 = r9;
                                                        if (!(c15)) {
                                                            r1 = 0;
                                                            break;
                                                        } else {
                                                            if (!(((int)((unsigned)r1 >> 8)) == 128)) {
                                                                r1 = 0;
                                                                break;
                                                            } else {
                                                                r11 = r11 + r10;
                                                                r1 = LD8(r11);
                                                                continue;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    r1 = 0;
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    } else {
                                        c9 = ((int)((unsigned)r1 >> 8)) == 128;
                                        r1 = 0;
                                        if (!(c9)) {
                                            break;
                                        } else {
                                            r1 = LD8(r8 + 0x06075135);
                                            r2 = r8;
                                            if (!(((r1 & 1) & (r1 & 1)) == 0)) {
                                                r2 = r2 + 32;
                                            }
                                            ST8(r13, r2);
                                            r13 = r13 + 1;
                                            r14 = r14 + 1;
                                            r11 = r11 + r10;
                                            if (!(r14 > 30)) {
                                                r1 = LD8(r11);
                                                continue;
                                            } else {
                                                r1 = LD8(r11);
                                                while (1) {
                                                    r8 = r1 & 255;
                                                    c18 = (r12 & r12) == 0;
                                                    if (!((r8 & r8) == 0)) {
                                                        POLL();
                                                        r5 = v36;
                                                        if (c18) {
                                                            r9 = 0;
                                                            r10 = 1;
                                                        } else {
                                                            r0 = GCALL5(0x06045760, r11, r5, 0, 0, v36);
                                                            r9 = r0 & 0xFFFF;
                                                            r8 = 0;
                                                            if (!(((int)((unsigned)r9 >> 8)) == 128)) {
                                                                r10 = 2;
                                                            } else {
                                                                r8 = r9 & 255;
                                                                r10 = 1;
                                                            }
                                                        }
                                                        c14 = (r12 & r12) == 0;
                                                        if (!((unsigned)((r8 - 61) & 255) > (unsigned)1)) {
                                                            r1 = 0;
                                                            break;
                                                        } else {
                                                            r0 = r8;
                                                            if (c14) {
                                                                r1 = LD8(r0 + 0x06075135);
                                                                r1 = r1 & 8;
                                                            } else {
                                                                r0 = GCALL5(0x060455C4, r9, 0, 0, 0, v36);
                                                                r1 = r0;
                                                            }
                                                            c15 = (r1 & r1) == 0;
                                                            r1 = r9;
                                                            if (!(c15)) {
                                                                r1 = 0;
                                                                break;
                                                            } else {
                                                                if (!(((int)((unsigned)r1 >> 8)) == 128)) {
                                                                    r1 = 0;
                                                                    break;
                                                                } else {
                                                                    r11 = r11 + r10;
                                                                    r1 = LD8(r11);
                                                                    continue;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r1 = 0;
                                                        break;
                                                    }
                                                }
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                } else {
                    r11 = r11 + r10;
                    r1 = LD8(r11);
                    continue;
                }
            } else {
                r1 = 0;
                break;
            }
        }
    }
    ST8(r13, r1);
    return r11;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CD5C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c3;
    FRAME(sp, 32);

    r12 = r5;
    r9 = r6;
    r8 = r7;
    r10 = 0;
    r2 = 0;
    r1 = LD32(0x10D4 + r4);
    r7 = 0;
    r13 = LD32(sp);
    if ((r1 & r1) == 0) {
        r0 = GCALL4(0x0601CC78, r12, 128, 0, r7);
        r2 = LD32(r0 + 8);
        if (((r12 & 4) & (r12 & 4)) == 0) {
            r3 = r8;
            if (!(r3 > r13)) {
                while (1) {
                    r1 = LD8(r9 + r3);
                    r1 = r1 & 255;
                    r0 = r2;
                    if ((r1 & r1) == 0) {
                        break;
                    } else {
                        r1 = LD8(r0 + r1);
                        r3 = r3 + 1;
                        r10 = r10 + (r1 & 255);
                        if (!(r3 > r13)) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    }
                    POLL();
                }
            }
            r10 = r10 + 3;
            r0 = (r10 >> 1) >> 1;
        } else {
            r2 = LD8((r2 + 77));
            r0 = ((((r2 & 255) * ((r13 - r8) + 1)) + 3) >> 1) >> 1;
        }
    } else {
        r3 = r8;
        r11 = r9;
        if (r3 > r13) {
            r10 = r10 + 3;
        } else {
            r14 = 0x0601CC78;
            r9 = r3 + r3;
            r0 = r9;
            while (1) {
                r1 = LD8(r0 + r11);
                r8 = r1 & 255;
                c3 = r7 == r8;
                if ((r8 & r8) == 0) {
                    r10 = r10 + 3;
                    break;
                } else {
                    r6 = 0;
                    if (!(c3)) {
                        r0 = GCALL4(r14, r12, r8, r6, r7);
                        r3 = r0;
                        ST8((r3 + 6), 0);
                        r2 = LD32(r3 + 8);
                        r7 = r8;
                    }
                    r1 = LD16(r9 + r11);
                    r1 = LD8(r2 + (r1 & 255));
                    r9 = r9 + 2;
                    r10 = r10 + (r1 & 255);
                    r0 = r9;
                    if (!(r9 > (r13 + r13))) {
                        POLL();
                        continue;
                    } else {
                        r10 = r10 + 3;
                        break;
                    }
                }
                POLL();
            }
        }
        r0 = (r10 >> 1) >> 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D034(int r4)
{
    int r0, r1, r2, r3, r7, r8, c3;

    r1 = LD32(0x10D4 + r4);
    r8 = r4;
    if ((r1 & r1) == 0) {
        r8 = r8 + 0x1B0;
        r0 = GCALL1(0x0607507C, r8);
        r2 = r0 - 2;
        r0 = 0;
        if (r2 >= 0) {
            r0 = r8;
            while (1) {
                r1 = LD8(r0 + r2);
                r2 = r2 - 1;
                if ((r1 & 255) == 1) {
                    POLL();
                    r0 = 1;
                    break;
                } else {
                    r0 = r8;
                    if (r2 >= 0) {
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
        r8 = r8 + 0x1B0;
        r0 = GCALL1(0x060455FC, r8);
        r2 = r0 - 2;
        r0 = 0;
        if (r2 >= 0) {
            r7 = 128;
            r2 = r2 + r2;
            r0 = r2;
            while (1) {
                r3 = LD16(r0 + r8);
                r0 = r3 & 255;
                if (!(((int)((unsigned)(r3 & 0xFFFF) >> 8)) == r7)) {
                    r2 = r2 - 2;
                    r0 = r2;
                    if (r2 >= 0) {
                        POLL();
                        continue;
                    } else {
                        r0 = 0;
                        break;
                    }
                } else {
                    c3 = r0 == 1;
                    r0 = c3;
                    if (c3) {
                        break;
                    } else {
                        r2 = r2 - 2;
                        r0 = r2;
                        if (r2 >= 0) {
                            POLL();
                            continue;
                        } else {
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
void f0601D408(int r4)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, c7, c9;

    r10 = r4;
    r4 = LD32((r10 + 80));
    r1 = LD32((r10 + 64));
    r9 = 0;
    r12 = (short)r1;
    r1 = LD32((r10 + 68));
    r11 = (short)r1;
    if (!((r4 & r4) == 0)) {
        r13 = 0x06027F48;
        do {
            ST32(r4 + 16, r9);
            r12 = LD16((r4 + 4));
            r2 = LD32(r4);
            r11 = LD16((r4 + 6));
            r1 = LD32(r10 + 12);
            if (!(r1 > r2)) {
                r9 = r4;
                r4 = LD32(r4 + 12);
            } else {
                if (r2 == 0x7FFFFFFF) {
                    r9 = r4;
                    r4 = LD32(r4 + 12);
                } else {
                    r8 = LD32(r4 + 12);
                    r0 = GCALL1(r13, r4);
                    r4 = r8;
                    if ((r9 & r9) == 0) {
                        ST32((r10 + 80), r4);
                    } else {
                        ST32(r9 + 12, r4);
                    }
                }
            }
        } while (AGAIN(!((r4 & r4) == 0)));
    }
    r4 = r9;
    r2 = r12;
    r3 = r11;
    if (!((r4 & r4) == 0)) {
        r1 = r4;
        do {
            ST16((r1 + 4), r2);
            ST16((r4 + 6), r3);
            r1 = LD16((r4 + 8));
            c7 = r1 >= r2;
            if (r1 >= 0) {
                if (c7) {
                    r2 = r1;
                }
            }
            r1 = LD16((r4 + 10));
            c9 = r1 > r3;
            if (r1 >= 0) {
                if (!(c9)) {
                    r3 = r1;
                }
            }
            r4 = LD32(r4 + 16);
            r1 = r4;
        } while (AGAIN(!((r4 & r4) == 0)));
    }
    r1 = r10 + 64;
    ST32(r1, r2);
    ST32((r10 + 68), r3);
    r1 = LD32(r1);
    ST32(r10 + 8, r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F3B0(int r4)
{
    int r0, c0;

    r0 = GCALL2(0x06075104, r4, 0x0601F3AC);
    c0 = r0 >= 0;
    r0 = 0;
    if (c0) {
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F450(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, c2, c4;
    FRAME(sp, 28);

    r10 = r4;
    r8 = r5;
    r13 = r7;
    r9 = r6 & 0xFFFF;
    r1 = LD32(sp);
    r11 = r1 & 0xFFFF;
    r0 = GCALL1(0x0601F38C, r4);
    r1 = LD32(r8 + 32);
    r12 = r9;
    if (!(r1 >= r0)) {
        c2 = r9 == r11;
        if (r1 >= 0) {
            r2 = (short)r12;
            if (!(c2)) {
                r0 = 0x346;
                r1 = LD16(0x346 + r10);
                if (!(r2 == r1)) {
                    r7 = LD32(r8 + 48);
                    r2 = LD32(r10 + 4);
                    r3 = LD32((r7 << 2) + r2);
                    r2 = LD32(r8 + 44);
                    r1 = LD8(((((1 & r2) | (r7 & 2)) << 8) + r13) + r12);
                    r0 = r3;
                    ST8(r0 + r2, r1);
                }
            } else {
                r1 = LD32(r8 + 48);
                r2 = LD32(r10 + 4);
                r3 = LD32((r1 << 2) + r2);
                r2 = LD32(r8 + 44);
                r1 = LD16((r8 + 26));
                r0 = r3;
                ST8(r0 + r2, r1);
            }
            r1 = LD32(r8 + 32);
            r2 = LD32(r8 + 44);
            ST32(r8 + 32, (r1 + 1));
            r2 = r2 + 1;
            ST32(r8 + 44, r2);
            r1 = LD16((r10 + 48));
            c4 = r2 >= (r1 & 0xFFFF);
            r1 = 0;
            if (c4) {
                ST32(r8 + 44, r1);
                r1 = LD32(r8 + 48);
                ST32(r8 + 48, (r1 + 1));
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F4F8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c5, c6, c10;
    FRAME(sp, 44);

    r10 = r4;
    r8 = r5;
    r12 = r6;
    r1 = LD32(sp);
    ST32(sp - 44, r7);
    ST32(sp - 40, (r1 & 0xFFFF));
    r14 = LD16((((r12 + r12) + r8) + 52));
    r1 = LD32(r8 + 44);
    r2 = r10 + 48;
    r0 = LD32(r8 + 48);
    r13 = r1 + r14;
    ST32(sp - 36, r0);
    ST32(r8 + 44, (r13 - 1));
    r1 = LD16(r2);
    r3 = r10;
    if (r13 >= (r1 & 0xFFFF)) {
        do {
            r1 = LD16(r2);
            r0 = LD32(sp - 36);
            r1 = r1 & 0xFFFF;
            r13 = r13 - r1;
            ST32(sp - 36, (r0 + 1));
        } while (AGAIN(r13 >= r1));
        r3 = r10;
    }
    r3 = r3 + 48;
    while (1) {
        r1 = LD16(r3);
        r2 = LD32(r8 + 44);
        r11 = 1;
        if (r2 >= (r1 & 0xFFFF)) {
            POLL();
            r1 = LD16(r3);
            ST32(r8 + 44, (r2 - (r1 & 0xFFFF)));
            r1 = LD32(r8 + 48);
            ST32(r8 + 48, (r1 + 1));
            continue;
        } else {
            break;
        }
    }
    if (!(r11 >= r14)) {
        do {
            r1 = LD32(r8 + 32);
            r9 = (r1 + r14) - r11;
            r0 = GCALL7(0x0601F38C, r10, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
            c5 = r9 >= 0;
            if (r9 >= r0) {
                r1 = r12;
            } else {
                r1 = r12;
                if (c5) {
                    r6 = LD8((r8 + r12) + 0x4034);
                    r2 = r6 & 255;
                    r0 = LD32(sp - 40);
                    c6 = (r2 & 0xFFFF) == r0;
                    r2 = (short)r2;
                    if (!(c6)) {
                        r1 = LD16(0x346 + r10);
                        if (!(r2 == r1)) {
                            r2 = LD32(r8 + 48);
                            r1 = LD32(r10 + 4);
                            r3 = LD32((r2 << 2) + r1);
                            r7 = LD32(r8 + 44);
                            r0 = LD32(sp - 44);
                            r1 = LD8(((((1 & r7) | (r2 & 2)) << 8) + r0) + (r6 & 255));
                            ST8(r3 + r7, r1);
                        }
                    } else {
                        r1 = LD32(r8 + 48);
                        r2 = LD32(r10 + 4);
                        r0 = LD32((r1 << 2) + r2);
                        r1 = LD16((r8 + 26));
                        r2 = LD32(r8 + 44);
                        ST8(r0 + r2, r1);
                    }
                    r1 = r12;
                }
            }
            r12 = LD16(((r1 + r1) + r8) + 0x2034);
            r1 = LD32(r8 + 44);
            r1 = r1 - 1;
            ST32(r8 + 44, r1);
            if (!(r1 >= 0)) {
                r1 = LD16((r10 + 48));
                ST32(r8 + 44, ((r1 & 0xFFFF) - 1));
                r1 = LD32(r8 + 48);
                ST32(r8 + 48, (r1 - 1));
            }
            r11 = r11 + 1;
        } while (AGAIN(!(r11 >= r14)));
    }
    r0 = GCALL7(0x0601F38C, r10, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
    r1 = LD32(r8 + 32);
    c10 = r1 >= r0;
    r0 = LD32(sp - 40);
    if (!(c10)) {
        r2 = (short)r12;
        if (!(r12 == r0)) {
            r1 = LD16(0x346 + r10);
            if (!(r2 == r1)) {
                r7 = LD32(r8 + 48);
                r2 = LD32(r10 + 4);
                r3 = LD32((r7 << 2) + r2);
                r2 = LD32(r8 + 44);
                r7 = r7 & 2;
                r0 = LD32(sp - 44);
                r1 = LD8(((((1 & r2) | r7) << 8) + r0) + r12);
                ST8(r3 + r2, r1);
            }
        } else {
            r1 = LD32(r8 + 48);
            r2 = LD32(r10 + 4);
            r3 = LD32((r1 << 2) + r2);
            r2 = LD32(r8 + 44);
            r1 = LD16((r8 + 26));
            ST8(r3 + r2, r1);
        }
    }
    r9 = 0x0601F38C;
    r1 = LD32(r8 + 32);
    ST32(r8 + 32, (r1 + r14));
    r0 = GCALL7(0x0601F38C, r10, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
    r1 = LD32(r8 + 32);
    if (r1 > r0) {
        r0 = GCALL7(r9, r10, r5, r6, r7, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
        ST32(r8 + 32, r0);
    }
    ST32(r8 + 44, r13);
    r0 = LD32(sp - 36);
    ST32(r8 + 48, r0);
    return r12 & 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601093C(int r4)
{
    int r0, r6, r8, r9;
    FRAME(sp, 16);

    r0 = GCALL4(0x06018688, (sp - 16), r4, 0, 0);
    r4 = LD32(sp - 16);
    r8 = 6;
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x0607507C, r4);
        r8 = r0;
    }
    r9 = 0x060100A8;
    r0 = GCALL1(0x0607507C, 0x060100A8);
    r0 = GCALL2(0x06028380, ((r8 + r0) + 1), 15);
    r8 = r0;
    r6 = LD32(sp - 16);
    if (!((r8 & r8) == 0)) {
        r0 = GCALL3(0x06045264, r8, r9, r6);
    }
    r4 = LD32(sp - 16);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060109B4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8, r9, r10, r11, r12, r13, r14;

    r8 = r4;
    r12 = r5;
    r14 = r6;
    r11 = 1;
    r0 = r8;
    ST32(r0 + 136, 1);
    r10 = 144;
    r4 = LD32(r0 + 144);
    r9 = 0;
    if (!((r4 & r4) == 0)) {
        r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
        ST32(r8 + r10, r9);
    }
    r13 = 0x1000;
    r0 = GCALL4(0x060279E0, 0, 0x1000, 4, r11);
    r1 = r0;
    ST32(r8 + r10, r1);
    if (!((r1 & r1) == 0)) {
        r0 = r8;
        r1 = LD32(r0 + 144);
        ST32(r0 + 152, r1);
        ST32(r0 + 160, 0x1000);
        ST32(r0 + 156, 0);
        ST32(r0 + 148, 0);
        ST32((r8 + 88), 0);
        ST32(r0 + 164, 0);
        r1 = LD8(r12);
        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
            r0 = GCALL1(0x0601E268, r8);
            r0 = GCALL4(0x06017DD4, r12, r8, r14, 0);
            r0 = GCALL0(0x060259E0);
            if ((r0 & r0) == 0) {
                r0 = GCALL0(0x0602767C);
            }
        }
        r3 = 164;
        r0 = r8;
        r1 = LD32(r0 + 164);
        if ((r1 & r1) == 0) {
            r1 = LD32(r0 + 144);
            ST32(r0 + 152, r1);
            ST32(r0 + 156, 0);
            ST32(r0 + r3, 0);
            ST32(r0 + 148, 0);
            r0 = GCALL1(0x06010850, r8);
            r0 = GCALL1(0x0601E268, r8);
            r7 = 0;
            if (!((r12 & r12) == 0)) {
                r0 = GCALL1(0x0601093C, r12);
                r9 = r0;
                r0 = GCALL4(0x06017DD4, r9, r8, r14, 0);
                r0 = GCALL1(0x06027F48, r9);
            } else {
                r0 = GCALL4(0x06017DD4, 0x06010260, r8, r14, r7);
            }
        }
        r0 = 136;
        ST32(136 + r8, 0);
    } else {
        r0 = GCALL2(0x06028380, r13, 4);
        r1 = r0;
        ST32(r8 + r10, r1);
        if (!((r1 & r1) == 0)) {
            r0 = r8;
            r1 = LD32(r0 + 144);
            ST32(r0 + 152, r1);
            ST32(r0 + 160, 0x1000);
            ST32(r0 + 156, 0);
            ST32(r0 + 148, 0);
            ST32((r8 + 88), 0);
            ST32(r0 + 164, 0);
            r1 = LD8(r12);
            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                r0 = GCALL1(0x0601E268, r8);
                r0 = GCALL4(0x06017DD4, r12, r8, r14, 0);
                r0 = GCALL0(0x060259E0);
                if ((r0 & r0) == 0) {
                    r0 = GCALL0(0x0602767C);
                }
            }
            r3 = 164;
            r0 = r8;
            r1 = LD32(r0 + 164);
            if ((r1 & r1) == 0) {
                r1 = LD32(r0 + 144);
                ST32(r0 + 152, r1);
                ST32(r0 + 156, 0);
                ST32(r0 + r3, 0);
                ST32(r0 + 148, 0);
                r0 = GCALL1(0x06010850, r8);
                r0 = GCALL1(0x0601E268, r8);
                r7 = 0;
                if (!((r12 & r12) == 0)) {
                    r0 = GCALL1(0x0601093C, r12);
                    r9 = r0;
                    r0 = GCALL4(0x06017DD4, r9, r8, r14, 0);
                    r0 = GCALL1(0x06027F48, r9);
                } else {
                    r0 = GCALL4(0x06017DD4, 0x06010260, r8, r14, r7);
                }
            }
            r0 = 136;
            ST32(136 + r8, 0);
        } else {
            r0 = GCALL1(0x06028168, -3);
            ST32(152 + r8, r9);
            ST32(160 + r8, r9);
            r0 = 156;
            ST32(156 + r8, r9);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010B38(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 40);

    r10 = r4;
    ST32(sp - 36, r5);
    r14 = r6;
    r13 = LD32(r10 + 60);
    ST32(0x0607668C, 2);
    r0 = GCALL4(0x06027000, r4, (sp - 40), r6, r7);
    r0 = GCALL1(0x06010850, r10);
    r12 = LD32(0x10E4 + r10);
    r4 = LD32(0x10B8 + r10);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
    }
    r4 = LD32(0x10C4 + r10);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
    }
    r8 = 144;
    r4 = LD32(r10 + 144);
    r9 = r10;
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        ST32(r10 + r8, 0);
    }
    r9 = r9 + 80;
    r1 = LD32(r9);
    if (!((r1 & r1) == 0)) {
        r11 = 0x06027F48;
        do {
            r4 = LD32(r9);
            r1 = LD32(r4 + 12);
            ST32(r9, r1);
            r0 = GCALL1(r11, r4);
            r1 = LD32(r9);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    r4 = LD32(0x10DC + r10);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        r2 = LD32(0x10E4 + r10);
        ST32(r2 + 8, 0);
    }
    r4 = LD32(0x10E0 + r10);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        r2 = LD32(0x10E4 + r10);
        ST32(r2 + 4, 0);
    }
    r0 = GCALL3(0x0604B3F0, r10, 0, 0x10F0);
    ST32(0x10E4 + r10, r12);
    ST32(r10 + 44, 0x400);
    ST32(r10 + 40, 0);
    ST32(r10 + 28, 0);
    ST32(r10 + 24, 0);
    ST32(r10 + 60, r13);
    r5 = LD32(sp - 36);
    r0 = GCALL3(0x060109B4, r10, r5, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010FC8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 104);

    ST32(64 + (sp - 100), r4);
    r12 = r6;
    r13 = r7;
    ST32(0x0607668C, 2);
    r0 = GCALL2(0x060750DC, (sp - 100), r5);
    r0 = GCALL4(0x06025948, (sp - 100), 0, r6, r7);
    r10 = r0;
    r14 = 0x060279E0;
    r0 = GCALL4(0x060279E0, 0, (r10 + 1), -1, 1);
    r11 = r0;
    r8 = sp - 100;
    if (!((r11 & r11) == 0)) {
        r8 = r8 + 16;
        r0 = GCALL3(0x0604B3F0, r8, 0, 48);
        r0 = GCALL4(0x060258EC, (sp - 100), r8, r11, r10);
        r0 = GCALL1(0x06025984, r8);
        if ((r13 & r13) == 0) {
            r0 = GCALL1(0x0607507C, r12);
            r5 = r0;
        } else {
            r0 = GCALL1(0x0607507C, r12);
            r9 = r0;
            r0 = GCALL1(0x0607507C, r13);
            r5 = r9 + r0;
        }
        r0 = GCALL4(r14, 0, ((r5 + r10) + 10), -1, 1);
        r8 = r0;
        r1 = 0;
        if (!((r8 & r8) == 0)) {
            ST8(r11 + r10, r1);
            r3 = LD32((100 + (sp - 100)));
            if ((r3 & r3) == 0) {
                r0 = GCALL3(0x06045264, r8, r11, r12);
            } else {
                ST32((sp - 104), r13);
                r6 = LD32(104 + (sp - 104));
                r0 = GCALL5(0x06045264, r8, r11, r6, r12, LD32((sp - 104)));
            }
            r0 = GCALL1(0x0607507C, r8);
            r10 = r0;
            ST8(r8 + r10, 0);
            r0 = LD32((64 + (sp - 100)));
            r4 = LD32(r0);
            r3 = 64;
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(0x06027F48, r4);
                r3 = 64;
            }
            r0 = LD32((r3 + (sp - 100)));
            ST32(r0, r8);
            ST32(0x06075980, r8);
            r0 = GCALL2(0x06010F3C, r8, r10);
        }
        r0 = GCALL1(0x06027F48, r11);
    }
    ST32(0x0607668C, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012508(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;

    r1 = LD8(0x060767FC);
    if ((((signed char)r1) & ((signed char)r1)) == 0) {
        r2 = LD32(r4);
        r1 = LD32(r4 + 4);
        ST32(r2 + 40, r1);
        ST32(0x0607668C, 2);
        r4 = LD32(r4);
        r0 = GCALL4(0x060166F0, r4, r5, r6, r7);
        r0 = GCALL0(0x06043AC0);
        ST32(0x0607668C, 0);
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601254C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8;

    r8 = r4;
    r2 = LD32(r8);
    ST32(r2 + 140, 1);
    r4 = LD32(r8);
    r0 = GCALL4(0x060166F0, r4, r5, r6, r7);
    r0 = GCALL0(0x06043AC0);
    r2 = LD32(r8);
    ST32(r2 + 140, 0);
    r2 = LD32(r8);
    r1 = LD32(r8 + 4);
    ST32(r2 + 40, r1);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060125E8(int r4)
{
    int r0, r1, r2, r8;

    r1 = LD8(0x060767FC);
    r8 = r4;
    if ((((signed char)r1) & ((signed char)r1)) == 0) {
        r4 = LD32(r8);
        r0 = GCALL1(0x06037674, r4);
        r4 = LD32(r8);
        r0 = GCALL2(0x06016610, r4, 0x060162B4);
        r0 = GCALL0(0x06033088);
        r4 = LD32(r8);
        r0 = GCALL2(0x06038B3C, 0, r0);
        r2 = LD32(r8);
        r1 = LD32(r8 + 4);
        ST32(r2 + 40, r1);
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012970(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8;

    r1 = LD8(0x060767FC);
    r8 = r4;
    if ((((signed char)r1) & ((signed char)r1)) == 0) {
        r4 = LD32(r8);
        r0 = GCALL4(0x06016610, r4, 0x060161C4, r6, r7);
        r0 = GCALL0(0x06027700);
        r2 = LD32(r8);
        r1 = LD32(r8 + 4);
        ST32(r2 + 40, r1);
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060129AC(int r4)
{
    int r0, r1, r2, r5, r6, r8, r9;

    r9 = r4;
    r5 = LD32(r9 + 20);
    r4 = LD32(r9);
    r0 = GCALL1(0x06012368, r4);
    if (!((r0 & r0) == 0)) {
        r4 = LD32(r9);
        r6 = LD8(0x0608AF53);
        r1 = LD32(r9 + 16);
        ST32(r9 + 20, r6);
        r5 = LD32(r1);
        r8 = LD32(r4 + 16);
        r0 = GCALL3(0x06010B38, r4, r5, r6);
        r1 = LD32(r9);
        ST32(r1 + 16, r8);
        ST32(0x0607668C, 2);
        r2 = LD32(r9);
        r1 = LD32(r9 + 4);
        ST32(r2 + 40, r1);
        r4 = LD32(r9);
        r0 = GCALL1(0x060166F0, r4);
        ST32(0x0607668C, 0);
    }
    r1 = LD32(0x06089B00);
    if (r1 >= 0) {
        r1 = LD8(0x0608AF56);
        if ((r1 & r1) == 0) {
            r1 = LD32(0x0608AB68);
            r2 = 136;
        } else {
            r2 = 186;
            r1 = LD32(0x0608AB68);
        }
        ST16((r1 + 2), r2);
    }
    r0 = GCALL1(0x0602CC0C, 0);
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012B3C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, c1;

    r9 = r4;
    r2 = 36;
    r8 = LD32(r9);
    ST32(r8 + 60, 36);
    r1 = LD32(0x0608B97C);
    r10 = LD32(r8 + 16);
    if (!((r1 & r1) == 0)) {
        ST32(r8 + 60, (196 + r2));
    }
    r1 = LD32(r9 + 16);
    r5 = LD32(r1);
    r6 = LD32(r9 + 20);
    r0 = GCALL4(0x06010B38, r8, r5, r6, r7);
    r1 = LD32(r9);
    ST32(r1 + 16, r10);
    r1 = LD8(0x060767FC);
    c1 = (((signed char)r1) & ((signed char)r1)) == 0;
    r1 = 2;
    if (c1) {
        r10 = 0x0607668C;
        ST32(0x0607668C, r1);
        r1 = LD32(r9 + 4);
        ST32(r8 + 40, r1);
        r0 = GCALL1(0x060166F0, r8);
        r1 = LD32(0x06089B00);
        if (r1 >= 0) {
            r0 = GCALL1(0x06010820, r8);
        }
        r0 = GCALL0(0x06043AC0);
        ST32(r10, 0);
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012BCC(int r4)
{
    int r0, r8;

    r8 = r4;
    r0 = GCALL1(0x06032164, 4);
    r4 = LD32(r8 + 12);
    r0 = GCALL2(0x06048E80, r4, 0x06011610);
    return -3;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06013EC8(int r4)
{
    int r0, r1, r8, r9, r10;

    r1 = LD32(0x06089CB0);
    r8 = r1 + r4;
    r1 = LD32(0x06089CB0);
    if (!(r1 >= r8)) {
        r10 = 0x25FE00A4;
        r9 = 0x06010B20;
        do {
            r0 = LD32(r10);
            if (!(((r0 & 135) & (r0 & 135)) == 0)) {
                r0 = GCALL1(r9, 1);
            }
            r0 = GCALL0(0x0605299C);
            r1 = LD32(0x06089CB0);
        } while (AGAIN(!(r1 >= r8)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06014150(void)
{
    int r0, r1;

    r1 = LD32(0x06000344);
    r0 = GCALL2(r1, -1, 1);
    r0 = GCALL2(0x06069E6C, 64, 0x0601413C);
    r1 = LD32(0x06000344);
    r0 = GCALL2(r1, -2, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06019240(int r4)
{
    int r0, r1, r2, r8, r9, r10, r11, r12;

    r8 = r4;
    r2 = r8 + 80;
    r1 = LD32(r2);
    r10 = 0;
    if (!((r1 & r1) == 0)) {
        r9 = r2;
        r11 = r8 + 64;
        r12 = r8 + 68;
        while (1) {
            r4 = LD32(r9);
            r2 = LD32(r4);
            if (r2 == 0x7FFFFFFF) {
                break;
            } else {
                r1 = LD32(r4 + 12);
                ST32(r9, r1);
                r1 = LD32(r4);
                if (r1 > r10) {
                    r10 = r1;
                }
                r1 = LD16((r4 + 4));
                ST32(r11, r1);
                r1 = LD16((r4 + 6));
                ST32(r12, r1);
                r1 = LD32(r11);
                ST32(r8 + 8, r1);
                r0 = GCALL1(0x06027F48, r4);
                r1 = LD32(r9);
                if (!((r1 & r1) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        r1 = LD32(r8 + 12);
        if (r10 > r1) {
            ST32(r8 + 12, r10);
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601A9B4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9;

    r9 = r4;
    r3 = LD32(0x10B8 + r9);
    r1 = LD32(0x10C0 + r9);
    r2 = LD16(r1);
    ST16(r3, r2);
    r1 = LD16((r1 + 2));
    ST16((r3 + 2), r1);
    ST32((r9 + 92), 0);
    r1 = LD32(0x10C8 + r9);
    if ((r1 & r1) == 0) {
        r8 = LD32((r9 + 88));
        r1 = r8;
        if (!((r8 & r8) == 0)) {
            r0 = LD16((r1 + 4));
            if (!(r0 == -1)) {
                r0 = (SR() & ~1) | 0;
                r7 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
                r0 = (SR() & ~1) | 0;
                SETSR((r0 | 240));
                r1 = LD32(0x060766B8);
                ST32(r8, r1);
                ST32(0x060766B8, r8);
                r1 = SR();
                SETSR(((r1 & -241) | ((r7 << 2) << 2)));
                r2 = r9;
            } else {
                r4 = LD32(r8 + 36);
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
                }
                r0 = GCALL1(0x06027F48, r8);
                r2 = r9;
            }
            ST32((r2 + 88), 0);
        }
    } else {
        r0 = LD32(0x10CC + r9);
        if (r0 == 3) {
            r8 = LD32((r9 + 88));
            r1 = r8;
            if (!((r8 & r8) == 0)) {
                r0 = LD16((r1 + 4));
                if (!(r0 == -1)) {
                    r0 = (SR() & ~1) | 0;
                    r7 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
                    r0 = (SR() & ~1) | 0;
                    SETSR((r0 | 240));
                    r1 = LD32(0x060766B8);
                    ST32(r8, r1);
                    ST32(0x060766B8, r8);
                    r1 = SR();
                    SETSR(((r1 & -241) | ((r7 << 2) << 2)));
                    r2 = r9;
                } else {
                    r4 = LD32(r8 + 36);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL4(0x06027F48, r4, r5, r6, r7);
                    }
                    r0 = GCALL1(0x06027F48, r8);
                    r2 = r9;
                }
                ST32((r2 + 88), 0);
            }
        }
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601AB20(int r4)
{
    int r0, r1, r8, c0, c2;

    r8 = r4;
    r1 = LD32(r8 + 4);
    c0 = r1 > 0;
    r1 = 0;
    if (c0) {
        r0 = GCALL1(0x0601D4D8, r8);
        r0 = GCALL1(0x06019240, r8);
        r0 = GCALL2(0x0601D178, r8, -18);
        r0 = GCALL2(0x0601D1A0, r8, -18);
        r0 = GCALL1(0x0601D1C4, r8);
        r1 = LD32(0x10C8 + r8);
        if (!((r1 & r1) == 0)) {
            r0 = LD32(0x10CC + r8);
            c2 = r0 == 1;
            r0 = r8;
            if (c2) {
                r4 = LD32(r0 + 0x10D0);
                r0 = GCALL1(0x0602AC4C, r4);
                ST32(r8 + 0x10D0, 0);
            }
        }
        r1 = LD32(r8 + 4);
        r0 = 1;
        ST32(r8 + 4, (r1 - 1));
    } else {
        ST32(r8 + 4, r1);
        r0 = 1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601ACC8(int r4)
{
    int r0, r1, r8, r9;

    r9 = r4 + 84;
    r8 = LD32(r9);
    if (!((r8 & r8) == 0)) {
        r0 = GCALL2(0x0601D178, r4, -24);
        r1 = LD32(r8 + 12);
        ST32(r9, r1);
        r0 = GCALL1(0x06027F48, r8);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601AF78(int r4)
{
    int r0, r1, r8;

    r8 = r4;
    r0 = GCALL2(0x0601D178, r4, -24);
    r8 = r8 + 84;
    r4 = LD32(r8);
    if (!((r4 & r4) == 0)) {
        r1 = LD32(r4 + 12);
        ST32(r8, r1);
        r0 = GCALL1(0x06027F48, r4);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601AFF8(int r4)
{
    int r0, r1, r8;

    r8 = r4;
    r0 = GCALL2(0x0601D178, r4, -24);
    r8 = r8 + 84;
    r4 = LD32(r8);
    if (!((r4 & r4) == 0)) {
        r1 = LD32(r4 + 12);
        ST32(r8, r1);
        r0 = GCALL1(0x06027F48, r4);
    }
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CC34(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = r4;
    r0 = GCALL4(0x0601CB70, 0, r5, r6, r7);
    r1 = 0;
    if (!((r0 & r0) == 0)) {
        do {
            r1 = r0;
            r0 = LD32(r1 + 52);
        } while (AGAIN(!((r0 & r0) == 0)));
    }
    if ((r1 & r1) == 0) {
        r1 = LD32(0x060875C8);
        ST32(r8 + 52, r1);
        ST32(0x060875C8, r8);
    } else {
        ST32(r1 + 52, r8);
        ST32(r8 + 52, 0);
    }
    r0 = GCALL0(0x0601CB88);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CE48(int r4, int r5)
{
    int r0, r1, r8, r9, r10, r11, c4;

    r11 = r4;
    if ((r5 & r5) == 0) {
        if (r11 == 3) {
            r0 = GCALL0(0x060438A4);
        }
    }
    r0 = GCALL0(0x0601CEEC);
    r0 = LD32(0x06000330);
    r0 = GCALL1(r0, 7);
    if (!((r0 & r0) == 0)) {
        r8 = LD32(0x060875C8);
        r9 = 0;
        if (!((r8 & r8) == 0)) {
            r10 = 0x06027F48;
            do {
                r1 = LD32(r8 + 56);
                c4 = (r1 & r1) == 0;
                r1 = c4;
                if (c4) {
                    if (r11 > r1) {
                        r4 = LD32(r8 + 12);
                        r1 = r8;
                        if (!((r4 & r4) == 0)) {
                            r1 = LD8((r1 + 6));
                            if ((r1 & r1) == 0) {
                                r0 = GCALL1(r10, r4);
                                ST32(r8 + 12, r9);
                            }
                        }
                    }
                    r4 = LD32(r8 + 16);
                    r1 = r8;
                    if (!((r4 & r4) == 0)) {
                        r1 = LD8((r1 + 5));
                        if ((r1 & r1) == 0) {
                            r0 = GCALL1(r10, r4);
                            ST32(r8 + 16, r9);
                        }
                    }
                }
                r8 = LD32(r8 + 52);
            } while (AGAIN(!((r8 & r8) == 0)));
        }
        r0 = GCALL0(0x0601CB88);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CF60(int r4, int r5, int r6, int r7)
{
    int r0, r1;

    r0 = GCALL4(0x0601CB70, 0, r5, r6, r7);
    r1 = 0;
    if (!((r0 & r0) == 0)) {
        do {
            ST32(r0 + 48, r1);
            r0 = LD32(r0 + 52);
        } while (AGAIN(!((r0 & r0) == 0)));
    }
    r0 = GCALL0(0x0601CB88);
    r0 = GCALL0(0x06043924);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D1C4(int r4)
{
    int r0, r1, r2, r8, r9;

    r9 = r4;
    r8 = LD32(r9 + 12);
    r0 = GCALL1(0x0601D4D8, r4);
    r2 = LD32(r9 + 12);
    if (r2 == r8) {
        r1 = LD32(r9 + 36);
        ST32(r9 + 12, (r1 + r2));
    }
    r0 = GCALL1(0x0601D408, r9);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601DAB0(int r4, int r5, int r6, int r7)
{
    int r0, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 552);

    r13 = r4;
    r11 = r6;
    r12 = r7;
    ST32((0x200 + (sp - 552)), r5);
    if (!(r11 > r12)) {
        r10 = 0;
        r14 = 255;
        do {
            r9 = (r12 - r11) + 1;
            if (r9 > r14) {
                r9 = r14;
            }
            r0 = r9 + r9;
            r3 = LD32((0x200 + (sp - 552)));
            ST32((0x204 + (sp - 552)), r0);
            r0 = GCALL3(0x0604B358, (sp - 552), ((r11 + r11) + r3), r0);
            r0 = LD32((0x204 + (sp - 552)));
            ST16(r0 + (sp - 552), 0);
            r8 = LD32(0x10B4 + r13);
            r0 = GCALL1(0x060455FC, (sp - 552));
            ST32((sp - 556), (r0 - 1));
            r0 = GCALL5(0x0601CD5C, r13, r8, (sp - 552), 0, LD32((sp - 556)));
            r10 = r10 + r0;
            r11 = r11 + r9;
        } while (AGAIN(!(r11 > r12)));
        r0 = r10;
    } else {
        r0 = GCALL4(0x06045264, 0x0608B9D0, 0x0601DA6C, r6, r7);
        r0 = GCALL1(0x0602BA00, 0x0608B9D0);
        r0 = GCALL2(0x06045264, 0x0608B9D0, 0x0601DA84);
        r0 = GCALL1(0x0602BA00, 0x0608B9D0);
        r0 = GCALL4(0x06045264, 0x0608B9D0, 0x0601DAA0, r11, r12);
        r0 = GCALL1(0x0602BA00, 0x0608B9D0);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601E268(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, c0, c1, c3, c4;

    r10 = r4;
    r0 = GCALL4(0x0601CF60, 0, r5, r6, r7);
    r0 = GCALL0(0x06027620);
    r1 = LD32(r10 + 60);
    r3 = 0x0608AF4E;
    ST32((r10 + 64), r1);
    ST32((r10 + 68), 0x25C);
    r2 = r10 + 72;
    ST32(r2, 36);
    r1 = LD8(0x0608AF4E);
    c0 = (r1 & r1) == 0;
    r1 = 0x0608AF4E;
    if (c0) {
        ST32(r2, -4);
        r1 = r3;
    }
    r1 = LD8((r1 - 1));
    c1 = (r1 & r1) == 0;
    r1 = r3;
    if (c1) {
        r1 = LD32(r2);
        ST32(r2, (r1 - 28));
        r1 = r3;
    }
    r1 = LD8((r1 + 10));
    if ((r1 & r1) == 0) {
        r1 = LD32(r2);
        ST32(r2, (r1 - 28));
    }
    r1 = LD32(r2);
    r9 = r10 + 80;
    ST32(r2, (r1 + 96));
    ST32((r10 + 76), 0x1BC);
    ST32(0x10B0 + r10, 0);
    r1 = LD32(r9);
    c3 = (r1 & r1) == 0;
    r1 = r10;
    if (!(c3)) {
        r11 = 0x06027F48;
        do {
            r4 = LD32(r9);
            r1 = LD32(r4 + 12);
            ST32(r9, r1);
            r0 = GCALL1(r11, r4);
            r1 = LD32(r9);
            c4 = (r1 & r1) == 0;
            r1 = r10;
        } while (AGAIN(!(c4)));
    }
    r3 = 0;
    r6 = 7;
    r1 = LD32((r1 + 64));
    r7 = 0;
    ST32(r10 + 8, r1);
    r1 = LD32((r10 + 72));
    r2 = r10;
    ST32(r10 + 12, r1);
    do {
        ST32((r2 + 104), r7);
        r3 = r3 + 1;
        r2 = r2 + 4;
    } while (AGAIN(!(r3 > r6)));
    r11 = 0;
    ST32((r10 + 100), 0);
    r0 = GCALL0(0x0601CD44);
    r2 = r0;
    r13 = 0x10B4;
    r0 = r10;
    ST32(r0 + 0x10B4, r2);
    ST32(r0 + 0x10BC, r2);
    r12 = 0;
    r0 = GCALL0(0x0601CD50);
    r1 = r0;
    r9 = 0x10C0;
    r0 = r10;
    ST32(r0 + 0x10C0, r1);
    ST16(r1, 0);
    r1 = LD32(r0 + 0x10C0);
    r1 = r1 + 2;
    r2 = LD8(r1);
    ST8(r1, (r2 & 191));
    r1 = LD32(r10 + 0x10C0);
    r1 = r1 + 2;
    r2 = LD8(r1);
    ST8(r1, (r2 & 127));
    r1 = LD32(r10 + 0x10C0);
    r8 = 0x10B8;
    r1 = r1 + 2;
    r2 = LD8(r1);
    ST8(r1, (r2 & 223));
    r0 = r10;
    r1 = LD32(r0 + 0x10B8);
    r5 = -1;
    if (!((r1 & r1) == 0)) {
        r1 = LD32(r0 + r9);
        r3 = LD32(r0 + r8);
        r2 = LD16(r1);
        r8 = 0x10C4;
        ST16(r3, r2);
        r1 = LD16((r1 + 2));
        ST16((r3 + 2), r1);
        r1 = LD32(r0 + 0x10C4);
        r0 = r10;
        if (!((r1 & r1) == 0)) {
            r2 = LD32(r0 + r8);
            ST16(r2, 123);
            r1 = LD32(r0 + r8);
            r1 = r1 + 2;
            r2 = LD8(r1);
            ST8(r1, (r2 & 191));
            r1 = LD32(r10 + r8);
            r1 = r1 + 2;
            r2 = LD8(r1);
            ST8(r1, (r2 | 128));
            r1 = LD32(r10 + r8);
            r1 = r1 + 2;
            r2 = LD8(r1);
            ST8(r1, (r2 & 223));
            r0 = r10;
            r1 = LD32(r0 + r9);
            ST16(r1, r12);
            r1 = LD32(r0 + r9);
            r1 = r1 + 2;
            r2 = LD8(r1);
            ST8(r1, (r2 & 191));
            r1 = LD32(r10 + r9);
            r1 = r1 + 2;
            r2 = LD8(r1);
            ST8(r1, (r2 & 127));
            r1 = LD32(r10 + r9);
            r1 = r1 + 2;
            r2 = LD8(r1);
            r9 = 0;
            ST8(r1, (r2 & 223));
            r0 = r10;
            ST8(r0 + 0x1B0, 0);
            ST32(r10 + 48, r11);
            ST32(r10 + 52, r11);
            ST32(r10 + 56, r11);
            ST32((r10 + 84), r11);
            ST8(r0 + 168, -110);
            ST32(r10, r11);
            ST32(r10 + 4, r11);
            r4 = LD32(r0 + r13);
            r0 = GCALL3(0x0601CC78, r4, 128, 0);
            r8 = 0x10DC;
            r1 = LD32(r0 + 32);
            ST32(r10 + 32, r1);
            ST32(r10 + 36, r1);
            r4 = LD32(r10 + 0x10DC);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(0x06027F48, r4);
                r0 = r10;
                ST32(r0 + r8, r11);
                r1 = LD32(r0 + 0x10E4);
                ST32(r1 + 8, r11);
            }
            r8 = 0x10E0;
            r4 = LD32(r10 + 0x10E0);
            if (!((r4 & r4) == 0)) {
                r0 = GCALL1(0x06027F48, r4);
                r0 = r10;
                ST32(r0 + r8, r11);
                r1 = LD32(r0 + 0x10E4);
                ST32(r1 + 4, r11);
            }
            ST8(176 + r10, r9);
            ST32(0x10D4 + r10, r11);
            r0 = GCALL0(0x06033E8C);
            ST32(0x10E8 + r10, -1);
            r0 = 0x10EC;
            ST32(0x10EC + r10, r11);
        } else {
            r0 = GCALL2(0x06028380, 4, -1);
            r1 = r0;
            r0 = r10;
            ST32(r0 + r8, r1);
            if (!((r1 & r1) == 0)) {
                r0 = r10;
                r2 = LD32(r0 + r8);
                ST16(r2, 123);
                r1 = LD32(r0 + r8);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 & 191));
                r1 = LD32(r10 + r8);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 | 128));
                r1 = LD32(r10 + r8);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 & 223));
                r0 = r10;
                r1 = LD32(r0 + r9);
                ST16(r1, r12);
                r1 = LD32(r0 + r9);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 & 191));
                r1 = LD32(r10 + r9);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 & 127));
                r1 = LD32(r10 + r9);
                r1 = r1 + 2;
                r2 = LD8(r1);
                r9 = 0;
                ST8(r1, (r2 & 223));
                r0 = r10;
                ST8(r0 + 0x1B0, 0);
                ST32(r10 + 48, r11);
                ST32(r10 + 52, r11);
                ST32(r10 + 56, r11);
                ST32((r10 + 84), r11);
                ST8(r0 + 168, -110);
                ST32(r10, r11);
                ST32(r10 + 4, r11);
                r4 = LD32(r0 + r13);
                r0 = GCALL3(0x0601CC78, r4, 128, 0);
                r8 = 0x10DC;
                r1 = LD32(r0 + 32);
                ST32(r10 + 32, r1);
                ST32(r10 + 36, r1);
                r4 = LD32(r10 + 0x10DC);
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(0x06027F48, r4);
                    r0 = r10;
                    ST32(r0 + r8, r11);
                    r1 = LD32(r0 + 0x10E4);
                    ST32(r1 + 8, r11);
                }
                r8 = 0x10E0;
                r4 = LD32(r10 + 0x10E0);
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(0x06027F48, r4);
                    r0 = r10;
                    ST32(r0 + r8, r11);
                    r1 = LD32(r0 + 0x10E4);
                    ST32(r1 + 4, r11);
                }
                ST8(176 + r10, r9);
                ST32(0x10D4 + r10, r11);
                r0 = GCALL0(0x06033E8C);
                ST32(0x10E8 + r10, -1);
                r0 = 0x10EC;
                ST32(0x10EC + r10, r11);
            }
        }
    } else {
        r0 = GCALL2(0x06028380, 4, r5);
        r1 = r0;
        r0 = r10;
        ST32(r0 + r8, r1);
        if (!((r1 & r1) == 0)) {
            r0 = r10;
            r1 = LD32(r0 + r9);
            r3 = LD32(r0 + r8);
            r2 = LD16(r1);
            r8 = 0x10C4;
            ST16(r3, r2);
            r1 = LD16((r1 + 2));
            ST16((r3 + 2), r1);
            r1 = LD32(r0 + 0x10C4);
            r0 = r10;
            if (!((r1 & r1) == 0)) {
                r2 = LD32(r0 + r8);
                ST16(r2, 123);
                r1 = LD32(r0 + r8);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 & 191));
                r1 = LD32(r10 + r8);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 | 128));
                r1 = LD32(r10 + r8);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 & 223));
                r0 = r10;
                r1 = LD32(r0 + r9);
                ST16(r1, r12);
                r1 = LD32(r0 + r9);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 & 191));
                r1 = LD32(r10 + r9);
                r1 = r1 + 2;
                r2 = LD8(r1);
                ST8(r1, (r2 & 127));
                r1 = LD32(r10 + r9);
                r1 = r1 + 2;
                r2 = LD8(r1);
                r9 = 0;
                ST8(r1, (r2 & 223));
                r0 = r10;
                ST8(r0 + 0x1B0, 0);
                ST32(r10 + 48, r11);
                ST32(r10 + 52, r11);
                ST32(r10 + 56, r11);
                ST32((r10 + 84), r11);
                ST8(r0 + 168, -110);
                ST32(r10, r11);
                ST32(r10 + 4, r11);
                r4 = LD32(r0 + r13);
                r0 = GCALL3(0x0601CC78, r4, 128, 0);
                r8 = 0x10DC;
                r1 = LD32(r0 + 32);
                ST32(r10 + 32, r1);
                ST32(r10 + 36, r1);
                r4 = LD32(r10 + 0x10DC);
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(0x06027F48, r4);
                    r0 = r10;
                    ST32(r0 + r8, r11);
                    r1 = LD32(r0 + 0x10E4);
                    ST32(r1 + 8, r11);
                }
                r8 = 0x10E0;
                r4 = LD32(r10 + 0x10E0);
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(0x06027F48, r4);
                    r0 = r10;
                    ST32(r0 + r8, r11);
                    r1 = LD32(r0 + 0x10E4);
                    ST32(r1 + 4, r11);
                }
                ST8(176 + r10, r9);
                ST32(0x10D4 + r10, r11);
                r0 = GCALL0(0x06033E8C);
                ST32(0x10E8 + r10, -1);
                r0 = 0x10EC;
                ST32(0x10EC + r10, r11);
            } else {
                r0 = GCALL2(0x06028380, 4, -1);
                r1 = r0;
                r0 = r10;
                ST32(r0 + r8, r1);
                if (!((r1 & r1) == 0)) {
                    r0 = r10;
                    r2 = LD32(r0 + r8);
                    ST16(r2, 123);
                    r1 = LD32(r0 + r8);
                    r1 = r1 + 2;
                    r2 = LD8(r1);
                    ST8(r1, (r2 & 191));
                    r1 = LD32(r10 + r8);
                    r1 = r1 + 2;
                    r2 = LD8(r1);
                    ST8(r1, (r2 | 128));
                    r1 = LD32(r10 + r8);
                    r1 = r1 + 2;
                    r2 = LD8(r1);
                    ST8(r1, (r2 & 223));
                    r0 = r10;
                    r1 = LD32(r0 + r9);
                    ST16(r1, r12);
                    r1 = LD32(r0 + r9);
                    r1 = r1 + 2;
                    r2 = LD8(r1);
                    ST8(r1, (r2 & 191));
                    r1 = LD32(r10 + r9);
                    r1 = r1 + 2;
                    r2 = LD8(r1);
                    ST8(r1, (r2 & 127));
                    r1 = LD32(r10 + r9);
                    r1 = r1 + 2;
                    r2 = LD8(r1);
                    r9 = 0;
                    ST8(r1, (r2 & 223));
                    r0 = r10;
                    ST8(r0 + 0x1B0, 0);
                    ST32(r10 + 48, r11);
                    ST32(r10 + 52, r11);
                    ST32(r10 + 56, r11);
                    ST32((r10 + 84), r11);
                    ST8(r0 + 168, -110);
                    ST32(r10, r11);
                    ST32(r10 + 4, r11);
                    r4 = LD32(r0 + r13);
                    r0 = GCALL3(0x0601CC78, r4, 128, 0);
                    r8 = 0x10DC;
                    r1 = LD32(r0 + 32);
                    ST32(r10 + 32, r1);
                    ST32(r10 + 36, r1);
                    r4 = LD32(r10 + 0x10DC);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                        r0 = r10;
                        ST32(r0 + r8, r11);
                        r1 = LD32(r0 + 0x10E4);
                        ST32(r1 + 8, r11);
                    }
                    r8 = 0x10E0;
                    r4 = LD32(r10 + 0x10E0);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(0x06027F48, r4);
                        r0 = r10;
                        ST32(r0 + r8, r11);
                        r1 = LD32(r0 + 0x10E4);
                        ST32(r1 + 4, r11);
                    }
                    ST8(176 + r10, r9);
                    ST32(0x10D4 + r10, r11);
                    r0 = GCALL0(0x06033E8C);
                    ST32(0x10E8 + r10, -1);
                    r0 = 0x10EC;
                    ST32(0x10EC + r10, r11);
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601E884(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r9, r10, r11, r12, c2, c7, c9, c10;

    r11 = r4;
    r1 = LD32(136 + r11);
    r12 = r5;
    if (!((r1 & r1) == 0)) {
        r1 = LD32(0x10C8 + r11);
        if ((r1 & r1) == 0) {
            r9 = LD32((r11 + 88));
            r5 = -1;
            if (!((r9 & r9) == 0)) {
                r0 = GCALL2(0x06028380, 40, r5);
                r10 = r0;
                r0 = 1;
                if (!((r10 & r10) == 0)) {
                    r6 = LD32(r9);
                    r2 = r9;
                    if (!((r6 & r6) == 0)) {
                        r0 = GCALL3(0x06045264, 0x0608B9D0, 0x0601E874, r6);
                        r0 = GCALL1(0x0602BA00, 0x0608B9D0);
                        r2 = r9;
                    }
                    r1 = LD32(r11 + 8);
                    ST16((r2 + 4), r1);
                    r1 = LD32(r11 + 12);
                    ST32(r9 + 16, r1);
                    r1 = LD32(0x060766B8);
                    while (1) {
                        c7 = r1 == r9;
                        if (!((r1 & r1) == 0)) {
                            POLL();
                            if (c7) {
                                break;
                            } else {
                                r1 = LD32(r1);
                                continue;
                            }
                        } else {
                            break;
                        }
                    }
                    c9 = (r12 & r12) == 0;
                    if ((r1 & r1) == 0) {
                        r1 = LD32(0x060766B8);
                        ST32(r9, r1);
                        ST32(0x060766B8, r9);
                    }
                    if (!(c9)) {
                        ST32(r12 + 8, r9);
                    }
                    r1 = r9;
                    r2 = LD32(r1);
                    ST32(r10, r2);
                    r2 = LD32(r9 + 4);
                    r1 = (r1 + 4) + 4;
                    ST32(r10 + 4, r2);
                    r2 = LD32(r1);
                    r1 = r1 + 4;
                    r3 = r10 + 8;
                    ST32(r3, r2);
                    r2 = LD32(r1);
                    r1 = r1 + 4;
                    r3 = r3 + 4;
                    ST32(r3, r2);
                    r2 = LD32(r1);
                    r1 = r1 + 4;
                    r3 = r3 + 4;
                    ST32(r3, r2);
                    r2 = LD32(r1);
                    r1 = r1 + 4;
                    r3 = r3 + 4;
                    ST32(r3, r2);
                    r2 = LD32(r1);
                    r1 = r1 + 4;
                    r3 = r3 + 4;
                    ST32(r3, r2);
                    r2 = LD32(r1);
                    r1 = r1 + 4;
                    r3 = r3 + 4;
                    ST32(r3, r2);
                    r2 = LD32(r1);
                    r3 = r3 + 4;
                    ST32(r3, r2);
                    r1 = LD32((r1 + 4));
                    ST32(r3 + 4, r1);
                    r1 = LD32(r9 + 36);
                    c10 = (r1 & r1) == 0;
                    r1 = 0;
                    if (c10) {
                        ST32((r11 + 88), r10);
                        ST16((r10 + 4), -1);
                        ST32(r10 + 16, -1);
                        ST16((r10 + 6), 0);
                        ST32(r10 + 20, 0);
                        ST32(r10, 0);
                        ST32(r10 + 28, 0);
                        ST8((r10 + 11), 0);
                        r0 = 1;
                    } else {
                        ST32(r10 + 36, r1);
                        r4 = LD32(r9 + 36);
                        r0 = GCALL1(0x0607507C, r4);
                        r0 = GCALL2(0x06028380, (r0 + 1), -1);
                        r1 = r0;
                        ST32(r10 + 36, r1);
                        if (!((r1 & r1) == 0)) {
                            r5 = LD32(r9 + 36);
                            r0 = GCALL2(0x060750DC, r1, r5);
                            ST32((r11 + 88), r10);
                            ST16((r10 + 4), -1);
                            ST32(r10 + 16, -1);
                            ST16((r10 + 6), 0);
                            ST32(r10 + 20, 0);
                            ST32(r10, 0);
                            ST32(r10 + 28, 0);
                            ST8((r10 + 11), 0);
                            r0 = 1;
                        } else {
                            r0 = GCALL1(0x06027F48, r10);
                            r0 = 1;
                        }
                    }
                }
            } else {
                r0 = 0;
            }
        } else {
            r0 = LD32(0x10CC + r11);
            c2 = r0 == 3;
            r0 = 0;
            if (c2) {
                r9 = LD32((r11 + 88));
                r5 = -1;
                if (!((r9 & r9) == 0)) {
                    r0 = GCALL2(0x06028380, 40, r5);
                    r10 = r0;
                    r0 = 1;
                    if (!((r10 & r10) == 0)) {
                        r6 = LD32(r9);
                        r2 = r9;
                        if (!((r6 & r6) == 0)) {
                            r0 = GCALL3(0x06045264, 0x0608B9D0, 0x0601E874, r6);
                            r0 = GCALL1(0x0602BA00, 0x0608B9D0);
                            r2 = r9;
                        }
                        r1 = LD32(r11 + 8);
                        ST16((r2 + 4), r1);
                        r1 = LD32(r11 + 12);
                        ST32(r9 + 16, r1);
                        r1 = LD32(0x060766B8);
                        while (1) {
                            c7 = r1 == r9;
                            if (!((r1 & r1) == 0)) {
                                POLL();
                                if (c7) {
                                    break;
                                } else {
                                    r1 = LD32(r1);
                                    continue;
                                }
                            } else {
                                break;
                            }
                        }
                        c9 = (r12 & r12) == 0;
                        if ((r1 & r1) == 0) {
                            r1 = LD32(0x060766B8);
                            ST32(r9, r1);
                            ST32(0x060766B8, r9);
                        }
                        if (!(c9)) {
                            ST32(r12 + 8, r9);
                        }
                        r1 = r9;
                        r2 = LD32(r1);
                        ST32(r10, r2);
                        r2 = LD32(r9 + 4);
                        r1 = (r1 + 4) + 4;
                        ST32(r10 + 4, r2);
                        r2 = LD32(r1);
                        r1 = r1 + 4;
                        r3 = r10 + 8;
                        ST32(r3, r2);
                        r2 = LD32(r1);
                        r1 = r1 + 4;
                        r3 = r3 + 4;
                        ST32(r3, r2);
                        r2 = LD32(r1);
                        r1 = r1 + 4;
                        r3 = r3 + 4;
                        ST32(r3, r2);
                        r2 = LD32(r1);
                        r1 = r1 + 4;
                        r3 = r3 + 4;
                        ST32(r3, r2);
                        r2 = LD32(r1);
                        r1 = r1 + 4;
                        r3 = r3 + 4;
                        ST32(r3, r2);
                        r2 = LD32(r1);
                        r1 = r1 + 4;
                        r3 = r3 + 4;
                        ST32(r3, r2);
                        r2 = LD32(r1);
                        r3 = r3 + 4;
                        ST32(r3, r2);
                        r1 = LD32((r1 + 4));
                        ST32(r3 + 4, r1);
                        r1 = LD32(r9 + 36);
                        c10 = (r1 & r1) == 0;
                        r1 = 0;
                        if (c10) {
                            ST32((r11 + 88), r10);
                            ST16((r10 + 4), -1);
                            ST32(r10 + 16, -1);
                            ST16((r10 + 6), 0);
                            ST32(r10 + 20, 0);
                            ST32(r10, 0);
                            ST32(r10 + 28, 0);
                            ST8((r10 + 11), 0);
                            r0 = 1;
                        } else {
                            ST32(r10 + 36, r1);
                            r4 = LD32(r9 + 36);
                            r0 = GCALL1(0x0607507C, r4);
                            r0 = GCALL2(0x06028380, (r0 + 1), -1);
                            r1 = r0;
                            ST32(r10 + 36, r1);
                            if (!((r1 & r1) == 0)) {
                                r5 = LD32(r9 + 36);
                                r0 = GCALL2(0x060750DC, r1, r5);
                                ST32((r11 + 88), r10);
                                ST16((r10 + 4), -1);
                                ST32(r10 + 16, -1);
                                ST16((r10 + 6), 0);
                                ST32(r10 + 20, 0);
                                ST32(r10, 0);
                                ST32(r10 + 28, 0);
                                ST8((r10 + 11), 0);
                                r0 = 1;
                            } else {
                                r0 = GCALL1(0x06027F48, r10);
                                r0 = 1;
                            }
                        }
                    }
                } else {
                    r0 = 0;
                }
            }
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601F2FC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8;

    r8 = r4;
    r1 = LD32(r8 + 12);
    if (!((r1 & r1) == 0)) {
        r4 = LD32(r8);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL4(0x0601F1D0, r4, r5, r6, r7);
        }
    }
    r4 = LD32(r8 + 4);
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
    }
    r4 = LD32(r8 + 8);
    r1 = 0;
    if (!((r4 & r4) == 0)) {
        r0 = GCALL1(0x06027F48, r4);
        r1 = 0;
    }
    ST32(r8 + 12, r1);
    ST32(r8, r1);
    ST32(r8 + 4, r1);
    ST32(r8 + 8, r1);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06010820(int r4)
{
    int r0, r1, r5;

    r1 = LD8(0x0608AF56);
    r5 = LD32(r4 + 20);
    if ((r1 & r1) == 0) {
        r5 = r5 + -240;
    } else {
        r5 = r5 + -336;
    }
    r0 = GCALL2(0x060106BC, r4, r5);
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060147F0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r9, r10;
    FRAME(sp, 68);

    r10 = r4;
    r2 = r5;
    r1 = r6 + r7;
    r5 = r5 + r7;
    r3 = LD32((64 + (sp - 64)));
    r9 = LD32(68 + (sp - 64));
    r4 = r6 + r3;
    r9 = r9 & 255;
    ST32(sp - 64, r4);
    ST32(sp - 60, r1);
    ST32(sp - 56, r1);
    ST32(sp - 52, r4);
    ST32(sp - 48, (r6 - r3));
    ST32(sp - 44, (r6 - r7));
    ST32(sp - 40, r5);
    ST32(sp - 36, (r2 + r3));
    r1 = r2 - r3;
    ST32(sp - 32, r1);
    r2 = r2 - r7;
    ST32(sp - 28, r2);
    ST32(sp - 24, r2);
    ST32(sp - 20, r1);
    ST32((sp - 68), r9);
    r0 = GCALL8(0x06014638, r10, r5, r2, r4, LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
    r7 = LD32(sp - 60);
    r6 = LD32(sp - 32);
    r5 = LD32(sp - 36);
    ST32((sp - 72), r9);
    r0 = GCALL8(0x06014638, r10, r5, r6, r7, LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)), LD32((sp - 60)));
    r7 = LD32(sp - 48);
    r6 = LD32(sp - 28);
    r5 = LD32(sp - 40);
    ST32((sp - 76), r9);
    r0 = GCALL8(0x06014638, r10, r5, r6, r7, LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)), LD32((sp - 64)));
    r7 = LD32(sp - 44);
    r6 = LD32(sp - 32);
    r5 = LD32(sp - 36);
    ST32((sp - 80), r9);
    r0 = GCALL8(0x06014638, r10, r5, r6, r7, LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)), LD32((sp - 68)));
    return;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601EDD0(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, r14, c1;
    int v36;
    int v40;
    int v44;
    int v48;
    int v52;

    r10 = r4;
    r11 = r5;
    r5 = LD32(r11 + 4);
    r0 = GCALL2(0x06025DFC, r4, r5);
    r5 = LD8(r10 + 168);
    r0 = GCALL3(0x06026208, r11, r5, 0);
    r13 = LD32(r10 + 16);
    v44 = r13;
    r1 = LD32(r10 + 136);
    r5 = 44;
    if ((r1 & r1) == 0) {
        r0 = LD32(r10 + 136);
        r2 = 0;
        v40 = r0;
        ST32(r10 + 136, 0);
        r1 = LD32(r11 + 0x2000000C);
        if ((r1 & r1) == 0) {
            r8 = LD32(r10 + 16);
            ST32(r10 + 16, r2);
            r1 = LD8(168 + r10);
            r0 = GCALL8(0x06015154, r10, 0, 0, 0x400, 0x7FFFFFFF, r1, v44, v40);
            ST32(r10 + 16, r8);
        } else {
            r1 = LD32(192 + r11);
            if ((r1 & r1) == 0) {
                r8 = LD32(r10 + 16);
                ST32(r10 + 16, r2);
                r1 = LD8(168 + r10);
                r0 = GCALL8(0x06015154, r10, 0, 0, 0x400, 0x7FFFFFFF, r1, v44, v40);
                ST32(r10 + 16, r8);
            }
        }
        r1 = LD32(0x2000000C + r11);
        if (!((r1 & r1) == 0)) {
            r1 = LD32(192 + r11);
            r0 = r11;
            if (!((r1 & r1) == 0)) {
                r1 = LD32(r0 + 196);
                v36 = r1;
                r6 = -v44;
                r12 = LD32(r0 + 200);
                r0 = GCALL7(0x0607286C, r6, r12, 0, 0, v44, v40, v36);
                r9 = r0 * r12;
                r1 = LD32(r10 + 24);
                r8 = 0;
                if (!(r9 >= (r6 + r1))) {
                    r14 = 0x06015A5C;
                    do {
                        r1 = LD32(224 + r11);
                        r0 = r11;
                        if (!((r1 & r1) == 0)) {
                            r1 = LD32(r0 + 196);
                            r7 = r8 + r1;
                            r1 = LD8(r10 + 168);
                            v48 = r1;
                            r1 = LD32(r11 + 200);
                            r0 = GCALL8(0x06015154, r10, r8, r9, (r7 - 1), ((r1 + r9) - 1), v48, v44, v40);
                        }
                        r0 = GCALL7(r14, r10, r11, r8, r9, v44, v40, v36);
                        r8 = r8 + v36;
                        if (!(r8 > 0x3FF)) {
                            POLL();
                            continue;
                        }
                        r1 = LD32(r10 + 24);
                        r9 = r9 + r12;
                        r8 = 0;
                    } while (AGAIN(!(r9 >= (r1 - v44))));
                }
            }
        }
        ST32(r10 + 136, v40);
        r0 = 1;
    } else {
        r0 = GCALL5(0x06015D00, r10, r5, 0, 0, v44);
        c1 = (r0 & r0) == 0;
        r0 = r10;
        if (c1) {
            r0 = 0;
        } else {
            r6 = 152;
            r7 = LD32(r0 + 152);
            ST32(r7, 7);
            ST32(r7 + 4, 0);
            ST16((r7 + 24), 0);
            ST32(r7 + 28, 0);
            r0 = r11;
            r1 = LD32(r0 + 196);
            ST16((r7 + 26), r1);
            r1 = LD32(r0 + 200);
            r2 = 148;
            ST32(r7 + 32, r1);
            ST32(r7 + 36, r11);
            r1 = LD32(r11 + 12);
            ST32(r7 + 40, r1);
            ST32(r7 + 12, 0);
            ST32(r7 + 16, 0x7FFFFFFF);
            r1 = LD32(r10 + 148);
            if (!((r1 & r1) == 0)) {
                ST32(r1, r7);
            }
            r0 = r10;
            ST32(r0 + r2, (r7 + 4));
            r1 = LD32(r0 + r6);
            ST32(r0 + r6, (r1 + 44));
            r1 = LD32(r0 + 164);
            ST32(r0 + 164, (r1 + 1));
            r0 = LD32(r10 + 136);
            r2 = 0;
            v40 = r0;
            ST32(r10 + 136, 0);
            r1 = LD32(r11 + 0x2000000C);
            if ((r1 & r1) == 0) {
                r8 = LD32(r10 + 16);
                ST32(r10 + 16, r2);
                r1 = LD8(168 + r10);
                r0 = GCALL8(0x06015154, r10, 0, 0, 0x400, 0x7FFFFFFF, r1, v44, v40);
                ST32(r10 + 16, r8);
            } else {
                r1 = LD32(192 + r11);
                if ((r1 & r1) == 0) {
                    r8 = LD32(r10 + 16);
                    ST32(r10 + 16, r2);
                    r1 = LD8(168 + r10);
                    r0 = GCALL8(0x06015154, r10, 0, 0, 0x400, 0x7FFFFFFF, r1, v44, v40);
                    ST32(r10 + 16, r8);
                }
            }
            r1 = LD32(0x2000000C + r11);
            if (!((r1 & r1) == 0)) {
                r1 = LD32(192 + r11);
                r0 = r11;
                if (!((r1 & r1) == 0)) {
                    r1 = LD32(r0 + 196);
                    v36 = r1;
                    r6 = -v44;
                    r12 = LD32(r0 + 200);
                    r0 = GCALL7(0x0607286C, r6, r12, 0, 0, v44, v40, v36);
                    r9 = r0 * r12;
                    r1 = LD32(r10 + 24);
                    r8 = 0;
                    if (!(r9 >= (r6 + r1))) {
                        r14 = 0x06015A5C;
                        do {
                            r1 = LD32(224 + r11);
                            r0 = r11;
                            if (!((r1 & r1) == 0)) {
                                r1 = LD32(r0 + 196);
                                r7 = r8 + r1;
                                r1 = LD8(r10 + 168);
                                v48 = r1;
                                r1 = LD32(r11 + 200);
                                r0 = GCALL8(0x06015154, r10, r8, r9, (r7 - 1), ((r1 + r9) - 1), v48, v44, v40);
                            }
                            r0 = GCALL7(r14, r10, r11, r8, r9, v44, v40, v36);
                            r8 = r8 + v36;
                            if (!(r8 > 0x3FF)) {
                                POLL();
                                continue;
                            }
                            r1 = LD32(r10 + 24);
                            r9 = r9 + r12;
                            r8 = 0;
                        } while (AGAIN(!(r9 >= (r1 - v44))));
                    }
                }
            }
            ST32(r10 + 136, v40);
            r0 = 1;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F760(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c2, c4;
    FRAME(sp, 52);

    r14 = sp - 44;
    r10 = r4;
    r8 = r5;
    ST32(r14 + 8, r7);
    r11 = r6 & 0xFFFF;
    r1 = LD32(sp);
    r13 = r11;
    r7 = LD32(r8 + 48);
    r6 = LD32(r8 + 44);
    r5 = LD32(r8 + 32);
    r12 = r1 & 0xFFFF;
    ST32((sp - 48), (r14 + 4));
    ST32((sp - 52), r14);
    r0 = GCALL6(0x0601F6B0, r4, r5, 0, r7, LD32((sp - 52)), LD32((sp - 48)));
    r9 = r0;
    r0 = GCALL6(0x0601F38C, r10, 0, 0, 0, LD32((sp - 52)), LD32((sp - 48)));
    if (!(r9 >= r0)) {
        c2 = r11 == r12;
        if (r9 >= 0) {
            r2 = (short)r13;
            if (!(c2)) {
                r0 = 0x346;
                r1 = LD16(0x346 + r10);
                r7 = LD32(r14 + 4);
                if (!(r2 == r1)) {
                    r2 = LD32(r10 + 4);
                    r3 = LD32((r7 << 2) + r2);
                    r2 = LD32(r14);
                    r0 = LD32(r14 + 8);
                    r1 = LD8(((((1 & r2) | (r7 & 2)) << 8) + r0) + r13);
                    r0 = r3;
                    ST8(r0 + r2, r1);
                }
            } else {
                r1 = LD32(r14 + 4);
                r2 = LD32(r10 + 4);
                r3 = LD32((r1 << 2) + r2);
                r2 = LD32(r14);
                r1 = LD16((r8 + 26));
                r0 = r3;
                ST8(r0 + r2, r1);
            }
            r1 = LD32(r8 + 32);
            r2 = LD32(r8 + 44);
            ST32(r8 + 32, (r1 + 1));
            r2 = r2 + 1;
            ST32(r8 + 44, r2);
            r1 = LD16((r10 + 48));
            c4 = r2 >= (r1 & 0xFFFF);
            r1 = 0;
            if (c4) {
                ST32(r8 + 44, r1);
                r1 = LD32(r8 + 48);
                ST32(r8 + 48, (r1 + 1));
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F834(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c6, c7;
    FRAME(sp, 64);

    r14 = sp - 56;
    r9 = r5;
    ST32(r14 + 8, r7);
    r1 = LD32(sp);
    r12 = r6;
    ST32(r14 + 12, (r1 & 0xFFFF));
    r1 = LD16((((r12 + r12) + r9) + 52));
    r10 = r4;
    ST32(r14 + 20, r1);
    r1 = LD32(r9 + 44);
    r13 = LD32(r14 + 20);
    r2 = r10 + 48;
    r0 = LD32(r9 + 48);
    r13 = r13 + r1;
    ST32(r9 + 44, (r13 - 1));
    r1 = LD16(r2);
    ST32(r14 + 16, r0);
    if (r13 >= (r1 & 0xFFFF)) {
        do {
            r1 = LD16(r2);
            r0 = LD32(r14 + 16);
            r1 = r1 & 0xFFFF;
            r13 = r13 - r1;
            ST32(r14 + 16, (r0 + 1));
        } while (AGAIN(r13 >= r1));
    }
    r3 = r10 + 48;
    while (1) {
        r1 = LD16(r3);
        r2 = LD32(r9 + 44);
        r0 = LD32(r14 + 20);
        if (r2 >= (r1 & 0xFFFF)) {
            POLL();
            r1 = LD16(r3);
            ST32(r9 + 44, (r2 - (r1 & 0xFFFF)));
            r1 = LD32(r9 + 48);
            ST32(r9 + 48, (r1 + 1));
            continue;
        } else {
            break;
        }
    }
    r11 = 1;
    r1 = r14;
    if (!(1 >= r0)) {
        do {
            r1 = LD32(r9 + 32);
            r0 = LD32(r14 + 20);
            r7 = LD32(r9 + 48);
            r6 = LD32(r9 + 44);
            ST32((sp - 60), (r14 + 4));
            ST32((sp - 64), r14);
            r0 = GCALL6(0x0601F6B0, r10, ((r1 + r0) - r11), 0, r7, LD32((sp - 64)), LD32((sp - 60)));
            r8 = r0;
            r0 = GCALL6(0x0601F38C, r10, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)));
            if (r8 >= r0) {
                r1 = r12;
            } else {
                r1 = r12;
                if (r8 >= 0) {
                    r6 = LD8((r9 + r12) + 0x4034);
                    r2 = r6 & 255;
                    r0 = LD32(r14 + 12);
                    c6 = (r2 & 0xFFFF) == r0;
                    r2 = (short)r2;
                    if (!(c6)) {
                        r1 = LD16(0x346 + r10);
                        c7 = r2 == r1;
                        r2 = LD32(r14 + 4);
                        if (!(c7)) {
                            r1 = LD32(r10 + 4);
                            r3 = LD32((r2 << 2) + r1);
                            r7 = LD32(r14);
                            r0 = LD32(r14 + 8);
                            r1 = LD8(((((1 & r7) | (r2 & 2)) << 8) + r0) + (r6 & 255));
                            ST8(r3 + r7, r1);
                        }
                    } else {
                        r1 = LD32(r14 + 4);
                        r2 = LD32(r10 + 4);
                        r0 = LD32((r1 << 2) + r2);
                        r1 = LD16((r9 + 26));
                        r2 = LD32(r14);
                        ST8(r0 + r2, r1);
                    }
                    r1 = r12;
                }
            }
            r12 = LD16(((r1 + r1) + r9) + 0x2034);
            r1 = LD32(r9 + 44);
            r1 = r1 - 1;
            ST32(r9 + 44, r1);
            if (!(r1 >= 0)) {
                r1 = LD16((r10 + 48));
                ST32(r9 + 44, ((r1 & 0xFFFF) - 1));
                r1 = LD32(r9 + 48);
                ST32(r9 + 48, (r1 - 1));
            }
            r0 = LD32(r14 + 20);
            r11 = r11 + 1;
            r1 = r14;
        } while (AGAIN(!(r11 >= r0)));
    }
    r7 = LD32(r9 + 48);
    r6 = LD32(r9 + 44);
    r5 = LD32(r9 + 32);
    ST32((sp - 60), (r1 + 4));
    ST32((sp - 64), r14);
    r0 = GCALL6(0x0601F6B0, r10, r5, 0, r7, LD32((sp - 64)), LD32((sp - 60)));
    r8 = r0;
    r0 = GCALL6(0x0601F38C, r10, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)));
    if (!(r8 >= r0)) {
        r0 = LD32(r14 + 12);
        if (r8 >= 0) {
            r2 = (short)r12;
            if (!(r12 == r0)) {
                r1 = LD16(0x346 + r10);
                r7 = LD32(r14 + 4);
                if (!(r2 == r1)) {
                    r2 = LD32(r10 + 4);
                    r3 = LD32((r7 << 2) + r2);
                    r2 = LD32(r14);
                    r0 = LD32(r14 + 8);
                    r1 = LD8(((((1 & r2) | (r7 & 2)) << 8) + r0) + r12);
                    ST8(r3 + r2, r1);
                }
            } else {
                r1 = LD32(r14 + 4);
                r2 = LD32(r10 + 4);
                r3 = LD32((r1 << 2) + r2);
                r2 = LD32(r14);
                r1 = LD16((r9 + 26));
                ST8(r3 + r2, r1);
            }
        }
    }
    r1 = LD32(r9 + 32);
    r8 = 0x0601F38C;
    r0 = LD32(r14 + 20);
    ST32(r9 + 32, (r1 + r0));
    r0 = GCALL1(0x0601F38C, r10);
    r1 = LD32(r9 + 32);
    if (r1 > r0) {
        r0 = GCALL1(r8, r10);
        ST32(r9 + 32, r0);
    }
    r0 = LD32(r14 + 16);
    ST32(r9 + 44, r13);
    ST32(r9 + 48, r0);
    return r12 & 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060111D8(int r4)
{
    int r0, r1, r8, r9, c0;

    r1 = LD8((r4 + 28));
    r1 = (r1 & 255) - 5;
    c0 = (unsigned)r1 > (unsigned)26;
    r1 = r1 + r1;
    if (c0) {
        r0 = 0;
    } else {
        r1 = LD16(0x060111FC + r1);
        switch (r1) {
        case 54:
            r8 = r4 + 24;
            r1 = LD16(r8);
            r4 = LD32(r4 + 20);
            r0 = GCALL2(0x060750DC, (r4 + r1), 0x06079D0C);
            r4 = 0x06079CF8;
            r0 = 0x0607507C;
            r0 = GCALL1(r0, r4);
            r1 = LD16(r8);
            ST16(r8, (r1 + r0));
            r0 = 1;
            break;
        case 78:
            r9 = 0x06079D14;
            r8 = r4;
            r8 = r8 + 24;
            r1 = LD16(r8);
            r4 = LD32(r4 + 20);
            r0 = GCALL2(0x060750DC, (r4 + r1), r9);
            r0 = 0x0607507C;
            r4 = r9;
            r0 = GCALL1(r0, r4);
            r1 = LD16(r8);
            ST16(r8, (r1 + r0));
            r0 = 1;
            break;
        case 130:
            r0 = 0;
            break;
        case 84:
            r9 = 0x06079D1C;
            r8 = r4;
            r8 = r8 + 24;
            r1 = LD16(r8);
            r4 = LD32(r4 + 20);
            r0 = GCALL2(0x060750DC, (r4 + r1), r9);
            r0 = 0x0607507C;
            r4 = r9;
            r0 = GCALL1(r0, r4);
            r1 = LD16(r8);
            ST16(r8, (r1 + r0));
            r0 = 1;
            break;
        case 90:
            r9 = 0x06079D24;
            r8 = r4;
            r8 = r8 + 24;
            r1 = LD16(r8);
            r4 = LD32(r4 + 20);
            r0 = GCALL2(0x060750DC, (r4 + r1), r9);
            r0 = 0x0607507C;
            r4 = r9;
            r0 = GCALL1(r0, r4);
            r1 = LD16(r8);
            ST16(r8, (r1 + r0));
            r0 = 1;
            break;
        case 96:
            r9 = 0x06079D2C;
            r8 = r4;
            r8 = r8 + 24;
            r1 = LD16(r8);
            r4 = LD32(r4 + 20);
            r0 = GCALL2(0x060750DC, (r4 + r1), r9);
            r0 = 0x0607507C;
            r4 = r9;
            r0 = GCALL1(r0, r4);
            r1 = LD16(r8);
            ST16(r8, (r1 + r0));
            r0 = 1;
            break;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060162B4(int r4)
{
    int r0, r1, r2, r5, r6, r8, r9;

    r9 = r4;
    r0 = 144;
    r8 = LD32(144 + r9);
    if (!((r8 & r8) == 0)) {
        do {
            r2 = LD32(r8);
            r1 = r2;
            if ((unsigned)r2 > (unsigned)14) {
                r8 = LD32(r8 + 4);
            } else {
                r1 = LD16(0x060162DC + (r1 + r1));
                r0 = 0x060162DC + r1;
                switch (r1) {
                case 120:
                    r8 = LD32(r8 + 4);
                    break;
                case 30:
                    r5 = LD32(r8 + 24);
                    r1 = LD32(r5 + 24);
                    if ((r1 & r1) == 0) {
                        r8 = LD32(r8 + 4);
                    } else {
                        r0 = 0x06036138;
                        r0 = GCALL2(r0, r9, r5);
                        r8 = LD32(r8 + 4);
                    }
                    break;
                case 44:
                    r5 = LD32(r8 + 24);
                    r1 = LD32(r5 + 24);
                    if ((r1 & r1) == 0) {
                        r8 = LD32(r8 + 4);
                    } else {
                        r0 = 0x06036310;
                        r0 = GCALL2(r0, r9, r5);
                        r8 = LD32(r8 + 4);
                    }
                    break;
                case 58:
                    r5 = LD32(r8 + 24);
                    r1 = LD32(r5 + 24);
                    if ((r1 & r1) == 0) {
                        r8 = LD32(r8 + 4);
                    } else {
                        r0 = 0x06036454;
                        r0 = GCALL2(r0, r9, r5);
                        r8 = LD32(r8 + 4);
                    }
                    break;
                case 72:
                    r5 = LD32(r8 + 24);
                    r1 = LD32(r5 + 24);
                    if ((r1 & r1) == 0) {
                        r8 = LD32(r8 + 4);
                    } else {
                        r0 = 0x060366D8;
                        r0 = GCALL2(r0, r9, r5);
                        r8 = LD32(r8 + 4);
                    }
                    break;
                case 86:
                    r5 = LD32(r8 + 24);
                    r1 = LD32(r5 + 24);
                    if ((r1 & r1) == 0) {
                        r8 = LD32(r8 + 4);
                    } else {
                        r0 = 0x06035454;
                        r0 = GCALL2(r0, r9, r5);
                        r8 = LD32(r8 + 4);
                    }
                    break;
                case 104:
                    r5 = LD32(r8 + 24);
                    r1 = LD32(r5 + 24);
                    r6 = 1;
                    if (!((r1 & r1) == 0)) {
                        r0 = GCALL3(0x0603592C, r9, r5, r6);
                    }
                    r8 = LD32(r8 + 4);
                    break;
                }
            }
        } while (AGAIN(!((r8 & r8) == 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D1F4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c0, c7;
    FRAME(sp, 40);

    r9 = r4;
    r13 = r5;
    r8 = (((r13 + r13) + r13) << 2) + r9;
    r11 = LD32(r8 + 0x2B4);
    r0 = r11;
    r3 = LD16(r0 + 216);
    r2 = LD32(r0 + 200);
    r1 = LD16(r0 + 220);
    r12 = r2 + ((r1 + r3) + (r1 + r3));
    r1 = LD16(r0 + 218);
    r3 = r3 + r1;
    r1 = LD32(r0 + 196);
    ST32(sp - 36, (r1 + (r3 + r3)));
    r14 = LD32(r9 + 8);
    r4 = LD32(r9 + 0x10B4);
    r10 = LD32(r9 + 12);
    r0 = GCALL5(0x0601CC78, r4, 128, 0, r7, LD32((sp - 36)));
    r3 = r0;
    r1 = LD16(r8 + 0x2B0);
    r1 = r1 - 4;
    c0 = (unsigned)r1 > (unsigned)5;
    r1 = r1 + r1;
    if (!(c0)) {
        r1 = LD16(0x0601D270 + r1);
        switch (r1) {
        case 12:
            r1 = LD32(r9 + 32);
            r1 = r1 - r12;
            r10 = r10 + r1;
            break;
        case 16:
            r1 = LD32(r9 + 32);
            r1 = r1 - ((r12 + ((int)((unsigned)r12 >> 31))) >> 1);
            r10 = r10 + r1;
            break;
        case 80:
            break;
        case 34:
            r1 = LD32(r9 + 32);
            r2 = LD32(r3 + 32);
            r1 = r1 - r2;
            r10 = r10 + r1;
            break;
        case 42:
            r1 = LD32(r3 + 32);
            r2 = LD32(r9 + 32);
            r10 = r10 + ((r2 - ((r1 + ((int)((unsigned)r1 >> 31))) >> 1)) - ((((int)((unsigned)r12 >> 31)) + r12) >> 1));
            break;
        case 74:
            r1 = LD32(r9 + 36);
            r1 = r1 - r12;
            r10 = r10 + r1;
            break;
        }
    }
    ST32((sp - 40), 0);
    r0 = GCALL6(0x060159A4, r9, r11, r14, r10, LD32((sp - 40)), LD32((sp - 36)));
    r7 = r9 + 88;
    r3 = LD32((r9 + (((r13 + r13) + r13) << 2)) + 0x2B8);
    ST32(r7, r3);
    if (!((r3 & r3) == 0)) {
        r0 = r11;
        r2 = LD16(r0 + 218);
        r1 = LD16(r0 + 216);
        ST16((r3 + 4), (r1 + (r2 + r14)));
        r3 = LD32(r7);
        r1 = LD16(r0 + 220);
        r2 = LD16(r0 + 216);
        ST32(r3 + 16, ((r1 + r10) + r2));
        r1 = LD32(r7);
        r0 = LD16((2 + (sp - 36)));
        ST16((r1 + 6), r0);
        r1 = LD32(r7);
        ST32(r1 + 20, r12);
    }
    r1 = LD32(r9 + 16);
    r3 = r1 + r10;
    r1 = LD32(r9 + 28);
    if (!((r3 + r12) >= r1)) {
        r0 = LD32(sp - 36);
    } else {
        r1 = LD32(r9 + 24);
        r0 = LD32(sp - 36);
        if (!(r3 >= r1)) {
            r1 = LD32(0x10C8 + r9);
            c7 = (r1 & r1) == 0;
            r1 = 2;
            if (c7) {
                r0 = GCALL5(0x06015A5C, r9, r11, r14, r10, LD32((sp - 36)));
                r0 = LD32(sp - 36);
            } else {
                r2 = LD32(0x10CC + r9);
                r0 = LD32(sp - 36);
                if (r2 > r1) {
                    r0 = GCALL5(0x06015A5C, r9, r11, r14, r10, LD32((sp - 36)));
                    r0 = LD32(sp - 36);
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601E9F8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c3, c5, c10, c28, c31;
    FRAME(sp, 48);

    r8 = r4;
    r10 = r5;
    ST32(sp - 44, r6);
    r14 = r7;
    r0 = r10;
    r3 = LD16(r0 + 216);
    r2 = LD32(r0 + 200);
    r1 = LD16(r0 + 220);
    r11 = r2 + ((r1 + r3) + (r1 + r3));
    r1 = LD16(r0 + 218);
    r3 = r3 + r1;
    r1 = LD32(r0 + 196);
    r13 = r1 + (r3 + r3);
    r4 = LD32(r8 + 0x10B4);
    r0 = GCALL5(0x0601CC78, r4, 128, 0, r7, LD32((sp - 44)));
    r9 = r0;
    r0 = LD32(sp);
    r12 = LD32(sp);
    if (!(r0 == 2)) {
        r4 = r8;
        if ((r12 & r12) == 0) {
            r0 = GCALL5(0x0601D4D8, r8, 0, 0, 0, LD32((sp - 44)));
            r0 = LD32(r8 + 8);
            ST32(sp - 44, r0);
            r14 = LD32(r8 + 12);
            r4 = r8;
        }
    } else {
        r0 = GCALL5(0x0601D4D8, r8, 0, 0, 0, LD32((sp - 44)));
        r1 = LD32((r8 + 68));
        r1 = r1 - r13;
        ST32(r8 + 8, r1);
        ST32(sp - 44, r1);
        r14 = LD32(r8 + 12);
        r4 = r8;
    }
    r5 = LD32(r10 + 4);
    r0 = GCALL5(0x06025DFC, r4, r5, 0, 0, LD32((sp - 44)));
    r10 = r0;
    r0 = LD32(r8 + 16);
    ST32(sp - 40, r0);
    r1 = LD32(r8 + 0x10C8);
    r0 = LD32(sp);
    if (!((r1 & r1) == 0)) {
        r0 = LD32(0x10CC + r8);
        c3 = r0 == 1;
        r0 = LD32(sp);
        if (c3) {
            r0 = GCALL6(0x0602AC28, r13, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)));
            r1 = LD32(0x10D0 + r8);
            ST32(0x10D0 + r8, (r1 + r13));
            r0 = GCALL6(0x0602AC4C, r13, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)));
            r0 = LD32(sp);
        }
    }
    c5 = (r0 & r0) == 0;
    if (!(r0 == 2)) {
        r6 = r13;
        if (!(c5)) {
            r0 = GCALL6(0x0601CF94, r8, 1, r6, 0, LD32((sp - 44)), LD32((sp - 40)));
            r7 = LD32(r8 + 56);
            r1 = r7 + r7;
            ST16((r1 + r8) + 0xEB0, r0);
            r1 = ((r1 + r7) << 2) + 0x2B0;
            r5 = r8 + r1;
            ST32(r5 + 4, r10);
            r12 = LD16(46 + (sp - 44));
            ST16(r8 + r1, r12);
            ST32(r5 + 8, 0);
            r0 = GCALL6(0x0601E884, r8, r5, 0, 0, LD32((sp - 44)), LD32((sp - 40)));
            r1 = LD32(r8 + 56);
            ST32(r8 + 56, (r1 + 1));
            r2 = LD32(sp);
            r2 = r2 - 4;
            r1 = r2;
            if ((unsigned)r2 > (unsigned)5) {
                r2 = LD32(r8 + 32);
                r1 = LD32(r8 + 36);
                if (!(r11 > r2)) {
                    r0 = LD32(sp);
                    if (r1 == r2) {
                        r0 = GCALL6(0x0601D034, r8, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)));
                        c10 = (r0 & r0) == 0;
                        r0 = LD32(sp);
                        if (c10) {
                            ST32(r8 + 32, r11);
                            ST32(r8 + 36, r11);
                            r0 = LD32(sp);
                        }
                    }
                } else {
                    ST32(r8 + 36, (r1 - r2));
                    r1 = LD32(r8 + 36);
                    ST32(r8 + 32, r11);
                    ST32(r8 + 36, (r1 + r11));
                    r0 = LD32(sp);
                }
            } else {
                r1 = LD16(0x0601EB1C + (r1 + r1));
                switch (r1) {
                case 28:
                    r2 = LD32(r8 + 32);
                    r1 = LD32(r8 + 36);
                    if (!(r11 > r2)) {
                        r0 = LD32(sp);
                        if (r1 == r2) {
                            r0 = GCALL6(0x0601D034, r8, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)));
                            c10 = (r0 & r0) == 0;
                            r0 = LD32(sp);
                            if (c10) {
                                ST32(r8 + 32, r11);
                                ST32(r8 + 36, r11);
                                r0 = LD32(sp);
                            }
                        }
                    } else {
                        ST32(r8 + 36, (r1 - r2));
                        r1 = LD32(r8 + 36);
                        ST32(r8 + 32, r11);
                        ST32(r8 + 36, (r1 + r11));
                        r0 = LD32(sp);
                    }
                    break;
                case 136:
                    r3 = LD32(r8 + 32);
                    r2 = (r11 + ((int)((unsigned)r11 >> 31))) >> 1;
                    if (r2 > r3) {
                        r1 = LD32(r8 + 36);
                        ST32(r8 + 36, (r1 - r3));
                        r1 = LD32(r8 + 36);
                        ST32(r8 + 32, r2);
                        ST32(r8 + 36, (r1 + r2));
                    }
                    r1 = LD32(r8 + 36);
                    r3 = LD32(r8 + 32);
                    r0 = LD32(sp);
                    if (r2 > (r1 - r3)) {
                        ST32(r8 + 36, (r3 + r2));
                        r0 = LD32(sp);
                    }
                    break;
                case 12:
                    r1 = LD32(r8 + 36);
                    if (r11 > r1) {
                        ST32(r8 + 36, r11);
                        r0 = LD32(sp);
                    } else {
                        r0 = LD32(sp);
                    }
                    break;
                case 174:
                    r7 = LD32(r9 + 32);
                    r1 = LD32(r8 + 36);
                    r3 = LD32(r8 + 32);
                    r0 = LD32(sp);
                    if ((r11 - r7) > (r1 - r3)) {
                        ST32(r8 + 36, ((r3 + r11) - r7));
                        r0 = LD32(sp);
                    }
                    break;
                case 206:
                    r1 = LD32(r9 + 32);
                    r7 = (r11 + ((int)((unsigned)r11 >> 31))) >> 1;
                    r3 = LD32(r8 + 32);
                    r2 = r7 + ((r1 + ((int)((unsigned)r1 >> 31))) >> 1);
                    if (!(r3 >= r2)) {
                        r1 = LD32(r8 + 36);
                        ST32(r8 + 36, (r1 - r3));
                        r1 = LD32(r8 + 36);
                        ST32(r8 + 32, r2);
                        ST32(r8 + 36, (r1 + r2));
                    }
                    r1 = LD32(r9 + 32);
                    r3 = LD32(r8 + 32);
                    r2 = r7 - ((r1 + ((int)((unsigned)r1 >> 31))) >> 1);
                    r1 = LD32(r8 + 36);
                    r0 = LD32(sp);
                    if (r2 > (r1 - r3)) {
                        ST32(r8 + 36, (r3 + r2));
                        r0 = LD32(sp);
                    }
                    break;
                case 290:
                    r2 = LD32(r8 + 36);
                    if (!(r2 >= r11)) {
                        r1 = LD32(r8 + 32);
                        ST32(r8 + 36, r11);
                        ST32(r8 + 32, (r11 - (r2 - r1)));
                    }
                    r0 = LD32(sp);
                    break;
                }
            }
        } else {
            ST32((sp - 48), 0);
            r6 = LD32(sp - 44);
            r0 = GCALL7(0x060159A4, r8, r10, r6, r14, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
            r9 = r8 + 88;
            r0 = LD32(r9);
            ST32(sp - 36, r0);
            r0 = GCALL8(0x0601E884, r8, 0, 0, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
            r1 = LD32(r8 + 136);
            if (!((r1 & r1) == 0)) {
                r1 = LD32(0x10C8 + r8);
                if ((r1 & r1) == 0) {
                    r3 = LD32(r9);
                    r0 = r10;
                    if (!((r3 & r3) == 0)) {
                        r2 = LD16(r0 + 218);
                        r12 = LD32(sp - 44);
                        r1 = LD16(r0 + 216);
                        ST16((r3 + 4), (r1 + (r2 + r12)));
                        r3 = LD32(r9);
                        r1 = LD16(r0 + 220);
                        r2 = LD16(r0 + 216);
                        ST32(r3 + 16, ((r1 + r14) + r2));
                        r1 = LD32(r9);
                        ST16((r1 + 6), r13);
                        r1 = LD32(r9);
                        ST32(r1 + 20, r11);
                        r0 = LD32(sp - 36);
                        r2 = r0;
                        if (!((r0 & r0) == 0)) {
                            r1 = LD32(r9);
                            r2 = LD8((r2 + 10));
                            ST8((r1 + 10), r2);
                            r2 = LD32(r9);
                            r1 = LD32(r0 + 28);
                            ST32(r2 + 28, r1);
                        }
                    }
                } else {
                    r0 = LD32(0x10CC + r8);
                    if (r0 == 3) {
                        r3 = LD32(r9);
                        r0 = r10;
                        if (!((r3 & r3) == 0)) {
                            r2 = LD16(r0 + 218);
                            r12 = LD32(sp - 44);
                            r1 = LD16(r0 + 216);
                            ST16((r3 + 4), (r1 + (r2 + r12)));
                            r3 = LD32(r9);
                            r1 = LD16(r0 + 220);
                            r2 = LD16(r0 + 216);
                            ST32(r3 + 16, ((r1 + r14) + r2));
                            r1 = LD32(r9);
                            ST16((r1 + 6), r13);
                            r1 = LD32(r9);
                            ST32(r1 + 20, r11);
                            r0 = LD32(sp - 36);
                            r2 = r0;
                            if (!((r0 & r0) == 0)) {
                                r1 = LD32(r9);
                                r2 = LD8((r2 + 10));
                                ST8((r1 + 10), r2);
                                r2 = LD32(r9);
                                r1 = LD32(r0 + 28);
                                ST32(r2 + 28, r1);
                            }
                        }
                    }
                }
            }
            r1 = LD32(0x20000014 + r10);
            r3 = LD32(sp - 40);
            if ((r1 & r1) == 0) {
                r3 = r3 + r14;
                r1 = LD32(r8 + 28);
                if ((r3 + r11) >= r1) {
                    r1 = LD32(r8 + 24);
                    if (!(r3 >= r1)) {
                        r1 = LD32(0x10C8 + r8);
                        c28 = (r1 & r1) == 0;
                        r1 = 2;
                        if (c28) {
                            r6 = LD32(sp - 44);
                            r0 = GCALL7(0x06015A5C, r8, r10, r6, r14, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        } else {
                            r2 = LD32(0x10CC + r8);
                            if (r2 > r1) {
                                r6 = LD32(sp - 44);
                                r0 = GCALL7(0x06015A5C, r8, r10, r6, r14, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                            }
                        }
                    }
                }
            }
            r0 = GCALL7(0x0601E884, r8, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
            r0 = LD32(sp);
        }
    } else {
        ST32((sp - 48), 0);
        r6 = LD32(sp - 44);
        r0 = GCALL7(0x060159A4, r8, r10, r6, r14, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
        r9 = r8 + 88;
        r0 = LD32(r9);
        ST32(sp - 36, r0);
        r0 = GCALL8(0x0601E884, r8, 0, 0, 0, LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
        r1 = LD32(r8 + 136);
        if (!((r1 & r1) == 0)) {
            r1 = LD32(0x10C8 + r8);
            if ((r1 & r1) == 0) {
                r3 = LD32(r9);
                r0 = r10;
                if (!((r3 & r3) == 0)) {
                    r2 = LD16(r0 + 218);
                    r12 = LD32(sp - 44);
                    r1 = LD16(r0 + 216);
                    ST16((r3 + 4), (r1 + (r2 + r12)));
                    r3 = LD32(r9);
                    r1 = LD16(r0 + 220);
                    r2 = LD16(r0 + 216);
                    ST32(r3 + 16, ((r1 + r14) + r2));
                    r1 = LD32(r9);
                    ST16((r1 + 6), r13);
                    r1 = LD32(r9);
                    ST32(r1 + 20, r11);
                    r0 = LD32(sp - 36);
                    r2 = r0;
                    if (!((r0 & r0) == 0)) {
                        r1 = LD32(r9);
                        r2 = LD8((r2 + 10));
                        ST8((r1 + 10), r2);
                        r2 = LD32(r9);
                        r1 = LD32(r0 + 28);
                        ST32(r2 + 28, r1);
                    }
                }
            } else {
                r0 = LD32(0x10CC + r8);
                if (r0 == 3) {
                    r3 = LD32(r9);
                    r0 = r10;
                    if (!((r3 & r3) == 0)) {
                        r2 = LD16(r0 + 218);
                        r12 = LD32(sp - 44);
                        r1 = LD16(r0 + 216);
                        ST16((r3 + 4), (r1 + (r2 + r12)));
                        r3 = LD32(r9);
                        r1 = LD16(r0 + 220);
                        r2 = LD16(r0 + 216);
                        ST32(r3 + 16, ((r1 + r14) + r2));
                        r1 = LD32(r9);
                        ST16((r1 + 6), r13);
                        r1 = LD32(r9);
                        ST32(r1 + 20, r11);
                        r0 = LD32(sp - 36);
                        r2 = r0;
                        if (!((r0 & r0) == 0)) {
                            r1 = LD32(r9);
                            r2 = LD8((r2 + 10));
                            ST8((r1 + 10), r2);
                            r2 = LD32(r9);
                            r1 = LD32(r0 + 28);
                            ST32(r2 + 28, r1);
                        }
                    }
                }
            }
        }
        r1 = LD32(0x20000014 + r10);
        r3 = LD32(sp - 40);
        if ((r1 & r1) == 0) {
            r3 = r3 + r14;
            r1 = LD32(r8 + 28);
            if ((r3 + r11) >= r1) {
                r1 = LD32(r8 + 24);
                if (!(r3 >= r1)) {
                    r1 = LD32(0x10C8 + r8);
                    c28 = (r1 & r1) == 0;
                    r1 = 2;
                    if (c28) {
                        r6 = LD32(sp - 44);
                        r0 = GCALL7(0x06015A5C, r8, r10, r6, r14, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                    } else {
                        r2 = LD32(0x10CC + r8);
                        if (r2 > r1) {
                            r6 = LD32(sp - 44);
                            r0 = GCALL7(0x06015A5C, r8, r10, r6, r14, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        }
                    }
                }
            }
        }
        r0 = GCALL7(0x0601E884, r8, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
        r0 = LD32(sp);
    }
    c31 = r0 == 2;
    if (!(r0 == 1)) {
        r2 = r8;
        if (!(c31)) {
            r12 = LD32(sp);
            if ((r12 & r12) == 0) {
                r1 = LD32(r8 + 8);
                r2 = r1 + r13;
                r1 = LD32((r8 + 68));
                if (r2 >= r1) {
                    r1 = LD32(r8 + 12);
                    ST32(r8 + 12, (r1 + r11));
                    r1 = LD32((r8 + 64));
                    ST32(r8 + 8, r1);
                } else {
                    ST32(r8 + 8, r2);
                    r7 = LD32(r8 + 12);
                    r5 = LD32((r8 + 64));
                    r0 = GCALL7(0x0601B028, r8, (r5 + r13), -1, (r7 + r11), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                }
            }
        } else {
            r2 = r2 + 64;
            r1 = LD32(r2);
            ST32(r8 + 8, r1);
            r1 = LD32((r8 + 68));
            r6 = r1 - r13;
            r1 = LD32(r2);
            if (r1 >= r6) {
                r1 = LD32(r8 + 12);
                ST32(r8 + 12, (r1 + r11));
            } else {
                r7 = LD32(r8 + 12);
                r0 = GCALL7(0x0601B028, r8, -1, r6, (r7 + r11), LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601DD34(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, c4, c1010;

    r1 = LD32(r4 + 32);
    r2 = LD32(r5 + 32);
    r7 = 1;
    if (!(r1 >= r2)) {
        ST32(r4 + 32, r2);
    }
    r3 = LD32(r4 + 36);
    r1 = LD32(r4 + 32);
    r2 = LD32(r5 + 32);
    r3 = r3 - r1;
    r1 = LD32(r5 + 36);
    if (!(r3 >= (r1 - r2))) {
        r1 = LD8(r6);
        r1 = r1 & 255;
        if ((r1 & r1) == 0) {
            c1010 = (r7 & r7) == 0;
        } else {
            r2 = 32;
            r3 = 0x06075135;
            r0 = r1;
            while (1) {
                r8 = LD8(r0 + r3);
                c4 = (unsigned)r1 > (unsigned)r2;
                if (!(((r8 & 8) & (r8 & 8)) == 0)) {
                    r6 = r6 + 1;
                    r1 = LD8(r6);
                    r1 = r1 & 255;
                    r0 = r1;
                    if (!((r1 & r1) == 0)) {
                        POLL();
                        continue;
                    } else {
                        c1010 = (r7 & r7) == 0;
                        break;
                    }
                } else {
                    if (!(c4)) {
                        r6 = r6 + 1;
                        r1 = LD8(r6);
                        r1 = r1 & 255;
                        r0 = r1;
                        if (!((r1 & r1) == 0)) {
                            POLL();
                            continue;
                        } else {
                            c1010 = (r7 & r7) == 0;
                            break;
                        }
                    } else {
                        c1010 = 0 == 0;
                        break;
                    }
                }
                POLL();
            }
        }
        if (c1010) {
            r1 = LD32(r5 + 36);
            r2 = LD32(r5 + 32);
            r1 = r1 - r2;
            r2 = LD32(r4 + 32);
            ST32(r4 + 36, (r1 + r2));
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06014638(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, c2, c7, c1006;
    FRAME(sp, 8);

    r1 = LD32(sp);
    r8 = r1 & 255;
    r1 = LD32(r4 + 16);
    r7 = r7 + r1;
    r1 = LD32(r4 + 28);
    r3 = LD32(r4 + 40);
    if (r7 >= r1) {
        r1 = LD32(r4 + 24);
        if (!(r7 >= r1)) {
            r1 = LD32(0x10C8 + r4);
            c2 = (r1 & r1) == 0;
            r1 = 2;
            if (c2) {
                c1006 = r5 >= 0;
                if (r5 > r6) {
                    r1 = r5;
                    r5 = r6;
                    r6 = r1;
                    c1006 = r5 >= 0;
                }
                if (!(c1006)) {
                    r5 = 0;
                }
                r4 = LD32(r4 + 44);
                c7 = r6 >= r4;
                r6 = r6 - r5;
                if (c7) {
                    r6 = (r4 - 1) - r5;
                }
                r0 = GCALL3(0x0604B3F0, (r3 + ((r7 * r4) + r5)), r8, (r6 + 1));
            } else {
                r2 = LD32(0x10CC + r4);
                if (r2 > r1) {
                    c1006 = r5 >= 0;
                    if (r5 > r6) {
                        r1 = r5;
                        r5 = r6;
                        r6 = r1;
                        c1006 = r5 >= 0;
                    }
                    if (!(c1006)) {
                        r5 = 0;
                    }
                    r4 = LD32(r4 + 44);
                    c7 = r6 >= r4;
                    r6 = r6 - r5;
                    if (c7) {
                        r6 = (r4 - 1) - r5;
                    }
                    r0 = GCALL3(0x0604B3F0, (r3 + ((r7 * r4) + r5)), r8, (r6 + 1));
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06015154(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c4, c6, c1006, c1017;
    FRAME(sp, 40);

    r10 = r4;
    r14 = r5;
    r8 = r6;
    r1 = LD32(sp + 4);
    r13 = r7;
    r11 = LD32(sp);
    ST32(sp - 36, ((signed char)r1));
    r9 = LD32(r10 + 16);
    r1 = LD32(136 + r10);
    r12 = r9 + r11;
    if ((r1 & r1) == 0) {
        r1 = LD32(r10 + 28);
        r0 = 1;
        if (r12 >= r1) {
            r1 = LD32(0x10C8 + r10);
            c6 = (r1 & r1) == 0;
            r1 = 2;
            if (c6) {
                r1 = LD32(r10 + 28);
                r2 = r9 + r8;
                r3 = r1;
                if (r2 >= r1) {
                    r9 = r8;
                    r8 = r2;
                } else {
                    r9 = r3 - r9;
                    r8 = r1;
                }
                r1 = LD32(r10 + 24);
                r8 = r1 - r8;
                r0 = 1;
                if (r8 >= 0) {
                    c1017 = r8 > 0;
                    if (((r9 + r8) + 1) > r11) {
                        r8 = (r11 - r9) + 1;
                        c1017 = r8 > 0;
                    }
                    r0 = 1;
                    if (c1017) {
                        r0 = LD8(3 + (sp - 36));
                        r11 = r0 & 255;
                        r12 = 0x06014638;
                        do {
                            ST32((sp - 40), r11);
                            r0 = GCALL6(r12, r10, r14, r13, r9, LD32((sp - 40)), LD32((sp - 36)));
                            r8 = r8 - 1;
                            r9 = r9 + 1;
                        } while (AGAIN(r8 > 0));
                        r0 = 1;
                    }
                }
            } else {
                r2 = LD32(0x10CC + r10);
                r0 = 1;
                if (r2 > r1) {
                    r1 = LD32(r10 + 28);
                    r2 = r9 + r8;
                    r3 = r1;
                    if (r2 >= r1) {
                        r9 = r8;
                        r8 = r2;
                    } else {
                        r9 = r3 - r9;
                        r8 = r1;
                    }
                    r1 = LD32(r10 + 24);
                    r8 = r1 - r8;
                    r0 = 1;
                    if (r8 >= 0) {
                        c1017 = r8 > 0;
                        if (((r9 + r8) + 1) > r11) {
                            r8 = (r11 - r9) + 1;
                            c1017 = r8 > 0;
                        }
                        r0 = 1;
                        if (c1017) {
                            r0 = LD8(3 + (sp - 36));
                            r11 = r0 & 255;
                            r12 = 0x06014638;
                            do {
                                ST32((sp - 40), r11);
                                r0 = GCALL6(r12, r10, r14, r13, r9, LD32((sp - 40)), LD32((sp - 36)));
                                r8 = r8 - 1;
                                r9 = r9 + 1;
                            } while (AGAIN(r8 > 0));
                            r0 = 1;
                        }
                    }
                }
            }
        }
    } else {
        r1 = LD32(0x10C8 + r10);
        if ((r1 & r1) == 0) {
            r0 = GCALL5(0x06015D00, r10, 40, 0, 0, LD32((sp - 36)));
            r5 = 2;
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r0 = GCALL5(0x06013C60, r10, r5, 0, 0, LD32((sp - 36)));
                r7 = r0;
                ST32(r7 + 4, 0);
                ST16((r7 + 24), r14);
                ST32(r7 + 28, r8);
                ST16((r7 + 26), r13);
                ST32(r7 + 32, r11);
                ST32(r7 + 12, r8);
                ST32(r7 + 16, r11);
                r2 = 148;
                r3 = LD16((2 + (sp - 36)));
                ST16((r7 + 36), r3);
                r1 = LD32(r10 + 148);
                c4 = (r1 & r1) == 0;
                c1006 = c4;
                if (!(c4)) {
                    ST32(r1, r7);
                    c1006 = 0;
                }
                r0 = r10;
                ST32(r0 + r2, (r7 + 4));
                r1 = LD32(r0 + 152);
                ST32(r0 + 152, (r1 + 40));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                r1 = LD32(r10 + 28);
                r0 = 1;
                if (r12 >= r1) {
                    r1 = LD32(0x10C8 + r10);
                    c6 = (r1 & r1) == 0;
                    r1 = 2;
                    if (c6) {
                        r1 = LD32(r10 + 28);
                        r2 = r9 + r8;
                        r3 = r1;
                        if (r2 >= r1) {
                            r9 = r8;
                            r8 = r2;
                        } else {
                            r9 = r3 - r9;
                            r8 = r1;
                        }
                        r1 = LD32(r10 + 24);
                        r8 = r1 - r8;
                        r0 = 1;
                        if (r8 >= 0) {
                            c1017 = r8 > 0;
                            if (((r9 + r8) + 1) > r11) {
                                r8 = (r11 - r9) + 1;
                                c1017 = r8 > 0;
                            }
                            r0 = 1;
                            if (c1017) {
                                r0 = LD8(3 + (sp - 36));
                                r11 = r0 & 255;
                                r12 = 0x06014638;
                                do {
                                    ST32((sp - 40), r11);
                                    r0 = GCALL6(r12, r10, r14, r13, r9, LD32((sp - 40)), LD32((sp - 36)));
                                    r8 = r8 - 1;
                                    r9 = r9 + 1;
                                } while (AGAIN(r8 > 0));
                                r0 = 1;
                            }
                        }
                    } else {
                        r2 = LD32(0x10CC + r10);
                        r0 = 1;
                        if (r2 > r1) {
                            r1 = LD32(r10 + 28);
                            r2 = r9 + r8;
                            r3 = r1;
                            if (r2 >= r1) {
                                r9 = r8;
                                r8 = r2;
                            } else {
                                r9 = r3 - r9;
                                r8 = r1;
                            }
                            r1 = LD32(r10 + 24);
                            r8 = r1 - r8;
                            r0 = 1;
                            if (r8 >= 0) {
                                c1017 = r8 > 0;
                                if (((r9 + r8) + 1) > r11) {
                                    r8 = (r11 - r9) + 1;
                                    c1017 = r8 > 0;
                                }
                                r0 = 1;
                                if (c1017) {
                                    r0 = LD8(3 + (sp - 36));
                                    r11 = r0 & 255;
                                    r12 = 0x06014638;
                                    do {
                                        ST32((sp - 40), r11);
                                        r0 = GCALL6(r12, r10, r14, r13, r9, LD32((sp - 40)), LD32((sp - 36)));
                                        r8 = r8 - 1;
                                        r9 = r9 + 1;
                                    } while (AGAIN(r8 > 0));
                                    r0 = 1;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            r0 = LD32(0x10CC + r10);
            if (!(r0 == 3)) {
                r1 = LD32(r10 + 28);
                r0 = 1;
                if (r12 >= r1) {
                    r1 = LD32(0x10C8 + r10);
                    c6 = (r1 & r1) == 0;
                    r1 = 2;
                    if (c6) {
                        r1 = LD32(r10 + 28);
                        r2 = r9 + r8;
                        r3 = r1;
                        if (r2 >= r1) {
                            r9 = r8;
                            r8 = r2;
                        } else {
                            r9 = r3 - r9;
                            r8 = r1;
                        }
                        r1 = LD32(r10 + 24);
                        r8 = r1 - r8;
                        r0 = 1;
                        if (r8 >= 0) {
                            c1017 = r8 > 0;
                            if (((r9 + r8) + 1) > r11) {
                                r8 = (r11 - r9) + 1;
                                c1017 = r8 > 0;
                            }
                            r0 = 1;
                            if (c1017) {
                                r0 = LD8(3 + (sp - 36));
                                r11 = r0 & 255;
                                r12 = 0x06014638;
                                do {
                                    ST32((sp - 40), r11);
                                    r0 = GCALL6(r12, r10, r14, r13, r9, LD32((sp - 40)), LD32((sp - 36)));
                                    r8 = r8 - 1;
                                    r9 = r9 + 1;
                                } while (AGAIN(r8 > 0));
                                r0 = 1;
                            }
                        }
                    } else {
                        r2 = LD32(0x10CC + r10);
                        r0 = 1;
                        if (r2 > r1) {
                            r1 = LD32(r10 + 28);
                            r2 = r9 + r8;
                            r3 = r1;
                            if (r2 >= r1) {
                                r9 = r8;
                                r8 = r2;
                            } else {
                                r9 = r3 - r9;
                                r8 = r1;
                            }
                            r1 = LD32(r10 + 24);
                            r8 = r1 - r8;
                            r0 = 1;
                            if (r8 >= 0) {
                                c1017 = r8 > 0;
                                if (((r9 + r8) + 1) > r11) {
                                    r8 = (r11 - r9) + 1;
                                    c1017 = r8 > 0;
                                }
                                r0 = 1;
                                if (c1017) {
                                    r0 = LD8(3 + (sp - 36));
                                    r11 = r0 & 255;
                                    r12 = 0x06014638;
                                    do {
                                        ST32((sp - 40), r11);
                                        r0 = GCALL6(r12, r10, r14, r13, r9, LD32((sp - 40)), LD32((sp - 36)));
                                        r8 = r8 - 1;
                                        r9 = r9 + 1;
                                    } while (AGAIN(r8 > 0));
                                    r0 = 1;
                                }
                            }
                        }
                    }
                }
            } else {
                r0 = GCALL5(0x06015D00, r10, 40, 0, 0, LD32((sp - 36)));
                r5 = 2;
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r0 = GCALL5(0x06013C60, r10, r5, 0, 0, LD32((sp - 36)));
                    r7 = r0;
                    ST32(r7 + 4, 0);
                    ST16((r7 + 24), r14);
                    ST32(r7 + 28, r8);
                    ST16((r7 + 26), r13);
                    ST32(r7 + 32, r11);
                    ST32(r7 + 12, r8);
                    ST32(r7 + 16, r11);
                    r2 = 148;
                    r3 = LD16((2 + (sp - 36)));
                    ST16((r7 + 36), r3);
                    r1 = LD32(r10 + 148);
                    c4 = (r1 & r1) == 0;
                    c1006 = c4;
                    if (!(c4)) {
                        ST32(r1, r7);
                        c1006 = 0;
                    }
                    r0 = r10;
                    ST32(r0 + r2, (r7 + 4));
                    r1 = LD32(r0 + 152);
                    ST32(r0 + 152, (r1 + 40));
                    r1 = LD32(r0 + 164);
                    ST32(r0 + 164, (r1 + 1));
                    r1 = LD32(r10 + 28);
                    r0 = 1;
                    if (r12 >= r1) {
                        r1 = LD32(0x10C8 + r10);
                        c6 = (r1 & r1) == 0;
                        r1 = 2;
                        if (c6) {
                            r1 = LD32(r10 + 28);
                            r2 = r9 + r8;
                            r3 = r1;
                            if (r2 >= r1) {
                                r9 = r8;
                                r8 = r2;
                            } else {
                                r9 = r3 - r9;
                                r8 = r1;
                            }
                            r1 = LD32(r10 + 24);
                            r8 = r1 - r8;
                            r0 = 1;
                            if (r8 >= 0) {
                                c1017 = r8 > 0;
                                if (((r9 + r8) + 1) > r11) {
                                    r8 = (r11 - r9) + 1;
                                    c1017 = r8 > 0;
                                }
                                r0 = 1;
                                if (c1017) {
                                    r0 = LD8(3 + (sp - 36));
                                    r11 = r0 & 255;
                                    r12 = 0x06014638;
                                    do {
                                        ST32((sp - 40), r11);
                                        r0 = GCALL6(r12, r10, r14, r13, r9, LD32((sp - 40)), LD32((sp - 36)));
                                        r8 = r8 - 1;
                                        r9 = r9 + 1;
                                    } while (AGAIN(r8 > 0));
                                    r0 = 1;
                                }
                            }
                        } else {
                            r2 = LD32(0x10CC + r10);
                            r0 = 1;
                            if (r2 > r1) {
                                r1 = LD32(r10 + 28);
                                r2 = r9 + r8;
                                r3 = r1;
                                if (r2 >= r1) {
                                    r9 = r8;
                                    r8 = r2;
                                } else {
                                    r9 = r3 - r9;
                                    r8 = r1;
                                }
                                r1 = LD32(r10 + 24);
                                r8 = r1 - r8;
                                r0 = 1;
                                if (r8 >= 0) {
                                    c1017 = r8 > 0;
                                    if (((r9 + r8) + 1) > r11) {
                                        r8 = (r11 - r9) + 1;
                                        c1017 = r8 > 0;
                                    }
                                    r0 = 1;
                                    if (c1017) {
                                        r0 = LD8(3 + (sp - 36));
                                        r11 = r0 & 255;
                                        r12 = 0x06014638;
                                        do {
                                            ST32((sp - 40), r11);
                                            r0 = GCALL6(r12, r10, r14, r13, r9, LD32((sp - 40)), LD32((sp - 36)));
                                            r8 = r8 - 1;
                                            r9 = r9 + 1;
                                        } while (AGAIN(r8 > 0));
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
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060161C4(int r4)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, c1012;

    r12 = r4;
    r0 = 144;
    r9 = LD32(144 + r12);
    if (!((r9 & r9) == 0)) {
        r13 = 0x06015A5C;
        do {
            r2 = LD32(r9);
            r10 = 0;
            if (!((unsigned)r2 > (unsigned)14)) {
                r1 = LD16(0x060161F8 + (r2 + r2));
                r0 = 0x060161F8 + r1;
                switch (r1) {
                case 136:
                    break;
                case 30:
                    r8 = LD32(r9 + 36);
                    r0 = GCALL1(0x06025AE0, r8);
                    r2 = LD16((r9 + 26));
                    r1 = LD32(196 + r8);
                    r11 = r9;
                    if (r2 >= r1) {
                        r2 = LD32(r9 + 32);
                        r1 = LD32(200 + r8);
                        if (r2 >= r1) {
                            r10 = 1;
                        }
                    }
                    r0 = GCALL1(0x06025AB4, r8);
                    r1 = LD32(r11 + 36);
                    r1 = LD32(r1 + 28);
                    if ((r1 & r1) == 0) {
                        c1012 = 0 == 0;
                    } else {
                        r0 = 236;
                        r4 = LD32(236 + r8);
                        c1012 = (r10 & r10) == 0;
                        if (!((r4 & r4) == 0)) {
                            r0 = GCALL1(0x06020DCC, r4);
                            c1012 = (r10 & r10) == 0;
                            if (!((r0 & r0) == 0)) {
                                r1 = LD32(240 + r8);
                                r0 = 0x328;
                                r1 = LD32(0x328 + r1);
                                c1012 = (r10 & r10) == 0;
                                if ((r1 & r1) == 0) {
                                    c1012 = 0 == 0;
                                }
                            }
                        }
                    }
                    r1 = r11;
                    if (!(c1012)) {
                        r7 = LD32(r11 + 28);
                        r6 = LD16((r1 + 24));
                        r0 = GCALL4(r13, r12, r8, r6, r7);
                    }
                    break;
                }
            }
            r9 = LD32(r9 + 4);
        } while (AGAIN(!((r9 & r9) == 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06017D08(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c5, c1011;
    FRAME(sp, 20);

    r2 = LD32(sp);
    r8 = LD32(sp + 4);
    r11 = LD32(sp + 8);
    r10 = r4;
    r9 = LD32(sp + 12);
    if ((r7 & r7) == 0) {
        r0 = 1;
    } else {
        if ((r5 & r5) == 0) {
            r0 = 1;
        } else {
            r1 = LD32(r7 + 4);
            r3 = LD32(r5 + 4);
            if (!(r1 == 60)) {
                r0 = r3;
                c1011 = r0 == 61;
                r0 = 1;
                if (c1011) {
                    r0 = 1;
                    if (r1 == 61) {
                        r5 = LD32(0x10D4 + r10);
                        r0 = GCALL2(0x06017C80, r8, r5);
                        r9 = r9 - r11;
                        r0 = GCALL2(0x06028380, (r9 + 1), 8);
                        r8 = r0;
                        r6 = r9;
                        if ((r8 & r8) == 0) {
                            POLL();
                            r0 = 0;
                        } else {
                            r0 = GCALL3(0x0604B358, r8, r11, r6);
                            ST8(r8 + r9, 0);
                            r0 = GCALL2(0x06033D70, r10, r8);
                            r0 = GCALL1(0x06027F48, r8);
                            r0 = 0;
                        }
                    }
                }
            } else {
                r0 = r3;
                if (!((r2 & r2) == 0)) {
                    c1011 = r0 == 61;
                    r0 = 1;
                    if (c1011) {
                        r0 = 1;
                        if (r1 == 61) {
                            r5 = LD32(0x10D4 + r10);
                            r0 = GCALL2(0x06017C80, r8, r5);
                            r9 = r9 - r11;
                            r0 = GCALL2(0x06028380, (r9 + 1), 8);
                            r8 = r0;
                            r6 = r9;
                            if ((r8 & r8) == 0) {
                                POLL();
                                r0 = 0;
                            } else {
                                r0 = GCALL3(0x0604B358, r8, r11, r6);
                                ST8(r8 + r9, 0);
                                r0 = GCALL2(0x06033D70, r10, r8);
                                r0 = GCALL1(0x06027F48, r8);
                                r0 = 0;
                            }
                        }
                    }
                } else {
                    c5 = r0 == 59;
                    if (r0 == 60) {
                        r5 = LD32(0x10D4 + r10);
                        r0 = GCALL2(0x06017C80, r8, r5);
                        r0 = GCALL2(0x06033CA8, r10, r8);
                        r0 = 0;
                    } else {
                        c1011 = r0 == 61;
                        if (!(c5)) {
                            r0 = 1;
                            if (c1011) {
                                r0 = 1;
                                if (r1 == 61) {
                                    r5 = LD32(0x10D4 + r10);
                                    r0 = GCALL2(0x06017C80, r8, r5);
                                    r9 = r9 - r11;
                                    r0 = GCALL2(0x06028380, (r9 + 1), 8);
                                    r8 = r0;
                                    r6 = r9;
                                    if ((r8 & r8) == 0) {
                                        POLL();
                                        r0 = 0;
                                    } else {
                                        r0 = GCALL3(0x0604B358, r8, r11, r6);
                                        ST8(r8 + r9, 0);
                                        r0 = GCALL2(0x06033D70, r10, r8);
                                        r0 = GCALL1(0x06027F48, r8);
                                        r0 = 0;
                                    }
                                }
                            }
                        } else {
                            c1011 = r0 == 61;
                            if ((r6 & r6) == 0) {
                                r0 = 1;
                                if (c1011) {
                                    r0 = 1;
                                    if (r1 == 61) {
                                        r5 = LD32(0x10D4 + r10);
                                        r0 = GCALL2(0x06017C80, r8, r5);
                                        r9 = r9 - r11;
                                        r0 = GCALL2(0x06028380, (r9 + 1), 8);
                                        r8 = r0;
                                        r6 = r9;
                                        if ((r8 & r8) == 0) {
                                            POLL();
                                            r0 = 0;
                                        } else {
                                            r0 = GCALL3(0x0604B358, r8, r11, r6);
                                            ST8(r8 + r9, 0);
                                            r0 = GCALL2(0x06033D70, r10, r8);
                                            r0 = GCALL1(0x06027F48, r8);
                                            r0 = 0;
                                        }
                                    }
                                }
                            } else {
                                r5 = LD32(0x10D4 + r10);
                                r0 = GCALL2(0x06017C80, r8, r5);
                                r0 = GCALL2(0x06033CA8, r10, r8);
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
int f06018588(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, c7, c1014;

    r11 = r5;
    r10 = r6;
    r9 = r7;
    if ((r11 & r11) == 0) {
        r0 = 0;
    } else {
        r1 = 0;
        if (!((r10 & r10) == 0)) {
            ST32(r9, r1);
            r8 = r4;
            if ((r10 & r10) == 0) {
                r0 = GCALL3(0x060750A0, r4, 0x06018570, 9);
                r8 = r8 + 9;
            }
            r2 = r11;
            r1 = LD8(r2);
            r0 = r1 & 255;
            c1014 = (r10 & r10) == 0;
            if (!((r0 & r0) == 0)) {
                r1 = 0x06075135;
                r0 = LD8(r0 + 0x06075135);
                c7 = (r10 & r10) == 0;
                c1014 = c7;
                if (((r0 & 8) & (r0 & 8)) == 0) {
                    r3 = r1;
                    while (1) {
                        r1 = LD32(r9);
                        ST32(r9, (r1 + 1));
                        if ((r10 & r10) == 0) {
                            r1 = LD8(r2);
                            ST8(r8, r1);
                            r8 = r8 + 1;
                        }
                        r2 = r2 + 1;
                        r1 = LD8(r2);
                        r0 = r1 & 255;
                        if ((r0 & r0) == 0) {
                            break;
                        } else {
                            r0 = LD8(r0 + r3);
                            if (((r0 & 8) & (r0 & 8)) == 0) {
                                POLL();
                                continue;
                            } else {
                                break;
                            }
                        }
                        POLL();
                    }
                    c1014 = (r10 & r10) == 0;
                }
            }
            r0 = 1;
            if (c1014) {
                r0 = GCALL3(0x060750A0, r8, 0x0601857C, 2);
                r2 = r11;
                r1 = LD8(r2);
                r0 = r1 & 255;
                r8 = r8 + 2;
                if (!((r0 & r0) == 0)) {
                    r3 = 0x06075135;
                    while (1) {
                        r0 = LD8(r0 + r3);
                        if (!(((r0 & 8) & (r0 & 8)) == 0)) {
                            break;
                        } else {
                            ST8(r8, r1);
                            r2 = r2 + 1;
                            r1 = LD8(r2);
                            r0 = r1 & 255;
                            r8 = r8 + 1;
                            if (!((r0 & r0) == 0)) {
                                POLL();
                                continue;
                            } else {
                                break;
                            }
                        }
                        POLL();
                    }
                }
                r0 = GCALL3(0x060750A0, r8, 0x06018580, 4);
                ST8((r8 + 4), 0);
                r0 = 1;
            }
        } else {
            if (!((r4 & r4) == 0)) {
                ST32(r9, r1);
                r8 = r4;
                if ((r10 & r10) == 0) {
                    r0 = GCALL3(0x060750A0, r4, 0x06018570, 9);
                    r8 = r8 + 9;
                }
                r2 = r11;
                r1 = LD8(r2);
                r0 = r1 & 255;
                c1014 = (r10 & r10) == 0;
                if (!((r0 & r0) == 0)) {
                    r1 = 0x06075135;
                    r0 = LD8(r0 + 0x06075135);
                    c7 = (r10 & r10) == 0;
                    c1014 = c7;
                    if (((r0 & 8) & (r0 & 8)) == 0) {
                        r3 = r1;
                        while (1) {
                            r1 = LD32(r9);
                            ST32(r9, (r1 + 1));
                            if ((r10 & r10) == 0) {
                                r1 = LD8(r2);
                                ST8(r8, r1);
                                r8 = r8 + 1;
                            }
                            r2 = r2 + 1;
                            r1 = LD8(r2);
                            r0 = r1 & 255;
                            if ((r0 & r0) == 0) {
                                break;
                            } else {
                                r0 = LD8(r0 + r3);
                                if (((r0 & 8) & (r0 & 8)) == 0) {
                                    POLL();
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            POLL();
                        }
                        c1014 = (r10 & r10) == 0;
                    }
                }
                r0 = 1;
                if (c1014) {
                    r0 = GCALL3(0x060750A0, r8, 0x0601857C, 2);
                    r2 = r11;
                    r1 = LD8(r2);
                    r0 = r1 & 255;
                    r8 = r8 + 2;
                    if (!((r0 & r0) == 0)) {
                        r3 = 0x06075135;
                        while (1) {
                            r0 = LD8(r0 + r3);
                            if (!(((r0 & 8) & (r0 & 8)) == 0)) {
                                break;
                            } else {
                                ST8(r8, r1);
                                r2 = r2 + 1;
                                r1 = LD8(r2);
                                r0 = r1 & 255;
                                r8 = r8 + 1;
                                if (!((r0 & r0) == 0)) {
                                    POLL();
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            POLL();
                        }
                    }
                    r0 = GCALL3(0x060750A0, r8, 0x06018580, 4);
                    ST8((r8 + 4), 0);
                    r0 = 1;
                }
            } else {
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601897C(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, c1, c1005;

    r9 = r4;
    r8 = r5;
    r10 = r6;
    r0 = GCALL1(0x0607507C, r4);
    r3 = r0;
    r1 = r3;
    while (1) {
        r1 = r1 - 1;
        if (r1 >= 0) {
            POLL();
            r2 = LD8(r9 + r1);
            r0 = r2;
            c1 = r0 == 47;
            if (r0 == 92) {
                c1005 = r1 >= 0;
                break;
            } else {
                c1005 = r1 >= 0;
                if (c1) {
                    break;
                } else {
                    continue;
                }
            }
        } else {
            c1005 = r1 >= 0;
            break;
        }
    }
    r7 = 0;
    if (c1005) {
        r7 = r1 + 1;
    }
    r1 = r7;
    if ((r3 - r7) > (r10 - 1)) {
        r3 = (r10 + r7) - 1;
        r1 = r7;
    }
    r0 = r9;
    if (!(r1 >= r3)) {
        do {
            r2 = LD8(r0 + r1);
            if (!(((signed char)r2) == 34)) {
                ST8(r8, r2);
                r8 = r8 + 1;
            }
            r1 = r1 + 1;
            r0 = r9;
        } while (AGAIN(!(r1 >= r3)));
    }
    ST8(r8, 0);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060189FC(int r4, int r5)
{
    int r0, r1, r2, r3, r7, c6, c1003;

    r2 = 0;
    r1 = LD8(r4);
    r0 = (signed char)r1;
    r3 = 0;
    if (!((r0 & r0) == 0)) {
        if (!(r0 == 46)) {
            r7 = 7;
            c1003 = r2 > 7;
            while (!(c1003)) {
                ST8(r5, r1);
                r4 = r4 + 1;
                r5 = r5 + 1;
                r1 = LD8(r4);
                r0 = (signed char)r1;
                r2 = r2 + 1;
                if ((r0 & r0) == 0) {
                    break;
                } else {
                    c1003 = r2 > r7;
                    if (!(r0 == 46)) {
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
    r1 = LD8(r4);
    c6 = (r1 & r1) == 0;
    r1 = 46;
    if (!(c6)) {
        ST8(r5, r1);
        r0 = LD8(r4);
        r5 = r5 + 1;
        if (!(r0 == 46)) {
            r4 = r4 + 1;
            do {
                r0 = LD8(r4);
                r4 = r4 + 1;
            } while (AGAIN(!(r0 == 46)));
            r4 = r4 - 1;
        }
        r4 = r4 + 1;
        r2 = LD8(r4);
        r7 = 2;
        if (!((((signed char)r2) & ((signed char)r2)) == 0)) {
            do {
                ST8(r5, r2);
                r4 = r4 + 1;
                r5 = r5 + 1;
                r2 = LD8(r4);
                r3 = r3 + 1;
            } while (AGAIN(!((((signed char)r2) & ((signed char)r2)) == 0)));
        }
        ST8(r5, 0);
        return 1;
    } else {
        ST8(r5, 0);
        return 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601B098(int r4)
{
    int r0, r1, r2, r5, r9, r10, r11, r12, r13, c0, c1005;

    r10 = r4;
    r4 = LD32((r10 + 80));
    c0 = (r4 & r4) == 0;
    r11 = 0;
    c1005 = c0;
    if (!(c0)) {
        r2 = 0x7FFFFFFF;
        while (1) {
            r1 = LD32(r4);
            if (r1 == r2) {
                break;
            } else {
                r4 = LD32(r4 + 12);
                if (!((r4 & r4) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        c1005 = (r4 & r4) == 0;
    }
    r9 = r10;
    if (!(c1005)) {
        r9 = r9 + 80;
        r1 = LD32(r9);
        r12 = r10;
        if (!((r1 & r1) == 0)) {
            r12 = r12 + 64;
            r13 = 0x06027F48;
            do {
                r4 = LD32(r9);
                r1 = LD32(r4 + 12);
                ST32(r9, r1);
                r1 = r4;
                r11 = LD32(r1);
                r1 = LD16((r1 + 4));
                ST32(r12, r1);
                ST32(r10 + 8, r1);
                r0 = GCALL1(r13, r4);
                r1 = LD32(r9);
            } while (AGAIN(!((r1 & r1) == 0)));
        }
    }
    r5 = LD32((r10 + 64));
    r0 = GCALL4(0x0601B028, r10, r5, -1, 0x7FFFFFFF);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601B188(int r4)
{
    int r1, r2, r3, r7, c0, c1005, c1010;

    r2 = LD32((r4 + 80));
    c0 = (r2 & r2) == 0;
    r3 = 0;
    c1005 = c0;
    if (!(c0)) {
        r7 = 0x7FFFFFFF;
        while (1) {
            r1 = LD32(r2);
            if (r1 == r7) {
                break;
            } else {
                r2 = LD32(r2 + 12);
                if (!((r2 & r2) == 0)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        c1005 = (r2 & r2) == 0;
    }
    r1 = r4;
    if (!(c1005)) {
        r2 = LD32((r1 + 80));
        if (!((r2 & r2) == 0)) {
            r7 = 0x7FFFFFFF;
            c1010 = r3 == 0x7FFFFFFF;
            while (1) {
                r1 = r2;
                if (c1010) {
                    break;
                } else {
                    r1 = LD16((r1 + 8));
                    r3 = LD32(r2);
                    if (r1 >= 0) {
                        POLL();
                        r2 = LD16((r2 + 4));
                        ST32((r4 + 64), r2);
                        ST32(r4 + 8, r2);
                        break;
                    } else {
                        r2 = LD32(r2 + 12);
                        c1010 = r3 == r7;
                        if (!((r2 & r2) == 0)) {
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
        return 1;
    } else {
        return 0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CEEC(void)
{
    int r0, r1, r4, r8, r9, r10, r11, c1010;

    r0 = LD32(0x06000330);
    r0 = GCALL1(r0, 7);
    if (!((r0 & r0) == 0)) {
        r8 = LD32(0x060875C8);
        r10 = 0;
        if (!((r8 & r8) == 0)) {
            r11 = 0x06027F48;
            do {
                r1 = LD32(r8 + 48);
                r9 = LD32(r8 + 52);
                if (!((r1 & r1) == 0)) {
                    c1010 = (r9 & r9) == 0;
                } else {
                    r1 = LD32(r8 + 56);
                    if (!((r1 & r1) == 0)) {
                        c1010 = (r9 & r9) == 0;
                    } else {
                        r4 = LD32(r8 + 12);
                        if (!((r4 & r4) == 0)) {
                            r0 = GCALL1(r11, r4);
                            ST32(r8 + 12, r10);
                        }
                        r4 = LD32(r8 + 16);
                        c1010 = (r9 & r9) == 0;
                        if (!((r4 & r4) == 0)) {
                            r0 = GCALL1(r11, r4);
                            ST32(r8 + 16, r10);
                            c1010 = (r9 & r9) == 0;
                        }
                    }
                }
                r8 = r9;
            } while (AGAIN(!(c1010)));
        }
        r0 = GCALL0(0x0601CB88);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601DC10(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12, r13, r14, c0, c1002;
    FRAME(sp, 288);

    r14 = r4;
    r11 = r6;
    r12 = r7;
    c0 = r11 > r12;
    r13 = r5;
    c1002 = c0;
    if (c0) {
        r0 = GCALL4(0x06045264, 0x0608B9D0, 0x0601DA84, r6, r7);
        r0 = GCALL1(0x0602BA00, 0x0608B9D0);
        ST32((sp - 292), r13);
        r0 = GCALL5(0x06045264, 0x0608B9D0, 0x0601DBF8, r11, r12, LD32((sp - 292)));
        r0 = GCALL5(0x0602BA00, 0x0608B9D0, 0, 0, 0, LD32((sp - 292)));
        c1002 = r11 > r12;
    }
    r10 = 0;
    if (!(c1002)) {
        do {
            r9 = (r12 - r11) + 1;
            r5 = r13;
            if (r9 > 255) {
                r9 = 255;
            }
            r0 = GCALL3(0x0604B358, (sp - 288), (r5 + r11), r9);
            ST8((sp - 288) + r9, 0);
            r8 = LD32(r14 + 0x10B4);
            r0 = GCALL1(0x0607507C, (sp - 288));
            ST32((sp - 292), (r0 - 1));
            r0 = GCALL5(0x0601CD5C, r14, r8, (sp - 288), 0, LD32((sp - 292)));
            r10 = r10 + r0;
            r11 = r11 + r9;
        } while (AGAIN(!(r11 > r12)));
    }
    return r10;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010850(int r4)
{
    int r0, r1, r2, r7, r8, r9, r10, r11, r12, r13, r14, c1, c1007;

    r14 = r4;
    r0 = SR();
    r7 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r0 = SR();
    r0 = r0 | 240;
    SETSR(r0);
    r8 = LD32(0x060766B8);
    r12 = LD32(0x060766BC);
    r11 = LD32(0x0607655C);
    ST32(0x060766B8, 0);
    ST32(0x060766C0, 0);
    ST32(0x060766BC, 0);
    ST32(0x0607655C, 0);
    r1 = SR();
    SETSR(((r1 & -241) | ((r7 << 2) << 2)));
    c1 = (r11 & r11) == 0;
    c1007 = c1;
    if (!((r8 & r8) == 0)) {
        r10 = 0x06027F48;
        do {
            r0 = LD32(r8 + 28);
            r9 = LD32(r8);
            if (!(r0 == -1)) {
                r4 = LD32(r8 + 36);
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(r10, r4);
                }
                r0 = GCALL1(r10, r8);
            }
            r8 = r9;
            c1007 = (r11 & r11) == 0;
        } while (AGAIN(!((r8 & r8) == 0)));
    }
    r2 = r14;
    if (!(c1007)) {
        r10 = 0x06027F48;
        do {
            r8 = LD32(r11);
            r13 = LD32(r11 + 4);
            if (!((r8 & r8) == 0)) {
                do {
                    r4 = LD32(r8 + 32);
                    r9 = LD32(r8 + 28);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(r10, r4);
                    }
                    r4 = LD32(r8 + 20);
                    if (!((r4 & r4) == 0)) {
                        r0 = GCALL1(r10, r4);
                    }
                    r0 = GCALL1(r10, r8);
                    r8 = r9;
                } while (AGAIN(!((r8 & r8) == 0)));
            }
            r0 = GCALL1(r10, r11);
            r11 = r13;
            r2 = r14;
        } while (AGAIN(!((r11 & r11) == 0)));
    }
    ST32((r2 + 96), 0);
    if (!((r12 & r12) == 0)) {
        r9 = 0x06027F48;
        do {
            r4 = LD32(r12);
            r8 = LD32(r12 + 8);
            r0 = GCALL1(r9, r4);
            r0 = GCALL1(r9, r12);
            r12 = r8;
        } while (AGAIN(!((r12 & r12) == 0)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601E7C0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11;
    FRAME(sp, 272);

    r10 = r4;
    r4 = r5;
    r8 = r6;
    r9 = r7;
    r11 = LD32(0x110 + (sp - 272));
    r7 = 0;
    r6 = 255;
    r5 = 0;
    do {
        r3 = LD32(r5 + r4);
        r2 = (((int)((unsigned)r3 >> 16)) & 255) + 15;
        r1 = (((int)((unsigned)r3 >> 8)) & 255) + 15;
        r3 = (r3 & 255) + 15;
        if ((unsigned)r2 > (unsigned)r6) {
            r2 = r6;
        }
        if ((unsigned)r1 > (unsigned)r6) {
            r1 = r6;
        }
        if ((unsigned)r3 > (unsigned)r6) {
            r3 = r6;
        }
        r0 = sp - 272;
        ST8(r0 + r7, (((((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1)) & 28) | (r2 & 224)) | (((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)) & 3)));
        r7 = r7 + 1;
        r5 = r5 + 4;
    } while (AGAIN(!(r7 > r6)));
    r5 = 0;
    r4 = r10;
    if (!(0 >= r9)) {
        do {
            if (!(0 >= r8)) {
                r2 = r4;
                r3 = r8 + r4;
                do {
                    r1 = LD8(r2);
                    r0 = r1 & 255;
                    r1 = LD8(r0 + (sp - 272));
                    ST8(r2, r1);
                    r2 = r2 + 1;
                } while (AGAIN(!(r2 >= r3)));
            }
            r5 = r5 + 1;
            r4 = r4 + r11;
        } while (AGAIN(!(r5 >= r9)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601EFE8(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, c0, c7, c8, c9, c1004;

    r8 = r4;
    r5 = (short)r5;
    r9 = (short)r6;
    r3 = 0;
    r7 = 1;
    r2 = 0;
    c0 = 0 >= r5;
    r6 = 8;
    c1004 = c0;
    if (!(c0)) {
        r4 = -1;
        do {
            r0 = r2 + r2;
            r2 = (short)(r2 + 1);
            ST16(r0 + r8, r4);
        } while (AGAIN(!(r2 >= r5)));
        r2 = 0;
        c1004 = 0 >= r5;
    }
    if (!(c1004)) {
        r4 = -2;
        do {
            r0 = r2 + r2;
            r2 = (short)(r2 + 8);
            ST16(r0 + r8, r4);
        } while (AGAIN(!(r2 >= r5)));
    }
    r2 = 0;
    r4 = 3;
    if (!(0 >= r9)) {
        r0 = r3;
        do {
            ST16((r0 + r0) + r8, r2);
            r3 = (short)(r3 + r6);
            while (1) {
                r1 = r2;
                if (!(r3 >= r5)) {
                    break;
                } else {
                    r7 = (short)(r7 + 1);
                    r0 = r7;
                    c7 = r7 > r4;
                    if (r0 == 3) {
                        r3 = 2;
                        r6 = 4;
                        POLL();
                        continue;
                    } else {
                        c8 = r0 == 2;
                        if (c7) {
                            c9 = r0 == 4;
                            r3 = c9;
                            if (c9) {
                                r6 = 2;
                                POLL();
                                continue;
                            } else {
                                r3 = 0;
                                r6 = 1;
                                POLL();
                                continue;
                            }
                        } else {
                            r3 = 4;
                            if (c8) {
                                r6 = 8;
                                POLL();
                                continue;
                            } else {
                                r3 = 0;
                                r6 = 1;
                            }
                        }
                    }
                }
                POLL();
            }
            r2 = (short)(r1 + 1);
            r0 = r3;
        } while (AGAIN(!(r2 >= r9)));
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601F088(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, c5;

    r1 = LD32(r4 + 4);
    r2 = r4;
    if (!((r1 & r1) == 0)) {
        r2 = r2 + 40;
        r1 = LD16(r2);
        r6 = 0;
        if (!(0 >= (r1 & 0xFFFF))) {
            r3 = 0;
            r0 = r6;
            do {
                r1 = LD32(r4 + 4);
                ST32((r0 << 2) + r1, r3);
                r1 = LD16(r2);
                r6 = r6 + 1;
                r0 = r6;
            } while (AGAIN(!(r6 >= (r1 & 0xFFFF))));
        }
        r7 = LD32(r4);
        r6 = 0;
        if (!((r7 & r7) == 0)) {
            r8 = r4 + 38;
            do {
                r1 = LD32(r7 + 8);
                r3 = 0;
                if (!(0 >= r1)) {
                    do {
                        r1 = LD16(r8);
                        c5 = r3 * (r1 & 0xFFFF);
                        r5 = LD32(r4 + 4);
                        r1 = LD32(r7 + 4);
                        ST32((r6 << 2) + r5, (r1 + c5));
                        r1 = LD32(r7 + 8);
                        r3 = r3 + 1;
                        r6 = r6 + 1;
                    } while (AGAIN(!(r3 >= r1)));
                }
                r7 = LD32(r7);
            } while (AGAIN(!((r7 & r7) == 0)));
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010368(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, c0, c2, c5, c1006;

    r9 = r4;
    r0 = SR();
    r7 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
    r5 = r7;
    r0 = SR();
    r3 = -241;
    r0 = r0 | 240;
    SETSR(r0);
    r6 = 0x060759B8;
    r1 = LD32(0x060759B8);
    c0 = r1 >= 0;
    r1 = 0;
    if (!(c0)) {
        ST32(0x060759C4, r1);
        ST32(r6, r1);
    }
    r1 = LD32(r9 + 20);
    r10 = 0x1FF;
    if (r1 > 0x1FF) {
        r2 = LD32(r6);
        r5 = 0x060759C0;
        r1 = LD32(0x060759C0);
        c2 = r2 > r1;
        c1006 = c2;
        if (c2) {
            r1 = LD32(r5);
            ST32(r6, r1);
            c1006 = 1;
        }
        r12 = LD32(r6);
        r1 = LD32(0x060759BC);
        r8 = r12 - r1;
        r1 = (SR() & ~1) | c1006;
        SETSR(((r1 & r3) | ((r7 << 2) << 2)));
        if (!((r8 & r8) == 0)) {
            r1 = LD32(0x060759D0);
            if ((r1 & r1) == 0) {
                r1 = LD32(r9 + 16);
                c5 = ((r1 + r12) & (r1 + r12)) == 0;
                r1 = 0;
                if (!(c5)) {
                    ST32(r9 + 28, r1);
                    ST32(r9 + 24, 16);
                    if (!(r8 > 0)) {
                        r1 = LD32(r9 + 16);
                        ST32(r9 + 16, (r1 + 16));
                        r0 = GCALL1(0x06015E54, r9);
                        r4 = r12;
                        r1 = LD32(r9 + 16);
                        ST32(r9 + 16, ((r1 - 16) - r8));
                        if (!(r12 >= 0)) {
                            r4 = r4 + r10;
                        }
                        r4 = HELPER((int)r4 >> 9);
                        r8 = r12 - ((r4 << 8) + (r4 << 8));
                        if (!(r8 >= 0)) {
                            r8 = r8 + 0x200;
                        }
                    } else {
                        r1 = LD32(r9 + 16);
                        ST32(r9 + 16, (r1 + -512));
                        r0 = GCALL1(0x06015E54, r9);
                        r1 = LD32(r9 + 16);
                        r2 = 0x200;
                        ST32(r9 + 16, ((r1 + 0x200) - r8));
                        r8 = r12 + 0x1F0;
                        r4 = r8;
                        if (!(r8 >= 0)) {
                            r4 = r4 + r10;
                        }
                        r4 = HELPER((int)r4 >> 9);
                        r8 = r8 - ((r4 << 8) + (r4 << 8));
                        if (!(r8 >= 0)) {
                            r8 = r8 + r2;
                        }
                    }
                    r2 = 0x0607599C;
                    r1 = LD32(0x0607599C);
                    if (!((r1 & r1) == 0)) {
                        r10 = r2;
                        r11 = 0x0605299C;
                        do {
                            r0 = GCALL0(r11);
                            r1 = LD32(r10);
                        } while (AGAIN(!((r1 & r1) == 0)));
                    }
                    r1 = LD32(r9 + 40);
                    ST32(0x060759A0, r1);
                    ST32(0x060759A4, 0x4000);
                    ST32(0x0607599C, (((r8 << 8) << 2) + 0x25E00000));
                    r1 = LD32(0x0607599C);
                    r8 = 0x0607599C;
                    if (!((r1 & r1) == 0)) {
                        r9 = 0x0605299C;
                        do {
                            r0 = GCALL0(r9);
                            r1 = LD32(r8);
                        } while (AGAIN(!((r1 & r1) == 0)));
                    }
                    ST32(0x060759D0, 1);
                    ST32(0x060759BC, r12);
                }
            }
        }
    } else {
        r1 = (SR() & ~1) | 0;
        SETSR(((r1 & r3) | ((r5 << 2) << 2)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060105B4(int r4, int r5, int r6, int r7)
{
    int r0, r1, c2, c4, c8, c11, c15, c16, c1032;

    r0 = r4;
    r1 = -602;
    if (r0 == -602) {
        r5 = 0x060516A0;
        r0 = GCALL4(0x06045264, 0x0608B860, r5, r6, r7);
        r0 = GCALL1(0x06010DDC, 24);
    } else {
        c2 = r0 == -12;
        if (r0 > r1) {
            r1 = -12;
            if (c2) {
                r0 = 0;
            } else {
                c11 = r0 == -1;
                if (r0 > r1) {
                    r1 = -1;
                    c1032 = c11;
                    if (c11) {
                        r5 = 0x06051798;
                        r0 = GCALL4(0x06045264, 0x0608B860, r5, r6, r7);
                        r0 = GCALL1(0x06010DDC, 24);
                    } else {
                        c15 = r0 == -3;
                        if (r0 > r1) {
                            c16 = (r0 & r0) == 0;
                            c1032 = c16;
                            if (!(c16)) {
                                r5 = 0x06051798;
                                r0 = GCALL4(0x06045264, 0x0608B860, r5, r6, r7);
                                r0 = GCALL1(0x06010DDC, 24);
                            } else {
                                r0 = 0;
                            }
                        } else {
                            if (c15) {
                                r5 = 0x0605174C;
                            } else {
                                c1032 = 0;
                                r5 = 0x06051798;
                            }
                            r0 = GCALL4(0x06045264, 0x0608B860, r5, r6, r7);
                            r0 = GCALL1(0x06010DDC, 24);
                        }
                    }
                } else {
                    if (r0 == -601) {
                        r5 = 0x060516A0;
                    } else {
                        if (r0 == -600) {
                            r5 = 0x06051630;
                        } else {
                            c1032 = 0;
                            r5 = 0x06051798;
                        }
                    }
                    r0 = GCALL4(0x06045264, 0x0608B860, r5, r6, r7);
                    r0 = GCALL1(0x06010DDC, 24);
                }
            }
        } else {
            c4 = r0 > -607;
            if (r0 == -607) {
                r5 = 0x06079BD0;
            } else {
                if (c4) {
                    c8 = r0 > -604;
                    if (r0 == -604) {
                        r5 = 0x06051710;
                    } else {
                        if (c8) {
                            r5 = 0x060515D8;
                        } else {
                            if (r0 == -605) {
                                r5 = 0x06079B98;
                            } else {
                                c1032 = 0;
                                r5 = 0x06051798;
                            }
                        }
                    }
                } else {
                    if (r0 == -1001) {
                        r5 = 0x06079C60;
                    } else {
                        if (r0 == -608) {
                            r5 = 0x06079CB8;
                        } else {
                            c1032 = 0;
                            r5 = 0x06051798;
                        }
                    }
                }
            }
            r0 = GCALL4(0x06045264, 0x0608B860, r5, r6, r7);
            r0 = GCALL1(0x06010DDC, 24);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010DDC(int r4)
{
    int r0, r1, r8, r9, r10, c2010;

    r10 = r4;
    if (!(r10 == 24)) {
        r1 = 0x06032164;
        r4 = 0;
    } else {
        r1 = 0x06032164;
        r4 = 2;
    }
    r0 = GCALL1(r1, r4);
    c2010 = R(10);
    SETR(10, r10);
    r0 = GCALL1(0x0602CDDC, r10);
    SETR(10, c2010);
    ST32(0x0607668C, 0);
    ST32(0x06076694, 0);
    r1 = LD32(0x060769D4);
    r8 = 0x060769D4;
    if (!((r1 & r1) == 0)) {
        r9 = 0x0605299C;
        do {
            r0 = GCALL0(r9);
            r1 = LD32(r8);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    r0 = GCALL1(0x06032164, 1);
    r0 = GCALL1(0x0602D5C0, r10);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010E54(int r4, int r5)
{
    int r0, r1, r8, r9, r10, c2010;

    r10 = r4;
    r8 = r5;
    if (!(r10 == 24)) {
        r1 = 0x06032164;
        r4 = 0;
    } else {
        r1 = 0x06032164;
        r4 = 2;
    }
    r0 = GCALL2(r1, r4, r5);
    c2010 = R(10);
    SETR(10, r10);
    r0 = GCALL1(0x0602CDDC, r10);
    SETR(10, c2010);
    ST32(0x0607668C, 0);
    ST32(0x06076694, 0);
    r1 = LD32(0x060769D4);
    r8 = 0x060769D4;
    if (!((r1 & r1) == 0)) {
        r9 = 0x0605299C;
        do {
            r0 = GCALL0(r9);
            r1 = LD32(r8);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    r0 = GCALL1(0x06032164, 1);
    r0 = GCALL1(0x0602D5C0, r10);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012194(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, r14, c3, c6, c10, c11, c1004, c2011, c2012;
    FRAME(sp, 32);

    r11 = r4;
    r9 = r5;
    r12 = r6;
    r14 = r7;
    r10 = LD32(sp);
    r13 = LD32(sp + 4);
    ST32(0x06078024, 0);
    r4 = LD32(r9);
    r0 = GCALL2(0x0607533C, r4, 0x06011610);
    ST32(0x060769AC, ((r0 & r0) == 0));
    c2011 = R(11);
    SETR(11, r11);
    c2012 = R(12);
    SETR(12, r12);
    r0 = GCALL4(0x06011630, r11, r9, r12, r10);
    SETR(11, c2011);
    SETR(12, c2012);
    r8 = r0;
    r0 = r13;
    if ((r8 & r8) == 0) {
        c6 = r0 == -2;
        if (r0 == -1) {
            r1 = r12;
        } else {
            r1 = r12;
            if (c6) {
                r1 = r12;
            } else {
                r4 = LD32((r1 + 100));
                r1 = r12;
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(0x06027F48, r4);
                    r1 = r12;
                }
                r4 = LD32((r1 + 104));
                r1 = r12;
                if (!((r4 & r4) == 0)) {
                    r0 = GCALL1(0x06027F48, r4);
                    r1 = r12;
                }
            }
        }
        ST32((r1 + 100), 0);
        ST32((r12 + 104), 0);
        r1 = LD32(r12 + 28);
        r0 = r1;
        c10 = r0 == 9;
        if (r0 == 2) {
            r0 = LD32(r12 + 44);
            c11 = r0 == 4;
            r0 = -1;
            if (c11) {
                r0 = -9;
            }
        } else {
            r0 = -1;
            if (c10) {
                r0 = LD32(r12 + 44);
                c11 = r0 == 4;
                r0 = -1;
                if (c11) {
                    r0 = -9;
                }
            }
        }
    } else {
        c3 = r0 == -2;
        c1004 = c3;
        if (r0 == -1) {
            r1 = r12;
            if (c1004) {
                r0 = GCALL0(0x06048F10);
                r1 = r12;
            }
        } else {
            c1004 = c3;
            if (c3) {
                r1 = r12;
                if (c1004) {
                    r0 = GCALL0(0x06048F10);
                    r1 = r12;
                }
            } else {
                r4 = LD32(0x060759B4);
                r0 = GCALL1(0x0604922C, r4);
                r6 = LD32((r12 + 104));
                r5 = LD32((r12 + 100));
                r4 = LD32(0x060767CC);
                r0 = GCALL3(0x06048C08, r4, r5, r6);
                ST32(0x06089A24, 0);
                r1 = r12;
            }
        }
        ST32((r1 + 100), 0);
        ST32((r12 + 104), 0);
        r4 = LD32(r14);
        if (!((r4 & r4) == 0)) {
            r0 = GCALL1(0x06027F48, r4);
        }
        ST32(r14, r8);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601265C(int r4)
{
    int r0, r5, r8, r9, c3;

    r9 = r4;
    r8 = 0x06010DDC;
    r0 = GCALL1(0x06010DDC, 4);
    if (!(r0 == 2)) {
        r0 = GCALL0(0x06043D04);
    } else {
        r0 = GCALL1(r8, 17);
        if ((r0 & r0) == 0) {
            r0 = GCALL1(0x06044030, 0x0608AF60);
        }
    }
    r8 = LD32(0x060766C0);
    r0 = r8;
    c3 = r0 == -12;
    if (r0 == -6) {
        r5 = LD32(0x060767CC);
        r4 = LD32(r9 + 12);
        r0 = GCALL2(0x0603CCE0, r4, r5);
        r0 = r8;
    } else {
        if (c3) {
            r0 = GCALL1(0x060125E8, r9);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012730(void)
{
    int r0, r1, c1, c2;

    r0 = GCALL1(0x06032164, 4);
    r0 = LD32(0x0608D388);
    r0 = LD8(r0 + 226);
    c1 = r0 == 5;
    if (r0 == 1) {
        r0 = GCALL2(0x06026CE4, 0, 1);
        r1 = 0x06053268;
        r0 = GCALL0(r1);
    } else {
        c2 = r0 == 2;
        if (!(c1)) {
            if (c2) {
                r0 = GCALL1(0x0607507C, 0x0608ADA4);
                if (!((r0 & r0) == 0)) {
                    r1 = 0x06053248;
                    r0 = GCALL0(r1);
                } else {
                    r0 = GCALL2(0x06045264, 0x0608B860, 0x06079768);
                    r0 = GCALL1(0x06010DDC, 24);
                }
            }
        } else {
            r0 = GCALL2(0x06026CE4, 0, 1);
            r1 = 0x06053268;
            r0 = GCALL0(r1);
        }
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06012810(int r4)
{
    int r0, r1, r5, r9, r10;

    r9 = r4;
    r0 = GCALL1(0x06010DDC, 3);
    if (!(r0 == 2)) {
        r0 = GCALL0(0x06043DE4);
    } else {
        r4 = LD32(0x060767CC);
        r0 = GCALL1(0x060440E4, r4);
    }
    r10 = LD32(0x060766C0);
    if (r10 == -21) {
        r1 = LD32(r9);
        r1 = LD32(0x10E4 + r1);
        ST32(r1 + 4, 0);
        r1 = LD32(r9);
        r1 = LD32(0x10E4 + r1);
        ST32(r1 + 8, 0);
        r5 = LD32(0x060767CC);
        r4 = LD32(r9 + 12);
        r0 = GCALL2(0x0603CCE0, r4, r5);
        ST32(0x06075988, 0);
    }
    return r10;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CB9C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9;

    r8 = r4;
    r9 = r5;
    r0 = GCALL4(0x06025A0C, 7, r5, r6, r7);
    ST32(0x060875C8, 0);
    r1 = 0x06076560;
    r0 = r8 << 8;
    if (!((r9 & r9) == 0)) {
        r0 = r0 | 4;
    }
    ST32(r1, r0);
    r8 = 0x06076564;
    r0 = GCALL4(0x060279E0, 0, 4, -1, 1);
    ST32(0x06076564, r0);
    if ((r0 & r0) == 0) {
        r0 = GCALL1(0x06028168, -3);
    }
    r1 = LD32(r8);
    ST16(r1, 0);
    r1 = r1 + 2;
    r0 = LD8(r1);
    ST8(r1, (r0 & 191));
    r1 = LD32(r8);
    r1 = r1 + 2;
    r0 = LD8(r1);
    ST8(r1, (r0 & 127));
    r1 = LD32(r8);
    r1 = r1 + 2;
    r0 = LD8(r1);
    ST8(r1, (r0 & 223));
    r0 = GCALL0(0x0601CB88);
    r0 = GCALL0(0x06020EB8);
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06010C44(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, r11, r12, r13, r14, c0;
    int v36;
    int v40;
    int v44;
    int v48;
    int v52;

    v48 = r4;
    r11 = r5;
    v44 = r6;
    v40 = r7;
    r0 = LD32(r11 + 44);
    c0 = r0 == 3;
    r0 = 0;
    if (c0) {
        r14 = 0x060279E0;
        r0 = GCALL7(0x060279E0, 0, 0x400, -1, 1, v48, v44, v40);
        r12 = r0;
        r6 = LD32(r11);
        r7 = R(7);
        r0 = GCALL7(0x06045264, r12, 0x06010068, r6, 0, v48, v44, v40);
        r13 = 0x0607507C;
        r0 = GCALL7(0x0607507C, r12, 0, 0, 0, v48, v44, v40);
        v36 = r0;
        r0 = GCALL8(0x060279E0, 0, 0x14C, -1, 1, v48, v44, v40, v36);
        r10 = r0;
        r6 = 0x14C;
        if ((r10 & r10) == 0) {
            r7 = R(7);
            r0 = GCALL8(0x06028168, -3, 0, 0, 0, v48, v44, v40, v36);
            r0 = 0;
        } else {
            r0 = GCALL8(0x0604B3F0, r10, 0, r6, 0, v48, v44, v40, v36);
            r4 = LD32(r11);
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL8(r13, r4, r5, r6, r7, v48, v44, v40, v36);
            r0 = GCALL8(r14, 0, (r0 + 1), -1, 1, v48, v44, v40, v36);
            r1 = r0;
            ST32(r10 + 4, r1);
            if (!((r1 & r1) == 0)) {
                r5 = LD32(r11);
                r0 = GCALL8(0x060750DC, r1, r5, 0, 0, v48, v44, v40, v36);
                r0 = r10;
                ST32(r0 + 204, 32);
                ST32(r0 + 196, 32);
                ST32(r0 + 208, 32);
                ST32(r0 + 200, 32);
                ST32(r0 + 0x114, 0);
                ST32(r0 + 212, 32);
                r1 = LD32(r11 + 16);
                ST32(r0 + 252, r1);
                r1 = LD32(r11 + 56);
                ST32(r0 + 0x100, r1);
                ST32(r0 + 0x10C, r1);
                ST32(r0 + 0x108, -1);
                ST32(r10 + 20, 0);
                ST32(r10 + 16, 0);
                ST32(r10 + 12, 0);
                r0 = GCALL8(0x06072820, (r10 + 40), r11, 28, 0, v48, v44, v40, v36);
                r4 = LD32(r11);
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL8(r13, r4, r5, r6, r7, v48, v44, v40, v36);
                r0 = GCALL8(r14, 0, (r0 + 1), -1, 1, v48, v44, v40, v36);
                r1 = r0;
                ST32(r10 + 40, r1);
                r5 = LD32(r11);
                r0 = GCALL8(0x060750DC, r1, r5, 0, 0, v48, v44, v40, v36);
                r9 = 168;
                r8 = 0x060286A8;
                do {
                    r7 = LD8(v48 + r9);
                    r0 = GCALL8(r8, 0x06026208, 3, r10, r7, 0, v48, v44, v40);
                } while (AGAIN(!((r0 & r0) == 0)));
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL8(0x06025A0C, 2, 0, 0, 0, v48, v44, v40, v36);
                r1 = LD32(0x060769B0);
                ST32(r10, r1);
                ST32(0x060769B0, r10);
                r1 = LD32(0x06000334);
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL8(r1, 2, r5, r6, r7, v48, v44, v40, v36);
                ST32(v44, r12);
                ST32(v40, v36);
                r0 = 1;
            } else {
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL8(0x06027F48, r10, 0, 0, 0, v48, v44, v40, v36);
                r7 = R(7);
                r0 = GCALL8(0x06028168, -3, 0, 0, 0, v48, v44, v40, v36);
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601637C(int r4, int r5, int r6)
{
    int r0, r1, r3, r7, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 52);

    ST32(sp - 44, r4);
    r12 = r5;
    r1 = LD32(sp + 8);
    ST32(sp - 40, (r1 & 0xFFFF));
    r11 = (r12 + 7) & -8;
    r13 = r6;
    if (r11 > 0) {
        ST32(sp - 36, (r11 - r12));
        r0 = GCALL7(0x06028380, (r11 * r13), 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
        r14 = r0;
        r9 = 0;
        if (!((r14 & r14) == 0)) {
            if (!(r9 >= r13)) {
                r10 = 0;
                r8 = r14;
                do {
                    r0 = LD32(sp - 44);
                    r5 = LD32(r0 + r10);
                    r0 = GCALL7(0x0604B358, r8, r5, r12, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                    r6 = LD32(sp - 36);
                    r0 = GCALL7(0x0604B3F0, (r8 + r12), 0, r6, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                    r10 = r10 + 4;
                    r9 = r9 + 1;
                    r8 = r8 + r11;
                } while (AGAIN(!(r9 >= r13)));
            }
            r3 = LD16((46 + (sp - 44)));
            r8 = r3 & 0xFFFF;
            r0 = GCALL7(0x06068240, r8, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
            r0 = LD32(sp + 4);
            r7 = r11 & 0xFFFF;
            if ((r0 & r0) == 0) {
                ST32((sp - 48), r14);
                ST32((sp - 52), (r13 & 0xFFFF));
                r6 = LD32(sp - 40);
                r0 = GCALL8(0x06067FFC, r8, 32, r6, r7, LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
            } else {
                ST32((sp - 48), r14);
                ST32((sp - 52), (r13 & 0xFFFF));
                r6 = LD32(sp - 40);
                r0 = GCALL8(0x06067FFC, r8, 160, r6, r7, LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                r7 = LD32(sp + 4);
                r0 = GCALL8(0x0606345C, 0x100, 0x100, 0x100, r7, LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                r5 = R(5);
                r6 = R(6);
                r0 = GCALL8(0x06013EC8, 1, r5, r6, r7, LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
            }
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL7(0x06027F48, r14, 0, 0, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06016478(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 64);

    ST32(sp - 56, r4);
    r10 = r5;
    r12 = r6;
    ST32(sp - 52, r7);
    r2 = (r10 + 7) & -8;
    ST32(sp - 36, r2);
    if (r2 > 0) {
        r8 = r2 >> 1;
        r0 = GCALL6(0x060279E0, 0, (r8 * r12), -1, 1, LD32((sp - 56)), LD32((sp - 52)));
        r9 = r0;
        r2 = 0;
        if (!((r9 & r9) == 0)) {
            if (!(r2 >= r12)) {
                ST32(sp - 40, r8);
                r10 = r10 + 1;
                ST32(sp - 48, (r10 >> 1));
                r13 = LD32(sp - 40);
                r14 = 0;
                r8 = 0;
                r5 = 0;
                ST32(sp - 44, r13);
                do {
                    r6 = r9 + r5;
                    r3 = LD32(sp - 56);
                    r7 = 0;
                    r11 = LD32(sp - 48);
                    r3 = r3 + r8;
                    if (!(0 >= r11)) {
                        r4 = r10 >> 1;
                        do {
                            r0 = LD8(r3);
                            r3 = r3 + 1;
                            r7 = r7 + 1;
                            r1 = ((r0 & 15) << 2) << 2;
                            ST8(r6, r1);
                            r0 = LD8(r3);
                            r3 = r3 + 1;
                            ST8(r6, (r1 | (r0 & 15)));
                            r6 = r6 + 1;
                        } while (AGAIN(!(r7 >= r4)));
                    }
                    r3 = LD32(sp - 44);
                    if (!(r7 >= r3)) {
                        do {
                            ST8(r6, r14);
                            r7 = r7 + 1;
                            r6 = r6 + 1;
                        } while (AGAIN(!(r7 >= r3)));
                    }
                    r2 = r2 + 1;
                    r13 = LD32(sp - 52);
                    r11 = LD32(sp - 40);
                    r8 = r8 + r13;
                    r5 = r5 + r11;
                } while (AGAIN(!(r2 >= r12)));
            }
            r13 = LD16((22 + (sp - 56)));
            r11 = LD16((58 + (sp - 56)));
            ST32((sp - 60), r9);
            ST32((sp - 64), (r12 & 0xFFFF));
            r0 = GCALL8(0x06067FFC, (r11 & 0xFFFF), 0, 240, (r13 & 0xFFFF), LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL8(0x06027F48, r9, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06016610(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    int v36;
    int v40;

    r8 = r4;
    v40 = r5;
    r3 = LD32(r8 + 16);
    r2 = 0x060759D0;
    v36 = r3;
    r1 = LD32(0x060759D0);
    if (!((r1 & r1) == 0)) {
        r9 = r2;
        r10 = 0x0605299C;
        do {
            r4 = R(4);
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL6(r10, r4, r5, r6, r7, v40, v36);
            r1 = LD32(r9);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    ST32(0x060759D4, 1);
    r11 = LD32(0x060759B4);
    r12 = -r11;
    r4 = r12;
    if (!(r12 >= 0)) {
        r4 = r4 + 0x1FF;
    }
    r2 = 0x060727A6;
    r4 = HELPER((int)r4 >> 9);
    r13 = (r4 << 8) + (r4 << 8);
    ST32(r8 + 16, r13);
    ST32(r8 + 44, 0x400);
    r4 = r11;
    if (!(r11 >= 0)) {
        r4 = r4 + 0x1FF;
    }
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL6(r2, r4, r5, r6, r7, v40, v36);
    r4 = R(4);
    r10 = r11 - ((r4 << 8) + (r4 << 8));
    r14 = 0x25E00000;
    ST32(r8 + 40, 0x25E00000);
    ST32(r8 + 28, r10);
    r9 = 0x200;
    r1 = LD32(r8 + 28);
    ST32(r8 + 24, 0x200);
    if (!(r1 >= 0x200)) {
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL6(v40, r8, r5, r6, r7, v40, v36);
    }
    ST32(r8 + 16, (r13 - r9));
    ST32(r8 + 44, 0x400);
    ST32(r8 + 40, r14);
    r9 = 0;
    ST32(r8 + 28, 0);
    r1 = LD32(r8 + 28);
    ST32(r8 + 24, r10);
    if (!(r1 >= r10)) {
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL6(v40, r8, r5, r6, r7, v40, v36);
    }
    ST32(r8 + 16, v36);
    ST32(0x060759D4, r9);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060166F0(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    int v36;
    int v40;

    r10 = r4;
    r3 = LD32(r10 + 16);
    r2 = 0x060759D0;
    v40 = r3;
    r1 = LD32(0x060759D0);
    if (!((r1 & r1) == 0)) {
        r8 = r2;
        r9 = 0x0605299C;
        do {
            r4 = R(4);
            r5 = R(5);
            r6 = R(6);
            r7 = R(7);
            r0 = GCALL5(r9, r4, r5, r6, r7, v40);
            r1 = LD32(r8);
        } while (AGAIN(!((r1 & r1) == 0)));
    }
    ST32(0x060759D4, 1);
    r13 = LD32(0x060759B4);
    r1 = LD32(r10 + 20);
    r2 = -16 & (r1 + -449);
    if (!(r2 >= 0)) {
        r2 = 0;
    }
    ST32(0x060759C0, r2);
    ST32(r10 + 44, 0x400);
    r0 = 140;
    r1 = LD32(140 + r10);
    r9 = -r13;
    if ((r1 & r1) == 0) {
        r4 = r13;
        if (!(r13 >= 0)) {
            r4 = r4 + 0x1FF;
        }
        r14 = 32;
        r4 = HELPER((int)r4 >> 9);
        r11 = r13 - ((r4 << 8) + (r4 << 8));
        r12 = r11;
        r8 = 0;
        while (1) {
            r4 = -r13;
            if (!(r4 >= 0)) {
                r4 = r4 + 0x1FF;
            }
            r4 = HELPER((int)r4 >> 9);
            ST32(r10 + 16, ((((r4 << 8) + (r4 << 8)) - r8) - r11));
            ST32(r10 + 28, 0);
            ST32(r10 + 24, 32);
            r3 = 0x200;
            r9 = r8;
            if (!((r14 + r11) > 0x200)) {
                r9 = 32;
            } else {
                r9 = r3 - (r9 + r11);
            }
            r3 = 0;
            if (r12 > 0x1FF) {
                break;
            } else {
                r0 = GCALL5(0x06015E54, r10, 0, 0, 0, v40);
                r5 = LD32(r10 + 40);
                r0 = GCALL5(0x0604B358, (0x25E00000 + ((r12 << 8) << 2)), r5, ((r9 << 8) << 2), 0, v40);
                r12 = r12 + 32;
                r14 = r14 + 32;
                r8 = r8 + 32;
            }
            POLL();
        }
        v36 = r3;
        r14 = 0;
        r12 = 0;
        while (1) {
            r4 = -r13;
            if (!(r4 >= 0)) {
                r4 = r4 + 0x1FF;
            }
            r4 = HELPER((int)r4 >> 9);
            ST32(r10 + 16, (((r4 << 8) + (r4 << 8)) - (0x200 + r12)));
            ST32(r10 + 28, 0);
            ST32(r10 + 24, 32);
            r9 = r11;
            if (!(((v36 + 1) * 32) > r11)) {
                r9 = 32;
            } else {
                r9 = r9 - r12;
            }
            if (r12 >= r11) {
                break;
            } else {
                r0 = GCALL6(0x06015E54, r10, 0, 0, 0, v40, v36);
                r5 = LD32(r10 + 40);
                r0 = GCALL6(0x0604B358, (0x25E00000 + r14), r5, ((r9 << 8) << 2), 0, v40, v36);
                r14 = r14 + 0x8000;
                r12 = r12 + 32;
                v36 = v36 + 1;
            }
            POLL();
        }
    } else {
        r4 = r9;
        if (!(r9 >= 0)) {
            r4 = r4 + 0x1FF;
        }
        r2 = 0x060727A6;
        r4 = HELPER((int)r4 >> 9);
        r14 = (r4 << 8) + (r4 << 8);
        ST32(r10 + 16, r14);
        r4 = r13;
        if (!(r13 >= 0)) {
            r4 = r4 + 0x1FF;
        }
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL5(r2, r4, r5, r6, r7, v40);
        r4 = R(4);
        r12 = r4;
        ST32(r10 + 40, 0x25E00000);
        ST32(r10 + 28, (r13 - ((r12 << 8) + (r12 << 8))));
        r8 = 0x200;
        r1 = LD32(r10 + 28);
        ST32(r10 + 24, 0x200);
        if (!(r1 >= 0x200)) {
            r0 = GCALL5(0x06015E54, r10, 0, 0, 0, v40);
        }
        ST32(r10 + 16, (r14 - r8));
        ST32(r10 + 40, 0x25E00000);
        ST32(r10 + 28, 0);
        r2 = r13 - ((r12 << 8) + (r12 << 8));
        r1 = LD32(r10 + 28);
        ST32(r10 + 24, r2);
        if (!(r1 >= r2)) {
            r0 = GCALL5(0x06015E54, r10, 0, 0, 0, v40);
        }
    }
    ST32(r10 + 16, v40);
    ST32(0x060759D4, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f06018930(int r4, int r5)
{
    int r0, r1, r6, r7, r8, r9;
    FRAME(sp, 16);

    ST32(sp - 16, r5);
    r1 = LD8(r5);
    r8 = r4;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        r9 = 0x06017AA4;
        do {
            r1 = LD32(sp - 16);
            r1 = LD8(r1);
            r0 = r1;
            if ((r1 & 255) == 38) {
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(r9, (sp - 16), r5, r6, r7, LD32((sp - 16)));
            }
            ST8(r8, r0);
            r1 = LD32(sp - 16);
            r1 = r1 + 1;
            ST32(sp - 16, r1);
            r1 = LD8(r1);
            r8 = r8 + 1;
        } while (AGAIN(!(((r1 & 255) & (r1 & 255)) == 0)));
    }
    ST8(r8, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0601A514(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, c3;
    FRAME(sp, 20);

    ST32(sp - 20, r5);
    r1 = LD8(r5);
    r9 = r4;
    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
        r10 = 0x06017AA4;
        r1 = LD32(sp - 20);
        do {
            r2 = LD8(r1);
            r0 = r2 & 255;
            r8 = r9;
            if ((unsigned)r0 > (unsigned)32) {
                r9 = r9 + 1;
                if (r0 == 38) {
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(r10, (sp - 20), r5, r6, r7, LD32((sp - 20)));
                } else {
                    r0 = r2;
                }
                ST8(r8, r0);
            }
            r1 = LD32(sp - 20);
            r1 = r1 + 1;
            ST32(sp - 20, r1);
            r1 = LD8(r1);
            c3 = ((r1 & 255) & (r1 & 255)) == 0;
            r1 = LD32(sp - 20);
        } while (AGAIN(!(c3)));
    }
    ST8(r9, 0);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601CC78(int r4, int r5, int r6, int r7)
{
    int r0, r1, r8, r9, r10, c2, c5;
    int v20;

    r8 = r4;
    r9 = r5 & 255;
    r10 = r6;
    if (!(r9 == 128)) {
        r8 = r8 & 0xFF00;
    }
    r0 = LD32(0x06076568);
    if ((r0 & r0) == 0) {
        r0 = GCALL4(0x0601CB70, 0, r5, r6, r7);
        if ((r0 & r0) == 0) {
            r0 = GCALL0(0x0601CB88);
            r0 = GCALL3(0x060213D0, r8, r9, r10);
            r4 = r0;
            if (!((r0 & r0) == 0)) {
                v20 = r0;
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL5(0x0601CC34, r4, 0, 0, 0, v20);
                r0 = v20;
                ST32(0x06076568, r0);
            } else {
                r4 = LD32(0x06076560);
                r6 = r10;
                if (r8 == r4) {
                    ST32(0x06076568, r0);
                } else {
                    r0 = GCALL3(0x0601CC78, r4, r9, r6);
                }
            }
        } else {
            while (1) {
                r1 = LD32(r0);
                c5 = r1 == r8;
                r1 = r0;
                if (!(c5)) {
                    r0 = LD32(r0 + 52);
                    if (!((r0 & r0) == 0)) {
                        POLL();
                        continue;
                    } else {
                        r0 = GCALL0(0x0601CB88);
                        r0 = GCALL3(0x060213D0, r8, r9, r10);
                        r4 = r0;
                        if (!((r0 & r0) == 0)) {
                            v20 = r0;
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL5(0x0601CC34, r4, 0, 0, 0, v20);
                            r0 = v20;
                            ST32(0x06076568, r0);
                            break;
                        } else {
                            r4 = LD32(0x06076560);
                            r6 = r10;
                            if (r8 == r4) {
                                ST32(0x06076568, r0);
                                break;
                            } else {
                                r0 = GCALL3(0x0601CC78, r4, r9, r6);
                                break;
                            }
                        }
                    }
                } else {
                    r1 = LD8((r1 + 4));
                    if ((r1 & 255) == r9) {
                        r1 = LD32(r0 + 48);
                        ST32(r0 + 48, (r1 + 1));
                        v20 = r0;
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(0x0601CB88, 0, 0, 0, 0, v20);
                        r0 = v20;
                        ST32(0x06076568, r0);
                        break;
                    } else {
                        r0 = LD32(r0 + 52);
                        if (!((r0 & r0) == 0)) {
                            POLL();
                            continue;
                        } else {
                            r0 = GCALL0(0x0601CB88);
                            r0 = GCALL3(0x060213D0, r8, r9, r10);
                            r4 = r0;
                            if (!((r0 & r0) == 0)) {
                                v20 = r0;
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL5(0x0601CC34, r4, 0, 0, 0, v20);
                                r0 = v20;
                                ST32(0x06076568, r0);
                                break;
                            } else {
                                r4 = LD32(0x06076560);
                                r6 = r10;
                                if (r8 == r4) {
                                    ST32(0x06076568, r0);
                                    break;
                                } else {
                                    r0 = GCALL3(0x0601CC78, r4, r9, r6);
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
        r1 = LD32(r0);
        c2 = r1 == r8;
        r1 = r0;
        if (!(c2)) {
            r0 = GCALL4(0x0601CB70, 0, r5, r6, r7);
            if ((r0 & r0) == 0) {
                r0 = GCALL0(0x0601CB88);
                r0 = GCALL3(0x060213D0, r8, r9, r10);
                r4 = r0;
                if (!((r0 & r0) == 0)) {
                    v20 = r0;
                    r5 = R(5);
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL5(0x0601CC34, r4, 0, 0, 0, v20);
                    r0 = v20;
                    ST32(0x06076568, r0);
                } else {
                    r4 = LD32(0x06076560);
                    r6 = r10;
                    if (r8 == r4) {
                        ST32(0x06076568, r0);
                    } else {
                        r0 = GCALL3(0x0601CC78, r4, r9, r6);
                    }
                }
            } else {
                while (1) {
                    r1 = LD32(r0);
                    c5 = r1 == r8;
                    r1 = r0;
                    if (!(c5)) {
                        r0 = LD32(r0 + 52);
                        if (!((r0 & r0) == 0)) {
                            POLL();
                            continue;
                        } else {
                            r0 = GCALL0(0x0601CB88);
                            r0 = GCALL3(0x060213D0, r8, r9, r10);
                            r4 = r0;
                            if (!((r0 & r0) == 0)) {
                                v20 = r0;
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL5(0x0601CC34, r4, 0, 0, 0, v20);
                                r0 = v20;
                                ST32(0x06076568, r0);
                                break;
                            } else {
                                r4 = LD32(0x06076560);
                                r6 = r10;
                                if (r8 == r4) {
                                    ST32(0x06076568, r0);
                                    break;
                                } else {
                                    r0 = GCALL3(0x0601CC78, r4, r9, r6);
                                    break;
                                }
                            }
                        }
                    } else {
                        r1 = LD8((r1 + 4));
                        if ((r1 & 255) == r9) {
                            r1 = LD32(r0 + 48);
                            ST32(r0 + 48, (r1 + 1));
                            v20 = r0;
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL5(0x0601CB88, 0, 0, 0, 0, v20);
                            r0 = v20;
                            ST32(0x06076568, r0);
                            break;
                        } else {
                            r0 = LD32(r0 + 52);
                            if (!((r0 & r0) == 0)) {
                                POLL();
                                continue;
                            } else {
                                r0 = GCALL0(0x0601CB88);
                                r0 = GCALL3(0x060213D0, r8, r9, r10);
                                r4 = r0;
                                if (!((r0 & r0) == 0)) {
                                    v20 = r0;
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL5(0x0601CC34, r4, 0, 0, 0, v20);
                                    r0 = v20;
                                    ST32(0x06076568, r0);
                                    break;
                                } else {
                                    r4 = LD32(0x06076560);
                                    r6 = r10;
                                    if (r8 == r4) {
                                        ST32(0x06076568, r0);
                                        break;
                                    } else {
                                        r0 = GCALL3(0x0601CC78, r4, r9, r6);
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
            r1 = LD8((r1 + 4));
            if (!((r1 & 255) == r9)) {
                r0 = GCALL4(0x0601CB70, 0, r5, r6, r7);
                if ((r0 & r0) == 0) {
                    r0 = GCALL0(0x0601CB88);
                    r0 = GCALL3(0x060213D0, r8, r9, r10);
                    r4 = r0;
                    if (!((r0 & r0) == 0)) {
                        v20 = r0;
                        r5 = R(5);
                        r6 = R(6);
                        r7 = R(7);
                        r0 = GCALL5(0x0601CC34, r4, 0, 0, 0, v20);
                        r0 = v20;
                        ST32(0x06076568, r0);
                    } else {
                        r4 = LD32(0x06076560);
                        r6 = r10;
                        if (r8 == r4) {
                            ST32(0x06076568, r0);
                        } else {
                            r0 = GCALL3(0x0601CC78, r4, r9, r6);
                        }
                    }
                } else {
                    while (1) {
                        r1 = LD32(r0);
                        c5 = r1 == r8;
                        r1 = r0;
                        if (!(c5)) {
                            r0 = LD32(r0 + 52);
                            if (!((r0 & r0) == 0)) {
                                POLL();
                                continue;
                            } else {
                                r0 = GCALL0(0x0601CB88);
                                r0 = GCALL3(0x060213D0, r8, r9, r10);
                                r4 = r0;
                                if (!((r0 & r0) == 0)) {
                                    v20 = r0;
                                    r5 = R(5);
                                    r6 = R(6);
                                    r7 = R(7);
                                    r0 = GCALL5(0x0601CC34, r4, 0, 0, 0, v20);
                                    r0 = v20;
                                    ST32(0x06076568, r0);
                                    break;
                                } else {
                                    r4 = LD32(0x06076560);
                                    r6 = r10;
                                    if (r8 == r4) {
                                        ST32(0x06076568, r0);
                                        break;
                                    } else {
                                        r0 = GCALL3(0x0601CC78, r4, r9, r6);
                                        break;
                                    }
                                }
                            }
                        } else {
                            r1 = LD8((r1 + 4));
                            if ((r1 & 255) == r9) {
                                r1 = LD32(r0 + 48);
                                ST32(r0 + 48, (r1 + 1));
                                v20 = r0;
                                r5 = R(5);
                                r6 = R(6);
                                r7 = R(7);
                                r0 = GCALL5(0x0601CB88, 0, 0, 0, 0, v20);
                                r0 = v20;
                                ST32(0x06076568, r0);
                                break;
                            } else {
                                r0 = LD32(r0 + 52);
                                if (!((r0 & r0) == 0)) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = GCALL0(0x0601CB88);
                                    r0 = GCALL3(0x060213D0, r8, r9, r10);
                                    r4 = r0;
                                    if (!((r0 & r0) == 0)) {
                                        v20 = r0;
                                        r5 = R(5);
                                        r6 = R(6);
                                        r7 = R(7);
                                        r0 = GCALL5(0x0601CC34, r4, 0, 0, 0, v20);
                                        r0 = v20;
                                        ST32(0x06076568, r0);
                                        break;
                                    } else {
                                        r4 = LD32(0x06076560);
                                        r6 = r10;
                                        if (r8 == r4) {
                                            ST32(0x06076568, r0);
                                            break;
                                        } else {
                                            r0 = GCALL3(0x0601CC78, r4, r9, r6);
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
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F6B0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 36);

    ST32(sp - 36, r4);
    r8 = r5;
    r12 = r7;
    r7 = LD16((r4 + 48));
    r10 = 0x0607286C;
    r9 = LD32(sp - 36);
    r7 = r7 & 0xFFFF;
    r0 = GCALL5(0x0607286C, r8, r7, 0, 0, LD32((sp - 36)));
    r5 = r0;
    r4 = LD32(sp - 36);
    r4 = r4 + 46;
    r1 = LD16(r4);
    r9 = r9 + 38;
    r2 = r5 + (r1 & 0xFFFF);
    r1 = LD16(r9);
    r11 = r6;
    r6 = r1 & 0xFFFF;
    r13 = LD32(sp);
    r14 = LD32(sp + 4);
    r1 = LD32(sp - 36);
    r0 = LD32(sp - 36);
    r1 = LD16((r1 + 44));
    r3 = r1 & 0xFFFF;
    r1 = LD32(r0 + 20);
    r8 = ((r2 * r6) + (r8 - (r5 * r7))) + r3;
    if ((r1 & r1) == 0) {
        ST32(r13, (r3 + r11));
        r1 = LD16(r4);
        ST32(r14, ((r1 & 0xFFFF) + r12));
    } else {
        r0 = GCALL5(r10, r8, r6, r6, r7, LD32((sp - 36)));
        r7 = r0;
        r6 = R(6);
        ST32(r13, (r8 - (r7 * r6)));
        r5 = LD16(r9);
        r0 = GCALL5(r10, 0, (r5 & 0xFFFF), r6, r7, LD32((sp - 36)));
        ST32(r14, r0);
    }
    return r8;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601FAA0(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, c3, c5, c1007;

    r8 = r4;
    r9 = r6;
    r12 = 0;
    r5 = LD16((r8 + 50));
    r11 = 0x060279E0;
    r0 = GCALL4(0x060279E0, 0, ((r5 & 0xFFFF) + (r5 & 0xFFFF)), -1, 1);
    r10 = r0;
    r1 = r8;
    if ((r10 & r10) == 0) {
        r0 = GCALL1(0x0602BA00, 0x0601FA34);
        r1 = r8;
    }
    r5 = LD16((r1 + 48));
    r4 = LD32(r9 + 32);
    r0 = GCALL2(0x0607286C, r4, (r5 & 0xFFFF));
    r1 = LD32(r8 + 4);
    r9 = r0 & 0xFFFF;
    if ((r1 & r1) == 0) {
        r5 = LD16((r8 + 40));
        r0 = GCALL4(r11, 0, ((r5 & 0xFFFF) << 2), -1, 1);
        ST32(r8 + 4, r0);
        if ((r0 & r0) == 0) {
            r0 = GCALL1(0x0602BA00, 0x0601FA64);
        }
    }
    c3 = (r10 & r10) == 0;
    c1007 = c3;
    if (c3) {
        r12 = -105;
    } else {
        r1 = LD32(r8 + 4);
        c5 = (r9 & r9) == 0;
        c1007 = c5;
        if (!((r1 & r1) == 0)) {
            if (!(c5)) {
                r6 = (short)r9;
                r9 = r8 + 50;
                r0 = LD16(0x346 + r8);
                r5 = LD16(r9);
                r0 = GCALL3(0x0601EFE8, r10, r5, r6);
                r7 = r8 + 46;
                r1 = LD16(r7);
                r2 = LD16(r10);
                r5 = (short)(r1 + r2);
                r1 = LD16(r9);
                r3 = 0;
                if (!((unsigned)0 >= (unsigned)(r1 & 0xFFFF))) {
                    r6 = r7;
                    r4 = r9;
                    r0 = r3;
                    do {
                        r0 = LD16((r0 + r0) + r10);
                        r1 = LD16(r6);
                        if (!(r0 == -1)) {
                            r5 = (short)(r1 + r3);
                        } else {
                            r2 = ((r1 & 0xFFFF) + r3) << 2;
                            r1 = LD32(r8 + 8);
                            r1 = LD32((r5 << 2) + r1);
                            r7 = LD32(r8 + 4);
                            ST32(r2 + r7, r1);
                        }
                        r3 = (r3 + 1) & 0xFFFF;
                        r1 = LD16(r4);
                        r0 = r3;
                    } while (AGAIN(!((unsigned)r3 >= (unsigned)(r1 & 0xFFFF))));
                }
            }
        } else {
            r12 = -105;
        }
    }
    if (!((r10 & r10) == 0)) {
        r0 = GCALL1(0x06027F48, r10);
    }
    return r12;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601288C(int r4)
{
    int r0, r5, r8, r9, r10, r11, r12, c2011;

    r11 = R(11);
    r8 = r4;
    r10 = 0x060759B4;
    r4 = LD32(0x060759B4);
    r0 = GCALL1(0x0604922C, r4);
    c2011 = R(11);
    SETR(11, r11);
    r0 = GCALL1(0x06010DDC, 25);
    SETR(11, c2011);
    r12 = 0x060766C0;
    r9 = LD32(0x060766C0);
    r11 = 0;
    if (r9 == -1) {
        ST32(r10, r11);
        r5 = LD32(r8 + 8);
        r4 = LD32(r8 + 12);
        r0 = GCALL4(0x06048DE0, r4, (r5 + 100), (r5 + 104), 0x06089A24);
        if ((r0 & r0) == 0) {
            ST32(r12, r11);
        }
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06013CA0(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, c9, c15, c2008, c2009;

    r8 = R(8);
    r9 = R(9);
    r1 = LD32(0x06089CB8);
    ST32(0x06089CB8, (r1 + 1));
    r2 = LD32(0x06089CB8);
    if (r2 > 1) {
        r2 = LD8(-494);
        r1 = LD8(-493);
        r2 = ((r2 & 255) << 8) | (r1 & 255);
        r1 = LD32(0x06089CC0);
        r2 = r2 - r1;
        if (!(r2 >= 0)) {
            r1 = LD32(0x0608B9B8);
            r2 = r2 + r1;
        }
        if (r2 > 0xF00) {
            r2 = LD32(0x06089CAC);
            ST32(0x06089CAC, (r2 + 1));
            r1 = LD32(0x06089CAC);
        }
    }
    r2 = LD8(-494);
    r1 = LD8(-493);
    ST32(0x06089CC0, (((r2 & 255) << 8) | (r1 & 255)));
    r0 = GCALL0(0x06013F7C);
    r0 = GCALL0(0x06062304);
    r1 = LD32(0x060759A8);
    if (!((r1 & r1) == 0)) {
        r1 = LD32(0x060759AC);
        if ((r1 & r1) == 0) {
            r0 = LD16(0x25D00010);
            r0 = r0 & 1;
            if ((r0 & r0) == 0) {
                r3 = LD16(0x25D00014);
                ST16(0x25C00000, 0x1000);
                ST16(0x25C00002, r3);
            }
        }
    }
    r2 = 0x060759AC;
    r1 = LD32(0x060759AC);
    if ((r1 & r1) == 0) {
        r0 = LD16(0x25D00010);
        r0 = r0 & 3;
        if (r0 == 3) {
            r9 = 1;
            ST32(r2, 1);
        }
    }
    r1 = LD32(0x060759A8);
    if (!((r1 & r1) == 0)) {
        r3 = 0x060759AC;
        r1 = LD32(0x060759AC);
        c9 = (r1 & r1) == 0;
        r1 = 2;
        if (!(c9)) {
            ST16(0x25D00004, r1);
            ST32(0x06079FC4, 1);
            ST32(r3, 0);
        }
    }
    r1 = LD32(0x06089CBC);
    if ((r1 & r1) == 0) {
        r0 = LD8(-490);
        r0 = GCALL2(0x0607290C, 8, ((r0 & 3) + (r0 & 3)));
        c2008 = R(8);
        SETR(8, r8);
        r0 = GCALL1(0x06073368, r0);
        SETR(8, c2008);
        r2 = r0;
        r0 = LD16(0x25F80004);
        if (((r0 & 1) & (r0 & 1)) == 0) {
            r1 = LD32(0x06000324);
            if (!((r1 & r1) == 0)) {
                r4 = LD32(0x06013C9C);
            } else {
                r4 = LD32(0x06013C98);
            }
        } else {
            r1 = LD32(0x06000324);
            if (!((r1 & r1) == 0)) {
                r4 = LD32(0x06013C94);
            } else {
                r4 = LD32(0x06013C90);
            }
        }
        r0 = GCALL2(0x06072FC4, r4, r2);
        r0 = GCALL1(0x060733D8, r0);
        r5 = -494;
        r6 = -493;
        r7 = 0x06089CC0;
        r3 = 0x0608B9B8;
        do {
            r1 = LD8(r5);
            r2 = LD8(r6);
            r1 = ((r1 & 255) << 8) | (r2 & 255);
            r2 = LD32(r7);
            r1 = r1 - r2;
            if (!(r1 >= 0)) {
                r2 = LD32(r3);
                r1 = r1 + r2;
                do {
                    c15 = r1 >= 0;
                    r1 = r1 + r2;
                } while (AGAIN(!(c15)));
                r1 = r1 - r2;
            }
        } while (AGAIN(!(r1 >= r0)));
        r0 = LD8(0x20100063);
        r0 = r0 & 1;
        if ((r0 & r0) == 0) {
            r0 = GCALL0(0x06016FE4);
            r0 = GCALL0(0x06016F08);
            r0 = GCALL0(0x06016A78);
        }
    }
    r8 = 0x0607599C;
    r1 = LD32(0x0607599C);
    if (!((r1 & r1) == 0)) {
        r6 = LD32(0x060759A4);
        r5 = LD32(0x060759A0);
        r4 = LD32(r8);
        c2009 = R(9);
        SETR(9, r9);
        r0 = GCALL3(0x06069CC8, r4, r5, r6);
        SETR(9, c2009);
        ST32(r8, 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06015D00(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, r13, c11, c13, c15;

    r9 = r4;
    r0 = r9;
    r1 = LD32(r0 + 152);
    r7 = 144;
    r2 = LD32(r0 + 144);
    r13 = LD32(r0 + 156);
    r1 = r1 - r2;
    ST32(r0 + 156, r1);
    r3 = 160;
    r6 = LD32(r0 + 160);
    r12 = 0;
    if (!((r1 + r5) > r6)) {
        ST32(0x06075A70, (144 + r9));
        if (!((r12 & r12) == 0)) {
            r0 = GCALL1(0x06027F48, r12);
        }
        r0 = 1;
    } else {
        r11 = r6;
        r2 = r11 + ((((((int)(((long long)r11 * 0x66666667) >> 32)) >> 1) >> 1) >> 1) - (((r11 << 1) - (r11 << 1)) - ((unsigned)r11 >> 31)));
        r1 = 0x800;
        if (!(r5 >= 0x800)) {
            r5 = r1;
        }
        r10 = r11 + r5;
        if (r10 > r2) {
            r10 = r2;
        }
        r0 = r9;
        ST32(r0 + r3, r10);
        r5 = LD32(r0 + r7);
        r6 = r10;
        if ((r5 & r5) == 0) {
            r0 = GCALL4(0x060279E0, 0, r10, 4, 1);
            r8 = r0;
        } else {
            r0 = GCALL4(0x06027C18, 0, r5, r6, r7);
            r8 = r0;
        }
        c11 = (r8 & r8) == 0;
        r7 = c11;
        if (!(c11)) {
            r0 = r9;
            r1 = LD32(r0 + 144);
            r2 = r8 - r1;
            r1 = LD32(r0 + 152);
            ST32(r0 + 152, (r1 + r2));
            r3 = 148;
            r1 = LD32(r0 + 148);
            c13 = (r1 & r1) == 0;
            r1 = r1 + r2;
            if (!(c13)) {
                ST32(r0 + r3, r1);
            }
            r3 = r8;
            if (!((r8 & r8) == 0)) {
                do {
                    r1 = LD32(r3 + 4);
                    c15 = (r1 & r1) == 0;
                    r1 = r1 + r2;
                    if (!(c15)) {
                        ST32(r3 + 4, r1);
                    }
                    r3 = LD32(r3 + 4);
                } while (AGAIN(!((r3 & r3) == 0)));
            }
            ST32(144 + r9, r8);
            ST32(0x06075A70, (144 + r9));
            if (!((r12 & r12) == 0)) {
                r0 = GCALL1(0x06027F48, r12);
            }
            r0 = 1;
        } else {
            r0 = GCALL4(0x060279E0, 1, r10, 4, r7);
            r8 = r0;
            r6 = r11;
            if (!((r8 & r8) == 0)) {
                r5 = LD32(r9 + 144);
                r0 = GCALL3(0x0604B358, r8, r5, r6);
                r12 = LD32(r9 + 144);
                r0 = r9;
                r1 = LD32(r0 + 144);
                r2 = r8 - r1;
                r1 = LD32(r0 + 152);
                ST32(r0 + 152, (r1 + r2));
                r3 = 148;
                r1 = LD32(r0 + 148);
                c13 = (r1 & r1) == 0;
                r1 = r1 + r2;
                if (!(c13)) {
                    ST32(r0 + r3, r1);
                }
                r3 = r8;
                if (!((r8 & r8) == 0)) {
                    do {
                        r1 = LD32(r3 + 4);
                        c15 = (r1 & r1) == 0;
                        r1 = r1 + r2;
                        if (!(c15)) {
                            ST32(r3 + 4, r1);
                        }
                        r3 = LD32(r3 + 4);
                    } while (AGAIN(!((r3 & r3) == 0)));
                }
                ST32(144 + r9, r8);
                ST32(0x06075A70, (144 + r9));
                if (!((r12 & r12) == 0)) {
                    r0 = GCALL1(0x06027F48, r12);
                }
                r0 = 1;
            } else {
                r0 = GCALL3(0x06045264, 0x0608B9D0, 0x06015CE4, r6);
                r0 = GCALL1(0x0602BA00, 0x0608B9D0);
                ST32(160 + r9, r11);
                ST32(156 + r9, r13);
                r0 = 0;
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06017468(void)
{
    int r0, r1, r2, r3, r4, r7, r8, r9, r10, r11, r12;

    r3 = 0x06086F94;
    r2 = 0;
    r7 = 0;
    r1 = 240;
    do {
        r0 = r7;
        r7 = r7 + 4;
        ST32(r0 + r3, r2);
    } while (AGAIN(!(r7 > r1)));
    r10 = 0;
    r12 = 0x0608708C;
    r11 = 0x06086F94;
    r8 = 0x0608708C;
    r9 = 0;
    do {
        ST32(r9 + r12, (0x06075C74 + r9));
        r0 = r10 << 2;
        r1 = LD32(r0 + 0x060761B0);
        ST32(r8 + 4, r1);
        r1 = LD32(r0 + 0x060762BC);
        ST32(r8 + 8, r1);
        r1 = LD32(r0 + 0x060763C8);
        ST32(r8 + 12, r1);
        ST32(r8 + 16, 0);
        r4 = LD32(r9 + r12);
        r0 = GCALL1(0x06017450, r4);
        r2 = ((signed char)(((signed char)r0) - ((int)((((long long)((signed char)r0) * 0x4325C53F) & ~0xFFFFFFFFLL) | (unsigned)((((((((int)(((long long)((signed char)r0) * 0x4325C53F) >> 32)) >> 1) >> 1) >> 1) >> 1) - (((((signed char)r0) << 1) - (((signed char)r0) << 1)) - ((unsigned)((signed char)r0) >> 31))) * 61))))) << 2;
        r0 = r2;
        r1 = LD32(r0 + r11);
        if (!((r1 & r1) == 0)) {
            ST32(r8 + 16, r1);
            r0 = r2;
        }
        ST32(r0 + r11, r8);
        r8 = r8 + 20;
        r10 = r10 + 1;
        r9 = r9 + 20;
    } while (AGAIN(!(r10 > 66)));
    return 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060176FC(int r4)
{
    int r0, r1, r2, r5, r6, r8, r9, r10;

    r9 = r4;
    r1 = LD8(r9);
    r6 = 3;
    if (!((r1 & r1) == 0)) {
        r0 = GCALL3(0x060752FC, 0x060176F8, r9, r6);
        r2 = r9;
        if ((r0 & r0) == 0) {
            ST8((r2 + 3), 0);
        }
        r0 = GCALL1(0x06017450, r9);
        r8 = LD32(((((signed char)r0) - ((int)((((long long)((signed char)r0) * 0x4325C53F) & ~0xFFFFFFFFLL) | (unsigned)((((((((int)(((long long)((signed char)r0) * 0x4325C53F) >> 32)) >> 1) >> 1) >> 1) >> 1) - (((((signed char)r0) << 1) - (((signed char)r0) << 1)) - ((unsigned)((signed char)r0) >> 31))) * 61)))) << 2) + 0x06086F94);
        r0 = r8;
        if (!((r8 & r8) == 0)) {
            r10 = 0x06075104;
            while (1) {
                r5 = LD32(r8);
                r0 = GCALL2(r10, r9, r5);
                if ((r0 & r0) == 0) {
                    break;
                } else {
                    r8 = LD32(r8 + 16);
                    if (!((r8 & r8) == 0)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
            r0 = r8;
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601B2C8(int r4, int r5)
{
    int r0, r1, r9, r10;

    r10 = r4;
    r9 = r5;
    if (!(r5 >= 0)) {
        r9 = -r9;
    }
    ST8(r10, 0);
    r4 = HELPER((int)((int)(((long long)r9 * 0x10624DD3) >> 32)) >> 6);
    r1 = r4 - (((r9 << 1) - (r9 << 1)) - ((unsigned)r9 >> 31));
    r9 = r9 - r1;
    r5 = LD32((r1 << 2) + 0x0607654C);
    r0 = GCALL2(0x06075408, r10, r5);
    r1 = (((((((int)(((long long)r9 * 0x51EB851F) >> 32)) >> 1) >> 1) >> 1) >> 1) >> 1) - (((r9 << 1) - (r9 << 1)) - ((unsigned)r9 >> 31));
    r9 = r9 - r1;
    r5 = LD32((r1 << 2) + 0x06076524);
    r0 = GCALL2(0x06075408, r10, r5);
    r1 = ((((int)(((long long)r9 * 0x66666667) >> 32)) >> 1) >> 1) - (((r9 << 1) - (r9 << 1)) - ((unsigned)r9 >> 31));
    r9 = r9 - r1;
    r5 = LD32((r1 << 2) + 0x060764FC);
    r0 = GCALL2(0x06075408, r10, r5);
    r5 = LD32((r9 << 2) + 0x060764D4);
    r0 = GCALL2(0x06075408, r10, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D898(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, c1, c1003;
    long long m0;
    int v24;
    int v28;

    r11 = r4;
    r8 = r5;
    r4 = LD32(0x10B4 + r11);
    r0 = GCALL4(0x0601CC78, r4, 128, 0, r7);
    r9 = LD32(r0 + 40);
    r10 = LD32(r0 + 36);
    r1 = LD32(0x10B8 + r11);
    r4 = LD16(r1);
    r0 = LD8((r1 + 2));
    if (!(((r0 & 128) & (r0 & 128)) == 0)) {
        r0 = GCALL1(0x0601EFA4, (r4 & 255));
        c1 = r0 > 49;
        r1 = 0;
        c1003 = c1;
        if (!(c1)) {
            r1 = 255;
            c1003 = 0;
        }
        r4 = r1;
    }
    r1 = r8;
    if ((unsigned)r8 > (unsigned)3) {
        r0 = 0;
    } else {
        r1 = LD16(0x0601D8EC + (r1 + r1));
        switch (r1) {
        case 200:
            r0 = 0;
            break;
        case 8:
            r2 = ((r9 << 1) - (r9 << 1)) - ((unsigned)r9 >> 31);
            m0 = (long long)r9 * 0x55555556;
            r0 = 0x06014E74;
            r6 = LD32(r11 + 12);
            r5 = LD32(r11 + 8);
            r0 = GCALL5(r0, r11, (r5 + ((r9 - r2) >> 1)), (r6 + ((((int)((unsigned)r10 >> 31)) + r10) >> 1)), (((int)(m0 >> 32)) - r2), ((signed char)r4));
            r0 = (((r9 + r9) + r9) + ((int)((unsigned)((r9 + r9) + r9) >> 31))) >> 1;
            break;
        case 24:
            r2 = ((r9 << 1) - (r9 << 1)) - ((unsigned)r9 >> 31);
            m0 = (long long)r9 * 0x55555556;
            r6 = LD32(r11 + 12);
            r0 = 0x06014FE4;
            r5 = LD32(r11 + 8);
            r0 = GCALL5(r0, r11, (r5 + ((r9 - r2) >> 1)), (r6 + ((((int)((unsigned)r10 >> 31)) + r10) >> 1)), (((int)(m0 >> 32)) - r2), ((signed char)r4));
            r0 = (((r9 + r9) + r9) + ((int)((unsigned)((r9 + r9) + r9) >> 31))) >> 1;
            break;
        case 94:
            r5 = LD32(r11 + 8);
            r6 = LD32(r11 + 12);
            r8 = r9 + r9;
            r0 = GCALL6(0x06015154, r11, (r5 + (((int)(((long long)r9 * 0x2AAAAAAB) >> 32)) - (((r9 << 1) - (r9 << 1)) - ((unsigned)r9 >> 31)))), (r6 - (((int)(((long long)((r10 << 2) + r10) * 0x2AAAAAAB) >> 32)) - (((((r10 << 2) + r10) << 1) - (((r10 << 2) + r10) << 1)) - ((unsigned)((r10 << 2) + r10) >> 31)))), ((r5 + (((int)(((long long)r9 * 0x2AAAAAAB) >> 32)) - (((r9 << 1) - (r9 << 1)) - ((unsigned)r9 >> 31)))) + (((int)(((long long)r8 * 0x55555556) >> 32)) - (((r8 << 1) - (r8 << 1)) - ((unsigned)r8 >> 31)))), ((((int)(((long long)(r10 + r10) * 0x55555556) >> 32)) - ((((r10 + r10) << 1) - ((r10 + r10) << 1)) - ((unsigned)(r10 + r10) >> 31))) + (r6 - (((int)(((long long)((r10 << 2) + r10) * 0x2AAAAAAB) >> 32)) - (((((r10 << 2) + r10) << 1) - (((r10 << 2) + r10) << 1)) - ((unsigned)((r10 << 2) + r10) >> 31))))), ((signed char)r4));
            r0 = ((r8 + r9) + ((int)((unsigned)(r8 + r9) >> 31))) >> 1;
            break;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601EFA4(int r4)
{
    return ((((((((int)(((long long)(((((((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2)) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + (28 & (r4 & 255))) + (((r4 & 255) & 3) + ((r4 & 255) & 3))) * 100) * ((int)0x92492493)) >> 32)) + (((((((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2)) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + (28 & (r4 & 255))) + (((r4 & 255) & 3) + ((r4 & 255) & 3))) * 100)) >> 1) >> 1) >> 1) >> 1) >> 1) - ((((((((((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2)) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + (28 & (r4 & 255))) + (((r4 & 255) & 3) + ((r4 & 255) & 3))) * 100) << 1) - ((((((((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2)) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + (28 & (r4 & 255))) + (((r4 & 255) & 3) + ((r4 & 255) & 3))) * 100) << 1)) - ((unsigned)(((((((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2)) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r4 & 255) >> 2)) >> 1)) >> 2))) + (28 & (r4 & 255))) + (((r4 & 255) & 3) + ((r4 & 255) & 3))) * 100) >> 31));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f060106BC(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r10, c5, c11, c14, c1013, c1020, c1027, c1028;

    r1 = LD32(r4 + 20);
    r8 = 0x1FF;
    r5 = (r5 + 8) & -16;
    if (r1 > 0x1FF) {
        r7 = 0x060759B4;
        r2 = LD32(0x060759B4);
        r3 = 0x060759B8;
        r1 = LD32(0x060759B8);
        if (r2 == r1) {
            r0 = (SR() & ~1) | 1;
            r6 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
            r0 = (SR() & ~1) | 1;
            SETSR((r0 | 240));
            r10 = r5 + -256;
            r2 = 0x060759C0;
            r1 = LD32(0x060759C0);
            if (r10 > r1) {
                r10 = LD32(r2);
            }
            if (!(r10 >= 0)) {
                r10 = 0;
            }
            r1 = LD32(r3);
            r10 = r10 - r1;
            c5 = r10 >= 0;
            c1028 = c5;
            if (!((r10 & r10) == 0)) {
                r1 = r10;
                if (!(c5)) {
                    r1 = -r10;
                }
                c1020 = r10 >= 0;
                if (r1 > r8) {
                    r3 = 0x200;
                    c1013 = r10 > 0;
                    do {
                        if (!(c1013)) {
                            r1 = LD32(r7);
                            ST32(r7, (r1 + -512));
                            r1 = LD32(r4 + 16);
                            r10 = r10 + r3;
                            r1 = r1 + r3;
                        } else {
                            r1 = LD32(r7);
                            ST32(r7, (r1 + r3));
                            r1 = LD32(r4 + 16);
                            r10 = r10 - r3;
                            r1 = r1 - r3;
                        }
                        ST32(r4 + 16, r1);
                        r2 = r10;
                        if (!(r10 >= 0)) {
                            r2 = -r10;
                        }
                        c11 = r10 > 0;
                        c1013 = c11;
                    } while (AGAIN(r2 > 0x1FF));
                    r1 = LD32(0x060759B4);
                    ST32(0x060759B8, r1);
                    r1 = LD32(0x060759B8);
                    ST32(0x060759BC, r1);
                    r1 = (SR() & ~1) | c11;
                    SETSR(((r1 & -241) | ((r6 << 2) << 2)));
                    ST32(0x0607668C, 2);
                    r0 = GCALL4(0x060166F0, r4, r5, r6, r7);
                    r0 = GCALL0(0x06043AC0);
                    ST32(0x0607668C, 0);
                    r0 = SR();
                    r6 = (int)((unsigned)((int)((unsigned)(r0 & 240) >> 2)) >> 2);
                    r1 = SR();
                    SETSR(((r1 & -241) | 240));
                    c1020 = r10 >= 0;
                }
                r2 = r10;
                if (!(c1020)) {
                    r2 = -r10;
                }
                c14 = r10 >= 0;
                if (!(r2 > 15)) {
                    r2 = 0x060759B8;
                    r1 = LD32(0x060759B8);
                    r1 = r1 + r10;
                    c1027 = c14;
                } else {
                    if (c14) {
                        r1 = LD32(0x060759B8);
                        ST32(0x060759B8, (r1 + 16));
                        r2 = 0x060759C4;
                        r1 = r10 - 16;
                        c1027 = 1;
                    } else {
                        r1 = LD32(0x060759B8);
                        ST32(0x060759B8, (r1 - 16));
                        r2 = 0x060759C4;
                        r1 = r10 + 16;
                        c1027 = 0;
                    }
                }
                ST32(r2, r1);
                c1028 = c1027;
            }
            r1 = (SR() & ~1) | c1028;
            SETSR(((r1 & -241) | ((r6 << 2) << 2)));
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06014708(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    long long m0;

    r1 = LD32(r4 + 16);
    r0 = 0x10C8;
    r6 = r6 + r1;
    r1 = LD32(0x10C8 + r4);
    r7 = r7 & 255;
    if ((r1 & r1) == 0) {
        if (!(r5 >= 0)) {
            return r0;
        } else {
            r2 = LD32(r4 + 44);
            if (r5 >= r2) {
                return r0;
            } else {
                r1 = LD32(r4 + 28);
                if (!(r6 >= r1)) {
                    return r0;
                } else {
                    r1 = LD32(r4 + 24);
                    m0 = (unsigned)(r6 * r2);
                    if (r6 >= r1) {
                        return r0;
                    } else {
                        r2 = LD32(r4 + 40);
                        r0 = r2;
                        ST8(r0 + (((int)m0) + r5), r7);
                        return r0;
                    }
                }
            }
        }
    } else {
        r0 = 0x10CC;
        r2 = LD32(0x10CC + r4);
        if (!(r2 > 2)) {
            return r0;
        } else {
            if (!(r5 >= 0)) {
                return r0;
            } else {
                r2 = LD32(r4 + 44);
                if (r5 >= r2) {
                    return r0;
                } else {
                    r1 = LD32(r4 + 28);
                    if (!(r6 >= r1)) {
                        return r0;
                    } else {
                        r1 = LD32(r4 + 24);
                        m0 = (unsigned)(r6 * r2);
                        if (r6 >= r1) {
                            return r0;
                        } else {
                            r2 = LD32(r4 + 40);
                            r0 = r2;
                            ST8(r0 + (((int)m0) + r5), r7);
                            return r0;
                        }
                    }
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601474C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11;
    long long m0;
    FRAME(sp, 80);

    r8 = r4;
    r4 = LD32(80 + (sp - 80));
    r3 = LD32(r8 + 16);
    r10 = LD32(r8 + 40);
    r9 = LD32(r8 + 44);
    r1 = LD32((84 + (sp - 80)));
    r2 = (r6 + r4) + r3;
    r11 = r1 & 255;
    ST32(sp - 80, r2);
    r1 = (r6 + r7) + r3;
    ST32(sp - 76, r1);
    ST32(sp - 72, r1);
    ST32(sp - 68, r2);
    r1 = (r6 - r4) + r3;
    ST32(sp - 64, r1);
    r6 = (r6 - r7) + r3;
    ST32(sp - 60, r6);
    ST32(sp - 56, r6);
    ST32(sp - 52, r1);
    r3 = r5 + r7;
    ST32(sp - 48, r3);
    r2 = r5 + r4;
    ST32(sp - 44, r2);
    r1 = r5 - r4;
    ST32(sp - 40, r1);
    r5 = r5 - r7;
    ST32(sp - 36, r5);
    ST32(sp - 32, r5);
    ST32(sp - 28, r1);
    ST32(sp - 24, r2);
    ST32(sp - 20, r3);
    r7 = sp - 80;
    r6 = 0;
    r5 = (sp - 80) + 28;
    do {
        r3 = LD32(r7 + 32);
        r0 = r6;
        r2 = LD32(r0 + (sp - 80));
        if (r3 >= 0) {
            if (!(r3 >= r9)) {
                r1 = LD32(r8 + 28);
                if (r2 >= r1) {
                    r1 = LD32(r8 + 24);
                    m0 = (unsigned)(r2 * r9);
                    if (!(r2 >= r1)) {
                        r0 = ((int)m0) + r3;
                        ST8(r0 + r10, r11);
                    }
                }
            }
        }
        r7 = r7 + 4;
        r6 = r6 + 4;
    } while (AGAIN(!(r7 > r5)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06014C4C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c6, c15, c21, c1009, c1012, c1032, c1040;
    FRAME(sp, 56);

    r11 = r4;
    r9 = r5;
    ST32(sp - 52, r7);
    r1 = LD32(sp + 4);
    ST32(sp - 48, ((signed char)r1));
    r1 = LD32(136 + r11);
    r8 = r6;
    r12 = LD32(sp);
    if ((r1 & r1) == 0) {
        c1012 = r8 == r12;
        r0 = LD32(sp - 52);
        if (!(c1012)) {
            r13 = LD32(sp - 52);
            if (!(r9 == r0)) {
                r1 = LD32(sp - 52);
                if (!(r13 >= r9)) {
                    ST32(sp - 52, r9);
                    r9 = r1;
                    r1 = r12;
                    r12 = r8;
                    r8 = r1;
                }
                r3 = LD32(sp - 52);
                r2 = r12 - r8;
                r3 = r3 - r9;
                r14 = 1;
                if (!(r3 >= 0)) {
                    r14 = -1;
                }
                ST32(sp - 36, 1);
                if (!(r2 >= 0)) {
                    ST32(sp - 36, -1);
                }
                r7 = r3;
                if (!(r3 >= 0)) {
                    r7 = -r3;
                }
                r1 = r2;
                if (!(r2 >= 0)) {
                    r1 = -r2;
                }
                c15 = r7 > r1;
                r1 = r3;
                if (!(c15)) {
                    r1 = r1 + r1;
                    r10 = r1 - r2;
                    ST32(sp - 44, r1);
                    ST32(sp - 40, ((r3 - r2) + (r3 - r2)));
                    while (1) {
                        r13 = LD8((7 + (sp - 52)));
                        r0 = GCALL8(0x06014708, r11, r9, r8, (r13 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                        c21 = r10 > 0;
                        if (!(r8 == r12)) {
                            POLL();
                            r13 = LD32(sp - 44);
                            c1040 = c21;
                            if (c21) {
                                r13 = LD32(sp - 40);
                                r9 = r9 + r14;
                                c1040 = 1;
                            }
                            r0 = LD32(sp - 36);
                            r10 = r10 + r13;
                            r8 = r8 + r0;
                            continue;
                        } else {
                            break;
                        }
                    }
                    r0 = 1;
                    return r0;
                } else {
                    r1 = r2 + r2;
                    r10 = r1 - r3;
                    ST32(sp - 44, r1);
                    ST32(sp - 40, ((r2 - r3) + (r2 - r3)));
                    r12 = 0x06014708;
                    r0 = LD8((7 + (sp - 52)));
                    r0 = GCALL8(0x06014708, r11, r9, r8, (r0 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                    r13 = LD32(sp - 52);
                    r0 = 1;
                    if (!(r9 == r13)) {
                        c1032 = r10 > 0;
                        do {
                            r0 = LD32(sp - 44);
                            if (c1032) {
                                r13 = LD32(sp - 40);
                                r9 = r9 + r14;
                                r0 = LD32(sp - 36);
                                r10 = r10 + r13;
                                r8 = r8 + r0;
                            } else {
                                r10 = r10 + r0;
                                r9 = r9 + r14;
                            }
                            r13 = LD8((7 + (sp - 52)));
                            r0 = GCALL8(r12, r11, r9, r8, (r13 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                            r0 = LD32(sp - 52);
                            c1032 = r10 > 0;
                        } while (AGAIN(!(r9 == r0)));
                        r0 = 1;
                    }
                    return r0;
                }
            } else {
                r13 = 7;
                if (r12 >= r8) {
                    r0 = LD8(7 + (sp - 52));
                    r7 = r12;
                    r6 = r8;
                    r5 = r9;
                    r4 = r11;
                    ST32((sp - 56), (r0 & 255));
                    r1 = 0x060146A4;
                } else {
                    r13 = LD8((r13 + (sp - 52)));
                    ST32((sp - 56), (r13 & 255));
                    r1 = 0x060146A4;
                    r7 = r8;
                    r6 = r12;
                    r5 = r9;
                    r4 = r11;
                }
                r0 = GCALL7(r1, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                r0 = 1;
                return r0;
            }
        } else {
            r13 = LD8((7 + (sp - 52)));
            ST32((sp - 56), (r13 & 255));
            r1 = 0x06014638;
            r7 = r8;
            r6 = LD32(sp - 52);
            r5 = r9;
            r4 = r11;
            r0 = GCALL7(r1, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
            r0 = 1;
            return r0;
        }
    } else {
        r1 = LD32(0x10C8 + r11);
        if ((r1 & r1) == 0) {
            r0 = GCALL6(0x06015D00, r11, 40, 0, 0, LD32((sp - 52)), LD32((sp - 48)));
            r5 = 0;
            if ((r0 & r0) == 0) {
                r0 = 0;
                return r0;
            } else {
                r0 = GCALL6(0x06013C60, r11, r5, 0, 0, LD32((sp - 52)), LD32((sp - 48)));
                r3 = r0;
                ST16((r3 + 24), r9);
                r13 = LD16((2 + (sp - 52)));
                ST16((r3 + 26), r13);
                ST32(r3 + 28, r8);
                ST32(r3 + 32, r12);
                r0 = LD16((6 + (sp - 52)));
                ST16((r3 + 36), r0);
                if (!(r8 > r12)) {
                    ST32(r3 + 16, r12);
                    ST32(r3 + 12, r8);
                } else {
                    ST32(r3 + 16, r8);
                    ST32(r3 + 12, r12);
                }
                r2 = 148;
                r1 = LD32(r11 + 148);
                c6 = (r1 & r1) == 0;
                c1009 = c6;
                if (!(c6)) {
                    ST32(r1, r3);
                    c1009 = 0;
                }
                r0 = r11;
                ST32(r0 + r2, (r3 + 4));
                r1 = LD32(r0 + 152);
                ST32(r0 + 152, (r1 + 40));
                r1 = LD32(r0 + 164);
                ST32(r0 + 164, (r1 + 1));
                c1012 = r8 == r12;
                r0 = LD32(sp - 52);
                if (!(c1012)) {
                    r13 = LD32(sp - 52);
                    if (!(r9 == r0)) {
                        r1 = LD32(sp - 52);
                        if (!(r13 >= r9)) {
                            ST32(sp - 52, r9);
                            r9 = r1;
                            r1 = r12;
                            r12 = r8;
                            r8 = r1;
                        }
                        r3 = LD32(sp - 52);
                        r2 = r12 - r8;
                        r3 = r3 - r9;
                        r14 = 1;
                        if (!(r3 >= 0)) {
                            r14 = -1;
                        }
                        ST32(sp - 36, 1);
                        if (!(r2 >= 0)) {
                            ST32(sp - 36, -1);
                        }
                        r7 = r3;
                        if (!(r3 >= 0)) {
                            r7 = -r3;
                        }
                        r1 = r2;
                        if (!(r2 >= 0)) {
                            r1 = -r2;
                        }
                        c15 = r7 > r1;
                        r1 = r3;
                        if (!(c15)) {
                            r1 = r1 + r1;
                            r10 = r1 - r2;
                            ST32(sp - 44, r1);
                            ST32(sp - 40, ((r3 - r2) + (r3 - r2)));
                            while (1) {
                                r13 = LD8((7 + (sp - 52)));
                                r0 = GCALL8(0x06014708, r11, r9, r8, (r13 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                                c21 = r10 > 0;
                                if (!(r8 == r12)) {
                                    POLL();
                                    r13 = LD32(sp - 44);
                                    c1040 = c21;
                                    if (c21) {
                                        r13 = LD32(sp - 40);
                                        r9 = r9 + r14;
                                        c1040 = 1;
                                    }
                                    r0 = LD32(sp - 36);
                                    r10 = r10 + r13;
                                    r8 = r8 + r0;
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            r0 = 1;
                            return r0;
                        } else {
                            r1 = r2 + r2;
                            r10 = r1 - r3;
                            ST32(sp - 44, r1);
                            ST32(sp - 40, ((r2 - r3) + (r2 - r3)));
                            r12 = 0x06014708;
                            r0 = LD8((7 + (sp - 52)));
                            r0 = GCALL8(0x06014708, r11, r9, r8, (r0 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                            r13 = LD32(sp - 52);
                            r0 = 1;
                            if (!(r9 == r13)) {
                                c1032 = r10 > 0;
                                do {
                                    r0 = LD32(sp - 44);
                                    if (c1032) {
                                        r13 = LD32(sp - 40);
                                        r9 = r9 + r14;
                                        r0 = LD32(sp - 36);
                                        r10 = r10 + r13;
                                        r8 = r8 + r0;
                                    } else {
                                        r10 = r10 + r0;
                                        r9 = r9 + r14;
                                    }
                                    r13 = LD8((7 + (sp - 52)));
                                    r0 = GCALL8(r12, r11, r9, r8, (r13 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                                    r0 = LD32(sp - 52);
                                    c1032 = r10 > 0;
                                } while (AGAIN(!(r9 == r0)));
                                r0 = 1;
                            }
                            return r0;
                        }
                    } else {
                        r13 = 7;
                        if (r12 >= r8) {
                            r0 = LD8(7 + (sp - 52));
                            r7 = r12;
                            r6 = r8;
                            r5 = r9;
                            r4 = r11;
                            ST32((sp - 56), (r0 & 255));
                            r1 = 0x060146A4;
                        } else {
                            r13 = LD8((r13 + (sp - 52)));
                            ST32((sp - 56), (r13 & 255));
                            r1 = 0x060146A4;
                            r7 = r8;
                            r6 = r12;
                            r5 = r9;
                            r4 = r11;
                        }
                        r0 = GCALL7(r1, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                        r0 = 1;
                        return r0;
                    }
                } else {
                    r13 = LD8((7 + (sp - 52)));
                    ST32((sp - 56), (r13 & 255));
                    r1 = 0x06014638;
                    r7 = r8;
                    r6 = LD32(sp - 52);
                    r5 = r9;
                    r4 = r11;
                    r0 = GCALL7(r1, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                    r0 = 1;
                    return r0;
                }
            }
        } else {
            r0 = LD32(0x10CC + r11);
            c1012 = r8 == r12;
            if (!(r0 == 3)) {
                r0 = LD32(sp - 52);
                if (!(c1012)) {
                    r13 = LD32(sp - 52);
                    if (!(r9 == r0)) {
                        r1 = LD32(sp - 52);
                        if (!(r13 >= r9)) {
                            ST32(sp - 52, r9);
                            r9 = r1;
                            r1 = r12;
                            r12 = r8;
                            r8 = r1;
                        }
                        r3 = LD32(sp - 52);
                        r2 = r12 - r8;
                        r3 = r3 - r9;
                        r14 = 1;
                        if (!(r3 >= 0)) {
                            r14 = -1;
                        }
                        ST32(sp - 36, 1);
                        if (!(r2 >= 0)) {
                            ST32(sp - 36, -1);
                        }
                        r7 = r3;
                        if (!(r3 >= 0)) {
                            r7 = -r3;
                        }
                        r1 = r2;
                        if (!(r2 >= 0)) {
                            r1 = -r2;
                        }
                        c15 = r7 > r1;
                        r1 = r3;
                        if (!(c15)) {
                            r1 = r1 + r1;
                            r10 = r1 - r2;
                            ST32(sp - 44, r1);
                            ST32(sp - 40, ((r3 - r2) + (r3 - r2)));
                            while (1) {
                                r13 = LD8((7 + (sp - 52)));
                                r0 = GCALL8(0x06014708, r11, r9, r8, (r13 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                                c21 = r10 > 0;
                                if (!(r8 == r12)) {
                                    POLL();
                                    r13 = LD32(sp - 44);
                                    c1040 = c21;
                                    if (c21) {
                                        r13 = LD32(sp - 40);
                                        r9 = r9 + r14;
                                        c1040 = 1;
                                    }
                                    r0 = LD32(sp - 36);
                                    r10 = r10 + r13;
                                    r8 = r8 + r0;
                                    continue;
                                } else {
                                    break;
                                }
                            }
                            r0 = 1;
                            return r0;
                        } else {
                            r1 = r2 + r2;
                            r10 = r1 - r3;
                            ST32(sp - 44, r1);
                            ST32(sp - 40, ((r2 - r3) + (r2 - r3)));
                            r12 = 0x06014708;
                            r0 = LD8((7 + (sp - 52)));
                            r0 = GCALL8(0x06014708, r11, r9, r8, (r0 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                            r13 = LD32(sp - 52);
                            r0 = 1;
                            if (!(r9 == r13)) {
                                c1032 = r10 > 0;
                                do {
                                    r0 = LD32(sp - 44);
                                    if (c1032) {
                                        r13 = LD32(sp - 40);
                                        r9 = r9 + r14;
                                        r0 = LD32(sp - 36);
                                        r10 = r10 + r13;
                                        r8 = r8 + r0;
                                    } else {
                                        r10 = r10 + r0;
                                        r9 = r9 + r14;
                                    }
                                    r13 = LD8((7 + (sp - 52)));
                                    r0 = GCALL8(r12, r11, r9, r8, (r13 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                                    r0 = LD32(sp - 52);
                                    c1032 = r10 > 0;
                                } while (AGAIN(!(r9 == r0)));
                                r0 = 1;
                            }
                            return r0;
                        }
                    } else {
                        r13 = 7;
                        if (r12 >= r8) {
                            r0 = LD8(7 + (sp - 52));
                            r7 = r12;
                            r6 = r8;
                            r5 = r9;
                            r4 = r11;
                            ST32((sp - 56), (r0 & 255));
                            r1 = 0x060146A4;
                        } else {
                            r13 = LD8((r13 + (sp - 52)));
                            ST32((sp - 56), (r13 & 255));
                            r1 = 0x060146A4;
                            r7 = r8;
                            r6 = r12;
                            r5 = r9;
                            r4 = r11;
                        }
                        r0 = GCALL7(r1, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                        r0 = 1;
                        return r0;
                    }
                } else {
                    r13 = LD8((7 + (sp - 52)));
                    ST32((sp - 56), (r13 & 255));
                    r1 = 0x06014638;
                    r7 = r8;
                    r6 = LD32(sp - 52);
                    r5 = r9;
                    r4 = r11;
                    r0 = GCALL7(r1, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                    r0 = 1;
                    return r0;
                }
            } else {
                r0 = GCALL6(0x06015D00, r11, 40, 0, 0, LD32((sp - 52)), LD32((sp - 48)));
                r5 = 0;
                if ((r0 & r0) == 0) {
                    r0 = 0;
                    return r0;
                } else {
                    r0 = GCALL6(0x06013C60, r11, r5, 0, 0, LD32((sp - 52)), LD32((sp - 48)));
                    r3 = r0;
                    ST16((r3 + 24), r9);
                    r13 = LD16((2 + (sp - 52)));
                    ST16((r3 + 26), r13);
                    ST32(r3 + 28, r8);
                    ST32(r3 + 32, r12);
                    r0 = LD16((6 + (sp - 52)));
                    ST16((r3 + 36), r0);
                    if (!(r8 > r12)) {
                        ST32(r3 + 16, r12);
                        ST32(r3 + 12, r8);
                    } else {
                        ST32(r3 + 16, r8);
                        ST32(r3 + 12, r12);
                    }
                    r2 = 148;
                    r1 = LD32(r11 + 148);
                    c6 = (r1 & r1) == 0;
                    c1009 = c6;
                    if (!(c6)) {
                        ST32(r1, r3);
                        c1009 = 0;
                    }
                    r0 = r11;
                    ST32(r0 + r2, (r3 + 4));
                    r1 = LD32(r0 + 152);
                    ST32(r0 + 152, (r1 + 40));
                    r1 = LD32(r0 + 164);
                    ST32(r0 + 164, (r1 + 1));
                    c1012 = r8 == r12;
                    r0 = LD32(sp - 52);
                    if (!(c1012)) {
                        r13 = LD32(sp - 52);
                        if (!(r9 == r0)) {
                            r1 = LD32(sp - 52);
                            if (!(r13 >= r9)) {
                                ST32(sp - 52, r9);
                                r9 = r1;
                                r1 = r12;
                                r12 = r8;
                                r8 = r1;
                            }
                            r3 = LD32(sp - 52);
                            r2 = r12 - r8;
                            r3 = r3 - r9;
                            r14 = 1;
                            if (!(r3 >= 0)) {
                                r14 = -1;
                            }
                            ST32(sp - 36, 1);
                            if (!(r2 >= 0)) {
                                ST32(sp - 36, -1);
                            }
                            r7 = r3;
                            if (!(r3 >= 0)) {
                                r7 = -r3;
                            }
                            r1 = r2;
                            if (!(r2 >= 0)) {
                                r1 = -r2;
                            }
                            c15 = r7 > r1;
                            r1 = r3;
                            if (!(c15)) {
                                r1 = r1 + r1;
                                r10 = r1 - r2;
                                ST32(sp - 44, r1);
                                ST32(sp - 40, ((r3 - r2) + (r3 - r2)));
                                while (1) {
                                    r13 = LD8((7 + (sp - 52)));
                                    r0 = GCALL8(0x06014708, r11, r9, r8, (r13 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                                    c21 = r10 > 0;
                                    if (!(r8 == r12)) {
                                        POLL();
                                        r13 = LD32(sp - 44);
                                        c1040 = c21;
                                        if (c21) {
                                            r13 = LD32(sp - 40);
                                            r9 = r9 + r14;
                                            c1040 = 1;
                                        }
                                        r0 = LD32(sp - 36);
                                        r10 = r10 + r13;
                                        r8 = r8 + r0;
                                        continue;
                                    } else {
                                        break;
                                    }
                                }
                                r0 = 1;
                                return r0;
                            } else {
                                r1 = r2 + r2;
                                r10 = r1 - r3;
                                ST32(sp - 44, r1);
                                ST32(sp - 40, ((r2 - r3) + (r2 - r3)));
                                r12 = 0x06014708;
                                r0 = LD8((7 + (sp - 52)));
                                r0 = GCALL8(0x06014708, r11, r9, r8, (r0 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                                r13 = LD32(sp - 52);
                                r0 = 1;
                                if (!(r9 == r13)) {
                                    c1032 = r10 > 0;
                                    do {
                                        r0 = LD32(sp - 44);
                                        if (c1032) {
                                            r13 = LD32(sp - 40);
                                            r9 = r9 + r14;
                                            r0 = LD32(sp - 36);
                                            r10 = r10 + r13;
                                            r8 = r8 + r0;
                                        } else {
                                            r10 = r10 + r0;
                                            r9 = r9 + r14;
                                        }
                                        r13 = LD8((7 + (sp - 52)));
                                        r0 = GCALL8(r12, r11, r9, r8, (r13 & 255), LD32((sp - 52)), LD32((sp - 48)), LD32((sp - 44)), LD32((sp - 40)));
                                        r0 = LD32(sp - 52);
                                        c1032 = r10 > 0;
                                    } while (AGAIN(!(r9 == r0)));
                                    r0 = 1;
                                }
                                return r0;
                            }
                        } else {
                            r13 = 7;
                            if (r12 >= r8) {
                                r0 = LD8(7 + (sp - 52));
                                r7 = r12;
                                r6 = r8;
                                r5 = r9;
                                r4 = r11;
                                ST32((sp - 56), (r0 & 255));
                                r1 = 0x060146A4;
                            } else {
                                r13 = LD8((r13 + (sp - 52)));
                                ST32((sp - 56), (r13 & 255));
                                r1 = 0x060146A4;
                                r7 = r8;
                                r6 = r12;
                                r5 = r9;
                                r4 = r11;
                            }
                            r0 = GCALL7(r1, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                            r0 = 1;
                            return r0;
                        }
                    } else {
                        r13 = LD8((7 + (sp - 52)));
                        ST32((sp - 56), (r13 & 255));
                        r1 = 0x06014638;
                        r7 = r8;
                        r6 = LD32(sp - 52);
                        r5 = r9;
                        r4 = r11;
                        r0 = GCALL7(r1, r4, r5, r6, r7, LD32((sp - 56)), LD32((sp - 52)), LD32((sp - 48)));
                        r0 = 1;
                        return r0;
                    }
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06015610(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c2, c7, c14, c16, c22, c28, c35, c41, c43, c47, c1006, c1019, c1033, c1038, c1051, c1055, c1059;
    FRAME(sp, 120);

    ST32(sp - 120, r4);
    ST32(sp - 116, r5);
    ST32(sp - 112, r6);
    ST32(sp - 108, r7);
    r0 = LD32(r4 + 16);
    ST32(sp - 100, r0);
    r11 = LD32(r4 + 44);
    ST32(sp - 96, r11);
    r0 = LD32(r4 + 40);
    ST32(sp - 92, r0);
    r11 = LD32(r6 + 4);
    ST32(sp - 88, r11);
    r0 = LD32(r6 + 8);
    ST32(sp - 84, r0);
    r11 = LD32(r6 + 12);
    ST32(sp - 80, r11);
    ST32(sp - 76, 0);
    ST32(sp - 72, 0);
    ST32(sp - 68, 0);
    ST32(sp - 64, 0);
    r0 = LD32(r6);
    ST32(sp - 60, r0);
    ST32((64 + (sp - 120)), 0);
    r0 = LD32(sp - 120);
    r1 = LD32(r0 + 0x10D4);
    ST32(68 + (sp - 120), r1);
    r0 = LD32(sp - 108);
    ST32((72 + (sp - 120)), r0);
    r11 = LD32(sp - 112);
    r0 = LD32(r11 + 20);
    ST32((76 + (sp - 120)), r0);
    r1 = LD32(sp - 112);
    r1 = LD8((r1 + 16));
    ST32((80 + (sp - 120)), (r1 & 255));
    r0 = LD32((68 + (sp - 120)));
    r11 = LD32(sp - 108);
    if ((r0 & r0) == 0) {
        r4 = LD32(sp - 116);
        r0 = GCALL8(0x0601CC78, r4, 128, 0, r7, LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)), LD32((sp - 108)));
        ST32((64 + (sp - 120)), r0);
        r11 = LD32(64 + (sp - 120));
        r0 = LD32(r11 + 8);
        ST32(sp - 76, r0);
        r11 = LD32(sp - 108);
    }
    r1 = LD8(r11);
    while (1) {
        r9 = r1 & 255;
        r0 = 68;
        if ((r9 & r9) == 0) {
            break;
        } else {
            POLL();
            r0 = LD32(r0 + (sp - 120));
            r11 = 72;
            if ((r0 & r0) == 0) {
                r11 = LD32(sp - 108);
                ST32(sp - 108, (r11 + 1));
            } else {
                r11 = r11 + (sp - 120);
                r0 = LD32(r11);
                r0 = r0 + 2;
                ST32(r11, r0);
                r9 = LD16((r0 - 2));
                r11 = LD32(sp - 108);
                r4 = LD32(sp - 116);
                r9 = r9 & 0xFFFF;
                ST32(sp - 108, (r11 + 2));
                r8 = (int)((unsigned)r9 >> 8);
                r7 = R(7);
                r0 = GCALL8(0x0601CC78, r4, r8, 0, 0, LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)), LD32((sp - 108)));
                ST32((64 + (sp - 120)), r0);
                r9 = r9 & 255;
                r11 = LD32((64 + (sp - 120)));
                r0 = LD32(r11 + 8);
                c2 = (r8 & 0xFFFF) == 128;
                ST32(sp - 76, r0);
                c1006 = c2;
                if (c2) {
                    c1006 = (unsigned)r9 > (unsigned)127;
                }
                r11 = LD32(sp - 112);
                r0 = LD32(sp - 80);
                r1 = LD32(r11 + 8);
                r1 = r1 + r0;
                r0 = LD32((64 + (sp - 120)));
                r2 = LD32(r0 + 32);
                ST32(sp - 84, (r1 - r2));
            }
            r0 = r9;
            if ((unsigned)r9 > (unsigned)32) {
                r4 = LD32((64 + (sp - 120)));
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL8(0x06043454, r4, r9, 0, 0, LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)), LD32((sp - 108)));
                r13 = r0;
                r14 = 0;
                r7 = 0;
                r0 = LD32(sp - 76);
                r3 = 0;
                r1 = LD8(r0 + r9);
                ST32(sp - 104, (r1 & 255));
                if ((r13 & r13) == 0) {
                    c1019 = r14 > 0;
                } else {
                    r0 = LD32(sp - 120);
                    r1 = LD32(r0 + 140);
                    c7 = (r1 & r1) == 0;
                    r1 = r13;
                    if (c7) {
                        ST8((r13 + 14), 1);
                        r1 = LD8((r13 + 6));
                        r14 = r1 & 255;
                        r1 = LD8((r13 + 7));
                        ST32(sp - 72, (r1 & 255));
                        ST32(sp - 60, 0);
                        r0 = LD32(r13 + 20);
                        ST32(sp - 68, r0);
                        r1 = LD8((r13 + 8));
                        ST32(sp - 64, (r1 & 255));
                        r1 = LD8((r13 + 11));
                        ST32(sp - 104, (r1 & 255));
                        r1 = LD32(sp - 88);
                        r11 = LD32(sp - 96);
                        r3 = (r1 >> 1) >> 1;
                        c14 = r3 >= 0;
                        if ((r3 + r14) > r11) {
                            r14 = (short)(r11 - r3);
                        }
                        r1 = r14;
                        if (!(c14)) {
                            r14 = (short)(r1 + r3);
                            r7 = -r3;
                            r3 = 0;
                        }
                        c1019 = r14 > 0;
                    } else {
                        r1 = LD8((r1 + 13));
                        if (((r1 & 255) & (r1 & 255)) == 0) {
                            c1019 = r14 > 0;
                        } else {
                            r1 = LD32(r13 + 20);
                            c1019 = r14 > 0;
                            if (!((r1 & r1) == 0)) {
                                ST8((r13 + 14), 1);
                                r1 = LD8((r13 + 6));
                                r14 = r1 & 255;
                                r1 = LD8((r13 + 7));
                                ST32(sp - 72, (r1 & 255));
                                ST32(sp - 60, 0);
                                r0 = LD32(r13 + 20);
                                ST32(sp - 68, r0);
                                r1 = LD8((r13 + 8));
                                ST32(sp - 64, (r1 & 255));
                                r1 = LD8((r13 + 11));
                                ST32(sp - 104, (r1 & 255));
                                r1 = LD32(sp - 88);
                                r11 = LD32(sp - 96);
                                r3 = (r1 >> 1) >> 1;
                                c14 = r3 >= 0;
                                if ((r3 + r14) > r11) {
                                    r14 = (short)(r11 - r3);
                                }
                                r1 = r14;
                                if (!(c14)) {
                                    r14 = (short)(r1 + r3);
                                    r7 = -r3;
                                    r3 = 0;
                                }
                                c1019 = r14 > 0;
                            }
                        }
                    }
                }
                c16 = (r13 & r13) == 0;
                if (c1019) {
                    r1 = LD32(sp - 84);
                    r0 = LD32(sp - 72);
                    r9 = LD32(sp - 100);
                    r11 = LD32(sp - 64);
                    r1 = (r1 - 1) + r0;
                    r0 = LD32(sp - 60);
                    r9 = r9 + r1;
                    r12 = r11 * r0;
                    r11 = LD32(sp - 96);
                    r12 = r12 + (r7 >> 1);
                    r1 = r11 * r9;
                    r11 = LD32(sp - 92);
                    ST32((84 + (sp - 120)), (r11 + (r1 + r3)));
                    r0 = LD32(76 + (sp - 120));
                    r8 = LD32(sp - 72);
                    if ((r0 & r0) == 0) {
                        c35 = (r13 & r13) == 0;
                        c1059 = c35;
                        if (r8 > 0) {
                            r10 = 255;
                            do {
                                r11 = LD32(sp - 120);
                                r1 = LD32(r11 + 28);
                                if (r9 >= r1) {
                                    r1 = LD32(r11 + 24);
                                    if (!(r9 >= r1)) {
                                        r5 = LD32(sp - 68);
                                        r5 = r5 + r12;
                                        r4 = r14;
                                        r6 = LD32((84 + (sp - 120)));
                                        if (r4 > 0) {
                                            do {
                                                r1 = LD8(r5);
                                                r5 = r5 + 1;
                                                r1 = LD16(((r1 & 255) + (r1 & 255)) + 0x06086D90);
                                                r7 = r1 & 0xFFFF;
                                                r1 = r7;
                                                if (!((r7 & r7) == 0)) {
                                                    r1 = (int)((unsigned)r1 >> 8);
                                                    if (!((r1 & r1) == 0)) {
                                                        r3 = LD32((80 + (sp - 120)));
                                                        r3 = r3 & r1;
                                                        c41 = r1 == r10;
                                                        r2 = r3;
                                                        c1051 = c41;
                                                        if (!(c41)) {
                                                            r1 = LD8(r6);
                                                            r2 = r1 | r3;
                                                            c1051 = 0;
                                                        }
                                                        ST8(r6, r2);
                                                    }
                                                    r1 = r7 & r10;
                                                    r7 = r6;
                                                    if (!((r1 & r1) == 0)) {
                                                        r7 = r7 + 1;
                                                        r3 = LD32(80 + (sp - 120));
                                                        c43 = r1 == r10;
                                                        r3 = r3 & r1;
                                                        r2 = r3;
                                                        c1055 = c43;
                                                        if (!(c43)) {
                                                            r1 = LD8(r7);
                                                            r2 = r1 | r3;
                                                            c1055 = 0;
                                                        }
                                                        ST8(r7, r2);
                                                    }
                                                }
                                                r4 = r4 - 2;
                                                r6 = r6 + 2;
                                            } while (AGAIN(r4 > 0));
                                        }
                                    }
                                }
                                r9 = r9 - 1;
                                r11 = LD32(sp - 64);
                                r12 = r12 + r11;
                                r11 = LD32((84 + (sp - 120)));
                                r8 = r8 - 1;
                                r0 = LD32(sp - 96);
                                ST32((84 + (sp - 120)), (r11 - r0));
                            } while (AGAIN(r8 > 0));
                            c1059 = (r13 & r13) == 0;
                        }
                    } else {
                        c22 = (r13 & r13) == 0;
                        if (r8 > 0) {
                            r10 = 255;
                            do {
                                r11 = LD32(sp - 120);
                                r1 = LD32(r11 + 28);
                                if (r9 >= r1) {
                                    r1 = LD32(r11 + 24);
                                    if (!(r9 >= r1)) {
                                        r5 = LD32(sp - 68);
                                        r5 = r5 + r12;
                                        r4 = r14;
                                        r6 = LD32((84 + (sp - 120)));
                                        if (r4 > 0) {
                                            do {
                                                r1 = LD8(r5);
                                                r5 = r5 + 1;
                                                r1 = LD16(((r1 & 255) + (r1 & 255)) + 0x06086D90);
                                                r7 = r1 & 0xFFFF;
                                                r1 = r7;
                                                if (!((r7 & r7) == 0)) {
                                                    r1 = (int)((unsigned)r1 >> 8);
                                                    c28 = r1 == r10;
                                                    if (!((r1 & r1) == 0)) {
                                                        r2 = r1;
                                                        if (c28) {
                                                            r11 = LD32((80 + (sp - 120)));
                                                            r1 = r1 & r11;
                                                            c1033 = 1;
                                                        } else {
                                                            r1 = LD8(r6);
                                                            r1 = r1 & (r2 ^ r10);
                                                            c1033 = 0;
                                                        }
                                                        ST8(r6, r1);
                                                    }
                                                    r1 = r7 & r10;
                                                    r3 = r6;
                                                    if (!((r1 & r1) == 0)) {
                                                        r3 = r3 + 1;
                                                        if (r1 == r10) {
                                                            r0 = LD32(80 + (sp - 120));
                                                            r1 = r1 & r0;
                                                            c1038 = 1;
                                                        } else {
                                                            r2 = r1 ^ r10;
                                                            r1 = LD8(r3);
                                                            r1 = r1 & r2;
                                                            c1038 = 0;
                                                        }
                                                        ST8(r3, r1);
                                                    }
                                                }
                                                r4 = r4 - 2;
                                                r6 = r6 + 2;
                                            } while (AGAIN(r4 > 0));
                                        }
                                    }
                                }
                                r9 = r9 - 1;
                                r11 = LD32(sp - 64);
                                r12 = r12 + r11;
                                r11 = LD32((84 + (sp - 120)));
                                r8 = r8 - 1;
                                r0 = LD32(sp - 96);
                                ST32((84 + (sp - 120)), (r11 - r0));
                            } while (AGAIN(r8 > 0));
                            c1059 = (r13 & r13) == 0;
                        } else {
                            c1059 = c22;
                        }
                    }
                } else {
                    c1059 = c16;
                }
                if (!(c1059)) {
                    r0 = GCALL8(0x06043340, r13, 0, 0, 0, LD32((sp - 120)), LD32((sp - 116)), LD32((sp - 112)), LD32((sp - 108)));
                }
                r11 = LD32(sp - 88);
                r0 = LD32(sp - 104);
                r11 = r11 + r0;
                ST32(sp - 88, r11);
                r0 = LD32(sp - 108);
            } else {
                c47 = r0 == 32;
                r0 = LD32(sp - 108);
                if (c47) {
                    r0 = LD32(sp - 76);
                    r1 = LD8(r0 + r9);
                    r11 = LD32(sp - 88);
                    r11 = r11 + (r1 & 255);
                    ST32(sp - 88, r11);
                    r0 = LD32(sp - 108);
                }
            }
            r1 = LD8(r0);
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06015A5C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c4, c11, c16;
    int v36;
    int v40;
    int v44;
    int v48;
    int v52;
    int v56;

    r14 = r4;
    r11 = r5;
    r12 = r6;
    r8 = r7;
    v36 = 0;
    r0 = LD32(r14 + 16);
    r13 = 200;
    v40 = r0;
    r3 = r0 + r8;
    r0 = r11;
    r1 = LD32(r0 + 200);
    r2 = r3 + r1;
    r1 = LD32(r14 + 28);
    r9 = 0;
    if (r2 >= r1) {
        r1 = LD32(r14 + 24);
        if (!(r3 >= r1)) {
            r0 = GCALL6(0x06025AE0, r11, r5, r6, r7, v40, v36);
            r1 = LD32(192 + r11);
            if ((r1 & r1) == 0) {
                r9 = 1;
            }
            r10 = 216;
            r3 = LD16(r11 + 216);
            r2 = (short)r3;
            c4 = (r9 & r9) == 0;
            if (!((r2 & r2) == 0)) {
                r2 = r2 + r2;
                r1 = LD32(196 + r11);
                r7 = ((r1 + r12) + r2) - 1;
                r1 = LD16(220 + r11);
                r6 = r8 + r1;
                r1 = LD16(218 + r11);
                r5 = r12 + r1;
                v44 = 1;
                v48 = (r3 + 2) & 255;
                r1 = 123;
                if (!((r9 & r9) == 0)) {
                    r1 = -1;
                }
                v52 = r1;
                r1 = LD32(r11 + r13);
                r0 = GCALL8(0x060153C8, r14, r5, r6, r7, (((r1 + r8) + r2) - 1), v52, v48, v44);
                r1 = LD16(r11 + r10);
                r12 = r12 + r1;
                r8 = r8 + r1;
            } else {
                if (!(c4)) {
                    r2 = r2 + r2;
                    r1 = LD32(196 + r11);
                    r7 = ((r1 + r12) + r2) - 1;
                    r1 = LD16(220 + r11);
                    r6 = r8 + r1;
                    r1 = LD16(218 + r11);
                    r5 = r12 + r1;
                    v44 = 1;
                    v48 = (r3 + 2) & 255;
                    r1 = 123;
                    if (!((r9 & r9) == 0)) {
                        r1 = -1;
                    }
                    v52 = r1;
                    r1 = LD32(r11 + r13);
                    r0 = GCALL8(0x060153C8, r14, r5, r6, r7, (((r1 + r8) + r2) - 1), v52, v48, v44);
                    r1 = LD16(r11 + r10);
                    r12 = r12 + r1;
                    r8 = r8 + r1;
                }
            }
            r1 = LD16(218 + r11);
            r12 = r12 + r1;
            r1 = LD16(220 + r11);
            r8 = r8 + r1;
            if ((r9 & r9) == 0) {
                r6 = LD32(224 + r11);
                r1 = LD32(228 + r11);
                c11 = r12 >= 0;
                if (!((r1 & r1) == 0)) {
                    r0 = LD32(232 + r11);
                    v36 = r0;
                }
                r7 = 0;
                if (!(c11)) {
                    r7 = -r12;
                    r12 = 0;
                }
                r13 = 0x400 - r12;
                r1 = LD32(196 + r11);
                r1 = r1 - r7;
                if (r13 > r1) {
                    r13 = r1;
                }
                r1 = LD32(r14 + 28);
                r2 = v40 + r8;
                r3 = r1;
                if (r2 >= r1) {
                    r10 = r2;
                    r3 = 0;
                } else {
                    r3 = r3 - r2;
                    r10 = r1;
                }
                r1 = LD32(r14 + 24);
                r10 = r1 - r10;
                r1 = r3;
                if (r10 >= 0) {
                    r2 = LD32(200 + r11);
                    r1 = r1 + r10;
                    c16 = (r6 & r6) == 0;
                    if (r1 > r2) {
                        r10 = r10 - (r1 - r2);
                    }
                    r0 = v36;
                    if (c16) {
                        r9 = r7;
                        if ((r0 & r0) == 0) {
                            r1 = LD32(212 + r11);
                            r9 = r9 + (r3 * r1);
                        }
                        r2 = LD32(r14 + 44);
                        r8 = (((r8 + r3) + v40) * r2) + r12;
                        if (r10 > 0) {
                            r12 = r3 << 2;
                            do {
                                r0 = v36;
                                if ((r0 & r0) == 0) {
                                    r1 = LD32(192 + r11);
                                    r5 = r1;
                                } else {
                                    r1 = LD32(r0 + r12);
                                    r5 = r1;
                                }
                                r5 = r5 + r9;
                                r1 = LD32(r14 + 40);
                                r4 = r1 + r8;
                                if (r13 > 0) {
                                    r0 = GCALL6(0x0604B358, r4, r5, r13, 0, v40, v36);
                                }
                                if ((v36 & v36) == 0) {
                                    r1 = LD32(212 + r11);
                                    r9 = r9 + r1;
                                }
                                r1 = LD32(r14 + 44);
                                r12 = r12 + 4;
                                r10 = r10 - 1;
                                r8 = r8 + r1;
                            } while (AGAIN(r10 > 0));
                        }
                    } else {
                        r9 = r7;
                        if ((r0 & r0) == 0) {
                            r1 = LD32(212 + r11);
                            r9 = r9 + (r3 * r1);
                        }
                        r2 = LD32(r14 + 44);
                        r8 = (((r8 + r3) + v40) * r2) + r12;
                        if (r10 > 0) {
                            r2 = r3 << 2;
                            do {
                                r0 = v36;
                                if ((r0 & r0) == 0) {
                                    r1 = LD32(192 + r11);
                                    r5 = r1;
                                } else {
                                    r1 = LD32(r0 + r2);
                                    r5 = r1;
                                }
                                r5 = r5 + r9;
                                r1 = LD32(r14 + 40);
                                r3 = 0;
                                r4 = r1 + r8;
                                if (!(0 >= r13)) {
                                    do {
                                        r1 = LD8(r5);
                                        r5 = r5 + 1;
                                        r1 = r1 & 255;
                                        if (!((r1 & r1) == 0)) {
                                            ST8(r4 + r3, r1);
                                        }
                                        r3 = r3 + 1;
                                    } while (AGAIN(!(r3 >= r13)));
                                }
                                if ((v36 & v36) == 0) {
                                    r1 = LD32(212 + r11);
                                    r9 = r9 + r1;
                                }
                                r1 = LD32(r14 + 44);
                                r2 = r2 + 4;
                                r10 = r10 - 1;
                                r8 = r8 + r1;
                            } while (AGAIN(r10 > 0));
                        }
                    }
                }
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL6(0x06025AB4, r11, 0, 0, 0, v40, v36);
            } else {
                r5 = R(5);
                r6 = R(6);
                r7 = R(7);
                r0 = GCALL6(0x06025AB4, r11, 0, 0, 0, v40, v36);
                r3 = LD32(0x060791C4);
                if (!((r3 & r3) == 0)) {
                    r0 = 196;
                    r2 = LD32(196 + r11);
                    r1 = LD32(196 + r3);
                    if (r2 >= r1) {
                        r0 = 200;
                        r2 = LD32(200 + r11);
                        r1 = LD32(200 + r3);
                        r11 = r3;
                        if (r2 >= r1) {
                            r6 = LD32(224 + r11);
                            r1 = LD32(228 + r11);
                            c11 = r12 >= 0;
                            if (!((r1 & r1) == 0)) {
                                r0 = LD32(232 + r11);
                                v36 = r0;
                            }
                            r7 = 0;
                            if (!(c11)) {
                                r7 = -r12;
                                r12 = 0;
                            }
                            r13 = 0x400 - r12;
                            r1 = LD32(196 + r11);
                            r1 = r1 - r7;
                            if (r13 > r1) {
                                r13 = r1;
                            }
                            r1 = LD32(r14 + 28);
                            r2 = v40 + r8;
                            r3 = r1;
                            if (r2 >= r1) {
                                r10 = r2;
                                r3 = 0;
                            } else {
                                r3 = r3 - r2;
                                r10 = r1;
                            }
                            r1 = LD32(r14 + 24);
                            r10 = r1 - r10;
                            r1 = r3;
                            if (r10 >= 0) {
                                r2 = LD32(200 + r11);
                                r1 = r1 + r10;
                                c16 = (r6 & r6) == 0;
                                if (r1 > r2) {
                                    r10 = r10 - (r1 - r2);
                                }
                                r0 = v36;
                                if (c16) {
                                    r9 = r7;
                                    if ((r0 & r0) == 0) {
                                        r1 = LD32(212 + r11);
                                        r9 = r9 + (r3 * r1);
                                    }
                                    r2 = LD32(r14 + 44);
                                    r8 = (((r8 + r3) + v40) * r2) + r12;
                                    if (r10 > 0) {
                                        r12 = r3 << 2;
                                        do {
                                            r0 = v36;
                                            if ((r0 & r0) == 0) {
                                                r1 = LD32(192 + r11);
                                                r5 = r1;
                                            } else {
                                                r1 = LD32(r0 + r12);
                                                r5 = r1;
                                            }
                                            r5 = r5 + r9;
                                            r1 = LD32(r14 + 40);
                                            r4 = r1 + r8;
                                            if (r13 > 0) {
                                                r0 = GCALL6(0x0604B358, r4, r5, r13, 0, v40, v36);
                                            }
                                            if ((v36 & v36) == 0) {
                                                r1 = LD32(212 + r11);
                                                r9 = r9 + r1;
                                            }
                                            r1 = LD32(r14 + 44);
                                            r12 = r12 + 4;
                                            r10 = r10 - 1;
                                            r8 = r8 + r1;
                                        } while (AGAIN(r10 > 0));
                                    }
                                } else {
                                    r9 = r7;
                                    if ((r0 & r0) == 0) {
                                        r1 = LD32(212 + r11);
                                        r9 = r9 + (r3 * r1);
                                    }
                                    r2 = LD32(r14 + 44);
                                    r8 = (((r8 + r3) + v40) * r2) + r12;
                                    if (r10 > 0) {
                                        r2 = r3 << 2;
                                        do {
                                            r0 = v36;
                                            if ((r0 & r0) == 0) {
                                                r1 = LD32(192 + r11);
                                                r5 = r1;
                                            } else {
                                                r1 = LD32(r0 + r2);
                                                r5 = r1;
                                            }
                                            r5 = r5 + r9;
                                            r1 = LD32(r14 + 40);
                                            r3 = 0;
                                            r4 = r1 + r8;
                                            if (!(0 >= r13)) {
                                                do {
                                                    r1 = LD8(r5);
                                                    r5 = r5 + 1;
                                                    r1 = r1 & 255;
                                                    if (!((r1 & r1) == 0)) {
                                                        ST8(r4 + r3, r1);
                                                    }
                                                    r3 = r3 + 1;
                                                } while (AGAIN(!(r3 >= r13)));
                                            }
                                            if ((v36 & v36) == 0) {
                                                r1 = LD32(212 + r11);
                                                r9 = r9 + r1;
                                            }
                                            r1 = LD32(r14 + 44);
                                            r2 = r2 + 4;
                                            r10 = r10 - 1;
                                            r8 = r8 + r1;
                                        } while (AGAIN(r10 > 0));
                                    }
                                }
                            }
                            r5 = R(5);
                            r6 = R(6);
                            r7 = R(7);
                            r0 = GCALL6(0x06025AB4, r11, 0, 0, 0, v40, v36);
                        }
                    }
                }
            }
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06016918(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, c0;
    long long m0;

    r10 = r4;
    r1 = LD32(0x06000344);
    r0 = GCALL2(r1, -1, 0x100);
    r0 = GCALL2(0x06069E6C, 71, 0x06016F50);
    r0 = GCALL0(0x0601742C);
    r1 = LD32(0x06000344);
    r0 = GCALL2(r1, -129, 0);
    r11 = 0x060279E0;
    c0 = r10 * 28;
    m0 = (unsigned)c0;
    r9 = c0;
    r0 = GCALL4(0x060279E0, 0, c0, -1, 1);
    ST32(0x06089CD0, r0);
    if ((r0 & r0) == 0) {
        r0 = 0;
    } else {
        r0 = GCALL4(r11, 0, ((int)((m0 & ~0xFFFFFFFFLL) | (unsigned)r9)), -1, 1);
        ST32(0x06089CCC, r0);
        if (!((r0 & r0) == 0)) {
            ST32(0x06089CC8, r10);
            r5 = 0;
            ST32(0x06089CC4, 0);
            if (!(0 >= r10)) {
                r4 = 0;
                r6 = 0;
                do {
                    r0 = r6;
                    r7 = LD32(0x06089CD0);
                    r3 = r6;
                    r2 = r6 + r7;
                    ST32(r0 + r7, r4);
                    ST32(r2 + 8, r4);
                    ST32(r2 + 12, r4);
                    ST32(r2 + 16, r4);
                    ST16((r2 + 24), r4);
                    r8 = LD32(0x06089CCC);
                    r6 = r6 + 28;
                    r1 = LD32(r0 + r7);
                    r5 = r5 + 1;
                    ST32(r0 + r8, r1);
                    r1 = LD32(r2 + 4);
                    r3 = r3 + r8;
                    ST32(r3 + 4, r1);
                    r2 = r2 + 8;
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
                    r3 = r3 + 4;
                    ST32(r3, r1);
                    r1 = LD32((r2 + 4));
                    ST32(r3 + 4, r1);
                } while (AGAIN(!(r5 >= r10)));
            }
            r0 = 1;
        } else {
            r0 = 0;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06016A78(void)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, c0, c1, c3, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c24, c44, c49, c59, c64, c1005, c1006, c1073, c1075, c1079;

    r1 = LD8(0x06089E03);
    r2 = r1 & 255;
    r0 = r2;
    c0 = r0 == 2;
    r11 = 0;
    c1005 = c0;
    if (c0) {
        r1 = 28;
        c1006 = c1005;
        r14 = 0;
        r12 = 0x06089CD0;
        r9 = r11 * r1;
        r1 = 112;
        while (1) {
            r7 = (r14 * r1) + 0x06089DD0;
            r1 = LD8((r7 + 51));
            r2 = r7;
            if (!((r1 & 255) == 255)) {
                r2 = r2 + 72;
                r1 = LD8(r2);
                r5 = 0;
                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                    r5 = 1;
                }
                r1 = LD8((r7 + 73));
                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                    r5 = r5 | 2;
                }
                r1 = LD8((r7 + 74));
                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                    r5 = r5 | 4;
                }
                r1 = LD8((r7 + 75));
                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                    r5 = r5 | 8;
                }
                r1 = LD8((r7 + 76));
                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                    r5 = r5 | 16;
                }
                r1 = LD8((r7 + 77));
                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                    r5 = r5 | 32;
                }
                r1 = LD8((r7 + 83));
                c13 = ((r1 & 255) & (r1 & 255)) == 0;
                r1 = r7;
                if (!(c13)) {
                    r5 = r5 | 64;
                    r1 = r2;
                } else {
                    r1 = LD8((r1 + 89));
                    c14 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r2;
                    if (!(c14)) {
                        r5 = r5 | 64;
                        r1 = r2;
                    }
                }
                r1 = LD8((r1 + 12));
                c15 = ((r1 & 255) & (r1 & 255)) == 0;
                r1 = r2;
                if (!(c15)) {
                    r5 = r5 | 0x100;
                    r1 = r2;
                } else {
                    r1 = LD8((r1 + 18));
                    c16 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r2;
                    if (!(c16)) {
                        r5 = r5 | 0x100;
                        r1 = r2;
                    }
                }
                r1 = LD8((r1 + 19));
                c17 = ((r1 & 255) & (r1 & 255)) == 0;
                r1 = r2;
                if (!(c17)) {
                    r5 = r5 | 128;
                }
                r1 = LD8((r1 + 6));
                c18 = ((r1 & 255) & (r1 & 255)) == 0;
                r1 = r2;
                if (!(c18)) {
                    r5 = r5 | 0x200;
                    r1 = r2;
                }
                r1 = LD8((r1 + 7));
                c19 = ((r1 & 255) & (r1 & 255)) == 0;
                r1 = r2;
                if (!(c19)) {
                    r5 = r5 | 0x1000;
                    r1 = r2;
                }
                r1 = LD8((r1 + 8));
                c20 = ((r1 & 255) & (r1 & 255)) == 0;
                r1 = r2;
                if (!(c20)) {
                    r5 = r5 | 0x2000;
                    r1 = r2;
                }
                r1 = LD8((r1 + 9));
                c21 = ((r1 & 255) & (r1 & 255)) == 0;
                r1 = r2;
                if (!(c21)) {
                    r5 = r5 | 0x400;
                    r1 = r2;
                }
                r1 = LD8((r1 + 10));
                c22 = ((r1 & 255) & (r1 & 255)) == 0;
                r1 = r7;
                if (!(c22)) {
                    r5 = r5 | 0x800;
                    r1 = r7;
                }
                r1 = LD8((r1 + 51));
                r2 = r1 & 255;
                r0 = r2;
                if (!(r0 == 2)) {
                    c24 = r0 == 21;
                    r0 = r2;
                    if (!(c24)) {
                        r6 = r9;
                        if (!(r0 == 22)) {
                            r0 = r2;
                            if (!(r2 == 227)) {
                                r3 = r9;
                                if (r0 == 52) {
                                    r0 = LD32(r12);
                                    ST32(r0 + r9, 5);
                                    r1 = LD8((r7 + 54));
                                    r3 = r3 + r0;
                                    r10 = r1 & 255;
                                    ST16((r3 + 20), r10);
                                    r1 = LD8((r7 + 55));
                                    r8 = r1 & 255;
                                    r13 = r8;
                                    if (((1 & r10) & (1 & r10)) == 0) {
                                        r1 = 32;
                                        if (!(((8 & r10) & (8 & r10)) == 0)) {
                                            r1 = LD8(((r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255) + 0x06075A74);
                                            r1 = r1 & 255;
                                            r0 = r1;
                                            c49 = r0 == 3;
                                            if (!(r0 == 1)) {
                                                r0 = r1;
                                                if (!(c49)) {
                                                    r1 = 32;
                                                    if (!(r0 == 2)) {
                                                        r0 = GCALL1(0x06032164, 9);
                                                        r1 = 32;
                                                    }
                                                } else {
                                                    r1 = r3 + 24;
                                                    r0 = LD16(r1);
                                                    ST16(r1, (r0 | 2));
                                                    r1 = 32;
                                                }
                                            } else {
                                                r1 = r3 + 24;
                                                r0 = LD16(r1);
                                                ST16(r1, (r0 | 1));
                                                r1 = 32;
                                            }
                                        }
                                    } else {
                                        r1 = LD8(((r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255) + 0x06075A74);
                                        r0 = r1 & 255;
                                        c44 = r0 == 3;
                                        if (!(r0 == 1)) {
                                            r1 = 32;
                                            if (c44) {
                                                r1 = r3 + 24;
                                                r2 = LD16(r1);
                                                r3 = -3;
                                                ST16(r1, (r2 & r3));
                                                r1 = 32;
                                            }
                                        } else {
                                            r1 = r3 + 24;
                                            r2 = LD16(r1);
                                            r3 = -2;
                                            ST16(r1, (r2 & r3));
                                            r1 = 32;
                                        }
                                    }
                                    if (((r1 & r10) & (r1 & r10)) == 0) {
                                        r0 = GCALL1(0x0602F7F4, r8);
                                        if (!((r0 & r0) == 0)) {
                                            r0 = GCALL1(0x0602F830, r8);
                                            r8 = r0 & 255;
                                        }
                                    }
                                    r1 = LD32(r12);
                                    r0 = LD16(((r1 + r9) + 24));
                                    r13 = r8;
                                    if (((r0 & 1) & (r0 & 1)) == 0) {
                                        r1 = 0x06075A74;
                                        r0 = (r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                    } else {
                                        r1 = 0x06075B74;
                                        r0 = (r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                    }
                                    r1 = LD8(r0 + r1);
                                    r0 = r10 & 64;
                                    r7 = r1 & 255;
                                    if ((r0 & r0) == 0) {
                                        r1 = LD32(r12);
                                        r3 = (r9 + r1) + 24;
                                        r1 = LD16(r3);
                                        ST16(r3, (r1 & -65));
                                        c1075 = 1;
                                    } else {
                                        r1 = LD8(r7 + 0x06075135);
                                        c59 = ((r1 & 2) & (r1 & 2)) == 0;
                                        r2 = r7;
                                        c1073 = c59;
                                        if (!(c59)) {
                                            r2 = r2 - 32;
                                            c1073 = 0;
                                        }
                                        r1 = LD32(r12);
                                        r1 = (r1 + r9) + 24;
                                        r0 = LD16(r1);
                                        r7 = r2 & 255;
                                        r0 = r0 | 64;
                                        ST16(r1, r0);
                                        c1075 = c1073;
                                    }
                                    r1 = LD32(r12);
                                    r5 = 0;
                                    ST16(((r9 + r1) + 22), ((r7 << 8) | r8));
                                } else {
                                    r1 = 7;
                                    if (!(r2 == 255)) {
                                        r0 = LD32(r12);
                                        c1079 = 0;
                                    } else {
                                        r0 = LD32(r12);
                                        r1 = 0;
                                        c1079 = 1;
                                    }
                                    ST32(r0 + r9, r1);
                                }
                            } else {
                                r0 = LD32(r12);
                                r2 = r9 + r0;
                                ST32(r0 + r9, 4);
                                r1 = LD8((r7 + 53));
                                ST16((r2 + 20), r1);
                                r1 = LD8((r7 + 54));
                                ST16((r2 + 22), r1);
                            }
                        } else {
                            r0 = LD32(r12);
                            ST32(r0 + r9, 6);
                            r2 = LD8((r7 + 54));
                            r6 = r6 + r0;
                            r7 = LD8((r7 + 55));
                            ST16((r6 + 20), (((((int)(((long long)((r2 & 255) - 128) * 0x2AAAAAAB) >> 32)) >> 1) >> 1) - (((((r2 & 255) - 128) << 1) - (((r2 & 255) - 128) << 1)) - ((unsigned)((r2 & 255) - 128) >> 31))));
                            ST16((r6 + 22), ((((((r7 & 255) - 128) << 1) - (((r7 & 255) - 128) << 1)) - ((unsigned)((r7 & 255) - 128) >> 31)) - ((((int)(((long long)((r7 & 255) - 128) * 0x2AAAAAAB) >> 32)) >> 1) >> 1)));
                        }
                    } else {
                        r0 = LD32(r12);
                        r1 = 3;
                        c1079 = 1;
                        ST32(r0 + r9, r1);
                    }
                } else {
                    r1 = LD32(r12);
                    r0 = r9;
                    ST32(r0 + r1, 1);
                }
                r1 = LD32(r12);
                r3 = r9 + r1;
                r1 = LD32(r3 + 16);
                ST32(r3 + 8, r5);
                r2 = (r5 ^ r1) & r5;
                r1 = LD32(r3 + 12);
                ST32(r3 + 16, r5);
                ST32(r3 + 12, (r1 | r2));
                r1 = LD32(0x06089CC8);
                r11 = r11 + 1;
                r9 = r9 + 28;
                if (r11 >= r1) {
                    break;
                } else {
                    r14 = r14 + 1;
                    r1 = 112;
                    if (r14 > 29) {
                        break;
                    } else {
                        POLL();
                        continue;
                    }
                }
            } else {
                r14 = r14 + 1;
                r1 = 112;
                if (r14 > 29) {
                    break;
                }
            }
            POLL();
        }
    } else {
        r3 = 1;
        c1 = (unsigned)(r2 - 21) > (unsigned)1;
        r1 = 28;
        c1006 = c1;
        if (!(c1)) {
            r14 = 0;
            r12 = 0x06089CD0;
            r9 = r11 * r1;
            r1 = 112;
            while (1) {
                r7 = (r14 * r1) + 0x06089DD0;
                r1 = LD8((r7 + 51));
                r2 = r7;
                if (!((r1 & 255) == 255)) {
                    r2 = r2 + 72;
                    r1 = LD8(r2);
                    r5 = 0;
                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                        r5 = 1;
                    }
                    r1 = LD8((r7 + 73));
                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                        r5 = r5 | 2;
                    }
                    r1 = LD8((r7 + 74));
                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                        r5 = r5 | 4;
                    }
                    r1 = LD8((r7 + 75));
                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                        r5 = r5 | 8;
                    }
                    r1 = LD8((r7 + 76));
                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                        r5 = r5 | 16;
                    }
                    r1 = LD8((r7 + 77));
                    if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                        r5 = r5 | 32;
                    }
                    r1 = LD8((r7 + 83));
                    c13 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r7;
                    if (!(c13)) {
                        r5 = r5 | 64;
                        r1 = r2;
                    } else {
                        r1 = LD8((r1 + 89));
                        c14 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c14)) {
                            r5 = r5 | 64;
                            r1 = r2;
                        }
                    }
                    r1 = LD8((r1 + 12));
                    c15 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r2;
                    if (!(c15)) {
                        r5 = r5 | 0x100;
                        r1 = r2;
                    } else {
                        r1 = LD8((r1 + 18));
                        c16 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c16)) {
                            r5 = r5 | 0x100;
                            r1 = r2;
                        }
                    }
                    r1 = LD8((r1 + 19));
                    c17 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r2;
                    if (!(c17)) {
                        r5 = r5 | 128;
                    }
                    r1 = LD8((r1 + 6));
                    c18 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r2;
                    if (!(c18)) {
                        r5 = r5 | 0x200;
                        r1 = r2;
                    }
                    r1 = LD8((r1 + 7));
                    c19 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r2;
                    if (!(c19)) {
                        r5 = r5 | 0x1000;
                        r1 = r2;
                    }
                    r1 = LD8((r1 + 8));
                    c20 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r2;
                    if (!(c20)) {
                        r5 = r5 | 0x2000;
                        r1 = r2;
                    }
                    r1 = LD8((r1 + 9));
                    c21 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r2;
                    if (!(c21)) {
                        r5 = r5 | 0x400;
                        r1 = r2;
                    }
                    r1 = LD8((r1 + 10));
                    c22 = ((r1 & 255) & (r1 & 255)) == 0;
                    r1 = r7;
                    if (!(c22)) {
                        r5 = r5 | 0x800;
                        r1 = r7;
                    }
                    r1 = LD8((r1 + 51));
                    r2 = r1 & 255;
                    r0 = r2;
                    if (!(r0 == 2)) {
                        c24 = r0 == 21;
                        r0 = r2;
                        if (!(c24)) {
                            r6 = r9;
                            if (!(r0 == 22)) {
                                r0 = r2;
                                if (!(r2 == 227)) {
                                    r3 = r9;
                                    if (r0 == 52) {
                                        r0 = LD32(r12);
                                        ST32(r0 + r9, 5);
                                        r1 = LD8((r7 + 54));
                                        r3 = r3 + r0;
                                        r10 = r1 & 255;
                                        ST16((r3 + 20), r10);
                                        r1 = LD8((r7 + 55));
                                        r8 = r1 & 255;
                                        r13 = r8;
                                        if (((1 & r10) & (1 & r10)) == 0) {
                                            r1 = 32;
                                            if (!(((8 & r10) & (8 & r10)) == 0)) {
                                                r1 = LD8(((r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255) + 0x06075A74);
                                                r1 = r1 & 255;
                                                r0 = r1;
                                                c49 = r0 == 3;
                                                if (!(r0 == 1)) {
                                                    r0 = r1;
                                                    if (!(c49)) {
                                                        r1 = 32;
                                                        if (!(r0 == 2)) {
                                                            r0 = GCALL1(0x06032164, 9);
                                                            r1 = 32;
                                                        }
                                                    } else {
                                                        r1 = r3 + 24;
                                                        r0 = LD16(r1);
                                                        ST16(r1, (r0 | 2));
                                                        r1 = 32;
                                                    }
                                                } else {
                                                    r1 = r3 + 24;
                                                    r0 = LD16(r1);
                                                    ST16(r1, (r0 | 1));
                                                    r1 = 32;
                                                }
                                            }
                                        } else {
                                            r1 = LD8(((r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255) + 0x06075A74);
                                            r0 = r1 & 255;
                                            c44 = r0 == 3;
                                            if (!(r0 == 1)) {
                                                r1 = 32;
                                                if (c44) {
                                                    r1 = r3 + 24;
                                                    r2 = LD16(r1);
                                                    r3 = -3;
                                                    ST16(r1, (r2 & r3));
                                                    r1 = 32;
                                                }
                                            } else {
                                                r1 = r3 + 24;
                                                r2 = LD16(r1);
                                                r3 = -2;
                                                ST16(r1, (r2 & r3));
                                                r1 = 32;
                                            }
                                        }
                                        if (((r1 & r10) & (r1 & r10)) == 0) {
                                            r0 = GCALL1(0x0602F7F4, r8);
                                            if (!((r0 & r0) == 0)) {
                                                r0 = GCALL1(0x0602F830, r8);
                                                r8 = r0 & 255;
                                            }
                                        }
                                        r1 = LD32(r12);
                                        r0 = LD16(((r1 + r9) + 24));
                                        r13 = r8;
                                        if (((r0 & 1) & (r0 & 1)) == 0) {
                                            r1 = 0x06075A74;
                                            r0 = (r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                        } else {
                                            r1 = 0x06075B74;
                                            r0 = (r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                        }
                                        r1 = LD8(r0 + r1);
                                        r0 = r10 & 64;
                                        r7 = r1 & 255;
                                        if ((r0 & r0) == 0) {
                                            r1 = LD32(r12);
                                            r3 = (r9 + r1) + 24;
                                            r1 = LD16(r3);
                                            ST16(r3, (r1 & -65));
                                            c1075 = 1;
                                        } else {
                                            r1 = LD8(r7 + 0x06075135);
                                            c59 = ((r1 & 2) & (r1 & 2)) == 0;
                                            r2 = r7;
                                            c1073 = c59;
                                            if (!(c59)) {
                                                r2 = r2 - 32;
                                                c1073 = 0;
                                            }
                                            r1 = LD32(r12);
                                            r1 = (r1 + r9) + 24;
                                            r0 = LD16(r1);
                                            r7 = r2 & 255;
                                            r0 = r0 | 64;
                                            ST16(r1, r0);
                                            c1075 = c1073;
                                        }
                                        r1 = LD32(r12);
                                        r5 = 0;
                                        ST16(((r9 + r1) + 22), ((r7 << 8) | r8));
                                    } else {
                                        r1 = 7;
                                        if (!(r2 == 255)) {
                                            r0 = LD32(r12);
                                            c1079 = 0;
                                        } else {
                                            r0 = LD32(r12);
                                            r1 = 0;
                                            c1079 = 1;
                                        }
                                        ST32(r0 + r9, r1);
                                    }
                                } else {
                                    r0 = LD32(r12);
                                    r2 = r9 + r0;
                                    ST32(r0 + r9, 4);
                                    r1 = LD8((r7 + 53));
                                    ST16((r2 + 20), r1);
                                    r1 = LD8((r7 + 54));
                                    ST16((r2 + 22), r1);
                                }
                            } else {
                                r0 = LD32(r12);
                                ST32(r0 + r9, 6);
                                r2 = LD8((r7 + 54));
                                r6 = r6 + r0;
                                r7 = LD8((r7 + 55));
                                ST16((r6 + 20), (((((int)(((long long)((r2 & 255) - 128) * 0x2AAAAAAB) >> 32)) >> 1) >> 1) - (((((r2 & 255) - 128) << 1) - (((r2 & 255) - 128) << 1)) - ((unsigned)((r2 & 255) - 128) >> 31))));
                                ST16((r6 + 22), ((((((r7 & 255) - 128) << 1) - (((r7 & 255) - 128) << 1)) - ((unsigned)((r7 & 255) - 128) >> 31)) - ((((int)(((long long)((r7 & 255) - 128) * 0x2AAAAAAB) >> 32)) >> 1) >> 1)));
                            }
                        } else {
                            r0 = LD32(r12);
                            r1 = 3;
                            c1079 = 1;
                            ST32(r0 + r9, r1);
                        }
                    } else {
                        r1 = LD32(r12);
                        r0 = r9;
                        ST32(r0 + r1, 1);
                    }
                    r1 = LD32(r12);
                    r3 = r9 + r1;
                    r1 = LD32(r3 + 16);
                    ST32(r3 + 8, r5);
                    r2 = (r5 ^ r1) & r5;
                    r1 = LD32(r3 + 12);
                    ST32(r3 + 16, r5);
                    ST32(r3 + 12, (r1 | r2));
                    r1 = LD32(0x06089CC8);
                    r11 = r11 + 1;
                    r9 = r9 + 28;
                    if (r11 >= r1) {
                        break;
                    } else {
                        r14 = r14 + 1;
                        r1 = 112;
                        if (r14 > 29) {
                            break;
                        } else {
                            POLL();
                            continue;
                        }
                    }
                } else {
                    r14 = r14 + 1;
                    r1 = 112;
                    if (r14 > 29) {
                        break;
                    }
                }
                POLL();
            }
        } else {
            c3 = r0 == 52;
            c1005 = c3;
            if (r2 == 227) {
                r1 = 28;
                c1006 = c1005;
                r14 = 0;
                r12 = 0x06089CD0;
                r9 = r11 * r1;
                r1 = 112;
                while (1) {
                    r7 = (r14 * r1) + 0x06089DD0;
                    r1 = LD8((r7 + 51));
                    r2 = r7;
                    if (!((r1 & 255) == 255)) {
                        r2 = r2 + 72;
                        r1 = LD8(r2);
                        r5 = 0;
                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                            r5 = 1;
                        }
                        r1 = LD8((r7 + 73));
                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                            r5 = r5 | 2;
                        }
                        r1 = LD8((r7 + 74));
                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                            r5 = r5 | 4;
                        }
                        r1 = LD8((r7 + 75));
                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                            r5 = r5 | 8;
                        }
                        r1 = LD8((r7 + 76));
                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                            r5 = r5 | 16;
                        }
                        r1 = LD8((r7 + 77));
                        if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                            r5 = r5 | 32;
                        }
                        r1 = LD8((r7 + 83));
                        c13 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r7;
                        if (!(c13)) {
                            r5 = r5 | 64;
                            r1 = r2;
                        } else {
                            r1 = LD8((r1 + 89));
                            c14 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r2;
                            if (!(c14)) {
                                r5 = r5 | 64;
                                r1 = r2;
                            }
                        }
                        r1 = LD8((r1 + 12));
                        c15 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c15)) {
                            r5 = r5 | 0x100;
                            r1 = r2;
                        } else {
                            r1 = LD8((r1 + 18));
                            c16 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r2;
                            if (!(c16)) {
                                r5 = r5 | 0x100;
                                r1 = r2;
                            }
                        }
                        r1 = LD8((r1 + 19));
                        c17 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c17)) {
                            r5 = r5 | 128;
                        }
                        r1 = LD8((r1 + 6));
                        c18 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c18)) {
                            r5 = r5 | 0x200;
                            r1 = r2;
                        }
                        r1 = LD8((r1 + 7));
                        c19 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c19)) {
                            r5 = r5 | 0x1000;
                            r1 = r2;
                        }
                        r1 = LD8((r1 + 8));
                        c20 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c20)) {
                            r5 = r5 | 0x2000;
                            r1 = r2;
                        }
                        r1 = LD8((r1 + 9));
                        c21 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r2;
                        if (!(c21)) {
                            r5 = r5 | 0x400;
                            r1 = r2;
                        }
                        r1 = LD8((r1 + 10));
                        c22 = ((r1 & 255) & (r1 & 255)) == 0;
                        r1 = r7;
                        if (!(c22)) {
                            r5 = r5 | 0x800;
                            r1 = r7;
                        }
                        r1 = LD8((r1 + 51));
                        r2 = r1 & 255;
                        r0 = r2;
                        if (!(r0 == 2)) {
                            c24 = r0 == 21;
                            r0 = r2;
                            if (!(c24)) {
                                r6 = r9;
                                if (!(r0 == 22)) {
                                    r0 = r2;
                                    if (!(r2 == 227)) {
                                        r3 = r9;
                                        if (r0 == 52) {
                                            r0 = LD32(r12);
                                            ST32(r0 + r9, 5);
                                            r1 = LD8((r7 + 54));
                                            r3 = r3 + r0;
                                            r10 = r1 & 255;
                                            ST16((r3 + 20), r10);
                                            r1 = LD8((r7 + 55));
                                            r8 = r1 & 255;
                                            r13 = r8;
                                            if (((1 & r10) & (1 & r10)) == 0) {
                                                r1 = 32;
                                                if (!(((8 & r10) & (8 & r10)) == 0)) {
                                                    r1 = LD8(((r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255) + 0x06075A74);
                                                    r1 = r1 & 255;
                                                    r0 = r1;
                                                    c49 = r0 == 3;
                                                    if (!(r0 == 1)) {
                                                        r0 = r1;
                                                        if (!(c49)) {
                                                            r1 = 32;
                                                            if (!(r0 == 2)) {
                                                                r0 = GCALL1(0x06032164, 9);
                                                                r1 = 32;
                                                            }
                                                        } else {
                                                            r1 = r3 + 24;
                                                            r0 = LD16(r1);
                                                            ST16(r1, (r0 | 2));
                                                            r1 = 32;
                                                        }
                                                    } else {
                                                        r1 = r3 + 24;
                                                        r0 = LD16(r1);
                                                        ST16(r1, (r0 | 1));
                                                        r1 = 32;
                                                    }
                                                }
                                            } else {
                                                r1 = LD8(((r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255) + 0x06075A74);
                                                r0 = r1 & 255;
                                                c44 = r0 == 3;
                                                if (!(r0 == 1)) {
                                                    r1 = 32;
                                                    if (c44) {
                                                        r1 = r3 + 24;
                                                        r2 = LD16(r1);
                                                        r3 = -3;
                                                        ST16(r1, (r2 & r3));
                                                        r1 = 32;
                                                    }
                                                } else {
                                                    r1 = r3 + 24;
                                                    r2 = LD16(r1);
                                                    r3 = -2;
                                                    ST16(r1, (r2 & r3));
                                                    r1 = 32;
                                                }
                                            }
                                            if (((r1 & r10) & (r1 & r10)) == 0) {
                                                r0 = GCALL1(0x0602F7F4, r8);
                                                if (!((r0 & r0) == 0)) {
                                                    r0 = GCALL1(0x0602F830, r8);
                                                    r8 = r0 & 255;
                                                }
                                            }
                                            r1 = LD32(r12);
                                            r0 = LD16(((r1 + r9) + 24));
                                            r13 = r8;
                                            if (((r0 & 1) & (r0 & 1)) == 0) {
                                                r1 = 0x06075A74;
                                                r0 = (r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                            } else {
                                                r1 = 0x06075B74;
                                                r0 = (r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                            }
                                            r1 = LD8(r0 + r1);
                                            r0 = r10 & 64;
                                            r7 = r1 & 255;
                                            if ((r0 & r0) == 0) {
                                                r1 = LD32(r12);
                                                r3 = (r9 + r1) + 24;
                                                r1 = LD16(r3);
                                                ST16(r3, (r1 & -65));
                                                c1075 = 1;
                                            } else {
                                                r1 = LD8(r7 + 0x06075135);
                                                c59 = ((r1 & 2) & (r1 & 2)) == 0;
                                                r2 = r7;
                                                c1073 = c59;
                                                if (!(c59)) {
                                                    r2 = r2 - 32;
                                                    c1073 = 0;
                                                }
                                                r1 = LD32(r12);
                                                r1 = (r1 + r9) + 24;
                                                r0 = LD16(r1);
                                                r7 = r2 & 255;
                                                r0 = r0 | 64;
                                                ST16(r1, r0);
                                                c1075 = c1073;
                                            }
                                            r1 = LD32(r12);
                                            r5 = 0;
                                            ST16(((r9 + r1) + 22), ((r7 << 8) | r8));
                                        } else {
                                            r1 = 7;
                                            if (!(r2 == 255)) {
                                                r0 = LD32(r12);
                                                c1079 = 0;
                                            } else {
                                                r0 = LD32(r12);
                                                r1 = 0;
                                                c1079 = 1;
                                            }
                                            ST32(r0 + r9, r1);
                                        }
                                    } else {
                                        r0 = LD32(r12);
                                        r2 = r9 + r0;
                                        ST32(r0 + r9, 4);
                                        r1 = LD8((r7 + 53));
                                        ST16((r2 + 20), r1);
                                        r1 = LD8((r7 + 54));
                                        ST16((r2 + 22), r1);
                                    }
                                } else {
                                    r0 = LD32(r12);
                                    ST32(r0 + r9, 6);
                                    r2 = LD8((r7 + 54));
                                    r6 = r6 + r0;
                                    r7 = LD8((r7 + 55));
                                    ST16((r6 + 20), (((((int)(((long long)((r2 & 255) - 128) * 0x2AAAAAAB) >> 32)) >> 1) >> 1) - (((((r2 & 255) - 128) << 1) - (((r2 & 255) - 128) << 1)) - ((unsigned)((r2 & 255) - 128) >> 31))));
                                    ST16((r6 + 22), ((((((r7 & 255) - 128) << 1) - (((r7 & 255) - 128) << 1)) - ((unsigned)((r7 & 255) - 128) >> 31)) - ((((int)(((long long)((r7 & 255) - 128) * 0x2AAAAAAB) >> 32)) >> 1) >> 1)));
                                }
                            } else {
                                r0 = LD32(r12);
                                r1 = 3;
                                c1079 = 1;
                                ST32(r0 + r9, r1);
                            }
                        } else {
                            r1 = LD32(r12);
                            r0 = r9;
                            ST32(r0 + r1, 1);
                        }
                        r1 = LD32(r12);
                        r3 = r9 + r1;
                        r1 = LD32(r3 + 16);
                        ST32(r3 + 8, r5);
                        r2 = (r5 ^ r1) & r5;
                        r1 = LD32(r3 + 12);
                        ST32(r3 + 16, r5);
                        ST32(r3 + 12, (r1 | r2));
                        r1 = LD32(0x06089CC8);
                        r11 = r11 + 1;
                        r9 = r9 + 28;
                        if (r11 >= r1) {
                            break;
                        } else {
                            r14 = r14 + 1;
                            r1 = 112;
                            if (r14 > 29) {
                                break;
                            } else {
                                POLL();
                                continue;
                            }
                        }
                    } else {
                        r14 = r14 + 1;
                        r1 = 112;
                        if (r14 > 29) {
                            break;
                        }
                    }
                    POLL();
                }
            } else {
                c1005 = c3;
                if (c3) {
                    r1 = 28;
                    c1006 = c1005;
                    r14 = 0;
                    r12 = 0x06089CD0;
                    r9 = r11 * r1;
                    r1 = 112;
                    while (1) {
                        r7 = (r14 * r1) + 0x06089DD0;
                        r1 = LD8((r7 + 51));
                        r2 = r7;
                        if (!((r1 & 255) == 255)) {
                            r2 = r2 + 72;
                            r1 = LD8(r2);
                            r5 = 0;
                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                r5 = 1;
                            }
                            r1 = LD8((r7 + 73));
                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                r5 = r5 | 2;
                            }
                            r1 = LD8((r7 + 74));
                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                r5 = r5 | 4;
                            }
                            r1 = LD8((r7 + 75));
                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                r5 = r5 | 8;
                            }
                            r1 = LD8((r7 + 76));
                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                r5 = r5 | 16;
                            }
                            r1 = LD8((r7 + 77));
                            if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                r5 = r5 | 32;
                            }
                            r1 = LD8((r7 + 83));
                            c13 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r7;
                            if (!(c13)) {
                                r5 = r5 | 64;
                                r1 = r2;
                            } else {
                                r1 = LD8((r1 + 89));
                                c14 = ((r1 & 255) & (r1 & 255)) == 0;
                                r1 = r2;
                                if (!(c14)) {
                                    r5 = r5 | 64;
                                    r1 = r2;
                                }
                            }
                            r1 = LD8((r1 + 12));
                            c15 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r2;
                            if (!(c15)) {
                                r5 = r5 | 0x100;
                                r1 = r2;
                            } else {
                                r1 = LD8((r1 + 18));
                                c16 = ((r1 & 255) & (r1 & 255)) == 0;
                                r1 = r2;
                                if (!(c16)) {
                                    r5 = r5 | 0x100;
                                    r1 = r2;
                                }
                            }
                            r1 = LD8((r1 + 19));
                            c17 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r2;
                            if (!(c17)) {
                                r5 = r5 | 128;
                            }
                            r1 = LD8((r1 + 6));
                            c18 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r2;
                            if (!(c18)) {
                                r5 = r5 | 0x200;
                                r1 = r2;
                            }
                            r1 = LD8((r1 + 7));
                            c19 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r2;
                            if (!(c19)) {
                                r5 = r5 | 0x1000;
                                r1 = r2;
                            }
                            r1 = LD8((r1 + 8));
                            c20 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r2;
                            if (!(c20)) {
                                r5 = r5 | 0x2000;
                                r1 = r2;
                            }
                            r1 = LD8((r1 + 9));
                            c21 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r2;
                            if (!(c21)) {
                                r5 = r5 | 0x400;
                                r1 = r2;
                            }
                            r1 = LD8((r1 + 10));
                            c22 = ((r1 & 255) & (r1 & 255)) == 0;
                            r1 = r7;
                            if (!(c22)) {
                                r5 = r5 | 0x800;
                                r1 = r7;
                            }
                            r1 = LD8((r1 + 51));
                            r2 = r1 & 255;
                            r0 = r2;
                            if (!(r0 == 2)) {
                                c24 = r0 == 21;
                                r0 = r2;
                                if (!(c24)) {
                                    r6 = r9;
                                    if (!(r0 == 22)) {
                                        r0 = r2;
                                        if (!(r2 == 227)) {
                                            r3 = r9;
                                            if (r0 == 52) {
                                                r0 = LD32(r12);
                                                ST32(r0 + r9, 5);
                                                r1 = LD8((r7 + 54));
                                                r3 = r3 + r0;
                                                r10 = r1 & 255;
                                                ST16((r3 + 20), r10);
                                                r1 = LD8((r7 + 55));
                                                r8 = r1 & 255;
                                                r13 = r8;
                                                if (((1 & r10) & (1 & r10)) == 0) {
                                                    r1 = 32;
                                                    if (!(((8 & r10) & (8 & r10)) == 0)) {
                                                        r1 = LD8(((r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255) + 0x06075A74);
                                                        r1 = r1 & 255;
                                                        r0 = r1;
                                                        c49 = r0 == 3;
                                                        if (!(r0 == 1)) {
                                                            r0 = r1;
                                                            if (!(c49)) {
                                                                r1 = 32;
                                                                if (!(r0 == 2)) {
                                                                    r0 = GCALL1(0x06032164, 9);
                                                                    r1 = 32;
                                                                }
                                                            } else {
                                                                r1 = r3 + 24;
                                                                r0 = LD16(r1);
                                                                ST16(r1, (r0 | 2));
                                                                r1 = 32;
                                                            }
                                                        } else {
                                                            r1 = r3 + 24;
                                                            r0 = LD16(r1);
                                                            ST16(r1, (r0 | 1));
                                                            r1 = 32;
                                                        }
                                                    }
                                                } else {
                                                    r1 = LD8(((r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255) + 0x06075A74);
                                                    r0 = r1 & 255;
                                                    c44 = r0 == 3;
                                                    if (!(r0 == 1)) {
                                                        r1 = 32;
                                                        if (c44) {
                                                            r1 = r3 + 24;
                                                            r2 = LD16(r1);
                                                            r3 = -3;
                                                            ST16(r1, (r2 & r3));
                                                            r1 = 32;
                                                        }
                                                    } else {
                                                        r1 = r3 + 24;
                                                        r2 = LD16(r1);
                                                        r3 = -2;
                                                        ST16(r1, (r2 & r3));
                                                        r1 = 32;
                                                    }
                                                }
                                                if (((r1 & r10) & (r1 & r10)) == 0) {
                                                    r0 = GCALL1(0x0602F7F4, r8);
                                                    if (!((r0 & r0) == 0)) {
                                                        r0 = GCALL1(0x0602F830, r8);
                                                        r8 = r0 & 255;
                                                    }
                                                }
                                                r1 = LD32(r12);
                                                r0 = LD16(((r1 + r9) + 24));
                                                r13 = r8;
                                                if (((r0 & 1) & (r0 & 1)) == 0) {
                                                    r1 = 0x06075A74;
                                                    r0 = (r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                                } else {
                                                    r1 = 0x06075B74;
                                                    r0 = (r13 - ((int)((((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) & ~0xFFFFFFFFLL) | (unsigned)(((int)((unsigned)((int)((unsigned)((int)((unsigned)((int)(((long long)((unsigned long long)(unsigned)r8 * (unsigned)0x38E38E39)) >> 32)) >> 2)) >> 1)) >> 2)) * 144)))) & 255;
                                                }
                                                r1 = LD8(r0 + r1);
                                                r0 = r10 & 64;
                                                r7 = r1 & 255;
                                                if ((r0 & r0) == 0) {
                                                    r1 = LD32(r12);
                                                    r3 = (r9 + r1) + 24;
                                                    r1 = LD16(r3);
                                                    ST16(r3, (r1 & -65));
                                                    c1075 = 1;
                                                } else {
                                                    r1 = LD8(r7 + 0x06075135);
                                                    c59 = ((r1 & 2) & (r1 & 2)) == 0;
                                                    r2 = r7;
                                                    c1073 = c59;
                                                    if (!(c59)) {
                                                        r2 = r2 - 32;
                                                        c1073 = 0;
                                                    }
                                                    r1 = LD32(r12);
                                                    r1 = (r1 + r9) + 24;
                                                    r0 = LD16(r1);
                                                    r7 = r2 & 255;
                                                    r0 = r0 | 64;
                                                    ST16(r1, r0);
                                                    c1075 = c1073;
                                                }
                                                r1 = LD32(r12);
                                                r5 = 0;
                                                ST16(((r9 + r1) + 22), ((r7 << 8) | r8));
                                            } else {
                                                r1 = 7;
                                                if (!(r2 == 255)) {
                                                    r0 = LD32(r12);
                                                    c1079 = 0;
                                                } else {
                                                    r0 = LD32(r12);
                                                    r1 = 0;
                                                    c1079 = 1;
                                                }
                                                ST32(r0 + r9, r1);
                                            }
                                        } else {
                                            r0 = LD32(r12);
                                            r2 = r9 + r0;
                                            ST32(r0 + r9, 4);
                                            r1 = LD8((r7 + 53));
                                            ST16((r2 + 20), r1);
                                            r1 = LD8((r7 + 54));
                                            ST16((r2 + 22), r1);
                                        }
                                    } else {
                                        r0 = LD32(r12);
                                        ST32(r0 + r9, 6);
                                        r2 = LD8((r7 + 54));
                                        r6 = r6 + r0;
                                        r7 = LD8((r7 + 55));
                                        ST16((r6 + 20), (((((int)(((long long)((r2 & 255) - 128) * 0x2AAAAAAB) >> 32)) >> 1) >> 1) - (((((r2 & 255) - 128) << 1) - (((r2 & 255) - 128) << 1)) - ((unsigned)((r2 & 255) - 128) >> 31))));
                                        ST16((r6 + 22), ((((((r7 & 255) - 128) << 1) - (((r7 & 255) - 128) << 1)) - ((unsigned)((r7 & 255) - 128) >> 31)) - ((((int)(((long long)((r7 & 255) - 128) * 0x2AAAAAAB) >> 32)) >> 1) >> 1)));
                                    }
                                } else {
                                    r0 = LD32(r12);
                                    r1 = 3;
                                    c1079 = 1;
                                    ST32(r0 + r9, r1);
                                }
                            } else {
                                r1 = LD32(r12);
                                r0 = r9;
                                ST32(r0 + r1, 1);
                            }
                            r1 = LD32(r12);
                            r3 = r9 + r1;
                            r1 = LD32(r3 + 16);
                            ST32(r3 + 8, r5);
                            r2 = (r5 ^ r1) & r5;
                            r1 = LD32(r3 + 12);
                            ST32(r3 + 16, r5);
                            ST32(r3 + 12, (r1 | r2));
                            r1 = LD32(0x06089CC8);
                            r11 = r11 + 1;
                            r9 = r9 + 28;
                            if (r11 >= r1) {
                                break;
                            } else {
                                r14 = r14 + 1;
                                r1 = 112;
                                if (r14 > 29) {
                                    break;
                                } else {
                                    POLL();
                                    continue;
                                }
                            }
                        } else {
                            r14 = r14 + 1;
                            r1 = 112;
                            if (r14 > 29) {
                                break;
                            }
                        }
                        POLL();
                    }
                } else {
                    if (!(r2 == 255)) {
                        r11 = r3;
                        r2 = LD32(0x06089CD0);
                        ST32(r2, 7);
                    }
                }
            }
        }
    }
    ST32(0x06089CC4, r11);
    r7 = 0x06089CC8;
    r1 = LD32(0x06089CC8);
    c64 = r11 >= r1;
    r1 = 28;
    if (!(c64)) {
        r6 = 0x06089CD0;
        r3 = 0;
        r5 = r11 * r1;
        do {
            r0 = r5;
            r2 = LD32(r6);
            r1 = r5 + r2;
            ST32(r0 + r2, r3);
            ST32(r1 + 8, r3);
            ST32(r1 + 12, r3);
            ST32(r1 + 16, r3);
            r1 = LD32(r7);
            r11 = r11 + 1;
            r5 = r5 + 28;
        } while (AGAIN(!(r11 >= r1)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060170B4(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r7, r8, r9, r10, r11, c0, c4, c6;
    long long m0;

    r10 = r4 & 255;
    r11 = r5 & 255;
    r8 = 0x06089D70;
    c0 = r10 * 42;
    m0 = (unsigned)c0;
    r3 = c0 + 0x06089D70;
    r1 = LD8(0x06089CE0);
    r2 = LD8(r3);
    r1 = LD8((r1 & 255) + 0x06089CF0);
    ST8((r3 + 41), (((r2 & 255) == (r1 & 255)) ^ 1));
    r1 = LD8(0x06089CE0);
    r1 = LD8((r1 & 255) + 0x06089CF0);
    ST8(c0 + 0x06089D70, r1);
    r1 = LD8(r3);
    r2 = r1 & 255;
    r0 = r2;
    r9 = 0;
    if (r0 == 22) {
        r9 = 6;
        r5 = 0x0601706C;
        r4 = ((int)m0) + (r8 + 1);
        r0 = GCALL3(0x0604B358, r4, r5, 21);
        r2 = 14;
    } else {
        c4 = r0 == 4;
        if (r2 > 22) {
            r4 = (int)m0;
            if (r2 == 240) {
                r5 = 0x0601703C;
                r4 = r4 + (r8 + 1);
                r0 = GCALL3(0x0604B358, r4, r5, 21);
                r2 = 14;
            } else {
                c6 = r2 == 241;
                r9 = c6;
                if (c6) {
                    r5 = 0x06017054;
                    r4 = r4 + (r8 + 1);
                    r0 = GCALL3(0x0604B358, r4, r5, 21);
                    r2 = 14;
                } else {
                    r1 = 42;
                    r0 = GCALL3(0x0604B358, ((r10 * r1) + 0x06089D71), 0x0601709C, 21);
                    r9 = 0;
                    r2 = 14;
                }
            }
        } else {
            r9 = 4;
            if (c4) {
                r4 = ((int)m0) + (r8 + 1);
                r5 = 0x06017084;
                r0 = GCALL3(0x0604B358, r4, r5, 21);
                r2 = 14;
            } else {
                r1 = 42;
                r0 = GCALL3(0x0604B358, ((r10 * r1) + 0x06089D71), 0x0601709C, 21);
                r9 = 0;
                r2 = 14;
            }
        }
    }
    r8 = r9;
    if (!((unsigned)r9 > (unsigned)r2)) {
        r5 = 0x06089DD0;
        r6 = 15;
        r7 = 112;
        r3 = -1;
        m0 = (unsigned)(r10 * 15);
        do {
            ST8(((((((int)m0) + r8) * r7) + r5) + 51), r3);
            r8 = (r8 + 1) & 255;
            m0 = (unsigned)(r10 * r6);
        } while (AGAIN(!((unsigned)r8 > (unsigned)r2)));
    }
    r8 = 0;
    r1 = r9;
    if (!((unsigned)0 >= (unsigned)r9)) {
        r10 = 0x06017204;
        do {
            r0 = GCALL1(r10, r11);
            r8 = (r8 + 1) & 255;
            r11 = r0;
        } while (AGAIN(!((unsigned)r8 >= (unsigned)r9)));
        r1 = r9;
    }
    return (r11 - (r1 - 15)) & 255;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06017204(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, c3;
    long long m0;

    r4 = r4 & 255;
    r9 = 0x06089CE0;
    r11 = 0x06089DD0;
    r10 = 112;
    r8 = 0x06089CF0;
    r2 = LD8(0x06089CE0);
    r2 = r2 + 1;
    ST8(0x06089CE0, r2);
    r0 = r2 & 255;
    r6 = (r4 * 112) + 0x06089DD0;
    r5 = r6 + 51;
    r2 = LD8(r5);
    r1 = LD8(r0 + 0x06089CF0);
    ST8((r6 + 71), (((r2 & 255) == (r1 & 255)) ^ 1));
    r1 = LD8(0x06089CE0);
    r1 = LD8((r1 & 255) + 0x06089CF0);
    ST8(r5, r1);
    r7 = 0;
    if (!((unsigned)(r1 & 255) > (unsigned)239)) {
        ST8((r6 + 50), 0);
        r0 = LD8(r5);
        r0 = r0 & 7;
        ST8((r6 + 68), r0);
        if (!((unsigned)r7 >= (unsigned)r0)) {
            r6 = r9;
            r9 = r11;
            r5 = r8;
            do {
                r1 = LD8(r6);
                r1 = r1 + 1;
                ST8(r6, r1);
                r1 = LD8((r1 & 255) + r5);
                r3 = (r4 * r10) + r9;
                ST8(((r3 + r7) + 52), r1);
                r7 = (r7 + 1) & 255;
                r1 = LD8((r3 + 68));
            } while (AGAIN(!((unsigned)r7 >= (unsigned)(r1 & 255))));
        }
        r1 = r4;
    } else {
        ST8((r6 + 68), 0);
        r5 = 4;
        r3 = r11;
        r2 = -1;
        c3 = r4 * r10;
        m0 = (unsigned)c3;
        r1 = c3;
        do {
            ST8((((r1 + r3) + r7) + 52), r2);
            r7 = (r7 + 1) & 255;
            r1 = (int)m0;
        } while (AGAIN(!((unsigned)r7 > (unsigned)r5)));
        r1 = r4;
    }
    return (r1 + 1) & 255;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06017AA4(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, c11, c13, c17, c19, c23, c25, c1038, c1040, c1047;
    FRAME(sp, 44);

    ST32(sp - 36, r4);
    r11 = LD32(r4);
    r11 = r11 + 1;
    r1 = LD8(r11);
    r13 = 32;
    if (!((r1 & 255) == 35)) {
        r9 = r11;
        r3 = 7;
        r2 = 0x06075135;
        while (1) {
            r1 = LD8(r9);
            r0 = LD8((r1 & 255) + r2);
            if (((r0 & 7) & (r0 & 7)) == 0) {
                break;
            } else {
                r9 = r9 + 1;
                if (!((r9 - r11) > r3)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        r10 = r9 - r11;
        r8 = 0x06075238;
        r0 = GCALL3(0x06075238, 0x06017A90, r11, 2);
        r6 = 2;
        if (!((r0 & r0) == 0)) {
            r0 = GCALL3(r8, 0x06017A94, r11, r6);
            r6 = 3;
            if (!((r0 & r0) == 0)) {
                r0 = GCALL3(r8, 0x06017A98, r11, r6);
                r6 = 4;
                if (!((r0 & r0) == 0)) {
                    r0 = GCALL3(r8, 0x06017A9C, r11, r6);
                    r1 = 0;
                    if (!((r0 & r0) == 0)) {
                        ST32(sp - 40, r1);
                        ST32(sp - 44, r1);
                        r0 = GCALL7(0x0604B358, (sp - 44), r11, r10, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                        r12 = 0;
                        if (r10 > 0) {
                            r14 = 95;
                            while (1) {
                                r3 = 0x06017790;
                                r7 = LD32(sp - 44);
                                r8 = 0;
                                r2 = LD32(sp - 40);
                                while (1) {
                                    r1 = LD32(r3);
                                    if (!(r7 == r1)) {
                                        r8 = r8 + 1;
                                        r3 = r3 + 8;
                                        if (!(r8 > r14)) {
                                            POLL();
                                            continue;
                                        } else {
                                            break;
                                        }
                                    } else {
                                        r1 = LD32(r3 + 4);
                                        c11 = r2 == r1;
                                        r1 = r8;
                                        if (!(c11)) {
                                            r8 = r8 + 1;
                                            r3 = r3 + 8;
                                            if (!(r8 > r14)) {
                                                POLL();
                                                continue;
                                            } else {
                                                break;
                                            }
                                        } else {
                                            r13 = (r1 - 96) & 255;
                                            r12 = 1;
                                            break;
                                        }
                                    }
                                    POLL();
                                }
                                c13 = r8 > r14;
                                r1 = 0;
                                c1038 = c13;
                                if (c13) {
                                    ST32(sp - 40, r1);
                                    ST32(sp - 44, r1);
                                    r6 = 0x06075135;
                                    r2 = sp - 44;
                                    r7 = (sp - 44) + 7;
                                    do {
                                        r1 = LD8(r2);
                                        r1 = r1 & 255;
                                        r5 = LD8(r1 + r6);
                                        if (!(((r5 & 1) & (r5 & 1)) == 0)) {
                                            r1 = r1 + 32;
                                        }
                                        ST8(r2, r1);
                                        r2 = r2 + 1;
                                    } while (AGAIN(!(r2 > r7)));
                                    r8 = 0;
                                    r7 = LD32(sp - 44);
                                    r6 = 95;
                                    r2 = LD32(sp - 40);
                                    while (1) {
                                        r1 = LD32(r3);
                                        if (!(r7 == r1)) {
                                            r8 = r8 + 1;
                                            r3 = r3 + 8;
                                            if (!(r8 > r6)) {
                                                POLL();
                                                continue;
                                            } else {
                                                break;
                                            }
                                        } else {
                                            r1 = LD32(r3 + 4);
                                            c17 = r2 == r1;
                                            r1 = r8;
                                            if (!(c17)) {
                                                r8 = r8 + 1;
                                                r3 = r3 + 8;
                                                if (!(r8 > r6)) {
                                                    POLL();
                                                    continue;
                                                } else {
                                                    break;
                                                }
                                            } else {
                                                r13 = (r1 - 96) & 255;
                                                r12 = 1;
                                                break;
                                            }
                                        }
                                        POLL();
                                    }
                                    c19 = r8 > r14;
                                    r6 = r10;
                                    c1038 = c19;
                                    if (c19) {
                                        r0 = GCALL7(0x0604B358, (sp - 44), r11, r6, 0, LD32((sp - 44)), LD32((sp - 40)), LD32((sp - 36)));
                                        c1038 = r8 > r14;
                                    }
                                }
                                c1040 = r10 > 0;
                                if (c1038) {
                                    r10 = r10 - 1;
                                    r9 = r9 - 1;
                                    ST8((sp - 44) + r10, 0);
                                    c1040 = r10 > 0;
                                }
                                c23 = (r12 & r12) == 0;
                                if (!(c1040)) {
                                    break;
                                } else {
                                    if (c23) {
                                        POLL();
                                        continue;
                                    } else {
                                        break;
                                    }
                                }
                                POLL();
                            }
                        }
                        r1 = r11;
                        if (!((r10 & r10) == 0)) {
                            r1 = LD8(r9);
                            c25 = (r1 & 255) == 59;
                            c1047 = c25;
                            if (c25) {
                                r9 = r9 + 1;
                                c1047 = 1;
                            }
                            r0 = LD32(sp - 36);
                            ST32(r0, (r9 - 1));
                            r0 = r13;
                        } else {
                            r0 = LD32(sp - 36);
                            r1 = r1 - 1;
                            ST32(r0, r1);
                            r0 = 38;
                        }
                    } else {
                        r13 = 34;
                        r9 = r11 + 4;
                        r1 = LD8(r9);
                        c25 = (r1 & 255) == 59;
                        c1047 = c25;
                        if (c25) {
                            r9 = r9 + 1;
                            c1047 = 1;
                        }
                        r0 = LD32(sp - 36);
                        ST32(r0, (r9 - 1));
                        r0 = r13;
                    }
                } else {
                    r13 = 38;
                    r9 = r11 + 3;
                    r1 = LD8(r9);
                    c25 = (r1 & 255) == 59;
                    c1047 = c25;
                    if (c25) {
                        r9 = r9 + 1;
                        c1047 = 1;
                    }
                    r0 = LD32(sp - 36);
                    ST32(r0, (r9 - 1));
                    r0 = r13;
                }
            } else {
                r13 = 62;
                r9 = r11 + 2;
                r1 = LD8(r9);
                c25 = (r1 & 255) == 59;
                c1047 = c25;
                if (c25) {
                    r9 = r9 + 1;
                    c1047 = 1;
                }
                r0 = LD32(sp - 36);
                ST32(r0, (r9 - 1));
                r0 = r13;
            }
        } else {
            r13 = 60;
            r9 = r11 + 2;
            r1 = LD8(r9);
            c25 = (r1 & 255) == 59;
            c1047 = c25;
            if (c25) {
                r9 = r9 + 1;
                c1047 = 1;
            }
            r0 = LD32(sp - 36);
            ST32(r0, (r9 - 1));
            r0 = r13;
        }
    } else {
        r9 = r11 + 1;
        r1 = LD8(r9);
        r2 = 0x06075135;
        r0 = LD8((r1 & 255) + 0x06075135);
        r11 = r9;
        while (1) {
            r9 = r9 + 1;
            if (!(((r0 & 4) & (r0 & 4)) == 0)) {
                POLL();
                r1 = LD8(r9);
                r0 = LD8((r1 & 255) + r2);
                continue;
            } else {
                break;
            }
        }
        r9 = r9 - 1;
        r1 = r11;
        if (!(r11 == r9)) {
            r0 = GCALL1(0x06075438, r11);
            r13 = r0 & 255;
            r1 = LD8(r9);
            c25 = (r1 & 255) == 59;
            c1047 = c25;
            if (c25) {
                r9 = r9 + 1;
                c1047 = 1;
            }
            r0 = LD32(sp - 36);
            ST32(r0, (r9 - 1));
            r0 = r13;
        } else {
            r0 = LD32(sp - 36);
            r1 = r1 - 2;
            ST32(r0, r1);
            r0 = 38;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06017DD4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c5, c9, c20, c22, c24, c26, c31, c38, c57, c58, c68, c70, c72, c74, c76, c77, c78, c81, c82, c84, c91, c92, c93, c96, c97, c103, c1013, c1015, c1027, c1030, c2012;
    FRAME(sp, 116);

    ST32(sp - 80, r4);
    r12 = r5;
    ST32(sp - 76, r6);
    ST32(sp - 72, r7);
    ST32(sp - 68, 1);
    ST32(sp - 60, 0);
    ST32(sp - 56, 0);
    ST32(sp - 52, 0);
    ST32(sp - 48, 0);
    ST32(sp - 44, r4);
    ST32(sp - 40, 0);
    ST32(r12 + 0x10D4, r6);
    r3 = LD32(sp - 76);
    r1 = 0;
    if ((r3 & r3) == 0) {
        ST8(r12 + 0x10D8, r1);
        ST32((64 + (sp - 100)), 0);
    } else {
        r4 = LD32(sp - 44);
        r0 = GCALL1(0x06045560, r4);
        r2 = r0;
        ST8(r12 + 0x10D8, r2);
        ST32((64 + (sp - 100)), ((signed char)r2));
    }
    r0 = GCALL2(0x06028380, 0x2000, -1);
    r14 = r0;
    r1 = LD32(sp - 80);
    if (!((r14 & r14) == 0)) {
        r13 = r14;
        r1 = LD8(r1);
        r9 = 0;
        while (1) {
            r8 = r1 & 255;
            if ((r8 & r8) == 0) {
                break;
            } else {
                POLL();
                r3 = LD32(sp - 68);
                if (!((r3 & r3) == 0)) {
                    r0 = GCALL0(0x0605299C);
                    r1 = LD32(sp - 80);
                    ST32(0x0608AB64, r1);
                    r0 = LD32(sp - 76);
                    if ((r0 & r0) == 0) {
                        r0 = LD32(sp - 76);
                        if (r9 > 0x1FFC) {
                            r9 = r9 - 4;
                            ST8(r14 + r9, 0);
                            c1013 = 1;
                            r0 = LD32(sp - 76);
                        }
                        c1015 = (r0 & r0) == 0;
                    } else {
                        c5 = (r0 & r0) == 0;
                        c1015 = c5;
                        if (r9 > 0xFFC) {
                            r9 = r9 - 4;
                            ST16((r9 + r9) + r13, 0);
                            c1013 = c5;
                            r0 = LD32(sp - 76);
                            c1015 = (r0 & r0) == 0;
                        }
                    }
                    r3 = 64;
                    if (c1015) {
                        r11 = 0;
                        ST32(sp - 64, 1);
                    } else {
                        r5 = LD32((r3 + (sp - 100)));
                        r4 = LD32(sp - 80);
                        r0 = GCALL2(0x06045760, r4, r5);
                        r11 = r0 & 0xFFFF;
                        r8 = 0;
                        if (!(((int)((unsigned)r11 >> 8)) == 128)) {
                            ST32(sp - 64, 2);
                        } else {
                            r8 = r11 & 255;
                            ST32(sp - 64, 1);
                        }
                    }
                    r0 = LD32(sp - 76);
                    c9 = (r0 & r0) == 0;
                    r0 = LD32(sp - 64);
                    if (c9) {
                        r10 = 0;
                        if (r8 == 60) {
                            r1 = LD32(sp - 80);
                            r1 = LD8((r1 + 1));
                            r0 = LD8((r1 & 255) + 0x06075135);
                            c1027 = ((r0 & 8) & (r0 & 8)) == 0;
                            if (c1027) {
                                r10 = 1;
                            }
                        }
                        c1030 = (r10 & r10) == 0;
                    } else {
                        r10 = 0;
                        if (!(r0 == 1)) {
                            c1030 = (r10 & r10) == 0;
                        } else {
                            c1030 = (r10 & r10) == 0;
                            if (r8 == 60) {
                                r4 = LD32(sp - 80);
                                r3 = LD32(sp - 64);
                                r5 = LD32((64 + (sp - 100)));
                                r0 = GCALL2(0x06045760, (r4 + r3), r5);
                                r0 = GCALL1(0x060455C4, (r0 & 0xFFFF));
                                c1027 = (r0 & r0) == 0;
                                if (c1027) {
                                    r10 = 1;
                                }
                                c1030 = (r10 & r10) == 0;
                            }
                        }
                    }
                    r10 = LD32(sp - 80);
                    if (c1030) {
                        r3 = LD32(sp - 76);
                        r1 = LD32(r12);
                        if ((r3 & r3) == 0) {
                            r0 = r8;
                            if ((r1 & r1) == 0) {
                                r1 = r8;
                                if (r0 == 32) {
                                    r1 = 32;
                                    if (!(r9 > 0)) {
                                        r0 = r14;
                                        ST8(r0 + r9, r1);
                                        r9 = r9 + 1;
                                    } else {
                                        r1 = LD8(((r9 + r14) - 1));
                                        c38 = (r1 & 255) == 32;
                                        r1 = 32;
                                        if (!(c38)) {
                                            ST8(r9 + r14, r1);
                                            r9 = r9 + 1;
                                        }
                                    }
                                } else {
                                    r2 = r8;
                                    if (!((unsigned)((r1 - 9) & 255) > (unsigned)1)) {
                                        r1 = 32;
                                        if (!(r9 > 0)) {
                                            r0 = r14;
                                            ST8(r0 + r9, r1);
                                            r9 = r9 + 1;
                                        } else {
                                            r1 = LD8(((r9 + r14) - 1));
                                            c38 = (r1 & 255) == 32;
                                            r1 = 32;
                                            if (!(c38)) {
                                                ST8(r9 + r14, r1);
                                                r9 = r9 + 1;
                                            }
                                        }
                                    } else {
                                        r10 = r14;
                                        if (!(r0 == 13)) {
                                            r10 = r10 + r9;
                                            r9 = r9 + 1;
                                            if (!(r8 == 38)) {
                                                ST8(r10, r2);
                                            } else {
                                                r0 = GCALL1(0x06017AA4, (sp - 80));
                                                ST8(r10, r0);
                                            }
                                        } else {
                                            r1 = 32;
                                            if (!(r9 > 0)) {
                                                r0 = r14;
                                                ST8(r0 + r9, r1);
                                                r9 = r9 + 1;
                                            } else {
                                                r1 = LD8(((r9 + r14) - 1));
                                                c38 = (r1 & 255) == 32;
                                                r1 = 32;
                                                if (!(c38)) {
                                                    ST8(r9 + r14, r1);
                                                    r9 = r9 + 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                c31 = r0 == 9;
                                if (!(r0 == 10)) {
                                    r0 = r8;
                                    if (!(c31)) {
                                        r10 = r14;
                                        if (!(r0 == 13)) {
                                            r10 = r10 + r9;
                                            r9 = r9 + 1;
                                            if (r0 == 38) {
                                                r0 = GCALL1(0x06017AA4, (sp - 80));
                                                ST8(r10, r0);
                                            } else {
                                                ST8(r10, r8);
                                            }
                                        }
                                    } else {
                                        r1 = 32;
                                        r0 = r14;
                                        ST8(r0 + r9, 32);
                                        r9 = r9 + 1;
                                        ST8(r0 + r9, 32);
                                        r9 = r9 + 1;
                                        ST8(r0 + r9, r1);
                                        r9 = r9 + 1;
                                    }
                                } else {
                                    ST8(r14 + r9, 0);
                                    r6 = LD32(sp - 76);
                                    r0 = GCALL3(0x0601DD98, r12, r14, r6);
                                    r0 = GCALL2(0x060193B0, r12, 0);
                                    r9 = 0;
                                    ST16(r13, 0);
                                }
                            }
                        } else {
                            r0 = r8;
                            if ((r1 & r1) == 0) {
                                r0 = GCALL1(0x060455C4, r11);
                                c24 = r9 > 0;
                                if ((r0 & r0) == 0) {
                                    r0 = r9;
                                    if (!(r8 == 38)) {
                                        ST16((r0 + r0) + r13, r11);
                                        r9 = r9 + 1;
                                    } else {
                                        r4 = sp - 100;
                                        r0 = GCALL1(0x06017AA4, (r4 + 20));
                                        r1 = (r0 & 255) | -32768;
                                        r0 = r9 + r9;
                                        ST16(r0 + r13, r1);
                                        r9 = r9 + 1;
                                    }
                                } else {
                                    r2 = r9;
                                    if (!(c24)) {
                                        r1 = -32448;
                                        r0 = r9;
                                        if (!(r11 == 0x8140)) {
                                            r1 = -32736;
                                            r0 = r0 + r0;
                                        } else {
                                            r0 = r0 + r0;
                                        }
                                        ST16(r0 + r13, r1);
                                        r9 = r9 + 1;
                                    } else {
                                        r2 = r2 + r2;
                                        r1 = LD16(((r2 + r13) - 2));
                                        c26 = r11 == 0x8140;
                                        if (!((r1 & 0xFFFF) == 0x8140)) {
                                            r0 = r2;
                                            if (!(c26)) {
                                                ST16(r0 + r13, -32736);
                                                r9 = r9 + 1;
                                            } else {
                                                ST16(r0 + r13, -32448);
                                                r9 = r9 + 1;
                                            }
                                        }
                                    }
                                }
                            } else {
                                c20 = r0 == 9;
                                if (!(r0 == 10)) {
                                    r0 = r9;
                                    if (!(c20)) {
                                        r0 = r8;
                                        c22 = r0 == 38;
                                        if (!(r0 == 13)) {
                                            r4 = sp - 100;
                                            if (c22) {
                                                r0 = GCALL1(0x06017AA4, (r4 + 20));
                                                r1 = (r0 & 255) | -32768;
                                                r0 = r9 + r9;
                                                ST16(r0 + r13, r1);
                                                r9 = r9 + 1;
                                            } else {
                                                r0 = r9;
                                                ST16((r0 + r0) + r13, r11);
                                                r9 = r9 + 1;
                                            }
                                        }
                                    } else {
                                        r1 = -32736;
                                        ST16((r0 + r0) + r13, -32736);
                                        r9 = r9 + 1;
                                        ST16((r9 + r9) + r13, -32736);
                                        r9 = r9 + 1;
                                        r0 = r9 + r9;
                                        ST16(r0 + r13, r1);
                                        r9 = r9 + 1;
                                    }
                                } else {
                                    ST16((r9 + r9) + r13, 0);
                                    r6 = LD32(sp - 76);
                                    r0 = GCALL3(0x0601DD98, r12, r14, r6);
                                    r0 = GCALL2(0x060193B0, r12, 0);
                                    r9 = 0;
                                    ST16(r13, 0);
                                }
                            }
                        }
                        r1 = LD32(sp - 80);
                        r3 = LD32(sp - 64);
                        ST32(sp - 80, (r1 + r3));
                    } else {
                        r6 = LD32(sp - 64);
                        r6 = r6 + r10;
                        ST32(sp - 80, r6);
                        r0 = GCALL3(0x06017534, r12, (sp - 100), r6);
                        r1 = LD8(sp - 100);
                        ST32(sp - 80, r0);
                        r8 = 0;
                        if (!((r1 & 255) == 47)) {
                            r0 = 0x060176FC;
                            r4 = sp - 100;
                        } else {
                            r8 = 1;
                            r0 = 0x060176FC;
                            r4 = (sp - 100) + 1;
                        }
                        r0 = GCALL1(r0, r4);
                        r1 = r0;
                        if (!((r1 & r1) == 0)) {
                            r0 = LD32(sp - 60);
                            if (!((r0 & r0) == 0)) {
                                r3 = LD32(sp - 60);
                                r0 = LD32(sp - 56);
                                ST32(sp - 52, r3);
                                ST32(sp - 48, r0);
                            }
                        }
                        ST32(sp - 60, r1);
                        ST32(sp - 56, r8);
                        if ((r1 & r1) == 0) {
                            r3 = LD32(sp - 72);
                        } else {
                            r1 = LD32(r1 + 4);
                            r3 = LD32(sp - 72);
                            if (r1 == 46) {
                                ST32(sp - 80, (r10 + 4));
                                r3 = LD32(sp - 72);
                            }
                        }
                        r0 = LD32(sp - 76);
                        if ((r3 & r3) == 0) {
                            r3 = LD32(sp - 76);
                            r1 = r9;
                            if ((r3 & r3) == 0) {
                                ST8(r14 + r9, 0);
                            } else {
                                ST16((r1 + r1) + r13, 0);
                            }
                            r0 = GCALL3(0x060750A0, (r12 + 0x1B0), r14, 255);
                            ST8(r12 + 0x2AF, 0);
                            r9 = 0;
                            ST16(r13, 0);
                            r3 = LD32(sp - 56);
                        } else {
                            r1 = r9;
                            if ((r0 & r0) == 0) {
                                ST8(r14 + r9, 0);
                            } else {
                                ST16((r1 + r1) + r13, 0);
                            }
                            r3 = LD32(sp - 56);
                            if (r9 > 0) {
                                ST32((sp - 104), r10);
                                r0 = LD32(sp - 44);
                                ST32((sp - 108), r0);
                                ST32((sp - 112), r14);
                                r3 = LD32((64 + (sp - 112)));
                                ST32((sp - 116), r3);
                                r7 = LD32(64 + (sp - 116));
                                r6 = LD32(sp - 56);
                                r5 = LD32(sp - 60);
                                r0 = GCALL8(0x06017D08, r12, r5, r6, r7, LD32((sp - 116)), LD32((sp - 112)), LD32((sp - 108)), LD32((sp - 104)));
                                if ((r0 & r0) == 0) {
                                    r9 = 0;
                                } else {
                                    r6 = LD32(sp - 76);
                                    r0 = GCALL3(0x0601DD98, r12, r14, r6);
                                    r9 = 0;
                                }
                                ST16(r13, 0);
                                r3 = LD32(sp - 56);
                            }
                        }
                        if (!((r3 & r3) == 0)) {
                            r3 = LD32(sp - 60);
                        } else {
                            r0 = LD32(sp - 60);
                            if ((r0 & r0) == 0) {
                                r3 = LD32(sp - 60);
                            } else {
                                r2 = LD32(r0 + 4);
                                r3 = LD32(sp - 60);
                                if ((unsigned)r2 > (unsigned)8) {
                                    r3 = LD32(sp - 72);
                                    if ((r3 & r3) == 0) {
                                        r5 = 0;
                                        if (!(r2 == 46)) {
                                            r0 = GCALL2(0x0601B558, r12, r5);
                                            ST32(sp - 72, 1);
                                        }
                                    }
                                    r3 = LD32(sp - 60);
                                }
                            }
                        }
                        if (!((r3 & r3) == 0)) {
                            r1 = LD32(r3 + 4);
                            r0 = r1;
                            c57 = r0 == 3;
                            if (!(r0 == 8)) {
                                if (c57) {
                                    r3 = LD32(sp - 56);
                                    r0 = LD32(sp - 72);
                                    if ((r3 & r3) == 0) {
                                        r3 = 0;
                                        if (!((r0 & r0) == 0)) {
                                            r0 = GCALL1(0x0601D4D8, r12);
                                            r3 = 0;
                                        }
                                        ST32(sp - 72, r3);
                                    }
                                }
                            } else {
                                r3 = LD32(sp - 56);
                                c58 = (r3 & r3) == 0;
                                r3 = 1;
                                if (c58) {
                                    r9 = 0;
                                    ST16(r13, 0);
                                }
                                ST32(sp - 72, r3);
                            }
                            r1 = LD32(0x10C8 + r12);
                            r0 = LD32(sp - 56);
                            if ((r1 & r1) == 0) {
                                r3 = LD32(sp - 68);
                            } else {
                                r3 = LD32(sp - 68);
                                if ((r0 & r0) == 0) {
                                    r3 = LD32(sp - 60);
                                    r1 = LD32(r3 + 4);
                                    r3 = LD32(sp - 68);
                                    if (r1 == 50) {
                                        r3 = LD32(sp - 52);
                                        r0 = LD32(sp - 52);
                                        if ((r3 & r3) == 0) {
                                            c2012 = R(12);
                                            SETR(12, r12);
                                            r0 = GCALL2(0x06029288, r12, 0);
                                            SETR(12, c2012);
                                            r0 = GCALL1(0x0602929C, r12);
                                            ST32(sp - 68, r0);
                                            r3 = LD32(sp - 68);
                                        } else {
                                            r1 = LD32(r0 + 4);
                                            r3 = LD32(sp - 68);
                                            if (r1 == 50) {
                                                c2012 = R(12);
                                                SETR(12, r12);
                                                r0 = GCALL2(0x06029288, r12, 0);
                                                SETR(12, c2012);
                                                r0 = GCALL1(0x0602929C, r12);
                                                ST32(sp - 68, r0);
                                                r3 = LD32(sp - 68);
                                            }
                                        }
                                    }
                                }
                            }
                            r0 = LD32(sp - 68);
                            if (!((r3 & r3) == 0)) {
                                r1 = LD32(0x10C8 + r12);
                                r0 = LD32(sp - 56);
                                if ((r1 & r1) == 0) {
                                    r0 = LD32(sp - 68);
                                } else {
                                    c68 = (r0 & r0) == 0;
                                    r0 = LD32(sp - 68);
                                    if (c68) {
                                        r0 = GCALL1(0x060290B8, r12);
                                        r3 = LD32(sp - 60);
                                        if ((r0 & r0) == 0) {
                                            r8 = LD32(r3 + 4);
                                            r0 = GCALL1(0x06029058, r12);
                                            c70 = (r0 & r0) == 0;
                                            r0 = r8;
                                            if (c70) {
                                                r1 = r8;
                                                if (!(r0 == 46)) {
                                                    r3 = 1;
                                                    c72 = (unsigned)(r1 - 51) > (unsigned)1;
                                                    r1 = r8;
                                                    if (c72) {
                                                        c74 = r0 == 55;
                                                        if ((unsigned)(r1 - 53) > (unsigned)r3) {
                                                            r1 = r8;
                                                            if (!(c74)) {
                                                                c76 = r0 == 56;
                                                                if ((unsigned)(r1 - 47) > (unsigned)r3) {
                                                                    r5 = 0;
                                                                    if (!(c76)) {
                                                                        c2012 = R(12);
                                                                        SETR(12, r12);
                                                                        r0 = GCALL2(0x06029288, r12, r5);
                                                                        SETR(12, c2012);
                                                                        ST32(sp - 68, r0);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        r0 = GCALL1(0x060290DC, r12);
                                        c77 = (r0 & r0) == 0;
                                        r0 = LD32(sp - 68);
                                        if (c77) {
                                            r0 = LD32(sp - 60);
                                            r8 = LD32(r0 + 4);
                                            r0 = GCALL1(0x06029058, r12);
                                            c78 = (r0 & r0) == 0;
                                            r0 = LD32(sp - 68);
                                            if (c78) {
                                                r0 = r8;
                                                if (!(r0 == 46)) {
                                                    r3 = 1;
                                                    if ((unsigned)(r8 - 51) > (unsigned)1) {
                                                        c81 = (unsigned)(r8 - 53) > (unsigned)r3;
                                                        c82 = r0 == 55;
                                                        if (c81) {
                                                            if (!(c82)) {
                                                                c84 = r0 == 56;
                                                                if ((unsigned)(r8 - 47) > (unsigned)r3) {
                                                                    if (!(c84)) {
                                                                        c2012 = R(12);
                                                                        SETR(12, r12);
                                                                        r0 = GCALL2(0x06029288, r12, 0);
                                                                        SETR(12, c2012);
                                                                        ST32(sp - 68, r0);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                r0 = LD32(sp - 68);
                                            }
                                        }
                                    }
                                }
                            }
                            r3 = LD32(sp - 56);
                            if (!((r0 & r0) == 0)) {
                                r0 = LD32(sp - 60);
                                if (!((r3 & r3) == 0)) {
                                    r3 = LD32(sp - 60);
                                    r1 = LD32(r3 + 12);
                                } else {
                                    r1 = LD32(r0 + 8);
                                }
                                r5 = LD32(sp - 80);
                                if (!((r1 & r1) == 0)) {
                                    r0 = GCALL2(r1, r12, r5);
                                    ST32(sp - 68, r0);
                                }
                            }
                        }
                        r0 = LD32(sp - 68);
                        r3 = LD32(sp - 60);
                        if ((r0 & r0) == 0) {
                            r4 = LD32(sp - 80);
                            r0 = GCALL1(0x060176CC, r4);
                            ST32(sp - 80, r0);
                            r3 = LD32(sp - 80);
                        } else {
                            if ((r3 & r3) == 0) {
                                r4 = LD32(sp - 80);
                                r0 = GCALL1(0x060176CC, r4);
                                ST32(sp - 80, r0);
                                r3 = LD32(sp - 80);
                            } else {
                                r1 = LD32(r3 + 4);
                                r7 = LD32(sp - 80);
                                if (!(r1 == 46)) {
                                    r4 = LD32(sp - 80);
                                    r0 = GCALL1(0x060176CC, r4);
                                    ST32(sp - 80, r0);
                                    r3 = LD32(sp - 80);
                                } else {
                                    r1 = LD8(r7);
                                    r2 = r7;
                                    while (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                        POLL();
                                        r1 = LD8(r2);
                                        c91 = (r1 & 255) == 45;
                                        r1 = LD32(sp - 80);
                                        if (!(c91)) {
                                            r1 = r1 + 1;
                                            ST32(sp - 80, r1);
                                            r2 = r1;
                                            r1 = LD8(r2);
                                            continue;
                                        } else {
                                            r1 = LD8((r2 + 1));
                                            c92 = (r1 & 255) == 45;
                                            r1 = LD32(sp - 80);
                                            if (!(c92)) {
                                                r1 = r1 + 1;
                                                ST32(sp - 80, r1);
                                                r2 = r1;
                                                r1 = LD8(r2);
                                                continue;
                                            } else {
                                                r1 = LD8((r2 + 2));
                                                c93 = (r1 & 255) == 62;
                                                r1 = LD32(sp - 80);
                                                if (c93) {
                                                    break;
                                                } else {
                                                    r1 = r1 + 1;
                                                    ST32(sp - 80, r1);
                                                    r2 = r1;
                                                    r1 = LD8(r2);
                                                }
                                            }
                                        }
                                    }
                                    r2 = LD32(sp - 80);
                                    r1 = LD8(r2);
                                    r1 = r1 & 255;
                                    c96 = (r1 & r1) == 0;
                                    if (!(r1 == 45)) {
                                        r3 = LD32(sp - 80);
                                        if (c96) {
                                            ST32(sp - 80, r7);
                                            r1 = LD8(r7);
                                            while (1) {
                                                r2 = LD32(sp - 80);
                                                if (!(((r1 & 255) & (r1 & 255)) == 0)) {
                                                    POLL();
                                                    r1 = LD8(r2);
                                                    c97 = (r1 & 255) == 62;
                                                    r1 = r2;
                                                    if (c97) {
                                                        break;
                                                    } else {
                                                        r1 = r1 + 1;
                                                        ST32(sp - 80, r1);
                                                        r1 = LD8(r1);
                                                        continue;
                                                    }
                                                } else {
                                                    break;
                                                }
                                            }
                                            r2 = LD32(sp - 80);
                                            r1 = LD8(r2);
                                            r3 = LD32(sp - 80);
                                            if ((r1 & 255) == 62) {
                                                ST32(sp - 80, (r2 + 1));
                                                r3 = LD32(sp - 80);
                                            }
                                        }
                                    } else {
                                        ST32(sp - 80, (r2 + 3));
                                        r3 = LD32(sp - 80);
                                    }
                                }
                            }
                        }
                        r2 = LD32(sp - 40);
                        ST32(sp - 44, r3);
                        ST32(sp - 40, (r2 + 1));
                        if (r2 > 30) {
                            r0 = GCALL0(0x0605299C);
                            ST32(sp - 40, 0);
                        }
                    }
                    r1 = LD32(sp - 80);
                    r1 = LD8(r1);
                    continue;
                } else {
                    break;
                }
            }
        }
        r2 = 0x10C8;
        r1 = LD32(r12 + 0x10C8);
        if (!((r1 & r1) == 0)) {
            r8 = r2;
            r9 = 0x0602929C;
            while (1) {
                r0 = GCALL2(r9, r12, 0x06017DD0);
                c103 = (r0 & r0) == 0;
                r0 = r12;
                if (c103) {
                    break;
                } else {
                    r1 = LD32(r0 + r8);
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
        r0 = GCALL1(0x0601D4D8, r12);
        r9 = 0x06027F48;
        r0 = GCALL1(0x06027F48, r14);
        r2 = r12 + 80;
        r1 = LD32(r2);
        if (!((r1 & r1) == 0)) {
            r8 = r2;
            do {
                r4 = LD32(r8);
                r1 = LD32(r4 + 12);
                ST32(r8, r1);
                r2 = LD32(r4);
                if (!(r2 == 0x7FFFFFFF)) {
                    ST32(r12 + 12, r2);
                }
                r0 = GCALL1(r9, r4);
                r1 = LD32(r8);
            } while (AGAIN(!((r1 & r1) == 0)));
        }
        r9 = r12 + 84;
        r1 = LD32(r9);
        if (!((r1 & r1) == 0)) {
            r10 = 0x06027F48;
            do {
                r4 = LD32(r9);
                r1 = LD32(r4 + 12);
                ST32(r9, r1);
                r0 = GCALL1(r10, r4);
                r1 = LD32(r9);
            } while (AGAIN(!((r1 & r1) == 0)));
        }
        r7 = 136;
        r0 = r12;
        r1 = LD32(r0 + 136);
        if (!((r1 & r1) == 0)) {
            r1 = LD32(r12 + 12);
            ST32(r12 + 20, (r1 + 240));
            r0 = r12;
        }
        r1 = LD32(r0 + r7);
        if (!((r1 & r1) == 0)) {
            r0 = 156;
            r1 = LD32(156 + r12);
            if (r1 > 0) {
                r0 = GCALL1(0x0604476C, r12);
            }
        }
    } else {
        ST32(r12 + 20, 0);
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06018688(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r8, r9, r10, r11, r12, r13, r14, c3, c5, c6, c7, c9, c11, c12, c17, c18, c23, c24, c25, c35, c36, c37, c39, c41, c42, c43, c44, c47, c48, c49, c50, c53, c54, c55, c1021, c1030, c1043, c1065, c1067, c1074, c1077;
    FRAME(sp, 40);

    ST32(sp - 36, r4);
    r12 = r5;
    r11 = r6;
    r13 = r7;
    ST32(r4, 0);
    r9 = 0;
    ST32(sp - 40, 0);
    if (!((r12 & r12) == 0)) {
        r10 = r12;
        if (!((r13 & r13) == 0)) {
            r9 = 5;
        }
        r1 = LD8(r10);
        r8 = r1 & 255;
        c3 = (r9 & r9) == 0;
        c1043 = c3;
        if (!((r8 & r8) == 0)) {
            r14 = 0x06018588;
            r0 = r8;
            do {
                c5 = r0 == 60;
                if (r0 == 62) {
                    r0 = GCALL6(0x0601852C, r8, 0, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                    r9 = (r9 + 3) + ((signed char)r0);
                } else {
                    c6 = r0 == 38;
                    if (c5) {
                        r0 = GCALL6(0x0601852C, r8, 0, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                        r9 = (r9 + 3) + ((signed char)r0);
                    } else {
                        c7 = r0 == 34;
                        if (c6) {
                            r0 = GCALL6(0x0601852C, r8, 0, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                            r9 = (r9 + 3) + ((signed char)r0);
                        } else {
                            r1 = 127;
                            if (c7) {
                                r0 = GCALL6(0x0601852C, r8, 0, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                r9 = (r9 + 3) + ((signed char)r0);
                            } else {
                                c9 = (r11 & r11) == 0;
                                if (!((unsigned)r8 > (unsigned)r1)) {
                                    r0 = r8;
                                    if (c9) {
                                        c1021 = (r13 & r13) == 0;
                                        r0 = r8;
                                        if (c1021) {
                                            c1030 = (r11 & r11) == 0;
                                            r0 = r8;
                                            if (c1030) {
                                                r9 = r9 + 1;
                                            } else {
                                                c23 = r0 == 72;
                                                if (r0 == 104) {
                                                    r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                    r6 = 7;
                                                    if ((r0 & r0) == 0) {
                                                        ST32(sp - 40, 0);
                                                        r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                        if ((r0 & r0) == 0) {
                                                            r9 = r9 + 1;
                                                        }
                                                        r2 = LD32(sp - 40);
                                                        r9 = (r9 + 15) + (r2 + r2);
                                                        r10 = r10 + (r2 - 1);
                                                    } else {
                                                        r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                        if (!((r0 & r0) == 0)) {
                                                            r9 = r9 + 1;
                                                        } else {
                                                            ST32(sp - 40, 0);
                                                            r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                            if ((r0 & r0) == 0) {
                                                                r9 = r9 + 1;
                                                            }
                                                            r2 = LD32(sp - 40);
                                                            r9 = (r9 + 15) + (r2 + r2);
                                                            r10 = r10 + (r2 - 1);
                                                        }
                                                    }
                                                } else {
                                                    c24 = r0 == 109;
                                                    if (c23) {
                                                        r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                        r6 = 7;
                                                        if ((r0 & r0) == 0) {
                                                            ST32(sp - 40, 0);
                                                            r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                            if ((r0 & r0) == 0) {
                                                                r9 = r9 + 1;
                                                            }
                                                            r2 = LD32(sp - 40);
                                                            r9 = (r9 + 15) + (r2 + r2);
                                                            r10 = r10 + (r2 - 1);
                                                        } else {
                                                            r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                            if (!((r0 & r0) == 0)) {
                                                                r9 = r9 + 1;
                                                            } else {
                                                                ST32(sp - 40, 0);
                                                                r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                if ((r0 & r0) == 0) {
                                                                    r9 = r9 + 1;
                                                                }
                                                                r2 = LD32(sp - 40);
                                                                r9 = (r9 + 15) + (r2 + r2);
                                                                r10 = r10 + (r2 - 1);
                                                            }
                                                        }
                                                    } else {
                                                        c25 = r0 == 77;
                                                        if (c24) {
                                                            r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                            r6 = 7;
                                                            if ((r0 & r0) == 0) {
                                                                ST32(sp - 40, 0);
                                                                r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                if ((r0 & r0) == 0) {
                                                                    r9 = r9 + 1;
                                                                }
                                                                r2 = LD32(sp - 40);
                                                                r9 = (r9 + 15) + (r2 + r2);
                                                                r10 = r10 + (r2 - 1);
                                                            } else {
                                                                r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                if (!((r0 & r0) == 0)) {
                                                                    r9 = r9 + 1;
                                                                } else {
                                                                    ST32(sp - 40, 0);
                                                                    r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                    if ((r0 & r0) == 0) {
                                                                        r9 = r9 + 1;
                                                                    }
                                                                    r2 = LD32(sp - 40);
                                                                    r9 = (r9 + 15) + (r2 + r2);
                                                                    r10 = r10 + (r2 - 1);
                                                                }
                                                            }
                                                        } else {
                                                            if (!(c25)) {
                                                                r9 = r9 + 1;
                                                            } else {
                                                                r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                r6 = 7;
                                                                if ((r0 & r0) == 0) {
                                                                    ST32(sp - 40, 0);
                                                                    r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                    if ((r0 & r0) == 0) {
                                                                        r9 = r9 + 1;
                                                                    }
                                                                    r2 = LD32(sp - 40);
                                                                    r9 = (r9 + 15) + (r2 + r2);
                                                                    r10 = r10 + (r2 - 1);
                                                                } else {
                                                                    r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                    if (!((r0 & r0) == 0)) {
                                                                        r9 = r9 + 1;
                                                                    } else {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        if ((r0 & r0) == 0) {
                                                                            r9 = r9 + 1;
                                                                        }
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = (r9 + 15) + (r2 + r2);
                                                                        r10 = r10 + (r2 - 1);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            c17 = r0 == 10;
                                            if (r0 == 13) {
                                                r2 = r10;
                                                if (r0 == 13) {
                                                    r2 = r2 + 1;
                                                    r1 = LD8(r2);
                                                    if ((r1 & 255) == 10) {
                                                        r10 = r2;
                                                    }
                                                }
                                                r9 = r9 + 7;
                                            } else {
                                                c18 = (r11 & r11) == 0;
                                                c1030 = c18;
                                                if (!(c17)) {
                                                    r0 = r8;
                                                    if (c1030) {
                                                        r9 = r9 + 1;
                                                    } else {
                                                        c23 = r0 == 72;
                                                        if (r0 == 104) {
                                                            r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                            r6 = 7;
                                                            if ((r0 & r0) == 0) {
                                                                ST32(sp - 40, 0);
                                                                r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                if ((r0 & r0) == 0) {
                                                                    r9 = r9 + 1;
                                                                }
                                                                r2 = LD32(sp - 40);
                                                                r9 = (r9 + 15) + (r2 + r2);
                                                                r10 = r10 + (r2 - 1);
                                                            } else {
                                                                r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                if (!((r0 & r0) == 0)) {
                                                                    r9 = r9 + 1;
                                                                } else {
                                                                    ST32(sp - 40, 0);
                                                                    r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                    if ((r0 & r0) == 0) {
                                                                        r9 = r9 + 1;
                                                                    }
                                                                    r2 = LD32(sp - 40);
                                                                    r9 = (r9 + 15) + (r2 + r2);
                                                                    r10 = r10 + (r2 - 1);
                                                                }
                                                            }
                                                        } else {
                                                            c24 = r0 == 109;
                                                            if (c23) {
                                                                r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                r6 = 7;
                                                                if ((r0 & r0) == 0) {
                                                                    ST32(sp - 40, 0);
                                                                    r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                    if ((r0 & r0) == 0) {
                                                                        r9 = r9 + 1;
                                                                    }
                                                                    r2 = LD32(sp - 40);
                                                                    r9 = (r9 + 15) + (r2 + r2);
                                                                    r10 = r10 + (r2 - 1);
                                                                } else {
                                                                    r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                    if (!((r0 & r0) == 0)) {
                                                                        r9 = r9 + 1;
                                                                    } else {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        if ((r0 & r0) == 0) {
                                                                            r9 = r9 + 1;
                                                                        }
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = (r9 + 15) + (r2 + r2);
                                                                        r10 = r10 + (r2 - 1);
                                                                    }
                                                                }
                                                            } else {
                                                                c25 = r0 == 77;
                                                                if (c24) {
                                                                    r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                    r6 = 7;
                                                                    if ((r0 & r0) == 0) {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        if ((r0 & r0) == 0) {
                                                                            r9 = r9 + 1;
                                                                        }
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = (r9 + 15) + (r2 + r2);
                                                                        r10 = r10 + (r2 - 1);
                                                                    } else {
                                                                        r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                        if (!((r0 & r0) == 0)) {
                                                                            r9 = r9 + 1;
                                                                        } else {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            if ((r0 & r0) == 0) {
                                                                                r9 = r9 + 1;
                                                                            }
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = (r9 + 15) + (r2 + r2);
                                                                            r10 = r10 + (r2 - 1);
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (!(c25)) {
                                                                        r9 = r9 + 1;
                                                                    } else {
                                                                        r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                        r6 = 7;
                                                                        if ((r0 & r0) == 0) {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            if ((r0 & r0) == 0) {
                                                                                r9 = r9 + 1;
                                                                            }
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = (r9 + 15) + (r2 + r2);
                                                                            r10 = r10 + (r2 - 1);
                                                                        } else {
                                                                            r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                            if (!((r0 & r0) == 0)) {
                                                                                r9 = r9 + 1;
                                                                            } else {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                if ((r0 & r0) == 0) {
                                                                                    r9 = r9 + 1;
                                                                                }
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = (r9 + 15) + (r2 + r2);
                                                                                r10 = r10 + (r2 - 1);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    r0 = r8;
                                                    r2 = r10;
                                                    if (r0 == 13) {
                                                        r2 = r2 + 1;
                                                        r1 = LD8(r2);
                                                        if ((r1 & 255) == 10) {
                                                            r10 = r2;
                                                        }
                                                    }
                                                    r9 = r9 + 7;
                                                }
                                            }
                                        }
                                    } else {
                                        c11 = r0 == 10;
                                        if (r0 == 13) {
                                            r2 = r10;
                                            if (r0 == 13) {
                                                r2 = r2 + 1;
                                                r1 = LD8(r2);
                                                if ((r1 & 255) == 10) {
                                                    r10 = r2;
                                                }
                                            }
                                            r9 = r9 + 4;
                                        } else {
                                            c12 = (r13 & r13) == 0;
                                            c1021 = c12;
                                            if (!(c11)) {
                                                r0 = r8;
                                                if (c1021) {
                                                    c1030 = (r11 & r11) == 0;
                                                    r0 = r8;
                                                    if (c1030) {
                                                        r9 = r9 + 1;
                                                    } else {
                                                        c23 = r0 == 72;
                                                        if (r0 == 104) {
                                                            r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                            r6 = 7;
                                                            if ((r0 & r0) == 0) {
                                                                ST32(sp - 40, 0);
                                                                r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                if ((r0 & r0) == 0) {
                                                                    r9 = r9 + 1;
                                                                }
                                                                r2 = LD32(sp - 40);
                                                                r9 = (r9 + 15) + (r2 + r2);
                                                                r10 = r10 + (r2 - 1);
                                                            } else {
                                                                r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                if (!((r0 & r0) == 0)) {
                                                                    r9 = r9 + 1;
                                                                } else {
                                                                    ST32(sp - 40, 0);
                                                                    r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                    if ((r0 & r0) == 0) {
                                                                        r9 = r9 + 1;
                                                                    }
                                                                    r2 = LD32(sp - 40);
                                                                    r9 = (r9 + 15) + (r2 + r2);
                                                                    r10 = r10 + (r2 - 1);
                                                                }
                                                            }
                                                        } else {
                                                            c24 = r0 == 109;
                                                            if (c23) {
                                                                r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                r6 = 7;
                                                                if ((r0 & r0) == 0) {
                                                                    ST32(sp - 40, 0);
                                                                    r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                    if ((r0 & r0) == 0) {
                                                                        r9 = r9 + 1;
                                                                    }
                                                                    r2 = LD32(sp - 40);
                                                                    r9 = (r9 + 15) + (r2 + r2);
                                                                    r10 = r10 + (r2 - 1);
                                                                } else {
                                                                    r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                    if (!((r0 & r0) == 0)) {
                                                                        r9 = r9 + 1;
                                                                    } else {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        if ((r0 & r0) == 0) {
                                                                            r9 = r9 + 1;
                                                                        }
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = (r9 + 15) + (r2 + r2);
                                                                        r10 = r10 + (r2 - 1);
                                                                    }
                                                                }
                                                            } else {
                                                                c25 = r0 == 77;
                                                                if (c24) {
                                                                    r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                    r6 = 7;
                                                                    if ((r0 & r0) == 0) {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        if ((r0 & r0) == 0) {
                                                                            r9 = r9 + 1;
                                                                        }
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = (r9 + 15) + (r2 + r2);
                                                                        r10 = r10 + (r2 - 1);
                                                                    } else {
                                                                        r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                        if (!((r0 & r0) == 0)) {
                                                                            r9 = r9 + 1;
                                                                        } else {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            if ((r0 & r0) == 0) {
                                                                                r9 = r9 + 1;
                                                                            }
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = (r9 + 15) + (r2 + r2);
                                                                            r10 = r10 + (r2 - 1);
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (!(c25)) {
                                                                        r9 = r9 + 1;
                                                                    } else {
                                                                        r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                        r6 = 7;
                                                                        if ((r0 & r0) == 0) {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            if ((r0 & r0) == 0) {
                                                                                r9 = r9 + 1;
                                                                            }
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = (r9 + 15) + (r2 + r2);
                                                                            r10 = r10 + (r2 - 1);
                                                                        } else {
                                                                            r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                            if (!((r0 & r0) == 0)) {
                                                                                r9 = r9 + 1;
                                                                            } else {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                if ((r0 & r0) == 0) {
                                                                                    r9 = r9 + 1;
                                                                                }
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = (r9 + 15) + (r2 + r2);
                                                                                r10 = r10 + (r2 - 1);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    c17 = r0 == 10;
                                                    if (r0 == 13) {
                                                        r2 = r10;
                                                        if (r0 == 13) {
                                                            r2 = r2 + 1;
                                                            r1 = LD8(r2);
                                                            if ((r1 & 255) == 10) {
                                                                r10 = r2;
                                                            }
                                                        }
                                                        r9 = r9 + 7;
                                                    } else {
                                                        c18 = (r11 & r11) == 0;
                                                        c1030 = c18;
                                                        if (!(c17)) {
                                                            r0 = r8;
                                                            if (c1030) {
                                                                r9 = r9 + 1;
                                                            } else {
                                                                c23 = r0 == 72;
                                                                if (r0 == 104) {
                                                                    r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                    r6 = 7;
                                                                    if ((r0 & r0) == 0) {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        if ((r0 & r0) == 0) {
                                                                            r9 = r9 + 1;
                                                                        }
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = (r9 + 15) + (r2 + r2);
                                                                        r10 = r10 + (r2 - 1);
                                                                    } else {
                                                                        r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                        if (!((r0 & r0) == 0)) {
                                                                            r9 = r9 + 1;
                                                                        } else {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            if ((r0 & r0) == 0) {
                                                                                r9 = r9 + 1;
                                                                            }
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = (r9 + 15) + (r2 + r2);
                                                                            r10 = r10 + (r2 - 1);
                                                                        }
                                                                    }
                                                                } else {
                                                                    c24 = r0 == 109;
                                                                    if (c23) {
                                                                        r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                        r6 = 7;
                                                                        if ((r0 & r0) == 0) {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            if ((r0 & r0) == 0) {
                                                                                r9 = r9 + 1;
                                                                            }
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = (r9 + 15) + (r2 + r2);
                                                                            r10 = r10 + (r2 - 1);
                                                                        } else {
                                                                            r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                            if (!((r0 & r0) == 0)) {
                                                                                r9 = r9 + 1;
                                                                            } else {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                if ((r0 & r0) == 0) {
                                                                                    r9 = r9 + 1;
                                                                                }
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = (r9 + 15) + (r2 + r2);
                                                                                r10 = r10 + (r2 - 1);
                                                                            }
                                                                        }
                                                                    } else {
                                                                        c25 = r0 == 77;
                                                                        if (c24) {
                                                                            r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                            r6 = 7;
                                                                            if ((r0 & r0) == 0) {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                if ((r0 & r0) == 0) {
                                                                                    r9 = r9 + 1;
                                                                                }
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = (r9 + 15) + (r2 + r2);
                                                                                r10 = r10 + (r2 - 1);
                                                                            } else {
                                                                                r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                                if (!((r0 & r0) == 0)) {
                                                                                    r9 = r9 + 1;
                                                                                } else {
                                                                                    ST32(sp - 40, 0);
                                                                                    r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                    if ((r0 & r0) == 0) {
                                                                                        r9 = r9 + 1;
                                                                                    }
                                                                                    r2 = LD32(sp - 40);
                                                                                    r9 = (r9 + 15) + (r2 + r2);
                                                                                    r10 = r10 + (r2 - 1);
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (!(c25)) {
                                                                                r9 = r9 + 1;
                                                                            } else {
                                                                                r0 = GCALL6(0x06075238, r10, 0x06018660, 7, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                                r6 = 7;
                                                                                if ((r0 & r0) == 0) {
                                                                                    ST32(sp - 40, 0);
                                                                                    r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                    if ((r0 & r0) == 0) {
                                                                                        r9 = r9 + 1;
                                                                                    }
                                                                                    r2 = LD32(sp - 40);
                                                                                    r9 = (r9 + 15) + (r2 + r2);
                                                                                    r10 = r10 + (r2 - 1);
                                                                                } else {
                                                                                    r0 = GCALL6(0x06075238, r10, 0x06018668, r6, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                                    if (!((r0 & r0) == 0)) {
                                                                                        r9 = r9 + 1;
                                                                                    } else {
                                                                                        ST32(sp - 40, 0);
                                                                                        r0 = GCALL6(r14, 0, r10, 1, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                        if ((r0 & r0) == 0) {
                                                                                            r9 = r9 + 1;
                                                                                        }
                                                                                        r2 = LD32(sp - 40);
                                                                                        r9 = (r9 + 15) + (r2 + r2);
                                                                                        r10 = r10 + (r2 - 1);
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r0 = r8;
                                                            r2 = r10;
                                                            if (r0 == 13) {
                                                                r2 = r2 + 1;
                                                                r1 = LD8(r2);
                                                                if ((r1 & 255) == 10) {
                                                                    r10 = r2;
                                                                }
                                                            }
                                                            r9 = r9 + 7;
                                                        }
                                                    }
                                                }
                                            } else {
                                                r0 = r8;
                                                r2 = r10;
                                                if (r0 == 13) {
                                                    r2 = r2 + 1;
                                                    r1 = LD8(r2);
                                                    if ((r1 & 255) == 10) {
                                                        r10 = r2;
                                                    }
                                                }
                                                r9 = r9 + 4;
                                            }
                                        }
                                    }
                                } else {
                                    r0 = GCALL6(0x0601852C, r8, 0, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                    r9 = (r9 + 3) + ((signed char)r0);
                                }
                            }
                        }
                    }
                }
                r10 = r10 + 1;
                r1 = LD8(r10);
                r8 = r1 & 255;
                r0 = r8;
            } while (AGAIN(!((r8 & r8) == 0)));
            c1043 = (r9 & r9) == 0;
        }
        r5 = r9;
        if (!(c1043)) {
            r0 = GCALL6(0x060279E0, 0, (r5 + 1), 3, 1, LD32((sp - 40)), LD32((sp - 36)));
            r1 = r0;
            r0 = LD32(sp - 36);
            ST32(r0, r1);
            if (!((r1 & r1) == 0)) {
                r10 = r12;
                r9 = r1;
                ST8(r9, 0);
                if (!((r13 & r13) == 0)) {
                    r6 = R(6);
                    r7 = R(7);
                    r0 = GCALL6(0x06045264, r9, 0x06018670, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                    r9 = r9 + r0;
                }
                r1 = LD8(r10);
                r8 = r1 & 255;
                r1 = 0;
                if (!((r8 & r8) == 0)) {
                    r14 = 0x06075238;
                    r12 = 0x06018588;
                    r0 = r8;
                    while (1) {
                        c35 = r0 == 60;
                        if (r0 == 62) {
                            r7 = R(7);
                            r0 = GCALL6(0x06018550, r9, r8, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                            r9 = r0;
                        } else {
                            c36 = r0 == 38;
                            if (c35) {
                                r7 = R(7);
                                r0 = GCALL6(0x06018550, r9, r8, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                r9 = r0;
                            } else {
                                c37 = r0 == 34;
                                if (c36) {
                                    r7 = R(7);
                                    r0 = GCALL6(0x06018550, r9, r8, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                    r9 = r0;
                                } else {
                                    r1 = 127;
                                    if (c37) {
                                        r7 = R(7);
                                        r0 = GCALL6(0x06018550, r9, r8, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                        r9 = r0;
                                    } else {
                                        c39 = (r11 & r11) == 0;
                                        if (!((unsigned)r8 > (unsigned)r1)) {
                                            r0 = r8;
                                            if (c39) {
                                                c1067 = (r13 & r13) == 0;
                                                r0 = r8;
                                                if (c1067) {
                                                    c1077 = (r11 & r11) == 0;
                                                    r0 = r8;
                                                    if (c1077) {
                                                        ST8(r9, r8);
                                                        r9 = r9 + 1;
                                                    } else {
                                                        c53 = r0 == 72;
                                                        if (r0 == 104) {
                                                            r7 = R(7);
                                                            r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                            r6 = 7;
                                                            if ((r0 & r0) == 0) {
                                                                ST32(sp - 40, 0);
                                                                r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                r2 = LD32(sp - 40);
                                                                r9 = r9 + ((r2 + r2) + 15);
                                                                r10 = r10 + (r2 - 1);
                                                            } else {
                                                                r7 = R(7);
                                                                r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                if (!((r0 & r0) == 0)) {
                                                                    ST8(r9, r8);
                                                                    r9 = r9 + 1;
                                                                } else {
                                                                    ST32(sp - 40, 0);
                                                                    r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                    r2 = LD32(sp - 40);
                                                                    r9 = r9 + ((r2 + r2) + 15);
                                                                    r10 = r10 + (r2 - 1);
                                                                }
                                                            }
                                                        } else {
                                                            c54 = r0 == 109;
                                                            if (c53) {
                                                                r7 = R(7);
                                                                r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                r6 = 7;
                                                                if ((r0 & r0) == 0) {
                                                                    ST32(sp - 40, 0);
                                                                    r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                    r2 = LD32(sp - 40);
                                                                    r9 = r9 + ((r2 + r2) + 15);
                                                                    r10 = r10 + (r2 - 1);
                                                                } else {
                                                                    r7 = R(7);
                                                                    r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                    if (!((r0 & r0) == 0)) {
                                                                        ST8(r9, r8);
                                                                        r9 = r9 + 1;
                                                                    } else {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = r9 + ((r2 + r2) + 15);
                                                                        r10 = r10 + (r2 - 1);
                                                                    }
                                                                }
                                                            } else {
                                                                c55 = r0 == 77;
                                                                if (c54) {
                                                                    r7 = R(7);
                                                                    r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                    r6 = 7;
                                                                    if ((r0 & r0) == 0) {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = r9 + ((r2 + r2) + 15);
                                                                        r10 = r10 + (r2 - 1);
                                                                    } else {
                                                                        r7 = R(7);
                                                                        r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                        if (!((r0 & r0) == 0)) {
                                                                            ST8(r9, r8);
                                                                            r9 = r9 + 1;
                                                                        } else {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = r9 + ((r2 + r2) + 15);
                                                                            r10 = r10 + (r2 - 1);
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (!(c55)) {
                                                                        ST8(r9, r8);
                                                                        r9 = r9 + 1;
                                                                    } else {
                                                                        r7 = R(7);
                                                                        r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                        r6 = 7;
                                                                        if ((r0 & r0) == 0) {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = r9 + ((r2 + r2) + 15);
                                                                            r10 = r10 + (r2 - 1);
                                                                        } else {
                                                                            r7 = R(7);
                                                                            r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                            if (!((r0 & r0) == 0)) {
                                                                                ST8(r9, r8);
                                                                                r9 = r9 + 1;
                                                                            } else {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = r9 + ((r2 + r2) + 15);
                                                                                r10 = r10 + (r2 - 1);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    c47 = r0 == 10;
                                                    if (r0 == 13) {
                                                        c49 = r0 == 13;
                                                        r2 = r10;
                                                        c1074 = c49;
                                                        if (c49) {
                                                            r2 = r2 + 1;
                                                            r1 = LD8(r2);
                                                            c50 = (r1 & 255) == 10;
                                                            c1074 = c50;
                                                            if (c50) {
                                                                r10 = r2;
                                                                c1074 = 1;
                                                            }
                                                        }
                                                        r5 = 0x06018680;
                                                        r6 = R(6);
                                                        r7 = R(7);
                                                        r0 = GCALL6(0x06045264, r9, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                        r9 = r9 + r0;
                                                    } else {
                                                        c48 = (r11 & r11) == 0;
                                                        c1077 = c48;
                                                        if (!(c47)) {
                                                            r0 = r8;
                                                            if (c1077) {
                                                                ST8(r9, r8);
                                                                r9 = r9 + 1;
                                                            } else {
                                                                c53 = r0 == 72;
                                                                if (r0 == 104) {
                                                                    r7 = R(7);
                                                                    r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                    r6 = 7;
                                                                    if ((r0 & r0) == 0) {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = r9 + ((r2 + r2) + 15);
                                                                        r10 = r10 + (r2 - 1);
                                                                    } else {
                                                                        r7 = R(7);
                                                                        r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                        if (!((r0 & r0) == 0)) {
                                                                            ST8(r9, r8);
                                                                            r9 = r9 + 1;
                                                                        } else {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = r9 + ((r2 + r2) + 15);
                                                                            r10 = r10 + (r2 - 1);
                                                                        }
                                                                    }
                                                                } else {
                                                                    c54 = r0 == 109;
                                                                    if (c53) {
                                                                        r7 = R(7);
                                                                        r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                        r6 = 7;
                                                                        if ((r0 & r0) == 0) {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = r9 + ((r2 + r2) + 15);
                                                                            r10 = r10 + (r2 - 1);
                                                                        } else {
                                                                            r7 = R(7);
                                                                            r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                            if (!((r0 & r0) == 0)) {
                                                                                ST8(r9, r8);
                                                                                r9 = r9 + 1;
                                                                            } else {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = r9 + ((r2 + r2) + 15);
                                                                                r10 = r10 + (r2 - 1);
                                                                            }
                                                                        }
                                                                    } else {
                                                                        c55 = r0 == 77;
                                                                        if (c54) {
                                                                            r7 = R(7);
                                                                            r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                            r6 = 7;
                                                                            if ((r0 & r0) == 0) {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = r9 + ((r2 + r2) + 15);
                                                                                r10 = r10 + (r2 - 1);
                                                                            } else {
                                                                                r7 = R(7);
                                                                                r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                if (!((r0 & r0) == 0)) {
                                                                                    ST8(r9, r8);
                                                                                    r9 = r9 + 1;
                                                                                } else {
                                                                                    ST32(sp - 40, 0);
                                                                                    r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                    r2 = LD32(sp - 40);
                                                                                    r9 = r9 + ((r2 + r2) + 15);
                                                                                    r10 = r10 + (r2 - 1);
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (!(c55)) {
                                                                                ST8(r9, r8);
                                                                                r9 = r9 + 1;
                                                                            } else {
                                                                                r7 = R(7);
                                                                                r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                r6 = 7;
                                                                                if ((r0 & r0) == 0) {
                                                                                    ST32(sp - 40, 0);
                                                                                    r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                    r2 = LD32(sp - 40);
                                                                                    r9 = r9 + ((r2 + r2) + 15);
                                                                                    r10 = r10 + (r2 - 1);
                                                                                } else {
                                                                                    r7 = R(7);
                                                                                    r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                    if (!((r0 & r0) == 0)) {
                                                                                        ST8(r9, r8);
                                                                                        r9 = r9 + 1;
                                                                                    } else {
                                                                                        ST32(sp - 40, 0);
                                                                                        r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                        r2 = LD32(sp - 40);
                                                                                        r9 = r9 + ((r2 + r2) + 15);
                                                                                        r10 = r10 + (r2 - 1);
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            r0 = r8;
                                                            c49 = r0 == 13;
                                                            r2 = r10;
                                                            c1074 = c49;
                                                            if (c49) {
                                                                r2 = r2 + 1;
                                                                r1 = LD8(r2);
                                                                c50 = (r1 & 255) == 10;
                                                                c1074 = c50;
                                                                if (c50) {
                                                                    r10 = r2;
                                                                    c1074 = 1;
                                                                }
                                                            }
                                                            r5 = 0x06018680;
                                                            r6 = R(6);
                                                            r7 = R(7);
                                                            r0 = GCALL6(0x06045264, r9, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                            r9 = r9 + r0;
                                                        }
                                                    }
                                                }
                                            } else {
                                                c41 = r0 == 10;
                                                if (r0 == 13) {
                                                    c43 = r0 == 13;
                                                    r2 = r10;
                                                    c1065 = c43;
                                                    if (c43) {
                                                        r2 = r2 + 1;
                                                        r1 = LD8(r2);
                                                        c44 = (r1 & 255) == 10;
                                                        c1065 = c44;
                                                        if (c44) {
                                                            r10 = r2;
                                                            c1065 = 1;
                                                        }
                                                    }
                                                    r5 = 0x06018678;
                                                    r6 = R(6);
                                                    r7 = R(7);
                                                    r0 = GCALL6(0x06045264, r9, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                    r9 = r9 + r0;
                                                } else {
                                                    c42 = (r13 & r13) == 0;
                                                    c1067 = c42;
                                                    if (!(c41)) {
                                                        r0 = r8;
                                                        if (c1067) {
                                                            c1077 = (r11 & r11) == 0;
                                                            r0 = r8;
                                                            if (c1077) {
                                                                ST8(r9, r8);
                                                                r9 = r9 + 1;
                                                            } else {
                                                                c53 = r0 == 72;
                                                                if (r0 == 104) {
                                                                    r7 = R(7);
                                                                    r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                    r6 = 7;
                                                                    if ((r0 & r0) == 0) {
                                                                        ST32(sp - 40, 0);
                                                                        r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                        r2 = LD32(sp - 40);
                                                                        r9 = r9 + ((r2 + r2) + 15);
                                                                        r10 = r10 + (r2 - 1);
                                                                    } else {
                                                                        r7 = R(7);
                                                                        r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                        if (!((r0 & r0) == 0)) {
                                                                            ST8(r9, r8);
                                                                            r9 = r9 + 1;
                                                                        } else {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = r9 + ((r2 + r2) + 15);
                                                                            r10 = r10 + (r2 - 1);
                                                                        }
                                                                    }
                                                                } else {
                                                                    c54 = r0 == 109;
                                                                    if (c53) {
                                                                        r7 = R(7);
                                                                        r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                        r6 = 7;
                                                                        if ((r0 & r0) == 0) {
                                                                            ST32(sp - 40, 0);
                                                                            r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                            r2 = LD32(sp - 40);
                                                                            r9 = r9 + ((r2 + r2) + 15);
                                                                            r10 = r10 + (r2 - 1);
                                                                        } else {
                                                                            r7 = R(7);
                                                                            r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                            if (!((r0 & r0) == 0)) {
                                                                                ST8(r9, r8);
                                                                                r9 = r9 + 1;
                                                                            } else {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = r9 + ((r2 + r2) + 15);
                                                                                r10 = r10 + (r2 - 1);
                                                                            }
                                                                        }
                                                                    } else {
                                                                        c55 = r0 == 77;
                                                                        if (c54) {
                                                                            r7 = R(7);
                                                                            r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                            r6 = 7;
                                                                            if ((r0 & r0) == 0) {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = r9 + ((r2 + r2) + 15);
                                                                                r10 = r10 + (r2 - 1);
                                                                            } else {
                                                                                r7 = R(7);
                                                                                r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                if (!((r0 & r0) == 0)) {
                                                                                    ST8(r9, r8);
                                                                                    r9 = r9 + 1;
                                                                                } else {
                                                                                    ST32(sp - 40, 0);
                                                                                    r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                    r2 = LD32(sp - 40);
                                                                                    r9 = r9 + ((r2 + r2) + 15);
                                                                                    r10 = r10 + (r2 - 1);
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (!(c55)) {
                                                                                ST8(r9, r8);
                                                                                r9 = r9 + 1;
                                                                            } else {
                                                                                r7 = R(7);
                                                                                r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                r6 = 7;
                                                                                if ((r0 & r0) == 0) {
                                                                                    ST32(sp - 40, 0);
                                                                                    r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                    r2 = LD32(sp - 40);
                                                                                    r9 = r9 + ((r2 + r2) + 15);
                                                                                    r10 = r10 + (r2 - 1);
                                                                                } else {
                                                                                    r7 = R(7);
                                                                                    r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                    if (!((r0 & r0) == 0)) {
                                                                                        ST8(r9, r8);
                                                                                        r9 = r9 + 1;
                                                                                    } else {
                                                                                        ST32(sp - 40, 0);
                                                                                        r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                        r2 = LD32(sp - 40);
                                                                                        r9 = r9 + ((r2 + r2) + 15);
                                                                                        r10 = r10 + (r2 - 1);
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                            c47 = r0 == 10;
                                                            if (r0 == 13) {
                                                                c49 = r0 == 13;
                                                                r2 = r10;
                                                                c1074 = c49;
                                                                if (c49) {
                                                                    r2 = r2 + 1;
                                                                    r1 = LD8(r2);
                                                                    c50 = (r1 & 255) == 10;
                                                                    c1074 = c50;
                                                                    if (c50) {
                                                                        r10 = r2;
                                                                        c1074 = 1;
                                                                    }
                                                                }
                                                                r5 = 0x06018680;
                                                                r6 = R(6);
                                                                r7 = R(7);
                                                                r0 = GCALL6(0x06045264, r9, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                r9 = r9 + r0;
                                                            } else {
                                                                c48 = (r11 & r11) == 0;
                                                                c1077 = c48;
                                                                if (!(c47)) {
                                                                    r0 = r8;
                                                                    if (c1077) {
                                                                        ST8(r9, r8);
                                                                        r9 = r9 + 1;
                                                                    } else {
                                                                        c53 = r0 == 72;
                                                                        if (r0 == 104) {
                                                                            r7 = R(7);
                                                                            r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                            r6 = 7;
                                                                            if ((r0 & r0) == 0) {
                                                                                ST32(sp - 40, 0);
                                                                                r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                r2 = LD32(sp - 40);
                                                                                r9 = r9 + ((r2 + r2) + 15);
                                                                                r10 = r10 + (r2 - 1);
                                                                            } else {
                                                                                r7 = R(7);
                                                                                r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                if (!((r0 & r0) == 0)) {
                                                                                    ST8(r9, r8);
                                                                                    r9 = r9 + 1;
                                                                                } else {
                                                                                    ST32(sp - 40, 0);
                                                                                    r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                    r2 = LD32(sp - 40);
                                                                                    r9 = r9 + ((r2 + r2) + 15);
                                                                                    r10 = r10 + (r2 - 1);
                                                                                }
                                                                            }
                                                                        } else {
                                                                            c54 = r0 == 109;
                                                                            if (c53) {
                                                                                r7 = R(7);
                                                                                r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                r6 = 7;
                                                                                if ((r0 & r0) == 0) {
                                                                                    ST32(sp - 40, 0);
                                                                                    r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                    r2 = LD32(sp - 40);
                                                                                    r9 = r9 + ((r2 + r2) + 15);
                                                                                    r10 = r10 + (r2 - 1);
                                                                                } else {
                                                                                    r7 = R(7);
                                                                                    r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                    if (!((r0 & r0) == 0)) {
                                                                                        ST8(r9, r8);
                                                                                        r9 = r9 + 1;
                                                                                    } else {
                                                                                        ST32(sp - 40, 0);
                                                                                        r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                        r2 = LD32(sp - 40);
                                                                                        r9 = r9 + ((r2 + r2) + 15);
                                                                                        r10 = r10 + (r2 - 1);
                                                                                    }
                                                                                }
                                                                            } else {
                                                                                c55 = r0 == 77;
                                                                                if (c54) {
                                                                                    r7 = R(7);
                                                                                    r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                    r6 = 7;
                                                                                    if ((r0 & r0) == 0) {
                                                                                        ST32(sp - 40, 0);
                                                                                        r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                        r2 = LD32(sp - 40);
                                                                                        r9 = r9 + ((r2 + r2) + 15);
                                                                                        r10 = r10 + (r2 - 1);
                                                                                    } else {
                                                                                        r7 = R(7);
                                                                                        r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                        if (!((r0 & r0) == 0)) {
                                                                                            ST8(r9, r8);
                                                                                            r9 = r9 + 1;
                                                                                        } else {
                                                                                            ST32(sp - 40, 0);
                                                                                            r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                            r2 = LD32(sp - 40);
                                                                                            r9 = r9 + ((r2 + r2) + 15);
                                                                                            r10 = r10 + (r2 - 1);
                                                                                        }
                                                                                    }
                                                                                } else {
                                                                                    if (!(c55)) {
                                                                                        ST8(r9, r8);
                                                                                        r9 = r9 + 1;
                                                                                    } else {
                                                                                        r7 = R(7);
                                                                                        r0 = GCALL6(r14, r10, 0x06018660, 7, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                        r6 = 7;
                                                                                        if ((r0 & r0) == 0) {
                                                                                            ST32(sp - 40, 0);
                                                                                            r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                            r2 = LD32(sp - 40);
                                                                                            r9 = r9 + ((r2 + r2) + 15);
                                                                                            r10 = r10 + (r2 - 1);
                                                                                        } else {
                                                                                            r7 = R(7);
                                                                                            r0 = GCALL6(r14, r10, 0x06018668, r6, r7, LD32((sp - 40)), LD32((sp - 36)));
                                                                                            if (!((r0 & r0) == 0)) {
                                                                                                ST8(r9, r8);
                                                                                                r9 = r9 + 1;
                                                                                            } else {
                                                                                                ST32(sp - 40, 0);
                                                                                                r0 = GCALL6(r12, r9, r10, 0, (sp - 40), LD32((sp - 40)), LD32((sp - 36)));
                                                                                                r2 = LD32(sp - 40);
                                                                                                r9 = r9 + ((r2 + r2) + 15);
                                                                                                r10 = r10 + (r2 - 1);
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    r0 = r8;
                                                                    c49 = r0 == 13;
                                                                    r2 = r10;
                                                                    c1074 = c49;
                                                                    if (c49) {
                                                                        r2 = r2 + 1;
                                                                        r1 = LD8(r2);
                                                                        c50 = (r1 & 255) == 10;
                                                                        c1074 = c50;
                                                                        if (c50) {
                                                                            r10 = r2;
                                                                            c1074 = 1;
                                                                        }
                                                                    }
                                                                    r5 = 0x06018680;
                                                                    r6 = R(6);
                                                                    r7 = R(7);
                                                                    r0 = GCALL6(0x06045264, r9, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                                    r9 = r9 + r0;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        r0 = r8;
                                                        c43 = r0 == 13;
                                                        r2 = r10;
                                                        c1065 = c43;
                                                        if (c43) {
                                                            r2 = r2 + 1;
                                                            r1 = LD8(r2);
                                                            c44 = (r1 & 255) == 10;
                                                            c1065 = c44;
                                                            if (c44) {
                                                                r10 = r2;
                                                                c1065 = 1;
                                                            }
                                                        }
                                                        r5 = 0x06018678;
                                                        r6 = R(6);
                                                        r7 = R(7);
                                                        r0 = GCALL6(0x06045264, r9, r5, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                                        r9 = r9 + r0;
                                                    }
                                                }
                                            }
                                        } else {
                                            r7 = R(7);
                                            r0 = GCALL6(0x06018550, r9, r8, 0, 0, LD32((sp - 40)), LD32((sp - 36)));
                                            r9 = r0;
                                        }
                                    }
                                }
                            }
                        }
                        r10 = r10 + 1;
                        r1 = LD8(r10);
                        r8 = r1 & 255;
                        r0 = r8;
                        if ((r8 & r8) == 0) {
                            break;
                        }
                        POLL();
                    }
                    r1 = 0;
                }
                ST8(r9, r1);
                r0 = 1;
            } else {
                r0 = 0;
            }
        } else {
            r0 = 1;
        }
    } else {
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601D4D8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c3, c4, c6, c10, c12, c14, c18, c1019, c1020, c1021, c1027, c1029, c1045;
    FRAME(sp, 64);

    r10 = r4;
    ST32(sp - 48, 0);
    ST32(sp - 40, 0);
    r14 = LD32(r10 + 0x10D4);
    if ((r14 & r14) == 0) {
        r8 = LD32(r10 + 56);
        r0 = GCALL1(0x0607507C, (r10 + 0x1B0));
        r11 = r0;
        ST16(((r8 + r8) + r10) + 0xEB0, r11);
    } else {
        r0 = GCALL1(0x060455FC, (r4 + 0x1B0));
        r7 = r0;
        r1 = LD32(r10 + 56);
        r11 = r7;
        ST16(((r1 + r1) + r10) + 0xEB0, r11);
    }
    r0 = r10;
    r1 = LD32(r0 + 0x10B4);
    ST32(sp - 64, r1);
    r1 = LD32(r0 + 0x10B8);
    ST32(sp - 60, r1);
    r1 = LD32((r10 + 88));
    r4 = LD32(sp - 64);
    ST32(sp - 56, r1);
    r0 = GCALL7(0x0601CC78, r4, 128, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)));
    r1 = 0x1B0;
    ST32(sp - 52, (r10 + 0x1B0));
    r3 = LD32(sp - 52);
    ST32(sp - 44, r3);
    if ((r14 & r14) == 0) {
        r1 = LD8(r10 + r1);
        ST32(sp - 48, (r1 & 255));
        r0 = LD32(sp - 48);
        r1 = LD8(r0 + 0x06075135);
        r1 = r1 & 8;
    } else {
        r1 = LD16(r10 + r1);
        ST32(sp - 40, (r1 & 0xFFFF));
        r4 = LD32(sp - 40);
        r0 = GCALL8(0x060455C4, r4, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
        r1 = r0;
    }
    r7 = 1;
    c3 = (r1 & r1) == 0;
    if (r11 > 1) {
        r1 = LD32(r10 + 48);
        c4 = r1 > 0;
        r1 = r10;
        if (c4) {
            r3 = LD32((r1 + 68));
            r1 = LD32((r10 + 64));
            r2 = r3 - r1;
            r1 = LD32((r10 + 104));
            c6 = r1 > r7;
            if (r1 == 1) {
                r1 = LD32(r10 + 52);
                r2 = (r2 - r1) + ((int)((unsigned)(r2 - r1) >> 31));
                r1 = LD32(r10 + 8);
                r2 = r2 >> 1;
                r1 = r1 + r2;
                c10 = r1 >= 0;
                ST32(r10 + 8, r1);
                c1019 = c10;
                if (!(c10)) {
                    ST32(r10 + 8, 0);
                    c1019 = 0;
                }
                r9 = 0;
                c1020 = c1019;
                r13 = r10;
                c1021 = c1020;
            } else {
                r9 = 0;
                c1020 = c6;
                if (!(c6)) {
                    r13 = r10;
                    c1021 = c1020;
                } else {
                    r13 = r10;
                    if (r1 == 2) {
                        r1 = LD32(r10 + 52);
                        r2 = r2 - r1;
                        r1 = LD32(r10 + 8);
                        r1 = r1 + r2;
                        c10 = r1 >= 0;
                        ST32(r10 + 8, r1);
                        c1019 = c10;
                        if (!(c10)) {
                            ST32(r10 + 8, 0);
                            c1019 = 0;
                        }
                        r9 = 0;
                        c1020 = c1019;
                        r13 = r10;
                        c1021 = c1020;
                    } else {
                        c1021 = 0;
                    }
                }
            }
            r13 = r13 + 88;
            ST32(sp - 36, 0);
            r12 = r10;
            r11 = r10;
            while (1) {
                r0 = r11;
                if ((r14 & r14) == 0) {
                    r1 = LD16(r0 + 0xEB0);
                    r0 = LD32(sp - 52);
                    r1 = LD8(r0 + r1);
                    ST32(sp - 48, (r1 & 255));
                } else {
                    r1 = LD16(r0 + 0xEB0);
                    r0 = LD32(sp - 44);
                    r1 = LD16(r0 + (r1 + r1));
                    ST32(sp - 40, (r1 & 0xFFFF));
                }
                c12 = (r14 & r14) == 0;
                r8 = 1;
                c1027 = c12;
                if (c12) {
                    r7 = 0;
                    if (!(c1027)) {
                        r8 = 0;
                    } else {
                        c1029 = (r14 & r14) == 0;
                        r3 = 27;
                        if (c1029) {
                            r2 = LD32(sp - 48);
                        } else {
                            r3 = LD8((r3 + (sp - 64)));
                            r2 = r3 & 255;
                        }
                        r2 = r2 - 1;
                        r1 = r2;
                        if ((unsigned)r2 > (unsigned)4) {
                            r8 = 0;
                            r7 = 0;
                        } else {
                            r1 = LD16(0x0601D67C + (r1 + r1));
                            switch (r1) {
                            case 10:
                                r0 = 0x0601D1F4;
                                r5 = r9;
                                r4 = r10;
                                break;
                            case 18:
                                r0 = 0x0601D390;
                                r5 = r9;
                                r4 = r10;
                                break;
                            case 26:
                                r0 = 0x0601D3B8;
                                r5 = r9;
                                r4 = r10;
                                break;
                            case 34:
                                r0 = 0x0601D3E0;
                                r5 = r9;
                                r4 = r10;
                                break;
                            case 42:
                                r5 = LD16(0x2B0 + r12);
                                r4 = r10;
                                r0 = 0x0601D898;
                                break;
                            }
                            r0 = GCALL8(r0, r4, r5, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r7 = r0;
                        }
                    }
                } else {
                    r2 = LD32(sp - 40);
                    c14 = (r14 & r14) == 0;
                    c1029 = c14;
                    c1027 = c14;
                    if (((int)((unsigned)r2 >> 8)) == 128) {
                        r3 = 27;
                        if (c1029) {
                            r2 = LD32(sp - 48);
                        } else {
                            r3 = LD8((r3 + (sp - 64)));
                            r2 = r3 & 255;
                        }
                        r2 = r2 - 1;
                        r1 = r2;
                        if ((unsigned)r2 > (unsigned)4) {
                            r8 = 0;
                            r7 = 0;
                        } else {
                            r1 = LD16(0x0601D67C + (r1 + r1));
                            switch (r1) {
                            case 10:
                                r0 = 0x0601D1F4;
                                r5 = r9;
                                r4 = r10;
                                break;
                            case 18:
                                r0 = 0x0601D390;
                                r5 = r9;
                                r4 = r10;
                                break;
                            case 26:
                                r0 = 0x0601D3B8;
                                r5 = r9;
                                r4 = r10;
                                break;
                            case 34:
                                r0 = 0x0601D3E0;
                                r5 = r9;
                                r4 = r10;
                                break;
                            case 42:
                                r5 = LD16(0x2B0 + r12);
                                r4 = r10;
                                r0 = 0x0601D898;
                                break;
                            }
                            r0 = GCALL8(r0, r4, r5, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                            r7 = r0;
                        }
                    } else {
                        r7 = 0;
                        if (!(c1027)) {
                            r8 = 0;
                        } else {
                            c1029 = (r14 & r14) == 0;
                            r3 = 27;
                            if (c1029) {
                                r2 = LD32(sp - 48);
                            } else {
                                r3 = LD8((r3 + (sp - 64)));
                                r2 = r3 & 255;
                            }
                            r2 = r2 - 1;
                            r1 = r2;
                            if ((unsigned)r2 > (unsigned)4) {
                                r8 = 0;
                                r7 = 0;
                            } else {
                                r1 = LD16(0x0601D67C + (r1 + r1));
                                switch (r1) {
                                case 10:
                                    r0 = 0x0601D1F4;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 18:
                                    r0 = 0x0601D390;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 26:
                                    r0 = 0x0601D3B8;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 34:
                                    r0 = 0x0601D3E0;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 42:
                                    r5 = LD16(0x2B0 + r12);
                                    r4 = r10;
                                    r0 = 0x0601D898;
                                    break;
                                }
                                r0 = GCALL8(r0, r4, r5, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r7 = r0;
                            }
                        }
                    }
                }
                r0 = LD32(sp - 36);
                if ((r8 & r8) == 0) {
                    r4 = LD32(r12 + 0x2B4);
                    ST32(0x10B4 + r10, r4);
                    r0 = GCALL8(0x0601CC78, r4, 128, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                    r8 = r0;
                    r0 = LD32(sp - 36);
                    ST32(0x10B8 + r10, ((0x2B0 + r0) + r10));
                    r1 = LD32(r12 + 0x2B8);
                    ST32(r13, r1);
                    r0 = r11;
                    r7 = LD16(r0 + 0xEB2);
                    r6 = LD16(r0 + 0xEB0);
                    r1 = LD32(0x10B4 + r10);
                    ST32((sp - 68), r1);
                    r1 = LD32(0x10B8 + r10);
                    ST32((sp - 72), r1);
                    r1 = LD32(r10 + 32);
                    ST32((sp - 76), r1);
                    r1 = LD32(r10 + 12);
                    ST32((sp - 80), r1);
                    r1 = LD32(r10 + 8);
                    ST32((sp - 84), r1);
                    r5 = LD32(sp - 52);
                    r0 = GCALL8(0x06014880, r10, r5, r6, (r7 - 1), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
                    r7 = r0;
                    r2 = LD32(r13);
                    c18 = (r2 & r2) == 0;
                    c1045 = c18;
                    if (!(c18)) {
                        r1 = LD32(r10 + 8);
                        ST16((r2 + 4), r1);
                        r2 = LD32(r10 + 12);
                        r1 = LD32(r10 + 32);
                        r2 = r2 + r1;
                        r1 = LD32(r8 + 32);
                        r3 = LD32(r13);
                        ST32(r3 + 16, (r2 - r1));
                        r1 = LD32(r13);
                        ST16((r1 + 6), r7);
                        r1 = LD32(r8 + 36);
                        r2 = LD32(r13);
                        ST32(r2 + 20, (r1 - 1));
                        c1045 = 0;
                    }
                    r0 = LD32(sp - 36);
                }
                r12 = r12 + 12;
                ST32(sp - 36, (r0 + 12));
                r1 = LD32(r10 + 8);
                ST32(r10 + 8, (r1 + r7));
                r1 = LD32(r10 + 56);
                r9 = r9 + 1;
                r11 = r11 + 2;
                if (r9 >= r1) {
                    break;
                }
                POLL();
            }
            r1 = LD32((r10 + 64));
            r7 = LD32(r10 + 36);
            r2 = LD32(r10 + 32);
            ST32(r10 + 8, r1);
            if (!(r7 >= r2)) {
                r1 = LD32(r10 + 12);
                ST32(r10 + 12, (r1 + r2));
            } else {
                r1 = LD32(r10 + 12);
                ST32(r10 + 12, (r1 + r7));
            }
        } else {
            r1 = LD32((r1 + 64));
            ST32(r10 + 8, r1);
        }
    } else {
        r1 = r10;
        if (c3) {
            r1 = LD32(r10 + 48);
            c4 = r1 > 0;
            r1 = r10;
            if (c4) {
                r3 = LD32((r1 + 68));
                r1 = LD32((r10 + 64));
                r2 = r3 - r1;
                r1 = LD32((r10 + 104));
                c6 = r1 > r7;
                if (r1 == 1) {
                    r1 = LD32(r10 + 52);
                    r2 = (r2 - r1) + ((int)((unsigned)(r2 - r1) >> 31));
                    r1 = LD32(r10 + 8);
                    r2 = r2 >> 1;
                    r1 = r1 + r2;
                    c10 = r1 >= 0;
                    ST32(r10 + 8, r1);
                    c1019 = c10;
                    if (!(c10)) {
                        ST32(r10 + 8, 0);
                        c1019 = 0;
                    }
                    r9 = 0;
                    c1020 = c1019;
                    r13 = r10;
                    c1021 = c1020;
                } else {
                    r9 = 0;
                    c1020 = c6;
                    if (!(c6)) {
                        r13 = r10;
                        c1021 = c1020;
                    } else {
                        r13 = r10;
                        if (r1 == 2) {
                            r1 = LD32(r10 + 52);
                            r2 = r2 - r1;
                            r1 = LD32(r10 + 8);
                            r1 = r1 + r2;
                            c10 = r1 >= 0;
                            ST32(r10 + 8, r1);
                            c1019 = c10;
                            if (!(c10)) {
                                ST32(r10 + 8, 0);
                                c1019 = 0;
                            }
                            r9 = 0;
                            c1020 = c1019;
                            r13 = r10;
                            c1021 = c1020;
                        } else {
                            c1021 = 0;
                        }
                    }
                }
                r13 = r13 + 88;
                ST32(sp - 36, 0);
                r12 = r10;
                r11 = r10;
                while (1) {
                    r0 = r11;
                    if ((r14 & r14) == 0) {
                        r1 = LD16(r0 + 0xEB0);
                        r0 = LD32(sp - 52);
                        r1 = LD8(r0 + r1);
                        ST32(sp - 48, (r1 & 255));
                    } else {
                        r1 = LD16(r0 + 0xEB0);
                        r0 = LD32(sp - 44);
                        r1 = LD16(r0 + (r1 + r1));
                        ST32(sp - 40, (r1 & 0xFFFF));
                    }
                    c12 = (r14 & r14) == 0;
                    r8 = 1;
                    c1027 = c12;
                    if (c12) {
                        r7 = 0;
                        if (!(c1027)) {
                            r8 = 0;
                        } else {
                            c1029 = (r14 & r14) == 0;
                            r3 = 27;
                            if (c1029) {
                                r2 = LD32(sp - 48);
                            } else {
                                r3 = LD8((r3 + (sp - 64)));
                                r2 = r3 & 255;
                            }
                            r2 = r2 - 1;
                            r1 = r2;
                            if ((unsigned)r2 > (unsigned)4) {
                                r8 = 0;
                                r7 = 0;
                            } else {
                                r1 = LD16(0x0601D67C + (r1 + r1));
                                switch (r1) {
                                case 10:
                                    r0 = 0x0601D1F4;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 18:
                                    r0 = 0x0601D390;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 26:
                                    r0 = 0x0601D3B8;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 34:
                                    r0 = 0x0601D3E0;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 42:
                                    r5 = LD16(0x2B0 + r12);
                                    r4 = r10;
                                    r0 = 0x0601D898;
                                    break;
                                }
                                r0 = GCALL8(r0, r4, r5, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r7 = r0;
                            }
                        }
                    } else {
                        r2 = LD32(sp - 40);
                        c14 = (r14 & r14) == 0;
                        c1029 = c14;
                        c1027 = c14;
                        if (((int)((unsigned)r2 >> 8)) == 128) {
                            r3 = 27;
                            if (c1029) {
                                r2 = LD32(sp - 48);
                            } else {
                                r3 = LD8((r3 + (sp - 64)));
                                r2 = r3 & 255;
                            }
                            r2 = r2 - 1;
                            r1 = r2;
                            if ((unsigned)r2 > (unsigned)4) {
                                r8 = 0;
                                r7 = 0;
                            } else {
                                r1 = LD16(0x0601D67C + (r1 + r1));
                                switch (r1) {
                                case 10:
                                    r0 = 0x0601D1F4;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 18:
                                    r0 = 0x0601D390;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 26:
                                    r0 = 0x0601D3B8;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 34:
                                    r0 = 0x0601D3E0;
                                    r5 = r9;
                                    r4 = r10;
                                    break;
                                case 42:
                                    r5 = LD16(0x2B0 + r12);
                                    r4 = r10;
                                    r0 = 0x0601D898;
                                    break;
                                }
                                r0 = GCALL8(r0, r4, r5, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                r7 = r0;
                            }
                        } else {
                            r7 = 0;
                            if (!(c1027)) {
                                r8 = 0;
                            } else {
                                c1029 = (r14 & r14) == 0;
                                r3 = 27;
                                if (c1029) {
                                    r2 = LD32(sp - 48);
                                } else {
                                    r3 = LD8((r3 + (sp - 64)));
                                    r2 = r3 & 255;
                                }
                                r2 = r2 - 1;
                                r1 = r2;
                                if ((unsigned)r2 > (unsigned)4) {
                                    r8 = 0;
                                    r7 = 0;
                                } else {
                                    r1 = LD16(0x0601D67C + (r1 + r1));
                                    switch (r1) {
                                    case 10:
                                        r0 = 0x0601D1F4;
                                        r5 = r9;
                                        r4 = r10;
                                        break;
                                    case 18:
                                        r0 = 0x0601D390;
                                        r5 = r9;
                                        r4 = r10;
                                        break;
                                    case 26:
                                        r0 = 0x0601D3B8;
                                        r5 = r9;
                                        r4 = r10;
                                        break;
                                    case 34:
                                        r0 = 0x0601D3E0;
                                        r5 = r9;
                                        r4 = r10;
                                        break;
                                    case 42:
                                        r5 = LD16(0x2B0 + r12);
                                        r4 = r10;
                                        r0 = 0x0601D898;
                                        break;
                                    }
                                    r0 = GCALL8(r0, r4, r5, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                                    r7 = r0;
                                }
                            }
                        }
                    }
                    r0 = LD32(sp - 36);
                    if ((r8 & r8) == 0) {
                        r4 = LD32(r12 + 0x2B4);
                        ST32(0x10B4 + r10, r4);
                        r0 = GCALL8(0x0601CC78, r4, 128, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
                        r8 = r0;
                        r0 = LD32(sp - 36);
                        ST32(0x10B8 + r10, ((0x2B0 + r0) + r10));
                        r1 = LD32(r12 + 0x2B8);
                        ST32(r13, r1);
                        r0 = r11;
                        r7 = LD16(r0 + 0xEB2);
                        r6 = LD16(r0 + 0xEB0);
                        r1 = LD32(0x10B4 + r10);
                        ST32((sp - 68), r1);
                        r1 = LD32(0x10B8 + r10);
                        ST32((sp - 72), r1);
                        r1 = LD32(r10 + 32);
                        ST32((sp - 76), r1);
                        r1 = LD32(r10 + 12);
                        ST32((sp - 80), r1);
                        r1 = LD32(r10 + 8);
                        ST32((sp - 84), r1);
                        r5 = LD32(sp - 52);
                        r0 = GCALL8(0x06014880, r10, r5, r6, (r7 - 1), LD32((sp - 84)), LD32((sp - 80)), LD32((sp - 76)), LD32((sp - 72)));
                        r7 = r0;
                        r2 = LD32(r13);
                        c18 = (r2 & r2) == 0;
                        c1045 = c18;
                        if (!(c18)) {
                            r1 = LD32(r10 + 8);
                            ST16((r2 + 4), r1);
                            r2 = LD32(r10 + 12);
                            r1 = LD32(r10 + 32);
                            r2 = r2 + r1;
                            r1 = LD32(r8 + 32);
                            r3 = LD32(r13);
                            ST32(r3 + 16, (r2 - r1));
                            r1 = LD32(r13);
                            ST16((r1 + 6), r7);
                            r1 = LD32(r8 + 36);
                            r2 = LD32(r13);
                            ST32(r2 + 20, (r1 - 1));
                            c1045 = 0;
                        }
                        r0 = LD32(sp - 36);
                    }
                    r12 = r12 + 12;
                    ST32(sp - 36, (r0 + 12));
                    r1 = LD32(r10 + 8);
                    ST32(r10 + 8, (r1 + r7));
                    r1 = LD32(r10 + 56);
                    r9 = r9 + 1;
                    r11 = r11 + 2;
                    if (r9 >= r1) {
                        break;
                    }
                    POLL();
                }
                r1 = LD32((r10 + 64));
                r7 = LD32(r10 + 36);
                r2 = LD32(r10 + 32);
                ST32(r10 + 8, r1);
                if (!(r7 >= r2)) {
                    r1 = LD32(r10 + 12);
                    ST32(r10 + 12, (r1 + r2));
                } else {
                    r1 = LD32(r10 + 12);
                    ST32(r10 + 12, (r1 + r7));
                }
            } else {
                r1 = LD32((r1 + 64));
                ST32(r10 + 8, r1);
            }
        } else {
            r1 = LD32((r1 + 64));
            ST32(r10 + 8, r1);
        }
    }
    r0 = r10;
    r3 = LD32(sp - 56);
    ST32((r10 + 88), r3);
    ST8(r0 + 0x1B0, 0);
    ST32(r10 + 48, 0);
    ST32(r10 + 52, 0);
    ST32(r10 + 56, 0);
    r3 = LD32(sp - 64);
    ST32(r0 + 0x10B4, r3);
    r3 = LD32(sp - 60);
    ST32(r0 + 0x10B8, r3);
    r4 = LD32(r0 + 0x10B4);
    r0 = GCALL8(0x0601CC78, r4, 128, 0, r7, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
    r1 = LD32(r0 + 32);
    ST32(r10 + 32, r1);
    ST32(r10 + 36, r1);
    r5 = R(5);
    r6 = R(6);
    r7 = R(7);
    r0 = GCALL8(0x0601D408, r10, 0, 0, 0, LD32((sp - 64)), LD32((sp - 60)), LD32((sp - 56)), LD32((sp - 52)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601E504(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 1088);

    ST32(0x400 + (sp - 1088), r4);
    ST32((0x404 + (sp - 1088)), r5);
    ST32((0x408 + (sp - 1088)), r6);
    ST32((0x40C + (sp - 1088)), r7);
    r7 = 0;
    r14 = 1;
    ST32(0x410 + (sp - 1088), 0);
    while (1) {
        r0 = LD32((0x410 + (sp - 1088)));
        r13 = LD32((0x404 + (sp - 1088)));
        r1 = LD32(r0 + r13);
        r6 = ((int)((unsigned)r1 >> 16)) & 255;
        r4 = ((int)((unsigned)r1 >> 8)) & 255;
        r10 = r1 & 255;
        r8 = r6 + 15;
        r5 = r4 + 15;
        r9 = r10 + 15;
        if ((unsigned)r8 > (unsigned)255) {
            r8 = 255;
        }
        if ((unsigned)r5 > (unsigned)255) {
            r5 = 255;
        }
        r1 = r6;
        if ((unsigned)r9 > (unsigned)255) {
            r9 = 255;
        }
        ST32((0x418 + (sp - 1088)), (3 & ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1))));
        ST32((0x41C + (sp - 1088)), (3 & ((int)((unsigned)((int)((unsigned)r4 >> 2)) >> 1))));
        ST32((0x420 + (sp - 1088)), (3 & ((int)((unsigned)((int)((unsigned)r10 >> 2)) >> 2))));
        r1 = LD32((0x418 + (sp - 1088)));
        r2 = r6;
        if (!((unsigned)(r1 - 1) > (unsigned)r14)) {
            r2 = r8;
        }
        r1 = LD32((0x41C + (sp - 1088)));
        ST32((0x414 + (sp - 1088)), r4);
        if (!((unsigned)(r1 - 1) > (unsigned)r14)) {
            ST32(0x414 + (sp - 1088), r5);
        }
        r1 = LD32((0x420 + (sp - 1088)));
        r3 = r10;
        if (!((unsigned)(r1 - 1) > (unsigned)r14)) {
            r3 = r9;
        }
        r1 = 224 & r2;
        r2 = LD32((0x414 + (sp - 1088)));
        r3 = (((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)) & 3) | (r1 | (((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 1)) & 28));
        if ((r3 & r3) == 0) {
            r3 = 4;
        }
        ST8((sp - 1088) + r7, r3);
        r0 = LD32(0x418 + (sp - 1088));
        r2 = r6;
        if (r0 == 3) {
            r2 = r8;
        }
        r0 = LD32(0x41C + (sp - 1088));
        ST32((0x414 + (sp - 1088)), r4);
        if (r0 == 3) {
            ST32((0x414 + (sp - 1088)), r5);
        }
        r0 = LD32(0x420 + (sp - 1088));
        r3 = r10;
        if (r0 == 3) {
            r3 = r9;
        }
        r1 = 224 & r2;
        r2 = LD32((0x414 + (sp - 1088)));
        r3 = (((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)) & 3) | (r1 | (((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 1)) & 28));
        if ((r3 & r3) == 0) {
            r3 = 4;
        }
        ST8((0x100 + (sp - 1088)) + r7, r3);
        r11 = 0x418;
        ST8((0x200 + (sp - 1088)) + r7, r3);
        r11 = LD32((r11 + (sp - 1088)));
        r2 = r6;
        if ((unsigned)r11 > (unsigned)r14) {
            r2 = r8;
        }
        r12 = LD32((0x41C + (sp - 1088)));
        ST32((0x414 + (sp - 1088)), r4);
        if ((unsigned)r12 > (unsigned)r14) {
            ST32(0x414 + (sp - 1088), r5);
        }
        r11 = LD32((0x420 + (sp - 1088)));
        r3 = r10;
        if ((unsigned)r11 > (unsigned)r14) {
            r3 = r9;
        }
        r1 = 224 & r2;
        r2 = LD32((0x414 + (sp - 1088)));
        r3 = (r1 | (((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 1)) & 28)) | (((int)((unsigned)((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 2)) >> 2)) & 3);
        if ((r3 & r3) == 0) {
            r3 = 4;
        }
        ST8((0x300 + (sp - 1088)) + r7, r3);
        r11 = LD32((0x44C + (sp - 1088)));
        if (r7 == r11) {
            r3 = 0;
            r8 = 3;
            r2 = sp - 1088;
            r11 = 0;
            do {
                ST8(r2 + r7, r11);
                r3 = r3 + 1;
                r2 = r2 + 0x100;
            } while (AGAIN(!(r3 > r8)));
        }
        r12 = 0x410 + (sp - 1088);
        r13 = LD32(r12);
        r7 = r7 + 1;
        ST32(r12, (r13 + 4));
        if (r7 > 255) {
            break;
        }
        POLL();
    }
    r11 = LD32(0x40C + (sp - 1088));
    r0 = LD32(0x448 + (sp - 1088));
    r7 = LD32((0x40C + (sp - 1088)));
    r8 = LD32((0x400 + (sp - 1088)));
    r8 = r8 + (r11 * r0);
    r1 = LD32((0x444 + (sp - 1088)));
    r1 = r1 + r7;
    r9 = r1;
    if (!(r7 >= r1)) {
        do {
            r0 = 0x408 + (sp - 1088);
            r3 = LD32(r0);
            r1 = LD32((0x440 + (sp - 1088)));
            r1 = r1 + r3;
            r4 = 2 & r7;
            if (!(r3 >= r1)) {
                r6 = r1;
                r5 = r3 + r8;
                do {
                    r1 = (((1 & r3) | r4) << 8) + (sp - 1088);
                    r2 = LD8(r5);
                    r3 = r3 + 1;
                    r0 = r2 & 255;
                    r1 = LD8(r0 + r1);
                    ST8(r5, r1);
                    r5 = r5 + 1;
                } while (AGAIN(!(r3 >= r6)));
            }
            r12 = LD32((0x448 + (sp - 1088)));
            r7 = r7 + 1;
            r8 = r8 + r12;
        } while (AGAIN(!(r7 >= r9)));
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601F210(int r4, int r5)
{
    int r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, r13, r14, c1, c5;
    long long m0;
    int v36;
    int v40;

    r11 = r4;
    r12 = r5;
    v40 = 0;
    r14 = 0;
    v36 = 0;
    r13 = 0;
    while (1) {
        r2 = v36;
        if ((r12 & r12) == 0) {
            break;
        } else {
            r0 = GCALL6(0x06028410, 1, 0, 0, 0, v40, v36);
            c1 = r11 * r12;
            m0 = (unsigned)c1;
            r9 = r0;
            r1 = c1;
            r4 = r9;
            if (!((unsigned)r9 > (unsigned)r1)) {
                r0 = GCALL6(0x060745A0, r4, r11, 0, 0, v40, v36);
                m0 = (unsigned)(r0 * r11);
            }
            r9 = (int)m0;
            c5 = (r13 & r13) == 0;
            if ((unsigned)r9 >= (unsigned)r11) {
                r0 = GCALL6(0x060279E0, 1, r9, -1, 1, v40, v36);
                r10 = r0;
                if ((r10 & r10) == 0) {
                    POLL();
                    continue;
                } else {
                    r13 = 0;
                    r0 = GCALL6(0x060279E0, 0, 12, -1, 1, v40, v36);
                    r8 = r0;
                    r6 = 12;
                    if ((r8 & r8) == 0) {
                        r5 = R(5);
                        r7 = R(7);
                        r0 = GCALL6(0x06027F48, r10, r5, r6, 0, v40, v36);
                        v36 = 1;
                        POLL();
                        r2 = v36;
                        break;
                    } else {
                        r0 = GCALL6(0x0604B3F0, r8, 0, r6, 0, v40, v36);
                        ST32(r8 + 4, r10);
                        r0 = GCALL6(0x060745A0, r9, r11, 0, 0, v40, v36);
                        ST32(r8 + 8, r0);
                        ST32(r8, r13);
                        if (!((r14 & r14) == 0)) {
                            ST32(r14, r8);
                        } else {
                            v40 = r8;
                        }
                        r14 = r8;
                        r1 = LD32(r14 + 8);
                        r12 = r12 - r1;
                        POLL();
                        continue;
                    }
                }
            } else {
                r9 = r1;
                if (!(c5)) {
                    v36 = 1;
                    POLL();
                    r2 = v36;
                    break;
                } else {
                    r13 = 1;
                    r0 = GCALL6(0x060279E0, 1, r9, -1, 1, v40, v36);
                    r10 = r0;
                    if ((r10 & r10) == 0) {
                        POLL();
                        continue;
                    } else {
                        r13 = 0;
                        r0 = GCALL6(0x060279E0, 0, 12, -1, 1, v40, v36);
                        r8 = r0;
                        r6 = 12;
                        if ((r8 & r8) == 0) {
                            r5 = R(5);
                            r7 = R(7);
                            r0 = GCALL6(0x06027F48, r10, r5, r6, 0, v40, v36);
                            v36 = 1;
                            POLL();
                            r2 = v36;
                            break;
                        } else {
                            r0 = GCALL6(0x0604B3F0, r8, 0, r6, 0, v40, v36);
                            ST32(r8 + 4, r10);
                            r0 = GCALL6(0x060745A0, r9, r11, 0, 0, v40, v36);
                            ST32(r8 + 8, r0);
                            ST32(r8, r13);
                            if (!((r14 & r14) == 0)) {
                                ST32(r14, r8);
                            } else {
                                v40 = r8;
                            }
                            r14 = r8;
                            r1 = LD32(r14 + 8);
                            r12 = r12 - r1;
                        }
                    }
                }
            }
        }
        POLL();
    }
    r0 = v40;
    if (!((r2 & r2) == 0)) {
        r5 = R(5);
        r6 = R(6);
        r7 = R(7);
        r0 = GCALL6(0x0601F1D0, v40, 0, 0, 0, v40, v36);
        r0 = 0;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0601FBC4(int r4, int r5, int r6)
{
    int r0, r1, r2, r3, r7, r8, r9, r10, r11, r12, r13, r14, c2, c22, c1002;
    int v32;
    int v36;
    int v40;
    int v44;
    int v48;

    v48 = r4;
    v44 = r5;
    if (!((r6 & r6) == 0)) {
        r14 = v44;
        r7 = 0;
        v40 = v48;
        while (1) {
            r1 = LD8((v40 + 56));
            r4 = r1 & 255;
            r6 = r4 + 15;
            r1 = LD8((v40 + 57));
            r8 = r1 & 255;
            r1 = LD8((v40 + 58));
            r5 = r8 + 15;
            r10 = r1 & 255;
            r9 = r10 + 15;
            if ((unsigned)r6 > (unsigned)255) {
                r6 = 255;
            }
            if ((unsigned)r5 > (unsigned)255) {
                r5 = 255;
            }
            r1 = r4;
            if ((unsigned)r9 > (unsigned)255) {
                r9 = 255;
            }
            r11 = 3 & ((int)((unsigned)((int)((unsigned)r1 >> 2)) >> 1));
            v32 = r11;
            r12 = 3 & ((int)((unsigned)((int)((unsigned)r8 >> 2)) >> 1));
            r13 = 3 & ((int)((unsigned)((int)((unsigned)r10 >> 2)) >> 2));
            v36 = r4;
            if (!((unsigned)(r11 - 1) > (unsigned)1)) {
                v36 = r6;
            }
            r3 = r8;
            if (!((unsigned)(r12 - 1) > (unsigned)1)) {
                r3 = r5;
            }
            r2 = r10;
            if (!((unsigned)(r13 - 1) > (unsigned)1)) {
                r2 = r9;
            }
            r1 = ((224 & v36) | (((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 1)) & 28)) | (((int)((unsigned)((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 2)) >> 2)) & 3);
            if ((r1 & r1) == 0) {
                r1 = 4;
            }
            ST8(r14, r1);
            v36 = r4;
            if (v32 == 3) {
                v36 = r6;
            }
            r3 = r8;
            if (r12 == 3) {
                r3 = r5;
            }
            r2 = r10;
            if (r13 == 3) {
                r2 = r9;
            }
            r1 = ((224 & v36) | (((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 1)) & 28)) | (((int)((unsigned)((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 2)) >> 2)) & 3);
            if ((r1 & r1) == 0) {
                r1 = 4;
            }
            r0 = r14;
            ST8(r0 + 0x100, r1);
            ST8(r0 + 0x200, r1);
            v36 = r4;
            if ((unsigned)v32 > (unsigned)1) {
                v36 = r6;
            }
            r3 = r8;
            if ((unsigned)r12 > (unsigned)1) {
                r3 = r5;
            }
            r2 = r10;
            if ((unsigned)r13 > (unsigned)1) {
                r2 = r9;
            }
            r1 = ((224 & v36) | (((int)((unsigned)((int)((unsigned)r3 >> 2)) >> 1)) & 28)) | (((int)((unsigned)((int)((unsigned)((int)((unsigned)r2 >> 2)) >> 2)) >> 2)) & 3);
            c22 = (r1 & r1) == 0;
            if (c22) {
                r1 = 4;
            }
            ST8(r14 + 0x300, r1);
            r1 = LD16(v48 + 0x346);
            if (r7 == r1) {
                r6 = 0;
                r3 = 3;
                r2 = v44;
                r11 = 0;
                do {
                    ST8(r2 + r7, r11);
                    r6 = r6 + 1;
                    r2 = r2 + 0x100;
                } while (AGAIN(!(r6 > r3)));
            }
            r14 = r14 + 1;
            r7 = r7 + 1;
            r0 = v40 + 3;
            v40 = r0;
            if (r7 > 255) {
                break;
            }
            POLL();
        }
    } else {
        r7 = 0;
        r2 = 255;
        r3 = 3;
        r5 = v44;
        c1002 = 1;
        do {
            r6 = 0;
            r0 = r5;
            do {
                ST8(r0 + r6, r6);
                r6 = r6 + 1;
            } while (AGAIN(!(r6 > r2)));
            r7 = r7 + 1;
            c2 = r7 > r3;
            r5 = r5 + 0x100;
            c1002 = c2;
        } while (AGAIN(!(c2)));
    }
    return r0;
}
