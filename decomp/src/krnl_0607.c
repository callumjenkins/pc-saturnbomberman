#include "krnl.h"

void f06070024(void)
{
    GJUMP0(0x0607005C);
}

int f060700E4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = 0x060D7768;
    r13 = LD32(0x060D7768);
    r3 = LD16(66 + r13);
    if (!((r3 & r3) == 0)) {
        r2 = LD32(0x060D7B3C);
        r1 = LD16(60 + r2);
        if (!((r1 & 0xFFFF) >= 0xFF00)) {
            r4 = LD16(62 + r13);
            r4 = r4 & 0xFFFF;
            if (r4 > 0) {
                if (!(r4 >= 3)) {
                    r0 = LD8(r13 + 6);
                    ST32(sp - 20, (r0 & 255));
                    r0 = LD16(68 + r13);
                    r0 = LD8(((r0 & 0xFFFF) << 1) + 0x060B90B5);
                    ST8(r13 + 6, r0);
                    r3 = LD32(r14);
                    r0 = LD16(r3 + 20);
                    ST32(sp - 16, (r0 & 0xFFFF));
                    r3 = LD32(r14);
                    r0 = LD16(68 + r3);
                    r2 = LD16(((r0 & 0xFFFF) << 1) + 0x060B90AA);
                    r0 = LD16(r3 + 20);
                    ST16(r3 + 20, (r0 + r2));
                    SETSP((sp - 20));
                    r0 = GCALL1(0x06020330, 6);
                    r2 = LD32(r14);
                    r0 = LD16(sp - 14);
                    ST16(r2 + 20, r0);
                    r3 = LD32(r14);
                    r0 = LD8(sp - 17);
                    ST8(r3 + 6, r0);
                    r3 = LD32(r14);
                    ST16(62 + r3, 0);
                    SETSP((sp - 20));
                    r0 = GCALL1(0x0600996A, 20);
                }
            }
        } else {
            SETSP((sp - 20));
            r0 = GCALL4(0x0606B6BC, r4, r5, r6, r7);
            r3 = LD32(r14);
            ST16(66 + r3, 0);
        }
        r0 = 1;
    } else {
        SETSP((sp - 20));
        r0 = GCALL0(0x0606C4C0);
        ST16((68 + r13), r0);
        if (((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
            r0 = 0;
        } else {
            r3 = LD32(r14);
            ST16(66 + r3, 1);
            r3 = LD32(r14);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r2 = LD16(68 + r3);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x06070130);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r2 & 0xFFFF)) + 8));
            r3 = LD32(r14);
            ST16(62 + r3, 29);
            r0 = 1;
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f06070748(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06070752);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            r14 = LD32(0x060D7768);
            r0 = LD16(66 + r14);
            if (!((r0 & 0xFFFF) == 2)) {
                ST16(48 + r14, 10);
            } else {
                r0 = LD16(r14 + 20);
                r3 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
                if (((r3 & 0xFFFF) & 0x42B7) == 0) {
                    r0 = LD16(r14 + 20);
                    SETSP((sp - 8));
                    r0 = GCALL2(0x0606C82C, (r0 & 0xFFFF), 128);
                }
            }
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x060707C2);
            r2 = LD32(0x060D7768);
            ST16(58 + r2, 0x12C);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606E864);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060707C2(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060707CC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r0 = LD16(66 + r4);
        if (!((r0 & 0xFFFF) == 2)) {
            ST16(48 + r4, 4);
        } else {
            r0 = LD16(r4 + 20);
            r3 = (r0 & 0xFFFF) << 1;
            r1 = LD16(0x060EC8B0 + r3);
            ST16(0x060EC8B0 + r3, (r1 & 0xFF7F));
        }
        r5 = LD32(r14);
        r3 = LD32(r14);
        r5 = LD16(66 + r5);
        r5 = LD16(0x060BA212 + (((r5 & 0xFFFF) - 1) << 1));
        r2 = LD16(80 + r3);
        r4 = LD16(0x060C1AA8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x0607081C);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 + (r2 & 0xFFFF)));
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0606D8B6);
        r2 = LD32(r14);
        ST16(66 + r2, 0);
        r2 = LD32(r14);
        ST16(62 + r2, 0x168);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060708BC(void)
{
    int r0, r1, r2, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x060708EA);
    r5 = LD32(0x060D7768);
    r2 = LD32(0x060D7768);
    r5 = LD16(48 + r5);
    r1 = LD16(80 + r2);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 4));
    SETPR(0x060708E4);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r1 & 0xFFFF)));
    SETPR(LD32((sp - 4)));
    return 1;
}

int f060708EA(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060708F4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            r14 = LD32(0x060D7768);
            r0 = LD8(r14 + 4);
            if (((r0 & 255) & 64) == 0) {
                r0 = LD16(r14 + 28);
                r6 = r0;
                r0 = LD16(r14 + 24);
                SETSP((sp - 8));
                SETPR(0x06070922);
                r0 = GCALL3(0x0606AE6C, 63, r0, r6);
            }
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0606D398);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606D37A);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f06070C2C(void)
{
    int r0, r2, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r14 = 0x060D7768;
    r13 = LD32(0x060D7768);
    r0 = LD16(62 + r13);
    if ((r0 & r0) == 0) {
        r4 = LD16(64 + r13);
        SETSP((sp - 24));
        r0 = GCALL1(0x0606BEBC, (r4 & 0xFFFF));
        if ((r0 & r0) == 0) {
            r0 = 0;
        } else {
            SETSP((sp - 24));
            r0 = GCALL0(0x0606BBB0);
            SETSP((sp - 24));
            r0 = GCALL0(0x0606B648);
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r13 = 0x060BA2A4;
                r3 = LD32(r14);
                r2 = LD16(0x060C1F24);
                ST16(66 + r3, r2);
                r5 = LD32(r14);
                r5 = LD8(67 + r5);
                r3 = LD32(r14);
                r2 = LD16(80 + r3);
                r5 = LD16((((signed char)(((r5 - 1) << 1) + ((r5 - 1) << 2))) + 0x060BA2A4));
                r4 = LD16(0x060C1AA8);
                SETR(13, 0x060BA2A4);
                SETR(14, r14);
                SETSP((sp - 24));
                SETPR(0x06070CB8);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 + (r2 & 0xFFFF)));
                r3 = LD32(r14);
                r0 = LD16(r3 + 24);
                r4 = LD16((66 + r3));
                r4 = ((r4 & 0xFFFF) << 2) + 0x060B90BE;
                r2 = LD16(r4);
                ST32(sp - 20, ((r0 & 0xFFFF) + r2));
                r2 = LD32(r14);
                r0 = LD16(r2 + 28);
                r2 = r0 & 0xFFFF;
                r0 = LD16(r4 + 2);
                r2 = r2 + r0;
                ST32(sp - 24, r2);
                r5 = LD32(sp - 20);
                SETR(13, 0x060BA2A4);
                SETR(14, r14);
                SETSP((sp - 24));
                SETPR(0x06070CEA);
                r0 = GCALL3(0x0606AE6C, 64, r5, r2);
                r5 = r0;
                if (!((r5 & r5) == 0)) {
                    r0 = LD32(r14);
                    r0 = LD8(r0 + 67);
                    r4 = (r5 * 124) + 0x060D5F30;
                    ST8(r4 + 6, r0);
                    r0 = LD16(r4 + 22);
                    r3 = LD32(r14);
                    r2 = 0x060C384C + (((r0 & 0xFFFF) * 84) & 0xFFFF);
                    r3 = LD8((67 + r3));
                    r0 = LD16((((signed char)(((r3 - 1) << 1) + ((r3 - 1) << 2))) + r13) + 2);
                    ST16(r2, r0);
                    r3 = LD32(r14);
                    r2 = LD8(67 + r3);
                    r0 = LD16((r13 + ((signed char)(((r2 - 1) << 1) + ((r2 - 1) << 2)))) + 4);
                    ST16((48 + r4), r0);
                    r3 = LD16(0x060C062C);
                    ST16(52 + r4, r3);
                }
                SETSP((sp - 24));
                r0 = GCALL1(0x06014516, 0x06070DA0);
                r0 = 1;
            }
        }
    } else {
        r0 = 0;
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f06071142(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607114E);
    r0 = GCALL3(0x0606B0DE, 0x060BA306, 242, 8);
    r2 = LD16(0x060C062C);
    ST32(0x060E2164 + ((short)(((r2 << 2) + r2) << 2)), 0x0607123A);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C78E);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 2));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x060711DC);
    return r0;
}

void f0607123A(int n)
{
    GJUMP1(0x0601628E, n);
}

int f0607127C(int r4, int r5, int r6, int r7)
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
        if (!((r1 & 0xFFFF) == ((r3 & 0xFFFF) + 5))) {
            r3 = LD16(50 + r4);
            r1 = LD16(80 + r5);
            if ((r3 & 0xFFFF) == ((r1 & 0xFFFF) + 6)) {
                SETSP((sp - 12));
                r0 = GCALL0(0x0606C7CE);
                SETSP((sp - 12));
                r0 = GCALL4(0x0606B6BC, r4, r5, r6, r7);
            }
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x0606C78E);
            SETSP((sp - 12));
            r0 = GCALL4(0x0606B6BC, r4, r5, r6, r7);
        }
    }
    r2 = LD32(r14);
    r0 = LD16(62 + r2);
    if ((r0 & r0) == 0) {
        r3 = LD32(r14);
        r2 = LD16(66 + r3);
        if (!((r2 & r2) == 0)) {
            r3 = LD32(r14);
            ST16(66 + r3, 0);
            SETSP((sp - 12));
            r0 = GCALL0(0x0606C7C2);
            r1 = LD32(r13);
            ST16(48 + r1, 0);
            SETSP((sp - 12));
            r0 = GCALL0(0x0606C7DE);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x060713C4);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 6));
            r3 = LD32(r14);
            ST16(62 + r3, 0x183);
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            r0 = 1;
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x0606E81C);
            r4 = LD32(r14);
            r4 = LD16(64 + r4);
            SETSP((sp - 12));
            r0 = GCALL1(0x0606BCD8, (r4 & 0xFFFF));
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r3 = LD32(r14);
                ST16(66 + r3, 1);
                SETSP((sp - 12));
                r0 = GCALL0(0x0606C79A);
                r1 = LD32(r13);
                ST16(48 + r1, 7);
                SETSP((sp - 12));
                r0 = GCALL0(0x0606C7EE);
                r5 = LD32(r14);
                r4 = LD16(0x060C1AA8);
                r5 = LD16(80 + r5);
                SETR(14, r14);
                SETSP((sp - 12));
                SETPR(0x06071382);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                r3 = LD32(r14);
                ST16(62 + r3, 0x19B);
                SETSP((sp - 12));
                r0 = GCALL1(0x06014516, 0x0606D88C);
                r0 = 1;
            }
        }
    } else {
        r0 = 0;
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060714D8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = 15;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r11 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(r4 + 24);
    r13 = r0 & 0xFFFF;
    r0 = LD16(r4 + 28);
    r12 = r0 & 0xFFFF;
    if (((r13 | r12) & 15) == 0) {
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x06071506);
        r0 = GCALL4(0x0607164E, 0, r5, r6, r7);
    }
    r10 = 0;
    r4 = 0xFFF0;
    r0 = LD32(r11);
    r0 = LD8(r0 + 6);
    r0 = r0 & 255;
    r5 = 16;
    if (r0 == 1) {
        r5 = LD32(r11);
        r0 = LD16(r5 + 24);
        r5 = r0;
        r13 = (r5 & 0xFFFF) & r4;
        r10 = (r5 & 0xFFFF) - r13;
    } else {
        if (r0 == 2) {
            r5 = LD32(r11);
            r0 = LD16(r5 + 28);
            r5 = r0;
            r12 = (r5 & 0xFFFF) & r4;
            r10 = (r5 & 0xFFFF) - r12;
        } else {
            if (r0 == 3) {
                r6 = LD32(r11);
                r0 = LD16(r6 + 24);
                r6 = r0 & 0xFFFF;
                r10 = (r5 - (r6 & r14)) & r14;
                r13 = r6 & r4;
                if (!((r10 & r10) == 0)) {
                    r13 = r13 + 16;
                }
            } else {
                if (r0 == 4) {
                    r6 = LD32(r11);
                    r0 = LD16(r6 + 28);
                    r6 = r0 & 0xFFFF;
                    r10 = (r5 - (r6 & r14)) & r14;
                    r12 = r6 & r4;
                    if (!((r10 & r10) == 0)) {
                        r12 = r12 + 16;
                    }
                }
            }
        }
    }
    r3 = LD32(r11);
    r8 = 0xFFDF;
    ST32(sp - 40, r3);
    r14 = LD32(r11);
    r9 = 124;
    while (1) {
        r1 = LD16(66 + r14);
        if (!((r1 & r1) == 0)) {
            POLL();
            r2 = LD16(66 + r14);
            r14 = 0x060D5F30 + ((r2 & 0xFFFF) * r9);
            ST32(r11, r14);
            SETSP((sp - 40));
            r0 = GCALL0(0x0606C894);
            r0 = LD8(r14 + 6);
            r0 = r0 & 255;
            if (r0 == 1) {
                r13 = r13 - 16;
                r0 = r13 + r10;
                ST16(r14 + 24, r0);
                ST16(r14 + 28, r12);
            } else {
                if (r0 == 2) {
                    r12 = r12 - 16;
                    r0 = r12 + r10;
                    ST16(r14 + 28, r0);
                    ST16(r14 + 24, r13);
                } else {
                    if (r0 == 3) {
                        r13 = r13 + 16;
                        r0 = r13 - r10;
                        ST16(r14 + 24, r0);
                        ST16(r14 + 28, r12);
                    } else {
                        if (r0 == 4) {
                            r12 = r12 + 16;
                            r0 = r12 - r10;
                            ST16(r14 + 28, r0);
                            ST16(r14 + 24, r13);
                        }
                    }
                }
            }
            r3 = LD32(r11);
            r0 = LD16(r3 + 18);
            ST16(r3 + 18, (r0 | 32));
            SETSP((sp - 40));
            r0 = GCALL0(0x0606C850);
            r3 = LD32(r11);
            r0 = LD16(r3 + 18);
            ST16(r3 + 18, (r0 & r8));
            continue;
        } else {
            break;
        }
    }
    r3 = LD32(sp - 40);
    ST32(r11, r3);
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

int f060718A8(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 20);
    r3 = LD16(((r0 & 0xFFFF) << 1) + 0x060EE8B0);
    ST32(sp - 8, (r3 & 0xFFFF));
    SETSP((sp - 8));
    SETPR(0x060718C4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD32(0x060D7768);
        r3 = LD32(sp - 8);
        r0 = LD16(r2 + 20);
        ST16((0x060EE8B0 + ((r0 & 0xFFFF) << 1)), r3);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f06071E16(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C776);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7EE);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x06071E64);
    r2 = LD32(0x060D7768);
    ST8(r2 + 6, 2);
    r3 = LD32(0x060D7B3C);
    ST16(48 + r3, 5);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r4 = LD16(0x060C1AA8);
    SETR(14, 0x060D7768);
    SETSP((sp - 8));
    SETPR(0x06071E54);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
    r3 = LD32(0x060D7768);
    ST16(62 + r3, 30);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 1;
}

int f06071E64(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06071E6E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606D786);
            if ((r0 & r0) == 0) {
                r3 = LD16(0x060C062C);
                ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x0606B1EC);
                SETSP((sp - 8));
                r0 = GCALL1(0x060144F4, 0x0606D2C8);
            } else {
                SETSP((sp - 8));
                r0 = GCALL0(0x0606D97A);
                r1 = LD32(r14);
                ST16(r1 + 12, 1);
                r3 = LD32(r14);
                ST16(r3 + 10, 0x8000);
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x0606E7F4);
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f06072052(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607205C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r2 = LD16(62 + r3);
        if ((r2 & r2) == 0) {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606C776);
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x060720EC);
            r3 = LD32(r14);
            ST16(44 + r3, 1);
            r3 = LD32(r14);
            ST16(r3 + 12, 1);
            r3 = LD32(r14);
            ST16(r3 + 10, 0x2000);
            r3 = LD32(r14);
            ST16((54 + r3), 32);
            ST16((56 + r3), 16);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606E70E);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
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

int f06072380(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607238C);
    r0 = GCALL3(0x0606B0DE, 0x060BA490, 122, 9);
    r4 = LD32(0x060D7768);
    r4 = LD16(40 + r4);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0606D8E6, (r4 & 0xFFFF));
    return r0;
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

int f060725F2(void)
{
    int r0, r2, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r14 = 0x060D7768;
    r13 = LD32(0x060D7768);
    r0 = LD16(62 + r13);
    if ((r0 & r0) == 0) {
        r3 = LD16(66 + r13);
        if (!((r3 & r3) == 0)) {
            r0 = LD16(r13 + 24);
            r4 = LD16((66 + r13));
            r4 = ((r4 & 0xFFFF) << 2) + 0x060B90BE;
            r2 = LD16(r4);
            ST32(sp - 20, ((r0 & 0xFFFF) + r2));
            r0 = LD16(r13 + 28);
            r2 = r0 & 0xFFFF;
            r0 = LD16(r4 + 2);
            r2 = r2 + r0;
            ST32(sp - 24, r2);
            r5 = LD32(sp - 20);
            SETR(14, r14);
            SETSP((sp - 24));
            SETPR(0x060726DA);
            r0 = GCALL3(0x0606AE6C, 67, r5, r2);
            r4 = r0;
            if (!((r4 & r4) == 0)) {
                r4 = (r4 * 124) + 0x060D5F30;
                ST32(sp - 24, r4);
                r0 = LD32(r14);
                r0 = LD8(r0 + 67);
                ST8(r4 + 6, r0);
                r5 = LD32(r14);
                r3 = LD32(r14);
                r5 = LD16(66 + r5);
                r4 = LD32(sp - 24);
                r5 = LD16(0x060BA4F0 + (((r5 & 0xFFFF) - 1) << 2));
                r2 = LD16(80 + r3);
                r0 = LD16(r4 + 22);
                SETSP((sp - 24));
                SETPR(0x06072718);
                r0 = GCALL2(0x06068ACC, (r0 & 0xFFFF), (r5 + (r2 & 0xFFFF)));
            }
            SETSP((sp - 24));
            r0 = GCALL1(0x06014516, 0x06072732);
            r0 = 1;
        } else {
            r4 = LD16(64 + r13);
            SETSP((sp - 24));
            r0 = GCALL1(0x0606BEBC, (r4 & 0xFFFF));
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                SETSP((sp - 24));
                r0 = GCALL0(0x0606BBB0);
                SETSP((sp - 24));
                r0 = GCALL0(0x0606B648);
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r3 = LD32(r14);
                    r2 = LD16(0x060C1F24);
                    ST16(66 + r3, r2);
                    r5 = LD32(r14);
                    r5 = LD16(66 + r5);
                    r3 = LD32(r14);
                    r5 = LD16(0x060BA4EE + (((r5 & 0xFFFF) - 1) << 2));
                    r2 = LD16(80 + r3);
                    r4 = LD16(0x060C1AA8);
                    SETR(14, r14);
                    SETSP((sp - 24));
                    SETPR(0x0607269A);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 + (r2 & 0xFFFF)));
                    r3 = LD32(r14);
                    ST16(58 + r3, 70);
                    SETSP((sp - 24));
                    r0 = GCALL1(0x06014516, 0x0606E864);
                    r0 = 1;
                }
            }
        }
    } else {
        r0 = 0;
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06072778(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06072786);
    r0 = GCALL3(0x0606B0DE, 0x060BA4FE, 138, 11);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C78E);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 2));
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    r3 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x06072812);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x060727BE);
    return r0;
}

int f060727BE(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060727C6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r2 = LD16(66 + r4);
        if (!((r2 & r2) == 0)) {
            r0 = LD8(r4 + 6);
            r2 = LD16(((r0 & 255) << 1) + 0x060B90A0);
            r0 = LD16(r4 + 20);
            SETSP((sp - 4));
            SETPR(0x060727FE);
            r0 = GCALL1(0x0606C8CA, ((r0 & 0xFFFF) + r2));
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D2C8);
        } else {
            ST16(66 + r4, 1);
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606E7F4);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f060729C4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060729CE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            r14 = 0x060D7768;
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETR(14, 0x060D7768);
            SETSP((sp - 8));
            SETPR(0x060729F8);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 8));
            r2 = LD32(0x060D7768);
            r0 = LD16(r2 + 20);
            r3 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
            r0 = LD16(r2 + 18);
            if (((r3 & 0xFFFF) & ((r0 & 0xFFFF) | 135)) == 0) {
                r4 = LD32(r14);
                r0 = LD16(r4 + 20);
                SETSP((sp - 8));
                r0 = GCALL2(0x0606C82C, (r0 & 0xFFFF), 128);
            }
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x06072A34);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06072A34(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06072A3E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL0(0x06072AC8);
        if ((r0 & r0) == 0) {
            r3 = LD32(0x060D7768);
            r0 = LD16(r3 + 20);
            r3 = (r0 & 0xFFFF) << 1;
            r1 = LD16(0x060EC8B0 + r3);
            ST16(0x060EC8B0 + r3, (r1 & 0xFF7F));
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, 0x060D7768);
            SETSP((sp - 8));
            SETPR(0x06072A72);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 7));
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0606D8B6);
            r2 = LD32(0x060D7768);
            ST16(66 + r2, 0);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
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

int f06072CD8(int r4, int r5, int r6, int r7)
{
    int r0, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r14 = 0x060D7768;
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETR(14, 0x060D7768);
    SETSP((sp - 16));
    SETPR(0x06072CF4);
    r0 = GCALL3(0x0606AE6C, 68, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r4 = (r4 * 124) + 0x060D5F30;
        ST32(sp - 16, r4);
        r0 = LD32(r14);
        r0 = LD8(r0 + 6);
        ST8(r4 + 6, r0);
        r5 = LD32(r14);
        r0 = LD8(r5 + 6);
        r4 = LD32(sp - 16);
        r5 = LD16((80 + r5));
        r5 = (r5 & 0xFFFF) + (r0 & 255);
        r0 = LD16(r4 + 22);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x06072D28);
        r0 = GCALL2(0x06068ACC, (r0 & 0xFFFF), (r5 + 8));
        r6 = LD32(r14);
        r0 = LD8(r6 + 6);
        r6 = LD16(0x060B9F7C + ((r0 & 255) << 1));
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 16));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), r6);
    }
    r2 = LD32(r14);
    ST16(58 + r2, 90);
    SETSP((sp - 16));
    r0 = GCALL1(0x060144F4, 0x0606E864);
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D8B6);
    return r0;
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

int f06072F9C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    SETSP((sp - 40));
    SETPR(0x06072FB6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 36)));
        SETPR(LD32((sp - 32)));
        SETR(8, LD32((sp - 28)));
        SETR(9, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if (!((r1 & 0xFFFF) >= 0xFF00)) {
            r14 = 0x060D7768;
            r4 = LD32(0x060D7768);
            r0 = LD8(r4 + 6);
            if ((r0 & r0) == 0) {
                r3 = LD16(62 + r4);
                if ((r3 & r3) == 0) {
                    r10 = 124;
                    r12 = 0x060B90C2;
                    r13 = 0x060B90A2;
                    ST32(sp - 40, 0x060B90AA);
                    r11 = 1;
                    while (1) {
                        r3 = LD32(sp - 40);
                        if (!((unsigned)r13 >= (unsigned)r3)) {
                            POLL();
                            r4 = LD32(r14);
                            r0 = LD16(r4 + 20);
                            r4 = LD16(r13);
                            r2 = LD32(r14);
                            r3 = LD16(0x060EC8B0 + ((r4 + (r0 & 0xFFFF)) << 1));
                            r0 = LD16(r2 + 18);
                            if (((r3 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
                                r8 = LD32(r14);
                                r9 = LD32(r14);
                                r0 = LD16(r8 + 24);
                                r8 = LD16(r12);
                                r8 = r8 + (r0 & 0xFFFF);
                                r0 = LD16(r9 + 28);
                                r9 = r0 & 0xFFFF;
                                r0 = LD16(r12 + 2);
                                SETR(10, r10);
                                SETR(11, r11);
                                SETR(12, r12);
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 40));
                                SETPR(0x06073044);
                                r0 = GCALL3(0x0606AE6C, 69, r8, (r9 + r0));
                                r4 = r0;
                                if (!((r4 & r4) == 0)) {
                                    ST8(0x060D5F36 + (r4 * r10), r11);
                                }
                            }
                            r12 = r12 + 4;
                            r13 = r13 + 2;
                            continue;
                        } else {
                            break;
                        }
                    }
                    r1 = LD32(r14);
                    ST8(r1 + 6, r11);
                }
            }
            SETSP((sp - 40));
            SETPR(0x06073068);
            r0 = GCALL0(0x0606C8C0);
            SETMACL(LD32((sp - 36)));
            SETPR(LD32((sp - 32)));
            SETR(8, LD32((sp - 28)));
            SETR(9, LD32((sp - 24)));
            SETR(10, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            SETMACL(LD32((sp - 36)));
            SETPR(LD32((sp - 32)));
            SETR(8, LD32((sp - 28)));
            SETR(9, LD32((sp - 24)));
            SETR(10, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP1(0x060144F4, 0x0606D398);
            return r0;
        }
    }
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

int f06073468(int r4, int r5, int r6, int r7)
{
    int r0, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r4 = LD32(0x060D7768);
    r0 = LD8(r4 + 4);
    if (((r0 & 255) & 64) == 0) {
        r11 = 5;
        r0 = LD16(r4 + 24);
        r12 = 124;
        r8 = 0x060D5F30;
        r14 = 1;
        r9 = 0x060C381C;
        ST32(sp - 40, (((r0 & 0xFFFF) + 8) & 0xFFF0));
        r0 = LD16(r4 + 28);
        r13 = 180;
        r10 = ((r0 & 0xFFFF) + 8) & 0xFFF0;
        do {
            r5 = LD32(sp - 40);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 40));
            SETPR(0x060734B6);
            r0 = GCALL3(0x0606AE6C, 70, r5, r10);
            r4 = r0;
            if (!((r4 & r4) == 0)) {
                r5 = (r4 * r12) + r8;
                r0 = LD16(r5 + 22);
                ST16((66 + ((((r0 & 0xFFFF) * 84) & 0xFFFF) + r9)), r13);
                ST8(r5 + 6, r14);
            }
            r14 = r14 + 1;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r11)));
    }
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x0606D2C8);
    return r0;
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

