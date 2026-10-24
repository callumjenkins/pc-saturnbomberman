#include "krnl.h"

void f06070024(void)
{
    GJUMP0(0x0607005C);
}

int f060704D0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r3 = LD16(66 + r4);
    if (!((r3 & r3) == 0)) {
        r2 = LD32(0x060D7B3C);
        r1 = LD16(60 + r2);
        if (!((r1 & 0xFFFF) >= 0xFF00)) {
            SETSP((sp - 12));
            SETPR(0x060705B2);
            r0 = GCALL4(0x0606BA1E, -8, 7, 0, 24);
        } else {
            SETSP((sp - 12));
            r0 = GCALL4(0x0606B6BC, r4, r5, r6, r7);
            r3 = LD32(r14);
            ST16(66 + r3, 0);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 1;
    } else {
        r6 = 32;
        r5 = LD16(64 + r4);
        r0 = LD16(r4 + 20);
        r2 = LD16(0x060B90A4);
        r1 = LD16((((r0 & 0xFFFF) + r2) << 1) + 0x060EC8B0);
        r5 = r5 & 0xFFFF;
        if (!(((r1 & 0xFFFF) & 32) == 0)) {
            ST16(66 + r4, 1);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06070554);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
            r3 = LD32(r14);
            r0 = LD8(r3 + 6);
            ST32(sp - 12, (r0 & 255));
            r3 = LD32(r14);
            ST8(r3 + 6, 2);
            SETSP((sp - 12));
            r0 = GCALL0(0x0601FCBE);
            if (!((r0 & r0) == 0)) {
                SETSP((sp - 12));
                r0 = GCALL1(0x0600996A, 20);
            }
            r2 = LD32(r14);
            r0 = LD8(sp - 9);
            ST8(r2 + 6, r0);
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 1;
        } else {
            r0 = LD16(0x060C1F4A + (((r5 << 1) + r5) << 2));
            if ((r0 & r0) == 0) {
                r0 = LD16(0x060C1F44 + (((r5 << 1) + r5) << 2));
                if (!(r0 >= 0)) {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return 0;
                } else {
                    r0 = LD16(0x060C1F44 + (((r5 << 1) + r5) << 2));
                    if (r0 > r6) {
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return 0;
                    } else {
                        ST16(66 + r4, 1);
                        r5 = LD32(r14);
                        r4 = LD16(0x060C1AA8);
                        r5 = LD16(80 + r5);
                        SETR(14, r14);
                        SETSP((sp - 12));
                        SETPR(0x06070554);
                        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                        r3 = LD32(r14);
                        r0 = LD8(r3 + 6);
                        ST32(sp - 12, (r0 & 255));
                        r3 = LD32(r14);
                        ST8(r3 + 6, 2);
                        SETSP((sp - 12));
                        r0 = GCALL0(0x0601FCBE);
                        if (!((r0 & r0) == 0)) {
                            SETSP((sp - 12));
                            r0 = GCALL1(0x0600996A, 20);
                        }
                        r2 = LD32(r14);
                        r0 = LD8(sp - 9);
                        ST8(r2 + 6, r0);
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return 1;
                    }
                }
            } else {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 0;
            }
        }
    }
}

int f06070660(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(66 + r4);
    if ((r0 & r0) == 0) {
        r1 = LD16(62 + r4);
        if ((r1 & r1) == 0) {
            SETSP((sp - 12));
            r0 = GCALL0(0x0606CA64);
            if (!((r0 & r0) == 0)) {
                r0 = 0;
            } else {
                r8 = LD32(r14);
                SETSP((sp - 12));
                r0 = GCALL0(0x0600A0B8);
                ST16((r8 + 66), ((r0 & 1) + 1));
                r5 = LD32(r14);
                r3 = LD32(r14);
                r5 = LD16(66 + r5);
                r5 = LD16(0x060BA20E + (((r5 & 0xFFFF) - 1) << 1));
                r2 = LD16(80 + r3);
                r4 = LD16(0x060C1AA8);
                SETSP((sp - 12));
                SETPR(0x060706F0);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 + (r2 & 0xFFFF)));
                SETSP((sp - 12));
                r0 = GCALL1(0x06014516, 0x06070748);
                r0 = 1;
            }
        } else {
            r3 = LD16(66 + r4);
            if (!((r3 & r3) == 0)) {
                r0 = 0;
            } else {
                SETSP((sp - 12));
                r0 = GCALL0(0x0600A0B8);
                if ((r0 & 15) == 0) {
                    r5 = LD32(r14);
                    r5 = LD16(80 + r5);
                    r4 = LD16(0x060C1AA8);
                    SETSP((sp - 12));
                    SETPR(0x060706A8);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                    SETSP((sp - 12));
                    r0 = GCALL1(0x06014516, 0x0606D8B6);
                    r0 = 1;
                } else {
                    r0 = 0;
                }
            }
        }
    } else {
        r0 = 0;
    }
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06070A04(void)
{
    int r0, r1, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(66 + r4);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    } else {
        r1 = LD16(62 + r4);
        if ((r1 & r1) == 0) {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606C4FA);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 0;
            } else {
                r3 = LD32(r14);
                r2 = LD16(0x060C1F32);
                ST16(66 + r3, r2);
                r5 = LD32(r14);
                r5 = LD16(66 + r5);
                r3 = LD32(r14);
                r5 = LD16(0x060BA262 + ((r5 & 0xFFFF) << 1));
                r2 = LD16(80 + r3);
                r4 = LD16(0x060C1AA8);
                SETR(14, r14);
                SETSP((sp - 8));
                SETPR(0x06070A5A);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r2 & 0xFFFF)));
                r3 = LD32(r14);
                ST16(62 + r3, 58);
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x06070A7A);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 1;
            }
        } else {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        }
    }
}

int f06070DE8(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06070DF4);
    r0 = GCALL3(0x0606B0DE, 0x060BA2BC, 225, 7);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C776);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 2));
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 4));
    SETPR(0x06070E14);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06070E2E);
    r2 = LD32(0x060D7768);
    ST16(58 + r2, 99);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606E864);
    return r0;
}

int f06070E2E(void)
{
    GCALL1(0x0600996A, 0x79);
    ST16(LD32(CURRENT) + 52, 0);
    GCALL0(0x0606C7CE);
    GCALL0(0x0606B6BC);
    ST32(0x060E2154 + (short)(LD16(0x060C062C) * 20), 0x06070F1C);
    GCALL1(0x060144F4, 0x06070E70);
    return GJUMP1(0x06014516, 0x0606E7F4);
}

int f06070F1C(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06070F24);
    r0 = GCALL0(0x0606C8C0);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D2C8);
        SETPR(LD32((sp - 4)));
        return 1;
    }
}

int f06070F7A(void)
{
    int r0, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r0 = LD16(62 + r3);
    if ((r0 & r0) == 0) {
        SETSP((sp - 8));
        r0 = GCALL0(0x0606E81C);
        r4 = LD32(r14);
        r4 = LD16(64 + r4);
        SETSP((sp - 8));
        r0 = GCALL1(0x0606BEBC, (r4 & 0xFFFF));
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        } else {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606BBB0);
            SETSP((sp - 8));
            r0 = GCALL0(0x0606B648);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 0;
            } else {
                r3 = LD32(r14);
                r2 = LD16(0x060C1F24);
                ST16(66 + r3, r2);
                SETSP((sp - 8));
                r0 = GCALL0(0x0606D986);
                r5 = LD32(r14);
                r3 = LD32(r14);
                r5 = LD16(80 + r5);
                r2 = LD16(66 + r3);
                r4 = LD16(0x060C1AA8);
                SETSP((sp - 8));
                SETPR(0x06070FE6);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r2 & 0xFFFF)) + 4));
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x06071050);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 1;
            }
        }
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

void f0607123A(int n)
{
    GJUMP1(0x0601628E, n);
}

void f0607193C(void)
{
    FRAME(sp, 20);
    gaddr table = sp - 20;
    gaddr obj, rec;

    COPYB(table, 0x060B298C, 10);
    obj = LD32(CURRENT);
    ST16(obj + 48, LD16(table + (LDU8(obj + 6) << 1)));
    rec = REC(LDU16(LD32(CURRENT) + 68));
    ST16(rec + 66, 0);
    while (LD16(rec + 68) != 0) {
        POLL();
        rec = REC(LDU16(rec + 68));
    }
    if (LDU16(rec + 40) != 1)
        ST16(rec + 72, 1);
    GCALL1(0x060144F4, 0x0606D2C8);
}

int f060719F0(void)
{
    int r0, r2, r3, r4, r5, r6, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r5 = 0x060D7B3C;
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(62 + r4);
    if ((r0 & r0) == 0) {
        r3 = LD16(66 + r4);
        if (!((r3 & r3) == 0)) {
            ST16(66 + r4, 0);
            r3 = LD32(r5);
            ST16(48 + r3, 0);
            SETSP((sp - 8));
            r0 = GCALL0(0x0606C7DE);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 8));
            SETPR(0x06071ADA);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 6));
            SETSP((sp - 8));
            r0 = GCALL0(0x06071AEE);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606D8B6);
        } else {
            ST16(66 + r4, 1);
            r3 = LD32(r5);
            ST16(48 + r3, 4);
            SETSP((sp - 8));
            r0 = GCALL0(0x0606C7EE);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06071AA0);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
            r3 = LD32(r14);
            ST16(62 + r3, 240);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606D8B6);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 1;
    } else {
        r6 = LD32(r5);
        r3 = LD16(50 + r6);
        r2 = LD16(80 + r4);
        if (!((r3 & 0xFFFF) == ((r2 & 0xFFFF) + 6))) {
            SETPR(LD32((sp - 8)));
            r0 = LD16(66 + r4);
            SETR(14, LD32((sp - 4)));
            return r0 & 0xFFFF;
        } else {
            r2 = LD16(60 + r6);
            if ((r2 & 0xFFFF) >= 0xFF00) {
                SETPR(LD32((sp - 8)));
                r0 = LD16(66 + r4);
                SETR(14, LD32((sp - 4)));
                return r0 & 0xFFFF;
            } else {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 1;
            }
        }
    }
}

void f06071AEE(void)
{
    FRAME(sp, 24);
    gaddr cur;

    COPYW(0x06094450, sp - 24, 0x060B2998, 16);
    cur = LD32(CURRENT);
    ST16(cur + 62, LD32(sp - 24 + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

int f06071B9C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    r10 = 0x06068ACC;
    r12 = 0x060C1AA8;
    r14 = 0x060D7768;
    r13 = LD32(0x060D7768);
    r0 = LD16(66 + r13);
    r11 = 0;
    if (!((r0 & r0) == 0)) {
        r3 = LD16(62 + r13);
        if ((r3 & r3) == 0) {
            r3 = LD16(68 + r13);
            ST16(68 + r13, (r3 + 1));
            r2 = LD32(r14);
            r0 = LD8(r2 + 67);
            r3 = LD16((68 + r2));
            r3 = LD16((((signed char)((((r0 - 1) << 2) + (r0 - 1)) << 1)) + 0x060BA3D8) + ((r3 & 0xFFFF) << 1));
            ST16(62 + r2, r3);
            r2 = LD32(r14);
            r3 = LD16(62 + r2);
            if (!((r3 & r3) == 0)) {
                r3 = LD32(r14);
                r2 = LD16(62 + r3);
                if (!((r2 & 0xFFFF) >= 255)) {
                    r0 = LD32(r14);
                    r4 = LD32(r14);
                    r0 = LD8(r0 + 67);
                    r4 = LD16((68 + r4));
                    r4 = LD16((((signed char)((((r0 - 1) << 2) + (r0 - 1)) << 1)) + 0x060BA3EC) + ((r4 & 0xFFFF) << 1));
                    if (!(r4 == 1)) {
                        if (r4 == -1) {
                            r4 = LD32(r14);
                            r0 = LD16(r4 + 20);
                            r3 = r0 & 0xFFFF;
                            r0 = LD8(r4 + 6);
                            r4 = LD16(0x060B90A0 + ((r0 & 255) << 1));
                            SETSP((sp - 28));
                            r0 = GCALL1(0x06020DB4, (r4 + r3));
                            if ((r0 & r0) == 0) {
                                r3 = LD32(r14);
                                ST16(72 + r3, 1);
                            }
                        }
                    } else {
                        r5 = LD32(r14);
                        r0 = LD8(r5 + 6);
                        r5 = (r0 & 255) << 1;
                        ST32(sp - 28, r5);
                        r5 = LD16(0x060B90B4 + r5);
                        r4 = LD32(r14);
                        r0 = LD16(r4 + 20);
                        r4 = LD32(sp - 28);
                        r4 = LD16((r4 + 0x060B90AA));
                        SETSP((sp - 28));
                        r0 = GCALL3(0x0601FA22, (r4 + (r0 & 0xFFFF)), (r5 & 0xFFFF), 1);
                        if ((r0 & r0) == 0) {
                            r3 = LD32(r14);
                            ST16(72 + r3, 1);
                        }
                    }
                } else {
                    r1 = LD32(r14);
                    ST16(62 + r1, r11);
                    r2 = LD32(r14);
                    ST16(66 + r2, r11);
                    r2 = LD32(r14);
                    r1 = LD16(72 + r2);
                    if (!((r1 & r1) == 0)) {
                        SETSP((sp - 28));
                        r0 = GCALL4(0x0606B6BC, r4, r5, r6, r7);
                        SETSP((sp - 28));
                        r0 = GCALL0(0x060145A8);
                    } else {
                        r5 = LD32(r14);
                        r2 = LD32(r14);
                        r5 = LD16(80 + r5);
                        r0 = LD8(r2 + 6);
                        r4 = LD16(r12);
                        SETSP((sp - 28));
                        SETPR(0x06071C70);
                        r0 = GCALL4(r10, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (((r0 & 255) - 1) << 2)) + 8), r6, r7);
                        r4 = 0x0606D8B6;
                        SETSP((sp - 28));
                        r0 = GCALL1(0x06014516, r4);
                    }
                }
            } else {
                r3 = LD32(r14);
                r5 = LD32(r14);
                r4 = LD16(r12);
                r5 = LD16(80 + r5);
                r0 = LD8(r3 + 6);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x06071C22);
                r0 = GCALL4(r10, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (((r0 & 255) - 1) << 2)) + 7), r6, r7);
                r4 = 0x0606E864;
                r3 = LD32(r14);
                ST16(58 + r3, 10);
                SETSP((sp - 28));
                r0 = GCALL1(0x06014516, r4);
            }
        }
        r0 = 1;
    } else {
        r0 = LD8(r13 + 6);
        if ((r0 & r0) == 0) {
            r0 = 0;
        } else {
            SETSP((sp - 28));
            r0 = GCALL1(0x0606C390, 2);
            ST16((66 + r13), r0);
            if (((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
                r0 = 0;
            } else {
                r3 = LD32(r14);
                r5 = LD32(r14);
                r4 = LD16(r12);
                r5 = LD16(80 + r5);
                r0 = LD8(r3 + 6);
                r2 = LD16(66 + r3);
                SETR(11, r11);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x06071D7E);
                r0 = GCALL4(r10, (r4 & 0xFFFF), ((((r5 & 0xFFFF) + (((r0 & 255) - 1) << 2)) + (r2 & 0xFFFF)) + 4), r6, r7);
                r3 = LD32(r14);
                ST16(72 + r3, r11);
                r3 = LD32(r14);
                ST16(68 + r3, r11);
                r3 = LD32(r14);
                r0 = LD8(r3 + 67);
                r2 = LD16((68 + r3));
                r2 = LD16((((signed char)((((r0 - 1) << 2) + (r0 - 1)) << 1)) + 0x060BA3D8) + ((r2 & 0xFFFF) << 1));
                ST16(62 + r3, r2);
                r0 = 1;
            }
        }
    }
    SETPR(LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06071F0C(void)
{
    int r0, r1, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(66 + r4);
    if ((r0 & r0) == 0) {
        r1 = LD16(82 + r4);
        if ((r1 & r1) == 0) {
            r0 = LD8(r4 + 6);
            if (!((r0 & r0) == 0)) {
                r0 = LD8(r4 + 6);
                ST16(0x060C1F24, (r0 & 255));
                SETSP((sp - 12));
                r0 = GCALL0(0x0606B648);
                ST32(sp - 12, r0);
                r3 = LD32(r14);
                ST16(44 + r3, 1);
                SETSP((sp - 12));
                r0 = GCALL0(0x0606B648);
                r4 = r0;
                r2 = LD32(r14);
                ST16(44 + r2, 0);
                r1 = LD32(sp - 12);
                if (!((r1 & r1) == 0)) {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return 0;
                } else {
                    if (!((r4 & r4) == 0)) {
                        r3 = LD32(r14);
                        ST16(66 + r3, 1);
                        r5 = LD32(r14);
                        r3 = LD32(r14);
                        r5 = LD16(80 + r5);
                        r0 = LD8(r3 + 6);
                        r4 = LD16(0x060C1AA8);
                        SETR(14, r14);
                        SETSP((sp - 12));
                        SETPR(0x06072038);
                        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 4));
                        r3 = LD32(r14);
                        ST16(62 + r3, 28);
                        SETSP((sp - 12));
                        r0 = GCALL1(0x06014516, 0x06072052);
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return 1;
                    } else {
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return 0;
                    }
                }
            } else {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 0;
            }
        } else {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        }
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

int f0607217C(void)
{
    int r0, r1, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 28));
    r0 = COPYW(0x0609445C, (sp - 28), 0x060B29A8, 20);
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(66 + r4);
    if ((r0 & r0) == 0) {
        r1 = LD16(62 + r4);
        if ((r1 & r1) == 0) {
            SETSP((sp - 28));
            r0 = GCALL0(0x0606E81C);
            r4 = LD32(r14);
            r4 = LD16(64 + r4);
            SETSP((sp - 28));
            r0 = GCALL1(0x0606BD32, (r4 & 0xFFFF));
            if (!((r0 & r0) == 0)) {
                SETSP((sp - 28));
                r0 = GCALL0(0x0606BBB0);
                r2 = LD32(r14);
                r3 = LD16(0x060C1F24);
                ST16(66 + r2, r3);
                r5 = LD16(0x060C1F24);
                r2 = LD32(r14);
                r3 = LD16(80 + r2);
                r5 = LD32((((r5 & 0xFFFF) << 2) + (sp - 28)));
                r4 = LD16(0x060C1AA8);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x06072250);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 + (r3 & 0xFFFF)));
                r3 = LD32(r14);
                ST16(62 + r3, 42);
                SETSP((sp - 28));
                r0 = GCALL1(0x06014516, 0x0607226A);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 1;
            } else {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 0;
            }
        } else {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        }
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

