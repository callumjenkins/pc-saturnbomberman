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