int f06073520(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06073528);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r1 = LD16(62 + r3);
        if ((r1 & r1) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x060735A0);
            SETSP((sp - 4));
            r0 = GCALL0(0x0606C7AA);
            r2 = LD32(0x060D7B3C);
            ST16(66 + r2, 180);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060735A0(int r4, int r5, int r6, int r7)
{
    int r0, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060735AA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r4 = LD16(40 + r4);
        SETSP((sp - 8));
        r0 = GCALL1(0x0606D8E6, (r4 & 0xFFFF));
        r2 = LD32(0x060D7768);
        r0 = LD8(r2 + 6);
        ST16(0x060C1F24, (r0 & 255));
        SETSP((sp - 8));
        r0 = GCALL0(0x0606D93E);
        if (!((r0 & r0) == 0)) {
            r2 = LD32(r14);
            ST16((54 + r2), 32);
            ST16((56 + r2), 16);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606E70E);
            SETSP((sp - 8));
            SETPR(0x060735EE);
            r0 = GCALL0(0x0606E70E);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06073678(void)
{
    int r0, r1, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST32(sp - 16, 11);
    SETSP((sp - 16));
    r0 = GCALL4(0x0606C9BE, -12, 11, -12, 11);
    r4 = r0;
    if ((r0 & r0) == 0) {
        r0 = 0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(0x060D5F54 + (r4 * 124));
        ST16((66 + r3), (r0 + 0xFFDF));
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        r4 = r4 & 0xFFFF;
        if (r4 >= 8) {
            r0 = 0;
        } else {
            r1 = LD16(0x060BA5DA + ((signed char)((r4 << 1) + (r4 << 2))));
            if ((r1 & r1) == 0) {
                r0 = 0;
            } else {
                r4 = LD16(0x060C062C);
                SETSP((sp - 16));
                r0 = GCALL1(0x06014820, r4);
                SETSP((sp - 16));
                r0 = GCALL1(0x060144F4, 0x06073726);
                r2 = LD32(r14);
                ST16(70 + r2, 4);
                r2 = LD32(r14);
                r3 = LD16(70 + r2);
                ST16(68 + r2, (r3 + 0x100));
                r5 = LD32(r14);
                r5 = LD16(80 + r5);
                r4 = LD16(0x060C1AA8);
                SETSP((sp - 16));
                SETPR(0x06073708);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
                SETSP((sp - 16));
                r0 = GCALL1(0x06014516, 0x0606D88C);
                SETSP((sp - 16));
                SETPR(0x06073716);
                r0 = GCALL0(0x0606D88C);
                r0 = 1;
            }
        }
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06073726(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    SETPR(0x06073736);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r13 = 0x060D7B3C;
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r3 = LD16(68 + r4);
        if ((r3 & 0xFFFF) > 0x100) {
            r3 = LD16(68 + r4);
            if ((r3 & 0xFFFF) > 0x200) {
                r2 = LD16(70 + r4);
                ST16(70 + r4, (-r2));
                r3 = LD32(r14);
                r2 = LD8(67 + r3);
                r1 = LD16((((signed char)((r2 << 1) + (r2 << 2))) + 0x060BA5DA));
                ST16(80 + r3, r1);
                r5 = LD32(r14);
                r5 = LD8(67 + r5);
                r0 = LD16((((signed char)((r5 << 1) + (r5 << 2))) + 0x060BA5DA) + 2);
                r5 = LD32(r14);
                r5 = LD16((80 + r5));
                r4 = LD16(0x060C1AA8);
                SETR(12, 0x060BA5DA);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 20));
                SETPR(0x0607384C);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r0 & 0xFFFF)));
                r4 = LD32(r13);
                r4 = LD16(46 + r4);
                SETR(12, 0x060BA5DA);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 20));
                SETPR(0x0607385C);
                r0 = GCALL1(0x0606B51C, ((r4 & 0xFFFF) & 0x3FF));
                r8 = LD32(r13);
                r4 = LD32(r14);
                r8 = r8 + 46;
                r5 = LD32(r13);
                r5 = LD16(44 + r5);
                r4 = LD8(67 + r4);
                r0 = LD16((((signed char)((r4 << 1) + (r4 << 2))) + 0x060BA5DA) + 4);
                SETR(8, r8);
                SETSP((sp - 20));
                SETPR(0x06073882);
                r0 = GCALL2(0x0606B4D0, (r0 & 0xFFFF), (r5 & 0xFFFF));
                ST16(r8, r0);
            }
            SETSP((sp - 20));
            r0 = GCALL0(0x060738A2);
        } else {
            r4 = LD32(r13);
            SETSP((sp - 20));
            r0 = GCALL2(0x0606AAC8, r4, 0);
            r3 = LD32(r14);
            r1 = LD16(42 + r3);
            ST16(42 + r3, (r1 | 0x2000));
            r5 = LD32(r14);
            r5 = LD16(66 + r5);
            r4 = LD32(r14);
            SETSP((sp - 20));
            r0 = GCALL2(0x0606B07E, r4, ((r5 & 0xFFFF) + 33));
            r4 = LD32(r14);
            r4 = LD16(66 + r4);
            r4 = LD32(0x060B9588 + ((((r4 & 0xFFFF) + 33) << 2) << 2));
            SETSP((sp - 20));
            r0 = GCALL1(0x060144F4, r4);
            r2 = LD32(r14);
            ST16(58 + r2, 90);
            SETSP((sp - 20));
            r0 = GCALL1(0x06014516, 0x0606E864);
        }
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    } else {
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
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

int f06073AEC(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06073AFA);
    r0 = GCALL3(0x0606B0DE, 0x060BA60A, 87, 7);
    r2 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x06073B32);
    r4 = LD32(0x060D7768);
    r4 = LD16(40 + r4);
    SETSP((sp - 8));
    r0 = GCALL1(0x0606D8E6, (r4 & 0xFFFF));
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0);
    r3 = LD32(0x060D7768);
    ST16(68 + r3, 0);
    r4 = 1;
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    r5 = 0x060C1E46;
    r0 = LD16(0x060C1E46);
    r0 = r0 & 0xFFFF;
    if (r0 == 3) {
        return r0;
    } else {
        r2 = LD16(r5);
        ST16(r5, (r2 | r4));
        r0 = LD16(r5);
        r0 = r0 & 0xFFFF;
        if (!(r0 == 3)) {
            return r0;
        } else {
            UNFRAME(sp);
            r0 = GJUMP2(0x060689FC, 0x060BA654, 107);
            return r0;
        }
    }
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

int f06073B72(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06073B7A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD32(0x060D7768);
        ST16(68 + r2, 1);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06073BE0(void)
{
    int r0, r2, r3, r4, r5, r6, r7, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r13 = 0x06014516;
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(68 + r4);
    if ((r0 & r0) == 0) {
        ST32(sp - 20, 11);
        SETSP((sp - 20));
        r0 = GCALL4(0x0606C9BE, -12, 11, -12, 11);
        r4 = r0;
        if ((r0 & r0) == 0) {
            r3 = LD32(r14);
            r0 = LD16(60 + r3);
            if ((r0 & r0) == 0) {
                r0 = 0;
            } else {
                r2 = LD32(r14);
                ST16(68 + r2, 1);
                r2 = LD32(0x060D7B3C);
                ST16(48 + r2, 12);
                r2 = LD32(r14);
                ST16(48 + r2, 17);
                r5 = LD32(r14);
                r5 = LD16(80 + r5);
                r4 = LD16(0x060C1AA8);
                SETR(13, r13);
                SETSP((sp - 20));
                SETPR(0x06073CCC);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
                SETSP((sp - 20));
                r0 = GCALL1(r13, 0x0606D8B6);
                r0 = 1;
            }
        } else {
            r7 = 0x060D5F30;
            r5 = r4 * 124;
            r0 = LD16((r5 + 0x060D5F30) + 36);
            if (!((r0 & 0xFFFF) == 37)) {
                r3 = LD32(r14);
                r0 = LD16(60 + r3);
                if ((r0 & r0) == 0) {
                    r0 = 0;
                } else {
                    r2 = LD32(r14);
                    ST16(68 + r2, 1);
                    r2 = LD32(0x060D7B3C);
                    ST16(48 + r2, 12);
                    r2 = LD32(r14);
                    ST16(48 + r2, 17);
                    r5 = LD32(r14);
                    r5 = LD16(80 + r5);
                    r4 = LD16(0x060C1AA8);
                    SETR(13, r13);
                    SETSP((sp - 20));
                    SETPR(0x06073CCC);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
                    SETSP((sp - 20));
                    r0 = GCALL1(r13, 0x0606D8B6);
                    r0 = 1;
                }
            } else {
                r2 = LD32(r14);
                ST16(66 + r2, r4);
                r6 = r5 + r7;
                r3 = LD32(r14);
                ST16(52 + r3, r4);
                r3 = LD16(0x060C062C);
                ST16(66 + r6, r3);
                r2 = LD16(0x060C062C);
                ST16(52 + r6, r2);
                r3 = LD16(0x060C062C);
                ST32(0x060E215C + ((short)(((r3 << 2) + r3) << 2)), 0x0606B1EC);
                SETSP((sp - 20));
                r0 = GCALL4(r13, 0x06073D4C, r5, r6, r7);
                r0 = 1;
            }
        }
    } else {
        r3 = LD16(60 + r4);
        if (!((r3 & r3) == 0)) {
            r0 = 0;
        } else {
            ST16(68 + r4, 0);
            r3 = LD32(0x060D7B3C);
            ST16(48 + r3, 5);
            r3 = LD32(r14);
            ST16(48 + r3, 16);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(13, r13);
            SETSP((sp - 20));
            SETPR(0x06073C2A);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 11));
            SETSP((sp - 20));
            r0 = GCALL1(r13, 0x0606D8B6);
            r0 = 1;
        }
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06073D4C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    SETSP((sp - 12));
    SETPR(0x06073D58);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        r1 = LD16(68 + (((r4 & 0xFFFF) * 124) + 0x060D5F30));
        if (!((r1 & r1) == 0)) {
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06073D7C);
            r0 = GCALL0(0x06073E02);
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x06073DC6);
            r4 = LD32(r14);
            r4 = LD16(66 + r4);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06073D90);
            r0 = GCALL1(0x0606B194, (r4 & 0xFFFF));
            r2 = LD32(r14);
            ST16(52 + r2, 0);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 12));
            SETPR(0x06073DAC);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 18));
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06073DC6(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06073DCE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r6 = LD32(0x060D7768);
        r5 = LD32(0x060D7768);
        r0 = LD16(r6 + 28);
        r6 = r0;
        r0 = LD16(r5 + 24);
        SETSP((sp - 4));
        SETPR(0x06073DE6);
        r0 = GCALL3(0x0606AE6C, 39, r0, r6);
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            r4 = LD16(0x060C062C);
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP1(0x0606B194, (r4 & 0xFFFF));
            return r0;
        }
    }
}

int f06073E02(void)
{
    int r0, r1, r2, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 12));
    SETPR(0x06073E1C);
    r0 = GCALL3(0x0606AE6C, 71, r0, r6);
    ST32(sp - 12, r0);
    if (!((r0 & r0) == 0)) {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 12));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), -1);
        r2 = LD32(sp - 12);
        r0 = 0x060D5F64;
        r1 = LD16(0x060C062C);
        ST16(0x060D5F64 + (r2 * 124), r1);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
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

int f06073EB8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06073EC2);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7B3C;
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 8));
        r0 = GCALL2(0x0606AAC8, r4, 3);
        r2 = LD32(0x060D7B3C);
        r0 = LD32(0x26006034);
        r3 = r2;
        if ((r0 & 2) == 0) {
            r1 = 0;
        } else {
            r1 = 0x100;
        }
        ST16(70 + r3, r1);
        ST16(68 + r2, r1);
        r3 = LD32(r14);
        r2 = LD16(60 + r3);
        if ((r2 & 0xFFFF) >= 0xFF00) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0606D398);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f060742E4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r14 = 0x060D7768;
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETR(14, 0x060D7768);
    SETSP((sp - 16));
    SETPR(0x06074300);
    r0 = GCALL3(0x0606AE6C, 72, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r4 = (r4 * 124) + 0x060D5F30;
        ST32(sp - 16, r4);
        r0 = LD32(r14);
        r0 = LD8(r0 + 6);
        ST8(r4 + 6, r0);
        r5 = LD32(r14);
        r0 = LD8(r5 + 6);
        r4 = LD32(sp - 16);
        r5 = LD16((80 + r5));
        r5 = (r5 & 0xFFFF) + (r0 & 255);
        r0 = LD16(r4 + 22);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x06074334);
        r0 = GCALL2(0x06068ACC, (r0 & 0xFFFF), (r5 + 12));
        r6 = LD32(r14);
        r0 = LD8(r6 + 6);
        r6 = LD16(0x060B9F7C + ((r0 & 255) << 1));
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 16));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), r6);
    }
    r5 = LD32(0x060D7B3C);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(50 + r5);
    SETR(14, r14);
    SETSP((sp - 16));
    SETPR(0x06074366);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 1));
    r2 = LD32(r14);
    r3 = LD16(42 + r2);
    if (((r3 & 0xFFFF) & 0x2000) == 0) {
        SETSP((sp - 16));
        r0 = GCALL0(0x060743AA);
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x060144F4, 0x0606D8B6);
        return r0;
    } else {
        r3 = LD32(r14);
        r1 = LD16(62 + r3);
        if (!((r1 & r1) == 0)) {
            SETSP((sp - 16));
            r0 = GCALL0(0x060743AA);
            SETMACL(LD32((sp - 12)));
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP1(0x060144F4, 0x0606D8B6);
            return r0;
        } else {
            SETSP((sp - 16));
            r0 = GCALL1(0x060144F4, 0x060743A6);
            SETMACL(LD32((sp - 12)));
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP1(0x06014516, 0x0606D8B6);
            return r0;
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

int f06074424(void)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06074444);
    SETSP((sp - 4));
    SETPR(0x0607443E);
    r0 = GCALL0(0x0606D2E8);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06074444(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 16));
    SETPR(0x06074450);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            r4 = LD32(0x060D7768);
            r0 = LD8(r4 + 4);
            if (((r0 & 255) & 64) == 0) {
                r3 = LD16(66 + r4);
                if ((r3 & r3) == 0) {
                    r0 = LD16(r4 + 24);
                    ST32(sp - 16, (((r0 & 0xFFFF) + 8) & 0xFFF0));
                    r0 = LD16(r4 + 28);
                    r0 = ((r0 & 0xFFFF) + 8) & 0xFFF0;
                    ST32(sp - 12, r0);
                    r5 = LD32(sp - 16);
                    SETSP((sp - 16));
                    SETPR(0x06074498);
                    r0 = GCALL3(0x0606AE6C, 8, r5, r0);
                    r4 = r0;
                    if (!((r4 & r4) == 0)) {
                        r1 = LD16(0x060D5F46 + (r4 * 124));
                        ST16(0x060C385E + (((r1 & 0xFFFF) * 84) & 0xFFFF), 180);
                    }
                    r2 = LD32(0x060D7768);
                    ST16(66 + r2, 1);
                }
            }
            SETSP((sp - 16));
            r0 = GCALL1(0x060144F4, 0x0606D398);
        }
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f06074522(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607452A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r2 = LD16(66 + r4);
        if (!((r2 & r2) == 0)) {
            r0 = LD8(r4 + 6);
            r2 = LD16(((r0 & 255) << 1) + 0x060B90A0);
            r0 = LD16(r4 + 20);
            SETSP((sp - 4));
            SETPR(0x06074562);
            r0 = GCALL1(0x0606C8CA, ((r0 & 0xFFFF) + r2));
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D2C8);
        } else {
            ST16(66 + r4, 1);
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606E7F4);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f06074604(void)
{
    int r0, r1, r2, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06074612);
    r0 = GCALL3(0x0606B0DE, 0x060BA6B0, 0x149, 25);
    r2 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r2 << 2) + r2) << 2)), 0x06074684);
    SETSP((sp - 8));
    r0 = GCALL0(0x060230AE);
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(r4 + 20);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606C82C, (r0 & 0xFFFF), 136);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0607466C);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 32));
    r0 = LD16(0x060C1E3E);
    if (!((r0 & r0) == 0)) {
        r0 = LD8(0x060C1722);
        if ((r0 & r0) == 0) {
            r3 = LD32(r14);
            r0 = LD8(r3 + 4);
            r0 = r0 | 64;
            ST8(r3 + 4, r0);
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0607466C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06074674);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06074684(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607468C);
    r0 = GCALL0(0x060230B8);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x060746AC);
    SETSP((sp - 4));
    SETPR(0x0607469A);
    r0 = GCALL0(0x0606D2E8);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x06014516, 0x0606D37A);
        return r0;
    }
}

int f060746AC(void)
{
    int r0, r1, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 4));
    SETPR(0x060746BA);
    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 0);
    r4 = 0x060EC8B0;
    r5 = LD32(0x060D7768);
    r0 = LD16(r5 + 20);
    r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
    r0 = r0 & 0xFFFF;
    if ((r0 & 7) == 0) {
        r0 = LD16(r5 + 20);
        r0 = (r0 & 0xFFFF) << 1;
        r1 = LD16(r0 + r4);
        ST16(r0 + r4, (r1 & 0xFF77));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D398);
        SETSP((sp - 4));
        SETPR(0x060746EA);
        r0 = GCALL0(0x0606D398);
    }
    SETPR(LD32((sp - 4)));
    return r0;
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

int f06074DC0(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06074DCC);
    r0 = GCALL3(0x0606B0DE, 0x060BA6E8, 160, 13);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 128));
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 4));
    r0 = GCALL2(0x0606950C, r4, 1);
    r1 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r1 << 2) + r1) << 2)), 0x060750D4);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C79A);
    ST16(0x060C277C, 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06074E20);
    SETSP((sp - 4));
    r0 = GCALL0(0x06074E14);
    SETPR(LD32((sp - 4)));
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r12 = 0x060C1AAA;
    r13 = 0x060D7B3C;
    r3 = LD16(0x060C1AAA);
    ST32(sp - 28, (r3 & 0xFFFF));
    r8 = LD32(0x060D7768);
    r4 = LD32(0x060D7B3C);
    r0 = LD16(r4 + 4);
    SETSP((sp - 28));
    r0 = GCALL1(0x060691DA, r0);
    ST16((r8 + 66), r0);
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r4 = LD16(r12);
        r5 = LD16(0x060C1AA8);
        SETSP((sp - 28));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), 1);
        r2 = LD16(r12);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        SETSP((sp - 28));
        r0 = GCALL2(0x0606AAC8, r14, 7);
        r2 = LD32(r13);
        r3 = LD16(44 + r2);
        ST16(44 + r14, r3);
        r2 = LD32(r13);
        r3 = LD16(46 + r2);
        ST16(46 + r14, r3);
        r2 = LD32(r13);
        r3 = LD16(40 + r2);
        ST16(40 + r14, r3);
        r5 = LD32(0x060D7768);
        r4 = LD16(r12);
        r5 = LD16(80 + r5);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 28));
        SETPR(0x0607528A);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 2));
        r0 = LD32(r13);
        r0 = LD16(r0 + 16);
        ST16(r14 + 16, r0);
        r0 = LD32(r13);
        r0 = LD16(r0 + 18);
        ST16(r14 + 18, r0);
        r0 = 82;
        ST16(82 + r14, -32);
    }
    r2 = LD32(sp - 28);
    ST16(r12, r2);
    SETMACL(LD32((sp - 24)));
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06074E14(void)
{
    ST16(LD32(CURRENT) + 62, 0x4B0);
}

int f06074E20(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, c2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    SETPR(0x06074E2A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL0(0x060694B8);
        r4 = 0x060D7768;
        r2 = LD32(0x060D7768);
        r2 = LD16(66 + r2);
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 4);
        ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 4, r0);
        r3 = LD32(0x060D7768);
        r3 = LD16(66 + r3);
        c2 = (r3 & 0xFFFF) * 84;
        r3 = LD32(0x060D7B3C);
        r2 = LD16(66 + r3);
        ST16(66 + (0x060C381C + (c2 & 0xFFFF)), r2);
        r3 = LD32(0x060D7768);
        r2 = LD16(62 + r3);
        if ((r2 & r2) == 0) {
            r3 = LD32(r4);
            ST16(68 + r3, 0);
            r3 = LD32(r4);
            ST16(62 + r3, 0x100);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x06074EF8);
            SETSP((sp - 8));
            r0 = GCALL1(0x0600996A, 147);
        }
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060750D4(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060750DE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x060750FA);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 3));
        r4 = LD32(0x060D7768);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r0 = LD16(r4 + 22);
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x0607510E);
        r0 = GCALL2(0x06068ACC, (r0 & 0xFFFF), ((r5 & 0xFFFF) + 1));
        r2 = LD32(0x060D7768);
        ST16(62 + r2, 240);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0607512C);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607512C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06075138);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r13 = LD32(0x060D7768);
        r0 = LD16(r13 + 20);
        r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
        if (((r0 & 0xFFFF) & 135) == 0) {
            r0 = LD16(r13 + 20);
            SETSP((sp - 12));
            r0 = GCALL2(0x0606C82C, (r0 & 0xFFFF), 128);
        }
        r2 = LD32(r14);
        r0 = LD16(66 + r2);
        if ((r0 & r0) == 0) {
            r1 = LD8(0x060C1722);
            if ((r1 & r1) == 0) {
                r2 = LD32(r14);
                r0 = LD16(62 + r2);
                if (!((r0 & r0) == 0)) {
                    r0 = LD32(0x26006034);
                    if ((r0 & 15) == 0) {
                        SETSP((sp - 12));
                        SETPR(0x060751F6);
                        r0 = GCALL0(0x060752B0);
                    }
                }
                SETPR(LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                r0 = LD32(0x060D7768);
                r0 = LD8(r0 + 4);
                if (((r0 & 255) & 64) == 0) {
                    r2 = LD32(r14);
                    r0 = LD16(62 + r2);
                    if (!((r0 & r0) == 0)) {
                        r0 = LD32(0x26006034);
                        if ((r0 & 15) == 0) {
                            SETSP((sp - 12));
                            SETPR(0x060751F6);
                            r0 = GCALL0(0x060752B0);
                        }
                    }
                    SETPR(LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP0(0x0606D410);
                    return r0;
                } else {
                    SETPR(LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP1(0x060144F4, 0x0606D398);
                    return r0;
                }
            }
        } else {
            r3 = LD32(r14);
            r2 = LD16(62 + r3);
            if (!((r2 & 0xFFFF) >= 40)) {
                r4 = LD32(r14);
                r4 = LD16(66 + r4);
                SETSP((sp - 12));
                r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
                r3 = LD32(r14);
                ST16(66 + r3, 0);
            }
            r2 = LD32(r14);
            r0 = LD16(62 + r2);
            if (!((r0 & r0) == 0)) {
                r0 = LD32(0x26006034);
                if ((r0 & 15) == 0) {
                    SETSP((sp - 12));
                    SETPR(0x060751F6);
                    r0 = GCALL0(0x060752B0);
                }
            }
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        }
    }
}

int f060752B0(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    r13 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r4 = LD16(66 + r4);
    if (((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0) {
        r2 = LD32(r13);
        r0 = LD16(r2 + 22);
        r3 = r0 & 0xFFFF;
    } else {
        r3 = r4 & 0xFFFF;
    }
    ST32(sp - 20, r3);
    SETSP((sp - 20));
    r0 = GCALL1(0x0600996A, 152);
    ST32((sp - 24), 1);
    r2 = LD32(sp - 20);
    ST32((sp - 28), r2);
    r1 = LD32(0x060D7B3C);
    r0 = LD16(r1 + 18);
    r8 = r0 - 80;
    SETSP((sp - 28));
    r0 = GCALL0(0x0600A0B8);
    ST32((sp - 32), (r8 + (r0 & 63)));
    r3 = LD32(0x060D7B3C);
    r0 = LD16(r3 + 16);
    r8 = r0 - 32;
    SETSP((sp - 32));
    r0 = GCALL0(0x0600A0B8);
    ST32((sp - 36), (r8 + (r0 & 63)));
    r3 = LD32(r13);
    r2 = LD16(80 + r3);
    ST32((sp - 40), ((r2 & 0xFFFF) + 4));
    r3 = LD32(0x060D7B3C);
    r2 = LD16(40 + r3);
    ST32((sp - 44), (r2 & 0xFFFF));
    r7 = LD32(0x060D7B3C);
    r7 = LD16(46 + r7);
    r6 = LD32(0x060D7B3C);
    r5 = LD32(0x060D7B3C);
    r6 = LD16(44 + r6);
    r0 = LD16(r5 + 4);
    SETSP((sp - 44));
    SETPR(0x0607533C);
    r0 = GCALL4(0x0606CAE4, 64, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
    SETPR(LD32((sp - 16)));
    SETR(8, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06075384(void)
{
    int r0, r2, r3, r4, r5, r8, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06075390);
    r0 = GCALL3(0x0606B0DE, 0x060BA70E, 160, 13);
    r2 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r2 << 2) + r2) << 2)), 0x0607544E);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C776);
    r3 = LD16(0x060C277C);
    ST16(0x060C277C, (r3 + 1));
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x060753D4);
    r4 = LD16(0x060C1AA8);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x060753D0);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
    SETPR(LD32((sp - 4)));
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    r8 = LD32(0x060D7768);
    SETSP((sp - 20));
    r0 = GCALL1(0x060691DA, 20);
    ST16((r8 + 66), r0);
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r2 = LD16(0x060C1AAA);
        r3 = LD32(0x060D7B3C);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r2 = LD16(44 + r3);
        ST16(44 + r14, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(46 + r3);
        ST16(46 + r14, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(40 + r3);
        ST16(40 + r14, r2);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AAA);
        SETR(13, 0x060D7B3C);
        SETR(14, r14);
        SETSP((sp - 20));
        SETPR(0x06075522);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 12));
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 16);
        ST16(r14 + 16, r0);
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 18);
        ST16(r14 + 18, r0);
    }
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(8, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0607553A(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06075548);
    r0 = GCALL3(0x0606B0DE, 0x060BA71A, 175, 15);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 128));
    SETSP((sp - 8));
    r0 = GCALL1(0x0606947C, 11);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C78E);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 16, 0x060757DE);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x060757A6);
    r3 = LD32(0x060D7768);
    ST16(72 + r3, 0);
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    r3 = LD32(0x060D7768);
    ST16(70 + r3, 0);
    r3 = LD32(0x060D7768);
    ST16(68 + r3, 255);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x06075648);
    r2 = LD32(0x060D7768);
    ST16(62 + r2, 0x168);
    SETPR(LD32((sp - 8)));
    r4 = LD16(0x060C1AA8);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r4 & 0xFFFF), 0);
    return r0;
}

int f060755C8(void)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    r3 = LD32(0x060D7768);
    ST16(68 + r3, 255);
    SETR(14, 0x060D7768);
    SETSP((sp - 8));
    SETPR(0x060755E2);
    r0 = GCALL1(0x0607587C, 0);
    r2 = LD32(0x060D7768);
    ST16(62 + r2, 0x168);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x06075648);
    SETSP((sp - 8));
    SETPR(0x060755F6);
    r0 = GCALL0(0x06075648);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06075648(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06075652);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r0 = LD16(72 + r4);
        if (!((r0 & r0) == 0)) {
            r0 = LD16(r4 + 20);
            r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
            if (((r0 & 0xFFFF) & 7) == 0) {
                r0 = LD8(r4 + 4);
                if (!(((r0 & 255) & 32) == 0)) {
                    SETSP((sp - 8));
                    r0 = GCALL0(0x0606C7C2);
                }
            }
        }
        r2 = LD32(r14);
        r0 = LD16(66 + r2);
        if ((r0 & r0) == 0) {
            r2 = LD32(r14);
            r0 = LD16(72 + r2);
            if (!((r0 & r0) == 0)) {
                r3 = LD32(0x060D7B3C);
                r0 = LD16(r3 + 10);
                if ((r0 & r0) == 0) {
                    SETR(14, r14);
                    SETSP((sp - 8));
                    SETPR(0x060756E4);
                    r0 = GCALL1(0x0607587C, 0);
                }
                r4 = LD32(r14);
                r4 = LD16(62 + r4);
                r4 = r4 & 0xFFFF;
                if (!((unsigned)r4 > (unsigned)32)) {
                    if (!((r4 & r4) == 0)) {
                        if (!((15 & r4) == 0)) {
                            if ((r4 & 7) == 0) {
                                SETSP((sp - 8));
                                SETPR(0x0607571E);
                                r0 = GCALL1(0x0607587C, 5);
                            }
                        } else {
                            SETSP((sp - 8));
                            SETPR(0x06075710);
                            r0 = GCALL1(0x0607587C, 1);
                        }
                    } else {
                        SETR(14, r14);
                        SETSP((sp - 8));
                        SETPR(0x060756FA);
                        r0 = GCALL1(0x0607587C, 0);
                        r3 = LD32(r14);
                        ST16(62 + r3, 0x168);
                    }
                }
            }
        } else {
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06075694);
            r0 = GCALL1(0x0607581A, 150);
            if ((r0 & r0) == 0) {
                SETSP((sp - 8));
                r0 = GCALL1(0x060144F4, 0x060755C8);
            } else {
                SETSP((sp - 8));
                r0 = GCALL1(0x0600996A, 144);
                SETSP((sp - 8));
                r0 = GCALL1(0x060144F4, 0x06075766);
                SETR(14, r14);
                SETSP((sp - 8));
                SETPR(0x060756AC);
                r0 = GCALL1(0x0607587C, 1);
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x0606D88C);
                r3 = LD32(r14);
                ST16(62 + r3, 150);
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

void f06075710(void)
{
    GJUMP0(0x0607571E);
}