void f060723D8(void)
{
    FRAME(sp, 24);
    gaddr cur;

    COPYW(0x06094450, sp - 24, 0x060B29BC, 16);
    cur = LD32(CURRENT);
    ST16(cur + 62, LD32(sp - 24 + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

int f06072406(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060D7B3C;
    r14 = 0x060D7768;
    r4 = LD32(0x060D7B3C);
    r3 = LD16(60 + r4);
    r5 = LD32(0x060D7768);
    if ((r3 & 0xFFFF) >= 0xFF00) {
        r1 = LD16(50 + r4);
        r3 = LD16(80 + r5);
        if (!((r1 & 0xFFFF) == ((r3 & 0xFFFF) + 8))) {
            r3 = LD16(50 + r4);
            r1 = LD16(80 + r5);
            if ((r3 & 0xFFFF) == ((r1 & 0xFFFF) + 9)) {
                SETSP((sp - 12));
                r0 = GCALL0(0x0606C7CE);
            }
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x0606C78E);
            r3 = LD32(r14);
            r1 = LD16(42 + r3);
            ST16(42 + r3, (r1 | 16));
        }
        SETSP((sp - 12));
        r0 = GCALL4(0x0606B6BC, r4, r5, r6, r7);
    }
    r2 = LD32(r14);
    r0 = LD16(62 + r2);
    if ((r0 & r0) == 0) {
        r3 = LD32(r14);
        r2 = LD16(66 + r3);
        if (!((r2 & r2) == 0)) {
            r2 = LD32(r14);
            ST16(66 + r2, 0);
            SETSP((sp - 12));
            r0 = GCALL0(0x0606C7C2);
            r3 = LD32(r14);
            r1 = LD16(42 + r3);
            ST16(42 + r3, (r1 & 0xFFEF));
            r3 = LD32(r13);
            ST16(48 + r3, 0);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06072580);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
            SETSP((sp - 12));
            r0 = GCALL0(0x060723D8);
            r2 = LD32(r14);
            r3 = LD16(62 + r2);
            ST16(62 + r2, (r3 + 59));
            r2 = LD32(r14);
            ST16(40 + r2, 14);
            r4 = LD32(r14);
            r4 = LD16(40 + r4);
            SETSP((sp - 12));
            r0 = GCALL1(0x0606D8E6, (r4 & 0xFFFF));
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            r0 = 1;
        } else {
            r3 = LD32(r14);
            ST16(66 + r3, 1);
            SETSP((sp - 12));
            r0 = GCALL0(0x0606C79A);
            r1 = LD32(r13);
            ST16(48 + r1, 4);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06072524);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 8));
            r3 = LD32(r14);
            ST16(62 + r3, 0x15F);
            r3 = LD32(r14);
            ST16(40 + r3, 9);
            r4 = LD32(r14);
            r4 = LD16(40 + r4);
            SETSP((sp - 12));
            r0 = GCALL1(0x0606D8E6, (r4 & 0xFFFF));
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            r0 = 1;
        }
    } else {
        r0 = 0;
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06072812(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607281A);
    r0 = GCALL0(0x0606C8C0);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D2C8);
        SETPR(LD32((sp - 4)));
        return 1;
    }
}

int f060728F8(void)
{
    int r0, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(66 + r4);
    if ((r0 & r0) == 0) {
        r0 = LD16(r4 + 20);
        r3 = LD16(((r0 & 0xFFFF) << 1) + 0x060EE8B0);
        if (((r3 & 0xFFFF) & 0xF00) == 0) {
            SETSP((sp - 8));
            r0 = GCALL0(0x0600A0B8);
            if ((r0 & 15) == 0) {
                r5 = LD32(r14);
                r4 = LD16(0x060C1AA8);
                r5 = LD16(80 + r5);
                SETSP((sp - 8));
                SETPR(0x06072972);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x0606D8B6);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 1;
            } else {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 0;
            }
        } else {
            ST16(66 + r4, 1);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 8));
            SETPR(0x0607293C);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 6));
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x060729C4);
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 1;
        }
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

int f06072AC8(void)
{
    int cell = LDU16(LD32(CURRENT) + 20);
    int a = cell + LD16(0x060B90A2);
    int b = cell + LD16(0x060B90A4);
    int c = cell + LD16(0x060B90A6);
    int d = cell + LD16(0x060B90A8);
    int walls = LDU16(FLAGS_AT(a)) | LDU16(FLAGS_AT(b)) | LDU16(FLAGS_AT(c)) | LDU16(FLAGS_AT(d));
    int extra = LDU16(0x060EE8B0 + a * 2) | LDU16(0x060EE8B0 + b * 2) | LDU16(0x060EE8B0 + c * 2) | LDU16(0x060EE8B0 + d * 2);

    return ((walls & 7) | (extra & 0xF00)) != 0;
}

int f06072BBA(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060D7768);
    r3 = LD16(42 + r4);
    if (((r3 & 0xFFFF) & 0x2000) == 0) {
        r3 = LD16(66 + r4);
        if (!((r3 & r3) == 0)) {
            r2 = LD16(82 + r4);
            if (!((r2 & r2) == 0)) {
                SETPR(LD32((sp - 4)));
                return 0;
            } else {
                ST16(66 + r4, 0);
                SETSP((sp - 4));
                SETPR(0x06072C10);
                r0 = GCALL0(0x06072C22);
                if ((r0 & r0) == 0) {
                    SETPR(LD32((sp - 4)));
                    return 0;
                } else {
                    SETPR(LD32((sp - 4)));
                    return 1;
                }
            }
        } else {
            r2 = LD16(82 + r4);
            if ((r2 & r2) == 0) {
                SETPR(LD32((sp - 4)));
                return 0;
            } else {
                ST16(66 + r4, 1);
                SETSP((sp - 4));
                SETPR(0x06072BF6);
                r0 = GCALL0(0x06072C22);
                if ((r0 & r0) == 0) {
                    SETPR(LD32((sp - 4)));
                    return 0;
                } else {
                    SETPR(LD32((sp - 4)));
                    return 1;
                }
            }
        }
    } else {
        r3 = LD16(62 + r4);
        if (!((r3 & r3) == 0)) {
            r3 = LD16(66 + r4);
            if (!((r3 & r3) == 0)) {
                r2 = LD16(82 + r4);
                if (!((r2 & r2) == 0)) {
                    SETPR(LD32((sp - 4)));
                    return 0;
                } else {
                    ST16(66 + r4, 0);
                    SETSP((sp - 4));
                    SETPR(0x06072C10);
                    r0 = GCALL0(0x06072C22);
                    if ((r0 & r0) == 0) {
                        SETPR(LD32((sp - 4)));
                        return 0;
                    } else {
                        SETPR(LD32((sp - 4)));
                        return 1;
                    }
                }
            } else {
                r2 = LD16(82 + r4);
                if ((r2 & r2) == 0) {
                    SETPR(LD32((sp - 4)));
                    return 0;
                } else {
                    ST16(66 + r4, 1);
                    SETSP((sp - 4));
                    SETPR(0x06072BF6);
                    r0 = GCALL0(0x06072C22);
                    if ((r0 & r0) == 0) {
                        SETPR(LD32((sp - 4)));
                        return 0;
                    } else {
                        SETPR(LD32((sp - 4)));
                        return 1;
                    }
                }
            }
        } else {
            SETSP((sp - 4));
            r0 = GCALL0(0x06073968);
            SETPR(LD32((sp - 4)));
            return 1;
        }
    }
}

int f06072C22(int r4, int r5, int r6, int r7)
{
    int r0, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(r4 + 20);
    r3 = r0 & 0xFFFF;
    r0 = LD8(r4 + 6);
    r5 = LD16(0x060B90AA + ((r0 & 255) << 1));
    r5 = r5 + r3;
    if (!((unsigned)r5 >= (unsigned)0x1000)) {
        r0 = LD8(r4 + 6);
        if (!((r0 & r0) == 0)) {
            r3 = LD16(0x060EC8B0 + (r5 << 1));
            r0 = LD16(r4 + 18);
            if ((((r3 & 0xFFFF) & (r0 & 0xFFFF)) & -33) == 0) {
                SETSP((sp - 8));
                r0 = GCALL1(0x060144F4, 0x06072CD8);
                r5 = LD32(r14);
                r0 = LD8(r5 + 6);
                r5 = LD16((80 + r5));
                r4 = LD16(0x060C1AA8);
                SETR(14, r14);
                SETSP((sp - 8));
                SETPR(0x06072CC0);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 3));
                r3 = LD32(r14);
                ST16(58 + r3, 33);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP1(0x06014516, 0x0606E864);
                return r0;
            } else {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 0;
            }
        } else {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        }
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

int f06072D62(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06072D6E);
    r0 = GCALL3(0x0606B0DE, 0x060BA550, 40, 3);
    r2 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x06072E5E);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C776);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 2));
    r3 = LD32(0x060D7768);
    ST16(r3 + 18, 0);
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 24);
    ST16((68 + r3), r0);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 28);
    ST16((70 + r3), r0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06072DCA);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 195);
    return r0;
}

int f06072E5E(void)
{
    int dx = GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 24) - LDU16(LD32(CURRENT) + 68));
    int dy = GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 28) - LDU16(LD32(CURRENT) + 70));
    int angle = GCALL1(0x0606CE8C, 127 & ((dx + dy) << 2));
    gaddr mover = LD32(MOVER_PTR);

    ST16(mover + 38, -GCALL1(0x060980E4, angle << 5));
    return 0;
}

int f06072ECA(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06072ED6);
    r0 = GCALL3(0x0606B0DE, 0x060BA55C, 40, 3);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C78E);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 18));
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 18);
    ST16(r3 + 18, (r0 & 0xFFDF));
    r3 = LD32(0x060D7768);
    ST16((62 + r3), 10);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x06072F9C);
    return r0;
}

int f06073112(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060D7768);
    r3 = LD16(42 + r4);
    if (((r3 & 0xFFFF) & 0x2000) == 0) {
        r5 = 0x060D7B3C;
        r3 = LD16(66 + r4);
        if (!((r3 & r3) == 0)) {
            r3 = LD16(60 + r4);
            if ((r3 & r3) == 0) {
                ST16(66 + r4, 0);
                r3 = LD32(r5);
                ST16(48 + r3, 0);
                SETSP((sp - 4));
                r0 = GCALL4(0x0606B6BC, r4, r5, 0, r7);
            }
            SETPR(LD32((sp - 4)));
            return 0;
        } else {
            r2 = LD16(60 + r4);
            if ((r2 & r2) == 0) {
                SETPR(LD32((sp - 4)));
                return 0;
            } else {
                ST16(66 + r4, 1);
                r3 = LD32(r5);
                ST16(48 + r3, 4);
                r4 = LD16(0x060C1AA8);
                r5 = LD32(0x060D7768);
                r5 = LD16(80 + r5);
                SETSP((sp - 4));
                SETPR(0x0607316C);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                SETSP((sp - 4));
                r0 = GCALL1(0x06014516, 0x0606D8B6);
                SETSP((sp - 4));
                SETPR(0x0607317A);
                r0 = GCALL0(0x0606D8B6);
                SETPR(LD32((sp - 4)));
                return 1;
            }
        }
    } else {
        r3 = LD16(62 + r4);
        if (!((r3 & r3) == 0)) {
            r5 = 0x060D7B3C;
            r3 = LD16(66 + r4);
            if (!((r3 & r3) == 0)) {
                r3 = LD16(60 + r4);
                if ((r3 & r3) == 0) {
                    ST16(66 + r4, 0);
                    r3 = LD32(r5);
                    ST16(48 + r3, 0);
                    SETSP((sp - 4));
                    r0 = GCALL4(0x0606B6BC, r4, r5, 0, r7);
                }
                SETPR(LD32((sp - 4)));
                return 0;
            } else {
                r2 = LD16(60 + r4);
                if ((r2 & r2) == 0) {
                    SETPR(LD32((sp - 4)));
                    return 0;
                } else {
                    ST16(66 + r4, 1);
                    r3 = LD32(r5);
                    ST16(48 + r3, 4);
                    r4 = LD16(0x060C1AA8);
                    r5 = LD32(0x060D7768);
                    r5 = LD16(80 + r5);
                    SETSP((sp - 4));
                    SETPR(0x0607316C);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                    SETSP((sp - 4));
                    r0 = GCALL1(0x06014516, 0x0606D8B6);
                    SETSP((sp - 4));
                    SETPR(0x0607317A);
                    r0 = GCALL0(0x0606D8B6);
                    SETPR(LD32((sp - 4)));
                    return 1;
                }
            }
        } else {
            SETSP((sp - 4));
            r0 = GCALL0(0x06073968);
            SETPR(LD32((sp - 4)));
            return 1;
        }
    }
}

int f06073242(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    SETSP((sp - 24));
    r0 = COPYB((sp - 24), 0x060B29CC, 8);
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r1 = LD16(66 + r4);
    r13 = 0;
    if (!((r1 & r1) == 0)) {
        r1 = LD16(62 + r4);
        if (!((r1 & r1) == 0)) {
            r0 = 0;
        } else {
            r0 = LD16(r4 + 20);
            r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
            if (((r0 & 0xFFFF) & 16) == 0) {
                ST16(66 + r4, r13);
                r3 = LD32(r14);
                ST16(68 + r3, r13);
                r3 = LD32(r14);
                ST16(r3 + 12, r13);
                r3 = LD32(r14);
                ST16(r3 + 10, 0x8000);
                r3 = LD32(r14);
                r0 = LD16(r3 + 18);
                ST16(r3 + 18, (r0 | 16));
                r3 = LD32(r14);
                ST16(40 + r3, 17);
                r4 = LD32(r14);
                r4 = LD16(40 + r4);
                SETSP((sp - 24));
                r0 = GCALL1(0x0606D8E6, (r4 & 0xFFFF));
                SETSP((sp - 24));
                r0 = GCALL0(0x060733DE);
                if (!((r0 & r0) == 0)) {
                    SETSP((sp - 24));
                    r0 = GCALL1(0x060144F4, 0x06073432);
                }
                r2 = LD32(0x060D7B3C);
                ST16(48 + r2, r13);
                r5 = LD32(r14);
                r5 = LD16(80 + r5);
                r4 = LD16(0x060C1AA8);
                SETSP((sp - 24));
                SETPR(0x060733C4);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                SETSP((sp - 24));
                r0 = GCALL1(0x06014516, 0x0606D8B6);
                r0 = 1;
            } else {
                r0 = 0;
            }
        }
    } else {
        r3 = LD16(84 + r4);
        if ((r3 & r3) == 0) {
            r3 = LD16(68 + r4);
            if ((r3 & 0xFFFF) >= 4) {
                ST16(66 + r4, 1);
                r8 = LD32(r14);
                SETSP((sp - 24));
                r0 = GCALL0(0x0600A0B8);
                r1 = LD16(((r0 & 3) << 1) + (sp - 24));
                ST16((r8 + 62), (r1 + 180));
                r0 = LD32(r14);
                ST16((12 + r0), r13);
                r0 = LD32(r14);
                ST16((10 + r0), 0xA000);
                r3 = LD32(r14);
                r0 = LD16(r3 + 18);
                ST16(r3 + 18, (r0 & 0xFFEF));
                r3 = LD32(r14);
                ST16((40 + r3), 15);
                r4 = LD32(r14);
                r4 = LD16(40 + r4);
                SETSP((sp - 24));
                r0 = GCALL1(0x0606D8E6, (r4 & 0xFFFF));
                r2 = LD32(0x060D7B3C);
                ST16(48 + r2, 6);
                r5 = LD32(r14);
                r5 = LD16(80 + r5);
                r4 = LD16(0x060C1AA8);
                SETSP((sp - 24));
                SETPR(0x060732F4);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
                SETSP((sp - 24));
                r0 = GCALL1(0x06014516, 0x0606D8B6);
                r0 = 1;
            } else {
                r2 = LD16(68 + r4);
                ST16(68 + r4, (r2 + 1));
                r0 = 0;
            }
        } else {
            r0 = 0;
        }
    }
    SETPR(LD32((sp - 16)));
    SETR(8, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060733DE(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr p = 0x060B90A2;

    if (!(LDU16(cur + 42) & 0x2000))
        return 0;
    do {
        if (!(LDU16(FLAGS_AT(LDU16(cur + 20) + LD16(p))) & (LDU16(cur + 18) | 16)))
            return 1;
        p += 2;
    } while (AGAIN(p < 0x060B90AA));
    return 0;
}

void f06073432(void)
{
    gaddr cur;

    GCALL1(0x060144F4, 0x0607399A);
    cur = LD32(CURRENT);
    ST16(cur + 42, LDU16(cur + 42) & 0xDFFF);
    cur = LD32(CURRENT);
    ST16(cur + 70, 4);
    cur = LD32(CURRENT);
    ST16(cur + 68, LD16(cur + 70) + 0x100);
}

int f060734F8(void)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06073504);
    r0 = GCALL3(0x0606B0DE, 0x060BA5B4, 64, 5);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06073520);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C776);
    SETPR(LD32((sp - 4)));
    r2 = LD32(0x060D7768);
    ST16(62 + r2, 75);
    return 62;
}

void f060738A2(void)
{
    gaddr cur;
    gaddr mover;
    int a;
    int w;
    int v;

    GCALL2(0x0606AAC8, LD32(MOVER_PTR), 3);
    a = GCALL1(0x0606CE8C, 0xFF & (LDU16(LD32(CURRENT) + 68) << 2));
    cur = LD32(CURRENT);
    w = LD16(cur + 68);
    mover = LD32(MOVER_PTR);
    ST16(mover + 70, (short)((unsigned int)((0x180 - (unsigned short)w / 2) * a) >> 16) + w);
    v = LDU16(mover + 70);
    if (v < 0x100) {
        v = 0x100;
    }
    ST16(mover + 68, DIVS(0x10000, v));
    cur = LD32(CURRENT);
    ST16(cur + 68, LD16(cur + 68) + LD16(cur + 70));
}

void f06073968(void)
{
    gaddr cur;

    GCALL1(0x060144F4, 0x0607399A);
    cur = LD32(CURRENT);
    ST16(cur + 42, LDU16(cur + 42) & 0xDFFF);
    cur = LD32(CURRENT);
    ST16(cur + 70, 4);
    cur = LD32(CURRENT);
    ST16(cur + 68, LD16(cur + 70) + 0x100);
}

void f06073AC0(void)
{
    gaddr cur;

    GCALL2(0x0606AAC8, LD32(MOVER_PTR), 0);
    ST16(LD32(CURRENT) + 80, 80);
    ST16(LD32(CURRENT) + 50, 6);
    ST16(LD32(CURRENT) + 48, 6);
    GJUMP1(0x060144F4, 0x0606D2C8);
}

int f06073B32(void)
{
    if (LD16(LD32(CURRENT) + 66)) {
        GCALL1(0x06014820, LD16(0x060C062C));
        GCALL1(0x060144F4, 0x06073B72);
        ST32(0x060E2154 + (short)(LD16(0x060C062C) * 20), 0x0606B1EC);
        ST16(LD32(CURRENT) + 18, 0);
    }
    return 0;
}

int f06073E4E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06073E5A);
    r0 = GCALL3(0x0606B0DE, 0x060BA648, 87, 7);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x06073EB8);
    return r0;
}