int f06075766(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607576E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x060755C8);
            SETSP((sp - 4));
            SETPR(0x06075792);
            r0 = GCALL1(0x0607587C, 5);
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        } else {
            SETSP((sp - 4));
            SETPR(0x06075782);
            r0 = GCALL1(0x0607587C, 3);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060757A6(void)
{
    int r0, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = LD32(0x060D7768);
    r0 = LD16(70 + r14);
    if (!((r0 & r0) == 0)) {
        r4 = LD16(70 + r14);
        SETSP((sp - 8));
        r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
        r3 = LD32(0x060D7768);
        ST16(70 + r3, 0);
    }
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0606D2C8);
    SETSP((sp - 8));
    SETPR(0x060757D8);
    r0 = GCALL0(0x0606D2C8);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0607587C(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r14 = 0x060D7768;
    r13 = LD32(0x060D7768);
    r0 = LD16(70 + r13);
    r12 = r4;
    if (!((r0 & r0) == 0)) {
        r4 = LD16(70 + r13);
        SETSP((sp - 24));
        r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
        r2 = LD32(r14);
        ST16(70 + r2, 0);
    }
    r5 = LD32(r14);
    r5 = LD16(80 + r5);
    r4 = LD16(0x060C1AA8);
    SETR(12, r12);
    SETR(14, r14);
    SETSP((sp - 24));
    SETPR(0x060758BC);
    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + r12));
    r3 = 1;
    if ((unsigned)r12 >= (unsigned)1) {
        r8 = LD32(r14);
        r8 = r8 + 70;
        ST32((sp - 28), r3);
        r2 = LD16(0x060C1AA8);
        ST32((sp - 32), (r2 & 0xFFFF));
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 18);
        ST32((sp - 36), r0);
        r2 = LD32(0x060D7B3C);
        r0 = LD16(r2 + 16);
        ST32((sp - 40), r0);
        r2 = LD32(r14);
        r1 = LD16(80 + r2);
        ST32((sp - 44), ((r12 + (r1 & 0xFFFF)) + 1));
        r2 = LD32(0x060D7B3C);
        r1 = LD16(40 + r2);
        ST32((sp - 48), (r1 & 0xFFFF));
        r7 = LD32(0x060D7B3C);
        r7 = LD16(46 + r7);
        r6 = LD32(0x060D7B3C);
        r6 = LD16(44 + r6);
        SETR(8, r8);
        SETR(14, r14);
        SETSP((sp - 48));
        SETPR(0x0607590E);
        r0 = GCALL4(0x0606CAE4, 0, 10, (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST16(r8, r0);
        r0 = r0 & 0xFFFF;
        if (!((r0 & r0) == 0)) {
            r4 = LD32(r14);
            r2 = LD16(70 + r4);
            r4 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            r1 = LD16(42 + r4);
            ST16(42 + r4, (r1 | 0x400));
            r0 = LD16(r4 + 18);
            ST16(r4 + 18, (r0 + 10));
            r0 = 38;
            r1 = LD16(38 + r4);
            ST16(38 + r4, (r1 - 10));
        }
    }
    SETMACL(LD32((sp - 24)));
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06075950(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r14;
    ENTRY_SP(sp);

    r4 = 1;
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    ST32(sp - 16, r4);
    SETSP((sp - 16));
    SETPR(0x0607598C);
    r0 = GCALL3(0x0606B0DE, 0x060BA734, 173, 14);
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 128));
    SETSP((sp - 16));
    r0 = GCALL1(0x0606947C, 11);
    SETSP((sp - 16));
    r0 = GCALL0(0x0606C79A);
    r3 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x06075AC0);
    SETSP((sp - 16));
    r0 = GCALL1(0x060144F4, 0x06075A14);
    r0 = LD32(sp - 16);
    if ((r0 & r0) == 0) {
        r2 = LD32(r14);
        r0 = 66;
        ST16(66 + r2, 0);
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r8 = LD32(r14);
        r6 = LD32(r14);
        r8 = r8 + 66;
        r5 = LD32(r14);
        r0 = LD16(r6 + 28);
        r6 = r0;
        r0 = LD16(r5 + 24);
        SETR(8, r8);
        SETSP((sp - 16));
        SETPR(0x060759E0);
        r0 = GCALL3(0x0606AE6C, 47, r0, r6);
        ST16(r8, r0);
        r0 = r0 & 0xFFFF;
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 12)));
            SETR(8, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r5 = LD16(0x060C1AA8);
            r4 = LD16(0x060C1AAA);
            SETPR(LD32((sp - 12)));
            SETR(8, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), -1);
            return r0;
        }
    }
}

int f06075954(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r14;
    ENTRY_SP(sp);

    r4 = 0;
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    ST32(sp - 16, r4);
    SETSP((sp - 16));
    SETPR(0x0607598C);
    r0 = GCALL3(0x0606B0DE, 0x060BA734, 173, 14);
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 128));
    SETSP((sp - 16));
    r0 = GCALL1(0x0606947C, 11);
    SETSP((sp - 16));
    r0 = GCALL0(0x0606C79A);
    r3 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x06075AC0);
    SETSP((sp - 16));
    r0 = GCALL1(0x060144F4, 0x06075A14);
    r0 = LD32(sp - 16);
    if ((r0 & r0) == 0) {
        r2 = LD32(r14);
        r0 = 66;
        ST16(66 + r2, 0);
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r8 = LD32(r14);
        r6 = LD32(r14);
        r8 = r8 + 66;
        r5 = LD32(r14);
        r0 = LD16(r6 + 28);
        r6 = r0;
        r0 = LD16(r5 + 24);
        SETR(8, r8);
        SETSP((sp - 16));
        SETPR(0x060759E0);
        r0 = GCALL3(0x0606AE6C, 47, r0, r6);
        ST16(r8, r0);
        r0 = r0 & 0xFFFF;
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 12)));
            SETR(8, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r5 = LD16(0x060C1AA8);
            r4 = LD16(0x060C1AAA);
            SETPR(LD32((sp - 12)));
            SETR(8, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), -1);
            return r0;
        }
    }
}

int f06075A14(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    SETPR(0x06075A1E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r0 = LD16(66 + r4);
        if (!((r0 & r0) == 0)) {
            r7 = 124;
            r6 = 0x060D5F30;
            r3 = LD16(66 + r4);
            r1 = LD16(66 + (((r3 & 0xFFFF) * 124) + 0x060D5F30));
            if (!((r1 & r1) == 0)) {
                r0 = LD8(r4 + 4);
                ST8(r4 + 4, (r0 | 64));
                r3 = LD32(r5);
                r0 = LD16(66 + r3);
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(r5);
                    r3 = LD16(66 + r2);
                    ST16(72 + (r6 + ((r3 & 0xFFFF) * r7)), 1);
                }
            }
        }
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06075AC0(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    SETPR(0x06075ACA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r0 = LD16(66 + r4);
        if (!((r0 & r0) == 0)) {
            r3 = LD16(66 + r4);
            ST16(0x060D5F78 + ((r3 & 0xFFFF) * 124), 1);
        }
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0606D2C8);
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06075B04(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06075B12);
    r0 = GCALL3(0x0606B0DE, 0x060BA744, 0x13E, 13);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C79A);
    r3 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x06075C38);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x06075B76);
    r2 = LD32(0x060D7768);
    ST8(r2 + 6, 2);
    r3 = LD32(0x060D7768);
    ST16(62 + r3, 0x168);
    r5 = LD32(0x060D7768);
    r0 = LD16(r5 + 28);
    r4 = LD32(0x060D7768);
    r5 = (int)((unsigned)(r0 & 0xFFFF) >> 2);
    r0 = LD16(r4 + 24);
    SETSP((sp - 8));
    SETPR(0x06075B5C);
    r0 = GCALL2(0x0605ECD8, ((int)((unsigned)((int)((unsigned)(r0 & 0xFFFF) >> 2)) >> 2)), ((int)((unsigned)r5 >> 2)));
    r4 = LD16(0x060C062C);
    SETSP((sp - 8));
    r0 = GCALL1(0x0605F1D0, (r4 & 0xFFFF));
    r2 = LD32(0x060D7B3C);
    ST16(38 + r2, -24);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 38;
}

int f06075C38(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06075C40);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D2C8);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
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

int f06075D98(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    r14 = 0;
    ST32((sp - 12), R(12));
    r13 = 0x060C27C0;
    r12 = 0x060D7B3C;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r8 = 1;
    r9 = 0x400;
    ST32((sp - 36), MACL());
    ST32(0x060C27C0, ((((r4 << 2) << 2) << 1) + 0x060C277E));
    ST32(sp - 56, 0);
    ST32(sp - 48, 0);
    ST32(sp - 52, 0);
    ST32(sp - 44, 0);
    ST16(sp - 40, 5);
    while (1) {
        r3 = LD32(r13);
        r10 = LD32(sp - 56);
        r10 = r10 << 1;
        ST16(((r3 + 26) + r10), r14);
        r3 = LD32(r13);
        ST16(((r3 + 2) + r10), 64);
        r3 = LD32(r13);
        r0 = LD16(((r3 + 8) + r10));
        r11 = LD32(r12);
        if (!((r0 & r0) == 0)) {
            r4 = LD32(r13);
            r4 = LD16(((r4 + 8) + r10));
            SETR(9, r9);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 56));
            SETPR(0x06075EA4);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), 0);
        } else {
            r3 = LD32(r13);
            ST32((sp - 60), ((r3 + 8) + r10));
            ST32((sp - 64), r8);
            r2 = LD16(0x060C1AA8);
            ST32((sp - 68), (r2 & 0xFFFF));
            r0 = LD16(r11 + 18);
            ST32((sp - 72), r0);
            r2 = LD16(0x060BA75A + r10);
            r0 = LD16(r11 + 16);
            ST32((sp - 76), (r0 + r2));
            ST32((sp - 80), r14);
            r1 = LD16(40 + r11);
            ST32((sp - 84), (r1 & 0xFFFF));
            r7 = LD16(46 + r11);
            r6 = LD16(44 + r11);
            r0 = LD16(r11 + 4);
            SETR(9, r9);
            SETR(10, r10);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 84));
            SETPR(0x06075E32);
            r0 = GCALL4(0x0606CAE4, r14, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
            r1 = LD32((sp - 60));
            ST16(r1, r0);
            r11 = LD32(r13);
            r2 = LD16(((r11 + 8) + r10));
            r11 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            SETSP((sp - 56));
            r0 = GCALL2(0x0606AAC8, r11, 3);
            ST16(38 + r11, -16);
            ST16(72 + r11, r14);
            ST16(74 + r11, -6);
            ST16(70 + r11, r14);
            r3 = LD16(42 + r11);
            ST16(42 + r11, (r3 | r9));
        }
        r1 = LD32(r13);
        r3 = LD32(sp - 44);
        r2 = LD16(((r1 + 14) + r3));
        if (!((r2 & r2) == 0)) {
            r4 = LD32(r13);
            r3 = LD32(sp - 48);
            r4 = LD16(((r4 + 14) + r3));
            SETR(9, r9);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 56));
            SETPR(0x06075F58);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), 0);
        } else {
            r3 = LD32(r13);
            r11 = LD32(sp - 52);
            ST32((sp - 60), ((r3 + 14) + r11));
            ST32((sp - 64), r8);
            r2 = LD16(0x060C1AA8);
            ST32((sp - 68), (r2 & 0xFFFF));
            r1 = LD32(r12);
            r0 = LD16(r1 + 18);
            ST32((sp - 72), r0);
            r2 = LD32(r12);
            r0 = LD16(r2 + 16);
            r2 = LD16(0x060BA75A + r11);
            ST32((sp - 76), (r0 + r2));
            ST32((sp - 80), r14);
            r2 = LD32(r12);
            r1 = LD16(40 + r2);
            ST32((sp - 84), (r1 & 0xFFFF));
            r7 = LD32(r12);
            r7 = LD16(46 + r7);
            r6 = LD32(r12);
            r6 = LD16(44 + r6);
            r5 = LD32(r12);
            r0 = LD16(r5 + 4);
            SETR(9, r9);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 84));
            SETPR(0x06075F02);
            r0 = GCALL4(0x0606CAE4, r14, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
            r1 = LD32((sp - 60));
            ST16(r1, r0);
            r3 = LD32(r13);
            r2 = LD16((r11 + (r3 + 14)));
            r11 = 0x060C381C + (((r2 & 0xFFFF) * 84) & 0xFFFF);
            SETSP((sp - 56));
            r0 = GCALL2(0x0606AAC8, r11, 3);
            ST16(38 + r11, -16);
            ST16(72 + r11, r14);
            r0 = LD16(sp - 40);
            ST16((74 + r11), r0);
            ST16(70 + r11, 0x100);
            r3 = LD16(42 + r11);
            ST16(42 + r11, (r3 | r9));
        }
        r3 = LD32(sp - 56);
        ST32(sp - 56, (r3 + 1));
        r2 = LD32(sp - 48);
        ST32(sp - 48, (r2 + 2));
        r1 = LD32(sp - 52);
        ST32(sp - 52, (r1 + 2));
        r3 = LD32(sp - 44);
        ST32(sp - 44, (r3 + 2));
        r0 = LD32(sp - 56);
        if ((unsigned)r0 >= (unsigned)3) {
            break;
        }
        POLL();
    }
    SETMACL(LD32((sp - 36)));
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

int f06075F92(int r4, int r5, int r6)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 16, r4);
    ST32(sp - 12, r5);
    ST32(sp - 20, r6);
    r6 = LD32(sp - 12);
    r5 = LD32(sp - 16);
    SETSP((sp - 20));
    SETPR(0x06075FA8);
    r0 = GCALL3(0x0606AE6C, 48, r5, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD32(sp - 20);
        r0 = 0x060D5F78;
        ST16(0x060D5F78 + (r4 * 124), r2);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06075FE8(void)
{
    int r0, r2, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06075FF8);
    r0 = GCALL3(0x0606B0DE, 0x060BA760, 0x143, 14);
    SETSP((sp - 12));
    r0 = GCALL0(0x0606C7FE);
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x06076070);
    r2 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r2 << 2) + r2) << 2)), 0x06076048);
    r3 = LD32(0x060D7768);
    ST8(r3 + 6, 2);
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    r8 = LD32(0x060D7768);
    SETSP((sp - 12));
    r0 = GCALL0(0x06075C6E);
    ST16((r8 + 70), r0);
    r3 = LD32(0x060D7B3C);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 0x400));
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 42;
}

int f06076048(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06076050);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD8(0x060C1722);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D2C8);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06076070(int r4, int r5, int r6, int r7)
{
    int r0, r8, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0607607C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 12));
        SETPR(0x06076094);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (r5 & 0xFFFF));
        r8 = LD32(0x060D7768);
        SETSP((sp - 12));
        r0 = GCALL0(0x0607612C);
        ST16((r8 + 68), r0);
        if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x060761BE);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 12));
            SETPR(0x060760BE);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f060761BE(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060761C8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r2 = LD16(66 + r3);
        if (!(((r2 & 0xFFFF) & 15) == 15)) {
            r4 = 0x06076070;
        } else {
            r4 = 0x06076250;
        }
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, r4);
        r5 = LD32(r14);
        r3 = LD32(r14);
        r5 = LD16(80 + r5);
        r2 = LD16(68 + r3);
        r4 = LD16(0x060C1AA8);
        SETSP((sp - 8));
        SETPR(0x06076208);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r2 & 0xFFFF)));
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06076250(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607625A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r1 = LD16(72 + r3);
        ST16(72 + r3, (r1 & 1));
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x060762AE);
        r2 = LD32(0x060D7768);
        ST16(60 + r2, 0xE10);
        SETSP((sp - 8));
        r0 = GCALL1(0x0600996A, 112);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AA8);
        SETSP((sp - 8));
        SETPR(0x06076298);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 6));
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060762AE(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x060762BC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 16));
        r0 = GCALL1(0x060144F4, 0x06076374);
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 20);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606C82C, ((r0 & 0xFFFF) - 1), 136);
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 20);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606C82C, (r0 & 0xFFFF), 136);
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 20);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606C82C, ((r0 & 0xFFFF) + 1), 136);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AA8);
        SETR(14, 0x060D7768);
        SETSP((sp - 16));
        SETPR(0x06076304);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 8));
        r4 = LD32(0x060D7768);
        r4 = LD16(70 + r4);
        SETR(14, 0x060D7768);
        SETSP((sp - 16));
        SETPR(0x0607630E);
        r0 = GCALL1(0x06075D98, (r4 & 0xFFFF));
        r2 = LD32(0x060D7768);
        ST16(66 + r2, 0);
        SETSP((sp - 16));
        r0 = GCALL1(0x0600996A, 113);
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06076374(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r11, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    SETSP((sp - 24));
    SETPR(0x06076386);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060C27C0;
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r2 = LD16(70 + r3);
        ST32(0x060C27C0, (((((r2 & 0xFFFF) << 2) << 2) << 1) + 0x060C277E));
        SETSP((sp - 24));
        r0 = GCALL0(0x06076658);
        SETR(13, 0x060C27C0);
        SETR(14, 0x060D7768);
        SETSP((sp - 24));
        SETPR(0x060763A8);
        r0 = GCALL0(0x060766D8);
        r5 = LD32(0x060D7768);
        r3 = LD32(0x060D7768);
        r5 = LD16(66 + r5);
        r5 = LD16(0x060BA7C2 + ((r5 & 0xFFFF) << 1));
        r2 = LD16(80 + r3);
        r4 = LD16(0x060C1AA8);
        SETR(13, 0x060C27C0);
        SETR(14, 0x060D7768);
        SETSP((sp - 24));
        SETPR(0x060763CC);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r2 & 0xFFFF)));
        r4 = LD32(0x060C27C0);
        r4 = r4 + 26;
        r0 = LD16(r4);
        r3 = r0 & 0xFFFF;
        r0 = LD16(r4 + 2);
        r3 = (r0 & 0xFFFF) & r3;
        r0 = LD16(r4 + 4);
        if (!((((r0 & 0xFFFF) & r3) & 2) == 0)) {
            SETSP((sp - 24));
            r0 = GCALL1(0x06009A3A, 113);
            r5 = LD32(r13);
            r0 = LD16(r5 + 20);
            SETSP((sp - 24));
            r0 = GCALL2(0x06076854, 0, (((r0 & 0xFFFF) + 1) & 7));
            ST32(sp - 24, r0);
            r5 = LD32(r13);
            r0 = LD16(r5 + 22);
            SETSP((sp - 24));
            r0 = GCALL2(0x06076854, 1, (((r0 & 0xFFFF) + 1) & 7));
            r11 = r0;
            r5 = LD32(r13);
            r0 = LD16(r5 + 24);
            SETSP((sp - 24));
            r0 = GCALL2(0x06076854, 2, (((r0 & 0xFFFF) + 1) & 7));
            r4 = r0;
            r2 = LD32(sp - 24);
            if (!(r2 == r11)) {
                r3 = LD32(r14);
                ST16(62 + r3, 60);
                SETSP((sp - 24));
                r0 = GCALL1(0x060144F4, 0x06076488);
            } else {
                if (!(r11 == r4)) {
                    r3 = LD32(r14);
                    ST16(62 + r3, 60);
                    SETSP((sp - 24));
                    r0 = GCALL1(0x060144F4, 0x06076488);
                } else {
                    SETSP((sp - 24));
                    r0 = GCALL1(0x0600996A, 105);
                    SETSP((sp - 24));
                    r0 = GCALL1(0x060144F4, 0x06076540);
                    r5 = LD32(r14);
                    r4 = LD16(0x060C1AA8);
                    r5 = LD16(80 + r5);
                    SETSP((sp - 24));
                    SETPR(0x0607644E);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 15));
                    SETSP((sp - 24));
                    r0 = GCALL1(0x06014516, 0x0606D88C);
                }
            }
        }
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06076488(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06076494);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r13 = LD32(0x060D7768);
        r0 = LD16(62 + r13);
        if ((r0 & r0) == 0) {
            r1 = LD16(60 + r13);
            if ((r1 & r1) == 0) {
                r4 = LD16(70 + r13);
                SETSP((sp - 12));
                r0 = GCALL1(0x06075CEE, (r4 & 0xFFFF));
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x06076528);
                r5 = LD32(r14);
                r5 = LD16(80 + r5);
                r4 = LD16(0x060C1AA8);
                SETR(14, r14);
                SETSP((sp - 12));
                SETPR(0x060764DC);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 7));
                SETSP((sp - 12));
                r0 = GCALL1(0x06014516, 0x0606D8B6);
                r0 = LD32(r14);
                r0 = LD16(r0 + 20);
                r0 = ((r0 & 0xFFFF) - 1) << 1;
                r3 = LD16(r0 + 0x060EC8B0);
                ST16(r0 + 0x060EC8B0, (r3 & 0xFFF7));
                r0 = LD32(r14);
                r0 = LD16(r0 + 20);
                r0 = (r0 & 0xFFFF) << 1;
                r3 = LD16(r0 + 0x060EC8B0);
                ST16(r0 + 0x060EC8B0, (r3 & 0xFFF7));
                r3 = LD32(r14);
                r0 = LD16(r3 + 20);
                r3 = ((r0 & 0xFFFF) << 1) + 0x060EC8B0;
                r0 = LD16(r3 + 2);
                ST16(r3 + 2, (r0 & 0xFFF7));
            } else {
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x060762AE);
            }
        }
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06076528(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06076530);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06076540(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607654A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r2 = LD16(70 + r3);
        r2 = ((((r2 & 0xFFFF) << 2) << 2) << 1) + 0x060C277E;
        ST32(0x060C27C0, r2);
        r0 = LD16(r2 + 20);
        SETSP((sp - 8));
        r0 = GCALL2(0x06076854, 0, ((r0 & 0xFFFF) + 1));
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x06076576);
        r0 = GCALL1(0x06076874, (7 & r0));
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x0607658A);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 16));
        r3 = LD32(0x060D7768);
        ST16(62 + r3, 60);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x06076608);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06076608(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06076610);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r0 = LD16(62 + r4);
        if ((r0 & r0) == 0) {
            ST16(62 + r4, 240);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x06076488);
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x06076644);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 17));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f060766D8(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 0;
    r14 = 0x060C27C0;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    r9 = 7;
    r10 = 0x100;
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    while (1) {
        r0 = LD32(r14);
        r13 = r11 << 1;
        r2 = LD16(((r0 + 8) + r13));
        r2 = r2 & 0xFFFF;
        ST32(sp - 44, r2);
        r0 = LD32(0x060D7B3C);
        r12 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r0 = LD16(r0 + 4);
        ST16(r12 + 4, r0);
        r0 = LD32(r14);
        r1 = LD16(((r0 + 14) + r13));
        r1 = r1 & 0xFFFF;
        ST32(sp - 40, r1);
        r8 = (((r1 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 4);
        ST16(r8 + 4, r0);
        r3 = LD32(r14);
        r0 = LD16(((r3 + 2) + r13));
        if (!((r0 & r0) == 0)) {
            r1 = LD32(r14);
            r3 = LD16(((r1 + 2) + r13));
            r1 = LD16(70 + r12);
            ST16(70 + r12, (r1 + r3));
            r0 = LD16(70 + r12);
            if ((r0 & 0xFFFF) >= r10) {
                ST16(70 + r12, 0);
                r0 = LD32(r14);
                r0 = LD16((r0 + 26) + r13);
                if (!(((r0 & 0xFFFF) & 1) == 0)) {
                    r3 = LD32(r14);
                    r3 = (r3 + 2) + r13;
                    r1 = LD16(r3);
                    ST16(r3, (r1 - 8));
                    r3 = LD32(r14);
                    r1 = LD16(((r3 + 2) + r13));
                    if ((r1 & r1) == 0) {
                        r3 = LD32(r14);
                        r3 = (r3 + 26) + r13;
                        r0 = LD16(r3);
                        ST16(r3, (r0 | 2));
                        SETSP((sp - 44));
                        r0 = GCALL1(0x0600996A, 114);
                    }
                }
                r3 = LD32(r14);
                r3 = (r3 + 20) + r13;
                r2 = LD16(r3);
                ST16(r3, (r2 - 1));
                r3 = LD32(r14);
                r3 = (r3 + 20) + r13;
                r0 = LD16(r3);
                ST16(r3, (r0 & 7));
            }
            r2 = LD16(70 + r12);
            ST16(70 + r8, ((-r2) + r10));
            r3 = LD32(0x060D7768);
            r2 = LD16(80 + r3);
            ST32((sp - 48), ((r2 & 0xFFFF) + 21));
            r5 = LD32(r14);
            r5 = LD16(((r5 + 20) + r13));
            SETSP((sp - 48));
            r0 = GCALL2(0x06076854, r11, ((r5 & 0xFFFF) & r9));
            r5 = LD32((sp - 48));
            r4 = LD32(sp - 44);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 44));
            SETPR(0x060767E6);
            r0 = GCALL2(0x06068A8E, r4, (r5 + r0));
            r2 = LD32(0x060D7768);
            r1 = LD16(80 + r2);
            ST32((sp - 48), ((r1 & 0xFFFF) + 21));
            r5 = LD32(r14);
            r5 = LD16(((r5 + 20) + r13));
            SETSP((sp - 48));
            r0 = GCALL2(0x06076854, r11, (((r5 & 0xFFFF) + 1) & r9));
            r5 = LD32((sp - 48));
            r4 = LD32(sp - 40);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(14, r14);
            SETSP((sp - 44));
            SETPR(0x06076812);
            r0 = GCALL2(0x06068A8E, r4, (r5 + r0));
        }
        r11 = r11 + 1;
        if ((unsigned)r11 >= (unsigned)3) {
            break;
        }
        POLL();
    }
    SETMACL(LD32((sp - 36)));
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

unsigned char f06076854(int a, int b)
{
    return LD8(0x060BA7D2 + ((LDU16(LD32(CURRENT) + 72) * 3 + a) << 3) + b);
}

int f06076874(int r4)
{
    int r0, r2, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 12, r4);
    r6 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r5 = LD32(0x060D7768);
    r6 = r0 + 0xFFE0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 12));
    SETPR(0x06076894);
    r0 = GCALL3(0x0606AE6C, 49, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD32(sp - 12);
        r0 = 0x060D5F72;
        ST16(0x060D5F72 + (r4 * 124), r2);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
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

int f0607690E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06076918);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7B3C);
        r2 = LD16(38 + r4);
        if (!(r2 > -256)) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x060769DC);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, 0x060D7768);
            SETSP((sp - 8));
            SETPR(0x06076952);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 30));
            r3 = LD32(0x060D7B3C);
            r1 = LD16(38 + r3);
            ST16(38 + r3, (r1 - 32));
            r3 = LD32(0x060D7768);
            r0 = LD16(r3 + 68);
            ST16(r3 + 24, r0);
            r3 = LD32(0x060D7768);
            r0 = LD16(r3 + 70);
            ST16(r3 + 28, (r0 + 48));
        } else {
            r2 = LD16(38 + r4);
            ST16(38 + r4, (r2 - 2));
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060769DC(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    SETPR(0x060769EC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r14 = 0x060D7B3C;
        r4 = LD32(0x060D7B3C);
        r3 = LD16(38 + r4);
        if (r3 >= 0) {
            SETSP((sp - 20));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
            r3 = LD32(r13);
            r0 = LD16(r3 + 20);
            r3 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
            if (((r3 & 0xFFFF) & 0x42F7) == 0) {
                r5 = LD32(r13);
                r4 = LD32(r13);
                r0 = LD16(r5 + 20);
                r4 = LD16(66 + r4);
                r4 = LD8(0x060BA80E + (r4 & 0xFFFF));
                SETSP((sp - 20));
                SETPR(0x06076ABA);
                r0 = GCALL2(0x06022446, (r4 & 255), (r0 & 0xFFFF));
            }
        } else {
            r2 = LD16(38 + r4);
            ST16(38 + r4, (r2 + 1));
            r3 = LD32(r13);
            r0 = LD16(72 + r3);
            if ((r0 & r0) == 0) {
                r8 = LD32(r13);
                r8 = r8 + 72;
                ST32((sp - 24), 0);
                ST32((sp - 28), 0);
                r2 = LD32(r14);
                r0 = LD16(r2 + 18);
                ST32((sp - 32), r0);
                r3 = LD32(r14);
                r0 = LD16(r3 + 16);
                ST32((sp - 36), r0);
                r3 = LD32(r13);
                r2 = LD16(80 + r3);
                ST32((sp - 40), ((r2 & 0xFFFF) + 28));
                r3 = LD32(r14);
                r2 = LD16(40 + r3);
                ST32((sp - 44), (r2 & 0xFFFF));
                r7 = LD32(r14);
                r6 = LD32(r14);
                r7 = LD16(46 + r7);
                r6 = LD16(44 + r6);
                SETR(8, r8);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 44));
                SETPR(0x06076A54);
                r0 = GCALL4(0x0606CAE4, 0, 10, (r6 & 0xFFFF), (r7 & 0xFFFF));
                ST16(r8, r0);
            }
            r3 = LD32(r13);
            r0 = LD16(74 + r3);
            if ((r0 & r0) == 0) {
                r4 = LD32(r14);
                r0 = LD16(r4 + 18);
                r4 = LD16((38 + r4));
                if ((r4 + r0) >= 0) {
                    SETSP((sp - 20));
                    r0 = GCALL1(0x0600996A, 116);
                    r3 = LD32(r13);
                    ST16(74 + r3, 1);
                }
            }
        }
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f06076B3C(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06076B4A);
    r0 = GCALL3(0x0606B0DE, 0x060BA816, 0x12B, 15);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C776);
    r3 = LD32(0x060D7768);
    ST16(68 + r3, 0);
    r3 = LD32(0x060D7768);
    ST16(70 + r3, 0);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154), 0x06076BBC);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x06076BE0);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 8, 0x06076C66);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x06077024);
    r4 = LD32(0x060D7768);
    SETPR(LD32((sp - 8)));
    r4 = LD16(40 + r4);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0606D8E6, (r4 & 0xFFFF));
    return r0;
}

int f06076BBC(void)
{
    int s = GCALL1(0x0606CE8C, LD32(0x26006034) & 255);

    ST16(LD32(MOVER_PTR) + 38, HELPER((s - 4) >> 14));
    return 0;
}

int f06076BE0(void)
{
    int r0, r1, r2, r4, r6, r7, r11, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r11 = 0x060D7B3C;
    r13 = LD32(0x060D7768);
    r0 = LD16(70 + r13);
    r14 = LD32(0x060D7B3C);
    if ((r0 & r0) == 0) {
        ST32((sp - 28), 0);
        ST32((sp - 32), 0);
        r0 = LD16(r14 + 18);
        ST32((sp - 36), r0);
        r0 = LD16(r14 + 16);
        ST32((sp - 40), r0);
        r2 = LD16(80 + r13);
        ST32((sp - 44), ((r2 & 0xFFFF) + 3));
        r1 = LD16(40 + r14);
        ST32((sp - 48), (r1 & 0xFFFF));
        r7 = LD16(46 + r14);
        r6 = LD16(44 + r14);
        SETR(11, r11);
        SETR(13, r13);
        SETSP((sp - 48));
        SETPR(0x06076C30);
        r0 = GCALL4(0x0606CAE4, 0, 20, (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST16((70 + r13), r0);
    }
    r4 = LD32(0x060D7768);
    r1 = LD16(70 + r4);
    r0 = LD32(r11);
    r0 = LD16(r0 + 16);
    r4 = (((r1 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    ST16(r4 + 16, r0);
    r0 = LD32(r11);
    r0 = LD16(r0 + 18);
    ST16(r4 + 18, r0);
    SETMACL(LD32((sp - 24)));
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f06076D1A(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    SETSP((sp - 24));
    SETPR(0x06076D2C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 24));
        r0 = GCALL1(0x060144F4, 0x06076DDA);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(12, 0x060D7768);
        SETSP((sp - 24));
        SETPR(0x06076D4E);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
        r3 = LD32(0x060D7768);
        ST16(66 + r3, 0);
        r8 = LD32(0x060D7768);
        r8 = r8 + 68;
        ST32((sp - 28), 0);
        ST32((sp - 32), 0);
        r2 = LD32(0x060D7B3C);
        r0 = LD16(r2 + 18);
        ST32((sp - 36), r0);
        r3 = LD32(0x060D7B3C);
        r0 = LD16(r3 + 16);
        ST32((sp - 40), r0);
        ST32((sp - 44), 0);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(40 + r3);
        ST32((sp - 48), (r2 & 0xFFFF));
        r7 = LD32(0x060D7B3C);
        r6 = LD32(0x060D7B3C);
        r7 = LD16(46 + r7);
        r5 = LD32(0x060D7B3C);
        r6 = LD16(44 + r6);
        r0 = LD16(r5 + 4);
        SETR(8, r8);
        SETR(12, 0x060D7768);
        SETSP((sp - 48));
        SETPR(0x06076D94);
        r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST16(r8, r0);
        r14 = LD32(0x060D7768);
        r2 = LD16(68 + r14);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        SETSP((sp - 24));
        r0 = GCALL2(0x0606AAC8, r14, 4);
        r2 = LD16(46 + r14);
        ST16(46 + r14, (r2 + 17));
        SETSP((sp - 24));
        SETPR(0x06076DBC);
        r0 = GCALL0(0x06076EC8);
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06076DDA(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06076DE4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            SETSP((sp - 8));
            r0 = GCALL1(0x06009A3A, 190);
            r4 = LD32(r14);
            SETSP((sp - 8));
            r0 = GCALL1(0x0606CC12, (r4 + 68));
            SETSP((sp - 8));
            r0 = GCALL0(0x060145A8);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06076E82);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 2));
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606D8B6);
            r2 = LD32(r14);
            ST16(62 + r2, 0x384);
        } else {
            r1 = LD32(r14);
            r2 = LD16(66 + r1);
            ST16(66 + r1, (r2 + 1));
            SETSP((sp - 8));
            SETPR(0x06076E08);
            r0 = GCALL0(0x06076EC8);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
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

int f060771D4(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060771DC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 28);
        if (!((r0 & 0xFFFF) >= 0x1D0)) {
            r0 = LD16(r4 + 28);
            ST16(r4 + 28, (r0 + 4));
        } else {
            ST16(0x060C27C8, 1);
            SETSP((sp - 4));
            SETPR(0x060771F6);
            r0 = GCALL0(0x06077ED8);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607723A);
            r0 = LD16(0x060C1E5C);
            if (!((r0 & r0) == 0)) {
                SETSP((sp - 4));
                r0 = GCALL0(0x06078DB0);
            }
            SETSP((sp - 4));
            r0 = GCALL0(0x0603EFDA);
            r2 = LD32(0x060D7768);
            ST16(58 + r2, 240);
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606E864);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607723A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077242);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607727E);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06077262);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 & 0xFFFF));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 76);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607727E(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD16(0x060C062C);
    ST32(0x060E2158 + ((short)(((r3 << 2) + r3) << 2)), 0x06077E20);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 & 0xFFDF));
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7AA);
    r0 = LD16(0x060C062C);
    ST32((0x060E215C + ((short)(((r0 << 2) + r0) << 2))), 0x060774A8);
    SETSP((sp - 4));
    r0 = GCALL0(0x06039FA4);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060775C6, 0);
    return r0;
}

int f06077330(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST16(0x060C27CE, 0);
    SETSP((sp - 4));
    SETPR(0x0607733C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD32(0x060E2150);
        r3 = LD32(r0 + 8);
        SETSP((sp - 4));
        SETPR(0x0607734A);
        r0 = GCALL0(r3);
        if (!((r0 & r0) == 0)) {
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            SETSP((sp - 4));
            r0 = GCALL0(0x0606DA9E);
            SETSP((sp - 4));
            r0 = GCALL0(0x0606DA3C);
            SETSP((sp - 4));
            r0 = GCALL0(0x0606D95C);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                r2 = LD16(0x060C27EE);
                if ((r2 & r2) == 0) {
                    r4 = 32;
                } else {
                    r4 = 16;
                }
                r2 = LD32(0x060D7768);
                ST16((54 + r2), r4);
                ST16((56 + r2), ((0xFFFF + r4) & 240));
                SETSP((sp - 4));
                r0 = GCALL1(0x06014516, 0x0606E70E);
                SETSP((sp - 4));
                SETPR(0x06077396);
                r0 = GCALL0(0x0606E70E);
                SETPR(LD32((sp - 4)));
                return r0;
            }
        }
    }
}

int f060773A8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060773B2);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060E2150);
        r1 = LD32(r3 + 8);
        SETSP((sp - 8));
        SETPR(0x060773C0);
        r0 = GCALL0(r1);
        if (!((r0 & r0) == 0)) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606E81C);
            r14 = 0x060D7768;
            r5 = LD32(0x060D7768);
            r5 = LD16(64 + r5);
            SETSP((sp - 8));
            r0 = GCALL3(0x0606C2B8, 4, (r5 & 0xFFFF), 4);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                SETSP((sp - 8));
                r0 = GCALL0(0x0607745C);
                SETSP((sp - 8));
                r0 = GCALL0(0x0606D95C);
                if ((r0 & r0) == 0) {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP0(0x0606D410);
                    return r0;
                } else {
                    r3 = LD32(r14);
                    ST16((54 + r3), 16);
                    ST16((56 + r3), 0);
                    SETSP((sp - 8));
                    r0 = GCALL1(0x06014516, 0x0606E70E);
                    SETSP((sp - 8));
                    SETPR(0x0607740E);
                    r0 = GCALL0(0x0606E70E);
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                }
            }
        }
    }
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

int f06077738(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r9, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(9));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x06077746);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(9, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        ST16(r3 + 12, 1);
        r3 = LD32(0x060D7768);
        ST16(r3 + 10, 0);
        SETSP((sp - 16));
        r0 = GCALL1(0x060144F4, 0x060777F6);
        r3 = LD16(0x060C27CC);
        if (!(r3 >= 0)) {
            r2 = 4;
        } else {
            r2 = 2;
        }
        ST16(0x060C1F24, r2);
        SETSP((sp - 16));
        r0 = GCALL0(0x0606D93E);
        if (!((r0 & r0) == 0)) {
            r9 = LD32(r14);
            r8 = LD32(r14);
            r4 = LD16(0x060C27CC);
            SETSP((sp - 16));
            r0 = GCALL1(0x060949D0, r4);
            r0 = (r0 << 2) << 2;
            ST16((r8 + 54), r0);
            ST16((r9 + 56), ((r0 + 0xFFFF) & 240));
            SETSP((sp - 16));
            r0 = GCALL1(0x06014516, 0x0606E70E);
            SETSP((sp - 16));
            SETPR(0x060777E0);
            r0 = GCALL0(0x0606E70E);
        }
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(9, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060777F6(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060777FE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06077834);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06077820);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 1));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06077834(int r4, int r5, int r6, int r7)
{
    int r0, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607783E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL0(0x06077A20);
        r14 = LD16(0x060C27D0);
        if ((r14 & r14) == 0) {
            ST16(0x060C27EE, 4);
            r4 = LD32(0x060D7768);
            r4 = LD16(80 + r4);
            SETSP((sp - 8));
            SETPR(0x060778A0);
            r0 = GCALL1(0x060775C6, ((r4 & 0xFFFF) + 3));
        } else {
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 8));
            SETPR(0x06077870);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (((((short)r14) - 1) << 1) + (((short)r14) - 1))) + 9));
            r2 = LD16(0x060C27D0);
            ST16(0x060C27D2, r2);
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x060778FC);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f06077870(void)
{
    ST16(0x060C27D2, LD16(0x060C27D0));
    GCALL1(0x060144F4, 0x060778FC);
    GCALL1(0x06014516, 0x0606D88C);
    GJUMP0(0x060778A0);
}

int f060778FC(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    SETSP((sp - 48));
    r0 = COPYW(0x06094450, (sp - 48), 0x060B2B04, 16);
    SETSP((sp - 48));
    SETPR(0x0607791E);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r1 = LD16(0x060C27CE);
        if (r1 == 255) {
            r0 = LD32(0x060D7B3C);
            r3 = LD16(r0 + 60);
            if ((r3 & 0xFFFF) >= 0xFF00) {
                r4 = LD32(0x060D7768);
                r4 = LD16(80 + r4);
                SETSP((sp - 48));
                SETPR(0x060779C4);
                r0 = GCALL1(0x060775C6, ((r4 & 0xFFFF) + 3));
            }
        } else {
            SETSP((sp - 48));
            r0 = GCALL0(0x06077A20);
            r12 = 1;
            r8 = 0x06020DB4;
            r14 = 0x060C27D8;
            r9 = 0x0600996A;
            r11 = 0x060C27D0;
            r10 = 0x060C27DC;
            r13 = 0x060C27D2;
            do {
                r3 = LD16(r11);
                r2 = LD16(r13);
                if (!(((r3 & r2) & r12) == 0)) {
                    r4 = LD16(r14);
                    SETSP((sp - 48));
                    r0 = GCALL1(r8, (r4 & 0xFFFF));
                    SETSP((sp - 48));
                    r0 = GCALL1(r9, 67);
                }
                r12 = r12 << 1;
                r14 = r14 + 2;
            } while (AGAIN(!((unsigned)r14 >= (unsigned)r10)));
            r0 = LD16(r13);
            if (r0 == 3) {
                r14 = LD16(r11);
                r14 = LD32(((r14 << 2) + (sp - 48)));
            } else {
                r4 = LD16(r13);
                r2 = LD16(r11);
                r14 = (((r4 - 1) << 1) + (r4 - 1)) + 10;
                if ((r2 & r4) == 0) {
                    r14 = r14 + 1;
                }
            }
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 48));
            SETPR(0x0607799E);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + r14));
            ST16(0x060C27CE, 255);
        }
        SETSP((sp - 48));
        r0 = GCALL0(0x0606D410);
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

int f06077AA8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06077AB2);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        ST16(r3 + 12, 1);
        r3 = LD32(0x060D7768);
        ST16(r3 + 10, 0);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x06077B06);
        ST16(0x060C1F24, 4);
        SETSP((sp - 8));
        r0 = GCALL0(0x0606D93E);
        if (!((r0 & r0) == 0)) {
            r1 = LD32(r14);
            r0 = LD32(r14);
            ST16((54 + r0), 80);
            ST16((r1 + 56), 64);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606E70E);
            SETSP((sp - 8));
            SETPR(0x06077AF8);
            r0 = GCALL0(0x0606E70E);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06077B06(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077B0E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06077B44);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06077B30);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 2));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06077B44(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077B4C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06077B8A);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 61);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06077B76);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 30));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06077B8A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077B92);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x06077B9A);
        r0 = GCALL0(0x06077FB0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06077BCC);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06077BB8);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 30));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06077BCC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077BD4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 62);
        r4 = LD32(0x060D7768);
        r4 = LD16(80 + r4);
        SETSP((sp - 4));
        SETPR(0x06077BEE);
        r0 = GCALL1(0x060775C6, ((r4 & 0xFFFF) + 4));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f06077CA8(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077CB0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        ST16(62 + r3, 0x258);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06077CF8);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 61);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06077CE4);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 20));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06077CF8(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077D00);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        ST16(48 + r3, 24);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06077D24);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 21));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D8B6);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06077DCC(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077DD4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD16(0x060C27D6);
        ST16(0x060C27D6, (r3 + 1));
        r2 = LD16(0x060C27D6);
        if ((r2 & 0xFFFF) >= 2) {
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x06077E0C);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 26));
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D8B6);
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x06077D38);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f06077E2A(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0602EE02);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06077E62);
    SETSP((sp - 4));
    SETPR(0x06077E40);
    r0 = GCALL0(0x0606D2E8);
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606D88C);
    ST32((sp - 8), 63);
    SETSP((sp - 8));
    SETPR(0x06077E5A);
    r0 = GCALL4(0x06080864, 140, 32, 63, 56);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06077E62(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077E6A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06077EA4);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06077E8C);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 48));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETSP((sp - 4));
        SETPR(0x06077E98);
        r0 = GCALL0(0x06078782);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06077EA4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06077EAC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C1E4A);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D398);
            SETSP((sp - 4));
            r0 = GCALL0(0x06039FAC);
            SETSP((sp - 4));
            r0 = GCALL0(0x06039FB4);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06077ED8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r0 = LD16(0x060C27C8);
    if ((r0 & r0) == 0) {
        SETMACL(LD32((sp - 28)));
        SETPR(LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r11 = 0;
        r13 = 0x060C27C6;
        r10 = LD32(0x060D7768);
        r0 = LD8(r10 + 4);
        r0 = r0 & 255;
        r12 = LD16(0x060C27C6);
        if ((r0 & 192) == 0) {
            r5 = 0x060D7B3C;
            r14 = LD32(0x060D7B3C);
            if (((r12 & 0xFFFF) & (r12 & 0xFFFF)) == 0) {
                ST32((sp - 32), r11);
                ST32((sp - 36), r11);
                r0 = LD16(r14 + 18);
                ST32((sp - 40), r0);
                r0 = LD16(r14 + 16);
                ST32((sp - 44), r0);
                r3 = LD16(80 + r10);
                ST32((sp - 48), ((r3 & 0xFFFF) + 7));
                r1 = LD16(40 + r14);
                ST32((sp - 52), (r1 & 0xFFFF));
                r7 = LD16(46 + r14);
                r6 = LD16(44 + r14);
                SETR(13, r13);
                SETSP((sp - 52));
                SETPR(0x06077F70);
                r0 = GCALL4(0x0606CAE4, r11, 10, (r6 & 0xFFFF), (r7 & 0xFFFF));
                ST16(r13, r0);
                r4 = LD16(r13);
                SETMACL(LD32((sp - 28)));
                SETPR(LD32((sp - 24)));
                SETR(10, LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP1(0x0606ABCC, (r4 & 0xFFFF));
                return r0;
            } else {
                r0 = LD16(r14 + 16);
                ST16(((((r12 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 16, r0);
                r1 = LD16(r13);
                r0 = LD32(r5);
                r0 = LD16(r0 + 18);
                ST16(((((r1 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 18, r0);
                SETMACL(LD32((sp - 28)));
                SETPR(LD32((sp - 24)));
                SETR(10, LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            }
        } else {
            if (!(((r12 & 0xFFFF) & (r12 & 0xFFFF)) == 0)) {
                SETSP((sp - 28));
                r0 = GCALL1(0x060692DC, (r12 & 0xFFFF));
                ST16(r13, r11);
            }
            SETMACL(LD32((sp - 28)));
            SETPR(LD32((sp - 24)));
            SETR(10, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        }
    }
}

void f06077F9A(void)
{
    int i = 0;

    do {
        ST16(0x060C27DC + i * 2, 0);
    } while (AGAIN(++i < 6));
}

int f06077FB0(void)
{
    int r0, r3, r4, r5, r6, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    SETSP((sp - 36));
    r0 = GCALL1(0x0600996A, 70);
    r11 = 124;
    r13 = 0x060D7768;
    r14 = 0;
    r8 = 0x060C27C4;
    r12 = 6;
    r9 = 0x060D5F30;
    r10 = 0x0606AE6C;
    do {
        r6 = LD32(r13);
        r0 = LD16(r6 + 28);
        r5 = LD32(r13);
        r6 = r0;
        r0 = LD16(r5 + 24);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x06077FE8);
        r0 = GCALL3(r10, 82, r0, r6);
        r4 = r0;
        if (!((r4 & r4) == 0)) {
            ST16(0x060C27DC + (r14 << 1), r4);
            r3 = LD16(r8);
            r5 = (r4 * r11) + r9;
            ST16(52 + r5, r3);
            r0 = 66;
            ST16(66 + r5, r14);
        }
        r14 = r14 + 1;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r12)));
    SETMACL(LD32((sp - 36)));
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

int f060780A4(void)
{
    int bits = 0;
    int p = 0x060C27DC;

    do {
        bits |= LDU16(p);
    } while (AGAIN((p += 2) < 0x060C27E8));
    return bits;
}

int f060780C0(void)
{
    int r0, r1, r2, r3, r4, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x060780D0);
    r0 = GCALL3(0x0606B0DE, 0x060BA920, 250, 17);
    r2 = LD32(0x060D7768);
    ST16(r2 + 18, 0);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL2(0x0606950C, r4, 1);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 128));
    SETSP((sp - 12));
    r0 = GCALL1(0x0606947C, 0x1E0);
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x0607825E);
    r8 = LD32(0x060D7768);
    SETSP((sp - 12));
    r0 = GCALL1(0x0600A0EC, 3);
    ST16((r8 + 68), ((r0 << 2) + r0));
    r3 = LD32(0x060D7B3C);
    r1 = LD32(0x060D7768);
    r0 = LD16(68 + r1);
    ST16((48 + r3), (r0 + 32));
    r3 = LD32(0x060D7768);
    r0 = LD16(68 + r3);
    ST16((48 + r3), (r0 + 36));
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x06078244);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 16, 0x06078164);
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0x06078164;
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

int f0607825E(void)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 32));
    r0 = COPYW(0x06094450, (sp - 32), 0x060B2B14, 24);
    SETSP((sp - 32));
    SETPR(0x06078274);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r1 = LD16(66 + r3);
        r1 = LD32((((r1 & 0xFFFF) << 2) + (sp - 32)));
        ST16(86 + r3, r1);
        SETSP((sp - 32));
        r0 = GCALL1(0x060144F4, 0x060782D2);
        ST16(0x060C1F24, 2);
        SETSP((sp - 32));
        r0 = GCALL0(0x0606D93E);
        if (!((r0 & r0) == 0)) {
            r1 = LD32(r14);
            r0 = LD32(r14);
            ST16((54 + r0), 16);
            ST16((r1 + 56), 0);
            SETSP((sp - 32));
            r0 = GCALL1(0x06014516, 0x0606E70E);
            SETSP((sp - 32));
            SETPR(0x060782C4);
            r0 = GCALL0(0x0606E70E);
        }
        SETSP((sp - 32));
        r0 = GCALL0(0x0606D410);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060782D2(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 12));
    SETPR(0x060782DE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 24);
        r5 = r0 & 0xFFFF;
        if (!(r5 > 96)) {
            SETSP((sp - 12));
            r0 = GCALL0(0x06078244);
        } else {
            if (r5 >= 0x1E0) {
                SETSP((sp - 12));
                r0 = GCALL0(0x06078244);
            } else {
                r0 = LD16(r4 + 28);
                if (!((r0 & 0xFFFF) > 0x150)) {
                    SETSP((sp - 12));
                    r0 = GCALL0(0x06078244);
                } else {
                    r0 = LD16(r4 + 28);
                    if (!((r0 & 0xFFFF) >= 0x2D0)) {
                        r5 = 1;
                        r3 = LD16(42 + r4);
                        if (((r3 & 0xFFFF) & 1) == 0) {
                            r2 = LD16(42 + r4);
                            ST16(42 + r4, (r2 | 0x100));
                            r1 = LD32(r14);
                            ST16(r1 + 12, r5);
                            r2 = LD32(r14);
                            ST16(r2 + 10, 0x8000);
                            r4 = LD32(r14);
                            r4 = LD16(86 + r4);
                            SETSP((sp - 12));
                            r0 = GCALL2(0x06074C34, (r4 & 0xFFFF), 32);
                            ST32(sp - 12, r0);
                            r4 = LD32(r14);
                            r4 = LD16(86 + r4);
                            SETSP((sp - 12));
                            r0 = GCALL2(0x06074B48, (r4 & 0xFFFF), r0);
                            SETSP((sp - 12));
                            r0 = GCALL1(0x06014516, 0x06074CB4);
                            r4 = 255;
                            r0 = 86;
                            r3 = LD32(r14);
                            r2 = LD16((86 + r3));
                            if (!((((r2 & 0xFFFF) + 64) & 255) >= 128)) {
                                r2 = -8;
                            } else {
                                r2 = 8;
                            }
                            r1 = LD16(r0 + r3);
                            ST16(r0 + r3, (r1 + r2));
                            r3 = LD32(r14);
                            r2 = LD16(86 + r3);
                            ST16(86 + r3, (r2 & r4));
                        }
                    } else {
                        SETSP((sp - 12));
                        r0 = GCALL0(0x06078244);
                    }
                }
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060783D6(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8, r9;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(9));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    SETSP((sp - 24));
    SETPR(0x060783E8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(9, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r4 = LD16(70 + r4);
        r3 = LD32(0x060D7768);
        r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
        r0 = LD16(r4 + 24);
        ST16(r3 + 24, r0);
        r3 = LD32(0x060D7768);
        r0 = LD16(r4 + 28);
        ST16(r3 + 28, (r0 + 0xFFF2));
        r3 = LD32(0x060D7B3C);
        r0 = LD16(r4 + 22);
        r0 = LD16((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C3842);
        ST16((38 + r3), r0);
        r9 = LD32(0x060D7B3C);
        r8 = LD32(0x060D7B3C);
        r4 = LD32(0x060D7B3C);
        r4 = LD16(38 + r4);
        SETSP((sp - 24));
        r0 = GCALL1(0x060949D0, r4);
        r0 = ((r0 << 2) << 1) + 0x100;
        ST16((r8 + 70), r0);
        ST16((r9 + 68), r0);
        r3 = LD32(0x060D7768);
        r1 = LD16(62 + r3);
        if ((r1 & r1) == 0) {
            SETSP((sp - 24));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        }
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(9, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f060784B8(int r4)
{
    int r0, r3, r5, r6, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r6 = 4;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r5 = 0;
    if ((r4 & r4) == 0) {
        r12 = r6;
        r4 = r5;
    } else {
        r12 = 2;
        r4 = r6;
    }
    r8 = 0x060D5F30;
    r9 = 0x0606AE6C;
    r11 = r5;
    r13 = 0x060D7768;
    r14 = 0 + r4;
    r10 = 124;
    if (!((unsigned)r5 >= (unsigned)r12)) {
        do {
            r6 = LD32(r13);
            r5 = LD32(r13);
            r0 = LD16(r6 + 28);
            r6 = r0;
            r0 = LD16(r5 + 24);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 36));
            SETPR(0x060784FE);
            r0 = GCALL3(r9, 83, r0, r6);
            r4 = r0;
            r11 = r11 + 1;
            if (!((r4 & r4) == 0)) {
                r5 = (r4 * r10) + r8;
                r3 = LD16(0x060C27C4);
                ST16(52 + r5, r3);
                ST16(66 + r5, r14);
            }
            r14 = r14 + 1;
        } while (AGAIN(!((unsigned)r11 >= (unsigned)r12)));
    }
    SETMACL(LD32((sp - 36)));
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
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

int f06078598(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    SETSP((sp - 44));
    SETPR(0x060785B2);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 36)));
        SETPR(LD32((sp - 32)));
        SETR(8, LD32((sp - 28)));
        SETR(9, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 44));
        r0 = GCALL0(0x06074770);
        r4 = r0;
        if (!((unsigned)r4 >= (unsigned)8)) {
            r14 = 0x060D7768;
            r13 = 0x060C2658;
            r8 = 24;
            r9 = 0x060980DC;
            r1 = LD32(0x060D7768);
            ST16(90 + r1, r4);
            r10 = 0x060BA92C;
            ST32(0x060C2658, (((short)((short)r4 * (short)220)) + 0x060C1F78));
            r3 = LD32(0x060C2658);
            r11 = 0;
            ST32(r3 + 8, 0);
            r12 = 0;
            do {
                r2 = LD32(r13);
                r3 = LD32(r2 + 8);
                ST32(r2 + 8, (r3 + 1));
                r3 = LD32(r13);
                ST32(sp - 40, r12);
                ST32((sp - 48), ((r3 + 12) + r12));
                r4 = LD32(r14);
                r0 = LD16(r4 + 24);
                r4 = LD8((67 + r4));
                ST32(sp - 44, r11);
                r4 = LD16(((((signed char)(((r4 << 1) + r4) << 2)) + r10) + r11));
                SETSP((sp - 48));
                r0 = GCALL1(r9, (r4 + (r0 & 0xFFFF)));
                r2 = LD32((sp - 48));
                ST32(r2, r0);
                r1 = LD32(r13);
                r2 = LD32(sp - 40);
                ST32((sp - 48), (4 + ((r1 + 12) + r2)));
                r4 = LD32(r14);
                r0 = LD16(r4 + 28);
                r2 = r0 & 0xFFFF;
                r4 = LD8((67 + r4));
                r3 = LD32(sp - 44);
                r0 = LD16(((((signed char)(((r4 << 1) + r4) << 2)) + r10) + r3) + 2);
                SETSP((sp - 48));
                r0 = GCALL1(r9, (r2 + r0));
                r12 = r12 + 8;
                r2 = LD32((sp - 48));
                ST32(r2, r0);
                r11 = r11 + 4;
            } while (AGAIN(!((unsigned)r12 >= (unsigned)r8)));
            r2 = LD32(r13);
            ST32(76 + r2, 16);
            SETSP((sp - 44));
            r0 = GCALL1(0x060144F4, 0x060786DC);
            SETSP((sp - 44));
            r0 = GCALL1(0x06014516, 0x060747C0);
        }
        SETMACL(LD32((sp - 36)));
        SETPR(LD32((sp - 32)));
        SETR(8, LD32((sp - 28)));
        SETR(9, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060786DC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060786E6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL1(0x0600996A, 71);
        r3 = LD32(0x060D7768);
        r1 = LD16(42 + r3);
        ST16(42 + r3, (r1 & 0xFF7F));
        SETSP((sp - 8));
        r0 = GCALL0(0x0606C7CE);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x0607871A);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 29));
        r3 = LD32(0x060D7768);
        r2 = LD16(66 + r3);
        r0 = 62;
        if (!((r2 & 0xFFFF) >= 4)) {
            r2 = 120;
        } else {
            r2 = 0x1E0;
        }
        ST16(r0 + r3, r2);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0607874C);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607874C(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06078754);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D2C8);
        } else {
            SETSP((sp - 4));
            SETPR(0x0607876A);
            r0 = GCALL0(0x0606C8C0);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06078782(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 8));
    SETPR(0x0607879A);
    r0 = GCALL3(0x0606AE6C, 84, r0, r6);
    r4 = r0;
    if ((r4 & r4) == 0) {
        ST16(0x060C1E4A, 1);
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = r4 * 124;
        r1 = LD16(0x060D5F5A + r3);
        ST16(0x060D5F5A + r3, (r1 | 128));
        SETMACL(LD32((sp - 8)));
        r4 = LD16(0x060C1AAA);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06069462, r4, 0x1E7);
        return r0;
    }
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