void f06073F74(void)
{
    FRAME(sp, 24);
    gaddr cur;

    COPYW(0x06094450, sp - 24, 0x060B29D4, 16);
    cur = LD32(CURRENT);
    ST16(cur + 62, LD32(sp - 24 + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

int f06073FF8(void)
{
    int r0, r2, r3, r4, r5, r8, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r3 = LD16(62 + r4);
    if (!((r3 & r3) == 0)) {
        r0 = 0;
    } else {
        ST16(70 + r4, 1);
        r3 = LD32(r14);
        r0 = LD8(r3 + 6);
        r0 = r0 & 255;
        ST16((68 + r3), r0);
        if (((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
            r8 = LD32(r14);
            SETSP((sp - 12));
            r0 = GCALL0(0x0600A0B8);
            ST8((r8 + 6), ((r0 & 3) + 1));
        }
        SETSP((sp - 12));
        r0 = GCALL1(0x06014516, 0x0607407A);
        r5 = LD32(r14);
        r4 = LD16(0x060C1AA8);
        r0 = LD8(r5 + 6);
        r5 = LD16((80 + r5));
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06074056);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 4));
        r3 = LD32(r14);
        r2 = LD32(0x060D7B3C);
        r0 = LD16(r2 + 10);
        ST16((66 + r3), r0);
        r3 = LD32(r14);
        ST16(62 + r3, 131);
        r0 = 1;
    }
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0607421E(void)
{
    int r0, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD8(r4 + 6);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    } else {
        r3 = LD16(62 + r4);
        if (!((r3 & r3) == 0)) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        } else {
            r0 = LD8(r4 + 6);
            r5 = LD16(0x060B90A0 + ((r0 & 255) << 1));
            r0 = LD16(r4 + 20);
            r3 = LD16(0x060EC8B0 + ((r5 + (r0 & 0xFFFF)) << 1));
            r0 = LD16(r4 + 18);
            if ((((r3 & 0xFFFF) & (r0 & 0xFFFF)) & -49) == 0) {
                SETSP((sp - 8));
                r0 = GCALL1(0x060144F4, 0x060742E4);
                r5 = LD32(r14);
                r0 = LD8(r5 + 6);
                r3 = LD32(r14);
                r2 = LD16(80 + r3);
                r4 = LD16(0x060C1AA8);
                SETSP((sp - 8));
                SETPR(0x060742CC);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((((r0 & 255) - 1) << 1) + (r2 & 0xFFFF)) + 5));
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x0606D88C);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 1;
            } else {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 0;
            }
        }
    }
}

void f060743A6(void)
{
    POLL();
    GJUMP0(0x06073968);
}

void f060743AA(void)
{
    FRAME(sp, 24);
    gaddr cur;

    COPYW(0x06094450, sp - 24, 0x060B2A94, 16);
    cur = LD32(CURRENT);
    ST16(cur + 62, LD32(sp - 24 + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

int f060744DC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060744E8);
    r0 = GCALL3(0x0606B0DE, 0x060BA6A4, 116, 9);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 2));
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    r3 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x06074576);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06074522);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 188);
    return r0;
}

int f06074576(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607457E);
    r0 = GCALL0(0x0606C8C0);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D2C8);
        SETPR(LD32((sp - 4)));
        return 1;
    }
}

void f06074754(void)
{
    int i = 0;

    do {
        ST16(0x060C1F78 + i * 220, 0);
    } while (AGAIN(++i < 8));
}

int f06074770(void)
{
    int i = 0;

    while (i < 8) {
        gaddr rec = 0x060C1F78 + i * 220;

        POLL();
        if (LD16(rec) == 0) {
            ST16(rec, 1);
            ST16(rec + 212, 0);
            return i;
        }
        i++;
    }
    return 8;
}

void f060747A6(unsigned int n)
{
    if (n < 8)
        ST16(0x060C1F78 + n * 220, 0);
}

void f060749D8(void)
{
    unsigned int total = 0;
    unsigned int i;

    if (LD32(LD32(PATH_PTR) + 76)) {
        for (i = 1; i < (unsigned int)LD32(LD32(PATH_PTR) + 76); i++) {
            POLL();
            total += GCALL1(0x06074A22, i);
        }
        total = DIVU(total, LD32(LD32(PATH_PTR) + 76));
    }
    ST32(LD32(PATH_PTR) + 216, total);
}

int f06074A22(int i)
{
    int dx = GCALL1(0x060949D0, LD32(LD32(PATH_PTR) + 80 + i * 8) - LD32(LD32(PATH_PTR) + 80 + (i - 1) * 8));
    int dy = GCALL1(0x060949D0, LD32(LD32(PATH_PTR) + 80 + i * 8 + 4) - LD32(LD32(PATH_PTR) + 80 + (i - 1) * 8 + 4));

    return GJUMP2(0x0609732A, dx, dy);
}

void f06074A7C(void)
{
    unsigned int i = 1;
    unsigned int j;

    while (i < (unsigned int)LD32(LD32(PATH_PTR) + 8)) {
        POLL();
        if (LD32(PATH_ENTRY(i - 1)) == LD32(PATH_ENTRY(i)) && LD32(PATH_ENTRY(i - 1) + 4) == LD32(PATH_ENTRY(i) + 4)) {
            j = i;
            while (j < (unsigned int)LD32(LD32(PATH_PTR) + 8)) {
                POLL();
                ST32(PATH_ENTRY(j - 1), LD32(PATH_ENTRY(j)));
                ST32(PATH_ENTRY(j - 1) + 4, LD32(PATH_ENTRY(j) + 4));
                j++;
            }
            i--;
            ST32(LD32(PATH_PTR) + 8, LD32(LD32(PATH_PTR) + 8) - 1);
        }
        i++;
    }
}

void f06074AFA(int x, int y)
{
    gaddr cur = LD32(0x060D7768);

    GJUMP2(0x06074B2C, x - LDU16(cur + 24), y - LDU16(cur + 28));
}

void f06074B2C(int x, int y)
{
    int speed;

    GCALL2(0x06074BB6, x, y);
    speed = (LDU16(LD32(0x060D7768) + 12) << 16) + LDU16(LD32(0x060D7768) + 10);
    ST16(LD32(0x060D7768) + 82,
         HELPER(GCALL2(0x060980B4, speed, GCALL1(0x0606CEB0, LDU16(LD32(0x060D7768) + 86))) >> 8));
    ST16(LD32(0x060D7768) + 84,
         HELPER(GCALL2(0x060980B4, speed, GCALL1(0x0606CE8C, LDU16(LD32(0x060D7768) + 86))) >> 8));
}

void f06074B48(short dir, short speed)
{
    gaddr cur = LD32(CURRENT);
    int v, s;

    ST16(cur + 54, speed);
    ST16(cur + 86, dir);
    v = (LDU16(cur + 12) << 16) + LDU16(cur + 10);
    s = GCALL2(0x060980B4, v, GCALL1(0x0606CEB0, LDU16(cur + 86)));
    ST16(cur + 82, HELPER(s >> 8));
    s = GCALL2(0x060980B4, v, GCALL1(0x0606CE8C, LDU16(cur + 86)));
    ST16(cur + 84, HELPER(s >> 8));
}

void f06074BB6(int x, int y)
{
    int ax = GCALL1(0x060949D0, x);
    int ay = GCALL1(0x060949D0, y);
    int big = (unsigned int)ax >= (unsigned int)ay ? ax : ay;
    int nx, ny;

    ST16(LD32(CURRENT) + 54, big);
    nx = -DIVS(GCALL1(0x060980DC, x), big);
    ny = DIVS(GCALL1(0x060980DC, y), big);
    ST16(LD32(CURRENT) + 86, GCALL2(0x0606CED4, -ny, nx));
}

int f06074C34(int dir, int scale)
{
    int s = ((dir + 32) & 64) ? GCALL1(0x0606CE8C, dir) : GCALL1(0x0606CEB0, dir);

    return GCALL1(0x060949D0, GCALL1(0x060980E4, 0x8000 + GCALL2(0x060980B4, GCALL1(0x060980DC, scale), s)));
}

void f06074E14(void)
{
    ST16(LD32(CURRENT) + 62, 0x4B0);
}

int f0607544E(void)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD16(0x060C277C);
    ST16(0x060C277C, (r3 - 1));
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606D2C8);
    SETSP((sp - 4));
    SETPR(0x06075466);
    r0 = GCALL0(0x0606D2C8);
    SETPR(LD32((sp - 4)));
    return r0;
}

void f06075710(void)
{
    GJUMP0(0x0607571E);
}

int f060757DE(int n)
{
    gaddr cur = LD32(CURRENT);
    int result = 66;

    if (LD16(cur + 66) == 0) {
        gaddr c = 0x060C1F42 + n * 12;

        result = LDU16(c + 4);
        if (result < 4) {
            result = LDU16(c + 6);
            if (result < 4) {
                ST16(cur + 66, 1);
                ST16(LD32(CURRENT) + 68, n);
                result = 68;
            }
        }
    }
    return result;
}

int f0607581A(int r4)
{
    int r0, r3, r5;
    ENTRY_SP(sp);

    r5 = r4;
    ST32((sp - 4), PR());
    ST32(sp - 8, r4);
    r4 = LD32(0x060D7768);
    r0 = LD16(r4 + 20);
    SETSP((sp - 8));
    SETPR(0x0607582E);
    r0 = GCALL2(0x06019290, (r0 & 0xFFFF), r5);
    r3 = LD8(0x060C063D);
    if ((unsigned)r0 >= (unsigned)(r3 & 255)) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        SETPR(LD32((sp - 4)));
        return 1;
    }
}

void f06075C58(void)
{
    int p = 0x060C277E;

    do {
        ST16(p, 0);
    } while (AGAIN((p += 32) < 0x060C27BE));
}

int f06075C6E(void)
{
    int i = 0;

    while (i < 2) {
        gaddr rec = 0x060C277E + i * 32;

        POLL();
        if (LD16(rec) == 0) {
            int k = 0;

            ST16(rec, 1);
            do {
                ST16(rec + 8 + k, 0);
                ST16(rec + 14 + k, 0);
                ST16(rec + 20 + k, GCALL0(0x0600A0B8) & 7);
                k += 2;
            } while (AGAIN(k < 6));
            return i;
        }
        i++;
    }
    return 2;
}

void f06075CEE(int n)
{
    gaddr s = 0x060C277E + n * 32;
    int i = 0;

    if (LD16(s) == 0) {
        return;
    }
    ST16(s, 0);
    do {
        if (LD16(s + 8 + i * 2) != 0) {
            GCALL1(0x060692DC, LDU16(s + 8 + i * 2));
        }
        if (LD16(s + 14 + i * 2) != 0) {
            GCALL1(0x060692DC, LDU16(s + 14 + i * 2));
        }
        i++;
    } while (AGAIN(i < 3));
}

int f0607612C(void)
{
    int fresh = 0, any = 0;
    int i = 0;

    do {
        int bit = 1 << i;
        gaddr p = 0x060BA7AA + (signed char)(i * 6);
        int j = 0;

        do {
            if (LDU16(FLAGS_AT(LD16(p) + LDU16(LD32(CURRENT) + 20))) & 7) {
                any = i + 1;
                if (!(LDU16(LD32(CURRENT) + 66) & bit))
                    fresh = i + 1;
                ST16(LD32(CURRENT) + 66, LD16(LD32(CURRENT) + 66) | bit);
                break;
            }
            p += 2;
        } while (AGAIN(++j < 3));
    } while (AGAIN(++i < 4));
    return fresh != 0 ? fresh : any;
}

void f06076658(void)
{
    int i = 0;

    do {
        if (LDU16(0x060EC8B0 + (LDU16(LD32(CURRENT) + 20) + i - 1) * 2) & 7) {
            gaddr p = LD32(0x060C27C0) + 26 + i * 2;
            gaddr cur;

            ST16(p, LDU16(p) | 1);
            cur = LD32(CURRENT);
            ST16(cur + 66, LDU16(cur + 66) | (1 << i));
        }
    } while (AGAIN(++i < 3));
}

unsigned char f06076854(int a, int b)
{
    return LD8(0x060BA7D2 + ((LDU16(LD32(CURRENT) + 72) * 3 + a) << 3) + b);
}

int f060768B0(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060768BC);
    r0 = GCALL3(0x0606B0DE, 0x060BA802, 0x143, 14);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x06076AD4);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607690E);
    r2 = LD32(0x060D7768);
    r0 = LD16(r2 + 24);
    ST16((68 + r2), r0);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 28);
    ST16((70 + r3), r0);
    r3 = LD32(0x060D7768);
    ST16(72 + r3, 0);
    r3 = LD32(0x060D7768);
    ST16(74 + r3, 0);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 115);
    return r0;
}

int f06076AD4(void)
{
    gaddr cur = LD32(CURRENT);

    if (LDU16(cur + 72)) {
        GCALL1(0x060692DC, LDU16(cur + 72));
        ST16(LD32(CURRENT) + 72, 0);
    }
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

int f06076BBC(void)
{
    int s = GCALL1(0x0606CE8C, LD32(0x26006034) & 255);

    ST16(LD32(MOVER_PTR) + 38, HELPER((s - 4) >> 14));
    return 0;
}

int f06076C66(void)
{
    int r0, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r0 = LD16(62 + r3);
    if ((r0 & r0) == 0) {
        SETSP((sp - 8));
        r0 = GCALL0(0x0606E81C);
        r4 = LD32(r14);
        r4 = LD16(64 + r4);
        SETSP((sp - 8));
        r0 = GCALL3(0x0606BCDE, (r4 & 0xFFFF), 2, 1);
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        } else {
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x06076D1A);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 8));
            SETPR(0x06076CFA);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 1));
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            SETSP((sp - 8));
            r0 = GCALL1(0x0600996A, 190);
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 1;
        }
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

void f06077024(void)
{
    GCALL1(0x06009A3A, 190);
    GCALL1(0x0606CC12, LD32(CURRENT) + 68);
    GCALL1(0x0606CC12, LD32(CURRENT) + 70);
    GJUMP1(0x060144F4, 0x0606D2C8);
}

int f060770A4(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    return GJUMP1(0x0609D730, 28);
}

void f0607745C(void)
{
    gaddr zone = 0x060C1F38;

    GCALL0(0x0606DA88);
    if (LD16(0x060C27CE) != 4)
        return;
    if (LDU16(LD32(CURRENT) + 24) <= 208)
        ST16(zone + 6, 1);
    if (LDU16(LD32(CURRENT) + 24) >= 0x170)
        ST16(zone + 2, 1);
    if (LDU16(LD32(CURRENT) + 28) >= 0x200)
        ST16(zone + 4, 1);
}

int f060774A8(void)
{
    int r0, r1, r2, r3, r4, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r14 = 0x060C27CE;
    r13 = LD16(0x060C27CE);
    if (!(r13 >= 3)) {
        r12 = 0x060C27D4;
        r11 = 4;
        if ((r13 & r13) == 0) {
            r13 = 0x060144F4;
            SETSP((sp - 20));
            r0 = GCALL0(0x0607766C);
            if ((r0 & r0) == 0) {
                SETSP((sp - 20));
                r0 = GCALL0(0x06077A8C);
                if ((r0 & r0) == 0) {
                    r3 = LD16(r14);
                    if (!((r3 & r3) == 0)) {
                        r0 = LD16(r14);
                        if (!(r0 == 3)) {
                            r0 = 0;
                        } else {
                            SETSP((sp - 20));
                            r0 = GCALL0(0x06077C08);
                            if ((r0 & r0) == 0) {
                                r0 = 0;
                            } else {
                                ST16(r14, r11);
                                r3 = LD32(0x060D7768);
                                ST16(62 + r3, 0x258);
                                SETSP((sp - 20));
                                r0 = GCALL1(0x06014516, 0x06077CA8);
                                ST16(r12, r11);
                                r0 = 1;
                            }
                        }
                    } else {
                        SETSP((sp - 20));
                        r0 = GCALL0(0x06077BFA);
                        if ((r0 & r0) == 0) {
                            r0 = LD16(r14);
                            if (!(r0 == 3)) {
                                r0 = 0;
                            } else {
                                SETSP((sp - 20));
                                r0 = GCALL0(0x06077C08);
                                if ((r0 & r0) == 0) {
                                    r0 = 0;
                                } else {
                                    ST16(r14, r11);
                                    r3 = LD32(0x060D7768);
                                    ST16(62 + r3, 0x258);
                                    SETSP((sp - 20));
                                    r0 = GCALL1(0x06014516, 0x06077CA8);
                                    ST16(r12, r11);
                                    r0 = 1;
                                }
                            }
                        } else {
                            ST16(r14, 3);
                            r3 = LD32(0x060D7768);
                            ST16(62 + r3, 0x258);
                            SETSP((sp - 20));
                            SETPR(0x06077564);
                            r0 = GCALL1(r13, 0x060773A8);
                            r0 = 1;
                        }
                    }
                } else {
                    ST16(r14, 2);
                    SETSP((sp - 20));
                    SETPR(0x0607751A);
                    r0 = GCALL1(r13, 0x06077AA8);
                    r0 = 1;
                }
            } else {
                ST16(r14, 1);
                SETSP((sp - 20));
                SETPR(0x06077506);
                r0 = GCALL1(r13, 0x06077738);
                r0 = 1;
            }
        } else {
            if (!(r13 == 3)) {
                if (!(r13 == 4)) {
                    r0 = 0;
                } else {
                    r2 = LD16(r12);
                    r2 = r2 - 1;
                    ST16(r12, r2);
                    if (!((((r2 + 1) & 0xFFFF) & ((r2 + 1) & 0xFFFF)) == 0)) {
                        r0 = 0;
                    } else {
                        ST16(r12, r11);
                        ST16(0x060C27D6, 0);
                        SETSP((sp - 20));
                        r0 = GCALL1(0x06014516, 0x06077D38);
                        r0 = 1;
                    }
                }
            } else {
                r13 = 0x060144F4;
                SETSP((sp - 20));
                r0 = GCALL0(0x0607766C);
                if ((r0 & r0) == 0) {
                    SETSP((sp - 20));
                    r0 = GCALL0(0x06077A8C);
                    if ((r0 & r0) == 0) {
                        r3 = LD16(r14);
                        if (!((r3 & r3) == 0)) {
                            r0 = LD16(r14);
                            if (!(r0 == 3)) {
                                r0 = 0;
                            } else {
                                SETSP((sp - 20));
                                r0 = GCALL0(0x06077C08);
                                if ((r0 & r0) == 0) {
                                    r0 = 0;
                                } else {
                                    ST16(r14, r11);
                                    r3 = LD32(0x060D7768);
                                    ST16(62 + r3, 0x258);
                                    SETSP((sp - 20));
                                    r0 = GCALL1(0x06014516, 0x06077CA8);
                                    ST16(r12, r11);
                                    r0 = 1;
                                }
                            }
                        } else {
                            SETSP((sp - 20));
                            r0 = GCALL0(0x06077BFA);
                            if ((r0 & r0) == 0) {
                                r0 = LD16(r14);
                                if (!(r0 == 3)) {
                                    r0 = 0;
                                } else {
                                    SETSP((sp - 20));
                                    r0 = GCALL0(0x06077C08);
                                    if ((r0 & r0) == 0) {
                                        r0 = 0;
                                    } else {
                                        ST16(r14, r11);
                                        r3 = LD32(0x060D7768);
                                        ST16(62 + r3, 0x258);
                                        SETSP((sp - 20));
                                        r0 = GCALL1(0x06014516, 0x06077CA8);
                                        ST16(r12, r11);
                                        r0 = 1;
                                    }
                                }
                            } else {
                                ST16(r14, 3);
                                r3 = LD32(0x060D7768);
                                ST16(62 + r3, 0x258);
                                SETSP((sp - 20));
                                SETPR(0x06077564);
                                r0 = GCALL1(r13, 0x060773A8);
                                r0 = 1;
                            }
                        }
                    } else {
                        ST16(r14, 2);
                        SETSP((sp - 20));
                        SETPR(0x0607751A);
                        r0 = GCALL1(r13, 0x06077AA8);
                        r0 = 1;
                    }
                } else {
                    ST16(r14, 1);
                    SETSP((sp - 20));
                    SETPR(0x06077506);
                    r0 = GCALL1(r13, 0x06077738);
                    r0 = 1;
                }
            }
        }
    } else {
        r1 = LD32(0x060D7768);
        r0 = LD16(62 + r1);
        if (!((r0 & r0) == 0)) {
            r12 = 0x060C27D4;
            r11 = 4;
            if ((r13 & r13) == 0) {
                r13 = 0x060144F4;
                SETSP((sp - 20));
                r0 = GCALL0(0x0607766C);
                if ((r0 & r0) == 0) {
                    SETSP((sp - 20));
                    r0 = GCALL0(0x06077A8C);
                    if ((r0 & r0) == 0) {
                        r3 = LD16(r14);
                        if (!((r3 & r3) == 0)) {
                            r0 = LD16(r14);
                            if (!(r0 == 3)) {
                                r0 = 0;
                            } else {
                                SETSP((sp - 20));
                                r0 = GCALL0(0x06077C08);
                                if ((r0 & r0) == 0) {
                                    r0 = 0;
                                } else {
                                    ST16(r14, r11);
                                    r3 = LD32(0x060D7768);
                                    ST16(62 + r3, 0x258);
                                    SETSP((sp - 20));
                                    r0 = GCALL1(0x06014516, 0x06077CA8);
                                    ST16(r12, r11);
                                    r0 = 1;
                                }
                            }
                        } else {
                            SETSP((sp - 20));
                            r0 = GCALL0(0x06077BFA);
                            if ((r0 & r0) == 0) {
                                r0 = LD16(r14);
                                if (!(r0 == 3)) {
                                    r0 = 0;
                                } else {
                                    SETSP((sp - 20));
                                    r0 = GCALL0(0x06077C08);
                                    if ((r0 & r0) == 0) {
                                        r0 = 0;
                                    } else {
                                        ST16(r14, r11);
                                        r3 = LD32(0x060D7768);
                                        ST16(62 + r3, 0x258);
                                        SETSP((sp - 20));
                                        r0 = GCALL1(0x06014516, 0x06077CA8);
                                        ST16(r12, r11);
                                        r0 = 1;
                                    }
                                }
                            } else {
                                ST16(r14, 3);
                                r3 = LD32(0x060D7768);
                                ST16(62 + r3, 0x258);
                                SETSP((sp - 20));
                                SETPR(0x06077564);
                                r0 = GCALL1(r13, 0x060773A8);
                                r0 = 1;
                            }
                        }
                    } else {
                        ST16(r14, 2);
                        SETSP((sp - 20));
                        SETPR(0x0607751A);
                        r0 = GCALL1(r13, 0x06077AA8);
                        r0 = 1;
                    }
                } else {
                    ST16(r14, 1);
                    SETSP((sp - 20));
                    SETPR(0x06077506);
                    r0 = GCALL1(r13, 0x06077738);
                    r0 = 1;
                }
            } else {
                if (!(r13 == 3)) {
                    if (!(r13 == 4)) {
                        r0 = 0;
                    } else {
                        r2 = LD16(r12);
                        r2 = r2 - 1;
                        ST16(r12, r2);
                        if (!((((r2 + 1) & 0xFFFF) & ((r2 + 1) & 0xFFFF)) == 0)) {
                            r0 = 0;
                        } else {
                            ST16(r12, r11);
                            ST16(0x060C27D6, 0);
                            SETSP((sp - 20));
                            r0 = GCALL1(0x06014516, 0x06077D38);
                            r0 = 1;
                        }
                    }
                } else {
                    r13 = 0x060144F4;
                    SETSP((sp - 20));
                    r0 = GCALL0(0x0607766C);
                    if ((r0 & r0) == 0) {
                        SETSP((sp - 20));
                        r0 = GCALL0(0x06077A8C);
                        if ((r0 & r0) == 0) {
                            r3 = LD16(r14);
                            if (!((r3 & r3) == 0)) {
                                r0 = LD16(r14);
                                if (!(r0 == 3)) {
                                    r0 = 0;
                                } else {
                                    SETSP((sp - 20));
                                    r0 = GCALL0(0x06077C08);
                                    if ((r0 & r0) == 0) {
                                        r0 = 0;
                                    } else {
                                        ST16(r14, r11);
                                        r3 = LD32(0x060D7768);
                                        ST16(62 + r3, 0x258);
                                        SETSP((sp - 20));
                                        r0 = GCALL1(0x06014516, 0x06077CA8);
                                        ST16(r12, r11);
                                        r0 = 1;
                                    }
                                }
                            } else {
                                SETSP((sp - 20));
                                r0 = GCALL0(0x06077BFA);
                                if ((r0 & r0) == 0) {
                                    r0 = LD16(r14);
                                    if (!(r0 == 3)) {
                                        r0 = 0;
                                    } else {
                                        SETSP((sp - 20));
                                        r0 = GCALL0(0x06077C08);
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                        } else {
                                            ST16(r14, r11);
                                            r3 = LD32(0x060D7768);
                                            ST16(62 + r3, 0x258);
                                            SETSP((sp - 20));
                                            r0 = GCALL1(0x06014516, 0x06077CA8);
                                            ST16(r12, r11);
                                            r0 = 1;
                                        }
                                    }
                                } else {
                                    ST16(r14, 3);
                                    r3 = LD32(0x060D7768);
                                    ST16(62 + r3, 0x258);
                                    SETSP((sp - 20));
                                    SETPR(0x06077564);
                                    r0 = GCALL1(r13, 0x060773A8);
                                    r0 = 1;
                                }
                            }
                        } else {
                            ST16(r14, 2);
                            SETSP((sp - 20));
                            SETPR(0x0607751A);
                            r0 = GCALL1(r13, 0x06077AA8);
                            r0 = 1;
                        }
                    } else {
                        ST16(r14, 1);
                        SETSP((sp - 20));
                        SETPR(0x06077506);
                        r0 = GCALL1(r13, 0x06077738);
                        r0 = 1;
                    }
                }
            }
        } else {
            r0 = LD16(r14);
            if (!(r0 == 4)) {
                r4 = 0;
            } else {
                r4 = LD32(0x060D7768);
                r4 = LD16(80 + r4);
                r4 = (r4 & 0xFFFF) + 22;
            }
            SETSP((sp - 20));
            SETPR(0x060774E2);
            r0 = GCALL1(0x060775C6, r4);
            r0 = 1;
        }
    }
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0607766C(void)
{
    gaddr p;
    int count = 0;

    if (LDU16(0x060C27EE)) {
        ST16(0x060C27EE, LDU16(0x060C27EE) - 1);
        return 0;
    }
    ST16(0x060C27CC, 0xFFF);
    p = 0x060BA8B0;
    do {
        gaddr cur = LD32(CURRENT);
        unsigned short cell = LDU16(cur + 20);

        ST16(cur + 20, cell + LDU16(0x060B90AA + LDU16(p) * 2));
        ST16(cur + 20, LDU16(cur + 20) + LD16(0x060B90A8));
        if (GCALL0(0x0606C5D6)) {
            int y, target;

            ST16(LD32(CURRENT) + 20, cell);
            GCALL1(0x0600C9AA, LD16(0x060C1F34));
            y = LDU16(0x060D7EB6);
            if (y >= 27) {
                count++;
                target = y - ((LDU16(LD32(CURRENT) + 28) + 48) >> 4);
                if (GCALL1(0x060949D0, LD16(0x060C27CC)) > GCALL1(0x060949D0, target))
                    ST16(0x060C27CC, target);
            }
        } else {
            ST16(LD32(CURRENT) + 20, cell);
        }
        p += 2;
    } while (AGAIN(p < 0x060BA8B4));
    return count;
}

void f06077870(void)
{
    ST16(0x060C27D2, LD16(0x060C27D0));
    GCALL1(0x060144F4, 0x060778FC);
    GCALL1(0x06014516, 0x0606D88C);
    GJUMP0(0x060778A0);
}

void f0607799E(void)
{
    ST16(0x060C27CE, 255);
    GJUMP0(0x060779C4);
}

void f06077A20(void)
{
    int i = 0;

    ST16(0x060C27D0, 0);
    do {
        int cell = LDU16(LD32(CURRENT) + 20) + LD16(0x060B90AA + LDU16(0x060BA8B0 + i * 2) * 2) + LD16(0x060B90A4) * 3;

        ST16(0x060C27D8 + i * 2, cell);
        if (LDU16(FLAGS_AT(cell)) & 32) {
            ST16(0x060C27D0, LD16(0x060C27D0) | (i + 1));
        }
        i++;
    } while (AGAIN(i < 2));
}

int f06077A8C(void)
{
    return GCALL0(0x060780A4) ? 0 : GCALL0(0x0606C5D6);
}

int f06077BFA(void)
{
    return GCALL0(0x0606BF8C);
}

int f06077C08(void)
{
    if ((unsigned char)LD8(LD32(CURRENT) + 7) < 2)
        return 0;
    return GCALL0(0x0606BE44) != 0;
}

int f06077E20(void)
{
    int r0, r4, r5, r6, r7, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077E26);
    r0 = GCALL0(0x06077ED8);
    SETPR(LD32((sp - 4)));
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    r0 = LD32(0x060D7768);
    r0 = LD8(r0 + 4);
    r0 = r0 & 255;
    if ((r0 & 192) == 0) {
        SETSP((sp - 28));
        r0 = GCALL0(0x0607884E);
        r12 = 6;
        r9 = 0x0606BA1E;
        r10 = 0x060BA98C;
        r13 = 0;
        r14 = 0x060C27EA;
        r11 = 0x060C27EE;
        do {
            r4 = LD16(r14);
            r4 = r4 & 0xFFFF;
            if (!((unsigned)r4 >= (unsigned)r12)) {
                r7 = (((r4 << 2) << 1) + r10) + r13;
                r4 = LD8(r7);
                r7 = r7 + 1;
                r5 = LD8(r7);
                r7 = r7 + 1;
                r6 = LD8(r7);
                r7 = LD8((r7 + 1));
                SETR(9, r9);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x060788F4);
                r0 = GCALL4(r9, r4, r5, r6, r7);
            }
            r14 = r14 + 2;
            r13 = r13 + 4;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r11)));
    }
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06077F9A(void)
{
    int i = 0;

    do {
        ST16(0x060C27DC + i * 2, 0);
    } while (AGAIN(++i < 6));
}

int f060780A4(void)
{
    int bits = 0;
    int p = 0x060C27DC;

    do {
        bits |= LDU16(p);
    } while (AGAIN((p += 2) < 0x060C27E8));
    return bits;
}

int f06078164(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(r4 + 20);
    SETR(14, 0x060D7768);
    SETSP((sp - 8));
    SETPR(0x06078176);
    r0 = GCALL2(0x060193B0, (r0 & 0xFFFF), 120);
    r2 = LD8(0x060C063D);
    r4 = r0;
    if ((unsigned)r0 >= (unsigned)(r2 & 255)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r1 = LD32(r14);
        ST16(70 + r1, r4);
        SETSP((sp - 8));
        r0 = GCALL0(0x0606C776);
        r4 = LD16(0x060C062C);
        SETSP((sp - 8));
        r0 = GCALL1(0x06014820, r4);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x060783D6);
        r5 = LD32(r14);
        r3 = LD32(r14);
        r5 = LD16(80 + r5);
        r2 = LD16(68 + r3);
        r4 = LD16(0x060C1AA8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x060781BA);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r2 & 0xFFFF)) + 35));
        SETSP((sp - 8));
        r0 = GCALL1(0x0600996A, 74);
        r2 = LD32(r14);
        ST16(62 + r2, 56);
        r4 = LD32(0x060D7B3C);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x0606AAC8, r4, 3);
        return r0;
    }
}

int f06078244(void)
{
    ST16(0x060C27DC + LDU16(LD32(CURRENT) + 66) * 2, 0);
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

int f06078532(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607853E);
    r0 = GCALL3(0x0606B0DE, 0x060BA974, 250, 17);
    r2 = LD32(0x060D7768);
    ST16(r2 + 18, 0);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C776);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06078598);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 128));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0606947C, 0x1E0);
    return r0;
}

int f0607881C(void)
{
    int r0, r2, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06078828);
    r0 = GCALL3(0x0606B0DE, 0x060BA980, 250, 17);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 4));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x060805BA);
    SETPR(LD32((sp - 4)));
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0x100);
    return 66;
}

void f0607884E(void)
{
    gaddr mover = LD32(MOVER_PTR);
    unsigned int dist = LDU16(mover + 50) - LDU16(LD32(CURRENT) + 80);
    int col = LDU16(mover + 10) - LDU16(0x060C27E8);

    if (dist >= 9 && dist < 20) {
        gaddr p = 0x060BA9BC + col * 2;

        ST16(0x060C27EA, LD8(p) & 255);
        ST16(0x060C27EC, LD8(p + 1) & 255);
    } else {
        ST16(0x060C27EC, 0);
        ST16(0x060C27EA, 0);
    }
}

int f06078D16(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = LD32(0x060D7768);
    r0 = LD16(70 + r14);
    if (!((r0 & r0) == 0)) {
        r4 = LD16(70 + r14);
        SETSP((sp - 8));
        r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x0606D398);
    return r0;
}

int f06078D38(void)
{
    gaddr mover = LD32(MOVER_PTR);
    gaddr cur = LD32(CURRENT);
    int s = GCALL1(0x0606CE8C, LDU16(cur + 68) & 255);
    gaddr obj;

    ST16(mover + 38, -GCALL1(0x060949D0, HELPER(s >> 11)));
    cur = LD32(CURRENT);
    ST16(cur + 68, LDU16(cur + 68) + 1);
    obj = OBJ(LDU16(LD32(CURRENT) + 70));
    ST16(obj + 16, LDU16(LD32(MOVER_PTR) + 16));
    obj = OBJ(LDU16(LD32(CURRENT) + 70));
    ST16(obj + 18, LDU16(LD32(MOVER_PTR) + 18));
    return 0;
}

void f06078DB0(void)
{
    ST16(0x060C1E48, 17);
}