int f060789B6(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060789BE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x060789FC);
        ST16(0x060C1F24, 2);
        SETSP((sp - 4));
        r0 = GCALL0(0x0606D986);
        r3 = LD32(0x060D7768);
        ST16((54 + r3), 80);
        ST16((56 + r3), 64);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606E70E);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060789FC(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06078A06);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x06078AB4);
        r14 = 0x060D7768;
        r2 = LD32(0x060D7768);
        r3 = LD16(66 + r2);
        r2 = LD16(0x060BAA48 + ((r3 & 0xFFFF) << 1));
        ST16(0x060C1F24, r2);
        r0 = LD16(0x060C1F24);
        if (!((r0 & 0xFFFF) == 2)) {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606D986);
            r3 = LD32(r14);
            ST16((54 + r3), 32);
            ST16((56 + r3), 16);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606E70E);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06078AB4(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06078ABE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = 0x060C1E48;
        r14 = 0x060D7768;
        r0 = LD32(0x060D7768);
        r0 = LD16(r0 + 66);
        if ((r0 & 0xFFFF) == 1) {
            ST16(r4, 16);
        }
        r0 = LD16(r4);
        if ((r0 & 0xFFFF) == 16) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x06078B44);
            r3 = LD32(r14);
            r5 = LD32(r14);
            r5 = LD16(66 + r5);
            r2 = LD16(80 + r3);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 8));
            SETPR(0x06078B04);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r2 & 0xFFFF)) + 3));
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06078B44(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06078B50);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r0 = LD16(0x060C1E48);
        r13 = LD32(0x060D7768);
        if (!((r0 & 0xFFFF) == 17)) {
            r5 = LD16(66 + r13);
            r2 = LD16(80 + r13);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 12));
            SETPR(0x06078C24);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r2 & 0xFFFF)) + 6));
            if (!((r0 & r0) == 0)) {
                SETSP((sp - 12));
                r0 = GCALL1(0x0600996A, 73);
            }
        } else {
            ST16(68 + r13, 0);
            r2 = LD16(0x060C062C);
            ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x06078D38);
            r4 = LD32(0x060D7B3C);
            SETSP((sp - 12));
            r0 = GCALL1(0x0606AB24, r4);
            r3 = LD32(r14);
            r1 = LD16(42 + r3);
            ST16(42 + r3, (r1 | 128));
            SETSP((sp - 12));
            r0 = GCALL1(0x0606947C, 0x1E0);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06078B9E);
            r0 = GCALL0(0x06078CA0);
            r4 = LD32(0x060D7B3C);
            SETSP((sp - 12));
            r0 = GCALL2(0x0606950C, r4, 1);
            r1 = LD32(r14);
            ST16(r1 + 12, 1);
            r3 = LD32(r14);
            ST16(r3 + 10, 0x8000);
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x06078D16);
            r5 = LD32(r14);
            r3 = LD32(r14);
            r5 = LD16(66 + r5);
            r2 = LD16(80 + r3);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06078BDA);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r2 & 0xFFFF)) + 9));
            r3 = LD32(r14);
            r0 = LD16(r3 + 66);
            r0 = LD8(((r0 & 0xFFFF) << 1) + 0x060BAA49);
            ST8(r3 + 6, r0);
            r3 = LD32(r14);
            ST16((54 + r3), 0x100);
            ST16((56 + r3), 240);
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606E70E);
        }
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06078CA0(void)
{
    int r0, r2, r3, r4, r5, r8, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    r8 = LD32(0x060D7768);
    SETSP((sp - 20));
    r0 = GCALL1(0x060691DA, 20);
    ST16((r8 + 70), r0);
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r2 = LD16(0x060C1AAA);
        r3 = LD32(0x060D7B3C);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r2 = LD16(44 + r3);
        ST16(44 + r14, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(46 + r3);
        ST16(46 + r14, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(40 + r3);
        ST16(40 + r14, r2);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AAA);
        SETR(13, 0x060D7B3C);
        SETR(14, r14);
        SETSP((sp - 20));
        SETPR(0x06078CFE);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 12));
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 16);
        ST16(r14 + 16, r0);
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 18);
        ST16(r14 + 18, r0);
    }
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(8, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f06078FBC(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06078FC6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r5 = 0x100;
        r14 = 0x060D7B3C;
        r4 = LD32(0x060D7B3C);
        r3 = LD16(68 + r4);
        if ((r3 & 0xFFFF) >= 0x100) {
            ST16(70 + r4, r5);
            ST16(68 + r4, r5);
            r4 = LD32(r14);
            SETSP((sp - 8));
            r0 = GCALL2(0x0606AAC8, r4, 0);
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x06079064);
            ST16(0x060C2816, 0);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 8));
            SETPR(0x06079024);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 19));
        } else {
            r2 = LD16(68 + r4);
            ST16(68 + r4, (r2 + 16));
            r3 = LD32(r14);
            r2 = LD16(70 + r3);
            ST16(70 + r3, (r2 + 16));
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06079064(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r10, r11, r12, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    SETSP((sp - 28));
    SETPR(0x06079078);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r10 = 0x060C2816;
        r11 = 0x060C1AA8;
        r14 = 0x060D7768;
        r4 = LD16(0x060C2816);
        if ((r4 & 0xFFFF) >= 4) {
            SETSP((sp - 28));
            r0 = GCALL1(0x0600996A, 89);
            r5 = LD32(r14);
            r4 = LD16(r11);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 28));
            SETPR(0x0607915A);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 2));
            SETSP((sp - 28));
            r0 = GCALL1(0x060144F4, 0x060791E0);
            r3 = LD32(r14);
            ST16(58 + r3, 60);
            SETSP((sp - 28));
            r0 = GCALL1(0x06014516, 0x0606E864);
        } else {
            r6 = ((signed char)(((r4 << 2) + r4) << 2)) + 0x060BAAFC;
            r4 = LD32(r6);
            r5 = LD32(r6 + 4);
            r7 = LD32(r6 + 8);
            r12 = LD32(r6 + 12);
            r3 = LD32(r6 + 16);
            ST32(sp - 28, r3);
            r3 = LD32(r14);
            ST16(r3 + 12, ((int)((unsigned)r7 >> 8)));
            r3 = LD32(r14);
            ST16(r3 + 10, ((255 & r7) << 8));
            SETSP((sp - 28));
            r0 = GCALL2(0x06074AFA, r4, r5);
            SETSP((sp - 28));
            r0 = GCALL1(0x06014516, 0x06074CB4);
            r5 = LD32(r14);
            r3 = LD32(sp - 28);
            r5 = LD16(80 + r5);
            r4 = LD16(r11);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(14, r14);
            SETSP((sp - 28));
            SETPR(0x060790E0);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + r3));
            if (!((r12 & r12) == 0)) {
                ST32((sp - 32), 1);
                r2 = LD16(r11);
                ST32((sp - 36), (r2 & 0xFFFF));
                r1 = LD32(0x060D7B3C);
                r0 = LD16(r1 + 18);
                ST32((sp - 40), r0);
                r2 = LD32(0x060D7B3C);
                r0 = LD16(r2 + 16);
                ST32((sp - 44), r0);
                r2 = LD32(r14);
                r1 = LD16(80 + r2);
                ST32((sp - 48), (r12 + (r1 & 0xFFFF)));
                r2 = LD32(0x060D7B3C);
                r1 = LD16(40 + r2);
                ST32((sp - 52), (r1 & 0xFFFF));
                r7 = LD32(0x060D7B3C);
                r7 = LD16(46 + r7);
                r6 = LD32(0x060D7B3C);
                r5 = LD32(0x060D7B3C);
                r6 = LD16(44 + r6);
                r0 = LD16(r5 + 4);
                SETR(10, r10);
                SETSP((sp - 52));
                SETPR(0x06079130);
                r0 = GCALL4(0x0606CAE4, 64, (r0 + 1), (r6 & 0xFFFF), (r7 & 0xFFFF));
                SETSP((sp - 28));
                r0 = GCALL1(0x0600996A, 90);
            }
            r2 = LD16(r10);
            ST16(r10, (r2 + 1));
        }
        SETPR(LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    } else {
        SETPR(LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f060791E0(void)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST16(0x060C27F4, 1);
    SETSP((sp - 4));
    SETPR(0x060791EC);
    r0 = GCALL0(0x0607A206);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 & 0xFFDF));
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7AA);
    r0 = LD16(0x060C062C);
    ST32((0x060E215C + ((short)(((r0 << 2) + r0) << 2))), 0x06079416);
    SETSP((sp - 4));
    r0 = GCALL0(0x06039FA4);
    SETSP((sp - 4));
    SETPR(0x0607921E);
    r0 = GCALL1(0x060793A6, 0);
    ST16(0x060C27F6, 0);
    r1 = LD32(0x060D7768);
    SETPR(LD32((sp - 4)));
    ST16(60 + r1, 0x4B0);
    return 60;
}

int f06079232(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0607923E);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r3 = LD32(0x060E2150);
        r2 = LD32(r3 + 8);
        SETSP((sp - 12));
        SETPR(0x06079250);
        r0 = GCALL0(r2);
        if ((r0 & r0) == 0) {
            r14 = 0x060D7768;
            r0 = LD16(0x060C27F6);
            if ((r0 & 128) == 0) {
                SETSP((sp - 12));
                r0 = GCALL0(0x0606E81C);
                r4 = LD32(r14);
                r4 = LD16(64 + r4);
                SETSP((sp - 12));
                r0 = GCALL1(0x0606BCD8, (r4 & 0xFFFF));
                if ((r0 & r0) == 0) {
                    SETSP((sp - 12));
                    r0 = GCALL0(0x0606D920);
                    r13 = r0;
                } else {
                    SETSP((sp - 12));
                    r0 = GCALL0(0x0606C28A);
                    r13 = r0;
                    if (!((r13 & r13) == 0)) {
                        SETSP((sp - 12));
                        r0 = GCALL0(0x0606D97A);
                    }
                }
            } else {
                SETSP((sp - 12));
                r0 = GCALL0(0x0606DA9E);
                SETSP((sp - 12));
                r0 = GCALL0(0x0606DA3C);
                r5 = 0x060C1F38;
                r2 = LD32(r14);
                r0 = LD16(r2 + 24);
                r3 = LD16(0x060C2818);
                r4 = 2;
                if (!((unsigned)r0 > (unsigned)r3)) {
                    ST16(r5 + 6, r4);
                }
                r3 = LD32(r14);
                r0 = LD16(r3 + 24);
                r3 = LD16(0x060C281A);
                if ((unsigned)r0 >= (unsigned)r3) {
                    ST16(r5 + 2, r4);
                }
                r3 = LD32(r14);
                r0 = LD16(r3 + 28);
                r3 = LD16(0x060C281C);
                if (!((unsigned)r0 > (unsigned)r3)) {
                    ST16(r5 + 8, r4);
                }
                r3 = LD32(r14);
                r0 = LD16(r3 + 28);
                r3 = LD16(0x060C281E);
                if ((unsigned)r0 >= (unsigned)r3) {
                    ST16(r5 + 4, r4);
                }
                SETSP((sp - 12));
                r0 = GCALL0(0x0606D95C);
                r13 = r0;
            }
            if ((r13 & r13) == 0) {
                SETPR(LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                r3 = LD32(r14);
                ST16((54 + r3), 16);
                ST16((56 + r3), 0);
                SETSP((sp - 12));
                r0 = GCALL1(0x06014516, 0x0606E70E);
                SETSP((sp - 12));
                SETPR(0x06079368);
                r0 = GCALL0(0x0606E70E);
                r4 = 0x060C27FA;
                r0 = LD16(0x060C27FA);
                if (!((r0 & r0) == 0)) {
                    r3 = LD16(r4);
                    ST16(r4, (r3 - 1));
                }
                r4 = 0x060C27FC;
                r0 = LD16(0x060C27FC);
                if (!((r0 & r0) == 0)) {
                    r3 = LD16(r4);
                    ST16(r4, (r3 - 1));
                }
                r4 = 0x060C27FE;
                r0 = LD16(0x060C27FE);
                if (!((r0 & r0) == 0)) {
                    r3 = LD16(r4);
                    ST16(r4, (r3 - 1));
                }
                SETPR(LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            }
        } else {
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        }
    } else {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f0607940C(void)
{
    int r0, r1, r3, r5, r6, r7, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06079412);
    r0 = GCALL0(0x06079F18);
    SETPR(LD32((sp - 4)));
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r0 = LD16(0x060C27F4);
    if (!((r0 & r0) == 0)) {
        r12 = 0x060C27F2;
        r11 = 0;
        r10 = LD32(0x060D7768);
        r0 = LD8(r10 + 4);
        r0 = r0 & 255;
        r13 = LD16(0x060C27F2);
        if ((r0 & 192) == 0) {
            r5 = 0x060D7B3C;
            r14 = LD32(0x060D7B3C);
            if (((r13 & 0xFFFF) & (r13 & 0xFFFF)) == 0) {
                ST32((sp - 32), r11);
                ST32((sp - 36), r11);
                r0 = LD16(r14 + 18);
                ST32((sp - 40), r0);
                r0 = LD16(r14 + 16);
                ST32((sp - 44), r0);
                r3 = LD16(80 + r10);
                ST32((sp - 48), ((r3 & 0xFFFF) + 66));
                r1 = LD16(40 + r14);
                ST32((sp - 52), (r1 & 0xFFFF));
                r7 = LD16(46 + r14);
                r6 = LD16(44 + r14);
                SETR(12, r12);
                SETSP((sp - 52));
                SETPR(0x0607A29E);
                r0 = GCALL4(0x0606CAE4, r11, 10, (r6 & 0xFFFF), (r7 & 0xFFFF));
                ST16(r12, r0);
            } else {
                r0 = LD16(r14 + 16);
                ST16(((((r13 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 16, r0);
                r1 = LD16(r12);
                r0 = LD32(r5);
                r0 = LD16(r0 + 18);
                ST16(((((r1 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 18, r0);
            }
        } else {
            if (!(((r13 & 0xFFFF) & (r13 & 0xFFFF)) == 0)) {
                SETSP((sp - 28));
                r0 = GCALL1(0x060692DC, (r13 & 0xFFFF));
                ST16(r12, r11);
            }
        }
    }
    SETMACL(LD32((sp - 28)));
    SETPR(LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f060796F8(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r3 = LD32(0x060D7768);
    r0 = LD8(r3 + 6);
    r0 = LD8(((r0 & 255) << 1) + 0x060B90B5);
    ST8(r3 + 6, r0);
    ST16(0x060C27F8, 6);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x06079756);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 8));
    SETPR(0x06079730);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
    SETSP((sp - 8));
    r0 = GCALL1(0x06014516, 0x0606D8B6);
    r2 = LD32(0x060D7B3C);
    ST16(48 + r2, 14);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7EE);
    r3 = LD16(0x060C27FA);
    ST16(0x060C27FA, (r3 + 4));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0607988C(void)
{
    int r0, r2, r3, r4, r5, r6, r7;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    SETSP((sp - 28));
    r0 = COPYW(0x06094450, (sp - 28), 0x060B2B2C, 16);
    r0 = LD32(0x26006034);
    r5 = LD16(0x060C1F2E);
    r4 = LD32(((r0 & 3) << 2) + (sp - 28));
    r2 = LD32(0x060D7B3C);
    r5 = LD16(0x060B90B4 + ((r5 & 0xFFFF) << 1));
    r0 = LD16(r2 + 16);
    r6 = (r5 & 0xFFFF) << 1;
    r2 = LD16(0x060B908C + r6);
    r5 = r0 + (r2 * r4);
    r2 = LD32(0x060D7B3C);
    r0 = LD16(r2 + 18);
    r2 = LD16(0x060B9096 + r6);
    ST32((sp - 32), -1);
    r3 = LD16(0x060C1AA8);
    ST32((sp - 36), (r3 & 0xFFFF));
    ST32((sp - 40), (r0 + (r2 * r4)));
    ST32((sp - 44), r5);
    r3 = LD32(0x060D7768);
    r2 = LD16(80 + r3);
    ST32((sp - 48), ((r2 & 0xFFFF) + 14));
    r3 = LD32(0x060D7B3C);
    r2 = LD16(40 + r3);
    ST32((sp - 52), (r2 & 0xFFFF));
    r7 = LD32(0x060D7B3C);
    r6 = LD32(0x060D7B3C);
    r7 = LD16(46 + r7);
    r5 = LD32(0x060D7B3C);
    r6 = LD16(44 + r6);
    r0 = LD16(r5 + 4);
    SETSP((sp - 52));
    SETPR(0x06079922);
    r0 = GCALL4(0x0606CAE4, 16, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

int f0607992E(void)
{
    return LD16(0x060C27FE) == 0 && GCALL1(0x0606C114, 7) != 0;
}

int f06079956(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607995E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06079988);
        r2 = LD32(0x060D7768);
        ST16(58 + r2, 16);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606E864);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06079A1A(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06079A24);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7B3C);
        r2 = LD16(38 + r4);
        if (r2 >= 0) {
            SETSP((sp - 8));
            r0 = GCALL1(0x0600996A, 89);
            r3 = LD32(0x060D7B3C);
            ST16(38 + r3, 0);
            r4 = LD32(0x060D7768);
            r4 = LD16(80 + r4);
            SETSP((sp - 8));
            SETPR(0x06079A5E);
            r0 = GCALL1(0x060793A6, ((r4 & 0xFFFF) + 2));
            r3 = LD16(0x060C27FE);
            ST16(0x060C27FE, (r3 + 24));
            r14 = LD16(0x060C280C);
            if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                SETSP((sp - 8));
                r0 = GCALL1(0x060692DC, (r14 & 0xFFFF));
                ST16(0x060C280C, 0);
            }
        } else {
            r1 = LD16(38 + r4);
            ST16(38 + r4, (r1 + 2));
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06079A8A(void)
{
    if (LDU16(0x060C2810)) {
        ST16(0x060C2810, LDU16(0x060C2810) - 1);
        return 0;
    }
    return !GCALL1(0x0606C114, 4);
}

int f06079AB4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06079ABE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r0 = LD16(58 + r4);
        if ((r0 & r0) == 0) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x06079B84);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06079B68);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 8));
            ST16(0x060C2812, 0);
            r1 = LD32(r14);
            ST16(58 + r1, 4);
        } else {
            r3 = LD16(58 + r4);
            ST16(58 + r4, (r3 - 1));
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f06079DE2(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06079DEC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 24);
        ST16(0x060C2818, (r0 + 0xFFD0));
        r1 = LD32(0x060D7768);
        r0 = LD16(r1 + 24);
        ST16(0x060C281A, (r0 + 48));
        r2 = LD32(0x060D7768);
        r0 = LD16(r2 + 28);
        ST16(0x060C281C, (r0 + 0xFFE0));
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 28);
        ST16(0x060C281E, (r0 + 32));
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x06079E22);
        r0 = GCALL1(0x060793A6, 0);
        r3 = LD32(0x060D7768);
        ST16(r3 + 12, 0);
        r3 = LD32(0x060D7768);
        ST16(r3 + 10, 0xA000);
        r3 = LD32(0x060D7768);
        ST16(60 + r3, 0x384);
        SETSP((sp - 8));
        SETPR(0x06079E3A);
        r0 = GCALL0(0x06079E80);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06079E80(void)
{
    int r0, r2, r3, r4, r5, r6, r7, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r13 = 0x060C2814;
    r0 = LD16(0x060C2814);
    if ((r0 & r0) == 0) {
        SETSP((sp - 16));
        r0 = GCALL1(0x0600996A, 97);
        ST32((sp - 20), 1);
        r3 = LD16(0x060C1AA8);
        ST32((sp - 24), (r3 & 0xFFFF));
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 18);
        ST32((sp - 28), r0);
        r3 = LD32(0x060D7B3C);
        r0 = LD16(r3 + 16);
        ST32((sp - 32), r0);
        r3 = LD32(0x060D7768);
        r2 = LD16(80 + r3);
        ST32((sp - 36), ((r2 & 0xFFFF) + 68));
        r3 = LD32(0x060D7B3C);
        r2 = LD16(40 + r3);
        ST32((sp - 40), (r2 & 0xFFFF));
        r7 = LD32(0x060D7B3C);
        r7 = LD16(46 + r7);
        r6 = LD32(0x060D7B3C);
        r6 = LD16(44 + r6);
        r5 = LD32(0x060D7B3C);
        r0 = LD16(r5 + 4);
        SETR(13, r13);
        SETSP((sp - 40));
        SETPR(0x06079EE8);
        r0 = GCALL4(0x0606CAE4, 0, (r0 + 40), (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST16(r13, r0);
        r4 = LD16(r13);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606AB08, (r4 & 0xFFFF), 3);
        r2 = LD16(r13);
        r4 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(70 + r4, 64);
        r0 = 68;
        ST16(68 + r4, 64);
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06079F18(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r12, r13, r14, c3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    r14 = 0x060C2814;
    r0 = LD16(0x060C2814);
    if (!((r0 & r0) == 0)) {
        r13 = 0x060D7768;
        r3 = LD32(0x060D7B3C);
        r0 = LD16(66 + r3);
        r12 = 0;
        if (!((r0 & r0) == 0)) {
            r2 = LD32(r13);
            ST16(60 + r2, r12);
        } else {
            r0 = LD32(0x060D7768);
            r0 = LD8(r0 + 4);
            if (!(((r0 & 255) & 192) == 0)) {
                r2 = LD32(r13);
                ST16(60 + r2, r12);
            }
        }
        r5 = 0x060C381C;
        r2 = LD16(r14);
        c3 = (r2 & 0xFFFF) * 84;
        r2 = LD32(r13);
        r1 = LD16(60 + r2);
        r4 = (c3 & 0xFFFF) + 0x060C381C;
        if (!((r1 & r1) == 0)) {
            r2 = LD16(68 + r4);
            if ((r2 & 0xFFFF) >= 0x100) {
                r1 = LD32(r13);
                r1 = LD16(60 + r1);
                SETSP((sp - 20));
                r0 = MODS((r1 & 0xFFFF), 30);
                if (!((r0 & r0) == 0)) {
                    SETMACL(LD32((sp - 20)));
                    SETPR(LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    SETMACL(LD32((sp - 20)));
                    SETPR(LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    ST32((sp - 4), PR());
                    ST32((sp - 8), MACL());
                    r4 = LD16(0x060C2814);
                    SETSP((sp - 8));
                    r0 = GCALL1(0x0600C90C, (r4 & 0xFFFF));
                    r6 = LD16(0x060D7E8A);
                    r5 = LD16(0x060D7E88);
                    SETSP((sp - 8));
                    SETPR(0x0607AF36);
                    r0 = GCALL3(0x0606AE6C, 86, r5, r6);
                    r4 = r0;
                    if (!((r4 & r4) == 0)) {
                        r0 = 0x060D5F64;
                        r2 = LD16(0x060C27F0);
                        ST16(0x060D5F64 + (r4 * 124), r2);
                    }
                    SETMACL(LD32((sp - 8)));
                    SETPR(LD32((sp - 4)));
                    return r0;
                }
            } else {
                r2 = LD16(68 + r4);
                ST16(68 + r4, (r2 + 1));
                r2 = LD16(r14);
                r0 = 70;
                r3 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r5;
                r2 = LD16(70 + r3);
                ST16(70 + r3, (r2 + 1));
                SETMACL(LD32((sp - 20)));
                SETPR(LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            }
        } else {
            r2 = LD16(68 + r4);
            if (!((r2 & 0xFFFF) > 32)) {
                r4 = LD16(r14);
                r2 = LD16(0x060C27F6);
                r4 = r4 & 0xFFFF;
                if (!(r2 == 128)) {
                    SETMACL(LD32((sp - 20)));
                    SETPR(LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP2(0x06068A8E, r4, 0);
                    return r0;
                } else {
                    SETSP((sp - 20));
                    r0 = GCALL1(0x060692DC, r4);
                    ST16(r14, r12);
                    r3 = LD32(r13);
                    ST16(r3 + 12, r12);
                    r3 = LD32(r13);
                    ST16(r3 + 10, 0xC000);
                    r0 = 60;
                    ST16(0x060C27F6, r12);
                    r2 = LD32(r13);
                    ST16(60 + r2, 0x4B0);
                    SETMACL(LD32((sp - 20)));
                    SETPR(LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                }
            } else {
                r2 = LD16(68 + r4);
                ST16(68 + r4, (r2 - 4));
                r0 = 70;
                r2 = LD16(r14);
                r3 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r5;
                r2 = LD16(70 + r3);
                ST16(70 + r3, (r2 - 4));
                SETMACL(LD32((sp - 20)));
                SETPR(LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            }
        }
    } else {
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f0607A050(void)
{
    int r0, r2, r3, r5, r6, r7;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x0602EE02);
    SETSP((sp - 8));
    r0 = GCALL0(0x0607A620);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0607A120);
    SETSP((sp - 8));
    SETPR(0x0607A06C);
    r0 = GCALL0(0x0606D2E8);
    r3 = LD32(0x060D7768);
    ST16(62 + r3, 180);
    ST32((sp - 12), 63);
    SETSP((sp - 12));
    SETPR(0x0607A086);
    r0 = GCALL4(0x06080864, 190, 16, 31, 40);
    ST32((sp - 16), 1);
    r2 = LD16(0x060C1AA8);
    ST32((sp - 20), (r2 & 0xFFFF));
    r0 = LD32(0x060D7B3C);
    r0 = LD16(r0 + 18);
    ST32((sp - 24), r0);
    r2 = LD32(0x060D7B3C);
    r0 = LD16(r2 + 16);
    ST32((sp - 28), r0);
    r2 = LD32(0x060D7768);
    r3 = LD16(80 + r2);
    ST32((sp - 32), ((r3 & 0xFFFF) + 71));
    r2 = LD32(0x060D7B3C);
    r3 = LD16(40 + r2);
    ST32((sp - 36), (r3 & 0xFFFF));
    r7 = LD32(0x060D7B3C);
    r6 = LD32(0x060D7B3C);
    r7 = LD16(46 + r7);
    r6 = LD16(44 + r6);
    r5 = LD32(0x060D7B3C);
    r0 = LD16(r5 + 4);
    SETSP((sp - 36));
    SETPR(0x0607A0D6);
    r0 = GCALL4(0x0606CAE4, 64, (r0 + 2), (r6 & 0xFFFF), (r7 & 0xFFFF));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0607A120(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607A12A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r2 = LD16(62 + r3);
        if ((r2 & r2) == 0) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0607A178);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0607A156);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 73));
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0607A15C);
            r0 = GCALL0(0x0607B15A);
            r2 = LD32(r14);
            ST16(62 + r2, 120);
            SETSP((sp - 8));
            SETPR(0x0607A16A);
            r0 = GCALL0(0x0607B2E4);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607A178(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607A180);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD32(0x060D7768);
        r3 = LD16(62 + r2);
        if ((r3 & r3) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607A1C2);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0607A1AE);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 77));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607A1C2(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607A1CA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C1E4A);
        if ((r0 & r0) == 0) {
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 4));
            SETPR(0x0607A1FA);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), 0);
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D398);
            SETSP((sp - 4));
            r0 = GCALL0(0x06039FAC);
            SETSP((sp - 4));
            r0 = GCALL0(0x06039FB4);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607A2B2(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 16, r4);
    ST32(sp - 12, r5);
    ST32(sp - 20, r6);
    ST32(sp - 24, r7);
    r6 = LD32(sp - 12);
    r5 = LD32(sp - 16);
    SETSP((sp - 24));
    SETPR(0x0607A2CA);
    r0 = GCALL3(0x0606AE6C, 87, r5, r6);
    r5 = r0;
    if (!((r5 & r5) == 0)) {
        r2 = LD16(0x060C27F0);
        r4 = (r5 * 124) + 0x060D5F30;
        ST16(52 + r4, r2);
        r3 = LD32(sp - 20);
        ST16(68 + r4, r3);
        r2 = LD32(sp - 24);
        r0 = 70;
        ST16(70 + r4, r2);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0607A35C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607A368);
    r0 = GCALL3(0x0606B0DE, 0x060BAC00, 229, 13);
    r2 = LD32(0x060D7768);
    ST16(r2 + 18, 0);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C776);
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607A390);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 101);
    return r0;
}