void f06078DEC(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f06079416(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r11 = 0x060C1AA8;
    r12 = 0x060D7768;
    r14 = 0x060C27F6;
    r0 = LD16(0x060C27F6);
    r4 = r0;
    if (!(r0 == 4)) {
        r8 = 0x060144F4;
        r9 = 0x06068ACC;
        if (!(r4 == 5)) {
            r0 = LD16(r14);
            r10 = 1;
            if (!((r0 & r0) == 0)) {
                r0 = LD16(r14);
                if (!((r0 & 127) == 0)) {
                    r13 = 0x060D7B3C;
                    r0 = LD16(r14);
                    if (!((r0 & r0) == 0)) {
                        r0 = LD16(r14);
                        if (!(r0 == 3)) {
                            r1 = LD16(r14);
                            if (!((r1 & r1) == 0)) {
                                r0 = 0;
                            } else {
                                SETSP((sp - 32));
                                r0 = GCALL0(0x06079D30);
                                if ((r0 & r0) == 0) {
                                    r0 = 0;
                                } else {
                                    r0 = LD16(r14);
                                    ST16(r14, (r0 | 128));
                                    SETSP((sp - 32));
                                    r0 = GCALL1(r8, 0x06079DE2);
                                    r5 = LD32(r12);
                                    r4 = LD16(r11);
                                    r5 = LD16(80 + r5);
                                    SETR(10, r10);
                                    SETR(11, r11);
                                    SETR(12, r12);
                                    SETR(13, r13);
                                    SETSP((sp - 32));
                                    SETPR(0x06079660);
                                    r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                    SETSP((sp - 32));
                                    r0 = GCALL1(0x06014516, 0x0606D8B6);
                                    ST32((sp - 36), r10);
                                    r2 = LD16(r11);
                                    ST32((sp - 40), (r2 & 0xFFFF));
                                    r3 = LD32(r13);
                                    r0 = LD16(r3 + 18);
                                    ST32((sp - 44), r0);
                                    r3 = LD32(r13);
                                    r0 = LD16(r3 + 16);
                                    ST32((sp - 48), r0);
                                    r3 = LD32(r12);
                                    r2 = LD16(80 + r3);
                                    ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                    r3 = LD32(r13);
                                    r2 = LD16(40 + r3);
                                    ST32((sp - 56), (r2 & 0xFFFF));
                                    r7 = LD32(r13);
                                    r7 = LD16(46 + r7);
                                    r6 = LD32(r13);
                                    r5 = LD32(r13);
                                    r6 = LD16(44 + r6);
                                    r0 = LD16(r5 + 4);
                                    SETR(10, r10);
                                    SETSP((sp - 56));
                                    SETPR(0x060796B0);
                                    r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                    r0 = r10;
                                }
                            }
                        } else {
                            SETSP((sp - 32));
                            r0 = GCALL0(0x06079A8A);
                            if ((r0 & r0) == 0) {
                                r1 = LD16(r14);
                                if (!((r1 & r1) == 0)) {
                                    r0 = 0;
                                } else {
                                    SETSP((sp - 32));
                                    r0 = GCALL0(0x06079D30);
                                    if ((r0 & r0) == 0) {
                                        r0 = 0;
                                    } else {
                                        r0 = LD16(r14);
                                        ST16(r14, (r0 | 128));
                                        SETSP((sp - 32));
                                        r0 = GCALL1(r8, 0x06079DE2);
                                        r5 = LD32(r12);
                                        r4 = LD16(r11);
                                        r5 = LD16(80 + r5);
                                        SETR(10, r10);
                                        SETR(11, r11);
                                        SETR(12, r12);
                                        SETR(13, r13);
                                        SETSP((sp - 32));
                                        SETPR(0x06079660);
                                        r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                        SETSP((sp - 32));
                                        r0 = GCALL1(0x06014516, 0x0606D8B6);
                                        ST32((sp - 36), r10);
                                        r2 = LD16(r11);
                                        ST32((sp - 40), (r2 & 0xFFFF));
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 18);
                                        ST32((sp - 44), r0);
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 16);
                                        ST32((sp - 48), r0);
                                        r3 = LD32(r12);
                                        r2 = LD16(80 + r3);
                                        ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                        r3 = LD32(r13);
                                        r2 = LD16(40 + r3);
                                        ST32((sp - 56), (r2 & 0xFFFF));
                                        r7 = LD32(r13);
                                        r7 = LD16(46 + r7);
                                        r6 = LD32(r13);
                                        r5 = LD32(r13);
                                        r6 = LD16(44 + r6);
                                        r0 = LD16(r5 + 4);
                                        SETR(10, r10);
                                        SETSP((sp - 56));
                                        SETPR(0x060796B0);
                                        r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                        r0 = r10;
                                    }
                                }
                            } else {
                                ST16(r14, 6);
                                SETSP((sp - 32));
                                r0 = GCALL1(0x06014516, 0x06079AB4);
                                r5 = LD32(r12);
                                r4 = LD16(r11);
                                r5 = LD16(80 + r5);
                                SETR(10, r10);
                                SETR(11, r11);
                                SETR(12, r12);
                                SETR(13, r13);
                                SETSP((sp - 32));
                                SETPR(0x060795E0);
                                r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                                r3 = LD32(r12);
                                ST16(58 + r3, 28);
                                ST32((sp - 36), r10);
                                r3 = LD16(r11);
                                ST32((sp - 40), (r3 & 0xFFFF));
                                r2 = LD32(r13);
                                r0 = LD16(r2 + 18);
                                ST32((sp - 44), (r0 - 32));
                                r3 = LD32(r13);
                                r0 = LD16(r3 + 16);
                                ST32((sp - 48), r0);
                                r3 = LD32(r12);
                                r2 = LD16(80 + r3);
                                ST32((sp - 52), ((r2 & 0xFFFF) + 11));
                                r3 = LD32(r13);
                                r2 = LD16(40 + r3);
                                ST32((sp - 56), (r2 & 0xFFFF));
                                r7 = LD32(r13);
                                r6 = LD32(r13);
                                r7 = LD16(46 + r7);
                                r6 = LD16(44 + r6);
                                r5 = LD32(r13);
                                r0 = LD16(r5 + 4);
                                SETR(10, r10);
                                SETSP((sp - 56));
                                SETPR(0x06079632);
                                r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                r0 = r10;
                            }
                        }
                    } else {
                        SETSP((sp - 32));
                        r0 = GCALL0(0x0607992E);
                        if ((r0 & r0) == 0) {
                            r0 = LD16(r14);
                            if (!(r0 == 3)) {
                                r1 = LD16(r14);
                                if (!((r1 & r1) == 0)) {
                                    r0 = 0;
                                } else {
                                    SETSP((sp - 32));
                                    r0 = GCALL0(0x06079D30);
                                    if ((r0 & r0) == 0) {
                                        r0 = 0;
                                    } else {
                                        r0 = LD16(r14);
                                        ST16(r14, (r0 | 128));
                                        SETSP((sp - 32));
                                        r0 = GCALL1(r8, 0x06079DE2);
                                        r5 = LD32(r12);
                                        r4 = LD16(r11);
                                        r5 = LD16(80 + r5);
                                        SETR(10, r10);
                                        SETR(11, r11);
                                        SETR(12, r12);
                                        SETR(13, r13);
                                        SETSP((sp - 32));
                                        SETPR(0x06079660);
                                        r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                        SETSP((sp - 32));
                                        r0 = GCALL1(0x06014516, 0x0606D8B6);
                                        ST32((sp - 36), r10);
                                        r2 = LD16(r11);
                                        ST32((sp - 40), (r2 & 0xFFFF));
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 18);
                                        ST32((sp - 44), r0);
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 16);
                                        ST32((sp - 48), r0);
                                        r3 = LD32(r12);
                                        r2 = LD16(80 + r3);
                                        ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                        r3 = LD32(r13);
                                        r2 = LD16(40 + r3);
                                        ST32((sp - 56), (r2 & 0xFFFF));
                                        r7 = LD32(r13);
                                        r7 = LD16(46 + r7);
                                        r6 = LD32(r13);
                                        r5 = LD32(r13);
                                        r6 = LD16(44 + r6);
                                        r0 = LD16(r5 + 4);
                                        SETR(10, r10);
                                        SETSP((sp - 56));
                                        SETPR(0x060796B0);
                                        r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                        r0 = r10;
                                    }
                                }
                            } else {
                                SETSP((sp - 32));
                                r0 = GCALL0(0x06079A8A);
                                if ((r0 & r0) == 0) {
                                    r1 = LD16(r14);
                                    if (!((r1 & r1) == 0)) {
                                        r0 = 0;
                                    } else {
                                        SETSP((sp - 32));
                                        r0 = GCALL0(0x06079D30);
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                        } else {
                                            r0 = LD16(r14);
                                            ST16(r14, (r0 | 128));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(r8, 0x06079DE2);
                                            r5 = LD32(r12);
                                            r4 = LD16(r11);
                                            r5 = LD16(80 + r5);
                                            SETR(10, r10);
                                            SETR(11, r11);
                                            SETR(12, r12);
                                            SETR(13, r13);
                                            SETSP((sp - 32));
                                            SETPR(0x06079660);
                                            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(0x06014516, 0x0606D8B6);
                                            ST32((sp - 36), r10);
                                            r2 = LD16(r11);
                                            ST32((sp - 40), (r2 & 0xFFFF));
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 18);
                                            ST32((sp - 44), r0);
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 16);
                                            ST32((sp - 48), r0);
                                            r3 = LD32(r12);
                                            r2 = LD16(80 + r3);
                                            ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                            r3 = LD32(r13);
                                            r2 = LD16(40 + r3);
                                            ST32((sp - 56), (r2 & 0xFFFF));
                                            r7 = LD32(r13);
                                            r7 = LD16(46 + r7);
                                            r6 = LD32(r13);
                                            r5 = LD32(r13);
                                            r6 = LD16(44 + r6);
                                            r0 = LD16(r5 + 4);
                                            SETR(10, r10);
                                            SETSP((sp - 56));
                                            SETPR(0x060796B0);
                                            r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                            r0 = r10;
                                        }
                                    }
                                } else {
                                    ST16(r14, 6);
                                    SETSP((sp - 32));
                                    r0 = GCALL1(0x06014516, 0x06079AB4);
                                    r5 = LD32(r12);
                                    r4 = LD16(r11);
                                    r5 = LD16(80 + r5);
                                    SETR(10, r10);
                                    SETR(11, r11);
                                    SETR(12, r12);
                                    SETR(13, r13);
                                    SETSP((sp - 32));
                                    SETPR(0x060795E0);
                                    r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                                    r3 = LD32(r12);
                                    ST16(58 + r3, 28);
                                    ST32((sp - 36), r10);
                                    r3 = LD16(r11);
                                    ST32((sp - 40), (r3 & 0xFFFF));
                                    r2 = LD32(r13);
                                    r0 = LD16(r2 + 18);
                                    ST32((sp - 44), (r0 - 32));
                                    r3 = LD32(r13);
                                    r0 = LD16(r3 + 16);
                                    ST32((sp - 48), r0);
                                    r3 = LD32(r12);
                                    r2 = LD16(80 + r3);
                                    ST32((sp - 52), ((r2 & 0xFFFF) + 11));
                                    r3 = LD32(r13);
                                    r2 = LD16(40 + r3);
                                    ST32((sp - 56), (r2 & 0xFFFF));
                                    r7 = LD32(r13);
                                    r6 = LD32(r13);
                                    r7 = LD16(46 + r7);
                                    r6 = LD16(44 + r6);
                                    r5 = LD32(r13);
                                    r0 = LD16(r5 + 4);
                                    SETR(10, r10);
                                    SETSP((sp - 56));
                                    SETPR(0x06079632);
                                    r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                    r0 = r10;
                                }
                            }
                        } else {
                            ST16(r14, 3);
                            SETSP((sp - 32));
                            r0 = GCALL1(r8, 0x06079956);
                            r4 = LD16(r11);
                            r5 = LD32(r12);
                            r5 = LD16(80 + r5);
                            SETR(13, r13);
                            SETSP((sp - 32));
                            SETPR(0x06079506);
                            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                            SETSP((sp - 32));
                            r0 = GCALL1(0x06014516, 0x0606D8B6);
                            r2 = LD32(r13);
                            ST16(48 + r2, 4);
                            SETSP((sp - 32));
                            r0 = GCALL0(0x0606C7EE);
                            SETSP((sp - 32));
                            SETPR(0x06079522);
                            r0 = GCALL0(0x0607AB38);
                            r0 = 1;
                        }
                    }
                } else {
                    SETSP((sp - 32));
                    r0 = GCALL0(0x0607A438);
                    if ((r0 & r0) == 0) {
                        r13 = 0x060D7B3C;
                        r0 = LD16(r14);
                        if (!((r0 & r0) == 0)) {
                            r0 = LD16(r14);
                            if (!(r0 == 3)) {
                                r1 = LD16(r14);
                                if (!((r1 & r1) == 0)) {
                                    r0 = 0;
                                } else {
                                    SETSP((sp - 32));
                                    r0 = GCALL0(0x06079D30);
                                    if ((r0 & r0) == 0) {
                                        r0 = 0;
                                    } else {
                                        r0 = LD16(r14);
                                        ST16(r14, (r0 | 128));
                                        SETSP((sp - 32));
                                        r0 = GCALL1(r8, 0x06079DE2);
                                        r5 = LD32(r12);
                                        r4 = LD16(r11);
                                        r5 = LD16(80 + r5);
                                        SETR(10, r10);
                                        SETR(11, r11);
                                        SETR(12, r12);
                                        SETR(13, r13);
                                        SETSP((sp - 32));
                                        SETPR(0x06079660);
                                        r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                        SETSP((sp - 32));
                                        r0 = GCALL1(0x06014516, 0x0606D8B6);
                                        ST32((sp - 36), r10);
                                        r2 = LD16(r11);
                                        ST32((sp - 40), (r2 & 0xFFFF));
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 18);
                                        ST32((sp - 44), r0);
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 16);
                                        ST32((sp - 48), r0);
                                        r3 = LD32(r12);
                                        r2 = LD16(80 + r3);
                                        ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                        r3 = LD32(r13);
                                        r2 = LD16(40 + r3);
                                        ST32((sp - 56), (r2 & 0xFFFF));
                                        r7 = LD32(r13);
                                        r7 = LD16(46 + r7);
                                        r6 = LD32(r13);
                                        r5 = LD32(r13);
                                        r6 = LD16(44 + r6);
                                        r0 = LD16(r5 + 4);
                                        SETR(10, r10);
                                        SETSP((sp - 56));
                                        SETPR(0x060796B0);
                                        r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                        r0 = r10;
                                    }
                                }
                            } else {
                                SETSP((sp - 32));
                                r0 = GCALL0(0x06079A8A);
                                if ((r0 & r0) == 0) {
                                    r1 = LD16(r14);
                                    if (!((r1 & r1) == 0)) {
                                        r0 = 0;
                                    } else {
                                        SETSP((sp - 32));
                                        r0 = GCALL0(0x06079D30);
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                        } else {
                                            r0 = LD16(r14);
                                            ST16(r14, (r0 | 128));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(r8, 0x06079DE2);
                                            r5 = LD32(r12);
                                            r4 = LD16(r11);
                                            r5 = LD16(80 + r5);
                                            SETR(10, r10);
                                            SETR(11, r11);
                                            SETR(12, r12);
                                            SETR(13, r13);
                                            SETSP((sp - 32));
                                            SETPR(0x06079660);
                                            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(0x06014516, 0x0606D8B6);
                                            ST32((sp - 36), r10);
                                            r2 = LD16(r11);
                                            ST32((sp - 40), (r2 & 0xFFFF));
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 18);
                                            ST32((sp - 44), r0);
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 16);
                                            ST32((sp - 48), r0);
                                            r3 = LD32(r12);
                                            r2 = LD16(80 + r3);
                                            ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                            r3 = LD32(r13);
                                            r2 = LD16(40 + r3);
                                            ST32((sp - 56), (r2 & 0xFFFF));
                                            r7 = LD32(r13);
                                            r7 = LD16(46 + r7);
                                            r6 = LD32(r13);
                                            r5 = LD32(r13);
                                            r6 = LD16(44 + r6);
                                            r0 = LD16(r5 + 4);
                                            SETR(10, r10);
                                            SETSP((sp - 56));
                                            SETPR(0x060796B0);
                                            r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                            r0 = r10;
                                        }
                                    }
                                } else {
                                    ST16(r14, 6);
                                    SETSP((sp - 32));
                                    r0 = GCALL1(0x06014516, 0x06079AB4);
                                    r5 = LD32(r12);
                                    r4 = LD16(r11);
                                    r5 = LD16(80 + r5);
                                    SETR(10, r10);
                                    SETR(11, r11);
                                    SETR(12, r12);
                                    SETR(13, r13);
                                    SETSP((sp - 32));
                                    SETPR(0x060795E0);
                                    r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                                    r3 = LD32(r12);
                                    ST16(58 + r3, 28);
                                    ST32((sp - 36), r10);
                                    r3 = LD16(r11);
                                    ST32((sp - 40), (r3 & 0xFFFF));
                                    r2 = LD32(r13);
                                    r0 = LD16(r2 + 18);
                                    ST32((sp - 44), (r0 - 32));
                                    r3 = LD32(r13);
                                    r0 = LD16(r3 + 16);
                                    ST32((sp - 48), r0);
                                    r3 = LD32(r12);
                                    r2 = LD16(80 + r3);
                                    ST32((sp - 52), ((r2 & 0xFFFF) + 11));
                                    r3 = LD32(r13);
                                    r2 = LD16(40 + r3);
                                    ST32((sp - 56), (r2 & 0xFFFF));
                                    r7 = LD32(r13);
                                    r6 = LD32(r13);
                                    r7 = LD16(46 + r7);
                                    r6 = LD16(44 + r6);
                                    r5 = LD32(r13);
                                    r0 = LD16(r5 + 4);
                                    SETR(10, r10);
                                    SETSP((sp - 56));
                                    SETPR(0x06079632);
                                    r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                    r0 = r10;
                                }
                            }
                        } else {
                            SETSP((sp - 32));
                            r0 = GCALL0(0x0607992E);
                            if ((r0 & r0) == 0) {
                                r0 = LD16(r14);
                                if (!(r0 == 3)) {
                                    r1 = LD16(r14);
                                    if (!((r1 & r1) == 0)) {
                                        r0 = 0;
                                    } else {
                                        SETSP((sp - 32));
                                        r0 = GCALL0(0x06079D30);
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                        } else {
                                            r0 = LD16(r14);
                                            ST16(r14, (r0 | 128));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(r8, 0x06079DE2);
                                            r5 = LD32(r12);
                                            r4 = LD16(r11);
                                            r5 = LD16(80 + r5);
                                            SETR(10, r10);
                                            SETR(11, r11);
                                            SETR(12, r12);
                                            SETR(13, r13);
                                            SETSP((sp - 32));
                                            SETPR(0x06079660);
                                            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(0x06014516, 0x0606D8B6);
                                            ST32((sp - 36), r10);
                                            r2 = LD16(r11);
                                            ST32((sp - 40), (r2 & 0xFFFF));
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 18);
                                            ST32((sp - 44), r0);
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 16);
                                            ST32((sp - 48), r0);
                                            r3 = LD32(r12);
                                            r2 = LD16(80 + r3);
                                            ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                            r3 = LD32(r13);
                                            r2 = LD16(40 + r3);
                                            ST32((sp - 56), (r2 & 0xFFFF));
                                            r7 = LD32(r13);
                                            r7 = LD16(46 + r7);
                                            r6 = LD32(r13);
                                            r5 = LD32(r13);
                                            r6 = LD16(44 + r6);
                                            r0 = LD16(r5 + 4);
                                            SETR(10, r10);
                                            SETSP((sp - 56));
                                            SETPR(0x060796B0);
                                            r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                            r0 = r10;
                                        }
                                    }
                                } else {
                                    SETSP((sp - 32));
                                    r0 = GCALL0(0x06079A8A);
                                    if ((r0 & r0) == 0) {
                                        r1 = LD16(r14);
                                        if (!((r1 & r1) == 0)) {
                                            r0 = 0;
                                        } else {
                                            SETSP((sp - 32));
                                            r0 = GCALL0(0x06079D30);
                                            if ((r0 & r0) == 0) {
                                                r0 = 0;
                                            } else {
                                                r0 = LD16(r14);
                                                ST16(r14, (r0 | 128));
                                                SETSP((sp - 32));
                                                r0 = GCALL1(r8, 0x06079DE2);
                                                r5 = LD32(r12);
                                                r4 = LD16(r11);
                                                r5 = LD16(80 + r5);
                                                SETR(10, r10);
                                                SETR(11, r11);
                                                SETR(12, r12);
                                                SETR(13, r13);
                                                SETSP((sp - 32));
                                                SETPR(0x06079660);
                                                r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                                SETSP((sp - 32));
                                                r0 = GCALL1(0x06014516, 0x0606D8B6);
                                                ST32((sp - 36), r10);
                                                r2 = LD16(r11);
                                                ST32((sp - 40), (r2 & 0xFFFF));
                                                r3 = LD32(r13);
                                                r0 = LD16(r3 + 18);
                                                ST32((sp - 44), r0);
                                                r3 = LD32(r13);
                                                r0 = LD16(r3 + 16);
                                                ST32((sp - 48), r0);
                                                r3 = LD32(r12);
                                                r2 = LD16(80 + r3);
                                                ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                                r3 = LD32(r13);
                                                r2 = LD16(40 + r3);
                                                ST32((sp - 56), (r2 & 0xFFFF));
                                                r7 = LD32(r13);
                                                r7 = LD16(46 + r7);
                                                r6 = LD32(r13);
                                                r5 = LD32(r13);
                                                r6 = LD16(44 + r6);
                                                r0 = LD16(r5 + 4);
                                                SETR(10, r10);
                                                SETSP((sp - 56));
                                                SETPR(0x060796B0);
                                                r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                                r0 = r10;
                                            }
                                        }
                                    } else {
                                        ST16(r14, 6);
                                        SETSP((sp - 32));
                                        r0 = GCALL1(0x06014516, 0x06079AB4);
                                        r5 = LD32(r12);
                                        r4 = LD16(r11);
                                        r5 = LD16(80 + r5);
                                        SETR(10, r10);
                                        SETR(11, r11);
                                        SETR(12, r12);
                                        SETR(13, r13);
                                        SETSP((sp - 32));
                                        SETPR(0x060795E0);
                                        r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                                        r3 = LD32(r12);
                                        ST16(58 + r3, 28);
                                        ST32((sp - 36), r10);
                                        r3 = LD16(r11);
                                        ST32((sp - 40), (r3 & 0xFFFF));
                                        r2 = LD32(r13);
                                        r0 = LD16(r2 + 18);
                                        ST32((sp - 44), (r0 - 32));
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 16);
                                        ST32((sp - 48), r0);
                                        r3 = LD32(r12);
                                        r2 = LD16(80 + r3);
                                        ST32((sp - 52), ((r2 & 0xFFFF) + 11));
                                        r3 = LD32(r13);
                                        r2 = LD16(40 + r3);
                                        ST32((sp - 56), (r2 & 0xFFFF));
                                        r7 = LD32(r13);
                                        r6 = LD32(r13);
                                        r7 = LD16(46 + r7);
                                        r6 = LD16(44 + r6);
                                        r5 = LD32(r13);
                                        r0 = LD16(r5 + 4);
                                        SETR(10, r10);
                                        SETSP((sp - 56));
                                        SETPR(0x06079632);
                                        r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                        r0 = r10;
                                    }
                                }
                            } else {
                                ST16(r14, 3);
                                SETSP((sp - 32));
                                r0 = GCALL1(r8, 0x06079956);
                                r4 = LD16(r11);
                                r5 = LD32(r12);
                                r5 = LD16(80 + r5);
                                SETR(13, r13);
                                SETSP((sp - 32));
                                SETPR(0x06079506);
                                r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                SETSP((sp - 32));
                                r0 = GCALL1(0x06014516, 0x0606D8B6);
                                r2 = LD32(r13);
                                ST16(48 + r2, 4);
                                SETSP((sp - 32));
                                r0 = GCALL0(0x0606C7EE);
                                SETSP((sp - 32));
                                SETPR(0x06079522);
                                r0 = GCALL0(0x0607AB38);
                                r0 = 1;
                            }
                        }
                    } else {
                        r0 = LD16(r14);
                        ST16(r14, (r0 | 2));
                        SETSP((sp - 32));
                        r0 = GCALL0(0x0600A0B8);
                        ST16(0x060C2800, (r0 & 1));
                        SETSP((sp - 32));
                        r0 = GCALL1(0x0600A0EC, 9);
                        r2 = LD32((r0 << 2) + 0x060BAB4C);
                        ST16(0x060C2802, r2);
                        SETSP((sp - 32));
                        r0 = GCALL1(r8, 0x0607A4C0);
                        r3 = LD32(r12);
                        r5 = LD32(r12);
                        r4 = LD16(r11);
                        r5 = LD16(80 + r5);
                        r0 = LD8(r3 + 6);
                        SETSP((sp - 32));
                        SETPR(0x060794D2);
                        r0 = GCALL2(r9, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 21));
                        SETSP((sp - 32));
                        r0 = GCALL1(0x06014516, 0x0606D88C);
                        r0 = 1;
                    }
                }
            } else {
                SETSP((sp - 32));
                r0 = GCALL0(0x060796CE);
                if ((r0 & r0) == 0) {
                    r0 = LD16(r14);
                    if (!((r0 & 127) == 0)) {
                        r13 = 0x060D7B3C;
                        r0 = LD16(r14);
                        if (!((r0 & r0) == 0)) {
                            r0 = LD16(r14);
                            if (!(r0 == 3)) {
                                r1 = LD16(r14);
                                if (!((r1 & r1) == 0)) {
                                    r0 = 0;
                                } else {
                                    SETSP((sp - 32));
                                    r0 = GCALL0(0x06079D30);
                                    if ((r0 & r0) == 0) {
                                        r0 = 0;
                                    } else {
                                        r0 = LD16(r14);
                                        ST16(r14, (r0 | 128));
                                        SETSP((sp - 32));
                                        r0 = GCALL1(r8, 0x06079DE2);
                                        r5 = LD32(r12);
                                        r4 = LD16(r11);
                                        r5 = LD16(80 + r5);
                                        SETR(10, r10);
                                        SETR(11, r11);
                                        SETR(12, r12);
                                        SETR(13, r13);
                                        SETSP((sp - 32));
                                        SETPR(0x06079660);
                                        r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                        SETSP((sp - 32));
                                        r0 = GCALL1(0x06014516, 0x0606D8B6);
                                        ST32((sp - 36), r10);
                                        r2 = LD16(r11);
                                        ST32((sp - 40), (r2 & 0xFFFF));
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 18);
                                        ST32((sp - 44), r0);
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 16);
                                        ST32((sp - 48), r0);
                                        r3 = LD32(r12);
                                        r2 = LD16(80 + r3);
                                        ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                        r3 = LD32(r13);
                                        r2 = LD16(40 + r3);
                                        ST32((sp - 56), (r2 & 0xFFFF));
                                        r7 = LD32(r13);
                                        r7 = LD16(46 + r7);
                                        r6 = LD32(r13);
                                        r5 = LD32(r13);
                                        r6 = LD16(44 + r6);
                                        r0 = LD16(r5 + 4);
                                        SETR(10, r10);
                                        SETSP((sp - 56));
                                        SETPR(0x060796B0);
                                        r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                        r0 = r10;
                                    }
                                }
                            } else {
                                SETSP((sp - 32));
                                r0 = GCALL0(0x06079A8A);
                                if ((r0 & r0) == 0) {
                                    r1 = LD16(r14);
                                    if (!((r1 & r1) == 0)) {
                                        r0 = 0;
                                    } else {
                                        SETSP((sp - 32));
                                        r0 = GCALL0(0x06079D30);
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                        } else {
                                            r0 = LD16(r14);
                                            ST16(r14, (r0 | 128));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(r8, 0x06079DE2);
                                            r5 = LD32(r12);
                                            r4 = LD16(r11);
                                            r5 = LD16(80 + r5);
                                            SETR(10, r10);
                                            SETR(11, r11);
                                            SETR(12, r12);
                                            SETR(13, r13);
                                            SETSP((sp - 32));
                                            SETPR(0x06079660);
                                            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(0x06014516, 0x0606D8B6);
                                            ST32((sp - 36), r10);
                                            r2 = LD16(r11);
                                            ST32((sp - 40), (r2 & 0xFFFF));
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 18);
                                            ST32((sp - 44), r0);
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 16);
                                            ST32((sp - 48), r0);
                                            r3 = LD32(r12);
                                            r2 = LD16(80 + r3);
                                            ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                            r3 = LD32(r13);
                                            r2 = LD16(40 + r3);
                                            ST32((sp - 56), (r2 & 0xFFFF));
                                            r7 = LD32(r13);
                                            r7 = LD16(46 + r7);
                                            r6 = LD32(r13);
                                            r5 = LD32(r13);
                                            r6 = LD16(44 + r6);
                                            r0 = LD16(r5 + 4);
                                            SETR(10, r10);
                                            SETSP((sp - 56));
                                            SETPR(0x060796B0);
                                            r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                            r0 = r10;
                                        }
                                    }
                                } else {
                                    ST16(r14, 6);
                                    SETSP((sp - 32));
                                    r0 = GCALL1(0x06014516, 0x06079AB4);
                                    r5 = LD32(r12);
                                    r4 = LD16(r11);
                                    r5 = LD16(80 + r5);
                                    SETR(10, r10);
                                    SETR(11, r11);
                                    SETR(12, r12);
                                    SETR(13, r13);
                                    SETSP((sp - 32));
                                    SETPR(0x060795E0);
                                    r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                                    r3 = LD32(r12);
                                    ST16(58 + r3, 28);
                                    ST32((sp - 36), r10);
                                    r3 = LD16(r11);
                                    ST32((sp - 40), (r3 & 0xFFFF));
                                    r2 = LD32(r13);
                                    r0 = LD16(r2 + 18);
                                    ST32((sp - 44), (r0 - 32));
                                    r3 = LD32(r13);
                                    r0 = LD16(r3 + 16);
                                    ST32((sp - 48), r0);
                                    r3 = LD32(r12);
                                    r2 = LD16(80 + r3);
                                    ST32((sp - 52), ((r2 & 0xFFFF) + 11));
                                    r3 = LD32(r13);
                                    r2 = LD16(40 + r3);
                                    ST32((sp - 56), (r2 & 0xFFFF));
                                    r7 = LD32(r13);
                                    r6 = LD32(r13);
                                    r7 = LD16(46 + r7);
                                    r6 = LD16(44 + r6);
                                    r5 = LD32(r13);
                                    r0 = LD16(r5 + 4);
                                    SETR(10, r10);
                                    SETSP((sp - 56));
                                    SETPR(0x06079632);
                                    r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                    r0 = r10;
                                }
                            }
                        } else {
                            SETSP((sp - 32));
                            r0 = GCALL0(0x0607992E);
                            if ((r0 & r0) == 0) {
                                r0 = LD16(r14);
                                if (!(r0 == 3)) {
                                    r1 = LD16(r14);
                                    if (!((r1 & r1) == 0)) {
                                        r0 = 0;
                                    } else {
                                        SETSP((sp - 32));
                                        r0 = GCALL0(0x06079D30);
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                        } else {
                                            r0 = LD16(r14);
                                            ST16(r14, (r0 | 128));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(r8, 0x06079DE2);
                                            r5 = LD32(r12);
                                            r4 = LD16(r11);
                                            r5 = LD16(80 + r5);
                                            SETR(10, r10);
                                            SETR(11, r11);
                                            SETR(12, r12);
                                            SETR(13, r13);
                                            SETSP((sp - 32));
                                            SETPR(0x06079660);
                                            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(0x06014516, 0x0606D8B6);
                                            ST32((sp - 36), r10);
                                            r2 = LD16(r11);
                                            ST32((sp - 40), (r2 & 0xFFFF));
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 18);
                                            ST32((sp - 44), r0);
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 16);
                                            ST32((sp - 48), r0);
                                            r3 = LD32(r12);
                                            r2 = LD16(80 + r3);
                                            ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                            r3 = LD32(r13);
                                            r2 = LD16(40 + r3);
                                            ST32((sp - 56), (r2 & 0xFFFF));
                                            r7 = LD32(r13);
                                            r7 = LD16(46 + r7);
                                            r6 = LD32(r13);
                                            r5 = LD32(r13);
                                            r6 = LD16(44 + r6);
                                            r0 = LD16(r5 + 4);
                                            SETR(10, r10);
                                            SETSP((sp - 56));
                                            SETPR(0x060796B0);
                                            r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                            r0 = r10;
                                        }
                                    }
                                } else {
                                    SETSP((sp - 32));
                                    r0 = GCALL0(0x06079A8A);
                                    if ((r0 & r0) == 0) {
                                        r1 = LD16(r14);
                                        if (!((r1 & r1) == 0)) {
                                            r0 = 0;
                                        } else {
                                            SETSP((sp - 32));
                                            r0 = GCALL0(0x06079D30);
                                            if ((r0 & r0) == 0) {
                                                r0 = 0;
                                            } else {
                                                r0 = LD16(r14);
                                                ST16(r14, (r0 | 128));
                                                SETSP((sp - 32));
                                                r0 = GCALL1(r8, 0x06079DE2);
                                                r5 = LD32(r12);
                                                r4 = LD16(r11);
                                                r5 = LD16(80 + r5);
                                                SETR(10, r10);
                                                SETR(11, r11);
                                                SETR(12, r12);
                                                SETR(13, r13);
                                                SETSP((sp - 32));
                                                SETPR(0x06079660);
                                                r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                                SETSP((sp - 32));
                                                r0 = GCALL1(0x06014516, 0x0606D8B6);
                                                ST32((sp - 36), r10);
                                                r2 = LD16(r11);
                                                ST32((sp - 40), (r2 & 0xFFFF));
                                                r3 = LD32(r13);
                                                r0 = LD16(r3 + 18);
                                                ST32((sp - 44), r0);
                                                r3 = LD32(r13);
                                                r0 = LD16(r3 + 16);
                                                ST32((sp - 48), r0);
                                                r3 = LD32(r12);
                                                r2 = LD16(80 + r3);
                                                ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                                r3 = LD32(r13);
                                                r2 = LD16(40 + r3);
                                                ST32((sp - 56), (r2 & 0xFFFF));
                                                r7 = LD32(r13);
                                                r7 = LD16(46 + r7);
                                                r6 = LD32(r13);
                                                r5 = LD32(r13);
                                                r6 = LD16(44 + r6);
                                                r0 = LD16(r5 + 4);
                                                SETR(10, r10);
                                                SETSP((sp - 56));
                                                SETPR(0x060796B0);
                                                r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                                r0 = r10;
                                            }
                                        }
                                    } else {
                                        ST16(r14, 6);
                                        SETSP((sp - 32));
                                        r0 = GCALL1(0x06014516, 0x06079AB4);
                                        r5 = LD32(r12);
                                        r4 = LD16(r11);
                                        r5 = LD16(80 + r5);
                                        SETR(10, r10);
                                        SETR(11, r11);
                                        SETR(12, r12);
                                        SETR(13, r13);
                                        SETSP((sp - 32));
                                        SETPR(0x060795E0);
                                        r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                                        r3 = LD32(r12);
                                        ST16(58 + r3, 28);
                                        ST32((sp - 36), r10);
                                        r3 = LD16(r11);
                                        ST32((sp - 40), (r3 & 0xFFFF));
                                        r2 = LD32(r13);
                                        r0 = LD16(r2 + 18);
                                        ST32((sp - 44), (r0 - 32));
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 16);
                                        ST32((sp - 48), r0);
                                        r3 = LD32(r12);
                                        r2 = LD16(80 + r3);
                                        ST32((sp - 52), ((r2 & 0xFFFF) + 11));
                                        r3 = LD32(r13);
                                        r2 = LD16(40 + r3);
                                        ST32((sp - 56), (r2 & 0xFFFF));
                                        r7 = LD32(r13);
                                        r6 = LD32(r13);
                                        r7 = LD16(46 + r7);
                                        r6 = LD16(44 + r6);
                                        r5 = LD32(r13);
                                        r0 = LD16(r5 + 4);
                                        SETR(10, r10);
                                        SETSP((sp - 56));
                                        SETPR(0x06079632);
                                        r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                        r0 = r10;
                                    }
                                }
                            } else {
                                ST16(r14, 3);
                                SETSP((sp - 32));
                                r0 = GCALL1(r8, 0x06079956);
                                r4 = LD16(r11);
                                r5 = LD32(r12);
                                r5 = LD16(80 + r5);
                                SETR(13, r13);
                                SETSP((sp - 32));
                                SETPR(0x06079506);
                                r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                SETSP((sp - 32));
                                r0 = GCALL1(0x06014516, 0x0606D8B6);
                                r2 = LD32(r13);
                                ST16(48 + r2, 4);
                                SETSP((sp - 32));
                                r0 = GCALL0(0x0606C7EE);
                                SETSP((sp - 32));
                                SETPR(0x06079522);
                                r0 = GCALL0(0x0607AB38);
                                r0 = 1;
                            }
                        }
                    } else {
                        SETSP((sp - 32));
                        r0 = GCALL0(0x0607A438);
                        if ((r0 & r0) == 0) {
                            r13 = 0x060D7B3C;
                            r0 = LD16(r14);
                            if (!((r0 & r0) == 0)) {
                                r0 = LD16(r14);
                                if (!(r0 == 3)) {
                                    r1 = LD16(r14);
                                    if (!((r1 & r1) == 0)) {
                                        r0 = 0;
                                    } else {
                                        SETSP((sp - 32));
                                        r0 = GCALL0(0x06079D30);
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                        } else {
                                            r0 = LD16(r14);
                                            ST16(r14, (r0 | 128));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(r8, 0x06079DE2);
                                            r5 = LD32(r12);
                                            r4 = LD16(r11);
                                            r5 = LD16(80 + r5);
                                            SETR(10, r10);
                                            SETR(11, r11);
                                            SETR(12, r12);
                                            SETR(13, r13);
                                            SETSP((sp - 32));
                                            SETPR(0x06079660);
                                            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                            SETSP((sp - 32));
                                            r0 = GCALL1(0x06014516, 0x0606D8B6);
                                            ST32((sp - 36), r10);
                                            r2 = LD16(r11);
                                            ST32((sp - 40), (r2 & 0xFFFF));
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 18);
                                            ST32((sp - 44), r0);
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 16);
                                            ST32((sp - 48), r0);
                                            r3 = LD32(r12);
                                            r2 = LD16(80 + r3);
                                            ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                            r3 = LD32(r13);
                                            r2 = LD16(40 + r3);
                                            ST32((sp - 56), (r2 & 0xFFFF));
                                            r7 = LD32(r13);
                                            r7 = LD16(46 + r7);
                                            r6 = LD32(r13);
                                            r5 = LD32(r13);
                                            r6 = LD16(44 + r6);
                                            r0 = LD16(r5 + 4);
                                            SETR(10, r10);
                                            SETSP((sp - 56));
                                            SETPR(0x060796B0);
                                            r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                            r0 = r10;
                                        }
                                    }
                                } else {
                                    SETSP((sp - 32));
                                    r0 = GCALL0(0x06079A8A);
                                    if ((r0 & r0) == 0) {
                                        r1 = LD16(r14);
                                        if (!((r1 & r1) == 0)) {
                                            r0 = 0;
                                        } else {
                                            SETSP((sp - 32));
                                            r0 = GCALL0(0x06079D30);
                                            if ((r0 & r0) == 0) {
                                                r0 = 0;
                                            } else {
                                                r0 = LD16(r14);
                                                ST16(r14, (r0 | 128));
                                                SETSP((sp - 32));
                                                r0 = GCALL1(r8, 0x06079DE2);
                                                r5 = LD32(r12);
                                                r4 = LD16(r11);
                                                r5 = LD16(80 + r5);
                                                SETR(10, r10);
                                                SETR(11, r11);
                                                SETR(12, r12);
                                                SETR(13, r13);
                                                SETSP((sp - 32));
                                                SETPR(0x06079660);
                                                r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                                SETSP((sp - 32));
                                                r0 = GCALL1(0x06014516, 0x0606D8B6);
                                                ST32((sp - 36), r10);
                                                r2 = LD16(r11);
                                                ST32((sp - 40), (r2 & 0xFFFF));
                                                r3 = LD32(r13);
                                                r0 = LD16(r3 + 18);
                                                ST32((sp - 44), r0);
                                                r3 = LD32(r13);
                                                r0 = LD16(r3 + 16);
                                                ST32((sp - 48), r0);
                                                r3 = LD32(r12);
                                                r2 = LD16(80 + r3);
                                                ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                                r3 = LD32(r13);
                                                r2 = LD16(40 + r3);
                                                ST32((sp - 56), (r2 & 0xFFFF));
                                                r7 = LD32(r13);
                                                r7 = LD16(46 + r7);
                                                r6 = LD32(r13);
                                                r5 = LD32(r13);
                                                r6 = LD16(44 + r6);
                                                r0 = LD16(r5 + 4);
                                                SETR(10, r10);
                                                SETSP((sp - 56));
                                                SETPR(0x060796B0);
                                                r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                                r0 = r10;
                                            }
                                        }
                                    } else {
                                        ST16(r14, 6);
                                        SETSP((sp - 32));
                                        r0 = GCALL1(0x06014516, 0x06079AB4);
                                        r5 = LD32(r12);
                                        r4 = LD16(r11);
                                        r5 = LD16(80 + r5);
                                        SETR(10, r10);
                                        SETR(11, r11);
                                        SETR(12, r12);
                                        SETR(13, r13);
                                        SETSP((sp - 32));
                                        SETPR(0x060795E0);
                                        r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                                        r3 = LD32(r12);
                                        ST16(58 + r3, 28);
                                        ST32((sp - 36), r10);
                                        r3 = LD16(r11);
                                        ST32((sp - 40), (r3 & 0xFFFF));
                                        r2 = LD32(r13);
                                        r0 = LD16(r2 + 18);
                                        ST32((sp - 44), (r0 - 32));
                                        r3 = LD32(r13);
                                        r0 = LD16(r3 + 16);
                                        ST32((sp - 48), r0);
                                        r3 = LD32(r12);
                                        r2 = LD16(80 + r3);
                                        ST32((sp - 52), ((r2 & 0xFFFF) + 11));
                                        r3 = LD32(r13);
                                        r2 = LD16(40 + r3);
                                        ST32((sp - 56), (r2 & 0xFFFF));
                                        r7 = LD32(r13);
                                        r6 = LD32(r13);
                                        r7 = LD16(46 + r7);
                                        r6 = LD16(44 + r6);
                                        r5 = LD32(r13);
                                        r0 = LD16(r5 + 4);
                                        SETR(10, r10);
                                        SETSP((sp - 56));
                                        SETPR(0x06079632);
                                        r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                        r0 = r10;
                                    }
                                }
                            } else {
                                SETSP((sp - 32));
                                r0 = GCALL0(0x0607992E);
                                if ((r0 & r0) == 0) {
                                    r0 = LD16(r14);
                                    if (!(r0 == 3)) {
                                        r1 = LD16(r14);
                                        if (!((r1 & r1) == 0)) {
                                            r0 = 0;
                                        } else {
                                            SETSP((sp - 32));
                                            r0 = GCALL0(0x06079D30);
                                            if ((r0 & r0) == 0) {
                                                r0 = 0;
                                            } else {
                                                r0 = LD16(r14);
                                                ST16(r14, (r0 | 128));
                                                SETSP((sp - 32));
                                                r0 = GCALL1(r8, 0x06079DE2);
                                                r5 = LD32(r12);
                                                r4 = LD16(r11);
                                                r5 = LD16(80 + r5);
                                                SETR(10, r10);
                                                SETR(11, r11);
                                                SETR(12, r12);
                                                SETR(13, r13);
                                                SETSP((sp - 32));
                                                SETPR(0x06079660);
                                                r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                                SETSP((sp - 32));
                                                r0 = GCALL1(0x06014516, 0x0606D8B6);
                                                ST32((sp - 36), r10);
                                                r2 = LD16(r11);
                                                ST32((sp - 40), (r2 & 0xFFFF));
                                                r3 = LD32(r13);
                                                r0 = LD16(r3 + 18);
                                                ST32((sp - 44), r0);
                                                r3 = LD32(r13);
                                                r0 = LD16(r3 + 16);
                                                ST32((sp - 48), r0);
                                                r3 = LD32(r12);
                                                r2 = LD16(80 + r3);
                                                ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                                r3 = LD32(r13);
                                                r2 = LD16(40 + r3);
                                                ST32((sp - 56), (r2 & 0xFFFF));
                                                r7 = LD32(r13);
                                                r7 = LD16(46 + r7);
                                                r6 = LD32(r13);
                                                r5 = LD32(r13);
                                                r6 = LD16(44 + r6);
                                                r0 = LD16(r5 + 4);
                                                SETR(10, r10);
                                                SETSP((sp - 56));
                                                SETPR(0x060796B0);
                                                r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                                r0 = r10;
                                            }
                                        }
                                    } else {
                                        SETSP((sp - 32));
                                        r0 = GCALL0(0x06079A8A);
                                        if ((r0 & r0) == 0) {
                                            r1 = LD16(r14);
                                            if (!((r1 & r1) == 0)) {
                                                r0 = 0;
                                            } else {
                                                SETSP((sp - 32));
                                                r0 = GCALL0(0x06079D30);
                                                if ((r0 & r0) == 0) {
                                                    r0 = 0;
                                                } else {
                                                    r0 = LD16(r14);
                                                    ST16(r14, (r0 | 128));
                                                    SETSP((sp - 32));
                                                    r0 = GCALL1(r8, 0x06079DE2);
                                                    r5 = LD32(r12);
                                                    r4 = LD16(r11);
                                                    r5 = LD16(80 + r5);
                                                    SETR(10, r10);
                                                    SETR(11, r11);
                                                    SETR(12, r12);
                                                    SETR(13, r13);
                                                    SETSP((sp - 32));
                                                    SETPR(0x06079660);
                                                    r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                                    SETSP((sp - 32));
                                                    r0 = GCALL1(0x06014516, 0x0606D8B6);
                                                    ST32((sp - 36), r10);
                                                    r2 = LD16(r11);
                                                    ST32((sp - 40), (r2 & 0xFFFF));
                                                    r3 = LD32(r13);
                                                    r0 = LD16(r3 + 18);
                                                    ST32((sp - 44), r0);
                                                    r3 = LD32(r13);
                                                    r0 = LD16(r3 + 16);
                                                    ST32((sp - 48), r0);
                                                    r3 = LD32(r12);
                                                    r2 = LD16(80 + r3);
                                                    ST32((sp - 52), ((r2 & 0xFFFF) + 67));
                                                    r3 = LD32(r13);
                                                    r2 = LD16(40 + r3);
                                                    ST32((sp - 56), (r2 & 0xFFFF));
                                                    r7 = LD32(r13);
                                                    r7 = LD16(46 + r7);
                                                    r6 = LD32(r13);
                                                    r5 = LD32(r13);
                                                    r6 = LD16(44 + r6);
                                                    r0 = LD16(r5 + 4);
                                                    SETR(10, r10);
                                                    SETSP((sp - 56));
                                                    SETPR(0x060796B0);
                                                    r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                                    r0 = r10;
                                                }
                                            }
                                        } else {
                                            ST16(r14, 6);
                                            SETSP((sp - 32));
                                            r0 = GCALL1(0x06014516, 0x06079AB4);
                                            r5 = LD32(r12);
                                            r4 = LD16(r11);
                                            r5 = LD16(80 + r5);
                                            SETR(10, r10);
                                            SETR(11, r11);
                                            SETR(12, r12);
                                            SETR(13, r13);
                                            SETSP((sp - 32));
                                            SETPR(0x060795E0);
                                            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
                                            r3 = LD32(r12);
                                            ST16(58 + r3, 28);
                                            ST32((sp - 36), r10);
                                            r3 = LD16(r11);
                                            ST32((sp - 40), (r3 & 0xFFFF));
                                            r2 = LD32(r13);
                                            r0 = LD16(r2 + 18);
                                            ST32((sp - 44), (r0 - 32));
                                            r3 = LD32(r13);
                                            r0 = LD16(r3 + 16);
                                            ST32((sp - 48), r0);
                                            r3 = LD32(r12);
                                            r2 = LD16(80 + r3);
                                            ST32((sp - 52), ((r2 & 0xFFFF) + 11));
                                            r3 = LD32(r13);
                                            r2 = LD16(40 + r3);
                                            ST32((sp - 56), (r2 & 0xFFFF));
                                            r7 = LD32(r13);
                                            r6 = LD32(r13);
                                            r7 = LD16(46 + r7);
                                            r6 = LD16(44 + r6);
                                            r5 = LD32(r13);
                                            r0 = LD16(r5 + 4);
                                            SETR(10, r10);
                                            SETSP((sp - 56));
                                            SETPR(0x06079632);
                                            r0 = GCALL4(0x0606CAE4, 64, (r0 + r10), (r6 & 0xFFFF), (r7 & 0xFFFF));
                                            r0 = r10;
                                        }
                                    }
                                } else {
                                    ST16(r14, 3);
                                    SETSP((sp - 32));
                                    r0 = GCALL1(r8, 0x06079956);
                                    r4 = LD16(r11);
                                    r5 = LD32(r12);
                                    r5 = LD16(80 + r5);
                                    SETR(13, r13);
                                    SETSP((sp - 32));
                                    SETPR(0x06079506);
                                    r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                                    SETSP((sp - 32));
                                    r0 = GCALL1(0x06014516, 0x0606D8B6);
                                    r2 = LD32(r13);
                                    ST16(48 + r2, 4);
                                    SETSP((sp - 32));
                                    r0 = GCALL0(0x0606C7EE);
                                    SETSP((sp - 32));
                                    SETPR(0x06079522);
                                    r0 = GCALL0(0x0607AB38);
                                    r0 = 1;
                                }
                            }
                        } else {
                            r0 = LD16(r14);
                            ST16(r14, (r0 | 2));
                            SETSP((sp - 32));
                            r0 = GCALL0(0x0600A0B8);
                            ST16(0x060C2800, (r0 & 1));
                            SETSP((sp - 32));
                            r0 = GCALL1(0x0600A0EC, 9);
                            r2 = LD32((r0 << 2) + 0x060BAB4C);
                            ST16(0x060C2802, r2);
                            SETSP((sp - 32));
                            r0 = GCALL1(r8, 0x0607A4C0);
                            r3 = LD32(r12);
                            r5 = LD32(r12);
                            r4 = LD16(r11);
                            r5 = LD16(80 + r5);
                            r0 = LD8(r3 + 6);
                            SETSP((sp - 32));
                            SETPR(0x060794D2);
                            r0 = GCALL2(r9, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 21));
                            SETSP((sp - 32));
                            r0 = GCALL1(0x06014516, 0x0606D88C);
                            r0 = 1;
                        }
                    }
                } else {
                    ST16(r14, r10);
                    SETSP((sp - 32));
                    SETPR(0x06079482);
                    r0 = GCALL0(0x060796F8);
                    r0 = 1;
                }
            }
        } else {
            SETSP((sp - 32));
            r0 = GCALL1(r8, 0x06079A1A);
            r4 = LD16(r11);
            r5 = LD32(r12);
            r5 = LD16(80 + r5);
            SETSP((sp - 32));
            SETPR(0x0607946A);
            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 1));
            r0 = 1;
        }
    } else {
        r5 = LD32(r12);
        r4 = LD16(r11);
        r5 = LD16(80 + r5);
        SETSP((sp - 32));
        SETPR(0x06079446);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
        r0 = 1;
    }
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060796CE(void)
{
    return LD16(0x060C27FA) <= 4 && GCALL1(0x0606C390, 3) != 0;
}