int f0607A390(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607A398);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607A3CE);
        r5 = LD32(0x060D7768);
        r4 = LD32(0x060D7768);
        r5 = LD16(70 + r5);
        r4 = LD16(68 + r4);
        SETSP((sp - 4));
        r0 = GCALL2(0x06074AFA, (r4 & 0xFFFF), (r5 & 0xFFFF));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607A3CE(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607A3D8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(66 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606C7CE);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0607A402);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 28));
            r3 = LD32(r14);
            ST16(66 + r3, 1);
        }
        r3 = LD32(0x060D7B3C);
        r2 = LD16(60 + r3);
        if (!((r2 & 0xFFFF) >= 0xFF00)) {
            SETSP((sp - 8));
            SETPR(0x0607A42A);
            r0 = GCALL0(0x0606C8C0);
        } else {
            SETSP((sp - 8));
            SETPR(0x0607A420);
            r0 = GCALL0(0x0606D2C8);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0607A420(void)
{
    GJUMP0(0x0607A42A);
}

int f0607A438(void)
{
    return LD16(0x060C27FC) == 0 && GCALL2(0x0606C006, 80, 80) != 0;
}

int f0607A4C0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 12));
    SETPR(0x0607A4CC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 12));
        r0 = GCALL1(0x060144F4, 0x0607A530);
        r1 = LD32(0x060D7768);
        r2 = LD16(0x060C2800);
        r0 = LD8(r1 + 6);
        r2 = (r2 << 2) + ((((r0 & 255) - 1) << 2) << 1);
        ST32(sp - 12, r2);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 12));
        SETPR(0x0607A506);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + 29) + r2));
        r2 = LD32(0x060D7768);
        ST16(58 + r2, 22);
        SETSP((sp - 12));
        r0 = GCALL1(0x06014516, 0x0606E864);
        r2 = LD32(0x060D7768);
        ST16(62 + r2, 30);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607A530(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607A538);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607A55C);
        SETSP((sp - 4));
        SETPR(0x0607A548);
        r0 = GCALL0(0x0607A6C4);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 96);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607A55C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0607A568);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060C2802;
        r0 = LD16(0x060C2802);
        r14 = 0;
        if ((r0 & r0) == 0) {
            SETSP((sp - 12));
            r0 = GCALL0(0x0607A990);
            r4 = LD16(0x060C2804);
            r2 = LD32(0x060C2848);
            r4 = r4 - r2;
            r1 = LD16(0x060C2806);
            r2 = LD32(0x060C284C);
            r4 = r4 + (r1 - r2);
            if (!((r4 & r4) == 0)) {
                SETSP((sp - 12));
                r0 = GCALL1(0x060949D0, r4);
                if (r0 >= 64) {
                    ST16(0x060C2808, -1);
                }
            } else {
                r14 = 1;
            }
        } else {
            r3 = LD32(0x060D7768);
            r1 = LD16(62 + r3);
            if ((r1 & r1) == 0) {
                r14 = 1;
            }
        }
        SETSP((sp - 12));
        r0 = GCALL0(0x0607A7DC);
        if ((r14 & r14) == 0) {
            SETSP((sp - 12));
            SETPR(0x0607A5F8);
            r0 = GCALL0(0x0607A9F2);
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x0607A620);
            r0 = LD16(r13);
            if ((r0 & r0) == 0) {
                SETSP((sp - 12));
                SETPR(0x0607A5EA);
                r0 = GCALL1(0x060793A6, 0);
                r3 = LD16(0x060C27FC);
                ST16(0x060C27FC, (r3 + 4));
            } else {
                r3 = LD16(r13);
                ST16(r13, (r3 - 1));
                r0 = LD16(0x060C2800);
                ST16(0x060C2800, (r0 ^ 1));
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x0607A4C0);
            }
        }
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f0607A6C4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 0;
    r10 = 0;
    r13 = 0x060C285C;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r4 = LD16(0x060C1AA8);
    r4 = r4 & 0xFFFF;
    r9 = 0x060C2820;
    r8 = 0x060D7768;
    r14 = 0x060D7B3C;
    do {
        r12 = r9;
        r2 = LD32(r8);
        r0 = LD8(r2 + 6);
        r2 = LD8(0x060C2801);
        r2 = (((signed char)((((r2 << 1) + r2) << 2) << 2)) + (0x060BAC0C + ((short)(((((((r0 & 255) - 1) << 1) + ((r0 & 255) - 1)) << 2) << 2) << 1)))) + r11;
        ST32(r13, r2);
        r3 = LD32(r8);
        r0 = LD16(80 + r3);
        r3 = LD32(r2 + 8);
        ST32(r9 + 12, ((r0 & 0xFFFF) + r3));
        r2 = LD32(r14);
        r3 = LD32(r13);
        r0 = LD16(r2 + 16);
        r2 = LD32(r3);
        ST32(r12, (r0 + r2));
        r3 = LD32(r14);
        r0 = LD16(r3 + 18);
        r3 = LD32(r13);
        r2 = LD32(r3 + 4);
        ST32(r12 + 4, (r0 + r2));
        r3 = LD32(r13);
        r2 = LD32(r3 + 12);
        ST32((sp - 36), r2);
        ST32((sp - 40), r4);
        ST32((sp - 44), r10);
        ST32((sp - 48), r10);
        r3 = LD32(r12 + 12);
        ST32((sp - 52), r3);
        r2 = LD32(r14);
        r3 = LD16(40 + r2);
        ST32((sp - 56), (r3 & 0xFFFF));
        r7 = LD32(r14);
        r6 = LD32(r14);
        r7 = LD16(46 + r7);
        r6 = LD16(44 + r6);
        r5 = LD32(r14);
        r0 = LD16(r5 + 4);
        SETR(8, r8);
        SETR(9, r9);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 56));
        SETPR(0x0607A774);
        r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST32(r12 + 16, r0);
        r11 = r11 + 16;
        r4 = r0;
        r9 = r9 + 20;
    } while (AGAIN(!((unsigned)r11 >= (unsigned)48)));
    r2 = LD32(0x060C2848);
    ST16(0x060C2804, r2);
    r1 = LD32(0x060C284C);
    ST16(0x060C2806, r1);
    ST16(0x060C2808, 1);
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x0607A7DC);
    return r0;
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

int f0607AB38(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 8));
    SETPR(0x0607AB50);
    r0 = GCALL3(0x0606AE6C, 85, r0, r6);
    ST16(0x060C280A, r0);
    r0 = r0 & 0xFFFF;
    if ((r0 & r0) == 0) {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD16(0x060C280A);
        r0 = LD16(0x060C27F0);
        ST16((0x060D5F64 + ((r2 & 0xFFFF) * 124)), r0);
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 8));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), -1);
        SETMACL(LD32((sp - 8)));
        r4 = LD16(0x060C1AAA);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x0606948A, r4);
        return r0;
    }
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

int f0607AC34(int r4, int r5, int r6, int r7)
{
    int r0, r3, r8, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0607AC40);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 12));
        r0 = GCALL0(0x0607ADAE);
        r14 = 0x060D7768;
        r8 = LD32(0x060D7768);
        SETSP((sp - 12));
        r0 = GCALL0(0x0600CA84);
        ST16((r8 + 20), r0);
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 20);
        r3 = LD16(((r0 & 0xFFFF) << 1) + 0x060EE8B0);
        if (!(((r3 & 0xFFFF) & 0x1000) == 0)) {
            r3 = LD32(r14);
            r0 = LD8(r3 + 4);
            ST8(r3 + 4, (r0 | 64));
        }
        SETSP((sp - 12));
        r0 = GCALL0(0x0606D410);
        SETSP((sp - 12));
        SETPR(0x0607AC7A);
        r0 = GCALL0(0x0607ADDC);
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0607AE7E);
        return r0;
    }
}

int f0607ACDC(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    SETSP((sp - 12));
    SETPR(0x0607ACE8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 12));
        r0 = GCALL0(0x0607ADAE);
        r14 = 0x060D7768;
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C27F0);
        r4 = LD16(0x060D5F46 + ((r4 & 0xFFFF) * 124));
        SETR(14, 0x060D7768);
        SETSP((sp - 12));
        SETPR(0x0607AD12);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
        ST16(0x060C27F6, 4);
        r5 = LD16(0x060C280C);
        r0 = LD32(0x060D7768);
        r0 = LD8(r0 + 4);
        r4 = r5 & 0xFFFF;
        if (((r0 & 255) & 64) == 0) {
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            SETSP((sp - 12));
            SETPR(0x0607AD4A);
            r0 = GCALL2(0x06068A8E, r4, ((r5 & 0xFFFF) + 63));
        } else {
            if (!(((r5 & 0xFFFF) & (r5 & 0xFFFF)) == 0)) {
                SETSP((sp - 12));
                r0 = GCALL1(0x060692DC, r4);
                ST16(0x060C280C, 0);
            }
        }
        r4 = LD16(0x060C280E);
        SETSP((sp - 12));
        r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
        ST16(0x060C280E, 0);
        SETSP((sp - 12));
        r0 = GCALL1(0x060144F4, 0x0607AD74);
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607AD74(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607AD7C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x0607ADAE);
        r0 = LD32(0x060D7768);
        r0 = LD16(r0 + 20);
        r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
        if (((r0 & 0xFFFF) & 7) == 0) {
            ST16(0x060C27F6, 5);
            SETSP((sp - 4));
            SETPR(0x0607ADA2);
            r0 = GCALL0(0x0606D2C8);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0607ADAE(void)
{
    int n = LDU16(0x060C27F0);

    ST16(LD32(CURRENT) + 24, LDU16(REC(n) + 24));
    ST16(LD32(CURRENT) + 28, LDU16(REC(n) + 28));
}

int f0607ADDC(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r5 = 0x060D7B3C;
    r13 = 0x060C280C;
    r4 = LD16(0x060C280C);
    r14 = LD32(0x060D7B3C);
    if (!(((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0)) {
        r0 = LD16(r14 + 4);
        ST16(((((r4 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 4, r0);
        r3 = LD16(r13);
        r0 = LD32(r5);
        r0 = LD16(r0 + 16);
        ST16(((((r3 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 16, r0);
        r2 = LD16(r13);
        r0 = LD32(r5);
        r0 = LD16(r0 + 18);
        ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 18, r0);
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        ST32((sp - 20), -1);
        r2 = LD16(0x060C1AA8);
        ST32((sp - 24), (r2 & 0xFFFF));
        r0 = LD16(r14 + 18);
        ST32((sp - 28), r0);
        r0 = LD16(r14 + 16);
        ST32((sp - 32), r0);
        r2 = LD32(0x060D7768);
        r3 = LD16(80 + r2);
        ST32((sp - 36), ((r3 & 0xFFFF) + 62));
        r2 = LD16(40 + r14);
        ST32((sp - 40), (r2 & 0xFFFF));
        r7 = LD16(46 + r14);
        r6 = LD16(44 + r14);
        r0 = LD16(r14 + 4);
        SETR(13, r13);
        SETSP((sp - 40));
        SETPR(0x0607AE32);
        r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST16(r13, r0);
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606C7C2);
        return r0;
    }
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

int f0607B044(int r4, int r5, int r6, int r7)
{
    int r0, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    SETPR(0x0607B054);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x0600A0B8;
        r12 = 1;
        SETSP((sp - 20));
        r0 = GCALL0(0x0600A0B8);
        if ((r0 & 1) == 0) {
            SETSP((sp - 20));
            r0 = GCALL0(r14);
            if ((r0 & r12) == 0) {
                r11 = 0x2A0;
            } else {
                r11 = 0x140;
            }
            SETSP((sp - 20));
            r0 = GCALL0(r14);
            r13 = 0x168 + r0;
        } else {
            SETSP((sp - 20));
            r0 = GCALL0(r14);
            r11 = 0x178 + r0;
            SETSP((sp - 20));
            r0 = GCALL0(r14);
            if ((r0 & r12) == 0) {
                r13 = 0x260;
            } else {
                r13 = 0x160;
            }
        }
        SETSP((sp - 20));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        SETSP((sp - 20));
        r0 = GCALL2(0x06074AFA, r11, r13);
        SETSP((sp - 20));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f0607B15A(void)
{
    int r0, r4, r5, r6, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    r14 = 0;
    ST32((sp - 12), R(12));
    r12 = 4;
    r13 = 0x060D7768;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 124;
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    r9 = 0x060D5F30;
    r10 = 0x0606AE6C;
    do {
        r6 = LD32(r13);
        r5 = LD32(r13);
        r0 = LD16(r6 + 28);
        r6 = r0;
        r0 = LD16(r5 + 24);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 32));
        SETPR(0x0607B186);
        r0 = GCALL3(r10, 89, r0, r6);
        r4 = r0;
        if (!((r4 & r4) == 0)) {
            r0 = 66;
            ST16(66 + ((r4 * r11) + r9), r14);
        }
        r14 = r14 + 1;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r12)));
    SETMACL(LD32((sp - 32)));
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0607B204(void)
{
    int r0, r1, r2, r3, r4, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = sp - 44;
    SETSP((sp - 44));
    r0 = COPYW(0x06094450, (sp - 44), 0x060B2B8C, 32);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x0607B21E);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r13 = 0x060D7B3C;
        r4 = 0x060D7768;
        r3 = LD32(0x060D7B3C);
        r2 = LD32(0x060D7768);
        r2 = LD16((68 + r2));
        r1 = LD16(38 + r3);
        ST16(38 + r3, (r1 + r2));
        r3 = LD32(0x060D7768);
        r2 = LD16(68 + r3);
        ST16(68 + r3, (r2 + 1));
        r3 = LD32(0x060D7B3C);
        r2 = LD16(38 + r3);
        if (!(r2 >= 0)) {
            r1 = LD32(r4);
            r2 = LD16(66 + r1);
            r0 = LD16(r1 + 24);
            r3 = LD32(((((r2 & 0xFFFF) << 2) << 1) + r14));
            ST16(r1 + 24, (r0 + r3));
            r2 = LD32(r4);
            r1 = LD16(66 + r2);
            r0 = LD16(r2 + 28);
            r3 = LD32((r14 + (((r1 & 0xFFFF) << 2) << 1)) + 4);
            ST16(r2 + 28, (r0 + r3));
        } else {
            SETSP((sp - 44));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
            r3 = LD32(r13);
            ST16(38 + r3, 0);
        }
        SETSP((sp - 44));
        r0 = GCALL0(0x0606D410);
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0607B2E4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 8));
    SETPR(0x0607B2FC);
    r0 = GCALL3(0x0606AE6C, 88, r0, r6);
    r4 = r0;
    if ((r4 & r4) == 0) {
        ST16(0x060C1E4A, 1);
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = r4 * 124;
        r1 = LD16(0x060D5F5A + r3);
        ST16(0x060D5F5A + r3, (r1 | 128));
        r4 = LD16(0x060C1AAA);
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06069462, r4, 0x1E7);
        return r0;
    }
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

int f0607B6A4(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    SETSP((sp - 12));
    SETPR(0x0607B6B0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 12));
        SETPR(0x0607B6CA);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 15));
        ST16(0x060C288E, 1);
        r3 = LD32(0x060D7768);
        r0 = LD16(0x060C288A);
        r0 = LD16((((r0 & 0xFFFF) * 124) + 0x060D5F30) + 24);
        ST16(r3 + 24, (r0 + 0xFFFD));
        r3 = LD32(0x060D7768);
        r0 = LD16(0x060C288A);
        r0 = LD16((((r0 & 0xFFFF) * 124) + 0x060D5F30) + 28);
        ST16(r3 + 28, r0);
        r3 = LD32(0x060D7B3C);
        ST16(38 + r3, -29);
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 24);
        if (!((r0 & 0xFFFF) > 64)) {
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x0607B72A);
        }
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607B72A(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607B734);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7B3C;
        r3 = LD32(0x060D7B3C);
        r2 = LD16(38 + r3);
        ST16(38 + r3, (r2 + 1));
        r3 = LD32(0x060D7B3C);
        r2 = LD16(38 + r3);
        if (r2 >= 0) {
            SETSP((sp - 8));
            r0 = GCALL1(0x0600996A, 123);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0607B76A);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 1));
            r2 = LD32(r14);
            ST16(38 + r2, 0);
            ST16(0x060C288E, 0);
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0607B79A);
            ST16(0x060C2870, 2);
            ST16(0x060C2872, 1);
            SETSP((sp - 8));
            r0 = GCALL0(0x0607B9D8);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607B79A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607B7A2);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607B7C8);
        ST16(0x060C2870, 2);
        ST16(0x060C2872, 0);
        SETSP((sp - 4));
        r0 = GCALL0(0x0607B9D8);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0607B88C(void)
{
    gaddr p = LD32(CURRENT) + 60;

    ST16(p, (GCALL0(0x0600A0B8) & 1) ? 0x258 : 0x708);
}

int f0607B90A(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x0607B918);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 16));
        r0 = GCALL1(0x0606AB24, r4);
        r13 = 0x060C2870;
        r14 = LD16(0x060C2870);
        r12 = 0x0600A0EC;
        r14 = r14 & 0xFFFF;
        while (1) {
            r2 = LD16(r13);
            if (r14 == (r2 & 0xFFFF)) {
                POLL();
                SETSP((sp - 16));
                r0 = GCALL1(r12, 5);
                r14 = r0;
                continue;
            } else {
                break;
            }
        }
        r4 = LD16(r13);
        if (!((unsigned)r14 > (unsigned)(r4 & 0xFFFF))) {
            r4 = 192;
        } else {
            r4 = 96;
        }
        r2 = LD32(0x060D7768);
        ST16(r2 + 12, ((int)((unsigned)r4 >> 8)));
        r3 = LD32(0x060D7768);
        ST16(r3 + 10, ((255 & r4) << 8));
        SETSP((sp - 16));
        r0 = GCALL1(0x060144F4, 0x0607BA0E);
        ST16(r13, r14);
        SETSP((sp - 16));
        r0 = GCALL0(0x0607B9D8);
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0607B9D8(void)
{
    int row = LDU16(0x060C2872) << 1;
    int x = LDU16(0x060BAE60 + row);
    int y = LDU16(0x060BAE48 + (LDU16(0x060C2870) << 2) + row);

    GCALL2(0x06074AFA, y, x);
    GJUMP1(0x06014516, 0x06074CB4);
}

int f0607BA0E(void)
{
    int r0, r2, r3, r4, r5, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    SETPR(0x0607BA1E);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r11 = 0x060C1AA8;
        r12 = 0x0606D410;
        r13 = 0x060144F4;
        r14 = 0x060D7768;
        r2 = LD32(0x060C1000);
        if ((unsigned)r2 > (unsigned)0xBB8) {
            r3 = LD32(r14);
            r0 = LD16(60 + r3);
            if (!((r0 & r0) == 0)) {
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 20));
                SETPR(0x0607BA80);
                r0 = GCALL0(0x0607BCCA);
                if ((r0 & r0) == 0) {
                    SETSP((sp - 20));
                    r0 = GCALL1(0x0600A0EC, 3);
                    r4 = r0;
                    if (!((r4 & r4) == 0)) {
                        if (!(r4 == 1)) {
                            r0 = LD32(r14);
                            ST16((62 + r0), 180);
                            SETSP((sp - 20));
                            r0 = GCALL1(r13, 0x0607BC9A);
                        } else {
                            SETSP((sp - 20));
                            r0 = GCALL1(r13, 0x0607BBAE);
                            r5 = LD32(r14);
                            r4 = LD16(r11);
                            r5 = LD16(80 + r5);
                            SETR(12, r12);
                            SETR(14, r14);
                            SETSP((sp - 20));
                            SETPR(0x0607BB32);
                            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 22));
                            r2 = LD32(r14);
                            ST16(62 + r2, 180);
                            ST16(0x060C2876, 0);
                        }
                    } else {
                        SETSP((sp - 20));
                        r0 = GCALL1(r13, 0x0607BB60);
                        r4 = LD16(r11);
                        r5 = LD32(r14);
                        r5 = LD16(80 + r5);
                        SETR(12, r12);
                        SETSP((sp - 20));
                        SETPR(0x0607BAA8);
                        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
                        SETSP((sp - 20));
                        r0 = GCALL1(0x06014516, 0x0606D88C);
                        SETR(12, r12);
                        SETSP((sp - 20));
                        SETPR(0x0607BAB6);
                        r0 = GCALL0(0x0607CD84);
                    }
                }
            } else {
                SETSP((sp - 20));
                r0 = GCALL1(r13, 0x0607C1C0);
                ST16(0x060C288C, 0);
                SETR(12, r12);
                SETSP((sp - 20));
                SETPR(0x0607BA78);
                r0 = GCALL1(0x0607E0BC, 1);
            }
        } else {
            SETSP((sp - 20));
            r0 = GCALL1(r13, 0x0607C524);
            r4 = LD16(r11);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            SETR(12, r12);
            SETSP((sp - 20));
            SETPR(0x0607BA50);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
            SETSP((sp - 20));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETSP((sp - 20));
        r0 = GCALL0(r12);
    }
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0607BB60(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607BB68);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0607BB82);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 11));
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 4));
            r0 = GCALL1(0x0600996A, 138);
        }
        r0 = LD16(0x060C2874);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x06009A3A, 138);
            SETSP((sp - 4));
            SETPR(0x0607BBA2);
            r0 = GCALL1(0x0607B8AE, 0);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607BBAE(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607BBB6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607BC3C);
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0607BBE4);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 23));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607BC3C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607BC44);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x0607BC4E);
        r0 = GCALL0(0x0607CFFE);
        r2 = LD16(0x060C2876);
        ST16(0x060C2876, (r2 + 1));
        r3 = LD16(0x060C2876);
        if ((r3 & 0xFFFF) >= 3) {
            SETSP((sp - 4));
            SETPR(0x0607BC8E);
            r0 = GCALL1(0x0607B8AE, 0);
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607BBAE);
            r3 = LD32(0x060D7768);
            ST16(62 + r3, 40);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0607BC86);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 22));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0607BC86(void)
{
    GJUMP0(0x0607BC8E);
}

int f0607BC9A(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607BCA2);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 4));
            SETPR(0x0607BCBE);
            r0 = GCALL0(0x0607BCCA);
        } else {
            SETSP((sp - 4));
            SETPR(0x0607BCB6);
            r0 = GCALL1(0x0607B8AE, 0);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f0607BEBC(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607BEC4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607BF14);
        r2 = LD32(0x060D7768);
        ST16(r2 + 12, 1);
        r3 = LD32(0x060D7768);
        ST16(r3 + 10, 0x8000);
        r5 = LD16(0x060C2872);
        r4 = LD16(0x060C287C);
        r5 = LD16(0x060BAE60 + ((r5 & 0xFFFF) << 1));
        r4 = LD16(0x060BAEBA + ((r4 & 0xFFFF) << 2));
        SETSP((sp - 4));
        r0 = GCALL2(0x06074AFA, ((r4 & 0xFFFF) + 32), (r5 & 0xFFFF));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607BF14(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 20));
    SETPR(0x0607BF24);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 20));
        r0 = GCALL1(0x060144F4, 0x0607C040);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 20));
        SETPR(0x0607BF46);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 28));
        SETSP((sp - 20));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        r2 = LD32(0x060D7768);
        ST16(62 + r2, 60);
        r5 = LD16(0x060C287C);
        r5 = ((r5 & 0xFFFF) << 2) + 0x060BAEBA;
        ST32(sp - 20, r5);
        r0 = LD16(r5 + 2);
        r4 = LD32(sp - 20);
        r4 = LD16(r4);
        SETSP((sp - 20));
        r0 = GCALL2(0x0600CA32, ((int)((unsigned)((int)((unsigned)(r4 & 0xFFFF) >> 2)) >> 2)), ((int)((unsigned)((int)((unsigned)(r0 & 0xFFFF) >> 2)) >> 2)));
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 20));
        r0 = GCALL1(0x06069606, r4);
        ST32((sp - 24), 0);
        ST32((sp - 28), 0);
        r2 = LD16(0x060D7E8A);
        ST32((sp - 32), r2);
        r1 = LD16(0x060D7E88);
        ST32((sp - 36), r1);
        r2 = LD32(0x060D7768);
        r1 = LD16(80 + r2);
        ST32((sp - 40), ((r1 & 0xFFFF) + 36));
        r2 = LD32(0x060D7B3C);
        r1 = LD16(40 + r2);
        ST32((sp - 44), (r1 & 0xFFFF));
        r6 = LD32(0x060D7B3C);
        r6 = LD16(44 + r6);
        SETSP((sp - 44));
        SETPR(0x0607BFBE);
        r0 = GCALL4(0x0606CAE4, 0, 152, (r6 & 0xFFFF), r0);
        ST16(0x060C2888, r0);
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C040(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 16));
    SETPR(0x0607C04E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 16));
            r0 = GCALL1(0x0600996A, 133);
            SETSP((sp - 16));
            r0 = GCALL1(0x060144F4, 0x0607C0E8);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 16));
            SETPR(0x0607C082);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 29));
            r3 = LD16(0x060C287C);
            r2 = LD16(0x060BAECE + ((r3 & 0xFFFF) << 1));
            ST32((sp - 20), (r2 & 0xFFFF));
            r7 = LD16(0x060C287C);
            r7 = ((r7 & 0xFFFF) << 2) + 0x060BAEBA;
            ST32(sp - 16, r7);
            r0 = LD16(r7 + 2);
            r7 = r0 & 0xFFFF;
            r6 = LD32(sp - 16);
            r6 = LD16(r6);
            r5 = LD32(r14);
            r4 = LD32(r14);
            r0 = LD16(r5 + 28);
            r5 = (r0 & 0xFFFF) - 52;
            r0 = LD16(r4 + 24);
            SETR(13, 0x060C287C);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x0607C0BC);
            r0 = GCALL4(0x0607D2D8, ((r0 & 0xFFFF) - 26), r5, (r6 & 0xFFFF), r7);
            r3 = LD16(0x060C287C);
            ST16(0x060C287E + ((r3 & 0xFFFF) << 1), 1);
            r3 = LD32(r14);
            ST16(62 + r3, 30);
        }
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C0E8(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C0F0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607C118);
            SETSP((sp - 4));
            r0 = GCALL0(0x0607C1A0);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C118(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C120);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x0607C128);
        r0 = GCALL1(0x0607B8AE, 0);
        ST16(0x060C2872, 0);
        r5 = LD16(0x060BAE60);
        SETSP((sp - 4));
        r0 = GCALL2(0x06074AFA, 144, (r5 & 0xFFFF));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0607C1A0(void)
{
    int id = LDU16(0x060C2888);

    if (id) {
        GCALL1(0x060692DC, id);
        ST16(0x060C2888, 0);
    }
}

int f0607C1C0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C1C8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C288C);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 4));
            r0 = GCALL1(0x0600996A, 124);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607C214);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0607C1FA);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 14));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            ST16(0x060C288E, 0);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C214(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607C21E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 8));
        SETPR(0x0607C238);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 15));
        r14 = 0x060C288E;
        r3 = LD16(0x060C288E);
        ST16(0x060C288E, (r3 + 1));
        r4 = LD16(0x060C288E);
        SETSP((sp - 8));
        r0 = GCALL1(0x0606CE8C, ((r4 & 0xFFFF) << 2));
        r2 = LD32(0x060D7B3C);
        SETSP((sp - 8));
        r0 = HELPER((int)r0 >> 11);
        ST16((38 + r2), (-r0));
        r2 = LD16(0x060C288E);
        if ((r2 & 0xFFFF) >= 32) {
            ST16(r14, 0);
            SETSP((sp - 8));
            r0 = GCALL1(0x0600996A, 123);
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0607C2A4);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 8));
            SETPR(0x0607C28E);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 16));
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C2EE(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C2F6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607C39C);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0607C318);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 17));
        r2 = LD32(0x060D7768);
        ST16(62 + r2, 42);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C3D8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C3E0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            SETSP((sp - 4));
            r0 = GCALL1(0x0600996A, 136);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607C434);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0607C41A);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 18));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            ST16(0x060C2876, 0);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C434(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607C43E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD32(0x060D7B3C);
        r3 = LD16(r0 + 60);
        if ((r3 & 0xFFFF) >= 0xFF00) {
            r14 = 0x060C2876;
            r2 = LD16(0x060C2876);
            if ((r2 & 0xFFFF) >= 5) {
                SETSP((sp - 8));
                SETPR(0x0607C4D8);
                r0 = GCALL0(0x0607D464);
                SETSP((sp - 8));
                r0 = GCALL1(0x060144F4, 0x0607C4EE);
            } else {
                r4 = LD16(0x060C1AA8);
                r5 = LD32(0x060D7768);
                r5 = LD16(80 + r5);
                SETR(14, r14);
                SETSP((sp - 8));
                SETPR(0x0607C474);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 19));
                r0 = LD16(r14);
                if (!((r0 & r0) == 0)) {
                    SETR(14, r14);
                    SETSP((sp - 8));
                    SETPR(0x0607C480);
                    r0 = GCALL0(0x0607D464);
                }
                r2 = LD16(r14);
                ST16(r14, (r2 + 1));
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C4EE(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C4F6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x0607C4FE);
        r0 = GCALL1(0x0607B8AE, 0);
        SETSP((sp - 4));
        r0 = GCALL0(0x0607B88C);
        r3 = LD32(0x060D7768);
        ST16(r3 + 12, 0);
        r3 = LD32(0x060D7768);
        ST16(r3 + 10, 0x8000);
        ST16(0x060C2872, 0);
        SETSP((sp - 4));
        r0 = GCALL0(0x0607B9D8);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C524(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C52C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x0602EE02);
        ST16(0x060C1E4A, 1);
        ST16(0x060C2894, 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607C572);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0607C560);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
        SETSP((sp - 4));
        SETPR(0x0607C566);
        r0 = GCALL1(0x0607E0BC, 2);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C572(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C57A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C2894);
        if (!((r0 & r0) == 0)) {
            r2 = LD32(0x060D7768);
            r0 = LD16(r2 + 24);
            if (!(r0 >= -256)) {
                r3 = LD16(0x060C062C);
                r4 = 0x060C1914;
                ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x0606B1EC);
                r3 = LD32(0x060C1914);
                if (!(r3 > 0)) {
                    r1 = LD16(0x060C2896);
                    if (!((r1 & r1) == 0)) {
                        SETSP((sp - 4));
                        r0 = GCALL1(0x0600996A, 132);
                        ST16(0x060C2896, 0);
                    }
                    r0 = LD16(0x060C1E4A);
                    if (!((r0 & r0) == 0)) {
                        SETSP((sp - 4));
                        r0 = GCALL0(0x0607BD28);
                        SETSP((sp - 4));
                        r0 = GCALL1(0x060144F4, 0x0606D23C);
                        ST16(0x060C2860, 0);
                        SETSP((sp - 4));
                        r0 = GCALL0(0x06039FAC);
                        SETSP((sp - 4));
                        r0 = GCALL0(0x06039FB4);
                    }
                } else {
                    r2 = LD32(r4);
                    ST32(r4, (r2 - 0x100));
                }
            } else {
                SETSP((sp - 4));
                r0 = GCALL0(0x0607B44C);
            }
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C65A(void)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0607C1A0);
    SETSP((sp - 4));
    r0 = GCALL0(0x0602EE02);
    SETSP((sp - 4));
    r0 = GCALL1(0x06009A3A, 138);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607C6A0);
    SETSP((sp - 4));
    SETPR(0x0607C67C);
    r0 = GCALL0(0x0606D2E8);
    ST32((sp - 8), 63);
    SETSP((sp - 8));
    SETPR(0x0607C68E);
    r0 = GCALL4(0x06080864, 180, 32, 63, 56);
    r3 = LD32(0x060D7768);
    ST16(62 + r3, 180);
    SETPR(LD32((sp - 4)));
    return 62;
}

int f0607C6A0(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C6A8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607C75C);
            SETSP((sp - 4));
            SETPR(0x0607C6C6);
            r0 = GCALL0(0x0607D804);
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0607C6DC);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 6));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            SETSP((sp - 4));
            SETPR(0x0607C6E8);
            r0 = GCALL1(0x0607D61C, 0);
            SETSP((sp - 4));
            SETPR(0x0607C6EC);
            r0 = GCALL1(0x0607D61C, 1);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607C75C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607C764);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 24);
        if (!(r0 >= -256)) {
            r4 = 0x060C1914;
            r1 = LD32(0x060C1914);
            if (!(r1 > 0)) {
                r0 = LD16(0x060C2896);
                if (!((r0 & r0) == 0)) {
                    SETSP((sp - 4));
                    r0 = GCALL1(0x0600996A, 132);
                    ST16(0x060C2896, 0);
                }
                r0 = LD16(0x060C1E4A);
                if (!((r0 & r0) == 0)) {
                    SETSP((sp - 4));
                    r0 = GCALL0(0x0607BD28);
                    SETSP((sp - 4));
                    r0 = GCALL1(0x060144F4, 0x0606D398);
                    ST16(0x060C2860, 0);
                    SETSP((sp - 4));
                    r0 = GCALL0(0x06039FAC);
                    SETSP((sp - 4));
                    r0 = GCALL0(0x06039FB4);
                }
            } else {
                r0 = LD32(r4);
                ST32(r4, (r0 - 0x100));
            }
        } else {
            SETSP((sp - 4));
            r0 = GCALL0(0x0607B44C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
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

int f0607CD84(void)
{
    int r0, r3, r4, r5, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(8));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST16(0x060C2874, 0);
    SETSP((sp - 20));
    r0 = GCALL0(0x0606E81C);
    r4 = LD32(0x060D7768);
    r4 = LD16(64 + r4);
    r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
    r0 = LD8(r4 + 4);
    r0 = r0 & 255;
    if ((r0 & 192) == 0) {
        r0 = LD16(r4 + 24);
        ST32(sp - 16, (((r0 & 0xFFFF) + 8) & 0xFFF0));
        r0 = LD16(r4 + 28);
        r0 = ((r0 & 0xFFFF) + 8) & 0xFFF0;
        ST32(sp - 20, r0);
        r5 = LD32(sp - 16);
        SETSP((sp - 20));
        SETPR(0x0607CDD2);
        r0 = GCALL3(0x0606AE6C, 95, r5, r0);
        r4 = r0;
        if (!((r4 & r4) == 0)) {
            r4 = (r4 * 124) + 0x060D5F30;
            ST32(sp - 20, r4);
            r3 = LD16(0x060C2860);
            ST16(52 + r4, r3);
            r8 = LD32(sp - 20);
            r4 = LD32(0x060D7B3C);
            SETSP((sp - 20));
            r0 = GCALL1(0x06068B62, r4);
            ST16((r8 + 62), r0);
            ST16(0x060C2874, 1);
        }
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(8, LD32((sp - 4)));
    return r0;
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

int f0607CFFE(void)
{
    int r0, r2, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    r0 = GCALL1(0x0600996A, 134);
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 8));
    SETPR(0x0607D022);
    r0 = GCALL3(0x0606AE6C, 94, r0, (r6 + 0xFFE0));
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r0 = 0x060D5F64;
        r2 = LD16(0x060C2860);
        ST16(0x060D5F64 + (r4 * 124), r2);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
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

int f0607D120(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8, r10, r11, r12;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(8));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    SETSP((sp - 32));
    SETPR(0x0607D136);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 32)));
        SETPR(LD32((sp - 28)));
        SETR(8, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 32));
        r0 = GCALL0(0x0606E81C);
        r12 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r4 = LD16(64 + r4);
        r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
        r0 = LD8(r4 + 4);
        if (!(((r0 & 255) & 192) == 0)) {
            r11 = 64;
            r10 = 128;
        } else {
            r0 = LD16(r4 + 24);
            r11 = (r0 & 0xFFFF) + 8;
            r0 = LD16(r4 + 28);
            r11 = r11 & 0xFFF0;
            r10 = ((r0 & 0xFFFF) + 8) & 0xFFF0;
        }
        SETSP((sp - 32));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        SETSP((sp - 32));
        r0 = GCALL0(0x06074770);
        r4 = r0;
        if (!((unsigned)r4 >= (unsigned)8)) {
            r1 = LD32(r12);
            ST16(90 + r1, r4);
            r4 = ((short)((short)r4 * (short)220)) + 0x060C1F78;
            ST32(0x060C2658, r4);
            r8 = r4 + 12;
            r4 = LD32(r12);
            r0 = LD16(r4 + 24);
            SETSP((sp - 32));
            r0 = GCALL1(0x060980DC, (r0 & 0xFFFF));
            ST32(r8, r0);
            r8 = LD32(0x060C2658);
            r4 = LD32(r12);
            r0 = LD16(r4 + 28);
            SETSP((sp - 32));
            r0 = GCALL1(0x060980DC, (r0 & 0xFFFF));
            ST32((r8 + 16), r0);
            r8 = LD32(0x060C2658);
            SETSP((sp - 32));
            r0 = GCALL1(0x060980DC, r11);
            ST32((r8 + 20), r0);
            r8 = LD32(0x060C2658);
            SETSP((sp - 32));
            r0 = GCALL1(0x060980DC, r10);
            ST32((r8 + 24), r0);
            r8 = LD32(0x060C2658);
            SETSP((sp - 32));
            r0 = GCALL1(0x0600A10E, 224);
            SETSP((sp - 32));
            r0 = GCALL1(0x060980DC, (r0 + 64));
            ST32((r8 + 28), r0);
            r8 = LD32(0x060C2658);
            SETSP((sp - 32));
            r0 = GCALL1(0x060980DC, 240);
            ST32((r8 + 32), r0);
            r3 = LD32(0x060C2658);
            ST32(r3 + 8, 3);
            r3 = LD32(0x060C2658);
            ST32(76 + r3, 16);
            r3 = LD32(0x060C2658);
            r1 = LD16(212 + r3);
            ST16(212 + r3, (r1 | 1));
            SETSP((sp - 32));
            r0 = GCALL1(0x06014516, 0x060747C0);
            SETSP((sp - 32));
            r0 = GCALL1(0x0600996A, 135);
        }
        SETMACL(LD32((sp - 32)));
        SETPR(LD32((sp - 28)));
        SETR(8, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f0607D2D8(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 16, r4);
    ST32(sp - 12, r5);
    ST32(sp - 20, r6);
    ST32(sp - 24, r7);
    r6 = LD32(sp - 12);
    r5 = LD32(sp - 16);
    SETSP((sp - 24));
    SETPR(0x0607D2F0);
    r0 = GCALL3(0x0606AE6C, 96, r5, r6);
    r5 = r0;
    if (!((r5 & r5) == 0)) {
        r2 = LD16(0x060C2860);
        r4 = (r5 * 124) + 0x060D5F30;
        ST16(52 + r4, r2);
        r3 = LD32(sp - 20);
        ST16(66 + r4, r3);
        r2 = LD32(sp - 24);
        ST16(68 + r4, r2);
        r3 = LD32(sp);
        r0 = 70;
        ST16(70 + r4, r3);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
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

int f0607D35C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607D364);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607D3F0);
        r5 = LD32(0x060D7768);
        r4 = LD32(0x060D7768);
        r5 = LD16(68 + r5);
        r4 = LD16(66 + r4);
        SETSP((sp - 4));
        r0 = GCALL2(0x06074AFA, (r4 & 0xFFFF), (r5 & 0xFFFF));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607D3F0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607D3FA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL1(0x0600996A, 141);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        SETSP((sp - 8));
        r0 = GCALL0(0x0606C7CE);
        SETSP((sp - 8));
        SETPR(0x0607D41A);
        r0 = GCALL0(0x0606C8C0);
        r6 = LD32(0x060D7768);
        r0 = LD16(r6 + 28);
        r5 = LD32(0x060D7768);
        r4 = LD32(0x060D7768);
        r6 = (r0 & 0xFFFF) + 8;
        r0 = LD16(r5 + 24);
        r4 = LD16(70 + r4);
        SETSP((sp - 8));
        r0 = GCALL4(0x0602370A, (r4 & 0xFFFF), ((((((r0 & 0xFFFF) + 8) >> 1) >> 1) >> 1) >> 1), ((((r6 >> 1) >> 1) >> 1) >> 1), 0);
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 20);
        SETSP((sp - 8));
        r0 = GCALL2(0x0606C82C, (r0 & 0xFFFF), 128);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607D464(void)
{
    int r0, r2, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    r0 = GCALL1(0x0600996A, 140);
    r6 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r5 = LD32(0x060D7768);
    r6 = r0 + 0xFFB0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 8));
    SETPR(0x0607D48A);
    r0 = GCALL3(0x0606AE6C, 97, (r0 + 88), r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r0 = 0x060D5F64;
        r2 = LD16(0x060C2860);
        ST16(0x060D5F64 + (r4 * 124), r2);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
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

int f0607D55C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607D564);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607D592);
        r5 = LD32(0x060D7768);
        r0 = LD16(r5 + 28);
        SETSP((sp - 4));
        r0 = GCALL2(0x06074AFA, 0x220, (r0 & 0xFFFF));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607D592(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0607D59E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r1 = LD16(42 + r3);
        ST16(42 + r3, (r1 & 0xFF7F));
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AA8);
        SETR(14, 0x060D7768);
        SETSP((sp - 12));
        SETPR(0x0607D5C4);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 25));
        r8 = LD32(0x060D7768);
        SETSP((sp - 12));
        r0 = GCALL1(0x0600A0EC, 79);
        ST16((r8 + 28), ((r0 & 0xFF0) + 128));
        r1 = LD32(0x060D7768);
        r0 = LD16(r1 + 28);
        ST16(r1 + 28, (r0 + 1));
        SETSP((sp - 12));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        r5 = LD32(0x060D7768);
        r0 = LD16(r5 + 28);
        SETSP((sp - 12));
        r0 = GCALL2(0x06074AFA, 0, (r0 & 0xFFFF));
        SETSP((sp - 12));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f0607D764(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607D76C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        r4 = LD32(0x060D7768);
        r0 = LD16(66 + r4);
        r5 = 0;
        if ((r0 & r0) == 0) {
            r4 = 0;
        } else {
            r4 = 0x170;
        }
        SETSP((sp - 4));
        r0 = GCALL2(0x06074AFA, r4, r5);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607D8B0(void)
{
    int r0, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    SETPR(0x0607D8BE);
    r0 = GCALL3(0x0606B0DE, 0x060BAF62, 0x162, 15);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7FE);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x060805BA);
    r4 = LD16(0x060C2860);
    r3 = LD32(0x060D7768);
    r4 = LD16(0x060D5F46 + ((r4 & 0xFFFF) * 124));
    r0 = LD16(0x060C3860 + ((((r4 & 0xFFFF) & 0xFFFF) * 84) & 0xFFFF));
    ST16((66 + r3), r0);
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
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

int f0607D96C(void)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607D978);
    r0 = GCALL3(0x0606B0DE, 0x060BAF6E, 0x187, 16);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 0x200));
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607D9A2);
    SETPR(LD32((sp - 4)));
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0);
    return 66;
}

int f0607D9A2(int r4, int r5, int r6, int r7)
{
    int r0, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    r0 = GCALL0(0x060694B8);
    SETSP((sp - 12));
    SETPR(0x0607D9B4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD32(0x060D7768);
        r0 = LD16(66 + r14);
        if ((r0 & r0) == 0) {
            r0 = LD16(r14 + 20);
            r13 = LD16(0x060B90A4);
            r13 = r13 + (r0 & 0xFFFF);
            r0 = LD16((r13 << 1) + 0x060EC8B0);
            if (!(((r0 & 0xFFFF) & 7) == 0)) {
                SETSP((sp - 12));
                r0 = GCALL1(0x06040DEE, r13);
                ST16((68 + r14), r0);
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x0607DA1E);
                r4 = LD16(0x060C1AA8);
                r5 = LD32(0x060D7768);
                r5 = LD16(80 + r5);
                SETSP((sp - 12));
                SETPR(0x0607DA04);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 3));
                SETSP((sp - 12));
                r0 = GCALL1(0x06014516, 0x0606D8B6);
            }
        }
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607DA1E(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607DA26);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 129);
        r2 = LD32(0x060D7768);
        ST16(66 + r2, 1);
        r4 = LD32(0x060D7768);
        r4 = LD16(68 + r4);
        SETSP((sp - 4));
        SETPR(0x0607DA46);
        r0 = GCALL1(0x0607DABC, (r4 & 0xFFFF));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607D9A2);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607DA5A(void)
{
    ST16(0x060C2878, 0);
    ST16(0x060C287A, 0);
    return 0;
}

int f0607DABC(int r4)
{
    int r0, r2, r3, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 12, r4);
    r6 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r5 = LD32(0x060D7768);
    r6 = r0 + 0xFFF0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 12));
    SETPR(0x0607DADC);
    r0 = GCALL3(0x0606AE6C, 93, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD16(0x060C062C);
        r5 = (r4 * 124) + 0x060D5F30;
        ST16(52 + r5, r2);
        r3 = LD32(sp - 12);
        r0 = 74;
        ST16(74 + r5, r3);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
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

int f0607DBA4(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 8));
    SETPR(0x0607DBAE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 24);
        if ((r0 & 0xFFFF) >= 176) {
            r2 = 1;
        } else {
            r2 = 0;
        }
        ST32(sp - 8, r2);
        ST16(68 + r3, r2);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        r4 = LD32(sp - 8);
        r4 = LD16(0x060BAF94 + (r4 << 1));
        SETSP((sp - 8));
        r0 = GCALL2(0x06074AFA, (r4 & 0xFFFF), 64);
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607DC4C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 16));
    r0 = GCALL1(0x0600996A, 130);
    r14 = 0x060D7768;
    r13 = 0;
    r2 = LD32(0x060D7768);
    ST16(72 + r2, 0);
    r5 = LD32(0x060D7768);
    r5 = LD16(52 + r5);
    r4 = ((r5 & 0xFFFF) * 124) + 0x060D5F30;
    r0 = LD8(r4 + 4);
    if (((r0 & 255) & 192) == 0) {
        ST16(66 + r4, r13);
    }
    r3 = LD32(r14);
    r0 = LD16(66 + r3);
    if (!((r0 & r0) == 0)) {
        r4 = LD32(r14);
        r4 = LD16(66 + r4);
        SETSP((sp - 16));
        r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
        r2 = LD32(r14);
        ST16(66 + r2, r13);
    }
    r3 = LD32(r14);
    r2 = LD16(68 + r3);
    ST16(0x060C2878 + ((r2 & 0xFFFF) << 1), 1);
    r5 = LD32(r14);
    r5 = LD16(80 + r5);
    r4 = LD16(0x060C1AA8);
    SETR(14, r14);
    SETSP((sp - 16));
    SETPR(0x0607DCC4);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
    r3 = LD32(0x060D7B3C);
    r2 = LD16(68 + r3);
    ST16(68 + r3, (r2 << 1));
    r3 = LD32(0x060D7B3C);
    r2 = LD16(70 + r3);
    ST16(70 + r3, (r2 << 1));
    r3 = LD32(r14);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 128));
    r3 = LD32(0x060D7B3C);
    ST16(r3 + 4, 0x1E0);
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x0607DCFC);
    return r0;
}

int f0607DCFC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607DD04);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D2C8);
        } else {
            r1 = LD32(0x060D7768);
            r0 = LD16(r1 + 24);
            if ((r0 & 0xFFFF) > 0x120) {
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0606D2C8);
            } else {
                SETSP((sp - 4));
                r0 = GCALL0(0x0607B44C);
            }
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f0607DEAC(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    r13 = 0x060D7768;
    r8 = LD32(0x060D7768);
    ST32((sp - 24), -1);
    r8 = r8 + 66;
    r3 = LD16(0x060C1AA8);
    ST32((sp - 28), (r3 & 0xFFFF));
    r0 = LD32(0x060D7B3C);
    r0 = LD16(r0 + 18);
    ST32((sp - 32), r0);
    r3 = LD32(0x060D7B3C);
    r0 = LD16(r3 + 16);
    ST32((sp - 36), r0);
    r3 = LD32(0x060D7768);
    r0 = LD16(80 + r3);
    ST32((sp - 40), ((r0 & 0xFFFF) + 6));
    r3 = LD32(0x060D7B3C);
    r2 = LD16(40 + r3);
    ST32((sp - 44), (r2 & 0xFFFF));
    r7 = LD32(0x060D7B3C);
    r6 = LD32(0x060D7B3C);
    r7 = LD16(46 + r7);
    r6 = LD16(44 + r6);
    SETR(8, r8);
    SETR(13, 0x060D7768);
    SETSP((sp - 44));
    SETPR(0x0607DF04);
    r0 = GCALL4(0x0606CAE4, 0, 20, (r6 & 0xFFFF), (r7 & 0xFFFF));
    ST16(r8, r0);
    r0 = r0 & 0xFFFF;
    if ((r0 & r0) == 0) {
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD32(r13);
        r2 = LD16(66 + r14);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        SETSP((sp - 20));
        r0 = GCALL2(0x0606AAC8, r14, 3);
        ST16(74 + r14, 0);
        ST16(72 + r14, 0);
        SETSP((sp - 20));
        r0 = GCALL1(0x0606AB24, r14);
        SETMACL(LD32((sp - 20)));
        r5 = LD8(0x060C1910);
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x0606950C, r14, (r5 & 255));
        return r0;
    }
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

int f0607E0BC(int r4)
{
    int r0, r1;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 12, r4);
    SETSP((sp - 12));
    SETPR(0x0607E0CE);
    r0 = GCALL3(0x0606AE6C, 98, 0x190, 64);
    ST16(0x060C288A, r0);
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r1 = LD32(sp - 12);
        r0 = (r0 & 0xFFFF) * 124;
        ST16((0x060D5F72 + r0), r1);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
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

int f0607E132(void)
{
    int r0, r1, r2, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 28));
    r0 = COPYW(0x0609445C, (sp - 28), 0x060B2BAC, 12);
    SETSP((sp - 28));
    SETPR(0x0607E14C);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r14 = 0x060D7768;
        r0 = 66;
        r13 = LD32(0x060D7768);
        r3 = LD16(66 + r13);
        if (!((r3 & r3) == 0)) {
            r5 = LD16(66 + r13);
            r5 = LD32((((r5 & 0xFFFF) << 2) + (sp - 28)));
            r2 = LD16(80 + r13);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 28));
            SETPR(0x0607E18E);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (r5 + (r2 & 0xFFFF)));
            r2 = LD32(r14);
            r0 = LD16(r2 + 24);
            if ((r0 & 0xFFFF) > 0x220) {
                SETSP((sp - 28));
                r0 = GCALL1(0x060144F4, 0x0606D23C);
            } else {
                SETSP((sp - 28));
                r0 = GCALL0(0x0607B44C);
                r5 = 1;
                r0 = LD32(r14);
                r4 = LD16(0x060C2860);
                r0 = LD16(r0 + 66);
                r0 = r0 & 0xFFFF;
                r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
                if (!(r0 == 0)) {
                    if (r0 == 1) {
                        r1 = LD32(r14);
                        r0 = LD16(r1 + 24);
                        r3 = r0 & 0xFFFF;
                        r0 = LD16(r4 + 24);
                        if (!((r3 - (r0 & 0xFFFF)) > 112)) {
                            ST16(0x060C288C, r5);
                        }
                    } else {
                        if (r0 == 2) {
                            r0 = LD32(r14);
                            r0 = LD16(r0 + 24);
                            r3 = r0 & 0xFFFF;
                            r0 = LD16(r4 + 24);
                            if (!((r3 - (r0 & 0xFFFF)) > 24)) {
                                ST16(0x060C2894, r5);
                            }
                        }
                    }
                }
            }
            SETSP((sp - 28));
            r0 = GCALL0(0x0606D410);
        } else {
            r1 = LD32(0x060C1914);
            if (r1 >= 0x00010000) {
                r5 = LD16(66 + r13);
                r5 = LD32((((r5 & 0xFFFF) << 2) + (sp - 28)));
                r2 = LD16(80 + r13);
                r4 = LD16(0x060C1AA8);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x0607E18E);
                r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (r5 + (r2 & 0xFFFF)));
                r2 = LD32(r14);
                r0 = LD16(r2 + 24);
                if ((r0 & 0xFFFF) > 0x220) {
                    SETSP((sp - 28));
                    r0 = GCALL1(0x060144F4, 0x0606D23C);
                } else {
                    SETSP((sp - 28));
                    r0 = GCALL0(0x0607B44C);
                    r5 = 1;
                    r0 = LD32(r14);
                    r4 = LD16(0x060C2860);
                    r0 = LD16(r0 + 66);
                    r0 = r0 & 0xFFFF;
                    r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
                    if (!(r0 == 0)) {
                        if (r0 == 1) {
                            r1 = LD32(r14);
                            r0 = LD16(r1 + 24);
                            r3 = r0 & 0xFFFF;
                            r0 = LD16(r4 + 24);
                            if (!((r3 - (r0 & 0xFFFF)) > 112)) {
                                ST16(0x060C288C, r5);
                            }
                        } else {
                            if (r0 == 2) {
                                r0 = LD32(r14);
                                r0 = LD16(r0 + 24);
                                r3 = r0 & 0xFFFF;
                                r0 = LD16(r4 + 24);
                                if (!((r3 - (r0 & 0xFFFF)) > 24)) {
                                    ST16(0x060C2894, r5);
                                }
                            }
                        }
                    }
                }
                SETSP((sp - 28));
                r0 = GCALL0(0x0606D410);
            }
        }
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0607E28C(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f0607E334(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607E33E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 8));
        r0 = GCALL2(0x0606AAC8, r4, 3);
        r2 = LD32(0x060D7B3C);
        ST16(70 + r2, 0x100);
        ST16(68 + r2, 0x100);
        r5 = LD32(0x060D7768);
        r4 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r0 = LD16(r4 + 22);
        SETSP((sp - 8));
        SETPR(0x0607E370);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), ((r5 & 0xFFFF) + 11));
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0607E408);
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f0607E44C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607E454);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = 0x060D7B3C;
        r4 = LD32(0x060D7B3C);
        r3 = LD16(68 + r4);
        if (!((r3 & 0xFFFF) >= 0x100)) {
            r1 = LD16(68 + r4);
            ST16(68 + r4, (r1 + 1));
            r3 = LD32(r5);
            r1 = LD16(70 + r3);
            ST16(70 + r3, (r1 + 1));
        }
        r0 = LD32(0x26006034);
        if ((r0 & 3) == 0) {
            r6 = 0x060C28A4;
            r1 = LD16(0x060C28A4);
            r4 = LD32(0x060D7768);
            if (!((r1 & r1) == 0)) {
                r0 = LD32(r5);
                r0 = LD16(r0 + 38);
                if (r0 == -8) {
                    r0 = LD16(r4 + 28);
                    if ((r0 & 0xFFFF) == 48) {
                        SETSP((sp - 4));
                        r0 = GCALL1(0x060144F4, 0x0607E50C);
                    } else {
                        r0 = LD16(r4 + 28);
                        r0 = r0 + 1;
                        ST16(r4 + 28, r0);
                    }
                } else {
                    r0 = LD32(r5);
                    r2 = LD16(r0 + 38);
                    ST16(r0 + 38, (r2 - 1));
                }
            } else {
                r0 = LD16(r4 + 28);
                if (!((r0 & 0xFFFF) > 16)) {
                    ST16(r6, 1);
                } else {
                    r0 = LD16(r4 + 28);
                    r0 = r0 - 1;
                    ST16(r4 + 28, r0);
                }
            }
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
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

int f0607E570(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607E578);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD32(0x060D7768);
        r0 = LD16(60 + r2);
        if ((r0 & r0) == 0) {
            r4 = 0x0607E680;
        } else {
            r4 = 0x0607E5A2;
        }
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, r4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607E5A2(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607E5AC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060D7E68);
        if (((r0 & 0xFFFF) & 4) == 0) {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606E81C);
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 24);
            r5 = LD16((64 + r4));
            r3 = LD32(0x060D7768);
            r5 = ((((r5 & 0xFFFF) << 1) + (r5 & 0xFFFF)) << 2) + 0x060C1F42;
            r4 = LD16(r5);
            r4 = r4 + (r0 & 0xFFFF);
            r0 = LD16(r3 + 28);
            r3 = r0 & 0xFFFF;
            r0 = LD16(r5 + 2);
            SETSP((sp - 8));
            r0 = GCALL2(0x06074AFA, ((r4 + 8) & 0xFFF0), (((r3 + r0) + 8) & 0xFFF0));
            r3 = LD32(0x060D7768);
            ST16(58 + r3, 30);
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0606E864);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x06074CB4);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607E70E(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607E716);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607E752);
        r2 = LD16(0x060C289E);
        if (!((r2 & r2) == 0)) {
            SETSP((sp - 4));
            r0 = GCALL0(0x0607EA10);
            if (!((r0 & r0) == 0)) {
                SETSP((sp - 4));
                r0 = GCALL1(0x06014516, 0x0607EA90);
            }
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0607E7CC);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607E7CC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607E7EE);
    r4 = LD16(0x060C1AA8);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 2));
    return r0;
}