int f0607992E(void)
{
    return LD16(0x060C27FE) == 0 && GCALL1(0x0606C114, 7) != 0;
}

int f06079A8A(void)
{
    if (LDU16(0x060C2810)) {
        ST16(0x060C2810, LDU16(0x060C2810) - 1);
        return 0;
    }
    return !GCALL1(0x0606C114, 4);
}

int f06079D30(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr p;
    int count = 0;

    if (LD16(cur + 60) != 0 || (LD8(cur + 7) & 255) < 2)
        return 0;
    if (IN_BOX(LDU16(cur + 24), LDU16(cur + 28))) {
        for (p = 0x060D5F30; p < 0x060D6028; p += 124) {
            if (!(LD8(p + 4) & 192) && IN_BOX(LDU16(p + 24), LDU16(p + 28)))
                count++;
            POLL();
        }
    }
    return count;
}

void f0607A420(void)
{
    GJUMP0(0x0607A42A);
}

int f0607A438(void)
{
    return LD16(0x060C27FC) == 0 && GCALL2(0x0606C006, 80, 80) != 0;
}

void f0607A5EA(void)
{
    ST16(0x060C27FC, LD16(0x060C27FC) + 4);
    GJUMP0(0x0607A5F8);
}

void f0607A60A(void)
{
    int p = 0x060C2820;

    do {
        ST32(p + 16, 0);
    } while (AGAIN((p += 20) < 0x060C285C));
}