int f0607E7EE(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607E7F6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7B3C);
        r2 = LD16(38 + r4);
        if (!((r2 & r2) == 0)) {
            r0 = LD32(0x26006034);
            if ((r0 & 3) == 0) {
                r2 = LD16(38 + r4);
                ST16(38 + r4, (r2 + 1));
            }
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607E850);
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0607E824);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            SETSP((sp - 4));
            SETPR(0x0607E830);
            r0 = GCALL0(0x0607F058);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607E850(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607E858);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607E88E);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0607E87A);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 8));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607E88E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607E898);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r1 = LD16(42 + r3);
        ST16(42 + r3, (r1 & 0xFF7F));
        r3 = LD32(0x060D7768);
        r1 = LD16(62 + r3);
        if (!((r1 & r1) == 0)) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0607E8C8);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
            r3 = LD16(0x060C289E);
            if (!((r3 & 0xFFFF) >= 5)) {
                SETR(14, r14);
                SETSP((sp - 8));
                SETPR(0x0607E8FE);
                r0 = GCALL0(0x0607F318);
                SETR(14, r14);
                SETSP((sp - 8));
                SETPR(0x0607E902);
                r0 = GCALL0(0x0607F0D2);
                r2 = LD32(r14);
                ST16(62 + r2, 10);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                SETSP((sp - 8));
                r0 = GCALL1(0x060144F4, 0x0607E95C);
                r5 = LD32(r14);
                r5 = LD16(80 + r5);
                r4 = LD16(0x060C1AA8);
                SETSP((sp - 8));
                SETPR(0x0607E8F0);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP1(0x06014516, 0x0606D88C);
                return r0;
            }
        }
    }
}

int f0607E95C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 128));
    SETSP((sp - 4));
    r0 = GCALL1(0x0606947C, 0x1E6);
    SETSP((sp - 4));
    SETPR(0x0607E97C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0607E9BA);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0607E99E);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 182);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607E9BA(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607E9C2);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0607E9DC);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 6));
        r4 = LD32(0x060D7B3C);
        r0 = LD16(38 + r4);
        if (!(r0 == -8)) {
            r0 = LD32(0x26006034);
            if ((r0 & 7) == 0) {
                r3 = LD16(38 + r4);
                ST16(38 + r4, (r3 - 1));
            }
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607EA90);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607EA10(void)
{
    if (!GCALL0(0x0606BF22))
        return 0;
    GCALL0(0x0606E81C);
    return GCALL0(0x0606BE44) == 0;
}

int f0607EA90(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607EA98);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD16(0x060C289A);
        if ((r3 & r3) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x0600996A, 161);
            r2 = LD32(0x060D7768);
            ST16(62 + r2, 100);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607EAE8);
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0607EAD4);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 13));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607EB66(void)
{
    int r0, r2, r3, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 8));
    SETPR(0x0607EB7E);
    r0 = GCALL3(0x0606AE6C, 75, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD16(0x060C2898);
        ST16(0x060D5F64 + (r4 * 124), r2);
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 8));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), -1);
        r3 = LD16(0x060C289A);
        ST16(0x060C289A, (r3 + 1));
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0607EBB4(void)
{
    GCALL1(0x060144F4, 0x0607EBD4);
    GCALL2(0x06074AFA, LDU16(LD32(CURRENT) + 24), 64);
    return GJUMP1(0x06014516, 0x06074CB4);
}

int f0607ECDE(void)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0602EE02);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607ED16);
    SETSP((sp - 4));
    SETPR(0x0607ECF4);
    r0 = GCALL0(0x0606D2E8);
    r2 = LD32(0x060D7768);
    ST16(62 + r2, 240);
    ST32((sp - 8), 63);
    SETSP((sp - 8));
    SETPR(0x0607ED0E);
    r0 = GCALL4(0x06080864, 0x118, 32, 63, 56);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0607ED16(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0607ED20);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r2 = LD16(62 + r3);
        if ((r2 & r2) == 0) {
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0607ED36);
            r0 = GCALL0(0x060804E8);
            r4 = LD32(r14);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r0 = LD16(r4 + 22);
            SETSP((sp - 8));
            SETPR(0x0607ED4A);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), ((r5 & 0xFFFF) + 16));
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0607ED68);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606D37A);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607ED68(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607ED6E);
    r0 = GCALL0(0x0607F058);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r4 = LD32(0x060D7768);
    r0 = LD16(r4 + 22);
    SETSP((sp - 4));
    SETPR(0x0607ED84);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), ((r5 & 0xFFFF) + 19));
    ST16(0x060C28A4, 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607EDF0);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 160);
    return r0;
}

int f0607EDF0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0607EDFC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7B3C;
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 12));
        r0 = GCALL2(0x0606AAC8, r4, 7);
        r13 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 28);
        if ((r0 & 0xFFFF) > 56) {
            r0 = LD16(r4 + 28);
            ST16(r4 + 28, (r0 - 2));
        }
        r3 = LD32(r14);
        r0 = LD16(68 + r3);
        if (!((r0 & r0) == 0)) {
            r2 = LD32(0x060D7768);
            r0 = LD16(r2 + 28);
            if (!((r0 & 0xFFFF) >= 112)) {
                r1 = LD32(r14);
                r3 = LD16(68 + r1);
                ST16(68 + r1, (r3 - 4));
                r2 = LD32(r14);
                r3 = LD16(70 + r2);
                ST16(70 + r2, (r3 - 4));
            }
        }
        r2 = LD32(r14);
        r3 = LD8(78 + r2);
        ST8(78 + r2, (r3 + 6));
        r2 = LD32(r14);
        ST16(74 + r2, 0);
        ST16(82 + r2, 0);
        r3 = LD32(r14);
        r2 = LD16(68 + r3);
        if ((r2 & r2) == 0) {
            r4 = LD32(r14);
            SETSP((sp - 12));
            r0 = GCALL2(0x0606AAC8, r4, 0);
            r5 = LD32(r13);
            r4 = LD32(r13);
            r5 = LD16(80 + r5);
            r0 = LD16(r4 + 22);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x0607EE88);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), ((r5 & 0xFFFF) + 20));
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x0607EEF8);
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606D37A);
            ST16(0x060C28A4, 128);
            r1 = LD32(r14);
            ST16((70 + r1), 16);
            ST16((68 + r1), 16);
            r3 = LD32(r14);
            ST8(78 + r3, 0);
        }
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607EEF8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    SETPR(0x0607EF08);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        SETSP((sp - 20));
        r0 = GCALL0(0x06039FAC);
        r13 = 0x060D7768;
        r14 = 0x060D7B3C;
        r12 = LD32(0x060D7768);
        r2 = LD32(0x060D7B3C);
        r3 = LD16(50 + r2);
        r2 = LD16(80 + r12);
        if (!((r3 & 0xFFFF) == ((r2 & 0xFFFF) + 21))) {
            r5 = LD16(80 + r12);
            r0 = LD16(r12 + 22);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x0607EF40);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), ((r5 & 0xFFFF) + 21));
            r4 = LD32(r14);
            SETSP((sp - 20));
            r0 = GCALL2(0x0606AAC8, r4, 7);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x0607EF4E);
            r0 = GCALL0(0x060806B4);
        }
        r12 = 0x060C28A4;
        r8 = LD32(r14);
        r0 = LD16(0x060C28A4);
        SETSP((sp - 20));
        r0 = GCALL1(0x0606CEB0, (255 & (r0 & 0xFFFF)));
        SETSP((sp - 20));
        r0 = HELPER((int)r0 >> 12);
        SETSP((sp - 20));
        r0 = GCALL1(0x060949D0, r0);
        ST16((r8 + 38), (-r0));
        r3 = LD32(r14);
        r2 = LD16(68 + r3);
        if (!((r2 & 0xFFFF) >= 0x100)) {
            r1 = LD32(r14);
            r2 = LD16(68 + r1);
            ST16(68 + r1, (r2 + 4));
            r1 = LD32(r14);
            r2 = LD16(70 + r1);
            ST16(70 + r1, (r2 + 4));
        }
        r3 = LD32(r14);
        r2 = LD16(68 + r3);
        if ((r2 & 0xFFFF) > 192) {
            r1 = LD16(r12);
            if ((r1 & 0xFFFF) >= 0x140) {
                r1 = LD32(r14);
                r3 = LD8(78 + r1);
                if ((r3 & r3) == 0) {
                    SETSP((sp - 20));
                    r0 = GCALL0(0x06039FB4);
                } else {
                    r3 = LD32(r14);
                    r1 = LD8(78 + r3);
                    ST8(78 + r3, (r1 + 4));
                }
            } else {
                r1 = LD32(r13);
                r0 = LD16(r1 + 28);
                if ((r0 & 0xFFFF) > 94) {
                    r1 = LD32(r13);
                    r3 = LD16(42 + r1);
                    ST16(42 + r1, (r3 & 0xFF7F));
                    r1 = LD16(r12);
                    ST16(r12, (r1 + 4));
                }
                r3 = LD32(r13);
                r0 = LD16(r3 + 28);
                ST16(r3 + 28, (r0 + 1));
                r3 = LD32(r14);
                r2 = LD8(78 + r3);
                ST8(78 + r3, (r2 + 16));
            }
        }
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    } else {
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f0607F058(void)
{
    int r0, r1, r2, r4, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r13 = 0x060D7B3C;
    r4 = LD32(0x060D7B3C);
    r0 = LD16(r4 + 4);
    SETSP((sp - 16));
    r0 = GCALL1(0x060691DA, (r0 - 1));
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r2 = LD16(0x060C1AAA);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r2 = LD16(42 + r14);
        ST16(42 + r14, (r2 | 64));
        r1 = LD32(r13);
        r2 = LD16(44 + r1);
        ST16(44 + r14, r2);
        r1 = LD32(r13);
        r2 = LD16(46 + r1);
        ST16(46 + r14, r2);
        r1 = LD32(r13);
        r2 = LD16(40 + r1);
        ST16(40 + r14, r2);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AAA);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x0607F0BC);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 3));
        r0 = LD32(r13);
        r0 = LD16(r0 + 16);
        ST16(r14 + 16, r0);
        r0 = LD32(r13);
        r0 = LD16(r0 + 18);
        ST16(r14 + 18, r0);
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0607F0D2(void)
{
    int r0, r1, r2, r4, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r13 = 0x060D7B3C;
    r4 = LD32(0x060D7B3C);
    r0 = LD16(r4 + 4);
    SETSP((sp - 16));
    r0 = GCALL1(0x060691DA, (r0 + 1));
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r2 = LD16(0x060C1AAA);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r2 = LD16(42 + r14);
        ST16(42 + r14, (r2 | 64));
        r1 = LD32(r13);
        r2 = LD16(44 + r1);
        ST16(44 + r14, r2);
        r1 = LD32(r13);
        r2 = LD16(46 + r1);
        ST16(46 + r14, r2);
        r1 = LD32(r13);
        r2 = LD16(40 + r1);
        ST16(40 + r14, r2);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AAA);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x0607F136);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 26));
        r0 = LD32(r13);
        r0 = LD16(r0 + 16);
        ST16(r14 + 16, r0);
        r0 = LD32(r13);
        r0 = LD16(r0 + 18);
        ST16(r14 + 18, r0);
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0607F1EA(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    r13 = LD16(0x060C2898);
    r13 = ((r13 & 0xFFFF) * 124) + 0x060D5F30;
    r0 = LD16(r13 + 22);
    r14 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 20));
    SETPR(0x0607F216);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r12 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(r13 + 24);
        ST16(r3 + 24, (r0 + 8));
        r3 = LD32(0x060D7768);
        r2 = LD16(38 + r14);
        r0 = LD16(r13 + 28);
        r13 = 0x060D7B3C;
        ST16(r3 + 28, (r0 - (((r2 + 0) + (0 > r2)) >> 1)));
        r3 = LD32(0x060D7B3C);
        r0 = LD16(r14 + 10);
        ST16(r3 + 10, r0);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(42 + r14);
        ST16(42 + r3, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(68 + r14);
        ST16(68 + r3, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(70 + r14);
        ST16(70 + r3, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(72 + r14);
        ST16(72 + r3, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(74 + r14);
        ST16(74 + r3, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD8(78 + r14);
        ST8(78 + r3, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(80 + r14);
        ST16(80 + r3, r2);
        r3 = LD32(0x060D7B3C);
        r2 = LD16(82 + r14);
        ST16(82 + r3, r2);
        r3 = LD16(38 + r14);
        if (!(r3 > -3)) {
            r4 = 0x1E4;
        } else {
            r4 = 10;
        }
        SETSP((sp - 20));
        r0 = GCALL1(0x0606947C, r4);
        r2 = LD32(r12);
        r3 = LD16(50 + r14);
        r1 = LD16(80 + r2);
        if ((r3 & 0xFFFF) == ((r1 & 0xFFFF) + 20)) {
            r2 = LD32(r13);
            ST16(r2 + 10, 0);
        }
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607F318(void)
{
    int r0, r2, r3, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 12));
    r0 = GCALL1(0x0600996A, 167);
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 12));
    SETPR(0x0607F33A);
    r0 = GCALL3(0x0606AE6C, 74, r0, r6);
    ST32(sp - 12, r0);
    if (!((r0 & r0) == 0)) {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 12));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), 1);
        r2 = LD32(sp - 12);
        r5 = (r2 * 124) + 0x060D5F30;
        r3 = LD16(0x060C2898);
        ST16(52 + r5, r3);
        r3 = LD16(0x060C289E);
        r0 = 66;
        ST16(66 + r5, r3);
        r2 = LD16(0x060C289E);
        ST16(0x060C289E, (r2 + 1));
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0607F37E(void)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607F38A);
    r0 = GCALL3(0x0606B0DE, 0x060BB026, 182, 16);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C776);
    r3 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x0607F9EA);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0607F3BE);
    SETSP((sp - 4));
    SETPR(0x0607F3B0);
    r0 = GCALL1(0x0607FF5A, 1);
    SETPR(LD32((sp - 4)));
    r3 = LD32(0x060D7768);
    ST16(62 + r3, 0xFFFF);
    return 62;
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

int f0607F648(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r13 = (sp - 100) + 4;
    SETSP((sp - 100));
    r0 = COPYW(0x06094450, (sp - 96), 0x060B2BB8, 64);
    SETR(13, r13);
    SETSP((sp - 100));
    SETPR(0x0607F670);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r4 = LD32(0x060D7B3C);
        r3 = LD16(38 + r4);
        if (r3 > 0) {
            r10 = 0x060EC8B0;
            r14 = 0x060D7768;
            ST16(38 + r4, 0);
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 20);
            r3 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
            r0 = LD16(r4 + 18);
            if (!(((r3 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
                r0 = LD32(r14);
                r2 = LD16(r0 + 62);
                if (!((r2 & r2) == 0)) {
                    r12 = 0x060C28A0;
                    r11 = 0x060C28A2;
                    r0 = LD16(86 + r4);
                    ST16((86 + r4), ((r0 + 1) & 224));
                    r9 = LD32(r14);
                    r3 = LD32(r14);
                    r9 = LD16(86 + r9);
                    r0 = LD16(r3 + 24);
                    r9 = (int)((unsigned)((int)((unsigned)((int)((unsigned)(r9 & 0xFFFF) >> 2)) >> 2)) >> 1);
                    r4 = ((r9 << 2) << 1) + r13;
                    r2 = LD32(r4);
                    ST16(0x060C28A0, (r0 + r2));
                    r3 = LD32(r14);
                    r2 = LD32(r4 + 4);
                    r0 = LD16(r3 + 28);
                    ST16(0x060C28A2, (r0 + r2));
                    r5 = LD16(0x060C28A2);
                    r4 = LD16(0x060C28A0);
                    SETSP((sp - 100));
                    r0 = GCALL2(0x0607F5A8, (r4 & 0xFFFF), (r5 & 0xFFFF));
                    if ((r0 & r0) == 0) {
                        r5 = ((r9 << 2) << 1) + r13;
                        ST32(sp - 100, r5);
                        r5 = LD32(r5 + 4);
                        r3 = LD16(r11);
                        r4 = LD32(sp - 100);
                        r5 = r5 + r3;
                        r4 = LD32(r4);
                        r3 = LD16(r12);
                        SETSP((sp - 100));
                        r0 = GCALL2(0x0600CAE4, (r4 + r3), r5);
                        r2 = LD32(r14);
                        r3 = LD16((r0 << 1) + r10);
                        r0 = LD16(r2 + 18);
                        if (!(((r3 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
                            r3 = LD32(r14);
                            r5 = LD16(86 + r3);
                            r5 = r5 ^ 128;
                            ST16(86 + r3, r5);
                            r3 = LD32(r14);
                            r0 = LD16(r3 + 24);
                            r4 = ((((int)((unsigned)((int)((unsigned)((int)((unsigned)(r5 & 0xFFFF) >> 2)) >> 2)) >> 1)) << 2) << 1) + r13;
                            r1 = LD32(r4);
                            ST16(r12, (r0 + r1));
                            r3 = LD32(r14);
                            r1 = LD32(r4 + 4);
                            r0 = LD16(r3 + 28);
                            ST16(r11, (r0 + r1));
                        } else {
                            r2 = LD16(0x060C28A2);
                            if ((r2 & 0xFFFF) > 176) {
                                r3 = LD32(r14);
                                r5 = LD16(86 + r3);
                                r5 = r5 ^ 128;
                                ST16(86 + r3, r5);
                                r3 = LD32(r14);
                                r0 = LD16(r3 + 24);
                                r4 = ((((int)((unsigned)((int)((unsigned)((int)((unsigned)(r5 & 0xFFFF) >> 2)) >> 2)) >> 1)) << 2) << 1) + r13;
                                r1 = LD32(r4);
                                ST16(r12, (r0 + r1));
                                r3 = LD32(r14);
                                r1 = LD32(r4 + 4);
                                r0 = LD16(r3 + 28);
                                ST16(r11, (r0 + r1));
                            } else {
                                r0 = LD16(0x060C28A0);
                                if (!((r0 & 0xFFFF) >= 80)) {
                                    r3 = LD32(r14);
                                    r5 = LD16(86 + r3);
                                    r5 = r5 ^ 128;
                                    ST16(86 + r3, r5);
                                    r3 = LD32(r14);
                                    r0 = LD16(r3 + 24);
                                    r4 = ((((int)((unsigned)((int)((unsigned)((int)((unsigned)(r5 & 0xFFFF) >> 2)) >> 2)) >> 1)) << 2) << 1) + r13;
                                    r1 = LD32(r4);
                                    ST16(r12, (r0 + r1));
                                    r3 = LD32(r14);
                                    r1 = LD32(r4 + 4);
                                    r0 = LD16(r3 + 28);
                                    ST16(r11, (r0 + r1));
                                } else {
                                    r0 = LD16(0x060C28A0);
                                    if ((r0 & 0xFFFF) > 0x150) {
                                        r3 = LD32(r14);
                                        r5 = LD16(86 + r3);
                                        r5 = r5 ^ 128;
                                        ST16(86 + r3, r5);
                                        r3 = LD32(r14);
                                        r0 = LD16(r3 + 24);
                                        r4 = ((((int)((unsigned)((int)((unsigned)((int)((unsigned)(r5 & 0xFFFF) >> 2)) >> 2)) >> 1)) << 2) << 1) + r13;
                                        r1 = LD32(r4);
                                        ST16(r12, (r0 + r1));
                                        r3 = LD32(r14);
                                        r1 = LD32(r4 + 4);
                                        r0 = LD16(r3 + 28);
                                        ST16(r11, (r0 + r1));
                                    }
                                }
                            }
                        }
                    }
                    SETSP((sp - 100));
                    r0 = GCALL1(0x0607F50A, 32);
                    r4 = 0x06074CB4;
                    SETSP((sp - 100));
                    r0 = GCALL1(0x06014516, r4);
                } else {
                    r4 = LD32(0x060D7B3C);
                    SETSP((sp - 100));
                    r0 = GCALL2(0x0606AAC8, r4, 0);
                    SETSP((sp - 100));
                    r0 = GCALL0(0x0606C7AA);
                    r0 = LD32(r14);
                    r0 = LD16(r0 + 20);
                    r0 = LD16(((r0 & 0xFFFF) << 1) + r10);
                    if (((r0 & 0xFFFF) & 143) == 0) {
                        r4 = LD32(r14);
                        r0 = LD16(r4 + 20);
                        SETSP((sp - 100));
                        r0 = GCALL2(0x0606C82C, (r0 & 0xFFFF), 136);
                    }
                    r2 = LD16(0x060C062C);
                    ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x0606B1EC);
                    SETSP((sp - 100));
                    r0 = GCALL1(0x060144F4, 0x0607F8F4);
                    r8 = LD32(r14);
                    SETSP((sp - 100));
                    r0 = GCALL0(0x0600A0B8);
                    ST16((r8 + 60), ((r0 & 127) + 150));
                }
            } else {
                r4 = LD32(0x060D7B3C);
                SETSP((sp - 100));
                r0 = GCALL2(0x0606AAC8, r4, 0);
                SETSP((sp - 100));
                r0 = GCALL0(0x0606C7AA);
                r0 = LD32(r14);
                r0 = LD16(r0 + 20);
                r0 = LD16(((r0 & 0xFFFF) << 1) + r10);
                if (((r0 & 0xFFFF) & 143) == 0) {
                    r4 = LD32(r14);
                    r0 = LD16(r4 + 20);
                    SETSP((sp - 100));
                    r0 = GCALL2(0x0606C82C, (r0 & 0xFFFF), 136);
                }
                r2 = LD16(0x060C062C);
                ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x0606B1EC);
                SETSP((sp - 100));
                r0 = GCALL1(0x060144F4, 0x0607F8F4);
                r8 = LD32(r14);
                SETSP((sp - 100));
                r0 = GCALL0(0x0600A0B8);
                ST16((r8 + 60), ((r0 & 127) + 150));
            }
        }
        SETSP((sp - 100));
        r0 = GCALL0(0x0606D410);
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

int f0607F8F4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0607F8FC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r1 = LD16(60 + r3);
        if ((r1 & r1) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x0600996A, 166);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0607F946);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0607F932);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 28));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0607F946(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r14 = 0x060D7768;
    r2 = LD32(0x060D7768);
    r0 = LD16(66 + r2);
    if ((r0 & r0) == 0) {
        r3 = 77;
    } else {
        r3 = 76;
    }
    ST32(sp - 16, r3);
    r6 = LD32(r14);
    r0 = LD16(r6 + 28);
    r5 = LD32(r14);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETR(14, r14);
    SETSP((sp - 16));
    SETPR(0x0607F974);
    r0 = GCALL3(0x0606AE6C, r3, r0, r6);
    r4 = r0;
    if ((r4 & r4) == 0) {
        r2 = LD16(0x060C289E);
        ST16(0x060C289E, (r2 - 1));
    } else {
        r2 = LD16(0x060C2898);
        ST16(0x060D5F64 + (r4 * 124), r2);
    }
    r3 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x0606B1EC);
    r3 = LD32(r14);
    r0 = LD16(r3 + 20);
    r3 = (r0 & 0xFFFF) << 1;
    r0 = LD16(0x060EC8B0 + r3);
    ST16((0x060EC8B0 + r3), (r0 & 0xFF77));
    SETSP((sp - 16));
    r0 = GCALL1(0x060144F4, 0x0607F9E4);
    r5 = LD32(r14);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 16));
    SETPR(0x0607F9D6);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 29));
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D88C);
    return r0;
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

int f0607FAD4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0607FAE0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = 0x060D7B3C;
        r3 = LD32(0x060D7B3C);
        r0 = LD16(r3 + 18);
        if (!(r0 >= 0x100)) {
            r2 = LD32(0x060D7768);
            r0 = LD16(r2 + 28);
            ST16(r2 + 28, (r0 + 2));
            r3 = LD32(0x060D7768);
            r2 = LD16(66 + r3);
            ST16(66 + r3, (r2 + 2));
            r3 = LD32(r4);
            r1 = LD32(0x060D7768);
            r0 = LD16(66 + r1);
            r0 = (r0 << 1) + 128;
            ST16((70 + r3), r0);
            ST16((68 + r3), r0);
            r8 = LD32(0x060D7768);
            SETSP((sp - 12));
            r0 = GCALL0(0x0600CA84);
            ST16((r8 + 20), r0);
            SETSP((sp - 12));
            SETPR(0x0607FB3C);
            r0 = GCALL0(0x0606C8C0);
            SETPR(LD32((sp - 12)));
            SETR(8, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            SETSP((sp - 12));
            SETPR(0x0607FAF6);
            r0 = GCALL0(0x0606D398);
            r3 = LD16(0x060C289A);
            ST16(0x060C289A, (r3 - 1));
            SETPR(LD32((sp - 12)));
            SETR(8, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        }
    }
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

int f0607FE0E(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    r3 = LD16(0x060C289E);
    ST16(0x060C289E, (r3 - 1));
    UNFRAME(sp);
    r0 = GJUMP0(0x0606D398);
    return r0;
}

int f0607FE68(void)
{
    int r0, r1, r2, r4, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r13 = 0x060D7B3C;
    r4 = LD32(0x060D7B3C);
    r0 = LD16(r4 + 18);
    SETSP((sp - 16));
    r0 = GCALL1(0x060691DA, r0);
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r2 = LD16(0x060C1AAA);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r2 = LD16(42 + r14);
        ST16(42 + r14, (r2 | 64));
        r1 = LD32(r13);
        r2 = LD16(44 + r1);
        ST16(44 + r14, r2);
        r1 = LD32(r13);
        r2 = LD16(46 + r1);
        ST16(46 + r14, r2);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AAA);
        r5 = LD16(80 + r5);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x0607FEC2);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 35));
        r0 = LD32(r13);
        r0 = LD16(r0 + 16);
        ST16(r14 + 16, r0);
        r0 = LD32(r13);
        r0 = LD16(r0 + 18);
        ST16(r14 + 18, r0);
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
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

int f0607FF5A(int r4)
{
    int r0, r1, r2, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 12, r4);
    r6 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r5 = LD32(0x060D7768);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 12));
    SETPR(0x0607FF76);
    r0 = GCALL3(0x0606AE6C, 79, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD32(sp - 12);
        r5 = (r4 * 124) + 0x060D5F30;
        ST16(66 + r5, r2);
        r1 = LD16(0x060C062C);
        ST16(52 + r5, r1);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r4;
}