void f0607A620(void)
{
    gaddr p = 0x060C2820;

    do {
        if (LD32(p + 16)) {
            GCALL1(0x060692DC, LD32(p + 16));
            ST32(p + 16, 0);
        }
        p += 20;
    } while (AGAIN(p < 0x060C285C));
}

void f0607A990(void)
{
    FRAME(sp, 88);
    gaddr table = sp - 88;
    gaddr entry;
    int scale;
    int dx, dy;

    COPYW(0x060944F4, table, 0x060B2B3C, 80);
    scale = LD16(0x060C2808);
    entry = table + (LDU8(LD32(CURRENT) + 6) << 4);
    dx = LD32(entry) * scale;
    dy = LD32(entry + 4) * scale;
    ST32(0x060C2834, LD32(0x060C2834) + dx);
    ST32(0x060C2838, LD32(0x060C2838) + dy);
    ST32(0x060C2848, LD32(0x060C2848) + dx * 2);
    ST32(0x060C284C, LD32(0x060C284C) + dy * 2);
}

int f0607ABD4(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607ABE0);
    r0 = GCALL3(0x0606B0DE, 0x060BAE16, 229, 13);
    r2 = LD32(0x060D7768);
    ST16(r2 + 18, 0);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C776);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607AC34);
    r2 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r2 << 2) + r2) << 2)), 0x0607ACDC);
    r4 = LD16(0x060C1AA8);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x0607AC20);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 61));
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606D8B6);
    SETSP((sp - 4));
    SETPR(0x0607AC2C);
    r0 = GCALL0(0x0607AE7E);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 98);
    return r0;
}

void f0607ADAE(void)
{
    int n = LDU16(0x060C27F0);

    ST16(LD32(CURRENT) + 24, LDU16(REC(n) + 24));
    ST16(LD32(CURRENT) + 28, LDU16(REC(n) + 28));
}

int f0607AFC0(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607AFCE);
    r0 = GCALL3(0x0606B0DE, 0x060BAE22, 229, 13);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 128));
    SETSP((sp - 8));
    r0 = GCALL1(0x0606947C, 0x1E0);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7FE);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0607B044);
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 8));
    SETPR(0x0607B00A);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 69));
    SETSP((sp - 8));
    r0 = GCALL1(0x06014516, 0x0606D8B6);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    r2 = LD32(0x060D7B3C);
    ST16(70 + r2, 64);
    ST16(68 + r2, 64);
    r3 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x0607B134);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0x060E2154;
}

int f0607B134(void)
{
    gaddr mover = LD32(MOVER_PTR);

    if (LDU16(mover + 68) < 0x100) {
        ST16(mover + 68, LD16(mover + 68) + 1);
        mover = LD32(MOVER_PTR);
        ST16(mover + 70, LD16(mover + 70) + 1);
    }
    return 0;
}

int f0607B1AE(void)
{
    int r0, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607B1BC);
    r0 = GCALL3(0x0606B0DE, 0x060BAE2E, 229, 13);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7FE);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0607B204);
    r4 = LD16(0x060C1AA8);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r0 = LD32(0x060D7768);
    r0 = LD16(r0 + 66);
    SETR(14, 0x060D7768);
    SETSP((sp - 8));
    SETPR(0x0607B1EC);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + ((r0 & 0xFFFF) & 1)) + 74));
    r3 = LD32(0x060D7B3C);
    ST16(38 + r3, -16);
    r3 = LD32(0x060D7768);
    ST16(68 + r3, 0xFFF8);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 68;
}

int f0607B32E(void)
{
    int r0, r2, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607B33A);
    r0 = GCALL3(0x0606B0DE, 0x060BAE3A, 229, 13);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 4));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x060805BA);
    SETPR(LD32((sp - 4)));
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0x100);
    return 66;
}

void f0607B3A0(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 28);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFF3);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFCF);
    ST16(0x060DF982, 153);
    ST16(0x060DF984, 151);
    ST16(0x060C1E44, 0);
}

void f0607B3E8(void)
{
    ST16(LD32(CURRENT) + 24, LDU16(0x060BAE48 + (LDU16(0x060C2870) << 2) + (LDU16(0x060C2872) << 1)));
    ST16(LD32(CURRENT) + 28, LDU16(0x060BAE60 + (LDU16(0x060C2872) << 1)));
}

void f0607B414(int n)
{
    gaddr obj;
    int v;

    GCALL1(0x0606948A, n);
    obj = OBJ(n);
    v = LD16(obj + 4) - 48;
    ST16(obj + 4, v > 20 ? v : 20);
}

void f0607B44C(void)
{
    int v = GCALL1(0x0605C9BC, (LDU16(LD32(CURRENT) + 28) + 8) >> 4);
    gaddr cur = LD32(CURRENT);

    v = (LDU16(cur + 24) << 16) + LDU16(cur + 26) - v;
    ST16(LD32(CURRENT) + 24, (unsigned int)v >> 16);
    ST16(LD32(CURRENT) + 26, v);
}

void f0607B88C(void)
{
    gaddr p = LD32(CURRENT) + 60;

    ST16(p, (GCALL0(0x0600A0B8) & 1) ? 0x258 : 0x708);
}

void f0607B9D8(void)
{
    int row = LDU16(0x060C2872) << 1;
    int x = LDU16(0x060BAE60 + row);
    int y = LDU16(0x060BAE48 + (LDU16(0x060C2870) << 2) + row);

    GCALL2(0x06074AFA, y, x);
    GJUMP1(0x06014516, 0x06074CB4);
}

void f0607BC86(void)
{
    GJUMP0(0x0607BC8E);
}

void f0607BCB6(void)
{
    GJUMP0(0x0607BCBE);
}

int f0607BCCA(void)
{
    int r0, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD16(0x060C2870);
    r4 = r4 & 0xFFFF;
    if (!((r4 & r4) == 0)) {
        if (!(r4 == 2)) {
            SETPR(LD32((sp - 4)));
            return 0;
        } else {
            r0 = LD16(0x060C287A);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 4)));
                return 0;
            } else {
                SETSP((sp - 4));
                r0 = GCALL0(0x0607BD78);
                if ((r0 & r0) == 0) {
                    SETPR(LD32((sp - 4)));
                    return 0;
                } else {
                    SETSP((sp - 4));
                    r0 = GCALL1(0x060144F4, 0x0607BDBA);
                    r5 = LD32(0x060D7768);
                    r4 = LD16(0x060C1AA8);
                    r5 = LD16(80 + r5);
                    SETSP((sp - 4));
                    SETPR(0x0607BD12);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 26));
                    SETSP((sp - 4));
                    r0 = GCALL1(0x06014516, 0x0606D88C);
                    SETPR(LD32((sp - 4)));
                    return 1;
                }
            }
        }
    } else {
        r0 = LD16(0x060C2878);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 4));
            r0 = GCALL0(0x0607BD78);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 4)));
                return 0;
            } else {
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0607BDBA);
                r5 = LD32(0x060D7768);
                r4 = LD16(0x060C1AA8);
                r5 = LD16(80 + r5);
                SETSP((sp - 4));
                SETPR(0x0607BD12);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 26));
                SETSP((sp - 4));
                r0 = GCALL1(0x06014516, 0x0606D88C);
                SETPR(LD32((sp - 4)));
                return 1;
            }
        } else {
            if (!(r4 == 2)) {
                SETPR(LD32((sp - 4)));
                return 0;
            } else {
                r0 = LD16(0x060C287A);
                if ((r0 & r0) == 0) {
                    SETPR(LD32((sp - 4)));
                    return 0;
                } else {
                    SETSP((sp - 4));
                    r0 = GCALL0(0x0607BD78);
                    if ((r0 & r0) == 0) {
                        SETPR(LD32((sp - 4)));
                        return 0;
                    } else {
                        SETSP((sp - 4));
                        r0 = GCALL1(0x060144F4, 0x0607BDBA);
                        r5 = LD32(0x060D7768);
                        r4 = LD16(0x060C1AA8);
                        r5 = LD16(80 + r5);
                        SETSP((sp - 4));
                        SETPR(0x0607BD12);
                        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 26));
                        SETSP((sp - 4));
                        r0 = GCALL1(0x06014516, 0x0606D88C);
                        SETPR(LD32((sp - 4)));
                        return 1;
                    }
                }
            }
        }
    }
}

void f0607BD28(void)
{
    gaddr p = 0x060BAEBA;

    do {
        int cell = GCALL2(0x0600CAE4, LDU16(p), LDU16(p + 2));

        ST16(FLAGS_AT(cell), LDU16(FLAGS_AT(cell)) & 0xFF7F);
        p += 4;
    } while (AGAIN(p < 0x060BAECE));
}

int f0607BD78(void)
{
    int i = GCALL1(0x0600A0EC, 5);
    int tried = 0;

    do {
        if (LDU16(0x060C287E + i * 2) == 0) {
            ST16(0x060C287C, i);
            return 1;
        }
        i++;
        tried++;
        if ((unsigned)i >= 5) {
            i = 0;
        }
    } while (AGAIN(tried < 5));
    return 0;
}

void f0607C1A0(void)
{
    int id = LDU16(0x060C2888);

    if (id) {
        GCALL1(0x060692DC, id);
        ST16(0x060C2888, 0);
    }
}

int f0607C7D6(void)
{
    int r0, r1, r2, r3, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = 0x060C2890;
    r0 = LD16(0x060C2890);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        r0 = LD32(0x060D7768);
        r0 = LD8(r0 + 4);
        if (!(((r0 & 255) & 192) == 0)) {
            SETPR(LD32((sp - 4)));
            return 0;
        } else {
            r6 = 0x060D7B3C;
            ST16(r4, 0);
            r2 = LD32(0x060D7B3C);
            r0 = LD16(66 + r2);
            if (!((r0 & r0) == 0)) {
                SETPR(LD32((sp - 4)));
                return 0;
            } else {
                r5 = 0x060D7768;
                r4 = LD32(0x060D7768);
                r0 = LD8(r4 + 7);
                if (!((r0 & r0) == 0)) {
                    r0 = LD8(r4 + 7);
                    ST8(r4 + 7, (r0 - 1));
                }
                r3 = LD32(r5);
                r0 = LD8(r3 + 7);
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(r6);
                    ST16(66 + r2, 180);
                    SETPR(LD32((sp - 4)));
                    return 0;
                } else {
                    r3 = LD32(r5);
                    r1 = LD16(42 + r3);
                    ST16(42 + r3, (r1 | 64));
                    r4 = LD16(0x060C2892);
                    SETSP((sp - 4));
                    SETPR(0x0607C82A);
                    r0 = GCALL1(0x0606D0CC, (r4 & 0xFFFF));
                    SETPR(LD32((sp - 4)));
                    return 1;
                }
            }
        }
    }
}

int f0607CCBC(gaddr list)
{
    gaddr rec = REC(LDU16(0x060C2860));
    int key = LDU16(OBJ(LDU16(rec + 22)) + 50) - LDU16(rec + 80);

    while (LD16(list) != -1) {
        POLL();
        if (LD16(list) == key)
            return 1;
        list += 2;
    }
    return 0;
}

int f0607CE40(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607CE4C);
    r0 = GCALL3(0x0606B0DE, 0x060BAF02, 0x162, 15);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607CE82);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 0x180));
    SETSP((sp - 4));
    r0 = GCALL1(0x0606947C, 152);
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 137);
    return r0;
}

int f0607D03E(void)
{
    int r0, r1, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0607D04E);
    r0 = GCALL3(0x0606B0DE, 0x060BAF32, 0x162, 15);
    SETSP((sp - 12));
    r0 = GCALL0(0x0606C78E);
    r3 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x0607D240);
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x0607D120);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 0x180));
    SETSP((sp - 12));
    r0 = GCALL1(0x0606947C, 0x1E0);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL1(0x0606AB24, r4);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    r2 = LD32(0x060D7B3C);
    ST16(74 + r2, 0);
    ST16(72 + r2, 0);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 28);
    ST16((68 + r3), r0);
    SETSP((sp - 12));
    r0 = GCALL0(0x0607D2A4);
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 66;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607D240(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r0 = GCALL5(0x0607D2A4, 0, 0, 0, 0, LD32((sp - 4)));
    SETSP((sp - 4));
    SETPR(0x0607D24C);
    r0 = GCALL5(0x0606C8C0, 0, 0, 0, 0, LD32((sp - 4)));
    SETPR(LD32((sp - 4)));
    return 0;
}

void f0607D2A4(void)
{
    int d = GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 28) - LDU16(LD32(CURRENT) + 68));

    ST16(LD32(MOVER_PTR) + 68, 0x100 + d);
    ST16(LD32(MOVER_PTR) + 70, d + 64);
}

int f0607D324(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607D330);
    r0 = GCALL3(0x0606B0DE, 0x060BAF3E, 0x162, 15);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C776);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 0x180));
    SETSP((sp - 4));
    r0 = GCALL1(0x0606947C, 0x1E0);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 4));
    r0 = GCALL1(0x0606AB24, r4);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x0607D35C);
    return r0;
}

int f0607D4A6(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607D4B2);
    r0 = GCALL3(0x0606B0DE, 0x060BAF4A, 0x162, 15);
    r2 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x0607D60E);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607D55C);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 0x180));
    SETSP((sp - 4));
    r0 = GCALL1(0x0606947C, 0x1E0);
    r4 = LD32(0x060D7B3C);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0606AB24, r4);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607D60E(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607D616);
    r0 = GCALL5(0x0606C8C0, 0, 0, 0, 0, LD32((sp - 4)));
    SETPR(LD32((sp - 4)));
    return 0;
}

int f0607D724(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607D730);
    r0 = GCALL3(0x0606B0DE, 0x060BAF56, 0x162, 15);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607D764);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 0x200));
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 4));
    r0 = GCALL1(0x0606AB24, r4);
    r5 = LD8(0x060C1910);
    r4 = LD32(0x060D7B3C);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x0606950C, r4, (r5 & 255));
    return r0;
}

int f0607D906(int r4, int r5)
{
    int r0, r6;
    ENTRY_SP(sp);

    r6 = r5;
    ST32((sp - 4), PR());
    ST32(sp - 12, r4);
    ST32(sp - 8, r5);
    r5 = LD32(sp - 12);
    SETSP((sp - 12));
    SETPR(0x0607D918);
    r0 = GCALL3(0x0606AE6C, 92, r5, r6);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0607DA5A(void)
{
    ST16(0x060C2878, 0);
    ST16(0x060C287A, 0);
    return 0;
}

int f0607DB04(void)
{
    int r0, r1, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0607DB14);
    r0 = GCALL3(0x0606B0DE, 0x060BAF88, 0x187, 16);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 0x100));
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    r2 = LD32(0x060D7B3C);
    ST16(74 + r2, 0);
    ST16(72 + r2, 0);
    SETSP((sp - 12));
    r0 = GCALL0(0x0606C7FE);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL1(0x0606AB24, r4);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x0607DC4C);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154), 0x0607DD98);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x0607DF5A);
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x0607DBA4);
    r2 = LD32(0x060D7768);
    r0 = LD16(r2 + 28);
    ST16((70 + r2), r0);
    SETR(14, 0x060D7768);
    SETSP((sp - 12));
    SETPR(0x0607DB94);
    r0 = GCALL0(0x0607DEAC);
    r2 = LD32(0x060D7768);
    ST16(72 + r2, 1);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 72;
}

int f0607DD98(void)
{
    gaddr cur = LD32(CURRENT);
    int d = GCALL1(0x060949D0, LDU16(cur + 28) - LDU16(LD32(CURRENT) + 70));
    int s = 0x100 - d * 3;
    gaddr mover = LD32(MOVER_PTR);
    int v;

    ST16(mover + 70, s);
    ST16(mover + 68, s);
    v = DIVS(LDU16(LD32(CURRENT) + 28) << 7, LDU16(LD32(CURRENT) + 70) - 64);
    v = GCALL1(0x0606CE8C, v);
    ST16(LD32(MOVER_PTR) + 38, HELPER(v >> 11));
    if (LD16(LD32(CURRENT) + 66)) {
        gaddr obj = OBJ(LDU16(LD32(CURRENT) + 66));

        ST16(obj + 70, s);
        ST16(obj + 68, s);
        ST16(obj + 16, LD16(LD32(MOVER_PTR) + 16));
        ST16(obj + 18, LD16(LD32(MOVER_PTR) + 18));
        ST16(obj + 38, GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 28) - 64));
    }
    if (!LD16(LD32(CURRENT) + 72))
        return 0;
    if (!GCALL0(0x0607DFB2))
        return 0;
    ST16(LD32(CURRENT) + 72, 0);
    GCALL1(0x060144F4, 0x0606D23C);
    return 1;
}

int f0607DF5A(void)
{
    gaddr cur = LD32(CURRENT);
    int v = LDU16(cur + 42);

    if (v & 128)
        return v;
    v = LDU16(cur + 28);
    if (v >= 112)
        return v;
    GCALL1(0x0607B414, LDU16(0x060C1AA8));
    cur = LD32(CURRENT);
    v = LD16(cur + 66);
    if (v) {
        gaddr mover = LD32(MOVER_PTR);

        v = LD16(mover + 4) + LD16(OBJ(LDU16(cur + 66)) + 38);
        ST16(mover + 4, v);
    }
    return v;
}

int f0607DFB2(void)
{
    int n = LDU16(0x060C2860);
    gaddr rec, mine, theirs, mover;
    int half, dx, dy;

    if (!n)
        return 0;
    rec = REC(n);
    if ((LD8(rec + 4) & 192) || LD16(0x060C288E))
        return 0;
    mine = OBJ(LDU16(rec + 22));
    theirs = OBJ(LDU16(LD32(CURRENT) + 66));
    half = (LDU16(rec + 28) - 64 + 4) >> 3;
    mover = LD32(MOVER_PTR);
    dx = LD16(theirs + 16) - LD16(mine + 16);
    dy = LD16(mover + 4) - LD16(mine + 4);
    if (dx < -8 - half || dx > 7 + half || dy < -4 || dy > 3)
        return 0;
    ST16(0x060C2890, LD16(0x060C2890) + 1);
    ST16(0x060C2892, LD16(LD32(CURRENT) + 74));
    return 1;
}

int f0607E0F2(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607E0FE);
    r0 = GCALL3(0x0606B0DE, 0x060BAF98, 0x187, 16);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 0x180));
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 32));
    SETSP((sp - 4));
    r0 = GCALL1(0x0606947C, 19);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 4));
    r0 = GCALL1(0x0606AB24, r4);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x0607E132);
    return r0;
}

void f0607E28C(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f0607E408(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607E410);
    r0 = GCALL0(0x0607F14C);
    r2 = LD32(0x060D7B3C);
    ST16(70 + r2, 0);
    ST16(68 + r2, 0);
    r3 = LD32(0x060D7B3C);
    ST16(74 + r3, 0);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r4 = LD32(0x060D7768);
    r0 = LD16(r4 + 22);
    SETR(14, 0);
    SETSP((sp - 8));
    SETPR(0x0607E43A);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r5 & 0xFFFF));
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0607E44C);
    ST16(0x060C28A4, 0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0607E50C(void)
{
    gaddr m;

    GCALL2(0x0606AAC8, LD32(MOVER_PTR), 0);
    m = LD32(MOVER_PTR);
    ST16(m + 70, 256);
    ST16(m + 68, 256);
    ST32(0x060E2160 + (short)(LD16(0x060C062C) * 20), 0x0607ECDE);
    GCALL0(0x0606C7AA);
    ST16(LD32(MOVER_PTR) + 48, 1);
    GCALL0(0x0606B6BC);
    GCALL1(0x060144F4, 0x0607E570);
    ST16(LD32(MOVER_PTR) + 38, -8);
    ST16(LD32(CURRENT) + 60, 480);
}

int f0607EA10(void)
{
    if (!GCALL0(0x0606BF22))
        return 0;
    GCALL0(0x0606E81C);
    return GCALL0(0x0606BE44) == 0;
}

int f0607EBB4(void)
{
    GCALL1(0x060144F4, 0x0607EBD4);
    GCALL2(0x06074AFA, LDU16(LD32(CURRENT) + 24), 64);
    return GJUMP1(0x06014516, 0x06074CB4);
}

int f0607F14C(void)
{
    int r0, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 4));
    SETPR(0x0607F162);
    r0 = GCALL3(0x0606AE6C, 73, r0, r6);
    ST16(0x060C289C, r0);
    SETPR(LD32((sp - 4)));
    return r0 & 0xFFFF;
}

int f0607F190(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607F19E);
    r0 = GCALL3(0x0606B0DE, 0x060BB01A, 182, 16);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7FE);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606950C, r4, 0);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 130));
    SETSP((sp - 8));
    r0 = GCALL1(0x0606947C, 0x1E4);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0607F1EA);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL1(0x0606AB72, r4);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL1(0x0606AB92, r4);
    r4 = LD16(0x060C1AA8);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068ACC, (r4 & 0xFFFF), 0);
    return r0;
}

void f0607F3BE(void)
{
    GCALL2(0x0606AAC8, LD32(MOVER_PTR), 7);
    ST16(LD32(CURRENT) + 68, 0);
    GCALL0(0x0607F3FC);
    ST32(0x060E2154 + (short)(LD16(0x060C062C) * 20), 0x0607F83C);
    GCALL1(0x060144F4, 0x0607F648);
    GJUMP1(0x06014516, 0x06074CB4);
}

void f0607F3FC(void)
{
    int tries = 64;
    int dx, dy;

    ST16(0x060C28A0, LD16(LD32(CURRENT) + 24));
    ST16(0x060C28A2, LD16(LD32(CURRENT) + 28));
    if (LD16(LD32(CURRENT) + 66)) {
        while (tries-- != 0) {
            POLL();
            dx = GCALL1(0x0600A0EC, 5);
            dy = GCALL1(0x0600A0EC, 5);
            if (dx == 2 && dy == 2)
                continue;
            ST16(0x060C28A0, LD16(LD32(CURRENT) + 24) + (dx - 2) * 16);
            ST16(0x060C28A2, LD16(LD32(CURRENT) + 28) + (dy - 2) * 16);
            if (GCALL2(0x0607F5A8, LDU16(0x060C28A0), LDU16(0x060C28A2)))
                break;
        }
    }
    GJUMP1(0x0607F50A, 64);
}

int f0607F50A(int divisor)
{
    int dx, dy, angle;

    ST16(LD32(CURRENT) + 70, -(int)((unsigned)(divisor << 4) >> 1));
    ST16(LD32(CURRENT) + 74, 0);
    ST16(LD32(MOVER_PTR) + 38, 0);
    dx = GCALL1(0x060980DC, GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 24) - LDU16(0x060C28A0)));
    dy = GCALL1(0x060980DC, GCALL1(0x060949D0, LDU16(LD32(CURRENT) + 28) - LDU16(0x060C28A2)));
    angle = DIVS(GCALL2(0x0609732A, dx, dy), divisor);
    ST16(LD32(CURRENT) + 12, (unsigned)angle >> 16);
    ST16(LD32(CURRENT) + 10, (((unsigned)angle >> 8) & 255) << 8);
    return GJUMP2(0x06074AFA, LDU16(0x060C28A0), LDU16(0x060C28A2));
}

int f0607F5A8(int x, unsigned int y)
{
    int cell;

    if (y > 176)
        return 0;
    cell = GCALL2(0x0600CAE4, x, y);
    return !(LDU16(FLAGS_AT(LD16(0x060B90A8) + cell)) & LDU16(FLAGS_AT(cell)) & (LDU16(LD32(CURRENT) + 18) & ~32));
}

int f0607F83C(void)
{
    gaddr mover = LD32(MOVER_PTR);
    gaddr cur = LD32(CURRENT);

    if (LD16(mover + 38) > 0) {
        ST16(cur + 74, 0);
    } else {
        int v = (LD16(mover + 38) << 16) + LDU16(cur + 74) + (LD16(cur + 70) << 8);

        ST16(LD32(MOVER_PTR) + 38, (unsigned int)v >> 16);
        ST16(LD32(CURRENT) + 74, v);
        cur = LD32(CURRENT);
        ST16(cur + 70, LD16(cur + 70) + 16);
    }
    ST8(LD32(MOVER_PTR) + 78, LDU16(LD32(CURRENT) + 70) >> 1);
    if (LD16(LD32(CURRENT) + 82) < 0) {
        mover = LD32(MOVER_PTR);
        ST8(mover + 78, -LD8(mover + 78));
    }
    return 0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0607F9E4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    UNFRAME(sp);
    r0 = GJUMP0(0x0606D398);
    return r0;
}

int f0607F9EA(void)
{
    gaddr cur = LD32(CURRENT);

    if (LDU16(cur + 36) == 74) {
        gaddr flags = FLAGS_AT(LDU16(cur + 20));

        ST16(flags, LDU16(flags) & 0xFF77);
    }
    ST16(0x060C289E, LD16(0x060C289E) - 1);
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

int f0607FA78(void)
{
    int r0, r1, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607FA86);
    r0 = GCALL3(0x0606B0DE, 0x060BB032, 182, 16);
    r2 = LD32(0x060D7768);
    ST16(r2 + 18, 0);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606950C, r4, 1);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 128));
    SETSP((sp - 8));
    r0 = GCALL1(0x0606947C, 0x1E5);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C78E);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0607FAD4);
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 66;
}

int f0607FC00(void)
{
    int r0, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r0 = LD16(62 + r3);
    if ((r0 & r0) == 0) {
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0607FC5C);
        r2 = LD32(r14);
        ST16(66 + r2, 0);
        r2 = LD32(0x060D7B3C);
        ST16(48 + r2, 36);
        SETSP((sp - 8));
        r0 = GCALL0(0x0606C7EE);
        r5 = LD32(r14);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AA8);
        SETSP((sp - 8));
        SETPR(0x0607FC4C);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 34));
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606D8B6);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 1;
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

void f0607FED8(void)
{
    gaddr mover = LD32(MOVER_PTR);
    gaddr obj;

    if (!(GCALL1(0x060691DA, LD16(mover + 18)) & 0xFFFF))
        return;
    obj = OBJ(LDU16(0x060C1AAA));
    ST16(obj + 42, LDU16(obj + 42) | 16);
    mover = LD32(MOVER_PTR);
    ST16(obj + 44, LD16(mover + 44));
    ST16(obj + 46, LD16(mover + 46));
    GCALL1(0x0606AB72, obj);
    mover = LD32(MOVER_PTR);
    ST16(obj + 10, LD16(mover + 10));
    ST16(obj + 16, LD16(mover + 16));
    ST16(obj + 18, LD16(mover + 18) + LD16(mover + 38));
    ST16(obj + 38, -16 - ((LD32(0x26006034) & 1) << 4));
}
